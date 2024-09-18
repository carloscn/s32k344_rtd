[!AUTOSPACING!]
[!NOCODE!]
    [!IF "var:defined('postBuildVariant')"!]
        [!VAR "VS_number" = "concat('_',$postBuildVariant)"!]
    [!ELSE!]
        [!VAR "VS_number" = "''"!]
    [!ENDIF!]
[!ENDNOCODE!]
[!CODE!]
/*==================================================================================================
* Project : RTD AUTOSAR 4.7
* Platform : CORTEXM
* Peripheral : eMios
* Dependencies : none
*
* Autosar Version : 4.7.0
* Autosar Revision : ASR_REL_4_7_REV_0000
* Autosar Conf.Variant :
* SW Version : 3.0.0
* Build Version : S32K3_RTD_3_0_0_D2303_ASR_REL_4_7_REV_0000_20230331
*
* Copyright 2020 - 2023 NXP Semiconductors
*
* NXP Confidential. This software is owned or controlled by NXP and may only be
* used strictly in accordance with the applicable license terms. By expressly
* accepting such terms or by downloading, installing, activating and/or otherwise
* using the software, you are agreeing that you have read, and that you agree to
* comply with and are bound by, such license terms. If you do not agree to be
* bound by the applicable license terms, then you may not retain, install,
* activate or otherwise use the software.
==================================================================================================*/

#ifndef EMIOS_OCU_IP_CFGDEFINES_H
#define EMIOS_OCU_IP_CFGDEFINES_H
/**
*   @file           Emios_Ocu_Ip_CfgDefines.h
*
*   @addtogroup     ocu_ip Ocu IPL
*   @brief          Ocu IPL Precompile defines header file.
*   @details        Precompile defines.
*
*   @{
*/
#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/

#include "Std_Types.h"
[!NOCODE!][!//
[!VAR "eMiosOnS32ZE_Platform" = "'STD_OFF'"!]

[!IF "node:exists(as:modconf("Resource")[1]/ResourceGeneral/ResourceSubderivative)"!][!//
    [!VAR "DerivativeName" = "text:toupper(substring-before(as:modconf("Resource")[1]/ResourceGeneral/ResourceSubderivative,'_'))"!][!//
    [!IF "contains($DerivativeName, 'S32Z') or contains($DerivativeName, 'S32E')"!][!//
        [!VAR "eMiosOnS32ZE_Platform" = "'STD_ON'"!]
        [!IF "contains($DerivativeName, 'S32Z')"!][!//
            [!CODE!][!WS "0"!]#include "S32Z2_EMIOS.h"[!CR!][!ENDCODE!][!//
        [!ENDIF!][!//
        [!IF "contains($DerivativeName, 'S32E')"!][!//
            [!CODE!][!WS "0"!]#include "S32E2_EMIOS.h"[!CR!][!ENDCODE!][!//
        [!ENDIF!][!//
    [!ENDIF!][!//
    [!IF "contains($DerivativeName, 'S32K3')"!][!//
        [!IF "contains($DerivativeName, 'S32K39')"!][!//
            [!VAR "eMiosOnS32K396_Platform" = "'STD_ON'"!]
            [!CODE!][!WS "0"!]#include "S32K39_EMIOS.h"[!CR!][!ENDCODE!][!//
        [!ELSEIF "contains($DerivativeName, 'S32K310')"!][!//
            [!CODE!][!WS "0"!]#include "S32K311_EMIOS.h"[!CR!][!ENDCODE!][!//
        [!ELSEIF "contains($DerivativeName, 'S32K328') or contains($DerivativeName, 'S32K338') or contains($DerivativeName, 'S32K348')"!][!//
            [!CODE!][!WS "0"!]#include "S32K358_EMIOS.h"[!CR!][!ENDCODE!][!//
        [!ELSE!][!//
            [!CODE!][!WS "0"!]#include "[!"$DerivativeName"!]_EMIOS.h"[!CR!][!ENDCODE!][!//
        [!ENDIF!][!//
    [!ENDIF!][!//
    [!IF "contains($DerivativeName, 'S32M27')"!][!//
        [!CODE!][!WS "0"!]#include "S32M27x_EMIOS.h"[!CR!][!ENDCODE!]
    [!ENDIF!]
[!ENDIF!][!//
[!ENDNOCODE!][!//

/*==================================================================================================
*                               HEADER FILE VERSION INFORMATION
==================================================================================================*/
#define EMIOS_OCU_IP_CFGDEFINES_VENDOR_ID                       43
#define EMIOS_OCU_IP_CFGDEFINES_AR_RELEASE_MAJOR_VERSION        4
#define EMIOS_OCU_IP_CFGDEFINES_AR_RELEASE_MINOR_VERSION        7
#define EMIOS_OCU_IP_CFGDEFINES_AR_RELEASE_REVISION_VERSION     0
#define EMIOS_OCU_IP_CFGDEFINES_SW_MAJOR_VERSION                3
#define EMIOS_OCU_IP_CFGDEFINES_SW_MINOR_VERSION                0
#define EMIOS_OCU_IP_CFGDEFINES_SW_PATCH_VERSION                0
/*==================================================================================================
*                                      FILE VERSION CHECKS
==================================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if this header file and Std_Types.h file are of the same Autosar version */
    #if ((EMIOS_OCU_IP_CFGDEFINES_AR_RELEASE_MAJOR_VERSION != STD_AR_RELEASE_MAJOR_VERSION) || \
        (EMIOS_OCU_IP_CFGDEFINES_AR_RELEASE_MINOR_VERSION != STD_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of Emios_Ocu_Ip_CfgDefines.h and Std_Types.h are different"
    #endif

#endif

/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/
[!NOCODE!]
    [!VAR "max_number_ocu_cfg" = "num:i(count(./OcuGeneral/OcuEcucPartitionRef/*))"!]

    /* Variable storing number of eMios modules available on the current platform */
    [!VAR "numEmiosHwModules" = "ecu:get('Ocu.Num_Emios_Hw_Modules')"!]
    [!VAR "nameHwModule" = "'EMIOS'"!]

    /* Variable storing number of channels available on the current eMios instance */
    [!VAR "numEmiosChannelsPerInstance" = "ecu:get('Ocu.Num_Emios_Hw_Channels')"!]
    
    /* Loop on all channels inside the same configuration Set */

    [!VAR "MacEmiosUsed"="0"!]
    [!LOOP "OcuGeneral/OcuHwResourceConfig/*"!][!//
        [!IF "node:value(OcuChannelIsUsed) = 'true' and contains(OcuHwResourceId, $nameHwModule)"!][!//
            [!VAR "MacEmiosUsed"="1"!]
        [!ENDIF!][!//
    [!ENDLOOP!][!//

    [!VAR "MacNumEmiosChannels"="0"!]
    [!LOOP "OcuConfigSet/OcuChannel/*"!][!//
        [!IF "contains(node:value(node:ref(./OcuHWSpecificSettingsRef)/OcuHardwareElements), $nameHwModule)"!][!//
            [!VAR "MacNumEmiosChannels"="$MacNumEmiosChannels + 1"!]
        [!ENDIF!][!//
    [!ENDLOOP!][!//

[!ENDNOCODE!][!//

#ifndef OCU_DOWNCOUNTING_SUPPORED
/**
* @brief        Switch to indicate that the down counting is supported
*               This feature is not supported for current implementation
*/
#define OCU_DOWNCOUNTING_SUPPORED   (STD_OFF)
#endif

#ifndef OCU_EMIOS_IP_ON_S32ZE_PLATFORM
/** @brief  platform on which the eMios IP is available */
#define OCU_EMIOS_IP_ON_S32ZE_PLATFORM     [!"$eMiosOnS32ZE_Platform"!]
#endif


#ifndef OCU_EMIOS_USED
/** @brief These defines indicate that at least one channel from each module is used in all configurations. */
#define OCU_EMIOS_USED    ([!IF "$MacEmiosUsed=1"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])
#endif

[!NOCODE!][!//
    [!IF "num:i($MacNumEmiosChannels) != 0"!]
        [!CODE!]
#ifndef OCU_CONF_EMIOS_CHANNELS_PB
/** @brief Number of configured eMios channels */
#define OCU_CONF_EMIOS_CHANNELS_PB  ([!"num:i($MacNumEmiosChannels)"!]U)
#endif
        [!ENDCODE!]
    [!ENDIF!]
[!ENDNOCODE!][!//

#ifndef OCU_CONF_EMIOS_MODULES_PB
/** @brief Number of configured eMios modules */
#define OCU_CONF_EMIOS_MODULES_PB     ([!"num:i(count(OcuConfigSet/OcuHWSpecificSettings/*))"!]U)
#endif

/**
* @brief    Switch to indicate if the down counting is supported
*           This feature is not supported for current implementation
*/
#define OCU_EMIOS_DOWNCOUNTING_SUPPORED   (STD_OFF)

#ifndef OCU_NOTIFICATION_SUPPORTED
/** @brief   Switch to indicate if the notifications are supported */
#define OCU_NOTIFICATION_SUPPORTED      ([!IF "OcuConfigurationOfOptionalApis/OcuNotificationSupported"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])
#endif

#ifndef OCU_EMIOS_INSTANCE_COUNT
/** @brief  The number of eMios instances available on platform */
#define OCU_EMIOS_INSTANCE_COUNT      (uint8)[!"$numEmiosHwModules"!]U
#endif

#ifndef OCU_EMIOS_CHANNEL_COUNT
/** @brief  The number of channels available on each eMios instance */
#define OCU_EMIOS_CHANNEL_COUNT      (uint8)[!"$numEmiosChannelsPerInstance"!]U
#endif

#ifndef OCU_EMIOS_NUM_HW_CHANNELS
/** @brief  Maximum number of Emios channels available on this platform */
#define OCU_EMIOS_NUM_HW_CHANNELS         ((OCU_EMIOS_CHANNEL_COUNT) * (OCU_EMIOS_INSTANCE_COUNT))
#endif

#ifndef OCU_DEV_ERROR_DETECT
/** @brief   Switch for enabling the development error detection. */
#define OCU_DEV_ERROR_DETECT        ([!IF "OcuGeneral/OcuDevErrorDetect"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])
#endif

#ifndef OCU_SET_CLOCK_MODE_API
/** @brief  Switch for enabling the dual clock functionality (Ocu_SetClockMode() API) */
#define OCU_SET_CLOCK_MODE_API      ([!IF "OcuGeneral/OcuEnableDualClockMode"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])
#endif

#ifndef OCU_ENABLE_USER_MODE_SUPPORT
/**
* @brief Support for User mode.
*        If this parameter has been configured to 'true' the Ocu driver code can be executed from both supervisor and user mode.
*/  
#define OCU_ENABLE_USER_MODE_SUPPORT    ([!IF "OcuGeneral/OcuEnableUserModeSupport"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])
#endif

/* Verification for user mode support. */
#ifndef MCAL_ENABLE_USER_MODE_SUPPORT
    #if (defined(OCU_ENABLE_USER_MODE_SUPPORT) && (STD_ON == OCU_ENABLE_USER_MODE_SUPPORT))
        #error MCAL_ENABLE_USER_MODE_SUPPORT is not enabled. For running OCU in user mode the MCAL_ENABLE_USER_MODE_SUPPORT needs to be defined
    #endif
#endif

/**
*   @brief ISRs configured for Ocu channels
*   @details Macros for channels used in ISR
*   @{
*/
[!NOCODE!][!//
[!IF "OcuConfigurationOfOptionalApis/OcuNotificationSupported"!]
    [!VAR "AlreadyParsedModule"!][!ENDVAR!][!//
    [!LOOP "OcuGeneral/OcuHwResourceConfig/*"!][!//
        [!IF "(OcuChannelIsUsed = 'true')"!][!//
            [!IF "(OcuIsrEnable = 'true')"!][!//
                [!IF "contains($AlreadyParsedModule, concat(text:split(OcuHwResourceId,'_')[1], '_', text:split(OcuHwResourceId,'_')[2])) = false()"!][!//
                    [!CODE!][!//
                    [!VAR "ModuleUsed"="concat(text:split(OcuHwResourceId,'_')[1], '_', text:split(OcuHwResourceId,'_')[2])"!][!//
#define OCU_[!"$ModuleUsed"!]_ISR_USED
                    [!ENDCODE!][!//
                    [!VAR "AlreadyParsedModule"="concat($AlreadyParsedModule,text:split(OcuHwResourceId,'_')[1], '_', text:split(OcuHwResourceId,'_')[2],'|')"!][!//
                [!ENDIF!][!//
                [!CODE!][!//
#define OCU_[!"OcuHwResourceId"!]_ISR_USED
#define [!"OcuHwResourceId"!]_ISR_USED
                [!ENDCODE!][!//
            [!ENDIF!][!//
        [!ENDIF!][!//
    [!ENDLOOP!][!//
[!ENDIF!]
[!ENDNOCODE!][!//
/** @} */

#ifndef OCU_DEINIT_API
/** @brief      Switch to indicate that Ocu_DeInit() API is supported */
#define OCU_DEINIT_API      ([!IF "OcuConfigurationOfOptionalApis/OcuDeInitApi"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])
#endif

#ifndef OCU_SET_PIN_STATE_API
/** @brief  Switch to indicate if Ocu_SetPinState() API is supported */
#define OCU_SET_PIN_STATE_API   ([!IF "OcuConfigurationOfOptionalApis/OcuSetPinStateApi"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])
#endif

#ifndef OCU_SET_PIN_ACTION_API
/** @brief  Switch to indicate if Ocu_SetPinAction() API is supported */
#define OCU_SET_PIN_ACTION_API  ([!IF "OcuConfigurationOfOptionalApis/OcuSetPinActionApi"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])
#endif

#ifndef OCU_GET_COUNTER_API
/** @brief   Switch to indicate if Ocu_GetCounter() API is supported */
#define OCU_GET_COUNTER_API     ([!IF "OcuConfigurationOfOptionalApis/OcuGetCounterApi"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])
#endif

#ifndef OCU_SET_ABSOLUTE_THRESHOLD_API
/** @brief  Switch to indicate if Ocu_SetAbsoluteThreshold() API is supported */
#define OCU_SET_ABSOLUTE_THRESHOLD_API  ([!IF "OcuConfigurationOfOptionalApis/OcuSetAbsoluteThresholdApi"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])
#endif

#ifndef OCU_SET_RELATIVE_THRESHOLD_API
/** @brief      Switch to indicate if Ocu_SetRelativeThreshold() API is supported */
#define OCU_SET_RELATIVE_THRESHOLD_API  ([!IF "OcuConfigurationOfOptionalApis/OcuSetRelativeThresholdApi"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])
#endif

/*==================================================================================================
*                                             ENUMS
==================================================================================================*/

/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/


/**
* @brief        Emios UC internal counter (CNT register) value type
* @details      The value of the period is platform dependent and thus configurable.
*               Type for reading the counter and writing the threshold values (in number of ticks).
*
*/
typedef [!"ecu:get('Ocu.Emios_TimersType')"!] Emios_Ocu_Ip_ValueType;

/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/

#ifdef __cplusplus
}
#endif

/** @} */
#endif  /* EMIOS_OCU_IP_CFGDEFINES_H */

[!ENDCODE!]
