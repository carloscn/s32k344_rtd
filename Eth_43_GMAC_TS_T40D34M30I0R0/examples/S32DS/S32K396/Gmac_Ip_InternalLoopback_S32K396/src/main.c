/*
*   (c) Copyright M4_SRC_YEAR_ID M4_SRC_COPYRIGHTED_TO
*   All Rights Reserved.
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
#include "Mcal.h"
#include "Gmac_Ip.h"
#include "Siul2_Port_Ip.h"
#include "Clock_Ip.h"
#include "OsIf.h"

#include "check_example.h"
/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/


/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/
#define INST_GMAC_0    (0U)
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
* @brief        Transmit & receive in internal loopback mode
* @details
*/
int main(void)
{
    Gmac_Ip_TxOptionsType TxOptions = {TRUE, GMAC_CRC_AND_PAD_INSERTION, GMAC_CHECKSUM_INSERTION_DISABLE};
    Gmac_Ip_BufferType TxBuffer = {0};
    Gmac_Ip_BufferType RxBuffer = {0};
    Gmac_Ip_TxInfoType TxInfo  = {0};
    Gmac_Ip_RxInfoType RxInfo  = {0};
    Gmac_Ip_StatusType Status;
    uint8 MacAddr[6U] = {0U};
    uint8 i;
    uint8 j = 0U;
    boolean Result = TRUE;

    OsIf_Init(NULL_PTR);
    Siul2_Port_Ip_Init(NUM_OF_CONFIGURED_PINS0, g_pin_mux_InitConfigArr0);
    Clock_Ip_Init(&Clock_Ip_aClockConfig[0U]);

    Gmac_Ip_Init(INST_GMAC_0, &Gmac_0_ConfigPB_BOARD_INITPERIPHERALS);

    /* Setup the frame with the Mac address and size */
    Gmac_Ip_GetMacAddr(INST_GMAC_0, MacAddr);

    /* Request a buffer of at least 64 bytes */
    TxBuffer.Length = 64U;
    if ((GMAC_STATUS_SUCCESS != Gmac_Ip_GetTxBuff(INST_GMAC_0, 0U, &TxBuffer, NULL_PTR)) || (TxBuffer.Length < 64U))
    {
        Result = FALSE;
    }

    for (i = 0U; i < 12U; i++)
    {
        *((uint8 *)(&TxBuffer.Data[0U] + i)) = MacAddr[0 + j];
        if (j < 5U)
        {
            j++;
        }
        else
        {
            j = 0U;
        }
    }

    /* Payload = Frame - (DstAddr + SrcAddr + EtherType/Length + FCS) */
    *((uint32 *)(TxBuffer.Data + 13U)) = 64U - (6U + 6U + 2U + 4U);

    /* Send the ETH frame */
    TxBuffer.Length = 64U - 4U;     /* Don't count FCS, because it is automatically inserted by the controller in this example */
    if (GMAC_STATUS_SUCCESS != Gmac_Ip_SendFrame(INST_GMAC_0, 0U, &TxBuffer, &TxOptions))
    {
        Result = FALSE;
    }

    /* Wait for the frame to be transmitted */
    do {
        Status = Gmac_Ip_GetTransmitStatus(INST_GMAC_0, 0U, &TxBuffer, &TxInfo);
    } while (Status == GMAC_STATUS_BUSY);

    /* Check the frame status */
    if ((GMAC_STATUS_SUCCESS != Status) || (0U != TxInfo.ErrMask))
    {
        Result = FALSE;
    }

    /* Wait for the frame to be received */
    do {
        Status = Gmac_Ip_ReadFrame(INST_GMAC_0, 0U, &RxBuffer, &RxInfo);
    } while (Status == GMAC_STATUS_RX_QUEUE_EMPTY);

    /* Check the frame status */
    if ((GMAC_STATUS_SUCCESS != Status) || (0U != RxInfo.ErrMask))
    {
        Result = FALSE;
    }

    Gmac_Ip_ProvideRxBuff(INST_GMAC_0, 0U, &RxBuffer);

    Gmac_Ip_DisableController(INST_GMAC_0);

    Exit_Example(Result);

    return 0;
}
#ifdef __cplusplus
}
#endif
