/*==================================================================================================
*   Project              : RTD AUTOSAR 4.7
*   Platform             : CORTEXM
*   Peripheral           : DPGA
*   Dependencies         : none
*
*   Autosar Version      : 4.7.0
*   Autosar Revision     : ASR_REL_4_7_REV_0000
*   Autosar Conf.Variant :
*   SW Version           : 3.0.0
*   Build Version        : S32K3_RTD_3_0_0_D2303_ASR_REL_4_7_REV_0000_20230331
*
*   Copyright 2022 NXP
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
*   @addtogroup dpga_ip
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
#include "Dpga_Ip.h"

/*==================================================================================================
*                                 SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define DPGA_IP_VENDOR_ID_ISR_C                      43
#define DPGA_IP_AR_RELEASE_MAJOR_VERSION_ISR_C       4
#define DPGA_IP_AR_RELEASE_MINOR_VERSION_ISR_C       7
#define DPGA_IP_AR_RELEASE_REVISION_VERSION_ISR_C    0
#define DPGA_IP_SW_MAJOR_VERSION_ISR_C               3
#define DPGA_IP_SW_MINOR_VERSION_ISR_C               0
#define DPGA_IP_SW_PATCH_VERSION_ISR_C               0

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and Dpga_Ip header file are of the same vendor */
#if (DPGA_IP_VENDOR_ID_ISR_C != DPGA_IP_VENDOR_ID)
    #error "Dpga_Ip_Isr.c and Dpga_Ip.h have different vendor ids"
#endif

/* Check if current file and Dpga_Ip header file are of the same Autosar version */
#if ((DPGA_IP_AR_RELEASE_MAJOR_VERSION_ISR_C     != DPGA_IP_AR_RELEASE_MAJOR_VERSION) || \
     (DPGA_IP_AR_RELEASE_MINOR_VERSION_ISR_C     != DPGA_IP_AR_RELEASE_MINOR_VERSION) || \
     (DPGA_IP_AR_RELEASE_REVISION_VERSION_ISR_C  != DPGA_IP_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Dpga_Ip_Isr.c and Dpga_Ip.h are different"
#endif

/* Check if current file and Dpga_Ip header file are of the same software version */
#if ((DPGA_IP_SW_MAJOR_VERSION_ISR_C != DPGA_IP_SW_MAJOR_VERSION) || \
     (DPGA_IP_SW_MINOR_VERSION_ISR_C != DPGA_IP_SW_MINOR_VERSION) || \
     (DPGA_IP_SW_PATCH_VERSION_ISR_C != DPGA_IP_SW_PATCH_VERSION))
    #error "Software Version Numbers of Dpga_Ip_Isr.c and Dpga_Ip.h are different"
#endif

/*==================================================================================================
*                                           CODE
==================================================================================================*/
#define DPGA_START_SEC_CODE
#include "Dpga_MemMap.h"

extern Dpga_Ip_StatusType Dpga_Ip_IRQHandler(const uint8 Instance);

ISR(Dpga_Isr);
/* Implementation of Dpga IRQ Handler */
ISR(Dpga_Isr)
{
    (void)Dpga_Ip_IRQHandler(0U);
}

#define DPGA_STOP_SEC_CODE
#include "Dpga_MemMap.h"


#ifdef __cplusplus
}
#endif

/** @} */
