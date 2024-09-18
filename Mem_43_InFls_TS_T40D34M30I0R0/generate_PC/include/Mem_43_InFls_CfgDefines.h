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

#ifndef [!"$MemNameUpper"!]_CFG_DEFINES_H
#define [!"$MemNameUpper"!]_CFG_DEFINES_H

/**
 * @file        [!"$MemName"!]_CfgDefines.h
 *
 * @addtogroup  [!"$MemNameUpper"!] Driver
 * implements   Mem_43_InFls_CfgDefines.h_Artifact
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


/*==================================================================================================
                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define [!"$MemNameUpper"!]_VENDOR_ID_CFG_DEFINES                           43
#define [!"$MemNameUpper"!]_AR_RELEASE_MAJOR_VERSION_CFG_DEFINES            4
#define [!"$MemNameUpper"!]_AR_RELEASE_MINOR_VERSION_CFG_DEFINES            7
#define [!"$MemNameUpper"!]_AR_RELEASE_REVISION_VERSION_CFG_DEFINES         0
#define [!"$MemNameUpper"!]_SW_MAJOR_VERSION_CFG_DEFINES                    3
#define [!"$MemNameUpper"!]_SW_MINOR_VERSION_CFG_DEFINES                    0
#define [!"$MemNameUpper"!]_SW_PATCH_VERSION_CFG_DEFINES                    0

/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/


/*==================================================================================================
                                       DEFINES AND MACROS
==================================================================================================*/

/* Number of configured Mem instances */
#define [!"$MemNameUpper"!]_MEM_INSTANCE_COUNT                       ([!"num:i( count(MemInstance/*) )"!]U)

/* Number of configured Mem Internal Units */
#define [!"$MemNameUpper"!]_INTERNAL_UNIT_COUNT                      (1U)

/* Pre-processor switch to enable and disable development error detection */
#define [!"$MemNameUpper"!]_DEV_ERROR_DETECT                         ([!IF "MemGeneral/MemDevErrorDetect"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

/* Mem Domain ID Value */
#define [!"$MemNameUpper"!]_DOMAIN_ID                                ([!"MemAutosarExt/MemDomainID"!]U)


#ifdef __cplusplus
}
#endif

/** @} */

#endif /* [!"$MemNameUpper"!]_CFG_DEFINES_H */
