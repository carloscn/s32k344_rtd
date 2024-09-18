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
*   @addtogroup AE_DRIVER Ae Driver
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
#include "Ae.h"
#include "Ae_Ipw.h"

#include "Det.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define AE_VENDOR_ID_C                      43
#define AE_MODULE_ID_C                      250
#define AE_AR_RELEASE_MAJOR_VERSION_C       4
#define AE_AR_RELEASE_MINOR_VERSION_C       7
#define AE_AR_RELEASE_REVISION_VERSION_C    0
#define AE_SW_MAJOR_VERSION_C               3
#define AE_SW_MINOR_VERSION_C               0
#define AE_SW_PATCH_VERSION_C               0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Checks against Ae.h */
#if (AE_VENDOR_ID_C != AE_VENDOR_ID)
    #error "Ae.c and Ae.h have different vendor ids"
#endif
#if ((AE_AR_RELEASE_MAJOR_VERSION_C    != AE_AR_RELEASE_MAJOR_VERSION) || \
     (AE_AR_RELEASE_MINOR_VERSION_C    != AE_AR_RELEASE_MINOR_VERSION) || \
     (AE_AR_RELEASE_REVISION_VERSION_C != AE_AR_RELEASE_REVISION_VERSION))
    #error "AUTOSAR Version Numbers of Ae.c and Ae.h are different"
#endif
#if ((AE_SW_MAJOR_VERSION_C != AE_SW_MAJOR_VERSION) || \
     (AE_SW_MINOR_VERSION_C != AE_SW_MINOR_VERSION) || \
     (AE_SW_PATCH_VERSION_C != AE_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Ae.c and Ae.h are different"
#endif

/* Checks against Ae_Ipw.h */
#if (AE_VENDOR_ID_C != AE_IPW_VENDOR_ID)
    #error "Ae.c and Ae_Ipw.h have different vendor ids"
#endif
#if ((AE_AR_RELEASE_MAJOR_VERSION_C    != AE_IPW_AR_RELEASE_MAJOR_VERSION) || \
     (AE_AR_RELEASE_MINOR_VERSION_C    != AE_IPW_AR_RELEASE_MINOR_VERSION) || \
     (AE_AR_RELEASE_REVISION_VERSION_C != AE_IPW_AR_RELEASE_REVISION_VERSION))
    #error "AUTOSAR Version Numbers of Ae.c and Ae_Ipw.h are different"
#endif
#if ((AE_SW_MAJOR_VERSION_C != AE_IPW_SW_MAJOR_VERSION) || \
     (AE_SW_MINOR_VERSION_C != AE_IPW_SW_MINOR_VERSION) || \
     (AE_SW_PATCH_VERSION_C != AE_IPW_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Ae.c and Ae_Ipw.h are different"
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Checks against Det.h */
    #if ((AE_AR_RELEASE_MAJOR_VERSION_C != DET_AR_RELEASE_MAJOR_VERSION) || \
         (AE_AR_RELEASE_MINOR_VERSION_C != DET_AR_RELEASE_MINOR_VERSION))
        #error "AUTOSAR Version Numbers of Ae.c and Det.h are different"
    #endif
#endif

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
#define AE_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "Ae_MemMap.h"

#if STD_ON == AE_DEV_ERROR_DETECT
/**
* @brief         State of the AE initialization.
* @details       Used to store state of the AE Initialization driver. It is initialized to AE_STATE_UNINIT
*/
static Ae_StateType Ae_axInitState;
#endif

#define AE_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "Ae_MemMap.h"
/*==================================================================================================
                                       GLOBAL CONSTANTS
==================================================================================================*/
#if (AE_PRECOMPILE_SUPPORT == STD_ON)

#define AE_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Ae_MemMap.h"

extern const Ae_ConfigType Ae_xPredefinedConfig;

#define AE_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Ae_MemMap.h"

#endif /* #if (AE_PRECOMPILE_SUPPORT == STD_ON) */

/*==================================================================================================
*                                      GLOBAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/
#define AE_START_SEC_CODE
#include "Ae_MemMap.h"

/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/

/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/

/*================================================================================================*/
/**
* @brief         Initializes the Ae Driver
*
*/
void Ae_Init(const Ae_ConfigType *CfgPtr)
{
    Std_ReturnType ReturnStatus = (Std_ReturnType)E_NOT_OK;
    const Ae_ConfigType *Ae_apxInternalCfg;
    
#if (STD_OFF == AE_PRECOMPILE_SUPPORT)
  #if (STD_ON == AE_DEV_ERROR_DETECT)
    if (NULL_PTR == CfgPtr)
    {
        (void)Det_ReportError(AE_MODULE_ID, 0U, AE_SID_INIT, AE_E_INIT_FAILED);
    }
    else
    {
  #endif
        Ae_apxInternalCfg = CfgPtr;
#else /* AE_PRECOMPILE_SUPPORT == STD_ON */
      #if (STD_ON == AE_DEV_ERROR_DETECT)
        if (NULL_PTR != CfgPtr)
        {
            (void)Det_ReportError(AE_MODULE_ID, 0U, AE_SID_INIT, AE_E_INIT_FAILED);
        }
        else
        {
      #endif
            Ae_apxInternalCfg = &Ae_xPredefinedConfig;
            (void)CfgPtr;
      #if (STD_ON == AE_DEV_ERROR_DETECT)
        }
      #endif          
#endif /* (STD_ON != AE_PRECOMPILE_SUPPORT) */
#if (STD_ON == AE_DEV_ERROR_DETECT)
        Ae_axInitState = AE_STATE_UNINIT;
#endif
       
        ReturnStatus = Ae_Ipw_Init(Ae_apxInternalCfg->Ae_pIpwConfig);
        
#if (STD_ON == AE_DEV_ERROR_DETECT)
        if ((Std_ReturnType)E_OK == ReturnStatus)
        {
            Ae_axInitState = AE_STATE_INIT;
        }
#else
    (void)ReturnStatus;
#endif        
#if (STD_OFF == AE_PRECOMPILE_SUPPORT)          
#if (STD_ON == AE_DEV_ERROR_DETECT)
    }
#endif
#endif
}

/*================================================================================================*/
/**
* @brief         Read register value.
*              
*/
Std_ReturnType Ae_ReadRegister (uint32 RegAddr,
                                uint8 DataWidth,
                                uint32 *RegValPtr
                                )
{
    Std_ReturnType ReturnStatus = (Std_ReturnType)E_NOT_OK;
    

#if (AE_DEV_ERROR_DETECT == STD_ON)
    if (NULL_PTR == RegValPtr)
    {
        (void)Det_ReportError(AE_MODULE_ID, 0U, AE_SID_READREGISTER, AE_E_PARAM_POINTER);
    }
    else if (AE_STATE_UNINIT == Ae_axInitState)
    {
        (void)Det_ReportError(AE_MODULE_ID, 0U, AE_SID_READREGISTER, AE_E_UNINIT);
    }
    else
    {
#endif /* AE_DEV_ERROR_DETECT == STD_ON */  
  
        ReturnStatus = Ae_Ipw_ReadReg(RegAddr, DataWidth, RegValPtr);
        
#if (AE_DEV_ERROR_DETECT == STD_ON)
    }
#endif /* AE_DEV_ERROR_DETECT == STD_ON */

    return ReturnStatus;
}

/*================================================================================================*/
/**
* @brief         Write register value.
*             
*/
Std_ReturnType Ae_WriteRegister (uint32 RegAddr,
                                 uint8 DataWidth,
                                 uint32 RegVal
                                )
{
    Std_ReturnType ReturnStatus = (Std_ReturnType)E_NOT_OK;
    
#if (AE_DEV_ERROR_DETECT == STD_ON)
    if (AE_STATE_UNINIT == Ae_axInitState)
    {
        (void)Det_ReportError(AE_MODULE_ID, 0U, AE_SID_WRITEREGISTER, AE_E_UNINIT);
    }
    else
    {
#endif /* AE_DEV_ERROR_DETECT == STD_ON */ 
   
        ReturnStatus = Ae_Ipw_WriteReg(RegAddr, DataWidth, RegVal);
        
#if (AE_DEV_ERROR_DETECT == STD_ON)
    }
#endif /* AE_DEV_ERROR_DETECT == STD_ON */

    return ReturnStatus;
}

/*================================================================================================*/
/*!
 * @brief Return status of global heath.
 *
 */ 
uint16 Ae_DecodeGlobalHeathStatus(void)
{
    uint16 Status = 0U;
    
#if (AE_DEV_ERROR_DETECT == STD_ON)
    if (AE_STATE_UNINIT == Ae_axInitState)
    {
        (void)Det_ReportError(AE_MODULE_ID, 0U, AE_SID_DECODEGLOBALHEATHSTATUS, AE_E_UNINIT);
    }
    else
    {
#endif /* AE_DEV_ERROR_DETECT == STD_ON */

        Status = Ae_Ipw_DecodeGlobalHeathStatus();
        
#if (AE_DEV_ERROR_DETECT == STD_ON)
    }
#endif /* AE_DEV_ERROR_DETECT == STD_ON */
        
    return Status;
}

/*================================================================================================*/
/*!
 * @brief Verify for correctness the received frame counter.
 *
 */
boolean Ae_Frame_Counter( boolean IsVerify,
                          uint8 ExpectedFrameCount,
                          uint8 *ActualFrameCount
                        )
{
    boolean Status = (boolean)FALSE;
    
#if (AE_DEV_ERROR_DETECT == STD_ON)
    if (AE_STATE_UNINIT == Ae_axInitState)
    {
        (void)Det_ReportError(AE_MODULE_ID, 0U, AE_SID_FRAMECOUNTER, AE_E_UNINIT);
    }
    else if (NULL_PTR == ActualFrameCount)
    {
        (void)Det_ReportError(AE_MODULE_ID, 0U, AE_SID_FRAMECOUNTER, AE_E_PARAM_POINTER);
    }
    else
    {
#endif /* AE_DEV_ERROR_DETECT == STD_ON */

    Status = Ae_Ipw_Frame_Counter(IsVerify, ExpectedFrameCount, ActualFrameCount);
    
#if (AE_DEV_ERROR_DETECT == STD_ON)
    }
#endif /* AE_DEV_ERROR_DETECT == STD_ON */

    return Status;
}

/*================================================================================================*/
/*!
 * @brief Initializes the configuration for analog input for measurement.
 *
 */
Std_ReturnType  Ae_AdcMeasureConfig( const Ae_HviHighVoltageInputConfig *pHviHighVoltConfig,
                                     Ae_AnalogInputType AnalogInputSelect
                                    )
{
    Std_ReturnType ReturnStatus = (Std_ReturnType)E_NOT_OK;
    
#if (AE_DEV_ERROR_DETECT == STD_ON)
    if (AE_STATE_UNINIT == Ae_axInitState)
    {
        (void)Det_ReportError(AE_MODULE_ID, 0U, AE_SID_ADCMEASURECONFIG, AE_E_UNINIT);
    }
    else if (NULL_PTR == pHviHighVoltConfig)
    {
        (void)Det_ReportError(AE_MODULE_ID, 0U, AE_SID_ADCMEASURECONFIG, AE_E_PARAM_POINTER);
    }
    else
    {
#endif /* AE_DEV_ERROR_DETECT == STD_ON */
 
        ReturnStatus = Ae_Ipw_AdcMeasureConfig(pHviHighVoltConfig, AnalogInputSelect);
        
#if (AE_DEV_ERROR_DETECT == STD_ON)
    }
#endif /* AE_DEV_ERROR_DETECT == STD_ON */

    return ReturnStatus;
}

/*================================================================================================*/
/*!
 * @brief Initializes the configuration for digital input.
 *
 */
Std_ReturnType  Ae_DigitalInputEventConfig(const Ae_HviChannelConfig *pAeHviChannelConfig)
{
    Std_ReturnType ReturnStatus = (Std_ReturnType)E_NOT_OK;
    
#if (AE_DEV_ERROR_DETECT == STD_ON)
    if (NULL_PTR == pAeHviChannelConfig)
    {
        (void)Det_ReportError(AE_MODULE_ID, 0U, AE_SID_DIGITALINPUTCONFIG, AE_E_PARAM_POINTER);
    }
    else if (AE_STATE_UNINIT == Ae_axInitState)
    {
        (void)Det_ReportError(AE_MODULE_ID, 0U, AE_SID_DIGITALINPUTCONFIG, AE_E_UNINIT);
    }
    else
    {
#endif /* AE_DEV_ERROR_DETECT == STD_ON */
 
        ReturnStatus = Ae_Ipw_DigitalInputEventConfig(pAeHviChannelConfig);
        
#if (AE_DEV_ERROR_DETECT == STD_ON)
    }
#endif /* AE_DEV_ERROR_DETECT == STD_ON */ 
    
    return ReturnStatus;
}

/*================================================================================================*/
/*!
 * @brief Initializes the configuration for High/Low Voltage detect.
 *
 */
Std_ReturnType  Ae_VoltageMonitorConfig(const Ae_VmConfig *pAeVmConfig,
                                        const Ae_HviHighVoltageInputConfig *pHighVoltageInput
                                        )
{
    Std_ReturnType ReturnStatus = (Std_ReturnType)E_NOT_OK;
    
#if (AE_DEV_ERROR_DETECT == STD_ON)
    if (AE_STATE_UNINIT == Ae_axInitState)
    {
        (void)Det_ReportError(AE_MODULE_ID, 0U, AE_SID_VOLTAGEMONITORCONFIG, AE_E_UNINIT);
    }
    else if ((NULL_PTR == pAeVmConfig) || (NULL_PTR == pHighVoltageInput))
    {
        (void)Det_ReportError(AE_MODULE_ID, 0U, AE_SID_VOLTAGEMONITORCONFIG, AE_E_PARAM_POINTER);
    }
    else
    {
#endif /* AE_DEV_ERROR_DETECT == STD_ON */
 
        ReturnStatus = Ae_Ipw_VoltageMonitorConfig(pAeVmConfig, pHighVoltageInput);
        
#if (AE_DEV_ERROR_DETECT == STD_ON)
    }
#endif /* AE_DEV_ERROR_DETECT == STD_ON */ 
    
    return ReturnStatus;
}

/*================================================================================================*/
/*!
 * @brief Check and clear interrupt flag used in interrupt mode.
 *
 */
void Ae_FaultsEventsProccess(void)
{
#if (AE_DEV_ERROR_DETECT == STD_ON)
    if (AE_STATE_UNINIT == Ae_axInitState)
    {
        (void)Det_ReportError(AE_MODULE_ID, 0U, AE_SID_FAULTSEVENTSPROCCESS, AE_E_UNINIT);
    }
    else
    {
#endif /* AE_DEV_ERROR_DETECT == STD_ON */

        Ae_Ipw_FaultsEventsProccess();
    
#if (AE_DEV_ERROR_DETECT == STD_ON)
    }
#endif /* AE_DEV_ERROR_DETECT == STD_ON */     
}

/*================================================================================================*/
/*!
 * @brief Check status flag used in polling mode for digital input, high/low voltage detect.
 *
 */
void  Ae_ReadFaultsEventsStatus(void)
{
#if (AE_DEV_ERROR_DETECT == STD_ON)
    if (AE_STATE_UNINIT == Ae_axInitState)
    {
        (void)Det_ReportError(AE_MODULE_ID, 0U, AE_SID_READFAULTSEVENTSSTATUS, AE_E_UNINIT);
    }
    else
    {
#endif /* AE_DEV_ERROR_DETECT == STD_ON */

        Ae_Ipw_ReadFaultsEventsStatus();
    
#if (AE_DEV_ERROR_DETECT == STD_ON)
    }
#endif /* AE_DEV_ERROR_DETECT == STD_ON */ 
}

#if STD_ON == AE_VERSION_INFO_API
/*================================================================================================*/
/**
* @brief         Returns the version information of this module.
*
* implements    Ae_GetVersionInfo_Activity
*/
void Ae_GetVersionInfo(Std_VersionInfoType *VersionInfoPtr) 
{
#if STD_ON == AE_DEV_ERROR_DETECT
    if (NULL_PTR == VersionInfoPtr)
    {
        (void)Det_ReportError(AE_MODULE_ID, 0U, AE_SID_GETVERSIONINFO, AE_E_PARAM_POINTER);
    }
    else
    {
#endif /* AE_DEV_ERROR_DETECT */
        VersionInfoPtr->moduleID = (uint16)AE_MODULE_ID;
        VersionInfoPtr->vendorID = (uint16)AE_VENDOR_ID;
        VersionInfoPtr->sw_major_version = (uint8)AE_SW_MAJOR_VERSION;
        VersionInfoPtr->sw_minor_version = (uint8)AE_SW_MINOR_VERSION;
        VersionInfoPtr->sw_patch_version = (uint8)AE_SW_PATCH_VERSION;
#if STD_ON == AE_DEV_ERROR_DETECT
    }
#endif /* AE_DEV_ERROR_DETECT */
}
#endif /* AE_VERSION_INFO_API */

#define AE_STOP_SEC_CODE
#include "Ae_MemMap.h"


#ifdef __cplusplus
}
#endif

/** @} */
