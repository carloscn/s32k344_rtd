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
#ifndef ZIPWIRE_CFG_H
#define ZIPWIRE_CFG_H

/**
*   @file    Zipwire_Cfg.h
*
*   @version 3.0.0
*
*   @brief   AUTOSAR Zipwire - Zipwire driver source file.
*   @details
*
*   @defgroup ZIPWIRE_HLD_DRIVER ZIPWIRE HLD Driver
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
#include "Zipwire_Types.h"
#include "Zipwire_Ip_Cfg.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define ZIPWIRE_CFG_VENDOR_ID                      43
#define ZIPWIRE_CFG_AR_RELEASE_MAJOR_VERSION       4
#define ZIPWIRE_CFG_AR_RELEASE_MINOR_VERSION       7
#define ZIPWIRE_CFG_AR_RELEASE_REVISION_VERSION    0
#define ZIPWIRE_CFG_SW_MAJOR_VERSION               3
#define ZIPWIRE_CFG_SW_MINOR_VERSION               0
#define ZIPWIRE_CFG_SW_PATCH_VERSION               0

/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/
/* Check if header file and Zipwire_Types.h file are of the same vendor */
#if (ZIPWIRE_CFG_VENDOR_ID != ZIPWIRE_TYPES_VENDOR_ID)
    #error "Zipwire_Cfg.h and Zipwire_Types.h have different vendor ids"
#endif

/* Check if header file and Zipwire_Types.h file are of the same Autosar version */
#if ((ZIPWIRE_CFG_AR_RELEASE_MAJOR_VERSION != ZIPWIRE_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (ZIPWIRE_CFG_AR_RELEASE_MINOR_VERSION != ZIPWIRE_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (ZIPWIRE_CFG_AR_RELEASE_REVISION_VERSION != ZIPWIRE_TYPES_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Zipwire_Cfg.h and Zipwire_Types.h are different"
#endif

/* Check if header file and Zipwire_Types.h file are of the same Software version */
#if ((ZIPWIRE_CFG_SW_MAJOR_VERSION != ZIPWIRE_TYPES_SW_MAJOR_VERSION) || \
     (ZIPWIRE_CFG_SW_MINOR_VERSION != ZIPWIRE_TYPES_SW_MINOR_VERSION) || \
     (ZIPWIRE_CFG_SW_PATCH_VERSION != ZIPWIRE_TYPES_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Zipwire_Cfg.h and Zipwire_Types.h are different"
#endif

/* Check if header file and Zipwire_Ip_Cfg.h file are of the same vendor */
#if (ZIPWIRE_CFG_VENDOR_ID != ZIPWIRE_IP_CFG_VENDOR_ID)
    #error "Zipwire_Cfg.h and Zipwire_Ip_Cfg.h have different vendor ids"
#endif

/* Check if header file and Zipwire_Ip_Cfg.h file are of the same Autosar version */
#if ((ZIPWIRE_CFG_AR_RELEASE_MAJOR_VERSION != ZIPWIRE_IP_CFG_AR_RELEASE_MAJOR_VERSION) || \
     (ZIPWIRE_CFG_AR_RELEASE_MINOR_VERSION != ZIPWIRE_IP_CFG_AR_RELEASE_MINOR_VERSION) || \
     (ZIPWIRE_CFG_AR_RELEASE_REVISION_VERSION != ZIPWIRE_IP_CFG_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Zipwire_Cfg.h and Zipwire_Ip_Cfg.h are different"
#endif

/* Check if header file and Zipwire_Ip_Cfg.h file are of the same Software version */
#if ((ZIPWIRE_CFG_SW_MAJOR_VERSION != ZIPWIRE_IP_CFG_SW_MAJOR_VERSION) || \
     (ZIPWIRE_CFG_SW_MINOR_VERSION != ZIPWIRE_IP_CFG_SW_MINOR_VERSION) || \
     (ZIPWIRE_CFG_SW_PATCH_VERSION != ZIPWIRE_IP_CFG_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Zipwire_Cfg.h and Zipwire_Ip_Cfg.h are different"
#endif
/*==================================================================================================
*                                            CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/

/*==================================================================================================
*                                              ENUMS
==================================================================================================*/

/*==================================================================================================
*                                  STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
*                                  GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/
#define ZIPWIRE_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Zipwire_MemMap.h"

/* Configure ZIPWIRE driver initialization */
extern const Zipwire_InitType Zipwire_xConfigInit;

#define ZIPWIRE_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Zipwire_MemMap.h"


/*==================================================================================================
*                                       FUNCTION PROTOTYPES
==================================================================================================*/


#ifdef __cplusplus
}
#endif

/** @} */

#endif /* ZIPWIRE_CFG_H */
