[!AUTOSPACING!]
[!CODE!]
/*==================================================================================================
* Project              : RTD AUTOSAR 4.7
* Platform             : CORTEXM
* Peripheral           : none
* Dependencies         : MemAcc
*
* Autosar Version      : 4.7.0
* Autosar Revision     : ASR_REL_4_7_REV_0000
* Autosar Conf.Variant :
* SW Version           : 3.0.0
* Build Version        : S32K3_RTD_3_0_0_D2303_ASR_REL_4_7_REV_0000_20230331
*
* Copyright 2020 - 2023 NXP Semiconductors
*
* NXP Confidential. This software is owned or controlled by NXP and may only be
* used strictly in accordance with the applicable license terms. By expressly
* accepting such terms or by downloading, installing, activating and/or otherwise
* using the software, you are agreeing that you have read, and that you agree to
* comply with and are bound by, such license terms. If you do not agree to be
* bound by the applicable license terms, then you may not retain, install,
* activate or otherwise use the software.
==================================================================================================*/

#ifndef FEE_CFG_H
#define FEE_CFG_H

/**
*   @file
*
*   @addtogroup FEE
*   @{
*/
/*   @implements Fee_Cfg.h_Artifact*/
#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
                                         INCLUDE FILES
 1) system and project includes
 2) needed interfaces from external units
 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Fee_Types.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/

#define FEE_VENDOR_ID_CFG                    43
#define FEE_AR_RELEASE_MAJOR_VERSION_CFG     4
#define FEE_AR_RELEASE_MINOR_VERSION_CFG     7
#define FEE_AR_RELEASE_REVISION_VERSION_CFG  0
#define FEE_SW_MAJOR_VERSION_CFG             3
#define FEE_SW_MINOR_VERSION_CFG             0
#define FEE_SW_PATCH_VERSION_CFG             0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and MODULENAME configuration header file are of the same vendor */
#if (FEE_VENDOR_ID_CFG != FEE_TYPES_VENDOR_ID)
    #error "Fee_Types.h and Fee_Cfg.h have different vendor ids"
#endif
/* Check if current file and MODULENAME configuration header file are
   of the same Autosar version
*/
#if ((FEE_AR_RELEASE_MAJOR_VERSION_CFG    != FEE_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (FEE_AR_RELEASE_MINOR_VERSION_CFG    != FEE_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (FEE_AR_RELEASE_REVISION_VERSION_CFG != FEE_TYPES_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Fee_Types.h and Fee_Cfg.h are different"
#endif
/* Check if current file and MODULENAME configuration header file are
   of the same software version
*/
#if ((FEE_SW_MAJOR_VERSION_CFG != FEE_TYPES_SW_MAJOR_VERSION) || \
     (FEE_SW_MINOR_VERSION_CFG != FEE_TYPES_SW_MINOR_VERSION) || \
     (FEE_SW_PATCH_VERSION_CFG != FEE_TYPES_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Fee_Types.h and Fee_Cfg.h are different"
#endif
[!VAR "NvmEndFlg" = "0"!]
[!IF "node:exists(FeeGeneral/FeeNvmJobEndNotification)"!]
    [!IF "not(text:match(normalize-space(FeeGeneral/FeeNvmJobEndNotification),'^[_a-zA-Z][_0-9a-zA-Z]*$'))"!]
        [!ERROR!]Invalid name of the Fee Nvm Job End Notification routine. Must be a valid C function name, NULL_PTR or NULL.[!ENDERROR!]
    [!ELSE!]
        [!VAR "NvmEndFlg" = "node:when((normalize-space(FeeGeneral/FeeNvmJobEndNotification) = 'NULL_PTR') or (normalize-space(FeeGeneral/FeeNvmJobEndNotification) = 'NULL'),0,1)"!]
    [!ENDIF!]
[!ENDIF!]
[!VAR "NvmErrFlg" = "0"!]
[!IF "node:exists(FeeGeneral/FeeNvmJobErrorNotification)"!]
    [!IF "not(text:match(normalize-space(FeeGeneral/FeeNvmJobErrorNotification),'^[_a-zA-Z][_0-9a-zA-Z]*$'))"!]
        [!ERROR!]Invalid name of the Fee Nvm Job Error Notification routine. Must be a valid C function name, NULL_PTR or NULL.[!ENDERROR!]
    [!ELSE!]
        [!VAR "NvmErrFlg" = "node:when((normalize-space(FeeGeneral/FeeNvmJobErrorNotification) = 'NULL_PTR') or (normalize-space(FeeGeneral/FeeNvmJobErrorNotification) = 'NULL'),0,1)"!]
    [!ENDIF!]
[!ENDIF!]
[!VAR "NvmClusterFormatFlg" = "0"!]
[!IF "node:exists(FeeGeneral/FeeClusterFormatNotification)"!]
    [!IF "not(text:match(normalize-space(FeeGeneral/FeeClusterFormatNotification),'^[_a-zA-Z][_0-9a-zA-Z]*$'))"!]
        [!ERROR!]Invalid name of the Fee Cluster Format During Init Notification routine. Must be a valid C function name, NULL_PTR or NULL.[!ENDERROR!]
    [!ELSE!]
        [!VAR "NvmClusterFormatFlg" = "node:when((normalize-space(FeeGeneral/FeeClusterFormatNotification) = 'NULL_PTR') or (normalize-space(FeeGeneral/FeeClusterFormatNotification) = 'NULL'),0,1)"!]
    [!ENDIF!]
[!ENDIF!]

[!INCLUDE "Fee_VersionCheck.m"!][!//

/*==================================================================================================
                                       DEFINES AND MACROS
==================================================================================================*/
[!VAR "FeeVPS" = "num:i(FeeGeneral/FeeVirtualPageSize)"!]
[!VAR "FeeMinReadPageSize" = "num:i(FeeGeneral/FeeMinimumReadPageSize)"!]
[!VAR "FeeBlkOverhead" = "num:i(ceiling(12 div $FeeVPS + 2) * $FeeVPS)"!]
[!VAR "FeeClsOverhead" = "num:i(ceiling(16 div $FeeVPS + 2) * $FeeVPS)"!]
[!VAR "FeeDataBufferSize" = "num:i(FeeGeneral/FeeDataBufferSize)"!]
[!//
[!// Reserve 1-byte for BlockAssignment
[!VAR "FeeBlkFirstPartSize" = "$FeeBlkOverhead - ($FeeVPS * 2)"!][!//
[!IF "$FeeBlkFirstPartSize < 13"!][!// 2-byte block number + 2-byte block size + 4-byte block address + 4-byte checksum + 1-byte block assignment
    [!VAR "FeeBlkOverhead" = "num:i($FeeBlkOverhead + 13 - $FeeBlkFirstPartSize)"!]
[!ENDIF!][!//
[!//
/* Pre-processor switch to enable and disable development error detection */
/** @implements   FeeDevErrorDetect_Object */
#define FEE_DEV_ERROR_DETECT                      ([!IF "FeeGeneral/FeeDevErrorDetect"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

/* Pre-processor switch to enable / disable the API to read out the modules
    version information */
/** @implements   FeeVersionInfoApi_Object */
#define FEE_VERSION_INFO_API                      ([!IF "FeeGeneral/FeeVersionInfoApi"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])
/* The size in bytes to which logical blocks shall be aligned */
/** @implements   FeeVirtualPageSize_Object */
#define FEE_VIRTUAL_PAGE_SIZE                     ([!"$FeeVPS"!]U)

/* Minimum Page size will be a multiple of the minimum page size. Fee shallalign read requests to this size */
/** @implements   FeeMinimumReadPageSize_Object */
#define FEE_MINIMUM_READ_PAGE_SIZE                            ([!"$FeeMinReadPageSize"!]U)

[!VAR "BiggestBufferAlignValue" = "0"!]
[!LOOP "as:modconf('MemAcc')[1]/MemAccAddressAreaConfiguration/*"!][!// Iterate through the index value
    [!VAR "BufferAlignValue"     = "node:value(./MemAccBufferAlignmentValue)"!]
    [!IF "$BiggestBufferAlignValue < $BufferAlignValue"!]
        [!VAR "BiggestBufferAlignValue" = "$BufferAlignValue"!]
    [!ENDIF!]
[!ENDLOOP!]
[!IF "num:i(num:mod(num:i(node:ref(FeeGeneral/FeeBufferAlignmentValue)/MemAccBufferAlignmentValue), num:i($BiggestBufferAlignValue))) != '0'"!]
    [!ERROR!]
            The FeeBufferAlignmentValue value must be inherited from the maximum size of MemAccBufferAlignmentValue.
    [!ENDERROR!]
[!ELSE!]
/* Parameter determines the alignment of the start address that Fee buffers need to have */
/** @implements   FeeBufferAlignmentValue_Object */
#define FEE_BUFFER_ALIGN_VALUE                            ([!"num:i(node:ref(FeeGeneral/FeeBufferAlignmentValue)/MemAccBufferAlignmentValue)"!]U)
[!ENDIF!]

/* Job end notification routine provided by the upper layer module (declaration) */
/** @implements   FeeNvmJobEndNotification_Object */

#define FEE_NVM_JOB_END_NOTIFICATION_DECL         [!//
[!IF "$NvmEndFlg = '1.0'"!]extern void [!"normalize-space(FeeGeneral/FeeNvmJobEndNotification)"!](void);[!ENDIF!]

/* Job end notification routine provided by the upper layer module */
/** @implements   FeeNvmJobEndNotification_Object */

#define FEE_NVM_JOB_END_NOTIFICATION              [!//
[!IF "$NvmEndFlg = '1.0'"!][!"normalize-space(FeeGeneral/FeeNvmJobEndNotification)"!]();[!ENDIF!]

/* Job error notification routine provided by the upper layer module (declaration) */
/** @implements   FeeNvmJobErrorNotification_Object */

#define FEE_NVM_JOB_ERROR_NOTIFICATION_DECL       [!//
[!IF "$NvmErrFlg = '1.0'"!]extern void [!"normalize-space(FeeGeneral/FeeNvmJobErrorNotification)"!](void);[!ENDIF!]

/* Job error notification routine provided by the upper layer module */
/** @implements   FeeNvmJobErrorNotification_Object */

#define FEE_NVM_JOB_ERROR_NOTIFICATION            [!//
[!IF "$NvmErrFlg = '1.0'"!][!"normalize-space(FeeGeneral/FeeNvmJobErrorNotification)"!]();[!ENDIF!]

/* Job cluster format notification routine provided by the upper layer module (declaration) */
#define FEE_NVM_CLUSTER_FORMAT_NOTIFICATION_DECL  [!//
[!IF "$NvmClusterFormatFlg = '1.0'"!]extern void [!"normalize-space(FeeGeneral/FeeClusterFormatNotification)"!](void);[!ENDIF!]

/* Job cluster format notification routine provided by the upper layer module */
#define FEE_NVM_CLUSTER_FORMAT_NOTIFICATION       [!//
[!IF "$NvmClusterFormatFlg = '1.0'"!][!"normalize-space(FeeGeneral/FeeClusterFormatNotification)"!]();[!ENDIF!]

/* Number of configured Fee cluster groups */
#define FEE_NUMBER_OF_CLUSTER_GROUPS              ([!"num:i(count(FeeClusterGroup/*))"!]U)

/* Number of configured Fee blocks */
#define FEE_CRT_CFG_NR_OF_BLOCKS                  ([!"num:i(count(FeeBlockConfiguration/*))"!]U)

/* Maximum number of Fee blocks in all project versions and configurations */
#define FEE_MAX_NR_OF_BLOCKS                      ([!//
[!IF "FeeGeneral/FeeSwapForeignBlocksEnabled"!][!"node:value(FeeGeneral/FeeMaximumNumberBlocks)"!]U[!ELSE!](FEE_CRT_CFG_NR_OF_BLOCKS)[!ENDIF!])

/* Management overhead per logical block in bytes */
/** @implements   FeeBlockOverhead_Object */
#define FEE_BLOCK_OVERHEAD                        ([!"$FeeBlkOverhead"!]U)

/* Management overhead per logical cluster in bytes */
#define FEE_CLUSTER_OVERHEAD                      ([!"$FeeClsOverhead"!]U)

/* Size of the data buffer in bytes */
#define FEE_DATA_BUFFER_SIZE                      ([!"$FeeDataBufferSize"!]U)

/* The contents of an erased flash memory cell */
#define FEE_ERASED_VALUE                          ([!"num:inttohex(bit:and(4294967295,255),2)"!]U)

/* Value of the block and cluster validation flag */
#define FEE_VALIDATED_VALUE                       ([!"num:inttohex(bit:and(bit:xor(4294967295,126),255),2)"!]U)

/* Value of the block and cluster invalidation flag */
#define FEE_INVALIDATED_VALUE                     ([!"num:inttohex(bit:and(bit:xor(4294967295,231),255),2)"!]U)

/* If reset, power loss etc. occurs here, neither newly nor previously written data is available */
#define FEE_BLOCK_ALWAYS_AVAILABLE                ([!IF "FeeGeneral/FeeBlockAlwaysAvailable"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

/* Behavior of Fee_ImmediateBlockErase */
#define FEE_LEGACY_IMM_ERASE_MODE                 ([!IF "FeeGeneral/FeeLegacyEraseMode"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

/* This configuration defines wheather Fee should swap foreign blocks found in flash at swap or not */
#define FEE_SWAP_FOREIGN_BLOCKS_ENABLED           ([!IF "FeeGeneral/FeeSwapForeignBlocksEnabled"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

#if (FEE_SWAP_FOREIGN_BLOCKS_ENABLED == STD_ON)
/* This configuration defines for which project the Fee configuration is used  */
#define FEE_BOOTLOADER_CONFIG                     ([!IF "FeeGeneral/FeeConfigAssignment='BOOTLOADER'"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])
#endif
/* This configuration defines if the status for the never written blocks must be INVALID or INCONSISTENT */
#define FEE_MARK_EMPTY_BLOCKS_INVALID             ([!IF "FeeGeneral/FeeMarkEmptyBlocksInvalid"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

/* Symbolic names of configured Fee blocks */
[!LOOP "node:order(FeeBlockConfiguration/*,'node:value(./FeeBlockNumber)')"!]
#define FeeConf_FeeBlockConfiguration_[!"node:name(.)"!]     ([!"./FeeBlockNumber"!]U)
[!ENDLOOP!]
[!NOCODE!]
[!VAR "FeeVirtualPageSize" = "FeeGeneral/FeeVirtualPageSize"!]
[!IF "$FeeVirtualPageSize < 16"!]
    [!VAR "FeeVirtualPageSize" = "16"!]
[!ENDIF!]

[!ENDNOCODE!]
#define FEE_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Fee_MemMap.h"
[!NOCODE!]
[!VAR "MemBiggestPageSize" = "0"!]
[!VAR "BiggestMinimumReadPageSize" = "0"!]
[!LOOP "FeeClusterGroup/*"!]
    [!VAR "FeeSmallestClusterSize" = "2147483647"!]
    [!VAR "FeeLoopIt" = "count(FeeCluster/*)"!]
    [!VAR "FeeReservedSize" = "0"!]
    [!LOOP "FeeCluster/*"!]
        [!VAR "FeeClusterSize" = "0"!]
        [!VAR "SubAreaCount"       = "num:i( count(node:ref(FeeMemAccAddressAreaRef)/MemAccSubAddressAreaConfiguration/*) )"!]
        [!VAR "LastSubArea"        = "node:path(node:ref(FeeMemAccAddressAreaRef)/MemAccSubAddressAreaConfiguration/*[number($SubAreaCount)])"!]
        [!VAR "NumberOfSectors"    = "node:ref($LastSubArea)/MemAccNumberOfSectors"!]
        [!VAR "StartAddress"       = "node:ref($LastSubArea)/MemAccLogicalStartAddress"!]
        [!VAR "SectorSize"         = "node:ref( node:ref($LastSubArea)/MemAccSectorBatchRef )/MemEraseSectorSize"!]
        [!// Get the current MemWritePageSize value.
        [!LOOP "node:ref(FeeMemAccAddressAreaRef)/MemAccSubAddressAreaConfiguration/*"!]
            [!VAR "MemCurrentWritePageSize"   = "node:ref(./MemAccSectorBatchRef)/MemWritePageSize"!]
            [!VAR "MemCurrentMinimumReadPageSize"   = "node:ref(./MemAccSectorBatchRef)/MemReadPageSize"!]

            [!// Get the biggest MemWritePageSize value.
            [!IF "$MemBiggestPageSize < $MemCurrentWritePageSize"!]
                [!VAR "MemBiggestPageSize" = "$MemCurrentWritePageSize"!]
                [!// check if FeeVirtualPageSize is not aligned with MemWritePageSize.
                [!IF "num:i(num:mod($FeeVPS,num:i($MemBiggestPageSize))) != '0'"!]
                    [!ERROR!]
                        The FeeVirtualPageSize must be configured to an integer multiple of MemWritePageSize (SectorBatch: [!"node:ref(./MemAccSectorBatchRef)/@name"!]).
                    [!ENDERROR!]
                [!ENDIF!]
            [!ENDIF!]
            [!// Get the biggest MinimumReadPageSize value.
            [!IF "$BiggestMinimumReadPageSize < $MemCurrentMinimumReadPageSize"!]
                [!VAR "BiggestMinimumReadPageSize" = "$MemCurrentMinimumReadPageSize"!]
                [!// check if FeeMinimumReadPageSize is not aligned with MinimumReadPageSize.
                [!IF "num:i(num:mod($FeeMinReadPageSize,num:i($BiggestMinimumReadPageSize))) != '0'"!]
                    [!ERROR!]
The FeeMinimumReadPageSize must be configured to an integer multiple of minimum page size(MemReadPageSize): (SectorBatch: [!"node:ref(./MemAccSectorBatchRef)/@name"!]).
                    [!ENDERROR!]
                [!ENDIF!]
            [!ENDIF!]
        [!ENDLOOP!]
        [!// Calculate total cluster size
        [!VAR "FeeClusterSize" = "num:i($StartAddress + $NumberOfSectors * $SectorSize)"!]
        [!IF "$FeeClusterSize < $FeeSmallestClusterSize"!]
            [!VAR "FeeSmallestClusterSize" = "$FeeClusterSize"!]
        [!ENDIF!]
    [!ENDLOOP!]
    [!// Calculate space remaining of the cluster after writing overhead and adding padding.
    [!VAR "FeeRemainingClusterSpace" = "$FeeSmallestClusterSize - ($FeeClsOverhead + $FeeBlkOverhead)"!]

    [!VAR "FeeBiggestBlockSize" = "0"!]
    [!VAR "FeeBiggestBlockImmediateData" = "'false'"!]

    [!LOOP "../../FeeBlockConfiguration/*[node:name(node:ref(FeeClusterGroupRef)) = node:current()/@name]"!]
        [!// Calculate space remaining of the cluster after writing all blocks at once.
        [!VAR "FeeRemainingClusterSpace" = "$FeeRemainingClusterSpace - num:i(ceiling(./FeeBlockSize div $FeeVPS) * $FeeVPS) - $FeeBlkOverhead"!]
        [!// Find the biggest block.
        [!IF "$FeeBiggestBlockSize < ./FeeBlockSize"!]
            [!VAR "FeeBiggestBlockSize" = "./FeeBlockSize"!]
            [!VAR "FeeBiggestBlockImmediateData" = "./FeeImmediateData"!]
        [!ENDIF!]
        [!// Calculate reserved space when FeeImmediateData is enable.
        [!IF "./FeeImmediateData"!]
            [!VAR "FeeReservedSize" = "$FeeReservedSize + $FeeBlkOverhead + num:i( ceiling( ./FeeBlockSize div $FeeVPS ) * $FeeVPS )"!]
        [!ENDIF!]
    [!ENDLOOP!]

    [!// Calculate space remaining of the cluster after writing the biggest block one more time
    [!IF "FeeBiggestBlockImmediateData = 'false'"!][!// Except for immediate blocks because they have been calculated in the reserved space
        [!VAR "FeeRemainingClusterSpace" = "$FeeRemainingClusterSpace - num:i(ceiling($FeeBiggestBlockSize div $FeeVPS) * $FeeVPS) - $FeeBlkOverhead"!]
    [!ENDIF!]

    [!// Space remaining of the cluster minus reserved space.
    [!VAR "FeeRemainingClusterSpace" = "$FeeRemainingClusterSpace - $FeeReservedSize"!]
    [!// Raise the error when space remaining of the cluster are less than 0.
    [!IF "($FeeRemainingClusterSpace < 0)"!]
        [!ERROR!]
The total size of blocks is too big. They do not fit into the cluster group [!"node:name(.)"!]. Increase the size of the cluster or reduce the size of blocks.
        [!ENDERROR!]
    [!ENDIF!]
[!ENDLOOP!]
[!ENDNOCODE!]
/* Configuration of cluster group set */
extern const Fee_ClusterGroupType Fee_ClrGrps[ FEE_NUMBER_OF_CLUSTER_GROUPS ];

/* Configuration of Fee blocks */
extern const Fee_BlockConfigType Fee_BlockConfig[ FEE_CRT_CFG_NR_OF_BLOCKS ];

#define FEE_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Fee_MemMap.h"
[!ENDCODE!]
#ifdef __cplusplus
}
#endif

/** @} */

#endif /* FEE_CFG_H */