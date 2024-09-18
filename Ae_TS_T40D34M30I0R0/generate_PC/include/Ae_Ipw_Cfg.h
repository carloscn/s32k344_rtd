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

#ifndef AE_IPW_CFG_H
#define AE_IPW_CFG_H

/**
*   @file
*
*   @addtogroup AE_DRIVER_CONFIGURATION Ae Driver Configurations
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
[!CODE!]#include "Ae_Ipw_[!"."!]_PBcfg.h"[!CR!][!ENDCODE!]
[!ENDLOOP!]
[!ELSE!]
[!CODE!]#include "Ae_Ipw_PBcfg.h"[!ENDCODE!]
[!ENDIF!]
[!ENDNOCODE!]

#include "Ae_Cfg.h"
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define AE_IPW_CFG_VENDOR_ID                    43
#define AE_IPW_CFG_AR_RELEASE_MAJOR_VERSION     4
#define AE_IPW_CFG_AR_RELEASE_MINOR_VERSION     7
#define AE_IPW_CFG_AR_RELEASE_REVISION_VERSION  0
#define AE_IPW_CFG_SW_MAJOR_VERSION             3
#define AE_IPW_CFG_SW_MINOR_VERSION             0
#define AE_IPW_CFG_SW_PATCH_VERSION             0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
[!NOCODE!]
[!IF "var:defined('postBuildVariant')"!]
[!LOOP "variant:all()"!]
[!CODE!][!//
/* Checks against Ae_Ipw_[!"."!]_PBcfg.h */
#if (AE_IPW_CFG_VENDOR_ID != AE_IPW_PBCFG_[!"."!]_VENDOR_ID)
    #error "Ae_Ipw_Cfg.h and Ae_Ipw_[!"."!]_PBcfg.h have different vendor ids"
#endif
#if ((AE_IPW_CFG_AR_RELEASE_MAJOR_VERSION    != AE_IPW_PBCFG_[!"."!]_AR_RELEASE_MAJOR_VERSION) || \
     (AE_IPW_CFG_AR_RELEASE_MINOR_VERSION    != AE_IPW_PBCFG_[!"."!]_AR_RELEASE_MINOR_VERSION) || \
     (AE_IPW_CFG_AR_RELEASE_REVISION_VERSION != AE_IPW_PBCFG_[!"."!]_AR_RELEASE_REVISION_VERSION))
     #error "AUTOSAR Version Numbers of Ae_Ipw_Cfg.h and Ae_Ipw_[!"."!]_PBcfg.h are different"
#endif
#if ((AE_IPW_CFG_SW_MAJOR_VERSION != AE_IPW_PBCFG_[!"."!]_SW_MAJOR_VERSION) || \
     (AE_IPW_CFG_SW_MINOR_VERSION != AE_IPW_PBCFG_[!"."!]_SW_MINOR_VERSION) || \
     (AE_IPW_CFG_SW_PATCH_VERSION != AE_IPW_PBCFG_[!"."!]_SW_PATCH_VERSION))
    #error "Software Version Numbers of Ae_Ipw_Cfg.h and Ae_Ipw_[!"."!]_PBcfg.h are different"
#endif
[!ENDCODE!]
[!ENDLOOP!]
[!ELSE!]
[!CODE!][!//
/* Checks against Ae_Ipw_PBcfg.h */
#if (AE_IPW_CFG_VENDOR_ID != AE_IPW_PBCFG_VENDOR_ID)
    #error "Ae_Ipw_Cfg.h and Ae_Ipw_PBcfg.h have different vendor ids"
#endif
#if ((AE_IPW_CFG_AR_RELEASE_MAJOR_VERSION    != AE_IPW_PBCFG_AR_RELEASE_MAJOR_VERSION) || \
     (AE_IPW_CFG_AR_RELEASE_MINOR_VERSION    != AE_IPW_PBCFG_AR_RELEASE_MINOR_VERSION) || \
     (AE_IPW_CFG_AR_RELEASE_REVISION_VERSION != AE_IPW_PBCFG_AR_RELEASE_REVISION_VERSION))
     #error "AUTOSAR Version Numbers of Ae_Ipw_Cfg.h and Ae_Ipw_PBcfg.h are different"
#endif
#if ((AE_IPW_CFG_SW_MAJOR_VERSION != AE_IPW_PBCFG_SW_MAJOR_VERSION) || \
     (AE_IPW_CFG_SW_MINOR_VERSION != AE_IPW_PBCFG_SW_MINOR_VERSION) || \
     (AE_IPW_CFG_SW_PATCH_VERSION != AE_IPW_PBCFG_SW_PATCH_VERSION))
    #error "Software Version Numbers of Ae_Ipw_Cfg.h and Ae_Ipw_PBcfg.h are different"
#endif
[!ENDCODE!]
[!ENDIF!]
[!ENDNOCODE!]

/* Checks against Ae_Cfg.h */
#if (AE_IPW_CFG_VENDOR_ID != AE_CFG_VENDOR_ID)
    #error "Ae_Ipw_Cfg.h and Ae_Cfg.h have different vendor ids"
#endif
#if ((AE_IPW_CFG_AR_RELEASE_MAJOR_VERSION    != AE_CFG_AR_RELEASE_MAJOR_VERSION) || \
     (AE_IPW_CFG_AR_RELEASE_MINOR_VERSION    != AE_CFG_AR_RELEASE_MINOR_VERSION) || \
     (AE_IPW_CFG_AR_RELEASE_REVISION_VERSION != AE_CFG_AR_RELEASE_REVISION_VERSION))
    #error "AUTOSAR Version Numbers of Ae_Ipw_Cfg.h and Ae_Cfg.h are different"
#endif
#if ((AE_IPW_CFG_SW_MAJOR_VERSION != AE_CFG_SW_MAJOR_VERSION) || \
     (AE_IPW_CFG_SW_MINOR_VERSION != AE_CFG_SW_MINOR_VERSION) || \
     (AE_IPW_CFG_SW_PATCH_VERSION != AE_CFG_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Ae_Ipw_Cfg.h and Ae_Cfg.h are different"
#endif
/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/
[!NOCODE!]
[!CODE!]#define AE_IPW_CONFIG_EXT \[!CR!][!ENDCODE!]
[!IF "var:defined('postBuildVariant')"!]
[!LOOP "variant:all()"!][!//
    [!CODE!][!WS "4"!]AE_IPW_CONFIG_[!"."!]_PB \[!CR!][!ENDCODE!]
[!ENDLOOP!][!//
[!ELSE!][!//
    [!CODE!][!WS "4"!]AE_IPW_CONFIG_PB[!ENDCODE!]
[!ENDIF!]
[!ENDNOCODE!]

/*==================================================================================================
*                                             ENUMS
==================================================================================================*/

/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/
/* Forward IPW structure declarations */
struct Aec_Ip_sConfigType;
struct Hvm_Ip_sConfigType;

/**
* @brief   The structure contains the hardware controller configuration type.
*/
typedef struct sAe_Ipw_ConfigType
{
    const struct Aec_Ip_sConfigType *Ae_Ipw_pAecConfig;
    const struct Hvm_Ip_sConfigType *Ae_Ipw_pHvmConfig;

} Ae_Ipw_ConfigType;

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

#endif /* AE_IPW_CFG_H */
