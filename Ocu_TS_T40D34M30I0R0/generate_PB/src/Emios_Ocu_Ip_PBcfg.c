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
*   Project              : RTD AUTOSAR 4.7
*   Platform             : CORTEXM
*   Peripheral           : eMios
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
/**
*   @file          Emios_Ocu_Ip[!"$VS_number"!]_PBcfg.c
*                  
*   @addtogroup    ocu_ip Ocu IPL
*   @brief         Ocu IPL Postbuild configuration source file.
*   @details       Postbuild configuration structure instances.
*
*   @{
*/

#ifdef __cplusplus
extern "C" {
#endif

/*==================================================================================================
*                                         INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/

[!IF "var:defined('postBuildVariant')"!][!//
#include "Emios_Ocu_Ip[!"$VS_number"!]_PBcfg.h"
[!ELSE!]
#include "Emios_Ocu_Ip_PBcfg.h"
[!ENDIF!]

/*==================================================================================================
*                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define EMIOS_OCU_IP[!"$VS_number"!]_PBCFG_VENDOR_ID_C                       43
#define EMIOS_OCU_IP[!"$VS_number"!]_PBCFG_AR_RELEASE_MAJOR_VERSION_C        4
#define EMIOS_OCU_IP[!"$VS_number"!]_PBCFG_AR_RELEASE_MINOR_VERSION_C        7
#define EMIOS_OCU_IP[!"$VS_number"!]_PBCFG_AR_RELEASE_REVISION_VERSION_C     0
#define EMIOS_OCU_IP[!"$VS_number"!]_PBCFG_SW_MAJOR_VERSION_C                3
#define EMIOS_OCU_IP[!"$VS_number"!]_PBCFG_SW_MINOR_VERSION_C                0
#define EMIOS_OCU_IP[!"$VS_number"!]_PBCFG_SW_PATCH_VERSION_C                0
/*==================================================================================================
*                                      FILE VERSION CHECKS
==================================================================================================*/
#if (EMIOS_OCU_IP[!"$VS_number"!]_PBCFG_VENDOR_ID_C != EMIOS_OCU_IP[!"$VS_number"!]_PBCFG_VENDOR_ID)
    #error "Emios_Ocu_Ip[!"$VS_number"!]_PBcfg.c and Emios_Ocu_Ip[!"$VS_number"!]_PBcfg.h have different vendor ids"
#endif

/* Check if  source file and Emios_Ocu_Ip[!"$VS_number"!]_PBcfg.h file are of the same Autosar version */
#if ((EMIOS_OCU_IP[!"$VS_number"!]_PBCFG_AR_RELEASE_MAJOR_VERSION_C != EMIOS_OCU_IP[!"$VS_number"!]_PBCFG_AR_RELEASE_MAJOR_VERSION) || \
     (EMIOS_OCU_IP[!"$VS_number"!]_PBCFG_AR_RELEASE_MINOR_VERSION_C != EMIOS_OCU_IP[!"$VS_number"!]_PBCFG_AR_RELEASE_MINOR_VERSION) || \
     (EMIOS_OCU_IP[!"$VS_number"!]_PBCFG_AR_RELEASE_REVISION_VERSION_C != EMIOS_OCU_IP[!"$VS_number"!]_PBCFG_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Emios_Ocu_Ip[!"$VS_number"!]_PBcfg.c and Emios_Ocu_Ip[!"$VS_number"!]_PBcfg.h are different"
#endif

/* Check if source file and Emios_Ocu_Ip[!"$VS_number"!]_PBcfg.h file are of the same Software version */
#if ((EMIOS_OCU_IP[!"$VS_number"!]_PBCFG_SW_MAJOR_VERSION_C != EMIOS_OCU_IP[!"$VS_number"!]_PBCFG_SW_MAJOR_VERSION) || \
     (EMIOS_OCU_IP[!"$VS_number"!]_PBCFG_SW_MINOR_VERSION_C != EMIOS_OCU_IP[!"$VS_number"!]_PBCFG_SW_MINOR_VERSION) || \
     (EMIOS_OCU_IP[!"$VS_number"!]_PBCFG_SW_PATCH_VERSION_C != EMIOS_OCU_IP[!"$VS_number"!]_PBCFG_SW_PATCH_VERSION))
    #error "Software Version Numbers of Emios_Ocu_Ip[!"$VS_number"!]_PBcfg.c and Emios_Ocu_Ip[!"$VS_number"!]_PBcfg.h are different"
#endif

/*===============================================================================================
*                                       LOCAL MACROS
===============================================================================================*/
[!NOCODE!]
    [!VAR "numConfiguredOcuChannels" = "num:i(count(OcuConfigSet/OcuChannel/*))"!]
    [!VAR "numConfiguredOcuModules" = "num:i(count(OcuConfigSet/OcuHWSpecificSettings/*))"!]
    [!VAR "numEmiosHwModules" = "ecu:get('Ocu.Num_Emios_Hw_Modules')"!]
    [!VAR "numEmiosHwChannels" = "ecu:get('Ocu.Num_Emios_Hw_Channels')"!]
    [!VAR "emiosTimersWidthType" = "ecu:get('Ocu.Emios_TimersType')"!]

[!ENDNOCODE!]

/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                        GLOBAL FUNCTION PROTOTYPES
==================================================================================================*/
#define OCU_START_SEC_CODE
#include "Ocu_MemMap.h"

#if (OCU_NOTIFICATION_SUPPORTED == STD_ON)
extern void Ocu_ProcessChannelNotification(uint16 Channel);
#endif

#define OCU_STOP_SEC_CODE
#include "Ocu_MemMap.h"

/*==================================================================================================
*                                       GLOBAL CONSTANTS
==================================================================================================*/

#define OCU_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Ocu_MemMap.h"

[!IF "$numConfiguredOcuChannels > 0"!]
    [!SELECT "OcuConfigSet"!]

    [!FOR "ModuleIdx" = "0" TO "$numEmiosHwModules - 1"!]
    [!VAR "CountChannels" = "0"!]
        [!LOOP "./OcuChannel/*"!]  
            [!IF "text:split(node:value(node:ref(./OcuHWSpecificSettingsRef)/OcuHardwareElements), "_")[2] = $ModuleIdx"!][!//
                [!VAR "CountChannels" = "$CountChannels + 1"!]
            [!ENDIF!]
        [!ENDLOOP!]
        [!IF "$CountChannels != 0"!]
            [!CODE!]
    /** @brief Number of configured eMios channels */
    #define NUMBER_CONF_EMIOS_[!"$ModuleIdx"!]_CHANNEL[!"$VS_number"!]    ([!"num:i($CountChannels)"!]U)[!CR!]
            [!ENDCODE!]
        [!ENDIF!]
    [!ENDFOR!]

    [!IF "node:exists(OcuCountdirection)"!]
        /** @brief counter direction */
        [!IF "(OcuCountdirection = 'OCU_EMIOS_DOWNCOUNTING')"!]
            [!VAR "EmiosCountDir" = "'((uint32)OCU_EMIOS_DOWNCOUNTING << OCU_EMIOS_COUNT_DIR_SHIFT)'"!]
        [!ELSE!]
            [!VAR "EmiosCountDir" = "'((uint32)OCU_EMIOS_UPCOUNTING << OCU_EMIOS_COUNT_DIR_SHIFT)'"!]
        [!ENDIF!]
    [!ELSE!]
        [!VAR "EmiosCountDir" = "'((uint32)OCU_EMIOS_UPCOUNTING << OCU_EMIOS_COUNT_DIR_SHIFT)'"!]
    [!ENDIF!]

    [!VAR "AlreadyParsedModules"!][!ENDVAR!][!//
    [!FOR "ModuleIdx" = "0" TO "$numEmiosHwModules - 1"!]
        [!VAR "comma" = "1"!]
        [!LOOP "./OcuChannel/*"!]
            [!IF "text:split(node:value(node:ref(./OcuHWSpecificSettingsRef)/OcuHardwareElements), "_")[2] = $ModuleIdx"!][!//
                [!IF "contains($AlreadyParsedModules, $ModuleIdx) = false()"!]
                    [!CODE!]
    /** @brief    Configurations for OCU channels using eMios [!"$ModuleIdx"!] */
    static const Emios_Ocu_Ip_ChannelConfigType Emios_Ocu_Ip_[!"$ModuleIdx"!]_ChannelConfig_PB[NUMBER_CONF_EMIOS_[!"$ModuleIdx"!]_CHANNEL[!"$VS_number"!]] =
    {
                    [!ENDCODE!]
                    [!VAR "AlreadyParsedModules"="concat($AlreadyParsedModules, $ModuleIdx)"!]
                [!ENDIF!]
                [!NOCODE!]
                    [!VAR "MacChannelId" = "num:i(./OcuChannelId)"!]
                    [!VAR "LocalHwChannel" = "node:value(node:ref(./OcuHWSpecificSettingsRef)/OcuHardwareElements)"!]
                    [!LOOP "../../../OcuGeneral/OcuHwResourceConfig/*"!][!//
                        [!IF "((node:value(OcuChannelIsUsed) = 'true') and contains(OcuHwResourceId, 'EMIOS')) and (not(OcuIsrEnable = 'true'))"!][!//
                            [!IF "node:value(./OcuHwResourceId) = $LocalHwChannel"!]
                                [!VAR "MacChannelId" = "num:i(255)"!]
                            [!ENDIF!]
                        [!ENDIF!][!//
                    [!ENDLOOP!][!//
                    
                    [!VAR "DefaultThreshold" = "num:i(OcuDefaultThreshold)"!]
                    [!VAR "MaxCounterValue" = "num:i(OcuMaxCounterValue)"!]
                    [!VAR "EmiosMasterBus" = "'EMIOS_OCU_BUS_INTERNAL_COUNTER'"!]
                    [!VAR "EmiosHardwareChannel" = "node:value(node:ref(./OcuHWSpecificSettingsRef)/OcuHardwareElements)"!]
                    [!VAR "Prescaler" = "'((uint32)EMIOS_PRESCALER_DIVIDE1 << OCU_EMIOS_CLOCK_DIV_SHIFT)'"!]
                    [!VAR "AltPrescaler" = "'((uint32)EMIOS_PRESCALER_DIVIDE1 << OCU_EMIOS_CLOCK_DIV_SHIFT)'"!]
                    [!VAR "DebugCfg" = "'(uint32)(0UL << OCU_EMIOS_DBG_INFO_SHIFT)'"!]

                    [!LOOP "../../OcuHWSpecificSettings/*"!]
                        [!IF "contains(OcuHardwareElements,'EMIOS')"!]
                            [!IF "contains(OcuHardwareElements,$EmiosHardwareChannel)"!]

                                /* get hw information: prescaler */
                                [!IF "(node:exists('OcuPrescale'))"!]
                                    [!VAR "Prescaler" = "concat('((uint32)EMIOS_PRESCALER_DIVIDE',substring-after(OcuPrescale,'_'),' << OCU_EMIOS_CLOCK_DIV_SHIFT)')"!]
                                [!ENDIF!]

                                /* get hw information: alternate prescaler */
                                [!IF "(node:exists('OcuPrescale_Alternate'))"!]
                                    [!VAR "AltPrescaler" = "concat('((uint32)EMIOS_PRESCALER_DIVIDE',substring-after(OcuPrescale_Alternate,'_'),' << OCU_EMIOS_CLOCK_DIV_SHIFT)')"!]
                                [!ENDIF!]

                                /* get hw information: debug information */
                                [!IF "(OcuEmiosFreeze = 'true')"!]
                                    [!VAR "DebugCfg" = "'(uint32)(1UL << OCU_EMIOS_DBG_INFO_SHIFT)'"!]
                                [!ENDIF!]

                                /* get hw information: master bus information */
                                [!IF "(node:exists('OcuEmiosBusSelect'))"!]
                                    [!IF "OcuEmiosBusSelect = 'EMIOS_OCU_BUS_INTERNAL_COUNTER'"!]
                                        [!VAR "EmiosMasterBus" = "OcuEmiosBusSelect"!]
                                        [!VAR "MasterBusChannel" = "OcuHardwareElements"!]
                                    [!ELSE!]
                                        [!VAR "EmiosMasterBus" = "OcuEmiosBusSelect"!]
                                        [!VAR "MasterBusChannel" = "concat(substring-before(OcuHardwareElements,'_CH'),'_CH_', ecu:get(concat('Ocu.',OcuEmiosBusSelect)))"!]
                                    [!ENDIF!]
                                [!ELSE!]
                                    [!VAR "MasterBusChannel" = "OcuHardwareElements"!]
                                [!ENDIF!]

                                [!BREAK!]
                            [!ENDIF!]
                        [!ENDIF!]
                    [!ENDLOOP!]
                    
                    [!VAR "PinUsed" = "OcuOutputPinUsed"!]
                    [!VAR "PinState" = "'((uint32)OCU_EMIOS_OUTPUT_DISABLED << OCU_EMIOS_OUTPIN_USED_SHIFT)'"!]
                    [!VAR "PinAction" = "'((uint32)OCU_EMIOS_SET_DISABLE << OCU_EMIOS_PIN_ACTION_SHIFT)'"!]

                    [!IF "($PinUsed = 'true')"!]
                        [!IF "(node:exists('OcuOutputPinDefaultState'))"!]
                            [!IF "(OcuOutputPinDefaultState = 'OCU_HIGH')"!]
                                [!VAR "PinState"= "'((uint32)OCU_EMIOS_OUTPUT_ENABLE << OCU_EMIOS_OUTPIN_USED_SHIFT) | ((uint32)(OCU_EMIOS_HIGH) << OCU_EMIOS_PIN_STATE_SHIFT)'"!]
                            [!ELSE!]
                                [!VAR "PinState"= "'((uint32)OCU_EMIOS_OUTPUT_ENABLE << OCU_EMIOS_OUTPIN_USED_SHIFT) | ((uint32)(OCU_EMIOS_LOW) << OCU_EMIOS_PIN_STATE_SHIFT)'"!]
                            [!ENDIF!]
                        [!ELSE!]
                            [!VAR "PinState"= "'((uint32)OCU_EMIOS_OUTPUT_ENABLE << OCU_EMIOS_OUTPIN_USED_SHIFT) | ((uint32)(OCU_EMIOS_LOW) << OCU_EMIOS_PIN_STATE_SHIFT)'"!]
                        [!ENDIF!]

                        [!IF "(node:exists('OcuOutputPinAction'))"!]
                            [!IF "(OcuOutputPinAction = 'OCU_SET_HIGH')"!]
                                [!VAR "PinAction"= "'((uint32)OCU_EMIOS_SET_HIGH << OCU_EMIOS_PIN_ACTION_SHIFT)'"!]
                            [!ELSEIF "(OcuOutputPinAction = 'OCU_TOGGLE')"!]
                                [!VAR "PinAction"= "'((uint32)OCU_EMIOS_SET_TOGGLE << OCU_EMIOS_PIN_ACTION_SHIFT)'"!]
                            [!ELSEIF "(OcuOutputPinAction = 'OCU_DISABLE')"!]
                                [!VAR "PinAction"= "'((uint32)OCU_EMIOS_SET_DISABLE << OCU_EMIOS_PIN_ACTION_SHIFT)'"!]
                            [!ELSE!]
                                [!VAR "PinAction"= "'((uint32)OCU_EMIOS_SET_LOW << OCU_EMIOS_PIN_ACTION_SHIFT)'"!]
                            [!ENDIF!]
                        [!ENDIF!]
                    [!ENDIF!]
                [!ENDNOCODE!]

                [!IF "contains(node:value(node:ref(./OcuHWSpecificSettingsRef)/OcuHardwareElements), 'EMIOS')"!]
                [!CODE!]
        /* [!"node:name(.)"!] -> [!"node:value(node:ref(./OcuHWSpecificSettingsRef)/OcuHardwareElements)"!] */
        {
            /** @brief  eMios hardware channel */
            (uint8)[!"text:split(node:value(node:ref(./OcuHWSpecificSettingsRef)/OcuHardwareElements), "_")[4]"!]U,
            /** @brief Ocu Default treshold: [!"$DefaultThreshold"!] */
            (Emios_Ocu_Ip_ValueType)[!IF "$emiosTimersWidthType = 'uint16'"!][!"num:inttohex($DefaultThreshold, 4)"!][!ELSE!][!"num:inttohex($DefaultThreshold, 8)"!][!ENDIF!]U,
            /** @brief Ocu max counter value: [!"$MaxCounterValue"!] */
            (Emios_Ocu_Ip_ValueType)[!IF "$emiosTimersWidthType = 'uint16'"!][!"num:inttohex($MaxCounterValue, 4)"!][!ELSE!][!"num:inttohex($MaxCounterValue, 8)"!][!ENDIF!]U,
                [!ENDCODE!]
                        [!IF "(../../../OcuGeneral/OcuEnableDualClockMode = 'true')"!]
                [!CODE!]
#if (OCU_SET_CLOCK_MODE_API == STD_ON)
            /** @brief eMios alternative Control Value */
            (uint32)[!"$AltPrescaler"!],
#endif
                [!ENDCODE!]
                        [!ENDIF!]
                [!CODE!]
            /** @brief eMios Control Value */
            (uint32)
            (
                [!"'(uint32)('"!][!"$EmiosMasterBus"!][!"' << EMIOS_OCU_BUS_SELECT_PARAM_SHIFT)'"!] | /* Counter select bits for the given channel */
                [!"$PinState"!] | /* Output Pin Enable and default state */
                [!"$PinAction"!] | /* Output Pin default action */
                [!"$DebugCfg"!] | /* Timer debug config */
                [!"$Prescaler"!] /* Timer clock prescaler configuration */
            ),
            /** @brief Ocu Hw Channel of counter BUS */
            (uint8)[!"text:split($MasterBusChannel, "_")[4]"!]U,
#if (OCU_NOTIFICATION_SUPPORTED == STD_ON)
            /** @brief eMios callback function name */[!CR!]
            &Ocu_ProcessChannelNotification,[!CR!]
            /** @brief eMios callback param */[!CR!]
            (uint16)[!"$MacChannelId"!]U[!CR!]
#endif
        },[!CR!]
                [!ENDCODE!]
                [!ENDIF!]
            [!ENDIF!]
        [!ENDLOOP!]
        [!IF "contains($AlreadyParsedModules, $ModuleIdx) = true()"!]
            [!CODE!]
    };

    /** @brief    eMios instance [!"$ModuleIdx"!] IP configuration */
    const Emios_Ocu_Ip_ConfigType Emios_Ocu_Ip_[!"$ModuleIdx"!]_ModuleCfgPB[!"$VS_number"!] = {
        /** @brief  Number of eMios channels in the OCU configuration for this instance */
        (uint8)NUMBER_CONF_EMIOS_[!"$ModuleIdx"!]_CHANNEL[!"$VS_number"!],
        /** @brief IP instance used for this OCU channel */
        (uint8)[!"$ModuleIdx"!]U,[!CR!]
        /** @brief  Pointer to the array of eMios channel configured for this instance */
        &Emios_Ocu_Ip_[!"$ModuleIdx"!]_ChannelConfig_PB[!CR!]
    };[!CR!]

        [!ENDCODE!]
        [!ENDIF!]
    [!ENDFOR!]
    [!ENDSELECT!]
[!ELSE!]
[!CODE!]
    /** @brief No eMios channel configured */
[!ENDCODE!]
[!ENDIF!]

#define OCU_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Ocu_MemMap.h"

/*==================================================================================================
*                                       GLOBAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                        GLOBAL FUNCTION PROTOTYPES
==================================================================================================*/

/*==================================================================================================
*                                    LOCAL FUNCTION PROTOTYPES
==================================================================================================*/

/*==================================================================================================
*                                        LOCAL FUNCTIONS
==================================================================================================*/

/*==================================================================================================
*                                        GLOBAL FUNCTIONS
==================================================================================================*/


#ifdef __cplusplus
}
#endif

/** @} */
[!ENDCODE!]
