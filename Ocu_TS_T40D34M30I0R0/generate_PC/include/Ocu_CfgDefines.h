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

#ifndef OCU_CFGDEFINES_H
#define OCU_CFGDEFINES_H
/**
*   @file           Ocu_CfgDefines.h
*
*   @addtogroup     ocu_driver Ocu Driver
*   @brief          Ocu HLD Precompile defines header file.
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

/*==================================================================================================
*                               HEADER FILE VERSION INFORMATION
==================================================================================================*/
#define OCU_CFGDEFINES_VENDOR_ID                       43
#define OCU_CFGDEFINES_AR_RELEASE_MAJOR_VERSION        4
#define OCU_CFGDEFINES_AR_RELEASE_MINOR_VERSION        7
#define OCU_CFGDEFINES_AR_RELEASE_REVISION_VERSION     0
#define OCU_CFGDEFINES_SW_MAJOR_VERSION                3
#define OCU_CFGDEFINES_SW_MINOR_VERSION                0
#define OCU_CFGDEFINES_SW_PATCH_VERSION                0
/*==================================================================================================
*                                      FILE VERSION CHECKS
==================================================================================================*/

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if this header file and Std_Types.h file are of the same Autosar version */
    #if ((OCU_CFGDEFINES_AR_RELEASE_MAJOR_VERSION != STD_AR_RELEASE_MAJOR_VERSION) || \
        (OCU_CFGDEFINES_AR_RELEASE_MINOR_VERSION != STD_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of Ocu_CfgDefines.h and Std_Types.h are different"
    #endif
#endif

/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/
[!NOCODE!]
[!VAR "numFtmHwModules" = "ecu:get('Ocu.Num_Ftm_Hw_Modules')"!]
[!VAR "numEmiosHwModules" = "ecu:get('Ocu.Num_Emios_Hw_Modules')"!]
[!VAR "numEtimerHwModules" = "ecu:get('Ocu.Num_Etimer_Hw_Modules')"!]
[!VAR "numFtmChannelsPerInstance" = "ecu:get('Ocu.Num_Ftm_Hw_Channels')"!]
[!VAR "numEmiosChannelsPerInstance" = "ecu:get('Ocu.Num_Emios_Hw_Channels')"!]
[!VAR "numEtimerChannelsPerInstance" = "ecu:get('Ocu.Num_Etimer_Hw_Channels')"!]
[!ENDNOCODE!]
/** @brief define Precompile */
[!NOCODE!]
[!IF "(IMPLEMENTATION_CONFIG_VARIANT = 'VariantPreCompile') and (variant:size() <= 1)"!]
[!CODE!]#define OCU_PRECOMPILE_SUPPORT      (STD_ON)[!ENDCODE!]
[!ELSE!]
[!CODE!]#define OCU_PRECOMPILE_SUPPORT      (STD_OFF)[!ENDCODE!]
[!ENDIF!]
[!ENDNOCODE!]

/** @brief   Switch to indicate if Ocu_GetVersionInfo API is supported */
#define OCU_VERSION_INFO_API    ([!IF "OcuConfigurationOfOptionalApis/OcuVersionInfoApi"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

#ifndef OCU_CONF_CHANNELS_PB
/** @brief  Number of configured Ocu channels */
#define OCU_CONF_CHANNELS_PB    ([!"num:i(count(OcuConfigSet/OcuChannel/*))"!]U)
#endif

#ifndef OCU_DOWNCOUNTING_SUPPORED
/**
* @brief        Switch to indicate that the down counting is supported
*               For current implementation, this feature does not support
*/
#define OCU_DOWNCOUNTING_SUPPORED   (STD_OFF)
#endif

#ifndef OCU_FTM_INSTANCE_COUNT
/** @brief  The number of Ftm instances available on platform */
#define OCU_FTM_INSTANCE_COUNT       (uint8)[!"$numFtmHwModules"!]U
#endif

#ifndef OCU_EMIOS_INSTANCE_COUNT
/** @brief  The number of eMios instances available on platform */
#define OCU_EMIOS_INSTANCE_COUNT     (uint8)[!"$numEmiosHwModules"!]U
#endif

#ifndef OCU_ETIMER_INSTANCE_COUNT
/** @brief  The number of eTimer instances available on platform */
#define OCU_ETIMER_INSTANCE_COUNT    (uint8)[!"$numEtimerHwModules"!]U
#endif

#ifndef OCU_FTM_CHANNEL_COUNT
/** @brief  The number of channels available on each Ftm instance */
#define OCU_FTM_CHANNEL_COUNT        (uint8)[!"$numFtmChannelsPerInstance"!]U
#endif

#ifndef OCU_EMIOS_CHANNEL_COUNT
/** @brief  The number of channels available on each eMios instance */
#define OCU_EMIOS_CHANNEL_COUNT      (uint8)[!"$numEmiosChannelsPerInstance"!]U
#endif

#ifndef OCU_ETIMER_CHANNEL_COUNT
/** @brief  The number of channels available on each eTimer instance */
#define OCU_ETIMER_CHANNEL_COUNT     (uint8)[!"$numEtimerChannelsPerInstance"!]U
#endif

#ifndef OCU_FTM_NUM_HW_CHANNELS
/** @brief maximum number of Ftm channels on this platform */
#define OCU_FTM_NUM_HW_CHANNELS      ((OCU_FTM_CHANNEL_COUNT) * (OCU_FTM_INSTANCE_COUNT))
#endif

#ifndef OCU_EMIOS_NUM_HW_CHANNELS
/** @brief maximum number of eMios channels available on this platform */
#define OCU_EMIOS_NUM_HW_CHANNELS    ((OCU_EMIOS_CHANNEL_COUNT) * (OCU_EMIOS_INSTANCE_COUNT))
#endif

#ifndef OCU_ETIMER_NUM_HW_CHANNELS
/** @brief maximum number of eTimer channels available on this platform */
#define OCU_ETIMER_NUM_HW_CHANNELS   ((OCU_ETIMER_CHANNEL_COUNT) * (OCU_ETIMER_INSTANCE_COUNT))
#endif

/** @brief Defines the maximum number of hw channels in the current configuration */
#define  OCU_NUM_HW_CHANNELS         (uint8)(OCU_FTM_NUM_HW_CHANNELS + OCU_EMIOS_NUM_HW_CHANNELS + OCU_ETIMER_NUM_HW_CHANNELS)

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
#endif  /* OCU_CFGDEFINES_H */
