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

#ifndef DPGA_TYPES_H
#define DPGA_TYPES_H

/**
*   @file
*
*   @addtogroup dpga
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
#include "CDD_Dpga_CfgDefines.h"
#include "Dpga_Ip_Types.h"

/*==================================================================================================
*                                 SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define DPGA_VENDOR_ID_TYPES                    43
#define DPGA_MODULE_ID_TYPES                    255
#define DPGA_AR_RELEASE_MAJOR_VERSION_TYPES     4
#define DPGA_AR_RELEASE_MINOR_VERSION_TYPES     7
#define DPGA_AR_RELEASE_REVISION_VERSION_TYPES  0
#define DPGA_SW_MAJOR_VERSION_TYPES             3
#define DPGA_SW_MINOR_VERSION_TYPES             0
#define DPGA_SW_PATCH_VERSION_TYPES             0

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and CDD_Dpga_CfgDefines header file are of the same vendor */
#if (DPGA_VENDOR_ID_TYPES != DPGA_VENDOR_ID_CFGDEFINES)
    #error "CDD_Dpga_Types.h and CDD_Dpga_CfgDefines.h have different vendor ids"
#endif

/* Check if current file and CDD_Dpga_CfgDefines header file are of the same Autosar version */
#if ((DPGA_AR_RELEASE_MAJOR_VERSION_TYPES     != DPGA_AR_RELEASE_MAJOR_VERSION_CFGDEFINES) || \
     (DPGA_AR_RELEASE_MINOR_VERSION_TYPES     != DPGA_AR_RELEASE_MINOR_VERSION_CFGDEFINES) || \
     (DPGA_AR_RELEASE_REVISION_VERSION_TYPES  != DPGA_AR_RELEASE_REVISION_VERSION_CFGDEFINES))
    #error "AutoSar Version Numbers of CDD_Dpga_Types.h and CDD_Dpga_CfgDefines.h are different"
#endif

/* Check if current file and CDD_Dpga_CfgDefines header file are of the same software version */
#if ((DPGA_SW_MAJOR_VERSION_TYPES != DPGA_SW_MAJOR_VERSION_CFGDEFINES) || \
     (DPGA_SW_MINOR_VERSION_TYPES != DPGA_SW_MINOR_VERSION_CFGDEFINES) || \
     (DPGA_SW_PATCH_VERSION_TYPES != DPGA_SW_PATCH_VERSION_CFGDEFINES))
    #error "Software Version Numbers of CDD_Dpga_Types.h and CDD_Dpga_CfgDefines.h are different"
#endif

/* Check if current file and Dpga_Ip_Types header file are of the same vendor */
#if (DPGA_VENDOR_ID_TYPES != DPGA_IP_VENDOR_ID_TYPES)
    #error "CDD_Dpga_Types.h and Dpga_Ip_Types.h have different vendor ids"
#endif

/* Check if current file and Dpga_Ip_Types header file are of the same Autosar version */
#if ((DPGA_AR_RELEASE_MAJOR_VERSION_TYPES     != DPGA_IP_AR_RELEASE_MAJOR_VERSION_TYPES) || \
     (DPGA_AR_RELEASE_MINOR_VERSION_TYPES     != DPGA_IP_AR_RELEASE_MINOR_VERSION_TYPES) || \
     (DPGA_AR_RELEASE_REVISION_VERSION_TYPES  != DPGA_IP_AR_RELEASE_REVISION_VERSION_TYPES))
    #error "AutoSar Version Numbers of CDD_Dpga_Types.h and Dpga_Ip_Types.h are different"
#endif

/* Check if current file and Dpga_Ip_Types header file are of the same software version */
#if ((DPGA_SW_MAJOR_VERSION_TYPES != DPGA_IP_SW_MAJOR_VERSION_TYPES) || \
     (DPGA_SW_MINOR_VERSION_TYPES != DPGA_IP_SW_MINOR_VERSION_TYPES) || \
     (DPGA_SW_PATCH_VERSION_TYPES != DPGA_IP_SW_PATCH_VERSION_TYPES))
    #error "Software Version Numbers of CDD_Dpga_Types.h and Dpga_Ip_Types.h are different"
#endif

/*==================================================================================================
*                                            CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/

/*==================================================================================================
*                                              ENUMS
==================================================================================================*/

/*==================================================================================================
*                                  STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/
/**
* @brief Differential Amplifier configuration structure
*        This structure is used to provide the configuration parameters for the Differential Amplifier.
*
*/
typedef Dpga_Ip_AmplifierConfigType Dpga_AmplifierConfigType;

/**
* @brief Dpga module configuration structure
*        This structure is used to provide the configuration parameters for the Dpga module.
*
*/
typedef Dpga_Ip_ConfigType Dpga_ConfigType;

/*==================================================================================================
*                                  GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                       FUNCTION PROTOTYPES
==================================================================================================*/


#ifdef __cplusplus
}
#endif

/** @} */

#endif /* DPGA_TYPES_H */
