/*
*   Copyright 2022 NXP
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
#include "Port.h"
#include "Dio.h"
#include "Icu.h"
#include "Mcl.h"
#include "Mcu.h"
#include "Platform.h"

#include "check_example.h"

/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/


/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/
#define NUM_MAX_BLINK         50U

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
volatile uint8 UserCountIrqCH0;
volatile uint8 BlinkCount;

/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/


/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/


/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/
extern ISR(EMIOS0_5_IRQ);

void delay(void)
{
    volatile uint32 count = 4200000U;
    while(count > 0)
    {
        count--;
    }
}
void User_EdgeDetect0(void)
{
    /* increment IRQ counter */
    UserCountIrqCH0++;
    if(UserCountIrqCH0 % 2 == 0)
    {
        Dio_WriteChannel(DioConf_DioChannel_Digital_Output_LED_D39, STD_HIGH);
    }
    else
    {
        Dio_WriteChannel(DioConf_DioChannel_Digital_Output_LED_D39, STD_LOW);
    }
}

/**
* @brief        Main function of the example
* @details      Initialize the used drivers and uses the Icu
*               and Dio drivers to toggle a LED on a push button
*/
int main(void) 
{   
    /* Init clock */
#if (STD_ON == MCU_PRECOMPILE_SUPPORT)
    Mcu_Init(NULL_PTR);
#else
    Mcu_Init(&Mcu_Config_VS_0);
#endif
    /* Initialize the clock tree */
    Mcu_InitClock(McuClockSettingConfig_0);
    /* Apply a mode configuration */
    Mcu_SetMode(McuModeSettingConf_0);
    
    /* Initialize Platform driver */
    Platform_Init(NULL_PTR);
    /* Install Emios ISR */
    Platform_InstallIrqHandler(EMIOS0_5_IRQn, &EMIOS0_5_IRQ, NULL_PTR);
    Platform_SetIrq(EMIOS0_5_IRQn,TRUE);

    /* Initialize all pins using the Port driver */
    Port_Init(NULL_PTR); 
    
    /* Initialize all pins using the Port driver */
    Mcl_Init(NULL_PTR); 

    /* Initialize the Icu driver */
    Icu_Init(NULL_PTR);
    UserCountIrqCH0 = 0U;
    BlinkCount = 0U;

    Icu_EnableEdgeDetection(IcuChannel_0);
    Icu_EnableNotification(IcuChannel_0);

    while (BlinkCount < NUM_MAX_BLINK)
    {
        if(BlinkCount % 2 == 0)
        {
            Dio_WriteChannel(DioConf_DioChannel_Port_pin_InputForIcuChannel0, STD_HIGH);
            delay();
        }
        else
        {
            Dio_WriteChannel(DioConf_DioChannel_Port_pin_InputForIcuChannel0, STD_LOW);
            delay();
        }
        BlinkCount++;
    }
    
    Exit_Example(TRUE);
    
    return (0U);
}

#ifdef __cplusplus
}
#endif

/** @} */
