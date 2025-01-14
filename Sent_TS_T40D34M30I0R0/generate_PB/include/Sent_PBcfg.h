/*==================================================================================================
*   Project              : RTD AUTOSAR 4.7
*   Platform             : CORTEXM
*   Peripheral           : FLEXIO_SENT_IP
*   Dependencies         : none
*
*   Autosar Version      : 4.7.0
*   Autosar Revision     : ASR_REL_4_7_REV_0000
*   Autosar Conf.Variant :
*   SW Version           : 3.0.0
*   Build Version        : S32K3_RTD_3_0_0_D2303_ASR_REL_4_7_REV_0000_20230331
*
*   Copyright 2020 - 2023 NXP Semiconductors NXP.
*
*   NXP Confidential. This software is owned or controlled by NXP and may only be
*   used strictly in accordance with the applicable license terms. By expressly
*   accepting such terms or by downloading, installing, activating and/or otherwise
*   using the software, you are agreeing that you have read, and that you agree to
*   comply with and are bound by, such license terms. If you do not agree to be
*   bound by the applicable license terms, then you may not retain, install,
*   activate or otherwise use the software.
==================================================================================================*/

#ifndef SENT_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_H
#define SENT_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_H

/**
*   @file       Sent_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBcfg.h
*
*   @version 3.0.0
*
*   @brief   AUTOSAR Sent - driver configuration header file.
*   @details Configuration settings generated by user settings.
*
*   @addtogroup [MODULE_SECTION]
*   @{
*/


#ifdef __cplusplus
extern "C" {
#endif

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define SENT_PBCFG_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]VENDOR_ID                         43
#define SENT_PBCFG_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]AR_RELEASE_MAJOR_VERSION          4
#define SENT_PBCFG_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]AR_RELEASE_MINOR_VERSION          7
#define SENT_PBCFG_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]AR_RELEASE_REVISION_VERSION       0
#define SENT_PBCFG_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]SW_MAJOR_VERSION                  3
#define SENT_PBCFG_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]SW_MINOR_VERSION                  0
#define SENT_PBCFG_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]SW_PATCH_VERSION                  0


/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/

[!AUTOSPACING!][!//
/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/
[!NOCODE!]
[!IF "not((IMPLEMENTATION_CONFIG_VARIANT != 'VariantPostBuild') and (variant:size() <= 1))"!]
    [!IF "var:defined('postBuildVariant')"!]
        [!VAR "PostBuildVariantNameUnderscore" = "concat('_',$postBuildVariant)"!]
        [!CODE!]#define SENT_CONFIG_[!"$postBuildVariant"!]_PB \[!CR!][!ENDCODE!]
    [!ELSE!]
        [!VAR "PostBuildVariantNameUnderscore" = "string(null)"!]
        [!CODE!]#define SENT_CONFIG_PB \[!CR!][!ENDCODE!]
    [!ENDIF!]
    [!VAR "SentConfiguredPartitions" = "num:i((count(SentGeneral/SentEcucPartitionRef/*)))"!]
    [!INDENT "4"!]
    [!IF "((IMPLEMENTATION_CONFIG_VARIANT != 'VariantPostBuild') and (variant:size()>1)) or (IMPLEMENTATION_CONFIG_VARIANT = 'VariantPostBuild')"!]
        [!IF "$SentConfiguredPartitions > 0"!]
            [!VAR "SentPartitionIdx" = "0"!]
            [!LOOP "SentGeneral/SentEcucPartitionRef/*"!]
                [!VAR "SentPartitionIdx" = "$SentPartitionIdx + 1"!]
                [!VAR "currentPartition" = "substring-after(substring-after(., 'EcuC/EcuC/'), '/')"!]
                [!CODE!]extern const Sent_ConfigType[!WS!]Sent_Config[!"$PostBuildVariantNameUnderscore"!]_[!"$currentPartition"!]; [!IF "$SentPartitionIdx < $SentConfiguredPartitions"!]\[!ENDIF!][!CR!][!ENDCODE!]
            [!ENDLOOP!]
        [!ELSE!]
            [!CODE!]extern const Sent_ConfigType[!WS!]Sent_Config[!"$PostBuildVariantNameUnderscore"!];[!ENDCODE!]
        [!ENDIF!]
    [!ENDIF!]
    [!ENDINDENT!]
[!ENDIF!]
[!ENDNOCODE!]


#ifdef __cplusplus
}
#endif

/** @} */

#endif /* SENT_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_H */
