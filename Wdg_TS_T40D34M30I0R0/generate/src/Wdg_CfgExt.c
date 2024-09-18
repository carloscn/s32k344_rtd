
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

/**
* @file
*
* @addtogroup  Wdg
* @{
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

#include "Wdg_ChannelTypes.h"
#include "Wdg_Cfg.h"
#include "Wdg_CfgExt.h"

[!INCLUDE "Wdg_VersionCheck_Src.m"!][!//
[!INCLUDE "Wdg_PluginMacros.m"!][!//
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/

#define WDG_VENDOR_ID_CFG_EXT_C                    43
#define WDG_AR_RELEASE_MAJOR_VERSION_CFG_EXT_C     4
#define WDG_AR_RELEASE_MINOR_VERSION_CFG_EXT_C     7
#define WDG_AR_RELEASE_REVISION_VERSION_CFG_EXT_C  0
#define WDG_SW_MAJOR_VERSION_CFG_EXT_C             3
#define WDG_SW_MINOR_VERSION_CFG_EXT_C             0
#define WDG_SW_PATCH_VERSION_CFG_EXT_C             0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and Wdg_CfgExt header file are of the same vendor */
#if (WDG_VENDOR_ID_CFG_EXT_C != WDG_VENDOR_ID_CFG_EXT)
    #error "Wdg_CfgExt.c and Wdg_CfgExt.h have different vendor ids"
#endif

/* Check if current file and Wdg_CfgExt header file are of the same Autosar version */
#if ((WDG_AR_RELEASE_MAJOR_VERSION_CFG_EXT_C     != WDG_AR_RELEASE_MAJOR_VERSION_CFG_EXT) || \
     (WDG_AR_RELEASE_MINOR_VERSION_CFG_EXT_C     != WDG_AR_RELEASE_MINOR_VERSION_CFG_EXT) || \
     (WDG_AR_RELEASE_REVISION_VERSION_CFG_EXT_C  != WDG_AR_RELEASE_REVISION_VERSION_CFG_EXT))
#error "AutoSar Version Numbers of Wdg_CfgExt.c and Wdg_CfgExt.h are different"
#endif

/* Check if current file and Wdg_CfgExt header file are of the same software version */
#if ((WDG_SW_MAJOR_VERSION_CFG_EXT_C != WDG_SW_MAJOR_VERSION_CFG_EXT) || \
     (WDG_SW_MINOR_VERSION_CFG_EXT_C != WDG_SW_MINOR_VERSION_CFG_EXT) || \
     (WDG_SW_PATCH_VERSION_CFG_EXT_C != WDG_SW_PATCH_VERSION_CFG_EXT))
#error "Software Version Numbers of Wdg_CfgExt.c and Wdg_CfgExt.h are different"
#endif

/* Check if current file and Wdg_ChannelTypes header file are of the same vendor */
#if (WDG_VENDOR_ID_CFG_EXT_C != WDG_CHANNEL_TYPES_VENDOR_ID)
    #error "Wdg_CfgExt.c and Wdg_ChannelTypes.h have different vendor ids"
#endif

#if (( WDG_AR_RELEASE_MAJOR_VERSION_CFG_EXT_C    != WDG_CHANNEL_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (WDG_AR_RELEASE_MINOR_VERSION_CFG_EXT_C     != WDG_CHANNEL_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (WDG_AR_RELEASE_REVISION_VERSION_CFG_EXT_C  != WDG_CHANNEL_TYPES_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Wdg_CfgExt.c and Wdg_ChannelTypes.h are different"
#endif

#if ((WDG_SW_MAJOR_VERSION_CFG_EXT_C != WDG_CHANNEL_TYPES_SW_MAJOR_VERSION) || \
     (WDG_SW_MINOR_VERSION_CFG_EXT_C != WDG_CHANNEL_TYPES_SW_MINOR_VERSION) || \
     (WDG_SW_PATCH_VERSION_CFG_EXT_C != WDG_CHANNEL_TYPES_SW_PATCH_VERSION))
#error "Software Version Numbers of Wdg_CfgExt.c and Wdg_ChannelTypes.h are different"
#endif

/* Check if source file and Wdg_Cfg header file are of the same Autosar version */
#if (WDG_VENDOR_ID_CFG_EXT_C != WDG_VENDOR_ID_CFG)
    #error "Wdg_CfgExt.c and Wdg_Cfg.h have different vendor ids"
#endif

#if (( WDG_AR_RELEASE_MAJOR_VERSION_CFG_EXT_C    != WDG_AR_RELEASE_MAJOR_VERSION_CFG) || \
     (WDG_AR_RELEASE_MINOR_VERSION_CFG_EXT_C     != WDG_AR_RELEASE_MINOR_VERSION_CFG) || \
     (WDG_AR_RELEASE_REVISION_VERSION_CFG_EXT_C  != WDG_AR_RELEASE_REVISION_VERSION_CFG))
    #error "AutoSar Version Numbers of Wdg_CfgExt.c and Wdg_Cfg.h are different"
#endif

#if ((WDG_SW_MAJOR_VERSION_CFG_EXT_C != WDG_SW_MAJOR_VERSION_CFG) || \
     (WDG_SW_MINOR_VERSION_CFG_EXT_C != WDG_SW_MINOR_VERSION_CFG) || \
     (WDG_SW_PATCH_VERSION_CFG_EXT_C != WDG_SW_PATCH_VERSION_CFG))
#error "Software Version Numbers of Wdg_CfgExt.c and Wdg_Cfg.h are different"
#endif


/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/


/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/


/*==================================================================================================
*                                       LOCAL CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                      LOCAL VARIABLES
==================================================================================================*/


/*==================================================================================================
*                                       GLOBAL CONSTANTS
==================================================================================================*/

#define WDG_START_SEC_CONFIG_DATA_UNSPECIFIED

#include "Wdg_MemMap.h"

[!NOCODE!]
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

[!IF "num:i($isPreCompileOrLinkTimeEnabled) = 1"!]
    [!IF "variant:size()<=1"!]
        [!CODE!]const Wdg_ConfigType * const Wdg_Config[WDG_NO_OF_INSTANCES]=[!ENDCODE!][!CR!]
        [!CODE!]{[!ENDCODE!][!CR!]
        [!INDENT "1"!]
        [!FOR "i" = "0" TO "num:i(ecu:get('Wdg.Num.Of.Instances'))-1"!]
            [!IF "num:i($i) > 0"!]
                [!VAR "xPathModule" = "concat('ASPathDataOfSchema:/Wdg_43_Instance',$i,'_','TS_T40D34M30I0R0/Wdg')"!]
            [!ELSE!]
                [!VAR "xPathModule" = "concat('ASPathDataOfSchema:/','TS_T40D34M30I0R0/Wdg')"!]
            [!ENDIF!]
            [!IF "node:exists($xPathModule)"!]
                [!IF "node:value(concat($xPathModule,'/IMPLEMENTATION_CONFIG_VARIANT'))='VariantPreCompile' or node:value(concat($xPathModule,'/IMPLEMENTATION_CONFIG_VARIANT'))='VariantLinkTime'"!]
                    [!IF "node:value(concat($xPathModule,'/WdgGeneral/WdgEnableMultiCoreSupport'))"!]
                        [!VAR "PartitionName" = "text:split(node:value(concat($xPathModule,'/WdgGeneral/WdgEcucPartitionRef')),'/')[5]"!]
                    [!ENDIF!]
                    [!CODE!][!IF "num:i($i) > 0"!] ,[!ENDIF!]&Wdg_Config_[!"$i"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][!IF "var:defined('PartitionName')"!]_[!"$PartitionName"!][!ENDIF!][!ENDCODE!][!CR!]
                [!ELSE!]
                    [!CODE!][!IF "num:i($i) > 0"!] ,[!ENDIF!]NULL_PTR[!ENDCODE!][!CR!]
                [!ENDIF!]
            [!ELSE!]
                 [!CODE!][!IF "num:i($i) > 0"!] ,[!ENDIF!]NULL_PTR[!ENDCODE!][!CR!]
            [!ENDIF!]
        [!ENDFOR!]
        [!ENDINDENT!]
        [!CODE!]};[!ENDCODE!][!CR!]
    [!ENDIF!]
[!ENDIF!]
[!ENDNOCODE!][!//

const uint16 Wdg_au16CfgInitialTimeout[WDG_NO_OF_INSTANCES]=
{
[!NOCODE!]
[!INDENT "1"!]
[!FOR "i" = "0" TO "num:i(ecu:get('Wdg.Num.Of.Instances'))-1"!]
    [!IF "num:i($i) > 0"!]
        [!VAR "xPathModule" = "concat('ASPathDataOfSchema:/Wdg_43_Instance',$i,'_','TS_T40D34M30I0R0/Wdg')"!]
    [!ELSE!]
        [!VAR "xPathModule" = "concat('ASPathDataOfSchema:/','TS_T40D34M30I0R0/Wdg')"!]
    [!ENDIF!]

    [!IF "node:exists($xPathModule)"!]
        [!CODE!][!IF "num:i($i) > 0"!] ,[!ENDIF!]WDG_43_INSTANCE[!"$i"!]_INITIAL_TIMEOUT_U16[!ENDCODE!][!CR!]
    [!ELSE!]
        [!CODE!][!IF "num:i($i) > 0"!] ,[!ENDIF!]0[!ENDCODE!][!CR!]
    [!ENDIF!]
[!ENDFOR!]
[!ENDINDENT!]
[!ENDNOCODE!][!//
};

const uint16 Wdg_au16CfgMaxTimeout[WDG_NO_OF_INSTANCES]=
{
[!NOCODE!]
[!INDENT "1"!]
[!FOR "i" = "0" TO "num:i(ecu:get('Wdg.Num.Of.Instances'))-1"!]
    [!IF "num:i($i) > 0"!]
        [!VAR "xPathModule" = "concat('ASPathDataOfSchema:/Wdg_43_Instance',$i,'_','TS_T40D34M30I0R0/Wdg')"!]
    [!ELSE!]
        [!VAR "xPathModule" = "concat('ASPathDataOfSchema:/','TS_T40D34M30I0R0/Wdg')"!]
    [!ENDIF!]

    [!IF "node:exists($xPathModule)"!]
        [!CODE!][!IF "num:i($i) > 0"!] ,[!ENDIF!]WDG_43_INSTANCE[!"$i"!]_MAX_TIMEOUT_U16[!ENDCODE!][!CR!]
    [!ELSE!]
        [!CODE!][!IF "num:i($i) > 0"!] ,[!ENDIF!]0[!ENDCODE!][!CR!]
    [!ENDIF!]
[!ENDFOR!]
[!ENDINDENT!]
[!ENDNOCODE!][!//
};

#if (WDG_MULTICORE_ENABLED == STD_ON)
const uint32 Wdg_au32InstanceCoreUsed[WDG_NO_OF_INSTANCES]=
{
[!NOCODE!]
[!INDENT "1"!]
[!FOR "i" = "0" TO "num:i(ecu:get('Wdg.Num.Of.Instances'))-1"!]
    [!IF "num:i($i) > 0"!]
        [!VAR "xPathModule" = "concat('ASPathDataOfSchema:/Wdg_43_Instance',$i,'_','TS_T40D34M30I0R0/Wdg')"!]
    [!ELSE!]
        [!VAR "xPathModule" = "concat('ASPathDataOfSchema:/','TS_T40D34M30I0R0/Wdg')"!]
    [!ENDIF!]
    [!CODE!][!IF "num:i($i) > 0"!] ,[!ENDIF!][!ENDCODE!][!CALL "WdgCoreConfig", "WdgNo" = "$xPathModule"!][!CR!]
[!ENDFOR!]
[!ENDINDENT!]
[!ENDNOCODE!][!//
};
#endif

#define WDG_STOP_SEC_CONFIG_DATA_UNSPECIFIED
/**
* @brief Include Memory mapping specification
*
*/
#include "Wdg_MemMap.h"



[!NOCODE!][!//
[!VAR "WdgDisableDemReport" = "0"!]
[!FOR "i" = "0" TO "num:i(ecu:get('Wdg.Num.Of.Instances'))-1"!]
    [!IF "num:i($i) > 0"!]
        [!VAR "xPathModule" = "concat('ASPathDataOfSchema:/Wdg_43_Instance',$i,'_','TS_T40D34M30I0R0/Wdg')"!]
    [!ELSE!]
        [!VAR "xPathModule" = "concat('ASPathDataOfSchema:/','TS_T40D34M30I0R0/Wdg')"!]
    [!ENDIF!]
    [!IF "node:exists(concat($xPathModule,'/WdgDemEventParameterRefs'))"!]
        [!IF "node:value(concat($xPathModule,'/WdgGeneral/AutosarExt/WdgDisableDemReportErrorStatus'))='false'"!]
            [!VAR "WdgDisableDemReport"    = "1"!]
            [!CODE!]#define WDG_START_SEC_CONST_UNSPECIFIED[!ENDCODE!][!CR!]
            [!CODE!]#include "Wdg_MemMap.h"[!ENDCODE!][!CR!][!CR!]
            [!BREAK!]
        [!ENDIF!]
    [!ENDIF!]
[!ENDFOR!]

[!IF "num:i($WdgDisableDemReport) = 1"!]

    [!VAR "isWdgDemEventAvailable"    = "0"!]
    [!FOR "i" = "0" TO "num:i(ecu:get('Wdg.Num.Of.Instances'))-1"!]
        [!IF "num:i($i) > 0"!]
            [!VAR "xPathModule" = "concat('ASPathDataOfSchema:/Wdg_43_Instance',$i,'_','TS_T40D34M30I0R0/Wdg')"!]
        [!ELSE!]
            [!VAR "xPathModule" = "concat('ASPathDataOfSchema:/','TS_T40D34M30I0R0/Wdg')"!]
        [!ENDIF!]
            [!IF "node:exists(concat($xPathModule,'/WdgDemEventParameterRefs'))"!]
                [!IF "node:value(concat($xPathModule,'/WdgGeneral/AutosarExt/WdgDisableDemReportErrorStatus'))='false'"!]
                    [!VAR "isWdgDemEventAvailable" = "1"!]
                    [!IF "node:exists(concat($xPathModule,'/WdgDemEventParameterRefs/WDG_E_DISABLE_REJECTED'))"!]
                        [!VAR "isWdgDemEventAvailable" = "0"!]
                        [!CODE!]const Mcal_DemErrorType Wdg_E_Disable_Rejected = [!ENDCODE!][!CR!]
                        [!CODE!]{[!ENDCODE!][!CR!]
                        [!CODE!]    (uint32)STD_ON,[!ENDCODE!][!CR!]
                        [!CODE!]    (uint16)DemConf_DemEventParameter_[!"string(node:ref(node:refs(concat($xPathModule,'/WdgDemEventParameterRefs/WDG_E_DISABLE_REJECTED')))/@name)"!][!ENDCODE!][!CR!]
                        [!CODE!]};[!ENDCODE!][!CR!][!CR!]
                        [!BREAK!]
                    [!ENDIF!]
                [!ENDIF!]
            [!ENDIF!]
    [!ENDFOR!]
    [!IF "num:i($isWdgDemEventAvailable) = 1"!]
        [!CODE!]const Mcal_DemErrorType Wdg_E_Disable_Rejected = [!ENDCODE!][!CR!]
        [!CODE!]{[!ENDCODE!][!CR!]
        [!CODE!]   (uint32)STD_OFF,[!ENDCODE!][!CR!]
        [!CODE!]   (uint16)0U[!ENDCODE!][!CR!]
        [!CODE!]};[!ENDCODE!][!CR!][!CR!]
    [!ENDIF!]

    [!VAR "isWdgDemEventAvailable"    = "0"!]
    [!FOR "i" = "0" TO "num:i(ecu:get('Wdg.Num.Of.Instances'))-1"!]
        [!IF "num:i($i) > 0"!]
            [!VAR "xPathModule" = "concat('ASPathDataOfSchema:/Wdg_43_Instance',$i,'_','TS_T40D34M30I0R0/Wdg')"!]
        [!ELSE!]
            [!VAR "xPathModule" = "concat('ASPathDataOfSchema:/','TS_T40D34M30I0R0/Wdg')"!]
        [!ENDIF!]
        [!IF "node:exists(concat($xPathModule,'/WdgDemEventParameterRefs'))"!]
            [!IF "node:value(concat($xPathModule,'/WdgGeneral/AutosarExt/WdgDisableDemReportErrorStatus'))='false'"!]
                [!VAR "isWdgDemEventAvailable"    = "1"!]
                [!IF "node:exists(concat($xPathModule,'/WdgDemEventParameterRefs/WDG_E_MODE_FAILED'))"!]
                    [!VAR "isWdgDemEventAvailable" = "0"!]
                    [!CODE!]const Mcal_DemErrorType Wdg_E_Mode_Failed = [!ENDCODE!][!CR!]
                    [!CODE!]{[!ENDCODE!][!CR!]
                    [!CODE!]    (uint32)STD_ON,[!ENDCODE!][!CR!]
                    [!CODE!]    (uint16)DemConf_DemEventParameter_[!"string(node:ref(node:refs(concat($xPathModule,'/WdgDemEventParameterRefs/WDG_E_MODE_FAILED')))/@name)"!][!ENDCODE!][!CR!]
                    [!CODE!]};[!ENDCODE!][!CR!][!CR!]
                    [!BREAK!]
                [!ENDIF!]
            [!ENDIF!]
        [!ENDIF!]
    [!ENDFOR!]
    [!IF "num:i($isWdgDemEventAvailable) = 1"!]
        [!CODE!]const Mcal_DemErrorType Wdg_E_Mode_Failed = [!ENDCODE!][!CR!]
        [!CODE!]{[!ENDCODE!][!CR!]
        [!CODE!]   (uint32)STD_OFF,[!ENDCODE!][!CR!]
        [!CODE!]   (uint16)0U[!ENDCODE!][!CR!]
        [!CODE!]};[!ENDCODE!][!CR!][!CR!]
    [!ENDIF!]
[!ENDIF!]


[!FOR "i" = "0" TO "num:i(ecu:get('Wdg.Num.Of.Instances'))-1"!]
    [!IF "num:i($i) > 0"!]
        [!VAR "xPathModule" = "concat('ASPathDataOfSchema:/Wdg_43_Instance',$i,'_','TS_T40D34M30I0R0/Wdg')"!]
    [!ELSE!]
        [!VAR "xPathModule" = "concat('ASPathDataOfSchema:/','TS_T40D34M30I0R0/Wdg')"!]
    [!ENDIF!]
    [!IF "node:exists(concat($xPathModule,'/WdgDemEventParameterRefs'))"!]
        [!IF "node:value(concat($xPathModule,'/WdgGeneral/AutosarExt/WdgDisableDemReportErrorStatus'))='false'"!]
            [!CODE!]#define WDG_STOP_SEC_CONST_UNSPECIFIED[!ENDCODE!][!CR!]
            [!CODE!]#include "Wdg_MemMap.h"[!ENDCODE!][!CR!]
            [!BREAK!]
        [!ENDIF!]
    [!ENDIF!]
[!ENDFOR!]
[!ENDNOCODE!][!//


/*==================================================================================================
*                                       GLOBAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/

/*==================================================================================================
*                                      LOCAL FUNCTIONS
==================================================================================================*/

/*==================================================================================================
*                                     GLOBAL FUNCTIONS
==================================================================================================*/
#ifdef __cplusplus
}
#endif

/** @} */

