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
#include "Mem_Otp_Ip.h"
#include "Mem_Otp_Ip_Types.h"
#include "OsIf.h"
#include "check_example.h"
#include "Clock_Ip.h"
#include "Aec_Ip.h"
#include "Lpspi_Ip.h"
#include "Siul2_Port_Ip.h"

/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/


/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/
#define OSC42MHzREG                                    0x03U
#define OSC42MHzVAL                                    17U

#define NUMOF_PINS_USED                                4U
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
* @brief        Example for Mem_Otp_Ip
* @details      Test write data into OSC42M mirror register:
*                1. Read data from OSC42M mirror register. If the functionality
*                is as expected then proceed with next steps.
*                2. Write an osc_trim value into OSC42M mirror register.
                 3. Read again data from OSC42M mirror register to verify data has just been written.
**/
int main(void)
{
    Mem_Otp_Ip_StatusType result;
    uint32 dataCheck;
    const uint32 instance_Cfg0 = Ocotp_ConfigSet_pHwConfig.ocotpInstance;

    OsIf_Init(NULL_PTR);
    /* Initialize for clock */
    Clock_Ip_Init(&Clock_Ip_aClockConfig[0U]);

    /* Initialize pins for LPSPI */
    Siul2_Port_Ip_Init(NUMOF_PINS_USED, g_pin_mux_InitConfigArr0);
    Lpspi_Ip_Init(&Lpspi_Ip_PhyUnitConfig_SpiPhyUnit_1_Instance_1);

    Aec_Ip_Init(&Aec_Ip_aConfigPB);
    /* Initialize Mem_Otp_Ip driver */
    Mem_Otp_Ip_Init(&Ocotp_ConfigSet_pHwConfig);
    /* Read data from OSC42M mirror register.*/
    result = Mem_Otp_Ip_ReadMirrorRegister(instance_Cfg0, OSC42MHzREG, &dataCheck);
    Ocotp_ExampleAssert(STATUS_MEM_OTP_IP_SUCCESS == result);
    /* Write an osc_trim value into OSC42M mirror register */
    result = Mem_Otp_Ip_WriteMirrorRegister(instance_Cfg0, OSC42MHzREG, OSC42MHzVAL);
    Ocotp_ExampleAssert(STATUS_MEM_OTP_IP_SUCCESS == result);
    /* Verify the value has just been written into OSC42M mirror register */
    result = Mem_Otp_Ip_ReadMirrorRegister(instance_Cfg0, OSC42MHzREG, &dataCheck);
    Ocotp_ExampleAssert(STATUS_MEM_OTP_IP_SUCCESS == result);
    Ocotp_ExampleAssert(OSC42MHzVAL == dataCheck);

    /* If we get here it means the test has passed */
    Exit_Example(TRUE);
    return (0U);
}

#ifdef __cplusplus
}
#endif

/** @} */
