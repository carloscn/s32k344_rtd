/*==================================================================================================
* Project : RTD AUTOSAR 4.7
* Platform : CORTEXM
* Peripheral : IPV_USDHC
* Dependencies : 
*
* Autosar Version : 4.7.0
* Autosar Revision : ASR_REL_4_7_REV_0000
* Autosar Conf.Variant :
* SW Version : 3.0.0
* Build Version : S32K3_RTD_3_0_0_D2303_ASR_REL_4_7_REV_0000_20230331
*
* Copyright 2020 - 2023 NXP Semiconductors
*
* NXP Confidential. This software is owned or controlled by NXP and may only be
* used strictly in accordance with the applicable license terms. By expressly
* accepting such terms or by downloading, installing, activating and/or otherwise
* using the software, you are agreeing that you have read, and that you agree to
* comply with and are bound by, such license terms. If you do not agree to be
* bound by the applicable license terms, then you may not retain, install,
* activate or otherwise use the software.
==================================================================================================*/

#ifndef MEM_43_EEP_IPW_H
#define MEM_43_EEP_IPW_H

/**
* @file
*
* @addtogroup MEM_43_EEP_DRIVER Mem_43_Eeprom Driver
* @{
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
#include "Sd_Emmc_Ip_Cfg.h"
#include "Sd_Emmc_Ip.h"
#include "Usdhc_Ip.h"
#include "Mem_43_Eep_InternalTypes.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define MEM_43_EEP_IPW_VENDOR_ID_H                    43
#define MEM_43_EEP_IPW_AR_RELEASE_MAJOR_VERSION_H     4
#define MEM_43_EEP_IPW_AR_RELEASE_MINOR_VERSION_H     7
#define MEM_43_EEP_IPW_AR_RELEASE_REVISION_VERSION_H  0
#define MEM_43_EEP_IPW_SW_MAJOR_VERSION_H             3
#define MEM_43_EEP_IPW_SW_MINOR_VERSION_H             0
#define MEM_43_EEP_IPW_SW_PATCH_VERSION_H             0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if header file and Sd_Emmc_Ip_Cfg.h header file are of the same vendor */
#if (MEM_43_EEP_IPW_VENDOR_ID_H != SD_EMMC_VENDOR_ID_IP_CFG)
    #error "Mem_43_Eep_IPW.h and Sd_Emmc_Ip_Cfg.h have different vendor ids"
#endif
/* Check if header file and Sd_Emmc_Ip_Cfg.h header file are of the same Autosar version */
#if ((MEM_43_EEP_IPW_AR_RELEASE_MAJOR_VERSION_H    != SD_EMMC_AR_RELEASE_MAJOR_VERSION_IP_CFG) || \
     (MEM_43_EEP_IPW_AR_RELEASE_MINOR_VERSION_H    != SD_EMMC_AR_RELEASE_MINOR_VERSION_IP_CFG) || \
     (MEM_43_EEP_IPW_AR_RELEASE_REVISION_VERSION_H != SD_EMMC_AR_RELEASE_REVISION_VERSION_IP_CFG) \
    )
    #error "AutoSar Version Numbers of Mem_43_Eep_IPW.h and Sd_Emmc_Ip_Cfg.h are different"
#endif
/* Check if header file and Sd_Emmc_Ip_Cfg.h header file are of the same software version */
#if ((MEM_43_EEP_IPW_SW_MAJOR_VERSION_H != SD_EMMC_SW_MAJOR_VERSION_IP_CFG) || \
     (MEM_43_EEP_IPW_SW_MINOR_VERSION_H != SD_EMMC_SW_MINOR_VERSION_IP_CFG) || \
     (MEM_43_EEP_IPW_SW_PATCH_VERSION_H != SD_EMMC_SW_PATCH_VERSION_IP_CFG) \
    )
    #error "Software Version Numbers of Mem_43_Eep_IPW.h and Sd_Emmc_Ip_Cfg.h are different"
#endif

/* Check if header file and Sd_Emmc_Ip.h header file are of the same vendor */
#if (MEM_43_EEP_IPW_VENDOR_ID_H != SD_EMMC_IP_VENDOR_ID)
    #error "Mem_43_Eep_IPW.h and Sd_Emmc_Ip.h have different vendor ids"
#endif
/* Check if header file and Sd_Emmc_Ip.h header file are of the same Autosar version */
#if ((MEM_43_EEP_IPW_AR_RELEASE_MAJOR_VERSION_H    != SD_EMMC_IP_AR_RELEASE_MAJOR_VERSION) || \
     (MEM_43_EEP_IPW_AR_RELEASE_MINOR_VERSION_H    != SD_EMMC_IP_AR_RELEASE_MINOR_VERSION) || \
     (MEM_43_EEP_IPW_AR_RELEASE_REVISION_VERSION_H != SD_EMMC_IP_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Mem_43_Eep_IPW.h and Sd_Emmc_Ip.h are different"
#endif
/* Check if header file and Sd_Emmc_Ip.h header file are of the same software version */
#if ((MEM_43_EEP_IPW_SW_MAJOR_VERSION_H != SD_EMMC_IP_SW_MAJOR_VERSION) || \
     (MEM_43_EEP_IPW_SW_MINOR_VERSION_H != SD_EMMC_IP_SW_MINOR_VERSION) || \
     (MEM_43_EEP_IPW_SW_PATCH_VERSION_H != SD_EMMC_IP_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Mem_43_Eep_IPW.h and Sd_Emmc_Ip.h are different"
#endif

/* Check if header file and Usdhc_Ip.h header file are of the same vendor */
#if (MEM_43_EEP_IPW_VENDOR_ID_H != USDHC_IP_VENDOR_ID_H)
    #error "Mem_43_Eep_IPW.h and Usdhc_Ip.h have different vendor ids"
#endif
/* Check if header file and Usdhc_Ip.h header file are of the same Autosar version */
#if ((MEM_43_EEP_IPW_AR_RELEASE_MAJOR_VERSION_H    != USDHC_IP_AR_RELEASE_MAJOR_VERSION_H) || \
     (MEM_43_EEP_IPW_AR_RELEASE_MINOR_VERSION_H    != USDHC_IP_AR_RELEASE_MINOR_VERSION_H) || \
     (MEM_43_EEP_IPW_AR_RELEASE_REVISION_VERSION_H != USDHC_IP_AR_RELEASE_REVISION_VERSION_H) \
    )
    #error "AutoSar Version Numbers of Mem_43_Eep_IPW.h and Usdhc_Ip.h are different"
#endif
/* Check if header file and Usdhc_Ip.h header file are of the same software version */
#if ((MEM_43_EEP_IPW_SW_MAJOR_VERSION_H != USDHC_IP_SW_MAJOR_VERSION_H) || \
     (MEM_43_EEP_IPW_SW_MINOR_VERSION_H != USDHC_IP_SW_MINOR_VERSION_H) || \
     (MEM_43_EEP_IPW_SW_PATCH_VERSION_H != USDHC_IP_SW_PATCH_VERSION_H) \
    )
    #error "Software Version Numbers of Mem_43_Eep_IPW.h and Usdhc_Ip.h are different"
#endif

/* Check if header file and Mem_43_Eep_InternalTypes.h header file are of the same vendor */
#if (MEM_43_EEP_IPW_VENDOR_ID_H != MEM_43_EEP_INTERNALTYPES_VENDOR_ID)
    #error "Mem_43_Eep_IPW.h and Mem_43_Eep_InternalTypes.h have different vendor ids"
#endif
/* Check if header file and Mem_43_Eep_InternalTypes.h header file are of the same Autosar version */
#if ((MEM_43_EEP_IPW_AR_RELEASE_MAJOR_VERSION_H     != MEM_43_EEP_INTERNALTYPES_AR_RELEASE_MAJOR_VERSION) || \
     (MEM_43_EEP_IPW_AR_RELEASE_MINOR_VERSION_H     != MEM_43_EEP_INTERNALTYPES_AR_RELEASE_MINOR_VERSION) || \
     (MEM_43_EEP_IPW_AR_RELEASE_REVISION_VERSION_H  != MEM_43_EEP_INTERNALTYPES_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Mem_43_Eep_IPW.h and Mem_43_Eep_InternalTypes.h are different"
#endif
/* Check if header file and Mem_43_Eep_InternalTypes.h header file are of the same software version */
#if ((MEM_43_EEP_IPW_SW_MAJOR_VERSION_H  != MEM_43_EEP_INTERNALTYPES_SW_MAJOR_VERSION) || \
     (MEM_43_EEP_IPW_SW_MINOR_VERSION_H  != MEM_43_EEP_INTERNALTYPES_SW_MINOR_VERSION) || \
     (MEM_43_EEP_IPW_SW_PATCH_VERSION_H  != MEM_43_EEP_INTERNALTYPES_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Mem_43_Eep_IPW.h and Mem_43_Eep_InternalTypes.h are different"
#endif

/*==================================================================================================
*                                    VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                    DEFINES AND MACROS
==================================================================================================*/

/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/
#define MEM_43_EEP_START_SEC_CODE
#include "Mem_43_Eep_MemMap.h"

Std_ReturnType Mem_43_Eep_Ipw_Init(Mem_43_Eep_ConfigType const * Config, uint32 InstanceIndex);

Std_ReturnType Mem_43_Eep_Ipw_DeInit(Mem_43_Eep_ConfigType const * Config, uint32 InstanceIndex);

Std_ReturnType Mem_43_Eep_Ipw_CheckReadParams(Mem_43_Eep_AddressType SourceAddress,
                                       Mem_43_Eep_DataType const * TargetAddressPtr,
                                       Mem_43_Eep_LengthType Length, uint32 InstanceIndex
                                      );

Std_ReturnType Mem_43_Eep_Ipw_Read(Mem_43_Eep_AddressType Mem_43_EepromAddrIt,
                            Mem_43_Eep_DataType *JobDataDestPtr,
                            Mem_43_Eep_LengthType TransfLength, uint32 InstanceIndex
                           );

Std_ReturnType Mem_43_Eep_Ipw_CheckWriteParams(Mem_43_Eep_AddressType TargetAddress,
                                        const Mem_43_Eep_DataType * pSourceAddressPtr,
                                        Mem_43_Eep_LengthType Length, uint32 InstanceIndex
                                       );

Std_ReturnType Mem_43_Eep_Ipw_Write(Mem_43_Eep_AddressType Mem_43_EepromAddrIt,
                             const Mem_43_Eep_DataType *JobSrcAddrPtr,
                             Mem_43_Eep_LengthType TransfLength, uint32 InstanceIndex
                            );

Std_ReturnType Mem_43_Eep_Ipw_CheckEraseParams(Mem_43_Eep_AddressType TargetAddress,
                                        Mem_43_Eep_LengthType Length, uint32 InstanceIndex
                                       );

Std_ReturnType Mem_43_Eep_Ipw_Erase(Mem_43_Eep_AddressType Mem_43_EepromAddrIt,
                             Mem_43_Eep_LengthType TransfLength, uint32 InstanceIndex
                            );

Std_ReturnType Mem_43_Eep_Ipw_CheckBlankCheckParams(Mem_43_Eep_AddressType TargetAddress,
                                                 Mem_43_Eep_LengthType Length, uint32 InstanceIndex
                                                 );

Mem_43_Eep_BlankCheckType Mem_43_Eep_Ipw_BlankCheck(Mem_43_Eep_AddressType EepromAddrIt,
                                      Mem_43_Eep_LengthType BlankLength, uint32 InstanceIndex
                                      );

Std_ReturnType Mem_43_Eep_Ipw_Cancel(uint32 InstanceIndex);

Std_ReturnType Mem_43_Eep_Ipw_CheckCompareParams(Mem_43_Eep_AddressType u32EepromAddrNeedsCompared,
                                          const uint8 * TargetAddressPtr,
                                          Mem_43_Eep_LengthType Length, uint32 InstanceIndex
                                         );

Mem_43_Eep_CompareCheckType Mem_43_Eep_Ipw_CompareSync(Mem_43_Eep_AddressType u32EepromAddrNeedsCompared,
                                   const uint8 *DestAddress,
                                   Mem_43_Eep_LengthType TransfLength, uint32 InstanceIndex
                                  );

#define MEM_43_EEP_STOP_SEC_CODE
#include "Mem_43_Eep_MemMap.h"

#ifdef __cplusplus
}
#endif

#endif

/** @}*/

