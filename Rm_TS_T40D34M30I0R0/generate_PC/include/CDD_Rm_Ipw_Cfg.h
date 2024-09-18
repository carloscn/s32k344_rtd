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

#ifndef CDD_RM_IPW_CFG_H
#define CDD_RM_IPW_CFG_H

/**
*   @file CDD_Rm_Ipw_Cfg.h
*
*   @addtogroup RM_MODULE RM Driver
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
[!CODE!]#include "CDD_Rm_Ipw_[!"."!]_PBcfg.h"[!CR!][!ENDCODE!]
[!ENDLOOP!]
[!ELSE!]
[!CODE!]#include "CDD_Rm_Ipw_PBcfg.h"[!ENDCODE!]
[!ENDIF!]
[!ENDNOCODE!]
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define RM_IPW_CFG_VENDOR_ID                    43
#define RM_IPW_CFG_AR_RELEASE_MAJOR_VERSION     4
#define RM_IPW_CFG_AR_RELEASE_MINOR_VERSION     7
#define RM_IPW_CFG_AR_RELEASE_REVISION_VERSION  0
#define RM_IPW_CFG_SW_MAJOR_VERSION             3
#define RM_IPW_CFG_SW_MINOR_VERSION             0
#define RM_IPW_CFG_SW_PATCH_VERSION             0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
[!NOCODE!]
[!IF "var:defined('postBuildVariant')"!]
[!LOOP "variant:all()"!]
[!CODE!][!//
/* Checks against CDD_Rm_Ipw_[!"."!]_PBcfg.h */
#if (RM_IPW_CFG_VENDOR_ID != RM_IPW_PBCFG_[!"."!]_VENDOR_ID)
    #error "CDD_Rm_Ipw_Cfg.h and CDD_Rm_Ipw_[!"."!]_PBcfg.h have different vendor ids"
#endif
#if ((RM_IPW_CFG_AR_RELEASE_MAJOR_VERSION    != RM_IPW_PBCFG_[!"."!]_AR_RELEASE_MAJOR_VERSION) || \
     (RM_IPW_CFG_AR_RELEASE_MINOR_VERSION    != RM_IPW_PBCFG_[!"."!]_AR_RELEASE_MINOR_VERSION) || \
     (RM_IPW_CFG_AR_RELEASE_REVISION_VERSION != RM_IPW_PBCFG_[!"."!]_AR_RELEASE_REVISION_VERSION))
     #error "AUTOSAR Version Numbers of CDD_Rm_Ipw_Cfg.h and CDD_Rm_Ipw_[!"."!]_PBcfg.h are different"
#endif
#if ((RM_IPW_CFG_SW_MAJOR_VERSION != RM_IPW_PBCFG_[!"."!]_SW_MAJOR_VERSION) || \
     (RM_IPW_CFG_SW_MINOR_VERSION != RM_IPW_PBCFG_[!"."!]_SW_MINOR_VERSION) || \
     (RM_IPW_CFG_SW_PATCH_VERSION != RM_IPW_PBCFG_[!"."!]_SW_PATCH_VERSION))
    #error "Software Version Numbers of CDD_Rm_Ipw_Cfg.h and CDD_Rm_Ipw_[!"."!]_PBcfg.h are different"
#endif
[!ENDCODE!][!//
[!ENDLOOP!][!//
[!ELSE!][!//
[!CODE!][!//
/* Checks against CDD_Rm_Ipw_PBcfg.h */
#if (RM_IPW_CFG_VENDOR_ID != RM_IPW_PBCFG_VENDOR_ID)
    #error "CDD_Rm_Ipw_Cfg.h and CDD_Rm_Ipw_PBcfg.h have different vendor ids"
#endif
#if ((RM_IPW_CFG_AR_RELEASE_MAJOR_VERSION    != RM_IPW_PBCFG_AR_RELEASE_MAJOR_VERSION) || \
     (RM_IPW_CFG_AR_RELEASE_MINOR_VERSION    != RM_IPW_PBCFG_AR_RELEASE_MINOR_VERSION) || \
     (RM_IPW_CFG_AR_RELEASE_REVISION_VERSION != RM_IPW_PBCFG_AR_RELEASE_REVISION_VERSION))
     #error "AUTOSAR Version Numbers of CDD_Rm_Ipw_Cfg.h and CDD_Rm_Ipw_PBcfg.h are different"
#endif
#if ((RM_IPW_CFG_SW_MAJOR_VERSION != RM_IPW_PBCFG_SW_MAJOR_VERSION) || \
     (RM_IPW_CFG_SW_MINOR_VERSION != RM_IPW_PBCFG_SW_MINOR_VERSION) || \
     (RM_IPW_CFG_SW_PATCH_VERSION != RM_IPW_PBCFG_SW_PATCH_VERSION))
    #error "Software Version Numbers of CDD_Rm_Ipw_Cfg.h and CDD_Rm_Ipw_PBcfg.h are different"
#endif
[!ENDCODE!][!//
[!ENDIF!][!//
[!ENDNOCODE!][!//
/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/
/**
* @brief   Collection of all configuration structures declarations.
*/

#define RM_IPW_ENABLE_XRDC                                ([!IF "RmGeneral/RmEnableXRDCSupport"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])
#define RM_IPW_ENABLE_PFLASH                              ([!IF "RmGeneral/RmPflashConfigurable"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])
#define RM_IPW_ENABLE_AXBS                                ([!IF "RmGeneral/RmCrossbarConfigurable"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])
#define RM_IPW_ENABLE_VIRT_WRAPPER                        ([!IF "RmGeneral/RmVirtWrapperConfigurable"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])
#define RM_IPW_ENABLE_XBIC                                ([!IF "RmGeneral/RmXbicConfigurable"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])
#define RM_IPW_ENABLE_SEMA42                              ([!IF "RmGeneral/RmEnableSema42Support"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])
#define RM_IPW_ENABLE_DMA_MUX                             ([!IF "RmGeneral/RmEnableDmaMuxSupport"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])
#define RM_IPW_ENABLE_MSCM                                ([!IF "RmGeneral/RmEnableMscmSupport"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])
/*==================================================================================================
*                                             ENUMS
==================================================================================================*/

/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/
[!IF "RmGeneral/RmEnableSema42Support"!][!//
/**
* @brief   Definition of Sema42 logic channel.
*/
[!CODE!][!//
[!VAR "Rm_Sema42ChannelCount" = "0"!][!//
[!LOOP "RmConfigSet/Sema42_ModuleConfig/Sema42LogicChannelConfiguration/*"!][!//
/* Logic Channel [!"num:i($Rm_Sema42ChannelCount)"!] */
#define RM_[!"toUpperCase(substring-after(./Sema42LogicChannel_LogicName ,''))"!]    ((uint8)[!"num:i($Rm_Sema42ChannelCount)"!]U)
[!VAR "Rm_Sema42ChannelCount" = "$Rm_Sema42ChannelCount + 1"!][!//
[!ENDLOOP!][!//
#define RM_SEMA42_LOGIC_CH_UNUSED     ((uint8)255U)
/* Logic Channel count */
#define RM_SEMAPHORE_CHANNEL_COUNT    ((uint8)[!"num:i($Rm_Sema42ChannelCount)"!]U)
[!ENDCODE!][!//
[!ENDIF!][!//

#if (STD_ON == RM_IPW_ENABLE_SEMA42)
/**
* @brief          Sema42 Logic Channel configuration structure
*/
typedef struct
{
    uint32 u32HardwareInstance;                                /*!< Hardware Instance */
    uint8  u8HardwareChannel;                                  /*!< Hardware Channel  */
} Rm_Ipw_Sema42_LogicChannelConfigType;

/**
* @brief          Sema42 Logic Channel configuration structure
*/
typedef struct
{
    const Rm_Ipw_Sema42_LogicChannelConfigType*   pLogicChannelArray;        /*!< Logic Channel Array */
} Rm_Ipw_Sema42_ConfigType;
#endif

/**
* @brief   The structure contains the hardware controller configuration type.
*/
typedef struct
{
#if (STD_ON == RM_IPW_ENABLE_XRDC)
    const Xrdc_Ip_ConfigType         *Rm_Ipw_pXrdcConfig;
#endif
#if (STD_ON == RM_IPW_ENABLE_SEMA42)
    const Rm_Ipw_Sema42_ConfigType   *Rm_Ipw_pSema42Config;
#endif
#if (STD_ON == RM_IPW_ENABLE_PFLASH)
    const Pflash_Ip_ConfigType       *Rm_Ipw_pPflashConfig;
#endif
#if (STD_ON == RM_IPW_ENABLE_AXBS)
    const Axbs_Ip_ConfigType         *Rm_Ipw_pAxbsConfig;
#endif
#if (STD_ON == RM_IPW_ENABLE_VIRT_WRAPPER)
    const Virt_Wrapper_Ip_ConfigType *Rm_Ipw_pVirt_WrapperConfig;
#endif
#if (STD_ON == RM_IPW_ENABLE_XBIC)
    const Xbic_Ip_ConfigType         *Rm_Ipw_pXbicConfig;
#endif
#if (STD_ON == RM_IPW_ENABLE_DMA_MUX)
    const Dma_Mux_Ip_ConfigType      *Rm_Ipw_pDma_MuxConfig;
#endif
#if (STD_ON == RM_IPW_ENABLE_MSCM)
    const Mscm_Ip_ConfigType         *Rm_Ipw_pMscmConfig;
#endif
} Rm_Ipw_ConfigType;

/**
* @brief   Collection of all configuration structures declarations.
*/
#define RM_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Rm_MemMap.h"

[!NOCODE!]
[!IF "var:defined('postBuildVariant')"!]
    [!LOOP "variant:all()"!]
        [!CODE!]RM_IPW_CONFIG_[!"."!]_PB[!CR!][!ENDCODE!]
    [!ENDLOOP!]
[!ELSE!]
    [!CODE!]RM_IPW_CONFIG_PB[!ENDCODE!]
[!ENDIF!]
[!ENDNOCODE!][!//

#define RM_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Rm_MemMap.h"
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
#endif /* __cplusplus */

/** @} */

#endif /* CDD_RM_IPW_CFG_H */

