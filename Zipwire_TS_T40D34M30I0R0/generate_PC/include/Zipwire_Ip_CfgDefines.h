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

/* Prevention from multiple including the same header */
#ifndef ZIPWIRE_IP_CFG_DEFINE_H
#define ZIPWIRE_IP_CFG_DEFINE_H

/**
*   @file       Zipwire_Ip_CfgDefines.h
*
*   @version    3.0.0
*
*   @brief      AUTOSAR Zipwire Post-Build(PB) configuration file code template.
*   @details    Code template for Post-Build(PB) configuration file generation.
*
*   @defgroup   ZIPWIRE_CFG ZIPWIRE Configuration
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
#include "StandardTypes.h"
[!NOCODE!][!// Include specific header file
[!IF "node:exists(as:modconf("Resource")[1]/ResourceGeneral/ResourceSubderivative)"!][!//
    [!VAR "DerivativeName" = "text:toupper(substring-before(as:modconf("Resource")[1]/ResourceGeneral/ResourceSubderivative,'_'))"!]
    [!IF "contains($DerivativeName, 'S32Z2')"!][!//
        [!CODE!][!WS "0"!]#include "S32Z2_LFAST.h"[!CR!][!ENDCODE!][!//
        [!CODE!][!WS "0"!]#include "S32Z2_SIPI.h"[!CR!][!ENDCODE!][!//
    [!ELSEIF "contains($DerivativeName, 'S32E2')"!][!//
        [!CODE!][!WS "0"!]#include "S32E2_LFAST.h"[!CR!][!ENDCODE!][!//
        [!CODE!][!WS "0"!]#include "S32E2_SIPI.h"[!CR!][!ENDCODE!][!//
    [!ELSEIF "contains($DerivativeName, 'S32K39')"!][!//
        [!CODE!][!WS "0"!]#include "S32K39_SIUL2.h"[!CR!][!ENDCODE!][!//
        [!CODE!][!WS "0"!]#include "S32K39_DCM_GPR.h"[!CR!][!ENDCODE!][!//
        [!CODE!][!WS "0"!]#include "S32K39_DIGRF_TOP.h"[!CR!][!ENDCODE!][!//
        [!CODE!][!WS "0"!]#include "S32K39_SIPI1.h"[!CR!][!ENDCODE!][!//
    [!ENDIF!][!//
[!ENDIF!][!//
[!ENDNOCODE!][!//



/*==================================================================================================
*                                 SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define ZIPWIRE_IP_CFG_DEFINES_VENDOR_ID                       43
#define ZIPWIRE_IP_CFG_DEFINES_AR_RELEASE_MAJOR_VERSION        4
#define ZIPWIRE_IP_CFG_DEFINES_AR_RELEASE_MINOR_VERSION        7
#define ZIPWIRE_IP_CFG_DEFINES_AR_RELEASE_REVISION_VERSION     0
#define ZIPWIRE_IP_CFG_DEFINES_SW_MAJOR_VERSION                3
#define ZIPWIRE_IP_CFG_DEFINES_SW_MINOR_VERSION                0
#define ZIPWIRE_IP_CFG_DEFINES_SW_PATCH_VERSION                0

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
/* Check if Zipwire_Ip_CfgDefines.h file and StandardTypes.h header file are of the same Autosar version */
#if ((ZIPWIRE_IP_CFG_DEFINES_AR_RELEASE_MAJOR_VERSION != STD_AR_RELEASE_MAJOR_VERSION) || \
     (ZIPWIRE_IP_CFG_DEFINES_AR_RELEASE_MINOR_VERSION != STD_AR_RELEASE_MINOR_VERSION) \
    )
    #error "AutoSar Version Numbers of Zipwire_Ip_CfgDefines.h file and StandardTypes.h are different"
#endif
#endif
/*==================================================================================================
*                                            CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/
/*! @brief  Enables or disables PRE-COMPILE SUPPORT. */
#define ZIPWIRE_PRECOMPILE_SUPPORT                              [!IF "IMPLEMENTATION_CONFIG_VARIANT = 'VariantPreCompile'"!](STD_ON)[!ELSE!](STD_OFF)[!ENDIF!]

/*! @brief  Error detect. */
#define ZIPWIRE_DET_IS_AVAILABLE                                [!IF "ZipwireGeneral/ZipwireDetectError"!](STD_ON)[!ELSE!](STD_OFF)[!ENDIF!]
#define ZIPWIRE_IP_DEV_ERROR_DETECT                             [!IF "ZipwireGeneral/ZipwireDetectError"!](STD_ON)[!ELSE!](STD_OFF)[!ENDIF!]

/*! @brief  Enables or disables User Mode use Register Protect. */
#define ZIPWIRE_ENABLE_USER_MODE_SUPPORT                        [!IF "ZipwireGeneral/ZipwireEnableUserModeSupport"!](STD_ON)[!ELSE!](STD_OFF)[!ENDIF!]

#ifndef MCAL_ENABLE_USER_MODE_SUPPORT
    #if (STD_ON == ZIPWIRE_ENABLE_USER_MODE_SUPPORT)
        #error MCAL_ENABLE_USER_MODE_SUPPORT is not enabled. For running ZIPWIRE in user mode, the MCAL_ENABLE_USER_MODE_SUPPORT needs to be defined
    #endif /* (STD_ON == ZIPWIRE_ENABLE_USER_MODE_SUPPORT) */
#endif /* ifndef MCAL_ENABLE_USER_MODE_SUPPORT */

/*! @brief DMA Supported. */
#define ZIPWIRE_IP_DMA_IS_AVAILABLE                             [!IF "ZipwireGeneral/ZipwireDmaSupportEnable"!](STD_ON)[!ELSE!](STD_OFF)[!ENDIF!]

/*! @brief  Enables or disables get Version Info. */
#define ZIPWIRE_VERSION_INFO_API_ENABLE                         [!IF " ZipwireGeneral/ZipwireVersionInfoApi"!](STD_ON)[!ELSE!](STD_OFF)[!ENDIF!]

/* @brief  Zipwire SIPI separated interrupt lines */
#define ZIPWIRE_IP_SEPARATED_IRQ_LINES                          [!IF "ecu:get('Zipwire.Hardware.SeparatedIrqLines')"!](STD_ON)[!ELSE!](STD_OFF)[!ENDIF!]

/* @brief  Zipwire SIPI separated interrupt lines */
#define ZIPWIRE_IP_ORED_IRQ_LINES                               [!IF "ecu:get('Zipwire.Hardware.OredIrqLines')"!](STD_ON)[!ELSE!](STD_OFF)[!ENDIF!]

/*! @brief  Core Default. */
#define ZIPWIRE_CORE_DEFAULT                                    (0U)

/*! @brief  Streaming Channel. */
#define ZIPWIRE_IP_STREAMING_CHANNEL                            (0x2U)

/** @brief  Zipwire Timeout Config */
#define ZIPWIRE_IP_TIMEOUT_COUNTER  ([!"num:i(./ZipwireGeneral/ZipwireTimeoutDuration)"!]UL)
#define ZIPWIRE_IP_TIMEOUT_TYPE     ([!"(./ZipwireGeneral/ZipwireTimeoutMethod)"!])

/*! @brief  Instance Enable. */
[!VAR "CounterInstance0" = "'STD_OFF'"!][!//
[!VAR "CounterInstance1" = "'STD_OFF'"!][!//
[!LOOP "ZipwireInstanceConfig/*"!][!//
[!IF "node:value('./ZipwireHwInstance')='ZIPWIRE_LOGIC_INSTANCE_0'"!][!//
[!VAR "CounterInstance0" = "'STD_ON'"!][!//
[!ENDIF!][!//
[!IF "node:value('./ZipwireHwInstance')='ZIPWIRE_LOGIC_INSTANCE_1'"!][!//
[!VAR "CounterInstance1" = "'STD_ON'"!][!//
[!ENDIF!][!//
[!ENDLOOP!][!//
[!CODE!][!//
#define ZIPWIRE_IP_INSTANCE_0_DEFINED                                     ([!"$CounterInstance0"!])
#define ZIPWIRE_IP_INSTANCE_1_DEFINED                                     ([!"$CounterInstance1"!])
[!ENDCODE!][!//

[!VAR "ChannelCount" = "num:i(count(ecu:list('Zipwire.Hardware.Channel.List')))"!][!//
/*! @brief  Number of channel support. */
#ifndef ZIPWIRE_IP_CHANNEL_COUNT_U8
#define ZIPWIRE_IP_CHANNEL_COUNT_U8                             ((uint8)[!"$ChannelCount"!]U)
#endif

[!VAR "InstanceCount" = "num:i(count(ecu:list('Zipwire.Hardware.Instances.List')))"!][!//
/*! @brief  Number of channel support. */
#ifndef ZIPWIRE_IP_INSTANCE_COUNT_U8
#define ZIPWIRE_IP_INSTANCE_COUNT_U8                             ((uint8)[!"$InstanceCount"!]U)
#endif

/*! @brief  Instance channel support. */
[!VAR "InstancesIndex" = "num:i(0)"!][!//

[!LOOP "ecu:list('Zipwire.Hardware.Instances.List')"!][!//
#define [!"."!]                                     ((uint8)[!"$InstancesIndex"!]U)
[!VAR "InstancesIndex"="num:i($InstancesIndex + 1)"!][!//
[!ENDLOOP!][!//

/*! @brief  Hardware channel support. */
[!VAR "ChannelIndex" = "num:i(0)"!][!//
[!LOOP "ecu:list('Zipwire.Hardware.Channel.List')"!][!//
#define [!"."!]                                     ((uint8)[!"$ChannelIndex"!]U)
[!VAR "ChannelIndex"="num:i($ChannelIndex + 1)"!][!//
[!ENDLOOP!][!//

#define IP_SIPI_CDR0_COUNT                                      (0x0U)
#define IP_SIPI_CDR1_COUNT                                      (0x0U)
#define IP_SIPI_CDR2_COUNT                                      (0x0U)
#define IP_SIPI_CDR3_COUNT                                      (0x7U)

[!IF "node:exists(as:modconf("Resource")[1]/ResourceGeneral/ResourceSubderivative)"!][!//
[!VAR "DerivativeName" = "text:toupper(substring-before(as:modconf("Resource")[1]/ResourceGeneral/ResourceSubderivative,'_'))"!]
[!IF "contains($DerivativeName, 'S32Z2') or contains($DerivativeName, 'S32E2')"!][!//
[!FOR "Instance" = "1" TO "2"!][!//
[!FOR "Channel" = "1" TO "4"!][!//
[!CODE!][!//
#define IP_SIPI[!"num:i($Instance - 1)"!]_CHANNEL_[!"num:i($Channel - 1)"!]                                      (Zipwire_Ip_SIPI_Channel_Type *)(IP_SIPI_0_BASE + (0x20000 * [!"num:i($Instance - 1)"!]) + (0x20 * [!"num:i($Channel - 1)"!] + 4 * (uint8)IP_SIPI_CDR[!"num:i($Channel - 1)"!]_COUNT))
[!ENDCODE!][!//
[!ENDFOR!][!//
[!ENDFOR!][!//
[!CODE!][!//
#define IP_SIPI_CHANNEL_BASE_PTRS                            { \
                                                            {IP_SIPI0_CHANNEL_0, IP_SIPI0_CHANNEL_1, IP_SIPI0_CHANNEL_2, IP_SIPI0_CHANNEL_3}, \
                                                            {IP_SIPI1_CHANNEL_0, IP_SIPI1_CHANNEL_1, IP_SIPI1_CHANNEL_2, IP_SIPI1_CHANNEL_3}  \
                                                            }
[!ENDCODE!][!//
[!ELSEIF "contains($DerivativeName, 'S32K39')"!][!//

#define SIPI_CDR2_COUNT        SIPI1_CDR2_COUNT
#define SIPI_CCR0_WRT_MASK     SIPI1_CCR0_WRT_MASK
#define SIPI_CCR0_RRT_MASK     SIPI1_CCR0_RRT_MASK
#define SIPI_CCR0_TC_MASK      SIPI1_CCR0_TC_MASK
#define SIPI_CIR0_RAIE_MASK    SIPI1_CIR0_RAIE_MASK
#define SIPI_CIR0_WAIE_MASK    SIPI1_CIR0_WAIE_MASK
#define IP_SIPI_0              IP_SIPI
#define SIPI_Type              SIPI1_Type
#define LFAST_Type             DIGRF_TOP_Type
#define IP_LFAST_BASE_PTRS     IP_DIGRF_TOP_BASE_PTRS
#define IP_LFAST_BASE_ADDRS    IP_DIGRF_TOP_BASE_ADDRS
#define IP_SIPI_BASE_PTRS      IP_SIPI1_BASE_PTRS

[!FOR "Instance" = "1" TO "2"!][!//
[!FOR "Channel" = "1" TO "4"!][!//
[!CODE!][!//
#define IP_SIPI[!"num:i($Instance - 1)"!]_CHANNEL_[!"num:i($Channel - 1)"!]                                      (Zipwire_Ip_SIPI_Channel_Type *)(IP_SIPI_BASE + (0x20000 * [!"num:i($Instance - 1)"!]) + (0x20 * [!"num:i($Channel - 1)"!] + 4 * (uint8)IP_SIPI_CDR[!"num:i($Channel - 1)"!]_COUNT))
[!ENDCODE!][!//
[!ENDFOR!][!//
[!ENDFOR!][!//
[!CODE!][!//
#define IP_SIPI_CHANNEL_BASE_PTRS                           { \
                                                            {IP_SIPI0_CHANNEL_0, IP_SIPI0_CHANNEL_1, IP_SIPI0_CHANNEL_2, IP_SIPI0_CHANNEL_3}, \
                                                            }
[!ENDCODE!][!//
[!ENDIF!][!//
[!ENDIF!][!//
/*! @brief SIPI data access macros */
#define ZIPWIRE_IP_SIPI_DATA_SHIFT(x)                                      ((uint32)(0x18U & (0x18U << ((uint8)(x)))))
#define ZIPWIRE_IP_SIPI_DATA(x,y)                                          ((x) >> ZIPWIRE_IP_SIPI_DATA_SHIFT(y))

/* @brief SIPI stream channel data register access */
#define ZIPWIRE_IP_SIPI_STREAM_DATA(x)                                     (IP_SIPI_0->CDR2[(x)])

/* @brief SIPI stream transfer length in bytes */
#define ZIPWIRE_IP_SIPI_STREAM_TRANSFER_LEN                                (0x8U)

/* @brief SIPI channel err or flags masks */
#define ZIPWIRE_IP_SIPI_CH0_ERR_MASK                                       (0xFFU)
#define ZIPWIRE_IP_SIPI_CH1_ERR_MASK                                       (0xFF00U)
#define ZIPWIRE_IP_SIPI_CH2_ERR_MASK                                       (0xFF0000U)
#define ZIPWIRE_IP_SIPI_CH3_ERR_MASK                                       (0xFF000000U)

/*! @brief LFAST LCR Register control register */
#define ZIPWIRE_IP_LFAST_LCR_LVTXOE_MASK                        [!IF "ecu:get('Zipwire.Hardware.LFAST.LCR')"!](STD_ON)[!ELSE!](STD_OFF)[!ENDIF!]

/*! @brief LFAST wakeup delay control register */
#define ZIPWIRE_IP_LFAST_WAKEUP_DELAY_CONTROL                   ((uint32)0x12015F02U)

/*! @brief LFAST data rate change delay in clock cycles*/
#define ZIPWIRE_IP_LFAST_RATE_CHANGE_DELAY                      (0xFU)

/* Define ICLC commands */
/*! @brief LFAST enable slave tx command */
#define ZIPWIRE_IP_LFAST_ENABLE_SLAVE_TX_CMD                    (0x31U)

/*! @brief LFAST check slave status command */
#define ZIPWIRE_IP_LFAST_CHECK_SLAVE_STATUS_CMD                 (0x0U)

/*! @brief LFAST enable slave pll command */
#define ZIPWIRE_IP_LFAST_ENABLE_SLAVE_PLL_CMD                   (0x02U)

/*! @brief LFAST change slave tx speed mode command */
#define ZIPWIRE_IP_LFAST_CHANGE_SLAVE_TX_SPEED_MODE_CMD         (0x80U)

/*! @brief LFAST change slave rx speed mode command */
#define ZIPWIRE_IP_LFAST_CHANGE_SLAVE_RX_SPEED_MODE_CMD         (0x10U)

/* @brief SIPI reset timeout */
#define ZIPWIRE_IP_SIPI_RESET_TIMEOUT                           (0x10000U)
/*==================================================================================================
*                                             ENUMS
==================================================================================================*/


#ifdef __cplusplus
}
#endif

/** @} */

#endif /* ZIPWIRE_IP_CFG_DEFINE_H */
