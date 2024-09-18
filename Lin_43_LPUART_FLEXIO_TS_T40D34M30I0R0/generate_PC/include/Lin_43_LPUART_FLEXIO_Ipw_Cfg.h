/*==================================================================================================
*   Project              : RTD AUTOSAR 4.7
*   Platform             : CORTEXM
*   Peripheral           : LPUART_FLEXIO
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

#ifndef LIN_43_LPUART_FLEXIO_IPW_CFG_H
#define LIN_43_LPUART_FLEXIO_IPW_CFG_H

/**
*   @file
*   
*   @internal 
*   @addtogroup LIN_IPW
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

[!NOCODE!]
[!IF "var:defined('postBuildVariant')"!]
[!LOOP "variant:all()"!]
[!CODE!]#include "Lin_43_LPUART_FLEXIO_Ipw_[!"."!]_PBcfg.h"[!CR!][!ENDCODE!]
[!ENDLOOP!]
[!ELSE!]
[!CODE!]#include "Lin_43_LPUART_FLEXIO_Ipw_PBcfg.h"[!ENDCODE!]
[!ENDIF!]
[!ENDNOCODE!]
#include "Lin_43_LPUART_FLEXIO_Ipw_Types.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/

#define LIN_43_LPUART_FLEXIO_IPW_CFG_VENDOR_ID                    43
#define LIN_43_LPUART_FLEXIO_IPW_CFG_AR_RELEASE_MAJOR_VERSION     4
#define LIN_43_LPUART_FLEXIO_IPW_CFG_AR_RELEASE_MINOR_VERSION     7
#define LIN_43_LPUART_FLEXIO_IPW_CFG_AR_RELEASE_REVISION_VERSION  0
#define LIN_43_LPUART_FLEXIO_IPW_CFG_SW_MAJOR_VERSION             3
#define LIN_43_LPUART_FLEXIO_IPW_CFG_SW_MINOR_VERSION             0
#define LIN_43_LPUART_FLEXIO_IPW_CFG_SW_PATCH_VERSION             0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
[!NOCODE!]
[!IF "var:defined('postBuildVariant')"!]
[!LOOP "variant:all()"!]
[!CODE!][!//
/* Checks against Lin_43_LPUART_FLEXIO_Ipw_[!"."!]_PBcfg.h */
#if (LIN_43_LPUART_FLEXIO_IPW_CFG_VENDOR_ID != LIN_43_LPUART_FLEXIO_IPW_[!"."!]_PBCFG_VENDOR_ID)
    #error "Lin_43_LPUART_FLEXIO_Ipw_Cfg.h and Lin_43_LPUART_FLEXIO_Ipw_[!"."!]_PBcfg.h have different vendor ids"
#endif
#if ((LIN_43_LPUART_FLEXIO_IPW_CFG_AR_RELEASE_MAJOR_VERSION    != LIN_43_LPUART_FLEXIO_IPW_[!"."!]_PBCFG_AR_RELEASE_MAJOR_VERSION) || \
     (LIN_43_LPUART_FLEXIO_IPW_CFG_AR_RELEASE_MINOR_VERSION    != LIN_43_LPUART_FLEXIO_IPW_[!"."!]_PBCFG_AR_RELEASE_MINOR_VERSION) || \
     (LIN_43_LPUART_FLEXIO_IPW_CFG_AR_RELEASE_REVISION_VERSION != LIN_43_LPUART_FLEXIO_IPW_[!"."!]_PBCFG_AR_RELEASE_REVISION_VERSION))
     #error "AUTOSAR Version Numbers of Lin_43_LPUART_FLEXIO_Ipw_Cfg.h and Lin_43_LPUART_FLEXIO_Ipw_[!"."!]_PBcfg.h are different"
#endif
#if ((LIN_43_LPUART_FLEXIO_IPW_CFG_SW_MAJOR_VERSION != LIN_43_LPUART_FLEXIO_IPW_[!"."!]_PBCFG_SW_MAJOR_VERSION) || \
     (LIN_43_LPUART_FLEXIO_IPW_CFG_SW_MINOR_VERSION != LIN_43_LPUART_FLEXIO_IPW_[!"."!]_PBCFG_SW_MINOR_VERSION) || \
     (LIN_43_LPUART_FLEXIO_IPW_CFG_SW_PATCH_VERSION != LIN_43_LPUART_FLEXIO_IPW_[!"."!]_PBCFG_SW_PATCH_VERSION))
    #error "Software Version Numbers of Lin_43_LPUART_FLEXIO_Ipw_Cfg.h and Lin_43_LPUART_FLEXIO_Ipw_[!"."!]_PBcfg.h are different"
#endif
[!ENDCODE!]
[!ENDLOOP!]
[!ELSE!]
[!CODE!][!//
/* Checks against Lin_43_LPUART_FLEXIO_Ipw_PBcfg.h */
#if (LIN_43_LPUART_FLEXIO_IPW_CFG_VENDOR_ID != LIN_43_LPUART_FLEXIO_IPW_PBCFG_VENDOR_ID)
    #error "Lin_43_LPUART_FLEXIO_Ipw_Cfg.h and Lin_43_LPUART_FLEXIO_Ipw_PBcfg.h have different vendor ids"
#endif
#if ((LIN_43_LPUART_FLEXIO_IPW_CFG_AR_RELEASE_MAJOR_VERSION    != LIN_43_LPUART_FLEXIO_IPW_PBCFG_AR_RELEASE_MAJOR_VERSION) || \
     (LIN_43_LPUART_FLEXIO_IPW_CFG_AR_RELEASE_MINOR_VERSION    != LIN_43_LPUART_FLEXIO_IPW_PBCFG_AR_RELEASE_MINOR_VERSION) || \
     (LIN_43_LPUART_FLEXIO_IPW_CFG_AR_RELEASE_REVISION_VERSION != LIN_43_LPUART_FLEXIO_IPW_PBCFG_AR_RELEASE_REVISION_VERSION))
     #error "AUTOSAR Version Numbers of Lin_43_LPUART_FLEXIO_Ipw_Cfg.h and Lin_43_LPUART_FLEXIO_Ipw_PBcfg.h are different"
#endif
#if ((LIN_43_LPUART_FLEXIO_IPW_CFG_SW_MAJOR_VERSION != LIN_43_LPUART_FLEXIO_IPW_PBCFG_SW_MAJOR_VERSION) || \
     (LIN_43_LPUART_FLEXIO_IPW_CFG_SW_MINOR_VERSION != LIN_43_LPUART_FLEXIO_IPW_PBCFG_SW_MINOR_VERSION) || \
     (LIN_43_LPUART_FLEXIO_IPW_CFG_SW_PATCH_VERSION != LIN_43_LPUART_FLEXIO_IPW_PBCFG_SW_PATCH_VERSION))
    #error "Software Version Numbers of Lin_43_LPUART_FLEXIO_Ipw_Cfg.h and Lin_43_LPUART_FLEXIO_Ipw_PBcfg.h are different"
#endif
[!ENDCODE!]
[!ENDIF!]
[!ENDNOCODE!]

/* Checks against Lin_43_LPUART_FLEXIO_Ipw_Types.h */
#if (LIN_43_LPUART_FLEXIO_IPW_CFG_VENDOR_ID != LIN_43_LPUART_FLEXIO_IPW_TYPES_VENDOR_ID)
    #error "Lin_43_LPUART_FLEXIO_Ipw_Cfg.h and Lin_43_LPUART_FLEXIO_Ipw_Types.h have different vendor ids"
#endif
#if ((LIN_43_LPUART_FLEXIO_IPW_CFG_AR_RELEASE_MAJOR_VERSION    != LIN_43_LPUART_FLEXIO_IPW_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (LIN_43_LPUART_FLEXIO_IPW_CFG_AR_RELEASE_MINOR_VERSION    != LIN_43_LPUART_FLEXIO_IPW_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (LIN_43_LPUART_FLEXIO_IPW_CFG_AR_RELEASE_REVISION_VERSION != LIN_43_LPUART_FLEXIO_IPW_TYPES_AR_RELEASE_REVISION_VERSION))
     #error "AUTOSAR Version Numbers of Lin_43_LPUART_FLEXIO_Ipw_Cfg.h and Lin_43_LPUART_FLEXIO_Ipw_Types.h are different"
#endif
#if ((LIN_43_LPUART_FLEXIO_IPW_CFG_SW_MAJOR_VERSION != LIN_43_LPUART_FLEXIO_IPW_TYPES_SW_MAJOR_VERSION) || \
     (LIN_43_LPUART_FLEXIO_IPW_CFG_SW_MINOR_VERSION != LIN_43_LPUART_FLEXIO_IPW_TYPES_SW_MINOR_VERSION) || \
     (LIN_43_LPUART_FLEXIO_IPW_CFG_SW_PATCH_VERSION != LIN_43_LPUART_FLEXIO_IPW_TYPES_SW_PATCH_VERSION))
    #error "Software Version Numbers of Lin_43_LPUART_FLEXIO_Ipw_Cfg.h and Lin_43_LPUART_FLEXIO_Ipw_Types.h are different"
#endif
/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/
[!NOCODE!]
[!CODE!]#define LIN_43_LPUART_FLEXIO_IPW_CONFIG_EXT \[!CR!][!ENDCODE!]
[!IF "var:defined('postBuildVariant')"!]
[!LOOP "variant:all()"!][!//
    [!CODE!][!WS "4"!]LIN_43_LPUART_FLEXIO_IPW_CONFIG_[!"."!]_PB \[!CR!][!ENDCODE!]
[!ENDLOOP!][!//
[!ELSE!][!//
    [!CODE!][!WS "4"!]LIN_43_LPUART_FLEXIO_IPW_CONFIG_PB[!ENDCODE!]
[!ENDIF!]
[!VAR "AllLinChannelEnableEcuMWakeupSource" = "'true'"!]
[!LOOP "LinGlobalConfig/LinChannel/*"!]
    [!IF "not(node:exists(LinChannelEcuMWakeupSource))"!]
        [!VAR "AllLinChannelEnableEcuMWakeupSource" = "'false'"!]
    [!ENDIF!]    
[!ENDLOOP!]
[!IF "$AllLinChannelEnableEcuMWakeupSource = 'false'"!]
[!CODE!]
#if (LIN_43_LPUART_FLEXIO_WAKEUP_DETECTION == STD_ON)

/**
* @brief          None EcuMWakeUpSource was referrd when LinChannelWakeupSupport is disable
*/
#define LIN_43_LPUART_FLEXIO_NONE_ECUM_WAKEUP_SOURCE_REF     (0UL)
#endif
[!ENDCODE!]
[!ENDIF!]

[!VAR "SlaveActivated" = "'STD_OFF'"!]
[!LOOP "LinGlobalConfig/LinChannel/*"!]
    [!IF "contains(node:value(LinNodeType), 'SLAVE')"!]
        [!VAR "SlaveActivated" = "'STD_ON'"!]
        [!BREAK!]
    [!ENDIF!]
[!ENDLOOP!]
[!CODE!]
/**
* @brief Macro which shows if at least one slave is present in the configuration
*/
#define LIN_43_LPUART_FLEXIO_IPW_DRIVER_HAS_SLAVE_NODE     ([!"$SlaveActivated"!]) 
[!ENDCODE!]
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

#endif /* LIN_43_LPUART_FLEXIO_IPW_CFG_H */
