[!AUTOSPACING!]
[!NOCODE!]
    [!IF "var:defined('postBuildVariant')"!]
        [!VAR "VS_number" = "concat('_',$postBuildVariant)"!]
    [!ELSE!]
        [!VAR "VS_number" = "''"!]
    [!ENDIF!]
[!ENDNOCODE!]
[!CODE!]
/*==================================================================================================
*   Project              : RTD AUTOSAR 4.7
*   Platform             : CORTEXM
*   Peripheral           : eMios
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

/**
*   @file         Ocu_Ipw[!"$VS_number"!]_PBcfg.c
*
*   @internal     
*   @addtogroup   ocu_ipw Ocu IPW
*   @brief        Ocu IPW Postbuild configuration source file.
*   @details
*
*   @{
*/

#ifdef __cplusplus
extern "C" {
#endif

/*==================================================================================================
*                                         INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/

#include "Ocu_Ipw[!"$VS_number"!]_PBcfg.h"

/*==================================================================================================
*                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define OCU_IPW[!"$VS_number"!]_PBCFG_VENDOR_ID_C                       43
#define OCU_IPW[!"$VS_number"!]_PBCFG_AR_RELEASE_MAJOR_VERSION_C        4
#define OCU_IPW[!"$VS_number"!]_PBCFG_AR_RELEASE_MINOR_VERSION_C        7
#define OCU_IPW[!"$VS_number"!]_PBCFG_AR_RELEASE_REVISION_VERSION_C     0
#define OCU_IPW[!"$VS_number"!]_PBCFG_SW_MAJOR_VERSION_C                3
#define OCU_IPW[!"$VS_number"!]_PBCFG_SW_MINOR_VERSION_C                0
#define OCU_IPW[!"$VS_number"!]_PBCFG_SW_PATCH_VERSION_C                0
/*==================================================================================================
*                                      FILE VERSION CHECKS
==================================================================================================*/
#if (OCU_IPW[!"$VS_number"!]_PBCFG_VENDOR_ID_C != OCU_IPW[!"$VS_number"!]_PBCFG_VENDOR_ID)
    #error "Ocu_Ipw[!"$VS_number"!]_PBcfg.c and Ocu_Ipw[!"$VS_number"!]_PBcfg.h have different vendor ids"
#endif

/* Check if  source file and Ocu_Ipw[!"$VS_number"!]_PBcfg.h file are of the same Autosar version */
#if ((OCU_IPW[!"$VS_number"!]_PBCFG_AR_RELEASE_MAJOR_VERSION_C != OCU_IPW[!"$VS_number"!]_PBCFG_AR_RELEASE_MAJOR_VERSION) || \
     (OCU_IPW[!"$VS_number"!]_PBCFG_AR_RELEASE_MINOR_VERSION_C != OCU_IPW[!"$VS_number"!]_PBCFG_AR_RELEASE_MINOR_VERSION) || \
     (OCU_IPW[!"$VS_number"!]_PBCFG_AR_RELEASE_REVISION_VERSION_C != OCU_IPW[!"$VS_number"!]_PBCFG_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Ocu_Ipw[!"$VS_number"!]_PBcfg.c and Ocu_Ipw[!"$VS_number"!]_PBcfg.h are different"
#endif

/* Check if source file and Ocu_Ipw[!"$VS_number"!]_PBcfg.h file are of the same Software version */
#if ((OCU_IPW[!"$VS_number"!]_PBCFG_SW_MAJOR_VERSION_C != OCU_IPW[!"$VS_number"!]_PBCFG_SW_MAJOR_VERSION) || \
     (OCU_IPW[!"$VS_number"!]_PBCFG_SW_MINOR_VERSION_C != OCU_IPW[!"$VS_number"!]_PBCFG_SW_MINOR_VERSION) || \
     (OCU_IPW[!"$VS_number"!]_PBCFG_SW_PATCH_VERSION_C != OCU_IPW[!"$VS_number"!]_PBCFG_SW_PATCH_VERSION))
    #error "Software Version Numbers of Ocu_Ipw[!"$VS_number"!]_PBcfg.c and Ocu_Ipw[!"$VS_number"!]_PBcfg.h are different"
#endif

/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                       GLOBAL CONSTANTS
==================================================================================================*/

#define OCU_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Ocu_MemMap.h"
[!NOCODE!]

[!VAR "max_number_ocu_cfg" = "num:i(count(./OcuGeneral/OcuEcucPartitionRef/*))"!]
[!VAR "numEmiosHwModules" = "ecu:get('Ocu.Num_Emios_Hw_Modules')"!]



[!SELECT "./OcuGeneral/OcuEcucPartitionRef"!]
[!FOR "OcuPartitionId_temp" = "0" TO "$max_number_ocu_cfg"!]
    [!VAR "OcuEcucPartitionChannel" = "''"!]
    [!VAR "AlreadyParsedEmiosInstances" = "''"!]
    [!IF "$max_number_ocu_cfg != 0"!]
        [!IF "$OcuPartitionId_temp = $max_number_ocu_cfg"!] [!BREAK!] [!ENDIF!] 
        [!VAR "OcuEcucPartitionRefName" = "node:value(./*[$OcuPartitionId_temp + 1])"!]
        [!VAR "OcuPartitionIndex" = "concat('_P',$OcuPartitionId_temp)"!]
    [!ELSE!]
        [!VAR "OcuEcucPartitionRefName" = "''"!]
        [!VAR "OcuPartitionIndex" = "''"!]
    [!ENDIF!]
    [!LOOP "../../OcuConfigSet/OcuChannel/*"!]
        [!IF "$max_number_ocu_cfg != 0"!]
            [!VAR "OcuEcucPartitionChannel" = "node:value(OcuChannelEcucPartitionRef/*[1])"!]
        [!ENDIF!]

        [!IF "$OcuEcucPartitionRefName = $OcuEcucPartitionChannel"!]
            [!IF "contains(node:value(node:ref(./OcuHWSpecificSettingsRef)/OcuHardwareElements), 'EMIOS')"!]
                [!VAR "EmiosInstanceNo" = "text:split(node:value(node:ref(./OcuHWSpecificSettingsRef)/OcuHardwareElements), "_")[2]"!]
                [!IF "contains($AlreadyParsedEmiosInstances, $EmiosInstanceNo) = false()"!]
                    [!VAR "AlreadyParsedEmiosInstances" = "concat($AlreadyParsedEmiosInstances, $EmiosInstanceNo)"!]
                [!ENDIF!]
            [!ENDIF!]
        [!ENDIF!]
    [!ENDLOOP!]
[!CODE!][!CR!][!CR!]
/** @brief    Ocu IPL configuration array for hardware instances configured within Partition[!"$OcuPartitionIndex"!] */
static const Emios_Ocu_Ip_ConfigType * const Emios_Ocu_Ip_ConfigTypeCfgPB[!"$VS_number"!][!"$OcuPartitionIndex"!][[!"$numEmiosHwModules"!]] = {[!CR!]
[!ENDCODE!]
[!FOR "Idx" = "0" TO "$numEmiosHwModules - 1"!]
    [!IF "contains($AlreadyParsedEmiosInstances, $Idx) = true()"!]
        [!CODE!]
        &Emios_Ocu_Ip_[!"$Idx"!]_ModuleCfgPB[!"$VS_number"!][!IF "$Idx != $numEmiosHwModules - 1"!][!CODE!],[!ENDCODE!][!ENDIF!][!CR!]
        [!ENDCODE!]
    [!ELSE!]
        [!CODE!]
        NULL_PTR[!IF "$Idx != $numEmiosHwModules - 1"!][!CODE!],[!ENDCODE!][!ENDIF!][!CR!]
        [!ENDCODE!]
    [!ENDIF!]
[!ENDFOR!]  
[!CODE!]
};
[!ENDCODE!]
[!ENDFOR!]
[!CODE!][!CR!][!ENDCODE!]
[!ENDSELECT!]


[!SELECT "./OcuGeneral/OcuEcucPartitionRef"!]
[!FOR "OcuPartitionId_temp" = "0" TO "$max_number_ocu_cfg"!]
    [!IF "$max_number_ocu_cfg != 0"!]
        [!IF "$OcuPartitionId_temp = $max_number_ocu_cfg"!] [!BREAK!] [!ENDIF!] 
        [!VAR "OcuEcucPartitionRefName" = "node:value(./*[$OcuPartitionId_temp + 1])"!]
        [!VAR "OcuPartitionIndex" = "concat('_P',$OcuPartitionId_temp)"!]
    [!ELSE!]
        [!VAR "OcuEcucPartitionRefName" = "''"!]
        [!VAR "OcuPartitionIndex" = "''"!]
    [!ENDIF!]
[!CODE!][!CR!]
/** @brief    IPW configuration array for Ocu channels configured within Partition[!"$OcuPartitionIndex"!] */
[!ENDCODE!]
[!CODE!]
static const Ocu_Ipw_IpChannelConfigType Ocu_Ipw_IpChCfgPB[!"$VS_number"!][!"$OcuPartitionIndex"!][OCU_CONF_CHANNELS_PB] = {
[!ENDCODE!]
[!VAR "OcuEcucPartitionChannel" = "''"!]
[!LOOP "../../OcuConfigSet/OcuChannel/*"!]
    [!IF "$max_number_ocu_cfg != 0"!]
        [!VAR "OcuEcucPartitionChannel" = "node:value(OcuChannelEcucPartitionRef/*[1])"!]
    [!ENDIF!]
    [!VAR "OcuHwElementSelected" = "node:value(node:ref(./OcuHWSpecificSettingsRef)/OcuHardwareElements)"!]
    [!CODE!]
    [!WS "4"!]/** @brief [!"$OcuHwElementSelected"!] [!"node:name(.)"!] */[!CR!]
    [!WS "4"!]{[!CR!]
    [!WS "8"!]/** @brief IP type of this channel */[!CR!]
    [!WS "8"!]OCU_EMIOS_CHANNEL,[!CR!]
    [!WS "8"!]/** @brief Emios Ip instance number used for this channel */
    [!WS "8"!](uint8)[!"text:split($OcuHwElementSelected,'_')[2]"!]U,
    [!WS "8"!]/** @brief Index in the configuration table of eMIOS IPL channels */[!CR!]
    [!ENDCODE!]
    [!IF "$OcuEcucPartitionRefName = $OcuEcucPartitionChannel"!]
        [!VAR "VarChannelIndex" = "0"!]
        [!LOOP "../../../OcuConfigSet/OcuChannel/*"!]
            [!IF "$OcuHwElementSelected = node:value(node:ref(./OcuHWSpecificSettingsRef)/OcuHardwareElements)"!]
                [!BREAK!]
            [!ENDIF!]
            [!IF "text:split($OcuHwElementSelected, "_")[2] = text:split(node:value(node:ref(./OcuHWSpecificSettingsRef)/OcuHardwareElements), "_")[2]"!]
                [!VAR "VarChannelIndex" = "$VarChannelIndex + 1"!]
            [!ENDIF!]
        [!ENDLOOP!]
        [!CODE!]
        [!WS "8"!](uint8)[!"num:i($VarChannelIndex)"!]U[!CR!]
        [!WS "4"!]},[!CR!]
        [!ENDCODE!]
    [!ELSE!]
        [!CODE!]
        [!WS "8"!](uint8)[!"num:i(255)"!]U[!CR!]
        [!WS "4"!]},[!CR!]
        [!ENDCODE!]
    [!ENDIF!]
[!ENDLOOP!]
[!CODE!]
};
[!CR!][!CR!]
[!ENDCODE!]
[!ENDFOR!]
[!ENDSELECT!]

[!SELECT "./OcuGeneral/OcuEcucPartitionRef"!]
[!FOR "OcuPartitionId_temp" = "0" TO "$max_number_ocu_cfg"!]
    [!VAR "OcuEcucPartitionChannel" = "''"!]
    [!VAR "AlreadyParsedEmiosInstances" = "''"!]
    [!IF "$max_number_ocu_cfg != 0"!]
        [!IF "$OcuPartitionId_temp = $max_number_ocu_cfg"!] [!BREAK!] [!ENDIF!] 
        [!VAR "OcuEcucPartitionRefName" = "node:value(./*[$OcuPartitionId_temp + 1])"!]
        [!VAR "OcuPartitionIndex" = "concat('_P',$OcuPartitionId_temp)"!]
    [!ELSE!]
        [!VAR "OcuEcucPartitionRefName" = "''"!]
        [!VAR "OcuPartitionIndex" = "''"!]
    [!ENDIF!]
[!CODE!][!CR!]
/** @brief    Ocu channels IPW configuration array for Partition[!"$OcuPartitionIndex"!] */
const Ocu_Ipw_IpConfigType Ocu_Ipw_IpCfgPB[!"$VS_number"!][!"$OcuPartitionIndex"!] = {[!CR!]
    &Emios_Ocu_Ip_ConfigTypeCfgPB[!"$VS_number"!][!"$OcuPartitionIndex"!],
    &Ocu_Ipw_IpChCfgPB[!"$VS_number"!][!"$OcuPartitionIndex"!]
[!ENDCODE!]
[!CODE!]
};[!CR!][!CR!]
[!ENDCODE!]
[!ENDFOR!]
[!ENDSELECT!]
[!ENDNOCODE!]

#define OCU_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Ocu_MemMap.h"

/*==================================================================================================
*                                       GLOBAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                    LOCAL FUNCTION PROTOTYPES
==================================================================================================*/

/*==================================================================================================
*                                        LOCAL FUNCTIONS
==================================================================================================*/

/*==================================================================================================
*                                        GLOBAL FUNCTIONS
==================================================================================================*/


#ifdef __cplusplus
}
#endif

/** @} */
[!ENDCODE!]
