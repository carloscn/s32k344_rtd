/*==================================================================================================
* Project : RTD AUTOSAR 4.7
* Platform : CORTEXM
* Peripheral : eMios
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

#ifndef OCU_IPW_CFGDEFINES_H
#define OCU_IPW_CFGDEFINES_H
/**
*   @file           Ocu_Ipw_CfgDefines.h
*
*   @internal
*   @addtogroup     ocu_ipw Ocu IPW
*   @brief          Ocu IPW Precompile defines header file.
*   @details        Precompile defines.
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
#include "OsIf.h"

/*==================================================================================================
*                               HEADER FILE VERSION INFORMATION
==================================================================================================*/
#define OCU_IPW_CFGDEFINES_VENDOR_ID                       43
#define OCU_IPW_CFGDEFINES_AR_RELEASE_MAJOR_VERSION        4
#define OCU_IPW_CFGDEFINES_AR_RELEASE_MINOR_VERSION        7
#define OCU_IPW_CFGDEFINES_AR_RELEASE_REVISION_VERSION     0
#define OCU_IPW_CFGDEFINES_SW_MAJOR_VERSION                3
#define OCU_IPW_CFGDEFINES_SW_MINOR_VERSION                0
#define OCU_IPW_CFGDEFINES_SW_PATCH_VERSION                0
/*==================================================================================================
*                                      FILE VERSION CHECKS
==================================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if this header file and Std_Types.h file are of the same Autosar version */
    #if ((OCU_IPW_CFGDEFINES_AR_RELEASE_MAJOR_VERSION != STD_AR_RELEASE_MAJOR_VERSION) || \
        (OCU_IPW_CFGDEFINES_AR_RELEASE_MINOR_VERSION != STD_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of Ocu_Ipw_CfgDefines.h and Std_Types.h are different"
    #endif

    /* Check if this header file and OsIf.h file are of the same Autosar version */
    #if ((OCU_IPW_CFGDEFINES_AR_RELEASE_MAJOR_VERSION != OSIF_AR_RELEASE_MAJOR_VERSION) || \
        (OCU_IPW_CFGDEFINES_AR_RELEASE_MINOR_VERSION != OSIF_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of Ocu_Ipw_CfgDefines.h and OsIf.h are different"
    #endif
#endif

/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/
[!NOCODE!]
[!VAR "maxPartition" = "num:i(0)"!]
[!IF "node:exists(as:modconf("EcuC")[1]/EcucPartitionCollection/*[1]/EcucPartition)"!]
    [!VAR "maxPartition" = "num:i(count(as:modconf("EcuC")[1]/EcucPartitionCollection/*[1]/EcucPartition/*))"!]
[!ENDIF!]
[!IF "$maxPartition = 0"!][!VAR "maxPartition" = "num:i(1)"!][!ENDIF!]

/* Variable indicate multicore feature enabled */
[!VAR "MulticoreEnabled" = "0"!]

[!IF "./OcuGeneral/OcuMulticoreEnabled"!]
[!VAR "MulticoreEnabled" = "1"!]
[!ENDIF!]

[!CODE!]
#ifndef OCU_MULTICORE_ENABLED
/** @brief define multicore support */
#define OCU_MULTICORE_ENABLED   ([!IF "$MulticoreEnabled = 1"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])
#endif

#if (STD_ON == OCU_MULTICORE_ENABLED)
    #define Ocu_GetCoreId()    ((uint8)OsIf_GetCoreID())
#else
    #define Ocu_GetCoreId()    ((uint8)0)
#endif
[!ENDCODE!]

[!IF "$MulticoreEnabled = 1"!]
    [!VAR "MaximumCoreId" = "0"!]
    [!VAR "CurrentCoreId" = "0"!]
    [!LOOP "OcuGeneral/OcuEcucPartitionRef/*"!]
        [!VAR "OcuEcucPartitionRefName" = "node:value(.)"!]

        [!LOOP "as:modconf('Os')[1]/OsApplication/*"!]
            [!IF "$OcuEcucPartitionRefName = node:value(./OsAppEcucPartitionRef)"!]
                [!SELECT "node:ref(./OsApplicationCoreRef)"!]
                    [!VAR "CurrentCoreId" = "node:value(./EcucCoreId)"!]

                    [!IF "num:i($MaximumCoreId) < num:i($CurrentCoreId)"!]
                        [!VAR "MaximumCoreId" = "$CurrentCoreId"!]
                    [!ENDIF!]
            [!ENDSELECT!]
            [!ENDIF!]
        [!ENDLOOP!]
    [!ENDLOOP!]

    [!VAR "MaximumCoreId" = "$MaximumCoreId + 1"!]
[!ENDIF!]
[!ENDNOCODE!]

/** @brief    Maximum number of configured partitions. */
#define OCU_MAX_PARTITIONS  ([!"num:i($maxPartition)"!]U)

[!NOCODE!][!//
/* Currently, OCU_FTM_USED is set by default to OFF, because there is no FTM IP on S32K3XX. */
[!VAR "MacFtmUsed"="0"!][!//
[!ENDNOCODE!][!//
#ifndef OCU_FTM_USED
/** @brief This define indicates that at least one channel from each module is used in all configurations. */
#define OCU_FTM_USED    ([!IF "$MacFtmUsed=1"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])
#endif

[!NOCODE!][!//
    [!VAR "MacEmiosUsed"="0"!][!//

    /* Loop on all channels inside the same configuration Set */
    [!LOOP "OcuGeneral/OcuHwResourceConfig/*"!][!//
        [!IF "node:value(OcuChannelIsUsed) = 'true' and contains(OcuHwResourceId, 'EMIOS')"!][!//
            [!VAR "MacEmiosUsed"="1"!][!//
        [!ENDIF!][!//
    [!ENDLOOP!][!//
[!ENDNOCODE!][!//
#ifndef OCU_EMIOS_USED
/** @brief This define indicates that at least one channel from each module is used in all configurations. */
#define OCU_EMIOS_USED    ([!IF "$MacEmiosUsed=1"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])
#endif

[!NOCODE!][!//
/* Currently, OCU_ETIMER_USED is set by default to OFF, because there is no EMIOS IP on S32K3XX. */
[!VAR "MacEtimerUsed"="0"!][!//
[!ENDNOCODE!][!//
#ifndef OCU_ETIMER_USED
/** @brief This define indicates that at least one channel from each module is used in all configurations. */
#define OCU_ETIMER_USED    ([!IF "$MacEtimerUsed=1"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])
#endif

[!NOCODE!][!//
[!VAR "MacNumEmiosChannels"="0"!]
/* Loop on all channels inside the same configuration Set */
[!LOOP "OcuConfigSet/OcuChannel/*"!][!//
    [!IF "contains(node:value(node:ref(./OcuHWSpecificSettingsRef)/OcuHardwareElements), 'EMIOS')"!][!//
        [!VAR "MacNumEmiosChannels"="$MacNumEmiosChannels + 1"!]
    [!ENDIF!][!//
[!ENDLOOP!][!//
[!IF "num:i($MacNumEmiosChannels) != 0"!]
[!CODE!]
#ifndef OCU_CONF_EMIOS_CHANNELS_PB
/** @brief Number of configured eMios channels */
#define OCU_CONF_EMIOS_CHANNELS_PB  ([!"num:i($MacNumEmiosChannels)"!]U)
#endif
[!ENDCODE!]
[!ENDIF!]

[!ENDNOCODE!][!//

#ifndef OCU_CONF_CHANNELS_PB
/** @brief  Number of configured Ocu channels */
#define OCU_CONF_CHANNELS_PB    ([!"num:i(count(OcuConfigSet/OcuChannel/*))"!]U)
#endif

#ifndef OCU_DEINIT_API
/** @brief      Switch to indicate that Ocu_DeInit() API is supported */
#define OCU_DEINIT_API      ([!IF "OcuConfigurationOfOptionalApis/OcuDeInitApi"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])
#endif

#ifndef OCU_SET_PIN_STATE_API
/** @brief  Switch to indicate if Ocu_SetPinState() API is supported */
#define OCU_SET_PIN_STATE_API   ([!IF "OcuConfigurationOfOptionalApis/OcuSetPinStateApi"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])
#endif

#ifndef OCU_SET_PIN_ACTION_API
/** @brief  Switch to indicate if Ocu_SetPinAction() API is supported */
#define OCU_SET_PIN_ACTION_API  ([!IF "OcuConfigurationOfOptionalApis/OcuSetPinActionApi"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])
#endif

#ifndef OCU_GET_COUNTER_API
/** @brief   Switch to indicate if Ocu_GetCounter() API is supported */
#define OCU_GET_COUNTER_API     ([!IF "OcuConfigurationOfOptionalApis/OcuGetCounterApi"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])
#endif

#ifndef OCU_SET_ABSOLUTE_THRESHOLD_API
/** @brief  Switch to indicate if Ocu_SetAbsoluteThreshold() API is supported */
#define OCU_SET_ABSOLUTE_THRESHOLD_API  ([!IF "OcuConfigurationOfOptionalApis/OcuSetAbsoluteThresholdApi"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])
#endif

#ifndef OCU_SET_RELATIVE_THRESHOLD_API
/** @brief      Switch to indicate if Ocu_SetRelativeThreshold() API is supported */
#define OCU_SET_RELATIVE_THRESHOLD_API  ([!IF "OcuConfigurationOfOptionalApis/OcuSetRelativeThresholdApi"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])
#endif

/*==================================================================================================
*                                             ENUMS
==================================================================================================*/

/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/**
* @brief        Hardware specific internal counter type definition
* @details      The value of the period is platform dependent and thus configurable.
*               Type for reading the counter and writing the threshold values (in number of ticks).
*
*/
typedef [!"ecu:get('Ocu.Emios_TimersType')"!] Ocu_Ipw_ValueType;

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
#endif  /* OCU_IPW_CFGDEFINES_H */
