[!NOCODE!][!//
[!//////////////////////////////////////////////////////////////////////////////////////////////////
[!////////////////////////   VARIABLE DEFINE FOR EB TRESOS       ///////////////////////////////////

[!VAR "MemName"      = "'Mem_43_InFls'"!][!//
[!VAR "MemNameUpper" = "text:toupper($MemName)"!][!//


[!//////////////////////////////////////////////////////////////////////////////////////////////////
[!///////////////////////    FUNCTION (MACRO) FOR EB TRESOS      ///////////////////////////////////


[!//////////////////////////////////////////////////////////////////////////////////////////////////
[!ENDNOCODE!][!//
[!AUTOSPACING!][!//
/*==================================================================================================
*   Project              : RTD AUTOSAR 4.7
*   Platform             : CORTEXM
*   Peripheral           : C40
*   Dependencies         : None
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

#ifndef [!"$MemNameUpper"!]_CFG_H
#define [!"$MemNameUpper"!]_CFG_H

/**
 * @file        [!"$MemName"!]_Cfg.h
 *
 * @addtogroup  [!"$MemNameUpper"!] Driver
 * implements   Mem_43_InFls_Cfg.h_Artifact
 *
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
#include "[!"$MemName"!]_Types.h"

/*==================================================================================================
                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define [!"$MemNameUpper"!]_VENDOR_ID_CFG                           43
#define [!"$MemNameUpper"!]_AR_RELEASE_MAJOR_VERSION_CFG            4
#define [!"$MemNameUpper"!]_AR_RELEASE_MINOR_VERSION_CFG            7
#define [!"$MemNameUpper"!]_AR_RELEASE_REVISION_VERSION_CFG         0
#define [!"$MemNameUpper"!]_SW_MAJOR_VERSION_CFG                    3
#define [!"$MemNameUpper"!]_SW_MINOR_VERSION_CFG                    0
#define [!"$MemNameUpper"!]_SW_PATCH_VERSION_CFG                    0

/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/

/* Check if current file and [!"$MemName"!]_Types.h header file are of the same vendor */
#if ([!"$MemNameUpper"!]_VENDOR_ID_CFG != [!"$MemNameUpper"!]_TYPES_VENDOR_ID)
    #error "[!"$MemName"!]_Cfg.h and [!"$MemName"!]_Types.h have different vendor ids"
#endif
/* Check if current file and [!"$MemName"!]_Types.h header file are of the same Autosar version */
#if (([!"$MemNameUpper"!]_AR_RELEASE_MAJOR_VERSION_CFG    != [!"$MemNameUpper"!]_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     ([!"$MemNameUpper"!]_AR_RELEASE_MINOR_VERSION_CFG    != [!"$MemNameUpper"!]_TYPES_AR_RELEASE_MINOR_VERSION) || \
     ([!"$MemNameUpper"!]_AR_RELEASE_REVISION_VERSION_CFG != [!"$MemNameUpper"!]_TYPES_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of [!"$MemName"!]_Cfg.h and [!"$MemName"!]_Types.h are different"
#endif
/* Check if current file and [!"$MemName"!]_Types.h header file are of the same Software version */
#if (([!"$MemNameUpper"!]_SW_MAJOR_VERSION_CFG != [!"$MemNameUpper"!]_TYPES_SW_MAJOR_VERSION) || \
     ([!"$MemNameUpper"!]_SW_MINOR_VERSION_CFG != [!"$MemNameUpper"!]_TYPES_SW_MINOR_VERSION) || \
     ([!"$MemNameUpper"!]_SW_PATCH_VERSION_CFG != [!"$MemNameUpper"!]_TYPES_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of [!"$MemName"!]_Cfg.h and [!"$MemName"!]_Types.h are different"
#endif

/*==================================================================================================
                                       DEFINES AND MACROS
==================================================================================================*/

/* Mem Instances ID */
[!LOOP "MemInstance/*"!][!//
#define [!"$MemNameUpper"!]_INSTANCE_[!"node:pos(.)"!]_ID            ([!"./MemInstanceId"!]U)
[!ENDLOOP!][!//

/*==================================================================================================
                                 GLOBAL CONSTANT DECLARATIONS
==================================================================================================*/

#define [!"$MemNameUpper"!]_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "[!"$MemName"!]_MemMap.h"


/* Configuration of [!"$MemName"!] */
extern const [!"$MemName"!]_ConfigType [!"$MemName"!]_Config;

/* Configuration of MemSectorBatch */
[!LOOP "MemInstance/*"!][!//
extern const [!"$MemName"!]_SectorBatchType [!"$MemName"!]_[!"node:name(.)"!]_SectorBatch[[!"num:i(count(./MemSectorBatch/*))"!]U];
[!ENDLOOP!][!//


#define [!"$MemNameUpper"!]_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "[!"$MemName"!]_MemMap.h"


/*==================================================================================================
                                     FUNCTION PROTOTYPES
==================================================================================================*/


#ifdef __cplusplus
}
#endif

/** @} */

#endif /* [!"$MemNameUpper"!]_CFG_H */
