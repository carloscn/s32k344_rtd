/*==================================================================================================
*   Project              : RTD AUTOSAR 4.7
*   Platform             : CORTEXM
*   Peripheral           : 
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

#ifndef MCU[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_H
#define MCU[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_H

/**
*   @file       Mcu[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg.h
*   @implements Mcu_PBcfg.h_Artifact
*   @version    3.0.0
*
*   @brief      AUTOSAR Mcu - Data structures for the Mcu driver.
*   @details    Postbuild structure configurations for the driver initalization.
*
*   @addtogroup MCU
*   @{
*/

#ifdef __cplusplus
extern "C"
{
#endif



/*==================================================================================================
*                                          INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/

/*==================================================================================================
                                SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define MCU[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_VENDOR_ID                     43
#define MCU[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_AR_RELEASE_MAJOR_VERSION      4
#define MCU[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_AR_RELEASE_MINOR_VERSION      7
#define MCU[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_AR_RELEASE_REVISION_VERSION   0
#define MCU[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_SW_MAJOR_VERSION              3
#define MCU[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_SW_MINOR_VERSION              0
#define MCU[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_SW_PATCH_VERSION              0

/*==================================================================================================
*                                      FILE VERSION CHECKS
==================================================================================================*/


/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
*                                        LOCAL MACROS
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      LOCAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                       GLOBAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       GLOBAL VARIABLES
==================================================================================================*/

[!NOCODE!]
[!IF "not((IMPLEMENTATION_CONFIG_VARIANT = 'VariantPreCompile') and (variant:size() <= 1))"!]
[!IF "var:defined('postBuildVariant')"!][!//
  [!VAR "postBuildVariantNameUnderscore" = "concat('_',$postBuildVariant)"!][!//
[!CODE!]#define MCU_CONFIG_[!"$postBuildVariant"!]_PB \[!CR!][!ENDCODE!]
[!ELSE!][!//
  [!VAR "postBuildVariantNameUnderscore" = "string(null)"!][!//
[!CODE!]#define MCU_CONFIG_PB \[!CR!][!ENDCODE!]
[!ENDIF!][!//
[!IF "not((IMPLEMENTATION_CONFIG_VARIANT = 'VariantPreCompile') and (variant:size() <= 1))"!]
    [!CODE!][!WS4!]extern const Mcu_ConfigType Mcu_Config[!"$postBuildVariantNameUnderscore"!];[!ENDCODE!]
[!ENDIF!]
[!ENDIF!]
[!ENDNOCODE!]

/*==================================================================================================
                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/

/*==================================================================================================
                                       LOCAL FUNCTIONS
==================================================================================================*/

/*==================================================================================================
                                       GLOBAL FUNCTIONS
==================================================================================================*/


#ifdef __cplusplus
}
#endif

/** @} */
#endif /* #ifndef MCU[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_H */

