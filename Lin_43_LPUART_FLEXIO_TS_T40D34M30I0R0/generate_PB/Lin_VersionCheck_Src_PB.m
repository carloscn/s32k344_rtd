[!NOCODE!][!//
/**
    @file    LIN_VersionCheck_Inc.m
    @version 3.0.0

    @brief   AUTOSAR Lin_43_LPUART_FLEXIO - Brief description.
    @details Version check variables vor Lin_PBcfg.c

    Project RTD AUTOSAR 4.7
    Patform CORTEXM
    Peripheral LPUART_FLEXIO
    Dependencies none

    ARVersion 4.7.0
    ARRevision ASR_REL_4_7_REV_0000
    ARConfVariant
    SWVersion 3.0.0
    BuildVersion S32K3_RTD_3_0_0_D2303_ASR_REL_4_7_REV_0000_20230331

    (c) Copyright 2020 - 2023 NXP Semiconductors. 
    All Rights Reserved.
*/
/*==================================================================================================
==================================================================================================*/

[!VAR "LIN_AR_MAJOR_VERSION_TEMPLATE"="4"!][!//
[!VAR "LIN_AR_MINOR_VERSION_TEMPLATE"="7"!][!//
[!VAR "LIN_AR_PATCH_VERSION_TEMPLATE"="0"!][!//
[!VAR "LIN_SW_MAJOR_VERSION_TEMPLATE"="3"!][!//
[!VAR "LIN_SW_MINOR_VERSION_TEMPLATE"="0"!][!//
[!VAR "LIN_SW_PATCH_VERSION_TEMPLATE"="0"!][!//
[!ENDNOCODE!][!//

[!SELECT "CommonPublishedInformation"!][!//
[!IF "num:i(ArReleaseMajorVersion) != num:i($LIN_AR_MAJOR_VERSION_TEMPLATE)"!]
[!ERROR!]
      **** AUTOSAR major version number of the Basic Software Module Description file (Lin.epd version [!"ArReleaseMajorVersion"!]) and the Code template file (Lin_PBcfg.c  version [!"num:i($LIN_AR_MAJOR_VERSION_TEMPLATE)"!]) are different ****
[!ENDERROR!]
[!ENDIF!][!//
[!IF "num:i(ArReleaseMinorVersion)  != num:i($LIN_AR_MINOR_VERSION_TEMPLATE)"!]
[!ERROR!]
      **** AUTOSAR minor version number of the Basic Software Module Description file (Lin.epd version [!"ArReleaseMinorVersion"!]) and the Code template file (Lin_PBcfg.c  version [!"num:i($LIN_AR_MINOR_VERSION_TEMPLATE)"!]) are different ****
[!ENDERROR!]
[!ENDIF!][!//
[!IF "num:i(ArReleaseRevisionVersion)  != num:i($LIN_AR_PATCH_VERSION_TEMPLATE)"!]
[!ERROR!]
      **** AUTOSAR patch version number of the Basic Software Module Description file (Lin.epd version [!"ArReleaseRevisionVersion"!]) and the Code template file (Lin_PBcfg.c  version [!"num:i($LIN_AR_PATCH_VERSION_TEMPLATE)"!]) are different ****
[!ENDERROR!]
[!ENDIF!][!//
[!IF "num:i(SwMajorVersion) != num:i($LIN_SW_MAJOR_VERSION_TEMPLATE)"!]
[!ERROR!]
      **** The software major number of the Basic Software Module Description file (Lin.epd version [!"SwMajorVersion"!]) and the Code template file (Lin_PBcfg.c  version [!"num:i($LIN_SW_MAJOR_VERSION_TEMPLATE)"!]) are different ****
[!ENDERROR!]
[!ENDIF!][!//
[!IF "num:i(SwMinorVersion) != num:i($LIN_SW_MINOR_VERSION_TEMPLATE)"!]
[!ERROR!]
      **** The software minor number of the Basic Software Module Description file (Lin.epd version [!"SwMinorVersion"!]) and the Code template file (Lin_PBcfg.c  version [!"num:i($LIN_SW_MINOR_VERSION_TEMPLATE)"!]) are different ****
[!ENDERROR!]
[!ENDIF!][!//
[!IF "num:i(SwPatchVersion) != num:i($LIN_SW_PATCH_VERSION_TEMPLATE)"!]
[!ERROR!]
      **** The software patch number of the Basic Software Module Description file (Lin.epd version [!"SwPatchVersion"!]) and the Code template file (Lin_PBcfg.c  version [!"num:i($LIN_SW_PATCH_VERSION_TEMPLATE)"!]) are different ****
[!ENDERROR!]
[!ENDIF!][!//
[!ENDSELECT!][!//
[!NOCODE!][!//
[!ENDNOCODE!][!//
