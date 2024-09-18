/*==================================================================================================
*   Project              : RTD AUTOSAR 4.7
*   Platform             : CORTEXM
*   Peripheral           : FLEXIO
*   Dependencies         : 
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

#ifndef LPUART_UART_IP[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_H
#define LPUART_UART_IP[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_H

/**
*   @file
*   @defgroup lpuart_uart_ip Lpuart UART IPL
*   @addtogroup  lpuart_uart_ip Lpuart UART IPL
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

#include "Lpuart_Uart_Ip_Types.h"

/*==================================================================================================
                                SOURCE FILE VERSION INFORMATION
==================================================================================================*/

#define LPUART_UART_IP[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_VENDOR_ID                     43
#define LPUART_UART_IP[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_AR_RELEASE_MAJOR_VERSION      4
#define LPUART_UART_IP[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_AR_RELEASE_MINOR_VERSION      7
#define LPUART_UART_IP[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_AR_RELEASE_REVISION_VERSION   0
#define LPUART_UART_IP[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_SW_MAJOR_VERSION              3
#define LPUART_UART_IP[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_SW_MINOR_VERSION              0
#define LPUART_UART_IP[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_SW_PATCH_VERSION              0

/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/
/* Checks against Lpuart_Uart_Ip_Types.h */
#if (LPUART_UART_IP[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_VENDOR_ID != LPUART_UART_IP_TYPES_VENDOR_ID)
    #error "Lpuart_Uart_Ip[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCfg.h and Lpuart_Uart_Ip_Types.h have different vendor ids"
#endif
#if ((LPUART_UART_IP[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_AR_RELEASE_MAJOR_VERSION   != LPUART_UART_IP_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (LPUART_UART_IP[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_AR_RELEASE_MINOR_VERSION   != LPUART_UART_IP_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (LPUART_UART_IP[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_AR_RELEASE_REVISION_VERSION!= LPUART_UART_IP_TYPES_AR_RELEASE_REVISION_VERSION))
    #error "AUTOSAR Version Numbers of Lpuart_Uart_Ip[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCfg.h and Lpuart_Uart_Ip_Types.h are different"
#endif
#if ((LPUART_UART_IP[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_SW_MAJOR_VERSION!= LPUART_UART_IP_TYPES_SW_MAJOR_VERSION) || \
     (LPUART_UART_IP[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_SW_MINOR_VERSION!= LPUART_UART_IP_TYPES_SW_MINOR_VERSION) || \
     (LPUART_UART_IP[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_SW_PATCH_VERSION!= LPUART_UART_IP_TYPES_SW_PATCH_VERSION))
    #error "Software Version Numbers of Lpuart_Uart_Ip[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCfg.h and Lpuart_Uart_Ip_Types.h are different"
#endif


/*==================================================================================================
                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
                                        GLOBAL MACROS
==================================================================================================*/
/**
* @brief          Link Uart channels symbolic names with Uart hardware channel IDs.
* @details        Link Uart channels symbolic names with Uart hardware channel IDs.
*
* @api
*/

[!// Get number instance
[!VAR "VarUartHwChannel" = "0"!][!//
[!LOOP "UartGlobalConfig/UartChannel/*"!][!//
  [!IF "UartHwUsing = 'LPUART_IP'"!][!//
    [!VAR "HardwareChannel" = "node:value(DetailModuleConfiguration/UartHwChannel)"!][!//
    [!IF "contains($HardwareChannel, 'LPUART_MSC')"!][!// LPUART_MSC is only available on S32K396
        [!VAR "VarUartHwChannel" = "4"!][!//
    [!ELSE!]
        [!VAR "VarUartHwChannel" = "substring-after(string($HardwareChannel),'LPUART_')"!][!//
    [!ENDIF!]
    [!VAR "UartHWChannelName" = "concat('LPUART_UART_IP_INSTANCE_USING_', substring-after($HardwareChannel,'LPUART_'))"!][!//
      [!CODE!][!//

#ifndef [!"$UartHWChannelName"!]
    #define [!"$UartHWChannelName"!]    [!"num:i($VarUartHwChannel)"!]U
#endif

      [!ENDCODE!][!//
  [!ENDIF!][!//
[!ENDLOOP!][!//


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
[!NOCODE!]
[!VAR "UsingLpuart" = "0"!]
[!LOOP "UartGlobalConfig/UartChannel/*"!]
    [!IF "UartHwUsing = 'LPUART_IP'"!]
        [!VAR "UsingLpuart" = "1"!]
        [!BREAK!][!//
    [!ENDIF!]
[!ENDLOOP!]
[!IF "var:defined('postBuildVariant')"!][!//
  [!VAR "PostBuildVariantNameUnderscore" = "concat('_',$postBuildVariant)"!][!//
[!CODE!]#define LPUART_UART_IP_CONFIG_[!"$postBuildVariant"!]_PB[!IF "$UsingLpuart = 1"!] \[!ENDIF!][!CR!][!ENDCODE!]
[!ELSE!][!//
  [!VAR "PostBuildVariantNameUnderscore" = "string(null)"!][!//
[!CODE!]#define LPUART_UART_IP_CONFIG_PB \[!CR!][!ENDCODE!]
[!ENDIF!][!//
[!LOOP "UartGlobalConfig/UartChannel/*"!][!//
[!IF "UartHwUsing = 'LPUART_IP'"!][!//
[!CODE!]extern const Lpuart_Uart_Ip_UserConfigType Lpuart_Uart_Ip_xHwConfigPB_[!"UartChannelId"!][!"$PostBuildVariantNameUnderscore"!];\[!CR!][!ENDCODE!][!//
[!ENDIF!]
    [!ENDLOOP!]
[!ENDNOCODE!]


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

#endif /* LPUART_UART_IP[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_H */
