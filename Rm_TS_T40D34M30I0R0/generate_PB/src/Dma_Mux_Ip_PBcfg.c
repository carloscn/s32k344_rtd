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

/**
*   @file Dma_Mux_Ip[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg.c
*
*   @addtogroup DMA_MUX_IP DMA_MUX IPV Driver
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
#include "Dma_Mux_Ip_Cfg.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define RM_DMA_MUX_IP[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_VENDOR_ID_C                     43
#define RM_DMA_MUX_IP[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_AR_RELEASE_MAJOR_VERSION_C      4
#define RM_DMA_MUX_IP[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_AR_RELEASE_MINOR_VERSION_C      7
#define RM_DMA_MUX_IP[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_AR_RELEASE_REVISION_VERSION_C   0
#define RM_DMA_MUX_IP[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_SW_MAJOR_VERSION_C              3
#define RM_DMA_MUX_IP[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_SW_MINOR_VERSION_C              0
#define RM_DMA_MUX_IP[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_SW_PATCH_VERSION_C              0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Checks against Dma_Mux_Ip_Cfg.h */
#if (RM_DMA_MUX_IP[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_VENDOR_ID_C != RM_DMA_MUX_IP_CFG_VENDOR_ID)
    #error "Dma_Mux_Ip[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg.c and Dma_Mux_Ip_Cfg.h have different vendor ids"
#endif
#if ((RM_DMA_MUX_IP[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_AR_RELEASE_MAJOR_VERSION_C    != RM_DMA_MUX_IP_CFG_AR_RELEASE_MAJOR_VERSION) || \
     (RM_DMA_MUX_IP[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_AR_RELEASE_MINOR_VERSION_C    != RM_DMA_MUX_IP_CFG_AR_RELEASE_MINOR_VERSION) || \
     (RM_DMA_MUX_IP[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_AR_RELEASE_REVISION_VERSION_C != RM_DMA_MUX_IP_CFG_AR_RELEASE_REVISION_VERSION) \
    )
     #error "AUTOSAR Version Numbers of Dma_Mux_Ip[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg.c and Dma_Mux_Ip_Cfg.h are different"
#endif
#if ((RM_DMA_MUX_IP[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_SW_MAJOR_VERSION_C != RM_DMA_MUX_IP_CFG_SW_MAJOR_VERSION) || \
     (RM_DMA_MUX_IP[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_SW_MINOR_VERSION_C != RM_DMA_MUX_IP_CFG_SW_MINOR_VERSION) || \
     (RM_DMA_MUX_IP[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_SW_PATCH_VERSION_C != RM_DMA_MUX_IP_CFG_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Dma_Mux_Ip[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg.c and Dma_Mux_Ip_Cfg.h are different"
#endif
/*==================================================================================================
                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
                                        LOCAL MACROS
==================================================================================================*/
[!NOCODE!]
[!VAR "DMAMuxMask" = "'CHCFG'"!]
[!ENDNOCODE!]
#define DMAMUX_CHANNEL_CFG_ENBL_MASK		DMAMUX_[!"$DMAMuxMask"!]_ENBL_MASK
#define DMAMUX_CHANNEL_CFG_TRIG				DMAMUX_[!"$DMAMuxMask"!]_TRIG
/*==================================================================================================
                                       LOCAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
                                       LOCAL VARIABLES
==================================================================================================*/

/*==================================================================================================
                                       GLOBAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
                                       GLOBAL VARIABLES
==================================================================================================*/
#define RM_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Rm_MemMap.h"

[!NOCODE!]
[!MACRO "Dma_MuxGetInstanceNumber"!][!//
[!NOCODE!]

[!VAR "currentDMAHwInstance" = "./Dma_Mux_HwInstance"!]
[!VAR "currentChannel" = "./Dma_Mux_HwChannel"!]

[!FOR "i" = "0" TO "num:i(count(ecu:list('Rm.Dma_Mux.Instance.List')))-1"!][!//
    [!IF "ecu:get(text:replace('Rm.Dma_Mux.DMA_MUX_Index.DmaInstance','Index', num:i($i))) = $currentDMAHwInstance"!][!//
        [!IF "contains(ecu:list(text:replace('Rm.Dma_Mux.DMA_MUX_Index.DmaChannel.List','Index', num:i($i))), $currentChannel)"!][!//
            [!VAR "currentMuxInstance" = "ecu:list('Rm.Dma_Mux.Instance.List')[position() = ($i+1)]"!]
            [!VAR "currentSource" = "(node:value(concat("./Dma_Mux_Source", num:i($i))))"!]
            [!VAR "currentChannelNumber" = "num:i(substring-after($currentChannel, 'DMA_CHANNEL_'))"!]
            [!// VAR "deviationNumber" : deviation between the DMA channel number and the corresponding CHCFG register number
            [!VAR "deviationNumber" = "num:i(substring-after(ecu:list(text:replace('Rm.Dma_Mux.DMA_MUX_Index.DmaChannel.List','Index', num:i($i)))[position() = 1], 'DMA_CHANNEL_'))"!]
            [!VAR "currentCHCFGNumber" = "num:i($currentChannelNumber - $deviationNumber)"!]
            [!BREAK!]
        [!ENDIF!]
    [!ENDIF!]
    [!//ELSE no happen because it will check in interface
[!ENDFOR!]

[!ENDNOCODE!][!//
[!ENDMACRO!][!//

    [!IF "RmGeneral/RmEnableDmaMuxSupport"!] /* System settings */
[!CODE!]
[!SELECT "RmConfigSet/Dma_Mux_Configuration"!][!//
[!VAR "comma" = "num:i(1)"!][!//
[!VAR "ChannelCount" = "num:i(count(Dma_Mux_Module_Config/*))"!][!//
static const Dma_Mux_Ip_ChannelConfigType Dma_Mux_Channel_Config[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][[!"$ChannelCount"!]] =
{
[!LOOP "./Dma_Mux_Module_Config/*"!][!//
    {[!CALL "Dma_MuxGetInstanceNumber"!]
        [!"$currentMuxInstance"!],
        [!"$currentCHCFGNumber"!]U,
        ([!"$currentSource"!] | DMAMUX_CHANNEL_CFG_ENBL_MASK | DMAMUX_CHANNEL_CFG_TRIG([!IF "./Dma_Mux_Enable_Trigger"!]1U[!ELSE!]0U[!ENDIF!]))
    }[!IF "(num:i($comma))<($ChannelCount)"!],[!CR!][!ENDIF!][!VAR "comma"="$comma + 1"!][!//
[!ENDLOOP!]
};

const Dma_Mux_Ip_ConfigType Dma_Mux_Config[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!] =
{
    [!"$ChannelCount"!]U,
    Dma_Mux_Channel_Config[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]
};
[!ENDSELECT!][!//

[!ENDCODE!][!//
    [!ENDIF!][!//
[!ENDNOCODE!][!//
#define RM_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Rm_MemMap.h"
/*==================================================================================================
                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/

/*==================================================================================================
                                       LOCAL FUNCTIONS
==================================================================================================*/

/*==================================================================================================
                                       GLOBAL FUNCTIONS
==================================================================================================*/

#ifdef __cplusplus
}
#endif

/** @} */

