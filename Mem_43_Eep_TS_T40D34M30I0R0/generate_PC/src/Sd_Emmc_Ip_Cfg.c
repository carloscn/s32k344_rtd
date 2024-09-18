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
[!VAR "variantName" = "''"!][!//
[!VAR "variantNameUpperCase" = "''"!][!//
[!IF "var:defined('postBuildVariant')"!][!//
[!VAR "variantName" = "concat('_', $postBuildVariant)"!][!//
[!VAR "variantNameUpperCase" = "toUpperCase(string($variantName))"!][!//
[!ENDIF!][!//

/**
* @file Sd_Emmc_Ip[!"$variantName"!]_PBcfg.c
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
#include "Sd_Emmc_Ip_Cfg.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define SD_EMMC[!"$variantNameUpperCase"!]_VENDOR_ID_IP_PBCFG_C                      43
#define SD_EMMC[!"$variantNameUpperCase"!]_AR_RELEASE_MAJOR_VERSION_IP_PBCFG_C       4
#define SD_EMMC[!"$variantNameUpperCase"!]_AR_RELEASE_MINOR_VERSION_IP_PBCFG_C       7
#define SD_EMMC[!"$variantNameUpperCase"!]_AR_RELEASE_REVISION_VERSION_IP_PBCFG_C    0
#define SD_EMMC[!"$variantNameUpperCase"!]_SW_MAJOR_VERSION_IP_PBCFG_C               3
#define SD_EMMC[!"$variantNameUpperCase"!]_SW_MINOR_VERSION_IP_PBCFG_C               0
#define SD_EMMC[!"$variantNameUpperCase"!]_SW_PATCH_VERSION_IP_PBCFG_C               0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and Sd_Emmc_Ip_Cfg header file are of the same vendor */
#if (SD_EMMC[!"$variantNameUpperCase"!]_VENDOR_ID_IP_PBCFG_C != SD_EMMC_VENDOR_ID_IP_CFG)
    #error "AutoSar Version Numbers of Sd_Emmc_Ip[!"$variantName"!]_PBcfg.c and Sd_Emmc_Ip_Cfg.h have different vendor ids"
#endif
/* Check if current file and Sd_Emmc_Ip_Cfg header file are of the same Autosar version */
#if ((SD_EMMC[!"$variantNameUpperCase"!]_AR_RELEASE_MAJOR_VERSION_IP_PBCFG_C    != SD_EMMC_AR_RELEASE_MAJOR_VERSION_IP_CFG) || \
     (SD_EMMC[!"$variantNameUpperCase"!]_AR_RELEASE_MINOR_VERSION_IP_PBCFG_C    != SD_EMMC_AR_RELEASE_MINOR_VERSION_IP_CFG) || \
     (SD_EMMC[!"$variantNameUpperCase"!]_AR_RELEASE_REVISION_VERSION_IP_PBCFG_C != SD_EMMC_AR_RELEASE_REVISION_VERSION_IP_CFG) \
    )
    #error "AutoSar Version Numbers of Sd_Emmc_Ip[!"$variantName"!]_PBcfg.c and Sd_Emmc_Ip_Cfg.h are different"
#endif
/* Check if current file and Sd_Emmc_Ip_Cfg header file are of the same Software version */
#if ((SD_EMMC[!"$variantNameUpperCase"!]_SW_MAJOR_VERSION_IP_PBCFG_C != SD_EMMC_SW_MAJOR_VERSION_IP_CFG) || \
     (SD_EMMC[!"$variantNameUpperCase"!]_SW_MINOR_VERSION_IP_PBCFG_C != SD_EMMC_SW_MINOR_VERSION_IP_CFG) || \
     (SD_EMMC[!"$variantNameUpperCase"!]_SW_PATCH_VERSION_IP_PBCFG_C != SD_EMMC_SW_PATCH_VERSION_IP_CFG) \
    )
    #error "Software Version Numbers of Sd_Emmc_Ip[!"$variantName"!]_PBcfg.c and Sd_Emmc_Ip_Cfg.h are different"
#endif

/*==================================================================================================
                                     FUNCTION PROTOTYPES
==================================================================================================*/

/*==================================================================================================
                                           CONSTANTS
==================================================================================================*/
[!NOCODE!]
[!IF "node:exists(Mem_43_EepSdCfg)"!][!//
    [!SELECT "Mem_43_EepSdCfg"!]
    [!LOOP "./*"!][!//
[!CODE!]

#define MEM_43_EEP_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Mem_43_Eep_MemMap.h"
[!IF "node:exists(BootCardConfig)"!]
/* EMMC Boot Configuration */
static const Sd_Emmc_Ip_BootConfigType [!"node:name(.)"!]_Boot[!"$variantName"!] =
{
   [!"node:value(./BootCardConfig/bootPartitionSelect)"!], /* Boot partition selection */
   (boolean)[!IF "node:value(./BootCardConfig/ackEnable)"!]TRUE[!ELSE!]FALSE[!ENDIF!], /* ACK enable/disabled for boot process */
   [!"node:value(./BootCardConfig/bootSpeed)"!], /* Boot mode - SDR or DDR */
   [!"node:value(./BootCardConfig/bootBusWidth)"!], /* Boot bus width- 1-4-8 bits*/
};
[!ENDIF!]
/* SD Configurations */
const Sd_Emmc_Ip_ConfigType [!"node:name(.)"!][!"$variantName"!] =
{
    &[!"node:name(node:ref(./usdhcCfgReference))"!][!"$variantName"!],
    [!"node:value(./afrequencyTable)"!]UL, /* SdConfigClock */
    [!"./u32McuClock"!]UL, /* u32McuClock */
    0UL, /* flags */
    [!IF "./Mem_43_EepEnableOperationsOnEmmc"!]SD_IP_MEMORY_CARD_MMC[!ELSE!]SD_IP_MEMORY_CARD_SD[!ENDIF!], /* cardType */
    [!"./Mem_43_EepBusWidthMode"!], /* Bus width mode */
    [!"./Mem_43_EepCardDriverStrength"!]U, /* Card driver strength */
[!IF "node:exists(BootCardConfig)"!][!//
    &[!"node:name(.)"!]_Boot[!"$variantName"!]   /* MMC boot configuration */
[!ELSE!][!//
    NULL_PTR   /* MMC boot configuration */
[!ENDIF!][!//
};

#define MEM_43_EEP_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Mem_43_Eep_MemMap.h"

[!ENDCODE!][!//
    [!ENDLOOP!][!//
    [!ENDSELECT!][!//
[!ENDIF!][!//
[!ENDNOCODE!]
[!ENDCODE!]
#ifdef __cplusplus
}
#endif
/** @}*/
