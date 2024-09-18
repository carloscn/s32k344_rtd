/*
*   Copyright 2020-2022 NXP
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

/**
*   @file main.c
*
*   @addtogroup main_module main module documentation
*   @{
*/


#ifdef __cplusplus
extern "C" {
#endif

/* Including necessary configuration files. */
#include "Clock_Ip.h"
#include "IntCtrl_Ip.h"
#include "Siul2_Port_Ip.h"
#include "Lpi2c_Ip.h"
#include "Flexio_I2c_Ip.h"
#include "Flexio_Mcl_Ip.h"
#include "Lpi2c_Ip_VS_0_PBcfg.h"
#include "Flexio_I2c_Ip_VS_0_PBcfg.h"
#include "check_example.h"

volatile int exit_code = 0;

/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/

/**
* @brief        Define transfer size
*/
#define TRANSFER_SIZE 8U

/*==================================================================================================
*                                      GLOBAL VARIABLES
==================================================================================================*/

/**
* @brief        Define data buffers
*/
uint8 rxBufferMaster[TRANSFER_SIZE] = {0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0};
uint8 rxBufferSlave[TRANSFER_SIZE] = {0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0};
uint8 txBuffer[TRANSFER_SIZE] = {0x0, 0x1, 0x2, 0x3, 0x4, 0x5, 0x6, 0x7};

/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/

void I2c_SlaveCallback(Lpi2c_Ip_SlaveEventType event, uint8 userData)
{
	uint32 u32Instance = (uint32)userData;

	switch(event)
	{
	   case I2C_SLAVE_EVENT_TX_REQ:
		   Lpi2c_Ip_SlaveSetBuffer(u32Instance, txBuffer, TRANSFER_SIZE);
		   break;

	   case I2C_SLAVE_EVENT_RX_REQ:
			Lpi2c_Ip_SlaveSetBuffer(u32Instance, rxBufferSlave, TRANSFER_SIZE);
	        break;

	   default:
		   break;
	}

	/* Cast to void to avoid compiler warnings */
 	(void) userData;
}
/*!
  \brief The main function for the project.
  \details The startup initialization sequence is the following:
 * - startup asm routine
 * - main()
*/
int main(void)
{
    uint32 timeout = 0xFFFF;
	boolean checkOk = TRUE;
	uint8 i;

    /* Init clock  */
    Clock_Ip_Init(&Clock_Ip_aClockConfig[0]);
	
	/* Enable LPI2C interrupts */
    IntCtrl_Ip_Init(&IntCtrlConfig_0);

	/* Init Pins */
	Siul2_Port_Ip_Init(NUM_OF_CONFIGURED_PINS0, g_pin_mux_InitConfigArr0);

	/* Init Mcl */
	Flexio_Mcl_Ip_InitDevice(&Flexio_Ip_xFlexioInit);

	/* Init FlexIO module */
	Flexio_I2c_Ip_MasterInit(0U, FLEXIO_I2C_CHANNEL_0, &Flexio_I2cMasterChannel0_VS_0);
	
	/* Init lpi2c in slave mod */
	Lpi2c_Ip_SlaveInit(LPI2C_CHANNEL_0, &I2c_Lpi2cSlaveChannel0_VS_0);

	/* Send data non-blocking */
	Flexio_I2c_Ip_MasterSendData(0U, FLEXIO_I2C_CHANNEL_0, txBuffer, TRANSFER_SIZE, TRUE);

	/* Wait master transfer to finish */
	while(((Flexio_I2c_Ip_MasterGetStatus(0U, FLEXIO_I2C_CHANNEL_0, NULL_PTR)) == FLEXIO_I2C_IP_BUSY_STATUS) && (timeout > 0))
	{
		timeout--;
	}
	
	/* Wait slave module to finish */
	while(((Lpi2c_Ip_SlaveGetTransferStatus(LPI2C_CHANNEL_0, NULL_PTR)) == LPI2C_IP_BUSY_STATUS) && (timeout > 0))
	{
		timeout--;
	}

	/* Verify data received */
	for (i = 0; i < TRANSFER_SIZE; i++)
	{
		if( txBuffer[i] != rxBufferSlave[i])
		{
			checkOk = FALSE;
		}
	}
	
	/* Receive data non-blocking */
	Flexio_I2c_Ip_MasterReceiveData(0U, FLEXIO_I2C_CHANNEL_0, rxBufferMaster, TRANSFER_SIZE, TRUE);

	/* Wait master transfer to finish */
	while(((Flexio_I2c_Ip_MasterGetStatus(0U, FLEXIO_I2C_CHANNEL_0, NULL_PTR)) == FLEXIO_I2C_IP_BUSY_STATUS) && (timeout > 0))
	{
		timeout--;
	}
	
	/* Wait slave module to finish */
	while(((Lpi2c_Ip_SlaveGetTransferStatus(LPI2C_CHANNEL_0, NULL_PTR)) == LPI2C_IP_BUSY_STATUS) && (timeout > 0))
	{
		timeout--;
	}

	/* Verify data received */
	for (i = 0; i < TRANSFER_SIZE; i++)
	{
		if( txBuffer[i] != rxBufferMaster[i])
		{
			checkOk = FALSE;
		}
	}
    /* Check if transfer was successful */
    Exit_Example(checkOk);
    return exit_code;
}

#ifdef __cplusplus
}
#endif


/** @} */
