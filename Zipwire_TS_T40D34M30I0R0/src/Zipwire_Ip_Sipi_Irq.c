/*==================================================================================================
*   Project              : RTD AUTOSAR 4.7
*   Platform             : CORTEXM
*   Peripheral           : 
*   Dependencies         : none
*
*   Autosar Version      : 4.7.0
*   Autosar Revision     : ASR_REL_4_7_REV_0000
*   Autosar Conf.Variant :
*   SW Version           : 3.0.0
*   Build Version        : S32K3_RTD_3_0_0_D2303_ASR_REL_4_7_REV_0000_20230331
*
*   Copyright 2020 - 2023 NXP Semiconductors
*   
*
*   NXP Confidential. This software is owned or controlled by NXP and may only be
*   used strictly in accordance with the applicable license terms. By expressly
*   accepting such terms or by downloading, installing, activating and/or otherwise
*   using the software, you are agreeing that you have read, and that you agree to
*   comply with and are bound by, such license terms. If you do not agree to be
*   bound by the applicable license terms, then you may not retain, install,
*   activate or otherwise use the software.
==================================================================================================*/

/**
*   @file    Zipwire_Ip_Sipi_Irq.c
*
*   @version 3.0.0
*
*   @brief   AUTOSAR Zipwire - Zipwire Ip driver source file.
*   @details
*
*   @addtogroup ZIPWIRE_IP_DRIVER ZIPWIRE IP Driver
*   @{
*/

/*==================================================================================================
*                                          INCLUDE FILES
*  1) system and project includes
*  2) needed interfaces from external units
*  3) internal and external interfaces from this unit
==================================================================================================*/
#include "Zipwire_Ip_Sipi_Irq.h"
#include "Zipwire_Ip_Cfg.h"

/*==================================================================================================
                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define ZIPWIRE_IP_SIPI_IRQ_VENDOR_ID_C                       43
#define ZIPWIRE_IP_SIPI_IRQ_AR_RELEASE_MAJOR_VERSION_C        4
#define ZIPWIRE_IP_SIPI_IRQ_AR_RELEASE_MINOR_VERSION_C        7
#define ZIPWIRE_IP_SIPI_IRQ_AR_RELEASE_REVISION_VERSION_C     0
#define ZIPWIRE_IP_SIPI_IRQ_SW_MAJOR_VERSION_C                3
#define ZIPWIRE_IP_SIPI_IRQ_SW_MINOR_VERSION_C                0
#define ZIPWIRE_IP_SIPI_IRQ_SW_PATCH_VERSION_C                0

/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/
/* Check if Zipwire_Ip_Sipi_Irq.c file and Zipwire_Ip_Cfg.h file are of the same vendor */
#if (ZIPWIRE_IP_SIPI_IRQ_VENDOR_ID_C != ZIPWIRE_IP_CFG_VENDOR_ID)
    #error "Zipwire_Ip_Sipi_Irq.c and Zipwire_Ip_Cfg.h have different vendor ids"
#endif

/* Check if Zipwire_Ip_Sipi_Irq.c file and Zipwire_Ip_Cfg.h file are of the same Autosar version */
#if ((ZIPWIRE_IP_SIPI_IRQ_AR_RELEASE_MAJOR_VERSION_C != ZIPWIRE_IP_CFG_AR_RELEASE_MAJOR_VERSION) || \
     (ZIPWIRE_IP_SIPI_IRQ_AR_RELEASE_MINOR_VERSION_C != ZIPWIRE_IP_CFG_AR_RELEASE_MINOR_VERSION) || \
     (ZIPWIRE_IP_SIPI_IRQ_AR_RELEASE_REVISION_VERSION_C != ZIPWIRE_IP_CFG_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Zipwire_Ip_Sipi_Irq.c and Zipwire_Ip_Cfg.h are different"
#endif

/* Check if Zipwire_Ip_Sipi_Irq.c file and Zipwire_Ip_Cfg.h file are of the same Software version */
#if ((ZIPWIRE_IP_SIPI_IRQ_SW_MAJOR_VERSION_C != ZIPWIRE_IP_CFG_SW_MAJOR_VERSION) || \
     (ZIPWIRE_IP_SIPI_IRQ_SW_MINOR_VERSION_C != ZIPWIRE_IP_CFG_SW_MINOR_VERSION) || \
     (ZIPWIRE_IP_SIPI_IRQ_SW_PATCH_VERSION_C != ZIPWIRE_IP_CFG_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Zipwire_Ip_Sipi_Irq.c and Zipwire_Ip_Cfg.h are different"
#endif

/* Check if Zipwire_Ip_Sipi_Irq.c file and Zipwire_Ip_Sipi_Irq.h file are of the same vendor */
#if (ZIPWIRE_IP_SIPI_IRQ_VENDOR_ID_C != ZIPWIRE_IP_SIPI_IRQ_VENDOR_ID)
    #error "Zipwire_Ip_Sipi_Irq.c and Zipwire_Ip_Sipi_Irq.h have different vendor ids"
#endif

/* Check if Zipwire_Ip_Sipi_Irq.c file and Zipwire_Ip_Sipi_Irq.h file are of the same Autosar version */
#if ((ZIPWIRE_IP_SIPI_IRQ_AR_RELEASE_MAJOR_VERSION_C != ZIPWIRE_IP_SIPI_IRQ_AR_RELEASE_MAJOR_VERSION) || \
     (ZIPWIRE_IP_SIPI_IRQ_AR_RELEASE_MINOR_VERSION_C != ZIPWIRE_IP_SIPI_IRQ_AR_RELEASE_MINOR_VERSION) || \
     (ZIPWIRE_IP_SIPI_IRQ_AR_RELEASE_REVISION_VERSION_C != ZIPWIRE_IP_SIPI_IRQ_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Zipwire_Ip_Sipi_Irq.c and Zipwire_Ip_Sipi_Irq.h are different"
#endif

/* Check if Zipwire_Ip_Sipi_Irq.c file and Zipwire_Ip_Sipi_Irq.h file are of the same Software version */
#if ((ZIPWIRE_IP_SIPI_IRQ_SW_MAJOR_VERSION_C != ZIPWIRE_IP_SIPI_IRQ_SW_MAJOR_VERSION) || \
     (ZIPWIRE_IP_SIPI_IRQ_SW_MINOR_VERSION_C != ZIPWIRE_IP_SIPI_IRQ_SW_MINOR_VERSION) || \
     (ZIPWIRE_IP_SIPI_IRQ_SW_PATCH_VERSION_C != ZIPWIRE_IP_SIPI_IRQ_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Zipwire_Ip_Sipi_Irq.c and Zipwire_Ip_Sipi_Irq.h are different"
#endif

/*==================================================================================================
 *                                       FUNCTION PROTOYPES
==================================================================================================*/


/*==================================================================================================
 *                                            FUNCTION
==================================================================================================*/
#define ZIPWIRE_START_SEC_CODE
#include "Zipwire_MemMap.h"

/* INSTANCE 0 IRQ */
#if (STD_ON == ZIPWIRE_IP_INSTANCE_0_DEFINED)
#if (STD_ON == ZIPWIRE_IP_ORED_IRQ_LINES)
/* SIPI irq handler */
void Zipwire_Ip_Sipi0_IRQHandler()
{
    uint32 SipiRarAckrMask = SIPI1_CSR0_RAR_MASK | SIPI1_CSR0_ACKR_MASK;

    /**** CHANNELS READ/ACK INTERRUPTS ****/
    /* Check channel 0 */
    if ((IP_SIPI_0->CSR0 & SipiRarAckrMask) > 0U)
    {
        Zipwire_Ip_Sipi0_Ch0ResponseOrAckIrqHandler();
    }
    /* Check channel 1 */
    if ((IP_SIPI_0->CSR1 & SipiRarAckrMask) > 0U)
    {
        Zipwire_Ip_Sipi0_Ch1ResponseOrAckIrqHandler();
    }
    /* Check channel 2 */
    if ((IP_SIPI_0->CSR2 & SipiRarAckrMask) > 0U)
    {
        Zipwire_Ip_Sipi0_Ch2ResponseOrAckIrqHandler();
    }
    /* Check channel 3 */
    if ((IP_SIPI_0->CSR3 & SipiRarAckrMask) > 0U)
    {
        Zipwire_Ip_Sipi0_Ch3ResponseOrAckIrqHandler();
    }

    /**** CHANNELS ERROR INTERRUPTS ****/
    if (IP_SIPI_0->ERR > 0U)
    {
        Zipwire_Ip_Sipi0_ErrorIrqHandler();
    }

    /**** GLOBAL CRC ERROR INTERRUPT ****/
    if (hwAccZipwireSipi_IsCrcErrIntEnabled(IP_SIPI_0))
    {
        if ((IP_SIPI_0->SR & SIPI1_SR_GCRCE_MASK) > 0U)
        {
            hwAccZipwireSipi_ClearGlobalCrcErrFlag(IP_SIPI_0);
            Zipwire_Ip_Sipi_CrcErrHandler(0U);
        }
    }

    /**** TRIGGER OR MAX COUNT REACHED INTERRUPT ****/
    Zipwire_Ip_Sipi0_TriggerOrMaxCountReachedIrqHandler();
}
#endif /* #if (STD_ON == ZIPWIRE_IP_ORED_IRQ_LINES) */

/* SIPI channel error irq handler */
void Zipwire_Ip_Sipi0_ErrorIrqHandler()
{
    /* Check channel 0 */
    if ((IP_SIPI_0->ERR & ZIPWIRE_IP_SIPI_CH0_ERR_MASK) > 0U)
    {
        /* Timeout error channel 0 */
        if (hwAccZipwireSipi_IsChannelInterruptEnabled(IP_SIPI0_CHANNEL_0, SIPI_TIMEOUT_IRQ))
        {
            if (hwAccZipwireSipi_GetChnTimeoutErrFlag(IP_SIPI_0, 0U))
            {
                hwAccZipwireSipi_ClearChnTimeoutErrFlag(IP_SIPI_0, 0U);
                Zipwire_Ip_Sipi_ChnTimeoutErrHandler(0U, 0U);
                return;
            }
        }
        /* Transaction ID error channel 0 */
        if (hwAccZipwireSipi_IsChannelInterruptEnabled(IP_SIPI0_CHANNEL_0, SIPI_TRANS_ID_ERR_IRQ))
        {
            if (hwAccZipwireSipi_GetChnTransactionIdErrFlag(IP_SIPI_0, 0U))
            {
                hwAccZipwireSipi_ClearChnTransactionIdErrFlag(IP_SIPI_0, 0U);
                Zipwire_Ip_Sipi_ChnTransIdErrHandler(0U, 0U);
                return;
            }
        }
        /* ACK error channel 0 */
        if (hwAccZipwireSipi_IsChannelInterruptEnabled(IP_SIPI0_CHANNEL_0, SIPI_ACK_ERR_IRQ))
        {
            if (hwAccZipwireSipi_GetChnAckErrFlag(IP_SIPI_0, 0U))
            {
                hwAccZipwireSipi_ClearChnAckErrFlag(IP_SIPI_0, 0U);
                Zipwire_Ip_Sipi_ChnAckErrHandler(0U, 0U);
                return;
            }
        }
    }

    /* Check channel 1 */
    if ((IP_SIPI_0->ERR & ZIPWIRE_IP_SIPI_CH1_ERR_MASK) > 0U)
    {
        /* Timeout error channel 1 */
        if (hwAccZipwireSipi_IsChannelInterruptEnabled(IP_SIPI0_CHANNEL_1, SIPI_TIMEOUT_IRQ))
        {
            if (hwAccZipwireSipi_GetChnTimeoutErrFlag(IP_SIPI_0, 1U))
            {
                hwAccZipwireSipi_ClearChnTimeoutErrFlag(IP_SIPI_0, 1U);
                Zipwire_Ip_Sipi_ChnTimeoutErrHandler(0U, 1U);
                return;
            }
        }
        /* Transaction ID error channel 1 */
        if (hwAccZipwireSipi_IsChannelInterruptEnabled(IP_SIPI0_CHANNEL_1, SIPI_TRANS_ID_ERR_IRQ))
        {
            if (hwAccZipwireSipi_GetChnTransactionIdErrFlag(IP_SIPI_0, 1U))
            {
                hwAccZipwireSipi_ClearChnTransactionIdErrFlag(IP_SIPI_0, 1U);
                Zipwire_Ip_Sipi_ChnTransIdErrHandler(0U, 1U);
                return;
            }
        }
        /* ACK error channel 1 */
        if (hwAccZipwireSipi_IsChannelInterruptEnabled(IP_SIPI0_CHANNEL_1, SIPI_ACK_ERR_IRQ))
        {
            if (hwAccZipwireSipi_GetChnAckErrFlag(IP_SIPI_0, 1U))
            {
                hwAccZipwireSipi_ClearChnAckErrFlag(IP_SIPI_0, 1U);
                Zipwire_Ip_Sipi_ChnAckErrHandler(0U, 1U);
                return;
            }
        }
    }

    /* Check channel 2 */
    if ((IP_SIPI_0->ERR & ZIPWIRE_IP_SIPI_CH2_ERR_MASK) > 0U)
    {
        /* Timeout error channel 2 */
        if (hwAccZipwireSipi_IsChannelInterruptEnabled(IP_SIPI0_CHANNEL_2, SIPI_TIMEOUT_IRQ))
        {
            if (hwAccZipwireSipi_GetChnTimeoutErrFlag(IP_SIPI_0, 2U))
            {
                hwAccZipwireSipi_ClearChnTimeoutErrFlag(IP_SIPI_0, 2U);
                Zipwire_Ip_Sipi_ChnTimeoutErrHandler(0U, 2U);
                return;
            }
        }
        /* Transaction ID error channel 2 */
        if (hwAccZipwireSipi_IsChannelInterruptEnabled(IP_SIPI0_CHANNEL_2, SIPI_TRANS_ID_ERR_IRQ))
        {
            if (hwAccZipwireSipi_GetChnTransactionIdErrFlag(IP_SIPI_0, 2U))
            {
                hwAccZipwireSipi_ClearChnTransactionIdErrFlag(IP_SIPI_0, 2U);
                Zipwire_Ip_Sipi_ChnTransIdErrHandler(0U, 2U);
                return;
            }
        }
        /* ACK error channel 2 */
        if (hwAccZipwireSipi_IsChannelInterruptEnabled(IP_SIPI0_CHANNEL_2, SIPI_ACK_ERR_IRQ))
        {
            if (hwAccZipwireSipi_GetChnAckErrFlag(IP_SIPI_0, 2U))
            {
                hwAccZipwireSipi_ClearChnAckErrFlag(IP_SIPI_0, 2U);
                Zipwire_Ip_Sipi_ChnAckErrHandler(0U, 2U);
                return;
            }
        }
    }

    /* Check channel 3 */
    if ((IP_SIPI_0->ERR & ZIPWIRE_IP_SIPI_CH3_ERR_MASK) > 0U)
    {
        /* Timeout error channel 3 */
        if (hwAccZipwireSipi_IsChannelInterruptEnabled(IP_SIPI0_CHANNEL_3, SIPI_TIMEOUT_IRQ))
        {
            if (hwAccZipwireSipi_GetChnTimeoutErrFlag(IP_SIPI_0, 3U))
            {
                hwAccZipwireSipi_ClearChnTimeoutErrFlag(IP_SIPI_0, 3U);
                Zipwire_Ip_Sipi_ChnTimeoutErrHandler(0U, 3U);
                return;
            }
        }
        /* Transaction ID error channel 3 */
        if (hwAccZipwireSipi_IsChannelInterruptEnabled(IP_SIPI0_CHANNEL_3, SIPI_TRANS_ID_ERR_IRQ))
        {
            if (hwAccZipwireSipi_GetChnTransactionIdErrFlag(IP_SIPI_0, 3U))
            {
                hwAccZipwireSipi_ClearChnTransactionIdErrFlag(IP_SIPI_0, 3U);
                Zipwire_Ip_Sipi_ChnTransIdErrHandler(0U, 3U);
                return;
            }
        }
        /* ACK error channel 3 */
        if (hwAccZipwireSipi_IsChannelInterruptEnabled(IP_SIPI0_CHANNEL_3, SIPI_ACK_ERR_IRQ))
        {
            if (hwAccZipwireSipi_GetChnAckErrFlag(IP_SIPI_0, 3U))
            {
                hwAccZipwireSipi_ClearChnAckErrFlag(IP_SIPI_0, 3U);
                Zipwire_Ip_Sipi_ChnAckErrHandler(0U, 3U);
                return;
            }
        }
    }
}

/* SIPI crc error irq handler */
void Zipwire_Ip_Sipi0_CrcErrorIrqHandler()
{
    hwAccZipwireSipi_ClearGlobalCrcErrFlag(IP_SIPI_0);
    Zipwire_Ip_Sipi_CrcErrHandler(0U);
}

/* SIPI channel 0 response or ack irq handler */
void Zipwire_Ip_Sipi0_Ch0ResponseOrAckIrqHandler()
{
    /* Check channel 0 read answer received */
    if (hwAccZipwireSipi_IsChannelInterruptEnabled(IP_SIPI0_CHANNEL_0, SIPI_READ_ANSWER_IRQ))
    {
        if (hwAccZipwireSipi_GetChannelFlag(IP_SIPI0_CHANNEL_0, SIPI_READ_ANSWER_FLAG))
        {
            hwAccZipwireSipi_ClearChannelFlag(IP_SIPI0_CHANNEL_0, SIPI_READ_ANSWER_FLAG);
            Zipwire_Ip_Sipi_ChnReadAnswerHandler(0U, 0U);
            return;
        }
    }

    /* Check channel 0 ack */
    if (hwAccZipwireSipi_IsChannelInterruptEnabled(IP_SIPI0_CHANNEL_0, SIPI_ACK_IRQ))
    {
        if (hwAccZipwireSipi_GetChannelFlag(IP_SIPI0_CHANNEL_0, SIPI_ACK_FLAG))
        {
            hwAccZipwireSipi_ClearChannelFlag(IP_SIPI0_CHANNEL_0, SIPI_ACK_FLAG);
            Zipwire_Ip_Sipi_ChnAckHandler(0U, 0U);
            return;
        }
    }
}

/* SIPI channel 1 response or ack irq handler */
void Zipwire_Ip_Sipi0_Ch1ResponseOrAckIrqHandler()
{
    /* Check channel 1 read answer received */
    if (hwAccZipwireSipi_IsChannelInterruptEnabled(IP_SIPI0_CHANNEL_1, SIPI_READ_ANSWER_IRQ))
    {
        if (hwAccZipwireSipi_GetChannelFlag(IP_SIPI0_CHANNEL_1, SIPI_READ_ANSWER_FLAG))
        {
            hwAccZipwireSipi_ClearChannelFlag(IP_SIPI0_CHANNEL_1, SIPI_READ_ANSWER_FLAG);
            Zipwire_Ip_Sipi_ChnReadAnswerHandler(0U, 1U);
            return;
        }
    }

    /* Check channel 1 ack */
    if (hwAccZipwireSipi_IsChannelInterruptEnabled(IP_SIPI0_CHANNEL_1, SIPI_ACK_IRQ))
    {
        if (hwAccZipwireSipi_GetChannelFlag(IP_SIPI0_CHANNEL_1, SIPI_ACK_FLAG))
        {
            hwAccZipwireSipi_ClearChannelFlag(IP_SIPI0_CHANNEL_1, SIPI_ACK_FLAG);
            Zipwire_Ip_Sipi_ChnAckHandler(0U, 1U);
            return;
        }
    }
}

/* SIPI channel 2 response or ack irq handler */
void Zipwire_Ip_Sipi0_Ch2ResponseOrAckIrqHandler()
{
    /* Check channel 2 read answer received */
    if (hwAccZipwireSipi_IsChannelInterruptEnabled(IP_SIPI0_CHANNEL_2, SIPI_READ_ANSWER_IRQ))
    {
        if (hwAccZipwireSipi_GetChannelFlag(IP_SIPI0_CHANNEL_2, SIPI_READ_ANSWER_FLAG))
        {
            hwAccZipwireSipi_ClearChannelFlag(IP_SIPI0_CHANNEL_2, SIPI_READ_ANSWER_FLAG);
            Zipwire_Ip_Sipi_ChnReadAnswerHandler(0U, 2U);
            return;
        }
    }

    /* Check channel 2 ack */
    if (hwAccZipwireSipi_IsChannelInterruptEnabled(IP_SIPI0_CHANNEL_2, SIPI_ACK_IRQ))
    {
        if (hwAccZipwireSipi_GetChannelFlag(IP_SIPI0_CHANNEL_2, SIPI_ACK_FLAG))
        {
            hwAccZipwireSipi_ClearChannelFlag(IP_SIPI0_CHANNEL_2, SIPI_ACK_FLAG);
            Zipwire_Ip_Sipi_ChnAckHandler(0U, 2U);
            return;
        }
    }
}

/* SIPI channel 3 response or ack irq handler */
void Zipwire_Ip_Sipi0_Ch3ResponseOrAckIrqHandler()
{
    /* Check channel 3 read answer received */
    if (hwAccZipwireSipi_IsChannelInterruptEnabled(IP_SIPI0_CHANNEL_3, SIPI_READ_ANSWER_IRQ))
    {
        if (hwAccZipwireSipi_GetChannelFlag(IP_SIPI0_CHANNEL_3, SIPI_READ_ANSWER_FLAG))
        {
            hwAccZipwireSipi_ClearChannelFlag(IP_SIPI0_CHANNEL_3, SIPI_READ_ANSWER_FLAG);
            Zipwire_Ip_Sipi_ChnReadAnswerHandler(0U, 3U);
            return;
        }
    }

    /* Check channel 3 ack */
    if (hwAccZipwireSipi_IsChannelInterruptEnabled(IP_SIPI0_CHANNEL_3, SIPI_ACK_IRQ))
    {
        if (hwAccZipwireSipi_GetChannelFlag(IP_SIPI0_CHANNEL_3, SIPI_ACK_FLAG))
        {
            hwAccZipwireSipi_ClearChannelFlag(IP_SIPI0_CHANNEL_3, SIPI_ACK_FLAG);
            Zipwire_Ip_Sipi_ChnAckHandler(0U, 3U);
            return;
        }
    }
}

/* SIPI trigger or max count reached irq handler */
void Zipwire_Ip_Sipi0_TriggerOrMaxCountReachedIrqHandler()
{
    /* Max count reached */
    if (hwAccZipwireSipi_IsMaxCountReachedIntEnabled(IP_SIPI_0))
    {
        if (hwAccZipwireSipi_GetMaxCountReachedFlag(IP_SIPI_0))
        {
            hwAccZipwireSipi_ClearMaxCountReachedFlag(IP_SIPI_0);
            Zipwire_Ip_Sipi_MaxCountReachedHandler(0U);
            return;
        }
    }

    /* Trigger channel 0 */
    if (hwAccZipwireSipi_IsChannelInterruptEnabled(IP_SIPI0_CHANNEL_0, SIPI_TRIGGER_IRQ))
    {
        if (hwAccZipwireSipi_GetChnTriggerEventFlag(IP_SIPI_0, 0U))
        {
            hwAccZipwireSipi_ClearChnTriggerEventFlag(IP_SIPI_0, 0U);
            Zipwire_Ip_Sipi_ChnTriggerHandler(0U, 0U);
            return;
        }
    }

    /* Trigger channel 1 */
    if (hwAccZipwireSipi_IsChannelInterruptEnabled(IP_SIPI0_CHANNEL_1, SIPI_TRIGGER_IRQ))
    {
        if (hwAccZipwireSipi_GetChnTriggerEventFlag(IP_SIPI_0, 1U))
        {
            hwAccZipwireSipi_ClearChnTriggerEventFlag(IP_SIPI_0, 1U);
            Zipwire_Ip_Sipi_ChnTriggerHandler(0U, 1U);
            return;
        }
    }

    /* Trigger channel 2 */
    if (hwAccZipwireSipi_IsChannelInterruptEnabled(IP_SIPI0_CHANNEL_2, SIPI_TRIGGER_IRQ))
    {
        if (hwAccZipwireSipi_GetChnTriggerEventFlag(IP_SIPI_0, 2U))
        {
            hwAccZipwireSipi_ClearChnTriggerEventFlag(IP_SIPI_0, 2U);
            Zipwire_Ip_Sipi_ChnTriggerHandler(0U, 2U);
            return;
        }
    }

    /* Trigger channel 3 */
    if (hwAccZipwireSipi_IsChannelInterruptEnabled(IP_SIPI0_CHANNEL_3, SIPI_TRIGGER_IRQ))
    {
        if (hwAccZipwireSipi_GetChnTriggerEventFlag(IP_SIPI_0, 3U))
        {
            hwAccZipwireSipi_ClearChnTriggerEventFlag(IP_SIPI_0, 3U);
            Zipwire_Ip_Sipi_ChnTriggerHandler(0U, 3U);
            return;
        }
    }
}
#endif /* #if (STD_ON == ZIPWIRE_IP_INSTANCE_0_DEFINED) */

/* INSTANCE 1 IRQ */
#if (STD_ON == ZIPWIRE_IP_INSTANCE_1_DEFINED)
#if (STD_ON == ZIPWIRE_IP_ORED_IRQ_LINES)
/* SIPI irq handler */
void Zipwire_Ip_Sipi1_IRQHandler()
{
    uint32 SipiRarAckrMask = SIPI1_CSR0_RAR_MASK | SIPI1_CSR0_ACKR_MASK;

    /**** CHANNELS READ/ACK INTERRUPTS ****/
    /* Check channel 0 */
    if ((IP_SIPI1_1->CSR0 & SipiRarAckrMask) > 0U)
    {
        Zipwire_Ip_Sipi1_Ch0ResponseOrAckIrqHandler();
    }
    /* Check channel 1 */
    if ((IP_SIPI1_1->CSR1 & SipiRarAckrMask) > 0U)
    {
        Zipwire_Ip_Sipi1_Ch1ResponseOrAckIrqHandler();
    }
    /* Check channel 2 */
    if ((IP_SIPI1_1->CSR2 & SipiRarAckrMask) > 0U)
    {
        Zipwire_Ip_Sipi1_Ch2ResponseOrAckIrqHandler();
    }
    /* Check channel 3 */
    if ((IP_SIPI1_1->CSR3 & SipiRarAckrMask) > 0U)
    {
        Zipwire_Ip_Sipi1_Ch3ResponseOrAckIrqHandler();
    }

    /**** CHANNELS ERROR INTERRUPTS ****/
    if (IP_SIPI1_1->ERR > 0U)
    {
        Zipwire_Ip_Sipi1_ErrorIrqHandler();
    }

    /**** GLOBAL CRC ERROR INTERRUPT ****/
    if (hwAccZipwireSipi_IsCrcErrIntEnabled(IP_SIPI1_1))
    {
        if ((IP_SIPI1_1->SR & SIPI1_SR_GCRCE_MASK) > 0U)
        {
            hwAccZipwireSipi_ClearGlobalCrcErrFlag(IP_SIPI1_1);
            Zipwire_Ip_Sipi_CrcErrHandler(1U);
        }
    }

    /**** TRIGGER OR MAX COUNT REACHED INTERRUPT ****/
    Zipwire_Ip_Sipi1_TriggerOrMaxCountReachedIrqHandler();
}
#endif /* #if (STD_ON == ZIPWIRE_IP_ORED_IRQ_LINES) */

/* SIPI channel error irq handler */
void Zipwire_Ip_Sipi1_ErrorIrqHandler()
{
    /* Check channel 0 */
    if ((IP_SIPI1_1->ERR & ZIPWIRE_IP_SIPI_CH0_ERR_MASK) > 0U)
    {
        /* Timeout error channel 0 */
        if (hwAccZipwireSipi_IsChannelInterruptEnabled(IP_SIPI1_CHANNEL_0, SIPI_TIMEOUT_IRQ))
        {
            if (hwAccZipwireSipi_GetChnTimeoutErrFlag(IP_SIPI1_1, 0U))
            {
                hwAccZipwireSipi_ClearChnTimeoutErrFlag(IP_SIPI1_1, 0U);
                Zipwire_Ip_Sipi_ChnTimeoutErrHandler(1U, 0U);
                return;
            }
        }
        /* Transaction ID error channel 0 */
        if (hwAccZipwireSipi_IsChannelInterruptEnabled(IP_SIPI1_CHANNEL_0, SIPI_TRANS_ID_ERR_IRQ))
        {
            if (hwAccZipwireSipi_GetChnTransactionIdErrFlag(IP_SIPI1_1, 0U))
            {
                hwAccZipwireSipi_ClearChnTransactionIdErrFlag(IP_SIPI1_1, 0U);
                Zipwire_Ip_Sipi_ChnTransIdErrHandler(1U, 0U);
                return;
            }
        }
        /* ACK error channel 0 */
        if (hwAccZipwireSipi_IsChannelInterruptEnabled(IP_SIPI1_CHANNEL_0, SIPI_ACK_ERR_IRQ))
        {
            if (hwAccZipwireSipi_GetChnAckErrFlag(IP_SIPI1_1, 0U))
            {
                hwAccZipwireSipi_ClearChnAckErrFlag(IP_SIPI1_1, 0U);
                Zipwire_Ip_Sipi_ChnAckErrHandler(1U, 0U);
                return;
            }
        }
    }

    /* Check channel 1 */
    if ((IP_SIPI1_1->ERR & ZIPWIRE_IP_SIPI_CH1_ERR_MASK) > 0U)
    {
        /* Timeout error channel 1 */
        if (hwAccZipwireSipi_IsChannelInterruptEnabled(IP_SIPI1_CHANNEL_1, SIPI_TIMEOUT_IRQ))
        {
            if (hwAccZipwireSipi_GetChnTimeoutErrFlag(IP_SIPI1_1, 1U))
            {
                hwAccZipwireSipi_ClearChnTimeoutErrFlag(IP_SIPI1_1, 1U);
                Zipwire_Ip_Sipi_ChnTimeoutErrHandler(1U, 1U);
                return;
            }
        }
        /* Transaction ID error channel 1 */
        if (hwAccZipwireSipi_IsChannelInterruptEnabled(IP_SIPI1_CHANNEL_1, SIPI_TRANS_ID_ERR_IRQ))
        {
            if (hwAccZipwireSipi_GetChnTransactionIdErrFlag(IP_SIPI1_1, 1U))
            {
                hwAccZipwireSipi_ClearChnTransactionIdErrFlag(IP_SIPI1_1, 1U);
                Zipwire_Ip_Sipi_ChnTransIdErrHandler(1U, 1U);
                return;
            }
        }
        /* ACK error channel 1 */
        if (hwAccZipwireSipi_IsChannelInterruptEnabled(IP_SIPI1_CHANNEL_1, SIPI_ACK_ERR_IRQ))
        {
            if (hwAccZipwireSipi_GetChnAckErrFlag(IP_SIPI1_1, 1U))
            {
                hwAccZipwireSipi_ClearChnAckErrFlag(IP_SIPI1_1, 1U);
                Zipwire_Ip_Sipi_ChnAckErrHandler(1U, 1U);
                return;
            }
        }
    }

    /* Check channel 2 */
    if ((IP_SIPI1_1->ERR & ZIPWIRE_IP_SIPI_CH2_ERR_MASK) > 0U)
    {
        /* Timeout error channel 2 */
        if (hwAccZipwireSipi_IsChannelInterruptEnabled(IP_SIPI1_CHANNEL_2, SIPI_TIMEOUT_IRQ))
        {
            if (hwAccZipwireSipi_GetChnTimeoutErrFlag(IP_SIPI1_1, 2U))
            {
                hwAccZipwireSipi_ClearChnTimeoutErrFlag(IP_SIPI1_1, 2U);
                Zipwire_Ip_Sipi_ChnTimeoutErrHandler(1U, 2U);
                return;
            }
        }
        /* Transaction ID error channel 2 */
        if (hwAccZipwireSipi_IsChannelInterruptEnabled(IP_SIPI1_CHANNEL_2, SIPI_TRANS_ID_ERR_IRQ))
        {
            if (hwAccZipwireSipi_GetChnTransactionIdErrFlag(IP_SIPI1_1, 2U))
            {
                hwAccZipwireSipi_ClearChnTransactionIdErrFlag(IP_SIPI1_1, 2U);
                Zipwire_Ip_Sipi_ChnTransIdErrHandler(1U, 2U);
                return;
            }
        }
        /* ACK error channel 2 */
        if (hwAccZipwireSipi_IsChannelInterruptEnabled(IP_SIPI1_CHANNEL_2, SIPI_ACK_ERR_IRQ))
        {
            if (hwAccZipwireSipi_GetChnAckErrFlag(IP_SIPI1_1, 2U))
            {
                hwAccZipwireSipi_ClearChnAckErrFlag(IP_SIPI1_1, 2U);
                Zipwire_Ip_Sipi_ChnAckErrHandler(1U, 2U);
                return;
            }
        }
    }

    /* Check channel 3 */
    if ((IP_SIPI1_1->ERR & ZIPWIRE_IP_SIPI_CH3_ERR_MASK) > 0U)
    {
        /* Timeout error channel 3 */
        if (hwAccZipwireSipi_IsChannelInterruptEnabled(IP_SIPI1_CHANNEL_3, SIPI_TIMEOUT_IRQ))
        {
            if (hwAccZipwireSipi_GetChnTimeoutErrFlag(IP_SIPI1_1, 3U))
            {
                hwAccZipwireSipi_ClearChnTimeoutErrFlag(IP_SIPI1_1, 3U);
                Zipwire_Ip_Sipi_ChnTimeoutErrHandler(1U, 3U);
                return;
            }
        }
        /* Transaction ID error channel 3 */
        if (hwAccZipwireSipi_IsChannelInterruptEnabled(IP_SIPI1_CHANNEL_3, SIPI_TRANS_ID_ERR_IRQ))
        {
            if (hwAccZipwireSipi_GetChnTransactionIdErrFlag(IP_SIPI1_1, 3U))
            {
                hwAccZipwireSipi_ClearChnTransactionIdErrFlag(IP_SIPI1_1, 3U);
                Zipwire_Ip_Sipi_ChnTransIdErrHandler(1U, 3U);
                return;
            }
        }
        /* ACK error channel 3 */
        if (hwAccZipwireSipi_IsChannelInterruptEnabled(IP_SIPI1_CHANNEL_3, SIPI_ACK_ERR_IRQ))
        {
            if (hwAccZipwireSipi_GetChnAckErrFlag(IP_SIPI1_1, 3U))
            {
                hwAccZipwireSipi_ClearChnAckErrFlag(IP_SIPI1_1, 3U);
                Zipwire_Ip_Sipi_ChnAckErrHandler(1U, 3U);
                return;
            }
        }
    }
}

/* SIPI crc error irq handler */
void Zipwire_Ip_Sipi1_CrcErrorIrqHandler()
{
    hwAccZipwireSipi_ClearGlobalCrcErrFlag(IP_SIPI1_1);
    Zipwire_Ip_Sipi_CrcErrHandler(1U);
}

/* SIPI channel 0 response or ack irq handler */
void Zipwire_Ip_Sipi1_Ch0ResponseOrAckIrqHandler()
{
    /* Check channel 0 read answer received */
    if (hwAccZipwireSipi_IsChannelInterruptEnabled(IP_SIPI1_CHANNEL_0, SIPI_READ_ANSWER_IRQ))
    {
        if (hwAccZipwireSipi_GetChannelFlag(IP_SIPI1_CHANNEL_0, SIPI_READ_ANSWER_FLAG))
        {
            hwAccZipwireSipi_ClearChannelFlag(IP_SIPI1_CHANNEL_0, SIPI_READ_ANSWER_FLAG);
            Zipwire_Ip_Sipi_ChnReadAnswerHandler(1U, 0U);
            return;
        }
    }

    /* Check channel 0 ack */
    if (hwAccZipwireSipi_IsChannelInterruptEnabled(IP_SIPI1_CHANNEL_0, SIPI_ACK_IRQ))
    {
        if (hwAccZipwireSipi_GetChannelFlag(IP_SIPI1_CHANNEL_0, SIPI_ACK_FLAG))
        {
            hwAccZipwireSipi_ClearChannelFlag(IP_SIPI1_CHANNEL_0, SIPI_ACK_FLAG);
            Zipwire_Ip_Sipi_ChnAckHandler(1U, 0U);
            return;
        }
    }
}

/* SIPI channel 1 response or ack irq handler */
void Zipwire_Ip_Sipi1_Ch1ResponseOrAckIrqHandler()
{
    /* Check channel 1 read answer received */
    if (hwAccZipwireSipi_IsChannelInterruptEnabled(IP_SIPI1_CHANNEL_1, SIPI_READ_ANSWER_IRQ))
    {
        if (hwAccZipwireSipi_GetChannelFlag(IP_SIPI1_CHANNEL_1, SIPI_READ_ANSWER_FLAG))
        {
            hwAccZipwireSipi_ClearChannelFlag(IP_SIPI1_CHANNEL_1, SIPI_READ_ANSWER_FLAG);
            Zipwire_Ip_Sipi_ChnReadAnswerHandler(1U, 1U);
            return;
        }
    }

    /* Check channel 1 ack */
    if (hwAccZipwireSipi_IsChannelInterruptEnabled(IP_SIPI1_CHANNEL_1, SIPI_ACK_IRQ))
    {
        if (hwAccZipwireSipi_GetChannelFlag(IP_SIPI1_CHANNEL_1, SIPI_ACK_FLAG))
        {
            hwAccZipwireSipi_ClearChannelFlag(IP_SIPI1_CHANNEL_1, SIPI_ACK_FLAG);
            Zipwire_Ip_Sipi_ChnAckHandler(1U, 1U);
            return;
        }
    }
}

/* SIPI channel 2 response or ack irq handler */
void Zipwire_Ip_Sipi1_Ch2ResponseOrAckIrqHandler()
{
    /* Check channel 2 read answer received */
    if (hwAccZipwireSipi_IsChannelInterruptEnabled(IP_SIPI1_CHANNEL_2, SIPI_READ_ANSWER_IRQ))
    {
        if (hwAccZipwireSipi_GetChannelFlag(IP_SIPI1_CHANNEL_2, SIPI_READ_ANSWER_FLAG))
        {
            hwAccZipwireSipi_ClearChannelFlag(IP_SIPI1_CHANNEL_2, SIPI_READ_ANSWER_FLAG);
            Zipwire_Ip_Sipi_ChnReadAnswerHandler(1U, 2U);
            return;
        }
    }

    /* Check channel 2 ack */
    if (hwAccZipwireSipi_IsChannelInterruptEnabled(IP_SIPI1_CHANNEL_2, SIPI_ACK_IRQ))
    {
        if (hwAccZipwireSipi_GetChannelFlag(IP_SIPI1_CHANNEL_2, SIPI_ACK_FLAG))
        {
            hwAccZipwireSipi_ClearChannelFlag(IP_SIPI1_CHANNEL_2, SIPI_ACK_FLAG);
            Zipwire_Ip_Sipi_ChnAckHandler(1U, 2U);
            return;
        }
    }
}

/* SIPI channel 3 response or ack irq handler */
void Zipwire_Ip_Sipi1_Ch3ResponseOrAckIrqHandler()
{
    /* Check channel 3 read answer received */
    if (hwAccZipwireSipi_IsChannelInterruptEnabled(IP_SIPI1_CHANNEL_3, SIPI_READ_ANSWER_IRQ))
    {
        if (hwAccZipwireSipi_GetChannelFlag(IP_SIPI1_CHANNEL_3, SIPI_READ_ANSWER_FLAG))
        {
            hwAccZipwireSipi_ClearChannelFlag(IP_SIPI1_CHANNEL_3, SIPI_READ_ANSWER_FLAG);
            Zipwire_Ip_Sipi_ChnReadAnswerHandler(1U, 3U);
            return;
        }
    }

    /* Check channel 3 ack */
    if (hwAccZipwireSipi_IsChannelInterruptEnabled(IP_SIPI1_CHANNEL_3, SIPI_ACK_IRQ))
    {
        if (hwAccZipwireSipi_GetChannelFlag(IP_SIPI1_CHANNEL_3, SIPI_ACK_FLAG))
        {
            hwAccZipwireSipi_ClearChannelFlag(IP_SIPI1_CHANNEL_3, SIPI_ACK_FLAG);
            Zipwire_Ip_Sipi_ChnAckHandler(1U, 3U);
            return;
        }
    }
}

/* SIPI trigger or max count reached irq handler */
void Zipwire_Ip_Sipi1_TriggerOrMaxCountReachedIrqHandler()
{
    /* Max count reached */
    if (hwAccZipwireSipi_IsMaxCountReachedIntEnabled(IP_SIPI1_1))
    {
        if (hwAccZipwireSipi_GetMaxCountReachedFlag(IP_SIPI1_1))
        {
            hwAccZipwireSipi_ClearMaxCountReachedFlag(IP_SIPI1_1);
            Zipwire_Ip_Sipi_MaxCountReachedHandler(1U);
            return;
        }
    }

    /* Trigger channel 0 */
    if (hwAccZipwireSipi_IsChannelInterruptEnabled(IP_SIPI1_CHANNEL_0, SIPI_TRIGGER_IRQ))
    {
        if (hwAccZipwireSipi_GetChnTriggerEventFlag(IP_SIPI1_1, 0U))
        {
            hwAccZipwireSipi_ClearChnTriggerEventFlag(IP_SIPI1_1, 0U);
            Zipwire_Ip_Sipi_ChnTriggerHandler(1U, 0U);
            return;
        }
    }

    /* Trigger channel 1 */
    if (hwAccZipwireSipi_IsChannelInterruptEnabled(IP_SIPI1_CHANNEL_1, SIPI_TRIGGER_IRQ))
    {
        if (hwAccZipwireSipi_GetChnTriggerEventFlag(IP_SIPI1_1, 1U))
        {
            hwAccZipwireSipi_ClearChnTriggerEventFlag(IP_SIPI1_1, 1U);
            Zipwire_Ip_Sipi_ChnTriggerHandler(1U, 1U);
            return;
        }
    }

    /* Trigger channel 2 */
    if (hwAccZipwireSipi_IsChannelInterruptEnabled(IP_SIPI1_CHANNEL_2, SIPI_TRIGGER_IRQ))
    {
        if (hwAccZipwireSipi_GetChnTriggerEventFlag(IP_SIPI1_1, 2U))
        {
            hwAccZipwireSipi_ClearChnTriggerEventFlag(IP_SIPI1_1, 2U);
            Zipwire_Ip_Sipi_ChnTriggerHandler(1U, 2U);
            return;
        }
    }

    /* Trigger channel 3 */
    if (hwAccZipwireSipi_IsChannelInterruptEnabled(IP_SIPI1_CHANNEL_3, SIPI_TRIGGER_IRQ))
    {
        if (hwAccZipwireSipi_GetChnTriggerEventFlag(IP_SIPI1_1, 3U))
        {
            hwAccZipwireSipi_ClearChnTriggerEventFlag(IP_SIPI1_1, 3U);
            Zipwire_Ip_Sipi_ChnTriggerHandler(1U, 3U);
            return;
        }
    }
}
#endif /* #if (STD_ON == ZIPWIRE_IP_INSTANCE_1_DEFINED) */
#define ZIPWIRE_STOP_SEC_CODE
#include "Zipwire_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */
