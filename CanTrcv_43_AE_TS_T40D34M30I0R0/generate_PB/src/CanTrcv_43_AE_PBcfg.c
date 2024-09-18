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
/**
*   @file    CanTrcv_43_AE_PBcfg[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!].c
*   @version 3.0.0
*
*   @brief   AUTOSAR CanTrcv_43_AE - module interface
*   @details Configuration Structures for PostBuild
*
*   @addtogroup CANTRCV_DRIVER
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
#include "CanTrcv_43_AE_Types.h"
#include "CanTrcv_43_AE.h"
#include "CanTrcv_43_AE_Ipw_Cfg.h"

[!NOCODE!]
[!IF "var:defined('postBuildVariant')"!]
    [!VAR "postBuildVariantNameUnderscore" = "concat('_',$postBuildVariant)"!]
[!ELSE!]
    [!VAR "postBuildVariantNameUnderscore" = "string(null)"!]
[!ENDIF!]
[!ENDNOCODE!]
[!AUTOSPACING!]
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define CANTRCV_43_AE_VENDOR_ID_PBCFG[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_C                      43
#define CANTRCV_43_AE_AR_RELEASE_MAJOR_VERSION_PBCFG[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_C       4
#define CANTRCV_43_AE_AR_RELEASE_MINOR_VERSION_PBCFG[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_C       7
#define CANTRCV_43_AE_AR_RELEASE_REVISION_VERSION_PBCFG[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_C    0
#define CANTRCV_43_AE_SW_MAJOR_VERSION_PBCFG[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_C               3
#define CANTRCV_43_AE_SW_MINOR_VERSION_PBCFG[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_C               0
#define CANTRCV_43_AE_SW_PATCH_VERSION_PBCFG[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_C               0
/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/

/*==================================================================================================
*                                      GLOBAL VARIABLES
==================================================================================================*/
#define CANTRCV_43_AE_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanTrcv_43_AE_MemMap.h"

/* Inport external structure defined by IPW */
CANTRCV_43_AE_IPW_EXT

#define CANTRCV_43_AE_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanTrcv_43_AE_MemMap.h"
/*==================================================================================================
*                                   GLOBAL FUNCTION PROTOTYPES
==================================================================================================*/

/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
*                                      LOCAL CONSTANTS
==================================================================================================*/
[!INDENT "0"!]
#define CANTRCV_43_AE_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanTrcv_43_AE_MemMap.h"

[!SELECT "CanTrcvConfigSet"!]
    /**
    *   @brief  CanTrcv Transceiver Config
    */
    [!VAR "ChannelConfigCount" = "num:i(count(./CanTrcvChannel/*))"!]
    static const CanTrcv_43_AE_TransceiverConfigType CanTrcv_aTransceiverConfig[CANTRCV_43_AE_TRANSCEIVER_CONFIG_COUNT]=
    {
        [!INDENT "4"!]
        [!VAR "ChnIdx" = "num:i(0)"!]
        [!LOOP "node:order(./CanTrcvChannel/*, './CanTrcvChannelId')"!]
        {
            [!INDENT "8"!]
            /* .CanTrcv_u8SwTransceiverId */
            (uint8)[!"./CanTrcvChannelId"!]U,
            /* .CanTrcv_u8HwTransceiverId */
            (uint8)[!"./CanTrcvChannelId"!]U,
            /* .CanTrcv_u8CanIfTransceiverId */
            (uint8)[!"./CanTrcvAbstractCanIfId"!]U,
        #if (CANTRCV_43_AE_ICU_USED == STD_ON)
            [!IF "node:exists(./CanTrcvIcuChannelRef)"!]
                /* .CanTrcv_bIcuUsed */
                (boolean)TRUE,
                /* .CanTrcv_u16IcuChnId */
                (uint16)[!"num:i(node:ref(./CanTrcvIcuChannelRef)/IcuChannelId)"!],
            [!ELSE!]
                /* .CanTrcv_bIcuUsed */
                (boolean)FALSE,
                /* .CanTrcv_u16IcuChnId */
                (uint16)0U,
            [!ENDIF!]
        #endif
        #if (CANTRCV_43_AE_ECUM_USED == STD_ON)
            [!IF "node:exists(./CanTrcvWakeupSourceRef)"!]
                /* .CanTrcv_WakeupSourceMask */
                (uint32)(1U << [!"num:i(node:ref(./CanTrcvWakeupSourceRef)/EcuMWakeupSourceId)"!]),
            [!ELSE!]
                /* .CanTrcv_WakeupSourceMask */
                (uint32)0U,
            [!ENDIF!]
        #endif
        #if (CANTRCV_43_AE_DEM_USED == STD_ON)
            [!IF "node:exists(./CanTrcvDemEventParameterRefs/CANTRCV_E_BUS_ERROR)"!]
                /* .CanTrcv_DemEventId */
                (uint16)[!"node:ref(./CanTrcvDemEventParameterRefs/CANTRCV_E_BUS_ERROR)/DemEventId"!],
            [!ELSE!]
                /* .CanTrcv_DemEventId */
                (uint16)0U,
            [!ENDIF!]
        #endif
            /* .CanTrcv_bWakeupByBusUsed */
            (boolean)[!IF "node:exists(./CanTrcvWakeupByBusUsed) and ./CanTrcvWakeupByBusUsed = 'true'"!]TRUE[!ELSE!]FALSE[!ENDIF!],
            /* .DeviceModeAfterInit */
            [!IF "./CanTrcvInitState = 'CANTRCV_OP_MODE_SLEEP'"!]
                CANTRCV_TRCVMODE_SLEEP,
            [!ELSEIF "./CanTrcvInitState = 'CANTRCV_OP_MODE_STANDBY'"!]
                CANTRCV_TRCVMODE_STANDBY,
            [!ELSE!]
                CANTRCV_TRCVMODE_NORMAL,
            [!ENDIF!]
            /* .CanTrcv_IpwTransceiverConfig */
            &CanTrcv_43_AE_Ipw_TransceiverConfig[!"$postBuildVariantNameUnderscore"!]_Chn[!"$ChnIdx"!]
            [!ENDINDENT!]
            [!VAR "ChnIdx" = "num:i($ChnIdx + 1)"!]
        }[!IF "$ChnIdx < $ChannelConfigCount"!],[!ENDIF!][!CR!]
        [!ENDLOOP!]
        [!ENDINDENT!]
    };
[!ENDSELECT!]

[!VAR "ChannelConfigCount" = "num:i(count(./CanTrcvConfigSet/CanTrcvChannel/*))"!]
[!VAR "CanTrcvEcucPartitionRefCount" = "num:i(count(./CanTrcvGeneral/CanTrcvEcucPartitionRef/*))"!]
[!IF "$CanTrcvEcucPartitionRefCount != 0"!]
    [!LOOP "./CanTrcvGeneral/CanTrcvEcucPartitionRef/*"!]
        [!VAR "CanTrcvEcuCPartitionPath" = "node:value(.)"!]
        [!VAR "CanTrcvPartitionMatchCounter" = "0"!]
        [!LOOP "../../../CanTrcvConfigSet/CanTrcvChannel/*"!]
            [!IF "node:exists(./CanTrcvChannelEcucPartitionRef) and (node:value(CanTrcvChannelEcucPartitionRef) = $CanTrcvEcuCPartitionPath)"!]
                [!VAR "CanTrcvPartitionMatchCounter" = "1"!]
            [!ENDIF!]
        [!ENDLOOP!]
        [!IF "$CanTrcvPartitionMatchCounter = 1"!]
            /**
            *   @brief  CanTrcv Transceiver Object's pointer structure of [!"node:name(node:ref(.))"!]
            */
            static const CanTrcv_43_AE_TransceiverConfigType * const CanTrcv_apTransceiver_[!"node:name(node:ref(.))"!][CANTRCV_43_AE_TRANSCEIVER_CONFIG_COUNT]=
            {
                [!INDENT "4"!]
                [!VAR "ChnIdx" = "0"!]
                [!LOOP "node:order(../../../CanTrcvConfigSet/CanTrcvChannel/*, './CanTrcvChannelId')"!]
                    [!VAR "ChnIdx" = "num:i($ChnIdx + 1)"!]
                    [!IF "node:exists(./CanTrcvChannelEcucPartitionRef)"!]
                        [!IF "(node:value(./CanTrcvChannelEcucPartitionRef) = $CanTrcvEcuCPartitionPath)"!]
                            &CanTrcv_aTransceiverConfig[[!"num:i(./CanTrcvChannelId)"!]U][!IF "$ChnIdx < $ChannelConfigCount"!],[!ENDIF!][!CR!]
                        [!ELSE!]
                            NULL_PTR[!IF "$ChnIdx < $ChannelConfigCount"!],[!ENDIF!][!CR!]
                        [!ENDIF!]
                    [!ELSE!]
                        NULL_PTR[!IF "$ChnIdx < $ChannelConfigCount"!],[!ENDIF!][!CR!]
                    [!ENDIF!]
                [!ENDLOOP!]
                [!ENDINDENT!]
            };
        [!ENDIF!]
    [!ENDLOOP!]
[!ELSE!]
    static const CanTrcv_43_AE_TransceiverConfigType * const CanTrcv_apTransceiver[CANTRCV_43_AE_TRANSCEIVER_CONFIG_COUNT]=
    {
        [!INDENT "4"!]
            [!VAR "ChnIdx" = "0"!]
            [!LOOP "node:order(./CanTrcvConfigSet/CanTrcvChannel/*, './CanTrcvChannelId')"!]
                [!VAR "ChnIdx" = "num:i($ChnIdx + 1)"!]
                &CanTrcv_aTransceiverConfig[[!"num:i(./CanTrcvChannelId)"!]U][!IF "$ChnIdx < $ChannelConfigCount"!],[!ENDIF!][!CR!]
            [!ENDLOOP!]
        [!ENDINDENT!]
    };
[!ENDIF!]
/*==================================================================================================
*                                      GLOBAL CONSTANTS
==================================================================================================*/
/**
*   @brief  Top level structure contain all CanTrcv driver Config
*/
[!IF "(./IMPLEMENTATION_CONFIG_VARIANT != 'VariantPostBuild') and (variant:size() <= 1)"!][!// VariantPreCompile/LinkTime and at most 1 configured variant
    [!IF "$CanTrcvEcucPartitionRefCount != 0"!][!// Existing CAN EcucPartition References
        [!LOOP "./CanTrcvGeneral/CanTrcvEcucPartitionRef/*"!]
            [!VAR "CanTrcvEcuCPartitionPath" = "node:value(.)"!]
            [!VAR "CanTrcvEcucPartitionName" = "substring-after(substring-after($CanTrcvEcuCPartitionPath, 'EcuC/EcuC/'), '/')"!]
            [!VAR "CanTrcvPartitionMatchCounter" = "0"!]
            [!LOOP "../../../CanTrcvConfigSet/CanTrcvChannel/*"!]
                [!IF "node:exists(./CanTrcvChannelEcucPartitionRef) and (node:value(CanTrcvChannelEcucPartitionRef) = $CanTrcvEcuCPartitionPath)"!]
                    [!VAR "CanTrcvPartitionMatchCounter" = "1"!]
                [!ENDIF!]
            [!ENDLOOP!]
            [!IF "$CanTrcvPartitionMatchCounter = 1"!]
                static const CanTrcv_43_AE_ConfigType[!WS!]CanTrcv_Config_[!"$CanTrcvEcucPartitionName"!] =
                {
                    [!INDENT "4"!]
                        /* Configuration Core ID */
                        [!VAR "OsAppMatchCounter" = "0"!]
                        [!LOOP "as:modconf('Os')[1]/OsApplication/*"!]
                            [!IF "contains(node:value(./OsAppEcucPartitionRef), $CanTrcvEcucPartitionName)"!]
                                [!VAR "OsAppMatchCounter" = "1"!]
                                [!VAR "CoreID" = "node:value(node:ref(./OsApplicationCoreRef)/EcucCoreId)"!]
                            [!ENDIF!]
                        [!ENDLOOP!]
                        [!IF "$OsAppMatchCounter = 1"!](uint32)[!"$CoreID"!]U[!ELSE!]0U[!ENDIF!],[!CR!]
                        /* Array of Pointer to Controller Type which are assigned to partition */
                        CanTrcv_apTransceiver_[!"$CanTrcvEcucPartitionName"!]
                    [!ENDINDENT!]
                };[!CR!]
            [!ENDIF!]
        [!ENDLOOP!]
    [!ELSE!][!// No ECUC partition referenced in CAN
        const CanTrcv_43_AE_ConfigType[!WS!]CanTrcv_43_AE_Config =
        {
            [!INDENT "4"!]
                /* Configuration Core ID */
                (uint32)0U,
                /* Array of Pointer to Controller infomation have aligned by Controller ID */
                CanTrcv_apTransceiver
            [!ENDINDENT!]
        };[!CR!]

    [!ENDIF!]
[!ELSE!][!// VariantPostBuild or more than 1 configured variant
    [!IF "variant:size() > 0"!][!// If ECUC exists or there is at least one variant
        [!IF "$CanTrcvEcucPartitionRefCount != 0"!][!// Existing CAN EcucPartition References
            [!LOOP "./CanTrcvGeneral/CanTrcvEcucPartitionRef/*"!]
                [!VAR "CanTrcvEcuCPartitionPath" = "node:value(.)"!]
                [!VAR "CanTrcvEcucPartitionName" = "substring-after(substring-after($CanTrcvEcuCPartitionPath, 'EcuC/EcuC/'), '/')"!]
                [!VAR "CanTrcvPartitionMatchCounter" = "0"!]
                [!LOOP "../../../CanTrcvConfigSet/CanTrcvChannel/*"!]
                    [!IF "node:exists(./CanTrcvChannelEcucPartitionRef) and (node:value(CanTrcvChannelEcucPartitionRef) = $CanTrcvEcuCPartitionPath)"!]
                        [!VAR "CanTrcvPartitionMatchCounter" = "1"!]
                    [!ENDIF!]
                [!ENDLOOP!]
                [!IF "$CanTrcvPartitionMatchCounter = 1"!]
                    const CanTrcv_43_AE_ConfigType[!WS!]CanTrcv_43_AE_Config_[!"variant:name()"!]_[!"$CanTrcvEcucPartitionName"!] =
                    {
                        [!INDENT "4"!]
                            /* Configuration Core ID */
                            [!VAR "OsAppMatchCounter" = "0"!]
                            [!LOOP "as:modconf('Os')[1]/OsApplication/*"!]
                                [!IF "contains(node:value(./OsAppEcucPartitionRef), $CanTrcvEcucPartitionName)"!]
                                    [!VAR "OsAppMatchCounter" = "1"!]
                                    [!VAR "CoreID" = "node:value(node:ref(./OsApplicationCoreRef)/EcucCoreId)"!]
                                [!ENDIF!]
                            [!ENDLOOP!]
                            [!IF "$OsAppMatchCounter = 1"!](uint32)[!"$CoreID"!]U[!ELSE!](uint32)0U[!ENDIF!],[!CR!]
                            /* Array of Pointer to Controller Type which are assigned to partition */
                            CanTrcv_apTransceiver_[!"$CanTrcvEcucPartitionName"!]
                        [!ENDINDENT!]
                    };[!CR!]
                [!ENDIF!]
            [!ENDLOOP!]
        [!ELSE!][!// No ECUC partition referenced in CAN
            const CanTrcv_43_AE_ConfigType[!WS!]CanTrcv_43_AE_Config_[!"variant:name()"!] =
            {
                [!INDENT "4"!]
                    /* Configuration Core ID */
                    (uint32)0U,
                    /* Array of Pointer to Controller infomation have aligned by Controller ID */
                    CanTrcv_apTransceiver
                [!ENDINDENT!]
            };[!CR!]

        [!ENDIF!]
    [!ELSE!][!// PB with no variant or no ECUC
        [!IF "$CanTrcvEcucPartitionRefCount != 0"!][!// Existing CAN EcucPartition References
            [!LOOP "./CanTrcvGeneral/CanTrcvEcucPartitionRef/*"!]
                [!VAR "CanTrcvEcuCPartitionPath" = "node:value(.)"!]
                [!VAR "CanTrcvEcucPartitionName" = "substring-after(substring-after($CanTrcvEcuCPartitionPath, 'EcuC/EcuC/'), '/')"!]
                [!VAR "CanTrcvPartitionMatchCounter" = "0"!]
                [!LOOP "../../../CanTrcvConfigSet/CanTrcvChannel/*"!]
                    [!IF "node:exists(./CanTrcvChannelEcucPartitionRef) and (node:value(CanTrcvChannelEcucPartitionRef) = $CanTrcvEcuCPartitionPath)"!]
                        [!VAR "CanTrcvPartitionMatchCounter" = "1"!]
                    [!ENDIF!]
                [!ENDLOOP!]
                [!IF "$CanTrcvPartitionMatchCounter = 1"!]
                    const CanTrcv_43_AE_ConfigType[!WS!]CanTrcv_43_AE_Config_[!"$CanTrcvEcucPartitionName"!] =
                    {
                        [!INDENT "4"!]
                            /* Configuration Core ID */
                            [!VAR "OsAppMatchCounter" = "0"!]
                            [!LOOP "as:modconf('Os')[1]/OsApplication/*"!]
                                [!IF "contains(node:value(./OsAppEcucPartitionRef), $CanTrcvEcucPartitionName)"!]
                                    [!VAR "OsAppMatchCounter" = "1"!]
                                    [!VAR "CoreID" = "node:value(node:ref(./OsApplicationCoreRef)/EcucCoreId)"!]
                                [!ENDIF!]
                            [!ENDLOOP!]
                            [!IF "$OsAppMatchCounter = 1"!](uint32)[!"$CoreID"!]U[!ELSE!](uint32)0U[!ENDIF!],[!CR!]
                            /* Array of Pointer to Controller Type which are assigned to partition */
                            CanTrcv_apTransceiver_[!"$CanTrcvEcucPartitionName"!]
                        [!ENDINDENT!]
                    };[!CR!]
                [!ENDIF!]
            [!ENDLOOP!]
        [!ELSE!][!// No ECUC partition referenced in CAN
            const CanTrcv_43_AE_ConfigType[!WS!]CanTrcv_43_AE_Config =
            {
                [!INDENT "4"!]
                    /* Configuration Core ID */
                    (uint32)0U,
                    /* Array of Pointer to Controller infomation have aligned by Controller ID */
                    CanTrcv_apTransceiver
                [!ENDINDENT!]
            };[!CR!]

        [!ENDIF!]
    [!ENDIF!]
[!ENDIF!]

[!IF "(./IMPLEMENTATION_CONFIG_VARIANT != 'VariantPostBuild') and (variant:size() <= 1)"!]
    [!IF "$CanTrcvEcucPartitionRefCount != 0"!][!// Existing CAN EcucPartition References
        [!SELECT "as:modconf('EcuC')[1]"!]
            [!VAR "MaxCoreIdConfig" = "num:i(count(./EcucHardware/*[1]/EcucCoreDefinition/*))"!]
        [!ENDSELECT!]
        const CanTrcv_43_AE_ConfigType * const [!WS!]CanTrcv_43_AE_Config[[!"$MaxCoreIdConfig"!]U] =
        {
            [!INDENT "4"!]
            [!VAR "coreIdx" = "0"!]
            [!LOOP "node:order(as:modconf('EcuC')[1]/EcucHardware/*[1]/EcucCoreDefinition/*, './EcucCoreId')"!]
                [!VAR "OsAppPart" = "''"!]
                [!VAR "coreIdx" = "$coreIdx + 1"!]
                [!VAR "CoreId" = "node:value(./EcucCoreId)"!]
                [!VAR "CanTrcvPartShortName" = "''"!]
                [!VAR "CanTrcvPartMatchCounter" = "0"!]
                [!LOOP "as:modconf('Os')[1]/OsApplication/*"!]
                    [!IF "$CoreId = node:value(node:ref(./OsApplicationCoreRef)/EcucCoreId)"!]
                        [!VAR "OsAppPart" = "node:value(./OsAppEcucPartitionRef)"!]
                    [!ENDIF!]
                [!ENDLOOP!]
                [!LOOP "as:modconf('Can')[1]/CanTrcvGeneral/CanTrcvEcucPartitionRef/*"!]
                    [!IF "$OsAppPart = node:value(.)"!]
                        [!VAR "CanTrcvPartMatchCounter" = "$CanTrcvPartMatchCounter + 1"!]
                        [!VAR "CanTrcvPartShortName" = "substring-after(substring-after(., 'EcuC/EcuC/'), '/')"!]
                    [!ENDIF!]
                [!ENDLOOP!]
                [!IF "$CanTrcvPartMatchCounter = 1"!]&CanTrcv_Config_[!"$CanTrcvPartShortName"!][!ELSE!]NULL_PTR[!ENDIF!][!IF "$coreIdx < $MaxCoreIdConfig"!],[!ENDIF!][!CR!]
            [!ENDLOOP!]
            [!ENDINDENT!]
        };
    [!ENDIF!]
[!ENDIF!]

#define CANTRCV_43_AE_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanTrcv_43_AE_MemMap.h"

[!ENDINDENT!]

#ifdef __cplusplus
}
#endif

/** @} */
