/*==================================================================================================
*   Project              : M4_SRC_PROJECT_NAME
*   Platform             : M4_SRC_MCU_FAMILY
*   Peripheral           : M4_SRC_USED_PERIPHERAL
*   Dependencies         : M4_SRC_AR_MODULE_DEPENDENCY
*
*   Autosar Version      : M4_SRC_AR_SPEC_VERSION_MAJOR.M4_SRC_AR_SPEC_VERSION_MINOR.M4_SRC_AR_SPEC_VERSION_PATCH
*   Autosar Revision     : M4_SRC_AR_RELEASE_REVISION
*   Autosar Conf.Variant :
*   SW Version           : M4_SRC_SW_VERSION_MAJOR.M4_SRC_SW_VERSION_MINOR.M4_SRC_SW_VERSION_PATCH
*   Build Version        : M4_SRC_BUILD_ID
*
*   Copyright M4_SRC_YEAR_ID M4_SRC_COPYRIGHTED_TO
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
*   @file
*
*   @addtogroup Wdg
*   @{
*/

#ifdef __cplusplus
extern "C"{
#endif

/*=================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
=================================================================================================*/
#include "Clock_Ip.h"

#include "IntCtrl_Ip.h"
#include "IntCtrl_Ip_Cfg.h"
#include "Swt_Ip.h"

#include "AeWdog_Ip.h"
#include "AeWdog_Ip_VS_0_PBcfg.h"
#include "Aec_Ip.h"
#include "Lpspi_Ip.h"
#include "Siul2_Port_Ip.h"

/* SWT instance used - 0 */
#define SWT_INST                     0U

#define TIMEOUT_EXPIRED              0U

#define TIMEOUT                      100000000U
#define NUM_OF_NOTIFICATIONS         5U

#define AEWDOG_INST                  (0U)
#define AEC_DATAWIDTH_16                    (16U)
#define AEC_WDCFG_ADDR                      (0x30)
#define AEWDOG_WDCFG_RESET_VAL              (0x0300)
#define NUM_OF_SERVICE_TIMES         (50U)

volatile uint32 u32NumOfNotifications = 0U;

/**
* @brief        SWT notification
* @details      Used for toggle led
*/
void Swt_CallbackNotification0(void)
{
    u32NumOfNotifications++;
}

void Delay(volatile uint32 u32Count)
{
    while(u32Count--);
}

/**
* @brief        SWT0 Interrupt handler
* @details      Be used for calling Swt_Ip_IrqHandler defined in Swt_Ip.c
*/
extern void Swt_Ip_Swt0_Isr(void);

int main (void)
{
    volatile uint32 u32Count = 0U;
    uint32 u32Timeout = TIMEOUT;

    uint32 aeWdogRegVal;
    AeWdog_Ip_StatusType aewdog_status = AEWDOG_IP_STATUS_SUCCESS;

    Clock_Ip_InitClock(&Clock_Ip_aClockConfig[0]);
    Clock_Ip_DistributePll();
    /*Enable the SWT0 interrupt vector */
    IntCtrl_Ip_Init(&IntCtrlConfig_0);
    IntCtrl_Ip_InstallHandler(SWT0_IRQn, Swt_Ip_Swt0_Isr, NULL_PTR);

    /*Initialize SWT */
    Swt_Ip_Init(SWT_INST, &Swt_Ip_1_Cfg0);

    for (u32Count = 0U; u32Count < NUM_OF_NOTIFICATIONS; u32Count ++)
    {
        /* Service SWT0 */
        Swt_Ip_Service(SWT_INST);

        while ((u32NumOfNotifications <= u32Count) && (u32Timeout--))
        {

        }

        if (u32Timeout == TIMEOUT_EXPIRED)
        {
            /* Test is failed and the notification function has been called */
            DevAssert(FALSE);
        }

        u32Timeout = TIMEOUT;
    }

    /* De-initialize SWT0 */
    Swt_Ip_Deinit(SWT_INST);


    /* Initialize pins for LPSPI */
    Siul2_Port_Ip_Init(NUM_OF_CONFIGURED_PINS0, g_pin_mux_InitConfigArr0);

    Lpspi_Ip_Init(&Lpspi_Ip_PhyUnitConfig_SpiPhyUnit_0_Instance_1_VS_0);


    Aec_Ip_Init(&Aec_Ip_aConfigPB_VS_0);
    /*Initialize AEWDOG */
    aewdog_status = AeWdog_Ip_Init(AEWDOG_INST, &AeWdog_Ip_Cfg0);

    if(aewdog_status != AEWDOG_IP_STATUS_SUCCESS)
    {
        /* Initialize AEWDOG failed */
        DevAssert(FALSE);
    }

    for(u32Count = 0; u32Count < NUM_OF_SERVICE_TIMES; u32Count++)
    {
        /* Service AEWDOG */
        AeWdog_Ip_Service(AEWDOG_INST);

        Delay(500000);
    }
    Aec_Ip_SpiRead((uint32)AEC_WDCFG_ADDR, AEC_DATAWIDTH_16, &aeWdogRegVal);

    if(AEWDOG_WDCFG_RESET_VAL == aeWdogRegVal)
    {
        /* Service failed WDCFG register is reset */
        DevAssert(FALSE);
    }


    /* Test passed without any error detected */
    DevAssert(TRUE);

    return 0;
}

#ifdef __cplusplus
}
#endif

/** @} */
