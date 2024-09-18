[!AUTOSPACING!]
[!CODE!]
[!NOCODE!]

    [!INCLUDE "Pwm_VersionCheck_Src.m"!]

    /* Variable indicate multicore feature enabled */
    [!VAR "MulticoreEnabled" = "0"!]

    [!IF "./PwmGeneral/PwmMulticoreEnabled = 'true'"!]
        [!VAR "MulticoreEnabled" = "1"!]
    [!ENDIF!]

    /* Variable storing number of maximum partitions using in configuration */
    [!VAR "numPartition" = "0"!]

    [!LOOP "as:modconf('Os')[1]/OsApplication/*"!]
        [!SELECT "node:ref(./OsApplicationCoreRef)"!]
            [!IF "$numPartition < node:value(./EcucCoreId)"!]
                [!VAR "numPartition" = "node:value(./EcucCoreId)"!]
            [!ENDIF!]
        [!ENDSELECT!]
    [!ENDLOOP!]

    [!VAR "numPartition" = "$numPartition + 1"!]

    [!VAR "numChannelsCfg" = "num:i(count(as:modconf('Pwm')[1]/PwmChannelConfigSet/PwmChannel/*))"!]

    [!VAR "EmiosIsUsed" = "'false'"!]
    /* Variable storing number of eMIOS Modules available on the current platform */
    [!IF "ecu:has('Pwm.EmiosSupported') and (ecu:get('Pwm.EmiosSupported') = 'true')"!]
        [!VAR "numEmiosModules" = "ecu:get('Pwm.EmiosInstanceCount')"!]
        [!VAR "numEmiosChannelsPerModule" = "ecu:get('Pwm.EmiosChannelCount')"!]
        [!VAR "numEmiosChannels" = "($numEmiosModules * $numEmiosChannelsPerModule)"!]
        [!VAR "EmiosPrescaler14Bit" = "'false'"!]
        [!IF "ecu:has('Pwm.EmiosChannelPrescaler.List') and text:contains(ecu:get('Pwm.EmiosChannelPrescaler.List'), 'EMIOS_PWM_IP_PRESCALER_14BIT')"!]
            [!VAR "EmiosPrescaler14Bit" = "'true'"!]
        [!ENDIF!]
        /* Check if Emios is used */
        [!IF "(node:exists(PwmChannelConfigSet/PwmEmios) and (count(PwmChannelConfigSet/PwmEmios/*) > 0)) = 'true'"!]
            [!VAR "EmiosIsUsed" = "'true'"!]
        [!ENDIF!]
    [!ENDIF!]
   
    /* Variable storing number of Etimer Modules available on the current platform */
    [!VAR "pwmEtimerSupported" = "'false'"!]
    [!VAR "EtimerIsUsed" = "'false'"!]
    [!IF "ecu:has('Pwm.EtimerSupported') and (ecu:get('Pwm.EtimerSupported') = 'true')"!]
        [!VAR "numEtimerModules" = "ecu:get('Pwm.EtimerInstanceCount')"!]
        [!VAR "numEtimerChannelsPerModule" = "ecu:get('Pwm.EtimerChannelCount')"!]
        [!VAR "numEtimerChannels" = "($numEtimerModules * $numEtimerChannelsPerModule)"!]
        [!VAR "pwmEtimerSupported" = "'true'"!]
        /* Check if Etimer is used */
        [!IF "(node:exists(PwmChannelConfigSet/PwmEtimer) and (count(PwmChannelConfigSet/PwmEtimer/*) > 0)) = 'true'"!]
            [!VAR "EtimerIsUsed" = "'true'"!]
        [!ENDIF!]
    [!ENDIF!]

    /* Variable storing number of Flexio Modules available on the current platform */
    [!VAR "pwmFlexioSupported" = "'false'"!]
    [!IF "ecu:has('Pwm.FlexioSupported') and (ecu:get('Pwm.FlexioSupported') = 'true')"!]
        [!VAR "numFlexioModules" = "ecu:get('Pwm.FlexioInstanceCount')"!]
        [!VAR "numFlexioChannelsPerModule" = "ecu:get('Pwm.FlexioChannelCount')"!]
        [!VAR "numFlexioChannels" = "($numFlexioModules * $numFlexioChannelsPerModule)"!]
        [!VAR "pwmFlexioSupported" = "'true'"!]
    [!ENDIF!]

     /* Variable storing number of Ftm Modules available on the current platform */
    [!VAR "pwmFtmSupported" = "'false'"!]
    [!IF "ecu:has('Pwm.FtmSupported') and (ecu:get('Pwm.FtmSupported') = 'true')"!]
        [!VAR "numModules" = "ecu:get('Pwm.FtmInstanceCount')"!]
        [!VAR "numChannelsPerModule" = "ecu:get('Pwm.FtmChannelsCount')"!]
        [!VAR "numChannels" = "($numModules * $numChannelsPerModule)"!]
        [!VAR "pwmFtmSupported" = "'true'"!]
    [!ENDIF!]
    
     /* Variable storing number of FlexPwm Modules available on the current platform */
    [!VAR "pwmFlexPwmSupported" = "'false'"!]
    [!VAR "FlexPwmIsUsed" = "'false'"!]
    [!IF "ecu:has('Pwm.FlexPwmAvailable') and (ecu:get('Pwm.FlexPwmAvailable') = 'true')"!]
        [!VAR "numModules" = "ecu:get('Pwm.FlexPwmHwModulesNum')"!]
        [!VAR "numSubModules" = "ecu:get('Pwm.FlexPwmHwSubModulesNum')"!]
        [!VAR "numChannelsPerSubModule" = "ecu:get('Pwm.FlexPwmHwChannelInSubModuleNum')"!]
        [!VAR "numFlexPwmSubModules" = "($numModules * $numSubModules)"!]
        [!VAR "numChannels" = "($numFlexPwmSubModules * $numChannelsPerSubModule)"!]
        [!VAR "pwmFlexPwmSupported" = "'true'"!]
        /* Check if FlexPwm is used */
        [!IF "(node:exists(PwmChannelConfigSet/FlexPwm) and (count(PwmChannelConfigSet/FlexPwm/*) > 0)) = 'true'"!]
            [!VAR "FlexPwmIsUsed" = "'true'"!]
        [!ENDIF!]
    [!ENDIF!]
    
    [!VAR "FlexPwmHwStartFrom0" = "'false'"!]
    [!IF "ecu:has('Pwm.FlexPwmHwModules.List') and text:contains(ecu:get('Pwm.FlexPwmHwModules.List'), 'FlexPwm_0')"!]
        [!VAR "FlexPwmHwStartFrom0" = "'true'"!]
    [!ENDIF!]
    

[!IF "ecu:has('Pwm.FtmSupported') and (ecu:get('Pwm.FtmSupported') = 'true')"!]
    /*====================================== Ftm ==================================================*/
    /** @brief  Macro used to generate the correspondence (translation) table between all FTM available
                channels and the indexes of channels in the array of PWM channels configured to use FTM */
    [!MACRO "GenerateFtmHwToLogicMap", "paramFtmModule", "partitionRefName"!]
    [!NOCODE!]
        [!VAR "OutVarHwToLogicArray" = "''"!]
        [!VAR "OutVarHwToLogicComment" = "''"!]

        /* Loop through all channels of FTM module received as parameter */
        [!FOR "MacCurModChannel" = "0" TO "$numChannelsPerModule - 1"!]
            /* Limit max number of configured channels to 255 */
            [!VAR "MacVarChTranslationIndex" = "255"!]

            /* Loop through all PWM channels configured to use FTM */
            [!LOOP "as:modconf('Pwm')[1]/PwmChannelConfigSet/PwmChannel/*"!]
                [!VAR "HasPartition" = "0"!]

                [!LOOP "./PwmChannelEcucPartitionRef/*"!]
                    [!VAR "PwmChannelEcucPartitionRefName" = "node:value(.)"!]

                    [!IF "$PwmChannelEcucPartitionRefName = $partitionRefName"!]
                        [!VAR "HasPartition" = "1"!]
                    [!ENDIF!]
                [!ENDLOOP!]

                [!IF "($MulticoreEnabled = 0) or (($MulticoreEnabled = 1) and ($HasPartition = 1))"!]
                    /* Get indexes of FTM Module and Channel of current looped PWM channel */
                    [!VAR "MacFtmModule"  = "substring-after(node:ref(PwmHwChannel)/../../PwmHwInstance,'Ftm_')"!]
                    [!VAR "MacFtmChannel" = "substring-after(node:ref(PwmHwChannel)/PwmFtmChId,'CH_')"!]

                    /* Check the match with the module received as parameter */
                    [!IF "$MacFtmModule = $paramFtmModule"!]

                        /* Check the match with the channel loop variable */
                        [!IF "num:i($MacFtmChannel) = $MacCurModChannel"!]
                            /* Keep the index of the channel in the array of configured PWM channels */
                            [!VAR "MacVarChTranslationIndex" = "PwmChannelId"!]
                        [!ENDIF!]

                    [!ENDIF!]
                [!ENDIF!]
            [!ENDLOOP!]

            /* Build the comment for the current Module */
            [!VAR "OutVarHwToLogicComment" = "concat('/* Index of channels 0 - ', num:i($numChannelsPerModule) - 1, ' of FTM_', num:i($paramFtmModule), ' in the array of logic PWM channels */')"!]

            /* If no configured PWM channel is using the current FTM channel in Module */
            [!IF "$MacVarChTranslationIndex = 255"!]
                [!VAR "OutVarHwToLogicArray" = "concat($OutVarHwToLogicArray, '(Pwm_ChannelType)255')"!]
            [!ELSE!]
                [!VAR "OutVarHwToLogicArray" = "concat($OutVarHwToLogicArray, '(Pwm_ChannelType)', $MacVarChTranslationIndex)"!]
            [!ENDIF!]

            [!IF "$MacCurModChannel < $numChannelsPerModule - 1"!]
                [!VAR "OutVarHwToLogicArray" = "concat($OutVarHwToLogicArray, ', ')"!]
            [!ENDIF!]
        [!ENDFOR!]

    [!ENDNOCODE!]
    [!ENDMACRO!]
[!ENDIF!]

[!IF "ecu:has('Pwm.FlexPwmAvailable') and (ecu:get('Pwm.FlexPwmAvailable') = 'true')"!]
    /*====================================== FlexPwm ==================================================*/
        /** @brief  Macro used to generate the correspondence (translation) table between all FlexPWM available
                channels and the indexes of channels in the array of PWM channels configured to use FlexPWM */
    [!MACRO "GenerateFlexPwmHwToLogicMap", "paramIdxSubModule"!]
    [!NOCODE!]
        [!VAR "OutVarHwToLogicArray" = "''"!]
        [!VAR "OutVarHwToLogicComment" = "''"!]

        /* Loop through all channels of FlexPWM submodule received as parameter */
        [!FOR "MacCurSubmodChannel" = "0" TO "2"!]

            /* Limit max number of configured channels to 255 */
            [!VAR "MacVarChTranslationIndex" = "255"!]

            /* Loop through all PWM channels configured to use FlexPWM */
            [!LOOP "as:modconf('Pwm')[1]/PwmChannelConfigSet/PwmChannel/*"!]
                [!IF "contains(PwmHwChannel,'FlexPwm')"!]

                    /* Get indexes of FlexPWM module, submodule and channel of current looped PWM channel */
                    [!VAR "MacIdxFlexModule"    = "num:i(substring-after(node:ref(PwmHwChannel)/../../../../FlexPwmModule, '_'))"!]
                    [!VAR "MacIdxFlexSubModule" = "num:i(substring-after(node:ref(PwmHwChannel)/../../FlexPwmSubModule, '_'))"!]
                    [!VAR "MacIdxFlexChannel"   = "translate(substring-after(node:ref(PwmHwChannel)/FlexPwmChannel, 'FLEXPWM_IP_PWM'),'XABC','0121')"!]

                    /* Compute the submodule global ID, unique across all submodules */
                    [!IF "$FlexPwmHwStartFrom0 = 'true'"!]
                        [!VAR "MacIdxSubModuleGlobal" = "num:i(num:i($MacIdxFlexSubModule) + (num:i(4 *(num:i($MacIdxFlexModule)))))"!]
                    [!ELSE!]
                        [!VAR "MacIdxSubModuleGlobal" = "num:i(num:i($MacIdxFlexSubModule) + (num:i(4 *(num:i($MacIdxFlexModule) - 1))))"!]
                    [!ENDIF!]

                    /* Check the match with the submodule ID received as parameter */
                    [!IF "$MacIdxSubModuleGlobal = $paramIdxSubModule"!]

                        /* Check the match with the channel loop var */
                        [!IF "num:i($MacIdxFlexChannel) = $MacCurSubmodChannel"!]

                            /* Keep the index of the channel in the array of configured PWM channels */
                            [!VAR "MacVarChTranslationIndex" = "PwmChannelId"!]
                        [!ENDIF!]
                    [!ENDIF!]
                [!ENDIF!]
            [!ENDLOOP!]
            
            /* Build the comment for the current submodule */
            [!VAR "OutVarHwToLogicComment" = "concat('/* Index of channel X, A and B of sub-module ', num:i($paramIdxSubModule mod 4), ' of FlexPWM ', num:i($paramIdxSubModule div 4), ' in the array of logic PWM channels */')"!]

            /* If no configured PWM channel is using the current FlexPWM channel in submodule */
            [!IF "$MacVarChTranslationIndex = 255"!]
                [!VAR "OutVarHwToLogicArray" = "concat($OutVarHwToLogicArray, '(Pwm_ChannelType)255')"!]
            [!ELSE!]
                [!VAR "OutVarHwToLogicArray" = "concat($OutVarHwToLogicArray, '(Pwm_ChannelType)', $MacVarChTranslationIndex)"!]
            [!ENDIF!]

            [!IF "$MacCurSubmodChannel < 2"!]
                [!VAR "OutVarHwToLogicArray" = "concat($OutVarHwToLogicArray, ', ')"!]
            [!ENDIF!]
        [!ENDFOR!]

    [!ENDNOCODE!]
    [!ENDMACRO!]
[!ENDIF!]

/*====================================== eMIOS ==================================================*/

    /* Function to generate master bus period in ticks if input value is in seconds */
    [!MACRO "GenerateEmiosMasterbusPeriodInTicks", "MotorFreq"!]
    [!NOCODE!]
        [!VAR "MasterPrescalerVal" = "substring-after(MasterBusPrescaler,'DIV_')"!]
        [!VAR "MasterPeriod" = "MasterBusPeriodDefault"!]
        [!VAR "MasterPeriodMax" = "16777215"!]

        [!IF "MasterBusPeriodInTicks"!]
            [!VAR "OutMasterPeriodTicks" = "$MasterPeriod"!]
        [!ELSE!]
            [!VAR "OutMasterPeriodTicks" = "$MasterPeriod * ($MotorFreq div $MasterPrescalerVal)"!]
        [!ENDIF!]

        [!IF "num:i($OutMasterPeriodTicks) < 1"!]
            [!ERROR!]
The configured period/ticks for master bus [!"PwmEmiosMasterBus"!] on [!"../../PwmEmiosModule"!] in channel config set [!"name(../../../../.)"!] is smaller than 1 tick: [!"$OutMasterPeriodTicks"!]
The plugin performs the conversion from Period to ticks if requested.
To solve this problem change the configured Period/ticks or change the Pwm Channel clock tree settings.
            [!ENDERROR!]
        [!ENDIF!]

        [!IF "num:i($OutMasterPeriodTicks) > $MasterPeriodMax"!]
            [!ERROR!]
The configured period/ticks for master bus [!"PwmEmiosMasterBus"!] on [!"../../PwmEmiosModule"!] in channel config set [!"name(../../../../.)"!] is larger than [!"$MasterPeriodMax"!] ticks: [!"$MasterPeriod"!]
The plugin performs the conversion from Period to ticks if requested.
To solve this problem change the configured Period/ticks or change the Pwm Channel clock tree settings.
            [!ENDERROR!]
        [!ENDIF!]

    [!ENDNOCODE!]
    [!ENDMACRO!]

    /* Macro used to validate the offset of channel that using PWM_FIXED_PERIOD class */
    [!MACRO "ValidateOffsetPwmFixedPeriod"!]
    [!NOCODE!]
        [!LOOP "PwmChannel/*"!]
            [!IF "contains(PwmHwIP,'Emios')"!]
                [!IF "node:exists('PwmChannelClass')"!]
                    [!IF "((contains(node:ref(PwmEmiosChannel)/PwmModeSelect,'OPWMB')) or (contains(node:ref(PwmEmiosChannel)/PwmModeSelect,'OPWMT')) or (contains(node:ref(PwmEmiosChannel)/PwmModeSelect,'OPWM')))"!]
                        [!IF "not((contains(node:ref(PwmEmiosChannel)/PwmModeSelect,'OPWMCB')) or (contains(node:ref(PwmEmiosChannel)/PwmModeSelect,'OPWMC')))"!]
                            [!VAR "PwmChannelName" = "node:name(.)"!]
                            [!VAR "ChannelClass" = "PwmChannelClass"!]

                            [!IF "($ChannelClass = 'PWM_FIXED_PERIOD')"!]
                                [!VAR "Offset" = "node:ref(PwmEmiosChannel)/PwmOffset"!]

                                [!IF "($Offset != 0)"!]
                                    [!ERROR!]
For PwmChannel_[!"$PwmChannelName"!] use PWM_FIXED_PERIOD class, so the offset phase shift must be equal 0
                                    [!ENDERROR!]
                                [!ENDIF!]
                            [!ENDIF!]
                        [!ENDIF!]
                    [!ENDIF!]
                [!ENDIF!]
            [!ENDIF!]
        [!ENDLOOP!]

    [!ENDNOCODE!]
    [!ENDMACRO!]

[!IF "ecu:has('Pwm.EmiosSupported') and (ecu:get('Pwm.EmiosSupported') = 'true')"!]
    /* Macro used to validate the period value when using the external counter bus */
    [!MACRO "ValidatePeriodMasterBus"!]
    [!IF "node:exists(as:modconf("Resource")[1]/ResourceGeneral/ResourceSubderivative)"!][!//
        [!VAR "DerivativeName" = "text:toupper(substring-before(as:modconf("Resource")[1]/ResourceGeneral/ResourceSubderivative,'_'))"!]
    [!ENDIF!][!//
    [!NOCODE!]
        [!LOOP "PwmChannel/*"!]
            [!IF "contains(PwmHwChannel,'Emios')"!]
                [!VAR "PwmChannelName" = "node:name(.)"!]
                [!VAR "pwmPeriod" = "num:i(PwmPeriodDefault)"!]
                [!IF "as:modconf('Mcl')[1]/MclGeneral/MclEmiosCommon/MclEnableEmiosCommon = 'false'"!]
                    [!ERROR!]
Please enable "Enable Emmios Common Support" in MclGeneral/MclEmiosCommon/MclEnableEmiosCommon.
                    [!ENDERROR!]
                [!ENDIF!]
                [!IF "not(contains(node:ref(PwmHwChannel)/EmiosChCounterBus,'EMIOS_PWM_IP_BUS_INTERNAL'))"!]
                    [!VAR "NumCount" = "0"!]
                    [!VAR "EmiosCh" = "substring-after(node:ref(PwmHwChannel)/EmiosChId,'CH_')"!]
                    [!VAR "EmiosBus" = "substring-after(node:ref(PwmHwChannel)/EmiosChCounterBus,'EMIOS_PWM_IP_BUS_')"!]
                    [!VAR "EmiosMode" = "node:value(node:ref(PwmHwChannel)/EmiosChMode)"!]
                    [!VAR "EmiosInstance" = "substring-after(node:ref(PwmHwChannel)/../../PwmHwInstance,'Emios_')"!]

                    [!IF "$EmiosPrescaler14Bit = 'true'"!]
                        [!VAR "EmiosPwmPre" = "node:value(node:ref(PwmHwChannel)/EmiosChPrescaler)"!]
                        [!VAR "EmiosPwmAltPre" = "node:value(node:ref(PwmHwChannel)/EmiosChPrescalerAlternate)"!]
                    [!ELSE!]
                        [!VAR "EmiosPwmPre" = "substring-after(node:ref(PwmHwChannel)/EmiosChPrescaler,'EMIOS_PWM_IP_CLOCK_DIV_')"!]
                        [!VAR "EmiosPwmAltPre" = "substring-after(node:ref(PwmHwChannel)/EmiosChPrescalerAlternate,'EMIOS_PWM_IP_CLOCK_DIV_')"!]
                    [!ENDIF!]
                    [!VAR "EmiosDeadTime" = "node:value(node:ref(PwmHwChannel)/EmiosChDeadtime)"!]
                    [!VAR "EmiosMaster" = "30"!]
                    [!IF "($EmiosBus = 'BCDE')"!]
                        [!IF "($EmiosCh < 8)"!]
                            [!VAR "EmiosMaster" = "0"!]
                        [!ELSEIF "($EmiosCh < 16)"!]
                            [!VAR "EmiosMaster" = "8"!]
                        [!ELSEIF "($EmiosCh < 24)"!]
                            [!VAR "EmiosMaster" = "16"!]
                        [!ELSE!]
                            [!VAR "EmiosMaster" = "24"!]
                        [!ENDIF!]
                    [!ELSEIF "($EmiosBus = 'A')"!]
                        [!VAR "EmiosMaster" = "23"!]
                    [!ELSE!]
                        [!VAR "EmiosMaster" = "22"!]
                    [!ENDIF!]
                    [!LOOP "as:modconf('Mcl')[1]/MclConfig/EmiosCommon/*"!]
                        [!VAR "EmiosMclIns" = "substring-after(EmiosMclInstances,'EMIOS_')"!]
                        [!IF "$EmiosInstance = $EmiosMclIns"!]
                            [!VAR "NumMasterBus" = "0"!]
                            [!LOOP "EmiosMclMasterBus/*"!]
                                [!VAR "NumMasterBus" = "$NumMasterBus + 1"!]
                                [!VAR "EmiosMcl" = "node:name(.)"!]
                                [!VAR "EmiosMclMode" = "node:value(./EmiosMclMasterBusModeType)"!]
                                [!VAR "EmiosMclBusNumber" = "num:i(text:split(node:value(./EmiosMclMasterBusNumber), 'CH_')[2])"!]
                                [!VAR "EmiosMclMasterBusPre" = "substring-after(node:value(./EmiosMclMasterBusPrescaler), 'DIV_')"!]
                                [!VAR "EmiosMclMasterBusAltPre" = "substring-after(node:value(./EmiosMclMasterBusAltPrescaler), 'DIV_')"!]
                                [!IF "num:i($EmiosMaster) = $EmiosMclBusNumber"!]
                                    [!VAR "EmiosMclPeriod" = "num:i(EmiosMclDefaultPeriod)"!]
                                    [!VAR "NumCount" = "1"!]
                                    [!IF "contains($EmiosMode, 'OPWMT')"!]
                                        [!IF "$pwmPeriod != $EmiosMclPeriod"!]
                                            [!ERROR!]
The channel [!"$PwmChannelName"!] in OPWMT mode used external counter bus [!"$EmiosBus"!] but the Pwm period is ([!"$pwmPeriod"!] ticks) not equal the Emios period ([!"$EmiosMclPeriod"!] ticks) in [!"$EmiosMcl"!], Please update!
                                            [!ENDERROR!]
                                        [!ENDIF!]
                                        [!IF "not(contains($EmiosMclMode,'UP_COUNTER'))"!]
                                            [!ERROR!]
The channel [!"$PwmChannelName"!] in OPWMT mode used external counter bus [!"$EmiosBus"!],only use MC_UP_COUNTER or MCB_UP_COUNTER mode in MCL !
                                            [!ENDERROR!]
                                        [!ENDIF!]
                                    [!ELSEIF "contains($EmiosMode, 'OPWMB')"!]
                                        [!IF "$pwmPeriod != $EmiosMclPeriod"!]
                                            [!ERROR!]
The channel [!"$PwmChannelName"!] in OPWMB mode used external counter bus [!"$EmiosBus"!] but the Pwm period is ([!"$pwmPeriod"!] ticks) not equal the Emios period ([!"$EmiosMclPeriod"!] ticks) in [!"$EmiosMcl"!], Please update!
                                            [!ENDERROR!]
                                        [!ENDIF!]
                                        [!IF "not(contains($EmiosMclMode,'MCB_UP_COUNTER'))"!]
                                            [!ERROR!]
The channel [!"$PwmChannelName"!] in OPWMB mode used external counter bus [!"$EmiosBus"!],only use MCB_UP_COUNTER mode in MCL !
                                            [!ENDERROR!]
                                        [!ENDIF!]
                                    [!ELSEIF "contains($EmiosMode, 'OPWMCB')"!]
                                        [!VAR "periodMcl" = "num:i(1 + ($pwmPeriod div 2))"!]
                                        [!IF "$periodMcl != $EmiosMclPeriod"!]
                                            [!ERROR!]
The channel [!"$PwmChannelName"!] in OPWMCB mode used external counter bus [!"$EmiosBus"!], Please update default period is [!"$periodMcl"!] in (Emios_[!"$EmiosInstance"!]_CH_[!"num:i($EmiosMaster)"!]) Emios Mcl configuration !
                                            [!ENDERROR!]
                                        [!ENDIF!]
                                        [!IF "not(contains($EmiosMclMode,'MCB_UP_DOWN_COUNTER'))"!]
                                            [!ERROR!]
The channel [!"$PwmChannelName"!] in OPWMCB mode used external counter bus [!"$EmiosBus"!],only use MCB_UP_DOWN_COUNTER mode in MCL !
                                            [!ENDERROR!]
                                        [!ENDIF!]
                                        [!IF "(contains($DerivativeName,'S32K344')) or (contains($DerivativeName,'S32K324')) or (contains($DerivativeName,'S32K314'))"!]
                                            [!IF "$EmiosDeadTime != 0"!]
                                                [!IF "$EmiosPwmPre != $EmiosMclMasterBusPre"!]
                                                    [!ERROR!]
[ERR050575] The channel [!"$PwmChannelName"!] in OPWMCB mode used external counter bus [!"$EmiosBus"!], Channel configured in OPWMCB mode with lead or trail dead time insertion features enabled must have channel prescaler equal to the timebase channel prescaler configured in MCB mode in MCL.
                                                    [!ENDERROR!]
                                                [!ENDIF!]
                                            [!ENDIF!]
                                        [!ENDIF!]
                                    [!ELSEIF "contains($EmiosMode, 'OPWMC')"!]
                                        [!VAR "periodMcl" = "num:i(1 + ($pwmPeriod div 2))"!]
                                        [!IF "$periodMcl != $EmiosMclPeriod"!]
                                            [!ERROR!]
The channel [!"$PwmChannelName"!] in OPWMC mode used external counter bus [!"$EmiosBus"!], Please update default period is [!"$periodMcl"!] in (Emios_[!"$EmiosInstance"!]_CH_[!"num:i($EmiosMaster)"!]) Emios Mcl configuration !
                                            [!ENDERROR!]
                                        [!ENDIF!]
                                        [!IF "not(contains($EmiosMclMode,'MC_UP_DOWN_COUNTER'))"!]
                                            [!ERROR!]
The channel [!"$PwmChannelName"!] in OPWMC mode used external counter bus [!"$EmiosBus"!],only use MC_UP_DOWN_COUNTER mode in MCL !
                                            [!ENDERROR!]
                                        [!ENDIF!]                                        
                                    [!ELSEIF "contains($EmiosMode, 'OPWM')"!]
                                        [!IF "$pwmPeriod != $EmiosMclPeriod"!]
                                            [!ERROR!]
The channel [!"$PwmChannelName"!] in OPWM mode used external counter bus [!"$EmiosBus"!] but the Pwm period is ([!"$pwmPeriod"!] ticks) not equal the Emios period ([!"$EmiosMclPeriod"!] ticks) in [!"$EmiosMcl"!], Please update!
                                            [!ENDERROR!]
                                        [!ENDIF!]
                                        [!IF "not(contains($EmiosMclMode,'MC_UP_COUNTER'))"!]
                                            [!ERROR!]
The channel [!"$PwmChannelName"!] in OPWM mode used external counter bus [!"$EmiosBus"!],only use MC_UP_COUNTER mode in MCL !
                                            [!ENDERROR!]
                                        [!ENDIF!]                                     
                                    [!ELSE!]
                                        [!IF "$pwmPeriod > $EmiosMclPeriod"!]
                                            [!ERROR!]
The channel [!"$PwmChannelName"!] in DAOC mode used external counter bus [!"$EmiosBus"!] but the Pwm period is ([!"$pwmPeriod"!] ticks) is greater than the Emios Mcl period ([!"$EmiosMclPeriod"!] ticks) in [!"$EmiosMcl"!], Please update to Pwm period is less than or equal Emios Mcl period!
                                            [!ENDERROR!]
                                        [!ENDIF!]
                                        [!IF "not(contains($EmiosMclMode,'MCB_UP_COUNTER'))"!]
                                            [!ERROR!]
The channel [!"$PwmChannelName"!] in DAOC mode used external counter bus [!"$EmiosBus"!],only use MCB_UP_COUNTER mode in MCL !
                                            [!ENDERROR!]
                                        [!ENDIF!]
                                    [!ENDIF!]
                                [!ENDIF!]
                            [!ENDLOOP!]

                            [!IF "$NumMasterBus = 0"!]
                                [!ERROR!]
The Pwm channel used external counter bus, But Emios master bus was not configured in MCL.
                                [!ENDERROR!]
                            [!ENDIF!]
                        [!ENDIF!]
                    [!ENDLOOP!]
                    [!IF "$NumCount = 0"!]
                        [!ERROR!]
The channel [!"$PwmChannelName"!] used external counter bus [!"$EmiosBus"!], Please configure this counter bus (Emios_[!"$EmiosInstance"!]_CH_[!"num:i($EmiosMaster)"!]) in MCL!
                        [!ENDERROR!]
                    [!ENDIF!]
                [!ENDIF!]
            [!ENDIF!]
        [!ENDLOOP!]

    [!ENDNOCODE!]
    [!ENDMACRO!]

    /* Macro used to generate the correspondence (translation) table between all Emios available
    channels and the indexes of channels in the array of PWM channels configured to use Emios */
    [!MACRO "GenerateEmiosHwToLogicMap", "paramEmiosModule"!]
    [!NOCODE!]
        [!CODE!]
        /*---------------------eMIOS_[!"num:i($paramEmiosModule)"!]---------------------------*/
        [!ENDCODE!]

        [!FOR "MacCurModChannel" = "0" TO "$numEmiosChannelsPerModule - 1"!]

            /* Limit max number of configured channels to 255 */
            [!VAR "MacVarChTranslationIndex" = "255"!]

            /* Loop through all PWM channels configured to use eMIOS IP */
            [!LOOP "as:modconf('Pwm')[1]/PwmChannelConfigSet/PwmChannel/*"!]
                [!IF "contains(PwmHwChannel,'Emios')"!]
                    /* Get indexes of EMIOS Module and Channel of current looped PWM channel */
                    [!VAR "EmiosCh" = "substring-after(node:ref(PwmHwChannel)/EmiosChId,'CH_')"!]
                    [!VAR "EmiosInstance" = "substring-after(node:ref(PwmHwChannel)/../../PwmHwInstance,'Emios_')"!]

                    /* Check the match with the module id received as parameter */
                    [!IF "num:i($EmiosInstance) = num:i($paramEmiosModule)"!]

                        /* Check the match with the channel loop var */
                        [!IF "num:i($EmiosCh) = $MacCurModChannel"!]
                            /* Keep the index of the channel in the array of configured PWM channels */
                            [!VAR "MacVarChTranslationIndex" = "PwmChannelId"!]
                        [!ENDIF!]
                    [!ENDIF!]
                [!ENDIF!]
            [!ENDLOOP!]

            [!CODE!]
        (Pwm_ChannelType)[!"num:i($MacVarChTranslationIndex)"!][!//
            [!ENDCODE!]

            [!IF "($MacCurModChannel < $numEmiosChannelsPerModule - 1) or ($paramEmiosModule < $numEmiosModules - 1) or ($pwmFlexioSupported = 'true') or ($pwmEtimerSupported = 'true') or ($pwmFlexPwmSupported = 'true')"!]
                [!CODE!],[!//
                [!ENDCODE!]
            [!ENDIF!]

            [!IF "$MacVarChTranslationIndex < 255"!]
                [!CODE!]
            /* Emios_[!"num:i($paramEmiosModule)"!]_[!"num:i($MacCurModChannel)"!] */
                [!ENDCODE!]
            [!ELSE!]
                [!CODE!]
            /* Emios_[!"num:i($paramEmiosModule)"!]_[!"num:i($MacCurModChannel)"!] unused */
                [!ENDCODE!]
            [!ENDIF!]
        [!ENDFOR!]

    [!ENDNOCODE!]
    [!ENDMACRO!]
[!ENDIF!]

/*====================================== Etimer ==================================================*/
[!IF "ecu:has('Pwm.EtimerSupported') and (ecu:get('Pwm.EtimerSupported') = 'true')"!]
    /* Macro used to generate the correspondence (translation) table between all Etimer available
    channels and the indexes of channels in the array of PWM channels configured to use Etimer */
    [!MACRO "GenerateEtimerHwToLogicMap", "paramEtimerModule"!]
    [!NOCODE!]
        [!CODE!]
        /*---------------------Etimer_[!"num:i($paramEtimerModule)"!]---------------------------*/
        [!ENDCODE!]

        [!FOR "MacCurModChannel" = "0" TO "$numEtimerChannelsPerModule - 1"!]

            /* Limit max number of configured channels to 255 */
            [!VAR "MacVarChTranslationIndex" = "255"!]

            /* Loop through all PWM channels configured to use Etimer IP */
            [!LOOP "as:modconf('Pwm')[1]/PwmChannelConfigSet/PwmChannel/*"!]
                [!IF "contains(PwmHwChannel,'Etimer')"!]
                    /* Get indexes of Etimer Module and Channel of current looped PWM channel */
                    [!VAR "EtimerCh" = "substring-after(node:ref(PwmHwChannel)/EtimerChId,'CH_')"!]
                    [!VAR "EtimerInstance" = "substring-after(node:ref(PwmHwChannel)/../../PwmHwInstance,'Etimer_')"!]

                    /* Check the match with the module id received as parameter */
                    [!IF "num:i($EtimerInstance) = num:i($paramEtimerModule)"!]

                        /* Check the match with the channel loop var */
                        [!IF "num:i($EtimerCh) = $MacCurModChannel"!]
                            /* Keep the index of the channel in the array of configured PWM channels */
                            [!VAR "MacVarChTranslationIndex" = "PwmChannelId"!]
                        [!ENDIF!]
                    [!ENDIF!]
                [!ENDIF!]
            [!ENDLOOP!]

            [!CODE!]
        (Pwm_ChannelType)[!"num:i($MacVarChTranslationIndex)"!][!//
            [!ENDCODE!]

            [!IF "($MacCurModChannel < $numEtimerChannelsPerModule - 1) or ($paramEtimerModule < $numEtimerModules - 1) or ($pwmFlexPwmSupported = 'true')"!]
                [!CODE!],[!//
                [!ENDCODE!]
            [!ENDIF!]

            [!IF "$MacVarChTranslationIndex < 255"!]
                [!CODE!]
            /* Etimer_[!"num:i($paramEtimerModule)"!]_[!"num:i($MacCurModChannel)"!] */
                [!ENDCODE!]
            [!ELSE!]
                [!CODE!]
            /* Etimer_[!"num:i($paramEtimerModule)"!]_[!"num:i($MacCurModChannel)"!] unused */
                [!ENDCODE!]
            [!ENDIF!]
        [!ENDFOR!]

    [!ENDNOCODE!]
    [!ENDMACRO!]
[!ENDIF!]

/*====================================== Flexio ==================================================*/
[!IF "ecu:has('Pwm.FlexioSupported') and (ecu:get('Pwm.FlexioSupported') = 'true')"!]

    /* Macro used to generate the correspondence (translation) table between all Flexio available
    channels and the indexes of channels in the array of PWM channels configured to use Flexio */
    [!MACRO "GenerateFlexioHwToLogicMap", "paramFlexioModule"!]
    [!NOCODE!]
        [!CODE!]
        /*---------------------Flexio_[!"num:i($paramFlexioModule)"!]---------------------------*/
        [!ENDCODE!]

        [!FOR "MacCurModChannel" = "0" TO "$numFlexioChannelsPerModule - 1"!]

            /* Limit max number of configured channels to 255 */
            [!VAR "MacVarChTranslationIndex" = "255"!]

            /* Loop through all PWM channels configured to use Flexio IP */
            [!LOOP "as:modconf('Pwm')[1]/PwmChannelConfigSet/PwmChannel/*"!]
                [!IF "contains(PwmHwChannel,'Flexio')"!]
                    /* Get indexes of FLEXIO Module and Channel of current looped PWM channel */
                    [!VAR "FlexioCh" = "substring-after(node:ref(PwmHwChannel)/FlexioChId,'CH_')"!]
                    [!VAR "FlexioInstance" = "substring-after(node:ref(PwmHwChannel)/../../PwmHwInstance,'Flexio_')"!]

                    /* Check the match with the module id received as parameter */
                    [!IF "num:i($FlexioInstance) = num:i($paramFlexioModule)"!]

                        /* Check the match with the channel loop var */
                        [!IF "num:i($FlexioCh) = $MacCurModChannel"!]
                            /* Keep the index of the channel in the array of configured PWM channels */
                            [!VAR "MacVarChTranslationIndex" = "PwmChannelId"!]
                        [!ENDIF!]
                    [!ENDIF!]
                [!ENDIF!]
            [!ENDLOOP!]

            [!CODE!]
        (Pwm_ChannelType)[!"num:i($MacVarChTranslationIndex)"!][!//
            [!ENDCODE!]

            [!IF "($MacCurModChannel < $numFlexioChannelsPerModule - 1) or ($paramFlexioModule < $numFlexioModules - 1) or ($pwmEtimerSupported = 'true') or ($pwmFlexPwmSupported = 'true')"!]
                [!CODE!],[!//
                [!ENDCODE!]
            [!ENDIF!]

            [!IF "$MacVarChTranslationIndex < 255"!]
                [!CODE!]
            /* Flexio_[!"num:i($paramFlexioModule)"!]_[!"num:i($MacCurModChannel)"!] */
                [!ENDCODE!]
            [!ELSE!]
                [!CODE!]
            /* Flexio_[!"num:i($paramFlexioModule)"!]_[!"num:i($MacCurModChannel)"!] unused */
                [!ENDCODE!]
            [!ENDIF!]
        [!ENDFOR!]

    [!ENDNOCODE!]
    [!ENDMACRO!]
[!ENDIF!]

/*===================================== GENERAL ==================================================*/

    /* Macro used to count and validate the configured PWM channels */
    [!MACRO "ValidatePwmConfiguration"!]
    [!NOCODE!]
        [!VAR "OutNumPwmChannels" = "num:i(count(PwmChannel/*))"!]
        [!VAR "OutNumPwmChannelsUsingEmios" = "0"!]

        [!VAR "MacOuterLoopCounter" = "0"!]

        [!LOOP "PwmChannel/*"!]
            [!VAR "MacOuterLoopCounter" = "$MacOuterLoopCounter + 1"!]

            /* Check if there are no eMIOS hardware channels referenced multiple times by same logic channels */
            [!IF "contains(PwmHwIP,'Emios')"!]
                [!VAR "MacInnerLoopCounter" = "0"!]
                [!VAR "MacMatchcounter" = "0"!]
                [!VAR "MacOuterEmiosChannelPath" = "node:path(node:ref(./PwmEmiosChannel))"!]

                [!LOOP "../../../*[@index]/PwmChannel/*"!]
                    [!IF "contains(PwmHwIP,'Emios')"!]
                        [!VAR "MacInnerLoopCounter" = "$MacInnerLoopCounter + 1"!]

                        [!IF "$MacOuterLoopCounter >= $MacInnerLoopCounter"!]
                            [!VAR "MacInnerEmiosChannelPath" = "node:path(node:ref(./PwmEmiosChannel))"!]

                            [!IF "($MacInnerEmiosChannelPath = $MacOuterEmiosChannelPath)"!]
                                [!VAR "MacMatchcounter" = "$MacMatchcounter + 1"!]
                            [!ENDIF!]
                        [!ENDIF!]
                    [!ENDIF!]
                [!ENDLOOP!]

                [!IF "$MacMatchcounter > 1"!]
                    [!ERROR!]
eMIOS channel [!"$MacInnerEmiosChannelPath"!] is referenced by more than one logic PWM channel.
                    [!ENDERROR!]
                [!ENDIF!]
            [!ENDIF!]

            /* Update variables storing number of PWM channels using eMIOS IP */
            [!IF "contains(PwmHwIP,'Emios')"!]
                [!VAR "OutNumPwmChannelsUsingEmios" = "$OutNumPwmChannelsUsingEmios + 1"!]
            [!ENDIF!]

        [!ENDLOOP!]

    [!ENDNOCODE!]
    [!ENDMACRO!]

[!ENDNOCODE!]
/*==================================================================================================
*   Project              : RTD AUTOSAR 4.7
*   Platform             : CORTEXM
*   Peripheral           : Emios Flexio FlexPwm
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
*   @file       Pwm_PBcfg.c
*
*   @addtogroup pwm_driver Pwm Driver
*   @{
*/

#ifdef __cplusplus
extern "C"{
#endif

[!SELECT "PwmChannelConfigSet"!]
[!NOCODE!]
    [!CALL "ValidatePwmConfiguration"!]

    [!CALL "ValidateOffsetPwmFixedPeriod"!]

[!IF "ecu:has('Pwm.EmiosSupported') and (ecu:get('Pwm.EmiosSupported') = 'true')"!]
    [!CALL "ValidatePeriodMasterBus"!]
[!ENDIF!]

    [!VAR "PwmChannels" = "num:i(count(PwmChannel/*))"!]

[!ENDNOCODE!]

/*==================================================================================================
*                                          INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Std_Types.h"
#include "Pwm.h"

/*==================================================================================================
*                                 SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define PWM[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PB_CFG_VENDOR_ID_C                       43
#define PWM[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PB_CFG_MODULE_ID_C                       121
#define PWM[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PB_CFG_AR_RELEASE_MAJOR_VERSION_C        4
#define PWM[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PB_CFG_AR_RELEASE_MINOR_VERSION_C        7
#define PWM[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PB_CFG_AR_RELEASE_REVISION_VERSION_C     0
#define PWM[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PB_CFG_SW_MAJOR_VERSION_C                3
#define PWM[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PB_CFG_SW_MINOR_VERSION_C                0
#define PWM[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PB_CFG_SW_PATCH_VERSION_C                0

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if source file and Std_Types.h are of the same AUTOSAR version */
    #if ((PWM[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PB_CFG_AR_RELEASE_MAJOR_VERSION_C != STD_AR_RELEASE_MAJOR_VERSION) || \
         (PWM[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PB_CFG_AR_RELEASE_MINOR_VERSION_C != STD_AR_RELEASE_MINOR_VERSION))
        #error "AUTOSAR version numbers of Pwm[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg.c and Std_Types.h are different."
    #endif
#endif

#if (PWM[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PB_CFG_VENDOR_ID_C != PWM_VENDOR_ID)
    #error "Pwm[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg.c and Pwm.h have different vendor ids"
#endif

#if ((PWM[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PB_CFG_AR_RELEASE_MAJOR_VERSION_C    != PWM_AR_RELEASE_MAJOR_VERSION) || \
     (PWM[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PB_CFG_AR_RELEASE_MINOR_VERSION_C    != PWM_AR_RELEASE_MINOR_VERSION) || \
     (PWM[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PB_CFG_AR_RELEASE_REVISION_VERSION_C != PWM_AR_RELEASE_REVISION_VERSION))
    #error "AUTOSAR version numbers of Pwm[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg.c and Pwm.h are different"
#endif

#if ((PWM[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PB_CFG_SW_MAJOR_VERSION_C != PWM_SW_MAJOR_VERSION) || \
     (PWM[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PB_CFG_SW_MINOR_VERSION_C != PWM_SW_MINOR_VERSION) || \
     (PWM[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PB_CFG_SW_PATCH_VERSION_C != PWM_SW_PATCH_VERSION))
    #error "Software version numbers of Pwm[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg.c and Pwm.h are different"
#endif

/*==================================================================================================
*                           LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
*                                          LOCAL MACROS
==================================================================================================*/

/*==================================================================================================
*                                         LOCAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                         LOCAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                        GLOBAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                        GLOBAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                    LOCAL FUNCTION PROTOTYPES
==================================================================================================*/
#define PWM_START_SEC_CODE
#include "Pwm_MemMap.h"

[!NOCODE!]
[!INCLUDE "Pwm_NotifyCheck_Src.m"!]
[!IF "../PwmGeneral/PwmNotificationSupported"!]
[!CALL "GeneratePwmNotifications"!]
[!ENDIF!]
[!ENDNOCODE!]

#define PWM_STOP_SEC_CODE
#include "Pwm_MemMap.h"

/*==================================================================================================
*                                        GLOBAL VARIABLES
==================================================================================================*/
#define PWM_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Pwm_MemMap.h"

/*============================== Channels configuration ===================================*/
[!IF "$MulticoreEnabled = 1"!]
    [!LOOP "as:modconf('Pwm')[1]/PwmGeneral/PwmEcucPartitionRef/*"!]
        [!NOCODE!]
            [!VAR "PartitionIndex" = "@index"!]

            [!VAR "PwmEcucPartitionRefName" = "node:value(.)"!]
            [!VAR "PwmEcucPartitionShortName" = "substring-after($PwmEcucPartitionRefName, '/')"!]
            [!VAR "PwmEcucPartitionShortName" = "substring-after($PwmEcucPartitionShortName, '/')"!]
            [!VAR "PwmEcucPartitionShortName" = "substring-after($PwmEcucPartitionShortName, '/')"!]
            [!VAR "PwmEcucPartitionShortName" = "substring-after($PwmEcucPartitionShortName, '/')"!]

            [!VAR "NumChannelInPartition" = "0"!]

            /* Count channels in each module that is using for current partition */
            [!LOOP "./../../../PwmChannelConfigSet/PwmChannel/*"!]

                [!LOOP "./PwmChannelEcucPartitionRef/*"!]
                    [!VAR "PwmChannelEcucPartitionRefName" = "node:value(.)"!]

                    [!IF "$PwmChannelEcucPartitionRefName = $PwmEcucPartitionRefName"!]
                        [!VAR "NumChannelInPartition" = "$NumChannelInPartition + 1"!]
                    [!ENDIF!]
                [!ENDLOOP!]
            [!ENDLOOP!]

            [!IF "(num:i($NumChannelInPartition)) > 0"!]
                [!VAR "NumFtmModuleInPartition" = "0"!]

                [!VAR "FtmModuleMappingArray" = "''"!]
                [!VAR "MappingArrayIndex" = "0"!]

                /* Count FTM modules that is using for current partition
                   and generate mapping array for FTM module in current partition */
                [!LOOP "as:modconf('Pwm')[1]/PwmChannelConfigSet/PwmFtm/*"!]
                    [!VAR "FtmHardwareModule" = "./PwmHwInstance"!]
                    [!VAR "HasOccurred" = "0"!]

                    [!LOOP "./../../../PwmChannel/*"!]
                        [!IF "$HasOccurred = 0"!]
                            [!LOOP "./PwmChannelEcucPartitionRef/*"!]
                                [!VAR "PwmChannelEcucPartitionRefName" = "node:value(.)"!]

                                [!IF "$PwmChannelEcucPartitionRefName = $PwmEcucPartitionRefName"!]
                                    [!IF "node:value(node:ref(./../../PwmHwChannel)/../../PwmHwInstance) = $FtmHardwareModule"!]
                                        [!VAR "NumFtmModuleInPartition" = "$NumFtmModuleInPartition + 1"!]
                                        [!VAR "HasOccurred" = "1"!]
                                    [!ENDIF!]
                                [!ENDIF!]
                            [!ENDLOOP!]
                        [!ENDIF!]
                    [!ENDLOOP!]

                    [!IF "$HasOccurred = 1"!]
                        [!VAR "FtmModuleMappingArray" = "concat($FtmModuleMappingArray, '|', num:i($MappingArrayIndex))"!]
                        [!VAR "MappingArrayIndex" = "$MappingArrayIndex + 1"!]
                    [!ELSE!]
                        [!VAR "FtmModuleMappingArray" = "concat($FtmModuleMappingArray, '|255')"!]
                    [!ENDIF!]
                [!ENDLOOP!]
            [!ENDIF!]
        [!ENDNOCODE!]
[!//
        [!IF "$NumChannelInPartition > 0"!]
/*================================== Partition [!"$PwmEcucPartitionShortName"!] ==================================*/
/**
* @brief        Array of configured PWM channels
*
*/
const Pwm_ChannelConfigType Pwm_Channels[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PB_[!"$PwmEcucPartitionShortName"!][PWM[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PB_CFG_CHANNELS_COUNT_[!"text:toupper($PwmEcucPartitionShortName)"!]] =
{
            [!NOCODE!]
                [!VAR "PwmChIndex" = "0"!]
                [!VAR "comma" = "0"!]
                [!FOR "varCounter" = "0" TO "$numChannelsCfg - 1"!]
                    [!LOOP "as:modconf('Pwm')[1]/PwmChannelConfigSet/PwmChannel/*"!]
                        [!IF "$varCounter = ./PwmChannelId"!]
                            [!VAR "HasPartition" = "0"!]

                            [!LOOP "./PwmChannelEcucPartitionRef/*"!]
                                [!VAR "PwmChannelEcucPartitionRefName" = "node:value(.)"!]
                                [!IF "$PwmChannelEcucPartitionRefName = $PwmEcucPartitionRefName"!]
                                    [!VAR "HasPartition" = "1"!]
                                [!ENDIF!]
                            [!ENDLOOP!]

                            [!IF "$HasPartition = 1"!]
                                [!VAR "ChannelName" = "node:name(.)"!]
                                [!VAR "ChannelId" = "PwmChannelId"!]

                                [!"node:refvalid(PwmHwChannel)"!]

                                [!IF "node:exists(PwmChannelClass)"!]
                                    [!VAR "ChannelClass" = "node:value(PwmChannelClass)"!]
                                [!ELSE!]
                                    [!VAR "ChannelClass" = "'PWM_FIXED_PERIOD'"!]
                                [!ENDIF!]

                                [!IF "(node:exists('PwmNotification')) and ((PwmNotification != '"NULL_PTR"') and (PwmNotification != 'NULL_PTR') and (PwmNotification != '"NULL"') and (PwmNotification != 'NULL'))"!]
                                    [!VAR "NotifFunc" = "concat('&', PwmNotification)"!]
                                [!ELSE!]
                                    [!VAR "NotifFunc" = "'NULL_PTR'"!]
                                [!ENDIF!]

                                [!CODE!]
    /* [!"$ChannelName"!] */
    {
        /** @brief  Channel Id */
        (Pwm_ChannelType)[!"$ChannelId"!]U,
        /** @brief  Channel class */
        [!"$ChannelClass"!],
        /** @brief  Ip channel configuration */
        {
                                    [!IF "text:match(node:ref(PwmHwChannel)/../../PwmHwInstance, 'Emios') = 'true'"!]
                                        [!VAR "instanceId" = "substring-after(node:ref(PwmHwChannel)/../../PwmHwInstance, '_')"!]
                                        [!VAR "channelId" = "substring-after(node:ref(PwmHwChannel)/EmiosChId, '_')"!]
            /** @brief  Hardware Channel Type */
            PWM_CHANNEL_EMIOS,
            /** @brief  Pointer to the Emios ip Configuration */
            (const void *)(&Emios_Pwm_Ip[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_I[!"$instanceId"!]_Ch[!"$channelId"!]),
        #if (defined(PWM_FLEXIO_USED) && (PWM_FLEXIO_USED == STD_ON))
            /** @brief  Pointer to the Flexio ip channel configuration structure */
            NULL_PTR,
[!IF "ecu:has('Pwm.FlexioHasPrescaler') and (ecu:get('Pwm.FlexioHasPrescaler') = 'true')"!]
            /** @brief  Alternate Clock for flexio channel */
            FLEXIO_PWM_IP_CLK_DIV_1,
[!ENDIF!]
        #endif
        #if (PWM_FLEXPWM_USED == STD_ON)
            /** @brief  Pointer to the FlexPwm ip channel configuration structure */
            NULL_PTR,
            /** @brief SubModule id for this channel */
            0U,
        #endif
        #if (defined(PWM_ETIMER_USED) && (PWM_ETIMER_USED == STD_ON))
            /** @brief  Pointer to the Etimer ip channel configuration structure */
            NULL_PTR,
        #endif
            /** @brief  Hardware Channel Instance ID */
            (Pwm_IpwInstanceType)EMIOS_PWM_IP[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_I[!"$instanceId"!]_CH[!"$channelId"!]_CFG,
            /** @brief The duty cycle of this channel */
            [!"PwmDutycycleDefault"!]U
                                    [!ELSEIF "text:match(node:ref(PwmHwChannel)/../../PwmHwInstance, 'Etimer') = 'true'"!]
                                        [!VAR "instanceId" = "substring-after(node:ref(PwmHwChannel)/../../PwmHwInstance, '_')"!]
                                        [!VAR "channelId" = "substring-after(node:ref(PwmHwChannel)/EtimerChId, '_')"!]
            /** @brief  Hardware Channel Type */
            PWM_CHANNEL_ETIMER,
        #if (PWM_EMIOS_USED == STD_ON)
            /** @brief  Pointer to the Emios ip channel configuration structure */
            NULL_PTR,
        #endif
        #if (PWM_FLEXPWM_USED == STD_ON)
            /** @brief  Pointer to the FlexPwm ip channel configuration structure */
            NULL_PTR,
            /** @brief SubModule id for this channel */
            0U,
        #endif
            /** @brief  Pointer to the Etimer ip Configuration */
            (const void *)(&Etimer_Pwm_Ip[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_I[!"$instanceId"!]_Ch[!"$channelId"!]),
            /** @brief  Hardware Channel Instance ID */
            (Pwm_IpwInstanceType)ETIMER_PWM_IP[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_I[!"$instanceId"!]_CH[!"$channelId"!]_CFG,
            /** @brief The duty cycle of this channel */
            [!"PwmDutycycleDefault"!]U
                                    [!ELSEIF "text:match(node:ref(PwmHwChannel)/../../PwmHwInstance, 'Flexio') = 'true'"!]
                                        [!VAR "instanceId" = "substring-after(node:ref(PwmHwChannel)/../../PwmHwInstance, '_')"!]
                                        [!VAR "channelId" = "substring-after(node:ref(PwmHwChannel)/FlexioChId, '_')"!]
            /** @brief  Hardware Channel Type */
            PWM_CHANNEL_FLEXIO,
        #if (defined(PWM_EMIOS_USED) && (PWM_EMIOS_USED == STD_ON))
            /** @brief  Pointer to the Emios ip Channel Configuration */
            NULL_PTR,
        #endif
        #if (defined(PWM_FTM_USED) && (PWM_FTM_USED == STD_ON))
            /** @brief  Pointer to the Ftm ip Channel Configuration */
            NULL_PTR,
        #endif
        #if (defined(PWM_FLEXIO_USED) && (PWM_FLEXIO_USED == STD_ON))
            /** @brief  Pointer to the Flexio ip channel configuration structure */
            &Flexio_Pwm_Ip[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_I[!"$instanceId"!]_Ch[!"$channelId"!],
[!IF "ecu:has('Pwm.FlexioHasPrescaler') and (ecu:get('Pwm.FlexioHasPrescaler') = 'true')"!]
            /** @brief  Alternate Clock for flexio channel */
            [!"node:ref(PwmHwChannel)/FlexioChPrescalerAlternate"!],
[!ENDIF!]
        #endif
        #if (defined(PWM_FLEXPWM_USED) && (PWM_FLEXPWM_USED == STD_ON))
            /** @brief  Pointer to the FlexPwm ip channel configuration structure */
            NULL_PTR,
            /** @brief SubModule id for this channel */
            0U,
        #endif
            /** @brief  Hardware Channel Instance ID */
            (Pwm_IpwInstanceType)FLEXIO_PWM_IP[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_I[!"$instanceId"!]_CH[!"$channelId"!]_CFG,
            /** @brief The duty cycle of this channel */
            [!"PwmDutycycleDefault"!]U
                                    [!ELSEIF "text:match(node:ref(PwmHwChannel)/../../PwmHwInstance, 'Ftm') = 'true'"!]
                                        [!VAR "instanceId" = "substring-after(node:ref(PwmHwChannel)/../../PwmHwInstance, '_')"!]
                                        [!VAR "channelId" = "substring-after(node:ref(PwmHwChannel)/PwmFtmChId, '_')"!]
            /** @brief  Hardware Channel Type */
            PWM_CHANNEL_FTM,
            /** @brief  Hardware Channel Configuration Pointer */
            (const void *)(&Ftm_Pwm_Ip[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_I[!"$instanceId"!]_Ch[!"$channelId"!]),
        #if (defined(PWM_FLEXIO_USED) && (PWM_FLEXIO_USED == STD_ON))
            /** @brief  Pointer to the Flexio ip channel configuration structure */
            NULL_PTR,
[!IF "ecu:has('Pwm.FlexioHasPrescaler') and (ecu:get('Pwm.FlexioHasPrescaler') = 'true')"!]
            /** @brief  Alternate Clock for flexio channel*/
            FLEXIO_PWM_IP_CLK_DIV_1,
[!ENDIF!]
        #endif
            /** @brief  Hardware Channel Instance ID */
            (Pwm_IpwInstanceType)FTM_PWM_IP[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_I[!"$instanceId"!]_CH[!"$channelId"!]_CFG,
            /** @brief The duty cycle of this channel */
            [!"PwmDutycycleDefault"!]U
                                    [!ELSEIF "contains(PwmHwChannel,'FlexPwm')"!]
                                        [!VAR "instanceId" = "num:i(substring-after(node:ref(PwmHwChannel)/../../../../FlexPwmModule, '_'))"!]
                                        [!VAR "SubModule" = "num:i(substring-after(node:ref(PwmHwChannel)/../../FlexPwmSubModule, '_'))"!]
                                        [!VAR "channelCfgName" = "(substring-after(node:ref(PwmHwChannel)/FlexPwmChannel, 'FLEXPWM_IP_'))"!]
            /** @brief  Hardware Channel Type */
            PWM_CHANNEL_FLEXPWM,
        #if (PWM_EMIOS_USED == STD_ON)
            /** @brief  Pointer to the Emios ip channel configuration structure */
            NULL_PTR,
        #endif
        #if (defined(PWM_FLEXIO_USED) && (PWM_FLEXIO_USED == STD_ON))
            /** @brief  Pointer to the Flexio ip channel configuration structure */
            NULL_PTR,
[!IF "ecu:has('Pwm.FlexioHasPrescaler') and (ecu:get('Pwm.FlexioHasPrescaler') = 'true')"!]
            /** @brief  Alternate Clock for flexio channel*/
            FLEXIO_PWM_IP_CLK_DIV_1,
[!ENDIF!]
        #endif
            /** @brief  Hardware Channel Configuration Pointer */
            (const void *)(&FlexPwm_Ip[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_ChannelCfg_I[!"$instanceId"!]_S[!"$SubModule"!]_[!"$channelCfgName"!]),
            /** @brief SubModule id for this channel */
            (uint8)FLEXPWM_IP_SUB[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_I[!"$instanceId"!]_SUB[!"$SubModule"!]_CFG,
            /** @brief  Hardware Channel Instance ID */
        #if (defined(PWM_ETIMER_USED) && (PWM_ETIMER_USED == STD_ON))
            /** @brief  Pointer to the Etimer ip channel configuration structure */
            NULL_PTR,
        #endif
            (Pwm_IpwInstanceType)FLEXPWM_IP_INS[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_I[!"$instanceId"!]_SUB[!"$SubModule"!]_[!"$channelCfgName"!]_CFG,
            /** @brief The duty cycle of this channel */
            [!"PwmDutycycleDefault"!]U
                                    [!ELSE!]
            /** @brief  Hardware Channel Type */
            PWM_CHANNEL_NONE,
            /** @brief  Hardware Channel Configuration Pointer */
            NULL_PTR,
            /** @brief  Hardware Channel Instance ID */
            (Pwm_IpwInstanceType)0U,
            /** @brief The duty cycle of this channel */
            0U
                                    [!ENDIF!]
        },
        /** @brief  The state of the channel output in idle mode */
        [!"PwmIdleState"!][!IF "../../../PwmGeneral/PwmNotificationSupported"!],[!ENDIF!][!CR!]
                                    [!IF "../../../PwmGeneral/PwmNotificationSupported"!]
                                        [!WS "8"!][!"$NotifFunc"!]
                                    [!ENDIF!]
                                    [!IF "$comma < $NumChannelInPartition - 1"!][!VAR "comma" = "$comma + 1"!]
    },
                                    [!ELSE!]
    }
                                    [!ENDIF!]
                                [!ENDCODE!]
                            [!ENDIF!]
                        [!ENDIF!]
                        [!VAR "PwmChIndex" = "$PwmChIndex + 1"!]
                    [!ENDLOOP!]
                [!ENDFOR!]
            [!ENDNOCODE!]
};

        [!ENDIF!]
    [!ENDLOOP!]
[!ELSE!][!//
/**
* @brief        Array of configured PWM channels
*
*/
const Pwm_ChannelConfigType Pwm_Channels[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PB[PWM[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PB_CFG_CHANNELS_COUNT] =
{
    [!NOCODE!]
        [!VAR "PwmChIndex" = "0"!]
        [!VAR "comma" = "0"!]
        [!FOR "varCounter" = "0" TO "$numChannelsCfg - 1"!]
            [!LOOP "as:modconf('Pwm')[1]/PwmChannelConfigSet/PwmChannel/*"!]
                [!IF "$varCounter = ./PwmChannelId"!]
                    [!VAR "ChannelName" = "node:name(.)"!]
                    [!VAR "ChannelId" = "PwmChannelId"!]

                    [!"node:refvalid(PwmHwChannel)"!]

                    [!IF "node:exists(PwmChannelClass)"!]
                        [!VAR "ChannelClass" = "node:value(PwmChannelClass)"!]
                    [!ELSE!]
                        [!VAR "ChannelClass" = "'PWM_FIXED_PERIOD'"!]
                    [!ENDIF!]

                    [!IF "(node:exists('PwmNotification')) and ((PwmNotification != '"NULL_PTR"') and (PwmNotification != 'NULL_PTR') and (PwmNotification != '"NULL"') and (PwmNotification != 'NULL'))"!]
                        [!VAR "NotifFunc" = "concat('&', PwmNotification)"!]
                    [!ELSE!]
                        [!VAR "NotifFunc" = "'NULL_PTR'"!]
                    [!ENDIF!]

                    [!CODE!]
    /* [!"$ChannelName"!] */
    {
        /** @brief  Channel Id */
        (Pwm_ChannelType)[!"$ChannelId"!]U,
        /** @brief  Channel class */
        [!"$ChannelClass"!],
        /** @brief  Ip channel configuration */
        {
                        [!IF "text:match(node:ref(PwmHwChannel)/../../PwmHwInstance, 'Emios') = 'true'"!]
                            [!VAR "instanceId" = "substring-after(node:ref(PwmHwChannel)/../../PwmHwInstance, '_')"!]
                            [!VAR "channelId" = "substring-after(node:ref(PwmHwChannel)/EmiosChId, '_')"!]
            /** @brief  Hardware Channel Type */
            PWM_CHANNEL_EMIOS,
            /** @brief  Pointer to the Emios ip Configuration */
            (const void *)(&Emios_Pwm_Ip[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_I[!"$instanceId"!]_Ch[!"$channelId"!]),
        #if (defined(PWM_FLEXIO_USED) && (PWM_FLEXIO_USED == STD_ON))
            /** @brief  Pointer to the Flexio ip channel configuration structure */
            NULL_PTR,
[!IF "ecu:has('Pwm.FlexioHasPrescaler') and (ecu:get('Pwm.FlexioHasPrescaler') = 'true')"!]
            /** @brief  Alternate Clock for flexio channel */
            FLEXIO_PWM_IP_CLK_DIV_1,
[!ENDIF!]
        #endif
        #if (PWM_FLEXPWM_USED == STD_ON)
            /** @brief  Pointer to the FlexPwm ip channel configuration structure */
            NULL_PTR,
            /** @brief SubModule id for this channel */
            0U,
        #endif
        #if (defined(PWM_ETIMER_USED) && (PWM_ETIMER_USED == STD_ON))
            /** @brief  Pointer to the Etimer ip channel configuration structure */
            NULL_PTR,
        #endif
            /** @brief  Hardware Channel Instance ID */
            (Pwm_IpwInstanceType)EMIOS_PWM_IP[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_I[!"$instanceId"!]_CH[!"$channelId"!]_CFG,
            /** @brief The duty cycle of this channel */
            [!"PwmDutycycleDefault"!]U
                                    [!ELSEIF "text:match(node:ref(PwmHwChannel)/../../PwmHwInstance, 'Etimer') = 'true'"!]
                                        [!VAR "instanceId" = "substring-after(node:ref(PwmHwChannel)/../../PwmHwInstance, '_')"!]
                                        [!VAR "channelId" = "substring-after(node:ref(PwmHwChannel)/EtimerChId, '_')"!]
            /** @brief  Hardware Channel Type */
            PWM_CHANNEL_ETIMER,
        #if (PWM_EMIOS_USED == STD_ON)
            /** @brief  Pointer to the Emios ip channel configuration structure */
            NULL_PTR,
        #endif
        #if (PWM_FLEXPWM_USED == STD_ON)
            /** @brief  Pointer to the FlexPwm ip channel configuration structure */
            NULL_PTR,
            /** @brief SubModule id for this channel */
            0U,
        #endif
            /** @brief  Pointer to the Etimer ip Configuration */
            (const void *)(&Etimer_Pwm_Ip[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_I[!"$instanceId"!]_Ch[!"$channelId"!]),
            /** @brief  Hardware Channel Instance ID */
            (Pwm_IpwInstanceType)ETIMER_PWM_IP[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_I[!"$instanceId"!]_CH[!"$channelId"!]_CFG,
            /** @brief The duty cycle of this channel */
            [!"PwmDutycycleDefault"!]U
                        [!ELSEIF "text:match(node:ref(PwmHwChannel)/../../PwmHwInstance, 'Flexio') = 'true'"!]
                            [!VAR "instanceId" = "substring-after(node:ref(PwmHwChannel)/../../PwmHwInstance, '_')"!]
                            [!VAR "channelId" = "substring-after(node:ref(PwmHwChannel)/FlexioChId, '_')"!]
            /** @brief  Hardware Channel Type */
            PWM_CHANNEL_FLEXIO,
        #if (defined(PWM_EMIOS_USED) && (PWM_EMIOS_USED == STD_ON))
            /** @brief  Pointer to the Emios ip channel configuration structure */
            NULL_PTR,
        #endif
        #if (defined(PWM_FTM_USED) && (PWM_FTM_USED == STD_ON))
            /** @brief  Pointer to the Ftm ip Channel Configuration */
            NULL_PTR,
        #endif
        #if (defined(PWM_FLEXIO_USED) && (PWM_FLEXIO_USED == STD_ON))
            /** @brief  Pointer to the Flexio ip channel configuration structure */
            &Flexio_Pwm_Ip[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_I[!"$instanceId"!]_Ch[!"$channelId"!],
[!IF "ecu:has('Pwm.FlexioHasPrescaler') and (ecu:get('Pwm.FlexioHasPrescaler') = 'true')"!]
            /** @brief  Alternate Clock for flexio channel */
            [!"node:ref(PwmHwChannel)/FlexioChPrescalerAlternate"!],
[!ENDIF!]
        #endif
        #if (defined(PWM_FLEXPWM_USED) && (PWM_FLEXPWM_USED == STD_ON))
            /** @brief  Pointer to the FlexPwm ip channel configuration structure */
            NULL_PTR,
            /** @brief SubModule id for this channel */
            0U,
        #endif
            /** @brief  Hardware Channel Instance ID */
            (Pwm_IpwInstanceType)FLEXIO_PWM_IP[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_I[!"$instanceId"!]_CH[!"$channelId"!]_CFG,
            /** @brief The duty cycle of this channel */
            [!"PwmDutycycleDefault"!]U
                        [!ELSEIF "text:match(node:ref(PwmHwChannel)/../../PwmHwInstance, 'Ftm') = 'true'"!]
                            [!VAR "instanceId" = "substring-after(node:ref(PwmHwChannel)/../../PwmHwInstance, '_')"!]
                            [!VAR "channelId" = "substring-after(node:ref(PwmHwChannel)/PwmFtmChId, '_')"!]
            /** @brief  Hardware Channel Type */
            PWM_CHANNEL_FTM,
            /** @brief  Hardware Channel Configuration Pointer */
            (const void *)(&Ftm_Pwm_Ip[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_I[!"$instanceId"!]_Ch[!"$channelId"!]),
        #if (defined(PWM_FLEXIO_USED) && (PWM_FLEXIO_USED == STD_ON))
            /** @brief  Pointer to the Flexio ip channel configuration structure */
            NULL_PTR,
[!IF "ecu:has('Pwm.FlexioHasPrescaler') and (ecu:get('Pwm.FlexioHasPrescaler') = 'true')"!]
            /** @brief  Alternate Clock for flexio channel kkkk */
            FLEXIO_PWM_IP_CLK_DIV_1,
[!ENDIF!]
        #endif
            /** @brief  Hardware Channel Instance ID */
            (Pwm_IpwInstanceType)FTM_PWM_IP[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_I[!"$instanceId"!]_CH[!"$channelId"!]_CFG,
            /** @brief The duty cycle of this channel */
            [!"PwmDutycycleDefault"!]U
                        [!ELSEIF "contains(PwmHwChannel,'FlexPwm')"!]
                            [!VAR "instanceId" = "num:i(substring-after(node:ref(PwmHwChannel)/../../../../FlexPwmModule, '_'))"!]
                            [!VAR "SubModule" = "num:i(substring-after(node:ref(PwmHwChannel)/../../FlexPwmSubModule, '_'))"!]
                            [!VAR "channelCfgName" = "(substring-after(node:ref(PwmHwChannel)/FlexPwmChannel, 'FLEXPWM_IP_'))"!]
            /** @brief  Hardware Channel Type */
            PWM_CHANNEL_FLEXPWM,
        #if (PWM_EMIOS_USED == STD_ON)
            /** @brief  Pointer to the Emios ip channel configuration structure */
            NULL_PTR,
        #endif
        #if (defined(PWM_FLEXIO_USED) && (PWM_FLEXIO_USED == STD_ON))
            /** @brief  Pointer to the Flexio ip channel configuration structure */
            NULL_PTR,
[!IF "ecu:has('Pwm.FlexioHasPrescaler') and (ecu:get('Pwm.FlexioHasPrescaler') = 'true')"!]
            /** @brief  Alternate Clock for flexio channel */
            FLEXIO_PWM_IP_CLK_DIV_1,
[!ENDIF!]
        #endif
            /** @brief  Hardware Channel Configuration Pointer */
            (const void *)(&FlexPwm_Ip[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_ChannelCfg_I[!"$instanceId"!]_S[!"$SubModule"!]_[!"$channelCfgName"!]),
            /** @brief SubModule id for this channel */
            (uint8)FLEXPWM_IP_SUB[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_I[!"$instanceId"!]_SUB[!"$SubModule"!]_CFG,
            /** @brief  Hardware Channel Instance ID */
        #if (defined(PWM_ETIMER_USED) && (PWM_ETIMER_USED == STD_ON))
            /** @brief  Pointer to the Etimer ip channel configuration structure */
            NULL_PTR,
        #endif
            (Pwm_IpwInstanceType)FLEXPWM_IP_INS[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_I[!"$instanceId"!]_SUB[!"$SubModule"!]_[!"$channelCfgName"!]_CFG,
            /** @brief The duty cycle of this channel */
            [!"PwmDutycycleDefault"!]U
                        [!ELSE!]
            /** @brief  Hardware Channel Type */
            PWM_CHANNEL_NONE,
            /** @brief  Hardware Channel Configuration Pointer */
            NULL_PTR,
            /** @brief  Hardware Channel Instance ID */
            (Pwm_IpwInstanceType)0U,
            /** @brief The duty cycle of this channel */
            0U
                        [!ENDIF!]
        },
        /** @brief  The state of the channel output in idle mode */
        [!"PwmIdleState"!][!IF "../../../PwmGeneral/PwmNotificationSupported"!],[!ENDIF!][!CR!]
                        [!IF "../../../PwmGeneral/PwmNotificationSupported"!]
                            [!WS "8"!][!"$NotifFunc"!]
                        [!ENDIF!]
    }[!IF "$PwmChIndex < $PwmChannels - 1"!],[!ENDIF!][!CR!]
                    [!ENDCODE!]
                    [!VAR "PwmChIndex" = "$PwmChIndex + 1"!]
                [!ENDIF!]
            [!ENDLOOP!]
        [!ENDFOR!]
    [!ENDNOCODE!]
};
[!ENDIF!]
[!//
[!IF "(ecu:has('Pwm.ExclusiveHwInstance') = 'true') and (ecu:get('Pwm.ExclusiveHwInstance') = 'true')"!]
/*============================== Instances configuration ===================================*/
[!ENDIF!]
[!IF "$MulticoreEnabled = 1"!]
    [!LOOP "as:modconf('Pwm')[1]/PwmGeneral/PwmEcucPartitionRef/*"!]
        [!NOCODE!]
            [!VAR "PartitionIndex" = "@index"!]

            [!VAR "PwmEcucPartitionRefName" = "node:value(.)"!]
            [!VAR "PwmEcucPartitionShortName" = "substring-after($PwmEcucPartitionRefName, '/')"!]
            [!VAR "PwmEcucPartitionShortName" = "substring-after($PwmEcucPartitionShortName, '/')"!]
            [!VAR "PwmEcucPartitionShortName" = "substring-after($PwmEcucPartitionShortName, '/')"!]
            [!VAR "PwmEcucPartitionShortName" = "substring-after($PwmEcucPartitionShortName, '/')"!]

            [!VAR "NumChannelInPartition" = "0"!]

            /* Count channels in each module that is using for current partition */
            [!LOOP "./../../../PwmChannelConfigSet/PwmChannel/*"!]

                [!LOOP "./PwmChannelEcucPartitionRef/*"!]
                    [!VAR "PwmChannelEcucPartitionRefName" = "node:value(.)"!]

                    [!IF "$PwmChannelEcucPartitionRefName = $PwmEcucPartitionRefName"!]
                        [!VAR "NumChannelInPartition" = "$NumChannelInPartition + 1"!]
                    [!ENDIF!]
                [!ENDLOOP!]
            [!ENDLOOP!]

            [!IF "(num:i($NumChannelInPartition)) > 0"!]

                [!VAR "NumFtmModuleInPartition" = "0"!]
                [!VAR "NumFlexPwmModuleInPartition" = "0"!]

                [!VAR "FtmModuleMappingArray" = "''"!]
                [!VAR "FlexPwmModuleMappingArray" = "''"!]
                [!VAR "MappingArrayIndex" = "0"!]

                /* Count FTM modules that is using for current partition
                   and generate mapping array for FTM module in current partition */
                [!LOOP "as:modconf('Pwm')[1]/PwmChannelConfigSet/PwmFtm/*"!]
                    [!VAR "FtmHardwareModule" = "./PwmHwInstance"!]
                    [!VAR "HasOccurred" = "0"!]

                    [!LOOP "./../../PwmChannel/*"!]
                        [!IF "$HasOccurred = 0"!]
                            [!LOOP "./PwmChannelEcucPartitionRef/*"!]
                                [!VAR "PwmChannelEcucPartitionRefName" = "node:value(.)"!]

                                [!IF "$PwmChannelEcucPartitionRefName = $PwmEcucPartitionRefName"!]
                                    [!IF "node:value(node:ref(./../../PwmHwChannel)/../../PwmHwInstance) = $FtmHardwareModule"!]

                                        [!VAR "NumFtmModuleInPartition" = "$NumFtmModuleInPartition + 1"!]
                                        [!VAR "HasOccurred" = "1"!]
                                    [!ENDIF!]
                                [!ENDIF!]
                            [!ENDLOOP!]
                        [!ENDIF!]
                    [!ENDLOOP!]

                    [!IF "$HasOccurred = 1"!]
                        [!VAR "FtmModuleMappingArray" = "concat($FtmModuleMappingArray, '|', num:i($MappingArrayIndex))"!]
                        [!VAR "MappingArrayIndex" = "$MappingArrayIndex + 1"!]
                    [!ELSE!]
                        [!VAR "FtmModuleMappingArray" = "concat($FtmModuleMappingArray, '|255')"!]
                    [!ENDIF!]
                [!ENDLOOP!]
                
                /* Count FlexPwm modules that is using for current partition
                   and generate mapping array for FlexPwm module in current partition */
                [!LOOP "as:modconf('Pwm')[1]/PwmChannelConfigSet/FlexPwm/*"!]
                    [!VAR "FlexPwmHardwareModule" = "./FlexPwmModule"!]
                    [!VAR "HasOccurred" = "0"!]

                    [!LOOP "./../../PwmChannel/*"!]
                        [!IF "$HasOccurred = 0"!]
                            [!LOOP "./PwmChannelEcucPartitionRef/*"!]
                                [!VAR "PwmChannelEcucPartitionRefName" = "node:value(.)"!]

                                [!IF "$PwmChannelEcucPartitionRefName = $PwmEcucPartitionRefName"!]
                                    [!IF "(node:ref(./../../PwmHwChannel)/../../../../FlexPwmModule) = $FlexPwmHardwareModule"!]

                                        [!VAR "NumFlexPwmModuleInPartition" = "$NumFlexPwmModuleInPartition + 1"!]
                                        [!VAR "HasOccurred" = "1"!]
                                    [!ENDIF!]
                                [!ENDIF!]
                            [!ENDLOOP!]
                        [!ENDIF!]
                    [!ENDLOOP!]

                    [!IF "$HasOccurred = 1"!]
                        [!VAR "FlexPwmModuleMappingArray" = "concat($FlexPwmModuleMappingArray, '|', num:i($MappingArrayIndex))"!]
                        [!VAR "MappingArrayIndex" = "$MappingArrayIndex + 1"!]
                    [!ELSE!]
                        [!VAR "FlexPwmModuleMappingArray" = "concat($FlexPwmModuleMappingArray, '|255')"!]
                    [!ENDIF!]
                [!ENDLOOP!]
            [!ENDIF!]
        [!ENDNOCODE!]
[!//
        [!IF "$NumChannelInPartition > 0"!]

/*================================== Partition [!"$PwmEcucPartitionShortName"!] ==================================*/
            [!IF "(ecu:has('Pwm.ExclusiveHwInstance') = 'true') and (ecu:get('Pwm.ExclusiveHwInstance') = 'true')"!]
#if (PWM_HW_INSTANCE_USED == STD_ON)
/** @brief        Array of configured Pwm instances */
const Pwm_IpwInstanceConfigType Pwm_Instances[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PB_[!"$PwmEcucPartitionShortName"!][PWM[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PB_CFG_INSTANCES_COUNT_[!"text:toupper($PwmEcucPartitionShortName)"!]] =
{
                [!IF "$pwmFtmSupported = 'true'"!]
                    [!VAR "ftmInstances"  = "num:i(count(./../../../PwmChannelConfigSet/PwmFtm/*))"!]
                    [!IF "$ftmInstances > 0"!]
                        [!VAR "comma" = "1"!]
                        [!LOOP "as:modconf('Pwm')[1]/PwmChannelConfigSet/PwmFtm/*"!]
                            [!VAR "FtmModuleArrayIndex" = "@index"!]
                            [!IF "text:split($FtmModuleMappingArray, '|')[num:i($FtmModuleArrayIndex) + 1] != '255'"!]
    {
                                [!VAR "instanceId" = "substring-after(PwmHwInstance, '_')"!]
        /** @brief  The Id instance configured */
        [!"$instanceId"!]U,
        /** @brief  The type of ip instance configured */
        PWM_INSTANCE_FTM,
        /** @brief  Pointer to the ip instance configuration structure */
        (const void *)(&Ftm_Pwm_Ip[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_UserCfg[!"$instanceId"!])
    }[!IF "(num:i($comma)) < (num:i($NumFtmModuleInPartition))"!],[!ENDIF!][!VAR "comma" = "$comma + 1"!][!CR!]
                                [!ENDIF!]
                        [!ENDLOOP!]
                    [!ELSE!]
    {
         /** @brief  The Id instance configured */
        255U,
        /** @brief  The type of ip instance configured */
        PWM_INSTANCE_NONE,
        /** @brief  Pointer to the ip instance configuration structure */
        NULL_PTR
    }        
                    [!ENDIF!]
                [!ELSEIF "$pwmFlexPwmSupported = 'true'"!]
                    [!VAR "FlexPwmInstances"  = "num:i(count(./../../../PwmChannelConfigSet/FlexPwm/*))"!]
                    [!IF "($FlexPwmInstances > 0) and ($NumFlexPwmModuleInPartition > 0)"!]
                        [!VAR "comma" = "1"!]
                        [!LOOP "as:modconf('Pwm')[1]/PwmChannelConfigSet/FlexPwm/*"!]
                            [!VAR "FlexPwmModuleArrayIndex" = "@index"!]
                            [!IF "text:split($FlexPwmModuleMappingArray, '|')[num:i($FlexPwmModuleArrayIndex) + 1] != '255'"!]
    {
                                [!VAR "instanceId" = "substring-after(FlexPwmModule, '_')"!]
        /** @brief  The Id instance configured */
        [!IF "$FlexPwmHwStartFrom0 = 'true'"!]
            [!"num:i($instanceId)"!]U,
        [!ELSE!]
            [!"num:i($instanceId - 1)"!]U,
        [!ENDIF!]
        /** @brief  The type of ip instance configured */
        PWM_INSTANCE_FLEXPWM,
        /** @brief  Pointer to the ip instance configuration structure */
        (const void *)(&FlexPwm_Ip[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_InstanceCfg_I[!"$instanceId"!])
    }[!IF "(num:i($comma)) < (num:i($NumFlexPwmModuleInPartition))"!],[!ENDIF!][!VAR "comma" = "$comma + 1"!][!CR!]
                                [!ENDIF!]
                        [!ENDLOOP!]
                    [!ELSE!]
    {
        /** @brief  The Id instance configured */
        255U,
        /** @brief  The type of ip instance configured */
        PWM_INSTANCE_NONE,
#if (PWM_FLEXPWM_USED == STD_ON)           
        /** @brief  Pointer to the ip instance configuration structure */
        NULL_PTR
#endif
    }        
                    [!ENDIF!]
                [!ELSE!]
    {
          /** @brief  The Id instance configured */
        255U,
        /** @brief  The type of ip instance configured */
        PWM_INSTANCE_NONE
    }
                [!ENDIF!]
};
#endif
            [!ENDIF!]

const uint8 Pwm_LogicalToPartitionMap[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PB_[!"$PwmEcucPartitionShortName"!][PWM[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PB_CFG_CHANNELS_COUNT] =
{
            [!NOCODE!]
                [!VAR "PartitionLogicalChannelIdx" = "0"!]
                [!VAR "comma" = "0"!]

                [!FOR "varCounter" = "0" TO "$numChannelsCfg - 1"!]
                    [!LOOP "./../../../PwmChannelConfigSet/PwmChannel/*"!]
                        [!IF "$varCounter = PwmChannelId"!]
                            [!VAR "HasPartition" = "0"!]

                            [!LOOP "./PwmChannelEcucPartitionRef/*"!]
                                [!VAR "PwmChannelEcucPartitionRefName" = "node:value(.)"!]

                                [!IF "$PwmChannelEcucPartitionRefName = $PwmEcucPartitionRefName"!]
                                    [!VAR "HasPartition" = "1"!]
                                [!ENDIF!]
                            [!ENDLOOP!]

                            [!IF "$HasPartition = 1"!]
                                [!CODE!]
    /* Mapping from [!"node:name(.)"!] */
    (uint8)[!"num:i($PartitionLogicalChannelIdx)"!][!VAR "PartitionLogicalChannelIdx" = "$PartitionLogicalChannelIdx + 1"!][!IF "(num:i($comma)) < (num:i($numChannelsCfg - 1))"!][!VAR "comma" = "$comma + 1"!],[!ENDIF!][!CR!]
                                [!ENDCODE!]
                            [!ELSE!]
                                [!CODE!]
    /* No logical channel mapping */
    (uint8)255U[!IF "(num:i($comma)) < (num:i($numChannelsCfg - 1))"!][!VAR "comma" = "$comma + 1"!],[!ENDIF!][!CR!]
                                [!ENDCODE!]
                            [!ENDIF!]
                        [!ENDIF!]
                    [!ENDLOOP!]
                [!ENDFOR!]
            [!ENDNOCODE!]
};
        [!ENDIF!]
    [!ENDLOOP!]
[!ELSE!]

    [!IF "(ecu:has('Pwm.ExclusiveHwInstance') = 'true') and (ecu:get('Pwm.ExclusiveHwInstance') = 'true')"!]
#if (PWM_HW_INSTANCE_USED == STD_ON)
/** @brief        Array of configured Pwm instances */
const Pwm_IpwInstanceConfigType Pwm_Instances[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PB[PWM[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PB_CFG_INSTANCES_COUNT] =
{
        [!IF "$pwmFtmSupported = 'true'"!]
            [!VAR "ftmInstances"  = "num:i(count(PwmFtm/*))"!]
            [!IF "$ftmInstances > 0"!]
                [!LOOP "PwmFtm/*"!]
    {
                [!VAR "instanceId" = "substring-after(PwmHwInstance, '_')"!]
        /** @brief  The Id instance configured */
        [!"$instanceId"!]U,
        /** @brief  The type of ip instance configured */
        PWM_INSTANCE_FTM,
        /** @brief  Pointer to the ip instance configuration structure */
        (const void *)(&Ftm_Pwm_Ip[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_UserCfg[!"$instanceId"!])
    }[!IF "num:i($ftmInstances) > '1'"!],[!ENDIF!][!CR!]
                    [!VAR "ftmInstances"  = "num:i($ftmInstances) - 1"!]
                [!ENDLOOP!]
            [!ELSE!]
    {
         /** @brief  The Id instance configured */
        255U,
        /** @brief  The type of ip instance configured */
        PWM_INSTANCE_NONE,
        /** @brief  Pointer to the ip instance configuration structure */
        NULL_PTR
    }        
            [!ENDIF!]
        [!ELSEIF "$pwmFlexPwmSupported = 'true'"!]
            [!VAR "FlexPwmInstances"  = "num:i(count(FlexPwm/*))"!]
            [!IF "$FlexPwmInstances > 0"!]
                [!LOOP "FlexPwm/*"!]
    {
                [!VAR "instanceId" = "substring-after(FlexPwmModule, '_')"!]
        /** @brief  The Id instance configured */
        [!IF "$FlexPwmHwStartFrom0 = 'true'"!]
            [!"num:i($instanceId)"!]U,
        [!ELSE!]
            [!"num:i($instanceId - 1)"!]U,
        [!ENDIF!]
        /** @brief  The type of ip instance configured */
        PWM_INSTANCE_FLEXPWM,
        /** @brief  Pointer to the ip instance configuration structure */
        (const void *)(&FlexPwm_Ip[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_InstanceCfg_I[!"$instanceId"!])
    }[!IF "num:i($FlexPwmInstances) > '1'"!],[!ENDIF!][!CR!]
                    [!VAR "FlexPwmInstances"  = "num:i($FlexPwmInstances) - 1"!]
                [!ENDLOOP!]
            [!ELSE!]
    {
         /** @brief  The Id instance configured */
        255U,
        /** @brief  The type of ip instance configured */
        PWM_INSTANCE_NONE,
#if (PWM_FLEXPWM_USED == STD_ON)           
        /** @brief  Pointer to the ip instance configuration structure */
        NULL_PTR  
#endif        
    }
            [!ENDIF!]
        [!ELSE!]
    {
        /** @brief  The Id instance configured */
        255U,
        /** @brief  The type of ip instance configured */
        PWM_INSTANCE_NONE
    }        
        [!ENDIF!]
};
#endif
    [!ENDIF!]

[!ENDIF!]
/*============================== High level configuration ===================================*/
[!IF "$MulticoreEnabled = 1"!]
    [!LOOP "../PwmGeneral/PwmEcucPartitionRef/*"!]
        [!NOCODE!]
            [!VAR "PartitionIndex" = "@index"!]

            [!VAR "PwmEcucPartitionRefName" = "node:value(.)"!]
            [!VAR "PwmEcucPartitionShortName" = "substring-after($PwmEcucPartitionRefName, '/')"!]
            [!VAR "PwmEcucPartitionShortName" = "substring-after($PwmEcucPartitionShortName, '/')"!]
            [!VAR "PwmEcucPartitionShortName" = "substring-after($PwmEcucPartitionShortName, '/')"!]
            [!VAR "PwmEcucPartitionShortName" = "substring-after($PwmEcucPartitionShortName, '/')"!]

            [!VAR "NumChannelInPartition" = "0"!]
            [!VAR "CurrentCoreId" = "0"!]

            /* Count channels in each module that is using for current partition */
            [!LOOP "./../../../PwmChannelConfigSet/PwmChannel/*"!]

                [!LOOP "./PwmChannelEcucPartitionRef/*"!]
                    [!VAR "PwmChannelEcucPartitionRefName" = "node:value(.)"!]

                    [!IF "$PwmChannelEcucPartitionRefName = $PwmEcucPartitionRefName"!]
                        [!VAR "NumChannelInPartition" = "$NumChannelInPartition + 1"!]
                    [!ENDIF!]
                [!ENDLOOP!]
            [!ENDLOOP!]

            /* Get core ID that current partition points to */
            [!LOOP "as:modconf('Os')[1]/OsApplication/*"!]
                [!IF "$PwmEcucPartitionRefName = node:value(./OsAppEcucPartitionRef)"!]
                    [!SELECT "node:ref(./OsApplicationCoreRef)"!]
                        [!VAR "CurrentCoreId" = "node:value(./EcucCoreId)"!]
                    [!ENDSELECT!]
                [!ENDIF!]
            [!ENDLOOP!]
        [!ENDNOCODE!]

/*================================== Partition [!"$PwmEcucPartitionShortName"!] ==================================*/
        [!IF "$NumChannelInPartition > 0"!]
/**
* @brief        PWM high level configuration structure
*
*/
            [!IF "((./../../../IMPLEMENTATION_CONFIG_VARIANT != 'VariantPostBuild') and (variant:size() > 1)) or (./../../../IMPLEMENTATION_CONFIG_VARIANT = 'VariantPostBuild')"!]
const Pwm_ConfigType Pwm_Config[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_[!"$PwmEcucPartitionShortName"!] =
            [!ELSE!]
const Pwm_ConfigType Pwm_Config_[!"$PwmEcucPartitionShortName"!] =
            [!ENDIF!]
{
    /** @brief  Core ID */
    (uint32)[!"$CurrentCoreId"!]U,
    /** @brief  Number of configured PWM channels */
    (Pwm_ChannelType)PWM[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PB_CFG_CHANNELS_COUNT_[!"text:toupper($PwmEcucPartitionShortName)"!],
    /** @brief  Pointer to array of PWM channels */
    &Pwm_Channels[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PB_[!"$PwmEcucPartitionShortName"!],
            [!IF "(ecu:has('Pwm.ExclusiveHwInstance') = 'true') and (ecu:get('Pwm.ExclusiveHwInstance') = 'true')"!]
#if (PWM_HW_INSTANCE_USED == STD_ON)
    /** @brief  Number of Pwm configured instances */
    (Pwm_InstanceType)PWM[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PB_CFG_INSTANCES_COUNT_[!"text:toupper($PwmEcucPartitionShortName)"!],
    /** @brief  Pointer to the list of Pwm configured channels */
    &Pwm_Instances[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PB_[!"$PwmEcucPartitionShortName"!],
#endif
            [!ENDIF!]
    &Pwm_LogicalToPartitionMap[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PB_[!"$PwmEcucPartitionShortName"!],
            [!IF "./../../../PwmGeneral/PwmNotificationSupported"!]
#if (PWM_NOTIFICATION_SUPPORTED == STD_ON)
    /** @brief  Hardware to logic channel map. Array containing a number of elements
                equal to total number of available channels on all IP. */
    {
                [!IF "ecu:has('Pwm.FtmSupported') and (ecu:get('Pwm.FtmSupported') = 'true')"!]
                    [!FOR "idx" = "0" TO "$numModules -1"!]
                [!CALL "GenerateFtmHwToLogicMap", "paramFtmModule" = "$idx", "partitionRefName" = "$PwmEcucPartitionRefName"!]
        [!"$OutVarHwToLogicComment"!]
        [!"$OutVarHwToLogicArray"!][!IF "$idx < $numModules -1"!],[!CR!][!ENDIF!]
                    [!ENDFOR!][!IF "ecu:has('Pwm.FlexioSupported') and (ecu:get('Pwm.FlexioSupported') = 'true')"!],[!ENDIF!][!CR!]
                [!ENDIF!]
                [!IF "ecu:has('Pwm.EmiosSupported') and (ecu:get('Pwm.EmiosSupported') = 'true')"!]
                    [!FOR "idx" = "0" TO "$numEmiosModules -1"!]
        [!CALL "GenerateEmiosHwToLogicMap", "paramEmiosModule" = "$idx"!]
                    [!ENDFOR!]
                [!ENDIF!]
                [!IF "ecu:has('Pwm.EtimerSupported') and (ecu:get('Pwm.EtimerSupported') = 'true')"!]
                    [!FOR "idx" = "0" TO "$numEtimerModules -1"!]
        [!CALL "GenerateEtimerHwToLogicMap", "paramEtimerModule" = "$idx"!]
                    [!ENDFOR!]
                [!ENDIF!]
                [!IF "ecu:has('Pwm.FlexioSupported') and (ecu:get('Pwm.FlexioSupported') = 'true')"!]
                    [!FOR "idx" = "0" TO "$numFlexioModules -1"!]
        [!CALL "GenerateFlexioHwToLogicMap", "paramFlexioModule" = "$idx"!]
                    [!ENDFOR!]
                [!ENDIF!]
                [!IF "ecu:has('Pwm.FlexPwmAvailable') and (ecu:get('Pwm.FlexPwmAvailable') = 'true')"!]
                    [!FOR "idx" = "0" TO "$numFlexPwmSubModules - 1"!]
                [!CALL "GenerateFlexPwmHwToLogicMap", "paramIdxSubModule" = "$idx"!]
        [!"$OutVarHwToLogicComment"!]
        [!"$OutVarHwToLogicArray"!][!IF "$idx < $numFlexPwmSubModules - 1"!],[!CR!][!ENDIF!]
                    [!ENDFOR!][!//
                [!ENDIF!]
    }
#endif
            [!ENDIF!]
};
        [!ELSE!]
/**
* @brief        No high level configuration structure for PWM for [!"$PwmEcucPartitionShortName"!]
*
*/
        [!ENDIF!]
    [!ENDLOOP!]

    [!IF "(./../IMPLEMENTATION_CONFIG_VARIANT != 'VariantPostBuild') and (variant:size() <= 1)"!]
const Pwm_ConfigType* const Pwm_Config[PWM[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PB_CONF_PARTITIONS] =
{

        [!NOCODE!]
            [!FOR "CurrentCoreId" = "0" TO "$numPartition - 1"!]
                [!VAR "HasCore" = "0"!]
                [!VAR "HasPartition" = "0"!]
                [!VAR "foundPartition" = "0"!]

                [!LOOP "../PwmGeneral/PwmEcucPartitionRef/*"!]
                    [!IF "num:i($foundPartition) = 0"!]
                        [!VAR "PwmEcucPartitionRefName" = "node:value(.)"!]
                        [!VAR "PwmEcucPartitionShortName" = "substring-after($PwmEcucPartitionRefName, '/')"!]
                        [!VAR "PwmEcucPartitionShortName" = "substring-after($PwmEcucPartitionShortName, '/')"!]
                        [!VAR "PwmEcucPartitionShortName" = "substring-after($PwmEcucPartitionShortName, '/')"!]
                        [!VAR "PwmEcucPartitionShortName" = "substring-after($PwmEcucPartitionShortName, '/')"!]
                        [!VAR "PartitionIndex" = "@index"!]

                        [!LOOP "as:modconf('Os')[1]/OsApplication/*"!]
                            [!IF "$PwmEcucPartitionRefName = node:value(./OsAppEcucPartitionRef)"!]
                                [!SELECT "node:ref(./OsApplicationCoreRef)"!]
                                    [!VAR "OsCoreId" = "node:value(./EcucCoreId)"!]

                                    [!IF "num:i($OsCoreId) = num:i($CurrentCoreId)"!]
                                        [!VAR "HasCore" = "1"!]

                                        [!LOOP "as:modconf('Pwm')[1]/PwmChannelConfigSet/PwmChannel/*"!]
                                            [!LOOP "./PwmChannelEcucPartitionRef/*"!]
                                                [!VAR "PwmChannelEcucPartitionRefName" = "node:value(.)"!]

                                                [!IF "$PwmChannelEcucPartitionRefName = $PwmEcucPartitionRefName"!]
                                                    [!VAR "HasPartition" = "1"!]
                                                    [!VAR "foundPartition" = "1"!]
                                                [!ENDIF!]
                                            [!ENDLOOP!]
                                        [!ENDLOOP!]
                                    [!ENDIF!]
                                [!ENDSELECT!]
                            [!ENDIF!]
                        [!ENDLOOP!]
                    [!ENDIF!]
                [!ENDLOOP!]

                [!IF "$HasCore = 1"!]
                    [!IF "$HasPartition = 1"!]
                        [!CODE!]
    /** @brief  Pointer to configuration structure of PWM for [!"$PwmEcucPartitionShortName"!] refered by core [!"num:i($CurrentCoreId)"!] */
    &Pwm_Config_[!"$PwmEcucPartitionShortName"!][!//
                        [!ENDCODE!]
                    [!ELSE!]
                        [!CODE!]
    /** @brief  No configuration structure of PWM refered by core [!"num:i($CurrentCoreId)"!] */
    NULL_PTR[!//
                        [!ENDCODE!]
                    [!ENDIF!]
                [!ELSE!]
                    [!CODE!]
    /** @brief  No configuration structure of PWM refered by core [!"num:i($CurrentCoreId)"!] */
    NULL_PTR[!//
                    [!ENDCODE!]
                [!ENDIF!]

                [!IF "$CurrentCoreId < $numPartition - 1"!][!CODE!],[!ENDCODE!][!ENDIF!][!CR!]
            [!ENDFOR!]
        [!ENDNOCODE!]
};
    [!ENDIF!]
[!ELSE!][!//
    [!IF "((./../IMPLEMENTATION_CONFIG_VARIANT != 'VariantPostBuild') and (variant:size() > 1)) or (./../IMPLEMENTATION_CONFIG_VARIANT = 'VariantPostBuild')"!]
const Pwm_ConfigType Pwm_Config[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!] =
    [!ELSE!]
const Pwm_ConfigType Pwm_Config =
    [!ENDIF!]
{
    /** @brief  Number of configured PWM channels */
    (Pwm_ChannelType)PWM[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PB_CFG_CHANNELS_COUNT,
    /** @brief  Pointer to array of PWM channels */
    &Pwm_Channels[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PB,
    [!IF "(ecu:has('Pwm.ExclusiveHwInstance') = 'true') and (ecu:get('Pwm.ExclusiveHwInstance') = 'true')"!]
#if (PWM_HW_INSTANCE_USED == STD_ON)
    /** @brief  Number of Pwm configured instances */
    (Pwm_InstanceType)PWM[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PB_CFG_INSTANCES_COUNT,
    /** @brief  Pointer to the list of Pwm configured channels */
    &Pwm_Instances[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PB,
#endif
    [!ENDIF!]
    [!IF "./../PwmGeneral/PwmNotificationSupported"!]
#if (PWM_NOTIFICATION_SUPPORTED == STD_ON)
    /** @brief  Hardware to logic channel map. Array containing a number of elements
                equal to total number of available channels on all IP. */
    {
        [!IF "ecu:has('Pwm.FtmSupported') and (ecu:get('Pwm.FtmSupported') = 'true')"!]
            [!FOR "idx" = "0" TO "$numModules -1"!]
                [!CALL "GenerateFtmHwToLogicMap", "paramFtmModule" = "$idx", "partitionRefName" = "'NULL'"!]
        [!"$OutVarHwToLogicComment"!]
        [!"$OutVarHwToLogicArray"!][!IF "$idx < $numModules -1"!],[!CR!][!ENDIF!]
            [!ENDFOR!][!IF "ecu:has('Pwm.FlexioSupported') and (ecu:get('Pwm.FlexioSupported') = 'true')"!],[!ENDIF!][!CR!]
        [!ENDIF!]
        [!IF "ecu:has('Pwm.EmiosSupported') and (ecu:get('Pwm.EmiosSupported') = 'true')"!]
            [!FOR "idx" = "0" TO "$numEmiosModules -1"!]
        [!CALL "GenerateEmiosHwToLogicMap", "paramEmiosModule" = "$idx"!]
            [!ENDFOR!]
        [!ENDIF!]
        [!IF "ecu:has('Pwm.EtimerSupported') and (ecu:get('Pwm.EtimerSupported') = 'true')"!]
            [!FOR "idx" = "0" TO "$numEtimerModules -1"!]
        [!CALL "GenerateEtimerHwToLogicMap", "paramEtimerModule" = "$idx"!]
            [!ENDFOR!]
        [!ENDIF!]
        [!IF "ecu:has('Pwm.FlexioSupported') and (ecu:get('Pwm.FlexioSupported') = 'true')"!]
            [!FOR "idx" = "0" TO "$numFlexioModules -1"!]
        [!CALL "GenerateFlexioHwToLogicMap", "paramFlexioModule" = "$idx"!]
            [!ENDFOR!]
        [!ENDIF!]
        [!IF "ecu:has('Pwm.FlexPwmAvailable') and (ecu:get('Pwm.FlexPwmAvailable') = 'true')"!]
            [!FOR "idx" = "0" TO "$numFlexPwmSubModules - 1"!]
                [!CALL "GenerateFlexPwmHwToLogicMap", "paramIdxSubModule" = "$idx"!]
        [!"$OutVarHwToLogicComment"!]
        [!"$OutVarHwToLogicArray"!][!IF "$idx < $numFlexPwmSubModules - 1"!],[!CR!][!ENDIF!]
            [!ENDFOR!][!//
        [!ENDIF!]
    }
#endif
    [!ENDIF!]
};
[!ENDIF!]
[!//
#define PWM_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Pwm_MemMap.h"
[!ENDSELECT!]


#ifdef __cplusplus
}
#endif

/** @} */

[!ENDCODE!]
