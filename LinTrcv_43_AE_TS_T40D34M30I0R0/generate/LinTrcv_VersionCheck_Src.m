[!NOCODE!][!//
/**
    @file    LIN_VersionCheck_Inc.m
    @version 3.0.0

    @brief   AUTOSAR LinTrcv_43_AE - Brief description.
    @details Version check variables vor Lin_Cfg.c

    Project RTD AUTOSAR 4.7
    Patform CORTEXM
    Peripheral AE
    Dependencies none

    ARVersion 4.7.0
    ARRevision ASR_REL_4_7_REV_0000
    ARConfVariant
    SWVersion 3.0.0
    BuildVersion S32K3_RTD_3_0_0_D2303_ASR_REL_4_7_REV_0000_20230331

    (c) Copyright 2020 - 2023 NXP Semiconductors
    All Rights Reserved.
*/
/*==================================================================================================
==================================================================================================*/
[!VAR "LINTRCV_AR_MAJOR_VERSION_TEMPLATE"="4"!][!//
[!VAR "LINTRCV_AR_MINOR_VERSION_TEMPLATE"="7"!][!//
[!VAR "LINTRCV_AR_PATCH_VERSION_TEMPLATE"="0"!][!//
[!VAR "LINTRCV_SW_MAJOR_VERSION_TEMPLATE"="3"!][!//
[!VAR "LINTRCV_SW_MINOR_VERSION_TEMPLATE"="0"!][!//
[!VAR "LINTRCV_SW_PATCH_VERSION_TEMPLATE"="0"!][!//
[!ENDNOCODE!][!//

[!SELECT "CommonPublishedInformation"!][!//
[!IF "num:i(ArReleaseMajorVersion) != num:i($LINTRCV_AR_MAJOR_VERSION_TEMPLATE)"!]
    [!ERROR!]
          **** AUTOSAR major version number of the Basic Software Module Description file (Lin.epd version [!"ArReleaseMajorVersion"!]) and the Code template file (LinTrcv_Cfg.c version [!"num:i($LINTRCV_AR_MAJOR_VERSION_TEMPLATE)"!]) are different ****
    [!ENDERROR!]
[!ENDIF!][!//
[!IF "num:i(ArReleaseMinorVersion)  != num:i($LINTRCV_AR_MINOR_VERSION_TEMPLATE)"!]
    [!ERROR!]
          **** AUTOSAR minor version number of the Basic Software Module Description file (LinTrcv.epd version [!"ArReleaseMinorVersion"!]) and the Code template file (LinTrcv_Cfg.c version [!"num:i($LINTRCV_AR_MINOR_VERSION_TEMPLATE)"!]) are different ****
    [!ENDERROR!]
[!ENDIF!][!//
[!IF "num:i(ArReleaseRevisionVersion)  != num:i($LINTRCV_AR_PATCH_VERSION_TEMPLATE)"!]
    [!ERROR!]
          **** AUTOSAR patch version number of the Basic Software Module Description file (LinTrcv.epd version [!"ArReleaseRevisionVersion"!]) and the Code template file (LinTrcv_Cfg.c version [!"num:i($LINTRCV_AR_PATCH_VERSION_TEMPLATE)"!]) are different ****
    [!ENDERROR!]
[!ENDIF!][!//
[!IF "num:i(SwMajorVersion) != num:i($LINTRCV_SW_MAJOR_VERSION_TEMPLATE)"!]
    [!ERROR!]
          **** The software major number of the Basic Software Module Description file (LinTrcv.epd version [!"SwMajorVersion"!]) and the Code template file (LinTrcv_Cfg.c version [!"num:i($LINTRCV_SW_MAJOR_VERSION_TEMPLATE)"!]) are different ****
    [!ENDERROR!]
[!ENDIF!][!//
[!IF "num:i(SwMinorVersion) != num:i($LINTRCV_SW_MINOR_VERSION_TEMPLATE)"!]
    [!ERROR!]
          **** The software minor number of the Basic Software Module Description file (LinTrcv.epd version [!"SwMinorVersion"!]) and the Code template file (LinTrcv_Cfg.c version [!"num:i($LINTRCV_SW_MINOR_VERSION_TEMPLATE)"!]) are different ****
    [!ENDERROR!]
[!ENDIF!][!//
[!IF "num:i(SwPatchVersion) != num:i($LINTRCV_SW_PATCH_VERSION_TEMPLATE)"!]
    [!ERROR!]
          **** The software patch number of the Basic Software Module Description file (LinTrcv.epd version [!"SwPatchVersion"!]) and the Code template file (LinTrcv_Cfg.c version [!"num:i($LINTRCV_SW_PATCH_VERSION_TEMPLATE)"!]) are different ****
    [!ENDERROR!]
[!ENDIF!][!//
[!ENDSELECT!][!//
[!NOCODE!][!//
[!ENDNOCODE!][!//
