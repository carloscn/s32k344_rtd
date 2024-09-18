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
*
*   NXP Confidential. This software is owned or controlled by NXP and may only be
*   used strictly in accordance with the applicable license terms. By expressly
*   accepting such terms or by downloading, installing, activating and/or otherwise
*   using the software, you are agreeing that you have read, and that you agree to
*   comply with and are bound by, such license terms. If you do not agree to be
*   bound by the applicable license terms, then you may not retain, install,
*   activate or otherwise use the software.
==================================================================================================*/


#ifndef WDG_IPW_CFG_DEFINES_H
#define WDG_IPW_CFG_DEFINES_H

/**
*   @file
*
*   @addtogroup  Wdg
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
[!NOCODE!]
[!INDENT "0"!]
[!VAR "isSwtAvailable" = "0"!]
[!VAR "isAeWdogAvailable" = "0"!]
[!FOR "i" = "0" TO "num:i(ecu:get('Wdg.Num.Of.Instances'))-1"!]
    [!IF "num:i($i) > 0"!]
        [!VAR "xPathModule" = "concat('ASPathDataOfSchema:/Wdg_43_Instance',$i,'_','TS_T40D34M30I0R0/Wdg')"!]
    [!ELSE!]
        [!VAR "xPathModule" = "concat('ASPathDataOfSchema:/','TS_T40D34M30I0R0/Wdg')"!]
    [!ENDIF!]
    [!IF "ecu:list('Wdg.WdgInstance')[$i + 1] ='AEWDOG'"!]
        [!IF "$isAeWdogAvailable = 0"!]
            [!VAR "isAeWdogAvailable" = "1"!]
            [!CODE!]#include "AeWdog_Ip_Cfg_Defines.h"[!ENDCODE!][!CR!]
        [!ENDIF!]
    [!ELSEIF "contains(ecu:list('Wdg.WdgInstance')[$i + 1], 'SWT')"!]
        [!IF "$isSwtAvailable = 0"!]
            [!VAR "isSwtAvailable" = "1"!]
            [!CODE!]#include "Swt_Ip_Cfg_Defines.h"[!ENDCODE!][!CR!]
        [!ENDIF!]
    [!ENDIF!]
[!ENDFOR!]
[!ENDINDENT!]
[!ENDNOCODE!][!//
/*==================================================================================================
                                SOURCE FILE VERSION INFORMATION
==================================================================================================*/

#define WDG_IPW_CFG_DEFINES_VENDOR_ID                    43
#define WDG_IPW_CFG_DEFINES_AR_RELEASE_MAJOR_VERSION     4
#define WDG_IPW_CFG_DEFINES_AR_RELEASE_MINOR_VERSION     7
#define WDG_IPW_CFG_DEFINES_AR_RELEASE_REVISION_VERSION  0
#define WDG_IPW_CFG_DEFINES_SW_MAJOR_VERSION             3
#define WDG_IPW_CFG_DEFINES_SW_MINOR_VERSION             0
#define WDG_IPW_CFG_DEFINES_SW_PATCH_VERSION             0

/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/

[!NOCODE!]
[!INDENT "0"!]
[!VAR "isSwtAvailable" = "0"!]
[!VAR "isAeWdogAvailable" = "0"!]
[!FOR "i" = "0" TO "num:i(ecu:get('Wdg.Num.Of.Instances'))-1"!]
    [!IF "num:i($i) > 0"!]
        [!VAR "xPathModule" = "concat('ASPathDataOfSchema:/Wdg_43_Instance',$i,'_','TS_T40D34M30I0R0/Wdg')"!]
    [!ELSE!]
        [!VAR "xPathModule" = "concat('ASPathDataOfSchema:/','TS_T40D34M30I0R0/Wdg')"!]
    [!ENDIF!]
    [!IF "node:exists($xPathModule)"!]
        [!IF "ecu:list('Wdg.WdgInstance')[$i + 1] ='AEWDOG'"!]
            [!IF "$isAeWdogAvailable = 0"!]
                [!VAR "isAeWdogAvailable" = "1"!]
                [!CODE!]
                #if (WDG_IPW_CFG_DEFINES_VENDOR_ID != AEWDOG_IP_CFG_DEFINES_VENDOR_ID)
                #error "Wdg_Ipw_Cfg_Defines.h and AeWdog_Ip_Cfg_Defines.h have different vendor ids"
                #endif

                /* Check if current file and AeWdog_Ip_Cfg_Defines header file are of the same Autosar version */
                #if ((WDG_IPW_CFG_DEFINES_AR_RELEASE_MAJOR_VERSION   != AEWDOG_IP_CFG_DEFINES_AR_RELEASE_MAJOR_VERSION) || \
                    (WDG_IPW_CFG_DEFINES_AR_RELEASE_MINOR_VERSION    != AEWDOG_IP_CFG_DEFINES_AR_RELEASE_MINOR_VERSION) || \
                    (WDG_IPW_CFG_DEFINES_AR_RELEASE_REVISION_VERSION != AEWDOG_IP_CFG_DEFINES_AR_RELEASE_REVISION_VERSION))
                #error "AutoSar Version Numbers of Wdg_Ipw_Cfg_Defines.h and AeWdog_Ip_Cfg_Defines.h are different"
                #endif

                /* Check if current file and AeWdog_Ip_Cfg_Defines header file are of the same software version */
                #if ((WDG_IPW_CFG_DEFINES_SW_MAJOR_VERSION != AEWDOG_IP_CFG_DEFINES_SW_MAJOR_VERSION) || \
                    (WDG_IPW_CFG_DEFINES_SW_MINOR_VERSION  != AEWDOG_IP_CFG_DEFINES_SW_MINOR_VERSION) || \
                    (WDG_IPW_CFG_DEFINES_SW_PATCH_VERSION  != AEWDOG_IP_CFG_DEFINES_SW_PATCH_VERSION))
                #error "Software Version Numbers of Wdg_Ipw_Cfg_Defines.h and AeWdog_Ip_Cfg_Defines.h are different"
                #endif
                [!ENDCODE!][!CR!]
            [!ENDIF!]
        [!ENDIF!]
        [!IF "contains(ecu:list('Wdg.WdgInstance')[$i + 1], 'SWT')"!]
            [!IF "$isSwtAvailable = 0"!]
                [!VAR "isSwtAvailable" = "1"!]
                [!CODE!]
                #if (WDG_IPW_CFG_DEFINES_VENDOR_ID != SWT_IP_CFG_DEFINES_VENDOR_ID)
                #error "Wdg_Ipw_Cfg_Defines.h and Swt_Ip_Cfg_Defines.h have different vendor ids"
                #endif

                /* Check if current file and Swt_Ip_Cfg_Defines header file are of the same Autosar version */
                #if ((WDG_IPW_CFG_DEFINES_AR_RELEASE_MAJOR_VERSION   != SWT_IP_CFG_DEFINES_AR_RELEASE_MAJOR_VERSION) || \
                    (WDG_IPW_CFG_DEFINES_AR_RELEASE_MINOR_VERSION    != SWT_IP_CFG_DEFINES_AR_RELEASE_MINOR_VERSION) || \
                    (WDG_IPW_CFG_DEFINES_AR_RELEASE_REVISION_VERSION != SWT_IP_CFG_DEFINES_AR_RELEASE_REVISION_VERSION))
                #error "AutoSar Version Numbers of Wdg_Ipw_Cfg_Defines.h and Swt_Ip_Cfg_Defines.h are different"
                #endif

                /* Check if current file and Swt_Ip_Cfg_Defines header file are of the same software version */
                #if ((WDG_IPW_CFG_DEFINES_SW_MAJOR_VERSION != SWT_IP_CFG_DEFINES_SW_MAJOR_VERSION) || \
                    (WDG_IPW_CFG_DEFINES_SW_MINOR_VERSION  != SWT_IP_CFG_DEFINES_SW_MINOR_VERSION) || \
                    (WDG_IPW_CFG_DEFINES_SW_PATCH_VERSION  != SWT_IP_CFG_DEFINES_SW_PATCH_VERSION))
                #error "Software Version Numbers of Wdg_Ipw_Cfg_Defines.h and Swt_Ip_Cfg_Defines.h are different"
                #endif
                [!ENDCODE!][!CR!]
            [!ENDIF!]
        [!ENDIF!]
    [!ENDIF!]
[!ENDFOR!]
[!ENDINDENT!]
[!ENDNOCODE!][!//

/*==================================================================================================
*                                            CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/

[!VAR "CheckMultiCore" = "0"!][!//
[!VAR "WdgInstanceCount" = "0"!][!//

/**
 * @brief  This define indicate the number of instances of the WDG
 */
#define WDG_IPW_NO_OF_INSTANCES            ([!"num:i(ecu:get('Wdg.Num.Of.Instances'))"!]U)

/**
 * @brief  This define initializes all type of wdg instances to WDG_IPW_INIT_ARRAY
 */
[!NOCODE!]
[!INDENT "0"!]
    [!CODE!]#define WDG_IPW_INIT_ARRAY {WDG_IPW_UNINIT_IP[!ENDCODE!]
[!FOR "i" = "0" TO "num:i(ecu:get('Wdg.Num.Of.Instances'))-1"!]
    [!IF "num:i($i) !=0"!]
        [!CODE!], WDG_IPW_UNINIT_IP[!ENDCODE!]
    [!ENDIF!]
[!ENDFOR!]
    [!CODE!] }[!ENDCODE!]
[!ENDINDENT!]
[!ENDNOCODE!]

/**
  * @brief  This constant specifies if the instance of the WDG is selected or not
  */
[!NOCODE!]
[!INDENT "0"!]
[!VAR "isAeWdogAvailable" = "0"!]
[!FOR "i" = "0" TO "num:i(ecu:get('Wdg.Num.Of.Instances'))-1"!]
    [!IF "num:i($i) > 0"!]
        [!VAR "xPathModule" = "concat('ASPathDataOfSchema:/Wdg_43_Instance',$i,'_','TS_T40D34M30I0R0/Wdg')"!]
    [!ELSE!]
        [!VAR "xPathModule" = "concat('ASPathDataOfSchema:/','TS_T40D34M30I0R0/Wdg')"!]
    [!ENDIF!]
    [!IF "node:exists($xPathModule)"!]
        [!IF "ecu:list('Wdg.WdgInstance')[$i + 1] ='AEWDOG'"!]
            [!IF "$isAeWdogAvailable = 0"!]
                [!VAR "isAeWdogAvailable" = "1"!]
                [!CODE!]#define WDG_IPW_ENABLE_INSTANCE[!"$i"!]      (AEWDOG_IP_ENABLE)[!ENDCODE!][!CR!]
            [!ENDIF!]
        [!ENDIF!]
        [!IF "contains(ecu:list('Wdg.WdgInstance')[$i + 1], 'SWT')"!]
            [!CODE!]#define WDG_IPW_ENABLE_INSTANCE[!"$i"!]      (SWT_IP_ENABLE_INSTANCE[!"$i"!])[!ENDCODE!][!CR!]
        [!ENDIF!]
    [!ELSE!]
        [!CODE!]#define WDG_IPW_ENABLE_INSTANCE[!"$i"!]      (STD_OFF)[!ENDCODE!][!CR!]
    [!ENDIF!]
[!ENDFOR!]
[!ENDINDENT!]
[!ENDNOCODE!][!//

/**
  * @brief  This constant specifies the hardware used or not.
  */
[!NOCODE!]
[!INDENT "0"!]
[!VAR "isSwtAvailable" = "0"!]
[!VAR "isAeWdogAvailable" = "0"!]
[!FOR "i" = "0" TO "num:i(ecu:get('Wdg.Num.Of.Instances'))-1"!]
    [!IF "num:i($i) > 0"!]
        [!VAR "xPathModule" = "concat('ASPathDataOfSchema:/Wdg_43_Instance',$i,'_','TS_T40D34M30I0R0/Wdg')"!]
    [!ELSE!]
        [!VAR "xPathModule" = "concat('ASPathDataOfSchema:/','TS_T40D34M30I0R0/Wdg')"!]
    [!ENDIF!]
    [!IF "node:exists($xPathModule)"!]
        [!IF "ecu:list('Wdg.WdgInstance')[$i + 1] ='AEWDOG'"!]
            [!IF "$isAeWdogAvailable = 0"!]
                [!VAR "isAeWdogAvailable" = "1"!]
                [!CODE!]#define AEWDOG_IP_USED      (STD_ON)[!ENDCODE!][!CR!]
            [!ENDIF!]
        [!ELSEIF "contains(ecu:list('Wdg.WdgInstance')[$i + 1], 'SWT')"!]
            [!IF "$isSwtAvailable = 0"!]
                [!VAR "isSwtAvailable" = "1"!]
                [!CODE!]#define SWT_IP_USED      (STD_ON)[!ENDCODE!][!CR!]
            [!ENDIF!]
        [!ENDIF!]
    [!ENDIF!]
[!ENDFOR!]
[!IF "$isAeWdogAvailable = 0"!]
    [!CODE!]#define AEWDOG_IP_USED   (STD_OFF)[!ENDCODE!][!CR!]
[!ENDIF!]
[!IF "$isSwtAvailable = 0"!]
    [!CODE!]#define SWT_IP_USED      (STD_OFF)[!ENDCODE!][!CR!]
[!ENDIF!]
[!ENDINDENT!]
[!ENDNOCODE!][!//

/**
* @brief  Compile switch to allow/forbid disabling the watchdog driver during runtime
*/
[!NOCODE!]
[!INDENT "0"!]
[!VAR "isDeInitAvailable" = "0"!]
[!FOR "i" = "0" TO "num:i(ecu:get('Wdg.Num.Of.Instances'))-1"!]
    [!IF "num:i($i) > 0"!]
        [!VAR "xPathModule" = "concat('ASPathDataOfSchema:/Wdg_43_Instance',$i,'_','TS_T40D34M30I0R0/Wdg')"!]
    [!ELSE!]
        [!VAR "xPathModule" = "concat('ASPathDataOfSchema:/','TS_T40D34M30I0R0/Wdg')"!]
    [!ENDIF!]
    [!IF "node:exists($xPathModule)"!]
        [!IF "contains(ecu:list('Wdg.WdgInstance')[$i + 1], 'SWT')"!]
            [!VAR "isDeInitAvailable" = "1"!]            
            [!BREAK!]
        [!ENDIF!]
    [!ENDIF!]
[!ENDFOR!]
[!IF "$isDeInitAvailable = 1"!]
    [!CODE!]#define WDG_IPW_DEINIT    (SWT_IP_DEINIT)[!ENDCODE!][!CR!]
[!ELSE!]
    [!CODE!]#define WDG_IPW_DEINIT    (STD_OFF)[!ENDCODE!][!CR!]
[!ENDIF!]
[!ENDINDENT!]
[!ENDNOCODE!]

/**
* @brief  This variable will which Wdg instances can be serviced directly
*/
[!NOCODE!]
[!INDENT "0"!]
[!VAR "isSwtAvailable" = "0"!]
[!VAR "isEnableDirectService"     = "0"!]
[!VAR "isDisableDirectService"    = "0"!][!//
[!FOR "i" = "0" TO "num:i(ecu:get('Wdg.Num.Of.Instances'))-1"!]
    [!IF "num:i($i) > 0"!]
        [!VAR "xPathModule" = "concat('ASPathDataOfSchema:/Wdg_43_Instance',$i,'_','TS_T40D34M30I0R0/Wdg')"!]
    [!ELSE!]
        [!VAR "xPathModule" = "concat('ASPathDataOfSchema:/','TS_T40D34M30I0R0/Wdg')"!]
    [!ENDIF!]
    [!IF "node:exists($xPathModule)"!]
        [!IF "contains(ecu:list('Wdg.WdgInstance')[$i + 1], 'SWT')"!]
            [!VAR "isSwtAvailable" = "1"!]
            [!CODE!]#define WDG_IPW_ENABLE_DIRECT_SERVICE_INSTANCE[!"$i"!] (SWT_IP_ENABLE_DIRECT_SERVICE_INSTANCE[!"$i"!])[!ENDCODE!][!CR!]
        [!ELSE!]
            [!IF "node:value(concat($xPathModule,'/WdgGeneral/WdgEnableDirectService'))"!]
                [!VAR "isEnableDirectService" = "1"!]
                [!CODE!]#define WDG_IPW_ENABLE_DIRECT_SERVICE_INSTANCE[!"$i"!] (STD_ON)[!ENDCODE!][!CR!]
                [!IF "num:i($isDisableDirectService) = 1"!]
                    [!ERROR!]The "Wdg Enable Direct Service" node must be enabled or disabled for all instances[!ENDERROR!]
                    [!BREAK!]
                [!ENDIF!]
            [!ELSE!]
                [!VAR "isDisableDirectService" = "1"!]
                [!CODE!]#define WDG_IPW_ENABLE_DIRECT_SERVICE_INSTANCE[!"$i"!] (STD_OFF)[!ENDCODE!][!CR!]
                [!IF "num:i($isEnableDirectService) = 1"!]
                    [!ERROR!]The "Wdg Enable Direct Service" node must be enabled or disabled for all instances[!ENDERROR!]
                [!ENDIF!]
            [!ENDIF!]
        [!ENDIF!]
    [!ELSE!]
        [!CODE!]#define WDG_IPW_ENABLE_DIRECT_SERVICE_INSTANCE[!"$i"!] (STD_OFF)[!ENDCODE!][!CR!]
    [!ENDIF!]
[!ENDFOR!]
[!IF "$isSwtAvailable = 1"!]
    [!CODE!]
    #define WDG_IPW_DIRECT_SERVICE  (SWT_IP_ENABLE_DIRECT_SERVICE)
    [!ENDCODE!]
[!ELSE!]
    [!CODE!]
    #define WDG_IPW_DIRECT_SERVICE ([!IF "$isEnableDirectService = 1"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])
    [!ENDCODE!]
[!ENDIF!]
[!ENDINDENT!]
[!ENDNOCODE!][!//


/**
* @brief  This variable will indicate if the ISR for WDG instances is used
*/
[!NOCODE!]
[!INDENT "0"!]
[!FOR "i" = "0" TO "num:i(ecu:get('Wdg.Num.Of.Instances'))-1"!]
    [!IF "contains(ecu:list('Wdg.WdgInstance')[$i + 1], 'SWT')"!]
        [!CODE!]#define WDG_IPW_ISR[!"$i"!]_USED (SWT_IP_ISR[!"$i"!]_USED)[!ENDCODE!][!CR!]
    [!ELSE!]
        [!CODE!]#define WDG_IPW_ISR[!"$i"!]_USED (STD_OFF)[!ENDCODE!][!CR!]
    [!ENDIF!]
[!ENDFOR!]
[!ENDINDENT!]
[!ENDNOCODE!][!//

/**
* @brief  This variable will indicate which Wdg instance support the Clear Reset Request feature
*/
[!NOCODE!]
[!INDENT "0"!]
[!VAR "isClearResetRequestAvailable" = "0"!]
[!FOR "i" = "0" TO "num:i(ecu:get('Wdg.Num.Of.Instances'))-1"!]
    [!IF "contains(ecu:list('Wdg.WdgInstance')[$i + 1], 'SWT')"!]
        [!VAR "isClearResetRequestAvailable" = "1"!]
        [!CODE!]#define WDG_IPW_CLEAR_RESET_REQUEST_INSTANCE[!"$i"!] (SWT_IP_CLEAR_RESET_REQUEST_INSTANCE[!"$i"!])[!ENDCODE!][!CR!]
    [!ELSE!]
        [!CODE!]#define WDG_IPW_CLEAR_RESET_REQUEST_INSTANCE[!"$i"!] (STD_OFF)[!ENDCODE!][!CR!]
    [!ENDIF!]
[!ENDFOR!]
[!IF "$isClearResetRequestAvailable = 1"!]
    [!CODE!]#define WDG_IPW_CLEAR_RESET_REQUEST (SWT_IP_CLEAR_RESET_REQUEST)[!ENDCODE!][!CR!]
[!ELSE!]
    [!CODE!]#define WDG_IPW_CLEAR_RESET_REQUEST (STD_OFF)[!ENDCODE!][!CR!]
[!ENDIF!]
[!ENDINDENT!]
[!ENDNOCODE!][!//

[!NOCODE!][!//
[!INDENT "0"!]
    [!VAR "isDirectServiceAvailable" = "1"!]
    [!VAR "checkVersionInforAPI" = "1"!]
    [!FOR "i" = "0" TO "num:i(ecu:get('Wdg.Num.Of.Instances'))-1"!]
        [!IF "num:i($i) > 0"!]
            [!VAR "xPathModule" = "concat('ASPathDataOfSchema:/Wdg_43_Instance',$i,'_','TS_T40D34M30I0R0/Wdg')"!]
        [!ELSE!]
            [!VAR "xPathModule" = "concat('ASPathDataOfSchema:/','TS_T40D34M30I0R0/Wdg')"!]
        [!ENDIF!]
        [!IF "node:exists($xPathModule)"!]
            [!IF "ecu:list('Wdg.WdgInstance')[$i + 1] ='AEWDOG'"!]
                [!IF "node:value(concat($xPathModule,'/WdgGeneral/WdgVersionInfoApi'))"!]
                    [!VAR "checkVersionInforAPI" = "0"!]
                [!ENDIF!]

                [!VAR "getInitialTimeoutValue" = "node:value(concat($xPathModule,'/WdgGeneral/WdgInitialTimeout'))"!]
                [!VAR "getTimeoutMaxValue" = "node:value(concat($xPathModule,'/WdgGeneral/WdgMaxTimeout'))"!]

                [!IF "node:exists(concat($xPathModule,'/WdgSettingsConfig/WdgExternalTriggerCounterRef'))"!]
                    [!IF "node:value(concat($xPathModule,'/WdgGeneral/WdgEnableDirectService'))='false'"!]
                        [!VAR "isDirectServiceAvailable" = "0"!]
                        [!VAR "GptChannelInitialTickValue" = "node:value(node:ref(node:value(concat($xPathModule,'/WdgSettingsConfig/WdgExternalTriggerCounterRef')))/GptChannelTickFrequency)"!]
                        [!VAR "GptChannelTickValueMax" = "node:value(node:ref(node:value(concat($xPathModule,'/WdgSettingsConfig/WdgExternalTriggerCounterRef')))/GptChannelTickValueMax)"!]
                        [!IF "$getTimeoutMaxValue > ($GptChannelTickValueMax div $GptChannelInitialTickValue)"!]
                            [!ERROR!][!//
                            [!"'Must set Wdg Max Timeout [s] lest than or equal to '"!][!"$GptChannelTickValueMax div $GptChannelInitialTickValue"!]
                            [!ENDERROR!][!//
                        [!ENDIF!]
                    [!ENDIF!]
                [!ENDIF!]
                [!CODE!]
                /**
                * @brief  These variables will indicate the Wdg Initial Timeout and Wdg Max Timeout parameters in miliseconds for Wdg module [!"$i"!]
                */
                #define WDG_IPW_INSTANCE[!"$i"!]_INITIAL_TIMEOUT_U16 ((uint16)[!"num:i(node:value(concat($xPathModule,'/WdgGeneral/WdgInitialTimeout')) * 1000)"!])
                #define WDG_IPW_INSTANCE[!"$i"!]_MAX_TIMEOUT_U16 ((uint16)[!"num:i(node:value(concat($xPathModule,'/WdgGeneral/WdgMaxTimeout')) * 1000)"!])
                [!ENDCODE!]
            [!ENDIF!]
            [!IF "contains(ecu:list('Wdg.WdgInstance')[$i + 1], 'SWT')"!]
                [!CODE!]
                /**
                * @brief  These variables will indicate the Wdg Initial Timeout and Wdg Max Timeout parameters in miliseconds for Wdg module [!"$i"!]
                */
                #define WDG_IPW_INSTANCE[!"$i"!]_INITIAL_TIMEOUT_U16 (SWT_IP_INSTANCE[!"$i"!]_INITIAL_TIMEOUT_U16)
                #define WDG_IPW_INSTANCE[!"$i"!]_MAX_TIMEOUT_U16 (SWT_IP_INSTANCE[!"$i"!]_MAX_TIMEOUT_U16)
                [!ENDCODE!]
            [!ENDIF!]
        [!ENDIF!]
    [!ENDFOR!]
[!ENDINDENT!]
[!ENDNOCODE!][!//

[!NOCODE!]
[!INDENT "0"!]
    [!VAR "isDirectServiceAvailable" = "0"!]
    [!VAR "isAeWdogAvailable" = "0"!]
    [!VAR "isSwtAvailable" = "0"!]
    [!FOR "i" = "0" TO "num:i(ecu:get('Wdg.Num.Of.Instances'))-1"!]
        [!IF "num:i($i) > 0"!]
            [!VAR "xPathModule" = "concat('ASPathDataOfSchema:/Wdg_43_Instance',$i,'_','TS_T40D34M30I0R0/Wdg')"!]
        [!ELSE!]
            [!VAR "xPathModule" = "concat('ASPathDataOfSchema:/','TS_T40D34M30I0R0/Wdg')"!]
        [!ENDIF!]
        [!IF "node:exists($xPathModule)"!]
            [!IF "ecu:list('Wdg.WdgInstance')[$i + 1] ='AEWDOG'"!]
                [!VAR "isAeWdogAvailable" = "1"!]
            [!ELSEIF "contains(ecu:list('Wdg.WdgInstance')[$i + 1], 'SWT')"!]
                [!VAR "isSwtAvailable" = "1"!]
            [!ENDIF!]
            [!IF "node:value(concat($xPathModule,'/WdgGeneral/WdgEnableDirectService'))='false' and node:value(concat($xPathModule,'/WdgGeneral/WdgDevErrorDetect'))='true'"!]
                [!VAR "isDirectServiceAvailable" = "1"!]
            [!ENDIF!]
        [!ENDIF!]
    [!ENDFOR!]
    [!IF "num:i($isDirectServiceAvailable) = 1"!]
        [!CODE!]
        /**
        * @brief  This macros indicate the Wdg timeout value for Wdg module.
        */
        [!IF "$isAeWdogAvailable = 1 and $isSwtAvailable = 1"!]
            [!FOR "i" = "0" TO "num:i(ecu:get('Wdg.Num.Of.Instances'))-1"!][!//
                [!IF "contains(ecu:list('Wdg.WdgInstance')[$i + 1], 'SWT')"!][!//
                    [!IF "num:i($i)=0"!][!//
                        [!CODE!][!//
                        #define WDG_IPW_TIMEOUT_VALUE_ARRAY {SWT_IP_INSTANCE[!"$i"!]_TIMEOUT_VALUE_ARRAY \
                        [!ENDCODE!][!//
                    [!ELSE!][!//
                        [!CODE!][!//
                            ,SWT_IP_INSTANCE[!"$i"!]_TIMEOUT_VALUE_ARRAY \
                        [!ENDCODE!][!//
                    [!ENDIF!][!//
                [!ENDIF!][!//
            [!ENDFOR!][!//
            [!CODE!][!//
                            ,AEWDOG_IPW_TIMEOUT_VALUE_ARRAY }
            [!ENDCODE!][!//
        [!ELSEIF "$isAeWdogAvailable = 1"!]
            #define WDG_IPW_TIMEOUT_VALUE_ARRAY      AEWDOG_IPW_TIMEOUT_VALUE_ARRAY
        [!ELSE!]
            #define WDG_IPW_TIMEOUT_VALUE_ARRAY     SWT_TIMEOUT_VALUE_ARRAY
        [!ENDIF!]
        [!ENDCODE!]
    [!ENDIF!]
[!ENDINDENT!]
[!ENDNOCODE!]

/**
* @brief  Compile switch to enable development error detection
*/
[!NOCODE!]
[!INDENT "0"!]
[!VAR "WdgEnableDevErrorDetect" = "0"!][!//
[!FOR "i" = "0" TO "num:i(ecu:get('Wdg.Num.Of.Instances'))-1"!]
    [!IF "num:i($i) > 0"!]
        [!VAR "xPathModule" = "concat('ASPathDataOfSchema:/Wdg_43_Instance',$i,'_','TS_T40D34M30I0R0/Wdg')"!]
    [!ELSE!]
        [!VAR "xPathModule" = "concat('ASPathDataOfSchema:/','TS_T40D34M30I0R0/Wdg')"!]
    [!ENDIF!]
    [!IF "node:exists($xPathModule)"!]
        [!IF "node:value(concat($xPathModule,'/WdgGeneral/WdgDevErrorDetect'))"!]
            [!VAR "WdgEnableDevErrorDetect" = "1"!]
        [!ENDIF!]
    [!ENDIF!]
[!ENDFOR!]
[!CODE!]
#define WDG_IPW_DEV_ERROR_DETECT ([!IF "$WdgEnableDevErrorDetect = 1"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])[!ENDCODE!][!CR!]
[!ENDINDENT!]
[!ENDNOCODE!]

#ifdef __cplusplus
}
#endif

/** @} */

#endif /* WDG_IPW_CFG_DEFINES_H */
