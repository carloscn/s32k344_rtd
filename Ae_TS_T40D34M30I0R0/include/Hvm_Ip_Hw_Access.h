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

#ifndef HVM_IP_HW_ACCESS_H
#define HVM_IP_HW_ACCESS_H

/**
*   @file
*   
*   @internal
*   @addtogroup HVM_DRIVER HVM Driver
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
#include "Hvm_Ip_Types.h"
#include "Hvm_Ip.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define HVM_IP_HW_ACCESS_VENDOR_ID                    43
#define HVM_IP_HW_ACCESS_AR_RELEASE_MAJOR_VERSION     4
#define HVM_IP_HW_ACCESS_AR_RELEASE_MINOR_VERSION     7
#define HVM_IP_HW_ACCESS_AR_RELEASE_REVISION_VERSION  0
#define HVM_IP_HW_ACCESS_SW_MAJOR_VERSION             3
#define HVM_IP_HW_ACCESS_SW_MINOR_VERSION             0
#define HVM_IP_HW_ACCESS_SW_PATCH_VERSION             0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Checks against Hvm_Ip.h */
#if (HVM_IP_HW_ACCESS_VENDOR_ID != HVM_IP_VENDOR_ID)
    #error "Hvm_Ip_Hw_Access.h and Hvm_Ip.h have different vendor ids"
#endif
#if (( HVM_IP_HW_ACCESS_AR_RELEASE_MAJOR_VERSION    != HVM_IP_AR_RELEASE_MAJOR_VERSION) || \
     ( HVM_IP_HW_ACCESS_AR_RELEASE_MINOR_VERSION    != HVM_IP_AR_RELEASE_MINOR_VERSION) || \
     ( HVM_IP_HW_ACCESS_AR_RELEASE_REVISION_VERSION != HVM_IP_AR_RELEASE_REVISION_VERSION))
     #error "AUTOSAR Version Numbers of Hvm_Ip_Hw_Access.h and Hvm_Ip.h are different"
#endif
#if (( HVM_IP_HW_ACCESS_SW_MAJOR_VERSION != HVM_IP_SW_MAJOR_VERSION) || \
     ( HVM_IP_HW_ACCESS_SW_MINOR_VERSION != HVM_IP_SW_MINOR_VERSION) || \
     ( HVM_IP_HW_ACCESS_SW_PATCH_VERSION != HVM_IP_SW_PATCH_VERSION))
    #error "Software Version Numbers of Hvm_Ip_Hw_Access.h and Hvm_Ip.h are different"
#endif

/* Checks against Hvm_Ip_Types.h */
#if (HVM_IP_HW_ACCESS_VENDOR_ID != HVM_IP_TYPES_VENDOR_ID)
    #error "Hvm_Ip_Hw_Access.h and Hvm_Ip_Types.h have different vendor ids"
#endif
#if (( HVM_IP_HW_ACCESS_AR_RELEASE_MAJOR_VERSION    != HVM_IP_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     ( HVM_IP_HW_ACCESS_AR_RELEASE_MINOR_VERSION    != HVM_IP_TYPES_AR_RELEASE_MINOR_VERSION) || \
     ( HVM_IP_HW_ACCESS_AR_RELEASE_REVISION_VERSION != HVM_IP_TYPES_AR_RELEASE_REVISION_VERSION))
     #error "AUTOSAR Version Numbers of Hvm_Ip_Hw_Access.h and Hvm_Ip_Types.h are different"
#endif
#if (( HVM_IP_HW_ACCESS_SW_MAJOR_VERSION != HVM_IP_TYPES_SW_MAJOR_VERSION) || \
     ( HVM_IP_HW_ACCESS_SW_MINOR_VERSION != HVM_IP_TYPES_SW_MINOR_VERSION) || \
     ( HVM_IP_HW_ACCESS_SW_PATCH_VERSION != HVM_IP_TYPES_SW_PATCH_VERSION))
    #error "Software Version Numbers of Hvm_Ip_Hw_Access.h and Hvm_Ip_Types.h are different"
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
 * @param[out] ElapsedTimeOut  The elapsed time to be passed to HVM_TimeoutExpired
 * @param[out] TimeoutTicksOut The timeout value (in ticks) to be passed to HVM_TimeoutExpired
 * @param[in]  TimeoutUs       The timeout value (in microseconds)
 */
void HVM_StartTimeout(uint32 *StartTimeOut,
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
boolean HVM_TimeoutExpired(uint32 *StartTimeInOut,
                            uint32 *ElapsedTimeInOut,
                            uint32 TimeoutTicks);
                                                      
/*!
 * @brief Empty Callback function.
 *
 * @details  This function added to driver in case AeHvmUnderControlIsrCallback in configuration is false to avoid failure. User can handle isr by 
 *           a function Hvm_Ip_ReportEventsCallback was defined by themselves. 
 *
 */
void Hvm_Ip_ReportEventsCallback(uint8 Instance, Hvm_Ip_OutputStatusType Event);

                           
#define AE_STOP_SEC_CODE
#include "Ae_MemMap.h"


#ifdef __cplusplus
}
#endif

/** @} */

#endif /* HVM_IP_HW_ACCESS_H */
