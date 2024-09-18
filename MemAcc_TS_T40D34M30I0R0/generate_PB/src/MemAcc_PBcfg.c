[!NOCODE!]
[!//////////////////////////////////////////////////////////////////////////////////////////////////
[!//////////////////////////////////////////////////////////////////////////////////////////////////
[!//
[!//
[!// Global variable name used for all structure name
[!VAR "VariantName" = "''"!][!//
[!IF "var:defined('postBuildVariant')"!][!//
    [!VAR "VariantName" = "concat('_', $postBuildVariant)"!][!//
[!ENDIF!][!//
[!//
[!VAR "MemAccConfigName" = "'MemAcc'"!]
[!IF "var:defined('postBuildVariant')"!][!//
    [!VAR "MemAccConfigName" = "concat($MemAccConfigName, $VariantName)"!][!//
[!ENDIF!][!//
[!//
[!//
[!VAR "AddressAreaCount"  = "num:i( count(MemAccAddressAreaConfiguration/*) )"!]
[!//
[!//
[!VAR "MemDrivers" = "''"!]
[!VAR "MemDriversInvocation" = "''"!]
[!LOOP "MemAccAddressAreaConfiguration/*"!]
[!LOOP "MemAccSubAddressAreaConfiguration/*"!]
    [!VAR "MemName" = "MemAccMemNamePrefix"!][!// extract from path
    [!IF "not(text:contains(string($MemDrivers), $MemName))"!][!// check for duplicated element
        [!VAR "MemDrivers" = "concat($MemDrivers, ',', $MemName)"!][!// append to list
        [!VAR "MemDriversInvocation" = "concat($MemDriversInvocation, ',', concat('MEMACC_MEM_',./MemAccMemInvocation))"!][!// append to list
    [!ENDIF!]
[!ENDLOOP!]
[!ENDLOOP!]
[!//
[!VAR "MemDriverCount" = "num:i( count( text:split($MemDrivers, ',') ) )"!][!// split by comma and count
[!//
[!//
[!VAR "CommentAlignment" = "100"!][!//
[!VAR "PaddingSpaces" = "'                                                                                              '"!][!//
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
*   Peripheral           : none
*   Dependencies         : MemAcc
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
*   @file MemAcc[!"$VariantName"!]_PBcfg.h
*
*   @addtogroup MEMACC
*   @{
*/

/* implements MemAcc_PBcfg.c_Artifact */

#ifdef __cplusplus
extern "C"{
#endif


/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "MemAcc_Types.h"

[!FOR "LoopIt" = "1" TO "$MemDriverCount"!]
    [!VAR "MemInvocation"          = "text:split($MemDriversInvocation, ',')[number($LoopIt)]"!]
    [!VAR "MemName"                = "text:split($MemDrivers, ',')[number($LoopIt)]"!]
    [!IF "$MemInvocation != 'MEMACC_MEM_INDIRECT_DYNAMIC'"!]
#include "[!"$MemName"!].h"
    [!ENDIF!]
[!ENDFOR!]

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define MEMACC_VENDOR_ID_PCFG_C                      43
#define MEMACC_AR_RELEASE_MAJOR_VERSION_PCFG_C       4
#define MEMACC_AR_RELEASE_MINOR_VERSION_PCFG_C       7
#define MEMACC_AR_RELEASE_REVISION_VERSION_PCFG_C    0
#define MEMACC_SW_MAJOR_VERSION_PCFG_C               3
#define MEMACC_SW_MINOR_VERSION_PCFG_C               0
#define MEMACC_SW_PATCH_VERSION_PCFG_C               0


/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/

[!INCLUDE "MemAcc_VersionCheck.m"!][!//


/*==================================================================================================
                                       INTERNAL RUNTIME INFORMATION
==================================================================================================*/
#define MEMACC_START_SEC_CODE
#include "MemAcc_MemMap.h"
[!NOCODE!]

[!VAR "MemJobDoneCallBackList"!][!ENDVAR!]

[!LOOP "MemAccAddressAreaConfiguration/*"!]
    [!VAR "MemJobDoneCallBackList" = "concat($MemJobDoneCallBackList, MemAccJobEndNotificationName, ' ')"!]
[!ENDLOOP!]

[!VAR "MemUniqueCallBackList"!][!ENDVAR!]
[!VAR "MemUniqueCallBackList" = "concat($MemUniqueCallBackList, 'NULL_PTR', ' ')"!]

[!LOOP "text:split($MemJobDoneCallBackList)"!]
    [!IF "text:contains(text:split($MemUniqueCallBackList), . ) = 0"!]
        [!VAR "MemUniqueCallBackList" = "concat($MemUniqueCallBackList, . , ' ')"!]
        [!CODE!]extern void [!"."!](MemAcc_AddressAreaIdType AddressAreaId, MemAcc_JobResultType JobResult);[!CR!][!ENDCODE!]
    [!ENDIF!]
[!ENDLOOP!]
[!ENDNOCODE!]

#define MEMACC_STOP_SEC_CODE
#include "MemAcc_MemMap.h"

#define MEMACC_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "MemAcc_MemMap.h"

/* Information of the current processing job of each adddress area */
static MemAcc_JobRuntimeInfoType    [!"$MemAccConfigName"!]_JobRuntimeInfo[[!"$AddressAreaCount"!]];

#define MEMACC_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "MemAcc_MemMap.h"


/*==================================================================================================
                                 GLOBAL CONSTANT DECLARATIONS
==================================================================================================*/

#define MEMACC_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "MemAcc_MemMap.h"


/* Configuration of mem driver information */
static MemAcc_MemApiType [!"$MemAccConfigName"!]_MemApis[[!"$MemDriverCount"!]] =
{
[!FOR "LoopIt" = "1" TO "$MemDriverCount"!]
    [!VAR "MemInvocation"          = "text:split($MemDriversInvocation, ',')[number($LoopIt)]"!]
    [!VAR "MemName"                = "text:split($MemDrivers, ',')[number($LoopIt)]"!]
    [!VAR "UniqueId"               = "'0xFFFFFFFF'"!][!// not supported yet
    [!VAR "Flags"                  = "'0xFFFFFFFF'"!][!// not supported yet
    [!VAR "Header"                 = "'0xFFFFFFFF'"!][!// not supported yet
    [!VAR "Delimiter"              = "'0xFFFFFFFF'"!][!// not supported yet
    [!VAR "PropagateErrorFunc"     = "'NULL_PTR'"!]  [!// Does not use this function in Mem Acc
    [!VAR "SuspendFunc"            = "'NULL_PTR'"!]  [!// Does not use this function in Mem Acc
    [!VAR "ResumeFunc"             = "'NULL_PTR'"!]  [!// Does not use this function in Mem Acc
    [!IF "$MemInvocation != 'MEMACC_MEM_INDIRECT_DYNAMIC'"!]
        [!VAR "InitFunc"               = "concat('(MemAcc_MemInitFuncType)',              $MemName, '_Init')                  "!]
        [!VAR "DeInitFunc"             = "concat('(MemAcc_MemDeInitFuncType)',            $MemName, '_DeInit')                "!]
        [!VAR "MainFunc"               = "concat('(MemAcc_MemMainFuncType)',              $MemName, '_MainFunction')          "!]
        [!VAR "GetJobResultFunc"       = "concat('(MemAcc_MemGetJobResultFuncType)',      $MemName, '_GetJobResult')          "!]
        [!VAR "ReadFunc"               = "concat('(MemAcc_MemReadFuncType)',              $MemName, '_Read')                  "!]
        [!VAR "WriteFunc"              = "concat('(MemAcc_MemWriteFuncType)',             $MemName, '_Write')                 "!]
        [!VAR "EraseFunc"              = "concat('(MemAcc_MemEraseFuncType)',             $MemName, '_Erase')                 "!]
        [!VAR "BlankCheckFunc"         = "concat('(MemAcc_MemBlankCheckFuncType)',        $MemName, '_BlankCheck')            "!]
        [!VAR "HwSpecificServiceFunc"  = "concat('(MemAcc_MemHwSpecificServiceFuncType)', $MemName, '_HwSpecificService')     "!]
    [!ELSE!]
        [!VAR "InitFunc"               = "'NULL_PTR'"!]
        [!VAR "DeInitFunc"             = "'NULL_PTR'"!]
        [!VAR "MainFunc"               = "'NULL_PTR'"!]
        [!VAR "GetJobResultFunc"       = "'NULL_PTR'"!]
        [!VAR "ReadFunc"               = "'NULL_PTR'"!]
        [!VAR "WriteFunc"              = "'NULL_PTR'"!]
        [!VAR "EraseFunc"              = "'NULL_PTR'"!]
        [!VAR "BlankCheckFunc"         = "'NULL_PTR'"!]
        [!VAR "HwSpecificServiceFunc"  = "'NULL_PTR'"!]
    [!ENDIF!]
    {
        /* [!"$MemName"!] driver */
        [!CALL "PrintAlign", "Tabs"="2", "Str"="$UniqueId"              ,  "Unit"="'U'",  "Cmt"="'/* UniqueId               */'  "!]
        [!CALL "PrintAlign", "Tabs"="2", "Str"="$Flags"                 ,  "Unit"="'U'",  "Cmt"="'/* Flags                  */'  "!]
        [!CALL "PrintAlign", "Tabs"="2", "Str"="$Header"                ,  "Unit"="'U'",  "Cmt"="'/* Header                 */'  "!]
        [!CALL "PrintAlign", "Tabs"="2", "Str"="$Delimiter"             ,  "Unit"="'U'",  "Cmt"="'/* Delimiter              */'  "!]
        [!CALL "PrintAlign", "Tabs"="2", "Str"="$InitFunc"              ,  "Unit"="''",   "Cmt"="'/* InitFunc               */'  "!]
        [!CALL "PrintAlign", "Tabs"="2", "Str"="$DeInitFunc"            ,  "Unit"="''",   "Cmt"="'/* DeInitFunc             */'  "!]
        [!CALL "PrintAlign", "Tabs"="2", "Str"="$MainFunc"              ,  "Unit"="''",   "Cmt"="'/* MainFunc               */'  "!]
        [!CALL "PrintAlign", "Tabs"="2", "Str"="$GetJobResultFunc"      ,  "Unit"="''",   "Cmt"="'/* GetJobResultFunc       */'  "!]
        [!CALL "PrintAlign", "Tabs"="2", "Str"="$ReadFunc"              ,  "Unit"="''",   "Cmt"="'/* ReadFunc               */'  "!]
        [!CALL "PrintAlign", "Tabs"="2", "Str"="$WriteFunc"             ,  "Unit"="''",   "Cmt"="'/* WriteFunc              */'  "!]
        [!CALL "PrintAlign", "Tabs"="2", "Str"="$EraseFunc"             ,  "Unit"="''",   "Cmt"="'/* EraseFunc              */'  "!]
        [!CALL "PrintAlign", "Tabs"="2", "Str"="$BlankCheckFunc"        ,  "Unit"="''",   "Cmt"="'/* BlankCheckFunc         */'  "!]
        [!CALL "PrintAlign", "Tabs"="2", "Str"="$PropagateErrorFunc"    ,  "Unit"="''",   "Cmt"="'/* PropagateErrorFunc     */'  "!]
        [!CALL "PrintAlign", "Tabs"="2", "Str"="$SuspendFunc"           ,  "Unit"="''",   "Cmt"="'/* SuspendFunc            */'  "!]
        [!CALL "PrintAlign", "Tabs"="2", "Str"="$ResumeFunc"            ,  "Unit"="''",   "Cmt"="'/* ResumeFunc             */'  "!]
        [!CALL "PrintAlign", "Tabs"="2", "Str"="$HwSpecificServiceFunc" ,  "Unit"="''",   "Cmt"="'/* HwSpecificServiceFunc  */'  ","Comma"="''"!]
    }[!IF "$LoopIt != num:i($MemDriverCount)"!],[!ENDIF!][!CR!][!//
[!ENDFOR!]
};
/* Configuration of mem driver invocation type */
static const MemAcc_MemInvocationType [!"$MemAccConfigName"!]_MemInvocation[[!"$MemDriverCount"!]] =
{
[!FOR "LoopIt" = "1" TO "$MemDriverCount"!]
    [!"text:split($MemDriversInvocation, ',')[number($LoopIt)]"!][!IF "$LoopIt != num:i($MemDriverCount)"!],[!ENDIF!][!CR!][!//
[!ENDFOR!]
};
/* Configuration of sub address areas */
[!LOOP "MemAccAddressAreaConfiguration/*"!][!// Iterate through the index value
[!VAR "AreaName" = "node:name(.)"!]
static const MemAcc_SubAddressAreaType [!"$MemAccConfigName"!]_[!"$AreaName"!]_SubAreas[[!"num:i(count(./MemAccSubAddressAreaConfiguration/*))"!]U] =
{
    [!VAR "LoopIt" = "count(./MemAccSubAddressAreaConfiguration/*)"!]
    [!LOOP "./MemAccSubAddressAreaConfiguration/*"!]
    [!VAR "LoopIt"                 = "$LoopIt - 1"!]
    [!VAR "LogicalStartAddress"    = "./MemAccLogicalStartAddress"!]
    [!VAR "PhysicalSectorSize"     = "node:ref(./MemAccSectorBatchRef)/MemEraseSectorSize"!]
    [!VAR "PhysicalStartAddress"   = "num:i( node:ref(./MemAccSectorBatchRef)/MemStartAddress + $PhysicalSectorSize * ./MemAccSectorOffset )"!]
    [!VAR "Length"                 = "num:i( $PhysicalSectorSize * ./MemAccNumberOfSectors)"!]
    [!VAR "NumOfEraseRetries"      = "num:i( node:when(node:exists(./MemAccNumberOfEraseRetries), ./MemAccNumberOfEraseRetries, 0) )"!]
    [!VAR "NumOfWriteRetries"      = "num:i( node:when(node:exists(./MemAccNumberOfWriteRetries), ./MemAccNumberOfWriteRetries, 0) )"!]
    [!VAR "BurstSettings"          = "'0U'"!]
    [!IF "./MemAccUseEraseBurst"!][!VAR "BurstSettings" = "concat($BurstSettings, ' | MEMACC_BURST_ERASE')"!][!ENDIF!]
    [!IF "./MemAccUseReadBurst "!][!VAR "BurstSettings" = "concat($BurstSettings, ' | MEMACC_BURST_READ')"!][!ENDIF!]
    [!IF "./MemAccUseWriteBurst"!][!VAR "BurstSettings" = "concat($BurstSettings, ' | MEMACC_BURST_WRITE')"!][!ENDIF!]
    [!VAR "MemInvocation"          = "concat('MEMACC_MEM_',./MemAccMemInvocation)"!]
    [!VAR "MemInstanceId"          = "node:ref(./MemAccSectorBatchRef)/../../MemInstanceId"!]
    [!VAR "MemSectorBatchIndex"    = "node:pos(node:ref(./MemAccSectorBatchRef))"!]
    [!VAR "MemName"                = "text:split(./MemAccSectorBatchRef, '/')[2]"!][!// extract Mem driver name from path
    [!IF "./MemAccUseEraseBurst"!]
        [!VAR "SectorEraseBurstSize"    = "node:ref(./MemAccSectorBatchRef)/MemBurstSettings/MemEraseBurstSize"!]
    [!ELSE!]
        [!VAR "SectorEraseBurstSize"    = "node:ref(./MemAccSectorBatchRef)/MemEraseSectorSize"!]
    [!ENDIF!]
    [!IF "./MemAccUseReadBurst"!]
        [!VAR "ReadPageBurstSize"       = "node:ref(./MemAccSectorBatchRef)/MemBurstSettings/MemReadBurstSize"!]
    [!ELSE!]
        [!VAR "ReadPageBurstSize"       = "node:ref(./MemAccSectorBatchRef)/MemReadPageSize"!]
    [!ENDIF!]
    [!IF "./MemAccUseWriteBurst"!]
        [!VAR "WritePageBurstSize"      = "node:ref(./MemAccSectorBatchRef)/MemBurstSettings/MemWriteBurstSize"!]
    [!ELSE!]
        [!VAR "WritePageBurstSize"      = "node:ref(./MemAccSectorBatchRef)/MemWritePageSize"!]
    [!ENDIF!]
    
    [!VAR "SectorEraseSize"    = "node:ref(./MemAccSectorBatchRef)/MemEraseSectorSize"!]
    [!VAR "ReadPageSize"       = "node:ref(./MemAccSectorBatchRef)/MemReadPageSize"!]
    [!VAR "WritePageSize"      = "node:ref(./MemAccSectorBatchRef)/MemWritePageSize"!]

    [!VAR "MemApiIndex"            = "0"!]
    [!FOR "MemLoopIt" = "1" TO "$MemDriverCount"!][!// Find the according MemApi index
        [!IF "$MemName = text:split($MemDrivers, ',')[number($MemLoopIt)]"!]
            [!VAR "MemApiIndex" = "num:i($MemLoopIt - 1)"!]
            [!BREAK!]
        [!ENDIF!]
    [!ENDFOR!]
    [!VAR "MemApi"                 = "concat('&(', $MemAccConfigName, '_MemApis[MEMACC_', text:toupper(text:split($MemDrivers, ',')[number($MemLoopIt)]), '_HW_ID])')"!]
    [!VAR "MemHwResource"          = "''"!]
    [!IF "$MemName = 'Mem_43_ExFls'"!][!// TODO: check for, Mem_Eep in the future
        [!VAR "HwResourceName"     = "node:ref(node:ref(node:ref(./MemAccSectorBatchRef)/../../MemDeviceRef)/MemQspiInstance)/MemControllerName"!]
        [!IF "$HwResourceName      = 'QSPI_IP_INSTANCE_0'"!][!VAR "MemHwResource" = "'MEMACC_MEM_HW_QSPI_0'"!][!ENDIF!]
        [!IF "$HwResourceName      = 'QSPI_IP_INSTANCE_1'"!][!VAR "MemHwResource" = "'MEMACC_MEM_HW_QSPI_1'"!][!ENDIF!]
    [!ELSEIF "$MemName = 'Mem_43_InFls'"!]
        [!VAR "MemHwResource" = "'MEMACC_MEM_HW_INTERNAL'"!]
    [!ELSEIF "$MemName = 'Mem_43_Eep'"!]
        [!VAR "MemHwResource" = "'MEMACC_MEM_HW_EEP'"!]
    [!ENDIF!]
    [!VAR "Hw_Id"                 = "concat('MEMACC_', text:toupper(text:split($MemDrivers, ',')[number($MemLoopIt)]), '_HW_ID')"!]
    {
        /* [!"node:name(.)"!] */
        [!CALL "PrintAlign", "Tabs"="2", "Str"="$LogicalStartAddress",   "Unit"="'U'",  "Cmt"="'/* LogicalStartAddress  */'  "!]
        [!CALL "PrintAlign", "Tabs"="2", "Str"="$PhysicalStartAddress",  "Unit"="'U'",  "Cmt"="'/* PhysicalStartAddress */'  "!]
        [!CALL "PrintAlign", "Tabs"="2", "Str"="$Length",                "Unit"="'U'",  "Cmt"="'/* Length               */'  "!]
        [!CALL "PrintAlign", "Tabs"="2", "Str"="$NumOfEraseRetries",     "Unit"="'U'",  "Cmt"="'/* NumOfEraseRetries    */'  "!]
        [!CALL "PrintAlign", "Tabs"="2", "Str"="$NumOfWriteRetries",     "Unit"="'U'",  "Cmt"="'/* NumOfWriteRetries    */'  "!]
        [!CALL "PrintAlign", "Tabs"="2", "Str"="$BurstSettings",         "Unit"="''",   "Cmt"="'/* BurstSettings        */'  "!]
        [!CALL "PrintAlign", "Tabs"="2", "Str"="$MemInvocation",         "Unit"="''",   "Cmt"="'/* MemInvocation        */'  "!]
        [!CALL "PrintAlign", "Tabs"="2", "Str"="$MemApi",                "Unit"="''",   "Cmt"="'/* MemApi               */'  "!]
        [!CALL "PrintAlign", "Tabs"="2", "Str"="$MemInstanceId",         "Unit"="'U'",  "Cmt"="'/* MemInstanceId        */'  "!]
        {
            [!CALL "PrintAlign", "Tabs"="3", "Str"="$SectorEraseSize",            "Unit"="'U'",  "Cmt"="'/* SectorEraseSize      */'  "!]
            [!CALL "PrintAlign", "Tabs"="3", "Str"="$ReadPageSize",               "Unit"="'U'",  "Cmt"="'/* ReadPageSize         */'  "!]
            [!CALL "PrintAlign", "Tabs"="3", "Str"="$WritePageSize",              "Unit"="'U'",  "Cmt"="'/* WritePageSize        */'  "!]
            [!CALL "PrintAlign", "Tabs"="3", "Str"="$SectorEraseBurstSize",       "Unit"="'U'",  "Cmt"="'/* SectorEraseSize      */'  "!]
            [!CALL "PrintAlign", "Tabs"="3", "Str"="$ReadPageBurstSize",          "Unit"="'U'",  "Cmt"="'/* ReadPageSize         */'  "!]
            [!CALL "PrintAlign", "Tabs"="3", "Str"="$WritePageBurstSize",         "Unit"="'U'",  "Cmt"="'/* WritePageSize        */'  ","Comma"="''"!]
        },
        [!CALL "PrintAlign", "Tabs"="2", "Str"="$MemHwResource",         "Unit"="''",   "Cmt"="'/* MemHwResource        */'  "!]
        [!CALL "PrintAlign", "Tabs"="2", "Str"="$Hw_Id",                 "Unit"="''",   "Cmt"="'/* MemoryDriverHwId     */'  ","Comma"="''"!]
    }[!IF "$LoopIt != 0"!],[!ENDIF!][!CR!][!//
    [!ENDLOOP!]
};

[!ENDLOOP!][!//


/* Configuration of address areas */
static const MemAcc_AddressAreaType [!"$MemAccConfigName"!]_AddressAreas[[!"$AddressAreaCount"!]] =
{
[!VAR "LoopIt" = "count(MemAccAddressAreaConfiguration/*)"!]
[!LOOP "node:order(MemAccAddressAreaConfiguration/*, '65535 - node:value(./MemAccAddressAreaPriority)')"!][!// Iterate through the priority value (0 = lowest, 65535 = highest)
    [!VAR "LoopIt"             = "$LoopIt - 1"!]
    [!VAR "AreaId"             = "./MemAccAddressAreaId"!]
    [!VAR "Priority"           = "./MemAccAddressAreaPriority"!]
    [!VAR "BufferAlignment"    = "./MemAccBufferAlignmentValue"!]
    [!VAR "JobEndNotif"        = "./MemAccJobEndNotificationName"!]
    [!VAR "SubAreaCount"       = "num:i( count(./MemAccSubAddressAreaConfiguration/*) )"!]
    [!VAR "SubAreas"           = "concat($MemAccConfigName, '_', node:name(.), '_SubAreas')"!]
    [!VAR "LastSubArea"        = "node:path(./MemAccSubAddressAreaConfiguration/*[number($SubAreaCount)])"!]
    [!VAR "StartAddress"       = "node:ref($LastSubArea)/MemAccLogicalStartAddress"!]
    [!VAR "NumberOfSectors"    = "node:ref($LastSubArea)/MemAccNumberOfSectors"!]
    [!VAR "SectorSize"         = "node:ref( node:ref($LastSubArea)/MemAccSectorBatchRef )/MemEraseSectorSize"!]
    [!VAR "AreaLength"         = "num:i($StartAddress + $NumberOfSectors * $SectorSize)"!]
    {
        /* [!"node:name(.)"!] */
        [!CALL "PrintAlign", "Tabs"="2", "Str"="$AreaId",           "Unit"="'U'",  "Cmt"="'/* AreaId          */'  "!]
        [!CALL "PrintAlign", "Tabs"="2", "Str"="$AreaLength",       "Unit"="'U'",  "Cmt"="'/* Length          */'  "!]
        [!CALL "PrintAlign", "Tabs"="2", "Str"="$Priority",         "Unit"="'U'",  "Cmt"="'/* Priority        */'  "!]
        [!CALL "PrintAlign", "Tabs"="2", "Str"="$BufferAlignment",  "Unit"="'U'",  "Cmt"="'/* BufferAlignment */'  "!]
        [!CALL "PrintAlign", "Tabs"="2", "Str"="$JobEndNotif",      "Unit"="''",   "Cmt"="'/* JobEndNotif     */'  "!]
        [!CALL "PrintAlign", "Tabs"="2", "Str"="$SubAreaCount",     "Unit"="'U'",  "Cmt"="'/* SubAreaCount    */'  "!]
        [!CALL "PrintAlign", "Tabs"="2", "Str"="$SubAreas",         "Unit"="''",   "Cmt"="'/* SubAreas        */'  ","Comma"="''"!]
    }[!IF "$LoopIt != 0"!],[!ENDIF!][!CR!][!//
[!ENDLOOP!]
};


/* Configuration of MemAcc */
const MemAcc_ConfigType [!"$MemAccConfigName"!]_Config =
{
    [!VAR "AddressAreas"      = "concat($MemAccConfigName, '_AddressAreas')"!]
    [!VAR "JobRuntimeInfo"    = "concat($MemAccConfigName, '_JobRuntimeInfo')"!]
    [!VAR "MemApis"           = "concat($MemAccConfigName, '_MemApis')"!]
    [!VAR "MemInvocation"     = "concat($MemAccConfigName, '_MemInvocation')"!]
    [!CALL "PrintAlign", "Str"="$AddressAreaCount",  "Unit"="'U'",  "Cmt"="'/* AddressAreaCount */'  "!]
    [!CALL "PrintAlign", "Str"="$AddressAreas",      "Unit"="''",   "Cmt"="'/* AddressAreas     */'  "!]
    [!CALL "PrintAlign", "Str"="$JobRuntimeInfo",    "Unit"="''",   "Cmt"="'/* JobRuntimeInfo   */'  "!]
    [!CALL "PrintAlign", "Str"="$MemDriverCount",    "Unit"="'U'",  "Cmt"="'/* MemApiCount      */'  "!]
    [!CALL "PrintAlign", "Str"="$MemApis",           "Unit"="''",   "Cmt"="'/* MemApis          */'  "!]
    [!CALL "PrintAlign", "Str"="$MemInvocation",     "Unit"="''",   "Cmt"="'/* MemInvocation    */'  ","Comma"="''"!]
};

#define MEMACC_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "MemAcc_MemMap.h"


/*==================================================================================================
                                           CONSTANTS
==================================================================================================*/


#ifdef __cplusplus
}
#endif

/** @}*/
[!ENDCODE!][!//