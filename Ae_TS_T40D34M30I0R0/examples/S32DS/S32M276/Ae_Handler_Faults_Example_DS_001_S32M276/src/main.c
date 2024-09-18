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
#include "Platform.h"
#include "Icu.h"

#include "check_example.h"
/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/


/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/
#define AEC_FAULT_EN_ADDR                       (0x1CU)
#define AEC_ALIVE_WD_CFG_ADDR                   (0x30U)
#define AEC_ALIVE_WD_ANSWER_ADDR                (0x38U)
#define AEC_FAULTS_STATUS_ADDR                  (0x18U)
    
#define AEC_WRONG_VALUE                         (1U)
    
#define CANPHY_VALID_MASK                       (0x8003U)
#define IO_FUNCMUX_CFG_VALID                    (0x0F1F0FU)

#define RSTGEN_HIVAE_ACTIVE                     (0x0020U)

#define AEC_AE_FAULTS_ENABLE_ALIVE_WDG_EN_MASK  (0x8000U)
#define AEC_AE_FAULTS_ENABLE_XFER_ERR_EN_MASK   (0x400U)

#define AEC_DATAWIDTH_16                        (16U)

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
uint16 StatusXferFlag = 0U;
uint16 StatusWdgFlag = 0U;
/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/

void Ae_WdgNotification(void);
void Ae_XferNotification(void);

/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/

void Ae_XferNotification()
{
    StatusXferFlag++;
}

void Ae_WdgNotification()
{
    StatusWdgFlag++;
}
/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/
/**
* @brief        How to set up for the feature events/faults.
* @details
*/
int main(void)
{
    uint32 RegVal;
    boolean bPass = TRUE;
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
    
    /* Install interrupt for Icu and callback function */
    Platform_Init(NULL_PTR);
    
    /* Configure LPSI in sync mode */
    Spi_Init(NULL_PTR);
    
    /* Set Icu to catch interrupt_out */
    Icu_Init(&Icu_Config);
    Icu_EnableNotification(IcuChannel_0);
    Icu_EnableEdgeDetection(IcuChannel_0);
    
    Ae_Init(NULL_PTR);
  
    /* Fault enable to ensure faults configured as in configuration was enabled */
    ReturnStatus = Ae_ReadRegister(AEC_FAULT_EN_ADDR, AEC_DATAWIDTH_16, &RegVal);
    if (((Std_ReturnType)E_NOT_OK == ReturnStatus) || (0U == (RegVal & (AEC_AE_FAULTS_ENABLE_ALIVE_WDG_EN_MASK | AEC_AE_FAULTS_ENABLE_ALIVE_WDG_EN_MASK))))
    {
        bPass = FALSE;
    }
    
    /* Try to create faults by watchdog */
    /* Clear register to set simple mode */
    ReturnStatus = Ae_WriteRegister(AEC_ALIVE_WD_CFG_ADDR, AEC_DATAWIDTH_16, 0U);
    /* Respond value, then interrupt_out occurs */
    ReturnStatus |= Ae_WriteRegister(AEC_ALIVE_WD_ANSWER_ADDR, AEC_DATAWIDTH_16, AEC_WRONG_VALUE);
    /* Flags status have to cleard */
    ReturnStatus |= Ae_ReadRegister(AEC_FAULTS_STATUS_ADDR, AEC_DATAWIDTH_16, &RegVal);
    if (((Std_ReturnType)E_NOT_OK == ReturnStatus) || (0U != (RegVal & (AEC_AE_FAULTS_ENABLE_ALIVE_WDG_EN_MASK | AEC_AE_FAULTS_ENABLE_ALIVE_WDG_EN_MASK))))
    {
        bPass = FALSE;
    }
    /* Read status from callback functions */
    if ((0 == StatusWdgFlag) || (0 == StatusXferFlag))
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
