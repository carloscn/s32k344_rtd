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

#ifndef AEWDOG_IP_PBCFG_H
#define AEWDOG_IP_PBCFG_H

/**
*   @file
*
*   @addtogroup AeWdog_Ip
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

#include "AeWdog_Ip_Cfg_Defines.h"
#include "AeWdog_Ip_Types.h"

/*==================================================================================================
*                                 SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define AEWDOG_IP_PBCFG_VENDOR_ID                    43
#define AEWDOG_IP_PBCFG_MODULE_ID                    102
#define AEWDOG_IP_PBCFG_AR_RELEASE_MAJOR_VERSION     4
#define AEWDOG_IP_PBCFG_AR_RELEASE_MINOR_VERSION     7
#define AEWDOG_IP_PBCFG_AR_RELEASE_REVISION_VERSION  0
#define AEWDOG_IP_PBCFG_SW_MAJOR_VERSION             3
#define AEWDOG_IP_PBCFG_SW_MINOR_VERSION             0
#define AEWDOG_IP_PBCFG_SW_PATCH_VERSION             0

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/
/* Check if AeWdog_Ip_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBcfg.h and AeWdog_Ip_Cfg_Defines.h are of the same vendor */
#if (AEWDOG_IP_PBCFG_VENDOR_ID != AEWDOG_IP_CFG_DEFINES_VENDOR_ID)
#error "AeWdog_Ip_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBcfg.h and AeWdog_Ip_Cfg_Defines.h have different vendor ids"
#endif

/* Check if AeWdog_Ip_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBcfg.h and AeWdog_Ip_Cfg_Defines.h are of the same Autosar version */
#if ((AEWDOG_IP_PBCFG_AR_RELEASE_MAJOR_VERSION    != AEWDOG_IP_CFG_DEFINES_AR_RELEASE_MAJOR_VERSION) || \
     (AEWDOG_IP_PBCFG_AR_RELEASE_MINOR_VERSION    != AEWDOG_IP_CFG_DEFINES_AR_RELEASE_MINOR_VERSION) || \
     (AEWDOG_IP_PBCFG_AR_RELEASE_REVISION_VERSION != AEWDOG_IP_CFG_DEFINES_AR_RELEASE_REVISION_VERSION) \
    )
#error "AutoSar Version Numbers of AeWdog_Ip_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBcfg.h and AeWdog_Ip_Cfg_Defines.h are different"
#endif

/* Check if AeWdog_Ip_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBcfg.h and AeWdog_Ip_Cfg_Defines.h are of the same Software version */
#if ((AEWDOG_IP_PBCFG_SW_MAJOR_VERSION != AEWDOG_IP_CFG_DEFINES_SW_MAJOR_VERSION) || \
     (AEWDOG_IP_PBCFG_SW_MINOR_VERSION != AEWDOG_IP_CFG_DEFINES_SW_MINOR_VERSION) || \
     (AEWDOG_IP_PBCFG_SW_PATCH_VERSION != AEWDOG_IP_CFG_DEFINES_SW_PATCH_VERSION) \
    )
#error "Software Version Numbers of AeWdog_Ip_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBcfg.h and AeWdog_Ip_Cfg_Defines.h are different"
#endif

/* Check if AeWdog_Ip_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBcfg.h and AeWdog_Ip_Types.h are of the same vendor */
#if (AEWDOG_IP_PBCFG_VENDOR_ID != AEWDOG_IP_TYPES_VENDOR_ID)
#error "AeWdog_Ip_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBcfg.h and AeWdog_Ip_Types.h have different vendor ids"
#endif

/* Check if AeWdog_Ip_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBcfg.h and AeWdog_Ip_Types.h are of the same Autosar version */
#if ((AEWDOG_IP_PBCFG_AR_RELEASE_MAJOR_VERSION    != AEWDOG_IP_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (AEWDOG_IP_PBCFG_AR_RELEASE_MINOR_VERSION    != AEWDOG_IP_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (AEWDOG_IP_PBCFG_AR_RELEASE_REVISION_VERSION != AEWDOG_IP_TYPES_AR_RELEASE_REVISION_VERSION) \
    )
#error "AutoSar Version Numbers of AeWdog_Ip_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBcfg.h and AeWdog_Ip_Types.h are different"
#endif

/* Check if AeWdog_Ip_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBcfg.h and AeWdog_Ip_Types.h are of the same Software version */
#if ((AEWDOG_IP_PBCFG_SW_MAJOR_VERSION != AEWDOG_IP_TYPES_SW_MAJOR_VERSION) || \
     (AEWDOG_IP_PBCFG_SW_MINOR_VERSION != AEWDOG_IP_TYPES_SW_MINOR_VERSION) || \
     (AEWDOG_IP_PBCFG_SW_PATCH_VERSION != AEWDOG_IP_TYPES_SW_PATCH_VERSION) \
    )
#error "Software Version Numbers of AeWdog_Ip_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBcfg.h and AeWdog_Ip_Types.h are different"
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

#define WDG_START_SEC_CONFIG_DATA_UNSPECIFIED

#include "Wdg_MemMap.h"
[!NOCODE!]
[!INDENT "0"!]
[!FOR "i" = "0" TO "count(ecu:list('Wdg.WdgInstance')) - 1"!]
    [!VAR "xPathModule" = "concat('./../../../Wdg_43_Instance',$i,'/ELEMENTS/Wdg')"!]
    [!IF "node:exists($xPathModule)"!]
        [!IF "ecu:list('Wdg.WdgInstance')[$i + 1] ='AEWDOG'"!]
            [!CODE!]extern const AeWdog_Ip_ConfigType AeWdog_Ip_Settings[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!];[!ENDCODE!][!CR!]
        [!ENDIF!]
    [!ENDIF!]
[!ENDFOR!]
[!ENDINDENT!]
[!ENDNOCODE!][!//

#define WDG_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Wdg_MemMap.h"

/*==================================================================================================
*                                       FUNCTION PROTOTYPES
==================================================================================================*/


#ifdef __cplusplus
}
#endif

/** @} */

#endif /* AEWDOG_IP_PBCFG_H */
