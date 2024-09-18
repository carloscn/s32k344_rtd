/*
*   (c) Copyright 2020 NXP
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
#include "Lin_43_LPUART_FLEXIO.h"
#include "LinTrcv_43_AE.h"
#include "Ae.h"
#include "LinTrcv_43_AE_Types.h"
#include "Port.h"
#include "Spi.h"
#include "Platform.h"
#include "OsIf.h"
#if (LIN_43_LPUART_FLEXIO_FLEXIO_USED == STD_ON)
#include "Mcl.h"
#endif
#include "check_example.h"

/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/


/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/
#define T_LINTRCV_NETWORK       (uint8)0U
#define LIN_MASTER_RESPONSE LIN_FRAMERESPONSE_TX
#define T_LIN_TEST_NUM_CHANNELS ((uint8)1U)
#define T_LIN_TEST_FRM_NUM      ((uint8)1U)
#define T_LIN_TIME_OUT 400000

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
uint8 T_Lin_Data[3] = {0x01, 0x02, 0x03};

const Lin_PduType T_Lin_Frame[T_LIN_TEST_FRM_NUM] =
{
    {0x1A, LIN_ENHANCED_CS, LIN_MASTER_RESPONSE, 3u, T_Lin_Data}
};
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
* @brief        Main function of the example
* @details      A LIN Master sends a LIN Frame  ( header + response )
*/
int main(void)
{
    LinTrcv_TrcvModeType TempOpMode;
    static uint8 linSdu[8] = {0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0};
    volatile Lin_StatusType T_LinStatus;
    volatile uint32 TimeOut;
    uint8 Index_frame = 0;
    Lin_PduType linFrame;
    const uint8* linSduPtr = linSdu;
    volatile uint8 T_result = 0;
    uint8 Channel_Index = 0;

    /* Init system clock */
    Mcu_Init(NULL_PTR);

    /* Initialize the clock tree and apply PLL as system clock */
    Mcu_InitClock(McuClockSettingConfig_0);
#if (MCU_NO_PLL == STD_OFF)
    while ( MCU_PLL_LOCKED != Mcu_GetPllStatus() )
    {
        /* Busy wait until the System PLL is locked */
    }
    Mcu_DistributePllClock();
#endif
    Mcu_SetMode(McuModeSettingConf_0);

    /* Configure output pins */
    Port_Init(NULL_PTR);

    /* Configure LPSI in sync mode */
    Spi_Init(NULL_PTR);

    /* Init Ae */
    Ae_Init(NULL_PTR);

    /* Install interrupt handlers using the Platform driver */
    Platform_Init(NULL_PTR);

    /* Init osif */
    OsIf_Init(NULL_PTR);
#if (LIN_43_LPUART_FLEXIO_FLEXIO_USED == STD_ON)
    Mcl_Init(NULL_PTR);
#endif
    /* Initialize LINTRCV module */
    LinTrcv_43_AE_Init(NULL_PTR);
    /* Call LinTrcv_SetOpMode to switch mode to Normal */
    (void)LinTrcv_43_AE_SetOpMode(T_LINTRCV_NETWORK, LINTRCV_TRCV_MODE_NORMAL);
    /* Call LinTrcv_GetOpMode to get current mode */
    (void)LinTrcv_43_AE_GetOpMode(T_LINTRCV_NETWORK, &TempOpMode);

    /* Initialize LIN module */
    Lin_43_LPUART_FLEXIO_Init(NULL_PTR);

    for (Channel_Index = 0; Channel_Index < T_LIN_TEST_NUM_CHANNELS; Channel_Index++)
    {
        /* Wakeup LIN channels for ASR 4.3.1 */
        Lin_43_LPUART_FLEXIO_WakeupInternal(Channel_Index);
        /* Check Lin channel wakeup */
        Lin_43_LPUART_FLEXIO_CheckWakeup(Channel_Index);

        /* Get frame data */
        linFrame = T_Lin_Frame[Index_frame];

        /* Send LIN frame */
        Lin_43_LPUART_FLEXIO_SendFrame(Channel_Index, &linFrame);

        /* Wait for the transmission done */
        TimeOut = 4*T_LIN_TIME_OUT;
        do {
            T_LinStatus = Lin_43_LPUART_FLEXIO_GetStatus(Channel_Index, &linSduPtr);
        } while (LIN_TX_OK != T_LinStatus && 0 != TimeOut--);

        /* Verify that the LIN frame is sent successfully */
        if (LIN_TX_OK == T_LinStatus)
        {
            T_result = T_result + 1;
        }
    }

    Exit_Example(((T_LIN_TEST_FRM_NUM * T_LIN_TEST_NUM_CHANNELS) == T_result) && (LINTRCV_TRCV_MODE_NORMAL == TempOpMode));
    return (0U);
}


#ifdef __cplusplus
}
#endif

/** @} */
