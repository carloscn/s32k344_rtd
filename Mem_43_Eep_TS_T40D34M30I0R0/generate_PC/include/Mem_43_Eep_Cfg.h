
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
#ifndef MEM_43_EEP_CFG_H
#define MEM_43_EEP_CFG_H

/**
*   @file Mem_43_Eep_Cfg.h
*
*   @addtogroup MEM_43_EEP
*   @{
*/

#ifdef __cplusplus
extern "C"{
#endif

[!INDENT "0"!][!//
/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Mem_43_Eep_Types.h"
#include "Mem_43_Eep_InternalTypes.h"
#include "StandardTypes.h"
#include "Mcal.h"
[!ENDINDENT!][!//
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define MEM_43_EEP_VENDOR_ID_CFG                    43
#define MEM_43_EEP_AR_RELEASE_MAJOR_VERSION_CFG     4
#define MEM_43_EEP_AR_RELEASE_MINOR_VERSION_CFG     7
#define MEM_43_EEP_AR_RELEASE_REVISION_VERSION_CFG  0
#define MEM_43_EEP_SW_MAJOR_VERSION_CFG             3
#define MEM_43_EEP_SW_MINOR_VERSION_CFG             0
#define MEM_43_EEP_SW_PATCH_VERSION_CFG             0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and Mem_43_Eep configuration header file are of the same vendor */
#if (MEM_43_EEP_TYPES_VENDOR_ID != MEM_43_EEP_VENDOR_ID_CFG)
    #error "Mem_43_Eep_Types.h and Mem_43_Eep_Cfg.h have different vendor ids"
#endif
/* Check if current file and Mem_43_Eep configuration header file are of the same Autosar version */
#if ((MEM_43_EEP_TYPES_AR_RELEASE_MAJOR_VERSION    != MEM_43_EEP_AR_RELEASE_MAJOR_VERSION_CFG) || \
     (MEM_43_EEP_TYPES_AR_RELEASE_MINOR_VERSION    != MEM_43_EEP_AR_RELEASE_MINOR_VERSION_CFG) || \
     (MEM_43_EEP_TYPES_AR_RELEASE_REVISION_VERSION != MEM_43_EEP_AR_RELEASE_REVISION_VERSION_CFG) \
    )
    #error "AutoSar Version Numbers of Mem_43_Eep_Types.h and Mem_43_Eep_Cfg.h are different"
#endif
/* Check if current file and Mem_43_Eep configuration header file are of the same software version */
#if ((MEM_43_EEP_TYPES_SW_MAJOR_VERSION != MEM_43_EEP_SW_MAJOR_VERSION_CFG) || \
     (MEM_43_EEP_TYPES_SW_MINOR_VERSION != MEM_43_EEP_SW_MINOR_VERSION_CFG) || \
     (MEM_43_EEP_TYPES_SW_PATCH_VERSION != MEM_43_EEP_SW_PATCH_VERSION_CFG) \
    )
    #error "Software Version Numbers of Mem_43_Eep_Types.h and Mem_43_Eep_Cfg.h are different"
#endif

/* Check if current file and Mem_43_Eep configuration header file are of the same vendor */
#if (MEM_43_EEP_INTERNALTYPES_VENDOR_ID != MEM_43_EEP_VENDOR_ID_CFG)
    #error "Mem_43_Eep_InternalTypes.h and Mem_43_Eep_Cfg.h have different vendor ids"
#endif
/* Check if current file and Mem_43_Eep configuration header file are of the same Autosar version */
#if ((MEM_43_EEP_INTERNALTYPES_AR_RELEASE_MAJOR_VERSION    != MEM_43_EEP_AR_RELEASE_MAJOR_VERSION_CFG) || \
     (MEM_43_EEP_INTERNALTYPES_AR_RELEASE_MINOR_VERSION    != MEM_43_EEP_AR_RELEASE_MINOR_VERSION_CFG) || \
     (MEM_43_EEP_INTERNALTYPES_AR_RELEASE_REVISION_VERSION != MEM_43_EEP_AR_RELEASE_REVISION_VERSION_CFG) \
    )
    #error "AutoSar Version Numbers of Mem_43_Eep_InternalTypes.h and Mem_43_Eep_Cfg.h are different"
#endif
/* Check if current file and Mem_43_Eep configuration header file are of the same software version */
#if ((MEM_43_EEP_INTERNALTYPES_SW_MAJOR_VERSION != MEM_43_EEP_SW_MAJOR_VERSION_CFG) || \
     (MEM_43_EEP_INTERNALTYPES_SW_MINOR_VERSION != MEM_43_EEP_SW_MINOR_VERSION_CFG) || \
     (MEM_43_EEP_INTERNALTYPES_SW_PATCH_VERSION != MEM_43_EEP_SW_PATCH_VERSION_CFG) \
    )
    #error "Software Version Numbers of Mem_43_Eep_InternalTypes.h and Mem_43_Eep_Cfg.h are different"
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if current file and StandardTypes header file are of the same Autosar version */
    #if ((MEM_43_EEP_AR_RELEASE_MAJOR_VERSION_CFG != STD_AR_RELEASE_MAJOR_VERSION) || \
         (MEM_43_EEP_AR_RELEASE_MINOR_VERSION_CFG != STD_AR_RELEASE_MINOR_VERSION) \
        )
        #error "AutoSar Version Numbers of Mem_43_Eep_Cfg.h and StandardTypes.h are different"
    #endif
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if current file and Mcal header file are of the same version */
    #if ((MEM_43_EEP_AR_RELEASE_MAJOR_VERSION_CFG != MCAL_AR_RELEASE_MAJOR_VERSION) || \
         (MEM_43_EEP_AR_RELEASE_MINOR_VERSION_CFG != MCAL_AR_RELEASE_MINOR_VERSION) \
        )
        #error "AutoSar Version Numbers of Mem_43_Eep_Cfg.h and Mcal.h are different"
    #endif
#endif

/*==================================================================================================
                                       DEFINES AND MACROS
==================================================================================================*/

/* Pre-processor switch to enable and disable development error detection */
#define MEM_43_EEP_DEV_ERROR_DETECT        [!IF "MemGeneral/MemDevErrorDetect"!](STD_ON)[!ELSE!](STD_OFF)[!ENDIF!]

/* Pre-processor value for driver istance id*/
/* Mem Instances ID */
[!LOOP "MemInstance/*"!][!//
#define MEM_43_EEP_INSTANCE_[!"node:pos(.)"!]_ID            (Mem_43_Eep_InstanceIdType)([!"./MemInstanceId"!]U)
[!ENDLOOP!][!//

/* Number of configured Mem instances */
#define MEM_43_EEP_INSTANCE_COUNT                           ([!"num:i( count(MemInstance/*) )"!]U)

/* The maximum number of bytes to read in one cycle */
#define MEM_43_EEP_MAX_READ_BLOCK_SIZE                      ([!"num:i(Mem_43_EepInitConfiguration/Mem_43_EepMaxReadBlockSize)"!])

/* The maximum number of bytes to write in one cycle */
#define MEM_43_EEP_MAX_WRITE_BLOCK_SIZE                     ([!"num:i(Mem_43_EepInitConfiguration/Mem_43_EepMaxWriteBlockSize)"!])

/* Compile switch to enable and disable the Mem_43_Eep_Suspend function */
#define MEM_43_EEP_SUSPEND_API             [!IF "AutosarExt/Mem_43_EepSuspendApi"!](STD_ON)[!ELSE!](STD_OFF)[!ENDIF!]

/* Compile switch to enable and disable the Mem_43_Eep_Resume function */
#define MEM_43_EEP_RESUME_API              [!IF "AutosarExt/Mem_43_EepResumeApi"!](STD_ON)[!ELSE!](STD_OFF)[!ENDIF!]

/* Compile switch to enable and disable the Mem_43_Eep_PropageError function */
#define MEM_43_EEP_PROPAGATEERROR_API      [!IF "AutosarExt/Mem_43_EepPropageErrorApi"!](STD_ON)[!ELSE!](STD_OFF)[!ENDIF!]

/* Compile switch to enable and disable the Mem_43_Eep_Erase function */
#define MEM_43_EEP_ERASE_API               [!IF "AutosarExt/Mem_43_EepEraseApi"!](STD_ON)[!ELSE!](STD_OFF)[!ENDIF!]

/* Compile switch to enable and disable the Mem_43_Eep_Write function */
#define MEM_43_EEP_WRITE_API               [!IF "AutosarExt/Mem_43_EepWriteApi"!](STD_ON)[!ELSE!](STD_OFF)[!ENDIF!]

/* Compile switch to enable and disable the Mem_43_Eep_Read function */
#define MEM_43_EEP_READ_API                [!IF "AutosarExt/Mem_43_EepReadApi"!](STD_ON)[!ELSE!](STD_OFF)[!ENDIF!]

/* Compile switch to enable and disable the Mem_43_Eep_BlankCheck function */
#define MEM_43_EEP_BLANKCHECK_API          [!IF "AutosarExt/Mem_43_EepBankCheckApi"!](STD_ON)[!ELSE!](STD_OFF)[!ENDIF!]

/* Compile switch to enable and disable the Mem_43_Eep_HwSpecificService function */
/* MEM_43_EEP_HWSPECIFICSERVICE_API = STD_ON if at least a ServiceId is enabled. Currently only support compare service */
#define MEM_43_EEP_HWSPECIFICSERVICE_API   [!IF "AutosarExt/Mem_43_EepServiceCompare"!](STD_ON)[!ELSE!](STD_OFF)[!ENDIF!]

/* Compile switch to enable and disable the Mem_43_EepServiceCompare feature */
#define MEM_43_EEP_SERVICE_COMPARE         [!IF "AutosarExt/Mem_43_EepServiceCompare"!](STD_ON)[!ELSE!](STD_OFF)[!ENDIF!]

#if (MEM_43_EEP_SERVICE_COMPARE == STD_ON)
/* Define ServiceId for Compare feature */
#define MEM_43_EEP_HWSERVICEID_COMPARE     (0x00U)
#endif

/* Compile switch to enable and disable the Mem_43_Eep_GetJobResult function */
#define MEM_43_EEP_GET_JOB_RESULT_API      [!IF "AutosarExt/Mem_43_EepGetJobResultApi"!](STD_ON)[!ELSE!](STD_OFF)[!ENDIF!]

/* Pre-processor switch to enable / disable the API to read out the modules version information */
#define MEM_43_EEP_VERSION_INFO_API        [!IF "AutosarExt/Mem_43_EepVersionInfoApi"!](STD_ON)[!ELSE!](STD_OFF)[!ENDIF!]

/* defines if the write operation will be executed in asynchronous mode or not*/
#define MEM_43_EEP_ASYNC_WRITE_OPERATIONS_ENABLED      [!IF "AutosarExt/Mem_43_EepBlockSizeWriteAsynchBehaviorEn"!](STD_ON)[!ELSE!](STD_OFF)[!ENDIF!]

/* defines if the Erase operation will be executed in asynchronous mode or not*/
#define MEM_43_EEP_ASYNC_ERASE_OPERATIONS_ENABLED      [!IF "AutosarExt/Mem_43_EepBlockSizeEraseAsynchBehaviorEn"!](STD_ON)[!ELSE!](STD_OFF)[!ENDIF!]

/*==================================================================================================
                                 STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
                                 GLOBAL CONSTANT DECLARATIONS
==================================================================================================*/
[!INDENT "0"!][!//
[!IF "IMPLEMENTATION_CONFIG_VARIANT='VariantPreCompile'"!][!//
  [!IF "variant:size()<=1"!][!//
#define MEM_43_EEP_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Mem_43_Eep_MemMap.h"

/* Declaration of pre-compile configuration set structure */
extern const Mem_43_Eep_ConfigType Mem_43_Eep_Config;

#define MEM_43_EEP_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Mem_43_Eep_MemMap.h"

  [!ENDIF!][!//
[!ENDIF!][!//
[!ENDINDENT!][!//
[!ENDCODE!][!//

#if (MEM_43_EEP_SERVICE_COMPARE == STD_ON)

#define MEM_43_EEP_START_SEC_VAR_CLEARED_32_NO_CACHEABLE
#include "Mem_43_Eep_MemMap.h"

/* Physical compare check address. */
extern Mem_43_Eep_AddressType  Mem_43_Eep_Conpare_u32EepromAddrNeedsCompared;

#define MEM_43_EEP_STOP_SEC_VAR_CLEARED_32_NO_CACHEABLE
#include "Mem_43_Eep_MemMap.h"
#endif

#ifdef __cplusplus
}
#endif

#endif /* MEM_43_EEP_CFG_H */

