/*==================================================================================================
*   Project              : M4_SRC_PROJECT_NAME
*   Platform             : M4_SRC_MCU_FAMILY
*   Peripheral           : M4_SRC_USED_PERIPHERAL
*   Dependencies         : M4_SRC_AR_MODULE_DEPENDENCY
*
*   Autosar Version      : M4_SRC_AR_SPEC_VERSION_MAJOR.M4_SRC_AR_SPEC_VERSION_MINOR.M4_SRC_AR_SPEC_VERSION_PATCH
*   Autosar Revision     : M4_SRC_AR_RELEASE_REVISION
*   Autosar Conf.Variant :
*   SW Version           : M4_SRC_SW_VERSION_MAJOR.M4_SRC_SW_VERSION_MINOR.M4_SRC_SW_VERSION_PATCH
*   Build Version        : M4_SRC_BUILD_ID
*
   Copyright M4_SRC_YEAR_ID M4_SRC_COPYRIGHTED_TO
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

/**
*   @file main.c
*
*   @addtogroup main_module main module documentation
*   @{
*/

/* Including necessary configuration files. */
#include "Mcal.h"


/* User includes */
#include "OsIf.h"
#include "Flexio_Lin_Ip.h"
#include "Lpuart_Lin_Ip.h"
#include "Flexio_Mcl_Ip.h"
#include "Clock_Ip.h"
#include "IntCtrl_Ip.h"
#include "Siul2_Port_Ip.h"
#include "check_example.h"

/* Global Macros */
#define BUFFER_SIZE             (3U)
#define T_LIN_TIME_OUT          (400000U)
#define FLEXIO_PID              (0x1A)
#define LPUART_PID              (0x1A)
#define MASTER_ROLE             (0U)
#define SLAVE_ROLE              (1U)

#define FLEXIO_INSTANCE         (0U)

/* Global Variables */
uint8 FlexioTxBuff[BUFFER_SIZE] = {0x01, 0x02, 0x03};
uint8 LpuartTxBuff[BUFFER_SIZE] = {0x04, 0x05, 0x06};
//uint8 SduBuf[3U];

Lpuart_Lin_Ip_PduType LinLpuartPdu[] =
{
    {
                .Pid = (uint8)LPUART_PID,
                .Cs = LPUART_LIN_IP_ENHANCED_CS,
                .SduPtr = LpuartTxBuff,
                .Drc = LPUART_LIN_IP_FRAMERESPONSE_TX,
                .Dl = (uint8)BUFFER_SIZE
    },
    {
                .Pid = (uint8)LPUART_PID,
                .Cs = LPUART_LIN_IP_ENHANCED_CS,
                .SduPtr = NULL_PTR,
                .Drc = LPUART_LIN_IP_FRAMERESPONSE_RX,
                .Dl = (uint8)BUFFER_SIZE
    }
};

Flexio_Lin_Ip_PduType LinFlexioPdu[] =
{
    {
                .Pid = (uint8)FLEXIO_PID,
                .Cs = FLEXIO_LIN_IP_ENHANCED_CS,
                .SduPtr = FlexioTxBuff,
                .Drc = FLEXIO_LIN_IP_FRAMERESPONSE_TX,
                .Dl = (uint8)BUFFER_SIZE
    },
    {
                .Pid = (uint8)FLEXIO_PID,
                .Cs = FLEXIO_LIN_IP_ENHANCED_CS,
                .SduPtr = NULL_PTR,
                .Drc = FLEXIO_LIN_IP_FRAMERESPONSE_RX,
                .Dl = (uint8)BUFFER_SIZE
    }
};



/*!
  \brief The main function for the project.
  \details The startup initialization sequence is the following:
 * - startup asm routine
 * - main()
*/
int main(void)
{
    const uint8 *DummyBuffer;
    uint32 TimeoutValue = 0u;
    volatile Flexio_Lin_Ip_TransferStatusType FlexioMasterStatus = FLEXIO_LIN_IP_STATUS_OPERATIONAL;
    volatile Lpuart_Lin_Ip_TransferStatusType LpuartMasterStatus = LPUART_LIN_IP_STATUS_OPERATIONAL;

    /* Init clock  */
    Clock_Ip_Init(&Clock_Ip_aClockConfig[0]);

    /*Enable Flexio module */
    /* Init Flexio common Mcl  */
    Flexio_Mcl_Ip_InitDevice(&Flexio_Ip_xFlexioInit);

    /* Initialize all pins */
    Siul2_Port_Ip_Init(NUM_OF_CONFIGURED_PINS0, g_pin_mux_InitConfigArr0);

    /* Initialize IRQs */
    IntCtrl_Ip_Init(&IntCtrlConfig_0);

    /* Example for Flexio_Lin */
    /*Intialize Flexio_Lin */
    Flexio_Lin_Ip_Init(Flexio_Lin_Ip_Sa_pHwConfigPB_0_VS_0.Instance, &Flexio_Lin_Ip_Sa_pHwConfigPB_0_VS_0);

    /* Start of the sending frame from Flexio Master*/
    (void)Flexio_Lin_Ip_SendFrame(Flexio_Lin_Ip_Sa_pHwConfigPB_0_VS_0.Instance, &LinFlexioPdu[MASTER_ROLE]);

    /*Wait for the transmission done on Master*/
    TimeoutValue = 4*T_LIN_TIME_OUT;
    do
    {
        FlexioMasterStatus = Flexio_Lin_Ip_GetStatus(Flexio_Lin_Ip_Sa_pHwConfigPB_0_VS_0.Instance, (const uint8 **)&DummyBuffer);
    }
    while ((FLEXIO_LIN_IP_STATUS_TX_OK != FlexioMasterStatus) && (TimeoutValue-- > 1));


    /* Flexio over Lin driver de-initialization*/
    Flexio_Lin_Ip_Deinit(Flexio_Lin_Ip_Sa_pHwConfigPB_0_VS_0.Instance);

    /* Disable Flexio Module*/
    Flexio_Mcl_Ip_DeinitDevice(FLEXIO_INSTANCE);

    /* Example for Lpuart_Lin */

    /*Intialize Lpuart_Lin */
    Lpuart_Lin_Ip_Init(Lpuart_Lin_Ip_Sa_pHwConfigPB_0_VS_0.Instance, &Lpuart_Lin_Ip_Sa_pHwConfigPB_0_VS_0);

    /* Start of the sending frame from Lpuart Master*/
    (void)Lpuart_Lin_Ip_SendFrame(Lpuart_Lin_Ip_Sa_pHwConfigPB_0_VS_0.Instance, &LinLpuartPdu[MASTER_ROLE]);

    /*Wait for the transmission done */
    TimeoutValue = 4*T_LIN_TIME_OUT;
    do
    {
        LpuartMasterStatus = Lpuart_Lin_Ip_GetStatus(Lpuart_Lin_Ip_Sa_pHwConfigPB_0_VS_0.Instance, (const uint8 **)&DummyBuffer);
    }
    while ((LPUART_LIN_IP_STATUS_TX_OK != LpuartMasterStatus) && (TimeoutValue-- > 1));

    /* Lpuart over Lin driver de-initialization*/
    Lpuart_Lin_Ip_Deinit(Lpuart_Lin_Ip_Sa_pHwConfigPB_0_VS_0.Instance);

    /* Check status */
    Exit_Example(FLEXIO_LIN_IP_STATUS_TX_OK == FlexioMasterStatus && \
                 LPUART_LIN_IP_STATUS_TX_OK == LpuartMasterStatus);

    return (0);

}

/** @} */
