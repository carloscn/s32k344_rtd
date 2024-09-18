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

#ifndef SD_EMMC_IP_H
#define SD_EMMC_IP_H

/**
*   @file
*
*   @addtogroup IPV_SD_EMMC SD_EMMC
*   @{
*/

#ifdef __cplusplus
extern "C"{
#endif
/*==================================================================================================
                                         INCLUDE FILES
 1) system and project includes
 2) needed interfaces from external units
 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Sd_Emmc_Ip_Types.h"
#include "Sd_Emmc_Ip_Cfg.h"
#if (STD_ON == SD_IP_DEV_ERROR_DETECT)
  #include "Devassert.h"
#endif
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define SD_EMMC_IP_VENDOR_ID                    43
#define SD_EMMC_IP_AR_RELEASE_MAJOR_VERSION     4
#define SD_EMMC_IP_AR_RELEASE_MINOR_VERSION     7
#define SD_EMMC_IP_AR_RELEASE_REVISION_VERSION  0
#define SD_EMMC_IP_SW_MAJOR_VERSION             3
#define SD_EMMC_IP_SW_MINOR_VERSION             0
#define SD_EMMC_IP_SW_PATCH_VERSION             0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if header file and Sd_Emmc_Ip_Types.h header file are of the same vendor */
#if (SD_EMMC_IP_VENDOR_ID != SD_EMMC_IP_TYPES_VENDOR_ID)
    #error "Sd_Emmc_Ip.h and Sd_Emmc_Ip_Types.h have different vendor ids"
#endif
/* Check if header file and Sd_Emmc_Ip_Types.h header file are of the same Autosar version */
#if ((SD_EMMC_IP_AR_RELEASE_MAJOR_VERSION    != SD_EMMC_IP_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (SD_EMMC_IP_AR_RELEASE_MINOR_VERSION    != SD_EMMC_IP_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (SD_EMMC_IP_AR_RELEASE_REVISION_VERSION != SD_EMMC_IP_TYPES_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Sd_Emmc_Ip.h and Sd_Emmc_Ip_Types.h are different"
#endif
/* Check if header file and Sd_Emmc_Ip_Types.h header file are of the same software version */
#if ((SD_EMMC_IP_SW_MAJOR_VERSION != SD_EMMC_IP_TYPES_SW_MAJOR_VERSION) || \
     (SD_EMMC_IP_SW_MINOR_VERSION != SD_EMMC_IP_TYPES_SW_MINOR_VERSION) || \
     (SD_EMMC_IP_SW_PATCH_VERSION != SD_EMMC_IP_TYPES_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Sd_Emmc_Ip.h and Sd_Emmc_Ip_Types.h are different"
#endif

/* Check if header file and Sd_Emmc_Ip_Cfg.h header file are of the same vendor */
#if (SD_EMMC_IP_VENDOR_ID != SD_EMMC_VENDOR_ID_IP_CFG)
    #error "Sd_Emmc_Ip.h and Sd_Emmc_Ip_Cfg.h have different vendor ids"
#endif
/* Check if header file and Sd_Emmc_Ip_Cfg.h header file are of the same Autosar version */
#if ((SD_EMMC_IP_AR_RELEASE_MAJOR_VERSION    != SD_EMMC_AR_RELEASE_MAJOR_VERSION_IP_CFG) || \
     (SD_EMMC_IP_AR_RELEASE_MINOR_VERSION    != SD_EMMC_AR_RELEASE_MINOR_VERSION_IP_CFG) || \
     (SD_EMMC_IP_AR_RELEASE_REVISION_VERSION != SD_EMMC_AR_RELEASE_REVISION_VERSION_IP_CFG) \
    )
    #error "AutoSar Version Numbers of Sd_Emmc_Ip.h and Sd_Emmc_Ip_Cfg.h are different"
#endif
/* Check if header file and Sd_Emmc_Ip_Cfg.h header file are of the same software version */
#if ((SD_EMMC_IP_SW_MAJOR_VERSION != SD_EMMC_SW_MAJOR_VERSION_IP_CFG) || \
     (SD_EMMC_IP_SW_MINOR_VERSION != SD_EMMC_SW_MINOR_VERSION_IP_CFG) || \
     (SD_EMMC_IP_SW_PATCH_VERSION != SD_EMMC_SW_PATCH_VERSION_IP_CFG) \
    )
    #error "Software Version Numbers of Sd_Emmc_Ip.h and Sd_Emmc_Ip_Cfg.h are different"
#endif

/* Checks against Devassert.h */
#if SD_IP_DEV_ERROR_DETECT == STD_ON
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if ((SD_EMMC_IP_AR_RELEASE_MAJOR_VERSION != DEVASSERT_AR_RELEASE_MAJOR_VERSION) || \
         (SD_EMMC_IP_AR_RELEASE_MINOR_VERSION != DEVASSERT_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of Sd_Emmc_Ip.h and Devassert.h are different"
    #endif
#endif
#endif /* STD_ON == SD_IP_DEV_ERROR_DETECT */
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
#define MEM_43_EEP_START_SEC_CODE
#include "Mem_43_Eep_MemMap.h"

Sd_Emmc_Ip_StatusType Sd_Emmc_Ip_Init(const Sd_Emmc_Ip_ConfigType *Config);

Sd_Emmc_Ip_StatusType Sd_Emmc_Ip_DeInit(const Sd_Emmc_Ip_ConfigType *Config);

boolean Sd_Emmc_Ip_CheckReadOnly(void);

Sd_Emmc_Ip_StatusType Sd_Emmc_Ip_ReadBlocks(const Sd_Emmc_Ip_ConfigType *Config, uint8 *Buffer, uint32 StartBlock, uint32 BlockCount);

Sd_Emmc_Ip_StatusType Sd_Emmc_Ip_WriteBlocks(const Sd_Emmc_Ip_ConfigType *Config, const uint8 *Buffer, uint32 StartBlock, uint32 BlockCount, boolean AsyncEnable);

Sd_Emmc_Ip_StatusType Sd_Emmc_Ip_EraseBlocks(const Sd_Emmc_Ip_ConfigType *Config, uint32 StartBlock, uint32 BlockCount, boolean AsyncEnable);

Sd_Emmc_Ip_StatusType Sd_Emmc_Ip_Abort(const Sd_Emmc_Ip_ConfigType *Config);

void Sd_Emmc_Ip_GetCardInformation(Sd_Emmc_Ip_CardInformationType *CardInformation);

void Sd_Ip_StopTransmission(const Sd_Emmc_Ip_ConfigType *Config);

Sd_Emmc_Ip_StatusType Sd_Emmc_Ip_MmcSwitchPartitionAccess(const Sd_Emmc_Ip_ConfigType *Sd_Ip_pConfig, Sd_Ip_MmcPartitionAccessType Sd_Ip_PartitionAccess);

#define MEM_43_EEP_STOP_SEC_CODE
#include "Mem_43_Eep_MemMap.h"

#ifdef __cplusplus
}
#endif

/*! @} */
#endif /* SD_EMMC_IP_H*/
