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

#ifndef SIUL2_ICU_IP_DEFINES_H
#define SIUL2_ICU_IP_DEFINES_H

/**
 *   @file       Siul2_Icu_Ip_Defines.h
 *   @version    3.0.0
 *
 *   @brief      AUTOSAR Icu - contains the data exported by the Icu module
 *   @details    Contains the information that will be exported by the module, as requested by Autosar.
 *
 *   @addtogroup siul2_icu_ip SIUL2 IPL
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
[!NOCODE!][!// Include specific header file

[!IF "node:exists(as:modconf("Resource")[1]/ResourceGeneral/ResourceSubderivative)"!][!//
    [!VAR "DerivativeName" = "text:toupper(substring-before(as:modconf("Resource")[1]/ResourceGeneral/ResourceSubderivative,'_'))"!]
    [!VAR "SiulBaseAddr" = "'IP_SIUL2_BASE_PTRS'"!]
    [!CODE!][!WS "0"!]/* Include platform header file. */[!CR!][!ENDCODE!][!//

    [!IF "contains($DerivativeName, 'S32K3')"!][!//
        [!IF "contains($DerivativeName, 'S32K328') or contains($DerivativeName, 'S32K338') or contains($DerivativeName, 'S32K348')"!][!//
            [!CODE!][!WS "0"!]#include "S32K358_SIUL2.h"[!CR!][!ENDCODE!][!//
        [!ELSEIF "contains($DerivativeName, 'S32K39')"!][!//
            [!CODE!][!WS "0"!]#include "S32K39_SIUL2.h"[!CR!][!ENDCODE!][!//
        [!ELSEIF "contains($DerivativeName, 'S32K310')"!][!//
            [!CODE!][!WS "0"!]#include "S32K311_SIUL2.h"[!CR!][!ENDCODE!][!//
        [!ELSE!]
            [!CODE!][!WS "0"!]#include "[!"$DerivativeName"!]_SIUL2.h"[!CR!][!ENDCODE!][!//
        [!ENDIF!][!//
    [!ENDIF!][!//

    [!IF "contains($DerivativeName, 'S32M27')"!][!//
        [!CODE!][!WS "0"!]#include "S32M27x_SIUL2.h"[!CR!][!ENDCODE!][!//
    [!ENDIF!][!//
    [!IF "contains($DerivativeName, 'S32R41')"!][!//
        [!CODE!][!WS "0"!]#include "S32R41_SIUL2.h"[!CR!][!ENDCODE!][!//
    [!ENDIF!][!//
    [!IF "contains($DerivativeName, 'S32R45')"!][!//
        [!CODE!][!WS "0"!]#include "S32R45_SIUL2.h"[!CR!][!ENDCODE!][!//
    [!ENDIF!][!//
    [!IF "contains($DerivativeName, 'SAF85')"!][!//
        [!CODE!][!WS "0"!]#include "SAF85XX_SIUL2.h"[!CR!][!ENDCODE!][!//
    [!ENDIF!][!//
    [!IF "contains($DerivativeName, 'S32G2')"!][!//
        [!CODE!][!WS "0"!]#include "S32G274A_SIUL2.h"[!CR!][!ENDCODE!][!//
    [!ENDIF!][!//
    [!IF "contains($DerivativeName, 'S32E')"!][!//
        [!CODE!][!WS "0"!]#include "S32E2_SIUL2.h"[!CR!][!ENDCODE!][!//
        [!VAR "SiulBaseAddr" = "'{ IP_SIUL2_0, IP_SIUL2_1, NULL_PTR, IP_SIUL2_3, IP_SIUL2_4, IP_SIUL2_5, IP_SIUL2_AE }'"!]
    [!ENDIF!][!//
    [!IF "contains($DerivativeName, 'S32Z')"!][!//
        [!CODE!][!WS "0"!]#include "S32Z2_SIUL2.h"[!CR!][!ENDCODE!][!//
        [!VAR "SiulBaseAddr" = "'{ IP_SIUL2_0, IP_SIUL2_1, NULL_PTR, IP_SIUL2_3, IP_SIUL2_4, IP_SIUL2_5 }'"!]
    [!ENDIF!][!//
    [!IF "contains($DerivativeName, 'S32G3')"!][!//
        [!CODE!][!WS "0"!]#include "S32G399A_SIUL2.h"[!CR!][!ENDCODE!][!//
    [!ENDIF!][!//
[!ENDIF!][!//

[!ENDNOCODE!][!//

/*==================================================================================================
 *                              SOURCE FILE VERSION INFORMATION
 *================================================================================================*/
#define SIUL2_ICU_IP_DEFINES_VENDOR_ID                      43
#define SIUL2_ICU_IP_DEFINES_AR_RELEASE_MAJOR_VERSION       4
#define SIUL2_ICU_IP_DEFINES_AR_RELEASE_MINOR_VERSION       7
#define SIUL2_ICU_IP_DEFINES_AR_RELEASE_REVISION_VERSION    0
#define SIUL2_ICU_IP_DEFINES_SW_MAJOR_VERSION               3
#define SIUL2_ICU_IP_DEFINES_SW_MINOR_VERSION               0
#define SIUL2_ICU_IP_DEFINES_SW_PATCH_VERSION               0

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if header file and Std_Types.h file are of the same Autosar version */
    #if ((SIUL2_ICU_IP_DEFINES_AR_RELEASE_MAJOR_VERSION != STD_AR_RELEASE_MAJOR_VERSION) || \
         (SIUL2_ICU_IP_DEFINES_AR_RELEASE_MINOR_VERSION != STD_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of Siul2_Icu_Ip_Defines.h and Std_Types.h are different"
    #endif
#endif

/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/
[!NOCODE!]
[!VAR "CheckSiul2Support" = "0"!][!//
[!SELECT "IcuConfigSet"!][!//
    [!LOOP "./IcuChannel/*"!][!//
        [!IF "contains(node:path(node:ref(./IcuChannelRef)), 'IcuSiul2')"!][!//
            [!VAR "CheckSiul2Support" = "$CheckSiul2Support + 1"!][!//
        [!ENDIF!][!//
    [!ENDLOOP!][!//
[!ENDSELECT!]

[!CODE!]#define SIUL2_ICU_IP_USED               [!IF "$CheckSiul2Support != 0"!](STD_ON)[!ELSE!](STD_OFF)[!ENDIF!][!CR!][!CR!][!ENDCODE!]

[!CODE!][!WS "0"!]#if (STD_ON == SIUL2_ICU_IP_USED)[!CR!][!ENDCODE!][!//
[!ENDNOCODE!]

/* Redefines the address table of the Siul2 instance. */
#define SIUL2_ICU_IP_BASE_PTRS      [!"$SiulBaseAddr"!]

/** @brief Switches the Development Error Detection and Notification on or off.  */
#define SIUL2_ICU_IP_DEV_ERROR_DETECT        ([!IF "IcuGeneral/IcuDevErrorDetect"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

/** @brief The number of Siul2 instances available on platform */
#define SIUL2_ICU_IP_NUM_OF_INSTANCES        ([!"ecu:get('Icu.Num_Siul2_Hw_Modules')"!]U)

/** @brief The number of channels available on each instance */
#define SIUL2_ICU_IP_NUM_OF_CHANNELS         ([!"ecu:get('Icu.Num_Siul2_Hw_Channels')"!]U)

/** @brief The number of Siul2 channels are used in configuration */
#define SIUL2_ICU_IP_NUM_OF_CHANNELS_USED    ((uint8)[!"num:i($CheckSiul2Support)"!]U)

/** @brief Adds or removes all services related to the de-initialization functionality. */
#define SIUL2_ICU_IP_DEINIT_API                 ([!IF "IcuOptionalApis/IcuDeInitApi"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

/** @brief Adds or removes all services related to mode set functionality. */
#define SIUL2_ICU_IP_SET_MODE_API               ([!IF "IcuOptionalApis/IcuSetModeApi"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

/** @brief Adds or removes all services related to dual clock edge functionality. */
#define SIUL2_ICU_IP_DUAL_CLOCK_MODE_API        ([!IF "IcuAutosarExt/IcuEnableDualClockMode"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

/** @brief Add or remove all functions related to input state. */
#define SIUL2_ICU_IP_GET_INPUT_STATE_API        ([!IF "IcuOptionalApis/IcuGetInputStateApi"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

/** @brief Support for User mode. If this parameter has been configured to 'STD_ON', the FTM driver 
 *         code can be executed from both supervisor and user mode. */
#define SIUL2_ICU_IP_ENABLE_USER_MODE_SUPPORT   ([!IF "IcuGeneral/IcuEnableUserModeSupport"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

/* Verification for user mode support. */
#ifndef MCAL_ENABLE_USER_MODE_SUPPORT
    #if (defined (SIUL2_ICU_IP_ENABLE_USER_MODE_SUPPORT) && (STD_ON == SIUL2_ICU_IP_ENABLE_USER_MODE_SUPPORT))
        #error MCAL_ENABLE_USER_MODE_SUPPORT is not enabled. For running Icu in user mode the MCAL_ENABLE_USER_MODE_SUPPORT needs to be defined
    #endif
#endif

[!MACRO "ICU_GENERATE_IP_INDEX_IN_CHANNELS_STATUS"!][!//
[!NOCODE!][!//

[!IF "(num:i(ecu:get('Icu.Num_Siul2_Hw_Modules')) > 0) and (num:i(ecu:get('Icu.Num_Siul2_Hw_Channels')) > 0)"!][!//
[!CODE!][!WS "0"!]#define SIUL2_ICU_IP_INITIAL_INDEX_OF_CHANNELS \[!CR!][!ENDCODE!][!//
[!CODE!][!WS "4"!]{ \[!CR!][!ENDCODE!][!//
[!VAR "index" = "0"!][!//
[!FOR "LoopModule" = "0" TO "num:i(ecu:get('Icu.Num_Siul2_Hw_Modules') - 1)"!][!//
    [!VAR "valueOfOneModule" = "'{'"!][!//
    [!FOR "LoopChannel" = "0" TO "num:i(ecu:get('Icu.Num_Siul2_Hw_Channels') - 1)"!][!//
        [!VAR "indexInArray" = "'255'"!][!//
        [!SELECT "IcuConfigSet"!][!//
        [!IF "count(IcuSiul2/*) > '0'"!][!//
            [!LOOP "IcuSiul2/*"!][!//
                [!VAR "module" = "node:value(./IcuSiul2Instance)"!][!//
                [!LOOP "IcuSiul2Channels/*"!][!//
                    [!VAR "channel" = "node:value(./IcuSiul2Channel)"!][!//
                    [!IF "($LoopModule = $module) and ($LoopChannel = $channel)"!][!//
                        [!VAR "indexInArray" = "num:i($index)"!][!//
                        [!VAR "index" = "$index + 1"!][!//
                    [!ENDIF!][!//
                [!ENDLOOP!][!//
            [!ENDLOOP!][!//
        [!ENDIF!][!//
        [!ENDSELECT!][!//
        
        [!IF "num:i($LoopChannel) < (num:i(ecu:get('Icu.Num_Siul2_Hw_Channels') - 1))"!][!//
            [!VAR "valueOfOneModule" = "concat($valueOfOneModule, num:i($indexInArray), 'U, ')"!][!//
        [!ELSE!][!//
            [!VAR "valueOfOneModule" = "concat($valueOfOneModule, num:i($indexInArray), 'U')"!][!//
        [!ENDIF!][!//
    [!ENDFOR!][!//

    [!IF "num:i($LoopModule) < (num:i(ecu:get('Icu.Num_Siul2_Hw_Modules') - 1))"!][!//
        [!VAR "valueOfOneModule" = "concat($valueOfOneModule, '},')"!][!//
    [!ELSE!][!//
        [!VAR "valueOfOneModule" = "concat($valueOfOneModule, '}')"!][!//
    [!ENDIF!][!//
    
    [!CODE!][!WS "8"!][!"$valueOfOneModule"!] \[!CR!][!ENDCODE!][!//
[!ENDFOR!][!//
[!CODE!][!WS "4"!]} \[!CR!][!ENDCODE!][!//
[!ENDIF!][!//

[!ENDNOCODE!][!//
[!ENDMACRO!][!// End of Macro ICU_GENERATE_IP_INDEX_IN_CHANNELS_STATUS

[!CALL "ICU_GENERATE_IP_INDEX_IN_CHANNELS_STATUS"!][!//


[!NOCODE!][!//
    [!IF "contains($DerivativeName, 'S32E')"!][!//
        [!CODE!][!WS "0"!]#define SIUL2_ICU_AE_REG_PROT_AVAILABLE[!CR!][!ENDCODE!][!//
        [!CODE!][!WS "0"!]#define SIUL2_ICU_AE_MIN_INSTANCE (6U)[!CR!][!ENDCODE!][!//
    [!ENDIF!][!//
[!ENDNOCODE!][!//

#endif /* SIUL2_ICU_IP_USED */

#ifdef __cplusplus
}
#endif

/** @} */

#endif  /* SIUL2_ICU_IP_DEFINES_H */
[!ENDCODE!][!//
