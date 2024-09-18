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
#ifndef WKPU_IP_DEFINES_H
#define WKPU_IP_DEFINES_H

/**
 *   @file    Wkpu_Ip_Defines.h
 *   @version 3.0.0
 *
 *   @brief   AUTOSAR Icu - contains the data exported by the Icu module
 *   @details Contains the information that will be exported by the module, as requested by Autosar.
 *
 *   @addtogroup wkpu_icu_ip WKPU IPL
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
    [!CODE!][!WS "0"!]/* Include platform header file. */[!CR!][!ENDCODE!][!//

    [!IF "contains($DerivativeName, 'S32K3')"!][!//
        [!IF "contains($DerivativeName, 'S32K328') or contains($DerivativeName, 'S32K338') or contains($DerivativeName, 'S32K348')"!][!//
            [!CODE!][!WS "0"!]#include "S32K358_WKPU.h"[!CR!][!ENDCODE!][!//
        [!ELSEIF "contains($DerivativeName, 'S32K39')"!][!//
            [!CODE!][!WS "0"!]#include "S32K39_WKPU.h"[!CR!][!ENDCODE!][!//
        [!ELSEIF "contains($DerivativeName, 'S32K310')"!][!//
            [!CODE!][!WS "0"!]#include "S32K311_WKPU.h"[!CR!][!ENDCODE!][!//
        [!ELSE!]
            [!CODE!][!WS "0"!]#include "[!"$DerivativeName"!]_WKPU.h"[!CR!][!ENDCODE!][!//
        [!ENDIF!][!//
    [!ENDIF!][!//

    [!IF "contains($DerivativeName, 'S32M27')"!][!//
        [!CODE!][!WS "0"!]#include "S32M27x_WKPU.h"[!CR!][!ENDCODE!][!//
    [!ENDIF!][!//
    [!IF "contains($DerivativeName, 'S32R41')"!][!//
        [!CODE!][!WS "0"!]#include "S32R41_WKPU.h"[!CR!][!ENDCODE!][!//
    [!ENDIF!][!//
    [!IF "contains($DerivativeName, 'S32R45')"!][!//
        [!CODE!][!WS "0"!]#include "S32R45_WKPU.h"[!CR!][!ENDCODE!][!//
    [!ENDIF!][!//
    [!IF "contains($DerivativeName, 'S32G2')"!][!//
        [!CODE!][!WS "0"!]#include "S32G274A_WKPU.h"[!CR!][!ENDCODE!][!//
    [!ENDIF!][!//
    [!IF "contains($DerivativeName, 'S32G3')"!][!//
        [!CODE!][!WS "0"!]#include "S32G399A_WKPU.h"[!CR!][!ENDCODE!][!//
    [!ENDIF!][!//
[!ENDIF!][!//

[!ENDNOCODE!][!//

/*==================================================================================================
 *                              SOURCE FILE VERSION INFORMATION
 *================================================================================================*/

#define WKPU_IP_DEFINES_VENDOR_ID                    43
#define WKPU_IP_DEFINES_AR_RELEASE_MAJOR_VERSION     4
#define WKPU_IP_DEFINES_AR_RELEASE_MINOR_VERSION     7
#define WKPU_IP_DEFINES_AR_RELEASE_REVISION_VERSION  0
#define WKPU_IP_DEFINES_SW_MAJOR_VERSION             3
#define WKPU_IP_DEFINES_SW_MINOR_VERSION             0
#define WKPU_IP_DEFINES_SW_PATCH_VERSION             0

/*==================================================================================================
 *                                      FILE VERSION CHECKS
 *================================================================================================*/
/* Check if header file and Std_Types.h file are of the same Autosar version */
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if ((WKPU_IP_DEFINES_AR_RELEASE_MAJOR_VERSION != STD_AR_RELEASE_MAJOR_VERSION) || \
         (WKPU_IP_DEFINES_AR_RELEASE_MINOR_VERSION != STD_AR_RELEASE_MINOR_VERSION))
    #error "AutoSar Version Numbers of Wkpu_Ip_Defines.h and Std_Types.h are different"
    #endif
#endif

/*==================================================================================================
                                       DEFINES AND MACROS
==================================================================================================*/

[!NOCODE!]
[!VAR "CheckWkpuSupport" = "0"!][!//
[!SELECT "IcuConfigSet"!][!//
    [!LOOP "./IcuChannel/*"!][!//
        [!IF "contains(node:path(node:ref(./IcuChannelRef)), 'IcuWkpu')"!][!//
            [!VAR "CheckWkpuSupport" = "$CheckWkpuSupport + 1"!][!//
        [!ENDIF!][!//
    [!ENDLOOP!][!//
[!ENDSELECT!]

[!IF "node:exists(as:modconf("Resource")[1]/ResourceGeneral/ResourceSubderivative)"!][!//
    [!IF "contains($DerivativeName, 'SAF85')"!][!//
        [!VAR "CheckWkpuSupport" = "0"!][!//
    [!ENDIF!][!//
[!ENDIF!][!//

[!CODE!]#define WKPU_IP_USED               [!IF "$CheckWkpuSupport != 0"!](STD_ON)[!ELSE!](STD_OFF)[!ENDIF!][!CR!][!CR!][!ENDCODE!]

[!CODE!][!WS "0"!]#if (STD_ON == WKPU_IP_USED)[!CR!][!ENDCODE!][!//

[!VAR "CoreCnt" = "num:i(0)"!]
[!SELECT "IcuConfigSet"!][!//
    [!IF "count(IcuWkpu/*) > '0'"!]
        [!LOOP "IcuWkpu/*"!]
            [!VAR "CoreCnt" = "num:i(count(IcuWkpuNMIConfiguration/*))"!]
        [!ENDLOOP!]
    [!ENDIF!]
[!ENDSELECT!]
[!CODE!]#define WKPU_IP_NMI_API               [!IF "(num:i($CoreCnt))!= (num:i(0))"!](STD_ON)[!ELSE!](STD_OFF)[!ENDIF!][!CR!][!ENDCODE!]
[!ENDNOCODE!]

#if (defined (WKPU_IP_NMI_API) && (STD_ON == WKPU_IP_NMI_API))
/*! @brief The distance between cores */
#define     WKPU_IP_CORE_OFFSET_SIZE            (8U)
#define     WKPU_IP_SUPPORT_NONE_REQUEST
#define     WKPU_IP_SUPPORT_NON_MASK_INT
[!NOCODE!]
[!CODE!]/** @brief The WKPU core array */[!CR!][!ENDCODE!]
[!CODE!]#define WKPU_IP_CORE_ARRAY \[!CR!][!ENDCODE!]
[!CODE!]{                          \[!CR!][!ENDCODE!]
[!VAR "NumCores" = "num:i(count(ecu:list('Icu.IcuConfigSet.IcuChannel.IcuHwChannel.IcuWkpuCoresSupport')) - 1)"!]
[!FOR "CoreIdx" = "1" TO "$NumCores"!]
    [!VAR "CoreID" = "num:i(ecu:list('Icu.IcuConfigSet.IcuChannel.IcuHwChannel.IcuWkpuCoresSupport')[num:i($CoreIdx)])"!]
    [!CODE!][!WS "4"!]WKPU_CORE[!"$CoreID"!]    /*!< Core [!"$CoreID"!] */[!ENDCODE!]
    [!IF "(num:i($CoreIdx))<(num:i($NumCores))"!][!CODE!],[!ENDCODE!][!ENDIF!][!CODE!]\[!CR!][!ENDCODE!]
[!ENDFOR!]
[!CODE!]}[!CR!][!ENDCODE!]
[!IF "(num:i($CoreCnt))!= (num:i(0))"!]
    [!CODE!]#define     WKPU_IP_NMI_CORE_CNT                ([!"$CoreCnt"!]U)[!CR!][!ENDCODE!]
[!ENDIF!]
/** @brief The number core support for WKPU module */
[!CODE!]#define     WKPU_IP_NMI_NUM_CORES               ([!"$NumCores"!]U)[!CR!][!ENDCODE!]
[!ENDNOCODE!]
#endif

#define     WKPU_IP_SUPPORT_INTERRUPT_REQUEST
#define     WKPU_IP_NUM_OF_CHANNELS             ([!"ecu:get('Icu.Num_Wkpu_Hw_Channels')"!]U)

/** @brief The number of Wkpu channels are used in configuration */
#define     WKPU_IP_NUM_OF_CHANNELS_USED        ((uint8)[!"num:i($CheckWkpuSupport)"!]U)

[!IF "num:i(ecu:get('Icu.Num_Wkpu_Hw_Channels')) > '32'"!]
    [!CODE!][!//
#define     WKPU_IP_NUM_OF_CHANNELS_IN_ONE_REG  (32U)
    [!ENDCODE!][!//
[!ELSE!]
    [!CODE!][!//
#define     WKPU_IP_NUM_OF_CHANNELS_IN_ONE_REG  ([!"ecu:get('Icu.Num_Wkpu_Hw_Channels')"!]U)
    [!ENDCODE!][!//
[!ENDIF!]

[!IF "node:exists(IcuAutosarExt/IcuWkpuStandbyWakeupSupport)"!][!//
/** @brief Switch for enabling Standby wakeup support  on or off */
#define     WKPU_IP_STANDBY_WAKEUP_SUPPORT      ([!IF "node:exists(IcuAutosarExt/IcuWkpuStandbyWakeupSupport)"!][!IF "IcuAutosarExt/IcuWkpuStandbyWakeupSupport"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!][!ELSE!]STD_OFF[!ENDIF!])
[!ENDIF!][!//

[!// Define used to see if S32R45 or S32R41 derivative is used.
[!IF "((ecu:get('Icu.Derivative')) = 'S32R45') or ((ecu:get('Icu.Derivative')) = 'S32R41')"!][!//
    [!CODE!][!WS "0"!]#define WKPU_DERIVATIVE_SUPPORT_ONLY_NMI        (STD_ON)[!CR!][!ENDCODE!][!//
[!ENDIF!][!//

[!IF "((ecu:get('Icu.Derivative')) = 'S32R41')"!][!//
[!CODE!]
/** @brief Support for User mode.If this parameter has been configured to 'STD_ON',
 *  the WKPU driver code can be executed from both supervisor and user mode. */
#define WKPU_IP_ENABLE_USER_MODE_SUPPORT   ([!IF "IcuGeneral/IcuEnableUserModeSupport"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

/* Verification for user mode support. */
#ifndef MCAL_ENABLE_USER_MODE_SUPPORT
 #if (defined (WKPU_IP_ENABLE_USER_MODE_SUPPORT) && (STD_ON == WKPU_IP_ENABLE_USER_MODE_SUPPORT))
    #error MCAL_ENABLE_USER_MODE_SUPPORT is not enabled. For running Icu in user mode the MCAL_ENABLE_USER_MODE_SUPPORT needs to be defined
 #endif
#endif

[!ENDCODE!][!//
[!ENDIF!][!//

[!MACRO "ICU_GENERATE_IP_INDEX_IN_CHANNELS_STATUS"!][!//
[!NOCODE!][!//

[!IF "(num:i(ecu:get('Icu.Num_Wkpu_Hw_Modules')) > 0) and (num:i(ecu:get('Icu.Num_Wkpu_Hw_Channels')) > 0)"!][!//
[!CODE!][!WS "0"!]#define WKPU_IP_INITIAL_INDEX_OF_CHANNELS \[!CR!][!ENDCODE!][!//
[!VAR "index" = "0"!][!//
[!VAR "valueOfOneModule" = "'{'"!][!//
[!FOR "LoopChannel" = "0" TO "num:i(ecu:get('Icu.Num_Wkpu_Hw_Channels') - 1)"!][!//
    [!VAR "indexInArray" = "'255'"!][!//
    [!SELECT "IcuConfigSet"!][!//
    [!IF "count(IcuWkpu/*) > '0'"!][!//
        [!LOOP "IcuWkpu/*"!][!//
            [!LOOP "IcuWkpuChannels/*"!][!//
                [!VAR "channel" = "node:value(./IcuWkpuChannel)"!][!//
                [!IF "($LoopChannel = $channel)"!][!//
                    [!VAR "indexInArray" = "num:i($index)"!][!//
                    [!VAR "index" = "$index + 1"!][!//
                [!ENDIF!][!//
            [!ENDLOOP!][!//
        [!ENDLOOP!][!//
    [!ENDIF!][!//
    [!ENDSELECT!][!//
    
    [!IF "num:i($LoopChannel) < (num:i(ecu:get('Icu.Num_Wkpu_Hw_Channels') - 1))"!][!//
        [!VAR "valueOfOneModule" = "concat($valueOfOneModule, num:i($indexInArray), 'U, ')"!][!//
    [!ELSE!][!//
        [!VAR "valueOfOneModule" = "concat($valueOfOneModule, num:i($indexInArray), 'U')"!][!//
    [!ENDIF!][!//
[!ENDFOR!][!//

[!VAR "valueOfOneModule" = "concat($valueOfOneModule, '}')"!][!//

[!CODE!][!WS "4"!][!"$valueOfOneModule"!][!CR!][!CR!][!ENDCODE!][!//
[!ENDIF!][!//

[!ENDNOCODE!][!//
[!ENDMACRO!][!// End of Macro ICU_GENERATE_IP_INDEX_IN_CHANNELS_STATUS

[!CALL "ICU_GENERATE_IP_INDEX_IN_CHANNELS_STATUS"!][!//

#endif /* WKPU_IP_USED */

#ifdef __cplusplus
}
#endif

/** @} */

#endif  /* WKPU_IP_DEFINES_H */
[!ENDCODE!][!//
