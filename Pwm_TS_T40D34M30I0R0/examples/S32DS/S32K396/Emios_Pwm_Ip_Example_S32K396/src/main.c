/*
*   (c) Copyright 2022 NXP
*
*   NXP Confidential. This software is owned or controlled by NXP and may only be used strictly
*   in accordance with the applicable license terms. By expressly accepting
*   such terms or by downloading, installing, activating and/or otherwise using
*   the software, you are agreeing that you have read, and that you agree to
*   comply with and are bound by, such license terms. If you do not agree to
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

#include "Clock_Ip.h"
#include "Emios_Pwm_Ip.h"
#include "Emios_Mcl_Ip.h"
#include "Siul2_Port_Ip.h"

/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/


/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/
#define NUM_BLINK_LED     (uint32)10U
#define DELAY_TIMER       (uint32)5000000U
#define INSTANCE_0        (uint8)0U
#define CHANNEL_3         (uint8)3U
#define CHANNEL_23        (uint8)23U
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

void TestDelay(uint32 delay);
/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/
void TestDelay(uint32 delay)
{
    static volatile uint32 DelayTimer = 0;
    while(DelayTimer<delay)
    {
        DelayTimer++;
    }
    DelayTimer=0;
}

/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/

/**
* @brief        Main function of the example
* @details      Initialize the used drivers and uses the Pwm driver to control the led brightness
*               and blink a LED
*/
int main (void)
{
    uint8 num_blink = 0U;
    /* Initialize clock () */
    Clock_Ip_Init(&Clock_Ip_aClockConfig[0]);

    /* Initialize all pins using the Port driver */
    Siul2_Port_Ip_Init(NUM_OF_CONFIGURED_PINS0, g_pin_mux_InitConfigArr0);

    /* Initialize Emios_Mcl driver */
    Emios_Mcl_Ip_Init(INSTANCE_0, &Emios_Mcl_Ip_0_Config_VS_0);

    /* Initialize Emios_Pwm_Ip driver */
    Emios_Pwm_Ip_InitChannel(EMIOS_PWM_IP_VS_0_I0_CH3_CFG, &Emios_Pwm_Ip_VS_0_I0_Ch3);

    /* Set new period for the channels that used external counter bus */
    Emios_Mcl_Ip_SetCounterBusPeriod(INSTANCE_0, CHANNEL_23, 0x5000);

    /* Setup new duty cycle to the pin*/
    Emios_Pwm_Ip_SetDutyCycle(INSTANCE_0, CHANNEL_3, 0x200);

    /* Setup new duty cycle to the pin*/
    Emios_Pwm_Ip_SetDutyCycle(INSTANCE_0, CHANNEL_3, 0x4000);

    /* Using duty 0% and 100% to blink led */
    while(num_blink < NUM_BLINK_LED)
    {
        /* Led off when duty cycle is 100% */
        Emios_Pwm_Ip_SetDutyCycle(INSTANCE_0, CHANNEL_3, 0x5000);
        TestDelay(DELAY_TIMER);

        /* Led on when duty cycle is 0% */
        Emios_Pwm_Ip_SetDutyCycle(INSTANCE_0, CHANNEL_3, 0U);
        TestDelay(DELAY_TIMER);
        num_blink++;
    }

    /* De-Initialize Emios_Pwm_Ip driver */
    Emios_Pwm_Ip_DeInitChannel(INSTANCE_0, CHANNEL_3);

    return 0U;
}

#ifdef __cplusplus
}
#endif

/** @} */
