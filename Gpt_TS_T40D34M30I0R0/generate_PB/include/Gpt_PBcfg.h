/*==================================================================================================
* Project : RTD AUTOSAR 4.7
* Platform : CORTEXM
* Peripheral : Stm_Pit_Rtc_Emios
* Dependencies : none
*
* Autosar Version : 4.7.0
* Autosar Revision : ASR_REL_4_7_REV_0000
* Autosar Conf.Variant :
* SW Version : 3.0.0
* Build Version : S32K3_RTD_3_0_0_D2303_ASR_REL_4_7_REV_0000_20230331
*
* Copyright 2020 - 2023 NXP Semiconductors
*
* NXP Confidential. This software is owned or controlled by NXP and may only be
* used strictly in accordance with the applicable license terms. By expressly
* accepting such terms or by downloading, installing, activating and/or otherwise
* using the software, you are agreeing that you have read, and that you agree to
* comply with and are bound by, such license terms. If you do not agree to be
* bound by the applicable license terms, then you may not retain, install,
* activate or otherwise use the software.
==================================================================================================*/

#ifndef GPT_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_H
#define GPT_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_H

/**
*   @file           Gpt_PBcfg.h
*
*   @addtogroup     gpt Gpt Driver
*   @{
*/

#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define GPT_VENDOR_ID_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_H                    43
#define GPT_AR_RELEASE_MAJOR_VERSION_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_H     4
#define GPT_AR_RELEASE_MINOR_VERSION_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_H     7
#define GPT_AR_RELEASE_REVISION_VERSION_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_H  0
#define GPT_SW_MAJOR_VERSION_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_H             3
#define GPT_SW_MINOR_VERSION_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_H             0
#define GPT_SW_PATCH_VERSION_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_H             0
/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/
[!NOCODE!]
[!IF "(IMPLEMENTATION_CONFIG_VARIANT = 'VariantPostBuild' or (variant:size()>1))"!]
    [!IF "var:defined('postBuildVariant')"!]
      [!VAR "postBuildVariantNameUnderscore" = "concat('_',$postBuildVariant)"!]
        [!CODE!]#define GPT_CONFIG_[!"$postBuildVariant"!]_PB \[!CR!][!ENDCODE!]
    [!ELSE!]
      [!VAR "postBuildVariantNameUnderscore" = "string(null)"!]
        [!CODE!]#define GPT_CONFIG_PB \[!CR!][!ENDCODE!]
    [!ENDIF!]
    [!VAR "GptConfiguredPartitions" = "num:i((count(GptDriverConfiguration/GptEcucPartitionRef/*)))"!]
    [!IF "$GptConfiguredPartitions > 0"!]
        [!LOOP "GptDriverConfiguration/GptEcucPartitionRef/*"!]
            [!VAR "currentPartition" = "substring-after(substring-after(substring-after(substring-after(.,'/'),'/'),'/'),'/')"!]
            [!CODE!][!WS "8"!]extern const Gpt_ConfigType Gpt_Config[!"$postBuildVariantNameUnderscore"!]_[!"$currentPartition"!]; \[!CR!][!ENDCODE!]
        [!ENDLOOP!]
    [!ELSE!]
            [!CODE!][!WS "8"!]extern const Gpt_ConfigType Gpt_Config[!"$postBuildVariantNameUnderscore"!];[!CR!][!ENDCODE!]
    [!ENDIF!]
[!ENDIF!]
[!ENDNOCODE!]

#ifdef __cplusplus
}
#endif
/** @} */
#endif  /* GPT_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_H */
