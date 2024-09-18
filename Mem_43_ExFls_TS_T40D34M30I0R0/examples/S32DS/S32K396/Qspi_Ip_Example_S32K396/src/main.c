/*
*   (c) Copyright 2020 NXP
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
#include "S32K39_SIUL2.h"
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
#define MEM_EXFLS_JOB_SIZE                 256U
#define MEM_EXFLS_JOB_ADDRESS              0x40000U
#define MEM_EXFLS_SECTOR_SIZE              0x40000U
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
uint8 Txdata[MEM_EXFLS_JOB_SIZE];
uint8 Rxdata_IP[MEM_EXFLS_JOB_SIZE];
uint8 Rxdata_AHB[MEM_EXFLS_JOB_SIZE];
/*==================================================================================================
*                                       DEFINE MACRO
==================================================================================================*/
#define   SIUL2_MSCR_SSS(x)   ((x) << SIUL2_MSCR_SSS_0_SHIFT)


/*==================================================================================================
*                                      GLOBAL VARIABLES
==================================================================================================*/


/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/
void Mem_ExFls_PinSetup(void);
void Mem_ExFls_InitBuffers(void);
boolean Mem_ExFls_VerifyBuffers(void);

/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/
void Mem_ExFls_PinSetup(void)
{
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
}

void Mem_ExFls_InitBuffers(void)
{
    uint32 i;

    for (i = 0U; i < MEM_EXFLS_JOB_SIZE; i++)
    {
        Txdata[i] = (uint8)i;
        Rxdata_IP[i] = 0U;
        Rxdata_AHB[i] = 0U;
    }
}

boolean Mem_ExFls_VerifyBuffers()
{
    uint32 i;
    volatile uint8 temp;
    boolean retVal = TRUE;

    for (i = 0U; i < MEM_EXFLS_JOB_SIZE; i++)
    {
        temp = Txdata[i];
        if ( (Rxdata_IP[i] != temp) || (Rxdata_AHB[i] != temp) )
        {
            retVal = FALSE;
            break;
        }
    }
    return retVal;
}


/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/
/**
* @brief        Main function of the example
* @details      Initializez Mem IP C40 driver and
*               erase, write, read internal fls memory
*/
int main(void)
{
    boolean exampleStatus = TRUE;
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
    if (STATUS_QSPI_IP_SUCCESS != qspiStatus)
    {
        exampleStatus = FALSE;
    }
    qspiStatus = Qspi_Ip_Init(instance, &Qspi_Ip_paFlashCfg[0], &Qspi_Ip_paFlashConnectionCfg[0]);
    if (STATUS_QSPI_IP_SUCCESS != qspiStatus)
    {
        exampleStatus = FALSE;
    }

    /* Erase an external sector which has address is 4096 */
    qspiStatus = Qspi_Ip_EraseBlock(instance, MEM_EXFLS_JOB_ADDRESS, MEM_EXFLS_SECTOR_SIZE);
    if (STATUS_QSPI_IP_SUCCESS != qspiStatus)
    {
        exampleStatus = FALSE;
    }

    /* Check qspiStatus of external memory */
    while ((STATUS_QSPI_IP_BUSY == (qspiStatus = Qspi_Ip_GetMemoryStatus(instance))) && (timeout > 0))
    {
        timeout--;
    }
    if (STATUS_QSPI_IP_SUCCESS != qspiStatus)
    {
        exampleStatus = FALSE;
    }

    /* Verify erase */
    if (STATUS_QSPI_IP_SUCCESS != Qspi_Ip_EraseVerify(instance, MEM_EXFLS_JOB_ADDRESS, MEM_EXFLS_SECTOR_SIZE))
    {
        exampleStatus = FALSE;
    }

    /* Reset Timeout*/
    timeout = MEM_EXFLS_TIME_OUT;
    /* Write to external flash*/
    if (STATUS_QSPI_IP_SUCCESS != Qspi_Ip_Program(instance, MEM_EXFLS_JOB_ADDRESS, Txdata, MEM_EXFLS_JOB_SIZE))
    {
        exampleStatus = FALSE;
    }

    /* Check qspiStatus of external memory */
    while ((STATUS_QSPI_IP_BUSY == (qspiStatus = Qspi_Ip_GetMemoryStatus(instance))) && (timeout > 0))
    {
        timeout--;
    }
    if (STATUS_QSPI_IP_SUCCESS != qspiStatus)
    {
        exampleStatus = FALSE;
    }

    /* Read data from external flash*/

    /* Using IP command read into Rxdata_IP buffer */
    if (STATUS_QSPI_IP_SUCCESS != Qspi_Ip_Read(instance, MEM_EXFLS_JOB_ADDRESS, Rxdata_IP, MEM_EXFLS_JOB_SIZE))
    {
        exampleStatus = FALSE;
    }

    /* Using AHB command read into Rxdata_AHB buffer */
    qspiStatus = Qspi_Ip_AhbReadEnable(instance);
    if (STATUS_QSPI_IP_SUCCESS == qspiStatus)
    {
        /* Table of AHB addresses for QuadSPI instances. */
        const uint32 Qspi_Ip_AhbAddress[QuadSPI_INSTANCE_COUNT] = QuadSPI_AHB_PTRS;
        /* Get AHB address of QspiInstance */
        uint8* pAHBExAddr = (uint8*)(Qspi_Ip_AhbAddress[instance] + MEM_EXFLS_JOB_ADDRESS);

        for (uint32 i = 0U; i < MEM_EXFLS_JOB_SIZE; i++)
        {
            Rxdata_AHB[i] = pAHBExAddr[i];
        }
    }
    else
    {
        exampleStatus = FALSE;
    }

    if (! Mem_ExFls_VerifyBuffers())
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
