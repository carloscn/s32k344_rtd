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

#ifdef __cplusplus
extern "C" {
#endif


/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Adc.h"
#include "Mcu.h"
#include "Mcl.h"
#include "CDD_Rm.h"
#include "Platform.h"
#include "check_example.h"

/*==================================================================================================
*                                      EXTERN DECLARATIONS
==================================================================================================*/
/* By default S32K342, K358 and K311 boards will have 3.3V voltage reference selected while S32K312, S32K344 and S32K396 will have 5V selected.
 * If you have S32K342 with default pin configuration or if you've manually selected 3.3V reference, please uncomment the following line: */
#define ADC_3V3_VREF_SELECTED
#ifdef ADC_3V3_VREF_SELECTED
#define ADC_BANDGAP         5980U /* Vbandgap ~ 1.2V on 14 bits resolution, 3.3V VrefH */
#else
#define ADC_BANDGAP         3932U /* Vbandgap ~ 1.2V on 14 bits resolution, 5V VrefH */
#endif

#define ADC_VREFH           16383U /* 14 bits resolution */

#define NUM_RESULTS         (3u)
#define RESULT_BUFF_VAL     (0xaaaa)
#define ADC_RESULT_BUFF_VAL (0xbbbb)

#define ADC_TOLERANCE(x,y)  (((x > y) ? (x - y) : (y - x)) > 200U) /* Check that the data is within tolerated range */

#ifndef S32K396
    #define BCTU_IRQ            BCTU_IRQn
    #ifndef S32M276
    #define DMA_IRQ             DMATCD1_IRQn
    #else
    #define DMA_IRQ             DMA1_IRQn
    #endif
    #define DMA_IRQ_HANDLER     Dma0_Ch1_IRQHandler
#else
    #define BCTU_IRQ            BCTU0_IRQn
    #define DMA_IRQ             eDMA1_DMATCD_CH0_CH1_IRQn
    #define DMA_IRQ_HANDLER     Dma1_Ch0_Ch1_IrqHandler
#endif

extern ISR(Adc_Sar_0_Isr);
extern ISR(Bctu_0_Isr);
extern ISR(DMA_IRQ_HANDLER);

/*==================================================================================================
*                                      GLOBAL VARIABLES
==================================================================================================*/
Adc_ValueGroupType    ResultBuffer[NUM_RESULTS]    =  {RESULT_BUFF_VAL, RESULT_BUFF_VAL, RESULT_BUFF_VAL};
Adc_ValueGroupType    AdcReadGroupResult[NUM_RESULTS] =  {ADC_RESULT_BUFF_VAL, ADC_RESULT_BUFF_VAL, ADC_RESULT_BUFF_VAL};
Adc_ValueGroupType    BctuCtrlModeResult = 0u;

uint16 FifoResult[5u];

#define ADC_START_SEC_VAR_INIT_UNSPECIFIED_NO_CACHEABLE
#include "Adc_MemMap.h"

__attribute__(( aligned(32) )) Adc_ValueGroupType    ResultBufferDma[NUM_RESULTS] =  {RESULT_BUFF_VAL, RESULT_BUFF_VAL, RESULT_BUFF_VAL};

#define ADC_STOP_SEC_VAR_INIT_UNSPECIFIED_NO_CACHEABLE
#include "Adc_MemMap.h"

volatile uint8 VarNotification_0 = 0u;
volatile uint8 VarNotification_1 = 0u;
volatile uint8 BctuWatermarkNotif = 0u;
volatile uint8 BctuTrigNotif = 0u;
volatile uint8 BctuNewDataNotif = 0u;

/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/
void Notification_0(void)
{
    VarNotification_0++;
}

void Notification_1(void)
{
    VarNotification_1++;
}

#if (ADC_ENABLE_CTU_CONTROL_MODE_API == STD_ON)
void WatermarkNotification1(void)
{
    BctuWatermarkNotif++;

    Adc_CtuReadFifoData(0u, FifoResult, 4u);
}

void BctuTriggerNotification(void)
{
    BctuTrigNotif++;
}
void NewDataNotification(void)
{
    BctuNewDataNotif++;
}
#endif /* (ADC_ENABLE_CTU_CONTROL_MODE_API == STD_ON) */


int main(void)
{
    Std_ReturnType StdReturn = E_NOT_OK;
    volatile boolean bStatus = TRUE;
#if (ADC_CALIBRATION == STD_ON)
    Adc_CalibrationStatusType CalibStatus;
#endif /* (ADC_CALIBRATION == STD_ON) */
    uint8 Index, AltIndex;

    /* Initialize Mcu Driver */
    Mcu_Init(&Mcu_Config_VS_0);
    Mcu_InitClock(McuClockSettingConfig_0);
    Mcu_SetMode(McuModeSettingConf_0);

    /* Initialize Mcl driver */
    Mcl_Init(NULL_PTR);
    /* Initialize Rm driver */
    Rm_Init(NULL_PTR);

    /* Initialize Platform Driver */
    Platform_Init(NULL_PTR);
    Platform_InstallIrqHandler(ADC0_IRQn, Adc_Sar_0_Isr, NULL_PTR);
    Platform_InstallIrqHandler(BCTU_IRQ, Bctu_0_Isr, NULL_PTR);
    Platform_InstallIrqHandler(DMA_IRQ, DMA_IRQ_HANDLER, NULL_PTR);
    Platform_SetIrq(ADC0_IRQn, TRUE);
    Platform_SetIrq(BCTU_IRQ, TRUE);
    Platform_SetIrq(DMA_IRQ, TRUE);

#if (ADC_PRECOMPILE_SUPPORT == STD_ON)
    Adc_Init(NULL_PTR);
#else
    Adc_Init(&Adc_Config_VS_0);
#endif /* (ADC_PRECOMPILE_SUPPORT == STD_ON) */

#if (ADC_CALIBRATION == STD_ON)
    /* Calibrate the first hardware unit used for Interrupt. */
    /* Call Calibration function multiple times, to mitigate instability of board source */
    for(Index = 0; Index <= 5; Index++)
    {
        Adc_Calibrate(AdcHwUnit_0, &CalibStatus);
        if(CalibStatus.AdcUnitSelfTestStatus == E_OK)
        {
            break;
        }
    }
    /* Fail if calibration did not succeed after multiple attempts. */
    if(Index > 5)
    {
        bStatus = FALSE;
    }
#endif /* (ADC_CALIBRATION == STD_ON) */

    if (bStatus)
    {
        /* Part 1: Example with SW Triggered One-Shot Conversion Mode, data conversion is updated by Interrupt.*/
        /*******************************************************************************************************/
        /* ResultBuffer is updated new data in Adc_Sar_0_Isr handler */
        Adc_SetupResultBuffer(AdcGroupSoftwareOneShot, ResultBuffer);
        Adc_EnableGroupNotification(AdcGroupSoftwareOneShot);

        for (Index = 0u; Index < 10u; Index++)
        {
            VarNotification_0 = 0;
            Adc_StartGroupConversion(AdcGroupSoftwareOneShot);

            /* Check if notification is called */
            while (VarNotification_0 == 0u)
            {}

            StdReturn = Adc_ReadGroup(AdcGroupSoftwareOneShot, AdcReadGroupResult);
            if (E_OK != StdReturn)
            {
                bStatus = FALSE;
                break;
            }
            if ((ResultBuffer[0u] != AdcReadGroupResult[0u]) || \
                (ResultBuffer[1u] != AdcReadGroupResult[1u]) || \
                (ResultBuffer[2u] != RESULT_BUFF_VAL) || \
                (AdcReadGroupResult[2u] != ADC_RESULT_BUFF_VAL) || \
                (ADC_TOLERANCE(ResultBuffer[0u], ADC_BANDGAP)) || \
                (ADC_TOLERANCE(ResultBuffer[1u], ADC_VREFH)) \
                )
            {
                bStatus = FALSE;
                break;
            }
            /* Reset the buffers before starting new conversion */
            for (AltIndex = 0; AltIndex < NUM_RESULTS; AltIndex++)
            {
                ResultBuffer[AltIndex] = RESULT_BUFF_VAL;
                AdcReadGroupResult[AltIndex] = ADC_RESULT_BUFF_VAL;
            }
        }

        /* Part 2: Example with BCTU controlled mode conversion by Interrupt.*/
        /*******************************************************************************************************/
        Adc_EnableCtuControlMode(AdcHwUnit_0);
        Adc_CtuStartConversion(AdcHwTrigger_1);

        while (BctuTrigNotif == 0u)
        {}

        while (BctuNewDataNotif == 0u)
        {}

        BctuCtrlModeResult = Adc_CtuReadConvData(AdcHwUnit_0);

        /* SW start conversion for trigger which uses LIST and FIFO */
        Adc_CtuStartConversion(AdcHwTrigger_2);
        while (BctuWatermarkNotif == 0u)
        {}

        if ((0u != FifoResult[4u]) || ADC_TOLERANCE(BctuCtrlModeResult, ADC_BANDGAP) || \
            (ADC_TOLERANCE(FifoResult[0u], ADC_BANDGAP)) || \
            (ADC_TOLERANCE(FifoResult[1u], ADC_BANDGAP)) || \
            (ADC_TOLERANCE(FifoResult[2u], ADC_BANDGAP)) || \
            (ADC_TOLERANCE(FifoResult[3u], ADC_VREFH)) \
            )
        {
            bStatus = FALSE;
        }

        Adc_DisableCtuControlMode(AdcHwUnit_0);
    }

    /* Part 3: Example with SW Triggered One-Shot Conversion Mode, data conversion is updated by DMA.*/
    /*******************************************************************************************************/
#if (ADC_CALIBRATION == STD_ON)
    /* Calibrate the second hardware unit used for DMA. */
    for (Index = 0; Index <= 5; Index++)
    {
        Adc_Calibrate(AdcHwUnitDma, &CalibStatus);
        if(CalibStatus.AdcUnitSelfTestStatus == E_OK)
        {
            break;
        }
    }
    /* Fail if calibration did not succeed after multiple attempts. */
    if (Index > 5)
    {
        bStatus = FALSE;
    }
#endif /* (ADC_CALIBRATION == STD_ON) */

    if (bStatus)
    {
        Adc_SetupResultBuffer(AdcGroupSoftwareOneShotDma, ResultBufferDma);
        Adc_EnableGroupNotification(AdcGroupSoftwareOneShotDma);

        for (Index = 0u; Index < 10u; Index++)
        {
            VarNotification_1 = 0;
            Adc_StartGroupConversion(AdcGroupSoftwareOneShotDma);
            /* Check if notification is called */
            while (VarNotification_1 == 0u)
            {}

            StdReturn = Adc_ReadGroup(AdcGroupSoftwareOneShotDma, AdcReadGroupResult);
            if (E_OK != StdReturn)
            {
                bStatus = FALSE;
                break;
            }

            /* Need to shift 1 bit because of DMA will always transfer the full 15 bits width of data from the CDR register
            but Adc_ReadGroup returns data with Resolution 14 bits and right alignment which were done by configuration. */
            if ((ResultBufferDma[0u] >> 1U != AdcReadGroupResult[0u]) || \
                (ResultBufferDma[1u] >> 1U != AdcReadGroupResult[1u]) || \
                (ResultBufferDma[2u] != RESULT_BUFF_VAL) || \
                (AdcReadGroupResult[2u] != ADC_RESULT_BUFF_VAL) || \
                (ADC_TOLERANCE((ResultBufferDma[0u] >> 1U), ADC_BANDGAP)) || \
                (ADC_TOLERANCE((ResultBufferDma[1u] >> 1U), ADC_VREFH)) \
                )
            {
                bStatus = FALSE;
                break;
            }
            /* Reset the buffers before starting new conversion */
            for (AltIndex = 0; AltIndex < NUM_RESULTS; AltIndex++)
            {
                ResultBufferDma[AltIndex] = RESULT_BUFF_VAL;
                AdcReadGroupResult[AltIndex] = ADC_RESULT_BUFF_VAL;
            }
        }
    }

    Adc_DeInit();

    Exit_Example(bStatus);

    return 0;
}


#ifdef __cplusplus
}
#endif

/** @} */
