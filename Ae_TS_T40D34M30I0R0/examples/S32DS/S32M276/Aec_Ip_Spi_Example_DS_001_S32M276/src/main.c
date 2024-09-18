/*
*   (c) Copyright 2022 NXP
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
#include "Clock_Ip.h"
#include "Aec_Ip.h"
#include "OsIf.h"
#include "Lpspi_Ip.h"
#include "Siul2_Port_Ip.h"
#include "S32M27x_HVI_AE.h"
#include "check_example.h"

/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/


/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/
#define AEC_IO_FUNCMUX_ADDR                 (0x48U)
#define AEC_CANPHY_ADDR                     (0x70U)
#define AEC_RSTGEN_CFG_ADDR                 (0x44U)

#define HVI_INSTANCE                        (1U)
#define HVI_DIV_SELECT                      (2U)

#define CANPHY_VALID_MASK                   (0x8003U)
#define IO_FUNCMUX_CFG_VALID                (0x0F1F0FU)

#define RSTGEN_HIVAE_ACTIVE                 (0x0020U)

#define NUMOF_PINS_USED                     (4U)

#define AEC_DATAWIDTH_8                     (8U)
#define AEC_DATAWIDTH_16                    (16U)
#define AEC_DATAWIDTH_32                    (32U)
/*==================================================================================================
*                                      LOCAL CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                      LOCAL VARIABLES
==================================================================================================*/


/*==================================================================================================
*                                      GLOBAL CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                      GLOBAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/

/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/
/**
* @brief        Read/Write to register of AE block through SPI interface.
* @details
*/
int main(void)
{
    boolean bPass = TRUE;
    uint32 RegVal;
    Aec_Ip_StatusType Status = AEC_STATUS_SUCCESS;

    OsIf_Init(NULL_PTR);

    Clock_Ip_Init(&Clock_Ip_aClockConfig[0U]);

    /* Initialize pins for LPSPI */
    Siul2_Port_Ip_Init(NUMOF_PINS_USED, g_pin_mux_InitConfigArr0);

    Lpspi_Ip_Init(&Lpspi_Ip_PhyUnitConfig_SpiPhyUnit_1_Instance_1);


    Aec_Ip_Init(&Aec_Ip_aConfigPB);

    /* Verify read/write for register 32 bits */
    Status = Aec_Ip_SpiWrite(AEC_IO_FUNCMUX_ADDR, AEC_DATAWIDTH_32, 0xFFFFFFFFU);
    Status |= Aec_Ip_SpiRead(AEC_IO_FUNCMUX_ADDR, AEC_DATAWIDTH_32, &RegVal);
    if ((RegVal != IO_FUNCMUX_CFG_VALID) || (AEC_STATUS_SUCCESS != Status))
    {
        bPass = FALSE;
    }

    /* Verify read/write for register 16 bits */
    Status = Aec_Ip_SpiWrite(AEC_CANPHY_ADDR, AEC_DATAWIDTH_16, 0xFFFFU);
    Status |= Aec_Ip_SpiRead(AEC_CANPHY_ADDR, AEC_DATAWIDTH_16, &RegVal);
    if ((RegVal != CANPHY_VALID_MASK) || (AEC_STATUS_SUCCESS != Status))
    {
        bPass = FALSE;
    }

    /* Verify read/write for register 8 bits */
    /* Enable HVI IP */
    Status = Aec_Ip_SpiWrite(AEC_RSTGEN_CFG_ADDR, AEC_DATAWIDTH_16, RSTGEN_HIVAE_ACTIVE);

    /* Turn off HVI channel and enable configuration mode */
    Status |= Aec_Ip_SpiWrite((uint32)&IP_HVI_AE->UCTRL_ARRAY[HVI_INSTANCE].UCTRL, AEC_DATAWIDTH_8, HVI_AE_UCTRL_CFGEN_MASK);

    /* Configure divider and pull down enable for HVI instance 1 */
    RegVal = HVI_AE_UCFG_DIVSEL(HVI_DIV_SELECT) | HVI_AE_UCFG_PDEN_MASK;
    Status = Aec_Ip_SpiWrite((uint32)&IP_HVI_AE->UCTRL_ARRAY[HVI_INSTANCE].UCFG, AEC_DATAWIDTH_16, RegVal);
    Status |= Aec_Ip_SpiRead((uint32)&IP_HVI_AE->UCTRL_ARRAY[HVI_INSTANCE].UCFG, AEC_DATAWIDTH_16, &RegVal);
    RegVal &= (HVI_AE_UCFG_DIVSEL_MASK | HVI_AE_UCFG_PDEN_MASK);
    if ((RegVal != (HVI_AE_UCFG_DIVSEL(HVI_DIV_SELECT) | HVI_AE_UCFG_PDEN_MASK)) || (AEC_STATUS_SUCCESS != Status))
    {
        bPass = FALSE;
    }
    
    Exit_Example(bPass);
    
    return 0;
}

/** @} */
