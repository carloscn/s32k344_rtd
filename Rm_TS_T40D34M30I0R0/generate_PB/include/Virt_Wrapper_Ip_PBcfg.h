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

#ifndef VIRT_WRAPPER_IP_PBCFG[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_H
#define VIRT_WRAPPER_IP_PBCFG[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_H

/**
*   @file Virt_Wrapper_Ip_PBcfg.h
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
#include "Virt_Wrapper_Ip_Types.h"

/*==================================================================================================
                                SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define RM_VIRT_WRAPPER_IP_PBCFG[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_VENDOR_ID                     43
#define RM_VIRT_WRAPPER_IP_PBCFG[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_AR_RELEASE_MAJOR_VERSION      4
#define RM_VIRT_WRAPPER_IP_PBCFG[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_AR_RELEASE_MINOR_VERSION      7
#define RM_VIRT_WRAPPER_IP_PBCFG[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_AR_RELEASE_REVISION_VERSION   0
#define RM_VIRT_WRAPPER_IP_PBCFG[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_SW_MAJOR_VERSION              3
#define RM_VIRT_WRAPPER_IP_PBCFG[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_SW_MINOR_VERSION              0
#define RM_VIRT_WRAPPER_IP_PBCFG[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_SW_PATCH_VERSION              0

/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/
/* Checks against Virt_Wrapper_Ip_Types.h */
#if (RM_VIRT_WRAPPER_IP_PBCFG[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_VENDOR_ID != RM_VIRT_WRAPPER_IP_TYPES_VENDOR_ID)
    #error "Virt_Wrapper_Ip[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg.h and Virt_Wrapper_Ip_Types.h have different vendor ids"
#endif
#if ((RM_VIRT_WRAPPER_IP_PBCFG[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_AR_RELEASE_MAJOR_VERSION    != RM_VIRT_WRAPPER_IP_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (RM_VIRT_WRAPPER_IP_PBCFG[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_AR_RELEASE_MINOR_VERSION    != RM_VIRT_WRAPPER_IP_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (RM_VIRT_WRAPPER_IP_PBCFG[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_AR_RELEASE_REVISION_VERSION != RM_VIRT_WRAPPER_IP_TYPES_AR_RELEASE_REVISION_VERSION))
     #error "AUTOSAR Version Numbers of Virt_Wrapper_Ip[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg.h and Virt_Wrapper_Ip_Types.h are different"
#endif
#if ((RM_VIRT_WRAPPER_IP_PBCFG[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_SW_MAJOR_VERSION != RM_VIRT_WRAPPER_IP_TYPES_SW_MAJOR_VERSION) || \
     (RM_VIRT_WRAPPER_IP_PBCFG[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_SW_MINOR_VERSION != RM_VIRT_WRAPPER_IP_TYPES_SW_MINOR_VERSION) || \
     (RM_VIRT_WRAPPER_IP_PBCFG[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_SW_PATCH_VERSION != RM_VIRT_WRAPPER_IP_TYPES_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Virt_Wrapper_Ip[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg.h and Virt_Wrapper_Ip_Types.h are different"
#endif

/*==================================================================================================
                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
                                        LOCAL MACROS
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

[!NOCODE!]
[!IF "var:defined('postBuildVariant')"!][!//
  [!VAR "postBuildVariantNameUnderscore" = "concat('_',$postBuildVariant)"!][!//
[!IF "RmGeneral/RmVirtWrapperConfigurable"!]
[!CODE!]#define VIRT_WRAPPER_CONFIG_[!"$postBuildVariant"!]_PB \[!CR!][!ENDCODE!]
[!ELSE!]
[!CODE!]#define VIRT_WRAPPER_CONFIG_[!"$postBuildVariant"!]_PB[!CR!][!ENDCODE!]
[!ENDIF!]
[!ELSE!][!//
  [!VAR "postBuildVariantNameUnderscore" = "string(null)"!][!//
[!IF "RmGeneral/RmVirtWrapperConfigurable"!]
[!CODE!]#define VIRT_WRAPPER_CONFIG_PB \[!CR!][!ENDCODE!]
[!ELSE!]
[!CODE!]#define VIRT_WRAPPER_CONFIG_PB[!CR!][!ENDCODE!]
[!ENDIF!]
[!ENDIF!][!//
[!IF "RmGeneral/RmVirtWrapperConfigurable"!]
[!CODE!][!//
[!WS4!]   extern const Virt_Wrapper_Ip_ConfigType Virt_Wrapper_Ip_Config[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!];
[!ENDCODE!]
[!ENDIF!]
[!ENDNOCODE!]

/*==================================================================================================
                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/

/*==================================================================================================
                                       LOCAL FUNCTIONS
==================================================================================================*/

/*==================================================================================================
                                       GLOBAL FUNCTIONS
==================================================================================================*/

#ifdef __cplusplus
}
#endif

/** @} */

#endif /* VIRT_WRAPPER_IP_PBCFG[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_H */

