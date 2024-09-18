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

#ifndef LINTRCV_43_AE_IPW_H
#define LINTRCV_43_AE_IPW_H

/**
*   @file
*
*   @internal
*   @addtogroup LINTRCV_43_AE_IPW
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

#include "LinTrcv_43_AE_Ipw_Cfg.h"
#include "AeLinPhy_LinTrcv_Ip.h"
#include "Lin_GeneralTypes.h"
#include "LinTrcv_43_AE_Types.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/

#define LINTRCV_43_AE_IPW_VENDOR_ID                    43
#define LINTRCV_43_AE_IPW_AR_RELEASE_MAJOR_VERSION     4
#define LINTRCV_43_AE_IPW_AR_RELEASE_MINOR_VERSION     7
#define LINTRCV_43_AE_IPW_AR_RELEASE_REVISION_VERSION  0
#define LINTRCV_43_AE_IPW_SW_MAJOR_VERSION             3
#define LINTRCV_43_AE_IPW_SW_MINOR_VERSION             0
#define LINTRCV_43_AE_IPW_SW_PATCH_VERSION             0
/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/

/* Checks against LinTrcv_43_AE_Ipw_Cfg.h */
#if (LINTRCV_43_AE_IPW_VENDOR_ID != LINTRCV_43_AE_IPW_CFG_VENDOR_ID)
    #error "LinTrcv_43_AE_Ipw.h and LinTrcv_43_AE_Ipw_Cfg.h have different vendor ids"
#endif
#if ((LINTRCV_43_AE_IPW_AR_RELEASE_MAJOR_VERSION    != LINTRCV_43_AE_IPW_CFG_AR_RELEASE_MAJOR_VERSION) || \
     (LINTRCV_43_AE_IPW_AR_RELEASE_MINOR_VERSION    != LINTRCV_43_AE_IPW_CFG_AR_RELEASE_MINOR_VERSION) || \
     (LINTRCV_43_AE_IPW_AR_RELEASE_REVISION_VERSION != LINTRCV_43_AE_IPW_CFG_AR_RELEASE_REVISION_VERSION))
    #error "AUTOSAR Version Numbers of LinTrcv_43_AE_Ipw.h and LinTrcv_43_AE_Ipw_Cfg.h are different"
#endif
#if ((LINTRCV_43_AE_IPW_SW_MAJOR_VERSION != LINTRCV_43_AE_IPW_CFG_SW_MAJOR_VERSION) || \
     (LINTRCV_43_AE_IPW_SW_MINOR_VERSION != LINTRCV_43_AE_IPW_CFG_SW_MINOR_VERSION) || \
     (LINTRCV_43_AE_IPW_SW_PATCH_VERSION != LINTRCV_43_AE_IPW_CFG_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of LinTrcv_43_AE_Ipw.h and LinTrcv_43_AE_Ipw_Cfg.h are different"
#endif

/* Checks against AeLinPhy_LinTrcv_43_AE_Ip.h */
#if (LINTRCV_43_AE_IPW_VENDOR_ID != AELINPHY_LINTRCV_IP_VENDOR_ID)
    #error "LinTrcv_43_AE_Ipw.h and AeLinPhy_LinTrcv_Ip.h have different vendor ids"
#endif
#if ((LINTRCV_43_AE_IPW_AR_RELEASE_MAJOR_VERSION    != AELINPHY_LINTRCV_IP_AR_RELEASE_MAJOR_VERSION) || \
     (LINTRCV_43_AE_IPW_AR_RELEASE_MINOR_VERSION    != AELINPHY_LINTRCV_IP_AR_RELEASE_MINOR_VERSION) || \
     (LINTRCV_43_AE_IPW_AR_RELEASE_REVISION_VERSION != AELINPHY_LINTRCV_IP_AR_RELEASE_REVISION_VERSION))
    #error "AUTOSAR Version Numbers of LinTrcv_43_AE_Ipw.h and AeLinPhy_LinTrcv_Ip.h are different"
#endif
#if ((LINTRCV_43_AE_IPW_SW_MAJOR_VERSION != AELINPHY_LINTRCV_IP_SW_MAJOR_VERSION) || \
     (LINTRCV_43_AE_IPW_SW_MINOR_VERSION != AELINPHY_LINTRCV_IP_SW_MINOR_VERSION) || \
     (LINTRCV_43_AE_IPW_SW_PATCH_VERSION != AELINPHY_LINTRCV_IP_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of LinTrcv_43_AE_Ipw.h and AeLinPhy_LinTrcv_Ip.h are different"
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if current file and Lin_GeneralTypes.h header file are of the same Autosar version */
    #if ((LINTRCV_43_AE_IPW_AR_RELEASE_MAJOR_VERSION != LIN_GENERALTYPES_AR_RELEASE_MAJOR_VERSION) || \
         (LINTRCV_43_AE_IPW_AR_RELEASE_MINOR_VERSION != LIN_GENERALTYPES_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of LinTrcv.h and Lin_GeneralTypes.h are different"
    #endif
#endif

/* Checks against LinTrcv_43_AE_Types.h */
#if (LINTRCV_43_AE_IPW_VENDOR_ID != LINTRCV_43_AE_TYPES_VENDOR_ID)
    #error "LinTrcv_43_AE_Ipw.h and LinTrcv_43_AE_Types.h have different vendor ids"
#endif
/* Check if current file and LinTrcv_43_AE_Types header file are of the same Autosar version */
#if ((LINTRCV_43_AE_IPW_AR_RELEASE_MAJOR_VERSION    != LINTRCV_43_AE_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (LINTRCV_43_AE_IPW_AR_RELEASE_MINOR_VERSION    != LINTRCV_43_AE_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (LINTRCV_43_AE_IPW_AR_RELEASE_REVISION_VERSION != LINTRCV_43_AE_TYPES_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of LinTrcv_43_AE_Ipw.h and LinTrcv_43_AE_Types.h are different"
#endif
/* Check if current file and LinTrcv_43_AE_Types header file are of the same Software version */
#if ((LINTRCV_43_AE_IPW_SW_MAJOR_VERSION != LINTRCV_43_AE_TYPES_SW_MAJOR_VERSION) || \
     (LINTRCV_43_AE_IPW_SW_MINOR_VERSION != LINTRCV_43_AE_TYPES_SW_MINOR_VERSION) || \
     (LINTRCV_43_AE_IPW_SW_PATCH_VERSION != LINTRCV_43_AE_TYPES_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of LinTrcv_43_AE_Ipw.h and LinTrcv_43_AE_Types.h are different"
#endif
/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/


/*==================================================================================================
*                                             ENUMS
==================================================================================================*/

/*==================================================================================================
*                                  STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
*                                 GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                     FUNCTION PROTOTYPES
==================================================================================================*/
#define LINTRCV_43_AE_START_SEC_CODE
#include "LinTrcv_43_AE_MemMap.h"

/**
* @internal
* @brief   Check if a LINTRCV channel has been waked-up.
* @details This function identifies which LINTRCV channel has been woken
*          up by the LINTRCV bus transceiver This API is used when the
*          LINTRCV channel wake up functionality is disabled (wake up
*          interrupt is disabled) it checks the wake up flag from
*          all LINTRCV channels which are in sleep mode and which
*          have the wake up functionality disabled.
*
* @param[in] Channel LINTRCV channel to be waked-up.
*
* @return            Std_ReturnType.
* @retval E_OK       If the LINTRCV Channel has the wake
*                    up flag set and the wake up ISR disabled
* @retval E_NOT_OK   Otherwise.
*
*
**/
Std_ReturnType LinTrcv_43_AE_Ipw_CheckWakeup(uint8 LinNetwork);

/**
* @internal
* @brief   Initialize a LINTRCV channel.
* @details This function initializes all hardware registers needed to
*          start the LINTRCV functionality on the selected channel.
*
* @param[in] Channel LINTRCV channel to be initialized.
*
* @return            void.
*
*/
void LinTrcv_43_AE_Ipw_InitChannel(uint8 LinNetwork, const LinTrcv_43_AE_HwConfigType* ChannelConfigPtr);
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
Std_ReturnType  LinTrcv_43_AE_Ipw_SetOpMode(uint8 LinNetwork, LinTrcv_TrcvModeType OpMode);
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
Std_ReturnType  LinTrcv_43_AE_Ipw_GetOpMode(uint8 LinNetwork, LinTrcv_TrcvModeType * OpMode);
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
Std_ReturnType  LinTrcv_43_AE_Ipw_GetBusWuReason(uint8 LinNetwork, LinTrcv_TrcvWakeupReasonType * Reason);
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
Std_ReturnType  LinTrcv_43_AE_Ipw_SetWakeupMode(uint8 LinNetwork, LinTrcv_TrcvWakeupModeType TrcvWakupMode);

#define LINTRCV_43_AE_STOP_SEC_CODE
#include "LinTrcv_43_AE_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */

#endif /* LINTRCV_43_AE_IPW_H */
