/*==================================================================================================
*   Project              : RTD AUTOSAR 4.7
*   Platform             : CORTEXM
*   Peripheral           : DPGA
*   Dependencies         : none
*
*   Autosar Version      : 4.7.0
*   Autosar Revision     : ASR_REL_4_7_REV_0000
*   Autosar Conf.Variant :
*   SW Version           : 3.0.0
*   Build Version        : S32K3_RTD_3_0_0_D2303_ASR_REL_4_7_REV_0000_20230331
*
*   Copyright 2022 NXP
*
*   NXP Confidential. This software is owned or controlled by NXP and may only be
*   used strictly in accordance with the applicable license terms. By expressly
*   accepting such terms or by downloading, installing, activating and/or otherwise
*   using the software, you are agreeing that you have read, and that you agree to
*   comply with and are bound by, such license terms. If you do not agree to be
*   bound by the applicable license terms, then you may not retain, install,
*   activate or otherwise use the software.
==================================================================================================*/

[!CODE!][!//
#ifndef DPGA_IP_[!IF "var:defined('postBuildVariant')"!][!"text:toupper($postBuildVariant)"!]_[!ENDIF!]PBCFG_H
#define DPGA_IP_[!IF "var:defined('postBuildVariant')"!][!"text:toupper($postBuildVariant)"!]_[!ENDIF!]PBCFG_H
[!ENDCODE!][!//

/**
*   @file
*
*   @addtogroup dpga_ip_config Dpga IPL Configuration
*   @{
*/

#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
*                                          INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Dpga_Ip_Types.h"

[!NOCODE!][!//
[!INCLUDE "Dpga_RegOperations.m"!][!//
[!ENDNOCODE!][!//
/*==================================================================================================
*                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define  DPGA_IP_VENDOR_ID_[!IF "var:defined('postBuildVariant')"!][!"text:toupper($postBuildVariant)"!]_[!ENDIF!]PBCFG                    43
#define  DPGA_IP_AR_RELEASE_MAJOR_VERSION_[!IF "var:defined('postBuildVariant')"!][!"text:toupper($postBuildVariant)"!]_[!ENDIF!]PBCFG     4
#define  DPGA_IP_AR_RELEASE_MINOR_VERSION_[!IF "var:defined('postBuildVariant')"!][!"text:toupper($postBuildVariant)"!]_[!ENDIF!]PBCFG     7
#define  DPGA_IP_AR_RELEASE_REVISION_VERSION_[!IF "var:defined('postBuildVariant')"!][!"text:toupper($postBuildVariant)"!]_[!ENDIF!]PBCFG  0
#define  DPGA_IP_SW_MAJOR_VERSION_[!IF "var:defined('postBuildVariant')"!][!"text:toupper($postBuildVariant)"!]_[!ENDIF!]PBCFG             3
#define  DPGA_IP_SW_MINOR_VERSION_[!IF "var:defined('postBuildVariant')"!][!"text:toupper($postBuildVariant)"!]_[!ENDIF!]PBCFG             0
#define  DPGA_IP_SW_PATCH_VERSION_[!IF "var:defined('postBuildVariant')"!][!"text:toupper($postBuildVariant)"!]_[!ENDIF!]PBCFG             0

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and Dpga_Ip_Types header file are of the same vendor */
#if (DPGA_IP_VENDOR_ID_[!IF "var:defined('postBuildVariant')"!][!"text:toupper($postBuildVariant)"!]_[!ENDIF!]PBCFG != DPGA_IP_VENDOR_ID_TYPES)
    #error "Dpga_Ip[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg.h and Dpga_Ip_Types.h have different vendor ids"
#endif

/* Check if current file and Dpga_Ip_Types header file are of the same Autosar version */
#if ((DPGA_IP_AR_RELEASE_MAJOR_VERSION_[!IF "var:defined('postBuildVariant')"!][!"text:toupper($postBuildVariant)"!]_[!ENDIF!]PBCFG     != DPGA_IP_AR_RELEASE_MAJOR_VERSION_TYPES) || \
     (DPGA_IP_AR_RELEASE_MINOR_VERSION_[!IF "var:defined('postBuildVariant')"!][!"text:toupper($postBuildVariant)"!]_[!ENDIF!]PBCFG     != DPGA_IP_AR_RELEASE_MINOR_VERSION_TYPES) || \
     (DPGA_IP_AR_RELEASE_REVISION_VERSION_[!IF "var:defined('postBuildVariant')"!][!"text:toupper($postBuildVariant)"!]_[!ENDIF!]PBCFG  != DPGA_IP_AR_RELEASE_REVISION_VERSION_TYPES))
    #error "AutoSar Version Numbers of Dpga_Ip[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg.h and Dpga_Ip_Types.h are different"
#endif

/* Check if current file and Dpga_Ip_Types header file are of the same software version */
#if ((DPGA_IP_SW_MAJOR_VERSION_[!IF "var:defined('postBuildVariant')"!][!"text:toupper($postBuildVariant)"!]_[!ENDIF!]PBCFG != DPGA_IP_SW_MAJOR_VERSION_TYPES) || \
     (DPGA_IP_SW_MINOR_VERSION_[!IF "var:defined('postBuildVariant')"!][!"text:toupper($postBuildVariant)"!]_[!ENDIF!]PBCFG != DPGA_IP_SW_MINOR_VERSION_TYPES) || \
     (DPGA_IP_SW_PATCH_VERSION_[!IF "var:defined('postBuildVariant')"!][!"text:toupper($postBuildVariant)"!]_[!ENDIF!]PBCFG != DPGA_IP_SW_PATCH_VERSION_TYPES))
    #error "Software Version Numbers of Dpga_Ip[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg.h and Dpga_Ip_Types.h are different"
#endif

/*==================================================================================================
*                                            CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/

/*==================================================================================================
*                                              ENUMS
==================================================================================================*/

/*==================================================================================================
*                                  STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
*                                  GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/
#define DPGA_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Dpga_MemMap.h"
[!//
[!CALL "Dpga_Ip_Config" , "MacroGenerationType" = "'declaration_config'"!][!//
[!//
#define DPGA_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Dpga_MemMap.h"

/*==================================================================================================
*                                       FUNCTION PROTOTYPES
==================================================================================================*/
#define DPGA_START_SEC_CODE
#include "Dpga_MemMap.h"

[!CALL "Dpga_Ip_Config" , "MacroGenerationType" = "'declaration_callback'"!][!//

#define DPGA_STOP_SEC_CODE
#include "Dpga_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */

[!CODE!][!//
#endif /* DPGA_IP_[!IF "var:defined('postBuildVariant')"!][!"text:toupper($postBuildVariant)"!]_[!ENDIF!]PBCFG_H */
[!ENDCODE!][!//
