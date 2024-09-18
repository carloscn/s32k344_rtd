[!AUTOSPACING!]
[!// Section for macros used in this file
[!NOCODE!]
    [!MACRO "getPeriodInTicks", "instance", "subModule"!]
        [!NOCODE!]
            [!VAR "varPeriodMax" = "65534"!]
            [!VAR "valuePeriod" = "''"!]
            [!LOOP "../../../../PwmChannel/*"!]
                [!IF "contains(PwmHwChannel,'FlexPwm')"!]
                    [!VAR "insId" = "num:i(substring-after(node:ref(PwmHwChannel)/../../../../FlexPwmModule, '_'))"!]
                    [!VAR "subMod" = "num:i(substring-after(node:ref(PwmHwChannel)/../../FlexPwmSubModule, '_'))"!]
                    [!VAR "clockPrescaler" = "num:i(substring-after(node:ref(PwmHwChannel)/../../FlexPwmPrescaler, 'FLEXPWM_IP_DIV'))"!]
                    [!VAR "mcuClockRef" = "num:i(node:value(node:ref(./PwmMcuClockReferencePoint)/McuClockReferencePointFrequency))"!]
                    [!IF "($instance = $insId) and ($subModule = $subMod)"!]
                            [!IF "PwmPeriodInTicks"!]
                                [!VAR "valuePeriod" = "num:i(node:value(PwmPeriodDefault))"!]
                            [!ELSE!]
                                [!VAR "valuePeriod" = "num:i(node:value(PwmPeriodDefault) * ($mcuClockRef div $clockPrescaler))"!]
                            [!ENDIF!]
                          
                            [!IF "num:i($valuePeriod) > $varPeriodMax"!]
                                [!ERROR!]
[Error in variant: [!"variant:name()"!]] The configured period/ticks for PwmChannelId '[!"PwmChannelId"!]' is [!"$valuePeriod"!] ticks which is larger than the maximum allowed value for the period, which is [!"num:i($varPeriodMax)"!] ticks
The plugin performs the conversion from Period to ticks if requested.
To solve this problem change the configured Period/ticks or change the Pwm clock tree settings.
                                [!ENDERROR!]
                            [!ENDIF!]
                    [!ENDIF!]
                [!ENDIF!]
            [!ENDLOOP!]
        [!ENDNOCODE!]
    [!ENDMACRO!]

    [!MACRO "getParamAsr", "instance", "subModule", "channel"!]
        [!NOCODE!]
            [!VAR "valuePeriod" = "''"!]
            [!VAR "valueDutyCycle" = "''"!]
            [!VAR "valuePolarity" = "''"!]
            [!VAR "checkValid" = "0"!]
            [!LOOP "./../../../../../../PwmChannel/*"!]
                [!IF "contains(PwmHwChannel,'FlexPwm')"!]
                    [!VAR "instanceIdx" = "num:i(substring-after(node:ref(PwmHwChannel)/../../../../FlexPwmModule, '_'))"!]
                    [!VAR "subMod" = "num:i(substring-after(node:ref(PwmHwChannel)/../../FlexPwmSubModule, '_'))"!]
                    [!VAR "channelIdx" = "(substring-after(node:ref(PwmHwChannel)/FlexPwmChannel, 'FLEXPWM_IP_'))"!]
                    [!VAR "clockPrescaler" = "num:i(substring-after(node:ref(PwmHwChannel)/../../FlexPwmPrescaler, 'FLEXPWM_IP_DIV'))"!]
                    [!VAR "mcuClockRef" = "num:i(node:value(node:ref(./PwmMcuClockReferencePoint)/McuClockReferencePointFrequency))"!]
                    [!IF "($instance = $instanceIdx) and ($subModule = $subMod) and ($channel = $channelIdx)"!]
                        [!VAR "checkValid" = "1"!]
                        [!IF "PwmPeriodInTicks"!]
                            [!VAR "valuePeriod" = "num:i(node:value(PwmPeriodDefault))"!]
                        [!ELSE!]
                            [!VAR "valuePeriod" = "num:i(node:value(PwmPeriodDefault) * ($mcuClockRef div $clockPrescaler))"!]
                        [!ENDIF!]
                        [!VAR "valueDutyCycle" = "num:i(node:value(PwmDutycycleDefault))"!]
                        [!VAR "valueDutyCycle" = "num:i(($valuePeriod * $valueDutyCycle) div 32768)"!]

                        [!VAR "valuePolarity" = "substring-after(node:value(PwmPolarity), '_')"!]
                        [!VAR "valuePolarity" = "concat('FLEXPWM_IP_POL_', $valuePolarity)"!]
                    [!ENDIF!]
                [!ENDIF!]
            [!ENDLOOP!]
            [!IF "$checkValid = 0"!]
                [!ERROR!] "FLEXPWM_[!"$instance"!]_SUB_[!"$subModule"!]_[!"$channel"!] did not reference by any channels in PwmChannel list, Please remove this channel in FlexPwm channels list"[!ENDERROR!]
            [!ENDIF!]
        [!ENDNOCODE!]
    [!ENDMACRO!]

    [!MACRO "GetReloadTypes"!]
        [!VAR "ReloadTypes" = "'FLEXPWM_IP_RELOAD_'"!]
        [!IF "./FullCycleReload"!]
            [!IF "./HalfCycleReload"!]
                [!VAR "Reload" = "'FULL_HALF'"!]
            [!ELSE!]  
                [!VAR "Reload" = "'FULL'"!]
            [!ENDIF!]
        [!ELSE!]
            [!IF "./HalfCycleReload"!]
                [!VAR "Reload" = "'HALF'"!]
            [!ELSE!]  
                [!VAR "Reload" = "'IMMEDIATE'"!]
            [!ENDIF!]
        [!ENDIF!]
        [!VAR "ReloadTypes" = "concat($ReloadTypes, $Reload)"!]
    [!ENDMACRO!]

    [!MACRO "GetFaultChannelsCfg"!]
        [!VAR "FaultLevelValueAll" = "0"!]
        [!VAR "AutomaticFaultClrAll" = "0"!]
        [!VAR "FaultSafetyModeAll" = "0"!]
        [!VAR "FullCycleAll" = "0"!]
        [!VAR "FaultInterruptAll" = "0"!]
        [!VAR "FaultNotifAll" = "'{'"!]
        [!LOOP "./FlexPwmFaultChannelSettings/*"!]
            [!VAR "FaultChannel" = "substring-after(name(.), '_')"!]
            [!IF "node:value(./FlexPwmFaultLevel) = 'LOW'"!]
                [!VAR "FaultLevelValue" = "0"!]
            [!ELSE!]
                [!VAR "FaultLevelValue" = "1"!]
            [!ENDIF!]
            [!IF "(./FlexPwmAutomaticFaultClearing)"!]
                [!VAR "AutomaticFaultClr" = "1"!]
            [!ELSE!]
                [!VAR "AutomaticFaultClr" = "0"!]
            [!ENDIF!]
            [!IF "(./FlexPwmFaultSafetyMode)"!]
                [!VAR "FaultSafetyMode" = "1"!]
            [!ELSE!]
                [!VAR "FaultSafetyMode" = "0"!]
            [!ENDIF!]
            [!IF "(./FlexPwmFullCycle)"!]
                [!VAR "FullCycle" = "1"!]
            [!ELSE!]
                [!VAR "FullCycle" = "0"!]
            [!ENDIF!]
            [!IF "(./FlexPwmFaultInterruptEn)"!]
                [!VAR "FaultInterrupt" = "1"!]
            [!ELSE!]
                [!VAR "FaultInterrupt" = "0"!]
            [!ENDIF!]
            [!IF "(./../../FlexPwmFaultFunctionality = 'true') and (./../../../../../PwmGeneral/PwmNotificationSupported = 'true')"!]
                [!IF "(./FlexPwmFaultInterruptEn = 'true')"!]
                    [!VAR "FaultNotif" = "./FlexPwmFaultNotification"!]
                [!ELSE!]
                    [!VAR "FaultNotif" = "'NULL_PTR'"!]
                [!ENDIF!]
            [!ELSE!]
                [!VAR "FaultNotif" = "'NULL_PTR'"!]
            [!ENDIF!]
            [!IF "num:i($FaultChannel) != 0"!]
                [!VAR "FaultNotif" = "concat(', ', $FaultNotif)"!]
            [!ENDIF!]
            [!FOR "j" = "1" TO "num:i($FaultChannel)"!]
                [!VAR "FaultLevelValue" = "num:i($FaultLevelValue) * 2"!]
                [!VAR "AutomaticFaultClr" = "num:i($AutomaticFaultClr) * 2"!]
                [!VAR "FaultSafetyMode" = "num:i($FaultSafetyMode) * 2"!]
                [!VAR "FullCycle" = "num:i($FullCycle) * 2"!]
                [!VAR "FaultInterrupt" = "num:i($FaultInterrupt) * 2"!]
            [!ENDFOR!]
            [!VAR "FaultLevelValueAll" = "$FaultLevelValueAll + $FaultLevelValue"!]
            [!VAR "AutomaticFaultClrAll" = "$AutomaticFaultClrAll + $AutomaticFaultClr"!]
            [!VAR "FaultSafetyModeAll" = "$FaultSafetyModeAll + $FaultSafetyMode"!]
            [!VAR "FullCycleAll" = "$FullCycleAll + $FullCycle"!]
            [!VAR "FaultInterruptAll" = "$FaultInterruptAll + $FaultInterrupt"!]
            [!VAR "FaultNotifAll" = "concat($FaultNotifAll, $FaultNotif)"!]
        [!ENDLOOP!]
        [!VAR "FaultNotifAll" = "concat($FaultNotifAll, '}')"!]
    [!ENDMACRO!]
    
    [!MACRO "GetDisableOutputOnFault"!]
        [!VAR "DisableOutputOnFault" = "0"!]
        [!IF "(./FlexPwmChannelFaultSettings/FlexPwmDisableOutputOnFault0)"!]
            [!VAR "DisableOutputOnFault0" = "1"!]
        [!ELSE!]
            [!VAR "DisableOutputOnFault0" = "0"!]
        [!ENDIF!]
        [!IF "(./FlexPwmChannelFaultSettings/FlexPwmDisableOutputOnFault1)"!]
            [!VAR "DisableOutputOnFault1" = "2"!]
        [!ELSE!]
            [!VAR "DisableOutputOnFault1" = "0"!]
        [!ENDIF!]
        [!IF "(./FlexPwmChannelFaultSettings/FlexPwmDisableOutputOnFault2)"!]
            [!VAR "DisableOutputOnFault2" = "4"!]
        [!ELSE!]
            [!VAR "DisableOutputOnFault2" = "0"!]
        [!ENDIF!]
        [!IF "(./FlexPwmChannelFaultSettings/FlexPwmDisableOutputOnFault3)"!]
            [!VAR "DisableOutputOnFault3" = "8"!]
        [!ELSE!]
            [!VAR "DisableOutputOnFault3" = "0"!]
        [!ENDIF!]
        [!VAR "DisableOutputOnFault" = "$DisableOutputOnFault0 + $DisableOutputOnFault1 + $DisableOutputOnFault2 + $DisableOutputOnFault3"!]
    [!ENDMACRO!]
    
    [!MACRO "GetInterruptChannelCb", "instance", "subModule", "channel"!]
        [!VAR "NumSub" = "num:i(ecu:get('Pwm.FlexPwmHwSubModulesNum'))"!]
        [!VAR "NumChInSub" = "num:i(ecu:get('Pwm.FlexPwmHwChannelInSubModuleNum'))"!]
        [!VAR "FuctionCb" = "''"!]
        [!VAR "ParamCb" = "''"!]
        [!VAR "InterruptType" = "./FlexPwmChInterrupt"!]        
        [!IF "$channel = 'PWMX'"!]
            [!VAR "channelId" = "0"!]
        [!ELSEIF "$channel = 'PWMA'"!]
            [!VAR "channelId" = "1"!]
        [!ELSEIF "$channel = 'PWMB'"!]
            [!VAR "channelId" = "2"!]
        [!ENDIF!]
            
        [!VAR "FlexPwmHwStartFrom0" = "'false'"!]
        [!IF "ecu:has('Pwm.FlexPwmHwModules.List') and text:contains(ecu:get('Pwm.FlexPwmHwModules.List'), 'FlexPwm_0')"!]
            [!VAR "FlexPwmHwStartFrom0" = "'true'"!]
        [!ENDIF!]

        [!IF "(./../../../../../../../PwmGeneral/PwmNotificationSupported)"!]
            [!IF "$InterruptType = 'FLEXPWM_IP_COMPARE_INT'"!]
                [!VAR "FuctionCb" = "'&Pwm_Ipw_FlexPwmNotification'"!]
                [!IF "$FlexPwmHwStartFrom0 = 'true'"!]
                    [!VAR "ParamCb" = "num:i(($instance) * $NumSub * $NumChInSub + $subModule * 3 + $channelId)"!]
                [!ELSE!]
                    [!VAR "ParamCb" = "num:i(($instance - 1) * $NumSub * $NumChInSub + $subModule * 3 + $channelId)"!]
                [!ENDIF!]

                [!VAR "ParamCb" = "concat($ParamCb, 'U')"!]
            [!ELSE!]
                [!VAR "FuctionCb" = "'NULL_PTR'"!]    
                [!VAR "ParamCb" = "'0U'"!]  
            [!ENDIF!]
        [!ELSE!]
            [!IF "$InterruptType = 'FLEXPWM_IP_COMPARE_INT'"!]
                [!VAR "FuctionCb" = "./FlexPwmChIrqCallback/FlexPwmChIrqFunctionCallback"!]    
                [!VAR "ParamCb" = "./FlexPwmChIrqCallback/FlexPwmChIrqParameterCallback"!]   
            [!ELSE!]
                [!VAR "FuctionCb" = "'NULL_PTR'"!]    
                [!VAR "ParamCb" = "'NULL_PTR'"!]  
            [!ENDIF!]
        [!ENDIF!]
    [!ENDMACRO!]
    
    [!MACRO "GetInstanceParam"!]
        [!VAR "OutputEnAll" = "0"!]
        [!VAR "MctrlRunAll" = "0"!]
        [!LOOP "./FlexPwmSubModules/*"!]
            [!VAR "SubModule" = "substring-after(./FlexPwmSubModule,'SubModule_')"!]
            [!VAR "MctrlRun" = "1"!]
            [!FOR "j" = "1" TO "num:i($SubModule)"!]
                [!VAR "MctrlRun" = "num:i($MctrlRun) * 2"!]
            [!ENDFOR!] 
            [!VAR "MctrlRunAll" = "$MctrlRunAll + $MctrlRun"!]
            [!VAR "OutputEn" = "0"!]
            [!VAR "RelationChBToChA" = "./FlexPwmIndependent"!]
            [!LOOP "./FlexPwmChannels/*"!]
                [!VAR "channelCfgName" = "substring-after(./FlexPwmChannel,'FLEXPWM_IP_')"!]
                [!IF "$channelCfgName = 'PWMX'"!]
                    [!VAR "shift" = "1"!]
                [!ELSEIF "$channelCfgName = 'PWMB'"!]
                    [!VAR "shift" = "16"!]
                [!ELSEIF "$channelCfgName = 'PWMA'"!]
                    [!IF "$RelationChBToChA = 'FLEXPWM_IP_COMPLEMENTARY'"!]
                        [!VAR "shift" = "272"!]
                    [!ELSE!]
                        [!VAR "shift" = "256"!]
                    [!ENDIF!]
                [!ENDIF!]
                [!VAR "OutputEn" = "num:i($shift) * num:i($MctrlRun)"!]
                [!VAR "OutputEnAll" = "num:i($OutputEnAll) + num:i($OutputEn)"!]
            [!ENDLOOP!]
        [!ENDLOOP!]
    [!ENDMACRO!]
[!ENDNOCODE!]
[!CODE!]
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
*   @file       FlexPwm_Ip_PBcfg.c
*
*   @addtogroup flexpwm_ip FlexPwm Pwm IPL
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
#include "FlexPwm_Ip_Cfg.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/

#define FLEXPWM_IP[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PB_CFG_VENDOR_ID_C                       43
#define FLEXPWM_IP[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PB_CFG_AR_RELEASE_MAJOR_VERSION_C        4
#define FLEXPWM_IP[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PB_CFG_AR_RELEASE_MINOR_VERSION_C        7
#define FLEXPWM_IP[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PB_CFG_AR_RELEASE_REVISION_VERSION_C     0
#define FLEXPWM_IP[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PB_CFG_SW_MAJOR_VERSION_C                3
#define FLEXPWM_IP[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PB_CFG_SW_MINOR_VERSION_C                0
#define FLEXPWM_IP[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PB_CFG_SW_PATCH_VERSION_C                0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if source file and FlexPwm_Ip_Cfg.h file are of the same vendor */
#if (FLEXPWM_IP[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PB_CFG_VENDOR_ID_C != FLEXPWM_IP_CFG_VENDOR_ID)
    #error "Vendor IDs of FlexPwm_Ip[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg.c and FlexPwm_Ip_Cfg.h are different."
#endif

/* Check if source file and FlexPwm_Ip_Cfg.h file are of the same AUTOSAR version */
#if ((FLEXPWM_IP[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PB_CFG_AR_RELEASE_MAJOR_VERSION_C    != FLEXPWM_IP_CFG_AR_RELEASE_MAJOR_VERSION) || \
     (FLEXPWM_IP[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PB_CFG_AR_RELEASE_MINOR_VERSION_C    != FLEXPWM_IP_CFG_AR_RELEASE_MINOR_VERSION) || \
     (FLEXPWM_IP[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PB_CFG_AR_RELEASE_REVISION_VERSION_C != FLEXPWM_IP_CFG_AR_RELEASE_REVISION_VERSION))
    #error "AUTOSAR version numbers of FlexPwm_Ip[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg.c and FlexPwm_Ip_Cfg.h are different."
#endif

/* Check if source file and FlexPwm_Ip_Cfg.h file are of the same Software version */
#if ((FLEXPWM_IP[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PB_CFG_SW_MAJOR_VERSION_C != FLEXPWM_IP_CFG_SW_MAJOR_VERSION)  || \
     (FLEXPWM_IP[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PB_CFG_SW_MINOR_VERSION_C != FLEXPWM_IP_CFG_SW_MINOR_VERSION)  || \
     (FLEXPWM_IP[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PB_CFG_SW_PATCH_VERSION_C != FLEXPWM_IP_CFG_SW_PATCH_VERSION))
    #error "Software version numbers of FlexPwm_Ip[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg.c and FlexPwm_Ip_Cfg.h are different."
#endif

/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/


/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/


/*==================================================================================================
*                                      LOCAL CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                      LOCAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/
#define PWM_START_SEC_CODE
#include "Pwm_MemMap.h"

[!LOOP "as:modconf('Pwm')[1]/PwmChannelConfigSet/FlexPwm/*"!]
    [!IF "(./FlexPwmFaultFunctionality = 'true') and (./../../../PwmGeneral/PwmNotificationSupported = 'true')"!]
        [!LOOP "./FlexPwmFaultChannelSettings/*"!]
            [!VAR "faultCh" = "node:name(.)"!]
            [!IF "(./FlexPwmFaultInterruptEn = 'true')"!]
                [!IF "((./FlexPwmFaultNotification) != 'NULL_PTR') and ((./FlexPwmFaultNotification) != 'NULL') and ((./FlexPwmFaultNotification) != '"NULL"')"!]
                    [!CODE!]
/** @brief  Prototypes of Fault notification [!"$faultCh"!] callback */
extern void [!"./FlexPwmFaultNotification"!](void);

                    [!ENDCODE!]
                [!ENDIF!]
            [!ENDIF!]
        [!ENDLOOP!]
    [!ENDIF!]
[!ENDLOOP!]
[!LOOP "as:modconf('Pwm')[1]/PwmChannelConfigSet/FlexPwm/*"!]
    [!VAR "HwInstance" = "substring-after(./FlexPwmModule,'FlexPwm_')"!]
    [!LOOP "./FlexPwmSubModules/*"!]
        [!VAR "SubModule" = "substring-after(./FlexPwmSubModule,'SubModule_')"!]
        [!VAR "NumOfChannelUsedInterrupt" = "0"!]
        [!LOOP "./FlexPwmChannels/*"!]
            [!VAR "channelName" = "substring-after(./FlexPwmChannel,'FLEXPWM_IP_')"!]
            [!IF "(./FlexPwmChInterrupt = 'FLEXPWM_IP_COMPARE_INT') and (./../../../../../../../PwmGeneral/PwmNotificationSupported = 'true')"!]
                [!VAR "NumOfChannelUsedInterrupt" = "NumOfChannelUsedInterrupt + 1"!]
                [!CODE!]
/** @brief  Prototypes of FlexPwm notification callback */
extern void Pwm_Ipw_FlexPwmNotification(uint8 Channel);
                [!ENDCODE!]
                [!BREAK!]
            [!ENDIF!]
        [!ENDLOOP!]
        [!IF "$NumOfChannelUsedInterrupt = 1"!]
            [!BREAK!]
        [!ENDIF!]
    [!ENDLOOP!]
    [!IF "$NumOfChannelUsedInterrupt = 1"!]
        [!BREAK!]
    [!ENDIF!]    
[!ENDLOOP!]

#define PWM_STOP_SEC_CODE
#include "Pwm_MemMap.h"
/*==================================================================================================
*                                      GLOBAL VARIABLES
==================================================================================================*/
#ifndef FLEXPWM_IP_PRECOMPILE_SUPPORT
#define PWM_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Pwm_MemMap.h"

[!LOOP "./PwmChannelConfigSet/FlexPwm/*"!]
    [!VAR "instanceId" = "substring-after(./FlexPwmModule, '_')"!]
/*================================================================================================*/

/* FlexPwm instance [!"$instanceId"!] fault channels configuration */
const FlexPwm_Ip_FaultChCfgTypes FlexPwm_Ip[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_FaultCfg_I[!"$instanceId"!] =
{
[!CALL "GetFaultChannelsCfg"!]
    /* FaultLevel */              [!"num:i($FaultLevelValueAll)"!]U,
    /* AutoFaultClearing */       [!"num:i($AutomaticFaultClrAll)"!]U,
    /* FaultSafetyMode */         [!"num:i($FaultSafetyModeAll)"!]U,
    /* FullCycle */               [!"num:i($FullCycleAll)"!]U,  
    /* FaultInterruptEn */        [!"num:i($FaultInterruptAll)"!]U,
    /* FaultNotification */       [!"$FaultNotifAll"!]
};

    [!LOOP "./FlexPwmSubModules/*"!]
        [!VAR "SubModule" = "substring-after(./FlexPwmSubModule,'SubModule_')"!]       
        [!LOOP "./FlexPwmChannels/*"!]
            [!VAR "channelCfgName" = "substring-after(./FlexPwmChannel,'FLEXPWM_IP_')"!]
            [!IF "./FlexPwm_CTU_Trigger = 'FLEXPWM_IP_NO_TRIGGER'"!]
                [!VAR "OutputTrig" = "./FlexPwm_CTU_Trigger"!]
            [!ELSE!]
                [!VAR "CfgName" = "substring-after(./FlexPwmChannel,'FLEXPWM_IP_PWM')"!]
                [!VAR "OutputTrig" = "concat(./FlexPwm_CTU_Trigger, '_', $CfgName)"!]
            [!ENDIF!]
/* FlexPwm instance [!"$instanceId"!] subModule [!"$SubModule"!] channel [!"$channelCfgName"!] configuration */
const FlexPwm_Ip_ChannelCfgTypes FlexPwm_Ip[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_ChannelCfg_I[!"$instanceId"!]_S[!"$SubModule"!]_[!"$channelCfgName"!] =
{
[!CALL "getParamAsr", "instance"="$instanceId", "subModule"="$SubModule", "channel"="$channelCfgName"!]
[!CALL "GetDisableOutputOnFault"!]
[!CALL "GetInterruptChannelCb", "instance"="$instanceId", "subModule"="$SubModule", "channel"="$channelCfgName"!]
    /* ChannelId */               [!"./FlexPwmChannel"!],
    /* Polarity */                [!"$valuePolarity"!],
    /* DutyCycle */               [!"$valueDutyCycle"!]U,
    /* PhaseShiftTicks */         [!"num:i(./FlexPwmPhaseShiftTicks)"!]U,
    /* OutputTrig */              [!"$OutputTrig"!],
    /* FaultState */              [!"(./FlexPwmFaultOutputState)"!],
    /* DisOutputFault */          [!"num:i($DisableOutputOnFault)"!]U,
    /* InterruptType */           [!"./FlexPwmChInterrupt"!],
    /* ChannelCb */               {
        /* CbFunction */             [!"$FuctionCb"!],
        /* CbParameter */            [!"$ParamCb"!]
                                  }
};

        [!ENDLOOP!]
/* FlexPwm instance [!"$instanceId"!] subModule [!"$SubModule"!] channels configuration array */
const FlexPwm_Ip_ChannelCfgTypes * const FlexPwm_Ip[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_ChannelCfg_I[!"$instanceId"!]_S[!"$SubModule"!]_Array[[!"num:i(count(./FlexPwmChannels/*))"!]U] =
{
        [!VAR "counter" = "num:i(count(./FlexPwmChannels/*))"!]
        [!LOOP "./FlexPwmChannels/*"!]
            [!VAR "channelName" = "substring-after(./FlexPwmChannel,'FLEXPWM_IP_')"!]
    &FlexPwm_Ip[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_ChannelCfg_I[!"$instanceId"!]_S[!"$SubModule"!]_[!"$channelName"!][!IF "num:i($counter) > '1'"!],[!ENDIF!][!CR!]
            [!VAR "counter" = "$counter - 1"!]
        [!ENDLOOP!]
};

    [!ENDLOOP!]
    [!LOOP "./FlexPwmSubModules/*"!]
        [!VAR "SubModule" = "substring-after(./FlexPwmSubModule,'SubModule_')"!]
        [!IF "./FlexPwmDebugEnable"!][!VAR "Debug" = "'1U'"!][!ELSE!][!VAR "Debug" = "'0U'"!][!ENDIF!]      
/* FlexPwm instance [!"$instanceId"!] subModule [!"$SubModule"!] SubModule configuration */
const FlexPwm_Ip_SubModuleCfgTypes FlexPwm_Ip[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_SubModCfg_I[!"$instanceId"!]_S[!"$SubModule"!] =
{
[!CALL "getPeriodInTicks", "instance"="$instanceId", "subModule"="$SubModule"!]
[!CALL "GetReloadTypes"!]
    /* SubModuleId */              [!"num:i($SubModule)"!]U,
    /* ClkSource */                [!"./FlexPwmClockSel"!],
    /* InitControl */              [!"./FlexPwmInitControlSrc"!],
    /* Prescaler */                [!"./FlexPwmPrescaler"!],
    /* PrescalerAlt */             [!"./FlexPwmPrescaler_Alternate"!],
    /* ReloadSrc */                [!"./ReloadSrcSelect"!],
    /* Reload */                   [!"$ReloadTypes"!],
    /* LoadFrq */                  [!"./ReloadFrequency"!],
    /* ForceSrc */                 [!"./ForceOutSelect"!],
    /* ChPair */                   [!"./FlexPwmIndependent"!],
    /* SigPwm */                   [!"./FlexPwmCapabilities"!],
    /* InitVal */                  [!"num:i(./FlexPwmInitVal)"!]U,
    /* CompSrc */                  [!"./FlexPwmPolarityPair"!],
    /* DeadTimeCount0 */           [!"./FlexPwmDeadTimeCount0"!]U,
    /* DeadTimeCount1 */           [!"./FlexPwmDeadTimeCount1"!]U,
    /* DebugModeEnable */          [!"$Debug"!],
    /* ChannelCfgArray */          FlexPwm_Ip[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_ChannelCfg_I[!"$instanceId"!]_S[!"$SubModule"!]_Array,
    /* NumChannelCfg */            [!"num:i(count(./FlexPwmChannels/*))"!]U,
    /* Period */                   [!"$valuePeriod"!]U
};

    [!ENDLOOP!]
/* FlexPwm instance [!"$instanceId"!] SubModule configuration array */
const FlexPwm_Ip_SubModuleCfgTypes * const FlexPwm_Ip[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_SubModCfg_I[!"$instanceId"!]_Array[[!"num:i(count(./FlexPwmSubModules/*))"!]U] =
{
    [!VAR "counter" = "num:i(count(./FlexPwmSubModules/*))"!]
    [!LOOP "./FlexPwmSubModules/*"!]
        [!VAR "SubModule" = "substring-after(./FlexPwmSubModule,'SubModule_')"!]
    &FlexPwm_Ip[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_SubModCfg_I[!"$instanceId"!]_S[!"$SubModule"!][!IF "num:i($counter) > '1'"!],[!ENDIF!][!CR!]
        [!VAR "counter" = "$counter - 1"!]
    [!ENDLOOP!]
};

[!CALL "GetInstanceParam"!]
/* FlexPwm instance [!"$instanceId"!] Configuration*/    
const FlexPwm_Ip_InstanceCfgTypes FlexPwm_Ip[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_InstanceCfg_I[!"$instanceId"!] =
{
    /* OutputEnable */               [!"num:i($OutputEnAll)"!]U,
    /* MasterControlRun */           [!"num:i($MctrlRunAll)"!]U,
    /* FaultFunctionalityEnable */   [!"text:toupper(./FlexPwmFaultFunctionality)"!],
    /* FaultGlitchStretchEnable */   [!"text:toupper(./FlexPwmFaultFilterSettings/FlexPwmFaultGlitchStretchEnable)"!],
    /* FaultFilterCounter */         [!"num:i(./FlexPwmFaultFilterSettings/FlexPwmFaultFilterCounter)"!]U,
    /* FaultFilterPeriod */          [!"num:i(./FlexPwmFaultFilterSettings/FlexPwmFaultFilterPeriod)"!]U,
    /* NoCombinationalPath */        [!"num:i(./FlexPwmFaultFilterSettings/FlexPwmFaultCombinationalPath)"!]U,
    /* FaultChCfg */                 &FlexPwm_Ip[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_FaultCfg_I[!"$instanceId"!],
    /* SubModuleCfgArray */          FlexPwm_Ip[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_SubModCfg_I[!"$instanceId"!]_Array,
    /* NumSubModuleCfg */            [!"num:i(count(./FlexPwmSubModules/*))"!]U
};

[!ENDLOOP!]    

#define PWM_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Pwm_MemMap.h"
#endif  /* FLEXPWM_IP_PRECOMPILE_SUPPORT */

#ifdef __cplusplus
}
#endif

/** @} */

[!ENDCODE!]
