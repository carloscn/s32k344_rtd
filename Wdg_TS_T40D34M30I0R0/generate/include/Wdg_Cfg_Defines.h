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

#ifndef WDG_CFG_DEFINES_H
#define WDG_CFG_DEFINES_H

/**
*   @file
*
*   @addtogroup Wdg
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
#include "WdgIf_Types.h"
#include "Wdg_Ipw_Cfg_Defines.h"
#include "Mcal.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/

#define WDG_VENDOR_ID_CFG                    43
#define WDG_AR_RELEASE_MAJOR_VERSION_CFG     4
#define WDG_AR_RELEASE_MINOR_VERSION_CFG     7
#define WDG_AR_RELEASE_REVISION_VERSION_CFG  0
#define WDG_SW_MAJOR_VERSION_CFG             3
#define WDG_SW_MINOR_VERSION_CFG             0
#define WDG_SW_PATCH_VERSION_CFG             0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/

#if (WDG_VENDOR_ID_CFG != WDG_IPW_CFG_DEFINES_VENDOR_ID)
#error "Wdg_Cfg_Defines.h and Wdg_Ipw_Cfg_Defines.h have different vendor ids"
#endif

/* Check if current file and Wdg_Ipw_Types header file are of the same Autosar version */
#if ((WDG_AR_RELEASE_MAJOR_VERSION_CFG     != WDG_IPW_CFG_DEFINES_AR_RELEASE_MAJOR_VERSION) || \
    (WDG_AR_RELEASE_MINOR_VERSION_CFG     != WDG_IPW_CFG_DEFINES_AR_RELEASE_MINOR_VERSION) || \
    (WDG_AR_RELEASE_REVISION_VERSION_CFG  != WDG_IPW_CFG_DEFINES_AR_RELEASE_REVISION_VERSION))
#error "AutoSar Version Numbers of Wdg_Cfg_Defines.h and Wdg_Ipw_Cfg_Defines.h are different"
#endif

/* Check if current file and Wdg_Ipw_Types header file are of the same software version */
#if ((WDG_SW_MAJOR_VERSION_CFG != WDG_IPW_CFG_DEFINES_SW_MAJOR_VERSION) || \
    (WDG_SW_MINOR_VERSION_CFG != WDG_IPW_CFG_DEFINES_SW_MINOR_VERSION) || \
    (WDG_SW_PATCH_VERSION_CFG != WDG_IPW_CFG_DEFINES_SW_PATCH_VERSION))
#error "Software Version Numbers of Wdg_Cfg_Defines.h and Wdg_Ipw_Cfg_Defines.h are different"
#endif

/* Check if current file and WDG configuration header file are of the same vendor */
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if current file and Wdg_Ipw_Types header file are of the same Autosar version */
    #if ((WDG_AR_RELEASE_MAJOR_VERSION_CFG     != WDGIF_TYPES_AR_RELEASE_MAJOR_VERSION) || \
        (WDG_AR_RELEASE_MINOR_VERSION_CFG     != WDGIF_TYPES_AR_RELEASE_MINOR_VERSION))
    #error "AutoSar Version Numbers of Wdg_Cfg_Defines.h and WdgIf_Types.h are different"
    #endif

    /* Check if source file and Mcal header file are of the same Autosar version */
    #if (( WDG_AR_RELEASE_MAJOR_VERSION_CFG != MCAL_AR_RELEASE_MAJOR_VERSION) || \
        ( WDG_AR_RELEASE_MINOR_VERSION_CFG != MCAL_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of Wdg_Cfg_Defines.h and Mcal.h are different"
    #endif
#endif /* DISABLE_MCAL_INTERMODULE_ASR_CHECK */

/*==================================================================================================
*                                            CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/
[!NOCODE!]
[!INCLUDE "Wdg_VersionCheck_Inc.m"!]
[!INCLUDE "Wdg_PluginMacros.m"!]
[!ENDNOCODE!]

/**
 * @brief  This define indicate the number of HW IPs available on the Platform
 */
[!VAR "MaxIndex"="num:i(ecu:get('Wdg.Num.Of.Instances'))"!]
#define WDG_NO_OF_INSTANCES            ([!"num:i(ecu:get('Wdg.Num.Of.Instances'))"!]U)

/**
 * @brief  This define initializes all wdg instances to WDGIF_OFF_MODE
 */
[!NOCODE!]
[!INDENT "0"!]
    [!CODE!]#define WDG_INIT_PREVIOUS_MODE_ARRAY {WDGIF_OFF_MODE[!ENDCODE!]
[!FOR "i" = "0" TO "num:i(ecu:get('Wdg.Num.Of.Instances'))-1"!]
    [!IF "num:i($i) !=0"!]
        [!CODE!], WDGIF_OFF_MODE[!ENDCODE!]
    [!ENDIF!]
[!ENDFOR!]
    [!CODE!] }[!ENDCODE!]
[!ENDINDENT!]
[!ENDNOCODE!]

/**
 * @brief  This define initializes to WDG_UNINIT for variable that indicated the state of the driver
 */
[!NOCODE!]
[!INDENT "0"!]
    [!CODE!]#define WDG_INIT_STATUS_ARRAY {WDG_UNINIT[!ENDCODE!]
[!FOR "i" = "0" TO "num:i(ecu:get('Wdg.Num.Of.Instances'))-1"!]
    [!IF "num:i($i) !=0"!]
        [!CODE!], WDG_UNINIT[!ENDCODE!]
    [!ENDIF!]
[!ENDFOR!]
    [!CODE!] }[!ENDCODE!]
[!ENDINDENT!]
[!ENDNOCODE!]

/**
 * @brief  These defines indicate which Wdg Instances are enabled
 */
[!NOCODE!]
[!INDENT "0"!]
[!FOR "i" = "0" TO "num:i(ecu:get('Wdg.Num.Of.Instances'))-1"!][!CR!]
    [!CODE!]#define WDG_INSTANCE[!"$i"!] (WDG_IPW_ENABLE_INSTANCE[!"$i"!])[!ENDCODE!]
[!ENDFOR!]
[!ENDINDENT!]
[!ENDNOCODE!]

/**
 * @brief  This constant specifies if the multi-core is used or not
 */
[!NOCODE!]
[!VAR "isMultiCoreEnabled"     = "0"!]
[!VAR "isMultiCoreDisabled"    = "0"!]

[!FOR "i" = "0" TO "num:i(ecu:get('Wdg.Num.Of.Instances'))-1"!]
    [!IF "num:i($i) > 0"!]
        [!VAR "xPathModule" = "concat('ASPathDataOfSchema:/Wdg_43_Instance',$i,'_','TS_T40D34M30I0R0/Wdg')"!]
    [!ELSE!]
        [!VAR "xPathModule" = "concat('ASPathDataOfSchema:/','TS_T40D34M30I0R0/Wdg')"!]
    [!ENDIF!]
    [!IF "node:exists($xPathModule)"!]
        [!IF "node:value(concat($xPathModule,'/WdgGeneral/WdgEnableMultiCoreSupport'))"!]
            [!VAR "isMultiCoreEnabled" = "1"!]
            [!IF "num:i($isMultiCoreDisabled) = 1"!]
                [!ERROR!]The "Wdg Enable Multi-Core Support" node must be enabled or disabled for all instances[!ENDERROR!]
                [!BREAK!]
            [!ENDIF!]
        [!ELSE!]
            [!VAR "isMultiCoreDisabled" = "1"!]
            [!IF "num:i($isMultiCoreEnabled) = 1"!]
                [!ERROR!]The "Wdg Enable Multi-Core Support" node must be enabled or disabled for all instances[!ENDERROR!]
            [!ENDIF!]
        [!ENDIF!]
    [!ENDIF!]
[!ENDFOR!]

[!IF "num:i($isMultiCoreEnabled) = 1"!]
    [!CODE!]#define WDG_MULTICORE_ENABLED (STD_ON)[!ENDCODE!]
[!ELSE!]
    [!CODE!]#define WDG_MULTICORE_ENABLED (STD_OFF)[!ENDCODE!]
[!ENDIF!]
[!ENDNOCODE!][!//

/**
 * @brief  This define indicates if disabling the Wdg hardware is allowed
 */
#define WDG_DISABLE_ALLOWED    (WDG_IPW_DEINIT)
[!NOCODE!][!//
[!INDENT "0"!]
    [!FOR "i" = "0" TO "num:i(ecu:get('Wdg.Num.Of.Instances'))-1"!]
        [!IF "num:i($i) > 0"!]
            [!VAR "xPathModule" = "concat('ASPathDataOfSchema:/Wdg_43_Instance',$i,'_','TS_T40D34M30I0R0/Wdg')"!]
        [!ELSE!]
            [!VAR "xPathModule" = "concat('ASPathDataOfSchema:/','TS_T40D34M30I0R0/Wdg')"!]
        [!ENDIF!]
        [!IF "node:exists($xPathModule)"!]
            [!CODE!]
            /**
            * @brief  These variables will indicate the Wdg Initial Timeout and Wdg Max Timeout parameters in miliseconds for Wdg module [!"$i"!]
            */
            #define WDG_43_INSTANCE[!"$i"!]_INITIAL_TIMEOUT_U16 (WDG_IPW_INSTANCE[!"$i"!]_INITIAL_TIMEOUT_U16)
            #define WDG_43_INSTANCE[!"$i"!]_MAX_TIMEOUT_U16 (WDG_IPW_INSTANCE[!"$i"!]_MAX_TIMEOUT_U16)
            [!ENDCODE!]
        [!ENDIF!]
    [!ENDFOR!]
[!ENDINDENT!]
[!ENDNOCODE!][!//

/**
 * @brief  Compile switch to enable/disable the version information for Wdg module
 */
[!NOCODE!][!//
[!INDENT "0"!]
    [!VAR "enableVersionInforAPI" = "0"!]
    [!VAR "disableVersionInforAPI" = "0"!]
    [!FOR "i" = "0" TO "num:i(ecu:get('Wdg.Num.Of.Instances'))-1"!]
        [!IF "num:i($i) > 0"!]
            [!VAR "xPathModule" = "concat('ASPathDataOfSchema:/Wdg_43_Instance',$i,'_','TS_T40D34M30I0R0/Wdg')"!]
        [!ELSE!]
            [!VAR "xPathModule" = "concat('ASPathDataOfSchema:/','TS_T40D34M30I0R0/Wdg')"!]
        [!ENDIF!]
        [!IF "node:exists($xPathModule)"!]
            [!IF "node:value(concat($xPathModule,'/WdgGeneral/WdgVersionInfoApi'))"!]
                [!VAR "enableVersionInforAPI" = "1"!]
                [!IF "num:i($disableVersionInforAPI) = 1"!]
                    [!ERROR!]The "Wdg VersionInfo Api" node must be enabled or disabled for all instances[!ENDERROR!]
                    [!BREAK!]
                [!ENDIF!]
            [!ELSE!]
                [!VAR "disableVersionInforAPI" = "1"!]
                [!IF "num:i($enableVersionInforAPI) = 1"!]
                    [!ERROR!]The "Wdg VersionInfo Api" node must be enabled or disabled for all instances[!ENDERROR!]
                    [!BREAK!]
                [!ENDIF!]
            [!ENDIF!]
            [!CODE!]
            #define WDG_43_INSTANCE[!"$i"!]_VERSION_INFO_API ([!IF "node:value(concat($xPathModule,'/WdgGeneral/WdgVersionInfoApi'))"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])
            [!ENDCODE!]
        [!ELSE!]
            [!CODE!]
            #define WDG_43_INSTANCE[!"$i"!]_VERSION_INFO_API (STD_OFF)
            [!ENDCODE!]
        [!ENDIF!]
    [!ENDFOR!]
    [!CODE!]
        /**
         * @brief  Compile switch to enable/disable the Wdg_ChannelGetVersionInfo function.
         */
        #define WDG_VERSION_INFO_API ([!IF "$enableVersionInforAPI = 1"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])
    [!ENDCODE!]
[!ENDINDENT!]
[!ENDNOCODE!][!//

/**
 * @brief  This define indicates which instances of the Wdg hardware can be serviced directly
 */
[!NOCODE!]
[!INDENT "0"!]
[!FOR "i" = "0" TO "num:i(ecu:get('Wdg.Num.Of.Instances'))-1"!]
    [!CODE!]#define WDG_DIRECT_SERVICE_INSTANCE[!"$i"!] (WDG_IPW_ENABLE_DIRECT_SERVICE_INSTANCE[!"$i"!])[!ENDCODE!][!CR!]
[!ENDFOR!]
[!ENDINDENT!]
[!ENDNOCODE!][!//


/**
 * @brief  This define indicates if servicing the Wdg hardware directly, without an external trigger, is allowed
 */
#define WDG_DIRECT_SERVICE (WDG_IPW_DIRECT_SERVICE)

/**
 * @brief  This variable will indicate if the ClearResetRequest feature is enabled
 */
[!NOCODE!]
[!INDENT "0"!]
[!FOR "i" = "0" TO "num:i(ecu:get('Wdg.Num.Of.Instances'))-1"!]
    [!CODE!]#define WDG_CLEAR_RESET_REQUEST_INSTANCE[!"$i"!] (WDG_IPW_CLEAR_RESET_REQUEST_INSTANCE[!"$i"!])[!ENDCODE!][!CR!]
[!ENDFOR!]
[!ENDINDENT!]
[!ENDNOCODE!][!//

#define WDG_CLEAR_RESET_REQUEST (WDG_IPW_CLEAR_RESET_REQUEST)

/**
* @brief  This define indicate that the watchdog is Enable or Disable User mode support
*/
[!NOCODE!][!//
[!VAR "isEnableUserModeSupport" = "0"!]
[!VAR "disableUserModeSupport" = "0"!]
[!FOR "i" = "0" TO "num:i(ecu:get('Wdg.Num.Of.Instances'))-1"!]
    [!IF "num:i($i) > 0"!]
        [!VAR "xPathModule" = "concat('ASPathDataOfSchema:/Wdg_43_Instance',$i,'_','TS_T40D34M30I0R0/Wdg')"!]
    [!ELSE!]
        [!VAR "xPathModule" = "concat('ASPathDataOfSchema:/','TS_T40D34M30I0R0/Wdg')"!]
    [!ENDIF!]
    [!IF "node:exists($xPathModule)"!]
        [!IF "node:value(concat($xPathModule,'/WdgGeneral/WdgEnableUserModeSupport'))"!]
            [!VAR "isEnableUserModeSupport" = "1"!]
            [!IF "num:i($disableUserModeSupport) = 1"!]
                [!ERROR!]The "Wdg Enable User Mode Support" node must be enabled or disabled for all instances[!ENDERROR!]
                [!BREAK!]
            [!ENDIF!]
        [!ELSE!]
            [!VAR "disableUserModeSupport" = "1"!]
            [!IF "num:i($isEnableUserModeSupport) = 1"!]
                [!ERROR!]The "Wdg Enable User Mode Support" node must be enabled or disabled for all instances[!ENDERROR!]
            [!ENDIF!]
        [!ENDIF!]
    [!ENDIF!]
[!ENDFOR!]
[!IF "num:i($isEnableUserModeSupport) = 1"!]
    [!CODE!]#define WDG_ENABLE_USER_MODE_SUPPORT (STD_ON)[!ENDCODE!][!CR!]
[!ELSE!]
    [!CODE!]#define WDG_ENABLE_USER_MODE_SUPPORT (STD_OFF)[!ENDCODE!][!CR!]
[!ENDIF!]
[!ENDNOCODE!][!//


/**
 * @brief  This variable will indicate if the ISR for WDG instances is used
 */
[!NOCODE!]
[!INDENT "0"!]
[!FOR "i" = "0" TO "num:i(ecu:get('Wdg.Num.Of.Instances'))-1"!]
    [!CODE!]#define WDG_ISR[!"$i"!]_USED (WDG_IPW_ISR[!"$i"!]_USED)[!ENDCODE!][!CR!]
[!ENDFOR!]
[!ENDINDENT!]
[!ENDNOCODE!][!//

/**
 * @brief  Compile switch to enable/disable development error detection for this module
 */
#define WDG_DEV_ERROR_DETECT (WDG_IPW_DEV_ERROR_DETECT)

[!NOCODE!]
[!VAR "DemErrorReportsEnabled"     = "0"!]
[!VAR "DemErrorReportsDisabled"    = "0"!]

[!FOR "i" = "0" TO "num:i(ecu:get('Wdg.Num.Of.Instances'))-1"!]
    [!IF "num:i($i) > 0"!]
        [!VAR "xPathModule" = "concat('ASPathDataOfSchema:/Wdg_43_Instance',$i,'_','TS_T40D34M30I0R0/Wdg')"!]
    [!ELSE!]
        [!VAR "xPathModule" = "concat('ASPathDataOfSchema:/','TS_T40D34M30I0R0/Wdg')"!]
    [!ENDIF!]
    [!IF "node:exists($xPathModule)"!]
        [!IF "node:value(concat($xPathModule,'/WdgGeneral/AutosarExt/WdgDisableDemReportErrorStatus'))"!]
            [!VAR "DemErrorReportsDisabled" = "1"!]
            [!IF "num:i($DemErrorReportsEnabled) = 1"!]
                [!ERROR!]The "Wdg Disable Production Error Reporting" node must be enabled or disabled for all instances[!ENDERROR!]
                [!BREAK!]
            [!ENDIF!]
        [!ELSE!]
            [!VAR "DemErrorReportsEnabled" = "1"!]
            [!IF "num:i($DemErrorReportsDisabled) = 1"!]
                [!ERROR!]The "Wdg Disable Production Error Reporting" node must be enabled or disabled for all instances[!ENDERROR!]
            [!ENDIF!]
        [!ENDIF!]
    [!ENDIF!]
[!ENDFOR!]
[!ENDNOCODE!][!//

/**
 * @brief  Switch to globaly enable/disable the production error reporting.
 */
[!NOCODE!]
[!IF "num:i($DemErrorReportsEnabled) = 1"!]
    [!CODE!]#define WDG_DISABLE_DEM_REPORT_ERROR_STATUS (STD_OFF)[!ENDCODE!]
[!ELSE!]
    [!CODE!]#define WDG_DISABLE_DEM_REPORT_ERROR_STATUS (STD_ON)[!ENDCODE!]
[!ENDIF!]
[!ENDNOCODE!][!//

#ifdef WDG_ENABLE_USER_MODE_SUPPORT
    #if (STD_ON == WDG_ENABLE_USER_MODE_SUPPORT)
        /**
         * @brief  This define indicate that the ipv SWT is protected by register protection 
         */
        #define WDG_SWT_REG_PROT_AVAILABLE
    #endif /* (STD_ON == WDG_ENABLE_USER_MODE_SUPPORT) */
#endif /* ifdef WDG_ENABLE_USER_MODE_SUPPORT */

/**
 * @brief  perform checking marco MCAL_ENABLE_USER_MODE_SUPPORT available or not.
 */
#ifndef MCAL_ENABLE_USER_MODE_SUPPORT
    #if (STD_ON == WDG_ENABLE_USER_MODE_SUPPORT)
        #error MCAL_ENABLE_USER_MODE_SUPPORT is not enabled. For running Wdg in user mode, the MCAL_ENABLE_USER_MODE_SUPPORT needs to be defined
    #endif /* (STD_ON == WDG_ENABLE_USER_MODE_SUPPORT) */
#endif /* ifndef MCAL_ENABLE_USER_MODE_SUPPORT */

[!NOCODE!]
[!INDENT "0"!]
[!VAR "isPostBuildEnabled"    = "0"!]
[!VAR "isPreCompileOrLinkTimeEnabled"    = "0"!]

[!FOR "i" = "0" TO "num:i(ecu:get('Wdg.Num.Of.Instances'))-1"!]
    [!IF "num:i($i) > 0"!]
        [!VAR "xPathModule" = "concat('ASPathDataOfSchema:/Wdg_43_Instance',$i,'_','TS_T40D34M30I0R0/Wdg')"!]
    [!ELSE!]
        [!VAR "xPathModule" = "concat('ASPathDataOfSchema:/','TS_T40D34M30I0R0/Wdg')"!]
    [!ENDIF!]
    [!IF "node:exists($xPathModule)"!]
        [!IF "node:value(concat($xPathModule,'/IMPLEMENTATION_CONFIG_VARIANT'))='VariantPreCompile' or node:value(concat($xPathModule,'/IMPLEMENTATION_CONFIG_VARIANT'))='VariantLinkTime'"!]
            [!VAR "isPreCompileOrLinkTimeEnabled"    = "1"!]
            [!IF "num:i($isPostBuildEnabled) = 1"!]
                [!ERROR!]The "Config Variant" node must be either "VariantPostBuild" or "VariantLinkTime"/"VariantPreCompile" for all enabled instances[!ENDERROR!]
                [!BREAK!]
            [!ENDIF!]
        [!ELSE!]
            [!VAR "isPostBuildEnabled"    = "1"!]
            [!IF "num:i($isPreCompileOrLinkTimeEnabled) = 1"!]
                [!ERROR!]The "Config Variant" node must be either "VariantPostBuild" or "VariantLinkTime"/"VariantPreCompile" for all enabled instances[!ENDERROR!]
                [!BREAK!]
            [!ENDIF!]
        [!ENDIF!]
    [!ENDIF!]
[!ENDFOR!]
[!ENDINDENT!]
[!ENDNOCODE!]

/**
 * @brief  Define to enabled PreCompile Support.
 */
[!NOCODE!]
[!INDENT "0"!]
[!IF "variant:size()<=1"!]
    [!IF "num:i($isPreCompileOrLinkTimeEnabled) = 1"!]
        [!CODE!]#define WDG_PRECOMPILE_SUPPORT (STD_ON)[!ENDCODE!]
    [!ELSE!]
        [!CODE!]#define WDG_PRECOMPILE_SUPPORT (STD_OFF)[!ENDCODE!]
    [!ENDIF!]
[!ELSE!]
    [!CODE!]#define WDG_PRECOMPILE_SUPPORT (STD_OFF)[!ENDCODE!]
[!ENDIF!]

[!ENDINDENT!]
[!ENDNOCODE!]

[!NOCODE!]
[!INDENT "0"!]
    [!FOR "i" = "0" TO "num:i(ecu:get('Wdg.Num.Of.Instances'))-1"!]
        [!IF "num:i($i) > 0"!]
            [!VAR "xPathModule" = "concat('ASPathDataOfSchema:/Wdg_43_Instance',$i,'_','TS_T40D34M30I0R0/Wdg')"!]
        [!ELSE!]
            [!VAR "xPathModule" = "concat('ASPathDataOfSchema:/','TS_T40D34M30I0R0/Wdg')"!]
        [!ENDIF!]
        [!IF "node:exists($xPathModule)"!]
            [!IF "node:value(concat($xPathModule,'/WdgGeneral/WdgEnableDirectService'))='false' and node:value(concat($xPathModule,'/WdgGeneral/WdgDevErrorDetect'))='true'"!]
                [!CODE!]
                /**
                * @brief  This macros indicate the Wdg timeout value for Wdg module.
                */
                #define WDG_TIMEOUT_VALUE_ARRAY WDG_IPW_TIMEOUT_VALUE_ARRAY
                [!ENDCODE!]
                [!BREAK!]
            [!ENDIF!]
        [!ENDIF!]
    [!ENDFOR!]
[!ENDINDENT!]
[!ENDNOCODE!]


/*==================================================================================================
*                                             ENUMS
==================================================================================================*/

/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                   FUNCTION PROTOTYPES
==================================================================================================*/


#ifdef __cplusplus
}
#endif

/** @} */

#endif /* WDG_CFG_DEFINES_H */
