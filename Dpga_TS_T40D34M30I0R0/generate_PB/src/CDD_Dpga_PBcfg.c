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

/**
*   @file
*
*   @addtogroup dpga_driver_config Dpga Driver Configuration
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
[!NOCODE!][!//
[!INCLUDE "Dpga_RegOperations.m"!][!//
[!CODE!]#include "CDD_Dpga[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg.h"[!CR!][!ENDCODE!]
[!CODE!]#include "Dpga_Ip[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg.h"[!CR!][!ENDCODE!]
[!ENDNOCODE!][!//

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define DPGA_VENDOR_ID_[!IF "var:defined('postBuildVariant')"!][!"text:toupper($postBuildVariant)"!]_[!ENDIF!]PBCFG_C                       43
#define DPGA_AR_RELEASE_MAJOR_VERSION_[!IF "var:defined('postBuildVariant')"!][!"text:toupper($postBuildVariant)"!]_[!ENDIF!]PBCFG_C        4
#define DPGA_AR_RELEASE_MINOR_VERSION_[!IF "var:defined('postBuildVariant')"!][!"text:toupper($postBuildVariant)"!]_[!ENDIF!]PBCFG_C        7
#define DPGA_AR_RELEASE_REVISION_VERSION_[!IF "var:defined('postBuildVariant')"!][!"text:toupper($postBuildVariant)"!]_[!ENDIF!]PBCFG_C     0
#define DPGA_SW_MAJOR_VERSION_[!IF "var:defined('postBuildVariant')"!][!"text:toupper($postBuildVariant)"!]_[!ENDIF!]PBCFG_C                3
#define DPGA_SW_MINOR_VERSION_[!IF "var:defined('postBuildVariant')"!][!"text:toupper($postBuildVariant)"!]_[!ENDIF!]PBCFG_C                0
#define DPGA_SW_PATCH_VERSION_[!IF "var:defined('postBuildVariant')"!][!"text:toupper($postBuildVariant)"!]_[!ENDIF!]PBCFG_C                0

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and CDD_Dpga[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg header file are of the same vendor */
#if (DPGA_VENDOR_ID_[!IF "var:defined('postBuildVariant')"!][!"text:toupper($postBuildVariant)"!]_[!ENDIF!]PBCFG_C != DPGA_VENDOR_ID_[!IF "var:defined('postBuildVariant')"!][!"text:toupper($postBuildVariant)"!]_[!ENDIF!]PBCFG)
    #error "CDD_Dpga[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg.c and CDD_Dpga[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg.h have different vendor ids"
#endif

/* Check if current file and CDD_Dpga[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg header file are of the same Autosar version */
#if ((DPGA_AR_RELEASE_MAJOR_VERSION_[!IF "var:defined('postBuildVariant')"!][!"text:toupper($postBuildVariant)"!]_[!ENDIF!]PBCFG_C     != DPGA_AR_RELEASE_MAJOR_VERSION_[!IF "var:defined('postBuildVariant')"!][!"text:toupper($postBuildVariant)"!]_[!ENDIF!]PBCFG) || \
     (DPGA_AR_RELEASE_MINOR_VERSION_[!IF "var:defined('postBuildVariant')"!][!"text:toupper($postBuildVariant)"!]_[!ENDIF!]PBCFG_C     != DPGA_AR_RELEASE_MINOR_VERSION_[!IF "var:defined('postBuildVariant')"!][!"text:toupper($postBuildVariant)"!]_[!ENDIF!]PBCFG) || \
     (DPGA_AR_RELEASE_REVISION_VERSION_[!IF "var:defined('postBuildVariant')"!][!"text:toupper($postBuildVariant)"!]_[!ENDIF!]PBCFG_C  != DPGA_AR_RELEASE_REVISION_VERSION_[!IF "var:defined('postBuildVariant')"!][!"text:toupper($postBuildVariant)"!]_[!ENDIF!]PBCFG))
    #error "AutoSar Version Numbers of CDD_Dpga[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg.c and CDD_Dpga[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg.h are different"
#endif

/* Check if current file and CDD_Dpga[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg header file are of the same software version */
#if ((DPGA_SW_MAJOR_VERSION_[!IF "var:defined('postBuildVariant')"!][!"text:toupper($postBuildVariant)"!]_[!ENDIF!]PBCFG_C != DPGA_SW_MAJOR_VERSION_[!IF "var:defined('postBuildVariant')"!][!"text:toupper($postBuildVariant)"!]_[!ENDIF!]PBCFG) || \
     (DPGA_SW_MINOR_VERSION_[!IF "var:defined('postBuildVariant')"!][!"text:toupper($postBuildVariant)"!]_[!ENDIF!]PBCFG_C != DPGA_SW_MINOR_VERSION_[!IF "var:defined('postBuildVariant')"!][!"text:toupper($postBuildVariant)"!]_[!ENDIF!]PBCFG) || \
     (DPGA_SW_PATCH_VERSION_[!IF "var:defined('postBuildVariant')"!][!"text:toupper($postBuildVariant)"!]_[!ENDIF!]PBCFG_C != DPGA_SW_PATCH_VERSION_[!IF "var:defined('postBuildVariant')"!][!"text:toupper($postBuildVariant)"!]_[!ENDIF!]PBCFG))
    #error "Software Version Numbers of CDD_Dpga[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg.c and CDD_Dpga[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg.h are different"
#endif

/* Check if current file and Dpga_Ip[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg header file are of the same vendor */
#if (DPGA_VENDOR_ID_[!IF "var:defined('postBuildVariant')"!][!"text:toupper($postBuildVariant)"!]_[!ENDIF!]PBCFG_C != DPGA_IP_VENDOR_ID_[!IF "var:defined('postBuildVariant')"!][!"text:toupper($postBuildVariant)"!]_[!ENDIF!]PBCFG)
    #error "CDD_Dpga[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg.c and Dpga_Ip[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg.h have different vendor ids"
#endif

/* Check if current file and Dpga_Ip[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg header file are of the same Autosar version */
#if ((DPGA_AR_RELEASE_MAJOR_VERSION_[!IF "var:defined('postBuildVariant')"!][!"text:toupper($postBuildVariant)"!]_[!ENDIF!]PBCFG_C     != DPGA_IP_AR_RELEASE_MAJOR_VERSION_[!IF "var:defined('postBuildVariant')"!][!"text:toupper($postBuildVariant)"!]_[!ENDIF!]PBCFG) || \
     (DPGA_AR_RELEASE_MINOR_VERSION_[!IF "var:defined('postBuildVariant')"!][!"text:toupper($postBuildVariant)"!]_[!ENDIF!]PBCFG_C     != DPGA_IP_AR_RELEASE_MINOR_VERSION_[!IF "var:defined('postBuildVariant')"!][!"text:toupper($postBuildVariant)"!]_[!ENDIF!]PBCFG) || \
     (DPGA_AR_RELEASE_REVISION_VERSION_[!IF "var:defined('postBuildVariant')"!][!"text:toupper($postBuildVariant)"!]_[!ENDIF!]PBCFG_C  != DPGA_IP_AR_RELEASE_REVISION_VERSION_[!IF "var:defined('postBuildVariant')"!][!"text:toupper($postBuildVariant)"!]_[!ENDIF!]PBCFG))
    #error "AutoSar Version Numbers of CDD_Dpga[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg.c and Dpga_Ip[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg.h are different"
#endif

/* Check if current file and Dpga_Ip[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg header file are of the same software version */
#if ((DPGA_SW_MAJOR_VERSION_[!IF "var:defined('postBuildVariant')"!][!"text:toupper($postBuildVariant)"!]_[!ENDIF!]PBCFG_C != DPGA_IP_SW_MAJOR_VERSION_[!IF "var:defined('postBuildVariant')"!][!"text:toupper($postBuildVariant)"!]_[!ENDIF!]PBCFG) || \
     (DPGA_SW_MINOR_VERSION_[!IF "var:defined('postBuildVariant')"!][!"text:toupper($postBuildVariant)"!]_[!ENDIF!]PBCFG_C != DPGA_IP_SW_MINOR_VERSION_[!IF "var:defined('postBuildVariant')"!][!"text:toupper($postBuildVariant)"!]_[!ENDIF!]PBCFG) || \
     (DPGA_SW_PATCH_VERSION_[!IF "var:defined('postBuildVariant')"!][!"text:toupper($postBuildVariant)"!]_[!ENDIF!]PBCFG_C != DPGA_IP_SW_PATCH_VERSION_[!IF "var:defined('postBuildVariant')"!][!"text:toupper($postBuildVariant)"!]_[!ENDIF!]PBCFG))
    #error "Software Version Numbers of CDD_Dpga[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg.c and Dpga_Ip[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg.h are different"
#endif

/*==================================================================================================
*                           LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
*                                          LOCAL MACROS
==================================================================================================*/

/*==================================================================================================
*                                         LOCAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                         LOCAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                        GLOBAL CONSTANTS
==================================================================================================*/
#define DPGA_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Dpga_MemMap.h"

[!CALL "CDD_Dpga_Config" , "MacroGenerationType" = "'definition_precompile'"!][!//

#define DPGA_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Dpga_MemMap.h"

/*==================================================================================================
*                                        GLOBAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                    LOCAL FUNCTION PROTOTYPES
==================================================================================================*/

/*==================================================================================================
*                                         LOCAL FUNCTIONS
==================================================================================================*/

/*==================================================================================================
*                                        GLOBAL FUNCTIONS
==================================================================================================*/

#ifdef __cplusplus
}
#endif

/** @} */