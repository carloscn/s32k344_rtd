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
 
#ifndef AEC_IP_IRQ_H
#define AEC_IP_IRQ_H

/**
*   @file
*
*   @addtogroup AEC_DRIVER AEC Driver
*   @{
*/

#ifdef __cplusplus
extern "C" {
#endif
 
/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "OsIf.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define AEC_IP_IRQ_VENDOR_ID                      43
#define AEC_IP_IRQ_AR_RELEASE_MAJOR_VERSION       4
#define AEC_IP_IRQ_AR_RELEASE_MINOR_VERSION       7
#define AEC_IP_IRQ_AR_RELEASE_REVISION_VERSION    0
#define AEC_IP_IRQ_SW_MAJOR_VERSION               3
#define AEC_IP_IRQ_SW_MINOR_VERSION               0
#define AEC_IP_IRQ_SW_PATCH_VERSION               0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Checks against OsIf.h */
    #if (( AEC_IP_IRQ_AR_RELEASE_MAJOR_VERSION      != OSIF_AR_RELEASE_MAJOR_VERSION) || \
        ( AEC_IP_IRQ_AR_RELEASE_MINOR_VERSION       != OSIF_AR_RELEASE_MINOR_VERSION))
        #error "AUTOSAR Version Numbers of Aec_Ip_Irq.h and OsIf.h are different"
    #endif
#endif


/*******************************************************************************
 * API
 ******************************************************************************/
#define AE_START_SEC_CODE
#include "Ae_MemMap.h"

ISR(AEC_Common_IRQHandler);

#define AE_STOP_SEC_CODE
#include "Ae_MemMap.h"


#ifdef __cplusplus
}
#endif

/** @} */

#endif /* AEC_IP_IRQ_H */
