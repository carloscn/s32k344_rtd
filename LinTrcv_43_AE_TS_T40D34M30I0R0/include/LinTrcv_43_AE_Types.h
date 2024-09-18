/*==================================================================================================
*   Project              : RTD AUTOSAR 4.7
*   Platform             : CORTEXM
*   Peripheral           : AE
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

#ifndef LINTRCV_43_AE_TYPES_H
#define LINTRCV_43_AE_TYPES_H

/**
*   @file    LinTrcv_43_AE_Types.h
*   @implements LinTrcv_43_AE_Types.h_Artifact
*
*   @defgroup lintrcv_driver LINTRCV Driver
*   @addtogroup  lintrcv_driver LINTRCV Driver
*   @{
*/

#ifdef __cplusplus
extern "C"
{
#endif

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "LinTrcv_43_AE_Ipw_Types.h"
#if (LINTRCV_43_AE_WAKEUP_DETECTION == STD_ON)
#include "EcuM_Externals.h"
#endif
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/

#define LINTRCV_43_AE_TYPES_VENDOR_ID                    43
#define LINTRCV_43_AE_TYPES_AR_RELEASE_MAJOR_VERSION     4
#define LINTRCV_43_AE_TYPES_AR_RELEASE_MINOR_VERSION     7
#define LINTRCV_43_AE_TYPES_AR_RELEASE_REVISION_VERSION  0
#define LINTRCV_43_AE_TYPES_SW_MAJOR_VERSION             3
#define LINTRCV_43_AE_TYPES_SW_MINOR_VERSION             0
#define LINTRCV_43_AE_TYPES_SW_PATCH_VERSION             0

/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/
/* Checks against Lin_Ipw_Types.h */
#if (LINTRCV_43_AE_TYPES_VENDOR_ID != LINTRCV_43_AE_IPW_TYPES_VENDOR_ID)
    #error "Lin_Types.h and Lin_Ipw_Types.h have different vendor ids"
#endif
#if ((LINTRCV_43_AE_TYPES_AR_RELEASE_MAJOR_VERSION    != LINTRCV_43_AE_IPW_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (LINTRCV_43_AE_TYPES_AR_RELEASE_MINOR_VERSION    != LINTRCV_43_AE_IPW_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (LINTRCV_43_AE_TYPES_AR_RELEASE_REVISION_VERSION != LINTRCV_43_AE_IPW_TYPES_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Lin_Types.h and Lin_Ipw_Types.h are different"
#endif
/* Check if current file and Lin_Ipw_Types.h header file are of the same Software version */
#if ((LINTRCV_43_AE_TYPES_SW_MAJOR_VERSION != LINTRCV_43_AE_IPW_TYPES_SW_MAJOR_VERSION) || \
     (LINTRCV_43_AE_TYPES_SW_MINOR_VERSION != LINTRCV_43_AE_IPW_TYPES_SW_MINOR_VERSION) || \
     (LINTRCV_43_AE_TYPES_SW_PATCH_VERSION != LINTRCV_43_AE_IPW_TYPES_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Lin_Types.h and Lin_Ipw_Types.h are different"
#endif
#if (LINTRCV_43_AE_WAKEUP_DETECTION == STD_ON)
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if current file and ComStackTypes header file are of the same Autosar version */
    #if ((LINTRCV_43_AE_TYPES_AR_RELEASE_MAJOR_VERSION != ECUM_CBK_AR_RELEASE_MAJOR_VERSION) || \
         (LINTRCV_43_AE_TYPES_AR_RELEASE_MINOR_VERSION != ECUM_CBK_AR_RELEASE_MINOR_VERSION) \
        )
        #error "AutoSar Version Numbers of Lin_Types.h and EcuM_Externals.h are different"
    #endif
#endif
#endif
/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/

/*==================================================================================================
                                       DEFINES AND MACROS
==================================================================================================*/

/*==================================================================================================
*                                             ENUMS
==================================================================================================*/

/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/**
* @brief          LINTRCV channel configuration type structure.
* @details        This is the type of the external data structure containing
*                 the overall initialization data for one LINTRCV Channel.
*                 A pointer to such a structure is provided to the LINTRCV channel
*                 initialization routine for configuration of the LINTRCV hardware
*                 channel.
*
*
*/
typedef struct
{
    const uint8 LinTrcvChannelID;                                       /**!< @brief Lin Channel ID */
    const LinTrcv_43_AE_HwConfigType *ChannelConfigPtr;                 /**!< @brief LINTRCV Hardware configuration pointer.*/
    const uint32 ChannelCoreId;                                         /**!< @brief LINTRCV Channel core id.*/
    const boolean AllocatedPartition;                             /**!< @brief LINTRCV Channel is allocated partition or not.*/
    const boolean LinTrcvChannelUsed;                             /**!< @brief Shall the related LIN transceiver channel be used.*/
#if (LINTRCV_43_AE_WAKEUP_DETECTION == STD_ON)
    const boolean LinTrcvWakeupByBusUsed;                         /**!< @brief Is wake up by bus supported.*/
    EcuM_WakeupSourceType LinTrcvChannelEcuMWakeupSource;         /**!< @brief This parameter contains a reference to
                                                                  the Wakeup Source for this controller as defined in the
                                                                  ECU State Manager.*/
#endif
#if (LINTRCV_43_AE_ICU_USED == STD_ON)
    const uint16 LinTrcvIcuChannel;                               /**!< @brief Reference to the IcuChannel to enable/disable the interrupts for wakeups.*/
#endif
} LinTrcv_43_AE_ChannelConfigType;

/**
* @brief          LINTRCV driver configuration type structure.
* @details        This is the type of the pointer to the external data
*                 LINTRCV Channels.
*                 A pointer of such a structure is provided to the LINTRCV driver
*                 initialization routine for configuration of the LINTRCV hardware
*                 channel.
*
*
*
* @implements LinTrcv_43_AE_ConfigType_struct
*/
typedef struct
{
    uint32 PartitionCoreId;              /**!< @brief Partition core id is assigned for this configuration */
    /**
     * @brief     Hardware channel.
     * @details   Constant pointer of the constant external data
     *            structure containing the overall initialization data
     *            for all the configured LINTRCV Channels.
     */
    const LinTrcv_43_AE_ChannelConfigType *LinTrcv_43_AE_ChannelPtr[LINTRCV_43_AE_HW_MAX_MODULES]; /**!< @brief Constant pointer to an array containing
                                                                         the configurations for the available LINTRCV channels */
} LinTrcv_43_AE_ConfigType;

/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/

/*==================================================================================================
*                                     EXTERNAL CONSTANTS
==================================================================================================*/
#ifdef __cplusplus
}
#endif

/** @} */

#endif /*LINTRCV_43_AE_TYPES_H*/
