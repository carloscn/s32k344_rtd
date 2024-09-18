/*==================================================================================================
*   Project              : RTD AUTOSAR 4.7
*   Platform             : CORTEXM
*   Peripheral           : IPV_QSPI
*   Dependencies         : None
*
*   Autosar Version      : 4.7.0
*   Autosar Revision     : ASR_REL_4_7_REV_0000
*   Autosar Conf.Variant :
*   SW Version           : 3.0.0
*   Build Version        : S32K3_RTD_3_0_0_D2303_ASR_REL_4_7_REV_0000_20230331
*
*   (c) Copyright 2020 - 2023 NXP Semiconductors
*   All Rights Reserved.
==================================================================================================*/
/**
*   @file    Mem_43_ExFls_VersionCheck.m
*   @version 3.0.0
*
*   @brief   AUTOSAR Mem_43_ExFls - version check macro.
*   @details Version checks.
*
*   @addtogroup MEM_43_EXFLS
*   @{
*/
[!NOCODE!][!//

[!/* *** multiple inclusion protection *** */!]
[!IF "not(var:defined('MEM_43_EXFLS_VERSIONCHECK_M'))"!]
[!VAR "MEM_43_EXFLS_VERSIONCHECK_M"="'true'"!]

[!VAR "MEM_43_EXFLS_AR_RELEASE_MAJOR_VERSION_TEMPLATE"="4"!][!//
[!VAR "MEM_43_EXFLS_AR_RELEASE_MINOR_VERSION_TEMPLATE"="7"!][!//
[!VAR "MEM_43_EXFLS_AR_RELEASE_REVISION_VERSION_TEMPLATE"="0"!][!//

[!VAR "MEM_43_EXFLS_SW_MAJOR_VERSION_TEMPLATE"="3"!][!//
[!VAR "MEM_43_EXFLS_SW_MINOR_VERSION_TEMPLATE"="0"!][!//
[!VAR "MEM_43_EXFLS_SW_PATCH_VERSION_TEMPLATE"="0"!][!//


[!SELECT "CommonPublishedInformation"!][!//

[!ASSERT "ArReleaseMajorVersion = num:i($MEM_43_EXFLS_AR_RELEASE_MAJOR_VERSION_TEMPLATE)"!]
    **** AUTOSAR release major version number of the Basic Software Module Description file (version [!"ArReleaseMajorVersion "!]) and the Code template file (version [!"num:i($MEM_43_EXFLS_AR_RELEASE_MAJOR_VERSION_TEMPLATE)"!]) are different ****
[!ENDASSERT!][!//
[!ASSERT "ArReleaseMinorVersion  = num:i($MEM_43_EXFLS_AR_RELEASE_MINOR_VERSION_TEMPLATE)"!]
    **** AUTOSAR release minor version number of the Basic Software Module Description file (version [!"ArReleaseMinorVersion"!]) and the Code template files (version [!"num:i($MEM_43_EXFLS_AR_RELEASE_MINOR_VERSION_TEMPLATE)"!]) are different ****
[!ENDASSERT!][!//
[!ASSERT "ArReleaseRevisionVersion  = num:i($MEM_43_EXFLS_AR_RELEASE_REVISION_VERSION_TEMPLATE)"!]
    **** AUTOSAR release revision version number of the Basic Software Module Description file (version [!"ArReleaseRevisionVersion"!]) and the Code template files (version [!"num:i($MEM_43_EXFLS_AR_RELEASE_REVISION_VERSION_TEMPLATE)"!]) are different ****
[!ENDASSERT!][!//

[!ASSERT "SwMajorVersion = num:i($MEM_43_EXFLS_SW_MAJOR_VERSION_TEMPLATE)"!]
    **** The software major number of the Basic Software Module Description file (version [!"SwMajorVersion"!]) and the Code template files (version [!"num:i($MEM_43_EXFLS_SW_MAJOR_VERSION_TEMPLATE)"!]) are different ****
[!ENDASSERT!][!//
[!ASSERT "SwMinorVersion = num:i($MEM_43_EXFLS_SW_MINOR_VERSION_TEMPLATE)"!]
    **** The software minor number of the Basic Software Module Description file (version [!"SwMinorVersion"!]) and the Code template files (version [!"num:i($MEM_43_EXFLS_SW_MINOR_VERSION_TEMPLATE)"!]) are different ****
[!ENDASSERT!][!//
[!ASSERT "SwPatchVersion = num:i($MEM_43_EXFLS_SW_PATCH_VERSION_TEMPLATE)"!]
    **** The software minor number of the Basic Software Module Description file (version [!"SwPatchVersion"!]) and the Code template files (version [!"num:i($MEM_43_EXFLS_SW_PATCH_VERSION_TEMPLATE)"!]) are different ****
[!ENDASSERT!][!//

[!ENDSELECT!][!//


[!ENDIF!][!// MEM_43_EXFLS_VERSIONCHECK_M

[!ENDNOCODE!][!//
