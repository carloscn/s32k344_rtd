[!/* *** multiple inclusion protection *** */!]
[!IF "not(var:defined('ADC_VERSIONCHECK_SRC_M'))"!]
[!VAR "ADC_VERSIONCHECK_SRC_M"="'true'"!]
[!NOCODE!][!//
/*==================================================================================================
*   Project              : RTD AUTOSAR 4.7
*   Platform             : CORTEXM
*   Peripheral           : ADC_SAR
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
*   @file
*
*   @addtogroup adc_driver_config Adc Driver Configuration
*   @{
*/

[!VAR "ADC_AR_RELEASE_MAJOR_VERSION_TEMPLATE"="4"!][!//
[!VAR "ADC_AR_RELEASE_MINOR_VERSION_TEMPLATE"="7"!][!//
[!VAR "ADC_AR_RELEASE_REVISION_VERSION_TEMPLATE"="0"!][!//
[!VAR "ADC_SW_MAJOR_VERSION_TEMPLATE"="3"!][!//
[!VAR "ADC_SW_MINOR_VERSION_TEMPLATE"="0"!][!//
[!VAR "ADC_SW_PATCH_VERSION_TEMPLATE"="0"!][!//
[!ENDNOCODE!][!//
[!SELECT "CommonPublishedInformation"!][!//

[!IF "not(num:i(ArReleaseMajorVersion) = num:i($ADC_AR_RELEASE_MAJOR_VERSION_TEMPLATE))"!]
    [!ERROR!]
        **** AUTOSAR release major version number of the Basic Software Module Description file (Adc.epd version [!"ArReleaseMajorVersion"!]) and the Code template file are different ****
    [!ENDERROR!]
[!ENDIF!]
[!IF "not(num:i(ArReleaseMinorVersion) = num:i($ADC_AR_RELEASE_MINOR_VERSION_TEMPLATE))"!]
    [!ERROR!]
        **** AUTOSAR release minor version number of the Basic Software Module Description file (Adc.epd version [!"ArReleaseMinorVersion"!]) and the Code template file are different ****
    [!ENDERROR!]
[!ENDIF!]
[!IF "not(num:i(ArReleaseRevisionVersion) = num:i($ADC_AR_RELEASE_REVISION_VERSION_TEMPLATE))"!]
    [!ERROR!]
        **** AUTOSAR release revision version number of the Basic Software Module Description file (Adc.epd version [!"ArReleaseRevisionVersion"!]) and the Code template file are different ****
    [!ENDERROR!]
[!ENDIF!]

[!IF "not(num:i(SwMajorVersion) = num:i($ADC_SW_MAJOR_VERSION_TEMPLATE))"!]
    [!ERROR!]
        **** The software major number of the Basic Software Module Description file (Adc.epd version [!"SwMajorVersion"!]) and the Code template file are different ****
    [!ENDERROR!]
[!ENDIF!]
[!IF "not(num:i(SwMinorVersion) = num:i($ADC_SW_MINOR_VERSION_TEMPLATE))"!]
    [!ERROR!]
        **** The software minor number of the Basic Software Module Description file (Adc.epd version [!"SwMinorVersion"!]) and the Code template file are different ****
    [!ENDERROR!]
[!ENDIF!]
[!IF "not(num:i(SwPatchVersion) = num:i($ADC_SW_PATCH_VERSION_TEMPLATE))"!]
    [!ERROR!]
        **** The software patch number of the Basic Software Module Description file (Adc.epd version [!"SwPatchVersion"!]) and the Code template file are different ****
    [!ENDERROR!]
[!ENDIF!]
[!ENDSELECT!][!//
[!ENDIF!]

/** @} */