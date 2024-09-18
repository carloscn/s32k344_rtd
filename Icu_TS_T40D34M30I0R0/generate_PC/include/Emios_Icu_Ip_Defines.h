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
#ifndef EMIOS_ICU_IP_DEFINES_H
#define EMIOS_ICU_IP_DEFINES_H

/**
 *   @file
 *   @implements Emios_Icu_Ip_Defines.h_Artifact
 *   @addtogroup emios_icu_ip EMIOS IPL
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
            [!CODE!][!WS "0"!]#include "S32K358_EMIOS.h"[!CR!][!ENDCODE!][!//
        [!ELSEIF "contains($DerivativeName, 'S32K39')"!][!//
            [!CODE!][!WS "0"!]#include "S32K39_EMIOS.h"[!CR!][!ENDCODE!][!//
        [!ELSEIF "contains($DerivativeName, 'S32K310')"!][!//
            [!CODE!][!WS "0"!]#include "S32K311_EMIOS.h"[!CR!][!ENDCODE!][!//
        [!ELSE!]
            [!CODE!][!WS "0"!]#include "[!"$DerivativeName"!]_EMIOS.h"[!CR!][!ENDCODE!][!//
        [!ENDIF!][!//
    [!ENDIF!][!//

    [!IF "contains($DerivativeName, 'S32M27')"!][!//
        [!CODE!][!WS "0"!]#include "S32M27x_EMIOS.h"[!CR!][!ENDCODE!][!//
    [!ENDIF!][!//
    [!IF "contains($DerivativeName, 'S32E')"!][!//
        [!CODE!][!WS "0"!]#include "S32E2_EMIOS.h"[!CR!][!ENDCODE!][!//
    [!ENDIF!][!//
    [!IF "contains($DerivativeName, 'S32Z')"!][!//
        [!CODE!][!WS "0"!]#include "S32Z2_EMIOS.h"[!CR!][!ENDCODE!][!//
    [!ENDIF!][!//
    
    [!VAR "eMiosMaxCounter" = "num:i(ecu:get('Icu.Emios_Hw_MaximumCounter'))"!]

[!ENDIF!][!//
[!ENDNOCODE!][!//

/*==================================================================================================
 *                              SOURCE FILE VERSION INFORMATION
 *================================================================================================*/
#define EMIOS_ICU_IP_DEFINES_VENDOR_ID                       43
#define EMIOS_ICU_IP_DEFINES_AR_RELEASE_MAJOR_VERSION        4
#define EMIOS_ICU_IP_DEFINES_AR_RELEASE_MINOR_VERSION        7
#define EMIOS_ICU_IP_DEFINES_AR_RELEASE_REVISION_VERSION     0
#define EMIOS_ICU_IP_DEFINES_SW_MAJOR_VERSION                3
#define EMIOS_ICU_IP_DEFINES_SW_MINOR_VERSION                0
#define EMIOS_ICU_IP_DEFINES_SW_PATCH_VERSION                0

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/
/* Check if header file and Std_Types.h file are of the same Autosar version */
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if ((EMIOS_ICU_IP_DEFINES_AR_RELEASE_MAJOR_VERSION != STD_AR_RELEASE_MAJOR_VERSION) || \
         (EMIOS_ICU_IP_DEFINES_AR_RELEASE_MINOR_VERSION != STD_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of Emios_Icu_Ip_Defines.h and Std_Types.h are different"
    #endif
#endif

/*==================================================================================================
*                                            CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/
/** @brief    Adds or removes the support eMios channels and measurement with DMA*/
[!VAR "TimestampDmaEnable" = "0"!][!/*
*/!][!VAR "MeasurementDmaEnable" = "0"!][!/*
*/!][!VAR "CheckEmiosSupport" = "0"!][!/*
*/!][!SELECT "IcuConfigSet"!][!/*
    */!][!LOOP "./IcuChannel/*"!][!/*
        */!][!IF "contains(node:path(node:ref(./IcuChannelRef)), 'IcueMios')"!][!/*
            */!][!VAR "CheckEmiosSupport" = "$CheckEmiosSupport + 1"!][!/*
            */!][!IF "IcuDMAChannelEnable = 'true'"!][!/*
                */!][!IF "IcuMeasurementMode = 'ICU_MODE_SIGNAL_MEASUREMENT'"!][!/*
                    */!][!VAR "MeasurementDmaEnable" = "$MeasurementDmaEnable + 1"!][!/*
                */!][!ELSEIF "IcuMeasurementMode='ICU_MODE_TIMESTAMP'"!][!/*
                    */!][!VAR "TimestampDmaEnable" = "$TimestampDmaEnable + 1"!][!/*
                */!][!ENDIF!][!/*
            */!][!ENDIF!][!/*
        */!][!ENDIF!][!/*
    */!][!ENDLOOP!][!/*
 */!][!ENDSELECT!]

#define EMIOS_ICU_IP_USED                        ([!IF "$CheckEmiosSupport != 0"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

#if (STD_ON == EMIOS_ICU_IP_USED)

#define EMIOS_ICU_IP_CHANNEL_24_USED             ([!IF "ecu:get('Icu.Num_Emios_Hw_Channels') > 24"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

/** @brief The number of EMIOS instances available on platform */
#define EMIOS_ICU_IP_INSTANCE_COUNT               ([!"ecu:get('Icu.Num_Emios_Hw_Modules')"!]U)

/** @brief The number of channels available on each EMIOS instance */
#define EMIOS_ICU_IP_NUM_OF_CHANNELS              ([!"ecu:get('Icu.Num_Emios_Hw_Channels')"!]U)

/** @brief The number of eMios channels are used in configuration */
#define EMIOS_ICU_IP_NUM_OF_CHANNELS_USED         ((uint8)[!"num:i($CheckEmiosSupport)"!]U)

#define EMIOS_ICU_IP_CHANNEL_NOT_USED             ((uint8)0xFF)

#define EMIOS_ICU_IP_MASTERBUS_CHANNEL_USED       ((uint8)0xFE)

/** @brief Switches the Development Error Detection and Notification on or off.  */
#define EMIOS_ICU_IP_DEV_ERROR_DETECT             ([!IF "IcuGeneral/IcuDevErrorDetect"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])
#define EMIOS_ICU_IP_VALIDATE_GLOBAL_CALL         (EMIOS_ICU_IP_DEV_ERROR_DETECT)

/** @brief Adds or removes all services related to the timestamp functionality. */
#define EMIOS_ICU_IP_TIMESTAMP_API                ([!IF "IcuOptionalApis/IcuTimestampApi"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

/** @brief Adds or removes all services related to the edge detect functionality. */
#define EMIOS_ICU_IP_EDGE_DETECT_API              ([!IF "IcuOptionalApis/IcuEdgeDetectApi"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

/** @brief Adds or removes all services related to the signal mesurement functionality. */
#define EMIOS_ICU_IP_SIGNAL_MEASUREMENT_API       ([!IF "IcuOptionalApis/IcuSignalMeasurementApi"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

/** @brief Adds or removes all services related to the input level. */
#define EMIOS_ICU_IP_GET_INPUT_LEVEL_API          ([!IF "node:exists(IcuAutosarExt/IcuGetInputLevelApi)"!][!IF "IcuAutosarExt/IcuGetInputLevelApi"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!][!ELSE!]STD_OFF[!ENDIF!])

/** @brief define SAIC mode if any channels not supporting IPWM or IPM mode is configured. */
#define EMIOS_ICU_IP_SIGNAL_MEASUREMENT_USES_SAIC_MODE            ([!IF "node:exists(IcuAutosarExt/IcuSupportSAICModeApi)"!][!IF "IcuAutosarExt/IcuSupportSAICModeApi"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!][!ELSE!]STD_OFF[!ENDIF!])

[!IF "node:exists(IcuAutosarExt/IcuSetMaxCounterValue)"!][!//
/** @brief Adds or removes the service set Max Counter for eMios. */
#define EMIOS_ICU_IP_SET_MAX_COUNTER          ([!IF "IcuAutosarExt/IcuSetMaxCounterValue"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])
[!ENDIF!][!//

[!IF "node:exists(IcuAutosarExt/IcuSetInitialCounterValue)"!][!//
/** @brief Adds or removes the service set Initial Counter for eMios. */
#define EMIOS_ICU_IP_SET_INITIAL_COUNTER           ([!IF "IcuAutosarExt/IcuSetInitialCounterValue"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])
[!ENDIF!][!//

/** @brief Adds or removes all services related to the deinitialization functionality. */
#define EMIOS_ICU_IP_DEINIT_API                   ([!IF "IcuOptionalApis/IcuDeInitApi"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

/** @brief Adds or removes all services related to mode set functionality. */
#define EMIOS_ICU_IP_SET_MODE_API                 ([!IF "IcuOptionalApis/IcuSetModeApi"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

/** @brief Adds or removes all services related to edge count functionality. */
#define EMIOS_ICU_IP_EDGE_COUNT_API               ([!IF "IcuOptionalApis/IcuEdgeCountApi"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

/** @brief Adds or removes all services related to input state functionality. */
#define EMIOS_ICU_IP_GET_INPUT_STATE_API          ([!IF "IcuOptionalApis/IcuGetInputStateApi"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

/** @brief Adds or removes all services related to dual clock edge functionality. */
#define EMIOS_ICU_IP_DUAL_CLOCK_MODE_API          ([!IF "IcuAutosarExt/IcuEnableDualClockMode"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

#define EMIOS_ICU_IP_CAPTURERGISTER_API           ([!IF "node:exists(IcuAutosarExt/IcuGetCaptureRegisterValueApi)"!][!IF "IcuAutosarExt/IcuGetCaptureRegisterValueApi"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!][!ELSE!]STD_OFF[!ENDIF!])

/** @brief Adds or Removes the code related to overflow notification */
#define EMIOS_ICU_IP_OVERFLOW_NOTIFICATION_API    ([!IF "IcuAutosarExt/IcuOverflowNotificationApi"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

/** @brief Adds or removes the support measurement with DMA. */
#define EMIOS_ICU_IP_SIGNALMEASUREMENT_USES_DMA   ([!IF "$MeasurementDmaEnable != 0"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])
#define EMIOS_ICU_IP_TIMESTAMP_USES_DMA           ([!IF "$TimestampDmaEnable != 0"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

/** @brief Adds or removes the support measurement with DMA in IPL */
#define EMIOS_ICU_IP_SIGNALMEASUREMENT_USES_DMA_IPL   (STD_OFF)
#define EMIOS_ICU_IP_DMA_MAJORLOOP_COUNT              (2U)
#define EMIOS_ICU_IP_TIMESTAMP_USES_DMA_IPL           (STD_OFF)

#define EMIOS_ICU_IP_GET_PULSE_WIDTH_API          ([!IF "num:i(0) != num:i(ecu:get('Icu.Num_Emios_Hw_Modules'))"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

/** @brief Support for User mode.
 *  If this parameter has been configured to STD_ON, the EMIOS driver code
 *  can be executed from both supervisor and user mode. */
#define EMIOS_ICU_IP_ENABLE_USER_MODE_SUPPORT     ([!IF "IcuGeneral/IcuEnableUserModeSupport"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

/* Verification for user mode support. */
#ifndef MCAL_ENABLE_USER_MODE_SUPPORT
    #if (defined (EMIOS_ICU_IP_ENABLE_USER_MODE_SUPPORT) && (STD_ON == EMIOS_ICU_IP_ENABLE_USER_MODE_SUPPORT))
        #error MCAL_ENABLE_USER_MODE_SUPPORT is not enabled. For running Icu in user mode the MCAL_ENABLE_USER_MODE_SUPPORT needs to be defined
    #endif
#endif

[!IF "node:exists(as:modconf('Mcl')[1])"!][!//
#define EMIOS_ICU_USES_MCL_DRIVER   (STD_ON)
[!ELSE!][!//
#define EMIOS_ICU_USES_MCL_DRIVER   (STD_OFF)
[!ENDIF!][!//

#if ((EMIOS_ICU_IP_EDGE_COUNT_API == STD_ON) || (EMIOS_ICU_IP_SIGNAL_MEASUREMENT_API == STD_ON) || (EMIOS_ICU_IP_TIMESTAMP_API == STD_ON))
#define EMIOS_ICU_IP_COUNTER_MASK              ((uint32)[!"$eMiosMaxCounter"!])
#endif

[!MACRO "ICU_GENERATE_IP_INDEX_IN_CHANNELS_STATUS"!][!//
[!NOCODE!][!//

[!IF "(num:i(ecu:get('Icu.Num_Emios_Hw_Modules')) > 0) and (num:i(ecu:get('Icu.Num_Emios_Hw_Channels')) > 0)"!][!//
[!CODE!][!WS "0"!]#define EMIOS_ICU_IP_INITIAL_INDEX_OF_CHANNELS \[!CR!][!ENDCODE!][!//
[!CODE!][!WS "4"!]{ \[!CR!][!ENDCODE!][!//
[!VAR "index" = "0"!][!//
[!FOR "LoopModule" = "0" TO "num:i(ecu:get('Icu.Num_Emios_Hw_Modules') - 1)"!][!//
    [!VAR "valueOfOneModule" = "'{'"!][!//
    [!FOR "LoopChannel" = "0" TO "num:i(ecu:get('Icu.Num_Emios_Hw_Channels') - 1)"!][!//
        [!VAR "indexInArray" = "'255'"!][!//
        [!SELECT "IcuConfigSet"!][!//
        [!IF "count(IcueMios/*) > '0'"!][!//
            [!LOOP "IcueMios/*"!][!//
                [!VAR "module" = "node:value(./IcueMiosModule)"!][!//
                [!LOOP "IcueMiosChannels/*"!][!//
                    [!VAR "channel" = "node:value(./IcueMiosChannel)"!][!//
                    [!IF "($LoopModule = $module) and ($LoopChannel = $channel)"!][!//
                        [!VAR "indexInArray" = "num:i($index)"!][!//
                        [!VAR "index" = "$index + 1"!][!//
                    [!ENDIF!][!//
                [!ENDLOOP!][!//
            [!ENDLOOP!][!//
        [!ENDIF!][!//
        [!ENDSELECT!][!//
        
        [!IF "num:i($LoopChannel) < (num:i(ecu:get('Icu.Num_Emios_Hw_Channels') - 1))"!][!//
            [!VAR "valueOfOneModule" = "concat($valueOfOneModule, num:i($indexInArray), 'U, ')"!][!//
        [!ELSE!][!//
            [!VAR "valueOfOneModule" = "concat($valueOfOneModule, num:i($indexInArray), 'U')"!][!//
        [!ENDIF!][!//
    [!ENDFOR!][!//

    [!IF "num:i($LoopModule) < (num:i(ecu:get('Icu.Num_Emios_Hw_Modules') - 1))"!][!//
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
/*==================================================================================================
*                                              ENUMS
==================================================================================================*/

/*==================================================================================================
*                                  STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/
/**
*   @brief Implementation specific. This type shall be chosen in order to have the most efficient
*       implementation on a specific microcontroller platform.
*       Range: 0  to width of the timer register.
*       Description: Width of the buffer for timestamp ticks and measured elapsed timeticks
*/
typedef uint32 eMios_Icu_ValueType;

/*==================================================================================================
*                                  GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                       FUNCTION PROTOTYPES
==================================================================================================*/
[!MACRO "CheckNeedMclConfiguration"!][!//
    [!SELECT "IcuConfigSet"!][!//
        [!IF "not(node:exists(as:modconf('Mcl')[1]))"!][!//
            [!VAR "EmiosCheckExists" = "0"!][!//
            [!LOOP "IcueMios/*"!][!//
                [!IF "node:exists(IcueMiosModule)"!][!//
                    [!VAR "EmiosCheckExists" = "$EmiosCheckExists + 1"!][!//
                [!ENDIF!][!//
            [!ENDLOOP!][!//
            [!IF "$EmiosCheckExists != 0"!][!//
                [!ERROR!]
                    Additional Mcl module is required when using eMios!
                [!ENDERROR!][!//
            [!ENDIF!][!//
        [!ENDIF!][!//
    [!ENDSELECT!][!//
[!ENDMACRO!][!//

[!IF "node:exists(as:modconf('Mcl')[1])"!][!//
[!MACRO "PwmExclusivAccess"!][!//
[!IF "node:exists(as:modconf('Mcl')[1]/MclConfig/EmiosCommon)"!][!//

    [!LOOP "IcuConfigSet/IcueMios/*"!] [!// Assuming that in the icu.xdm file have check whether EMIOS instance used
        [!VAR "emiosInstance" = "node:value(./IcueMiosModule)"!][!//
        [!LOOP "IcueMiosChannels/*"!] [!// Assuming that in the icu.xdm file have check whether EMIOS channel used
        
            [!IF "contains(node:value(./IcuEmiosBusSelect), 'EMIOS_ICU_BUS_A')"!][!//
                [!LOOP "as:modconf('Mcl')[1]/MclConfig/EmiosCommon/*"!][!//
                    [!IF "text:split(node:value(EmiosMclInstances), '_')[2] = $emiosInstance"!][!//
                        [!LOOP "EmiosMclMasterBus/*"!][!//
                            [!IF "(text:split(node:value(./EmiosMclMasterBusNumber), '_')[3] = '23') and node:value(./EmiosMclPwmExclusiveAccess) = 'true' "!][!//
                                [!ERROR!]
                                    EMIOS_ICU_BUS_A(or 23 channel in MCL) is used exclusiv by PWM driver! Please recheck MCL configuration for EMIOS!
                                [!ENDERROR!][!//
                            [!ENDIF!][!//
                        [!ENDLOOP!][!//
                    [!ENDIF!][!//
                [!ENDLOOP!][!//
            [!ENDIF!][!//

            [!IF "contains(node:value(./IcuEmiosBusSelect), 'EMIOS_ICU_BUS_F')"!][!//
                [!LOOP "as:modconf('Mcl')[1]/MclConfig/EmiosCommon/*"!][!//
                    [!IF "text:split(node:value(EmiosMclInstances), '_')[2] = $emiosInstance"!][!//
                        [!LOOP "EmiosMclMasterBus/*"!][!//
                            [!IF "(text:split(node:value(./EmiosMclMasterBusNumber), '_')[3] = '22') and node:value(./EmiosMclPwmExclusiveAccess) = 'true' "!][!//
                                [!ERROR!]
                                    EMIOS_ICU_BUS_F(or 22 channel in MCL) is used exclusiv by PWM driver! Please recheck MCL configuration for EMIOS!
                                [!ENDERROR!][!//
                            [!ENDIF!][!//
                        [!ENDLOOP!][!//
                    [!ENDIF!][!//
                [!ENDLOOP!][!//
            [!ENDIF!][!//

            [!IF "contains(node:value(./IcuEmiosBusSelect), 'EMIOS_ICU_BUS_DIVERSE')"!][!//
                [!IF "num:i(node:value(./IcueMiosChannel)) < 8"!]
                    [!LOOP "as:modconf('Mcl')[1]/MclConfig/EmiosCommon/*"!][!//
                        [!IF "text:split(node:value(EmiosMclInstances), '_')[2] = $emiosInstance"!][!//
                            [!LOOP "EmiosMclMasterBus/*"!][!//
                                [!IF "(text:split(node:value(./EmiosMclMasterBusNumber), '_')[3] = '0') and node:value(./EmiosMclPwmExclusiveAccess) = 'true' "!][!//
                                    [!ERROR!]
                                        EMIOS_ICU_BUS_B(or 0 channel in MCL) is used exclusiv by PWM driver! Please recheck MCL configuration for EMIOS!
                                    [!ENDERROR!][!//
                                [!ENDIF!][!//
                            [!ENDLOOP!][!//
                        [!ENDIF!][!//
                    [!ENDLOOP!][!//
                [!ENDIF!]

                [!IF "num:i(node:value(./IcueMiosChannel)) > 8 and num:i(node:value(./IcueMiosChannel)) < 16"!]
                    [!LOOP "as:modconf('Mcl')[1]/MclConfig/EmiosCommon/*"!][!//
                        [!IF "text:split(node:value(EmiosMclInstances), '_')[2] = $emiosInstance"!][!//
                            [!LOOP "EmiosMclMasterBus/*"!][!//
                                [!IF "(text:split(node:value(./EmiosMclMasterBusNumber), '_')[3] = '8') and node:value(./EmiosMclPwmExclusiveAccess) = 'true' "!][!//
                                    [!ERROR!]
                                        EMIOS_ICU_BUS_C(or 8 channel in MCL) is used exclusiv by PWM driver! Please recheck MCL configuration for EMIOS!
                                    [!ENDERROR!][!//
                                [!ENDIF!][!//
                            [!ENDLOOP!][!//
                        [!ENDIF!][!//
                    [!ENDLOOP!][!//
                [!ENDIF!]

                [!IF "num:i(node:value(./IcueMiosChannel)) > 16"!]
                    [!LOOP "as:modconf('Mcl')[1]/MclConfig/EmiosCommon/*"!][!//
                        [!IF "text:split(node:value(EmiosMclInstances), '_')[2] = $emiosInstance"!][!//
                            [!LOOP "EmiosMclMasterBus/*"!][!//
                                [!IF "(text:split(node:value(./EmiosMclMasterBusNumber), '_')[3] = '16') and node:value(./EmiosMclPwmExclusiveAccess) = 'true' "!][!//
                                    [!ERROR!]
                                        EMIOS_ICU_BUS_D(or 16 channel in MCL) is used exclusiv by PWM driver! Please recheck MCL configuration for EMIOS!
                                    [!ENDERROR!][!//
                                [!ENDIF!][!//
                            [!ENDLOOP!][!//
                        [!ENDIF!][!//
                    [!ENDLOOP!][!//
                [!ENDIF!]
            [!ENDIF!][!//

        [!ENDLOOP!][!//
    [!ENDLOOP!][!//
[!ENDIF!][!//
[!ENDMACRO!][!//
[!ENDIF!][!//

[!CALL "CheckNeedMclConfiguration"!][!//
[!IF "node:exists(as:modconf('Mcl')[1])"!][!//
[!CALL "PwmExclusivAccess"!][!//
[!ENDIF!][!//

#endif  /* EMIOS_ICU_IP_USED */

#ifdef __cplusplus
}
#endif

/** @} */

#endif  /* EMIOS_ICU_IP_DEFINES_H */

[!ENDCODE!][!//
