/*
*   Copyright M4_SRC_YEAR_ID M4_SRC_COPYRIGHTED_TO NXP.
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
#include "Mcl.h"
#include "Mcu.h"
#include "CDD_Sent.h"
#include "Port.h"
/* #include "Platform.h" */
#include "check_example.h"
/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/


/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/


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
uint8 Sent_RxSlowIndication = 0U;
uint8 Sent_RxFastIndication = 0U;
uint8 Sent_FastErrorIndication = 0U;
uint8 Sent_SlowErrorIndication = 0U;
uint8 Sent_ErrorIndication = 0U;
/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/
uint16 ErrorArray[6] = {0, 0, 0, 0, 0, 0};

/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/


/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/
void SentFastNotification(Flexio_Sent_Ip_StatusType status, Flexio_Sent_FastMsgType *pSent_FastMsg)
{
    Sent_RxFastIndication++;
    if(Sent_RxFastIndication > 200)
    {
        Sent_StopChannelReceiving(0, 0);
    }
    (void)status;
    (void)pSent_FastMsg;
}
void SentSlowNotification(Flexio_Sent_Ip_StatusType status, Flexio_Sent_SerialMsgType *SentSerialMsg)
{
    Sent_RxSlowIndication++;
    (void)status;
    (void)SentSerialMsg;
}
void SentSlowErrorNotification(Flexio_Sent_Ip_ErrorStatusType ErrorEvent)
{
    Sent_SlowErrorIndication++;
    ErrorArray[ErrorEvent]++;
}
void SentFastErrorNotification(Flexio_Sent_Ip_ErrorStatusType ErrorEvent)
{
    Sent_FastErrorIndication++;
    ErrorArray[ErrorEvent]++;
}

int main(void)
{
    boolean ExampleResult = FALSE;

    Mcu_Init(NULL_PTR);
    /* Initialize Mcu Clock */
    Mcu_InitClock(0);
    while (Mcu_GetPllStatus() != MCU_PLL_LOCKED){};
    /* Use PLL clock */
    Mcu_DistributePllClock();
    Mcu_SetMode(0U);

    /* Initialize Port driver */
    Port_Init(NULL_PTR);

    /* Initialize Platform driver */
   /* Platform_Init(NULL_PTR); */

    /* Initialize Mcl driver */
    Mcl_Init(NULL_PTR);
    /* Initialize Sent driver */
    Sent_Init(NULL_PTR);
    Sent_StartChannelReceiving(0U, 0U);
    Sent_GetSerialChannelMsgData(0U, 0U);
    Sent_DeInit();

    if((Sent_RxFastIndication > 0) && (Sent_RxSlowIndication > 0))
    {
        ExampleResult = TRUE;
    }
    Exit_Example(ExampleResult);

    return (0U);
}

#ifdef __cplusplus
}
#endif

/** @} */
