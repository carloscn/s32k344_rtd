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

#ifndef DPGA_H
#define DPGA_H

/**
*   @file
*
*   @addtogroup dpga
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
#include "CDD_Dpga_Cfg.h"
#include "CDD_Dpga_Types.h"
#include "Dpga_Ip.h"

/*==================================================================================================
*                                 SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define DPGA_VENDOR_ID                    43
#define DPGA_MODULE_ID                    255
#define DPGA_AR_RELEASE_MAJOR_VERSION     4
#define DPGA_AR_RELEASE_MINOR_VERSION     7
#define DPGA_AR_RELEASE_REVISION_VERSION  0
#define DPGA_SW_MAJOR_VERSION             3
#define DPGA_SW_MINOR_VERSION             0
#define DPGA_SW_PATCH_VERSION             0

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and CDD_Dpga_Cfg header file are of the same vendor */
#if (DPGA_VENDOR_ID != DPGA_VENDOR_ID_CFG)
    #error "CDD_Dpga.h and CDD_Dpga_Cfg.h have different vendor ids"
#endif

/* Check if current file and CDD_Dpga_Cfg header file are of the same Autosar version */
#if ((DPGA_AR_RELEASE_MAJOR_VERSION     != DPGA_AR_RELEASE_MAJOR_VERSION_CFG) || \
     (DPGA_AR_RELEASE_MINOR_VERSION     != DPGA_AR_RELEASE_MINOR_VERSION_CFG) || \
     (DPGA_AR_RELEASE_REVISION_VERSION  != DPGA_AR_RELEASE_REVISION_VERSION_CFG))
    #error "AutoSar Version Numbers of CDD_Dpga.h and CDD_Dpga_Cfg.h are different"
#endif

/* Check if current file and CDD_Dpga_Cfg header file are of the same software version */
#if ((DPGA_SW_MAJOR_VERSION != DPGA_SW_MAJOR_VERSION_CFG) || \
     (DPGA_SW_MINOR_VERSION != DPGA_SW_MINOR_VERSION_CFG) || \
     (DPGA_SW_PATCH_VERSION != DPGA_SW_PATCH_VERSION_CFG))
    #error "Software Version Numbers of CDD_Dpga.h and CDD_Dpga_Cfg.h are different"
#endif

/* Check if current file and CDD_Dpga_Types header file are of the same vendor */
#if (DPGA_VENDOR_ID != DPGA_VENDOR_ID_TYPES)
    #error "CDD_Dpga.h and CDD_Dpga_Types.h have different vendor ids"
#endif

/* Check if current file and CDD_Dpga_Types header file are of the same Autosar version */
#if ((DPGA_AR_RELEASE_MAJOR_VERSION     != DPGA_AR_RELEASE_MAJOR_VERSION_TYPES) || \
     (DPGA_AR_RELEASE_MINOR_VERSION     != DPGA_AR_RELEASE_MINOR_VERSION_TYPES) || \
     (DPGA_AR_RELEASE_REVISION_VERSION  != DPGA_AR_RELEASE_REVISION_VERSION_TYPES))
    #error "AutoSar Version Numbers of CDD_Dpga.h and CDD_Dpga_Types.h are different"
#endif

/* Check if current file and CDD_Dpga_Types header file are of the same software version */
#if ((DPGA_SW_MAJOR_VERSION != DPGA_SW_MAJOR_VERSION_TYPES) || \
     (DPGA_SW_MINOR_VERSION != DPGA_SW_MINOR_VERSION_TYPES) || \
     (DPGA_SW_PATCH_VERSION != DPGA_SW_PATCH_VERSION_TYPES))
    #error "Software Version Numbers of CDD_Dpga.h and CDD_Dpga_Types.h are different"
#endif

/* Check if current file and Dpga_Ip header file are of the same vendor */
#if (DPGA_VENDOR_ID != DPGA_IP_VENDOR_ID)
    #error "CDD_Dpga.h and Dpga_Ip.h have different vendor ids"
#endif

/* Check if current file and Dpga_Ip header file are of the same Autosar version */
#if ((DPGA_AR_RELEASE_MAJOR_VERSION     != DPGA_IP_AR_RELEASE_MAJOR_VERSION) || \
     (DPGA_AR_RELEASE_MINOR_VERSION     != DPGA_IP_AR_RELEASE_MINOR_VERSION) || \
     (DPGA_AR_RELEASE_REVISION_VERSION  != DPGA_IP_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of CDD_Dpga.h and Dpga_Ip.h are different"
#endif

/* Check if current file and Dpga_Ip header file are of the same software version */
#if ((DPGA_SW_MAJOR_VERSION != DPGA_IP_SW_MAJOR_VERSION) || \
     (DPGA_SW_MINOR_VERSION != DPGA_IP_SW_MINOR_VERSION) || \
     (DPGA_SW_PATCH_VERSION != DPGA_IP_SW_PATCH_VERSION))
    #error "Software Version Numbers of CDD_Dpga.h and Dpga_Ip.h are different"
#endif

/*==================================================================================================
*                                            CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/
/**
* @brief   APIs service IDs.
*
* @details Service IDs for the DPGA driver APIs.
*
*/
#define DPGA_INIT_ID                         (0x00U) /**< Dpga_Init() ID */
#define DPGA_DEINIT_ID                       (0x01U) /**< Dpga_Deinit() ID */
#define DPGA_CONFIGURE_AMPLIFIER_ID          (0x02U) /**< Dpga_ConfigureAmplifier() ID */
#if (STD_ON == DPGA_VERSION_INFO_API)
#define DPGA_GETVERSIONINFO_ID               (0x03U) /**< Dpga_GetVersionInfo() ID */
#endif

#if (STD_ON == DPGA_DEV_ERROR_DETECT)
/**
* @brief   Det error codes.
*
* @details Error codes that the DPGA driver uses for generating Det errors
*
*/
#define DPGA_E_NOT_INITIALIZED       (0x01U) /**< API service used without module initialization */
#define DPGA_E_INIT_FAILED           (0x02U) /**< API service called with invalid configuration pointer */
#define DPGA_E_INVALID_POINTER       (0x03U) /**< API service called with an invalid pointer */
#define DPGA_E_ALREADY_INITIALIZED   (0x05U) /**< Init API service used when the module has been already initialized */
#endif /* (STD_ON == DPGA_DEV_ERROR_DETECT) */

/*==================================================================================================
*                                              ENUMS
==================================================================================================*/

/*==================================================================================================
*                                  STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
*                                  GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/
#define DPGA_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Dpga_MemMap.h"

#if (STD_ON == DPGA_PRECOMPILE_SUPPORT)
    extern const Dpga_ConfigType * const Dpga_ConfigVariantPredefined[1U];
#else
    DPGA_CONFIG_EXT
#endif

#define DPGA_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Dpga_MemMap.h"

/*==================================================================================================
*                                       FUNCTION PROTOTYPES
==================================================================================================*/
#define DPGA_START_SEC_CODE
#include "Dpga_MemMap.h"

/**
* @brief   Initialize the DPGA module.
*
* @details This function initializes the DPGA module:
*               - Maps the logical channel to the hardware channel
*               - Initializes the channel
*
* @param[in] Config Pointer to the configuration structure
*
*/
Std_ReturnType Dpga_Init(const Dpga_ConfigType * const Config);

/**
* @brief   Deinitialize the DPGA module.
*
* @details This function deinitializes the DPGA module to the reset values.
*          The driver must be initialized before calling Dpga_DeInit().
*
*/
Std_ReturnType Dpga_DeInit(void);

/**
* @brief   Reload Amplifier configuration.
*
* @details This function is used to configure the Amplifier at runtime.
*          The user can store specific configuration values after device power up
*          and reload them after each device reset.
*
* @param[in] AmplifierConfig  Pointer to the Amplifier configuration structure
*
* @return   Std_ReturnType
*
*/
Std_ReturnType Dpga_ConfigureAmplifier(const Dpga_AmplifierConfigType * AmplifierConfig);

#if (STD_ON == DPGA_VERSION_INFO_API)
/**
* @brief   Returns the version information of the DPGA module.
*
* @details The version information includes:
*
*          - Two bytes for the Vendor ID
*          - Two bytes for the Module ID
*          - One byte for the Channel ID
*          - Three bytes version number. The numbering shall be vendor specific and it consists of:
*               - The major, the minor and the patch version number of the module;
*               - The AUTOSAR specification version number shall not be included.
*                 The AUTOSAR specification version number is checked during compile time and therefore not required in this API.

*
* @param[in] VersionInfo Pointer to the version info structure
*
*/
void Dpga_GetVersionInfo(Std_VersionInfoType * VersionInfo);
#endif /* (STD_ON == DPGA_VERSION_INFO_API) */

#define DPGA_STOP_SEC_CODE
#include "Dpga_MemMap.h"


#ifdef __cplusplus
}
#endif

/** @} */

#endif /* DPGA_H */
