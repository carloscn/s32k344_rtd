[!NOCODE!][!//
/**
  @file    Can_VersionCheck_Inc.m
  @version 3.0.0

  @brief   AUTOSAR Can_43_FLEXCAN - version check macro.
  @details Version checks.

  Project RTD AUTOSAR 4.7
  Platform CORTEXM
  Peripheral FLEXCAN
  Dependencies 

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

[!/* avoid multiple inclusion */!]
[!IF "not(var:defined('CAN_VERSION_CHECK_INC_M'))"!]
[!VAR "CAN_VERSION_CHECK_INC_M"="'true'"!]

[!VAR "CAN_AR_RELEASE_MAJOR_VERSION_TEMPLATE"="4"!][!//
[!VAR "CAN_AR_RELEASE_MINOR_VERSION_TEMPLATE"="7"!][!//
[!VAR "CAN_AR_RELEASE_REVISION_VERSION_TEMPLATE"="0"!][!//
[!VAR "CAN_SW_MAJOR_VERSION_TEMPLATE"="3"!][!//
[!VAR "CAN_SW_MINOR_VERSION_TEMPLATE"="0"!][!//
[!VAR "CAN_SW_PATCH_VERSION_TEMPLATE"="0"!][!//

[!SELECT "CommonPublishedInformation"!][!//
[!IF "not(num:i(ArReleaseMajorVersion) = num:i($CAN_AR_RELEASE_MAJOR_VERSION_TEMPLATE))"!]
    [!ERROR!]
        "AUTOSAR major version number of the Basic Software Module Description file (Can.epd version [!"ArReleaseMajorVersion"!]) and the Code template file (Can_Cfg.h version [!"num:i($CAN_AR_RELEASE_MAJOR_VERSION_TEMPLATE)"!]) are different"
    [!ENDERROR!]
[!ENDIF!]
[!IF "not(num:i(ArReleaseMinorVersion) = num:i($CAN_AR_RELEASE_MINOR_VERSION_TEMPLATE))"!]
    [!ERROR!]
        "AUTOSAR minor version number of the Basic Software Module Description file (Can.epd version [!"ArReleaseMinorVersion"!]) and the Code template file (Can_Cfg.h version [!"num:i($CAN_AR_RELEASE_MINOR_VERSION_TEMPLATE)"!]) are different"
    [!ENDERROR!]
[!ENDIF!]
[!IF "not(num:i(ArReleaseRevisionVersion) = num:i($CAN_AR_RELEASE_REVISION_VERSION_TEMPLATE))"!]
    [!ERROR!]
        "AUTOSAR patch version number of the Basic Software Module Description file (Can.epd version [!"ArReleaseRevisionVersion"!]) and the Code template file (Can_Cfg.h version [!"num:i($CAN_AR_RELEASE_REVISION_VERSION_TEMPLATE)"!]) are different"
    [!ENDERROR!]
[!ENDIF!]
[!IF "not(num:i(SwMajorVersion) = num:i($CAN_SW_MAJOR_VERSION_TEMPLATE))"!]
    [!ERROR!]
        "The software major number of the Basic Software Module Description file (Can.epd version [!"SwMajorVersion"!]) and the Code template file (Can_Cfg.h version [!"num:i($CAN_SW_MAJOR_VERSION_TEMPLATE)"!]) are different"
    [!ENDERROR!]
[!ENDIF!]
[!IF "not(num:i(SwMinorVersion) = num:i($CAN_SW_MINOR_VERSION_TEMPLATE))"!]
    [!ERROR!]
        "The software minor number of the Basic Software Module Description file (Can.epd version [!"SwMinorVersion"!]) and the Code template file (Can_Cfg.h version [!"num:i($CAN_SW_MINOR_VERSION_TEMPLATE)"!]) are different"
    [!ENDERROR!]
[!ENDIF!]
[!IF "not(num:i(SwPatchVersion) = num:i($CAN_SW_PATCH_VERSION_TEMPLATE))"!]
    [!ERROR!]
        "The software patch number of the Basic Software Module Description file (Can.epd version [!"SwPatchVersion"!]) and the Code template file (Can_Cfg.h version [!"num:i($CAN_SW_PATCH_VERSION_TEMPLATE)"!]) are different"
    [!ENDERROR!]
[!ENDIF!]
[!ENDSELECT!][!//

[!ENDIF!][!// avoid multiple inclusion ENDIF

[!ENDNOCODE!][!//