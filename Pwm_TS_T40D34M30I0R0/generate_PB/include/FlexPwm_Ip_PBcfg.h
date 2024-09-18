[!AUTOSPACING!]
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

#ifndef FLEXPWM_IP[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_H
#define FLEXPWM_IP[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_H

/**
*   @file       FlexPwm_Ip_PBcfg.h
*
*   @addtogroup flexpwm_ip FlexPwm IPL
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
#include "FlexPwm_Ip_Types.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define FLEXPWM_IP[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PB_CFG_VENDOR_ID                       43
#define FLEXPWM_IP[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PB_CFG_AR_RELEASE_MAJOR_VERSION        4
#define FLEXPWM_IP[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PB_CFG_AR_RELEASE_MINOR_VERSION        7
#define FLEXPWM_IP[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PB_CFG_AR_RELEASE_REVISION_VERSION     0
#define FLEXPWM_IP[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PB_CFG_SW_MAJOR_VERSION                3
#define FLEXPWM_IP[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PB_CFG_SW_MINOR_VERSION                0
#define FLEXPWM_IP[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PB_CFG_SW_PATCH_VERSION                0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if header file and FlexPwm_Ip_Types header file are of the same vendor */
#if (FLEXPWM_IP[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PB_CFG_VENDOR_ID != FLEXPWM_IP_TYPES_VENDOR_ID)
    #error "Vendor IDs of FlexPwm_Ip[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg.h and FlexPwm_Ip_Types.h are different."
#endif

/* Check if header file and FlexPwm_Ip_Types header file are of the same AUTOSAR version */
#if ((FLEXPWM_IP[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PB_CFG_AR_RELEASE_MAJOR_VERSION    != FLEXPWM_IP_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (FLEXPWM_IP[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PB_CFG_AR_RELEASE_MINOR_VERSION    != FLEXPWM_IP_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (FLEXPWM_IP[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PB_CFG_AR_RELEASE_REVISION_VERSION != FLEXPWM_IP_TYPES_AR_RELEASE_REVISION_VERSION))
    #error "AUTOSAR version numbers of FlexPwm_Ip[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg.h and FlexPwm_Ip_Types.h are different."
#endif

/* Check if header file and FlexPwm_Ip_Types header file are of the same software version */
#if ((FLEXPWM_IP[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PB_CFG_SW_MAJOR_VERSION != FLEXPWM_IP_TYPES_SW_MAJOR_VERSION) || \
     (FLEXPWM_IP[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PB_CFG_SW_MINOR_VERSION != FLEXPWM_IP_TYPES_SW_MINOR_VERSION) || \
     (FLEXPWM_IP[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PB_CFG_SW_PATCH_VERSION != FLEXPWM_IP_TYPES_SW_PATCH_VERSION))
    #error "Software version numbers of FlexPwm_Ip[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg.h and FlexPwm_Ip_Types.h are different."
#endif

/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/
[!VAR "FlexPwmHwStartFrom0" = "'false'"!]
[!IF "ecu:has('Pwm.FlexPwmHwModules.List') and text:contains(ecu:get('Pwm.FlexPwmHwModules.List'), 'FlexPwm_0')"!]
    [!VAR "FlexPwmHwStartFrom0" = "'true'"!]
[!ENDIF!]
[!LOOP "./PwmChannelConfigSet/FlexPwm/*"!]
    [!VAR "instanceId" = "substring-after(./FlexPwmModule, '_')"!]
    [!LOOP "./FlexPwmSubModules/*"!]
        [!VAR "SubModule" = "substring-after(./FlexPwmSubModule,'SubModule_')"!]
    /* FlexPwm submodule index for configuration */
#define FLEXPWM_IP_SUB[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_I[!"$instanceId"!]_SUB[!"$SubModule"!]_CFG      ([!"num:i($SubModule)"!]U)
[!CR!]
        [!LOOP "./FlexPwmChannels/*"!]
            [!VAR "channelCfgName" = "substring-after(./FlexPwmChannel,'FLEXPWM_IP_')"!]
/* FlexPwm instance index for configuration [!"$channelCfgName"!] */
[!IF "$FlexPwmHwStartFrom0 = 'true'"!]
#define FLEXPWM_IP_INS[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_I[!"$instanceId"!]_SUB[!"$SubModule"!]_[!"$channelCfgName"!]_CFG      ([!"num:i($instanceId)"!]U)
[!ELSE!]
#define FLEXPWM_IP_INS[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_I[!"$instanceId"!]_SUB[!"$SubModule"!]_[!"$channelCfgName"!]_CFG      ([!"num:i($instanceId - 1)"!]U)
[!ENDIF!]
[!CR!]
        [!ENDLOOP!]
    [!ENDLOOP!]
[!ENDLOOP!]

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
#ifndef FLEXPWM_IP_PRECOMPILE_SUPPORT
#define PWM_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Pwm_MemMap.h"

[!LOOP "./PwmChannelConfigSet/FlexPwm/*"!]
    [!VAR "instanceId" = "substring-after(./FlexPwmModule, '_')"!]
/*================================================================================================*/
/* FlexPwm instance [!"$instanceId"!] User configuration structure */
extern const FlexPwm_Ip_InstanceCfgTypes FlexPwm_Ip[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_InstanceCfg_I[!"$instanceId"!];
[!CR!]
/* Channel configurations for FlexPwm instance [!"$instanceId"!] */
    [!LOOP "./FlexPwmSubModules/*"!]
        [!VAR "SubModule" = "substring-after(./FlexPwmSubModule,'SubModule_')"!]
        [!LOOP "./FlexPwmChannels/*"!]
            [!VAR "channelCfgName" = "substring-after(./FlexPwmChannel,'FLEXPWM_IP_')"!]
/* FlexPwm instance [!"$instanceId"!] submodule [!"$SubModule"!] channel [!"$channelCfgName"!] configuration */
extern const FlexPwm_Ip_ChannelCfgTypes FlexPwm_Ip[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_ChannelCfg_I[!"$instanceId"!]_S[!"$SubModule"!]_[!"$channelCfgName"!];
[!CR!]
        [!ENDLOOP!]
    [!ENDLOOP!]
[!ENDLOOP!]

#define PWM_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Pwm_MemMap.h"
#endif  /* FLEXPWM_IP_PRECOMPILE_SUPPORT */

#ifdef __cplusplus
}
#endif

/** @} */

#endif /* FLEXPWM_IP[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_H */

[!ENDCODE!]
