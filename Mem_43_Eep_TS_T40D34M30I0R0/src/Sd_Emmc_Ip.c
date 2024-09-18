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
*   @addtogroup Sd Ip
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
#include "Sd_Emmc_Ip.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define SD_EMMC_IP_VENDOR_ID_C                    43
#define SD_EMMC_IP_AR_RELEASE_MAJOR_VERSION_C     4
#define SD_EMMC_IP_AR_RELEASE_MINOR_VERSION_C     7
#define SD_EMMC_IP_AR_RELEASE_REVISION_VERSION_C  0
#define SD_EMMC_IP_SW_MAJOR_VERSION_C             3
#define SD_EMMC_IP_SW_MINOR_VERSION_C             0
#define SD_EMMC_IP_SW_PATCH_VERSION_C             0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if current file and Mcal header file are of the same Autosar version */
    #if ((SD_EMMC_IP_AR_RELEASE_MAJOR_VERSION_C != MCAL_AR_RELEASE_MAJOR_VERSION) || \
         (SD_EMMC_IP_AR_RELEASE_MINOR_VERSION_C != MCAL_AR_RELEASE_MINOR_VERSION) \
        )
        #error "AutoSar Version Numbers of Sd_Emmc_Ip.c and Mcal.h are different"
    #endif
#endif

/* Check if header file and Usdhc_Ip.h header file are of the same vendor */
#if (SD_EMMC_IP_VENDOR_ID_C != USDHC_IP_VENDOR_ID_H)
    #error "Sd_Emmc_Ip.c and Usdhc_Ip.h have different vendor ids"
#endif
/* Check if header file and Usdhc_Ip.h header file are of the same Autosar version */
#if ((SD_EMMC_IP_AR_RELEASE_MAJOR_VERSION_C    != USDHC_IP_AR_RELEASE_MAJOR_VERSION_H) || \
     (SD_EMMC_IP_AR_RELEASE_MINOR_VERSION_C    != USDHC_IP_AR_RELEASE_MINOR_VERSION_H) || \
     (SD_EMMC_IP_AR_RELEASE_REVISION_VERSION_C != USDHC_IP_AR_RELEASE_REVISION_VERSION_H) \
    )
    #error "AutoSar Version Numbers of Sd_Emmc_Ip.c and Usdhc_Ip.h are different"
#endif
/* Check if header file and Usdhc_Ip.h header file are of the same software version */
#if ((SD_EMMC_IP_SW_MAJOR_VERSION_C != USDHC_IP_SW_MAJOR_VERSION_H) || \
     (SD_EMMC_IP_SW_MINOR_VERSION_C != USDHC_IP_SW_MINOR_VERSION_H) || \
     (SD_EMMC_IP_SW_PATCH_VERSION_C != USDHC_IP_SW_PATCH_VERSION_H) \
    )
    #error "Software Version Numbers of Sd_Emmc_Ip.c and Usdhc_Ip.h are different"
#endif

/* Check if header file and Sd_Emmc_Ip.h header file are of the same vendor */
#if (SD_EMMC_IP_VENDOR_ID_C != SD_EMMC_IP_VENDOR_ID)
    #error "Sd_Emmc_Ip.c and Sd_Emmc_Ip.h have different vendor ids"
#endif
/* Check if header file and Sd_Emmc_Ip.h header file are of the same Autosar version */
#if ((SD_EMMC_IP_AR_RELEASE_MAJOR_VERSION_C    != SD_EMMC_IP_AR_RELEASE_MAJOR_VERSION) || \
     (SD_EMMC_IP_AR_RELEASE_MINOR_VERSION_C    != SD_EMMC_IP_AR_RELEASE_MINOR_VERSION) || \
     (SD_EMMC_IP_AR_RELEASE_REVISION_VERSION_C != SD_EMMC_IP_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Sd_Emmc_Ip.c and Sd_Emmc_Ip.h are different"
#endif
/* Check if header file and Sd_Emmc_Ip.h header file are of the same software version */
#if ((SD_EMMC_IP_SW_MAJOR_VERSION_C != SD_EMMC_IP_SW_MAJOR_VERSION) || \
     (SD_EMMC_IP_SW_MINOR_VERSION_C != SD_EMMC_IP_SW_MINOR_VERSION) || \
     (SD_EMMC_IP_SW_PATCH_VERSION_C != SD_EMMC_IP_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Sd_Emmc_Ip.c and Sd_Emmc_Ip.h are different"
#endif

/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/

/*==================================================================================================
*                                      LOCAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      LOCAL VARIABLES
==================================================================================================*/

#define MEM_43_EEP_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "Mem_43_Eep_MemMap.h"

/*!< SDHC capability information */
static Usdhc_Ip_ControllerCapabilityType Sd_Emmc_Ip_Capability[SD_IP_INSTANCE_NO];

static Usdhc_Ip_TransferStorageType Sd_Emmc_Ip_TransferStorage;

/*!< EMMC card capability information  */
static Sd_Ip_MmcCapabilityType mmcCapability;

/* MMC Extended CID Register */
static Sd_Ip_MmcCidType Sd_Emmc_Ip_MmcCid;

/* MMC Extended CSD Register */
static Sd_Ip_MmcCsdType Sd_Emmc_Ip_MmcCsd;

/* MMC Current Partition Access state */
static Sd_Ip_MmcPartitionAccessType mmcPartitionState;

/* MMC Extended CSR Register */
static Sd_Ip_MmcECsrType Sd_Emmc_Ip_MmcECsr ;

/* Sd CID Register. Uniquely identifies the card. */
static Sd_Ip_CidType Sd_Emmc_Ip_Cid;

/* Sd CSD Register. Information about card operation conditions */
static Sd_Ip_CsdType Sd_Emmc_Ip_Csd;

/* Sd SCR Register. Information about card's special features. */
static Sd_Ip_ScrType Sd_Emmc_Ip_Scr;
/* State of Erase or Write for aync/syn modes */
static Sd_Emmc_Ip_StatusType Sd_Emmc_Ip_eJobState;

#define MEM_43_EEP_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "Mem_43_Eep_MemMap.h"

#define MEM_43_EEP_START_SEC_VAR_INIT_BOOLEAN
#include "Mem_43_Eep_MemMap.h"
/* Setup variables in one function which only call one time in that function*/
static boolean Sd_Emmc_Ip_bFirstTimeTransfer = TRUE;
#define MEM_43_EEP_STOP_SEC_VAR_INIT_BOOLEAN
#include "Mem_43_Eep_MemMap.h"

#define MEM_43_EEP_START_SEC_VAR_CLEARED_32
#include "Mem_43_Eep_MemMap.h"
/* Store number of block counts */
static uint32 Sd_Emmc_Ip_u32TempblockCount;
/* The block count has been wrote. */
static uint32 Sd_Emmc_Ip_u32BlockDone;
/* The block count can be wrote in one time sending WRITE_BLOCKS Sd_Emmc_Ip_TransferStorage.command. */
static uint32 Sd_Emmc_Ip_u32BlockCountOneTransfer;
/* Relative address of the card. Used in host-card communication */
static uint32 Sd_Emmc_Ip_u32RelativeAddress;
static uint32 Sd_Emmc_Ip_u32AppCmd41Argument;
/* Store block count of card */
static uint32 Sd_Emmc_Ip_u32BlockCountInfo;
/* Store block size of card */
static uint32 Sd_Emmc_Ip_u32BlockSizeInfo;
/* SD bus clock frequency united in Hz */
static uint32 Sd_Emmc_Ip_u32BusClockInfo;
/* Card version - SPEC_VERS in the CSD */
static uint32 Sd_Emmc_Ip_u32VersionInfo;
/* Flags in Sd_Ip_CardFlagType */
static uint32 Sd_Emmc_Ip_u32CardFlags;
/* Card type */
static Sd_Ip_ProtocolType Sd_Emmc_Ip_eCardTypeInfo;

#if (STD_ON == FEATURE_USDHC_HAS_HIGHSPEED_TUNNING)
/* Tuning pattern */
static const uint32 u32TuningPattern4bit[MMC_TUNING_4BIT_PATTERN_WORDS] = {
    0xFF0FFF00U, 0xFFCCC3CCU,
    0xC33CCCFFU, 0xFEFFFEEFU,
    0xFFDFFFDDU, 0xFFFBFFFBU,
    0xBFFF7FFFU, 0x77F7BDEFU,
    0xFFF0FFF0U, 0x0FFCCC3CU,
    0xCC33CCCFU, 0xFFEFFFEEU,
    0xFFFDFFFDU, 0xDFFFBFFFU,
    0xBBFFF7FFU, 0xF77F7BDEU
};

static const uint32 u32TuningPattern8bit[MMC_TUNING_8BIT_PATTERN_WORDS] = {
    0xFFFF00FFU, 0xFFFF0000U,
    0xFFFFCCCCU, 0xCC33CCCCU,
    0xCC3333CCU, 0xCCCCFFFFU,
    0xFFEEFFFFU, 0xFFEEEEFFU,
    0xFFFFDDFFU, 0xFFFFDDDDU,
    0xFFFFFFBBU, 0xFFFFFFBBU,
    0xBBFFFFFFU, 0x77FFFFFFU,
    0x7777FF77U, 0xBBDDEEFFU,
    0xFFFFFF00U, 0xFFFFFF00U,
    0x00FFFFCCU, 0xCCCC33CCU,
    0xCCCC3333U, 0xCCCCCCFFU,
    0xFFFFEEFFU, 0xFFFFEEEEU,
    0xFFFFFFDDU, 0xFFFFFFDDU,
    0xDDFFFFFFU, 0xBBFFFFFFU,
    0xBBBBFFFFU, 0xFF77FFFFU,
    0xFF7777FFU, 0x77BBDDEEU
};
#endif

#define MEM_43_EEP_STOP_SEC_VAR_CLEARED_32
#include "Mem_43_Eep_MemMap.h"

#define MEM_43_EEP_START_SEC_VAR_CLEARED_32_NO_CACHEABLE
#include "Mem_43_Eep_MemMap.h"

#if (STD_ON == FEATURE_USDHC_HAS_HIGHSPEED_TUNNING)
/* Buffer to store read data from tuning process */
VAR_ALIGN(static uint32 Sd_Emmc_Ip_u32TuningDestBuffer[MMC_TUNING_8BIT_PATTERN_WORDS], USDHC_ALIGNMENT_SIZE)
#endif

/* Buffer to store Csd register value read from the card */
VAR_ALIGN(static uint32 Sd_Emmc_Ip_u32CsdBuffer[128U], USDHC_ALIGNMENT_SIZE)
/* Buffer to store Scr register value read from the card */
VAR_ALIGN(static uint32 Sd_Emmc_Ip_u32RegScr[2U], USDHC_ALIGNMENT_SIZE)
/* Store function Status */
VAR_ALIGN(static uint32 Sd_Emmc_Ip_u32FunctionStatus[16U], USDHC_ALIGNMENT_SIZE)

#define MEM_43_EEP_STOP_SEC_VAR_CLEARED_32_NO_CACHEABLE
#include "Mem_43_Eep_MemMap.h"

/*==================================================================================================
*                                      GLOBAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      GLOBAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/

#define MEM_43_EEP_START_SEC_CODE
#include "Mem_43_Eep_MemMap.h"

static void Sd_Emmc_InitAllVarriable(void);

static inline Sd_Emmc_Ip_StatusType Sd_Ip_SelectCard(const Sd_Emmc_Ip_ConfigType *Config, boolean IsSelected);

static inline Sd_Emmc_Ip_StatusType Sd_Ip_WaitWriteComplete(const Sd_Emmc_Ip_ConfigType *Config);

static inline Sd_Emmc_Ip_StatusType Sd_Ip_SendApplicationCmd(const Sd_Emmc_Ip_ConfigType *Config);

static inline Sd_Emmc_Ip_StatusType Sd_Ip_GoIdle(const Sd_Emmc_Ip_ConfigType *Config);

static Sd_Emmc_Ip_StatusType Sd_Ip_MmcDecodeExtCsd(const uint32 *RegExtCsd);

static Sd_Emmc_Ip_StatusType Sd_Ip_MmcSendExtCsd(const Sd_Emmc_Ip_ConfigType *Config);

#if (STD_ON == FEATURE_USDHC_HAS_HIGHSPEED_TUNNING)
static Sd_Emmc_Ip_StatusType Sd_Ip_MmcSendTuning(const Sd_Emmc_Ip_ConfigType *Config, uint32 BlockSize);

static Sd_Emmc_Ip_StatusType Sd_Ip_MmcExecuteTuning(const Sd_Emmc_Ip_ConfigType *Config, uint32 BlockSize);

static Sd_Emmc_Ip_StatusType Sd_Ip_VerifyTuningPattern4bit(const Sd_Emmc_Ip_ConfigType *Config);

static Sd_Emmc_Ip_StatusType Sd_Ip_VerifyTuningPattern8bit(const Sd_Emmc_Ip_ConfigType *Config);
#endif

static Sd_Emmc_Ip_StatusType Sd_Ip_MmcSwitch(const Sd_Emmc_Ip_ConfigType *Config, uint32 Access, uint8 Index, uint32 Value);

static inline Sd_Emmc_Ip_StatusType Sd_Ip_SetBlockSize(const Sd_Emmc_Ip_ConfigType *Config, uint32 BlockSize);

static Sd_Emmc_Ip_StatusType Sd_Ip_HandleSetBlockCountSize(const Sd_Emmc_Ip_ConfigType *Config, uint32 BlockCount, uint32 BlockSize);

static inline Sd_Emmc_Ip_StatusType Sd_Ip_SetBlockCount(const Sd_Emmc_Ip_ConfigType *Config, uint32 BlockCount);

static Sd_Emmc_Ip_StatusType Sd_Ip_SendRca(const Sd_Emmc_Ip_ConfigType *Config);

static Sd_Emmc_Ip_StatusType Sd_Ip_SwitchFunction(const Sd_Emmc_Ip_ConfigType *Config,
                                                  Sd_Ip_SwitchModeType Mode,
                                                  Sd_Ip_GroupNumType Group,
                                                  uint32 Number,
                                                  uint32 *Status
                                                 );

#if (USDHC_IP_V180_SUPPORT == STD_ON)
static inline Sd_Emmc_Ip_StatusType Sd_Ip_SwitchVoltage(const Sd_Emmc_Ip_ConfigType *Config);
#endif

static void Sd_Ip_DecodeScr(const Sd_Emmc_Ip_ConfigType *Config, const uint32 *RegScr);

static Sd_Emmc_Ip_StatusType Sd_Ip_SendScr(const Sd_Emmc_Ip_ConfigType *Config);

static Sd_Emmc_Ip_StatusType Sd_Ip_CheckAndSwitchFunction(const Sd_Emmc_Ip_ConfigType *Config,
                                                          Sd_Ip_GroupNumType Group,
                                                          uint32 Function
                                                         );

static Sd_Emmc_Ip_StatusType Sd_Ip_SetDataBusWidth(const Sd_Emmc_Ip_ConfigType *Config, Sd_Ip_DataBusWidthType Width);

static void Sd_Ip_SetCsdFlag(const uint32 *RegCsd);

static Sd_Emmc_Ip_StatusType Sd_Ip_DecodeCsd(const uint32 *RegCsd);

static Sd_Emmc_Ip_StatusType Sd_Ip_MmcDecodeCsd(const uint32 *RegCsd);

static Sd_Emmc_Ip_StatusType Sd_Ip_SendCsd(const Sd_Emmc_Ip_ConfigType *Config);

static void Sd_Ip_MmcGetCapabilities(void);

static uint8 Sd_Ip_GetValueFromRange(const uint32 *Array, uint8 Start, uint8 Len);

static void Sd_Ip_MmcDecodeCid(const uint32 *RegCid);

static void Sd_Ip_DecodeCid(const uint32 *RegCid);

static Sd_Emmc_Ip_StatusType Sd_Ip_AllSendCid(const Sd_Emmc_Ip_ConfigType *Config);

static Sd_Emmc_Ip_StatusType Sd_Ip_ApplicationSendOperationCondition(const Sd_Emmc_Ip_ConfigType *Config,
                                                                     uint32 Argument
                                                                    );

static Sd_Emmc_Ip_StatusType Sd_Ip_SendInterfaceCondition(const Sd_Emmc_Ip_ConfigType *Config);

static Sd_Emmc_Ip_StatusType Sd_Ip_Read(const Sd_Emmc_Ip_ConfigType *Config,
                                        uint8 *Buffer,
                                        uint32 StartBlock,
                                        uint32 BlockSize,
                                        uint32 BlockCount
                                       );

static Sd_Emmc_Ip_StatusType Sd_Ip_Write(const Sd_Emmc_Ip_ConfigType *Config,
                                         const uint8 *Buffer,
                                         uint32 StartBlock,
                                         uint32 BlockCount,
                                         boolean AsyncEnable
                                        );

static Sd_Emmc_Ip_StatusType Sd_Ip_Erase(const Sd_Emmc_Ip_ConfigType *Config, uint32 StartBlock, uint32 BlockCount, boolean AsyncEnable);

static Sd_Emmc_Ip_StatusType Sd_Ip_SwitchToDataTransfer(const Sd_Emmc_Ip_ConfigType *Config);

#if (STD_ON == FEATURE_USDHC_HAS_HIGHSPEED_TUNNING)
static Sd_Emmc_Ip_StatusType Sd_Ip_SwitchToHS200(const Sd_Emmc_Ip_ConfigType *Config, uint32 BusWidth);

static Sd_Emmc_Ip_StatusType Sd_Ip_SwitchToHS400(const Sd_Emmc_Ip_ConfigType *Config);
#endif

static Sd_Emmc_Ip_StatusType Sd_Ip_IncreaseMmcBusSpeed(const Sd_Emmc_Ip_ConfigType *Config);

static void Sd_Ip_SetCmd41Argument(const Sd_Emmc_Ip_ConfigType *Config);

static Sd_Emmc_Ip_StatusType Sd_Ip_SdSwitchSpeed(const Sd_Emmc_Ip_ConfigType *Config);

static Sd_Emmc_Ip_StatusType Sd_Ip_MmcSwitchSpeed(const Sd_Emmc_Ip_ConfigType *Config);

static Sd_Emmc_Ip_StatusType Sd_Ip_SendEraseBlockStart(const Sd_Emmc_Ip_ConfigType *Config, uint32 EraseBlockStart);

static Sd_Emmc_Ip_StatusType Sd_Ip_SendEraseBlockEnd(const Sd_Emmc_Ip_ConfigType *Config, uint32 EraseBlockEnd);

static uint32 Sd_Ip_LoadHword(const volatile uint32 *DstAddr, uint32 Offset);

static uint32 Sd_Ip_LoadDword(const volatile uint32 *DstAddr, uint32 Offset);

static void Sd_Ip_SwapDword(volatile uint32 *DstAddr, uint32 Offset, volatile uint32 SrcData);

static uint32 Sd_Ip_SwapHword(const volatile uint32 *DstAddr, uint32 Offset);

static void Sd_Emmc_Ip_WriteBlocksBlocking(const Sd_Emmc_Ip_ConfigType *Config, const uint8 *Buffer, uint32 StartBlock);
static void Sd_Emmc_Ip_WriteBlocksNonBlocking(const Sd_Emmc_Ip_ConfigType *Config, const uint8 *Buffer, uint32 StartBlock);

static void Sd_Emmc_Ip_EraseBlocksBlocking(const Sd_Emmc_Ip_ConfigType *Config, uint32 StartBlock);
static void Sd_Emmc_Ip_EraseBlocksNonBlocking(const Sd_Emmc_Ip_ConfigType *Config, uint32 StartBlock);

static void Sd_Emmc_Ip_CalcBlockCountOneTransfer(const Sd_Emmc_Ip_ConfigType *Config);

static void Sd_Ip_WritePreCheck(const Sd_Emmc_Ip_ConfigType *Config,
                                uint32 BlockCount,
                                uint32 BlockSize
                               );

static void Sd_Ip_ErasePreCheck(const Sd_Emmc_Ip_ConfigType *Config,
                                uint32 StartBlock,
                                uint32 BlockCount
                               );

static inline void Sd_Ip_SetCsd0Flag(const uint32 *RegCsd);

static inline boolean Sd_Ip_CardTypeSDSC(void);

static void Sd_Emmc_Ip_InitPreCheck(const Sd_Emmc_Ip_ConfigType *Config);
static Sd_Emmc_Ip_StatusType Sd_Emmc_Ip_EnterIdentificationMode(const Sd_Emmc_Ip_ConfigType *Config);
static Sd_Emmc_Ip_StatusType Sd_Emmc_Ip_EnterDataTransferMode(const Sd_Emmc_Ip_ConfigType *Config);

static Sd_Emmc_Ip_StatusType Sd_Ip_IncreaseMmcBusSpeed4Bit(const Sd_Emmc_Ip_ConfigType *Config);
static Sd_Emmc_Ip_StatusType Sd_Ip_IncreaseMmcBusSpeed8Bit(const Sd_Emmc_Ip_ConfigType *Config);
static Sd_Emmc_Ip_StatusType Sd_Ip_IncreaseMmcBusSpeed4BitDDR(const Sd_Emmc_Ip_ConfigType *Config);
static Sd_Emmc_Ip_StatusType Sd_Ip_IncreaseMmcBusSpeed8BitDDR(const Sd_Emmc_Ip_ConfigType *Config);

#if (STD_ON == FEATURE_USDHC_HAS_HIGHSPEED_TUNNING)
static Sd_Emmc_Ip_StatusType Sd_Ip_MmcSwitchHighSpeedHS400(const Sd_Emmc_Ip_ConfigType *Sd_Ip_pConfig);
static Sd_Emmc_Ip_StatusType Sd_Ip_MmcSwitchHighSpeedHS200(const Sd_Emmc_Ip_ConfigType *Sd_Ip_pConfig);
#endif

static Sd_Emmc_Ip_StatusType Sd_Ip_MmcSwitchHighSpeedDDR52(const Sd_Emmc_Ip_ConfigType *Sd_Ip_pConfig);
static Sd_Emmc_Ip_StatusType Sd_Ip_MmcSwitchHighSpeedSDR52(const Sd_Emmc_Ip_ConfigType *Sd_Ip_pConfig);

static inline Sd_Emmc_Ip_StatusType Sd_Ip_AnalyzeOperationConditionSD(uint32 OCRValue);
static inline void Sd_Ip_AnalyzeOperationConditionMMC(uint32 OCRValue);

static inline Sd_Emmc_Ip_StatusType Sd_Ip_SwitchFunctionSupported(void);

static inline Sd_Emmc_Ip_StatusType Sd_Ip_SwitchFunctionCheck(uint32 SupportBis,
                                                              uint32 FunctionGroupStatus,
                                                              Sd_Ip_GroupNumType Group,
                                                              uint32 Function
                                                             );

static inline Sd_Emmc_Ip_StatusType Sd_Ip_SwitchFunctionSet(uint32 FunctionGroupStatus,
                                                            Sd_Ip_GroupNumType Group,
                                                            uint32 Function
                                                           );

static Sd_Emmc_Ip_StatusType Sd_Ip_IncreaseBusSpeed4Bit(const Sd_Emmc_Ip_ConfigType *Config);

static uint32 Sd_Ip_GetCardStatus(const Sd_Emmc_Ip_ConfigType *Config);

#if (STD_ON == SD_IP_MMC_CONFIG_BOOT_ENABLED)
static Sd_Emmc_Ip_StatusType Sd_Emmc_Ip_MmcConfigBootMode(const Sd_Emmc_Ip_ConfigType *Sd_Ip_pConfig);
#endif

/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/
/**
* @brief         Sd_Ip_AnalyzeOperationConditionSD
* @details       Analyze operation condition for SD card
*/
static inline Sd_Emmc_Ip_StatusType Sd_Ip_AnalyzeOperationConditionSD(uint32 OCRValue)
{
    Sd_Emmc_Ip_StatusType Status;

    /* Check card busy state */
    if (0U != (OCRValue & (uint32)aSD_OcrPowerUpBusyFlag))
    {
        Status = (Sd_Emmc_Ip_StatusType)SD_IP_STATUS_SUCCESS;

        /* Card supports high capacity */
        if (0U != (OCRValue & (uint32)aSD_OcrCardCapacitySupportFlag))
        {
            Sd_Emmc_Ip_u32CardFlags |= (uint32)SD_IP_SUPPORT_HIGH_CAPACITY_FLAG;
        }

        /* 1.8V support */
        if (0U != (OCRValue & (uint32)aSD_OcrSwitch18AcceptFlag))
        {
            Sd_Emmc_Ip_u32CardFlags |= (uint32)SD_IP_SUPPORT_VOLTAGE_180V;
        }
    }
    else
    {
        /* Card is still busy (bit 31 is not set yet) */
        Status = (Sd_Emmc_Ip_StatusType)SD_IP_STATUS_TIMEOUT;
    }

    return Status;
}

/**
* @brief         Sd_Ip_AnalyzeOperationConditionMMC
* @details       Analyze operation condition for MMC card
*/
static inline void Sd_Ip_AnalyzeOperationConditionMMC(uint32 OCRValue)
{
    if (0x2U == ((OCRValue & MMC_OCR_ACCESS_MODE_MASK) >> MMC_OCR_ACCESS_MODE_SHIFT))
    {
        /* Card supports high capacity */
        Sd_Emmc_Ip_u32CardFlags |= (uint32)SD_IP_SUPPORT_HIGH_CAPACITY_FLAG;
    }
}

/**
* @brief         Sd_Ip_CardTypeSDSC
* @details       Check if card type is SDSC or not
*
* @return        void
* @pre           The USDHC driver needs to be initialized.
*/
static inline boolean Sd_Ip_CardTypeSDSC(void)
{
    /* Check if card type is SDSC or not */
    return ( (SD_IP_MEMORY_CARD_SD == Sd_Emmc_Ip_eCardTypeInfo) && (0U == (Sd_Emmc_Ip_u32CardFlags & (uint32)SD_IP_SUPPORT_HIGH_CAPACITY_FLAG)) );
}

/**
* @brief         Sd_Emmc_InitAllVarriable
* @details       Initialize global variables to their default values
*
* @param[in]     void
*
* @return        void
* @pre           N/A
*/
static void Sd_Emmc_InitAllVarriable(void)
{
    /* Initialize global variable */
    Sd_Emmc_Ip_u32AppCmd41Argument = 0U;
    Sd_Emmc_Ip_eJobState           = (Sd_Emmc_Ip_StatusType)SD_IP_STATUS_SUCCESS;
}

/**
* @brief         Sd_Ip_LoadHword
* @details       Return reversed uint32 data
*
* @param[in]     DstAddr Destination address
* @param[in]     Offset  Register field address Offset
*
* @return        Laddr   Reversed data with half word
* @pre           The USDHC driver needs to be initialized.
*/
static uint32 Sd_Ip_LoadHword(const volatile uint32 *DstAddr, uint32 Offset)
{
    uint32 *Laddr = (uint32 *)((uint32)(DstAddr) + Offset);

    /* Reversed data with half word endian */
    *Laddr = ((((uint32)(*Laddr) & 0xFFU) << 8U) | (((uint32)(*Laddr) & 0xFF00U) >> 8U) | (((uint32)(*Laddr) & 0xFF000000U) >> 8U) | (((uint32)(*Laddr) & 0x00FF0000U) << 8U));
    
    return *Laddr;
}

/**
* @brief         Sd_Ip_SwapHword
* @details       Reverse half word sequence in uint32
*
* @param[in]     DstAddr Destination address
* @param[in]     Offset  Register field address Offset
*
* @return        Laddr   Reversed data with half word
* @pre           The USDHC driver needs to be initialized.
*/
static uint32 Sd_Ip_SwapHword(const volatile uint32 *DstAddr, uint32 Offset)
{
    uint32 *Laddr = (uint32 *)((uint32)(DstAddr) + Offset);

    /* Reversed data with half word endian */
    *Laddr = ((((uint32)(*Laddr) & 0x0000FFFFU) << 16U) | (((uint32)(*Laddr) & 0xFFFF0000U) >> 16U));
    
    return *Laddr;
}
/**
* @brief         Sd_Ip_LoadDword
* @details       Return reversed uint32 data
*
* @param[in]     DstAddr Destination address
* @param[in]     Offset  Register field address Offset
*
* @return        Rvdw    Reversed data
* @pre           The USDHC driver needs to be initialized.
*/
static uint32 Sd_Ip_LoadDword(const volatile uint32 *DstAddr, uint32 Offset)
{
    /*! @brief Returned data for Sd_Ip_SwapDword function */
    static uint32 Rvdw;

    const uint32 *Laddr = (uint32 *)((uint32)(DstAddr) + Offset);
    Rvdw = *Laddr;
    Sd_Ip_SwapDword(&Rvdw, 0U, Rvdw);

    return Rvdw;
}

/**
* @brief         Sd_Ip_SwapDword
* @details       Reverse byte sequence in uint32
*
* @param[in]     DstAddr Destination address
* @param[in]     Offset  Register field address Offset
* @param[in]     SrcData Data to be swapped
*
* @return        void    
* @pre           The USDHC driver needs to be initialized.
*/
static void Sd_Ip_SwapDword(volatile uint32 *DstAddr, uint32 Offset, volatile uint32 SrcData)
{
    uint32 *Laddr  = (uint32 *)((uint32)(DstAddr) + Offset);
    uint32 Rv      = SrcData;
    uint32 Swapped = ((Rv >> 24U) & 0xFFU) | ((Rv << 8U) & 0xFF0000U) | ((Rv >> 8U) & 0xFF00U) | ((Rv << 24U) & 0xFF000000U);
    *Laddr = Swapped;
}

/**
* @brief         Sd_Ip_SelectCard
* @details       Send SELECT_CARD command to set the card to be transfer state or not.
*
* @param[in]     Config Card descriptor.
* @param[in]     IsSelected True to set the card into transfer state.
*
* @return        Status    
* @pre           The USDHC driver needs to be initialized.
*/
static inline Sd_Emmc_Ip_StatusType Sd_Ip_SelectCard(const Sd_Emmc_Ip_ConfigType *Config, boolean IsSelected)
{
    Sd_Emmc_Ip_StatusType Status = (Sd_Emmc_Ip_StatusType)SD_IP_STATUS_SUCCESS;
    /* Prepare the command description */
    Sd_Emmc_Ip_TransferStorage.command.index = (uint32)aSDMMC_SelectCard;
    /* Card is selected to set into transfer state */
    if (IsSelected)
    {
        Sd_Emmc_Ip_TransferStorage.command.argument = (uint32)(Sd_Emmc_Ip_u32RelativeAddress) << 16U;
        Sd_Emmc_Ip_TransferStorage.command.responseType = USDHC_RESPONSE_TYPE_R1;
    }
    else
    {
        Sd_Emmc_Ip_TransferStorage.command.argument = 0U;
        Sd_Emmc_Ip_TransferStorage.command.responseType = USDHC_RESPONSE_TYPE_NONE;
    }

    Sd_Emmc_Ip_TransferStorage.content.command = &Sd_Emmc_Ip_TransferStorage.command;
    Sd_Emmc_Ip_TransferStorage.content.data = NULL_PTR;
    /* Start transfer */
    if ((STATUS_USDHC_IP_SUCCESS != uSDHC_Ip_Transfer(Config->usdhcConfig->instance, &Sd_Emmc_Ip_TransferStorage.content, (boolean)FALSE))|| (0U != ((Sd_Emmc_Ip_TransferStorage.command.response[0U]) & (uint32)SD_IP_R1_ALL_ERROR_FLAGS)))
    {
        /* The errors occurred */
        Status = (Sd_Emmc_Ip_StatusType)SD_IP_STATUS_TRANSFER_FAILED;
    }

    /* Wait until card to transfer state */
    return Status;

}

/**
* @brief         Sd_Ip_WaitWriteComplete
* @details       Wait write process complete.
*
* @param[in]     Config Card descriptor.
*
* @return        Status    
* @pre           The USDHC driver needs to be initialized.
*/
static inline Sd_Emmc_Ip_StatusType Sd_Ip_WaitWriteComplete(const Sd_Emmc_Ip_ConfigType *Config)
{
    Sd_Emmc_Ip_StatusType Status    = (Sd_Emmc_Ip_StatusType)SD_IP_STATUS_SUCCESS;
    Usdhc_Ip_StatusType ControllerStatus;
    boolean NeedLoop                = TRUE;
    uint32 SendOperationCondRetries = SD_IP_SEND_STATUS_RETRIES_NO;

    /* Set the command index */
    Sd_Emmc_Ip_TransferStorage.command.index = (uint32)aSDMMC_SendStatus;
    /* Set the argument */
    Sd_Emmc_Ip_TransferStorage.command.argument = (uint32)(Sd_Emmc_Ip_u32RelativeAddress) << 16U;
    /* Set the response type */
    Sd_Emmc_Ip_TransferStorage.command.responseType = USDHC_RESPONSE_TYPE_R1;
    Sd_Emmc_Ip_TransferStorage.command.type         = USDHC_COMMAND_TYPE_NORMAL;

    do
    {
        SendOperationCondRetries--;
        Sd_Emmc_Ip_TransferStorage.content.command = &Sd_Emmc_Ip_TransferStorage.command;
        Sd_Emmc_Ip_TransferStorage.content.data = NULL_PTR;
        /* Start transfer */
        ControllerStatus = uSDHC_Ip_Transfer(Config->usdhcConfig->instance, &Sd_Emmc_Ip_TransferStorage.content, (boolean)FALSE);
        /* Check transfer result */
        if ( (STATUS_USDHC_IP_SUCCESS != ControllerStatus) ||
             (0U != ((Sd_Emmc_Ip_TransferStorage.command.response[0U]) & (uint32)SD_IP_R1_ALL_ERROR_FLAGS))
           )
        {
            /* Transfer failed */
            Status = (Sd_Emmc_Ip_StatusType)SD_IP_STATUS_TRANSFER_FAILED;
            NeedLoop = (boolean)FALSE;
        }
        else
        {
            /* Check the response */
            if ((0U != ((Sd_Emmc_Ip_TransferStorage.command.response[0U] & (uint32)SD_IP_R1_READY_FOR_DATA_FLAG))) &&
                    (SD_IP_R1_CURRENT_STATE(Sd_Emmc_Ip_TransferStorage.command.response[0U]) != (uint32)aSDMMC_R1StateProgram))
            {
                NeedLoop = (boolean)FALSE;
            }
        }
    } while ((TRUE == NeedLoop) && (SendOperationCondRetries > 0U));

    return Status;

}

/**
* @brief         Sd_Ip_SendApplicationCmd
* @details       Send SEND_APPLICATION_COMMAND command.
*
* @param[in]     Config Card descriptor.
*
* @return        Status    
* @pre           The USDHC driver needs to be initialized.
*/
static inline Sd_Emmc_Ip_StatusType Sd_Ip_SendApplicationCmd(const Sd_Emmc_Ip_ConfigType *Config)
{
    Sd_Emmc_Ip_StatusType Status = (Sd_Emmc_Ip_StatusType)SD_IP_STATUS_SUCCESS;

    /* Prepare the command description */
    Sd_Emmc_Ip_TransferStorage.command.index = (uint32)aSDMMC_ApplicationCommand;
    Sd_Emmc_Ip_TransferStorage.command.argument = ((uint32)(Sd_Emmc_Ip_u32RelativeAddress) << 16U);
    Sd_Emmc_Ip_TransferStorage.command.type = USDHC_COMMAND_TYPE_NORMAL;
    Sd_Emmc_Ip_TransferStorage.command.responseType = USDHC_RESPONSE_TYPE_R1;

    Sd_Emmc_Ip_TransferStorage.content.command = &Sd_Emmc_Ip_TransferStorage.command;
    Sd_Emmc_Ip_TransferStorage.content.data = NULL_PTR;
    /* Start transfer */
    if ((STATUS_USDHC_IP_SUCCESS != uSDHC_Ip_Transfer(Config->usdhcConfig->instance, &Sd_Emmc_Ip_TransferStorage.content, (boolean)FALSE)) || (0U != ((Sd_Emmc_Ip_TransferStorage.command.response[0U]) & (uint32)SD_IP_R1_ALL_ERROR_FLAGS)))

    {
        /* The errors occurred */
        Status = (Sd_Emmc_Ip_StatusType)SD_IP_STATUS_TRANSFER_FAILED;
    }
    else
    {
        /* Check the response */
        if (0U == (Sd_Emmc_Ip_TransferStorage.command.response[0U] & (uint32)SD_IP_R1_APPLICATIONC_COMMAND_FLAG))
        {
            /* Card does not support application command */
            Status = (Sd_Emmc_Ip_StatusType)SD_IP_STATUS_CARD_NOT_SUPPORTED;
        }
    }

    return Status;
}

#if (USDHC_IP_V180_SUPPORT == STD_ON)
/**
* @brief         Sd_Ip_SwitchVoltage
* @details       Wrapper on uSDHC_SwitchVoltage routine.
*
* @param[in]     Config Card descriptor.
*
* @return        Status    
* @pre           The USDHC driver needs to be initialized.
*/
static inline Sd_Emmc_Ip_StatusType Sd_Ip_SwitchVoltage(const Sd_Emmc_Ip_ConfigType *Config)
{
    Sd_Emmc_Ip_StatusType Status = (Sd_Emmc_Ip_StatusType)SD_IP_STATUS_SUCCESS;

    if ( (0U != (Sd_Emmc_Ip_u32CardFlags & (uint32)SD_IP_SUPPORT_SDHC_FLAG)) &&
         (0U != (Sd_Emmc_Ip_u32CardFlags & (uint32)SD_IP_SUPPORT_VOLTAGE_180V))
       )
    {
        Sd_Emmc_Ip_TransferStorage.command.index        = (uint32)aSD_VoltageSwitch;
        Sd_Emmc_Ip_TransferStorage.command.argument     = 0U;
        Sd_Emmc_Ip_TransferStorage.command.type         = USDHC_COMMAND_TYPE_NORMAL;
        Sd_Emmc_Ip_TransferStorage.command.responseType = USDHC_RESPONSE_TYPE_R1;

        Sd_Emmc_Ip_TransferStorage.content.command      = &Sd_Emmc_Ip_TransferStorage.command;
        Sd_Emmc_Ip_TransferStorage.content.data         = NULL_PTR;

        if ( (STATUS_USDHC_IP_SUCCESS != uSDHC_Ip_Transfer(Config->usdhcConfig->instance, &Sd_Emmc_Ip_TransferStorage.content, (boolean)FALSE)) ||
             (0U != ((Sd_Emmc_Ip_TransferStorage.command.response[0U]) & (uint32)SD_IP_R1_ALL_ERROR_FLAGS))
            )
        {
            Status = (Sd_Emmc_Ip_StatusType)SD_IP_STATUS_TRANSFER_FAILED;
        }
        else
        {
            if (STATUS_USDHC_IP_SUCCESS != uSDHC_Ip_SwitchVoltage(Config->usdhcConfig->instance, TRUE))
            {
                Status = (Sd_Emmc_Ip_StatusType)SD_IP_STATUS_SWITCH_VOLTAGE_FAILED;
            }
        }
    }

    return Status;
}
#endif /* USDHC_IP_V180_SUPPORT */

/**
* @brief         Sd_Ip_GoIdle
* @details       Send GO_IDLE command to set the card to be idle state.
*
* @param[in]     Config Card descriptor.
*
* @return        Status    
* @pre           The USDHC driver needs to be initialized.
*/
static inline Sd_Emmc_Ip_StatusType Sd_Ip_GoIdle(const Sd_Emmc_Ip_ConfigType *Config)
{
    Sd_Emmc_Ip_StatusType Status = (Sd_Emmc_Ip_StatusType)SD_IP_STATUS_SUCCESS;

    /* Set the command atributes */
    Sd_Emmc_Ip_TransferStorage.command.index = (uint32)aSDMMC_GoIdleState;
    Sd_Emmc_Ip_TransferStorage.command.argument = 0U;
    Sd_Emmc_Ip_TransferStorage.command.type = USDHC_COMMAND_TYPE_NORMAL;
    Sd_Emmc_Ip_TransferStorage.command.responseType = USDHC_RESPONSE_TYPE_NONE;

    /* store transfer description */
    Sd_Emmc_Ip_TransferStorage.content.command = &Sd_Emmc_Ip_TransferStorage.command;
    Sd_Emmc_Ip_TransferStorage.content.data = NULL_PTR;

    /* start transfer */
    if (STATUS_USDHC_IP_SUCCESS != uSDHC_Ip_Transfer(Config->usdhcConfig->instance, &Sd_Emmc_Ip_TransferStorage.content, (boolean)FALSE))
    {
        Status = (Sd_Emmc_Ip_StatusType)SD_IP_STATUS_GO_IDLE_FAILED;
    }

    return Status;
}

/**
* @brief         Sd_Ip_SetBlockSize
* @details       Send SET_BLOCK_SIZE command to set card block size.
*
* @param[in]     Config Card descriptor.
*
* @return        Status    
* @pre           The USDHC driver needs to be initialized.
*/
static inline Sd_Emmc_Ip_StatusType Sd_Ip_SetBlockSize(const Sd_Emmc_Ip_ConfigType *Config, uint32 BlockSize)
{
    Sd_Emmc_Ip_StatusType Status = (Sd_Emmc_Ip_StatusType)SD_IP_STATUS_SUCCESS;

    /* Prepare the transfer description */
    Sd_Emmc_Ip_TransferStorage.command.index = (uint32)aSDMMC_SetBlockLength;
    Sd_Emmc_Ip_TransferStorage.command.argument = BlockSize;
    Sd_Emmc_Ip_TransferStorage.command.type = USDHC_COMMAND_TYPE_NORMAL;
    Sd_Emmc_Ip_TransferStorage.command.responseType = USDHC_RESPONSE_TYPE_R1;
    /* Store the transfer description */
    Sd_Emmc_Ip_TransferStorage.content.command = &Sd_Emmc_Ip_TransferStorage.command;
    Sd_Emmc_Ip_TransferStorage.content.data = NULL_PTR;
    /* Start transfer */
    if ((STATUS_USDHC_IP_SUCCESS != uSDHC_Ip_Transfer(Config->usdhcConfig->instance, &Sd_Emmc_Ip_TransferStorage.content, (boolean)FALSE)) || (0U != ((Sd_Emmc_Ip_TransferStorage.command.response[0U]) & (uint32)SD_IP_R1_ALL_ERROR_FLAGS)))
    {
        Status = (Sd_Emmc_Ip_StatusType)SD_IP_STATUS_TRANSFER_FAILED;
    }

    return Status;
}

/**
* @brief         Sd_Ip_SetBlockCount
* @details       Send SET_BLOCK_COUNT command for next transfer.
*
* @param[in]     Config Card descriptor.
* @param[in]     BlockCount    Block count.
*
* @return        Status    
* @pre           The USDHC driver needs to be initialized.
*/
static inline Sd_Emmc_Ip_StatusType Sd_Ip_SetBlockCount(const Sd_Emmc_Ip_ConfigType *Config, uint32 BlockCount)
{
    Sd_Emmc_Ip_StatusType Status = (Sd_Emmc_Ip_StatusType)SD_IP_STATUS_SUCCESS;

    /* Prepare the command transfer description */
    Sd_Emmc_Ip_TransferStorage.command.index = (uint32)aSDMMC_SetBlockCount;
    Sd_Emmc_Ip_TransferStorage.command.argument = BlockCount;
    Sd_Emmc_Ip_TransferStorage.command.type = USDHC_COMMAND_TYPE_NORMAL;
    Sd_Emmc_Ip_TransferStorage.command.responseType = USDHC_RESPONSE_TYPE_R1;

    Sd_Emmc_Ip_TransferStorage.content.command = &Sd_Emmc_Ip_TransferStorage.command;
    Sd_Emmc_Ip_TransferStorage.content.data = NULL_PTR;
    /* Start transfer */
    if ((STATUS_USDHC_IP_SUCCESS != uSDHC_Ip_Transfer(Config->usdhcConfig->instance, &Sd_Emmc_Ip_TransferStorage.content, (boolean)FALSE)) || (0U != ((Sd_Emmc_Ip_TransferStorage.command.response[0U]) & (uint32)SD_IP_R1_ALL_ERROR_FLAGS)))
    {
        /* the errors occurred */
        Status = (Sd_Emmc_Ip_StatusType)SD_IP_STATUS_TRANSFER_FAILED;
    }

    return Status;
}

/**
* @brief         Sd_Ip_SendRca
* @details       Send GET_RCA command to get card relative address.
*
* @param[in]     Config Card descriptor.
*
* @return        Status    
* @pre           The USDHC driver needs to be initialized.
*/
static Sd_Emmc_Ip_StatusType Sd_Ip_SendRca(const Sd_Emmc_Ip_ConfigType *Config)
{
    Sd_Emmc_Ip_StatusType Status = (Sd_Emmc_Ip_StatusType)SD_IP_STATUS_SUCCESS;

    /* Prepare the command description */
    Sd_Emmc_Ip_TransferStorage.command.index = (uint32)aSD_SendRelativeAddress;
    Sd_Emmc_Ip_TransferStorage.command.type = USDHC_COMMAND_TYPE_NORMAL;
    /* Set the argument and response type */
    if (SD_IP_MEMORY_CARD_MMC == Sd_Emmc_Ip_eCardTypeInfo)
    {
        Sd_Emmc_Ip_TransferStorage.command.argument = 0x00020000U;
        Sd_Emmc_Ip_TransferStorage.command.responseType = USDHC_RESPONSE_TYPE_R1;
    }
    else
    {
        Sd_Emmc_Ip_TransferStorage.command.argument = 0x00000000U;
        Sd_Emmc_Ip_TransferStorage.command.responseType = USDHC_RESPONSE_TYPE_R6;
    }

    Sd_Emmc_Ip_TransferStorage.content.command = &Sd_Emmc_Ip_TransferStorage.command;
    Sd_Emmc_Ip_TransferStorage.content.data = NULL_PTR;
    /* Start transfer */
    if (STATUS_USDHC_IP_SUCCESS == uSDHC_Ip_Transfer(Config->usdhcConfig->instance, &Sd_Emmc_Ip_TransferStorage.content, (boolean)FALSE))
    {
        /* Set the relative address */
        if (SD_IP_MEMORY_CARD_MMC == Sd_Emmc_Ip_eCardTypeInfo)
        {
            Sd_Emmc_Ip_u32RelativeAddress = 0x2U;
        }
        else
        {
            Sd_Emmc_Ip_u32RelativeAddress = (Sd_Emmc_Ip_TransferStorage.command.response[0U] >> 16U);
        }
    }
    else
    {
        /* The errors occurred */
        Status = (Sd_Emmc_Ip_StatusType)SD_IP_STATUS_TRANSFER_FAILED;
    }

    return Status;
}

/**
* @brief         Sd_Ip_SwitchFunction
* @details       Send SWITCH_FUNCTION command to switch the card function group.
*
* @param[in]     Config Card descriptor.
* @param[in]     Mode          0 to check function group. 1 to switch function group
* @param[in]     Group         Function group
* @param[in]     Number        Function number in the function group.
* @param[in]     Status        Switch function Status.
*
* @return        State    
* @pre           The USDHC driver needs to be initialized.
*/
static Sd_Emmc_Ip_StatusType Sd_Ip_SwitchFunction(const Sd_Emmc_Ip_ConfigType *Config,
                                                  Sd_Ip_SwitchModeType Mode,
                                                  Sd_Ip_GroupNumType Group,
                                                  uint32 Number,
                                                  uint32 *Status
                                                 )
{
    Sd_Emmc_Ip_StatusType State = (Sd_Emmc_Ip_StatusType)SD_IP_STATUS_SUCCESS;

    /* Set block size */
    if ((Sd_Emmc_Ip_StatusType)SD_IP_STATUS_SUCCESS != Sd_Ip_SetBlockSize(Config, 64U))
    {
        State = (Sd_Emmc_Ip_StatusType)SD_IP_STATUS_SET_CARD_BLOCK_SIZE_FAILED;
    }
    else
    {
        /* Prepare the command transfer atributes */
        Sd_Emmc_Ip_TransferStorage.command.index        = (uint32)aSD_Switch;
        Sd_Emmc_Ip_TransferStorage.command.argument     = (((uint32)(Mode) << 31U) | 0x00FFFFFFU);
        Sd_Emmc_Ip_TransferStorage.command.argument    &= ~((uint32)(0xFU) << ((uint32)Group * 4U));
        Sd_Emmc_Ip_TransferStorage.command.argument    |= (Number << ((uint32)Group * 4U));
        Sd_Emmc_Ip_TransferStorage.command.type         = USDHC_COMMAND_TYPE_NORMAL;
        Sd_Emmc_Ip_TransferStorage.command.responseType = USDHC_RESPONSE_TYPE_R1;
        /* Prepare the data transfer atributes */
        Sd_Emmc_Ip_TransferStorage.data.blockSize       = 64U;
        Sd_Emmc_Ip_TransferStorage.data.blockCount      = 1U;
        Sd_Emmc_Ip_TransferStorage.data.rxData          = Status;
        Sd_Emmc_Ip_TransferStorage.data.txData          = NULL_PTR;
        /* store the transfer description */
        Sd_Emmc_Ip_TransferStorage.content.command      = &Sd_Emmc_Ip_TransferStorage.command;
        Sd_Emmc_Ip_TransferStorage.content.data         = &Sd_Emmc_Ip_TransferStorage.data;
        /* start transfer */
        if ( (STATUS_USDHC_IP_SUCCESS != uSDHC_Ip_Transfer(Config->usdhcConfig->instance, &Sd_Emmc_Ip_TransferStorage.content, (boolean)FALSE)) ||
             (0U != (Sd_Emmc_Ip_TransferStorage.command.response[0U] & (uint32)(SD_IP_R1_ALL_ERROR_FLAGS)))
           )
        {
            State = (Sd_Emmc_Ip_StatusType)SD_IP_STATUS_TRANSFER_FAILED;
        }
    }

    return State;
}

/**
* @brief         Sd_Ip_MmcSendExtCsd
* @details       Send EXT_CSD routine.
*
* @param[in]     Config Card descriptor.
*
* @return        Status    
* @pre           The USDHC driver needs to be initialized.
*/
static Sd_Emmc_Ip_StatusType Sd_Ip_MmcSendExtCsd(const Sd_Emmc_Ip_ConfigType *Config)
{
    Sd_Emmc_Ip_StatusType Status = (Sd_Emmc_Ip_StatusType)SD_IP_STATUS_SUCCESS;
    
    /* Set command index */
    Sd_Emmc_Ip_TransferStorage.command.index = (uint32)aMMC_SendExtendedCsd;
    /* Set argument */
    Sd_Emmc_Ip_TransferStorage.command.argument = 0U;
    /* Set command type and response */
    Sd_Emmc_Ip_TransferStorage.command.type = USDHC_COMMAND_TYPE_NORMAL;
    Sd_Emmc_Ip_TransferStorage.command.responseType = USDHC_RESPONSE_TYPE_R1;

    /* Set buffer atributes */
    Sd_Emmc_Ip_TransferStorage.data.blockSize = 512U;
    Sd_Emmc_Ip_TransferStorage.data.blockCount = 1U;
    Sd_Emmc_Ip_TransferStorage.data.rxData = (uint32 *)Sd_Emmc_Ip_u32CsdBuffer;
    Sd_Emmc_Ip_TransferStorage.data.txData = NULL_PTR;

    Sd_Emmc_Ip_TransferStorage.content.command = &Sd_Emmc_Ip_TransferStorage.command;
    Sd_Emmc_Ip_TransferStorage.content.data = &Sd_Emmc_Ip_TransferStorage.data;

    /* Start transfer */
    if (STATUS_USDHC_IP_SUCCESS != uSDHC_Ip_Transfer(Config->usdhcConfig->instance, &Sd_Emmc_Ip_TransferStorage.content, (boolean)FALSE))
    {
        Status = (Sd_Emmc_Ip_StatusType)SD_IP_STATUS_TRANSFER_FAILED;
    }
    else
    {
        /* Switch function Status byte sequence from card is litle endian(LSB first). */
        switch (Config->usdhcConfig->endianMode)
        {
            case USDHC_ENDIAN_MODE_BIG:
                Sd_Emmc_Ip_u32CsdBuffer[MMC_EXT_CSD_INDEX_SEC_CNT          >> 2U] = Sd_Ip_LoadDword(Sd_Emmc_Ip_u32CsdBuffer, (MMC_EXT_CSD_INDEX_SEC_CNT          >> 2U) * sizeof(uint32));
                Sd_Emmc_Ip_u32CsdBuffer[MMC_EXT_CSD_INDEX_DATA_SECTOR_SIZE >> 2U] = Sd_Ip_LoadDword(Sd_Emmc_Ip_u32CsdBuffer, (MMC_EXT_CSD_INDEX_DATA_SECTOR_SIZE >> 2U) * sizeof(uint32));
                Sd_Emmc_Ip_u32CsdBuffer[MMC_EXT_CSD_INDEX_BUS_WIDTH        >> 2U] = Sd_Ip_LoadDword(Sd_Emmc_Ip_u32CsdBuffer, (MMC_EXT_CSD_INDEX_BUS_WIDTH        >> 2U) * sizeof(uint32));
                Sd_Emmc_Ip_u32CsdBuffer[MMC_EXT_CSD_INDEX_REV              >> 2U] = Sd_Ip_LoadDword(Sd_Emmc_Ip_u32CsdBuffer, (MMC_EXT_CSD_INDEX_REV              >> 2U) * sizeof(uint32));
                Sd_Emmc_Ip_u32CsdBuffer[MMC_EXT_CSD_INDEX_CARD_TYPE        >> 2U] = Sd_Ip_LoadDword(Sd_Emmc_Ip_u32CsdBuffer, (MMC_EXT_CSD_INDEX_CARD_TYPE        >> 2U) * sizeof(uint32));
                Sd_Emmc_Ip_u32CsdBuffer[MMC_EXT_CSD_STROBE_SUPPORT         >> 2U] = Sd_Ip_LoadDword(Sd_Emmc_Ip_u32CsdBuffer, (MMC_EXT_CSD_STROBE_SUPPORT         >> 2U) * sizeof(uint32));
                Sd_Emmc_Ip_u32CsdBuffer[MMC_EXT_CSD_INDEX_PARTITION_CONFIG >> 2U] = Sd_Ip_LoadDword(Sd_Emmc_Ip_u32CsdBuffer, (MMC_EXT_CSD_INDEX_PARTITION_CONFIG >> 2U) * sizeof(uint32));
                Sd_Emmc_Ip_u32CsdBuffer[MMC_EXT_CSD_INDEX_BOOT_SIZE_MULT   >> 2U] = Sd_Ip_LoadDword(Sd_Emmc_Ip_u32CsdBuffer, (MMC_EXT_CSD_INDEX_BOOT_SIZE_MULT   >> 2U) * sizeof(uint32));
                Sd_Emmc_Ip_u32CsdBuffer[MMC_EXT_CSD_INDEX_BOOT_INFO        >> 2U] = Sd_Ip_LoadDword(Sd_Emmc_Ip_u32CsdBuffer, (MMC_EXT_CSD_INDEX_BOOT_INFO        >> 2U) * sizeof(uint32));
                break;

            case USDHC_ENDIAN_MODE_HALF_WORD_BIG:
                Sd_Emmc_Ip_u32CsdBuffer[MMC_EXT_CSD_INDEX_SEC_CNT          >> 2U] = Sd_Ip_SwapHword(Sd_Emmc_Ip_u32CsdBuffer, (MMC_EXT_CSD_INDEX_SEC_CNT          >> 2U) * sizeof(uint32));
                Sd_Emmc_Ip_u32CsdBuffer[MMC_EXT_CSD_INDEX_DATA_SECTOR_SIZE >> 2U] = Sd_Ip_SwapHword(Sd_Emmc_Ip_u32CsdBuffer, (MMC_EXT_CSD_INDEX_DATA_SECTOR_SIZE >> 2U) * sizeof(uint32));
                Sd_Emmc_Ip_u32CsdBuffer[MMC_EXT_CSD_INDEX_BUS_WIDTH        >> 2U] = Sd_Ip_SwapHword(Sd_Emmc_Ip_u32CsdBuffer, (MMC_EXT_CSD_INDEX_BUS_WIDTH        >> 2U) * sizeof(uint32));
                Sd_Emmc_Ip_u32CsdBuffer[MMC_EXT_CSD_INDEX_REV              >> 2U] = Sd_Ip_SwapHword(Sd_Emmc_Ip_u32CsdBuffer, (MMC_EXT_CSD_INDEX_REV              >> 2U) * sizeof(uint32));
                Sd_Emmc_Ip_u32CsdBuffer[MMC_EXT_CSD_INDEX_CARD_TYPE        >> 2U] = Sd_Ip_SwapHword(Sd_Emmc_Ip_u32CsdBuffer, (MMC_EXT_CSD_INDEX_CARD_TYPE        >> 2U) * sizeof(uint32));
                Sd_Emmc_Ip_u32CsdBuffer[MMC_EXT_CSD_STROBE_SUPPORT         >> 2U] = Sd_Ip_SwapHword(Sd_Emmc_Ip_u32CsdBuffer, (MMC_EXT_CSD_STROBE_SUPPORT         >> 2U) * sizeof(uint32));
                Sd_Emmc_Ip_u32CsdBuffer[MMC_EXT_CSD_INDEX_PARTITION_CONFIG >> 2U] = Sd_Ip_SwapHword(Sd_Emmc_Ip_u32CsdBuffer, (MMC_EXT_CSD_INDEX_PARTITION_CONFIG >> 2U) * sizeof(uint32));
                Sd_Emmc_Ip_u32CsdBuffer[MMC_EXT_CSD_INDEX_BOOT_SIZE_MULT   >> 2U] = Sd_Ip_SwapHword(Sd_Emmc_Ip_u32CsdBuffer, (MMC_EXT_CSD_INDEX_BOOT_SIZE_MULT   >> 2U) * sizeof(uint32));
                Sd_Emmc_Ip_u32CsdBuffer[MMC_EXT_CSD_INDEX_BOOT_INFO        >> 2U] = Sd_Ip_SwapHword(Sd_Emmc_Ip_u32CsdBuffer, (MMC_EXT_CSD_INDEX_BOOT_INFO        >> 2U) * sizeof(uint32));
                break;

            default:
                /* Doesn't need to switch byte sequence when decodes bytes as big endian sequence. */
                break;
        }

        Status = Sd_Ip_MmcDecodeExtCsd(Sd_Emmc_Ip_u32CsdBuffer);
    }

    return Status;
}

#if (STD_ON == FEATURE_USDHC_HAS_HIGHSPEED_TUNNING)
static Sd_Emmc_Ip_StatusType Sd_Ip_VerifyTuningPattern4bit(const Sd_Emmc_Ip_ConfigType *Config)
{
    Sd_Emmc_Ip_StatusType Status = SD_IP_STATUS_SUCCESS;
    uint32 Index;

    /* Swap data by endianess */
    switch (Config->usdhcConfig->endianMode)
    {
        case USDHC_ENDIAN_MODE_LITTLE:
            /* Swap bytes: A-B-C-D to D-C-B-A */
            for (Index = 0; Index < MMC_TUNING_4BIT_PATTERN_WORDS; Index++)
            {
                Sd_Emmc_Ip_u32TuningDestBuffer[Index] = Sd_Ip_LoadDword(Sd_Emmc_Ip_u32TuningDestBuffer, Index * sizeof(uint32));
            }
            break;

        case USDHC_ENDIAN_MODE_HALF_WORD_BIG:
            /* Swap bytes: A-B-C-D to B-A-D-C */
            for (Index = 0; Index < MMC_TUNING_4BIT_PATTERN_WORDS; Index++)
            {
                Sd_Emmc_Ip_u32TuningDestBuffer[Index] = Sd_Ip_LoadHword(Sd_Emmc_Ip_u32TuningDestBuffer, Index * sizeof(uint32));
            }
            break;

        default:
            /* USDHC_ENDIAN_MODE_BIG */
            /* Doesn't need to switch byte sequence when decodes bytes as big endian sequence. */
            break;
    }

    /* Verify the received tuning data */
    for (Index = 0; Index < MMC_TUNING_4BIT_PATTERN_WORDS; Index++)
    {
        if (Sd_Emmc_Ip_u32TuningDestBuffer[Index] != u32TuningPattern4bit[Index])
        {
            Status = SD_IP_STATUS_TUNING_FAILED;
            break;
        }
    }

    return Status;
}

static Sd_Emmc_Ip_StatusType Sd_Ip_VerifyTuningPattern8bit(const Sd_Emmc_Ip_ConfigType *Config)
{
    Sd_Emmc_Ip_StatusType Status = SD_IP_STATUS_SUCCESS;
    uint32 Index;

    /* Swap data by endianess */
    switch (Config->usdhcConfig->endianMode)
    {
        case USDHC_ENDIAN_MODE_LITTLE:
            /* Swap bytes: A-B-C-D to D-C-B-A */
            for (Index = 0; Index < MMC_TUNING_8BIT_PATTERN_WORDS; Index++)
            {
                Sd_Emmc_Ip_u32TuningDestBuffer[Index] = Sd_Ip_LoadDword(Sd_Emmc_Ip_u32TuningDestBuffer, Index * sizeof(uint32));
            }
            break;

        case USDHC_ENDIAN_MODE_HALF_WORD_BIG:
            /* Swap bytes: A-B-C-D to B-A-D-C */
            for (Index = 0; Index < MMC_TUNING_8BIT_PATTERN_WORDS; Index++)
            {
                Sd_Emmc_Ip_u32TuningDestBuffer[Index] = Sd_Ip_LoadHword(Sd_Emmc_Ip_u32TuningDestBuffer, Index * sizeof(uint32));
            }
            break;

        default:
            /* USDHC_ENDIAN_MODE_BIG */
            /* Doesn't need to switch byte sequence when decodes bytes as big endian sequence. */
            break;
    }

    /* Verify the received tuning data */
    for (Index = 0; Index < MMC_TUNING_8BIT_PATTERN_WORDS; Index++)
    {
        if (Sd_Emmc_Ip_u32TuningDestBuffer[Index] != u32TuningPattern8bit[Index])
        {
            Status = SD_IP_STATUS_TUNING_FAILED;
            break;
        }
    }

    return Status;
}

/**
* @brief         Sd_Ip_MmcSendTuning
* @details       Send tuning command
*
* @param[in]     Config Card descriptor.
* @param[in]     BlockSize Select block size for transfer
*
* @return        Status    
* @pre           The USDHC driver needs to be initialized.
*/
static Sd_Emmc_Ip_StatusType Sd_Ip_MmcSendTuning(const Sd_Emmc_Ip_ConfigType *Config, uint32 BlockSize)
{
    Sd_Emmc_Ip_StatusType Status = (Sd_Emmc_Ip_StatusType)SD_IP_STATUS_SUCCESS;

    /* Prepare the transfer command */
    Sd_Emmc_Ip_TransferStorage.command.index        = (uint32)aSDMMC_SendTuningPattern;
    Sd_Emmc_Ip_TransferStorage.command.argument     = 0U;
    Sd_Emmc_Ip_TransferStorage.command.type         = USDHC_COMMAND_TYPE_NORMAL;
    Sd_Emmc_Ip_TransferStorage.command.responseType = USDHC_RESPONSE_TYPE_R1;
    Sd_Emmc_Ip_TransferStorage.content.command      = &Sd_Emmc_Ip_TransferStorage.command;
    /* Store the transfer data */
    Sd_Emmc_Ip_TransferStorage.data.blockSize       = BlockSize;
    Sd_Emmc_Ip_TransferStorage.data.blockCount      = 1;
    Sd_Emmc_Ip_TransferStorage.data.rxData          = (uint32 *)Sd_Emmc_Ip_u32TuningDestBuffer;
    Sd_Emmc_Ip_TransferStorage.data.txData          = NULL_PTR;
    Sd_Emmc_Ip_TransferStorage.content.data         = &Sd_Emmc_Ip_TransferStorage.data;

    /* Start transfer */
    if ((STATUS_USDHC_IP_SUCCESS != uSDHC_Ip_Transfer(Config->usdhcConfig->instance, &Sd_Emmc_Ip_TransferStorage.content, (boolean)FALSE)) || \
            (0U != ((Sd_Emmc_Ip_TransferStorage.command.response[0U]) & (uint32)SD_IP_R1_ALL_ERROR_FLAGS)))
    {
        Status = (Sd_Emmc_Ip_StatusType)SD_IP_STATUS_TRANSFER_FAILED;
    }
    else
    {
        /* Compare data received from the card with tuning pattern to check if tuning successful or not */
        switch (Config->busWidthMode)
        {
            case SD_IP_DATABUSWIDTH_4BIT:
                Status = Sd_Ip_VerifyTuningPattern4bit(Config);
                break;

            case SD_IP_DATABUSWIDTH_8BIT:
            case SD_IP_DATABUSWIDTH_8BIT_DDR:
                Status = Sd_Ip_VerifyTuningPattern8bit(Config);
                break;

            default:
                /* Do nothing */
                break;
        }
    }

    return Status;
}

/**
* @brief         Sd_Ip_MmcExecuteTuning
* @details       Execute tuning process
*
* @param[in]     Config Card descriptor.
* @param[in]     blockSize Select block size for transfer
*
* @return        Status    
* @pre           The USDHC driver needs to be initialized.
*/
static Sd_Emmc_Ip_StatusType Sd_Ip_MmcExecuteTuning(const Sd_Emmc_Ip_ConfigType *Config, uint32 BlockSize)
{
    Sd_Emmc_Ip_StatusType Status = (Sd_Emmc_Ip_StatusType)SD_IP_STATUS_SUCCESS;
    uint8 MinDelay, MaxDelay, AvgDelay;

    /* Setup USDHC registers before tuning process */
    uSDHC_Ip_PreTuning(Config->usdhcConfig->instance);

    /* find the mininum delay first which can pass tuning */
    MinDelay = MMC_TUNING_RETRIES_MIN;
    while (MinDelay < MMC_TUNE_CTRL_MAX) {
        uSDHC_Ip_ConfigTuning(Config->usdhcConfig->instance, MinDelay);
        if (SD_IP_STATUS_SUCCESS == Sd_Ip_MmcSendTuning(Config, BlockSize))
        {
            break;
        }
        MinDelay += MMC_TUNE_CTRL_STEP;
    }

    /* find the maxinum delay which can not pass tuning */
    MaxDelay = MinDelay + MMC_TUNE_CTRL_STEP;
    while (MaxDelay < MMC_TUNE_CTRL_MAX) {
        uSDHC_Ip_ConfigTuning(Config->usdhcConfig->instance, MaxDelay);
        if (SD_IP_STATUS_SUCCESS != Sd_Ip_MmcSendTuning(Config, BlockSize))
        {
            MaxDelay -= MMC_TUNE_CTRL_STEP;
            break;
        }
        MaxDelay += MMC_TUNE_CTRL_STEP;
    }

    /* use average delay to get the best timing */
    AvgDelay = (MinDelay + MaxDelay) >> 1U;
    uSDHC_Ip_ConfigTuning(Config->usdhcConfig->instance, AvgDelay);
    Status = Sd_Ip_MmcSendTuning(Config, BlockSize);

    /* Setup USDHC registers after tuning process */
    uSDHC_Ip_PostTuning(Config->usdhcConfig->instance);

    return Status;
}
#endif /* (STD_ON == FEATURE_USDHC_HAS_HIGHSPEED_TUNNING) */

/**
* @brief         Sd_Ip_MmcSwitch
* @details       Switch routine for settting EXT_CSD register.
*
* @param[in]     Config Card descriptor.
* @param[in]     Access        type of operation
* @param[in]     Index         index in EXT_CSD register
* @param[in]     Value         value to write in EXT_CSD register
*
* @return        Status    
* @pre           The USDHC driver needs to be initialized.
*/
static Sd_Emmc_Ip_StatusType Sd_Ip_MmcSwitch(const Sd_Emmc_Ip_ConfigType *Config, uint32 Access, uint8 Index, uint32 Value)
{
    Sd_Emmc_Ip_StatusType Status = (Sd_Emmc_Ip_StatusType)SD_IP_STATUS_SUCCESS;

    /* Prepare the transfer description */
    Sd_Emmc_Ip_TransferStorage.command.index        = (uint32)aMMC_Switch;
    Sd_Emmc_Ip_TransferStorage.command.argument     = (uint32)(Access | ((uint32)Index  << MMCShiftIndex) | Value);
    Sd_Emmc_Ip_TransferStorage.command.type         = USDHC_COMMAND_TYPE_NORMAL;
    Sd_Emmc_Ip_TransferStorage.command.responseType = USDHC_RESPONSE_TYPE_R1b;
    /* Store the transfer description */
    Sd_Emmc_Ip_TransferStorage.content.command      = &Sd_Emmc_Ip_TransferStorage.command;
    Sd_Emmc_Ip_TransferStorage.content.data         = NULL_PTR;
    /* Start transfer */
    if (STATUS_USDHC_IP_SUCCESS != uSDHC_Ip_Transfer(Config->usdhcConfig->instance, &Sd_Emmc_Ip_TransferStorage.content, (boolean)FALSE))
    {
        Status = (Sd_Emmc_Ip_StatusType)SD_IP_STATUS_TRANSFER_FAILED;
    }
    /* Waiting for write operation complete */
    if ((Sd_Emmc_Ip_StatusType)SD_IP_STATUS_SUCCESS != Sd_Ip_WaitWriteComplete(Config))
    {
        Status = (Sd_Emmc_Ip_StatusType)SD_IP_STATUS_WAIT_WRITE_COMPLETE_FAILED;
    }

    return Status;

}

/**
* @brief         Sd_Ip_DecodeScr
* @details       Decode raw SCR register content in the data blocks.
*
* @param[in]     Config Card descriptor.
* @param[in]     RegScr Raw SCR register content.
*
* @return        void    
* @pre           The USDHC driver needs to be initialized.
*/
static void Sd_Ip_DecodeScr(const Sd_Emmc_Ip_ConfigType *Config, const uint32 *RegScr)
{
    /* Get the scrStructure */
    Sd_Emmc_Ip_Scr.scrStructure = (uint8)((RegScr[0U] & 0xF0000000U) >> 28U);
    /* Get the sdSpecification */
    Sd_Emmc_Ip_Scr.sdSpecification = (uint8)((RegScr[0U] & 0xF000000U) >> 24U);
    if (((RegScr[0U] & 0x800000U) >> 23U) != 0U)
    {
        Sd_Emmc_Ip_Scr.flags |= (uint16)aSD_ScrDataStatusAfterErase;
    }
    /* Get the sdSecurity */
    Sd_Emmc_Ip_Scr.sdSecurity = (uint8)((RegScr[0U] & 0x700000U) >> 20U);
    /* Get the sdBusWidths */
    Sd_Emmc_Ip_Scr.sdBusWidths = (uint8)((RegScr[0U] & 0xF0000U) >> 16U);
    if (((uint8)((RegScr[0U] & 0x8000U) >> 15U)) != 0U)
    {
        Sd_Emmc_Ip_Scr.flags |= (uint16)aSD_ScrSdSpecification3;
    }
    /* Get the extendedSecurity */
    Sd_Emmc_Ip_Scr.extendedSecurity = (uint8)((RegScr[0U] & 0x7800U) >> 10U);
    /* Get the commandSupport */
    Sd_Emmc_Ip_Scr.commandSupport = (uint8)(RegScr[0U] & 0x3U);
    /* Get the reservedForManufacturer */
    Sd_Emmc_Ip_Scr.reservedForManufacturer = RegScr[1U];

    /* Get specification version. */
    switch (Sd_Emmc_Ip_Scr.sdSpecification)
    {
        case 0U:
            Sd_Emmc_Ip_u32VersionInfo = (uint32)aSD_SpecificationVersion1_0;
            break;

        case 1U:
            Sd_Emmc_Ip_u32VersionInfo = (uint32)aSD_SpecificationVersion1_1;
            break;

        case 2U:
            Sd_Emmc_Ip_u32VersionInfo = (uint32)aSD_SpecificationVersion2_0;
            if (0U != (Sd_Emmc_Ip_Scr.flags & (uint16)aSD_ScrSdSpecification3))
            {
                Sd_Emmc_Ip_u32VersionInfo = (uint32)aSD_SpecificationVersion3_0;
            }
            break;

        default:
            /* Others! */
            break;
    }
    /* Set the Sd config flags */
    if (0U != (Sd_Emmc_Ip_Scr.sdBusWidths & (uint8)aSD_DataBusWidth4Bit))
    {
        Sd_Emmc_Ip_u32CardFlags |= (uint32)SD_IP_SUPPORT_4_BIT_WIDTH_FLAG;
    }

    Sd_Emmc_Ip_u32CardFlags |= ((uint32)Sd_Emmc_Ip_Scr.commandSupport & (uint32)SD_IP_SUPPORT_SPEED_CLASS_CONTROL_CMD);

    /* SD specification v.3.00 states, CMD23 should be disabled for ADMA1 */
    if (USDHC_DMA_MODE_ADMA1 != Config->usdhcConfig->dmaMode)
    {
        Sd_Emmc_Ip_u32CardFlags |= ((uint32)Sd_Emmc_Ip_Scr.commandSupport & (uint32)SD_IP_SUPPORT_SET_BLOCK_COUNT_CMD);
    }
}

/**
* @brief         Sd_Ip_SendScr
* @details       Send GET_SCR command.
*
* @param[in]     Config Card descriptor.
*
* @return        Status    
* @pre           The USDHC driver needs to be initialized.
*/
static Sd_Emmc_Ip_StatusType Sd_Ip_SendScr(const Sd_Emmc_Ip_ConfigType *Config)
{
    /*
     * uSDHC Host Controller Capabilities register contains MBL (Maximum Block Length) bit set to 011b which means 4096 bytes.
     * This value indicates the maximum block size that the Host Driver can read and write to the buffer in the uSDHC.
     * The buffer shall transfer block size without wait cycles.
     */
    Sd_Emmc_Ip_StatusType Status = (Sd_Emmc_Ip_StatusType)SD_IP_STATUS_SUCCESS;

    /* Send application command */
    if ((Sd_Emmc_Ip_StatusType)SD_IP_STATUS_SUCCESS != Sd_Ip_SendApplicationCmd(Config))
    {
        Status = (Sd_Emmc_Ip_StatusType)SD_IP_STATUS_SEND_APPL_COMMAND_FAILED;
    }

    if ((Sd_Emmc_Ip_StatusType)SD_IP_STATUS_SUCCESS == Status)
    {
        /* Prepare the command transfer description */
        Sd_Emmc_Ip_TransferStorage.command.index        = (uint32)aSD_ApplicationSendScr;
        Sd_Emmc_Ip_TransferStorage.command.type         = USDHC_COMMAND_TYPE_NORMAL;
        Sd_Emmc_Ip_TransferStorage.command.responseType = USDHC_RESPONSE_TYPE_R1;
        Sd_Emmc_Ip_TransferStorage.command.argument     = 0U;
        /* Prepare the data transfer description */
        Sd_Emmc_Ip_TransferStorage.data.blockSize       = 8U;
        Sd_Emmc_Ip_TransferStorage.data.blockCount      = 1U;
        Sd_Emmc_Ip_TransferStorage.data.rxData          = Sd_Emmc_Ip_u32RegScr;
        Sd_Emmc_Ip_TransferStorage.data.txData          = NULL_PTR;

        Sd_Emmc_Ip_TransferStorage.content.data         = &Sd_Emmc_Ip_TransferStorage.data;
        Sd_Emmc_Ip_TransferStorage.content.command      = &Sd_Emmc_Ip_TransferStorage.command;
        /* Start transfer */
        if ((STATUS_USDHC_IP_SUCCESS != uSDHC_Ip_Transfer(Config->usdhcConfig->instance, &Sd_Emmc_Ip_TransferStorage.content, (boolean)FALSE)) || (0U != ((Sd_Emmc_Ip_TransferStorage.command.response[0U]) & (uint32)SD_IP_R1_ALL_ERROR_FLAGS)))
        {
            Status = (Sd_Emmc_Ip_StatusType)SD_IP_STATUS_TRANSFER_FAILED;
        }

    }

    if ((Sd_Emmc_Ip_StatusType)SD_IP_STATUS_SUCCESS == Status)
    {
        /* SCR register data byte sequence from card is big endian(MSB first). */
        switch (Config->usdhcConfig->endianMode)
        {
            case USDHC_ENDIAN_MODE_LITTLE:
                /* In little endian mode, SD bus byte transferred first is the byte stored in lowest byte position in a
                word which will cause 4 byte's sequence in a word is not consistent with their original sequence from
                card. So the sequence of 4 bytes received in a word should be converted. */
                Sd_Emmc_Ip_u32RegScr[0U] = Sd_Ip_LoadDword(Sd_Emmc_Ip_u32RegScr, 0U);
                Sd_Emmc_Ip_u32RegScr[1U] = Sd_Ip_LoadDword(Sd_Emmc_Ip_u32RegScr, 1U * sizeof(uint32));
                break;

            case USDHC_ENDIAN_MODE_HALF_WORD_BIG:
                Sd_Emmc_Ip_u32RegScr[0U] = Sd_Ip_LoadHword(Sd_Emmc_Ip_u32RegScr, 0U);
                Sd_Emmc_Ip_u32RegScr[1U] = Sd_Ip_LoadHword(Sd_Emmc_Ip_u32RegScr, 1U * sizeof(uint32));
                break;

            case USDHC_ENDIAN_MODE_BIG:
                break; /* Doesn't need to switch byte sequence when decodes bytes as big endian sequence. */

            default:
                Status = (Sd_Emmc_Ip_StatusType)SD_IP_STATUS_NOT_SUPPORTED;
                break;
        }

        if ((Sd_Emmc_Ip_StatusType)SD_IP_STATUS_SUCCESS == Status)
        {
            /* Decode Scr */
            Sd_Ip_DecodeScr(Config, Sd_Emmc_Ip_u32RegScr);
        }
    }

    return Status;
}

/**
* @brief         Sd_Ip_SwitchFunctionCheck
* @details       Check supported of a function in a given group
*
* @return        Status
* @pre           The USDHC driver needs to be initialized.
*/
static inline Sd_Emmc_Ip_StatusType Sd_Ip_SwitchFunctionCheck(uint32 SupportBis,
                                                              uint32 FunctionGroupStatus,
                                                              Sd_Ip_GroupNumType Group,
                                                              uint32 Function
                                                             )
{
    Sd_Emmc_Ip_StatusType Status;

    /* Check the corresponding support bit in Group
       and the function can be switched in the status field
     */
    if ( ((SupportBis & ((uint32)1U << Function)) == 0U) ||
         (((FunctionGroupStatus >> ((uint32)Group * 4U)) & 0x0FU) != Function)
       )
    {
        Status = (Sd_Emmc_Ip_StatusType)SD_IP_STATUS_CARD_NOT_SUPPORTED;
    }
    else
    {
        Status = (Sd_Emmc_Ip_StatusType)SD_IP_STATUS_SUCCESS;
    }

    return Status;
}

/**
* @brief         Sd_Ip_SwitchFunctionSet
* @details       Check the result of a switch command
*
* @return        Status
* @pre           The USDHC driver needs to be initialized.
*/
static inline Sd_Emmc_Ip_StatusType Sd_Ip_SwitchFunctionSet(uint32 FunctionGroupStatus,
                                                            Sd_Ip_GroupNumType Group,
                                                            uint32 Function
                                                           )
{
    Sd_Emmc_Ip_StatusType Status;

    /* Check the result of switch command */
    if (((FunctionGroupStatus >> ((uint32)Group * 4U)) & 0x0FU) != Function)
    {
        Status = (Sd_Emmc_Ip_StatusType)SD_IP_STATUS_SWITCH_FAILED;
    }
    else
    {
        Status = (Sd_Emmc_Ip_StatusType)SD_IP_STATUS_SUCCESS;
    }

    return Status;
}


/**
* @brief         Sd_Ip_CheckAndSwitchFunction
* @details       Switch the card to be high speed mode.
*
* @param[in]     Config Card descriptor.
* @param[in]     Group group number.
* @param[in]     Function function number.
*
* @return        Status    
* @pre           The USDHC driver needs to be initialized.
*/
static Sd_Emmc_Ip_StatusType Sd_Ip_CheckAndSwitchFunction(const Sd_Emmc_Ip_ConfigType *Config,
                                                          Sd_Ip_GroupNumType Group,
                                                          uint32 Function
                                                         )
{
    Sd_Emmc_Ip_StatusType Status = (Sd_Emmc_Ip_StatusType)SD_IP_STATUS_SUCCESS;
    uint32 FunctionGroupStatus;
    uint16 FunctionGroupInfo[6U];

    /* Check if card support high speed mode. */
    if ((Sd_Emmc_Ip_StatusType)SD_IP_STATUS_SUCCESS != Sd_Ip_SwitchFunction(Config, aSD_SwitchCheck, Group, Function, Sd_Emmc_Ip_u32FunctionStatus))
    {
        Status = (Sd_Emmc_Ip_StatusType)SD_IP_STATUS_SWITCH_FAILED;
    }
    else
    {
        /* Switch function Status byte sequence from card is big endian(MSB first). */
        switch (Config->usdhcConfig->endianMode)
        {
            case USDHC_ENDIAN_MODE_LITTLE:
                /* In little endian mode, SD bus byte transferred first is the byte stored in lowest byte position in
                a word which will cause 4 byte's sequence in a word is not consistent with their original sequence from
                card. So the sequence of 4 bytes received in a word should be converted. */
                Sd_Emmc_Ip_u32FunctionStatus[0U] = Sd_Ip_LoadDword(Sd_Emmc_Ip_u32FunctionStatus, 0U);
                Sd_Emmc_Ip_u32FunctionStatus[1U] = Sd_Ip_LoadDword(Sd_Emmc_Ip_u32FunctionStatus, 1U * sizeof(uint32));
                Sd_Emmc_Ip_u32FunctionStatus[2U] = Sd_Ip_LoadDword(Sd_Emmc_Ip_u32FunctionStatus, 2U * sizeof(uint32));
                Sd_Emmc_Ip_u32FunctionStatus[3U] = Sd_Ip_LoadDword(Sd_Emmc_Ip_u32FunctionStatus, 3U * sizeof(uint32));
                Sd_Emmc_Ip_u32FunctionStatus[4U] = Sd_Ip_LoadDword(Sd_Emmc_Ip_u32FunctionStatus, 4U * sizeof(uint32));
                break;

            case USDHC_ENDIAN_MODE_HALF_WORD_BIG:
                Sd_Emmc_Ip_u32FunctionStatus[0U] = Sd_Ip_LoadHword(Sd_Emmc_Ip_u32FunctionStatus, 0U);
                Sd_Emmc_Ip_u32FunctionStatus[1U] = Sd_Ip_LoadHword(Sd_Emmc_Ip_u32FunctionStatus, 1U * sizeof(uint32));
                Sd_Emmc_Ip_u32FunctionStatus[2U] = Sd_Ip_LoadHword(Sd_Emmc_Ip_u32FunctionStatus, 2U * sizeof(uint32));
                Sd_Emmc_Ip_u32FunctionStatus[3U] = Sd_Ip_LoadHword(Sd_Emmc_Ip_u32FunctionStatus, 3U * sizeof(uint32));
                Sd_Emmc_Ip_u32FunctionStatus[4U] = Sd_Ip_LoadHword(Sd_Emmc_Ip_u32FunctionStatus, 4U * sizeof(uint32));
                break;

            default:
                /* USDHC_ENDIAN_MODE_BIG */
                /* Doesn't need to switch byte sequence when decodes bytes as big endian sequence. */
                break;
        }

        FunctionGroupInfo[5U] = (uint16)(Sd_Emmc_Ip_u32FunctionStatus[0U]);
        FunctionGroupInfo[4U] = (uint16)(Sd_Emmc_Ip_u32FunctionStatus[1U] >> 16U);
        FunctionGroupInfo[3U] = (uint16)(Sd_Emmc_Ip_u32FunctionStatus[1U]);
        FunctionGroupInfo[2U] = (uint16)(Sd_Emmc_Ip_u32FunctionStatus[2U] >> 16U);
        FunctionGroupInfo[1U] = (uint16)(Sd_Emmc_Ip_u32FunctionStatus[2U]);
        FunctionGroupInfo[0U] = (uint16)(Sd_Emmc_Ip_u32FunctionStatus[3U] >> 16U);
        FunctionGroupStatus   = ((Sd_Emmc_Ip_u32FunctionStatus[3U] & 0xFFU) << 8U) | (Sd_Emmc_Ip_u32FunctionStatus[4U] >> 24U);

        /* check if function is supported. */
        Status = Sd_Ip_SwitchFunctionCheck((uint32)(FunctionGroupInfo[Group]), FunctionGroupStatus, Group, Function);
    }

    if ((Sd_Emmc_Ip_StatusType)SD_IP_STATUS_SUCCESS == Status)
    {
        /* Switch to high speed mode. */
        if ((Sd_Emmc_Ip_StatusType)SD_IP_STATUS_SUCCESS != Sd_Ip_SwitchFunction(Config, aSD_SwitchSet, Group, Function, Sd_Emmc_Ip_u32FunctionStatus))
        {
            Status = (Sd_Emmc_Ip_StatusType)SD_IP_STATUS_SWITCH_FAILED;
        }
        else
        {
            /* Switch function Status byte sequence from card is big endian(MSB first). */
            switch (Config->usdhcConfig->endianMode)
            {
                case USDHC_ENDIAN_MODE_LITTLE:
                    /* In little endian mode is little endian, SD bus byte transferred first is the byte stored in lowest byte
                    position in a word which will cause 4 byte's sequence in a word is not consistent with their original
                    sequence from card. So the sequence of 4 bytes received in a word should be converted.*/
                    Sd_Emmc_Ip_u32FunctionStatus[3U] = Sd_Ip_LoadDword(Sd_Emmc_Ip_u32FunctionStatus, 3U * sizeof(uint32));
                    Sd_Emmc_Ip_u32FunctionStatus[4U] = Sd_Ip_LoadDword(Sd_Emmc_Ip_u32FunctionStatus, 4U * sizeof(uint32));
                    break;

                case USDHC_ENDIAN_MODE_HALF_WORD_BIG:
                    Sd_Emmc_Ip_u32FunctionStatus[3U] = Sd_Ip_LoadHword(Sd_Emmc_Ip_u32FunctionStatus, 3U * sizeof(uint32));
                    Sd_Emmc_Ip_u32FunctionStatus[4U] = Sd_Ip_LoadHword(Sd_Emmc_Ip_u32FunctionStatus, 4U * sizeof(uint32));
                    break;

                default:
                    /* USDHC_ENDIAN_MODE_BIG */
                    /* Doesn't need to switch byte sequence when decodes bytes as big endian sequence. */
                    break;
            }

            /* If switch function group failed, function group will be returned. */
            FunctionGroupStatus = ((Sd_Emmc_Ip_u32FunctionStatus[3U] & 0xFFU) << 8U) | (Sd_Emmc_Ip_u32FunctionStatus[4U] >> 24U);
            Status = Sd_Ip_SwitchFunctionSet(FunctionGroupStatus, Group, Function);
        }
    }

    return Status;
}

/**
* @brief         Sd_Ip_SetDataBusWidth
* @details       Send SET_DATA_WIDTH command to set SD bus width.
*
* @param[in]     Config Card descriptor.
* @param[in]     Width Data bus width.
*
* @return        Status    
* @pre           The USDHC driver needs to be initialized.
*/
static Sd_Emmc_Ip_StatusType Sd_Ip_SetDataBusWidth(const Sd_Emmc_Ip_ConfigType *Config,
                                                   Sd_Ip_DataBusWidthType Width
                                                  )
{
    Sd_Emmc_Ip_StatusType Status = (Sd_Emmc_Ip_StatusType)SD_IP_STATUS_SUCCESS;

    /* Send application command */
    if ((Sd_Emmc_Ip_StatusType)SD_IP_STATUS_SUCCESS != Sd_Ip_SendApplicationCmd(Config))
    {
        Status = (Sd_Emmc_Ip_StatusType)SD_IP_STATUS_SEND_APPL_COMMAND_FAILED;
    }

    if ((Sd_Emmc_Ip_StatusType)SD_IP_STATUS_SUCCESS == Status)
    {
        /* Prepare command transfer */
        Sd_Emmc_Ip_TransferStorage.command.index        = (uint32)aSD_ApplicationSetBusWidth;
        Sd_Emmc_Ip_TransferStorage.command.type         = USDHC_COMMAND_TYPE_NORMAL;
        Sd_Emmc_Ip_TransferStorage.command.responseType = USDHC_RESPONSE_TYPE_R1;
        /* Prepare command argument */
        switch ((uint32)Width)
        {
            case (uint32)aSD_DataBusWidth1Bit:
                Sd_Emmc_Ip_TransferStorage.command.argument = 0U;
                break;

            case (uint32)aSD_DataBusWidth4Bit:
                Sd_Emmc_Ip_TransferStorage.command.argument = 2U;
                break;

            /* invalid width */
            default:
                Status = (Sd_Emmc_Ip_StatusType)SD_IP_STATUS_ERROR;
                break;
        }
    }

    if (Status == (Sd_Emmc_Ip_StatusType)SD_IP_STATUS_SUCCESS)
    {
        /* Store the command description */
        Sd_Emmc_Ip_TransferStorage.content.command = &Sd_Emmc_Ip_TransferStorage.command;
        Sd_Emmc_Ip_TransferStorage.content.data = NULL_PTR;
        /* Start transfer */
        if ( (STATUS_USDHC_IP_SUCCESS != uSDHC_Ip_Transfer(Config->usdhcConfig->instance, &Sd_Emmc_Ip_TransferStorage.content, (boolean)FALSE)) ||
             (0U != ((Sd_Emmc_Ip_TransferStorage.command.response[0U]) & (uint32)SD_IP_R1_ALL_ERROR_FLAGS))
           )
        {
            Status = (Sd_Emmc_Ip_StatusType)SD_IP_STATUS_TRANSFER_FAILED;
        }
    }

    return Status;
}

/**
* @brief         Sd_Ip_MmcDecodeExtCsd
* @details       Decode EXT_CSD routine.
*
* @param[in]     Config Card descriptor.
* @param[in]     width Data bus width.
*
* @return        Status    
* @pre           The USDHC driver needs to be initialized.
*/
static Sd_Emmc_Ip_StatusType Sd_Ip_MmcDecodeExtCsd(const uint32 *RegExtCsd)
{
    /* Get the EXT_CSD  atributes*/
    Sd_Emmc_Ip_MmcECsr.sectorCount         =        (RegExtCsd[MMC_EXT_CSD_INDEX_SEC_CNT          >> 2U] >> MMC_EXT_CSD_SEC_CNT_SHIFT);
    Sd_Emmc_Ip_MmcECsr.dataSectorSize      = (uint8)(RegExtCsd[MMC_EXT_CSD_INDEX_DATA_SECTOR_SIZE >> 2U] >> MMC_EXT_CSD_DATA_SECTOR_SIZE_SHIFT);
    Sd_Emmc_Ip_MmcECsr.dataBusWidth        = (uint8)(RegExtCsd[MMC_EXT_CSD_INDEX_BUS_WIDTH        >> 2U] >> MMC_EXT_CSD_BUS_WIDTH_SHIFT);
    Sd_Emmc_Ip_MmcECsr.extendecCsdVersion  = (uint8)(RegExtCsd[MMC_EXT_CSD_INDEX_REV              >> 2U] >> MMC_EXT_CSD_REV_SHIFT);
    Sd_Emmc_Ip_MmcECsr.csdStructureVersion = (uint8)(RegExtCsd[MMC_EXT_CSD_INDEX_STRUCTURE        >> 2U] >> MMC_EXT_CSD_STRUCTURE_SHIFT);
    Sd_Emmc_Ip_MmcECsr.cardType            = (uint8)(RegExtCsd[MMC_EXT_CSD_INDEX_CARD_TYPE        >> 2U] >> MMC_EXT_CSD_CARD_TYPE_SHIFT);
    Sd_Emmc_Ip_MmcECsr.strobeSupport       = (uint8)(RegExtCsd[MMC_EXT_CSD_STROBE_SUPPORT         >> 2U] >> MMC_EXT_CSD_STROBE_SUPPORT_SHIFT);
    Sd_Emmc_Ip_MmcECsr.highSpeedTiming     = (uint8)(RegExtCsd[MMC_EXT_CSD_INDEX_HS_TIMING        >> 2U] >> MMC_EXT_CSD_HS_TIMING_SHIFT);
    Sd_Emmc_Ip_MmcECsr.bootConfig          = (uint8)(RegExtCsd[MMC_EXT_CSD_INDEX_PARTITION_CONFIG    >> 2U] >> MMC_EXT_CSD_PARTITION_CONFIG_SHIFT);
    Sd_Emmc_Ip_MmcECsr.bootSizeMultiplier  = (uint8)(RegExtCsd[MMC_EXT_CSD_INDEX_BOOT_SIZE_MULT      >> 2U] >> MMC_EXT_CSD_BOOT_SIZE_MULT_SHIFT);
    Sd_Emmc_Ip_MmcECsr.bootInformation     = (uint8)(RegExtCsd[MMC_EXT_CSD_INDEX_BOOT_INFO           >> 2U] >> MMC_EXT_CSD_BOOT_INFO_SHIFT);
    Sd_Emmc_Ip_MmcECsr.bootBusCondition    = (uint8)(RegExtCsd[MMC_EXT_CSD_INDEX_BOOT_BUS_CONDITIONS >> 2U] >> MMC_EXT_CSD_BOOT_BUS_CONDITIONS_SHIFT);

    /* Set block count */
    Sd_Emmc_Ip_u32BlockCountInfo = Sd_Emmc_Ip_MmcECsr.sectorCount;

    switch (Sd_Emmc_Ip_MmcECsr.dataSectorSize)
    {
        case 0U:
            /* If Sd_Emmc_Ip_MmcECsr.dataSectorSize = 0 then BlockSize is 512 */
            Sd_Emmc_Ip_u32BlockSizeInfo = SD_IP_SDMMC_DEFAULT_BLOCK_SIZE;
            break;

        case 1U:
            /* If Sd_Emmc_Ip_MmcECsr.dataSectorSize = 1 then BlockSize is 4096 */
            Sd_Emmc_Ip_u32BlockSizeInfo = 4096U;
            break;

        default:
            /* other data sector size */
            break;
    }

    return (Sd_Emmc_Ip_StatusType)SD_IP_STATUS_SUCCESS;
}

/**
* @brief         Sd_Ip_MmcGetCapabilities
* @details       Collect card capabilities
*
* @param[in]     void
*
* @return        void    
* @pre           The USDHC driver needs to be initialized.
*/
static void Sd_Ip_MmcGetCapabilities(void)
{
    uint32 CardType;
    uint32 StrobeSupport;

    /* Get the EXT_CSD  atributes*/
    CardType      = (uint32)(Sd_Emmc_Ip_MmcECsr.cardType) & MMC_EXT_CSD_CARD_TYPE_MASK;
    StrobeSupport = (uint32)(Sd_Emmc_Ip_MmcECsr.strobeSupport);

    /* Get the information about what features are supported by the current card */
    if (0U != (CardType & ((uint32)SD_IP_MMC_CARD_TYPE_HS400_1_8V | (uint32)SD_IP_MMC_CARD_TYPE_HS400_1_2V)))
    {
        mmcCapability.supportHS400 = (boolean)TRUE;
    }
    if (0U != (CardType & ((uint32)SD_IP_MMC_CARD_TYPE_HS200_1_8V | (uint32)SD_IP_MMC_CARD_TYPE_HS200_1_2V)))
    {
        mmcCapability.supportHS200 = (boolean)TRUE;
    }
    if (0U != (CardType & ((uint32)SD_IP_MMC_CARD_TYPE_HS_52_DDR_1_8V | (uint32)SD_IP_MMC_CARD_TYPE_HS_52_DDR_1_2V)))
    {
        mmcCapability.supportHS52DDR = (boolean)TRUE;
    }
    if (0U != (CardType & ((uint32)SD_IP_MMC_CARD_TYPE_HS_52 | (uint32)SD_IP_MMC_CARD_TYPE_HS_26)))
    {
        mmcCapability.supportHSLegacy = (boolean)TRUE;
    }
    if (StrobeSupport == 1U)
    {
        mmcCapability.supportEnhanceStrobe = (boolean)TRUE;
    }
}

/**
* @brief         Sd_Ip_GetValueFromRange
* @details       Get CSD register value by length
*
* @param[in]     Array Array address to read
* @param[in]     Start Data bus width.
* @param[in]     Len   Data length
*
* @return        Result    
* @pre           The USDHC driver needs to be initialized.
*/
static uint8 Sd_Ip_GetValueFromRange(const uint32 *Array, uint8 Start, uint8 Len)
{
    uint8 Result         = 0U;
    const uint32* Buffer = Array;
    uint8 Cnt            = Start / 32U;
    uint8 Mask           = (uint8)((1U << Len) - 1U);
    uint8 Temp;

    Temp = (uint8)(Buffer[Cnt] >> (Start % 32U)) & Mask;

    /* If the start and and bit is in the same word */
    if ((Start + Len) <= (uint8)(32U * (Cnt + 1U)))
    {
        Result = Temp;
    }
    /* If the start and and bit is in the different word */
    else
    {
        Result = (Temp | (uint8)Buffer[Cnt + 1U]) & Mask;
    }

    return Result;
}

/**
* @brief         Sd_Ip_MmcDecodeCsd
* @details       Decode raw CSD register content in the data blocks.
*
* @param[in]     Config Card descriptor.
* @param[in]     RegCsd Raw CSD register content.
*
* @return        Status    
* @pre           The USDHC driver needs to be initialized.
*/
static Sd_Emmc_Ip_StatusType Sd_Ip_MmcDecodeCsd(const uint32 *RegCsd)
{
    Sd_Emmc_Ip_StatusType Status = (Sd_Emmc_Ip_StatusType)SD_IP_STATUS_SUCCESS;

    /* Get the atributes in CSD register */
    Sd_Emmc_Ip_MmcCsd.csdStructureVersion        = Sd_Ip_GetValueFromRange(RegCsd, 126U, 2U);
    Sd_Emmc_Ip_MmcCsd.systemSpecificationVersion = Sd_Ip_GetValueFromRange(RegCsd, 122U, 4U);
    Sd_Emmc_Ip_MmcCsd.dataReadAccessTime1        = Sd_Ip_GetValueFromRange(RegCsd, 112U, 8U);
    Sd_Emmc_Ip_MmcCsd.dataReadAccessTime2        = Sd_Ip_GetValueFromRange(RegCsd, 104U, 8U);
    Sd_Emmc_Ip_MmcCsd.transferSpeed              = Sd_Ip_GetValueFromRange(RegCsd,  96U, 8U);
    Sd_Emmc_Ip_MmcCsd.cardCommandClass           = (uint16)((RegCsd[2U] >> 20U) & 0xFFFU);
    Sd_Emmc_Ip_MmcCsd.readBlockLength            = Sd_Ip_GetValueFromRange(RegCsd,  80U, 4U);
    Sd_Emmc_Ip_MmcCsd.deviceSize                 = (uint16)((RegCsd[2U] & 0x3FFU) << 2U);
    Sd_Emmc_Ip_MmcCsd.deviceSize                |= (uint16)((RegCsd[1U] >> 30U) & 0x3U);

    /* Get current information */
    Sd_Emmc_Ip_MmcCsd.readCurrentVddMin        = Sd_Ip_GetValueFromRange(RegCsd, 59U, 3U);
    Sd_Emmc_Ip_MmcCsd.readCurrentVddMax        = Sd_Ip_GetValueFromRange(RegCsd, 56U, 3U);
    Sd_Emmc_Ip_MmcCsd.writeCurrentVddMin       = Sd_Ip_GetValueFromRange(RegCsd, 53U, 3U);
    Sd_Emmc_Ip_MmcCsd.writeCurrentVddMax       = Sd_Ip_GetValueFromRange(RegCsd, 50U, 3U);
    Sd_Emmc_Ip_MmcCsd.deviceSizeMultiplier     = Sd_Ip_GetValueFromRange(RegCsd, 47U, 3U);
    Sd_Emmc_Ip_MmcCsd.eraseGroupSize           = Sd_Ip_GetValueFromRange(RegCsd, 42U, 5U);
    Sd_Emmc_Ip_MmcCsd.eraseGroupSizeMultiplier = Sd_Ip_GetValueFromRange(RegCsd, 47U, 5U);
    Sd_Emmc_Ip_MmcCsd.maxWriteBlockLength      = Sd_Ip_GetValueFromRange(RegCsd, 22U, 4U);
    Sd_Emmc_Ip_MmcCsd.fileFormat               = Sd_Ip_GetValueFromRange(RegCsd, 10U, 2U);

    /* Get card total block count and block size. */
    Sd_Emmc_Ip_u32VersionInfo = (uint32)Sd_Emmc_Ip_MmcCsd.systemSpecificationVersion;
    if (4U > Sd_Emmc_Ip_u32VersionInfo)
    {
        /* Update Block count and block size */
        Sd_Emmc_Ip_u32BlockCountInfo = ((uint32)Sd_Emmc_Ip_MmcCsd.deviceSize + 1UL) << ((uint32)Sd_Emmc_Ip_MmcCsd.deviceSizeMultiplier + 2UL);
        Sd_Emmc_Ip_u32BlockSizeInfo  = ((uint32)1U << Sd_Emmc_Ip_MmcCsd.readBlockLength);

        if (SD_IP_SDMMC_DEFAULT_BLOCK_SIZE != Sd_Emmc_Ip_u32BlockSizeInfo)
        {
            /* Re-calculate block count and block size */
            Sd_Emmc_Ip_u32BlockCountInfo = (Sd_Emmc_Ip_u32BlockCountInfo * Sd_Emmc_Ip_u32BlockSizeInfo);
            Sd_Emmc_Ip_u32BlockSizeInfo  =  SD_IP_SDMMC_DEFAULT_BLOCK_SIZE;
            Sd_Emmc_Ip_u32BlockCountInfo = (Sd_Emmc_Ip_u32BlockCountInfo / Sd_Emmc_Ip_u32BlockSizeInfo);
        }
    }

    return Status;
}

/**
* @brief         Sd_Ip_SetCsdFlag
* @details       Write CSD register content to CSD Flags
*
* @param[in]     pointer to CSD array
*
* @return        Status    
* @pre           The USDHC driver needs to be initialized.
*/
static void Sd_Ip_SetCsdFlag(const uint32 *RegCsd)
{
    /* check if SD card supports READ_BLOCK_PARTIAL */
    if (0U != (RegCsd[2U] & 0x8000U))
    {
        Sd_Emmc_Ip_Csd.flags |= (uint16)SD_IP_CSD_READ_BLOCK_PARTIAL_FLAG;
    }
    /* check if SD card supports WRITE_BLOCK_MISALIGN */
    if (0U != (RegCsd[2U] & 0x4000U))
    {
        Sd_Emmc_Ip_Csd.flags |= (uint16)SD_IP_CSD_WRITE_BLOCK_MISALIGN_FLAG;
    }
    /* check if SD card supports READ_BLOCK_MISALIGN */
    if (0U != (RegCsd[2U] & 0x2000U))
    {
        Sd_Emmc_Ip_Csd.flags |= (uint16)SD_IP_CSD_READ_BLOCK_MISALIGN_FLAG;
    }
    /* check if SD card supports DSR_IMPLEMENTATION */
    if (0U != (RegCsd[2U] & 0x1000U))
    {
        Sd_Emmc_Ip_Csd.flags |= (uint16)SD_IP_CSD_DSR_IMPLEMENTATION_FLAG;
    }

    /* check if SD card supports ERASE_BLOCK_ENABLED */
    if (0U != ((uint8)((RegCsd[1U] & 0x4000U) >> 14U)))
    {
        Sd_Emmc_Ip_Csd.flags |= (uint16)SD_IP_CSD_ERASE_BLOCK_ENABLED_FLAG;
    }

    /* Split function to avoid HIS_CCM */
    Sd_Ip_SetCsd0Flag(RegCsd);
}

static inline void Sd_Ip_SetCsd0Flag(const uint32 *RegCsd)
{
    /* check if SD card supports WRITE_PROTECT_GROUP_ENABLED */
    if (0U != ((uint8)(RegCsd[0U] & 0x80000000U)))
    {
        Sd_Emmc_Ip_Csd.flags |= (uint16)SD_IP_CSD_WRITE_PROTECT_GROUP_ENABLED_FLAG;
    }
    /* check if SD card supports WRITE_BLOCK_PARTIAL */
    if (0U != ((uint8)((RegCsd[0U] & 0x200000U) >> 21U)))
    {
        Sd_Emmc_Ip_Csd.flags |= (uint16)SD_IP_CSD_WRITE_BLOCK_PARTIAL_FLAG;
    }
    /* check if SD card supports FILE_FORMAT_GROUP */
    if (0U != ((uint8)((RegCsd[0U] & 0x8000U) >> 15U)))
    {
        Sd_Emmc_Ip_Csd.flags |= (uint16)SD_IP_CSD_FILE_FORMAT_GROUP_FLAG;
    }
    /* check if SD card supports CSD_COPY */
    if (0U != ((uint8)((RegCsd[0U] & 0x4000U) >> 14U)))
    {
        Sd_Emmc_Ip_Csd.flags |= (uint16)SD_IP_CSD_COPY_FLAG;
    }
    /* check if SD card supports PERMANENT_WRITE_PROTECT */
    if (0U != ((uint8)((RegCsd[0U] & 0x2000U) >> 13U)))
    {
        Sd_Emmc_Ip_Csd.flags |= (uint16)SD_IP_CSD_PERMANENT_WRITE_PROTECT_FLAG;
    }
    /* check if SD card supports TEMPORARY_WRITE_PROTECT */
    if (0U != ((uint8)((RegCsd[0U] & 0x1000U) >> 12U)))
    {
        Sd_Emmc_Ip_Csd.flags |= (uint16)SD_IP_CSD_TEMPORARY_WRITE_PROTECT_FLAG;
    }
}

/**
* @brief         Sd_Ip_DecodeCsd
* @details       Decode raw CSD register content in the data blocks.
*
* @param[in]     Config Card descriptor.
* @param[in]     RegCsd Raw CSD register content.
*
* @return        Status    
* @pre           The USDHC driver needs to be initialized.
*/
static Sd_Emmc_Ip_StatusType Sd_Ip_DecodeCsd(const uint32 *RegCsd)
{
    Sd_Emmc_Ip_StatusType Status = (Sd_Emmc_Ip_StatusType)SD_IP_STATUS_SUCCESS;

    /* Get the csdStructure */
    Sd_Emmc_Ip_Csd.csdStructure        = (uint8)((RegCsd[3U] & 0xC0000000U) >> 30U);
    /* Get the dataReadAccessTime */
    Sd_Emmc_Ip_Csd.dataReadAccessTime1 = (uint8)((RegCsd[3U] & 0x00FF0000U) >> 16U);
    Sd_Emmc_Ip_Csd.dataReadAccessTime2 = (uint8)((RegCsd[3U] & 0x0000FF00U) >> 8U);
    /* Get the transferSpeed */
    Sd_Emmc_Ip_Csd.transferSpeed       = (uint8)(RegCsd[3U]  & 0xFFU);
    /* Get the cardCommandClass */
    Sd_Emmc_Ip_Csd.cardCommandClass    = (uint16)((RegCsd[2U] & 0xFFF00000U) >> 20U);
    /* Get the readBlockLength */
    Sd_Emmc_Ip_Csd.readBlockLength     = (uint8)((RegCsd[2U]  & 0xF0000U) >> 16U);

    switch (Sd_Emmc_Ip_Csd.csdStructure)
    {
        case 0:
            /* Get the deviceSize */
            Sd_Emmc_Ip_Csd.deviceSize           = (uint32)((RegCsd[2U] & 0x3FFU) << 2U);
            Sd_Emmc_Ip_Csd.deviceSize          |= (uint32)((RegCsd[1U] & 0xC0000000U) >> 30U);
            /* Get the readCurrent */
            Sd_Emmc_Ip_Csd.readCurrentVddMin    = (uint8)((RegCsd[1U] & 0x38000000U) >> 27U);
            Sd_Emmc_Ip_Csd.readCurrentVddMax    = (uint8)((RegCsd[1U] & 0x7000000U) >> 24U);
            /* Get the writeCurrent */
            Sd_Emmc_Ip_Csd.writeCurrentVddMin   = (uint8)((RegCsd[1U] & 0xE00000U) >> 20U);
            Sd_Emmc_Ip_Csd.writeCurrentVddMax   = (uint8)((RegCsd[1U] & 0x1C0000U) >> 18U);
            /* Get the deviceSizeMultiplier */
            Sd_Emmc_Ip_Csd.deviceSizeMultiplier = (uint8)((RegCsd[1U] & 0x38000U) >> 15U);

            /* Get card total block count and block size. */
            Sd_Emmc_Ip_u32BlockCountInfo        = ((Sd_Emmc_Ip_Csd.deviceSize + 1U) << (Sd_Emmc_Ip_Csd.deviceSizeMultiplier + 2U));
            Sd_Emmc_Ip_u32BlockSizeInfo         = ((uint32)1U << Sd_Emmc_Ip_Csd.readBlockLength);
            if (SD_IP_SDMMC_DEFAULT_BLOCK_SIZE != Sd_Emmc_Ip_u32BlockSizeInfo)
            {
                Sd_Emmc_Ip_u32BlockCountInfo    = (Sd_Emmc_Ip_u32BlockCountInfo * Sd_Emmc_Ip_u32BlockSizeInfo);
                Sd_Emmc_Ip_u32BlockSizeInfo     = SD_IP_SDMMC_DEFAULT_BLOCK_SIZE;
                Sd_Emmc_Ip_u32BlockCountInfo    = (Sd_Emmc_Ip_u32BlockCountInfo / Sd_Emmc_Ip_u32BlockSizeInfo);
            }
            break;

        case 1:
            /* Set the BlockSize */
            Sd_Emmc_Ip_u32BlockSizeInfo = SD_IP_SDMMC_DEFAULT_BLOCK_SIZE;
            /* Get the deviceSize */
            Sd_Emmc_Ip_Csd.deviceSize   = (uint32)((RegCsd[2U] & 0x3FU) << 16U);
            Sd_Emmc_Ip_Csd.deviceSize  |= (uint32)((RegCsd[1U] & 0xFFFF0000U) >> 16U);
            if (Sd_Emmc_Ip_Csd.deviceSize >= 0xFFFFU)
            {
                Sd_Emmc_Ip_u32CardFlags |= (uint16)SD_IP_SUPPORT_SDXC_FLAG;
            }
            Sd_Emmc_Ip_u32BlockCountInfo = ((Sd_Emmc_Ip_Csd.deviceSize + 1U) * 1024U);
            break;

        /* Card is not supported */
        default:
            Status = (Sd_Emmc_Ip_StatusType)SD_IP_STATUS_CARD_NOT_SUPPORTED;
            break;
    }

    if((Sd_Emmc_Ip_StatusType)SD_IP_STATUS_SUCCESS == Status)
    {
        /* Get the eraseSectorSize */
        Sd_Emmc_Ip_Csd.eraseSectorSize       = ((uint8)(RegCsd[1U] >> 7U) & 0x7FU);
        /* Get the writeProtectGroupSize */
        Sd_Emmc_Ip_Csd.writeProtectGroupSize = (uint8)(RegCsd[1U] & 0x7FU);
        /* Get the writeSpeedFactor */
        Sd_Emmc_Ip_Csd.writeSpeedFactor      = (uint8)((RegCsd[0U] & 0x1C000000U) >> 26U);
        /* Get the writeBlockLength */
        Sd_Emmc_Ip_Csd.writeBlockLength      = (uint8)((RegCsd[0U] & 0x3C00000U) >> 22U);
        /* Get the fileFormat */
        Sd_Emmc_Ip_Csd.fileFormat            = (uint8)((RegCsd[0U] & 0xC00U) >> 10U);
        Sd_Ip_SetCsdFlag(RegCsd);
    }

    return Status;
}

/**
* @brief         Sd_Ip_SendCsd
* @details       Send SEND_CSD command to get CSD register content from Card.
*
* @param[in]     Config Card descriptor.
*
* @return        Status    
* @pre           The USDHC driver needs to be initialized.
*/
static Sd_Emmc_Ip_StatusType Sd_Ip_SendCsd(const Sd_Emmc_Ip_ConfigType *Config)
{
    Sd_Emmc_Ip_StatusType Status = (Sd_Emmc_Ip_StatusType)SD_IP_STATUS_SUCCESS;
    /* Prepare the command transfer description */
    Sd_Emmc_Ip_TransferStorage.command.index        = (uint32)aSDMMC_SendCsd;
    Sd_Emmc_Ip_TransferStorage.command.argument     = (Sd_Emmc_Ip_u32RelativeAddress << 16U);
    Sd_Emmc_Ip_TransferStorage.command.type         = USDHC_COMMAND_TYPE_NORMAL;
    Sd_Emmc_Ip_TransferStorage.command.responseType = USDHC_RESPONSE_TYPE_R2;

    Sd_Emmc_Ip_TransferStorage.content.command      = &Sd_Emmc_Ip_TransferStorage.command;
    Sd_Emmc_Ip_TransferStorage.content.data         = NULL_PTR;

    /* Start transfer */
    if (STATUS_USDHC_IP_SUCCESS == uSDHC_Ip_Transfer(Config->usdhcConfig->instance, &Sd_Emmc_Ip_TransferStorage.content, (boolean)FALSE))
    {
        /* The response is from bit 127:8 in R2, corresponding to Sd_Emmc_Ip_TransferStorage.command.response[3U]:Sd_Emmc_Ip_TransferStorage.command.response[0U][31U:8]. */
        switch (Sd_Emmc_Ip_eCardTypeInfo)
        {
            /* Decode Csd */
            case SD_IP_MEMORY_CARD_SD:
                Status = Sd_Ip_DecodeCsd(Sd_Emmc_Ip_TransferStorage.command.response);
                break;

            case SD_IP_MEMORY_CARD_MMC:
                Status = Sd_Ip_MmcDecodeCsd(Sd_Emmc_Ip_TransferStorage.command.response);
                break;

            default:
                Status = (Sd_Emmc_Ip_StatusType)SD_IP_STATUS_CARD_NOT_SUPPORTED;
                break;
        }
    }
    else
    {
        /* The errors occurred */
        Status = (Sd_Emmc_Ip_StatusType)SD_IP_STATUS_TRANSFER_FAILED;
    }

    return Status;
}

/**
* @brief         Sd_Ip_DecodeCid
* @details       Decode raw CID register content in the data blocks.
*
* @param[in]     RegCid raw CID register content.
*
* @return        void    
* @pre           The USDHC driver needs to be initialized.
*/
static void Sd_Ip_DecodeCid(const uint32 *RegCid)
{
    /* Get the manufacturerID */
    Sd_Emmc_Ip_Cid.manufacturerID       = (uint8)((RegCid[3U] & 0xFF000000U) >> 24U);
    /* Get the applicationID */
    Sd_Emmc_Ip_Cid.applicationID        = (uint16)((RegCid[3U] & 0xFFFF00U) >> 8U);
    /* Get the productName */
    Sd_Emmc_Ip_Cid.productName[0U]      = (uint8)((RegCid[3U] & 0xFFU));
    Sd_Emmc_Ip_Cid.productName[1U]      = (uint8)((RegCid[2U] & 0xFF000000U) >> 24U);
    Sd_Emmc_Ip_Cid.productName[2U]      = (uint8)((RegCid[2U] & 0xFF0000U) >> 16U);
    Sd_Emmc_Ip_Cid.productName[3U]      = (uint8)((RegCid[2U] & 0xFF00U) >> 8U);
    Sd_Emmc_Ip_Cid.productName[4U]      = (uint8)((RegCid[2U] & 0xFFU));
    /* Get the productVersion */
    Sd_Emmc_Ip_Cid.productVersion       = (uint8)((RegCid[1U] & 0xFF000000U) >> 24U);
    /* Get the productSerialNumber */
    Sd_Emmc_Ip_Cid.productSerialNumber  = (uint32)((RegCid[1U] & 0xFFFFFFU) << 8U);
    Sd_Emmc_Ip_Cid.productSerialNumber |= (uint32)((RegCid[0U] & 0xFF000000U) >> 24U);
    /* Get the manufacturerData */
    Sd_Emmc_Ip_Cid.manufacturerData     = (uint16)((RegCid[0U] & 0xFFF00U) >> 8U);
}

/**
* @brief         Sd_Ip_MmcDecodeCid
* @details       Decode MMC raw CID register content in the data blocks
*
* @param[in]     RegCid raw CID register content.
*
* @return        void    
* @pre           The USDHC driver needs to be initialized.
*/
static void Sd_Ip_MmcDecodeCid(const uint32 *RegCid)
{
    /* Get the manufacturerID */
    Sd_Emmc_Ip_MmcCid.manufacturerID       = (uint8)((RegCid[3U] & 0xFF000000U) >> 24U);
    /* Get the applicationID */
    Sd_Emmc_Ip_MmcCid.applicationID        = (uint16)((RegCid[3U] & 0xFF00U) >> 8U);
    /* Get the productName */
    Sd_Emmc_Ip_MmcCid.productName[0U]      = (uint8)((RegCid[3U] & 0xFFU));
    Sd_Emmc_Ip_MmcCid.productName[1U]      = (uint8)((RegCid[2U] & 0xFF000000U) >> 24U);
    Sd_Emmc_Ip_MmcCid.productName[2U]      = (uint8)((RegCid[2U] & 0xFF0000U) >> 16U);
    Sd_Emmc_Ip_MmcCid.productName[3U]      = (uint8)((RegCid[2U] & 0xFF00U) >> 8U);
    Sd_Emmc_Ip_MmcCid.productName[4U]      = (uint8)((RegCid[2U] & 0xFFU));
    Sd_Emmc_Ip_MmcCid.productName[5U]      = (uint8)((RegCid[1U] & 0xFF000000U));
    /* Get the productVersion */
    Sd_Emmc_Ip_MmcCid.productVersion       = (uint8)((RegCid[1U] & 0xFF0000U) >> 16U);
    /* Get the productSerialNumber */
    Sd_Emmc_Ip_MmcCid.productSerialNumber  = (uint32)((RegCid[1U] & 0xFFFFU) << 16U);
    Sd_Emmc_Ip_MmcCid.productSerialNumber |= (uint32)((RegCid[0U] & 0xFFFF0000U) >> 16U);
    /* Get the manufacturerData */
    Sd_Emmc_Ip_MmcCid.manufacturerData     = (uint8)((RegCid[0U] & 0xFF00U) >> 8U);
}

/**
* @brief         Sd_Ip_AllSendCid
* @details       Send GET_CID command to get CID from card.
*
* @param[in]     Config Card descriptor.
*
* @return        Status    
* @pre           The USDHC driver needs to be initialized.
*/
static Sd_Emmc_Ip_StatusType Sd_Ip_AllSendCid(const Sd_Emmc_Ip_ConfigType *Config)
{
    Sd_Emmc_Ip_StatusType Status = (Sd_Emmc_Ip_StatusType)SD_IP_STATUS_SUCCESS;
    /* Prepare the command transfer description */
    Sd_Emmc_Ip_TransferStorage.command.index        = (uint32)aSDMMC_AllSendCid;
    Sd_Emmc_Ip_TransferStorage.command.argument     = 0U;
    Sd_Emmc_Ip_TransferStorage.command.type         = USDHC_COMMAND_TYPE_NORMAL;
    Sd_Emmc_Ip_TransferStorage.command.responseType = USDHC_RESPONSE_TYPE_R2;

    Sd_Emmc_Ip_TransferStorage.content.command      = &Sd_Emmc_Ip_TransferStorage.command;
    Sd_Emmc_Ip_TransferStorage.content.data         = NULL_PTR;

    /* Start transfer */
    if (STATUS_USDHC_IP_SUCCESS == uSDHC_Ip_Transfer(Config->usdhcConfig->instance, &Sd_Emmc_Ip_TransferStorage.content, (boolean)FALSE))
    {
        switch (Sd_Emmc_Ip_eCardTypeInfo)
        {
            /* If card is SD */
            case SD_IP_MEMORY_CARD_SD:
                (void)Sd_Ip_DecodeCid(Sd_Emmc_Ip_TransferStorage.command.response);
                break;

            /* If card is MMC */
            case SD_IP_MEMORY_CARD_MMC:
                (void)Sd_Ip_MmcDecodeCid(Sd_Emmc_Ip_TransferStorage.command.response);
                break;

            /* Card is not supported */
            default:
                Status = (Sd_Emmc_Ip_StatusType)SD_IP_STATUS_CARD_NOT_SUPPORTED;
                break;
        }
    }
    else
    {
        Status = (Sd_Emmc_Ip_StatusType)SD_IP_STATUS_TRANSFER_FAILED;
    }

    return Status;
}

/**
* @brief         Sd_Ip_ApplicationSendOperationCondition
* @details       Sends host capacity support information and asks the accessed card to send its operating condition register content.
*
* @param[in]     Config Card descriptor.
* @param[in]     Argument      The argument of the send operation condition ncomamnd.
*
* @return        Status    
* @pre           The USDHC driver needs to be initialized.
*/
static Sd_Emmc_Ip_StatusType Sd_Ip_ApplicationSendOperationCondition(const Sd_Emmc_Ip_ConfigType *Config, uint32 Argument)
{
    Sd_Emmc_Ip_StatusType Status    = (Sd_Emmc_Ip_StatusType)SD_IP_STATUS_SUCCESS;
    uint32 RetryNo                  = SD_IP_SDMMC_MAX_VOLTAGE_RETRIES;
    uint8 SendOperationCondRetries  = SD_IP_MAX_RETRIES;
    uint32 Capabilities;

    while (RetryNo > 0U)
    {
        RetryNo--;

        do
        {
            /* Try to send application command */
            Status = Sd_Ip_SendApplicationCmd(Config);
            SendOperationCondRetries--;
        }
        while (((Sd_Emmc_Ip_StatusType)SD_IP_STATUS_SUCCESS != Status) && (SendOperationCondRetries > 0U));
        /* Prepare the command transfer description */
        Sd_Emmc_Ip_TransferStorage.command.index        = (uint32)aSD_ApplicationSendOperationCondition;
        Sd_Emmc_Ip_TransferStorage.command.type         = USDHC_COMMAND_TYPE_NORMAL;
        Sd_Emmc_Ip_TransferStorage.command.responseType = USDHC_RESPONSE_TYPE_R3;

        if ((Sd_Emmc_Ip_StatusType)SD_IP_STATUS_SUCCESS != Status)
        {
            Status = (Sd_Emmc_Ip_StatusType)SD_IP_STATUS_SEND_APPL_COMMAND_FAILED;
        }
        else
        {
            /*
             * Vdd window bits[08:23] should be completed otherwise
             * the ACMD41 command is considered as "inquiry" and
             * can't be used for initialization purpose.
             */
            Capabilities = (Argument & ((uint32)aSD_OcrSwitch18RequestFlag | (uint32)aSD_OcrVdd32_33Flag | (uint32)aSD_OcrVdd33_34Flag | (uint32)aSD_OcrHostCapacitySupportFlag));

            /* Update the command argument */
            Sd_Emmc_Ip_TransferStorage.command.argument = Capabilities;

            Sd_Emmc_Ip_TransferStorage.content.command = &Sd_Emmc_Ip_TransferStorage.command;
            Sd_Emmc_Ip_TransferStorage.content.data    = NULL_PTR;

            /* Transfer the command */
            if (STATUS_USDHC_IP_SUCCESS != uSDHC_Ip_Transfer(Config->usdhcConfig->instance, &Sd_Emmc_Ip_TransferStorage.content, (boolean)FALSE))
            {
                Status = (Sd_Emmc_Ip_StatusType)SD_IP_STATUS_TRANSFER_FAILED;
                /* Transfer failed: Terminate the loop */
                RetryNo = 0U;
            }
            else
            {
                /* Analyze the response */
                Status = Sd_Ip_AnalyzeOperationConditionSD(Sd_Emmc_Ip_TransferStorage.command.response[0U]);
                if ((Sd_Emmc_Ip_StatusType)SD_IP_STATUS_SUCCESS == Status)
                {
                    /* Analyze succeeded: Terminate the loop */
                    RetryNo = 0U;
                }
            }
        }
    }

    return Status;
}

/**
* @brief         Sd_Ip_FindBusClock
* @details       Set bus clock for USDHC from configured SD clock
*
* @param[in]     Config Card descriptor.
* @param[in]     argument      The argument of the send operation condition ncomamnd.
*
* @return        DummyReturn    
* @pre           The USDHC driver needs to be initialized.
*/
static uint32 Sd_Ip_FindBusClock(const Sd_Emmc_Ip_ConfigType *Config)
{
    uint32 DummyReturn;
    uint32 NextFrequency = Config->SdConfigClock;
#if (SD_IP_AUTO_DISCOVER_FREQUENCY == STD_ON)
    Sd_Emmc_Ip_StatusType Status = (Sd_Emmc_Ip_StatusType)SD_IP_STATUS_SUCCESS;
    /* Try to find bus clock */
    do
    {
#endif
        /* Set the bus clock */
        (void)uSDHC_Ip_SetBusClock(Config->usdhcConfig->instance, Config->u32McuClock, NextFrequency, &DummyReturn);
#if (SD_IP_AUTO_DISCOVER_FREQUENCY == STD_ON)
        /* Try Setting the block size */
        Status = Sd_Ip_SetBlockSize(Config, 64U);
        if ((Sd_Emmc_Ip_StatusType)SD_IP_STATUS_SUCCESS != Status)
        {
            NextFrequency >>= 1U;
        }
    }
    while ((Sd_Emmc_Ip_StatusType)SD_IP_STATUS_SUCCESS != Status);
#endif

    return DummyReturn;
}

/**
* @brief         Sd_Ip_SendInterfaceCondition
* @details       Send GET_INTERFACE_CONDITION command to get card interface condition.
*
* @param[in]     Config Card descriptor.
* @param[in]     argument      The argument of the send operation condition ncomamnd.
*
* @return        Status    
* @pre           The USDHC driver needs to be initialized.
*/
static Sd_Emmc_Ip_StatusType Sd_Ip_SendInterfaceCondition(const Sd_Emmc_Ip_ConfigType *Config)
{
    Sd_Emmc_Ip_StatusType Status = SD_IP_STATUS_ERROR;
    Sd_Ip_ProtocolType LocalCardType;
    uint32 StartTime;
    uint32 CurrentTime;

    /* Prepare the transfer description */
    Sd_Emmc_Ip_TransferStorage.command.index        = (uint32)aMMC_SendOperationCondition;
    Sd_Emmc_Ip_TransferStorage.command.type         = USDHC_COMMAND_TYPE_NORMAL;
    Sd_Emmc_Ip_TransferStorage.command.argument     = 0x0;
    Sd_Emmc_Ip_TransferStorage.command.responseType = USDHC_RESPONSE_TYPE_R3;
    /* Store the transfer description */
    Sd_Emmc_Ip_TransferStorage.content.command      = &Sd_Emmc_Ip_TransferStorage.command;
    Sd_Emmc_Ip_TransferStorage.content.data         = NULL_PTR;

    LocalCardType = SD_IP_MEMORY_CARD_MMC;
    /* Get start time */
    StartTime = OsIf_GetCounter(USDHC_IP_TIMEOUT_TYPE);
    CurrentTime = 0U;
    for (;;)
    {
        CurrentTime += OsIf_GetElapsed(&StartTime, USDHC_IP_TIMEOUT_TYPE);
        if (CurrentTime >= USDHC_IP_GET_INTERFACE_CONDITION_TIMEOUT)
        {
            /* Timeout errors */
            Usdhc_Ip_bFailedTimeout = (boolean)TRUE;
            Status = (Sd_Emmc_Ip_StatusType)SD_IP_STATUS_TIMEOUT;
        }
        else
        {
            /* Start transfer */
            if (STATUS_USDHC_IP_SUCCESS == uSDHC_Ip_Transfer(Config->usdhcConfig->instance, &Sd_Emmc_Ip_TransferStorage.content, (boolean)FALSE))
            {
                /* Set the command argument */
                Sd_Emmc_Ip_TransferStorage.command.argument = ((Sd_Emmc_Ip_TransferStorage.command.response[0]) | MMC_OCR_SECTOR_ACCESS_MODE_MASK);
                if (0U == (Sd_Emmc_Ip_TransferStorage.command.response[0] & MMC_OCR_BUSY_MASK))  /* bit 31 is not set (busy) */
                {
                    /* Card is still busy, loop until OCR[31] = 1 */
                    /* MMC Specs - Access mode validation: The host shall ignore the access mode bits if the device is busy */
                    continue;
                }

                /* Analyze the response (OCR register) */
                Sd_Ip_AnalyzeOperationConditionMMC(Sd_Emmc_Ip_TransferStorage.command.response[0]);
                /* Found eMMC card */
                Status = SD_IP_STATUS_SUCCESS;
            }
        }
        break;
    }

    if ((Sd_Emmc_Ip_StatusType)SD_IP_STATUS_SUCCESS != Status)
    {
        /* Software reset for all */
        (void)uSDHC_Ip_Reset(Config->usdhcConfig->instance, USDHC_SYS_CTRL_RSTA_MASK, USDHC_IP_RESET_TIMEOUT);
        /* Prepare the command transfer */
        Sd_Emmc_Ip_TransferStorage.command.index        = (uint32)aSD_SendInterfaceCondition;
        Sd_Emmc_Ip_TransferStorage.command.argument     = 0x1AAU;
        Sd_Emmc_Ip_TransferStorage.command.responseType = USDHC_RESPONSE_TYPE_R7;

        Sd_Emmc_Ip_TransferStorage.content.command      = &Sd_Emmc_Ip_TransferStorage.command;
        Sd_Emmc_Ip_TransferStorage.content.data         = NULL_PTR;

        LocalCardType = SD_IP_MEMORY_CARD_SD;
        /* Start transfer */
        if (STATUS_USDHC_IP_SUCCESS != uSDHC_Ip_Transfer(Config->usdhcConfig->instance, &Sd_Emmc_Ip_TransferStorage.content, (boolean)FALSE))
        {
            Status =  (Sd_Emmc_Ip_StatusType)SD_IP_STATUS_TRANSFER_FAILED;
        }
        else
        {
            /*
             * CMD8 (Send Interface Condition) argument contains host supply voltage and check pattern (any 8-bit value).
             * If the card accept supply voltage, and it responds and echoes supply voltage and check pattern back.
             * Check pattern value 0xAA is recommended by SD Physical Layer Simplified Specification Version 2.00 p. 40.
             */
            Status = (Sd_Emmc_Ip_StatusType)SD_IP_STATUS_SUCCESS;
            if (0xAAU != (Sd_Emmc_Ip_TransferStorage.command.response[0U] & 0xFFU))
            {
                /* Card is not supported */
                Status = (Sd_Emmc_Ip_StatusType)SD_IP_STATUS_CARD_NOT_SUPPORTED;
            }
        }
    }

    if ((Sd_Emmc_Ip_StatusType)SD_IP_STATUS_SUCCESS != Status)
    {
        LocalCardType = SD_IP_MEMORY_CARD_NOT_SUPPORTED;
    }

#if (MEM_43_EEP_SD_IP_DEV_ERROR_DETECT == STD_ON)
    if (Sd_Emmc_Ip_eCardTypeInfo != LocalCardType)
    {
        /* Card is not supported */
        Status = (Sd_Emmc_Ip_StatusType)SD_IP_STATUS_MEMORY_CARD_INCORRECT;
    }
#else
    Sd_Emmc_Ip_eCardTypeInfo = LocalCardType;
#endif

    return Status;
}

/**
* @brief         Sd_Ip_HandleSetBlockCountSize
* @details       Wrapper over Sd_Ip_SetBlockCount routine.
*
* @param[in]     Config Card descriptor.
* @param[in]     BlockCount    Number of blocks.
* @param[in]     BlockSize     Block size.
*
* @return        Status    
* @pre           The SD driver needs to be initialized.
*/
static Sd_Emmc_Ip_StatusType Sd_Ip_HandleSetBlockCountSize(const Sd_Emmc_Ip_ConfigType *Config, uint32 BlockCount, uint32 BlockSize)
{
    Sd_Emmc_Ip_StatusType Status = (Sd_Emmc_Ip_StatusType)SD_IP_STATUS_SUCCESS;

    /* Check if card supports set block count */
    if (((0U != (Sd_Emmc_Ip_u32CardFlags & (uint32)SD_IP_SUPPORT_HIGH_CAPACITY_FLAG)) && (BlockSize != 512U)) || (BlockSize > Sd_Emmc_Ip_u32BlockSizeInfo) ||
            (BlockSize > Sd_Emmc_Ip_Capability[Config->usdhcConfig->instance].maxBlockLength) || (0U != (BlockSize % 4U)))
    {
        Status = (Sd_Emmc_Ip_StatusType)SD_IP_STATUS_CARD_NOT_SUPPORTED;
    }
    else
    {
        if ((1U < BlockCount) && (FALSE == Sd_Emmc_Ip_TransferStorage.data.enableAutoCMD12) &&
                (0U != (Sd_Emmc_Ip_u32CardFlags & (uint32)SD_IP_SUPPORT_SET_BLOCK_COUNT_CMD)))
        {
            /* Set block count */
            if ((Sd_Emmc_Ip_StatusType)SD_IP_STATUS_SUCCESS != Sd_Ip_SetBlockCount(Config, BlockCount))
            {
                /* Set the block count failed */
                Status = (Sd_Emmc_Ip_StatusType)SD_IP_STATUS_SET_BLOCK_COUNT_FAILED;
            }
        }
    }

    return Status;
}

/**
* @brief         Sd_Ip_Read
* @details       Read data from specific SD card.
*
* @param[in]     Config Card descriptor.
* @param[in]     Buffer        Buffer to save data blocks read.
* @param[in]     StartBlock    Card start block number to be read.
* @param[in]     BlockSize     Block size.
* @param[in]     BlockCount    Block count.
*
* @return        Status    
* @pre           The SD driver needs to be initialized.
*/
static Sd_Emmc_Ip_StatusType Sd_Ip_Read(const Sd_Emmc_Ip_ConfigType *Config,
                                        uint8 *Buffer,
                                        uint32 StartBlock,
                                        uint32 BlockSize,
                                        uint32 BlockCount
                                       )
{
    Sd_Emmc_Ip_StatusType Status = (Sd_Emmc_Ip_StatusType)SD_IP_STATUS_SUCCESS;

    /* Wait for the card write process complete because of that card read process and write process use one buffer. */
    if ((Sd_Emmc_Ip_StatusType)SD_IP_STATUS_SUCCESS != Sd_Ip_WaitWriteComplete(Config))
    {
        Status = (Sd_Emmc_Ip_StatusType)SD_IP_STATUS_WAIT_WRITE_COMPLETE_FAILED;
    }

    if ((Sd_Emmc_Ip_StatusType)SD_IP_STATUS_SUCCESS == Status)
    {
        /* Set the block count */
        Status = Sd_Ip_HandleSetBlockCountSize(Config, BlockCount, BlockSize);
    }

    if ((Sd_Emmc_Ip_StatusType)SD_IP_STATUS_SUCCESS == Status)
    {
        /* Prepare the command transfer description */
        Sd_Emmc_Ip_TransferStorage.data.blockSize  = BlockSize;
        Sd_Emmc_Ip_TransferStorage.data.blockCount = BlockCount;
        Sd_Emmc_Ip_TransferStorage.data.rxData     = (uint32 *)((uint32)Buffer);
        Sd_Emmc_Ip_TransferStorage.data.txData     = NULL_PTR;

        Sd_Emmc_Ip_TransferStorage.command.index   = (uint32)aSDMMC_ReadMultipleBlock;
        /* If single block will be read */
        if (1U == Sd_Emmc_Ip_TransferStorage.data.blockCount)
        {
            Sd_Emmc_Ip_TransferStorage.command.index = (uint32)aSDMMC_ReadSingleBlock;
        }

        Sd_Emmc_Ip_TransferStorage.command.argument = StartBlock;
        if ((boolean)TRUE == Sd_Ip_CardTypeSDSC())
        {
            /* SDSC       (CCS=0) : byte unit address
               SHHC, SDXC (CCS=1) : block unit address (512 bytes unit)
             */
            Sd_Emmc_Ip_TransferStorage.command.argument *= BlockSize;
        }

        /* Set the command type and response type */
        Sd_Emmc_Ip_TransferStorage.command.type         = USDHC_COMMAND_TYPE_NORMAL;
        Sd_Emmc_Ip_TransferStorage.command.responseType = USDHC_RESPONSE_TYPE_R1;
        Sd_Emmc_Ip_TransferStorage.content.command      = &Sd_Emmc_Ip_TransferStorage.command;
        Sd_Emmc_Ip_TransferStorage.content.data         = &Sd_Emmc_Ip_TransferStorage.data;
        /* Start transfer command */
        if ((STATUS_USDHC_IP_SUCCESS != uSDHC_Ip_Transfer(Config->usdhcConfig->instance, &Sd_Emmc_Ip_TransferStorage.content, (boolean)FALSE)) || \
                (0U != ((Sd_Emmc_Ip_TransferStorage.command.response[0U]) & (uint32)SD_IP_R1_ALL_ERROR_FLAGS)))
        {
            /* The errors occurred */
            Status = (Sd_Emmc_Ip_StatusType)SD_IP_STATUS_TRANSFER_FAILED;
        }
        
    }

    /* Checking if timeout occurs */
    if ((boolean)TRUE == Usdhc_Ip_bFailedTimeout)
    {
        Status = SD_IP_STATUS_TIMEOUT;
        Usdhc_Ip_bFailedTimeout = (boolean)FALSE;
    }

    return Status;
}

/**
* @brief         Sd_Ip_WritePreCheck
* @details       Check before write data
*
* @return        void
* @pre           The SD driver needs to be initialized.
*/
static void Sd_Ip_WritePreCheck(const Sd_Emmc_Ip_ConfigType *Config,
                                uint32 BlockCount,
                                uint32 BlockSize
                               )
{
    uint32 StartTime;
    uint32 CurrentTime;
    volatile uint32   PresentStatusFlags = 0U;

    /* Check if card is read only */
    if (FALSE != Sd_Emmc_Ip_CheckReadOnly())
    {
        Sd_Emmc_Ip_eJobState = (Sd_Emmc_Ip_StatusType)SD_IP_STATUS_CARD_IS_WRITE_PROTECTED;
    }
    PresentStatusFlags = (uint32)(uSDHC_Ip_GetPresentStatusFlags(Config->usdhcConfig->instance) & (uint32)USDHC_DATA0_LINE_LEVEL);

    MCAL_FAULT_INJECTION_POINT(EEP_WRITE_PRE_CHECK);

    if ((Sd_Emmc_Ip_StatusType)SD_IP_STATUS_SUCCESS == Sd_Emmc_Ip_eJobState)
    {
        StartTime = OsIf_GetCounter(USDHC_IP_TIMEOUT_TYPE);
        CurrentTime = 0U;
        /* Waiting for the card's buffer to be not full. */
        while (0U == PresentStatusFlags)
        {
            CurrentTime += OsIf_GetElapsed(&StartTime, USDHC_IP_TIMEOUT_TYPE);
            if (CurrentTime >= USDHC_IP_GET_PRESENT_STATUS_TIMEOUT)
            {
                /* Timeout errors */
                Usdhc_Ip_bFailedTimeout = (boolean)TRUE;
                Sd_Emmc_Ip_eJobState = (Sd_Emmc_Ip_StatusType)SD_IP_STATUS_TIMEOUT;
                break;
            }
            PresentStatusFlags = (uint32)(uSDHC_Ip_GetPresentStatusFlags(Config->usdhcConfig->instance) & (uint32)USDHC_DATA0_LINE_LEVEL);
        }
        if ((Sd_Emmc_Ip_StatusType)SD_IP_STATUS_SUCCESS == Sd_Emmc_Ip_eJobState)
        {
            /* Waiting for previous write operation is complete */
            if ((Sd_Emmc_Ip_StatusType)SD_IP_STATUS_SUCCESS != Sd_Ip_WaitWriteComplete(Config))
            {
                Sd_Emmc_Ip_eJobState = (Sd_Emmc_Ip_StatusType)SD_IP_STATUS_WAIT_WRITE_COMPLETE_FAILED;
            }
        }
    }

    if ((Sd_Emmc_Ip_StatusType)SD_IP_STATUS_SUCCESS == Sd_Emmc_Ip_eJobState)
    {
        /* Set the block counts to be written */
        Sd_Emmc_Ip_eJobState = Sd_Ip_HandleSetBlockCountSize(Config, BlockCount, BlockSize);
    }
}

/**
* @brief         Sd_Ip_Write
* @details       Write data to specific card
*
* @param[in]     Config Card descriptor.
* @param[in]     buffer        Buffer to be sent.
* @param[in]     StartBlock    Card start block number to be written.
* @param[in]     BlockSize     Block size.
* @param[in]     BlockCount    Block count.
*
* @return        Status    
* @pre           The SD driver needs to be initialized.
*/
static Sd_Emmc_Ip_StatusType Sd_Ip_Write(const Sd_Emmc_Ip_ConfigType *Config,
                                         const uint8 *Buffer,
                                         uint32 StartBlock,
                                         uint32 BlockCount,
                                         boolean AsyncEnable
                                        )
{
    uint32 BlockSize = SD_IP_SDMMC_DEFAULT_BLOCK_SIZE;
    Usdhc_Ip_StatusType ControllerStatus;

    /* Prepare before a write operation */
    Sd_Ip_WritePreCheck(Config, BlockCount, BlockSize);

    if ((Sd_Emmc_Ip_StatusType)SD_IP_STATUS_SUCCESS == Sd_Emmc_Ip_eJobState)
    {
        /* Prepare transfer description */
        Sd_Emmc_Ip_TransferStorage.data.blockSize  = BlockSize;
        Sd_Emmc_Ip_TransferStorage.data.blockCount = BlockCount;
        Sd_Emmc_Ip_TransferStorage.data.txData     = (const uint32 *)((uint32)Buffer);
        Sd_Emmc_Ip_TransferStorage.data.rxData     = NULL_PTR;

        /* If single/multi block will be written */
        Sd_Emmc_Ip_TransferStorage.command.index   = (1U == BlockCount) ? (uint32)aSDMMC_WriteSingleBlock : (uint32)aSDMMC_WriteMultipleBlock;

        /* Set command argument */
        Sd_Emmc_Ip_TransferStorage.command.argument = StartBlock;
        if ((boolean)TRUE == Sd_Ip_CardTypeSDSC())
        {
            /* SDSC       (CCS=0) : byte unit address
               SHHC, SDXC (CCS=1) : block unit address (512 bytes unit)
             */
            Sd_Emmc_Ip_TransferStorage.command.argument *= BlockSize;
        }

        /* Set type of command and response type */
        Sd_Emmc_Ip_TransferStorage.command.type         = USDHC_COMMAND_TYPE_NORMAL;
        Sd_Emmc_Ip_TransferStorage.command.responseType = USDHC_RESPONSE_TYPE_R1;
        /* Store the transfer description */
        Sd_Emmc_Ip_TransferStorage.content.command      = &Sd_Emmc_Ip_TransferStorage.command;
        Sd_Emmc_Ip_TransferStorage.content.data         = &Sd_Emmc_Ip_TransferStorage.data;
    }

    if (((Sd_Emmc_Ip_StatusType)SD_IP_STATUS_SUCCESS == Sd_Emmc_Ip_eJobState) || (SD_IP_STATUS_PENDING == Sd_Emmc_Ip_eJobState))
    {
        /* Start transfer */
        ControllerStatus = uSDHC_Ip_Transfer(Config->usdhcConfig->instance, &Sd_Emmc_Ip_TransferStorage.content, AsyncEnable);

        if (STATUS_USDHC_IP_SUCCESS == ControllerStatus)
        {
            if ((0U != ((Sd_Emmc_Ip_TransferStorage.command.response[0U]) & (uint32)SD_IP_R1_ALL_ERROR_FLAGS)))
            {
                Sd_Emmc_Ip_eJobState = (Sd_Emmc_Ip_StatusType)SD_IP_STATUS_TRANSFER_FAILED;
            }
            else
            {
                Sd_Emmc_Ip_eJobState = (Sd_Emmc_Ip_StatusType)SD_IP_STATUS_SUCCESS;
            }
        }
        else if (STATUS_USDHC_IP_PENDING == ControllerStatus)
        {
            /* Do nothing and waiting for done */
            Sd_Emmc_Ip_eJobState = (Sd_Emmc_Ip_StatusType)SD_IP_STATUS_PENDING;
        }
        else
        {
            Sd_Emmc_Ip_eJobState = (Sd_Emmc_Ip_StatusType)SD_IP_STATUS_TRANSFER_FAILED;
        }
    }

    /* Checking if timeout occurs */
    if ((boolean)TRUE == Usdhc_Ip_bFailedTimeout)
    {
        Sd_Emmc_Ip_eJobState = SD_IP_STATUS_TIMEOUT;
        Usdhc_Ip_bFailedTimeout = (boolean)FALSE;
    }

    return Sd_Emmc_Ip_eJobState;
}

/**
* @brief         Sd_Ip_ErasePreCheck
* @details       Prepare before erasing data
*
* @return        void
* @pre           The SD driver needs to be initialized.
*/
static void Sd_Ip_ErasePreCheck(const Sd_Emmc_Ip_ConfigType *Config,
                                uint32 StartBlock,
                                uint32 BlockCount
                               )
{
    uint32 EraseBlockStart;
    uint32 EraseBlockEnd;
    uint32 StartTime;
    uint32 CurrentTime;
    volatile uint32   PresentStatusFlags = 0U;

    EraseBlockStart = StartBlock;
    EraseBlockEnd = EraseBlockStart + BlockCount;

    /* Check if card is read only */
    if (FALSE != Sd_Emmc_Ip_CheckReadOnly())
    {
        Sd_Emmc_Ip_eJobState = (Sd_Emmc_Ip_StatusType)SD_IP_STATUS_CARD_IS_WRITE_PROTECTED;
    }

    PresentStatusFlags = (uint32)(uSDHC_Ip_GetPresentStatusFlags(Config->usdhcConfig->instance) & (uint32)USDHC_DATA0_LINE_LEVEL);
    MCAL_FAULT_INJECTION_POINT(SD_ERASE_PRE_CHECK);

    if ((Sd_Emmc_Ip_StatusType)SD_IP_STATUS_SUCCESS == Sd_Emmc_Ip_eJobState)
    {
        StartTime = OsIf_GetCounter(USDHC_IP_TIMEOUT_TYPE);
        CurrentTime = 0U;
        /* Waiting for the card's buffer to be not full. */
        while (0U == PresentStatusFlags)
        {
            CurrentTime += OsIf_GetElapsed(&StartTime, USDHC_IP_TIMEOUT_TYPE);
            if (CurrentTime >= USDHC_IP_GET_PRESENT_STATUS_TIMEOUT)
            {
                /* Timeout errors */
                Usdhc_Ip_bFailedTimeout = (boolean)TRUE;
                Sd_Emmc_Ip_eJobState = (Sd_Emmc_Ip_StatusType)SD_IP_STATUS_TIMEOUT;
                break;
            }
            PresentStatusFlags = (uint32)(uSDHC_Ip_GetPresentStatusFlags(Config->usdhcConfig->instance) & (uint32)USDHC_DATA0_LINE_LEVEL);
        }

        if ((Sd_Emmc_Ip_StatusType)SD_IP_STATUS_SUCCESS == Sd_Emmc_Ip_eJobState)
        {
            /* Wait for the card write process complete because of that card read process and write process use one buffer. */
            if ((Sd_Emmc_Ip_StatusType)SD_IP_STATUS_SUCCESS != Sd_Ip_WaitWriteComplete(Config))
            {
                Sd_Emmc_Ip_eJobState = (Sd_Emmc_Ip_StatusType)SD_IP_STATUS_WAIT_WRITE_COMPLETE_FAILED;
            }
        }
    }

    Sd_Emmc_Ip_TransferStorage.command.type = USDHC_COMMAND_TYPE_NORMAL;

    if ((Sd_Emmc_Ip_StatusType)SD_IP_STATUS_SUCCESS == Sd_Emmc_Ip_eJobState)
    {
        if ((boolean)TRUE == Sd_Ip_CardTypeSDSC())
        {
            /* SDSC       (CCS=0) : byte unit address
               SHHC, SDXC (CCS=1) : block unit address (512 bytes unit)
             */
            EraseBlockStart = EraseBlockStart * SD_IP_SDMMC_DEFAULT_BLOCK_SIZE;
            EraseBlockEnd   = EraseBlockEnd   * SD_IP_SDMMC_DEFAULT_BLOCK_SIZE;
        }
        /* Send the block start */
        Sd_Emmc_Ip_eJobState = Sd_Ip_SendEraseBlockStart(Config, EraseBlockStart);
    }

    if ((Sd_Emmc_Ip_StatusType)SD_IP_STATUS_SUCCESS == Sd_Emmc_Ip_eJobState)
    {
        /* Send the block end */
        Sd_Emmc_Ip_eJobState = Sd_Ip_SendEraseBlockEnd(Config, EraseBlockEnd);
    }
}

/**
* @brief         Sd_Ip_Erase
* @details       Erase data for the given block range.
*
* @param[in]     Config Card descriptor.
* @param[in]     StartBlock    Card start block number to be erased.
* @param[in]     BlockCount    The block count to be erased.
*
* @return        Status    
* @pre           The SD driver needs to be initialized.
*/
static Sd_Emmc_Ip_StatusType Sd_Ip_Erase(const Sd_Emmc_Ip_ConfigType *Config, uint32 StartBlock, uint32 BlockCount, boolean AsyncEnable)
{
    Usdhc_Ip_StatusType ControllerStatus;

    /* Prepare before an erase operation */
    Sd_Ip_ErasePreCheck(Config, StartBlock, BlockCount);

    if ((Sd_Emmc_Ip_StatusType)SD_IP_STATUS_SUCCESS == Sd_Emmc_Ip_eJobState)
    {
        /* Prepare transfer description */
        Sd_Emmc_Ip_TransferStorage.command.index        = (uint32)aSDMMC_Erase;
        Sd_Emmc_Ip_TransferStorage.command.argument     = 0x00000000U;
        Sd_Emmc_Ip_TransferStorage.command.responseType = USDHC_RESPONSE_TYPE_R1b;
        Sd_Emmc_Ip_TransferStorage.content.command      = &Sd_Emmc_Ip_TransferStorage.command;
        Sd_Emmc_Ip_TransferStorage.content.data         = NULL_PTR;
    }

    if (((Sd_Emmc_Ip_StatusType)SD_IP_STATUS_SUCCESS == Sd_Emmc_Ip_eJobState) || (SD_IP_STATUS_PENDING == Sd_Emmc_Ip_eJobState))
    {
        /* Send the command to start erase */
        ControllerStatus = uSDHC_Ip_Transfer(Config->usdhcConfig->instance, &Sd_Emmc_Ip_TransferStorage.content, AsyncEnable);

        if (STATUS_USDHC_IP_SUCCESS == ControllerStatus)
        {
            if ((0U != ((Sd_Emmc_Ip_TransferStorage.command.response[0U]) & (uint32)SD_IP_R1_ALL_ERROR_FLAGS)))
            {
                Sd_Emmc_Ip_eJobState = (Sd_Emmc_Ip_StatusType)SD_IP_STATUS_TRANSFER_FAILED;
            }
            else
            {
                Sd_Emmc_Ip_eJobState = (Sd_Emmc_Ip_StatusType)SD_IP_STATUS_SUCCESS;
            }
        }
        else if (STATUS_USDHC_IP_PENDING == ControllerStatus)
        {
            /* Do nothing and waiting for done */
            Sd_Emmc_Ip_eJobState = (Sd_Emmc_Ip_StatusType)SD_IP_STATUS_PENDING;
        }
        else
        {
            Sd_Emmc_Ip_eJobState = (Sd_Emmc_Ip_StatusType)SD_IP_STATUS_TRANSFER_FAILED;
        }
    }

    /* Checking if timeout occurs */
    if ((boolean)TRUE == Usdhc_Ip_bFailedTimeout)
    {
        Sd_Emmc_Ip_eJobState = SD_IP_STATUS_TIMEOUT;
        Usdhc_Ip_bFailedTimeout = (boolean)FALSE;
    }

    return Sd_Emmc_Ip_eJobState;
}

/**
* @brief         Sd_Ip_SwitchFunctionSupported
* @details       Check if card supports switch function or not
*
* @return        Status
* @pre           The USDHC driver needs to be initialized.
*/
static inline Sd_Emmc_Ip_StatusType Sd_Ip_SwitchFunctionSupported(void)
{
    Sd_Emmc_Ip_StatusType Status;

    /* Check card version and bit 10 in CSD register */
    if ((Sd_Emmc_Ip_u32VersionInfo < (uint32)aSD_SpecificationVersion1_1) || (0U == (Sd_Emmc_Ip_Csd.cardCommandClass & (uint16)aSDMMC_CommandClassSwitch)))
    {
        Status = (Sd_Emmc_Ip_StatusType)SD_IP_STATUS_CARD_NOT_SUPPORTED;
    }
    else
    {
        Status = (Sd_Emmc_Ip_StatusType)SD_IP_STATUS_SUCCESS;
    }

    return Status;
}

/**
* @brief         Sd_Ip_IncreaseBusSpeed4Bit
* @details       Set SD bus width, switch card into high speed mode if supported.
*
* @param[in]     Config Card descriptor.
*
* @return        Status
* @pre           The USDHC driver needs to be initialized.
*/
static Sd_Emmc_Ip_StatusType Sd_Ip_IncreaseBusSpeed4Bit(const Sd_Emmc_Ip_ConfigType *Config)
{
    Sd_Emmc_Ip_StatusType Status = (Sd_Emmc_Ip_StatusType)SD_IP_STATUS_SUCCESS;

    /* Check if both host and card support bus width 4-bit */
    if ( (0U != ((Sd_Emmc_Ip_Capability[Config->usdhcConfig->instance].flags) & (uint32)USDHC_HOST_CTRL_CAP_SUPPORT_4BIT)) &&
         (0U != (Sd_Emmc_Ip_u32CardFlags & (uint32)SD_IP_SUPPORT_4_BIT_WIDTH_FLAG))
       )
    {
        /* Set card bus width */
        Status = Sd_Ip_SetDataBusWidth(Config, aSD_DataBusWidth4Bit);
        if ((Sd_Emmc_Ip_StatusType)SD_IP_STATUS_SUCCESS == Status)
        {
            /* Set host bus width */
            uSDHC_Ip_SetDataBusWidth(Config->usdhcConfig->instance, USDHC_DATA_BUS_WIDTH_4BIT);
        }
        else
        {
            Status = (Sd_Emmc_Ip_StatusType)SD_IP_STATUS_SET_DATA_BUS_WIDTH_FAILED;
        }
    }

    return Status;
}

/**
* @brief         Sd_Ip_ConvertSwitchFunctionResult
* @details       Convert the result after performing SwitchFunction 
*
* @return        Status
* @pre           The USDHC driver needs to be initialized.
*/
static inline Sd_Emmc_Ip_StatusType Sd_Ip_ConvertSwitchFunctionResult(Sd_Emmc_Ip_StatusType SwitchResult)
{
    Sd_Emmc_Ip_StatusType Status;

    if ( ((Sd_Emmc_Ip_StatusType)SD_IP_STATUS_CARD_NOT_SUPPORTED != SwitchResult) &&
         ((Sd_Emmc_Ip_StatusType)SD_IP_STATUS_SUCCESS            != SwitchResult)
       )
    {
        Status = (Sd_Emmc_Ip_StatusType)SD_IP_STATUS_SWITCH_FAILED;
    }
    else
    {
        /* The requested function was not supported or the switching function succeeded */
        /* SD_IP_STATUS_CARD_NOT_SUPPORTED is also acceptable */
        Status = (Sd_Emmc_Ip_StatusType)SD_IP_STATUS_SUCCESS;
    }

    return Status;
}

/**
* @brief         Sd_Ip_SwitchHighSpeed
* @details       Set SD bus width, switch card into high speed mode if supported.
*
* @param[in]     Config Card descriptor.
*
* @return        Status    
* @pre           The USDHC driver needs to be initialized.
*/
static Sd_Emmc_Ip_StatusType Sd_Ip_SwitchHighSpeed(const Sd_Emmc_Ip_ConfigType *Config)
{
    Sd_Emmc_Ip_StatusType Status;
    Sd_Emmc_Ip_StatusType SwitchResult;

    /* Check if CMD6 supported or not */
    Status = Sd_Ip_SwitchFunctionSupported();

    if ((Sd_Emmc_Ip_StatusType)SD_IP_STATUS_SUCCESS == Status)
    {
        /* Set to max frequency in non-high speed mode. */
        Sd_Emmc_Ip_u32BusClockInfo = Sd_Ip_FindBusClock(Config);

        /* Set to 4-bit data bus mode. */
        Status = Sd_Ip_IncreaseBusSpeed4Bit(Config);
    }

#if (USDHC_IP_V180_SUPPORT == STD_ON)
    if (0U != (Sd_Emmc_Ip_u32CardFlags & (uint32)SD_IP_SUPPORT_VOLTAGE_180V))
    {
        if ((Sd_Emmc_Ip_StatusType)SD_IP_STATUS_SUCCESS == Status)
        {
            SwitchResult = Sd_Ip_CheckAndSwitchFunction(Config, aSD_GroupDriverStrength, (uint32)aSD_DriverStrengthTypeB);
            Status = Sd_Ip_ConvertSwitchFunctionResult(SwitchResult);
        }

        if ((Sd_Emmc_Ip_StatusType)SD_IP_STATUS_SUCCESS == Status)
        {
            SwitchResult = Sd_Ip_CheckAndSwitchFunction(Config, aSD_GroupCurrentLimit, (uint32)aSD_CurrentLimit200MA);
            Status = Sd_Ip_ConvertSwitchFunctionResult(SwitchResult);
        }
    }
#endif /* USDHC_IP_V180_SUPPORT */

    if ((Sd_Emmc_Ip_StatusType)SD_IP_STATUS_SUCCESS == Status)
    {
        /* Switch the card to high speed mode */
        if (0U != (Sd_Emmc_Ip_Capability[Config->usdhcConfig->instance].flags & (uint32)USDHC_HOST_CTRL_CAP_HSS_MASK))
        {
            SwitchResult = Sd_Ip_CheckAndSwitchFunction(Config, aSD_GroupTimingMode, (uint32)aSD_FunctionSDR25HighSpeed);
            if ((Sd_Emmc_Ip_StatusType)SD_IP_STATUS_SUCCESS == SwitchResult)
            {
                if (STATUS_USDHC_IP_SUCCESS != uSDHC_Ip_SetBusClock(Config->usdhcConfig->instance, Config->u32McuClock, SD_CLOCK_50MHZ, &(Sd_Emmc_Ip_u32BusClockInfo)))
                {
                    Status = SD_IP_STATUS_ERROR;
                }
            }
            else
            {
                Status = Sd_Ip_ConvertSwitchFunctionResult(SwitchResult);
            }
        }
    }

    return Status;
}

/**
* @brief         Sd_Ip_SwitchToDataTransfer
* @details       Switch card from initialization state into data transfer state.
*
* @param[in]     Config Card descriptor.
*
* @return        Status    
* @pre           The USDHC driver needs to be initialized.
*/
static Sd_Emmc_Ip_StatusType Sd_Ip_SwitchToDataTransfer(const Sd_Emmc_Ip_ConfigType *Config)
{
    Sd_Emmc_Ip_StatusType Status;

    /* Initialize card if the card is SD card. */
    Status = Sd_Ip_AllSendCid(Config);

    if ((Sd_Emmc_Ip_StatusType)SD_IP_STATUS_SUCCESS != Status)
    {
        /* The errors occurred */
        Status = (Sd_Emmc_Ip_StatusType)SD_IP_STATUS_ALL_SEND_CID_FAILED;
    }
    else
    {
        /* Send relative card address */
        Status = Sd_Ip_SendRca(Config);
        if ((Sd_Emmc_Ip_StatusType)SD_IP_STATUS_SUCCESS != Status)
        {
            /* The errors occurred */
            Status = (Sd_Emmc_Ip_StatusType)SD_IP_STATUS_SEND_RELATIVE_ADDRESS_FAILED;
        }
    }

    if ((Sd_Emmc_Ip_StatusType)SD_IP_STATUS_SUCCESS == Status)
    {
        /* Get Sd_Emmc_Ip_Csd register */
        Status = Sd_Ip_SendCsd(Config);
        if ((Sd_Emmc_Ip_StatusType)SD_IP_STATUS_SUCCESS == Status)
        {
            /* Set the bus clock */
            (void)uSDHC_Ip_SetBusClock(Config->usdhcConfig->instance, Config->u32McuClock, SD_CLOCK_25MHZ, &(Sd_Emmc_Ip_u32BusClockInfo));
        }
        else
        {
            Status = (Sd_Emmc_Ip_StatusType)SD_IP_STATUS_SEND_CSD_FAILED;
        }
    }

    if ((Sd_Emmc_Ip_StatusType)SD_IP_STATUS_SUCCESS == Status)
    {
        /* Select card */
        Status = Sd_Ip_SelectCard(Config, TRUE);
        if ((Sd_Emmc_Ip_StatusType)SD_IP_STATUS_SUCCESS != Status)
        {
            /* The errors occurred */
            Status = (Sd_Emmc_Ip_StatusType)SD_IP_STATUS_SELECT_CARD_FAILED;
        }
    }

    if (SD_IP_MEMORY_CARD_SD == Sd_Emmc_Ip_eCardTypeInfo)
    {
        if ((Sd_Emmc_Ip_StatusType)SD_IP_STATUS_SUCCESS == Status)
        {
            /* Get the Scr register */
            Status = Sd_Ip_SendScr(Config);
            if ((Sd_Emmc_Ip_StatusType)SD_IP_STATUS_SUCCESS != Status)
            {
                /* The errors occurred */
                Status = (Sd_Emmc_Ip_StatusType)SD_IP_STATUS_SEND_SCR_FAILED;
            }
        }
    }

    return Status;
}

#if (STD_ON == FEATURE_USDHC_HAS_HIGHSPEED_TUNNING)
static Sd_Emmc_Ip_StatusType Sd_Ip_MmcSwitchHighSpeedHS400(const Sd_Emmc_Ip_ConfigType *Sd_Ip_pConfig)
{
    Sd_Emmc_Ip_StatusType Status = (Sd_Emmc_Ip_StatusType)SD_IP_STATUS_SUCCESS;
    Usdhc_Ip_StatusType ControllerStatus;
    uint32 TimmingValue;

    /* Try switching to each high speed mode from top down */
    if (mmcCapability.supportHS400 == TRUE)
    {
        /* Change speed to HS400 by sending CMD6 */
        TimmingValue = ((uint32)Sd_Ip_pConfig->driverStrength << 4U) | MMCHS400Speed;
        Status = Sd_Ip_MmcSwitch(Sd_Ip_pConfig, MMCCWriteBits, (uint8)185U, TimmingValue << 8U);

        if ((Sd_Emmc_Ip_StatusType)SD_IP_STATUS_SUCCESS == Status)
        {
            /* Set MIX_CTRL register for DDR, HS400, and enhanced HS400 modes */
            uSDHC_Ip_SetTiming(Sd_Ip_pConfig->usdhcConfig->instance, TRUE, FALSE, TRUE);
            /* Wait for MMC device ready by sending CMD13 */
            if ((Sd_Emmc_Ip_StatusType)SD_IP_STATUS_SUCCESS != Sd_Ip_WaitWriteComplete(Sd_Ip_pConfig))
            {
                Status = SD_IP_STATUS_WAIT_WRITE_COMPLETE_FAILED;
            }
            else
            {
                /* Set bus clock upto 400MHz for HS400 operation. Note: In DDR mode, clock value will be automatically divided by 2 by hardware */
                ControllerStatus = uSDHC_Ip_SetBusClock(Sd_Ip_pConfig->usdhcConfig->instance,
                                                        Sd_Ip_pConfig->u32McuClock,
                                                        Sd_Ip_pConfig->SdConfigClock << 1U,
                                                        &(Sd_Emmc_Ip_u32BusClockInfo)
                                                       );

                if (STATUS_USDHC_IP_SUCCESS == ControllerStatus)
                {
                    /* Change voltage to low voltage. HS400 only runs in low voltage mode */
                    ControllerStatus = uSDHC_Ip_SwitchVoltage(Sd_Ip_pConfig->usdhcConfig->instance, TRUE);
                }

                if (STATUS_USDHC_IP_SUCCESS != ControllerStatus)
                {
                    Status = SD_IP_STATUS_ERROR;
                }
            }
        }

    }

    return Status;
}

static Sd_Emmc_Ip_StatusType Sd_Ip_MmcSwitchHighSpeedHS200(const Sd_Emmc_Ip_ConfigType *Sd_Ip_pConfig)
{
    Sd_Emmc_Ip_StatusType Status = (Sd_Emmc_Ip_StatusType)SD_IP_STATUS_SUCCESS;
    Usdhc_Ip_StatusType ControllerStatus;
    uint32 TimmingValue;

    if (mmcCapability.supportHS200 == TRUE)
    {
        /* Change speed to HS200 by sending CMD6 */
        TimmingValue = ((uint32)Sd_Ip_pConfig->driverStrength << 4U) | MMCHS200Speed;
        Status = Sd_Ip_MmcSwitch(Sd_Ip_pConfig, MMCCWriteBits, (uint8)185U, TimmingValue << 8U);
        if (SD_IP_STATUS_SUCCESS == Status)
        {
            /* Set bus clock upto 200MHz for HS200 operation */
            ControllerStatus = uSDHC_Ip_SetBusClock(Sd_Ip_pConfig->usdhcConfig->instance,
                                                    Sd_Ip_pConfig->u32McuClock,
                                                    Sd_Ip_pConfig->SdConfigClock,
                                                    &(Sd_Emmc_Ip_u32BusClockInfo)
                                                   ); 

            if (STATUS_USDHC_IP_SUCCESS == ControllerStatus)
            {
                /* Change voltage to low voltage. HS200 only runs in low voltage mode */
                ControllerStatus = uSDHC_Ip_SwitchVoltage(Sd_Ip_pConfig->usdhcConfig->instance, TRUE);
            }

            if (STATUS_USDHC_IP_SUCCESS != ControllerStatus)
            {
                Status = SD_IP_STATUS_ERROR;
            }
        }
    }

    return Status;
}
#endif

static Sd_Emmc_Ip_StatusType Sd_Ip_MmcSwitchHighSpeedDDR52(const Sd_Emmc_Ip_ConfigType *Sd_Ip_pConfig)
{
    Sd_Emmc_Ip_StatusType Status = (Sd_Emmc_Ip_StatusType)SD_IP_STATUS_SUCCESS;
    Usdhc_Ip_StatusType ControllerStatus;

    if (mmcCapability.supportHS52DDR == TRUE)
    {
        /* Change speed to High speed by sending CMD6 */
        Status = Sd_Ip_MmcSwitch(Sd_Ip_pConfig, MMCCWriteBits, (uint8)185U, MMCHightSpeed);
        /* Set MIX_CTRL register for DDR, HS400, and enhanced HS400 modes */
        uSDHC_Ip_SetTiming(Sd_Ip_pConfig->usdhcConfig->instance, TRUE, FALSE, FALSE);
        if (SD_IP_STATUS_SUCCESS == Status)
        {
            /* Set bus clock upto 52MHz for DDR52 operation
               Note: In DDR mode, clock value will be automatically divided by 2 by hardware
             */
            ControllerStatus = uSDHC_Ip_SetBusClock(Sd_Ip_pConfig->usdhcConfig->instance,
                                                    Sd_Ip_pConfig->u32McuClock,
                                                    MMC_CLOCK_52MHZ << 1U,
                                                    &(Sd_Emmc_Ip_u32BusClockInfo)
                                                   );

            if (STATUS_USDHC_IP_SUCCESS != ControllerStatus)
            {
                Status = SD_IP_STATUS_ERROR;
            }
        }
    }

    return Status;
}

static Sd_Emmc_Ip_StatusType Sd_Ip_MmcSwitchHighSpeedSDR52(const Sd_Emmc_Ip_ConfigType *Sd_Ip_pConfig)
{
    Sd_Emmc_Ip_StatusType Status = (Sd_Emmc_Ip_StatusType)SD_IP_STATUS_SUCCESS;
    Usdhc_Ip_StatusType ControllerStatus;

    if (mmcCapability.supportHSLegacy == TRUE)
    {
        /* Change speed to High speed by sending CMD6 */
        Status = Sd_Ip_MmcSwitch(Sd_Ip_pConfig, MMCCWriteBits, (uint8)185U, MMCHightSpeed);
        if (SD_IP_STATUS_SUCCESS == Status)
        {
            /* Set bus clock upto 52MHz for SDR52 operation */
            ControllerStatus = uSDHC_Ip_SetBusClock(Sd_Ip_pConfig->usdhcConfig->instance,
                                                    Sd_Ip_pConfig->u32McuClock,
                                                    MMC_CLOCK_52MHZ,
                                                    &(Sd_Emmc_Ip_u32BusClockInfo)
                                                   );

            if (STATUS_USDHC_IP_SUCCESS != ControllerStatus)
            {
                Status = SD_IP_STATUS_ERROR;
            }
        }
    }

    return Status;
}


/**
* @brief         Sd_Ip_SwitchToSDR52
* @details       Switch card speed to SDR52.
*
* @param[in]     Sd_Ip_pConfig Card descriptor.
* @param[in]     busWidth      Bus width 4/8 bits.
*
* @return        Status    
* @pre           The USDHC driver needs to be initialized.
*/
static Sd_Emmc_Ip_StatusType Sd_Ip_SwitchToSDR52(const Sd_Emmc_Ip_ConfigType *Sd_Ip_pConfig, uint32 busWidth)
{
    Sd_Emmc_Ip_StatusType Status;

    /* Change MMC bus width to configured buswidth by sending CMD6 */
    Status = Sd_Ip_MmcSwitch(Sd_Ip_pConfig, MMCCWriteBits, (uint8)183U, busWidth);
    if ((Sd_Emmc_Ip_StatusType)SD_IP_STATUS_SUCCESS == Status)
    {
        /* Configure data bus width for USDHC host to configured buswidth */
        if (busWidth == MMCBusWidth8)
        {
            uSDHC_Ip_SetDataBusWidth(Sd_Ip_pConfig->usdhcConfig->instance, USDHC_DATA_BUS_WIDTH_8BIT);
        }
        else
        {
            uSDHC_Ip_SetDataBusWidth(Sd_Ip_pConfig->usdhcConfig->instance, USDHC_DATA_BUS_WIDTH_4BIT);
        }
        /* Switch speed to high speed HS200 mode, clock frequency less than or equal to 52MHz */
        Status = Sd_Ip_MmcSwitchHighSpeedSDR52(Sd_Ip_pConfig);
    }

    return Status;
}

/**
* @brief         Sd_Ip_SwitchToDDR52
* @details       Switch card speed to DDR52.
*
* @param[in]     Sd_Ip_pConfig Card descriptor.
* @param[in]     busWidth      Bus width 4/8 bits DDR.
*
* @return        Status    
* @pre           The USDHC driver needs to be initialized.
*/
static Sd_Emmc_Ip_StatusType Sd_Ip_SwitchToDDR52(const Sd_Emmc_Ip_ConfigType *Sd_Ip_pConfig, uint32 busWidth)
{
    Sd_Emmc_Ip_StatusType Status;

    /* Change bus width to 4 bit DDR for MMC device by sending CMD6 */
    Status = Sd_Ip_MmcSwitch(Sd_Ip_pConfig, MMCCWriteBits, (uint8)183U, busWidth);

    if ((Sd_Emmc_Ip_StatusType)SD_IP_STATUS_SUCCESS == Status)
    {
        /* Change speed of MMC device to high speed DDR52 mode, clock frequency less than or equal to 52MHz DDR */
        if ((Sd_Emmc_Ip_StatusType)SD_IP_STATUS_SUCCESS != Sd_Ip_MmcSwitchHighSpeedDDR52(Sd_Ip_pConfig))
        {
            Status = SD_IP_STATUS_SWITCH_FAILED;
        }
    }

    if ((Sd_Emmc_Ip_StatusType)SD_IP_STATUS_SUCCESS == Status)
    {
        /* Wait for MMC device ready by sending CMD13 */
        if ((Sd_Emmc_Ip_StatusType)SD_IP_STATUS_SUCCESS != Sd_Ip_WaitWriteComplete(Sd_Ip_pConfig))
        {
            Status = SD_IP_STATUS_WAIT_WRITE_COMPLETE_FAILED;
        }
    }

    return Status;
}

#if (STD_ON == FEATURE_USDHC_HAS_HIGHSPEED_TUNNING)
/**
* @brief         Sd_Ip_SwitchToHS200
* @details       Switch card speed to HS200.
*
* @param[in]     Config Card descriptor.
* @param[in]     busWidth      Bus width 4/8 bits.
*
* @return        Status    
* @pre           The USDHC driver needs to be initialized.
*/
static Sd_Emmc_Ip_StatusType Sd_Ip_SwitchToHS200(const Sd_Emmc_Ip_ConfigType *Config, uint32 BusWidth)
{
    Sd_Emmc_Ip_StatusType Status;

    /* Change bus width of MMC device to configured buswidth by sending CMD6 */
    Status = Sd_Ip_MmcSwitch(Config, MMCCWriteBits, (uint8)183U, BusWidth);
    if ((Sd_Emmc_Ip_StatusType)SD_IP_STATUS_SUCCESS == Status)
    {
        /* Configure data bus width for USDHC host to configured buswidth */
        if(BusWidth == MMCBusWidth8)
        {
            uSDHC_Ip_SetDataBusWidth(Config->usdhcConfig->instance, USDHC_DATA_BUS_WIDTH_8BIT);
            /* Switch speed to high speed HS200 mode, clock frequency less than or equal to 200MHz */
            Status = Sd_Ip_MmcSwitchHighSpeedHS200(Config);
            if ((Sd_Emmc_Ip_StatusType)SD_IP_STATUS_SUCCESS == Status)
            {
                /* Execute manual tuning procedure */ 
                Status = Sd_Ip_MmcExecuteTuning(Config, MMC_TUNING_8BIT_BLKSIZE);
            }
        }
        else
        {
            uSDHC_Ip_SetDataBusWidth(Config->usdhcConfig->instance, USDHC_DATA_BUS_WIDTH_4BIT);
            /* Switch speed to high speed HS200 mode, clock frequency less than or equal to 200MHz */
            Status = Sd_Ip_MmcSwitchHighSpeedHS200(Config);
            if ((Sd_Emmc_Ip_StatusType)SD_IP_STATUS_SUCCESS == Status)
            {
                /* Execute manual tuning procedure */ 
                Status = Sd_Ip_MmcExecuteTuning(Config, MMC_TUNING_4BIT_BLKSIZE);
            }
        }
    }

    return Status;
}

/**
* @brief         Sd_Ip_SwitchToHS400
* @details       Switch card speed to HS400.
*
* @param[in]     Config Card descriptor.
*
* @return        Status    
* @pre           The USDHC driver needs to be initialized.
*/
static Sd_Emmc_Ip_StatusType Sd_Ip_SwitchToHS400(const Sd_Emmc_Ip_ConfigType *Config)
{
    Sd_Emmc_Ip_StatusType Status = (Sd_Emmc_Ip_StatusType)SD_IP_STATUS_SUCCESS;

    /* If card does not support enhance strobe, then it needs to be tuned in HS200 mode, then switch to HS legacy mode, before upgrading to HS400 mode */
    if (mmcCapability.supportEnhanceStrobe != TRUE)
    {
        /* Increase bus width to 8 bit */
        Status = Sd_Ip_MmcSwitch(Config, MMCCWriteBits, (uint8)183U, MMCBusWidth8);
        /* Set 8 bit DTW for host */
        uSDHC_Ip_SetDataBusWidth(Config->usdhcConfig->instance, USDHC_DATA_BUS_WIDTH_8BIT);
        if ((Sd_Emmc_Ip_StatusType)SD_IP_STATUS_SUCCESS == Status)
        {
            /* Switch card speed to high speed HS200 mode, clock frequency less than or equal to 200MHz */
            if((Sd_Emmc_Ip_StatusType)SD_IP_STATUS_SUCCESS == Sd_Ip_MmcSwitchHighSpeedHS200(Config))
            {
                /* Perform tuning process in HS200 mode */
                Status = Sd_Ip_MmcExecuteTuning(Config, MMC_TUNING_8BIT_BLKSIZE);
            }
            if ((Sd_Emmc_Ip_StatusType)SD_IP_STATUS_SUCCESS == Status)
            {
                /* After tuning successfully, switch card mode back to high speed mode, clock frequency less than or equal to 52MHz */
                Status = Sd_Ip_MmcSwitchHighSpeedSDR52(Config);
            }
        }
    }
    if ((Sd_Emmc_Ip_StatusType)SD_IP_STATUS_SUCCESS == Status)
    {
        /* Increase bus width to 8 bit DDR */
        Status = Sd_Ip_MmcSwitch(Config, MMCCWriteBits, (uint8)183U, MMCBusWidth8ddr);

        if ((Sd_Emmc_Ip_StatusType)SD_IP_STATUS_SUCCESS == Status)
        {
            /* Switch speed to high speed HS400 mode, clock frequency less than or equal to 200MHz DDR */
            Status = Sd_Ip_MmcSwitchHighSpeedHS400(Config);
        }
        /* Configure strobe Dll control for HS400 mode */
        uSDHC_Ip_SetStrobeDll(Config->usdhcConfig->instance);
    }

    return Status;
}
#endif /* (STD_ON == FEATURE_USDHC_HAS_HIGHSPEED_TUNNING) */

static Sd_Emmc_Ip_StatusType Sd_Ip_IncreaseMmcBusSpeed4Bit(const Sd_Emmc_Ip_ConfigType *Config)
{
    Sd_Emmc_Ip_StatusType Status = SD_IP_STATUS_ERROR;

    /* In 4 bit SDR mode, try to switch speed to HS200 (highest speed) */
    #if (STD_ON == FEATURE_USDHC_HAS_HIGHSPEED_TUNNING)
    if (0U != (Sd_Emmc_Ip_Capability[Config->usdhcConfig->instance].flags & (uint32)USDHC_HOST_CTRL_CAP_VS18_MASK))
    {
        /* HS200 only runs in 1.8V mode */
        Status = Sd_Ip_SwitchToHS200(Config, MMCBusWidth4);
    }
    #endif

    if ((Sd_Emmc_Ip_StatusType)SD_IP_STATUS_SUCCESS != Status)
    {
        /* If switching to HS200 mode failed, switch speed to high speed SDR52 mode, clock frequency less than or equal to 52MHz */
        Status = Sd_Ip_SwitchToSDR52(Config, MMCBusWidth4);
    }

    return Status;
}

static Sd_Emmc_Ip_StatusType Sd_Ip_IncreaseMmcBusSpeed8Bit(const Sd_Emmc_Ip_ConfigType *Config)
{
    Sd_Emmc_Ip_StatusType Status = SD_IP_STATUS_ERROR;

    /* In 8 bit SDR mode, try to switch speed to HS200 (highest speed) */
    #if (STD_ON == FEATURE_USDHC_HAS_HIGHSPEED_TUNNING)
    if (0U != (Sd_Emmc_Ip_Capability[Config->usdhcConfig->instance].flags & (uint32)USDHC_HOST_CTRL_CAP_VS18_MASK))
    {
        /* HS200 only runs in 1.8V mode */
        Status = Sd_Ip_SwitchToHS200(Config, MMCBusWidth8);
    }
    #endif

    if ((Sd_Emmc_Ip_StatusType)SD_IP_STATUS_SUCCESS != Status)
    {
        /* If switching to HS200 mode failed, switch speed to SDR52 mode, clock frequency less than or equal to 52MHz */
        Status = Sd_Ip_SwitchToSDR52(Config, MMCBusWidth8);
    }

    return Status;
}

static Sd_Emmc_Ip_StatusType Sd_Ip_IncreaseMmcBusSpeed4BitDDR(const Sd_Emmc_Ip_ConfigType *Config)
{
    Sd_Emmc_Ip_StatusType Status;

    /* In 4 bit DDR mode, try to switch speed to DDR52, return switching failed Status in case of failure */
    /* Switch device speed to high speed mode before enabling DDR */
    Status = Sd_Ip_SwitchToSDR52(Config, MMCBusWidth4);
    if ((Sd_Emmc_Ip_StatusType)SD_IP_STATUS_SUCCESS == Status)
    {
        Status = Sd_Ip_SwitchToDDR52(Config, MMCBusWidth4ddr);
    }

    return Status;
}

static Sd_Emmc_Ip_StatusType Sd_Ip_IncreaseMmcBusSpeed8BitDDR(const Sd_Emmc_Ip_ConfigType *Config)
{
    Sd_Emmc_Ip_StatusType Status = SD_IP_STATUS_ERROR;

    /* In 8 bit DDR mode, try to switch speed to HS400 (highest speed), switch to DDR52 mode in case of failure */
    /* Switch speed to high speed HS400 mode, clock frequency less than or equal to 200MHz DDR */
    #if (STD_ON == FEATURE_USDHC_HAS_HIGHSPEED_TUNNING)
    if (0U != (Sd_Emmc_Ip_Capability[Config->usdhcConfig->instance].flags & (uint32)USDHC_HOST_CTRL_CAP_VS18_MASK))
    {
        /* HS400 only runs in 1.8V mode */
        Status = Sd_Ip_SwitchToHS400(Config);
    }
    #endif

    /* Switch speed to DDR52 if failing to change to HS400 */
    if ((Sd_Emmc_Ip_StatusType)SD_IP_STATUS_SUCCESS != Status)
    {
        /* Configure data bus width to 8 bits for USDHC host */
        uSDHC_Ip_SetDataBusWidth(Config->usdhcConfig->instance, USDHC_DATA_BUS_WIDTH_8BIT);
        /* Change bus width to 8 bit for MMC device by sending CMD6 */
        if ((Sd_Emmc_Ip_StatusType)SD_IP_STATUS_SUCCESS != Sd_Ip_MmcSwitch(Config, MMCCWriteBits, (uint8)183U, MMCBusWidth8))
        {
            Status = SD_IP_STATUS_SWITCH_FAILED;
        }
        else
        {
            /* Switch device speed to high speed mode */
            Status = Sd_Ip_MmcSwitch(Config, MMCCWriteBits, (uint8)185U, MMCHightSpeed);
        }

        if ((Sd_Emmc_Ip_StatusType)SD_IP_STATUS_SUCCESS == Status)
        {
            Status = Sd_Ip_SwitchToDDR52(Config, MMCBusWidth8ddr);
        }
    }

    return Status;
}

/**
* @brief         Sd_Ip_IncreaseMmcBusSpeed
* @details       Improve the speed for MMC card by increasing
* the bus speed, changing the power class to
* support more current and setting the bus to 4 bits or 8 bits.
*
* @param[in]     Config Card descriptor.
*
* @return        Status    
* @pre           The USDHC driver needs to be initialized.
*/
static Sd_Emmc_Ip_StatusType Sd_Ip_IncreaseMmcBusSpeed(const Sd_Emmc_Ip_ConfigType *Config)
{
    Sd_Emmc_Ip_StatusType Status = (Sd_Emmc_Ip_StatusType)SD_IP_STATUS_SUCCESS;

    /* Read the Ext_csd register */
    Status = Sd_Ip_MmcSendExtCsd(Config);
    /* Get the card capabilities information from Extended CSD register */
    if ((Sd_Emmc_Ip_StatusType)SD_IP_STATUS_SUCCESS == Status)
    {
        Sd_Ip_MmcGetCapabilities();
    }

    switch (Config->busWidthMode)
    {
        case SD_IP_DATABUSWIDTH_4BIT:
            Status = Sd_Ip_IncreaseMmcBusSpeed4Bit(Config);
            break;

        case SD_IP_DATABUSWIDTH_8BIT:
            Status = Sd_Ip_IncreaseMmcBusSpeed8Bit(Config);
            break;

        case SD_IP_DATABUSWIDTH_4BIT_DDR:
            Status = Sd_Ip_IncreaseMmcBusSpeed4BitDDR(Config);
            break;

        case SD_IP_DATABUSWIDTH_8BIT_DDR:
            Status = Sd_Ip_IncreaseMmcBusSpeed8BitDDR(Config);
            break;

        default:
            /* Do nothing */
            break;
    }

    if ((Sd_Emmc_Ip_StatusType)SD_IP_STATUS_SUCCESS == Status)
    {
        /* Switch power class */
        Status = Sd_Ip_MmcSwitch(Config, MMCCWriteBits, (uint8)187U, MMCPowerClass700);
    }

    if ((Sd_Emmc_Ip_StatusType)SD_IP_STATUS_SUCCESS == Status)
    {
        /* Update the Ext_csd register for storing card runtime information */
        Status = Sd_Ip_MmcSendExtCsd(Config);
    }

    return Status;
}

/**
* @brief         Sd_Ip_SetCmd41Argument
* @details       Set argument value for ACMD41.
*
* @param[in]     Config Card descriptor.
*
* @return        void    
* @pre           The USDHC driver needs to be initialized.
*/
static void Sd_Ip_SetCmd41Argument(const Sd_Emmc_Ip_ConfigType *Config)
{
#if (USDHC_IP_V330_SUPPORT == STD_ON)
    if (0U != (Sd_Emmc_Ip_Capability[Config->usdhcConfig->instance].flags & (uint32)USDHC_HOST_CTRL_CAP_VS33_MASK))
    {
        Sd_Emmc_Ip_u32AppCmd41Argument |= ((uint32)aSD_OcrVdd32_33Flag | (uint32)aSD_OcrVdd33_34Flag);
    }
#endif /* USDHC_IP_V330_SUPPORT */

#if (USDHC_IP_V300_SUPPORT == STD_ON)
    if (0U != ((Sd_Emmc_Ip_Capability[Config->usdhcConfig->instance].flags) & (uint32)USDHC_HOST_CTRL_CAP_VS30_MASK))
    {
        Sd_Emmc_Ip_u32AppCmd41Argument |= (uint32)aSD_OcrVdd29_30Flag;
    }
#endif /* USDHC_IP_V300_SUPPORT */

    if (SD_IP_MEMORY_CARD_SD == Sd_Emmc_Ip_eCardTypeInfo)
    {
        /* SDHC or SDXC card */
        Sd_Emmc_Ip_u32AppCmd41Argument |= (uint32)aSD_OcrHostCapacitySupportFlag;
        Sd_Emmc_Ip_u32AppCmd41Argument |= (uint32)aSD_OcrSwitchSDXCPowerControlFlag;
        Sd_Emmc_Ip_u32CardFlags        |= (uint16)SD_IP_SUPPORT_SDHC_FLAG;

#if (USDHC_IP_V180_SUPPORT == STD_ON)
        if (0U != (Sd_Emmc_Ip_Capability[Config->usdhcConfig->instance].flags & (uint32)USDHC_HOST_CTRL_CAP_VS18_MASK))
        {
            Sd_Emmc_Ip_u32AppCmd41Argument |= (uint32)aSD_OcrSwitch18RequestFlag;
        }
#endif /* USDHC_IP_V180_SUPPORT */
    }

#if ((USDHC_IP_V330_SUPPORT == STD_OFF) && (USDHC_IP_V300_SUPPORT == STD_OFF) && (USDHC_IP_V180_SUPPORT == STD_OFF))
    (void)Config;
#endif

}

/**
* @brief         Sd_Ip_SdSwitchSpeed
* @details       Switch to high speed for SD card type.
*
* @param[in]     Config Card descriptor.
*
* @return        Status    
* @pre           The USDHC driver needs to be initialized.
*/
static Sd_Emmc_Ip_StatusType Sd_Ip_SdSwitchSpeed(const Sd_Emmc_Ip_ConfigType *Config)
{
    Sd_Emmc_Ip_StatusType Status;

    Status = Sd_Ip_SwitchHighSpeed(Config);
    if ((Sd_Emmc_Ip_StatusType)SD_IP_STATUS_SUCCESS == Status)
    {
        Status = Sd_Ip_SetBlockSize(Config, SD_IP_SDMMC_DEFAULT_BLOCK_SIZE);
    }

    return Status;
}


/**
* @brief         Sd_Ip_MmcSwitchSpeed
* @details       Switch to high speed for eMMC card type.
*
* @param[in]     Config Card descriptor.
*
* @return        Status    
* @pre           The USDHC driver needs to be initialized.
*/
static Sd_Emmc_Ip_StatusType Sd_Ip_MmcSwitchSpeed(const Sd_Emmc_Ip_ConfigType *Config)
{
    Sd_Emmc_Ip_StatusType Status = SD_IP_STATUS_SUCCESS;

    if(Sd_Emmc_Ip_u32VersionInfo >= 4U)
    {
        Status = Sd_Ip_IncreaseMmcBusSpeed(Config);
    }
    else
    {
        if (STATUS_USDHC_IP_SUCCESS != uSDHC_Ip_SetBusClock(Config->usdhcConfig->instance, Config->u32McuClock, SD_CLOCK_50MHZ, &(Sd_Emmc_Ip_u32BusClockInfo)))
        {
            Status = SD_IP_STATUS_ERROR;
        }
    }

    return Status;
}

/**
* @brief         Sd_Ip_SendEraseBlockStart
* @details       Send commands to card to inform the start block to erase.
*
* @param[in]     Config Card descriptor.
*
* @return        Status    
* @pre           The SD driver needs to be initialized.
*/
static Sd_Emmc_Ip_StatusType Sd_Ip_SendEraseBlockStart(const Sd_Emmc_Ip_ConfigType *Config, uint32 EraseBlockStart)
{
    Sd_Emmc_Ip_StatusType Status = SD_IP_STATUS_SUCCESS;

    /* Send ERASE_WRITE_BLOCK_START command to set the start block number to erase. */
    Sd_Emmc_Ip_TransferStorage.command.index = (uint32)aSD_EraseWriteBlockStart;

    if (SD_IP_MEMORY_CARD_MMC == Sd_Emmc_Ip_eCardTypeInfo)
    {
        Sd_Emmc_Ip_TransferStorage.command.index = (uint32)aMMC_EraseGroupStart;
    }
    /* Set argument for command */
    Sd_Emmc_Ip_TransferStorage.command.argument     = EraseBlockStart;
    /* Set type of response */
    Sd_Emmc_Ip_TransferStorage.command.responseType = USDHC_RESPONSE_TYPE_R1;

    Sd_Emmc_Ip_TransferStorage.content.command      = &Sd_Emmc_Ip_TransferStorage.command;
    Sd_Emmc_Ip_TransferStorage.content.data         = NULL_PTR;

    /* Start transfer and check response */
    if ((STATUS_USDHC_IP_SUCCESS != uSDHC_Ip_Transfer(Config->usdhcConfig->instance, &Sd_Emmc_Ip_TransferStorage.content, (boolean)FALSE)) ||  \
            (0U != ((Sd_Emmc_Ip_TransferStorage.command.response[0U]) & (uint32)SD_IP_R1_ALL_ERROR_FLAGS)))
    {
        Status = (Sd_Emmc_Ip_StatusType)SD_IP_STATUS_TRANSFER_FAILED;
    }

    return Status;
}

/**
* @brief         Sd_Ip_SendEraseBlockEnd
* @details       Send commands to card to inform the last block to erase.
*
* @param[in]     Config Card descriptor.
* @param[in]     EraseBlockStart Index of the last block to erase.
*
* @return        Status    
* @pre           The SD driver needs to be initialized.
*/
static Sd_Emmc_Ip_StatusType Sd_Ip_SendEraseBlockEnd(const Sd_Emmc_Ip_ConfigType *Config, uint32 EraseBlockEnd)
{
    Sd_Emmc_Ip_StatusType Status = SD_IP_STATUS_SUCCESS;

    /* Send ERASE_WRITE_BLOCK_END command to set the end block number to erase. */
    Sd_Emmc_Ip_TransferStorage.command.index = (uint32)aSD_EraseWriteBlockEnd;
    if (SD_IP_MEMORY_CARD_MMC == Sd_Emmc_Ip_eCardTypeInfo)
    {
        Sd_Emmc_Ip_TransferStorage.command.index = (uint32)aMMC_EraseGroupEnd;
    }

    Sd_Emmc_Ip_TransferStorage.command.argument = EraseBlockEnd;

    Sd_Emmc_Ip_TransferStorage.content.command  = &Sd_Emmc_Ip_TransferStorage.command;
    Sd_Emmc_Ip_TransferStorage.content.data     = NULL_PTR;

    if ((STATUS_USDHC_IP_SUCCESS != uSDHC_Ip_Transfer(Config->usdhcConfig->instance, &Sd_Emmc_Ip_TransferStorage.content, (boolean)FALSE)) ||  \
            (0U != ((Sd_Emmc_Ip_TransferStorage.command.response[0U]) & (uint32)SD_IP_R1_ALL_ERROR_FLAGS)))
    {
        Status = (Sd_Emmc_Ip_StatusType)SD_IP_STATUS_TRANSFER_FAILED;
    }

    return Status;
}

/**
* @brief         Sd_Emmc_Ip_EnterIdentificationMode
* @details       Initialize the host controller to default configuration and switch to Identification mode
*
* @return        Status
* @pre           The USDHC driver needs to be initialized.
*/
static Sd_Emmc_Ip_StatusType Sd_Emmc_Ip_EnterIdentificationMode(const Sd_Emmc_Ip_ConfigType *Config)
{
    Sd_Emmc_Ip_StatusType Status;
    Usdhc_Ip_StatusType ControllerStatus;

    /* Set bus width to 1-bit */
    uSDHC_Ip_SetDataBusWidth(Config->usdhcConfig->instance, USDHC_DATA_BUS_WIDTH_1BIT);

    /* Set bus clock to 100KHz */
    ControllerStatus = uSDHC_Ip_SetBusClock(Config->usdhcConfig->instance, Config->u32McuClock, SDMMC_CLOCK_100KHZ, &(Sd_Emmc_Ip_u32BusClockInfo));

    /* Switch Voltage to 3V3 */
    if (STATUS_USDHC_IP_SUCCESS == ControllerStatus)
    {
        ControllerStatus = uSDHC_Ip_SwitchVoltage(Config->usdhcConfig->instance, FALSE);
    }

    /* Send 80 clock cycles to card to activate the card */
    if (STATUS_USDHC_IP_SUCCESS == ControllerStatus)
    {
        ControllerStatus = uSDHC_Ip_SetCardActive(Config->usdhcConfig->instance);
    }

    /* Send GO_IDLE command to enter idle state */
    if (STATUS_USDHC_IP_SUCCESS == ControllerStatus)
    {
        Status = Sd_Ip_GoIdle(Config);
    }
    else
    {
        Status = (Sd_Emmc_Ip_StatusType)SD_IP_STATUS_TIMEOUT;
    }

    return Status;
}

/**
* @brief         Sd_Emmc_Ip_EnterDataTransferMode
* @details       Switch card to Data transfer mode and increase the data speed
*
* @return        Status
* @pre           The USDHC driver needs to be initialized.
*/
static Sd_Emmc_Ip_StatusType Sd_Emmc_Ip_EnterDataTransferMode(const Sd_Emmc_Ip_ConfigType *Config)
{
    Sd_Emmc_Ip_StatusType Status;

    /* Send RCA command */
    Status = Sd_Ip_SwitchToDataTransfer(Config);

    if ((Sd_Emmc_Ip_StatusType)SD_IP_STATUS_SUCCESS == Status)
    {
        /* Increase bus speed */
        switch (Sd_Emmc_Ip_eCardTypeInfo)
        {
            case SD_IP_MEMORY_CARD_SD:
                Status = Sd_Ip_SdSwitchSpeed(Config);
                if ((Sd_Emmc_Ip_StatusType)SD_IP_STATUS_SUCCESS != Status)
                {
                    Status = (Sd_Emmc_Ip_StatusType)SD_IP_STATUS_SET_CARD_BLOCK_SIZE_FAILED;
                }
                break;

            case SD_IP_MEMORY_CARD_MMC:
                Status = Sd_Ip_MmcSwitchSpeed(Config);
                break;

            default:
                Status = (Sd_Emmc_Ip_StatusType)SD_IP_STATUS_NOT_SUPPORTED;
                break;
        }
    }

    return Status;
}

/**
* @brief         Sd_Emmc_Ip_InitPreCheck
* @details       Prepare for the initialization sequence
*
* @return        void
* @pre           The USDHC driver needs to be initialized.
*/
static void Sd_Emmc_Ip_InitPreCheck(const Sd_Emmc_Ip_ConfigType *Config)
{
    /* Check the validity of the input parameters */
    SD_IP_DEV_ASSERT(Config != NULL_PTR);

    Sd_Emmc_InitAllVarriable();

    /* Reseting relative address of the card*/
    Sd_Emmc_Ip_u32RelativeAddress = 0U;

    /* Store information of Sd_Ip_CardFlagType*/
    Sd_Emmc_Ip_u32CardFlags = Config->flags;
    /* Store information card type */
    Sd_Emmc_Ip_eCardTypeInfo = Config->cardType;
    /*
    * Enable auto CMD12. If this field is false, user have to send a "CMD12" command to card after each time send/receive data to stop the data transfer.
    * If this field is true, uSDHC will send "CMD12" command automatically after data transfer is end
    */
    Sd_Emmc_Ip_TransferStorage.data.enableAutoCMD12 = Config->usdhcConfig->EnableAutoCMD12;
}

#if (STD_ON == SD_IP_MMC_CONFIG_BOOT_ENABLED)
/**
** Configure extended CSD register for boot operation
 *
*/
static Sd_Emmc_Ip_StatusType Sd_Emmc_Ip_MmcConfigBootMode(const Sd_Emmc_Ip_ConfigType *Sd_Ip_pConfig)
{
    Sd_Emmc_Ip_StatusType status = (Sd_Emmc_Ip_StatusType)SD_IP_STATUS_SUCCESS;
    uint32 BootPartitionconfig = 0U;
    uint32 BootConditionconfig = 0U;

    /* Configure ACK enable/disable, partition seclection for boot operation */
    if((boolean)TRUE == Sd_Ip_pConfig->mmcBootConfig->ackEnable)
    {
        BootPartitionconfig = MMC_PARTITION_CONFIG_ACK(1U);
    }
    BootPartitionconfig |= MMC_PARTITION_CONFIG_ENABLE(Sd_Ip_pConfig->mmcBootConfig->bootPartitionSelect);

    status = Sd_Ip_MmcSwitch(Sd_Ip_pConfig, MMCCWriteBits, (uint8)MMC_EXT_CSD_INDEX_PARTITION_CONFIG, BootPartitionconfig<< 8);

    if ((Sd_Emmc_Ip_StatusType)SD_IP_STATUS_SUCCESS == status)
    {
        /* Get extended CSD */
        status = Sd_Ip_MmcSendExtCsd(Sd_Ip_pConfig);
    }

    /* Select boot mode for boot operation */
    if ((Sd_Emmc_Ip_StatusType)SD_IP_STATUS_SUCCESS == status)
    {
        /*Check the MMC card support High speed and DDR or not*/
        if(((Sd_Ip_pConfig->mmcBootConfig->bootSpeed == SD_IP_MMCBOOT_SDR_HIGH_SPEED) && (((Sd_Emmc_Ip_MmcECsr.bootInformation & MMC_HS_BOOT_MODE_MASK ) >> MMC_HS_BOOT_MODE_SHIFT) == 0U)) || \
           ((Sd_Ip_pConfig->mmcBootConfig->bootSpeed == SD_IP_MMCBOOT_DDR) && (((Sd_Emmc_Ip_MmcECsr.bootInformation & MMC_DDR_BOOT_MODE_MASK ) >> MMC_DDR_BOOT_MODE_SHIFT) == 0U)) \
          )
        {
            status = SD_IP_STATUS_SWITCH_FAILED;
        }
        else
        {
            BootConditionconfig = MMC_BOOT_MODE(Sd_Ip_pConfig->mmcBootConfig->bootSpeed) << 8U;
        }
    }

    /* Configure bus width for boot operation according to Usdhc configuration */
    if ((Sd_Emmc_Ip_StatusType)SD_IP_STATUS_SUCCESS == status)
    {
        switch (Sd_Ip_pConfig->mmcBootConfig->bootWidth)
        {
            case SD_IP_MMCBOOT_DBW_4BIT:
                /* Increase bus width to 4bit */
                BootConditionconfig |= MMCBusWidth4;
                break;
            case SD_IP_MMCBOOT_DBW_8BIT:
                /* Increase bus width to 8bit */
                BootConditionconfig |= MMCBusWidth8;
                break;
            default:
                /* 1-bit bus width */
                BootConditionconfig |= MMCBusWidth1;
                break;
        }
            status = Sd_Ip_MmcSwitch(Sd_Ip_pConfig, MMCCWriteBits, (uint8)MMC_EXT_CSD_INDEX_BOOT_BUS_CONDITIONS, BootConditionconfig);
    }
    return status;
}
#endif
/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/
/**
* @brief         Sd_Emmc_Ip_Init
* @details       Initialize the card on a specific host controller.
*
* @param[in]     Config Card descriptor.
*
* @return        Status    
* @pre           The USDHC driver needs to be initialized.
*/
/* implements Sd_Emmc_Ip_Init_Activity */
Sd_Emmc_Ip_StatusType Sd_Emmc_Ip_Init(const Sd_Emmc_Ip_ConfigType *Config)
{
    Sd_Emmc_Ip_StatusType Status;

    /* Prepare for the initialization sequence */ 
    Sd_Emmc_Ip_InitPreCheck(Config);

    /* Enter Identification mode */
    Status = Sd_Emmc_Ip_EnterIdentificationMode(Config);

    if ((Sd_Emmc_Ip_StatusType)SD_IP_STATUS_SUCCESS == Status)
    {
        #ifdef USDHC_PRES_STATE_WPSPL_MASK
        if (0U == (uSDHC_Ip_GetPresentStatusFlags(Config->usdhcConfig->instance) & (uint32)USDHC_PRES_STATE_WPSPL_MASK))
        {
            Sd_Emmc_Ip_u32CardFlags |= (uint32)SD_IP_WRITE_PROTECT_FLAG;
        }
        #endif

        /* Hand-shaking with card to validate the interface voltage range. */
        /* Get host capability. */
        uSDHC_Ip_GetCapability(Config->usdhcConfig->instance, &(Sd_Emmc_Ip_Capability[Config->usdhcConfig->instance]));
        /* Check card's supported interface condition. */
        Status = Sd_Ip_SendInterfaceCondition(Config);
    }

    if ((Sd_Emmc_Ip_StatusType)SD_IP_STATUS_SUCCESS != Status)
    {
        /* Not supported cards(SDSC & MMC) */
        Status = Sd_Ip_GoIdle(Config);
    }

    if ( ((Sd_Emmc_Ip_StatusType)SD_IP_STATUS_SUCCESS == Status) && (SD_IP_MEMORY_CARD_SD == Sd_Emmc_Ip_eCardTypeInfo) )
    {
        Sd_Ip_SetCmd41Argument(Config);

        /* Set card interface condition according to SDHC capability and card's supported interface condition. */
        Status = Sd_Ip_ApplicationSendOperationCondition(Config, Sd_Emmc_Ip_u32AppCmd41Argument);
        if ((Sd_Emmc_Ip_StatusType)SD_IP_STATUS_TIMEOUT == Status)
        {
            /* MMC card */
            Status = (Sd_Emmc_Ip_StatusType)SD_IP_STATUS_NOT_SUPPORTED;
        }
        else if ((Sd_Emmc_Ip_StatusType)SD_IP_STATUS_SUCCESS != Status)
        {
            Status = (Sd_Emmc_Ip_StatusType)SD_IP_STATUS_HANDSHAKE_OP_FAILED;
        }
        else
        {
            /* In case SD_IP_STATUS_SUCCESS */
            #if (USDHC_IP_V180_SUPPORT == STD_ON)
            Status = Sd_Ip_SwitchVoltage(Config);
            #endif
        }
    }

    /* Enter Data transfer mode and increase bus clock */
    if ((Sd_Emmc_Ip_StatusType)SD_IP_STATUS_SUCCESS == Status)
    {
        Status = Sd_Emmc_Ip_EnterDataTransferMode(Config);
    }

#if (STD_ON == SD_IP_MMC_CONFIG_BOOT_ENABLED)
    /* Configure for Boot Mode , only support for eMMC card */
    if ( ((Sd_Emmc_Ip_StatusType)SD_IP_STATUS_SUCCESS == Status) && (SD_IP_MEMORY_CARD_MMC == Sd_Emmc_Ip_eCardTypeInfo) )
    {
        Status = Sd_Emmc_Ip_MmcConfigBootMode(Config);
    }
#endif

    /* Checking if timeout occurs */
    if ((boolean)TRUE == Usdhc_Ip_bFailedTimeout)
    {
        Status = SD_IP_STATUS_TIMEOUT;
        Usdhc_Ip_bFailedTimeout = (boolean)FALSE;
    }

    return Status;
}

/**
* @brief         Sd_Emmc_Ip_DeInit
* @details       This function deinitializes the specific card.
*
* @param[in]     Config Card descriptor.
*
* @return        Status    
* @pre           The SD driver needs to be initialized.
*/
/* implements Sd_Emmc_Ip_DeInit_Activity */
Sd_Emmc_Ip_StatusType Sd_Emmc_Ip_DeInit(const Sd_Emmc_Ip_ConfigType *Config)
{
    /* Check the validity of the input parameters */
    SD_IP_DEV_ASSERT(Config != NULL_PTR);
    Sd_Emmc_Ip_StatusType Status;


    Status = Sd_Ip_SelectCard(Config, FALSE);

    if ((Sd_Emmc_Ip_StatusType)SD_IP_STATUS_SUCCESS == Status)
    {
        Status = Sd_Ip_GoIdle(Config);
    }

    uSDHC_Ip_SetDataBusWidth(Config->usdhcConfig->instance, USDHC_DATA_BUS_WIDTH_1BIT);
    return Status;
}

/**
* @brief         Sd_Emmc_Ip_CheckReadOnly
* @details       This function checks if the card is write-protected via CSD register or WP pin.
*
* @param[in]     Config Card descriptor.
*
* @return        ReadOnly Card is read only or not    
* @pre           The SD driver needs to be initialized.
*/
boolean Sd_Emmc_Ip_CheckReadOnly(void)
{
    boolean ReadOnly = FALSE;

    if (0U != (Sd_Emmc_Ip_u32CardFlags & (uint32)SD_IP_WRITE_PROTECT_FLAG))
    {
        ReadOnly = TRUE;
    }

    if (0U != (Sd_Emmc_Ip_Csd.flags & (uint16)SD_IP_CSD_PERMANENT_WRITE_PROTECT_FLAG))
    {
        ReadOnly = TRUE;
    }

    if (0U != (Sd_Emmc_Ip_Csd.flags & (uint16)SD_IP_CSD_TEMPORARY_WRITE_PROTECT_FLAG))
    {
        ReadOnly = TRUE;
    }

    return ReadOnly;
}

/**
* @brief         Sd_Emmc_Ip_ReadBlocks
* @details       This function reads blocks from specific card, with default block size defined by SDHC_CARD_DEFAULT_BLOCK_SIZE.
*
* @param[in]     Config     The card configuration.
* @param[in]     Buffer     The buffer to save the data read from card.
* @param[in]     StartBlock The start block index.
* @param[in]     BlockCount The number of blocks to read.
*
* @return        Status
* @pre           The SD driver needs to be initialized.
*/
/* implements Sd_Emmc_Ip_ReadBlocks_Activity */
Sd_Emmc_Ip_StatusType Sd_Emmc_Ip_ReadBlocks(const Sd_Emmc_Ip_ConfigType *Config, uint8 *Buffer, uint32 StartBlock, uint32 BlockCount)
{
    /* Check the validity of the input parameters */
    SD_IP_DEV_ASSERT(Config != NULL_PTR);
    SD_IP_DEV_ASSERT(Buffer != NULL_PTR);
    SD_IP_DEV_ASSERT(BlockCount != 0U);
    uint32 BlockCountOneTime;
    uint32 BlockLeft;
    uint32 BlockDone;
    uint32 u32bootSize = 0;

    /* Check if number of writing blocks exceeds boot partition size */
    if((SD_IP_MMC_PARTITION_BOOT_1 == mmcPartitionState) || (SD_IP_MMC_PARTITION_BOOT_2 == mmcPartitionState))
    {
        /* Calculate total boot partition size in SD_IP_SDMMC_DEFAULT_BLOCK_SIZE unit, bootSizeMulti*128*1024/SD_IP_SDMMC_DEFAULT_BLOCK_SIZE */
        u32bootSize = (uint32)((uint32)Sd_Emmc_Ip_MmcECsr.bootSizeMultiplier << 17U)/SD_IP_SDMMC_DEFAULT_BLOCK_SIZE;
        if(BlockCount > u32bootSize)
        {
            Sd_Emmc_Ip_eJobState = SD_IP_STATUS_ERROR;
        }
    }

    /* If end block is greater than card capability */
    if ((BlockCount + StartBlock) > Sd_Emmc_Ip_u32BlockCountInfo)
    {
        Sd_Emmc_Ip_eJobState = (Sd_Emmc_Ip_StatusType)SD_IP_STATUS_ERROR;
    }
    else
    {
        BlockLeft = BlockCount;
        BlockDone = 0U;
        /* Read all block until finished */
        while (BlockLeft != 0U)
        {
            /* If remaning blocks is greater than maximum blocks can be read at one time */
            if (BlockLeft > Sd_Emmc_Ip_Capability[Config->usdhcConfig->instance].maxBlockCount)
            {
                BlockLeft = (BlockLeft - Sd_Emmc_Ip_Capability[Config->usdhcConfig->instance].maxBlockCount);
                BlockCountOneTime = Sd_Emmc_Ip_Capability[Config->usdhcConfig->instance].maxBlockCount;
            }
            else
            {
                BlockCountOneTime = BlockLeft;
                BlockLeft = 0U;
            }
            /* Read block */
            Sd_Emmc_Ip_eJobState = Sd_Ip_Read(Config,
                                              (uint8 *)&Buffer[(BlockDone * SD_IP_SDMMC_DEFAULT_BLOCK_SIZE)],
                                              StartBlock + BlockDone,
                                              SD_IP_SDMMC_DEFAULT_BLOCK_SIZE,
                                              BlockCountOneTime
                                             );

            /* If error occurred */
            if ((Sd_Emmc_Ip_StatusType)SD_IP_STATUS_SUCCESS != Sd_Emmc_Ip_eJobState)
            {
                break;
            }
            /* Calculate BlockDone for next read operation */
            BlockDone += BlockCountOneTime;
        }
    }

    return Sd_Emmc_Ip_eJobState;
}

/**
* @brief         Sd_Emmc_Ip_CalcBlockCountOneTransfer
* @details       Calculate the maximum block count for each write transaction
*
* @return        void
* @pre           The SD driver needs to be initialized.
*/
static void Sd_Emmc_Ip_CalcBlockCountOneTransfer(const Sd_Emmc_Ip_ConfigType *Config)
{
    if (Sd_Emmc_Ip_u32TempblockCount > Sd_Emmc_Ip_Capability[Config->usdhcConfig->instance].maxBlockCount)
    {
        Sd_Emmc_Ip_u32TempblockCount        = (Sd_Emmc_Ip_u32TempblockCount - Sd_Emmc_Ip_Capability[Config->usdhcConfig->instance].maxBlockCount);
        Sd_Emmc_Ip_u32BlockCountOneTransfer = Sd_Emmc_Ip_Capability[Config->usdhcConfig->instance].maxBlockCount;
    }
    else
    {
        Sd_Emmc_Ip_u32BlockCountOneTransfer = Sd_Emmc_Ip_u32TempblockCount;
        Sd_Emmc_Ip_u32TempblockCount        = 0U;
    }
}


/**
* @brief         Sd_Emmc_Ip_WriteBlocks
* @details       This function writes blocks to specific card, with default block size 512 bytes.
*
* @param[in]     card       The card descriptor.   
* @param[in]     Buffer     The Buffer holding the data to be written to the card.   
* @param[in]     StartBlock The start block index.   
* @param[in]     BlockCount The number of blocks to write.   
*
* @return        Status
* @pre           The SD driver needs to be initialized.
*/
/* implements Sd_Emmc_Ip_WriteBlocks_Activity */
Sd_Emmc_Ip_StatusType Sd_Emmc_Ip_WriteBlocks(const Sd_Emmc_Ip_ConfigType *Config, const uint8 *Buffer, uint32 StartBlock, uint32 BlockCount, boolean AsyncEnable)
{
    uint32 u32bootSize = 0;

    /* Check the validity of the input parameters */
    SD_IP_DEV_ASSERT(Config != NULL_PTR);
    SD_IP_DEV_ASSERT(Buffer != NULL_PTR);
    SD_IP_DEV_ASSERT(BlockCount != 0U);

    /* Check if number of writing blocks exceeds boot partition size */
    if((SD_IP_MMC_PARTITION_BOOT_1 == mmcPartitionState) || (SD_IP_MMC_PARTITION_BOOT_2 == mmcPartitionState))
    {
        /* Calculate total boot partition size in SD_IP_SDMMC_DEFAULT_BLOCK_SIZE unit, bootSizeMulti*128*1024/SD_IP_SDMMC_DEFAULT_BLOCK_SIZE */
        u32bootSize = (uint32)((uint32)Sd_Emmc_Ip_MmcECsr.bootSizeMultiplier << 17U)/SD_IP_SDMMC_DEFAULT_BLOCK_SIZE;
        if(BlockCount > u32bootSize)
        {
            Sd_Emmc_Ip_eJobState = SD_IP_STATUS_ERROR;
        }
    }

    /* Those variables will be setup once before starting operations */
    if (TRUE == Sd_Emmc_Ip_bFirstTimeTransfer)
    {
        Sd_Emmc_Ip_eJobState = SD_IP_STATUS_SUCCESS;
        Sd_Emmc_Ip_u32TempblockCount = BlockCount;
        Sd_Emmc_Ip_u32BlockDone = 0U;
        Sd_Emmc_Ip_u32BlockCountOneTransfer = 0U;
        /* Reset this variable*/
        Sd_Emmc_Ip_bFirstTimeTransfer = FALSE;
    }
    if ((BlockCount + StartBlock) > Sd_Emmc_Ip_u32BlockCountInfo)
    {
        Sd_Emmc_Ip_eJobState = (Sd_Emmc_Ip_StatusType)SD_IP_STATUS_ERROR;
    }
    else
    {
        if ((boolean)FALSE == AsyncEnable)
        {
            Sd_Emmc_Ip_WriteBlocksBlocking(Config, Buffer, StartBlock);
        }
        else
        {
            Sd_Emmc_Ip_WriteBlocksNonBlocking(Config, Buffer, StartBlock);
        }
    }

    return Sd_Emmc_Ip_eJobState;
}


static void Sd_Emmc_Ip_WriteBlocksBlocking(const Sd_Emmc_Ip_ConfigType *Config, const uint8 *Buffer, uint32 StartBlock)
{
    while (Sd_Emmc_Ip_u32TempblockCount != 0U)
    {
        Sd_Emmc_Ip_CalcBlockCountOneTransfer(Config);

        Sd_Emmc_Ip_eJobState = Sd_Ip_Write(Config,
                                           &Buffer[(Sd_Emmc_Ip_u32BlockDone * SD_IP_SDMMC_DEFAULT_BLOCK_SIZE)],
                                           (StartBlock + Sd_Emmc_Ip_u32BlockDone),
                                           Sd_Emmc_Ip_u32BlockCountOneTransfer,
                                           (boolean)FALSE
                                          );

        if ((Sd_Emmc_Ip_StatusType)SD_IP_STATUS_SUCCESS != Sd_Emmc_Ip_eJobState)
        {
            break;
        }
        Sd_Emmc_Ip_u32BlockDone += Sd_Emmc_Ip_u32BlockCountOneTransfer;
    }
    /* Reset this variable to next operation */
    Sd_Emmc_Ip_bFirstTimeTransfer = TRUE;
}


static void Sd_Emmc_Ip_WriteBlocksNonBlocking(const Sd_Emmc_Ip_ConfigType *Config, const uint8 *Buffer, uint32 StartBlock)
{
    if ((SD_IP_STATUS_SUCCESS == Sd_Emmc_Ip_eJobState) || (SD_IP_STATUS_PENDING == Sd_Emmc_Ip_eJobState))
    {
        if ( SD_IP_STATUS_SUCCESS == Sd_Emmc_Ip_eJobState)
        {
            Sd_Emmc_Ip_CalcBlockCountOneTransfer(Config);
        }
        /* Async mode will be polling until the write is done */
        Sd_Emmc_Ip_eJobState = Sd_Ip_Write(Config,
                                           &Buffer[(Sd_Emmc_Ip_u32BlockDone * SD_IP_SDMMC_DEFAULT_BLOCK_SIZE)],
                                           (StartBlock + Sd_Emmc_Ip_u32BlockDone),
                                           Sd_Emmc_Ip_u32BlockCountOneTransfer,
                                           (boolean)TRUE
                                          );

        /* Work is done when all data is writen and job is successful  */
        if ((Sd_Emmc_Ip_u32TempblockCount == 0U) && (SD_IP_STATUS_SUCCESS == Sd_Emmc_Ip_eJobState))
        {
            Sd_Emmc_Ip_eJobState = SD_IP_STATUS_SUCCESS;
            Sd_Emmc_Ip_bFirstTimeTransfer = TRUE;
        }
        /* There is still data to write, so call Sd_Ip_Write with the next block */
        else if ((Sd_Emmc_Ip_u32TempblockCount > 0U) && (SD_IP_STATUS_SUCCESS == Sd_Emmc_Ip_eJobState))
        {
            Sd_Emmc_Ip_u32BlockDone += Sd_Emmc_Ip_u32BlockCountOneTransfer;

            /* Calculate again Sd_Emmc_Ip_u32TempblockCount */
            Sd_Emmc_Ip_CalcBlockCountOneTransfer(Config);

            /* Continues to write */
            Sd_Emmc_Ip_eJobState = Sd_Ip_Write(Config,
                                               &Buffer[(Sd_Emmc_Ip_u32BlockDone * SD_IP_SDMMC_DEFAULT_BLOCK_SIZE)],
                                               (StartBlock + Sd_Emmc_Ip_u32BlockDone),
                                               Sd_Emmc_Ip_u32BlockCountOneTransfer,
                                               (boolean)TRUE
                                              );
        }
        else if ((SD_IP_STATUS_PENDING == Sd_Emmc_Ip_eJobState))
        {
            /* Do nothing - working is on-going and waiting for finishing */
        }
        else
        {
            /* Working is not successful */
            Sd_Emmc_Ip_bFirstTimeTransfer = TRUE;
        }
    }
    else
    {
        /* Working is not successful */
        Sd_Emmc_Ip_bFirstTimeTransfer = TRUE;
    }
}


/**
* @brief         Sd_Emmc_Ip_EraseBlocks
* @details       This function erases blocks of a specific card, with default block size 512 bytes.
*
* @param[in]     card The card descriptor.
* @param[in]     StartBlock The start block index.
* @param[in]     BlockCount The number of blocks to erase.
*
* @return        Status
* @pre           The SD driver needs to be initialized.
*/
/* implements Sd_Emmc_Ip_EraseBlocks_Activity */
Sd_Emmc_Ip_StatusType Sd_Emmc_Ip_EraseBlocks(const Sd_Emmc_Ip_ConfigType *Config, uint32 StartBlock, uint32 BlockCount, boolean AsyncEnable)
{
    /* Check the validity of the input parameters */
    SD_IP_DEV_ASSERT(Config != NULL_PTR);
    SD_IP_DEV_ASSERT(BlockCount != 0U);
    uint32 u32bootSize = 0;

    /* Check if number of writing blocks exceeds boot partition size */
    if((SD_IP_MMC_PARTITION_BOOT_1 == mmcPartitionState) || (SD_IP_MMC_PARTITION_BOOT_2 == mmcPartitionState))
    {
        /* Calculate total boot partition size in SD_IP_SDMMC_DEFAULT_BLOCK_SIZE unit, bootSizeMulti*128*1024/SD_IP_SDMMC_DEFAULT_BLOCK_SIZE */
        u32bootSize = (uint32)((uint32)Sd_Emmc_Ip_MmcECsr.bootSizeMultiplier << 17U)/SD_IP_SDMMC_DEFAULT_BLOCK_SIZE;
        if(BlockCount > u32bootSize)
        {
            Sd_Emmc_Ip_eJobState = SD_IP_STATUS_ERROR;
        }
    }
    /* Those variables will be setup once before starting operations */
    if (TRUE == Sd_Emmc_Ip_bFirstTimeTransfer)
    {
        Sd_Emmc_Ip_eJobState = SD_IP_STATUS_SUCCESS;
        Sd_Emmc_Ip_u32TempblockCount = BlockCount;
        Sd_Emmc_Ip_u32BlockDone = 0U;
        Sd_Emmc_Ip_u32BlockCountOneTransfer = 0U;
        /* Reset this variable*/
        Sd_Emmc_Ip_bFirstTimeTransfer = FALSE;
    }

    if ((BlockCount + StartBlock) > Sd_Emmc_Ip_u32BlockCountInfo)
    {
        Sd_Emmc_Ip_eJobState = (Sd_Emmc_Ip_StatusType)SD_IP_STATUS_ERROR;
    }
    else
    {
        if ((boolean)FALSE == AsyncEnable)
        {
            Sd_Emmc_Ip_EraseBlocksBlocking(Config, StartBlock);
        }
        else
        {
            Sd_Emmc_Ip_EraseBlocksNonBlocking(Config, StartBlock);
        }
    }

    return Sd_Emmc_Ip_eJobState;
}


static void Sd_Emmc_Ip_EraseBlocksBlocking(const Sd_Emmc_Ip_ConfigType *Config, uint32 StartBlock)
{
    while (Sd_Emmc_Ip_u32TempblockCount != 0U)
    {
        Sd_Emmc_Ip_CalcBlockCountOneTransfer(Config);

        Sd_Emmc_Ip_eJobState = Sd_Ip_Erase(Config,
                                           StartBlock + Sd_Emmc_Ip_u32BlockDone,
                                           Sd_Emmc_Ip_u32BlockCountOneTransfer,
                                           (boolean)FALSE
                                          );

        if ((Sd_Emmc_Ip_StatusType)SD_IP_STATUS_SUCCESS != Sd_Emmc_Ip_eJobState)
        {
            break;
        }
        Sd_Emmc_Ip_u32BlockDone += Sd_Emmc_Ip_u32BlockCountOneTransfer;
    }
    /* Reset this variable to next operation */
    Sd_Emmc_Ip_bFirstTimeTransfer = TRUE;
}


static void Sd_Emmc_Ip_EraseBlocksNonBlocking(const Sd_Emmc_Ip_ConfigType *Config, uint32 StartBlock)
{
    if ((SD_IP_STATUS_SUCCESS == Sd_Emmc_Ip_eJobState) || (SD_IP_STATUS_PENDING == Sd_Emmc_Ip_eJobState))
    {
        if ( SD_IP_STATUS_SUCCESS == Sd_Emmc_Ip_eJobState)
        {
            Sd_Emmc_Ip_CalcBlockCountOneTransfer(Config);
        }
        /* Async mode will be polling until the write is done */
        Sd_Emmc_Ip_eJobState = Sd_Ip_Erase(Config,
                                           StartBlock + Sd_Emmc_Ip_u32BlockDone,
                                           Sd_Emmc_Ip_u32BlockCountOneTransfer,
                                           (boolean)TRUE
                                          );

        /* Work is done when all data is writen and job is successful  */
        if ((Sd_Emmc_Ip_u32TempblockCount == 0U) && (SD_IP_STATUS_SUCCESS == Sd_Emmc_Ip_eJobState))
        {
            Sd_Emmc_Ip_eJobState = SD_IP_STATUS_SUCCESS;
            Sd_Emmc_Ip_bFirstTimeTransfer = TRUE;
        }
        /* There is still data to write, so call Sd_Ip_Write with the next block */
        else if ((Sd_Emmc_Ip_u32TempblockCount > 0U) && (SD_IP_STATUS_SUCCESS == Sd_Emmc_Ip_eJobState))
        {
            Sd_Emmc_Ip_u32BlockDone += Sd_Emmc_Ip_u32BlockCountOneTransfer;

            /* Calculate again Sd_Emmc_Ip_u32TempblockCount */
            Sd_Emmc_Ip_CalcBlockCountOneTransfer(Config);
            /* Continues to write */
            Sd_Emmc_Ip_eJobState = Sd_Ip_Erase(Config,
                                               StartBlock + Sd_Emmc_Ip_u32BlockDone,
                                               Sd_Emmc_Ip_u32BlockCountOneTransfer,
                                               (boolean)TRUE
                                              );
        }
        else if ((SD_IP_STATUS_PENDING == Sd_Emmc_Ip_eJobState))
        {
            /* Do nothing - working is on-going and waiting for finishing */
        }
        else
        {
            /* Working is not successful */
            Sd_Emmc_Ip_bFirstTimeTransfer = TRUE;
        }
    }
    else
    {
        /* Working is not successful */
        Sd_Emmc_Ip_bFirstTimeTransfer = TRUE;
    }
}


/*!
 * @brief Send CMD13 to get card status
 *
 * @param Sd_Ip_pConfig Card descriptor.
 * @retval CardStatus 32-bit card status
 */
static uint32 Sd_Ip_GetCardStatus(const Sd_Emmc_Ip_ConfigType *Config)
{
    uint32 CardStatus = (uint32)SD_IP_R1_ALL_ERROR_FLAGS;  /* Initial value: all error flag are set */

    /* Set the command index */
    Sd_Emmc_Ip_TransferStorage.command.index        = (uint32)aSDMMC_SendStatus;
    /* Set the argument */
    Sd_Emmc_Ip_TransferStorage.command.argument     = (uint32)(Sd_Emmc_Ip_u32RelativeAddress) << 16U;
    /* Set the response type */
    Sd_Emmc_Ip_TransferStorage.command.responseType = USDHC_RESPONSE_TYPE_R1;
    Sd_Emmc_Ip_TransferStorage.command.type         = USDHC_COMMAND_TYPE_NORMAL;

    Sd_Emmc_Ip_TransferStorage.content.command      = &Sd_Emmc_Ip_TransferStorage.command;
    Sd_Emmc_Ip_TransferStorage.content.data         = NULL_PTR;

    /* Start transfer */
    if (STATUS_USDHC_IP_SUCCESS == uSDHC_Ip_Transfer(Config->usdhcConfig->instance, &Sd_Emmc_Ip_TransferStorage.content, (boolean)FALSE))
    {
        /* Get 32-bit card status */
        CardStatus = Sd_Emmc_Ip_TransferStorage.command.response[0U];
    }

    return CardStatus;
}


/*!
 * @brief Send CMD12 to stop a transaction.
 *
 * @param[in]     Config          The card descriptor.
 *
 * @return        Status
 * @pre           The SD driver needs to be initialized.
 */
void Sd_Ip_StopTransmission(const Sd_Emmc_Ip_ConfigType *Config)
{
    uint32 CardStatus;
    uint32 CardState;
    uint32 RetryNo = 2UL;  /* Number of retries to issue CMD12 */

    do
    {
        CardStatus = Sd_Ip_GetCardStatus(Config);
        CardState  = SD_IP_R1_CURRENT_STATE(CardStatus);

        /* Only send CMD12 while card is sending or receiving data.
         * If card is already in tran state, CMD12 is not accepted and Host Driver needs to ignore illegal command error in next R1
         * (PartA2_SD_Host_Controller_Simplified_Specification_Ver4.20, chapter 3.8.1 Abort Command Sequence)
         */
        if ( (0U == (CardStatus & SD_IP_R1_ALL_ERROR_FLAGS)) &&
             (((uint32)aSDMMC_R1StateSendData == CardState) || ((uint32)aSDMMC_R1StateReceiveData == CardState))
           )
        {
            Sd_Emmc_Ip_TransferStorage.command.index        = (uint32)aSDMMC_StopTransmission;
            Sd_Emmc_Ip_TransferStorage.command.argument     = 0U;
            Sd_Emmc_Ip_TransferStorage.command.type         = USDHC_COMMAND_TYPE_ABORT;
            Sd_Emmc_Ip_TransferStorage.command.responseType = USDHC_RESPONSE_TYPE_R1b;
            Sd_Emmc_Ip_TransferStorage.content.command      = &Sd_Emmc_Ip_TransferStorage.command;
            Sd_Emmc_Ip_TransferStorage.content.data         = NULL_PTR;
            /* Start transfer */
            (void)uSDHC_Ip_Transfer(Config->usdhcConfig->instance, &Sd_Emmc_Ip_TransferStorage.content, (boolean)FALSE);
        }
        else
        {
            /* Exit the loop */
            break;
        }

        RetryNo--;
    }
    while (RetryNo > 0UL);
}


/**
* @brief         Sd_Emmc_Ip_Abort
* @details       This function aborts when working is on-going
*
* @param[in]     card The card descriptor.
*
* @return        Status
* @pre           The SD driver needs to be initialized.
*/
/* implements Sd_Emmc_Ip_Abort_Activity */
Sd_Emmc_Ip_StatusType Sd_Emmc_Ip_Abort(const Sd_Emmc_Ip_ConfigType *Config)
{
    /* Check the validity of the input parameters */
    SD_IP_DEV_ASSERT(Config != NULL_PTR);
    Sd_Emmc_Ip_StatusType Status = (Sd_Emmc_Ip_StatusType)SD_IP_STATUS_SUCCESS;

    /* Reset to default*/
    Sd_Emmc_Ip_bFirstTimeTransfer = TRUE;
    if (STATUS_USDHC_IP_SUCCESS != uSDHC_Ip_Abort(Config->usdhcConfig->instance))
    {
        Status = SD_IP_STATUS_ERROR;
    }

    /* Force the card to stop transmission */
    Sd_Ip_StopTransmission(Config);

    /* Discard data in the host controller buffer */
    uSDHC_Ip_DiscardData(Config->usdhcConfig->instance);

    /* Checking if timeout occurs */
    if ((boolean)TRUE == Usdhc_Ip_bFailedTimeout)
    {
        Status = SD_IP_STATUS_TIMEOUT;
        Usdhc_Ip_bFailedTimeout = (boolean)FALSE;
    }

    return Status;
}

/**
* @brief         Sd_Emmc_Ip_GetCardInformation
* @details       This function get card information as Cid, Csd, ... 
*
* @param[in]     Pointer to card information 
*
* @return        None
* @pre           The SD driver needs to be initialized.
*/
void Sd_Emmc_Ip_GetCardInformation(Sd_Emmc_Ip_CardInformationType *CardInformation)
{
    /* Check the validity of the input parameters */
    SD_IP_DEV_ASSERT(CardInformation != NULL_PTR);
    
    /* Sd card information */
    if (SD_IP_MEMORY_CARD_SD == Sd_Emmc_Ip_eCardTypeInfo)
    {
        /* Get information of Sd card */
        CardInformation->SdCardCidRegister = &Sd_Emmc_Ip_Cid;
        CardInformation->SdCardCsdRegister = &Sd_Emmc_Ip_Csd;
        CardInformation->SdCardScrRegister = &Sd_Emmc_Ip_Scr;
        /* Get information of Emmc card */
        CardInformation->EmmcCidRegister = NULL_PTR;
        CardInformation->EmmcCsdRegister = NULL_PTR;
        CardInformation->EmmcCsrRegister = NULL_PTR;
    }
    /* Emmc card information */
    else
    {
        /* Get information of Sd card */
        CardInformation->SdCardCidRegister = NULL_PTR;
        CardInformation->SdCardCsdRegister = NULL_PTR;
        CardInformation->SdCardScrRegister = NULL_PTR;
        /* Get information of Emmc card */
        CardInformation->EmmcCidRegister = &Sd_Emmc_Ip_MmcCid;
        CardInformation->EmmcCsdRegister = &Sd_Emmc_Ip_MmcCsd;
        CardInformation->EmmcCsrRegister = &Sd_Emmc_Ip_MmcECsr;
    }
        
    /* Get information of block count */
    CardInformation->u32BlockCount  = Sd_Emmc_Ip_u32BlockCountInfo;
    /* Get information of block size */
    CardInformation->u32BlockSize   = Sd_Emmc_Ip_u32BlockSizeInfo;
    /* Get SD bus clock frequency united in Hz*/
    CardInformation->u32BusClock_Hz = Sd_Emmc_Ip_u32BusClockInfo;
    /* Card version - SPEC_VERS in the CSD */
    CardInformation->u32Version     = Sd_Emmc_Ip_u32VersionInfo;
    /* Card type */
    CardInformation->eCardType      = Sd_Emmc_Ip_eCardTypeInfo;
}

/**
** @brief Switch access to desired partition
 *
*/
Sd_Emmc_Ip_StatusType Sd_Emmc_Ip_MmcSwitchPartitionAccess(const Sd_Emmc_Ip_ConfigType *Sd_Ip_pConfig, Sd_Ip_MmcPartitionAccessType Sd_Ip_PartitionAccess)
{
    Sd_Emmc_Ip_StatusType status;
    uint32 u32PartitionConfig;

    /* Wait for MMC device ready by sending CMD13 */
    status = Sd_Ip_WaitWriteComplete(Sd_Ip_pConfig);

    if(SD_IP_STATUS_SUCCESS == status)
    {
        u32PartitionConfig = (((uint32)Sd_Emmc_Ip_MmcECsr.bootConfig & (MMC_PARTITION_CONFIG_ENABLE_MASK | MMC_PARTITION_CONFIG_ACK_MASK)) | MMC_PARTITION_CONFIG_ACCESS(Sd_Ip_PartitionAccess));
        /* Switch access to desired boot partition */
        status = Sd_Ip_MmcSwitch(Sd_Ip_pConfig, MMCCWriteBits, (uint8)MMC_EXT_CSD_INDEX_PARTITION_CONFIG, u32PartitionConfig << 8);
    }

    /* Update MMC_EXT_CSD_INDEX_PARTITION_CONFIG register value into var Sd_Emmc_Ip_MmcECsr.bootConfig */
    if(SD_IP_STATUS_SUCCESS == status)
    {
        status = Sd_Ip_MmcSendExtCsd(Sd_Ip_pConfig);
    }

    /* Verify extended CSD register field */
    if(SD_IP_STATUS_SUCCESS == status)
    {
        if(((uint8)(Sd_Emmc_Ip_MmcECsr.bootConfig & MMC_PARTITION_CONFIG_ACCESS_MASK) >> MMC_PARTITION_CONFIG_ACCESS_SHIFT) == (uint8)Sd_Ip_PartitionAccess)
        {
            mmcPartitionState = Sd_Ip_PartitionAccess;
            status = SD_IP_STATUS_SUCCESS;
        }
        else
        {
            status = SD_IP_STATUS_ERROR;
        }
    }

    return status;
}

#define MEM_43_EEP_STOP_SEC_CODE
#include "Mem_43_Eep_MemMap.h"

#ifdef __cplusplus
}
#endif
/** @} */

