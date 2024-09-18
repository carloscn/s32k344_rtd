/*==================================================================================================
*   Project              : RTD AUTOSAR 4.7
*   Platform             : CORTEXM
*   Peripheral           : AE
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

#ifndef AELINPHY_LINTRCV_IP_CFG_H
#define AELINPHY_LINTRCV_IP_CFG_H

/**
*   @file
*
*   @addtogroup AELINPHY_LINTRCV_IP
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
* 4) user callback header files
==================================================================================================*/
#include "Mcal.h"
#include "AeLinPhy_LinTrcv_Ip_Types.h"

[!NOCODE!][!// Include specific header file
[!IF "node:exists(as:modconf("Resource")[1]/ResourceGeneral/ResourceSubderivative)"!][!//
    [!VAR "GetDerivative" = "as:modconf("Resource")[1]/ResourceGeneral/ResourceSubderivative"!][!//
    [!VAR "Derivative" = "text:toupper(substring-before($GetDerivative, '_'))"!][!//

    [!IF "contains($Derivative, 'S32M24')"!][!//
        [!VAR "Derivative" = "'S32M24x'"!][!//
    [!ELSEIF "contains($Derivative, 'S32M27')"!][!//
        [!VAR "Derivative" = "'S32M27x'"!][!//
    [!ENDIF!][!//
[!CODE!][!WS "0"!]#include "[!"$Derivative"!]_AEC_AE.h"[!CR!][!ENDCODE!][!//
[!ENDIF!][!//
[!ENDNOCODE!][!//

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/

#define AELINPHY_LINTRCV_IP_CFG_VENDOR_ID                    43
#define AELINPHY_LINTRCV_IP_CFG_AR_RELEASE_MAJOR_VERSION     4
#define AELINPHY_LINTRCV_IP_CFG_AR_RELEASE_MINOR_VERSION     7
#define AELINPHY_LINTRCV_IP_CFG_AR_RELEASE_REVISION_VERSION  0
#define AELINPHY_LINTRCV_IP_CFG_SW_MAJOR_VERSION             3
#define AELINPHY_LINTRCV_IP_CFG_SW_MINOR_VERSION             0
#define AELINPHY_LINTRCV_IP_CFG_SW_PATCH_VERSION             0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Checks against AeLinPhy_LinTrcv_Ip_Types.h */

#if (AELINPHY_LINTRCV_IP_CFG_VENDOR_ID != AELINPHY_LINTRCV_IP_TYPES_VENDOR_ID)
    #error "AeLinPhy_LinTrcv_Ip_Cfg.h and AeLinPhy_LinTrcv_Ip_Types.h have different vendor ids"
#endif
#if ((AELINPHY_LINTRCV_IP_CFG_AR_RELEASE_MAJOR_VERSION    != AELINPHY_LINTRCV_IP_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (AELINPHY_LINTRCV_IP_CFG_AR_RELEASE_MINOR_VERSION    != AELINPHY_LINTRCV_IP_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (AELINPHY_LINTRCV_IP_CFG_AR_RELEASE_REVISION_VERSION != AELINPHY_LINTRCV_IP_TYPES_AR_RELEASE_REVISION_VERSION) \
    )
     #error "AUTOSAR Version Numbers of AeLinPhy_LinTrcv_Ip_Cfg.h and AeLinPhy_LinTrcv_Ip_Types.h are different"
#endif
#if ((AELINPHY_LINTRCV_IP_CFG_SW_MAJOR_VERSION != AELINPHY_LINTRCV_IP_TYPES_SW_MAJOR_VERSION) || \
     (AELINPHY_LINTRCV_IP_CFG_SW_MINOR_VERSION != AELINPHY_LINTRCV_IP_TYPES_SW_MINOR_VERSION) || \
     (AELINPHY_LINTRCV_IP_CFG_SW_PATCH_VERSION != AELINPHY_LINTRCV_IP_TYPES_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of AeLinPhy_LinTrcv_Ip_Cfg.h and AeLinPhy_LinTrcv_Ip_Types.h are different"
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if current file and Mcal.h header file are of the same Autosar version */
    #if ((AELINPHY_LINTRCV_IP_CFG_AR_RELEASE_MAJOR_VERSION != MCAL_AR_RELEASE_MAJOR_VERSION) || \
         (AELINPHY_LINTRCV_IP_CFG_AR_RELEASE_MINOR_VERSION != MCAL_AR_RELEASE_MINOR_VERSION) \
        )
        #error "AUTOSAR Version Numbers of AeLinPhy_LinTrcv_Ip_Cfg.h and Mcal.h are different"
    #endif
#endif /* DISABLE_MCAL_INTERMODULE_ASR_CHECK */

/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/
[!NOCODE!]
[!CODE!]#define AELINPHY_LINTRCV_IP_CONFIG_EXT \[!CR!][!ENDCODE!]
[!LOOP "LinTrcvChannel/*"!][!//
    [!CODE!]
    extern const AeLinPhy_LinTrcv_Ip_UserConfigType AeLinPhy_LinTrcv_Ip_pHwConfigPB_[!"LinTrcvChannelId"!]; \
    [!ENDCODE!]
[!ENDLOOP!]
[!ENDNOCODE!]

/**
* @brief   Switches the Development Error Detection and Notification ON or OFF.
*
*
*/
#define AELINPHY_LINTRCV_IP_DEV_ERROR_DETECT               ([!IF "LinTrcvGeneral/LinTrcvDevErrorDetect"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!]) /*!< Development error detection */


#if (AELINPHY_LINTRCV_IP_DEV_ERROR_DETECT == STD_ON)
    #define AELINPHY_LINTRCV_IP_DEV_ASSERT(x)      DevAssert(x)
#endif /* (AELINPHY_LINTRCV_IP_DEV_ERROR_DETECT == STD_ON) */
/*==================================================================================================
*                                            ENUMS
==================================================================================================*/

/*==================================================================================================
*                               STRUCTURES AND OTHER TYPEDEFS
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

#endif  /* AELINPHY_LINTRCV_IP_CFG_H */
