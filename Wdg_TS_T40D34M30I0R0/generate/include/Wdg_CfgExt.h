
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

#ifndef WDG_CFG_EXT_H
#define WDG_CFG_EXT_H

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
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Wdg_ChannelTypes.h"
#include "Mcal.h"
#include "Wdg_Cfg.h"
[!INCLUDE "Wdg_PluginMacros.m"!][!//
[!INCLUDE "Wdg_VersionCheck_Inc.m"!][!//
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/

#define WDG_VENDOR_ID_CFG_EXT                    43
#define WDG_AR_RELEASE_MAJOR_VERSION_CFG_EXT     4
#define WDG_AR_RELEASE_MINOR_VERSION_CFG_EXT     7
#define WDG_AR_RELEASE_REVISION_VERSION_CFG_EXT  0
#define WDG_SW_MAJOR_VERSION_CFG_EXT             3
#define WDG_SW_MINOR_VERSION_CFG_EXT             0
#define WDG_SW_PATCH_VERSION_CFG_EXT             0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and WDG configuration header file are of the same vendor */
#if (WDG_VENDOR_ID_CFG_EXT != WDG_CHANNEL_TYPES_VENDOR_ID)
#error "Wdg_CfgExt.h and Wdg_ChannelTypes.h have different vendor ids"
#endif

/* Check if current file and Wdg_ChannelTypes header file are of the same Autosar version */
#if ((WDG_AR_RELEASE_MAJOR_VERSION_CFG_EXT     != WDG_CHANNEL_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (WDG_AR_RELEASE_MINOR_VERSION_CFG_EXT     != WDG_CHANNEL_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (WDG_AR_RELEASE_REVISION_VERSION_CFG_EXT  != WDG_CHANNEL_TYPES_AR_RELEASE_REVISION_VERSION))
#error "AutoSar Version Numbers of Wdg_CfgExt.h and Wdg_ChannelTypes.h are different"
#endif

/* Check if current file and Wdg_Ipw_Types header file are of the same software version */
#if ((WDG_SW_MAJOR_VERSION_CFG_EXT != WDG_CHANNEL_TYPES_SW_MAJOR_VERSION) || \
     (WDG_SW_MINOR_VERSION_CFG_EXT != WDG_CHANNEL_TYPES_SW_MINOR_VERSION) || \
     (WDG_SW_PATCH_VERSION_CFG_EXT != WDG_CHANNEL_TYPES_SW_PATCH_VERSION))
#error "Software Version Numbers of Wdg_CfgExt.h and Wdg_ChannelTypes.h are different"
#endif

/* Check if source file and Wdg_Cfg header file are of the same Autosar version */
#if (WDG_VENDOR_ID_CFG_EXT != WDG_VENDOR_ID_CFG)
#error "Wdg_CfgExt.h and Wdg_Cfg.h have different vendor ids"
#endif

#if ((WDG_AR_RELEASE_MAJOR_VERSION_CFG_EXT     != WDG_AR_RELEASE_MAJOR_VERSION_CFG) || \
     (WDG_AR_RELEASE_MINOR_VERSION_CFG_EXT     != WDG_AR_RELEASE_MINOR_VERSION_CFG) || \
     (WDG_AR_RELEASE_REVISION_VERSION_CFG_EXT  != WDG_AR_RELEASE_REVISION_VERSION_CFG))
    #error "AutoSar Version Numbers of Wdg_CfgExt.h and Wdg_Cfg.h are different"
#endif

#if ((WDG_SW_MAJOR_VERSION_CFG_EXT != WDG_SW_MAJOR_VERSION_CFG) || \
     (WDG_SW_MINOR_VERSION_CFG_EXT != WDG_SW_MINOR_VERSION_CFG) || \
     (WDG_SW_PATCH_VERSION_CFG_EXT != WDG_SW_PATCH_VERSION_CFG))
#error "Software Version Numbers of Wdg_CfgExt.h and Wdg_Cfg.h are different"
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if source file and Mcal header file are of the same Autosar version */
    #if (( WDG_AR_RELEASE_MAJOR_VERSION_CFG_EXT != MCAL_AR_RELEASE_MAJOR_VERSION) || \
        ( WDG_AR_RELEASE_MINOR_VERSION_CFG_EXT  != MCAL_AR_RELEASE_MINOR_VERSION))
    #error "AutoSar Version Numbers of Wdg_CfgExt.h and Mcal.h are different"
    #endif
#endif /* DISABLE_MCAL_INTERMODULE_ASR_CHECK */

/*==================================================================================================
*                                       GLOBAL CONSTANTS
==================================================================================================*/
#if (WDG_MULTICORE_ENABLED == STD_ON)
    #define WDG_START_SEC_CONFIG_DATA_32
    #include "Wdg_MemMap.h"

    extern const uint32 Wdg_au32InstanceCoreUsed[WDG_NO_OF_INSTANCES];

    #define WDG_STOP_SEC_CONFIG_DATA_32
    #include "Wdg_MemMap.h"
#endif

#define WDG_START_SEC_CONFIG_DATA_16

#include "Wdg_MemMap.h"

extern const uint16 Wdg_au16CfgInitialTimeout[WDG_NO_OF_INSTANCES];

extern const uint16 Wdg_au16CfgMaxTimeout[WDG_NO_OF_INSTANCES];

#define WDG_STOP_SEC_CONFIG_DATA_16
#include "Wdg_MemMap.h"

#if (WDG_PRECOMPILE_SUPPORT == STD_ON)

#define WDG_START_SEC_CONFIG_DATA_UNSPECIFIED

#include "Wdg_MemMap.h"

extern const Wdg_ConfigType * const Wdg_Config[WDG_NO_OF_INSTANCES];
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

[!IF "num:i($isPreCompileOrLinkTimeEnabled) = 1"!]
    [!IF "variant:size()<=1"!]
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
                    [!IF "var:defined('postBuildVariant')"!]
                        [!CODE!]extern const Wdg_ConfigType Wdg_Config_[!"$i"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!IF "var:defined('PartitionName')"!]_[!"$PartitionName"!][!ENDIF!][!ENDIF!];[!ENDCODE!][!CR!]
                    [!ELSE!]
                        [!CODE!]extern const Wdg_ConfigType Wdg_Config_[!"$i"!][!IF "var:defined('PartitionName')"!]_[!"$PartitionName"!][!ENDIF!];[!ENDCODE!][!CR!]
                    [!ENDIF!]
                [!ENDIF!]
            [!ENDIF!]
        [!ENDFOR!]
    [!ENDIF!]
[!ENDIF!]
[!ENDINDENT!]
[!ENDNOCODE!]

#define WDG_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Wdg_MemMap.h"

#endif
/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/

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

#endif /* WDG_CFG_EXT_H */


