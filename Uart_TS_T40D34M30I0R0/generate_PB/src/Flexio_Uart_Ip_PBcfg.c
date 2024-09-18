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

/**
*   @file
*   @defgroup flexio_uart_tx_ip Flexio UART IPL
*   @addtogroup  flexio_uart_tx_ip Flexio UART IPL
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

#include "Flexio_Uart_Ip_Cfg.h"
#include "StandardTypes.h"
#if (FLEXIO_UART_IP_HAS_DMA_ENABLED == STD_ON)
#include "Dma_Ip.h"
#endif
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/

#define FLEXIO_UART_IP[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_VENDOR_ID_C                     43
#define FLEXIO_UART_IP[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_AR_RELEASE_MAJOR_VERSION_C      4
#define FLEXIO_UART_IP[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_AR_RELEASE_MINOR_VERSION_C      7
#define FLEXIO_UART_IP[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_AR_RELEASE_REVISION_VERSION_C   0
#define FLEXIO_UART_IP[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_SW_MAJOR_VERSION_C              3
#define FLEXIO_UART_IP[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_SW_MINOR_VERSION_C              0
#define FLEXIO_UART_IP[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_SW_PATCH_VERSION_C              0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/

/* Checks against Flexio_Uart_Ip_Cfg.h */
#if (FLEXIO_UART_IP[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_VENDOR_ID_C != FLEXIO_UART_IP_CFG_VENDOR_ID)
    #error "Flexio_Uart_Ip[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg.c and Flexio_Uart_Ip_Cfg.h have different vendor ids"
#endif
#if ((FLEXIO_UART_IP[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_AR_RELEASE_MAJOR_VERSION_C    != FLEXIO_UART_IP_CFG_AR_RELEASE_MAJOR_VERSION) || \
     (FLEXIO_UART_IP[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_AR_RELEASE_MINOR_VERSION_C    != FLEXIO_UART_IP_CFG_AR_RELEASE_MINOR_VERSION) || \
     (FLEXIO_UART_IP[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_AR_RELEASE_REVISION_VERSION_C != FLEXIO_UART_IP_CFG_AR_RELEASE_REVISION_VERSION))
     #error "AUTOSAR Version Numbers of Flexio_Uart_Ip[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg.c and Flexio_Uart_Ip_Cfg.h are different"
#endif
#if ((FLEXIO_UART_IP[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_SW_MAJOR_VERSION_C != FLEXIO_UART_IP_CFG_SW_MAJOR_VERSION) || \
     (FLEXIO_UART_IP[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_SW_MINOR_VERSION_C != FLEXIO_UART_IP_CFG_SW_MINOR_VERSION) || \
     (FLEXIO_UART_IP[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_SW_PATCH_VERSION_C != FLEXIO_UART_IP_CFG_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Flexio_Uart_Ip[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg.c and Flexio_Uart_Ip_Cfg.h are different"
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if current file and StandardTypes.h header file are of the same Autosar version */
    #if ((FLEXIO_UART_IP[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_AR_RELEASE_MAJOR_VERSION_C != STD_AR_RELEASE_MAJOR_VERSION) || \
         (FLEXIO_UART_IP[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_AR_RELEASE_MINOR_VERSION_C != STD_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of Flexio_Uart_Ip[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg.c and StandardTypes.h are different"
    #endif
    /* Checks against Dma_Ip.h */
    #if (FLEXIO_UART_IP_HAS_DMA_ENABLED == STD_ON)
        #if ((FLEXIO_UART_IP[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_AR_RELEASE_MAJOR_VERSION_C != DMA_IP_AR_RELEASE_MAJOR_VERSION) || \
             (FLEXIO_UART_IP[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_AR_RELEASE_MINOR_VERSION_C != DMA_IP_AR_RELEASE_MINOR_VERSION))
            #error "AutoSar Version Numbers of Flexio_Uart_Ip[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg.c and Dma_Ip.h are different"
        #endif
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
*                                   STATE STRUCTURE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                      LOCAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      LOCAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                      GLOBAL VARIABLES
==================================================================================================*/
#define UART_START_SEC_VAR_CLEARED_UNSPECIFIED_NO_CACHEABLE
#include "Uart_MemMap.h"
[!NOCODE!]
[!VAR "NumHwChannelConfig" = "0"!]
[!LOOP "UartGlobalConfig/UartChannel/*"!][!//
[!IF "UartHwUsing = 'FLEXIO_IP'"!]
    [!VAR "NumHwChannelConfig" = "$NumHwChannelConfig + 1"!]
[!ENDIF!]
[!ENDLOOP!][!//
[!IF "$NumHwChannelConfig != 0"!]
[!CODE!]extern Flexio_Uart_Ip_StateStructureType Flexio_Uart_Ip_apStateStructure[FLEXIO_UART_IP_NUMBER_OF_INSTANCES];[!ENDCODE!]
[!ENDIF!]
[!ENDNOCODE!]
#define UART_STOP_SEC_VAR_CLEARED_UNSPECIFIED_NO_CACHEABLE
#include "Uart_MemMap.h"

#define UART_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Uart_MemMap.h"

[!NOCODE!]
[!VAR "Callback"  = "'NULL_PTR'"!]
[!VAR "CallbackParam" = "'NULL_PTR'"!]
[!IF "GeneralConfiguration/UartCallbackCapability"!]
    [!IF "(node:exists(GeneralConfiguration/UartCallback))"!]
        [!IF "node:value(GeneralConfiguration/UartCallback) != 'NULL_PTR'"!]
            [!VAR "Callback" = "'(Flexio_Uart_Ip_CallbackType)Uart_Ipw_FlexioTransferCallback'"!]
        [!ENDIF!]
    [!ENDIF!]
[!ENDIF!]
[!ENDNOCODE!]

[!NOCODE!]
[!VAR "NumChannelUser"  = "0"!]
[!LOOP "UartGlobalConfig/UartChannel/*"!][!//
[!VAR "Ratio" = "0"!]

[!IF "UartHwUsing = 'FLEXIO_IP'"!]
[!CODE!]
/**
* @brief          Hardware configuration for Uart Hardware - Configuration:
*
* @api
*/
const Flexio_Uart_Ip_UserConfigType Flexio_Uart_Ip_xHwConfigPB_[!"UartChannelId"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!] =
{
[!ENDCODE!]
[!IF "(node:exists(FlexioModuleConfiguration))"!]
[!SELECT "node:ref(UartClockRef)"!]
[!VAR "ClockFrequencyFromMcu" = "McuClockReferencePointFrequency"!]
[!VAR "ClockFrequency" = "num:i($ClockFrequencyFromMcu)"!]
[!ENDSELECT!][!//

[!IF "node:exists(as:modconf("Resource")[1]/ResourceGeneral/ResourceSubderivative)"!][!//
    [!VAR "_derivative" = "as:modconf("Resource")[1]/ResourceGeneral/ResourceSubderivative"!][!//
    [!VAR "derivative" = "substring-before($_derivative, '_')"!][!//
    [!IF "node:value(FlexioModuleConfiguration/DesireBaudrate) != 'FLEXIO_UART_BAUDRATE_CUSTOM'"!]
        [!VAR "Baudrate" = "num:i(substring-after(FlexioModuleConfiguration/DesireBaudrate, 'FLEXIO_UART_BAUDRATE_'))"!]
        [!IF "contains($derivative, 's32k1') or contains($derivative, 's32m24')"!][!//
            [!VAR "Ratio" = "num:i(2)"!]
            [!VAR "Divider" = "num:i(num:i($ClockFrequency div ($Baudrate * $Ratio)) - 1)"!]
            [!IF "($Divider > num:i(255)) or ($Divider < num:i(0))"!]
                [!ERROR!] Uart baud rate divider = [!"$Divider"!], it should be < 255 and > 0, please select another MCU clock.[!ENDERROR!]
            [!ENDIF!]
            [!VAR "TimeDecMode" = "'FLEXIO_TIMER_DECREMENT_FXIO_CLK_SHIFT_TMR'"!]
        [!ENDIF!]

        [!IF "contains($derivative, 's32k3') or contains($derivative, 's32m27')"!][!//
            [!VAR "Ratio" = "num:i(32)"!]
            [!VAR "Divider" = "num:i(num:i($ClockFrequency div ($Baudrate * $Ratio)) - 1)"!]
            [!IF "($Divider <= num:i(255)) and ($Divider >= num:i(0))"!]
                [!VAR "TimeDecMode" = "'FLEXIO_TIMER_DECREMENT_FXIO_CLK_DIV_16'"!]
            [!ELSE!]
                [!VAR "Ratio" = "num:i(512)"!]
                [!VAR "Divider" = "num:i(num:i($ClockFrequency div ($Baudrate * $Ratio)) - 1)"!]
                [!IF "($Divider > num:i(255)) or ($Divider < num:i(0))"!]
                    [!ERROR!] Uart baud rate divider = [!"$Divider"!], it should be < 255 and > 0, please select another MCU clock.[!ENDERROR!]
                [!ELSE!]
                    [!VAR "TimeDecMode" = "'FLEXIO_TIMER_DECREMENT_FXIO_CLK_DIV_256'"!]
                [!ENDIF!]
            [!ENDIF!]
        [!ENDIF!]
    [!ELSE!]
        [!IF "node:value(FlexioModuleConfiguration/CustomTimerDecrement) = 'FLEXIO_TIMER_DECREMENT_FXIO_CLK_SHIFT_TMR'"!]
            [!VAR "Ratio" = "num:i(2)"!]
        [!ELSE!]
            [!VAR "Ratio" = "num:i(2) * num:i(substring-after(FlexioModuleConfiguration/CustomTimerDecrement, 'FLEXIO_TIMER_DECREMENT_FXIO_CLK_DIV_'))"!]
        [!ENDIF!]
        [!VAR "Divider" = "num:i(FlexioModuleConfiguration/CustomBaudrateDivider)"!]
        [!VAR "TimeDecMode" = "node:value(FlexioModuleConfiguration/CustomTimerDecrement)"!]
    [!ENDIF!]
[!ELSE!]
    [!ERROR!] Resource module not found.[!ENDERROR!]
[!ENDIF!]

[!VAR "ActualBaudrate" = "num:i($ClockFrequency div ($Ratio * ($Divider + 1)))"!]

[!IF "(node:exists(FlexioModuleConfiguration/UartHwChannelRef))"!][!//
[!SELECT "node:ref(FlexioModuleConfiguration/UartHwChannelRef)"!][!//
    [!VAR "FlexioUartPin" = "num:i(substring-after(FlexioMclPinId, 'PIN_'))"!]
    [!VAR "FlexioUartChannel" = "num:i(substring-after(FlexioMclChannelId, 'CHANNEL_'))"!]
[!ENDSELECT!][!//
[!ELSE!][!//
    [!VAR "FlexioUartPin" = "num:i(255)"!]
    [!VAR "FlexioUartChannel" = "num:i(255)"!]
[!ENDIF!][!//    /* Runtime state structure refference */

[!CODE!]
    /*!< Flexio Uart Channel has been configured */
    [!"$FlexioUartChannel"!]U,
    /*!< Driver type: interrupts/DMA */
    [!"FlexioModuleConfiguration/FlexioUartInteruptDmaMethod"!],
    /*!< Baudrate divider */
    [!"$Divider"!]U,
    /*!< The source of the Timer decrement and the source of the Shift clock */
    [!"$TimeDecMode"!],
    /*!< Baud rate in hertz */
    [!"$ActualBaudrate"!]U,
    /*!< Number of bits per word */
    [!"FlexioModuleConfiguration/bitCount"!],
    /*!< Driver direction: Tx or Rx */
    [!"FlexioModuleConfiguration/driverDirection"!],
    /*!< Flexio pin to use as Tx or Rx pin */
    [!"$FlexioUartPin"!]U,
    /*!< User callback function. Note that this function will be
        called from the interrupt service routine, so itsexecution time
        should be as small as possible. It can be NULL if it is not needed */
    [!"$Callback"!],
    /* Callback parameter pointer.*/
    [!"$CallbackParam"!],
#if (FLEXIO_UART_IP_HAS_DMA_ENABLED == STD_ON)
    /* DMA channel number for DMA-based Rx or DMA-based Tx. */
[!IF "(node:exists(FlexioModuleConfiguration/FlexioDmaChannelRef))"!][!//
[!SELECT "node:ref(FlexioModuleConfiguration/FlexioDmaChannelRef)"!][!//
    [!"dmaLogicChannel_LogicName"!],
[!ENDSELECT!][!//
[!ELSE!][!//
    255,
[!ENDIF!][!//    /* Runtime state structure refference */
#endif
    &Flexio_Uart_Ip_apStateStructure[[!"num:i($NumChannelUser)"!]]
[!ENDCODE!]
[!ENDIF!][!//    /* exists(FlexioModuleConfiguration) */
[!CODE!]
};
[!ENDCODE!]
[!VAR "NumChannelUser" = "$NumChannelUser + 1"!]
[!ENDIF!]
[!ENDLOOP!][!//
[!ENDNOCODE!]
#define UART_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Uart_MemMap.h"
/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/

/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/


#ifdef __cplusplus
}

/** @} */

#endif
