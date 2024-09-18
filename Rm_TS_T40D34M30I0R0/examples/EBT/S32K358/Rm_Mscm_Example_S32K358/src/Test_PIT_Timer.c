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
#include "Test_PIT_Timer.h"

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
* @brief        Trigger Timer Interrupt
* @details      
*/
void TriggerInterrupt(uint8 u8IrqNumber)
{
    switch(u8IrqNumber)
    {
        case T_DISABLE_IRQn:
            Pit_TriggerInterrupt(T_DISABLE_PIT, T_PIT_CHANNEL, T_COUNT_VALUE);
            break;
        case T_ENABLE_IRQn:
            Pit_TriggerInterrupt(T_ENABLE_PIT, T_PIT_CHANNEL, T_COUNT_VALUE);
            break;
        default :
            break;
    }
}

/**
* @brief        Initialization of PIT timer
* @details      
*/
void Pit_TriggerInterrupt(PIT_Type *base, uint8 channel, uint32 period)
{
    /* Enable timer */
    base->MCR = 0x00;
    
    /* Set the channel period */
    base->TIMER[channel].LDVAL = period;
    base->TIMER[channel].TFLG |= PIT_TFLG_TIF_MASK;
    
    /* Disable timer */
    base->TIMER[channel].TCTRL &= ~PIT_TCTRL_TEN_MASK;
    /* Enable interrupt to generate one interrupt */
    base->TIMER[channel].TCTRL |= PIT_TCTRL_TIE_MASK;
    
    /* Start channel */
    base->TIMER[channel].TCTRL |= PIT_TCTRL_TEN_MASK;

    /* Wait till interrupt flag is set */
    while( !((base->TIMER[channel].TFLG & PIT_TFLG_TIF_MASK) == 1UL) );
    
    /* Clear the Timer Interrupt flag */
    base->TIMER[channel].TFLG = PIT_TFLG_TIF_MASK;
    base->TIMER[channel].TCTRL &= ~PIT_TCTRL_TEN_MASK;
}

/**
* @brief        Clear Interrupt Pending PIT Timer
* @details      
*/
void PIT_ClearInterruptPending(uint8 u8IrqNumber)
{
	/* Clear Pending Interrupt */
    IntCtrl_Ip_ClearPending(u8IrqNumber);
	
	/* Disable channel interrupts */
	switch(u8IrqNumber)
	{
		case T_DISABLE_IRQn:
			T_DISABLE_PIT->TIMER[T_PIT_CHANNEL].TCTRL &= ~PIT_TCTRL_TIE_MASK;
			break;
		case T_ENABLE_IRQn:
			T_ENABLE_PIT->TIMER[T_PIT_CHANNEL].TCTRL &= ~PIT_TCTRL_TIE_MASK;
			break;
		default:
			break;
	}
}

/*==================================================================================================
*                                       INTERRUPT HANDLER
==================================================================================================*/
/* PIT0 Interrupt Handler */
void PIT0_IrqHandler(void)
{
	/* Clear pending Interrupt to prevent re-isr */
    PIT_ClearInterruptPending(T_DISABLE_IRQn);
	
	/* Callback to main */
	PIT_IrqCallbackHandler();
}
/* PIT1 Interrupt Handler */
void PIT1_IrqHandler(void)
{
	/* Clear pending Interrupt to prevent re-isr */
    PIT_ClearInterruptPending(T_ENABLE_IRQn);
	
	/* Callback to main */
	PIT_IrqCallbackHandler();
}

#ifdef __cplusplus
}
#endif

/** @} */
