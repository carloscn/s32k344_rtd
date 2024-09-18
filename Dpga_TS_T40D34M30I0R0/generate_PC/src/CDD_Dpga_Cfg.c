/*==================================================================================================
*   Project              : RTD AUTOSAR 4.7
*   Platform             : CORTEXM
*   Peripheral           : DPGA
*   Dependencies         : none
*
*   Autosar Version      : 4.7.0
*   Autosar Revision     : ASR_REL_4_7_REV_0000
*   Autosar Conf.Variant :
*   SW Version           : 3.0.0
*   Build Version        : S32K3_RTD_3_0_0_D2303_ASR_REL_4_7_REV_0000_20230331
*
*   Copyright 2022 NXP
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
*   @addtogroup dpga_driver_config Dpga Driver Configuration
*   @{
*/

#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
*                                          INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "CDD_Dpga.h"

/*==================================================================================================
*                                 SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define DPGA_VENDOR_ID_CFG_C                      43
#define DPGA_AR_RELEASE_MAJOR_VERSION_CFG_C       4
#define DPGA_AR_RELEASE_MINOR_VERSION_CFG_C       7
#define DPGA_AR_RELEASE_REVISION_VERSION_CFG_C    0
#define DPGA_SW_MAJOR_VERSION_CFG_C               3
#define DPGA_SW_MINOR_VERSION_CFG_C               0
#define DPGA_SW_PATCH_VERSION_CFG_C               0

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and CDD_Dpga header file are of the same vendor */
#if (DPGA_VENDOR_ID_CFG_C != DPGA_VENDOR_ID)
    #error "CDD_Dpga_Cfg.c and CDD_Dpga.h have different vendor IDs"
#endif

/* Check if current file and CDD_Dpga header file are of the same Autosar version */
#if ((DPGA_AR_RELEASE_MAJOR_VERSION_CFG_C    != DPGA_AR_RELEASE_MAJOR_VERSION) || \
     (DPGA_AR_RELEASE_MINOR_VERSION_CFG_C    != DPGA_AR_RELEASE_MINOR_VERSION) || \
     (DPGA_AR_RELEASE_REVISION_VERSION_CFG_C != DPGA_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of CDD_Dpga_Cfg.c and CDD_Dpga.h are different"
#endif

/* Check if current file and CDD_Dpga header file are of the same software version */
#if ((DPGA_SW_MAJOR_VERSION_CFG_C != DPGA_SW_MAJOR_VERSION) || \
     (DPGA_SW_MINOR_VERSION_CFG_C != DPGA_SW_MINOR_VERSION) || \
     (DPGA_SW_PATCH_VERSION_CFG_C != DPGA_SW_PATCH_VERSION))
    #error "Software Version Numbers of CDD_Dpga_Cfg.c and CDD_Dpga.h are different"
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

#ifdef __cplusplus
}
#endif

/** @} */
