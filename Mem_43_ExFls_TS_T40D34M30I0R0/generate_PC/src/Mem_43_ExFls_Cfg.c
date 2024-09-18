[!NOCODE!]
[!//////////////////////////////////////////////////////////////////////////////////////////////////
[!//////////////////////////////////////////////////////////////////////////////////////////////////
[!//
[!//
[!VAR "MemUnits"  = "''"!]
[!VAR "QspiUnits" = "''"!]
[!LOOP "MemInstance/*"!]
    [!VAR "MemDeviceRef" = "./MemDeviceRef"!]
    [!IF "not(text:contains(string($MemUnits), $MemDeviceRef))"!][!// check for duplicated element
        [!VAR "MemUnits" = "concat($MemUnits, ',', $MemDeviceRef)"!][!// append to list
    [!ENDIF!]
    [!//
    [!VAR "MemQspiInstance" = "node:ref(./MemDeviceRef)/MemQspiInstance"!]
    [!IF "not(text:contains(string($QspiUnits), $MemQspiInstance))"!][!// check for duplicated element
        [!VAR "QspiUnits" = "concat($QspiUnits, ',', $MemQspiInstance)"!][!// append to list
    [!ENDIF!]
[!ENDLOOP!]
[!//
[!VAR "MemUnitsCount"          = "num:i( count( text:split($MemUnits,  ',') ) )"!]
[!VAR "QspiUnitsCount"         = "num:i( count( text:split($QspiUnits, ',') ) )"!]
[!//
[!VAR "SerialflashCfgCount"    = "num:i(count(MemDevice/MemSerialFlashCfg/*))"!][!//
[!VAR "HyperflashCfgCount"     = "num:i(count(MemDevice/MemHyperFlashCfg/*))"!][!//
[!VAR "FlashConfigCount"       = "num:i($SerialflashCfgCount + $HyperflashCfgCount)"!][!//
[!//
[!VAR "CommentAlignment" = "70"!][!//
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
[!//
[!//////////////////////////////////////////////////////////////////////////////////////////////////
[!//////////////////////////////////////////////////////////////////////////////////////////////////
[!ENDNOCODE!]
[!AUTOSPACING!]
[!CODE!]
[!//
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
*   @file Mem_ExFls_Cfg.c
*
*   @addtogroup MEM_EXFLS
*   @{
*/

/* implements Mem_43_ExFls_Cfg.c_Artifact */

#ifdef __cplusplus
extern "C"{
#endif


/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Mem_43_ExFls_Cfg.h"
#include "Qspi_Ip_Cfg.h"


/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define MEM_43_EXFLS_VENDOR_ID_PCFG_C                      43
#define MEM_43_EXFLS_AR_RELEASE_MAJOR_VERSION_PCFG_C       4
#define MEM_43_EXFLS_AR_RELEASE_MINOR_VERSION_PCFG_C       7
#define MEM_43_EXFLS_AR_RELEASE_REVISION_VERSION_PCFG_C    0
#define MEM_43_EXFLS_SW_MAJOR_VERSION_PCFG_C               3
#define MEM_43_EXFLS_SW_MINOR_VERSION_PCFG_C               0
#define MEM_43_EXFLS_SW_PATCH_VERSION_PCFG_C               0


/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/

[!INCLUDE "Mem_43_ExFls_VersionCheck.m"!][!//


/*==================================================================================================
                                 GLOBAL CONSTANT DECLARATIONS
==================================================================================================*/

#define MEM_43_EXFLS_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Mem_43_ExFls_MemMap.h"


/* QSPI units configurations */
static const Mem_43_ExFls_QspiUnitType Mem_43_ExFls_QspiUnitsCfg[MEM_43_EXFLS_QSPI_UNIT_COUNT] =
{
[!VAR "LoopIt" = "$QspiUnitsCount"!]
[!FOR "Unit" = "1" TO "$QspiUnitsCount"!]
    [!VAR "LoopIt"              = "$LoopIt - 1"!]
    [!VAR "ControllerPath"      = "text:split($QspiUnits, ',')[number($Unit)]"!]
    [!VAR "ControllerCfg"       = "'NULL_PTR'"!]
    [!VAR "ControllerCmt"       = "'/* skip configuration */'"!]
    [!VAR "ControllerInstance"  = "concat('(uint32)', node:ref($ControllerPath)/MemControllerName)"!]
    [!IF "node:refvalid( node:ref($ControllerPath)/MemControllerCfgRef )"!]
        [!VAR "ControllerPos"   = "node:pos( string( node:ref($ControllerPath)/MemControllerCfgRef ) )"!]
        [!VAR "ControllerCfg"   = "concat('&(Qspi_Ip_paQspiUnitCfg[', $ControllerPos, 'U])')"!]
        [!VAR "ControllerCmt"   = "'/* use ControllerCfg */'"!]
    [!ENDIF!]
    {
        [!CALL "PrintAlign", "Tabs"="2", "Str"="$ControllerInstance", "Unit"="''", "Cmt"="'/* HardwareInstance */'  "!]
        [!CALL "PrintAlign", "Tabs"="2", "Str"="$ControllerCfg",      "Unit"="''", "Cmt"="$ControllerCmt            "!]
    }[!IF "$LoopIt != 0"!],[!ENDIF!][!CR!][!//
[!ENDFOR!]
};

/* Memory units configurations */
static const Mem_43_ExFls_MemoryUnitType Mem_43_ExFls_MemUnitsCfg[MEM_43_EXFLS_MEM_UNIT_COUNT] =
{
[!VAR "LoopIt" = "$MemUnitsCount"!]
[!FOR "Unit" = "1" TO "$MemUnitsCount"!]
    [!VAR "LoopIt"             = "$LoopIt - 1"!]
    [!VAR "FlsMemPath"         = "text:split($MemUnits, ',')[number($Unit)]"!]
    [!VAR "FlsMemPos"          = "node:pos( node:ref($FlsMemPath) )"!]
    [!VAR "MemConnect"         = "concat('&(Qspi_Ip_paFlashConnectionCfg[', $FlsMemPos, 'U])')"!]
    [!VAR "AHBRead"            = "concat('(boolean)', text:toupper( node:ref($FlsMemPath)/MemAHBReadEnable ) )"!]
    [!VAR "MemCfg"             = "'NULL_PTR'"!]
    [!VAR "MemCmt"             = "'/* use SFDP */'"!]
    [!IF "node:ref($FlsMemPath)/MemUseSfdp = 'false'"!]
        [!VAR "MemCmt"         = "'/* use MemCfg */'"!]
        [!VAR "MemCfgPath"     = "node:ref($FlsMemPath)/MemCfgRef"!]
        [!VAR "MemCfgPos"      = "node:pos( string($MemCfgPath) )"!]
        [!IF "text:contains( node:path($MemCfgPath), 'HyperFlashCfg')"!]
            [!VAR "MemCfgPos"  = "num:i($MemCfgPos + $SerialflashCfgCount)"!][!//Add Hyperflash config offset
            [!VAR "MemCmt"     = "'/* use HyperFlashCfg */'"!]
        [!ENDIF!]
        [!VAR "MemCfg"         = "concat('&(Qspi_Ip_paFlashCfg[', $MemCfgPos, 'U])')"!]
    [!ENDIF!]
    {
        [!CALL "PrintAlign", "Tabs"="2", "Str"="$MemConnect", "Cmt"="'/* Connect  */'  "!]
        [!CALL "PrintAlign", "Tabs"="2", "Str"="$MemCfg",     "Cmt"="$MemCmt           "!]
        [!CALL "PrintAlign", "Tabs"="2", "Str"="$AHBRead",    "Cmt"="'/* AHB read */'  "!]
    }[!IF "$LoopIt != 0"!],[!ENDIF!][!CR!][!//
[!ENDFOR!]
};

/* External QSPI flash parameters. */
static const Mem_43_ExFls_MemDeviceType Mem_43_ExFls_MemDevices =
{
    [!CALL "PrintAlign", "Str"="'Mem_43_ExFls_QspiUnitsCfg'", "Cmt"="'/* QspiUnits */'  "!]
    [!CALL "PrintAlign", "Str"="'Mem_43_ExFls_MemUnitsCfg'",  "Cmt"="'/* MemUnits  */'  "!]
};


/* Configuration of MemSectorBatch */
[!LOOP "MemInstance/*"!]
const Mem_43_ExFls_SectorBatchType Mem_43_ExFls_[!"node:name(.)"!]_SectorBatch[[!"num:i(count(./MemSectorBatch/*))"!]U] =
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
static const Mem_43_ExFls_MemInstanceType Mem_43_ExFls_MemInstances[MEM_43_EXFLS_MEM_INSTANCE_COUNT] =
{
[!VAR "LoopIt" = "count(MemInstance/*)"!]
[!//[!LOOP "node:order(MemInstance/*, 'node:value(./MemInstanceId)')"!][!// Iterate through the MemInstanceId value
[!LOOP "MemInstance/*"!][!// Iterate through the index value
    [!VAR "LoopIt"             = "$LoopIt - 1"!]
    [!VAR "InstanceId"         = "concat('MEM_43_EXFLS_INSTANCE_', node:pos(.), '_ID')"!]
    [!VAR "SectorBatchCount"   = "num:i(count(./MemSectorBatch/*))"!]
    [!VAR "SectorBatch"        = "concat('Mem_43_ExFls_', node:name(.), '_SectorBatch')"!]
    [!VAR "MemUnitIndex"       = "0"!]
    [!FOR "Unit" = "1" TO "$MemUnitsCount"!]
        [!VAR "FlsMemPath" = "text:split($MemUnits, ',')[number($Unit)]"!]
        [!IF "$FlsMemPath  = ./MemDeviceRef"!]
            [!VAR "MemUnitIndex" = "num:i($Unit - 1)"!]
            [!BREAK!]
        [!ENDIF!]
    [!ENDFOR!]
    {
        /* [!"node:name(.)"!] */
        [!CALL "PrintAlign", "Tabs"="2", "Str"="$InstanceId",       "Unit"="''",  "Cmt"="'/* InstanceId       */'  "!]
        [!CALL "PrintAlign", "Tabs"="2", "Str"="$SectorBatchCount", "Unit"="'U'", "Cmt"="'/* SectorBatchCount */'  "!]
        [!CALL "PrintAlign", "Tabs"="2", "Str"="$SectorBatch",      "Unit"="''",  "Cmt"="'/* SectorBatches    */'  "!]
        [!CALL "PrintAlign", "Tabs"="2", "Str"="$MemUnitIndex",     "Unit"="'U'", "Cmt"="'/* MemUnitIndex     */'  "!]
    }[!IF "$LoopIt != 0"!],[!ENDIF!][!CR!][!//
[!ENDLOOP!]
};


/* Configuration of Mem_43_ExFls */
const Mem_43_ExFls_ConfigType Mem_43_ExFls_Config =
{
    [!CALL "PrintAlign", "Str"="'Mem_43_ExFls_MemInstances'", "Cmt"="'/* MemInstances */'  "!]
    [!CALL "PrintAlign", "Str"="'&Mem_43_ExFls_MemDevices'",  "Cmt"="'/* MemDevices   */'  "!]
};


#define MEM_43_EXFLS_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Mem_43_ExFls_MemMap.h"


/*==================================================================================================
                                           CONSTANTS
==================================================================================================*/


#ifdef __cplusplus
}
#endif

/** @}*/
[!ENDCODE!][!//
