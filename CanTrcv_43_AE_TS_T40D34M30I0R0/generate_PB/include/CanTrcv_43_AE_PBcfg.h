/*==================================================================================================
*   Project              : RTD AUTOSAR 4.7
*   Platform             : CORTEXM
*   Peripheral           : AE
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
/*==================================================================================================
==================================================================================================*/
#ifndef CANTRCV_43_AE_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_H
#define CANTRCV_43_AE_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_H

/**
*   @file    CanTrcv_43_AE_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBcfg.h
*   @version 3.0.0
*
*   @brief   AUTOSAR CanTrcv_43_AE - module interface
*   @details Configuration settings generated by user settings.
*
*   @addtogroup CANTRCV_DRIVER
*   @{
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
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define CANTRCV_43_AE_VENDOR_ID_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_H 43
#define CANTRCV_43_AE_AR_RELEASE_MAJOR_VERSION_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_H 4
#define CANTRCV_43_AE_AR_RELEASE_MINOR_VERSION_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_H 7
#define CANTRCV_43_AE_AR_RELEASE_REVISION_VERSION_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_H 0
#define CANTRCV_43_AE_SW_MAJOR_VERSION_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_H 3
#define CANTRCV_43_AE_SW_MINOR_VERSION_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_H 0
#define CANTRCV_43_AE_SW_PATCH_VERSION_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_H 0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/
[!NOCODE!]
[!VAR "VariantsNo" = "variant:size()"!]
[!IF "((IMPLEMENTATION_CONFIG_VARIANT != 'VariantPostBuild') and (variant:size()>1)) or (IMPLEMENTATION_CONFIG_VARIANT = 'VariantPostBuild')"!]
    [!IF "var:defined('postBuildVariant')"!]
        [!VAR "postBuildVariantNameUnderscore" = "concat('_',$postBuildVariant)"!]
        [!CODE!]#define CANTRCV_43_AE_CONFIG_[!"$postBuildVariant"!]_PB \[!CR!][!ENDCODE!]
    [!ELSE!]
        [!VAR "postBuildVariantNameUnderscore" = "string(null)"!]
        [!CODE!]#define CANTRCV_43_AE_CONFIG_PB \[!CR!][!ENDCODE!]
    [!ENDIF!]
    [!VAR "CanTrcvConfiguredPartitions" = "num:i((count(CanTrcvGeneral/CanTrcvEcucPartitionRef/*)))"!]
    [!INDENT "4"!]
    [!IF "$CanTrcvConfiguredPartitions > 0"!]
        [!VAR "CanTrcvPartitionIdx" = "0"!]
        [!LOOP "CanTrcvGeneral/CanTrcvEcucPartitionRef/*"!]
            [!VAR "CanTrcvPartitionIdx" = "$CanTrcvPartitionIdx + 1"!]
            [!VAR "currentPartition" = "substring-after(substring-after(., 'EcuC/EcuC/'), '/')"!]
            [!CODE!]extern const CanTrcv_43_AE_ConfigType[!WS!]CanTrcv_43_AE_Config[!"$postBuildVariantNameUnderscore"!]_[!"$currentPartition"!]; [!IF "$CanTrcvPartitionIdx < $CanTrcvConfiguredPartitions"!]\[!ENDIF!][!CR!][!ENDCODE!]
        [!ENDLOOP!]
    [!ELSE!]
        [!CODE!]extern const CanTrcv_43_AE_ConfigType[!WS!]CanTrcv_43_AE_Config[!"$postBuildVariantNameUnderscore"!];[!ENDCODE!]
    [!ENDIF!]
    [!ENDINDENT!]
[!ENDIF!]
[!ENDNOCODE!]

#ifdef __cplusplus
}
#endif

/** @} */

#endif /* _CANTRCV_43_AE_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_H_ */
