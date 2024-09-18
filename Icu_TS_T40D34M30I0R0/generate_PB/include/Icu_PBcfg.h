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

#ifndef ICU_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_H
#define ICU_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_H

/**
 *   @file       Icu_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBcfg.h
 *   @version    3.0.0
 *
 *   @brief      AUTOSAR Icu  - ICU driver configuration header file.
 *   @details        
 *
 *   @addtogroup icu Icu Driver
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

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define ICU_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_VENDOR_ID                    43
#define ICU_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_AR_RELEASE_MAJOR_VERSION     4
#define ICU_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_AR_RELEASE_MINOR_VERSION     7
#define ICU_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_AR_RELEASE_REVISION_VERSION  0
#define ICU_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_SW_MAJOR_VERSION             3
#define ICU_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_SW_MINOR_VERSION             0
#define ICU_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_SW_PATCH_VERSION             0

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/
[!NOCODE!]
[!IF "(IMPLEMENTATION_CONFIG_VARIANT = 'VariantPostBuild' or (variant:size()>1))"!]
    [!VAR "VariantsNo" = "variant:size()"!]
    [!IF "var:defined('postBuildVariant')"!]
      [!VAR "postBuildVariantNameUnderscore" = "concat('_',$postBuildVariant)"!]
        [!CODE!]#define ICU_CONFIG_[!"$postBuildVariant"!]_PB \[!CR!][!ENDCODE!]
    [!ELSE!]
      [!VAR "postBuildVariantNameUnderscore" = "string(null)"!]
        [!CODE!]#define ICU_CONFIG_PB \[!CR!][!ENDCODE!]
    [!ENDIF!]
    [!VAR "IcuConfiguredPartitions" = "num:i((count(IcuGeneral/IcuEcucPartitionRef/*)))"!]
    [!IF "$IcuConfiguredPartitions > 0"!]
        [!LOOP "IcuGeneral/IcuEcucPartitionRef/*"!]
            [!VAR "currentPartition" = "substring-after(substring-after(substring-after(substring-after(.,'/'),'/'),'/'),'/')"!]
            [!CODE!][!WS "8"!]extern const Icu_ConfigType Icu_Config[!"$postBuildVariantNameUnderscore"!]_[!"$currentPartition"!]; \[!CR!][!ENDCODE!]
        [!ENDLOOP!]
    [!ELSE!]
            [!CODE!][!WS "8"!]extern const Icu_ConfigType Icu_Config[!"$postBuildVariantNameUnderscore"!];[!CR!][!ENDCODE!]
    [!ENDIF!]
[!ENDIF!]
[!ENDNOCODE!]
#ifdef __cplusplus
}
#endif

/** @} */

#endif  /* ICU_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_H */

