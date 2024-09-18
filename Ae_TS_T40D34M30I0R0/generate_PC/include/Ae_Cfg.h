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

#ifndef AE_CFG_H
#define AE_CFG_H

/**
*   @file
*   @implements Ae_Cfg.h_Artifact
*   @addtogroup AE_DRIVER_CONFIGURATION Ae Driver Configuration
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
[!NOCODE!]
[!IF "var:defined('postBuildVariant')"!]
[!LOOP "variant:all()"!]
[!CODE!]#include "Ae_[!"."!]_PBcfg.h"[!CR!][!ENDCODE!]
[!ENDLOOP!]
[!ELSE!]
[!CODE!]#include "Ae_PBcfg.h"[!ENDCODE!]
[!ENDIF!]
[!ENDNOCODE!]

#include "Mcal.h"
#include "Hvm_Ip_Types.h"
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define AE_CFG_VENDOR_ID                    43
#define AE_CFG_AR_RELEASE_MAJOR_VERSION     4
#define AE_CFG_AR_RELEASE_MINOR_VERSION     7
#define AE_CFG_AR_RELEASE_REVISION_VERSION  0
#define AE_CFG_SW_MAJOR_VERSION             3
#define AE_CFG_SW_MINOR_VERSION             0
#define AE_CFG_SW_PATCH_VERSION             0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
[!NOCODE!]
[!IF "var:defined('postBuildVariant')"!]
[!LOOP "variant:all()"!]
[!CODE!][!//
/* Checks against Ae_[!"."!]_PBcfg.h */
#if (AE_CFG_VENDOR_ID != AE_PBCFG_[!"."!]_VENDOR_ID)
    #error "Ae_Cfg.h and Ae_[!"."!]_PBcfg.h have different vendor ids"
#endif
#if ((AE_CFG_AR_RELEASE_MAJOR_VERSION    != AE_PBCFG_[!"."!]_AR_RELEASE_MAJOR_VERSION) || \
     (AE_CFG_AR_RELEASE_MINOR_VERSION    != AE_PBCFG_[!"."!]_AR_RELEASE_MINOR_VERSION) || \
     (AE_CFG_AR_RELEASE_REVISION_VERSION != AE_PBCFG_[!"."!]_AR_RELEASE_REVISION_VERSION))
     #error "AUTOSAR Version Numbers of Ae_Cfg.h and Ae_[!"."!]_PBcfg.h are different"
#endif
#if ((AE_CFG_SW_MAJOR_VERSION != AE_PBCFG_[!"."!]_SW_MAJOR_VERSION) || \
     (AE_CFG_SW_MINOR_VERSION != AE_PBCFG_[!"."!]_SW_MINOR_VERSION) || \
     (AE_CFG_SW_PATCH_VERSION != AE_PBCFG_[!"."!]_SW_PATCH_VERSION))
    #error "Software Version Numbers of Ae_Cfg.h and Ae_[!"."!]_PBcfg.h are different"
#endif
[!ENDCODE!]
[!ENDLOOP!]
[!ELSE!]
[!CODE!][!//
/* Checks against Ae_PBcfg.h */
#if (AE_CFG_VENDOR_ID != AE_PBCFG_VENDOR_ID)
    #error "Ae_Cfg.h and Ae_PBcfg.h have different vendor ids"
#endif
#if ((AE_CFG_AR_RELEASE_MAJOR_VERSION    != AE_PBCFG_AR_RELEASE_MAJOR_VERSION) || \
     (AE_CFG_AR_RELEASE_MINOR_VERSION    != AE_PBCFG_AR_RELEASE_MINOR_VERSION) || \
     (AE_CFG_AR_RELEASE_REVISION_VERSION != AE_PBCFG_AR_RELEASE_REVISION_VERSION))
     #error "AUTOSAR Version Numbers of Ae_Cfg.h and Ae_PBcfg.h are different"
#endif
#if ((AE_CFG_SW_MAJOR_VERSION != AE_PBCFG_SW_MAJOR_VERSION) || \
     (AE_CFG_SW_MINOR_VERSION != AE_PBCFG_SW_MINOR_VERSION) || \
     (AE_CFG_SW_PATCH_VERSION != AE_PBCFG_SW_PATCH_VERSION))
    #error "Software Version Numbers of Ae_Cfg.h and Ae_PBcfg.h are different"
#endif
[!ENDCODE!]
[!ENDIF!]
[!ENDNOCODE!]

/* Checks against Hvm_Ip_Types.h */
#if (AE_CFG_VENDOR_ID != HVM_IP_TYPES_VENDOR_ID)
    #error "Ae_Cfg.h and Hvm_Ip_Types.h have different vendor ids"
#endif
#if ((AE_CFG_AR_RELEASE_MAJOR_VERSION    != HVM_IP_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (AE_CFG_AR_RELEASE_MINOR_VERSION    != HVM_IP_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (AE_CFG_AR_RELEASE_REVISION_VERSION != HVM_IP_TYPES_AR_RELEASE_REVISION_VERSION))
     #error "AUTOSAR Version Numbers of Ae_Cfg.h and Hvm_Ip_Types.h are different"
#endif
#if ((AE_CFG_SW_MAJOR_VERSION != HVM_IP_TYPES_SW_MAJOR_VERSION) || \
     (AE_CFG_SW_MINOR_VERSION != HVM_IP_TYPES_SW_MINOR_VERSION) || \
     (AE_CFG_SW_PATCH_VERSION != HVM_IP_TYPES_SW_PATCH_VERSION))
    #error "Software Version Numbers of Ae_Cfg.h and Hvm_Ip_Types.h are different"
#endif
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Checks against Mcal.h */
    #if ((AE_CFG_AR_RELEASE_MAJOR_VERSION != MCAL_AR_RELEASE_MAJOR_VERSION) || \
         (AE_CFG_AR_RELEASE_MINOR_VERSION != MCAL_AR_RELEASE_MINOR_VERSION))
        #error "AUTOSAR Version Numbers of Ae_Cfg.h and Mcal.h are different"
    #endif
#endif
/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/
[!NOCODE!]
[!IF "not((IMPLEMENTATION_CONFIG_VARIANT != 'VariantPostBuild') and (variant:size() <= 1))"!]
[!CODE!]#define AE_CONFIG_EXT \[!CR!][!ENDCODE!]
[!IF "var:defined('postBuildVariant')"!]
[!LOOP "variant:all()"!][!//
    [!CODE!][!WS "4"!]AE_CONFIG_[!"."!]_PB \[!CR!][!ENDCODE!]
[!ENDLOOP!][!//
[!ELSE!][!//
    [!CODE!][!WS "4"!]AE_CONFIG_PB[!ENDCODE!]
[!ENDIF!]
[!ENDIF!]
[!ENDNOCODE!] 

/*! @brief Enables / Disables PreCompile support when there is a single configuration */
#define AE_PRECOMPILE_SUPPORT          ([!IF "(IMPLEMENTATION_CONFIG_VARIANT != 'VariantPostBuild') and (variant:size() <= 1)"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

/*! @brief Enables / Disables DET development errors detection and reporting */
#define AE_DEV_ERROR_DETECT            ([!IF "AeGeneral/AeDevErrorDetect"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

/*! @brief Enables / Disables Ae_GetVersionInfo API */
#define AE_VERSION_INFO_API            ([!IF "AeGeneral/AeVersionInfoApi"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

/*==================================================================================================
*                                             ENUMS
==================================================================================================*/

/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/* Forward IPW structure declarations */
struct sAe_Ipw_ConfigType;

/**
* @brief This type is used to group all multiple configurations.
* implements Ae_ConfigType_structure
*/   
typedef struct 
{
    const struct sAe_Ipw_ConfigType *Ae_pIpwConfig;

} Ae_ConfigType;

/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
                                       GLOBAL CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/

#ifdef __cplusplus
}
#endif

/** @} */

#endif /* AE_CFG_H */

