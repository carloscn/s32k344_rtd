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
*   @file Xrdc_Ip_Cfg.c
*
*   @addtogroup XRDC_IP XRDC IPV Driver
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
#include "Xrdc_Ip_Types.h"
#include "Xrdc_Ip_Cfg.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define RM_XRDC_IP_CFG_VENDOR_ID_C                     43
#define RM_XRDC_IP_CFG_AR_RELEASE_MAJOR_VERSION_C      4
#define RM_XRDC_IP_CFG_AR_RELEASE_MINOR_VERSION_C      7
#define RM_XRDC_IP_CFG_AR_RELEASE_REVISION_VERSION_C   0
#define RM_XRDC_IP_CFG_SW_MAJOR_VERSION_C              3
#define RM_XRDC_IP_CFG_SW_MINOR_VERSION_C              0
#define RM_XRDC_IP_CFG_SW_PATCH_VERSION_C              0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Checks against Xrdc_Ip_Types.h */
#if (RM_XRDC_IP_CFG_VENDOR_ID_C != RM_XRDC_IP_TYPES_VENDOR_ID)
    #error "Xrdc_Ip_Cfg.c and Xrdc_Ip_Types.h have different vendor ids"
#endif
#if ((RM_XRDC_IP_CFG_AR_RELEASE_MAJOR_VERSION_C    != RM_XRDC_IP_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (RM_XRDC_IP_CFG_AR_RELEASE_MINOR_VERSION_C    != RM_XRDC_IP_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (RM_XRDC_IP_CFG_AR_RELEASE_REVISION_VERSION_C != RM_XRDC_IP_TYPES_AR_RELEASE_REVISION_VERSION))
     #error "AUTOSAR Version Numbers of Xrdc_Ip_Cfg.c and Xrdc_Ip_Types.h are different"
#endif
#if ((RM_XRDC_IP_CFG_SW_MAJOR_VERSION_C != RM_XRDC_IP_TYPES_SW_MAJOR_VERSION) || \
     (RM_XRDC_IP_CFG_SW_MINOR_VERSION_C != RM_XRDC_IP_TYPES_SW_MINOR_VERSION) || \
     (RM_XRDC_IP_CFG_SW_PATCH_VERSION_C != RM_XRDC_IP_TYPES_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Xrdc_Ip_Cfg.c and Xrdc_Ip_Types.h are different"
#endif

/* Checks against Xrdc_Ip_Cfg.h */
#if (RM_XRDC_IP_CFG_VENDOR_ID_C != RM_XRDC_IP_CFG_VENDOR_ID)
    #error "Xrdc_Ip_Cfg.c and Xrdc_Ip_Cfg.h have different vendor ids"
#endif
#if ((RM_XRDC_IP_CFG_AR_RELEASE_MAJOR_VERSION_C    != RM_XRDC_IP_CFG_AR_RELEASE_MAJOR_VERSION) || \
     (RM_XRDC_IP_CFG_AR_RELEASE_MINOR_VERSION_C    != RM_XRDC_IP_CFG_AR_RELEASE_MINOR_VERSION) || \
     (RM_XRDC_IP_CFG_AR_RELEASE_REVISION_VERSION_C != RM_XRDC_IP_CFG_AR_RELEASE_REVISION_VERSION))
     #error "AUTOSAR Version Numbers of Xrdc_Ip_Cfg.c and Xrdc_Ip_Cfg.h are different"
#endif
#if ((RM_XRDC_IP_CFG_SW_MAJOR_VERSION_C != RM_XRDC_IP_CFG_SW_MAJOR_VERSION) || \
     (RM_XRDC_IP_CFG_SW_MINOR_VERSION_C != RM_XRDC_IP_CFG_SW_MINOR_VERSION) || \
     (RM_XRDC_IP_CFG_SW_PATCH_VERSION_C != RM_XRDC_IP_CFG_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Xrdc_Ip_Cfg.c and Xrdc_Ip_Cfg.h are different"
#endif

/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/


/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/

/*==================================================================================================
*                                      LOCAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      LOCAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                      GLOBAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/

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

