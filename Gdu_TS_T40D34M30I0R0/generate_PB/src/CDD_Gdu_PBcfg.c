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

/**
*   @file    CDD_Gdu_PBcfg[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!].c
*   @version 3.0.0
*
*   @brief   AUTOSAR Gdu - HLD postbuild configuration.
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
#include "Gdu_Ip[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg.h"
#include "CDD_Gdu[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFOGDUATION
==================================================================================================*/
#define GDU[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_VENDOR_ID_C                     43
#define GDU[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_AR_RELEASE_MAJOR_VERSION_C      4
#define GDU[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_AR_RELEASE_MINOR_VERSION_C      7
#define GDU[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_AR_RELEASE_REVISION_VERSION_C   0
#define GDU[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_SW_MAJOR_VERSION_C              3
#define GDU[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_SW_MINOR_VERSION_C              0
#define GDU[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_SW_PATCH_VERSION_C              0

/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/
#if (GDU[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_VENDOR_ID_C != GDU_IP[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_VENDOR_ID)
    #error "CDD_GDU[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg.c and Gdu_Ip[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg.h have different vendor ids"
#endif
#if ((GDU[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_AR_RELEASE_MAJOR_VERSION_C    != GDU_IP[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_AR_RELEASE_MAJOR_VERSION) || \
     (GDU[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_AR_RELEASE_MINOR_VERSION_C    != GDU_IP[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_AR_RELEASE_MINOR_VERSION) || \
     (GDU[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_AR_RELEASE_REVISION_VERSION_C != GDU_IP[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_AR_RELEASE_REVISION_VERSION))
     #error "AUTOSAR Version Numbers of CDD_GDU[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg.c and Gdu_Ip[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg.h are different"
#endif
#if ((GDU[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_SW_MAJOR_VERSION_C != GDU_IP[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_SW_MAJOR_VERSION) || \
     (GDU[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_SW_MINOR_VERSION_C != GDU_IP[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_SW_MINOR_VERSION) || \
     (GDU[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_SW_PATCH_VERSION_C != GDU_IP[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of CDD_GDU[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg.c and Gdu_Ip[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg.h are different"
#endif

/* Checks against CDD_Gdu_[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg.h */
#if (GDU[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_VENDOR_ID_C != GDU[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_VENDOR_ID)
    #error "CDD_Gdu[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg.c and CDD_Gdu_PBcfg.h have different vendor ids"
#endif
#if ((GDU[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_AR_RELEASE_MAJOR_VERSION_C    != GDU[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_AR_RELEASE_MAJOR_VERSION) || \
     (GDU[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_AR_RELEASE_MINOR_VERSION_C    != GDU[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_AR_RELEASE_MINOR_VERSION) || \
     (GDU[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_AR_RELEASE_REVISION_VERSION_C != GDU[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AUTOSAR Version Numbers of CDD_Gdu[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg.c and CDD_Gdu_PBcfg.h are different"
#endif
#if ((GDU[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_SW_MAJOR_VERSION_C != GDU[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_SW_MAJOR_VERSION) || \
     (GDU[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_SW_MINOR_VERSION_C != GDU[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_SW_MINOR_VERSION) || \
     (GDU[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_SW_PATCH_VERSION_C != GDU[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of CDD_Gdu[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg.c and CDD_Gdu_PBcfg.h are different"
#endif

/*==================================================================================================
                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
                                       LOCAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
                                       LOCAL VARIABLES
==================================================================================================*/

/*==================================================================================================
                                      LOCAL MACROS
==================================================================================================*/

/*==================================================================================================
                                       GLOBAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
                                       GLOBAL VARIABLES
==================================================================================================*/
#define GDU_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Gdu_MemMap.h"

[!NOCODE!][!//
[!VAR "VariantsNo" = "variant:size()"!]
[!IF "(IMPLEMENTATION_CONFIG_VARIANT !='VariantPostBuild' and ($VariantsNo <= 1))"!]
[!CODE!][!//
/** TODO: */
const Gdu_Ip_ConfigType * const Gdu_ConfigVariantPredefined[1] =
{
    &GDU_CONFIG
};
[!ENDCODE!][!//
[!ENDIF!][!//
[!ENDNOCODE!][!//

#define GDU_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Gdu_MemMap.h"

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
