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
#include "Mcu.h"
#include "Ae.h"
#include "OsIf.h"
#include "Spi.h"
#include "Port.h"
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
    Std_ReturnType ReturnStatus = (Std_ReturnType)E_NOT_OK;

    OsIf_Init(NULL_PTR);

    Mcu_Init(NULL_PTR);

    Mcu_InitClock(McuClockSettingConfig_0);

#if (MCU_NO_PLL == STD_OFF)
    while ( MCU_PLL_LOCKED != Mcu_GetPllStatus() )
    {
        /* Busy wait until the System PLL is locked */
    }

    Mcu_DistributePllClock();
#endif

    Mcu_SetMode(McuModeSettingConf_0);
    
    /* Initialize pins for LPSPI */
    Port_Init(NULL_PTR);
    
    /* Configure LPSI in sync mode */
    Spi_Init(NULL_PTR);

    Ae_Init(NULL_PTR);
    
    /* Verify read/write for register 32 bits */
    ReturnStatus = Ae_WriteRegister(AEC_IO_FUNCMUX_ADDR, AEC_DATAWIDTH_32, 0xFFFFFFFFU);
    ReturnStatus |= Ae_ReadRegister(AEC_IO_FUNCMUX_ADDR, AEC_DATAWIDTH_32, &RegVal);
    if ((RegVal != IO_FUNCMUX_CFG_VALID) || ((Std_ReturnType)E_NOT_OK == ReturnStatus))
    {
        bPass = FALSE;
    }
    
    /* Verify read/write for register 16 bits */
    ReturnStatus = Ae_WriteRegister(AEC_CANPHY_ADDR, AEC_DATAWIDTH_16, 0xFFFFU);
    ReturnStatus |= Ae_ReadRegister(AEC_CANPHY_ADDR, AEC_DATAWIDTH_16, &RegVal);
    if ((RegVal != CANPHY_VALID_MASK) || ((Std_ReturnType)E_NOT_OK == ReturnStatus))
    {
        bPass = FALSE;
    }
    
    /* Verify read/write for register 8 bits */
    /* Enable HVI IP */
    ReturnStatus = Ae_WriteRegister(AEC_RSTGEN_CFG_ADDR, AEC_DATAWIDTH_16, RSTGEN_HIVAE_ACTIVE);
    
    /* Turn off HVI channel and enable configuration mode */
    ReturnStatus |= Ae_WriteRegister((uint32)&IP_HVI_AE->UCTRL_ARRAY[HVI_INSTANCE].UCTRL, AEC_DATAWIDTH_8, HVI_AE_UCTRL_CFGEN_MASK);

    /* Configure divider and pull down enable for HVI instance 1 */
    RegVal = HVI_AE_UCFG_DIVSEL(HVI_DIV_SELECT) | HVI_AE_UCFG_PDEN_MASK;
    ReturnStatus |= Ae_WriteRegister((uint32)&IP_HVI_AE->UCTRL_ARRAY[HVI_INSTANCE].UCFG, AEC_DATAWIDTH_16, RegVal);
    ReturnStatus |= Ae_ReadRegister((uint32)&IP_HVI_AE->UCTRL_ARRAY[HVI_INSTANCE].UCFG, AEC_DATAWIDTH_16, &RegVal);
    RegVal &= (HVI_AE_UCFG_DIVSEL_MASK | HVI_AE_UCFG_PDEN_MASK);
    if ((RegVal != (HVI_AE_UCFG_DIVSEL(HVI_DIV_SELECT) | HVI_AE_UCFG_PDEN_MASK)) || ((Std_ReturnType)E_NOT_OK == ReturnStatus))
    {
        bPass = FALSE;
    }

    Exit_Example(bPass);
    
    return 0;
}


#ifdef __cplusplus
}
#endif

/** @} */
