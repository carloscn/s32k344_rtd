/*==================================================================================================
*   Project              : RTD AUTOSAR 4.7
*   Platform             : CORTEXM
*   Peripheral           : 
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

#ifndef POWER_IP_CFG_DEFINES_H
#define POWER_IP_CFG_DEFINES_H

/**
*   @file       Power_Ip_Cfg_Defines.h
*   @version    3.0.0
*
*   @brief   AUTOSAR Mcu - Post-Build(PB) configuration file code template.
*   @details Code template for Post-Build(PB) configuration file generation.
*
*   @addtogroup POWER_DRIVER_CONFIGURATION Power Ip Driver
*   @{
*/

#ifdef __cplusplus
extern "C"{
#endif


/*==================================================================================================
                                         INCLUDE FILES
 1) system and project includes
 2) needed interfaces from external units
 3) internal and external interfaces from this unit
==================================================================================================*/
#include "StandardTypes.h"
[!NOCODE!][!// Include specific header file
[!IF "node:exists(as:modconf("Resource")[1]/ResourceGeneral/ResourceSubderivative)"!][!//
    [!IF "contains(as:modconf("Resource")[1]/ResourceGeneral/ResourceSubderivative, 's32k312')"!][!//
[!CODE!][!WS "0"!]#include "S32K312_MC_ME.h"[!CR!][!ENDCODE!][!//
[!CODE!][!WS "0"!]#include "S32K312_MC_RGM.h"[!CR!][!ENDCODE!][!//
[!CODE!][!WS "0"!]#include "S32K312_PMC.h"[!CR!][!ENDCODE!][!//
[!CODE!][!WS "0"!]#include "S32K312_DCM_GPR.h"[!CR!][!ENDCODE!][!//
[!CODE!][!WS "0"!]#include "S32K312_FLASH.h"[!CR!][!ENDCODE!][!//
[!CODE!][!WS "0"!]#include "S32K312_SCB.h"[!CR!][!ENDCODE!][!//
    [!ELSEIF "contains(as:modconf("Resource")[1]/ResourceGeneral/ResourceSubderivative, 's32k311') or
                contains(as:modconf("Resource")[1]/ResourceGeneral/ResourceSubderivative, 's32k310')"!][!//
[!CODE!][!WS "0"!]#include "S32K311_MC_ME.h"[!CR!][!ENDCODE!][!//
[!CODE!][!WS "0"!]#include "S32K311_MC_RGM.h"[!CR!][!ENDCODE!][!//
[!CODE!][!WS "0"!]#include "S32K311_PMC.h"[!CR!][!ENDCODE!][!//
[!CODE!][!WS "0"!]#include "S32K311_DCM_GPR.h"[!CR!][!ENDCODE!][!//
[!CODE!][!WS "0"!]#include "S32K311_FLASH.h"[!CR!][!ENDCODE!][!//
[!CODE!][!WS "0"!]#include "S32K311_SCB.h"[!CR!][!ENDCODE!][!//
    [!ELSEIF "contains(as:modconf("Resource")[1]/ResourceGeneral/ResourceSubderivative, 's32k314')"!][!//
[!CODE!][!WS "0"!]#include "S32K314_MC_ME.h"[!CR!][!ENDCODE!][!//
[!CODE!][!WS "0"!]#include "S32K314_MC_RGM.h"[!CR!][!ENDCODE!][!//
[!CODE!][!WS "0"!]#include "S32K314_PMC.h"[!CR!][!ENDCODE!][!//
[!CODE!][!WS "0"!]#include "S32K314_DCM_GPR.h"[!CR!][!ENDCODE!][!//
[!CODE!][!WS "0"!]#include "S32K314_FLASH.h"[!CR!][!ENDCODE!][!//
[!CODE!][!WS "0"!]#include "S32K314_SCB.h"[!CR!][!ENDCODE!][!//
    [!ELSEIF "contains(as:modconf("Resource")[1]/ResourceGeneral/ResourceSubderivative, 's32k322')"!][!//
[!CODE!][!WS "0"!]#include "S32K322_MC_ME.h"[!CR!][!ENDCODE!][!//
[!CODE!][!WS "0"!]#include "S32K322_MC_RGM.h"[!CR!][!ENDCODE!][!//
[!CODE!][!WS "0"!]#include "S32K322_PMC.h"[!CR!][!ENDCODE!][!//
[!CODE!][!WS "0"!]#include "S32K322_DCM_GPR.h"[!CR!][!ENDCODE!][!//
[!CODE!][!WS "0"!]#include "S32K322_FLASH.h"[!CR!][!ENDCODE!][!//
[!CODE!][!WS "0"!]#include "S32K322_SCB.h"[!CR!][!ENDCODE!][!//
    [!ELSEIF "contains(as:modconf("Resource")[1]/ResourceGeneral/ResourceSubderivative, 's32k324')"!][!//
[!CODE!][!WS "0"!]#include "S32K324_MC_ME.h"[!CR!][!ENDCODE!][!//
[!CODE!][!WS "0"!]#include "S32K324_MC_RGM.h"[!CR!][!ENDCODE!][!//
[!CODE!][!WS "0"!]#include "S32K324_PMC.h"[!CR!][!ENDCODE!][!//
[!CODE!][!WS "0"!]#include "S32K324_DCM_GPR.h"[!CR!][!ENDCODE!][!//
[!CODE!][!WS "0"!]#include "S32K324_FLASH.h"[!CR!][!ENDCODE!][!//
[!CODE!][!WS "0"!]#include "S32K324_SCB.h"[!CR!][!ENDCODE!][!//
    [!ELSEIF "contains(as:modconf("Resource")[1]/ResourceGeneral/ResourceSubderivative, 's32k341')"!][!//
[!CODE!][!WS "0"!]#include "S32K341_MC_ME.h"[!CR!][!ENDCODE!][!//
[!CODE!][!WS "0"!]#include "S32K341_MC_RGM.h"[!CR!][!ENDCODE!][!//
[!CODE!][!WS "0"!]#include "S32K341_PMC.h"[!CR!][!ENDCODE!][!//
[!CODE!][!WS "0"!]#include "S32K341_DCM_GPR.h"[!CR!][!ENDCODE!][!//
[!CODE!][!WS "0"!]#include "S32K341_FLASH.h"[!CR!][!ENDCODE!][!//
[!CODE!][!WS "0"!]#include "S32K341_SCB.h"[!CR!][!ENDCODE!][!//
    [!ELSEIF "contains(as:modconf("Resource")[1]/ResourceGeneral/ResourceSubderivative, 's32k342')"!][!//
[!CODE!][!WS "0"!]#include "S32K342_MC_ME.h"[!CR!][!ENDCODE!][!//
[!CODE!][!WS "0"!]#include "S32K342_MC_RGM.h"[!CR!][!ENDCODE!][!//
[!CODE!][!WS "0"!]#include "S32K342_PMC.h"[!CR!][!ENDCODE!][!//
[!CODE!][!WS "0"!]#include "S32K342_DCM_GPR.h"[!CR!][!ENDCODE!][!//
[!CODE!][!WS "0"!]#include "S32K342_FLASH.h"[!CR!][!ENDCODE!][!//
[!CODE!][!WS "0"!]#include "S32K342_SCB.h"[!CR!][!ENDCODE!][!//
    [!ELSEIF "contains(as:modconf("Resource")[1]/ResourceGeneral/ResourceSubderivative, 's32k39')"!][!//
[!CODE!][!WS "0"!]#include "S32K39_MC_ME.h"[!CR!][!ENDCODE!][!//
[!CODE!][!WS "0"!]#include "S32K39_MC_RGM.h"[!CR!][!ENDCODE!][!//
[!CODE!][!WS "0"!]#include "S32K39_PMC.h"[!CR!][!ENDCODE!][!//
[!CODE!][!WS "0"!]#include "S32K39_DCM_GPR.h"[!CR!][!ENDCODE!][!//
[!CODE!][!WS "0"!]#include "S32K39_FLASH.h"[!CR!][!ENDCODE!][!//
[!CODE!][!WS "0"!]#include "S32K39_SCB.h"[!CR!][!ENDCODE!][!//
    [!ELSEIF "contains(as:modconf("Resource")[1]/ResourceGeneral/ResourceSubderivative, 's32k358') or
                contains(as:modconf("Resource")[1]/ResourceGeneral/ResourceSubderivative, 's32k328') or
                contains(as:modconf("Resource")[1]/ResourceGeneral/ResourceSubderivative, 's32k338') or
                contains(as:modconf("Resource")[1]/ResourceGeneral/ResourceSubderivative, 's32k348')"!][!//
[!CODE!][!WS "0"!]#include "S32K358_MC_ME.h"[!CR!][!ENDCODE!][!//
[!CODE!][!WS "0"!]#include "S32K358_MC_RGM.h"[!CR!][!ENDCODE!][!//
[!CODE!][!WS "0"!]#include "S32K358_PMC.h"[!CR!][!ENDCODE!][!//
[!CODE!][!WS "0"!]#include "S32K358_DCM_GPR.h"[!CR!][!ENDCODE!][!//
[!CODE!][!WS "0"!]#include "S32K358_FLASH.h"[!CR!][!ENDCODE!][!//
[!CODE!][!WS "0"!]#include "S32K358_SCB.h"[!CR!][!ENDCODE!][!//
    [!ELSEIF "contains(as:modconf("Resource")[1]/ResourceGeneral/ResourceSubderivative, 's32k388')"!][!//
[!CODE!][!WS "0"!]#include "S32K388_MC_ME.h"[!CR!][!ENDCODE!][!//
[!CODE!][!WS "0"!]#include "S32K388_MC_RGM.h"[!CR!][!ENDCODE!][!//
[!CODE!][!WS "0"!]#include "S32K388_PMC.h"[!CR!][!ENDCODE!][!//
[!CODE!][!WS "0"!]#include "S32K388_DCM_GPR.h"[!CR!][!ENDCODE!][!//
[!CODE!][!WS "0"!]#include "S32K388_FLASH.h"[!CR!][!ENDCODE!][!//
[!CODE!][!WS "0"!]#include "S32K388_SCB.h"[!CR!][!ENDCODE!][!//
    [!ELSEIF "contains(as:modconf("Resource")[1]/ResourceGeneral/ResourceSubderivative, 's32m27')"!][!//
[!CODE!][!WS "0"!]#include "S32M27x_MC_ME.h"[!CR!][!ENDCODE!][!//
[!CODE!][!WS "0"!]#include "S32M27x_MC_RGM.h"[!CR!][!ENDCODE!][!//
[!CODE!][!WS "0"!]#include "S32M27x_PMC.h"[!CR!][!ENDCODE!][!//
[!CODE!][!WS "0"!]#include "S32M27x_PMC_AE.h"[!CR!][!ENDCODE!][!//
[!CODE!][!WS "0"!]#include "S32M27x_DCM_GPR.h"[!CR!][!ENDCODE!][!//
[!CODE!][!WS "0"!]#include "S32M27x_FLASH.h"[!CR!][!ENDCODE!][!//
[!CODE!][!WS "0"!]#include "S32M27x_SCB.h"[!CR!][!ENDCODE!][!//
[!CODE!][!WS "0"!]#include "S32M27x_AEC_AE.h"[!CR!][!ENDCODE!][!//
    [!ELSE!][!//
[!CODE!][!WS "0"!]#include "S32K344_MC_ME.h"[!CR!][!ENDCODE!][!//
[!CODE!][!WS "0"!]#include "S32K344_MC_RGM.h"[!CR!][!ENDCODE!][!//
[!CODE!][!WS "0"!]#include "S32K344_PMC.h"[!CR!][!ENDCODE!][!//
[!CODE!][!WS "0"!]#include "S32K344_DCM_GPR.h"[!CR!][!ENDCODE!][!//
[!CODE!][!WS "0"!]#include "S32K344_FLASH.h"[!CR!][!ENDCODE!][!//
[!CODE!][!WS "0"!]#include "S32K344_SCB.h"[!CR!][!ENDCODE!][!//
    [!ENDIF!][!//
[!ENDIF!][!//
[!ENDNOCODE!][!//

/*==================================================================================================
                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define POWER_IP_CFG_DEFINES_VENDOR_ID                       43
#define POWER_IP_CFG_DEFINES_AR_RELEASE_MAJOR_VERSION        4
#define POWER_IP_CFG_DEFINES_AR_RELEASE_MINOR_VERSION        7
#define POWER_IP_CFG_DEFINES_AR_RELEASE_REVISION_VERSION     0
#define POWER_IP_CFG_DEFINES_SW_MAJOR_VERSION                3
#define POWER_IP_CFG_DEFINES_SW_MINOR_VERSION                0
#define POWER_IP_CFG_DEFINES_SW_PATCH_VERSION                0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
/* Check if Power_Ip_Cfg_Defines.h file and StandardTypes.h file are of the same Autosar version */
#if ((POWER_IP_CFG_DEFINES_AR_RELEASE_MAJOR_VERSION    != STD_AR_RELEASE_MAJOR_VERSION) || \
     (POWER_IP_CFG_DEFINES_AR_RELEASE_MINOR_VERSION    != STD_AR_RELEASE_MINOR_VERSION))
    #error "AutoSar Version Numbers of Power_Ip_Cfg_Defines.h and StandardTypes.h are different"
#endif
#endif
/*==================================================================================================
                                           DEFINES AND MACROS
==================================================================================================*/
/**
* @brief            Derivative used.
*/
#define POWER_IP_DERIVATIVE_[!"ecu:get('MCU.Derivative')"!]


[!NOCODE!]
    [!CODE!]#define PMC_CONFIG_RWBITS_MASK                      ( \[!CR!][!ENDCODE!]
    [!VAR "Mac_NumOfCONFIG" = "count(ecu:list('MCU.PMC.Config.List'))"!]
    [!FOR "CONFIGCounter" = "1" TO "$Mac_NumOfCONFIG"!]
        [!IF "$CONFIGCounter < $Mac_NumOfCONFIG"!]
[!CODE!]                                                    ((uint32)PMC_CONFIG_[!"ecu:list('MCU.PMC.Config.List')[num:i($CONFIGCounter)]"!]_MASK) |\[!CR!][!ENDCODE!]
        [!ELSE!]
[!CODE!]                                                    ((uint32)PMC_CONFIG_[!"ecu:list('MCU.PMC.Config.List')[num:i($CONFIGCounter)]"!]_MASK) )[!CR!][!ENDCODE!]
        [!ENDIF!]
    [!ENDFOR!]
[!ENDNOCODE!]


[!IF "node:exists(McuGeneralConfiguration/McuDisableRgmInit)"!]
/**
* @brief            If this parameter is set to TRUE, the Reset Generation Module (RGM) initialization has to be disabled from the MCU driver.
*/
#define POWER_IP_DISABLE_RGM_INIT      [!IF "McuGeneralConfiguration/McuDisableRgmInit = 'true'"!](STD_ON)[!ELSE!](STD_OFF)[!ENDIF!]
[!ENDIF!]

/**
* @brief            If this parameter is set to TRUE, the Power Management Controller (PMC) initialization has to be disabled from the MCU driver.
*/
#define POWER_IP_DISABLE_PMC_INIT      [!IF "McuGeneralConfiguration/McuDisablePmcInit = 'true'"!](STD_ON)[!ELSE!](STD_OFF)[!ENDIF!]

/**
* @brief            If this parameter is set to TRUE, the Switched Mode Power Supply (SMPS) initialization has to be disabled from the MCU driver.
*/
#define POWER_IP_ENABLE_SMPS_INIT      [!IF "contains(ecu:get('MCU.PMC.Config.List'), 'LMSMPSEN')"!](STD_ON)[!ELSE!](STD_OFF)[!ENDIF!]

/**
* @brief            Support for Low Power mode.
*/
#define POWER_IP_ENTER_LOW_POWER_MODE   [!IF "McuGeneralConfiguration/McuEnterLowPowerMode = 'true'"!](STD_ON)[!ELSE!](STD_OFF)[!ENDIF!]

/**
* @brief
*/
#define POWER_IP_PERFORM_RESET_API   [!IF "McuGeneralConfiguration/McuPerformResetApi = 'true'"!](STD_ON)[!ELSE!](STD_OFF)[!ENDIF!]


/**
* @brief            Configure PRTNm_COREn_ADDR registers
*/
#define POWER_IP_CONFIGURE_CADDRN    [!IF "McuCoreControlConfiguration/McuCoreBootAddressControl = 'true'"!](STD_ON)[!ELSE!](STD_OFF)[!ENDIF!]

/**
* @brief            Support for lockstep configuration (PTRNx_CORE_LOCKSTEP) registers.
*/
#define POWER_IP_LOCKSTEP_CTRL_SUPPORT    [!IF "text:tolower(ecu:get('MCU.MC_ME.LockStepControl')) = 'true'"!](STD_ON)[!ELSE!](STD_OFF)[!ENDIF!]

/**
* @brief            Support for Functional Reset Disable (FERD regiter present).
*/
#define POWER_IP_FUNCTIONAL_RESET_DISABLE_SUPPORT         [!IF "num:i( count( ecu:list('MCU.MC_RGM.FuncRstDis.List') ) ) != 0"!](STD_ON)[!ELSE!](STD_OFF)[!ENDIF!]


/**
* @brief            Max number of MC_ME partitions.
*/
#define POWER_IP_MAX_NUMBER_OF_PARTITIONS       ((uint8)[!"num:i( count( ecu:list('MCU.Partitions.List') ) )"!]U)

/**
* @brief            ISR Mcu_ResetAlternate_ISR is/isn't available (STD_ON/STD_OFF)
*/
#define POWER_IP_RESET_ALTERNATE_ISR_USED            [!IF "McuGeneralConfiguration/McuAlternateResetIsrUsed = 'true'"!](STD_ON)[!ELSE!](STD_OFF)[!ENDIF!]


#define POWER_IP_HAS_OUTPUT_SAFE_STATE     [!IF "text:tolower(ecu:get('MCU.MC_ME.HasOutputSafeState')) = 'true'"!](STD_ON)[!ELSE!](STD_OFF)[!ENDIF!]


#define POWER_IP_RESET_DURING_STANDBY_SUPPORTED  [!IF "text:tolower(ecu:get('MCU.RGM.ResetDuringStandbySupported')) = 'true'"!](STD_ON)[!ELSE!](STD_OFF)[!ENDIF!]


#define POWER_IP_RESET_DOMAINS_SUPPORTED             [!IF "text:tolower(ecu:get('MCU.RGM.DomainResetSupported')) = 'true'"!](STD_ON)[!ELSE!](STD_OFF)[!ENDIF!]

/**
* @brief            PMC_AE Configuration Register (CONFIG) and PMC_AE Monitor Register (MONITOR).
*/
#define POWER_IP_PMC_AE_SUPPORT     [!IF "text:tolower(ecu:get('MCU.PMC.AE.SUPPORT')) = 'true'"!](STD_ON)[!ELSE!](STD_OFF)[!ENDIF!]

/**
* @brief            AEC Configuration Register (RSTGEN_CFG).
*/
#define POWER_IP_AEC_SUPPORT     [!IF "text:tolower(ecu:get('MCU.AEC.RSTGENCFG.SUPPORT')) = 'true'"!](STD_ON)[!ELSE!](STD_OFF)[!ENDIF!]

/**
* @brief            Enable the usage of Non-Autosar API  Power_Ip_PmcAeConfig().
*/
#define POWER_IP_PMCAECONFIG_API     [!IF "node:exists(McuDebugConfiguration/McuPmcAeConfigApi)"!][!IF "McuDebugConfiguration/McuPmcAeConfigApi = 'true'"!](STD_ON)[!ELSE!](STD_OFF)[!ENDIF!][!ELSE!](STD_ON)[!ENDIF!]

/**
* @brief            Enable the usage of Non-Autosar API  Power_Ip_AecResetConfig().
*/
#define POWER_IP_AECRESETCONFIG_API     [!IF "node:exists(McuDebugConfiguration/McuAecResetConfigApi)"!][!IF "McuDebugConfiguration/McuAecResetConfigApi = 'true'"!](STD_ON)[!ELSE!](STD_OFF)[!ENDIF!][!ELSE!](STD_ON)[!ENDIF!]

/**
* @brief            ISR Mcu_PMC_UnderOverVoltage_ISR is/isn't available (STD_ON/STD_OFF)
*/
#define POWER_IP_VOLTAGE_ERROR_ISR_USED              [!IF "McuGeneralConfiguration/McuVoltageErrorIsrUsed = 'true'"!](STD_ON)[!ELSE!](STD_OFF)[!ENDIF!]
/**
* @brief            Create defines with the values assigned to Mcu Reset Reason configurations.
*                   These values can be  retrieved from Mcu_GetResetReason Api.
*/
[!LOOP "McuPublishedInformation/McuResetReasonConf/*"!]

#define McuConf_McuResetReasonConf_[!"name(.)"!]   ((uint8)[!"num:i(McuResetReason)"!]U)
[!ENDLOOP!]

[!IF "ecu:get('MCU.SLEEPONEXIT.SUPPORT') = 'true'"!]
/**
* @brief           This define controls the availability of function Mcu_SleepOnExit
*/
#define POWER_IP_SLEEPONEXIT_SUPPORT    (STD_ON)
[!ENDIF!]

/**
* @brief            Support Mc_Me COFB (COFB regiter present).
*/
#define POWER_IP_MC_ME_COFB_SUPPORT         [!IF "text:tolower(ecu:get('MCU.MC_ME.COFBSupported')) = 'true'"!](STD_ON)[!ELSE!](STD_OFF)[!ENDIF!]

[!NOCODE!]
[!VAR "NumOfPartitions" = "count(ecu:list('MCU.Partitions.List'))"!]
[!FOR "PartitionCounter" = "1" TO "$NumOfPartitions"!]
    [!VAR "PrtEffectiveIndex" = "num:i(substring-after(ecu:list('MCU.Partitions.List')[number($PartitionCounter)], 'Partition'))"!]
    [!VAR "CofbResourcePath" = "concat('MCU.MC_ME.Partition', $PrtEffectiveIndex, '.COFBs.List')"!]
    [!VAR "NumOfCofbs" = "num:i(count(ecu:list($CofbResourcePath)))"!]
    [!FOR "CofbCounter" = "1" TO "$NumOfCofbs"!]
        [!VAR "CofbEffectiveIndex" = "num:i(substring-after(ecu:list($CofbResourcePath)[number($CofbCounter)], 'COFB_'))"!]
        [!CODE!][!//
/***********************************************************/
/*                 MC_ME_PRTN[!"$PrtEffectiveIndex"!]_COFB[!"$CofbEffectiveIndex"!]_CLKEN                 */
/***********************************************************/
#define MC_ME_PRTN[!"$PrtEffectiveIndex"!]_COFB[!"$CofbEffectiveIndex"!]_CLKEN_RWBITS_MASK  ((uint32)( \[!CR!][!ENDCODE!]
        [!VAR "NumOfReqs" = "count(ecu:list('MCU.MC_ME.Peripherals.Slots.List'))"!]
        [!FOR "ReqCounter" = "1" TO "$NumOfReqs"!]
            [!IF "contains(ecu:list('MCU.MC_ME.Peripherals.Slots.List')[num:i($ReqCounter)], concat('PRTN', num:i($PrtEffectiveIndex), '_COFB', num:i($CofbEffectiveIndex), '_REQ'))"!]
                [!VAR "ReqIndex" = "num:i(substring-after(ecu:list('MCU.MC_ME.Peripherals.Slots.List')[num:i($ReqCounter)], concat('PRTN', num:i($PrtEffectiveIndex), '_COFB', num:i($CofbEffectiveIndex), '_REQ')))"!]
[!CODE!][!WS "20"!]MC_ME_PRTN[!"$PrtEffectiveIndex"!]_COFB[!"$CofbEffectiveIndex"!]_CLKEN_REQ[!"$ReqIndex"!]_MASK | \[!CR!][!ENDCODE!]
            [!ENDIF!]
        [!ENDFOR!]
        [!CODE!][!WS "20"!]0x00000000))[!CR!][!ENDCODE!]
[!CODE!]#define MC_ME_PRTN[!"$PrtEffectiveIndex"!]_COFB[!"$CofbEffectiveIndex"!]_CLKEN(value)       ((uint32)(((uint32)(value)) & MC_ME_PRTN[!"$PrtEffectiveIndex"!]_COFB[!"$CofbEffectiveIndex"!]_CLKEN_RWBITS_MASK))[!CR!][!ENDCODE!]
    [!ENDFOR!]
[!ENDFOR!]
[!ENDNOCODE!]
/*==================================================================================================
                                             ENUMS
==================================================================================================*/


/*==================================================================================================
                                 STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/



#ifdef __cplusplus
}
#endif

/** @} */
#endif /* #ifndef POWER_IP_CFG_DEFINES_H */


