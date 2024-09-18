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

#ifndef DPGA_IP_H
#define DPGA_IP_H

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
#include "Dpga_Ip_Cfg.h"
#include "Dpga_Ip_Types.h"
#include "Aec_Ip.h"

/*==================================================================================================
*                                 SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define DPGA_IP_VENDOR_ID                    43
#define DPGA_IP_MODULE_ID                    255
#define DPGA_IP_AR_RELEASE_MAJOR_VERSION     4
#define DPGA_IP_AR_RELEASE_MINOR_VERSION     7
#define DPGA_IP_AR_RELEASE_REVISION_VERSION  0
#define DPGA_IP_SW_MAJOR_VERSION             3
#define DPGA_IP_SW_MINOR_VERSION             0
#define DPGA_IP_SW_PATCH_VERSION             0

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and Dpga_Ip_Cfg header file are of the same vendor */
#if (DPGA_IP_VENDOR_ID != DPGA_IP_VENDOR_ID_CFG)
    #error "Dpga_Ip.h and Dpga_Ip_Cfg.h have different vendor ids"
#endif

/* Check if current file and Dpga_Ip_Cfg header file are of the same Autosar version */
#if ((DPGA_IP_AR_RELEASE_MAJOR_VERSION     != DPGA_IP_AR_RELEASE_MAJOR_VERSION_CFG) || \
     (DPGA_IP_AR_RELEASE_MINOR_VERSION     != DPGA_IP_AR_RELEASE_MINOR_VERSION_CFG) || \
     (DPGA_IP_AR_RELEASE_REVISION_VERSION  != DPGA_IP_AR_RELEASE_REVISION_VERSION_CFG))
    #error "AutoSar Version Numbers of Dpga_Ip.h and Dpga_Ip_Cfg.h are different"
#endif

/* Check if current file and Dpga_Ip_Cfg header file are of the same software version */
#if ((DPGA_IP_SW_MAJOR_VERSION != DPGA_IP_SW_MAJOR_VERSION_CFG) || \
     (DPGA_IP_SW_MINOR_VERSION != DPGA_IP_SW_MINOR_VERSION_CFG) || \
     (DPGA_IP_SW_PATCH_VERSION != DPGA_IP_SW_PATCH_VERSION_CFG))
    #error "Software Version Numbers of Dpga_Ip.h and Dpga_Ip_Cfg.h are different"
#endif

/* Check if current file and Dpga_Ip_Types header file are of the same vendor */
#if (DPGA_IP_VENDOR_ID != DPGA_IP_VENDOR_ID_TYPES)
    #error "Dpga_Ip.h and Dpga_Ip_Types.h have different vendor ids"
#endif

/* Check if current file and Dpga_Ip_Types header file are of the same Autosar version */
#if ((DPGA_IP_AR_RELEASE_MAJOR_VERSION     != DPGA_IP_AR_RELEASE_MAJOR_VERSION_TYPES) || \
     (DPGA_IP_AR_RELEASE_MINOR_VERSION     != DPGA_IP_AR_RELEASE_MINOR_VERSION_TYPES) || \
     (DPGA_IP_AR_RELEASE_REVISION_VERSION  != DPGA_IP_AR_RELEASE_REVISION_VERSION_TYPES))
    #error "AutoSar Version Numbers of Dpga_Ip.h and Dpga_Ip_Types.h are different"
#endif

/* Check if current file and Dpga_Ip_Types header file are of the same software version */
#if ((DPGA_IP_SW_MAJOR_VERSION != DPGA_IP_SW_MAJOR_VERSION_TYPES) || \
     (DPGA_IP_SW_MINOR_VERSION != DPGA_IP_SW_MINOR_VERSION_TYPES) || \
     (DPGA_IP_SW_PATCH_VERSION != DPGA_IP_SW_PATCH_VERSION_TYPES))
    #error "Software Version Numbers of Dpga_Ip.h and Dpga_Ip_Types.h are different"
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

/*==================================================================================================
*                                       FUNCTION PROTOTYPES
==================================================================================================*/
#define DPGA_START_SEC_CODE
#include "Dpga_MemMap.h"

/**
* @brief   Initialize the DPGA module.
*
* @details This function initializes the DPGA module.
*
* @param[in] Instance  DPGA instance
* @param[in] Config    Pointer to the configuration structure
*
*/
Dpga_Ip_StatusType Dpga_Ip_Init(const uint8 Instance,
                                const Dpga_Ip_ConfigType * const Config);

/**
* @brief   Deinitialize the DPGA module.
*
* @details This function deinitializes the DPGA module. The driver can't be used until initialized again.
*
* @param[in] Instance  DPGA instance
*
*/
Dpga_Ip_StatusType Dpga_Ip_DeInit(const uint8 Instance);

/**
* @brief   Reload Amplifier configuration.
*
* @details This function is used to configure the Amplifier at runtime.
*          The user can store specific configuration values after device power up
*          and reload them after each device reset.
*
* @param[in] Instance           DPGA instance
* @param[in] AmplifierConfig    Pointer to the Amplifier configuration structure
*
*/
Dpga_Ip_StatusType Dpga_Ip_ConfigureAmplifier(const uint8 Instance,
                                              const Dpga_Ip_AmplifierConfigType * AmplifierConfig);
/**
* @brief   Handle DPGA interrupt.
*
* @details This function handles DPGA interrupt events.
*
* @param[in] Instance           DPGA instance
*/
Dpga_Ip_StatusType Dpga_Ip_IRQHandler(const uint8 Instance);

#define DPGA_STOP_SEC_CODE
#include "Dpga_MemMap.h"


#ifdef __cplusplus
}
#endif

/** @} */

#endif /* DPGA_IP_H */
