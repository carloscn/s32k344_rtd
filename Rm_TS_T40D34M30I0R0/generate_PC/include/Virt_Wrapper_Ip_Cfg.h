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
*   NXP Confidential. This software is owned or controlled by NXP and may only be
*   used strictly in accordance with the applicable license terms. By expressly
*   accepting such terms or by downloading, installing, activating and/or otherwise
*   using the software, you are agreeing that you have read, and that you agree to
*   comply with and are bound by, such license terms. If you do not agree to be
*   bound by the applicable license terms, then you may not retain, install,
*   activate or otherwise use the software.
==================================================================================================*/

#ifndef VIRT_WRAPPER_IP_CFG_H
#define VIRT_WRAPPER_IP_CFG_H

/**
*   @file Virt_Wrapper_Ip_Cfg.h
*
*   @addtogroup Virt_Wrapper_Ip Virt Wrapper IPV Driver
*   @{
*/


#ifdef __cplusplus
extern "C"{
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
[!CODE!]#include "Virt_Wrapper_Ip_[!"."!]_PBcfg.h"[!CR!][!ENDCODE!]
[!ENDLOOP!]
[!ELSE!]
[!CODE!]#include "Virt_Wrapper_Ip_PBcfg.h"[!ENDCODE!]
[!ENDIF!]
[!ENDNOCODE!]
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define RM_VIRT_WRAPPER_IP_CFG_VENDOR_ID                    43
#define RM_VIRT_WRAPPER_IP_CFG_AR_RELEASE_MAJOR_VERSION     4
#define RM_VIRT_WRAPPER_IP_CFG_AR_RELEASE_MINOR_VERSION     7
#define RM_VIRT_WRAPPER_IP_CFG_AR_RELEASE_REVISION_VERSION  0
#define RM_VIRT_WRAPPER_IP_CFG_SW_MAJOR_VERSION             3
#define RM_VIRT_WRAPPER_IP_CFG_SW_MINOR_VERSION             0
#define RM_VIRT_WRAPPER_IP_CFG_SW_PATCH_VERSION             0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
[!NOCODE!]
[!IF "var:defined('postBuildVariant')"!]
[!LOOP "variant:all()"!]
[!CODE!][!//
/* Checks against Virt_Wrapper_Ip_[!"."!]_PBcfg.h */
#if (RM_VIRT_WRAPPER_IP_CFG_VENDOR_ID != RM_VIRT_WRAPPER_IP_PBCFG_[!"."!]_VENDOR_ID)
    #error "Virt_Wrapper_Ip_Cfg.h and Virt_Wrapper_Ip_[!"."!]_PBcfg.h have different vendor ids"
#endif
#if ((RM_VIRT_WRAPPER_IP_CFG_AR_RELEASE_MAJOR_VERSION    != RM_VIRT_WRAPPER_IP_PBCFG_[!"."!]_AR_RELEASE_MAJOR_VERSION) || \
     (RM_VIRT_WRAPPER_IP_CFG_AR_RELEASE_MINOR_VERSION    != RM_VIRT_WRAPPER_IP_PBCFG_[!"."!]_AR_RELEASE_MINOR_VERSION) || \
     (RM_VIRT_WRAPPER_IP_CFG_AR_RELEASE_REVISION_VERSION != RM_VIRT_WRAPPER_IP_PBCFG_[!"."!]_AR_RELEASE_REVISION_VERSION))
     #error "AUTOSAR Version Numbers of Virt_Wrapper_Ip_Cfg.h and Virt_Wrapper_Ip_[!"."!]_PBcfg.h are different"
#endif
#if ((RM_VIRT_WRAPPER_IP_CFG_SW_MAJOR_VERSION != RM_VIRT_WRAPPER_IP_PBCFG_[!"."!]_SW_MAJOR_VERSION) || \
     (RM_VIRT_WRAPPER_IP_CFG_SW_MINOR_VERSION != RM_VIRT_WRAPPER_IP_PBCFG_[!"."!]_SW_MINOR_VERSION) || \
     (RM_VIRT_WRAPPER_IP_CFG_SW_PATCH_VERSION != RM_VIRT_WRAPPER_IP_PBCFG_[!"."!]_SW_PATCH_VERSION))
    #error "Software Version Numbers of Virt_Wrapper_Ip_Cfg.h and Virt_Wrapper_Ip_[!"."!]_PBcfg.h are different"
#endif
[!ENDCODE!]
[!ENDLOOP!]
[!ELSE!]
[!CODE!][!//
/* Checks against Virt_Wrapper_Ip_PBcfg.h */
#if (RM_VIRT_WRAPPER_IP_CFG_VENDOR_ID != RM_VIRT_WRAPPER_IP_PBCFG_VENDOR_ID)
    #error "Virt_Wrapper_Ip_Cfg.h and Virt_Wrapper_Ip_PBcfg.h have different vendor ids"
#endif
#if ((RM_VIRT_WRAPPER_IP_CFG_AR_RELEASE_MAJOR_VERSION    != RM_VIRT_WRAPPER_IP_PBCFG_AR_RELEASE_MAJOR_VERSION) || \
     (RM_VIRT_WRAPPER_IP_CFG_AR_RELEASE_MINOR_VERSION    != RM_VIRT_WRAPPER_IP_PBCFG_AR_RELEASE_MINOR_VERSION) || \
     (RM_VIRT_WRAPPER_IP_CFG_AR_RELEASE_REVISION_VERSION != RM_VIRT_WRAPPER_IP_PBCFG_AR_RELEASE_REVISION_VERSION))
     #error "AUTOSAR Version Numbers of Virt_Wrapper_Ip_Cfg.h and Virt_Wrapper_Ip_PBcfg.h are different"
#endif
#if ((RM_VIRT_WRAPPER_IP_CFG_SW_MAJOR_VERSION != RM_VIRT_WRAPPER_IP_PBCFG_SW_MAJOR_VERSION) || \
     (RM_VIRT_WRAPPER_IP_CFG_SW_MINOR_VERSION != RM_VIRT_WRAPPER_IP_PBCFG_SW_MINOR_VERSION) || \
     (RM_VIRT_WRAPPER_IP_CFG_SW_PATCH_VERSION != RM_VIRT_WRAPPER_IP_PBCFG_SW_PATCH_VERSION))
    #error "Software Version Numbers of Virt_Wrapper_Ip_Cfg.h and Virt_Wrapper_Ip_PBcfg.h are different"
#endif
[!ENDCODE!]
[!ENDIF!]
[!ENDNOCODE!]
/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/
[!IF "RmGeneral/RmVirtWrapperConfigurable"!]
/**
* @brief   Collection of all configuration structures declarations.
*/
[!NOCODE!]
[!CODE!]#define VIRT_WRAPPER_CONFIG_EXT \[!CR!][!ENDCODE!]
[!IF "var:defined('postBuildVariant')"!]
    [!VAR "variantIndex"="0"!][!//
    [!VAR "variantNumber"="variant:size()"!][!//
[!LOOP "variant:all()"!][!//
    [!VAR "variantIndex"="$variantIndex + 1"!][!//
    [!CODE!][!WS "4"!]VIRT_WRAPPER_CONFIG_[!"."!]_PB[!IF "$variantIndex < $variantNumber"!] \[!CR!][!ENDIF!][!ENDCODE!]
[!ENDLOOP!][!//
[!ELSE!][!//
    [!CODE!][!WS "4"!]VIRT_WRAPPER_CONFIG_PB[!ENDCODE!]
[!ENDIF!]
[!ENDNOCODE!][!//
[!ENDIF!]

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
                                       GLOBAL CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/


#ifdef __cplusplus
}
#endif /* __cplusplus */

/** @} */

#endif /* VIRT_WRAPPER_IP_CFG_H */

