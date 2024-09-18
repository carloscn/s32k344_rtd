[!NOCODE!]
[!//////////////////////////////////////////////////////////////////////////////////////////////////
[!//////////////////////////////////////////////////////////////////////////////////////////////////
[!//
[!//
[!VAR "MemUnits"  = "''"!]
[!VAR "QspiUnits" = "''"!]
[!LOOP "MemInstance/*"!]
    [!VAR "MemDeviceRef" = "./MemDeviceRef"!]
    [!IF "not(text:contains(string($MemUnits), $MemDeviceRef))"!][!// check for duplicated element
        [!VAR "MemUnits" = "concat($MemUnits, ',', $MemDeviceRef)"!][!// append to list
    [!ENDIF!]
    [!//
    [!VAR "MemQspiInstance" = "node:ref(./MemDeviceRef)/MemQspiInstance"!]
    [!IF "not(text:contains(string($QspiUnits), $MemQspiInstance))"!][!// check for duplicated element
        [!VAR "QspiUnits" = "concat($QspiUnits, ',', $MemQspiInstance)"!][!// append to list
    [!ENDIF!]
[!ENDLOOP!]
[!//
[!VAR "MemUnitsCount"  = "count( text:split($MemUnits,  ',') )"!]
[!VAR "QspiUnitsCount" = "count( text:split($QspiUnits, ',') )"!]
[!//
[!VAR "MemUsingSfdpCount" = "0"!]
[!FOR "Unit" = "1" TO "$MemUnitsCount"!]
    [!VAR "FlsMemPath"    = "text:split($MemUnits, ',')[number($Unit)]"!]
    [!IF "node:ref($FlsMemPath)/MemUseSfdp = 'true'"!]
        [!VAR "MemUsingSfdpCount" = "$MemUsingSfdpCount + 1"!][!//
    [!ENDIF!]
[!ENDFOR!]
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

#ifndef MEM_43_EXFLS_CFG_DEFINES_H
#define MEM_43_EXFLS_CFG_DEFINES_H

/**
*   @file Mem_43_ExFls_CfgDefines.h
*
*   @addtogroup MEM_43_EXFLS
*   @{
*/

/* implements Mem_43_ExFls_CfgDefines.h_Artifact */

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
#define MEM_43_EXFLS_VENDOR_ID_CFG_DEFINES                    43
#define MEM_43_EXFLS_AR_RELEASE_MAJOR_VERSION_CFG_DEFINES     4
#define MEM_43_EXFLS_AR_RELEASE_MINOR_VERSION_CFG_DEFINES     7
#define MEM_43_EXFLS_AR_RELEASE_REVISION_VERSION_CFG_DEFINES  0
#define MEM_43_EXFLS_SW_MAJOR_VERSION_CFG_DEFINES             3
#define MEM_43_EXFLS_SW_MINOR_VERSION_CFG_DEFINES             0
#define MEM_43_EXFLS_SW_PATCH_VERSION_CFG_DEFINES             0


/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/


/*==================================================================================================
                                       DEFINES AND MACROS
==================================================================================================*/

/* Number of configured Mem instances */
#define MEM_43_EXFLS_MEM_INSTANCE_COUNT                       ([!"num:i( count(MemInstance/*) )"!]U)

/* Number of configured Qspi units */
#define MEM_43_EXFLS_QSPI_UNIT_COUNT                          ([!"num:i( $QspiUnitsCount )"!]U)

/* Number of configured Mem units */
#define MEM_43_EXFLS_MEM_UNIT_COUNT                           ([!"num:i( $MemUnitsCount )"!]U)

/* Number of flash devices using SFDP */
#define MEM_43_EXFLS_DEVICES_USING_SFDP                       ([!"num:i( $MemUsingSfdpCount )"!]U)

/* Pre-processor switch to enable and disable development error detection */
#define MEM_43_EXFLS_DEV_ERROR_DETECT                         ([!IF "MemGeneral/MemDevErrorDetect"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

/* Mem instances id */
[!LOOP "MemInstance/*"!]
#define MEM_43_EXFLS_INSTANCE_[!"node:pos(.)"!]_ID            ([!"./MemInstanceId"!]U)
[!ENDLOOP!]


/* Maximum length of data for a read operation based on hardware capability */
#define MEM_43_EXFLS_QSPI_MAX_READ_LENGTH                     FEATURE_QSPI_RX_BUF_SIZE

/* Maximum length of data for a write operation based on hardware capability */
#define MEM_43_EXFLS_QSPI_MAX_WRITE_LENGTH                    FEATURE_QSPI_TX_BUF_SIZE


[!ENDCODE!][!//

#ifdef __cplusplus
}
#endif

/** @} */

#endif /* MEM_43_EXFLS_CFG_DEFINES_H */

