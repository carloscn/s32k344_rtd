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

#ifndef LINTRCV_43_AE_H
#define LINTRCV_43_AE_H

/**
*   @file   LinTrcv.h
*   @implements LinTrcv.h_Artifact
*
*   @defgroup lin_driver LINTRCV Driver
*   @addtogroup  lin_driver LINTRCV Driver
*   @{
*/

#ifdef __cplusplus
extern "C"
{
#endif

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "LinTrcv_43_AE_Types.h"
#include "Lin_GeneralTypes.h"
#include "LinIf.h"
#include "LinTrcv_43_AE_Ipw.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define LINTRCV_43_AE_MODULE_ID                      64
#define LINTRCV_43_AE_VENDOR_ID                      43
#define LINTRCV_43_AE_AR_RELEASE_MAJOR_VERSION       4
#define LINTRCV_43_AE_AR_RELEASE_MINOR_VERSION       7
#define LINTRCV_43_AE_AR_RELEASE_REVISION_VERSION    0
#define LINTRCV_43_AE_SW_MAJOR_VERSION               3
#define LINTRCV_43_AE_SW_MINOR_VERSION               0
#define LINTRCV_43_AE_SW_PATCH_VERSION               0

/*==================================================================================================
*                                      FILE VERSION CHECKS
==================================================================================================*/
/* Checks against LinTrcv_43_AE_Types.h */
#if (LINTRCV_43_AE_VENDOR_ID != LINTRCV_43_AE_TYPES_VENDOR_ID)
    #error "LinTrcv.h and LinTrcv_43_AE_Types.h have different vendor ids"
#endif
/* Check if current file and LinTrcv_43_AE_Types header file are of the same Autosar version */
#if ((LINTRCV_43_AE_AR_RELEASE_MAJOR_VERSION    != LINTRCV_43_AE_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (LINTRCV_43_AE_AR_RELEASE_MINOR_VERSION    != LINTRCV_43_AE_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (LINTRCV_43_AE_AR_RELEASE_REVISION_VERSION != LINTRCV_43_AE_TYPES_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of LinTrcv.h and LinTrcv_43_AE_Types.h are different"
#endif
/* Check if current file and LinTrcv_43_AE_Types header file are of the same Software version */
#if ((LINTRCV_43_AE_SW_MAJOR_VERSION != LINTRCV_43_AE_TYPES_SW_MAJOR_VERSION) || \
     (LINTRCV_43_AE_SW_MINOR_VERSION != LINTRCV_43_AE_TYPES_SW_MINOR_VERSION) || \
     (LINTRCV_43_AE_SW_PATCH_VERSION != LINTRCV_43_AE_TYPES_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of LinTrcv.h and LinTrcv_43_AE_Types.h are different"
#endif
/* Checks against LinTrcv_43_AE_Ipw.h */
#if (LINTRCV_43_AE_VENDOR_ID != LINTRCV_43_AE_IPW_VENDOR_ID)
    #error "LinTrcv.h and LinTrcv_43_AE_Ipw.h have different vendor ids"
#endif
/* Check if current file and LinTrcv_43_AE_Ipw header file are of the same Autosar version */
#if ((LINTRCV_43_AE_AR_RELEASE_MAJOR_VERSION    != LINTRCV_43_AE_IPW_AR_RELEASE_MAJOR_VERSION) || \
     (LINTRCV_43_AE_AR_RELEASE_MINOR_VERSION    != LINTRCV_43_AE_IPW_AR_RELEASE_MINOR_VERSION) || \
     (LINTRCV_43_AE_AR_RELEASE_REVISION_VERSION != LINTRCV_43_AE_IPW_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of LinTrcv.h and LinTrcv_43_AE_Ipw.h are different"
#endif
/* Check if current file and LinTrcv_43_AE_Ipw header file are of the same Software version */
#if ((LINTRCV_43_AE_SW_MAJOR_VERSION != LINTRCV_43_AE_IPW_SW_MAJOR_VERSION) || \
     (LINTRCV_43_AE_SW_MINOR_VERSION != LINTRCV_43_AE_IPW_SW_MINOR_VERSION) || \
     (LINTRCV_43_AE_SW_PATCH_VERSION != LINTRCV_43_AE_IPW_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of LinTrcv.h and LinTrcv_43_AE_Ipw.h are different"
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if current file and Lin_GeneralTypes.h header file are of the same Autosar version */
    #if ((LINTRCV_43_AE_AR_RELEASE_MAJOR_VERSION != LIN_GENERALTYPES_AR_RELEASE_MAJOR_VERSION) || \
            (LINTRCV_43_AE_AR_RELEASE_MINOR_VERSION != LIN_GENERALTYPES_AR_RELEASE_MINOR_VERSION) \
        )
        #error "AutoSar Version Numbers of LinTrcv.h and Lin_GeneralTypes.h are different"
    #endif

    /* Check if current file and LinIf.h header file are of the same Autosar version */
    #if ((LINTRCV_43_AE_AR_RELEASE_MAJOR_VERSION != LINIF_AR_RELEASE_MAJOR_VERSION) || \
            (LINTRCV_43_AE_AR_RELEASE_MINOR_VERSION != LINIF_AR_RELEASE_MINOR_VERSION) \
        )
        #error "AutoSar Version Numbers of LinTrcv.h and LinIf.h are different"
    #endif
#endif

/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/

/*==================================================================================================
                                       DEFINES AND MACROS
==================================================================================================*/

#if (LINTRCV_43_AE_DEV_ERROR_DETECT == STD_ON)
/**
* @brief            API called with wrong parameter for LIN network.
*
*
*/
#define LINTRCV_43_AE_E_INVALID_LIN_NETWORK            ((uint8)0x01U)

/**
* @brief            API called with null pointer parameter
* @details          The LINTRCV Driver module shall report the development error
*                   "LINTRCV_43_AE_E_PARAM_POINTER (0x02)", when API Service is called
*                   with a NULL pointer. In case of this error, the API service
*                   shall return immediately without any further action,
*                   beside reporting this development error.
*
*
*/
#define LINTRCV_43_AE_E_PARAM_POINTER   ((uint8)0x02U)

/**
* @brief            API service used without initialization
* @details          The LINTRCV Driver module shall report the development error "LINTRCV_43_AE_E_UNINIT (0x11)",
*                   when the API Service is used without module initialization.
*
*
*/
#define LINTRCV_43_AE_E_UNINIT   ((uint8)0x11U)

/**
* @brief            API service called in wrong transceiver operation mode
*
*
*/
#define LINTRCV_43_AE_E_TRCV_NOT_SLEEP  ((uint8)0x21U)

/**
* @brief            API service called in wrong transceiver operation mode
*
*
*/
#define LINTRCV_43_AE_E_TRCV_NOT_NORMAL  ((uint8)0x22U)

/**
* @brief            API service called with invalid mode because optional transition is not enabled
*
*
*/
#define LINTRCV_43_AE_E_INVALID_TRCV_OPMODE       ((uint8)0x25U)

/**
* @brief            API service called with the requested resource is not configured to be available on the current core.
* @details          The LINTRCV will check upon each API call if the requested resource is configured to be available on the current core,
*                   and in case of error will return LINTRCV_43_AE_E_PARAM_CONFIG
*
*
*/
#define LINTRCV_43_AE_E_PARAM_CONFIG       ((uint8)0x07U)

/**
* @brief            API service called with invalid configuration pointer
* @details          The LINTRCV Driver module shall report the development error
*                   "LINTRCV_43_AE_E_INIT_FAILED (0x08)", when API Service is called
*                   with invalid configuration pointer.
*
*
*/

#define LINTRCV_43_AE_E_INIT_FAILED       ((uint8)0x08U)

#endif  /* (LINTRCV_43_AE_DEV_ERROR_DETECT == STD_ON) */

/**
* @brief            LINTRCV driver states
* @details          The state NOT_ACTIVE means that the LinTrcv module has not
*                   been initialized yet and cannot be used.
*
*
*/
#define LINTRCV_43_AE_NOT_ACTIVE                  (0x03U)

/**
* @brief            LINTRCV driver states
* @details          The ACTIVE state indicates that the LINTRCV driver has been
*                   initialized, making each available channel ready for service.
*
*
*/
#define LINTRCV_43_AE_ACTIVE                      (0x04U)

/* Service IDs of the AUTOSAR LINTRCV API. */

/**
* @brief            API service ID for LinTrcv_43_AE_Init() function.
* @details          Parameters used when raising an error or exception.
*
*
*/
#define LINTRCV_43_AE_INIT_ID                      ((uint8)0x00U)



/**
* @brief            API service ID for LinTrcv_43_AE_SetOpMode() function.
* @details          Parameters used when raising an error or exception.
*
*
*/
#define LINTRCV_43_AE_SETOPMODE_ID                 ((uint8)0x01U)

/**
* @brief            API service ID for LinTrcv_43_AE_GetOpMode() function.
* @details          Parameters used when raising an error or exception.
*
*
*/
#define LINTRCV_43_AE_GETOPMODE_ID                 ((uint8)0x02U)

/**
* @brief            API service ID for LinTrcv_43_AE_GetBusWuReason() function.
* @details          Parameters used when raising an error or exception.
*
*
*/
#define LINTRCV_43_AE_GETBUSWUREASON_ID            ((uint8)0x03U)

/**
* @brief            API service ID for LinTrcv_43_AE_GetVersionInfo() function.
* @details          Parameters used when raising an error or exception.
*
*
*/
#define LINTRCV_43_AE_GETVERSIONINFO_ID            ((uint8)0x04U)


/**
* @brief            API service ID for LinTrcv_43_AE_CheckWakeup() function.
* @details          Parameters used when raising an error or exception.
*
*
*/
#define LINTRCV_43_AE_CHECKWAKEUP_ID               ((uint8)0x07U)

/**
* @brief            API service ID for LinTrcv_43_AE_SetWakeupMode() function.
* @details          Parameters used when raising an error or exception.
*
*
*/
#define LINTRCV_43_AE_SETWAKEUPMODE_ID            ((uint8)0x05U)


/*==================================================================================================
*                                             ENUMS
==================================================================================================*/

/*==================================================================================================
*                                  STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
*                                    GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/

#define LINTRCV_43_AE_START_SEC_CODE
#include "LinTrcv_43_AE_MemMap.h"


/**
* @brief   Initializes the LINTRCV module.
*
* @param[in] ConfigPtr - Pointer to the selected configuration set.
*
* @return  void
*
* @pre     -
*
*
**/
void            LinTrcv_43_AE_Init(const LinTrcv_43_AE_ConfigType * ConfigPtr);


/**
* @brief   The internal state of the LIN transceiver driver is switched to mode given in the parameter OpMode.
*
* @param[in] LinNetwork       LIN network to wich API call has to be applied
* @param[in] OpMode           The parameter says to which operation mode the change shall be performed.
*
* @return                  Std_ReturnType.
* @retval E_OK             will be returned if the transceiver state has been changed to the requested mode.
*
* @retval E_NOT_OK         will be returned if the transceiver state change is not
*                          accepted or has failed or the parameter is out of the allowed range.
*
*
*
**/
Std_ReturnType  LinTrcv_43_AE_SetOpMode(uint8 LinNetwork, LinTrcv_TrcvModeType OpMode);

/**
* @brief   API detects the actual software state of LIN transceiver driver.
*
* @param[in] LinNetwork       LIN network to wich API call has to be applied
* @param[out] OpMode           Pointer to operation mode of the bus the API is applied to.
*
* @return                  Std_ReturnType.
* @retval E_OK             will be returned if the operation mode is detected.
*
* @retval E_NOT_OK         will be returned, if service request is failed due to
*                          development errors or the operation mode is not detected.
*
*
*
**/
Std_ReturnType  LinTrcv_43_AE_GetOpMode(uint8 LinNetwork, LinTrcv_TrcvModeType * OpMode);


/**
* @brief   This API provides the reason for the wakeup that the LIN transceiver has detected
*          in the parameter "Reason". The ability to detect and differentiate the possible
*          wakeup reasons depends strongly on the LIN transceiver hardware.
*
* @param[in] LinNetwork       LIN network to wich API call has to be applied
* @param[out] Reason          Pointer to wakeup reason of the bus the API is applied to.
*
* @return                  Std_ReturnType.
* @retval E_OK             will be returned if the wake up reason is detected.
*
* @retval E_NOT_OK         will be returned, if service request is failed due to
*                          development errors or the wakeup reason is not detected..
*
*
*
**/
Std_ReturnType  LinTrcv_43_AE_GetBusWuReason(uint8 LinNetwork, LinTrcv_TrcvWakeupReasonType * Reason);


/**
* @brief   Notifies the calling function if a wakeup is detected.
*
* @param[in] LinNetwork       LIN network to which API call has to be applied.
*
* @return                  Std_ReturnType.
* @retval E_NOT_OK         Will be returned, if no wakeup has been detected
*
* @retval E_OK             Will be returned, if a wakeup has been detected.
*
* @pre:    LinTrcv_43_AE_Init function must be called before this API.
*
*
**/
Std_ReturnType  LinTrcv_43_AE_CheckWakeup(uint8 LinNetwork);

/**
* @brief   This API enables, disables and clears the notification for wakeup events on the addressed network.
*
* @param[in] LinNetwork           LIN network to which API call has to be applied.
*
* @param[in] TrcvWakupMode        Requested transceiver wakup reason.
*
* @return                  Std_ReturnType.
* @retval E_NOT_OK         will be returned, if service request is failed due to
*                          development errors or the wakeup mode is not set
* @retval E_OK             will be returned if the transceiver state has been changed
*                          to the requested mode..
*
* @pre:    LinTrcv_43_AE_Init function must be called before this API.
*
*
**/
Std_ReturnType  LinTrcv_43_AE_SetWakeupMode(uint8 LinNetwork, LinTrcv_TrcvWakeupModeType TrcvWakupMode);

#if (LINTRCV_43_AE_VERSION_INFO_API == STD_ON)

/**
* @brief   Returns the version information of this module.
* @details The version information includes:
*
*          - Two bytes for the Vendor ID
*          - Two bytes for the Module ID
*          - One byte  for the Instance ID
*          - Three bytes version number. The numbering shall be vendor
*            specific: it consists of:
*
*             - The major, the minor and the patch version number of
*               the module;
*             - The AUTOSAR specification version number shall not
*               be included. The AUTOSAR specification version number is
*               checked during compile time and therefore not required
*               in this API.
*
* @param[in,out] versioninfo   Pointer for storing the version information
*                              of this module.
*
* @return void.
*
*
*
*
**/
void LinTrcv_43_AE_GetVersionInfo (Std_VersionInfoType * versioninfo);

#endif  /* LINTRCV_43_AE_VERSION_INFO_API == STD_ON */

#define LINTRCV_43_AE_STOP_SEC_CODE
#include "LinTrcv_43_AE_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */

#endif /* LINTRCV_43_AE_H */
