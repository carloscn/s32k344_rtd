
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
#ifndef AECANPHY_IP_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_H
#define AECANPHY_IP_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_H

/**
*   @file AeCanPHY_Ip_PBcfg.h
*
*   @addtogroup AeCanPHY
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
#define AE_CANPHY_IP_VENDOR_ID_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_H                     43
#define AE_CANPHY_IP_AR_RELEASE_MAJOR_VERSION_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_H      4
#define AE_CANPHY_IP_AR_RELEASE_MINOR_VERSION_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_H      7
#define AE_CANPHY_IP_AR_RELEASE_REVISION_VERSION_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_H   0
#define AE_CANPHY_IP_SW_MAJOR_VERSION_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_H              3
#define AE_CANPHY_IP_SW_MINOR_VERSION_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_H              0
#define AE_CANPHY_IP_SW_PATCH_VERSION_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_H              0
/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/

/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/
[!NOCODE!]
[!IF "var:defined('postBuildVariant')"!]
    [!VAR "postBuildVariantNameUnderscore" = "concat('_',$postBuildVariant)"!]
[!ELSE!]
    [!VAR "postBuildVariantNameUnderscore" = "string(null)"!]
[!ENDIF!]
[!CODE!]#define AE_CANPHY_IP[!"$postBuildVariantNameUnderscore"!]_PB_CFG  \[!CR!][!ENDCODE!]
[!SELECT "CanTrcvConfigSet"!]
[!VAR "CtrlConfigCount" = "num:i(count(./CanTrcvChannel/*))"!]
[!CODE!][!WS "4"!]extern const AeCanPHY_Ip_ConfigType AeCanPHY_aConfigPB[!"$postBuildVariantNameUnderscore"!][[!"$CtrlConfigCount"!]U];[!ENDCODE!]
[!ENDSELECT!]
[!ENDNOCODE!]

#ifdef __cplusplus
}
#endif /* __cplusplus */

/** @} */

#endif /* AECANPHY_IP_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_H */
