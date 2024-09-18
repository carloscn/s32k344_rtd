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
#ifndef ZIPWIRE_IP_H
#define ZIPWIRE_IP_H

/**
*   @file    Zipwire_Ip.h
*
*   @version 3.0.0
*
*   @brief   AUTOSAR Zipwire - Zipwire Ip driver source file.
*   @details
*
*   @defgroup ZIPWIRE_IP_DRIVER ZIPWIRE IPL Driver
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
#include "Zipwire_Ip_Cfg.h"
#include "OsIf.h"
/*==================================================================================================
*                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/*
* @brief Parameters that shall be published within the driver header file and also in the
* module's description file
*/
#define ZIPWIRE_IP_VENDOR_ID                     43
#define ZIPWIRE_IP_AR_RELEASE_MAJOR_VERSION      4
#define ZIPWIRE_IP_AR_RELEASE_MINOR_VERSION      7
#define ZIPWIRE_IP_AR_RELEASE_REVISION_VERSION   0
#define ZIPWIRE_IP_SW_MAJOR_VERSION              3
#define ZIPWIRE_IP_SW_MINOR_VERSION              0
#define ZIPWIRE_IP_SW_PATCH_VERSION              0

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/
/* Check if the files Zipwire_Ip.h and Zipwire_Ip_Cfg.h are of the same version */
#if (ZIPWIRE_IP_VENDOR_ID != ZIPWIRE_IP_CFG_VENDOR_ID)
    #error "Zipwire_Ip.h and Zipwire_Ip_Cfg.h have different vendor ids"
#endif

/* Check if Zipwire_Ip.h and Zipwire_Ip_Cfg.h are of the same Autosar version */
#if ((ZIPWIRE_IP_AR_RELEASE_MAJOR_VERSION    != ZIPWIRE_IP_CFG_AR_RELEASE_MAJOR_VERSION) || \
     (ZIPWIRE_IP_AR_RELEASE_MINOR_VERSION    != ZIPWIRE_IP_CFG_AR_RELEASE_MINOR_VERSION) || \
     (ZIPWIRE_IP_AR_RELEASE_REVISION_VERSION != ZIPWIRE_IP_CFG_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Zipwire_Ip.h and Zipwire_Ip_Cfg.h are different"
#endif

/* Check if Zipwire_Ip.h and Zipwire_Ip_Cfg.h are of the same Software version */
#if ((ZIPWIRE_IP_SW_MAJOR_VERSION != ZIPWIRE_IP_CFG_SW_MAJOR_VERSION) || \
     (ZIPWIRE_IP_SW_MINOR_VERSION != ZIPWIRE_IP_CFG_SW_MINOR_VERSION) || \
     (ZIPWIRE_IP_SW_PATCH_VERSION != ZIPWIRE_IP_CFG_SW_PATCH_VERSION)    \
    )
    #error "Software Version Numbers of Zipwire_Ip.h and Zipwire_Ip_Cfg.h are different"
#endif

/* Check if this header file and OsIf.h file are of the same Autosar version */
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if ((ZIPWIRE_IP_AR_RELEASE_MAJOR_VERSION != OSIF_AR_RELEASE_MAJOR_VERSION) || \
        (ZIPWIRE_IP_AR_RELEASE_MINOR_VERSION != OSIF_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of Zipwire_Ip.h and OsIf.h are different"
    #endif
#endif


/*==================================================================================================
*                                            CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/

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
 * @brief   This function initializes the Zipwire Driver in IP Layer.
 * @details This service is a non-reentrant function that shall initialize the Zipwire driver.
 *          The user must make sure that the clock is enabled.
 *
 * @param[in] pxZipwireConfig     - Pointer to the configuration structure.
 *
 * @return void
 *
 * @api
 *
 **/
void Zipwire_Ip_Init(const Zipwire_Ip_ConfigType *const pxZipwireConfig);

/**
 * @brief   This function initializes the Zipwire Driver in IP Layer.
 * @details This service is a non-reentrant function that shall initialize the Zipwire driver.
 *          The user must make sure that the clock is enabled.
 *
 * @param[in] pxZipwireConfig     - Pointer to the configuration structure.
 *
 * @return void
 *
 * @api
 *
 **/
void Zipwire_Ip_DeInit(const Zipwire_Ip_ConfigType *const pxZipwireConfig);

/*!
 * @brief Initializes the driver.
 *
 * @details This function initializes the appropriate SIPI and LFAST interfaces, according to the
 *          configuration passed by the user.
 * @param[in] pxZipwireInstanceConfig - Specifies the Logic Instance Configuration defined by the user
 * @return    An error code or ZIPWIRE_IP_STATUS_SUCCESS
 */
Zipwire_Ip_StatusType Zipwire_Ip_InitInstance(const Zipwire_Ip_LogicInstanceConfigType *pxZipwireInstanceConfig);


/*!
 * @brief De-initializes the ZIPWIRE driver.
 *
 * @details This function shuts down the communication interfaces and brings the driver state machine
 *          back to the uninitialized state.
 *
 * @param[in] pxZipwireInstanceConfig - Specifies the Logic Instance Configuration defined by the user
 * @param[in] pxZipwireChannelInit - Specifies the Logic Channel Configuration defined by the user
 * @return    An error code or ZIPWIRE_IP_STATUS_SUCCESS
 */
Zipwire_Ip_StatusType Zipwire_Ip_DeInitInstance(uint8 HwInstance);


/*!
 * @brief Initializes a ZIPWIRE HwChannel.
 *
 * @details This function initializes a HwChannel with the settings provided by the user.
 *
 * @param[in] pxZipwireChannelConfig - Specifies the Logic Channel Config defined by the user
 * @return    An error code or ZIPWIRE_IP_STATUS_SUCCESS
 */
Zipwire_Ip_StatusType Zipwire_Ip_InitChannel(const Zipwire_Ip_LogicChannelConfigType *pxZipwireChannelConfig);


/*!
 * @brief De-initializes a ZIPWIRE HwChannel.
 *
 * @details This function de-initializes a HwChannel.
 *
 * @param[in] pxZipwireChannelConfig - Specifies the Logic Channel Config defined by the user
 * @return    An error code or ZIPWIRE_IP_STATUS_SUCCESS
 */
Zipwire_Ip_StatusType Zipwire_Ip_DeInitChannel(uint8 HwInstance, uint8 HwChannel);


/*!
 * @brief Performs multiple read transfers.
 *
 * @details This function performs multiple reads from the addresses supplied by the user within the array
 *          parameter. It returns once the first transfer is launched. If a callback is installed, the user will be
 *          notified when the last read transfer is done; otherwise, transfer status can be checked by
 *          calling 'Zipwire_Ip_GetChannelStatus'.
 *
 * @param[in]     HwInstance - Instance number
 * @param[in]     HwChannel  - The HwChannel number
 * @param[in/out] DataArray  - Array of transfer descriptors (address, size, data)
 * @param[in]     DataArrayLength - Length of the data array
 * @return        An error code or ZIPWIRE_IP_STATUS_SUCCESS
 */
Zipwire_Ip_StatusType Zipwire_Ip_Read(uint8 HwInstance,
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
 * @param[in]     HwInstance - Instance number
 * @param[in]     HwChannel - The HwChannel number
 * @param[in/out] DataArray - Array of transfer descriptors (address, size, data)
 * @param[in]     DataArrayLength - Length of the data array
 * @return        An error code or ZIPWIRE_IP_STATUS_SUCCESS
 */
Zipwire_Ip_StatusType Zipwire_Ip_ReadBlocking(uint8 HwInstance,
                                            uint8 HwChannel,
                                            Zipwire_Ip_TransferDescriptor *DataArray,
                                            uint32 DataArrayLength);

#if (STD_ON == ZIPWIRE_IP_DMA_IS_AVAILABLE)
/*!
 * @brief Performs multiple read transfers using DMA.
 *
 * This function performs multiple read transfers from the address supplied by the user, using
 * DMA requests. The DMA engine automatically copies data in the data buffer.
 * The function returns once the first transfer is launched. If a callback is installed, the user will be
 * notified when the last read transfer is done; otherwise, transfer status can be checked by
 * calling 'ZIPWIRE_DRV_GetChannelStatus'.
 * @Note: Only 32-bits transfers are supported in DMA mode.
 *
 * @param[in] HwInstance - Instance number
 * @param[in] HwChannel - The HwChannel number
 * @param[in] DataArray - Array of transfer descriptors (address, size, data)
 * @param[in] AddressArray - Array containing target addresses where data will be read from
 * @param[in] DataArrayLength - Length of the data & address buffers
 * @return    An error code or ZIPWIRE_IP_STATUS_SUCCESS
 */
Zipwire_Ip_StatusType Zipwire_Ip_ReadDma(uint8 HwInstance,
                             uint8 HwChannel,
                             uint32 *DataArray,
                             const uint32 *AddressArray,
                             uint32 DataArrayLength);


/*!
 * @brief Performs multiple read transfers using DMA, synchronously.
 *
 * This function performs multiple read transfers from the address supplied by the user, using
 * DMA requests. The DMA engine automatically copies data in the data buffer.
 * The function does not return until all the read requests are served or an error occurs.
 * @Note: Only 32-bits transfers are supported in DMA mode.
 *  
 * @param[in] HwInstance - Instance number
 * @param[in] HwChannel - The HwChannel number
 * @param[in] DataArray - Array of transfer descriptors (address, size, data)
 * @param[in] AddressArray - Array containing target addresses where data will be read from
 * @param[in] DataArrayLength - Length of the data & address buffers
 * @return    An error code or ZIPWIRE_IP_STATUS_SUCCESS
 */
Zipwire_Ip_StatusType Zipwire_Ip_ReadDmaBlocking(uint8 HwInstance,
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
 * calling 'ZIPWIRE_DRV_GetChannelStatus'.
 *
 * @param[in] HwInstance - Instance number
 * @param[in] HwChannel - The HwChannel number
 * @param[in] DataArray - Array of transfer descriptors (address, size, data)
 * @param[in] DataArrayLength - Length of the data array
 * @return    An error code or ZIPWIRE_IP_STATUS_SUCCESS
 */
Zipwire_Ip_StatusType Zipwire_Ip_Write(uint8 HwInstance,
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
 * @param[in] HwChannel - The HwChannel number
 * @param[in] DataArray - Array of transfer descriptors (address, size, data)
 * @param[in] DataArrayLength - Length of the data array
 * @return    An error code or ZIPWIRE_IP_STATUS_SUCCESS
 */
Zipwire_Ip_StatusType Zipwire_Ip_WriteBlocking(uint8 HwInstance,
                                               uint8 HwChannel,
                                               Zipwire_Ip_TransferDescriptor *DataArray,
                                               uint32 DataArrayLength);


#if (STD_ON == ZIPWIRE_IP_DMA_IS_AVAILABLE)
/*!
 * @brief Performs multiple write transfers using DMA.
 *
 * This function performs multiple write transfers to the address supplied by the user, using
 * DMA requests. The DMA engine automatically copies data from the data buffer.
 * The function returns once the first transfer is launched. If a callback is installed, the user will be
 * notified when the last read transfer is done; otherwise, transfer status can be checked by
 * calling 'ZIPWIRE_DRV_GetChannelStatus'.
 * @Note: Only 32-bits transfers are supported in DMA mode.
 * 
 * @param[in] HwInstance - Instance number
 * @param[in] HwChannel - The HwChannel number
 * @param[in] DataArray - Data Buffer
 * @param[in] AddressArray - Array containing target addresses where data will be written
 * @param[in] DataArrayLength - Length of the data & address buffers
 * @return    An error code or ZIPWIRE_IP_STATUS_SUCCESS
 */
Zipwire_Ip_StatusType Zipwire_Ip_WriteDma(uint8 HwInstance,
                              uint8 HwChannel,
                              const uint32 *DataArray,
                              const uint32 *AddressArray,
                              uint32 DataArrayLength);


/*!
 * @brief Performs multiple write transfers using DMA, synchronously.
 *
 * This function performs multiple write transfers from the address supplied by the user, using
 * DMA requests. The DMA engine automatically copies data from the data buffer.
 * The function does not return until all the write requests are served or an error occurs.
 * @Note: Only 32-bits transfers are supported in DMA mode.
 * 
 * @param[in] HwInstance - Instance number
 * @param[in] HwChannel - The HwChannel number
 * @param[in] DataArray - Data Buffer
 * @param[in] AddressArray - Array containing target addresses where data will be written
 * @param[in] DataArrayLength - Length of the data & address buffers
 * @return    An error code or ZIPWIRE_IP_STATUS_SUCCESS
 */
Zipwire_Ip_StatusType Zipwire_Ip_WriteDmaBlocking(uint8 HwInstance,
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
Zipwire_Ip_StatusType Zipwire_Ip_StreamWrite(uint8 HwInstance,
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
Zipwire_Ip_StatusType Zipwire_Ip_RequestId(uint8 HwInstance, uint8 HwChannel, uint32 *Id);


/*!
 * @brief Sends a trigger command to the target.
 *
 * This function sends a trigger transfer command to the target.
 *
 * @param[in]  HwInstance - Instance number
 * @param[in]  HwChannel - The channel number
 * @return     An error code or ZIPWIRE_IP_STATUS_SUCCESS
 */
Zipwire_Ip_StatusType Zipwire_Ip_Trigger(uint8 HwInstance, uint8 HwChannel);


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
Zipwire_Ip_StatusType Zipwire_Ip_GetChannelStatus(uint8 HwInstance, uint8 HwChannel);


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
Zipwire_Ip_Callback Zipwire_Ip_InstallGlobalCallback(uint8 HwInstance,
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
Zipwire_Ip_ChannelCallback Zipwire_Ip_InstallChannelCallback(uint8 HwInstance,
                                                          uint8 HwChannel,
                                                          Zipwire_Ip_ChannelCallback CallbackFunction,
                                                          void * CallbackParam);
#define ZIPWIRE_STOP_SEC_CODE
#include "Zipwire_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */

#endif /* #ifndef ZIPWIRE_IP_H */
