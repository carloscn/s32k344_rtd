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

#ifndef MEM_43_INFLS_TYPES_H
#define MEM_43_INFLS_TYPES_H

/**
 * @file       Mem_43_InFlsTypes.h
 *
 * @addtogroup MEM_43_INFLS
 * implements  Mem_43_InFls_Types.h_Artifact
 *
 * @{
 */

#ifdef __cplusplus
extern "C"
{
#endif

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "StandardTypes.h"
#include "Mem_43_InFls_CfgDefines.h"
#include "C40_Ip_Types.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define MEM_43_INFLS_TYPES_VENDOR_ID                      43
#define MEM_43_INFLS_TYPES_AR_RELEASE_MAJOR_VERSION       4
#define MEM_43_INFLS_TYPES_AR_RELEASE_MINOR_VERSION       7
#define MEM_43_INFLS_TYPES_AR_RELEASE_REVISION_VERSION    0
#define MEM_43_INFLS_TYPES_SW_MAJOR_VERSION               3
#define MEM_43_INFLS_TYPES_SW_MINOR_VERSION               0
#define MEM_43_INFLS_TYPES_SW_PATCH_VERSION               0

/*==================================================================================================
                                    FILE VERSION CHECKS
==================================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if current file and StandardTypes header file are of the same Autosar version */
    #if ((MEM_43_INFLS_TYPES_AR_RELEASE_MAJOR_VERSION != STD_AR_RELEASE_MAJOR_VERSION) || \
         (MEM_43_INFLS_TYPES_AR_RELEASE_MINOR_VERSION != STD_AR_RELEASE_MINOR_VERSION) \
        )
        #error "AutoSar Version Numbers of Mem_43_InFlsTypes.h and StandardTypes.h are different"
    #endif
#endif

/* Check if current file and Mem_43_InFls_CfgDefines.h header file are of the same vendor */
#if (MEM_43_INFLS_TYPES_VENDOR_ID != MEM_43_INFLS_VENDOR_ID_CFG_DEFINES)
    #error "Mem_43_InFlsTypes.h and Mem_43_InFls_CfgDefines.h have different vendor ids"
#endif
/* Check if current file and Mem_43_InFls_CfgDefines.h header file are of the same Autosar version */
#if ((MEM_43_INFLS_TYPES_AR_RELEASE_MAJOR_VERSION    != MEM_43_INFLS_AR_RELEASE_MAJOR_VERSION_CFG_DEFINES) || \
     (MEM_43_INFLS_TYPES_AR_RELEASE_MINOR_VERSION    != MEM_43_INFLS_AR_RELEASE_MINOR_VERSION_CFG_DEFINES) || \
     (MEM_43_INFLS_TYPES_AR_RELEASE_REVISION_VERSION != MEM_43_INFLS_AR_RELEASE_REVISION_VERSION_CFG_DEFINES) \
    )
    #error "AutoSar Version Numbers of Mem_43_InFlsTypes.h and Mem_43_InFls_CfgDefines.h are different"
#endif
/* Check if current file and Mem_43_InFls_CfgDefines.h header file are of the same Software version */
#if ((MEM_43_INFLS_TYPES_SW_MAJOR_VERSION != MEM_43_INFLS_SW_MAJOR_VERSION_CFG_DEFINES) || \
     (MEM_43_INFLS_TYPES_SW_MINOR_VERSION != MEM_43_INFLS_SW_MINOR_VERSION_CFG_DEFINES) || \
     (MEM_43_INFLS_TYPES_SW_PATCH_VERSION != MEM_43_INFLS_SW_PATCH_VERSION_CFG_DEFINES) \
    )
    #error "Software Version Numbers of Mem_43_InFlsTypes.h and Mem_43_InFls_CfgDefines.h are different"
#endif

/* Check if current file and C40_Ip_Types.h header file are of the same vendor */
#if (MEM_43_INFLS_TYPES_VENDOR_ID != C40_IP_TYPES_VENDOR_ID_CFG)
    #error "Mem_43_InFlsTypes.h and C40_Ip_Types.h have different vendor ids"
#endif
/* Check if current file and C40_Ip_Types.h header file are of the same Autosar version */
#if ((MEM_43_INFLS_TYPES_AR_RELEASE_MAJOR_VERSION    != C40_IP_TYPES_AR_RELEASE_MAJOR_VERSION_CFG) || \
     (MEM_43_INFLS_TYPES_AR_RELEASE_MINOR_VERSION    != C40_IP_TYPES_AR_RELEASE_MINOR_VERSION_CFG) || \
     (MEM_43_INFLS_TYPES_AR_RELEASE_REVISION_VERSION != C40_IP_TYPES_AR_RELEASE_REVISION_VERSION_CFG) \
    )
    #error "AutoSar Version Numbers of Mem_43_InFlsTypes.h and C40_Ip_Types.h are different"
#endif
/* Check if current file and C40_Ip_Types.h header file are of the same Software version */
#if ((MEM_43_INFLS_TYPES_SW_MAJOR_VERSION != C40_IP_TYPES_SW_MAJOR_VERSION_CFG) || \
     (MEM_43_INFLS_TYPES_SW_MINOR_VERSION != C40_IP_TYPES_SW_MINOR_VERSION_CFG) || \
     (MEM_43_INFLS_TYPES_SW_PATCH_VERSION != C40_IP_TYPES_SW_PATCH_VERSION_CFG) \
    )
    #error "Software Version Numbers of Mem_43_InFlsTypes.h and C40_Ip_Types.h are different"
#endif

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/
/**
*  @brief    AUTOSAR module identification
*/
#define MEM_43_INFLS_MODULE_ID            91U

/**
*  @brief    AUTOSAR module instance identification
*/
#define MEM_43_INFLS_INSTANCE_ID          0U


/**
 *  Development error codes (passed to DET)
 */
/**
 * @brief       API service called without module initialization
 * @implements  MEM_43_INFLS_E_UNINIT_define
 */
#define MEM_43_INFLS_E_UNINIT                0x01U

/**
 * @brief       API service called with NULL pointer
 * @implements  MEM_43_INFLS_E_PARAM_POINTER_define
 */
#define MEM_43_INFLS_E_PARAM_POINTER         0x02U

/**
 * @brief       API service called with an invalid address
 * @implements  MEM_43_INFLS_E_PARAM_ADDRESS_define
 */
#define MEM_43_INFLS_E_PARAM_ADDRESS         0x03U

/**
 * @brief       API service called with an invalid length
 * @implements  MEM_43_INFLS_E_PARAM_LENGTH_define
*/
#define MEM_43_INFLS_E_PARAM_LENGTH          0x04U

/**
 * @brief       API service called with an invalid driver instance ID
 * @implements  MEM_43_INFLS_E_PARAM_INSTANCE_ID_define
*/
#define MEM_43_INFLS_E_PARAM_INSTANCE_ID     0x05U

/**
 * @brief       API service called while a job request is still in progress
 * @implements  MEM_43_INFLS_E_JOB_PENDING_define
*/
#define MEM_43_INFLS_E_JOB_PENDING           0x06U

/**
 * @brief       API service called without errors
 * @implements  MEM_43_INFLS_E_OK_define
*/
#define MEM_43_INFLS_E_OK                    0xFFU
/**
 *  END Development error codes
 */


/**
 *  All service IDs (passed to DET)
 */
/* Synchronous Functions */
/**
 * @brief   Service ID of function Mem_43_InFls_DeInit
*/
#define MEM_43_INFLS_DEINIT_ID               0x00U

/**
 * @brief   Service ID of function Mem_43_InFls_Init
*/
#define MEM_43_INFLS_INIT_ID                 0x01U

/**
 * @brief   Service ID of function Mem_43_InFls_GetVersionInfo
*/
#define MEM_43_INFLS_GETVERSIONINFO_ID       0x02U

/**
 * @brief   Service ID of function Mem_43_InFls_GetJobResult
*/
#define MEM_43_INFLS_GETJOBRESULT_ID         0x04U

/**
 * @brief   Service ID of function Mem_43_InFls_PropagateError
*/
#define MEM_43_INFLS_PROPAGATEERROR_ID       0x08U

/**
 * @brief   Service ID of function Mem_43_InFls_Suspend
*/
#define MEM_43_INFLS_SUSPEND_ID              0x0CU

/**
 * @brief   Service ID of function Mem_43_InFls_Resume
*/
#define MEM_43_INFLS_RESUME_ID               0x0DU


/* Asynchronous Functions */
/**
 * @brief   Service ID of function Mem_43_InFls_Read
*/
#define MEM_43_INFLS_READ_ID                 0x05U

/**
 * @brief   Service ID of function Mem_43_InFls_Write
*/
#define MEM_43_INFLS_WRITE_ID                0x06U

/**
 * @brief   Service ID of function Mem_43_InFls_Erase
*/
#define MEM_43_INFLS_ERASE_ID                0x07U

/**
 * @brief   Service ID of function Mem_43_InFls_BlankCheck
*/
#define MEM_43_INFLS_BLANKCHECK_ID           0x08U

/**
 * @brief   Service ID of function Mem_43_InFls_HwSpecificService
*/
#define MEM_43_INFLS_HWSPECIFICSERVICE_ID    0x0AU


/* Scheduled Functions */
/**
 * @brief   Service ID of function Mem_43_InFls_MainFunction
*/
#define MEM_43_INFLS_MAINFUNCTION_ID         0x03U
/**
 * END All service IDs
*/


/* Job flags */
/**
 * @brief   Initial value
*/
#define MEM_43_INFLS_JOB_FLAG_NONE           0x00U

/**
 * @brief   Indicates that new job has been accepted
*/
#define MEM_43_INFLS_JOB_FLAG_STARTED        0x01U

/*==================================================================================================
                                                TYPEDEFS
==================================================================================================*/

/**
 * @brief          Mem Address Type
 * @details        Physical memory device address type
 * @implements     Mem_43_InFls_AddressType_typedef
 */
typedef uint32 Mem_43_InFls_AddressType;

/**
 * @brief          Mem Instance Id Type
 * @details        Mem Instance Id Type
 * @implements     Mem_43_InFls_InstanceIdType_typedef
 */
typedef uint32 Mem_43_InFls_InstanceIdType;

/**
 * @brief          Mem Length Type
 * @details        Physical memory device length type
 * @implements     Mem_43_InFls_LengthType_typedef
 */
typedef uint32 Mem_43_InFls_LengthType;

/**
 * @brief          Mem Data Type
 * @details        Read data user buffer type
 * @implements     Mem_43_InFls_DataType_typedef
 */
typedef uint8 Mem_43_InFls_DataType;

/**
 * @brief          Mem CRC Type
 * @details        CRC computed over config set
 *                 Mem_43_InFls_CrcType_typedef
 */
typedef uint16 Mem_43_InFls_CrcType;

/**
 * @brief          Mem Hardware Service Id Type
 * @details        Hardware specific service request identifier type
 * @implements     Mem_43_InFls_HwServiceIdType_typedef
 */
typedef uint32 Mem_43_InFls_HwServiceIdType;

/**
 * @brief          Mem Internal Flash Type
 * @details        Configuration structure of internal flash.
 */
typedef C40_ConfigType Mem_43_InFls_InternalConfigType;

/*==================================================================================================
                                                ENUMS
==================================================================================================*/

/**
 * @brief          Mem job result type
 *                 Mem_43_InFlsJobResultType_enumeration
 */
typedef enum
{
    MEM_43_INFLS_JOB_OK                 = 0x00,    /* The last job has been finished successfully                                    */
    MEM_43_INFLS_JOB_PENDING            = 0x01,    /* A job is currently being processed                                             */
    MEM_43_INFLS_JOB_FAILED             = 0x02,    /* Job failed for some unspecific reason                                          */
    MEM_43_INFLS_JOB_INCONSISTENT       = 0x03,    /* The checked page is not blank                                                  */
    MEM_43_INFLS_JOB_ECC_UNCORRECTED    = 0x04,    /* Uncorrectable ECC errors occurred during memory access                         */
    MEM_43_INFLS_JOB_ECC_CORRECTED      = 0x05     /* Correctable ECC errors occurred during memory access                           */
} Mem_43_InFls_JobResultType;

/**
 * @brief          Type of job currently executed by Mem_43_InFls_MainFunction.
 */
typedef enum
{
    MEM_43_INFLS_JOB_NONE               = 0x00,    /* no job executed                                                                */
    MEM_43_INFLS_JOB_ERASE              = 0x01,    /* erase one or more complete flash sectors                                       */
    MEM_43_INFLS_JOB_WRITE              = 0x02,    /* write one or more complete flash pages                                         */
    MEM_43_INFLS_JOB_READ               = 0x03,    /* read one or more bytes from flash memory                                       */
    MEM_43_INFLS_JOB_COMPARE            = 0x04,    /* compare data buffer with content of flash memory                               */
    MEM_43_INFLS_JOB_BLANK_CHECK        = 0x05     /* check content of erased flash memory area                                      */
} Mem_43_InFls_JobType;


/*==================================================================================================
                                        CONFIGURATION STRUCTURES
==================================================================================================*/

/**
 * @brief          Mem internal unit type
 * @details        Mem internal unit config data structure
 *                 Mem_43_InFls_InternalUnitType_struct
 */
typedef struct
{
    const Mem_43_InFls_InternalConfigType *InternalConfig;      /* Pointer to configuration structure internal flash */
} Mem_43_InFls_InternalUnitType;

/**
 * @brief          Mem device config type
 * @details        Mem device config data structure
 *                 Mem_43_InFls_MemDeviceType_struct
 */
typedef struct
{
    const Mem_43_InFls_InternalUnitType    *InternalUnits;      /* Point to first element in array of internal flash unit configurations */
} Mem_43_InFls_MemDeviceType;


/**
 * @brief          Sector Batch Type
 * @details        Sector Batch data structure for group of identical sectors
 *                 Note: burst sizes equal to normal sizes in case burst disabled
 *                 Mem_43_InFls_SectorBatchType_struct
 */
typedef struct
{
    const Mem_43_InFls_AddressType    StartAddress;       /* Physical start address of the sector batch                              */
    const Mem_43_InFls_AddressType    EndAddress;         /* Physical end address of the sector batch                                */
    const uint32                      SectorSize;         /* Size of a sector in bytes in this sector batch (smallest erasable unit) */
    const uint32                      ReadPageSize;       /* Size of a read page of this sector in bytes (smallest readable unit)    */
    const uint32                      WritePageSize;      /* Size of a write page of this sector in bytes (smallest writeable unit)  */
    const uint32                      EraseBurstSize;     /* Size of sector erase burst in bytes (for improved performance)          */
    const uint32                      ReadBurstSize;      /* Size of page read burst in bytes (for improved performance)             */
    const uint32                      WriteBurstSize;     /* Size of page write/program burst in bytes (for improved performance)    */
} Mem_43_InFls_SectorBatchType;

/**
 * @brief          Mem Instance Type
 * @details        Mem Instance data structure
 *                 Mem_43_InFls_MemInstanceType_struct
 */
typedef struct
{
    const Mem_43_InFls_InstanceIdType     InstanceId;          /* Unique numeric identifier for each a Mem driver instance           */
    const uint32                          SectorBatchCount;    /* Number of sector batches in this Mem instance                      */
    const Mem_43_InFls_SectorBatchType   *SectorBatches;       /* Point to first element in array of sector batches configurations   */
    const uint8                           MemUnitIndex;        /* Index of flash memory unit used for this Mem instance              */
} Mem_43_InFls_MemInstanceType;

/**
 * @brief          Mem Configuration Type
 * @details        Mem module initialization data structure
 * @implements     Mem_43_InFls_ConfigType_struct
 */
typedef struct
{
    const Mem_43_InFls_MemInstanceType   *MemInstances;        /* Point to first element in array of mem instances configurations    */
    const Mem_43_InFls_MemDeviceType     *MemDevices;          /* Mem devices configurations used by the mem instance                */
} Mem_43_InFls_ConfigType;


/*==================================================================================================
                                        INTERNAL TYPES
==================================================================================================*/

/**
 * @brief          Mem job runtime information Type
 * @details        This structure contains runtime information the current processing job of each Mem instance.
 *                 Mem_43_InFls_JobRuntimeInfoType_struct
 */
typedef struct
{
    /* Input information */
    Mem_43_InFls_InstanceIdType            InstanceId;         /* Unique numeric identifier for each a Mem driver instance           */
    Mem_43_InFls_JobType                   JobType;            /* Type of currently executed job (Erase, Write, or Read)             */
    Mem_43_InFls_AddressType               Address;            /* Last physical address to be processed                              */
    Mem_43_InFls_DataType                 *DataPtr;            /* Pointer to user data buffer (used in Read and Write)               */
    Mem_43_InFls_LengthType                Length;             /* Remaining bytes of data to be processed                            */

    /* Output result of the parameter checking stage */
    uint32                                 InstanceIndex;      /* The mem index number according to the mem instance id              */
    const Mem_43_InFls_SectorBatchType    *SectorBatch;        /* The sector batch to be worked with the request job                 */

    /* Runtime information */
    Mem_43_InFls_JobResultType             JobResult;          /* The result of the most recent job                                  */
    uint8                                  JobFlags;           /* Job information (Started state, burst mode)                        */
} Mem_43_InFls_JobRuntimeInfoType;

#ifdef __cplusplus
}
#endif

/** @}*/

#endif /* MEM_43_INFLS_TYPES_H */
