/*==================================================================================================
*   Project              : RTD AUTOSAR 4.7
*   Platform             : CORTEXM
*   Peripheral           : 
*   Dependencies         : none
*
*   Autosar Version      : 4.7.0
*   Autosar Revision     : ASR_REL_4_7_REV_0000
*   Autosar Conf.Variant :
*   SW Version           : 0.9.0
*   Build Version        : S32ZE_RTD_0_9_0_D2209_ASR_REL_4_7_REV_0000_20220930
*
*   Copyright 2021-2022 NXP Semiconductors
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
*   @file    Zipwire_Ip.c
*
*   @version 3.0.0
*
*   @brief   AUTOSAR Zipwire - Zipwire Ip driver source file.
*   @details
*
*   @addtogroup ZIPWIRE_IP_DRIVER
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
#include "Zipwire_Ip.h"
#include "Zipwire_Ip_Sipi_Hw_Access.h"
#include "Zipwire_Ip_Sipi_Irq.h"
#include "Zipwire_Ip_Lfast_Hw_Access.h"
#include "Zipwire_Ip_Lfast.h"
#include "Zipwire_Ip_DevAssert.h"

#if (STD_ON == ZIPWIRE_IP_DMA_IS_AVAILABLE)
#include "Dma_Ip.h"
#endif

#if (defined(ZIPWIRE_ENABLE_USER_MODE_SUPPORT) && (STD_ON == ZIPWIRE_ENABLE_USER_MODE_SUPPORT))
#define USER_MODE_REG_PROT_ENABLED      (STD_ON)
#include "OsIf_Internal.h"
#include "Reg_eSys.h"
#include "RegLockMacros.h"
#endif

/*==================================================================================================
                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/*
* @brief Parameters that shall be published within the driver header file and also in the
* module's description file
*/
#define ZIPWIRE_IP_VENDOR_ID_C                      43
#define ZIPWIRE_IP_AR_RELEASE_MAJOR_VERSION_C       4
#define ZIPWIRE_IP_AR_RELEASE_MINOR_VERSION_C       7
#define ZIPWIRE_IP_AR_RELEASE_REVISION_VERSION_C    0
#define ZIPWIRE_IP_SW_MAJOR_VERSION_C               3
#define ZIPWIRE_IP_SW_MINOR_VERSION_C               0
#define ZIPWIRE_IP_SW_PATCH_VERSION_C               0

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/
/* Check if the files Zipwire_Ip.c and Zipwire_Ip_Lfast.h are of the same version */
#if (ZIPWIRE_IP_VENDOR_ID_C != ZIPWIRE_IP_VENDOR_ID)
    #error "Zipwire_Ip.c and Zipwire_Ip_Lfast.h have different vendor ids"
#endif

/* Check if Zipwire_Ip.c and Zipwire_Ip_Lfast.h are of the same Autosar version */
#if ((ZIPWIRE_IP_AR_RELEASE_MAJOR_VERSION_C    != ZIPWIRE_IP_AR_RELEASE_MAJOR_VERSION) || \
     (ZIPWIRE_IP_AR_RELEASE_MINOR_VERSION_C    != ZIPWIRE_IP_AR_RELEASE_MINOR_VERSION) || \
     (ZIPWIRE_IP_AR_RELEASE_REVISION_VERSION_C != ZIPWIRE_IP_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Zipwire_Ip.c and Zipwire_Ip_Lfast.h are different"
#endif

/* Check if Zipwire_Ip.c and Zipwire_Ip_Lfast.h are of the same Software version */
#if ((ZIPWIRE_IP_SW_MAJOR_VERSION_C != ZIPWIRE_IP_SW_MAJOR_VERSION) || \
     (ZIPWIRE_IP_SW_MINOR_VERSION_C != ZIPWIRE_IP_SW_MINOR_VERSION) || \
     (ZIPWIRE_IP_SW_PATCH_VERSION_C != ZIPWIRE_IP_SW_PATCH_VERSION)    \
    )
    #error "Software Version Numbers of Zipwire_Ip.c and Zipwire_Ip_Lfast.h are different"
#endif

/* Check if the files Zipwire_Ip.c and Zipwire_Ip_DevAssert.h are of the same version */
#if (ZIPWIRE_IP_VENDOR_ID_C != ZIPWIRE_IP_DEVASSERT_VENDOR_ID)
    #error "Zipwire_Ip.c and Zipwire_Ip_DevAssert.h have different vendor ids"
#endif

/* Check if Zipwire_Ip.c file and Zipwire_Ip_DevAssert.h header file are of the same Autosar version */
#if ((ZIPWIRE_IP_AR_RELEASE_MAJOR_VERSION_C    != ZIPWIRE_IP_DEVASSERT_AR_RELEASE_MAJOR_VERSION) || \
     (ZIPWIRE_IP_AR_RELEASE_MINOR_VERSION_C    != ZIPWIRE_IP_DEVASSERT_AR_RELEASE_MINOR_VERSION) || \
     (ZIPWIRE_IP_AR_RELEASE_REVISION_VERSION_C != ZIPWIRE_IP_DEVASSERT_AR_RELEASE_REVISION_VERSION) \
     )
    #error "AutoSar Version Numbers of Zipwire_Ip.c and Zipwire_Ip_DevAssert.h are different"
#endif

/* Check if Zipwire_Ip.c and Zipwire_Ip_DevAssert.h are of the same Software version */
#if ((ZIPWIRE_IP_SW_MAJOR_VERSION_C != ZIPWIRE_IP_DEVASSERT_SW_MAJOR_VERSION) || \
     (ZIPWIRE_IP_SW_MINOR_VERSION_C != ZIPWIRE_IP_DEVASSERT_SW_MINOR_VERSION) || \
     (ZIPWIRE_IP_SW_PATCH_VERSION_C != ZIPWIRE_IP_DEVASSERT_SW_PATCH_VERSION)    \
    )
    #error "Software Version Numbers of Zipwire_Ip.c and Zipwire_Ip_DevAssert.h are different"
#endif

/* Check if the files Zipwire_Ip.c and Zipwire_Ip_Lfast_Hw_Access.h are of the same version */
#if (ZIPWIRE_IP_VENDOR_ID_C != ZIPWIRE_IP_LFAST_HW_ACCESS_VENDOR_ID)
    #error "Zipwire_Ip.c and Zipwire_Ip_Lfast_Hw_Access.h have different vendor ids"
#endif

/* Check if Zipwire_Ip.c file and Zipwire_Ip_Lfast_Hw_Access.h header file are of the same Autosar version */
#if ((ZIPWIRE_IP_AR_RELEASE_MAJOR_VERSION_C    != ZIPWIRE_IP_LFAST_HW_ACCESS_AR_RELEASE_MAJOR_VERSION) || \
     (ZIPWIRE_IP_AR_RELEASE_MINOR_VERSION_C    != ZIPWIRE_IP_LFAST_HW_ACCESS_AR_RELEASE_MINOR_VERSION) || \
     (ZIPWIRE_IP_AR_RELEASE_REVISION_VERSION_C != ZIPWIRE_IP_LFAST_HW_ACCESS_AR_RELEASE_REVISION_VERSION) \
     )
    #error "AutoSar Version Numbers of Zipwire_Ip.c and Zipwire_Ip_Lfast_Hw_Access.h are different"
#endif

/* Check if Zipwire_Ip.c and Zipwire_Ip_Lfast_Hw_Access.h are of the same Software version */
#if ((ZIPWIRE_IP_SW_MAJOR_VERSION_C != ZIPWIRE_IP_LFAST_HW_ACCESS_SW_MAJOR_VERSION) || \
     (ZIPWIRE_IP_SW_MINOR_VERSION_C != ZIPWIRE_IP_LFAST_HW_ACCESS_SW_MINOR_VERSION) || \
     (ZIPWIRE_IP_SW_PATCH_VERSION_C != ZIPWIRE_IP_LFAST_HW_ACCESS_SW_PATCH_VERSION)    \
    )
    #error "Software Version Numbers of Zipwire_Ip.c and Zipwire_Ip_Lfast_Hw_Access.h are different"
#endif

/* Check if the files Zipwire_Ip.c and Zipwire_Ip_Sipi_Hw_Access.h are of the same version */
#if (ZIPWIRE_IP_VENDOR_ID_C != ZIPWIRE_IP_SIPI_HW_ACCESS_VENDOR_ID)
    #error "Zipwire_Ip.c and Zipwire_Ip_Sipi_Hw_Access.h have different vendor ids"
#endif

/* Check if Zipwire_Ip.c file and Zipwire_Ip_Sipi_Hw_Access.h header file are of the same Autosar version */
#if ((ZIPWIRE_IP_AR_RELEASE_MAJOR_VERSION_C    != ZIPWIRE_IP_SIPI_HW_ACCESS_AR_RELEASE_MAJOR_VERSION) || \
     (ZIPWIRE_IP_AR_RELEASE_MINOR_VERSION_C    != ZIPWIRE_IP_SIPI_HW_ACCESS_AR_RELEASE_MINOR_VERSION) || \
     (ZIPWIRE_IP_AR_RELEASE_REVISION_VERSION_C != ZIPWIRE_IP_SIPI_HW_ACCESS_AR_RELEASE_REVISION_VERSION) \
     )
    #error "AutoSar Version Numbers of Zipwire_Ip.c and Zipwire_Ip_Sipi_Hw_Access.h are different"
#endif

/* Check if Zipwire_Ip.c and Zipwire_Ip_Sipi_Hw_Access.h are of the same Software version */
#if ((ZIPWIRE_IP_SW_MAJOR_VERSION_C != ZIPWIRE_IP_SIPI_HW_ACCESS_SW_MAJOR_VERSION) || \
     (ZIPWIRE_IP_SW_MINOR_VERSION_C != ZIPWIRE_IP_SIPI_HW_ACCESS_SW_MINOR_VERSION) || \
     (ZIPWIRE_IP_SW_PATCH_VERSION_C != ZIPWIRE_IP_SIPI_HW_ACCESS_SW_PATCH_VERSION)    \
    )
    #error "Software Version Numbers of Zipwire_Ip.c and Zipwire_Ip_Sipi_Hw_Access.h are different"
#endif

#if (STD_ON == ZIPWIRE_IP_DMA_IS_AVAILABLE)
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
/* Check if Zipwire_Ip.c file and Dma_Ip.h header file are of the same Autosar version */
#if ((ZIPWIRE_IP_AR_RELEASE_MAJOR_VERSION_C != DMA_IP_AR_RELEASE_MAJOR_VERSION) || \
     (ZIPWIRE_IP_AR_RELEASE_MINOR_VERSION_C != DMA_IP_AR_RELEASE_MINOR_VERSION))
    #error "AutoSar Version Numbers of Zipwire_Ip.c and Dma_Ip.h are different"
#endif
#endif
#endif

#if (defined(ZIPWIRE_ENABLE_USER_MODE_SUPPORT) && (STD_ON == ZIPWIRE_ENABLE_USER_MODE_SUPPORT))
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK

/* Check if Zipwire_Ip_Hardware.c file and OsIf_Internal.h header file are of the same Autosar version */
#if ((ZIPWIRE_IP_AR_RELEASE_MAJOR_VERSION_C != OSIF_INTERNAL_AR_RELEASE_MAJOR_VERSION) || \
     (ZIPWIRE_IP_AR_RELEASE_MINOR_VERSION_C != OSIF_INTERNAL_AR_RELEASE_MINOR_VERSION))
    #error "AutoSar Version Numbers of Zipwire_Ip.c and OsIf_Internal.h are different"
#endif

/* Check if Zipwire_Ip_Hardware.c file and Reg_eSys.h header file are of the same Autosar version */
#if ((ZIPWIRE_IP_AR_RELEASE_MAJOR_VERSION_C != REG_ESYS_AR_RELEASE_MAJOR_VERSION) || \
     (ZIPWIRE_IP_AR_RELEASE_MINOR_VERSION_C != REG_ESYS_AR_RELEASE_MINOR_VERSION))
    #error "AutoSar Version Numbers of Zipwire_Ip.c and Reg_eSys.h are different"
#endif

/* Check if Zipwire_Ip_Hardware.c file and RegLockMacros.h header file are of the same Autosar version */
#if ((ZIPWIRE_IP_AR_RELEASE_MAJOR_VERSION_C != REGLOCKMACROS_AR_RELEASE_MAJOR_VERSION) || \
     (ZIPWIRE_IP_AR_RELEASE_MINOR_VERSION_C != REGLOCKMACROS_AR_RELEASE_MINOR_VERSION))
    #error "AutoSar Version Numbers of Zipwire_Ip.c and RegLockMacros.h are different"
#endif

#endif
#endif


/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/
#if (STD_ON == ZIPWIRE_IP_DMA_IS_AVAILABLE)
#define ZIPWIRE_IP_DMA_DATA_CONFIG_DIMENSION        (14U)
#define ZIPWIRE_IP_DMA_ADDRESS_CONFIG_DIMENSION     (10U)
#endif /* #if (STD_ON == ZIPWIRE_IP_DMA_IS_AVAILABLE) */
/*==================================================================================================
*                                      LOCAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      LOCAL VARIABLES
==================================================================================================*/
#define ZIPWIRE_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "Zipwire_MemMap.h"
static const Zipwire_Ip_LogicChannelConfigType  * const *s_ppaxLogicChannelInit;
static const Zipwire_Ip_LogicInstanceConfigType * const *s_ppaxLogicInstanceInit;
#define ZIPWIRE_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "Zipwire_MemMap.h"

#define ZIPWIRE_START_SEC_CONST_UNSPECIFIED
#include "Zipwire_MemMap.h"


SIPI_Type * s_ZipwireSipiInstances[ZIPWIRE_IP_INSTANCE_COUNT_U8] = IP_SIPI_BASE_PTRS;
LFAST_Type * s_ZipwireLfastInstances[ZIPWIRE_IP_INSTANCE_COUNT_U8] = IP_LFAST_BASE_PTRS;
Zipwire_Ip_SIPI_Channel_Type * s_ZipwireSipiChannels[ZIPWIRE_IP_INSTANCE_COUNT_U8][ZIPWIRE_IP_CHANNEL_COUNT_U8] = IP_SIPI_CHANNEL_BASE_PTRS;

#define ZIPWIRE_STOP_SEC_CONST_UNSPECIFIED
#include "Zipwire_MemMap.h"

#define ZIPWIRE_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "Zipwire_MemMap.h"

static Zipwire_Ip_InstanceState s_axLogicInstanceState[ZIPWIRE_IP_INSTANCE_COUNT_U8];
static Zipwire_Ip_ChannelState s_axLogicChannelState[ZIPWIRE_IP_INSTANCE_COUNT_U8][ZIPWIRE_IP_CHANNEL_COUNT_U8];

#define ZIPWIRE_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "Zipwire_MemMap.h"

#if (STD_ON == ZIPWIRE_IP_DMA_IS_AVAILABLE)
#define ZIPWIRE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Zipwire_MemMap.h"

static Dma_Ip_LogicChannelTransferListType s_atAddressDmaTransferList[ZIPWIRE_IP_DMA_ADDRESS_CONFIG_DIMENSION] =
{
    {DMA_IP_CH_SET_SOURCE_ADDRESS, 0U},
    {DMA_IP_CH_SET_SOURCE_SIGNED_OFFSET, 0U},
    {DMA_IP_CH_SET_SOURCE_TRANSFER_SIZE, 0U},
    {DMA_IP_CH_SET_DESTINATION_ADDRESS, 0U},
    {DMA_IP_CH_SET_DESTINATION_SIGNED_OFFSET, 0U},
    {DMA_IP_CH_SET_DESTINATION_TRANSFER_SIZE, 0U},
    {DMA_IP_CH_SET_MINORLOOP_SIZE, 4U},
    {DMA_IP_CH_SET_MAJORLOOP_COUNT, 1U},
    {DMA_IP_CH_SET_CONTROL_EN_MAJOR_INTERRUPT, FALSE},
    {DMA_IP_CH_SET_CONTROL_DIS_AUTO_REQUEST, TRUE}
};

static Dma_Ip_LogicChannelTransferListType s_atDataDmaTransferList[ZIPWIRE_IP_DMA_DATA_CONFIG_DIMENSION] =
{
    {DMA_IP_CH_SET_SOURCE_ADDRESS, 0U},
    {DMA_IP_CH_SET_SOURCE_SIGNED_OFFSET, 0U},
    {DMA_IP_CH_SET_SOURCE_TRANSFER_SIZE, 0U},
    {DMA_IP_CH_SET_DESTINATION_ADDRESS, 0U},
    {DMA_IP_CH_SET_DESTINATION_SIGNED_OFFSET, 0U},
    {DMA_IP_CH_SET_DESTINATION_TRANSFER_SIZE, 0U},
    {DMA_IP_CH_SET_MINORLOOP_SIZE, 4U},
    {DMA_IP_CH_SET_MINORLOOP_EN_LINK, TRUE},
    {DMA_IP_CH_SET_MINORLOOP_LOGIC_LINK_CH, 0U},
    {DMA_IP_CH_SET_MAJORLOOP_EN_LINK, FALSE},
    {DMA_IP_CH_SET_MAJORLOOP_LOGIC_LINK_CH, 0U},
    {DMA_IP_CH_SET_MAJORLOOP_COUNT, 1U},
    {DMA_IP_CH_SET_CONTROL_EN_MAJOR_INTERRUPT, FALSE},
    {DMA_IP_CH_SET_CONTROL_DIS_AUTO_REQUEST, TRUE}
};

#define ZIPWIRE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Zipwire_MemMap.h"
#endif /* #if (STD_ON == ZIPWIRE_IP_DMA_IS_AVAILABLE) */

/*==================================================================================================
*                                      GLOBAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      GLOBAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/
static Zipwire_Ip_StatusType Zipwire_Ip_LaunchRWCommand(uint8 HwInstance,
                                                        uint8 HwChannel,
                                                        Zipwire_Ip_TransferDescriptor *Data,
                                                        uint32 DataArrayLength,
                                                        boolean WriteEnable,
                                                        boolean IsBlocking);
static void Zipwire_Ip_WriteData(uint8 HwInstance, uint8 HwChannel, Zipwire_Ip_TransferDescriptor *Data);
static void Zipwire_Ip_StopTransfer(uint8 HwInstance, uint8 HwChannel);

#if (STD_ON == ZIPWIRE_IP_DMA_IS_AVAILABLE)
static Zipwire_Ip_StatusType Zipwire_Ip_LaunchRWCommandWithDma(uint8 HwInstance,
                                               uint8 HwChannel,
                                               uint32 *DataArray,
                                               const uint32 *AddressArray,
                                               uint32 DataArrayLength,
                                               boolean write,
                                               boolean IsBlocking);
void Zipwire_Ip_DmaCallback(void *InstanceState,  Dma_Ip_ReturnType DmaStatus);
#endif /* #if (STD_ON == ZIPWIRE_IP_DMA_IS_AVAILABLE) */

static void Zipwire_Ip_StartTimeout(uint32 *StartTimeOut,
                         uint32 *ElapsedTimeOut,
                         uint32 *TimeoutTicksOut,
                         uint32 TimeoutUs);

static boolean Zipwire_Ip_TimeoutExpired(uint32 *startTimeInOut,
                            uint32 *elapsedTimeInOut,
                            uint32 TimeoutTicks);

#if (defined(ZIPWIRE_ENABLE_USER_MODE_SUPPORT) && (ZIPWIRE_ENABLE_USER_MODE_SUPPORT == STD_ON))
/**
 * @brief This function configure Set User Access Allowed
 */
void Zipwire_Ip_SetUserAccessAllowed(uint32 const pxZipwireBaseAddr);
#endif /* ZIPWIRE_ENABLE_USER_MODE_SUPPORT == STD_ON */
/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/

#define ZIPWIRE_START_SEC_CODE
#include "Zipwire_MemMap.h"

#if (defined(ZIPWIRE_ENABLE_USER_MODE_SUPPORT) && (STD_ON == ZIPWIRE_ENABLE_USER_MODE_SUPPORT))
/**
 * @brief This function configure Set User Access Allowed
 */
void Zipwire_Ip_SetUserAccessAllowed(uint32 const pxZipwireBaseAddr)
{
    /* ZIPWIRE SetUserAccessAllowed */
    #if defined(MCAL_ZIPWIRE_REG_PROT_AVAILABLE) 
        #if (STD_ON == MCAL_ZIPWIRE_REG_PROT_AVAILABLE)
        SET_USER_ACCESS_ALLOWED(pxZipwireBaseAddr, ZIPWIRE_PROT_MEM_U32);
        #endif
    #endif
    /* Avoid compiler warning */
    (void)pxZipwireBaseAddr;
}
#endif /* STD_ON == ZIPWIRE_ENABLE_USER_MODE_SUPPORT */


#if (defined(ZIPWIRE_ENABLE_USER_MODE_SUPPORT) && (STD_ON == ZIPWIRE_ENABLE_USER_MODE_SUPPORT))
/**
 * @brief This function configure Set User Access Allowed for ZIPWIRE
 */
static void Zipwire_Ip_SpecificSetUserAccessAllowed(uint32 const pxZipwireBaseAddr)
{
    OsIf_Trusted_Call1param(Zipwire_Ip_SetUserAccessAllowed, pxZipwireBaseAddr);
}
#endif /* STD_ON == ZIPWIRE_ENABLE_USER_MODE_SUPPORT */


/**
 * @brief         Initializes the Zipwire Instances based on the user configuration.
 * @implements    Zipwire_Ip_InitInstance_Activity
 */
Zipwire_Ip_StatusType Zipwire_Ip_InitInstance(const Zipwire_Ip_LogicInstanceConfigType *pxZipwireInstanceConfig)
{
    ZIPWIRE_IP_DEV_ASSERT(pxZipwireInstanceConfig->HwInstance < ZIPWIRE_IP_INSTANCE_COUNT_U8);
    ZIPWIRE_IP_DEV_ASSERT(pxZipwireInstanceConfig != NULL_PTR);
    ZIPWIRE_IP_DEV_ASSERT(pxZipwireInstanceConfig->LfastConfig != NULL_PTR);

    LFAST_Type *pxLfastBase = s_ZipwireLfastInstances[pxZipwireInstanceConfig->HwInstance];
    SIPI_Type *pxSipiBase = s_ZipwireSipiInstances[pxZipwireInstanceConfig->HwInstance];
    Zipwire_Ip_InstanceState *InstanceState = &s_axLogicInstanceState[pxZipwireInstanceConfig->HwInstance];

    Zipwire_Ip_StatusType ZipwireStatus;

    /* Perform a soft reset of the SIPI state machine */
    ZipwireStatus = hwAccZipwireSipi_SoftReset(pxSipiBase);
    if (ZipwireStatus != ZIPWIRE_IP_STATUS_SUCCESS)
    {
        return ZipwireStatus;
    }
    /* Enable SIPI module */
    hwAccZipwireSipi_Enable(pxSipiBase, TRUE);
    /* Enable target functionality for the SIPI module */
    hwAccZipwireSipi_TargetEnable(pxSipiBase, TRUE);
    /* Move SIPI to INIT mode */
    hwAccZipwireSipi_EnterInitMode(pxSipiBase);
    /* Configure address offset and clock prescaler with user options */
    hwAccZipwireSipi_SetAddrOffset(pxSipiBase, (uint8)pxZipwireInstanceConfig->AddrOffset);
    hwAccZipwireSipi_SetTimeoutClockPrescaler(pxSipiBase, ((uint16)pxZipwireInstanceConfig->TimeoutClkDiv));
    /* Move back to NORMAL mode */
    hwAccZipwireSipi_ExitInitMode(pxSipiBase);
    /* Enable CRC error interrupt */
    hwAccZipwireSipi_SetCrcErrInt(pxSipiBase, TRUE);
    /* Configure maximum address interrupt with user option */
    hwAccZipwireSipi_SetMaxCountReachedInt(pxSipiBase, pxZipwireInstanceConfig->MaxCountReachedInt);

    /* Configure user callbacks */
    InstanceState->Callback = pxZipwireInstanceConfig->Callback;
    InstanceState->CallbackParam = pxZipwireInstanceConfig->CallbackParam;

    #if (defined(ZIPWIRE_ENABLE_USER_MODE_SUPPORT) && (STD_ON == ZIPWIRE_ENABLE_USER_MODE_SUPPORT))
    static uint32 const s_pxZipwireBaseAddr[ZIPWIRE_IP_INSTANCE_COUNT_U8] = IP_LFAST_BASE_ADDRS;
    /* Allow user access to register protected */
    Zipwire_Ip_SpecificSetUserAccessAllowed(s_pxZipwireBaseAddr[pxZipwireInstanceConfig->HwInstance]);
    #endif /* #if (STD_ON == ZIPWIRE_ENABLE_USER_MODE_SUPPORT) */
    
    /* Initialize appropriate LFAST interface */
    if (pxZipwireInstanceConfig->LfastConfig->Role == LFAST_MASTER)
    {
        ZipwireStatus = Zipwire_Ip_MasterInit(pxLfastBase,
                                pxZipwireInstanceConfig->LfastConfig->SpeedMode,
                                pxZipwireInstanceConfig->LfastConfig->LowSpeedClkDiv,
                                pxZipwireInstanceConfig->LfastConfig->SyncTimeout,
                                pxZipwireInstanceConfig->LfastConfig->SyncAttempts);
    }
    else
    {
        ZipwireStatus = Zipwire_Ip_SlaveInit(pxLfastBase,
                                pxZipwireInstanceConfig->LfastConfig->SpeedMode,
                                pxZipwireInstanceConfig->LfastConfig->LowSpeedClkDiv,
                                pxZipwireInstanceConfig->LfastConfig->SyncTimeout);
    }
    if (ZipwireStatus != ZIPWIRE_IP_STATUS_SUCCESS)
    {
        return ZipwireStatus;
    }
    return ZIPWIRE_IP_STATUS_SUCCESS;
}


/**
 * @brief         Deinitializes the Zipwire Instances.
 * @implements    Zipwire_Ip_DeInitInstance_Activity
 */
Zipwire_Ip_StatusType Zipwire_Ip_DeInitInstance(uint8 HwInstance)
{
    ZIPWIRE_IP_DEV_ASSERT(HwInstance < ZIPWIRE_IP_INSTANCE_COUNT_U8);

    LFAST_Type *pxLfastBase = s_ZipwireLfastInstances[HwInstance];
    SIPI_Type *pxSipiBase = s_ZipwireSipiInstances[HwInstance];
    Zipwire_Ip_InstanceState *InstanceState = &s_axLogicInstanceState[HwInstance];

    uint8 ChannelCounter;
    Zipwire_Ip_StatusType ZipwireStatus;

    /* Perform a soft reset of the SIPI state machine */
    ZipwireStatus = hwAccZipwireSipi_SoftReset(pxSipiBase);
    if(&s_axLogicInstanceState[HwInstance] != NULL_PTR)
    {
        /* Perform a soft reset of the SIPI state machine */
        if (ZipwireStatus == ZIPWIRE_IP_STATUS_SUCCESS)
        {
            /* Disable SIPI global interrupts */
            hwAccZipwireSipi_SetCrcErrInt(pxSipiBase, FALSE);
            hwAccZipwireSipi_SetMaxCountReachedInt(pxSipiBase, FALSE);

            /* Reset user callbacks */
            InstanceState->Callback = NULL_PTR;
            InstanceState->CallbackParam = NULL_PTR;
            /* Deinitialize all channels */
            for (ChannelCounter = 0U; ChannelCounter < ZIPWIRE_IP_CHANNEL_COUNT_U8; ChannelCounter++)
            {
                (void)Zipwire_Ip_DeInitChannel(HwInstance, ChannelCounter);
            }

            /* Disable SIPI module */
            hwAccZipwireSipi_Enable(pxSipiBase, FALSE);
            /* LFAST interface */
            hwAccZipwireLfast_EnableLfast(pxLfastBase, FALSE);
        }
    }
    return ZipwireStatus;
}


/**
 * @brief         Initializes the Zipwire SIPI Channels based on the user configuration.
 * @implements    Zipwire_Ip_InitChannel_Activity
 */
Zipwire_Ip_StatusType Zipwire_Ip_InitChannel(const Zipwire_Ip_LogicChannelConfigType *pxZipwireChannelConfig)
{
    ZIPWIRE_IP_DEV_ASSERT(pxZipwireChannelConfig->HwInstance < ZIPWIRE_IP_INSTANCE_COUNT_U8);
    ZIPWIRE_IP_DEV_ASSERT(pxZipwireChannelConfig->HwChannel  < ZIPWIRE_IP_CHANNEL_COUNT_U8);

    SIPI_Type *pxSipiBase = s_ZipwireSipiInstances[pxZipwireChannelConfig->HwInstance];
    Zipwire_Ip_SIPI_Channel_Type *pxSipiChannelBase = s_ZipwireSipiChannels[pxZipwireChannelConfig->HwInstance][pxZipwireChannelConfig->HwChannel];
    Zipwire_Ip_ChannelState *ChannelState = &s_axLogicChannelState[pxZipwireChannelConfig->HwInstance][pxZipwireChannelConfig->HwChannel];

    Zipwire_Ip_StatusType ZipwireStatus;

    /* Save instance & channel info */
    
    ChannelState->HwInstance = pxZipwireChannelConfig->HwInstance;
    ChannelState->HwChannel  = pxZipwireChannelConfig->HwChannel;

    /* Save references user callbacks */
    ChannelState->Callback = pxZipwireChannelConfig->Callback;
    ChannelState->CallbackParam = pxZipwireChannelConfig->CallbackParam;

    /* Initialize channel status */
    ChannelState->ChannelStatus = ZIPWIRE_IP_STATUS_SUCCESS;
    /* Initialize transfer buffer reference to NULL_PTR */
    ChannelState->TransferBuffer = NULL_PTR;
    /* Initialize Id request and target ID to zero */
    ChannelState->TargetId = NULL_PTR;
    ChannelState->IdRequest = FALSE;
    ChannelState->DisableNotification = FALSE;

#if (STD_ON == ZIPWIRE_IP_DMA_IS_AVAILABLE)
    /* Initialize DMA */
    ChannelState->DmaEnable = pxZipwireChannelConfig->DmaEnable;
    ChannelState->DmaDataChn = pxZipwireChannelConfig->DmaDataChn;
    ChannelState->DmaAddrChn = pxZipwireChannelConfig->DmaAddrChn;
    ChannelState->DmaWriteTransfer = FALSE;
#endif

    /* Enable channel interrupts */
    hwAccZipwireSipi_SetChannelInterrupt(pxSipiChannelBase, SIPI_ACK_ERR_IRQ, pxZipwireChannelConfig->AckErrIrq);
    hwAccZipwireSipi_SetChannelInterrupt(pxSipiChannelBase, SIPI_TIMEOUT_IRQ, pxZipwireChannelConfig->TimeoutErrIrq);
    hwAccZipwireSipi_SetChannelInterrupt(pxSipiChannelBase, SIPI_TRANS_ID_ERR_IRQ, pxZipwireChannelConfig->TransIdErrIrq);
    hwAccZipwireSipi_SetChannelInterrupt(pxSipiChannelBase, SIPI_TRIGGER_IRQ, TRUE);
    /* Move SIPI to INIT mode */
    hwAccZipwireSipi_EnterInitMode(pxSipiBase);
    /* Configure channel timeout */
    hwAccZipwireSipi_SetChannelTimeout(pxSipiChannelBase, pxZipwireChannelConfig->Timeout);
    /* Enable the channel */
    hwAccZipwireSipi_EnableChannel(pxSipiChannelBase, TRUE);
    /* Move back to NORMAL mode*/
    hwAccZipwireSipi_ExitInitMode(pxSipiBase);

    return ZIPWIRE_IP_STATUS_SUCCESS;
}


/**
 * @brief         Deinitializes the Zipwire SIPI Channels.
 * @implements    Zipwire_Ip_DeInitChannel_Activity
 */
Zipwire_Ip_StatusType Zipwire_Ip_DeInitChannel(uint8 HwInstance, uint8 HwChannel)
{
    ZIPWIRE_IP_DEV_ASSERT(HwInstance < ZIPWIRE_IP_INSTANCE_COUNT_U8);
    ZIPWIRE_IP_DEV_ASSERT(HwChannel < ZIPWIRE_IP_CHANNEL_COUNT_U8);

    SIPI_Type *pxSipiBase = s_ZipwireSipiInstances[HwInstance];
    Zipwire_Ip_SIPI_Channel_Type *pxSipiChannelBase = s_ZipwireSipiChannels[HwInstance][HwChannel];

    Zipwire_Ip_ChannelState *ChannelState = &s_axLogicChannelState[HwInstance][HwChannel];
    if (&s_axLogicChannelState[HwInstance][HwChannel] != NULL_PTR)
    {
        /* Reset user callbacks */
        ChannelState->Callback = NULL_PTR;
        ChannelState->CallbackParam = NULL_PTR;

        /* Disable channel interrupts */
        hwAccZipwireSipi_SetChannelInterrupt(pxSipiChannelBase, SIPI_ACK_ERR_IRQ, FALSE);
        hwAccZipwireSipi_SetChannelInterrupt(pxSipiChannelBase, SIPI_TIMEOUT_IRQ, FALSE);
        hwAccZipwireSipi_SetChannelInterrupt(pxSipiChannelBase, SIPI_TRANS_ID_ERR_IRQ, FALSE);
        hwAccZipwireSipi_SetChannelInterrupt(pxSipiChannelBase, SIPI_TRIGGER_IRQ, FALSE);

        /* Move SIPI to INIT mode */
        hwAccZipwireSipi_EnterInitMode(pxSipiBase);
        /* Disable the channel */
        hwAccZipwireSipi_EnableChannel(pxSipiChannelBase, FALSE);
        /* Move back to NORMAL mode*/
        hwAccZipwireSipi_ExitInitMode(pxSipiBase);
    }
    return ZIPWIRE_IP_STATUS_SUCCESS;
}


/**
 * @brief         Initializes the ZIPWIRE Driver settings based on user configuration.
 * @implements    Zipwire_Ip_Init_Activity
 */
void Zipwire_Ip_Init(const Zipwire_Ip_ConfigType *const pxZipwireConfig)
{
    uint32 LocInstanceIndex = 0U;
    uint32 LocChannelIndex  = 0U;

    ZIPWIRE_IP_DEV_ASSERT(NULL_PTR != pxZipwireConfig);

    /* Save pointer to initialization structure for LogicInstanceConfigList */
    s_ppaxLogicInstanceInit = pxZipwireConfig->ZipwireIpInstanceCfg->LogicInstanceConfigList;

    for (LocInstanceIndex = 0U; LocInstanceIndex < ZIPWIRE_IP_NUM_LOGIC_INSTANCE_MAX; LocInstanceIndex++)
    {
        if (NULL_PTR != s_ppaxLogicInstanceInit[LocInstanceIndex])
        {
            Zipwire_Ip_InitInstance(s_ppaxLogicInstanceInit[LocInstanceIndex]);
        }
        else
        {
            ZIPWIRE_IP_DEV_ASSERT(FALSE);
        }
    }

    /* Save pointer to initialization structure for LogicChannelConfig */
    s_ppaxLogicChannelInit = pxZipwireConfig->ZipwireIpChannelCfg->LogicChannelConfigList;

    for (LocChannelIndex = 0U; LocChannelIndex < ZIPWIRE_IP_NUM_LOGIC_CHANNEL_MAX; LocChannelIndex++)
    {
        if (NULL_PTR != s_ppaxLogicChannelInit[LocChannelIndex])
        {
            Zipwire_Ip_InitChannel(s_ppaxLogicChannelInit[LocChannelIndex]);
        }
        else
        {
            ZIPWIRE_IP_DEV_ASSERT(FALSE);
        }
    }

}


/**
 * @brief         Deinitializes the ZIPWIRE Driver settings based on user configuration.
 * @implements    Zipwire_Ip_DeInit_Activity
 */
void Zipwire_Ip_DeInit(const Zipwire_Ip_ConfigType *const pxZipwireConfig)
{
    uint32 LocInstanceIndex = 0U;

    ZIPWIRE_IP_DEV_ASSERT(NULL_PTR != pxZipwireConfig);

    /* Save pointer to initialization structure for LogicInstanceConfigList */
    s_ppaxLogicInstanceInit = pxZipwireConfig->ZipwireIpInstanceCfg->LogicInstanceConfigList;
    for (LocInstanceIndex = 0U; LocInstanceIndex < ZIPWIRE_IP_NUM_LOGIC_INSTANCE_MAX; LocInstanceIndex++)
    {
        if (NULL_PTR != s_ppaxLogicInstanceInit[LocInstanceIndex])
        {
            Zipwire_Ip_DeInitInstance(LocInstanceIndex);
        }
        else
        {
            ZIPWIRE_IP_DEV_ASSERT(FALSE);
        }
    }
}

/**
 * @brief         This function performs multiple read transfers, asynchronously.
 * @implements    Zipwire_Ip_Read_Activity
 */
Zipwire_Ip_StatusType Zipwire_Ip_Read(uint8 HwInstance,
                                      uint8 HwChannel,
                                      Zipwire_Ip_TransferDescriptor *DataArray,
                                      uint32 DataArrayLength)
{
    Zipwire_Ip_StatusType ReadStatus;

    /* Launch the read command and return */
    ReadStatus = Zipwire_Ip_LaunchRWCommand(HwInstance, HwChannel, DataArray, DataArrayLength, FALSE, FALSE);

    return ReadStatus;
}


/**
 * @brief         This function performs multiple read transfers, asynchronously and
 *                waits for either transfer completion or timeout Event.
 * @implements    Zipwire_Ip_ReadBlocking_Activity
 */
Zipwire_Ip_StatusType Zipwire_Ip_ReadBlocking(uint8 HwInstance,
                                              uint8 HwChannel,
                                              Zipwire_Ip_TransferDescriptor *DataArray,
                                              uint32 DataArrayLength)
{
    Zipwire_Ip_SIPI_Channel_Type *pxSipiChannelBase = s_ZipwireSipiChannels[HwInstance][HwChannel];
    Zipwire_Ip_StatusType ReadBlockingStatus;
    Zipwire_Ip_ChannelState *ChannelState = &s_axLogicChannelState[HwInstance][HwChannel];

    /* Launch the read command */
    ReadBlockingStatus = Zipwire_Ip_LaunchRWCommand(HwInstance, HwChannel, DataArray, DataArrayLength, FALSE, TRUE);

    if (ReadBlockingStatus != ZIPWIRE_IP_STATUS_SUCCESS)
    {
        return ReadBlockingStatus;
    }
    else
    {
        /* Wait for all the read requests to be serviced */
        uint32 StartTime, ElapsedTime, TimeoutTicks;
        Zipwire_Ip_StartTimeout(&StartTime, &ElapsedTime, &TimeoutTicks, ZIPWIRE_IP_TIMEOUT_COUNTER);
        while(!Zipwire_Ip_TimeoutExpired(&StartTime, &ElapsedTime, TimeoutTicks));

        if (ReadBlockingStatus == ZIPWIRE_IP_STATUS_TIMEOUT)
        {
            ChannelState->IsBlocking = FALSE;
            /* In case of timeout, disable channel logic, so no answers are considered beyond this point */
            hwAccZipwireSipi_SetChannelInterrupt(pxSipiChannelBase, SIPI_READ_ANSWER_IRQ, FALSE);
            hwAccZipwireSipi_SetChannelReadRequest(pxSipiChannelBase, FALSE);
            /* Update channel status */
            ChannelState->ChannelStatus = ZIPWIRE_IP_STATUS_TIMEOUT;
        }
    }

    return ChannelState->ChannelStatus;
}


#if (STD_ON == ZIPWIRE_IP_DMA_IS_AVAILABLE)
/**
 * @brief         This function performs multiple read transfers using DMA.
 *                The function returns right after launching the first command.
 * @implements    Zipwire_Ip_ReadDma_Activity
 */
Zipwire_Ip_StatusType Zipwire_Ip_ReadDma(uint8 HwInstance,
                             uint8 HwChannel,
                             uint32 *DataArray,
                             const uint32 *AddressArray,
                             uint32 DataArrayLength)
{
    Zipwire_Ip_StatusType ReadDmaStatus;

    /* Launch the read command and return */
    ReadDmaStatus = Zipwire_Ip_LaunchRWCommandWithDma(HwInstance, HwChannel, DataArray, AddressArray,
                                          DataArrayLength, FALSE, FALSE);

    return ReadDmaStatus;
}


/**
 * @brief         This function performs multiple read transfers using DMA and
 *                waits for either transfer completion or timeout Event.
 * @implements    Zipwire_Ip_ReadDmaBlocking_Activity
 */
Zipwire_Ip_StatusType Zipwire_Ip_ReadDmaBlocking(uint8 HwInstance,
                                                uint8 HwChannel,
                                                uint32 *DataArray,
                                                const uint32 *AddressArray,
                                                uint32 DataArrayLength)
{

    Zipwire_Ip_StatusType ReadDmaBlockingStatus;
    SIPI_Type *pxSipiBase = s_ZipwireSipiInstances[HwInstance];
    Zipwire_Ip_SIPI_Channel_Type *pxSipiChannelBase = s_ZipwireSipiChannels[HwInstance][HwChannel];
    Zipwire_Ip_ChannelState *ChannelState = &s_axLogicChannelState[HwInstance][HwChannel];

    /* Launch the read command */
    ReadDmaBlockingStatus = Zipwire_Ip_LaunchRWCommandWithDma(HwInstance, HwChannel, DataArray, AddressArray,
                                                              DataArrayLength, FALSE, TRUE);

    if (ReadDmaBlockingStatus != ZIPWIRE_IP_STATUS_SUCCESS)
    {
        return ReadDmaBlockingStatus;
    }
    else
    {
        /* Wait for all the read requests to be serviced */
        uint32 StartTime, ElapsedTime, TimeoutTicks;
        Zipwire_Ip_StartTimeout(&StartTime, &ElapsedTime, &TimeoutTicks, ZIPWIRE_IP_TIMEOUT_COUNTER);
        while(!Zipwire_Ip_TimeoutExpired(&StartTime, &ElapsedTime, TimeoutTicks));

        if (ReadDmaBlockingStatus == ZIPWIRE_IP_STATUS_TIMEOUT)
        {
            ChannelState->IsBlocking = FALSE;
            /* Move SIPI to INIT mode */
            hwAccZipwireSipi_EnterInitMode(pxSipiBase);
            /* Disable HwChannel DMA */
            hwAccZipwireSipi_EnableChannelDma(pxSipiChannelBase, FALSE);
            /* Move SIPI back to normal mode */
            hwAccZipwireSipi_ExitInitMode(pxSipiBase);
            /* Disable HwChannel read requests */
            hwAccZipwireSipi_SetChannelReadRequest(pxSipiChannelBase, FALSE);
            /* Update HwChannel status */
            ChannelState->ChannelStatus = ZIPWIRE_IP_STATUS_TIMEOUT;
        }
    }

    return ChannelState->ChannelStatus;
}
#endif /* #if (STD_ON == ZIPWIRE_IP_DMA_IS_AVAILABLE) */



/**
 * @brief         This function performs multiple write transfers, asynchronously.
 * @implements    Zipwire_Ip_Write_Activity
 */
Zipwire_Ip_StatusType Zipwire_Ip_Write(uint8 HwInstance,
                                      uint8 HwChannel,
                                      Zipwire_Ip_TransferDescriptor *DataArray,
                                      uint32 DataArrayLength)
{
    Zipwire_Ip_StatusType WriteStatus;

    /* Launch the write command and return */
    WriteStatus = Zipwire_Ip_LaunchRWCommand(HwInstance, HwChannel, DataArray,
                                   DataArrayLength, TRUE, FALSE);

    return WriteStatus;
}


/**
 * @brief         This function performs multiple write transfers, synchronously.
 * @implements    Zipwire_Ip_WriteBlocking_Activity
 */
Zipwire_Ip_StatusType Zipwire_Ip_WriteBlocking(uint8 HwInstance,
                                               uint8 HwChannel,
                                               Zipwire_Ip_TransferDescriptor *DataArray,
                                               uint32 DataArrayLength)
{

    Zipwire_Ip_SIPI_Channel_Type *pxSipiChannelBase = s_ZipwireSipiChannels[HwInstance][HwChannel];
    Zipwire_Ip_ChannelState *ChannelState = &s_axLogicChannelState[HwInstance][HwChannel];
    
    Zipwire_Ip_StatusType WriteBlockingStatus;

    /* Launch the write command */
    WriteBlockingStatus = Zipwire_Ip_LaunchRWCommand(HwInstance, HwChannel, DataArray,
                                   DataArrayLength, TRUE, TRUE);

    if (WriteBlockingStatus != ZIPWIRE_IP_STATUS_SUCCESS)
    {
        return WriteBlockingStatus;
    }
    else
    {
        /* Wait for all the write requests to be serviced */
        uint32 StartTime, ElapsedTime, TimeoutTicks;
        Zipwire_Ip_StartTimeout(&StartTime, &ElapsedTime, &TimeoutTicks, ZIPWIRE_IP_TIMEOUT_COUNTER);
        while(!Zipwire_Ip_TimeoutExpired(&StartTime, &ElapsedTime, TimeoutTicks));

        if (WriteBlockingStatus == ZIPWIRE_IP_STATUS_SUCCESS)
        {
            ChannelState->IsBlocking = FALSE;
            /* In case of timeout, disable channel logic, so no ACK is considered beyond this point */
            hwAccZipwireSipi_SetChannelInterrupt(pxSipiChannelBase, SIPI_ACK_IRQ, FALSE);
            hwAccZipwireSipi_SetChannelWriteRequest(pxSipiChannelBase, FALSE);
            /* Update channel status */
            ChannelState->ChannelStatus = ZIPWIRE_IP_STATUS_SUCCESS;
        }
    }

    return ChannelState->ChannelStatus;
}


#if (STD_ON == ZIPWIRE_IP_DMA_IS_AVAILABLE)
/**
 * @brief         This function performs multiple write transfers using DMA.
 *                The function returns right after launching the first command.
 * @implements    Zipwire_Ip_WriteDma_Activity
 */
Zipwire_Ip_StatusType Zipwire_Ip_WriteDma(uint8 HwInstance,
                              uint8 HwChannel,
                              const uint32 *DataArray,
                              const uint32 *AddressArray,
                              uint32 DataArrayLength)
{
    Zipwire_Ip_StatusType WriteDmaStatus;

    /* Launch the write command and return */
    WriteDmaStatus = Zipwire_Ip_LaunchRWCommandWithDma(HwInstance, HwChannel, (uint32 *)DataArray,
                                          AddressArray, DataArrayLength, TRUE, FALSE);

    return WriteDmaStatus;
}


/**
 * @brief         This function performs multiple write transfers using DMA and
 *                waits for either transfer completion or timeout Event.
 * @implements    Zipwire_Ip_WriteDmaBlocking_Activity
 */
Zipwire_Ip_StatusType Zipwire_Ip_WriteDmaBlocking(uint8 HwInstance,
                                      uint8 HwChannel,
                                      const uint32 *DataArray,
                                      const uint32 *AddressArray,
                                      uint32 DataArrayLength)
{
    Zipwire_Ip_StatusType WriteDmaBlockingStatus;
    Zipwire_Ip_ChannelState *ChannelState = &s_axLogicChannelState[HwInstance][HwChannel];
    SIPI_Type *pxSipiBase = s_ZipwireSipiInstances[HwInstance];
    Zipwire_Ip_SIPI_Channel_Type *pxSipiChannelBase = s_ZipwireSipiChannels[HwInstance][HwChannel];

    /* Launch the write command */
    WriteDmaBlockingStatus = Zipwire_Ip_LaunchRWCommandWithDma(HwInstance, HwChannel, (uint32 *)DataArray,
                                          AddressArray, DataArrayLength, TRUE, TRUE);

    if (WriteDmaBlockingStatus != ZIPWIRE_IP_STATUS_SUCCESS)
    {
        return WriteDmaBlockingStatus;
    }
    else
    {
        /* Wait for all the write requests to be serviced */
        uint32 StartTime, ElapsedTime, TimeoutTicks;
        Zipwire_Ip_StartTimeout(&StartTime, &ElapsedTime, &TimeoutTicks, ZIPWIRE_IP_TIMEOUT_COUNTER);
        while(!Zipwire_Ip_TimeoutExpired(&StartTime, &ElapsedTime, TimeoutTicks));

        if (WriteDmaBlockingStatus == ZIPWIRE_IP_STATUS_TIMEOUT)
        {
            ChannelState->IsBlocking = FALSE;
            /* Move SIPI to INIT mode */
            hwAccZipwireSipi_EnterInitMode(pxSipiBase);
            /* Disable HwChannel DMA */
            hwAccZipwireSipi_EnableChannelDma(pxSipiChannelBase, FALSE);
            /* Move SIPI back to normal mode */
            hwAccZipwireSipi_ExitInitMode(pxSipiBase);
            /* Disable HwChannel write requests */
            hwAccZipwireSipi_SetChannelWriteRequest(pxSipiChannelBase, FALSE);
            /* Update HwChannel WriteDmaBlockingStatusus */
            ChannelState->ChannelStatus = ZIPWIRE_IP_STATUS_TIMEOUT;
        }
    }

    return ChannelState->ChannelStatus;
}
#endif /* #if (STD_ON == ZIPWIRE_IP_DMA_IS_AVAILABLE) */


/**
 * @brief         This function performs a streaming write operation synchronously.
 * @implements    Zipwire_Ip_StreamWrite_Activity
 */
Zipwire_Ip_StatusType Zipwire_Ip_StreamWrite(uint8 HwInstance,
                                 uint8 HwChannel,
                                 uint32 DataAddress,
                                 uint32 TargetAcrRegAddress,
                                 const uint32 *Data)
{
    ZIPWIRE_IP_DEV_ASSERT(HwInstance < ZIPWIRE_IP_INSTANCE_COUNT_U8);
    ZIPWIRE_IP_DEV_ASSERT(HwChannel == ZIPWIRE_IP_STREAMING_CHANNEL);
    ZIPWIRE_IP_DEV_ASSERT(Data != NULL_PTR);

    uint8 StreamCounter;
    Zipwire_Ip_TransferDescriptor TargetConfig;
    Zipwire_Ip_StatusType StreamWriteStatus;
    Zipwire_Ip_ChannelState *ChannelState = &s_axLogicChannelState[HwInstance][HwChannel];
    Zipwire_Ip_SIPI_Channel_Type *pxSipiChannelBase = s_ZipwireSipiChannels[HwInstance][HwChannel];

    /* Create a transfer descriptor for configuring target address in the ACR register */
    TargetConfig.TransferSize = ZIPWIRE_32_BITS;
    TargetConfig.Address = TargetAcrRegAddress;
    TargetConfig.Data = DataAddress;
    /* Temporary disable notifications */
    ChannelState->DisableNotification = TRUE;
    /* Perform a single write command to set the address count register at the target node */
    StreamWriteStatus = Zipwire_Ip_WriteBlocking(HwInstance, HwChannel, &TargetConfig, 1U);
    /* Enable back success notification */
    ChannelState->DisableNotification = FALSE;
    if (StreamWriteStatus != ZIPWIRE_IP_STATUS_SUCCESS)
    {
        return StreamWriteStatus;
    }

    /* Channel setup */
    ChannelState->IsBlocking = TRUE;
    ChannelState->ChannelStatus = ZIPWIRE_IP_STATUS_BUSY;
    ChannelState->RemainingTransfers = 0U;

    /* Fill in the Data for the streaming transfer */
    for (StreamCounter = 0U; StreamCounter < ZIPWIRE_IP_SIPI_STREAM_TRANSFER_LEN; StreamCounter++)
    {
        ZIPWIRE_IP_SIPI_STREAM_DATA(StreamCounter) = *Data;
        Data++;
    }

    /* Enable write ACK interrupt */
    hwAccZipwireSipi_SetChannelInterrupt(pxSipiChannelBase, SIPI_ACK_IRQ, TRUE);
    /* Enable write and streaming requests */
    hwAccZipwireSipi_SetChannelWriteRequest(pxSipiChannelBase, TRUE);
    hwAccZipwireSipi_SetChannelStreamingWriteRequest(pxSipiChannelBase, TRUE);
    /* Write address register with dummy value to trigger the transfer */
    hwAccZipwireSipi_SetChannelAddr(pxSipiChannelBase, 0U);

    /* Wait for the write request to be serviced */
    uint32 StartTime, ElapsedTime, TimeoutTicks;
    Zipwire_Ip_StartTimeout(&StartTime, &ElapsedTime, &TimeoutTicks, ZIPWIRE_IP_TIMEOUT_COUNTER);
    while(!Zipwire_Ip_TimeoutExpired(&StartTime, &ElapsedTime, TimeoutTicks));

    if (StreamWriteStatus == ZIPWIRE_IP_STATUS_TIMEOUT)
    {
        ChannelState->IsBlocking = FALSE;
        /* In case of Timeout, disable HwChannel logic, so no ACK is considered beyond this point */
        hwAccZipwireSipi_SetChannelInterrupt(pxSipiChannelBase, SIPI_ACK_IRQ, FALSE);
        hwAccZipwireSipi_SetChannelStreamingWriteRequest(pxSipiChannelBase, FALSE);
        hwAccZipwireSipi_SetChannelWriteRequest(pxSipiChannelBase, FALSE);
        /* Update HwChannel status */
        ChannelState->ChannelStatus = ZIPWIRE_IP_STATUS_TIMEOUT;
    }

    return ChannelState->ChannelStatus;
}


/**
 * @brief         This function performs an ID request transfer.
 *
 * @implements    Zipwire_Ip_RequestId_Activity
 */
Zipwire_Ip_StatusType Zipwire_Ip_RequestId(uint8 HwInstance, uint8 HwChannel, uint32 *Id)
{
    ZIPWIRE_IP_DEV_ASSERT(HwInstance < ZIPWIRE_IP_INSTANCE_COUNT_U8);
    ZIPWIRE_IP_DEV_ASSERT(HwChannel < ZIPWIRE_IP_CHANNEL_COUNT_U8);
    ZIPWIRE_IP_DEV_ASSERT(Id != NULL_PTR);

    Zipwire_Ip_StatusType RequestIdStatus;
    Zipwire_Ip_ChannelState *ChannelState = &s_axLogicChannelState[HwInstance][HwChannel];
    Zipwire_Ip_SIPI_Channel_Type *pxSipiChannelBase = s_ZipwireSipiChannels[HwInstance][HwChannel];

    /* Check if channel is busy with another transfer */
    if (ChannelState->ChannelStatus == ZIPWIRE_IP_STATUS_BUSY)
    {
        return ZIPWIRE_IP_STATUS_BUSY;
    }

    /* Transfer setup */
    ChannelState->IdRequest = TRUE;
    ChannelState->RemainingTransfers = 0U;
    ChannelState->TargetId = Id;
    /* Channel becomes busy now */
    ChannelState->ChannelStatus = ZIPWIRE_IP_STATUS_BUSY;

    /* Enable ID request */
    hwAccZipwireSipi_SetChannelIdTransferRequest(pxSipiChannelBase, TRUE);
    /* Enable read answer interrupt */
    hwAccZipwireSipi_SetChannelInterrupt(pxSipiChannelBase, SIPI_READ_ANSWER_IRQ, TRUE);
    /* Set the target address - dummy value to trigger the transfer */
    hwAccZipwireSipi_SetChannelAddr(pxSipiChannelBase, 0U);

    /* Wait for the ID request to be serviced */
    uint32 StartTime, ElapsedTime, TimeoutTicks;
    Zipwire_Ip_StartTimeout(&StartTime, &ElapsedTime, &TimeoutTicks, ZIPWIRE_IP_TIMEOUT_COUNTER);
    while(!Zipwire_Ip_TimeoutExpired(&StartTime, &ElapsedTime, TimeoutTicks));

    if (RequestIdStatus == ZIPWIRE_IP_STATUS_TIMEOUT)
    {
        ChannelState->IsBlocking = FALSE;
        /* In case of Timeout, disable HwChannel logic, so no ACK is considered beyond this point */
        hwAccZipwireSipi_SetChannelInterrupt(pxSipiChannelBase, SIPI_READ_ANSWER_IRQ, FALSE);
        hwAccZipwireSipi_SetChannelIdTransferRequest(pxSipiChannelBase, FALSE);
        /* Update HwChannel status */
        ChannelState->ChannelStatus = ZIPWIRE_IP_STATUS_TIMEOUT;
    }

    return ChannelState->ChannelStatus;
}


/**
 * @brief         This function sends a trigger command to the target.
 * @implements    Zipwire_Ip_Trigger_Activity
 */
Zipwire_Ip_StatusType Zipwire_Ip_Trigger(uint8 HwInstance, uint8 HwChannel)
{
    ZIPWIRE_IP_DEV_ASSERT(HwInstance < ZIPWIRE_IP_INSTANCE_COUNT_U8);
    ZIPWIRE_IP_DEV_ASSERT(HwChannel < ZIPWIRE_IP_CHANNEL_COUNT_U8);

    Zipwire_Ip_StatusType TrigerStatus;
    Zipwire_Ip_ChannelState *ChannelState = &s_axLogicChannelState[HwInstance][HwChannel];
    Zipwire_Ip_SIPI_Channel_Type *pxSipiChannelBase = s_ZipwireSipiChannels[HwInstance][HwChannel];

    /* Check if channel is busy with another transfer */
    if (ChannelState->ChannelStatus != ZIPWIRE_IP_STATUS_BUSY)
    {
        /* Transfer setup */
        ChannelState->IsBlocking = TRUE;
        ChannelState->RemainingTransfers = 0U;
        ChannelState->IdRequest = FALSE;
        /* Channel becomes busy now */
        ChannelState->ChannelStatus = ZIPWIRE_IP_STATUS_BUSY;

        /* Enable read answer interrupt */
        hwAccZipwireSipi_SetChannelInterrupt(pxSipiChannelBase, SIPI_ACK_IRQ, TRUE);
        /* Send ID request */
        hwAccZipwireSipi_SetChannelTriggerCommand(pxSipiChannelBase, TRUE);

        /* Wait for the ID request to be serviced */
        uint32 StartTime, ElapsedTime, TimeoutTicks;
        Zipwire_Ip_StartTimeout(&StartTime, &ElapsedTime, &TimeoutTicks, ZIPWIRE_IP_TIMEOUT_COUNTER);
        while(!Zipwire_Ip_TimeoutExpired(&StartTime, &ElapsedTime, TimeoutTicks));

        if (TrigerStatus == ZIPWIRE_IP_STATUS_TIMEOUT)
        {
            ChannelState->IsBlocking = FALSE;
            /* In case of Timeout, disable HwChannel logic, so no ACK is considered beyond this point */
            hwAccZipwireSipi_SetChannelInterrupt(pxSipiChannelBase, SIPI_ACK_IRQ, FALSE);
            hwAccZipwireSipi_SetChannelTriggerCommand(pxSipiChannelBase, FALSE);
            /* Update HwChannel status */
            ChannelState->ChannelStatus = ZIPWIRE_IP_STATUS_TIMEOUT;
        }
    }
    return ChannelState->ChannelStatus;
}


/**
 * @brief         This function returns the current channel status.
 * @implements    Zipwire_Ip_GetChannelStatus_Activity
 */
Zipwire_Ip_StatusType Zipwire_Ip_GetChannelStatus(uint8 HwInstance, uint8 HwChannel)
{
    ZIPWIRE_IP_DEV_ASSERT(HwInstance < ZIPWIRE_IP_INSTANCE_COUNT_U8);
    ZIPWIRE_IP_DEV_ASSERT(HwChannel < ZIPWIRE_IP_CHANNEL_COUNT_U8);

    return s_axLogicChannelState[HwInstance][HwChannel].ChannelStatus;
}


/**
 * @brief         This function installs a global Callback for the driver.
 * @implements    Zipwire_Ip_InstallGlobalCallback_Activity
 */
Zipwire_Ip_Callback Zipwire_Ip_InstallGlobalCallback(uint8 HwInstance,
                                                     Zipwire_Ip_Callback CallbackFunction,
                                                     void * CallbackParam)
{
    ZIPWIRE_IP_DEV_ASSERT(HwInstance < ZIPWIRE_IP_INSTANCE_COUNT_U8);

    Zipwire_Ip_InstanceState * InstanceState;

    InstanceState = &s_axLogicInstanceState[HwInstance];

    /* Save the previous callback and set the new one */
    Zipwire_Ip_Callback CurrentCallback = InstanceState->Callback;
    InstanceState->Callback = CallbackFunction;
    InstanceState->CallbackParam = CallbackParam;

    return CurrentCallback;
}


/**
 * @brief         This function installs a callback for a zipwire channel
 * @implements    Zipwire_Ip_InstallChannelCallback_Activity
 */
Zipwire_Ip_ChannelCallback Zipwire_Ip_InstallChannelCallback(uint8 HwInstance,
                                                          uint8 HwChannel,
                                                          Zipwire_Ip_ChannelCallback CallbackFunction,
                                                          void * CallbackParam)
{
    ZIPWIRE_IP_DEV_ASSERT(HwInstance < ZIPWIRE_IP_INSTANCE_COUNT_U8);
    ZIPWIRE_IP_DEV_ASSERT(HwChannel < ZIPWIRE_IP_CHANNEL_COUNT_U8);

    Zipwire_Ip_ChannelState * ChannelState;

    ChannelState = &s_axLogicChannelState[HwInstance][HwChannel];

    /* Save the previous callback and set the new one */
    Zipwire_Ip_ChannelCallback CurrentCallback = ChannelState->Callback;
    ChannelState->Callback = CallbackFunction;
    ChannelState->CallbackParam = CallbackParam;

    return CurrentCallback;
}
/*==================================================================================================
*                                      PRIVATE FUNCTIONS
==================================================================================================*/
/**
* @brief         Zipwire_Ip_StartTimeout
* @implements    Zipwire_Ip_StartTimeout_Activity
*/
static void Zipwire_Ip_StartTimeout(uint32 *StartTimeOut,
                                    uint32 *ElapsedTimeOut,
                                    uint32 *TimeoutTicksOut,
                                    uint32 TimeoutUs)
{
    *StartTimeOut    = OsIf_GetCounter(ZIPWIRE_IP_TIMEOUT_TYPE);
    *ElapsedTimeOut  = 0U;
    *TimeoutTicksOut = OsIf_MicrosToTicks(TimeoutUs, ZIPWIRE_IP_TIMEOUT_TYPE);
}


/**
* @brief         Zipwire_Ip_TimeoutExpired
* @implements    Zipwire_Ip_TimeoutExpired_Activity
*/
static boolean Zipwire_Ip_TimeoutExpired(uint32 *startTimeInOut,
                                        uint32 *elapsedTimeInOut,
                                        uint32 TimeoutTicks)
{
    *elapsedTimeInOut += OsIf_GetElapsed(startTimeInOut, ZIPWIRE_IP_TIMEOUT_TYPE);

    return ((*elapsedTimeInOut >= TimeoutTicks)? TRUE : FALSE);
}
/**
 * @brief         This internal function launches a read/Write command at the
 *                initiator.
 * @implements    Zipwire_Ip_LaunchRWCommand
 */
static Zipwire_Ip_StatusType Zipwire_Ip_LaunchRWCommand(uint8 HwInstance,
                                        uint8 HwChannel,
                                        Zipwire_Ip_TransferDescriptor *DataArray,
                                        uint32 DataArrayLength,
                                        boolean Write,
                                        boolean IsBlocking)
{
    ZIPWIRE_IP_DEV_ASSERT(HwInstance < ZIPWIRE_IP_INSTANCE_COUNT_U8);
    ZIPWIRE_IP_DEV_ASSERT(HwChannel < ZIPWIRE_IP_CHANNEL_COUNT_U8);
    ZIPWIRE_IP_DEV_ASSERT(DataArray != NULL_PTR);
    ZIPWIRE_IP_DEV_ASSERT(DataArrayLength > 0U);

    Zipwire_Ip_ChannelState *ChannelState = &s_axLogicChannelState[HwInstance][HwChannel];
    Zipwire_Ip_SIPI_Channel_Type *pxSipiChannelBase = s_ZipwireSipiChannels[HwInstance][HwChannel];


    /* Check if HwChannel is busy with another transfer */
    if (ChannelState->ChannelStatus == ZIPWIRE_IP_STATUS_BUSY)
    {
        return ZIPWIRE_IP_STATUS_BUSY;
    }

    /* Transfer setup */
    ChannelState->IsBlocking = IsBlocking;
    ChannelState->TransferBuffer = DataArray;
    ChannelState->RemainingTransfers = DataArrayLength - 1U;
    ChannelState->IdRequest = FALSE;
    /* Channel becomes busy now */
    ChannelState->ChannelStatus = ZIPWIRE_IP_STATUS_BUSY;

    if (Write)
    {
        /* Write transfer */

        /* Enable Write request */
        hwAccZipwireSipi_SetChannelWriteRequest(pxSipiChannelBase, TRUE);
        /* Enable Write ACK interrupt */
        hwAccZipwireSipi_SetChannelInterrupt(pxSipiChannelBase, SIPI_ACK_IRQ, TRUE);
        /* Write the DataArray and trigger the transfer */
        Zipwire_Ip_WriteData(HwInstance, HwChannel, DataArray);
    }
    else
    {
        /* Read transfer */

        /* Configure the word length */
        hwAccZipwireSipi_SetChannelWordLength(pxSipiChannelBase, DataArray->TransferSize);
        /* Enable read request */
        hwAccZipwireSipi_SetChannelReadRequest(pxSipiChannelBase, TRUE);
        /* Enable read answer interrupt */
        hwAccZipwireSipi_SetChannelInterrupt(pxSipiChannelBase, SIPI_READ_ANSWER_IRQ, TRUE);
        /* Set the target address - this will trigger the transfer */
        hwAccZipwireSipi_SetChannelAddr(pxSipiChannelBase, DataArray->Address);
    }

    return ZIPWIRE_IP_STATUS_SUCCESS;
}



#if (STD_ON == ZIPWIRE_IP_DMA_IS_AVAILABLE)
/**
 * @brief         This internal function launches a Read/WriteEnable command at the
 *                initiator using DMA requests.
 *
 * @implements    Zipwire_Ip_LaunchRWCommandWithDma_Activity
 */
static Zipwire_Ip_StatusType Zipwire_Ip_LaunchRWCommandWithDma(uint8 HwInstance,
                                                                uint8 HwChannel,
                                                                uint32 *DataArray,
                                                                const uint32 *AddressArray,
                                                                uint32 DataArrayLength,
                                                                boolean WriteEnable,
                                                                boolean IsBlocking)
{
    ZIPWIRE_IP_DEV_ASSERT(HwInstance < ZIPWIRE_IP_INSTANCE_COUNT_U8);
    ZIPWIRE_IP_DEV_ASSERT(HwChannel < ZIPWIRE_IP_CHANNEL_COUNT_U8);
    ZIPWIRE_IP_DEV_ASSERT(AddressArray != NULL_PTR);
    ZIPWIRE_IP_DEV_ASSERT(DataArray != NULL_PTR);
    ZIPWIRE_IP_DEV_ASSERT(DataArrayLength > 0U);

    Zipwire_Ip_ChannelState *ChannelState = &s_axLogicChannelState[HwInstance][HwChannel];
    SIPI_Type *pxSipiBase = s_ZipwireSipiInstances[HwInstance];
    Zipwire_Ip_SIPI_Channel_Type *pxSipiChannelBase = s_ZipwireSipiChannels[HwInstance][HwChannel];

    ZIPWIRE_IP_DEV_ASSERT(ChannelState->DmaEnable);
    Dma_Ip_ReturnType DmaReturnStatusAddress;
    Dma_Ip_ReturnType DmaReturnStatusData;

    /* Check if channel is busy with another transfer */
    if (ChannelState->ChannelStatus == ZIPWIRE_IP_STATUS_BUSY)
    {
        return ZIPWIRE_IP_STATUS_BUSY;
    }

    
    /* Set up parameters for Dma_Ip_LogicChannelTransferListType Address Channel*/
    s_atAddressDmaTransferList[7U].Value = (WriteEnable ? DataArrayLength : (DataArrayLength - 1U));     /* DMA_IP_CH_SET_MAJORLOOP_COUNT */

    s_atAddressDmaTransferList[0U].Value = ((uint32)AddressArray);                                       /* DMA_IP_CH_SET_SOURCE_ADDRESS */
    s_atAddressDmaTransferList[3U].Value = (uint32)(&(pxSipiChannelBase->CAR));                          /* DMA_IP_CH_SET_DESTINATION_ADDRESS */
    s_atAddressDmaTransferList[1U].Value = 4;                                                            /* DMA_IP_CH_SET_SOURCE_SIGNED_OFFSET */
    s_atAddressDmaTransferList[4U].Value = 0;                                                            /* DMA_IP_CH_SET_DESTINATION_SIGNED_OFFSET */
    s_atAddressDmaTransferList[2U].Value = DMA_IP_TRANSFER_SIZE_4_BYTE;                                  /* DMA_IP_CH_SET_SOURCE_TRANSFER_SIZE */
    s_atAddressDmaTransferList[5U].Value = DMA_IP_TRANSFER_SIZE_4_BYTE;                                  /* DMA_IP_CH_SET_DESTINATION_TRANSFER_SIZE */
    
    s_atAddressDmaTransferList[8U].Value = WriteEnable;                                                  /* DMA_IP_CH_SET_CONTROL_EN_MAJOR_INTERRUPT */

    /* Set up parameters for Dma_Ip_LogicChannelTransferListType Data Channel*/
    s_atDataDmaTransferList[8U].Value = ChannelState->DmaAddrChn;                                                   /* DMA_IP_CH_SET_MINORLOOP_LOGIC_LINK_CH */
    s_atDataDmaTransferList[9U].Value = WriteEnable;                                                                /* DMA_IP_CH_SET_MAJORLOOP_EN_LINK */
    s_atDataDmaTransferList[10U].Value = ChannelState->DmaAddrChn;                                                  /* DMA_IP_CH_SET_MAJORLOOP_LOGIC_LINK_CH */
    s_atDataDmaTransferList[11U].Value = DataArrayLength;                                                           /* DMA_IP_CH_SET_MAJORLOOP_COUNT */
    s_atDataDmaTransferList[12U].Value = !WriteEnable;                                                              /* DMA_IP_CH_SET_CONTROL_EN_MAJOR_INTERRUPT */

    s_atDataDmaTransferList[0U].Value = (WriteEnable ? (uint32)(DataArray) : (uint32)(&(pxSipiChannelBase->CDR)));  /* DMA_IP_CH_SET_SOURCE_ADDRESS */
    s_atDataDmaTransferList[3U].Value = (WriteEnable ? (uint32)(&(pxSipiChannelBase->CDR)) : (uint32)(DataArray));  /* DMA_IP_CH_SET_DESTINATION_ADDRESS */
    s_atDataDmaTransferList[1U].Value = (WriteEnable ? (int16_t)4 : (int16_t)0);                                    /* DMA_IP_CH_SET_SOURCE_SIGNED_OFFSET */
    s_atDataDmaTransferList[4U].Value = (WriteEnable ? (int16_t)0 : (int16_t)4);                                    /* DMA_IP_CH_SET_DESTINATION_SIGNED_OFFSET */
    s_atDataDmaTransferList[2U].Value = DMA_IP_TRANSFER_SIZE_4_BYTE;                                                /* DMA_IP_CH_SET_SOURCE_TRANSFER_SIZE */
    s_atDataDmaTransferList[5U].Value = DMA_IP_TRANSFER_SIZE_4_BYTE;                                                /* DMA_IP_CH_SET_DESTINATION_TRANSFER_SIZE */

    /* Transfer setup */
    ChannelState->IsBlocking = IsBlocking;
    ChannelState->RemainingTransfers = 0U;
    ChannelState->IdRequest = FALSE;
    ChannelState->DmaWriteTransfer = WriteEnable;
    /* Channel becomes busy now */
    ChannelState->ChannelStatus = ZIPWIRE_IP_STATUS_BUSY;

    /* Enable DMA functionality for the channel */
    hwAccZipwireSipi_EnterInitMode(pxSipiBase);
    hwAccZipwireSipi_EnableChannelDma(pxSipiChannelBase, TRUE);
    hwAccZipwireSipi_ExitInitMode(pxSipiBase);

    /* Only 32 bits transfers supported in DMA mode */
    hwAccZipwireSipi_SetChannelWordLength(pxSipiChannelBase, ZIPWIRE_32_BITS);

    if (WriteEnable)
    {
        /* Enable WriteEnable request */
        hwAccZipwireSipi_SetChannelWriteRequest(pxSipiChannelBase, TRUE);
    }
    else
    {
        /* Enable WriteEnable request */
        hwAccZipwireSipi_SetChannelReadRequest(pxSipiChannelBase, TRUE);
        /* First address is written by sw, DMA starts transferring from the next */
        s_atAddressDmaTransferList[0U].Value += 4U; 
    }

    /* Set the DMA configurations in the two TCDs and start the channels */
    if (s_atAddressDmaTransferList[7U].Value > 0U)
    {
        DmaReturnStatusAddress = Dma_Ip_SetLogicChannelTransferList(ChannelState->DmaAddrChn, s_atAddressDmaTransferList, ZIPWIRE_IP_DMA_ADDRESS_CONFIG_DIMENSION);
        ZIPWIRE_IP_DEV_ASSERT(DmaReturnStatusAddress == DMA_IP_STATUS_SUCCESS);
        /* Start transfer with Dma Logic Channel Name */
        DmaReturnStatusAddress = Dma_Ip_SetLogicChannelCommand(ChannelState->DmaAddrChn, DMA_IP_CH_SET_SOFTWARE_REQUEST);
        ZIPWIRE_IP_DEV_ASSERT(DmaReturnStatusAddress == DMA_IP_STATUS_SUCCESS);
    }
    DmaReturnStatusData = Dma_Ip_SetLogicChannelTransferList(ChannelState->DmaDataChn, s_atDataDmaTransferList, ZIPWIRE_IP_DMA_DATA_CONFIG_DIMENSION);
    ZIPWIRE_IP_DEV_ASSERT(DmaReturnStatusData == DMA_IP_STATUS_SUCCESS);
    /* Start transfer with Dma Logic Channel Name */
    DmaReturnStatusData = Dma_Ip_SetLogicChannelCommand(ChannelState->DmaDataChn, DMA_IP_CH_SET_SOFTWARE_REQUEST);
    ZIPWIRE_IP_DEV_ASSERT(DmaReturnStatusData == DMA_IP_STATUS_SUCCESS);

    /* WriteEnable the first address to trigger the first Read transfer */
    if (!WriteEnable)
    {
        hwAccZipwireSipi_SetChannelAddr(pxSipiChannelBase, *AddressArray);
    }

    return ZIPWIRE_IP_STATUS_SUCCESS;
}


/**
 * @brief         This internal function represents the DMA Callback used
 *                internally by the driver to finish DMA transfers.
 *
 * @implements    Zipwire_Ip_DmaCallback_Activity
 */
void Zipwire_Ip_DmaCallback(void *ZipwireChannelState,  Dma_Ip_ReturnType DmaStatus)
{
    Zipwire_Ip_ChannelState *ChannelState = (Zipwire_Ip_ChannelState *)ZipwireChannelState;
    Zipwire_Ip_SIPI_Channel_Type *pxSipiChannelBase = s_ZipwireSipiChannels[ChannelState->HwInstance][ChannelState->HwChannel];

    Zipwire_Ip_Events Event;

    /* Disable read/write requests */
    if (ChannelState->DmaWriteTransfer)
    {
        hwAccZipwireSipi_SetChannelWriteRequest(pxSipiChannelBase, FALSE);
        hwAccZipwireSipi_ClearChannelFlag(pxSipiChannelBase, SIPI_ACK_FLAG);
        Event = ZIPWIRE_EVENT_WRITE_COMPLETE;
    }
    else
    {
        hwAccZipwireSipi_SetChannelReadRequest(pxSipiChannelBase, FALSE);
        hwAccZipwireSipi_ClearChannelFlag(pxSipiChannelBase, SIPI_READ_ANSWER_FLAG);
        Event = ZIPWIRE_EVENT_READ_COMPLETE;
    }

    /* Update internal DmaStatus */
    if (DmaStatus == DMA_IP_STATUS_SUCCESS)
    {
        ChannelState->ChannelStatus = ZIPWIRE_IP_STATUS_SUCCESS;
    }
    else
    {
        ChannelState->ChannelStatus = ZIPWIRE_IP_STATUS_ERROR;
    }

    /* If the transfer was blocking, notify the waiting thread */
    if (ChannelState->IsBlocking)
    {
        ChannelState->IsBlocking = FALSE;
    }
    /* Call the user Callback, if any */
    if (ChannelState->Callback != NULL_PTR)
    {
        if (DmaStatus == DMA_IP_STATUS_SUCCESS)
        {
            ChannelState->Callback(ChannelState->HwInstance, ChannelState->HwChannel, Event, ChannelState->CallbackParam);
        }
        else
        {
            ChannelState->Callback(ChannelState->HwInstance, ChannelState->HwChannel, ZIPWIRE_EVENT_DMA_ERR, ChannelState->CallbackParam);
        }
    }
}
#endif /* #if (STD_ON == ZIPWIRE_IP_DMA_IS_AVAILABLE) */


/**
 * @brief         This internal function stops the ongoing transfer.
 *
 * @implements    Zipwire_Ip_StopTransfer_Activity.
 */
static void Zipwire_Ip_StopTransfer(uint8 HwInstance, uint8 HwChannel)
{
    Zipwire_Ip_ChannelState *ChannelState = &s_axLogicChannelState[HwInstance][HwChannel];
    Zipwire_Ip_SIPI_Channel_Type *pxSipiChannelBase = s_ZipwireSipiChannels[HwInstance][HwChannel];


#if (STD_ON == ZIPWIRE_IP_DMA_IS_AVAILABLE)
    SIPI_Type *pxSipiBase = s_ZipwireSipiInstances[HwInstance];
    /* Stop DMA */
    if (ChannelState->DmaEnable)
    {
        hwAccZipwireSipi_EnterInitMode(pxSipiBase);
        hwAccZipwireSipi_EnableChannelDma(pxSipiChannelBase, FALSE);
        hwAccZipwireSipi_ExitInitMode(pxSipiBase);
    }
#endif /* #if (STD_ON == ZIPWIRE_IP_DMA_IS_AVAILABLE) */

    /* Disable all requests */
    pxSipiChannelBase->CCR &= ~(SIPI_CCR0_WRT_MASK | SIPI_CCR0_RRT_MASK | SIPI_CCR0_TC_MASK);
    /* Disable read answer/write ack interrupts */
    pxSipiChannelBase->CIR &= ~(SIPI_CIR0_WAIE_MASK | SIPI_CIR0_RAIE_MASK);
}


/**
 * @brief         This internal function computes the correct values for DataArray
 *                and Address registers for the desired DataArray to reach the right
 *                location at the target node.
 * @implements    Zipwire_Ip_WriteData_Activity
 */
static void Zipwire_Ip_WriteData(uint8 HwInstance, uint8 HwChannel, Zipwire_Ip_TransferDescriptor *DataArray)
{
    ZIPWIRE_IP_DEV_ASSERT((DataArray->TransferSize != ZIPWIRE_16_BITS) || ((DataArray->Address & 1U) == 0U));
    ZIPWIRE_IP_DEV_ASSERT((DataArray->TransferSize != ZIPWIRE_32_BITS) || ((DataArray->Address & 3U) == 0U));

    uint32 Address = DataArray->Address;
    Zipwire_Ip_SIPI_Channel_Type *pxSipiChannelBase = s_ZipwireSipiChannels[HwInstance][HwChannel];

    /* Configure transfer Size */
    hwAccZipwireSipi_SetChannelWordLength(pxSipiChannelBase, DataArray->TransferSize);

    switch (DataArray->TransferSize)
    {
        case ZIPWIRE_32_BITS:
            /* No processing needed for 32-bit words */
            hwAccZipwireSipi_SetChannelData(pxSipiChannelBase, DataArray->Data);
            break;
        case ZIPWIRE_16_BITS:
            /* For 16-bit words with multiple-of-4 addresses (ending in 0b00), Data needs to be shifted with 16 bits */
            hwAccZipwireSipi_SetChannelData(pxSipiChannelBase, (DataArray->Data << ((DataArray->Address & 2U) << 3U)));
            /* LSB of Address determines which half word will be transferred from the DataArray register */
            Address |= (((DataArray->Address & 2U) >> 1U) ^ 1U);
            break;
        case ZIPWIRE_8_BITS:
            /* For 8-bit transfers, Data needs to be shifted on the appropriate byte within the DATA register */
            hwAccZipwireSipi_SetChannelData(pxSipiChannelBase, (DataArray->Data << (((Address & 3U) ^ 3U) << 3U)));
            break;
        default:
            /* This branch should never be reached */
            ZIPWIRE_IP_DEV_ASSERT(FALSE);
            break;
    }

    /* Set the target Address - this will trigger the transfer */
    hwAccZipwireSipi_SetChannelAddr(pxSipiChannelBase, Address);
}

/*==================================================================================================
 *                                   IRQ HANDLER FUNCTIONS
==================================================================================================*/

/**
 * @brief         IRQ handler for read answer received interrupt.
 * 
 * @implements    Zipwire_Ip_Sipi_ChnReadAnswerHandler_Activity
 */
void Zipwire_Ip_Sipi_ChnReadAnswerHandler(uint8 HwInstance, uint8 HwChannel)
{
    Zipwire_Ip_ChannelState *ChannelState = &s_axLogicChannelState[HwInstance][HwChannel];
    Zipwire_Ip_SIPI_Channel_Type *pxSipiChannelBase = s_ZipwireSipiChannels[HwInstance][HwChannel];


    /* ID request serviced */
    if (ChannelState->IdRequest)
    {
        /* Get the received ID */
        *ChannelState->TargetId = ZIPWIRE_IP_SIPI_DATA(hwAccZipwireSipi_GetChannelData(pxSipiChannelBase), ZIPWIRE_32_BITS);

        /* Update HwChannel state */
        ChannelState->TargetId = NULL_PTR;
        ChannelState->IdRequest = FALSE;

        /* Disable the interrupt and the Id requests for this HwChannel */
        hwAccZipwireSipi_SetChannelInterrupt(pxSipiChannelBase, SIPI_READ_ANSWER_IRQ, FALSE);
        hwAccZipwireSipi_SetChannelIdTransferRequest(pxSipiChannelBase, FALSE);

        /* Update internal status */
        ChannelState->ChannelStatus = ZIPWIRE_IP_STATUS_SUCCESS;

        /* Call the user Callback, if any */
        if (ChannelState->Callback != NULL_PTR)
        {
        ChannelState->Callback(HwInstance, HwChannel, ZIPWIRE_EVENT_READ_COMPLETE, ChannelState->CallbackParam);
        }
    }
    /* Read request serviced */
    else
    {
        /* Get the received data in the user buffer */
        ChannelState->TransferBuffer->Data = ZIPWIRE_IP_SIPI_DATA(hwAccZipwireSipi_GetChannelData(pxSipiChannelBase), ChannelState->TransferBuffer->TransferSize);

        /* If this was the last transfer, disable this HwChannel from further listening for answers */
        if (ChannelState->RemainingTransfers == 0U)
        {
            /* Disable the interrupt and the read requests for this HwChannel */
            hwAccZipwireSipi_SetChannelInterrupt(pxSipiChannelBase, SIPI_READ_ANSWER_IRQ, FALSE);
            hwAccZipwireSipi_SetChannelReadRequest(pxSipiChannelBase, FALSE);

            /* Update internal status */
            ChannelState->ChannelStatus = ZIPWIRE_IP_STATUS_SUCCESS;

            /* If the transfer was blocking, notify the waiting thread */
            if (ChannelState->IsBlocking)
            {
                ChannelState->IsBlocking = FALSE;
            }

            /* Call the user Callback, if any */
            if (ChannelState->Callback != NULL_PTR)
            {
                ChannelState->Callback(HwInstance, HwChannel, ZIPWIRE_EVENT_READ_COMPLETE, ChannelState->CallbackParam);
            }
        }
        /* More transfers to be done */
        else
        {
            /* Update buffer reference */
            ChannelState->TransferBuffer++;
            ChannelState->RemainingTransfers--;

            /* Configure and launch the next transfer */
            hwAccZipwireSipi_SetChannelWordLength(pxSipiChannelBase, ChannelState->TransferBuffer->TransferSize);
            hwAccZipwireSipi_SetChannelAddr(pxSipiChannelBase, ChannelState->TransferBuffer->Address);
        }
    }
}


/**
 * @brief         IRQ handler for ACK received interrupt.
 * 
 * @implements    Zipwire_Ip_Sipi_ChnAckHandler_Activity
 */
void Zipwire_Ip_Sipi_ChnAckHandler(uint8 HwInstance, uint8 HwChannel)
{
    Zipwire_Ip_ChannelState *ChannelState = &s_axLogicChannelState[HwInstance][HwChannel];
    Zipwire_Ip_SIPI_Channel_Type *pxSipiChannelBase = s_ZipwireSipiChannels[HwInstance][HwChannel];

    /* If this was the last transfer, disable this channel from further writing data */
    if (ChannelState->RemainingTransfers == 0U)
    {
        /* Disable the interrupt and the write transfers for this HwChannel */
        hwAccZipwireSipi_SetChannelInterrupt(pxSipiChannelBase, SIPI_ACK_IRQ, FALSE);
        pxSipiChannelBase->CCR &= ~(SIPI_CCR0_WRT_MASK | SIPI_CCR0_TC_MASK);

        /* Update internal status */
        ChannelState->ChannelStatus = ZIPWIRE_IP_STATUS_SUCCESS;

        /* If the transfer was blocking, notify the waiting thread */
        if (ChannelState->IsBlocking)
        {
            ChannelState->IsBlocking = FALSE;
        }
        /* Call the user Callback, if any */
        if ((ChannelState->Callback != NULL_PTR) && (!(ChannelState->DisableNotification)))
        {
            ChannelState->Callback(HwInstance, HwChannel, ZIPWIRE_EVENT_WRITE_COMPLETE, ChannelState->CallbackParam);
        }
    }
    /* More transfers to be done */
    else
    {
        /* Update buffer reference */
        ChannelState->TransferBuffer++;
        ChannelState->RemainingTransfers--;

        /* Launch the next transfer */
        Zipwire_Ip_WriteData(HwInstance, HwChannel, ChannelState->TransferBuffer);
    }
}


/**
 * @brief         IRQ handler for trigger command received interrupt.
 * 
 * @implements    Zipwire_Ip_Sipi_ChnTriggerHandler_Activity
 */
void Zipwire_Ip_Sipi_ChnTriggerHandler(uint8 HwInstance, uint8 HwChannel)
{
    const Zipwire_Ip_ChannelState *ChannelState = &s_axLogicChannelState[HwInstance][HwChannel];
    if (ChannelState->Callback != NULL_PTR)
    {
        ChannelState->Callback(HwInstance, HwChannel, ZIPWIRE_EVENT_TRIGGER_COMMAND, ChannelState->CallbackParam);
    }
}


/**
 * @brief         IRQ handler for global CRC error interrupt.
 * 
 * @implements    Zipwire_Ip_Sipi_ZipwireErrHandler_Activity
 */
void Zipwire_Ip_Sipi_CrcErrHandler(uint8 HwInstance)
{
    const Zipwire_Ip_InstanceState *InstanceState = &s_axLogicInstanceState[HwInstance];
    if (InstanceState->Callback != NULL_PTR)
    {
        InstanceState->Callback(HwInstance, ZIPWIRE_EVENT_GLOBAL_CRC_ERR, InstanceState->CallbackParam);
    }
}


/**
 * @brief         IRQ handler for max count reached interrupt.
 * 
 * @implements    Zipwire_Ip_Sipi_MaxCountReachedHandler_Activity
 */
void Zipwire_Ip_Sipi_MaxCountReachedHandler(uint8 HwInstance)
{
    const Zipwire_Ip_InstanceState *InstanceState = &s_axLogicInstanceState[HwInstance];
    if (InstanceState->Callback != NULL_PTR)
    {
        InstanceState->Callback(HwInstance, ZIPWIRE_EVENT_MAX_COUNT_REACHED, InstanceState->CallbackParam);
    }
}


/**
 * @brief         IRQ handler for channel timeout error interrupt.
 * 
 * @implements    Zipwire_Ip_Sipi_ChnTimeoutErrHandler_Activity
 */
void Zipwire_Ip_Sipi_ChnTimeoutErrHandler(uint8 HwInstance, uint8 HwChannel)
{
    Zipwire_Ip_ChannelState *ChannelState = &s_axLogicChannelState[HwInstance][HwChannel];
    ChannelState->ChannelStatus = ZIPWIRE_IP_STATUS_ZIPWIRE_TIMEOUT_ERR;
    Zipwire_Ip_StopTransfer(HwInstance, HwChannel);
    if (ChannelState->Callback != NULL_PTR)
    {
        ChannelState->Callback(HwInstance, HwChannel, ZIPWIRE_EVENT_TIMEOUT_ERR, ChannelState->CallbackParam);
    }
}


/**
 * @brief         IRQ handler for channel transaction ID error interrupt.
 * 
 * @implements    Zipwire_Ip_Sipi_ChnTransIdErrHandler_Activity
 */
void Zipwire_Ip_Sipi_ChnTransIdErrHandler(uint8 HwInstance, uint8 HwChannel)
{
    Zipwire_Ip_ChannelState *ChannelState = &s_axLogicChannelState[HwInstance][HwChannel];
    ChannelState->ChannelStatus = ZIPWIRE_IP_STATUS_ZIPWIRE_TRANSACTION_ID_ERR;
    Zipwire_Ip_StopTransfer(HwInstance, HwChannel);
    if (ChannelState->Callback != NULL_PTR)
    {
        ChannelState->Callback(HwInstance, HwChannel, ZIPWIRE_EVENT_TRANSACTION_ID_ERR, ChannelState->CallbackParam);
    }
}


/**
 * @brief         IRQ handler for channel ACK error interrupt.
 * 
 * @implements    Zipwire_Ip_Sipi_ChnAckErrHandler_Activity
 */
void Zipwire_Ip_Sipi_ChnAckErrHandler(uint8 HwInstance, uint8 HwChannel)
{
    Zipwire_Ip_ChannelState *ChannelState = &s_axLogicChannelState[HwInstance][HwChannel];
    ChannelState->ChannelStatus = ZIPWIRE_IP_STATUS_ZIPWIRE_ACK_ERR;
    Zipwire_Ip_StopTransfer(HwInstance, HwChannel);
    if (ChannelState->Callback != NULL_PTR)
    {
        ChannelState->Callback(HwInstance, HwChannel, ZIPWIRE_EVENT_ACK_ERR, ChannelState->CallbackParam);
    }
}


#define ZIPWIRE_STOP_SEC_CODE
#include "Zipwire_MemMap.h"


#ifdef __cplusplus
}
#endif

/** @} */
