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
extern "C"
{
#endif

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "sys_init.h"
#include "SchM_Mem_43_ExFls.h"
#include "Mem_43_ExFls.h"
#include "Qspi_Ip.h"
#include "S32K358_SIUL2.h"


/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/

#define WRITE_ADDR                  0U
#define SECTOR_SIZE                 4096U
#define WRITE_SIZE                  512U

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
*                                       DEFINE MACRO
==================================================================================================*/
#define SIUL2_MSCR_SSS(x)    ((x) << SIUL2_MSCR_SSS_0_SHIFT)


/*==================================================================================================
*                                      GLOBAL VARIABLES
==================================================================================================*/

uint8 Txdata[WRITE_SIZE];
uint8 Rxdata[WRITE_SIZE];
const Mem_43_ExFls_InstanceIdType Test_MemInstanceId = MEM_43_EXFLS_INSTANCE_0_ID;


/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/


/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/
/**
 * @brief Implement a simple assert macro
 *
 * @param  Condition
 * @return void
 */

static inline void Exit_Example(boolean result)
{
    volatile uint8 * testResultBasePtr;

    testResultBasePtr = (volatile uint8 *)VV_RESULT_ADDRESS;

    if (TRUE == result)
    {
        *testResultBasePtr = 0x5AU;
    }
    else
    {
        *testResultBasePtr = 0x33U;
    }
}

void Mem_ExFls_PinSetup(void)
{
#if (defined(S32K396)|| defined(S32K358))
    /* QuadSPI_SCKFA - PTD10 */
    IP_SIUL2->MSCR[106] = SIUL2_MSCR_OBE(1U) | SIUL2_MSCR_IBE(1U) | SIUL2_MSCR_SSS(7U) | SIUL2_MSCR_DSE(1U) | SIUL2_MSCR_SRC(1U);
    IP_SIUL2->IMCR[821 - 512] = SIUL2_IMCR_SSS(1U);

    /* QuadSPI_PCSFA - PTC3 */
    IP_SIUL2->MSCR[67] = SIUL2_MSCR_OBE(1U) | SIUL2_MSCR_IBE(1U) | SIUL2_MSCR_SSS(6U) | SIUL2_MSCR_DSE(1U) | SIUL2_MSCR_SRC(1U);

    /* QuadSPI_DQSFA - PTC1 */
    IP_SIUL2->MSCR[65] = SIUL2_MSCR_OBE(1U) | SIUL2_MSCR_IBE(1U) | SIUL2_MSCR_SSS(3U) | SIUL2_MSCR_DSE(1U) | SIUL2_MSCR_SRC(0U);
    IP_SIUL2->IMCR[935 - 512] = SIUL2_IMCR_SSS(1U);

    #if 0
    /* QuadSPI_INTA - PTB2 (Not connected to the memory chip, just pull-up) */
    IP_SIUL2->MSCR[34] = SIUL2_MSCR_OBE(0U) | SIUL2_MSCR_IBE(1U) | SIUL2_MSCR_SSS(0U) | SIUL2_MSCR_DSE(1U) | SIUL2_MSCR_PUE(1U) | SIUL2_MSCR_PUS(1U);
    IP_SIUL2->IMCR[949 - 512] = SIUL2_IMCR_SSS(5U);  /* Source from PTB2 */
    #endif

    /* QuadSPI_IOFA0 - PTD11 */
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
#endif
}


void Mem_ExFls_TxBufInit(void)
{
    uint32 i;

    for (i = 0; i < WRITE_SIZE; i++)
    {
        Txdata[i]  = (uint8)(i);
    }
}

void Mem_ExFls_RxBufClr(void)
{
    uint32 i;

    for (i = 0; i < WRITE_SIZE; i++)
    {
        Rxdata[i]  = 4U;
    }
}

sint32 Mem_ExFls_CheckData(uint32 offset, uint32 size)
{
    uint32 i;

    /* The unused bytes must have cleared values */
    for (i = 0; i < offset; i++)
    {
        if (Rxdata[i] != 4U) return i;
    }

    for (i = offset; i < size; i++)
    {
        if (Rxdata[i] != Txdata[i]) return i;
    }
    return -1;
}

void Mem_ExFls_ProcessJobs(void)
{
    /* Polling until the driver is not busy */
    do
    {
        Mem_43_ExFls_MainFunction();
    }
    while ( MEM_43_EXFLS_JOB_PENDING == Mem_43_ExFls_GetJobResult(Test_MemInstanceId) );
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
    boolean exampleStatus = TRUE;

    sys_init();
    Mem_ExFls_PinSetup();

    volatile sint32 check;

    Mem_ExFls_TxBufInit();
    Mem_ExFls_RxBufClr();

    Mem_43_ExFls_Init(NULL_PTR);
    if (MEM_43_EXFLS_JOB_OK != Mem_43_ExFls_GetJobResult(Test_MemInstanceId))
    {
        exampleStatus = FALSE;
    }

    /* Erase */
    Mem_43_ExFls_Erase(Test_MemInstanceId, WRITE_ADDR, SECTOR_SIZE);
    Mem_ExFls_ProcessJobs();
    if (MEM_43_EXFLS_JOB_OK != Mem_43_ExFls_GetJobResult(Test_MemInstanceId))
    {
        exampleStatus = FALSE;
    }

    /* BlankCheck */
    Mem_43_ExFls_BlankCheck(Test_MemInstanceId, WRITE_ADDR, SECTOR_SIZE);
    Mem_ExFls_ProcessJobs();
    if (MEM_43_EXFLS_JOB_OK != Mem_43_ExFls_GetJobResult(Test_MemInstanceId))
    {
        exampleStatus = FALSE;
    }

    /* Write */
    Mem_43_ExFls_Write(Test_MemInstanceId, WRITE_ADDR, Txdata, WRITE_SIZE);
    Mem_ExFls_ProcessJobs();
    if (MEM_43_EXFLS_JOB_OK != Mem_43_ExFls_GetJobResult(Test_MemInstanceId))
    {
        exampleStatus = FALSE;
    }

    /* Read */
    Mem_43_ExFls_Read(Test_MemInstanceId, WRITE_ADDR, Rxdata, WRITE_SIZE);
    Mem_ExFls_ProcessJobs();

    check = Mem_ExFls_CheckData(0U, WRITE_SIZE);

    if (check != (-1))
    {
        exampleStatus = FALSE;
    }

    Exit_Example(exampleStatus);
    return (0U);
}

#ifdef __cplusplus
}
#endif

/** @} */
