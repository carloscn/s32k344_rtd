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
 * @file       Mem_43_InFls.c
 *
 * @addtogroup MEM_43_INFLS
 * implements  Mem_43_InFls.c_Artifact
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
#include "Det.h"
#include "SchM_Mem_43_InFls.h"

#include "Mem_43_InFls.h"
#include "Mem_43_InFls_Ipw.h"

/*==================================================================================================
 *                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define MEM_43_INFLS_VENDOR_ID_C                      43
#define MEM_43_INFLS_AR_RELEASE_MAJOR_VERSION_C       4
#define MEM_43_INFLS_AR_RELEASE_MINOR_VERSION_C       7
#define MEM_43_INFLS_AR_RELEASE_REVISION_VERSION_C    0
#define MEM_43_INFLS_SW_MAJOR_VERSION_C               3
#define MEM_43_INFLS_SW_MINOR_VERSION_C               0
#define MEM_43_INFLS_SW_PATCH_VERSION_C               0

/*==================================================================================================
 *                                     FILE VERSION CHECKS
==================================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if current file and Det header file are of the same Autosar version */
    #if ((MEM_43_INFLS_AR_RELEASE_MAJOR_VERSION_C != DET_AR_RELEASE_MAJOR_VERSION) || \
         (MEM_43_INFLS_AR_RELEASE_MINOR_VERSION_C != DET_AR_RELEASE_MINOR_VERSION) \
        )
        #error "AutoSar Version Numbers of Mem_43_InFls.c and Det.h are different"
    #endif
    /* Check if current file and SchM_Fls header file are of the same Autosar version */
    #if ((MEM_43_INFLS_AR_RELEASE_MAJOR_VERSION_C != SCHM_MEM_43_INFLS_AR_RELEASE_MAJOR_VERSION) || \
         (MEM_43_INFLS_AR_RELEASE_MINOR_VERSION_C != SCHM_MEM_43_INFLS_AR_RELEASE_MINOR_VERSION) \
        )
        #error "AutoSar Version Numbers of Mem_43_InFls.c and SchM_Mem_43_InFls.h are different"
    #endif
#endif

/* Check if current file and Mem_43_InFls.h header file are of the same vendor */
#if (MEM_43_INFLS_VENDOR_ID_C != MEM_43_INFLS_VENDOR_ID)
    #error "Mem_43_InFls.c and Mem_43_InFls.h have different vendor ids"
#endif
/* Check if current file and Mem_43_InFls.h header file are of the same Autosar version */
#if ((MEM_43_INFLS_AR_RELEASE_MAJOR_VERSION_C    != MEM_43_INFLS_AR_RELEASE_MAJOR_VERSION) || \
     (MEM_43_INFLS_AR_RELEASE_MINOR_VERSION_C    != MEM_43_INFLS_AR_RELEASE_MINOR_VERSION) || \
     (MEM_43_INFLS_AR_RELEASE_REVISION_VERSION_C != MEM_43_INFLS_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Mem_43_InFls.c and Mem_43_InFls.h are different"
#endif
/* Check if current file and Mem_43_InFls.h header file are of the same Software version */
#if ((MEM_43_INFLS_SW_MAJOR_VERSION_C != MEM_43_INFLS_SW_MAJOR_VERSION) || \
     (MEM_43_INFLS_SW_MINOR_VERSION_C != MEM_43_INFLS_SW_MINOR_VERSION) || \
     (MEM_43_INFLS_SW_PATCH_VERSION_C != MEM_43_INFLS_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Mem_43_InFls.c and Mem_43_InFls.h are different"
#endif

/* Check if current file and Mem_43_InFls_Ipw.h header file are of the same vendor */
#if (MEM_43_INFLS_VENDOR_ID_C != MEM_43_INFLS_IPW_VENDOR_ID)
    #error "Mem_43_InFls.c and Mem_43_InFls_Ipw.h have different vendor ids"
#endif
/* Check if current file and Mem_43_InFls_Ipw.h header file are of the same Autosar version */
#if ((MEM_43_INFLS_AR_RELEASE_MAJOR_VERSION_C    != MEM_43_INFLS_IPW_AR_RELEASE_MAJOR_VERSION) || \
     (MEM_43_INFLS_AR_RELEASE_MINOR_VERSION_C    != MEM_43_INFLS_IPW_AR_RELEASE_MINOR_VERSION) || \
     (MEM_43_INFLS_AR_RELEASE_REVISION_VERSION_C != MEM_43_INFLS_IPW_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Mem_43_InFls.c and Mem_43_InFls_Ipw.h are different"
#endif
/* Check if current file and Mem_43_InFls_Ipw.h header file are of the same Software version */
#if ((MEM_43_INFLS_SW_MAJOR_VERSION_C != MEM_43_INFLS_IPW_SW_MAJOR_VERSION) || \
     (MEM_43_INFLS_SW_MINOR_VERSION_C != MEM_43_INFLS_IPW_SW_MINOR_VERSION) || \
     (MEM_43_INFLS_SW_PATCH_VERSION_C != MEM_43_INFLS_IPW_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Mem_43_InFls.c and Mem_43_InFls_Ipw.h are different"
#endif

/*==================================================================================================
 *                                      GLOBAL VARIABLES
==================================================================================================*/

#define MEM_43_INFLS_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "Mem_43_InFls_MemMap.h"


/* Pointer to current mem internal flash module configuration set */
const Mem_43_InFls_ConfigType           * Mem_43_InFls_pConfigPtr;

/* Information of the current processing job of each Mem instance */
static Mem_43_InFls_JobRuntimeInfoType    Mem_43_InFls_eJobRuntimeInfo[MEM_43_INFLS_MEM_INSTANCE_COUNT];


#define MEM_43_INFLS_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "Mem_43_InFls_MemMap.h"

/*==================================================================================================
 *                           LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/


/*==================================================================================================
                                        LOCAL MACROS
==================================================================================================*/

/*! Specifies invalid mem instance index (valid ones will be in range 0 to MEM_43_INFLS_MEM_INSTANCE_COUNT-1) */
#define MEM_43_INFLS_MEM_INSTANCE_INDEX_INVALID              MEM_43_INFLS_MEM_INSTANCE_COUNT

/*==================================================================================================
                                       LOCAL VARIABLES
==================================================================================================*/


/*==================================================================================================
                                       LOCAL CONSTANTS
==================================================================================================*/


/*==================================================================================================
                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/


/*==================================================================================================
                                       LOCAL FUNCTIONS (internal usage)
==================================================================================================*/

#define MEM_43_INFLS_START_SEC_CODE
#include "Mem_43_InFls_MemMap.h"


/**
 * @brief    Report a development error
 */
static void Mem_43_InFls_ReportDevError(
    Mem_43_InFls_InstanceIdType    InstanceId,
    uint32                      ApiId,
    uint32                      ErrorId
)
{
#if (MEM_43_INFLS_DEV_ERROR_DETECT == STD_ON)
    /* Raise the development error via Det function */
    (void)Det_ReportError(MEM_43_INFLS_MODULE_ID, (uint8)InstanceId, (uint8)ApiId, (uint8)ErrorId);
#endif

    (void)InstanceId;
    (void)ApiId;
    (void)ErrorId;
}


/**
 * @brief    Computes and checks the CRC over configuration set
 */
static Std_ReturnType Mem_43_InFls_ValidateConfigCRC(void)
{
    Std_ReturnType RetVal = (Std_ReturnType)E_OK;
    /* Not implemented yet */
    return RetVal;
}


/**
 * @brief    Search the list of Mem instances and returns index of instance with matching InstanceId
 */
static uint32 Mem_43_InFls_GetInstanceIndex(const Mem_43_InFls_InstanceIdType InstanceId)
{
    uint32 InstanceIndex = 0U;

    /* Loop through all configured memory instances */
    for (InstanceIndex = 0U; InstanceIndex < MEM_43_INFLS_MEM_INSTANCE_COUNT; InstanceIndex++)
    {
        if (InstanceId == Mem_43_InFls_pConfigPtr->MemInstances[InstanceIndex].InstanceId)
        {
            /* InstanceId is matched, exit loop */
            break;
        }
    }

    /* The returned value will be INVALID if InstanceId is not matched with any InstanceIndex */
    return InstanceIndex;
}


/**
 * @brief    Search for the sector batch that contains the provided address
 */
static const Mem_43_InFls_SectorBatchType * Mem_43_InFls_GetSectorBatch(
    uint32                   InstanceIndex,
    Mem_43_InFls_AddressType    Address
)
{
    const Mem_43_InFls_MemInstanceType *MemInstance = &(Mem_43_InFls_pConfigPtr->MemInstances[InstanceIndex]);
    const Mem_43_InFls_SectorBatchType *SectorBatch = MemInstance->SectorBatches;
    uint32 Index = 0U;

    /* Loop through all configured sector batches of this memory instance */
    do
    {
        if ( (SectorBatch->StartAddress <= Address) && (Address <= SectorBatch->EndAddress) )
        {
            /* The address falls within this sector batch */
            break;
        }

        /* Move to the next sector batch */
        SectorBatch++;
        Index++;
    }
    while (Index < MemInstance->SectorBatchCount);

    /* The returned value will be NULL_PTR if Address does not fall within any sector batch */
    if (Index >= MemInstance->SectorBatchCount)
    {
        SectorBatch = NULL_PTR;
    }

    return SectorBatch;
}


/**
 * @brief    Checks if the provided address and length are in range and aligned to end of the sector.
 */
static uint32 Mem_43_InFls_CheckSectorAligned(Mem_43_InFls_JobRuntimeInfoType *JobRequest)
{
    uint32 ErrorId;
    uint32 SectorSize = JobRequest->SectorBatch->SectorSize;
    Mem_43_InFls_AddressType StartAddress  = JobRequest->SectorBatch->StartAddress;
    Mem_43_InFls_AddressType EndAddress    = JobRequest->SectorBatch->EndAddress;
    Mem_43_InFls_AddressType TargetAddress = JobRequest->Address;
    Mem_43_InFls_LengthType  Length        = JobRequest->Length;

    if ( ( 0U != ((TargetAddress - StartAddress) % SectorSize)))
    {
        /* Address of job is not in range or not aligned to start of the sector */
        ErrorId = MEM_43_INFLS_E_PARAM_ADDRESS;
    }
    else if ( 0U != ( ( EndAddress - ( (TargetAddress + Length) - 1U ) )  % SectorSize ))
    {
        /* Length of job is not aligned to end of the sector */
        ErrorId = MEM_43_INFLS_E_PARAM_LENGTH;
    }
    else
    {
        /* Both address and length are valid */
        ErrorId = MEM_43_INFLS_E_OK;
    }

    return ErrorId;
}


/**
 * @brief    Checks if the provided address and length are in range and aligned to end of the page.
 */
static uint32 Mem_43_InFls_CheckWritePageAligned(Mem_43_InFls_JobRuntimeInfoType *JobRequest)
{
    uint32 ErrorId;
    uint32 WritePageSize = JobRequest->SectorBatch->WritePageSize;
    Mem_43_InFls_AddressType StartAddress  = JobRequest->SectorBatch->StartAddress;
    Mem_43_InFls_AddressType TargetAddress = JobRequest->Address;
    Mem_43_InFls_LengthType  Length        = JobRequest->Length;
    Mem_43_InFls_LengthType  SectorOffset  = 0U;

    SectorOffset = (TargetAddress + Length) - StartAddress;

    if ( 0U != ( TargetAddress % WritePageSize ) )
    {
        /* Address of job is not in range or not aligned to start of the page */
        ErrorId = MEM_43_INFLS_E_PARAM_ADDRESS;
    }
    else if ( 0U != (SectorOffset % WritePageSize) )
    {
        /* Length of job is not aligned to end of the page */
        ErrorId = MEM_43_INFLS_E_PARAM_LENGTH;
    }
    else
    {
        /* Both address and length are valid */
        ErrorId = MEM_43_INFLS_E_OK;
    }

    return ErrorId;
}


/**
 * @brief    Checks if the provided address and length are valid
 */
static uint32 Mem_43_InFls_ValidateAddressAndLength(Mem_43_InFls_JobRuntimeInfoType *JobRequest)
{
    uint32 ErrorId;

    JobRequest->SectorBatch = Mem_43_InFls_GetSectorBatch(JobRequest->InstanceIndex, JobRequest->Address);
    if (NULL_PTR == JobRequest->SectorBatch)
    {
        /* Could not find the sector batch, the address is invalid */
        ErrorId = MEM_43_INFLS_E_PARAM_ADDRESS;
    }
    else if ( (0U == JobRequest->Length) ||
              ((JobRequest->Address + JobRequest->Length - 1U) > JobRequest->SectorBatch->EndAddress)
            )
    {
        /* The length is invalid */
        ErrorId = MEM_43_INFLS_E_PARAM_LENGTH;
    }
    else
    {
        switch (JobRequest->JobType)
        {
        case MEM_43_INFLS_JOB_ERASE:
            ErrorId = Mem_43_InFls_CheckSectorAligned(JobRequest);
            break;
        case MEM_43_INFLS_JOB_WRITE:
            ErrorId = Mem_43_InFls_CheckWritePageAligned(JobRequest);
            break;

        default:
            /* Both address and length are valid */
            ErrorId = MEM_43_INFLS_E_OK;
            break;
        }
    }

    return ErrorId;
}


/**
 * @brief    Checks if provided InstanceId is consistent with the configuration
 */
static uint32 Mem_43_InFls_ValidateInstanceId(Mem_43_InFls_JobRuntimeInfoType *JobRequest)
{
    uint32 ErrorId = MEM_43_INFLS_E_OK;

    /* Get the mem index number according to the mem instance id */
    JobRequest->InstanceIndex = Mem_43_InFls_GetInstanceIndex(JobRequest->InstanceId);

#if (MEM_43_INFLS_DEV_ERROR_DETECT == STD_ON)
    /* Only check if development error detection is enabled */
    if (MEM_43_INFLS_MEM_INSTANCE_INDEX_INVALID == JobRequest->InstanceIndex)
    {
        /* The provided InstanceId is inconsistent with the configuration */
        ErrorId = MEM_43_INFLS_E_PARAM_INSTANCE_ID;
    }
#endif

    return ErrorId;
}


/**
 * @brief    Checks if the Mem module has been initialized.
 */
static inline uint32 Mem_43_InFls_ValidateModuleInitialized(void)
{
    uint32 ErrorId = MEM_43_INFLS_E_OK;

#if (MEM_43_INFLS_DEV_ERROR_DETECT == STD_ON)
    /* Only check if development error detection is enabled */
    if (NULL_PTR == Mem_43_InFls_pConfigPtr)
    {
        /* The Mem module has not been initialized */
        ErrorId = MEM_43_INFLS_E_UNINIT;
    }
#endif

    return ErrorId;
}


/**
 * @brief    Common checks of input parameters for driver APIs.
 */
static uint32 Mem_43_InFls_ValidateParamJobCommon(Mem_43_InFls_JobRuntimeInfoType *JobRequest)
{
    uint32 ErrorId;

    /* Checks if the Mem module has been initialized */
    ErrorId = Mem_43_InFls_ValidateModuleInitialized();

    if (MEM_43_INFLS_E_OK == ErrorId)
    {
        /* Check if the provided InstanceId is consistent with the configuration */
        ErrorId = Mem_43_InFls_ValidateInstanceId(JobRequest);
    }

    if (MEM_43_INFLS_E_OK == ErrorId)
    {
        /* Check if the address and the length are valid */
        ErrorId = Mem_43_InFls_ValidateAddressAndLength(JobRequest);
    }

    return ErrorId;
}


/**
 * @brief    Checks if the input argument is a NULL pointer.
 */
static inline uint32 Mem_43_InFls_ValidateDataPointer(const Mem_43_InFls_DataType *DataPtr)
{
    uint32 ErrorId = MEM_43_INFLS_E_OK;

    if (NULL_PTR == DataPtr)
    {
        /* The DataPtr argument is a NULL pointer */
        ErrorId = MEM_43_INFLS_E_PARAM_POINTER;
    }

    return ErrorId;
}


/**
 * @brief    Checks the input parameters for data transfer jobs (read, write)
 */
static uint32 Mem_43_InFls_ValidateParamJobDataTransfer(Mem_43_InFls_JobRuntimeInfoType *JobRequest)
{
    uint32 ErrorId;

    /* Perform the common checking */
    ErrorId = Mem_43_InFls_ValidateParamJobCommon(JobRequest);

    /* Perform the specific checking */
    if (MEM_43_INFLS_E_OK == ErrorId)
    {
        ErrorId = Mem_43_InFls_ValidateDataPointer(JobRequest->DataPtr);
    }

    return ErrorId;
}


/**
 * @brief    Initialize the input parameter for the new job request
 */
static void Mem_43_InFls_InitJobRequest(
    Mem_43_InFls_JobRuntimeInfoType    *JobRequest,
    Mem_43_InFls_InstanceIdType         InstanceId,
    Mem_43_InFls_AddressType            Address,
    Mem_43_InFls_DataType              *DataPtr,
    Mem_43_InFls_LengthType             Length
)
{
    /* Input value */
    JobRequest->InstanceId       = InstanceId;
    JobRequest->Address          = Address;
    JobRequest->DataPtr          = DataPtr;
    JobRequest->Length           = Length;
    /* Default value */
    JobRequest->InstanceIndex    = MEM_43_INFLS_MEM_INSTANCE_INDEX_INVALID;
    JobRequest->SectorBatch      = NULL_PTR;
    /* Prepare for a new job */
    JobRequest->JobFlags         = MEM_43_INFLS_JOB_FLAG_STARTED;
    JobRequest->JobResult        = MEM_43_INFLS_JOB_PENDING;
}


/**
 * @brief    Check if the mem instance is idle and configure the new job request
 */
static uint32 Mem_43_InFls_ConfigureJobRequest(const Mem_43_InFls_JobRuntimeInfoType *JobRequest)
{
    uint32 ErrorId;

    if (MEM_43_INFLS_JOB_PENDING == Mem_43_InFls_eJobRuntimeInfo[JobRequest->InstanceIndex].JobResult)
    {
        /* A previous job is still being processed */
        ErrorId = MEM_43_INFLS_E_JOB_PENDING;
    }
    else
    {
        /* Accept the requested job */
        ErrorId = MEM_43_INFLS_E_OK;
        /* Configure the new job */
        Mem_43_InFls_eJobRuntimeInfo[JobRequest->InstanceIndex] = *JobRequest;
    }

    return ErrorId;
}


/**
 * @brief   Decides which sub-function to call based on the job type:
 *          Modify (Write, Erase) or Read (Read, BlankCheck).
 */
static Mem_43_InFls_JobResultType Mem_43_InFls_DoRequestedJobs(
    uint32                           InstanceIndex,
    Mem_43_InFls_JobRuntimeInfoType    *JobInfo
)
{
    /* Assume no more data to process, previous asynchronous job completed successfully */
    Mem_43_InFls_JobResultType JobResult = MEM_43_INFLS_JOB_OK;

    if (0U != JobInfo->Length)
    {
        /* Call Low-level driver to work with physical flash device
         * Process the maximum length depending on the hardware capabilities, or until a sector boundary
         */
        switch (JobInfo->JobType)
        {
            case MEM_43_INFLS_JOB_ERASE:
                JobResult = Mem_43_InFls_IPW_Erase(InstanceIndex, JobInfo);
                break;

            case MEM_43_INFLS_JOB_WRITE:
                JobResult = Mem_43_InFls_IPW_Write(InstanceIndex, JobInfo);
                break;

            case MEM_43_INFLS_JOB_READ:
                JobResult = Mem_43_InFls_IPW_Read(InstanceIndex, JobInfo);
                break;

            case MEM_43_INFLS_JOB_BLANK_CHECK:
                JobResult = Mem_43_InFls_IPW_BlankCheck(InstanceIndex, JobInfo);
                break;

            default:  /* MEM_43_INFLS_JOB_NONE */
                JobResult = MEM_43_INFLS_JOB_FAILED;
                break;
        };

        if ( (MEM_43_INFLS_JOB_OK == JobResult) && (0U != JobInfo->Length) )
        {
            /* The current chunk has completed but there is still data to process, need more MainFunction calls */
            JobResult = MEM_43_INFLS_JOB_PENDING;
        }
    }

    return JobResult;
}


/**
 * @brief    Process the pending job for the mem instance
 */
static void Mem_43_InFls_ProcessRequestedJobs(uint32 InstanceIndex)
{
    Mem_43_InFls_JobRuntimeInfoType *JobInfo = &(Mem_43_InFls_eJobRuntimeInfo[InstanceIndex]);
    Mem_43_InFls_JobResultType     JobResult = MEM_43_INFLS_JOB_OK;

    if ((JobInfo->JobFlags & MEM_43_INFLS_JOB_FLAG_STARTED) != 0U)
    {
        /* Clear any previous suspended job */
        JobResult = Mem_43_InFls_IPW_AbortSuspended(InstanceIndex, JobInfo->JobType);
        /* Clear flag */
        JobInfo->JobFlags &=  ~((uint8)MEM_43_INFLS_JOB_FLAG_STARTED);
    }
    else
    {
        /* Check the status of the job is being processed in the low-level driver */
        JobResult = Mem_43_InFls_IPW_GetJobResult(InstanceIndex, JobInfo->JobType);
    }

    if (MEM_43_INFLS_JOB_OK == JobResult)
    {
        /* The previous pending job has been done, launch new operation */
        JobResult = Mem_43_InFls_DoRequestedJobs(InstanceIndex, JobInfo);
    }

    /* Update the latest job result */
    JobInfo->JobResult = JobResult;
}


/*==================================================================================================
                                       GLOBAL FUNCTIONS (Synchronous Functions)
==================================================================================================*/

/**
 * @brief        The function initializes Mem_43_InFls module.
 *
 * @details      Initialization function - initializes all variables
 *               and sets the module state to initialized.
 *
 * @param[in]    ConfigPtr        Pointer to the configuration data structure - since Mem_43_InFls driver
 *                                is a precompile module this parameter is typically not used.
 *
 * @param[inout] None
 *
 * @param[out]   None
 *
 * @return       None
 *
 * @pre          None
 *
 * @api
 *
 * @implements   Mem_43_InFls_Init_Activity
 */
void Mem_43_InFls_Init(const Mem_43_InFls_ConfigType * ConfigPtr)
{
    Mem_43_InFls_JobResultType JobResult = MEM_43_INFLS_JOB_OK;
    Std_ReturnType Status;
    uint32 InstanceIndex;

    if (NULL_PTR != ConfigPtr)
    {
        /* The ConfigPtr argument is not a NULL pointer */
        Mem_43_InFls_ReportDevError(0U, MEM_43_INFLS_INIT_ID, MEM_43_INFLS_E_PARAM_POINTER);
    }
    else
    {
        /* Initialize the Mem driver internal states and set the Mem driver job processing state to MEM_43_INFLS_JOB_OK */
        Mem_43_InFls_pConfigPtr = &Mem_43_InFls_Config;

        Status = Mem_43_InFls_ValidateConfigCRC();
        if ((Std_ReturnType)E_OK == Status)
        {
            /* Initialize low-level hardware */
            Status = Mem_43_InFls_IPW_Init();
        }

        if ((Std_ReturnType)E_OK != Status)
        {
            /* Mark the driver as un-initialized */
            Mem_43_InFls_pConfigPtr = NULL_PTR;
            JobResult = MEM_43_INFLS_JOB_FAILED;
        }

        /* Update job result */
        for (InstanceIndex = 0U; InstanceIndex < MEM_43_INFLS_MEM_INSTANCE_COUNT; InstanceIndex++)
        {
            Mem_43_InFls_eJobRuntimeInfo[InstanceIndex].JobResult = JobResult;
        }
    }
}


/**
 * @brief        The function de-initializes the Mem_43_InFls module.
 *
 * @details      De-initialize module. If there is still an access job pending,
 *               it is immediately terminated (using hardware cancel operation)
 *               and the Mem driver module state is set to uninitialized.
 *
 * @param[in]    None
 *
 * @param[inout] None
 *
 * @param[out]   None
 *
 * @return       None
 *
 * @api
 *
 * @pre          The Mem_43_InFls module must be re-initialized before it will accept
 *               any new job requests after this service is processed.
 *
 * @implements   Mem_43_InFls_DeInit_Activity
 */
void Mem_43_InFls_DeInit(void)
{
    uint32 InstanceIndex;
    Mem_43_InFls_JobResultType JobResult = MEM_43_INFLS_JOB_OK;

    /* Check if the driver has been initialized before */
    if (NULL_PTR != Mem_43_InFls_pConfigPtr)
    {
        /* Cancel any ongoing flash operations in the hardware */
        for (InstanceIndex = 0U; InstanceIndex < MEM_43_INFLS_MEM_INSTANCE_COUNT; InstanceIndex++)
        {
            /* Check if there was a pending job in each instance */
            if (MEM_43_INFLS_JOB_PENDING == Mem_43_InFls_eJobRuntimeInfo[InstanceIndex].JobResult)
            {
                /* Cancel the on-going job for this mem instance */
                JobResult = Mem_43_InFls_IPW_AbortSuspended(InstanceIndex, Mem_43_InFls_eJobRuntimeInfo[InstanceIndex].JobType);
            }

            /* Update job result */
            Mem_43_InFls_eJobRuntimeInfo[InstanceIndex].JobResult = JobResult;
            /* Update job JobType to MEM_43_INFLS_JOB_NONE */
            Mem_43_InFls_eJobRuntimeInfo[InstanceIndex].JobType   = MEM_43_INFLS_JOB_NONE;
        }

        /* De-initialize the Mem driver internal states */
        Mem_43_InFls_pConfigPtr = NULL_PTR;
    }
}


/**
 * @brief        Return the version information of the Mem module.
 *
 * @details      Version information includes:
 *               - Module Id
 *               - Vendor Id
 *               - Vendor specific version numbers
 *
 * @param[in]    None
 *
 * @param[inout] None
 *
 * @param[out]   VersionInfoPtr    Pointer to where to store the version information of this module.
 *
 * @return       None
 *
 * @api
 *
 * @implements    Mem_43_InFls_GetVersionInfo_Activity
 */
void Mem_43_InFls_GetVersionInfo(Std_VersionInfoType * VersionInfoPtr)
{
    if (NULL_PTR != VersionInfoPtr)
    {
        /* Return version information about Mem module */
        VersionInfoPtr->moduleID         = (uint16)MEM_43_INFLS_MODULE_ID;
        VersionInfoPtr->vendorID         = (uint16)MEM_43_INFLS_VENDOR_ID;
        VersionInfoPtr->sw_major_version =  (uint8)MEM_43_INFLS_SW_MAJOR_VERSION;
        VersionInfoPtr->sw_minor_version =  (uint8)MEM_43_INFLS_SW_MINOR_VERSION;
        VersionInfoPtr->sw_patch_version =  (uint8)MEM_43_INFLS_SW_PATCH_VERSION;
    }
    else
    {
        /* The VersionInfoPtr argument is a NULL pointer */
        Mem_43_InFls_ReportDevError(0U, MEM_43_INFLS_GETVERSIONINFO_ID, MEM_43_INFLS_E_PARAM_POINTER);
    }
}


/**
 * @brief        Returns the result of the most recent job.
 *
 * @details      Returns synchronously the result of the last job.
 *
 * @param[in]    InstanceId    ID of the related memory driver instance.
 *
 * @param[inout] None
 *
 * @param[out]   None
 *
 * @return       Mem_43_InFls_JobResultType    Most recent job result.
 *
 * @api
 *
 * @implements   Mem_43_InFls_GetJobResult_Activity
 */
Mem_43_InFls_JobResultType Mem_43_InFls_GetJobResult(Mem_43_InFls_InstanceIdType InstanceId)
{
    Mem_43_InFls_JobResultType JobResult = MEM_43_INFLS_JOB_FAILED;
    uint32 InstanceIndex;

    InstanceIndex = Mem_43_InFls_GetInstanceIndex(InstanceId);
    if (InstanceIndex != MEM_43_INFLS_MEM_INSTANCE_INDEX_INVALID)
    {
        /* Get the most recent job result of the according driver instance */
        JobResult = Mem_43_InFls_eJobRuntimeInfo[InstanceIndex].JobResult;
    }

    return JobResult;
}


/**
 * @brief        Suspends active memory operation using hardware mechanism.
 *
 * @details      If the suspend mechanism is not supported by hardware,
 *               implementation based on physical segmentation.
 *
 * @param[in]    InstanceId    ID of the related memory driver instance.
 *
 * @param[inout] None
 *
 * @param[out]   None
 *
 * @return       None
 *
 * @api
 *
 * @implements   Mem_43_InFls_Suspend_Activity
 */
void Mem_43_InFls_Suspend(Mem_43_InFls_InstanceIdType InstanceId)
{
    /* Not implemented yet */
    (void)InstanceId;
}


/**
 * @brief        Resumes suspended memory operation using hardware mechanism.
 *
 * @details      Resumes suspended memory operation using hardware mechanism.
 *
 * @param[in]    InstanceId    ID of the related memory driver instance.
 *
 * @param[inout] None
 *
 * @param[out]   None
 *
 * @return       None
 *
 * @api
 *
 * @implements   Mem_43_InFls_Resume_Activity
 */
void Mem_43_InFls_Resume(Mem_43_InFls_InstanceIdType InstanceId)
{
    /* Not implemented yet */
    (void)InstanceId;
}


/**
 * @brief        Propagates an ECC error to the memory upper layers
 *
 * @details      This service can be used to report an access error in case
 *               the Mem driver cannot provide the access error information - typically for ECC faults.
 *               It is called by the system ECC handler to propagate an ECC error to the memory upper layers.
 *
 * @param[in]    InstanceId    ID of the related memory driver instance.
 *
 * @param[inout] None
 *
 * @param[out]   None
 *
 * @return       None
 *
 * @api
 *
 * @implements   Mem_43_InFls_PropagateError_Activity
 */
void Mem_43_InFls_PropagateError(Mem_43_InFls_InstanceIdType InstanceId)
{
    /* Not implemented yet */
    (void)InstanceId;
}


/*==================================================================================================
                                       GLOBAL FUNCTIONS (Asynchronous Functions)
==================================================================================================*/

/**
 * @brief            Reads from flash memory.
 *
 * @details          Triggers a read job to copy the from the source address into the referenced destination data
 *                   buffer. The result of this service can be retrieved using the Mem_GetJobResult API. If the read
 *                   operation was successful, the result of the job is MEM_43_INFLS_JOB_OK. If the read operation failed,
 *                   the result of the job is either MEM_JOB_FAILED in case of a general error or MEM_ECC_
 *                   CORRECTED/MEM_ECC_UNCORRECTED in case of a correctable/uncorrectable ECC error.
 *
 * @param[in]        InstanceId            ID of the related memory driver instance
 * @param[in]        SourceAddress         Physical address to read data from.
 * @param[in]        Length                Read length in bytes.
 *
 * @param[out]       DestinationDataPtr    Destination memory pointer to store the read data
 *
 * @return           Std_ReturnType
 *                   - E_OK                   : The requested job has been accepted by the module.
 *                   - E_NOT_OK               : The requested job has not been accepted by the module.
 *                   - E_MEM_SERVICE_NOT_AVAIL: The service function is not implemented.
 *
 * @api
 *
 * @pre              The module has to be initialized.
 *
 * @implements       Mem_43_InFls_Read_Activity
 */
Std_ReturnType Mem_43_InFls_Read(
    Mem_43_InFls_InstanceIdType    InstanceId,
    Mem_43_InFls_AddressType       SourceAddress,
    Mem_43_InFls_DataType        * DestinationDataPtr,
    Mem_43_InFls_LengthType        Length
)
{
    Std_ReturnType RetVal = (Std_ReturnType)E_OK;
    uint32 ErrorId;

    /* Prepare for input parameter checking before update runtime information */
    Mem_43_InFls_JobRuntimeInfoType JobRequest;
    JobRequest.JobType = MEM_43_INFLS_JOB_READ;
    Mem_43_InFls_InitJobRequest(&JobRequest, InstanceId, SourceAddress, DestinationDataPtr, Length);

    /* Perform the input parameters checking */
    ErrorId = Mem_43_InFls_ValidateParamJobDataTransfer(&JobRequest);

    if (MEM_43_INFLS_E_OK == ErrorId)
    {
        /* Start of exclusive area */
        SchM_Enter_Mem_43_InFls_MEM_EXCLUSIVE_AREA_03();

        /* Configure the new job request to global runtime variable */
        ErrorId = Mem_43_InFls_ConfigureJobRequest(&JobRequest);

        /* End of exclusive area */
        SchM_Exit_Mem_43_InFls_MEM_EXCLUSIVE_AREA_03();
    }

    if (MEM_43_INFLS_E_OK != ErrorId)
    {
        /* Reject the requested job */
        RetVal = (Std_ReturnType)E_NOT_OK;
        /* Report the error */
        Mem_43_InFls_ReportDevError(InstanceId, MEM_43_INFLS_READ_ID, ErrorId);
    }

    return RetVal;
}


/**
 * @brief            Writes to flash memory.
 *
 * @details          Triggers a write job to store the passed data to the provided address area with given address
 *                   and length. The result of this service can be retrieved using the Mem_GetJobResult API. If the
 *                   write operation was successful, the job result is MEM_43_INFLS_JOB_OK. If there was an issue writing
 *                   the data, the result is MEM_FAILED.
 *
 * @param[in]        InstanceId            ID of the related memory driver instance
 * @param[in]        TargetAddress         Physical write address (aligned to page size).
 * @param[out]       SourceDataPtr         Source data pointer (aligned to page size).
 * @param[in]        Length                Write length in bytes (aligned to page size).
 *
 * @return           Std_ReturnType
 *                   - E_OK                   : The requested job has been accepted by the module.
 *                   - E_NOT_OK               : The requested job has not been accepted by the module.
 *                   - E_MEM_SERVICE_NOT_AVAIL: The service function is not implemented.
 *
 * @api
 *
 * @pre              The module has to be initialized.
 *
 * @implements       Mem_43_InFls_Write_Activity
 */
Std_ReturnType Mem_43_InFls_Write(
    Mem_43_InFls_InstanceIdType     InstanceId,
    Mem_43_InFls_AddressType        TargetAddress,
    const Mem_43_InFls_DataType   * SourceDataPtr,
    Mem_43_InFls_LengthType         Length
)
{
    Std_ReturnType RetVal = (Std_ReturnType)E_OK;
    uint32 ErrorId;

    /* Prepare for input parameter checking before update runtime information */
    Mem_43_InFls_JobRuntimeInfoType JobRequest;
    JobRequest.JobType = MEM_43_INFLS_JOB_WRITE;

    /* Clause added to fulfil MISRA Rule 11.8 */
    const Mem_43_InFls_AddressType SourceDataAddr = (Mem_43_InFls_AddressType)&(SourceDataPtr[0]);

    Mem_43_InFls_InitJobRequest(&JobRequest, InstanceId, TargetAddress, (Mem_43_InFls_DataType *)(SourceDataAddr), Length);

    /* Perform the input parameters checking */
    ErrorId = Mem_43_InFls_ValidateParamJobDataTransfer(&JobRequest);

    if (MEM_43_INFLS_E_OK == ErrorId)
    {
        /* Start of exclusive area */
        SchM_Enter_Mem_43_InFls_MEM_EXCLUSIVE_AREA_02();

        /* Configure the new job request to global runtime variable */
        ErrorId = Mem_43_InFls_ConfigureJobRequest(&JobRequest);

        /* End of exclusive area */
        SchM_Exit_Mem_43_InFls_MEM_EXCLUSIVE_AREA_02();
    }

    if (MEM_43_INFLS_E_OK != ErrorId)
    {
        /* Reject the requested job */
        RetVal = (Std_ReturnType)E_NOT_OK;
        /* Report the error */
        Mem_43_InFls_ReportDevError(InstanceId, MEM_43_INFLS_WRITE_ID, ErrorId);
    }

    return RetVal;
}


/**
 * @brief            Erase one or more complete flash sectors.
 *
 * @details          Triggers an erase job of the given sector/sector batch defined by targetAddress and length.
 *                   The result of this service can be retrieved using the Mem_GetJobResult API. If the erase operation
 *                   was successful, the result of the job is MEM_43_INFLS_JOB_OK. If the erase operation failed, e.g. due to
 *                   a hardware issue, the result of the job is MEM_JOB_FAILED.
 *
 * @param[in]        InstanceId            ID of the related memory driver instance
 * @param[in]        TargetAddress         Physical erase address (aligned to sector size).
 * @param[in]        Length                Erase length in bytes (aligned to sector size).
 *
 * @param[out]       None
 *
 * @return           Std_ReturnType
 *                   - E_OK                   : The requested job has been accepted by the module.
 *                   - E_NOT_OK               : The requested job has not been accepted by the module.
 *                   - E_MEM_SERVICE_NOT_AVAIL: The service function is not implemented.
 *
 * @api
 *
 * @pre              The module has to be initialized.
 *
 * @implements       Mem_43_InFls_Erase_Activity
 */
Std_ReturnType Mem_43_InFls_Erase(
    Mem_43_InFls_InstanceIdType    InstanceId,
    Mem_43_InFls_AddressType       TargetAddress,
    Mem_43_InFls_LengthType        Length
)
{
    Std_ReturnType RetVal = (Std_ReturnType)E_OK;
    uint32 ErrorId;

    /* Prepare for input parameter checking before update runtime information */
    Mem_43_InFls_JobRuntimeInfoType JobRequest;
    JobRequest.JobType = MEM_43_INFLS_JOB_ERASE;
    Mem_43_InFls_InitJobRequest(&JobRequest, InstanceId, TargetAddress, NULL_PTR, Length);

    /* Perform the input parameters checking */
    ErrorId = Mem_43_InFls_ValidateParamJobCommon(&JobRequest);

    if (MEM_43_INFLS_E_OK == ErrorId)
    {
        /* Start of exclusive area */
        SchM_Enter_Mem_43_InFls_MEM_EXCLUSIVE_AREA_01();

        /* Configure the new job request to global runtime variable */
        ErrorId = Mem_43_InFls_ConfigureJobRequest(&JobRequest);

        /* End of exclusive area */
        SchM_Exit_Mem_43_InFls_MEM_EXCLUSIVE_AREA_01();
    }

    if (MEM_43_INFLS_E_OK != ErrorId)
    {
        /* Reject the requested job */
        RetVal = (Std_ReturnType)E_NOT_OK;
        /* Report the error */
        Mem_43_InFls_ReportDevError(InstanceId, MEM_43_INFLS_ERASE_ID, ErrorId);
    }

    return RetVal;
}


/**
 * @brief            Verify whether a given memory area has been erased but not (yet) programmed.
 *
 * @details          Triggers a job to check the erased state of the page which is referenced by targetAddress.
 *                   The result of this service can be retrieved using the Mem_GetJobResult API. If the checked page is
 *                   blank, the result of the job is MEM_43_INFLS_JOB_OK. Otherwise, if the page is not blank, the result is
 *                   MEM_INCONSISTENT.
 *
 * @param[in]        InstanceId            ID of the related memory driver instance
 * @param[in]        TargetAddress         Physical blank check address.
 * @param[in]        Length                Blank check length.
 *
 * @param[out]       None
 *
 * @return           Std_ReturnType
 *                   - E_OK                   : The requested job has been accepted by the module.
 *                   - E_NOT_OK               : The requested job has not been accepted by the module.
 *                   - E_MEM_SERVICE_NOT_AVAIL: The service function is not implemented.
 *
 * @api
 *
 * @pre              The module has to be initialized.
 *
 * @implements       Mem_43_InFls_BlankCheck_Activity
 */
Std_ReturnType Mem_43_InFls_BlankCheck(
    Mem_43_InFls_InstanceIdType    InstanceId,
    Mem_43_InFls_AddressType       TargetAddress,
    Mem_43_InFls_LengthType        Length
)
{
    Std_ReturnType RetVal = (Std_ReturnType)E_OK;
    uint32 ErrorId;

    /* Prepare for input parameter checking before update runtime information */
    Mem_43_InFls_JobRuntimeInfoType JobRequest;
    JobRequest.JobType = MEM_43_INFLS_JOB_BLANK_CHECK;
    Mem_43_InFls_InitJobRequest(&JobRequest, InstanceId, TargetAddress, NULL_PTR, Length);

    /* Perform the input parameters checking */
    ErrorId = Mem_43_InFls_ValidateParamJobCommon(&JobRequest);

    if (MEM_43_INFLS_E_OK == ErrorId)
    {
        /* Start of exclusive area */
        SchM_Enter_Mem_43_InFls_MEM_EXCLUSIVE_AREA_04();

        /* Configure the new job request to global runtime variable */
        ErrorId = Mem_43_InFls_ConfigureJobRequest(&JobRequest);

        /* End of exclusive area */
        SchM_Exit_Mem_43_InFls_MEM_EXCLUSIVE_AREA_04();
    }

    if (MEM_43_INFLS_E_OK != ErrorId)
    {
        /* Reject the requested job */
        RetVal = (Std_ReturnType)E_NOT_OK;
        /* Report the error */
        Mem_43_InFls_ReportDevError(InstanceId, MEM_43_INFLS_BLANKCHECK_ID, ErrorId);
    }

    return RetVal;
}


/**
 * @brief            Trigger a hardware specific service.
 *
 * @details          Triggers a hardware specific memory driver job. DataPtr can be used to pass and return data to/
 *                   from this service. This service is just a dispatcher to the hardware specific service
 *                   implementation referenced by HwServiceId. The result of this service can be retrieved using the
 *                   Mem_GetJobResult API. If the hardware specific operation was successful, the result of the job
 *                   is MEM_43_INFLS_JOB_OK. If the hardware specific operation failed, the result of the job is MEM_JOB_FAILED.
 *
 * @param[in]        InstanceId            ID of the related memory driver instance
 * @param[in]        HwServiceId           Hardware specific service request identifier for dispatching the request.
 * @param[in]        DataPtr               Request specific data pointer.
 * @param[in]        LengthPtr             Size pointer of the data passed by dataPtr.
 *
 * @param[out]       None
 *
 * @return           Std_ReturnType
 *                   - E_OK                   : The requested job has been accepted by the module.
 *                   - E_NOT_OK               : The requested job has not been accepted by the module.
 *                   - E_MEM_SERVICE_NOT_AVAIL: The service function is not implemented.
 *
 * @api
 *
 * @pre              The module has to be initialized.
 *
 * @implements       Mem_43_InFls_HwSpecificService_Activity
 */
Std_ReturnType Mem_43_InFls_HwSpecificService(
    Mem_43_InFls_InstanceIdType     InstanceId,
    Mem_43_InFls_HwServiceIdType    HwServiceId,
    Mem_43_InFls_DataType         * DataPtr,
    Mem_43_InFls_LengthType       * LengthPtr
)
{
    Std_ReturnType RetVal = (Std_ReturnType)E_NOT_OK;

    /* Not implemented yet */
    (void)InstanceId;
    (void)HwServiceId;
    (void)DataPtr;
    (void)LengthPtr;

    return RetVal;
}


/*==================================================================================================
                                       GLOBAL FUNCTIONS (Scheduled Functions)
==================================================================================================*/

/**
 * @brief            Service to handle the requested jobs and the internal management operations.
 *
 * @details          Service to handle the requested jobs and the internal management operations.
 *
 * @param[in]    None
 *
 * @param[inout] None
 *
 * @param[out]   None
 *
 * @return       None
 *
 * @api
 *
 * @pre              The module has to be initialized.
 *
 * @note             This function have to be called cyclically by the Basic Software Module;
 *                   it will do nothing if there aren't pending job.
 *
 * @implements       Mem_43_InFls_MainFunction_Activity
 */
void Mem_43_InFls_MainFunction(void)
{
    uint32 InstanceIndex;

    /* SWS_BSW_00037 - If the module is not initialized and the main function is executed
       then no error shall be reported and the main function shall return immediately.
    */
    if (NULL_PTR != Mem_43_InFls_pConfigPtr)
    {
        for (InstanceIndex = 0U; InstanceIndex < MEM_43_INFLS_MEM_INSTANCE_COUNT; InstanceIndex++)
        {
            /* Check if there was a pending job in each instance */
            if (MEM_43_INFLS_JOB_PENDING == Mem_43_InFls_eJobRuntimeInfo[InstanceIndex].JobResult)
            {
                /* Process the requested job for this mem instance */
                Mem_43_InFls_ProcessRequestedJobs(InstanceIndex);
            }
        }
    }
}


#define MEM_43_INFLS_STOP_SEC_CODE
#include "Mem_43_InFls_MemMap.h"


#ifdef __cplusplus
}
#endif

/** @} */
