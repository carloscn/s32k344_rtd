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

#include "Wdg_43_Instance0_Ipw_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBcfg.h"

[!INCLUDE "Wdg_VersionCheck_Src_PB.m"!][!//
[!INCLUDE "Wdg_PluginMacros.m"!][!//
 /*==================================================================================================
 *                              SOURCE FILE VERSION INFORMATION
 ==================================================================================================*/
#define WDG_43_INSTANCE0_IPW_VENDOR_ID_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_C                    43
#define WDG_43_INSTANCE0_IPW_AR_RELEASE_MAJOR_VERSION_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_C     4
#define WDG_43_INSTANCE0_IPW_AR_RELEASE_MINOR_VERSION_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_C     7
#define WDG_43_INSTANCE0_IPW_AR_RELEASE_REVISION_VERSION_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_C  0
#define WDG_43_INSTANCE0_IPW_SW_MAJOR_VERSION_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_C             3
#define WDG_43_INSTANCE0_IPW_SW_MINOR_VERSION_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_C             0
#define WDG_43_INSTANCE0_IPW_SW_PATCH_VERSION_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_C             0

 /*==================================================================================================
 *                                      FILE VERSION CHECKS
 ==================================================================================================*/
 /* Check if current file and WDG configuration header file are of the same vendor */
#if (WDG_43_INSTANCE0_IPW_VENDOR_ID_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_C != WDG_43_INSTANCE0_IPW_VENDOR_ID_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG)
#error "Wdg_43_Instance0_Ipw_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBcfg.c and Wdg_43_Instance0_Ipw_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBcfg.h have different vendor ids"
#endif

/* Check if current file and Wdg_Cfg header file are of the same Autosar version */
#if ((WDG_43_INSTANCE0_IPW_AR_RELEASE_MAJOR_VERSION_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_C     != WDG_43_INSTANCE0_IPW_AR_RELEASE_MAJOR_VERSION_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG) || \
     (WDG_43_INSTANCE0_IPW_AR_RELEASE_MINOR_VERSION_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_C     != WDG_43_INSTANCE0_IPW_AR_RELEASE_MINOR_VERSION_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG) || \
     (WDG_43_INSTANCE0_IPW_AR_RELEASE_REVISION_VERSION_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_C  != WDG_43_INSTANCE0_IPW_AR_RELEASE_REVISION_VERSION_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG))
#error "AutoSar Version Numbers of Wdg_43_Instance0_Ipw_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBcfg.c and Wdg_43_Instance0_Ipw_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBcfg.h are different"
#endif

/* Check if current file and Wdg_Cfg header file are of the same software version */
#if ((WDG_43_INSTANCE0_IPW_SW_MAJOR_VERSION_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_C != WDG_43_INSTANCE0_IPW_SW_MAJOR_VERSION_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG) || \
     (WDG_43_INSTANCE0_IPW_SW_MINOR_VERSION_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_C != WDG_43_INSTANCE0_IPW_SW_MINOR_VERSION_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG) || \
     (WDG_43_INSTANCE0_IPW_SW_PATCH_VERSION_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_C != WDG_43_INSTANCE0_IPW_SW_PATCH_VERSION_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG))
#error "Software Version Numbers of Wdg_43_Instance0_Ipw_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBcfg.c and Wdg_43_Instance0_Ipw_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBcfg.h are different"
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
*                                     GLOBAL FUNCTIONS
==================================================================================================*/

/*==================================================================================================
*                                       GLOBAL CONSTANTS
==================================================================================================*/

#define WDG_START_SEC_CONFIG_DATA_UNSPECIFIED

#include "Wdg_MemMap.h"

/*Structures for Instance 0 */
[!VAR "xPathModule" = "concat('ASPathDataOfSchema:/','TS_T40D34M30I0R0/Wdg')"!][!//
[!IF "node:exists($xPathModule)"!][!//
const Wdg_Ipw_ConfigType Wdg_Ipw_OffModeSettings_0[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]=
{
    (Wdg_Ipw_IpType) WDG_IPW_SWT_IP
    ,&Swt_Ip_OffModeSettings_0[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]
#if (AEWDOG_IP_USED == STD_ON)
    ,NULL_PTR
#endif /*(AEWDOG_IP_USED == STD_ON)*/
};

const Wdg_Ipw_ConfigType Wdg_Ipw_SlowModeSettings_0[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]=
{
    (Wdg_Ipw_IpType) WDG_IPW_SWT_IP
    ,&Swt_Ip_SlowModeSettings_0[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]
#if (AEWDOG_IP_USED == STD_ON)
    ,NULL_PTR
#endif /*(AEWDOG_IP_USED == STD_ON)*/
};

const Wdg_Ipw_ConfigType Wdg_Ipw_FastModeSettings_0[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]=
{
    (Wdg_Ipw_IpType) WDG_IPW_SWT_IP
    ,&Swt_Ip_FastModeSettings_0[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]
#if (AEWDOG_IP_USED == STD_ON)
    ,NULL_PTR
#endif /*(AEWDOG_IP_USED == STD_ON)*/
};
[!ENDIF!][!//

#define WDG_STOP_SEC_CONFIG_DATA_UNSPECIFIED

#include "Wdg_MemMap.h"

/*==================================================================================================
*                                       GLOBAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/


/*==================================================================================================
    *                                      LOCAL FUNCTIONS
==================================================================================================*/

#ifdef __cplusplus
}
#endif


/** @} */

