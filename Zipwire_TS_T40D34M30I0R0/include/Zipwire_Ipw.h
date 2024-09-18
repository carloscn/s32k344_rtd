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
#ifndef ZIPWIRE_IPW_H
#define ZIPWIRE_IPW_H

/**
*   @file    Zipwire_Ipw.h
*
*   @version 3.0.0
*
*   @brief   AUTOSAR Zipwire - Zipwire Ipw driver source file.
*   @details
*
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
#include "Zipwire_Ip.h"

/*==================================================================================================
*                                 SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @brief Parameters that shall be published within the Zipwire driver header file and also in the
*        module's description file.
*
*/
#define ZIPWIRE_IPW_VENDOR_ID                    43
#define ZIPWIRE_IPW_AR_RELEASE_MAJOR_VERSION     4
#define ZIPWIRE_IPW_AR_RELEASE_MINOR_VERSION     7
#define ZIPWIRE_IPW_AR_RELEASE_REVISION_VERSION  0
#define ZIPWIRE_IPW_SW_MAJOR_VERSION             3
#define ZIPWIRE_IPW_SW_MINOR_VERSION             0
#define ZIPWIRE_IPW_SW_PATCH_VERSION             0

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/
/* Check if the files Zipwire_Ipw.h and Zipwire_Ip.h are of the same version */
#if (ZIPWIRE_IPW_VENDOR_ID != ZIPWIRE_IP_VENDOR_ID)
    #error "Zipwire_Ipw.h and Zipwire_Ip.h have different vendor ids"
#endif

/* Check if Zipwire_Ipw.h and Zipwire_Ip.h are of the same Autosar version */
#if ((ZIPWIRE_IPW_AR_RELEASE_MAJOR_VERSION    != ZIPWIRE_IP_AR_RELEASE_MAJOR_VERSION) || \
     (ZIPWIRE_IPW_AR_RELEASE_MINOR_VERSION    != ZIPWIRE_IP_AR_RELEASE_MINOR_VERSION) || \
     (ZIPWIRE_IPW_AR_RELEASE_REVISION_VERSION != ZIPWIRE_IP_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Zipwire_Ipw.h and Zipwire_Ip.h are different"
#endif

/* Check if Zipwire_Ipw.h and Zipwire_Ip.h are of the same Software version */
#if ((ZIPWIRE_IPW_SW_MAJOR_VERSION != ZIPWIRE_IP_SW_MAJOR_VERSION) || \
     (ZIPWIRE_IPW_SW_MINOR_VERSION != ZIPWIRE_IP_SW_MINOR_VERSION) || \
     (ZIPWIRE_IPW_SW_PATCH_VERSION != ZIPWIRE_IP_SW_PATCH_VERSION)    \
    )
    #error "Software Version Numbers of Zipwire_Ipw.h and Zipwire_Ip.h are different"
#endif
/*==================================================================================================
*                                            CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                        DEFINES AND MACROS
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
 * @brief   This function initializes the ZIPWIRE Driver in IPW Layer.
 * @details This service is a non-reentrant function that shall initialize the Zipwire driver.
 *          The user must make sure that the clock is enabled.
 *
 * @param[in] pxZipwireIpInstanceConfigInit     - Pointer to the Zipwire specific configuration structure that contains static configuration of the Intances.
 * @param[in] pxZipwireIpChannelConfigInit      - Pointer to the Zipwire specific configuration structure that contains static configuration of the Channels.
 *
 * @return void
 *
 * @api
 *
 **/
#define Zipwire_Ipw_Init(pxZipwireConfig) Zipwire_Ip_Init(pxZipwireConfig)
/**
 * @brief   This function initializes the ZIPWIRE Driver in IPW Layer.
 * @details This service is a non-reentrant function that shall initialize the Zipwire driver.
 *          The user must make sure that the clock is enabled.
 *
 * @param[in] pxZipwireIpInstanceConfigInit     - Pointer to the Zipwire specific configuration structure that contains static configuration of the Intances.
 *
 * @return void
 *
 * @api
 *
 **/
#define Zipwire_Ipw_DeInit(pxZipwireConfig) Zipwire_Ip_DeInit(pxZipwireConfig)

/**
 * @brief   This function shall start algorithm calculate Zipwire in IPW layer.
 * @details This service is a reentrant function that shall start the Channel to calculate the Zipwire using the configured algorithm.
 *
 * @param[in]     HwInstance - Instance number
 * @param[in]     HwChannel  - The HwChannel number
 * @param[in/out] DataArray  - Array of transfer descriptors (address, size, data)
 * @param[in]     DataArrayLength - Length of the data array
 * @return        An error code or ZIPWIRE_IP_STATUS_SUCCESS
 *
 * @api
 *
 **/
#define Zipwire_Ipw_Read(HwInstance, HwChannel, DataArray, DataArrayLength) Zipwire_Ip_Read(HwInstance, HwChannel, DataArray, DataArrayLength)


/**
 * @brief   This function get result Zipwire after finish calculated in IPW Layer.
 * @details This service is a function that shall get result Zipwire Channel parameters list
 *
 * @param[in]     HwInstance - Instance number
 * @param[in]     HwChannel  - The HwChannel number
 * @param[in/out] DataArray  - Array of transfer descriptors (address, size, data)
 * @param[in]     DataArrayLength - Length of the data array
 * @return        An error code or ZIPWIRE_IP_STATUS_SUCCESS
 *
 * @api
 *
 **/
#define Zipwire_Ipw_ReadBlocking(HwInstance, HwChannel, DataArray, DataArrayLength) Zipwire_Ip_ReadBlocking(HwInstance, HwChannel, DataArray, DataArrayLength)

#if (STD_ON == ZIPWIRE_IP_DMA_IS_AVAILABLE)
/**
 * @brief   This function shall start algorithm calculate Zipwire in IPW layer.
 * @details This service is a reentrant function that shall start the Channel to calculate the Zipwire using the configured algorithm.
 *
 * @param[in]     HwInstance - Instance number
 * @param[in]     HwChannel  - The HwChannel number
 * @param[in/out] DataArray  - Array of transfer descriptors (address, size, data)
 * @param[in]     DataArrayLength - Length of the data array
 * @return        An error code or ZIPWIRE_IP_STATUS_SUCCESS
 *
 * @api
 *
 **/
#define Zipwire_Ipw_ReadDma(HwInstance, HwChannel, DataArray, AddressArray, DataArrayLength) Zipwire_Ip_ReadDma(HwInstance, HwChannel, DataArray, AddressArray, DataArrayLength)


/**
 * @brief   This function shall start algorithm calculate Zipwire in IPW layer.
 * @details This service is a reentrant function that shall start the Channel to calculate the Zipwire using the configured algorithm.
 *
 * @param[in]     HwInstance - Instance number
 * @param[in]     HwChannel  - The HwChannel number
 * @param[in/out] DataArray  - Array of transfer descriptors (address, size, data)
 * @param[in]     DataArrayLength - Length of the data array
 * @return        An error code or ZIPWIRE_IP_STATUS_SUCCESS
 *
 * @api
 *
 **/
#define Zipwire_Ipw_ReadDmaBlocking(HwInstance, HwChannel, DataArray, AddressArray, DataArrayLength) Zipwire_Ip_ReadDmaBlocking(HwInstance, HwChannel, DataArray, AddressArray, DataArrayLength)
#endif

/**
 * @brief   This function get result Zipwire after finish calculated in IPW Layer.
 * @details This service is a function that shall get result Zipwire Channel parameters list
 *
 * @param[in]     HwInstance - Instance number
 * @param[in]     HwChannel  - The HwChannel number
 * @param[in/out] DataArray  - Array of transfer descriptors (address, size, data)
 * @param[in]     DataArrayLength - Length of the data array
 * @return        An error code or ZIPWIRE_IP_STATUS_SUCCESS
 *
 * @api
 *
 **/
#define Zipwire_Ipw_Write(HwInstance, HwChannel, DataArray, DataArrayLength) Zipwire_Ip_Write(HwInstance, HwChannel, DataArray, DataArrayLength)


/**
 * @brief   This function get result Zipwire after finish calculated in IPW Layer.
 * @details This service is a function that shall get result Zipwire Channel parameters list
 *
 * @param[in]     HwInstance - Instance number
 * @param[in]     HwChannel  - The HwChannel number
 * @param[in/out] DataArray  - Array of transfer descriptors (address, size, data)
 * @param[in]     DataArrayLength - Length of the data array
 * @return        An error code or ZIPWIRE_IP_STATUS_SUCCESS
 *
 * @api
 *
 **/
#define Zipwire_Ipw_WriteBlocking(HwInstance, HwChannel, DataArray, DataArrayLength) Zipwire_Ip_WriteBlocking(HwInstance, HwChannel, DataArray, DataArrayLength)

#if (STD_ON == ZIPWIRE_IP_DMA_IS_AVAILABLE)
/**
 * @brief   This function get result Zipwire after finish calculated in IPW Layer.
 * @details This service is a function that shall get result Zipwire Channel parameters list
 *
 * @param[in]     HwInstance - Instance number
 * @param[in]     HwChannel  - The HwChannel number
 * @param[in/out] DataArray  - Array of transfer descriptors (address, size, data)
 * @param[in]     DataArrayLength - Length of the data array
 * @return        An error code or ZIPWIRE_IP_STATUS_SUCCESS
 *
 * @api
 *
 **/
#define Zipwire_Ipw_WriteDma(HwInstance, HwChannel, DataArray, AddressArray, DataArrayLength) Zipwire_Ip_WriteDma(HwInstance, HwChannel, DataArray, AddressArray, DataArrayLength)


/**
 * @brief   This function get result Zipwire after finish calculated in IPW Layer.
 * @details This service is a function that shall get result Zipwire Channel parameters list
 *
 * @param[in]     HwInstance - Instance number
 * @param[in]     HwChannel  - The HwChannel number
 * @param[in/out] DataArray  - Array of transfer descriptors (address, size, data)
 * @param[in]     DataArrayLength - Length of the data array
 * @return        An error code or ZIPWIRE_IP_STATUS_SUCCESS
 *
 * @api
 *
 **/
#define Zipwire_Ipw_WriteDmaBlocking(HwInstance, HwChannel, DataArray, AddressArray, DataArrayLength) Zipwire_Ip_WriteDmaBlocking(HwInstance, HwChannel, DataArray, AddressArray, DataArrayLength)

#endif

/*!
 * @brief   Performs a synchronous stream write.
 * @details This function performs a streaming write operation. It does not return until all the bytes are transferred.
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
#define Zipwire_Ipw_StreamWrite(HwInstance, HwChannel, DataAddress, TargetAcrRegAddress, Data) Zipwire_Ip_StreamWrite(HwInstance, HwChannel, DataAddress, TargetAcrRegAddress, Data);


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
#define Zipwire_Ipw_RequestId(HwInstance, HwChannel, Id) Zipwire_Ip_RequestId(HwInstance, HwChannel, Id)


/*!
 * @brief Sends a trigger command to the target.
 *
 * This function sends a trigger transfer command to the target.
 *
 * @param[in]  HwInstance - Instance number
 * @param[in]  HwChannel - The channel number
 * @return     An error code or ZIPWIRE_IP_STATUS_SUCCESS
 */
#define Zipwire_Ipw_Trigger(HwInstance, HwChannel) Zipwire_Ip_Trigger(HwInstance, HwChannel)

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
#define Zipwire_Ipw_GetChannelStatus(HwInstance, HwChannel) Zipwire_Ip_GetChannelStatus(HwInstance, HwChannel)


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
#define Zipwire_Ipw_InstallGlobalCallback(HwInstance, CallbackFunction, CallbackParam) Zipwire_Ip_InstallGlobalCallback(HwInstance, CallbackFunction, CallbackParam)


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
#define Zipwire_Ipw_InstallChannelCallback(HwInstance, HwChannel, CallbackFunction, CallbackParam) Zipwire_Ip_InstallChannelCallback(HwInstance, HwChannel, CallbackFunction, CallbackParam)

#define ZIPWIRE_STOP_SEC_CODE
#include "Zipwire_MemMap.h"



#ifdef __cplusplus
}
#endif

/** @} */

#endif /* ZIPWIRE_IPW_H */
