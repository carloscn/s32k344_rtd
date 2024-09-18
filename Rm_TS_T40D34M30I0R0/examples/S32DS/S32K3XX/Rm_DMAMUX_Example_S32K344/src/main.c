/*
*   (c) Copyright 2023 NXP
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

#include "CDD_Rm.h"
#include "Mcal.h"
#include "Osif.h"
#include "Mcu.h"
#include "Platform.h"
#include "Gpt.h"
#include "Port.h"
#include "Dio.h"
#include "CDD_Mcl.h"
#include "check_example.h"
#include "Dma_Ip_Hw_Access.h"
#include "Derivative_Cfg.h"
/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/


/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/
#define DMA_CH0_CONFIG_LIST_DIMENSION      ((uint32)2U)

#define DMA_CH0_BUFFER_DIMENSION           ((uint32)24U)
#define DMA_CH0_CONFIG_LIST_DIMENSION      ((uint32)2U)

#define DMA_IRQ_NOT_TRIGGERED              ((uint32)0U)
#define DMA_IRQ_TRIGGERED_ONCE             ((uint32)1U)

#define TRIGGER_COUNT                      ((uint16)10U)
#define TIMEOUT_PERIOD                     ((uint32)300000U)

#define GPT_CHANNEL_0                      ((uint8)0U)
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
volatile uint32 g_DmaCh0_CallbackCounter = 0U;
volatile uint32 g_DmaCh0_ErrorCallbackCounter = 0U;

volatile uint16 index1 = 0U;
volatile uint16 index2 = 0U;
volatile uint16 flag = 0U;
/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/
Std_ReturnType CHECK_Uint8_BufferCompare(uint8 * pSource, uint8 * pDestination, uint32 Length);

/*==================================================================================================
*                                       LOCAL FUNCTIONS

==================================================================================================*/
/**
* @brief        DMA ch0 callback
* @details      Notification callback for DMA transfer channel 0
*/
void Mcl_Ch0Callback(void)
{
    g_DmaCh0_CallbackCounter++;
}

/**
* @brief        DMA error callback
* @details      Notification callback for DMA error transfer
*/
void Mcl_Ch0ErrorCallback(void)
{
    g_DmaCh0_ErrorCallbackCounter++;
}

/**
* @brief        Gpt notification called by the configured channel periodically
* @details      Pit notification callback
*/
void Gpt_PitNotification(void)
{
    ++index1;
    flag++;
}

/**
* @brief        PIT_0 Interrupt handler
* @details      Defined in Pit_Gpt_Ip.c
*/
extern ISR(PIT_ISR_USED);

/**
* @brief        Buffer compare function
* @details      Buffer compare function
*/
Std_ReturnType CHECK_Uint8_BufferCompare(uint8 * pSource, uint8 * pDestination, uint32 Length)
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
/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/

/**
* @brief        Main function of the example
* @details      Example uses RM_init to configure DMA MUX to perform data transfers from the source array to the destination array.
*               Depending on the configuration of RM, the source module can use the correspond DMA channel correctly.
*               The steps are as follows:
*                 - Declare variables
*                 - Call Mcu_Init, Mcu_InitClock, Mcu_SetMode to initialize Clock
*                 - Call Mcl_Init to initialize DMA, configrue TRIGMUX
*                 - Call Rm_Init to configure DMA MUX.
*                 - Call Platform_Init to setup ISR for DMA and PIT interrupt
*                 - Call Port_Init, GPT_Init to initialize PIT, support for trigger DMA feature
*                 - Config source and destination address for DMA transfer, start request transfer to DMA
*                 - Start timer
*                 - Waiting for DMA transfer.
*                 - Verify DMA transfer successfully
*                 - Exit example
*/

int main(void)
{
#define MCL_START_SEC_VAR_INIT_UNSPECIFIED_NO_CACHEABLE
#include "Mcl_MemMap.h"
    /* DMA Logic Channel 0 Buffers */
    __attribute__(( aligned(32) )) static uint8 DmaCh0_SourceBuffer[DMA_CH0_BUFFER_DIMENSION] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23};
    __attribute__(( aligned(32) )) static uint8 DmaCh0_DestinationBuffer[DMA_CH0_BUFFER_DIMENSION];
#define MCL_STOP_SEC_VAR_INIT_UNSPECIFIED_NO_CACHEABLE
#include "Mcl_MemMap.h"

    /* DMA Logic Channel 0 Address Configuration */
    Mcl_DmaChannelTransferListType DmaCh0_TransferList[DMA_CH0_CONFIG_LIST_DIMENSION] =
    {
        {MCL_DMA_CH_SET_SOURCE_ADDRESS, (Dma_Ip_uintPtrType)&DmaCh0_SourceBuffer[0U]},
        {MCL_DMA_CH_SET_DESTINATION_ADDRESS, (Dma_Ip_uintPtrType)&DmaCh0_DestinationBuffer[0U]},
    };

    boolean Status = TRUE;
    Std_ReturnType StdStatus = E_OK;
    Mcl_DmaChannelStatusType t_GetChannel0Status;

    /* Initialize Mcu Driver */
    Mcu_Init(NULL_PTR);

    Mcu_InitClock(McuClockSettingConfig_0);
#if (MCU_NO_PLL == STD_OFF)
    while ( MCU_PLL_LOCKED != Mcu_GetPllStatus() )
    {
        /* Busy wait until the System PLL is locked */
    }
    Mcu_DistributePllClock();
#endif
    Mcu_SetMode(McuModeSettingConf_0);

    /* Initialize MCL Driver */
    Mcl_Init(NULL_PTR);

    /* Initialize RM, DMA has read/write permission */
    Rm_Init(NULL_PTR);

    /* Initialize all pins using the Port driver */
    Port_Init(NULL_PTR);

    /* Initialize Platform driver */
    Platform_Init(NULL_PTR);
    
    /* Install ISR */
    Platform_InstallIrqHandler(DMA_IRQ_NUM_USED, &DMA_ISR_USED, NULL_PTR);
    Platform_InstallIrqHandler(PIT_IRQ_NUM_USED, &PIT_ISR_USED, NULL_PTR);

    /* Initialize the Gpt driver */
    Gpt_Init(&Gpt_Config);

    /* Set Logic Channel 0 -> Source and Destination Address */
    Mcl_SetDmaChannelTransferList(DMA_LOGIC_CH_0, DmaCh0_TransferList, DMA_CH0_CONFIG_LIST_DIMENSION);
    /* Start request DMA transfer for logic Channel 0 */
    Mcl_SetDmaChannelCommand(DMA_LOGIC_CH_0, MCL_DMA_CH_START_REQUEST);

    /* Enable the Gpt notification */
    Gpt_EnableNotification(GPT_CHANNEL_0);
    /* Start the Gpt timer */
    Gpt_StartTimer(GPT_CHANNEL_0, TIMEOUT_PERIOD);

    while (TRUE)
    {
        if (flag > 0)
        {
            /* Get DMA transfer status */
            Mcl_GetDmaChannelStatus(DMA_LOGIC_CH_0, &t_GetChannel0Status);
            while(t_GetChannel0Status.Done != TRUE)
            {
                /* Return false if DMA transfer too long */
                if (index1 > TRIGGER_COUNT)
                {
                    Status = FALSE;
                    break;
                }
                Mcl_GetDmaChannelStatus(DMA_LOGIC_CH_0, &t_GetChannel0Status);
            }
            flag = 0;
            break;
        }
    }

    /* Check DMA transfered data */
    StdStatus = CHECK_Uint8_BufferCompare(DmaCh0_SourceBuffer, DmaCh0_DestinationBuffer, DMA_CH0_BUFFER_DIMENSION);
    if(E_OK != StdStatus)
    {
        Status = FALSE;
    }

    /* Stop the Gpt timer */
    Gpt_StopTimer(GPT_CHANNEL_0);

    Exit_Example(Status);
}


#ifdef __cplusplus
}
#endif

/** @} */
