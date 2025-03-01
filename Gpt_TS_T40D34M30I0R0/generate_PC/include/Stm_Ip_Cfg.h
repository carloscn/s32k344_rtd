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

#ifndef STM_IP_CFG_H
#define STM_IP_CFG_H

/**
*   @file           Stm_Ip_Cfg.h
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
/* Include all variants header files. */
[!IF "var:defined('postBuildVariant')"!]
    [!LOOP "variant:all()"!]
#include "Stm_Ip_[!"."!]_PBcfg.h"
    [!ENDLOOP!]
[!ELSE!]
#include "Stm_Ip_PBcfg.h"
[!ENDIF!]
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define STM_IP_VENDOR_ID_CFG                    43
#define STM_IP_AR_RELEASE_MAJOR_VERSION_CFG     4
#define STM_IP_AR_RELEASE_MINOR_VERSION_CFG     7
#define STM_IP_AR_RELEASE_REVISION_VERSION_CFG  0
#define STM_IP_SW_MAJOR_VERSION_CFG             3
#define STM_IP_SW_MINOR_VERSION_CFG             0
#define STM_IP_SW_PATCH_VERSION_CFG             0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
[!IF "var:defined('postBuildVariant')"!]
    [!LOOP "variant:all()"!]
#if (STM_IP_VENDOR_ID_CFG != STM_IP_VENDOR_ID_[!"."!]_PBCFG_H)
    #error "Stm_Ip_Cfg.h and Stm_Ip_[!"."!]_PBcfg.h have different vendor ids"
#endif
/* Check if this header file and header file are of the same Autosar version */
#if ((STM_IP_AR_RELEASE_MAJOR_VERSION_CFG != STM_IP_AR_RELEASE_MAJOR_VERSION_[!"."!]_PBCFG_H) || \
     (STM_IP_AR_RELEASE_MINOR_VERSION_CFG != STM_IP_AR_RELEASE_MINOR_VERSION_[!"."!]_PBCFG_H) || \
     (STM_IP_AR_RELEASE_REVISION_VERSION_CFG != STM_IP_AR_RELEASE_REVISION_VERSION_[!"."!]_PBCFG_H) \
    )
    #error "AutoSar Version Numbers of Stm_Ip_Cfg.h and Stm_Ip_[!"."!]_PBcfg.h are different"
#endif
/* Check if this header file and header file are of the same Software version */
#if ((STM_IP_SW_MAJOR_VERSION_CFG != STM_IP_SW_MAJOR_VERSION_[!"."!]_PBCFG_H) || \
     (STM_IP_SW_MINOR_VERSION_CFG != STM_IP_SW_MINOR_VERSION_[!"."!]_PBCFG_H) || \
     (STM_IP_SW_PATCH_VERSION_CFG != STM_IP_SW_PATCH_VERSION_[!"."!]_PBCFG_H) \
    )
    #error "Software Version Numbers of Stm_Ip_Cfg.h and Stm_Ip_[!"."!]_PBcfg.h are different"
#endif
    [!ENDLOOP!]
[!ELSE!]
#if (STM_IP_VENDOR_ID_CFG != STM_IP_VENDOR_ID_PBCFG_H)
    #error "Stm_Ip_Cfg.h and Stm_Ip_PBcfg.h have different vendor ids"
#endif
/* Check if this header file and header file are of the same Autosar version */
#if ((STM_IP_AR_RELEASE_MAJOR_VERSION_CFG != STM_IP_AR_RELEASE_MAJOR_VERSION_PBCFG_H) || \
     (STM_IP_AR_RELEASE_MINOR_VERSION_CFG != STM_IP_AR_RELEASE_MINOR_VERSION_PBCFG_H) || \
     (STM_IP_AR_RELEASE_REVISION_VERSION_CFG != STM_IP_AR_RELEASE_REVISION_VERSION_PBCFG_H) \
    )
    #error "AutoSar Version Numbers of Stm_Ip_Cfg.h and Stm_Ip_PBcfg.h are different"
#endif
/* Check if this header file and header file are of the same Software version */
#if ((STM_IP_SW_MAJOR_VERSION_CFG != STM_IP_SW_MAJOR_VERSION_PBCFG_H) || \
     (STM_IP_SW_MINOR_VERSION_CFG != STM_IP_SW_MINOR_VERSION_PBCFG_H) || \
     (STM_IP_SW_PATCH_VERSION_CFG != STM_IP_SW_PATCH_VERSION_PBCFG_H) \
    )
    #error "Software Version Numbers of Stm_Ip_Cfg.h and Stm_Ip_PBcfg.h are different"
#endif
[!ENDIF!]
/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/
/**
* @brief Dev error detect switch
*/
#define STM_IP_DEV_ERROR_DETECT ([!IF "GptDriverConfiguration/GptDevErrorDetect"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

/*================================================================================================*/
/**
* @brief    STM_IP_CHANGE_NEXT_TIMEOUT_VALUE switch
* @details  Enable/disable support for changing timeout value during timer running
*/
#define STM_IP_CHANGE_NEXT_TIMEOUT_VALUE     ([!IF "GptAutosarExt/GptChangeNextTimeoutValueApi"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

/*================================================================================================*/
/**
* @brief    STM_IP_PREDEFTIMER_FUNCTIONALITY_API switch
* @details  Enable/disable GPT_PREDEFTIMER_FUNCTIONALITY_API.
*/
#define STM_IP_PREDEFTIMER_FUNCTIONALITY_API ([!IF "GptConfigurationOfOptApiServices/GptPredefTimerFunctionalityApi"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

/*================================================================================================*/
/**
* @brief    STM_IP_ABSOLUTE_COUTNING_API switch
* @details  Enable/disable support for absolute compare value
*/
[!NOCODE!]
[!VAR "AbsCounting" = "0"!]
[!SELECT "./GptChannelConfigSet"!][!//
[!IF "count(GptStm/*) > '0'"!][!//
    [!LOOP "GptStm/*"!][!//
        [!LOOP "GptStmChannels/*"!][!//
            [!IF "StmAbsoluteCounting"!][!//
                [!VAR "AbsCounting" = "1"!]
            [!ENDIF!][!//
        [!ENDLOOP!][!//
    [!ENDLOOP!][!//
[!ENDIF!][!//
[!ENDSELECT!][!//
[!ENDNOCODE!]

#define STM_IP_ABSOLUTE_COUNTING_API    ([!IF "$AbsCounting=1"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

/*================================================================================================*/
/**
* @brief    STM_IP_ENABLE_USER_MODE_SUPPORT switch
* @details  Enable/disable support usermode.If this parameter has been configured to 'TRUE' the GPT driver code can be executed from both supervisor and user mode.
*/
#define STM_IP_ENABLE_USER_MODE_SUPPORT    ([!IF "GptAutosarExt/GptEnableUserModeSupport"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

#ifndef MCAL_ENABLE_USER_MODE_SUPPORT
    #ifdef STM_IP_ENABLE_USER_MODE_SUPPORT
        #if (STD_ON == STM_IP_ENABLE_USER_MODE_SUPPORT)
            #error MCAL_ENABLE_USER_MODE_SUPPORT is not enabled. For running Gpt in user mode the MCAL_ENABLE_USER_MODE_SUPPORT needs to be defined.
        #endif /* (STD_ON == STM_IP_ENABLE_USER_MODE_SUPPORT) */
    #endif /* ifndef MCAL_ENABLE_USER_MODE_SUPPORT */
#endif /* ifdef MCAL_ENABLE_USER_MODE_SUPPORT*/

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
#endif  /* STM_IP_CFG_H */
