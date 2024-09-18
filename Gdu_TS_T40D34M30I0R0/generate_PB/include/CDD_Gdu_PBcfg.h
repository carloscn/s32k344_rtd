/*==================================================================================================
*   Project              : RTD AUTOSAR 4.7
*   Platform             : CORTEXM
*   Peripheral           : IPV_GDU
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

#ifndef CDD_GDU[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_H
#define CDD_GDU[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_H

/**
*   @file    CDD_Gdu[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg.h
*   @version 3.0.0
*
*   @brief   AUTOSAR Gdu - HLD postbuild configuration header.
*
*   @addtogroup CDD_GDU
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
#include "CDD_Gdu_Types.h"

/*==================================================================================================
                               SOURCE FILE VERSION INFOGDUATION
==================================================================================================*/
#define GDU[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_VENDOR_ID                    43
#define GDU[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_AR_RELEASE_MAJOR_VERSION     4
#define GDU[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_AR_RELEASE_MINOR_VERSION     7
#define GDU[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_AR_RELEASE_REVISION_VERSION  0
#define GDU[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_SW_MAJOR_VERSION             3
#define GDU[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_SW_MINOR_VERSION             0
#define GDU[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_SW_PATCH_VERSION             0

/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/
/* Checks against CDD_Gdu_Types.h */
#if (GDU[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_VENDOR_ID != GDU_TYPES_VENDOR_ID)
    #error "CDD_Gdu[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg.h and CDD_Gdu_Types.h have different vendor ids"
#endif
#if ((GDU[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_AR_RELEASE_MAJOR_VERSION    != GDU_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (GDU[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_AR_RELEASE_MINOR_VERSION    != GDU_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (GDU[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_AR_RELEASE_REVISION_VERSION != GDU_TYPES_AR_RELEASE_REVISION_VERSION))
     #error "AUTOSAR Version Numbers of CDD_Gdu[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg.h and CDD_Gdu_Types.h are different"
#endif
#if ((GDU[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_SW_MAJOR_VERSION != GDU_TYPES_SW_MAJOR_VERSION) || \
     (GDU[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_SW_MINOR_VERSION != GDU_TYPES_SW_MINOR_VERSION) || \
     (GDU[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_SW_PATCH_VERSION != GDU_TYPES_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of CDD_Gdu[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg.h and CDD_Gdu_Types.h are different"
#endif

/*==================================================================================================
                                           CONSTANTS
==================================================================================================*/

/*==================================================================================================
                                       DEFINES AND MACROS
==================================================================================================*/
[!NOCODE!]
[!IF "(IMPLEMENTATION_CONFIG_VARIANT = 'VariantPreCompile') and (variant:size() <= 1)"!][!//

[!CODE!]
/** The configuration structure for CDD_GDU is the one from IPV_GDU */
#define GDU_CONFIG Gdu_Ip_xConfig
[!ENDCODE!][!//

[!ELSE!][!// (IMPLEMENTATION_CONFIG_VARIANT = 'VariantPreCompile') and (variant:size() <= 1)

[!VAR "VariantsNo" = "variant:size()"!]
[!IF "var:defined('postBuildVariant')"!][!//
    [!VAR "postBuildVariantNameUnderscore" = "concat('_',$postBuildVariant)"!][!//
[!ELSE!][!//
    [!VAR "postBuildVariantNameUnderscore" = "string(null)"!][!//
[!ENDIF!][!//

[!CODE!]
/** The configuration structure for CDD_GDU is the one from IPV_GDU */
#define GDU_CONFIG[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!] Gdu_Ip_xConfig[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][!CR!]
[!ENDCODE!][!//

[!CODE!]/** GDU configuration set */[!CR!][!ENDCODE!]
[!IF "var:defined('postBuildVariant')"!][!//
[!CODE!]#define GDU_CONFIG_[!"$postBuildVariant"!]_PB \[!CR!][!ENDCODE!]
[!ELSE!][!//
[!CODE!]#define GDU_CONFIG_PB \[!CR!][!ENDCODE!]
[!ENDIF!][!//
[!CODE!][!WS4!]extern const Gdu_Ip_ConfigType GDU_CONFIG[!"$postBuildVariantNameUnderscore"!];[!ENDCODE!]
[!ENDIF!][!// (IMPLEMENTATION_CONFIG_VARIANT = 'VariantPreCompile') and (variant:size() <= 1)
[!ENDNOCODE!][!//


/*==================================================================================================
                                             ENUMS
==================================================================================================*/

/*==================================================================================================
                                 STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
                                     FUNCTION PROTOTYPES
==================================================================================================*/

#ifdef __cplusplus
}
#endif

/** @} */

#endif    /* CDD_GDU[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_H */
