[!CODE!][!//
[!AUTOSPACING!][!//
/*==================================================================================================
*   Project              : RTD AUTOSAR 4.7
*   Platform             : CORTEXM
*   Peripheral           : Emios Siul2 Wkpu LpCmp
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

#ifndef CMP_IP_DEFINES_H
#define CMP_IP_DEFINES_H

/**
 *   @file    Cmp_Ip_Defines.h
 *   @version 3.0.0
 *
 *   @brief   AUTOSAR Icu - contains the data exported by the Icu module
 *   @details Contains the information that will be exported by the module, as requested by Autosar.
 *
 *   @addtogroup cmp_icu_ip CMP IPL
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
 *================================================================================================*/
#include "Std_Types.h"
[!NOCODE!][!//
[!IF "node:exists(as:modconf("Resource")[1]/ResourceGeneral/ResourceSubderivative)"!][!//
    [!VAR "DerivativeName" = "text:toupper(substring-before(as:modconf("Resource")[1]/ResourceGeneral/ResourceSubderivative,'_'))"!][!//
    [!CODE!][!WS "0"!]/* Include platform header file. */[!CR!][!ENDCODE!][!//
    [!IF "contains($DerivativeName, 'S32K1')"!][!//
        [!CODE!][!WS "0"!]#include "[!"$DerivativeName"!]_CMP.h"[!CR!][!ENDCODE!][!//
    [!ELSEIF "contains($DerivativeName, 'S32K3')"!][!//
        [!IF "contains($DerivativeName, 'S32K328') or contains($DerivativeName, 'S32K338') or contains($DerivativeName, 'S32K348')"!][!//
            [!CODE!][!WS "0"!]#include "S32K358_LPCMP.h"[!CR!][!ENDCODE!][!//
        [!ELSEIF "contains($DerivativeName, 'S32K39')"!][!//
            [!CODE!][!WS "0"!]#include "S32K39_LPCMP.h"[!CR!][!ENDCODE!][!//
        [!ELSEIF "contains($DerivativeName, 'S32K310')"!][!//
            [!CODE!][!WS "0"!]#include "S32K311_LPCMP.h"[!CR!][!ENDCODE!][!//
        [!ELSE!]
            [!CODE!][!WS "0"!]#include "[!"$DerivativeName"!]_LPCMP.h"[!CR!][!ENDCODE!][!//
        [!ENDIF!][!//
    [!ELSEIF "contains($DerivativeName, 'S32M24')"!][!//
        [!CODE!][!WS "0"!]#include "S32M24x_CMP.h"[!CR!][!ENDCODE!][!//
    [!ELSEIF "contains($DerivativeName, 'S32M27')"!][!//
        [!CODE!][!WS "0"!]#include "S32M27x_LPCMP.h"[!CR!][!ENDCODE!][!//
    [!ENDIF!][!//
[!ENDIF!][!//

[!ENDNOCODE!][!//

/*==================================================================================================
 *                              SOURCE FILE VERSION INFORMATION
 *================================================================================================*/
#define CMP_IP_DEFINES_VENDOR_ID                    43
#define CMP_IP_DEFINES_AR_RELEASE_MAJOR_VERSION     4
#define CMP_IP_DEFINES_AR_RELEASE_MINOR_VERSION     7
#define CMP_IP_DEFINES_AR_RELEASE_REVISION_VERSION  0
#define CMP_IP_DEFINES_SW_MAJOR_VERSION             3
#define CMP_IP_DEFINES_SW_MINOR_VERSION             0
#define CMP_IP_DEFINES_SW_PATCH_VERSION             0

/*==================================================================================================
 *                                      FILE VERSION CHECKS
 *================================================================================================*/

/* Check if header file and Std_Types.h file are of the same Autosar version */
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if ((CMP_IP_DEFINES_AR_RELEASE_MAJOR_VERSION != STD_AR_RELEASE_MAJOR_VERSION) || \
         (CMP_IP_DEFINES_AR_RELEASE_MINOR_VERSION != STD_AR_RELEASE_MINOR_VERSION))
    #error "AutoSar Version Numbers of Cmp_Ip_Defines.h and Std_Types.h are different"
    #endif
#endif

/*==================================================================================================
                                       DEFINES AND MACROS
==================================================================================================*/
[!NOCODE!][!//
[!VAR "CheckCmpSupport" = "0"!][!//
[!SELECT "IcuConfigSet"!][!//
    [!LOOP "./IcuChannel/*"!][!//
        [!IF "contains(node:path(node:ref(./IcuChannelRef)), 'IcuLpCmp')"!][!//
            [!VAR "CheckCmpSupport" = "$CheckCmpSupport + 1"!][!//
        [!ENDIF!][!//
    [!ENDLOOP!][!//
[!ENDSELECT!]

[!CODE!]#define CMP_IP_USED               [!IF "$CheckCmpSupport != 0"!](STD_ON)[!ELSE!](STD_OFF)[!ENDIF!][!CR!][!CR!][!ENDCODE!]

[!CODE!][!WS "0"!]#if (STD_ON == CMP_IP_USED)[!CR!][!ENDCODE!][!//

[!IF "node:exists(as:modconf("Resource")[1]/ResourceGeneral/ResourceSubderivative)"!][!//
    [!VAR "DerivativeName" = "text:toupper(substring-before(as:modconf("Resource")[1]/ResourceGeneral/ResourceSubderivative,'_'))"!][!//
    [!IF "contains($DerivativeName, 'S32K1') or contains($DerivativeName, 'S32M24')"!][!//
        [!CODE!][!WS "0"!]#define CMP_IP_NOT_SUPPORT_LOWPOWER[!CR!][!ENDCODE!][!//

        [!CODE!][!WS "0"!]#define ICU_CMP_INSTANCE_COUNT    (CMP_INSTANCE_COUNT)[!CR!][!ENDCODE!][!//
    [!ENDIF!][!//
    [!IF "contains($DerivativeName, 'S32K3') or contains($DerivativeName, 'S32M27')"!][!//
        [!CODE!][!WS "0"!]#define CMP_IP_SUPPORT_LOWPOWER[!CR!][!ENDCODE!][!//

        [!CODE!][!WS "0"!]#define ICU_CMP_INSTANCE_COUNT    (LPCMP_INSTANCE_COUNT)[!CR!][!ENDCODE!][!//
    [!ENDIF!][!//
[!ENDIF!][!//

[!ENDNOCODE!][!//

/** @brief Adds or removes all services related to input state functionality. */
#define CMP_IP_GET_INPUT_STATE_API          ([!IF "IcuOptionalApis/IcuGetInputStateApi"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

[!SELECT "./IcuConfigSet"!]
[!IF "count(IcuLpCmp/*) > '0'"!][!//
[!LOOP "IcuLpCmp/*"!][!//
    [!CODE!]#define ICU_CMP_[!"node:value(IcuCmpInstanceNumber)"!]_ISR_USED (STD_ON)[!CR!][!ENDCODE!][!//
[!ENDLOOP!][!//
[!ENDIF!]
[!ENDSELECT!]

#define     CMP_IP_DEV_ERROR_DETECT        ([!IF "IcuGeneral/IcuDevErrorDetect"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

#endif /* CMP_IP_USED */

#ifdef __cplusplus
}
#endif

/** @} */

#endif  /* CMP_IP_DEFINES_H */
[!ENDCODE!]
