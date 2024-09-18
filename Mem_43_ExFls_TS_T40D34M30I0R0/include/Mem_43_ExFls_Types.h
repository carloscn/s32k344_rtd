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

#ifndef MEM_43_EXFLS_TYPES_H
#define MEM_43_EXFLS_TYPES_H

/**
*   @file Mem_43_ExFlsTypes.h
*
*   @addtogroup MEM_43_EXFLS Driver
*   @{
*/

/* implements Mem_43_ExFls_Types.h_Artifact */

#ifdef __cplusplus
extern "C"{
#endif


/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "StandardTypes.h"
#include "Mem_43_ExFls_CfgDefines.h"
#include "Qspi_Ip_Types.h"


/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define MEM_43_EXFLS_TYPES_VENDOR_ID                      43
#define MEM_43_EXFLS_TYPES_AR_RELEASE_MAJOR_VERSION       4
#define MEM_43_EXFLS_TYPES_AR_RELEASE_MINOR_VERSION       7
#define MEM_43_EXFLS_TYPES_AR_RELEASE_REVISION_VERSION    0
#define MEM_43_EXFLS_TYPES_SW_MAJOR_VERSION               3
#define MEM_43_EXFLS_TYPES_SW_MINOR_VERSION               0
#define MEM_43_EXFLS_TYPES_SW_PATCH_VERSION               0


/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/


/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/

/* Job flags */
#define MEM_43_EXFLS_JOB_FLAG_NONE                        0x00U     /* Initial value                               */
#define MEM_43_EXFLS_JOB_FLAG_STARTED                     0x01U     /* Indicates that new job has been accepted    */


/*==================================================================================================
                                             TYPEDEFS
==================================================================================================*/

/**
* @brief          Mem Address Type
* @details        Physical memory device address type
* @implements     Mem_43_ExFls_AddressType_typedef
*/
typedef uint32 Mem_43_ExFls_AddressType;


/**
* @brief          Mem Instance Id Type
* @details        Mem Instance Id Type
* @implements     Mem_43_ExFls_InstanceIdType_typedef
*/
typedef uint32 Mem_43_ExFls_InstanceIdType;


/**
* @brief          Mem Length Type
* @details        Physical memory device length type
* @implements     Mem_43_ExFls_LengthType_typedef
*/
typedef uint32 Mem_43_ExFls_LengthType;


/**
* @brief          Mem Data Type
* @details        Read data user buffer type
* @implements     Mem_43_ExFls_DataType_typedef
*/
typedef uint8 Mem_43_ExFls_DataType;


/**
* @brief          Mem CRC Type
* @details        CRC computed over config set
*/
typedef uint16 Mem_43_ExFls_CrcType;


/**
* @brief          Mem Hardware Service Id Type
* @details        Hardware specific service request identifier type
* @implements     Mem_43_ExFls_HwServiceIdType_typedef
*/
typedef uint32 Mem_43_ExFls_HwServiceIdType;


/*==================================================================================================
                                             ENUMS
==================================================================================================*/

/**
* @brief          Mem job result type
* @implements     Mem_43_ExFlsJobResultType_enumeration
*/
typedef enum
{
    MEM_43_EXFLS_JOB_OK                 = 0x00,    /* The last job has been finished successfully                                    */
    MEM_43_EXFLS_JOB_PENDING            = 0x01,    /* A job is currently being processed                                             */
    MEM_43_EXFLS_JOB_FAILED             = 0x02,    /* Job failed for some unspecific reason                                          */
    MEM_43_EXFLS_JOB_INCONSISTENT       = 0x03,    /* The checked page is not blank                                                  */
    MEM_43_EXFLS_JOB_ECC_UNCORRECTED    = 0x04,    /* Uncorrectable ECC errors occurred during memory access                         */
    MEM_43_EXFLS_JOB_ECC_CORRECTED      = 0x05     /* Correctable ECC errors occurred during memory access                           */
} Mem_43_ExFls_JobResultType;


/**
* @brief          Type of job currently executed by Mem_43_ExFls_MainFunction.
*/
typedef enum
{
    MEM_43_EXFLS_JOB_NONE               = 0x00,    /* no job executed                                                                */
    MEM_43_EXFLS_JOB_ERASE              = 0x01,    /* erase one or more complete flash sectors                                       */
    MEM_43_EXFLS_JOB_WRITE              = 0x02,    /* write one or more complete flash pages                                         */
    MEM_43_EXFLS_JOB_READ               = 0x03,    /* read one or more bytes from flash memory                                       */
    MEM_43_EXFLS_JOB_COMPARE            = 0x04,    /* compare data buffer with content of flash memory                               */
    MEM_43_EXFLS_JOB_BLANK_CHECK        = 0x05     /* check content of erased flash memory area                                      */
} Mem_43_ExFls_JobType;


/*==================================================================================================
                                        CONFIGURATION STRUCTURES
==================================================================================================*/

typedef struct
{
    const uint32                          HardwareInstance;            /* Hardware instance number                                 */
    const Qspi_Ip_ControllerConfigType   *Config;                      /* Hardware configuration                                   */
} Mem_43_ExFls_QspiUnitType;


typedef struct
{
    const Qspi_Ip_MemoryConnectionType   *Connect;                     /* Connection for each external memory device               */
    const Qspi_Ip_MemoryConfigType       *Config;                      /* External memory devices configuration                    */
    boolean                               AHBRead;                     /* AHB direct reads configuration                           */
} Mem_43_ExFls_MemoryUnitType;


/**
* @brief          Mem device config type
* @details        Mem device config data structure
*/
typedef struct
{
    /**
    * @brief QSPI unit configurations (size = MEM_EXFLS_QSPI_UNIT_COUNT)
    */
    const Mem_43_ExFls_QspiUnitType      *QspiUnits;         /* Point to first element in array of QSPI unit configurations          */
    /**
    * @brief Flash memory unit configurations (size = MEM_EXFLS_MEM_UNIT_COUNT)
    *        Each "MemUnit" = a pair of "MemConnection" + "MemCfg"
    */
    const Mem_43_ExFls_MemoryUnitType    *MemUnits;          /* Point to first element in array of Flash memory unit configurations  */
} Mem_43_ExFls_MemDeviceType;


/**
* @brief          Sector Batch Type
* @details        Sector Batch data structure for group of identical sectors
*                 Note: burst sizes equal to normal sizes in case burst disabled
*/
typedef struct
{
    const Mem_43_ExFls_AddressType    StartAddress;       /* Physical start address of the sector batch                              */
    const Mem_43_ExFls_AddressType    EndAddress;         /* Physical end address of the sector batch                                */
    const uint32                   SectorSize;         /* Size of a sector in bytes in this sector batch (smallest erasable unit) */
    const uint32                   ReadPageSize;       /* Size of a read page of this sector in bytes (smallest readable unit)    */
    const uint32                   WritePageSize;      /* Size of a write page of this sector in bytes (smallest writeable unit)  */
    const uint32                   EraseBurstSize;     /* Size of sector erase burst in bytes (for improved performance)          */
    const uint32                   ReadBurstSize;      /* Size of page read burst in bytes (for improved performance)             */
    const uint32                   WriteBurstSize;     /* Size of page write/program burst in bytes (for improved performance)    */
} Mem_43_ExFls_SectorBatchType;


/**
* @brief          Mem Instance Type
* @details        Mem Instance data structure
*/
typedef struct
{
    const Mem_43_ExFls_InstanceIdType     InstanceId;          /* Unique numeric identifier for each a Mem driver instance           */
    const uint32                       SectorBatchCount;    /* Number of sector batches in this Mem instance                      */
    const Mem_43_ExFls_SectorBatchType   *SectorBatches;       /* Point to first element in array of sector batches configurations   */
    const uint8                        MemUnitIndex;        /* Index of flash memory unit used for this Mem instance              */
} Mem_43_ExFls_MemInstanceType;


/**
* @brief          Mem Configuration Type
* @details        Mem module initialization data structure
* @implements     Mem_43_ExFls_ConfigType_typedef
*/
typedef struct
{
    const Mem_43_ExFls_MemInstanceType   *MemInstances;        /* Point to first element in array of mem instances configurations    */
    const Mem_43_ExFls_MemDeviceType     *MemDevices;          /* Mem devices configurations used by the mem instance                */
} Mem_43_ExFls_ConfigType;


/*==================================================================================================
                                        INTERNAL TYPES
==================================================================================================*/

/**
* @brief          Mem job runtime information Type
* @details        This structure contains runtime information the current processing job of each Mem instance.
*/
typedef struct
{
    /* Input information */
    Mem_43_ExFls_InstanceIdType            InstanceId;         /* Unique numeric identifier for each a Mem driver instance           */
    Mem_43_ExFls_JobType                   JobType;            /* Type of currently executed job (Erase, Write, or Read)             */
    Mem_43_ExFls_AddressType               Address;            /* Last physical address to be processed                              */
    Mem_43_ExFls_DataType                 *DataPtr;            /* Pointer to user data buffer (used in Read and Write)               */
    Mem_43_ExFls_LengthType                Length;             /* Remaining bytes of data to be processed                            */
    /* Output result of the parameter checking stage */
    uint32                              InstanceIndex;      /* The mem index number according to the mem instance id              */
    const Mem_43_ExFls_SectorBatchType    *SectorBatch;        /* The sector batch to be worked with the request job                 */
    /* Runtime information */
    Mem_43_ExFls_JobResultType             JobResult;          /* The result of the most recent job                                  */
    uint8                               JobFlags;           /* Job information (Started state, burst mode)                        */
} Mem_43_ExFls_JobRuntimeInfoType;


#ifdef __cplusplus
}
#endif

/** @}*/

#endif /* MEM_43_EXFLS_TYPES_H */
