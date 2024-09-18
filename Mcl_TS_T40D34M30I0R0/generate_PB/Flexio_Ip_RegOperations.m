[!AUTOSPACING!]
[!NOCODE!]
/*==================================================================================================
*   Project              : RTD AUTOSAR 4.7
*   Platform             : CORTEXM
*   Peripheral           : DMA,CACHE,TRGMUX,LCU,EMIOS,FLEXIO
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

[!VAR "NumberFlexioInstance" = "num:i(count(MclConfig/FlexioCommon/*))"!]
[!VAR "NumberFlexioChannels" = "num:i(count(MclConfig/FlexioCommon/*/FlexioMclLogicChannels/*))"!]

[!MACRO "Mcl_FlexioInstanceConfigTypeGen"!]
[!NOCODE!]

[!VAR "Mac_Comma" = "1"!]
[!CODE!]
[!WS "0"!]/**
[!WS "0"!]* @brief   Configuration for Flexio instance
[!WS "0"!]* @details This structure should contains data about the Flexio common
[!WS "0"!]*          part configurated using Mcl driver
[!WS "0"!]* @implements Mcl_FlexioInstanceConfigType
[!WS "0"!]*/
[!WS "0"!]const Flexio_Ip_InstanceConfigType Flexio_Ip_xFlexioInit[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!] =
[!WS "0"!]{
[!ENDCODE!][!//
[!LOOP "MclConfig/FlexioCommon/*"!][!//
    [!CODE!][!//
[!WS "8"!]/** @brief  Hardware Flexio instance number */
[!WS "8"!](uint8) [!"text:split(FlexioMclInstances, '_')[2]"!]U,
[!WS "8"!](boolean)[!"text:toupper(node:value(FlexioDebugEnable))"!],
[!ENDCODE!][!//
[!ENDLOOP!][!//
[!CODE!][!//
[!WS "0"!]};[!//
[!ENDCODE!][!//
[!ENDNOCODE!][!//
[!ENDMACRO!][!//

[!ENDNOCODE!][!//
