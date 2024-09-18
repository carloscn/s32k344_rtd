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
#ifndef ZIPWIRE_IP_TYPES_H
#define ZIPWIRE_IP_TYPES_H

/**
*   @file    Zipwire_Ip_Types.h
*
*   @version 3.0.0
*
*   @brief   AUTOSAR Zipwire - Zipwire Ip driver header file.
*   @details
*
*   @addtogroup ZIPWIRE_IP_DRIVER
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
#include "Mcal.h"
#include "Zipwire_Ip_CfgDefines.h"

/*==================================================================================================
*                                 SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/*
 * @brief Parameters that shall be published within the driver header file and also in the
 *        module's description file
 */
#define ZIPWIRE_IP_TYPES_VENDOR_ID                     43
#define ZIPWIRE_IP_TYPES_AR_RELEASE_MAJOR_VERSION      4
#define ZIPWIRE_IP_TYPES_AR_RELEASE_MINOR_VERSION      7
#define ZIPWIRE_IP_TYPES_AR_RELEASE_REVISION_VERSION   0
#define ZIPWIRE_IP_TYPES_SW_MAJOR_VERSION              3
#define ZIPWIRE_IP_TYPES_SW_MINOR_VERSION              0
#define ZIPWIRE_IP_TYPES_SW_PATCH_VERSION              0

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
/* Check if Zipwire_Ip_Types.h file and Mcal.h header file are of the same Autosar version */
#if ((ZIPWIRE_IP_TYPES_AR_RELEASE_MAJOR_VERSION != MCAL_AR_RELEASE_MAJOR_VERSION) || \
     (ZIPWIRE_IP_TYPES_AR_RELEASE_MINOR_VERSION != MCAL_AR_RELEASE_MINOR_VERSION))
    #error "AutoSar Version Numbers of Zipwire_Ip_Types.h and Mcal.h are different"
#endif
#endif


/* Check if the files Zipwire_Ip_Types.h and Zipwire_Ip_CfgDefines.h are of the same version */
#if (ZIPWIRE_IP_TYPES_VENDOR_ID != ZIPWIRE_IP_CFG_DEFINES_VENDOR_ID)
    #error "Zipwire_Ip_Types.h and Zipwire_Ip_CfgDefines.h have different vendor ids"
#endif

/* Check if Zipwire_Ip_Types.h and Zipwire_Ip_CfgDefines.h are of the same Autosar version */
#if ((ZIPWIRE_IP_TYPES_AR_RELEASE_MAJOR_VERSION    != ZIPWIRE_IP_CFG_DEFINES_AR_RELEASE_MAJOR_VERSION) || \
     (ZIPWIRE_IP_TYPES_AR_RELEASE_MINOR_VERSION    != ZIPWIRE_IP_CFG_DEFINES_AR_RELEASE_MINOR_VERSION) || \
     (ZIPWIRE_IP_TYPES_AR_RELEASE_REVISION_VERSION != ZIPWIRE_IP_CFG_DEFINES_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Zipwire_Ip_Types.h and Zipwire_Ip_CfgDefines.h are different"
#endif

/* Check if Zipwire_Ip_Types.h and Zipwire_Ip_CfgDefines.h are of the same Software version */
#if ((ZIPWIRE_IP_TYPES_SW_MAJOR_VERSION != ZIPWIRE_IP_CFG_DEFINES_SW_MAJOR_VERSION) || \
     (ZIPWIRE_IP_TYPES_SW_MINOR_VERSION != ZIPWIRE_IP_CFG_DEFINES_SW_MINOR_VERSION) || \
     (ZIPWIRE_IP_TYPES_SW_PATCH_VERSION != ZIPWIRE_IP_CFG_DEFINES_SW_PATCH_VERSION)    \
    )
    #error "Software Version Numbers of Zipwire_Ip_Types.h and Zipwire_Ip_CfgDefines.h are different"
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
/* Zipwire events */
/**
 * @brief This type contains the Zipwire Ip Events Type.
 * @details The Event State type provides information about the Zipwire general state.
 *
 * */
typedef enum
{
    ZIPWIRE_EVENT_GLOBAL_CRC_ERR      = 0x00U,    /*!< Global ZIPWIRE error */
    ZIPWIRE_EVENT_MAX_COUNT_REACHED   = 0x01U,    /*!< Address maximum count reached */
    ZIPWIRE_EVENT_TIMEOUT_ERR         = 0x02U,    /*!< Channel timeout */
    ZIPWIRE_EVENT_TRANSACTION_ID_ERR  = 0x03U,    /*!< Transaction ID error */
    ZIPWIRE_EVENT_ACK_ERR             = 0x04U,    /*!< Error on received ACK */
    ZIPWIRE_EVENT_WRITE_COMPLETE      = 0x05U,    /*!< ACK received correctly */
    ZIPWIRE_EVENT_READ_COMPLETE       = 0x06U,    /*!< Read answer received */
    ZIPWIRE_EVENT_TARGET_ID_RECEIVED  = 0x07U,    /*!< ID request served; received target ID */
    ZIPWIRE_EVENT_TRIGGER_COMMAND     = 0x08U,    /*!< Trigger command received */
    ZIPWIRE_EVENT_DMA_ERR             = 0x09U     /*!< DMA error */
} Zipwire_Ip_Events;


/**
 * @brief   This type contains the Zipwire Ip LFAST driver states
 * @details The role is identified by the following structure.
 *          Internal driver enumeration.
 * */
typedef enum
{
    /* ZIPWIRE specific error codes */
    ZIPWIRE_IP_STATUS_SUCCESS                     = 0x00U,
    ZIPWIRE_IP_STATUS_TIMEOUT                     = 0x01U,
    ZIPWIRE_IP_STATUS_BUSY                        = 0x02U,
    ZIPWIRE_IP_STATUS_ERROR                       = 0x03U,
    ZIPWIRE_IP_STATUS_ZIPWIRE_ACK_ERR             = 0x04U,
    ZIPWIRE_IP_STATUS_ZIPWIRE_TRANSACTION_ID_ERR  = 0x05U,
    ZIPWIRE_IP_STATUS_ZIPWIRE_TIMEOUT_ERR         = 0x06U,
} Zipwire_Ip_StatusType;

/**
 * @brief   This type contains the Zipwire Ip LFAST Role(MASTER/SLAVE).
 * @details The role is identified by the following structure.
 *          Internal driver enumeration.
 * */
typedef enum {
    LFAST_SLAVE = 0U,
    LFAST_MASTER = 1U
} Zipwire_Ip_LfastRole;


/**
 * @brief   This type contains the Zipwire Ip LFAST Speed Mode(LOW/HIGH).
 * @details The speed mode is identified by the following structure.
 *          Internal driver enumeration.
 * */
typedef enum {
    LFAST_LOW_SPEED = 0U,
    LFAST_HIGH_SPEED = 1U
} Zipwire_Ip_LfastSpeedMode;


/**
 * @brief   This type contains the Zipwire Ip LFAST clock division in low speed.
 * @details The clock division in low speed is identified by the following structure.
 *          Internal driver enumeration.
 * */
typedef enum {
    LFAST_LOW_SPEED_CLK_DIV_2 = 0U,
    LFAST_LOW_SPEED_CLK_DIV_4 = 1U
} Zipwire_Ip_LfastLowSpeedClk;


/**
 * @brief   This type contains the Zipwire Ip address offset.
 * @details The address offset is identified by the following structure.
 *          Internal driver enumeration.
 * */
typedef enum
{
    ZIPWIRE_ADDR_NO_CHANGE = 0U,                 /*!< No change. Address stays the same after the transfer is done */
    ZIPWIRE_ADDR_INC_4     = 1U,                 /*!< Increment address by 4 */
    ZIPWIRE_ADDR_DEC_4     = 2U                  /*!< Decrement address by 4 */
} Zipwire_Ip_AddressOffset;


/**
 * @brief   This type contains the Zipwire Ip address offset.
 * @details The transfer size is identified by the following structure.
 *          Internal driver enumeration.
 * */
typedef enum
{
    ZIPWIRE_8_BITS  = 0U,                        /*!< 8-bit transfer */
    ZIPWIRE_16_BITS = 1U,                        /*!< 16-bit transfer */
    ZIPWIRE_32_BITS = 2U                         /*!< 32-bit transfer */
} Zipwire_Ip_TransferSize;


/**
 * @brief   This type contains the Zipwire Ip timeout counter prescaler.
 * @details The timeout counter prescaler is identified by the following structure.
 *          Internal driver enumeration.
 * */
typedef enum
{
    ZIPWIRE_DIV_64   = 0x040U,                   /*!< Timeout counter clock = system clock/64 */
    ZIPWIRE_DIV_128  = 0x080U,                   /*!< Timeout counter clock = system clock/128 */
    ZIPWIRE_DIV_256  = 0x100U,                   /*!< Timeout counter clock = system clock/256 */
    ZIPWIRE_DIV_512  = 0x200U,                   /*!< Timeout counter clock = system clock/512 */
    ZIPWIRE_DIV_1024 = 0x400U                    /*!< Timeout counter clock = system clock/1024 */
} Zipwire_Ip_TimeoutPrescaler;


/*==================================================================================================
*                                  STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/
/**
 * @brief This type contains the global callback for the zipwire driver .
 * @details The Callback is defined by the user and installed by the driver in the corresponding IRQ.
 *
 * @return void
 *
 *
 * */
typedef void (*Zipwire_Ip_Callback)(uint8 HwInstance, Zipwire_Ip_Events Event, void *UserData);


/**
 * @brief This type contains the channel callback for zipwire driver.
 * @details The Callback is defined by the user and installed by the driver in the corresponding IRQ.
 *
 * @return void
 *
 *
 * */
typedef void (*Zipwire_Ip_ChannelCallback)(uint8 HwInstance, uint8 HwChannel, Zipwire_Ip_Events Event, void *UserData);



/**
 * @brief   This type contains the Zipwire Ip SIPI Channel Registers.
 * @details The Channel is identified by the following structure:
 *          Configure registers for each SIPI Channel.
 * */
typedef struct {
  volatile uint32 CCR;                              /**< SIPI Channel Control Register */
  volatile uint32 CSR;                              /**< SIPI Channel Status Register */
  uint8 RESERVED_0[4];
  volatile uint32 CIR;                              /**< SIPI Channel Interrupt Register */
  volatile uint32 CTOR;                             /**< SIPI Channel Timeout Register */
  volatile const uint32 CCRC;                       /**< SIPI Channel ZIPWIRE Register */
  volatile uint32 CAR;                              /**< SIPI Channel Address Register */
  volatile uint32 CDR;                              /**< SIPI Channel Data Register */
} Zipwire_Ip_SIPI_Channel_Type;


/**
 * @brief   This type contains the Zipwire Ip SIPI Stream Channel Registers.
 * @details The Channel is identified by the following structure
 *          Configure registers for each SIPI Stream Channel.
 * */
typedef struct {
  volatile uint32 CCR;                              /**< SIPI Channel Control Register */
  volatile uint32 CSR;                              /**< SIPI Channel Status Register */
  uint8 RESERVED_0[4];
  volatile uint32 CIR;                              /**< SIPI Channel Interrupt Register */
  volatile uint32 CTOR;                             /**< SIPI Channel Timeout Register */
  volatile const uint32 CCRC;                       /**< SIPI Channel ZIPWIRE Register */
  volatile uint32 CAR;                              /**< SIPI Channel Address Register */
  volatile uint32 CDR[SIPI_CDR2_COUNT];             /**< SIPI Channel Data Register */
} Zipwire_Ip_SIPI_Stream_Channel_Type;


/**
 * @brief   This type contains the Zipwire Ip LFAST configuration.
 * @details The LFAST configuration is identified by the following structure.
 * */
typedef struct
{
    Zipwire_Ip_LfastRole             Role;                   /*!< LFAST role: MASTER/SLAVE */
    Zipwire_Ip_LfastSpeedMode        SpeedMode;              /*!< LFAST speed mode: high-speed/low-speed */
    uint32                           SyncTimeout;            /*!< Timeout used for the LFAST master-slave synchronization;
                                                             @Note: A value of zero for this parameter is equivalent to timeout
                                                             being disregarded by the driver; the LFAST initialization
                                                             will wait forever for commands/responses from the other node. */
    uint32                           SyncAttempts;           /*!< Number of attempts for the master to synchronize with the slave;
                                                             this field is only used by the master node.
                                                             @Note: A value of zero for this parameter is equivalent to an infinite
                                                             number of attempts; the LFAST master will try forever to synchronize
                                                             with the slave */
    Zipwire_Ip_LfastLowSpeedClk      LowSpeedClkDiv;         /*!< LFAST clock division factor in Low Speed Select mode. */
} Zipwire_Ip_LfastChannelConfigType;


/**
 * @brief   This type contains the Zipwire transfer descriptor.
 * @details The zipwire transfer descriptor is identified by the following structure.
 * */
typedef struct
{
    uint32 Address;
    uint32 Data;
    Zipwire_Ip_TransferSize TransferSize;
} Zipwire_Ip_TransferDescriptor;


/**
 * @brief   This type contains the Zipwire user configuration.
 * @details The zipwire instance user configuration is identified by the following structure.
 * */
typedef struct
{
    uint8 HwInstance;                                   /*!< SIPI instance number */
    Zipwire_Ip_LfastChannelConfigType *LfastConfig;     /*!< LFAST configuration */
    Zipwire_Ip_AddressOffset AddrOffset;                /*!< Address increment/decrement for stream transfers */
    Zipwire_Ip_TimeoutPrescaler TimeoutClkDiv;          /*!< SIPI timeout clock prescaler */
    boolean MaxCountReachedInt;                            /*!< Maximum address reached interrupt enable */
    Zipwire_Ip_Callback Callback;                        /*!< Global callback (max count reached/global ZIPWIRE error) */
    void * CallbackParam;                               /*!< Global callback parameter */
} Zipwire_Ip_LogicInstanceConfigType;


/**
 * @brief   This type contains the Zipwire user configuration.
 * @details The zipwire channel user configuration is identified by the following structure.
 * */
typedef struct
{
    uint8 HwChannel;                                    /*!< SIPI channel number (0-3) */
    uint8 HwInstance;                                   /*!< SIPI instance number */
    uint8 Timeout;                                      /*!< Timeout value for requests. */
#if (STD_ON == ZIPWIRE_IP_DMA_IS_AVAILABLE)    
    boolean DmaEnable;                                  /*!< Enable channel DMA functionality */
    uint8 DmaDataChn;                                   /*!< DMA channel number used to transfer data */
    uint8 DmaAddrChn;                                   /*!< DMA channel number used to transfer addresses */
#endif
    boolean TimeoutErrIrq;                              /*!< Enables/disables timeout error handling for the channel */
    boolean AckErrIrq;                                  /*!< Enables/disables ACK error handling for the channel */
    boolean TransIdErrIrq;                              /*!< Enables/disables transaction ID error handling for the channel */
    Zipwire_Ip_ChannelCallback Callback;                /*!< Channel error callback */
    void * CallbackParam;                               /*!< Channel error callback parameter */
} Zipwire_Ip_LogicChannelConfigType;


/**
 * @brief   This type contains the Zipwire Ip Initialization.
 * @details The Zipwire Ip Initialization contains all the information required to initialize the ZIPWIRE Instances
 *          Internal driver structure.
 * */
typedef struct
{
    const Zipwire_Ip_LogicInstanceConfigType *const *LogicInstanceConfigList; /**< Pointer to list LogicInstanceConfig */

} Zipwire_Ip_InstancesInitType;


/**
 * @brief   This type contains the Zipwire Ip Initialization.
 * @details The Zipwire Ip Initialization contains all the information required to initialize the ZIPWIRE Channels
 *          Internal driver structure.
 * */
typedef struct
{
    const Zipwire_Ip_LogicChannelConfigType  *const *LogicChannelConfigList;  /**< Pointer to list LogicChannelConfig */

} Zipwire_Ip_ChannelsInitType;


/**
 * @brief   This type contains the Zipwire Ip Initialization.
 * @details The Zipwire Ip Initialization contains all the information required to initialize the ZIPWIRE Channels
 *          Internal driver structure.
 * */
typedef struct
{
    const Zipwire_Ip_InstancesInitType *ZipwireIpInstanceCfg;  /**< Pointer to list LogicChannelConfig */
    const Zipwire_Ip_ChannelsInitType *ZipwireIpChannelCfg; /**< Pointer to list LogicInstanceConfig */

} Zipwire_Ip_ConfigType;

/**
 * @brief   This type contains the Zipwire configuration for global callback function.
 * @details The zipwire global instance state is identified by the following structure.
 * */
typedef struct
{
    Zipwire_Ip_Callback Callback;  /*!< Global callback (max count reached/global ZIPWIRE error) */
    void * CallbackParam;          /*!< Global callback parameter */
} Zipwire_Ip_InstanceState;


/**
 * @brief   This type contains the Zipwire channel state structure.
 * @details The zipwire channel state structure is identified by the following structure.
 * */
typedef struct
{
    uint8 HwInstance;                               /*!< SIPI instance number */
    uint8 HwChannel;                                /*!< SIPI channel number */
    Zipwire_Ip_ChannelCallback Callback;            /*!< Channel callback */
    void * CallbackParam;                           /*!< Channel callback parameter */
    volatile Zipwire_Ip_StatusType ChannelStatus;   /*!< Channel status */
    volatile boolean IsBlocking;                    /*!< Flag used for channel blocking operation */
    Zipwire_Ip_TransferDescriptor *TransferBuffer;  /*!< Internal array holding the buffer for continuous transfers */
    volatile uint32 RemainingTransfers;             /*!< Number of continuous transfers still to be served */
    boolean DmaEnable;                              /*!< Enable DMA functionality for this channel */

#if (STD_ON == ZIPWIRE_IP_DMA_IS_AVAILABLE)
    boolean DmaWriteTransfer;                       /*!< Flag used to differentiate between read and write DMA transfers */
    uint8 DmaDataChn;                               /*!< DMA channel number used to transfer data */
    uint8 DmaAddrChn;                               /*!< DMA channel number used to transfer addresses */
#endif
    volatile boolean IdRequest;                        /*!< Flag used to mark ID request transfers */
    boolean DisableNotification;                       /*!< Flag used when the application must not be notified of an event */
    uint32 * TargetId;                              /*!< Internal variable storing the requested target ID */
} Zipwire_Ip_ChannelState;
/*=================================================================================================-
*                                GLOBAL VARIABLE DECLARATIONS
============================================================-=====================================*/

/*===================================================================================-==============
*                                    FUNCTION PROTOTYPES
========================================================================================-=========*/

#ifdef __cplusplus
}
#endif

/** @} */

#endif /* #ifndef ZIPWIRE_IP_TYPES_H */
