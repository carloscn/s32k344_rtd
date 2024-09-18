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

#ifndef DMA_MUX_IP_CFG_H
#define DMA_MUX_IP_CFG_H

/**
*   @file Dma_Mux_Ip_Cfg.h
*
*   @addtogroup DMA_MUX_IP DMA_MUX IPV Driver
*   @{
*/

#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
                                         INCLUDE FILES
==================================================================================================*/
#include "Dma_Mux_Ip_Types.h"
[!NOCODE!]
[!IF "var:defined('postBuildVariant')"!]
[!LOOP "variant:all()"!]
[!CODE!]#include "Dma_Mux_Ip_[!"."!]_PBcfg.h"[!CR!][!ENDCODE!]
[!ENDLOOP!]
[!ELSE!]
[!CODE!]#include "Dma_Mux_Ip_PBcfg.h"[!ENDCODE!]
[!ENDIF!]
[!ENDNOCODE!]

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define RM_DMA_MUX_IP_CFG_VENDOR_ID                    43
#define RM_DMA_MUX_IP_CFG_AR_RELEASE_MAJOR_VERSION     4
#define RM_DMA_MUX_IP_CFG_AR_RELEASE_MINOR_VERSION     7
#define RM_DMA_MUX_IP_CFG_AR_RELEASE_REVISION_VERSION  0
#define RM_DMA_MUX_IP_CFG_SW_MAJOR_VERSION             3
#define RM_DMA_MUX_IP_CFG_SW_MINOR_VERSION             0
#define RM_DMA_MUX_IP_CFG_SW_PATCH_VERSION             0

/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/
/* Checks against Dma_Mux_Ip_Types.h */
#if (RM_DMA_MUX_IP_CFG_VENDOR_ID != RM_DMA_MUX_IP_TYPES_VENDOR_ID)
    #error "Dma_Mux_Ip_Cfg.h and Dma_Mux_Ip_Types.h have different vendor ids"
#endif
#if (( RM_DMA_MUX_IP_CFG_AR_RELEASE_MAJOR_VERSION    != RM_DMA_MUX_IP_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     ( RM_DMA_MUX_IP_CFG_AR_RELEASE_MINOR_VERSION    != RM_DMA_MUX_IP_TYPES_AR_RELEASE_MINOR_VERSION) || \
     ( RM_DMA_MUX_IP_CFG_AR_RELEASE_REVISION_VERSION != RM_DMA_MUX_IP_TYPES_AR_RELEASE_REVISION_VERSION) \
    )
     #error "AUTOSAR Version Numbers of Dma_Mux_Ip_Cfg.h and Dma_Mux_Ip_Types.h are different"
#endif
#if (( RM_DMA_MUX_IP_CFG_SW_MAJOR_VERSION != RM_DMA_MUX_IP_TYPES_SW_MAJOR_VERSION) || \
     ( RM_DMA_MUX_IP_CFG_SW_MINOR_VERSION != RM_DMA_MUX_IP_TYPES_SW_MINOR_VERSION) || \
     ( RM_DMA_MUX_IP_CFG_SW_PATCH_VERSION != RM_DMA_MUX_IP_TYPES_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Dma_Mux_Ip_Cfg.h and Dma_Mux_Ip_Types.h are different"
#endif

[!NOCODE!]
[!IF "var:defined('postBuildVariant')"!]
[!LOOP "variant:all()"!]
[!CODE!][!//
/* Checks against Dma_Mux_Ip_[!"."!]_PBcfg.h */
#if (RM_DMA_MUX_IP_CFG_VENDOR_ID != RM_DMA_MUX_IP_[!"."!]_PBCFG_VENDOR_ID)
    #error "Dma_Mux_Ip_Cfg.h and Dma_Mux_Ip_[!"."!]_PBcfg.h have different vendor ids"
#endif
#if (( RM_DMA_MUX_IP_CFG_AR_RELEASE_MAJOR_VERSION    != RM_DMA_MUX_IP_[!"."!]_PBCFG_AR_RELEASE_MAJOR_VERSION) || \
     ( RM_DMA_MUX_IP_CFG_AR_RELEASE_MINOR_VERSION    != RM_DMA_MUX_IP_[!"."!]_PBCFG_AR_RELEASE_MINOR_VERSION) || \
     ( RM_DMA_MUX_IP_CFG_AR_RELEASE_REVISION_VERSION != RM_DMA_MUX_IP_[!"."!]_PBCFG_AR_RELEASE_REVISION_VERSION))
     #error "AUTOSAR Version Numbers of Dma_Mux_Ip_Cfg.h and Dma_Mux_Ip_[!"."!]_PBcfg.h are different"
#endif
#if (( RM_DMA_MUX_IP_CFG_SW_MAJOR_VERSION != RM_DMA_MUX_IP_[!"."!]_PBCFG_SW_MAJOR_VERSION) || \
     ( RM_DMA_MUX_IP_CFG_SW_MINOR_VERSION != RM_DMA_MUX_IP_[!"."!]_PBCFG_SW_MINOR_VERSION) || \
     ( RM_DMA_MUX_IP_CFG_SW_PATCH_VERSION != RM_DMA_MUX_IP_[!"."!]_PBCFG_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Dma_Mux_Ip_Cfg.h and Dma_Mux_Ip_[!"."!]_PBcfg.h are different"
#endif
[!ENDCODE!]
[!ENDLOOP!]
[!ELSE!]
[!CODE!][!//
/* Checks against Dma_Mux_Ip_PBcfg.h */
#if (RM_DMA_MUX_IP_CFG_VENDOR_ID != RM_DMA_MUX_IP_PBCFG_VENDOR_ID)
    #error "Dma_Mux_Ip_Cfg.h and Dma_Mux_Ip_PBcfg.h have different vendor ids"
#endif
#if (( RM_DMA_MUX_IP_CFG_AR_RELEASE_MAJOR_VERSION    != RM_DMA_MUX_IP_PBCFG_AR_RELEASE_MAJOR_VERSION) || \
     ( RM_DMA_MUX_IP_CFG_AR_RELEASE_MINOR_VERSION    != RM_DMA_MUX_IP_PBCFG_AR_RELEASE_MINOR_VERSION) || \
     ( RM_DMA_MUX_IP_CFG_AR_RELEASE_REVISION_VERSION != RM_DMA_MUX_IP_PBCFG_AR_RELEASE_REVISION_VERSION) \
    )
     #error "AUTOSAR Version Numbers of Dma_Mux_Ip_Cfg.h and Dma_Mux_Ip_PBcfg.h are different"
#endif
#if (( RM_DMA_MUX_IP_CFG_SW_MAJOR_VERSION != RM_DMA_MUX_IP_PBCFG_SW_MAJOR_VERSION) || \
     ( RM_DMA_MUX_IP_CFG_SW_MINOR_VERSION != RM_DMA_MUX_IP_PBCFG_SW_MINOR_VERSION) || \
     ( RM_DMA_MUX_IP_CFG_SW_PATCH_VERSION != RM_DMA_MUX_IP_PBCFG_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Dma_Mux_Ip_Cfg.h and Dma_Mux_Ip_PBcfg.h are different"
#endif
[!ENDCODE!]
[!ENDIF!]
[!ENDNOCODE!]
/*==================================================================================================
                                       GLOBAL VARIABLES
==================================================================================================*/
/**
* @brief   Collection of all configuration structures declarations.
*/
[!NOCODE!]
[!CODE!]
#define DMA_MUX_CONFIG_EXT \[!CR!][!ENDCODE!]
[!IF "var:defined('postBuildVariant')"!]
    [!VAR "variantIndex"="0"!][!//
    [!VAR "variantNumber"="variant:size()"!][!//
[!LOOP "variant:all()"!][!//
    [!VAR "variantIndex"="$variantIndex + 1"!][!//
    [!CODE!][!WS "4"!]DMA_MUX_CONFIG_[!"."!]_PB[!IF "$variantIndex < $variantNumber"!] \[!CR!][!ENDIF!][!ENDCODE!]
[!ENDLOOP!][!//
[!ELSE!][!//
    [!CODE!][!WS "4"!]DMA_MUX_CONFIG_PB[!ENDCODE!]
[!ENDIF!]
[!ENDNOCODE!]

#ifdef __cplusplus
}
#endif

/** @} */

#endif /* DMA_MUX_IP_CFG_H */



