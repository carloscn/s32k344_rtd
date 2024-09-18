[!NOCODE!][!//
/**
  @file    Spi_VersionCheck_Inc.m
  @version 3.0.0

  @brief   AUTOSAR Spi - version check macro.
  @details Version checks.
  
  Project RTD AUTOSAR 4.7
  Patform CORTEXM
  Peripheral LPSPI
  Dependencies 
  
  ARVersion 4.7.0
  ARRevision ASR_REL_4_7_REV_0000
  ARConfVariant
  SWVersion 3.0.0
  BuildVersion S32K3_RTD_3_0_0_D2303_ASR_REL_4_7_REV_0000_20230331

  Copyright 2020 - 2023 NXP Semiconductors NXP


*/
/*==================================================================================================
==================================================================================================*/

[!/* avoid multiple inclusion */!]
[!IF "not(var:defined('SPI_VERSION_CHECK_INC_M'))"!]
[!VAR "SPI_VERSION_CHECK_INC_M"="'true'"!]

[!VAR "SPI_AR_RELEASE_MAJOR_VERSION_TEMPLATE"="4"!][!//
[!VAR "SPI_AR_RELEASE_MINOR_VERSION_TEMPLATE"="7"!][!//
[!VAR "SPI_AR_RELEASE_REVISION_VERSION_TEMPLATE"="0"!][!//
[!VAR "SPI_SW_MAJOR_VERSION_TEMPLATE"="3"!][!//
[!VAR "SPI_SW_MINOR_VERSION_TEMPLATE"="0"!][!//
[!VAR "SPI_SW_PATCH_VERSION_TEMPLATE"="0"!][!// 

[!SELECT "CommonPublishedInformation"!][!//
[!IF "not(num:i(ArReleaseMajorVersion) = num:i($SPI_AR_RELEASE_MAJOR_VERSION_TEMPLATE))"!]
    [!ERROR!]
        "AUTOSAR release major version number of the Basic Software Module Description file (Spi.epd version [!"ArReleaseMajorVersion "!]) and the Code template files (Spi_Cfg.h version [!"num:i($SPI_AR_RELEASE_MAJOR_VERSION_TEMPLATE)"!]) are different"
    [!ENDERROR!]
[!ENDIF!]
[!IF "not(num:i(ArReleaseMinorVersion) = num:i($SPI_AR_RELEASE_MINOR_VERSION_TEMPLATE))"!]
    [!ERROR!]
        "AUTOSAR release minor version number of the Basic Software Module Description file (Spi.epd version [!"ArReleaseMinorVersion"!]) and the Code template files (Spi_Cfg.h version [!"num:i($SPI_AR_RELEASE_MINOR_VERSION_TEMPLATE)"!]) are different"
    [!ENDERROR!]
[!ENDIF!]    
[!IF "not(num:i(ArReleaseRevisionVersion)  = num:i($SPI_AR_RELEASE_REVISION_VERSION_TEMPLATE))"!]
    [!ERROR!]
        "AUTOSAR release revision version number of the Basic Software Module Description file (Spi.epd version [!"ArReleaseRevisionVersion"!]) and the Code template files (Spi_Cfg.h version [!"num:i($SPI_AR_RELEASE_REVISION_VERSION_TEMPLATE)"!]) are different"
    [!ENDERROR!]
[!ENDIF!] 
[!IF "not(num:i(SwMajorVersion) = num:i($SPI_SW_MAJOR_VERSION_TEMPLATE))"!]
    [!ERROR!]
        "The software major number of the Basic Software Module Description file (Spi.epd version [!"SwMajorVersion"!]) and the Code template files (Spi_Cfg.h version [!"num:i($SPI_SW_MAJOR_VERSION_TEMPLATE)"!]) are different"
    [!ENDERROR!]
[!ENDIF!]
[!IF "not(num:i(SwMinorVersion) = num:i($SPI_SW_MINOR_VERSION_TEMPLATE))"!]
    [!ERROR!]
        "The software minor number of the Basic Software Module Description file (Spi.epd version [!"SwMinorVersion"!]) and the Code template files (Spi_Cfg.h version [!"num:i($SPI_SW_MINOR_VERSION_TEMPLATE)"!]) are different"
    [!ENDERROR!]
[!ENDIF!]
[!IF "not(num:i(SwPatchVersion) = num:i($SPI_SW_PATCH_VERSION_TEMPLATE))"!]
    [!ERROR!]
        "The software minor number of the Basic Software Module Description file (Spi.epd version [!"SwPatchVersion"!]) and the Code template files (Spi_Cfg.h version [!"num:i($SPI_SW_PATCH_VERSION_TEMPLATE)"!]) are different"
    [!ENDERROR!]
[!ENDIF!]
[!ENDSELECT!][!//

[!ENDIF!][!// avoid multiple inclusion ENDIF
[!ENDNOCODE!][!//
