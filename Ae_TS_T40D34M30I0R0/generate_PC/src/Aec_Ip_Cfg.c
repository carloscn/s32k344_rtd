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

#ifndef AEC_IP_CFG_C
#define AEC_IP_CFG_C

/**
*   @file
*
*   @addtogroup AEC_DRIVER_CONFIGURATION AEC Driver Configuration
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
#include "Aec_Ip_Types.h"
#include "Aec_Ip_Cfg.h"
#include "Mcal.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define AEC_IP_CFG_VENDOR_ID_C                     43
#define AEC_IP_CFG_AR_RELEASE_MAJOR_VERSION_C      4
#define AEC_IP_CFG_AR_RELEASE_MINOR_VERSION_C      7
#define AEC_IP_CFG_AR_RELEASE_REVISION_VERSION_C   0
#define AEC_IP_CFG_SW_MAJOR_VERSION_C              3
#define AEC_IP_CFG_SW_MINOR_VERSION_C              0
#define AEC_IP_CFG_SW_PATCH_VERSION_C              0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Checks against Aec_Ip_Types.h */
#if (AEC_IP_CFG_VENDOR_ID_C != AEC_IP_TYPES_VENDOR_ID)
    #error "Aec_Ip_Cfg.c and Aec_Ip_Types.h have different vendor ids"
#endif
#if ((AEC_IP_CFG_AR_RELEASE_MAJOR_VERSION_C    != AEC_IP_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (AEC_IP_CFG_AR_RELEASE_MINOR_VERSION_C    != AEC_IP_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (AEC_IP_CFG_AR_RELEASE_REVISION_VERSION_C != AEC_IP_TYPES_AR_RELEASE_REVISION_VERSION))
     #error "AUTOSAR Version Numbers of Aec_Ip_Cfg.c and Aec_Ip_Types.h are different"
#endif
#if ((AEC_IP_CFG_SW_MAJOR_VERSION_C != AEC_IP_TYPES_SW_MAJOR_VERSION) || \
     (AEC_IP_CFG_SW_MINOR_VERSION_C != AEC_IP_TYPES_SW_MINOR_VERSION) || \
     (AEC_IP_CFG_SW_PATCH_VERSION_C != AEC_IP_TYPES_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Aec_Ip_Cfg.c and Aec_Ip_Types.h are different"
#endif

/* Checks against Aec_Ip_Cfg.h */
#if (AEC_IP_CFG_VENDOR_ID_C != AEC_IP_CFG_VENDOR_ID)
    #error "Aec_Ip_Cfg.c and Aec_Ip_Cfg.h have different vendor ids"
#endif
#if ((AEC_IP_CFG_AR_RELEASE_MAJOR_VERSION_C    != AEC_IP_CFG_AR_RELEASE_MAJOR_VERSION) || \
     (AEC_IP_CFG_AR_RELEASE_MINOR_VERSION_C    != AEC_IP_CFG_AR_RELEASE_MINOR_VERSION) || \
     (AEC_IP_CFG_AR_RELEASE_REVISION_VERSION_C != AEC_IP_CFG_AR_RELEASE_REVISION_VERSION))
     #error "AUTOSAR Version Numbers of Aec_Ip_Cfg.c and Aec_Ip_Cfg.h are different"
#endif
#if ((AEC_IP_CFG_SW_MAJOR_VERSION_C != AEC_IP_CFG_SW_MAJOR_VERSION) || \
     (AEC_IP_CFG_SW_MINOR_VERSION_C != AEC_IP_CFG_SW_MINOR_VERSION) || \
     (AEC_IP_CFG_SW_PATCH_VERSION_C != AEC_IP_CFG_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Aec_Ip_Cfg.c and Aec_Ip_Cfg.h are different"
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Checks against Mcal.h */
    #if ((AEC_IP_CFG_AR_RELEASE_MAJOR_VERSION_C != MCAL_AR_RELEASE_MAJOR_VERSION) || \
         (AEC_IP_CFG_AR_RELEASE_MINOR_VERSION_C != MCAL_AR_RELEASE_MINOR_VERSION))
        #error "AUTOSAR Version Numbers of Aec_Ip_Cfg.c and Mcal.h are different"
    #endif
#endif

/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/


/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/

/*==================================================================================================
*                                      LOCAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      LOCAL VARIABLES
==================================================================================================*/
#define AE_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Ae_MemMap.h"

[!MACRO "GetEventsMask"!][!//
[!NOCODE!]
    [!VAR "EventsMask"     = "'0U'"!]
    [!LOOP "AeIrqConfig/AeIntConfig/*"!]
        [!IF "(node:current()/@index) < 11"!]
        [!IF "node:value(AeIsrEnabled) = 'true'"!]
            [!VAR "EventEn" = "concat('AEC_AE_EVENTS_ENABLE_', node:value(AeIntName), '_EN_MASK')"!]
            [!VAR "EventsMask" = "concat($EventsMask, ' | ', $EventEn)"!]
        [!ENDIF!]
        [!ENDIF!]
    [!ENDLOOP!]

    [!CODE!][!"$EventsMask"!][!ENDCODE!]
[!ENDNOCODE!][!//
[!ENDMACRO!][!//

[!MACRO "GetFaultsMask"!][!//
[!NOCODE!]
    [!VAR "FaultsMask"     = "'0U'"!]
    [!LOOP "AeIrqConfig/AeIntConfig/*"!]
        [!IF "(node:current()/@index) > 10"!]
        [!IF "node:value(AeIsrEnabled) = 'true'"!]
            [!VAR "FaultsEn" = "concat('AEC_AE_FAULTS_ENABLE_', node:value(AeIntName), '_EN_MASK')"!]
            [!VAR "FaultsMask" = "concat($FaultsMask, ' | ', $FaultsEn)"!]
        [!ENDIF!]
        [!ENDIF!]
    [!ENDLOOP!]

    [!CODE!][!"$FaultsMask"!][!ENDCODE!]
[!ENDNOCODE!][!//
[!ENDMACRO!][!//

[!CODE!]
/* List of configurations for routing interrupts */
static const Aec_Ip_IntRouteConfigType aIntRouteConfig[] =
{
[!ENDCODE!]
[!NOCODE!]
[!LOOP "AeIrqConfig/AeIntConfig/*"!]
    [!IF "(node:value(AeIntHandler) = 'NULL_PTR') or (node:value(AeIntHandler) = 'undefined_handler')"!]
        [!VAR "AeHandler" = "'NULL_PTR'"!]
    [!ELSE!]
        [!VAR "AeHandler" = "node:value(AeIntHandler)"!]
    [!ENDIF!]
	[!IF "(node:current()/@index) < 11"!]
		[!VAR "AeName" = "concat('AEC_AE_EVENTS_STATUS_', node:value(AeIntName), '_FL_MASK')"!]
	[!ELSE!]
		[!VAR "AeName" = "concat('AEC_AE_FAULTS_STATUS_', node:value(AeIntName), '_FL_MASK')"!]
	[!ENDIF!]
    [!CODE!]    
    { [!"$AeName"!], [!"AeIsrPriority"!]U, [!"$AeHandler"!]},
    [!ENDCODE!]
[!ENDLOOP!]
[!ENDNOCODE!]
[!CODE!]};[!ENDCODE!]

#define AE_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Ae_MemMap.h"
/*==================================================================================================
*                                      GLOBAL VARIABLES
==================================================================================================*/
#define AE_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Ae_MemMap.h"

[!CODE!]
/* Configuration structure for routing interrupt */
const Aec_Ip_GlobalRouteConfigType Aec_intRouteConfig =
{
    (uint16)([!CALL "GetEventsMask"!]),
    (uint16)([!CALL "GetFaultsMask"!]),
    aIntRouteConfig
};
[!ENDCODE!]

#define AE_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Ae_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */

#endif /* AEC_IP_CFG_C */
