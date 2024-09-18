
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

#ifndef MEM_43_EEP_INTERNALTYPES_H
#define MEM_43_EEP_INTERNALTYPES_H

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
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Sd_Emmc_Ip_Types.h"
#include "Usdhc_Ip_Types.h"
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define MEM_43_EEP_INTERNALTYPES_VENDOR_ID                    43
#define MEM_43_EEP_INTERNALTYPES_AR_RELEASE_MAJOR_VERSION     4
#define MEM_43_EEP_INTERNALTYPES_AR_RELEASE_MINOR_VERSION     7
#define MEM_43_EEP_INTERNALTYPES_AR_RELEASE_REVISION_VERSION  0
#define MEM_43_EEP_INTERNALTYPES_SW_MAJOR_VERSION             3
#define MEM_43_EEP_INTERNALTYPES_SW_MINOR_VERSION             0
#define MEM_43_EEP_INTERNALTYPES_SW_PATCH_VERSION             0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and Sd_Emmc_Ip_Types header file are of the same vendor */
#if (MEM_43_EEP_INTERNALTYPES_VENDOR_ID != SD_EMMC_IP_TYPES_VENDOR_ID)
    #error "Mem_43_Eep_InternalTypes.h and Sd_Emmc_Ip_Types.h have different vendor ids"
#endif
/* Check if current file and Sd_Emmc_Ip_Types header file are of the same Autosar version */
#if ((MEM_43_EEP_INTERNALTYPES_AR_RELEASE_MAJOR_VERSION    != SD_EMMC_IP_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (MEM_43_EEP_INTERNALTYPES_AR_RELEASE_MINOR_VERSION    != SD_EMMC_IP_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (MEM_43_EEP_INTERNALTYPES_AR_RELEASE_REVISION_VERSION != SD_EMMC_IP_TYPES_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Mem_43_Eep_InternalTypes.h and Sd_Emmc_Ip_Types.h are different"
#endif
/* Check if current file and Sd_Emmc_Ip_Types header file are of the same software version */
#if ((MEM_43_EEP_INTERNALTYPES_SW_MAJOR_VERSION != SD_EMMC_IP_TYPES_SW_MAJOR_VERSION) || \
     (MEM_43_EEP_INTERNALTYPES_SW_MINOR_VERSION != SD_EMMC_IP_TYPES_SW_MINOR_VERSION) || \
     (MEM_43_EEP_INTERNALTYPES_SW_PATCH_VERSION != SD_EMMC_IP_TYPES_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Mem_43_Eep_InternalTypes.h and Sd_Emmc_Ip_Types.h are different"
#endif

/* Check if current file and Usdhc_Ip_Types header file are of the same vendor */
#if (MEM_43_EEP_INTERNALTYPES_VENDOR_ID != USDHC_IP_TYPES_VENDOR_ID_H)
    #error "Mem_43_Eep_InternalTypes.h and Usdhc_Ip_Types.h have different vendor ids"
#endif
/* Check if current file and Usdhc_Ip_Types header file are of the same Autosar version */
#if ((MEM_43_EEP_INTERNALTYPES_AR_RELEASE_MAJOR_VERSION    != USDHC_IP_TYPES_AR_RELEASE_MAJOR_VERSION_H) || \
     (MEM_43_EEP_INTERNALTYPES_AR_RELEASE_MINOR_VERSION    != USDHC_IP_TYPES_AR_RELEASE_MINOR_VERSION_H) || \
     (MEM_43_EEP_INTERNALTYPES_AR_RELEASE_REVISION_VERSION != USDHC_IP_TYPES_AR_RELEASE_REVISION_VERSION_H) \
    )
    #error "AutoSar Version Numbers of Mem_43_Eep_InternalTypes.h and Usdhc_Ip_Types.h are different"
#endif
/* Check if current file and Usdhc_Ip_Types header file are of the same software version */
#if ((MEM_43_EEP_INTERNALTYPES_SW_MAJOR_VERSION != USDHC_IP_TYPES_SW_MAJOR_VERSION_H) || \
     (MEM_43_EEP_INTERNALTYPES_SW_MINOR_VERSION != USDHC_IP_TYPES_SW_MINOR_VERSION_H) || \
     (MEM_43_EEP_INTERNALTYPES_SW_PATCH_VERSION != USDHC_IP_TYPES_SW_PATCH_VERSION_H) \
    )
    #error "Software Version Numbers of Mem_43_Eep_InternalTypes.h and Usdhc_Ip_Types.h are different"
#endif
/*==================================================================================================
*                                             ENUMS
==================================================================================================*/
/**
* @brief          Type of job currently executed by Mem_43_Eep_MainFunction.
*/
typedef enum
{
    /**
    * @brief erase one or more complete mem_eeprom sectors
    */
    MEM_43_EEP_JOB_ERASE = 0,
    /**
    * @brief write one or more complete mem_eeprom pages
    */
    MEM_43_EEP_JOB_WRITE,
    /**
    * @brief read one or more bytes from mem_eeprom memory
    */
    MEM_43_EEP_JOB_READ,
    /**
    * @brief check blank bytes from mem_eeprom memory
    */
    MEM_43_EEP_JOB_BLANKCHECK,
    /**
    * @brief hardware specific service
    */
    MEM_43_EEP_JOB_HWSPECIFICSERVICE
} Mem_43_Eep_JobType;

/**
* @brief           Asynchronous job result type.
*/
typedef enum
{
    /**
    * @brief Has been finished successfully
    */
    MEM_43_EEP_BLANKCHECK_E_OK,
    /**
    * @brief Has not been finished successfully
    */
    MEM_43_EEP_BLANKCHECK_E_NOT_OK,
    /**
    * @brief The checked page is not blank
    */
    MEM_43_EEP_BLANKCHECK_E_INCONSISTENT
} Mem_43_Eep_BlankCheckType;

/**
*           Result of compare operation.
*/
typedef enum
{
    MEM_43_EEP_COMPARE_E_OK,                   /* The data buffer match with content of eeprom memory. */
    MEM_43_EEP_COMPARE_E_FAILED,               /* Read the data from the card failed.*/
    MEM_43_EEP_COMPARE_E_BLOCK_INCONSISTENT,   /* The data buffer doesn't match with content of eeprom memory */
} Mem_43_Eep_CompareCheckType;

/**
* @brief          Size of data to be processeed by CRC.
*
*
*/
typedef enum
{
    MEM_43_EEP_CRC_8_BITS = 0,
    MEM_43_EEP_CRC_16_BITS
} Mem_43_Eep_CrcDataSizeType;


/**
 * @brief          Mem job runtime information Type
 * @details        This structure contains runtime information the current processing job of each Mem instance.
 *
 */
typedef struct
{
/**
* @brief Maximum number of bytes to read in one cycle of Mem_43_Eep_MainFunction
*/
    Mem_43_Eep_LengthType Mem_43_Eep_u32MaxRead;
/**
* @brief Maximum number of bytes to write in one cycle of Mem_43_Eep_MainFunction
*/
    Mem_43_Eep_LengthType Mem_43_Eep_u32MaxWrite;
/**
* @brief Logical address of data block currently processed by Mem_43_Eep_MainFunction
*/
    Mem_43_Eep_AddressType Mem_43_Eep_u32EepromAddrIt;
/**
* @brief Remainin length to be transfered until the end of the job
*/
     Mem_43_Eep_LengthType Mem_43_Eep_u32RemainingLength;
/**
* @brief Result of last mem_43_eeprom module job
*/
    Mem_43_Eep_JobResultType Mem_43_Eep_eJobResult;
/**
* @brief Type of currently executed job (erase, write, read, or blank)
*/
    Mem_43_Eep_JobType Mem_43_Eep_eJob;
/**
* @brief Type of currently executed HwServiceId job (compare) when executing ProcessHwSpecificServiceJob
*/
    Mem_43_Eep_HwServiceIdType    Mem_43_Eep_u32HwServiceIdJob;
/**
* @brief Pointer to current position in source data buffer
*/
    Mem_43_Eep_DataType * Mem_43_Eep_pJobSrcAddrPtr;
/**
* @brief Pointer to current position in target data buffer
*/
    Mem_43_Eep_DataType * Mem_43_Eep_pJobDataDestPtr;
} Mem_43_Eep_JobRuntimeInfoType;


/**
 * @brief          Sector Batch Type
 * @details        Sector Batch data structure for group of identical sectors
 *                 Note: burst sizes equal to normal sizes in case burst disabled
 *
 */
typedef struct
{
    const Mem_43_Eep_AddressType    StartAddress;       /* Physical start address of the sector batch                              */
    const Mem_43_Eep_AddressType    EndAddress;         /* Physical end address of the sector batch                                */
    const uint32                      SectorSize;         /* Size of a sector in bytes in this sector batch (smallest erasable unit) */
    const uint32                      ReadPageSize;       /* Size of a read page of this sector in bytes (smallest readable unit)    */
    const uint32                      WritePageSize;      /* Size of a write page of this sector in bytes (smallest writeable unit)  */
    const uint32                      EraseBurstSize;     /* Size of sector erase burst in bytes (for improved performance)          */
    const uint32                      ReadBurstSize;      /* Size of page read burst in bytes (for improved performance)             */
    const uint32                      WriteBurstSize;     /* Size of page write/program burst in bytes (for improved performance)    */
} Mem_43_Eep_SectorBatchType;

/**
 * @brief          Mem Instance Type
 * @details        Mem Instance data structure
 *
 */
typedef struct
{
    const Mem_43_Eep_InstanceIdType     InstanceId;          /* Unique numeric identifier for each a Mem driver instance           */
    const uint32                          SectorBatchCount;    /* Number of sector batches in this Mem instance                      */
    const Mem_43_Eep_SectorBatchType   *SectorBatches;       /* Point to first element in array of sector batches configurations   */
    const uint8                           MemUnitIndex;        /* Index of flash memory unit used for this Mem instance              */
} Mem_43_Eep_MemInstanceType;


/**
* @brief          Mem_43_Eep Config Type
* @details        Mem_43_Eep module initialization data structure
* @implements     Mem_43_Eep_ConfigType_typedef
*
*/
typedef struct
{   
    /**
    * @brief Point to first element in array of mem instances configurations
    */
    const Mem_43_Eep_MemInstanceType   *MemInstances;
    /**
     * @brief MEM_43_EEP Config Set CRC checksum
     */
    Mem_43_Eep_CrcType u16ConfigCrc;
    /**
      * @brief SD Ip configuration pointer
    **/
    const Sd_Emmc_Ip_ConfigType * pMem_43_EepSdConfig;
} Mem_43_Eep_ConfigType;

/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

#ifdef __cplusplus
}
#endif

#endif /* MEM_43_EEP_INTERNALTYPES_H */

/** @}*/
