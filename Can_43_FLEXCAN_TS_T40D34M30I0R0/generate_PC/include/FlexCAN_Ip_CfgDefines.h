
/*==================================================================================================
*   Project              : RTD AUTOSAR 4.7
*   Platform             : CORTEXM
*   Peripheral           : FLEXCAN
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
#ifndef FLEXCAN_IP_CFGDEFINES_H
#define FLEXCAN_IP_CFGDEFINES_H

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
[!NOCODE!][!// Include headers for FlexCAN_Ip_DeviceReg.h
[!IF "node:exists(as:modconf("Resource")[1]/ResourceGeneral/ResourceSubderivative)"!][!// 
    [!VAR "DerivativeName" = "text:toupper(substring-before(as:modconf("Resource")[1]/ResourceGeneral/ResourceSubderivative,'_'))"!]
   
    [!IF "contains($DerivativeName, 'S32K3')"!][!//  
        [!IF "contains($DerivativeName, 'S32K310')"!][!//
            /* Use S32K311 header files as common for S32K310 and S32K311 */
            [!VAR "DerivativeName" = "'S32K311'"!]
        [!ELSEIF "contains($DerivativeName, 'S32K39')"!][!//
            /* Use S32K39 header files as common for S32K394 and S32K396 */
            [!VAR "DerivativeName" = "'S32K39'"!]
        [!ELSEIF "contains($DerivativeName, 'S32K328') or contains($DerivativeName, 'S32K338') or contains($DerivativeName, 'S32K348')"!][!//
            /* Use S32K358 header files as common for phantom derivatives of S32K358 */
            [!VAR "DerivativeName" = "'S32K358'"!]
        [!ENDIF!][!//
        [!CODE!][!WS "0"!]
        #include "[!"$DerivativeName"!].h"
        [!CR!][!ENDCODE!][!//
    [!ELSEIF "contains($DerivativeName, 'S32M')"!][!//
        /* Use S32M27x header files as common for S32M274 and S32M276 */
        [!CODE!][!WS "0"!]
        #include "S32M27x.h"
        [!CR!][!ENDCODE!][!//
    [!ELSE!]
        [!CODE!][!WS "0"!]
        #error "Unknown platform!"
        [!CR!][!ENDCODE!][!//
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
/*
* @file           FlexCAN_Ip_CfgDefines.h
*/
#define FLEXCAN_IP_CFGDEFINES_VENDOR_ID_H                      43
#define FLEXCAN_IP_CFGDEFINES_AR_RELEASE_MAJOR_VERSION_H       4
#define FLEXCAN_IP_CFGDEFINES_AR_RELEASE_MINOR_VERSION_H       7
#define FLEXCAN_IP_CFGDEFINES_AR_RELEASE_REVISION_VERSION_H    0
#define FLEXCAN_IP_CFGDEFINES_SW_MAJOR_VERSION_H               3
#define FLEXCAN_IP_CFGDEFINES_SW_MINOR_VERSION_H               0
#define FLEXCAN_IP_CFGDEFINES_SW_PATCH_VERSION_H               0
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

#endif /* FLEXCAN_IP_CFGDEFINES_H */
