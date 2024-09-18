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

#ifndef MEMACC_TYPES_H
#define MEMACC_TYPES_H

/**
*   @file MemAccTypes.h
*
*   @addtogroup MEMACC Driver
*   @{
*/

/* implements MemAccTypes.h_Artifact */

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
#include "MemAcc_CfgDefines.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define MEMACC_TYPES_VENDOR_ID                      43
#define MEMACC_TYPES_AR_RELEASE_MAJOR_VERSION       4
#define MEMACC_TYPES_AR_RELEASE_MINOR_VERSION       7
#define MEMACC_TYPES_AR_RELEASE_REVISION_VERSION    0
#define MEMACC_TYPES_SW_MAJOR_VERSION               3
#define MEMACC_TYPES_SW_MINOR_VERSION               0
#define MEMACC_TYPES_SW_PATCH_VERSION               0


/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/


/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/

/* Define the type with exactly the size of a pointer for working with pointers */
#if (CPU_TYPE == CPU_TYPE_64)
    typedef uint64 MemAcc_UintPtrType;
#elif (CPU_TYPE == CPU_TYPE_32)
    typedef uint32 MemAcc_UintPtrType;
#else
    #error "Unsupported CPU_TYPE"
#endif


/* Burst settings */
#define MEMACC_BURST_ERASE                        (1U << 0U)
#define MEMACC_BURST_READ                         (1U << 1U)
#define MEMACC_BURST_WRITE                        (1U << 2U)


/* Job flags */
#define MEMACC_JOB_FLAG_NONE                       0x00U     /* Initial value                               */
#define MEMACC_JOB_FLAG_STARTED                    0x01U     /* Indicates that new job has been accepted    */
#define MEMACC_JOB_FLAG_BURST_MODE                 0x02U     /* Indicates that the job uses burts settings  */

#define MEMACC_MEMSERVICE_COMPARE_API_ID           0x01U     /* Hardware-specific service ID for Compare API */
/*==================================================================================================
                                             TYPEDEFS
==================================================================================================*/

/**
* @brief         MemAcc Address Area Id Type
* @details       Unique address area ID type
* @implements    MemAcc_AddressType_typedef
*/
typedef uint16 MemAcc_AddressAreaIdType;


/**
* @brief         MemAcc Address Type
* @details       Logical memory address type (depends on based on MemAcc64BitSupport configuration 32 or 64 bit)
* @implements    MemAcc_AddressType_typedef
*/
typedef MEMACC_ADDRESSTYPE MemAcc_AddressType;


/**
* @brief         MemAcc Length Type
* @details       Job length type (depends on based on MemAcc64BitSupport configuration 32 or 64 bit)
* @implements    MemAcc_LengthType_typedef
*/
typedef MEMACC_LENGTHTYPE MemAcc_LengthType;


/**
* @brief          MemAcc Data Type
* @details        General data type
* @implements     MemAcc_DataType_typedef
*/
typedef uint8 MemAcc_DataType;


/*==================================================================================================
                                             MEM RELATED TYPES
==================================================================================================*/

/**
* @brief         Memory driver configuration structure type
* @details       Memory driver configuration structure type
* @implements    MemAcc_MemConfigType_typedef
*/
typedef void MemAcc_MemConfigType;


/**
* @brief         MemAcc Mem Data Type
* @details       General data type
* @implements    MemAcc_MemDataType_typedef
*/
typedef uint8 MemAcc_MemDataType;


/**
* @brief         Memory driver instance ID type
* @details       Memory driver instance ID type
* @implements    MemAcc_MemInstanceIdType_typedef
*/
typedef uint32 MemAcc_MemInstanceIdType;


/**
* @brief         Physical memory device length type
* @details       Physical memory device length type
* @implements    MemAcc_MemLengthType_typedef
*/
typedef MemAcc_LengthType MemAcc_MemLengthType;


/**
* @brief         Physical memory device address type
* @details       Derived from MemAcc_AddressType
* @implements    MemAcc_MemAddressType_typedef
*/
typedef MemAcc_AddressType MemAcc_MemAddressType;


/**
* @brief         Index type for Mem driver hardware specific service table
* @details       Index type for Mem driver hardware specific service table
* @implements    MemAcc_MemHwServiceIdType_typedef
*/
typedef uint32 MemAcc_MemHwServiceIdType;


/**
* @brief          MemAcc mem job result type
* @implements     MemAcc_MemJobResultType_enumeration
*/
typedef enum
{
    MEM_JOB_OK                 = 0x00,    /* The last job has been finished successfully                                    */
    MEM_JOB_PENDING            = 0x01,    /* A job is currently being processed                                             */
    MEM_JOB_FAILED             = 0x02,    /* Job failed for some unspecific reason                                          */
    MEM_INCONSISTENT           = 0x03,    /* The checked page is not blank                                                  */
    MEM_ECC_UNCORRECTED        = 0x04,    /* Uncorrectable ECC errors occurred during memory access                         */
    MEM_ECC_CORRECTED          = 0x05     /* Correctable ECC errors occurred during memory access                           */
} MemAcc_MemJobResultType;


/**
* @brief         MemAcc_MemInvocationType
* @details       Defines how the Mem driver services are accessed and how the Mem driver is scheduled and activated/initialized.
* 
* @implements    MemAcc_MemInvocationType_enumeration
*/
typedef enum
{
    /**
    * Mem driver is linked with application.
    * Mem service functions are directly called by MemAcc.
    * Mem_Init is called by EcuM and Mem_MainFunction is triggered by SchM.
    * 
    */
    MEMACC_MEM_DIRECT_STATIC    = 0x00,

    /**
    * Mem driver is linked as a separate binary and is dynamically activated.
    * MemAcc will use Mem driver header table to invoke Mem service functions.
    * Call of Mem_Init and Mem_MainFunction is handled by MemAcc.
    * 
    */
    MEMACC_MEM_INDIRECT_DYNAMIC = 0x01,

    /**
    * Mem driver is linked with application.
    * MemAcc will use Mem driver header table to invoke Mem service functions.
    * Call of Mem_Init and Mem_MainFunction is handled by MemAcc.
    */
    MEMACC_MEM_INDIRECT_STATIC  = 0x02
} MemAcc_MemInvocationType;


/*==================================================================================================
                                             ENUMS
==================================================================================================*/

/**
* @brief          Asynchronous job result type
* @implements     MemAccJobResultType_enumeration
*/
typedef enum
{
    MEMACC_MEM_OK               = 0x00,    /* The last MemAcc job was finished successfully                                                    */
    MEMACC_MEM_FAILED           = 0x01,    /* The last MemAcc job resulted in an unspecific failure and the job was not completed              */
    MEMACC_MEM_INCONSISTENT     = 0x02,    /* The last MemAcc job didn't meet the expected result, e.g. a blank check operation                */
    MEMACC_MEM_CANCELED         = 0x03,    /* The last MemAcc job was canceled                                                                 */
    MEMACC_MEM_ECC_UNCORRECTED  = 0x04,    /* The last memory operation returned an uncorrectable ECC error                                    */
    MEMACC_MEM_ECC_CORRECTED    = 0x05     /* The last memory operation returned a correctable ECC error                                       */
} MemAcc_JobResultType;

/**
* @brief          Lock address area status type
*/
typedef enum
{
    MEMACC_UNLOCK             = 0x00,    /* The address area is unlock                                                                         */
    MEMACC_LOCKING            = 0x01,    /* The address area is locking                                                                        */
    MEMACC_LOCKED             = 0x02     /* The address area is locked                                                                         */
} MemAcc_LockStatusType;

/**
* @brief          Asynchronous job status type
* @implements     MemAcc_JobStatusType_enumeration
*/
typedef enum
{
    MEMACC_JOB_IDLE             = 0x00,    /* Job processing was completed or no job currently pending                                         */
    MEMACC_JOB_PENDING          = 0x01     /* A job is currently being processed                                                               */
} MemAcc_JobStatusType;

/**
* @brief          Type for asynchronous jobs
* @implements     MemAcc_JobType_enumeration
*/
typedef enum
{
    MEMACC_NO_JOB               = 0x00,    /* No job currently pending          */
    MEMACC_WRITE_JOB            = 0x01,    /* Write job pending                 */
    MEMACC_READ_JOB             = 0x02,    /* Read job pending                  */
    MEMACC_COMPARE_JOB          = 0x03,    /* Compare job pending               */
    MEMACC_ERASE_JOB            = 0x04,    /* Erase job pending                 */
    MEMACC_MEMHWSPECIFIC_JOB    = 0x05,    /* Hardware specific job pending     */
    MEMACC_BLANKCHECK_JOB       = 0x06,    /* Blank check job pending           */
    MEMACC_REQUESTLOCK_JOB      = 0x07     /* Request lock job pending          */
} MemAcc_JobType;


/**
* @brief          Internal asynchronous job state transition
* @implements     MemAcc_JobStateType_enumeration
*/
typedef enum
{
    MEMACC_JOB_STATE_STARTING    = 0x00,  /* The job is pending to be processed             */
    MEMACC_JOB_STATE_PROCESSING  = 0x01,  /* The job is being processed                     */
    MEMACC_JOB_STATE_RETRYING    = 0x02,  /* The job is attempting a retry after a failure  */
    MEMACC_JOB_STATE_SUSPENDING  = 0x03,  /* The job is being suspended                     */
    MEMACC_JOB_STATE_RESUMING    = 0x04,  /* The job is being resumed                       */
    MEMACC_JOB_STATE_CANCELING   = 0x05,  /* The job is being canceled                      */
    MEMACC_JOB_STATE_STOP        = 0x06   /* The job is stop                                */
} MemAcc_JobStateType;


/**
* @brief         MemAcc Hardware Id Type
* @details       The name of each enum parameter is constructed from the Mem module name and the Mem instance name.
*                Type for the unique numeric identifiers of all Mem hardware instances used for hardware specific requests.
* 
* @implements    MemAcc_HwIdType_enumeration
*/
typedef uint32 MemAcc_HwIdType;


/*==================================================================================================
                                            FUNCTION POINTER PROTOTYPE
==================================================================================================*/

/**
 * @brief    Function pointer for the Mem_Init service for the invocation of the Mem driver API via function pointer interface.
*/
typedef void (*MemAcc_MemInitFuncType)(
    MemAcc_MemConfigType    *ConfigPtr
);


/**
 * @brief    Function pointer for the Mem_DeInit service for the invocation of the Mem driver API via function pointer interface.
*/
typedef void (*MemAcc_MemDeInitFuncType)(void);


/**
 * @brief    Function pointer for the Mem_JobResultType service for the invocation of the Mem driver API via function pointer interface.
*/
typedef MemAcc_MemJobResultType (*MemAcc_MemGetJobResultFuncType)(
    MemAcc_MemInstanceIdType    InstanceId
);


/**
 * @brief    Function pointer for the Mem_Suspend service for the invocation of the Mem driver API via function pointer interface.
*/
typedef void (*MemAcc_MemSuspendFuncType)(
    MemAcc_MemInstanceIdType    InstanceId
);


/**
 * @brief    Function pointer for the Mem_Resume service for the invocation of the Mem driver API via function pointer interface.
*/
typedef void (*MemAcc_MemResumeFuncType)(
    MemAcc_MemInstanceIdType    InstanceId
);


/**
 * @brief    Function pointer for the Mem_PropagateError service for the invocation of the Mem driver API via function pointer interface.
*/
typedef void (*MemAcc_MemPropagateErrorFuncType)(
    MemAcc_MemInstanceIdType    InstanceId
);


/**
 * @brief    Function pointer for the Mem_Read service for the invocation of the Mem driver API via function pointer interface.
*/
typedef Std_ReturnType (*MemAcc_MemReadFuncType)(
    MemAcc_MemInstanceIdType    InstanceId,
    MemAcc_MemAddressType       SourceAddress,
    MemAcc_MemDataType         *DestinationDataPtr,
    MemAcc_MemLengthType        Length
);


/**
 * @brief    Function pointer for the Mem_Write service for the invocation of the Mem driver API via function pointer interface.
*/
typedef Std_ReturnType (*MemAcc_MemWriteFuncType)(
    MemAcc_MemInstanceIdType     InstanceId,
    MemAcc_MemAddressType        TargetAddress,
    const  MemAcc_MemDataType   *SourceDataPtr,
    MemAcc_MemLengthType         Length
);


/**
 * @brief    Function pointer for the Mem_Erase service for the invocation of the Mem driver API via function pointer interface.
*/
typedef Std_ReturnType (*MemAcc_MemEraseFuncType)(
    MemAcc_MemInstanceIdType     InstanceId,
    MemAcc_MemAddressType        TargetAddress,
    MemAcc_MemLengthType         Length
);


/**
 * @brief    Function pointer for the Mem_BlankCheck service for the invocation of the Mem driver API via function pointer interface.
*/
typedef Std_ReturnType (*MemAcc_MemBlankCheckFuncType)(
    MemAcc_MemInstanceIdType     InstanceId,
    MemAcc_MemAddressType        TargetAddress,
    MemAcc_MemLengthType         Length
);


/**
 * @brief    Function pointer for the Mem_HwSpecificService service for the invocation of the Mem driver API via function pointer interface.
*/
typedef Std_ReturnType (*MemAcc_MemHwSpecificServiceFuncType)(
    MemAcc_MemInstanceIdType     InstanceId,
    MemAcc_MemHwServiceIdType    HwServiceId,
    MemAcc_MemDataType          *DataPtr,
    MemAcc_MemLengthType        *LengthPtr
);


/**
 * @brief    Function pointer for the Mem_MainFunction service for the invocation of the Mem driver API via function pointer interface.
*/
typedef void (*MemAcc_MemMainFuncType)(void);


/*==================================================================================================
                                            NOTIFICATION PROTOTYPE
==================================================================================================*/

/* MemAcc application job end notification callback. The function name is configurable */
typedef void (*MemAcc_AddressAreaJobEndNotification)(
    MemAcc_AddressAreaIdType    AddressAreaId,
    MemAcc_JobResultType        JobResult
);


/* Address area lock application callback. The function name is configurable. */
typedef void (*MemAcc_ApplicationLockNotification)(void);


/*==================================================================================================
                                        CONFIGURATION STRUCTURES
==================================================================================================*/

/**
* @brief          MemAcc memory infomation type
* @details        This structure contains information of Mem device characteristics.
*                 It can be accessed via the MemAcc_GetMemoryInfo() service.
* @implements     MemAcc_MemoryInfoType_typedef
*/
typedef struct
{
    MemAcc_AddressType    LogicalStartAddress;     /* Logical start address of sub address area                                          */
    MemAcc_AddressType    PhysicalStartAddress;    /* Physical start address of sub address area                                         */
    MemAcc_LengthType     MaxOffset;               /* Size of sub address area in bytes -1                                               */
    uint32                EraseSectorSize;         /* Size of a sector in bytes                                                          */
    uint32                EraseSectorBurstSize;    /* Size of a sector burst in bytes. Equals SectorSize in case burst is disabled       */
    uint32                ReadPageSize;            /* Read size of a page in bytes                                                       */
    uint32                WritePageSize;           /* Write size of a page in bytes                                                      */
    uint32                ReadPageBurstSize;       /* Size of a read page burst in bytes. Equals ReadPageSize in case burst is disabled  */
    uint32                WritePageBurstSize;      /* Size of a page burst in bytes. Equals WritePageSize in case burst is disabled      */
    MemAcc_HwIdType       HwId;                    /* Referenced memory driver hardware identifier                                       */
} MemAcc_MemoryInfoType;


/**
* @brief          MemAcc job infomation type
* @details        This structure contains information the current processing state of the MemAcc module.
* @implements     MemAcc_MemoryInfoType_typedef
*/
typedef struct
{
    uint32                  LogicalAddress;    /* Address of currently active address area request             */
    uint32                  Length;            /* Length of the currently active address area request          */
    MemAcc_HwIdType         HwId;              /* Referenced memory driver hardware identifier                 */
    uint32                  MemInstanceId;     /* Instance ID of the current memory request                    */
    uint32                  MemAddress;        /* Physical address of the current memory driver request        */
    uint32                  MemLength;         /* Length of memory driver request                              */
    MemAcc_JobType          CurrentJob;        /* Currently active MemAcc job                                  */
    MemAcc_JobResultType    MemResult;         /* Current or last Mem driver result                            */
} MemAcc_JobInfoType;


/**
* @brief          MemAcc_MemApiType
* @details        This structure contains elements for accessing the Mem driver service functions and consistency information.
* @implements     MemAcc_MemApiType_typedef
*/
typedef struct
{
    uint64                                 UniqueId;                 /* Unique ID                                     */
    uint64                                 Flags;                    /* Header flags                                  */
    uint64                                 Header;                   /* Address of Mem driver header structure        */
    uint64                                 Delimiter;                /* Address of Mem driver delimiter field         */
    MemAcc_MemInitFuncType                 InitFunc;                 /* Mem_Init function pointer                     */
    MemAcc_MemDeInitFuncType               DeInitFunc;               /* Mem_Init function pointer                     */
    MemAcc_MemMainFuncType                 MainFunc;                 /* Mem_Main function pointer                     */
    MemAcc_MemGetJobResultFuncType         GetJobResultFunc;         /* Mem_GetJobResult function pointer             */
    MemAcc_MemReadFuncType                 ReadFunc;                 /* Mem_Read function pointer                     */
    MemAcc_MemWriteFuncType                WriteFunc;                /* Mem_Write function pointer                    */
    MemAcc_MemEraseFuncType                EraseFunc;                /* Mem_Erase function pointer                    */
    MemAcc_MemBlankCheckFuncType           BlankCheckFunc;           /* Mem_BlankCheck function pointer               */
    MemAcc_MemPropagateErrorFuncType       PropagateErrorFunc;       /* Mem_PropagateError function pointer           */
    MemAcc_MemSuspendFuncType              SuspendFunc;              /* Mem_Suspend function pointer                  */
    MemAcc_MemResumeFuncType               ResumeFunc;               /* Mem_Resume function pointer                   */
    MemAcc_MemHwSpecificServiceFuncType    HwSpecificServiceFunc;    /* Hardware specific service function pointer    */
} MemAcc_MemApiType;

typedef struct
{
    const uint32                   SectorSize;         /* Size of a sector in bytes in this sector batch (smallest erasable unit) */
    const uint32                   ReadPageSize;       /* Size of a read page of this sector in bytes (smallest readable unit)    */
    const uint32                   WritePageSize;      /* Size of a write page of this sector in bytes (smallest writeable unit)  */
    const uint32                   EraseBurstSize;     /* Size of sector erase burst in bytes (for improved performance)          */
    const uint32                   ReadBurstSize;      /* Size of page read burst in bytes (for improved performance)             */
    const uint32                   WriteBurstSize;     /* Size of page write/program burst in bytes (for improved performance)    */
} MemAcc_SectorBatchInfoType;
/**
* @brief          MemAcc_SubAddressAreaType
* @details        Data structure for a sub address area
* @implements     MemAcc_SubAddressAreaType_typedef
*/
typedef struct
{
    MemAcc_AddressType                  LogicalStartAddress;     /* Logical start address of sub address area                      */
    MemAcc_AddressType                  PhysicalStartAddress;    /* Physical start address of sub address area                     */
    MemAcc_LengthType                   Length;                  /* Size of sub address area in bytes                              */
    uint8                               NumOfEraseRetries;       /* The number of retries of a failed erase job                    */
    uint8                               NumOfWriteRetries;       /* The number of retries of a failed write job                    */
    uint8                               BurstSettings;           /* Burst settings of Erase/read/write operations                  */
    /* Mem related information */
    MemAcc_MemInvocationType            MemInvocation;           /* How the Mem driver is invocated                                */
    const MemAcc_MemApiType            *MemApi;                  /* Mem driver service functions and consistency information       */
    MemAcc_MemInstanceIdType            MemInstanceId;           /* Instance ID of the current memory request                      */
    const MemAcc_SectorBatchInfoType    MemSectorBatchInfo;      /* Sector batch information                                       */
    uint8                               MemHwResource;           /* The hardware resource identifier value                         */
    uint8                               Hw_Id;                   /* Referenced memory driver hardware identifier                   */
} MemAcc_SubAddressAreaType;


/**
* @brief          MemAcc_AddressAreaType
* @details        This structure contains configured information for each memory address areas.
* @implements     MemAcc_AddressAreaType_typedef
*/
typedef struct
{
    MemAcc_AddressAreaIdType                AreaId;             /* Unique numeric identifier of address area                              */
    MemAcc_LengthType                       Length;             /* Size of the whole address area in bytes                                */
    uint16                                  Priority;           /* The priority of an AddressArea compared to other AddressAreas          */
    uint8                                   BufferAlignment;    /* Buffer alignment value                                                 */
    MemAcc_AddressAreaJobEndNotification    JobEndNotif;        /* The notification function which is called after MemAcc job completion  */
    uint16                                  SubAreaCount;       /* Number of sub address areas in this memory address area                */
    const MemAcc_SubAddressAreaType        *SubAreas;           /* Point to first element in array of sub address areas configurations    */
} MemAcc_AddressAreaType;


/**
* @brief          MemAcc job runtime information type
* @details        This structure contains runtime information the current processing job of each address area.
* @implements     MemAcc_JobRuntimeInfoType_typedef
*/
typedef struct
{
    /* Input information */
    MemAcc_AddressAreaIdType            AreaId;              /* Requested address area id                                   */
    MemAcc_JobType                      JobType;             /* Type of currently executed job (Erase, Write, or Read,...)  */
    MemAcc_AddressType                  LogicAddress;        /* Last logical address to be processed                        */
    MemAcc_AddressType                  PhysicAddress;       /* Last physical address to be processed                       */
    MemAcc_LengthType                   LengthOrigin;        /* Requested bytes of data to be processed                     */
    MemAcc_DataType                    *DataPtr;             /* Pointer to user data buffer (used in Read, Write, Compare)  */
    MemAcc_MemHwServiceIdType           MemHwServiceId;      /* Hardware specific service request identifier for dispatching the request */
    /* Output result of the parameter checking stage */
    uint16                              AreaIndex;           /* The index of address area being processed                   */
    const MemAcc_SubAddressAreaType    *SubArea;             /* The start sub address area of the requested job             */
    /* Runtime information */
    MemAcc_LengthType                   LengthRemain;        /* Remaining bytes of data to be processed                     */
    MemAcc_LengthType                   LengthChunk;         /* The amount of data in bytes to be processed each chunk      */
    MemAcc_JobStateType                 JobState;            /* The internal transition state                               */
    MemAcc_JobResultType                JobResult;           /* The result of the most recent job                           */
    MemAcc_JobStatusType                JobStatus;           /* The asynchronous job status                                 */
    uint8                               JobRetries;          /* The number of retries of a failed erase or write job        */
    MemAcc_LockStatusType               LockStatus;          /* The lock status of the address area                         */
    boolean                             JobLocked;           /* The requested job is locked or not                          */
    MemAcc_AddressType                  LockAddress;         /* The start address of locked area                            */
    MemAcc_LengthType                   LockLength;          /* The length of locked area                                   */
    MemAcc_ApplicationLockNotification  LockNotif;           /* The callback function is called when the lock is complete   */
} MemAcc_JobRuntimeInfoType;


/**
* @brief          MemAcc Configuration type
* @details        Postbuild configuration structure type
* @implements     MemAcc_ConfigType_typedef
*/
typedef struct
{
    const uint32                    AddressAreaCount;    /* Number of address areas are configured in this configuration set   */
    const MemAcc_AddressAreaType   *AddressAreas;        /* Point to first element in array of address areas configurations    */
    MemAcc_JobRuntimeInfoType      *JobRuntimeInfo;      /* Point to first element in array of job runtime infomation          */
    const uint32                    MemApiCount;         /* Number of Mem drivers are used by MemAcc in this configuration set */
    MemAcc_MemApiType              *MemApis;             /* Mem driver service functions and consistency information           */
    const MemAcc_MemInvocationType *MemApisInvocation;   /* How the Mem drivers is invocated                                   */
} MemAcc_ConfigType;


#ifdef __cplusplus
}
#endif

/** @}*/

#endif /* MEMACC_TYPES_H */
