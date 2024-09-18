[!CODE!][!//
/*==================================================================================================
*   Project              : RTD AUTOSAR 4.7
*   Platform             : CORTEXM
*   Peripheral           : MEM_OTP_IP
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
*
*   @addtogroup OCOTP
*   @{
*/

#ifdef __cplusplus
extern "C"{
#endif

[!INDENT "0"!]
/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "CDD_Ocotp.h"
[!ENDINDENT!][!//
#ifdef OCOTP_PRECOMPILE_SUPPORT

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define OCOTP_VENDOR_ID_PCFG_C                      43
#define OCOTP_AR_RELEASE_MAJOR_VERSION_PCFG_C       4
#define OCOTP_AR_RELEASE_MINOR_VERSION_PCFG_C       7
#define OCOTP_AR_RELEASE_REVISION_VERSION_PCFG_C    0
#define OCOTP_SW_MAJOR_VERSION_PCFG_C               3
#define OCOTP_SW_MINOR_VERSION_PCFG_C               0
#define OCOTP_SW_PATCH_VERSION_PCFG_C               0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and Ocotp header file are of the same vendor */
#if (OCOTP_VENDOR_ID_PCFG_C != CDD_OCOTP_VENDOR_ID)
    #error "Ocotp_Cfg.c and Ocotp.h have different vendor ids"
#endif
/* Check if current file and Ocotp header file are of the same Autosar version */
#if ((OCOTP_AR_RELEASE_MAJOR_VERSION_PCFG_C    != CDD_OCOTP_AR_RELEASE_MAJOR_VERSION) || \
     (OCOTP_AR_RELEASE_MINOR_VERSION_PCFG_C    != CDD_OCOTP_AR_RELEASE_MINOR_VERSION) || \
     (OCOTP_AR_RELEASE_REVISION_VERSION_PCFG_C != CDD_OCOTP_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Ocotp_Cfg.c and Ocotp.h are different"
#endif
/* Check if current file and Ocotp header file are of the same Software version */
#if ((OCOTP_SW_MAJOR_VERSION_PCFG_C != CDD_OCOTP_SW_MAJOR_VERSION) || \
     (OCOTP_SW_MINOR_VERSION_PCFG_C != CDD_OCOTP_SW_MINOR_VERSION) || \
     (OCOTP_SW_PATCH_VERSION_PCFG_C != CDD_OCOTP_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Ocotp_Cfg.c and Ocotp.h are different"
#endif

[!INCLUDE "Ocotp_VersionCheck.m"!][!//

/*==================================================================================================
*                           LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
*                                          LOCAL MACROS
==================================================================================================*/

/*==================================================================================================
*                                         LOCAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                         LOCAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                        GLOBAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                        GLOBAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                    LOCAL FUNCTION PROTOTYPES
==================================================================================================*/

/*==================================================================================================
*                                         LOCAL FUNCTIONS
==================================================================================================*/

/*==================================================================================================
*                                        GLOBAL FUNCTIONS
==================================================================================================*/

[!ENDCODE!]


#endif /* OCOTP_PRECOMPILE_SUPPORT */
#ifdef __cplusplus
}
#endif

/** @}*/
