[!/* *** multiple inclusion protection *** */!]
[!IF "not(var:defined('DPGA_REGOPERATIONS_M'))"!]
[!VAR "DPGA_REGOPERATIONS_M"="'true'"!]
[!NOCODE!][!//
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

/**
*   @file
*
*   @addtogroup dpga_driver_config Dpga Driver Configuration
*   @{
*/

[!ENDNOCODE!][!//
[!AUTOSPACING!]
// ----------------------------------------- IPL Configuration -----------------------------------------
// IPL - Dpga Config
// GenerationType='declaration_config' or 'declaration_callback' or 'definition_amplifier_config' or 'definition_config'
[!MACRO "Dpga_Ip_Config" , "MacroGenerationType"!][!//
[!NOCODE!][!//
[!VAR "VariantsNo" = "variant:size()"!]
[!IF "var:defined('postBuildVariant')"!]
    [!VAR "postBuildVariantNameUnderscore" = "concat('_',$postBuildVariant)"!]
[!ELSE!]
    [!VAR "postBuildVariantNameUnderscore" = "string(null)"!]
[!ENDIF!]

[!VAR "NumOfDpgaChannels"="num:i(count(DpgaChannel/*)-1)"!][!//
[!FOR "Unit" = "0" TO "num:i($NumOfDpgaChannels)"!][!//
    [!LOOP "DpgaChannel/*"!][!//
        [!IF "(DpgaChannelId = $Unit)"!][!//
            [!IF "$MacroGenerationType = 'declaration_config'"!]
[!CODE!]
/**
* @brief Dpga Ip Channel [!"DpgaChannelId"!] Config for configuration variant [!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!][!ENDIF!].
*/
extern const Dpga_Ip_ConfigType Dpga_Ip_Config[!"$postBuildVariantNameUnderscore"!];
[!ENDCODE!][!//
            [!ELSEIF "$MacroGenerationType = 'declaration_callback'"!]
[!CODE!][!//
[!IF "DpgaConfiguration/DpgaCallback != 'NULL_PTR'"!][!//
/**
* @brief Dpga Callback Function.
*/
extern void [!"DpgaConfiguration/DpgaCallback"!](Dpga_Ip_EventType Event);[!//
[!ENDIF!][!//
[!ENDCODE!][!//
            [!ELSEIF "$MacroGenerationType = 'definition_amplifier_config'"!]
                [!IF "num:i(substring-after(DpgaConfiguration/DpgaAmplifierGain, 'GAIN_')) = num:i(8)"!]
                    [!VAR "DpgaAmplGain" = "num:i(0)"!]
                [!ELSEIF "num:i(substring-after(DpgaConfiguration/DpgaAmplifierGain, 'GAIN_')) = num:i(16)"!]
                    [!VAR "DpgaAmplGain" = "num:i(1)"!]
                [!ELSEIF "num:i(substring-after(DpgaConfiguration/DpgaAmplifierGain, 'GAIN_')) = num:i(24)"!]
                    [!VAR "DpgaAmplGain" = "num:i(2)"!]
                [!ELSEIF "num:i(substring-after(DpgaConfiguration/DpgaAmplifierGain, 'GAIN_')) = num:i(32)"!]
                    [!VAR "DpgaAmplGain" = "num:i(3)"!]
                [!ELSEIF "num:i(substring-after(DpgaConfiguration/DpgaAmplifierGain, 'GAIN_')) = num:i(40)"!]
                    [!VAR "DpgaAmplGain" = "num:i(4)"!]
                [!ELSEIF "num:i(substring-after(DpgaConfiguration/DpgaAmplifierGain, 'GAIN_')) = num:i(50)"!]
                    [!VAR "DpgaAmplGain" = "num:i(5)"!]
                [!ELSEIF "num:i(substring-after(DpgaConfiguration/DpgaAmplifierGain, 'GAIN_')) = num:i(65)"!]
                    [!VAR "DpgaAmplGain" = "num:i(6)"!]
                [!ELSEIF "num:i(substring-after(DpgaConfiguration/DpgaAmplifierGain, 'GAIN_')) = num:i(80)"!]
                    [!VAR "DpgaAmplGain" = "num:i(7)"!]
                [!ENDIF!]
                [!IF "num:i(substring-after(DpgaConfiguration/DpgaOutCommonModeVoltage, 'VREF_DIV_')) = num:i(12)"!]
                    [!VAR "DpgaOutCommonMode" = "num:i(0)"!]
                [!ELSEIF "num:i(substring-after(DpgaConfiguration/DpgaOutCommonModeVoltage, 'VREF_DIV_')) = num:i(6)"!]
                    [!VAR "DpgaOutCommonMode" = "num:i(1)"!]
                [!ELSEIF "num:i(substring-after(DpgaConfiguration/DpgaOutCommonModeVoltage, 'VREF_DIV_')) = num:i(4)"!]
                    [!VAR "DpgaOutCommonMode" = "num:i(2)"!]
                [!ELSEIF "num:i(substring-after(DpgaConfiguration/DpgaOutCommonModeVoltage, 'VREF_DIV_')) = num:i(2)"!]
                    [!VAR "DpgaOutCommonMode" = "num:i(3)"!]
                [!ENDIF!]
                [!IF "num:i(substring-after(DpgaConfiguration/DpgaInCommonModeCoarse, 'SHIFT_')) = num:i(200)"!]
                    [!VAR "DpgaInCommonModeCoarse" = "num:i(1)"!]
                [!ELSEIF "num:i(substring-after(DpgaConfiguration/DpgaInCommonModeCoarse, 'SHIFT_')) = num:i(100)"!]
                    [!VAR "DpgaInCommonModeCoarse" = "num:i(2)"!]
                [!ELSEIF "num:i(substring-after(DpgaConfiguration/DpgaInCommonModeCoarse, 'SHIFT_')) = num:i(50)"!]
                    [!VAR "DpgaInCommonModeCoarse" = "num:i(3)"!]
                [!ELSEIF "num:i(substring-after(DpgaConfiguration/DpgaInCommonModeCoarse, 'SHIFT_')) = num:i(0)"!]
                    [!VAR "DpgaInCommonModeCoarse" = "num:i(0)"!]
                [!ENDIF!]
[!CODE!][!//
/**
* @brief Amplifier configuration structure for configuration variant [!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!][!ENDIF!].
*/
static Dpga_Ip_AmplifierConfigType Dpga_Ip_AmplifierConfig[!"$postBuildVariantNameUnderscore"!] =
{
    [!"$DpgaAmplGain"!]U,    /* .AmplifierGain - amplify by [!"num:i(substring-after(DpgaConfiguration/DpgaAmplifierGain, 'GAIN_'))"!] */
    [!"$DpgaOutCommonMode"!]U,    /* .OutCommonModeVoltage - Vref / [!"num:i(substring-after(DpgaConfiguration/DpgaOutCommonModeVoltage, 'VREF_DIV_'))"!] */
    [!"DpgaConfiguration/DpgaOffset"!]U,    /* .AmplifierOffset - see RM for detailed description of this value significance */
    [!"$DpgaInCommonModeCoarse"!]U,    /* .InCommonModeCoarse - shift with [!"num:i(substring-after(DpgaConfiguration/DpgaInCommonModeCoarse, 'SHIFT_'))"!] uA current out of both inputs */
    [!"DpgaConfiguration/DpgaInCommonModeFine"!]U     /* .InCommonModeFine - see RM for detailed description of this value significance */
};
[!ENDCODE!][!//
            [!ELSEIF "$MacroGenerationType = 'definition_config'"!]
[!CODE!]
/**
* @brief Dpga configuration structure for configuration variant [!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!][!ENDIF!].
*/
const Dpga_Ip_ConfigType Dpga_Ip_Config[!"$postBuildVariantNameUnderscore"!] =
{
    &Dpga_Ip_AmplifierConfig[!"$postBuildVariantNameUnderscore"!],    /* .AmplifierConfig */
    [!"DpgaConfiguration/DpgaBlankingTimeDuration"!]U,    /* .BlankingTimeDuration */
    /* .BTTriggerStateArray */
    {
[!ENDCODE!][!//
                [!VAR "NumOfTriggers"="num:i(count(DpgaConfiguration/DpgaBlankingTimeTriggerList/*))"!][!//
                [!VAR "LoopIdx"="0"!][!//
                [!LOOP "DpgaConfiguration/DpgaBlankingTimeTriggerList/*"!][!//
                    [!VAR "LoopIdx" = "$LoopIdx + 1"!][!//
                    [!IF "substring-before(DpgaBTTriggerState, '_EDGE') = 'NO'"!]
                        [!VAR "BTTriggerState" = "num:i(0)"!]
                        [!VAR "BTTriggerStateText" = "'this trigger cannot start the BT counter'"!]
                    [!ELSEIF "substring-before(DpgaBTTriggerState, '_EDGE') = 'FALLING'"!]
                        [!VAR "BTTriggerState" = "num:i(1)"!]
                        [!VAR "BTTriggerStateText" = "'the falling edge of this trigger starts the BT counter from 0'"!]
                    [!ELSEIF "substring-before(DpgaBTTriggerState, '_EDGE') = 'RISING'"!]
                        [!VAR "BTTriggerState" = "num:i(2)"!]
                        [!VAR "BTTriggerStateText" = "'the rising edge of this trigger starts the BT counter from 0'"!]
                    [!ELSEIF "substring-before(DpgaBTTriggerState, '_EDGE') = 'BOTH'"!]
                        [!VAR "BTTriggerState" = "num:i(3)"!]
                        [!VAR "BTTriggerStateText" = "'both edges of this trigger start the BT counter from 0'"!]
                    [!ENDIF!]
[!CODE!][!//
        [!"$BTTriggerState"!]U[!IF "$LoopIdx < num:i($NumOfTriggers)"!],[!ENDIF!]    /* Trigger [!"num:i($LoopIdx)"!] - [!"$BTTriggerStateText"!] */
[!ENDCODE!][!//
                [!ENDLOOP!][!//
[!CODE!][!//
    },
[!IF "../../GeneralConfiguration/DpgaEnableVoltageMonitoring = 'true'"!][!//
#if (STD_ON == DPGA_IP_ENABLE_VOLTAGE_MONITORING)
    (boolean)[!IF "DpgaConfiguration/DpgaEnableBipolarDetector = 'true'"!]TRUE[!ELSE!]FALSE[!ENDIF!],    /* .BipolarInputModeEnable */
    [!"DpgaConfiguration/DpgaLowDetectLimit"!]U,    /* .LowDetectLimit */
    [!"DpgaConfiguration/DpgaHighDetectLimit"!]U,    /* .HighDetectLimit */
    [!"DpgaConfiguration/DpgaLowDetectFilterDuration"!]U,    /* .LowDetectFilterDuration */
    [!"DpgaConfiguration/DpgaHighDetectFilterDuration"!]U,    /* .HighDetectFilterDuration */
#endif /* (STD_ON == DPGA_IP_ENABLE_VOLTAGE_MONITORING) */
[!ENDIF!][!//
    (Dpga_Ip_CallbackType)[!"DpgaConfiguration/DpgaCallback"!]    /* .DpgaCallback */
};
[!ENDCODE!][!//
            [!ENDIF!]
        [!ENDIF!]
    [!ENDLOOP!]
[!ENDFOR!]
[!ENDNOCODE!]
[!ENDMACRO!][!//

// IPL - Cfg Defines
[!MACRO "Dpga_Ip_ConfigDef"!][!//
#define DPGA_IP_DEV_ERROR_DETECT                [!IF "GeneralConfiguration/DpgaIpDevErrorDetect"!](STD_ON)[!ELSE!](STD_OFF)[!ENDIF!]
#define DPGA_IP_TIMEOUT_TYPE                    ([!"GeneralConfiguration/DpgaTimeoutMethod"!])
#define DPGA_IP_TIMEOUT_VALUE                   ([!"GeneralConfiguration/DpgaTimeoutValue"!]U)
#define DPGA_IP_CONFIG_TYPE                      Dpga_Ip_ConfigType
/**
* @brief  If Voltage Monitoring is enbaled, this define is (STD_ON). Otherwise, this define is (STD_OFF).
*/
#define DPGA_IP_ENABLE_VOLTAGE_MONITORING       [!IF "GeneralConfiguration/DpgaEnableVoltageMonitoring"!](STD_ON)[!ELSE!](STD_OFF)[!ENDIF!]

/**
* @brief  Maximum number of Blanking Time triggers.
*/
#define DPGA_IP_BT_NUM_OF_TRIGGERS              (6U)

[!ENDMACRO!]

// ----------------------------------------- HLD Configuration -----------------------------------------
// HLD - Cfg Defines
[!MACRO "CDD_Dpga_ConfigDef"!][!//
[!NOCODE!][!//
[!VAR "VariantsNo" = "variant:size()"!]
[!ENDNOCODE!][!//
#define DPGA_DEV_ERROR_DETECT           [!IF "GeneralConfiguration/DpgaDevErrorDetect"!](STD_ON)[!ELSE!](STD_OFF)[!ENDIF!]
#define DPGA_VERSION_INFO_API           [!IF "GeneralConfiguration/DpgaVersionInfoApi"!](STD_ON)[!ELSE!](STD_OFF)[!ENDIF!]
#define DPGA_ENABLE_USER_MODE_SUPPORT   (STD_OFF)
#define DPGA_MULTICORE_SUPPORT          (STD_OFF)
[!IF "($VariantsNo <= 1) and (IMPLEMENTATION_CONFIG_VARIANT != 'VariantPostBuild')"!][!//
#define DPGA_PRECOMPILE_SUPPORT         (STD_ON)
[!ELSE!][!//
#define DPGA_PRECOMPILE_SUPPORT         (STD_OFF)
[!ENDIF!][!//
#define DPGA_CONFIG_TYPE                DPGA_IP_CONFIG_TYPE
/**
* @brief  Dpga channel name to logic channel id mapping
*/
[!NOCODE!][!//
[!LOOP "DpgaChannel/*"!][!//
[!CODE!][!//
#define [!"@name"!]                   ([!"node:value(DpgaChannelId)"!]U)
[!ENDCODE!][!//
[!ENDLOOP!][!//
[!ENDNOCODE!][!//

#ifdef DPGA_ENABLE_USER_MODE_SUPPORT
    #if(STD_ON == DPGA_ENABLE_USER_MODE_SUPPORT)
        /**
        * @brief  This define indicate that the ipv Dpga is protected by register protection.
        */
        #define DPGA_REG_PROT_AVAILABLE
    #endif /* (STD_ON == DPGA_ENABLE_USER_MODE_SUPPORT) */
#endif /* ifdef DPGA_ENABLE_USER_MODE_SUPPORT */

/**
* @brief  perform checking marco MCAL_ENABLE_USER_MODE_SUPPORT available or not.
*/
#ifndef MCAL_ENABLE_USER_MODE_SUPPORT
    #if (STD_ON == DPGA_ENABLE_USER_MODE_SUPPORT)
        #error MCAL_ENABLE_USER_MODE_SUPPORT is not enabled. For running DPGA in user mode, the MCAL_ENABLE_USER_MODE_SUPPORT needs to be defined
    #endif /* (STD_ON == DPGA_ENABLE_USER_MODE_SUPPORT) */
#endif /* ifndef MCAL_ENABLE_USER_MODE_SUPPORT */
[!ENDMACRO!]

// HLD Config
// GenerationType='definition' or 'declaration' or 'definition_local' or 'definition_precompile'
[!MACRO "CDD_Dpga_Config" , "MacroGenerationType"!][!//
[!NOCODE!][!//
[!VAR "VariantsNo" = "variant:size()"!]
[!IF "var:defined('postBuildVariant')"!]
    [!VAR "postBuildVariantNameUnderscore" = "concat('_',$postBuildVariant)"!]
[!ELSE!]
    [!VAR "postBuildVariantNameUnderscore" = "string(null)"!]
[!ENDIF!]
[!IF "$MacroGenerationType = 'declaration'"!]
[!CODE!][!//
/* Dpga config structure to be used by Dpga Init function */
#define Dpga_Config[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariantNameUnderscore"!][!ENDIF!] Dpga_Ip_Config[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariantNameUnderscore"!][!ENDIF!]
[!ENDCODE!][!//
    [!IF "not((IMPLEMENTATION_CONFIG_VARIANT = 'VariantPreCompile') and (variant:size() <= 1))"!][!//
[!CODE!][!//
#define DPGA_CONFIG[!"$postBuildVariantNameUnderscore"!]_PB \
[!ENDCODE!][!//
        [!IF "$VariantsNo > 0"!][!//
            [!CODE!][!WS4!]extern const DPGA_CONFIG_TYPE Dpga_Config[!"$postBuildVariantNameUnderscore"!];[!CR!][!ENDCODE!]
        [!ELSE!][!//
            [!CODE!][!WS4!]extern const DPGA_CONFIG_TYPE Dpga_Config;[!CR!][!ENDCODE!]
        [!ENDIF!][!//
    [!ENDIF!]
[!ELSEIF "$MacroGenerationType = 'definition_precompile'"!]
    [!IF "($VariantsNo <= 1) and (IMPLEMENTATION_CONFIG_VARIANT != 'VariantPostBuild')"!][!//
[!CODE!][!//
const Dpga_ConfigType * const Dpga_ConfigVariantPredefined[1U] =
{
    &Dpga_Config[!"$postBuildVariantNameUnderscore"!]
};
[!ENDCODE!][!//
    [!ENDIF!][!//
[!ENDIF!][!//
[!ENDNOCODE!][!//
[!ENDMACRO!][!//



/** @} */
[!ENDIF!]
