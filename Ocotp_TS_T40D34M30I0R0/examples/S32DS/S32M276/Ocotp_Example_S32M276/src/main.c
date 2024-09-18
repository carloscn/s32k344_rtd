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
#include "Mcu.h"
#include "Ae.h"
#include "Spi.h"
#include "Port.h"
#include "SchM_Ocotp.h"
#include "CDD_Ocotp.h"
#include "Mcal.h"
#include "check_example.h"
/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/


/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/
#define OSC42MHz       17U
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
void Ocotp_ExampleAssert(boolean Condition)
{
    if (!Condition)
    {
        for (;;)
        {
            /* Loop forever */
        }
    }
}

/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/

/**
* @brief        Example for Ocotp
* @details      Test write data into OSC42M mirror register:
*                1. Read data from OSC42M mirror register. If the functionality
*                is as expected then proceed with next steps.
*                2. Write an osc_trim value into OSC42M mirror register.
                 3. Read again data from OSC42M mirror register to verify data has just been written.
**/
int main(void)
{
    Std_ReturnType result;
    uint32 DataCheck;


    /* Initialize Mcu clock */
    Mcu_Init(NULL_PTR);
    Mcu_InitClock(McuClockSettingConfig_0);

    while (MCU_PLL_LOCKED != Mcu_GetPllStatus())
    {
        /* Busy wait until the System PLL is locked */
    }

    Mcu_DistributePllClock();

    Mcu_SetMode(McuModeSettingConf_0);

    /* Initialize pins for LPSPI */
    Port_Init(NULL_PTR);

    /* Configure LPSI in sync mode */
    Spi_Init(NULL_PTR);

    Ae_Init(NULL_PTR);

    /* Initialize Ocotp driver */
    Ocotp_Init(NULL_PTR);
    /* Read data from OSC42M mirror register.*/
    result = Ocotp_ReadMirrorRegister(OcotpConf_OcotpChannelConfiguration_OcotpChannel_0,&DataCheck);
    Ocotp_ExampleAssert(E_OK == result);
    /* Write an osc_trim value into OSC42M mirror register */
    result = Ocotp_WriteMirrorRegister(OcotpConf_OcotpChannelConfiguration_OcotpChannel_0, OSC42MHz);
    Ocotp_ExampleAssert(E_OK == result);
    /* Verify the value has just been written into OSC42M mirror register */
    result = Ocotp_ReadMirrorRegister(OcotpConf_OcotpChannelConfiguration_OcotpChannel_0,&DataCheck);
    Ocotp_ExampleAssert(E_OK == result);
    Ocotp_ExampleAssert(OSC42MHz == DataCheck);

    /* If we get here it means the test has passed */
    Exit_Example(TRUE);
    return (0U);
}

#ifdef __cplusplus
}
#endif

/** @} */
