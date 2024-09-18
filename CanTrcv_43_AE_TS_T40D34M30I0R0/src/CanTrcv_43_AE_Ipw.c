/*==================================================================================================
*   Project              : RTD AUTOSAR 4.7
*   Platform             : CORTEXM
*   Peripheral           : AE
*   Dependencies         : 
*
*   Autosar Version      : 4.7.0
*   Autosar Revision     : ASR_REL_4_7_REV_0000
*   Autosar Conf.Variant :
*   SW Version           : 3.0.0
*   Build Version        : S32K3_RTD_3_0_0_D2303_ASR_REL_4_7_REV_0000_20230331
*
*   Copyright 2020 - 2023 NXP Semiconductors
*
*   NXP Confidential. This software is owned or controlled by NXP and may only be
*   used strictly in accordance with the applicable license terms. By expressly
*   accepting such terms or by downloading, installing, activating and/or otherwise
*   using the software, you are agreeing that you have read, and that you agree to
*   comply with and are bound by, such license terms. If you do not agree to be
*   bound by the applicable license terms, then you may not retain, install,
*   activate or otherwise use the software.
==================================================================================================*/
/*==================================================================================================
==================================================================================================*/
/**
* @file         CanTrcv_43_AE_Ipw.c
* @version      3.0.0
*
* @brief        AUTOSAR CanTrcv_43_AE - module interface
* @details      API implementation for CanTrcv driver.
*
*
* @addtogroup   CANTRCV_DRIVER
* @{
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
#include "CanTrcv_43_AE_Ipw.h"
#include "CanTrcv_43_AE.h"
#if (CANTRCV_43_AE_ICU_USED == STD_ON)
    #include "Icu.h"
#endif
#if (CANTRCV_43_AE_ECUM_USED == STD_ON)
#include "EcuM.h"
#endif
#include "AeCanPHY_Ip.h"
#include "Det.h"
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define CANTRCV_43_AE_IPW_VENDOR_ID_C                      43
#define CANTRCV_43_AE_IPW_MODULE_ID_C                      70
#define CANTRCV_43_AE_IPW_AR_RELEASE_MAJOR_VERSION_C       4
#define CANTRCV_43_AE_IPW_AR_RELEASE_MINOR_VERSION_C       7
#define CANTRCV_43_AE_IPW_AR_RELEASE_REVISION_VERSION_C    0
#define CANTRCV_43_AE_IPW_SW_MAJOR_VERSION_C               3
#define CANTRCV_43_AE_IPW_SW_MINOR_VERSION_C               0
#define CANTRCV_43_AE_IPW_SW_PATCH_VERSION_C               0
/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/

/*==================================================================================================
                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/

/*==================================================================================================
                                       LOCAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
                                       LOCAL VARIABLES
==================================================================================================*/

/*==================================================================================================
                                       GLOBAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
                                       GLOBAL VARIABLES
==================================================================================================*/

/*==================================================================================================
                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/
#define CANTRCV_43_AE_START_SEC_CODE
#include "CanTrcv_43_AE_MemMap.h"

/* Local function to report det_runtime error about a Spi miscommunication */
static void CanTrcv_Ipw_ReportSpiMiscommunication(AeCanPHY_Ip_StatusType DeviceStatus, uint8 Sid);
/*==================================================================================================
                                       LOCAL FUNCTIONS
==================================================================================================*/
static void CanTrcv_Ipw_ReportSpiMiscommunication(AeCanPHY_Ip_StatusType DeviceStatus, uint8 Sid)
{
    if (AE_CANPHY_STATUS_ERR_SPI == DeviceStatus)
    {
        (void)Det_ReportRuntimeError((uint16)CANTRCV_43_AE_IPW_MODULE_ID,
                                     (uint8)CANTRCV_43_AE_INSTANCE,
                                     (uint8)Sid,
                                     (uint8)CANTRCV_43_AE_E_NO_TRCV_CONTROL);
    }
}
/*==================================================================================================
                                       GLOBAL FUNCTIONS
==================================================================================================*/

/*================================================================================================*/
/* Ipw_Init */
Std_ReturnType CanTrcv_43_AE_Ipw_Init(const CanTrcv_43_AE_TransceiverConfigType * TransceiverConfig)
{
    AeCanPHY_Ip_StatusType Retval = AE_CANPHY_STATUS_SUCCESS;
#if ((CANTRCV_43_AEWAKEUP_MODE_POLLING == STD_ON) && (CANTRCV_43_AE_ECUM_USED == STD_ON))
    uint32 Flag = 0U;
#endif 

#if (CANTRCV_43_AEWAKEUP_MODE_POLLING == STD_ON)
    if (TRUE == TransceiverConfig->CanTrcv_bWakeupByBusUsed)
    {
    #if (CANTRCV_43_AE_ECUM_USED == STD_ON)
        if (0U != TransceiverConfig->CanTrcv_WakeupSourceMask)
        {
            Retval = AeCanPHY_Ip_GetEventStatusFlag(TransceiverConfig->CanTrcv_u8HwTransceiverId, &Flag);
            if (AE_CANPHY_STATUS_SUCCESS == Retval)
            {
                if ((AE_CANPHY_CANPHY_MONITOR_REG_CANPHY_WKUP_FLAG & Flag) != 0U)
                {
                    EcuM_SetWakeupEvent(TransceiverConfig->CanTrcv_WakeupSourceMask);
                }
            }
        }
    #endif /* (CANTRCV_43_AE_ECUM_USED == STD_ON) */

        if (AE_CANPHY_STATUS_SUCCESS == Retval)
        {
            /* Enable wakeup notification */
            Retval = AeCanPHY_Ip_SetEventNotification(TransceiverConfig->CanTrcv_u8HwTransceiverId, AE_CANPHY_WKUP_EVENT, TRUE);
        }
    }
#endif /* (CANTRCV_43_AEWAKEUP_MODE_POLLING == STD_ON) */

    if (AE_CANPHY_STATUS_SUCCESS == Retval)
    {
        Retval = AeCanPHY_Ip_Init(TransceiverConfig->CanTrcv_u8HwTransceiverId, TransceiverConfig->CanTrcv_IpwTransceiverConfig->CanTrcv_Ipw_HwConfig);
    }

#if ((CANTRCV_43_AEWAKEUP_MODE_POLLING == STD_ON) &&  (CANTRCV_43_AE_ICU_USED == STD_ON))
    if ((AE_CANPHY_STATUS_SUCCESS == Retval) && (TRUE == TransceiverConfig->CanTrcv_bIcuUsed))
    {
        if (CANTRCV_TRCVMODE_STANDBY == TransceiverConfig->CanTrcv_eInitState)
        {
            Icu_EnableNotification(TransceiverConfig->CanTrcv_u16IcuChnId);
        }
        else
        {
            Icu_DisableNotification(TransceiverConfig->CanTrcv_u16IcuChnId);
        }
    }
#endif /* ((CANTRCV_43_AEWAKEUP_MODE_POLLING == STD_ON) &&  (CANTRCV_43_AE_ICU_USED == STD_ON)) */

    /* If the read/write commands can't be written successfully to transceiver by Spi, Report det runtime */
    CanTrcv_Ipw_ReportSpiMiscommunication(Retval, CANTRCV_43_AE_SID_INIT);

    return (AE_CANPHY_STATUS_SUCCESS == Retval) ? (E_OK) : (E_NOT_OK);
}

/* Ipw_SetOpMode */
Std_ReturnType CanTrcv_43_AE_Ipw_SetOpMode(const CanTrcv_43_AE_TransceiverConfigType * TransceiverConfig, CanTrcv_TrcvModeType OpMode)
{
    AeCanPHY_Ip_StatusType Retval = AE_CANPHY_STATUS_FAILED;

    /* Map the modes supported by hw to modes of autosar */
    switch (OpMode)
    {
        case CANTRCV_TRCVMODE_NORMAL:
        {
            Retval = AeCanPHY_Ip_SetMode(TransceiverConfig->CanTrcv_u8HwTransceiverId, AE_CANPHY_NORMAL_MODE);
        #if (CANTRCV_43_AE_ICU_USED == STD_ON)
            if ((AE_CANPHY_STATUS_SUCCESS == Retval) && (TRUE == (TransceiverConfig->CanTrcv_bIcuUsed)))
            {
                Icu_DisableNotification(TransceiverConfig->CanTrcv_u16IcuChnId);
            }
        #endif
            break;
        }
        case CANTRCV_TRCVMODE_STANDBY:
        {
            Retval = AeCanPHY_Ip_SetMode(TransceiverConfig->CanTrcv_u8HwTransceiverId, AE_CANPHY_OFFLINE_MODE);
        #if (CANTRCV_43_AE_ICU_USED == STD_ON)
            if ((AE_CANPHY_STATUS_SUCCESS == Retval) && (TRUE == (TransceiverConfig->CanTrcv_bIcuUsed)))
            {
                Icu_EnableNotification(TransceiverConfig->CanTrcv_u16IcuChnId);
            }
        #endif
            break;
        }
        /* The sleep mode is not under control by Can PHY but AE(deepsleep mode),
         * the driver will not map sleep mode to CANPHY HW as it has same functionality with stanby mode at the view of driver. */
        default:
            /* return NOT_OK if sleep mode requested. */
            break;
    }

    /* If the read/write commands can't be written successfully to transceiver by Spi, Report det runtime */
    CanTrcv_Ipw_ReportSpiMiscommunication(Retval, CANTRCV_43_AE_SID_SET_OPMODE);

    return (AE_CANPHY_STATUS_SUCCESS == Retval) ? (E_OK) : (E_NOT_OK);
}

/* Ipw_GetOpMode */
Std_ReturnType CanTrcv_43_AE_Ipw_GetOpMode(const CanTrcv_43_AE_TransceiverConfigType * TransceiverConfig, CanTrcv_TrcvModeType* OpMode)
{
    AeCanPHY_Ip_StatusType Retval = AE_CANPHY_STATUS_FAILED;
    AeCanPHY_Ip_TransceiverModeType TransceiverMode;

    Retval = AeCanPHY_Ip_GetMode(TransceiverConfig->CanTrcv_u8HwTransceiverId, &TransceiverMode);

    if (AE_CANPHY_STATUS_SUCCESS == Retval)
    {
        /* Map the modes supported by hw to modes of autosar */
        switch (TransceiverMode)
        {
            case AE_CANPHY_NORMAL_MODE:
            {
                *OpMode = CANTRCV_TRCVMODE_NORMAL;
                break;
            }
            case AE_CANPHY_OFFLINE_MODE:
            {
                *OpMode = CANTRCV_TRCVMODE_STANDBY;
                break;
            }
            default:
                break;
        }
    }

    /* If the read/write commands can't be written successfully to transceiver by Spi, Report det runtime */
    CanTrcv_Ipw_ReportSpiMiscommunication(Retval, CANTRCV_43_AE_SID_GET_OPMODE);

    return (AE_CANPHY_STATUS_SUCCESS == Retval) ? (E_OK) : (E_NOT_OK);
}

/* Ipw_GetBusWuReason */
Std_ReturnType CanTrcv_43_AE_Ipw_GetBusWuReason(const CanTrcv_43_AE_TransceiverConfigType * TransceiverConfig, CanTrcv_TrcvWakeupReasonType * Reason)
{
    Std_ReturnType Retval = E_OK;
#if (CANTRCV_43_AEWAKEUP_MODE_POLLING == STD_ON)
    uint32 Flag = 0U;
#endif /* (CANTRCV_43_AEWAKEUP_MODE_POLLING == STD_ON) */
    CanTrcv_TrcvWakeupReasonType WuReasonTemp = CANTRCV_WU_NOT_SUPPORTED;

#if (CANTRCV_43_AEWAKEUP_MODE_POLLING == STD_ON)
    if (TRUE == TransceiverConfig->CanTrcv_bWakeupByBusUsed)
    {
        if (AE_CANPHY_STATUS_SUCCESS == AeCanPHY_Ip_GetEventStatusFlag(TransceiverConfig->CanTrcv_u8HwTransceiverId, &Flag))
        {
            if ((AE_CANPHY_CANPHY_MONITOR_REG_CANPHY_WKUP_FLAG & Flag) != 0U)
            {
                /* A bus wakeup detected */
                WuReasonTemp = CANTRCV_WU_BY_BUS;
            }
            else
            {
                /* No reasons detected, return E_NOT_OK */
                Retval = E_NOT_OK;
            }
        }
        else
        {
            /* Still return E_OK in this case, because infact the reason here is CANTRCV_WU_ERROR */
            WuReasonTemp = CANTRCV_WU_ERROR;
            /* If the read/write commands can't be written successfully to transceiver by Spi, Report det runtime */
            CanTrcv_Ipw_ReportSpiMiscommunication(AE_CANPHY_STATUS_ERR_SPI, CANTRCV_43_AE_SID_GET_BUS_WU_REASON);
        }
    }
#else
    (void)TransceiverConfig;
#endif /* (CANTRCV_43_AEWAKEUP_MODE_POLLING == STD_ON) */

    if (E_OK == Retval)
    {
        *Reason = WuReasonTemp;
    }
    return Retval;
}

/* Ipw_SetWakeupMode */
Std_ReturnType CanTrcv_43_AE_Ipw_SetWakeupMode(const CanTrcv_43_AE_TransceiverConfigType * TransceiverConfig, CanTrcv_TrcvWakeupModeType TrcvWakeupMode)
{
    AeCanPHY_Ip_StatusType Retval = AE_CANPHY_STATUS_SUCCESS;
#if ((CANTRCV_43_AEWAKEUP_MODE_POLLING == STD_ON) && (CANTRCV_43_AE_ECUM_USED == STD_ON))
    uint32 Flag = 0U;
#endif 

    if (CANTRCV_WUMODE_CLEAR == TrcvWakeupMode)
    {
        /* Clear the wakeup flag from HW */
        Retval = AeCanPHY_Ip_ClearEventStatusFlag(TransceiverConfig->CanTrcv_u8HwTransceiverId, AE_CANPHY_WKUP_EVENT);
    }
    else
    {
        if (CANTRCV_WUMODE_ENABLE == TrcvWakeupMode)
        {
        #if (CANTRCV_43_AEWAKEUP_MODE_POLLING == STD_ON)
            if (TRUE == TransceiverConfig->CanTrcv_bWakeupByBusUsed)
            {
            #if (CANTRCV_43_AE_ECUM_USED == STD_ON)
                if (0U != TransceiverConfig->CanTrcv_WakeupSourceMask)
                {
                    Retval = AeCanPHY_Ip_GetEventStatusFlag(TransceiverConfig->CanTrcv_u8HwTransceiverId, &Flag);
                    if (AE_CANPHY_STATUS_SUCCESS == Retval)
                    {
                        if ((AE_CANPHY_CANPHY_MONITOR_REG_CANPHY_WKUP_FLAG & Flag) != 0U)
                        {
                            EcuM_SetWakeupEvent(TransceiverConfig->CanTrcv_WakeupSourceMask);
                        }
                    }
                }
            #endif /* (CANTRCV_43_AE_ECUM_USED == STD_ON) */
            }
        #endif /* (CANTRCV_43_AEWAKEUP_MODE_POLLING == STD_ON) */

        #if (CANTRCV_43_AE_ICU_USED == STD_ON)
            if ((AE_CANPHY_STATUS_SUCCESS == Retval) && (TRUE == TransceiverConfig->CanTrcv_bIcuUsed))
            {
                Icu_EnableNotification(TransceiverConfig->CanTrcv_u16IcuChnId);
            }
        #endif
        }
        else /* (CANTRCV_WUMODE_DISABLE == TrcvWakeupMode) */
        {
        #if (CANTRCV_43_AE_ICU_USED == STD_ON)
            if (TRUE == TransceiverConfig->CanTrcv_bIcuUsed)
            {
                Icu_DisableNotification(TransceiverConfig->CanTrcv_u16IcuChnId);
            }
        #endif
        }
    }

    /* If the read/write commands can't be written successfully to transceiver by Spi, Report det runtime */
    CanTrcv_Ipw_ReportSpiMiscommunication(Retval, CANTRCV_43_AE_SID_SET_WAKEUP_MODE);

    return (AE_CANPHY_STATUS_SUCCESS == Retval) ? (E_OK) : (E_NOT_OK);
}

Std_ReturnType CanTrcv_43_AE_Ipw_CheckWakeupFlag(const CanTrcv_43_AE_TransceiverConfigType * TransceiverConfig, boolean * WakeFlag)
{
    AeCanPHY_Ip_StatusType Retval = AE_CANPHY_STATUS_FAILED;
    uint32 Flag = 0U;

    Retval = AeCanPHY_Ip_GetEventStatusFlag(TransceiverConfig->CanTrcv_u8HwTransceiverId, &Flag);

    if (AE_CANPHY_STATUS_SUCCESS == Retval)
    {
        if ((AE_CANPHY_CANPHY_MONITOR_REG_CANPHY_WKUP_FLAG & Flag) != 0U)
        {
            *WakeFlag = TRUE;
        }
    }

    return (AE_CANPHY_STATUS_SUCCESS == Retval) ? (E_OK) : (E_NOT_OK);
}

Std_ReturnType CanTrcv_43_AE_Ipw_CheckBusError(const CanTrcv_43_AE_TransceiverConfigType * TransceiverConfig, boolean * ErrFlag)
{
    AeCanPHY_Ip_StatusType Retval = AE_CANPHY_STATUS_FAILED;
    uint32 Flag = 0U;

    Retval = AeCanPHY_Ip_GetEventStatusFlag(TransceiverConfig->CanTrcv_u8HwTransceiverId, &Flag);

    if (AE_CANPHY_STATUS_SUCCESS == Retval)
    {
        /* Check if the transceiver is one of error states: Dominant timeout, invalid state */
        if (((AE_CANPHY_CANPHY_MONITOR_REG_TXDOM_TIMEDOUT_FLAG | AE_CANPHY_CANPHY_MONITOR_REG_INVALID_STATE_FLAG) & Flag) != 0U)
        {
            *ErrFlag = TRUE;
        }
        /* consider to clear error flags after reported to uppper layer */
    }

    return (AE_CANPHY_STATUS_SUCCESS == Retval) ? (E_OK) : (E_NOT_OK);
}


/* Ipw_DeInit */
Std_ReturnType CanTrcv_43_AE_Ipw_DeInit(const CanTrcv_43_AE_TransceiverConfigType * TransceiverConfig)
{
    AeCanPHY_Ip_StatusType Retval = AE_CANPHY_STATUS_FAILED;

    Retval = AeCanPHY_Ip_DeInit(TransceiverConfig->CanTrcv_u8HwTransceiverId);

    /* If the read/write commands can't be written successfully to transceiver by Spi, Report det runtime */
    CanTrcv_Ipw_ReportSpiMiscommunication(Retval, CANTRCV_43_AE_SID_DEINIT);

    return (AE_CANPHY_STATUS_SUCCESS == Retval) ? (E_OK) : (E_NOT_OK);
}

#define CANTRCV_43_AE_STOP_SEC_CODE
#include "CanTrcv_43_AE_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */
