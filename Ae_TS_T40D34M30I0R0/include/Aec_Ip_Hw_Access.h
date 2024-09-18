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

#ifndef AEC_IP_HW_ACCESS_H
#define AEC_IP_HW_ACCESS_H

/**
*   @file
*   
*   @internal
*   @addtogroup AEC_DRIVER AEC Driver
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
#include "Aec_Ip_Types.h"
#include "Aec_Ip.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define AEC_IP_HW_ACCESS_VENDOR_ID                    43
#define AEC_IP_HW_ACCESS_AR_RELEASE_MAJOR_VERSION     4
#define AEC_IP_HW_ACCESS_AR_RELEASE_MINOR_VERSION     7
#define AEC_IP_HW_ACCESS_AR_RELEASE_REVISION_VERSION  0
#define AEC_IP_HW_ACCESS_SW_MAJOR_VERSION             3
#define AEC_IP_HW_ACCESS_SW_MINOR_VERSION             0
#define AEC_IP_HW_ACCESS_SW_PATCH_VERSION             0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Checks against Aec_Ip.h */
#if (AEC_IP_HW_ACCESS_VENDOR_ID != AEC_IP_VENDOR_ID)
    #error "Aec_Ip_Hw_Access.h and Aec_Ip.h have different vendor ids"
#endif
#if (( AEC_IP_HW_ACCESS_AR_RELEASE_MAJOR_VERSION    != AEC_IP_AR_RELEASE_MAJOR_VERSION) || \
     ( AEC_IP_HW_ACCESS_AR_RELEASE_MINOR_VERSION    != AEC_IP_AR_RELEASE_MINOR_VERSION) || \
     ( AEC_IP_HW_ACCESS_AR_RELEASE_REVISION_VERSION != AEC_IP_AR_RELEASE_REVISION_VERSION))
     #error "AUTOSAR Version Numbers of Aec_Ip_Hw_Access.h and Aec_Ip.h are different"
#endif
#if (( AEC_IP_HW_ACCESS_SW_MAJOR_VERSION != AEC_IP_SW_MAJOR_VERSION) || \
     ( AEC_IP_HW_ACCESS_SW_MINOR_VERSION != AEC_IP_SW_MINOR_VERSION) || \
     ( AEC_IP_HW_ACCESS_SW_PATCH_VERSION != AEC_IP_SW_PATCH_VERSION))
    #error "Software Version Numbers of Aec_Ip_Hw_Access.h and Aec_Ip.h are different"
#endif

/* Checks against Aec_Ip_Types.h */
#if (AEC_IP_HW_ACCESS_VENDOR_ID != AEC_IP_TYPES_VENDOR_ID)
    #error "Aec_Ip_Hw_Access.h and Aec_Ip_Types.h have different vendor ids"
#endif
#if (( AEC_IP_HW_ACCESS_AR_RELEASE_MAJOR_VERSION    != AEC_IP_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     ( AEC_IP_HW_ACCESS_AR_RELEASE_MINOR_VERSION    != AEC_IP_TYPES_AR_RELEASE_MINOR_VERSION) || \
     ( AEC_IP_HW_ACCESS_AR_RELEASE_REVISION_VERSION != AEC_IP_TYPES_AR_RELEASE_REVISION_VERSION))
     #error "AUTOSAR Version Numbers of Aec_Ip_Hw_Access.h and Aec_Ip_Types.h are different"
#endif
#if (( AEC_IP_HW_ACCESS_SW_MAJOR_VERSION != AEC_IP_TYPES_SW_MAJOR_VERSION) || \
     ( AEC_IP_HW_ACCESS_SW_MINOR_VERSION != AEC_IP_TYPES_SW_MINOR_VERSION) || \
     ( AEC_IP_HW_ACCESS_SW_PATCH_VERSION != AEC_IP_TYPES_SW_PATCH_VERSION))
    #error "Software Version Numbers of Aec_Ip_Hw_Access.h and Aec_Ip_Types.h are different"
#endif

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/*******************************************************************************
 * Variables
 ******************************************************************************/


/*******************************************************************************
 * API
 ******************************************************************************/
#define AE_START_SEC_CODE
#include "Ae_MemMap.h"

/*!
 * @brief Initializes a starting reference point for timeout
 *
 * @param[out] StartTimeOut    The starting time from which elapsed time is measured
 * @param[out] ElapsedTimeOut  The elapsed time to be passed to AEC_TimeoutExpired
 * @param[out] TimeoutTicksOut The timeout value (in ticks) to be passed to AEC_TimeoutExpired
 * @param[in]  TimeoutUs       The timeout value (in microseconds)
 */
void AEC_StartTimeout(uint32 *StartTimeOut,
                       uint32 *ElapsedTimeOut,
                       uint32 *TimeoutTicksOut,
                       uint32 TimeoutUs);

/*!
 * @brief Checks for timeout condition.
 *
 * @param[in,out] StartTimeInOut    The starting time from which elapsed time is measured
 * @param[in,out] ElapsedTimeInOut  The accumulated elapsed time from the starting time reference
 * @param[in]     TimeoutTicks      The timeout limit (in ticks)
 */
boolean AEC_TimeoutExpired(uint32 *StartTimeInOut,
                            uint32 *ElapsedTimeInOut,
                            uint32 TimeoutTicks);
/*!
 * @brief Handle interrupt that trigger interrupt_out.
 *
 */ 
void AEC_IRQEventFaultHandler(void);

/*!
 * @brief Set up to enable for events/faults to raise interrupt_out.
 *
 * Return AEC_STATUS_SUCCESS    if set up successful.
 *        AEC_STATUS_TIMEOUT    if set up failed.
 */
Aec_Ip_StatusType AEC_EventsFaultsEnable(void);
                            
#define AE_STOP_SEC_CODE
#include "Ae_MemMap.h"


#ifdef __cplusplus
}
#endif

/** @} */

#endif /* AEC_IP_HW_ACCESS_H */
