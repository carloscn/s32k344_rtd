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

#ifndef TSPC_PORT_IP_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_H
#define TSPC_PORT_IP_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_H

/**
*   @file    Tspc_Port_Ip_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBcfg.h
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
#define TSPC_PORT_IP_VENDOR_ID_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_H                       43
#define TSPC_PORT_IP_AR_RELEASE_MAJOR_VERSION_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_H        4
#define TSPC_PORT_IP_AR_RELEASE_MINOR_VERSION_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_H        7
#define TSPC_PORT_IP_AR_RELEASE_REVISION_VERSION_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_H     0
#define TSPC_PORT_IP_SW_MAJOR_VERSION_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_H                3
#define TSPC_PORT_IP_SW_MINOR_VERSION_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_H                0
#define TSPC_PORT_IP_SW_PATCH_VERSION_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_H                0

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
[!IF "not(contains(as:modconf("Resource")[1]/ResourceGeneral/ResourceSubderivative, 's32k396')) and not(contains(as:modconf("Resource")[1]/ResourceGeneral/ResourceSubderivative, 's32k394'))"!][!//  /* S32K394: sub/phantom derivatives of S32K396 */
/*! @brief User configuration structure */
[!INDENT "0"!][!//
    [!IF "var:defined('postBuildVariant')"!][!//
#define TSPC_PORT_CONFIG_[!"$postBuildVariant"!]_PB \
    [!ELSE!][!//
#define TSPC_PORT_CONFIG_PB \
    [!ENDIF!][!//
    extern const Tspc_Port_Ip_ObeGroupConfig aTspc_InitConfigArr[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][NUM_OF_OBE_GROUP_CONFIG];
[!ENDINDENT!][!//
[!ENDIF!][!//
/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/


#ifdef __cplusplus
}
#endif

/** @} */

#endif /* TSPC_PORT_IP_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_H */
