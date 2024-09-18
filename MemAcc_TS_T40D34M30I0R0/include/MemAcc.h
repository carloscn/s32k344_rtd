/*==================================================================================================
*   Project              : RTD AUTOSAR 4.7
*   Platform             : CORTEXM
*   Peripheral           : none
*   Dependencies         : MemAcc
*
*   Autosar Version      : 4.7.0
*   Autosar Revision     : ASR_REL_4_7_REV_0000
*   Autosar Conf.Variant :
*   SW Version           : 3.0.0
*   Build Version        : S32K3_RTD_3_0_0_D2303_ASR_REL_4_7_REV_0000_20230331
*
*   (c) Copyright 2020 - 2023 NXP Semiconductors
*   All Rights Reserved.
*
*   NXP Confidential. This software is owned or controlled by NXP and may only be
*   used strictly in accordance with the applicable license terms. By expressly
*   accepting such terms or by downloading, installing, activating and/or otherwise
*   using the software, you are agreeing that you have read, and that you agree to
*   comply with and are bound by, such license terms. If you do not agree to be
*   bound by the applicable license terms, then you may not retain, install,
*   activate or otherwise use the software.
==================================================================================================*/

#ifndef MEMACC_H
#define MEMACC_H

/**
*   @file MemAcc.h
*
*   @addtogroup MEMACC
*   @{
*/

/* implements MemAcc.h_Artifact */

#ifdef __cplusplus
extern "C"{
#endif


/*==================================================================================================
                                         INCLUDE FILES
 1) system and project includes
 2) needed interfaces from external units
 3) internal and external interfaces from this unit
==================================================================================================*/
#include "MemAcc_Cfg.h"
#include "MemAcc_Types.h"


/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define MEMACC_VENDOR_ID                      43
#define MEMACC_AR_RELEASE_MAJOR_VERSION       4
#define MEMACC_AR_RELEASE_MINOR_VERSION       7
#define MEMACC_AR_RELEASE_REVISION_VERSION    0
#define MEMACC_SW_MAJOR_VERSION               3
#define MEMACC_SW_MINOR_VERSION               0
#define MEMACC_SW_PATCH_VERSION               0


/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/


/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/

/**
*  @brief    AUTOSAR module identification
*/
#define MEMACC_MODULE_ID                41U

/**
*  @brief    AUTOSAR module instance identification
*/
#define MEMACC_INSTANCE_ID              0U


/**
* @brief    Development error codes (passed to DET)
*/
#define MEMACC_E_UNINIT                            0x01U  /* API service called without module initialization                                        */
#define MEMACC_E_PARAM_POINTER                     0x02U  /* API service called with NULL pointer argument                                           */
#define MEMACC_E_PARAM_ADDRESS_AREA_ID             0x03U  /* API service called with wrong address area ID                                           */
#define MEMACC_E_PARAM_ADDRESS_LENGTH              0x04U  /* API service called with address and length not belonging to the passed address area ID  */
#define MEMACC_E_PARAM_HW_ID                       0x05U  /* API service called with a hardware ID not belonging to the passed address area ID       */
#define MEMACC_E_BUSY                              0x06U  /* API service called for an address area ID with a pending job request                    */
#define MEMACC_E_MEM_INIT_FAILED                   0x07U  /* Dynamic MEM driver activation failed due to inconsistent MEM driver binary              */
#define MEMACC_E_OK                                0xFFU  /* API service called without errors                                                       */


/**
* @brief    All service IDs (passed to DET)
*/
/* Synchronous Functions */
#define MEMACC_DEINIT_ID                           0x00U  /* Service ID of function MemAcc_DeInit                        */
#define MEMACC_INIT_ID                             0x01U  /* Service ID of function MemAcc_Init                          */
#define MEMACC_GETVERSIONINFO_ID                   0x02U  /* Service ID of function MemAcc_GetVersionInfo                */

#define MEMACC_GETJOBRESULT_ID                     0x05U  /* Service ID of function MemAcc_GetJobResult                  */
#define MEMACC_GETJOBSTATUS_ID                     0x05U  /* Service ID of function MemAcc_GetJobStatus                  */
#define MEMACC_GETMEMORYINFO_ID                    0x06U  /* Service ID of function MemAcc_GetMemoryInfo                 */
#define MEMACC_GETPROCESSEDLENGTH_ID               0x07U  /* Service ID of function MemAcc_GetProcessedLength            */
#define MEMACC_GETJOBINFO_ID                       0x08U  /* Service ID of function MemAcc_GetJobInfo                    */

#define MEMACC_ACTIVATEMEM_ID                      0x14U  /* Service ID of function MemAcc_ActivateMem                   */
#define MEMACC_DEACTIVATEMEM_ID                    0x15U  /* Service ID of function MemAcc_DeactivateMem                 */


/* Asynchronous Functions */
#define MEMACC_CANCEL_ID                           0x04U  /* Service ID of function MemAcc_Cancel                        */
#define MEMACC_READ_ID                             0x09U  /* Service ID of function MemAcc_Read                          */
#define MEMACC_WRITE_ID                            0x0AU  /* Service ID of function MemAcc_Write                         */
#define MEMACC_ERASE_ID                            0x0BU  /* Service ID of function MemAcc_Erase                         */
#define MEMACC_COMPARE_ID                          0x0CU  /* Service ID of function MemAcc_Compare                       */
#define MEMACC_BLANKCHECK_ID                       0x0DU  /* Service ID of function MemAcc_BlankCheck                    */
#define MEMACC_HWSPECIFICSERVICE_ID                0x0EU  /* Service ID of function MemAcc_HwSpecificService             */

#define MEMACC_REQUESTLOCK_ID                      0x11U  /* Service ID of function MemAcc_RequestLock                   */
#define MEMACC_RELEASELOCK_ID                      0x12U  /* Service ID of function MemAcc_ReleaseLock                   */


/* Scheduled Functions */
#define MEMACC_MAINFUNCTION_ID                     0x03U  /* Service ID of function MemAcc_MainFunction                  */


/* Notification Functions */
#define MEMACC_ADDRESSAREAJOBENDNOTIFICATION_ID    0x0FU  /* Service ID of function AddressAreaJobEndNotification */
#define MEMACC_APPLICATIONLOCKNOTIFICATION_ID      0x14U  /* Service ID of function MemAcc_MainFunction           */


/*==================================================================================================
                                          CONSTANTS
==================================================================================================*/


/*==================================================================================================
                                       GLOBAL VARIABLES
==================================================================================================*/

#define MEMACC_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "MemAcc_MemMap.h"

/* Pointer to current memacc module configuration set */
extern const MemAcc_ConfigType            *MemAcc_pConfigPtr;


#define MEMACC_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "MemAcc_MemMap.h"


/*==================================================================================================
                                       GLOBAL FUNCTIONS (Synchronous Functions)
==================================================================================================*/

/**
 * @brief        The function initializes MemAcc module.
 */
void MemAcc_Init(const MemAcc_ConfigType * ConfigPtr);


/**
 * @brief        The function de-initializes the MemAcc module.
 */
void MemAcc_DeInit(void);


/**
 * @brief        Return the version information of the Mem module.
 */
void MemAcc_GetVersionInfo(Std_VersionInfoType * VersionInfoPtr);


/**
 * @brief        Get the most recent job result.
 */
MemAcc_JobResultType MemAcc_GetJobResult(MemAcc_AddressAreaIdType AddressAreaId);


/**
 * @brief        Get the most recent job status.
 */
MemAcc_JobStatusType MemAcc_GetJobStatus(MemAcc_AddressAreaIdType AddressAreaId);


/**
 * @brief        Get the memory information of the referenced address area.
 */
Std_ReturnType MemAcc_GetMemoryInfo (
    MemAcc_AddressAreaIdType    AddressAreaId,
    MemAcc_AddressType          Address,
    MemAcc_MemoryInfoType      *MemoryInfoPtr
);


/**
 * @brief        Get the processed length of data of the referenced address area.
 */
MemAcc_LengthType MemAcc_GetProcessedLength(MemAcc_AddressAreaIdType AddressAreaId);


/**
 * @brief        Get the memory information of the referenced address area.
 */
void MemAcc_GetJobInfo(
    MemAcc_AddressAreaIdType    AddressAreaId,
    MemAcc_JobInfoType         *JobInfoPtr
);


/**
 * @brief        Dynamic activation and initialization of a Mem driver referenced by HwId and HeaderAddress.
 */
Std_ReturnType MemAcc_ActivateMem(
    MemAcc_AddressType    HeaderAddress,
    MemAcc_HwIdType       HwId
);


/**
 * @brief        Dynamic deactivation of a Mem driver referenced by HwId and HeaderAddress.
 */
Std_ReturnType MemAcc_DeactivateMem(
    MemAcc_HwIdType       HwId,
    MemAcc_AddressType    HeaderAddress
);


/*==================================================================================================
                                       GLOBAL FUNCTIONS (Asynchronous Functions)
==================================================================================================*/

/**
 * @brief            Cancel an ongoing job.
 */
void MemAcc_Cancel(MemAcc_AddressAreaIdType AddressAreaId);


/**
 * @brief            Reads from flash memory.
 */
Std_ReturnType MemAcc_Read(
    MemAcc_AddressAreaIdType    AddressAreaId,
    MemAcc_AddressType          SourceAddress,
    MemAcc_DataType            *DestinationDataPtr,
    MemAcc_LengthType           Length
);

/**
 * @brief            Writes to flash memory.
 */
Std_ReturnType MemAcc_Write(
    MemAcc_AddressAreaIdType     AddressAreaId,
    MemAcc_AddressType           TargetAddress,
    const MemAcc_DataType       *SourceDataPtr,
    MemAcc_LengthType            Length
);


/**
 * @brief            Erase one or more complete flash sectors.
 */
Std_ReturnType MemAcc_Erase(
    MemAcc_AddressAreaIdType    AddressAreaId,
    MemAcc_AddressType          TargetAddress,
    MemAcc_LengthType           Length
);


#if (MEMACC_COMPARE_API == STD_ON)

/**
 * @brief            Compares a flash memory area with an application data buffer.
 */
Std_ReturnType MemAcc_Compare(
    MemAcc_AddressAreaIdType    AddressAreaId,
    MemAcc_AddressType          SourceAddress,
    const MemAcc_DataType      *DataPtr,
    MemAcc_LengthType           Length
);

#endif


/**
 * @brief            Verify whether a given memory area has been erased but not (yet) programmed.
 */
Std_ReturnType MemAcc_BlankCheck(
    MemAcc_AddressAreaIdType    AddressAreaId,
    MemAcc_AddressType          TargetAddress,
    MemAcc_LengthType           Length
);


/**
 * @brief            Trigger a hardware specific service.
 */
Std_ReturnType MemAcc_HwSpecificService(
    MemAcc_AddressAreaIdType     AddressAreaId,
    MemAcc_HwIdType              HwId,
    MemAcc_MemHwServiceIdType    HwServiceId,
    MemAcc_DataType             *DataPtr,
    MemAcc_LengthType           *LengthPtr
);


/**
 * @brief            Request lock of an address area for exclusive access.
 */
Std_ReturnType MemAcc_RequestLock(
    MemAcc_AddressAreaIdType            AddressAreaId,
    MemAcc_AddressType                  Address,
    MemAcc_AddressType                  Length,
    MemAcc_ApplicationLockNotification  LockNotificationFctPtr
);


/**
 * @brief            Release access lock of provided address area.
 */
Std_ReturnType MemAcc_ReleaseLock(
    MemAcc_AddressAreaIdType    AddressAreaId,
    MemAcc_AddressType          Address,
    MemAcc_AddressType          Length
);


#ifdef __cplusplus
}
#endif

/** @} */

#endif /* MEMACC_H */
