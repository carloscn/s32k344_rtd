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

#ifndef DPGA_IP_CFGDEFINES_H
#define DPGA_IP_CFGDEFINES_H

/**
*   @file
*
*   @addtogroup dpga_ip_config Dpga IPL Configuration
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
#include "StandardTypes.h"
#include "OsIf.h"
#include "[!"ecu:get('Dpga.DpgaHeaderName')"!].h"

[!IF "GeneralConfiguration/DpgaIpDevErrorDetect"!][!//
#include "Devassert.h"
[!ENDIF!][!//
[!NOCODE!][!//
[!INCLUDE "Dpga_RegOperations.m"!][!//
[!ENDNOCODE!][!//

/*==================================================================================================
*                                 SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define DPGA_IP_VENDOR_ID_CFGDEFINES                    43
#define DPGA_IP_AR_RELEASE_MAJOR_VERSION_CFGDEFINES     4
#define DPGA_IP_AR_RELEASE_MINOR_VERSION_CFGDEFINES     7
#define DPGA_IP_AR_RELEASE_REVISION_VERSION_CFGDEFINES  0
#define DPGA_IP_SW_MAJOR_VERSION_CFGDEFINES             3
#define DPGA_IP_SW_MINOR_VERSION_CFGDEFINES             0
#define DPGA_IP_SW_PATCH_VERSION_CFGDEFINES             0

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
/* Check if current file and StandardTypes header file are of the same Autosar version */
#if ((DPGA_IP_AR_RELEASE_MAJOR_VERSION_CFGDEFINES     != STD_AR_RELEASE_MAJOR_VERSION) || \
     (DPGA_IP_AR_RELEASE_MINOR_VERSION_CFGDEFINES     != STD_AR_RELEASE_MINOR_VERSION))
    #error "AutoSar Version Numbers of Dpga_Ip_CfgDefines.h and StandardTypes.h are different"
#endif

/* Check if current file and OsIf header file are of the same Autosar version */
#if ((DPGA_IP_AR_RELEASE_MAJOR_VERSION_CFGDEFINES     != OSIF_AR_RELEASE_MAJOR_VERSION) || \
     (DPGA_IP_AR_RELEASE_MINOR_VERSION_CFGDEFINES     != OSIF_AR_RELEASE_MINOR_VERSION))
    #error "AutoSar Version Numbers of Dpga_Ip_CfgDefines.h and OsIf.h are different"
#endif
[!IF "GeneralConfiguration/DpgaIpDevErrorDetect"!][!//

/* Check if current file and Devassert.h header file are of the same Autosar version */
#if ((DPGA_IP_AR_RELEASE_MAJOR_VERSION_CFGDEFINES != DEVASSERT_AR_RELEASE_MAJOR_VERSION) || \
     (DPGA_IP_AR_RELEASE_MINOR_VERSION_CFGDEFINES != DEVASSERT_AR_RELEASE_MINOR_VERSION))
    #error "AutoSar Version Numbers of Dpga_Ip_CfgDefines.h and Devassert.h are different"
#endif
[!ENDIF!][!//
#endif /* DISABLE_MCAL_INTERMODULE_ASR_CHECK */

/*==================================================================================================
*                                            CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/
[!CALL "Dpga_Ip_ConfigDef"!][!//

/*==================================================================================================
*                                              ENUMS
==================================================================================================*/

/*==================================================================================================
*                                  STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

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

#endif /* DPGA_IP_CFGDEFINES_H */