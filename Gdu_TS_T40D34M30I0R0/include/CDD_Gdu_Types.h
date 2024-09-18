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

#ifndef CDD_GDU_TYPES_H
#define CDD_GDU_TYPES_H

/**
*   @file    CDD_Gdu_Types.h
*   @version 3.0.0
*
*   @brief   AUTOSAR Gdu - this file contains the type definitions.
*
*   @addtogroup CDD_GDU
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
#include "StandardTypes.h"
#include "Gdu_Ip_Types.h"
#include "CDD_Gdu_CfgDefines.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define GDU_TYPES_VENDOR_ID                    43
#define GDU_TYPES_MODULE_ID                    123
#define GDU_TYPES_AR_RELEASE_MAJOR_VERSION     4
#define GDU_TYPES_AR_RELEASE_MINOR_VERSION     7
#define GDU_TYPES_AR_RELEASE_REVISION_VERSION  0
#define GDU_TYPES_SW_MAJOR_VERSION             3
#define GDU_TYPES_SW_MINOR_VERSION             0
#define GDU_TYPES_SW_PATCH_VERSION             0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if current file and StandardTypes.h header file are of the same Autosar version */
    #if ((GDU_TYPES_AR_RELEASE_MAJOR_VERSION != STD_AR_RELEASE_MAJOR_VERSION) || \
         (GDU_TYPES_AR_RELEASE_MINOR_VERSION != STD_AR_RELEASE_MINOR_VERSION) \
        )
        #error "Autosar Version Numbers of Gdu_Ip_Types.h and StandardTypes.h are different"
    #endif
#endif

#if (GDU_TYPES_VENDOR_ID != GDU_IP_TYPES_VENDOR_ID)
#error "CDD_Gdu_Types.h and Gdu_Ip_Types.h have different vendor ids"
#endif
#if ((GDU_TYPES_AR_RELEASE_MAJOR_VERSION    != GDU_IP_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (GDU_TYPES_AR_RELEASE_MINOR_VERSION    != GDU_IP_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (GDU_TYPES_AR_RELEASE_REVISION_VERSION != GDU_IP_TYPES_AR_RELEASE_REVISION_VERSION))
#error "AutoSar Version Numbers of CDD_Gdu_Types.h and Gdu_Ip_Types.h are different"
#endif
#if ((GDU_TYPES_SW_MAJOR_VERSION != GDU_IP_TYPES_SW_MAJOR_VERSION) || \
     (GDU_TYPES_SW_MINOR_VERSION != GDU_IP_TYPES_SW_MINOR_VERSION) || \
     (GDU_TYPES_SW_PATCH_VERSION != GDU_IP_TYPES_SW_PATCH_VERSION))
#error "Software Version Numbers of CDD_Gdu_Types.h and Gdu_Ip_Types.h are different"
#endif

#if ((GDU_TYPES_AR_RELEASE_MAJOR_VERSION != GDU_CFGDEFINES_AR_RELEASE_MAJOR_VERSION) || \
     (GDU_TYPES_AR_RELEASE_MINOR_VERSION != GDU_CFGDEFINES_AR_RELEASE_MINOR_VERSION) || \
     (GDU_TYPES_AR_RELEASE_REVISION_VERSION != GDU_CFGDEFINES_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of CDD_Gdu_Types.h and CDD_Gdu_CfgDefines.h are different"
#endif
#if ((GDU_TYPES_SW_MAJOR_VERSION != GDU_CFGDEFINES_SW_MAJOR_VERSION) || \
     (GDU_TYPES_SW_MINOR_VERSION != GDU_CFGDEFINES_SW_MINOR_VERSION) || \
     (GDU_TYPES_SW_PATCH_VERSION != GDU_CFGDEFINES_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of CDD_Gdu_Types.h and CDD_Gdu_CfgDefines.h are different"
#endif
#if (GDU_TYPES_VENDOR_ID != GDU_CFGDEFINES_VENDOR_ID)
    #error "CDD_Gdu_Types.h and CDD_Gdu_CfgDefines.h have different vendor ids"
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

#ifdef __cplusplus
}
#endif

/** @} */

#endif /* CDD_GDU_TYPES_H */
