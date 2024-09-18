/*==================================================================================================
*   Project              : RTD AUTOSAR 4.7
*   Platform             : CORTEXM
*   Peripheral           : SIUL2
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
*   @file    Igf_Port_Ip_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBcfg.c
*
*   @addtogroup Port_CFG
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
#include "Igf_Port_Ip.h"

/*==================================================================================================
*                                 SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define IGF_PORT_IP_VENDOR_ID_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_C                       43
#define IGF_PORT_IP_AR_RELEASE_MAJOR_VERSION_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_C        4
#define IGF_PORT_IP_AR_RELEASE_MINOR_VERSION_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_C        7
#define IGF_PORT_IP_AR_RELEASE_REVISION_VERSION_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_C     0
#define IGF_PORT_IP_SW_MAJOR_VERSION_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_C                3
#define IGF_PORT_IP_SW_MINOR_VERSION_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_C                0
#define IGF_PORT_IP_SW_PATCH_VERSION_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_C                0

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/
/* Check if Igf_Port_Ip_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBcfg.c and Igf_Port_Ip.h are of the same vendor */
#if (IGF_PORT_IP_VENDOR_ID_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_C != IGF_PORT_IP_VENDOR_ID_H)
    #error "Igf_Port_Ip_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBcfg.c and Igf_Port_Ip.h have different vendor ids"
#endif
/* Check if Igf_Port_Ip_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBcfg.c and Igf_Port_Ip.h are of the same Autosar version */
#if ((IGF_PORT_IP_AR_RELEASE_MAJOR_VERSION_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_C    != IGF_PORT_IP_AR_RELEASE_MAJOR_VERSION_H) || \
     (IGF_PORT_IP_AR_RELEASE_MINOR_VERSION_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_C    != IGF_PORT_IP_AR_RELEASE_MINOR_VERSION_H) || \
     (IGF_PORT_IP_AR_RELEASE_REVISION_VERSION_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_C != IGF_PORT_IP_AR_RELEASE_REVISION_VERSION_H) \
    )
    #error "AutoSar Version Numbers of Igf_Port_Ip_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBcfg.c and Igf_Port_Ip.h are different"
#endif
/* Check if Igf_Port_Ip_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBcfg.c and Igf_Port_Ip.h are of the same software version */
#if ((IGF_PORT_IP_SW_MAJOR_VERSION_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_C != IGF_PORT_IP_SW_MAJOR_VERSION_H) || \
     (IGF_PORT_IP_SW_MINOR_VERSION_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_C != IGF_PORT_IP_SW_MINOR_VERSION_H) || \
     (IGF_PORT_IP_SW_PATCH_VERSION_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_C != IGF_PORT_IP_SW_PATCH_VERSION_H)    \
    )
    #error "Software Version Numbers of Igf_Port_Ip_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBcfg.c and Igf_Port_Ip.h are different"
#endif
/*==================================================================================================
*                           LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
*                                          LOCAL MACROS
==================================================================================================*/
[!/*****************************************************************************/!][!//
[!/*                          MACRO GetIgfInstanceAndChannel                   */!][!//
[!/*****************************************************************************/!][!//
[!/* Get the IGF Instance number and channel number                            */!][!//
[!MACRO "GetIgfInstanceAndChannel"!][!//
[!NOCODE!][!//
[!VAR "MacIgfInstance"="number(substring-after(substring-before(./IGFSettings/IGFChannel,'_'),'IGF'))"!][!//
[!VAR "MacIgfChannel"="number(substring-after(./IGFSettings/IGFChannel,'_'))"!][!//
[!ENDNOCODE!][!//
(uint8)[!"num:i($MacIgfInstance)"!], (uint8)[!"num:i($MacIgfChannel)"!][!//
[!ENDMACRO!][!//
[!/*****************************************************************************/!][!//
[!//
[!//
[!/*****************************************************************************/!][!//
[!/*                          MACRO GetIgfMCR                                  */!][!//
[!/*****************************************************************************/!][!//
[!/* Get the IGF MCR register value                                            */!][!//
[!MACRO "GetIgfMCR"!][!//
[!NOCODE!][!//
[!VAR "MacIgfMCR"="num:i(0)"!][!//
[!/* Check if IMM (Immediate Edge Propagation) is set. If yes, MCR will contain only this bit, because the filtering is disabled */!][!//
[!IF "./IGFSettings/IGF_IMM"!][!//
    [!VAR "MacIgfMCR"="bit:or($MacIgfMCR,bit:shl(1,9))"!][!//
[!ELSE!]
    [!IF "text:match(./IGFSettings/IGF_PSSEL, 'External')"!][!//
        [!VAR "MacIgfMCR"="bit:or($MacIgfMCR,bit:shl(1,8))"!][!//
    [!ENDIF!][!//
    [!/* Check the falling edge filter selection */!][!//
    [!IF "text:match(./IGFSettings/IGF_FFM, 'Bypass')"!][!//
        [!VAR "MacIgfMCR"="bit:or($MacIgfMCR,bit:shl(0,3))"!][!//
    [!ELSEIF "text:match(./IGFSettings/IGF_FFM, '^Windowing$')"!][!//
        [!VAR "MacIgfMCR"="bit:or($MacIgfMCR,bit:shl(1,3))"!][!//
    [!ELSEIF "text:match(./IGFSettings/IGF_FFM, '^Integrating$')"!][!//
        [!VAR "MacIgfMCR"="bit:or($MacIgfMCR,bit:shl(2,3))"!][!//
    [!ELSEIF "text:match(./IGFSettings/IGF_FFM, '^IntegratingHold$')"!][!//
        [!VAR "MacIgfMCR"="bit:or($MacIgfMCR,bit:shl(3,3))"!][!//
    [!ELSEIF "text:match(./IGFSettings/IGF_FFM, '^WindowingWithPostSample$')"!][!//
        [!VAR "MacIgfMCR"="bit:or($MacIgfMCR,bit:shl(4,3))"!][!//
    [!ENDIF!][!//
    [!/* Check the rising edge filter selection */!][!//
    [!IF "text:match(./IGFSettings/IGF_RFM, 'Bypass')"!][!//
        [!VAR "MacIgfMCR"="bit:or($MacIgfMCR,bit:shl(0,0))"!][!//
    [!ELSEIF "text:match(./IGFSettings/IGF_RFM, '^Windowing$')"!][!//
        [!VAR "MacIgfMCR"="bit:or($MacIgfMCR,bit:shl(1,0))"!][!//
    [!ELSEIF "text:match(./IGFSettings/IGF_RFM, '^Integrating$')"!][!//
        [!VAR "MacIgfMCR"="bit:or($MacIgfMCR,bit:shl(2,0))"!][!//
    [!ELSEIF "text:match(./IGFSettings/IGF_RFM, '^IntegratingHold$')"!][!//
        [!VAR "MacIgfMCR"="bit:or($MacIgfMCR,bit:shl(3,0))"!][!//
    [!ELSEIF "text:match(./IGFSettings/IGF_RFM, '^WindowingWithPostSample$')"!][!//
        [!VAR "MacIgfMCR"="bit:or($MacIgfMCR,bit:shl(4,0))"!][!//
    [!ENDIF!][!//
    [!/* Set FGEN bit */!][!//
    [!VAR "MacIgfMCR"="bit:or($MacIgfMCR,bit:shl(1,6))"!][!//
[!ENDIF!][!//
[!ENDNOCODE!][!//
(uint32)[!"num:inttohex($MacIgfMCR,8)"!]U[!//
[!ENDMACRO!][!//
[!/*****************************************************************************/!][!//
[!//
[!//
[!/*****************************************************************************/!][!//
[!/*                          MACRO GetIgfPRESR                                */!][!//
[!/*****************************************************************************/!][!//
[!/* Get the IGF channel prescaler value                                       */!][!//
[!MACRO "GetIgfPRESR"!][!//
[!VAR "MacIgfPRESR"="num:hextoint('0xFFFFFFFF')"!][!//
[!NOCODE!][!//
[!/* Check if the IGF Prescaler control is enabled.Check is a bit more complex for the epd tests to pass */!][!//
[!IF "node:exists(./IGFSettings/IGF_FGEN) and node:exists(./IGFSettings/IGF_IMM)"!][!//
    [!IF "./IGFSettings/IGF_FGEN = 'true' and ./IGFSettings/IGF_IMM = 'false' and ./IGFSettings/IGF_PSSEL = 'Internal'"!][!//
        [!VAR "MacIgfPRESR"="./IGFSettings/IGF_FPRE"!][!//
    [!ENDIF!][!//
[!ENDIF!][!//
[!ENDNOCODE!][!//
(uint32)[!"num:inttohex($MacIgfPRESR,8)"!]U[!//
[!ENDMACRO!][!//
[!/*****************************************************************************/!][!//
[!//
[!//
[!/*****************************************************************************/!][!//
[!/*                          MACRO GetIgfRTH                                  */!][!//
[!/*****************************************************************************/!][!//
[!/* Get the IGF RTH value                                                     */!][!//
[!MACRO "GetIgfRTH"!][!//
[!VAR "MacIgfRTH"="num:hextoint('0xFFFFFFFF')"!][!//
[!NOCODE!][!//
[!/* Check if the IGF RTH is enabled. Check is a bit more complex for the epd tests to pass */!][!//
[!IF "node:exists(./IGFSettings/IGF_FGEN) and node:exists(./IGFSettings/IGF_IMM)"!][!//
    [!IF "./IGFSettings/IGF_FGEN = 'true' and ./IGFSettings/IGF_IMM = 'false'"!][!//
        [!VAR "MacIgfRTH"="./IGFSettings/IGF_RTH"!][!//
    [!ENDIF!][!//
[!ENDIF!][!//
[!ENDNOCODE!][!//
(uint32)[!"num:inttohex($MacIgfRTH,8)"!]U[!//
[!ENDMACRO!][!//
[!/*****************************************************************************/!][!//
[!//
[!//
[!/*****************************************************************************/!][!//
[!/*                          MACRO GetIgfFTH                                  */!][!//
[!/*****************************************************************************/!][!//
[!/* Get the IGF FTH value                                                     */!][!//
[!MACRO "GetIgfFTH"!][!//
[!VAR "MacIgfFTH"="num:hextoint('0xFFFFFFFF')"!][!//
[!NOCODE!][!//
[!/* Check if the IGF FTH is enabled. Check is a bit more complex for the epd tests to pass */!][!//
[!IF "node:exists(./IGFSettings/IGF_FGEN) and node:exists(./IGFSettings/IGF_IMM)"!][!//
    [!IF "./IGFSettings/IGF_FGEN = 'true' and ./IGFSettings/IGF_IMM = 'false'"!][!//
        [!VAR "MacIgfFTH"="./IGFSettings/IGF_FTH"!][!//
    [!ENDIF!][!//
[!ENDIF!][!//
[!ENDNOCODE!][!//
(uint32)[!"num:inttohex($MacIgfFTH,8)"!]U[!//
[!ENDMACRO!][!//

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
[!SELECT "PortConfigSet"!][!//
[!VAR "count"= "1"!][!//
[!NOCODE!]
[!/* Count maximum number of configured IGF channels. */!][!//
[!VAR "MaxNoOfConfiguredIgfChannels" = "0"!][!//
[!LOOP "PortContainer/*/PortPin/*"!][!//
    [!/* Check if the IGF Settings container is enabled */!][!//
    [!IF "boolean(./IGFSettings)"!][!//
        [!/* Check if the FGEN bit is enabled. If not, it means that we will not touch the IGF channel settings */!][!//
        [!IF "./IGFSettings/IGF_FGEN"!][!//
            [!VAR "MaxNoOfConfiguredIgfChannels"= "$MaxNoOfConfiguredIgfChannels+1"!][!//
        [!ENDIF!][!//
    [!ENDIF!][!//
[!ENDLOOP!][!//
[!ENDNOCODE!][!//
[!IF "$MaxNoOfConfiguredIgfChannels>0"!][!//
#define PORT_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Port_MemMap.h"

/**
* @brief IGF Channels configuration data for configPB
*/
const Igf_Port_Ip_ChannelConfigType aIgf_InitConfigArr[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][IGF_NUM_OF_CHANNELS_CONFIG] =
{
    /* Instance, channel, MCR Register, Prescaler Register, RTH Register, FTH Register */
[!NOCODE!][!//
[!LOOP "PortContainer/*/PortPin/*"!][!//
    [!/* Check if the IGF Settings container is enabled */!][!//
    [!IF "boolean(./IGFSettings)"!][!//
        [!/* Check if the FGEN bit is enabled. If not, it means that we will not touch the IGF channel settings */!][!//
        [!IF "./IGFSettings/IGF_FGEN"!][!//
            [!IF "$MaxNoOfConfiguredIgfChannels>$count"!][!//
[!CODE!][!//
    {[!CALL "GetIgfInstanceAndChannel"!], [!CALL "GetIgfMCR"!], [!CALL "GetIgfPRESR"!], [!CALL "GetIgfRTH"!], [!CALL "GetIgfFTH"!]},
[!ENDCODE!][!//
            [!ELSE!][!//
[!CODE!][!//
    {[!CALL "GetIgfInstanceAndChannel"!], [!CALL "GetIgfMCR"!], [!CALL "GetIgfPRESR"!], [!CALL "GetIgfRTH"!], [!CALL "GetIgfFTH"!]}
[!ENDCODE!][!//
            [!ENDIF!][!//
            [!VAR "count"= "$count+1"!][!//
        [!ENDIF!][!//
    [!ENDIF!][!//
[!ENDLOOP!][!//
[!ENDNOCODE!][!//
};

#define PORT_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Port_MemMap.h"
[!ENDIF!][!//
[!ENDSELECT!][!//

/*==================================================================================================
*                                        GLOBAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                        GLOBAL VARIABLES
==================================================================================================*/

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
