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

#ifndef DMA_MUX_IP_CFG_DEFINES_H
#define DMA_MUX_IP_CFG_DEFINES_H

/**
*   @file Dma_Mux_Ip_CfgDefines.h
*
*   @addtogroup DMA_MUX_IP DMA_MUX IPV Driver
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
[!IF "RmGeneral/RmEnableDmaMuxSupport"!][!//
#include "[!"ecu:get('Rm.Common.Header.List')"!]_DMAMUX.h"
[!IF "contains(as:modconf("Resource")[1]/ResourceGeneral/ResourceSubderivative, 's32z27')"!][!//
#include "[!"ecu:get('Rm.Common.Header.List')"!]_CE_DMAMUX.h"
[!ENDIF!][!// s32z27
[!ENDIF!][!// RmEnableDmaMuxSupport

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define RM_DMA_MUX_IP_CFG_DEFINES_VENDOR_ID                    43
#define RM_DMA_MUX_IP_CFG_DEFINES_AR_RELEASE_MAJOR_VERSION     4
#define RM_DMA_MUX_IP_CFG_DEFINES_AR_RELEASE_MINOR_VERSION     7
#define RM_DMA_MUX_IP_CFG_DEFINES_AR_RELEASE_REVISION_VERSION  0
#define RM_DMA_MUX_IP_CFG_DEFINES_SW_MAJOR_VERSION             3
#define RM_DMA_MUX_IP_CFG_DEFINES_SW_MINOR_VERSION             0
#define RM_DMA_MUX_IP_CFG_DEFINES_SW_PATCH_VERSION             0


/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/

#define RM_IP_ENABLE_DMA_MUX                ([!IF "RmGeneral/RmEnableDmaMuxSupport"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])
/** @brief    Development error checking */
#define DMA_MUX_IP_DEV_ERROR_DETECT         ([!IF "RmConfigSet/Dma_Mux_Configuration/Dma_Mux_DevErrorDetect"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

[!IF "RmGeneral/RmEnableDmaMuxSupport"!][!//
[!IF "RmGeneral/RmEnableUserModeSupport"!][!//
/** @brief    User mode support          */
#define DMA_MUX_IP_ENABLE_USER_MODE_SUPPORT
#ifndef MCAL_ENABLE_USER_MODE_SUPPORT
    #ifdef DMA_MUX_IP_ENABLE_USER_MODE_SUPPORT
        #error "MCAL_ENABLE_USER_MODE_SUPPORT is not enabled. For running DMA_MUX in user mode the MCAL_ENABLE_USER_MODE_SUPPORT needs to be defined"
    #endif /* (ifdef DMA_MUX_IP_ENABLE_USER_MODE_SUPPORT) */
#endif /* ifndef MCAL_ENABLE_USER_MODE_SUPPORT */
[!ELSE!][!//
[!ENDIF!][!//

#define DMA_MUX_IP_INSTANCE_COUNT			([!"num:i(count(ecu:list('Rm.Dma_Mux.Instance.List')))"!]UL)
#define DMA_MUX_IP_INSTANCE_BASE_PTRS		{[!"ecu:get('Rm.Dma_Mux.basePtr.List')"!]}
#define DMA_MUX_IP_GATE_OFFSET(x)           ((x) ^ ((uint8)[!"ecu:get('Rm.Dma_Mux.ChannelOffset')"!]UL))

[!VAR "Space1" = "'                                   '"!][!//
[!FOR "i" = "1" TO "num:i(count(ecu:list('Rm.Dma_Mux.Instance.List')))"!][!//
[!VAR "DmaMuxInstance" = "ecu:list('Rm.Dma_Mux.Instance.List')[position() = $i]"!][!//
#define [!"$DmaMuxInstance"!][!"substring($Space1,string-length($DmaMuxInstance))"!]([!"num:i($i - 1)"!]U)
[!ENDFOR!]

[!VAR "Space" = "'                                                              '"!][!//
[!FOR "counter" = "0" TO "num:i(count(ecu:list('Rm.Dma_Mux.Instance.List')))-1"!][!//
/* Sources of [!"ecu:list('Rm.Dma_Mux.Instance.List')[position()=$counter+1]"!] */
[!VAR "SourceListName" = "text:replace('Rm.Dma_Mux.DMA_MUX_Instance.Source.List','Instance',$counter)"!][!//
[!VAR "SourceListNumber" = "text:replace('Rm.Dma_Mux.DMA_MUX_Instance.SourceNumber.List','Instance',$counter)"!][!//
[!VAR "Maxcount" = "num:i(count(ecu:list($SourceListName)))"!][!//
[!FOR "i" = "1" TO "$Maxcount"!][!//
[!VAR "SourceName" = "ecu:list($SourceListName)[position() = $i]"!][!//
[!VAR "SourceNumber" = "ecu:list($SourceListNumber)[position() = $i]"!][!//
#define [!"$SourceName"!][!"substring($Space,string-length($SourceName))"!]([!"num:i($SourceNumber)"!]U)
[!ENDFOR!]
[!ENDFOR!][!//
[!ENDIF!][!//
#ifdef __cplusplus
}
#endif

/** @} */

#endif /* DMA_MUX_IP_CFG_DEFINES_H */

