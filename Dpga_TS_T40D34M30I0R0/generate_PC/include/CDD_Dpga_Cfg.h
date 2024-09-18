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

#ifndef CDD_DPGA_CFG_H
#define CDD_DPGA_CFG_H

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
#include "StandardTypes.h"
[!NOCODE!][!//
[!IF "var:defined('postBuildVariant')"!]
[!LOOP "variant:all()"!]
[!CODE!]#include "CDD_Dpga_[!"."!]_PBcfg.h"[!CR!][!ENDCODE!]
[!ENDLOOP!]
[!ELSE!]
[!CODE!]#include "CDD_Dpga_PBcfg.h"[!CR!][!ENDCODE!]
[!ENDIF!]
[!ENDNOCODE!][!//

/*==================================================================================================
*                                 SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define DPGA_VENDOR_ID_CFG                       43
#define DPGA_AR_RELEASE_MAJOR_VERSION_CFG        4
#define DPGA_AR_RELEASE_MINOR_VERSION_CFG        7
#define DPGA_AR_RELEASE_REVISION_VERSION_CFG     0
#define DPGA_SW_MAJOR_VERSION_CFG                3
#define DPGA_SW_MINOR_VERSION_CFG                0
#define DPGA_SW_PATCH_VERSION_CFG                0

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
/* Check if current file and StandardTypes header file are of the same Autosar version */
#if ((DPGA_AR_RELEASE_MAJOR_VERSION_CFG     != STD_AR_RELEASE_MAJOR_VERSION) || \
     (DPGA_AR_RELEASE_MINOR_VERSION_CFG     != STD_AR_RELEASE_MINOR_VERSION))
    #error "AutoSar Version Numbers of CDD_Dpga_Cfg.h and StandardTypes.h are different"
#endif
#endif /* DISABLE_MCAL_INTERMODULE_ASR_CHECK */

[!IF "var:defined('postBuildVariant')"!][!//
[!LOOP "variant:all()"!][!//
/* Check if current file and CDD_Dpga_[!"."!]_PBcfg header file are of the same vendor */
#if (DPGA_VENDOR_ID_CFG != DPGA_VENDOR_ID_[!"text:toupper(.)"!]_PBCFG)
    #error "CDD_Dpga_Cfg.h and CDD_Dpga_[!"."!]_PBcfg.h have different vendor IDs"
#endif

/* Check if current file and CDD_Dpga_[!"."!]_PBcfg header file are of the same Autosar version */
#if ((DPGA_AR_RELEASE_MAJOR_VERSION_CFG     != DPGA_AR_RELEASE_MAJOR_VERSION_[!"text:toupper(.)"!]_PBCFG) || \
     (DPGA_AR_RELEASE_MINOR_VERSION_CFG     != DPGA_AR_RELEASE_MINOR_VERSION_[!"text:toupper(.)"!]_PBCFG) || \
     (DPGA_AR_RELEASE_REVISION_VERSION_CFG  != DPGA_AR_RELEASE_REVISION_VERSION_[!"text:toupper(.)"!]_PBCFG))
    #error "AutoSar Version Numbers of CDD_Dpga_Cfg.h and CDD_Dpga_[!"."!]_PBcfg.h are different"
#endif

/* Check if current file and CDD_Dpga_[!"."!]_PBcfg header file are of the same software version */
#if ((DPGA_SW_MAJOR_VERSION_CFG != DPGA_SW_MAJOR_VERSION_[!"text:toupper(.)"!]_PBCFG) || \
     (DPGA_SW_MINOR_VERSION_CFG != DPGA_SW_MINOR_VERSION_[!"text:toupper(.)"!]_PBCFG) || \
     (DPGA_SW_PATCH_VERSION_CFG != DPGA_SW_PATCH_VERSION_[!"text:toupper(.)"!]_PBCFG))
    #error "Software Version Numbers of CDD_Dpga_Cfg.h and CDD_Dpga_[!"."!]_PBcfg.h are different"
#endif
[!ENDLOOP!][!//
[!ELSE!][!//
/* Check if current file and CDD_Dpga_PBcfg header file are of the same vendor */
#if (DPGA_VENDOR_ID_CFG != DPGA_VENDOR_ID_PBCFG)
    #error "CDD_Dpga_Cfg.h and CDD_Dpga_PBcfg.h have different vendor IDs"
#endif

/* Check if current file and CDD_Dpga_PBcfg header file are of the same Autosar version */
#if ((DPGA_AR_RELEASE_MAJOR_VERSION_CFG    != DPGA_AR_RELEASE_MAJOR_VERSION_PBCFG) || \
     (DPGA_AR_RELEASE_MINOR_VERSION_CFG    != DPGA_AR_RELEASE_MINOR_VERSION_PBCFG) || \
     (DPGA_AR_RELEASE_REVISION_VERSION_CFG != DPGA_AR_RELEASE_REVISION_VERSION_PBCFG))
    #error "AutoSar Version Numbers of CDD_Dpga_Cfg.h and CDD_Dpga_PBcfg.h are different"
#endif

/* Check if current file and CDD_Dpga_PBcfg header file are of the same software version */
#if ((DPGA_SW_MAJOR_VERSION_CFG != DPGA_SW_MAJOR_VERSION_PBCFG) || \
     (DPGA_SW_MINOR_VERSION_CFG != DPGA_SW_MINOR_VERSION_PBCFG) || \
     (DPGA_SW_PATCH_VERSION_CFG != DPGA_SW_PATCH_VERSION_PBCFG))
    #error "Software Version Numbers of CDD_Dpga_Cfg.h and CDD_Dpga_PBcfg.h are different"
#endif
[!ENDIF!][!//

/*==================================================================================================
*                                            CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/
[!IF "not((IMPLEMENTATION_CONFIG_VARIANT = 'VariantPreCompile') and (variant:size() <= 1))"!][!//
#define DPGA_CONFIG_EXT \
[!IF "var:defined('postBuildVariant')"!][!//
[!LOOP "variant:all()"!][!//
DPGA_CONFIG_[!"."!]_PB \
[!ENDLOOP!][!//
[!ELSE!][!//
DPGA_CONFIG_PB
[!ENDIF!][!//
[!ENDIF!]
/*==================================================================================================
*                                              ENUMS
==================================================================================================*/

/*==================================================================================================
*                                  STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
*                                  GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                       FUNCTION PROTOTYPES
==================================================================================================*/

#ifdef __cplusplus
}
#endif

/** @} */

#endif /* CDD_DPGA_CFG_H */
