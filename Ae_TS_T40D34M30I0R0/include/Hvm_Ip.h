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

#ifndef HVM_IP_H
#define HVM_IP_H

/**
*   @file
*
*   @addtogroup HVM_DRIVER HVM Driver
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
#include "Hvm_Ip_Types.h"
#include "Hvm_Ip_Cfg.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define HVM_IP_VENDOR_ID                      43
#define HVM_IP_AR_RELEASE_MAJOR_VERSION       4
#define HVM_IP_AR_RELEASE_MINOR_VERSION       7
#define HVM_IP_AR_RELEASE_REVISION_VERSION    0
#define HVM_IP_SW_MAJOR_VERSION               3
#define HVM_IP_SW_MINOR_VERSION               0
#define HVM_IP_SW_PATCH_VERSION               0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Checks against Hvm_Ip_Types.h */
#if (HVM_IP_VENDOR_ID != HVM_IP_TYPES_VENDOR_ID)
    #error "Hvm_Ip.h and Hvm_Ip_Types.h have different vendor ids"
#endif
#if (( HVM_IP_AR_RELEASE_MAJOR_VERSION    != HVM_IP_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     ( HVM_IP_AR_RELEASE_MINOR_VERSION    != HVM_IP_TYPES_AR_RELEASE_MINOR_VERSION) || \
     ( HVM_IP_AR_RELEASE_REVISION_VERSION != HVM_IP_TYPES_AR_RELEASE_REVISION_VERSION))
     #error "AUTOSAR Version Numbers of Hvm_Ip.h and Hvm_Ip_Types.h are different"
#endif
#if (( HVM_IP_SW_MAJOR_VERSION != HVM_IP_TYPES_SW_MAJOR_VERSION) || \
     ( HVM_IP_SW_MINOR_VERSION != HVM_IP_TYPES_SW_MINOR_VERSION) || \
     ( HVM_IP_SW_PATCH_VERSION != HVM_IP_TYPES_SW_PATCH_VERSION))
    #error "Software Version Numbers of Hvm_Ip.h and Hvm_Ip_Types.h are different"
#endif

/* Checks against Hvm_Ip_Cfg.h */
#if (HVM_IP_VENDOR_ID != HVM_IP_CFG_VENDOR_ID)
    #error "Hvm_Ip.h and Hvm_Ip_Cfg.h have different vendor ids"
#endif
#if (( HVM_IP_AR_RELEASE_MAJOR_VERSION    != HVM_IP_CFG_AR_RELEASE_MAJOR_VERSION) || \
     ( HVM_IP_AR_RELEASE_MINOR_VERSION    != HVM_IP_CFG_AR_RELEASE_MINOR_VERSION) || \
     ( HVM_IP_AR_RELEASE_REVISION_VERSION != HVM_IP_CFG_AR_RELEASE_REVISION_VERSION))
     #error "AUTOSAR Version Numbers of Hvm_Ip.h and Hvm_Ip_Cfg.h are different"
#endif
#if (( HVM_IP_SW_MAJOR_VERSION != HVM_IP_CFG_SW_MAJOR_VERSION) || \
     ( HVM_IP_SW_MINOR_VERSION != HVM_IP_CFG_SW_MINOR_VERSION) || \
     ( HVM_IP_SW_PATCH_VERSION != HVM_IP_CFG_SW_PATCH_VERSION))
    #error "Software Version Numbers of Hvm_Ip.h and Hvm_Ip_Cfg.h are different"
#endif

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/*******************************************************************************
 * GLOBAL VARIABLE DECLARATIONS
 ******************************************************************************/
#define AE_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Ae_MemMap.h"

HVM_CONFIG_EXT

#define AE_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Ae_MemMap.h"

#define AE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Ae_MemMap.h"

extern Hvm_Ip_ReportEventCallbackType Hvm_Ip_pfReportCallback;

#define AE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Ae_MemMap.h"

/*******************************************************************************
 * API
 ******************************************************************************/
#define AE_START_SEC_CODE
#include "Ae_MemMap.h"

/**
* @brief         Initializes the Hvm Driver
* @details       The configuration pointer is internally stored and
*                the driver is initialized.
* 
* @param[in]     HvmConfig Pointer to the module configuration structure
*
* @retval        HVM_STATUS_SUCCESS The initialization was successful.
*
*/
Hvm_Ip_StatusType  Hvm_Ip_Init(const Hvm_Ip_ConfigType *pHvmConfig);

/**
* @brief         Initializes the configuration for analog input for measurement.
* @details       Base on configuration to select analog input, HVI channel, divider if high voltage input selected.
*
* @param[in]     pHviHighVoltConfig Pointer to configuration for High Voltage Input.
*                AnalogInputSelect Type of analog input.
*
* @retval        HVM_STATUS_SUCCESS The initialization was successful.
*/
Hvm_Ip_StatusType  Hvm_Ip_AdcMeasureConfig(const Ae_HviHighVoltageInputConfig *pHviHighVoltConfig,
                                           Ae_AnalogInputType AnalogInputSelect
                                           );

/**
* @brief         Initializes the configuration for digital input.
* @details       Initializes the configuration for digital input include: voltage input source, divider, mode polling or interrupt used.
*
* @param[in]     pHviConfig HVI channels configuration.
*
* @retval        HVM_STATUS_SUCCESS The initialization was successful.
*/                          
Hvm_Ip_StatusType  Hvm_Ip_DigitalInputEventConfig(const Ae_HviChannelConfig *pHviConfig);

/**
* @brief         Initializes the configuration for Voltage Monitor.
* @details       Initializes the configuration for High/Low voltage detect.
*
* @param[in]     pAeVmConfig       Pointer to configuration of VM.
* @param[in]     pHighVoltageInput Pointer to configuration of High Voltage Input.
*
* @retval        HVM_STATUS_SUCCESS The initialization was successful.
*/
Hvm_Ip_StatusType  Hvm_Ip_VoltageMonitorConfig(const Ae_VmConfig *pAeVmConfig,
                                               const Ae_HviHighVoltageInputConfig *pHighVoltageInput
                                              );

/**
* @brief         Check status flag used in polling mode.
* @details       This function used to read status flag for digital input, high voltage, low voltage detect.
*
*/
void Hvm_Ip_ReadFaultsEventsStatus(void);
/**
* @brief         Check and clear interrupt flag used in interrupt mode.
* @details       Check interrupt flag, clear flag if event (digital input, high voltage, low voltage detected) occured.
*
*/
void Hvm_Ip_FaultsEventsProccess(void);
                               
#define AE_STOP_SEC_CODE
#include "Ae_MemMap.h"


#ifdef __cplusplus
}
#endif

/** @} */

#endif /* HVM_IP_H */

