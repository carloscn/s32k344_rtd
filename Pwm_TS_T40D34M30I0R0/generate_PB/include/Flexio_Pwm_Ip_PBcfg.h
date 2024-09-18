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

#ifndef FLEXIO_PWM_IP[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_H
#define FLEXIO_PWM_IP[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_H

/**
*   @file Flexio_Pwm_Ip_PBcfg.h
*
*   @addtogroup flexio_pwm_ip FlexIO Pwm IPL
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
#include "Std_Types.h"
#include "Flexio_Pwm_Ip_Types.h"

/*==================================================================================================
*                                 SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define FLEXIO_PWM_IP[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_VENDOR_ID                    43
#define FLEXIO_PWM_IP[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_MODULE_ID                    121
#define FLEXIO_PWM_IP[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_AR_RELEASE_MAJOR_VERSION     4
#define FLEXIO_PWM_IP[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_AR_RELEASE_MINOR_VERSION     7
#define FLEXIO_PWM_IP[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_AR_RELEASE_REVISION_VERSION  0
#define FLEXIO_PWM_IP[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_SW_MAJOR_VERSION             3
#define FLEXIO_PWM_IP[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_SW_MINOR_VERSION             0
#define FLEXIO_PWM_IP[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_SW_PATCH_VERSION             0

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if header file and Std_Types.h are of the same AUTOSAR version */
    #if ((FLEXIO_PWM_IP[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_AR_RELEASE_MAJOR_VERSION != STD_AR_RELEASE_MAJOR_VERSION) || \
         (FLEXIO_PWM_IP[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_AR_RELEASE_MINOR_VERSION != STD_AR_RELEASE_MINOR_VERSION))
        #error "AUTOSAR Version Numbers of Flexio_Pwm_Ip[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg.h and Std_Types.h are different"
    #endif
#endif

/* Check if header file and Flexio_Pwm_Ip_Types.h header file are of the same vendor */
#if (FLEXIO_PWM_IP[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_VENDOR_ID != FLEXIO_PWM_IP_TYPES_VENDOR_ID)
    #error "Vendor IDs of Flexio_Pwm_Ip[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg.h and Flexio_Pwm_Ip_Types.h are different."
#endif

/* Check if header file and Flexio_Pwm_Ip_Types.h header file are of the same AUTOSAR version */
#if ((FLEXIO_PWM_IP[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_AR_RELEASE_MAJOR_VERSION    != FLEXIO_PWM_IP_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (FLEXIO_PWM_IP[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_AR_RELEASE_MINOR_VERSION    != FLEXIO_PWM_IP_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (FLEXIO_PWM_IP[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_AR_RELEASE_REVISION_VERSION != FLEXIO_PWM_IP_TYPES_AR_RELEASE_REVISION_VERSION))
    #error "AUTOSAR version numbers of Flexio_Pwm_Ip[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg.h and Flexio_Pwm_Ip_Types.h are different."
#endif

/* Check if header file and Flexio_Pwm_Ip_Types.h header file are of the same software version */
#if ((FLEXIO_PWM_IP[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_SW_MAJOR_VERSION != FLEXIO_PWM_IP_TYPES_SW_MAJOR_VERSION) || \
     (FLEXIO_PWM_IP[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_SW_MINOR_VERSION != FLEXIO_PWM_IP_TYPES_SW_MINOR_VERSION) || \
     (FLEXIO_PWM_IP[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_SW_PATCH_VERSION != FLEXIO_PWM_IP_TYPES_SW_PATCH_VERSION))
    #error "Software version numbers of Flexio_Pwm_Ip[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg.h and Flexio_Pwm_Ip_Types.h are different."
#endif

/*==================================================================================================
*                                            CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/
[!LOOP "./PwmChannelConfigSet/PwmFlexio/*/PwmFlexioChannels/*"!]
    [!VAR "instanceId" = "substring-after(../../PwmHwInstance, '_')"!]
    [!VAR "instanceCfgName" = "name(../..)"!]
    [!VAR "channelId" = "substring-after(FlexioChId, '_')"!]
    [!VAR "channelCfgName" = "name(.)"!]
/* Flexio instance index for [!"$instanceCfgName"!]/[!"$channelCfgName"!] */
#define FLEXIO_PWM_IP[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_I[!"$instanceId"!]_CH[!"$channelId"!]_CFG    ([!"$instanceId"!]U)
[!ENDLOOP!]

/*==================================================================================================
*                                              ENUMS
==================================================================================================*/

/*==================================================================================================
*                                  STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
*                                  GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/
#define PWM_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Pwm_MemMap.h"

[!LOOP "./PwmChannelConfigSet/PwmFlexio/*/PwmFlexioChannels/*"!]
    [!VAR "instanceId" = "substring-after(../../PwmHwInstance, '_')"!]
    [!VAR "instanceCfgName" = "name(../..)"!]
    [!VAR "channelId" = "substring-after(FlexioChId, '_')"!]
    [!VAR "channelCfgName" = "name(.)"!]
    [!VAR "pinId" = "substring-after(FlexioPinId, '_')"!]
/** @brief [!"$channelCfgName"!] of [!"$instanceCfgName"!] Pwm using Timer [!"$channelId"!] and Pin [!"$pinId"!] */
extern const Flexio_Pwm_Ip_ChannelConfigType Flexio_Pwm_Ip[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_I[!"$instanceId"!]_Ch[!"$channelId"!];
[!ENDLOOP!]

#define PWM_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Pwm_MemMap.h"

/*==================================================================================================
*                                       FUNCTION PROTOTYPES
==================================================================================================*/


#ifdef __cplusplus
}
#endif

/** @} */

#endif /* FLEXIO_PWM_IP_PBCFG_H */

[!ENDCODE!]
