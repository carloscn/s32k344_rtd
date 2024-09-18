/*==================================================================================================
*   Project              : RTD AUTOSAR 4.7
*   Platform             : CORTEXM
*   Peripheral           : IPV_GDU
*   Dependencies         : none
*
*   Autosar Version      : 4.7.0
*   Autosar Revision     : ASR_REL_4_7_REV_0000
*   Autosar Conf.Variant :
*   SW Version           : 3.0.0
*   Build Version        : S32K3_RTD_3_0_0_D2303_ASR_REL_4_7_REV_0000_20230331
*
*   (c) Copyright 2020 - 2023 NXP Semiconductors
*   All Rights Reserved.
*
*   NXP Confidential. This software is owned or controlled by NXP and may only be
*   used strictly in accordance with the applicable license terms. By expressly
*   accepting such terms or by downloading, installing, activating and/or otherwise
*   using the software, you are agreeing that you have read, and that you agree to
*   comply with and are bound by, such license terms. If you do not agree to be
*   bound by the applicable license terms, then you may not retain, install,
*   activate or otherwise use the software.
==================================================================================================*/

#ifndef GDU_IP_TYPES_H
#define GDU_IP_TYPES_H

/**
*   @file    Gdu_Ip_Types.h
*   @version 3.0.0
*
*   @brief   AUTOSAR Gdu - IPV_GDU type definitions.
*
*   @addtogroup IPV_GDU
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
#include "StandardTypes.h"
#include "Gdu_Ip_CfgDefines.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define GDU_IP_TYPES_VENDOR_ID                    43
#define GDU_IP_TYPES_MODULE_ID                    123
#define GDU_IP_TYPES_AR_RELEASE_MAJOR_VERSION     4
#define GDU_IP_TYPES_AR_RELEASE_MINOR_VERSION     7
#define GDU_IP_TYPES_AR_RELEASE_REVISION_VERSION  0
#define GDU_IP_TYPES_SW_MAJOR_VERSION             3
#define GDU_IP_TYPES_SW_MINOR_VERSION             0
#define GDU_IP_TYPES_SW_PATCH_VERSION             0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if current file and StandardTypes.h header file are of the same Autosar version */
    #if ((GDU_IP_TYPES_AR_RELEASE_MAJOR_VERSION != STD_AR_RELEASE_MAJOR_VERSION) || \
         (GDU_IP_TYPES_AR_RELEASE_MINOR_VERSION != STD_AR_RELEASE_MINOR_VERSION) \
        )
        #error "Autosar Version Numbers of Gdu_Ip_Types.h and StandardTypes.h are different"
    #endif
#endif

#if (GDU_IP_TYPES_VENDOR_ID != GDU_IP_CFGDEFINES_VENDOR_ID)
#error "Gdu_Ip_Types.h and Gdu_Ip_CfgDefines.h have different vendor ids"
#endif
#if ((GDU_IP_TYPES_AR_RELEASE_MAJOR_VERSION    != GDU_IP_CFGDEFINES_AR_RELEASE_MAJOR_VERSION) || \
     (GDU_IP_TYPES_AR_RELEASE_MINOR_VERSION    != GDU_IP_CFGDEFINES_AR_RELEASE_MINOR_VERSION) || \
     (GDU_IP_TYPES_AR_RELEASE_REVISION_VERSION != GDU_IP_CFGDEFINES_AR_RELEASE_REVISION_VERSION))
#error "AutoSar Version Numbers of Gdu_Ip_Types.h and Gdu_Ip_CfgDefines.h are different"
#endif
#if ((GDU_IP_TYPES_SW_MAJOR_VERSION != GDU_IP_CFGDEFINES_SW_MAJOR_VERSION) || \
     (GDU_IP_TYPES_SW_MINOR_VERSION != GDU_IP_CFGDEFINES_SW_MINOR_VERSION) || \
     (GDU_IP_TYPES_SW_PATCH_VERSION != GDU_IP_CFGDEFINES_SW_PATCH_VERSION))
#error "Software Version Numbers of Gdu_Ip_Types.h and Gdu_Ip_CfgDefines.h are different"
#endif

/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/

/*==================================================================================================
*                                             ENUMS
==================================================================================================*/

/** The significance of each return code is explained in the function descriptions */
typedef enum
{
    GDU_IP_STATUS_OK,
    GDU_IP_STATUS_ERROR,
    GDU_IP_STATUS_INVALID,
    GDU_IP_STATUS_ERRORCONDITION
} Gdu_Ip_StatusType;

/** Controls GDUEN */
typedef enum
{
    GDU_IP_MODE_MIN = -1,           /**< lower boundary for consecutive enumerators */
    GDU_IP_MODE_ENABLE,             /**< GDU is enabled                             */
    GDU_IP_MODE_DISABLE,            /**< GDU is disabled                            */
    GDU_IP_MODE_MAX                 /**< upper boundary for consecutive enumerators */
} Gdu_Ip_ModeType;

/** Controls SSTEN */
typedef enum
{
    GDU_IP_SAFESTATE_MIN = -1,      /**< lower boundary for consecutive enumerators */
    GDU_IP_SAFESTATE_ON,            /**< put the GDU in safe state                  */
    GDU_IP_SAFESTATE_OFF,           /**< pull the GDU out from safe state           */
    GDU_IP_SAFESTATE_MAX            /**< upper boundary for consecutive enumerators */
} Gdu_Ip_SafeStateType;

/** Enumeration of the input PWM channels */
typedef enum
{
    GDU_IP_PWM_CHANNEL_MIN = -1,    /**< lower boundary for consecutive enumerators */
    GDU_IP_PWM_CHANNEL_0,           /**< input PWM channel 0                        */
    GDU_IP_PWM_CHANNEL_1,           /**< input PWM channel 1                        */
    GDU_IP_PWM_CHANNEL_2,           /**< input PWM channel 2                        */
    GDU_IP_PWM_CHANNEL_3,           /**< input PWM channel 3                        */
    GDU_IP_PWM_CHANNEL_4,           /**< input PWM channel 4                        */
    GDU_IP_PWM_CHANNEL_5,           /**< input PWM channel 5                        */
    GDU_IP_PWM_CHANNEL_MAX          /**< upper boundary for consecutive enumerators */
} Gdu_Ip_PwmChannelType;

/** Enumeration of a signal's edge types */
typedef enum
{
    GDU_IP_EDGE_MIN = -1,           /**< lower boundary for consecutive enumerators */
    GDU_IP_EDGE_RISING,             /**< rising edge                                */
    GDU_IP_EDGE_FALLING,            /**< falling edge                               */
    GDU_IP_EDGE_MAX                 /**< upper boundary for consecutive enumerators */
} Gdu_Ip_EdgeType;

/** Enumeration of slew rate configuration registers */
typedef enum
{
    GDU_IP_SLEWRATE_MIN = -1,       /**< lower boundary for consecutive enumerators */
    GDU_IP_SLEWRATE_HS_ON,          /**< HSSRON register                            */
    GDU_IP_SLEWRATE_HS_OFF,         /**< HSSROFF register                           */
    GDU_IP_SLEWRATE_LS_ON,          /**< LSSRON register                            */
    GDU_IP_SLEWRATE_LS_OFF,         /**< LSSROFF register                           */
    GDU_IP_SLEWRATE_MAX             /**< upper boundary for consecutive enumerators */
} Gdu_Ip_SlewRateSelectType;

/** Enumeration of the possible trimming percentages */
typedef enum
{
    GDU_IP_IREF_TRIM_MIN = -1,      /**< lower boundary for consecutive enumerators */
    GDU_IP_IREF_TRIM_000,           /**< 62.5% (minimum current)                    */
    GDU_IP_IREF_TRIM_001,           /**< 75%                                        */
    GDU_IP_IREF_TRIM_010,           /**< 87.5%                                      */
    GDU_IP_IREF_TRIM_011,           /**< 100% (10 μA at nominal process)            */
    GDU_IP_IREF_TRIM_100,           /**< 112.5%                                     */
    GDU_IP_IREF_TRIM_101,           /**< 125%                                       */
    GDU_IP_IREF_TRIM_110,           /**< 137.5%                                     */
    GDU_IP_IREF_TRIM_111,           /**< 150% (maximum current)                     */
    GDU_IP_IREF_TRIM_MAX            /**< upper boundary for consecutive enumerators */
} Gdu_Ip_IrefTrimType;

enum
{
    GDU_ICOIL_0,
    GDU_ICOIL_1,
    GDU_ICOIL_2,
    GDU_ICOIL_3,
    GDU_ICOIL_4,
    GDU_ICOIL_5,
    GDU_ICOIL_6,
    GDU_ICOIL_7
};

enum
{
    GDU_DUTY_CYCLE_1_DIV_2,
    GDU_DUTY_CYCLE_1_DIV_4,
    GDU_DUTY_CYCLE_3_DIV_4
};

enum
{
    GDU_DS_FILTER_200ns,
    GDU_DS_FILTER_600ns,
    GDU_DS_FILTER_1000ns,
    GDU_DS_FILTER_1400ns
};

enum
{
    GDU_DS_LEVEL_150mV,
    GDU_DS_LEVEL_250mV,
    GDU_DS_LEVEL_350mV,
    GDU_DS_LEVEL_450mV,
    GDU_DS_LEVEL_700mV,
    GDU_DS_LEVEL_950mV,
    GDU_DS_LEVEL_1200mV,
    GDU_DS_LEVEL_1450mV
};

enum
{
    GDU_CP_DISCHARGE_250ns,
    GDU_CP_DISCHARGE_500ns,
    GDU_CP_DISCHARGE_750ns,
    GDU_CP_DISCHARGE_1000ns
};

/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/
/** The configuration structure follows the layout of the register set structure */
typedef GDU_AE_Type Gdu_Ip_ConfigType;

/** Type definition for the notification function */
typedef void (*Gdu_Ip_NotificationType) (
    uint32 InterruptFlags
);

/**
 * Structure containing bit-fields for each of the possible error conditions found in the INTF register.
 *
 * Is it ok to define single-bit fields as boolean? It's important that they do not have a signed bit:
 * boolean is defined in PlatformTypes.h as either unsigned char or bool, so the following extract
 * from the C99 standard applies if the members are defined as bool:
 * "If the value 0 or 1 is stored into a nonzero-width bit-field of type _Bool, the value of the
 * bit-field shall compare equal to the value stored."
 */
typedef struct
{
    boolean DesaturationLS0 : 1;
    boolean DesaturationLS1 : 1;
    boolean DesaturationLS2 : 1;
    boolean DesaturationHS0 : 1;
    boolean DesaturationHS1 : 1;
    boolean DesaturationHS2 : 1;
    boolean HighVoltageHD   : 1;
} Gdu_Ip_ErrorStatusType;

/** Structure type that maps to one of the registers below; they contain configuration values
 *  for the slew rate of the gate driver signals that correspond to:
 *  - HSSRON: FETs on the high side (valid for the turn on part)
 *  - HSSROFF: FETs on the high side (valid for the turn off part)
 *  - LSSRON: FETs on the low side (valid for the turn on part)
 *  - LSSROFF: FETs on the low side (valid for the turn off part)
 */
typedef struct
{
    uint8 TimePoint1;
    uint8 TimePoint2;
    uint8 Slew1;
    uint8 Slew2;
    uint8 Slew3;
} Gdu_Ip_SlewRateConfigType;

typedef struct
{
    Gdu_Ip_IrefTrimType LG0;
    Gdu_Ip_IrefTrimType HG0;
    Gdu_Ip_IrefTrimType LG1;
    Gdu_Ip_IrefTrimType HG1;
    Gdu_Ip_IrefTrimType LG2;
    Gdu_Ip_IrefTrimType HG2;
} Gdu_Ip_IrefTrimmingType;

/** Structure containing off state diagnostics settings */
typedef struct
{
    boolean PullHs0Down : 1;    /**< Pull down HS0  */
    boolean PullHs1Down : 1;    /**< Pull down HS1  */
    boolean PullHs2Down : 1;    /**< Pull down HS2  */
    boolean PullHs0Up : 1;      /**< Pull up HS0    */
    boolean PullHs1Up : 1;      /**< Pull up HS1    */
    boolean PullHs2Up : 1;      /**< Pull up HS2    */
} Gdu_Ip_OffStateDiagType;

#ifdef __cplusplus
}
#endif

/** @} */

#endif /* GDU_IP_TYPES_H */
