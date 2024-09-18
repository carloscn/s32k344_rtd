[!NOCODE!]
[!//////////////////////////////////////////////////////////////////////////////////////////////////
[!//////////////////////////////////////////////////////////////////////////////////////////////////
[!//
[!//
[!//
[!//
[!//////////////////////////////////////////////////////////////////////////////////////////////////
[!//////////////////////////////////////////////////////////////////////////////////////////////////
[!ENDNOCODE!]
[!AUTOSPACING!]
[!CODE!]
[!//
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

#ifndef MEM_43_EXFLS_CFG_H
#define MEM_43_EXFLS_CFG_H

/**
*   @file Mem_43_ExFls_Cfg.h
*
*   @addtogroup MEM_43_EXFLS
*   @{
*/

/* implements Mem_43_ExFls_Cfg.h_Artifact */

#ifdef __cplusplus
extern "C"{
#endif


/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Mem_43_ExFls_Types.h"


/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define MEM_43_EXFLS_VENDOR_ID_CFG                    43
#define MEM_43_EXFLS_AR_RELEASE_MAJOR_VERSION_CFG     4
#define MEM_43_EXFLS_AR_RELEASE_MINOR_VERSION_CFG     7
#define MEM_43_EXFLS_AR_RELEASE_REVISION_VERSION_CFG  0
#define MEM_43_EXFLS_SW_MAJOR_VERSION_CFG             3
#define MEM_43_EXFLS_SW_MINOR_VERSION_CFG             0
#define MEM_43_EXFLS_SW_PATCH_VERSION_CFG             0


/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/


/*==================================================================================================
                                       DEFINES AND MACROS
==================================================================================================*/


/*==================================================================================================
                                 STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/


/*==================================================================================================
                                 GLOBAL CONSTANT DECLARATIONS
==================================================================================================*/

#define MEM_43_EXFLS_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Mem_43_ExFls_MemMap.h"


/* Configuration of Mem_43_ExFls */
extern const Mem_43_ExFls_ConfigType Mem_43_ExFls_Config;

/* Configuration of MemSectorBatch */
[!LOOP "MemInstance/*"!]
extern const Mem_43_ExFls_SectorBatchType Mem_43_ExFls_[!"node:name(.)"!]_SectorBatch[[!"num:i(count(./MemSectorBatch/*))"!]U];
[!ENDLOOP!][!//


#define MEM_43_EXFLS_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Mem_43_ExFls_MemMap.h"


/*==================================================================================================
                                     FUNCTION PROTOTYPES
==================================================================================================*/


[!ENDCODE!][!//

#ifdef __cplusplus
}
#endif

/** @} */

#endif /* MEM_43_EXFLS_CFG_H */
