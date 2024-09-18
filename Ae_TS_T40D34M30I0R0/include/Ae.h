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
#ifndef AE_H
#define AE_H

/**
*   @file
*
*   @addtogroup AE_DRIVER Aeernet Driver
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
#include "Ae_Cfg.h"           /* Mandatory include - see the SWS */

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define AE_VENDOR_ID                    43
#define AE_MODULE_ID                    250
#define AE_AR_RELEASE_MAJOR_VERSION     4
#define AE_AR_RELEASE_MINOR_VERSION     7
#define AE_AR_RELEASE_REVISION_VERSION  0
#define AE_SW_MAJOR_VERSION             3
#define AE_SW_MINOR_VERSION             0
#define AE_SW_PATCH_VERSION             0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Checks against Ae_Cfg.h */
#if (AE_VENDOR_ID != AE_CFG_VENDOR_ID)
    #error "Ae.h and Ae_Cfg.h have different vendor ids"
#endif
#if ((AE_AR_RELEASE_MAJOR_VERSION    != AE_CFG_AR_RELEASE_MAJOR_VERSION) || \
     (AE_AR_RELEASE_MINOR_VERSION    != AE_CFG_AR_RELEASE_MINOR_VERSION) || \
     (AE_AR_RELEASE_REVISION_VERSION != AE_CFG_AR_RELEASE_REVISION_VERSION))
     #error "AUTOSAR Version Numbers of Ae.h and Ae_Cfg.h are different"
#endif
#if ((AE_SW_MAJOR_VERSION != AE_CFG_SW_MAJOR_VERSION) || \
     (AE_SW_MINOR_VERSION != AE_CFG_SW_MINOR_VERSION) || \
     (AE_SW_PATCH_VERSION != AE_CFG_SW_PATCH_VERSION))
    #error "Software Version Numbers of Ae.h and Ae_Cfg.h are different"
#endif
/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/
/* Service IDs definition */
#if STD_ON == AE_DEV_ERROR_DETECT 
/*! @brief Service ID of Ae_Init */
#define AE_SID_INIT                         0x01
/*! @brief Service ID of Ae_WriteRegister */
#define AE_SID_WRITEREGISTER                0x02
/*! @brief Service ID of Ae_ReadRegister */
#define AE_SID_READREGISTER                 0x03
/*! @brief Service ID of Ae_GetVersionInfo */
#define AE_SID_GETVERSIONINFO               0x04
/*! @brief Service ID of Ae_AdcMeasureConfig */
#define AE_SID_ADCMEASURECONFIG             0x05
/*! @brief Service ID of Ae_DigitalInputEventConfig */
#define AE_SID_DIGITALINPUTCONFIG           0x06
/*! @brief Service ID of Ae_VoltageMonitorConfig */
#define AE_SID_VOLTAGEMONITORCONFIG         0x07
/*! @brief Service ID of Ae_DecodeGlobalHeathStatus */
#define AE_SID_DECODEGLOBALHEATHSTATUS      0x08
/*! @brief Service ID of Ae_Frame_Counter */
#define AE_SID_FRAMECOUNTER                 0x09
/*! @brief Service ID of Ae_FaultsEventsProccess */
#define AE_SID_FAULTSEVENTSPROCCESS         0x0A
/*! @brief Service ID of Ae_ReadFaultsEventsStatus */
#define AE_SID_READFAULTSEVENTSSTATUS       0x0B
#endif

/* DET error codes */
#if STD_ON == AE_DEV_ERROR_DETECT
    /*! @brief Development Error ID for "Invalid Controller Index" */
    #define AE_E_INV_CTRL_IDX      ((uint8)0x01)
    /*! @brief Development Error ID for "Uninitialized Controller" */
    #define AE_E_UNINIT            ((uint8)0x02)
    /*! @brief Development Error ID for "Invalid (Null) Pointer Parameter" */
    #define AE_E_PARAM_POINTER     ((uint8)0x03)
    /*! @brief Development Error ID for "Invalid Parameter" */
    #define AE_E_INV_PARAM         ((uint8)0x04)
    /*! @brief Development Error ID for "Invalid Controller Mode" */
    #define AE_E_INV_MODE          ((uint8)0x05)
    /*! @brief Development Error ID for "Invalid Configuration pointer argument" */
    #define AE_E_INIT_FAILED       ((uint8)0x08)
#endif

/* Return status of global heath for each frame. User can use this to read status. */
#define AE_STATUS_CLOCK_MISS               (0x0001U)
#define AE_STATUS_WRONG_ANSWER             (0x0002U)
#define AE_STATUS_FSM_STATUS               (0x0004U)
#define AE_STATUS_TST_MODE                 (0x0010U)
#define AE_STATUS_PMC_MODE                 (0x0020U)
#define AE_STATUS_FAULT_NOTIFY             (0x0040U)
#define AE_STATUS_EVENT_NOTIFY             (0x0080U)
#define AE_STATUS_FIRST_FRAME              (0x8000U)

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/

/*==================================================================================================
*                                             ENUMS
==================================================================================================*/

/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/
typedef enum
{
   AE_STATE_UNINIT = 0U,
   AE_STATE_INIT   = 1U
} Ae_StateType;
/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

#define AE_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Ae_MemMap.h"

#if STD_OFF == AE_PRECOMPILE_SUPPORT
AE_CONFIG_EXT
#endif

#define AE_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Ae_MemMap.h"


/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/
#define AE_START_SEC_CODE
#include "Ae_MemMap.h"


/**
* @brief         Initializes the Ae Driver
* @details       The configuration pointer is internally stored and
*                the driver is initialized.
*/
extern void Ae_Init(const Ae_ConfigType *CfgPtr);

/**
* @brief         Read register value.
* @details       Read register value.
* @param[in]     RegAddr Index of the AE register to be read.
* @param[in]     DataWidth Size of register in AEC that want to read/write.
* @param[out]    RegValPtr Filled with the register content of the indexed register
*   
* Return         E_OK if read value from register successful.
*                E_NOT_OK E_OK if read value from register failure.                
*/
extern Std_ReturnType Ae_ReadRegister ( uint32 RegAddr,
                                        uint8 DataWidth,
                                        uint32 *RegValPtr
                                       );
/**
* @brief         Write register value.
* @details       Write register value.
* @param[in]     RegAddr Index of the AE register to be write.
* @param[in]     DataWidth Size of register in AEC that want to read/write.
* @param[in]     RegVal Filled with the register content of the indexed register
*   
* Return         E_OK if write value from register successful.
*                E_NOT_OK E_OK if write value from register failure.  
*                
*/
extern Std_ReturnType Ae_WriteRegister ( uint32 RegAddr,
                                         uint8 DataWidth,
                                         uint32 RegVal
                                        );
/*!
 * @brief Return status of global heath.
 *
 */                                 
extern uint16 Ae_DecodeGlobalHeathStatus(void);

/*!
 * @brief         Verify for correctness the received frame counter or just number of frames.
 *
 * @param[in]     IsVerify want to verify for correctness for frame counter.
 * @param[in]     ExpectedFrameCount Number of frame expected get.
 * @param[out]    ActualFrameCount Number of frame get in real.
 *
 * Return counter status of respond frame from AE_Robin.
 *
 */
extern boolean Ae_Frame_Counter( boolean IsVerify,
                                 uint8 ExpectedFrameCount,
                                 uint8 *ActualFrameCount
                                );

/*!
 * @brief Initializes the configuration for analog input for measurement.
 *
 * @param[in]   pHviHighVoltConfig Pointer for configuration of High Voltage Input.
 * @param[in]   AnalogInputSelect Type of Analog Input.
 *
 * Return       E_OK The initialization was successful.
 *
 */
extern Std_ReturnType  Ae_AdcMeasureConfig( const Ae_HviHighVoltageInputConfig *pHviHighVoltConfig,
                                            Ae_AnalogInputType AnalogInputSelect
                                           );  

/*!
 * @brief Initializes the configuration for digital input.
 *
 * @param[in] pAeHviChannelConfig Pointer to configuration of HVI channel.
 *
 * Return E_OK The initialization was successful.
 *
 */
extern Std_ReturnType  Ae_DigitalInputEventConfig(const Ae_HviChannelConfig *pAeHviChannelConfig);

/*!
 * @brief Initializes the configuration for High/Low Voltage detect.
 *
 * @param[in]   pAeVmConfig Pointer to configuration of VM.
 * @param[in]   pHighVoltageInput Pointer to configuration of High Voltage Input.
 *
 * Return       E_OK The initialization was successful.
 */
extern Std_ReturnType  Ae_VoltageMonitorConfig( const Ae_VmConfig *pAeVmConfig,
                                                const Ae_HviHighVoltageInputConfig *pHighVoltageInput
                                               );

/*!
 * @brief Check and clear interrupt flag used in interrupt mode.
 *
 * Return Interrupt flag want to read raised or not.
 *
 */
extern void Ae_FaultsEventsProccess(void);

/*!
 * @brief Check status flag used in polling mode for digital input, high/low voltage detect.
 *
 */
extern void  Ae_ReadFaultsEventsStatus(void);

#if STD_ON == AE_VERSION_INFO_API
/**
* @brief         Returns the version information of this module.
* @api
* @param[out]    VersionInfoPtr Pointer where to store the version information
*                of this particular module instance.
* implements     Ae_GetVersionInfo_Activity
*/
extern void Ae_GetVersionInfo(Std_VersionInfoType *VersionInfoPtr);
#endif /* AE_VERSION_INFO_API */


#define AE_STOP_SEC_CODE
#include "Ae_MemMap.h"


#ifdef __cplusplus
}
#endif

/** @} */

#endif /* AE_H */
