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

#ifndef EMIOS_PWM_IP_CFG_H
#define EMIOS_PWM_IP_CFG_H

/**
*   @file       Emios_Pwm_Ip_Cfg.h
*
*   @addtogroup emios_pwm_ip Emios Pwm IPL
*   @{
*/

#ifdef __cplusplus
extern "C"{
#endif

[!NOCODE!]
    /* Check if Emios is used */
    [!IF "(node:exists(PwmChannelConfigSet/PwmEmios) and (count(PwmChannelConfigSet/PwmEmios/*) > 0)) = 'true'"!]
        [!VAR "EmiosIsUsed" = "'true'"!]
    [!ELSE!]
        [!VAR "EmiosIsUsed" = "'false'"!]
    [!ENDIF!]
[!ENDNOCODE!]
/*==================================================================================================
*                                          INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
/* Standard Types */
#include "Std_Types.h"

/* DevAssert implementation */
#include "Devassert.h"

/* Register definitions */
[!IF "node:exists(as:modconf("Resource")[1]/ResourceGeneral/ResourceSubderivative)"!][!//
    [!VAR "DerivativeName" = "text:toupper(substring-before(as:modconf("Resource")[1]/ResourceGeneral/ResourceSubderivative,'_'))"!]
    [!IF "contains(as:modconf("Resource")[1]/ResourceGeneral/ResourceSubderivative, 's32k310')"!][!//
        [!CODE!][!WS "0"!]#include "S32K311_EMIOS.h"[!CR!][!ENDCODE!][!//
    [!ELSEIF "contains(as:modconf("Resource")[1]/ResourceGeneral/ResourceSubderivative, 's32e')"!][!//
        [!CODE!][!WS "0"!]#include "S32E2_EMIOS.h"[!CR!][!ENDCODE!][!//
    [!ELSEIF "contains(as:modconf("Resource")[1]/ResourceGeneral/ResourceSubderivative, 's32z')"!][!//
        [!CODE!][!WS "0"!]#include "S32Z2_EMIOS.h"[!CR!][!ENDCODE!][!//
    [!ELSEIF "contains(as:modconf("Resource")[1]/ResourceGeneral/ResourceSubderivative, 's32m27')"!][!//
        [!CODE!][!WS "0"!]#include "S32M27x_EMIOS.h"[!CR!][!ENDCODE!][!//
    [!ELSEIF "contains(as:modconf("Resource")[1]/ResourceGeneral/ResourceSubderivative, 's32k39')"!][!//
        [!CODE!][!WS "0"!]#include "S32K39_EMIOS.h"[!CR!][!ENDCODE!][!//
    [!ELSEIF "contains(as:modconf("Resource")[1]/ResourceGeneral/ResourceSubderivative, 's32k328') or
              contains(as:modconf("Resource")[1]/ResourceGeneral/ResourceSubderivative, 's32k338') or
              contains(as:modconf("Resource")[1]/ResourceGeneral/ResourceSubderivative, 's32k348')"!][!//
        [!CODE!][!WS "0"!]#include "S32K358_EMIOS.h"[!CR!][!ENDCODE!][!//
    [!ELSE!][!//
        [!CODE!][!WS "0"!]#include "[!"$DerivativeName"!]_EMIOS.h"[!CR!][!ENDCODE!][!//
    [!ENDIF!][!//
[!ENDIF!][!//

/* Include all variants header files. */
[!IF "var:defined('postBuildVariant')"!]
    [!LOOP "variant:all()"!]
#include "Emios_Pwm_Ip_[!"."!]_PBcfg.h"
    [!ENDLOOP!]
[!ELSE!]
#include "Emios_Pwm_Ip_PBcfg.h"
[!ENDIF!]

/*==================================================================================================
*                                 SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define EMIOS_PWM_IP_CFG_VENDOR_ID                    43
#define EMIOS_PWM_IP_CFG_MODULE_ID                    121
#define EMIOS_PWM_IP_CFG_AR_RELEASE_MAJOR_VERSION     4
#define EMIOS_PWM_IP_CFG_AR_RELEASE_MINOR_VERSION     7
#define EMIOS_PWM_IP_CFG_AR_RELEASE_REVISION_VERSION  0
#define EMIOS_PWM_IP_CFG_SW_MAJOR_VERSION             3
#define EMIOS_PWM_IP_CFG_SW_MINOR_VERSION             0
#define EMIOS_PWM_IP_CFG_SW_PATCH_VERSION             0

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if header file and Std_Types.h are of the same AUTOSAR version */
    #if ((EMIOS_PWM_IP_CFG_AR_RELEASE_MAJOR_VERSION != STD_AR_RELEASE_MAJOR_VERSION) || \
         (EMIOS_PWM_IP_CFG_AR_RELEASE_MINOR_VERSION != STD_AR_RELEASE_MINOR_VERSION))
        #error "AUTOSAR Version Numbers of Emios_Pwm_Ip_Cfg.h and Std_Types.h are different"
    #endif

    /* Check if header file and Devassert.h are of the same AUTOSAR version */
    #if ((EMIOS_PWM_IP_CFG_AR_RELEASE_MAJOR_VERSION != DEVASSERT_AR_RELEASE_MAJOR_VERSION) || \
         (EMIOS_PWM_IP_CFG_AR_RELEASE_MINOR_VERSION != DEVASSERT_AR_RELEASE_MINOR_VERSION))
        #error "AUTOSAR Version Numbers of Emios_Pwm_Ip_Cfg.h and Devassert.h are different"
    #endif
#endif

[!IF "var:defined('postBuildVariant')"!]
    [!LOOP "variant:all()"!]
/* Check if header file and Emios_Pwm_Ip_[!"."!]_Pbcfg header file are of the same vendor */
#if (EMIOS_PWM_IP_CFG_VENDOR_ID != EMIOS_PWM_IP_[!"."!]_PB_CFG_VENDOR_ID)
    #error "Vendor IDs of Emios_Pwm_Ip_Cfg.h and Emios_Pwm_Ip_[!"."!]_Pbcfg.h are different."
#endif

/* Check if header file and Pwm_EnvCfg header file are of the same AUTOSAR version */
#if ((EMIOS_PWM_IP_CFG_AR_RELEASE_MAJOR_VERSION    != EMIOS_PWM_IP_[!"."!]_PB_CFG_AR_RELEASE_MAJOR_VERSION) || \
     (EMIOS_PWM_IP_CFG_AR_RELEASE_MINOR_VERSION    != EMIOS_PWM_IP_[!"."!]_PB_CFG_AR_RELEASE_MINOR_VERSION) || \
     (EMIOS_PWM_IP_CFG_AR_RELEASE_REVISION_VERSION != EMIOS_PWM_IP_[!"."!]_PB_CFG_AR_RELEASE_REVISION_VERSION))
    #error "AUTOSAR version numbers of Emios_Pwm_Ip_Cfg.h and Emios_Pwm_Ip_[!"."!]_Pbcfg.h are different."
#endif

/* Check if header file and Pwm_EnvCfg header file are of the same software version */
#if ((EMIOS_PWM_IP_CFG_SW_MAJOR_VERSION != EMIOS_PWM_IP_[!"."!]_PB_CFG_SW_MAJOR_VERSION) || \
     (EMIOS_PWM_IP_CFG_SW_MINOR_VERSION != EMIOS_PWM_IP_[!"."!]_PB_CFG_SW_MINOR_VERSION) || \
     (EMIOS_PWM_IP_CFG_SW_PATCH_VERSION != EMIOS_PWM_IP_[!"."!]_PB_CFG_SW_PATCH_VERSION))
    #error "Software version numbers of Emios_Pwm_Ip_Cfg.h and Emios_Pwm_Ip_[!"."!]_Pbcfg.h are different."
#endif
    [!ENDLOOP!]
[!ELSE!]
/* Check if header file and Pwm_EnvCfg header file are of the same vendor */
#if (EMIOS_PWM_IP_CFG_VENDOR_ID != EMIOS_PWM_IP_PB_CFG_VENDOR_ID)
    #error "Vendor IDs of Emios_Pwm_Ip_Cfg.h and Emios_Pwm_Ip_Pbcfg.h are different."
#endif

/* Check if header file and Pwm_EnvCfg header file are of the same AUTOSAR version */
#if ((EMIOS_PWM_IP_CFG_AR_RELEASE_MAJOR_VERSION    != EMIOS_PWM_IP_PB_CFG_AR_RELEASE_MAJOR_VERSION) || \
     (EMIOS_PWM_IP_CFG_AR_RELEASE_MINOR_VERSION    != EMIOS_PWM_IP_PB_CFG_AR_RELEASE_MINOR_VERSION) || \
     (EMIOS_PWM_IP_CFG_AR_RELEASE_REVISION_VERSION != EMIOS_PWM_IP_PB_CFG_AR_RELEASE_REVISION_VERSION))
    #error "AUTOSAR version numbers of Emios_Pwm_Ip_Cfg.h and Emios_Pwm_Ip_Pbcfg.h are different."
#endif

/* Check if header file and Pwm_EnvCfg header file are of the same software version */
#if ((EMIOS_PWM_IP_CFG_SW_MAJOR_VERSION != EMIOS_PWM_IP_PB_CFG_SW_MAJOR_VERSION) || \
     (EMIOS_PWM_IP_CFG_SW_MINOR_VERSION != EMIOS_PWM_IP_PB_CFG_SW_MINOR_VERSION) || \
     (EMIOS_PWM_IP_CFG_SW_PATCH_VERSION != EMIOS_PWM_IP_PB_CFG_SW_PATCH_VERSION))
    #error "Software version numbers of Emios_Pwm_Ip_Cfg.h and Emios_Pwm_Ip_Pbcfg.h are different."
#endif
[!ENDIF!]

/*==================================================================================================
*                                            CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/
/** @brief      Enable the Emios Ip */
#define EMIOS_PWM_IP_USED                          ([!IF "$EmiosIsUsed = 'true'"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

/** @brief      Switch to enable the development error detection. */
#define EMIOS_PWM_IP_DEV_ERROR_DETECT              ([!IF "PwmGeneral/PwmDevErrorDetect"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

/** @brief      The number of Emios instances available on platform */
#define EMIOS_PWM_IP_INSTANCE_COUNT                ([!"ecu:get('Pwm.EmiosInstanceMacro')"!])
/** @brief      The number of channels available on each Emios instance */
#define EMIOS_PWM_IP_CHANNEL_COUNT                 ([!"ecu:get('Pwm.EmiosChannelMacro')"!])

/** @brief      The number of PWM modes implemented in hardware */
#define EMIOS_PWM_IP_MODES                         ([!"ecu:get('Pwm.EmiosPwmModesCount')"!]U)
/** @brief      Mapping between available channels and the PWM mode supported by each of them */
#define EMIOS_PWM_IP_CHANNEL_MODES                 {\
[!FOR "instance" = "0" TO "number(ecu:get('Pwm.EmiosInstanceCount')) - 1"!]
                                                    {[!"ecu:get(concat('Pwm.EmiosPwmModesMappingInst_', $instance))"!]},\
[!ENDFOR!]
                                                }
/** @brief Min counter value for PWM modes */
#define EMIOS_PWM_IP_MIN_CNT_VAL                   (0x0001UL)
/** @brief Max counter value for PWM modes */
#define EMIOS_PWM_IP_MAX_CNT_VAL                   ([!IF "ecu:get('Pwm.TimerPrecision') = 'uint16'"!]0xFFFFUL[!ELSE!]0xFFFFFFUL[!ENDIF!])

/** @brief      Counter bus channel number */
#define EMIOS_PWM_IP_COUNTER_BUS_A                 (23U)
#define EMIOS_PWM_IP_COUNTER_BUS_BCDE              (248U)
#define EMIOS_PWM_IP_COUNTER_BUS_F                 (22U)

[!NOCODE!]
[!IF "(num:i(ecu:get('Pwm.EmiosInstanceCount')) > 0) and (num:i(ecu:get('Pwm.EmiosChannelCount')) > 0)"!]
    [!VAR "index" = "0"!]
    [!CODE!][!WS "0"!]/** @brief Arrays to store the channel logic Index State */[!CR!][!ENDCODE!]
    [!CODE!][!WS "0"!]#define EMIOS_PWM_IP_USED_CHANNELS \[!CR!][!ENDCODE!]
    [!CODE!][!WS "0"!]{ \[!CR!][!ENDCODE!]
    [!FOR "moduleIndex" = "0" TO "num:i(ecu:get('Pwm.EmiosInstanceCount') - 1)"!]
        [!VAR "eMiosModuleVal" = "'{'"!]
        [!FOR "channelIndex" = "0" TO "num:i(ecu:get('Pwm.EmiosChannelCount') - 1)"!]
            [!VAR "numOfChUsedSameMasterBus" = "0"!]
            [!VAR "moduleIndexInArray" = "num:i(255)"!]
            [!SELECT "PwmChannelConfigSet"!]
                [!IF "count(PwmEmios/*) > '0'"!]
                    [!LOOP "PwmEmios/*"!]
                        [!VAR "pwmEmiosModule" = "substring-after(node:value(./PwmHwInstance), 'Emios_')"!]
                        [!LOOP "PwmEmiosChannels/*"!]
                        [!VAR "channelVal" = "substring-after(node:value(./EmiosChId), 'CH_')"!]
                            [!IF "contains(substring-after(node:value(./EmiosChCounterBus), 'EMIOS_PWM_IP_BUS'),'_A')"!]
                                [!VAR "pwmEmiosMasterBusChannel" = "num:i(23)"!]
                            [!ELSEIF "contains(substring-after(node:value(./EmiosChCounterBus), 'EMIOS_PWM_IP_BUS'),'_F')"!]
                                [!VAR "pwmEmiosMasterBusChannel" = "num:i(22)"!]
                            [!ELSEIF "contains(substring-after(node:value(./EmiosChCounterBus), 'EMIOS_PWM_IP_BUS'),'_BCDE')"!]
                                [!VAR "channelValTemp" = "substring-after(node:value(./EmiosChId), 'CH_')"!]
                                [!VAR "pwmEmiosMasterBusChannel" = "num:i(num:i($channelValTemp div num:i(8)) * num:i(8))"!]
                            [!ELSEIF "contains(substring-after(node:value(./EmiosChCounterBus), 'EMIOS_PWM_IP_BUS'),'_INTERNAL')"!]
                                [!VAR "pwmEmiosMasterBusChannel" = "substring-after(node:value(./EmiosChId), 'CH_')"!]
                            [!ENDIF!]

                            [!IF "($moduleIndex = $pwmEmiosModule) and (($channelIndex = $pwmEmiosMasterBusChannel) or ($channelIndex = $channelVal))"!]
                                [!IF "$numOfChUsedSameMasterBus = 0"!]
                                    [!VAR "moduleIndexInArray" = "num:i($index)"!]
                                    [!VAR "index" = "$index + 1"!]
                                [!ENDIF!]
                                [!IF "($moduleIndex = $pwmEmiosModule) and ($channelIndex = $pwmEmiosMasterBusChannel)"!]
                                    [!VAR "numOfChUsedSameMasterBus" = "$numOfChUsedSameMasterBus + 1"!]
                                [!ENDIF!]                                
                            [!ENDIF!]
                        [!ENDLOOP!]
                    [!ENDLOOP!]
                [!ENDIF!]
            [!ENDSELECT!]

            [!IF "num:i($channelIndex) < (num:i(ecu:get('Pwm.EmiosChannelCount') - 1))"!]
                [!VAR "eMiosModuleVal" = "concat($eMiosModuleVal, num:i($moduleIndexInArray), 'U, ')"!]
            [!ELSE!]
                [!VAR "eMiosModuleVal" = "concat($eMiosModuleVal, num:i($moduleIndexInArray), 'U')"!]
            [!ENDIF!]

        [!ENDFOR!]

        [!IF "num:i($moduleIndex) < (num:i(ecu:get('Pwm.EmiosInstanceCount') - 1))"!]
            [!VAR "eMiosModuleVal" = "concat($eMiosModuleVal, '}, \')"!]
        [!ELSE!]
            [!VAR "eMiosModuleVal" = "concat($eMiosModuleVal, '} \')"!]
        [!ENDIF!]

        [!CODE!][!WS "4"!][!"$eMiosModuleVal"!][!CR!][!ENDCODE!]

    [!ENDFOR!]

    [!CODE!][!WS "0"!]}[!CR!][!ENDCODE!]

[!ENDIF!]
[!ENDNOCODE!]

/** @brief    Calculate the supported eMios channels */
[!NOCODE!]
[!VAR "NumOfUsedEmiosCh" = "num:i($index)"!]
[!ENDNOCODE!]

#define EMIOS_PWM_IP_NUM_OF_CHANNELS_USED       ((uint8)[!"num:i($NumOfUsedEmiosCh)"!]U)

#define EMIOS_PWM_IP_INITIAL_MODES \
{\
[!NOCODE!]
[!FOR "channel" = "0" TO "$NumOfUsedEmiosCh - 1"!]
    [!CODE!][!WS "8"!]EMIOS_PWM_IP_MODE_NODEFINE[!ENDCODE!]
    [!IF "$channel < $NumOfUsedEmiosCh - 1"!][!CODE!],[!ENDCODE!][!ENDIF!][!CODE!]\[!CR!][!ENDCODE!]
[!ENDFOR!]
[!ENDNOCODE!]
}
/*==================================================================================================
*                                              ENUMS
==================================================================================================*/

/*==================================================================================================
*                                  STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/
/* Redefine eMIOS_Type from header file to comply with coding guidelines */
typedef eMIOS_Type Emios_Pwm_Ip_HwAddrType;

/**
* @brief        PWM Period type (the value of the period is platform dependent and thus configurable)
*/
typedef [!"ecu:get('Pwm.TimerPrecision')"!] Emios_Pwm_Ip_PeriodType;

/**
* @brief        PWM Duty type (the value of the period is platform dependent and thus configurable)
*/
typedef [!"ecu:get('Pwm.TimerPrecision')"!] Emios_Pwm_Ip_DutyType;
/*==================================================================================================
*                                  GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                       FUNCTION PROTOTYPES
==================================================================================================*/


#ifdef __cplusplus
}
#endif

/** @} */

#endif /* EMIOS_PWM_IP_CFG_H */

[!ENDCODE!]
