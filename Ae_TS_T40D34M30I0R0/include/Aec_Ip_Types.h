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

#ifndef AEC_IP_TYPES_H
#define AEC_IP_TYPES_H

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
#include "Mcal.h"
#include "Aec_Ip_Cfg_Defines.h"
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define AEC_IP_TYPES_VENDOR_ID                      43
#define AEC_IP_TYPES_AR_RELEASE_MAJOR_VERSION       4
#define AEC_IP_TYPES_AR_RELEASE_MINOR_VERSION       7
#define AEC_IP_TYPES_AR_RELEASE_REVISION_VERSION    0
#define AEC_IP_TYPES_SW_MAJOR_VERSION               3
#define AEC_IP_TYPES_SW_MINOR_VERSION               0
#define AEC_IP_TYPES_SW_PATCH_VERSION               0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Checks against Aec_Ip_Cfg_Defines.h */
#if (AEC_IP_TYPES_VENDOR_ID != AEC_IP_CFG_DEFINES_VENDOR_ID)
    #error "Aec_Ip_Types.h and Aec_Ip_Cfg_Defines.h have different vendor ids"
#endif
#if ((AEC_IP_TYPES_AR_RELEASE_MAJOR_VERSION    != AEC_IP_CFG_DEFINES_AR_RELEASE_MAJOR_VERSION) || \
     (AEC_IP_TYPES_AR_RELEASE_MINOR_VERSION    != AEC_IP_CFG_DEFINES_AR_RELEASE_MINOR_VERSION) || \
     (AEC_IP_TYPES_AR_RELEASE_REVISION_VERSION != AEC_IP_CFG_DEFINES_AR_RELEASE_REVISION_VERSION))
     #error "AUTOSAR Version Numbers of Aec_Ip_Types.h and Aec_Ip_Cfg_Defines.h are different"
#endif
#if ((AEC_IP_TYPES_SW_MAJOR_VERSION != AEC_IP_CFG_DEFINES_SW_MAJOR_VERSION) || \
     (AEC_IP_TYPES_SW_MINOR_VERSION != AEC_IP_CFG_DEFINES_SW_MINOR_VERSION) || \
     (AEC_IP_TYPES_SW_PATCH_VERSION != AEC_IP_CFG_DEFINES_SW_PATCH_VERSION))
    #error "Software Version Numbers of Aec_Ip_Types.h and Aec_Ip_Cfg_Defines.h are different"
#endif
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Checks against Mcal.h */
    #if ((AEC_IP_TYPES_AR_RELEASE_MAJOR_VERSION != MCAL_AR_RELEASE_MAJOR_VERSION) || \
         (AEC_IP_TYPES_AR_RELEASE_MINOR_VERSION != MCAL_AR_RELEASE_MINOR_VERSION))
        #error "AUTOSAR Version Numbers of Aec_Ip_Types.h and Mcal.h are different"
    #endif
#endif
/*******************************************************************************
 * Definitions
 ******************************************************************************/
/*!
 * @brief SPI configuration for access
 * Implements : Aec_Ip_SpiConfigType_Class
 */
typedef struct Aec_Ip_sSpiConfigType
{
    boolean SyncTransmit;   /* SPI sync/async transmission */
    uint32 Timeout;
    const void *Extension;
} Aec_Ip_SpiConfigType;

typedef enum
{
    /* Generic error codes */
    AEC_STATUS_SUCCESS                    = 0x000U,   /*!< Generic operation success status */
    AEC_STATUS_ERROR                      = 0x001U,   /*!< Generic operation failure status */
    AEC_STATUS_TIMEOUT                    = 0x002U    /*!< Generic operation timeout status */

} Aec_Ip_StatusType;

/**
* @brief          Interrupt handler type.
* @implements     Aec_Ip_IntHandlerType_typedef
*/
typedef void (*Aec_Ip_IntHandlerType)(void);

/**
* @brief          Structure storing the routing and handler configuration for an interrupt request.
* @implements     Aec_Ip_IntRouteConfigType_typedef
*/
typedef struct Aec_Ip_sIntRouteConfigType
{
	/** @brief Name of event/fault */
	uint16 IsrMask;
	/** @brief Priority for event/fault */
	uint8 IsrPriority;
    /** @brief Interrupt handler */
    Aec_Ip_IntHandlerType pfHandler;
    
} Aec_Ip_IntRouteConfigType;

#ifdef __cplusplus
}
#endif

/** @} */

#endif /* AEC_IP_TYPES_H */
