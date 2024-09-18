/*==================================================================================================
*   Project              : RTD AUTOSAR 4.7
*   Platform             : CORTEXM
*   Peripheral           : Swt
*   Dependencies         : none
*
*   Autosar Version      : 4.7.0
*   Autosar Revision     : ASR_REL_4_7_REV_0000
*   Autosar Conf.Variant :
*   SW Version           : 3.0.0
*   Build Version        : S32K3_RTD_3_0_0_D2303_ASR_REL_4_7_REV_0000_20230331
*
*   Copyright 2020 - 2023 NXP Semiconductors
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

/**
*   @file
*
*   @addtogroup AeWdog_Ip
*   @{
*/

#ifdef __cplusplus
extern "C"{
#endif

[!INCLUDE "Wdg_PluginMacros.m"!][!//
/*==================================================================================================
*                                          INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/

#include "AeWdog_Ip_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBcfg.h"

/*==================================================================================================
*                                 SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define AEWDOG_IP_PBCFG_VENDOR_ID_C                      43
#define AEWDOG_IP_PBCFG_AR_RELEASE_MAJOR_VERSION_C       4
#define AEWDOG_IP_PBCFG_AR_RELEASE_MINOR_VERSION_C       7
#define AEWDOG_IP_PBCFG_AR_RELEASE_REVISION_VERSION_C    0
#define AEWDOG_IP_PBCFG_SW_MAJOR_VERSION_C               3
#define AEWDOG_IP_PBCFG_SW_MINOR_VERSION_C               0
#define AEWDOG_IP_PBCFG_SW_PATCH_VERSION_C               0

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and AeWdog_Ip_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBcfg header file are of the same vendor */
#if (AEWDOG_IP_PBCFG_VENDOR_ID_C != AEWDOG_IP_PBCFG_VENDOR_ID)
#error "AeWdog_Ip_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBcfg.c and AeWdog_Ip_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBcfg.h have different vendor ids"
#endif

/* Check if current file and AeWdog_Ip_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBcfg header file are of the same Autosar version */
#if ((AEWDOG_IP_PBCFG_AR_RELEASE_MAJOR_VERSION_C    != AEWDOG_IP_PBCFG_AR_RELEASE_MAJOR_VERSION   ) || \
     (AEWDOG_IP_PBCFG_AR_RELEASE_MINOR_VERSION_C    != AEWDOG_IP_PBCFG_AR_RELEASE_MINOR_VERSION   ) || \
     (AEWDOG_IP_PBCFG_AR_RELEASE_REVISION_VERSION_C != AEWDOG_IP_PBCFG_AR_RELEASE_REVISION_VERSION))
#error "AutoSar Version Numbers of AeWdog_Ip_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBcfg.c and AeWdog_Ip_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBcfg.h are different"
#endif

/* Check if current file and AeWdog_Ip_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBcfg header file are of the same software version */
#if ((AEWDOG_IP_PBCFG_SW_MAJOR_VERSION_C != AEWDOG_IP_PBCFG_SW_MAJOR_VERSION) || \
     (AEWDOG_IP_PBCFG_SW_MINOR_VERSION_C != AEWDOG_IP_PBCFG_SW_MINOR_VERSION) || \
     (AEWDOG_IP_PBCFG_SW_PATCH_VERSION_C != AEWDOG_IP_PBCFG_SW_PATCH_VERSION))
#error "Software Version Numbers of AeWdog_Ip_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBcfg.c and AeWdog_Ip_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBcfg.h are different"
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

/*==================================================================================================
*                                        GLOBAL VARIABLES
==================================================================================================*/

#define WDG_START_SEC_CONFIG_DATA_UNSPECIFIED

#include "Wdg_MemMap.h"

[!AUTOSPACING!]

[!NOCODE!]
[!INDENT "0"!]
[!FOR "i" = "0" TO "count(ecu:list('Wdg.WdgInstance')) - 1"!]
    [!VAR "xPathModule" = "concat('./../../../Wdg_43_Instance',$i,'/ELEMENTS/Wdg')"!]
    [!IF "node:exists($xPathModule)"!]
        [!IF "ecu:list('Wdg.WdgInstance')[$i + 1] ='AEWDOG'"!]
            [!CODE!]
            const AeWdog_Ip_ConfigType AeWdog_Ip_Settings[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]=
            {
            [!CALL "AeWdogConfig", "WdgNo" = "$xPathModule"!]
            };
            [!ENDCODE!]
        [!ENDIF!]
    [!ENDIF!]
[!ENDFOR!]
[!ENDINDENT!]
[!ENDNOCODE!][!//


#define WDG_STOP_SEC_CONFIG_DATA_UNSPECIFIED

#include "Wdg_MemMap.h"

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
