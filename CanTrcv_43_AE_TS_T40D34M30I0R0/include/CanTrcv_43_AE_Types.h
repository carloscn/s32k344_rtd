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
* @file         CanTrcv_43_AE_Types.h
* @version      3.0.0
*
* @brief        AUTOSAR CanTrcv_43_AE - module interface.
*               API header for CANTRCV driver.
*
*
* @addtogroup   CANTRCV_DRIVER
* @{
*/

#ifndef _CANTRCV_43_AE_TYPYES_H_
#define _CANTRCV_43_AE_TYPYES_H_

/*==================================================================================================
                                         INCLUDE FILES
 1) system and project includes
 2) needed interfaces from external units
 3) internal and external interfaces from this unit
==================================================================================================*/
#include "StandardTypes.h"
#include "Can_GeneralTypes.h"
#include "CanTrcv_43_AE_Cfg.h"
#include "CanTrcv_43_AE_Ipw_Types.h"
/*==================================================================================================
                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/

/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/

/*==================================================================================================
                                           CONSTANTS
==================================================================================================*/

/*==================================================================================================
                                       DEFINES AND MACROS
==================================================================================================*/

/*==================================================================================================
                                             ENUMS
==================================================================================================*/

/*==================================================================================================
                                 STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/
/**
* @brief CanTrcv_43_AE_TransceiverConfigType
*/
typedef struct
{
    /** @brief The Id of Transceiver channel configured by tool configuration */
    const uint8 CanTrcv_u8SwTransceiverId;
    /** @brief The Id of Transceiver channel mapped in Hardware */
    const uint8 CanTrcv_u8HwTransceiverId;
    /** @brief The Id referred by CanIf to CanTrcv */
    const uint8 CanTrcv_u8CanIfTransceiverId;
#if (CANTRCV_43_AE_ICU_USED == STD_ON)
    /** @brief The Icu channel referred by the transceiver. */
    const boolean CanTrcv_bIcuUsed;
    /** @brief The Icu channel referred by the transceiver. */
    const uint16 CanTrcv_u16IcuChnId;
#endif
#if (CANTRCV_43_AE_ECUM_USED == STD_ON)
    /** @brief The value report to EcuM for a wakeup event. */
    const uint32 CanTrcv_WakeupSourceMask;
#endif
#if (CANTRCV_43_AE_DEM_USED == STD_ON)
    /** @brief The value report to Dem for a bus error. */
    const uint16 CanTrcv_DemEventId;
#endif
    /** @brief Specifies if wakeup is enabled on the transceiver */
    const boolean CanTrcv_bWakeupByBusUsed;
    /** @brief The mode of Transceiver after Init */
    const CanTrcv_TrcvModeType CanTrcv_eInitState;
    /** @brief Pointer to Ipw configuration wrapped to specific IPV configuration */
    const CanTrcv_43_AE_Ipw_TransceiverConfigType * const CanTrcv_IpwTransceiverConfig;
}CanTrcv_43_AE_TransceiverConfigType;
/*==================================================================================================
                                 GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
                                     FUNCTION PROTOTYPES
==================================================================================================*/

#endif /* _CANTRCV_43_AE_TYPYES_H_ */
