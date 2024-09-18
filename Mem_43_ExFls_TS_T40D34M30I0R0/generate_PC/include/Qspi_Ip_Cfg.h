[!AUTOSPACING!]
[!CODE!][!//
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

#ifndef QSPI_IP_CFG_H
#define QSPI_IP_CFG_H

/**
*   @file Qspi_Ip_Cfg.h
*
*   @addtogroup FLS
*   @{
*/

/* implements Qspi_Ip_Cfg.h_Artifact */

#ifdef __cplusplus
extern "C"{
#endif


/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Qspi_Ip_Types.h"
[!IF "MemGeneral/MemDevErrorDetect"!][!//
#include "Devassert.h"
[!ENDIF!][!//


/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define QSPI_IP_VENDOR_ID_CFG                    43
#define QSPI_IP_AR_RELEASE_MAJOR_VERSION_CFG     4
#define QSPI_IP_AR_RELEASE_MINOR_VERSION_CFG     7
#define QSPI_IP_AR_RELEASE_REVISION_VERSION_CFG  0
#define QSPI_IP_SW_MAJOR_VERSION_CFG             3
#define QSPI_IP_SW_MINOR_VERSION_CFG             0
#define QSPI_IP_SW_PATCH_VERSION_CFG             0


/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/


/*==================================================================================================
                                       DEFINES AND MACROS
==================================================================================================*/

/* Number of serial flash devices */
#define QSPI_IP_MEM_INSTANCE_COUNT        ([!"num:i(count(MemDevice/MemCfg/*))"!]U)

/* Maximum number of retries for Write Enable command */
#define QSPI_IP_MAX_RETRY                 ([!"MemGeneral/MemQspiWriteEnableRetries"!]U)

/* Pre-processor switch to enable/disable development error detection for QSPI Ip API */
#define DEV_ASSERT_QSPI(x)                [!IF "MemGeneral/MemDevErrorDetect"!][!WS "16"!]DevAssert((x))[!ENDIF!][!CR!]

/* Timeout for DLL lock sequence */
#define QSPI_IP_DLL_LOCK_TIMEOUT          ([!"MemGeneral/MemQspiDllLockTimeout"!]U)

/* Timeout for QSPI command completion */
#define QSPI_IP_CMD_COMPLETE_TIMEOUT      ([!"MemGeneral/MemQspiCommandCompleteTimeout"!]U)

#define QSPI_IP_QSPI_IDLE_TIMEOUT         ([!"MemGeneral/MemQspiIdleTimeout"!]U)

/* Timeout for external flash software reset completion */
#define QSPI_IP_RESET_TIMEOUT             ([!"MemGeneral/MemQspiResetTimeout"!]U)

/* Timeout for external flash startup initialization sequence completion */
#define QSPI_IP_FLS_INIT_TIMEOUT          ([!"MemGeneral/MemQspiFlashInitTimeout"!]U)

/* Timeout for a complete read operation */
#define QSPI_IP_READ_TIMEOUT              ([!"MemGeneral/MemQspiSyncReadTimeout"!]U)

/* OsIf counter type used in timeout detection for QSPI IP operations  */
#define QSPI_IP_TIMEOUT_TYPE              ([!"MemGeneral/MemExFlsTimeoutMethod"!])

/* Delay after changing the value of the QSPI software reset bits */
#define QSPI_IP_SOFTWARE_RESET_DELAY      ([!"MemGeneral/MemQspiSoftwareResetDelay"!]U)

/*! @brief Minimum delay in CPU cycles between Tx FIFO reset and Tx FIFO push */
#define QSPI_IP_TX_BUFFER_RESET_DELAY     ([!"MemGeneral/MemQspiTxBufferResetDelay"!]U)

/** QSPI user mode support macro */
#define QSPI_IP_ENABLE_USER_MODE_SUPPORT  ([!IF "AutosarExt/MemEnableUserModeSupport"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

#ifndef MCAL_ENABLE_USER_MODE_SUPPORT
    #if (STD_ON == QSPI_IP_ENABLE_USER_MODE_SUPPORT)
        #error MCAL_ENABLE_USER_MODE_SUPPORT is not enabled. For running Fls in user mode the MCAL_ENABLE_USER_MODE_SUPPORT needs to be defined.
    #endif
#endif

[!ENDCODE!][!//


/*==================================================================================================
                                       DEFINES AND MACROS
==================================================================================================*/

[!NOCODE!]
[!VAR "LUTSeqDefAlignment" = "85"!][!//
[!VAR "PaddingSpaces" = "'                                                                  '"!][!//
[!MACRO "PrintLUTSequence", "LutName" = "", "LutPos" = ""!][!//
    [!VAR "LUTSequenceOut" = "concat('#define ', $LutName)"!][!// Add the LUT name
    [!VAR "LUTSequenceOut" = "concat($LUTSequenceOut, $PaddingSpaces)"!][!// Padding spaces for alignment
    [!VAR "LUTSequenceOut" = "substring($LUTSequenceOut, 1, $LUTSeqDefAlignment - string-length($LutPos))"!][!// Perform the alignment
    [!VAR "LUTSequenceOut" = "concat($LUTSequenceOut, ' ', $LutPos, 'U')"!][!// Add the LUT position
    [!CODE!][!"$LUTSequenceOut"!][!CR!][!ENDCODE!][!// Print the output string
[!ENDMACRO!][!//
[!//
[!INDENT "0"!] [!//

[!IF "num:i(count(MemDevice/MemSerialFlashCfg/*)) > 0"!][!//
    [!CODE!][!WS "0"!]/* Defines for direct access to the virtual LUT table */[!CR!][!ENDCODE!]
    [!CODE!][!CR!][!ENDCODE!]
    [!LOOP "MemDevice/MemSerialFlashCfg/*"!][!// Iterate through memory configurations
        [!VAR "FlsLutIdx" = "0"!][!//
        [!CODE!][!WS "0"!]/* Configuration: [!"node:name(.)"!] */[!CR!][!ENDCODE!]
        [!VAR "FlsLutName" = "concat('QSPI_IP_', node:name(.), '_LUT_SEQUENCE_')"!][!//
        [!LOOP "node:order(./MemLUT/*, 'node:value(./MemLUTIndex)')"!][!// Iterate through the Fls LUT Index
            [!CALL "PrintLUTSequence", "LutName" = "text:toupper(concat($FlsLutName,node:name(.)))", "LutPos" = "num:i($FlsLutIdx)"!]
            [!VAR "FlsLutIdx" = "$FlsLutIdx + 1 + num:i(count(./MemInstructionOperandPair/*))"!][!//
        [!ENDLOOP!][!//
        [!CODE!][!CR!][!ENDCODE!]
    [!ENDLOOP!][!//
[!ENDIF!][!//

[!ENDINDENT!][!//
[!ENDNOCODE!]



/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

#define MEM_43_EXFLS_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Mem_43_ExFls_MemMap.h"

[!NOCODE!][!//
[!VAR "configName"             =    "'Qspi_Ip'"!][!//
[!VAR "ControllerCfgCount"     =    "num:i(count(MemDevice/MemControllerCfg/*))"!][!//
[!VAR "SerialflashCfgCount"    =    "num:i(count(MemDevice/MemSerialFlashCfg/*))"!][!//
[!VAR "HyperflashCfgCount"     =    "num:i(count(MemDevice/MemHyperFlashCfg/*))"!][!//
[!VAR "FlashConfigCount"       =    "num:i($SerialflashCfgCount + $HyperflashCfgCount)"!][!//
[!VAR "FlsMemCount"            =    "num:i(count(MemDevice/MemCfg/*))"!][!//

    [!CODE!][!CR!][!ENDCODE!][!//
    [!IF "$ControllerCfgCount > 0"!][!//
        [!CODE!]/* Controller connections */[!CR!][!ENDCODE!][!//
        [!CODE!]extern const Qspi_Ip_ControllerConfigType [!"$configName"!]_paQspiUnitCfg[[!"$ControllerCfgCount"!]U];[!CR!][!ENDCODE!][!//
        [!CODE!][!CR!][!ENDCODE!][!//
    [!ENDIF!][!//
    [!IF "$FlashConfigCount > 0"!][!//
        [!CODE!]/* Memory configurations */[!CR!][!ENDCODE!][!//
        [!CODE!]extern const Qspi_Ip_MemoryConfigType [!"$configName"!]_paFlashCfg[[!"$FlashConfigCount"!]U];[!CR!][!ENDCODE!][!//
        [!CODE!][!CR!][!ENDCODE!][!//
    [!ENDIF!][!//
    [!IF "$FlsMemCount > 0"!][!//
        [!CODE!]/* Memory-controller connections */[!CR!][!ENDCODE!][!//
        [!CODE!]extern const Qspi_Ip_MemoryConnectionType [!"$configName"!]_paFlashConnectionCfg[[!"$FlsMemCount"!]U];[!CR!][!ENDCODE!][!//
        [!CODE!][!CR!][!ENDCODE!][!//
    [!ENDIF!][!//

[!ENDNOCODE!][!//

#define MEM_43_EXFLS_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Mem_43_ExFls_MemMap.h"


#ifdef __cplusplus
}
#endif

/** @} */

#endif /* QSPI_IP_CFG_H */

