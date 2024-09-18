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
   (c) Copyright 2020 - 2023 NXP Semiconductors
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

/**
*   @file   LinTrcv_43_AE_Ipw.c
*   
*   @internal 
*   @addtogroup LINTRCV_43_AE_IPW
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

#include "LinTrcv_43_AE_Ipw.h"
#include "OsIf.h"
#include "LinIf.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/

#define LINTRCV_43_AE_IPW_VENDOR_ID_C                    43
#define LINTRCV_43_AE_IPW_AR_RELEASE_MAJOR_VERSION_C     4
#define LINTRCV_43_AE_IPW_AR_RELEASE_MINOR_VERSION_C     7
#define LINTRCV_43_AE_IPW_AR_RELEASE_REVISION_VERSION_C  0
#define LINTRCV_43_AE_IPW_SW_MAJOR_VERSION_C             3
#define LINTRCV_43_AE_IPW_SW_MINOR_VERSION_C             0
#define LINTRCV_43_AE_IPW_SW_PATCH_VERSION_C             0

/*==================================================================================================
*                                      FILE VERSION CHECKS
==================================================================================================*/
/* Checks against LinTrcv_43_AE_Ipw.h */
#if (LINTRCV_43_AE_IPW_VENDOR_ID_C != LINTRCV_43_AE_IPW_VENDOR_ID)
    #error "LinTrcv_43_AE_Ipw.c and LinTrcv_43_AE_Ipw.h have different vendor ids"
#endif
/* Check if current file and LinTrcv_43_AE_Ipw header file are of the same Autosar version */
#if ((LINTRCV_43_AE_IPW_AR_RELEASE_MAJOR_VERSION_C    != LINTRCV_43_AE_IPW_AR_RELEASE_MAJOR_VERSION) || \
     (LINTRCV_43_AE_IPW_AR_RELEASE_MINOR_VERSION_C    != LINTRCV_43_AE_IPW_AR_RELEASE_MINOR_VERSION) || \
     (LINTRCV_43_AE_IPW_AR_RELEASE_REVISION_VERSION_C != LINTRCV_43_AE_IPW_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of LinTrcv_43_AE_Ipw.c and LinTrcv_43_AE_Ipw.h are different"
#endif
/* Check if current file and LinTrcv_43_AE_Ipw header file are of the same Software version */
#if ((LINTRCV_43_AE_IPW_SW_MAJOR_VERSION_C != LINTRCV_43_AE_IPW_SW_MAJOR_VERSION) || \
     (LINTRCV_43_AE_IPW_SW_MINOR_VERSION_C != LINTRCV_43_AE_IPW_SW_MINOR_VERSION) || \
     (LINTRCV_43_AE_IPW_SW_PATCH_VERSION_C != LINTRCV_43_AE_IPW_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of LinTrcv_43_AE_Ipw.c and LinTrcv_43_AE_Ipw.h are different"
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if current file and OsIf.h header file are of the same Autosar version */
    #if ((LINTRCV_43_AE_IPW_AR_RELEASE_MAJOR_VERSION_C != OSIF_AR_RELEASE_MAJOR_VERSION) || \
         (LINTRCV_43_AE_IPW_AR_RELEASE_MINOR_VERSION_C != OSIF_AR_RELEASE_MINOR_VERSION) \
        )
        #error "AutoSar Version Numbers of LinTrcv_43_AE_Ipw.c and OsIf.h are different"
    #endif
    /* Check if current file and LinTrcvIf.h header file are of the same Autosar version */
    #if ((LINTRCV_43_AE_IPW_AR_RELEASE_MAJOR_VERSION_C != LINIF_AR_RELEASE_MAJOR_VERSION) || \
         (LINTRCV_43_AE_IPW_AR_RELEASE_MINOR_VERSION_C != LINIF_AR_RELEASE_MINOR_VERSION) \
        )
        #error "AutoSar Version Numbers of LinTrcv_43_AE_Ipw.c and LinIf.h are different"
    #endif
#endif

/*==================================================================================================
*                           LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL VARIABLES
==================================================================================================*/
#define LINTRCV_43_AE_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "LinTrcv_43_AE_MemMap.h"
/**
* @brief          Global configuration array.
* @details        Array containing channel configurations.
*/
static const LinTrcv_43_AE_HwConfigType *LinTrcv_43_AE_Ipw_apChannelsConfig[LINTRCV_43_AE_HW_MAX_MODULES];

#define LINTRCV_43_AE_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "LinTrcv_43_AE_MemMap.h"
/*==================================================================================================
*                                       GLOBAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       GLOBAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                       GLOBAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       GLOBAL VARIABLES
==================================================================================================*/
#define LINTRCV_43_AE_START_SEC_VAR_CLEARED_8
#include "LinTrcv_43_AE_MemMap.h"

/**
* @brief          LINTRCV channel state variable.
* @details        LINTRCV channel state machine.
*/
extern uint8 LinTrcv_43_AE_au8LinTrcvChStatus[LINTRCV_43_AE_HW_MAX_MODULES];

#define LINTRCV_43_AE_STOP_SEC_VAR_CLEARED_8
#include "LinTrcv_43_AE_MemMap.h"
/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/

/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/
#define LINTRCV_43_AE_START_SEC_CODE
#include "LinTrcv_43_AE_MemMap.h"

/* LinTrcv_43_AE_Ipw_InitChannel */

void LinTrcv_43_AE_Ipw_InitChannel(uint8 LinNetwork, const LinTrcv_43_AE_HwConfigType* ChannelConfigPtr)
{
    uint8 HwUnit = ChannelConfigPtr->LinTrcvHwChannel;
    const AeLinPhy_LinTrcv_Ip_UserConfigType *TempPointer;

    TempPointer = ChannelConfigPtr->AeLinPhyConfigPtr;
    /* Save a pointer to the channel configuration structure */
    LinTrcv_43_AE_Ipw_apChannelsConfig[LinNetwork] = ChannelConfigPtr;
    (void)AeLinPhy_LinTrcv_Ip_Init(HwUnit, TempPointer);

    /* Set LINTRCV channel state machine to LINTRCV_43_AE_CH_SLEEP_STATE */
    (void)AeLinPhy_LinTrcv_Ip_SetMode(HwUnit, AELINPHY_LINTRCV_IP_STANDBY_MODE);
}
/* LinTrcv_43_AE_Ipw_SetOpMode */
Std_ReturnType  LinTrcv_43_AE_Ipw_SetOpMode(uint8 LinNetwork, LinTrcv_TrcvModeType OpMode)
{
    Std_ReturnType TempReturn = E_NOT_OK;
    AeLinPhy_LinTrcv_Ip_StatusType Retval = AELINPHY_LINTRCV_IP_STATUS_ERROR;
    uint8 HwUnit = LinTrcv_43_AE_Ipw_apChannelsConfig[LinNetwork]->LinTrcvHwChannel;
    
    /* Map the modes supported by hw to modes of autosar */
    switch (OpMode)
    {
        case LINTRCV_TRCV_MODE_NORMAL:
        {
            Retval = AeLinPhy_LinTrcv_Ip_SetMode(HwUnit, AELINPHY_LINTRCV_IP_NORMAL_MODE);
            break;
        }
        case LINTRCV_TRCV_MODE_STANDBY:
        case LINTRCV_TRCV_MODE_SLEEP:
        {
            Retval = AeLinPhy_LinTrcv_Ip_SetMode(HwUnit, AELINPHY_LINTRCV_IP_STANDBY_MODE);
            break;
        }
        default:
            break;
    }
    /* Set mode is successful, then set TempReturn to E_OK */
    if (AELINPHY_LINTRCV_IP_STATUS_SUCCESS == Retval)
    {
        TempReturn = E_OK;
    }
    
    return TempReturn;
}

/* LinTrcv_43_AE_Ipw_GetOpMode */
Std_ReturnType  LinTrcv_43_AE_Ipw_GetOpMode(uint8 LinNetwork, LinTrcv_TrcvModeType * OpMode)
{
    Std_ReturnType TempReturn = E_NOT_OK;
    uint8 HwUnit = LinTrcv_43_AE_Ipw_apChannelsConfig[LinNetwork]->LinTrcvHwChannel;
    AeLinPhy_LinTrcv_Ip_StatusType Retval = AELINPHY_LINTRCV_IP_STATUS_ERROR;
    AeLinPhy_LinTrcv_Ip_TransceiverModeType TransceiverMode;
    
    Retval = AeLinPhy_LinTrcv_Ip_GetMode(HwUnit, &TransceiverMode);
    
    if (AELINPHY_LINTRCV_IP_STATUS_SUCCESS == Retval)
    {
        switch (TransceiverMode)
        {
            case AELINPHY_LINTRCV_IP_NORMAL_MODE:
            {
                *OpMode = LINTRCV_TRCV_MODE_NORMAL;
                break;
            }
            case AELINPHY_LINTRCV_IP_STANDBY_MODE:
            {
                if ((LINTRCV_TRCV_MODE_SLEEP == LinTrcv_43_AE_au8LinTrcvChStatus[LinNetwork]))
                {   
                    *OpMode = LINTRCV_TRCV_MODE_SLEEP;
                }
                else
                {
                    *OpMode = LINTRCV_TRCV_MODE_STANDBY;
                }
                break;
            }
            default:
                break;
        }
        
        TempReturn = E_OK;
    }
    
    return TempReturn;
}

/* LinTrcv_43_AE_Ipw_SetWakeupMode */
Std_ReturnType  LinTrcv_43_AE_Ipw_SetWakeupMode(uint8 LinNetwork, LinTrcv_TrcvWakeupModeType TrcvWakupMode)
{
    Std_ReturnType TempReturn = E_NOT_OK;
    uint8 HwUnit = LinTrcv_43_AE_Ipw_apChannelsConfig[LinNetwork]->LinTrcvHwChannel;
    AeLinPhy_LinTrcv_Ip_StatusType Retval = AELINPHY_LINTRCV_IP_STATUS_ERROR;
    
    switch (TrcvWakupMode)
    {
        case LINTRCV_WUMODE_ENABLE:
        {
            Retval = AeLinPhy_LinTrcv_Ip_SetWakeupMode(HwUnit, AELINPHY_LINTRCV_IP_WUMODE_ENABLE);
            break;
        }
        case LINTRCV_WUMODE_DISABLE:
        {
            Retval = AeLinPhy_LinTrcv_Ip_SetWakeupMode(HwUnit, AELINPHY_LINTRCV_IP_WUMODE_DISABLE);
            break;
        }
        case LINTRCV_WUMODE_CLEAR:
        {
            Retval = AeLinPhy_LinTrcv_Ip_SetWakeupMode(HwUnit, AELINPHY_LINTRCV_IP_WUMODE_CLEAR);
            break;
        }
        default:
            break;
    }
    
    /* Set mode is successful, then set TempReturn to E_OK */
    if (AELINPHY_LINTRCV_IP_STATUS_SUCCESS == Retval)
    {
        TempReturn = E_OK;
    }
    
    return TempReturn;
}

/* LinTrcv_43_AE_Ipw_CheckWakeup */
Std_ReturnType LinTrcv_43_AE_Ipw_CheckWakeup(uint8 LinNetwork)
{
    Std_ReturnType TempReturn = E_NOT_OK;
    uint8 HwUnit = LinTrcv_43_AE_Ipw_apChannelsConfig[LinNetwork]->LinTrcvHwChannel;
    AeLinPhy_LinTrcv_Ip_StatusType Retval = AELINPHY_LINTRCV_IP_STATUS_ERROR;
    
    Retval = AeLinPhy_LinTrcv_Ip_CheckWakeupFlag(HwUnit);
    /* If wakeup pulse is detected, set TempReturn to E_OK */
    if (AELINPHY_LINTRCV_IP_STATUS_SUCCESS == Retval)
    {
        TempReturn = E_OK;
    }
    
    return TempReturn;
}
#define LINTRCV_43_AE_STOP_SEC_CODE
#include "LinTrcv_43_AE_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */
