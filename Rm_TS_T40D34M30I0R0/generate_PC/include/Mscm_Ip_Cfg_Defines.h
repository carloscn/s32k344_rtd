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

#ifndef MSCM_IP_CFG_DEFINES_H
#define MSCM_IP_CFG_DEFINES_H

/**
*   @file Mscm_Ip_Cfg_Defines.h
*
*   @addtogroup MSCM_IP MSCM IPV Driver
*   @{
*/

#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
                                         INCLUDE FILES
==================================================================================================*/
/**
 * Include specific header file
 */
#include "StandardTypes.h"
#include "[!"ecu:get('Rm.Common.Header.List')"!]_MSCM.h"
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define RM_MSCM_IP_CFG_DEFINES_VENDOR_ID                          43
#define RM_MSCM_IP_CFG_DEFINES_AR_RELEASE_MAJOR_VERSION           4
#define RM_MSCM_IP_CFG_DEFINES_AR_RELEASE_MINOR_VERSION           7
#define RM_MSCM_IP_CFG_DEFINES_AR_RELEASE_REVISION_VERSION        0
#define RM_MSCM_IP_CFG_DEFINES_SW_MAJOR_VERSION                   3
#define RM_MSCM_IP_CFG_DEFINES_SW_MINOR_VERSION                   0
#define RM_MSCM_IP_CFG_DEFINES_SW_PATCH_VERSION                   0
/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/
/** @brief    Core Mask to write MSCM Register */
#define MSCM_IP_CORE_MASK						([!"num:i(ecu:get('Rm.MSCM.coreMask'))"!]U)
/** @brief    Development error checking */
#define MSCM_IP_DEV_ERROR_DETECT				([!IF "RmConfigSet/Mscm_Configuration/MscmDevErrorDetect"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])
[!IF "RmGeneral/RmEnableUserModeSupport"!][!//

/** @brief    User mode support          */
#define MSCM_IP_ENABLE_USER_MODE_SUPPORT
#ifndef MCAL_ENABLE_USER_MODE_SUPPORT
    #ifdef MSCM_IP_ENABLE_USER_MODE_SUPPORT
        #error "MCAL_ENABLE_USER_MODE_SUPPORT is not enabled. For running MSCM in user mode the MCAL_ENABLE_USER_MODE_SUPPORT needs to be defined"
    #endif /* (ifdef MSCM_IP_ENABLE_USER_MODE_SUPPORT) */
#endif /* ifndef MCAL_ENABLE_USER_MODE_SUPPORT */
[!ENDIF!][!//
[!VAR "Space" 				= "'                                                			'"!][!//
[!VAR "sumIRQNumber" 		= "count(ecu:list('Rm.MSCM.irqs.Name.List'))"!][!// Total IRQ Number
[!VAR "MSCM_SPIStartIdx" 	= "num:i(1)"!][!// Start index of MSCM IRQ Support
[!VAR "sumSPINumber" = "num:i($sumIRQNumber - $MSCM_SPIStartIdx + 1)"!][!// Calculate sum of SPI Number
/** @brief		Last implemented interrupt routing */
#define MSCM_IP_SPI_MAX							([!"ecu:list('Rm.MSCM.spiNumber.List')[position()=$sumSPINumber]"!]U)
/** @brief		Number of SPI Routing Support */
#define MSCM_IP_SPI_COUNT						([!"$sumSPINumber"!]U)

/** @brief		SPI Number Configuration */
[!FOR "i" = "$MSCM_SPIStartIdx" TO "$sumIRQNumber"!][!//
[!VAR "IRQName" = "ecu:list('Rm.MSCM.irqs.Name.List')[position() = $i]"!][!//
[!VAR "SPIIdx"  = "$i - $MSCM_SPIStartIdx + 1"!][!//
#define [!"$IRQName"!][!"substring($Space,string-length($IRQName))"!]([!"ecu:list('Rm.MSCM.spiNumber.List')[position() = $SPIIdx]"!]U)
[!ENDFOR!][!//

#ifdef __cplusplus
}
#endif

/** @} */

#endif /* MSCM_IP_CFG_DEFINES_H */

