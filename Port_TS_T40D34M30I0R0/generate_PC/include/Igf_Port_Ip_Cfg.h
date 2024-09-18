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

#ifndef IGF_PORT_IP_CFG_H
#define IGF_PORT_IP_CFG_H

/**
*   @file    Igf_Port_Ip_Cfg.h
*
*   @addtogroup Port_CFG
*   @{
*/

#ifdef __cplusplus
extern "C"{
#endif

/*=================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
=================================================================================================*/
[!INDENT "0"!][!//
[!IF "node:exists(as:modconf("Resource")[1]/ResourceGeneral/ResourceSubderivative)"!][!//
    [!IF "contains(as:modconf("Resource")[1]/ResourceGeneral/ResourceSubderivative, 's32k396') or contains(as:modconf("Resource")[1]/ResourceGeneral/ResourceSubderivative, 's32k394')"!][!//  /* S32K394: sub/phantom derivatives of S32K396 */
#include "Igf_Port_Ip_Types.h"
#include "S32K39_IGF.h"
        [!/* Variants */!][!//
        [!IF "var:defined('postBuildVariant')"!][!//
        [!LOOP "variant:all()"!][!//
#include "Igf_Port_Ip_[!"."!]_PBcfg.h"
        [!ENDLOOP!][!//
        [!ELSE!][!//
#include "Igf_Port_Ip_PBcfg.h"
        [!ENDIF!][!//
    [!ENDIF!][!//
[!ENDIF!][!//
[!ENDINDENT!]
/*=================================================================================================
*                              SOURCE FILE VERSION INFORMATION
=================================================================================================*/
#define IGF_PORT_IP_VENDOR_ID_CFG_H                       43
#define IGF_PORT_IP_AR_RELEASE_MAJOR_VERSION_CFG_H        4
#define IGF_PORT_IP_AR_RELEASE_MINOR_VERSION_CFG_H        7
#define IGF_PORT_IP_AR_RELEASE_REVISION_VERSION_CFG_H     0
#define IGF_PORT_IP_SW_MAJOR_VERSION_CFG_H                3
#define IGF_PORT_IP_SW_MINOR_VERSION_CFG_H                0
#define IGF_PORT_IP_SW_PATCH_VERSION_CFG_H                0

/*=================================================================================================
*                                     FILE VERSION CHECKS
=================================================================================================*/
[!IF "contains(as:modconf("Resource")[1]/ResourceGeneral/ResourceSubderivative, 's32k396') or contains(as:modconf("Resource")[1]/ResourceGeneral/ResourceSubderivative, 's32k394')"!][!//  /* S32K394: sub/phantom derivatives of S32K396 */
/* Check if the files Igf_Port_Ip_Cfg.h and Igf_Port_Ip_Types.h are of the same version */
#if (IGF_PORT_IP_VENDOR_ID_CFG_H != IGF_PORT_IP_TYPES_VENDOR_ID_H)
    #error "Igf_Port_Ip_Cfg.h and Igf_Port_Ip_Types.h have different vendor ids"
#endif
/* Check if Igf_Port_Ip_Cfg.h and Igf_Port_Ip_Types.h are of the same Autosar version */
#if ((IGF_PORT_IP_AR_RELEASE_MAJOR_VERSION_CFG_H    != IGF_PORT_IP_TYPES_AR_RELEASE_MAJOR_VERSION_H) || \
     (IGF_PORT_IP_AR_RELEASE_MINOR_VERSION_CFG_H    != IGF_PORT_IP_TYPES_AR_RELEASE_MINOR_VERSION_H) || \
     (IGF_PORT_IP_AR_RELEASE_REVISION_VERSION_CFG_H != IGF_PORT_IP_TYPES_AR_RELEASE_REVISION_VERSION_H) \
    )
    #error "AutoSar Version Numbers of Igf_Port_Ip_Cfg.h and Igf_Port_Ip_Types.h are different"
#endif
/* Check if Igf_Port_Ip_Cfg.h and Igf_Port_Ip_Types.h are of the same Software version */
#if ((IGF_PORT_IP_SW_MAJOR_VERSION_CFG_H != IGF_PORT_IP_TYPES_SW_MAJOR_VERSION_H) || \
     (IGF_PORT_IP_SW_MINOR_VERSION_CFG_H != IGF_PORT_IP_TYPES_SW_MINOR_VERSION_H) || \
     (IGF_PORT_IP_SW_PATCH_VERSION_CFG_H != IGF_PORT_IP_TYPES_SW_PATCH_VERSION_H)    \
    )
    #error "Software Version Numbers of Igf_Port_Ip_Cfg.h and Igf_Port_Ip_Types.h are different"
#endif

    [!IF "var:defined('postBuildVariant')"!][!//
    [!LOOP "variant:all()"!][!//
/* Check if the files Igf_Port_Ip_Cfg.h and Igf_Port_Ip_[!"."!]_PBcfg.h are of the same version */
#if (IGF_PORT_IP_VENDOR_ID_CFG_H != IGF_PORT_IP_VENDOR_ID_[!"."!]_PBCFG_H)
    #error "Igf_Port_Ip_Cfg.h and Igf_Port_Ip_[!"."!]_PBcfg.h have different vendor ids"
#endif
/* Check if Igf_Port_Ip_Cfg.h and Igf_Port_Ip_[!"."!]_PBcfg.h are of the same Autosar version */
#if ((IGF_PORT_IP_AR_RELEASE_MAJOR_VERSION_CFG_H    != IGF_PORT_IP_AR_RELEASE_MAJOR_VERSION_[!"."!]_PBCFG_H) || \
     (IGF_PORT_IP_AR_RELEASE_MINOR_VERSION_CFG_H    != IGF_PORT_IP_AR_RELEASE_MINOR_VERSION_[!"."!]_PBCFG_H) || \
     (IGF_PORT_IP_AR_RELEASE_REVISION_VERSION_CFG_H != IGF_PORT_IP_AR_RELEASE_REVISION_VERSION_[!"."!]_PBCFG_H) \
    )
    #error "AutoSar Version Numbers of Igf_Port_Ip_Cfg.h and Igf_Port_Ip_[!"."!]_PBcfg.h are different"
#endif
/* Check if Igf_Port_Ip_Cfg.h and Igf_Port_Ip_[!"."!]_PBcfg.h are of the same Software version */
#if ((IGF_PORT_IP_SW_MAJOR_VERSION_CFG_H != IGF_PORT_IP_SW_MAJOR_VERSION_[!"."!]_PBCFG_H) || \
     (IGF_PORT_IP_SW_MINOR_VERSION_CFG_H != IGF_PORT_IP_SW_MINOR_VERSION_[!"."!]_PBCFG_H) || \
     (IGF_PORT_IP_SW_PATCH_VERSION_CFG_H != IGF_PORT_IP_SW_PATCH_VERSION_[!"."!]_PBCFG_H)    \
    )
    #error "Software Version Numbers of Igf_Port_Ip_Cfg.h and Igf_Port_Ip_[!"."!]_PBcfg.h are different"
#endif
    [!ENDLOOP!][!//
    [!ELSE!][!//
/* Check if the files Igf_Port_Ip_Cfg.h and Igf_Port_Ip_PBcfg.h are of the same version */
#if (IGF_PORT_IP_VENDOR_ID_CFG_H != IGF_PORT_IP_VENDOR_ID_PBCFG_H)
    #error "Igf_Port_Ip_Cfg.h and Igf_Port_Ip_PBcfg.h have different vendor ids"
#endif
/* Check if Igf_Port_Ip_Cfg.h and Igf_Port_Ip_PBcfg.h are of the same Autosar version */
#if ((IGF_PORT_IP_AR_RELEASE_MAJOR_VERSION_CFG_H    != IGF_PORT_IP_AR_RELEASE_MAJOR_VERSION_PBCFG_H) || \
     (IGF_PORT_IP_AR_RELEASE_MINOR_VERSION_CFG_H    != IGF_PORT_IP_AR_RELEASE_MINOR_VERSION_PBCFG_H) || \
     (IGF_PORT_IP_AR_RELEASE_REVISION_VERSION_CFG_H != IGF_PORT_IP_AR_RELEASE_REVISION_VERSION_PBCFG_H) \
    )
    #error "AutoSar Version Numbers of Igf_Port_Ip_Cfg.h and Igf_Port_Ip_PBcfg.h are different"
#endif
/* Check if Igf_Port_Ip_Cfg.h and Igf_Port_Ip_PBcfg.h are of the same Software version */
#if ((IGF_PORT_IP_SW_MAJOR_VERSION_CFG_H != IGF_PORT_IP_SW_MAJOR_VERSION_PBCFG_H) || \
     (IGF_PORT_IP_SW_MINOR_VERSION_CFG_H != IGF_PORT_IP_SW_MINOR_VERSION_PBCFG_H) || \
     (IGF_PORT_IP_SW_PATCH_VERSION_CFG_H != IGF_PORT_IP_SW_PATCH_VERSION_PBCFG_H)    \
    )
    #error "Software Version Numbers of Igf_Port_Ip_Cfg.h and Igf_Port_Ip_PBcfg.h are different"
#endif
    [!ENDIF!][!//
[!ENDIF!][!//
/*=================================================================================================
*                                          CONSTANTS
=================================================================================================*/


/*=================================================================================================
*                                       DEFINES AND MACROS
=================================================================================================*/
[!IF "contains(as:modconf("Resource")[1]/ResourceGeneral/ResourceSubderivative, 's32k396') or contains(as:modconf("Resource")[1]/ResourceGeneral/ResourceSubderivative, 's32k394')"!][!//  /* S32K394: sub/phantom derivatives of S32K396 */
/*! @brief User number of configured input glitch filter */
[!SELECT "PortConfigSet"!][!//
[!VAR "count"= "1"!][!//
[!NOCODE!]
[!/* Count maximum number of configured IGF channels. */!][!//
[!VAR "MaxNoOfConfiguredIgfChannels" = "0"!][!//
[!LOOP "PortContainer/*/PortPin/*"!][!//
    [!/* Check if the IGF Settings container is enabled */!][!//
    [!IF "boolean(./IGFSettings)"!][!//
        [!/* Check if the FGEN bit is enabled. If not, it means that we will not touch the IGF channel settings */!][!//
        [!IF "./IGFSettings/IGF_FGEN"!][!//
            [!VAR "MaxNoOfConfiguredIgfChannels"= "$MaxNoOfConfiguredIgfChannels+1"!][!//
        [!ENDIF!][!//
    [!ENDIF!][!//
[!ENDLOOP!][!//
[!CODE!][!//
#define IGF_NUM_OF_CHANNELS_CONFIG      ((uint8)[!"num:i($MaxNoOfConfiguredIgfChannels)"!]U)
[!ENDCODE!][!//
[!ENDNOCODE!][!//
[!ENDSELECT!][!//

[!INDENT "0"!][!//
    [!IF "$MaxNoOfConfiguredIgfChannels>0"!][!//
    [!CODE!][!//
    #define PORT_START_SEC_CONFIG_DATA_UNSPECIFIED
    #include "Port_MemMap.h"

    [!IF "var:defined('postBuildVariant')"!][!//
    [!LOOP "variant:all()"!][!//
    IGF_PORT_CONFIG_[!"."!]_PB \
    [!ENDLOOP!][!//
    [!ELSE!][!//
    IGF_PORT_CONFIG_PB
    [!ENDIF!][!//

    #define PORT_STOP_SEC_CONFIG_DATA_UNSPECIFIED
    #include "Port_MemMap.h"
    [!ENDCODE!][!//
    [!ENDIF!][!//
[!ENDINDENT!][!//
[!ENDIF!][!//
/*=================================================================================================
*                                             ENUMS
=================================================================================================*/


/*=================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
=================================================================================================*/


/*=================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
=================================================================================================*/

/*=================================================================================================
*                                    FUNCTION PROTOTYPES
=================================================================================================*/

#ifdef __cplusplus
}
#endif

/** @} */

#endif /* IGF_PORT_IP_CFG_H */
