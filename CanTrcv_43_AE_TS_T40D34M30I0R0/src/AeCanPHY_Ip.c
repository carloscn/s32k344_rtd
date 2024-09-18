/*==================================================================================================
*   Project              : RTD AUTOSAR 4.7
*   Platform             : CORTEXM
*   Peripheral           : AE
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
/*==================================================================================================
==================================================================================================*/
/**
* @file         CanTrcv_43_AE.c
* @version      3.0.0
*
* @brief        AUTOSAR CanTrcv_43_AE - module interface
* @details      API implementation for CanTrcv driver.
*
*
* @addtogroup   CANTRCV_DRIVER
* @{
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
#include "AeCanPHY_Ip.h"
#include "AeCanPHY_HwAccess.h"
#include "AeCanPHY_Ip_CfgDefines.h"
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/

/*==================================================================================================
                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/
#define AE_CANPHY_CANPHY_CFG_REG_ADDR                  (0x70U)
#define AE_CANPHY_CANPHY_MONITOR_REG_ADDR              (0x74U)

#define AE_CANPHY_PMC_CONFIG_REG_ADDR                  (0x100U)
#define AE_CANPHY_PMC_MONITOR_REG_ADDR                 (0x104U)
#define AE_CANPHY_RSTGEN_CFG_REG_ADDR                  (0x44U)
/*==================================================================================================
                                       LOCAL CONSTANTS
==================================================================================================*/
#define CANTRCV_43_AE_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "CanTrcv_43_AE_MemMap.h"

static const AeCanPHY_Ip_ConfigType * AeCanPHY_pState[1U];

#define CANTRCV_43_AE_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "CanTrcv_43_AE_MemMap.h"
/*==================================================================================================
                                       LOCAL VARIABLES
==================================================================================================*/

/*==================================================================================================
                                       GLOBAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
                                       GLOBAL VARIABLES
==================================================================================================*/

/*==================================================================================================
                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/

/*==================================================================================================
                                       LOCAL FUNCTIONS
==================================================================================================*/

/*==================================================================================================
                                       GLOBAL FUNCTIONS
==================================================================================================*/

/*================================================================================================*/
#define CANTRCV_43_AE_START_SEC_CODE
#include "CanTrcv_43_AE_MemMap.h"

AeCanPHY_Ip_StatusType AeCanPHY_Ip_Init(uint8 HwChannel, const AeCanPHY_Ip_ConfigType * Config)
{
    uint32 Command = 0U;
    AeCanPHY_Ip_StatusType RetVal = AE_CANPHY_STATUS_FAILED;
    uint32 template;

    /* Enable VDDC for CAN PHY */
    RetVal = AeCanPHY_ReadRegisterViaSpi(&(Config->SpiConfig), AE_CANPHY_PMC_CONFIG_REG_ADDR, &template, 32U);
    if (AE_CANPHY_STATUS_SUCCESS != RetVal)
    {
        return RetVal;
    }
    /* enable VDDC */
    template |= 8U;
    RetVal = AeCanPHY_WriteRegisterViaSpi(&(Config->SpiConfig), AE_CANPHY_PMC_CONFIG_REG_ADDR, template, 32U);
    if (AE_CANPHY_STATUS_SUCCESS != RetVal)
    {
        return RetVal;
    }

    /* Enable CAN PHY */
    template = 0U;
    RetVal = AeCanPHY_ReadRegisterViaSpi(&(Config->SpiConfig), AE_CANPHY_RSTGEN_CFG_REG_ADDR, &template, 16U);
    if (AE_CANPHY_STATUS_SUCCESS != RetVal)
    {
        return RetVal;
    }
    /* Activate CAN_PHY */
    template |= 2U;
    RetVal = AeCanPHY_WriteRegisterViaSpi(&(Config->SpiConfig), AE_CANPHY_RSTGEN_CFG_REG_ADDR, template, 16U);
    if (AE_CANPHY_STATUS_SUCCESS != RetVal)
    {
        return RetVal;
    }

    /* Clear LVCDF flag */
    template = 0U;
    RetVal = AeCanPHY_ReadRegisterViaSpi(&(Config->SpiConfig), AE_CANPHY_PMC_MONITOR_REG_ADDR, &template, 32U);
    if (AE_CANPHY_STATUS_SUCCESS != RetVal)
    {
        return RetVal;
    }
    /* To not impact to other W1C, 'Write 1 to set/clear' flags */
    template &= ~(0x0000FFFF);
    /* clear LVCDF for CANPHY */
    template |= 0x08U;
    RetVal = AeCanPHY_WriteRegisterViaSpi(&(Config->SpiConfig), AE_CANPHY_PMC_MONITOR_REG_ADDR, template, 32U);
    if (AE_CANPHY_STATUS_SUCCESS != RetVal)
    {
        return RetVal;
    }

    /* Enable Transceiver */
    Command = AEC_AE_CANPHY_CFG_CANPHY_ENABLE_MASK;

    /* Set mode for Transceiver */
    Command |= (uint32)Config->DeviceModeAfterInit;

    /* Write to CANPHY_CFG register */
    RetVal = AeCanPHY_WriteRegisterViaSpi(&(Config->SpiConfig), AE_CANPHY_CANPHY_CFG_REG_ADDR, Command, 16U);

    if (AE_CANPHY_STATUS_SUCCESS == RetVal)
    {
        AeCanPHY_pState[HwChannel] = Config;
    }

    return RetVal;
}

AeCanPHY_Ip_StatusType AeCanPHY_Ip_SetMode(uint8 HwChannel, AeCanPHY_Ip_TransceiverModeType Mode)
{
    uint32 Command = 0U;
    AeCanPHY_Ip_StatusType RetVal = AE_CANPHY_STATUS_FAILED;
    const AeCanPHY_Ip_ConfigType * State = AeCanPHY_pState[HwChannel];

    Command = AEC_AE_CANPHY_CFG_CANPHY_ENABLE_MASK;

    /* Set mode for Transceiver */
    Command |= (uint32)Mode;

    /* Write to CANPHY_CFG register */
    RetVal = AeCanPHY_WriteRegisterViaSpi(&(State->SpiConfig), AE_CANPHY_CANPHY_CFG_REG_ADDR, Command, 16U);

    return RetVal;
}

AeCanPHY_Ip_StatusType AeCanPHY_Ip_GetMode(uint8 HwChannel, AeCanPHY_Ip_TransceiverModeType * Mode)
{
    uint32 Data = 0U;
    AeCanPHY_Ip_StatusType RetVal = AE_CANPHY_STATUS_FAILED;
    const AeCanPHY_Ip_ConfigType * State = AeCanPHY_pState[HwChannel];

    RetVal = AeCanPHY_ReadRegisterViaSpi(&(State->SpiConfig), AE_CANPHY_CANPHY_CFG_REG_ADDR, &Data, 16U);

    if (AE_CANPHY_STATUS_SUCCESS == RetVal)
    {
        /* Get mode for Transceiver */
        *Mode = (AeCanPHY_Ip_TransceiverModeType)(Data & AEC_AE_CANPHY_CFG_MODE_MASK);
    }

    return RetVal;
}

AeCanPHY_Ip_StatusType AeCanPHY_Ip_GetEventStatusFlag(uint8 HwChannel, uint32 * Event)
{
    uint32 Data = 0U;
    AeCanPHY_Ip_StatusType RetVal = AE_CANPHY_STATUS_FAILED;
    const AeCanPHY_Ip_ConfigType * State = AeCanPHY_pState[HwChannel];

    RetVal = AeCanPHY_ReadRegisterViaSpi(&(State->SpiConfig), AE_CANPHY_CANPHY_MONITOR_REG_ADDR, &Data, 16U);

    if (AE_CANPHY_STATUS_SUCCESS == RetVal)
    {
        /* Get all events for Transceiver */
        *Event = Data & (AEC_AE_CANPHY_MONITOR_CANPHY_INVALIDSTATE_FL_MASK | AEC_AE_CANPHY_MONITOR_CANPHY_TXDOMTIMEDOUT_FL_MASK | AEC_AE_CANPHY_MONITOR_CANPHY_WKUP_FL_MASK);
    }

    return RetVal;
}

AeCanPHY_Ip_StatusType AeCanPHY_Ip_ClearEventStatusFlag(uint8 HwChannel, AeCanPHY_Ip_TransceiverEventType Event)
{
    uint32 Command = 0U;
    AeCanPHY_Ip_StatusType RetVal = AE_CANPHY_STATUS_FAILED;
    const AeCanPHY_Ip_ConfigType * State = AeCanPHY_pState[HwChannel];

    RetVal = AeCanPHY_ReadRegisterViaSpi(&(State->SpiConfig), AE_CANPHY_CANPHY_MONITOR_REG_ADDR, &Command, 16U);

    if (AE_CANPHY_STATUS_SUCCESS == RetVal)
    {
        Command &= ~(AEC_AE_CANPHY_MONITOR_CANPHY_INVALIDSTATE_FL_MASK |
                    AEC_AE_CANPHY_MONITOR_CANPHY_TXDOMTIMEDOUT_FL_MASK |
                    AEC_AE_CANPHY_MONITOR_CANPHY_WKUP_FL_MASK);

        switch (Event)
        {
            case AE_CANPHY_WKUP_EVENT:
            {
                Command |= AEC_AE_CANPHY_MONITOR_CANPHY_WKUP_FL_MASK;
                break;
            }
            case AE_CANPHY_INVALID_STATE_EVENT:
            {
                Command |= AEC_AE_CANPHY_MONITOR_CANPHY_INVALIDSTATE_FL_MASK;
                break;
            }
            case AE_CANPHY_TXDOM_TIMEDOUT_EVENT:
            {
                Command |= AEC_AE_CANPHY_MONITOR_CANPHY_TXDOMTIMEDOUT_FL_MASK;
                break;
            }
            default:
                break;
        }

        /* Write to CANPHY_CFG register */
        RetVal = AeCanPHY_WriteRegisterViaSpi(&(State->SpiConfig), AE_CANPHY_CANPHY_MONITOR_REG_ADDR, Command, 16U);
    }

    return RetVal;
}

AeCanPHY_Ip_StatusType AeCanPHY_Ip_SetEventNotification(uint8 HwChannel, AeCanPHY_Ip_TransceiverEventType Event, boolean IsEnable)
{
    uint32 Command = 0U;
    AeCanPHY_Ip_StatusType RetVal = AE_CANPHY_STATUS_FAILED;
    const AeCanPHY_Ip_ConfigType * State = AeCanPHY_pState[HwChannel];

    RetVal = AeCanPHY_ReadRegisterViaSpi(&(State->SpiConfig), AE_CANPHY_CANPHY_MONITOR_REG_ADDR, &Command, 16U);

    if (AE_CANPHY_STATUS_SUCCESS == RetVal)
    {
        Command &= ~(AEC_AE_CANPHY_MONITOR_CANPHY_INVALIDSTATE_FL_MASK |
                    AEC_AE_CANPHY_MONITOR_CANPHY_TXDOMTIMEDOUT_FL_MASK |
                    AEC_AE_CANPHY_MONITOR_CANPHY_WKUP_FL_MASK);

        switch (Event)
        {
            case AE_CANPHY_WKUP_EVENT:
            {
                Command |= AEC_AE_CANPHY_MONITOR_CANPHY_WKUP_EN(IsEnable);
                break;
            }
            case AE_CANPHY_INVALID_STATE_EVENT:
            {
                Command |= AEC_AE_CANPHY_MONITOR_CANPHY_INVALIDSTATE_EN(IsEnable);
                break;
            }
            case AE_CANPHY_TXDOM_TIMEDOUT_EVENT:
            {
                Command |= AEC_AE_CANPHY_MONITOR_CANPHY_TXDOMTIMEDOUT_EN(IsEnable);
                break;
            }
            default:
                break;
        }
        /* Write to CANPHY_CFG register */
        RetVal = AeCanPHY_WriteRegisterViaSpi(&(State->SpiConfig), AE_CANPHY_CANPHY_MONITOR_REG_ADDR, Command, 16U);
    }

    return RetVal;
}

AeCanPHY_Ip_StatusType AeCanPHY_Ip_DeInit(uint8 HwChannel)
{
    AeCanPHY_Ip_StatusType RetVal = AE_CANPHY_STATUS_FAILED;
    const AeCanPHY_Ip_ConfigType * State = AeCanPHY_pState[HwChannel];
    uint32 Command = 0U;

    /* Write reset value to CANPHY_CFG register */
    RetVal = AeCanPHY_WriteRegisterViaSpi(&(State->SpiConfig), AE_CANPHY_CANPHY_CFG_REG_ADDR, Command, 16U);

    if (AE_CANPHY_STATUS_SUCCESS == RetVal)
    {
        /* clear all event flags */
        Command = (AEC_AE_CANPHY_MONITOR_CANPHY_INVALIDSTATE_FL_MASK |
                    AEC_AE_CANPHY_MONITOR_CANPHY_TXDOMTIMEDOUT_FL_MASK |
                    AEC_AE_CANPHY_MONITOR_CANPHY_WKUP_FL_MASK);
        /* Write reset value to CANPHY_CFG register */
        RetVal = AeCanPHY_WriteRegisterViaSpi(&(State->SpiConfig), AE_CANPHY_CANPHY_MONITOR_REG_ADDR, Command, 16U);
    }

    if (AE_CANPHY_STATUS_SUCCESS == RetVal)
    {
        AeCanPHY_pState[HwChannel] = NULL_PTR;
    }

    return RetVal;
}

#define CANTRCV_43_AE_STOP_SEC_CODE
#include "CanTrcv_43_AE_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */
