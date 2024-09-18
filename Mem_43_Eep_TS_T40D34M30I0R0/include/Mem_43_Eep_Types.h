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

#ifndef MEM_43_EEP_TYPES_H
#define MEM_43_EEP_TYPES_H

/**
*   @file Mem_43_EepTypes.h
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
#include "StandardTypes.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define MEM_43_EEP_TYPES_VENDOR_ID                    43
#define MEM_43_EEP_TYPES_AR_RELEASE_MAJOR_VERSION     4
#define MEM_43_EEP_TYPES_AR_RELEASE_MINOR_VERSION     7
#define MEM_43_EEP_TYPES_AR_RELEASE_REVISION_VERSION  0
#define MEM_43_EEP_TYPES_SW_MAJOR_VERSION             3
#define MEM_43_EEP_TYPES_SW_MINOR_VERSION             0
#define MEM_43_EEP_TYPES_SW_PATCH_VERSION             0

/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if current file and Std_Types.h file are of the same version */
    #if ((MEM_43_EEP_TYPES_AR_RELEASE_MAJOR_VERSION != STD_AR_RELEASE_MAJOR_VERSION) || \
         (MEM_43_EEP_TYPES_AR_RELEASE_MINOR_VERSION != STD_AR_RELEASE_MINOR_VERSION)\
        )
        #error "AutoSar Version Numbers of MEM_43_EEP_TYPES.h and Std_Types.h are different"
    #endif
#endif

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/


/*==================================================================================================
                                 STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/
/**
* @brief          Mem_43_Eep CRC Type.
* @details        CRC computed over config set.
*
*/
typedef uint16 Mem_43_Eep_CrcType;

/**
* @brief          Mem_43_Eep Address Type.
* @details        Physical memory device address type.
*
* @implements     Mem_43_Eep_AddressType_typedef
*/
typedef uint32 Mem_43_Eep_AddressType;

/**
* @brief          Mem_43_Eep Data Type.
* @details        Read data user buffer type.
*
* @implements     Mem_43_Eep_DataType_typedef
*/
typedef uint8 Mem_43_Eep_DataType;

/**
* @brief          Mem_43_Eep InstanceId Type.
* @details        Job end notification function called by Mem in case the job processing is
*                 configured for job end notification.
*
* @implements     Mem_43_Eep_InstanceIdType_typedef
*/
typedef uint32 Mem_43_Eep_InstanceIdType;

/**
* @brief           Asynchronous job result type.
* @implements     Mem_43_Eep_JobResultType_typedef
*/
typedef enum
{
    /**
    * @brief The last job has been finished successfully
    */
    MEM_43_EEP_JOB_OK,
    /**
    * @brief A job is currently being processed
    */
    MEM_43_EEP_JOB_PENDING,
    /**
    * @brief Job failed for some unspecific reason
    */
    MEM_43_EEP_JOB_FAILED,
    /**
    * @brief The checked page is not blank
    */
    MEM_43_EEP_INCONSISTENT,
    /**
    * @brief Uncorrectable ECC errors occurred during memory access
    */
    MEM_43_EEP_ECC_UNCORRECTED,
    /**
    * @brief Correctable ECC errors occurred during memory access
    */
    MEM_43_EEP_ECC_CORRECTED
} Mem_43_Eep_JobResultType;

/**
* @brief          Mem_43_Eep Length Type.
* @details        Number of bytes to read,write,erase,compare
*
* @implements     Mem_43_Eep_LengthType_typedef
*/
typedef uint32 Mem_43_Eep_LengthType;

/**
* @brief          Mem_43_Eep HwServiceId Type
* @details        Job end notification function called by Mem in case the job processing is
*                 configured for job end notification.
*
* @implements     Mem_43_Eep_HwServiceIdType_typedef
*/
typedef uint32 Mem_43_Eep_HwServiceIdType;

#ifdef __cplusplus
}
#endif

#endif /* MEM_43_EEP_TYPES_H */

/** @}*/
