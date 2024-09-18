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
#include "Clock_Ip.h"
#include "S32K344_SIUL2.h"
#include "Qspi_Ip.h"
#include "Qspi_Ip_Cfg.h"
#include "sys_init.h"
#include "check_example.h"

/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/


/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/
#define MEM_EXFLS_BUF_SIZE                 128U
#define MEM_EXFLS_JOB_ADDRESS              0x1000U
#define MEM_EXFLS_SECTOR_SIZE              0x1000U
#define MEM_EXFLS_TIME_OUT                 32768U

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
#define SIUL2_MSCR_SSS(x)            (SIUL2_MSCR_SSS_0((x) & 1U) | SIUL2_MSCR_SSS_1(((x) >> 1U) & 1U) | SIUL2_MSCR_SSS_2(((x) >> 2U) & 1U))


/*==================================================================================================
*                                      GLOBAL VARIABLES
==================================================================================================*/

uint8 TxBuffer[MEM_EXFLS_BUF_SIZE];
uint8 RxBuffer_IP[MEM_EXFLS_BUF_SIZE];
uint8 RxBuffer_AHB[MEM_EXFLS_BUF_SIZE];
/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/
void Mem_ExFls_PinSetup(void);
void Mem_ExFls_InitBuffers(void);
void Mem_ExFls_ExampleAssert(boolean Condition);

/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/
/**
 * @brief Implement a simple assert macro
 *
 * @param  Condition
 * @return void
 */
void Mem_ExFls_ExampleAssert(boolean Condition)
{
    while (!Condition)
    {
        /* Loop forever */
    }
}


void Mem_ExFls_PinSetup(void)
{
    /* QuadSPI_PCSFA - PTC3 */
    IP_SIUL2->MSCR[67] = SIUL2_MSCR_OBE(1U) | SIUL2_MSCR_IBE(0U) | SIUL2_MSCR_SSS(6U) | SIUL2_MSCR_DSE(1U);

    /* QuadSPI_SCKFA - PTD10 */
    IP_SIUL2->MSCR[106] = SIUL2_MSCR_OBE(1U) | SIUL2_MSCR_IBE(1U) | SIUL2_MSCR_SSS(7U) | SIUL2_MSCR_DSE(1U);
    IP_SIUL2->IMCR[821 - 512] = SIUL2_IMCR_SSS(1U);

    /* QuadSPI_IOFA0 - PTD11 */
    IP_SIUL2->MSCR[107] = SIUL2_MSCR_OBE(1U) | SIUL2_MSCR_IBE(1U) | SIUL2_MSCR_SSS(7U) | SIUL2_MSCR_DSE(1U);
    IP_SIUL2->IMCR[817 - 512] = SIUL2_IMCR_SSS(1U);
    /* QuadSPI_IOFA1 - PTD7 */
    IP_SIUL2->MSCR[103] = SIUL2_MSCR_OBE(1U) | SIUL2_MSCR_IBE(1U) | SIUL2_MSCR_SSS(7U) | SIUL2_MSCR_DSE(1U);
    IP_SIUL2->IMCR[818 - 512] = SIUL2_IMCR_SSS(1U);
    /* QuadSPI_IOFA2 - PTD12 */
    IP_SIUL2->MSCR[108] = SIUL2_MSCR_OBE(1U) | SIUL2_MSCR_IBE(1U) | SIUL2_MSCR_SSS(7U) | SIUL2_MSCR_DSE(1U);
    IP_SIUL2->IMCR[819 - 512] = SIUL2_IMCR_SSS(1U);
    /* QuadSPI_IOFA3 - PTC2 */
    IP_SIUL2->MSCR[66] = SIUL2_MSCR_OBE(1U) | SIUL2_MSCR_IBE(1U) | SIUL2_MSCR_SSS(7U) | SIUL2_MSCR_DSE(1U);
    IP_SIUL2->IMCR[820 - 512] = SIUL2_IMCR_SSS(1U);
}


void Mem_ExFls_InitBuffers(void)
{
    uint32 Index;

    for (Index = 0U; Index < MEM_EXFLS_BUF_SIZE; Index++)
    {
        TxBuffer[Index] = (uint8)Index;
        RxBuffer_IP[Index] = 0U;
        RxBuffer_AHB[Index] = 0U;
    }
}


/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/
/**
* @brief        Main function of the example
* @details      Initializez Fls IP C40 driver and
*               erase, write, read internal fls memory
*/
int main(void)
{
    uint32 timeout = MEM_EXFLS_TIME_OUT;
    uint32 instance = Qspi_Ip_paFlashConnectionCfg[0].qspiInstance;
    Qspi_Ip_StatusType qspiStatus;


    /* Initialize clock */
	sys_init();


    /* Initialize QSPI's pins */
    Mem_ExFls_PinSetup();

    /* Initialize buffers */
    Mem_ExFls_InitBuffers();

    /* Initialize QSPI */
    qspiStatus = Qspi_Ip_ControllerInit(instance, &Qspi_Ip_paQspiUnitCfg[0]);
    Mem_ExFls_ExampleAssert(STATUS_QSPI_IP_SUCCESS == qspiStatus);

    qspiStatus = Qspi_Ip_Init(instance, &Qspi_Ip_paFlashCfg[0], &Qspi_Ip_paFlashConnectionCfg[0]);
    Mem_ExFls_ExampleAssert(STATUS_QSPI_IP_SUCCESS == qspiStatus);

    /* Erase an external sector which has address is 4096 */
    qspiStatus = Qspi_Ip_EraseBlock(instance, MEM_EXFLS_JOB_ADDRESS, MEM_EXFLS_SECTOR_SIZE);
    Mem_ExFls_ExampleAssert(STATUS_QSPI_IP_SUCCESS == qspiStatus);

    /* Check qspiStatus of external memory */
    while ((STATUS_QSPI_IP_BUSY == (qspiStatus = Qspi_Ip_GetMemoryStatus(instance))) && (timeout > 0))
    {
        timeout--;
    }
    Mem_ExFls_ExampleAssert(STATUS_QSPI_IP_SUCCESS == qspiStatus);


    /* Verify erase */
    qspiStatus = Qspi_Ip_EraseVerify(instance, MEM_EXFLS_JOB_ADDRESS, MEM_EXFLS_SECTOR_SIZE);
    Mem_ExFls_ExampleAssert(STATUS_QSPI_IP_SUCCESS == qspiStatus);


    /* Write to external flash*/
    qspiStatus = Qspi_Ip_Program(instance, MEM_EXFLS_JOB_ADDRESS, TxBuffer, MEM_EXFLS_BUF_SIZE);
    Mem_ExFls_ExampleAssert(STATUS_QSPI_IP_SUCCESS == qspiStatus);

    /* Check status of external memory */
    /* Reset Timeout */
    timeout = MEM_EXFLS_TIME_OUT;
    while ((STATUS_QSPI_IP_BUSY == (qspiStatus = Qspi_Ip_GetMemoryStatus(instance))) && (timeout > 0))
    {
        timeout--;
    }
    Mem_ExFls_ExampleAssert(STATUS_QSPI_IP_SUCCESS == qspiStatus);


    /* Read data from external flash */

    /* Enable AHB read */
    qspiStatus = Qspi_Ip_AhbReadEnable(instance);
    Mem_ExFls_ExampleAssert(STATUS_QSPI_IP_SUCCESS == qspiStatus);


    /* Using IP command read into RxBuffer_IP buffer */
    qspiStatus = Qspi_Ip_Read(instance, MEM_EXFLS_JOB_ADDRESS, RxBuffer_IP, MEM_EXFLS_BUF_SIZE);
    Mem_ExFls_ExampleAssert(STATUS_QSPI_IP_SUCCESS == qspiStatus);

    /* Using AHB command read into RxBuffer_AHB buffer */

    /* Table of AHB addresses for QuadSPI instances. */
    const uint32 Qspi_Ip_AhbAddress[QuadSPI_INSTANCE_COUNT] = QuadSPI_AHB_PTRS;
    /* Get AHB address of QspiInstance */
    uint8* pAHBExAddr = (uint8*)(Qspi_Ip_AhbAddress[instance] + MEM_EXFLS_JOB_ADDRESS);

    for (uint32 Index = 0U; Index < MEM_EXFLS_BUF_SIZE; Index++)
    {
        RxBuffer_AHB[Index] = pAHBExAddr[Index];
    }

    /* Reset Timeout*/
    timeout = MEM_EXFLS_TIME_OUT;
    /* Wait until AHB accesses finish to avoid conflict between AHB commands with subsequent IP commands */
    while ((STATUS_QSPI_IP_BUSY == (qspiStatus = Qspi_Ip_ControllerGetStatus(instance))) && (timeout > 0))
    {
        timeout--;
    }
    Mem_ExFls_ExampleAssert(STATUS_QSPI_IP_SUCCESS == qspiStatus);



    /* Verify data */
    for (uint32 Index = 0U; Index < MEM_EXFLS_BUF_SIZE; Index++)
    {
        Mem_ExFls_ExampleAssert(TxBuffer[Index] == RxBuffer_IP[Index]);
        Mem_ExFls_ExampleAssert(TxBuffer[Index] == RxBuffer_AHB[Index]);
    }


    /* If we get here it means the test has passed */
    Exit_Example(TRUE);
    return (0U);
}

#ifdef __cplusplus
}
#endif

/** @} */
