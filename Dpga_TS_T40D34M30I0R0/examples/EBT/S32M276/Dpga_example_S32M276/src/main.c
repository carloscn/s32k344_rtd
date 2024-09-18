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
#include "Ae.h"
#include "Spi.h"
#include "CDD_Dpga.h"
#include "Mcu.h"
#include "Port.h"
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

boolean CheckResult(uint32 Result, uint32 Reference, uint32 Tolerance)
{
    boolean Status = FALSE;
    if(Result > Reference)
    {
        if((Result - Reference) < Tolerance)
        {
            Status = TRUE;
        }
    }
    else
    {
        if((Reference - Result) < Tolerance)
        {
            Status = TRUE;
        }
    }

    return Status;
}

void Notification_0(void)
{
    VarNotification_0++;
}

DPGA_AE_Type * T_Base = BaseArr[0U];

int main(void)
{

    volatile Std_ReturnType ReturnValue = (Std_ReturnType)E_NOT_OK;
    boolean bPass = TRUE;
    uint32 CtrlReg;
    uint32 AmpCfgReg;
    uint32 BTReg;


    OsIf_Init(NULL_PTR);

    /* Initialize Mcu Driver */
#if (MCU_PRECOMPILE_SUPPORT == STD_ON)
    Mcu_Init(NULL_PTR);
#else
    Mcu_Init(&Mcu_Config_VS_0);
#endif /* MCU_PRECOMPILE_SUPPORT == STD_ON */
    Mcu_InitClock(McuClockSettingConfig_0);
#if (MCU_NO_PLL == STD_OFF)
    /* Busy wait until the System PLL is locked */
    while(MCU_PLL_LOCKED != Mcu_GetPllStatus());
    Mcu_DistributePllClock();
#endif /* MCU_NO_PLL == STD_OFF */
    Mcu_SetMode(McuModeSettingConf_0);

     /* Initialize pins for LPSPI */
    Port_Init(NULL_PTR);
    /* Configure LPSI in sync mode */
    Spi_Init(NULL_PTR);
    /* Initialize Ae */
    Ae_Init(NULL_PTR);
    /* Active Dpga module in AE controller. */
    Mcu_AecResetConfig();

    /* Initialize DPGA */
#if (STD_ON == DPGA_PRECOMPILE_SUPPORT)
    ReturnValue = Dpga_Init(NULL_PTR);
#else
    ReturnValue = Dpga_Init(&Dpga_Config_VS_0);
#endif

    /* Set analog mode, DPGA is connected to AMPOUT through an anamux.
       TODO: this should be done in Port module */
    ReturnValue |= Ae_WriteRegister(T_AEC_IO_FUNCMUX_CFG_REG_ADDR, T_REG_WIDTH_4B, (uint32)1U);
    /* Check that Dpga is enabled and in functional mode */
    ReturnValue |= Ae_ReadRegister((uint32)(&(T_Base->CTRL)), T_REG_WIDTH_1B, &CtrlReg);
    if(0x9U != CtrlReg)
    {
        bPass=FALSE;
    }

    /* Check that the Amplifier's parameters are as configured*/
    ReturnValue |= Ae_ReadRegister((uint32)(&(T_Base->AMPCFG)), T_REG_WIDTH_4B, &AmpCfgReg);
    if(0U != AmpCfgReg)
    {
        bPass=FALSE;
    }
    /* Check that Blanking Time feature is not triggered by any of the triggers*/
    ReturnValue |= Ae_ReadRegister((uint32)(&(T_Base->BTCFG)), T_REG_WIDTH_4B, &BTReg);
    if(0U != BTReg)
    {
        bPass=FALSE;
    }

    /* Reset IO_FUNCMUX_CFG register value */
    ReturnValue |= Ae_WriteRegister(T_AEC_IO_FUNCMUX_CFG_REG_ADDR, T_REG_WIDTH_4B, (uint32)0U);

    ReturnValue = Dpga_DeInit();

    Exit_Example(bPass);
    return 0;
}

#ifdef __cplusplus
}
#endif
/** @} */
