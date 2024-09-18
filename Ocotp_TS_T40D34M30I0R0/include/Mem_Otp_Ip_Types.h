/*==================================================================================================
*   Project              : RTD AUTOSAR 4.7
*   Platform             : CORTEXM
*   Peripheral           : MEM_OTP_IP
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

#ifndef MEM_OTP_IP_TYPES_H
#define MEM_OTP_IP_TYPES_H

/**
*   @file
*
*   @addtogroup MEM_OTP_IP
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

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define MEM_OTP_IP_TYPES_VENDOR_ID                    43
#define MEM_OTP_IP_TYPES_AR_RELEASE_MAJOR_VERSION     4
#define MEM_OTP_IP_TYPES_AR_RELEASE_MINOR_VERSION     7
#define MEM_OTP_IP_TYPES_AR_RELEASE_REVISION_VERSION  0
#define MEM_OTP_IP_TYPES_SW_MAJOR_VERSION             3
#define MEM_OTP_IP_TYPES_SW_MINOR_VERSION             0
#define MEM_OTP_IP_TYPES_SW_PATCH_VERSION             0

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
        /* Check if current file and StandardTypes header file are of the same Autosar version */
    #if ((MEM_OTP_IP_TYPES_AR_RELEASE_MAJOR_VERSION != STD_AR_RELEASE_MAJOR_VERSION) || \
         (MEM_OTP_IP_TYPES_AR_RELEASE_MINOR_VERSION != STD_AR_RELEASE_MINOR_VERSION) \
        )
        #error "AutoSar Version Numbers of Mem_Otp_Ip_Types.c and StandardTypes.h are different"
    #endif
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
 /*!
 * @brief Ocotp Ip status type.
*/
typedef enum
{
    STATUS_MEM_OTP_IP_ERROR = 0U,                 /*!< Boot Error            */
    STATUS_MEM_OTP_IP_BUSY,                       /*!< Status busy             */
    STATUS_MEM_OTP_IP_SUCCESS,                    /*!< Status success          */
    STATUS_MEM_OTP_IP_INVALID_INPUT_ADDRESS,      /*!< invalid input parameter */
    STATUS_MEM_OTP_IP_ERROR_TIMEOUT               /*!< timeout error          */
} Mem_Otp_Ip_StatusType;

/*==================================================================================================
*                                  STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/
/**
* @brief    Ocotp instance type.
* @details  An integer which describe the order of the instance configured.
*/
typedef uint8 Ocotp_InstanceType;

/**
* @brief    User configuration structure.
* @details  Structure contains the configuration parameters which will be used to initialize Ocotp module.
*/
typedef struct
{
    Ocotp_InstanceType ocotpInstance;           /*!< Ocotp instance        */
}Mem_Otp_Ip_ConfigType;
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

#endif /* MEM_OTP_IP_TYPES_H */
