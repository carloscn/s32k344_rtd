/*==================================================================================================
*   Project              : RTD AUTOSAR 4.7
*   Platform             : CORTEXM
*   Peripheral           : HSE
*   Dependencies         : none
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
*   @file
*
*   @addtogroup CRYPTO
*   @{
*/

#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
*                                          INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Crypto_Util.h"
#include "SchM_Crypto.h"

/*==================================================================================================
*                                 SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define CRYPTO_UTIL_VENDOR_ID_C                     43
#define CRYPTO_UTIL_AR_RELEASE_MAJOR_VERSION_C      4
#define CRYPTO_UTIL_AR_RELEASE_MINOR_VERSION_C      7
#define CRYPTO_UTIL_AR_RELEASE_REVISION_VERSION_C   0
#define CRYPTO_UTIL_SW_MAJOR_VERSION_C              3
#define CRYPTO_UTIL_SW_MINOR_VERSION_C              0
#define CRYPTO_UTIL_SW_PATCH_VERSION_C              0

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/
/* Check if Crypto_Util source file and Crypto_Util header file are of the same vendor */
#if (CRYPTO_UTIL_VENDOR_ID_C != CRYPTO_UTIL_VENDOR_ID)
    #error "Crypto_Util.c and Crypto_Util.h have different vendor ids"
#endif

/* Check if Crypto_Util source file and Crypto_Util header file are of the same Autosar version */
#if ((CRYPTO_UTIL_AR_RELEASE_MAJOR_VERSION_C    != CRYPTO_UTIL_AR_RELEASE_MAJOR_VERSION) || \
     (CRYPTO_UTIL_AR_RELEASE_MINOR_VERSION_C    != CRYPTO_UTIL_AR_RELEASE_MINOR_VERSION) || \
     (CRYPTO_UTIL_AR_RELEASE_REVISION_VERSION_C != CRYPTO_UTIL_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Crypto_Util.c and Crypto_Util.h are different"
#endif

/* Check if Crypto_Util source file and Crypto_Util header file are of the same Software version */
#if ((CRYPTO_UTIL_SW_MAJOR_VERSION_C != CRYPTO_UTIL_SW_MAJOR_VERSION) || \
     (CRYPTO_UTIL_SW_MINOR_VERSION_C != CRYPTO_UTIL_SW_MINOR_VERSION) || \
     (CRYPTO_UTIL_SW_PATCH_VERSION_C != CRYPTO_UTIL_SW_PATCH_VERSION)    \
    )
    #error "Software Version Numbers of Crypto_Util.c and Crypto_Util.h are different"
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if Crypto_Util source file and SchM_Crypto header file are of the same Autosar version */
    #if ((CRYPTO_UTIL_AR_RELEASE_MAJOR_VERSION_C != SCHM_CRYPTO_AR_RELEASE_MAJOR_VERSION) || \
         (CRYPTO_UTIL_AR_RELEASE_MINOR_VERSION_C != SCHM_CRYPTO_AR_RELEASE_MINOR_VERSION)    \
        )
        #error "AutoSar Version Numbers of Crypto_Util.c and SchM_Crypto.h are different"
    #endif
#endif

/*==================================================================================================
*                           LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
*                                          LOCAL MACROS
==================================================================================================*/

#if ((STD_ON == CRYPTO_KEYS_EXIST) && (STD_ON == CRYPTO_ENABLE_REDIRECTION_SUPPORT))
/* Value used to as maximum size to iterate thorugh all possible redirectable IOs */
#define CRYPTO_IO_REDIRECTION_SIZE_U8                ((uint8)0x05U)
/* Values used to iterate thorugh all possible IOs */
#define CRYPTO_REDIRECT_CONFIG_PRIMARY_INPUT_U8      ((uint8)0x01U)
#define CRYPTO_REDIRECT_CONFIG_SECONDARY_INPUT_U8    ((uint8)0x02U)
#define CRYPTO_REDIRECT_CONFIG_TERTIARY_INPUT_U8     ((uint8)0x04U)
#define CRYPTO_REDIRECT_CONFIG_PRIMARY_OUTPUT_U8     ((uint8)0x10U)
#define CRYPTO_REDIRECT_CONFIG_SECONDARY_OUTPUT_U8   ((uint8)0x20U)
#endif /* ((STD_ON == CRYPTO_KEYS_EXIST) && (STD_ON == CRYPTO_ENABLE_REDIRECTION_SUPPORT)) */

/*==================================================================================================
*                                         LOCAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                         LOCAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                        GLOBAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                        GLOBAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                    LOCAL FUNCTION PROTOTYPES
==================================================================================================*/
#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"

#if (STD_ON == CRYPTO_ENABLE_REDIRECTION_SUPPORT)
static inline void Crypto_Util_RedirectInputOutput
(
    const Crypto_JobType*                         pJob,
    Crypto_JobPrimitiveIOUpdateType*              pJobPrimitiveIOUpdate,
    const Crypto_InputOutputRedirectionConfigType redirectionConfiguration
);
#endif /* (STD_ON == CRYPTO_ENABLE_REDIRECTION_SUPPORT) */ 

/*==================================================================================================
*                                         LOCAL FUNCTIONS
==================================================================================================*/
#if ((STD_ON == CRYPTO_KEYS_EXIST) && (STD_ON == CRYPTO_ENABLE_REDIRECTION_SUPPORT))
/**
* @brief           A function to redirect the selected input or output.
* @details         This function gets called only when the caller function has 
*                  all other redirection validations passed. The selected input
*                  will be redirected.
*
* @param[in]       pJob: Pointer to the job
* @param[out]      pJobPrimitiveIOUpdate: Pointer to the structure of inputs and outputs to be redirected
* @param[in]       redirectionConfiguration: Used to select the settings for the redirected input or output
* @returns         void
*
*
* @pre
*
*/
static inline void Crypto_Util_RedirectInputOutput
(
    const Crypto_JobType*                         pJob,
    Crypto_JobPrimitiveIOUpdateType*              pJobPrimitiveIOUpdate,
    const Crypto_InputOutputRedirectionConfigType redirectionConfiguration
)
{
    uint32         u32RedirectedKeyIdx                 = 0U;
    uint32         u32RedirectedKeyElemIdx             = 0U;
    uint32         u32SelectedKeyIdRedirectInfo        = 0U;
    uint32         u32SelectedKeyElementIdRedirectInfo = 0U;

    /* Assign the proper inputKeyId and inputKeyElementId */
    switch (redirectionConfiguration)
    {
        case CRYPTO_REDIRECT_CONFIG_PRIMARY_INPUT:
            u32SelectedKeyIdRedirectInfo        = pJob->jobRedirectionInfoRef->inputKeyId;
            u32SelectedKeyElementIdRedirectInfo = pJob->jobRedirectionInfoRef->inputKeyElementId;
            break;

        case CRYPTO_REDIRECT_CONFIG_SECONDARY_INPUT:
            u32SelectedKeyIdRedirectInfo        = pJob->jobRedirectionInfoRef->secondaryInputKeyId;
            u32SelectedKeyElementIdRedirectInfo = pJob->jobRedirectionInfoRef->secondaryInputKeyElementId;
            break;

        case CRYPTO_REDIRECT_CONFIG_TERTIARY_INPUT:
            u32SelectedKeyIdRedirectInfo        = pJob->jobRedirectionInfoRef->tertiaryInputKeyId;
            u32SelectedKeyElementIdRedirectInfo = pJob->jobRedirectionInfoRef->tertiaryInputKeyElementId;
            break;

        case CRYPTO_REDIRECT_CONFIG_PRIMARY_OUTPUT:
            u32SelectedKeyIdRedirectInfo        = pJob->jobRedirectionInfoRef->outputKeyId;
            u32SelectedKeyElementIdRedirectInfo = pJob->jobRedirectionInfoRef->outputKeyElementId;
            break;

        case CRYPTO_REDIRECT_CONFIG_SECONDARY_OUTPUT:
            u32SelectedKeyIdRedirectInfo        = pJob->jobRedirectionInfoRef->secondaryOutputKeyId;
            u32SelectedKeyElementIdRedirectInfo = pJob->jobRedirectionInfoRef->secondaryOutputKeyElementId;
            break;

        default:
            ; /* This line is never reached */
            break;
    }

    /* Take the key index and key element index. */
    u32RedirectedKeyIdx = Crypto_Util_GetKeyIdx(u32SelectedKeyIdRedirectInfo);

    /* Check if the u32RedirectedKeyIdx is valid */
    if(CRYPTO_INVALID_KEY_IDX_U32 != u32RedirectedKeyIdx)
    {
        u32RedirectedKeyElemIdx = Crypto_Util_GetKeyElementIdx (u32RedirectedKeyIdx, u32SelectedKeyElementIdRedirectInfo);

        /* Check if the u32RedirectedKeyElemIdx is valid */
        if(CRYPTO_INVALID_KEY_ELEMENT_IDX_U32 != u32RedirectedKeyElemIdx)
        {
            switch (redirectionConfiguration)
            {
                case CRYPTO_REDIRECT_CONFIG_PRIMARY_INPUT:
                    pJobPrimitiveIOUpdate->pInput                 = Crypto_aKeyElementList[u32RedirectedKeyElemIdx].pCryptoElementArray;
                    pJobPrimitiveIOUpdate->pInputLength           = Crypto_aKeyElementList[u32RedirectedKeyElemIdx].pu32CryptoElementActualSize;
                    break;

                case CRYPTO_REDIRECT_CONFIG_SECONDARY_INPUT:
                    pJobPrimitiveIOUpdate->pSecondaryInput        = Crypto_aKeyElementList[u32RedirectedKeyElemIdx].pCryptoElementArray;
                    pJobPrimitiveIOUpdate->pSecondaryInputLength  = Crypto_aKeyElementList[u32RedirectedKeyElemIdx].pu32CryptoElementActualSize;
                    break;

                case CRYPTO_REDIRECT_CONFIG_TERTIARY_INPUT:
                    pJobPrimitiveIOUpdate->pTertiaryInput         = Crypto_aKeyElementList[u32RedirectedKeyElemIdx].pCryptoElementArray;
                    pJobPrimitiveIOUpdate->pTertiaryInputLength   = Crypto_aKeyElementList[u32RedirectedKeyElemIdx].pu32CryptoElementActualSize;
                    break;

                case CRYPTO_REDIRECT_CONFIG_PRIMARY_OUTPUT:
                    pJobPrimitiveIOUpdate->pOutput                = Crypto_aKeyElementList[u32RedirectedKeyElemIdx].pCryptoElementArray;
                    /* Update the Crypto element actual size to max size. */
                    *(Crypto_aKeyElementList[u32RedirectedKeyElemIdx].pu32CryptoElementActualSize) = Crypto_aKeyElementList[u32RedirectedKeyElemIdx].u32CryptoKeyElementMaxSize;
                    pJobPrimitiveIOUpdate->pOutputLength          = Crypto_aKeyElementList[u32RedirectedKeyElemIdx].pu32CryptoElementActualSize;
                    break;

                case CRYPTO_REDIRECT_CONFIG_SECONDARY_OUTPUT:
                    pJobPrimitiveIOUpdate->pSecondaryOutput       = Crypto_aKeyElementList[u32RedirectedKeyElemIdx].pCryptoElementArray;
                    /* Update the Crypto element actual size to max size. */
                    *(Crypto_aKeyElementList[u32RedirectedKeyElemIdx].pu32CryptoElementActualSize) = Crypto_aKeyElementList[u32RedirectedKeyElemIdx].u32CryptoKeyElementMaxSize;
                    pJobPrimitiveIOUpdate->pSecondaryOutputLength = Crypto_aKeyElementList[u32RedirectedKeyElemIdx].pu32CryptoElementActualSize;
                    break;

                default:
                    ; /* This line is never reached */
                    break;
            }
        }
        else
        {
            ; /* u32RedirectedKeyElemIdx invalid */
        }
    }
    else
    {
        ; /* u32RedirectedKeyIdx invalid */
    }
}
#endif /* ((STD_ON == CRYPTO_KEYS_EXIST) && (STD_ON == CRYPTO_ENABLE_REDIRECTION_SUPPORT)) */

/*==================================================================================================
*                                        GLOBAL FUNCTIONS
==================================================================================================*/

#if (STD_ON == CRYPTO_KEYS_EXIST)
#if (STD_ON == CRYPTO_SPT_ECC_KEY_PAIR_GEN)
/**
* @brief           MemCompare function
* @details         MemCompare function
*
* @param[in]       pu8Source   - address of the destination
* @param[in]       pu8Dest     - address of the source
* @param[in]       u32Size   - size to be compared
*
* @returns         bResult   - Returned TRUE if the values are equal
*
*
* @pre
*
*/
boolean Crypto_Util_MemCmp
(
    const uint8* pu8Source,
    const uint8* pu8Dest,
    const uint32 u32Size
)
{
    /*Local variables used as result of compare(True - same, False - different)*/
    boolean bResult = TRUE;

    /*Check if the pointers given as arguments are valid*/
    if((NULL_PTR != pu8Source) && (NULL_PTR != pu8Dest))
    {
        /*Local variables used as loop index*/
        uint32 u32Index;

        /*Loop through the length of the memory locations*/
        for(u32Index = 0; u32Index < u32Size; u32Index++)
        {
            if (pu8Source[u32Index] == pu8Dest[u32Index])
            {
                /*Nothing to do, continue the check*/
            }
            else
            {
                /*Break the loop, values differ*/
                bResult = FALSE;
                break;
            }
        }
    }
    else
    {
        /*One or both arguments not valid, set the result of the operation to false*/
        bResult = FALSE;
    }
    return bResult;
}
#endif /* (STD_ON == CRYPTO_SPT_ECC_KEY_PAIR_GEN) */

#if ((STD_ON == CRYPTO_SPT_ECC_KEY_IMPORT) || (STD_ON == CRYPTO_SPT_ECC_KEY_EXPORT))
/**
* @brief           Crypto_Util_SwapArrayBytes Swap function for an array input
* @details         Crypto_Util_SwapArrayBytes Swap function will change endianness of input
*
* @param[in]       pu8Source: Address of the source
* @param[in]       u32Len:  Size of input in bytes
*
* @returns         void
*/
void Crypto_Util_SwapArrayBytes
(
    uint8* pu8Source,
    uint32 u32Len
)
{
    uint32         u32Start = (uint32)0U;
    uint32         u32End   = u32Len - 1U ;
    uint8          u8Temp   = (uint8)0U;

    if ((NULL_PTR != pu8Source) && ((uint32)0U != u32Len))
    {
        while (u32Start < u32End)
        {
            u8Temp            = pu8Source[u32Start];
            pu8Source[u32Start] = pu8Source[u32End];
            pu8Source[u32End]   = u8Temp;
            u32Start++;
            u32End--;
        }
    }
}


/**
* @brief           Crypto_Util_Memset copies a value to a specified address.
* @details         Crypto_Util_Memset copies the value u8Value to the first u32Size bytes  pointed to by the pointer pDest.
*
* @param[in]       pDest   - address of the destination
* @param[in]       u8Value - value to copy
* @param[in]       u32Size - size to be copied
*
* @returns         void
*/
void Crypto_Util_Memset
(
    uint8* pDest,
    uint8 u8Value,
    uint32 u32Size
)
{
    /*Check for NULL pointer*/
    if(NULL_PTR != pDest)
    {
        /*Local variable used as an index for loop counting*/
        uint32 u32Counter;

        /*Loop through the entire size*/
        for (u32Counter = 0U; u32Counter < u32Size; u32Counter++)
        {
            /*Set the desired value into the current location*/
            pDest[u32Counter] = u8Value;
        }
    }
    else
    {
        /*Nothing to do, invalid argument*/
    }
}
#endif /* ((STD_ON == CRYPTO_SPT_ECC_KEY_IMPORT) || (STD_ON == CRYPTO_SPT_ECC_KEY_EXPORT)) */
#endif /* (STD_ON == CRYPTO_KEYS_EXIST) */

/**
* @brief           Memcopy function
* @details         Memcopy function
*
* @param[in]       pu8Dest   - address of the destination
* @param[in]       pu8Source - address of the source
* @param[in]       u32Size - size to be copied
*
* @returns         void
*
*
* @pre
*
*/
void Crypto_Util_MemCpy8
(
    uint8*       pu8Dest,
    const uint8* pu8Source,
    uint32       u32Size
)
{
    /*Check if the pointers given as arguments are valid*/
    if((NULL_PTR != pu8Dest) && (NULL_PTR != pu8Source))
    {
        /*Local variable used as a loop index*/
        uint32 u32Index;

        /*Loop through the length of the memory*/
        for(u32Index = 0; u32Index < u32Size; u32Index++)
        {
            /*Copy the value from the source to destination*/
            pu8Dest[u32Index] = pu8Source[u32Index];
        }
    }
    else
    {
        /*Nothing to do, One or both arguments not valid*/
    }
}


/**
* @brief           Initialize the CDO job queues
* @details         Each CDO has 2 queues, one with free elements, the second containing jobs sorted by priority.
*                  For each of the CDO queues, only the first element (head) is stored, as each queue element has a reference to the next one.
*                  This function initializes the queues heads and chains the elements in the free jobs queues
*
* @param[in]       void
* @returns         void
*
*
* @pre
*
*/
void Crypto_Util_InitJobQueues(void)
{
    uint32 u32ObjectIdx;
    uint32 u32IdxQueueElement;

    for (u32ObjectIdx = 0U; u32ObjectIdx < (uint32)CRYPTO_NUMBER_OF_DRIVER_OBJECTS_U32; u32ObjectIdx++)
    {
        /* Initialize the head of queued jobs stating that no job is queued */
        Crypto_aObjectQueueList[u32ObjectIdx].u32HeadOfQueuedJobs = CRYPTO_JOB_QUEUE_NONE_U32;

        if (0U == Crypto_aDriverObjectList[u32ObjectIdx].u32CryptoQueueSize)
        {
            /* If CDO queue size is zero, mark the queue of free jobs as being empty. */
            Crypto_aObjectQueueList[u32ObjectIdx].u32HeadOfFreeJobs = CRYPTO_JOB_QUEUE_NONE_U32;
        }
        else
        {
            /* Initialize the CDO queue of free jobs by chaining all queue job elements */
            Crypto_aObjectQueueList[u32ObjectIdx].u32HeadOfFreeJobs = 0U;
            for (u32IdxQueueElement = 0U; u32IdxQueueElement < (Crypto_aDriverObjectList[u32ObjectIdx].u32CryptoQueueSize - 1U); u32IdxQueueElement++)
            {
                Crypto_aDriverObjectList[u32ObjectIdx].pQueuedJobs[u32IdxQueueElement].u32Next = u32IdxQueueElement + 1U;
            }
            /* Mark the last in the queue as pointing to no other next queue element */
            Crypto_aDriverObjectList[u32ObjectIdx].pQueuedJobs[u32IdxQueueElement].u32Next = CRYPTO_JOB_QUEUE_NONE_U32;
        }
    }
}

/**
* @brief           Adds a job in the jobs queue
* @details         Each CDO has 2 queues, one with free elements, the second containing jobs sorted by priority.
*                  For each of the CDO queues, only the first element (head) is stored, as each queue element has a reference to the next one.
*                  This function tries to find a free queue element and move it from the list of free jobs in the list of queued jobs
*
* @param[in]       u32ObjectIdx: identifier of the Crypto Driver Object to be used for queuing the job
* @param[in]       pJob:        pointer to the job to be queued
* @returns         boolean
*                   TRUE  - job has been queued
*                   FALSE - job could not be queued
*
*
* @pre
*
*/
boolean Crypto_Util_QueueJob
(
    uint32          u32ObjectIdx,
    Crypto_JobType* pJob
)
{
    uint32* pu32QueueSearch = &(Crypto_aObjectQueueList[u32ObjectIdx].u32HeadOfQueuedJobs);
    boolean bJobQueued   = FALSE;
    uint32  u32IdxQueueElementJob;
    uint32  u32TempIdxQueueElement;

    /* Enter critical section  */
    SchM_Enter_Crypto_CRYPTO_EXCLUSIVE_AREA_00();

    /* Check if there is at least one element in the free jobs queue */
    if (CRYPTO_JOB_QUEUE_NONE_U32 != Crypto_aObjectQueueList[u32ObjectIdx].u32HeadOfFreeJobs)
    {
        /* Take the first element from the queue of free jobs */
        u32IdxQueueElementJob = Crypto_aObjectQueueList[u32ObjectIdx].u32HeadOfFreeJobs;
        /* Set new value for head of free jobs queue as the next element in the queue */
        Crypto_aObjectQueueList[u32ObjectIdx].u32HeadOfFreeJobs = Crypto_aDriverObjectList[u32ObjectIdx].pQueuedJobs[u32IdxQueueElementJob].u32Next;
        /* Put the element taken from free jobs queue in the job queue, in the right position based on priority */
        while ((FALSE == bJobQueued) && (CRYPTO_JOB_QUEUE_NONE_U32 != *pu32QueueSearch))
        {
            if (pJob->jobInfo->jobPriority > Crypto_aDriverObjectList[u32ObjectIdx].pQueuedJobs[*pu32QueueSearch].pJob->jobInfo->jobPriority)
            {
                /* Save address of list element we are inserting the new job in front of */
                u32TempIdxQueueElement = *pu32QueueSearch;
                /* Need to insert the element here */
                *pu32QueueSearch = u32IdxQueueElementJob;

                Crypto_aDriverObjectList[u32ObjectIdx].pQueuedJobs[u32IdxQueueElementJob].u32Next = u32TempIdxQueueElement;
                /* Mark the job as queued */
                bJobQueued = TRUE;
            }
            /* Advance to the next element in the queue */
            pu32QueueSearch = &(Crypto_aDriverObjectList[u32ObjectIdx].pQueuedJobs[*pu32QueueSearch].u32Next);
        }
        /* If we looped through all elements containing queued jobs and did not find a place where to put the new element, add it at the end */
        if (FALSE == bJobQueued)
        {
            *pu32QueueSearch = u32IdxQueueElementJob;
            /* Mark the new added queue element as being the last one in the queue */
            Crypto_aDriverObjectList[u32ObjectIdx].pQueuedJobs[u32IdxQueueElementJob].u32Next = CRYPTO_JOB_QUEUE_NONE_U32;
        }
        /* Copy the job into the free queue element found */
        Crypto_aDriverObjectList[u32ObjectIdx].pQueuedJobs[u32IdxQueueElementJob].pJob = pJob;
        /* Mark the job as queued */
        bJobQueued = TRUE;
    }
    /* Exit critical section */
    SchM_Exit_Crypto_CRYPTO_EXCLUSIVE_AREA_00();

    return bJobQueued;
}

/**
* @brief           Dequeues the first job in the queue
* @details         Removes the first queued job (head) and adds it in the queue of free jobs
*
* @param[in]       u32ObjectIdx: identifier of the Crypto Driver Object to be used for dequeuing the job
* @returns         void
*
*
* @pre            Assumes that at least one element exists in the queued jobs
*
*/
void Crypto_Util_DequeueHeadJob
(
    uint32 u32ObjectIdx
)
{
    uint32 u32HeadOfQueuedJobs;
    uint32 u32HeadOfFreeJobs;

    /* Enter critical section  */
    SchM_Enter_Crypto_CRYPTO_EXCLUSIVE_AREA_01();

    u32HeadOfQueuedJobs = Crypto_aObjectQueueList[u32ObjectIdx].u32HeadOfQueuedJobs;
    u32HeadOfFreeJobs   = Crypto_aObjectQueueList[u32ObjectIdx].u32HeadOfFreeJobs;

    /* Move head of queued jobs to the next element in the queue */
    Crypto_aObjectQueueList[u32ObjectIdx].u32HeadOfQueuedJobs = Crypto_aDriverObjectList[u32ObjectIdx].pQueuedJobs[u32HeadOfQueuedJobs].u32Next;

    /* Add the removed head of queued jobs as being the head of queue of free jobs */
    Crypto_aObjectQueueList[u32ObjectIdx].u32HeadOfFreeJobs                         = u32HeadOfQueuedJobs;
    Crypto_aDriverObjectList[u32ObjectIdx].pQueuedJobs[u32HeadOfQueuedJobs].u32Next = u32HeadOfFreeJobs;

    /* Exit critical section */
    SchM_Exit_Crypto_CRYPTO_EXCLUSIVE_AREA_01();
}


/**
* @brief           Dequeues from the list of queued jobs the first found job with the given jobId
* @details         Searches the queued jobs for a job with a given jobId and if found, removes it
*
* @param[in]       u32ObjectIdx: identifier of the Crypto Driver Object to be used for dequeuing the job
* @param[in]       pJobInfo:       pointer to jobInfo structure containing the jobId to search for
* @returns         Std_ReturnType
*
*
* @pre
*
*/
Std_ReturnType Crypto_Util_DequeueJob
(
    uint32                    u32ObjectIdx,
    const Crypto_JobInfoType* pJobInfo
)
{
    Std_ReturnType RetVal = (Std_ReturnType)E_NOT_OK;
    uint32*        pu32QueueSearch;
    uint32         u32TempIdxQueueElement1;
    uint32         u32TempIdxQueueElement2;

    /* Check if there is at least one element in the list of queued jobs */
    if (CRYPTO_JOB_QUEUE_NONE_U32 != Crypto_aObjectQueueList[u32ObjectIdx].u32HeadOfQueuedJobs)
    {
        pu32QueueSearch = &(Crypto_aObjectQueueList[u32ObjectIdx].u32HeadOfQueuedJobs);
        /* Loop through entire list of queued jobs */
        while (CRYPTO_JOB_QUEUE_NONE_U32 != *pu32QueueSearch)
        {
            /* Check if the current looped job from the list of queued jobs has same jobId with the one received as parameter */
            if (pJobInfo->jobId == Crypto_aDriverObjectList[u32ObjectIdx].pQueuedJobs[*pu32QueueSearch].pJob->jobInfo->jobId)
            {
                /* Enter critical section  */
                SchM_Enter_Crypto_CRYPTO_EXCLUSIVE_AREA_02();

                /* Store temporary the value of the address of the element in array Crypto_aDriverObjectList[u32ObjectIdx].pQueuedJobs[] pointed by pu32QueueSearch */
                u32TempIdxQueueElement1 = *pu32QueueSearch;

                /* Found a job matching the same jobId. Remove it from the list of queued jobs */
                *pu32QueueSearch = Crypto_aDriverObjectList[u32ObjectIdx].pQueuedJobs[*pu32QueueSearch].u32Next;

                /* Add the removed element in in the list of free jobs */
                u32TempIdxQueueElement2 = Crypto_aObjectQueueList[u32ObjectIdx].u32HeadOfFreeJobs;

                Crypto_aObjectQueueList[u32ObjectIdx].u32HeadOfFreeJobs = u32TempIdxQueueElement1;

                Crypto_aDriverObjectList[u32ObjectIdx].pQueuedJobs[u32TempIdxQueueElement1].u32Next = u32TempIdxQueueElement2;

                /* Exit critical section */
                SchM_Exit_Crypto_CRYPTO_EXCLUSIVE_AREA_02();

                RetVal = (Std_ReturnType)E_OK;
                break;
            }
            /* Advance to the next element in the list of queued jobs, searching for the job to dequeue */
            pu32QueueSearch = &(Crypto_aDriverObjectList[u32ObjectIdx].pQueuedJobs[*pu32QueueSearch].u32Next);
        }
    }

    return RetVal;
}

#if (STD_ON == CRYPTO_KEYS_EXIST)
/**
* @brief           Checks if a key element ID is valid
* @details         Checks if a key element ID is valid and present inside the required key
*
* @param[in]       u32KeyIndex                          - index of the key containing the key element
* @param[in]       u32keyElementId                      - key element ID
* @returns         CRYPTO_INVALID_KEY_ELEMENT_IDX_U32:  - Request failed, keyElement not found
*                  All other values:                    - Request successful, keyElement found
*
* @pre
*
*/
uint32 Crypto_Util_GetKeyElementIdx
(
    uint32 u32KeyIndex,
    uint32 u32keyElementId
)
{
    uint32 u32RetVal = CRYPTO_INVALID_KEY_ELEMENT_IDX_U32;
    uint32 u32Counter;

    for (u32Counter = 0U; u32Counter < Crypto_aKeyList[u32KeyIndex].u32NumCryptoKeyElements; u32Counter++)
    {
        if (u32keyElementId == Crypto_aKeyElementList[Crypto_aKeyList[u32KeyIndex].pCryptoKeyElementList[u32Counter]].u32CryptoKeyElementId)
        {
            u32RetVal = Crypto_aKeyList[u32KeyIndex].pCryptoKeyElementList[u32Counter];
            break;
        }
    }

    return u32RetVal;
}
#endif /* (STD_ON == CRYPTO_KEYS_EXIST) */


/**
* @brief           A function to update or redirect inputs or outputs
* @details         This function updates all IOs and checks the redirectionConfiguration 
*                  to decide which input/output needs to be redirected.
*                  The redirection part is subjected to other validations inside
*                  the function.
*
* @param[in]       pJob: Pointer to the job
* @param[out]      pJobPrimitiveIOUpdate: Pointer to the structure of inputs and outputs to be redirected
* @returns         void
*
*
* @pre
*
*/
void Crypto_Util_UpdateInputOutput
(
    const Crypto_JobType*            pJob,
    Crypto_JobPrimitiveIOUpdateType* pJobPrimitiveIOUpdate
)
{
#if ((STD_ON == CRYPTO_KEYS_EXIST) && (STD_ON == CRYPTO_ENABLE_REDIRECTION_SUPPORT))
    uint8 u8Index;
    Crypto_InputOutputRedirectionConfigType redirectionConfiguration = CRYPTO_REDIRECT_CONFIG_PRIMARY_INPUT;
    /* Array of constant values used for IO redirection selection */
    const uint8 Crypto_IORedirectionConfig[CRYPTO_IO_REDIRECTION_SIZE_U8] =
    {
        CRYPTO_REDIRECT_CONFIG_PRIMARY_INPUT_U8,
        CRYPTO_REDIRECT_CONFIG_SECONDARY_INPUT_U8,
        CRYPTO_REDIRECT_CONFIG_TERTIARY_INPUT_U8,
        CRYPTO_REDIRECT_CONFIG_PRIMARY_OUTPUT_U8,
        CRYPTO_REDIRECT_CONFIG_SECONDARY_OUTPUT_U8
    };
#endif /* ((STD_ON == CRYPTO_KEYS_EXIST) && (STD_ON == CRYPTO_ENABLE_REDIRECTION_SUPPORT)) */

   /* Update the IOs with jobPrimitiveInputOutput information */
    pJobPrimitiveIOUpdate->pInput                  = pJob->jobPrimitiveInputOutput.inputPtr;
    pJobPrimitiveIOUpdate->pInputLength            = &(pJob->jobPrimitiveInputOutput.inputLength);

    pJobPrimitiveIOUpdate->pSecondaryInput         = pJob->jobPrimitiveInputOutput.secondaryInputPtr;
    pJobPrimitiveIOUpdate->pSecondaryInputLength   = &(pJob->jobPrimitiveInputOutput.secondaryInputLength);

    pJobPrimitiveIOUpdate->pTertiaryInput          = pJob->jobPrimitiveInputOutput.tertiaryInputPtr;
    pJobPrimitiveIOUpdate->pTertiaryInputLength    = &(pJob->jobPrimitiveInputOutput.tertiaryInputLength);

    pJobPrimitiveIOUpdate->pOutput                 = pJob->jobPrimitiveInputOutput.outputPtr;
    pJobPrimitiveIOUpdate->pOutputLength           = pJob->jobPrimitiveInputOutput.outputLengthPtr;

    pJobPrimitiveIOUpdate->pSecondaryOutput        = pJob->jobPrimitiveInputOutput.secondaryOutputPtr;
    pJobPrimitiveIOUpdate->pSecondaryOutputLength  = pJob->jobPrimitiveInputOutput.secondaryOutputLengthPtr;

#if ((STD_ON == CRYPTO_KEYS_EXIST) && (STD_ON == CRYPTO_ENABLE_REDIRECTION_SUPPORT))
    if (NULL_PTR != pJob->jobRedirectionInfoRef)
    {
        /* Loop through all inputs and outputs */
        for (u8Index = 0U; u8Index < CRYPTO_IO_REDIRECTION_SIZE_U8; u8Index++)
        {
            switch (Crypto_IORedirectionConfig[u8Index])
            {
                case CRYPTO_REDIRECT_CONFIG_PRIMARY_INPUT_U8:
                    redirectionConfiguration = CRYPTO_REDIRECT_CONFIG_PRIMARY_INPUT;
                    break;

                case CRYPTO_REDIRECT_CONFIG_SECONDARY_INPUT_U8:
                    redirectionConfiguration = CRYPTO_REDIRECT_CONFIG_SECONDARY_INPUT;
                    break;

                case CRYPTO_REDIRECT_CONFIG_TERTIARY_INPUT_U8:
                    redirectionConfiguration = CRYPTO_REDIRECT_CONFIG_TERTIARY_INPUT;
                    break;

                case CRYPTO_REDIRECT_CONFIG_PRIMARY_OUTPUT_U8:
                    redirectionConfiguration = CRYPTO_REDIRECT_CONFIG_PRIMARY_OUTPUT;
                    break;

                case CRYPTO_REDIRECT_CONFIG_SECONDARY_OUTPUT_U8:
                    redirectionConfiguration = CRYPTO_REDIRECT_CONFIG_SECONDARY_OUTPUT;
                    break;

                default:
                    ; /* This line is never reached */
                    break;
            }

            /* Check if the current IO is redirectable */
            if (TRUE == Crypto_Util_IsRedirectionSet(pJob->jobRedirectionInfoRef->redirectionConfig, redirectionConfiguration))
            {
                Crypto_Util_RedirectInputOutput(pJob, pJobPrimitiveIOUpdate, redirectionConfiguration);
            }
            else
            {
                ; /* No operation */
            }
        }
    }
    else
    {
        ; /* No operation */
    }
#endif /* ((STD_ON == CRYPTO_KEYS_EXIST) && (STD_ON == CRYPTO_ENABLE_REDIRECTION_SUPPORT)) */
}

#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */


