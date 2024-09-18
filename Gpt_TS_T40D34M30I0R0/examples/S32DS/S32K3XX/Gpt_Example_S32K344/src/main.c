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


/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Mcu.h"
#include "Port.h"
#include "Dio.h"
#include "Gpt.h"
#include "Platform.h"

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
static volatile uint8 toggleLed = 0U;

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
* @brief        Gpt notification called by the configured channel periodically
* @details      Used to blink a led
*/
void Gpt_PitNotification(void)
{
    toggleLed = 1U;
}


/**
* @brief        Main function of the example
* @details      Initializes the used drivers and uses the Gpt
*               and Dio drivers to toggle a LED periodically
*/
int main(void)
{
    uint8 count = 0U;
    uint8 pinValue = STD_LOW;
    
    /* Init clock */
#if (STD_ON == MCU_PRECOMPILE_SUPPORT)
    Mcu_Init(NULL_PTR);
#else
    Mcu_Init(&Mcu_Config_VS_0);
#endif

#if (STD_ON == MCU_INIT_CLOCK)
    /* Initialize the clock tree and apply PLL as system clock */
    Mcu_InitClock(McuClockSettingConfig_0);

#if (STD_OFF == MCU_NO_PLL)
    while ( MCU_PLL_LOCKED != Mcu_GetPllStatus() )
    {
        /* Busy wait until the System PLL is locked */
    }
    Mcu_DistributePllClock();
#endif

    Mcu_SetMode(McuModeSettingConf_0);

#else
    #error "The Mcu Init Clock API should be enabled from the Mcu driver"
#endif

    /* Initialize all pins using the Port driver */
#if (STD_ON == PORT_PRECOMPILE_SUPPORT)
    Port_Init(NULL_PTR);
#else
    Port_Init(&Port_Config_VS_0);
#endif

    /* Initialize Platform driver */
    Platform_Init(NULL_PTR);

    /* Initialize the high level configuration structure of Gpt driver */
#if (STD_ON == GPT_PRECOMPILE_SUPPORT)
    Gpt_Init(NULL_PTR);
#else
    Gpt_Init(&Gpt_Config_VS_0);
#endif

    /* Start the Gpt timer */
    Gpt_StartTimer(GptConf_GptChannelConfiguration_GptChannelConfiguration_0, 20000000U);

    /* Enable the Gpt notification to get the event for toggling the LED periodically */
    Gpt_EnableNotification(GptConf_GptChannelConfiguration_GptChannelConfiguration_0);

    while (count < 10U)
    {
        /* Toggle the gpio pin to blink the LED when the Pit notification is called */
        if (1U == toggleLed)
        {
            count++;
            pinValue = (STD_LOW == pinValue) ? STD_HIGH : STD_LOW;
            Dio_WriteChannel(DioConf_DioChannel_Digital_Output_LED, pinValue);
            toggleLed = 0U;
        }
    }

    Gpt_StopTimer(GptConf_GptChannelConfiguration_GptChannelConfiguration_0);

    Exit_Example(TRUE);

    return (0U);
}


#ifdef __cplusplus
}
#endif

/** @} */
