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

/* Prevention from multiple including the same header */
#ifndef ZIPWIRE_IP_DEVASSERT_H
#define ZIPWIRE_IP_DEVASSERT_H

/**
*   @file    Zipwire_Ip_DevAssert.h
*
*   @version 3.0.0
*
*   @brief   AUTOSAR Zipwire - Zipwire Ip driver header file.
*   @details
*
*   @addtogroup ZIPWIRE_IP_DRIVER
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
#include "Mcal.h"
#include "Zipwire_Ip_Types.h"

/*==================================================================================================
                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @brief Parameters that shall be published within the standard types header file and also in the
*        module's description file
*/
#define ZIPWIRE_IP_DEVASSERT_VENDOR_ID                     43
#define ZIPWIRE_IP_DEVASSERT_AR_RELEASE_MAJOR_VERSION      4
#define ZIPWIRE_IP_DEVASSERT_AR_RELEASE_MINOR_VERSION      7
#define ZIPWIRE_IP_DEVASSERT_AR_RELEASE_REVISION_VERSION   0
#define ZIPWIRE_IP_DEVASSERT_SW_MAJOR_VERSION              3
#define ZIPWIRE_IP_DEVASSERT_SW_MINOR_VERSION              0
#define ZIPWIRE_IP_DEVASSERT_SW_PATCH_VERSION              0

/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
/* Check if source file and Mcal header file are of the same Autosar version */
#if ((ZIPWIRE_IP_DEVASSERT_AR_RELEASE_MAJOR_VERSION != MCAL_AR_RELEASE_MAJOR_VERSION) || \
    (ZIPWIRE_IP_DEVASSERT_AR_RELEASE_MINOR_VERSION  != MCAL_AR_RELEASE_MINOR_VERSION))
    #error "AutoSar Version Numbers of Zipwire_Ip_DevAssert.h and Mcal header are different"
#endif
#endif

/* Check if source file and Zipwire header file are of the same vendor */
#if (ZIPWIRE_IP_DEVASSERT_VENDOR_ID != ZIPWIRE_IP_TYPES_VENDOR_ID)
    #error "Zipwire_Ip_DevAssert.h and Zipwire_Ip_Types have different vendor ids"
#endif

/* Check if source file and Zipwire header file are of the same Autosar version */
#if ((ZIPWIRE_IP_DEVASSERT_AR_RELEASE_MAJOR_VERSION    != ZIPWIRE_IP_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (ZIPWIRE_IP_DEVASSERT_AR_RELEASE_MINOR_VERSION    != ZIPWIRE_IP_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (ZIPWIRE_IP_DEVASSERT_AR_RELEASE_REVISION_VERSION != ZIPWIRE_IP_TYPES_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Zipwire_Ip_DevAssert.h and Zipwire_Ip_Types are different"
#endif

/* Check if source file and Zipwire header file are of the same Software version */
#if ((ZIPWIRE_IP_DEVASSERT_SW_MAJOR_VERSION != ZIPWIRE_IP_TYPES_SW_MAJOR_VERSION) || \
     (ZIPWIRE_IP_DEVASSERT_SW_MINOR_VERSION != ZIPWIRE_IP_TYPES_SW_MINOR_VERSION) || \
     (ZIPWIRE_IP_DEVASSERT_SW_PATCH_VERSION != ZIPWIRE_IP_TYPES_SW_PATCH_VERSION)    \
    )
    #error "Software Version Numbers of Zipwire_Ip_DevAssert.h and Zipwire_Ip_Types are different"
#endif

/*==================================================================================================
                                           TYPEDEF
==================================================================================================*/
#define ZIPWIRE_START_SEC_CODE
#include "Zipwire_MemMap.h"

#if (STD_ON == ZIPWIRE_IP_DEV_ERROR_DETECT)
    /* Implement default assert macro */
    static inline void Zipwire_Ip_DevAssert(volatile boolean x)
    {
        if (x) { } else { for (;;) {} }
    }
    #define ZIPWIRE_IP_DEV_ASSERT(x) Zipwire_Ip_DevAssert(x)
#else
    /* Assert macro does nothing */
    #define ZIPWIRE_IP_DEV_ASSERT(x) ((void)0)
#endif /* #if (STD_ON == ZIPWIRE_IP_DEV_ERROR_DETECT) */

#define ZIPWIRE_STOP_SEC_CODE
#include "Zipwire_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */

#endif  /* #ifndef ZIPWIRE_IP_DEVASSERT_H */
