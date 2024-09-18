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

#ifndef USDHC_IP_CFG_H
#define USDHC_IP_CFG_H

/**
* @file Usdhc_Ip_Cfg.h
*
* @addtogroup Usdhc_Ip
* @{
*/

#ifdef __cplusplus
extern "C"{
#endif

/**
*
*
*/

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/

#include "Usdhc_Ip_Types.h"
#include "StandardTypes.h"
#include "OsIf.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define USDHC_VENDOR_ID_IP_CFG                          43
#define USDHC_AR_RELEASE_MAJOR_VERSION_IP_CFG           4
#define USDHC_AR_RELEASE_MINOR_VERSION_IP_CFG           7
#define USDHC_AR_RELEASE_REVISION_VERSION_IP_CFG        0
#define USDHC_SW_MAJOR_VERSION_IP_CFG                   3
#define USDHC_SW_MINOR_VERSION_IP_CFG                   0
#define USDHC_SW_PATCH_VERSION_IP_CFG                   0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and Usdhc_Ip_Types header file are of the same vendor */
#if (USDHC_VENDOR_ID_IP_CFG != USDHC_IP_TYPES_VENDOR_ID_H)
    #error "Usdhc_Ip_Cfg.h and Usdhc_Ip_Types.h have different vendor ids"
#endif
/* Check if current file and Usdhc_Ip_Types header file are of the same Autosar version */
#if ((USDHC_AR_RELEASE_MAJOR_VERSION_IP_CFG    != USDHC_IP_TYPES_AR_RELEASE_MAJOR_VERSION_H) || \
     (USDHC_AR_RELEASE_MINOR_VERSION_IP_CFG    != USDHC_IP_TYPES_AR_RELEASE_MINOR_VERSION_H) || \
     (USDHC_AR_RELEASE_REVISION_VERSION_IP_CFG != USDHC_IP_TYPES_AR_RELEASE_REVISION_VERSION_H) \
    )
    #error "AutoSar Version Numbers of Usdhc_Ip_Cfg.h and Usdhc_Ip_Types.h are different"
#endif
/* Check if current file and Usdhc_Ip_Types header file are of the same software version */
#if ((USDHC_SW_MAJOR_VERSION_IP_CFG != USDHC_IP_TYPES_SW_MAJOR_VERSION_H) || \
     (USDHC_SW_MINOR_VERSION_IP_CFG != USDHC_IP_TYPES_SW_MINOR_VERSION_H) || \
     (USDHC_SW_PATCH_VERSION_IP_CFG != USDHC_IP_TYPES_SW_PATCH_VERSION_H) \
    )
    #error "Software Version Numbers of Usdhc_Ip_Cfg.h and Usdhc_Ip_Types.h are different"
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if current file and StandardTypes header file are of the same Autosar version */
    #if ((USDHC_AR_RELEASE_MAJOR_VERSION_IP_CFG != STD_AR_RELEASE_MAJOR_VERSION) || \
         (USDHC_AR_RELEASE_MINOR_VERSION_IP_CFG != STD_AR_RELEASE_MINOR_VERSION) \
        )
        #error "AutoSar Version Numbers of Usdhc_Ip_Cfg.h and StandardTypes.h are different"
    #endif
    /* Check if current file and OsIf header file are of the same Autosar version */
    #if ((USDHC_AR_RELEASE_MAJOR_VERSION_IP_CFG != OSIF_AR_RELEASE_MAJOR_VERSION) || \
         (USDHC_AR_RELEASE_MINOR_VERSION_IP_CFG != OSIF_AR_RELEASE_MINOR_VERSION) \
        )
        #error "AutoSar Version Numbers of Usdhc_Ip_Cfg.h and OsIf.h are different"
    #endif
#endif
/*==================================================================================================
                                       DEFINES AND MACROS
==================================================================================================*/
[!NOCODE!]
    [!SELECT "Mem_43_EepUsdhcControllerCfg"!]
    [!CODE!]
[!IF "./*[1]/EnableADMA1Mode"!][!//
/*! @brief Enable/disable ADMA1 mode */
#define USDHC_IP_ENABLE_ADMA1
[!ENDIF!][!//
[!INDENT "0"!]
/*! @brief Enable/disable dev error detect for USDHC */
#define USDHC_IP_DEV_ERROR_DETECT                     [!IF "./*[1]/Mem_43_EepUsdhcIpDevErrorDetect"!](STD_ON)[!ELSE!](STD_OFF)[!ENDIF!]
/* @brief uSDHC development error detect enable/disable */
#define USDHC_IP_DEV_ASSERT(x)                        [!IF "./*[1]/Mem_43_EepUsdhcIpDevErrorDetect"!]DevAssert((x))[!ENDIF!]

/*! @brief Enable/disable cache synchronization */
#define USDHC_IP_SYNCRONIZE_CACHE                     [!IF "./*[1]/Mem_43_EepSynchronizeCache"!](STD_ON)[!ELSE!](STD_OFF)[!ENDIF!]
/*! @brief Timeout value to switch voltage */
#define USDHC_IP_SWITCH_VOLTAGE_TIMEOUT               ([!"num:inttohex(./*[1]/SwitchVoltageTimeout)"!]U)
/*! @brief Timeout value to get present status of uSDHC */
#define USDHC_IP_GET_PRESENT_STATUS_TIMEOUT           ([!"num:inttohex(./*[1]/GetPresentStatusTimeout)"!]U)
/*! @brief Timeout value to set card active */
#define USDHC_IP_SETCARDACTIVE_TIMEOUT                ([!"num:inttohex(./*[1]/cardActiveTimeout)"!]U)
/*! @brief Timeout value to set bus clock for uSDHC */
#define USDHC_IP_SETBUSCLOCK_TIMEOUT                  ([!"num:inttohex(./*[1]/setBusClkTimeout)"!]U)
/*! @brief Timeout value to abort current transfer */
#define USDHC_IP_ABORT_TRANSFER_TIMEOUT               ([!"num:inttohex(./*[1]/AbortTransferTimeout)"!]U)
/*! @brief Timeout value to reset the uSDHC */
#define USDHC_IP_RESET_TIMEOUT                        ([!"num:inttohex(./*[1]/ResetUsdhcTimeout)"!]U)
/*! @brief Timeout value to transfer operations in synchronized mode  */
#define USDHC_IP_SYNC_TRANSFER_TIMEOUT                ([!"num:inttohex(./*[1]/transferSyncTimeout)"!]U)
/*! @brief Timeout value to transfer operations in asynchronized mode  */
#define USDHC_IP_ASYNC_TRANSFER_TIMEOUT               ([!"num:inttohex(./*[1]/transferAsyncTimeout)"!]U)
/*! @brief Timeout value to get card interface condition */
#define USDHC_IP_GET_INTERFACE_CONDITION_TIMEOUT      ([!"num:inttohex(./*[1]/getInterfaceTimeout)"!]U)
/*! @brief Multicore support */
[!IF "../AutosarExt/Mem_43_EepMCoreEnable"!][!//
#define USDHC_MCORE_ENABLED                           (STD_ON)
#define USDHC_MCORE_SEMA4_JOB                         ([!"num:inttohex(../AutosarExt/Mem_43_EepMCoreJobSemaphoreChannelNo)"!]U)
[!ELSE!][!//
#define USDHC_MCORE_ENABLED                           (STD_OFF)
[!ENDIF!][!//

/* Pre-processor switch to enable and disable the API for MMC boot feature */
#define USDHC_IP_MMC_BOOT_ENABLED                     [!IF "node:exists(./*[1]/BootHostConfig)"!](STD_ON)[!ELSE!](STD_OFF)[!ENDIF!]
/*! @brief Default block size to set in Block attribute register */
#define USDHC_IP_DEFAULT_BLOCK_SIZE                   (512U)
[!NOCODE!][!//
    [!IF "node:value(./*[1]/Mem_43_EepTimeoutMethod) = 'OSIF_COUNTER_SYSTEM'"!]
        [!VAR "strCounterType" = "'OSIF_COUNTER_SYSTEM'"!][!//
        [!CODE!][!//
            /* Check if the chosen counter type is enabled */
            #if (STD_OFF == OSIF_USE_SYSTEM_TIMER)
             #error "OSIF System counter is disabled"
            #endif
        [!ENDCODE!][!//
    [!ELSEIF "node:value(./*[1]/Mem_43_EepTimeoutMethod) = 'OSIF_COUNTER_CUSTOM'"!]
        [!VAR "strCounterType" = "'OSIF_COUNTER_CUSTOM'"!][!//
        [!CODE!][!//
            /* Check if the chosen counter type is enabled */
            #if (STD_OFF == OSIF_USE_CUSTOM_TIMER)
              #error "OSIF Custom counter is disabled"
            #endif
        [!ENDCODE!][!//
    [!ELSE!][!//
        [!VAR "strCounterType" = "'OSIF_COUNTER_DUMMY'"!][!//
    [!ENDIF!][!//
[!ENDNOCODE!][!//

/*! @brief  OsIf counter type used in timeout detection for USDHC IP operations */
#define USDHC_IP_TIMEOUT_TYPE                         ([!"$strCounterType"!])
/*! @brief  Usdhc host supports 3.3V operation */
#define USDHC_IP_V330_SUPPORT                         [!IF "./*[1]/voltageSupport/Support33V"!](STD_ON)[!ELSE!](STD_OFF)[!ENDIF!]
/*! @brief  Usdhc host supports 3V operation */
#define USDHC_IP_V300_SUPPORT                         [!IF "./*[1]/voltageSupport/Support30V"!](STD_ON)[!ELSE!](STD_OFF)[!ENDIF!]
/*! @brief  Usdhc host supports 1.8V operation */
#define USDHC_IP_V180_SUPPORT                         [!IF "./*[1]/voltageSupport/Support18V"!](STD_ON)[!ELSE!](STD_OFF)[!ENDIF!]
/*! @brief Word size of Current platform */
#define USDHC_IP_PLATFORM_WORDSIZE                    (4U)
/*! @brief The cache types specifies what type of cache shall be used */
#define USDHC_IP_CACHE_TYPE                           (CACHE_IP_CORE)
/*! @brief Cache line length in bytes for current platform */
#define USDHC_IP_CACHE_LINE_LENGTH                    (32UL)
/*! Timeout for MMC card to get stable before receiving CMD0 */
#define USDHC_IP_WAIT_CARD_STABLE                     (1000U)

[!ENDINDENT!]

/*==================================================================================================
                                 STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
                                 GLOBAL CONSTANT DECLARATIONS
==================================================================================================*/

#define MEM_43_EEP_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Mem_43_Eep_MemMap.h"
[!ENDCODE!]

[!LOOP "./*"!][!//
    [!VAR "configName" = "node:name(.)"!]
    [!IF "var:defined('postBuildVariant')"!][!//
        [!CODE!][!CR!][!ENDCODE!]
        [!LOOP "variant:all()"!][!//
            [!CODE!]/*! @brief USDHC module configurations */[!CR!][!ENDCODE!]
            [!CODE!]extern const Usdhc_Ip_ConfigType [!"$configName"!]_[!"."!];[!CR!][!CR!][!ENDCODE!]
        [!ENDLOOP!][!//
    [!ELSE!][!//
        [!CODE!][!CR!][!ENDCODE!]
        [!CODE!]/*! @brief USDHC module configurations */[!CR!][!ENDCODE!]
        [!CODE!]extern const Usdhc_Ip_ConfigType [!"$configName"!];[!CR!][!CR!][!ENDCODE!]
    [!ENDIF!][!//
[!ENDLOOP!][!//
    [!ENDSELECT!]
[!ENDNOCODE!]

#define MEM_43_EEP_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Mem_43_Eep_MemMap.h"
[!ENDCODE!]
#ifdef __cplusplus
}
#endif

#endif /* USDHC_IP_CFG_H */

