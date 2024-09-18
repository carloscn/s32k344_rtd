/*==================================================================================================
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
==================================================================================================*/

#ifdef __cplusplus
extern "C" {
#endif

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/

#include "Pwm.h"
#include "Mcu.h"
#include "Siul2_Port_Ip.h"
#include "Mcl.h"

/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/


/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/
#define NUM_BLINK_LED     (uint32)10U
#define DELAY_TIMER       (uint32)5000000U
#define MCL_EMIOS_0_CH_23 (uint16)23U
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
int main(void)
{
    uint8 num_blink = 0U;

    /* Initialize the Mcu driver */
    Mcu_Init(&Mcu_Config_VS_0);

    /* Initialize the clock tree */
    Mcu_InitClock(McuClockSettingConfig_0);

    /* Apply a mode configuration */
    Mcu_SetMode(McuModeSettingConf_0);

    /* Initialize all pins using the Siul2_Port driver */
    Siul2_Port_Ip_Init(NUM_OF_CONFIGURED_PINS, g_pin_mux_InitConfigArr_VS_0);

    /* Initialize Mcl driver */
    Mcl_Init(&Mcl_Config_VS_0);

    /* Initialize Pwm driver , after that Led on*/
    Pwm_Init(&Pwm_Config_VS_0);

    /* Set new period for all channels used external counter bus */
    Mcl_Emios_SetCounterBusPeriod(MCL_EMIOS_0_CH_23, 0x9000U, FALSE);

    /* Increasing LED brightness using Pwm_SetDutyCycle*/
    Pwm_SetDutyCycle(EMIOS_0_CH3, 0x200);
    Pwm_SetDutyCycle(FLEXIO_0_CH_1_D0 , 0x200);
    Pwm_SetDutyCycle(FLEXPWM_0_X_SM3, 0x200);

    /* Decreasing LED brightness using Pwm_SetDutyCycle*/
    Pwm_SetDutyCycle(EMIOS_0_CH3, 0x7000);
    Pwm_SetDutyCycle(FLEXIO_0_CH_1_D0 , 0x7000);
    Pwm_SetDutyCycle(FLEXPWM_0_X_SM3, 0x7000);

    /* Using duty cycle 0% and 100% to Blink LED */
    while(num_blink < NUM_BLINK_LED)
    {
        /* Led off when duty cycle is 100% */
        Pwm_SetDutyCycle(EMIOS_0_CH3, 0x8000);
        Pwm_SetDutyCycle(FLEXIO_0_CH_1_D0 , 0x8000);
        Pwm_SetDutyCycle(FLEXPWM_0_X_SM3, 0x8000);
        TestDelay(DELAY_TIMER);

        /* Led on when duty cycle is 0% */
        Pwm_SetDutyCycle(EMIOS_0_CH3, 0x0000);
        Pwm_SetDutyCycle(FLEXIO_0_CH_1_D0 , 0x0000);
        Pwm_SetDutyCycle(FLEXPWM_0_X_SM3, 0x0000);
        TestDelay(DELAY_TIMER);
        num_blink++;
    }

    /* De-Initialize Pwm driver */
    Pwm_DeInit();

    return 0U;
}

#ifdef __cplusplus
}
#endif

/** @} */
