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

/**
*   @file
*
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
#include "Hvm_Ip_Hw_Access.h"
#include "OsIf.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define HVM_IP_HW_ACCESS_VENDOR_ID_C                      43
#define HVM_IP_HW_ACCESS_AR_RELEASE_MAJOR_VERSION_C       4
#define HVM_IP_HW_ACCESS_AR_RELEASE_MINOR_VERSION_C       7
#define HVM_IP_HW_ACCESS_AR_RELEASE_REVISION_VERSION_C    0
#define HVM_IP_HW_ACCESS_SW_MAJOR_VERSION_C               3
#define HVM_IP_HW_ACCESS_SW_MINOR_VERSION_C               0
#define HVM_IP_HW_ACCESS_SW_PATCH_VERSION_C               0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Checks against Hvm_Ip_Hw_Access.h */
#if (HVM_IP_HW_ACCESS_VENDOR_ID_C != HVM_IP_HW_ACCESS_VENDOR_ID)
    #error "Hvm_Ip_Hw_Access.c and Hvm_Ip_Hw_Access.h have different vendor ids"
#endif
#if ((HVM_IP_HW_ACCESS_AR_RELEASE_MAJOR_VERSION_C    != HVM_IP_HW_ACCESS_AR_RELEASE_MAJOR_VERSION) || \
     (HVM_IP_HW_ACCESS_AR_RELEASE_MINOR_VERSION_C    != HVM_IP_HW_ACCESS_AR_RELEASE_MINOR_VERSION) || \
     (HVM_IP_HW_ACCESS_AR_RELEASE_REVISION_VERSION_C != HVM_IP_HW_ACCESS_AR_RELEASE_REVISION_VERSION))
     #error "AUTOSAR Version Numbers of Hvm_Ip_Hw_Access.c and Hvm_Ip_Hw_Access.h are different"
#endif
#if ((HVM_IP_HW_ACCESS_SW_MAJOR_VERSION_C != HVM_IP_HW_ACCESS_SW_MAJOR_VERSION) || \
     (HVM_IP_HW_ACCESS_SW_MINOR_VERSION_C != HVM_IP_HW_ACCESS_SW_MINOR_VERSION) || \
     (HVM_IP_HW_ACCESS_SW_PATCH_VERSION_C != HVM_IP_HW_ACCESS_SW_PATCH_VERSION))
    #error "Software Version Numbers of Hvm_Ip_Hw_Access.c and Hvm_Ip_Hw_Access.h are different"
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Checks against OsIf.h */
    #if (( HVM_IP_HW_ACCESS_AR_RELEASE_MAJOR_VERSION_C    != OSIF_AR_RELEASE_MAJOR_VERSION) || \
        ( HVM_IP_HW_ACCESS_AR_RELEASE_MINOR_VERSION_C     != OSIF_AR_RELEASE_MINOR_VERSION))
        #error "AUTOSAR Version Numbers of Hvm_Ip_Hw_Access.c and OsIf.h are different"
    #endif
#endif
/*******************************************************************************
 * Definitions
 ******************************************************************************/
 
/*******************************************************************************
 * Variables
 ******************************************************************************/

/*******************************************************************************
 * Private Functions
 ******************************************************************************/
#define AE_START_SEC_CODE
#include "Ae_MemMap.h"

/*FUNCTION**********************************************************************
 *
 * Function Name : HVM_StartTimeout
 * Description   : Checks for timeout condition
 *
 *END**************************************************************************/
void HVM_StartTimeout(uint32 *StartTimeOut,
                       uint32 *ElapsedTimeOut,
                       uint32 *TimeoutTicksOut,
                       uint32 TimeoutUs)
{
    *StartTimeOut    = OsIf_GetCounter(HVM_TIMEOUT_TYPE);
    *ElapsedTimeOut  = 0U;
    *TimeoutTicksOut = OsIf_MicrosToTicks(TimeoutUs, HVM_TIMEOUT_TYPE);
}

/*FUNCTION**********************************************************************
 *
 * Function Name : HVM_TimeoutExpired
 * Description   : Checks for timeout expiration condition
 *
 *END**************************************************************************/
boolean HVM_TimeoutExpired(uint32 *StartTimeInOut,
                            uint32 *ElapsedTimeInOut,
                            uint32 TimeoutTicks)
{
    *ElapsedTimeInOut += OsIf_GetElapsed(StartTimeInOut, HVM_TIMEOUT_TYPE);

    return ((*ElapsedTimeInOut >= TimeoutTicks)? TRUE : FALSE);
}

#if (STD_OFF == HVM_CONTROL_CALLBACK_FUNC)
/*FUNCTION**********************************************************************
 *
 * Function Name : Hvm_Ip_ReportEventsCallback
 * Description   : Empty Callback function.
 *
 *END**************************************************************************/ 
void Hvm_Ip_ReportEventsCallback(uint8 Instance, Hvm_Ip_OutputStatusType Event)
{
    /* No implementation */
    (void)Instance;
    (void)Event;
}
#endif
/*******************************************************************************
 * Code
 ******************************************************************************/


#define AE_STOP_SEC_CODE
#include "Ae_MemMap.h"


#ifdef __cplusplus
}
#endif
/** @} */
