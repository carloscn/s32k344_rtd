/*==================================================================================================
*   Project              : RTD AUTOSAR 4.7
*   Platform             : CORTEXM
*   Peripheral           : AE
*   Dependencies         : none
*
*   Autosar Version      : 4.7.0
*   Autosar Revision     : ASR_REL_4_7_REV_0000
*   Autosar Conf.Variant :
*   SW Version           : 3.0.0
*   Build Version        : S32K3_RTD_3_0_0_D2303_ASR_REL_4_7_REV_0000_20230331
*
*   (c) Copyright 2020 - 2023 NXP Semiconductors
*   All Rights Reserved.
*
*   NXP Confidential. This software is owned or controlled by NXP and may only be
*   used strictly in accordance with the applicable license terms. By expressly
*   accepting such terms or by downloading, installing, activating and/or otherwise
*   using the software, you are agreeing that you have read, and that you agree to
*   comply with and are bound by, such license terms. If you do not agree to be
*   bound by the applicable license terms, then you may not retain, install,
*   activate or otherwise use the software.
==================================================================================================*/

#ifndef AELINPHY_LINTRCV_IP_H
#define AELINPHY_LINTRCV_IP_H

/**
*   @file AeLinPhy_LinTrcv_Ip.h
*
*   @addtogroup AELINPHY_LINTRCV_IP
*   @{
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
#include "AeLinPhy_LinTrcv_Ip_Cfg.h"
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define AELINPHY_LINTRCV_IP_VENDOR_ID                      43
#define AELINPHY_LINTRCV_IP_AR_RELEASE_MAJOR_VERSION       4
#define AELINPHY_LINTRCV_IP_AR_RELEASE_MINOR_VERSION       7
#define AELINPHY_LINTRCV_IP_AR_RELEASE_REVISION_VERSION    0
#define AELINPHY_LINTRCV_IP_SW_MAJOR_VERSION               3
#define AELINPHY_LINTRCV_IP_SW_MINOR_VERSION               0
#define AELINPHY_LINTRCV_IP_SW_PATCH_VERSION               0

/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/

/* Checks against AeLinPhy_LinTrcv_Ip_Cfg.h */
#if (AELINPHY_LINTRCV_IP_VENDOR_ID != AELINPHY_LINTRCV_IP_CFG_VENDOR_ID)
    #error "AeLinPhy_Ip.h and AeLinPhy_Ip_Cfg.h have different vendor ids"
#endif
/* Check if current file and AeLinPhy_LinTrcv_Ip_Cfg header file are of the same Autosar version */
#if ((AELINPHY_LINTRCV_IP_AR_RELEASE_MAJOR_VERSION    != AELINPHY_LINTRCV_IP_CFG_AR_RELEASE_MAJOR_VERSION) || \
     (AELINPHY_LINTRCV_IP_AR_RELEASE_MINOR_VERSION    != AELINPHY_LINTRCV_IP_CFG_AR_RELEASE_MINOR_VERSION) || \
     (AELINPHY_LINTRCV_IP_AR_RELEASE_REVISION_VERSION != AELINPHY_LINTRCV_IP_CFG_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AUTOSAR Version Numbers of AeLinPhy_LinTrcv_Ip.h and AeLinPhy_LinTrcv_Ip_Cfg.h are different"
#endif
/* Check if current file and AeLinPhy_LinTrcv_Ip_Cfg header file are of the same Software version */
#if ((AELINPHY_LINTRCV_IP_SW_MAJOR_VERSION != AELINPHY_LINTRCV_IP_CFG_SW_MAJOR_VERSION) || \
     (AELINPHY_LINTRCV_IP_SW_MINOR_VERSION != AELINPHY_LINTRCV_IP_CFG_SW_MINOR_VERSION) || \
     (AELINPHY_LINTRCV_IP_SW_PATCH_VERSION != AELINPHY_LINTRCV_IP_CFG_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of AeLinPhy_LinTrcv_Ip.h and AeLinPhy_LinTrcv_Ip_Cfg.h are different"
#endif

/* Checks against AeLinPhy_LinTrcv_Ip_Types.h */
#if (AELINPHY_LINTRCV_IP_VENDOR_ID != AELINPHY_LINTRCV_IP_TYPES_VENDOR_ID)
    #error "AeLinPhy_LinTrcv_Ip.h and AeLinPhy_LinTrcv_Ip_Types.h have different vendor ids"
#endif
/* Check if current file and AeLinPhy_LinTrcv_Ip_Types header file are of the same Autosar version */
#if ((AELINPHY_LINTRCV_IP_AR_RELEASE_MAJOR_VERSION    != AELINPHY_LINTRCV_IP_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (AELINPHY_LINTRCV_IP_AR_RELEASE_MINOR_VERSION    != AELINPHY_LINTRCV_IP_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (AELINPHY_LINTRCV_IP_AR_RELEASE_REVISION_VERSION != AELINPHY_LINTRCV_IP_TYPES_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AUTOSAR Version Numbers of AeLinPhy_LinTrcv_Ip.h and AeLinPhy_LinTrcv_Ip_Types.h are different"
#endif
/* Check if current file and AeLinPhy_LinTrcv_Ip_Types header file are of the same Software version */
#if ((AELINPHY_LINTRCV_IP_SW_MAJOR_VERSION != AELINPHY_LINTRCV_IP_TYPES_SW_MAJOR_VERSION) || \
     (AELINPHY_LINTRCV_IP_SW_MINOR_VERSION != AELINPHY_LINTRCV_IP_TYPES_SW_MINOR_VERSION) || \
     (AELINPHY_LINTRCV_IP_SW_PATCH_VERSION != AELINPHY_LINTRCV_IP_TYPES_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of AeLinPhy_LinTrcv_Ip.h and AeLinPhy_LinTrcv_Ip_Types.h are different"
#endif

/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/


/*==================================================================================================
*                                             ENUMS
==================================================================================================*/

/*==================================================================================================
*                                     STRUCTURES AND OTHERS
==================================================================================================*/

/*==================================================================================================
                                 GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
                                     FUNCTION PROTOTYPES
==================================================================================================*/
#define LINTRCV_43_AE_START_SEC_CODE
#include "LinTrcv_43_AE_MemMap.h"

/*!
AeLinPhy_LinTrcv_Ip_Init
 */
AeLinPhy_LinTrcv_Ip_StatusType AeLinPhy_LinTrcv_Ip_Init(const uint8 Instance, const AeLinPhy_LinTrcv_Ip_UserConfigType *LinTrcvUserConfig);

/*!
AeLinPhy_LinTrcv_Ip_Deinit
 */
AeLinPhy_LinTrcv_Ip_StatusType AeLinPhy_LinTrcv_Ip_Deinit(const uint8 Instance);

/*!
AeLinPhy_LinTrcv_Ip_SetMode
 */
AeLinPhy_LinTrcv_Ip_StatusType AeLinPhy_LinTrcv_Ip_SetMode(const uint8 Instance, const AeLinPhy_LinTrcv_Ip_TransceiverModeType OpMode);

/*!
AeLinPhy_LinTrcv_Ip_GetMode
 */
AeLinPhy_LinTrcv_Ip_StatusType AeLinPhy_LinTrcv_Ip_GetMode(const uint8 Instance, AeLinPhy_LinTrcv_Ip_TransceiverModeType *TransceiverMode);

/*!
AeLinPhy_LinTrcv_Ip_SetWakeupMode
 */
AeLinPhy_LinTrcv_Ip_StatusType AeLinPhy_LinTrcv_Ip_SetWakeupMode(const uint8 Instance, AeLinPhy_LinTrcv_Ip_TrcvWakeupModeType TrcvWakupMode);

/*!
AeLinPhy_LinTrcv_Ip_CheckWakeupFlag
 */
AeLinPhy_LinTrcv_Ip_StatusType AeLinPhy_LinTrcv_Ip_CheckWakeupFlag(const uint8 Instance);


#define LINTRCV_43_AE_STOP_SEC_CODE
#include "LinTrcv_43_AE_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */

#endif /* AELINPHY_LINTRCV_IP_H */
