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

#ifndef DMA_MUX_IP[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_H
#define DMA_MUX_IP[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_H

/**
*   @file Dma_Mux_Ip[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg.h
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

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define RM_DMA_MUX_IP[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_VENDOR_ID                    43
#define RM_DMA_MUX_IP[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_AR_RELEASE_MAJOR_VERSION     4
#define RM_DMA_MUX_IP[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_AR_RELEASE_MINOR_VERSION     7
#define RM_DMA_MUX_IP[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_AR_RELEASE_REVISION_VERSION  0
#define RM_DMA_MUX_IP[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_SW_MAJOR_VERSION             3
#define RM_DMA_MUX_IP[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_SW_MINOR_VERSION             0
#define RM_DMA_MUX_IP[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_SW_PATCH_VERSION             0

/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/

/*==================================================================================================
                                       GLOBAL VARIABLES
==================================================================================================*/

/** @brief    Declaration of the configuration structure for Dma Mux Ip */
[!NOCODE!]
[!IF "var:defined('postBuildVariant')"!][!//
  [!VAR "postBuildVariantNameUnderscore" = "concat('_',$postBuildVariant)"!][!//
[!IF "RmGeneral/RmEnableDmaMuxSupport"!]
[!CODE!]#define DMA_MUX_CONFIG_[!"$postBuildVariant"!]_PB \[!CR!][!ENDCODE!]
[!ELSE!]
[!CODE!]#define DMA_MUX_CONFIG_[!"$postBuildVariant"!]_PB[!CR!][!ENDCODE!]
[!ENDIF!]
[!ELSE!][!//
  [!VAR "postBuildVariantNameUnderscore" = "string(null)"!][!//
[!IF "RmGeneral/RmEnableDmaMuxSupport"!]
[!CODE!]#define DMA_MUX_CONFIG_PB \[!CR!][!ENDCODE!]
[!ELSE!]
[!CODE!]#define DMA_MUX_CONFIG_PB[!CR!][!ENDCODE!]
[!ENDIF!]
[!ENDIF!][!//
[!IF "RmGeneral/RmEnableDmaMuxSupport"!]
    [!CODE!][!WS "4"!]extern const Dma_Mux_Ip_ConfigType Dma_Mux_Config[!"$postBuildVariantNameUnderscore"!];[!ENDCODE!]
[!ENDIF!]
[!ENDNOCODE!]

#ifdef __cplusplus
}
#endif

/** @} */

#endif /* DMA_MUX_IP[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_H */

