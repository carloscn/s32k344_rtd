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

/* Prevention from multiple including the same memory map */
#if !defined(TEST_PIT_TIMER_H_)  /* Check if memory map has not been already included */
#define TEST_PIT_TIMER_H_

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Platform.h"
#include "Derivative_Cfg.h"
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
#define T_PIT_CHANNEL  			(0U)
#define T_COUNT_VALUE  			(200U)

#if !defined(T_DISABLE_IRQn) || !defined(T_ENABLE_IRQn)
	#error "Must define T_ENABLE_IRQn and T_DISABLE_IRQn in Derivative_Cfg.h"
#endif

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
void TriggerInterrupt(uint8 u8IrqNumber);

/**
* @brief        Initialization of PIT timer
* @details      
*/
void Pit_TriggerInterrupt(PIT_Type *base, uint8 channel, uint32 period);

/**
* @brief        Clear Interrupt Pending PIT Timer
* @details      
*/
void PIT_ClearInterruptPending(uint8 u8IrqNumber);

/**
* @brief        PIT Interrupt Callback Handler
* @details      
*/
void PIT_IrqCallbackHandler(void);


/** @} */

#endif  /* #if !defined(TEST_PIT_TIMER_H_) */
