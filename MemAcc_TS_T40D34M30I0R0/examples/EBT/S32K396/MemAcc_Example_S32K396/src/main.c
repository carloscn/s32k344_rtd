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
#include "sys_init.h"
#include "SchM_MemAcc.h"
#include "MemAcc.h"
#include "Mem_43_ExFls.h"
#include "S32K39.h"
#include "check_example.h"

/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/


/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/
#define TEST_AREA       (7U)
#define WRITE_ADDR      (0U)
#define SECTOR_SIZE     (0x40000U)
#define WRITE_SIZE      (128U)

/*
    S32K396: MSCR_SSS_WIDTH = 4
    Others : MSCR_SSS_WIDTH = 3
 */
#define   SIUL2_MSCR_SSS(x)   ((x) << SIUL2_MSCR_SSS_0_SHIFT)
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
uint8 TxBuffer[WRITE_SIZE];
uint8 RxBuffer[WRITE_SIZE];

/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/
void    ExampleInitBuffers(void);
boolean ExampleCheckData(uint32 offset, uint32 size);
void    ExampleAssert(boolean Condition);
void    ExampleProcessJobs(void);
void    MemAcc_PinSetup(void);
/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/
void MemAcc_PinSetup(void)
{
    /* QuadSPI_SCKFA - PTD10 */
    IP_SIUL2->MSCR[106] = SIUL2_MSCR_OBE(1U) | SIUL2_MSCR_IBE(1U) | SIUL2_MSCR_SSS(7U) | SIUL2_MSCR_DSE(1U) | SIUL2_MSCR_SRC(1U);
    IP_SIUL2->IMCR[821 - 512] = SIUL2_IMCR_SSS(1U);
    /* QuadSPI_PCSFA - PTC3 */
    IP_SIUL2->MSCR[67] = SIUL2_MSCR_OBE(1U) | SIUL2_MSCR_IBE(1U) | SIUL2_MSCR_SSS(6U) | SIUL2_MSCR_DSE(1U) | SIUL2_MSCR_SRC(1U);
    /* QuadSPI_DQSFA - PTC1 */
    IP_SIUL2->MSCR[65] = SIUL2_MSCR_OBE(1U) | SIUL2_MSCR_IBE(1U) | SIUL2_MSCR_SSS(3U) | SIUL2_MSCR_DSE(1U) | SIUL2_MSCR_SRC(0U);
    IP_SIUL2->IMCR[935 - 512] = SIUL2_IMCR_SSS(1U);
    IP_SIUL2->MSCR[107] = SIUL2_MSCR_OBE(1U) | SIUL2_MSCR_IBE(1U) | SIUL2_MSCR_SSS(7U) | SIUL2_MSCR_DSE(1U) | SIUL2_MSCR_SRC(0U);
    IP_SIUL2->IMCR[817 - 512] = SIUL2_IMCR_SSS(1U);
    /* QuadSPI_IOFA1 - PTD7 */
    IP_SIUL2->MSCR[103] = SIUL2_MSCR_OBE(1U) | SIUL2_MSCR_IBE(1U) | SIUL2_MSCR_SSS(7U) | SIUL2_MSCR_DSE(1U) | SIUL2_MSCR_SRC(0U);
    IP_SIUL2->IMCR[818 - 512] = SIUL2_IMCR_SSS(1U);
    /* QuadSPI_IOFA2 - PTD12 */
    IP_SIUL2->MSCR[108] = SIUL2_MSCR_OBE(1U) | SIUL2_MSCR_IBE(1U) | SIUL2_MSCR_SSS(7U) | SIUL2_MSCR_DSE(1U) | SIUL2_MSCR_SRC(0U);
    IP_SIUL2->IMCR[819 - 512] = SIUL2_IMCR_SSS(1U);
    /* QuadSPI_IOFA3 - PTC2 */
    IP_SIUL2->MSCR[66] = SIUL2_MSCR_OBE(1U) | SIUL2_MSCR_IBE(1U) | SIUL2_MSCR_SSS(7U) | SIUL2_MSCR_DSE(1U) | SIUL2_MSCR_SRC(0U);
    IP_SIUL2->IMCR[820 - 512] = SIUL2_IMCR_SSS(1U);
    /* QuadSPI_IOFA4 - PTC0 */
    IP_SIUL2->MSCR[64] = SIUL2_MSCR_OBE(1U) | SIUL2_MSCR_IBE(1U) | SIUL2_MSCR_SSS(4U) | SIUL2_MSCR_DSE(1U) | SIUL2_MSCR_SRC(0U);
    IP_SIUL2->IMCR[931 - 512] = SIUL2_IMCR_SSS(1U);
    /* QuadSPI_IOFA5 - PTD9 */
    IP_SIUL2->MSCR[105] = SIUL2_MSCR_OBE(1U) | SIUL2_MSCR_IBE(1U) | SIUL2_MSCR_SSS(8U) | SIUL2_MSCR_DSE(1U) | SIUL2_MSCR_SRC(0U);
    IP_SIUL2->IMCR[932 - 512] = SIUL2_IMCR_SSS(1U);
    /* QuadSPI_IOFA6 - PTD8 */
    IP_SIUL2->MSCR[104] = SIUL2_MSCR_OBE(1U) | SIUL2_MSCR_IBE(1U) | SIUL2_MSCR_SSS(8U) | SIUL2_MSCR_DSE(1U) | SIUL2_MSCR_SRC(0U);
    IP_SIUL2->IMCR[933 - 512] = SIUL2_IMCR_SSS(1U);
    /* QuadSPI_IOFA7 - PTC17 */
    IP_SIUL2->MSCR[81] = SIUL2_MSCR_OBE(1U) | SIUL2_MSCR_IBE(1U) | SIUL2_MSCR_SSS(8U) | SIUL2_MSCR_DSE(1U) | SIUL2_MSCR_SRC(0U);
    IP_SIUL2->IMCR[934 - 512] = SIUL2_IMCR_SSS(1U);
}


/**
 * @brief Implement a simple assert macro
 *
 * @param  Condition
 * @return void
 */
void ExampleAssert(boolean Condition)
{
    while (!Condition)
    {
        /* Loop forever */
    }
}


void ExampleInitBuffers(void)
{
    uint32 Index;

    for (Index = 0U; Index < WRITE_SIZE; Index++)
    {
        TxBuffer[Index] = (uint8)Index;
        RxBuffer[Index] = 0U;
    }
}

boolean ExampleCheckData(uint32 offset, uint32 size)
{
    uint32 i;

    /* The unused bytes must have cleared values */
    for (i = 0; i < offset; i++)
    {
        if (RxBuffer[i] != 4U) return (boolean)FALSE;
    }

    for (i = offset; i < size; i++)
    {
        if (RxBuffer[i] != TxBuffer[i]) return (boolean)FALSE;
    }
    return (boolean)TRUE;
}
void ExampleProcessJobs(void)
{
    /* Polling until the address area is not busy */
    do
    {
        MemAcc_MainFunction();
        Mem_43_ExFls_MainFunction();
    }
    while ( MEMACC_JOB_PENDING == MemAcc_GetJobStatus(TEST_AREA) );
}
/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/
/**
* @brief        Main function of the example
* @details      Initializes the used drivers and uses the Fls driver to erase, write and read the memory
*/
int main(void)
{
    boolean check;

    /* Init system */
    sys_init();

    /* Init PIN */
    MemAcc_PinSetup();

    ExampleInitBuffers();

    /* Init Mem(s) */
    Mem_43_ExFls_Init(NULL_PTR);

    /* Init MemAcc */
    MemAcc_Init(&MemAcc_Config);

    ExampleAssert(MEMACC_JOB_IDLE == MemAcc_GetJobStatus(TEST_AREA));
    ExampleAssert(MEMACC_MEM_OK   == MemAcc_GetJobResult(TEST_AREA));

    /* Erase */
    ExampleAssert(E_OK == MemAcc_Erase(TEST_AREA, WRITE_ADDR, SECTOR_SIZE));
    ExampleProcessJobs();

    /* BlankCheck */
    ExampleAssert(E_OK == MemAcc_BlankCheck(TEST_AREA, WRITE_ADDR, SECTOR_SIZE));
    ExampleProcessJobs();

    /* Write */
    ExampleAssert(E_OK == MemAcc_Write(TEST_AREA, WRITE_ADDR, TxBuffer, WRITE_SIZE));
    ExampleProcessJobs();

    /* Read */
    ExampleAssert(E_OK == MemAcc_Read(TEST_AREA, WRITE_ADDR, RxBuffer, WRITE_SIZE));
    ExampleProcessJobs();

    check = ExampleCheckData(0U, WRITE_SIZE);
    ExampleAssert(check == (boolean)TRUE);

    /* If we get here it means the test has passed */
    Exit_Example(TRUE);
    return (0U);
}

#ifdef __cplusplus
}
#endif

/** @} */
