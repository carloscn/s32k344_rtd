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

#ifndef EMIOS_MCL_IP_CFG_DEFINES_H
#define EMIOS_MCL_IP_CFG_DEFINES_H
/**
*   @file Emios_Mcl_Ip_Cfg_Defines.h
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
#include "Emios_Mcl_Ip_Cfg_DeviceRegisters.h"

[!IF "node:accessible(//Icu)"!][!//
#include "Emios_Icu_Ip_Cfg.h"
[!ENDIF!][!//
[!IF "node:accessible(//Pwm)"!][!//
#include "Emios_Pwm_Ip_CfgDefines.h"
[!ENDIF!][!//
[!IF "node:accessible(//Ocu)"!][!//
#include "Emios_Ocu_Ip_CfgDefines.h"
[!ENDIF!][!//
[!IF "node:accessible(//Gpt)"!][!//
#include "Emios_Gpt_Ip_Cfg_Defines.h"
[!ENDIF!][!//

/*==================================================================================================
*                               HEADER FILE VERSION INFORMATION
==================================================================================================*/
#define EMIOS_MCL_IP_CFG_DEFINES_VENDOR_ID                       43
#define EMIOS_MCL_IP_CFG_DEFINES_AR_RELEASE_MAJOR_VERSION        4
#define EMIOS_MCL_IP_CFG_DEFINES_AR_RELEASE_MINOR_VERSION        7
#define EMIOS_MCL_IP_CFG_DEFINES_AR_RELEASE_REVISION_VERSION     0
#define EMIOS_MCL_IP_CFG_DEFINES_SW_MAJOR_VERSION                3
#define EMIOS_MCL_IP_CFG_DEFINES_SW_MINOR_VERSION                0
#define EMIOS_MCL_IP_CFG_DEFINES_SW_PATCH_VERSION                0
/*==================================================================================================
*                                      FILE VERSION CHECKS
==================================================================================================*/
#if (EMIOS_MCL_IP_CFG_DEFINES_VENDOR_ID != EMIOS_MCL_IP_CFG_DEVICEREGISTERS_VENDOR_ID)
    #error "Emios_Mcl_Ip_Cfg_Defines.h and Emios_Mcl_Ip_Cfg_DeviceRegisters.h have different vendor ids"
#endif

/* Check if  header file and Emios_Mcl_Ip_Cfg_DeviceRegisters.h file are of the same Autosar version */
#if ((EMIOS_MCL_IP_CFG_DEFINES_AR_RELEASE_MAJOR_VERSION != EMIOS_MCL_IP_CFG_DEVICEREGISTERS_AR_RELEASE_MAJOR_VERSION) || \
     (EMIOS_MCL_IP_CFG_DEFINES_AR_RELEASE_MINOR_VERSION != EMIOS_MCL_IP_CFG_DEVICEREGISTERS_AR_RELEASE_MINOR_VERSION) || \
     (EMIOS_MCL_IP_CFG_DEFINES_AR_RELEASE_REVISION_VERSION != EMIOS_MCL_IP_CFG_DEVICEREGISTERS_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Emios_Mcl_Ip_Cfg_Defines.h and Emios_Mcl_Ip_Cfg_DeviceRegisters.h are different"
#endif

/* Check if header file and Emios_Mcl_Ip_Cfg_DeviceRegisters.h file are of the same Software version */
#if ((EMIOS_MCL_IP_CFG_DEFINES_SW_MAJOR_VERSION != EMIOS_MCL_IP_CFG_DEVICEREGISTERS_SW_MAJOR_VERSION) || \
     (EMIOS_MCL_IP_CFG_DEFINES_SW_MINOR_VERSION != EMIOS_MCL_IP_CFG_DEVICEREGISTERS_SW_MINOR_VERSION) || \
     (EMIOS_MCL_IP_CFG_DEFINES_SW_PATCH_VERSION != EMIOS_MCL_IP_CFG_DEVICEREGISTERS_SW_PATCH_VERSION))
    #error "Software Version Numbers of Emios_Mcl_Ip_Cfg_Defines.h and Emios_Mcl_Ip_Cfg_DeviceRegisters.h are different"
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
[!IF "node:accessible(//Gpt)"!][!//
    /* Check if this header file and Emios_Gpt_Ip_Cfg_Defines.h file are of the same Autosar version */
    #if ((EMIOS_MCL_IP_CFG_DEFINES_AR_RELEASE_MAJOR_VERSION != EMIOS_GPT_IP_CFG_DEFINES_AR_RELEASE_MAJOR_VERSION) || \
        (EMIOS_MCL_IP_CFG_DEFINES_AR_RELEASE_MINOR_VERSION != EMIOS_GPT_IP_CFG_DEFINES_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of Emios_Mcl_Ip_Cfg_Defines.h and Emios_Gpt_Ip_Cfg_Defines.h are different"
    #endif
[!ENDIF!][!//
[!IF "node:accessible(//Ocu)"!][!//
    /* Check if this header file and Emios_Ocu_Ip_CfgDefines.h file are of the same Autosar version */
    #if ((EMIOS_MCL_IP_CFG_DEFINES_AR_RELEASE_MAJOR_VERSION != EMIOS_OCU_IP_CFGDEFINES_AR_RELEASE_MAJOR_VERSION) || \
        (EMIOS_MCL_IP_CFG_DEFINES_AR_RELEASE_MINOR_VERSION != EMIOS_OCU_IP_CFGDEFINES_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of Emios_Mcl_Ip_Cfg_Defines.h and Emios_Ocu_Ip_CfgDefines.h are different"
    #endif
[!ENDIF!][!//
[!IF "node:accessible(//Icu)"!][!//
    /* Check if this header file and Emios_Icu_Ip_Cfg.h file are of the same Autosar version */
    #if ((EMIOS_MCL_IP_CFG_DEFINES_AR_RELEASE_MAJOR_VERSION != EMIOS_ICU_IP_CFG_AR_RELEASE_MAJOR_VERSION) || \
        (EMIOS_MCL_IP_CFG_DEFINES_AR_RELEASE_MINOR_VERSION != EMIOS_ICU_IP_CFG_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of Emios_Mcl_Ip_Cfg_Defines.h and Emios_Icu_Ip_Cfg.h are different"
    #endif
[!ENDIF!][!//
[!IF "node:accessible(//Pwm)"!][!//
    /* Check if this header file and Emios_Pwm_Ip_CfgDefines.h file are of the same Autosar version */
    #if ((EMIOS_MCL_IP_CFG_DEFINES_AR_RELEASE_MAJOR_VERSION != EMIOS_PWM_IP_CFGDEFINES_AR_RELEASE_MAJOR_VERSION) || \
        (EMIOS_MCL_IP_CFG_DEFINES_AR_RELEASE_MINOR_VERSION != EMIOS_PWM_IP_CFGDEFINES_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of Emios_Mcl_Ip_Cfg_Defines.h and Emios_Pwm_Ip_CfgDefines.h are different"
    #endif
[!ENDIF!][!//
#endif

/*==================================================================================================
*                                            CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/
[!INDENT "0"!][!//
[!IF "node:exists(as:modconf("Resource")[1]/ResourceGeneral/ResourceSubderivative)"!][!//
    [!VAR "DerivativeName" = "text:toupper(substring-before(as:modconf("Resource")[1]/ResourceGeneral/ResourceSubderivative,'_'))"!]
    [!IF "contains($DerivativeName, 'S32K3')"!][!//
        [!CODE!][!WS "0"!]/* Timer width */[!CR!][!ENDCODE!][!//
        [!IF "contains($DerivativeName, 'S32K396') or contains($DerivativeName, 'S32K394') or contains($DerivativeName, 'S32K388')"!][!//
            [!CODE!][!WS "0"!]#define EMIOS_MCL_IP_24BITS_TIMER_WIDTH       STD_ON[!CR!][!ENDCODE!][!//
        [!ELSE!][!//
            [!CODE!][!WS "0"!]#define EMIOS_MCL_IP_24BITS_TIMER_WIDTH       STD_OFF[!CR!][!ENDCODE!][!//
        [!ENDIF!][!//
    [!ELSEIF "contains($DerivativeName, 'S32M276') or contains($DerivativeName, 'S32M274')"!][!//
        [!CODE!][!WS "0"!]/* Timer width */[!CR!][!ENDCODE!][!//
        [!CODE!][!WS "0"!]#define EMIOS_MCL_IP_24BITS_TIMER_WIDTH       STD_OFF[!CR!][!ENDCODE!][!//
    [!ELSE!][!//
        [!ERROR "The Resource plugin or ResourceSubderivative field is not available for header file inclusion."!][!//
    [!ENDIF!][!//
[!ENDIF!][!//
[!ENDINDENT!][!//


[!NOCODE!][!//

[!NOCODE!][!//
[!CODE!][!WS "0"!]/* eMIOS master buses. */[!CR!][!ENDCODE!][!//
[!FOR "Index" = "1" TO "num:i( count( ecu:list('Mcl.Emios_Hw_MasterBuses') ) )"!][!//
    [!CODE!][!WS "0"!]#define [!"ecu:list('Mcl.Emios_Hw_MasterBuses')[num:i($Index)]"!]         (uint16)([!"text:split(ecu:list('Mcl.Emios_Hw_MasterBuses')[num:i($Index)], '_CH_')[2]"!]U)[!CR!][!ENDCODE!][!//
[!ENDFOR!][!//
[!ENDNOCODE!][!//

[!CODE!][!WS "0"!]/* Macros that indicate EMIOS channels used by MCL. */[!CR!][!ENDCODE!][!//
[!SELECT "./MclConfig"!][!//
    [!LOOP "EmiosCommon/*"!][!//
        [!LOOP "./EmiosMclMasterBus/*"!][!//
                [!CODE!][!WS "0"!]#ifndef [!"node:value(./../../EmiosMclInstances)"!]_CH_[!"text:split(node:value(./EmiosMclMasterBusNumber), '_CH_')[2]"!]_USED[!CR!][!ENDCODE!][!//
                [!CODE!][!WS "4"!]#define [!"node:value(./../../EmiosMclInstances)"!]_CH_[!"text:split(node:value(./EmiosMclMasterBusNumber), '_CH_')[2]"!]_USED[!CR!][!ENDCODE!][!//
                [!CODE!][!WS "0"!]#else[!CR!][!ENDCODE!][!//
                [!CODE!][!WS "4"!]#error "[!"node:value(./../../EmiosMclInstances)"!]_CH_[!"text:split(node:value(./EmiosMclMasterBusNumber), '_CH_')[2]"!] channel cannot be used by MCL driver. Channel locked by other driver!"[!CR!][!ENDCODE!][!//
                [!CODE!][!WS "0"!]#endif[!CR!][!CR!][!ENDCODE!][!//
        [!ENDLOOP!][!//
    [!ENDLOOP!][!//
[!ENDSELECT!][!//

[!ENDNOCODE!][!//

[!NOCODE!][!//

[!CODE!][!WS "0"!]/* Macros used to save logic MCL EMIOS channel encoding. */[!CR!][!ENDCODE!][!//
[!SELECT "./MclConfig"!][!//
    [!VAR "currentLogicChannel" = "num:i(0)"!][!//
    [!LOOP "EmiosCommon/*"!][!//
        [!LOOP "./EmiosMclMasterBus/*"!][!//
            [!CODE!][!WS "0"!]#define MCL_EMIOS_LOGIC_CH[!"num:i($currentLogicChannel)"!] (uint16)(([!"text:split(node:value(./../../EmiosMclInstances), '_')[2]"!]U << 8U) + [!"node:value(./EmiosMclMasterBusNumber)"!])[!CR!][!ENDCODE!][!//
            [!VAR "currentLogicChannel"="$currentLogicChannel + 1"!][!//
        [!ENDLOOP!][!//
    [!ENDLOOP!][!//
[!ENDSELECT!][!//

[!ENDNOCODE!][!//

#define EMIOS_MCL_IP_DEV_ERROR_DETECT       (STD_OFF)

/** @brief Enable/disable EMIOS multicore support. */
#define EMIOS_IP_MULTICORE_IS_AVAILABLE [!IF "node:value(./MclGeneral/MclEnableMulticoreSupport)"!][!CODE!][!WS "4"!](STD_ON)[!CR!][!ENDCODE!][!ELSE!][!CODE!][!WS "4"!](STD_OFF)[!CR!][!ENDCODE!][!ENDIF!][!//

[!IF "node:value(./MclGeneral/MclEnableMulticoreSupport)"!]
    [!VAR "InitializationCoreRef" = "node:value(MclGeneral/MclEcucPartitionRef)"!][!//
    [!VAR "InitializationCoreId"  = "0"!][!//
    [!LOOP "as:modconf('Os')[1]/OsApplication/*"!][!//
        [!IF "$InitializationCoreRef = node:value(./OsAppEcucPartitionRef)"!][!//
            [!SELECT "node:ref(./OsApplicationCoreRef)"!][!//
                [!VAR "InitializationCoreId" = "node:value(./EcucCoreId)"!][!//
            [!ENDSELECT!][!//
        [!ENDIF!][!//
    [!ENDLOOP!][!//
[!CODE!][!WS "0"!]/** @brief Core used for initialization. */[!CR!][!ENDCODE!][!//
[!CODE!][!WS "0"!]#define MULTICORE_INIT_CORE                [!"num:i($InitializationCoreId)"!]U[!CR!][!ENDCODE!][!//
[!ENDIF!][!//




/*==================================================================================================
*                                              ENUMS
==================================================================================================*/

/*==================================================================================================
*                                  STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
*                                  GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                       FUNCTION PROTOTYPES
==================================================================================================*/

#ifdef __cplusplus
}
#endif

#endif /* EMIOS_MCL_IP_CFG_DEFINES_H */
[!ENDCODE!][!//
