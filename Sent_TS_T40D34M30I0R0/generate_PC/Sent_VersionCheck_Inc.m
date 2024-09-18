[!NOCODE!][!//
/**
  @file    Sent_VersionCheck_Inc.m
  @version 3.0.0

  @brief   AUTOSAR Sent - version check macro.
  @details Version checks.
  
  Project RTD AUTOSAR 4.7
  Platform CORTEXM
  Peripheral FLEXIO_SENT_IP
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

[!/* avoid multiple inclusion */!]
[!IF "not(var:defined('SENT_VERSION_CHECK_INC_M'))"!]
[!VAR "SENT_VERSION_CHECK_INC_M"="'true'"!]

[!VAR "SENT_AR_RELEASE_MAJOR_VERSION_TEMPLATE"="4"!][!// 
[!VAR "SENT_AR_RELEASE_MINOR_VERSION_TEMPLATE"="7"!][!// 
[!VAR "SENT_AR_RELEASE_REVISION_VERSION_TEMPLATE"="0"!][!// 
[!VAR "SENT_SW_MAJOR_VERSION_TEMPLATE"="3"!][!//      
[!VAR "SENT_SW_MINOR_VERSION_TEMPLATE"="0"!][!//
[!VAR "SENT_SW_PATCH_VERSION_TEMPLATE"="0"!][!//      

[!SELECT "CommonPublishedInformation"!][!//
[!IF "not(num:i(ArReleaseMajorVersion) = num:i($SENT_AR_RELEASE_MAJOR_VERSION_TEMPLATE))"!]
    [!ERROR!]
        "AUTOSAR major version number of the Basic Software Module Description file (Sent.epd version [!"ArReleaseMajorVersion"!]) and the Code template file (Sent_Cfg.h version [!"num:i($SENT_AR_RELEASE_MAJOR_VERSION_TEMPLATE)"!]) are different"
    [!ENDERROR!]
[!ENDIF!]
[!IF "not(num:i(ArReleaseMinorVersion) = num:i($SENT_AR_RELEASE_MINOR_VERSION_TEMPLATE))"!]
    [!ERROR!]
        "AUTOSAR minor version number of the Basic Software Module Description file (Sent.epd version [!"ArReleaseMinorVersion"!]) and the Code template file (Sent_Cfg.h version [!"num:i($SENT_AR_RELEASE_MINOR_VERSION_TEMPLATE)"!]) are different"
    [!ENDERROR!]
[!ENDIF!]
[!IF "not(num:i(ArReleaseRevisionVersion) = num:i($SENT_AR_RELEASE_REVISION_VERSION_TEMPLATE))"!]
    [!ERROR!]
        "AUTOSAR patch version number of the Basic Software Module Description file (Sent.epd version [!"ArReleaseRevisionVersion"!]) and the Code template file (Sent_Cfg.h version [!"num:i($SENT_AR_RELEASE_REVISION_VERSION_TEMPLATE)"!]) are different"
    [!ENDERROR!]
[!ENDIF!]
[!IF "not(num:i(SwMajorVersion) = num:i($SENT_SW_MAJOR_VERSION_TEMPLATE))"!]
    [!ERROR!]
        "The software major number of the Basic Software Module Description file (Sent.epd version [!"SwMajorVersion"!]) and the Code template file (Sent_Cfg.h version [!"num:i($SENT_SW_MAJOR_VERSION_TEMPLATE)"!]) are different"
    [!ENDERROR!]
[!ENDIF!]
[!IF "not(num:i(SwMinorVersion) = num:i($SENT_SW_MINOR_VERSION_TEMPLATE))"!]
    [!ERROR!]
        "The software minor number of the Basic Software Module Description file (Sent.epd version [!"SwMinorVersion"!]) and the Code template file (Sent_Cfg.h version [!"num:i($SENT_SW_MINOR_VERSION_TEMPLATE)"!]) are different"
    [!ENDERROR!]
[!ENDIF!]
[!IF "not(num:i(SwPatchVersion) = num:i($SENT_SW_PATCH_VERSION_TEMPLATE))"!]
    [!ERROR!]
        "The software patch number of the Basic Software Module Description file (Sent.epd version [!"SwPatchVersion"!]) and the Code template file (Sent_Cfg.h version [!"num:i($SENT_SW_PATCH_VERSION_TEMPLATE)"!]) are different"
    [!ENDERROR!]
[!ENDIF!]
[!ENDSELECT!][!//

[!ENDIF!][!// avoid multiple inclusion ENDIF

[!ENDNOCODE!][!//