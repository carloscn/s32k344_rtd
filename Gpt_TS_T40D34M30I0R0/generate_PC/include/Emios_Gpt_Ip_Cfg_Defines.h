/*==================================================================================================
* Project : RTD AUTOSAR 4.7
* Platform : CORTEXM
* Peripheral : Stm_Pit_Rtc_Emios
* Dependencies : none
*
* Autosar Version : 4.7.0
* Autosar Revision : ASR_REL_4_7_REV_0000
* Autosar Conf.Variant :
* SW Version : 3.0.0
* Build Version : S32K3_RTD_3_0_0_D2303_ASR_REL_4_7_REV_0000_20230331
*
* Copyright 2020 - 2023 NXP Semiconductors
*
* NXP Confidential. This software is owned or controlled by NXP and may only be
* used strictly in accordance with the applicable license terms. By expressly
* accepting such terms or by downloading, installing, activating and/or otherwise
* using the software, you are agreeing that you have read, and that you agree to
* comply with and are bound by, such license terms. If you do not agree to be
* bound by the applicable license terms, then you may not retain, install,
* activate or otherwise use the software.
==================================================================================================*/

#ifndef EMIOS_GPT_IP_CFG_DEFINES_H
#define EMIOS_GPT_IP_CFG_DEFINES_H

/**
*   @file           Emios_Gpt_Ip_Cfg_Defines.h
*
*   @addtogroup     emios_ip Emios IPL
*
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
#include "Std_Types.h"
[!NOCODE!][!// Include specific header file
[!IF "node:exists(as:modconf("Resource")[1]/ResourceGeneral/ResourceSubderivative)"!][!//
    [!VAR "DerivativeName" = "text:toupper(substring-before(as:modconf("Resource")[1]/ResourceGeneral/ResourceSubderivative,'_'))"!][!//
    [!CODE!][!WS "0"!]/* Include platform header file. */[!CR!][!ENDCODE!][!//
    [!IF "contains(as:modconf("Resource")[1]/ResourceGeneral/ResourceSubderivative, 's32k328') or
            contains(as:modconf("Resource")[1]/ResourceGeneral/ResourceSubderivative, 's32k338') or
            contains(as:modconf("Resource")[1]/ResourceGeneral/ResourceSubderivative, 's32k348') or
            contains(as:modconf("Resource")[1]/ResourceGeneral/ResourceSubderivative, 's32k358')"!][!//
        [!CODE!][!WS "0"!]#include "S32K358_EMIOS.h"[!CR!][!ENDCODE!][!//
    [!ELSEIF "contains(as:modconf("Resource")[1]/ResourceGeneral/ResourceSubderivative, 's32k310') or
                contains(as:modconf("Resource")[1]/ResourceGeneral/ResourceSubderivative, 's32k311')"!][!//
        [!CODE!][!WS "0"!]#include "S32K311_EMIOS.h"[!CR!][!ENDCODE!][!//
    [!ELSEIF "contains(as:modconf("Resource")[1]/ResourceGeneral/ResourceSubderivative, 's32k39')"!][!//
        [!CODE!][!WS "0"!]#include "S32K39_EMIOS.h"[!CR!][!ENDCODE!][!//
    [!ELSEIF "contains(as:modconf("Resource")[1]/ResourceGeneral/ResourceSubderivative, 's32m27')"!][!//
        [!CODE!][!WS "0"!]#include "S32M27x_EMIOS.h"[!CR!][!ENDCODE!][!//
    [!ELSEIF "contains(as:modconf("Resource")[1]/ResourceGeneral/ResourceSubderivative, 's32z27x')"!][!//
        [!CODE!][!WS "0"!]#include "S32Z2_EMIOS.h"[!CR!][!ENDCODE!][!//
    [!ELSEIF "contains(as:modconf("Resource")[1]/ResourceGeneral/ResourceSubderivative, 's32e27x')"!][!//
        [!CODE!][!WS "0"!]#include "S32E2_EMIOS.h"[!CR!][!ENDCODE!][!//
    [!ELSE!][!//
        [!CODE!][!WS "0"!]#include "[!"$DerivativeName"!]_EMIOS.h"[!CR!][!ENDCODE!][!//
    [!ENDIF!][!//
[!ELSE!][!//
    [!ERROR "The Resource plugins or ResourceSubderivative field is not available for header file inclusion."!][!//
[!ENDIF!][!//
[!ENDNOCODE!][!//
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define EMIOS_GPT_IP_CFG_DEFINES_VENDOR_ID                    43
#define EMIOS_GPT_IP_CFG_DEFINES_AR_RELEASE_MAJOR_VERSION     4
#define EMIOS_GPT_IP_CFG_DEFINES_AR_RELEASE_MINOR_VERSION     7
#define EMIOS_GPT_IP_CFG_DEFINES_AR_RELEASE_REVISION_VERSION  0
#define EMIOS_GPT_IP_CFG_DEFINES_SW_MAJOR_VERSION             3
#define EMIOS_GPT_IP_CFG_DEFINES_SW_MINOR_VERSION             0
#define EMIOS_GPT_IP_CFG_DEFINES_SW_PATCH_VERSION             0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if header file and Std_Types.h file are of the same Autosar version */
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if ((EMIOS_GPT_IP_CFG_DEFINES_AR_RELEASE_MAJOR_VERSION != STD_AR_RELEASE_MAJOR_VERSION) || \
         (EMIOS_GPT_IP_CFG_DEFINES_AR_RELEASE_MINOR_VERSION != STD_AR_RELEASE_MINOR_VERSION))
    #error "AutoSar Version Numbers of Emios_Gpt_Ip_Cfg_Defines.h and Std_Types.h are different"
    #endif
#endif
/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/
[!NOCODE!][!//
[!VAR "MacEmiosUsed"="0"!][!//
    // Loop on all channels inside the same Configuration Set
    [!LOOP "GptHwConfiguration/*"!][!//
        [!IF "node:value(GptChannelIsUsed) = 'true' and contains(GptIsrHwId, 'EMIOS')"!][!//
            [!VAR "MacEmiosUsed"="1"!][!//
        [!ENDIF!][!//
    [!ENDLOOP!][!//
[!ENDNOCODE!][!//

/**
* @brief These defines indicate that at least one channel from each module is used in all configurations.
*/
#define EMIOS_GPT_IP_USED ([!IF "$MacEmiosUsed=1"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])
/*================================================================================================*/
/**
* @brief    EMIOS_GPT_IP_SET_CLOCK_MODE switch
* @details  Enable/disable API for Dual Mode support.
*/
#define EMIOS_GPT_IP_SET_CLOCK_MODE           ([!IF "GptAutosarExt/GptEnableDualClockMode"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])
/**
*
* @brief IRQ Defines for each channel used
*/
[!NOCODE!][!//
[!LOOP "GptHwConfiguration/*"!][!//
    [!IF "(GptChannelIsUsed = 'true') and (GptIsrEnable = 'true')"!][!//
        [!IF "contains(GptIsrHwId,"EMIOS")"!][!//
                [!CODE!][!//
#define GPT_[!"GptIsrHwId"!]_ISR_USED
                [!ENDCODE!][!//
        [!ENDIF!][!//
    [!ENDIF!]//
[!ENDLOOP!][!//
[!ENDNOCODE!][!//

[!NOCODE!][!//
[!CODE!]/* Macros that indicate EMIOS interrupts used by GPT. */[!CR!][!ENDCODE!][!//
    [!LOOP "GptHwConfiguration/*"!][!//
        [!IF "(node:value(./GptIsrEnable) = 'true') and (text:split(node:value(./GptIsrHwId), '_')[1] = 'EMIOS')"!][!//
            [!CODE!][!WS "4"!]#ifndef [!"node:value(./GptIsrHwId)"!]_ISR_USED[!CR!][!ENDCODE!][!//
            [!CODE!][!WS "8"!]#define GPT_[!"node:value(./GptIsrHwId)"!]_ISR_USED[!CR!][!ENDCODE!][!//
            [!CODE!][!WS "8"!]#define [!"node:value(./GptIsrHwId)"!]_ISR_USED[!CR!][!ENDCODE!][!//
            [!CODE!][!WS "4"!]#else[!CR!][!ENDCODE!][!//
            [!CODE!][!WS "8"!]#error "[!"node:value(./GptIsrHwId)"!] interrupt cannot be used by Gpt driver. Channel locked by other driver!"[!CR!][!ENDCODE!][!//
            [!CODE!][!WS "4"!]#endif[!CR!][!CR!][!ENDCODE!][!//
        [!ENDIF!][!//
    [!ENDLOOP!][!//
[!ENDNOCODE!][!//

/*================================================================================================*/

/*================================================================================================*/

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
*                                    FUNCTION PROTOTYPES
==================================================================================================*/

#ifdef __cplusplus
}
#endif
/** @} */

#endif  /* EMIOS_GPT_IP_CFG_DEFINES_H */
