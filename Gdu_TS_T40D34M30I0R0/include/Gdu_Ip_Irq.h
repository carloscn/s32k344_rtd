/*==================================================================================================
*   Project              : RTD AUTOSAR 4.7
*   Platform             : CORTEXM
*   Peripheral           : IPV_GDU
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

#ifndef GDU_IP_IRQ_H
#define GDU_IP_IRQ_H

/**
*   @file    Gdu_Ip_Irq.h
*   @version 3.0.0
*
*   @brief   AUTOSAR Gdu - header file for the interrupt handling part.
*
*   @addtogroup IPV_GDU
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
#include "Gdu_Ip.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define GDU_IP_IRQ_VENDOR_ID                    43
#define GDU_IP_IRQ_MODULE_ID                    123
#define GDU_IP_IRQ_AR_RELEASE_MAJOR_VERSION     4
#define GDU_IP_IRQ_AR_RELEASE_MINOR_VERSION     7
#define GDU_IP_IRQ_AR_RELEASE_REVISION_VERSION  0
#define GDU_IP_IRQ_SW_MAJOR_VERSION             3
#define GDU_IP_IRQ_SW_MINOR_VERSION             0
#define GDU_IP_IRQ_SW_PATCH_VERSION             0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
#if (GDU_IP_IRQ_VENDOR_ID != GDU_IP_VENDOR_ID)
#error "Gdu_Ip_Irq.h and Gdu_Ip.h have different vendor ids"
#endif
#if ((GDU_IP_IRQ_AR_RELEASE_MAJOR_VERSION    != GDU_IP_AR_RELEASE_MAJOR_VERSION) || \
     (GDU_IP_IRQ_AR_RELEASE_MINOR_VERSION    != GDU_IP_AR_RELEASE_MINOR_VERSION) || \
     (GDU_IP_IRQ_AR_RELEASE_REVISION_VERSION != GDU_IP_AR_RELEASE_REVISION_VERSION))
#error "AutoSar Version Numbers of Gdu_Ip_Irq.h and Gdu_Ip.h are different"
#endif
#if ((GDU_IP_IRQ_SW_MAJOR_VERSION != GDU_IP_SW_MAJOR_VERSION) || \
     (GDU_IP_IRQ_SW_MINOR_VERSION != GDU_IP_SW_MINOR_VERSION) || \
     (GDU_IP_IRQ_SW_PATCH_VERSION != GDU_IP_SW_PATCH_VERSION))
#error "Software Version Numbers of Gdu_Ip_Irq.h and Gdu_Ip.h are different"
#endif

/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/

/*==================================================================================================
*                                             ENUMS
==================================================================================================*/

/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/
#define GDU_START_SEC_CODE
#include "Gdu_MemMap.h"

/** * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
* @brief        ISR for GDU_INT.
* @details      Simply call Gdu_Ip_ISR and handle everything from there.
*
* @pre
* @implements   TODO
* @api
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
ISR(Gdu_Ip_Irq_ISR);

#define GDU_STOP_SEC_CODE
#include "Gdu_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */

#endif /* GDU_IP_IRQ_H */
