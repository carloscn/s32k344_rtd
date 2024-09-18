
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
*   (c) Copyright 2020 - 2023 NXP Semiconductors
*   All Rights Reserved.
*
* NXP Confidential. This software is owned or controlled by NXP and may only be
* used strictly in accordance with the applicable license terms. By expressly
* accepting such terms or by downloading, installing, activating and/or otherwise
* using the software, you are agreeing that you have read, and that you agree to
* comply with and are bound by, such license terms. If you do not agree to be
* bound by the applicable license terms, then you may not retain, install,
* activate or otherwise use the software.
==================================================================================================*/

#ifndef MEM_43_EEP_H
#define MEM_43_EEP_H

/**
* @file
*
* @addtogroup MEM_43_EEP_DRIVER Mem_43_Eeprom Driver
* @{
*/
/* implements Mem_43_Eep.h_Artifact */
#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
                                         INCLUDE FILES
 1) system and project includes
 2) needed interfaces from external units
 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Mem_43_Eep_Cfg.h"
#include "Mem_43_Eep_InternalTypes.h"
#include "SchM_Mem_43_Eep.h"
#include "StandardTypes.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define MEM_43_EEP_VENDOR_ID            43
#define MEM_43_EEP_MODULE_ID            90
#define MEM_43_EEP_AR_RELEASE_MAJOR_VERSION     4
#define MEM_43_EEP_AR_RELEASE_MINOR_VERSION     7
#define MEM_43_EEP_AR_RELEASE_REVISION_VERSION  0
#define MEM_43_EEP_SW_MAJOR_VERSION             3
#define MEM_43_EEP_SW_MINOR_VERSION             0
#define MEM_43_EEP_SW_PATCH_VERSION             0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/

/* Check if header file and Mem_43_Eep_Cfg.h header file are of the same vendor */
#if (MEM_43_EEP_VENDOR_ID != MEM_43_EEP_VENDOR_ID_CFG)
    #error "Mem_43_Eep.h and Mem_43_Eep_Cfg.h have different vendor ids"
#endif
/* Check if header file and Mem_43_Eep_Cfg.h header file are of the same Autosar version */
#if ((MEM_43_EEP_AR_RELEASE_MAJOR_VERSION    != MEM_43_EEP_AR_RELEASE_MAJOR_VERSION_CFG) || \
     (MEM_43_EEP_AR_RELEASE_MINOR_VERSION    != MEM_43_EEP_AR_RELEASE_MINOR_VERSION_CFG) || \
     (MEM_43_EEP_AR_RELEASE_REVISION_VERSION != MEM_43_EEP_AR_RELEASE_REVISION_VERSION_CFG) \
    )
    #error "AutoSar Version Numbers of Mem_43_Eep.h and Mem_43_Eep_Cfg.h are different"
#endif
/* Check if header file and Mem_43_Eep_Cfg.h header file are of the same software version */
#if ((MEM_43_EEP_SW_MAJOR_VERSION != MEM_43_EEP_SW_MAJOR_VERSION_CFG) || \
     (MEM_43_EEP_SW_MINOR_VERSION != MEM_43_EEP_SW_MINOR_VERSION_CFG) || \
     (MEM_43_EEP_SW_PATCH_VERSION != MEM_43_EEP_SW_PATCH_VERSION_CFG) \
    )
    #error "Software Version Numbers of Mem_43_Eep.h and Mem_43_Eep_Cfg.h are different"
#endif

/* Check if header file and Mem_43_Eep_InternalTypes.h header file are of the same vendor */
#if (MEM_43_EEP_VENDOR_ID != MEM_43_EEP_INTERNALTYPES_VENDOR_ID)
    #error "Mem_43_Eep.h and Mem_43_Eep_InternalTypes.h have different vendor ids"
#endif
/* Check if header file and Mem_43_Eep_InternalTypes.h header file are of the same Autosar version */
#if ((MEM_43_EEP_AR_RELEASE_MAJOR_VERSION    != MEM_43_EEP_INTERNALTYPES_AR_RELEASE_MAJOR_VERSION) || \
     (MEM_43_EEP_AR_RELEASE_MINOR_VERSION    != MEM_43_EEP_INTERNALTYPES_AR_RELEASE_MINOR_VERSION) || \
     (MEM_43_EEP_AR_RELEASE_REVISION_VERSION != MEM_43_EEP_INTERNALTYPES_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Mem_43_Eep.h and Mem_43_Eep_InternalTypes.h are different"
#endif
/* Check if header file and Mem_43_Eep_InternalTypes.h header file are of the same software version */
#if ((MEM_43_EEP_SW_MAJOR_VERSION != MEM_43_EEP_INTERNALTYPES_SW_MAJOR_VERSION) || \
     (MEM_43_EEP_SW_MINOR_VERSION != MEM_43_EEP_INTERNALTYPES_SW_MINOR_VERSION) || \
     (MEM_43_EEP_SW_PATCH_VERSION != MEM_43_EEP_INTERNALTYPES_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Mem_43_Eep.h and Mem_43_Eep_InternalTypes.h are different"
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if current file and StandardTypes.h file are of the same version */
    #if ((MEM_43_EEP_AR_RELEASE_MAJOR_VERSION != STD_AR_RELEASE_MAJOR_VERSION) || \
         (MEM_43_EEP_AR_RELEASE_MINOR_VERSION != STD_AR_RELEASE_MINOR_VERSION)\
        )
        #error "AutoSar Version Numbers of Mem_43_Eep.h and StandardTypes.h are different"
    #endif
    /* Check if current file and SchM_Mem_43_Eep.h file are of the same version */
    #if ((MEM_43_EEP_AR_RELEASE_MAJOR_VERSION != SCHM_MEM_43_EEP_AR_RELEASE_MAJOR_VERSION) || \
         (MEM_43_EEP_AR_RELEASE_MINOR_VERSION != SCHM_MEM_43_EEP_AR_RELEASE_MINOR_VERSION)\
        )
        #error "AutoSar Version Numbers of Mem_43_Eep.h and SchM_Mem_43_Eep.h are different"
    #endif
#endif


/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/
/**
* @brief          Development error codes (passed to DET).
*
*/
/**
*   @brief service ID of error: API service called without module initialization. (passed to DET)
*/
#define MEM_43_EEP_E_UNINIT                 0x01U
/**
*   @brief service ID of error:  NULL_PTR passed. (passed to DET)
*/
#define MEM_43_EEP_E_PARAM_POINTER          0x02U
/**
*   @brief service ID of error: TargetAddress is not in range and aligned to first byte of mem_43_eeprom sector. (passed to DET)
*/
#define MEM_43_EEP_E_PARAM_ADDRESS          0x03U
/**
*   @brief service ID of error: TargetAddress is not in range and aligned to last byte of mem_43_eeprom sector. (passed to DET)
*/
#define MEM_43_EEP_E_PARAM_LENGTH           0x04U
/**
*   @brief service ID of error:  invalid instace id passed. (passed to DET)
*/
#define MEM_43_EEP_E_PARAM_INSTANCE_ID      0x05U
/**
*   @brief service ID of error:  invalid instace id passed. (passed to DET)
*/
#define MEM_43_EEP_E_JOB_PENDING            0x06U
/**
*   @brief service ID of error: The hardware operation did not finish before timeout expired. (passed to DET)
*/
#define MEM_43_EEP_E_TIMEOUT                0x07U

/**
* @brief          All service IDs (passed to DET).
*
*/
#define MEM_43_EEP_INIT_ID                  0x01U
#define MEM_43_EEP_DEINIT_ID                0x0BU
#define MEM_43_EEP_GETVERSIONINFO_ID        0x02U
#define MEM_43_EEP_GETJOBRESULT_ID          0x04U
#define MEM_43_EEP_SUSPEND_ID               0x0CU
#define MEM_43_EEP_RESUME_ID                0x0DU
#define MEM_43_EEP_PROPRAGATEERROR_ID       0x08U
#define MEM_43_EEP_READ_ID                  0x05U
#define MEM_43_EEP_WRITE_ID                 0x06U
#define MEM_43_EEP_ERASE_ID                 0x07U
#define MEM_43_EEP_BLANKCHECK_ID            0x09U
#define MEM_43_EEP_HWSPECIFICSERVICE_ID     0x0AU
#define MEM_43_EEP_MAINFUNCTION_ID          0x03U

#define E_MEM_SERVICE_NOT_AVAIL          0x02U

/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/

/**
* @brief    Start of Mem_43_Eep section CODE
*/
#define MEM_43_EEP_START_SEC_CODE
#include "Mem_43_Eep_MemMap.h"

/**
* @brief        The function initializes Mem_43_Eep module.
* @details      The function sets the internal module variables according to given
*               configuration set.
*
* @param[in]    ConfigPtr        Pointer to mem_43_eeprom driver configuration set.
*
* @api
*
* @pre          @p ConfigPtr must not be @p NULL_PTR
**
*/
void Mem_43_Eep_Init(const Mem_43_Eep_ConfigType * ConfigPtr);

/**
* @brief        The function deinitializes Mem_43_Eep module.
* @details      The function sets the internal module variables to null.
*
* @param[in]    None
*
* @api
**
*/
void Mem_43_Eep_DeInit(void);

#if (MEM_43_EEP_WRITE_API == STD_ON)
/**
* @brief            Write one or more complete mem_43_eeprom pages to the mem_43_eeprom device.
* @details          Triggers a write job to store the passed data to the provided address area with given address
*                   and length. The result of this service can be retrieved using the Mem_GetJobResult API. If the
*                   write operation was successful, the job result is MEM_JOB_OK. If there was an issue writing
*                   the data, the result is MEM_FAILED.
*
* @param[in]        instanceId            ID of the related memory driver instance.
* @param[in]        targetAddress        Physical erase address (aligned to sector size).
* @param[in]        sourceDataPtr        Source data pointer (aligned to page size).
* @param[in]        length               Write length in bytes (aligned to sector size).
* @param[inout]     None
* @param[out]       None
*
* @return           Std_ReturnType
* @retval           E_OK                      The requested job has been accepted by the module.
* @retval           E_NOT_OK                  The requested job has not been accepted by the module.
* @retval           E_MEM_SERVICE_NOT_AVAIL   The service function is not implemented.
*
* @api
*
* @pre              The module has to be initialized and not busy.
* @post
*
*/
Std_ReturnType Mem_43_Eep_Write(Mem_43_Eep_InstanceIdType instanceId,
                             Mem_43_Eep_AddressType targetAddress,
                             const Mem_43_Eep_DataType* sourceDataPtr,
                             Mem_43_Eep_LengthType length);
#endif

#if (MEM_43_EEP_ERASE_API == STD_ON)
/**
* @brief            Erase memory by writing erase value.
* @details          Triggers an erase job of the given sector/sector batch defined by targetAddress and length. The
*                   result of this service can be retrieved using the Mem_GetJobResult API. If the erase operation
*                   was successful, the result of the job is MEM_JOB_OK. If the erase operation failed, e.g. due to
*                   a hardware issue, the result of the job is MEM_JOB_FAILED.
*
* @param[in]        instanceId            ID of the related memory driver instance.
* @param[in]        targetAddress        Physical erase address (aligned to sector size).
* @param[in]        length               Erase length in bytes (aligned to sector size).
* @param[inout]     None
* @param[out]       None
*
* @return           Std_ReturnType
* @retval           E_OK                      The requested job has been accepted by the module.
* @retval           E_NOT_OK                  The requested job has not been accepted by the module.
* @retval           E_MEM_SERVICE_NOT_AVAIL   The service function is not implemented.
*
* @api
*
* @pre              The module has to be initialized and not busy.
* @post
*
*/
Std_ReturnType Mem_43_Eep_Erase(Mem_43_Eep_InstanceIdType instanceId,
                             Mem_43_Eep_AddressType targetAddress,
                             Mem_43_Eep_LengthType length);
#endif

#if (MEM_43_EEP_SUSPEND_API == STD_ON)
/**
* @brief            Suspend an ongoing mem_43_eeprom read job.
* @details          Suspend active memory operation using hardware mechanism.
*
* @param[in]        instanceId        ID of the related memory driver instance.
* @param[inout]     None
* @param[out]       None
*
* @return           None
*
* @api
*
* @pre              The module must be initialized.
* @post             @p Mem_43_Eep_Suspend changes module status and @p Mem_43_Eep_eJobRuntimeInfo[InstanceIndex].Mem_43_Eep_eJobResult
*                   internal variable.
*/
void Mem_43_Eep_Suspend(Mem_43_Eep_InstanceIdType instanceId);
#endif

#if (MEM_43_EEP_RESUME_API == STD_ON)
/**
* @brief            Resume a suspended mem_43_eeprom read job.
* @details          Resume suspended memory operation using hardware mechanism.
*
* @param[in]        instanceId        ID of the related memory driver instance.
* @param[inout]     None
* @param[out]       None
*
* @return           None
*
* @api
*
* @pre              The module must be initialized.
* @post             @p Mem_43_Eep_Resume changes module status and @p Mem_43_Eep_eJobRuntimeInfo[InstanceIndex].Mem_43_Eep_eJobResult
*                   internal variable.
*
*/
void Mem_43_Eep_Resume(Mem_43_Eep_InstanceIdType instanceId);
#endif

#if (MEM_43_EEP_GET_JOB_RESULT_API == STD_ON)
/**
* @brief            Performs actual mem_43_eeprom read, write, erase and compare jobs.
* @pre              The module has to be initialized.
* @param[in]        Job  Currently executed job (erase, write, read, or compare)
*
* @return           Mem_43_Eep_JobResultType
* @retval           MEM_43_EEP_JOB_OK              Successfully completed job.
* @retval           MEM_43_EEP_JOB_FAILED          Not successfully completed job.
* @retval           MEM_43_EEP_JOB_PENDING         Still pending job (not yet completed).
* @retval           MEM_43_EEP_JOB_OK              Job has been canceled.
* @retval           MEM_43_EEP_INCONSISTENT        Inconsistent block requested, it may
*                                             contains corrupted data.
**/
Mem_43_Eep_JobResultType Mem_43_Eep_GetJobResult(Mem_43_Eep_InstanceIdType InstanceId);
#endif

#if (MEM_43_EEP_PROPAGATEERROR_API == STD_ON)
/**
* @brief            Provide access error information.
* @details          This service can be used to report an access error in case the Mem driver cannot provide the
*                   access error information - typically for ECC faults. It is called by the system ECC handler to
*                   propagate an ECC error to the memory upper layers..
*
* @param[in]        instanceId        ID of the related memory driver instance.
* @param[inout]     None
* @param[out]       None
*
* @return           None
*
* @api
*
* @pre              The module must be initialized.
* @post             @p Mem_43_Eep_PropagateError changes module status and @p Mem_43_Eep_eJobRuntimeInfo[InstanceIndex].Mem_43_Eep_eJobResult
*                   internal variable.
*
*/
void Mem_43_Eep_PropagateError(Mem_43_Eep_InstanceIdType instanceId);
#endif

#if (MEM_43_EEP_READ_API == STD_ON)
/**
* @brief            Reads from mem_43_eeprom memory.
* @details          Starts a read job asynchronously. The actual job is performed by @p Mem_43_Eep_MainFunction.
*                   Triggers a read job to copy the from the source address into the referenced destination data
*                   buffer. The result of this service can be retrieved using the Mem_GetJobResult API. If the read
*                   operation was successful, the result of the job is MEM_JOB_OK. If the read operation failed,
*                   the result of the job is either MEM_JOB_FAILED in case of a general error or 
*                   MEM_ECC_CORRECTED/MEM_ECC_UNCORRECTED in case of a correctable/uncorrectable ECC error.
*
* @param[in]        instanceId            ID of the related memory driver instance.
* @param[in]        sourceAddress        Physical address to read data from.
* @param[in]        length               Number of bytes to read.
* @param[inout]     None
* @param[out]       destinationDataPtr   Destination memory pointer to store the read data.
*
* @return           Std_ReturnType
* @retval           E_OK                      The requested job has been accepted by the module.
* @retval           E_NOT_OK                  The requested job has not been accepted by the module.
* @retval           E_MEM_SERVICE_NOT_AVAIL   The service function is not implemented.
*
* @api
*
* @pre            The module has to be initialized and not busy.
* @post
*
*/
Std_ReturnType Mem_43_Eep_Read(Mem_43_Eep_InstanceIdType instanceId,
                            Mem_43_Eep_AddressType sourceAddress,
                            Mem_43_Eep_DataType* destinationDataPtr,
                            Mem_43_Eep_LengthType length);
#endif

#if (MEM_43_EEP_BLANKCHECK_API == STD_ON)
/**
* @brief            Check blank memory by checking against erased value.
* @details          Triggers a job to check the erased state of the page which is referenced by targetAddress. The
*                   result of this service can be retrieved using the Mem_GetJobResult API. If the checked page is
*                   blank, the result of the job is MEM_43_EEP_JOB_OK. Otherwise, if the page is not blank, the result is
*                   MEM_43_EEP_INCONSISTENT.
*
* @param[in]        instanceId            ID of the related memory driver instance.
* @param[in]        targetAddress        Physical blank check addres.
* @param[in]        length               Blank check length.
* @param[inout]     None
* @param[out]       None
*
* @return           Std_ReturnType
* @retval           E_OK                      The requested job has been accepted by the module.
* @retval           E_NOT_OK                  The requested job has not been accepted by the module.
* @retval           E_MEM_SERVICE_NOT_AVAIL   The service function is not implemented.
*
* @api
*
* @pre              The module has to be initialized and not busy. 
* @post
*
*/
Std_ReturnType Mem_43_Eep_BlankCheck(Mem_43_Eep_InstanceIdType instanceId,
                                  Mem_43_Eep_AddressType targetAddress,
                                  Mem_43_Eep_LengthType length);
#endif

#if (MEM_43_EEP_HWSPECIFICSERVICE_API == STD_ON)
/**
* @brief            Triggers a hardware specific memory driver job. dataPtr can be used to pass and return data to/from this service.
* @details          This service is just a dispatcher to the hardware specific service implementation referenced by hwServiceId. 
*                   The result of this service can be retrieved using the Mem_43_Eep_GetJobResult API. If the hardware specific 
*                   operation was successful, the result of the job is MEM_43_EEP_JOB_OK. If the hardware specific operation failed, 
*                   the result of the job is MEM_43_EEP_JOB_FAILED.
*
* @param[in]        instanceId          ID of the related memory driver instance.
* @param[in]        hwServiceId        Hardware specific service request identifier for dispatching the request.
* @param[in]        dataPtr            Request specific data pointer.
* @param[in]        lengthPtr          Size pointer of the data passed by dataPtr.
* @param[inout]     None
* @param[out]       None
*
* @return           Std_ReturnType
* @retval           E_OK                      The requested job has been accepted by the module.
* @retval           E_NOT_OK                  The requested job has not been accepted by the module.
* @retval           E_MEM_SERVICE_NOT_AVAIL   The service function is not implemented.
*
* @api
*
* @pre              The module has to be initialized and not busy.
* @post
*
*/
Std_ReturnType Mem_43_Eep_HwSpecificService (Mem_43_Eep_InstanceIdType instanceId,
                                          Mem_43_Eep_HwServiceIdType hwServiceId,
                                          Mem_43_Eep_DataType* dataPtr,
                                          Mem_43_Eep_LengthType* lengthPtr);
#endif

#if (MEM_43_EEP_VERSION_INFO_API == STD_ON)
/**
* @brief        Returns version information about MEM_43_EEP module.
* @details      Version information includes:
*               - Module Id
*               - Vendor Id
*               - Vendor specific version numbers (BSW00407).
*
* @param[in,out] versioninfo  Pointer to where to store the version information of this module.
*
* @api
**
*/
void Mem_43_Eep_GetVersionInfo(Std_VersionInfoType * versionInfoPtr);
#endif

/*==================================================================================================
                                       GLOBAL FUNCTIONS (Scheduled Functions)
==================================================================================================*/

/**
 * @brief            Service to handle the requested jobs and the internal management operations.
 */
void Mem_43_Eep_MainFunction(void);

/**
* @brief    Stop of Mem_43_Eep section CODE
*/
#define MEM_43_EEP_STOP_SEC_CODE
#include "Mem_43_Eep_MemMap.h"

#ifdef __cplusplus
}
#endif
#endif /* MEM_43_EEP_H */

/** @} */
