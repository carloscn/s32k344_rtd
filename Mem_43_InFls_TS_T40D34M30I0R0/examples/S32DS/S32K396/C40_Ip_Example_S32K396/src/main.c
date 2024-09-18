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
#include "C40_Ip.h"

#include "check_example.h"

/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/


/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/
#define FLS_MASTER_ID                0U
#define FLS_BUF_SIZE                 80U
#define FLS_SECTOR_ADDR              0x00600000U
#define FLS_SECTOR_TEST              C40_CODE_ARRAY_0_BLOCK_1_S256


/*==================================================================================================
*                                      LOCAL CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                      LOCAL VARIABLES
==================================================================================================*/


/*==================================================================================================
*                                      GLOBAL CONSTANTS
==================================================================================================*/
uint8 Txdata[FLS_BUF_SIZE];
uint8 Rxdata[FLS_BUF_SIZE];


/*==================================================================================================
*                                      GLOBAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/
void    Fls_InitBuffers(void);
boolean Fls_VerifyBuffers(void);


/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/
void Fls_InitBuffers(void)
{
    uint32 i;

    for (i = 0U; i < FLS_BUF_SIZE; i++)
    {
        Txdata[i] = (uint8)i;
        Rxdata[i] = 0U;
    }
}

boolean Fls_VerifyBuffers()
{
    uint32 i;

    for (i = 0U; i < FLS_BUF_SIZE; i++)
    {
        if (Rxdata[i] != Txdata[i])
        {
            return FALSE;
        }
    }
    return TRUE;
}


/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/
/**
* @brief        Main function of the example
* @details      Initializes IP C40 driver and erase, write, read internal flash memory
*/
int main(void)
{
    boolean exampleStatus = TRUE;
    C40_Ip_StatusType c40Status;
    Clock_Ip_StatusType clockStatus;

    /* Initialize clock */
    clockStatus = Clock_Ip_Init(&Clock_Ip_aClockConfig[0]);
    if (clockStatus != CLOCK_IP_SUCCESS)
    {
        exampleStatus = FALSE;
    }

    /* Initialize C40 driver */
    C40_Ip_Init(&C40_Ip_InitCfg);

    /* Initialize buffers */
    Fls_InitBuffers();

    /* Unlock sector */
    if (STATUS_C40_IP_SECTOR_PROTECTED == C40_Ip_GetLock(FLS_SECTOR_TEST))
    {
        C40_Ip_ClearLock(FLS_SECTOR_TEST, FLS_MASTER_ID);
    }

    /* Erase sector */
    C40_Ip_MainInterfaceSectorErase(FLS_SECTOR_TEST, FLS_MASTER_ID);
    do
    {
        c40Status = C40_Ip_MainInterfaceSectorEraseStatus();
    }
    while (STATUS_C40_IP_BUSY == c40Status);

    if (STATUS_C40_IP_SUCCESS != c40Status)
    {
        exampleStatus = FALSE;
    }

    /* Write data */
    C40_Ip_MainInterfaceWrite(FLS_SECTOR_ADDR, FLS_BUF_SIZE, Txdata, FLS_MASTER_ID);
    do
    {
        c40Status = C40_Ip_MainInterfaceWriteStatus();
    }
    while (STATUS_C40_IP_BUSY == c40Status);

    if (STATUS_C40_IP_SUCCESS != c40Status)
    {
        exampleStatus = FALSE;
    }

    /* Read data */
    if (STATUS_C40_IP_ERROR == C40_Ip_Read(FLS_SECTOR_ADDR, FLS_BUF_SIZE, Rxdata))
    {
        exampleStatus = FALSE;
    }

    /* Compare data */
    if (STATUS_C40_IP_ERROR == C40_Ip_Compare(FLS_SECTOR_ADDR, FLS_BUF_SIZE, Rxdata))
    {
        exampleStatus = FALSE;
    }

    /* Compare data between Tx and Rx buffer */
    if (! Fls_VerifyBuffers())
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
