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
#include "S32K358_SIUL2.h"
#include "Sd_Emmc_Ip.h"
#include "Usdhc_Ip.h"
#include "Sd_Emmc_Ip_Cfg.h"
#include "Clock_Ip.h"
#include "IntCtrl_Ip.h"
#include "check_example.h"

/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/
/* Test Erase/Write/Read: 10 blocks from block 1 */
#define MEM_43_EEP_BLOCK_START             (1U)
#define MEM_43_EEP_BLOCK_COUNT             (10U)      /* 10 blocks */

#define MEM_43_EEP_BLOCK_SIZE              (512U)     /* 512 bytes */
#define MEM_43_EEP_TEST_SIZE               (MEM_43_EEP_BLOCK_SIZE * MEM_43_EEP_BLOCK_COUNT)

/*==================================================================================================
*                                      GLOBAL CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                      GLOBAL VARIABLES
==================================================================================================*/
/* Data buffers to test */
#define MEM_43_EEP_START_SEC_VAR_CLEARED_8_NO_CACHEABLE
#include "Mem_43_Eep_MemMap.h"

VAR_ALIGN(uint8 TxBuffer[MEM_43_EEP_TEST_SIZE],4U)
VAR_ALIGN(uint8 RxBuffer[MEM_43_EEP_TEST_SIZE],4U)

#define MEM_43_EEP_STOP_SEC_VAR_CLEARED_8_NO_CACHEABLE
#include "Mem_43_Eep_MemMap.h"

/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/

void BufferInit(void)
{
    uint32 Count;

    /* Initialize data to default value */
    for (Count = 0U; Count < MEM_43_EEP_TEST_SIZE; Count++)
    {
        TxBuffer[Count] = (uint8)Count;
        RxBuffer[Count] = 0U;
    }
}

void PinInit(void)
{
/*** PTA31  -> uSDHC_D[0] */
    IP_SIUL2->MSCR[31] = SIUL2_MSCR_OBE(1U) | SIUL2_MSCR_IBE(1U) | SIUL2_MSCR_PUE(1) | SIUL2_MSCR_PUS(1) | SIUL2_MSCR_SSS_1(1U) | SIUL2_MSCR_SSS_2(1U);
    IP_SIUL2->IMCR[939-512] = SIUL2_IMCR_SSS(4U);
/*** PTB18  -> uSDHC_D[1] */
    IP_SIUL2->MSCR[50] = SIUL2_MSCR_OBE(1U) | SIUL2_MSCR_IBE(1U) | SIUL2_MSCR_PUE(1) | SIUL2_MSCR_PUS(1) | SIUL2_MSCR_SSS_0(1U) | SIUL2_MSCR_SSS_3(1U);
    IP_SIUL2->IMCR[940-512] = SIUL2_IMCR_SSS(6U);
/*** PTB19  -> uSDHC_D[2] */   
    IP_SIUL2->MSCR[51] = SIUL2_MSCR_OBE(1U) | SIUL2_MSCR_IBE(1U) | SIUL2_MSCR_PUE(1) | SIUL2_MSCR_PUS(1) | SIUL2_MSCR_SSS_3(1U);
    IP_SIUL2->IMCR[941-512] = SIUL2_IMCR_SSS(3U);
/*** PTA29  -> uSDHC_D[3] */   
    IP_SIUL2->MSCR[29] = SIUL2_MSCR_OBE(1U) | SIUL2_MSCR_IBE(1U) | SIUL2_MSCR_PUE(1) | SIUL2_MSCR_PUS(1) | SIUL2_MSCR_SSS_3(1U) | SIUL2_MSCR_SSS_0(1U);
    IP_SIUL2->IMCR[942-512] = SIUL2_IMCR_SSS(4U);
/*** PTB26  -> uSDHC_CMD  */    
    IP_SIUL2->MSCR[58] = SIUL2_MSCR_OBE(1U) | SIUL2_MSCR_IBE(1U) | SIUL2_MSCR_PUE(1) | SIUL2_MSCR_PUS(1) | SIUL2_MSCR_SSS_0(1U) | SIUL2_MSCR_SSS_2(1U);
    IP_SIUL2->IMCR[938-512] = SIUL2_IMCR_SSS(3U);
    #ifdef S32K358_172MQFP
/* Pin setup for s32k358_172mqfp */
/*** PTD8  -> uSDHC_CLK  */    
    IP_SIUL2->MSCR[104] = SIUL2_MSCR_OBE(1U) | SIUL2_MSCR_IBE(1U) | SIUL2_MSCR_PUE(1) | SIUL2_MSCR_PUS(1) | SIUL2_MSCR_SSS_0(1U) | SIUL2_MSCR_SSS_1(1U) | SIUL2_MSCR_SSS_3(1U);
    IP_SIUL2->IMCR[937-512] = SIUL2_IMCR_SSS(6U);
    #else
/* Pin setup for s32k358_289bga */
/*** PTA30 ->  uSDHC_D[4]  */    
    IP_SIUL2->MSCR[30]  = SIUL2_MSCR_OBE(1U) | SIUL2_MSCR_IBE(1U) | SIUL2_MSCR_PUE(1) | SIUL2_MSCR_PUS(1) | SIUL2_MSCR_SSS_0(1U) | SIUL2_MSCR_SSS_1(1U) | SIUL2_MSCR_SSS_2(1U);
    IP_SIUL2->IMCR[943-512] = SIUL2_IMCR_SSS(1U);
/*** PTA28  ->  uSDHC_D[5] */
    IP_SIUL2->MSCR[28]  = SIUL2_MSCR_OBE(1U) | SIUL2_MSCR_IBE(1U) | SIUL2_MSCR_PUE(1) | SIUL2_MSCR_PUS(1) | SIUL2_MSCR_SSS_3(1U) | SIUL2_MSCR_SSS_1(1U);
    IP_SIUL2->IMCR[944-512] = SIUL2_IMCR_SSS(1U);
/*** PTB21  -> uSDHC_D[6] */    
    IP_SIUL2->MSCR[53]  = SIUL2_MSCR_OBE(1U) | SIUL2_MSCR_IBE(1U) | SIUL2_MSCR_PUE(1) | SIUL2_MSCR_PUS(1) | SIUL2_MSCR_SSS_2(1U);
    IP_SIUL2->IMCR[945-512] = SIUL2_IMCR_SSS(1U);
/*** PTB20  ->  uSDHC_D[7] */    
    IP_SIUL2->MSCR[52]  = SIUL2_MSCR_OBE(1U) | SIUL2_MSCR_IBE(1U) | SIUL2_MSCR_PUE(1) | SIUL2_MSCR_PUS(1) | SIUL2_MSCR_SSS_0(1U) | SIUL2_MSCR_SSS_3(1U); 
    IP_SIUL2->IMCR[946-512] = SIUL2_IMCR_SSS(1U);
/*** PTB5  -> uSDHC_CLK  */    
    IP_SIUL2->MSCR[37] = SIUL2_MSCR_OBE(1U) | SIUL2_MSCR_IBE(1U) | SIUL2_MSCR_PUE(1) | SIUL2_MSCR_PUS(1) | SIUL2_MSCR_SSS_1(1U)| SIUL2_MSCR_SSS_3(1U);
    IP_SIUL2->IMCR[937-512] = SIUL2_IMCR_SSS(3U);
    #endif
/*** PTE12 -> uSDHC_RESET_B */
    IP_SIUL2->MSCR[140] = SIUL2_MSCR_OBE(1U) | SIUL2_MSCR_IBE(1U) | SIUL2_MSCR_PUE(1) | SIUL2_MSCR_PUS(1) | SIUL2_MSCR_SSS_0(1U); 
/*** PTE12 -> uSDHC_WP */    
    IP_SIUL2->IMCR[936 - 512] = SIUL2_IMCR_SSS(1U);
}

/* Implement a simple assert macro */
void ExampleAssert(boolean Condition)
{
    if (!Condition)
    {
        /* Stop here */
        ASM_KEYWORD(BREAKPOINT_INSTR);
        for (;;)
        {
            /* Loop forever */
        }
    }
}

/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/


/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/

/**
* @brief        Main function of the example
* @details      Initializez the used drivers
*/
int main(void)
{
    uint32 Count;
    Usdhc_Ip_StateType ControllerState;
    Sd_Emmc_Ip_StatusType SdStatus;
    Usdhc_Ip_StatusType ControllerStatus;

    /* Initialize clock module */
    Clock_Ip_InitClock(&Clock_Ip_aClockConfig[0]);
    while ( CLOCK_IP_PLL_LOCKED != Clock_Ip_GetPllStatus() )
    {
        /* Busy wait until the System PLL is locked */
    }
    /* Distribute the PLL across the clock tree */
    Clock_Ip_DistributePll();

    /* Install and enable interrupt for Usdhc */
    IntCtrl_Ip_Init(&IntCtrlConfig_0);

    /* Initialize uSDHC controller pins */
    PinInit();

    /* Initialize Tx and Rx buffer */
    BufferInit();

    /* Init controller */
    ControllerStatus = uSDHC_Ip_Init(&ControllerState, &UsdhcControllerCfg_0, 0U);
    ExampleAssert(STATUS_USDHC_IP_SUCCESS == ControllerStatus);
    /* Init card */
    SdStatus = Sd_Emmc_Ip_Init(&EepSdCfg_0);
    ExampleAssert(SD_IP_STATUS_SUCCESS == SdStatus);

    /* Test Erase/Write/Read syn mode: MEM_43_EEP_BLOCK_COUNT from MEM_43_EEP_BLOCK_START */

    /* Erase block with syn mode */
    SdStatus = Sd_Emmc_Ip_EraseBlocks(&EepSdCfg_0, MEM_43_EEP_BLOCK_START, MEM_43_EEP_BLOCK_COUNT, (boolean)FALSE);
    ExampleAssert(SD_IP_STATUS_SUCCESS == SdStatus);
    /* Read block */
    SdStatus = Sd_Emmc_Ip_ReadBlocks(&EepSdCfg_0, RxBuffer, MEM_43_EEP_BLOCK_START, MEM_43_EEP_BLOCK_COUNT);
    ExampleAssert(SD_IP_STATUS_SUCCESS == SdStatus);
    /* Blank check */
    for (Count = 0; Count < MEM_43_EEP_TEST_SIZE; Count++)
    {
        ExampleAssert(0U == RxBuffer[Count]);
    }

    /* Write block */
    SdStatus = Sd_Emmc_Ip_WriteBlocks(&EepSdCfg_0, TxBuffer, MEM_43_EEP_BLOCK_START, MEM_43_EEP_BLOCK_COUNT, (boolean)FALSE);
    ExampleAssert(SD_IP_STATUS_SUCCESS == SdStatus);
    /* Read block */
    SdStatus = Sd_Emmc_Ip_ReadBlocks(&EepSdCfg_0, RxBuffer, MEM_43_EEP_BLOCK_START, MEM_43_EEP_BLOCK_COUNT);
    ExampleAssert(SD_IP_STATUS_SUCCESS == SdStatus);
    /* Verify received data */
    for (Count = 0; Count < MEM_43_EEP_TEST_SIZE; Count++)
    {
        ExampleAssert(RxBuffer[Count] == TxBuffer[Count]);
    }

    Exit_Example(TRUE);
    return (0U);
}


#ifdef __cplusplus
}
#endif

/** @} */
