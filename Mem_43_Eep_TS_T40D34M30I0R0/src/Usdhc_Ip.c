/*==================================================================================================
*   Project              : RTD AUTOSAR 4.7
*   Platform             : CORTEXM
*   Peripheral           : IPV_USDHC
*   Dependencies         : 
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
*   @addtogroup Usdhc Ip
*   @{
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
#include "Mcal.h"
#include "Usdhc_Ip.h"

#if (STD_ON == USDHC_IP_SYNCRONIZE_CACHE)
#include "Cache_Ip.h"
#endif

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define USDHC_IP_VENDOR_ID_C                    43
#define USDHC_IP_AR_RELEASE_MAJOR_VERSION_C     4
#define USDHC_IP_AR_RELEASE_MINOR_VERSION_C     7
#define USDHC_IP_AR_RELEASE_REVISION_VERSION_C  0
#define USDHC_IP_SW_MAJOR_VERSION_C             3
#define USDHC_IP_SW_MINOR_VERSION_C             0
#define USDHC_IP_SW_PATCH_VERSION_C             0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if current file and Mcal header file are of the same Autosar version */
    #if ((USDHC_IP_AR_RELEASE_MAJOR_VERSION_C != MCAL_AR_RELEASE_MAJOR_VERSION) || \
         (USDHC_IP_AR_RELEASE_MINOR_VERSION_C != MCAL_AR_RELEASE_MINOR_VERSION) \
        )
        #error "AutoSar Version Numbers of Usdhc_Ip.c and Mcal.h are different"
    #endif
#endif

/* Check if Usdhc_Ip source file and Usdhc_Ip header file are of the same vendor */
#if (USDHC_IP_VENDOR_ID_C != USDHC_IP_VENDOR_ID_H)
    #error "Usdhc_Ip.c and Usdhc_Ip.h have different vendor ids"
#endif
/* Check if header file and Usdhc_Ip.h header file are of the same Autosar version */
#if ((USDHC_IP_AR_RELEASE_MAJOR_VERSION_C    != USDHC_IP_AR_RELEASE_MAJOR_VERSION_H) || \
     (USDHC_IP_AR_RELEASE_MINOR_VERSION_C    != USDHC_IP_AR_RELEASE_MINOR_VERSION_H) || \
     (USDHC_IP_AR_RELEASE_REVISION_VERSION_C != USDHC_IP_AR_RELEASE_REVISION_VERSION_H) \
    )
    #error "AutoSar Version Numbers of Usdhc_Ip.c and Usdhc_Ip.h are different"
#endif
/* Check if Usdhc_Ip source file and Usdhc_Ip header file are of the same Software version */
#if ((USDHC_IP_SW_MAJOR_VERSION_C != USDHC_IP_SW_MAJOR_VERSION_H) || \
     (USDHC_IP_SW_MINOR_VERSION_C != USDHC_IP_SW_MINOR_VERSION_H) || \
     (USDHC_IP_SW_PATCH_VERSION_C != USDHC_IP_SW_PATCH_VERSION_H)    \
    )
    #error "Software Version Numbers of Usdhc_Ip.c and Usdhc_Ip.h are different"
#endif

#if (STD_ON == USDHC_IP_SYNCRONIZE_CACHE)
    #ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
        /* Check if current file and Cache_Ip header file are of the same Autosar version */
        #if ((USDHC_IP_AR_RELEASE_MAJOR_VERSION_C != CACHE_IP_AR_RELEASE_MAJOR_VERSION) || \
             (USDHC_IP_AR_RELEASE_MINOR_VERSION_C != CACHE_IP_AR_RELEASE_MINOR_VERSION) \
            )
            #error "AutoSar Version Numbers of Usdhc_Ip.c and Cache_Ip.h are different"
        #endif
    #endif
#endif

/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
                                        LOCAL MACROS
==================================================================================================*/

/*! @brief Clock setting */
/* Max SD clock divisor from Base clock */
#define USDHC_INITIAL_CLKFS             (1U)                                /* Initial value of SD clock frequency selector */
#define USDHC_MAX_CLKFS                 ((USDHC_SYS_CTRL_SDCLKFS_MASK >> USDHC_SYS_CTRL_SDCLKFS_SHIFT) + 1U)
#define USDHC_NEXT_CLKFS(x)             ((x) <<= 1U)
#define USDHC_PREV_CLKFS(x)             ((x) >>= 1U)

/*!< All flags mask */
#define USDHC_ALL_INTERRUPTS_MASK       (0xFFFFFFFFU)

/*==================================================================================================
                                       LOCAL CONSTANTS
==================================================================================================*/

#define MEM_43_EEP_START_SEC_CONST_UNSPECIFIED
#include "Mem_43_Eep_MemMap.h"

/*! @brief uSDHC Base pointer array */
USDHC_Type * const Usdhc_Ip_BaseAddr[USDHC_INSTANCE_COUNT] = IP_USDHC_BASE_PTRS;

#define MEM_43_EEP_STOP_SEC_CONST_UNSPECIFIED
#include "Mem_43_Eep_MemMap.h"

/*==================================================================================================
                                       LOCAL VARIABLES
==================================================================================================*/

#define MEM_43_EEP_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "Mem_43_Eep_MemMap.h"

/*! @brief Pointers to uSDHC internal driver state for each Instance. */
static Usdhc_Ip_StateType * Usdhc_Ip_State[USDHC_INSTANCE_COUNT];

/*! @brief State of Transfer */
static Usdhc_Ip_StatusType Usdhc_Ip_eTransferStatus;

#define MEM_43_EEP_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "Mem_43_Eep_MemMap.h"

#define MEM_43_EEP_START_SEC_VAR_CLEARED_BOOLEAN
#include "Mem_43_Eep_MemMap.h"

/* In order to check the failed timeout */
boolean Usdhc_Ip_bFailedTimeout;
/* Setup hardware in one function which only call one time in that function */
static boolean Usdhc_Ip_bDriverBusy;

#define MEM_43_EEP_STOP_SEC_VAR_CLEARED_BOOLEAN
#include "Mem_43_Eep_MemMap.h"

#define MEM_43_EEP_START_SEC_VAR_CLEARED_32
#include "Mem_43_Eep_MemMap.h"

static uint32 Usdhc_Ip_u32UsdhcStartTime;
static uint32 Usdhc_Ip_u32UsdhcCurrentTime;

#define MEM_43_EEP_STOP_SEC_VAR_CLEARED_32
#include "Mem_43_Eep_MemMap.h"

/*==================================================================================================
                                       GLOBAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      GLOBAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/
#define MEM_43_EEP_START_SEC_CODE
#include "Mem_43_Eep_MemMap.h"

static void uSDHC_Ip_InitAllVarriable(uint32 Instance);

static inline uint32 uSDHC_Ip_GetCommandResponse(const USDHC_Type * Base,
                                                 uint32 Index
                                                );

#if defined(USDHC_IP_ENABLE_ADMA1)
static Usdhc_Ip_StatusType uSDHC_Ip_SetAdma1Table(uint32 * Table,
                                                  uint32 TableSize,
                                                  const uint32 * Data,
                                                  uint32 DataSize
                                                 );
#endif

static Usdhc_Ip_StatusType uSDHC_Ip_SetAdma2Table(uint32 * Table,
                                                  uint32 TableSize,
                                                  const uint32 * Data,
                                                  uint32 DataSize
                                                 );

static Usdhc_Ip_StatusType uSDHC_Ip_SetAdmaTableConfig(USDHC_Type * Base,
                                                       Usdhc_Ip_DmaModeType DmaMode,
                                                       const Usdhc_Ip_StateType * State,
                                                       const uint32 * Data,
                                                       uint32 DataBytes
                                                      );

static void uSDHC_Ip_ProcessTransferCommand(uint32 Instance,
                                            uint32 InterruptFlags
                                           );

static void uSDHC_Ip_ProcessTransferData(uint32 Instance,
                                         uint32 InterruptFlags
                                        );

static void uSDHC_Ip_ProcessTransferCardDetect(uint32 Instance,
                                               uint32 InterruptFlags
                                              );

static void uSDHC_Ip_ProcessCardInterrupt(uint32 Instance);

static void uSDHC_Ip_ProcessBlockGapInterrupt(uint32 Instance);

static inline uint32 uSDHC_Ip_BuildResponseFlags(Usdhc_Ip_ResponseType ResponseType);

void uSDHC_Ip_StartTransfer(USDHC_Type * Base,
                            const Usdhc_Ip_CommandType * Command,
                            const Usdhc_Ip_DataType * Data
                           );

static void uSDHC_Ip_GetCommandResponseOfR2(const USDHC_Type * Base,
                                            Usdhc_Ip_CommandType * Command
                                           );

static void uSDHC_Ip_ReceiveCommandResponse(const USDHC_Type * Base,
                                            Usdhc_Ip_CommandType * Command
                                           );

static uint32 uSDHC_Ip_ReadDataPort(const USDHC_Type * Base,
                                    const Usdhc_Ip_DataType * Data,
                                    uint32 TransferredWords
                                   );

static uint32 uSDHC_Ip_WriteDataPort(USDHC_Type * Base,
                                     const Usdhc_Ip_DataType * Data,
                                     uint32 TransferredWords
                                    );

static Usdhc_Ip_StatusType uSDHC_Ip_CheckBlockSize(const Usdhc_Ip_DataType * Data,
                                                   Usdhc_Ip_DmaModeType DmaMode
                                                  );

static void uSDHC_Ip_InitCallBacks(const Usdhc_Ip_ConfigType * Config,
                                   uint32 Instance,
                                   USDHC_Type * Base
                                  );

static void uSDHC_Ip_TransferProcess(uint32 Instance,
                                     const Usdhc_Ip_TransferType * Transfer,
                                     boolean AsyncEnable
                                    );


/*==================================================================================================
                                       LOCAL FUNCTIONS
==================================================================================================*/

/**
* @brief         uSDHC_Ip_InitAllVarriable
* @details       Initialize global variables to their default values
*
* @param[in]     Instance USDHC hardware Instance
*
* @return        void
* @pre           N/A
*/
static void uSDHC_Ip_InitAllVarriable(uint32 Instance)
{
    Usdhc_Ip_State[Instance] = (Usdhc_Ip_StateType *)NULL_PTR;
    Usdhc_Ip_bDriverBusy     = (boolean)FALSE;
    Usdhc_Ip_eTransferStatus  = STATUS_USDHC_IP_SUCCESS;
    Usdhc_Ip_bFailedTimeout  = (boolean)FALSE;
}

/* implements uSDHC_Isr_Activity */
/* uSDHC interrupt handler */
ISR(uSDHC0_Isr)
{
    USDHC_Type * Base     = Usdhc_Ip_BaseAddr[0];
    volatile uint32 InterruptFlags = 0UL;
    volatile uint32 u32interruptEnblEnable = 0UL;
    volatile uint32 u32interruptSignEnable = 0UL;
    uint32 u32validInterrupts = 0UL;
#if (USDHC_MCORE_ENABLED == STD_ON)
    uint32 u32DomainId = 0U;
    uint32 u32GateLocker = 0U;
#endif


#if (USDHC_MCORE_ENABLED == STD_ON)
    /* Get domain id */
    u32DomainId = Xrdc_Ip_GetDomainID(0U);
    /* Get gate locker */
    u32GateLocker = (uint32)Sema42_Ip_GetGateLocker(0U, USDHC_MCORE_SEMA4_JOB);
#endif

#if (USDHC_MCORE_ENABLED == STD_ON)
    if((uint32)SEMA42_IP_UNLOCKED_GATE == u32GateLocker)
    {
        /* If the gate was not locked by the HLD before, this event is spurious, try to lock gate to clear flag, then unlock and return immediately */
        if(Sema42_Ip_Success == Sema42_Ip_LockGate(0U, USDHC_MCORE_SEMA4_JOB, u32DomainId))
        {
            /* Get interrupt register */
            InterruptFlags = Base->INT_STATUS;
            /* Get interrupt enable register */
            u32interruptEnblEnable = Base->INT_STATUS_EN;
            /* Get interrupt signal register */
            u32interruptSignEnable = Base->INT_SIGNAL_EN;
            /* Check for valid interrupts */
            u32validInterrupts = (uint32)InterruptFlags;
            u32validInterrupts &= (uint32)u32interruptEnblEnable;
            u32validInterrupts &= (uint32)u32interruptSignEnable;    /* sequential calculation to fix misra 13.2 */
            /* Clear interrupt flags that have been set and checked as an valid interrupt */
            Base->INT_STATUS = u32validInterrupts;
            Sema42_Ip_UnlockGate(0U, USDHC_MCORE_SEMA4_JOB);
        }
    }
    else if (u32DomainId == u32GateLocker)         /* If the gate was locked by the HLD before */
    {
#endif
        /* Get interrupt register */
        InterruptFlags = Base->INT_STATUS;
        /* Get interrupt enable register */
        u32interruptEnblEnable = Base->INT_STATUS_EN;
        /* Get interrupt signal register */
        u32interruptSignEnable = Base->INT_SIGNAL_EN;
        /* Check for valid interrupts */
        u32validInterrupts = (uint32)InterruptFlags;
        u32validInterrupts &= (uint32)u32interruptEnblEnable;
        u32validInterrupts &= (uint32)u32interruptSignEnable;    /* sequential calculation to fix misra 13.2 */
        /* Clear interrupt flags that have been set and checked as an valid interrupt */
        Base->INT_STATUS = u32validInterrupts;

        /* Check for spurious interrupts */
        if (0U != ((USDHC_CARD_DETECT_INT | USDHC_COMMAND_INT | USDHC_DATA_INT | USDHC_INT_STATUS_CINT_MASK | USDHC_INT_STATUS_BGE_MASK) & u32validInterrupts))
        {
            if (Usdhc_Ip_State[0] != NULL_PTR)
            {
                if ((u32validInterrupts & USDHC_CARD_DETECT_INT) != 0U)
                {
                    uSDHC_Ip_ProcessTransferCardDetect(0, (u32validInterrupts & USDHC_CARD_DETECT_INT));
                }
                if ((u32validInterrupts & USDHC_COMMAND_INT) != 0U)
                {
                    uSDHC_Ip_ProcessTransferCommand(0, (u32validInterrupts & USDHC_COMMAND_INT));
                }
                if ((u32validInterrupts & USDHC_DATA_INT) != 0U)
                {
                    uSDHC_Ip_ProcessTransferData(0, (u32validInterrupts & USDHC_DATA_INT));
                }
                if ((u32validInterrupts & USDHC_INT_STATUS_CINT_MASK) != 0U)
                {
                    /* Disable Card interrupt status flag */
                    Base->INT_STATUS_EN &= ~USDHC_INT_STATUS_CINT_MASK;
                    /* Disable Card interrupt signal */
                    Base->INT_SIGNAL_EN &= ~USDHC_INT_STATUS_CINT_MASK;
                    uSDHC_Ip_ProcessCardInterrupt(0);
                }
                if ((u32validInterrupts & USDHC_INT_STATUS_BGE_MASK) != 0U)
                {
                    uSDHC_Ip_ProcessBlockGapInterrupt(0);
                }
            }
        }
#if (USDHC_MCORE_ENABLED == STD_ON)
    }
    else
    {
        /* Doing nothing, interruption is belong to other core */
    }
#endif
}

/**
* @brief         uSDHC_Ip_GetCommandResponse
* @details       Get command response from corresponding register
*
* @param[in]     Base  USDHC Base pointer
* @param[in]     Index USDHC response register index
*
* @return        CmdRespond
* @pre           The USDHC driver needs to be initialized
*/
static inline uint32 uSDHC_Ip_GetCommandResponse(const USDHC_Type * Base,
                                                 uint32 Index
                                                )
{
    uint32 CmdRespond;

    /* Response is stored in CMD_RSP0 */
    if (Index == 0U)
    {
        CmdRespond = Base->CMD_RSP0;
    }
    /* Response is stored in CMD_RSP1 */
    else if (Index == 1U)
    {
        CmdRespond = Base->CMD_RSP1;
    }
    /* Response is stored in CMD_RSP2 */
    else if (Index == 2U)
    {
        CmdRespond = Base->CMD_RSP2;
    }
    /* Response is stored in CMD_RSP3 */
    else if (Index == 3U)
    {
        CmdRespond = Base->CMD_RSP3;
    }
    /* No response */
    else
    {
        CmdRespond = 0U;
    }

    return CmdRespond;
}

#if defined(USDHC_IP_ENABLE_ADMA1)
/**
* @brief         uSDHC_Ip_SetAdma1Table
* @details       Configures the ADMA1 table
*
* @param[in]     Table      pointer to ADMA1 table
* @param[in]     TableSize  ADMA1 table size    
* @param[in]     Data       pointer to data
* @param[in]     DataSize   data size
*
* @return        Status
* @pre           N/A
*/
static Usdhc_Ip_StatusType uSDHC_Ip_SetAdma1Table(uint32 * Table,
                                                  uint32 TableSize,
                                                  const uint32 * Data,
                                                  uint32 DataSize
                                                 )
{
    const uint32 * StartAddress;
    Usdhc_Ip_StatusType Status = STATUS_USDHC_IP_SUCCESS;
    uint32 Entries;
    uint32 RemainDataBytes;
    uint32 EntryCount;
    Usdhc_Ip_aDma1DescriptorType *Adma1EntryAddress;

    StartAddress = Data;
    /* Check if ADMA descriptor's number is enough */
    Entries = ((DataSize / (USDHC_ADMA1_DESCRIPTOR_MAX_LENGTH_PER_ENTRY + 1U)) + 1U);
    /* ADMA1 needs two descriptors to finish a transfer */
    Entries <<= 1U;
    /* If the number of entries needed to transfer data is larger than number of ADMA table, return STATUS_USDHC_IP_OUT_OF_RANGE */
    if (Entries > (TableSize / USDHC_IP_PLATFORM_WORDSIZE))
    {
        Status = STATUS_USDHC_IP_OUT_OF_RANGE;
    }
    else
    {
        Adma1EntryAddress = (Usdhc_Ip_aDma1DescriptorType *)(Table);
        for (EntryCount = 0U; EntryCount < Entries; EntryCount += 2U)
        {
            RemainDataBytes = DataSize - ((uint32)StartAddress - (uint32)Data);
            /* Each descriptor for ADMA1 is 32-bit in length */
            if (RemainDataBytes <= USDHC_ADMA1_DESCRIPTOR_MAX_LENGTH_PER_ENTRY)
            {
                /* The last piece of data, setting end flag in descriptor */
                Adma1EntryAddress[EntryCount]  = (RemainDataBytes << USDHC_ADMA1_DESCRIPTOR_LENGTH_SHIFT);
                Adma1EntryAddress[EntryCount] |= USDHC_ADMA1_DESCRIPTOR_TYPE_SET_LENGTH_MASK;
                Adma1EntryAddress[EntryCount + 1U]  = ((uint32)(StartAddress));
                Adma1EntryAddress[EntryCount + 1U] |= (USDHC_ADMA1_DESCRIPTOR_TYPE_TRANSFER_MASK | USDHC_ADMA1_DESCRIPTOR_END_MASK);
            }
            else
            {
                Adma1EntryAddress[EntryCount]  = ((uint32)(USDHC_ADMA1_DESCRIPTOR_MAX_LENGTH_PER_ENTRY) << USDHC_ADMA1_DESCRIPTOR_LENGTH_SHIFT);
                Adma1EntryAddress[EntryCount] |= USDHC_ADMA1_DESCRIPTOR_TYPE_SET_LENGTH_MASK;
                Adma1EntryAddress[EntryCount + 1U]  = ((uint32)(StartAddress));
                Adma1EntryAddress[EntryCount + 1U] |= USDHC_ADMA1_DESCRIPTOR_TYPE_TRANSFER_MASK;
                StartAddress = &StartAddress[USDHC_ADMA1_DESCRIPTOR_MAX_LENGTH_PER_ENTRY / USDHC_IP_PLATFORM_WORDSIZE];
            }
        }
    }

    return Status;
}
#endif /* USDHC_IP_ENABLE_ADMA1 */

/**
* @brief         uSDHC_Ip_SetAdma2Table
* @details       Configures the ADMA2 table
*
* @param[in]     Table      pointer to ADMA2 table
* @param[in]     TableSize  ADMA1 table size    
* @param[in]     Data       pointer to data
* @param[in]     DataSize   data size
*
* @return        Status
* @pre           N/A
*/
static Usdhc_Ip_StatusType uSDHC_Ip_SetAdma2Table(uint32 * Table,
                                                  uint32 TableSize,
                                                  const uint32 * Data,
                                                  uint32 DataSize
                                                 )
{
    const uint32 * StartAddress;
    Usdhc_Ip_StatusType Status = STATUS_USDHC_IP_SUCCESS;
    uint32 Entries;
    uint32 RemainDataBytes;
    uint32 EntryCount;
    Usdhc_Ip_aDma2DescriptorType *Adma2EntryAddress;

    StartAddress = Data;
    /* Check if ADMA descriptor's number is enough. */
    Entries = ((DataSize / (USDHC_ADMA2_DESCRIPTOR_MAX_LENGTH_PER_ENTRY + 1U)) + 1U);
    /* If the number of Entries needed to transfer data is larger than number of ADMA table, return STATUS_USDHC_IP_OUT_OF_RANGE */
    if (Entries > (TableSize / USDHC_IP_PLATFORM_WORDSIZE))
    {
        Status = STATUS_USDHC_IP_OUT_OF_RANGE;
    }
    else
    {
        Adma2EntryAddress = (Usdhc_Ip_aDma2DescriptorType *)((uint32)Table);
        for (EntryCount = 0U; EntryCount < Entries; EntryCount++)
        {
            RemainDataBytes = DataSize - ((uint32)StartAddress - (uint32)Data);
            /* Each descriptor for ADMA2 is 64-bit in length */
            if (RemainDataBytes <= USDHC_ADMA2_DESCRIPTOR_MAX_LENGTH_PER_ENTRY)
            {
                /* The last piece of data, setting end flag in descriptor */
                Adma2EntryAddress[EntryCount].address    = StartAddress;
                Adma2EntryAddress[EntryCount].attribute  = (RemainDataBytes << USDHC_ADMA2_DESCRIPTOR_LENGTH_SHIFT);
                Adma2EntryAddress[EntryCount].attribute |= (USDHC_ADMA2_DESCRIPTOR_TYPE_TRANSFER_MASK | USDHC_ADMA2_DESCRIPTOR_END_MASK);
            }
            else
            {
                Adma2EntryAddress[EntryCount].address    = StartAddress;
                Adma2EntryAddress[EntryCount].attribute  = ((uint32)(USDHC_ADMA2_DESCRIPTOR_MAX_LENGTH_PER_ENTRY) << USDHC_ADMA2_DESCRIPTOR_LENGTH_SHIFT);
                Adma2EntryAddress[EntryCount].attribute |= USDHC_ADMA2_DESCRIPTOR_TYPE_TRANSFER_MASK;
                StartAddress = &StartAddress[USDHC_ADMA2_DESCRIPTOR_MAX_LENGTH_PER_ENTRY / USDHC_IP_PLATFORM_WORDSIZE];
            }
        }
    }

    return Status;
}

/**
* @brief         uSDHC_Ip_SetAdmaTableConfig
* @details       Configures the ADMA table
*
* @param[in]     Base        USDHC Base pointer
* @param[in]     DmaMode     DMA mode configured   
* @param[in]     State       USDHC state pointer
* @param[in]     Data        pointer to data
* @param[in]     DataBytes   data size
*
* @return        status
* @pre           N/A
*/
static Usdhc_Ip_StatusType uSDHC_Ip_SetAdmaTableConfig(USDHC_Type * Base,
                                                       Usdhc_Ip_DmaModeType DmaMode,
                                                       const Usdhc_Ip_StateType * State,
                                                       const uint32 * Data,
                                                       uint32 DataBytes
                                                      )
{
    Usdhc_Ip_StatusType Status = STATUS_USDHC_IP_SUCCESS;

    switch (DmaMode)
    {
        case USDHC_DMA_MODE_NO_DMA:
            /* Do nothing if ADMA is disabled */
            break;

#if defined(USDHC_IP_ENABLE_ADMA1)
        case USDHC_DMA_MODE_ADMA1:
            Status = uSDHC_Ip_SetAdma1Table(State->admaTable, State->admaTableSize, Data, DataBytes);
            if (Status == STATUS_USDHC_IP_SUCCESS)
            {
                /* When use ADMA, disable simple DMA */
                Base->DS_ADDR = 0U;
                Base->ADMA_SYS_ADDR = (uint32)State->admaTable;
            }
            break;
#endif /* USDHC_IP_ENABLE_ADMA1 */

        case USDHC_DMA_MODE_ADMA2:
            Status = uSDHC_Ip_SetAdma2Table(State->admaTable, State->admaTableSize, Data, DataBytes);
            if (Status == STATUS_USDHC_IP_SUCCESS)
            {
                /* When use ADMA, disable simple DMA */
                Base->DS_ADDR = 0U;
                Base->ADMA_SYS_ADDR = (uint32)State->admaTable;
            }
            break;

        default:
            /* Do nothing */
            break;
    }

    if (STATUS_USDHC_IP_SUCCESS != Status)
    {
        Status = STATUS_USDHC_IP_PREPARE_ADMA_FAILED;
    }

    return Status;
}

/**
* @brief         uSDHC_Ip_ProcessTransferCommand
* @details       The interrupt handler for transferring command
*
* @param[in]     Instance           USDHC Instance
* @param[in]     InterruptFlags  interrupt enable flags
*
* @return        void
* @pre           The USDHC driver needs to be initialized
*/
static void uSDHC_Ip_ProcessTransferCommand(uint32 Instance,
                                            uint32 InterruptFlags
                                           )
{
    Usdhc_Ip_StateType * State = Usdhc_Ip_State[Instance];

    if (((InterruptFlags & USDHC_COMMAND_ERROR_INT) != 0U) && (State->transferErrorCallback != NULL_PTR))
    {
        /* Error occurs, invoke callback function with error code */
        State->transferErrorCallback(Instance, InterruptFlags);
        State->u16TransferComplete++;
    }
    else
    {
        /* Receive response */
        uSDHC_Ip_ReceiveCommandResponse(Usdhc_Ip_BaseAddr[Instance], State->command);
        if (State->transferCompleteCallback != NULL_PTR)
        {
            State->transferCompleteCallback(Instance, InterruptFlags);
        }
        if (NULL_PTR == State->data)
        {
            State->u16TransferComplete++;
        }
    }
}

/**
* @brief         uSDHC_Ip_ProcessTransferData
* @details       The interrupt handler for transferring data
*
* @param[in]     Instance           USDHC Instance
* @param[in]     InterruptFlags  interrupt enable flags
*
* @return        void
* @pre           The USDHC driver needs to be initialized
*/
static void uSDHC_Ip_ProcessTransferData(uint32 Instance,
                                         uint32 InterruptFlags
                                        )
{
    Usdhc_Ip_StateType * State = Usdhc_Ip_State[Instance];
    boolean ExistInt = FALSE;

    if (((InterruptFlags & (USDHC_DATA_ERROR_INT | USDHC_INT_STATUS_DMAE_MASK)) != 0U) && (State->transferErrorCallback != NULL_PTR))
    {
        /* Error occurs, invoke callback function with error code */
        State->transferErrorCallback(Instance, InterruptFlags);
        ExistInt = TRUE;
    }

    if (((InterruptFlags & USDHC_INT_STATUS_BRR_MASK) != 0U) && (ExistInt != TRUE))
    {
        /* Data in read buffer is available */
        State->transferredWords = uSDHC_Ip_ReadDataPort(Usdhc_Ip_BaseAddr[Instance], State->data, State->transferredWords);
        ExistInt = TRUE;
    }

    if (((InterruptFlags & USDHC_INT_STATUS_BWR_MASK) != 0U) && (ExistInt != TRUE))
    {
        /* Write buffer is empty */
        State->transferredWords = uSDHC_Ip_WriteDataPort(Usdhc_Ip_BaseAddr[Instance], State->data, State->transferredWords);
        ExistInt = TRUE;
    }

    if (((InterruptFlags & USDHC_INT_STATUS_TC_MASK) != 0U) && (ExistInt != TRUE))
    {
        if(State->transferCompleteCallback != NULL_PTR)
        {
            State->transferCompleteCallback(Instance, InterruptFlags);
        }
        /* Transfer complete flag was set */
        State->u16TransferComplete++;
    }
}

/**
* @brief         uSDHC_Ip_ProcessTransferCardDetect
* @details       The interrupt handler for detecting the card
*
* @param[in]     Instance           USDHC Instance
* @param[in]     InterruptFlags  interrupt enable flags
*
* @return        void
* @pre           The USDHC driver needs to be initialized
*/
static void uSDHC_Ip_ProcessTransferCardDetect(uint32 Instance,
                                               uint32 InterruptFlags
                                              )
{
    const Usdhc_Ip_StateType * State = Usdhc_Ip_State[Instance];

    if ((InterruptFlags & USDHC_INT_STATUS_CINS_MASK) != 0U)
    {
        if (NULL_PTR!= Usdhc_Ip_State[Instance]->cardInsertCallback)
        {
            State->cardInsertCallback(Instance, 0U);
        }
    }
    else if ((InterruptFlags & USDHC_INT_STATUS_CRM_MASK) != 0U)
    {
        if (NULL_PTR != Usdhc_Ip_State[Instance]->cardRemoveCallback)
        {
            State->cardRemoveCallback(Instance, 0U);
        }
    }
    else
    {
        /* Do nothing */
    }
}

/**
* @brief         uSDHC_Ip_ProcessCardInterrupt
* @details       The interrupt handler for card interrupt
*
* @param[in]     Instance USDHC Instance
*
* @return        void
* @pre           The USDHC driver needs to be initialized
*/
static void uSDHC_Ip_ProcessCardInterrupt(uint32 Instance)
{
    const Usdhc_Ip_StateType * State = Usdhc_Ip_State[Instance];

    State->cardIntCallback(Instance, 0U);
}

/**
* @brief         uSDHC_Ip_ProcessBlockGapInterrupt
* @details       The interrupt handler for block gap interrupt
*
* @param[in]     Instance USDHC Instance
*
* @return        void
* @pre           The USDHC driver needs to be initialized
*/
static void uSDHC_Ip_ProcessBlockGapInterrupt(uint32 Instance)
{
    const Usdhc_Ip_StateType * State = Usdhc_Ip_State[Instance];

    State->blockGapCallback(Instance, 0U);
}

/**
* @brief         uSDHC_Ip_StartTransfer
* @details       Define the flag corresponding to each response type
*
* @param[in]     ResponseType    Command response type
*
* @return        uint32
* @pre           The USDHC driver needs to be initialized
*/
static inline uint32 uSDHC_Ip_BuildResponseFlags(Usdhc_Ip_ResponseType ResponseType)
{
    uint32 CmdReg;

    /* Define the flag corresponding to each response type. */
    switch (ResponseType)
    {
        case USDHC_RESPONSE_TYPE_R1: /* Response 1 */
            CmdReg = (USDHC_RESPONSE_LENGTH48_FLAG | USDHC_ENABLE_CRC_CHECK_FLAG | USDHC_ENABLE_INDEX_CHECK_FLAG);
            break;

        case USDHC_RESPONSE_TYPE_R1b: /* Response 1 with busy */
            CmdReg = (USDHC_RESPONSE_LENGTH48_BUSY_FLAG | USDHC_ENABLE_CRC_CHECK_FLAG | USDHC_ENABLE_INDEX_CHECK_FLAG);
            break;

        case USDHC_RESPONSE_TYPE_R2: /* Response 2 */
            CmdReg = (USDHC_RESPONSE_LENGTH136_FLAG | USDHC_ENABLE_CRC_CHECK_FLAG);
            break;

        case USDHC_RESPONSE_TYPE_R3: /* Response 3 */
            CmdReg = (USDHC_RESPONSE_LENGTH48_FLAG);
            break;

        case USDHC_RESPONSE_TYPE_R4: /* Response 4 */
            CmdReg = (USDHC_RESPONSE_LENGTH48_FLAG);
            break;

        case USDHC_RESPONSE_TYPE_R5: /* Response 5 */
            CmdReg = (USDHC_RESPONSE_LENGTH48_FLAG | USDHC_ENABLE_CRC_CHECK_FLAG);
            break;

        case USDHC_RESPONSE_TYPE_R5b: /* Response 5 with busy */
            CmdReg = (USDHC_RESPONSE_LENGTH48_BUSY_FLAG | USDHC_ENABLE_CRC_CHECK_FLAG | USDHC_ENABLE_INDEX_CHECK_FLAG);
            break;

        case USDHC_RESPONSE_TYPE_R6: /* Response 6 */
            CmdReg = (USDHC_RESPONSE_LENGTH48_FLAG | USDHC_ENABLE_CRC_CHECK_FLAG | USDHC_ENABLE_INDEX_CHECK_FLAG);
            break;

        case USDHC_RESPONSE_TYPE_R7: /* Response 7 */
            CmdReg = (USDHC_RESPONSE_LENGTH48_FLAG | USDHC_ENABLE_CRC_CHECK_FLAG | USDHC_ENABLE_INDEX_CHECK_FLAG);
            break;

        default:
            /* USDHC_RESPONSE_TYPE_NONE */
            /* Do nothing */
            CmdReg = 0U;
            break;
    }

    return CmdReg;
}

/**
* @brief         uSDHC_Ip_StartTransfer
* @details       Start a transfer
*
* @param[in]     Base    USDHC Base pointer
* @param[in]     Command Command to transfer
* @param[in]     Data    USDHC Data to transfer
*
* @return        void
* @pre           The USDHC driver needs to be initialized
*/
void uSDHC_Ip_StartTransfer(USDHC_Type * Base,
                            const Usdhc_Ip_CommandType * Command,
                            const Usdhc_Ip_DataType * Data
                           )
{
    uint32                      CmdReg          = 0U;
    uint32                      MixCtrlReg      = Base->MIX_CTRL;
    Usdhc_Ip_TransferConfigType TransferConfig;
    Usdhc_Ip_DmaModeType        DmaMode;
#if (STD_ON == USDHC_IP_SYNCRONIZE_CACHE)
    uint32                      CacheStartAddress;
#endif

    /* Define the flag corresponding to each response type. */
    CmdReg = uSDHC_Ip_BuildResponseFlags(Command->responseType);

    if (Command->type == USDHC_COMMAND_TYPE_ABORT)
    {
        CmdReg |= USDHC_CMD_TYPE_ABORT_FLAG;
    }

    /* Clear some bit fields of MIX_CTRL before setting them according to configuration */
    MixCtrlReg &= ~(USDHC_ENABLE_DMA_FLAG | USDHC_MULTIPLE_BLOCK_FLAG | USDHC_ENABLE_BLOCK_COUNT_FLAG | USDHC_ENABLE_AUTO_CMD12_FLAG | USDHC_ENABLE_BLOCK_COUNT_FLAG | USDHC_DATA_READ_FLAG);
    if (Data != NULL_PTR)
    {
        CmdReg |= USDHC_DATA_PRESENT_FLAG;
        DmaMode = (Usdhc_Ip_DmaModeType)((Base->PROT_CTRL & USDHC_PROT_CTRL_DMASEL_MASK) >> USDHC_PROT_CTRL_DMASEL_SHIFT);
        if (DmaMode != USDHC_DMA_MODE_NO_DMA)
        {
            MixCtrlReg |= USDHC_ENABLE_DMA_FLAG;
        }
        if (Data->blockCount > 1U)
        {
            MixCtrlReg |= (USDHC_MULTIPLE_BLOCK_FLAG | USDHC_ENABLE_BLOCK_COUNT_FLAG);
            if (Data->enableAutoCMD12)
            {
                /* Enable Auto command 12. */
                MixCtrlReg |= USDHC_ENABLE_AUTO_CMD12_FLAG;
            }
        }

        TransferConfig.dataBlockSize = Data->blockSize;
        TransferConfig.dataBlockCount = Data->blockCount;
        if (Data->blockCount > USDHC_MAX_BLOCK_COUNT)
        {
            TransferConfig.dataBlockSize = Data->blockSize;
            TransferConfig.dataBlockCount = USDHC_MAX_BLOCK_COUNT;

            MixCtrlReg &= ~(uint32)USDHC_ENABLE_BLOCK_COUNT_FLAG;
        }
#if (STD_ON == USDHC_IP_SYNCRONIZE_CACHE)
        if (Data->rxData != NULL_PTR)
        {
            MixCtrlReg |= USDHC_DATA_READ_FLAG;
            /* Clear and invalidate cache of rx data before starting transfer */
            CacheStartAddress = (uint32)Data->rxData & (~(USDHC_IP_CACHE_LINE_LENGTH - 1UL));
            (void)Cache_Ip_CleanByAddr( USDHC_IP_CACHE_TYPE,
                                        CACHE_IP_DATA,
                                        (boolean)TRUE,
                                        CacheStartAddress,
                                        (uint32)((TransferConfig.dataBlockCount * TransferConfig.dataBlockSize) + (USDHC_IP_CACHE_LINE_LENGTH * 2UL))
                                      );
        }
        if(Data->txData != NULL_PTR)
        {
            /* Clear cache of tx Data before starting transfer */
            CacheStartAddress = (uint32)Data->txData & (~(USDHC_IP_CACHE_LINE_LENGTH - 1UL));
            (void)Cache_Ip_CleanByAddr( USDHC_IP_CACHE_TYPE,
                                        CACHE_IP_DATA,
                                        (boolean)FALSE,
                                        CacheStartAddress,
                                        (uint32)((TransferConfig.dataBlockCount * TransferConfig.dataBlockSize) + (USDHC_IP_CACHE_LINE_LENGTH * 2UL))
                                      );
        }
#else
        if (Data->rxData != NULL_PTR)
        {
            MixCtrlReg |= USDHC_DATA_READ_FLAG;
        }
#endif
    }
    else
    {
        TransferConfig.dataBlockSize  = 0U;
        TransferConfig.dataBlockCount = 0U;
    }

    TransferConfig.commandArgument = Command->argument;
    TransferConfig.commandIndex    = Command->index;
    TransferConfig.cmdReg          = CmdReg;
    TransferConfig.mixCtrlReg      = MixCtrlReg;
    
    Base->BLK_ATT     = ((Base->BLK_ATT & ~(USDHC_BLK_ATT_BLKSIZE_MASK | USDHC_BLK_ATT_BLKCNT_MASK)) |
                         (USDHC_BLK_ATT_BLKSIZE(TransferConfig.dataBlockSize) | USDHC_BLK_ATT_BLKCNT(TransferConfig.dataBlockCount)));
    Base->CMD_ARG     = TransferConfig.commandArgument;
    Base->MIX_CTRL    = TransferConfig.mixCtrlReg;
    Base->CMD_XFR_TYP = (((TransferConfig.commandIndex << USDHC_CMD_XFR_TYP_CMDINX_SHIFT) & USDHC_CMD_XFR_TYP_CMDINX_MASK) |
                         (TransferConfig.cmdReg & (USDHC_CMD_XFR_TYP_DPSEL_MASK | USDHC_CMD_XFR_TYP_CMDTYP_MASK | USDHC_CMD_XFR_TYP_CICEN_MASK |
                                           USDHC_CMD_XFR_TYP_CCCEN_MASK | USDHC_CMD_XFR_TYP_RSPTYP_MASK)));
}

/**
* @brief         uSDHC_Ip_GetCommandResponseOfR2
* @details       Get 4 bytes responses of R2 command type from card
*
* @param[in]     Base    USDHC Base pointer
* @param[in]     Command Command type variable where response is stored
*
* @return        void
* @pre           The USDHC driver needs to be initialized
*/
static void uSDHC_Ip_GetCommandResponseOfR2(const USDHC_Type * Base,
                                            Usdhc_Ip_CommandType * Command
                                           )
{
    uint8 IdxRsp;

    for (IdxRsp = 0U; IdxRsp < 4U; IdxRsp++)
    {
        Command->response[IdxRsp] = uSDHC_Ip_GetCommandResponse(Base, IdxRsp);
    }

    /* R3-R2-R1-R0(lowest 8 bit is invalid bit) has the same format as R2 format in SD specification document
    after removed internal CRC7 and end bit. */
    do
    {
        Command->response[IdxRsp - 1U] <<= 8U;
        if (IdxRsp > 1U)
        {
            Command->response[IdxRsp - 1U] |= ((Command->response[IdxRsp - 2U] & USDHC_RESPONSE_TYPE_R2_MASK) >> USDHC_RESPONSE_TYPE_R2_SHIFT);
        }
    } while ((IdxRsp--) > 0U);
}

/**
* @brief         uSDHC_Ip_ReceiveCommandResponse
* @details       Get 4 bytes responses from card
*
* @param[in]     Base    USDHC Base pointer
* @param[in]     Command Command type variable where response is stored
*
* @return        void
* @pre           The USDHC driver needs to be initialized
*/
static void uSDHC_Ip_ReceiveCommandResponse(const USDHC_Type * Base,
                                            Usdhc_Ip_CommandType * Command
                                           )
{
    boolean EnableAutoCMD12 = (boolean)FALSE;

    if (Command->responseType != USDHC_RESPONSE_TYPE_NONE)
    {
        if(0U != ((Base->MIX_CTRL & USDHC_MIX_CTRL_AC12EN_MASK) >> USDHC_MIX_CTRL_AC12EN_SHIFT))
        {
            EnableAutoCMD12 = (boolean)TRUE;
        }

        /* Responses of type R1b (Auto CMD12 responses) have response data bits stored in the CMDRSP3 register */
        if ((Command->responseType == USDHC_RESPONSE_TYPE_R1b) && ((boolean)TRUE == EnableAutoCMD12))
        {
            Command->response[0U] = uSDHC_Ip_GetCommandResponse(Base, 3U);
        }
        else
        {
            if (Command->responseType == USDHC_RESPONSE_TYPE_R2)
            {
                uSDHC_Ip_GetCommandResponseOfR2(Base, Command);
            }
            else
            {
                Command->response[0U] = uSDHC_Ip_GetCommandResponse(Base, 0U);
            }
        }
    }
}

/**
* @brief         uSDHC_Ip_ReadDataPort
* @details       Read data from data buffer access port register 
*
* @param[in]     Base             USDHC Base pointer
* @param[in]     Data             Buffer to store data
* @param[in]     TransferredWords Number of words to read from data buffer access port
*
* @return        u32transferredWordsTemp
* @pre           The USDHC driver needs to be initialized
*/
static uint32 uSDHC_Ip_ReadDataPort(const USDHC_Type * Base,
                                    const Usdhc_Ip_DataType * Data,
                                    uint32 TransferredWords
                                   )
{
    uint32 WordCount = 0U;
    uint32 TransferredWordsTemp = TransferredWords;
    uint32 TotalWords;

    /* The words can be read at this time. */
    uint32 WordsCanBeRead;
    uint32 ReadWatermark = ((Base->WTMK_LVL & USDHC_WTMK_LVL_RD_WML_MASK) >> USDHC_WTMK_LVL_RD_WML_SHIFT);

    /* Calculate total words */
    TotalWords = ((Data->blockCount * Data->blockSize) / USDHC_IP_PLATFORM_WORDSIZE);

    /* If ReadWatermark is greater than TotalWords */
    if (ReadWatermark >= TotalWords)
    {
        WordsCanBeRead = TotalWords;
    }
    else if ((TotalWords - TransferredWordsTemp) >= ReadWatermark)
    {
        WordsCanBeRead = ReadWatermark;
    }
    /* remaining words */
    else
    {
        WordsCanBeRead = (TotalWords - TransferredWordsTemp);
    }

    /* Read data from buffer */
    while (WordCount < WordsCanBeRead)
    {
        Data->rxData[TransferredWordsTemp] = Base->DATA_BUFF_ACC_PORT;
        TransferredWordsTemp++;
        WordCount++;
    }

    return TransferredWordsTemp;
}

/**
* @brief         uSDHC_Ip_WriteDataPort
* @details       Write data to data buffer access port register 
*
* @param[in]     Base             USDHC Base pointer
* @param[in]     Data             Buffer to store write data
* @param[in]     TransferredWords Number of words to write to data buffer access port
*
* @return        TransferredWordsTemp
* @pre           The USDHC driver needs to be initialized
*/
static uint32 uSDHC_Ip_WriteDataPort(USDHC_Type * Base,
                                     const Usdhc_Ip_DataType * Data,
                                     uint32 TransferredWords
                                    )
{
    uint32 WordCount = 0UL;
    uint32 TransferredWordsTemp = TransferredWords;

    /* Total words need writing */
    uint32 TotalWords;
    /* Words can be written at this time. */
    uint32 WordsCanBeWritten;
    uint32 WriteWatermark = ((Base->WTMK_LVL & USDHC_WTMK_LVL_WR_WML_MASK) >> USDHC_WTMK_LVL_WR_WML_SHIFT);
    /* Calculate total words */
    TotalWords = ((Data->blockCount * Data->blockSize) / USDHC_IP_PLATFORM_WORDSIZE);

    /* if WriteWatermark is greater than TotalWords */
    if (WriteWatermark >= TotalWords)
    {
        WordsCanBeWritten = TotalWords;
    }
    else if ((TotalWords - TransferredWordsTemp) >= WriteWatermark)
    {
        WordsCanBeWritten = WriteWatermark;
    }
    else
    {
        WordsCanBeWritten = (TotalWords - TransferredWordsTemp);
    }

    /* Write data to buffer */
    while (WordCount < WordsCanBeWritten)
    {
        Base->DATA_BUFF_ACC_PORT = Data->txData[TransferredWordsTemp];
        TransferredWordsTemp++;
        WordCount++;
    }

    return TransferredWordsTemp;
}

/**
* @brief         uSDHC_Ip_CheckBlockSize
* @details       Check block size value for current transfer
*
* @param[in]     Data             Variable to store transfer data
* @param[in]     DmaMode          DMA mode chosen for current transfer
*
* @return        eStatus
* @pre           The USDHC driver needs to be initialized
*/
static Usdhc_Ip_StatusType uSDHC_Ip_CheckBlockSize(const Usdhc_Ip_DataType * Data,
                                                   Usdhc_Ip_DmaModeType DmaMode
                                                  )
{
    Usdhc_Ip_StatusType Status = Usdhc_Ip_eTransferStatus;

    /* Command must not be NULL_PTR
     * If Data != NULL_PTR then blockSize must be divisible by 4 */
    if ( (Data != NULL_PTR) && ((Data->blockSize % 4U) != 0U) && 
         ((DmaMode != USDHC_DMA_MODE_ADMA2) || ((((uint32)(Data->txData) &    3U) == 0U) && (((uint32)(Data->rxData) &    3U) == 0U))) &&
         ((DmaMode != USDHC_DMA_MODE_ADMA1) || ((((uint32)(Data->txData) & 4095U) == 0U) && (((uint32)(Data->rxData) & 4095U) == 0U)))
       )
    {
        Status = STATUS_USDHC_IP_ERROR;
    }

    return Status;
}

/**
* @brief         uSDHC_Ip_ResetRegisters
* @details       Set uSDHC registers to their reset values
*
* @param[in]     BaseAddress             Base address of peripheral
*
* @return        N/A
* @pre           The USDHC driver needs to be clocked
*/
static void uSDHC_Ip_ResetRegisters(USDHC_Type *BaseAddress)
{
#if (STD_ON == FEATURE_USDHC_HAS_HIGHSPEED_TUNNING)
    BaseAddress->STROBE_DLL_CTRL      = 0U;
    BaseAddress->CLK_TUNE_CTRL_STATUS = 0U;
    BaseAddress->TUNING_CTRL          = 0x212800U;
#endif
    BaseAddress->MIX_CTRL             = 0x80000000U;
    BaseAddress->PROT_CTRL            = 0x08800020U;
    BaseAddress->VEND_SPEC            = 0x30007809U;
}

#if (STD_ON == USDHC_IP_MMC_BOOT_ENABLED)
Usdhc_Ip_StatusType uSDHC_Ip_ProcessFastBoot(uint32 instance,const Usdhc_Ip_BootConfigType * UsdhcBootConfig, uint32 numberBlocks, uint32 * buffer)
{
    Usdhc_Ip_DataType initDataState;
    USDHC_Type * Base                   = Usdhc_Ip_BaseAddr[instance];
    uint32     u32startTime             = 0U;
    uint32     u32currentTime           = 0U;
    uint32     u32MmcBootReg            = 0U;
    uint32     u32flagValue             = UsdhcBootConfig->bootFlags;
    uint32     MixCtrlReg               = 0u;

    /* Set MMC boot configuration */
    u32MmcBootReg  = Base->MMC_BOOT;

    u32MmcBootReg &= ~(USDHC_MMC_BOOT_DTOCV_ACK_MASK | USDHC_MMC_BOOT_BOOT_ACK_MASK | USDHC_MMC_BOOT_BOOT_MODE_MASK
                    | USDHC_MMC_BOOT_BOOT_EN_MASK | USDHC_MMC_BOOT_AUTO_SABG_EN_MASK | USDHC_MMC_BOOT_DISABLE_TIME_OUT_MASK
                    | USDHC_MMC_BOOT_BOOT_BLK_CNT_MASK);

    /* Sets the timeout value for the boot ACK. */
    u32MmcBootReg |= USDHC_MMC_BOOT_DTOCV_ACK(UsdhcBootConfig->ackTimeout);
    /* Configures the boot mode. */
    u32MmcBootReg |= USDHC_MMC_BOOT_BOOT_MODE(UsdhcBootConfig->bootMode);
    /* Enables/Disables the boot ACK. */
    u32MmcBootReg |= USDHC_MMC_BOOT_BOOT_ACK(((u32flagValue & (uint32)USDHC_MMC_BOOT_BOOT_ACK_MASK) != 0UL) ? 1UL : 0UL);
    /* Enables/Disables checking timeout boot */
    u32MmcBootReg |= USDHC_MMC_BOOT_DISABLE_TIME_OUT(((u32flagValue & (uint32)USDHC_MMC_BOOT_DISABLE_TIME_OUT_MASK) != 0UL) ? 1UL : 0UL);
    /* Enables/disable the automatic stop at the block gap. */
    u32MmcBootReg |= USDHC_MMC_BOOT_AUTO_SABG_EN(((u32flagValue & (uint32)USDHC_MMC_BOOT_AUTO_SABG_EN_MASK) != 0UL) ? 1UL : 0UL);
    /* Configures the the block count for the boot. */
    u32MmcBootReg |= USDHC_MMC_BOOT_BOOT_BLK_CNT(UsdhcBootConfig->stopBlockGapCount);

    Base->MMC_BOOT = u32MmcBootReg;

    /* Initialize state variable */
    initDataState.enableAutoCMD12 = (boolean)TRUE;
    initDataState.blockSize       = USDHC_IP_DEFAULT_BLOCK_SIZE;
    initDataState.blockCount      = numberBlocks;
    initDataState.rxData          = NULL_PTR;
    initDataState.txData          = NULL_PTR;
    Usdhc_Ip_State[instance]->data = &initDataState;

    /* Assign rx buffer to data handle */
    Usdhc_Ip_State[instance]->data->rxData = (uint32 *)buffer;

    /* Reset transferredWords */
    Usdhc_Ip_State[instance]->transferredWords = 0U;
    Usdhc_Ip_StateType * pUsdhcIpState = Usdhc_Ip_State[instance];

    /* SW reset the MMC card */
    Base->CMD_ARG     = 0xF0F0F0F0U;
    Base->CMD_XFR_TYP = 0x0U;

    /* Wait for more than 74 clock cycles for the card to be stable */
    u32startTime = OsIf_GetCounter(USDHC_IP_TIMEOUT_TYPE);
    u32currentTime = 0U;
    /* Waiting for reset operation complete */
    while (u32currentTime < USDHC_IP_WAIT_CARD_STABLE)
    {
        u32currentTime += OsIf_GetElapsed(&u32startTime, USDHC_IP_TIMEOUT_TYPE);
    }

    /* Set initialization active state by sending 80 clock cycles to the card */
    Usdhc_Ip_eTransferStatus = uSDHC_Ip_SetCardActive(instance);

    /* Set data bus width for boot */
    uSDHC_Ip_SetDataBusWidth(instance, UsdhcBootConfig->bootBusWidth);

    MixCtrlReg = Base->MIX_CTRL;

    MixCtrlReg &= ~USDHC_MIX_CTRL_DDR_EN_MASK;
    if ((boolean)TRUE == (boolean)UsdhcBootConfig->enableDDR)
    {
        MixCtrlReg |= USDHC_MIX_CTRL_DDR_EN_MASK;
    }
    MixCtrlReg |= USDHC_MIX_CTRL_MSBSEL_MASK | USDHC_MIX_CTRL_DTDSEL_MASK | USDHC_MIX_CTRL_BCEN_MASK;
    /* Configure block attributes and mix control registers */
    Base->MIX_CTRL    = MixCtrlReg;

    Base->BLK_ATT     = ((Base->BLK_ATT & ~(USDHC_BLK_ATT_BLKSIZE_MASK | USDHC_BLK_ATT_BLKCNT_MASK)) |
                         (USDHC_BLK_ATT_BLKSIZE(USDHC_IP_DEFAULT_BLOCK_SIZE) | USDHC_BLK_ATT_BLKCNT(numberBlocks)));

    /* Enable boot */
    Base->MMC_BOOT |= (USDHC_MMC_BOOT_BOOT_EN(1U));

    /* Start boot operation */
    Base->CMD_ARG     = 0xFFFFFFFAU;
    Base->CMD_XFR_TYP |= USDHC_CMD_XFR_TYP_DPSEL_MASK;

    /* Wait for Transfer complete flag */
    u32startTime = OsIf_GetCounter(USDHC_IP_TIMEOUT_TYPE);
    u32currentTime = 0U;
    while (0U == pUsdhcIpState->u16TransferComplete)
    {
        u32currentTime += OsIf_GetElapsed(&u32startTime, USDHC_IP_TIMEOUT_TYPE);
        if (u32currentTime >= USDHC_IP_SYNC_TRANSFER_TIMEOUT)
        {
            Usdhc_Ip_bDriverBusy = (boolean)FALSE;
            Usdhc_Ip_eTransferStatus = STATUS_USDHC_IP_TIMEOUT;
            /* Timeout errors */
            Usdhc_Ip_bFailedTimeout = (boolean)TRUE;
            break;
        }
    }
    if(0U != pUsdhcIpState->u16TransferComplete)
    {
        Usdhc_Ip_bDriverBusy = (boolean)FALSE;
        pUsdhcIpState->u16TransferComplete = 0U;
        Usdhc_Ip_eTransferStatus = STATUS_USDHC_IP_SUCCESS;
    }

    /* Stop boot process */
    if(USDHC_ALTER_MMC_BOOT == UsdhcBootConfig->bootMode)
    {
        Base->CMD_ARG     = 0x0U;
        Base->CMD_XFR_TYP = 0U;
    }
    Base->MMC_BOOT &= ~USDHC_MMC_BOOT_BOOT_EN(1U);

    return Usdhc_Ip_eTransferStatus;
}
#endif

/*==================================================================================================
                                       GLOBAL FUNCTIONS
==================================================================================================*/

/**
* @brief         uSDHC_Ip_Reset
* @details       Reset the uSDHC module
*
* @param[in]     Instance  USDHC hardware Instance
* @param[in]     Mask      Register mask to choose to reset data lines, command lines or all lines
* @param[in]     TimeoutMs Timeout for reset operation
*
* @return        Status
* @pre           The USDHC driver needs to be initialized
*/
Usdhc_Ip_StatusType uSDHC_Ip_Reset(uint32 Instance,
                                   uint32 Mask,
                                   uint32 TimeoutMs
                                  )
{
    USDHC_IP_DEV_ASSERT(Instance < USDHC_INSTANCE_COUNT);
    Usdhc_Ip_StatusType Status = STATUS_USDHC_IP_SUCCESS;
    USDHC_Type * Base          = Usdhc_Ip_BaseAddr[Instance];
    volatile uint32   ResetBit = 0U;
    /* Reset uSDHC module */
    Base->SYS_CTRL |= (Mask & (USDHC_SYS_CTRL_RSTA_MASK | USDHC_SYS_CTRL_RSTC_MASK | USDHC_SYS_CTRL_RSTD_MASK));

    Usdhc_Ip_u32UsdhcStartTime = OsIf_GetCounter(USDHC_IP_TIMEOUT_TYPE);
    Usdhc_Ip_u32UsdhcCurrentTime = 0U;

    ResetBit = (uint32)(Base->SYS_CTRL & Mask);
    MCAL_FAULT_INJECTION_POINT(MEM_43_EEP_FIP_FR_CHECK_WHILE_LOOP_CTRL_REG);

    /* Waiting for reset operation complete */
    while (0U != ResetBit)
    {
        Usdhc_Ip_u32UsdhcCurrentTime += OsIf_GetElapsed(&Usdhc_Ip_u32UsdhcStartTime, USDHC_IP_TIMEOUT_TYPE);
        if (Usdhc_Ip_u32UsdhcCurrentTime >= TimeoutMs)
        {
            Status = STATUS_USDHC_IP_TIMEOUT;
            /* Timeout errors */
            Usdhc_Ip_bFailedTimeout = (boolean)TRUE;
            break;
        }
        ResetBit = (uint32)(Base->SYS_CTRL & Mask);
    }

    return Status;
}

/**
* @brief         uSDHC_Ip_GetPresentStatusFlags
* @details       Get present status flags of USDHC
*
* @param[in]     Instance  USDHC hardware Instance
*
* @return        value of PRES_STATE register
* @pre           The USDHC driver needs to be initialized
*/
uint32 uSDHC_Ip_GetPresentStatusFlags(uint32 Instance)
{
    /* Checking input param */
    USDHC_IP_DEV_ASSERT(Instance < USDHC_INSTANCE_COUNT);
    /* Return the value in PRES_STATE register */
    return (Usdhc_Ip_BaseAddr[Instance]->PRES_STATE);
}

/**
* @brief         uSDHC_Ip_DiscardData
* @details       Discard data in the host controller buffer
*
* @param[in]     Instance  USDHC hardware Instance
*
* @return        void
* @pre           The USDHC driver needs to be initialized
*/
void uSDHC_Ip_DiscardData(uint32 Instance)
{
    uint32 Timeout = (uint32)USDHC_IP_RESET_TIMEOUT;
    uint32 PresentStatusFlags;

    /* Make sure there is no incomplete data transferring */
    do
    {
        PresentStatusFlags = uSDHC_Ip_GetPresentStatusFlags(Instance);
        if (0UL == (PresentStatusFlags & (USDHC_PRES_STATE_CIHB_MASK | USDHC_PRES_STATE_CDIHB_MASK)))
        {
            /* Both DATA and CMD lines are not in use */
            break;
        }

        Timeout--;
    }
    while (Timeout > 0UL);

    /* Reset all DATA and CMD lines */
    (void)uSDHC_Ip_Reset(Instance, (uint32)USDHC_SYS_CTRL_RSTA_MASK, (uint32)USDHC_IP_RESET_TIMEOUT);
}

/**
* @brief         uSDHC_Ip_Init
* @details       Initializes uSDHC module.
*
* @param[in]     State    USDHC state variable
* @param[in]     Config   USDHC initialization configuration
* @param[in]     Instance USDHC hardware instance
*
* @return        status
* @pre           N/A
*/
/* implements uSDHC_Ip_Init_Activity */
Usdhc_Ip_StatusType uSDHC_Ip_Init(Usdhc_Ip_StateType * State,
                                  const Usdhc_Ip_ConfigType * Config,
                                  uint32 Instance
                                 )
{
    /* Checking input param */
    USDHC_IP_DEV_ASSERT(Config != NULL_PTR);
    uint32 ProtCtrlReg;
    uSDHC_Ip_InitAllVarriable(Instance);

    USDHC_Type * Base          = Usdhc_Ip_BaseAddr[Instance];
    Usdhc_Ip_StatusType Status = STATUS_USDHC_IP_SUCCESS;

    /* Reset uSDHC. */
    Status = uSDHC_Ip_Reset(Instance, (uint32)USDHC_SYS_CTRL_RSTA_MASK, (uint32)USDHC_IP_RESET_TIMEOUT);

    /* Reset USDHC registers to reset values */
    uSDHC_Ip_ResetRegisters(Base);

    if (STATUS_USDHC_IP_SUCCESS == Status)
    {
        /* Configures the usdhc protocol via the PROT_CTRL register */
        ProtCtrlReg = Base->PROT_CTRL;
        ProtCtrlReg &= ~(USDHC_PROT_CTRL_D3CD_MASK | USDHC_PROT_CTRL_EMODE_MASK | USDHC_PROT_CTRL_DMASEL_MASK);
        /* Set DAT3 as card detection pin */
        if (Config->cardDetectDat3)
        {
            ProtCtrlReg |= USDHC_PROT_CTRL_D3CD_MASK;
        }
        /* Endian mode and DMA mode */
        ProtCtrlReg |= (USDHC_PROT_CTRL_EMODE(Config->endianMode) | USDHC_PROT_CTRL_DMASEL(Config->dmaMode));
        Base->PROT_CTRL = ProtCtrlReg;
        /* Write and Read Watermark Level*/
        ProtCtrlReg = 0U;
        ProtCtrlReg |= (USDHC_WTMK_LVL_WR_WML(Config->writeWatermarkLevel) | USDHC_WTMK_LVL_RD_WML(Config->readWatermarkLevel));
        Base->WTMK_LVL = ProtCtrlReg;
        /* Initial uSDHC state */
        State->admaTable                     = Config->admaTable;
        State->admaTableSize                 = Config->admaTableSize;
        State->transferErrorCallback         = Config->transferErrorCallback;
        State->transferCompleteCallback      = Config->transferCompleteCallback;
        State->cardInsertCallback            = Config->cardInsertCallback;
        State->cardRemoveCallback            = Config->cardRemoveCallback;
        State->blockGapCallback              = Config->blockGapCallback;
        State->cardIntCallback               = Config->cardIntCallback;
        Usdhc_Ip_State[Instance]             = State;

        State->u16TransferComplete = 0U;

        /* Clear all interrupt status flags */
        Base->INT_STATUS_EN = ~USDHC_ALL_INTERRUPTS_MASK;
        /* Disable all interrupt signal */
        Base->INT_SIGNAL_EN = ~USDHC_ALL_INTERRUPTS_MASK;

        /* Clear interrupt status flag */
        Base->INT_STATUS_EN |= USDHC_INT_STATUS_CC_MASK | USDHC_INT_STATUS_TC_MASK;
        /* Enable interrupt signal */
        Base->INT_SIGNAL_EN |= USDHC_INT_STATUS_CC_MASK | USDHC_INT_STATUS_TC_MASK;

        /* Clear error status flag */
        Base->INT_STATUS_EN |= USDHC_COMMAND_ERROR_INT | USDHC_DATA_ERROR_INT;
        /* Enables error interrupts */
        Base->INT_SIGNAL_EN |= USDHC_COMMAND_ERROR_INT | USDHC_DATA_ERROR_INT;

        /* Enables DMA interrupts if enabled */
        switch (Config->dmaMode)
        {
            case USDHC_DMA_MODE_ADMA1:
            case USDHC_DMA_MODE_ADMA2:
                /* Clear DMAE flag flag */
                Base->INT_STATUS_EN |= USDHC_INT_STATUS_DMAE_MASK | USDHC_INT_STATUS_DINT_MASK;
                /* Enables DMA interrupts */
                Base->INT_SIGNAL_EN |= USDHC_INT_STATUS_DMAE_MASK | USDHC_INT_STATUS_DINT_MASK;
                break;

            case USDHC_DMA_MODE_NO_DMA:
                /* Clear BRR flag */
                Base->INT_STATUS_EN |= USDHC_INT_STATUS_BRR_MASK | USDHC_INT_STATUS_BWR_MASK;
                /* Enables BRR interrupts */
                Base->INT_SIGNAL_EN |= USDHC_INT_STATUS_BRR_MASK | USDHC_INT_STATUS_BWR_MASK;
                break;

            default:
                /* Do nothing */
                break;
        }

        uSDHC_Ip_InitCallBacks(Config, Instance, Base);
    }

    return Status;
}

/**
* @brief         uSDHC_Ip_InitCallBacks
* @details       Initializes configured callbacks

* @return        void
* @pre           The USDHC driver needs to be initialized
*/
static void uSDHC_Ip_InitCallBacks(const Usdhc_Ip_ConfigType * Config,
                                   uint32 Instance,
                                   USDHC_Type * Base
                                  )
{
    if (NULL_PTR != Config->transferCompleteCallback)
    {
        Usdhc_Ip_State[Instance]->transferCompleteCallback = Config->transferCompleteCallback;
    }
    if (NULL_PTR != Config->transferErrorCallback)
    {
        Usdhc_Ip_State[Instance]->transferErrorCallback = Config->transferErrorCallback;
    }

    if (NULL_PTR != Config->cardInsertCallback)
    {
        /* Save notification pointer */
        Usdhc_Ip_State[Instance]->cardInsertCallback = Config->cardInsertCallback;
        /* Clear card insertion flag */
        Base->INT_STATUS_EN |= USDHC_INT_STATUS_CINS_MASK;
        /* Enables card insertion interrupts */
        Base->INT_SIGNAL_EN |= USDHC_INT_STATUS_CINS_MASK;
    }
    else
    {
        /* Clear interrupt status flag */
        Base->INT_STATUS_EN &= ~USDHC_INT_STATUS_CINS_MASK;
        /* Disable interrupt signal */
        Base->INT_SIGNAL_EN &= ~USDHC_INT_STATUS_CINS_MASK;
    }

    if (NULL_PTR != Config->cardRemoveCallback)
    {
        /* Save notification pointer */
        Usdhc_Ip_State[Instance]->cardRemoveCallback = Config->cardRemoveCallback;
        /* Clear card removal flag */
        Base->INT_STATUS_EN |= USDHC_INT_STATUS_CRM_MASK;
        /* Enables card removal interrupt */
        Base->INT_SIGNAL_EN |= USDHC_INT_STATUS_CRM_MASK;
    }
    else
    {
        /* Clear interrupt status flag */
        Base->INT_STATUS_EN &= ~USDHC_INT_STATUS_CRM_MASK;
        /* Disable interrupt signal */
        Base->INT_SIGNAL_EN &= ~USDHC_INT_STATUS_CRM_MASK;
    }

    if (NULL_PTR != Config->blockGapCallback)
    {
        /* Save notification pointer */
        Usdhc_Ip_State[Instance]->blockGapCallback = Config->blockGapCallback;
        /* Clear block gap flag */
        Base->INT_STATUS_EN |= USDHC_INT_STATUS_BGE_MASK;
        /* Enables block gap interrupt */
        Base->INT_SIGNAL_EN |= USDHC_INT_STATUS_BGE_MASK;
    }
    else
    {
        /* Clear block gap interrupt status flag */
        Base->INT_STATUS_EN &= ~USDHC_INT_STATUS_BGE_MASK;
        /* Disable block gap interrupt signal */
        Base->INT_SIGNAL_EN &= ~USDHC_INT_STATUS_BGE_MASK;
    }
    if (NULL_PTR != Config->cardIntCallback)
    {
        /* Save notification pointer */
        Usdhc_Ip_State[Instance]->cardIntCallback = Config->cardIntCallback;
        /* Clear card flag */
        Base->INT_STATUS_EN |= USDHC_INT_STATUS_CINT_MASK;
        /* Enables card interrupt */
        Base->INT_SIGNAL_EN |= USDHC_INT_STATUS_CINT_MASK;
    }
    else
    {
        /* Clear card interrupt status flag */
        Base->INT_STATUS_EN &= ~USDHC_INT_STATUS_CINT_MASK;
        /* Disable card interrupt signal */
        Base->INT_SIGNAL_EN &= ~USDHC_INT_STATUS_CINT_MASK;
    }
}

/**
* @brief         uSDHC_Ip_DeInit
* @details       Deinitializes a uSDHC module.
*
* @param[in]     Instance USDHC hardware Instance
*
* @return        status
* @pre           The USDHC driver needs to be initialized
*/
Usdhc_Ip_StatusType uSDHC_Ip_DeInit(uint32 Instance)
{
    /* Checking input param */
    USDHC_IP_DEV_ASSERT(Instance < USDHC_INSTANCE_COUNT);
    USDHC_Type * Base             = Usdhc_Ip_BaseAddr[Instance];
    Usdhc_Ip_StateType * State    = Usdhc_Ip_State[Instance];

    /* if the instance was not initialized, do nothing */
    if (NULL_PTR != State)
    {
        /* Clear interrupt status flag */
        Base->INT_STATUS_EN = ~USDHC_ALL_INTERRUPTS_MASK;
        /* Disable interrupt signal */
        Base->INT_SIGNAL_EN = ~USDHC_ALL_INTERRUPTS_MASK;

        /* Destroy the synchronization objects */
        State->u16TransferComplete = 0U;
    }

    return STATUS_USDHC_IP_SUCCESS;
}

/**
* @brief         uSDHC_Ip_SetDataBusWidth
* @details       Set data bus width for uSDHC module
*
* @param[in]     Instance        USDHC hardware Instance
* @param[in]     Width           USDHC data bus width
*
* @return        void
* @pre           The USDHC driver needs to be initialized 
*/
void uSDHC_Ip_SetDataBusWidth(uint32 Instance,
                              Usdhc_Ip_DataBusWidthType Width
                             )
{
    /* Checking input param */
    USDHC_IP_DEV_ASSERT(Instance < USDHC_INSTANCE_COUNT);
    USDHC_Type * Base = Usdhc_Ip_BaseAddr[Instance];

    Base->PROT_CTRL = ((Base->PROT_CTRL & ~USDHC_PROT_CTRL_DTW_MASK) | USDHC_PROT_CTRL_DTW(Width));
}

/**
* @brief         uSDHC_Ip_SwitchVoltage
* @details       Enable/disable low voltage operation
*
* @param[in]     Instance     USDHC hardware Instance
* @param[in]     IsLowVoltage Enable/Disable low voltage
*
* @return        status
* @pre           The USDHC driver needs to be initialized 
*/
Usdhc_Ip_StatusType uSDHC_Ip_SwitchVoltage(uint32 Instance,
                                           boolean IsLowVoltage
                                          )
{
    USDHC_Type * Base = Usdhc_Ip_BaseAddr[Instance];
    Usdhc_Ip_StatusType Status = STATUS_USDHC_IP_SUCCESS;
    volatile uint32   PresentStatusFlags = 0U;

    Base->VEND_SPEC &= ~USDHC_VEND_SPEC_FRC_SDCLK_ON_MASK;
#if (USDHC_IP_V180_SUPPORT == STD_ON)
    /* host switch to 1.8V */
    Base->VEND_SPEC = (Base->VEND_SPEC & ~USDHC_VEND_SPEC_VSELECT_MASK) | USDHC_VEND_SPEC_VSELECT((TRUE == IsLowVoltage) ? 1U : 0U);
#endif /* USDHC_IP_V180_SUPPORT */

    /* uSDHC_Enable SD clock */
    Base->VEND_SPEC |= USDHC_VEND_SPEC_FRC_SDCLK_ON_MASK;

    Usdhc_Ip_u32UsdhcStartTime = OsIf_GetCounter(USDHC_IP_TIMEOUT_TYPE);
    Usdhc_Ip_u32UsdhcCurrentTime = 0U;

    PresentStatusFlags = (uint32)(uSDHC_Ip_GetPresentStatusFlags(Instance) & (uint32)USDHC_PRES_STATE_SDSTB_MASK);

    /* Label for checking test timeout */
    MCAL_FAULT_INJECTION_POINT(MEM_43_EEP_CHECK_WHILE_LOOP_PRESENT_STATUS_FLAG_1);

    /* Wait until the internal card clock is stable. */
    while (0U == PresentStatusFlags)
    {
        Usdhc_Ip_u32UsdhcCurrentTime += OsIf_GetElapsed(&Usdhc_Ip_u32UsdhcStartTime, USDHC_IP_TIMEOUT_TYPE);
        if (Usdhc_Ip_u32UsdhcCurrentTime >= USDHC_IP_SWITCH_VOLTAGE_TIMEOUT)
        {
            Status = STATUS_USDHC_IP_TIMEOUT;
            /* Timeout errors */
            Usdhc_Ip_bFailedTimeout = (boolean)TRUE;
            break;
        }
        PresentStatusFlags = (uint32)(uSDHC_Ip_GetPresentStatusFlags(Instance) & (uint32)USDHC_PRES_STATE_SDSTB_MASK);
    }

    Usdhc_Ip_u32UsdhcStartTime = OsIf_GetCounter(USDHC_IP_TIMEOUT_TYPE);
    Usdhc_Ip_u32UsdhcCurrentTime = 0U;

    PresentStatusFlags = (uint32)(uSDHC_Ip_GetPresentStatusFlags(Instance) & ((uint32)USDHC_PRES_STATE_CIHB_MASK | (uint32)USDHC_PRES_STATE_CDIHB_MASK));

    /* Label for checking test timeout */
    MCAL_FAULT_INJECTION_POINT(MEM_43_EEP_CHECK_WHILE_LOOP_PRESENT_STATUS_FLAG_2);

    /* Wait until the usdhc can issue command. */
    while (0U != PresentStatusFlags)
    {
        Usdhc_Ip_u32UsdhcCurrentTime += OsIf_GetElapsed(&Usdhc_Ip_u32UsdhcStartTime, USDHC_IP_TIMEOUT_TYPE);
        if (Usdhc_Ip_u32UsdhcCurrentTime >= USDHC_IP_SWITCH_VOLTAGE_TIMEOUT)
        {
            Status = STATUS_USDHC_IP_TIMEOUT;
            /* Timeout errors */
            Usdhc_Ip_bFailedTimeout = (boolean)TRUE;
            break;
        }
        PresentStatusFlags = (uint32)(uSDHC_Ip_GetPresentStatusFlags(Instance) & ((uint32)USDHC_PRES_STATE_CIHB_MASK | (uint32)USDHC_PRES_STATE_CDIHB_MASK));
    }

#if (USDHC_IP_V180_SUPPORT == STD_ON)
    if (TRUE == IsLowVoltage)
    {
        Usdhc_Ip_u32UsdhcStartTime = OsIf_GetCounter(USDHC_IP_TIMEOUT_TYPE);
        Usdhc_Ip_u32UsdhcCurrentTime = 0U;

        PresentStatusFlags = (uint32)(uSDHC_Ip_GetPresentStatusFlags(Instance) & ((uint32)USDHC_DATA0_LINE_LEVEL));

        /* Label for checking test timeout */
        MCAL_FAULT_INJECTION_POINT(MEM_43_EEP_CHECK_WHILE_LOOP_PRESENT_STATUS_FLAG_3);

        /* check data line and cmd line status */
        while (0U == PresentStatusFlags)
        {
            Usdhc_Ip_u32UsdhcCurrentTime += OsIf_GetElapsed(&Usdhc_Ip_u32UsdhcStartTime, USDHC_IP_TIMEOUT_TYPE);
            if (Usdhc_Ip_u32UsdhcCurrentTime >= USDHC_IP_SWITCH_VOLTAGE_TIMEOUT)
            {
                Status = STATUS_USDHC_IP_TIMEOUT;
                /* Timeout errors */
                Usdhc_Ip_bFailedTimeout = (boolean)TRUE;
                break;
            }
            PresentStatusFlags = (uint32)(uSDHC_Ip_GetPresentStatusFlags(Instance) & ((uint32)USDHC_DATA0_LINE_LEVEL));
        }
    }
#else
    (void)IsLowVoltage;
#endif /* USDHC_IP_V180_SUPPORT */

    return Status;
}

/**
* @brief         uSDHC_Ip_GetCapability
* @details       Get supported capability of uSDHC module
*
* @param[in]     Instance     USDHC hardware Instance
* @param[in]     Capability  pointer to store module capability
*
* @return        void
* @pre           The USDHC driver needs to be initialized 
*/
void uSDHC_Ip_GetCapability(uint32 Instance,
                            Usdhc_Ip_ControllerCapabilityType * Capability
                           )
{
    /* Checking input params */
    USDHC_IP_DEV_ASSERT(Instance < USDHC_INSTANCE_COUNT);
    USDHC_IP_DEV_ASSERT(Capability != NULL_PTR);

#if defined(FEATURE_USDHC_HAS_HOST_CTRL_VER)
    uint32 HostVer;
#endif
    uint32 MaxBlockLength;
    const USDHC_Type * Base = Usdhc_Ip_BaseAddr[Instance];
    uint32 HtCapability     = Base->HOST_CTRL_CAP;

#if defined(FEATURE_USDHC_HAS_HOST_CTRL_VER)
    /* If uSDHC module support HOST_CTRL_VER register */
    HostVer          = Base->HOST_CTRL_VER;;
    /* store version */
    Capability->specVersion   = ((HostVer & USDHC_HOST_CTRL_VER_SVN_MASK) >> USDHC_HOST_CTRL_VER_SVN_SHIFT);
    Capability->vendorVersion = ((HostVer & USDHC_HOST_CTRL_VER_VVN_MASK) >> USDHC_HOST_CTRL_VER_VVN_SHIFT);
#endif
    /* Read maximum block length number */
    MaxBlockLength             = ((HtCapability & USDHC_HOST_CTRL_CAP_MBL_MASK) >> USDHC_HOST_CTRL_CAP_MBL_SHIFT);
    /* Store MaxBlockLength */
    Capability->maxBlockLength = (512UL << MaxBlockLength);
    /* Store maxBlockCount */
    Capability->maxBlockCount  = USDHC_MAX_BLOCK_COUNT;
    /* Store DMA support */
    Capability->flags          = (HtCapability & (USDHC_HOST_CTRL_CAP_ADMAS_MASK | USDHC_HOST_CTRL_CAP_HSS_MASK | USDHC_HOST_CTRL_CAP_DMAS_MASK |\
                                                  USDHC_HOST_CTRL_CAP_SRS_MASK));

    /* Store voltages support */
#if (USDHC_IP_V330_SUPPORT == STD_ON)
    Capability->flags         |= (HtCapability & USDHC_HOST_CTRL_CAP_VS33_MASK);
#endif

#if (USDHC_IP_V300_SUPPORT == STD_ON)
    Capability->flags         |= (HtCapability & USDHC_HOST_CTRL_CAP_VS30_MASK);
#endif

#if (USDHC_IP_V180_SUPPORT == STD_ON)
    Capability->flags         |= (HtCapability & USDHC_HOST_CTRL_CAP_VS18_MASK);
#endif

    Capability->flags         |= (USDHC_HOST_CTRL_CAP_SUPPORT_4BIT | USDHC_HOST_CTRL_CAP_SUPPORT_8BIT);
}

/**
* @brief         uSDHC_Ip_SetBusClock
* @details       Get supported capability of uSDHC module
*
* @param[in]     Instance          USDHC hardware Instance
* @param[in]     BusClock          USDHC bus clock frequency
* @param[in]     SrcClock          USDHC source clock frequency
* @param[out]    NearestFrequency  Pointer to store nearest frequency
*
* @return        status
* @pre           The USDHC driver needs to be initialized 
*/
Usdhc_Ip_StatusType uSDHC_Ip_SetBusClock(uint32 Instance,
                                         uint32 BusClock,
                                         uint32 SrcClock,
                                         uint32 *NearestFrequency
                                        )
{
    const uint32 divisor[4] = {1U, 2U, 15U, 16U};
    uint32 Index;
    uint32 FinalDivisor = 1U;
    uint32 Prescaler;
    uint32 FinalPrescaler = 1U;
    uint32 Deviation;
    uint32 PreDeviation = 0xFFFFFFFFU;
    uint32 SdFrequency;
    uint32 SysCtrlReg;
    Usdhc_Ip_StatusType Status = STATUS_USDHC_IP_SUCCESS;
    USDHC_Type * Base = Usdhc_Ip_BaseAddr[Instance];
    volatile uint32   PresentStatusFlags = 0U;

    /* Checking input params */
    USDHC_IP_DEV_ASSERT(Instance < USDHC_INSTANCE_COUNT);
    USDHC_IP_DEV_ASSERT(SrcClock > 0U);

    /* Disable SD clock. It should be disabled before changing the SD clock frequency.*/
    Base->VEND_SPEC &= ~USDHC_VEND_SPEC_FRC_SDCLK_ON_MASK;

    for (Prescaler = USDHC_INITIAL_CLKFS; Prescaler < USDHC_MAX_CLKFS; USDHC_NEXT_CLKFS(Prescaler))
    {
        for (Index = 0U; Index < 4U; Index++)
        {
            SdFrequency = (BusClock / Prescaler) / divisor[Index];
            if(SdFrequency > SrcClock)
            {
                Deviation = SdFrequency - SrcClock;
            }
            else
            {
                Deviation = SrcClock - SdFrequency;
            }
            if(Deviation < PreDeviation)
            {
                PreDeviation = Deviation;
                FinalDivisor = divisor[Index];
                FinalPrescaler = Prescaler;
            }
        }
    }
    *NearestFrequency = (BusClock / FinalPrescaler) / FinalDivisor;
    /* Set the SD clock frequency divisor, SD clock frequency select */
    SysCtrlReg = Base->SYS_CTRL;
    SysCtrlReg &= ~(USDHC_SYS_CTRL_DVS_MASK | USDHC_SYS_CTRL_SDCLKFS_MASK | USDHC_SYS_CTRL_DTOCV_MASK);
    SysCtrlReg |= (USDHC_SYS_CTRL_DVS(FinalDivisor - 1U) | USDHC_SYS_CTRL_SDCLKFS(FinalPrescaler >> 1U) | USDHC_SYS_CTRL_DTOCV(0xFU));
    Base->SYS_CTRL = SysCtrlReg;

    Usdhc_Ip_u32UsdhcStartTime = OsIf_GetCounter(USDHC_IP_TIMEOUT_TYPE);
    Usdhc_Ip_u32UsdhcCurrentTime = 0U;

    PresentStatusFlags = (uint32)(uSDHC_Ip_GetPresentStatusFlags(Instance) & (uint32)USDHC_PRES_STATE_SDSTB_MASK);

    MCAL_FAULT_INJECTION_POINT(MEM_43_EEP_CHECK_WHILE_LOOP_IP_SET_BUS_CLOCK);

    /* Waiting for SD clock is stable */
    while (0U == PresentStatusFlags)
    {
        Usdhc_Ip_u32UsdhcCurrentTime += OsIf_GetElapsed(&Usdhc_Ip_u32UsdhcStartTime, USDHC_IP_TIMEOUT_TYPE);
        if (Usdhc_Ip_u32UsdhcCurrentTime >= USDHC_IP_SETBUSCLOCK_TIMEOUT)
        {
            Status = STATUS_USDHC_IP_TIMEOUT;
            /* Timeout errors */
            Usdhc_Ip_bFailedTimeout = (boolean)TRUE;
            break;
        }
        PresentStatusFlags = (uint32)(uSDHC_Ip_GetPresentStatusFlags(Instance) & (uint32)USDHC_PRES_STATE_SDSTB_MASK);
    }

    /* Enable the SD clock. */
    Base->VEND_SPEC |= USDHC_VEND_SPEC_FRC_SDCLK_ON_MASK;

    return Status;
}

/**
* @brief         uSDHC_Ip_SetCardActive
* @details       Send 80 clock cycles to card to activate the card
*
* @param[in]     Instance          USDHC hardware instance
*
* @return        status
* @pre           The USDHC driver needs to be initialized 
*/
Usdhc_Ip_StatusType uSDHC_Ip_SetCardActive(uint32 Instance)
{
    Usdhc_Ip_StatusType Status = STATUS_USDHC_IP_SUCCESS;
    USDHC_Type * Base          = Usdhc_Ip_BaseAddr[Instance];
    volatile uint32   ResetBit = 0U;

    /* Checking input param */
    USDHC_IP_DEV_ASSERT(Instance < USDHC_INSTANCE_COUNT);

    /* Sending clock to init card */
    Base->SYS_CTRL |= USDHC_SYS_CTRL_INITA_MASK;

    Usdhc_Ip_u32UsdhcStartTime = OsIf_GetCounter(USDHC_IP_TIMEOUT_TYPE);
    Usdhc_Ip_u32UsdhcCurrentTime = 0U;

    ResetBit = (uint32)(Base->SYS_CTRL & USDHC_SYS_CTRL_INITA_MASK);

    MCAL_FAULT_INJECTION_POINT(MEM_43_EEP_CHECK_WHILE_LOOP_IP_SET_CARD_ACTIVE);

    /* Wait for 80 clock cycles are sent */
    while (0U != ResetBit)
    {
        Usdhc_Ip_u32UsdhcCurrentTime += OsIf_GetElapsed(&Usdhc_Ip_u32UsdhcStartTime, USDHC_IP_TIMEOUT_TYPE);
        if (Usdhc_Ip_u32UsdhcCurrentTime >= USDHC_IP_SETCARDACTIVE_TIMEOUT)
        {
            Status = STATUS_USDHC_IP_TIMEOUT;
            /* Timeout errors */
            Usdhc_Ip_bFailedTimeout = (boolean)TRUE;
            break;
        }
        ResetBit = (uint32)(Base->SYS_CTRL & USDHC_SYS_CTRL_INITA_MASK);
    }

    return Status;
}

/**
* @brief         uSDHC_Ip_TransferProcess
* @details       Get the response from card if response is available

* @return        void
* @pre           The USDHC driver needs to be initialized
*/
static void uSDHC_Ip_TransferProcess(uint32 Instance,
                                     const Usdhc_Ip_TransferType * Transfer,
                                     boolean AsyncEnable
                                    )
{
    USDHC_Type           * Base          = Usdhc_Ip_BaseAddr[Instance];
    Usdhc_Ip_StateType   * TransferState = Usdhc_Ip_State[Instance];
    Usdhc_Ip_CommandType * Command       = Transfer->command;
    Usdhc_Ip_DataType    * Data          = Transfer->data;

    if ((boolean)FALSE == Usdhc_Ip_bDriverBusy)
    {
        /* Save command and data into handle before transferring. */
        Usdhc_Ip_State[Instance]->command          = Command;
        Usdhc_Ip_State[Instance]->data             = Data;
        /* transferredWords will only be updated in ISR when transfer way is DATAPORT. */
        Usdhc_Ip_State[Instance]->transferredWords = 0U;

        /* Start transfer */
        uSDHC_Ip_StartTransfer(Base, Command, Data);

        Usdhc_Ip_u32UsdhcStartTime = OsIf_GetCounter(USDHC_IP_TIMEOUT_TYPE);
        Usdhc_Ip_u32UsdhcCurrentTime = 0U;
    }

    MCAL_FAULT_INJECTION_POINT(MEM_43_EEP_CHECK_WHILE_LOOP_TRANFER_PROCESS);

    if (FALSE == AsyncEnable)
    {
        while (0U == TransferState->u16TransferComplete)
        {
            Usdhc_Ip_u32UsdhcCurrentTime += OsIf_GetElapsed(&Usdhc_Ip_u32UsdhcStartTime, USDHC_IP_TIMEOUT_TYPE);
            if (Usdhc_Ip_u32UsdhcCurrentTime >= USDHC_IP_SYNC_TRANSFER_TIMEOUT)
            {
                Usdhc_Ip_bDriverBusy = (boolean)FALSE;
                Usdhc_Ip_eTransferStatus = STATUS_USDHC_IP_TIMEOUT;
                /* Timeout errors */
                Usdhc_Ip_bFailedTimeout = (boolean)TRUE;
                break;
            }
        }

        if (0U != TransferState->u16TransferComplete)
        {
            Usdhc_Ip_bDriverBusy = (boolean)FALSE;
            TransferState->u16TransferComplete = 0U;
            Usdhc_Ip_eTransferStatus = STATUS_USDHC_IP_SUCCESS;
        }
    }
    else /*TRUE == AsyncEnable*/
    {
        if ((0U != TransferState->u16TransferComplete) && (STATUS_USDHC_IP_PENDING == Usdhc_Ip_eTransferStatus))
        {
            Usdhc_Ip_bDriverBusy = (boolean)FALSE;
            TransferState->u16TransferComplete = 0U;
            Usdhc_Ip_eTransferStatus = STATUS_USDHC_IP_SUCCESS;
        }
        else
        {
            /* Job is pending and waiting for done */
            Usdhc_Ip_eTransferStatus = STATUS_USDHC_IP_PENDING;
            /* Hardware will be setup once until work is done */
            Usdhc_Ip_bDriverBusy = (boolean)TRUE;
            Usdhc_Ip_u32UsdhcCurrentTime += OsIf_GetElapsed(&Usdhc_Ip_u32UsdhcStartTime, USDHC_IP_TIMEOUT_TYPE);
            if (Usdhc_Ip_u32UsdhcCurrentTime >= USDHC_IP_ASYNC_TRANSFER_TIMEOUT)
            {
                Usdhc_Ip_eTransferStatus = STATUS_USDHC_IP_TIMEOUT;
                Usdhc_Ip_bDriverBusy = (boolean)FALSE;
                /* Timeout errors */
                Usdhc_Ip_bFailedTimeout = (boolean)TRUE;
            }
        }
    }
}


/**
* @brief         uSDHC_Ip_Transfer
* @details       Send a command or data using non-blocking mode to the card and get the response from card if response is available
*
* @param[in]     Instance          USDHC hardware instance
* @param[in]     Transfer          pointer to store transfer information 
* @param[in]     AsyncEnable       enable/disable asynchronous mode
*
* @return        status
* @pre           The USDHC driver needs to be initialized 
*/
Usdhc_Ip_StatusType uSDHC_Ip_Transfer(uint32 Instance,
                                      const Usdhc_Ip_TransferType * Transfer,
                                      boolean AsyncEnable
                                     )
{
    USDHC_IP_DEV_ASSERT(Instance < USDHC_INSTANCE_COUNT);
    USDHC_IP_DEV_ASSERT(Transfer != NULL_PTR);
    USDHC_IP_DEV_ASSERT(Transfer->command != NULL_PTR);  /* Command must not be NULL_PTR, data can be NULL_PTR. */
    USDHC_Type * Base                  = Usdhc_Ip_BaseAddr[Instance];
    Usdhc_Ip_DmaModeType DmaMode       = (Usdhc_Ip_DmaModeType)((Base->PROT_CTRL & USDHC_PROT_CTRL_DMASEL_MASK) >> USDHC_PROT_CTRL_DMASEL_SHIFT);
    const Usdhc_Ip_DataType * Data     = Transfer->data;
    uint32 presentStatus               = 0U;
    const Usdhc_Ip_StateType * TransferState = Usdhc_Ip_State[Instance];

    /* Check block size for current transfer */
    Usdhc_Ip_eTransferStatus = uSDHC_Ip_CheckBlockSize(Data, DmaMode);

    if ((STATUS_USDHC_IP_ERROR != Usdhc_Ip_eTransferStatus) && ((boolean)FALSE == Usdhc_Ip_bDriverBusy))
    {
        /* Put as success before */
        Usdhc_Ip_eTransferStatus = STATUS_USDHC_IP_SUCCESS;
        /* Wait until command/data bus out of busy status. */
        presentStatus = uSDHC_Ip_GetPresentStatusFlags(Instance);
        if (((presentStatus & USDHC_PRES_STATE_CIHB_MASK) != 0U) || ((Data != NULL_PTR) && ((presentStatus & USDHC_PRES_STATE_CDIHB_MASK) != 0U)))
        {
            Usdhc_Ip_eTransferStatus = STATUS_USDHC_IP_BUSY;
        }
        else
        {
            if (Data != NULL_PTR)
            {
                /* Update ADMA descriptor table and reset transferred words if data isn't NULL_PTR. */
                Usdhc_Ip_eTransferStatus = uSDHC_Ip_SetAdmaTableConfig(Base, DmaMode, TransferState,
                                                    ((Data->rxData != NULL_PTR) ? Data->rxData : Data->txData),
                                                    (Data->blockCount * Data->blockSize));
            }
        }
    }

    if ((STATUS_USDHC_IP_SUCCESS == Usdhc_Ip_eTransferStatus) || (STATUS_USDHC_IP_PENDING == Usdhc_Ip_eTransferStatus))
    {
        /* Check for response */
        uSDHC_Ip_TransferProcess(Instance, Transfer, AsyncEnable);
    }

    return Usdhc_Ip_eTransferStatus;
}

Usdhc_Ip_StatusType uSDHC_Ip_Abort(uint32 Instance)
{
    USDHC_Type * Base                  = Usdhc_Ip_BaseAddr[Instance];
    Usdhc_Ip_StateType * TransferState = Usdhc_Ip_State[Instance];
    uint32 InterruptFlags              = Base->INT_STATUS;
    boolean ExitLoop                   = (boolean)FALSE;

    /* Check if it has on going operation */
    if (STATUS_USDHC_IP_PENDING == Usdhc_Ip_eTransferStatus)
    {
        Usdhc_Ip_u32UsdhcStartTime = OsIf_GetCounter(USDHC_IP_TIMEOUT_TYPE);
        Usdhc_Ip_u32UsdhcCurrentTime = 0U;

        MCAL_FAULT_INJECTION_POINT(MEM_43_EEP_CHECK_WHILE_LOOP_ABORT);

        /* Abort job */
        uSDHC_Ip_SetSABGREQ(Instance);

        while ((0U == TransferState->u16TransferComplete) && ((InterruptFlags & USDHC_INT_STATUS_TC_MASK) != USDHC_INT_STATUS_TC_MASK))
        {
            InterruptFlags = Base->INT_STATUS;
            Usdhc_Ip_u32UsdhcCurrentTime += OsIf_GetElapsed(&Usdhc_Ip_u32UsdhcStartTime, USDHC_IP_TIMEOUT_TYPE);
            if (Usdhc_Ip_u32UsdhcCurrentTime >= USDHC_IP_ABORT_TRANSFER_TIMEOUT)
            {
                /* Timeout errors */
                Usdhc_Ip_bFailedTimeout = (boolean)TRUE;
                ExitLoop = (boolean)TRUE;
            }

            /* Checking if erase command was complete */
            if ((NULL_PTR == TransferState->data) && (USDHC_INT_STATUS_CC_MASK == (InterruptFlags & USDHC_INT_STATUS_CC_MASK)))
            {
                ExitLoop = (boolean)TRUE;
            }

            if ((boolean)TRUE == ExitLoop)
            {
                break;
            }
        }

        /* Clear the stop request */
        uSDHC_Ip_ClearSABGREQ(Instance);

        /* Reset the states */
        Usdhc_Ip_bDriverBusy = (boolean)FALSE;
        TransferState->u16TransferComplete = 0U;
        Base->INT_STATUS = InterruptFlags;

        if ((boolean)TRUE == Usdhc_Ip_bFailedTimeout)
        {
            /* Timeout error occurred */
            Usdhc_Ip_eTransferStatus = STATUS_USDHC_IP_TIMEOUT;
        }
        else
        {
            Usdhc_Ip_eTransferStatus = STATUS_USDHC_IP_SUCCESS;
        }
    }

    return Usdhc_Ip_eTransferStatus;
}


/**
* @brief         uSDHC_Ip_SetSABGREQ
* @details       Stops executing a transaction at the next block gap request
*
* @param[in]     Instance         USDHC hardware instance
*
* @return        void
* @pre           The USDHC driver needs to be initialized
*/
void uSDHC_Ip_SetSABGREQ(uint32 Instance)
{
    USDHC_Type * Base = Usdhc_Ip_BaseAddr[Instance];

    /* Stop at block gap request */
    Base->PROT_CTRL |= USDHC_PROT_CTRL_SABGREQ_MASK;
}


/**
* @brief         uSDHC_Ip_ClearSABGREQ
* @details       Clear the stop at block gap request
*
* @param[in]     Instance         USDHC hardware instance
*
* @return        void
* @pre           The USDHC driver needs to be initialized
*/
void uSDHC_Ip_ClearSABGREQ(uint32 Instance)
{
    USDHC_Type * Base = Usdhc_Ip_BaseAddr[Instance];

    /* Clear the stop request */
    Base->PROT_CTRL &= ~USDHC_PROT_CTRL_SABGREQ_MASK;
}


/**
* @brief         uSDHC_Ip_SetTiming
* @details       Configure USDHC register for timing condition
*
* @param[in]     Instance          USDHC hardware instance
* @param[in]     DdrEnable        enable/disable DDR mode
* @param[in]     EnHs400          enable/disable enhanced HS400 mode
* @param[in]     Hs400Mode        enable/disable HS400 mode
*
* @return        void
* @pre           The USDHC driver needs to be initialized 
*/
void uSDHC_Ip_SetTiming(uint32 Instance,
                        boolean DdrEnable,
                        boolean EnHs400,
                        boolean Hs400Mode
                       )
{
    USDHC_Type * Base = Usdhc_Ip_BaseAddr[Instance];
    uint32 MixCtrlReg = Base->MIX_CTRL;

    MixCtrlReg &= ~USDHC_MIX_CTRL_DDR_EN_MASK;
    if ((boolean)TRUE == DdrEnable)
    {
        MixCtrlReg |= USDHC_MIX_CTRL_DDR_EN_MASK;
    }

#if (STD_ON == FEATURE_USDHC_HAS_HIGHSPEED_TUNNING)
    MixCtrlReg &= ~USDHC_MIX_CTRL_EN_HS400_MODE_MASK;
    if ((boolean)TRUE == EnHs400)
    {
        MixCtrlReg |= USDHC_MIX_CTRL_EN_HS400_MODE_MASK;
    }

    MixCtrlReg &= ~USDHC_MIX_CTRL_HS400_MODE_MASK;
    if ((boolean)TRUE == Hs400Mode)
    {
        MixCtrlReg |= USDHC_MIX_CTRL_HS400_MODE_MASK;
    }
#else
    /* Unused variables */
    (void)EnHs400;
    (void)Hs400Mode;
#endif

    Base->MIX_CTRL = MixCtrlReg;
}

#if (STD_ON == FEATURE_USDHC_HAS_HIGHSPEED_TUNNING)
/**
* @brief         uSDHC_Ip_ConfigTuning
* @details       Configure registers for pre-tuning phase
*
* @param[in]     Instance          USDHC hardware instance
*
* @return        status
* @pre           The USDHC driver needs to be initialized 
*/
void uSDHC_Ip_ConfigTuning(uint32 Instance,
                           uint8 DelayValue
                          )
{
    USDHC_Type * Base          = Usdhc_Ip_BaseAddr[Instance];
    Usdhc_Ip_StatusType status = STATUS_USDHC_IP_SUCCESS;

    Base->TUNING_CTRL &= ~ USDHC_TUNING_CTRL_STD_TUNING_EN_MASK;
    status = uSDHC_Ip_Reset(Instance, (uint32)USDHC_SYS_CTRL_RSTA_MASK, (uint32)USDHC_IP_RESET_TIMEOUT);
    if (STATUS_USDHC_IP_SUCCESS == status)
    {
        Base->MIX_CTRL    |= (USDHC_MIX_CTRL_EXE_TUNE_MASK | USDHC_MIX_CTRL_SMP_CLK_SEL_MASK);
        Base->VEND_SPEC   |= USDHC_VEND_SPEC_FRC_SDCLK_ON_MASK;
        Base->CLK_TUNE_CTRL_STATUS &= ~USDHC_CLK_TUNE_CTRL_STATUS_DLY_CELL_SET_PRE_MASK;
        Base->CLK_TUNE_CTRL_STATUS |= USDHC_CLK_TUNE_CTRL_STATUS_DLY_CELL_SET_PRE(DelayValue);
    }
}

/**
* @brief         uSDHC_Ip_PreTuning
* @details       Configure registers for pre-tuning phase
*
* @param[in]     Instance          USDHC hardware instance
*
* @return        status
* @pre           The USDHC driver needs to be initialized 
*/
void uSDHC_Ip_PreTuning(uint32 Instance)
{
    USDHC_Type * Base = Usdhc_Ip_BaseAddr[Instance];

    /* Disable command interrupts for tuning transactions (only check for received tuning data) */
    Base->INT_STATUS_EN &= ~USDHC_COMMAND_INT;
    Base->INT_SIGNAL_EN &= ~USDHC_COMMAND_INT;
    Base->INT_STATUS_EN &= ~USDHC_INT_STATUS_DCE_MASK;
    Base->INT_SIGNAL_EN &= ~USDHC_INT_STATUS_DCE_MASK;
}

/**
* @brief         uSDHC_Ip_PostTuning
* @details       Configure registers for post-tuning phase
*
* @param[in]     Instance          USDHC hardware instance
*
* @return        status
* @pre           The USDHC driver needs to be initialized 
*/
void uSDHC_Ip_PostTuning(uint32 Instance)
{
    USDHC_Type * Base    = Usdhc_Ip_BaseAddr[Instance];

    Base->MIX_CTRL  &= ~USDHC_MIX_CTRL_EXE_TUNE_MASK;
    Base->VEND_SPEC &= ~USDHC_VEND_SPEC_FRC_SDCLK_ON_MASK;
    (void)uSDHC_Ip_Reset(Instance, (uint32)USDHC_SYS_CTRL_RSTA_MASK, (uint32)USDHC_IP_RESET_TIMEOUT);
    Base->MIX_CTRL |= USDHC_MIX_CTRL_SMP_CLK_SEL_MASK | USDHC_MIX_CTRL_AUTO_TUNE_EN_MASK;

    /* Re-enable command interrupts for normal transactions */
    Base->INT_STATUS_EN |= USDHC_COMMAND_INT;
    Base->INT_SIGNAL_EN |= USDHC_COMMAND_INT;
    Base->INT_STATUS_EN |= USDHC_INT_STATUS_DCE_MASK;
    Base->INT_SIGNAL_EN |= USDHC_INT_STATUS_DCE_MASK;
}

/**
* @brief         uSDHC_Ip_SetStrobeDll
* @details       Configure strobe Dll control for HS400 mode
*
* @param[in]     Instance          USDHC hardware instance
*
* @return        status
* @pre           The USDHC driver needs to be initialized 
*/
void uSDHC_Ip_SetStrobeDll(uint32 Instance)
{
    USDHC_Type * Base         = Usdhc_Ip_BaseAddr[Instance];
    uint32 u32StrobeDelay     = 0U;
    uint32 u32StrobeDllReg    = 0U;

    /* Disable clock before enabling strobe dll */
    Base->VEND_SPEC &= ~USDHC_VEND_SPEC_FRC_SDCLK_ON_MASK;

    /* Strobe dll control reset */
    Base->STROBE_DLL_CTRL |= USDHC_STROBE_DLL_CTRL_STROBE_DLL_CTRL_RESET_MASK;
    /* Clear the reset bit on strobe dll */
    Base->STROBE_DLL_CTRL &= ~USDHC_STROBE_DLL_CTRL_STROBE_DLL_CTRL_RESET_MASK;

    /* Enable Strobe dll control and adjust the delay target */
    u32StrobeDelay  = ESDHC_STROBE_DLL_CTRL_SLV_DLY_TARGET_DEFAULT;
    u32StrobeDllReg = USDHC_STROBE_DLL_CTRL_STROBE_DLL_CTRL_ENABLE(1U) | \
                      USDHC_STROBE_DLL_CTRL_STROBE_DLL_CTRL_SLV_UPDATE_INT(4U) | \
                      (u32StrobeDelay << USDHC_STROBE_DLL_CTRL_STROBE_DLL_CTRL_SLV_DLY_TARGET_SHIFT);

    Base->STROBE_DLL_CTRL = u32StrobeDllReg;
}

#endif /* (STD_ON == FEATURE_USDHC_HAS_HIGHSPEED_TUNNING) */

#define MEM_43_EEP_STOP_SEC_CODE
#include "Mem_43_Eep_MemMap.h"

#ifdef __cplusplus
}
#endif
/** @} */
