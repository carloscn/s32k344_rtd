/*==================================================================================================
*   Project              : RTD AUTOSAR 4.7
*   Platform             : CORTEXM
*   Peripheral           : DPGA
*   Dependencies         : none
*
*   Autosar Version      : 4.7.0
*   Autosar Revision     : ASR_REL_4_7_REV_0000
*   Autosar Conf.Variant :
*   SW Version           : 3.0.0
*   Build Version        : S32K3_RTD_3_0_0_D2303_ASR_REL_4_7_REV_0000_20230331
*
*   Copyright 2022 NXP
*
*   NXP Confidential. This software is owned or controlled by NXP and may only be
*   used strictly in accordance with the applicable license terms. By expressly
*   accepting such terms or by downloading, installing, activating and/or otherwise
*   using the software, you are agreeing that you have read, and that you agree to
*   comply with and are bound by, such license terms. If you do not agree to be
*   bound by the applicable license terms, then you may not retain, install,
*   activate or otherwise use the software.
==================================================================================================*/

#ifndef DPGA_IP_TYPES_H
#define DPGA_IP_TYPES_H

/**
*   @file
*
*   @addtogroup dpga_ip
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
#include "Dpga_Ip_CfgDefines.h"

/*==================================================================================================
*                                 SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define DPGA_IP_VENDOR_ID_TYPES                    43
#define DPGA_IP_MODULE_ID_TYPES                    255
#define DPGA_IP_AR_RELEASE_MAJOR_VERSION_TYPES     4
#define DPGA_IP_AR_RELEASE_MINOR_VERSION_TYPES     7
#define DPGA_IP_AR_RELEASE_REVISION_VERSION_TYPES  0
#define DPGA_IP_SW_MAJOR_VERSION_TYPES             3
#define DPGA_IP_SW_MINOR_VERSION_TYPES             0
#define DPGA_IP_SW_PATCH_VERSION_TYPES             0

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and Dpga_Ip_CfgDefines header file are of the same vendor */
#if (DPGA_IP_VENDOR_ID_TYPES != DPGA_IP_VENDOR_ID_CFGDEFINES)
    #error "Dpga_Ip_Types.h and Dpga_Ip_CfgDefines.h have different vendor ids"
#endif

/* Check if current file and Dpga_Ip_CfgDefines header file are of the same Autosar version */
#if ((DPGA_IP_AR_RELEASE_MAJOR_VERSION_TYPES     != DPGA_IP_AR_RELEASE_MAJOR_VERSION_CFGDEFINES) || \
     (DPGA_IP_AR_RELEASE_MINOR_VERSION_TYPES     != DPGA_IP_AR_RELEASE_MINOR_VERSION_CFGDEFINES) || \
     (DPGA_IP_AR_RELEASE_REVISION_VERSION_TYPES  != DPGA_IP_AR_RELEASE_REVISION_VERSION_CFGDEFINES))
    #error "AutoSar Version Numbers of Dpga_Ip_Types.h and Dpga_Ip_CfgDefines.h are different"
#endif

/* Check if current file and Dpga_Ip_CfgDefines header file are of the same software version */
#if ((DPGA_IP_SW_MAJOR_VERSION_TYPES != DPGA_IP_SW_MAJOR_VERSION_CFGDEFINES) || \
     (DPGA_IP_SW_MINOR_VERSION_TYPES != DPGA_IP_SW_MINOR_VERSION_CFGDEFINES) || \
     (DPGA_IP_SW_PATCH_VERSION_TYPES != DPGA_IP_SW_PATCH_VERSION_CFGDEFINES))
    #error "Software Version Numbers of Dpga_Ip_Types.h and Dpga_Ip_CfgDefines.h are different"
#endif

/*==================================================================================================
*                                            CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/

/*==================================================================================================
*                                              ENUMS
==================================================================================================*/
/**
* @brief Dpga Ip Status
*
*/
typedef enum
{
    DPGA_IP_STATUS_SUCCESS      = 0x000U,
    DPGA_IP_STATUS_ERROR        = 0x001U,
    DPGA_IP_STATUS_TIMEOUT      = 0x002U,
    DPGA_IP_STATUS_BUSY         = 0x003U,
    DPGA_IP_STATUS_UNSUPPORTED  = 0x004U
} Dpga_Ip_StatusType;

/**
* @brief Events which can trigger DPGA notification callback.
*
*/
typedef enum
{
    DPGA_IP_AMP_PARITY_CHECK_EVENT      = 0x00U,
    DPGA_IP_BT_PARITY_CHECK_EVENT       = 0x01U
#if (STD_ON == DPGA_IP_ENABLE_VOLTAGE_MONITORING)
,
    DPGA_IP_LOW_VOLTAGE_DETECT_EVENT    = 0x02U,
    DPGA_IP_HIGH_VOLTAGE_DETECT_EVENT   = 0x03U
#endif
} Dpga_Ip_EventType;

/*==================================================================================================
*                                  STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/
/**
* @brief Callback used for DPGA module notifications.
*        Possible notifications: low/high voltage detect, parity check.
*
*/
typedef void (*Dpga_Ip_CallbackType)(Dpga_Ip_EventType Event);

/**
* @brief Differential Amplifier configuration structure
*
* This structure is used to provide the configuration parameters for the Differential Amplifier
*
*/
typedef struct
{
    uint8 AmplifierGain;                /**< The gain of the Amplifier */
    uint8 OutCommonModeVoltage;         /**< Common Mode Voltage of the output of the Amplifier */
    uint8 AmplifierOffset;              /**< Amplifier offset  */
    uint8 InCommonModeCoarse;           /**< The common mode of the differential inputs of the Amplifier */
    uint8 InCommonModeFine;             /**< Adjust the common mode of the differential inputs of the amplifier */
} Dpga_Ip_AmplifierConfigType;

/**
* @brief Dpga Ip module configuration structure
*
* This structure is used to provide the configuration parameters for the Dpga Ip module.
*
*/
typedef struct
{
    Dpga_Ip_AmplifierConfigType * AmplifierConfig;          /**< Pointer to the Amplifier Config structure */
    uint8 BlankingTimeDuration;                             /**< Blanking time duration, in number of module cycles */
    uint8 BTTriggerStateArray[DPGA_IP_BT_NUM_OF_TRIGGERS];  /**< State of the Blanking Time Triggers 0 - 5: on which edge to start the counter for each trigger */
#if (STD_ON == DPGA_IP_ENABLE_VOLTAGE_MONITORING)
    boolean BipolarInputModeEnable;                         /**< If true, the full voltage swing on the input is to be measured */
    uint8 LowDetectLimit;                                   /**< When the output of the differential amplifier is lower than the limit defined here,
                                                                 a high detect event is generated. The LD limit is (1 + LowDetectLimit) / 64 if the supply voltage. */
    uint8 HighDetectLimit;                                  /**< When the output of the differential amplifier is higher than the limit defined here,
                                                                 a high detect event is generated. The HD limit is (48 + HighDetectLimit) / 64 if the supply voltage. */
    uint16 LowDetectFilterDuration;                         /**< The minimal time duration that the low detect event must be active before the low detect output flag is set.
                                                                 The value written here + 1 is the minimal time duration in number of module clock cycles. */
    uint16 HighDetectFilterDuration;                        /**< The minimal time duration that the high detect event must be active before the high detect output flag is set.
                                                                 The value written here + 1 is the minimal time duration in number of module clock cycles. */
#endif /* (STD_ON == DPGA_IP_ENABLE_VOLTAGE_MONITORING) */
    Dpga_Ip_CallbackType DpgaCallback;                      /**< Dpga callback function. This will be called for all Dpga events. */
} Dpga_Ip_ConfigType;

/*==================================================================================================
*                                  GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                       FUNCTION PROTOTYPES
==================================================================================================*/


#ifdef __cplusplus
}
#endif

/** @} */

#endif /* DPGA_IP_TYPES_H */
