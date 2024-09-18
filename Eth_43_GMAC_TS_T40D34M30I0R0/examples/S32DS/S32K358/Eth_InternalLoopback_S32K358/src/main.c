/*
*   (c) Copyright M4_SRC_YEAR_ID M4_SRC_COPYRIGHTED_TO
*   All Rights Reserved.
*
*   NXP Confidential. This software is owned or controlled by NXP and may only be used strictly
*   in accordance with the applicable license terms.  By expressly accepting
*   such terms or by downloading, installing, activating and/or otherwise using
*   the software, you are agreeing that you have read, and that you agree to
*   comply with and are bound by, such license terms.  If you do not agree to
*   be bound by the applicable license terms, then you may not retain,
*   install, activate or otherwise use the software.
*
*   This file contains sample code only. It is not part of the production code deliverables.
*/

#ifdef __cplusplus
extern "C" {
#endif


/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Mcu.h"
#include "Port.h"
#include "Eth_43_GMAC.h"
#include "OsIf.h"
#include "check_example.h"

/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/


/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/

/*==================================================================================================
*                                      LOCAL CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                      LOCAL VARIABLES
==================================================================================================*/


/*==================================================================================================
*                                      GLOBAL CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                      GLOBAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/


/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/


/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/
/**
* @brief        Transmit & receive in internal loopback mode
* @details
*/
int main(void)
{
    Eth_RxStatsType RxStatus;
    Eth_BufIdxType BufferIndex;
    uint8 *PayloadBuffer;
    uint16 PayloadLength;
    uint8 Gmac_0_MacAddr[6U] = {0};
    Eth_RxStatusType Status = ETH_NOT_RECEIVED;
    boolean Pass = TRUE;

    OsIf_Init(NULL_PTR);

    /* Initialize all pins using the Port driver */
    Port_Init(NULL_PTR);

    /* Initialize the Mcu driver */
    Mcu_Init(NULL_PTR);

    /* Initialize the clock tree and apply PLL as system clock */
    Mcu_InitClock(McuClockSettingConfig_0);

    Mcu_SetMode(McuModeSettingConf_0);

    Eth_43_GMAC_Init(NULL_PTR);

    Eth_43_GMAC_SetControllerMode(EthConf_EthCtrlConfig_EthCtrlConfig_0, ETH_MODE_ACTIVE);

    Eth_43_GMAC_ProvideTxBuffer(EthConf_EthCtrlConfig_EthCtrlConfig_0, 0U, &BufferIndex, &PayloadBuffer, &PayloadLength);

    Eth_43_GMAC_GetPhysAddr(EthConf_EthCtrlConfig_EthCtrlConfig_0, Gmac_0_MacAddr);

    Eth_43_GMAC_Transmit(EthConf_EthCtrlConfig_EthCtrlConfig_0, BufferIndex, (Eth_FrameType)46U, TRUE, 46U, Gmac_0_MacAddr);

    Eth_43_GMAC_TxConfirmation(EthConf_EthCtrlConfig_EthCtrlConfig_0);

    while (RxStatus.RxStatsPkts < 1U)
    {
        Eth_43_GMAC_GetRxStats(EthConf_EthCtrlConfig_EthCtrlConfig_0, &RxStatus);
    }
    
    Eth_43_GMAC_Receive(EthConf_EthCtrlConfig_EthCtrlConfig_0, 0U, &Status);

    if (ETH_RECEIVED != Status)
    {
        Pass = FALSE;
    }

    Eth_43_GMAC_SetControllerMode(EthConf_EthCtrlConfig_EthCtrlConfig_0, ETH_MODE_DOWN);

    Exit_Example(Pass);

    return 0;
}


#ifdef __cplusplus
}
#endif

/** @} */
