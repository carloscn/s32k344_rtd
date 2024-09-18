[!CODE!][!//
[!AUTOSPACING!][!//
[!NOCODE!][!//

[!MACRO "GenerateUniqueElements", "ListWithDuplicateElements"!][!//
    [!VAR "ListWithUniqueElements" = "''"!][!//
    [!FOR "index" = "0" TO "num:i(count(text:split($ListWithDuplicateElements)))"!][!//
        [!IF "not(text:contains(text:split($ListWithUniqueElements), text:split($ListWithDuplicateElements)[$index + 1]))"!][!//
            [!VAR "ListWithUniqueElements" = "concat($ListWithUniqueElements, ' ', text:split($ListWithDuplicateElements)[$index + 1])"!][!//
        [!ENDIF!][!//
    [!ENDFOR!][!//
    [!"$ListWithUniqueElements"!][!//
[!ENDMACRO!][!//

[!ENDNOCODE!][!//
/*==================================================================================================
*   Project              : RTD AUTOSAR 4.7
*   Platform             : CORTEXM
*   Peripheral           : Emios Siul2 Wkpu LpCmp
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

#ifndef SIUL2_ICU_IP_CFG_H
#define SIUL2_ICU_IP_CFG_H

/**
 *   @file       Siul2_Icu_Ip_Cfg.h
 *   @version    3.0.0
 *
 *   @brief      AUTOSAR Icu - contains the data exported by the Icu module
 *   @details    Contains the information that will be exported by the module, as requested by Autosar.
 *
 *   @addtogroup siul2_icu_ip SIUL2 IPL
 *   @{
 */
 
#ifdef __cplusplus
extern "C"{
#endif

 /*==================================================================================================
 *                                         INCLUDE FILES
 * 1) system and project includes
 * 2) needed interfaces from external units
 * 3) internal and external interfaces from this unit
 *================================================================================================*/
#include "Std_Types.h"
[!NOCODE!][!//
[!IF "var:defined('postBuildVariant')"!][!//
    [!LOOP "variant:all()"!][!//
        [!CODE!][!WS "0"!]#include "Siul2_Icu_Ip_[!"."!]_PBcfg.h"[!CR!][!ENDCODE!][!//
    [!ENDLOOP!][!//
[!ELSE!][!//
    [!CODE!][!WS "0"!]#include "Siul2_Icu_Ip_PBcfg.h"[!CR!][!ENDCODE!][!//
[!ENDIF!][!//
[!ENDNOCODE!][!//

/*==================================================================================================
 *                              SOURCE FILE VERSION INFORMATION
 *================================================================================================*/
#define SIUL2_ICU_IP_CFG_VENDOR_ID                       43
#define SIUL2_ICU_IP_CFG_AR_RELEASE_MAJOR_VERSION        4
#define SIUL2_ICU_IP_CFG_AR_RELEASE_MINOR_VERSION        7
#define SIUL2_ICU_IP_CFG_AR_RELEASE_REVISION_VERSION     0
#define SIUL2_ICU_IP_CFG_SW_MAJOR_VERSION                3
#define SIUL2_ICU_IP_CFG_SW_MINOR_VERSION                0
#define SIUL2_ICU_IP_CFG_SW_PATCH_VERSION                0

/*==================================================================================================
 *                                      FILE VERSION CHECKS
 *================================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if header file and Std_Types.h file are of the same Autosar version */
    #if ((SIUL2_ICU_IP_CFG_AR_RELEASE_MAJOR_VERSION != STD_AR_RELEASE_MAJOR_VERSION) || \
         (SIUL2_ICU_IP_CFG_AR_RELEASE_MINOR_VERSION != STD_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of Siul2_Icu_Ip_Cfg.h and Std_Types.h are different"
    #endif
#endif

[!IF "var:defined('postBuildVariant')"!][!//
    [!LOOP "variant:all()"!][!//
/* Check if source file and ICU configuration header file are of the same vendor */
#if (SIUL2_ICU_IP_CFG_VENDOR_ID != SIUL2_ICU_IP_[!"."!]_PBCFG_VENDOR_ID)
    #error "Siul2_Icu_Ip_Cfg.h and Siul2_Icu_Ip_[!"."!]_PBcfg.h have different vendor IDs"
#endif
    /* Check if header file and Icu configuration header file are of the same Autosar version */
#if ((SIUL2_ICU_IP_CFG_AR_RELEASE_MAJOR_VERSION != SIUL2_ICU_IP_[!"."!]_PBCFG_AR_RELEASE_MAJOR_VERSION) || \
     (SIUL2_ICU_IP_CFG_AR_RELEASE_MINOR_VERSION != SIUL2_ICU_IP_[!"."!]_PBCFG_AR_RELEASE_MINOR_VERSION) || \
     (SIUL2_ICU_IP_CFG_AR_RELEASE_REVISION_VERSION != SIUL2_ICU_IP_[!"."!]_PBCFG_AR_RELEASE_REVISION_VERSION) )
    #error "AutoSar Version Numbers of Siul2_Icu_Ip_Cfg.h and Siul2_Icu_Ip_[!"."!]_PBcfg.h are different"
#endif
/* Check if header file and Icu configuration header file are of the same software version */
#if ((SIUL2_ICU_IP_CFG_SW_MAJOR_VERSION != SIUL2_ICU_IP_[!"."!]_PBCFG_SW_MAJOR_VERSION) || \
     (SIUL2_ICU_IP_CFG_SW_MINOR_VERSION != SIUL2_ICU_IP_[!"."!]_PBCFG_SW_MINOR_VERSION) || \
     (SIUL2_ICU_IP_CFG_SW_PATCH_VERSION != SIUL2_ICU_IP_[!"."!]_PBCFG_SW_PATCH_VERSION) )
    #error "Software Version Numbers of Siul2_Icu_Ip_Cfg.h and Siul2_Icu_Ip_[!"."!]_PBcfg.h are different"
#endif
    [!ENDLOOP!][!//
[!ELSE!][!//
/* Check if source file and ICU configuration header file are of the same vendor */
#if (SIUL2_ICU_IP_CFG_VENDOR_ID != SIUL2_ICU_IP_PBCFG_VENDOR_ID)
    #error "Siul2_Icu_Ip_Cfg.h and Siul2_Icu_Ip_PBcfg.h have different vendor IDs"
#endif
    /* Check if header file and Icu configuration header file are of the same Autosar version */
#if ((SIUL2_ICU_IP_CFG_AR_RELEASE_MAJOR_VERSION != SIUL2_ICU_IP_PBCFG_AR_RELEASE_MAJOR_VERSION) || \
     (SIUL2_ICU_IP_CFG_AR_RELEASE_MINOR_VERSION != SIUL2_ICU_IP_PBCFG_AR_RELEASE_MINOR_VERSION) || \
     (SIUL2_ICU_IP_CFG_AR_RELEASE_REVISION_VERSION != SIUL2_ICU_IP_PBCFG_AR_RELEASE_REVISION_VERSION) )
    #error "AutoSar Version Numbers of Siul2_Icu_Ip_Cfg.h and Siul2_Icu_Ip_PBcfg.h are different"
#endif
/* Check if header file and Icu configuration header file are of the same software version */
#if ((SIUL2_ICU_IP_CFG_SW_MAJOR_VERSION != SIUL2_ICU_IP_PBCFG_SW_MAJOR_VERSION) || \
     (SIUL2_ICU_IP_CFG_SW_MINOR_VERSION != SIUL2_ICU_IP_PBCFG_SW_MINOR_VERSION) || \
     (SIUL2_ICU_IP_CFG_SW_PATCH_VERSION != SIUL2_ICU_IP_PBCFG_SW_PATCH_VERSION) )
    #error "Software Version Numbers of Siul2_Icu_Ip_Cfg.h and Siul2_Icu_Ip_PBcfg.h are different"
#endif
[!ENDIF!][!//
/*==================================================================================================
                                       DEFINES AND MACROS
==================================================================================================*/
[!NOCODE!][!//
[!CODE!][!WS "0"!]#if (STD_ON == SIUL2_ICU_IP_USED)[!CR!][!ENDCODE!][!//
[!IF "node:exists(as:modconf("Resource")[1]/ResourceGeneral/ResourceSubderivative)"!][!//
    [!IF "contains(as:modconf("Resource")[1]/ResourceGeneral/ResourceSubderivative, 's32k3') or contains(as:modconf("Resource")[1]/ResourceGeneral/ResourceSubderivative, 's32m27')"!][!//
        [!CODE!][!WS "0"!]/** @brief SIUL2 external ISRs configured for ICU channels. */[!CR!][!ENDCODE!][!//
        [!SELECT "IcuConfigSet"!][!//
            [!LOOP "IcuHwInterruptConfigList/*"!][!//
                [!IF "(IcuIsrEnable = 'true') and (contains(IcuIsrHwId, 'IRQ'))"!][!//
                    [!CODE!][!WS "0"!]#define SIUL2_ICU_[!"text:split(./IcuIsrHwId, '_0_')[2]"!]_ISR_USED[!CR!][!CR!][!ENDCODE!][!//
                [!ENDIF!][!//
            [!ENDLOOP!][!//
        [!ENDSELECT!][!//
    [!ENDIF!][!//

    [!IF "contains(as:modconf("Resource")[1]/ResourceGeneral/ResourceSubderivative, 's32g2') or contains(as:modconf("Resource")[1]/ResourceGeneral/ResourceSubderivative, 's32r45') or contains(as:modconf("Resource")[1]/ResourceGeneral/ResourceSubderivative, 's32r41') or contains(as:modconf("Resource")[1]/ResourceGeneral/ResourceSubderivative, 's32g3') or contains(as:modconf("Resource")[1]/ResourceGeneral/ResourceSubderivative, 'saf85')"!][!//
        [!VAR "UsingSiul2Interrupt" = "0"!][!//
        [!LOOP "IcuConfigSet/IcuHwInterruptConfigList/*"!][!//
            [!IF "(IcuIsrEnable = 'true') and (contains(IcuIsrHwId, 'IRQ'))"!][!//
                [!VAR "UsingSiul2Interrupt"="$UsingSiul2Interrupt + 1"!][!//
            [!ENDIF!][!//
        [!ENDLOOP!][!//
        [!IF "contains(as:modconf("Resource")[1]/ResourceGeneral/ResourceSubderivative, 's32r45') or contains(as:modconf("Resource")[1]/ResourceGeneral/ResourceSubderivative, 's32g2') or contains(as:modconf("Resource")[1]/ResourceGeneral/ResourceSubderivative, 's32g3')"!][!//
            [!CODE!][!WS "0"!]/** @brief SIUL2 external ISRs configured for ICU channels. */[!CR!][!ENDCODE!][!//
            [!CODE!]#define SIUL2_1_ICU_EIRQ_SINGLE_INT      ([!IF "$UsingSiul2Interrupt != 0"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])[!CR!][!ENDCODE!][!//
        [!ENDIF!][!//
        [!IF "contains(as:modconf("Resource")[1]/ResourceGeneral/ResourceSubderivative, 's32r41') or contains(as:modconf("Resource")[1]/ResourceGeneral/ResourceSubderivative, 'saf85')"!][!//
            [!CODE!][!WS "0"!]/** @brief SIUL2 external ISRs configured for ICU channels. */[!CR!][!ENDCODE!][!//
            [!CODE!]#define SIUL2_0_ICU_EIRQ_SINGLE_INT      ([!IF "$UsingSiul2Interrupt != 0"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])[!CR!][!ENDCODE!][!//
        [!ENDIF!][!//
    [!ENDIF!][!//

    [!IF "contains(as:modconf("Resource")[1]/ResourceGeneral/ResourceSubderivative, 's32e') or
          contains(as:modconf("Resource")[1]/ResourceGeneral/ResourceSubderivative, 's32z')"!][!//
        [!VAR "ListOfUsedIrqs" = "''"!][!//

        [!LOOP "IcuConfigSet/IcuHwInterruptConfigList/*"!][!//
            [!IF "(IcuIsrEnable = 'true') and (contains(IcuIsrHwId, 'IRQ'))"!][!//
                [!VAR "Siul2InstanceUsed" = "text:split(node:value(IcuIsrHwId), '_IRQ')[1]"!][!//
                [!VAR "ListOfUsedIrqs" = "concat($ListOfUsedIrqs, ' ', $Siul2InstanceUsed)"!][!//
            [!ENDIF!][!//
        [!ENDLOOP!][!//

        [!VAR "UniqueUsedSiul2"!][!CALL "GenerateUniqueElements", "ListWithDuplicateElements" = "$ListOfUsedIrqs"!][!ENDVAR!][!//

        [!FOR "x" = "1" TO "num:i(count(text:split($UniqueUsedSiul2, ' ')))"!][!//
            [!CODE!][!WS "0"!]/* SIUL2 external interrupt used. */[!CR!][!ENDCODE!][!//
            [!CODE!][!WS "0"!]#define [!"(text:split($UniqueUsedSiul2, ' '))[num:i($x)]"!]_ICU_EIRQ_SINGLE_INT    (STD_ON)[!CR!][!CR!][!ENDCODE!][!//
        [!ENDFOR!][!//
    [!ENDIF!][!//
 
[!ENDIF!][!//
[!ENDNOCODE!][!//

[!IF "count(./IcuConfigSet/IcuSiul2/*) > '0'"!][!//
    [!CODE!]/* Export SIUL2 configuration. */[!CR!][!ENDCODE!][!//
    [!CODE!]#define SIUL2_ICU_CONFIG_EXT \[!CR!][!ENDCODE!][!//
    [!IF "var:defined('postBuildVariant')"!][!//
        [!LOOP "variant:all()"!][!//
            [!CODE!][!WS "8"!]SIUL2_ICU_CONFIG_[!"."!]_PB \[!CR!][!ENDCODE!][!//
        [!ENDLOOP!][!//
    [!ELSE!][!//
        [!CODE!][!WS "8"!]SIUL2_ICU_CONFIG_PB[!CR!][!ENDCODE!][!//
    [!ENDIF!][!//
    [!CODE!][!CR!][!ENDCODE!][!//
[!ENDIF!][!//

#endif /* SIUL2_ICU_IP_USED */

#ifdef __cplusplus
}
#endif

/** @} */

#endif  /* SIUL2_ICU_IP_CFG_H */
[!ENDCODE!]
