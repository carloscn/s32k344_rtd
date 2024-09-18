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

#ifndef WDG_CFG_H
#define WDG_CFG_H

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
#include "Wdg_Cfg_Defines.h"
#include "Mcal.h"
[!NOCODE!][!//
[!VAR "WdgDisableDemReport" = "1"!]
[!FOR "i" = "0" TO "num:i(ecu:get('Wdg.Num.Of.Instances'))-1"!]
    [!IF "num:i($i) > 0"!]
        [!VAR "xPathModule" = "concat('ASPathDataOfSchema:/Wdg_43_Instance',$i,'_','TS_T40D34M30I0R0/Wdg')"!]
    [!ELSE!]
        [!VAR "xPathModule" = "concat('ASPathDataOfSchema:/','TS_T40D34M30I0R0/Wdg')"!]
    [!ENDIF!]

    [!IF "node:exists($xPathModule)"!]
    [!IF "node:exists(concat($xPathModule,'/WdgDemEventParameterRefs'))"!]
        [!IF "node:value(concat($xPathModule,'/WdgGeneral/AutosarExt/WdgDisableDemReportErrorStatus'))='false'"!]
            [!VAR "WdgDisableDemReport" = "0"!]
        [!ENDIF!]
    [!ENDIF!]
    [!ENDIF!][!//
[!ENDFOR!]
[!ENDNOCODE!][!//

#if (WDG_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
  #include "Dem.h"
#endif



[!NOCODE!]
[!INDENT "0"!]
[!FOR "i" = "0" TO "num:i(ecu:get('Wdg.Num.Of.Instances'))-1"!]
    [!IF "num:i($i) > 0"!]
        [!VAR "xPathModule" = "concat('ASPathDataOfSchema:/Wdg_43_Instance',$i,'_','TS_T40D34M30I0R0/Wdg')"!]
    [!ELSE!]
        [!VAR "xPathModule" = "concat('ASPathDataOfSchema:/','TS_T40D34M30I0R0/Wdg')"!]
    [!ENDIF!]
    [!IF "node:exists($xPathModule)"!]
        [!IF "var:defined('postBuildVariant')"!]
            [!LOOP "variant:all()"!][!//
                [!CODE!]#include "Wdg_43_Instance[!"$i"!]_[!"."!]_PBcfg.h"[!ENDCODE!][!CR!]
            [!ENDLOOP!]
        [!ELSE!]
            [!CODE!]#include "Wdg_43_Instance[!"$i"!]_PBcfg.h"[!ENDCODE!][!CR!]
        [!ENDIF!]
    [!ENDIF!]
[!ENDFOR!]
[!ENDINDENT!]
[!INCLUDE "Wdg_VersionCheck_Inc.m"!]
[!INCLUDE "Wdg_PluginMacros.m"!]
[!ENDNOCODE!]
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
[!NOCODE!]
[!INDENT "0"!]
[!FOR "i" = "0" TO "num:i(ecu:get('Wdg.Num.Of.Instances'))-1"!]
    [!IF "num:i($i) > 0"!]
        [!VAR "xPathModule" = "concat('ASPathDataOfSchema:/Wdg_43_Instance',$i,'_','TS_T40D34M30I0R0/Wdg')"!]
    [!ELSE!]
        [!VAR "xPathModule" = "concat('ASPathDataOfSchema:/','TS_T40D34M30I0R0/Wdg')"!]
    [!ENDIF!]
    [!IF "node:exists($xPathModule)"!]
        [!IF "var:defined('postBuildVariant')"!]
            [!LOOP "variant:all()"!][!//
                [!CODE!]
                    /* Check if current file and Wdg_43_Instance[!"$i"!]_[!"."!]_PBcfg.h header file are of the same vendor */
                    #if (WDG_VENDOR_ID_CFG != WDG_43_INSTANCE[!"$i"!]_VENDOR_ID_[!"."!]_PBCFG)
                        #error "Wdg_Cfg.h and Wdg_43_Instance[!"$i"!]_[!"."!]_PBcfg.h have different vendor ids"
                    #endif
    
                    /* Check if current file and Wdg_43_Instance[!"$i"!]_[!"."!]_PBcfg.h header file are of the same Autosar version */
                    #if ((WDG_AR_RELEASE_MAJOR_VERSION_CFG    != WDG_43_INSTANCE[!"$i"!]_AR_RELEASE_MAJOR_VERSION_[!"."!]_PBCFG) || \
                        (WDG_AR_RELEASE_MINOR_VERSION_CFG    != WDG_43_INSTANCE[!"$i"!]_AR_RELEASE_MINOR_VERSION_[!"."!]_PBCFG) || \
                        (WDG_AR_RELEASE_REVISION_VERSION_CFG != WDG_43_INSTANCE[!"$i"!]_AR_RELEASE_REVISION_VERSION_[!"."!]_PBCFG))
                        #error "AutoSar Version Numbers of Wdg_Cfg.h and Wdg_43_Instance[!"$i"!]_[!"."!]_PBcfg.h are different"
                    #endif
                    /* Check if current file and Wdg_43_Instance[!"$i"!]_[!"."!]_PBcfg.h header file are of the same Software version */
                    #if ((WDG_SW_MAJOR_VERSION_CFG != WDG_43_INSTANCE[!"$i"!]_SW_MAJOR_VERSION_[!"."!]_PBCFG) || \
                        (WDG_SW_MINOR_VERSION_CFG != WDG_43_INSTANCE[!"$i"!]_SW_MINOR_VERSION_[!"."!]_PBCFG) || \
                        (WDG_SW_PATCH_VERSION_CFG != WDG_43_INSTANCE[!"$i"!]_SW_PATCH_VERSION_[!"."!]_PBCFG))
                        #error "Software Version Numbers of Wdg_Cfg.h and Wdg_43_Instance[!"$i"!]_[!"."!]_PBcfg.h are different"
                    #endif
                [!ENDCODE!]
            [!ENDLOOP!]
        [!ELSE!]
                [!CODE!]
                    /* Check if current file and Wdg_43_Instance[!"$i"!]_[!"."!]_PBcfg.h header file are of the same vendor */
                    #if (WDG_VENDOR_ID_CFG != WDG_43_INSTANCE[!"$i"!]_VENDOR_ID_PBCFG)
                        #error "Wdg_Cfg.h and Wdg_43_Instance[!"$i"!]_PBcfg.h have different vendor ids"
                    #endif
    
                    /* Check if current file and Wdg_43_Instance[!"$i"!]_PBcfg.h header file are of the same Autosar version */
                    #if ((WDG_AR_RELEASE_MAJOR_VERSION_CFG    != WDG_43_INSTANCE[!"$i"!]_AR_RELEASE_MAJOR_VERSION_PBCFG) || \
                        (WDG_AR_RELEASE_MINOR_VERSION_CFG    != WDG_43_INSTANCE[!"$i"!]_AR_RELEASE_MINOR_VERSION_PBCFG) || \
                        (WDG_AR_RELEASE_REVISION_VERSION_CFG != WDG_43_INSTANCE[!"$i"!]_AR_RELEASE_REVISION_VERSION_PBCFG))
                        #error "AutoSar Version Numbers of Wdg_Cfg.h and Wdg_43_Instance[!"$i"!]_PBcfg.h are different"
                    #endif
                    /* Check if current file and Wdg_43_Instance[!"$i"!]_PBcfg.h header file are of the same Software version */
                    #if ((WDG_SW_MAJOR_VERSION_CFG != WDG_43_INSTANCE[!"$i"!]_SW_MAJOR_VERSION_PBCFG) || \
                        (WDG_SW_MINOR_VERSION_CFG != WDG_43_INSTANCE[!"$i"!]_SW_MINOR_VERSION_PBCFG) || \
                        (WDG_SW_PATCH_VERSION_CFG != WDG_43_INSTANCE[!"$i"!]_SW_PATCH_VERSION_PBCFG))
                        #error "Software Version Numbers of Wdg_Cfg.h and Wdg_43_Instance[!"$i"!]_PBcfg.h are different"
                    #endif
                [!ENDCODE!]
        [!ENDIF!]
    [!ENDIF!]
[!ENDFOR!]
[!ENDINDENT!]
[!ENDNOCODE!]
 #ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
     /* Check if source file and Mcal header file are of the same Autosar version */
     #if ((WDG_AR_RELEASE_MAJOR_VERSION_CFG != MCAL_AR_RELEASE_MAJOR_VERSION) || \
          (WDG_AR_RELEASE_MINOR_VERSION_CFG != MCAL_AR_RELEASE_MINOR_VERSION))
         #error "AutoSar Version Numbers of Wdg_Cfg.h and Mcal.h are different"
     #endif

    #if ((WDG_AR_RELEASE_MAJOR_VERSION_CFG    != WDGIF_TYPES_AR_RELEASE_MAJOR_VERSION) || \
         (WDG_AR_RELEASE_MINOR_VERSION_CFG    != WDGIF_TYPES_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of Wdg_Cfg.h and WdgIf_Types.h are different"
    #endif
    [!IF "$WdgDisableDemReport = 0"!]
    #if (WDG_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
        /* Check if source file and Dem header file are of the same Autosar version */
        #if ((WDG_AR_RELEASE_MAJOR_VERSION_CFG != DEM_AR_RELEASE_MAJOR_VERSION) || \
            (WDG_AR_RELEASE_MINOR_VERSION_CFG != DEM_AR_RELEASE_MINOR_VERSION))
            #error "AutoSar Version Numbers of Wdg_Cfg.h and Dem.h are different"
        #endif
    #endif
    [!ENDIF!]
#endif /* DISABLE_MCAL_INTERMODULE_ASR_CHECK */


/*==================================================================================================
*                                       GLOBAL CONSTANTS
==================================================================================================*/


[!NOCODE!][!//
    [!FOR "i" = "0" TO "num:i(ecu:get('Wdg.Num.Of.Instances'))-1"!]
        [!IF "num:i($i) > 0"!]
            [!VAR "xPathModule" = "concat('ASPathDataOfSchema:/Wdg_43_Instance',$i,'_','TS_T40D34M30I0R0/Wdg')"!]
        [!ELSE!]
            [!VAR "xPathModule" = "concat('ASPathDataOfSchema:/','TS_T40D34M30I0R0/Wdg')"!]
        [!ENDIF!]
            [!IF "node:exists(concat($xPathModule,'/WdgDemEventParameterRefs'))"!]
                [!IF "node:value(concat($xPathModule,'/WdgGeneral/AutosarExt/WdgDisableDemReportErrorStatus'))='false'"!]
                    [!CODE!]#define WDG_START_SEC_CONST_UNSPECIFIED[!ENDCODE!][!CR!]
                    [!CODE!]#include "Wdg_MemMap.h"[!ENDCODE!][!CR!][!CR!]

                    [!CODE!]/**[!ENDCODE!][!CR!]
                    [!CODE!]* @brief Dem error codes[!ENDCODE!][!CR!]
                    [!CODE!]*/[!ENDCODE!][!CR!][!CR!]
                    
                    [!CODE!] extern const Mcal_DemErrorType Wdg_E_Disable_Rejected;[!ENDCODE!][!CR!][!CR!]
                    [!CODE!] extern const Mcal_DemErrorType Wdg_E_Mode_Failed;[!ENDCODE!][!CR!][!CR!]

                    [!CODE!]#define WDG_STOP_SEC_CONST_UNSPECIFIED[!ENDCODE!][!CR!]
                    [!CODE!]#include "Wdg_MemMap.h"[!ENDCODE!][!CR!][!CR!]

                    [!CODE!]/**[!ENDCODE!][!CR!]
                    [!CODE!]* @brief Dem error codes[!ENDCODE!][!CR!]
                    [!CODE!]*/[!ENDCODE!][!CR!][!CR!]
                    [!BREAK!]
                [!ENDIF!]
            [!ENDIF!]
    [!ENDFOR!]
[!ENDNOCODE!][!//

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/
[!NOCODE!]
[!INDENT "0"!]
[!FOR "i" = "0" TO "num:i(ecu:get('Wdg.Num.Of.Instances'))-1"!][!CR!]
    [!IF "num:i($i) > 0"!]
        [!VAR "xPathModule" = "concat('ASPathDataOfSchema:/Wdg_43_Instance',$i,'_','TS_T40D34M30I0R0/Wdg')"!]
    [!ELSE!]
        [!VAR "xPathModule" = "concat('ASPathDataOfSchema:/','TS_T40D34M30I0R0/Wdg')"!]
    [!ENDIF!]
    [!IF "node:exists($xPathModule)"!]
        [!CODE!]#define WDG_43_INSTANCE[!"$i"!]_CONFIG_EXT [!ENDCODE!]
        [!IF "var:defined('postBuildVariant')"!]
            [!LOOP "variant:all()"!]
                [!CODE!]WDG_43_INSTANCE[!"$i"!]_CONFIG_[!"."!]_PB[!ENDCODE!][!CR!]
            [!ENDLOOP!]
        [!ELSE!]
            [!CODE!]WDG_43_INSTANCE[!"$i"!]_CONFIG_PB[!ENDCODE!]
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

#endif /* WDG_CFG_H */
