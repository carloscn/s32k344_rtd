/*==================================================================================================
*   Project              : RTD AUTOSAR 4.7
*   Platform             : CORTEXM
*   Peripheral           : AE
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
*   @file   LinTrcv_43_AE_Ipw_Cfg.c
*   @implements LinTrcv_43_AE_Ipw_Cfg.c_Artifact
*
*   @internal
*   @addtogroup LINTRCV_43_AE_IPW
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
#include "LinTrcv_43_AE_Ipw_Cfg.h"
#include "AeLinPhy_LinTrcv_Ip_Cfg.h"


/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define LINTRCV_43_AE_IPW_CFG_VENDOR_ID_C                     43
#define LINTRCV_43_AE_IPW_CFG_AR_RELEASE_MAJOR_VERSION_C      4
#define LINTRCV_43_AE_IPW_CFG_AR_RELEASE_MINOR_VERSION_C      7
#define LINTRCV_43_AE_IPW_CFG_AR_RELEASE_REVISION_VERSION_C   0
#define LINTRCV_43_AE_IPW_CFG_SW_MAJOR_VERSION_C              3
#define LINTRCV_43_AE_IPW_CFG_SW_MINOR_VERSION_C              0
#define LINTRCV_43_AE_IPW_CFG_SW_PATCH_VERSION_C              0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Checks against LinTrcv_43_AE_Ipw_Cfg.h */
#if (LINTRCV_43_AE_IPW_CFG_VENDOR_ID_C != LINTRCV_43_AE_IPW_CFG_VENDOR_ID)
    #error "LinTrcv_43_AE_Ipw_Cfg.c and LinTrcv_43_AE_Ipw_Cfg.h have different vendor ids"
#endif
#if ((LINTRCV_43_AE_IPW_CFG_AR_RELEASE_MAJOR_VERSION_C    != LINTRCV_43_AE_IPW_CFG_AR_RELEASE_MAJOR_VERSION) || \
     (LINTRCV_43_AE_IPW_CFG_AR_RELEASE_MINOR_VERSION_C    != LINTRCV_43_AE_IPW_CFG_AR_RELEASE_MINOR_VERSION) || \
     (LINTRCV_43_AE_IPW_CFG_AR_RELEASE_REVISION_VERSION_C != LINTRCV_43_AE_IPW_CFG_AR_RELEASE_REVISION_VERSION))
    #error "AUTOSAR Version Numbers of LinTrcv_43_AE_Ipw_Cfg.c and LinTrcv_43_AE_Ipw_Cfg.h are different"
#endif
#if ((LINTRCV_43_AE_IPW_CFG_SW_MAJOR_VERSION_C != LINTRCV_43_AE_IPW_CFG_SW_MAJOR_VERSION) || \
     (LINTRCV_43_AE_IPW_CFG_SW_MINOR_VERSION_C != LINTRCV_43_AE_IPW_CFG_SW_MINOR_VERSION) || \
     (LINTRCV_43_AE_IPW_CFG_SW_PATCH_VERSION_C != LINTRCV_43_AE_IPW_CFG_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of LinTrcv_43_AE_Ipw_Cfg.c and LinTrcv_43_AE_Ipw_Cfg.h are different"
#endif

/* Checks against AeLinPhy_LinTrcv_Ip_Cfg.h */
#if (LINTRCV_43_AE_IPW_CFG_VENDOR_ID_C != AELINPHY_LINTRCV_IP_CFG_VENDOR_ID)
    #error "LinTrcv_43_AE_Ipw_Cfg.c and AeLinPhy_LinTrcv_Ip_Cfg.h have different vendor ids"
#endif
#if ((LINTRCV_43_AE_IPW_CFG_AR_RELEASE_MAJOR_VERSION_C    != AELINPHY_LINTRCV_IP_CFG_AR_RELEASE_MAJOR_VERSION) || \
     (LINTRCV_43_AE_IPW_CFG_AR_RELEASE_MINOR_VERSION_C    != AELINPHY_LINTRCV_IP_CFG_AR_RELEASE_MINOR_VERSION) || \
     (LINTRCV_43_AE_IPW_CFG_AR_RELEASE_REVISION_VERSION_C != AELINPHY_LINTRCV_IP_CFG_AR_RELEASE_REVISION_VERSION))
    #error "AUTOSAR Version Numbers of LinTrcv_43_AE_Ipw_Cfg.c and AeLinPhy_LinTrcv_Ip_Cfg.h are different"
#endif
#if ((LINTRCV_43_AE_IPW_CFG_SW_MAJOR_VERSION_C != AELINPHY_LINTRCV_IP_CFG_SW_MAJOR_VERSION) || \
     (LINTRCV_43_AE_IPW_CFG_SW_MINOR_VERSION_C != AELINPHY_LINTRCV_IP_CFG_SW_MINOR_VERSION) || \
     (LINTRCV_43_AE_IPW_CFG_SW_PATCH_VERSION_C != AELINPHY_LINTRCV_IP_CFG_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of LinTrcv_43_AE_Ipw_Cfg.c and AeLinPhy_LinTrcv_Ip_Cfg.h are different"
#endif

/*==================================================================================================
*                           LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
*                                          LOCAL MACROS
==================================================================================================*/

/*==================================================================================================
*                                         LOCAL CONSTANTS
==================================================================================================*/
#define LINTRCV_43_AE_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "LinTrcv_43_AE_MemMap.h"

/**
* @brief   Export AELINPHY_LINTRCV configurations.
*/
AELINPHY_LINTRCV_IP_CONFIG_EXT

/*==================================================================================================
*                                         LOCAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                        GLOBAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                        GLOBAL VARIABLES
==================================================================================================*/
[!NOCODE!]
[!LOOP "LinTrcvChannel/*"!][!//
[!CODE!][!//
/**
*
* @brief          Hardware configuration for LinTrcv Hardware Instance [!"LinTrcvHwChannel"!] - Configuration:
*
*
*/
const LinTrcv_43_AE_HwConfigType LinTrcv_43_AE_Ipw_pHwConfigPB_[!"LinTrcvChannelId"!] =
{
    [!"substring-after(LinTrcvHwChannel, '_')"!]U,       /* [!"LinTrcvHwChannel"!] */

    &AeLinPhy_LinTrcv_Ip_pHwConfigPB_[!"LinTrcvChannelId"!]
};
[!ENDCODE!]
[!ENDLOOP!][!//
[!ENDNOCODE!]

#define LINTRCV_43_AE_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "LinTrcv_43_AE_MemMap.h"
/*==================================================================================================
*                                    LOCAL FUNCTION PROTOTYPES
==================================================================================================*/

/*==================================================================================================
*                                         LOCAL FUNCTIONS
==================================================================================================*/

/*==================================================================================================
*                                        GLOBAL FUNCTIONS
==================================================================================================*/

/*==================================================================================================
*                                      LOCAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                      LOCAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      GLOBAL CONSTANTS
==================================================================================================*/


#ifdef __cplusplus
}
#endif

/** @} */
