/*==================================================================================================
*   Project              : RTD AUTOSAR 4.7
*   Platform             : CORTEXM
*   Peripheral           : SIUL2
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

#ifndef SIUL2_PORT_IP_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_H
#define SIUL2_PORT_IP_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_H

/**
*   @file    Siul2_Port_Ip_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBcfg.h
*
*   @addtogroup Port_CFG
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
#define SIUL2_PORT_IP_VENDOR_ID_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_H                       43
#define SIUL2_PORT_IP_AR_RELEASE_MAJOR_VERSION_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_H        4
#define SIUL2_PORT_IP_AR_RELEASE_MINOR_VERSION_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_H        7
#define SIUL2_PORT_IP_AR_RELEASE_REVISION_VERSION_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_H     0
#define SIUL2_PORT_IP_SW_MAJOR_VERSION_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_H                3
#define SIUL2_PORT_IP_SW_MINOR_VERSION_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_H                0
#define SIUL2_PORT_IP_SW_PATCH_VERSION_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_H                0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/

/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/

/*==================================================================================================
*                                             ENUMS
==================================================================================================*/

/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/
/*! @brief User configuration structure */
[!IF "var:defined('postBuildVariant')"!][!//
#define SIUL2_PORT_CONFIG_[!"$postBuildVariant"!]_PB \
[!ELSE!][!//
#define SIUL2_PORT_CONFIG_PB \
[!ENDIF!][!//
[!INDENT "0"!][!//
    extern const Siul2_Port_Ip_PinSettingsConfig g_pin_mux_InitConfigArr[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][NUM_OF_CONFIGURED_PINS];
[!ENDINDENT!][!//
/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/


#ifdef __cplusplus
}
#endif

/** @} */

#endif /* SIUL2_PORT_IP_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_H */
