[!NOCODE!][!//

/*!
*   @file       Pwm_VersionCheck_Src_PB.m
*   @version    3.0.0
*
*   @brief      AUTOSAR Pwm macro to check for notification config, variant post-build
*   @details    Macro to check for notification config, variant post-build
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

[!ENDNOCODE!][!//


[!/* avoid multiple inclusion */!]
[!IF "not(var:defined('PWM_VERSION_CHECK_SRC_PB_M'))"!]
[!VAR "PWM_VERSION_CHECK_SRC_PB_M"="'true'"!]


[!VAR "PWM_AR_MAJOR_VERSION_TEMPLATE"="4"!][!//
[!VAR "PWM_AR_MINOR_VERSION_TEMPLATE"="7"!][!//
[!VAR "PWM_AR_REVISION_VERSION_TEMPLATE"="0"!][!//
[!VAR "PWM_SW_MAJOR_VERSION_TEMPLATE"="3"!][!//
[!VAR "PWM_SW_MINOR_VERSION_TEMPLATE"="0"!][!//
[!VAR "PWM_SW_PATCH_VERSION_TEMPLATE"="0"!][!//

[!SELECT "CommonPublishedInformation"!][!//

[!IF "not(num:i(ArReleaseMajorVersion) = num:i($PWM_AR_MAJOR_VERSION_TEMPLATE))"!]
    [!ERROR!]
        "AUTOSAR major version number of the Basic Software Module Description file (Pwm.epd version [!"ArReleaseMajorVersion"!]) and the Code template file (Pwm_PBcfg.c  version [!"num:i($PWM_AR_MAJOR_VERSION_TEMPLATE)"!]) are different"
    [!ENDERROR!]
[!ENDIF!][!//
[!IF "not(num:i(ArReleaseMinorVersion) = num:i($PWM_AR_MINOR_VERSION_TEMPLATE))"!]
    [!ERROR!]
        "AUTOSAR release minor version number of the Basic Software Module Description file (Pwm.epd version [!"ArReleaseMinorVersion"!]) and the Code template files (Pwm_PBcfg.c  version [!"num:i($PWM_AR_MINOR_VERSION_TEMPLATE)"!]) are different"
    [!ENDERROR!]
[!ENDIF!][!//
[!IF "not(num:i(ArReleaseRevisionVersion) = num:i($PWM_AR_REVISION_VERSION_TEMPLATE))"!]
    [!ERROR!]
        "AUTOSAR release revision version number of the Basic Software Module Description file (Pwm.epd version [!"ArReleaseRevisionVersion"!]) and the Code template files (Pwm_PBcfg.c  version [!"num:i($PWM_AR_REVISION_VERSION_TEMPLATE)"!]) are different"
    [!ENDERROR!]
[!ENDIF!][!//
[!IF "not(num:i(SwMajorVersion) = num:i($PWM_SW_MAJOR_VERSION_TEMPLATE))"!]
    [!ERROR!]
        "The software major number of the Basic Software Module Description file (Pwm.epd version [!"SwMajorVersion"!]) and the Code template files (Pwm_PBcfg.c  version [!"num:i($PWM_SW_MAJOR_VERSION_TEMPLATE)"!]) are different"
    [!ENDERROR!]
[!ENDIF!][!//
[!IF "not(num:i(SwMinorVersion) = num:i($PWM_SW_MINOR_VERSION_TEMPLATE))"!]
    [!ERROR!]
        "The software minor number of the Basic Software Module Description file (Pwm.epd version [!"SwMinorVersion"!]) and the Code template files (Pwm_PBcfg.c  version [!"num:i($PWM_SW_MINOR_VERSION_TEMPLATE)"!]) are different"
    [!ENDERROR!]
[!ENDIF!][!//
[!IF "not(num:i(SwPatchVersion) = num:i($PWM_SW_PATCH_VERSION_TEMPLATE))"!]
    [!ERROR!]
        "The software patch number of the Basic Software Module Description file (Pwm.epd version [!"SwPatchVersion"!]) and the Code template files (Pwm_PBcfg.c  version [!"num:i($PWM_SW_PATCH_VERSION_TEMPLATE)"!]) are different"
    [!ENDERROR!]
[!ENDIF!]


[!ENDSELECT!][!//
[!NOCODE!][!//
[!ENDNOCODE!][!//


[!ENDIF!][!// avoid multiple inclusion ENDIF

