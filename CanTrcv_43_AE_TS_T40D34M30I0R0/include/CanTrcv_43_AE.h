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
/**
* @file         CanTrcv_43_AE.h
* @version      3.0.0
*
* @brief        AUTOSAR CanTrcv_43_AE - module interface.
*               API header for CANTRCV driver.
*
*
* @addtogroup   CANTRCV_DRIVER
* @{
*/

#ifndef _CANTRCV_43_AE_H_
#define _CANTRCV_43_AE_H_

/*==================================================================================================
                                         INCLUDE FILES
 1) system and project includes
 2) needed interfaces from external units
 3) internal and external interfaces from this unit
==================================================================================================*/
#include "StandardTypes.h"
#include "Can_GeneralTypes.h"
#include "CanTrcv_43_AE_Cfg.h"
#include "CanTrcv_43_AE_Types.h"
/*==================================================================================================
                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define CANTRCV_43_AE_VENDOR_ID                    43
#define CANTRCV_43_AE_MODULE_ID                    70
#define CANTRCV_43_AE_AR_RELEASE_MAJOR_VERSION     4
#define CANTRCV_43_AE_AR_RELEASE_MINOR_VERSION     7
#define CANTRCV_43_AE_AR_RELEASE_REVISION_VERSION  0
#define CANTRCV_43_AE_SW_MAJOR_VERSION             3
#define CANTRCV_43_AE_SW_MINOR_VERSION             0
#define CANTRCV_43_AE_SW_PATCH_VERSION             0

/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/

/*==================================================================================================
                                           CONSTANTS
==================================================================================================*/

/*==================================================================================================
                                       DEFINES AND MACROS
==================================================================================================*/
#if (CANTRCV_43_AE_DEV_ERROR_DETECT == STD_ON)
/**
* 
*         Development errors.
*         The Can module shall be able to detect the following errors and exceptions depending
*                 on its configuration (development/production). Development Errors shall indicate errors
*                 that are caused by erroneous usage of the Can module API. This covers API parameter
*                 checks and call sequence errors.
*                 Development error values are of type uint8.
*
*/

/*! @brief Development Error ID for API called with wrong parameter for the CAN transceiver */
#define  CANTRCV_43_AE_E_INVALID_TRANSCEIVER       (0x1U)
/*! @brief Development Error ID for API called with null pointer parameter */
#define  CANTRCV_43_AE_E_PARAM_POINTER             (0x2U)
/*! @brief Development Error ID for API service used without initialization */
#define  CANTRCV_43_AE_E_UNINIT                    (0x11U)
/*! @brief Development Error ID for API service called in wrong transceiver operation mode (STANDBY expected) */
#define  CANTRCV_43_AE_E_TRCV_NOT_STANDBY          (0x21U)
/*! @brief Development Error ID for API service called in wrong transceiver operation mode (NORMAL expected) */
#define  CANTRCV_43_AE_E_TRCV_NOT_NORMAL           (0x22U)
/*! @brief Development Error ID for API service called with invalid parameter for TrcvWakeupMode */
#define  CANTRCV_43_AE_E_PARAM_TRCV_WAKEUP_MODE    (0x23U)
/*! @brief Development Error ID for API service called with invalid parameter for OpMode */
#define  CANTRCV_43_AE_E_PARAM_TRCV_OPMODE         (0x24U)
/*! @brief Development Error ID for Configured baud rate is not supported by the transceiver */
#define  CANTRCV_43_AE_E_BAUDRATE_NOT_SUPPORTED    (0x25U)
/*! @brief Development Error ID for Module initialization has failed, e.g. CanTrcv_Init() called with an invalid pointer in postbuild. */
#define  CANTRCV_43_AE_E_INIT_FAILED               (0x27U)
#endif /* CANTRCV_43_AE_DEV_ERROR_DETECT == STD_ON */
/*! @brief Runtime Error ID when No/incorrect communication to transceiver. */
#define  CANTRCV_43_AE_E_NO_TRCV_CONTROL           (0x26U)
/**
*  Service ID (APIs) for Det reporting
*
*/
/*! @brief Service ID of CanTrcv_43_AE_Init */
#define CANTRCV_43_AE_SID_INIT                                 ((uint8)0x00U)
/*! @brief Service ID of CanTrcv_43_AE_SetOpMode */
#define CANTRCV_43_AE_SID_SET_OPMODE                           ((uint8)0x01U)
/*! @brief Service ID of CanTrcv_43_AE_GetOpMode */
#define CANTRCV_43_AE_SID_GET_OPMODE                           ((uint8)0x02U)
/*! @brief Service ID of CanTrcv_43_AE_GetBusWuReason */
#define CANTRCV_43_AE_SID_GET_BUS_WU_REASON                    ((uint8)0x03U)
/*! @brief Service ID of CanTrcv_43_AE_GetVersionInfo */
#define CANTRCV_43_AE_SID_GET_VERSION_INFO                     ((uint8)0x04U)
/*! @brief Service ID of CanTrcv_43_AE_SetWakeupMode */
#define CANTRCV_43_AE_SID_SET_WAKEUP_MODE                      ((uint8)0x05U)
/*! @brief Service ID of CanTrcv_43_AE_CheckWakeup */
#define CANTRCV_43_AE_SID_CHECK_WAKEUP                         ((uint8)0x07U)
/*! @brief Service ID of CanTrcv_43_AE_CheckWakeFlag */
#define CANTRCV_43_AE_SID_CHECK_WAKE_FLAG                      ((uint8)0x0EU)
/*! @brief Service ID of CanTrcv_43_AE_DeInit */
#define CANTRCV_43_AE_SID_DEINIT                               ((uint8)0x10U)
/*==================================================================================================
                                             ENUMS
==================================================================================================*/

/**
* @brief        CanTrcv_43_AE_eDriverStatusType
* @details      Driver status helps to prevent double driver initialization.
*
*/
typedef enum
{
    CANTRCV_43_AE_NOT_ACTIVE = 0x0U, /*!< Driver not initialized */
    CANTRCV_43_AE_ACTIVE  = 0x1U /*!< Driver ready */
} CanTrcv_43_AE_eDriverStatusType;
/*==================================================================================================
                                 STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/
/** @brief Can Transceiver Configuration */
/** @implements  CanTrcv_ConfigType_struct */
typedef struct
{
    /** @brief Configuration Core ID */
    const uint32 CanTrcv_u32CoreID;
    /** @brief Pointer to all Tranceiver channels asigned to the partition */
    const CanTrcv_43_AE_TransceiverConfigType * const * CanTrcv_ppTransceivers;
} CanTrcv_43_AE_ConfigType;
/*==================================================================================================
                                 GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/
#define CANTRCV_43_AE_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanTrcv_43_AE_MemMap.h"

/* Extern driver and device configuration structures. */
CANTRCV_43_AE_CONFIG_EXT

#define CANTRCV_43_AE_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanTrcv_43_AE_MemMap.h"

/*==================================================================================================
                                     FUNCTION PROTOTYPES
==================================================================================================*/

#define CANTRCV_43_AE_START_SEC_CODE
#include "CanTrcv_43_AE_MemMap.h"

#if (CANTRCV_43_AE_VERSION_INFO_API == STD_ON)
/**
* @brief        CAN transceiver driver get version info function. SID is 0x04.
* @details      Returns the version information of this module.
*
* @param[out]   versioninfo     Pointer to where to store the version information of this module.
*
* @return       void
*
* @api
*/
/** @implements   CanTrcv_GetVersionInfo_Activity */
void CanTrcv_43_AE_GetVersionInfo(Std_VersionInfoType * VersionInfo);
#endif /* CANTRCV_43_AE_VERSION_INFO_API == STD_ON */

/**
* @brief        Initializes CanTrcv module. SID 0x00.
* @details      Initializes all transceivers configured in ConfigPtr parameter.
*               The CANTRCV module shall be initialized by CanTrcv_43_AE_Init() service call during the
*               start-up.
*
* @param[in]    ConfigPtr       Pointer to driver configuration structure.
*
* @return       void
*
*
* @pre          CanTrcv_43_AE_Init shall be called at most once during runtime.
* @post         CanTrcv_43_AE_Init shall initialize all the transceivers and set the driver in READY state.
*
* @api
*/
void CanTrcv_43_AE_Init(const CanTrcv_43_AE_ConfigType* ConfigPtr);

/**
* @brief        Sets the mode of the Transceiver to the value OpMode. SID 0x01.
* @details      Puts the device in one of following modes: normal, standby, sleep.
*
* @param[in]    Transceiver         Index of the transceiver.
* @param[out]   OpMode              Desired operating mode.
*
* @return       Std_ReturnType      Result of the transition.
* @retval       E_OK                Operation executed successfully.
* @retval       E_NOT_OK            Operation failed.
*
*
* @pre          CanTrcv module should be initialized before calling the CanTrcv_43_AE_SetOpMode method.
* @post         CanTrcv_43_AE_SetOpMode shall set the transceiver in the desired state.
*
* @api
*/
Std_ReturnType CanTrcv_43_AE_SetOpMode(uint8 Transceiver, CanTrcv_TrcvModeType OpMode);

/**
* @brief        Gets current operation mode. SID 0x02.
* @details      Gets the mode of the Transceiver and returns it in OpMode. The device is in one
*               of following modes: normal, standby, sleep.
*
* @param[in]    Transceiver         CAN transceiver ID.
* @param[out]   OpMode              Current operating mode.
*
* @return       Std_ReturnType      Result of the transition.
* @retval       E_OK                Operation executed successfully.
* @retval       E_NOT_OK            Operation failed.
*
*
* @pre          CanTrcv module should be initialized before calling the CanTrcv_43_AE_GetOpMode method.
* @post         CanTrcv_43_AE_GetOpMode shall return the currently working mode of the transceiver.
*
* @api
*/
Std_ReturnType CanTrcv_43_AE_GetOpMode(uint8 Transceiver, CanTrcv_TrcvModeType* OpMode);

/**
* @brief        Gets the wakeup reason of the Transceiver and returns it in parameter Reason. SID 0x03.
* @details      The device can be woken up by Wake Up Pattern
*                   
* @param[in]    Transceiver         CAN transceiver to which API call has to be applied.
* @param[out]   Reason              Pointer to wake up reason.
*
* @return       Std_ReturnType      Result of the transition.
* @retval       E_OK                Operation executed successfully.
* @retval       E_NOT_OK            Operation failed.
*
*
* @pre          CanTrcv module should be initialized before calling the CanTrcv_43_AE_GetBusWuReason method.
* @post         CanTrcv_43_AE_GetBusWuReason shall return wake up reason.
*
* @api
*/
/** @implements   CanTrcv_GetBusWuReason_Activity */
Std_ReturnType CanTrcv_43_AE_GetBusWuReason(uint8 Transceiver, CanTrcv_TrcvWakeupReasonType * Reason);

/**
* @brief        Enables, disables or clears wake up events of the Transceiver according to TrcvWakeupMode. SID 0x05.
* @details      Enables, disables or clears wake up functionality. If WU mode is disabled all wake up sources
*               and interrupts are off. If WU mode is enabled, all wake up sources and interrupts are set
*               according to configuration. If WU mode is clear, pending wake up flag is cleared.
*
* @param[in]    Transceiver         CAN Transceiver ID.
* @param[in]    TrcvWakeupMode      Mode of wake up functionality (enabled, disabled, cleared).
*
* @return       Std_ReturnType      Result of the transition.
* @retval       E_OK                Operation executed successfully.
* @retval       E_NOT_OK            Operation failed.
*
*
* @pre          CanTrcv module should be initialized before calling the CanTrcv_43_AE_SetWakeupMode method.
* @post         CanTrcv_43_AE_SetWakeupMode shall return status of the transceiver.
*
* @api
*/
/** @implements   CanTrcv_SetWakeupMode_Activity */
Std_ReturnType CanTrcv_43_AE_SetWakeupMode(uint8 Transceiver, CanTrcv_TrcvWakeupModeType TrcvWakeupMode);

/*================================================================================================*/
/**
* @brief        Service is called by underlying CANIF in case a wake up interrupt is detected. SID 0x07.
* @details      Reads wake up source from the device and  reports it to ECUM.
*
* @param[in]    Transceiver         CAN transceiver ID.
*
* @return       Std_ReturnType      Result of the transition.
* @retval       E_OK                Operation executed successfully.
* @retval       E_NOT_OK            Operation failed.
*
*
* @pre          CanTrcv module should be initialized before calling the CanTrcv_43_AE_CheckWakeup method.
* @post         CanTrcv_43_AE_CheckWakeup shall read and report wake up reason.
*
* @api
*/
/** @implements   CanTrcv_CheckWakeup_Activity */
Std_ReturnType CanTrcv_43_AE_CheckWakeup(uint8 Transceiver);

/*================================================================================================*/
/**
* @brief        Requests to check the status of the wakeup flag from the transceiver hardware. SID 0x0E.
* @details      Checks wake up event and if WU occurred, reports it.
*
* @param[in]    Transceiver         CAN transceiver ID.
*
* @return       Std_ReturnType      Result of the transition.
* @retval       E_OK                Operation executed successfully.
* @retval       E_NOT_OK            Operation failed.
*
*
* @pre          CanTrcv module should be initialized before calling the CanTrcv_43_AE_CheckWakeFlag method.
* @post         CanTrcv_43_AE_CheckWakeFlag shall check for wake up event, and if such event occurred, report it.
*
* @api
*/
/** @implements   CanTrcv_CheckWakeFlag_Activity */
Std_ReturnType CanTrcv_43_AE_CheckWakeFlag(uint8 Transceiver);

/**
* @brief          De-initializes the CanTrcv module. SID 0x10.
* @details        De-initialize all the transceivers.
*                 The CANTRCV module shall be de-initialized by CanTrcv_43_AE_DeInit() service call.
*                 This routine is called by:
*                 - CanIf or an upper layer according to Autosar requirements.
*
* @param[in]      None
*
* @return         void
*
*
* @pre            Before transceiver de-initalization, the driver must be initialized and the transceivers must not be in Start state.
* @post           CanTrcv_43_AE_DeInit shall de-initialize all the transceivers and set the driver in UNINIT state.
*
* @api
*/
void CanTrcv_43_AE_DeInit(void);

#define CANTRCV_43_AE_STOP_SEC_CODE
#include "CanTrcv_43_AE_MemMap.h"

#endif /* _CANTRCV_43_AE_H_ */
