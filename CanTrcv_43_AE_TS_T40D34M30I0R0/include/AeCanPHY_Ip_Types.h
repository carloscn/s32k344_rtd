/*==================================================================================================
*   Project              : RTD AUTOSAR 4.7
*   Platform             : CORTEXM
*   Peripheral           : AE
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
/*==================================================================================================
==================================================================================================*/
#ifndef AE_CANPHY_IP_TYPES_H
#define AE_CANPHY_IP_TYPES_H

/*==================================================================================================
                                         INCLUDE FILES
 1) system and project includes
 2) needed interfaces from external units
 3) internal and external interfaces from this unit
==================================================================================================*/
#include "StandardTypes.h"
/*==================================================================================================
                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/


/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/


/*==================================================================================================
                                           CONSTANTS
==================================================================================================*/

/*==================================================================================================
                                       DEFINES AND MACROS
==================================================================================================*/

/*==================================================================================================
                                             ENUMS
==================================================================================================*/
typedef enum
{
    /** @brief Offline mode. Wake-Up Pattern detection is enabled. */
    AE_CANPHY_OFFLINE_MODE          = 0U,
    /** @brief Normal mode. The full transceiver functionality is available. */
    AE_CANPHY_NORMAL_MODE               = 1U,
    /** @brief Listen only mode. The CAN transmitter is turned off. */
    AE_CANPHY_LISTEN_ONLY_MODE        = 3U
} AeCanPHY_Ip_TransceiverModeType;

typedef enum
{
    /** @brief Listen only mode. The CAN transmitter is turned off. */
    AE_CANPHY_WKUP_EVENT                = 0U,
    /** @brief Offline mode. Wake-Up Pattern detection is enabled. */
    AE_CANPHY_INVALID_STATE_EVENT       = 1U,
    /** @brief Normal mode. The full transceiver functionality is available. */
    AE_CANPHY_TXDOM_TIMEDOUT_EVENT      = 2U
} AeCanPHY_Ip_TransceiverEventType;

typedef enum
{
    /** @brief No error. */
    AE_CANPHY_STATUS_SUCCESS            = 0U,
    /** @brief General error, command failed to execute task successfully. */
    AE_CANPHY_STATUS_FAILED,
    /** @brief SPI communication error. */
    AE_CANPHY_STATUS_ERR_SPI,
} AeCanPHY_Ip_StatusType;
/*==================================================================================================
                                 STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/
typedef struct
{
    /** @brief The Spi communication retries. */
    uint8 SpiCommRetries;
} AeCanPHY_Ip_SpiConfigType;

typedef struct
{
    /** @brief The Spi configuration using for accessing to the Transceiver. */
    AeCanPHY_Ip_SpiConfigType SpiConfig;
    /** @brief The mode of transceiver enterred after Initialization. */
    AeCanPHY_Ip_TransceiverModeType DeviceModeAfterInit;
} AeCanPHY_Ip_ConfigType;
/*==================================================================================================
                                 GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
                                     FUNCTION PROTOTYPES
==================================================================================================*/

#endif /* AE_CANPHY_IP_TYPES_H */
