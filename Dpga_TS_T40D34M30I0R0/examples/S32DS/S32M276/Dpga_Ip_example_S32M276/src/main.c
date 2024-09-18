/*
*   Copyright 2023 NXP
*
*   NXP Confidential. This software is owned or controlled by NXP and may only be used strictly
*   in accordance with the applicable license terms.  By expressly accepting
*   such terms or by downloading, installing, activating and/or otherwise using
*   the software, you are agreeing that you have read, and that you agree to
*   comply with and are bound by, such license terms.  If you do not agree to
*   be bound by the applicable license terms, then you may not retain,
*   install, activate or otherwise use the software.
*
*   This file contains sample code only. It is not part of the production code deliverables.
*/

#ifdef __cplusplus
extern "C" {
#endif

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Aec_Ip.h"
#include "Lpspi_Ip.h"
#include "Dpga_Ip.h"
#include "Clock_Ip.h"
#include "Power_Ip.h"
#include "Siul2_Port_Ip.h"
#include "OsIf.h"
#include "S32M27x_LPSPI.h"
#include "S32M27x_SIUL2.h"
#include "S32M27x_AEC_AE.h"
#include "S32M27x_DPGA_AE.h"
#include "check_example.h"


/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/
#define T_REG_WIDTH_1B                    ((uint8)8U)
#define T_REG_WIDTH_2B                    ((uint8)16U)
#define T_REG_WIDTH_4B                    ((uint8)32U)

#define T_AEC_IO_FUNCMUX_CFG_REG_ADDR     ((uint8)0x48U)

/*==================================================================================================
*                                      EXTERN DECLARATIONS
==================================================================================================*/


/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
*                                      LOCAL VARIABLES
==================================================================================================*/
/* Table of base addresses for DPGA instances */
static DPGA_AE_Type * const BaseArr[DPGA_AE_INSTANCE_COUNT] = IP_DPGA_AE_BASE_PTRS;

/*==================================================================================================
*                                      GLOBAL VARIABLES
==================================================================================================*/
volatile boolean T_AmpError = FALSE;
volatile boolean T_BTError  = FALSE;
volatile uint32 VarNotification_0 = 0;



/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/
void Dpga_Callback(Dpga_Ip_EventType Event);
void Dpga_Callback(Dpga_Ip_EventType Event)
{
    switch(Event)
    {
        case DPGA_IP_AMP_PARITY_CHECK_EVENT:
        {
            T_AmpError = TRUE;
            break;
        }
        case DPGA_IP_BT_PARITY_CHECK_EVENT:
        {
            T_BTError = TRUE;
            break;
        }
        default:
        {
            /* Do nothing */
            break;
        }
    }
}

void Notification_0(void)
{
    VarNotification_0++;
}


int main(void)
{
    volatile Std_ReturnType ReturnValue = (Std_ReturnType)E_NOT_OK;
    boolean bPass = TRUE;
    uint32 CtrlReg;
    uint32 AmpCfgReg;
    uint32 BTReg;
    DPGA_AE_Type * T_Base;
    T_Base = BaseArr[0U];
    OsIf_Init(NULL_PTR);

    /* Initialize Mcu Driver */
    Clock_Ip_Init(&Clock_Ip_aClockConfig[0U]);

     /* Initialize pins for LPSPI */
    Siul2_Port_Ip_Init(NUM_OF_CONFIGURED_PINS0, g_pin_mux_InitConfigArr0);
    /* Configure LPSI in sync mode */
    Lpspi_Ip_Init(&Lpspi_Ip_PhyUnitConfig_SpiPhyUnit_1_Instance_1);
    /* Initialize Ae */
    Aec_Ip_Init(&Aec_Ip_aConfigPB);
    /* Active Dpga module in AE controller. */
    Power_Ip_AecResetConfig(&Power_Ip_HwIPsConfigPB);
    /* Initialize DPGA */
    ReturnValue = Dpga_Ip_Init(0U,&Dpga_Ip_Config);


    /* Set analog mode, DPGA is connected to AMPOUT through an anamux.
       TODO: this should be done in Port module */
    ReturnValue |= Aec_Ip_SpiWrite(T_AEC_IO_FUNCMUX_CFG_REG_ADDR, T_REG_WIDTH_4B, (uint32)1U);
    /* Check that Dpga is enabled and in functional mode */
    ReturnValue |= Aec_Ip_SpiRead((uint32)(&(T_Base->CTRL)), T_REG_WIDTH_1B, &CtrlReg);
    if(0x9U != CtrlReg)
    {
        bPass=FALSE;
    }

    /* Check that the Amplifier's parameters are as configured*/
    ReturnValue |= Aec_Ip_SpiRead((uint32)(&(T_Base->AMPCFG)), T_REG_WIDTH_4B, &AmpCfgReg);
    if(0U != AmpCfgReg)
    {
        bPass=FALSE;
    }
    /* Check that Blanking Time feature is not triggered by any of the triggers*/
    ReturnValue |= Aec_Ip_SpiRead((uint32)(&(T_Base->BTCFG)), T_REG_WIDTH_4B, &BTReg);
    if(0U != BTReg)
    {
        bPass=FALSE;
    }
    /*measure the output by multimeter*/
    /* Reset IO_FUNCMUX_CFG register value */
    ReturnValue |= Aec_Ip_SpiWrite(T_AEC_IO_FUNCMUX_CFG_REG_ADDR, T_REG_WIDTH_4B, (uint32)0U);

    ReturnValue = Dpga_Ip_DeInit(0U);

    Exit_Example(bPass);
    return 0;
}

#ifdef __cplusplus
}
#endif
/** @} */
