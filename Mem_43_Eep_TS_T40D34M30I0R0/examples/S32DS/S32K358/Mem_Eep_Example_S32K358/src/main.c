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
#include "Mcu.h"
#include "Platform.h"
#include "Mem_43_Eep.h"
#include "Mem_43_Eep_IPW.h"
#include "check_example.h"
/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/
#define NUMBER_OF_SECTORS_TO_TEST              1U
#define SECTOR_SIZE                            512U     /* SD_IP_SDMMC_DEFAULT_BLOCK_SIZE */

#define MEM_43_EEP_TEST_ADDR                   (0U)
#define MEM_43_EEP_TEST_SIZE                   (NUMBER_OF_SECTORS_TO_TEST * SECTOR_SIZE)
/*==================================================================================================
*                                      GLOBAL CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                      GLOBAL VARIABLES
==================================================================================================*/

/* Data buffers to test */
#define MEM_43_EEP_START_SEC_VAR_CLEARED_8_NO_CACHEABLE
#include "Mem_43_Eep_MemMap.h"

VAR_ALIGN(Mem_43_Eep_DataType TxBuffer[MEM_43_EEP_TEST_SIZE],4U)
VAR_ALIGN(Mem_43_Eep_DataType RxBuffer[MEM_43_EEP_TEST_SIZE],4U)

#define MEM_43_EEP_STOP_SEC_VAR_CLEARED_8_NO_CACHEABLE
#include "Mem_43_Eep_MemMap.h"

/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/


/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/

void BufferInit(void)
{
    uint32 i;

    for (i = 0; i < MEM_43_EEP_TEST_SIZE; i++)
    {
        TxBuffer[i] = (Mem_43_Eep_DataType)(i);
        RxBuffer[i] = (Mem_43_Eep_DataType)0x0U;
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
/* Pin setup for s32k358_mapbga289 */
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
*                                       GLOBAL FUNCTIONS
==================================================================================================*/

/**
* @brief        Main function of the example
* @details      Initializez the used drivers
*/
int main(void)
{
    uint16 Count = 0;
    Std_ReturnType Status;
    Mem_43_Eep_LengthType CompareLength = MEM_43_EEP_TEST_SIZE;

    /* Initialize clock module */
    #if (MCU_PRECOMPILE_SUPPORT == STD_ON)
    Mcu_Init(NULL_PTR);
    #endif

    /* Set mode for enable uSDHC clock */
    Mcu_SetMode(McuModeSettingConf_0);
    
    /* Initialize the clock tree and apply PLL as system clock */
    Mcu_InitClock(McuClockSettingConfig_0);

    while ( MCU_PLL_LOCKED != Mcu_GetPllStatus() )
    {
        /* Busy wait until the System PLL is locked */
    }
    /* Distribute the PLL across the clock tree */
    Mcu_DistributePllClock();

    /* Initialize Platform driver, enable interrupt for Usdhc */
    Platform_Init(NULL_PTR);

    /* Initialize uSDHC controller pins */
    PinInit();

    /* Initialize Tx and Rx buffer */
    BufferInit();

    /* Init Mem_43_Eep driver */
    Mem_43_Eep_Init(NULL_PTR);

    /* Erase memory */
    Status = Mem_43_Eep_Erase(MEM_43_EEP_INSTANCE_0_ID, MEM_43_EEP_TEST_ADDR, MEM_43_EEP_TEST_SIZE);
    ExampleAssert(E_OK == Status);
    /* Perform the job */
    do
    {
        Mem_43_Eep_MainFunction();
    }while (MEM_43_EEP_JOB_PENDING == Mem_43_Eep_GetJobResult(MEM_43_EEP_INSTANCE_0_ID));
    /* Check job result */
    ExampleAssert(MEM_43_EEP_JOB_OK == Mem_43_Eep_GetJobResult(MEM_43_EEP_INSTANCE_0_ID));

    /* Write one or more complete mem_43_eeprom pages to the mem_43_eeprom device */
    Status = Mem_43_Eep_Write(MEM_43_EEP_INSTANCE_0_ID, MEM_43_EEP_TEST_ADDR, TxBuffer, MEM_43_EEP_TEST_SIZE);
    ExampleAssert(E_OK == Status);
    /* Perform the job */
    do
    {
        Mem_43_Eep_MainFunction();
    }while (MEM_43_EEP_JOB_PENDING == Mem_43_Eep_GetJobResult(MEM_43_EEP_INSTANCE_0_ID));
    /* Check job result */
    ExampleAssert(MEM_43_EEP_JOB_OK == Mem_43_Eep_GetJobResult(MEM_43_EEP_INSTANCE_0_ID));

    /** Compare mem_43_eeprom memory area with an application data buffer **/
    /* Set Eep memory address needs to be compared */
    Mem_43_Eep_Conpare_u32EepromAddrNeedsCompared = MEM_43_EEP_TEST_ADDR;
    /* Set job for Compare feature */
    Status = Mem_43_Eep_HwSpecificService(MEM_43_EEP_INSTANCE_0_ID, MEM_43_EEP_HWSERVICEID_COMPARE, TxBuffer, &CompareLength);
    ExampleAssert(E_OK == Status);
    /* Perform the job */
    do
    {
        Mem_43_Eep_MainFunction();
    }while (MEM_43_EEP_JOB_PENDING == Mem_43_Eep_GetJobResult(MEM_43_EEP_INSTANCE_0_ID));
    /* Check job result */
    ExampleAssert(MEM_43_EEP_JOB_OK == Mem_43_Eep_GetJobResult(MEM_43_EEP_INSTANCE_0_ID));

    /* Read data from mem_43_eeprom memory */
    Status = Mem_43_Eep_Read(MEM_43_EEP_INSTANCE_0_ID, MEM_43_EEP_TEST_ADDR, RxBuffer, MEM_43_EEP_TEST_SIZE);
    ExampleAssert(E_OK == Status);
    /* Perform the job */
    do
    {
        Mem_43_Eep_MainFunction();
    }while (MEM_43_EEP_JOB_PENDING == Mem_43_Eep_GetJobResult(MEM_43_EEP_INSTANCE_0_ID));
    /* Check job result */
    ExampleAssert(MEM_43_EEP_JOB_OK == Mem_43_Eep_GetJobResult(MEM_43_EEP_INSTANCE_0_ID));

    /* Check received data */
    for (Count = 0; Count < MEM_43_EEP_TEST_SIZE; Count++)
    {
        ExampleAssert(RxBuffer[Count] == TxBuffer[Count]);
    }

    /* If we get here it means the test has passed */
    Exit_Example(TRUE);
    return (0U);
}


#ifdef __cplusplus
}
#endif

/** @} */
