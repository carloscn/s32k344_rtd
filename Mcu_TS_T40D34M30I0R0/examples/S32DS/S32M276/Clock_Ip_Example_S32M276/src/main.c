/*
*   Copyright 2020 NXP
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

/*!
**  @addtogroup main_module main module documentation
**  @{
*/
/* MODULE main */


/* Including necessary configuration files. */
#include "Clock_Ip.h"
#include "check_example.h"

#define CLOCKOUT_FREQ_CFG_0   20000000U
#define CLOCKOUT_FREQ_CFG_1   6000000U



/*!
  \brief The main function for the project.
  \details The startup initialization sequence is the following:
 * - startup asm routine
 * - main()
*/
int main(void)
{
    Clock_Ip_StatusType clockStatus;
    boolean Result = TRUE;

    /* Write your code here */
    clockStatus = Clock_Ip_Init(&Clock_Ip_aClockConfig[0]);

    if (clockStatus != CLOCK_IP_SUCCESS)
    {
        Result = FALSE;
    }
    else
    {
        if (Clock_Ip_GetClockFrequency(CLKOUT_RUN_CLK) != CLOCKOUT_FREQ_CFG_0)
        {
            Result = FALSE;
        }
    }


    clockStatus = Clock_Ip_Init(&Clock_Ip_aClockConfig[1]);

    if (clockStatus != CLOCK_IP_SUCCESS)
    {
        Result = FALSE;
    }
    else
    {
        if (Clock_Ip_GetClockFrequency(CLKOUT_RUN_CLK) != CLOCKOUT_FREQ_CFG_1)
        {
            Result = FALSE;
        }
    }

    Exit_Example(Result);
    return (0U);
}

/* END main */
/*!
** @}
*/
