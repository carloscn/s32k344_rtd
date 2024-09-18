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

#ifndef AXBS_IP_CFG_DEFINES_H
#define AXBS_IP_CFG_DEFINES_H

/**
*   @file Axbs_Ip_Cfg_Defines.h
*
*   @addtogroup AXBS_IP AXBS IPV Driver
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
[!IF "RmGeneral/RmCrossbarConfigurable"!][!//
[!NOCODE!]
	[!VAR "AXBS_Type" = "'AXBS_LITE'"!]
	[!IF "ecu:get('Rm.AXBS.AXBSLite.Support') != 'true'"!]
		[!VAR "AXBS_Type" = "'AXBS'"!]
	[!ENDIF!]
[!CODE!][!//
#include "[!"ecu:get('Rm.Common.Header.List')"!]_[!"$AXBS_Type"!].h"
[!ENDCODE!][!//
[!ENDNOCODE!]
[!ENDIF!][!//
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define RM_AXBS_IP_CFG_DEFINES_VENDOR_ID                    43
#define RM_AXBS_IP_CFG_DEFINES_AR_RELEASE_MAJOR_VERSION     4
#define RM_AXBS_IP_CFG_DEFINES_AR_RELEASE_MINOR_VERSION     7
#define RM_AXBS_IP_CFG_DEFINES_AR_RELEASE_REVISION_VERSION  0
#define RM_AXBS_IP_CFG_DEFINES_SW_MAJOR_VERSION             3
#define RM_AXBS_IP_CFG_DEFINES_SW_MINOR_VERSION             0
#define RM_AXBS_IP_CFG_DEFINES_SW_PATCH_VERSION             0
/*==================================================================================================
*                                      FILE VERSION CHECKS
==================================================================================================*/


/*==================================================================================================
*                                 GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                             ENUMS
==================================================================================================*/


/*==================================================================================================
*                                           CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/
[!IF "RmGeneral/RmCrossbarConfigurable"!]
#define RM_IP_ENABLE_AXBS                              ([!IF "RmGeneral/RmCrossbarConfigurable"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

#define RM_CROSSBAR_PRS_READONLY                       ([!IF "ecu:get('Rm.Crossbar.PRS.IsReadOnly') = 1"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

#define AXBS_IP_DEV_ERROR_DETECT                       ([!IF "RmConfigSet/Crossbar_Configuration/CrossbarDevErrorDetect"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

#define AXBS_IP_PRS_RESET_VALUE_ARRAY_U32              {[!"ecu:get('Rm.Crossbar.PRSResetValue.List')"!]}

#define AXBS_IP_CRS_RESET_VALUE_ARRAY_U32              {[!"ecu:get('Rm.Crossbar.CRSResetValue.List')"!]}
[!IF "RmGeneral/RmEnableUserModeSupport"!]
/** @brief    User mode support          */
#define AXBS_IP_ENABLE_USER_MODE_SUPPORT

#ifndef MCAL_ENABLE_USER_MODE_SUPPORT
    #ifdef AXBS_IP_ENABLE_USER_MODE_SUPPORT
        #error "MCAL_ENABLE_USER_MODE_SUPPORT is not enabled. For running AXBS in user mode the MCAL_ENABLE_USER_MODE_SUPPORT needs to be defined"
    #endif /* (STD_ON == AXBS_IP_ENABLE_USER_MODE_SUPPORT) */
#endif /* ifndef MCAL_ENABLE_USER_MODE_SUPPORT */
[!ENDIF!][!//

[!NOCODE!]
	[!VAR "AXBS_Type" = "'AXBS_LITE'"!]
	[!IF "ecu:get('Rm.AXBS.AXBSLite.Support') != 'true'"!]
		[!VAR "AXBS_Type" = "'AXBS'"!]
	[!ENDIF!]
[!CODE!][!//
/** @brief    Macro representing of support instance AXBS */
#define AXBS_IP_INSTANCE_COUNT               [!"$AXBS_Type"!]_INSTANCE_COUNT
/** @brief    Array initializer of AXBS peripheral base address */
#define AXBS_IP_ARRAY_BASE_ADDRS             IP_[!"$AXBS_Type"!]_BASE_ADDRS
[!ENDCODE!][!//
[!ENDNOCODE!]

/* Definition of AXBS Instances */
[!FOR "counter" = "1" TO "num:i(count(ecu:list('Rm.Crossbar.CrossbarInstances.List')))"!][!//
#define [!"ecu:list('Rm.Crossbar.CrossbarInstances.List')[position() = $counter]"!]                  (uint32)([!"num:i(($counter)-1)"!]U)
[!ENDFOR!][!//
[!ENDIF!]
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

#endif /* AXBS_IP_DEVICE_REGISTERS_H */
