/*==================================================================================================
*   Project              : RTD AUTOSAR 4.7
*   Platform             : CORTEXM
*   Peripheral           : Swt
*   Dependencies         : none
*
*   Autosar Version      : 4.7.0
*   Autosar Revision     : ASR_REL_4_7_REV_0000
*   Autosar Conf.Variant :
*   SW Version           : 3.0.0
*   Build Version        : S32K3_RTD_3_0_0_D2303_ASR_REL_4_7_REV_0000_20230331
*
*   Copyright 2020 - 2023 NXP Semiconductors
*   All Rights Reserved.
*
*   NXP Confidential. This software is owned or controlled by NXP and may only be
*   used strictly in accordance with the applicable license terms. By expressly
*   accepting such terms or by downloading, installing, activating and/or otherwise
*   using the software, you are agreeing that you have read, and that you agree to
*   comply with and are bound by, such license terms. If you do not agree to be
*   bound by the applicable license terms, then you may not retain, install,
*   activate or otherwise use the software.
==================================================================================================*/

#ifndef AEWDOG_IP_CFG_DEFINES_H
#define AEWDOG_IP_CFG_DEFINES_H

/**
*   @file
*
*   @addtogroup AeWdog_Ip
*   @{
*/

#ifdef __cplusplus
extern "C"{
#endif


/*==================================================================================================
*                                          INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/

#include "StandardTypes.h"

/*==================================================================================================
*                                 SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define AEWDOG_IP_CFG_DEFINES_VENDOR_ID                    43
#define AEWDOG_IP_CFG_DEFINES_MODULE_ID                    102
#define AEWDOG_IP_CFG_DEFINES_AR_RELEASE_MAJOR_VERSION     4
#define AEWDOG_IP_CFG_DEFINES_AR_RELEASE_MINOR_VERSION     7
#define AEWDOG_IP_CFG_DEFINES_AR_RELEASE_REVISION_VERSION  0
#define AEWDOG_IP_CFG_DEFINES_SW_MAJOR_VERSION             3
#define AEWDOG_IP_CFG_DEFINES_SW_MINOR_VERSION             0
#define AEWDOG_IP_CFG_DEFINES_SW_PATCH_VERSION             0

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if current file and StandardTypes header file are of the same Autosar version */
    #if ((AEWDOG_IP_CFG_DEFINES_AR_RELEASE_MAJOR_VERSION    != STD_AR_RELEASE_MAJOR_VERSION) || \
        (AEWDOG_IP_CFG_DEFINES_AR_RELEASE_MINOR_VERSION     != STD_AR_RELEASE_MINOR_VERSION))
    #error "AutoSar Version Numbers of AeWdog_Ip_Cfg_Defines.h and StandardTypes.h are different"
    #endif
#endif /* DISABLE_MCAL_INTERMODULE_ASR_CHECK */

/*==================================================================================================
*                                            CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/
[!NOCODE!]
[!INDENT "0"!]
[!VAR "AewdogIsSelected" = "0"!]
[!FOR "i" = "0" TO "count(ecu:list('Wdg.WdgInstance')) - 1"!]
    [!VAR "xPathModule" = "concat('./../../../Wdg_43_Instance',$i,'/ELEMENTS/Wdg')"!]
    [!IF "node:exists($xPathModule)"!]
        [!IF "ecu:list('Wdg.WdgInstance')[$i + 1] ='AEWDOG'"!]
            [!VAR "AewdogIsSelected" = "1"!]
            [!VAR "AeWdogTokenVal" = "num:inttohex(node:value(concat('./../../../Wdg_43_Instance',$i,'/ELEMENTS/Wdg/WdgSettingsConfig/WdgSettingsConfiguration/WdgWatchdogToken')))"!]
            [!VAR "AeWdogEnableDevErrorDetect" = "0"!][!//
            [!IF "node:value(concat('./../../../Wdg_43_Instance',$i,'/ELEMENTS/Wdg/WdgGeneral/WdgDevErrorDetect'))"!]
                [!VAR "AeWdogEnableDevErrorDetect" = "1"!]
            [!ENDIF!]
            [!CODE!]
            /**
            * @brief  Compile switch to enable development error detection
            */
            #define AEWDOG_IP_DEV_ERROR_DETECT ([!IF "$AeWdogEnableDevErrorDetect = 1"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])[!ENDCODE!][!CR!]
        [!ENDIF!]
    [!ENDIF!]
[!ENDFOR!]

[!IF "$AewdogIsSelected = 1"!][!CODE!]
/**
* @brief  This constant specifies if the instance of the AEWDOG is selected or not
*/
#define AEWDOG_IP_ENABLE           (STD_ON)

/**
* @brief  This define is used to store the AE IP config structure name.
*/
#define AEWDOG_AEC_IP_CONFIG_NAME                 Aec_Ip_aConfigPB[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][!ENDCODE!][!//
[!ELSE!][!CODE!]
/**
* @brief  Compile switch to enable development error detection
*/
#define AEWDOG_IP_DEV_ERROR_DETECT (STD_OFF)
/**
* @brief  This constant specifies if the instance of the AEWDOG is selected or not
*/
#define AEWDOG_IP_ENABLE           (STD_OFF)[!ENDCODE!][!//
[!ENDIF!][!//
[!ENDINDENT!]
[!ENDNOCODE!][!//

[!NOCODE!]
[!INDENT "0"!]
[!FOR "i" = "0" TO "count(ecu:list('Wdg.WdgInstance')) - 1"!]
    [!VAR "xPathModule" = "concat('./../../../Wdg_43_Instance',$i,'/ELEMENTS/Wdg')"!]
    [!IF "node:exists($xPathModule)"!]
        [!IF "ecu:list('Wdg.WdgInstance')[$i + 1] ='AEWDOG'"!]
            [!IF "node:value(concat('./../../../Wdg_43_Instance',$i,'/ELEMENTS/Wdg/WdgSettingsConfig/WdgSettingsConfiguration/WdgWatchdogMode')) = 'CHALLENGER_WATCHDOG'"!][!//
            [!CODE!][!//
            /**
            * @brief  This variable will indicate aeWdog mode
            */
            #define AEWDOG_IP_CHALLENGER_WATCHDOG_USED

            /**
            * @brief  This variable will indicate the value of Token register
            */
            #define AEWDOG_IP_TOKEN_INIT_VALUE           ((uint16)[!"$AeWdogTokenVal"!])
            [!ENDCODE!][!//
            [!ENDIF!][!//

            [!CODE!][!//
            /**
            * @brief  This variable will indicate if the ISR for AEWDOG instances is used
            */
            [!ENDCODE!][!//
            [!IF "node:value(concat('./../../../Wdg_43_Instance',$i,'/ELEMENTS/Wdg/WdgSettingsConfig/WdgInterruptContentEnable'))"!][!//
            [!CODE!]#define AEWDOG_IP_ISR_USED  (STD_ON)[!ENDCODE!]
            [!ELSE!]
            [!CODE!]#define AEWDOG_IP_ISR_USED  (STD_OFF)[!ENDCODE!]
            [!ENDIF!]
        [!ENDIF!]
    [!ENDIF!]
[!ENDFOR!]
[!ENDINDENT!]
[!ENDNOCODE!][!//

/**
* @brief  This variable will indicate RAM/ROM execution
*/
[!NOCODE!]
[!VAR "RunAreaROM" = "0"!]
[!VAR "RunAreaRAM" = "0"!]

[!FOR "i" = "0" TO "num:i(ecu:get('Wdg.Num.Of.Instances'))-1"!]
    [!IF "num:i($i) > 0"!]
        [!VAR "xPathModule" = "concat('./../../../Wdg','_43_Instance',$i)"!]
    [!ELSE!]
        [!VAR "xPathModule" = "concat('./../../../','Wdg')"!]
    [!ENDIF!]
    [!IF "node:exists(concat($xPathModule,'/ELEMENTS/Wdg'))"!]
        [!IF "node:value(concat($xPathModule,'/ELEMENTS/Wdg/WdgGeneral/WdgRunArea')) = 'ROM'"!]
            [!VAR "RunAreaROM" = "1"!]
            [!IF "num:i($RunAreaRAM) = 1"!]
                [!ERROR!]The "WdgRunArea" must be either ROM or RAM for both enabled Wdg Instances[!ENDERROR!]
                [!BREAK!]
            [!ENDIF!]
        [!ELSE!]
            [!VAR "RunAreaRAM" = "1"!]
            [!IF "num:i($RunAreaROM) = 1"!]
                [!ERROR!]The "WdgRunArea" must be either ROM or RAM for both enabled Wdg Instances[!ENDERROR!]
            [!ENDIF!]
        [!ENDIF!]
    [!ENDIF!]
[!ENDFOR!]

[!IF "num:i($RunAreaROM) = 1"!]
    [!CODE!]#define WDG_ROM (1U)[!ENDCODE!]
[!ELSE!]
    [!CODE!]#define WDG_RAM (0U)[!ENDCODE!]
[!ENDIF!]
[!ENDNOCODE!]

[!NOCODE!]
[!INDENT "0"!]
[!VAR "isDirectServiceAvailable" = "0"!][!//
[!FOR "i" = "0" TO "num:i(ecu:get('Wdg.Num.Of.Instances'))-1"!]
    [!IF "num:i($i) > 0"!]
        [!VAR "xPathModule" = "concat('ASPathDataOfSchema:/Wdg_43_Instance',$i,'_','TS_T40D34M30I0R0/Wdg')"!]
    [!ELSE!]
        [!VAR "xPathModule" = "concat('ASPathDataOfSchema:/','TS_T40D34M30I0R0/Wdg')"!]
    [!ENDIF!]
    [!IF "node:exists($xPathModule)"!]
        [!IF "node:value(concat($xPathModule,'/WdgGeneral/WdgEnableDirectService'))"!]
            [!VAR "isDirectServiceAvailable" = "1"!]
        [!ENDIF!]
    [!ENDIF!]
[!ENDFOR!]

[!IF "num:i($isDirectServiceAvailable)=0"!]
    [!FOR "i" = "0" TO "num:i(ecu:get('Wdg.Num.Of.Instances'))-1"!]
        [!IF "num:i($i) > 0"!]
            [!VAR "xPathModule" = "concat('ASPathDataOfSchema:/Wdg_43_Instance',$i,'_','TS_T40D34M30I0R0/Wdg')"!]
        [!ELSE!]
            [!VAR "xPathModule" = "concat('ASPathDataOfSchema:/','TS_T40D34M30I0R0/Wdg')"!]
        [!ENDIF!]
        [!IF "node:exists($xPathModule) and (ecu:list('Wdg.WdgInstance')[$i + 1] ='AEWDOG')"!]
            [!IF "node:value(concat($xPathModule,'/WdgGeneral/WdgEnableDirectService'))='false'"!]
                [!VAR "temp_AeWdogTimeout" = "node:value(concat($xPathModule,'/WdgSettingsConfig/WdgSettingsConfiguration/WdgWindowPeriod'))"!]
                [!IF "$temp_AeWdogTimeout = 'DISABLED'"!]
                    [!VAR "getAeWdogTimeoutValue" = "num:i(0)"!]
                [!ELSE!]
                    [!VAR "getAeWdogTimeoutValue" = "substring-after($temp_AeWdogTimeout,'TIME_')"!]
                    [!VAR "getAeWdogTimeoutValue" = "substring-before($getAeWdogTimeoutValue,'_512')"!]
                    [!IF "contains($getAeWdogTimeoutValue,'_')='true'"!]
                        [!VAR "temp_AeWdogTimeout" = "$getAeWdogTimeoutValue"!]
                        [!VAR "getAeWdogTimeoutValue" = "num:i(num:i((substring-before($temp_AeWdogTimeout,'_')) * num:i(substring-after($temp_AeWdogTimeout,'_')) * 512) div 1000)"!]
                    [!ELSE!]
                        [!VAR "getAeWdogTimeoutValue" = "num:i((num:i($getAeWdogTimeoutValue) * 512) div 1000)"!]
                    [!ENDIF!]
                [!ENDIF!]
            [!ELSE!]
                [!VAR "getAeWdogTimeoutValue" = "num:i(0)"!]
            [!ENDIF!]
        [!ELSE!]
            [!VAR "getAeWdogTimeoutValue" = "num:i(0)"!]
        [!ENDIF!]
    [!ENDFOR!]
    
    [!CODE!][!//
    /**
    * @brief  This macros indicate the Wdg timeout value for Wdg module.
    */

    #define AEWDOG_IPW_TIMEOUT_VALUE_ARRAY {(uint32) 0, (uint32)[!"$getAeWdogTimeoutValue"!], (uint32) 0}
    [!ENDCODE!]
[!ENDIF!]
[!ENDINDENT!]
[!ENDNOCODE!][!//

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

#endif /* AEWDOG_IP_CFG_DEFINES_H */
