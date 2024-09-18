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

#ifndef FLEXIO_PWM_IP_CFGDEFINES_H
#define FLEXIO_PWM_IP_CFGDEFINES_H

/**
*   @file Flexio_Pwm_Ip_CfgDefines.h
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

/*==================================================================================================
*                                 SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define FLEXIO_PWM_IP_CFGDEFINES_VENDOR_ID                    43
#define FLEXIO_PWM_IP_CFGDEFINES_MODULE_ID                    121
#define FLEXIO_PWM_IP_CFGDEFINES_AR_RELEASE_MAJOR_VERSION     4
#define FLEXIO_PWM_IP_CFGDEFINES_AR_RELEASE_MINOR_VERSION     7
#define FLEXIO_PWM_IP_CFGDEFINES_AR_RELEASE_REVISION_VERSION  0
#define FLEXIO_PWM_IP_CFGDEFINES_SW_MAJOR_VERSION             3
#define FLEXIO_PWM_IP_CFGDEFINES_SW_MINOR_VERSION             0
#define FLEXIO_PWM_IP_CFGDEFINES_SW_PATCH_VERSION             0

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/
/* Check if header file and Std_Types.h are of the same AUTOSAR version */
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if ((FLEXIO_PWM_IP_CFGDEFINES_AR_RELEASE_MAJOR_VERSION != STD_AR_RELEASE_MAJOR_VERSION) || \
         (FLEXIO_PWM_IP_CFGDEFINES_AR_RELEASE_MINOR_VERSION != STD_AR_RELEASE_MINOR_VERSION))
        #error "AUTOSAR version numbers of Flexio_Pwm_Ip_CfgDefines.h and Std_Types.h are different."
    #endif
#endif

/*==================================================================================================
*                                            CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/
/** @brief      Flexio Timer has 8bit pwm low mode */
#define FLEXIO_PWM_IP_HAS_LOW_MODE              ([!IF "ecu:get('Pwm.FlexioHasLowMode') = 'true'"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])
/** @brief      Flexio Timer has 8bit pwm low mode */
#define FLEXIO_PWM_IP_HAS_PRESCALER             ([!IF "ecu:get('Pwm.FlexioHasPrescaler') = 'true'"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])
/** @brief      Flexio pin override value  */
#define FLEXIO_PWM_IP_HAS_PIN_OVERRIDE          ([!IF "ecu:get('Pwm.FlexioHasPinOverride') = 'true'"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

/* Defines for use with MCL Flexio common part */
[!LOOP "PwmChannelConfigSet/PwmFlexio/*/PwmFlexioChannels/*"!]
/** @brief      Flexio [!"substring-after(../../PwmHwInstance, '_')"!] Channel [!"substring-after(FlexioChId, '_')"!] used by PWM */
#ifndef [!"text:toupper(../../PwmHwInstance)"!]_[!"FlexioChId"!]_USED
    #define [!"text:toupper(../../PwmHwInstance)"!]_[!"FlexioChId"!]_USED
#else
    #error "Flexio [!"substring-after(../../PwmHwInstance, '_')"!] Channel [!"substring-after(FlexioChId, '_')"!] cannot be used by Pwm. Channel locked by another driver!"
#endif

/** @brief      Flexio [!"substring-after(../../PwmHwInstance, '_')"!] Pin [!"substring-after(FlexioPinId, '_')"!] used by PWM */
#ifndef [!"text:toupper(../../PwmHwInstance)"!]_[!"FlexioPinId"!]_USED
    #define [!"text:toupper(../../PwmHwInstance)"!]_[!"FlexioPinId"!]_USED
#else
    #error "Flexio [!"substring-after(../../PwmHwInstance, '_')"!] Pin [!"substring-after(FlexioPinId, '_')"!] cannot be used by Pwm. Pin used by another driver!"
#endif

[!ENDLOOP!]

[!LOOP "PwmChannelConfigSet/PwmFlexio/*/PwmFlexioChannels/*"!]
    [!IF "FlexioChInterrupt != ecu:list('Pwm.FlexioIrqType')[1]"!]
/** @brief        Flexio [!"substring-after(../../PwmHwInstance, '_')"!] Channel [!"substring-after(FlexioChId, '_')"!] IRQ used by PWM */
#ifdef [!"text:toupper(../../PwmHwInstance)"!]_[!"FlexioChId"!]_USED
    #define PWM_CHANNEL_[!"substring-after(FlexioChId, '_')"!]_USED
#else
    #error "Flexio [!"substring-after(../../PwmHwInstance, '_')"!] Channel [!"substring-after(FlexioChId, '_')"!] cannot be used by Pwm. Channel locked by another driver!"
#endif

/** @brief      Flexio [!"substring-after(../../PwmHwInstance, '_')"!] Pin [!"substring-after(FlexioPinId, '_')"!] Mask define for IRQ */
#define FLEXIO_PWM_IP_CHANNEL_[!"substring-after(FlexioChId, '_')"!]_PINMASK         (1U << [!"substring-after(FlexioPinId, '_')"!]U)

    [!ENDIF!]
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

/*==================================================================================================
*                                       FUNCTION PROTOTYPES
==================================================================================================*/


#ifdef __cplusplus
}
#endif

/** @} */

#endif /* FLEXIO_PWM_IP_CFGDEFINES_H */

[!ENDCODE!]
