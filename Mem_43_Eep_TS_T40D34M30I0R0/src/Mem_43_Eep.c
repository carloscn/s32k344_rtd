
/*==================================================================================================
* Project : RTD AUTOSAR 4.7
* Platform : CORTEXM
* Peripheral : IPV_USDHC
* Dependencies : 
*
* Autosar Version : 4.7.0
* Autosar Revision : ASR_REL_4_7_REV_0000
* Autosar Conf.Variant :
* SW Version : 3.0.0
* Build Version : S32K3_RTD_3_0_0_D2303_ASR_REL_4_7_REV_0000_20230331
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

/**
* @file
*
* @addtogroup MEM_43_EEP_DRIVER Mem_43_Eeprom Driver
* @{
*/
/*  Mem_43_Eep.c_Artifact */
#ifdef __cplusplus
extern "C"{
#endif

/* Compiler warning mem_43_eep_c_REF_CW_01: explicit cast discards volatile qualifier.
   The cast is explicit, intended and the casted value is treated properly.
   Sizes of the pointers and integral types for all the supported platforms/compilers are well known
   and the volatile keyword is not needed when using the pointer value as a mem_43_eeprom address counter,
   as the pointer value is not updated in the DSI interrupt context or by other hardware means.
*/

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Mem_43_Eep.h"
#include "Det.h"
#include "Mem_43_Eep_IPW.h"


/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define MEM_43_EEP_VENDOR_ID_C                      43
#define MEM_43_EEP_AR_RELEASE_MAJOR_VERSION_C       4
#define MEM_43_EEP_AR_RELEASE_MINOR_VERSION_C       7
#define MEM_43_EEP_AR_RELEASE_REVISION_VERSION_C    0
#define MEM_43_EEP_SW_MAJOR_VERSION_C               3
#define MEM_43_EEP_SW_MINOR_VERSION_C               0
#define MEM_43_EEP_SW_PATCH_VERSION_C               0


/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and Mem_43_Eep header file are of the same vendor */
#if (MEM_43_EEP_VENDOR_ID_C != MEM_43_EEP_VENDOR_ID)
    #error "Mem_43_Eep.c and Mem_43_Eep.h have different vendor ids"
#endif
/* Check if current file and Mem_43_Eep header file are of the same Autosar version */
#if ((MEM_43_EEP_AR_RELEASE_MAJOR_VERSION_C    != MEM_43_EEP_AR_RELEASE_MAJOR_VERSION) || \
     (MEM_43_EEP_AR_RELEASE_MINOR_VERSION_C    != MEM_43_EEP_AR_RELEASE_MINOR_VERSION) || \
     (MEM_43_EEP_AR_RELEASE_REVISION_VERSION_C != MEM_43_EEP_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Mem_43_Eep.c and Mem_43_Eep.h are different"
#endif
/* Check if current file and Mem_43_Eep header file are of the same Software version */
#if ((MEM_43_EEP_SW_MAJOR_VERSION_C != MEM_43_EEP_SW_MAJOR_VERSION) || \
     (MEM_43_EEP_SW_MINOR_VERSION_C != MEM_43_EEP_SW_MINOR_VERSION) || \
     (MEM_43_EEP_SW_PATCH_VERSION_C != MEM_43_EEP_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Mem_43_Eep.c and Mem_43_Eep.h are different"
#endif

/* Check if current file and Mem_43_Eep_IPW header file are of the same vendor */
#if (MEM_43_EEP_VENDOR_ID_C != MEM_43_EEP_IPW_VENDOR_ID_H)
    #error "Mem_43_Eep.c and Mem_43_Eep_IPW.h have different vendor ids"
#endif
/* Check if current file and Mem_43_Eep_IPW header file are of the same Autosar version */
#if ((MEM_43_EEP_AR_RELEASE_MAJOR_VERSION_C    != MEM_43_EEP_IPW_AR_RELEASE_MAJOR_VERSION_H) || \
     (MEM_43_EEP_AR_RELEASE_MINOR_VERSION_C    != MEM_43_EEP_IPW_AR_RELEASE_MINOR_VERSION_H) || \
     (MEM_43_EEP_AR_RELEASE_REVISION_VERSION_C != MEM_43_EEP_IPW_AR_RELEASE_REVISION_VERSION_H) \
    )
    #error "AutoSar Version Numbers of Mem_43_Eep.c and Mem_43_Eep_IPW.h are different"
#endif
/* Check if current file and Mem_43_Eep_IPW header file are of the same Software version */
#if ((MEM_43_EEP_SW_MAJOR_VERSION_C != MEM_43_EEP_IPW_SW_MAJOR_VERSION_H) || \
     (MEM_43_EEP_SW_MINOR_VERSION_C != MEM_43_EEP_IPW_SW_MINOR_VERSION_H) || \
     (MEM_43_EEP_SW_PATCH_VERSION_C != MEM_43_EEP_IPW_SW_PATCH_VERSION_H) \
    )
    #error "Software Version Numbers of Mem_43_Eep.c and Mem_43_Eep_IPW.h are different"
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if current file and Det header file are of the same Autosar version */
    #if ((MEM_43_EEP_AR_RELEASE_MAJOR_VERSION_C != DET_AR_RELEASE_MAJOR_VERSION) || \
         (MEM_43_EEP_AR_RELEASE_MINOR_VERSION_C != DET_AR_RELEASE_MINOR_VERSION) \
        )
        #error "AutoSar Version Numbers of Mem_43_Eep.c and Det.h are different"
    #endif
#endif


/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
                                        LOCAL MACROS
==================================================================================================*/

/*==================================================================================================
                                       LOCAL CONSTANTS
==================================================================================================*/


/*==================================================================================================
                                       LOCAL VARIABLES
==================================================================================================*/

#define MEM_43_EEP_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "Mem_43_Eep_MemMap.h"

/**
* @brief Pointer to current mem_43_eeprom module configuration set
*/
static const Mem_43_Eep_ConfigType * Mem_43_Eep_pConfigPtr = NULL_PTR;

/* Information of the current processing job of each Mem instance */
static Mem_43_Eep_JobRuntimeInfoType    Mem_43_Eep_eJobRuntimeInfo[MEM_43_EEP_INSTANCE_COUNT];


#define MEM_43_EEP_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "Mem_43_Eep_MemMap.h"

#define MEM_43_EEP_START_SEC_VAR_CLEARED_32
#include "Mem_43_Eep_MemMap.h"

/**
* @brief Pointer to current mem_43_eeprom module configuration set
*
*/
static uint32 Mem_43_Eep_u32AccCRCremainder;


#define MEM_43_EEP_STOP_SEC_VAR_CLEARED_32
#include "Mem_43_Eep_MemMap.h"

#if (MEM_43_EEP_SERVICE_COMPARE == STD_ON)
#define MEM_43_EEP_START_SEC_VAR_CLEARED_32_NO_CACHEABLE
#include "Mem_43_Eep_MemMap.h"

/**
* @brief Physical compare check address.
*
*/
Mem_43_Eep_AddressType  Mem_43_Eep_Conpare_u32EepromAddrNeedsCompared = 0U;

#define MEM_43_EEP_STOP_SEC_VAR_CLEARED_32_NO_CACHEABLE
#include "Mem_43_Eep_MemMap.h"
#endif
/*==================================================================================================
                                       GLOBAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      GLOBAL VARIABLES
==================================================================================================*/

/*==================================================================================================
                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/
#define MEM_43_EEP_START_SEC_CODE
#include "Mem_43_Eep_MemMap.h"

static void Mem_43_Eep_InitAllVarriable(uint32 InstanceIndex);
static void Mem_43_Eep_AccumulateCRC(uint32 InputData);
static void Mem_43_Eep_ResetCRC(void);
static uint32 Mem_43_Eep_FinalizeCRC (void);
static void Mem_43_Eep_UpdateCRCreminder(Mem_43_Eep_CrcDataSizeType DataSize);
static Mem_43_Eep_CrcType Mem_43_Eep_CalcCfgCRC(void);
static Mem_43_Eep_JobResultType Mem_43_Eep_ProcessWriteJob(uint32 InstanceIndex);
static Mem_43_Eep_JobResultType Mem_43_Eep_ProcessReadJob(uint32 InstanceIndex);
static Mem_43_Eep_JobResultType Mem_43_Eep_ProcessBlankCheckJob(uint32 InstanceIndex);
static Mem_43_Eep_JobResultType Mem_43_Eep_ProcessEraseJob(uint32 InstanceIndex);
static Mem_43_Eep_JobResultType Mem_43_Eep_ProcessHwSpecificServiceJob(uint32 InstanceIndex);
static Mem_43_Eep_JobResultType Mem_43_Eep_ProcessRequestedJobs(Mem_43_Eep_JobType Job, uint32 instanceId);

#if (MEM_43_EEP_SERVICE_COMPARE == STD_ON)
static Mem_43_Eep_JobResultType Mem_43_Eep_ProcessCompareJob(uint32 InstanceIndex);
static Std_ReturnType Mem_43_Eep_Compare(Mem_43_Eep_InstanceIdType instanceId, Mem_43_Eep_AddressType u32EepromAddrNeedsCompared, Mem_43_Eep_DataType* dataPtr, Mem_43_Eep_LengthType length);
#endif

#define MEM_43_EEP_STOP_SEC_CODE
#include "Mem_43_Eep_MemMap.h"

/*==================================================================================================
                                       LOCAL FUNCTIONS
==================================================================================================*/
#define MEM_43_EEP_START_SEC_CODE
#include "Mem_43_Eep_MemMap.h"

/**
* @brief         Mem_43_Eep_InitAllVarriable
* @details       Initialize global variables to their default values
*
* @param[in]     void
*
* @return        void
* @pre           N/A
*/
static void Mem_43_Eep_InitAllVarriable(uint32 InstanceIndex)
{

    /* Initialize all global variable */
    Mem_43_Eep_eJobRuntimeInfo[InstanceIndex].Mem_43_Eep_u32MaxRead         = MEM_43_EEP_MAX_READ_BLOCK_SIZE;
    Mem_43_Eep_eJobRuntimeInfo[InstanceIndex].Mem_43_Eep_u32MaxWrite        = MEM_43_EEP_MAX_WRITE_BLOCK_SIZE;
    Mem_43_Eep_eJobRuntimeInfo[InstanceIndex].Mem_43_Eep_u32EepromAddrIt    = 0UL;
    Mem_43_Eep_eJobRuntimeInfo[InstanceIndex].Mem_43_Eep_u32RemainingLength = 0UL;
    Mem_43_Eep_eJobRuntimeInfo[InstanceIndex].Mem_43_Eep_eJobResult         = MEM_43_EEP_JOB_OK;
    Mem_43_Eep_eJobRuntimeInfo[InstanceIndex].Mem_43_Eep_eJob               = MEM_43_EEP_JOB_ERASE;
    Mem_43_Eep_eJobRuntimeInfo[InstanceIndex].Mem_43_Eep_pJobSrcAddrPtr     = NULL_PTR;

    /* Initialize CRC remainder */
    Mem_43_Eep_u32AccCRCremainder = 0U;
}

/**
* @brief        Function to handle cumulative CRC calculation over input data.
*
* @details      Handles cumulative CRC calculation over input 32-bit data, .
*
* @param[in]    inputData ... data to be CRC-ed
*
* @return       void
* @retval       None.
*
* @pre          Mem_43_Eep_ResetCRC() was executed before the first call of
*               Mem_43_Eep_AccumulateCRC().
*
*
*/
static void Mem_43_Eep_AccumulateCRC(uint32 InputData)
{
    if (0xFFFFU < InputData)
    {
        /* preparation for accumulation of higher 16 bits of the InputData */
        Mem_43_Eep_u32AccCRCremainder = (Mem_43_Eep_u32AccCRCremainder << 16U) | (InputData >> 16U);
        /* make 16-bit accumulated result (in lower 16-bits of Mem_43_Eep_u32AccCRCremainder) */
        Mem_43_Eep_UpdateCRCreminder(MEM_43_EEP_CRC_16_BITS);
    }

    if (0xFFU < InputData)
    {
        /* preparation for accumulation of lower 16 bits of the InputData */
        Mem_43_Eep_u32AccCRCremainder = (Mem_43_Eep_u32AccCRCremainder << 16U) | (InputData & 0x0000FFFFU);
        /* make 16-bit accumulated result (in lower 16-bits of Mem_43_Eep_u32AccCRCremainder) */
        Mem_43_Eep_UpdateCRCreminder(MEM_43_EEP_CRC_16_BITS);
    }
    else
    {
        /* optimization: only 8 LSB bits are processed */
        /* preparation for accumulation of lower 8 bits of the InputData */
        Mem_43_Eep_u32AccCRCremainder = (Mem_43_Eep_u32AccCRCremainder << 8U) | InputData;
        /* make 16-bit accumulated result (in lower 16-bits of Mem_43_Eep_u32AccCRCremainder) */
        Mem_43_Eep_UpdateCRCreminder(MEM_43_EEP_CRC_8_BITS);
    }
}


/**
* @brief        Function to reset CRC calculation.
*
* @details      Resets accumulated Mem_43_Eep_u32AccCRCremainder.
*
* @param[in]    void
*
* @return       void
* @retval       None.
*
* @pre          None.
*
*
*/
static void Mem_43_Eep_ResetCRC(void)
{
    Mem_43_Eep_u32AccCRCremainder = 0U;
}

/**
* @brief        Function to finalize CRC calculation.
*
* @details      Finalizes accumulated CRC computation and resturns the final
*               CRC checksum.
*
* @param[in]    void
*
* @return       uint32
* @retval       The final CRC checksum in the lower 16 bits.
*
* @pre          Mem_43_Eep_AccumulateCRC() was executed at least once before
*               calling Mem_43_Eep_FinalizeCRC().
*
*/
static uint32 Mem_43_Eep_FinalizeCRC(void)
{
    /* add the final 0x0000 to the remainder */
    Mem_43_Eep_u32AccCRCremainder = (Mem_43_Eep_u32AccCRCremainder << 16U);
    /* make the final 16-bit CRC */
    Mem_43_Eep_UpdateCRCreminder(MEM_43_EEP_CRC_16_BITS);

    return Mem_43_Eep_u32AccCRCremainder;
}

/**
* @brief        Function to perfom CRC calculation over input 32-bit data.
*
* @details      Process 32-bit data to 16-bit reminder.
*
* @param[in]    accDataPtr ... ptr to data to be processed
*
* @return       void
* @retval       None.
*
* @pre          Can be called only from Mem_43_Eep_AccumulateCRC().
*
*/

static void Mem_43_Eep_UpdateCRCreminder(Mem_43_Eep_CrcDataSizeType DataSize)
{
    uint32 CrcPolynomSft;
    uint32 LeadingOne;
    uint32 AccDataLoc;
    uint32 LeadingOneInitial;

    switch (DataSize)
    {
        case MEM_43_EEP_CRC_8_BITS:
            CrcPolynomSft = 0x11021U << 7U; /* shifted CRC-16-CCITT (x.25 protocol)*/
            LeadingOneInitial = 0x10000U << 7U;
            break;
        case MEM_43_EEP_CRC_16_BITS:
        default:
            CrcPolynomSft = 0x11021U << 15U; /* shifted CRC-16-CCITT (x.25 protocol)*/
            LeadingOneInitial = 0x10000U << 15U;
            break;
    }

    /* copy static variable to auto (computation over static may be slow) */
    AccDataLoc = Mem_43_Eep_u32AccCRCremainder;

    /* CRC computation */
    for (LeadingOne = LeadingOneInitial; LeadingOne >= 0x00010000U; LeadingOne >>= 1U)
    {
        if ((AccDataLoc & LeadingOne) != 0U)
        {
            AccDataLoc ^= CrcPolynomSft;
        }
        CrcPolynomSft >>= 1U;
    }

    /* copy back to static variable */
    Mem_43_Eep_u32AccCRCremainder = AccDataLoc;
}


/**
 * @brief    Search the list of Mem instances and returns index of instance with matching InstanceId
 */
static uint32 Mem_43_Eep_GetInstanceIndex(const Mem_43_Eep_InstanceIdType InstanceId)
{
    uint32 InstanceIndex = MEM_43_EEP_INSTANCE_COUNT;
	uint32 Index = 0U;

    /* Loop through all configured memory instances */
    for (Index = 0U; Index < MEM_43_EEP_INSTANCE_COUNT; Index++)
    {
        if (InstanceId == Mem_43_Eep_pConfigPtr->MemInstances[Index].InstanceId)
        {
            /* InstanceId is matched, exit loop */
			InstanceIndex = Index;
            break;
        }
    }

    /* The returned value will be INVALID if InstanceId is not matched with any InstanceIndex */
    return InstanceIndex;
}


/**
 * @brief    Search for the sector batch that contains the provided address
 */
static const Mem_43_Eep_SectorBatchType * Mem_43_Eep_GetSectorBatch(
    uint32                   InstanceIndex,
    Mem_43_Eep_AddressType    Address
)
{
    const Mem_43_Eep_MemInstanceType *MemInstance = &(Mem_43_Eep_pConfigPtr->MemInstances[InstanceIndex]);
    const Mem_43_Eep_SectorBatchType *SectorBatch = MemInstance->SectorBatches;
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
* @brief        Calculates CRC over Mem_43_Eep configuration.
*
* @details      Calculates CRC over selected items of Mem_43_Eep configuration set
*               pointed to by ConfigPtr.
*
* @param[in]    ConfigPtr        Pointer to mem_43_eeprom driver configuration set.
*
* @return       uint32
* @retval       0 .. 0xFFFF (16-bit CRC using CRC-16-CCITT polynomial)
*
* @pre          Mem_43_Eep_pConfigPtr must not be properly initialized.
*
*/

static Mem_43_Eep_CrcType Mem_43_Eep_CalcCfgCRC(void)
{
    /* Reset the accumulated CRC value */
    Mem_43_Eep_ResetCRC();
    
    /* CRC - Accumulate Instance number */
    Mem_43_Eep_AccumulateCRC((uint32)Mem_43_Eep_pConfigPtr->pMem_43_EepSdConfig->usdhcConfig->instance);
    /* CRC - Accumulate cardDetectDat3 */
    Mem_43_Eep_AccumulateCRC((Mem_43_Eep_pConfigPtr->pMem_43_EepSdConfig->usdhcConfig->cardDetectDat3 == (boolean)TRUE)? 1U : 0U);
    /* CRC - Accumulate EnableAutoCMD12 */
    Mem_43_Eep_AccumulateCRC((Mem_43_Eep_pConfigPtr->pMem_43_EepSdConfig->usdhcConfig->EnableAutoCMD12 == (boolean)TRUE)? 1U : 0U);
    /* CRC - Accumulate endianMode */
    Mem_43_Eep_AccumulateCRC((uint32)Mem_43_Eep_pConfigPtr->pMem_43_EepSdConfig->usdhcConfig->endianMode);
    /* CRC - Accumulate dmaMode */
    Mem_43_Eep_AccumulateCRC((uint32)Mem_43_Eep_pConfigPtr->pMem_43_EepSdConfig->usdhcConfig->dmaMode);
    /* CRC - Accumulate admaTableSize */
    Mem_43_Eep_AccumulateCRC((uint32)Mem_43_Eep_pConfigPtr->pMem_43_EepSdConfig->usdhcConfig->admaTableSize);
    /* CRC - Accumulate writeWatermarkLevel */
    Mem_43_Eep_AccumulateCRC((uint32)Mem_43_Eep_pConfigPtr->pMem_43_EepSdConfig->usdhcConfig->writeWatermarkLevel);
    /* CRC - Accumulate readWatermarkLevel */
    Mem_43_Eep_AccumulateCRC((uint32)Mem_43_Eep_pConfigPtr->pMem_43_EepSdConfig->usdhcConfig->readWatermarkLevel);

    if (NULL_PTR != Mem_43_Eep_pConfigPtr->pMem_43_EepSdConfig->usdhcConfig->bootConfig)
    {
        /* CRC - Accumulate ackTimeout */
        Mem_43_Eep_AccumulateCRC((uint32)Mem_43_Eep_pConfigPtr->pMem_43_EepSdConfig->usdhcConfig->bootConfig->ackTimeout);
        /* CRC - Accumulate bootMode */
        Mem_43_Eep_AccumulateCRC((uint32)Mem_43_Eep_pConfigPtr->pMem_43_EepSdConfig->usdhcConfig->bootConfig->bootMode);
        /* CRC - Accumulate stopBlockGapCount */
        Mem_43_Eep_AccumulateCRC((uint32)Mem_43_Eep_pConfigPtr->pMem_43_EepSdConfig->usdhcConfig->bootConfig->stopBlockGapCount);
        /* CRC - Accumulate bootFlags */
        Mem_43_Eep_AccumulateCRC((uint32)Mem_43_Eep_pConfigPtr->pMem_43_EepSdConfig->usdhcConfig->bootConfig->bootFlags);
    }
    /* CRC - Accumulate SdConfigClock*/
    Mem_43_Eep_AccumulateCRC((uint32)Mem_43_Eep_pConfigPtr->pMem_43_EepSdConfig->SdConfigClock);
    /* CRC - Accumulate SdClockReference */
    Mem_43_Eep_AccumulateCRC((uint32)Mem_43_Eep_pConfigPtr->pMem_43_EepSdConfig->u32McuClock);

    return ((Mem_43_Eep_CrcType)Mem_43_Eep_FinalizeCRC());
}

#if (MEM_43_EEP_BLANKCHECK_API == STD_ON)
/**
* @brief        Pocess the blank check job
*
* @details      Compares data from Mem_43_Eep_eJobRuntimeInfo[InstanceIndex].Mem_43_Eep_pJobSrcAddrPtr to NULL_PTR
*               of lenth equal to Eep_u32MaxRead or Eep_u32RemainingLength.
*
* @param[in]
*
* @pre          The module must be initialized
*
*
*
*/
static Mem_43_Eep_JobResultType Mem_43_Eep_ProcessBlankCheckJob(uint32 InstanceIndex)
{
    Mem_43_Eep_JobResultType RetVal    = MEM_43_EEP_JOB_PENDING;
    Mem_43_Eep_BlankCheckType BlankCheckRetVal = MEM_43_EEP_BLANKCHECK_E_OK;
    Mem_43_Eep_LengthType BlankLength;

    /* the function will compare Mem_43_Eep_eJobRuntimeInfo[InstanceIndex].Mem_43_Eep_u32MaxRead or the remaining length */
    if (Mem_43_Eep_eJobRuntimeInfo[InstanceIndex].Mem_43_Eep_u32RemainingLength > Mem_43_Eep_eJobRuntimeInfo[InstanceIndex].Mem_43_Eep_u32MaxRead)
    {
        /* Eep_u32MaxWrite must be transferred */
        BlankLength = Mem_43_Eep_eJobRuntimeInfo[InstanceIndex].Mem_43_Eep_u32MaxRead;
    }
    else
    {
        /* Eep_u32RemainingLength must be transferred */
        BlankLength = Mem_43_Eep_eJobRuntimeInfo[InstanceIndex].Mem_43_Eep_u32RemainingLength;
    }

    /* if there is something to transfer */
    if (BlankLength > 0UL)
    {
        BlankCheckRetVal = Mem_43_Eep_Ipw_BlankCheck(Mem_43_Eep_eJobRuntimeInfo[InstanceIndex].Mem_43_Eep_u32EepromAddrIt, BlankLength, InstanceIndex);
    }

    /* update variables to be used for the next iteration */
    Mem_43_Eep_eJobRuntimeInfo[InstanceIndex].Mem_43_Eep_u32EepromAddrIt    = Mem_43_Eep_eJobRuntimeInfo[InstanceIndex].Mem_43_Eep_u32EepromAddrIt    + BlankLength;
    Mem_43_Eep_eJobRuntimeInfo[InstanceIndex].Mem_43_Eep_u32RemainingLength = Mem_43_Eep_eJobRuntimeInfo[InstanceIndex].Mem_43_Eep_u32RemainingLength - BlankLength;

    /* check status */
    if (MEM_43_EEP_BLANKCHECK_E_NOT_OK == BlankCheckRetVal)
    {
        /* job has failed */
        RetVal = MEM_43_EEP_JOB_FAILED;
    }

    if (MEM_43_EEP_BLANKCHECK_E_INCONSISTENT == BlankCheckRetVal)
    {
        /* comparison failed */
        RetVal = MEM_43_EEP_INCONSISTENT;
    }
    else if ((0UL == Mem_43_Eep_eJobRuntimeInfo[InstanceIndex].Mem_43_Eep_u32RemainingLength) && (MEM_43_EEP_BLANKCHECK_E_OK == BlankCheckRetVal))
    {
        /* the job is finished successfully */
        RetVal = MEM_43_EEP_JOB_OK;
    }
    else
    {
        /* do nothing */
    }

    return RetVal;
}
#endif

/**
* @brief        Pocess a read job
*
* @details      Reads data from Mem_43_Eep_eJobRuntimeInfo[InstanceIndex].Mem_43_Eep_u32EepromAddrIt to Mem_43_Eep_eJobRuntimeInfo[InstanceIndex].Mem_43_Eep_pJobSrcAddrPtr
*               of lenth equal to Mem_43_Eep_eJobRuntimeInfo[InstanceIndex].Mem_43_Eep_u32MaxRead or Mem_43_Eep_eJobRuntimeInfo[InstanceIndex].Mem_43_Eep_u32RemainingLength.
*
* @param[in]
*
* @pre          The module must be initialized
*
*
*
*/
static Mem_43_Eep_JobResultType Mem_43_Eep_ProcessReadJob(uint32 InstanceIndex)
{
    Mem_43_Eep_JobResultType RetVal    = MEM_43_EEP_JOB_PENDING;
    Std_ReturnType TransferRetVal = (Std_ReturnType)E_OK;
    Mem_43_Eep_LengthType TransfLength;

    /* transfer information to low level driver */
    /* the function will read Mem_43_Eep_eJobRuntimeInfo[InstanceIndex].Mem_43_Eep_u32MaxRead or the remaining length */
    /* compute length of transfer */
    if (Mem_43_Eep_eJobRuntimeInfo[InstanceIndex].Mem_43_Eep_u32RemainingLength > Mem_43_Eep_eJobRuntimeInfo[InstanceIndex].Mem_43_Eep_u32MaxRead)
    {
        /* Mem_43_Eep_eJobRuntimeInfo[InstanceIndex].Mem_43_Eep_u32MaxWrite must be transferred */
        TransfLength = Mem_43_Eep_eJobRuntimeInfo[InstanceIndex].Mem_43_Eep_u32MaxRead;
    }
    else
    {
        /* Mem_43_Eep_eJobRuntimeInfo[InstanceIndex].Mem_43_Eep_u32RemainingLength must be transferred */
        TransfLength = Mem_43_Eep_eJobRuntimeInfo[InstanceIndex].Mem_43_Eep_u32RemainingLength;
    }

    /* if there is something to transfer */
    if (TransfLength > 0UL)
    {
        TransferRetVal = Mem_43_Eep_Ipw_Read(Mem_43_Eep_eJobRuntimeInfo[InstanceIndex].Mem_43_Eep_u32EepromAddrIt, Mem_43_Eep_eJobRuntimeInfo[InstanceIndex].Mem_43_Eep_pJobSrcAddrPtr, TransfLength, InstanceIndex);
    }

    /* update variables to be used for the next iteration */
    Mem_43_Eep_eJobRuntimeInfo[InstanceIndex].Mem_43_Eep_pJobSrcAddrPtr  = &Mem_43_Eep_eJobRuntimeInfo[InstanceIndex].Mem_43_Eep_pJobSrcAddrPtr[TransfLength];
    Mem_43_Eep_eJobRuntimeInfo[InstanceIndex].Mem_43_Eep_u32EepromAddrIt    = Mem_43_Eep_eJobRuntimeInfo[InstanceIndex].Mem_43_Eep_u32EepromAddrIt    + TransfLength;
    Mem_43_Eep_eJobRuntimeInfo[InstanceIndex].Mem_43_Eep_u32RemainingLength = Mem_43_Eep_eJobRuntimeInfo[InstanceIndex].Mem_43_Eep_u32RemainingLength - TransfLength;

    /* check status */
    if ((Std_ReturnType)E_NOT_OK == TransferRetVal)
    {
        /* job has failed */
        RetVal = MEM_43_EEP_JOB_FAILED;
    }
    else if ((0UL == Mem_43_Eep_eJobRuntimeInfo[InstanceIndex].Mem_43_Eep_u32RemainingLength) && ((Std_ReturnType)E_OK == TransferRetVal))
    {
        /* the job is finished */
        RetVal = MEM_43_EEP_JOB_OK;
    }
    else
    {
        /* do nothing */
    }

    return RetVal;
}

/**
* @brief        Pocess a write job
*
* @details      Performs the write operation for a main function call.
*                Calls low level drivers for async or snc behavior.
*
* @param[in]
*
* @pre          The module must be initialized
*
*
*
*/
static Mem_43_Eep_JobResultType Mem_43_Eep_ProcessWriteJob(uint32 InstanceIndex)
{
    Mem_43_Eep_JobResultType RetVal    = MEM_43_EEP_JOB_PENDING;
    Std_ReturnType TransferRetVal = (Std_ReturnType)E_OK;

#if (MEM_43_EEP_ASYNC_WRITE_OPERATIONS_ENABLED == STD_OFF)
    Mem_43_Eep_LengthType TransfLength;

    /* transfer information to low level driver */
    /* the function will write Mem_43_Eep_eJobRuntimeInfo[InstanceIndex].Mem_43_Eep_u32MaxWrite or the remaining length */
    /* compute length of transfer */
    if (Mem_43_Eep_eJobRuntimeInfo[InstanceIndex].Mem_43_Eep_u32RemainingLength > Mem_43_Eep_eJobRuntimeInfo[InstanceIndex].Mem_43_Eep_u32MaxWrite)
    {
        /* Mem_43_Eep_eJobRuntimeInfo[InstanceIndex].Mem_43_Eep_u32MaxWrite must be transferred */
        TransfLength = Mem_43_Eep_eJobRuntimeInfo[InstanceIndex].Mem_43_Eep_u32MaxWrite;
    }
    else
    {
        /* Mem_43_Eep_eJobRuntimeInfo[InstanceIndex].Mem_43_Eep_u32RemainingLength must be transferred */
        TransfLength = Mem_43_Eep_eJobRuntimeInfo[InstanceIndex].Mem_43_Eep_u32RemainingLength;
    }

    /* if there is something to transfer */
    if (TransfLength > 0UL)
    {
        TransferRetVal = Mem_43_Eep_Ipw_Write(Mem_43_Eep_eJobRuntimeInfo[InstanceIndex].Mem_43_Eep_u32EepromAddrIt, Mem_43_Eep_eJobRuntimeInfo[InstanceIndex].Mem_43_Eep_pJobSrcAddrPtr, TransfLength, InstanceIndex);
    }

    /* update variables to be used for the next iteration */
    Mem_43_Eep_eJobRuntimeInfo[InstanceIndex].Mem_43_Eep_pJobSrcAddrPtr   = &Mem_43_Eep_eJobRuntimeInfo[InstanceIndex].Mem_43_Eep_pJobSrcAddrPtr[TransfLength];
    Mem_43_Eep_eJobRuntimeInfo[InstanceIndex].Mem_43_Eep_u32EepromAddrIt    = Mem_43_Eep_eJobRuntimeInfo[InstanceIndex].Mem_43_Eep_u32EepromAddrIt    + TransfLength;
    Mem_43_Eep_eJobRuntimeInfo[InstanceIndex].Mem_43_Eep_u32RemainingLength = Mem_43_Eep_eJobRuntimeInfo[InstanceIndex].Mem_43_Eep_u32RemainingLength - TransfLength;
#else
    /* in asynchronous mode in one main function call MEM_43_EEP
    * will trigger a hardware write operation for a 1,2, or 4 bytes page and return,
    * it will not wait for operation to finish */
    TransferRetVal = Mem_43_Eep_Ipw_Write(Mem_43_Eep_eJobRuntimeInfo[InstanceIndex].Mem_43_Eep_u32EepromAddrIt, Mem_43_Eep_eJobRuntimeInfo[InstanceIndex].Mem_43_Eep_pJobSrcAddrPtr, Mem_43_Eep_eJobRuntimeInfo[InstanceIndex].Mem_43_Eep_u32RemainingLength, InstanceIndex);
    /* Clear unused variable */
    (void)Mem_43_Eep_eJobRuntimeInfo[InstanceIndex].Mem_43_Eep_u32MaxWrite;

#endif /*#if (MEM_43_EEP_ASYNC_WRITE_OPERATIONS_ENABLED == STD_OFF)  */

    if ((Std_ReturnType)E_NOT_OK == TransferRetVal)
    {
        /* job has failed */
        RetVal = MEM_43_EEP_JOB_FAILED;
    }
#if (MEM_43_EEP_ASYNC_WRITE_OPERATIONS_ENABLED == STD_OFF)
    else if ((0UL == Mem_43_Eep_eJobRuntimeInfo[InstanceIndex].Mem_43_Eep_u32RemainingLength) && ((Std_ReturnType)E_OK == TransferRetVal))
#else
    else if ((Std_ReturnType)E_OK == TransferRetVal)
#endif /*#if (MEM_43_EEP_ASYNC_WRITE_OPERATIONS_ENABLED == STD_OFF)  */
    {
        /* the job is finished */
        RetVal = MEM_43_EEP_JOB_OK;
        /* job is done */
        Mem_43_Eep_eJobRuntimeInfo[InstanceIndex].Mem_43_Eep_u32RemainingLength = 0UL;
    }
    else
    {
        /* do nothing */
    }

    return RetVal;
}

/**
* @brief        Pocess a erase job
*
* @details      Performs the erase operation for a main function call.
*                Calls low level drivers for async or snc behavior.
*
* @param[in]
*
* @pre          The module must be initialized
*/
static Mem_43_Eep_JobResultType Mem_43_Eep_ProcessEraseJob(uint32 InstanceIndex)
{
    Mem_43_Eep_JobResultType RetVal    = MEM_43_EEP_JOB_PENDING;
    Std_ReturnType TransferRetVal = (Std_ReturnType)E_OK;

#if (MEM_43_EEP_ASYNC_ERASE_OPERATIONS_ENABLED == STD_OFF)
    Mem_43_Eep_LengthType u32TransfLength = 0UL;

    /* transfer information to low level driver */
    /* the function will write Mem_43_Eep_eJobRuntimeInfo[InstanceIndex].Mem_43_Eep_u32MaxWrite or the remaining length */
    /* compute length of transfer */
    if (Mem_43_Eep_eJobRuntimeInfo[InstanceIndex].Mem_43_Eep_u32RemainingLength > Mem_43_Eep_eJobRuntimeInfo[InstanceIndex].Mem_43_Eep_u32MaxWrite)
    {
        /* Mem_43_Eep_eJobRuntimeInfo[InstanceIndex].Mem_43_Eep_u32MaxWrite must be transferred */
        u32TransfLength = Mem_43_Eep_eJobRuntimeInfo[InstanceIndex].Mem_43_Eep_u32MaxWrite;
    }
    else
    {
        /* Mem_43_Eep_eJobRuntimeInfo[InstanceIndex].Mem_43_Eep_u32RemainingLength must be transferred */
        u32TransfLength = Mem_43_Eep_eJobRuntimeInfo[InstanceIndex].Mem_43_Eep_u32RemainingLength;
    }
    /* if there is something to transfer */
    if (u32TransfLength > 0UL)
    {
        TransferRetVal = Mem_43_Eep_Ipw_Erase(Mem_43_Eep_eJobRuntimeInfo[InstanceIndex].Mem_43_Eep_u32EepromAddrIt, u32TransfLength, InstanceIndex);
    }

    /* update variables to be used for the next iteration */
    Mem_43_Eep_eJobRuntimeInfo[InstanceIndex].Mem_43_Eep_u32EepromAddrIt = Mem_43_Eep_eJobRuntimeInfo[InstanceIndex].Mem_43_Eep_u32EepromAddrIt + u32TransfLength;
    Mem_43_Eep_eJobRuntimeInfo[InstanceIndex].Mem_43_Eep_u32RemainingLength = Mem_43_Eep_eJobRuntimeInfo[InstanceIndex].Mem_43_Eep_u32RemainingLength - u32TransfLength;
#else
    TransferRetVal = Mem_43_Eep_Ipw_Erase(Mem_43_Eep_eJobRuntimeInfo[InstanceIndex].Mem_43_Eep_u32EepromAddrIt, Mem_43_Eep_eJobRuntimeInfo[InstanceIndex].Mem_43_Eep_u32RemainingLength, InstanceIndex);
    /* Clear unused variable */
    (void)Mem_43_Eep_eJobRuntimeInfo[InstanceIndex].Mem_43_Eep_u32MaxWrite;

#endif /*#if (MEM_43_EEP_ASYNC_ERASE_OPERATIONS_ENABLED == STD_OFF)  */

    if ((Std_ReturnType)E_NOT_OK == TransferRetVal)
    {
        /* job has failed */
        RetVal = MEM_43_EEP_JOB_FAILED;
    }
    #if (MEM_43_EEP_ASYNC_ERASE_OPERATIONS_ENABLED == STD_OFF)
    else if ((0UL == Mem_43_Eep_eJobRuntimeInfo[InstanceIndex].Mem_43_Eep_u32RemainingLength) && ((Std_ReturnType)E_OK == TransferRetVal))
    #else
    else if ((Std_ReturnType)E_OK == TransferRetVal)
    #endif /*#if (MEM_43_EEP_ASYNC_ERASE_OPERATIONS_ENABLED == STD_OFF)  */
    {
        /* the job is finished */
        RetVal = MEM_43_EEP_JOB_OK;
        /* job is done */
        Mem_43_Eep_eJobRuntimeInfo[InstanceIndex].Mem_43_Eep_u32RemainingLength = 0UL;
    }
    else
    {
        /* do nothing */
    }

    return RetVal;
}

/**
* @brief        Process the HwSpecificService job
*
* @details      Process the HwSpecificService job with the corresponding serviceID stored in the variable Mem_43_Eep_eJobRuntimeInfo[InstanceIndex].Mem_43_Eep_u32HwServiceIdJob
*
* @param[in]
*
* @pre          The module must be initialized
*
*
*
*/
static Mem_43_Eep_JobResultType Mem_43_Eep_ProcessHwSpecificServiceJob(uint32 InstanceIndex)
{
    Mem_43_Eep_JobResultType RetVal    = MEM_43_EEP_JOB_FAILED;

#if (MEM_43_EEP_SERVICE_COMPARE == STD_ON)
    if(MEM_43_EEP_HWSERVICEID_COMPARE == Mem_43_Eep_eJobRuntimeInfo[InstanceIndex].Mem_43_Eep_u32HwServiceIdJob)
    {
        RetVal = Mem_43_Eep_ProcessCompareJob(InstanceIndex);
    }
#endif

    return RetVal;
}

#if (MEM_43_EEP_SERVICE_COMPARE == STD_ON)
/**
* @brief        Pocess the compare job
*
* @details      Compares data from Mem_43_Eep_pJobSrcAddrPtr to data from Mem_43_Eep_u32EepromAddrIt
*               of lenth equal to Mem_43_Eep_eJobRuntimeInfo[InstanceIndex].Mem_43_Eep_u32MaxRead or Mem_43_Eep_u32RemainingLength.
*
* @param[in]
*
* @pre          The module must be initialized
*
*
*
*/
static Mem_43_Eep_JobResultType Mem_43_Eep_ProcessCompareJob(uint32 InstanceIndex)
{
    Mem_43_Eep_JobResultType RetVal    = MEM_43_EEP_JOB_PENDING;
    Mem_43_Eep_CompareCheckType eCompareBlockRetVal = MEM_43_EEP_COMPARE_E_OK;
    Mem_43_Eep_LengthType TransfLength;

    /* the function will compare Mem_43_Eep_eJobRuntimeInfo[InstanceIndex].Mem_43_Eep_u32MaxRead or the remaining length */
    /* compute length of transfer */
    if (Mem_43_Eep_eJobRuntimeInfo[InstanceIndex].Mem_43_Eep_u32RemainingLength > Mem_43_Eep_eJobRuntimeInfo[InstanceIndex].Mem_43_Eep_u32MaxRead)
    {
        /* Mem_43_Eep_u32MaxWrite must be transferred */
        TransfLength = Mem_43_Eep_eJobRuntimeInfo[InstanceIndex].Mem_43_Eep_u32MaxRead;
    }
    else
    {
        /* Mem_43_Eep_eJobRuntimeInfo[InstanceIndex].Mem_43_Eep_u32RemainingLength must be transferred */
        TransfLength = Mem_43_Eep_eJobRuntimeInfo[InstanceIndex].Mem_43_Eep_u32RemainingLength;
    }

    /* if there is something to transfer */
    if (TransfLength > 0UL)
    {
        eCompareBlockRetVal = Mem_43_Eep_Ipw_CompareSync(Mem_43_Eep_eJobRuntimeInfo[InstanceIndex].Mem_43_Eep_u32EepromAddrIt, Mem_43_Eep_eJobRuntimeInfo[InstanceIndex].Mem_43_Eep_pJobDataDestPtr, TransfLength, InstanceIndex);
    }

    /* update variables to be used for the next iteration */
    Mem_43_Eep_eJobRuntimeInfo[InstanceIndex].Mem_43_Eep_pJobDataDestPtr   = &Mem_43_Eep_eJobRuntimeInfo[InstanceIndex].Mem_43_Eep_pJobDataDestPtr[TransfLength];
    Mem_43_Eep_eJobRuntimeInfo[InstanceIndex].Mem_43_Eep_u32EepromAddrIt    = Mem_43_Eep_eJobRuntimeInfo[InstanceIndex].Mem_43_Eep_u32EepromAddrIt    + TransfLength;
    Mem_43_Eep_eJobRuntimeInfo[InstanceIndex].Mem_43_Eep_u32RemainingLength = Mem_43_Eep_eJobRuntimeInfo[InstanceIndex].Mem_43_Eep_u32RemainingLength - TransfLength;

    /* check status */
    if (MEM_43_EEP_COMPARE_E_FAILED == eCompareBlockRetVal)
    {
        /* job has failed */
        RetVal = MEM_43_EEP_JOB_FAILED;
    }

    if (MEM_43_EEP_COMPARE_E_BLOCK_INCONSISTENT == eCompareBlockRetVal)
    {
        /* comparison failed */
        RetVal = MEM_43_EEP_INCONSISTENT;
    }
    else if ((0UL == Mem_43_Eep_eJobRuntimeInfo[InstanceIndex].Mem_43_Eep_u32RemainingLength) && (MEM_43_EEP_COMPARE_E_OK == eCompareBlockRetVal))
    {
        /* the job is finished successfully */
        RetVal = MEM_43_EEP_JOB_OK;
    }
    else
    {
        /* do nothing */
    }

    return RetVal;
}

static Std_ReturnType Mem_43_Eep_Compare(Mem_43_Eep_InstanceIdType instanceId,
                            Mem_43_Eep_AddressType u32EepromAddrNeedsCompared,
                            Mem_43_Eep_DataType* dataPtr,
                            Mem_43_Eep_LengthType length)
{
    Std_ReturnType RetVal = (Std_ReturnType) E_NOT_OK;
    const uint32 InstanceIndex = Mem_43_Eep_GetInstanceIndex(instanceId);

    if ((Std_ReturnType)E_NOT_OK == Mem_43_Eep_Ipw_CheckCompareParams(u32EepromAddrNeedsCompared, dataPtr, length, InstanceIndex))
    {
        RetVal = (Std_ReturnType) E_NOT_OK;
    }
    else
    {
        SchM_Enter_Mem_43_Eep_MEM_43_EEP_EXCLUSIVE_AREA_05();

        if (MEM_43_EEP_JOB_PENDING == Mem_43_Eep_eJobRuntimeInfo[InstanceIndex].Mem_43_Eep_eJobResult)
        {
#if (MEM_43_EEP_DEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError((uint16)MEM_43_EEP_MODULE_ID, (uint8)InstanceIndex, MEM_43_EEP_HWSPECIFICSERVICE_ID, MEM_43_EEP_E_JOB_PENDING);
#endif    /* MEM_43_EEP_DEV_ERROR_DETECT == STD_ON */
            RetVal =(Std_ReturnType) E_NOT_OK;
        }
        else
        {
            /* Configure the compare job */
            Mem_43_Eep_eJobRuntimeInfo[InstanceIndex].Mem_43_Eep_u32EepromAddrIt     = u32EepromAddrNeedsCompared;
            Mem_43_Eep_eJobRuntimeInfo[InstanceIndex].Mem_43_Eep_pJobDataDestPtr     = dataPtr;
            Mem_43_Eep_eJobRuntimeInfo[InstanceIndex].Mem_43_Eep_u32RemainingLength  = length;
            Mem_43_Eep_eJobRuntimeInfo[InstanceIndex].Mem_43_Eep_eJob                = MEM_43_EEP_JOB_HWSPECIFICSERVICE;
            /* Execute the compare job */
            Mem_43_Eep_eJobRuntimeInfo[InstanceIndex].Mem_43_Eep_eJobResult          = MEM_43_EEP_JOB_PENDING;

            RetVal = (Std_ReturnType) E_OK;
        }
        SchM_Exit_Mem_43_Eep_MEM_43_EEP_EXCLUSIVE_AREA_05();
    }

    return RetVal;
}
#endif


/*==================================================================================================
                                       GLOBAL FUNCTIONS
==================================================================================================*/

/**
* @brief        The function initializes Mem_43_Eep module.
* @details      Initialization function - initializes all variables and sets the module state to initialized.
*
* @param[in]    ConfigPtr: Pointer to the configuration data structure - since Mem_43_Eep driver is a
*                          precompile module this parameter is typically not used.
*
* @param[inout] None
* @param[out]   None
* @return  None
*
* @SYNC/ASYNC   SYNCHRONOUS
* @Reentrancy   Non Reentrant
*
* @api
*
* @pre          @p ConfigPtr must be @p NULL_PTR.
*
* @implements     Mem_43_Eep_Init_Activity
*
*/
void Mem_43_Eep_Init(const Mem_43_Eep_ConfigType * ConfigPtr)
{
    Std_ReturnType RetVal = (Std_ReturnType)E_OK;
    uint32 InstanceIndex = 0u;
#if (MEM_43_EEP_DEV_ERROR_DETECT == STD_ON)
    if(ConfigPtr != NULL_PTR)
    {
        (void) Det_ReportError((uint16)MEM_43_EEP_MODULE_ID, (uint8)InstanceIndex, MEM_43_EEP_INIT_ID, MEM_43_EEP_E_PARAM_POINTER);
    }
    else
    {
#endif
        (void)ConfigPtr;
        Mem_43_Eep_pConfigPtr = &Mem_43_Eep_Config;

        for (InstanceIndex = 0U; InstanceIndex < MEM_43_EEP_INSTANCE_COUNT; InstanceIndex++)
        {
            Mem_43_Eep_InitAllVarriable(InstanceIndex);

            /* check configuration CRC */
            if (Mem_43_Eep_pConfigPtr->u16ConfigCrc != Mem_43_Eep_CalcCfgCRC())
            {
            #if (MEM_43_EEP_DEV_ERROR_DETECT == STD_ON)
                (void) Det_ReportError((uint16)MEM_43_EEP_MODULE_ID, (uint8)0u, MEM_43_EEP_INIT_ID, MEM_43_EEP_E_UNINIT);
                Mem_43_Eep_pConfigPtr = NULL_PTR;
            #endif
                Mem_43_Eep_eJobRuntimeInfo[InstanceIndex].Mem_43_Eep_eJobResult = MEM_43_EEP_JOB_FAILED;
            }
            else
            {
                    RetVal = Mem_43_Eep_Ipw_Init(Mem_43_Eep_pConfigPtr, InstanceIndex);
                    if ((Std_ReturnType)E_NOT_OK == RetVal)
                {
                    Mem_43_Eep_eJobRuntimeInfo[InstanceIndex].Mem_43_Eep_eJobResult = MEM_43_EEP_JOB_FAILED;
                #if (MEM_43_EEP_DEV_ERROR_DETECT == STD_ON)
                    Mem_43_Eep_pConfigPtr = NULL_PTR;
                #endif
                }
                else
                {
                    Mem_43_Eep_eJobRuntimeInfo[InstanceIndex].Mem_43_Eep_eJobResult = MEM_43_EEP_JOB_OK;
                }
            }
        }
    }
}

/**
* @brief        The function deinitializes Mem_43_Eep module.
* @details      Deinitialization function - de initializes all variables and sets the module state to initialized.
*
* @param[in]    None
* @param[inout] None
* @param[out]   None
* @return       None
*
* @SYNC/ASYNC   SYNCHRONOUS
* @Reentrancy   Non Reentrant
*
* @api
*
* @pre 
*
* @implements     Mem_43_Eep_DeInit_Activity
*
*/
void Mem_43_Eep_DeInit(void)
{
    uint32 InstanceIndex = 0u;

    if ((Std_ReturnType)E_OK == Mem_43_Eep_Ipw_Cancel(InstanceIndex))
    {

        for (InstanceIndex = 0U; InstanceIndex < MEM_43_EEP_INSTANCE_COUNT; InstanceIndex++)
        {
            Mem_43_Eep_eJobRuntimeInfo[InstanceIndex].Mem_43_Eep_eJobResult = MEM_43_EEP_JOB_OK;
        }

        (void)Mem_43_Eep_Ipw_DeInit(Mem_43_Eep_pConfigPtr, 0u);
        Mem_43_Eep_pConfigPtr = NULL_PTR;
    }
#if (MEM_43_EEP_DEV_ERROR_DETECT == STD_ON)
    else
    {
        (void)Det_ReportError((uint16)MEM_43_EEP_MODULE_ID, (uint8)0u, MEM_43_EEP_INIT_ID, MEM_43_EEP_E_JOB_PENDING);
    }
#endif
}

#if (MEM_43_EEP_VERSION_INFO_API == STD_ON)
/**
* @brief        Returns version information about MEM_43_EEP module.
* @details      Version information includes:
*               - Module Id
*               - Vendor Id
*               - Vendor specific version numbers (BSW00407).
*
* @param[in,out] versionInfoPtr  Pointer to where to store the version information of this module.
*
* @api
*
* @implements       Mem_43_Eep_GetVersionInfo_Activity
*
*/
void Mem_43_Eep_GetVersionInfo(Std_VersionInfoType * versionInfoPtr)
{
#if (MEM_43_EEP_DEV_ERROR_DETECT == STD_ON)
    if (NULL_PTR == versionInfoPtr)
    {
        (void)Det_ReportError((uint16)MEM_43_EEP_MODULE_ID, (uint8)0u, MEM_43_EEP_GETVERSIONINFO_ID, MEM_43_EEP_E_PARAM_POINTER);
    }
    else
#endif /* MEM_43_EEP_DEV_ERROR_DETECT == STD_ON */
    {
        versionInfoPtr->moduleID = (uint16)MEM_43_EEP_MODULE_ID;
        versionInfoPtr->vendorID = (uint16)MEM_43_EEP_VENDOR_ID;
        versionInfoPtr->sw_major_version = (uint8)MEM_43_EEP_SW_MAJOR_VERSION;
        versionInfoPtr->sw_minor_version = (uint8)MEM_43_EEP_SW_MINOR_VERSION;
        versionInfoPtr->sw_patch_version = (uint8)MEM_43_EEP_SW_PATCH_VERSION;
    }
}
#endif

#if (MEM_43_EEP_GET_JOB_RESULT_API == STD_ON)
/**
 * @brief        Returns the result of the most recent job.
 *
 * @details      Returns synchronously the result of the last job.
 *
 * @param[in]    InstanceId    ID of the related memory driver instance.
 * @param[inout] None
 * @param[out]   None
 *
 * @return       Mem_43_Eep_JobResultType    Most recent job result.
 *
 * @api
 *
 * @implements   Mem_43_Eep_GetJobResult_Activity
 */
Mem_43_Eep_JobResultType Mem_43_Eep_GetJobResult(Mem_43_Eep_InstanceIdType InstanceId)
{
    Mem_43_Eep_JobResultType JobResult = MEM_43_EEP_JOB_FAILED;
    uint32 InstanceIndex = Mem_43_Eep_GetInstanceIndex(InstanceId);

#if (MEM_43_EEP_DEV_ERROR_DETECT == STD_ON)
    if (NULL_PTR == Mem_43_Eep_pConfigPtr)
    {
        (void)Det_ReportError((uint16)MEM_43_EEP_MODULE_ID, (uint8)InstanceIndex, MEM_43_EEP_GETJOBRESULT_ID, MEM_43_EEP_E_UNINIT);
    }
    else if (InstanceIndex >= MEM_43_EEP_INSTANCE_COUNT)
    {
        (void)Det_ReportError((uint16)MEM_43_EEP_MODULE_ID, (uint8)InstanceIndex, MEM_43_EEP_GETJOBRESULT_ID, MEM_43_EEP_E_PARAM_INSTANCE_ID);
    }
    else
#endif /* MEM_43_EEP_DEV_ERROR_DETECT == STD_ON */
    {
        /* Get the most recent job result of the according driver instance */
        JobResult = Mem_43_Eep_eJobRuntimeInfo[InstanceIndex].Mem_43_Eep_eJobResult;
    }

    return JobResult;
}
#endif

#if (MEM_43_EEP_SUSPEND_API == STD_ON)
/**
* @brief            Suspend an ongoing mem_43_eeprom read job.
* @details          Suspend active memory operation using hardware mechanism.
*
* @param[in]        instanceId        ID of the related memory driver instance.
* @param[inout]     None
* @param[out]       None
*
* @return           None
*
* @api
*
* @pre              The module must be initialized.
* @post             @p Mem_43_Eep_Suspend changes module status and @p Mem_43_Eep_eJobRuntimeInfo[InstanceIndex].Mem_43_Eep_eJobResult
*                   internal variable.
*
* @implements       Mem_43_Eep_Suspend_Activity
*/
void Mem_43_Eep_Suspend(Mem_43_Eep_InstanceIdType instanceId)
{
    (void)instanceId;
}
#endif    /* MEM_43_EEP_SUSPEND_API == STD_ON */

#if (MEM_43_EEP_RESUME_API == STD_ON)
/**
* @brief            Resume a suspended mem_43_eeprom read job.
* @details          Resume suspended memory operation using hardware mechanism.
*
* @param[in]        instanceId        ID of the related memory driver instance.
* @param[inout]     None
* @param[out]       None
*
* @return           None
*
* @api
*
* @pre              The module must be initialized.
* @post             @p Mem_43_Eep_Resume changes module status and @p Mem_43_Eep_eJobRuntimeInfo[InstanceIndex].Mem_43_Eep_eJobResult
*                   internal variable.
*
* @implements       Mem_43_Eep_Resume_Activity
*/
void Mem_43_Eep_Resume(Mem_43_Eep_InstanceIdType instanceId)
{
    (void)instanceId;
}
#endif    /* MEM_43_EEP_RESUME_API == STD_ON */

#if (MEM_43_EEP_PROPAGATEERROR_API == STD_ON)
/**
* @brief            Provide access error information.
* @details          This service can be used to report an access error in case the Mem driver cannot provide the
*                   access error information - typically for ECC faults. It is called by the system ECC handler to
*                   propagate an ECC error to the memory upper layers..
*
* @param[in]        instanceId        ID of the related memory driver instance.
* @param[inout]     None
* @param[out]       None
*
* @return           None
*
* @api
*
* @pre              The module must be initialized.
* @post             @p Mem_43_Eep_PropagateError changes module status and @p Mem_43_Eep_eJobRuntimeInfo[InstanceIndex].Mem_43_Eep_eJobResult
*                   internal variable.
*
* @implements       Mem_43_Eep_PropagateError_Activity
*/
void Mem_43_Eep_PropagateError(Mem_43_Eep_InstanceIdType instanceId)
{
    uint32 InstanceIndex = Mem_43_Eep_GetInstanceIndex(instanceId);
#if (MEM_43_EEP_DEV_ERROR_DETECT == STD_ON)
    if (NULL_PTR == Mem_43_Eep_pConfigPtr)
    {
        (void)Det_ReportError((uint16)MEM_43_EEP_MODULE_ID, (uint8)InstanceIndex, MEM_43_EEP_PROPRAGATEERROR_ID, MEM_43_EEP_E_UNINIT);
    }
    else if (InstanceIndex >= MEM_43_EEP_INSTANCE_COUNT)
    {
        (void)Det_ReportError((uint16)MEM_43_EEP_MODULE_ID, (uint8)InstanceIndex, MEM_43_EEP_PROPRAGATEERROR_ID, MEM_43_EEP_E_PARAM_INSTANCE_ID);
    }
    else
#endif /* MEM_43_EEP_DEV_ERROR_DETECT == STD_ON */
    {
        if (MEM_43_EEP_JOB_PENDING == Mem_43_Eep_eJobRuntimeInfo[InstanceIndex].Mem_43_Eep_eJobResult)
        {
                /* If underlying hardware job was successfully canceled */
                if ((Std_ReturnType)E_OK == Mem_43_Eep_Ipw_Cancel(InstanceIndex))
                {
                    /* Update global job result status */
                    Mem_43_Eep_eJobRuntimeInfo[InstanceIndex].Mem_43_Eep_eJobResult = MEM_43_EEP_ECC_UNCORRECTED;
                }
        }
        else
        {
            /* Leave the job result unchanged */
        }
    }
}
#endif    /* MEM_43_EEP_PROPAGATEERROR_API == STD_ON */

#if (MEM_43_EEP_READ_API == STD_ON)
/**
* @brief            Reads from mem_43_eeprom memory.
* @details          Starts a read job asynchronously. The actual job is performed by @p Mem_43_Eep_MainFunction.
*                   Triggers a read job to copy the from the source address into the referenced destination data
*                   buffer. The result of this service can be retrieved using the Mem_GetJobResult API. If the read
*                   operation was successful, the result of the job is MEM_JOB_OK. If the read operation failed,
*                   the result of the job is either MEM_JOB_FAILED in case of a general error or 
*                   MEM_ECC_CORRECTED/MEM_ECC_UNCORRECTED in case of a correctable/uncorrectable ECC error.
*
* @param[in]        instanceId            ID of the related memory driver instance.
* @param[in]        sourceAddress        Physical address to read data from.
* @param[in]        length               Number of bytes to read.
* @param[inout]     None
* @param[out]       destinationDataPtr   Destination memory pointer to store the read data.
*
* @return           Std_ReturnType
* @retval           E_OK                      The requested job has been accepted by the module.
* @retval           E_NOT_OK                  The requested job has not been accepted by the module.
* @retval           E_MEM_SERVICE_NOT_AVAIL   The service function is not implemented.
*
* @api
*
* @pre            The module has to be initialized and not busy.
* @post
*
* @implements       Mem_43_Eep_Read_Activity
*
*/
Std_ReturnType Mem_43_Eep_Read(Mem_43_Eep_InstanceIdType instanceId,
                            Mem_43_Eep_AddressType sourceAddress,
                            Mem_43_Eep_DataType* destinationDataPtr,
                            Mem_43_Eep_LengthType length)
{
    Std_ReturnType RetVal = (Std_ReturnType)E_NOT_OK;
    const uint32 InstanceIndex = Mem_43_Eep_GetInstanceIndex(instanceId);
    const Mem_43_Eep_SectorBatchType    *SectorBatch = Mem_43_Eep_GetSectorBatch(InstanceIndex, sourceAddress);        /* The sector batch to be worked with the request job                 */

#if (MEM_43_EEP_DEV_ERROR_DETECT == STD_ON)
    /* Check driver was initialized */
    if (NULL_PTR == Mem_43_Eep_pConfigPtr)
    {
        (void)Det_ReportError((uint16)MEM_43_EEP_MODULE_ID, (uint8)InstanceIndex, MEM_43_EEP_READ_ID, MEM_43_EEP_E_UNINIT);
    }
    else if (NULL_PTR == destinationDataPtr)
    {
        (void)Det_ReportError((uint16)MEM_43_EEP_MODULE_ID, (uint8)InstanceIndex, MEM_43_EEP_READ_ID, MEM_43_EEP_E_PARAM_POINTER);
    }
    else if (InstanceIndex >= MEM_43_EEP_INSTANCE_COUNT)
    {
        (void)Det_ReportError((uint16)MEM_43_EEP_MODULE_ID, (uint8)InstanceIndex, MEM_43_EEP_READ_ID, MEM_43_EEP_E_PARAM_INSTANCE_ID);
    }
    else if (NULL_PTR == SectorBatch)
    {
        (void)Det_ReportError((uint16)MEM_43_EEP_MODULE_ID, (uint8)InstanceIndex, MEM_43_EEP_READ_ID, MEM_43_EEP_E_PARAM_ADDRESS);
    }
    else if ((0u == length) || ((sourceAddress + length - 1u) > SectorBatch->EndAddress))
    {
        (void)Det_ReportError((uint16)MEM_43_EEP_MODULE_ID, (uint8)InstanceIndex, MEM_43_EEP_READ_ID, MEM_43_EEP_E_PARAM_LENGTH);
    }
    else
#endif
    if ((Std_ReturnType)E_NOT_OK == Mem_43_Eep_Ipw_CheckReadParams(sourceAddress, destinationDataPtr, length, InstanceIndex))
    {
        RetVal = (Std_ReturnType)E_NOT_OK;
    }
    else
    {
        SchM_Enter_Mem_43_Eep_MEM_43_EEP_EXCLUSIVE_AREA_03();

        if (MEM_43_EEP_JOB_PENDING == Mem_43_Eep_eJobRuntimeInfo[InstanceIndex].Mem_43_Eep_eJobResult)
        {
#if (MEM_43_EEP_DEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError((uint16)MEM_43_EEP_MODULE_ID, (uint8)InstanceIndex, MEM_43_EEP_READ_ID, MEM_43_EEP_E_JOB_PENDING);
#endif    /* MEM_43_EEP_DEV_ERROR_DETECT == STD_ON */
            RetVal = (Std_ReturnType)E_NOT_OK;
        }
        else
        {
            /* Configure the read job */
            Mem_43_Eep_eJobRuntimeInfo[InstanceIndex].Mem_43_Eep_u32EepromAddrIt     = sourceAddress;
            Mem_43_Eep_eJobRuntimeInfo[InstanceIndex].Mem_43_Eep_pJobSrcAddrPtr      = destinationDataPtr;
            Mem_43_Eep_eJobRuntimeInfo[InstanceIndex].Mem_43_Eep_u32RemainingLength  = length;
            Mem_43_Eep_eJobRuntimeInfo[InstanceIndex].Mem_43_Eep_eJob                = MEM_43_EEP_JOB_READ;
            /* Execute the read job */
            Mem_43_Eep_eJobRuntimeInfo[InstanceIndex].Mem_43_Eep_eJobResult          = MEM_43_EEP_JOB_PENDING;

            RetVal = (Std_ReturnType)E_OK;
        }
        SchM_Exit_Mem_43_Eep_MEM_43_EEP_EXCLUSIVE_AREA_03();
    }

    return RetVal;
}
#endif /*#if (MEM_43_EEP_READ_API == STD_ON)*/


#if (MEM_43_EEP_WRITE_API == STD_ON)
/**
* @brief            Write one or more complete mem_43_eeprom pages to the mem_43_eeprom device.
* @details          Triggers a write job to store the passed data to the provided address area with given address
*                   and length. The result of this service can be retrieved using the Mem_GetJobResult API. If the
*                   write operation was successful, the job result is MEM_JOB_OK. If there was an issue writing
*                   the data, the result is MEM_FAILED.
*
* @param[in]        instanceId            ID of the related memory driver instance.
* @param[in]        targetAddress        Physical erase address (aligned to sector size).
* @param[in]        sourceDataPtr        Source data pointer (aligned to page size).
* @param[in]        length               Write length in bytes (aligned to sector size).
* @param[inout]     None
* @param[out]       None
*
* @return           Std_ReturnType
* @retval           E_OK                      The requested job has been accepted by the module.
* @retval           E_NOT_OK                  The requested job has not been accepted by the module.
* @retval           E_MEM_SERVICE_NOT_AVAIL   The service function is not implemented.
*
* @api
*
* @pre              The module has to be initialized and not busy.
* @post
*
* @implements       Mem_43_Eep_Write_Activity
*
*/
Std_ReturnType Mem_43_Eep_Write(Mem_43_Eep_InstanceIdType instanceId,
                             Mem_43_Eep_AddressType targetAddress,
                             const Mem_43_Eep_DataType* sourceDataPtr,
                             Mem_43_Eep_LengthType length)
{
    Std_ReturnType RetVal = (Std_ReturnType)E_NOT_OK;
    const uint32 InstanceIndex = Mem_43_Eep_GetInstanceIndex(instanceId);
    const Mem_43_Eep_SectorBatchType *SectorBatch = Mem_43_Eep_GetSectorBatch(InstanceIndex, targetAddress);        /* The sector batch to be worked with the request job                 */

#if (MEM_43_EEP_DEV_ERROR_DETECT == STD_ON)
    if (NULL_PTR == Mem_43_Eep_pConfigPtr)
    {
        (void)Det_ReportError((uint16)MEM_43_EEP_MODULE_ID, (uint8)InstanceIndex, MEM_43_EEP_WRITE_ID, MEM_43_EEP_E_UNINIT);
    }
    else if (InstanceIndex >= MEM_43_EEP_INSTANCE_COUNT)
    {
        (void)Det_ReportError((uint16)MEM_43_EEP_MODULE_ID, (uint8)InstanceIndex, MEM_43_EEP_WRITE_ID, MEM_43_EEP_E_PARAM_INSTANCE_ID);
    }
    else if (NULL_PTR == sourceDataPtr)
    {
        (void)Det_ReportError((uint16)MEM_43_EEP_MODULE_ID, (uint8)InstanceIndex, MEM_43_EEP_WRITE_ID, MEM_43_EEP_E_PARAM_POINTER);
    }
    else if (NULL_PTR == SectorBatch)
    {
        (void)Det_ReportError((uint16)MEM_43_EEP_MODULE_ID, (uint8)InstanceIndex, MEM_43_EEP_WRITE_ID, MEM_43_EEP_E_PARAM_ADDRESS);
    }
    else if ((0u == length) || ((targetAddress + length - 1u) > SectorBatch->EndAddress))
    {
        (void)Det_ReportError((uint16)MEM_43_EEP_MODULE_ID, (uint8)InstanceIndex, MEM_43_EEP_WRITE_ID, MEM_43_EEP_E_PARAM_LENGTH);
    }
    else
#endif
    {
        if ((Std_ReturnType)E_OK == Mem_43_Eep_Ipw_CheckWriteParams(targetAddress, sourceDataPtr, length, InstanceIndex))
        {
            /* enter EA to protect global variables */
            SchM_Enter_Mem_43_Eep_MEM_43_EEP_EXCLUSIVE_AREA_02();

            if (MEM_43_EEP_JOB_PENDING == Mem_43_Eep_eJobRuntimeInfo[InstanceIndex].Mem_43_Eep_eJobResult)
            {
            #if (MEM_43_EEP_DEV_ERROR_DETECT == STD_ON)
                (void)Det_ReportError((uint16)MEM_43_EEP_MODULE_ID, (uint8)InstanceIndex, MEM_43_EEP_WRITE_ID, MEM_43_EEP_E_JOB_PENDING);
            #endif
                SchM_Exit_Mem_43_Eep_MEM_43_EEP_EXCLUSIVE_AREA_02();
            }
            else
            {
                /* Configure the write job */
                /* uint32 destination address which will be incremented during job processing */
                Mem_43_Eep_eJobRuntimeInfo[InstanceIndex].Mem_43_Eep_u32EepromAddrIt    = targetAddress;
                /* uint8 source pointer which will be incremented during job processing */
                Mem_43_Eep_eJobRuntimeInfo[InstanceIndex].Mem_43_Eep_pJobSrcAddrPtr     = (Mem_43_Eep_DataType *)sourceDataPtr;
                /* remaining length to be transfered */
                Mem_43_Eep_eJobRuntimeInfo[InstanceIndex].Mem_43_Eep_u32RemainingLength  = length;
                Mem_43_Eep_eJobRuntimeInfo[InstanceIndex].Mem_43_Eep_eJob                = MEM_43_EEP_JOB_WRITE;
                Mem_43_Eep_eJobRuntimeInfo[InstanceIndex].Mem_43_Eep_eJobResult          = MEM_43_EEP_JOB_PENDING;
                SchM_Exit_Mem_43_Eep_MEM_43_EEP_EXCLUSIVE_AREA_02();

                RetVal = (Std_ReturnType)E_OK;
            }
        }
    }

    return RetVal;
}
#endif /*#if (MEM_43_EEP_WRITE_API == STD_ON)*/

#if (MEM_43_EEP_ERASE_API == STD_ON)
/**
* @brief            Erase memory by writing erase value.
* @details          Triggers an erase job of the given sector/sector batch defined by targetAddress and length. The
*                   result of this service can be retrieved using the Mem_GetJobResult API. If the erase operation
*                   was successful, the result of the job is MEM_JOB_OK. If the erase operation failed, e.g. due to
*                   a hardware issue, the result of the job is MEM_JOB_FAILED.
*
* @param[in]        instanceId            ID of the related memory driver instance.
* @param[in]        targetAddress        Physical erase address (aligned to sector size).
* @param[in]        length               Erase length in bytes (aligned to sector size).
* @param[inout]     None
* @param[out]       None
*
* @return           Std_ReturnType
* @retval           E_OK                      The requested job has been accepted by the module.
* @retval           E_NOT_OK                  The requested job has not been accepted by the module.
* @retval           E_MEM_SERVICE_NOT_AVAIL   The service function is not implemented.
*
* @api
*
* @pre              The module has to be initialized and not busy.
* @post
*
* @implements       Mem_43_Eep_Erase_Activity
*
*/
Std_ReturnType Mem_43_Eep_Erase(Mem_43_Eep_InstanceIdType instanceId,
                             Mem_43_Eep_AddressType targetAddress,
                             Mem_43_Eep_LengthType length)
{
    Std_ReturnType RetVal = (Std_ReturnType)E_NOT_OK;
    const uint32 InstanceIndex = Mem_43_Eep_GetInstanceIndex(instanceId);
    const Mem_43_Eep_SectorBatchType *SectorBatch = Mem_43_Eep_GetSectorBatch(InstanceIndex, targetAddress);        /* The sector batch to be worked with the request job                 */

    /* Check driver was initialized */
#if (MEM_43_EEP_DEV_ERROR_DETECT == STD_ON)
    if (NULL_PTR == Mem_43_Eep_pConfigPtr)
    {
        (void)Det_ReportError((uint16)MEM_43_EEP_MODULE_ID, (uint8)InstanceIndex, MEM_43_EEP_ERASE_ID, MEM_43_EEP_E_UNINIT);
    }
    else if (InstanceIndex >= MEM_43_EEP_INSTANCE_COUNT)
    {
        (void)Det_ReportError((uint16)MEM_43_EEP_MODULE_ID, (uint8)InstanceIndex, MEM_43_EEP_ERASE_ID, MEM_43_EEP_E_PARAM_INSTANCE_ID);
    }
    else if (NULL_PTR == SectorBatch)
    {
        (void)Det_ReportError((uint16)MEM_43_EEP_MODULE_ID, (uint8)InstanceIndex, MEM_43_EEP_ERASE_ID, MEM_43_EEP_E_PARAM_ADDRESS);
    }
    else if ((0u == length) || ((targetAddress + length - 1u) > SectorBatch->EndAddress))
    {
        (void)Det_ReportError((uint16)MEM_43_EEP_MODULE_ID, (uint8)InstanceIndex, MEM_43_EEP_ERASE_ID, MEM_43_EEP_E_PARAM_LENGTH);
    }
    else
#endif
    {
        if ((Std_ReturnType)E_OK == Mem_43_Eep_Ipw_CheckEraseParams(targetAddress, length, InstanceIndex))
        {
            SchM_Enter_Mem_43_Eep_MEM_43_EEP_EXCLUSIVE_AREA_01();
            if (MEM_43_EEP_JOB_PENDING == Mem_43_Eep_eJobRuntimeInfo[InstanceIndex].Mem_43_Eep_eJobResult)
            {
            #if (MEM_43_EEP_DEV_ERROR_DETECT == STD_ON)
                (void) Det_ReportError((uint16)MEM_43_EEP_MODULE_ID, (uint8)InstanceIndex, MEM_43_EEP_ERASE_ID, MEM_43_EEP_E_JOB_PENDING);
            #endif
                SchM_Exit_Mem_43_Eep_MEM_43_EEP_EXCLUSIVE_AREA_01();
            }
            else
            {
                /* Configure the erase job */
                Mem_43_Eep_eJobRuntimeInfo[InstanceIndex].Mem_43_Eep_u32EepromAddrIt     = targetAddress;
                Mem_43_Eep_eJobRuntimeInfo[InstanceIndex].Mem_43_Eep_u32RemainingLength  = length;
                Mem_43_Eep_eJobRuntimeInfo[InstanceIndex].Mem_43_Eep_eJob                = MEM_43_EEP_JOB_ERASE;
                Mem_43_Eep_eJobRuntimeInfo[InstanceIndex].Mem_43_Eep_eJobResult          = MEM_43_EEP_JOB_PENDING;
                SchM_Exit_Mem_43_Eep_MEM_43_EEP_EXCLUSIVE_AREA_01();

                RetVal = (Std_ReturnType)E_OK;
            }
        }
    }

    return RetVal;
}
#endif /*#if (MEM_43_EEP_ERASE_API == STD_ON)*/

#if (MEM_43_EEP_BLANKCHECK_API == STD_ON)
/**
* @brief            Check blank memory by checking against erased value.
* @details          Triggers a job to check the erased state of the page which is referenced by targetAddress. The
*                   result of this service can be retrieved using the Mem_GetJobResult API. If the checked page is
*                   blank, the result of the job is MEM_43_EEP_JOB_OK. Otherwise, if the page is not blank, the result is
*                   MEM_43_EEP_INCONSISTENT.
*
* @param[in]        instanceId            ID of the related memory driver instance.
* @param[in]        targetAddress        Physical blank check addres.
* @param[in]        length               Blank check length.
* @param[inout]     None
* @param[out]       None
*
* @return           Std_ReturnType
* @retval           E_OK                      The requested job has been accepted by the module.
* @retval           E_NOT_OK                  The requested job has not been accepted by the module.
* @retval           E_MEM_SERVICE_NOT_AVAIL   The service function is not implemented.
*
* @api
*
* @pre              The module has to be initialized and not busy.
* @post
*
* @implements       Mem_43_Eep_BlankCheck_Activity
*
*/
Std_ReturnType Mem_43_Eep_BlankCheck(Mem_43_Eep_InstanceIdType instanceId,
                                  Mem_43_Eep_AddressType targetAddress,
                                  Mem_43_Eep_LengthType length)
{
    Std_ReturnType RetVal = (Std_ReturnType)E_NOT_OK;
    const uint32 InstanceIndex = Mem_43_Eep_GetInstanceIndex(instanceId);
    const Mem_43_Eep_SectorBatchType *SectorBatch = Mem_43_Eep_GetSectorBatch(InstanceIndex, targetAddress);        /* The sector batch to be worked with the request job                 */

    /* Check driver was initialized */
#if (MEM_43_EEP_DEV_ERROR_DETECT == STD_ON)
    if (NULL_PTR == Mem_43_Eep_pConfigPtr)
    {
        (void)Det_ReportError((uint16)MEM_43_EEP_MODULE_ID, (uint8)InstanceIndex, MEM_43_EEP_BLANKCHECK_ID, MEM_43_EEP_E_UNINIT);
    }
    else if (InstanceIndex >= MEM_43_EEP_INSTANCE_COUNT)
    {
        (void)Det_ReportError((uint16)MEM_43_EEP_MODULE_ID, (uint8)InstanceIndex, MEM_43_EEP_BLANKCHECK_ID, MEM_43_EEP_E_PARAM_INSTANCE_ID);
    }
    else if (NULL_PTR == SectorBatch)
    {
        (void)Det_ReportError((uint16)MEM_43_EEP_MODULE_ID, (uint8)InstanceIndex, MEM_43_EEP_BLANKCHECK_ID, MEM_43_EEP_E_PARAM_ADDRESS);
    }
    else if ((0u == length) || ((targetAddress + length - 1u) > SectorBatch->EndAddress))
    {
        (void)Det_ReportError((uint16)MEM_43_EEP_MODULE_ID, (uint8)InstanceIndex, MEM_43_EEP_BLANKCHECK_ID, MEM_43_EEP_E_PARAM_LENGTH);
    }
    else
#endif
    {
        if ((Std_ReturnType)E_OK == Mem_43_Eep_Ipw_CheckBlankCheckParams(targetAddress, length, InstanceIndex))
        {
            SchM_Enter_Mem_43_Eep_MEM_43_EEP_EXCLUSIVE_AREA_04();
            if (MEM_43_EEP_JOB_PENDING == Mem_43_Eep_eJobRuntimeInfo[InstanceIndex].Mem_43_Eep_eJobResult)
            {
            #if (MEM_43_EEP_DEV_ERROR_DETECT == STD_ON)
                (void) Det_ReportError((uint16)MEM_43_EEP_MODULE_ID, (uint8)InstanceIndex, MEM_43_EEP_BLANKCHECK_ID, MEM_43_EEP_E_JOB_PENDING);
            #endif
                SchM_Exit_Mem_43_Eep_MEM_43_EEP_EXCLUSIVE_AREA_04();
            }
            else
            {
                /* Configure the erase job */
                Mem_43_Eep_eJobRuntimeInfo[InstanceIndex].Mem_43_Eep_u32EepromAddrIt     = targetAddress;
                Mem_43_Eep_eJobRuntimeInfo[InstanceIndex].Mem_43_Eep_u32RemainingLength  = length;
                Mem_43_Eep_eJobRuntimeInfo[InstanceIndex].Mem_43_Eep_eJob                = MEM_43_EEP_JOB_BLANKCHECK;
                Mem_43_Eep_eJobRuntimeInfo[InstanceIndex].Mem_43_Eep_eJobResult          = MEM_43_EEP_JOB_PENDING;
                SchM_Exit_Mem_43_Eep_MEM_43_EEP_EXCLUSIVE_AREA_04();

                RetVal = (Std_ReturnType)E_OK;
            }
        }
    }

    return RetVal;
}
#endif /*#if (MEM_43_EEP_BLANKCHECK_API == STD_ON)*/

#if (MEM_43_EEP_HWSPECIFICSERVICE_API == STD_ON)
/**
* @brief            Triggers a hardware specific memory driver job. dataPtr can be used to pass and return data to/from this service.
* @details          This service is just a dispatcher to the hardware specific service implementation referenced by hwServiceId. 
*                   The result of this service can be retrieved using the Mem_43_Eep_GetJobResult API. If the hardware specific 
*                   operation was successful, the result of the job is MEM_43_EEP_JOB_OK. If the hardware specific operation failed, 
*                   the result of the job is MEM_43_EEP_JOB_FAILED.
*
* @param[in]        instanceId          ID of the related memory driver instance.
* @param[in]        hwServiceId        Hardware specific service request identifier for dispatching the request.
* @param[in]        dataPtr            Request specific data pointer.
* @param[in]        lengthPtr          Size pointer of the data passed by dataPtr.
* @param[inout]     None
* @param[out]       None
*
* @return           Std_ReturnType
* @retval           E_OK                      The requested job has been accepted by the module.
* @retval           E_NOT_OK                  The requested job has not been accepted by the module.
* @retval           E_MEM_SERVICE_NOT_AVAIL   The service function is not implemented.
*
* @api
*
* @pre              The module has to be initialized and not busy.
* @post
*
* @implements        Mem_43_Eep_HwSpecificService_Activity
*
*/
Std_ReturnType Mem_43_Eep_HwSpecificService (Mem_43_Eep_InstanceIdType instanceId,
                                          Mem_43_Eep_HwServiceIdType hwServiceId,
                                          Mem_43_Eep_DataType* dataPtr,
                                          Mem_43_Eep_LengthType* lengthPtr)
{
    Std_ReturnType RetVal = E_MEM_SERVICE_NOT_AVAIL;
    const uint32 InstanceIndex = Mem_43_Eep_GetInstanceIndex(instanceId);

    /* Check driver was initialized */
#if (MEM_43_EEP_DEV_ERROR_DETECT == STD_ON)
    if (NULL_PTR == Mem_43_Eep_pConfigPtr)
    {
        (void)Det_ReportError((uint16)MEM_43_EEP_MODULE_ID, (uint8)InstanceIndex, MEM_43_EEP_HWSPECIFICSERVICE_ID, MEM_43_EEP_E_UNINIT);
    }
    else if (InstanceIndex >= MEM_43_EEP_INSTANCE_COUNT)
    {
        (void)Det_ReportError((uint16)MEM_43_EEP_MODULE_ID, (uint8)InstanceIndex, MEM_43_EEP_HWSPECIFICSERVICE_ID, MEM_43_EEP_E_PARAM_INSTANCE_ID);
    }
    else if ((NULL_PTR == dataPtr) || (NULL_PTR == lengthPtr))
    {
        (void)Det_ReportError((uint16)MEM_43_EEP_MODULE_ID, (uint8)InstanceIndex, MEM_43_EEP_HWSPECIFICSERVICE_ID, MEM_43_EEP_E_PARAM_POINTER );
    }
    else
#endif
    {
        /* Save hwServiceId to Mem_43_Eep_ProcessHwSpecificService() executes the hwService job at runtime.*/
        Mem_43_Eep_eJobRuntimeInfo[InstanceIndex].Mem_43_Eep_u32HwServiceIdJob = hwServiceId;
#if (MEM_43_EEP_SERVICE_COMPARE == STD_ON)
        if (MEM_43_EEP_HWSERVICEID_COMPARE == hwServiceId)
        {
            RetVal = Mem_43_Eep_Compare(instanceId, Mem_43_Eep_Conpare_u32EepromAddrNeedsCompared, dataPtr, *lengthPtr);
        }
#endif  /* MEM_43_EEP_SERVICE_COMPARE == STD_ON */
        /* if (Other services : not yet implemented )*/
    }

    return RetVal;
}
#endif /*#if (MEM_43_EEP_HWSPECIFICSERVICE_API == STD_ON)*/

/**
* @brief            Performs actual mem_43_eeprom read, write, erase and compare jobs.
* @pre              The module has to be initialized.
* @param[in]        Job  Currently executed job (erase, write, read, or compare)
*
* @return           Mem_43_Eep_JobResultType
* @retval           MEM_43_EEP_JOB_OK              Successfully completed job.
* @retval           MEM_43_EEP_JOB_FAILED          Not successfully completed job.
* @retval           MEM_43_EEP_JOB_PENDING         Still pending job (not yet completed).
* @retval           MEM_43_EEP_JOB_OK        Job has been canceled.
* @retval           MEM_43_EEP_INCONSISTENT  Inconsistent block requested, it may
*                                             contains corrupted data.
*/
static Mem_43_Eep_JobResultType Mem_43_Eep_ProcessRequestedJobs(Mem_43_Eep_JobType Job, uint32 instanceId)
{
    Mem_43_Eep_JobResultType RetVal = MEM_43_EEP_JOB_FAILED;

    switch (Job)
    {
        case MEM_43_EEP_JOB_ERASE:
            /* Process erase job */
            RetVal = Mem_43_Eep_ProcessEraseJob(instanceId);
            break;

        case MEM_43_EEP_JOB_WRITE:
            /* Process write job */
            RetVal = Mem_43_Eep_ProcessWriteJob(instanceId);
            break;

        case MEM_43_EEP_JOB_READ:
            /* Process read job */
            RetVal = Mem_43_Eep_ProcessReadJob(instanceId);
            break;

        case MEM_43_EEP_JOB_BLANKCHECK:
            /* Process bank check job */
            RetVal = Mem_43_Eep_ProcessBlankCheckJob(instanceId);
            break;

        case MEM_43_EEP_JOB_HWSPECIFICSERVICE:
            /* Process hw specific service job */
            RetVal = Mem_43_Eep_ProcessHwSpecificServiceJob(instanceId);
            break;

        default:
            /* Do nothing - should not happen in Fully Trusted Environment;
               'default' clause added to fulfill MISRA Rule 15.3 */
            break;
    }

    return RetVal;
}

/**
* @brief            Performs actual mem_43_eeprom read, write, erase and compare jobs.
* @details          Bytes number processed per cycle depends by job type (erase, write, read, compare)
*                   current MEM_43_EEP module's operating mode (normal, fast)
*                   and write, erase Mode of Execution (sync, async).
*
* @api
*
* @pre              The module has to be initialized.
*
*
* @note             This function have to be called ciclically by the Basic Software Module;
*                   it will do nothing if there aren't pending job.
* @implements       Mem_43_Eep_MainFunction_Activity
*/
void Mem_43_Eep_MainFunction(void)
{

    uint32 InstanceIndex;

    /* Check if Mem_43_Eep is initialized*/
    /* SWS_BSW_00037 - If the module is not initialized and the main function is executed then no error shall be reported and the main function shall return immediately. */
    if (NULL_PTR != Mem_43_Eep_pConfigPtr)
    {
        for (InstanceIndex = 0U; InstanceIndex < MEM_43_EEP_INSTANCE_COUNT; InstanceIndex++)
        {
            if (MEM_43_EEP_JOB_PENDING == Mem_43_Eep_eJobRuntimeInfo[InstanceIndex].Mem_43_Eep_eJobResult)
            {

                    /* Process the requested jobs : write, compare, erase, read, blank check, hw specific service */
                    Mem_43_Eep_eJobRuntimeInfo[InstanceIndex].Mem_43_Eep_eJobResult = Mem_43_Eep_ProcessRequestedJobs(Mem_43_Eep_eJobRuntimeInfo[InstanceIndex].Mem_43_Eep_eJob, InstanceIndex);


            }
            else
            {
                /* Nothing to do since no job is pending */
            }
        }
    }
}


#define MEM_43_EEP_STOP_SEC_CODE
#include "Mem_43_Eep_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */
