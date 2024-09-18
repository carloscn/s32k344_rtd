/*==================================================================================================
*   Project              : RTD AUTOSAR 4.7
*   Platform             : CORTEXM
*   Peripheral           : 
*   Dependencies         : none
*
*   Autosar Version      : 4.7.0
*   Autosar Revision     : ASR_REL_4_7_REV_0000
*   Autosar Conf.Variant :
*   SW Version           : 3.0.0
*   Build Version        : S32K3_RTD_3_0_0_D2303_ASR_REL_4_7_REV_0000_20230331
*
*   Copyright 2020 - 2023 NXP Semiconductors
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
*   @addtogroup HVM_DRIVER HVM Driver
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
#include "Hvm_Ip.h"
#include "Hvm_Ip_Hw_Access.h"
#include "Hvm_Ip_Cfg_Defines.h"
#include "Aec_Ip.h"
#include "Mcal.h"

#if (STD_ON == HVM_DEV_ERROR_DETECT)
    #include "Devassert.h"
#endif /* (STD_ON == HVM_DEV_ERROR_DETECT) */ 

/*==================================================================================================
*                              SOURCE FILE VERSION InfoRMATION
==================================================================================================*/
#define HVM_IP_VENDOR_ID_C                      43
#define HVM_IP_AR_RELEASE_MAJOR_VERSION_C       4
#define HVM_IP_AR_RELEASE_MINOR_VERSION_C       7
#define HVM_IP_AR_RELEASE_REVISION_VERSION_C    0
#define HVM_IP_SW_MAJOR_VERSION_C               3
#define HVM_IP_SW_MINOR_VERSION_C               0
#define HVM_IP_SW_PATCH_VERSION_C               0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Checks against Hvm_Ip.h */
#if (HVM_IP_VENDOR_ID_C !=  HVM_IP_VENDOR_ID)
    #error "Hvm_Ip.c and Hvm_Ip.h have different vendor ids"
#endif
#if (( HVM_IP_AR_RELEASE_MAJOR_VERSION_C    !=  HVM_IP_AR_RELEASE_MAJOR_VERSION) || \
     ( HVM_IP_AR_RELEASE_MINOR_VERSION_C    !=  HVM_IP_AR_RELEASE_MINOR_VERSION) || \
     ( HVM_IP_AR_RELEASE_REVISION_VERSION_C !=  HVM_IP_AR_RELEASE_REVISION_VERSION))
     #error "AUTOSAR Version Numbers of Hvm_Ip.c and Hvm_Ip.h are different"
#endif
#if (( HVM_IP_SW_MAJOR_VERSION_C !=  HVM_IP_SW_MAJOR_VERSION) || \
     ( HVM_IP_SW_MINOR_VERSION_C !=  HVM_IP_SW_MINOR_VERSION) || \
     ( HVM_IP_SW_PATCH_VERSION_C !=  HVM_IP_SW_PATCH_VERSION))
    #error "Software Version Numbers of Hvm_Ip.c and Hvm_Ip.h are different"
#endif

/* Checks against Hvm_Ip_Hw_Access.h */
#if (HVM_IP_VENDOR_ID_C !=  HVM_IP_HW_ACCESS_VENDOR_ID)
    #error "Hvm_Ip.c and Hvm_Ip_Hw_Access.h have different vendor ids"
#endif
#if (( HVM_IP_AR_RELEASE_MAJOR_VERSION_C    !=  HVM_IP_HW_ACCESS_AR_RELEASE_MAJOR_VERSION) || \
     ( HVM_IP_AR_RELEASE_MINOR_VERSION_C    !=  HVM_IP_HW_ACCESS_AR_RELEASE_MINOR_VERSION) || \
     ( HVM_IP_AR_RELEASE_REVISION_VERSION_C !=  HVM_IP_HW_ACCESS_AR_RELEASE_REVISION_VERSION))
     #error "AUTOSAR Version Numbers of Hvm_Ip.c and Hvm_Ip_Hw_Access.h are different"
#endif
#if (( HVM_IP_SW_MAJOR_VERSION_C !=  HVM_IP_HW_ACCESS_SW_MAJOR_VERSION) || \
     ( HVM_IP_SW_MINOR_VERSION_C !=  HVM_IP_HW_ACCESS_SW_MINOR_VERSION) || \
     ( HVM_IP_SW_PATCH_VERSION_C !=  HVM_IP_HW_ACCESS_SW_PATCH_VERSION))
    #error "Software Version Numbers of Hvm_Ip.c and Hvm_Ip_Hw_Access.h are different"
#endif

/* Checks against Hvm_Ip_Cfg_Defines.h */
#if (HVM_IP_VENDOR_ID_C !=  HVM_IP_CFG_DEFINES_VENDOR_ID)
    #error "Hvm_Ip.c and Hvm_Ip_Cfg_Defines.h have different vendor ids"
#endif
#if (( HVM_IP_AR_RELEASE_MAJOR_VERSION_C    !=  HVM_IP_CFG_DEFINES_AR_RELEASE_MAJOR_VERSION) || \
     ( HVM_IP_AR_RELEASE_MINOR_VERSION_C    !=  HVM_IP_CFG_DEFINES_AR_RELEASE_MINOR_VERSION) || \
     ( HVM_IP_AR_RELEASE_REVISION_VERSION_C !=  HVM_IP_CFG_DEFINES_AR_RELEASE_REVISION_VERSION))
     #error "AUTOSAR Version Numbers of Hvm_Ip.c and Hvm_Ip_Cfg_Defines.h are different"
#endif
#if (( HVM_IP_SW_MAJOR_VERSION_C !=  HVM_IP_CFG_DEFINES_SW_MAJOR_VERSION) || \
     ( HVM_IP_SW_MINOR_VERSION_C !=  HVM_IP_CFG_DEFINES_SW_MINOR_VERSION) || \
     ( HVM_IP_SW_PATCH_VERSION_C !=  HVM_IP_CFG_DEFINES_SW_PATCH_VERSION))
    #error "Software Version Numbers of Hvm_Ip.c and Hvm_Ip_Cfg_Defines.h are different"
#endif

/* Checks against Aec_Ip.h */
#if (HVM_IP_VENDOR_ID_C !=  AEC_IP_VENDOR_ID)
    #error "Hvm_Ip.c and Aec_Ip.h have different vendor ids"
#endif
#if (( HVM_IP_AR_RELEASE_MAJOR_VERSION_C    !=  AEC_IP_AR_RELEASE_MAJOR_VERSION) || \
     ( HVM_IP_AR_RELEASE_MINOR_VERSION_C    !=  AEC_IP_AR_RELEASE_MINOR_VERSION) || \
     ( HVM_IP_AR_RELEASE_REVISION_VERSION_C !=  AEC_IP_AR_RELEASE_REVISION_VERSION))
     #error "AUTOSAR Version Numbers of Hvm_Ip.c and Aec_Ip.h are different"
#endif
#if (( HVM_IP_SW_MAJOR_VERSION_C !=  AEC_IP_SW_MAJOR_VERSION) || \
     ( HVM_IP_SW_MINOR_VERSION_C !=  AEC_IP_SW_MINOR_VERSION) || \
     ( HVM_IP_SW_PATCH_VERSION_C !=  AEC_IP_SW_PATCH_VERSION))
    #error "Software Version Numbers of Hvm_Ip.c and Aec_Ip.h are different"
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK   
    /* Checks against Devassert.h*/
    #if (STD_ON == HVM_DEV_ERROR_DETECT)
        #if (( HVM_IP_AR_RELEASE_MAJOR_VERSION_C    !=  DEVASSERT_AR_RELEASE_MAJOR_VERSION) || \
            ( HVM_IP_AR_RELEASE_MINOR_VERSION_C     !=  DEVASSERT_AR_RELEASE_MINOR_VERSION))
            #error "AUTOSAR Version Numbers of Hvm_Ip.c and Devassert.h are different"
        #endif
    #endif
#endif

/*******************************************************************************
 * Definitions
 ******************************************************************************/
#if (HVM_DEV_ERROR_DETECT == STD_ON)
    #define HVM_DEV_ASSERT(x)      DevAssert(x)
#else
    #define HVM_DEV_ASSERT(x)      
#endif

#define HVM_REG_SIZE_8           (8U)
#define HVM_REG_SIZE_16          (16U)
#define HVM_REG_SIZE_32          (32U)

/* Instance for VM/HVI */
#define HVM_INST_0                (0U)
#define HVM_INST_1                (1U)

#define AEC_RSTGEN_CFG_ADDR       (0x44U)
#define RSTGEN_HVIAE_ACTIVE       (0x0020U)

/*******************************************************************************
 * Variables
 ******************************************************************************/
#define AE_START_SEC_CONST_UNSPECIFIED
#include "Ae_MemMap.h"

static HVI_AE_Type * const Hvm_apxBases[1U] = IP_HVI_AE_BASE_PTRS;

#define AE_STOP_SEC_CONST_UNSPECIFIED
#include "Ae_MemMap.h"

#define AE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Ae_MemMap.h"

Hvm_Ip_ReportEventCallbackType Hvm_Ip_pfReportCallback = Hvm_Ip_ReportEventsCallback;

#define AE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Ae_MemMap.h"

/*******************************************************************************
 * Prototypes
 ******************************************************************************/
#define AE_START_SEC_CODE
#include "Ae_MemMap.h"

static Hvm_Ip_StatusType Hvm_Ip_WaitForStatusFlag( uint32 MaksVal,
                                                   uint32 Timeout
                                                  );
/*******************************************************************************
 * Private functions
 ******************************************************************************/                                          

/*FUNCTION**********************************************************************
 *
 * Function Name : Hvm_Ip_WaitForStatusFlag
 * Description   : Checks if the status flag has raised.
 *
 *END**************************************************************************/
static Hvm_Ip_StatusType Hvm_Ip_WaitForStatusFlag( uint32 MaksVal,
                                                   uint32 Timeout
                                                  )
{
    Aec_Ip_StatusType AecStatus = AEC_STATUS_TIMEOUT;
    Hvm_Ip_StatusType HvmStatus = HVM_STATUS_TIMEOUT;
    uint32 StartTime;
    uint32 ElapsedTime;
    uint32 TimeoutTicks;
    uint32 RegVal;
    const HVI_AE_Type *Base = Hvm_apxBases[0U];
    
    HVM_StartTimeout(&StartTime, &ElapsedTime, &TimeoutTicks, Timeout);

    /* Read the status register */
    do
    {
        AecStatus = Aec_Ip_SpiRead((uint32)&Base->STAT, HVM_REG_SIZE_32, &RegVal);
        
        if ((AEC_STATUS_SUCCESS == AecStatus) && (0U != (RegVal & MaksVal)))
        {
            HvmStatus = HVM_STATUS_SUCCESS;
            break;
        }
    } while (!HVM_TimeoutExpired(&StartTime, &ElapsedTime, TimeoutTicks));

    return HvmStatus;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Hvm_Ip_ReportEvents
 * Description   : Report event raised interrupt.
 *
 *END**************************************************************************/ 
static void Hvm_Ip_ReportEvents(uint8 Instance,
                                Hvm_Ip_OutputStatusType Event
                                )
{
    Hvm_Ip_pfReportCallback(Instance, Event);
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Hvm_Ip_HVIChannelInit
 * Description   : Initializes for HVI channels.
 *
 *END**************************************************************************/
static Hvm_Ip_StatusType Hvm_Ip_HVIChannelInit(const Ae_HviChannelConfig *pHviConfig)
{
    Aec_Ip_StatusType Status = AEC_STATUS_SUCCESS;
    const HVI_AE_Type *Base = Hvm_apxBases[0U];
    uint32 RegVal;
    uint8 HviChannel = pHviConfig->HviHighVolInputConfig.Hvichannel;
    
    /* Turn off HVI channel and enable configuration mode */
    Status |= Aec_Ip_SpiWrite((uint32)&Base->UCTRL_ARRAY[HviChannel].UCTRL, HVM_REG_SIZE_8, HVI_AE_UCTRL_CFGEN_MASK);
    
    /* Select the voltage division ratio if pull down selected */
    if ((boolean)TRUE == pHviConfig->HviHighVolInputConfig.PullDownEn)
    {
        RegVal = HVI_AE_UCFG_DIVSEL(pHviConfig->HviHighVolInputConfig.VoltDiv) | HVI_AE_UCFG_PDEN_MASK;
    }
    if ((boolean)TRUE == pHviConfig->HviHighVolInputConfig.PullUpEn)
    {
        RegVal = HVI_AE_UCFG_PUEN_MASK;
    }   
    /* Select the rising or falling edge as event  and enable digital Input */
    RegVal |= (HVI_AE_UCFG_DINPO(pHviConfig->InputPolarity) | HVI_AE_UCFG_DINEN(pHviConfig->InputDigitalEn));
    Status |= Aec_Ip_SpiWrite((uint32)&Base->UCTRL_ARRAY[HviChannel].UCFG, HVM_REG_SIZE_16, RegVal);
    
    /* Disable configuration mode and enable HVI */
    Status |= Aec_Ip_SpiWrite((uint32)&Base->UCTRL_ARRAY[HviChannel].UCTRL, HVM_REG_SIZE_8, HVI_AE_UCTRL_EN_MASK);
    
    /* Clear interrupt flag */
    Status |= Aec_Ip_SpiRead((uint32)&Base->INTF, HVM_REG_SIZE_32, &RegVal);
    Status |= Aec_Ip_SpiWrite((uint32)&Base->INTF, HVM_REG_SIZE_32, RegVal);
    
    /* Check whether interrupt used or polling mode */
    if ((boolean)TRUE == pHviConfig->IntDiditalInputEn)
    {
        if (0U == HviChannel)
        {
            RegVal = HVI_AE_INTEN_DINIE0_MASK;
        }
        else
        {
            RegVal = HVI_AE_INTEN_DINIE1_MASK;
        }
        /* Enable interrupt flag */
        Status |= Aec_Ip_SpiWrite((uint32)&Base->INTEN, HVM_REG_SIZE_32, RegVal);
    }
    
    return  ((AEC_STATUS_SUCCESS == Status)? (HVM_STATUS_SUCCESS) : (HVM_STATUS_ERROR));
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Hvm_Ip_AnalogInputInit
 * Description   : Initializes for Analog Input configuration.
 *
 *END**************************************************************************/
static Hvm_Ip_StatusType  Hvm_Ip_AnalogInputInit( const Ae_HviHighVoltageInputConfig *pHviHighVoltConfig,
                                                  Ae_AnalogInputType AnalogInputSelect,
                                                  boolean ConfigAgain
                                                 )
{
    uint8 HviChannel;
    uint32 RegVal;
    Aec_Ip_StatusType Status;
    const HVI_AE_Type *Base = Hvm_apxBases[0U];
    HviChannel = pHviHighVoltConfig->Hvichannel;
    
    /* Select one source to measure its voltage */
    RegVal = HVI_AE_GCTRL_AINSEL(AnalogInputSelect);
    /* Enable analog input channel */
    RegVal |= HVI_AE_GCTRL_AINEN(HviChannel);
    Status = Aec_Ip_SpiWrite((uint32)&Base->GCTRL, HVM_REG_SIZE_32, RegVal);
    
    if ((boolean)TRUE == ConfigAgain)
    {
        /* if high voltage selected for input, configure the voltage divider */
        if (((uint8)HVI_ANALOG_DIVIDE_DOWN_HIGH_INPUT_BUFFERED == AnalogInputSelect) && ((boolean)TRUE == pHviHighVoltConfig->PullDownEn))
        {
            /* Turn off the HVI channel and set Hvi in configuration mode */
            Status |= Aec_Ip_SpiWrite((uint32)&Base->UCTRL_ARRAY[HviChannel].UCTRL, HVM_REG_SIZE_8, HVI_AE_UCTRL_CFGEN_MASK);
            /* Select the voltage didivion ratio */
            RegVal = HVI_AE_UCFG_DIVSEL(pHviHighVoltConfig->VoltDiv);
            /* Enable the pull-down */
            RegVal |= HVI_AE_UCFG_PDEN_MASK;
            Status |= Aec_Ip_SpiWrite((uint32)&Base->UCTRL_ARRAY[HviChannel].UCFG, HVM_REG_SIZE_16, RegVal);
        }
    }
    
    /* Disable Configuration Mode if it set before and enable HVI channel */
    Status |= Aec_Ip_SpiWrite((uint32)&Base->UCTRL_ARRAY[HviChannel].UCTRL, HVM_REG_SIZE_8, HVI_AE_UCTRL_EN_MASK);
    
    return  ((AEC_STATUS_SUCCESS == Status)? (HVM_STATUS_SUCCESS) : (HVM_STATUS_ERROR));
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Hvm_Ip_VMInit
 * Description   : Initializes for Voltage Monitor configuration.
 *
 *END**************************************************************************/
static Hvm_Ip_StatusType  Hvm_Ip_VMInit( const Ae_VmConfig *pAeVmConfig,
                                         const Ae_HviHighVoltageInputConfig *pHighVoltageInput,
                                         boolean ConfigAgain
                                        )
{
    Aec_Ip_StatusType Status = AEC_STATUS_SUCCESS;
    const HVI_AE_Type *Base = Hvm_apxBases[0U];
    uint32 RegVal;
    
    if ((VM_HIGH_VOLTAGE_INPUT == pAeVmConfig->VoltageMonitor) && ((boolean)TRUE == ConfigAgain))
    {
        /* Program the voltage divider configuration */
        if ((boolean)TRUE == pHighVoltageInput->PullDownEn)
        {
            RegVal = HVI_AE_UCFG_DIVSEL(pHighVoltageInput->VoltDiv) | HVI_AE_UCFG_PDEN_MASK;
            Status |= Aec_Ip_SpiWrite((uint32)&Base->UCTRL_ARRAY[0U].UCFG, HVM_REG_SIZE_16, RegVal);
        }
    }
    /* HVI 0 conttected to VM by default */
    /* Turn off HVI and set configuration mode */
    Status |= Aec_Ip_SpiWrite((uint32)&Base->UCTRL_ARRAY[0U].UCTRL, HVM_REG_SIZE_8, HVI_AE_UCTRL_CFGEN_MASK);
 
    /* Select analog input voltage */
    RegVal = HVI_AE_VMCFG_VMINSEL(pAeVmConfig->VoltageMonitor);
    
    /* Select one of the two high voltage refrences */
    RegVal |= HVI_AE_VMCFG_HDREFSEL(pAeVmConfig->HighVoltDect);
    
    /* Select one of the four low voltage references */
    RegVal |= HVI_AE_VMCFG_LDREFSEL(pAeVmConfig->LowVoltDect);
    
    /* Enable the high and/ or low voltage monitors */
    if ((boolean)TRUE == pAeVmConfig->LowVolDectEn)
    {
        RegVal |= HVI_AE_VMCFG_LDEN_MASK;
    }
    
    if ((boolean)TRUE == pAeVmConfig->HighVolDectEn)
    {
        RegVal |= HVI_AE_VMCFG_HDEN_MASK;
    }
    
    Status |= Aec_Ip_SpiWrite((uint32)&Base->UCTRL_ARRAY[0U].VMCFG, HVM_REG_SIZE_8, RegVal);
    
    /* Disable configuration mode and enable HVI */
    Status |= Aec_Ip_SpiWrite((uint32)&Base->UCTRL_ARRAY[0U].UCTRL, HVM_REG_SIZE_8, HVI_AE_UCTRL_EN_MASK);
    
    /* Clear interrupt flags */
    RegVal = HVI_AE_INTF_HDIF0_MASK | HVI_AE_INTF_LDIF0_MASK;
    Status |= Aec_Ip_SpiWrite((uint32)&Base->INTF, HVM_REG_SIZE_32, RegVal);
    
    /* Reset variable value */
    Status |= Aec_Ip_SpiRead((uint32)&Base->INTEN, HVM_REG_SIZE_32, &RegVal);;
    
    /* Check if interrupt enabled */
    if ((boolean)TRUE == pAeVmConfig->IntHighVoltageEn)
    {
        RegVal |= HVI_AE_INTEN_HDIE0_MASK;
    }
    if ((boolean)TRUE == pAeVmConfig->IntLowVoltageEn)
    {
        RegVal |= HVI_AE_INTEN_LDIE0_MASK;
    }
    
    /* Enable interrupt flag */
    Status |= Aec_Ip_SpiWrite((uint32)&Base->INTEN, HVM_REG_SIZE_32, RegVal);
    
    return  ((AEC_STATUS_SUCCESS == Status)? (HVM_STATUS_SUCCESS) : (HVM_STATUS_ERROR));
}
/*******************************************************************************
 * Code
 ******************************************************************************/
/*FUNCTION**********************************************************************
 *
 * Function Name : Hvm_Ip_Init
 * Description   : Initializes the Hvm Driver.
 *
 *END**************************************************************************/ 
Hvm_Ip_StatusType  Hvm_Ip_Init(const Hvm_Ip_ConfigType *pHvmConfig)
{
    uint8 HviIdx;
    Hvm_Ip_StatusType Status = HVM_STATUS_TIMEOUT;
    Aec_Ip_StatusType AecStatus;
    uint32 RegVal;
    
    HVM_DEV_ASSERT(pHvmConfig != NULL_PTR);
    
    AecStatus = Aec_Ip_SpiRead(AEC_RSTGEN_CFG_ADDR, HVM_REG_SIZE_16, &RegVal);
    RegVal |= RSTGEN_HVIAE_ACTIVE;
    AecStatus |= Aec_Ip_SpiWrite(AEC_RSTGEN_CFG_ADDR, HVM_REG_SIZE_16, RegVal);
    
    if (AEC_STATUS_SUCCESS == AecStatus)
    {
        Status = HVM_STATUS_SUCCESS;
        for (HviIdx = 0U; HviIdx < HVI_NUMOF_MAX_INSTANCES; HviIdx++)
        {
            Status |= Hvm_Ip_HVIChannelInit(&pHvmConfig->Hvm_pChannelConfig[HviIdx]);
        }
        
        Status |= Hvm_Ip_AnalogInputInit(&pHvmConfig->Hvm_pChannelConfig[pHvmConfig->AnalogChannel].HviHighVolInputConfig, pHvmConfig->AnalogInput, FALSE);
        Status |= Hvm_Ip_VMInit(pHvmConfig->Hvm_pVmConfig, &pHvmConfig->Hvm_pChannelConfig[0U].HviHighVolInputConfig, FALSE);
    }
    
    return Status;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Hvm_Ip_AdcMeasureConfig
 * Description   : Initializes the configuration for analog input for measurement.
 *
 *END**************************************************************************/ 
Hvm_Ip_StatusType  Hvm_Ip_AdcMeasureConfig(const Ae_HviHighVoltageInputConfig *pHviHighVoltConfig,
                                           Ae_AnalogInputType AnalogInputSelect
                                           )
{
    Hvm_Ip_StatusType Status;    
    
    HVM_DEV_ASSERT(pHviHighVoltConfig != NULL_PTR);
    
    Status = Hvm_Ip_AnalogInputInit(pHviHighVoltConfig, AnalogInputSelect, TRUE);
    
    return  Status;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Hvm_Ip_DigitalInputEventConfig
 * Description   : Initializes the configuration for digital input.
 *
 *END**************************************************************************/ 
Hvm_Ip_StatusType  Hvm_Ip_DigitalInputEventConfig(const Ae_HviChannelConfig *pHviConfig)
{
    Hvm_Ip_StatusType Status;
    
    HVM_DEV_ASSERT(pHviConfig != NULL_PTR);
    
    Status = Hvm_Ip_HVIChannelInit(pHviConfig);
    
    return  Status;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Hvm_Ip_VoltageMonitorConfig
 * Description   : Initializes the configuration for High/Low Voltage detect.
 *
 *END**************************************************************************/ 
Hvm_Ip_StatusType  Hvm_Ip_VoltageMonitorConfig(const Ae_VmConfig *pAeVmConfig,
                                               const Ae_HviHighVoltageInputConfig *pHighVoltageInput
                                               )
{
    Hvm_Ip_StatusType Status;
    
    HVM_DEV_ASSERT(pAeVmConfig           != NULL_PTR);
    HVM_DEV_ASSERT(pHighVoltageInput     != NULL_PTR);
    
    Status = Hvm_Ip_VMInit(pAeVmConfig, pHighVoltageInput, TRUE);
    
    return Status;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Hvm_Ip_FaultsEventsProccess
 * Description   : Check and clear interrupt flag used in interrupt mode.
 *
 *END**************************************************************************/ 
void Hvm_Ip_FaultsEventsProccess(void)
{
    const HVI_AE_Type *Base = Hvm_apxBases[0U];
    uint32 StatusReg;
    uint32 EnReg;
     
    /* Check interrupt source */
    Aec_Ip_SpiRead((uint32)&Base->INTF, HVM_REG_SIZE_32, &StatusReg);
    /* Check interrupt enable mask */
    Aec_Ip_SpiRead((uint32)&Base->INTEN, HVM_REG_SIZE_32, &EnReg);
    
    if ((0U != (StatusReg & HVI_AE_INTF_DINIF1_MASK)) && (0U != (EnReg & HVI_AE_INTEN_DINIE1_MASK)))
    {
        /* Clear interrupt flag */
        Aec_Ip_SpiWrite((uint32)&Base->INTF, HVM_REG_SIZE_32, HVI_AE_INTF_DINIF1_MASK);
        
        Hvm_Ip_ReportEvents(HVM_INST_1, HVM_STATUS_DIGITAL_INPUT_ACTIVE);
    }
    if ((0U != (StatusReg & HVI_AE_INTF_DINIF0_MASK)) && (0U != (EnReg & HVI_AE_INTEN_DINIE0_MASK)))
    {
        /* Clear interrupt flag */
        Aec_Ip_SpiWrite((uint32)&Base->INTF, HVM_REG_SIZE_32, HVI_AE_INTF_DINIF0_MASK);
        
        Hvm_Ip_ReportEvents(HVM_INST_0, HVM_STATUS_DIGITAL_INPUT_ACTIVE);
    }
    if ((0U != (StatusReg & HVI_AE_INTF_HDIF0_MASK)) && (0U != (EnReg & HVI_AE_INTEN_HDIE0_MASK)))
    {
        /* Clear interrupt flag */
        Aec_Ip_SpiWrite((uint32)&Base->INTF, HVM_REG_SIZE_32, HVI_AE_INTF_HDIF0_MASK); 
        
        Hvm_Ip_ReportEvents(HVM_INST_0, HVM_STATUS_HIGH_DETECT);
    }
    if ((0U != (StatusReg & HVI_AE_INTF_LDIF0_MASK)) && (0U != (EnReg & HVI_AE_INTEN_LDIE0_MASK)))
    {
        /* Clear interrupt flag */
        Aec_Ip_SpiWrite((uint32)&Base->INTF, HVM_REG_SIZE_32, HVI_AE_INTF_LDIF0_MASK);
        
        Hvm_Ip_ReportEvents(HVM_INST_0, HVM_STATUS_LOW_DETECT);
    }
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Hvm_Ip_FaultsEventsProccess
 * Description   : Check status flag used in polling mode.
 *
 *END**************************************************************************/ 
void Hvm_Ip_ReadFaultsEventsStatus(void)
{
    Hvm_Ip_StatusType HvmStatus = HVM_STATUS_SUCCESS;

    HvmStatus = Hvm_Ip_WaitForStatusFlag(HVI_AE_STAT_DINS0_MASK, HVM_TIMEOUT_VALUE_US);
    if (HVM_STATUS_SUCCESS == HvmStatus)
    {
        Hvm_Ip_ReportEvents(HVM_INST_0, HVM_STATUS_DIGITAL_INPUT_ACTIVE);
    }

    HvmStatus = Hvm_Ip_WaitForStatusFlag(HVI_AE_STAT_DINS1_MASK, HVM_TIMEOUT_VALUE_US);   
    if (HVM_STATUS_SUCCESS == HvmStatus)
    {
        Hvm_Ip_ReportEvents(HVM_INST_1, HVM_STATUS_DIGITAL_INPUT_ACTIVE);
    }
    
    HvmStatus = Hvm_Ip_WaitForStatusFlag(HVI_AE_STAT_HDS0_MASK, HVM_TIMEOUT_VALUE_US);
    if (HVM_STATUS_SUCCESS == HvmStatus)
    {
        Hvm_Ip_ReportEvents(HVM_INST_0, HVM_STATUS_HIGH_DETECT);
    }

    HvmStatus = Hvm_Ip_WaitForStatusFlag(HVI_AE_STAT_LDS0_MASK, HVM_TIMEOUT_VALUE_US);
    if (HVM_STATUS_SUCCESS == HvmStatus)
    {
        Hvm_Ip_ReportEvents(HVM_INST_0, HVM_STATUS_LOW_DETECT);
    }
}

#define AE_STOP_SEC_CODE
#include "Ae_MemMap.h"


#ifdef __cplusplus
}
#endif
/** @} */
