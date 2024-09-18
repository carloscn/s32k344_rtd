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

/**
*   @file
*
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
#include "Aec_Ip_Hw_Access.h"
#include "Aec_Ip_Irq.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define AEC_IP_IRQ_VENDOR_ID_C                      43
#define AEC_IP_IRQ_AR_RELEASE_MAJOR_VERSION_C       4
#define AEC_IP_IRQ_AR_RELEASE_MINOR_VERSION_C       7
#define AEC_IP_IRQ_AR_RELEASE_REVISION_VERSION_C    0
#define AEC_IP_IRQ_SW_MAJOR_VERSION_C               3
#define AEC_IP_IRQ_SW_MINOR_VERSION_C               0
#define AEC_IP_IRQ_SW_PATCH_VERSION_C               0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Checks against Aec_Ip_Hw_Access.h */
#if (AEC_IP_IRQ_VENDOR_ID_C != AEC_IP_HW_ACCESS_VENDOR_ID)
    #error "Aec_Ip_Irq.c and Aec_Ip_Hw_Access.h have different vendor ids"
#endif
#if ((AEC_IP_IRQ_AR_RELEASE_MAJOR_VERSION_C    != AEC_IP_HW_ACCESS_AR_RELEASE_MAJOR_VERSION) || \
     (AEC_IP_IRQ_AR_RELEASE_MINOR_VERSION_C    != AEC_IP_HW_ACCESS_AR_RELEASE_MINOR_VERSION) || \
     (AEC_IP_IRQ_AR_RELEASE_REVISION_VERSION_C != AEC_IP_HW_ACCESS_AR_RELEASE_REVISION_VERSION))
     #error "AUTOSAR Version Numbers of Aec_Ip_Irq.c and Aec_Ip_Hw_Access.h are different"
#endif
#if ((AEC_IP_IRQ_SW_MAJOR_VERSION_C != AEC_IP_HW_ACCESS_SW_MAJOR_VERSION) || \
     (AEC_IP_IRQ_SW_MINOR_VERSION_C != AEC_IP_HW_ACCESS_SW_MINOR_VERSION) || \
     (AEC_IP_IRQ_SW_PATCH_VERSION_C != AEC_IP_HW_ACCESS_SW_PATCH_VERSION))
    #error "Software Version Numbers of Aec_Ip_Irq.c and Aec_Ip_Hw_Access.h are different"
#endif

/* Checks against Aec_Ip_Irq.h */
#if (AEC_IP_IRQ_VENDOR_ID_C != AEC_IP_IRQ_VENDOR_ID)
    #error "Aec_Ip_Irq.c and Aec_Ip_Irq.h have different vendor ids"
#endif
#if ((AEC_IP_IRQ_AR_RELEASE_MAJOR_VERSION_C    != AEC_IP_IRQ_AR_RELEASE_MAJOR_VERSION) || \
     (AEC_IP_IRQ_AR_RELEASE_MINOR_VERSION_C    != AEC_IP_IRQ_AR_RELEASE_MINOR_VERSION) || \
     (AEC_IP_IRQ_AR_RELEASE_REVISION_VERSION_C != AEC_IP_IRQ_AR_RELEASE_REVISION_VERSION))
     #error "AUTOSAR Version Numbers of Aec_Ip_Irq.c and Aec_Ip_Irq.h are different"
#endif
#if ((AEC_IP_IRQ_SW_MAJOR_VERSION_C != AEC_IP_IRQ_SW_MAJOR_VERSION) || \
     (AEC_IP_IRQ_SW_MINOR_VERSION_C != AEC_IP_IRQ_SW_MINOR_VERSION) || \
     (AEC_IP_IRQ_SW_PATCH_VERSION_C != AEC_IP_IRQ_SW_PATCH_VERSION))
    #error "Software Version Numbers of Aec_Ip_Irq.c and Aec_Ip_Irq.h are different"
#endif

/*******************************************************************************
 * Code
 ******************************************************************************/
#define AE_START_SEC_CODE
#include "Ae_MemMap.h"

ISR(AEC_Common_IRQHandler)
{
    AEC_IRQEventFaultHandler();
}

#define AE_STOP_SEC_CODE
#include "Ae_MemMap.h"


#ifdef __cplusplus
}
#endif
/** @} */

