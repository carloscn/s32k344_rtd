[!NOCODE!]
/**
    @file    Clock_Ip_RegOperations.m
    @version 3.0.0

    @brief   AUTOSAR Mcu - Register operations.
    @details Register operations.

    Project RTD AUTOSAR 4.7
    Platform CORTEXM
    Peripheral 
    Dependencies none

    ARVersion 4.7.0
    ARRevision ASR_REL_4_7_REV_0000
    ARConfVariant
    SWVersion 3.0.0
    BuildVersion S32K3_RTD_3_0_0_D2303_ASR_REL_4_7_REV_0000_20230331

    Copyright 2020 - 2023 NXP Semiconductors
 */
[!NOCODE!]
[!VAR "HwpIrcoscCount" = "count(ecu:list('MCU.IRCOSC.List'))"!]
[!VAR "HwpXoscsCount" = "count(ecu:list('MCU.XOSC.List'))"!]
[!VAR "HwpllsCount" = "count(ecu:list('MCU.PLL.List'))"!]
[!VAR "HwSelectorCount" = "count(ecu:list('MCU.SELECTOR.Names.List'))"!]
[!VAR "HwDividerCount" = "count(ecu:list('MCU.DIVIDER.Names.List'))"!]
[!VAR "HwDividerTriggerCount" = "count(ecu:list('MCU.DIVIDER.TRIGGER.Names.List'))"!]
[!VAR "NrOfClkDFSList" = "count(ecu:list('MCU.ClockDFS.List'))"!]
[!VAR "NrOfClkDfs" = "count(ecu:list('MCU.DFS.OutputPorts.List'))"!]
[!VAR "NrOfClkExternal" = "count(ecu:list('MCU.ExtClock.List'))"!]
[!VAR "NrOfCgmx" = "count(ecu:list('MCU.CGM.CgmModules.List'))"!]
[!VAR "NumOfPCFSs" = "count(ecu:list('MCU.CGM.CgmPcfs.List'))"!]
[!VAR "NumOfClkSource" = "count(ecu:list('MCU.PCFS.Indices.List'))"!]
[!VAR "NrOfClkGates" = "count(ecu:list('MCU.GATE.Names.List'))"!]
[!VAR "NrOfClkMonitor" = "count(ecu:list('MCU.CMU_FC.List'))"!]
[!VAR "NrOfSpecificPeriph" = "count(ecu:list('MCU.SPECIFIC_PERIPHERAL_PRAMs.List'))"!]
[!VAR "Mac_RegValuesIterator" = "0"!]
[!ENDNOCODE!][!//

[!MACRO "Count_Ircoscs","Config"!][!//
[!NOCODE!]
    [!VAR "Mac_ircoscsCount" = "0"!]
    [!IF "node:exists("McuFIRC")"!]
        [!IF "node:value("McuFIRC/McuFircUnderMcuControl")"!]
            [!VAR "Mac_ircoscsCount" = "$Mac_ircoscsCount + 2"!]
        [!ENDIF!]
    [!ENDIF!]
    [!IF "node:exists("McuSIRC")"!]
        [!IF "node:value("McuSIRC/McuSircUnderMcuControl")"!]
            [!VAR "Mac_ircoscsCount" = "$Mac_ircoscsCount + 1"!]
        [!ENDIF!]
    [!ENDIF!]
[!CODE!][!//
[!"num:i($Mac_ircoscsCount)"!][!//
[!ENDCODE!]
[!ENDNOCODE!][!//
[!ENDMACRO!][!//

[!MACRO "Count_Specific"!][!//
[!NOCODE!]
    [!VAR "Mac_specificCount" = "0"!]
    [!IF "node:exists("McuEMIOS")"!]
        [!LOOP "./McuEMIOS/*"!]
            [!IF "node:value(./McuEMIOSUnderMcuControl)"!]
                [!VAR "Mac_specificCount" = "$Mac_specificCount + 1"!]
            [!ENDIF!]

        [!ENDLOOP!]
    [!ENDIF!]
[!CODE!][!//
[!"num:i($Mac_specificCount * 5)"!][!//
[!ENDCODE!]
[!ENDNOCODE!][!//
[!ENDMACRO!][!//

[!MACRO "Count_Xoscs","Config"!][!//
[!NOCODE!]
    [!VAR "Mac_xoscsCount" = "0"!]
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
[!CODE!][!//
[!"num:i($Mac_xoscsCount)"!][!//
[!ENDCODE!]
[!ENDNOCODE!][!//
[!ENDMACRO!][!//

[!MACRO "Count_Plls","Config"!][!//
[!NOCODE!]
    [!VAR "Mac_NumOfPllUnderMcuCtr" = "0"!]
    [!FOR "PllCount" = "1" TO "num:i($HwpllsCount)"!][!//
        [!VAR "Mac_IndexPllx" = "substring-after(ecu:list('MCU.PLL.List')[number($PllCount)],'PLL_')"!]
        [!VAR "Mac_PllPath" = "concat('McuPll_',$Mac_IndexPllx)"!]
        [!IF "node:exists($Mac_PllPath)"!]
            [!VAR "Mac_McuControlPllPath" = "concat($Mac_PllPath,'/McuPLLUnderMcuControl')"!]
            [!IF "node:value($Mac_McuControlPllPath)"!]
                [!VAR "Mac_NumOfPllUnderMcuCtr" = "$Mac_NumOfPllUnderMcuCtr  + 1"!]
            [!ENDIF!]
        [!ENDIF!]
    [!ENDFOR!]
[!CODE!][!//
[!"num:i($Mac_NumOfPllUnderMcuCtr)"!][!//
[!ENDCODE!]
[!ENDNOCODE!][!//
[!ENDMACRO!][!//

[!MACRO "Count_Selectors","Config"!][!//
[!NOCODE!]
    [!VAR "Mac_selectorsCount" = "0"!]
[!// Selector of MC_CGM
        [!FOR "SelectorCGM" = "1" TO "num:i($NrOfCgmx)"!]
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
[!CODE!][!//
[!"num:i($Mac_selectorsCount)"!][!//
[!ENDCODE!]
[!ENDNOCODE!][!//
[!ENDMACRO!][!//


[!MACRO "Count_Dividers","Config"!][!//
[!NOCODE!]
    [!VAR "Mac_NumOfDivUnderMcuCtr" = "0"!]
    [!FOR "SelectorCGM" = "1" TO "num:i($NrOfCgmx)"!]
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

    [!FOR "PllCount" = "1" TO "num:i($HwpllsCount)"!][!//
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
[!CODE!][!//
[!"num:i($Mac_NumOfDivUnderMcuCtr)"!][!//
[!ENDCODE!]
[!ENDNOCODE!][!//
[!ENDMACRO!][!//

[!MACRO "GetDivTriggerClk","CrtCgm","CrtMux"!][!//
[!NOCODE!]
    [!VAR "Mac_divtriggername" = "concat('Cgm',$CrtCgm,'ClockMux',$CrtMux)"!]
    [!FOR "Currentdiv" = "1" TO "num:i($HwDividerTriggerCount)"!]
        [!IF "ecu:list('MCU.CGM.DIVIDER.TRIGGER.List')[num:i($Currentdiv)] = ($Mac_divtriggername)"!]
        [!VAR "Mac_divtriggerclk" = "ecu:list('MCU.DIVIDER.TRIGGER.Names.List')[num:i($Currentdiv)]"!][!//
        [!ENDIF!]
    [!ENDFOR!]
[!CODE!][!//
[!"($Mac_divtriggerclk)"!][!//
[!ENDCODE!]
[!ENDNOCODE!][!//
[!ENDMACRO!][!//

[!MACRO "Count_Dividers_Trigger","Config"!][!//
[!NOCODE!]
    [!VAR "Mac_NumOfDivTriggerUnderMcuCtr" = "0"!]
    [!IF "text:tolower(ecu:get('MCU.CGM.DividerTriggerSupport')) = 'true'"!][!//
        [!FOR "SelectorCGM" = "1" TO "num:i($NrOfCgmx)"!]
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
[!CODE!][!//
[!"num:i($Mac_NumOfDivTriggerUnderMcuCtr)"!][!//
[!ENDCODE!]
[!ENDNOCODE!][!//
[!ENDMACRO!][!//

[!MACRO "Count_Clk_Pcfs","Config"!][!//
[!NOCODE!]
[!VAR "Mac_NumOfClkPcfs" = "0"!][!//
[!FOR "CurrentCgm" = "1" TO "num:i($NrOfCgmx)"!][!//
[!VAR "Mac_cgm" = "ecu:list('MCU.CGM.CgmModules.List')[num:i($CurrentCgm)]"!][!//
[!VAR "Mac_capitalName" = "text:replace($Mac_cgm,substring($Mac_cgm,2),text:toupper(substring($Mac_cgm,2)))"!][!//
[!VAR "Mac_pcfscount" = "count(ecu:list(concat('MCU.',$Mac_capitalName,'.CgmPcfs.List')))"!][!//
[!FOR "CurrentPCFS" = "0" TO "num:i($Mac_pcfscount - 1)"!][!//
[!IF "node:value(concat('Mcu',$Mac_cgm,'SettingConfig/Mcu',$Mac_cgm,'PcsConfig/Mcu',$Mac_cgm,'PcsConfig_',$CurrentPCFS,'/McuClockPcfsUnderMcuControl'))"!][!//
[!VAR "Mac_NumOfClkPcfs" = "$Mac_NumOfClkPcfs + 1"!][!//
[!ENDIF!][!//
[!ENDFOR!][!//
[!ENDFOR!][!//
[!CODE!][!//
[!"num:i($Mac_NumOfClkPcfs)"!][!//
[!ENDCODE!]
[!ENDNOCODE!][!//
[!ENDMACRO!][!//

[!MACRO "Count_Clk_Monitor","Config"!][!//
[!NOCODE!]
    [!VAR "Mac_NumOfClkMonitor" = "0"!]
    [!IF "node:exists("McuClkMonitor")"!]
        [!LOOP "./McuClkMonitor/*"!]
            [!IF "node:value(./McuClockMonitorUnderMcuControl)"!]
                [!VAR "Mac_NumOfClkMonitor" = "$Mac_NumOfClkMonitor + 1"!]
            [!ENDIF!]
        [!ENDLOOP!]
    [!ENDIF!]
[!CODE!][!//
[!"num:i($Mac_NumOfClkMonitor)"!][!//
[!ENDCODE!]
[!ENDNOCODE!][!//
[!ENDMACRO!][!//

[!MACRO "GetCmuEnable"!][!//
[!NOCODE!]
    [!VAR "Mac_CmuEn"!][!IF "node:value('./McuClkMonitorEn')"!]1[!ELSE!]0[!ENDIF!][!ENDVAR!]
[!CODE!][!//
[!"num:i($Mac_CmuEn)"!][!//
[!ENDCODE!]
[!ENDNOCODE!][!//
[!ENDMACRO!][!//

[!MACRO "GetCmuInterruptEnable"!][!//
[!NOCODE!]
[!VAR "Mac_CmuInterruptEn" = "0"!][!//
[!IF "node:value('./McuMonitorInterruptEn')"!][!//
[!VAR "Mac_CmuInterruptEn" = "1"!][!//
[!ENDIF!][!//
[!CODE!][!//
[!"num:i($Mac_CmuInterruptEn)"!][!//
[!ENDCODE!]
[!ENDNOCODE!][!//
[!ENDMACRO!][!//

[!MACRO "GetMonitoredClockFrequency","Name"!][!//
[!NOCODE!]
[!VAR "Mac_monitoredclockfrequency" = "0"!]
[!VAR "Mac_nammonitoredclock" = "substring-after(substring-after($Name,'CMU_FC_'),'_')"!]

[!IF "$Mac_nammonitoredclock = 'AIPS_PLAT_CLK'"!][!//
    [!VAR "Mac_monitoredclockfrequency" = "node:value(../../McuCgm0SettingConfig/McuCgm0ClockMux0/McuClockMux0Divider1_Frequency)"!][!//
[!ENDIF!][!//
[!IF "$Mac_nammonitoredclock = 'CORE_CLK'"!][!//
    [!VAR "Mac_monitoredclockfrequency" = "node:value(../../McuCgm0SettingConfig/McuCgm0ClockMux0/McuClockMux0Divider0_Frequency)"!][!//
[!ENDIF!][!//
[!IF "$Mac_nammonitoredclock = 'FXOSC_CLK'"!][!//
    [!VAR "Mac_monitoredclockfrequency" = "node:value(../../McuFXOSC/McuFXOSC_Frequency)"!][!//
[!ENDIF!][!//
[!IF "$Mac_nammonitoredclock = 'HSE_CLK'"!][!//
    [!VAR "Mac_monitoredclockfrequency" = "node:value(../../McuCgm0SettingConfig/McuCgm0ClockMux0/McuClockMux0Divider3_Frequency)"!][!//
[!ENDIF!][!//
[!IF "$Mac_nammonitoredclock = 'CM7_CORE_CLK'"!][!//
    [!VAR "Mac_monitoredclockfrequency" = "node:value(../../McuCgm0SettingConfig/McuCgm0ClockMux0/McuClockMux0Divider7_Frequency)"!][!//
[!ENDIF!][!//

[!CODE!][!//
[!"num:i($Mac_monitoredclockfrequency)"!][!//
[!ENDCODE!]
[!ENDNOCODE!][!//
[!ENDMACRO!][!//

[!MACRO "GetCmuMonitorName","CmuIndex"!][!//
[!NOCODE!]
    [!VAR "Mac_CmuName" = "ecu:list('MCU.CMU_FC.List')[num:i($CmuIndex)]"!][!//
    [!VAR "Mac_MonitorName" = "substring-after(substring-after($Mac_CmuName,'CMU_FC_'),'_')"!][!//
[!CODE!][!//
[!"($Mac_MonitorName)"!][!//
[!ENDCODE!]
[!ENDNOCODE!][!//
[!ENDMACRO!][!//

[!MACRO "GetCmuBaseAddress","CmuIndex"!][!//
[!NOCODE!]
    [!VAR "Mac_CmuName" = "ecu:list('MCU.CMU_FC.List')[num:i($CmuIndex)]"!][!//
    [!VAR "Mac_MonitorName" = "substring-after(substring-after($Mac_CmuName,'CMU_FC_'),'_')"!][!//
    [!VAR "Mac_CmuBaseAddress" = "concat('IP_',substring-before($Mac_CmuName,$Mac_MonitorName),'BASE')"!][!//
    [!VAR "Mac_CmuBaseAddress" = "text:replace($Mac_CmuBaseAddress,'FC_','')"!][!//
[!CODE!][!//
[!"($Mac_CmuBaseAddress)"!][!//
[!ENDCODE!]
[!ENDNOCODE!][!//
[!ENDMACRO!][!//

[!MACRO "Count_ExtClks","Config"!][!//
[!NOCODE!][!//
    [!VAR "Mac_extClksCount" = "count(ecu:list('MCU.ExtClock.List'))"!][!//
[!CODE!][!//
[!"num:i($Mac_extClksCount)"!][!//
[!ENDCODE!][!//
[!ENDNOCODE!][!//
[!ENDMACRO!][!//

[!MACRO "GetIrcoscEn","Name","ClockSourceName"!][!//
[!NOCODE!]
    [!VAR "Mac_capitalName" = "text:replace($Name,substring($Name,2),text:tolower(substring($Name,2)))"!]
    [!VAR "Mac_enPath" = "concat('Mcu',$Name,'/Mcu',$Mac_capitalName,'StandbyEnable')"!]
    [!IF "$ClockSourceName = 'FIRC_CLK'"!][!//
        [!VAR "Mac_ircoscEn" = "num:i(1)"!]
    [!ELSE!]
        [!VAR "Mac_ircoscEn"!][!IF "node:value($Mac_enPath)"!]1[!ELSE!]0[!ENDIF!][!ENDVAR!]
    [!ENDIF!]
[!CODE!][!//
[!"num:i($Mac_ircoscEn)"!][!//
[!ENDCODE!]
[!ENDNOCODE!][!//
[!ENDMACRO!][!//

[!MACRO "GetIrcoscRange","ClockSourceName"!][!//
[!NOCODE!]
    [!IF "$ClockSourceName = 'FIRC_CLK'"!][!//
        [!VAR "Mac_FircPostDividerPath" = "'McuFIRC/McuFircDivSel'"!]
        [!IF "node:exists($Mac_FircPostDividerPath)"!]
            [!VAR "Mac_FircPostDividerName" = "'FIRC_POSTDIV_CLK'"!]
            [!IF "node:value($Mac_FircPostDividerPath) = 'Div_by_1'"!][!//
                [!VAR "Mac_ircoscRange" = "'CLOCK_IP_SUPPORTS_48MHZ_FREQUENCY'"!][!//
            [!ELSEIF "node:value($Mac_FircPostDividerPath) = 'Div_by_2'"!][!//
                [!VAR "Mac_ircoscRange" = "'CLOCK_IP_SUPPORTS_24MHZ_FREQUENCY'"!][!//
            [!ELSEIF "node:value($Mac_FircPostDividerPath) = 'Div_by_16'"!][!//
                [!VAR "Mac_ircoscRange" = "'CLOCK_IP_SUPPORTS_3MHZ_FREQUENCY'"!][!//
            [!ELSE!][!//
                [!VAR "Mac_ircoscRange" = "'0U'"!][!//
            [!ENDIF!][!//
        [!ELSE!][!//
            [!VAR "Mac_ircoscRange" = "'0U'"!][!//
        [!ENDIF!]
    [!ELSE!]
        [!VAR "Mac_ircoscRange" = "'0U'"!]
    [!ENDIF!]
[!CODE!][!//
[!"$Mac_ircoscRange"!][!//
[!ENDCODE!]
[!ENDNOCODE!][!//
[!ENDMACRO!][!//


[!MACRO "GetXoscFrequency","Name"!][!//
[!NOCODE!]
    [!VAR "Mac_freqPath" = "concat('Mcu',$Name,'/Mcu',$Name,'_Frequency')"!]
    [!VAR "Mac_xoscFreq" = "num:i(node:value($Mac_freqPath))"!]
[!CODE!][!//
[!"num:i($Mac_xoscFreq)"!][!//
[!ENDCODE!]
[!ENDNOCODE!][!//
[!ENDMACRO!][!//


[!MACRO "GetXoscCounter","Name"!][!//
[!NOCODE!]
    [!VAR "Mac_capitalName" = "text:replace($Name,substring($Name,2),text:tolower(substring($Name,2)))"!]
    [!VAR "Mac_counterPath" = "concat('Mcu',$Name,'/Mcu',$Mac_capitalName,'Counter')"!]
    [!VAR "Mac_xoscCounter" = "num:i(node:value($Mac_counterPath))"!]
[!CODE!][!//
[!"num:i($Mac_xoscCounter)"!][!//
[!ENDCODE!]
[!ENDNOCODE!][!//
[!ENDMACRO!][!//


[!MACRO "GetXoscOverdrive","Name"!][!//
[!NOCODE!]
    [!VAR "Mac_capitalName" = "text:replace($Name,substring($Name,2),text:tolower(substring($Name,2)))"!]
    [!VAR "Mac_overdrivePath" = "concat('Mcu',$Name,'/Mcu',$Mac_capitalName,'OverdriveProtection')"!]
    [!IF "node:exists($Mac_overdrivePath)"!]
        [!VAR "Mac_xoscOverdrive" = "num:i(node:value($Mac_overdrivePath))"!]
    [!ELSE!]
        [!VAR "Mac_xoscOverdrive" = "num:i(0)"!]
    [!ENDIF!]
[!CODE!][!//
[!"num:i($Mac_xoscOverdrive)"!][!//
[!ENDCODE!]
[!ENDNOCODE!][!//
[!ENDMACRO!][!//


[!MACRO "GetXoscBypass","Name"!][!//
[!NOCODE!]
    [!VAR "Mac_capitalName" = "text:replace($Name,substring($Name,2),text:tolower(substring($Name,2)))"!]
    [!VAR "Mac_bypassPath" = "concat('Mcu',$Name,'/Mcu',$Mac_capitalName,'Bypass')"!]
    [!IF "node:exists($bypassPath)"!]
        [!VAR "Mac_xoscBypass"!][!IF "node:value($Mac_bypassPath)"!]1[!ELSE!]0[!ENDIF!][!ENDVAR!]
    [!ELSE!]
        [!VAR "Mac_xoscBypass" = "num:i(0)"!]
    [!ENDIF!]
[!CODE!][!//
[!"num:i($Mac_xoscBypass)"!][!//
[!ENDCODE!]
[!ENDNOCODE!][!//
[!ENDMACRO!][!//


[!MACRO "GetXoscComp","Name"!][!//
[!NOCODE!]
    [!VAR "Mac_capitalName" = "text:replace($Name,substring($Name,2),text:tolower(substring($Name,2)))"!]
    [!VAR "Mac_compPath" = "concat('Mcu',$Name,'/Mcu',$Mac_capitalName,'MainComparator')"!]
    [!IF "node:exists($Mac_compPath)"!]
        [!VAR "Mac_xoscComp"!][!IF "node:value($Mac_compPath)"!]1[!ELSE!]0[!ENDIF!][!ENDVAR!]
    [!ELSE!]
        [!VAR "Mac_xoscComp" = "num:i(0)"!]
    [!ENDIF!]
[!CODE!][!//
[!"num:i($Mac_xoscComp)"!][!//
[!ENDCODE!]
[!ENDNOCODE!][!//
[!ENDMACRO!][!//

[!MACRO "GetXoscEn","Name"!][!//
[!NOCODE!]
    [!VAR "Mac_capitalName" = "text:replace($Name,substring($Name,2),text:tolower(substring($Name,2)))"!]
    [!VAR "Mac_enPath" = "concat('Mcu',$Name,'/Mcu',$Mac_capitalName,'PowerDownCtr')"!]
    [!VAR "Mac_xoscEn"!][!IF "node:value($Mac_enPath)"!]1[!ELSE!]0[!ENDIF!][!ENDVAR!]
[!CODE!][!//
[!"num:i($Mac_xoscEn)"!][!//
[!ENDCODE!]
[!ENDNOCODE!][!//
[!ENDMACRO!][!//


[!MACRO "GetDivisorValue","CrtCgm","CrtMux","CrtDiv"!][!//
[!NOCODE!]
    [!VAR "Mac_muxPath" = "concat('McuCgm0SettingConfig/McuCgm0ClockMux',num:i($CrtMux))"!]
    [!VAR "Mac_divPathPrefix" = "concat($Mac_muxPath,'/McuClkMux',num:i($CrtMux),'Div',num:i($CrtDiv))"!]
    [!VAR "Mac_divEnPath" = "concat($Mac_divPathPrefix,'_En')"!]
    [!VAR "Mac_divValuePath" = "concat($Mac_divPathPrefix,'_Divisor')"!]
    [!IF "node:value($Mac_divEnPath)"!]
        [!VAR "Mac_divValue" = "num:i(node:value($Mac_divValuePath) + 1)"!]
    [!ELSE!]
        [!VAR "Mac_divValue" = "0"!]
    [!ENDIF!]
[!CODE!][!//
[!"num:i($Mac_divValue)"!][!//
[!ENDCODE!]
[!ENDNOCODE!][!//
[!ENDMACRO!][!//


[!MACRO "GetPllEnable","Name"!][!//
[!NOCODE!]
    [!VAR "Mac_pllEn"!][!IF "node:value(concat('McuPll_',substring($Name,num:i(string-length($Name))),'/McuPLLEnabled'))"!]1[!ELSE!]0[!ENDIF!][!ENDVAR!]
[!CODE!][!//
[!"num:i($Mac_pllEn)"!][!//
[!ENDCODE!]
[!ENDNOCODE!][!//
[!ENDMACRO!][!//

[!MACRO "GetPllClockSelection","Name"!][!//
[!NOCODE!]
    [!VAR "Mac_pllclockselectionPath" = "concat('McuPll_',substring($Name,num:i(string-length($Name))),'/McuPllClockSelection')"!]
    [!IF "node:exists($Mac_pllclockselectionPath)"!]
        [!VAR "Mac_pllclockselection" = "node:value(concat('McuPll_',substring($Name,num:i(string-length($Name))),'/McuPllClockSelection'))"!]
    [!ELSE!]
        [!VAR "Mac_pllclockselection" = "'RESERVED_CLK'"!]
    [!ENDIF!]
[!CODE!][!//
[!"($Mac_pllclockselection)"!][!//
[!ENDCODE!]
[!ENDNOCODE!][!//
[!ENDMACRO!][!//

[!MACRO "GetPllModBypassEnable","Name"!][!//
[!NOCODE!]
    [!VAR "PllIndex" = "num:i(number(substring-after($Name,'PLL_')))"!][!//
    [!IF "$PllIndex > num:i(0)"!]
        [!VAR "Mac_pllBypEn" = "0"!]
    [!ELSE!]
        [!VAR "Mac_pllBypEn"!][!IF "node:value(concat('McuPll_',substring($Name,num:i(string-length($Name))),'/McuPll_Configuration/McuPllFmSscgbyp'))"!]1[!ELSE!]0[!ENDIF!][!ENDVAR!]
    [!ENDIF!]
[!CODE!][!//
[!"num:i($Mac_pllBypEn)"!][!//
[!ENDCODE!]
[!ENDNOCODE!][!//
[!ENDMACRO!][!//


[!MACRO "GetPllPrediv","Name"!][!//
[!NOCODE!]
    [!VAR "Mac_pllPrediv" = "node:value(concat('McuPll_',substring($Name,num:i(string-length($Name))),'/McuPll_Configuration/McuPllDvRdiv'))"!]
[!CODE!][!//
[!"num:i($Mac_pllPrediv)"!][!//
[!ENDCODE!]
[!ENDNOCODE!][!//
[!ENDMACRO!][!//


[!MACRO "GetPllNumerator","Name"!][!//
[!NOCODE!]
    [!VAR "PllIndex" = "num:i(number(substring-after($Name,'PLL_')))"!][!//
    [!IF "$PllIndex > num:i(0)"!]
        [!VAR "Mac_pllNum" = "0"!]
    [!ELSE!]
        [!VAR "Mac_pllNum" = "node:value(concat('McuPll_',substring($Name,num:i(string-length($Name))),'/McuPll_Configuration/McuPllFdMfn'))"!]
    [!ENDIF!]
[!CODE!][!//
[!"num:i($Mac_pllNum)"!][!//
[!ENDCODE!]
[!ENDNOCODE!][!//
[!ENDMACRO!][!//


[!MACRO "GetPllMultiplier","Name"!][!//
[!NOCODE!]
    [!VAR "Mac_pllMul" = "node:value(concat('McuPll_',substring($Name,num:i(string-length($Name))),'/McuPll_Configuration/McuPllDvMfi'))"!]
[!CODE!][!//
[!"num:i($Mac_pllMul)"!][!//
[!ENDCODE!]
[!ENDNOCODE!][!//
[!ENDMACRO!][!//


[!MACRO "GetPllStepSize","Name"!][!//
[!NOCODE!]
    [!VAR "PllIndex" = "num:i(number(substring-after($Name,'PLL_')))"!][!//
    [!IF "$PllIndex > num:i(0)"!]
        [!VAR "Mac_pllStepSize" = "0"!]
    [!ELSE!]
        [!VAR "Mac_pllStepSize" = "node:value(concat('McuPll_',substring($Name,num:i(string-length($Name))),'/McuPll_Configuration/McuPllFmStepSize'))"!]
    [!ENDIF!]
[!CODE!][!//
[!"num:i($Mac_pllStepSize)"!][!//
[!ENDCODE!]
[!ENDNOCODE!][!//
[!ENDMACRO!][!//


[!MACRO "GetPllStepNumber","Name"!][!//
[!NOCODE!]
    [!VAR "PllIndex" = "num:i(number(substring-after($Name,'PLL_')))"!][!//
    [!IF "$PllIndex > num:i(0)"!]
        [!VAR "Mac_pllStepNo" = "0"!]
    [!ELSE!]
        [!VAR "Mac_pllStepNo" = "node:value(concat('McuPll_',substring($Name,num:i(string-length($Name))),'/McuPll_Configuration/McuPllFmStepNo'))"!]
    [!ENDIF!]
[!CODE!][!//
[!"num:i($Mac_pllStepNo)"!][!//
[!ENDCODE!]
[!ENDNOCODE!][!//
[!ENDMACRO!][!//


[!MACRO "GetPllSigmaDelta","Name"!][!//
[!NOCODE!]
    [!VAR "PllIndex" = "num:i(number(substring-after($Name,'PLL_')))"!][!//
    [!IF "$PllIndex > num:i(0)"!]
        [!VAR "Mac_pllSDEn" = "0"!]
    [!ELSE!]
        [!VAR "Mac_pllSDEn"!][!IF "node:value(concat('McuPll_',substring($Name,num:i(string-length($Name))),'/McuPll_Configuration/McuPllFdSdmen'))"!]1[!ELSE!]0[!ENDIF!][!ENDVAR!]
    [!ENDIF!]
[!CODE!][!//
[!"num:i($Mac_pllSDEn)"!][!//
[!ENDCODE!]
[!ENDNOCODE!][!//
[!ENDMACRO!][!//


[!MACRO "GetMcuDFSPortMf","NumMcuPLL","NumDFS"!][!//
[!NOCODE!]
    [!VAR "Mac_valueDFSPortMfi" = "node:value(concat('McuPll_',$NumMcuPLL,'/McuDfs_Configuration/McuDFSPort',$NumDFS,'Mfi'))"!]
    [!VAR "Mac_valueDFSPortMfn" = "node:value(concat('McuPll_',$NumMcuPLL,'/McuDfs_Configuration/McuDFSPort',$NumDFS,'Mfn'))"!]
[!CODE!][!//
[!"num:i($Mac_valueDFSPortMfi)"!]U,
                    [!"num:i($Mac_valueDFSPortMfn)"!]U,[!//
[!ENDCODE!]
[!ENDNOCODE!][!//
[!ENDMACRO!][!//


[!MACRO "GetClockSource","Name","Pcfs"!][!//
[!NOCODE!]
    [!VAR "Mac_mcupcsname" = "node:value(concat('Mcu',$Name,'SettingConfig/Mcu',$Name,'PcsConfig/Mcu',$Name,'PcsConfig_',$Pcfs,'/McuPCS_Name'))"!]
    [!FOR "Currentclksrc" = "1" TO "num:i($NumOfClkSource)"!]
        [!IF "ecu:list('MCU.PCFS.Indices.List')[num:i($Currentclksrc)] = ($Mac_mcupcsname)"!]
        [!VAR "Mac_clksrc" = "ecu:list('MCU.ClockSource.List')[num:i($Currentclksrc)]"!][!//
        [!ENDIF!]
    [!ENDFOR!]
[!CODE!][!//
[!"($Mac_clksrc)"!][!//
[!ENDCODE!]
[!ENDNOCODE!][!//
[!ENDMACRO!][!//

[!MACRO "GetPcfsClockSourceFrequency","Name","Pcfs"!][!//
[!NOCODE!]
    [!VAR "Mac_pcfsclocksourcefrequency" = "node:value(concat('Mcu',$Name,'SettingConfig/Mcu',$Name,'PcsConfig/Mcu',$Name,'PcsConfig_',$Pcfs,'/McuPCS_SourceFrequency'))"!]
[!CODE!][!//
[!"num:i($Mac_pcfsclocksourcefrequency)"!][!//
[!ENDCODE!]
[!ENDNOCODE!][!//
[!ENDMACRO!][!//

[!MACRO "GetPcfsSelectorName","Name","Pcfs"!][!//
[!NOCODE!]
    [!VAR "Mac_mcupcsname" = "node:value(concat('Mcu',$Name,'SettingConfig/Mcu',$Name,'PcsConfig/Mcu',$Name,'PcsConfig_',$Pcfs,'/McuPCS_Name'))"!]
    [!FOR "Currentclksrc" = "1" TO "num:i($NumOfClkSource)"!]
        [!IF "ecu:list('MCU.PCFS.Indices.List')[num:i($Currentclksrc)] = ($Mac_mcupcsname)"!]
        [!VAR "Mac_clksrc" = "ecu:list('MCU.PcfsSelectorName.List')[num:i($Currentclksrc)]"!][!//
        [!ENDIF!]
    [!ENDFOR!]
[!CODE!][!//
[!"($Mac_clksrc)"!][!//
[!ENDCODE!]
[!ENDNOCODE!][!//
[!ENDMACRO!][!//


[!MACRO "GetClockExternal","Name"!][!//
[!NOCODE!]
    [!VAR "Mac_externalPath" = "concat('../../Mcu',$Name,'FrequencyHz')"!]
    [!IF "node:exists($Mac_externalPath)"!]
        [!VAR "Mac_valueclockexternal" = "node:value(concat('../../Mcu',$Name,'FrequencyHz'))"!]
    [!ELSE!]
        [!VAR "Mac_externalPath" = "concat('../../Mcu',$Name,'FrequencyHz')"!]
        [!IF "node:exists($Mac_externalPath)"!]
            [!VAR "Mac_valueclockexternal" = "node:value(concat('../../Mcu',$Name,'FrequencyHz'))"!]
        [!ELSE!]
            [!VAR "Mac_valueclockexternal" = "num:i(0)"!]
        [!ENDIF!]
    [!ENDIF!]
[!CODE!][!//
[!"num:i($Mac_valueclockexternal)"!][!//
[!ENDCODE!]
[!ENDNOCODE!][!//
[!ENDMACRO!][!//

[!MACRO "GetMcuPCSStepDuration","Name"!][!//
[!NOCODE!]
    [!VAR "Mac_pcsstepduration" = "node:value(concat('Mcu',$Name,'SettingConfig/McuPCSStepDuration'))"!]
[!CODE!][!//
[!"num:i($Mac_pcsstepduration)"!][!//
[!ENDCODE!]
[!ENDNOCODE!][!//
[!ENDMACRO!][!//

[!MACRO "GetmaxAllowableIDDchange","Name"!][!//
[!NOCODE!]
    [!VAR "Mac_maxallowableiddchange" = "node:value(concat('Mcu',$Name,'SettingConfig/Mcu',$Name,'PcsConfig/Mcu',$Name,'PcsConfig_0/McuPCS_MaxAllowableDynamicIDD'))"!]
[!CODE!][!//
[!"num:i($Mac_maxallowableiddchange)"!][!//
[!ENDCODE!]
[!ENDNOCODE!][!//
[!ENDMACRO!][!//

[!MACRO "Count_configureFrequencies","Config"!][!//
[!NOCODE!][!//
    [!VAR "Mac_configureFrequenciesCount" = "num:i(count(ecu:list('MCU.ConfiguredFrequency.List')) + 1)"!][!//
[!CODE!][!//
[!"num:i($Mac_configureFrequenciesCount)"!][!//
[!ENDCODE!][!//
[!ENDNOCODE!][!//
[!ENDMACRO!][!//

[!MACRO "GetClockConfiguredFrequency","Name"!][!//
[!NOCODE!]
[!VAR "Mac_clockConfiguredfrequency" = "0"!]

[!IF "$Name = 'CORE_CLK'"!][!//
    [!VAR "Mac_clockConfiguredfrequency" = "node:value(McuCgm0SettingConfig/McuCgm0ClockMux0/McuClockMux0Divider0_Frequency)"!][!//
[!ENDIF!][!//
[!IF "$Name = 'AIPS_PLAT_CLK'"!][!//
    [!VAR "Mac_clockConfiguredfrequency" = "node:value(McuCgm0SettingConfig/McuCgm0ClockMux0/McuClockMux0Divider1_Frequency)"!][!//
[!ENDIF!][!//
[!IF "$Name = 'AIPS_SLOW_CLK'"!][!//
    [!VAR "Mac_clockConfiguredfrequency" = "node:value(McuCgm0SettingConfig/McuCgm0ClockMux0/McuClockMux0Divider2_Frequency)"!][!//
[!ENDIF!][!//
[!IF "$Name = 'FIRC_CLK'"!][!//
    [!VAR "Mac_clockConfiguredfrequency" = "node:value(McuFIRC/McuFIRC_Frequency)"!][!//
[!ENDIF!][!//
[!IF "$Name = 'FXOSC_CLK'"!][!//
    [!VAR "Mac_clockConfiguredfrequency" = "node:value(McuFXOSC/McuFXOSC_Frequency)"!][!//
[!ENDIF!][!//

[!CODE!][!//
[!"num:i($Mac_clockConfiguredfrequency)"!][!//
[!ENDCODE!]
[!ENDNOCODE!][!//
[!ENDMACRO!][!//

[!MACRO "Clock_Ip_Clock_Config","Type"!][!//
[!NOCODE!]

[!LOOP "McuModuleConfiguration/McuClockSettingConfig/*"!]
    [!VAR "Mac_ClockConfig" = "num:i(num:i(McuClockSettingId))"!]
    [!VAR "Mac_ircoscsCount"!][!CALL "Count_Ircoscs",Config="$Mac_ClockConfig"!][!ENDVAR!]
    [!VAR "Mac_xoscsCount"!][!CALL "Count_Xoscs",Config="$Mac_ClockConfig"!][!ENDVAR!]
    [!VAR "Mac_NumOfPllUnderMcuCtr"!][!CALL "Count_Plls",Config="$Mac_ClockConfig"!][!ENDVAR!]
    [!VAR "Mac_selectorsCount"!][!CALL "Count_Selectors",Config="$Mac_ClockConfig"!][!ENDVAR!]
    [!VAR "Mac_NumOfDivUnderMcuCtr"!][!CALL "Count_Dividers",Config="$Mac_ClockConfig"!][!ENDVAR!]
    [!VAR "Mac_extClksCount"!][!CALL "Count_ExtClks",Config="$Mac_ClockConfig"!][!ENDVAR!]
    [!VAR "Mac_specificCount"!][!CALL "Count_Specific"!][!ENDVAR!]
    [!VAR "Mac_NumOfDivTriggerUnderMcuCtr"!][!CALL "Count_Dividers_Trigger"!][!ENDVAR!]
    [!VAR "Mac_NumOfUnderClkPcfs"!][!CALL "Count_Clk_Pcfs",Config="$Mac_ClockConfig"!][!ENDVAR!]
    [!VAR "Mac_NumOfUnderClkMonitor"!][!CALL "Count_Clk_Monitor",Config="$Mac_ClockConfig"!][!ENDVAR!]
    [!VAR "Mac_configureFrequenciesCount"!][!CALL "Count_configureFrequencies",Config="$Mac_ClockConfig"!][!ENDVAR!]
    [!CODE!]
[!IF "$Mac_ircoscsCount > num:i(0)"!][!//
static const Clock_Ip_IrcoscConfigType Clock_Ip_IrcoscConfigurations_[!"$Mac_ClockConfig"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][CLOCK_IP_CONFIGURED_IRCOSCS_[!"$Mac_ClockConfig"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_NO] = {

[!FOR "IrcoscsIterator" = "1" TO "num:i($HwpIrcoscCount)"!][!//
[!VAR "Mac_Ircoscs" = "ecu:list('MCU.IRCOSC.List')[num:i($IrcoscsIterator)]"!][!//
[!VAR "Mac_capitalIrcoscs" = "text:replace($Mac_Ircoscs,substring($Mac_Ircoscs,2),text:tolower(substring($Mac_Ircoscs,2)))"!][!//
[!VAR "Mac_IrcoscsPath" = "concat('Mcu',$Mac_Ircoscs,'/Mcu',$Mac_capitalIrcoscs,'UnderMcuControl')"!][!//
[!IF "node:value($Mac_IrcoscsPath)"!][!//
[!VAR "Mac_Ircosc" = "ecu:list('MCU.IRCOSC.List')[num:i($IrcoscsIterator)]"!][!//
    {
        [!"ecu:list('MCU.IRCOSC.Names')[num:i($IrcoscsIterator)]"!],
        [!CALL "GetIrcoscEn","Name"="$Mac_Ircosc","ClockSourceName"="ecu:list('MCU.IRCOSC.Names')[num:i($IrcoscsIterator)]"!]U,
        0U,
        [!CALL "GetIrcoscRange","ClockSourceName"="ecu:list('MCU.IRCOSC.Names')[num:i($IrcoscsIterator)]"!],
        0U,
        0U,
    },

[!ENDIF!][!//
[!ENDFOR!][!//
};

[!ENDIF!][!//
[!IF "$Mac_xoscsCount > num:i(0)"!][!//
static const Clock_Ip_XoscConfigType Clock_Ip_XoscConfigurations_[!"$Mac_ClockConfig"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][CLOCK_IP_CONFIGURED_XOSCS_[!"$Mac_ClockConfig"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_NO] = {

[!FOR "XoscsIterator" = "1" TO "num:i($HwpXoscsCount)"!][!//
[!VAR "Mac_Xosc" = "ecu:list('MCU.XOSC.List')[num:i($XoscsIterator)]"!][!//
[!VAR "Mac_capitalXosc" = "text:replace($Mac_Xosc,substring($Mac_Xosc,2),text:tolower(substring($Mac_Xosc,2)))"!][!//
[!VAR "Mac_XoscPath" = "concat('Mcu',$Mac_Xosc,'/Mcu',$Mac_capitalXosc,'UnderMcuControl')"!][!//
[!IF "node:value($Mac_XoscPath)"!][!//
[!VAR "Mac_Xosc" = "ecu:list('MCU.XOSC.List')[num:i($XoscsIterator)]"!][!//
    {
        [!"ecu:list('MCU.XOSC.Names')[num:i($XoscsIterator)]"!],                    /* Clock name associated to xosc */
        [!CALL "GetXoscFrequency","Name"="$Mac_Xosc"!]U,                    /* External oscillator frequency. */
        [!CALL "GetXoscEn","Name"="$Mac_Xosc"!]U,                           /* Enable xosc. */
        [!CALL "GetXoscCounter","Name"="$Mac_Xosc"!]U,                         /* Startup stabilization time. */
        [!CALL "GetXoscBypass","Name"="$Mac_Xosc"!]U,                           /* XOSC bypass option */
        [!CALL "GetXoscComp","Name"="$Mac_Xosc"!]U,                           /* Comparator enable */
        [!CALL "GetXoscOverdrive","Name"="$Mac_Xosc"!]U,                          /* Crystal overdrive protection */
        0U,                     /* Gain value */
        0U,                     /* Monitor type */
        0U,                     /* Automatic level controller */
    },

[!ENDIF!][!//
[!ENDFOR!][!//
};

[!ENDIF!]
[!IF "$Mac_NumOfPllUnderMcuCtr > num:i(0)"!][!//
static const Clock_Ip_PllConfigType Clock_Ip_PllConfigurations_[!"$Mac_ClockConfig"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][CLOCK_IP_CONFIGURED_PLLS_[!"$Mac_ClockConfig"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_NO] = {

[!FOR "PllIterator" = "1" TO "num:i($HwpllsCount)"!][!//
[!IF "node:value(concat('McuPll_',num:i($PllIterator - 1),'/McuPLLUnderMcuControl'))"!][!//
[!VAR "Mac_Pll" = "ecu:list('MCU.PLL.List')[num:i($PllIterator)]"!][!//
[!IF "$PllIterator = num:i(2)"!][!//
[!VAR "Mac_PllBypass" = "num:i('1')"!][!//
[!ELSE!][!//
[!VAR "Mac_PllBypass"!][!CALL "GetPllModBypassEnable","Name"="$Mac_Pll"!][!ENDVAR!][!//
[!ENDIF!][!//
    {
        [!"ecu:list('MCU.PLL.Names.List')[num:i($PllIterator)]"!],                  /*!<     name;                    */
        [!CALL "GetPllEnable","Name"="$Mac_Pll"!]U,                           /*!<     enable;                  */
        [!CALL "GetPllClockSelection","Name"="$Mac_Pll"!],                    /*!<     inputReference           */
        0U,                           /*!<     bypass;                  */
        [!CALL "GetPllPrediv","Name"="$Mac_Pll"!]U,                           /*!<     predivider;              */
        0U,                           /*!<     multiplier;              */
        0U,                           /*!<     postdivider;              */
        [!CALL "GetPllNumerator","Name"="$Mac_Pll"!]U,                           /*!<     numeratorFracLoopDiv;    */
        [!CALL "GetPllMultiplier","Name"="$Mac_Pll"!]U,                          /*!<     mulFactorDiv;            */
        [!IF "num:i($Mac_PllBypass) = num:i('1')"!]1[!ELSE!]0[!ENDIF!]U,                           /*!<     ModulationBypass;              */
        1U,                           /*!<     modulationType;          */
        [!IF "$PllIterator = num:i(2)"!]0[!ELSE!][!CALL "GetPllStepSize","Name"="$Mac_Pll"!][!ENDIF!]U,                           /*!<     modulationPeriod;        */
        [!IF "$PllIterator = num:i(2)"!]0[!ELSE!][!CALL "GetPllStepNumber","Name"="$Mac_Pll"!][!ENDIF!]U,                           /*!<     incrementStep;           */
        [!CALL "GetPllSigmaDelta","Name"="$Mac_Pll"!]U,                           /*!<     sigmaDelta;              */
        0U,                           /*!<     ditherControl;           */
        0U,                           /*!<     ditherControlValue;      */
        0U,                           /*!<     Monitor type */
        {                             /*!<     Dividers */
                0U,
                0U,
                0U,
        },
    },

[!ENDIF!][!//
[!ENDFOR!][!//
};

[!ENDIF!]
[!ENDCODE!]
[!IF "$Mac_selectorsCount > num:i(0)"!][!//
[!CODE!]
static const Clock_Ip_SelectorConfigType Clock_Ip_SelectorConfigurations_[!"$Mac_ClockConfig"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][CLOCK_IP_CONFIGURED_SELECTORS_[!"$Mac_ClockConfig"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_NO] = {

[!ENDCODE!]
[!VAR "Mac_CurrentSelector" = "0"!]
[!FOR "SelectorIndexOfList" = "1" TO "num:i($HwSelectorCount)"!][!//
[!// Selector of MC_CGM
            [!FOR "SelectorCGMx" = "1" TO "num:i($NrOfCgmx)"!]
[!VAR "Mac_IndexCGM" = "substring-after(ecu:list('MCU.CGM.CgmModules.List')[number($SelectorCGMx)], 'Cgm')"!]
            [!VAR "Mac_NumOfSelectors" = "count(ecu:list(concat('MCU.CGM',$Mac_IndexCGM,'.ClockMuxes.List')))"!]
            [!VAR "Mac_CurrentSelector" = "$Mac_CurrentSelector"!]
            [!FOR "SelectorIterator" = "1" TO "num:i($Mac_NumOfSelectors)"!]
                [!VAR "Mac_SelectorIndex" = "substring-after(ecu:list(concat('MCU.CGM',$Mac_IndexCGM,'.ClockMuxes.List'))[num:i($SelectorIterator)],'CLKMUX_')"!]
                [!VAR "Mac_SelectorPath" = "concat('McuCgm',$Mac_IndexCGM,'SettingConfig/McuCgm',$Mac_IndexCGM,'ClockMux',$Mac_SelectorIndex)"!]
                [!IF "node:exists($Mac_SelectorPath)"!]
                    [!VAR "Mac_ControlPath" = "concat($Mac_SelectorPath,'/McuClockMuxUnderMcuControl')"!]
                    [!IF "node:value($Mac_ControlPath)"!]
                        [!IF "ecu:list('MCU.SELECTOR.Names.List')[number($SelectorIndexOfList)] = ecu:list(concat('MCU.CGM',$Mac_IndexCGM,'.ClockMuxes.Names.List'))[num:i($SelectorIterator)]"!]
        [!CODE!]
    {
        [!"ecu:list(concat('MCU.CGM',$Mac_IndexCGM,'.ClockMuxes.Names.List'))[num:i($SelectorIterator)]"!],                     /* Clock name associated to selector */
        [!"node:value(concat($Mac_SelectorPath,'/McuClkMux',$Mac_SelectorIndex,'_Source'))"!],                       /* Name of the selected input source */
    },
        [!ENDCODE!]
                    [!VAR "Mac_CurrentSelector" = "$Mac_CurrentSelector + 1"!]
                        [!ENDIF!]
                    [!ENDIF!]
                [!ENDIF!]
            [!ENDFOR!]
            [!ENDFOR!]
[!// Selector of RTC_RTCC
                [!VAR "Mac_SelectorPath" = "'McuRtcClockSelect'"!]
                [!IF "node:exists($Mac_SelectorPath)"!]
                    [!VAR "Mac_ControlPath" = "concat($Mac_SelectorPath,'/McuClockMuxUnderMcuControl')"!]
                    [!IF "node:value($Mac_ControlPath)"!]
                        [!IF "ecu:list('MCU.SELECTOR.Names.List')[number($SelectorIndexOfList)] = 'RTC_CLK'"!]
        [!CODE!]
    {
        RTC_CLK,                     /* Clock name associated to selector */
        [!"node:value(concat($Mac_SelectorPath,'/McuRtc_Source'))"!],                       /* Name of the selected input source */
    },
        [!ENDCODE!]
                    [!VAR "Mac_CurrentSelector" = "$Mac_CurrentSelector + 1"!]
                        [!ENDIF!]
                    [!ENDIF!]
                [!ENDIF!]
[!ENDFOR!] [!// "SelectorIndexOfList"
[!CODE!]
};
[!ENDCODE!]
[!ENDIF!]
[!IF "$Mac_NumOfDivUnderMcuCtr > num:i(0)"!][!//
[!CODE!]
static const Clock_Ip_DividerConfigType Clock_Ip_DividerConfigurations_[!"$Mac_ClockConfig"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][CLOCK_IP_CONFIGURED_DIVIDERS_[!"$Mac_ClockConfig"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_NO] = {
[!ENDCODE!]
    [!VAR "Mac_CurrentDivider" = "0"!]
    [!VAR "Mac_DivValue" = "0"!]
[!FOR "DividerIndexOfList" = "1" TO "num:i($HwDividerCount)"!][!//
    [!// Divider of PLL
    [!FOR "PllCount" = "1" TO "num:i($HwpllsCount)"!][!//
        [!VAR "Mac_IndexPllx" = "substring-after(ecu:list('MCU.PLL.List')[number($PllCount)],'PLL_')"!]
        [!VAR "Mac_PllPath" = "concat('McuPll_',$Mac_IndexPllx)"!]
        [!IF "node:exists($Mac_PllPath)"!]
            [!VAR "Mac_McuControlPllPath" = "concat($Mac_PllPath,'/McuPLLUnderMcuControl')"!]
            [!IF "node:value($Mac_McuControlPllPath)"!]
                [!VAR "Mac_PllDividersList" = "concat('MCU.PLL',$Mac_IndexPllx,'.Dividers.List')"!]
                [!VAR "Mac_NrOfPllDivs" = "count(ecu:list($Mac_PllDividersList))"!]
                [!VAR "Mac_NrOfPllDV" = "count(ecu:list('MCU.PLL.Dividers.List'))"!]
                [!VAR "Mac_PllDivName" = "ecu:list('MCU.PLL.Dividers.Names.List')[num:i($PllCount)]"!]
                [!VAR "Mac_PllDivPath" = "concat('McuPll_',($Mac_IndexPllx),'/McuPll_Configuration/McuPllDvOdiv2')"!]
                [!IF "node:exists($Mac_PllDivPath)"!]
                    [!VAR "Mac_DivValue" = "num:i(node:value($Mac_PllDivPath))"!]
                [!ELSE!]
                    [!VAR "Mac_DivValue" = "0"!]
                [!ENDIF!]
                [!IF "ecu:list('MCU.DIVIDER.Names.List')[number($DividerIndexOfList)] = ($Mac_PllDivName)"!]
[!CODE!][!//
    {
        [!"($Mac_PllDivName)"!],
        [!"num:i($Mac_DivValue)"!]U,
        {
            0U,
        }
    },
[!ENDCODE!][!//
                    [!VAR "Mac_CurrentDivider" = "$Mac_CurrentDivider + 1"!]
                [!ENDIF!]
                [!FOR "PllDivIterator" = "1" TO "num:i($Mac_NrOfPllDivs)"!]
                    [!VAR "Mac_PllDivName" = "ecu:list(concat('MCU.PLL',$Mac_IndexPllx,'.Dividers.Names.List'))[num:i($PllDivIterator)]"!]
                    [!VAR "Mac_DivEnPath" = "concat('McuPll_',($Mac_IndexPllx),'/McuPll_Configuration/Mcu',ecu:list($Mac_PllDividersList)[num:i($PllDivIterator)],'_En')"!]
                    [!IF "node:value($Mac_DivEnPath)"!]
                        [!VAR "Mac_DivValPath" = "concat('McuPll_',($Mac_IndexPllx),'/McuPll_Configuration/Mcu',ecu:list($Mac_PllDividersList)[num:i($PllDivIterator)],'_Div')"!]
                        [!VAR "Mac_DivValue" = "num:i(node:value($Mac_DivValPath) + 1)"!]
                    [!ELSE!]
                        [!VAR "Mac_DivValue" = "0"!]
                    [!ENDIF!]
                        [!IF "ecu:list('MCU.DIVIDER.Names.List')[number($DividerIndexOfList)] = ($Mac_PllDivName)"!]
[!CODE!]
    {
        [!"($Mac_PllDivName)"!],
        [!"num:i($Mac_DivValue)"!]U,
        {
            0U,
        }
    },
[!ENDCODE!]
                    [!VAR "Mac_CurrentDivider" = "$Mac_CurrentDivider + 1"!]
                        [!ENDIF!]
                [!ENDFOR!]
            [!ENDIF!]
        [!ENDIF!]
    [!ENDFOR!]
    [!// FIRC post divider
        [!VAR "Mac_FircPostDividerPath" = "'McuFIRC/McuFircDivSel'"!]
        [!IF "node:exists($Mac_FircPostDividerPath)"!]
            [!VAR "Mac_FircControlPath" = "'McuFIRC/McuFircUnderMcuControl'"!]
            [!IF "node:value($Mac_FircControlPath)"!]
                [!VAR "Mac_FircPostDividerName" = "'FIRC_POSTDIV_CLK'"!]
                [!IF "node:value($Mac_FircPostDividerPath) = 'Div_by_1'"!][!//
                    [!VAR "Mac_DivValue" = "num:i(1)"!][!//
                [!ELSEIF "node:value($Mac_FircPostDividerPath) = 'Div_by_2'"!][!//
                    [!VAR "Mac_DivValue" = "num:i(2)"!][!//
                [!ELSEIF "node:value($Mac_FircPostDividerPath) = 'Div_by_16'"!][!//
                    [!VAR "Mac_DivValue" = "num:i(16)"!][!//
                [!ELSE!][!//
                    [!VAR "Mac_DivValue" = "num:i(0)"!][!//
                [!ENDIF!][!//
                [!IF "ecu:list('MCU.DIVIDER.Names.List')[number($DividerIndexOfList)] = ($Mac_FircPostDividerName)"!]
[!CODE!]
    {
        RESERVED_CLK,
        [!"num:i($Mac_DivValue)"!]U,
        {
            0U,
        }
    },
[!ENDCODE!]
                    [!VAR "Mac_CurrentDivider" = "$Mac_CurrentDivider + 1"!]
                [!ENDIF!]
            [!ENDIF!]
        [!ENDIF!]
    [!// Divider of CGM
    [!FOR "CgmCount" = "1" TO "num:i($NrOfCgmx)"!]
        [!VAR "Mac_IndexCGMx" = "substring-after(ecu:list('MCU.CGM.CgmModules.List')[number($CgmCount)],'Cgm')"!]
        [!VAR "Mac_NumOfMux" = "count(ecu:list(concat('MCU.CGM',$Mac_IndexCGMx,'.ClockMuxes.List')))"!]
        [!FOR "MuxIterator" = "1" TO "num:i($Mac_NumOfMux)"!]
            [!VAR "Mac_IndexMux" = "substring-after(ecu:list(concat('MCU.CGM',$Mac_IndexCGMx,'.ClockMuxes.List'))[num:i($MuxIterator)], 'CLKMUX_')"!]
            [!VAR "Mac_MuxPath" = "concat('McuCgm',$Mac_IndexCGMx,'SettingConfig/McuCgm',$Mac_IndexCGMx,'ClockMux',$Mac_IndexMux)"!]
            [!IF "node:exists($Mac_MuxPath)"!]
                [!VAR "Mac_ControlPath" = "concat($Mac_MuxPath,'/McuClockMuxUnderMcuControl')"!]
                [!IF "node:value($Mac_ControlPath)"!]
                    [!VAR "Mac_DividersList" = "concat('MCU.CGM',$Mac_IndexCGMx,'.ClockMux',$Mac_IndexMux,'.Dividers.List')"!]
                    [!VAR "Mac_NrOfMuxDivs" = "count(ecu:list($Mac_DividersList))"!]
                    [!FOR "MuxDivIterator" = "1" TO "num:i($Mac_NrOfMuxDivs)"!]
                        [!VAR "Mac_MuxDivName" = "ecu:list(concat('MCU.CGM',$Mac_IndexCGMx,'.ClockMux',$Mac_IndexMux,'.Dividers.Names.List'))[num:i($MuxDivIterator)]"!]
                        [!VAR "Mac_MuxDivEnPath" = "concat('McuCgm',($Mac_IndexCGMx),'SettingConfig/McuCgm',$Mac_IndexCGMx,'ClockMux',($Mac_IndexMux),'/McuClkMux',($Mac_IndexMux),ecu:list($Mac_DividersList)[num:i($MuxDivIterator)],'_En')"!]
                        [!IF "node:value($Mac_MuxDivEnPath)"!]
                            [!VAR "Mac_DivValPath" = "concat('McuCgm',($Mac_IndexCGMx),'SettingConfig/McuCgm',$Mac_IndexCGMx,'ClockMux',($Mac_IndexMux),'/McuClkMux',($Mac_IndexMux),ecu:list($Mac_DividersList)[num:i($MuxDivIterator)],'_Divisor')"!]
                            [!VAR "Mac_DivValue" = "num:i(node:value($Mac_DivValPath) + 1)"!]
                        [!ELSE!]
                            [!VAR "Mac_DivValue" = "0"!]
                        [!ENDIF!]
                            [!IF "ecu:list('MCU.DIVIDER.Names.List')[number($DividerIndexOfList)] = ($Mac_MuxDivName)"!]
[!CODE!]
    {
        [!"($Mac_MuxDivName)"!],
        [!"num:i($Mac_DivValue)"!]U,
        {
            0U,
        }
    },
[!ENDCODE!]
                        [!VAR "Mac_CurrentDivider" = "$Mac_CurrentDivider + 1"!]
                            [!ENDIF!]
                    [!ENDFOR!]
                [!ENDIF!]
            [!ENDIF!]
        [!ENDFOR!]
    [!ENDFOR!]
[!ENDFOR!] [!// "DividerIndexOfList"
[!CODE!]
};

[!ENDCODE!]
[!ENDIF!]
[!CODE!]
[!IF "text:tolower(ecu:get('MCU.CGM.DividerTriggerSupport')) = 'true'"!][!//
[!IF "$Mac_NumOfDivTriggerUnderMcuCtr > num:i(0)"!][!//
static const Clock_Ip_DividerTriggerConfigType Clock_Ip_DividerTriggerConfigurations_[!"$Mac_ClockConfig"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][CLOCK_IP_CONFIGURED_DIVIDER_TRIGGERS_[!"$Mac_ClockConfig"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_NO] = {

[!VAR "Mac_CommonDividerTrigger" = "0"!][!//
[!VAR "Mac_CurrentDividerTrigger" = "0"!][!//
[!VAR "Mac_DivTriggerValue" = "0"!][!//
[!FOR "CgmCount" = "1" TO "num:i($NrOfCgmx)"!][!//
[!VAR "Mac_IndexCGMx" = "substring-after(ecu:list('MCU.CGM.CgmModules.List')[number($CgmCount)],'Cgm')"!][!//
[!VAR "Mac_NumOfMux" = "count(ecu:list(concat('MCU.CGM',$Mac_IndexCGMx,'.ClockMuxes.List')))"!][!//
[!FOR "MuxIterator" = "1" TO "num:i($Mac_NumOfMux)"!][!//
[!VAR "Mac_IndexMux" = "substring-after(ecu:list(concat('MCU.CGM',$Mac_IndexCGMx,'.ClockMuxes.List'))[num:i($MuxIterator)], 'CLKMUX_')"!][!//
[!VAR "Mac_MuxPath" = "concat('McuCgm',$Mac_IndexCGMx,'SettingConfig/McuCgm',$Mac_IndexCGMx,'ClockMux',$Mac_IndexMux)"!][!//
[!IF "node:exists($Mac_MuxPath)"!][!//
[!VAR "Mac_ControlPath" = "concat($Mac_MuxPath,'/McuClockMuxUnderMcuControl')"!][!//
[!IF "node:value($Mac_ControlPath)"!][!//
[!IF "text:tolower(ecu:get('MCU.CGM.MultipleOnMuxSupport')) = 'true'"!][!//
[!VAR "Mac_DividersList" = "concat('MCU.CGM',$Mac_IndexCGMx,'.ClockMux',$Mac_IndexMux,'.Dividers.List')"!][!//
[!VAR "Mac_NrOfMuxDivs" = "count(ecu:list($Mac_DividersList))"!][!//
[!FOR "MuxDivIterator" = "1" TO "num:i($Mac_NrOfMuxDivs)"!][!//
[!VAR "Mac_MuxDivName" = "ecu:list(concat('MCU.CGM',$Mac_IndexCGMx,'.ClockMux',$Mac_IndexMux,'.Dividers.Names.List'))[num:i($MuxDivIterator)]"!][!//
[!VAR "Mac_MuxDivEnPath" = "concat('McuCgm',($Mac_IndexCGMx),'SettingConfig/McuCgm',$Mac_IndexCGMx,'ClockMux',($Mac_IndexMux),'/McuClkMux',($Mac_IndexMux),ecu:list($Mac_DividersList)[num:i($MuxDivIterator)],'_En')"!][!//
[!IF "node:value($Mac_MuxDivEnPath)"!][!//
[!VAR "Mac_DivTriggerPath" = "concat($Mac_MuxPath,'/McuClkMux',$Mac_IndexMux,ecu:list($Mac_DividersList)[num:i($MuxDivIterator)],'Trigger')"!][!//
[!IF "node:exists($Mac_DivTriggerPath)"!][!//
[!IF "node:value($Mac_DivTriggerPath) = 'COMMON_TRIGGER_DIVIDER_UPDATE'"!][!//
[!VAR "Mac_CommonDividerTrigger" = "$Mac_CommonDividerTrigger + 1"!][!//
[!ENDIF!][!//
[!ENDIF!][!//
[!ENDIF!][!//
[!ENDFOR!][!//
[!ELSE!][!//
[!VAR "Mac_DividersList" = "concat('MCU.CGM',$Mac_IndexCGMx,'.ClockMux',$Mac_IndexMux,'.Dividers.List')"!][!//
[!VAR "Mac_NrOfMuxDivs" = "count(ecu:list($Mac_DividersList))"!][!//
[!FOR "MuxDivIterator" = "1" TO "num:i($Mac_NrOfMuxDivs)"!][!//
[!VAR "Mac_MuxDivName" = "ecu:list(concat('MCU.CGM',$Mac_IndexCGMx,'.ClockMux',$Mac_IndexMux,'.Dividers.Names.List'))[num:i($MuxDivIterator)]"!][!//
[!VAR "Mac_MuxDivEnPath" = "concat('McuCgm',($Mac_IndexCGMx),'SettingConfig/McuCgm',$Mac_IndexCGMx,'ClockMux',($Mac_IndexMux),'/McuClkMux',($Mac_IndexMux),ecu:list($Mac_DividersList)[num:i($MuxDivIterator)],'_En')"!][!//
[!IF "node:value($Mac_MuxDivEnPath)"!][!//
[!VAR "Mac_DivTriggerPath" = "concat($Mac_MuxPath,'/McuClkMux',$Mac_IndexMux,ecu:list($Mac_DividersList)[num:i($MuxDivIterator)],'Trigger')"!][!//
[!IF "node:exists($Mac_DivTriggerPath)"!][!//
[!VAR "Mac_DivTriggerValue" = "node:value($Mac_DivTriggerPath)"!][!//
    {
        [!CALL "GetDivTriggerClk","CrtCgm"="$Mac_IndexCGMx","CrtMux"="$Mac_IndexMux"!],                     /* divider name */
        [!"($Mac_DivTriggerValue)"!],      /* trigger value */
        [!CALL "GetDivTriggerClk","CrtCgm"="$Mac_IndexCGMx","CrtMux"="$Mac_IndexMux"!],                     /* input source name */
    },
[!VAR "Mac_CurrentDividerTrigger" = "$Mac_CurrentDividerTrigger + 1"!][!//
[!ENDIF!][!//
[!ENDIF!][!//
[!ENDFOR!][!//
[!ENDIF!][!//
[!ENDIF!][!//
[!ENDIF!][!//
[!ENDFOR!][!//
[!ENDFOR!][!//
[!IF "text:tolower(ecu:get('MCU.CGM.MultipleOnMuxSupport')) = 'true'"!][!//
[!IF "$Mac_CommonDividerTrigger > num:i(0)"!][!//
    {
        CORE_CLK,                     /* divider name */
        COMMON_TRIGGER_DIVIDER_UPDATE,      /* trigger value */
        CORE_CLK,                     /* input source name */
    },
[!ELSE!][!//
    {
        CORE_CLK,                     /* divider name */
        IMMEDIATE_DIVIDER_UPDATE,      /* trigger value */
        CORE_CLK,                     /* input source name */
    },
[!VAR "Mac_NumOfDivTriggerUnderMcuCtr" = "1"!][!//
[!ENDIF!][!//
[!ENDIF!][!//
};

[!ENDIF!][!//
[!ENDIF!][!//
[!IF "$NrOfClkExternal > num:i(0)"!][!//
static const Clock_Ip_ExtClkConfigType Clock_Ip_ExtClkConfigurations_[!"$Mac_ClockConfig"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][CLOCK_IP_CONFIGURED_EXT_CLKS_[!"$Mac_ClockConfig"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_NO] = {

[!FOR "ClkExternal" = "1" TO "num:i($NrOfClkExternal)"!][!//
[!VAR "Mac_ClkExternalname" = "ecu:list('MCU.ExtClock.List')[num:i($ClkExternal)]"!][!//
    {
        [!"($Mac_ClkExternalname)"!],
        [!CALL "GetClockExternal","Name"="$Mac_ClkExternalname"!]U,
    },
[!ENDFOR!][!//
};

[!ENDIF!][!//
[!IF "$Mac_NumOfUnderClkPcfs > num:i(0)"!][!//
static const Clock_Ip_PcfsConfigType Clock_Ip_PcfsConfigurations_[!"$Mac_ClockConfig"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][CLOCK_IP_CONFIGURED_PCFS_[!"$Mac_ClockConfig"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_NO] = {

[!VAR "Mac_ClkPcfsIterator" = "0"!][!//
[!FOR "CurrentCgm" = "1" TO "num:i($NrOfCgmx)"!][!//
[!VAR "Mac_cgm" = "ecu:list('MCU.CGM.CgmModules.List')[num:i($CurrentCgm)]"!][!//
[!VAR "Mac_capitalName" = "text:replace($Mac_cgm,substring($Mac_cgm,2),text:toupper(substring($Mac_cgm,2)))"!][!//
[!VAR "Mac_pcfscount" = "count(ecu:list(concat('MCU.',$Mac_capitalName,'.CgmPcfs.List')))"!][!//
[!FOR "CurrentPCFS" = "0" TO "num:i($Mac_pcfscount - 1)"!][!//
[!IF "node:value(concat('Mcu',$Mac_cgm,'SettingConfig/Mcu',$Mac_cgm,'PcsConfig/Mcu',$Mac_cgm,'PcsConfig_',$CurrentPCFS,'/McuClockPcfsUnderMcuControl'))"!][!//
    {
        [!CALL "GetClockSource","Name"="$Mac_cgm","Pcfs"="$CurrentPCFS"!],
        [!CALL "GetmaxAllowableIDDchange","Name"="$Mac_cgm"!]U,
        [!CALL "GetMcuPCSStepDuration","Name"="$Mac_cgm"!]U,
        [!CALL "GetPcfsSelectorName","Name"="$Mac_cgm","Pcfs"="$CurrentPCFS"!],
        [!CALL "GetPcfsClockSourceFrequency","Name"="$Mac_cgm","Pcfs"="$CurrentPCFS"!]U,
    },
[!VAR "Mac_ClkPcfsIterator" = "$Mac_ClkPcfsIterator + 1"!][!//
[!ENDIF!][!//
[!ENDFOR!][!//
[!ENDFOR!][!//
};

[!ENDIF!][!//
[!IF "$Mac_NumOfUnderClkMonitor > num:i(0)"!][!//
static const Clock_Ip_CmuConfigType Clock_Ip_CmuConfigurations_[!"$Mac_ClockConfig"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][CLOCK_IP_CONFIGURED_CMUS_[!"$Mac_ClockConfig"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_NO] = {

[!IF "node:exists("McuClkMonitor")"!][!//
[!VAR "Mac_ClkMonitorIterator" = "0"!][!//
[!VAR "Mac_ClkMonitorName" = "0"!][!//
[!LOOP "./McuClkMonitor/*"!][!//
[!VAR "Mac_ClkMonitorName" = "$Mac_ClkMonitorName + 1"!][!//
[!VAR "Mac_McuCmuName" = "ecu:list('MCU.CMU_FC.List')[num:i($Mac_ClkMonitorName)]"!][!//
[!VAR "Mac_MonitorName"!][!CALL "GetCmuMonitorName","CmuIndex"="$Mac_ClkMonitorName"!][!ENDVAR!][!//
[!IF "node:value(./McuClockMonitorUnderMcuControl)"!][!//
[!VAR "Mac_ClkMonitorIterator" = "$Mac_ClkMonitorIterator + 1"!][!//
[!VAR "Mac_RegValuesIterator" = "$Mac_RegValuesIterator + 4"!][!//
    {
        [!"$Mac_MonitorName"!],            /* Clock name associated to clock monitor. */
        [!CALL "GetCmuEnable"!]U,                   /*Enable/disable clock monitor [!"$Mac_McuCmuName"!] */
        (                                           /* IER for [!"$Mac_McuCmuName"!] */
        CMU_FC_IER_FLLIE([!IF "./McuFLLInterruptEn = 'true'"!]1U[!ELSE!]0U[!ENDIF!]) |
        CMU_FC_IER_FHHIE([!IF "./McuFHHInterruptEn = 'true'"!]1U[!ELSE!]0U[!ENDIF!]) |
        CMU_FC_IER_FLLAIE([!IF "./McuFLLAsyncEventEn = 'true'"!]1U[!ELSE!]0U[!ENDIF!]) |
        CMU_FC_IER_FHHAIE([!IF "./McuFHHAsyncEventEn = 'true'"!]1U[!ELSE!]0U[!ENDIF!])
        ),
        [!CALL "GetMonitoredClockFrequency","Name"="$Mac_McuCmuName"!]U,
[!IF "../../../../../McuGeneralConfiguration/McuRegisterValuesOptimization = 'ENABLED'"!][!//
        {
            [!"num:i($Mac_RegValuesIterator - 4)"!]U,          /* Start index in register values array */
            [!"num:i($Mac_RegValuesIterator - 0)"!]U,          /* End index in register values array */
        },
[!ELSE!][!//
        {
            0U,          /* Start index in register values array */
            0U,          /* End index in register values array */
        },
[!ENDIF!][!//
    },
[!ENDIF!][!//
[!ENDLOOP!][!//
[!ENDIF!][!//
};

[!ENDIF!][!//
[!IF "$Mac_configureFrequenciesCount > num:i(0)"!][!//
static const Clock_Ip_ConfiguredFrequencyType Clock_Ip_ConfiguredFrequencyConfigurations_[!"$Mac_ClockConfig"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][CLOCK_IP_CONFIGURED_FREQUENCIES_COUNT] = {

    {
        CLOCK_IS_OFF,
        0U,
    },
[!FOR "ClkConfiguredFrequency" = "1" TO "num:i($Mac_configureFrequenciesCount)-1"!][!//
[!VAR "Mac_ClkConfiguredFrequencyname" = "ecu:list('MCU.ConfiguredFrequency.List')[num:i($ClkConfiguredFrequency)]"!][!//
    #if CLOCK_IP_CONFIGURED_FREQUENCIES_COUNT > [!"$ClkConfiguredFrequency"!]U
    {
        [!"($Mac_ClkConfiguredFrequencyname)"!],
        [!CALL "GetClockConfiguredFrequency","Name"="$Mac_ClkConfiguredFrequencyname"!]U,
    },
    #endif
[!ENDFOR!][!//
};
[!ENDIF!][!//
[!ENDCODE!]
[!ENDLOOP!][!// "McuModuleConfiguration/McuClockSettingConfig/*"
[!CODE!]

/* *************************************************************************
 * Configuration structure for Clock Configuration 0
 * ************************************************************************* */
 /*! @brief User Configuration structure clock_Cfg_0 */
const Clock_Ip_ClockConfigType Mcu_aClockConfig[!"$Type"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][[!"num:i(count(McuModuleConfiguration/McuClockSettingConfig/*))"!]U] = {
[!ENDCODE!]
[!LOOP "McuModuleConfiguration/McuClockSettingConfig/*"!]
    [!VAR "Mac_ClockConfig" = "num:i(num:i(McuClockSettingId))"!]
    [!VAR "Mac_ircoscsCount"!][!CALL "Count_Ircoscs",Config="$Mac_ClockConfig"!][!ENDVAR!]
    [!VAR "Mac_xoscsCount"!][!CALL "Count_Xoscs",Config="$Mac_ClockConfig"!][!ENDVAR!]
    [!VAR "Mac_NumOfPllUnderMcuCtr"!][!CALL "Count_Plls",Config="$Mac_ClockConfig"!][!ENDVAR!]
    [!VAR "Mac_selectorsCount"!][!CALL "Count_Selectors",Config="$Mac_ClockConfig"!][!ENDVAR!]
    [!VAR "Mac_NumOfDivUnderMcuCtr"!][!CALL "Count_Dividers",Config="$Mac_ClockConfig"!][!ENDVAR!]
    [!VAR "Mac_extClksCount"!][!CALL "Count_ExtClks",Config="$Mac_ClockConfig"!][!ENDVAR!]
    [!VAR "Mac_specificCount"!][!CALL "Count_Specific"!][!ENDVAR!]
    [!VAR "Mac_NumOfDivTriggerUnderMcuCtr"!][!CALL "Count_Dividers_Trigger"!][!ENDVAR!]
    [!VAR "Mac_NumOfUnderClkPcfs"!][!CALL "Count_Clk_Pcfs",Config="$Mac_ClockConfig"!][!ENDVAR!]
    [!VAR "Mac_NumOfUnderClkMonitor"!][!CALL "Count_Clk_Monitor",Config="$Mac_ClockConfig"!][!ENDVAR!]
    [!VAR "Mac_configureFrequenciesCount"!][!CALL "Count_configureFrequencies",Config="$Mac_ClockConfig"!][!ENDVAR!]
    [!CODE!]
    {
        [!"num:i(num:i(McuClockSettingId))"!]U,                                 /* clkConfigId */

[!IF "../../../McuGeneralConfiguration/McuRegisterValuesOptimization = 'ENABLED' and $Mac_NumOfUnderClkMonitor > num:i(0)"!][!//
        &Mcu_aClockRegisterValues[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!],                                 /* Register data if register value optimization is enabled */
[!ELSE!][!//
        (NULL_PTR),                                 /* Register data if register value optimization is enabled */
[!ENDIF!][!//

        [!"$Mac_ircoscsCount"!]U,                                 /* ircoscsCount */
        [!"$Mac_xoscsCount"!]U,                                 /* xoscsCount */
        [!"$Mac_NumOfPllUnderMcuCtr"!]U,                                 /* pllsCount */
        [!"$Mac_selectorsCount"!]U,                                /* selectorsCount */
        [!"$Mac_NumOfDivUnderMcuCtr"!]U,                                /* dividersCount */
        [!"$Mac_NumOfDivTriggerUnderMcuCtr"!]U,                                 /* dividerTriggersCount */
        [!"num:i($NrOfClkDFSList)"!]U,                                /* fracDivsCount */
        [!"$Mac_extClksCount"!]U,                                /* extClksCount */
        0U,                                 /* gatesCount */
        [!"$Mac_NumOfUnderClkPcfs"!]U,                                 /* pcfsCount */
        [!"$Mac_NumOfUnderClkMonitor"!]U,                                /* cmusCount */
        [!"$Mac_configureFrequenciesCount"!]U,                                /* configureFrequenciesCount */

[!IF "$Mac_ircoscsCount > num:i(0)"!][!//
        (&Clock_Ip_IrcoscConfigurations_[!"num:i(num:i(McuClockSettingId))"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]),                    /* Ircosc configurations */
[!ELSE!][!//
        (NULL_PTR),                                 /* Ircosc configurations */
[!ENDIF!][!//
[!IF "$Mac_xoscsCount > num:i(0)"!][!//
        (&Clock_Ip_XoscConfigurations_[!"num:i(num:i(McuClockSettingId))"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]),                      /* Xosc configurations */
[!ELSE!][!//
        (NULL_PTR),                                 /* Xosc configurations */
[!ENDIF!][!//
[!IF "$Mac_NumOfPllUnderMcuCtr > num:i(0)"!][!//
        (&Clock_Ip_PllConfigurations_[!"num:i(num:i(McuClockSettingId))"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]),                       /* Pll configurations */
[!ELSE!][!//
        (NULL_PTR),                                 /* Pll configurations */
[!ENDIF!][!//
[!IF "$Mac_selectorsCount > num:i(0)"!][!//
        (&Clock_Ip_SelectorConfigurations_[!"num:i(num:i(McuClockSettingId))"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]),                  /* Selectors configurations */
[!ELSE!][!//
        (NULL_PTR),                                 /* Selectors configurations */
[!ENDIF!][!//
[!IF "$Mac_NumOfDivUnderMcuCtr > num:i(0)"!][!//
        (&Clock_Ip_DividerConfigurations_[!"num:i(num:i(McuClockSettingId))"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]),                   /* dividers configurations */
[!ELSE!][!//
        (NULL_PTR),                                 /* dividers configurations */
[!ENDIF!][!//
[!IF "$Mac_NumOfDivTriggerUnderMcuCtr > num:i(0)"!][!//
        (&Clock_Ip_DividerTriggerConfigurations_[!"num:i(num:i(McuClockSettingId))"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]),            /* dividerTriggers configurations */
[!ELSE!][!//
        (NULL_PTR),                                 /* dividerTriggers configurations */
[!ENDIF!][!//
        (NULL_PTR),                                 /* fracDivs configurations */
[!IF "num:i($Mac_extClksCount) > num:i(0)"!][!//
        (&Clock_Ip_ExtClkConfigurations_[!"num:i(num:i(McuClockSettingId))"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]),                    /* extClks configurations */
[!ELSE!][!//
        (NULL_PTR),                                 /* extClks configurations */
[!ENDIF!][!//
        (NULL_PTR),                                 /* gates configurations */
[!IF "num:i($Mac_NumOfUnderClkPcfs) > num:i(0)"!][!//
        (&Clock_Ip_PcfsConfigurations_[!"num:i(num:i(McuClockSettingId))"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]),                      /* pcfs configurations */
[!ELSE!][!//
        (NULL_PTR),                                 /* pcfs configurations */
[!ENDIF!][!//
[!IF "num:i($Mac_NumOfUnderClkMonitor) > num:i(0)"!][!//
        (&Clock_Ip_CmuConfigurations_[!"num:i(num:i(McuClockSettingId))"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]),                       /* cmus configurations */
[!ELSE!][!//
        (NULL_PTR),                                 /* cmus configurations */
[!ENDIF!][!//
[!IF "num:i($Mac_configureFrequenciesCount) > num:i(0)"!][!//
        (&Clock_Ip_ConfiguredFrequencyConfigurations_[!"num:i(num:i(McuClockSettingId))"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]),       /* configureFrequencies configurations */
[!ELSE!][!//
        (NULL_PTR),                                 /* configureFrequencies configurations */
[!ENDIF!][!//
    },
[!ENDCODE!]
[!ENDLOOP!][!// "McuModuleConfiguration/McuClockSettingConfig/*"
[!CODE!]
};
[!ENDCODE!]
[!ENDNOCODE!][!//
[!ENDMACRO!][!//


[!MACRO "Clock_Ip_RegisterValue_Type"!][!//
[!NOCODE!]
[!VAR "Mac_ClockRegisterValues" = "concat('','')"!]
[!VAR "Mac_CmuUnderMcuControl" = "num:i(0)"!]
[!LOOP "McuModuleConfiguration/McuClockSettingConfig/*"!]
    [!VAR "Mac_CmuNameIndex" = "0"!]
    [!VAR "Mac_NewLine"!][!CR!][!ENDVAR!][!//
    [!LOOP "./McuClkMonitor/*"!]
    [!VAR "Mac_CmuNameIndex" = "$Mac_CmuNameIndex + 1"!][!//
        [!IF "node:value(./McuClockMonitorUnderMcuControl)"!][!//
            [!VAR "Mac_CmuUnderMcuControl" = "$Mac_CmuUnderMcuControl + 1"!][!//
[!//
[!// Get base addresse for CMUs
            [!VAR "Mac_BaseAddress"!][!CALL "GetCmuBaseAddress","CmuIndex"="$Mac_CmuNameIndex"!][!ENDVAR!][!//
[!//
[!//
[!//
[!// Get RCCR_Value for CMUs
[!///* Cmp1 = ceiling of (3 * fRef/ fBus) */
[!//Cmp1 = CLOCK_IP_OFFSET_REFERENCE_COUNT_FORMULA1 + (uint32)((CLOCK_IP_MULTIPLIER_REFERENCE_COUNT_FORMULA1 * ReferenceClk) / BusClk);
[!///* Cmp2 = ceiling of (8 + (5 * fRef / fMonitor)) */
[!//Cmp2 = CLOCK_IP_OFFSET_REFERENCE_COUNT_FORMULA2 + (uint32)((CLOCK_IP_MULTIPLIER_REFERENCE_COUNT_FORMULA2 * ReferenceClk) / MonitoredClk);
[!///* REF count = Max(cmp1,cmp2) */
[!//RefCount = (Cmp1 > Cmp2) ? Cmp1 : Cmp2;
[!///* Set reference counter */
[!//CmuFc->RCCR = RefCount * CLOCK_IP_CMU_REFERENCE_COUNTER_MINIMUM_VALUE_MULTIPLIER;
            [!VAR "Mac_CLOCK_IP_OFFSET_REFERENCE_COUNT_FORMULA1" = "1"!][!//
            [!VAR "Mac_CLOCK_IP_OFFSET_REFERENCE_COUNT_FORMULA2" = "9"!][!//
            [!VAR "Mac_CLOCK_IP_MULTIPLIER_REFERENCE_COUNT_FORMULA1" = "3"!][!//
            [!VAR "Mac_CLOCK_IP_MULTIPLIER_REFERENCE_COUNT_FORMULA2" = "5"!][!//
            [!VAR "Mac_CLOCK_IP_CMU_REFERENCE_COUNTER_MINIMUM_VALUE_MULTIPLIER" = "10"!][!//
            [!VAR "Mac_NameBusClk" = "ecu:list('MCU.CMU_FC.BusClock.List')[num:i($Mac_CmuNameIndex)]"!][!//
            [!VAR "Mac_NameRefClk" = "ecu:list('MCU.CMU_FC.RefClock.List')[num:i($Mac_CmuNameIndex)]"!][!//
            [!IF "$Mac_NameBusClk = 'AIPS_SLOW_CLK'"!][!//
                [!VAR "Mac_BusClk" = "node:value(../../McuCgm0SettingConfig/McuCgm0ClockMux0/McuClockMux0Divider2_Frequency) div num:i(1000)"!][!//
            [!ENDIF!][!//
            [!IF "$Mac_NameRefClk = 'FIRC_CLK'"!][!//
                [!VAR "Mac_ReferenceClk" = "node:value(../../McuFIRC/McuFIRC_Frequency) div num:i(1000)"!][!//
            [!ENDIF!][!//
            [!IF "$Mac_NameRefClk = 'FXOSC_CLK'"!][!//
                [!VAR "Mac_ReferenceClk" = "node:value(../../McuFXOSC/McuFXOSC_Frequency) div num:i(1000)"!][!//
            [!ENDIF!][!//
            [!VAR "Mac_MonitorName"!][!CALL "GetCmuMonitorName","CmuIndex"="$Mac_CmuNameIndex"!][!ENDVAR!][!//
            [!IF "$Mac_MonitorName = 'AIPS_PLAT_CLK'"!][!//
                [!VAR "Mac_MonitoredClk" = "node:value(../../McuCgm0SettingConfig/McuCgm0ClockMux0/McuClockMux0Divider1_Frequency) div num:i(1000)"!][!//
            [!ENDIF!][!//
            [!IF "$Mac_MonitorName = 'CORE_CLK'"!][!//
                [!VAR "Mac_MonitoredClk" = "node:value(../../McuCgm0SettingConfig/McuCgm0ClockMux0/McuClockMux0Divider0_Frequency) div num:i(1000)"!][!//
            [!ENDIF!][!//
            [!IF "$Mac_MonitorName = 'FXOSC_CLK'"!][!//
                [!VAR "Mac_MonitoredClk" = "node:value(../../McuFXOSC/McuFXOSC_Frequency) div num:i(1000)"!][!//
            [!ENDIF!][!//
            [!IF "$Mac_MonitorName = 'HSE_CLK'"!][!//
                [!VAR "Mac_MonitoredClk" = "node:value(../../McuCgm0SettingConfig/McuCgm0ClockMux0/McuClockMux0Divider3_Frequency) div num:i(1000)"!][!//
            [!ENDIF!][!//
            [!VAR "Mac_Cmp1" = "($Mac_CLOCK_IP_OFFSET_REFERENCE_COUNT_FORMULA1 + ($Mac_CLOCK_IP_MULTIPLIER_REFERENCE_COUNT_FORMULA1 * $Mac_ReferenceClk) div $Mac_BusClk)"!][!//
            [!VAR "Mac_Cmp2" = "($Mac_CLOCK_IP_OFFSET_REFERENCE_COUNT_FORMULA2 + ($Mac_CLOCK_IP_MULTIPLIER_REFERENCE_COUNT_FORMULA2 * $Mac_ReferenceClk) div $Mac_MonitoredClk)"!][!//
            [!VAR "Mac_RefCount" = "num:i(0)"!][!//
            [!IF "$Mac_Cmp1 > $Mac_Cmp2"!][!//
                [!VAR "Mac_RefCount" = "$Mac_Cmp1"!][!//
            [!ELSE!][!//
                [!VAR "Mac_RefCount" = "$Mac_Cmp2"!][!//
            [!ENDIF!][!//
            [!VAR "Mac_RCCR_Value" = "num:inttohex($Mac_RefCount * $Mac_CLOCK_IP_CMU_REFERENCE_COUNTER_MINIMUM_VALUE_MULTIPLIER)"!][!//
[!//
[!//
[!//
[!// Get HTCR_Value for CMUs
[!///* (fMonitoredClk mul_by (1000U plus CLOCK_IP_CMU_MONITORED_CLOCK_VARIATION)) divide_by (fReferenceClk mul_by (1000U minus CLOCK_IP_CMU_REFERENCE_CLOCK_VARIATION)) plus CLOCK_IP_CMU_FC_VAR plus 1U */
[!//HfRef = MonitoredClk * (1000U + CLOCK_IP_CMU_MONITORED_CLOCK_VARIATION) * RefCount;
[!//DivideBy = ReferenceClk * (1000U - CLOCK_IP_CMU_REFERENCE_CLOCK_VARIATION);
[!//DividerResult = (uint32) HfRef / DivideBy;
[!//ModuloValue = HfRef - (DivideBy * DividerResult);
[!//HfRef = (DividerResult * CLOCK_IP_CMU_REFERENCE_COUNTER_MINIMUM_VALUE_MULTIPLIER) + ((uint32)((ModuloValue * CLOCK_IP_CMU_REFERENCE_COUNTER_MINIMUM_VALUE_MULTIPLIER) / DivideBy)) + (CLOCK_IP_CMU_FC_VAR + 1U);
            [!VAR "Mac_CLOCK_IP_CMU_MONITORED_CLOCK_VARIATION" = "11"!][!//
            [!VAR "Mac_CLOCK_IP_CMU_REFERENCE_CLOCK_VARIATION" = "33"!][!//
            [!VAR "Mac_CLOCK_IP_CMU_FC_VAR" = "3"!][!//
            [!VAR "Mac_HfRef" = "$Mac_MonitoredClk * (1000 + $Mac_CLOCK_IP_CMU_MONITORED_CLOCK_VARIATION) * $Mac_RefCount"!][!//
            [!VAR "Mac_DivideBy" = "$Mac_ReferenceClk * (1000 - $Mac_CLOCK_IP_CMU_REFERENCE_CLOCK_VARIATION)"!][!//
            [!VAR "Mac_DividerResult" = "$Mac_HfRef div $Mac_DivideBy"!][!//
            [!VAR "Mac_ModuloValue" = "$Mac_HfRef - ($Mac_DivideBy * $Mac_DividerResult)"!][!//
            [!VAR "Mac_HfRef" = "($Mac_DividerResult * $Mac_CLOCK_IP_CMU_REFERENCE_COUNTER_MINIMUM_VALUE_MULTIPLIER) + (($Mac_ModuloValue * $Mac_CLOCK_IP_CMU_REFERENCE_COUNTER_MINIMUM_VALUE_MULTIPLIER) div $Mac_DivideBy) + ($Mac_CLOCK_IP_CMU_FC_VAR + 1)"!][!//
            [!VAR "Mac_HTCR_Value" = "num:inttohex($Mac_HfRef)"!][!//
[!//
[!//
[!//
[!// Get LTCR_Value for CMUs
[!///* (fMonitoredClk mul_by (1000U minus CLOCK_IP_CMU_MONITORED_CLOCK_VARIATION)) divide_by (fReferenceClk mul_by (1000U plus CLOCK_IP_CMU_REFERENCE_CLOCK_VARIATION)) minus CLOCK_IP_CMU_FC_VAR */
[!//LfRef = MonitoredClk * (1000U - CLOCK_IP_CMU_MONITORED_CLOCK_VARIATION) * RefCount;
[!//DivideBy = ReferenceClk * (1000U + CLOCK_IP_CMU_REFERENCE_CLOCK_VARIATION);
[!//DividerResult = (uint32) LfRef / DivideBy;
[!//ModuloValue = LfRef - (DivideBy * DividerResult);
[!//LfRef = (DividerResult * CLOCK_IP_CMU_REFERENCE_COUNTER_MINIMUM_VALUE_MULTIPLIER) + ((uint32)((ModuloValue * CLOCK_IP_CMU_REFERENCE_COUNTER_MINIMUM_VALUE_MULTIPLIER) / DivideBy)) - CLOCK_IP_CMU_FC_VAR;
            [!VAR "Mac_LfRef" = "$Mac_MonitoredClk * (1000 - $Mac_CLOCK_IP_CMU_MONITORED_CLOCK_VARIATION) * $Mac_RefCount"!][!//
            [!VAR "Mac_DivideBy" = "$Mac_ReferenceClk * (1000 + $Mac_CLOCK_IP_CMU_REFERENCE_CLOCK_VARIATION)"!][!//
            [!VAR "Mac_DividerResult" = "$Mac_LfRef div $Mac_DivideBy"!][!//
            [!VAR "Mac_ModuloValue" = "$Mac_LfRef - ($Mac_DivideBy * $Mac_DividerResult)"!][!//
            [!VAR "Mac_LfRef" = "($Mac_DividerResult * $Mac_CLOCK_IP_CMU_REFERENCE_COUNTER_MINIMUM_VALUE_MULTIPLIER) + (($Mac_ModuloValue * $Mac_CLOCK_IP_CMU_REFERENCE_COUNTER_MINIMUM_VALUE_MULTIPLIER) div $Mac_DivideBy) - $Mac_CLOCK_IP_CMU_FC_VAR"!][!//
            [!VAR "Mac_LTCR_Value" = "num:inttohex($Mac_LfRef)"!][!//
[!//
[!//
[!//
[!// Get IER_Value for CMUs
            [!VAR "Mac_FLLInterrupt_Value"!][!IF "./McuFLLInterruptEn = 'true'"!]1[!ELSE!]0[!ENDIF!][!ENDVAR!][!//
            [!VAR "Mac_FHHInterrupt_Value"!][!IF "./McuFHHInterruptEn = 'true'"!]2[!ELSE!]0[!ENDIF!][!ENDVAR!][!//
            [!VAR "Mac_FLLAsyncEvent_Value"!][!IF "./McuFLLAsyncEventEn = 'true'"!]4[!ELSE!]0[!ENDIF!][!ENDVAR!][!//
            [!VAR "Mac_FHHAsyncEvent_Value"!][!IF "./McuFHHAsyncEventEn = 'true'"!]8[!ELSE!]0[!ENDIF!][!ENDVAR!][!//
            [!VAR "Mac_IER_Value" = "num:inttohex(bit:or((bit:or($Mac_FLLInterrupt_Value,$Mac_FHHInterrupt_Value)),(bit:or($Mac_FLLAsyncEvent_Value,$Mac_FHHAsyncEvent_Value))))"!][!//
[!//
[!//
[!//
[!// Get Mac_ClockRegisterValues for CMUs
            [!VAR "Mac_ClockRegisterValues" = "concat($Mac_ClockRegisterValues,'    {((uint32*)(',$Mac_BaseAddress,' + 0x04)),',$Mac_RCCR_Value,'},{((uint32*)(',$Mac_BaseAddress,' + 0x08)),',$Mac_HTCR_Value,'},{((uint32*)(',$Mac_BaseAddress,' + 0x0C)),',$Mac_LTCR_Value,'},{((uint32*)(',$Mac_BaseAddress,' + 0x14)),',$Mac_IER_Value,'},',$Mac_NewLine)"!]
        [!ENDIF!][!//
    [!ENDLOOP!][!// "./McuClkMonitor/*"
    [!VAR "Mac_ClockRegisterValues" = "concat($Mac_ClockRegisterValues,$Mac_NewLine)"!]
[!ENDLOOP!][!// "McuModuleConfiguration/McuClockSettingConfig/*"
[!CODE!]
[!IF "$Mac_CmuUnderMcuControl > num:i(0)"!][!//
/* *************************************************************************
 * Register addresses and values are generatated by configuration tool
 * ************************************************************************* */
const Clock_Ip_RegisterValueType Mcu_aClockRegisterValues[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][CLOCK_IP_REGISTER_VALUES_COUNT];

const Clock_Ip_RegisterValueType Mcu_aClockRegisterValues[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][CLOCK_IP_REGISTER_VALUES_COUNT] = {
[!"$Mac_ClockRegisterValues"!]
};
[!ENDIF!][!//
[!ENDCODE!]
[!ENDNOCODE!][!//
[!ENDMACRO!][!//

[!ENDNOCODE!]
