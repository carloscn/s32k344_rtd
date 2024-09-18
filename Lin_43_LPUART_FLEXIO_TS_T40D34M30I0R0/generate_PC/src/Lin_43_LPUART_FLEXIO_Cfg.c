/*==================================================================================================
*   Project              : RTD AUTOSAR 4.7
*   Platform             : CORTEXM
*   Peripheral           : LPUART_FLEXIO
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
*   @file   Lin_Cfg.c
*   @implements Lin_Cfg.c_Artifact
*
*   @defgroup lin_driver LIN Driver
*   @addtogroup  lin_driver LIN Driver
*   @{
*/

#ifdef __cplusplus
extern "C"
{
#endif

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Lin_43_LPUART_FLEXIO_Cfg.h"
#include "Std_Types.h"
#if (LIN_43_LPUART_FLEXIO_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
#include "Dem.h"
#endif /* (LIN_43_LPUART_FLEXIO_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF) */

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/

#define LIN_43_LPUART_FLEXIO_CFG_VENDOR_ID_C                    43
#define LIN_43_LPUART_FLEXIO_CFG_AR_RELEASE_MAJOR_VERSION_C     4
#define LIN_43_LPUART_FLEXIO_CFG_AR_RELEASE_MINOR_VERSION_C     7
#define LIN_43_LPUART_FLEXIO_CFG_AR_RELEASE_REVISION_VERSION_C  0
#define LIN_43_LPUART_FLEXIO_CFG_SW_MAJOR_VERSION_C             3
#define LIN_43_LPUART_FLEXIO_CFG_SW_MINOR_VERSION_C             0
#define LIN_43_LPUART_FLEXIO_CFG_SW_PATCH_VERSION_C             0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
[!NOCODE!][!//
[!INCLUDE "Lin_VersionCheck_Src.m"!][!//
[!ENDNOCODE!][!//
#if (LIN_43_LPUART_FLEXIO_CFG_VENDOR_ID_C != LIN_43_LPUART_FLEXIO_CFG_VENDOR_ID)
    #error "Lin_43_LPUART_FLEXIO_Cfg.c and Lin_43_LPUART_FLEXIO_Cfg.h have different vendor ids"
#endif
/* Check if current file and Lin_43_LPUART_FLEXIO_Cfg header file are of the same Autosar version */
#if ((LIN_43_LPUART_FLEXIO_CFG_AR_RELEASE_MAJOR_VERSION_C    != LIN_43_LPUART_FLEXIO_CFG_AR_RELEASE_MAJOR_VERSION) || \
     (LIN_43_LPUART_FLEXIO_CFG_AR_RELEASE_MINOR_VERSION_C    != LIN_43_LPUART_FLEXIO_CFG_AR_RELEASE_MINOR_VERSION) || \
     (LIN_43_LPUART_FLEXIO_CFG_AR_RELEASE_REVISION_VERSION_C != LIN_43_LPUART_FLEXIO_CFG_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Lin_43_LPUART_FLEXIO_Cfg.c and Lin_43_LPUART_FLEXIO_Cfg.h are different"
#endif
/* Check if current file and Lin_43_LPUART_FLEXIO_Cfg header file are of the same Software version */
#if ((LIN_43_LPUART_FLEXIO_CFG_SW_MAJOR_VERSION_C != LIN_43_LPUART_FLEXIO_CFG_SW_MAJOR_VERSION) || \
     (LIN_43_LPUART_FLEXIO_CFG_SW_MINOR_VERSION_C != LIN_43_LPUART_FLEXIO_CFG_SW_MINOR_VERSION) || \
     (LIN_43_LPUART_FLEXIO_CFG_SW_PATCH_VERSION_C != LIN_43_LPUART_FLEXIO_CFG_SW_PATCH_VERSION) )
    #error "Software Version Numbers of Lin_43_LPUART_FLEXIO_Cfg.c and Lin_43_LPUART_FLEXIO_Cfg.h are different"
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK

    #if (STD_OFF == LIN_43_LPUART_FLEXIO_DISABLE_DEM_REPORT_ERROR_STATUS)
        /* Check if current file and Dem.h header file are of the same Autosar version */
        #if ((LIN_43_LPUART_FLEXIO_CFG_AR_RELEASE_MAJOR_VERSION_C != DEM_AR_RELEASE_MAJOR_VERSION) || \
             (LIN_43_LPUART_FLEXIO_CFG_AR_RELEASE_MINOR_VERSION_C != DEM_AR_RELEASE_MINOR_VERSION))
            #error "AutoSar Version Numbers of Lin_43_LPUART_FLEXIO_Cfg.c and Dem.h are different"
        #endif
    #endif /* STD_OFF == LIN_43_LPUART_FLEXIO_DISABLE_DEM_REPORT_ERROR_STATUS */
#endif

/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
*                                          LOCAL MACROS
==================================================================================================*/

/*==================================================================================================
*                                         LOCAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                         LOCAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                        GLOBAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                        GLOBAL VARIABLES
==================================================================================================*/
#define LIN_43_LPUART_FLEXIO_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Lin_43_LPUART_FLEXIO_MemMap.h"

[!NOCODE!]
[!CODE!]
#if (STD_OFF == LIN_43_LPUART_FLEXIO_DISABLE_DEM_REPORT_ERROR_STATUS)
/**
 * @brief   DEM error parameters
 */
const Mcal_DemErrorType  Lin_43_LPUART_FLEXIO_E_TimeoutCfg =
{
[!ENDCODE!]
[!VAR "LinDemErrorEnable" = "'false'"!]
[!IF "AutosarExt/LinDisableDemReportErrorStatus ='false'"!][!//
    [!IF "node:exists(LinDemEventParameterRefs)"!]
        [!VAR "LinDemErrorEnable" = "'true'"!]
    [!ENDIF!]
[!ENDIF!]
[!IF "$LinDemErrorEnable"!]
    [!IF "node:exists(LinDemEventParameterRefs/LIN_E_TIMEOUT)"!]
        [!IF "node:exists(node:value(LinDemEventParameterRefs/LIN_E_TIMEOUT))"!]
            [!CODE!]
    (uint32)STD_ON,
    DemConf_DemEventParameter_[!"node:name(node:ref(LinDemEventParameterRefs/LIN_E_TIMEOUT))"!]
            [!ENDCODE!]
        [!ELSE!]
            [!ERROR "Invalid reference for LIN_43_LPUART_FLEXIO_E_ERROR"!]
        [!ENDIF!]
    [!ELSE!]
        [!CODE!]
    (uint32)STD_OFF,
    0U
[!ENDCODE!]
    [!ENDIF!]
[!ELSE!]
    [!CODE!]
    (uint32)STD_OFF,
    0U
[!ENDCODE!]
[!ENDIF!]
[!CODE!]
};
#endif /* STD_OFF == LIN_43_LPUART_FLEXIO_DISABLE_DEM_REPORT_ERROR_STATUS */
[!ENDCODE!]
[!ENDNOCODE!]
#define LIN_43_LPUART_FLEXIO_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Lin_43_LPUART_FLEXIO_MemMap.h"

/*==================================================================================================
*                                    LOCAL FUNCTION PROTOTYPES
==================================================================================================*/

/*==================================================================================================
*                                         LOCAL FUNCTIONS
==================================================================================================*/

/*==================================================================================================
*                                        GLOBAL FUNCTIONS
==================================================================================================*/

#ifdef __cplusplus
}
#endif

/** @} */
