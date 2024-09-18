[!NOCODE!][!//
/**
*   @file    Dio_VersionCheck_Src.m
*   @version 3.0.0
*
*   @brief   AUTOSAR Dio - version check macro.
*   @details Version checks.
*
*   @addtogroup DIO
*   @{
*/
/*==================================================================================================
*   Project              : RTD AUTOSAR 4.7
*   Platform             : CORTEXM
*   Peripheral           : SIUL2
*   Dependencies         : none
*
*   Autosar Version      : 4.7.0
*   Autosar Revision     : ASR_REL_4_7_REV_0000
*   Autosar Conf.Variant :
*   SW Version           : 3.0.0
*   Build Version        : S32K3_RTD_3_0_0_D2303_ASR_REL_4_7_REV_0000_20230331
*
*   Copyright 2020 - 2023 NXP Semiconductors
==================================================================================================*/
[!/* avoid multiple inclusion */!]
[!IF "not(var:defined('DIO_VERSIONCHECK_SRC_M'))"!]
[!VAR "DIO_VERSIONCHECK_SRC_M"="'true'"!]
[!VAR "DIO_AR_RELEASE_MAJOR_VERSION_TEMPLATE"="4"!][!//
[!VAR "DIO_AR_RELEASE_MINOR_VERSION_TEMPLATE"="7"!][!//
[!VAR "DIO_AR_RELEASE_REVISION_VERSION_TEMPLATE"="0"!][!//
[!VAR "DIO_SW_MAJOR_VERSION_TEMPLATE"="3"!][!//
[!VAR "DIO_SW_MINOR_VERSION_TEMPLATE"="0"!][!//
[!VAR "DIO_SW_PATCH_VERSION_TEMPLATE"="0"!][!//

[!SELECT "CommonPublishedInformation"!][!//

[!IF "not(num:i(ArReleaseMajorVersion) = num:i($DIO_AR_RELEASE_MAJOR_VERSION_TEMPLATE))"!]
    [!ERROR!]
        "AUTOSAR release major version number of the Basic Software Module Description file (Dio.epd version [!"ArReleaseMajorVersion"!]) and the Code template file (Dio_Cfg.c version [!"num:i($DIO_AR_RELEASE_MAJOR_VERSION_TEMPLATE)"!]) are different"
    [!ENDERROR!]
[!ENDIF!]
[!IF "not(num:i(ArReleaseMinorVersion)  = num:i($DIO_AR_RELEASE_MINOR_VERSION_TEMPLATE))"!]
    [!ERROR!]
        "AUTOSAR release minor version number of the Basic Software Module Description file (Dio.epd version [!"ArReleaseMinorVersion"!]) and the Code template file (Dio_Cfg.c version [!"num:i($DIO_AR_RELEASE_MINOR_VERSION_TEMPLATE)"!]) are different"
    [!ENDERROR!]
[!ENDIF!]
[!IF "not(num:i(ArReleaseRevisionVersion)  = num:i($DIO_AR_RELEASE_REVISION_VERSION_TEMPLATE))"!]
    [!ERROR!]
        "AUTOSAR release revision version number of the Basic Software Module Description file (Dio.epd version [!"ArReleaseRevisionVersion"!]) and the Code template file (Dio_Cfg.c version [!"num:i($DIO_AR_RELEASE_REVISION_VERSION_TEMPLATE)"!]) are different"
    [!ENDERROR!]
[!ENDIF!]
[!IF "not(num:i(SwMajorVersion) = num:i($DIO_SW_MAJOR_VERSION_TEMPLATE))"!]
    [!ERROR!]
        "The software major number of the Basic Software Module Description file (Dio.epd version [!"SwMajorVersion"!]) and the Code template file (Dio_Cfg.c version [!"num:i($DIO_SW_MAJOR_VERSION_TEMPLATE)"!]) are different"
    [!ENDERROR!]
[!ENDIF!]
[!IF "not(num:i(SwMinorVersion) = num:i($DIO_SW_MINOR_VERSION_TEMPLATE))"!]
    [!ERROR!]
        "The software minor number of the Basic Software Module Description file (Dio.epd version [!"SwMinorVersion"!]) and the Code template file (Dio_Cfg.c version [!"num:i($DIO_SW_MINOR_VERSION_TEMPLATE)"!]) are different"
    [!ENDERROR!]
[!ENDIF!]
[!IF "not(num:i(SwPatchVersion) = num:i($DIO_SW_PATCH_VERSION_TEMPLATE))"!]
    [!ERROR!]
        "The software patch number of the Basic Software Module Description file (Dio.epd version [!"SwPatchVersion"!]) and the Code template file (Dio_Cfg.c version [!"num:i($DIO_SW_PATCH_VERSION_TEMPLATE)"!]) are different"
    [!ENDERROR!]
[!ENDIF!]
[!ENDSELECT!][!//

[!ENDIF!][!// avoid multiple inclusion ENDIF
[!ENDNOCODE!][!//
