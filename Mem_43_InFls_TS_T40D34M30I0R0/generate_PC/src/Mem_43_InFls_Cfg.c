[!NOCODE!][!//
[!//////////////////////////////////////////////////////////////////////////////////////////////////
[!////////////////////////   VARIABLE DEFINE FOR EB TRESOS       ///////////////////////////////////

[!VAR "MemName"      = "'Mem_43_InFls'"!][!//
[!VAR "MemNameUpper" = "text:toupper($MemName)"!][!//


[!//////////////////////////////////////////////////////////////////////////////////////////////////
[!///////////////////////    FUNCTION (MACRO) FOR EB TRESOS      ///////////////////////////////////

[!// Support line alignment with MACRO PrintAlign
[!VAR "CommentAlignment" = "60"!][!//
[!VAR "PaddingSpaces" = "'                                                                              '"!][!//
[!MACRO "PrintAlign", "Tabs" = "1", "Str" = "''", "Unit" = "''", "Cmt" = "''", "Comma" = "','"!][!//
    [!VAR "StrOut" = "''"!][!// Init the output string
    [!FOR "i" = "1" TO "$Tabs"!][!// Add tabs
        [!VAR "StrOut" = "concat($StrOut, '    ')"!][!//
    [!ENDFOR!][!//
    [!VAR "StrOut" = "concat($StrOut, $Str)"!][!//
    [!VAR "StrOut" = "concat($StrOut, $Unit)"!][!//
    [!VAR "StrOut" = "concat($StrOut, $Comma)"!][!//
    [!VAR "StrOut" = "concat($StrOut, $PaddingSpaces)"!][!// Padding spaces for alignment
    [!VAR "StrOut" = "substring($StrOut, 1, $CommentAlignment)"!][!// Perform the alignment
    [!VAR "StrOut" = "concat($StrOut, $Cmt)"!][!//
    [!CODE!][!"$StrOut"!][!CR!][!ENDCODE!][!// Print the output string
[!ENDMACRO!][!//
[!//


[!//////////////////////////////////////////////////////////////////////////////////////////////////
[!ENDNOCODE!][!//
[!AUTOSPACING!][!//
/*==================================================================================================
*   Project              : RTD AUTOSAR 4.7
*   Platform             : CORTEXM
*   Peripheral           : C40
*   Dependencies         : None
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
 * @file        [!"$MemName"!]_Cfg.c
 *
 * @addtogroup  [!"$MemNameUpper"!] Driver
 * implements   Mem_43_InFls_Cfg.c_Artifact
 *
 * @{
 */

#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "[!"$MemName"!]_Cfg.h"
#include "C40_Ip_Cfg.h"

/*==================================================================================================
                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define [!"$MemNameUpper"!]_VENDOR_ID_CFG_C                          43
#define [!"$MemNameUpper"!]_AR_RELEASE_MAJOR_VERSION_CFG_C           4
#define [!"$MemNameUpper"!]_AR_RELEASE_MINOR_VERSION_CFG_C           7
#define [!"$MemNameUpper"!]_AR_RELEASE_REVISION_VERSION_CFG_C        0
#define [!"$MemNameUpper"!]_SW_MAJOR_VERSION_CFG_C                   3
#define [!"$MemNameUpper"!]_SW_MINOR_VERSION_CFG_C                   0
#define [!"$MemNameUpper"!]_SW_PATCH_VERSION_CFG_C                   0

/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/
[!INCLUDE "Mem_43_InFls_VersionCheck.m"!][!//

/* Check if current file and [!"$MemName"!]_Cfg.h header file are of the same vendor */
#if ([!"$MemNameUpper"!]_VENDOR_ID_CFG_C != [!"$MemNameUpper"!]_VENDOR_ID_CFG)
    #error "[!"$MemName"!]_Cfg.c and [!"$MemName"!]_Cfg.h have different vendor ids"
#endif
/* Check if current file and [!"$MemName"!]_Cfg.h header file are of the same Autosar version */
#if (([!"$MemNameUpper"!]_AR_RELEASE_MAJOR_VERSION_CFG_C    != [!"$MemNameUpper"!]_AR_RELEASE_MAJOR_VERSION_CFG) || \
     ([!"$MemNameUpper"!]_AR_RELEASE_MINOR_VERSION_CFG_C    != [!"$MemNameUpper"!]_AR_RELEASE_MINOR_VERSION_CFG) || \
     ([!"$MemNameUpper"!]_AR_RELEASE_REVISION_VERSION_CFG_C != [!"$MemNameUpper"!]_AR_RELEASE_REVISION_VERSION_CFG) \
    )
    #error "AutoSar Version Numbers of [!"$MemName"!]_Cfg.c and [!"$MemName"!]_Cfg.h are different"
#endif
/* Check if current file and [!"$MemName"!]_Cfg.h header file are of the same Software version */
#if (([!"$MemNameUpper"!]_SW_MAJOR_VERSION_CFG_C != [!"$MemNameUpper"!]_SW_MAJOR_VERSION_CFG) || \
     ([!"$MemNameUpper"!]_SW_MINOR_VERSION_CFG_C != [!"$MemNameUpper"!]_SW_MINOR_VERSION_CFG) || \
     ([!"$MemNameUpper"!]_SW_PATCH_VERSION_CFG_C != [!"$MemNameUpper"!]_SW_PATCH_VERSION_CFG) \
    )
    #error "Software Version Numbers of [!"$MemName"!]_Cfg.c and [!"$MemName"!]_Cfg.h are different"
#endif

/* Check if current file and C40_Ip_Cfg.h header file are of the same vendor */
#if ([!"$MemNameUpper"!]_VENDOR_ID_CFG_C != C40_IP_VENDOR_ID_CFG)
    #error "[!"$MemName"!]_Cfg.c and C40_Ip_Cfg.h have different vendor ids"
#endif
/* Check if current file and C40_Ip_Cfg.h header file are of the same Autosar version */
#if (([!"$MemNameUpper"!]_AR_RELEASE_MAJOR_VERSION_CFG_C    != C40_IP_AR_RELEASE_MAJOR_VERSION_CFG) || \
     ([!"$MemNameUpper"!]_AR_RELEASE_MINOR_VERSION_CFG_C    != C40_IP_AR_RELEASE_MINOR_VERSION_CFG) || \
     ([!"$MemNameUpper"!]_AR_RELEASE_REVISION_VERSION_CFG_C != C40_IP_AR_RELEASE_REVISION_VERSION_CFG) \
    )
    #error "AutoSar Version Numbers of [!"$MemName"!]_Cfg.c and C40_Ip_Cfg.h are different"
#endif
/* Check if current file and C40_Ip_Cfg.h header file are of the same Software version */
#if (([!"$MemNameUpper"!]_SW_MAJOR_VERSION_CFG_C != C40_IP_SW_MAJOR_VERSION_CFG) || \
     ([!"$MemNameUpper"!]_SW_MINOR_VERSION_CFG_C != C40_IP_SW_MINOR_VERSION_CFG) || \
     ([!"$MemNameUpper"!]_SW_PATCH_VERSION_CFG_C != C40_IP_SW_PATCH_VERSION_CFG) \
    )
    #error "Software Version Numbers of [!"$MemName"!]_Cfg.c and C40_Ip_Cfg.h are different"
#endif

/*==================================================================================================
                                 GLOBAL CONSTANT DECLARATIONS
==================================================================================================*/

#define [!"$MemNameUpper"!]_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "[!"$MemName"!]_MemMap.h"


/* Mem Internal Units Configurations */
static const [!"$MemName"!]_InternalUnitType [!"$MemName"!]_InternalUnitsCfg[[!"$MemNameUpper"!]_INTERNAL_UNIT_COUNT] =
{
    {
        [!CALL "PrintAlign", "Tabs"="2", "Str"="'&C40_Ip_InitCfg'", "Cmt"="'/* InternalConfig */'", "Comma" = " '' "!]
    }
};

/* Mem Devices Configurations */
static const [!"$MemName"!]_MemDeviceType [!"$MemName"!]_MemDevices =
{
    [!CALL "PrintAlign", "Str"="concat($MemName, '_InternalUnitsCfg')", "Cmt"="'/* InternalUnits */'", "Comma" = " '' "!]
};


/* Configuration of MemSectorBatch */
[!LOOP "MemInstance/*"!]
const [!"$MemName"!]_SectorBatchType [!"$MemName"!]_[!"node:name(.)"!]_SectorBatch[[!"num:i(count(./MemSectorBatch/*))"!]U] =
{
    [!VAR "LoopIt" = "count(./MemSectorBatch/*)"!]
    [!LOOP "./MemSectorBatch/*"!]
    [!VAR "LoopIt"            = "$LoopIt - 1"!]
    [!VAR "StartAddress"      = "./MemStartAddress"!]
    [!VAR "EndAddress"        = "num:i(./MemStartAddress + ./MemNumberOfSectors * ./MemEraseSectorSize - 1)"!]
    [!VAR "SectorSize"        = "./MemEraseSectorSize"!]
    [!VAR "ReadPageSize"      = "./MemReadPageSize"!]
    [!VAR "WritePageSize"     = "./MemWritePageSize"!]
    [!VAR "EraseBurstSize"    = "node:when(node:exists(./MemBurstSettings), ./MemBurstSettings/MemEraseBurstSize, ./MemEraseSectorSize)"!]
    [!VAR "ReadBurstSize"     = "node:when(node:exists(./MemBurstSettings), ./MemBurstSettings/MemReadBurstSize,  ./MemReadPageSize)"!]
    [!VAR "WriteBurstSize"    = "node:when(node:exists(./MemBurstSettings), ./MemBurstSettings/MemWriteBurstSize, ./MemWritePageSize)"!]
    {
        /* [!"node:name(.)"!] */
        [!CALL "PrintAlign", "Tabs"="2", "Str"="$StartAddress",   "Unit"="'U'", "Cmt"="'/* StartAddress   */'  "!]
        [!CALL "PrintAlign", "Tabs"="2", "Str"="$EndAddress",     "Unit"="'U'", "Cmt"="'/* EndAddress     */'  "!]
        [!CALL "PrintAlign", "Tabs"="2", "Str"="$SectorSize",     "Unit"="'U'", "Cmt"="'/* SectorSize     */'  "!]
        [!CALL "PrintAlign", "Tabs"="2", "Str"="$ReadPageSize",   "Unit"="'U'", "Cmt"="'/* ReadPageSize   */'  "!]
        [!CALL "PrintAlign", "Tabs"="2", "Str"="$WritePageSize",  "Unit"="'U'", "Cmt"="'/* WritePageSize  */'  "!]
        [!CALL "PrintAlign", "Tabs"="2", "Str"="$EraseBurstSize", "Unit"="'U'", "Cmt"="'/* EraseBurstSize */'  "!]
        [!CALL "PrintAlign", "Tabs"="2", "Str"="$ReadBurstSize",  "Unit"="'U'", "Cmt"="'/* ReadBurstSize  */'  "!]
        [!CALL "PrintAlign", "Tabs"="2", "Str"="$WriteBurstSize", "Unit"="'U'", "Cmt"="'/* WriteBurstSize */'  "!]
    }[!IF "$LoopIt != 0"!],[!ENDIF!][!CR!][!//
    [!ENDLOOP!]
};

[!ENDLOOP!][!//

/* Configuration of Mem instances */
static const [!"$MemName"!]_MemInstanceType [!"$MemName"!]_MemInstances[[!"$MemNameUpper"!]_MEM_INSTANCE_COUNT] =
{
[!VAR "LoopIt" = "count(MemInstance/*)"!]
[!//[!LOOP "node:order(MemInstance/*, 'node:value(./MemInstanceId)')"!][!// Iterate through the MemInstanceId value
[!LOOP "MemInstance/*"!][!// Iterate through the index value
    [!VAR "LoopIt"             = "$LoopIt - 1"!]
    [!VAR "InstanceId"         = "concat($MemNameUpper, '_INSTANCE_', node:pos(.), '_ID')"!]
    [!VAR "SectorBatchCount"   = "num:i(count(./MemSectorBatch/*))"!]
    [!VAR "SectorBatch"        = "concat($MemName, '_', node:name(.), '_SectorBatch')"!]
    [!VAR "MemUnitIndex"       = "num:i(0)"!]
    {
        /* [!"node:name(.)"!] */
        [!CALL "PrintAlign", "Tabs"="2", "Str"="$InstanceId",       "Unit"="''",  "Cmt"="'/* InstanceId       */'  "!]
        [!CALL "PrintAlign", "Tabs"="2", "Str"="$SectorBatchCount", "Unit"="'U'", "Cmt"="'/* SectorBatchCount */'  "!]
        [!CALL "PrintAlign", "Tabs"="2", "Str"="$SectorBatch",      "Unit"="''",  "Cmt"="'/* SectorBatches    */'  "!]
        [!CALL "PrintAlign", "Tabs"="2", "Str"="$MemUnitIndex",     "Unit"="'U'", "Cmt"="'/* MemUnitIndex     */'  "!]
    }[!IF "$LoopIt != 0"!],[!ENDIF!][!CR!][!//
[!ENDLOOP!]
};


/* Configuration of [!"$MemName"!] */
const [!"$MemName"!]_ConfigType [!"$MemName"!]_Config =
{
    [!CALL "PrintAlign", "Str"="concat($MemName, '_MemInstances')",     "Cmt"="'/* MemInstances */'  "!]
    [!CALL "PrintAlign", "Str"="concat('&', $MemName, '_MemDevices')",  "Cmt"="'/* MemDevices   */'", "Comma" = " '' "!]
};


#define [!"$MemNameUpper"!]_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "[!"$MemName"!]_MemMap.h"


/*==================================================================================================
                                           CONSTANTS
==================================================================================================*/


#ifdef __cplusplus
}
#endif

/** @} */
