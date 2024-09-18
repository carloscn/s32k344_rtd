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

#ifndef PFLASH_IP_CFG_DEFINES_H
#define PFLASH_IP_CFG_DEFINES_H

/**
*   @file Pflash_Ip_Cfg_Defines.h
*
*   @addtogroup Pflash_Ip Pflash IPV Driver
*   @{
*/


#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
*                                         INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
/**
 * Include specific header file
 */
#include "StandardTypes.h"
[!IF "RmGeneral/RmPflashConfigurable"!]
#include "[!"ecu:get('Rm.Common.Header.List')"!]_PFLASH.h"
[!ENDIF!][!//
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define RM_PFLASH_IP_CFG_DEFINES_VENDOR_ID                    43
#define RM_PFLASH_IP_CFG_DEFINES_AR_RELEASE_MAJOR_VERSION     4
#define RM_PFLASH_IP_CFG_DEFINES_AR_RELEASE_MINOR_VERSION     7
#define RM_PFLASH_IP_CFG_DEFINES_AR_RELEASE_REVISION_VERSION  0
#define RM_PFLASH_IP_CFG_DEFINES_SW_MAJOR_VERSION             3
#define RM_PFLASH_IP_CFG_DEFINES_SW_MINOR_VERSION             0
#define RM_PFLASH_IP_CFG_DEFINES_SW_PATCH_VERSION             0
/*==================================================================================================
*                                      FILE VERSION CHECKS
==================================================================================================*/


/*==================================================================================================
*                                 GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                           CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/
[!IF "RmGeneral/RmPflashConfigurable"!]
[!IF "RmGeneral/RmEnableUserModeSupport"!]
/** @brief    User mode support          */
#define PFLASH_IP_ENABLE_USER_MODE_SUPPORT

#ifndef MCAL_ENABLE_USER_MODE_SUPPORT
    #ifdef PFLASH_IP_ENABLE_USER_MODE_SUPPORT
        #error "MCAL_ENABLE_USER_MODE_SUPPORT is not enabled. For running PFLASH in user mode the MCAL_ENABLE_USER_MODE_SUPPORT needs to be defined"
    #endif /* (STD_ON == PFLASH_IP_ENABLE_USER_MODE_SUPPORT) */
#endif /* ifndef MCAL_ENABLE_USER_MODE_SUPPORT */
[!ENDIF!][!// <-- RmEnableUserModeSupport -->
[!ENDIF!][!// <-- RmPflashConfigurable -->

/**
 * @brief		Define MAP fields in PFAPR register
 */
#define PFLASH_M15AP					0u
#define PFLASH_M14AP					1u
#define PFLASH_M13AP					2u
#define PFLASH_M12AP					3u
#define PFLASH_M11AP					4u
#define PFLASH_M10AP					5u
#define PFLASH_M9AP						6u
#define PFLASH_M8AP						7u
#define PFLASH_M7AP						8u
#define PFLASH_M6AP						9u
#define PFLASH_M5AP						10u
#define PFLASH_M4AP						11u
#define PFLASH_M3AP						12u
#define PFLASH_M2AP						13u
#define PFLASH_M1AP						14u
#define PFLASH_M0AP						15u

/*==================================================================================================
*                                             ENUMS
==================================================================================================*/
/**
* @brief          Enumeration listing Pflash master access protection field
*/
typedef enum
{
[!VAR "masterCount"	= "num:i(count(ecu:list('Rm.Pflash.Master.List')))"!][!// Number of Pflash Master Config
[!FOR "Count" = "1" TO "$masterCount"!][!//
	[!VAR "masterName" = "(ecu:list('Rm.Pflash.Master.List'))[position()=$Count]"!][!//
	[!VAR "masterMAP" = "(ecu:list('Rm.Pflash.MAP.List'))[position()=$Count]"!][!//
	[!"$masterName"!]=[!"$masterMAP"!][!IF "(num:i($Count))<(num:i($masterCount))"!],[!ENDIF!][!CR!][!//
[!ENDFOR!][!//
} Pflash_Ip_MasterType;

/*==================================================================================================
*                                 STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/


/*==================================================================================================
*                                      FUNCTION PROTOTYPES
==================================================================================================*/


#ifdef __cplusplus
}
#endif

/** @} */

#endif /* PFLASH_IP_DEVICE_REGISTERS_H */


