[!CODE!][!//
/*==================================================================================================
*   Project              : RTD AUTOSAR 4.7
*   Platform             : CORTEXM
*   Peripheral           : ADC_SAR
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

#ifndef BCTU_IP_CFGDEFINES_H
#define BCTU_IP_CFGDEFINES_H

/**
*   @file
*
*   @addtogroup bctu_ip_driver_config Bctu IPL Configuration
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
[!INDENT "0"!][!//
[!NOCODE!][!//
[!IF "node:exists(as:modconf("Resource")[1]/ResourceGeneral/ResourceSubderivative)"!][!//
    [!VAR "DerivativeName" = "text:toupper(substring-before(as:modconf("Resource")[1]/ResourceGeneral/ResourceSubderivative,'_'))"!][!//
    [!IF "contains($DerivativeName, 'S32K3') or contains($DerivativeName, 'S32M27')"!][!//
        [!IF "contains($DerivativeName, 'S32K341')"!][!//
            [!CODE!][!WS "0"!]#include "S32K341_ADC.h"[!CR!][!ENDCODE!][!//
            [!CODE!][!WS "0"!]#include "S32K341_BCTU.h"[!CR!][!ENDCODE!][!//
        [!ELSEIF "contains($DerivativeName, 'S32K39')"!]
            [!CODE!][!WS "0"!]#include "S32K39_ADC.h"[!CR!][!ENDCODE!][!//
            [!CODE!][!WS "0"!]#include "S32K39_BCTU.h"[!CR!][!ENDCODE!][!//
        [!ELSEIF "contains($DerivativeName, 'S32K328') or contains($DerivativeName, 'S32K338') or contains($DerivativeName, 'S32K348') or contains($DerivativeName, 'S32K358')"!]
            [!CODE!][!WS "0"!]#include "S32K358_ADC.h"[!CR!][!ENDCODE!][!//
            [!CODE!][!WS "0"!]#include "S32K358_BCTU.h"[!CR!][!ENDCODE!][!//
        [!ELSEIF "contains($DerivativeName, 'S32M27')"!]
            [!CODE!][!WS "0"!]#include "S32M27x_ADC.h"[!CR!][!ENDCODE!][!//
            [!CODE!][!WS "0"!]#include "S32M27x_BCTU.h"[!CR!][!ENDCODE!][!//
        [!ELSEIF "contains($DerivativeName, 'S32K310')"!]
            [!CODE!][!WS "0"!]#include "S32K311_ADC.h"[!CR!][!ENDCODE!][!//
            [!CODE!][!WS "0"!]#include "S32K311_BCTU.h"[!CR!][!ENDCODE!][!//
        [!ELSE!][!//
            [!CODE!][!WS "0"!]#include "[!"$DerivativeName"!]_ADC.h"[!CR!][!ENDCODE!][!//
            [!CODE!][!WS "0"!]#include "[!"$DerivativeName"!]_BCTU.h"[!CR!][!ENDCODE!][!//
        [!ENDIF!][!//
    [!ELSE!][!//
        [!CODE!][!WS "0"!]#error "Unknown platform!"[!CR!][!ENDCODE!][!//
    [!ENDIF!][!//
[!ELSE!][!//
    [!CODE!][!WS "0"!]#error "Unknown platform!"[!CR!][!ENDCODE!][!//
[!ENDIF!][!//
[!ENDNOCODE!][!//
[!ENDINDENT!][!//
#include "OsIf.h"
[!NOCODE!][!//
[!INCLUDE "Adc_VersionCheck_Src.m"!][!//
[!INCLUDE "Adc_RegOperations.m"!][!//
[!ENDNOCODE!][!//

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/

#define BCTU_IP_VENDOR_ID_CFGDEFINES                       43
#define BCTU_IP_AR_RELEASE_MAJOR_VERSION_CFGDEFINES        4
#define BCTU_IP_AR_RELEASE_MINOR_VERSION_CFGDEFINES        7
#define BCTU_IP_AR_RELEASE_REVISION_VERSION_CFGDEFINES     0
#define BCTU_IP_SW_MAJOR_VERSION_CFGDEFINES                3
#define BCTU_IP_SW_MINOR_VERSION_CFGDEFINES                0
#define BCTU_IP_SW_PATCH_VERSION_CFGDEFINES                0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
/* Check if Bctu_Ip_CfgDefines.h file and OsIf.h file are of the same Autosar version */
#if ((BCTU_IP_AR_RELEASE_MAJOR_VERSION_CFGDEFINES != OSIF_AR_RELEASE_MAJOR_VERSION) || \
     (BCTU_IP_AR_RELEASE_MINOR_VERSION_CFGDEFINES != OSIF_AR_RELEASE_MINOR_VERSION)    \
    )
    #error "AutoSar Version Numbers of Bctu_Ip_CfgDefines.h and OsIf.h are different"
#endif
#endif

/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/

[!CALL "BctuIpCfgDefinesMacro"!][!//
#define BCTU_IP_FIFO_COUNT                       ([!"(num:i(ecu:get('Adc.AdcConfigSet.BctuHwUnit.BctuNumberFifoBlock')))"!]U)
#define BCTU_IP_INVALID_DMA_CHANNEL_ID           (0xFFU)
[!IF "AutosarExt/CtuEnableDmaTransferMode"!][!//
#define BCTU_IP_DMA_SUPPORTED
[!IF "num:i(count(AdcConfigSet/BctuHwUnit/*[BctuFifoDmaRawData = 'true'])) > 0"!][!//
#define BCTU_IP_FIFO_DMA_RAW_EN
[!ENDIF!][!//
[!ENDIF!][!//

[!CALL "BctuIpAdcIndexOffsetMacro"!][!//

[!NOCODE!][!//
[!VAR "MaxBctuUnit" = "num:i(ecu:get('Adc.AdcConfigSet.BctuHwUnit'))"!][!//
[!VAR "MaxNumAdcCount" = "num:i(ecu:get('Adc.AdcConfigSet.BctuHwUnit0.AdcHwUnitCount'))"!][!//
[!FOR "Unit" = "0" TO "$MaxBctuUnit - 1"!][!//
    [!VAR "TempNumAdcCount" = "num:i(ecu:get(concat('Adc.AdcConfigSet.BctuHwUnit', $Unit, '.AdcHwUnitCount')))"!][!//
    [!IF "($MaxNumAdcCount < $TempNumAdcCount)"!][!//
        [!VAR "MaxNumAdcCount" = "$TempNumAdcCount"!][!//
    [!ENDIF!][!//
    [!IF "$Unit = ($MaxBctuUnit - 1)"!][!//
[!CODE!][!//
#define FEATURE_BCTU_NUM_ADC                     ([!"$MaxNumAdcCount"!]U)
[!ENDCODE!][!//
    [!ENDIF!][!//
[!ENDFOR!][!//
[!ENDNOCODE!][!//
/*==================================================================================================
*                                             ENUMS
==================================================================================================*/

/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                      LOCAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/


#ifdef __cplusplus
}
#endif

/** @} */

#endif /* BCTU_IP_CFGDEFINES_H */
[!ENDCODE!]
