/*==================================================================================================
*   Project              : RTD AUTOSAR 4.7
*   Platform             : CORTEXM
*   Peripheral           : Swt
*   Dependencies         : none
*
*   Autosar Version      : 4.7.0
*   Autosar Revision     : ASR_REL_4_7_REV_0000
*   Autosar Conf.Variant :
*   SW Version           : 3.0.0
*   Build Version        : S32K3_RTD_3_0_0_D2303_ASR_REL_4_7_REV_0000_20230331
*
*   (c) Copyright 2020 - 2023 NXP Semiconductors
*   All Rights Reserved.
*
*   NXP Confidential. This software is owned or controlled by NXP and may only be
*   used strictly in accordance with the applicable license terms. By expressly
*   accepting such terms or by downloading, installing, activating and/or otherwise
*   using the software, you are agreeing that you have read, and that you agree to
*   comply with and are bound by, such license terms. If you do not agree to be
*   bound by the applicable license terms, then you may not retain, install,
*   activate or otherwise use the software.
==================================================================================================*/

#ifndef AEWDOG_IP_CFG_H
#define AEWDOG_IP_CFG_H

/**
*   @file
*
*   @addtogroup AEWDOG_ip_config AEWDOG IPL Configuration
*   @{
*/

#ifdef __cplusplus
extern "C"{
#endif


/*==================================================================================================
*                                          INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "StandardTypes.h"
[!NOCODE!][!//
[!INDENT "0"!]
[!FOR "i" = "0" TO "num:i(ecu:get('Wdg.Num.Of.Instances'))-1"!]
    [!IF "num:i($i) > 0"!]
        [!VAR "xPathModule" = "concat('ASPathDataOfSchema:/Wdg_43_Instance',$i,'_','TS_T40D34M30I0R0/Wdg')"!]
    [!ELSE!]
        [!VAR "xPathModule" = "concat('ASPathDataOfSchema:/','TS_T40D34M30I0R0/Wdg')"!]
    [!ENDIF!]
    [!IF "node:exists($xPathModule) and contains(ecu:list('Wdg.WdgInstance')[$i + 1], 'AEWDOG')"!]
        [!IF "var:defined('postBuildVariant')"!][!//
            [!LOOP "variant:all()"!][!//
                [!CODE!]#include "AeWdog_Ip_[!"text:toupper(.)"!]_PBcfg.h"
                [!ENDCODE!]
            [!ENDLOOP!]
        [!ELSE!]
                [!CODE!]#include "AeWdog_Ip_PBcfg.h"
                [!ENDCODE!]
        [!ENDIF!]
    [!ENDIF!]
[!ENDFOR!]
[!ENDINDENT!]
[!ENDNOCODE!][!//

/*==================================================================================================
*                                 SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define AEWDOG_IP_VENDOR_ID_CFG_H                    43
#define AEWDOG_IP_AR_RELEASE_MAJOR_VERSION_CFG_H     4
#define AEWDOG_IP_AR_RELEASE_MINOR_VERSION_CFG_H     7
#define AEWDOG_IP_AR_RELEASE_REVISION_VERSION_CFG_H  0
#define AEWDOG_IP_SW_MAJOR_VERSION_CFG_H             3
#define AEWDOG_IP_SW_MINOR_VERSION_CFG_H             0
#define AEWDOG_IP_SW_PATCH_VERSION_CFG_H             0

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Checks against StandardTypes.h */
    #if ((AEWDOG_IP_AR_RELEASE_MAJOR_VERSION_CFG_H != STD_AR_RELEASE_MAJOR_VERSION) || \
         (AEWDOG_IP_AR_RELEASE_MINOR_VERSION_CFG_H != STD_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of AeWdog_Ip_Cfg.h and StandardTypes.h are different"
    #endif
#endif

[!FOR "i" = "0" TO "num:i(ecu:get('Wdg.Num.Of.Instances'))-1"!][!//
[!IF "num:i($i) > 0"!][!//
[!VAR "xPathModule" = "concat('ASPathDataOfSchema:/Wdg_43_Instance',$i,'_','TS_T40D34M30I0R0/Wdg')"!][!//
[!ELSE!][!//
[!VAR "xPathModule" = "concat('ASPathDataOfSchema:/','TS_T40D34M30I0R0/Wdg')"!][!//
[!ENDIF!][!//
[!IF "node:exists($xPathModule) and contains(ecu:list('Wdg.WdgInstance')[$i + 1], 'AEWDOG')"!][!//
[!IF "var:defined('postBuildVariant')"!][!//
[!LOOP "variant:all()"!][!//
#if (AEWDOG_IP_VENDOR_ID_CFG_H != AEWDOG_IP_PBCFG_VENDOR_ID)
    #error "AeWdog_Ip_Cfg.h and AeWdog_Ip_[!"."!]_PBcfg.h have different vendor IDs"
#endif

#if ((AEWDOG_IP_AR_RELEASE_MAJOR_VERSION_CFG_H != AEWDOG_IP_PBCFG_AR_RELEASE_MAJOR_VERSION) || \
     (AEWDOG_IP_AR_RELEASE_MINOR_VERSION_CFG_H != AEWDOG_IP_PBCFG_AR_RELEASE_MINOR_VERSION) || \
     (AEWDOG_IP_AR_RELEASE_REVISION_VERSION_CFG_H != AEWDOG_IP_PBCFG_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of AeWdog_Ip_Cfg.h and AeWdog_Ip_[!"."!]_PBcfg.h are different"
#endif

#if ((AEWDOG_IP_SW_MAJOR_VERSION_CFG_H != AEWDOG_IP_PBCFG_SW_MAJOR_VERSION) || \
     (AEWDOG_IP_SW_MINOR_VERSION_CFG_H != AEWDOG_IP_PBCFG_SW_MINOR_VERSION) || \
     (AEWDOG_IP_SW_PATCH_VERSION_CFG_H != AEWDOG_IP_PBCFG_SW_PATCH_VERSION))
    #error "Software Version Numbers of AeWdog_Ip_Cfg.h and AeWdog_Ip_[!"."!]_PBcfg.h are different"
#endif
[!ENDLOOP!][!//
[!ELSE!][!//
#if (AEWDOG_IP_VENDOR_ID_CFG_H != AEWDOG_IP_PBCFG_VENDOR_ID)
    #error "AeWdog_Ip_Cfg.h and AeWdog_Ip_PBcfg.h have different vendor IDs"
#endif

#if ((AEWDOG_IP_AR_RELEASE_MAJOR_VERSION_CFG_H != AEWDOG_IP_PBCFG_AR_RELEASE_MAJOR_VERSION) || \
     (AEWDOG_IP_AR_RELEASE_MINOR_VERSION_CFG_H != AEWDOG_IP_PBCFG_AR_RELEASE_MINOR_VERSION) || \
     (AEWDOG_IP_AR_RELEASE_REVISION_VERSION_CFG_H != AEWDOG_IP_PBCFG_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of AeWdog_Ip_Cfg.h and AeWdog_Ip_PBcfg.h are different"
#endif

#if ((AEWDOG_IP_SW_MAJOR_VERSION_CFG_H != AEWDOG_IP_PBCFG_SW_MAJOR_VERSION) || \
     (AEWDOG_IP_SW_MINOR_VERSION_CFG_H != AEWDOG_IP_PBCFG_SW_MINOR_VERSION) || \
     (AEWDOG_IP_SW_PATCH_VERSION_CFG_H != AEWDOG_IP_PBCFG_SW_PATCH_VERSION))
    #error "Software Version Numbers of AeWdog_Ip_Cfg.h and AeWdog_Ip_PBcfg.h are different"
#endif
[!ENDIF!][!//
[!ENDIF!][!//
[!ENDFOR!][!//
/*==================================================================================================
*                                            CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/

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

/** @} */

#endif /* AEWDOG_IP_CFG_H */

