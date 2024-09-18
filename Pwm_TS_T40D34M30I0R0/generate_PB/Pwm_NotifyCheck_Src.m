[!AUTOSPACING!]
[!NOCODE!]
/*!
*   @file       Pwm_NotifyCheck_Src.m
*   @version    3.0.0
*
*   @brief      AUTOSAR Pwm Macros that generate notifications handlers
*   @details    Macros that generate notifications handlers prototypes
*
*   @addtogroup PWM_MODULE
*   @{
*/
/*!==================================================================================================
*   Project              : RTD AUTOSAR 4.7
*   Platform             : CORTEXM
*   Peripheral           : Emios Flexio FlexPwm
*   Dependencies         : none
*
*   AUTOSAR Version      : 4.7.0
*   AUTOSAR Revision     : ASR_REL_4_7_REV_0000
*   AUTOSAR Conf.Variant :
*   SW Version           : 3.0.0
*   Build Version        : S32K3_RTD_3_0_0_D2303_ASR_REL_4_7_REV_0000_20230331
*
*   Copyright 2020 - 2023 NXP Semiconductors
==================================================================================================*/



/* Avoid multiple inclusion */
[!IF "not(var:defined('PWM_NOTIFY_CHECK_SRC_M'))"!]

    [!VAR "PWM_NOTIFY_CHECK_SRC_M"="'true'"!]


    /* This macro generates the list of prototypes of PWM channel notification handlers */
    [!MACRO "GeneratePwmNotifications"!]
    [!NOCODE!]
        [!LOOP "./PwmChannel/*"!]
            [!IF "node:exists('PwmNotification')"!]
                [!IF "(PwmNotification != 'NULL_PTR') and (PwmNotification != '"NULL"') and (PwmNotification != 'NULL')"!]
                    [!CODE!][!CR!]/** @brief  Prototypes of PWM channels User Notifications */[!ENDCODE!]

                    [!BREAK!]
                [!ENDIF!]
            [!ENDIF!]
        [!ENDLOOP!]

        [!VAR "MacOuterLoopCounter" = "0"!]
        [!VAR "MacInnerLoopCounter" = "0"!]

        /* Loop through all PWM channels and get name of Notification handlers for each of them.
           Loop the channels twice because there might be channels using same MacNotification function
           and we only want to declare it as external once */
        [!LOOP "./PwmChannel/*"!]
            [!VAR "MacOuterLoopCounter" = "$MacOuterLoopCounter + 1"!]
            [!VAR "MacInnerLoopCounter" = "0"!]
            [!VAR "MacMatchcounter" = "0"!]

            [!IF "node:exists('PwmNotification')"!]
                [!VAR "MacNotification" = "PwmNotification"!]

                [!LOOP "../../PwmChannel/*"!]
                    [!IF "(PwmNotification != 'NULL_PTR') and (PwmNotification != '"NULL"') and (PwmNotification != 'NULL')"!]
                        [!VAR "MacInnerLoopCounter" = "$MacInnerLoopCounter + 1"!]

                        [!IF "$MacOuterLoopCounter >= $MacInnerLoopCounter"!]
                            [!IF "($MacNotification = PwmNotification)"!]
                                [!VAR "MacMatchcounter" = "$MacMatchcounter + 1"!]
                            [!ENDIF!]
                        [!ENDIF!]
                    [!ENDIF!]
                [!ENDLOOP!]
            [!ENDIF!]

            [!IF "$MacMatchcounter = 1"!]
                [!CODE!][!CR!]extern void [!"PwmNotification"!](void);[!CR!][!ENDCODE!]
            [!ENDIF!]
        [!ENDLOOP!]

    [!ENDNOCODE!]
    [!ENDMACRO!]

[!ENDIF!] /* Avoid multiple inclusion ENDIF */

[!ENDNOCODE!]
