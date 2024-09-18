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

#ifndef SEMA42_IP_CFG_DEFINES_H_
#define SEMA42_IP_CFG_DEFINES_H_

/**
*   @file Sema42_Ip_CfgDefines.h
*
*   @addtogroup Sema42_Ip Sema42 IPV Driver
*   @{
*/

#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
                                         INCLUDE FILES
==================================================================================================*/
/**
 * Include specific header file
 */
#include "StandardTypes.h"
[!IF "RmGeneral/RmEnableSema42Support"!][!//
#include "[!"ecu:get('Rm.Common.Header.List')"!]_SEMA42.h"
[!ENDIF!][!//

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define RM_SEMA42_IP_CFG_DEFINES_VENDOR_ID                    43
#define RM_SEMA42_IP_CFG_DEFINES_AR_RELEASE_MAJOR_VERSION     4
#define RM_SEMA42_IP_CFG_DEFINES_AR_RELEASE_MINOR_VERSION     7
#define RM_SEMA42_IP_CFG_DEFINES_AR_RELEASE_REVISION_VERSION  0
#define RM_SEMA42_IP_CFG_DEFINES_SW_MAJOR_VERSION             3
#define RM_SEMA42_IP_CFG_DEFINES_SW_MINOR_VERSION             0
#define RM_SEMA42_IP_CFG_DEFINES_SW_PATCH_VERSION             0


/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
/* Checks against StandardTypes.h */
#if ((RM_SEMA42_IP_CFG_DEFINES_AR_RELEASE_MAJOR_VERSION != STD_AR_RELEASE_MAJOR_VERSION) || \
    (RM_SEMA42_IP_CFG_DEFINES_AR_RELEASE_MINOR_VERSION  != STD_AR_RELEASE_MINOR_VERSION))
    #error "AutoSar Version Numbers of Sema42_Ip_Cfg_Defines.h and StandardTypes.h are different"
#endif
#endif

/*==================================================================================================
*                                            CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/
[!IF "RmGeneral/RmEnableSema42Support"!]
/** @brief    Development error checking */
#define SEMA42_IP_DEV_ERROR_DETECT            ([!IF "RmConfigSet/Sema42_ModuleConfig/Sema42DevErrorDetect"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])
[!IF "RmGeneral/RmEnableUserModeSupport"!][!//
/** @brief    User mode support          */
#define SEMA42_IP_ENABLE_USER_MODE_SUPPORT
#ifndef MCAL_ENABLE_USER_MODE_SUPPORT
    #ifdef SEMA42_IP_ENABLE_USER_MODE_SUPPORT
        #error "MCAL_ENABLE_USER_MODE_SUPPORT is not enabled. For running SEMA42 in user mode the MCAL_ENABLE_USER_MODE_SUPPORT needs to be defined"
    #endif /* (ifdef SEMA42_IP_ENABLE_USER_MODE_SUPPORT) */
#endif /* ifndef MCAL_ENABLE_USER_MODE_SUPPORT */
[!ENDIF!][!//

/** @brief    Macro representing sum of instance Sema42 */
#define SEMA42_IP_INSTANCE_COUNT              SEMA42_INSTANCE_COUNT
/** @brief    Macro representing Array initializer of SEMA42 peripheral base pointers */
#define SEMA42_IP_ARRAY_BASE_PTRS             IP_SEMA42_BASE_PTRS

/** @brief    List Macro representing number instance of all of instance Sema42 */
[!NOCODE!][!//
[!VAR "Space" = "'                                     '"!][!//
[!FOR "counter" = "1" TO "num:i(count(ecu:list('Rm.Sema42.HardwareInstance.List')))"!]
[!VAR "SemaInstance" = "ecu:list('Rm.Sema42.HardwareInstance.List')[position() = $counter]"!]
[!CODE!][!//
#define [!"$SemaInstance"!][!"substring($Space,string-length($SemaInstance))"!]([!"num:i($counter -1)"!]U)
[!ENDCODE!][!//
[!ENDFOR!]
[!ENDNOCODE!][!//

#define SEMA42_IP_SUPPORT                     ([!IF "RmGeneral/RmEnableSema42Support"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])
/** @brief    Macro representing number of Domain Id */
#define SEMA42_IP_DOMAIN_ID_NUMBER            ([!"num:i(count(ecu:list('Rm.XRDC.DomainID.List')))"!]U)
/** @brief    Macro representing an unlocked gate */
#define SEMA42_IP_UNLOCKED_GATE               (0xFFU)
/** @brief    Macro representing an unknown gate */
#define SEMA42_IP_UNKNOWN_GATE                (0xFFU)
/** @brief    Macro representing an unknown domain ID that owns Sema42 */
#define SEMA42_IP_UNKNOWN_DOMAINID            (0xF0U)
/** @brief    Macro representing all gate are reseted */
#define SEMA42_IP_RESET_GATE_ALL              (0x40U)
/** @brief    Macro representing an unlocked gate value */
#define SEMA42_IP_UNLOCKED_GATE_VALUE         ([!"ecu:get('Rm.Sema42.UnlockedGate')"!]U)
/** @brief    Macro used for creating the lock value */
#define SEMA42_IP_GATE_LOCK(x)                (((x) +1UL))
/** @brief    Macro representing the first write sequence for a gate reset */
#define SEMA42_IP_RSTGT_FIRST_WRITE_SEQUENCE  ([!"ecu:get('Rm.Sema42.FirstWriteSequence')"!])
/** @brief    Macro representing the second write sequence for a gate reset */
#define SEMA42_IP_RSTGT_SECOND_WRITE_SEQUENCE ([!"ecu:get('Rm.Sema42.SecondWriteSequence')"!])
/** @brief    Macro representing an idle reset gate */
#define SEMA42_IP_RESET_GATE_IDLE             ([!"ecu:get('Rm.Sema42.ResetGateIdle')"!]U)
/** @brief    Macro used to translate between logic and physical gate offset */
#define SEMA42_IP_GATE_OFFSET(x)              ((x) ^ ((uint8)[!"ecu:get('Rm.Sema42.GateOffset')"!]UL))
[!ENDIF!][!//

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

#endif /* SEMA42_IP_CFG_DEFINES_H_ */

