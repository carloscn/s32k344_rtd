/*==================================================================================================
*   Project              : RTD AUTOSAR 4.7
*   Platform             : CORTEXM
*   Peripheral           : 
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
*   @file    CDD_Zipwire.c
*
*   @version 3.0.0
*
*   @brief   AUTOSAR Zipwire - Zipwire driver source file.
*   @details
*
*   @addtogroup ZIPWIRE_HLD_DRIVER
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
#include "CDD_Zipwire.h"

#if (STD_ON == ZIPWIRE_DET_IS_AVAILABLE)
    #include "Det.h"
#endif



/*=================================================================================================
*                              SOURCE FILE VERSION INFORMATION
=================================================================================================*/
/**
* @brief Parameters that shall be published within the Zipwire driver header file and also in the
*        module's description file
*/
#define ZIPWIRE_VENDOR_ID_C                    43
#define ZIPWIRE_AR_RELEASE_MAJOR_VERSION_C     4
#define ZIPWIRE_AR_RELEASE_MINOR_VERSION_C     7
#define ZIPWIRE_AR_RELEASE_REVISION_VERSION_C  0
#define ZIPWIRE_SW_MAJOR_VERSION_C             3
#define ZIPWIRE_SW_MINOR_VERSION_C             0
#define ZIPWIRE_SW_PATCH_VERSION_C             0

/*=================================================================================================
*                                     FILE VERSION CHECKS
=================================================================================================*/

/* Check if source file and Zipwire header file are of the same vendor */
#if (ZIPWIRE_VENDOR_ID_C != CDD_ZIPWIRE_VENDOR_ID)
    #error "CDD_Zipwire.c and CDD_Zipwire.h have different vendor ids"
#endif

/* Check if source file and Zipwire header file are of the same Autosar version */
#if ((ZIPWIRE_AR_RELEASE_MAJOR_VERSION_C    != CDD_ZIPWIRE_AR_RELEASE_MAJOR_VERSION) || \
     (ZIPWIRE_AR_RELEASE_MINOR_VERSION_C    != CDD_ZIPWIRE_AR_RELEASE_MINOR_VERSION) || \
     (ZIPWIRE_AR_RELEASE_REVISION_VERSION_C != CDD_ZIPWIRE_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of CDD_Zipwire.c and CDD_Zipwire.h are different"
#endif

/* Check if source file and Zipwire header file are of the same Software version */
#if ((ZIPWIRE_SW_MAJOR_VERSION_C != CDD_ZIPWIRE_SW_MAJOR_VERSION) || \
     (ZIPWIRE_SW_MINOR_VERSION_C != CDD_ZIPWIRE_SW_MINOR_VERSION) || \
     (ZIPWIRE_SW_PATCH_VERSION_C != CDD_ZIPWIRE_SW_PATCH_VERSION)    \
    )
    #error "Software Version Numbers of CDD_Zipwire.c and CDD_Zipwire.h are different"
#endif

/* Check if source file and ZIPWIRE_Ipw.h file are of the same vendor */
#if (ZIPWIRE_VENDOR_ID_C != ZIPWIRE_IPW_VENDOR_ID)
    #error "CDD_Zipwire.c and ZIPWIRE_Ipw.h have different vendor ids"
#endif

/* Check if the source file and ZIPWIRE_Ipw.h file are of the same Autosar version */
#if ((ZIPWIRE_AR_RELEASE_MAJOR_VERSION_C    != ZIPWIRE_IPW_AR_RELEASE_MAJOR_VERSION) || \
     (ZIPWIRE_AR_RELEASE_MINOR_VERSION_C    != ZIPWIRE_IPW_AR_RELEASE_MINOR_VERSION) || \
     (ZIPWIRE_AR_RELEASE_REVISION_VERSION_C != ZIPWIRE_IPW_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of CDD_Zipwire.c and ZIPWIRE_Ipw.h are different"
#endif

/* Check if source file and Zipwire header file are of the same Software version */
#if ((ZIPWIRE_SW_MAJOR_VERSION_C != ZIPWIRE_IPW_SW_MAJOR_VERSION) || \
     (ZIPWIRE_SW_MINOR_VERSION_C != ZIPWIRE_IPW_SW_MINOR_VERSION) || \
     (ZIPWIRE_SW_PATCH_VERSION_C != ZIPWIRE_IPW_SW_PATCH_VERSION)    \
    )
    #error "Software Version Numbers of CDD_Zipwire.c and ZIPWIRE_Ipw.h are different"
#endif

#if (STD_ON == ZIPWIRE_DET_IS_AVAILABLE)
/* Check if the source file and ZIPWIRE_Ipw.h file are of the same Autosar version */
#if ((ZIPWIRE_AR_RELEASE_MAJOR_VERSION_C    != DET_AR_RELEASE_MAJOR_VERSION) || \
     (ZIPWIRE_AR_RELEASE_MINOR_VERSION_C    != DET_AR_RELEASE_MINOR_VERSION) || \
     (ZIPWIRE_AR_RELEASE_REVISION_VERSION_C != DET_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of CDD_Zipwire.c and Det.h are different"
#endif

/* Check if source file and Zipwire header file are of the same Software version */
#if ((ZIPWIRE_SW_MAJOR_VERSION_C != DET_SW_MAJOR_VERSION) || \
     (ZIPWIRE_SW_MINOR_VERSION_C != DET_SW_MINOR_VERSION) || \
     (ZIPWIRE_SW_PATCH_VERSION_C != DET_SW_PATCH_VERSION)    \
    )
    #error "Software Version Numbers of CDD_Zipwire.c and Det.h are different"
#endif
#endif
/*==================================================================================================
                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/

/*==================================================================================================
                                       LOCAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
                                       LOCAL VARIABLES
==================================================================================================*/
#define ZIPWIRE_START_SEC_VAR_CLEARED_UNSPECIFIED_NO_CACHEABLE
#include "Zipwire_MemMap.h"
/**
* @brief          Global Configuration Pointer.
* @details        Data structure containing the set of configuration parameters required for
*                 initializing the ZIPWIRE Driver Instances.
*/
static const Zipwire_InitType * s_pxZipwireInit;

#if (STD_ON == ZIPWIRE_DET_IS_AVAILABLE)
static volatile Zipwire_StatusType ZipwireStatus = ZIPWIRE_UNINIT;
#endif

#define ZIPWIRE_STOP_SEC_VAR_CLEARED_UNSPECIFIED_NO_CACHEABLE
#include "Zipwire_MemMap.h"
/*==================================================================================================
                                       GLOBAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
                                       GLOBAL VARIABLES
==================================================================================================*/

/*==================================================================================================
                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/

/*==================================================================================================
                                       LOCAL FUNCTIONS
==================================================================================================*/
#define ZIPWIRE_START_SEC_CODE
#include "Zipwire_MemMap.h"

#if (STD_ON == ZIPWIRE_DET_IS_AVAILABLE)
/**
 * @brief      This function reports an development error to the Det module and records the failure in the local structure.
 * @details    This function reports an development error to the Det module and records the failure in the local structure.
 *
 * @param[in]  ServiceId       The service id of the caller function
 * @param[in]  ErrorId         The error id to be reported
 */
static inline void Zipwire_ReportDetError
(
    uint8 ServiceId,
    uint8 ErrorId
)
{
    (void)Det_ReportError((uint16)CDD_ZIPWIRE_MODULE_ID, ZIPWIRE_INSTANCE_ID, ServiceId, ErrorId);
}
#endif /* #if (STD_ON == ZIPWIRE_DET_IS_AVAILABLE) */

#define ZIPWIRE_STOP_SEC_CODE
#include "Zipwire_MemMap.h"
/*==================================================================================================
                                       GLOBAL FUNCTIONS
==================================================================================================*/
#define ZIPWIRE_START_SEC_CODE
#include "Zipwire_MemMap.h"

/**
 * @brief         Initializes the ZIPWIRE Driver settings based on user configuration.
 * @implements    Zipwire_Init_Activity
 */
void Zipwire_Init(const Zipwire_InitType * ConfigPtr)
{
#if (STD_ON == ZIPWIRE_PRECOMPILE_SUPPORT)
    #if (STD_ON == ZIPWIRE_DET_IS_AVAILABLE)
    if (ZIPWIRE_INIT == ZipwireStatus)
    {
        Zipwire_ReportDetError(ZIPWIRE_INIT_ID, ZIPWIRE_E_ALREADY_INITIALIZED);
    }
    if (NULL_PTR != ConfigPtr)
    {
        Zipwire_ReportDetError(ZIPWIRE_INIT_ID, ZIPWIRE_E_INIT_FAILED);
    }
    else
    {
    #else
        (void)ConfigPtr;
    #endif /* #if (STD_ON == ZIPWIRE_DET_IS_AVAILABLE) */
        s_pxZipwireInit = &Zipwire_xConfigInit;
        /* Init driver */
        Zipwire_Ipw_Init(s_pxZipwireInit);
    #if (STD_ON == ZIPWIRE_DET_IS_AVAILABLE)
    ZipwireStatus = ZIPWIRE_INIT;
    }
    #endif /* #if (STD_ON == ZIPWIRE_DET_IS_AVAILABLE) */
#endif /* #if (STD_ON == ZIPWIRE_PRECOMPILE_SUPPORT) */
}


/**
 * @brief         Deinitializes the ZIPWIRE Driver.
 * @implements    Zipwire_DeInit_Activity
 */
void Zipwire_DeInit(const Zipwire_InitType * ConfigPtr)
{
#if (STD_ON == ZIPWIRE_PRECOMPILE_SUPPORT)
    #if (STD_ON == ZIPWIRE_DET_IS_AVAILABLE)
    if (NULL_PTR != ConfigPtr)
    {
        Zipwire_ReportDetError(ZIPWIRE_DEINIT_ID, ZIPWIRE_E_DEINIT_FAILED);
    }
    else
    {
    #else
        (void)ConfigPtr;
    #endif /* #if (STD_ON == ZIPWIRE_DET_IS_AVAILABLE) */
        s_pxZipwireInit = &Zipwire_xConfigInit;
        /* DeInit driver */
        Zipwire_Ipw_DeInit(s_pxZipwireInit);
    #if (STD_ON == ZIPWIRE_DET_IS_AVAILABLE)
    ZipwireStatus = ZIPWIRE_DEINIT;
    }
    #endif /* #if (STD_ON == ZIPWIRE_DET_IS_AVAILABLE) */
#endif /* #if (STD_ON == ZIPWIRE_PRECOMPILE_SUPPORT) */
    
}


/**
 * @brief         Performs multiple read transfers.
 * @implements    Zipwire_Read_Activity
 */
Zipwire_Ip_StatusType Zipwire_Read(uint8 HwInstance, uint8 HwChannel, Zipwire_Ip_TransferDescriptor *DataArray, uint32 DataArrayLength)
{
    Zipwire_Ip_StatusType ReadStatus = ZIPWIRE_IP_STATUS_ERROR;
    #if (STD_ON == ZIPWIRE_DET_IS_AVAILABLE)
    if ((ZIPWIRE_UNINIT == ZipwireStatus) || (ZIPWIRE_DEINIT == ZipwireStatus))
    {
        Zipwire_ReportDetError(ZIPWIRE_READ_ID, ZIPWIRE_E_UNINIT);
    }
    else
    {
    #endif /* #if (STD_ON == ZIPWIRE_DET_IS_AVAILABLE) */
    ReadStatus = Zipwire_Ipw_Read(HwInstance, HwChannel, DataArray, DataArrayLength);
    #if (STD_ON == ZIPWIRE_DET_IS_AVAILABLE)
    }
    #endif  
    return ReadStatus;
}


/**
 * @brief         Performs multiple read transfers synchronously.
 * @implements    Zipwire_ReadBlocking_Activity
 */
Zipwire_Ip_StatusType Zipwire_ReadBlocking(uint8 HwInstance, uint8 HwChannel, Zipwire_Ip_TransferDescriptor *DataArray, uint32 DataArrayLength )
{
    Zipwire_Ip_StatusType ReadBlockingStatus = ZIPWIRE_IP_STATUS_ERROR;
    #if (STD_ON == ZIPWIRE_DET_IS_AVAILABLE)
    if ((ZIPWIRE_UNINIT == ZipwireStatus) || (ZIPWIRE_DEINIT == ZipwireStatus))
    {
        Zipwire_ReportDetError(ZIPWIRE_READBLOCKING_ID, ZIPWIRE_E_UNINIT);
    }
    else
    {
    #endif /* #if (STD_ON == ZIPWIRE_DET_IS_AVAILABLE) */
    ReadBlockingStatus = Zipwire_Ipw_ReadBlocking(HwInstance, HwChannel, DataArray, DataArrayLength);
    #if (STD_ON == ZIPWIRE_DET_IS_AVAILABLE)
    }
    #endif  
    return ReadBlockingStatus;
}

#if (STD_ON == ZIPWIRE_IP_DMA_IS_AVAILABLE)
/**
 * @brief         Performs multiple read transfers with DMA.
 * @implements    Zipwire_ReadDma_Activity
 */
Zipwire_Ip_StatusType Zipwire_ReadDma(uint8 HwInstance, uint8 HwChannel, uint32 *DataArray, const uint32 *AddressArray, uint32 DataArrayLength)
{
    Zipwire_Ip_StatusType ReadDmaStatus = ZIPWIRE_IP_STATUS_ERROR;

    #if (STD_ON == ZIPWIRE_DET_IS_AVAILABLE)
    if ((ZIPWIRE_UNINIT == ZipwireStatus) || (ZIPWIRE_DEINIT == ZipwireStatus))
    {
        Zipwire_ReportDetError(ZIPWIRE_READDMA_ID, ZIPWIRE_E_UNINIT);
    }
    else
    {
    #endif /* #if (STD_ON == ZIPWIRE_DET_IS_AVAILABLE) */
    ReadDmaStatus = Zipwire_Ipw_ReadDma(HwInstance, HwChannel, DataArray, AddressArray, DataArrayLength);
    #if (STD_ON == ZIPWIRE_DET_IS_AVAILABLE)
    }
    #endif  
    return ReadDmaStatus;
}


/**
 * @brief         Performs multiple read transfers synchronously with DMA.
 * @implements    Zipwire_ReadDmaBlocking_Activity
 */
Zipwire_Ip_StatusType Zipwire_ReadDmaBlocking(uint8 HwInstance, uint8 HwChannel, uint32 *DataArray, const uint32 *AddressArray, uint32 DataArrayLength)
{
    Zipwire_Ip_StatusType ReadDmaBlockingStatus = ZIPWIRE_IP_STATUS_ERROR;
    #if (STD_ON == ZIPWIRE_DET_IS_AVAILABLE)
    if ((ZIPWIRE_UNINIT == ZipwireStatus) || (ZIPWIRE_DEINIT == ZipwireStatus))
    {
        Zipwire_ReportDetError(ZIPWIRE_READDMABLOCKING_ID, ZIPWIRE_E_UNINIT);
    }
    else
    {
    #endif /* #if (STD_ON == ZIPWIRE_DET_IS_AVAILABLE) */
    ReadDmaBlockingStatus = Zipwire_Ipw_ReadDmaBlocking(HwInstance, HwChannel, DataArray, AddressArray, DataArrayLength);
    #if (STD_ON == ZIPWIRE_DET_IS_AVAILABLE)
    }
    #endif  
    return ReadDmaBlockingStatus;
}
#endif /* #if (STD_ON == ZIPWIRE_IP_DMA_IS_AVAILABLE) */

/**
 * @brief         Performs multiple write transfers.
 * @implements    Zipwire_Write_Activity
 */
Zipwire_Ip_StatusType Zipwire_Write(uint8 HwInstance, uint8 HwChannel, Zipwire_Ip_TransferDescriptor *DataArray, uint32 DataArrayLength)
{
    Zipwire_Ip_StatusType WriteStatus = ZIPWIRE_IP_STATUS_ERROR;
    #if (STD_ON == ZIPWIRE_DET_IS_AVAILABLE)
    if ((ZIPWIRE_UNINIT == ZipwireStatus) || (ZIPWIRE_DEINIT == ZipwireStatus))
    {
        Zipwire_ReportDetError(ZIPWIRE_WRITE_ID, ZIPWIRE_E_UNINIT);
    }
    else
    {
    #endif /* #if (STD_ON == ZIPWIRE_DET_IS_AVAILABLE) */
    WriteStatus = Zipwire_Ipw_Write(HwInstance, HwChannel, DataArray, DataArrayLength);
    #if (STD_ON == ZIPWIRE_DET_IS_AVAILABLE)
    }
    #endif  
    return WriteStatus;
}


/**
 * @brief         Performs multiple write transfers synchronously.
 * @implements    Zipwire_WriteBlocking_Activity
 */
Zipwire_Ip_StatusType Zipwire_WriteBlocking(uint8 HwInstance, uint8 HwChannel, Zipwire_Ip_TransferDescriptor *DataArray, uint32 DataArrayLength)
{
    Zipwire_Ip_StatusType WriteBlockingStatus = ZIPWIRE_IP_STATUS_ERROR;
    #if (STD_ON == ZIPWIRE_DET_IS_AVAILABLE)
    if ((ZIPWIRE_UNINIT == ZipwireStatus) || (ZIPWIRE_DEINIT == ZipwireStatus))
    {
        Zipwire_ReportDetError(ZIPWIRE_WRITEBLOCKING_ID, ZIPWIRE_E_UNINIT);
    }
    else
    {
    #endif /* #if (STD_ON == ZIPWIRE_DET_IS_AVAILABLE) */
    WriteBlockingStatus = Zipwire_Ipw_WriteBlocking(HwInstance, HwChannel, DataArray, DataArrayLength);
    #if (STD_ON == ZIPWIRE_DET_IS_AVAILABLE)
    }
    #endif  
    return WriteBlockingStatus;
}

#if (STD_ON == ZIPWIRE_IP_DMA_IS_AVAILABLE)
/**
 * @brief         Performs multiple write transfers with DMA.
 * @implements    Zipwire_WriteDma_Activity
 */
Zipwire_Ip_StatusType Zipwire_WriteDma(uint8 HwInstance, uint8 HwChannel, const uint32 *DataArray, const uint32 *AddressArray, uint32 DataArrayLength)
{
    Zipwire_Ip_StatusType WriteDmaStatus = ZIPWIRE_IP_STATUS_ERROR;
    #if (STD_ON == ZIPWIRE_DET_IS_AVAILABLE)
    if ((ZIPWIRE_UNINIT == ZipwireStatus) || (ZIPWIRE_DEINIT == ZipwireStatus))
    {
        Zipwire_ReportDetError(ZIPWIRE_WRITEDMA_ID, ZIPWIRE_E_UNINIT);
    }
    else
    {
    #endif /* #if (STD_ON == ZIPWIRE_DET_IS_AVAILABLE) */
    WriteDmaStatus = Zipwire_Ipw_WriteDma(HwInstance, HwChannel, DataArray, AddressArray, DataArrayLength);
    #if (STD_ON == ZIPWIRE_DET_IS_AVAILABLE)
    }
    #endif  
    return WriteDmaStatus;
}

/**
 * @brief         Performs multiple write transfers synchronously with DMA.
 * @implements    Zipwire_WriteDmaBlocking_Activity
 */
Zipwire_Ip_StatusType Zipwire_WriteDmaBlocking(uint8 HwInstance, uint8 HwChannel, const uint32 *DataArray, const uint32 *AddressArray, uint32 DataArrayLength)
{
    Zipwire_Ip_StatusType WriteDmaBlockingStatus = ZIPWIRE_IP_STATUS_ERROR;
    #if (STD_ON == ZIPWIRE_DET_IS_AVAILABLE)
    if ((ZIPWIRE_UNINIT == ZipwireStatus) || (ZIPWIRE_DEINIT == ZipwireStatus))
    {
        Zipwire_ReportDetError(ZIPWIRE_WRITEDMABLOCKING_ID, ZIPWIRE_E_UNINIT);
    }
    else
    {
    #endif /* #if (STD_ON == ZIPWIRE_DET_IS_AVAILABLE) */
    WriteDmaBlockingStatus = Zipwire_Ipw_WriteDmaBlocking(HwInstance, HwChannel, DataArray, AddressArray, DataArrayLength);
    #if (STD_ON == ZIPWIRE_DET_IS_AVAILABLE)
    }
    #endif  
    return WriteDmaBlockingStatus;
}
#endif /* #if (STD_ON == ZIPWIRE_IP_DMA_IS_AVAILABLE) */


/**
 * @brief         Performs a synchronous stream write.
 * @implements    Zipwire_StreamWrite_Activity
 */
Zipwire_Ip_StatusType Zipwire_StreamWrite(uint8 HwInstance, uint8 HwChannel, uint32 DataAddress, uint32 TargetAcrRegAddress, const uint32 *Data)
{
    Zipwire_Ip_StatusType StreamWriteStatus = ZIPWIRE_IP_STATUS_ERROR;
    #if (STD_ON == ZIPWIRE_DET_IS_AVAILABLE)
    if ((ZIPWIRE_UNINIT == ZipwireStatus) || (ZIPWIRE_DEINIT == ZipwireStatus))
    {
        Zipwire_ReportDetError(ZIPWIRE_STREAMWRITE_ID, ZIPWIRE_E_UNINIT);
    }
    else
    {
    #endif /* #if (STD_ON == ZIPWIRE_DET_IS_AVAILABLE) */
    StreamWriteStatus = Zipwire_Ipw_StreamWrite(HwInstance, HwChannel, DataAddress, TargetAcrRegAddress, Data);
    #if (STD_ON == ZIPWIRE_DET_IS_AVAILABLE)
    }
    #endif  
    return StreamWriteStatus;
}


/**
 * @brief         Performs an ID request transfer.
 * @implements    Zipwire_RequestId_Activity
 */
Zipwire_Ip_StatusType Zipwire_RequestId(uint8 HwInstance, uint8 HwChannel, uint32 *Id)
{
    Zipwire_Ip_StatusType RequestIdStatus = ZIPWIRE_IP_STATUS_ERROR;
    #if (STD_ON == ZIPWIRE_DET_IS_AVAILABLE)
    if ((ZIPWIRE_UNINIT == ZipwireStatus) || (ZIPWIRE_DEINIT == ZipwireStatus))
    {
        Zipwire_ReportDetError(ZIPWIRE_REQUESTID_ID, ZIPWIRE_E_UNINIT);
    }
    else
    {
    #endif /* #if (STD_ON == ZIPWIRE_DET_IS_AVAILABLE) */
    RequestIdStatus = Zipwire_Ipw_RequestId(HwInstance, HwChannel, Id);
    #if (STD_ON == ZIPWIRE_DET_IS_AVAILABLE)
    }
    #endif  
    return RequestIdStatus;
}


/**
 * @brief         Sends a trigger command to the target.
 * @implements    Zipwire_Trigger_Activity
 */
Zipwire_Ip_StatusType Zipwire_Trigger(uint8 HwInstance, uint8 HwChannel)
{
    Zipwire_Ip_StatusType TriggerStatus = ZIPWIRE_IP_STATUS_ERROR;
    #if (STD_ON == ZIPWIRE_DET_IS_AVAILABLE)
    if ((ZIPWIRE_UNINIT == ZipwireStatus) || (ZIPWIRE_DEINIT == ZipwireStatus))
    {
        Zipwire_ReportDetError(ZIPWIRE_TRIGGER_ID, ZIPWIRE_E_UNINIT);
    }
    else
    {
    #endif /* #if (STD_ON == ZIPWIRE_DET_IS_AVAILABLE) */
    TriggerStatus = Zipwire_Ipw_Trigger(HwInstance, HwChannel);
    #if (STD_ON == ZIPWIRE_DET_IS_AVAILABLE)
    }
    #endif  
    return TriggerStatus;
}


/**
 * @brief         Returns the channel status.
 * @implements    Zipwire_GetChannelStatus_Activity
 */
Zipwire_Ip_StatusType Zipwire_GetChannelStatus(uint8 HwInstance, uint8 HwChannel)
{
    Zipwire_Ip_StatusType GetChannelStatus = ZIPWIRE_IP_STATUS_ERROR;
    #if (STD_ON == ZIPWIRE_DET_IS_AVAILABLE)
    if ((ZIPWIRE_UNINIT == ZipwireStatus) || (ZIPWIRE_DEINIT == ZipwireStatus))
    {
        Zipwire_ReportDetError(ZIPWIRE_GETCHANNELSTATUS_ID, ZIPWIRE_E_UNINIT);
    }
    else
    {
    #endif /* #if (STD_ON == ZIPWIRE_DET_IS_AVAILABLE) */
    GetChannelStatus = Zipwire_Ipw_GetChannelStatus(HwInstance, HwChannel);
    #if (STD_ON == ZIPWIRE_DET_IS_AVAILABLE)
    }
    #endif  
    return GetChannelStatus;
}


/**
 * @brief         Installs a global driver callback.
 * @implements    Zipwire_InstallGlobalCallback_Activity
 */
Zipwire_Ip_Callback Zipwire_InstallGlobalCallback(uint8 HwInstance, Zipwire_Ip_Callback CallbackFunction, void * CallbackParam)
{
    Zipwire_Ip_Callback InstallGlobalCallbackStatus;
    #if (STD_ON == ZIPWIRE_DET_IS_AVAILABLE)
    if ((ZIPWIRE_UNINIT == ZipwireStatus) || (ZIPWIRE_DEINIT == ZipwireStatus))
    {
        Zipwire_ReportDetError(ZIPWIRE_INSTALLGLOBALCALLBACK_ID, ZIPWIRE_E_UNINIT);
    }
    else
    {
    #endif /* #if (STD_ON == ZIPWIRE_DET_IS_AVAILABLE) */
    InstallGlobalCallbackStatus = Zipwire_Ipw_InstallGlobalCallback(HwInstance, CallbackFunction, CallbackParam);
    #if (STD_ON == ZIPWIRE_DET_IS_AVAILABLE)
    }
    #endif  
    return InstallGlobalCallbackStatus;
}


/**
 * @brief         Installs a channel callback.
 * @implements    Zipwire_InstallChannelCallback_Activity
 */
Zipwire_Ip_ChannelCallback Zipwire_InstallChannelCallback(uint8 HwInstance, uint8 HwChannel, Zipwire_Ip_ChannelCallback CallbackFunction, void * CallbackParam)
{
    Zipwire_Ip_ChannelCallback InstallChannelCallbackStatus;
    #if (STD_ON == ZIPWIRE_DET_IS_AVAILABLE)
    if ((ZIPWIRE_UNINIT == ZipwireStatus) || (ZIPWIRE_DEINIT == ZipwireStatus))
    {
        Zipwire_ReportDetError(ZIPWIRE_INSTALLCHANNELCALLBACK_ID, ZIPWIRE_E_UNINIT);
    }
    else
    {
    #endif /* #if (STD_ON == ZIPWIRE_DET_IS_AVAILABLE) */
    InstallChannelCallbackStatus = Zipwire_Ipw_InstallChannelCallback(HwInstance, HwChannel, CallbackFunction, CallbackParam);
    #if (STD_ON == ZIPWIRE_DET_IS_AVAILABLE)
    }
    #endif  
    return InstallChannelCallbackStatus;
}


#if (ZIPWIRE_VERSION_INFO_API_ENABLE == STD_ON)
/**
 * @brief         Returns the version information of this module
 * @implements    Zipwire_GetVersionInfo_Activity
 */
void Zipwire_GetVersionInfo(Std_VersionInfoType *pVersionInfo)
{
    pVersionInfo->vendorID         = (uint16)CDD_ZIPWIRE_VENDOR_ID;
    pVersionInfo->moduleID         = (uint16)CDD_ZIPWIRE_MODULE_ID;
    pVersionInfo->sw_major_version = (uint8)CDD_ZIPWIRE_SW_MAJOR_VERSION;
    pVersionInfo->sw_minor_version = (uint8)CDD_ZIPWIRE_SW_MINOR_VERSION;
    pVersionInfo->sw_patch_version = (uint8)CDD_ZIPWIRE_SW_PATCH_VERSION;
}
#endif /* #if (ZIPWIRE_VERSION_INFO_API_ENABLE == STD_ON) */

#define ZIPWIRE_STOP_SEC_CODE
#include "Zipwire_MemMap.h"


#ifdef __cplusplus
}
#endif

/** @} */
