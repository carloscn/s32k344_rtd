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
#include "check_example.h"
#include "Test_PIT_Timer.h"
#include "Derivative_Cfg.h"
#include "sys_init.h"

/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/


/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/
#define DEFAULT_CORE            (255U)
#define WAIT_TIME               (1000UL)
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
uint8 	u8GetIntCore    = DEFAULT_CORE;
boolean b_InterruptFlag = FALSE;

/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/
/* Dummy delay function */
void Delay_Rm(volatile uint32 u32Cycles)
{
    while(u32Cycles--);
}

/**
* @brief        Get Core ID is running
* @details      
*/
uint8 Rm_GetCoreID(void)
{
    return (IP_MSCM->CPXNUM & MSCM_CPXNUM_CPN_MASK);
}

/* Default interrupt handler that to be configured */
void PIT_IrqCallbackHandler(void)
{
    /* Get current Core ID */
    u8GetIntCore = Rm_GetCoreID();
    
    /* Set Interrupt Flag */
    b_InterruptFlag = TRUE;
}

/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/

/**
* @brief        Main function of the example
* @details      
*/
int main(void) 
{
    boolean Status = TRUE;

    /* Initialize Clock, RM CDD and Platform module */
    sys_init();

    Rm_Init(NULL_PTR);
    Platform_Init(NULL_PTR);
    
    /* Trigger PIT0 Interrupt - MSCM routing DISABLE PIT0 ISR */
    TriggerInterrupt(T_DISABLE_IRQn);
    Delay_Rm(WAIT_TIME);
    
    /* Verify - No Interrupt occur */
    if ((FALSE != b_InterruptFlag) || (DEFAULT_CORE != u8GetIntCore))
    {
        Status = FALSE;
    }
        
    /* Trigger PIT1 Interrupt - MSCM routing ENABLE PIT0 ISR */
    TriggerInterrupt(T_ENABLE_IRQn);
    Delay_Rm(WAIT_TIME);
    
    /* Verify - Interrupt occurs, interrupt flag is set and get current core */
    if ((TRUE != b_InterruptFlag) || (TEST_CORE != u8GetIntCore))
    {
        Status = FALSE;
    }
    
    Exit_Example(Status);
    return (0U);
}


#ifdef __cplusplus
}
#endif

/** @} */
