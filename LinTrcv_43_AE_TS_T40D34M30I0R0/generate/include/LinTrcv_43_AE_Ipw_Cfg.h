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

#ifndef LINTRCV_43_AE_IPW_CFG_H
#define LINTRCV_43_AE_IPW_CFG_H

/**
*   @file
*
*   @internal
*   @addtogroup LINTRCV_43_AE_IPW
*   @{
*/

#ifdef __cplusplus
extern "C"
{
#endif

/*==================================================================================================
                                         INCLUDE FILES
 1) system and project includes
 2) needed interfaces from external units
 3) internal and external interfaces from this unit
==================================================================================================*/

#include "LinTrcv_43_AE_Ipw_Types.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/

#define LINTRCV_43_AE_IPW_CFG_VENDOR_ID                    43
#define LINTRCV_43_AE_IPW_CFG_AR_RELEASE_MAJOR_VERSION     4
#define LINTRCV_43_AE_IPW_CFG_AR_RELEASE_MINOR_VERSION     7
#define LINTRCV_43_AE_IPW_CFG_AR_RELEASE_REVISION_VERSION  0
#define LINTRCV_43_AE_IPW_CFG_SW_MAJOR_VERSION             3
#define LINTRCV_43_AE_IPW_CFG_SW_MINOR_VERSION             0
#define LINTRCV_43_AE_IPW_CFG_SW_PATCH_VERSION             0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Checks against LinTrcv_43_AE_Ipw_PBcfg.h */
#if (LINTRCV_43_AE_IPW_CFG_VENDOR_ID != LINTRCV_43_AE_IPW_CFG_VENDOR_ID)
    #error "LinTrcv_43_AE_Ipw_Cfg.h and LinTrcv_43_AE_Ipw_PBcfg.h have different vendor ids"
#endif
#if ((LINTRCV_43_AE_IPW_CFG_AR_RELEASE_MAJOR_VERSION    != LINTRCV_43_AE_IPW_CFG_AR_RELEASE_MAJOR_VERSION) || \
     (LINTRCV_43_AE_IPW_CFG_AR_RELEASE_MINOR_VERSION    != LINTRCV_43_AE_IPW_CFG_AR_RELEASE_MINOR_VERSION) || \
     (LINTRCV_43_AE_IPW_CFG_AR_RELEASE_REVISION_VERSION != LINTRCV_43_AE_IPW_CFG_AR_RELEASE_REVISION_VERSION))
     #error "AUTOSAR Version Numbers of LinTrcv_43_AE_Ipw_Cfg.h and LinTrcv_43_AE_Ipw_PBcfg.h are different"
#endif
#if ((LINTRCV_43_AE_IPW_CFG_SW_MAJOR_VERSION != LINTRCV_43_AE_IPW_CFG_SW_MAJOR_VERSION) || \
     (LINTRCV_43_AE_IPW_CFG_SW_MINOR_VERSION != LINTRCV_43_AE_IPW_CFG_SW_MINOR_VERSION) || \
     (LINTRCV_43_AE_IPW_CFG_SW_PATCH_VERSION != LINTRCV_43_AE_IPW_CFG_SW_PATCH_VERSION))
    #error "Software Version Numbers of LinTrcv_43_AE_Ipw_Cfg.h and LinTrcv_43_AE_Ipw_PBcfg.h are different"
#endif


/* Checks against LinTrcv_43_AE_Ipw_Types.h */
#if (LINTRCV_43_AE_IPW_CFG_VENDOR_ID != LINTRCV_43_AE_IPW_TYPES_VENDOR_ID)
    #error "LinTrcv_43_AE_Ipw_Cfg.h and LinTrcv_43_AE_Ipw_Types.h have different vendor ids"
#endif
#if ((LINTRCV_43_AE_IPW_CFG_AR_RELEASE_MAJOR_VERSION    != LINTRCV_43_AE_IPW_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (LINTRCV_43_AE_IPW_CFG_AR_RELEASE_MINOR_VERSION    != LINTRCV_43_AE_IPW_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (LINTRCV_43_AE_IPW_CFG_AR_RELEASE_REVISION_VERSION != LINTRCV_43_AE_IPW_TYPES_AR_RELEASE_REVISION_VERSION))
     #error "AUTOSAR Version Numbers of LinTrcv_43_AE_Ipw_Cfg.h and LinTrcv_43_AE_Ipw_Types.h are different"
#endif
#if ((LINTRCV_43_AE_IPW_CFG_SW_MAJOR_VERSION != LINTRCV_43_AE_IPW_TYPES_SW_MAJOR_VERSION) || \
     (LINTRCV_43_AE_IPW_CFG_SW_MINOR_VERSION != LINTRCV_43_AE_IPW_TYPES_SW_MINOR_VERSION) || \
     (LINTRCV_43_AE_IPW_CFG_SW_PATCH_VERSION != LINTRCV_43_AE_IPW_TYPES_SW_PATCH_VERSION))
    #error "Software Version Numbers of LinTrcv_43_AE_Ipw_Cfg.h and LinTrcv_43_AE_Ipw_Types.h are different"
#endif
/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/

[!NOCODE!]
[!CODE!]#define LINTRCV_43_AE_IPW_CONFIG_EXT \[!CR!][!ENDCODE!]
[!LOOP "LinTrcvChannel/*"!][!//
    [!CODE!]
    extern const LinTrcv_43_AE_HwConfigType LinTrcv_43_AE_Ipw_pHwConfigPB_[!"LinTrcvChannelId"!];\
    [!ENDCODE!]
[!ENDLOOP!]

[!VAR "AllLinTrcvChannelEnableEcuMWakeupSource" = "'true'"!]
[!LOOP "LinTrcvChannel/*"!]
    [!IF "not(node:exists(LinTrcvWakeupSourceRef))"!]
        [!VAR "AllLinTrcvChannelEnableEcuMWakeupSource" = "'false'"!]
    [!ENDIF!]
[!ENDLOOP!]
[!IF "$AllLinTrcvChannelEnableEcuMWakeupSource = 'false'"!]
[!CODE!]
/**
* @brief          None EcuMWakeUpSource was referrd when LinTrcvChannelWakeupSupport is disable
*/
#if (LINTRCV_43_AE_WAKEUP_DETECTION == STD_ON)
#define LINTRCV_43_AE_NONE_ECUM_WAKEUP_SOURCE_REF     (0UL)
#endif
[!ENDCODE!]
[!ENDIF!]
[!ENDNOCODE!]

/*==================================================================================================
*                                             ENUMS
==================================================================================================*/

/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                       GLOBAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/

#ifdef __cplusplus
}
#endif

/** @} */

#endif /* LINTRCV_43_AE_IPW_CFG_H */
