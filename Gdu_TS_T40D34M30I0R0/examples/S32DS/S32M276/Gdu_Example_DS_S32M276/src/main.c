/*==================================================================================================
*   Copyright M4_SRC_YEAR_ID M4_SRC_COPYRIGHTED_TO
*   All Rights Reserved.
*
*   NXP Confidential. This software is owned or controlled by NXP and may only be
*   used strictly in accordance with the applicable license terms. By expressly
*   accepting such terms or by downloading, installing, activating and/or otherwise
*   using the software, you are agreeing that you have read, and that you agree to
*   comply with and are bound by, such license terms. If you do not agree to be
*   bound by the applicable license terms, then you may not retain, install,
*   activate or otherwise use the software.
==================================================================================================*/

/**
*   @file    main.c
*   @brief   Main source file.
*   @addtogroup GDU_EXAMPLE
*   @{
*/

#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "OsIf.h"
#include "Det.h"
#include "Mcu.h"
#include "Port.h"
#include "Spi.h"
#include "Ae.h"
#include "CDD_Gdu.h"
#include "S32M27x.h"
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
#define GDU_START_SEC_VAR_CLEARED_BOOLEAN
#include "Gdu_MemMap.h"

/** Indicates if the notification has been called or not */
static boolean Gdu_TC_bInterrupted = FALSE;

#define GDU_STOP_SEC_VAR_CLEARED_BOOLEAN
#include "Gdu_MemMap.h"

/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/
#define GDU_START_SEC_CODE
#include "Gdu_MemMap.h"

static void Gdu_TestSetup_Clock (void)
{
    Mcu_Init(NULL_PTR);
    Mcu_InitClock(McuClockSettingConfig_0);
    Mcu_SetMode(McuModeSettingConf_0);
    OsIf_Init(NULL_PTR);
}

static void Gdu_TestSetup_Pins (void)
{
    Port_Init(NULL_PTR);
}

static void Gdu_TestSetup_Peripherals (void)
{
    Spi_Init(NULL_PTR);
    Ae_Init(NULL_PTR);
    Mcu_AecResetConfig();
}

/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/

int main (void)
{
    Std_ReturnType Return = E_OK;
    boolean Result = FALSE;

    Gdu_TestSetup_Clock();
    Gdu_TestSetup_Pins();
    Gdu_TestSetup_Peripherals();

    Return = Gdu_Init(NULL_PTR);

    Result = (E_OK == Return) ? TRUE : FALSE;
    Exit_Example(Result);

    return 0;
}

void Gdu_Notification (
    uint32 InterruptFlags)
{
    (void) InterruptFlags;

    Gdu_TC_bInterrupted = TRUE;
}

ISR(Gdu_FaultProtection)
{
    /* read the fault protection flags */
}

#define GDU_STOP_SEC_CODE
#include "Gdu_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */
