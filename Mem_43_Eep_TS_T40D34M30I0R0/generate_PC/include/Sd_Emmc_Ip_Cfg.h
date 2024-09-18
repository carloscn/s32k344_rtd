[!CODE!][!//
/*==================================================================================================
*   Project              : RTD AUTOSAR 4.7
*   Platform             : CORTEXM
*   Peripheral           : IPV_USDHC
*   Dependencies         : 
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

#ifndef SD_EMMC_IP_CFG_H
#define SD_EMMC_IP_CFG_H

/**
* @file Sd_Emmc_Ip_Cfg.h
*
* @addtogroup Sd_Emmc_Ip
* @{
*/

#ifdef __cplusplus
extern "C"{
#endif

/**
*
*
*/

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Usdhc_Ip_Cfg.h"
#include "Sd_Emmc_Ip_Types.h"
#include "StandardTypes.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define SD_EMMC_VENDOR_ID_IP_CFG                          43
#define SD_EMMC_AR_RELEASE_MAJOR_VERSION_IP_CFG           4
#define SD_EMMC_AR_RELEASE_MINOR_VERSION_IP_CFG           7
#define SD_EMMC_AR_RELEASE_REVISION_VERSION_IP_CFG        0
#define SD_EMMC_SW_MAJOR_VERSION_IP_CFG                   3
#define SD_EMMC_SW_MINOR_VERSION_IP_CFG                   0
#define SD_EMMC_SW_PATCH_VERSION_IP_CFG                   0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and Usdhc_Ip_Cfg header file are of the same vendor */
#if (SD_EMMC_VENDOR_ID_IP_CFG != USDHC_VENDOR_ID_IP_CFG)
    #error "Sd_Emmc_Ip_Cfg.h and Usdhc_Ip_Cfg.h have different vendor ids"
#endif
/* Check if current file and Usdhc_Ip_Cfg header file are of the same Autosar version */
#if ((SD_EMMC_AR_RELEASE_MAJOR_VERSION_IP_CFG    != USDHC_AR_RELEASE_MAJOR_VERSION_IP_CFG) || \
     (SD_EMMC_AR_RELEASE_MINOR_VERSION_IP_CFG    != USDHC_AR_RELEASE_MINOR_VERSION_IP_CFG) || \
     (SD_EMMC_AR_RELEASE_REVISION_VERSION_IP_CFG != USDHC_AR_RELEASE_REVISION_VERSION_IP_CFG) \
    )
    #error "AutoSar Version Numbers of Sd_Emmc_Ip_Cfg.h and Usdhc_Ip_Cfg.h are different"
#endif
/* Check if current file and Usdhc_Ip_Cfg header file are of the same software version */
#if ((SD_EMMC_SW_MAJOR_VERSION_IP_CFG != USDHC_SW_MAJOR_VERSION_IP_CFG) || \
     (SD_EMMC_SW_MINOR_VERSION_IP_CFG != USDHC_SW_MINOR_VERSION_IP_CFG) || \
     (SD_EMMC_SW_PATCH_VERSION_IP_CFG != USDHC_SW_PATCH_VERSION_IP_CFG) \
    )
    #error "Software Version Numbers of Sd_Emmc_Ip_Cfg.h and Usdhc_Ip_Cfg.h are different"
#endif

/* Check if current file and Sd_Emmc_Ip_Types header file are of the same vendor */
#if (SD_EMMC_VENDOR_ID_IP_CFG != SD_EMMC_IP_TYPES_VENDOR_ID)
    #error "Sd_Emmc_Ip_Cfg.h and Sd_Emmc_Ip_Types.h have different vendor ids"
#endif
/* Check if current file and Sd_Emmc_Ip_Types header file are of the same Autosar version */
#if ((SD_EMMC_AR_RELEASE_MAJOR_VERSION_IP_CFG    != SD_EMMC_IP_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (SD_EMMC_AR_RELEASE_MINOR_VERSION_IP_CFG    != SD_EMMC_IP_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (SD_EMMC_AR_RELEASE_REVISION_VERSION_IP_CFG != SD_EMMC_IP_TYPES_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Sd_Emmc_Ip_Cfg.h and Sd_Emmc_Ip_Types.h are different"
#endif
/* Check if current file and Sd_Emmc_Ip_Types header file are of the same software version */
#if ((SD_EMMC_SW_MAJOR_VERSION_IP_CFG != SD_EMMC_IP_TYPES_SW_MAJOR_VERSION) || \
     (SD_EMMC_SW_MINOR_VERSION_IP_CFG != SD_EMMC_IP_TYPES_SW_MINOR_VERSION) || \
     (SD_EMMC_SW_PATCH_VERSION_IP_CFG != SD_EMMC_IP_TYPES_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Sd_Emmc_Ip_Cfg.h and Sd_Emmc_Ip_Types.h are different"
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if current file and StandardTypes header file are of the same Autosar version */
    #if ((SD_EMMC_AR_RELEASE_MAJOR_VERSION_IP_CFG != STD_AR_RELEASE_MAJOR_VERSION) || \
         (SD_EMMC_AR_RELEASE_MINOR_VERSION_IP_CFG != STD_AR_RELEASE_MINOR_VERSION) \
        )
        #error "AutoSar Version Numbers of Mem_43_Eep.c and StandardTypes.h are different"
    #endif
#endif
/*==================================================================================================
                                       DEFINES AND MACROS
==================================================================================================*/

#define SD_IP_INSTANCE_NO                   (1U)
[!NOCODE!]
[!IF "node:exists(Mem_43_EepSdCfg)"!][!//
    [!SELECT "Mem_43_EepSdCfg"!]
    [!LOOP "./*"!][!//
    [!INDENT "0"!]
    [!CODE!]
#define SD_IP_DEV_ERROR_DETECT                 [!IF "./Mem_43_EepSdIpDevErrorDetect"!](STD_ON)[!ELSE!](STD_OFF)[!ENDIF!]

/* @brief SD_EMMC_IP development error detect enable/disable */
#define SD_IP_DEV_ASSERT(x)                    [!IF "./Mem_43_EepSdIpDevErrorDetect"!]DevAssert((x))[!ENDIF!]

/*! @brief Maximum loop count to check the card operation voltage range */
#define SD_IP_SDMMC_MAX_VOLTAGE_RETRIES        ([!"./SdMaxVoltRetries"!]U)

/* ! @brief Block size of the SD/eMMC device */
#define SD_IP_SDMMC_DEFAULT_BLOCK_SIZE         (512U)

/* ! @brief Page size of the SD/eMMC device. Data must be alligned to page size in case ADMA2 is used */
#define SD_IP_PAGE_SIZE_4BYTES                 ([!"(ecu:get('Mem_43_Eep.Sd.PageSize'))"!]U)

/*! @brief Maximum loop count to check the SDHC card for cmd55 */
#define SD_IP_MAX_RETRIES                      ([!"./SdMaxCmd55Retries"!]U)

/*! @brief Maximum loop count to check the SDHC card for cmd55 */
#define SD_IP_SEND_STATUS_RETRIES_NO           ([!"./SdMaxSendStatusRetries"!]U)

/*! @brief SD automatically discover frequency */
#define SD_IP_AUTO_DISCOVER_FREQUENCY          [!IF "./Mem_43_EepSdAutoDiscoverFrequency"!](STD_ON)[!ELSE!](STD_OFF)[!ENDIF!]

/* Pre-processor switch to enable and disable the API for configuring eMMC card for boot */
#define SD_IP_MMC_CONFIG_BOOT_ENABLED          [!IF "node:exists(BootCardConfig)"!](STD_ON)[!ELSE!](STD_OFF)[!ENDIF!]

    [!CR!][!ENDCODE!]
    [!ENDINDENT!]
    [!ENDLOOP!][!//
    [!ENDSELECT!]
[!ENDIF!][!//
[!ENDNOCODE!]
/* Should be set by configuration as STD_ON if
Mem_43_EepDevErrorDetect exists and is also set to ON */
#define MEM_43_EEP_SD_IP_DEV_ERROR_DETECT             (SD_IP_DEV_ERROR_DETECT)

/*==================================================================================================
                                 STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
                                 GLOBAL CONSTANT DECLARATIONS
==================================================================================================*/

[!NOCODE!]
[!VAR "variantIndex"="0"!][!//
[!VAR "Mem_43_EepSdCfgCount"="num:i(count(Mem_43_EepSdCfg/*))"!][!//
[!VAR "variantNumber"="variant:size()"!][!//

[!IF "$Mem_43_EepSdCfgCount > 0"!][!//
[!SELECT "Mem_43_EepSdCfg"!]
    [!IF "./*[1]/Mem_43_EepSdIpDevErrorDetect"!][!//
        [!CODE!]#define MEM_43_EEP_START_SEC_CONFIG_DATA_UNSPECIFIED[!CR!][!ENDCODE!]
        [!CODE!]#include "Mem_43_Eep_MemMap.h"[!CR!][!ENDCODE!]
    [!ELSE!]
        [!CODE!]#define MEM_43_EEP_START_SEC_VAR_INIT_UNSPECIFIED[!CR!][!ENDCODE!]
        [!CODE!]#include "Mem_43_Eep_MemMap.h"[!CR!][!ENDCODE!]
    [!ENDIF!][!//

    [!LOOP "./*"!][!//
        [!VAR "configName" = "node:name(.)"!]
        [!IF "var:defined('postBuildVariant')"!][!//
            [!CODE!][!CR!][!ENDCODE!]
            [!LOOP "variant:all()"!][!VAR "variantIndex"="$variantIndex + 1"!][!//
                [!CODE!]/*! @brief SD configurations */[!CR!][!ENDCODE!]
                [!CODE!]extern const Sd_Emmc_Ip_ConfigType [!"$configName"!]_[!"."!];[!CR!][!ENDCODE!]
            [!ENDLOOP!][!//
        [!ELSE!]
            [!CODE!][!CR!][!ENDCODE!]
            [!CODE!]/*! @brief SD configurations */[!CR!][!ENDCODE!]
            [!CODE!]extern const Sd_Emmc_Ip_ConfigType [!"$configName"!];[!CR!][!ENDCODE!]
        [!ENDIF!][!//
    [!ENDLOOP!]

    [!IF "./*[1]/Mem_43_EepSdIpDevErrorDetect"!][!//
        [!CODE!][!CR!][!ENDCODE!]
        [!CODE!]#define MEM_43_EEP_STOP_SEC_CONFIG_DATA_UNSPECIFIED[!CR!][!ENDCODE!]
        [!CODE!]#include "Mem_43_Eep_MemMap.h"[!CR!][!ENDCODE!]
    [!ELSE!]
        [!CODE!][!CR!][!ENDCODE!]
        [!CODE!]#define MEM_43_EEP_STOP_SEC_VAR_INIT_UNSPECIFIED[!CR!][!ENDCODE!]
        [!CODE!]#include "Mem_43_Eep_MemMap.h"[!CR!][!ENDCODE!]
    [!ENDIF!][!//
[!ENDSELECT!]
[!ENDIF!][!//
[!ENDNOCODE!]

[!CR!][!ENDCODE!][!//
#ifdef __cplusplus
}
#endif

#endif /* SD_EMMC_IP_CFG_H */

