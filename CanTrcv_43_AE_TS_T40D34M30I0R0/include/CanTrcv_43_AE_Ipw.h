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
* @file         CanTrcv_43_AE_Ipw.h
* @version      3.0.0
*
* @brief        AUTOSAR CanTrcv_43_AE - module interface.
*               API header for CANTRCV driver.
*
*
* @addtogroup   CANTRCV_DRIVER
* @{
*/

#ifndef _CANTRCV_43_AE_IPW_H_
#define _CANTRCV_43_AE_IPW_H_


/*==================================================================================================
                                         INCLUDE FILES
 1) system and project includes
 2) needed interfaces from external units
 3) internal and external interfaces from this unit
==================================================================================================*/
#include "StandardTypes.h"
#include "Can_GeneralTypes.h"
#include "CanTrcv_43_AE_Types.h"
/*=================================================================================================
                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define CANTRCV_43_AE_IPW_VENDOR_ID                    43
#define CANTRCV_43_AE_IPW_MODULE_ID                    70
#define CANTRCV_43_AE_IPW_AR_RELEASE_MAJOR_VERSION     4
#define CANTRCV_43_AE_IPW_AR_RELEASE_MINOR_VERSION     7
#define CANTRCV_43_AE_IPW_AR_RELEASE_REVISION_VERSION  0
#define CANTRCV_43_AE_IPW_SW_MAJOR_VERSION             3
#define CANTRCV_43_AE_IPW_SW_MINOR_VERSION             0
#define CANTRCV_43_AE_IPW_SW_PATCH_VERSION             0
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

/*==================================================================================================
                                 GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
                                     FUNCTION PROTOTYPES
==================================================================================================*/

#define CANTRCV_43_AE_START_SEC_CODE
#include "CanTrcv_43_AE_MemMap.h"

/* Ipw_Init */
Std_ReturnType CanTrcv_43_AE_Ipw_Init(const CanTrcv_43_AE_TransceiverConfigType * TransceiverConfig);

/* Ipw_SetOpMode */
Std_ReturnType CanTrcv_43_AE_Ipw_SetOpMode(const CanTrcv_43_AE_TransceiverConfigType * TransceiverConfig, CanTrcv_TrcvModeType OpMode);

/* Ipw_GetOpMode */
Std_ReturnType CanTrcv_43_AE_Ipw_GetOpMode(const CanTrcv_43_AE_TransceiverConfigType * TransceiverConfig, CanTrcv_TrcvModeType* OpMode);

/* Ipw_GetBusWuReason */
Std_ReturnType CanTrcv_43_AE_Ipw_GetBusWuReason(const CanTrcv_43_AE_TransceiverConfigType * TransceiverConfig, CanTrcv_TrcvWakeupReasonType * Reason);

/* Ipw_SetWakeupMode */
Std_ReturnType CanTrcv_43_AE_Ipw_SetWakeupMode(const CanTrcv_43_AE_TransceiverConfigType * TransceiverConfig, CanTrcv_TrcvWakeupModeType TrcvWakeupMode);

/* Ipw_CheckWakeupFlag */
Std_ReturnType CanTrcv_43_AE_Ipw_CheckWakeupFlag(const CanTrcv_43_AE_TransceiverConfigType * TransceiverConfig, boolean * WakeFlag);

/* Ipw_CheckBusError */
Std_ReturnType CanTrcv_43_AE_Ipw_CheckBusError(const CanTrcv_43_AE_TransceiverConfigType * TransceiverConfig, boolean * ErrFlag);

/* Ipw_DeInit */
Std_ReturnType CanTrcv_43_AE_Ipw_DeInit(const CanTrcv_43_AE_TransceiverConfigType * TransceiverConfig);


#define CANTRCV_43_AE_STOP_SEC_CODE
#include "CanTrcv_43_AE_MemMap.h"

#endif /* _CANTRCV_43_AE_IPW_H_ */
