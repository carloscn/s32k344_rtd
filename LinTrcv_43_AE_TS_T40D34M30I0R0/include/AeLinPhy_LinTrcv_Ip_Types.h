/*==================================================================================================
*   Project              : RTD AUTOSAR 4.7
*   Platform             : CORTEXM
*   Peripheral           : AE
*   Dependencies         : none
*
*   Autosar Version      : 4.7.0
*   Autosar Revision     : ASR_REL_4_7_REV_0000
*   Autosar Conf.Variant :
*   SW Version           : 3.0.0
*   Build Version        : S32K3_RTD_3_0_0_D2303_ASR_REL_4_7_REV_0000_20230331
*
*   (c) Copyright 2020 - 2023 NXP Semiconductors
*   All Rights Reserved.
*
*   NXP Confidential. This software is owned or controlled by NXP and may only be
*   used strictly in accordance with the applicable license terms. By expressly
*   accepting such terms or by downloading, installing, activating and/or otherwise
*   using the software, you are agreeing that you have read, and that you agree to
*   comply with and are bound by, such license terms. If you do not agree to be
*   bound by the applicable license terms, then you may not retain, install,
*   activate or otherwise use the software.
==================================================================================================*/

#ifndef AELINPHY_LINTRCV_IP_TYPESS_H
#define AELINPHY_LINTRCV_IP_TYPESS_H

/**
*   @file   AeLinPhy_LinTrcv_Ip_Types.h
*
*   @defgroup aelinphy_lintrcv_ip AeLinPhy LinTrcv IPL
*   @addtogroup  aelinphy_lintrcv_ip AeLinPhy LinTrcv IPL
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

/*==================================================================================================
*                                 SOURCE FILE VERSION INFORMATION
==================================================================================================*/

#define AELINPHY_LINTRCV_IP_TYPES_VENDOR_ID                    43
#define AELINPHY_LINTRCV_IP_TYPES_AR_RELEASE_MAJOR_VERSION     4
#define AELINPHY_LINTRCV_IP_TYPES_AR_RELEASE_MINOR_VERSION     7
#define AELINPHY_LINTRCV_IP_TYPES_AR_RELEASE_REVISION_VERSION  0
#define AELINPHY_LINTRCV_IP_TYPES_SW_MAJOR_VERSION             3
#define AELINPHY_LINTRCV_IP_TYPES_SW_MINOR_VERSION             0
#define AELINPHY_LINTRCV_IP_TYPES_SW_PATCH_VERSION             0

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/

/*==================================================================================================
*                                            CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/

/*==================================================================================================
*                                              ENUMS
==================================================================================================*/
/**
 * @brief Enum containing the events related to a mode of Lin Tracv
 *
 * @details This enum defines types for an enumerating event related to mode of Lin Tracv.
 *
 * @implements AeLinPhy_LinTrcv_Ip_TransceiverModeType_enum
 *
 *
 */
typedef enum
{
    AELINPHY_LINTRCV_IP_OFF_MODE                = 0x00U,    /**< @brief The LIN Physical Layer is fully disabled. No wake-up functionality is available.  */
    AELINPHY_LINTRCV_IP_RECV_ONLY_MODE          = 0x01U,    /**< @brief Entering this mode disables the transmitter and immediately stops any on-going transmission, The receiver is running in full performance mode */
    AELINPHY_LINTRCV_IP_NORMAL_MODE             = 0x02U,    /**< @brief The full functionality is available. Both receiver and transmitter are enabled. */
    AELINPHY_LINTRCV_IP_STANDBY_MODE            = 0x03U,    /**< @brief The transmitter of the LIN Physical Layer is disabled and the receiver enters a low power mode in order to be able to detect valid wake-up pulses on the LIN bus*/
} AeLinPhy_LinTrcv_Ip_TransceiverModeType;

/**
 * @brief AELINPHY status type
 * @implements AeLinPhy_LinTrcv_Ip_StatusType_enum
 */
typedef enum
{
    AELINPHY_LINTRCV_IP_STATUS_SUCCESS = 0x00,              /** @brief No error. */
    AELINPHY_LINTRCV_IP_STATUS_ERROR                        /** @brief General error, command failed to execute task successfully. */
} AeLinPhy_LinTrcv_Ip_StatusType;

/**
 * @brief Enum containing the events related to a wakeup mode of Lin Tracv
 *
 * @details This enum defines types for an enumerating event related to wakeup mode of Lin Tracv.
 *
 * @implements AeLinPhy_LinTrcv_Ip_TransceiverModeType_enum
 *
 *
 */
typedef enum
{
    AELINPHY_LINTRCV_IP_WUMODE_ENABLE         = 0x00U,    /**< @brief The notification for wakeup events is enabled on the addressed network.  */
    AELINPHY_LINTRCV_IP_WUMODE_DISABLE        = 0x01U,    /**< @brief The notification for wakeup events is disabled on the addressed network */
    AELINPHY_LINTRCV_IP_WUMODE_CLEAR          = 0x02U,    /**< @brief A stored wakeup event is cleared on the addressed network*/
} AeLinPhy_LinTrcv_Ip_TrcvWakeupModeType;
/*==================================================================================================
*                                  STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/


/**
 * @brief User configuration structure of the LINTRCV driver.
 * @implements AeLinPhy_LinTrcv_Ip_UserConfigType_structure
 *
 *
 */
typedef struct
{
    uint8 Instance;                                         /**< @brief Hardware Instance */
} AeLinPhy_LinTrcv_Ip_UserConfigType;

/*==================================================================================================
*                                  GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                       FUNCTION PROTOTYPES
==================================================================================================*/


#ifdef __cplusplus
}
#endif

/** @} */

#endif /* AELINPHY_LINTRCV_IP_TYPESS_H  */
