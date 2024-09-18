[!NOCODE!]
[!//////////////////////////////////////////////////////////////////////////////////////////////////
[!//////////////////////////////////////////////////////////////////////////////////////////////////
[!//
[!//
[!VAR "MemDrivers" = "''"!]
[!LOOP "MemAccAddressAreaConfiguration/*"!]
[!LOOP "MemAccSubAddressAreaConfiguration/*"!]
    [!VAR "MemName" = "MemAccMemNamePrefix"!][!// extract from path
    [!IF "not(text:contains(string($MemDrivers), $MemName))"!][!// check for duplicated element
        [!VAR "MemDrivers" = "concat($MemDrivers, ',', $MemName)"!][!// append to list
    [!ENDIF!]
[!ENDLOOP!]
[!ENDLOOP!]
[!//
[!VAR "MemDriverCount" = "count( text:split($MemDrivers, ',') )"!][!// split by comma and count
[!//
[!IF "MemAccGeneral/MemAcc64BitSupport"!]
    [!VAR "MemAcc_AddressType" = "'uint64'"!]
    [!VAR "MemAcc_LengthType"  = "'uint64'"!]
[!ELSE!]
    [!VAR "MemAcc_AddressType" = "'uint32'"!]
    [!VAR "MemAcc_LengthType"  = "'uint32'"!]
[!ENDIF!]
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

#ifndef MEMACC_CFG_DEFINES_H
#define MEMACC_CFG_DEFINES_H

/**
*   @file MemAcc_CfgDefines.h
*
*   @addtogroup MEMACC
*   @{
*/

/* implements MemAcc_CfgDefines.h_Artifact */

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
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define MEMACC_VENDOR_ID_CFG_DEFINES                      43
#define MEMACC_AR_RELEASE_MAJOR_VERSION_CFG_DEFINES       4
#define MEMACC_AR_RELEASE_MINOR_VERSION_CFG_DEFINES       7
#define MEMACC_AR_RELEASE_REVISION_VERSION_CFG_DEFINES    0
#define MEMACC_SW_MAJOR_VERSION_CFG_DEFINES               3
#define MEMACC_SW_MINOR_VERSION_CFG_DEFINES               0
#define MEMACC_SW_PATCH_VERSION_CFG_DEFINES               0


/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/


/*==================================================================================================
                                       DEFINES AND MACROS
==================================================================================================*/

/* Pre-processor switch to enable and disable development error detection */
#define MEMACC_DEV_ERROR_DETECT                        ([!IF "MemAccGeneral/MemAccDevErrorDetect"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

/* Pre-processor switch to define if the Mem driver functions are called using the Mem function pointer table API */
#define MEMACC_USE_MEM_FUNCPTR_TABLE                   ([!IF "MemAccGeneral/MemAccUseMemFuncPtrTable"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

/* Pre-processor switch to enable/disable the function MemAcc_Compare() */
#define MEMACC_COMPARE_API                             ([!IF "MemAccGeneral/MemAccCompareApi"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

/* OsIf counter type used in timeout detection for MemAcc operations */
#define MEMACC_TIMEOUT_TYPE                            ([!"MemAccGeneral/MemAccTimeoutMethod"!])

/* Define support for 32 or 64Bit address type */
#define MEMACC_ADDRESSTYPE                             [!"$MemAcc_AddressType"!]
#define MEMACC_LENGTHTYPE                              [!"$MemAcc_LengthType"!]

/*Mem drivers hardware ID list*/
[!FOR "LoopIt" = "1" TO "$MemDriverCount"!]
#define MEMACC_[!"text:toupper(text:split($MemDrivers, ',')[number($LoopIt)])"!]_HW_ID                         ([!"num:i($LoopIt - 1)"!]U)
[!ENDFOR!]

/* Number of hardware resources which are provided by Mem drivers */
#define MEMACC_MEM_HW_RESOURCE_COUNT                   ([!"num:i( count( ecu:list('MemAcc.Mem.Hw.Resource.List') ) )"!]U)

/* The unique numeric identifiers for each hardware resource */
[!VAR "HwResourceCount" = "0"!]
[!LOOP "ecu:list('MemAcc.Mem.Hw.Resource.List')"!]
#define [!"."!]                           ([!"num:i($HwResourceCount)"!]U)
[!VAR "HwResourceCount" = "$HwResourceCount + 1"!]
[!ENDLOOP!]


[!ENDCODE!][!//

#ifdef __cplusplus
}
#endif

/** @} */

#endif /* MEMACC_CFG_DEFINES_H */

