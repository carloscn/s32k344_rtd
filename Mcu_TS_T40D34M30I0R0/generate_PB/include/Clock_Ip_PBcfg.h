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

#ifndef CLOCK_IP[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_H
#define CLOCK_IP[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_H

/**
*   @file       Clock_Ip[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg.h
*   @version    3.0.0
*
*   @brief   AUTOSAR Mcu - Post-Build(PB) configuration file code template.
*   @details Code template for Post-Build(PB) configuration file generation.
*
*   @addtogroup CLOCK_DRIVER_CONFIGURATION Clock Ip Driver
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
#include "Clock_Ip_Types.h"


/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define CLOCK_IP[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_VENDOR_ID                      43
#define CLOCK_IP[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_AR_RELEASE_MAJOR_VERSION       4
#define CLOCK_IP[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_AR_RELEASE_MINOR_VERSION       7
#define CLOCK_IP[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_AR_RELEASE_REVISION_VERSION    0
#define CLOCK_IP[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_SW_MAJOR_VERSION               3
#define CLOCK_IP[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_SW_MINOR_VERSION               0
#define CLOCK_IP[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_SW_PATCH_VERSION               0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if header file and Clock_Ip_Types.h file are of the same vendor */
#if (CLOCK_IP[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_VENDOR_ID != CLOCK_IP_TYPES_VENDOR_ID)
    #error "Clock_Ip[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg.h and Clock_Ip_Types.h have different vendor ids"
#endif

/* Check if header file and Clock_Ip_Types.h file are of the same Autosar version */
#if ((CLOCK_IP[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_AR_RELEASE_MAJOR_VERSION != CLOCK_IP_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (CLOCK_IP[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_AR_RELEASE_MINOR_VERSION != CLOCK_IP_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (CLOCK_IP[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_AR_RELEASE_REVISION_VERSION != CLOCK_IP_TYPES_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Clock_Ip[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg.h and Clock_Ip_Types.h are different"
#endif

/* Check if header file and Clock_Ip_Types.h file are of the same Software version */
#if ((CLOCK_IP[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_SW_MAJOR_VERSION != CLOCK_IP_TYPES_SW_MAJOR_VERSION) || \
     (CLOCK_IP[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_SW_MINOR_VERSION != CLOCK_IP_TYPES_SW_MINOR_VERSION) || \
     (CLOCK_IP[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_SW_PATCH_VERSION != CLOCK_IP_TYPES_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Clock_Ip[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg.h and Clock_Ip_Types.h are different"
#endif

/*==================================================================================================
*                                            CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/

/**
* @brief            Number of configured internal oscillators
*/
[!VAR "Mac_ClockConfigIndex" = "0"!][!//
[!NOCODE!][!//
[!LOOP "McuModuleConfiguration/McuClockSettingConfig/*"!][!//
    [!VAR "Mac_ircoscsCount" = "0"!][!//
    [!IF "node:exists("McuFIRC")"!][!//
        [!IF "node:value("McuFIRC/McuFircUnderMcuControl")"!][!//
            [!VAR "Mac_ircoscsCount" = "$Mac_ircoscsCount + 2"!][!// 2 = FIRC + FIRC_STANDBY
        [!ENDIF!][!//
    [!ENDIF!][!//
    [!IF "node:exists("McuSIRC")"!][!//
        [!IF "node:value("McuSIRC/McuSircUnderMcuControl")"!][!//
            [!VAR "Mac_ircoscsCount" = "$Mac_ircoscsCount + 1"!][!//
        [!ENDIF!][!//
    [!ENDIF!][!//
    [!IF "$Mac_ircoscsCount > num:i(0)"!][!//
[!CODE!][!//
#define CLOCK_IP_CONFIGURED_IRCOSCS_[!"num:i($Mac_ClockConfigIndex)"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_NO       ([!"num:i($Mac_ircoscsCount)"!]U)
[!ENDCODE!][!//
    [!ENDIF!][!//
    [!VAR "Mac_ClockConfigIndex" = "$Mac_ClockConfigIndex + 1"!][!//
[!ENDLOOP!][!// "McuModuleConfiguration/McuClockSettingConfig/*"
[!ENDNOCODE!][!//

/**
* @brief            Number of configured external oscillators
*/
[!VAR "Mac_ClockConfigIndex" = "0"!][!//
[!NOCODE!][!//
[!LOOP "McuModuleConfiguration/McuClockSettingConfig/*"!][!//
    [!VAR "Mac_xoscsCount" = "0"!][!//
    [!IF "node:exists("McuFXOSC")"!]
        [!IF "node:value("McuFXOSC/McuFxoscUnderMcuControl")"!]
            [!VAR "Mac_xoscsCount" = "$Mac_xoscsCount + 1"!]
        [!ENDIF!]
    [!ENDIF!]
    [!IF "node:exists("McuSXOSC")"!]
        [!IF "node:value("McuSXOSC/McuSxoscUnderMcuControl")"!]
            [!VAR "Mac_xoscsCount" = "$Mac_xoscsCount + 1"!]
        [!ENDIF!]
    [!ENDIF!]
    [!IF "$Mac_xoscsCount > num:i(0)"!][!//
[!CODE!][!//
#define CLOCK_IP_CONFIGURED_XOSCS_[!"num:i($Mac_ClockConfigIndex)"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_NO       ([!"num:i($Mac_xoscsCount)"!]U)
[!ENDCODE!][!//
    [!ENDIF!][!//
    [!VAR "Mac_ClockConfigIndex" = "$Mac_ClockConfigIndex + 1"!][!//
[!ENDLOOP!][!// "McuModuleConfiguration/McuClockSettingConfig/*"
[!ENDNOCODE!][!//

/**
* @brief            Number of configured pll devices
*/
[!VAR "Mac_ClockConfigIndex" = "0"!][!//
[!NOCODE!][!//
[!LOOP "McuModuleConfiguration/McuClockSettingConfig/*"!][!//
    [!VAR "Mac_NumOfPllUnderMcuCtr" = "0"!]
    [!FOR "PllCount" = "1" TO "count(ecu:list('MCU.PLL.List'))"!][!//
        [!VAR "Mac_IndexPllx" = "substring-after(ecu:list('MCU.PLL.List')[number($PllCount)],'PLL_')"!]
        [!VAR "Mac_PllPath" = "concat('McuPll_',$Mac_IndexPllx)"!]
        [!IF "node:exists($Mac_PllPath)"!]
            [!VAR "Mac_McuControlPllPath" = "concat($Mac_PllPath,'/McuPLLUnderMcuControl')"!]
            [!IF "node:value($Mac_McuControlPllPath)"!]
                [!VAR "Mac_NumOfPllUnderMcuCtr" = "$Mac_NumOfPllUnderMcuCtr  + 1"!]
            [!ENDIF!]
        [!ENDIF!]
    [!ENDFOR!]
    [!IF "$Mac_NumOfPllUnderMcuCtr > num:i(0)"!][!//
[!CODE!][!//
#define CLOCK_IP_CONFIGURED_PLLS_[!"num:i($Mac_ClockConfigIndex)"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_NO       ([!"num:i($Mac_NumOfPllUnderMcuCtr)"!]U)
[!ENDCODE!][!//
    [!ENDIF!][!//
    [!VAR "Mac_ClockConfigIndex" = "$Mac_ClockConfigIndex + 1"!][!//
[!ENDLOOP!][!// "McuModuleConfiguration/McuClockSettingConfig/*"
[!ENDNOCODE!][!//

/**
* @brief            Number of configured selectors
*/
[!VAR "Mac_ClockConfigIndex" = "0"!][!//
[!NOCODE!][!//
[!LOOP "McuModuleConfiguration/McuClockSettingConfig/*"!][!//
    [!VAR "Mac_selectorsCount" = "0"!]
[!// Selector of MC_CGM
        [!FOR "SelectorCGM" = "1" TO "count(ecu:list('MCU.CGM.CgmModules.List'))"!]
[!VAR "Mac_IndexCGMx" = "substring-after(ecu:list('MCU.CGM.CgmModules.List')[number($SelectorCGM)],'Cgm')"!]
        [!VAR "Mac_NumOfSelectors" = "count(ecu:list(concat('MCU.CGM',$Mac_IndexCGMx,'.ClockMuxes.List')))"!]
        [!FOR "SelectorIndex" = "0" TO "num:i($Mac_NumOfSelectors)"!]
        [!VAR "Mac_IndexCGM_MUXx" = "substring-after(ecu:list(concat('MCU.CGM',$Mac_IndexCGMx,'.ClockMuxes.List'))[number($SelectorIndex)],'CLKMUX_')"!]
            [!VAR "Mac_SelectorPath" = "concat('McuCgm',$Mac_IndexCGMx,'SettingConfig/McuCgm',$Mac_IndexCGMx,'ClockMux',$Mac_IndexCGM_MUXx)"!]
            [!IF "node:exists($Mac_SelectorPath)"!]
                [!VAR "Mac_ControlPath" = "concat($Mac_SelectorPath,'/McuClockMuxUnderMcuControl')"!]
                [!IF "node:value($Mac_ControlPath)"!]
                    [!VAR "Mac_selectorsCount" = "$Mac_selectorsCount + 1"!]
                [!ENDIF!]
            [!ENDIF!]
        [!ENDFOR!]
        [!ENDFOR!]
[!// Selector of RTC_RTCC
       [!VAR "Mac_SelectorPath" = "'McuRtcClockSelect'"!]
       [!IF "node:exists($Mac_SelectorPath)"!]
           [!VAR "Mac_ControlPath" = "concat($Mac_SelectorPath,'/McuClockMuxUnderMcuControl')"!]
           [!IF "node:value($Mac_ControlPath)"!]
           [!VAR "Mac_selectorsCount" = "$Mac_selectorsCount + 1"!]
           [!ENDIF!]
       [!ENDIF!]
    [!IF "$Mac_selectorsCount > num:i(0)"!][!//
[!CODE!][!//
#define CLOCK_IP_CONFIGURED_SELECTORS_[!"num:i($Mac_ClockConfigIndex)"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_NO       ([!"num:i($Mac_selectorsCount)"!]U)
[!ENDCODE!][!//
    [!ENDIF!][!//
    [!VAR "Mac_ClockConfigIndex" = "$Mac_ClockConfigIndex + 1"!][!//
[!ENDLOOP!][!// "McuModuleConfiguration/McuClockSettingConfig/*"
[!ENDNOCODE!][!//

/**
* @brief            Number of configured dividers
*/
[!VAR "Mac_ClockConfigIndex" = "0"!][!//
[!NOCODE!][!//
[!LOOP "McuModuleConfiguration/McuClockSettingConfig/*"!][!//
    [!VAR "Mac_NumOfDivUnderMcuCtr" = "0"!]
    [!FOR "SelectorCGM" = "1" TO "count(ecu:list('MCU.CGM.CgmModules.List'))"!]
        [!VAR "Mac_IndexCGMx" = "substring-after(ecu:list('MCU.CGM.CgmModules.List')[number($SelectorCGM)],'Cgm')"!]
        [!VAR "Mac_NumOfSelectors" = "count(ecu:list(concat('MCU.CGM',$Mac_IndexCGMx,'.ClockMuxes.List')))"!]
        [!FOR "SelectorIterator" = "0" TO "num:i($Mac_NumOfSelectors - 1)"!]
            [!VAR "Mac_SelectorIndex" = "substring-after(ecu:list(concat('MCU.CGM',$Mac_IndexCGMx,'.ClockMuxes.List'))[num:i($SelectorIterator + 1)], 'CLKMUX_')"!]
            [!VAR "Mac_SelectorPath" = "concat('McuCgm',$Mac_IndexCGMx,'SettingConfig/McuCgm',$Mac_IndexCGMx,'ClockMux',$Mac_SelectorIndex)"!]
            [!IF "node:exists($Mac_SelectorPath)"!]
                [!VAR "Mac_ControlPath" = "concat($Mac_SelectorPath,'/McuClockMuxUnderMcuControl')"!]
                [!IF "node:value($Mac_ControlPath)"!]
                    [!VAR "Mac_DividersList" = "concat('MCU.CGM',$Mac_IndexCGMx,'.ClockMux',$Mac_SelectorIndex,'.Dividers.List')"!]
                    [!VAR "Mac_NumOfDividers" = "count(ecu:list($Mac_DividersList))"!]
                    [!VAR "Mac_NumOfDivUnderMcuCtr" = "$Mac_NumOfDivUnderMcuCtr + $Mac_NumOfDividers"!]
                [!ENDIF!]
            [!ENDIF!]
        [!ENDFOR!]
    [!ENDFOR!]
    [!FOR "PllCount" = "1" TO "count(ecu:list('MCU.PLL.List'))"!][!//
        [!VAR "Mac_IndexPllx" = "substring-after(ecu:list('MCU.PLL.List')[number($PllCount)],'PLL_')"!]
        [!VAR "Mac_PllPath" = "concat('McuPll_',$Mac_IndexPllx)"!]
        [!IF "node:exists($Mac_PllPath)"!]
            [!VAR "Mac_McuControlPllPath" = "concat($Mac_PllPath,'/McuPLLUnderMcuControl')"!]
            [!IF "node:value($Mac_McuControlPllPath)"!]
                [!VAR "Mac_PllDvOdiv2Path" = "concat($Mac_PllPath,'/McuPll_Configuration/McuPllDvOdiv2')"!][!//
                [!IF "node:exists($Mac_PllDvOdiv2Path)"!][!//
                    [!VAR "Mac_NumOfPllDividers" = "1"!][!//
                [!ELSE!]
                    [!VAR "Mac_NumOfPllDividers" = "0"!]
                [!ENDIF!]
                [!VAR "Mac_DividersList" = "concat('MCU.PLL',$Mac_IndexPllx,'.Dividers.List')"!]
                [!VAR "Mac_NumOfDividers" = "count(ecu:list($Mac_DividersList))"!]
                [!VAR "Mac_NumOfDivUnderMcuCtr" = "$Mac_NumOfDivUnderMcuCtr + $Mac_NumOfPllDividers + $Mac_NumOfDividers"!]
            [!ENDIF!]
        [!ENDIF!]
    [!ENDFOR!]
    [!IF "$Mac_NumOfDivUnderMcuCtr > num:i(0)"!][!//
[!CODE!][!//
#define CLOCK_IP_CONFIGURED_DIVIDERS_[!"num:i($Mac_ClockConfigIndex)"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_NO       ([!"num:i($Mac_NumOfDivUnderMcuCtr)"!]U)
[!ENDCODE!][!//
    [!ENDIF!][!//
    [!VAR "Mac_ClockConfigIndex" = "$Mac_ClockConfigIndex + 1"!][!//
[!ENDLOOP!][!// "McuModuleConfiguration/McuClockSettingConfig/*"
[!ENDNOCODE!][!//

/**
* @brief            Number of configured divider triggers
*/
[!VAR "Mac_ClockConfigIndex" = "0"!][!//
[!NOCODE!][!//
[!LOOP "McuModuleConfiguration/McuClockSettingConfig/*"!][!//
    [!VAR "Mac_NumOfDivTriggerUnderMcuCtr" = "0"!]
    [!IF "text:tolower(ecu:get('MCU.CGM.DividerTriggerSupport')) = 'true'"!][!//
        [!FOR "SelectorCGM" = "1" TO "count(ecu:list('MCU.CGM.CgmModules.List'))"!]
            [!VAR "Mac_IndexCGMx" = "substring-after(ecu:list('MCU.CGM.CgmModules.List')[number($SelectorCGM)],'Cgm')"!]
            [!VAR "Mac_NumOfSelectors" = "count(ecu:list(concat('MCU.CGM',$Mac_IndexCGMx,'.ClockMuxes.List')))"!]
            [!FOR "SelectorIterator" = "0" TO "num:i($Mac_NumOfSelectors - 1)"!]
                [!VAR "Mac_SelectorIndex" = "substring-after(ecu:list(concat('MCU.CGM',$Mac_IndexCGMx,'.ClockMuxes.List'))[num:i($SelectorIterator + 1)], 'CLKMUX_')"!]
                [!VAR "Mac_SelectorPath" = "concat('McuCgm',$Mac_IndexCGMx,'SettingConfig/McuCgm',$Mac_IndexCGMx,'ClockMux',$Mac_SelectorIndex)"!]
                [!IF "node:exists($Mac_SelectorPath)"!]
                    [!VAR "Mac_ControlPath" = "concat($Mac_SelectorPath,'/McuClockMuxUnderMcuControl')"!]
                    [!IF "node:value($Mac_ControlPath)"!]
                        [!VAR "Mac_DividersList" = "concat('MCU.CGM',$Mac_IndexCGMx,'.ClockMux',$Mac_SelectorIndex,'.Dividers.List')"!][!//
                        [!VAR "Mac_NrOfMuxDivs" = "count(ecu:list($Mac_DividersList))"!][!//
                        [!FOR "MuxDiv" = "1" TO "num:i($Mac_NrOfMuxDivs)"!][!//
                            [!IF "node:exists(concat($Mac_SelectorPath,'/McuClkMux',$Mac_SelectorIndex,ecu:list($Mac_DividersList)[num:i($MuxDiv)],'_En'))"!]
                            [!VAR "Mac_DivPath" = "concat($Mac_SelectorPath,'/McuClkMux',$Mac_SelectorIndex,ecu:list($Mac_DividersList)[num:i($MuxDiv)],'_En')"!]
                                [!IF "node:value($Mac_DivPath)"!]
                                    [!VAR "Mac_DivTriggerPath" = "concat($Mac_SelectorPath,'/McuClkMux',$Mac_SelectorIndex,ecu:list($Mac_DividersList)[num:i($MuxDiv)],'Trigger')"!]
                                    [!IF "node:exists($Mac_DivTriggerPath)"!]
                                        [!IF "text:tolower(ecu:get('MCU.CGM.MultipleOnMuxSupport')) = 'true'"!][!//
                                            [!VAR "Mac_NumOfDivTriggerUnderMcuCtr" = "1"!]
                                        [!ELSE!]
                                            [!VAR "Mac_NumOfDivTriggerUnderMcuCtr" = "$Mac_NumOfDivTriggerUnderMcuCtr + 1"!]
                                        [!ENDIF!]
                                    [!ENDIF!]
                                [!ENDIF!]
                            [!ENDIF!]
                        [!ENDFOR!]
                    [!ENDIF!]
                [!ENDIF!]
            [!ENDFOR!]
        [!ENDFOR!]
    [!ENDIF!]
    [!IF "$Mac_NumOfDivTriggerUnderMcuCtr > num:i(0)"!][!//
[!CODE!][!//
#define CLOCK_IP_CONFIGURED_DIVIDER_TRIGGERS_[!"num:i($Mac_ClockConfigIndex)"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_NO       ([!"num:i($Mac_NumOfDivTriggerUnderMcuCtr)"!]U)
[!ENDCODE!][!//
    [!ENDIF!][!//
    [!VAR "Mac_ClockConfigIndex" = "$Mac_ClockConfigIndex + 1"!][!//
[!ENDLOOP!][!// "McuModuleConfiguration/McuClockSettingConfig/*"
[!ENDNOCODE!][!//

/**
* @brief            Number of configured fractional dividers
*/
[!VAR "Mac_ClockConfigIndex" = "0"!][!//
[!NOCODE!][!//
[!LOOP "McuModuleConfiguration/McuClockSettingConfig/*"!][!//
    [!VAR "NrOfClkDFSList" = "count(ecu:list('MCU.ClockDFS.List'))"!]
    [!IF "$NrOfClkDFSList > num:i(0)"!][!//
[!CODE!][!//
#define CLOCK_IP_CONFIGURED_FRACTIONAL_DIVIDERS_[!"num:i($Mac_ClockConfigIndex)"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_NO       ([!"num:i($NrOfClkDFSList)"!]U)
[!ENDCODE!][!//
    [!ENDIF!][!//
    [!VAR "Mac_ClockConfigIndex" = "$Mac_ClockConfigIndex + 1"!][!//
[!ENDLOOP!][!// "McuModuleConfiguration/McuClockSettingConfig/*"
[!ENDNOCODE!][!//

/**
* @brief            Number of configured external signals
*/
[!VAR "Mac_ClockConfigIndex" = "0"!][!//
[!NOCODE!][!//
[!LOOP "McuModuleConfiguration/McuClockSettingConfig/*"!][!//
    [!VAR "Mac_extClksCount" = "count(ecu:list('MCU.ExtClock.List'))"!][!//
    [!IF "$Mac_extClksCount > num:i(0)"!][!//
[!CODE!][!//
#define CLOCK_IP_CONFIGURED_EXT_CLKS_[!"num:i($Mac_ClockConfigIndex)"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_NO       ([!"num:i($Mac_extClksCount)"!]U)
[!ENDCODE!][!//
    [!ENDIF!][!//
    [!VAR "Mac_ClockConfigIndex" = "$Mac_ClockConfigIndex + 1"!][!//
[!ENDLOOP!][!// "McuModuleConfiguration/McuClockSettingConfig/*"
[!ENDNOCODE!][!//

/**
* @brief            Number of configured pcfs
*/
[!VAR "Mac_ClockConfigIndex" = "0"!][!//
[!NOCODE!][!//
[!LOOP "McuModuleConfiguration/McuClockSettingConfig/*"!][!//
    [!VAR "Mac_NumOfClkPcfs" = "0"!][!//
    [!FOR "CurrentCgm" = "1" TO "count(ecu:list('MCU.CGM.CgmModules.List'))"!][!//
    [!VAR "Mac_cgm" = "ecu:list('MCU.CGM.CgmModules.List')[num:i($CurrentCgm)]"!][!//
    [!VAR "Mac_capitalName" = "text:replace($Mac_cgm,substring($Mac_cgm,2),text:toupper(substring($Mac_cgm,2)))"!][!//
    [!VAR "Mac_pcfscount" = "count(ecu:list(concat('MCU.',$Mac_capitalName,'.CgmPcfs.List')))"!][!//
    [!FOR "CurrentPCFS" = "0" TO "num:i($Mac_pcfscount - 1)"!][!//
    [!IF "node:value(concat('Mcu',$Mac_cgm,'SettingConfig/Mcu',$Mac_cgm,'PcsConfig/Mcu',$Mac_cgm,'PcsConfig_',$CurrentPCFS,'/McuClockPcfsUnderMcuControl'))"!][!//
    [!VAR "Mac_NumOfClkPcfs" = "$Mac_NumOfClkPcfs + 1"!][!//
    [!ENDIF!][!//
    [!ENDFOR!][!//
    [!ENDFOR!][!//
    [!IF "$Mac_NumOfClkPcfs > num:i(0)"!][!//
[!CODE!][!//
#define CLOCK_IP_CONFIGURED_PCFS_[!"num:i($Mac_ClockConfigIndex)"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_NO       ([!"num:i($Mac_NumOfClkPcfs)"!]U)
[!ENDCODE!][!//
    [!ENDIF!][!//
    [!VAR "Mac_ClockConfigIndex" = "$Mac_ClockConfigIndex + 1"!][!//
[!ENDLOOP!][!// "McuModuleConfiguration/McuClockSettingConfig/*"
[!ENDNOCODE!][!//

/**
* @brief            Number of configured gates
*/
[!VAR "Mac_ClockConfigIndex" = "0"!][!//
[!NOCODE!][!//
[!LOOP "McuModuleConfiguration/McuClockSettingConfig/*"!][!//
    [!VAR "Mac_NumOfClkGates" = "0"!][!//
    [!IF "$Mac_NumOfClkGates > num:i(0)"!][!//
[!CODE!][!//
#define CLOCK_IP_CONFIGURED_GATES_[!"num:i($Mac_ClockConfigIndex)"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_NO       ([!"num:i($Mac_NumOfClkGates)"!]U)
[!ENDCODE!][!//
    [!ENDIF!][!//
    [!VAR "Mac_ClockConfigIndex" = "$Mac_ClockConfigIndex + 1"!][!//
[!ENDLOOP!][!// "McuModuleConfiguration/McuClockSettingConfig/*"
[!ENDNOCODE!][!//

/**
* @brief            Number of configured clock monitoring units
*/
[!VAR "Mac_ClockConfigIndex" = "0"!][!//
[!NOCODE!][!//
[!LOOP "McuModuleConfiguration/McuClockSettingConfig/*"!][!//
    [!VAR "Mac_NumOfClkMonitor" = "0"!]
    [!IF "node:exists("McuClkMonitor")"!]
        [!LOOP "./McuClkMonitor/*"!]
            [!IF "node:value(./McuClockMonitorUnderMcuControl)"!]
                [!VAR "Mac_NumOfClkMonitor" = "$Mac_NumOfClkMonitor + 1"!]
            [!ENDIF!]
        [!ENDLOOP!]
    [!ENDIF!]
    [!IF "$Mac_NumOfClkMonitor > num:i(0)"!][!//
[!CODE!][!//
#define CLOCK_IP_CONFIGURED_CMUS_[!"num:i($Mac_ClockConfigIndex)"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_NO       ([!"num:i($Mac_NumOfClkMonitor)"!]U)
[!ENDCODE!][!//
    [!ENDIF!][!//
    [!VAR "Mac_ClockConfigIndex" = "$Mac_ClockConfigIndex + 1"!][!//
[!ENDLOOP!][!// "McuModuleConfiguration/McuClockSettingConfig/*"
[!ENDNOCODE!][!//

/**
* @brief            Number of configured frequencies
*/
[!VAR "Mac_ClockConfigIndex" = "0"!][!//
[!NOCODE!][!//
[!LOOP "McuModuleConfiguration/McuClockSettingConfig/*"!][!//
    [!VAR "Mac_configureFrequenciesCount" = "num:i(count(ecu:list('MCU.ConfiguredFrequency.List')) + 1)"!][!//
    [!IF "$Mac_configureFrequenciesCount > num:i(0)"!][!//
[!CODE!][!//
#define CLOCK_IP_CONFIGURED_FREQUENCIES_[!"num:i($Mac_ClockConfigIndex)"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_NO       ([!"num:i($Mac_configureFrequenciesCount)"!]U)
[!ENDCODE!][!//
    [!ENDIF!][!//
    [!VAR "Mac_ClockConfigIndex" = "$Mac_ClockConfigIndex + 1"!][!//
[!ENDLOOP!][!// "McuModuleConfiguration/McuClockSettingConfig/*"
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
#define MCU_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Mcu_MemMap.h"


extern const Clock_Ip_ClockConfigType Mcu_aClockConfigPB[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][];

#define MCU_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Mcu_MemMap.h"

/*==================================================================================================
*                                       FUNCTION PROTOTYPES
==================================================================================================*/

#ifdef __cplusplus
}
#endif

/** @} */
#endif /* CLOCK_IP[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_H */

