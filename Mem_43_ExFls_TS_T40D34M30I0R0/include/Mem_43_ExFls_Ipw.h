/*==================================================================================================
*   Project              : RTD AUTOSAR 4.7
*   Platform             : CORTEXM
*   Peripheral           : IPV_QSPI
*   Dependencies         : None
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

#ifndef MEM_43_EXFLS_IPW_H
#define MEM_43_EXFLS_IPW_H

/**
*   @file Mem_43_ExFls_IPW.h
*
*   @addtogroup MEM_43_EXFLS
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
#include "Mem_43_ExFls.h"
#include "Qspi_Ip_Features.h"
#include "Qspi_Ip_Types.h"


/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define MEM_43_EXFLS_IPW_VENDOR_ID_H                       43
#define MEM_43_EXFLS_IPW_AR_RELEASE_MAJOR_VERSION_H        4
#define MEM_43_EXFLS_IPW_AR_RELEASE_MINOR_VERSION_H        7
#define MEM_43_EXFLS_IPW_AR_RELEASE_REVISION_VERSION_H     0
#define MEM_43_EXFLS_IPW_SW_MAJOR_VERSION_H                3
#define MEM_43_EXFLS_IPW_SW_MINOR_VERSION_H                0
#define MEM_43_EXFLS_IPW_SW_PATCH_VERSION_H                0


/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/


/*==================================================================================================
*                                    DEFINES AND MACROS
==================================================================================================*/


/*==================================================================================================
*                                    VARIABLE DECLARATIONS
==================================================================================================*/



/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/

#define MEM_43_EXFLS_START_SEC_CODE
#include "Mem_43_ExFls_MemMap.h"


/**
* @brief          Initialize the hardware resources.
*/
Std_ReturnType Mem_43_ExFls_IPW_Init(void);

/*
 * Function Name : Mem_43_ExFls_IPW_DeInit
 * Description   : De-Initialize memory flash devices
 */
void Mem_43_ExFls_IPW_DeInit(uint32 InstanceIndex);

/**
* @brief          Returns synchronously the result of the last job.
*/
Mem_43_ExFls_JobResultType Mem_43_ExFls_IPW_GetJobResult(uint32 InstanceIndex);


/**
* @brief          Abort a suspended hardware job to prepare for a new job.
*/
void Mem_43_ExFls_IPW_AbortSuspended(uint32 InstanceIndex);


/**
* @brief          IP wrapper read function.
*/
Mem_43_ExFls_JobResultType Mem_43_ExFls_IPW_Read(
    uint32                          InstanceIndex,
    Mem_43_ExFls_JobRuntimeInfoType   *JobInfo
);


/**
* @brief          IP wrapper blank check function.
*/
Mem_43_ExFls_JobResultType Mem_43_ExFls_IPW_BlankCheck(
    uint32                          InstanceIndex,
    Mem_43_ExFls_JobRuntimeInfoType   *JobInfo
);


/**
* @brief          IP wrapper write function.
*/
Mem_43_ExFls_JobResultType Mem_43_ExFls_IPW_Write(
    uint32                          InstanceIndex,
    Mem_43_ExFls_JobRuntimeInfoType   *JobInfo
);


/**
* @brief          IP wrapper erase function.
*/
Mem_43_ExFls_JobResultType Mem_43_ExFls_IPW_Erase(
    uint32                          InstanceIndex,
    Mem_43_ExFls_JobRuntimeInfoType   *JobInfo
);


#define MEM_43_EXFLS_STOP_SEC_CODE
#include "Mem_43_ExFls_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */

#endif /* MEM_43_EXFLS_IPW_H */
