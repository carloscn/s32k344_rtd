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

#ifndef RM_IPW[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_H
#define RM_IPW[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_H

/**
*   @file CDD_Rm_Ipw_PBcfg.h
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
#include "Xrdc_Ip.h"
#include "Pflash_Ip.h"
#include "Axbs_Ip.h"
#include "Virt_Wrapper_Ip.h"
#include "Xbic_Ip.h"
#include "Dma_Mux_Ip.h"
#include "Mscm_Ip.h"
#include "Sema42_Ip.h"
/*==================================================================================================
                                SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define RM_IPW_PBCFG[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_VENDOR_ID                     43
#define RM_IPW_PBCFG[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_AR_RELEASE_MAJOR_VERSION      4
#define RM_IPW_PBCFG[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_AR_RELEASE_MINOR_VERSION      7
#define RM_IPW_PBCFG[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_AR_RELEASE_REVISION_VERSION   0
#define RM_IPW_PBCFG[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_SW_MAJOR_VERSION              3
#define RM_IPW_PBCFG[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_SW_MINOR_VERSION              0
#define RM_IPW_PBCFG[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_SW_PATCH_VERSION              0
/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/
/* Checks against Xrdc_Ip.h */
#if (RM_IPW_PBCFG[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_VENDOR_ID != RM_XRDC_IP_VENDOR_ID)
    #error "CDD_Rm_Ipw[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg.h and Xrdc_Ip.h have different vendor ids"
#endif
#if ((RM_IPW_PBCFG[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_AR_RELEASE_MAJOR_VERSION    != RM_XRDC_IP_AR_RELEASE_MAJOR_VERSION) || \
     (RM_IPW_PBCFG[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_AR_RELEASE_MINOR_VERSION    != RM_XRDC_IP_AR_RELEASE_MINOR_VERSION) || \
     (RM_IPW_PBCFG[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_AR_RELEASE_REVISION_VERSION != RM_XRDC_IP_AR_RELEASE_REVISION_VERSION))
    #error "AUTOSAR Version Numbers of CDD_Rm_Ipw[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg.h and Xrdc_Ip.h are different"
#endif
#if ((RM_IPW_PBCFG[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_SW_MAJOR_VERSION != RM_XRDC_IP_SW_MAJOR_VERSION) || \
     (RM_IPW_PBCFG[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_SW_MINOR_VERSION != RM_XRDC_IP_SW_MINOR_VERSION) || \
     (RM_IPW_PBCFG[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_SW_PATCH_VERSION != RM_XRDC_IP_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of CDD_Rm_Ipw[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg.h and Xrdc_Ip.h are different"
#endif

/* Checks against Pflash_Ip.h */
#if (RM_IPW_PBCFG[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_VENDOR_ID != RM_PFLASH_IP_VENDOR_ID)
    #error "CDD_Rm_Ipw[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg.h and Pflash_Ip.h have different vendor ids"
#endif
#if ((RM_IPW_PBCFG[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_AR_RELEASE_MAJOR_VERSION    != RM_PFLASH_IP_AR_RELEASE_MAJOR_VERSION) || \
     (RM_IPW_PBCFG[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_AR_RELEASE_MINOR_VERSION    != RM_PFLASH_IP_AR_RELEASE_MINOR_VERSION) || \
     (RM_IPW_PBCFG[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_AR_RELEASE_REVISION_VERSION != RM_PFLASH_IP_AR_RELEASE_REVISION_VERSION))
    #error "AUTOSAR Version Numbers of CDD_Rm_Ipw[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg.h and Pflash_Ip.h are different"
#endif
#if ((RM_IPW_PBCFG[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_SW_MAJOR_VERSION != RM_PFLASH_IP_SW_MAJOR_VERSION) || \
     (RM_IPW_PBCFG[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_SW_MINOR_VERSION != RM_PFLASH_IP_SW_MINOR_VERSION) || \
     (RM_IPW_PBCFG[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_SW_PATCH_VERSION != RM_PFLASH_IP_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of CDD_Rm_Ipw[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg.h and Pflash_Ip.h are different"
#endif

/* Checks against Axbs_Ip.h */
#if (RM_IPW_PBCFG[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_VENDOR_ID != RM_AXBS_IP_VENDOR_ID)
    #error "CDD_Rm_Ipw[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg.h and Axbs_Ip.h have different vendor ids"
#endif
#if ((RM_IPW_PBCFG[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_AR_RELEASE_MAJOR_VERSION    != RM_AXBS_IP_AR_RELEASE_MAJOR_VERSION) || \
     (RM_IPW_PBCFG[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_AR_RELEASE_MINOR_VERSION    != RM_AXBS_IP_AR_RELEASE_MINOR_VERSION) || \
     (RM_IPW_PBCFG[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_AR_RELEASE_REVISION_VERSION != RM_AXBS_IP_AR_RELEASE_REVISION_VERSION))
    #error "AUTOSAR Version Numbers of CDD_Rm_Ipw[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg.h and Axbs_Ip.h are different"
#endif
#if ((RM_IPW_PBCFG[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_SW_MAJOR_VERSION != RM_AXBS_IP_SW_MAJOR_VERSION) || \
     (RM_IPW_PBCFG[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_SW_MINOR_VERSION != RM_AXBS_IP_SW_MINOR_VERSION) || \
     (RM_IPW_PBCFG[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_SW_PATCH_VERSION != RM_AXBS_IP_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of CDD_Rm_Ipw[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg.h and Axbs_Ip.h are different"
#endif

/* Checks against Virt_Wrapper_Ip.h */
#if (RM_IPW_PBCFG[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_VENDOR_ID != RM_VIRT_WRAPPER_IP_VENDOR_ID)
    #error "CDD_Rm_Ipw[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg.h and Virt_Wrapper_Ip.h have different vendor ids"
#endif
#if ((RM_IPW_PBCFG[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_AR_RELEASE_MAJOR_VERSION    != RM_VIRT_WRAPPER_IP_AR_RELEASE_MAJOR_VERSION) || \
     (RM_IPW_PBCFG[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_AR_RELEASE_MINOR_VERSION    != RM_VIRT_WRAPPER_IP_AR_RELEASE_MINOR_VERSION) || \
     (RM_IPW_PBCFG[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_AR_RELEASE_REVISION_VERSION != RM_VIRT_WRAPPER_IP_AR_RELEASE_REVISION_VERSION))
    #error "AUTOSAR Version Numbers of CDD_Rm_Ipw[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg.h and Virt_Wrapper_Ip.h are different"
#endif
#if ((RM_IPW_PBCFG[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_SW_MAJOR_VERSION != RM_VIRT_WRAPPER_IP_SW_MAJOR_VERSION) || \
     (RM_IPW_PBCFG[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_SW_MINOR_VERSION != RM_VIRT_WRAPPER_IP_SW_MINOR_VERSION) || \
     (RM_IPW_PBCFG[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_SW_PATCH_VERSION != RM_VIRT_WRAPPER_IP_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of CDD_Rm_Ipw[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg.h and Virt_Wrapper_Ip.h are different"
#endif

/* Checks against Xbic_Ip.h */
#if (RM_IPW_PBCFG[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_VENDOR_ID != RM_XBIC_IP_VENDOR_ID)
    #error "CDD_Rm_Ipw[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg.h and Xbic_Ip.h have different vendor ids"
#endif
#if ((RM_IPW_PBCFG[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_AR_RELEASE_MAJOR_VERSION    != RM_XBIC_IP_AR_RELEASE_MAJOR_VERSION) || \
     (RM_IPW_PBCFG[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_AR_RELEASE_MINOR_VERSION    != RM_XBIC_IP_AR_RELEASE_MINOR_VERSION) || \
     (RM_IPW_PBCFG[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_AR_RELEASE_REVISION_VERSION != RM_XBIC_IP_AR_RELEASE_REVISION_VERSION))
    #error "AUTOSAR Version Numbers of CDD_Rm_Ipw[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg.h and Xbic_Ip.h are different"
#endif
#if ((RM_IPW_PBCFG[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_SW_MAJOR_VERSION != RM_XBIC_IP_SW_MAJOR_VERSION) || \
     (RM_IPW_PBCFG[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_SW_MINOR_VERSION != RM_XBIC_IP_SW_MINOR_VERSION) || \
     (RM_IPW_PBCFG[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_SW_PATCH_VERSION != RM_XBIC_IP_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of CDD_Rm_Ipw[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg.h and Xbic_Ip.h are different"
#endif

/* Checks against Dma_Mux_Ip.h */
#if (RM_IPW_PBCFG[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_VENDOR_ID != RM_DMA_MUX_IP_VENDOR_ID)
    #error "CDD_Rm_Ipw[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg.h and Dma_Mux_Ip.h have different vendor ids"
#endif
#if ((RM_IPW_PBCFG[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_AR_RELEASE_MAJOR_VERSION    != RM_DMA_MUX_IP_AR_RELEASE_MAJOR_VERSION) || \
     (RM_IPW_PBCFG[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_AR_RELEASE_MINOR_VERSION    != RM_DMA_MUX_IP_AR_RELEASE_MINOR_VERSION) || \
     (RM_IPW_PBCFG[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_AR_RELEASE_REVISION_VERSION != RM_DMA_MUX_IP_AR_RELEASE_REVISION_VERSION))
    #error "AUTOSAR Version Numbers of CDD_Rm_Ipw[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg.h and Dma_Mux_Ip.h are different"
#endif
#if ((RM_IPW_PBCFG[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_SW_MAJOR_VERSION != RM_DMA_MUX_IP_SW_MAJOR_VERSION) || \
     (RM_IPW_PBCFG[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_SW_MINOR_VERSION != RM_DMA_MUX_IP_SW_MINOR_VERSION) || \
     (RM_IPW_PBCFG[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_SW_PATCH_VERSION != RM_DMA_MUX_IP_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of CDD_Rm_Ipw[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg.h and Dma_Mux_Ip.h are different"
#endif

/* Checks against Mscm_Ip.h */
#if (RM_IPW_PBCFG[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_VENDOR_ID != RM_MSCM_IP_VENDOR_ID)
    #error "CDD_Rm_Ipw[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg.h and Mscm_Ip.h have different vendor ids"
#endif
#if ((RM_IPW_PBCFG[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_AR_RELEASE_MAJOR_VERSION    != RM_MSCM_IP_AR_RELEASE_MAJOR_VERSION) || \
     (RM_IPW_PBCFG[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_AR_RELEASE_MINOR_VERSION    != RM_MSCM_IP_AR_RELEASE_MINOR_VERSION) || \
     (RM_IPW_PBCFG[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_AR_RELEASE_REVISION_VERSION != RM_MSCM_IP_AR_RELEASE_REVISION_VERSION))
    #error "AUTOSAR Version Numbers of CDD_Rm_Ipw[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg.h and Mscm_Ip.h are different"
#endif
#if ((RM_IPW_PBCFG[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_SW_MAJOR_VERSION != RM_MSCM_IP_SW_MAJOR_VERSION) || \
     (RM_IPW_PBCFG[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_SW_MINOR_VERSION != RM_MSCM_IP_SW_MINOR_VERSION) || \
     (RM_IPW_PBCFG[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_SW_PATCH_VERSION != RM_MSCM_IP_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of CDD_Rm_Ipw[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg.h and Mscm_Ip.h are different"
#endif

/* Checks against Sema42_Ip.h */
#if (RM_IPW_PBCFG[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_VENDOR_ID != RM_SEMA42_IP_VENDOR_ID)
    #error "CDD_Rm_Ipw[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg.h and Sema42_Ip.h have different vendor ids"
#endif
#if ((RM_IPW_PBCFG[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_AR_RELEASE_MAJOR_VERSION    != RM_SEMA42_IP_AR_RELEASE_MAJOR_VERSION) || \
     (RM_IPW_PBCFG[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_AR_RELEASE_MINOR_VERSION    != RM_SEMA42_IP_AR_RELEASE_MINOR_VERSION) || \
     (RM_IPW_PBCFG[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_AR_RELEASE_REVISION_VERSION != RM_SEMA42_IP_AR_RELEASE_REVISION_VERSION))
    #error "AUTOSAR Version Numbers of CDD_Rm_Ipw[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg.h and Sema42_Ip.h are different"
#endif
#if ((RM_IPW_PBCFG[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_SW_MAJOR_VERSION != RM_SEMA42_IP_SW_MAJOR_VERSION) || \
     (RM_IPW_PBCFG[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_SW_MINOR_VERSION != RM_SEMA42_IP_SW_MINOR_VERSION) || \
     (RM_IPW_PBCFG[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_SW_PATCH_VERSION != RM_SEMA42_IP_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of CDD_Rm_Ipw[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg.h and Sema42_Ip.h are different"
#endif
/*==================================================================================================
                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
                                        LOCAL MACROS
==================================================================================================*/

/*==================================================================================================
                                       LOCAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
                                       LOCAL VARIABLES
==================================================================================================*/

/*==================================================================================================
                                       GLOBAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
                                       GLOBAL VARIABLES
==================================================================================================*/
[!NOCODE!]
[!IF "var:defined('postBuildVariant')"!][!//
  [!VAR "postBuildVariantNameUnderscore" = "concat('_',$postBuildVariant)"!][!//
[!CODE!]#define RM_IPW_CONFIG_[!"$postBuildVariant"!]_PB \[!CR!][!ENDCODE!]
[!ELSE!][!//
  [!VAR "postBuildVariantNameUnderscore" = "string(null)"!][!//
[!CODE!]#define RM_IPW_CONFIG_PB \[!CR!][!ENDCODE!]
[!ENDIF!][!//
    [!CODE!][!WS "4"!]extern const Rm_Ipw_ConfigType Rm_Ipw_Config[!"$postBuildVariantNameUnderscore"!];[!ENDCODE!]
[!ENDNOCODE!]

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

#endif /* RM_IPW[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_H */

