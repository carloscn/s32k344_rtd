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
 * @file       Mem_43_InFls_Ipw.c
 *
 * @addtogroup MEM_43_INFLS Driver
 * implements  Mem_43_InFls_Ipw.c_Artifact
 *
 * @{
 */

#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
                                         INCLUDE FILES
 1) system and project includes
 2) needed interfaces from external units
 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Mem_43_InFls.h"
#include "Mem_43_InFls_Ipw.h"
#include "C40_Ip.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define MEM_43_INFLS_IPW_VENDOR_ID_C                           43
#define MEM_43_INFLS_IPW_AR_RELEASE_MAJOR_VERSION_C            4
#define MEM_43_INFLS_IPW_AR_RELEASE_MINOR_VERSION_C            7
#define MEM_43_INFLS_IPW_AR_RELEASE_REVISION_VERSION_C         0
#define MEM_43_INFLS_IPW_SW_MAJOR_VERSION_C                    3
#define MEM_43_INFLS_IPW_SW_MINOR_VERSION_C                    0
#define MEM_43_INFLS_IPW_SW_PATCH_VERSION_C                    0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and Mem_43_InFls.h header file are of the same vendor */
#if (MEM_43_INFLS_IPW_VENDOR_ID_C != MEM_43_INFLS_VENDOR_ID)
    #error "Mem_43_InFls_Ipw.c and Mem_43_InFls.h have different vendor ids"
#endif
/* Check if current file and Mem_43_InFls.h header file are of the same Autosar version */
#if ((MEM_43_INFLS_IPW_AR_RELEASE_MAJOR_VERSION_C    != MEM_43_INFLS_AR_RELEASE_MAJOR_VERSION) || \
     (MEM_43_INFLS_IPW_AR_RELEASE_MINOR_VERSION_C    != MEM_43_INFLS_AR_RELEASE_MINOR_VERSION) || \
     (MEM_43_INFLS_IPW_AR_RELEASE_REVISION_VERSION_C != MEM_43_INFLS_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Mem_43_InFls_Ipw.c and Mem_43_InFls.h are different"
#endif
/* Check if current file and Mem_43_InFls.h header file are of the same Software version */
#if ((MEM_43_INFLS_IPW_SW_MAJOR_VERSION_C != MEM_43_INFLS_SW_MAJOR_VERSION) || \
     (MEM_43_INFLS_IPW_SW_MINOR_VERSION_C != MEM_43_INFLS_SW_MINOR_VERSION) || \
     (MEM_43_INFLS_IPW_SW_PATCH_VERSION_C != MEM_43_INFLS_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Mem_43_InFls_Ipw.c and Mem_43_InFls.h are different"
#endif

/* Check if current file and Mem_43_InFls_Ipw.h header file are of the same vendor */
#if (MEM_43_INFLS_IPW_VENDOR_ID_C != MEM_43_INFLS_IPW_VENDOR_ID)
    #error "Mem_43_InFls_Ipw.c and Mem_43_InFls_Ipw.h have different vendor ids"
#endif
/* Check if current file and Mem_43_InFls_Ipw.h header file are of the same Autosar version */
#if ((MEM_43_INFLS_IPW_AR_RELEASE_MAJOR_VERSION_C    != MEM_43_INFLS_IPW_AR_RELEASE_MAJOR_VERSION) || \
     (MEM_43_INFLS_IPW_AR_RELEASE_MINOR_VERSION_C    != MEM_43_INFLS_IPW_AR_RELEASE_MINOR_VERSION) || \
     (MEM_43_INFLS_IPW_AR_RELEASE_REVISION_VERSION_C != MEM_43_INFLS_IPW_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Mem_43_InFls_Ipw.c and Mem_43_InFls_Ipw.h are different"
#endif
/* Check if current file and Mem_43_InFls_Ipw.h header file are of the same Software version */
#if ((MEM_43_INFLS_IPW_SW_MAJOR_VERSION_C != MEM_43_INFLS_IPW_SW_MAJOR_VERSION) || \
     (MEM_43_INFLS_IPW_SW_MINOR_VERSION_C != MEM_43_INFLS_IPW_SW_MINOR_VERSION) || \
     (MEM_43_INFLS_IPW_SW_PATCH_VERSION_C != MEM_43_INFLS_IPW_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Mem_43_InFls_Ipw.c and Mem_43_InFls_Ipw.h are different"
#endif

/* Check if current file and C40_Ip.h header file are of the same vendor */
#if (MEM_43_INFLS_IPW_VENDOR_ID_C != C40_IP_VENDOR_ID_H)
    #error "Mem_43_InFls_Ipw.c and C40_Ip.h have different vendor ids"
#endif
/* Check if current file and C40_Ip.h header file are of the same Autosar version */
#if ((MEM_43_INFLS_IPW_AR_RELEASE_MAJOR_VERSION_C    != C40_IP_AR_RELEASE_MAJOR_VERSION_H) || \
     (MEM_43_INFLS_IPW_AR_RELEASE_MINOR_VERSION_C    != C40_IP_AR_RELEASE_MINOR_VERSION_H) || \
     (MEM_43_INFLS_IPW_AR_RELEASE_REVISION_VERSION_C != C40_IP_AR_RELEASE_REVISION_VERSION_H) \
    )
    #error "AutoSar Version Numbers of Mem_43_InFls_Ipw.c and C40_Ip.h are different"
#endif
/* Check if current file and C40_Ip.h header file are of the same Software version */
#if ((MEM_43_INFLS_IPW_SW_MAJOR_VERSION_C != C40_IP_SW_MAJOR_VERSION_H) || \
     (MEM_43_INFLS_IPW_SW_MINOR_VERSION_C != C40_IP_SW_MINOR_VERSION_H) || \
     (MEM_43_INFLS_IPW_SW_PATCH_VERSION_C != C40_IP_SW_PATCH_VERSION_H) \
    )
    #error "Software Version Numbers of Mem_43_InFls_Ipw.c and C40_Ip.h are different"
#endif

/*==================================================================================================
                                       GLOBAL VARIABLES
==================================================================================================*/


/*==================================================================================================
 *                           LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/


/*==================================================================================================
                                       LOCAL VARIABLES
==================================================================================================*/


/*==================================================================================================
                                       LOCAL CONSTANTS
==================================================================================================*/


/*==================================================================================================
                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/

#define MEM_43_INFLS_START_SEC_CODE
#include "Mem_43_InFls_MemMap.h"


#define MEM_43_INFLS_STOP_SEC_CODE
#include "Mem_43_InFls_MemMap.h"


/*==================================================================================================
                                       LOCAL FUNCTIONS
==================================================================================================*/

#define MEM_43_INFLS_START_SEC_CODE
#include "Mem_43_InFls_MemMap.h"

/*
 * Description:    Get the memory unit index of the memory instance
 */
static inline uint32 Mem_43_InFls_IPW_GetMemoryUnitIndex(
    uint32    InstanceIndex
)
{
    /* Get the memory unit index */
    return ( Mem_43_InFls_pConfigPtr->MemInstances[InstanceIndex].MemUnitIndex );
}

/*
 * Description:    Update the job status after processing a chunk
 */
static void Mem_43_InFls_IPW_UpdateJobProcessedLength(
    Mem_43_InFls_JobRuntimeInfoType   *JobInfo,
    Mem_43_InFls_LengthType            TransferLength
)
{
    /* Move to the next chunk of job */
    JobInfo->Address += TransferLength;
    JobInfo->Length  -= TransferLength;

    /* Update data buffer pointer if required */
    if (NULL_PTR != JobInfo->DataPtr)
    {
        JobInfo->DataPtr = &(JobInfo->DataPtr[TransferLength]);
    }
}


/*
 * Description:    Compute the number of bytes to read for the current job.
 */
static Mem_43_InFls_LengthType Mem_43_InFls_IPW_ComputeReadLength(
    const Mem_43_InFls_JobRuntimeInfoType    *JobInfo
)
{
    Mem_43_InFls_LengthType ReadLength = JobInfo->Length;

    return ReadLength;
}


/**
 * @brief    Computes the size for an erase job.
 *           Based on physical hardware capability and device sector size boundary.
 */
static Mem_43_InFls_LengthType Mem_43_InFls_IPW_ComputeEraseLength(
    const Mem_43_InFls_JobRuntimeInfoType    *JobInfo
)
{
    Mem_43_InFls_LengthType EraseLength = JobInfo->SectorBatch->SectorSize;  /* default is normal size */
    const uint32 BurstSize           = JobInfo->SectorBatch->EraseBurstSize;

    /* Check for burst mode */
    if ( (0U == (JobInfo->Address % BurstSize)) &&
         (0U == (JobInfo->Length  % BurstSize))
       )
    {
        /* Both start address and length are aligned with the burst setting */
        EraseLength = BurstSize;
    }

    return EraseLength;
}


/**
 * @brief    Computes the size of the next chunk of a write job.
 *           Based on physical hardware capability and device page size boundary.
 */
static Mem_43_InFls_LengthType Mem_43_InFls_IPW_ComputeWriteLength(
    const Mem_43_InFls_JobRuntimeInfoType    *JobInfo
)
{
    uint32 WriteLength = JobInfo->Length;  /* the remaining length of the job */

    /* Check if chunk does not exceed IP driver capabilities */
    if (WriteLength > JobInfo->SectorBatch->WritePageSize)
    {
        WriteLength = JobInfo->SectorBatch->WritePageSize;
    }

    return WriteLength;
}


/**
 * @brief    Translate the return code from IPV to HLD.
 */
static Mem_43_InFls_JobResultType Mem_43_InFls_IPW_TranslateReturnCode(C40_Ip_StatusType IpReturnValue)
{
    Mem_43_InFls_JobResultType JobResult;

    switch (IpReturnValue)
    {
        case STATUS_C40_IP_BUSY:
            /* The job is still being processed */
            JobResult = MEM_43_INFLS_JOB_PENDING;
            break;

        case STATUS_C40_IP_SUCCESS:
            /* The job has completed */
            JobResult = MEM_43_INFLS_JOB_OK;
            break;

        default:
            /* Timeout or hardware errors */
            JobResult = MEM_43_INFLS_JOB_FAILED;
            break;
    }

    return JobResult;
}

/*==================================================================================================
                                       GLOBAL FUNCTIONS
==================================================================================================*/

/**
 * @brief        Mem_43_InFls_IPW_Init
 * @details      Initialize memory flash devices.
 */
Std_ReturnType Mem_43_InFls_IPW_Init(void)
{
    const Mem_43_InFls_InternalUnitType *InternalUnits = Mem_43_InFls_pConfigPtr->MemDevices->InternalUnits;
    Std_ReturnType RetVal = (Std_ReturnType)E_OK;
    C40_Ip_StatusType Status;
    uint32 Unit;

    for (Unit = 0U; Unit < MEM_43_INFLS_INTERNAL_UNIT_COUNT; Unit++)
    {
        if (NULL_PTR != InternalUnits[Unit].InternalConfig)
        {
            /* Use configuration "InternalConfig" to initialize C40 */
            Status = C40_Ip_Init(InternalUnits[Unit].InternalConfig);

            if (STATUS_C40_IP_SUCCESS != Status)
            {
                RetVal = (Std_ReturnType)E_NOT_OK;
                break;
            }
        }
    }

    return RetVal;
}


/**
 * @brief          IP wrapper read function.
 * @details        Route the read job to appropriate low level IP function.
 */
Mem_43_InFls_JobResultType Mem_43_InFls_IPW_Read(
    uint32                          InstanceIndex,
    Mem_43_InFls_JobRuntimeInfoType   *JobInfo
)
{
    Mem_43_InFls_JobResultType JobResult = MEM_43_INFLS_JOB_FAILED;
    Mem_43_InFls_LengthType TransferLength;
    C40_Ip_StatusType Status;

    if (JobInfo->Length == 0U)
    {
        /* No more data to read */
        JobResult = MEM_43_INFLS_JOB_OK;
    }
    else
    {
        /* Calculate length of data transfer */
        TransferLength = Mem_43_InFls_IPW_ComputeReadLength(JobInfo);

        /* Read data from flash memory device */
        Status = C40_Ip_Read(JobInfo->Address, TransferLength, JobInfo->DataPtr);

        if (STATUS_C40_IP_SUCCESS == Status)
        {
            /* The Read operations are SYNC, so the job result is OK immediately without PENDING state */
            JobResult = MEM_43_INFLS_JOB_PENDING;

            /* Update job state */
            Mem_43_InFls_IPW_UpdateJobProcessedLength(JobInfo, TransferLength);
        }
    }

    (void)InstanceIndex;

    return JobResult;
}


/**
 * @brief          IP wrapper blank check function.
 * @details        Route the blank check job to appropriate low level IP function.
 */
Mem_43_InFls_JobResultType Mem_43_InFls_IPW_BlankCheck(
    uint32                          InstanceIndex,
    Mem_43_InFls_JobRuntimeInfoType   *JobInfo
)
{
    Mem_43_InFls_JobResultType JobResult = MEM_43_INFLS_JOB_FAILED;
    Mem_43_InFls_LengthType TransferLength;
    C40_Ip_StatusType Status;

    if (JobInfo->Length == 0U)
    {
        /* No more data to check blank */
        JobResult = MEM_43_INFLS_JOB_OK;
    }
    else
    {
        /* Calculate length of data transfer */
        TransferLength = Mem_43_InFls_IPW_ComputeReadLength(JobInfo);

        /* Read data from flash memory device and verify that it is in erased state */
        Status = C40_Ip_Compare(JobInfo->Address, TransferLength, NULL_PTR);
        if (STATUS_C40_IP_SUCCESS == Status)
        {
            /* The Read operations are SYNC, so the job result is OK immediately without PENDING state */
            JobResult = MEM_43_INFLS_JOB_PENDING;

            /* Update job state */
            Mem_43_InFls_IPW_UpdateJobProcessedLength(JobInfo, TransferLength);
        }
        else
        {
            /* The memory area is not in the erased state */
            JobResult = MEM_43_INFLS_JOB_INCONSISTENT;
        }
    }

    (void)InstanceIndex;

    return JobResult;
}


/**
 * @brief          IP wrapper sector function.
 * @details        Route the erase job to appropriate low level IP function.
 */
Mem_43_InFls_JobResultType Mem_43_InFls_IPW_Erase(
    uint32                          InstanceIndex,
    Mem_43_InFls_JobRuntimeInfoType   *JobInfo
)
{
    Mem_43_InFls_JobResultType     JobResult = MEM_43_INFLS_JOB_FAILED;
    Mem_43_InFls_LengthType        TransferLength;
    C40_Ip_StatusType           Status;
    C40_Ip_VirtualSectorsType   VirtualSector;

    if (JobInfo->Length == 0U)
    {
        /* No more sector to erase */
        JobResult = MEM_43_INFLS_JOB_OK;
    }
    else
    {
        /* Calculate length of data transfer */
        TransferLength = Mem_43_InFls_IPW_ComputeEraseLength(JobInfo);

        /* Get the physical sector number */
        VirtualSector = C40_Ip_GetSectorNumberFromAddress(JobInfo->Address);

        /* Unlocks the Virtual Sector */
        Status = C40_Ip_ClearLock(VirtualSector, (uint8)MEM_43_INFLS_DOMAIN_ID);

        if (Status == STATUS_C40_IP_SUCCESS)
        {
            /* Call IP routine to erase internal flash memory sector */
            Status = C40_Ip_MainInterfaceSectorErase(VirtualSector, (uint8)MEM_43_INFLS_DOMAIN_ID);
        }

        if (STATUS_C40_IP_SUCCESS == Status)
        {
            /* Command is sent, the actual job is being processed in the memory device */
            JobResult = MEM_43_INFLS_JOB_PENDING;

            /* Update job state */
            Mem_43_InFls_IPW_UpdateJobProcessedLength(JobInfo, TransferLength);
        }
        else
        {
            /* Operation failed. Command is sent */
            JobResult = MEM_43_INFLS_JOB_FAILED;
        }
    }

    (void)InstanceIndex;

    return JobResult;
}


/**
 * @brief          IP wrapper sector write function.
 * @details        Route the write job to appropriate low level IP function.
 */
Mem_43_InFls_JobResultType Mem_43_InFls_IPW_Write(
    uint32                          InstanceIndex,
    Mem_43_InFls_JobRuntimeInfoType   *JobInfo
)
{
    Mem_43_InFls_JobResultType     JobResult = MEM_43_INFLS_JOB_FAILED;
    Mem_43_InFls_LengthType        TransferLength;
    C40_Ip_StatusType           Status;
    C40_Ip_VirtualSectorsType   VirtualSector;

    if (JobInfo->Length == 0U)
    {
        /* No more data to write */
        JobResult = MEM_43_INFLS_JOB_OK;
    }
    else
    {
        /* Calculate length of data transfer */
        TransferLength = Mem_43_InFls_IPW_ComputeWriteLength(JobInfo);

        /* Get the physical sector number */
        VirtualSector = C40_Ip_GetSectorNumberFromAddress(JobInfo->Address);

        /* Unlocks the Virtual Sector */
        Status = C40_Ip_ClearLock(VirtualSector, (uint8)MEM_43_INFLS_DOMAIN_ID);

        if (STATUS_C40_IP_SUCCESS == Status)
        {
            /* Call IP routine to write data to internal flash memory */
            Status = C40_Ip_MainInterfaceWrite(JobInfo->Address, TransferLength, JobInfo->DataPtr, (uint8)MEM_43_INFLS_DOMAIN_ID);
        }

        if (STATUS_C40_IP_SUCCESS == Status)
        {
            /* Command is sent, the actual job is being processed in the memory device */
            JobResult = MEM_43_INFLS_JOB_PENDING;

            /* Update job state */
            Mem_43_InFls_IPW_UpdateJobProcessedLength(JobInfo, TransferLength);
        }
        else
        {
            /* Operation failed. Command is sent */
            JobResult = MEM_43_INFLS_JOB_FAILED;
        }
    }

    (void)InstanceIndex;

    return JobResult;
}


/**
 * @brief    Returns synchronously the result of the last job.
 */
Mem_43_InFls_JobResultType Mem_43_InFls_IPW_GetJobResult(
    uint32               InstanceIndex,
    Mem_43_InFls_JobType JobType
)
{
    C40_Ip_StatusType          Status;
    Mem_43_InFls_JobResultType JobResult;

    switch (JobType)
    {
        case MEM_43_INFLS_JOB_ERASE:
            /* Process ongoing erase asynchronous hardware job. */
            Status = C40_Ip_MainInterfaceSectorEraseStatus();
            break;

        case MEM_43_INFLS_JOB_WRITE:
            /* Process ongoing write asynchronous hardware job. */
            Status = C40_Ip_MainInterfaceWriteStatus();
            break;

        default:
            Status = STATUS_C40_IP_SUCCESS;
            break;
    };

    JobResult = Mem_43_InFls_IPW_TranslateReturnCode(Status);
    (void)InstanceIndex;

    return JobResult;
}


/**
 * @brief       Abort a suspended hardware job to prepare for a new job.
 * @details     Check the hardware status and clear any suspended job.
 */
Mem_43_InFls_JobResultType Mem_43_InFls_IPW_AbortSuspended(
    uint32               InstanceIndex,
    Mem_43_InFls_JobType JobType
)
{
    C40_Ip_StatusType          Status = STATUS_C40_IP_SUCCESS;
    Mem_43_InFls_JobResultType JobResult;

    /* Check that job is being processed */
    if (MEM_43_INFLS_JOB_PENDING == Mem_43_InFls_IPW_GetJobResult(InstanceIndex, JobType))
    {
        /* Abort a program or erase operation */
        Status = C40_Ip_Abort();
    }

    JobResult = Mem_43_InFls_IPW_TranslateReturnCode(Status);

    return JobResult;
}


#define MEM_43_INFLS_STOP_SEC_CODE
#include "Mem_43_InFls_MemMap.h"


#ifdef __cplusplus
}
#endif

/** @} */
