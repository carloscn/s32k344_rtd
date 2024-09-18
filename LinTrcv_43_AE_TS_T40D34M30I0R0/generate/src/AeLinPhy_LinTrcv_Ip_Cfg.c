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
*   @file    AeLinPhy_LinTrcv_Ip_Cfg.c
*   @implements AeLinPhy_LinTrcv_Ip_Cfg.c_Artifact
*
*   @addtogroup AELINTRCV_IP
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
#include "AeLinPhy_LinTrcv_Ip_Cfg.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define AELINPHY_LINTRCV_IP_CFG_VENDOR_ID_C                     43
#define AELINPHY_LINTRCV_IP_CFG_AR_RELEASE_MAJOR_VERSION_C      4
#define AELINPHY_LINTRCV_IP_CFG_AR_RELEASE_MINOR_VERSION_C      7
#define AELINPHY_LINTRCV_IP_CFG_AR_RELEASE_REVISION_VERSION_C   0
#define AELINPHY_LINTRCV_IP_CFG_SW_MAJOR_VERSION_C              3
#define AELINPHY_LINTRCV_IP_CFG_SW_MINOR_VERSION_C              0
#define AELINPHY_LINTRCV_IP_CFG_SW_PATCH_VERSION_C              0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/

/* Checks against AeLinPhy_LinTrcv_Ip_Cfg.h */
#if (AELINPHY_LINTRCV_IP_CFG_VENDOR_ID_C != AELINPHY_LINTRCV_IP_CFG_VENDOR_ID)
    #error "AeLinPhy_LinTrcv_Ip_Cfg.c and AeLinPhy_LinTrcv_Ip_Cfg.h have different vendor ids"
#endif
/* Check if current file and AeLinPhy_LinTrcv_Ip_Cfg header file are of the same Autosar version */
#if ((AELINPHY_LINTRCV_IP_CFG_AR_RELEASE_MAJOR_VERSION_C    != AELINPHY_LINTRCV_IP_CFG_AR_RELEASE_MAJOR_VERSION) || \
     (AELINPHY_LINTRCV_IP_CFG_AR_RELEASE_MINOR_VERSION_C    != AELINPHY_LINTRCV_IP_CFG_AR_RELEASE_MINOR_VERSION) || \
     (AELINPHY_LINTRCV_IP_CFG_AR_RELEASE_REVISION_VERSION_C != AELINPHY_LINTRCV_IP_CFG_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of AeLinPhy_LinTrcv_Ip_Cfg.c and AeLinPhy_LinTrcv_Ip_Cfg.h are different"
#endif
/* Check if current file and AeLinPhy_LinTrcv_Ip_Cfg header file are of the same Software version */
#if ((AELINPHY_LINTRCV_IP_CFG_SW_MAJOR_VERSION_C != AELINPHY_LINTRCV_IP_CFG_SW_MAJOR_VERSION) || \
     (AELINPHY_LINTRCV_IP_CFG_SW_MINOR_VERSION_C != AELINPHY_LINTRCV_IP_CFG_SW_MINOR_VERSION) || \
     (AELINPHY_LINTRCV_IP_CFG_SW_PATCH_VERSION_C != AELINPHY_LINTRCV_IP_CFG_SW_PATCH_VERSION))
    #error "Software Version Numbers of AeLinPhy_LinTrcv_Ip_Cfg.c and AeLinPhy_LinTrcv_Ip_Cfg.h are different"
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
*                                      BUFFER DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                   STATE STRUCTURE DECLARATIONS
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
#define LINTRCV_43_AE_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "LinTrcv_43_AE_MemMap.h"
[!NOCODE!]
[!LOOP "LinTrcvChannel/*"!][!//
/**
* @brief          Hardware configuration for Lin Hardware Instance [!"LinTrcvHwChannel"!] - Configuration:
*
* 
*/
[!CODE!]

const AeLinPhy_LinTrcv_Ip_UserConfigType AeLinPhy_LinTrcv_Ip_pHwConfigPB_[!"LinTrcvChannelId"!] = 
{
    [!"num:i(substring-after(LinTrcvHwChannel,'_'))"!]U  /* Instance */
};
[!ENDCODE!]
[!ENDLOOP!][!//
[!ENDNOCODE!]
#define LINTRCV_43_AE_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "LinTrcv_43_AE_MemMap.h"
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
