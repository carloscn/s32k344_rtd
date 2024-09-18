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
/**
*   @file
*   @implements Ae_PBcfg.c_Artifact
*   @addtogroup AE_DRIVER_CONFIGURATION Ae Driver Configuration
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
#include "Ae_Cfg.h"
#include "Ae_Ipw_Cfg.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define AE_PBCFG[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_VENDOR_ID_C                     43
#define AE_PBCFG[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_AR_RELEASE_MAJOR_VERSION_C      4
#define AE_PBCFG[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_AR_RELEASE_MINOR_VERSION_C      7
#define AE_PBCFG[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_AR_RELEASE_REVISION_VERSION_C   0
#define AE_PBCFG[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_SW_MAJOR_VERSION_C              3
#define AE_PBCFG[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_SW_MINOR_VERSION_C              0
#define AE_PBCFG[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_SW_PATCH_VERSION_C              0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Checks against Ae_Cfg.h */
#if (AE_PBCFG[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_VENDOR_ID_C != AE_CFG_VENDOR_ID)
    #error "Ae[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg.c and Ae_Cfg.h have different vendor ids"
#endif
#if ((AE_PBCFG[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_AR_RELEASE_MAJOR_VERSION_C    != AE_CFG_AR_RELEASE_MAJOR_VERSION) || \
     (AE_PBCFG[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_AR_RELEASE_MINOR_VERSION_C    != AE_CFG_AR_RELEASE_MINOR_VERSION) || \
     (AE_PBCFG[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_AR_RELEASE_REVISION_VERSION_C != AE_CFG_AR_RELEASE_REVISION_VERSION))
    #error "AUTOSAR Version Numbers of Ae[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg.c and Ae_Cfg.h are different"
#endif
#if ((AE_PBCFG[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_SW_MAJOR_VERSION_C != AE_CFG_SW_MAJOR_VERSION) || \
     (AE_PBCFG[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_SW_MINOR_VERSION_C != AE_CFG_SW_MINOR_VERSION) || \
     (AE_PBCFG[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_SW_PATCH_VERSION_C != AE_CFG_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Ae[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg.c and Ae_Cfg.h are different"
#endif

/* Checks against Ae_Ipw_Cfg.h */
#if (AE_PBCFG[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_VENDOR_ID_C != AE_IPW_CFG_VENDOR_ID)
    #error "Ae[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg.c and Ae_Ipw_Cfg.h have different vendor ids"
#endif
#if ((AE_PBCFG[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_AR_RELEASE_MAJOR_VERSION_C    != AE_IPW_CFG_AR_RELEASE_MAJOR_VERSION) || \
     (AE_PBCFG[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_AR_RELEASE_MINOR_VERSION_C    != AE_IPW_CFG_AR_RELEASE_MINOR_VERSION) || \
     (AE_PBCFG[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_AR_RELEASE_REVISION_VERSION_C != AE_IPW_CFG_AR_RELEASE_REVISION_VERSION))
    #error "AUTOSAR Version Numbers of Ae[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg.c and Ae_Ipw_Cfg.h are different"
#endif
#if ((AE_PBCFG[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_SW_MAJOR_VERSION_C != AE_IPW_CFG_SW_MAJOR_VERSION) || \
     (AE_PBCFG[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_SW_MINOR_VERSION_C != AE_IPW_CFG_SW_MINOR_VERSION) || \
     (AE_PBCFG[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_SW_PATCH_VERSION_C != AE_IPW_CFG_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Ae[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg.c and Ae_Ipw_Cfg.h are different"
#endif


/*==================================================================================================
                                 GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/
#define AE_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Ae_MemMap.h"

/**
* @brief   Export IPW configurations.
*/
AE_IPW_CONFIG_EXT

#define AE_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Ae_MemMap.h"

/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/


/*==================================================================================================
*                                      LOCAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/

/*==================================================================================================
*                                      LOCAL VARIABLES
==================================================================================================*/


/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/
[!MACRO "GetConfigStructName"!][!//
[!NOCODE!]
    [!VAR "CtrlConfigStructureName" = "'NULL_PTR'"!]
    [!VAR "postBuildVariantNameUnderscore" = "string(null)"!]
    [!IF "var:defined('postBuildVariant')"!]
        [!VAR "postBuildVariantNameUnderscore" = "concat('_', $postBuildVariant)"!]
    [!ENDIF!]
    [!VAR "CtrlConfigStructureName" = "concat('&Ae_Ipw_aConfigPB', $postBuildVariantNameUnderscore, '')"!]
    [!CODE!][!"$CtrlConfigStructureName"!][!ENDCODE!]
[!ENDNOCODE!][!//
[!ENDMACRO!][!//

[!MACRO "GenerateSingleCoreConfig"!][!//
[!CODE!]
const Ae_ConfigType [!IF "(IMPLEMENTATION_CONFIG_VARIANT != 'VariantPostBuild') and (variant:size() <= 1)"!]Ae_xPredefinedConfig[!ELSE!]Ae_Config[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][!ENDIF!] =
{
    [!CALL "GetConfigStructName"!][!CR!]
};
[!ENDCODE!]
[!ENDMACRO!][!//

/*==================================================================================================
*                                      GLOBAL VARIABLES
==================================================================================================*/

#define AE_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Ae_MemMap.h"

[!CALL "GenerateSingleCoreConfig"!]

#define AE_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Ae_MemMap.h"
/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/


/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/

#ifdef __cplusplus
}
#endif
/** @} */
