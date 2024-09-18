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
* (c) Copyright 2020 - 2023 NXP Semiconductors
* All Rights Reserved.
*
* NXP Confidential. This software is owned or controlled by NXP and may only be
* used strictly in accordance with the applicable license terms. By expressly
* accepting such terms or by downloading, installing, activating and/or otherwise
* using the software, you are agreeing that you have read, and that you agree to
* comply with and are bound by, such license terms. If you do not agree to be
* bound by the applicable license terms, then you may not retain, install,
* activate or otherwise use the software.
==================================================================================================*/

/**
*   @file
*
*   @addtogroup FEE
*   @{
*/
/*   @implements Fee_Cfg.c_Artifact*/
#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
                                         INCLUDE FILES
 1) system and project includes
 2) needed interfaces from external units
 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Fee.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define FEE_VENDOR_ID_CFG_C                      43
#define FEE_AR_RELEASE_MAJOR_VERSION_CFG_C       4
#define FEE_AR_RELEASE_MINOR_VERSION_CFG_C       7
#define FEE_AR_RELEASE_REVISION_VERSION_CFG_C    0
#define FEE_SW_MAJOR_VERSION_CFG_C               3
#define FEE_SW_MINOR_VERSION_CFG_C               0
#define FEE_SW_PATCH_VERSION_CFG_C               0

/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/
/* Check if source file and Fee header file are of the same vendor */
#if (FEE_VENDOR_ID_CFG_C != FEE_VENDOR_ID)
    #error "Fee_Cfg.c and Fee.h have different vendor ids"
#endif
/* Check if current file and Fee header file are of the same Autosar version */
#if ((FEE_AR_RELEASE_MAJOR_VERSION_CFG_C    != FEE_AR_RELEASE_MAJOR_VERSION) || \
     (FEE_AR_RELEASE_MINOR_VERSION_CFG_C    != FEE_AR_RELEASE_MINOR_VERSION) || \
     (FEE_AR_RELEASE_REVISION_VERSION_CFG_C != FEE_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Fee_Cfg.c and Fee.h are different"
#endif
/* Check if current file and Fee header file are of the same Software version */
#if ((FEE_SW_MAJOR_VERSION_CFG_C != FEE_SW_MAJOR_VERSION) || \
     (FEE_SW_MINOR_VERSION_CFG_C != FEE_SW_MINOR_VERSION) || \
     (FEE_SW_PATCH_VERSION_CFG_C != FEE_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Fee_Cfg.c and Fee.h are different"
#endif

[!INCLUDE "Fee_VersionCheck.m"!][!//


/*==================================================================================================
                                       GLOBAL VARIABLES
==================================================================================================*/
[!VAR "FeeVPS" = "num:i(FeeGeneral/FeeVirtualPageSize)"!]
[!VAR "FeeBlkOverhead" = "num:i(ceiling(12 div $FeeVPS + 2) * $FeeVPS)"!]
[!VAR "FeeClsOverhead" = "num:i(ceiling(16 div $FeeVPS + 2) * $FeeVPS)"!]
[!//
[!// Reserve 1-byte for BlockAssignment
[!VAR "FeeBlkFirstPartSize" = "$FeeBlkOverhead - ($FeeVPS * 2)"!][!//
[!IF "$FeeBlkFirstPartSize < 13"!][!// 2-byte block number + 2-byte block size + 4-byte block address + 4-byte checksum + 1-byte block assignment
    [!VAR "FeeBlkOverhead" = "num:i($FeeBlkOverhead + 13 - $FeeBlkFirstPartSize)"!]
[!ENDIF!][!//
[!//

#define FEE_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Fee_MemMap.h"

[!VAR "FeeClusterStartAddress" = "0"!]
[!VAR "FeeEmulationAddress" = "0"!]
[!LOOP "FeeClusterGroup/*"!]
[!VAR "FeeCluterGrName" = "node:name(.)"!]

/* Configuration of cluster group [!"$FeeCluterGrName"!] */
static const Fee_ClusterType Fee_[!"node:name(.)"!][[!"num:i(count(FeeCluster/*))"!]] =
{
    [!VAR "FeeLoopIt" = "count(FeeCluster/*)"!]
    [!VAR "comma" = "' '"!]
    [!LOOP "FeeCluster/*"!]
    {
        [!VAR "comma" = "','"!]
    [!VAR "SubAreaCount"       = "num:i( count(node:ref(FeeMemAccAddressAreaRef)/MemAccSubAddressAreaConfiguration/*) )"!]
    [!VAR "LastSubArea"        = "node:path(node:ref(FeeMemAccAddressAreaRef)/MemAccSubAddressAreaConfiguration/*[number($SubAreaCount)])"!]
    [!VAR "NumberOfSectors"    = "node:ref($LastSubArea)/MemAccNumberOfSectors"!]
    [!VAR "StartAddress"       = "node:ref($LastSubArea)/MemAccLogicalStartAddress"!]
    [!VAR "SectorSize"         = "node:ref( node:ref($LastSubArea)/MemAccSectorBatchRef )/MemEraseSectorSize"!]
    [!VAR "AreaLength"         = "num:i($StartAddress + $NumberOfSectors * $SectorSize)"!]
        [!"num:i(node:ref(FeeMemAccAddressAreaRef)/MemAccAddressAreaId)"!]U[!"$comma"!] /* Address Aread Id so cluster belongs to */
        0U, /* start address of cluster */
        [!"num:i($AreaLength)"!]U /* Size */
    }[!IF "$FeeLoopIt != 0"!],[!ENDIF!][!CR!][!//
    [!ENDLOOP!]
};
[!ENDLOOP!]

/* Configuration of cluster group set */
const Fee_ClusterGroupType Fee_ClrGrps[FEE_NUMBER_OF_CLUSTER_GROUPS] =
{
[!VAR "FeeLoopIt" = "count(FeeClusterGroup/*)"!]
[!LOOP "FeeClusterGroup/*"!]
    [!VAR "FeeLoopIt" = "$FeeLoopIt - 1"!]
    [!// Compute the size of the reserved area (immediate block headers and aligned data)
    [!VAR "FeeReservedSize" = "0"!][!//
    [!LOOP "../../FeeBlockConfiguration/*[node:name(node:ref(FeeClusterGroupRef)) = node:current()/@name]"!]
        [!IF "./FeeImmediateData"!]
            [!VAR "FeeReservedSize" = "$FeeReservedSize + $FeeBlkOverhead + [!//
                             num:i( ceiling( ./FeeBlockSize div $FeeVPS ) * $FeeVPS )"!]
        [!ENDIF!]
    [!ENDLOOP!]     
    /* [!"node:name(.)"!] */
    {
        Fee_[!"node:name(.)"!], /* Cluster set */
        [!"num:i(count(./FeeCluster/*))"!]U, /* Number of clusters */
        [!"num:i( $FeeReservedSize )"!]U /* Size of the reserved area */
    }[!IF "$FeeLoopIt != 0"!],[!ENDIF!][!//

[!ENDLOOP!]
};

/* Configuration of Fee blocks */
const Fee_BlockConfigType Fee_BlockConfig[FEE_CRT_CFG_NR_OF_BLOCKS] =
{
[!VAR "FeeLoopIt" = "count(FeeBlockConfiguration/*)"!]
[!LOOP "node:order(FeeBlockConfiguration/*,'node:value(./FeeBlockNumber)')"!]
    [!VAR "FeeLoopIt" = "$FeeLoopIt - 1"!]
    /* [!"node:name(.)"!] */
    {
        FeeConf_FeeBlockConfiguration_[!"node:name(.)"!], /* FeeBlockNumber symbol */
        [!"./FeeBlockSize"!]U, /* FeeBlockSize */
        [!"node:ref(./FeeClusterGroupRef)/@index"!]U, /* FeeClusterGroup */
        (boolean) [!IF "./FeeImmediateData"!]TRUE [!ELSE!]FALSE[!ENDIF!],[!//
   /* FeeImmediateData */
#if (FEE_SWAP_FOREIGN_BLOCKS_ENABLED == STD_ON) 
        FEE_PROJECT_[!"node:value(./FeeBlockAssignment)"!] /* Fee Block Assignment to a project */
#else
        FEE_PROJECT_RESERVED
#endif
    }[!IF "$FeeLoopIt != 0"!],[!ENDIF!][!//

[!ENDLOOP!]
};
[!ENDCODE!]

#define FEE_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Fee_MemMap.h"

#ifdef __cplusplus
}
#endif
/** @}*/
