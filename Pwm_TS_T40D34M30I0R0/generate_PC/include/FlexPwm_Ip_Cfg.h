[!CODE!][!//
[!AUTOSPACING!]
/*==================================================================================================
*   Project              : RTD AUTOSAR 4.7
*   Platform             : CORTEXM
*   Peripheral           : Emios Flexio FlexPwm
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

#ifndef FLEXPWM_IP_CFG_H
#define FLEXPWM_IP_CFG_H

/**
*   @file       FlexPwm_Ip_Cfg.h
*
*   @addtogroup flexpwm_ip FlexPwm IPL
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
/* Standard Types */
#include "Std_Types.h"

/* Register definitions */
[!IF "node:exists(as:modconf("Resource")[1]/ResourceGeneral/ResourceSubderivative)"!][!//
    [!IF "contains(as:modconf("Resource")[1]/ResourceGeneral/ResourceSubderivative, 's32e')"!][!//
        [!CODE!][!WS "0"!]#include "S32E2_FLEXPWM.h"[!CR!][!ENDCODE!][!//
    [!ELSEIF "contains(as:modconf("Resource")[1]/ResourceGeneral/ResourceSubderivative, 's32k39')"!][!//
        [!CODE!][!WS "0"!]#include "S32K39_FLEXPWM.h"[!CR!][!ENDCODE!][!//
    [!ENDIF!][!//
[!ENDIF!][!//

/* Include all variants header files. */
[!IF "var:defined('postBuildVariant')"!]
    [!LOOP "variant:all()"!]
#include "FlexPwm_Ip_[!"."!]_PBcfg.h"
    [!ENDLOOP!]
[!ELSE!]
#include "FlexPwm_Ip_PBcfg.h"
[!ENDIF!]

/* Include Feature Defines */
#include "FlexPwm_Ip_CfgDefines.h"
#include "Reg_eSys.h"
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define FLEXPWM_IP_CFG_VENDOR_ID                    43
#define FLEXPWM_IP_CFG_MODULE_ID                    121
#define FLEXPWM_IP_CFG_AR_RELEASE_MAJOR_VERSION     4
#define FLEXPWM_IP_CFG_AR_RELEASE_MINOR_VERSION     7
#define FLEXPWM_IP_CFG_AR_RELEASE_REVISION_VERSION  0
#define FLEXPWM_IP_CFG_SW_MAJOR_VERSION             3
#define FLEXPWM_IP_CFG_SW_MINOR_VERSION             0
#define FLEXPWM_IP_CFG_SW_PATCH_VERSION             0

/*===============================================================================================
*                                      FILE VERSION CHECKS
===============================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if header file and Std_Types.h are of the same AUTOSAR version */
    #if ((FLEXPWM_IP_CFG_AR_RELEASE_MAJOR_VERSION != STD_AR_RELEASE_MAJOR_VERSION) || \
         (FLEXPWM_IP_CFG_AR_RELEASE_MINOR_VERSION != STD_AR_RELEASE_MINOR_VERSION))
        #error "AUTOSAR Version Numbers of FlexPwm_Ip_Cfg.h and Std_Types.h are different"
    #endif
    
    /* Check if header file and Reg_eSys.h are of the same AUTOSAR version */
    #if ((FLEXPWM_IP_CFG_AR_RELEASE_MAJOR_VERSION != REG_ESYS_AR_RELEASE_MAJOR_VERSION) || \
         (FLEXPWM_IP_CFG_AR_RELEASE_MINOR_VERSION != REG_ESYS_AR_RELEASE_MINOR_VERSION))
        #error "AUTOSAR Version Numbers of FlexPwm_Ip_Cfg.h and Reg_eSys.h are different"
    #endif
#endif

[!IF "var:defined('postBuildVariant')"!]
    [!LOOP "variant:all()"!]
/* Check if header file and FlexPwm_Ip_[!"."!]_Pbcfg header file are of the same vendor */
#if (FLEXPWM_IP_CFG_VENDOR_ID != FLEXPWM_IP_[!"."!]_PB_CFG_VENDOR_ID)
    #error "Vendor IDs of FlexPwm_Ip_Cfg.h and FlexPwm_Ip_[!"."!]_Pbcfg.h are different."
#endif

/* Check if header file and FlexPwm_Ip_[!"."!]_Pbcfg header file are of the same AUTOSAR version */
#if ((FLEXPWM_IP_CFG_AR_RELEASE_MAJOR_VERSION    != FLEXPWM_IP_[!"."!]_PB_CFG_AR_RELEASE_MAJOR_VERSION) || \
     (FLEXPWM_IP_CFG_AR_RELEASE_MINOR_VERSION    != FLEXPWM_IP_[!"."!]_PB_CFG_AR_RELEASE_MINOR_VERSION) || \
     (FLEXPWM_IP_CFG_AR_RELEASE_REVISION_VERSION != FLEXPWM_IP_[!"."!]_PB_CFG_AR_RELEASE_REVISION_VERSION))
    #error "AUTOSAR version numbers of FlexPwm_Ip_Cfg.h and FlexPwm_Ip_[!"."!]_Pbcfg.h are different."
#endif

/* Check if header file and FlexPwm_Ip_[!"."!]_Pbcfg header file are of the same software version */
#if ((FLEXPWM_IP_CFG_SW_MAJOR_VERSION != FLEXPWM_IP_[!"."!]_PB_CFG_SW_MAJOR_VERSION) || \
     (FLEXPWM_IP_CFG_SW_MINOR_VERSION != FLEXPWM_IP_[!"."!]_PB_CFG_SW_MINOR_VERSION) || \
     (FLEXPWM_IP_CFG_SW_PATCH_VERSION != FLEXPWM_IP_[!"."!]_PB_CFG_SW_PATCH_VERSION))
    #error "Software version numbers of FlexPwm_Ip_Cfg.h and FlexPwm_Ip_[!"."!]_Pbcfg.h are different."
#endif
    [!ENDLOOP!]
[!ELSE!]
/* Check if header file and FlexPwm_Ip_Pbcfg header file are of the same vendor */
#if (FLEXPWM_IP_CFG_VENDOR_ID != FLEXPWM_IP_PB_CFG_VENDOR_ID)
    #error "Vendor IDs of FlexPwm_Ip_Cfg.h and FlexPwm_Ip_Pbcfg.h are different."
#endif

/* Check if header file and FlexPwm_Ip_Pbcfg header file are of the same AUTOSAR version */
#if ((FLEXPWM_IP_CFG_AR_RELEASE_MAJOR_VERSION    != FLEXPWM_IP_PB_CFG_AR_RELEASE_MAJOR_VERSION) || \
     (FLEXPWM_IP_CFG_AR_RELEASE_MINOR_VERSION    != FLEXPWM_IP_PB_CFG_AR_RELEASE_MINOR_VERSION) || \
     (FLEXPWM_IP_CFG_AR_RELEASE_REVISION_VERSION != FLEXPWM_IP_PB_CFG_AR_RELEASE_REVISION_VERSION))
    #error "AUTOSAR version numbers of FlexPwm_Ip_Cfg.h and FlexPwm_Ip_Pbcfg.h are different."
#endif

/* Check if header file and FlexPwm_Ip_Pbcfg header file are of the same software version */
#if ((FLEXPWM_IP_CFG_SW_MAJOR_VERSION != FLEXPWM_IP_PB_CFG_SW_MAJOR_VERSION) || \
     (FLEXPWM_IP_CFG_SW_MINOR_VERSION != FLEXPWM_IP_PB_CFG_SW_MINOR_VERSION) || \
     (FLEXPWM_IP_CFG_SW_PATCH_VERSION != FLEXPWM_IP_PB_CFG_SW_PATCH_VERSION))
    #error "Software version numbers of FlexPwm_Ip_Cfg.h and FlexPwm_Ip_Pbcfg.h are different."
#endif
[!ENDIF!]

/* Check if header file and FlexPwm_Ip_CfgDefines header file are of the same vendor */
#if (FLEXPWM_IP_CFG_VENDOR_ID != FLEXPWM_IP_CFGDEFINES_VENDOR_ID)
    #error "Vendor IDs of FlexPwm_Ip_Cfg.h and FlexPwm_Ip_CfgDefines.h are different."
#endif

/* Check if header file and FlexPwm_Ip_CfgDefines header file are of the same AUTOSAR version */
#if ((FLEXPWM_IP_CFG_AR_RELEASE_MAJOR_VERSION    != FLEXPWM_IP_CFGDEFINES_AR_RELEASE_MAJOR_VERSION) || \
     (FLEXPWM_IP_CFG_AR_RELEASE_MINOR_VERSION    != FLEXPWM_IP_CFGDEFINES_AR_RELEASE_MINOR_VERSION) || \
     (FLEXPWM_IP_CFG_AR_RELEASE_REVISION_VERSION != FLEXPWM_IP_CFGDEFINES_AR_RELEASE_REVISION_VERSION))
    #error "AUTOSAR version numbers of FlexPwm_Ip_Cfg.h and FlexPwm_Ip_CfgDefines.h are different."
#endif

/* Check if header file and FlexPwm_Ip_CfgDefines header file are of the same software version */
#if ((FLEXPWM_IP_CFG_SW_MAJOR_VERSION != FLEXPWM_IP_CFGDEFINES_SW_MAJOR_VERSION) || \
     (FLEXPWM_IP_CFG_SW_MINOR_VERSION != FLEXPWM_IP_CFGDEFINES_SW_MINOR_VERSION) || \
     (FLEXPWM_IP_CFG_SW_PATCH_VERSION != FLEXPWM_IP_CFGDEFINES_SW_PATCH_VERSION))
    #error "Software version numbers of FlexPwm_Ip_Cfg.h and FlexPwm_Ip_CfgDefines.h are different."
#endif

/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/
/** @brief      In HLD this macro is OFF */
#define FLEXPWM_IP_DEV_ERROR_DETECT            (STD_OFF)

/** @brief    Support for User mode */
#define FLEXPWM_IP_ENABLE_USER_MODE_SUPPORT    ([!IF "PwmGeneral/PwmEnableUserModeSupport"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

/** @brief      The number of FlexPwm instances available on platform */
#define FLEXPWM_IP_INSTANCE_COUNT              (uint8)([!"ecu:get('Pwm.FlexPwmHwModulesNum')"!]U)
/** @brief      The number of channels available on each FlexPwm instance */
#define FLEXPWM_IP_SUBMODULE_COUNT             (uint8)([!"ecu:get('Pwm.FlexPwmHwSubModulesNum')"!]U)

#define FLEXPWM_IP_NUMCHANNELS_PER_SUBMODULE   (uint8)([!"ecu:get('Pwm.FlexPwmHwChannelInSubModuleNum')"!]U)

/** @brief      The number of channels available on each FlexPwm instance */
#define FLEXPWM_IP_UNIQUESUB_COUNT             (FLEXPWM_IP_SUBMODULE_COUNT * FLEXPWM_IP_NUMCHANNELS_PER_SUBMODULE)

#define FLEXPWM_IP_SIGNED_REG_OFFSET            0x8000

#ifndef MCAL_ENABLE_USER_MODE_SUPPORT
    #if (STD_ON == FLEXPWM_IP_ENABLE_USER_MODE_SUPPORT)
        #error MCAL_ENABLE_USER_MODE_SUPPORT is not enabled. For running FLEXPWM in user mode the MCAL_ENABLE_USER_MODE_SUPPORT needs to be defined
    #endif
#endif

#if ((STD_ON == FLEXPWM_IP_ENABLE_USER_MODE_SUPPORT) && defined(MCAL_FLEXPWM_AE_REG_PROT_AVAILABLE))
    #if (STD_ON == MCAL_FLEXPWM_AE_REG_PROT_AVAILABLE)
        #define  FLEXPWM_IP_USER_ACCESS_ALLOWED_AVAILABLE     (STD_ON)
    #else
        #define  FLEXPWM_IP_USER_ACCESS_ALLOWED_AVAILABLE     (STD_OFF)
    #endif
#else
#define  FLEXPWM_IP_USER_ACCESS_ALLOWED_AVAILABLE     (STD_OFF)
#endif

[!IF "ecu:get('Pwm.FlexPwmAvailable') = 'true'"!]
    [!NOCODE!]
        [!LOOP "as:modconf('Pwm')[1]/PwmChannelConfigSet/FlexPwm/*"!]
            [!IF "(./FlexPwmFaultFunctionality = 'true') and (./../../../PwmGeneral/PwmNotificationSupported = 'true')"!]
                [!LOOP "./FlexPwmFaultChannelSettings/*"!]
                    [!IF "(./FlexPwmFaultInterruptEn = 'true')"!]
                        [!CODE!]
#define FLEXPWM_IP_FAULT_ISR_USED
                        [!ENDCODE!]
                        [!BREAK!]
                    [!ENDIF!]
                [!ENDLOOP!]
            [!ENDIF!]
        [!ENDLOOP!]

        [!LOOP "as:modconf('Pwm')[1]/PwmChannelConfigSet/FlexPwm/*"!]
            [!VAR "HwInstance" = "substring-after(./FlexPwmModule,'FlexPwm_')"!]
            [!LOOP "./FlexPwmSubModules/*"!]
                [!VAR "SubModule" = "substring-after(./FlexPwmSubModule,'SubModule_')"!]
                [!LOOP "./FlexPwmChannels/*"!]
                    [!IF "(./FlexPwmChInterrupt = 'FLEXPWM_IP_COMPARE_INT') and (./../../../../../../../PwmGeneral/PwmNotificationSupported = 'true')"!]
                        [!CODE!]
#define FLEXPWM_IP_INS_[!"$HwInstance"!]_SUBMOD_[!"$SubModule"!]_ISR_USED
                        [!ENDCODE!]
                        [!BREAK!]
                    [!ENDIF!]
                [!ENDLOOP!]
            [!ENDLOOP!] 
        [!ENDLOOP!]
    [!ENDNOCODE!]
[!ENDIF!]
/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/
[!IF "ecu:get('Pwm.FlexPwmAvailable') = 'true'"!]
[!CODE!]
/* Redefine FlexPwm_Type from header file to comply with coding guidelines */
typedef FLEXPWM_Type FlexPwm_Ip_HwAddrType;
[!ENDCODE!]
[!ENDIF!]

#ifdef __cplusplus
}
#endif

/** @} */

#endif /* FLEXPWM_IP_CFG_H */

[!ENDCODE!]
