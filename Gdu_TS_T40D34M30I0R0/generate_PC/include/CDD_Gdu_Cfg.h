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

#ifndef CDD_GDU_CFG_H
#define CDD_GDU_CFG_H

/**
*   @file    CDD_Gdu_Cfg.h
*   @version 3.0.0
*
*   @brief   AUTOSAR Gdu - HLD precompile configuration header.
*
*   @addtogroup CDD_GDU
*   @{
*/

#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
[!IF "var:defined('postBuildVariant')"!]
[!LOOP "variant:all()"!]
#include "CDD_Gdu_[!"."!]_PBcfg.h"
[!ENDLOOP!]
[!ELSE!]
#include "CDD_Gdu_PBcfg.h"
[!ENDIF!]


/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define GDU_CFG_VENDOR_ID                    43
#define GDU_CFG_AR_RELEASE_MAJOR_VERSION     4
#define GDU_CFG_AR_RELEASE_MINOR_VERSION     7
#define GDU_CFG_AR_RELEASE_REVISION_VERSION  0
#define GDU_CFG_SW_MAJOR_VERSION             3
#define GDU_CFG_SW_MINOR_VERSION             0
#define GDU_CFG_SW_PATCH_VERSION             0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
[!IF "var:defined('postBuildVariant')"!]
[!LOOP "variant:all()"!]
/* Checks against CDD_Gdu_[!"."!]_PBcfg.h */
#if (GDU_CFG_VENDOR_ID != GDU_[!"."!]_PBCFG_VENDOR_ID)
    #error "CDD_Gdu_Cfg.h and CDD_Gdu_[!"."!]_PBcfg.h have different vendor ids"
#endif
#if ((GDU_CFG_AR_RELEASE_MAJOR_VERSION    != GDU_[!"."!]_PBCFG_AR_RELEASE_MAJOR_VERSION) || \
     (GDU_CFG_AR_RELEASE_MINOR_VERSION    != GDU_[!"."!]_PBCFG_AR_RELEASE_MINOR_VERSION) || \
     (GDU_CFG_AR_RELEASE_REVISION_VERSION != GDU_[!"."!]_PBCFG_AR_RELEASE_REVISION_VERSION))
     #error "AUTOSAR Version Numbers of CDD_Gdu_Cfg.h and CDD_Gdu_[!"."!]_PBcfg.h are different"
#endif
#if ((GDU_CFG_SW_MAJOR_VERSION != GDU_[!"."!]_PBCFG_SW_MAJOR_VERSION) || \
     (GDU_CFG_SW_MINOR_VERSION != GDU_[!"."!]_PBCFG_SW_MINOR_VERSION) || \
     (GDU_CFG_SW_PATCH_VERSION != GDU_[!"."!]_PBCFG_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of CDD_Gdu_Cfg.h and CDD_Gdu_[!"."!]_PBcfg.h are different"
#endif
[!ENDLOOP!]
[!ELSE!]
/* Checks against CDD_Gdu_PBcfg.h */
#if (GDU_CFG_VENDOR_ID != GDU_PBCFG_VENDOR_ID)
    #error "CDD_Gdu_Cfg.h and CDD_Gdu_PBcfg.h have different vendor ids"
#endif
#if ((GDU_CFG_AR_RELEASE_MAJOR_VERSION    != GDU_PBCFG_AR_RELEASE_MAJOR_VERSION) || \
     (GDU_CFG_AR_RELEASE_MINOR_VERSION    != GDU_PBCFG_AR_RELEASE_MINOR_VERSION) || \
     (GDU_CFG_AR_RELEASE_REVISION_VERSION != GDU_PBCFG_AR_RELEASE_REVISION_VERSION))
     #error "AUTOSAR Version Numbers of CDD_Gdu_Cfg.h and CDD_Gdu_PBcfg.h are different"
#endif
#if ((GDU_CFG_SW_MAJOR_VERSION != GDU_PBCFG_SW_MAJOR_VERSION) || \
     (GDU_CFG_SW_MINOR_VERSION != GDU_PBCFG_SW_MINOR_VERSION) || \
     (GDU_CFG_SW_PATCH_VERSION != GDU_PBCFG_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of CDD_Gdu_Cfg.h and CDD_Gdu_PBcfg.h are different"
#endif
[!ENDIF!]


/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/
[!IF "not((IMPLEMENTATION_CONFIG_VARIANT = 'VariantPreCompile') and (variant:size() <= 1))"!][!//
#define GDU_CONFIG_EXT \
[!IF "var:defined('postBuildVariant')"!][!//
[!LOOP "variant:all()"!][!//
GDU_CONFIG_[!"."!]_PB \
[!ENDLOOP!][!//
[!ELSE!][!//
GDU_CONFIG_PB
[!ENDIF!][!//
[!ENDIF!][!// Support for Post Build only

/*==================================================================================================
*                                             ENUMS
==================================================================================================*/

/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

#ifdef __cplusplus
}
#endif

/** @} */

#endif /* CDD_GDU_CFG_H */
