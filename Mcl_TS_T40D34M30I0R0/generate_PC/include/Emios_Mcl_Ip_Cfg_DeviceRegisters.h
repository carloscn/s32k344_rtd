[!AUTOSPACING!][!//
[!CODE!][!//
/*==================================================================================================
*   Project              : RTD AUTOSAR 4.7
*   Platform             : CORTEXM
*   Peripheral           : DMA,CACHE,TRGMUX,LCU,EMIOS,FLEXIO
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
*
*   NXP Confidential. This software is owned or controlled by NXP and may only be
*   used strictly in accordance with the applicable license terms. By expressly
*   accepting such terms or by downloading, installing, activating and/or otherwise
*   using the software, you are agreeing that you have read, and that you agree to
*   comply with and are bound by, such license terms. If you do not agree to be
*   bound by the applicable license terms, then you may not retain, install,
*   activate or otherwise use the software.
==================================================================================================*/

#ifndef EMIOS_MCL_IP_CFG_DEVICEREGISTERS_H
#define EMIOS_MCL_IP_CFG_DEVICEREGISTERS_H
/**
*   @file Emios_Mcl_Ip_Cfg_DeviceRegisters.h
*
*   @version 3.0.0
*
*   @brief   AUTOSAR Mcl - MCL driver header file.
*   @details
*
*   @addtogroup MCL_DRIVER MCL Driver
*   @{
*/
#ifdef __cplusplus
extern "C"
{
#endif

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
[!INDENT "0"!][!//
[!IF "node:exists(as:modconf("Resource")[1]/ResourceGeneral/ResourceSubderivative)"!][!//
    [!VAR "DerivativeName" = "text:toupper(substring-before(as:modconf("Resource")[1]/ResourceGeneral/ResourceSubderivative,'_'))"!]
    [!IF "contains($DerivativeName, 'S32K3')"!][!//
        [!CODE!][!WS "0"!]/* Include platform header file. */[!CR!][!ENDCODE!][!//
        [!IF "contains($DerivativeName, 'S32K396') or contains($DerivativeName, 'S32K394')"!][!//
            [!CODE!][!WS "0"!]#include "S32K39_EMIOS.h"[!CR!][!ENDCODE!][!//
        [!ELSEIF "contains($DerivativeName, 'S32K310')"!][!//
            [!CODE!][!WS "0"!]#include "S32K311_EMIOS.h"[!CR!][!ENDCODE!][!//
        [!ELSEIF "contains($DerivativeName, 'S32K328') or contains($DerivativeName, 'S32K338') or contains($DerivativeName, 'S32K348')"!][!//
            [!CODE!][!WS "0"!]#include "S32K358_EMIOS.h"[!CR!][!ENDCODE!][!//
        [!ELSE!][!//
            [!CODE!][!WS "0"!]#include "[!"$DerivativeName"!]_EMIOS.h"[!CR!][!ENDCODE!][!//
        [!ENDIF!][!//
    [!ELSEIF "contains($DerivativeName, 'S32M276') or contains($DerivativeName, 'S32M274')"!][!//
        [!CODE!][!WS "0"!]#include "S32M27x_EMIOS.h"[!CR!][!ENDCODE!][!//
    [!ELSE!][!//
        [!ERROR "The Resource plugin or ResourceSubderivative field is not available for header file inclusion."!][!//
    [!ENDIF!][!//
[!ENDIF!][!//
[!ENDINDENT!][!//

/*==================================================================================================
*                               HEADER FILE VERSION INFORMATION
==================================================================================================*/
#define EMIOS_MCL_IP_CFG_DEVICEREGISTERS_VENDOR_ID                       43
#define EMIOS_MCL_IP_CFG_DEVICEREGISTERS_AR_RELEASE_MAJOR_VERSION        4
#define EMIOS_MCL_IP_CFG_DEVICEREGISTERS_AR_RELEASE_MINOR_VERSION        7
#define EMIOS_MCL_IP_CFG_DEVICEREGISTERS_AR_RELEASE_REVISION_VERSION     0
#define EMIOS_MCL_IP_CFG_DEVICEREGISTERS_SW_MAJOR_VERSION                3
#define EMIOS_MCL_IP_CFG_DEVICEREGISTERS_SW_MINOR_VERSION                0
#define EMIOS_MCL_IP_CFG_DEVICEREGISTERS_SW_PATCH_VERSION                0


#ifdef __cplusplus
}
#endif

#endif /* EMIOS_MCL_IP_CFG_DEVICEREGISTERS_H */
[!ENDCODE!][!//
