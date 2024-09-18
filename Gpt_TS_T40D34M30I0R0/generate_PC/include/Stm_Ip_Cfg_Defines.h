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

#ifndef STM_IP_CFG_DEFINES_H
#define STM_IP_CFG_DEFINES_H

/**
*   @file           Stm_Ip_Cfg_Defines.h
*
*   @addtogroup     stm_ip Stm IPL
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
    [!IF "contains(as:modconf("Resource")[1]/ResourceGeneral/ResourceSubderivative, 's32k328') or
            contains(as:modconf("Resource")[1]/ResourceGeneral/ResourceSubderivative, 's32k338') or
            contains(as:modconf("Resource")[1]/ResourceGeneral/ResourceSubderivative, 's32k348') or
            contains(as:modconf("Resource")[1]/ResourceGeneral/ResourceSubderivative, 's32k358')"!][!//
        [!CODE!][!WS "0"!]#include "S32K358_STM.h"[!CR!][!ENDCODE!][!//
    [!ELSEIF "contains(as:modconf("Resource")[1]/ResourceGeneral/ResourceSubderivative, 's32k310') or
                contains(as:modconf("Resource")[1]/ResourceGeneral/ResourceSubderivative, 's32k311')"!][!//
        [!CODE!][!WS "0"!]#include "S32K311_STM.h"[!CR!][!ENDCODE!][!//
    [!ELSEIF "contains(as:modconf("Resource")[1]/ResourceGeneral/ResourceSubderivative, 's32k39')"!][!//
        [!CODE!][!WS "0"!]#include "S32K39_STM.h"[!CR!][!ENDCODE!][!//
    [!ELSEIF "contains(as:modconf("Resource")[1]/ResourceGeneral/ResourceSubderivative, 's32m27')"!][!//
        [!CODE!][!WS "0"!]#include "S32M27x_STM.h"[!CR!][!ENDCODE!][!//
    [!ELSEIF "contains(as:modconf("Resource")[1]/ResourceGeneral/ResourceSubderivative, 'saf85')"!][!//
        [!CODE!][!WS "0"!]#include "SAF85XX_STM.h"[!CR!][!ENDCODE!][!//
    [!ELSEIF "contains(as:modconf("Resource")[1]/ResourceGeneral/ResourceSubderivative, 's32z27x')"!][!//
        [!CODE!][!WS "0"!]#include "S32Z2_STM.h"[!CR!][!ENDCODE!][!//
    [!ELSEIF "contains(as:modconf("Resource")[1]/ResourceGeneral/ResourceSubderivative, 's32e27x')"!][!//
        [!CODE!][!WS "0"!]#include "S32E2_STM.h"[!CR!][!ENDCODE!][!//
    [!ELSEIF "contains(as:modconf("Resource")[1]/ResourceGeneral/ResourceSubderivative, 's32n')"!][!//
        [!CODE!][!WS "0"!]#include "S32N2RT_STM.h"[!CR!][!ENDCODE!][!//
    [!ELSE!][!//
        [!CODE!][!WS "0"!]#include "[!"$DerivativeName"!]_STM.h"[!CR!][!ENDCODE!][!//
    [!ENDIF!][!//
[!ELSE!][!//
    [!ERROR "The Resource plugins or ResourceSubderivative field is not available for header file inclusion."!][!//
[!ENDIF!][!//
[!ENDNOCODE!][!//

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define STM_IP_DEFINES_VENDOR_ID_CFG                    43
#define STM_IP_DEFINES_AR_RELEASE_MAJOR_VERSION_CFG     4
#define STM_IP_DEFINES_AR_RELEASE_MINOR_VERSION_CFG     7
#define STM_IP_DEFINES_AR_RELEASE_REVISION_VERSION_CFG  0
#define STM_IP_DEFINES_SW_MAJOR_VERSION_CFG             3
#define STM_IP_DEFINES_SW_MINOR_VERSION_CFG             0
#define STM_IP_DEFINES_SW_PATCH_VERSION_CFG             0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if header file and Std_Types.h file are of the same Autosar version */
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if ((STM_IP_DEFINES_AR_RELEASE_MAJOR_VERSION_CFG != STD_AR_RELEASE_MAJOR_VERSION) || \
         (STM_IP_DEFINES_AR_RELEASE_MINOR_VERSION_CFG != STD_AR_RELEASE_MINOR_VERSION))
    #error "AutoSar Version Numbers of Stm_Ip_Cfg_Defines.h and Std_Types.h are different"
    #endif
#endif
/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/
[!NOCODE!][!//
[!VAR "MacStmUsed"="0"!][!//
    // Loop on all channels inside the same Configuration Set
    [!LOOP "GptHwConfiguration/*"!][!//
        [!IF "node:value(GptChannelIsUsed) = 'true' and contains(GptIsrHwId, 'STM')"!][!//
            [!VAR "MacStmUsed"="1"!][!//
        [!ENDIF!][!//
    [!ENDLOOP!][!//
[!ENDNOCODE!][!//

/**
* @brief These defines indicate that at least one channel from each module is used in all configurations.
*/
#define STM_IP_USED ([!IF "$MacStmUsed=1"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

/*================================================================================================*/
/**
* @brief This define is used to select between interrupt on each channel and source interrupt
*        on entire module sources hardware implementations.
*
*/
#define STM_IP_MODULE_SINGLE_INTERRUPT [!IF "ecu:get('Gpt.GptConfig.Gpt_STM_ModuleSingleInterrupt')='STD_ON'"!](STD_ON)[!ELSE!](STD_OFF)[!ENDIF!]

/*================================================================================================*/
/**
* @brief    STM_IP_SET_CLOCK_MODE switch
* @details  Enable/disable API for Dual Mode support.
*/
#define STM_IP_SET_CLOCK_MODE           ([!IF "GptAutosarExt/GptEnableDualClockMode"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])


/**
* @{
* @brief IRQ Defines for each channel used
*/
[!NOCODE!][!//
[!VAR "AlreadyParsedModule"!][!ENDVAR!][!//
[!LOOP "GptHwConfiguration/*"!][!//
    [!IF "(GptChannelIsUsed = 'true') and (GptIsrEnable = 'true')"!][!//
        [!IF "contains(GptIsrHwId,"SMU_STM") or contains(GptIsrHwId,"CE_STM")"!][!//
            [!VAR "ModuleUsed"="concat(concat(text:split(GptIsrHwId,'_')[1], '_', text:split(GptIsrHwId,'_')[2]), '_' , text:split(GptIsrHwId,'_')[3])"!][!//
            [!IF "contains($AlreadyParsedModule, $ModuleUsed) = false()"!][!//
                [!CODE!][!//
#define [!"$ModuleUsed"!]_ISR_USED
                [!ENDCODE!][!//
                [!VAR "AlreadyParsedModule"="concat($AlreadyParsedModule,$ModuleUsed,'|')"!][!//
            [!ENDIF!][!//
        [!ELSEIF "contains(GptIsrHwId,"RTU0_STM") or contains(GptIsrHwId,"RTU1_STM")"!][!//
            [!VAR "ModuleUsed"="concat(concat(text:split(GptIsrHwId,'_')[1], '_', text:split(GptIsrHwId,'_')[2]), '_' , text:split(GptIsrHwId,'_')[3])"!][!//
            [!VAR "Instance"="substring-before(substring-after(GptIsrHwId , '_'), '_CH')"!][!//
            [!IF "contains($AlreadyParsedModule, $ModuleUsed) = false()"!][!//
                [!CODE!][!//
#define [!"$ModuleUsed"!]_ISR_USED
                [!ENDCODE!][!//
                [!VAR "AlreadyParsedModule"="concat($AlreadyParsedModule,$ModuleUsed,'|')"!][!//
            [!ENDIF!][!//
        [!ELSEIF "contains(GptIsrHwId,"STM")"!][!//
            [!IF "contains($AlreadyParsedModule, concat(text:split(GptIsrHwId,'_')[1], '_', text:split(GptIsrHwId,'_')[2])) = false()"!][!//
                [!CODE!][!//
                    [!VAR "ModuleUsed"="concat(text:split(GptIsrHwId,'_')[1], '_', text:split(GptIsrHwId,'_')[2])"!][!//
#define [!"$ModuleUsed"!]_ISR_USED
                [!ENDCODE!][!//
                [!VAR "AlreadyParsedModule"="concat($AlreadyParsedModule,text:split(GptIsrHwId,'_')[1], '_', text:split(GptIsrHwId,'_')[2],'|')"!][!//
            [!ENDIF!][!//
        [!ENDIF!][!//
    [!ENDIF!]//
[!ENDLOOP!][!//
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
*                                    FUNCTION PROTOTYPES
==================================================================================================*/

#ifdef __cplusplus
}
#endif
/** @} */

#endif  /* STM_IP_CFG_DEFINES_H */
