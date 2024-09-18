
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
#ifndef AECANPHY_IP_CFGDEFINES_H
#define AECANPHY_IP_CFGDEFINES_H

#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit

==================================================================================================*/
[!INDENT "0"!]
[!NOCODE!][!// Include headers for AeCanPHY_Ip_CfgDefines.h
[!IF "node:exists(as:modconf("Resource")[1]/ResourceGeneral/ResourceSubderivative)"!][!//
    [!VAR "DerivativeName" = "text:toupper(substring-before(as:modconf("Resource")[1]/ResourceGeneral/ResourceSubderivative,'_'))"!]
    [!IF "contains($DerivativeName, 'S32M27')"!][!//
        [!CODE!][!WS "0"!]
        #include "S32M27x_AEC_AE.h"
        [!CR!][!ENDCODE!][!//
    [!ELSE!]
        [!ERROR!]
            The AeCanPHY is not supported in the Derivative.
        [!ENDERROR!]
    [!ENDIF!][!//
[!ELSE!]
    [!CODE!][!WS "0"!]
    #error "Unknown platform!"
    [!CR!][!ENDCODE!][!//
[!ENDIF!][!//
[!ENDNOCODE!][!//
[!ENDINDENT!]
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define AECANPHY_IP_CFGDEFINES_VENDOR_ID_H                      43
#define AECANPHY_IP_CFGDEFINES_AR_RELEASE_MAJOR_VERSION_H       4
#define AECANPHY_IP_CFGDEFINES_AR_RELEASE_MINOR_VERSION_H       7
#define AECANPHY_IP_CFGDEFINES_AR_RELEASE_REVISION_VERSION_H    0
#define AECANPHY_IP_CFGDEFINES_SW_MAJOR_VERSION_H               3
#define AECANPHY_IP_CFGDEFINES_SW_MINOR_VERSION_H               0
#define AECANPHY_IP_CFGDEFINES_SW_PATCH_VERSION_H               0
/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/

/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/


#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* AECANPHY_IP_CFGDEFINES_H */
