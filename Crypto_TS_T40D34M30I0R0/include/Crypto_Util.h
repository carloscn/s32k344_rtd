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

#ifndef CRYPTO_UTIL_H
#define CRYPTO_UTIL_H

/**
*   @file
*
*   @internal
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
#include "Crypto_Cfg.h"
#include "Crypto_Private.h"

/*==================================================================================================
*                                 SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define CRYPTO_UTIL_VENDOR_ID                       43
#define CRYPTO_UTIL_MODULE_ID                       114
#define CRYPTO_UTIL_AR_RELEASE_MAJOR_VERSION        4
#define CRYPTO_UTIL_AR_RELEASE_MINOR_VERSION        7
#define CRYPTO_UTIL_AR_RELEASE_REVISION_VERSION     0
#define CRYPTO_UTIL_SW_MAJOR_VERSION                3
#define CRYPTO_UTIL_SW_MINOR_VERSION                0
#define CRYPTO_UTIL_SW_PATCH_VERSION                0

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/
/* Check if Crypto_Util header file and Crypto configuration header file are of the same vendor */
#if (CRYPTO_UTIL_VENDOR_ID != CRYPTO_VENDOR_ID_CFG)
    #error "Crypto_Util.h and Crypto_Cfg.h have different vendor ids"
#endif

/* Check if Crypto_Util header file and Crypto configuration header file are of the same Autosar version */
#if ((CRYPTO_UTIL_AR_RELEASE_MAJOR_VERSION    != CRYPTO_AR_RELEASE_MAJOR_VERSION_CFG) || \
     (CRYPTO_UTIL_AR_RELEASE_MINOR_VERSION    != CRYPTO_AR_RELEASE_MINOR_VERSION_CFG) || \
     (CRYPTO_UTIL_AR_RELEASE_REVISION_VERSION != CRYPTO_AR_RELEASE_REVISION_VERSION_CFG) \
    )
    #error "AutoSar Version Numbers of Crypto_Util.h and Crypto_Cfg.h are different"
#endif

/* Check if Crypto_Util header file and Crypto configuration header file are of the same Software version */
#if ((CRYPTO_UTIL_SW_MAJOR_VERSION != CRYPTO_SW_MAJOR_VERSION_CFG) || \
     (CRYPTO_UTIL_SW_MINOR_VERSION != CRYPTO_SW_MINOR_VERSION_CFG) || \
     (CRYPTO_UTIL_SW_PATCH_VERSION != CRYPTO_SW_PATCH_VERSION_CFG) \
    )
    #error "Software Version Numbers of Crypto_Util.h and Crypto_Cfg.h are different"
#endif

/* Check if Crypto_Util header file and Crypto private header file are of the same vendor */
#if (CRYPTO_UTIL_VENDOR_ID != CRYPTO_VENDOR_ID_PRIVATE)
    #error "Crypto_Util.h and Crypto_Private.h have different vendor ids"
#endif

/* Check if Crypto_Util header file and Crypto private header file are of the same Autosar version */
#if ((CRYPTO_UTIL_AR_RELEASE_MAJOR_VERSION    != CRYPTO_AR_RELEASE_MAJOR_VERSION_PRIVATE) || \
     (CRYPTO_UTIL_AR_RELEASE_MINOR_VERSION    != CRYPTO_AR_RELEASE_MINOR_VERSION_PRIVATE) || \
     (CRYPTO_UTIL_AR_RELEASE_REVISION_VERSION != CRYPTO_AR_RELEASE_REVISION_VERSION_PRIVATE) \
    )
    #error "AutoSar Version Numbers of Crypto_Util.h and Crypto_Private.h are different"
#endif

/* Check if Crypto_Util header file and Crypto private header file are of the same Software version */
#if ((CRYPTO_UTIL_SW_MAJOR_VERSION != CRYPTO_SW_MAJOR_VERSION_PRIVATE) || \
     (CRYPTO_UTIL_SW_MINOR_VERSION != CRYPTO_SW_MINOR_VERSION_PRIVATE) || \
     (CRYPTO_UTIL_SW_PATCH_VERSION != CRYPTO_SW_PATCH_VERSION_PRIVATE)    \
    )
    #error "Software Version Numbers of Crypto_Util.h and Crypto_Private.h are different"
#endif
/*==================================================================================================
*                                            CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/
/* Value used to mark the end of a job queue */
#define CRYPTO_JOB_QUEUE_NONE_U32               ((uint32)0xFFFFFFFFU)

/* Reserved value associated with invalid Crypto Driver Object id */
#define CRYPTO_INVALID_CDO_IDX_U32              ((uint32)0xFFFFFFFFU)

#if (STD_ON == CRYPTO_KEYS_EXIST)
    /* Reserved value associated with invalid Crypto Key id */
    #define CRYPTO_INVALID_KEY_IDX_U32          ((uint32)0xFFFFFFFFU)

    /* Reserved value associated with invalid Crypto Key Element id */
    #define CRYPTO_INVALID_KEY_ELEMENT_IDX_U32  ((uint32)0xFFFFFFFFU)
#endif /* (STD_ON == CRYPTO_KEYS_EXIST) */

/* Function-like macro for getting the id of the partition the code is running on */
#if (STD_ON == CRYPTO_ENABLE_MULTICORE_SUPPORT)
    #define Crypto_Util_GetPartitionId()        ((uint32)OsIf_GetCoreID())
#else
    #define Crypto_Util_GetPartitionId()        ((uint32)0U)
#endif /* (STD_ON == CRYPTO_ENABLE_MULTICORE_SUPPORT) */

#if ((STD_ON == CRYPTO_SPT_KEY_DERIVE) || (STD_ON == CRYPTO_ENABLE_TLS12_DERIVE_SUPPORT))
    /* Index of the byte storing the Key Derive Algorithm value in the buffer of the CRYPTO_KE_KEYDERIVATION_ALGORITHM key element */
    #define CRYPTO_KEY_DERIVE_ALGORITHM_IDX             (0U)
#endif /* ((STD_ON == CRYPTO_SPT_KEY_DERIVE) || (STD_ON == CRYPTO_ENABLE_TLS12_DERIVE_SUPPORT)) */

#if (STD_ON == CRYPTO_ENABLE_TLS12_DERIVE_SUPPORT)
    /* Index of the Key Material Length (used in CRYPTO_ALGOFAM_CUSTOM_TLS12_KEY_EXPANSION) value in the buffer of the CRYPTO_KE_KEYDERIVATION_OUTPUT_SIZE key element */
    #define CRYPTO_TLS12_KEY_MATERIAL_LENGTH_IDX    (0U)
    /* Index of the IV Length (used in CRYPTO_ALGOFAM_CUSTOM_TLS12_KEY_EXPANSION) value in the buffer of the CRYPTO_KE_KEYDERIVATION_OUTPUT_SIZE key element */
    #define CRYPTO_TLS12_IV_LENGTH_IDX              (1U)
    /* Index of the Verify Data Length (used in CRYPTO_ALGOFAM_CUSTOM_TLS12_GENERATE_VERIFY_CLIENT/CRYPTO_ALGOFAM_CUSTOM_TLS12_GENERATE_VERIFY_SERVER) value in the buffer of the CRYPTO_KE_KEYDERIVATION_OUTPUT_SIZE key element */
    #define CRYPTO_TLS12_VERIFY_DATA_LENGTH_IDX     (0U)
#endif /* (STD_ON == CRYPTO_ENABLE_TLS12_DERIVE_SUPPORT) */


/* Max value of uint32 */
#define CRYPTO_UTIL_MAX_U32    ((uint32)0xFFFFFFFFU)

/*==================================================================================================
*                                              ENUMS
==================================================================================================*/

/*==================================================================================================
*                                  STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/
/* Structure typedef for the information about the redirected or updated IOs */
typedef struct 
{
    const uint8*      pInput;
    const uint32*     pInputLength;
    const uint8*      pSecondaryInput;
    const uint32*     pSecondaryInputLength;
    const uint8*      pTertiaryInput;
    const uint32*     pTertiaryInputLength;
    const uint8*      pOutput;
    uint32*           pOutputLength;
    const uint8*      pSecondaryOutput;
    uint32*           pSecondaryOutputLength;
} Crypto_JobPrimitiveIOUpdateType;

/*==================================================================================================
*                                  GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                       FUNCTION PROTOTYPES
==================================================================================================*/
#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"

/**
* @brief           Memcopy function
* @details         Memcopy function
*
* @param[in]       pu8Dest   - address of the destination
* @param[in]       pu8Source - address of the source
* @param[in]       u32Size   - size to be copied
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
);

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
void Crypto_Util_InitJobQueues(void);

/**
* @brief           Adds a job in the jobs queue
* @details         Adds a job in the jobs queue, if at least one element is found in the queue of free jobs. The job is inserted in the queue
*                  based on its priority
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
);

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
);

/**
* @brief           Dequeues from the list of queued jobs the first found job with the given jobId
* @details         Searches the queued jobs for a job with a given jobId and if found, removes it
*
* @param[in]       u32ObjectIdx: identifier of the Crypto Driver Object to be used for dequeuing the job
* @param[in]       pJobInfo:     pointer to jobInfo structure containing the jobId to search for
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
);

#if (STD_ON == CRYPTO_KEYS_EXIST)
#if (STD_ON == CRYPTO_SPT_ECC_KEY_PAIR_GEN)
boolean Crypto_Util_MemCmp
(
    const uint8* pu8Source,
    const uint8* pu8Dest,
    const uint32 u32Size
);
#endif /* (STD_ON == CRYPTO_SPT_ECC_KEY_PAIR_GEN) */

#if ((STD_ON == CRYPTO_SPT_ECC_KEY_IMPORT) || (STD_ON == CRYPTO_SPT_ECC_KEY_EXPORT))
void Crypto_Util_SwapArrayBytes
(
    uint8* pu8Source,
    uint32 u32Len
);

void Crypto_Util_Memset
(
    uint8* pDest,
    uint8 u8Value,
    uint32 u32Size
);
#endif /* ((STD_ON == CRYPTO_SPT_ECC_KEY_IMPORT) || (STD_ON == CRYPTO_SPT_ECC_KEY_EXPORT)) */
#endif /* (STD_ON == CRYPTO_KEYS_EXIST) */

#if (STD_ON == CRYPTO_KEYS_EXIST)
uint32 Crypto_Util_GetKeyElementIdx
(
    uint32 u32KeyIndex,
    uint32 u32keyElementId
);
#endif /* (STD_ON == CRYPTO_KEYS_EXIST) */


/**
* @brief           A function to update or redirect inputs or outputs
* @details         This function updates all IOs and checks the redirectionConfigType 
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
);

/*==================================================================================================
*                                       INLINE FUNCTION DEFINITIONS
==================================================================================================*/

#if (STD_ON == CRYPTO_KEYS_EXIST)
/**
* @brief           Function used for getting the index of a Crypto Key from the list of Crypto Keys based on the id 
* @details         Function created with the restrain of macro-like functions in mind. It receives a key ID and a 
*                  search is based on it. If found, the key Index will be returned, if not then Invalid key Index 
*                  will be returned
*
* @param[in]       u32KeyId: ID of the wanted key
* @returns         uint32
*
*
* @pre
*
*/
static inline uint32 Crypto_Util_GetKeyIdx
(
    uint32 u32KeyId
)
{
    /*Ternary condition used for safe-guarding key Index passing*/
    return ((u32KeyId < CRYPTO_NUMBER_OF_KEYS_U32) ? u32KeyId : CRYPTO_INVALID_KEY_IDX_U32);
}

/**
* @brief           Function used for getting the id of a Crypto Key inside the list of Crypto job
* @details         Function created with the restrain of macro-like functions in mind. It receives a pointer to
*                  to a Crypto job and will return the value of its Key ID 
*
* @param[in]       pJob: pointer to a Crypto Job structure
* @returns         uint32
*
*
* @pre
*
*/
static inline uint32 Crypto_Util_GetJobKey
(
    const Crypto_JobType* pJob
)
{
    /*Local variable used for returning the output*/
    uint32 u32ReturnValue = CRYPTO_UTIL_MAX_U32;
 
    /*Check for Null Pointer*/
    if(NULL_PTR != pJob)
    {
        /*Set the return value*/
        #if (STD_ON == CRYPTO_ENABLE_ALTERNATE_MAPPING_FOR_JOB_KEY)
        u32ReturnValue = pJob->cryptoKeyId;
        #else
        u32ReturnValue = pJob->jobPrimitiveInfo->cryIfKeyId;
        #endif
    }
    else
    {
        /*Nothing to do, CRYPTO_UTIL_MAX_U32 will be returned to make it clear that it's invalid*/
    }

    /*Get the id of the key inside the Crypto job*/
    return u32ReturnValue;
}

/**
* @brief           Function used for checking if a bit-flag is set or not inside an array bit-map value
* @details         Function created with the restrain of macro-like functions in mind. Based on an Index of the key,
*                  it verifies if the bit position afferent to the key is set inside an array position calculated by
*                  dividing the key to the size of the array type - u08
*
* @param[in]       keyIdx: Index of the Key
* @returns         boolean
*
*
* @pre
*
*/
static inline boolean Crypto_Util_IsKeyValidFlagSet
(
    uint32 keyIdx
)
{
    /*Check if the flag on the bit position of keyIdx is set. The array holds 8 flags per index*/
    return ((boolean)((Crypto_au8NvramBlob0[(uint32)((keyIdx) / 8U)]  &  ((uint8)((uint8)1U<<((keyIdx) % 8U)))) != 0U));
}

/**
* @brief           Function used for clearing a bit-flag inside an array bit-map value
* @details         Function created with the restrain of macro-like functions in mind. Based on an Index of the key,
*                  it clears the bit whose position is afferent to the key inside an array position calculated by
*                  dividing the key to the size of the array type - u08
*
* @param[in]       keyIdx: Index of the Key
* @returns         void
*
*
* @pre
*
*/
static inline void Crypto_Util_ClearKeyValidFlag
(
    uint32 keyIdx
)
{
    /*Clear the flag on the bit position of keyIdx is set. The array holds 8 flags per index*/
    (Crypto_au8NvramBlob0[(uint32)((keyIdx) / 8U)] &= ~((uint8)((uint8)1U<<((keyIdx) % 8U))));
}
#endif

/**
* @brief           Function used for getting the index of a Crypto Driver Object
* @details         Function created with the restrain of macro-like functions in mind. It checks if
*                  if the ID is within the current list(the requested ID is not larger than the number
*                  of Crypto Driver Objects) then returns it, or if the condition is not met, it will return 
*                  invalid ID.
*
* @param[in]       u32DriverObjectId: Id to a Crypto Driver Object
* @returns         uint32
*
*
* @pre
*
*/
static inline uint32 Crypto_Util_GetObjectIdx
(
    uint32 u32DriverObjectId
)
{
    /*Ternary condition used for safe-guarding driver Object ID passing*/
    return (((u32DriverObjectId) < CRYPTO_NUMBER_OF_DRIVER_OBJECTS_U32) ? (u32DriverObjectId) : CRYPTO_INVALID_CDO_IDX_U32);
}

#if ((STD_ON == CRYPTO_KEYS_EXIST) && (STD_ON == CRYPTO_ENABLE_REDIRECTION_SUPPORT))
/**
* @brief           Function used for getting the redirection config type
* @details         Function created with the restrain of macro-like functions in mind. It checks if the sent 
*                  Configuration matches the configuration Type laid oud as a bit-map 
*
* @param[in]       u8RedirectionConfig:  Redirection Configuration
* @param[in]       redirectionType:      Redirection type
* @returns         boolean
*
*
* @pre
*
*/
static inline boolean Crypto_Util_IsRedirectionSet
(
    uint8                                   u8RedirectionConfig, 
    Crypto_InputOutputRedirectionConfigType redirectionType
)
{
    /*Compare the current configuration with a configuration type*/
    return ((boolean)(0U != ((uint8)(u8RedirectionConfig) & (uint8)(redirectionType))));
}
#endif

#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */

#endif /* CRYPTO_UTIL_H */


