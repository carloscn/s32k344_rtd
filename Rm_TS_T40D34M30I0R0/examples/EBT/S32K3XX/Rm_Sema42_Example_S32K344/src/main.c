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
#include "sys_init.h"
#include "CDD_Rm.h"
#include "CDD_Mcl.h"
#include "check_example.h"

/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/


/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/
#define DATA_LENGTH                        	(16U)
#define DMA_CH0_CONFIG_LIST_DIMENSION      	((uint32)2U)
#define TEST_TIMEOUT                       	((uint32)1000U)
/*==================================================================================================
*                                      LOCAL CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                      LOCAL VARIABLES
==================================================================================================*/
uint8 Src_data[DATA_LENGTH]  = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16};
uint8 Dest_data[DATA_LENGTH] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

/*==================================================================================================
*                                      GLOBAL CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                      GLOBAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/
void App_Initialize(void);
void SyncDataFromCache(uint32 Address, uint32 Length);
void DMA_StartTransfer(uint8 DMA_Channel, uint32 Src_Addr, uint32 Dest_Addr);
boolean DMA_WaitCptTransfer(uint8 DMA_Channel);
Std_ReturnType CompareTransferData(uint8 * pSource, uint8 * pDestination, uint32 Length);

/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/
/* Dummy delay function */
void Delay_Rm(volatile uint32 u32Cycles)
{
    while(u32Cycles--);
}

/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/

/**
* @brief        Main function of the example
* @details      Rm_Init to init Domain0 (CM7_0) and Domain1 (DMA) and provide both of them access to SRAM with Semaphore validation enable.
*               Rm_Init also enable Sema42.
*               Try to lock gate 1 of Sema42 instance 0 with Domain0, DMA can not transfer.
*               Reset all Sema42 gates, data is transfered successfully
*/
int main(void) 
{
    boolean Status 		= TRUE;
	boolean DMA_Status 	= FALSE;
    uint32 i;

    /* Initialize the needed module for Application */
    App_Initialize();

    /* Lock Logical channel 1 of Sema42. Domain0 will owns Sema42 Logical channel 0*/
    Rm_SemaphoreLockGate(RM_SEMA42_LOGIC_CH_0);

    /* Use DMA to transfer data from array Src_data to Dest_data. DMA belongs to domain 1, cannot transfer */
	DMA_StartTransfer(DMA_LOGIC_CH_0, (uint32)&Src_data[0U], (uint32)&Dest_data[0]);

	/* Wait DMA Transfer Complete or Timeout occurs */
    DMA_Status = DMA_WaitCptTransfer(DMA_LOGIC_CH_0);

	/* Check Transfer Status if FALSE */
	if (DMA_Status != FALSE)
	{
		Status = FALSE;
	}

    /* Check data is not transfered successfully */
    for (i=0; i< DATA_LENGTH; i++)
    {
        if(Dest_data[i] != 0)
        {
            Status = FALSE;
        }
    }

    /*Reset all gates then lock Logical channel 0 of Sema42 to achive write access to SRAM*/
    Rm_SemaphoreUnlockGate(RM_SEMA42_LOGIC_CH_0);

    /* Use DMA to transfer data from array Src_data to Dest_data */
    DMA_StartTransfer(DMA_LOGIC_CH_0, (uint32)&Src_data[0U], (uint32)&Dest_data[0]);
	
	/* Wait DMA Transfer Complete or Timeout occurs */
    DMA_Status = DMA_WaitCptTransfer(DMA_LOGIC_CH_0);

	/* Invalidate Cache to get data from cache to memory */
	SyncDataFromCache((uint32)&Dest_data[0], DATA_LENGTH);

	/* Check Transfer Status if true */
	if (DMA_Status != TRUE)
	{
		Status = FALSE;
	}

    /* Check data is transfered successfully */
    for (i=0; i< DATA_LENGTH; i++)
    {
        if(Dest_data[i] != Src_data[i])
        {
            Status = FALSE;
        }    
    }

    Exit_Example(Status);

    return (0U);
}


/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/
void App_Initialize(void)
{
	/* Initialize Clock for all module */
	sys_init();
	
    /* Initialize Mcu Driver */
    Mcl_Init(NULL_PTR);
	
    /* Initialize RM, DMA has read/write permission */
    Rm_Init(NULL_PTR);
}

void SyncDataFromCache(uint32 Address, uint32 Length)
{
#ifdef MCL_CACHE_IS_AVAILABLE
	#if (STD_ON == MCL_CACHE_IS_AVAILABLE)
	Mcl_CacheInvalidateByAddr(MCL_CACHE_CORE, MCL_CACHE_DATA, (uint32)Address, (uint32)Length);
	#endif	/* (STD_ON == MCL_CACHE_IS_AVAILABLE) */
#endif	/* MCL_CACHE_IS_AVAILABLE */
}

void DMA_StartTransfer(uint8 DMA_Channel, uint32 Src_Addr, uint32 Dest_Addr)
{
	/* Clear error for Channel 0 */
    Mcl_SetDmaChannelCommand(DMA_Channel, MCL_DMA_CH_ACK_ERROR);
	
	/* DMA Logic Address Configuration */
	Mcl_DmaChannelTransferListType DmaCh0_TransferList[DMA_CH0_CONFIG_LIST_DIMENSION] =
	{
		{MCL_DMA_CH_SET_SOURCE_ADDRESS, (uint32)Src_Addr},
		{MCL_DMA_CH_SET_DESTINATION_ADDRESS, (uint32)Dest_Addr},
	};
	
    /* Set Logic Channel 0 -> Source and Destination Address */
    Mcl_SetDmaChannelTransferList(DMA_Channel, DmaCh0_TransferList, DMA_CH0_CONFIG_LIST_DIMENSION);

    /* Start transfer for logic Channel 0 */
    Mcl_SetDmaChannelCommand(DMA_Channel, MCL_DMA_CH_START_SERVICE);
}

/**
 * Return TRUE if Transfer Successfully
 * Return FALSE if Transfer NOT Successfully - Timeout 
 */
boolean DMA_WaitCptTransfer(uint8 DMA_Channel)
{
	Mcl_DmaChannelStatusType DmaTransferStatus;
    uint32 TestTime = 0U;
	DmaTransferStatus.Done = FALSE;

    /* Get Dma transfer status or wait Timeout occur */
    do
    {
        Mcl_GetDmaChannelStatus(DMA_Channel, &DmaTransferStatus);
        TestTime++;
    } while(DmaTransferStatus.Done != TRUE && TestTime < TEST_TIMEOUT);
	
	return DmaTransferStatus.Done;
}

/**
 * This function to compare Data of 2 memory Buffers
 *
 * params	pSource			Start Address of Source Buffers
 *			pDestination	Start Address of Destination Buffers
 *			Length			Size of 2 memory Buffers
 *
 * retVal	E_OK 			if 2 memory buffers have the SAME data
 *			E_NOT_OK 		if 2 memory buffers have the DIFFERENT data
 */
Std_ReturnType CompareTransferData(uint8 * pSource, uint8 * pDestination, uint32 Length)
{
    uint32 Index = 0U;

    for(Index = 0U; Index < Length; Index++)
    {
        if(pSource[Index] != pDestination[Index])
        {
            return E_NOT_OK;
        }
    }
    return E_OK;
}

#ifdef __cplusplus
}
#endif

/** @} */
