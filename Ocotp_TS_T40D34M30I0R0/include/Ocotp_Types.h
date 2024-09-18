
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

#ifndef OCOTP_TYPES_H
#define OCOTP_TYPES_H

/**
*   @file
*
*   @addtogroup OCOTP
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
#include "Mem_Otp_Ip_Types.h"
#include "Ocotp_Cfg.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define OCOTP_TYPES_VENDOR_ID                    43
#define OCOTP_TYPES_AR_RELEASE_MAJOR_VERSION     4
#define OCOTP_TYPES_AR_RELEASE_MINOR_VERSION     7
#define OCOTP_TYPES_AR_RELEASE_REVISION_VERSION  0
#define OCOTP_TYPES_SW_MAJOR_VERSION             3
#define OCOTP_TYPES_SW_MINOR_VERSION             0
#define OCOTP_TYPES_SW_PATCH_VERSION             0
/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
        /* Check if current file and StandardTypes header file are of the same Autosar version */
    #if ((OCOTP_TYPES_AR_RELEASE_MAJOR_VERSION != STD_AR_RELEASE_MAJOR_VERSION) || \
         (OCOTP_TYPES_AR_RELEASE_MINOR_VERSION != STD_AR_RELEASE_MINOR_VERSION) \
        )
        #error "AutoSar Version Numbers of Ocotp_Types.c and StandardTypes.h are different"
    #endif
#endif

/* Check if current file and Mem_Otp_Ip_Types.h header file are of the same vendor */
#if (OCOTP_TYPES_VENDOR_ID != MEM_OTP_IP_TYPES_VENDOR_ID)
    #error "Ocotp_Types.h and Mem_Otp_Ip_Types.h have different vendor ids"
#endif
/* Check if current file and Mem_Otp_Ip_Types.h header file are of the same AutoSar version */
#if ((OCOTP_TYPES_AR_RELEASE_MAJOR_VERSION != MEM_OTP_IP_TYPES_AR_RELEASE_MAJOR_VERSION ) || \
     (OCOTP_TYPES_AR_RELEASE_MINOR_VERSION != MEM_OTP_IP_TYPES_AR_RELEASE_MINOR_VERSION ) || \
     (OCOTP_TYPES_AR_RELEASE_REVISION_VERSION != MEM_OTP_IP_TYPES_AR_RELEASE_REVISION_VERSION) \
    )
    #error "Software Version Numbers of Ocotp_Types.h and Mem_Otp_Ip_Types.h are different"
#endif
/* Check if current file and Mem_Otp_Ip_Types.h header file are of the same Software version */
#if ((OCOTP_TYPES_SW_MAJOR_VERSION != MEM_OTP_IP_TYPES_SW_MAJOR_VERSION) || \
     (OCOTP_TYPES_SW_MINOR_VERSION != MEM_OTP_IP_TYPES_SW_MINOR_VERSION) || \
     (OCOTP_TYPES_SW_PATCH_VERSION != MEM_OTP_IP_TYPES_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Ocotp_Types.h and Mem_Otp_Ip_Types.h are different"
#endif

/* Check if current file and Ocotp_Cfg.h header file are of the same vendor */
#if (OCOTP_TYPES_VENDOR_ID != OCOTP_VENDOR_ID_CFG)
    #error "Ocotp_Types.h and Ocotp_Cfg.h have different vendor ids"
#endif
/* Check if current file and Ocotp_Cfg.h header file are of the same AutoSar version */
#if ((OCOTP_TYPES_AR_RELEASE_MAJOR_VERSION != OCOTP_AR_RELEASE_MAJOR_VERSION_CFG ) || \
     (OCOTP_TYPES_AR_RELEASE_MINOR_VERSION != OCOTP_AR_RELEASE_MINOR_VERSION_CFG ) || \
     (OCOTP_TYPES_AR_RELEASE_REVISION_VERSION != OCOTP_AR_RELEASE_REVISION_VERSION_CFG) \
    )
    #error "Software Version Numbers of Ocotp_Types.h and Ocotp_Cfg.h are different"
#endif
/* Check if current file and Ocotp_Cfg.h header file are of the same Software version */
#if ((OCOTP_TYPES_SW_MAJOR_VERSION != OCOTP_SW_MAJOR_VERSION_CFG) || \
     (OCOTP_TYPES_SW_MINOR_VERSION != OCOTP_SW_MINOR_VERSION_CFG) || \
     (OCOTP_TYPES_SW_PATCH_VERSION != OCOTP_SW_PATCH_VERSION_CFG) \
    )
    #error "Software Version Numbers of Ocotp_Types.h and Ocotp_Cfg.h are different"
#endif
/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/

/*==================================================================================================
*                                              ENUMS
==================================================================================================*/

/**
* @brief          Status of Ocotp hardware.
*/
/* @implements Ocotp_HardwareStatusType_enumeration */
typedef enum
{
    OCOTP_HARDWARE_BUSY       = 0u,         /*!< Status of hardware is busy  */
    OCOTP_HARDWARE_ERROR,                   /*!< Status of hardware is error */
    OCOTP_HARDWARE_IDLE                     /*!< Status of hardware is idle  */
}Ocotp_HardwareStatusType;
/*==================================================================================================
                                 STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/
/**
* @brief          Ocotp address type.
* @details        Adrress of a register.
*/
typedef uint32 Ocotp_AddressType;

/**
* @brief          Ocotp channel type.
* @details        An integer which is used to describe the order of channel configured.
*/
/* @implements Ocotp_ChannelType_typedef */
typedef uint8 Ocotp_ChannelType;

/**
* @brief          Ocotp channel configuration type.
* @details        A structure which is used to contain the parameters of channel used.
                  Such as address of eFuse. Index of shadow register.
*/
/* @implements Ocotp_ChannelConfigType_structure */
typedef struct
{
    uint32                  Ocotp_MirrorAddress;        /*!< Address of Mirror Register */
    uint8                   Ocotp_ChannelNumber;       /*!< Channel number */
    Ocotp_InstanceType      Ocotp_Instance;            /*!< Instance Index */
}Ocotp_ChannelConfigType;

/**
* @brief          Ocotp configuration type.
* @details        A structure which is used to contain the hardware configuration
                  and the configuration of channels used.
*/
/* @implements Ocotp_ConfigType_structure */
typedef struct
{
    const Mem_Otp_Ip_ConfigType *pHwConfig;              /*!< User configuration structure */
    const Ocotp_ChannelConfigType (*pChanelConfig)[];  /*!< Ocotp channel configuration type */
}Ocotp_ConfigType;

/**
* @brief          Ocotp status type.
* @details        A structure which is used to contain the status of hardware
                  (Busy or idle or errors occurred) and status of repair error flag(If FBXC exists).
*/
/* @implements Ocotp_StatusType_structure */
typedef struct
{
    Ocotp_HardwareStatusType   HardwareStatus;
}Ocotp_StatusType;

/*==================================================================================================
*                                  GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                       FUNCTION PROTOTYPES
==================================================================================================*/

#ifdef __cplusplus
}
#endif

/** @}*/

#endif /* OCOTP_TYPES_H */
