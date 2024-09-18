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
/* Prevention from multiple including the same header */
#ifndef CDD_ZIPWIRE_H
#define CDD_ZIPWIRE_H

/**
*   @file    CDD_Zipwire.h
*
*   @version 3.0.0
*
*   @brief   AUTOSAR Zipwire - Zipwire Ip driver source file.
*   @details
*
*   @addtogroup ZIPWIRE_HLD_DRIVER
*   @{
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
#include "StandardTypes.h"
#include "Zipwire_Types.h"
#include "Zipwire_Cfg.h"
#include "Zipwire_Ipw.h"

/*=================================================================================================
*                              SOURCE FILE VERSION INFORMATION
=================================================================================================*/
/**
* @brief Parameters that shall be published within the Zipwire driver header file and also in the
*        module's description file
*/
#define CDD_ZIPWIRE_MODULE_ID                      255
#define CDD_ZIPWIRE_VENDOR_ID                      43
#define CDD_ZIPWIRE_AR_RELEASE_MAJOR_VERSION       4
#define CDD_ZIPWIRE_AR_RELEASE_MINOR_VERSION       7
#define CDD_ZIPWIRE_AR_RELEASE_REVISION_VERSION    0
#define CDD_ZIPWIRE_SW_MAJOR_VERSION               3
#define CDD_ZIPWIRE_SW_MINOR_VERSION               0
#define CDD_ZIPWIRE_SW_PATCH_VERSION               0

/*=================================================================================================
*                                     FILE VERSION CHECKS
=================================================================================================*/
/* Check if the files CDD_Zipwire.h and Zipwire_Types.h are of the same vendor */
#if (CDD_ZIPWIRE_VENDOR_ID != ZIPWIRE_TYPES_VENDOR_ID)
    #error "CDD_Zipwire.h and Zipwire_Types.h have different vendor ids"
#endif
/* Check if the files CDD_Zipwire.h and Zipwire_Types.h are of the same Autosar version */
#if ((CDD_ZIPWIRE_AR_RELEASE_MAJOR_VERSION    != ZIPWIRE_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (CDD_ZIPWIRE_AR_RELEASE_MINOR_VERSION    != ZIPWIRE_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (CDD_ZIPWIRE_AR_RELEASE_REVISION_VERSION != ZIPWIRE_TYPES_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of CDD_Zipwire.h and Zipwire_Types.h are different"
#endif
/* Check if the files CDD_Zipwire.h and Zipwire_Types.h are of the same software version */
#if ((CDD_ZIPWIRE_SW_MAJOR_VERSION != ZIPWIRE_TYPES_SW_MAJOR_VERSION) || \
     (CDD_ZIPWIRE_SW_MINOR_VERSION != ZIPWIRE_TYPES_SW_MINOR_VERSION) || \
     (CDD_ZIPWIRE_SW_PATCH_VERSION != ZIPWIRE_TYPES_SW_PATCH_VERSION)    \
    )
    #error "Software Version Numbers of CDD_Zipwire.h and Zipwire_Types.h are different"
#endif

/* Check if the files CDD_Zipwire.h and Zipwire_Cfg.h are of the same vendor */
#if (CDD_ZIPWIRE_VENDOR_ID != ZIPWIRE_CFG_VENDOR_ID)
    #error "CDD_Zipwire.h and Zipwire_Cfg.h have different vendor ids"
#endif
/* Check if the files CDD_Zipwire.h and Zipwire_Cfg.h are of the same Autosar version */
#if ((CDD_ZIPWIRE_AR_RELEASE_MAJOR_VERSION    != ZIPWIRE_CFG_AR_RELEASE_MAJOR_VERSION) || \
     (CDD_ZIPWIRE_AR_RELEASE_MINOR_VERSION    != ZIPWIRE_CFG_AR_RELEASE_MINOR_VERSION) || \
     (CDD_ZIPWIRE_AR_RELEASE_REVISION_VERSION != ZIPWIRE_CFG_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of CDD_Zipwire.h and Zipwire_Cfg.h are different"
#endif
/* Check if the files CDD_Zipwire.h and Zipwire_Cfg.h are of the same software version */
#if ((CDD_ZIPWIRE_SW_MAJOR_VERSION != ZIPWIRE_CFG_SW_MAJOR_VERSION) || \
     (CDD_ZIPWIRE_SW_MINOR_VERSION != ZIPWIRE_CFG_SW_MINOR_VERSION) || \
     (CDD_ZIPWIRE_SW_PATCH_VERSION != ZIPWIRE_CFG_SW_PATCH_VERSION)    \
    )
    #error "Software Version Numbers of CDD_Zipwire.h and Zipwire_Cfg.h are different"
#endif

/* Check if source file and ZIPWIRE_Ipw.h file are of the same vendor */
#if (CDD_ZIPWIRE_VENDOR_ID != ZIPWIRE_IPW_VENDOR_ID)
    #error "CDD_Zipwire.h and ZIPWIRE_Ipw.h have different vendor ids"
#endif

/* Check if the source file and ZIPWIRE_Ipw.h file are of the same Autosar version */
#if ((CDD_ZIPWIRE_AR_RELEASE_MAJOR_VERSION    != ZIPWIRE_IPW_AR_RELEASE_MAJOR_VERSION) || \
     (CDD_ZIPWIRE_AR_RELEASE_MINOR_VERSION    != ZIPWIRE_IPW_AR_RELEASE_MINOR_VERSION) || \
     (CDD_ZIPWIRE_AR_RELEASE_REVISION_VERSION != ZIPWIRE_IPW_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of CDD_Zipwire.h and ZIPWIRE_Ipw.h are different"
#endif

/* Check if source file and Zipwire header file are of the same Software version */
#if ((CDD_ZIPWIRE_SW_MAJOR_VERSION != ZIPWIRE_IPW_SW_MAJOR_VERSION) || \
     (CDD_ZIPWIRE_SW_MINOR_VERSION != ZIPWIRE_IPW_SW_MINOR_VERSION) || \
     (CDD_ZIPWIRE_SW_PATCH_VERSION != ZIPWIRE_IPW_SW_PATCH_VERSION)    \
    )
    #error "Software Version Numbers of CDD_Zipwire.h and ZIPWIRE_Ipw.h are different"
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if the files CDD_Zipwire.h and StandardTypes.h are of the same version */
    #if ((CDD_ZIPWIRE_AR_RELEASE_MAJOR_VERSION != STD_AR_RELEASE_MAJOR_VERSION) || \
        (CDD_ZIPWIRE_AR_RELEASE_MINOR_VERSION  != STD_AR_RELEASE_MINOR_VERSION)    \
        )
        #error "AutoSar Version Numbers of CDD_ZIPWIRE.h and StandardTypes.h are different"
    #endif
#endif

/*==================================================================================================
*                                            CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/

/**
* @brief    ID of ZIPWIRE Instance
* @details  Parameters used when raising an error/exception
*/
#define ZIPWIRE_INSTANCE_ID                               (0U)


/*-------------------------------------------------------------------------------------------------
 * THE SERVICE ID OF THE CALLER STANDARD FUNCTION
 * ---------------------------------------------------------------rc-------------------------------*/

/*-------------------------------------------------------------------------------------------------
 * THE SERVICE ID OF THE CALLER CDD FUNCTION
 * ----------------------------------------------------------------------------------------------*/
/**
* @brief    API service ID for Zipwire_Init function
* @details  Parameters used when raising an error/exception
*/
#define ZIPWIRE_INIT_ID                                       (2U)

/**
* @brief    API service ID for Zipwire_DeInit function
* @details  Parameters used when raising an error/exception
*/
#define ZIPWIRE_DEINIT_ID                                     (3U)

/**
* @brief    API service ID for Zipwire_Read function
* @details  Parameters used when raising an error/exception
*/
#define ZIPWIRE_READ_ID                                       (4U)

/**
* @brief    API service ID for Zipwire_ReadBlocking function
* @details  Parameters used when raising an error/exception
*/
#define ZIPWIRE_READBLOCKING_ID                               (5U)

/**
* @brief    API service ID for Zipwire_ReadDma function
* @details  Parameters used when raising an error/exception
*/
#define ZIPWIRE_READDMA_ID                                    (6U)

/**
* @brief    API service ID for Zipwire_ReadDmaBlocking function
* @details  Parameters used when raising an error/exception
*/
#define ZIPWIRE_READDMABLOCKING_ID                            (7U)

/**
* @brief    API service ID for Zipwire_Write function
* @details  Parameters used when raising an error/exception
*/
#define ZIPWIRE_WRITE_ID                                      (8U)

/**
* @brief    API service ID for Zipwire_WriteBlocking function
* @details  Parameters used when raising an error/exception
*/
#define ZIPWIRE_WRITEBLOCKING_ID                              (9U)

/**
* @brief    API service ID for Zipwire_WriteDma function
* @details  Parameters used when raising an error/exception
*/
#define ZIPWIRE_WRITEDMA_ID                                   (10U)

/**
* @brief    API service ID for Zipwire_WriteDmaBlocking function
* @details  Parameters used when raising an error/exception
*/
#define ZIPWIRE_WRITEDMABLOCKING_ID                           (11U)

/**
* @brief    API service ID for Zipwire_StreamWrite function
* @details  Parameters used when raising an error/exception
*/
#define ZIPWIRE_STREAMWRITE_ID                                (12U)

/**
* @brief    API service ID for Zipwire_RequestId function
* @details  Parameters used when raising an error/exception
*/
#define ZIPWIRE_REQUESTID_ID                                  (13U)

/**
* @brief    API service ID for Zipwire_Triger function
* @details  Parameters used when raising an error/exception
*/
#define ZIPWIRE_TRIGGER_ID                                    (14U)

/**
* @brief    API service ID for Zipwire_GetChannelStatus function
* @details  Parameters used when raising an error/exception
*/
#define ZIPWIRE_GETCHANNELSTATUS_ID                           (15U)

/**
* @brief    API service ID for Zipwire_InstallGlobalCallback function
* @details  Parameters used when raising an error/exception
*/
#define ZIPWIRE_INSTALLGLOBALCALLBACK_ID                      (16U)

/**
* @brief    API service ID for Zipwire_InstallChannelCallback function
* @details  Parameters used when raising an error/exception
*/
#define ZIPWIRE_INSTALLCHANNELCALLBACK_ID                     (17U)
/*-------------------------------------------------------------------------------------------------
 * THE ERROR ID TO BE REPORTED
 * -----------------------------------------------------------------------------------------------*/
/**
* @brief        The ZIPWIRE module is not properly initialized
* @details      Parameter is used when raising a Det error
* @implements   Zipwire_ErrorIds_define
* */
#define ZIPWIRE_E_INIT_FAILED                             (18U)

/**
* @brief        The ZIPWIRE module is not properly deinitialized
* @details      Parameter is used when raising a Det error
* @implements   Zipwire_ErrorIds_define
* */
#define ZIPWIRE_E_DEINIT_FAILED                           (19U)

/**
* @brief        The ZIPWIRE module is already initialized
* @details      Parameter is used when raising a Det error
* @implements   Zipwire_ErrorIds_define
* */
#define ZIPWIRE_E_ALREADY_INITIALIZED                     (20U)

/**
* @brief        The ZIPWIRE module is was never initialized
* @details      Parameter is used when raising a Det error
* @implements   Zipwire_ErrorIds_define
* */
#define ZIPWIRE_E_UNINIT                                  (21U)
/*==================================================================================================
*                                              ENUMS
==================================================================================================*/

/*==================================================================================================
*                                  STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
*                                  GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                       FUNCTION PROTOTYPES
==================================================================================================*/

#define ZIPWIRE_START_SEC_CODE
#include "Zipwire_MemMap.h"



/**
 * @brief   This service will store the Zipwire driver installation configuration based on user configuration.
 * @details This service is a non-reentrant function that shall store user configuration.
 *          The initialization is applied for the enabled IPs, configured statically.
 *
 * @param[in] ConfigPtr  - Pointer to the Zipwire specific configuration structure that contains static configuration.
 *
 * @return void
 *
 * @api
 *
 **/
void Zipwire_Init(const Zipwire_InitType * ConfigPtr);


/**
 * @brief   This service will store the Zipwire driver installation configuration based on user configuration.
 * @details This service is a non-reentrant function that shall store user configuration.
 *          The initialization is applied for the enabled IPs, configured statically.
 *
 * @param[in] ConfigPtr  - Pointer to the Zipwire specific configuration structure that contains static configuration.
 *
 * @return void
 *
 * @api
 *
 **/
void Zipwire_DeInit(const Zipwire_InitType * ConfigPtr);



/*!
 * @brief Performs multiple read transfers.
 *
 * @details This function performs multiple reads from the addresses supplied by the user within the array
 *          parameter. It returns once the first transfer is launched. If a callback is installed, the user will be
 *          notified when the last read transfer is done; otherwise, transfer status can be checked by
 *          calling 'Zipwire_Ip_GetChannelStatus'.
 *
 * @param[in] HwInstance - Instance number
 * @param[in] HwChannel  - Channel number
 * @param[in] DataArray  - Array of transfer descriptors (address, size, data)
 * @param[in] DataArrayLength - Length of the data array
 * @return    An error code or ZIPWIRE_IP_STATUS_SUCCESS
 * @api
 *
 **/
Zipwire_Ip_StatusType Zipwire_Read(uint8 HwInstance,
                  uint8 HwChannel,
                  Zipwire_Ip_TransferDescriptor *DataArray,
                  uint32 DataArrayLength);

/*!
 * @brief Performs multiple read transfers synchronously.
 *
 * This function performs multiple reads from the addresses supplied by the user within the array
 * parameter. It does not return until all the read requests are served or an error occurs.
 * Read data is stored in the array elements.
 *
 * @param[in] HwInstance - Instance number
 * @param[in] HwChannel - Channel number
 * @param[in] DataArray - Array of transfer descriptors (address, size, data)
 * @param[in] DataArrayLength - Length of the data array
 * @return    An error - code or ZIPWIRE_STATUS_SUCCESS
 * @api
 *
 **/
Zipwire_Ip_StatusType Zipwire_ReadBlocking(uint8 HwInstance,
                            uint8 HwChannel,
                            Zipwire_Ip_TransferDescriptor *DataArray,
                            uint32 DataArrayLength);

#if (STD_ON == ZIPWIRE_IP_DMA_IS_AVAILABLE)
/*!
 * @brief Performs multiple read transfers with DMA.
 *
 * @details This function performs multiple reads from the addresses supplied by the user within the array
 *          parameter. It returns once the first transfer is launched. If a callback is installed, the user will be
 *          notified when the last read transfer is done; otherwise, transfer status can be checked by
 *          calling 'Zipwire_Ip_GetChannelStatus'.
 *
 * @param[in] HwInstance - Instance number
 * @param[in] HwChannel  - Channel number
 * @param[in] DataArray - Array of transfer descriptors (address, size, data)
 * @param[in] AddressArray - Array containing target addresses where data will be read from
 * @param[in] DataArrayLength - Length of the data & address buffers
 * @return    An error code or ZIPWIRE_IP_STATUS_SUCCESS
 * @api
 *
 **/
Zipwire_Ip_StatusType Zipwire_ReadDma(uint8 HwInstance,
                    uint8 HwChannel,
                    uint32 *DataArray,
                    const uint32 *AddressArray,
                    uint32 DataArrayLength);


/*!
 * @brief Performs multiple read transfers.
 *
 * @details This function performs multiple reads from the addresses supplied by the user within the array
 *          parameter. It returns once the first transfer is launched. If a callback is installed, the user will be
 *          notified when the last read transfer is done; otherwise, transfer status can be checked by
 *          calling 'Zipwire_Ip_GetChannelStatus'.
 *
 * @param[in] HwInstance - Instance number
 * @param[in] HwChannel  - Channel number
 * @param[in] DataArray - Array of transfer descriptors (address, size, data)
 * @param[in] AddressArray - Array containing target addresses where data will be read from
 * @param[in] DataArrayLength - Length of the data & address buffers
 * @return    An error code or ZIPWIRE_IP_STATUS_SUCCESS
 * @api
 *
 **/
Zipwire_Ip_StatusType Zipwire_ReadDmaBlocking(uint8 HwInstance,
                            uint8 HwChannel,
                            uint32 *DataArray,
                            const uint32 *AddressArray,
                            uint32 DataArrayLength);
#endif /* #if (STD_ON == ZIPWIRE_IP_DMA_IS_AVAILABLE) */

/*!
 * @brief Performs multiple write transfers.
 *
 * This function performs multiple write operations at the addresses supplied by the user within the array
 * parameter. It returns once the first transfer is launched. If a callback is installed, the user will be
 * notified when the last write transfer is done; otherwise, transfer status can be checked with by
 * calling 'Zipwire_Ip_GetChannelStatus'.
 *
 * @param[in] HwInstance - Instance number
 * @param[in] HwChannel - Channel number
 * @param[in] DataArray - Array of transfer descriptors (address, size, data)
 * @param[in] DataArrayLength - Length of the data array
 * @return    An error - code or ZIPWIRE_IP_STATUS_SUCCESS
 * @api
 *
 **/
Zipwire_Ip_StatusType Zipwire_Write(uint8 HwInstance,
                    uint8 HwChannel,
                    Zipwire_Ip_TransferDescriptor *DataArray,
                    uint32 DataArrayLength);

/*!
 * @brief Performs multiple write transfers synchronously.
 *
 * This function performs multiple write operations at the addresses supplied by the user within the array
 * parameter. It  does not return until the last write operation is completed or an error occurred.
 *
 * @param[in] HwInstance - Instance number
 * @param[in] HwChannel - Channel number
 * @param[in] DataArray - Array of transfer descriptors (address, size, data)
 * @param[in] DataArrayLength - Length of the data array
 * @return    An error - code or ZIPWIRE_IP_STATUS_SUCCESS
 * @api
 *
 **/
Zipwire_Ip_StatusType Zipwire_WriteBlocking(uint8 HwInstance,
                            uint8 HwChannel,
                            Zipwire_Ip_TransferDescriptor *DataArray,
                            uint32 DataArrayLength);


#if (STD_ON == ZIPWIRE_IP_DMA_IS_AVAILABLE)
/*!
 * @brief Performs multiple write transfers using DMA.
 *
 * This function performs multiple write transfers from the address supplied by the user, using
 * DMA requests. The DMA engine automatically copies data from the data buffer.
 * The function does not return until all the write requests are served or an error occurs.
 * @Note: Only 32-bits transfers are supported in DMA mode.
 *
 * @param[in] HwInstance - Instance number
 * @param[in] HwChannel - Channel number
 * @param[in] DataArray - Array of transfer descriptors (address, size, data)
 * @param[in] AddressArray - Array containing target addresses where data will be read from
 * @param[in] DataArrayLength - Length of the data & address buffers
 * @return    An error - code or ZIPWIRE_IP_STATUS_SUCCESS
 * @api
 *
 **/
Zipwire_Ip_StatusType Zipwire_WriteDma(uint8 HwInstance,
                    uint8 HwChannel,
                    const uint32 *DataArray,
                    const uint32 *AddressArray,
                    uint32 DataArrayLength);


/*!
 * @brief Performs multiple write transfers using DMA, synchronously.
 *
 * This function performs multiple write operations at the addresses supplied by the user within the array
 * parameter. It returns once the first transfer is launched. If a callback is installed, the user will be
 * notified when the last write transfer is done; otherwise, transfer status can be checked with by
 * calling 'Zipwire_Ip_GetChannelStatus'.
 *
 * @param[in] HwInstance - Instance number
 * @param[in] HwChannel - Channel number
 * @param[in] DataArray - Array of transfer descriptors (address, size, data)
 * @param[in] AddressArray - Array containing target addresses where data will be read from
 * @param[in] DataArrayLength - Length of the data & address buffers
 * @return    An error - code or ZIPWIRE_IP_STATUS_SUCCESS
 * @api
 *
 **/
Zipwire_Ip_StatusType Zipwire_WriteDmaBlocking(uint8 HwInstance,
                            uint8 HwChannel,
                            const uint32 *DataArray,
                            const uint32 *AddressArray,
                            uint32 DataArrayLength);
#endif /* #if (STD_ON == ZIPWIRE_IP_DMA_IS_AVAILABLE) */


/*!
 * @brief Performs a synchronous stream write.
 *
 * This function performs a streaming write operation. It does not return until
 * all the bytes are transferred.
 *
 * @param[in] HwInstance - Instance number
 * @param[in] HwChannel - The HwChannel number
 * @param[in] DataAddress - Target address where the data will be written
 * @param[in] TargetAcrRegAddress - Address of the SIPI_ACR register on the target node
 * @param[in] Data - Array of data bytes to be streamed; it should point to an array of
 *                   minimum 8 bytes (SIPI stream transfer size). It is application responsibility
 *                   to correctly allocate memory before passing this reference, driver is
 *                   unaware of memory allocation at application level.
 * @return    An error code or ZIPWIRE_IP_STATUS_SUCCESS
 */
Zipwire_Ip_StatusType Zipwire_StreamWrite(uint8 HwInstance,
                                 uint8 HwChannel,
                                 uint32 DataAddress,
                                 uint32 TargetAcrRegAddress,
                                 const uint32 *Data);


/*!
 * @brief Performs an ID request transfer.
 *
 * This requests the device ID from the target node. The target ID will be saved in
 * the output parameter provided by application.
 *
 * @param[in]  HwInstance - Instance number
 * @param[in]  HwChannel - The channel number
 * @param[in]  Id - Reference to user variable where the target ID is stored
 * @return     An error code or ZIPWIRE_IP_STATUS_SUCCESS
 */
Zipwire_Ip_StatusType Zipwire_RequestId(uint8 HwInstance, uint8 HwChannel, uint32 *Id);


/*!
 * @brief Sends a trigger command to the target.
 *
 * This function sends a trigger transfer command to the target.
 *
 * @param[in]  HwInstance - Instance number
 * @param[in]  HwChannel - The channel number
 * @return     An error code or ZIPWIRE_IP_STATUS_SUCCESS
 */
Zipwire_Ip_StatusType Zipwire_Trigger(uint8 HwInstance, uint8 HwChannel);


/*!
 * @brief Returns the channel status.
 *
 * This function returns the status of the last transfer executed by the channel.
 *
 * @param[in] HwInstance - Instance number
 * @param[in] HwChannel - The channel number
 * @return The current channel status, or the status of the latest command;
 *         ZIPWIRE_IP_STATUS_BUSY is returned if a non-blocking command is in progress;
 *         ZIPWIRE_IP_STATUS_SUCCESS is returned if the last command completed successfully;
 *         If an error occurred in the last command, an appropriate error code is
 *         returned; please check the zipwire error codes descriptions.
 */
Zipwire_Ip_StatusType Zipwire_GetChannelStatus(uint8 HwInstance, uint8 HwChannel);


/*!
 * @brief Installs a global driver callback.
 *
 * This function installs a driver callback that will treat 'max count reached' and 'global CRC error' events.
 *
 * @param[in] HwInstance - Instance number
 * @param[in] CallbackFunction - The new callback
 * @param[in] CallbackParam - The new callback parameter
 * @return Reference to the current callback.
 */
Zipwire_Ip_Callback Zipwire_InstallGlobalCallback(uint8 HwInstance,
                                                     Zipwire_Ip_Callback CallbackFunction,
                                                     void * CallbackParam);


/*!
 * @brief Installs a channel callback.
 *
 * This function installs a callback for a zipwire channel. It will be called on successful
 * read/write, or in case of errors in the transfer.
 *
 * @param[in] HwInstance - Instance number
 * @param[in] HwChannel - The channel number
 * @param[in] CallbackFunction - The new callback
 * @param[in] CallbackParam - The new callback parameter
 * @return Reference to the current channel callback.
 */
Zipwire_Ip_ChannelCallback Zipwire_InstallChannelCallback(uint8 HwInstance,
                                                          uint8 HwChannel,
                                                          Zipwire_Ip_ChannelCallback CallbackFunction,
                                                          void * CallbackParam);


#if (STD_ON == ZIPWIRE_VERSION_INFO_API_ENABLE)
/**
 * @brief   Software module version query.
 * @details Returns the version information of this module
 *
 * @param[in]  pVersionInfo    - Pointer to get Version Information
 *
 * @return void
 *
 * @api
 *
 **/
void Zipwire_GetVersionInfo(Std_VersionInfoType *pVersionInfo);
#endif /* ZIPWIRE_VERSION_INFO_API_ENABLE == STD_ON */

#define ZIPWIRE_STOP_SEC_CODE
#include "Zipwire_MemMap.h"



#ifdef __cplusplus
}
#endif

/** @} */

#endif /* CDD_ZIPWIRE_H */
