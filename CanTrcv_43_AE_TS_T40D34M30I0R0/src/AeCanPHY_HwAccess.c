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
#include "Ae.h"
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

/*==================================================================================================
                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/

/*==================================================================================================
                                       LOCAL FUNCTIONS
==================================================================================================*/

/*==================================================================================================
                                       GLOBAL FUNCTIONS
==================================================================================================*/
#define CANTRCV_43_AE_START_SEC_CODE
#include "CanTrcv_43_AE_MemMap.h"

AeCanPHY_Ip_StatusType AeCanPHY_WriteRegisterViaSpi(const AeCanPHY_Ip_SpiConfigType * SpiConfig, uint16 RegAddr, uint32 writeData, uint8 Size)
{
    AeCanPHY_Ip_StatusType RetVal = AE_CANPHY_STATUS_FAILED;
    uint8 SpiTxCnt = 0U;

    do
    {
        if (E_OK == Ae_WriteRegister(RegAddr, Size, writeData))
        {
            RetVal = AE_CANPHY_STATUS_SUCCESS;
        }
        else
        {
            RetVal = AE_CANPHY_STATUS_ERR_SPI;
        }

        SpiTxCnt++;
    }
    while ((AE_CANPHY_STATUS_SUCCESS != RetVal) && (SpiTxCnt < (SpiConfig->SpiCommRetries)));

    return RetVal;
}

AeCanPHY_Ip_StatusType AeCanPHY_ReadRegisterViaSpi(const AeCanPHY_Ip_SpiConfigType * SpiConfig, uint16 RegAddr, uint32 * rxData, uint8 Size)
{
    AeCanPHY_Ip_StatusType RetVal = AE_CANPHY_STATUS_FAILED;
    uint8 SpiTxCnt = 0U;
    uint32 data = 0U;

    do
    {
        if (E_OK == Ae_ReadRegister(RegAddr, Size, &data))
        {
            *rxData = data;
            RetVal = AE_CANPHY_STATUS_SUCCESS;
        }
        else
        {
            RetVal = AE_CANPHY_STATUS_ERR_SPI;
        }

        SpiTxCnt++;
    }
    while ((AE_CANPHY_STATUS_SUCCESS != RetVal) && (SpiTxCnt < (SpiConfig->SpiCommRetries)));

    return RetVal;
}

#define CANTRCV_43_AE_STOP_SEC_CODE
#include "CanTrcv_43_AE_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */
