/*==================================================================================================
*   Project              : RTD AUTOSAR 4.7
*   Platform             : CORTEXM
*   Peripheral           : Emios Siul2 Wkpu LpCmp
*   Dependencies         : none
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

#ifndef ICU_IPW_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_H
#define ICU_IPW_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_H

/**
 *   @file           Icu_Ipw_PBcfg.h
 *   @version        3.0.0
 *
 *   @brief          AUTOSAR Icu  - Icu driver configuration header file.
 *   @details        
 *   @internal
 *   @addtogroup     icu_ipw
 *   @{
 */

#ifdef __cplusplus
extern "C"{
#endif

 /*==================================================================================================
 *                                         INCLUDE FILES
 * 1) system and project includes
 * 2) needed interfaces from external units
 * 3) internal and external interfaces from this unit
 *================================================================================================*/
[!INCLUDE "Icu_Ipw_PluginMacros.m"!][!//

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/

#define ICU_IPW_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_VENDOR_ID                    43
#define ICU_IPW_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_AR_RELEASE_MAJOR_VERSION     4
#define ICU_IPW_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_AR_RELEASE_MINOR_VERSION     7
#define ICU_IPW_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_AR_RELEASE_REVISION_VERSION  0
#define ICU_IPW_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_SW_MAJOR_VERSION             3
#define ICU_IPW_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_SW_MINOR_VERSION             0
#define ICU_IPW_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_SW_PATCH_VERSION             0

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/

/*==================================================================================================
 *                                       GLOBAL CONSTANTS
 *================================================================================================*/
[!NOCODE!]
[!FOR "PartitionIdx" = "1" TO "$IcuEcucPartitionRefNum"!]
    [!IF "$IcuEcucPartitionRefCount != 0 "!]
        [!VAR "PartitionIndex" = "node:name(node:value(IcuGeneral/IcuEcucPartitionRef/*[num:i($PartitionIdx)]))"!]
        [!VAR "IcuEcucPartitionRefName" = "node:value(IcuGeneral/IcuEcucPartitionRef/*[num:i($PartitionIdx)])"!]
    [!ENDIF!]
    [!SELECT "IcuConfigSet"!][!//
        [!CALL "ICU_VARIABLES"!]
        [!IF "num:i($OutNumChannelInPartition)!=0"!]
[!CODE!]
#define ICU_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Icu_MemMap.h"
[!ENDCODE!]
            [!CODE!]extern const Icu_Ipw_ChannelConfigType Icu_Ipw_IpChannelConfig_[!"$PBCfg_Variant"!][!IF "$IcuEcucPartitionRefCount != 0 "!]_P_[!"$PartitionIndex"!][!ENDIF!][[!"num:i($OutNumChannelInPartition)"!]U];[!CR!][!ENDCODE!]
            [!CODE!]extern const Icu_Ipw_IpConfigType Icu_Ipw_IpConfig_[!"$PBCfg_Variant"!][!IF "$IcuEcucPartitionRefCount != 0 "!]_P_[!"$PartitionIndex"!][!ENDIF!][[!"num:i($OutNumInstancesInPartition)"!]U];[!CR!][!ENDCODE!]
            [!CODE!][!CR!][!ENDCODE!]
[!CODE!]
#define ICU_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Icu_MemMap.h"
[!ENDCODE!]
        [!ENDIF!]
    [!ENDSELECT!]
[!ENDFOR!]
[!ENDNOCODE!]

#ifdef __cplusplus
}
#endif

#endif /* ICU_IPW_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_H */
