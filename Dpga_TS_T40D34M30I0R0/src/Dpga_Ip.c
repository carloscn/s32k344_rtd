/*==================================================================================================
*   Project              : RTD AUTOSAR 4.7
*   Platform             : CORTEXM
*   Peripheral           : DPGA
*   Dependencies         : none
*
*   Autosar Version      : 4.7.0
*   Autosar Revision     : ASR_REL_4_7_REV_0000
*   Autosar Conf.Variant :
*   SW Version           : 3.0.0
*   Build Version        : S32K3_RTD_3_0_0_D2303_ASR_REL_4_7_REV_0000_20230331
*
*   Copyright 2022 NXP
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
*   @addtogroup dpga_ip
*   @{
*/

#ifdef __cplusplus
extern "C"{
#endif


/*==================================================================================================
*                                          INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Dpga_Ip.h"

/*==================================================================================================
*                                 SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define DPGA_IP_VENDOR_ID_C                      43
#define DPGA_IP_AR_RELEASE_MAJOR_VERSION_C       4
#define DPGA_IP_AR_RELEASE_MINOR_VERSION_C       7
#define DPGA_IP_AR_RELEASE_REVISION_VERSION_C    0
#define DPGA_IP_SW_MAJOR_VERSION_C               3
#define DPGA_IP_SW_MINOR_VERSION_C               0
#define DPGA_IP_SW_PATCH_VERSION_C               0

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and Dpga_Ip header file are of the same vendor */
#if (DPGA_IP_VENDOR_ID_C != DPGA_IP_VENDOR_ID)
    #error "Dpga_Ip.c and Dpga_Ip.h have different vendor ids"
#endif

/* Check if current file and Dpga_Ip header file are of the same Autosar version */
#if ((DPGA_IP_AR_RELEASE_MAJOR_VERSION_C     != DPGA_IP_AR_RELEASE_MAJOR_VERSION) || \
     (DPGA_IP_AR_RELEASE_MINOR_VERSION_C     != DPGA_IP_AR_RELEASE_MINOR_VERSION) || \
     (DPGA_IP_AR_RELEASE_REVISION_VERSION_C  != DPGA_IP_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Dpga_Ip.c and Dpga_Ip.h are different"
#endif

/* Check if current file and Dpga_Ip header file are of the same software version */
#if ((DPGA_IP_SW_MAJOR_VERSION_C != DPGA_IP_SW_MAJOR_VERSION) || \
     (DPGA_IP_SW_MINOR_VERSION_C != DPGA_IP_SW_MINOR_VERSION) || \
     (DPGA_IP_SW_PATCH_VERSION_C != DPGA_IP_SW_PATCH_VERSION))
    #error "Software Version Numbers of Dpga_Ip.c and Dpga_Ip.h are different"
#endif

/*==================================================================================================
*                           LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
*                                          LOCAL MACROS
==================================================================================================*/
/**
* @brief Amplifier configuration max values.
*
* @details These are used to verify that amplifier-specific parameters are within hardware limits.
*/
#define DPGA_IP_MAX_GAIN                    ((uint8)0x07)
#define DPGA_IP_MAX_OFFSET                  ((uint8)0x0F)
#define DPGA_IP_MAX_COMMON_MODE             ((uint8)0x03)
#define DPGA_IP_MAX_COMMON_MODE_ADJUST      ((uint8)0x3F)

/**
* @brief Defines used for Ae_WriteRegister() and Ae_ReadRegister() DataWidth parameters.
*
* @details These are passed as parameters for Ae_WriteRegister() and Ae_ReadRegister() APIs.
*          They represent register width in bits.
*/
#define DPGA_IP_REG_WIDTH_1B                    ((uint8)8U)
#define DPGA_IP_REG_WIDTH_2B                    ((uint8)16U)
#define DPGA_IP_REG_WIDTH_4B                    ((uint8)32U)

#define DPGA_IP_CTRL_REG_RESET_VALUE            (0x08U)
#define DPGA_IP_AMPCFG_REG_RESET_VALUE          (0x00000800U)

/*==================================================================================================
*                                         LOCAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                         LOCAL VARIABLES
==================================================================================================*/
#define DPGA_START_SEC_CONST_UNSPECIFIED
#include "Dpga_MemMap.h"

/* Table of base addresses for DPGA instances */
static DPGA_AE_Type * const Dpga_Ip_apxBase[DPGA_AE_INSTANCE_COUNT] = IP_DPGA_AE_BASE_PTRS;

#define DPGA_STOP_SEC_CONST_UNSPECIFIED
#include "Dpga_MemMap.h"

#define DPGA_START_SEC_VAR_CLEARED_BOOLEAN
#include "Dpga_MemMap.h"

static boolean Dpga_Ip_bInitialized[DPGA_AE_INSTANCE_COUNT];

#define DPGA_STOP_SEC_VAR_CLEARED_BOOLEAN
#include "Dpga_MemMap.h"

#define DPGA_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "Dpga_MemMap.h"

static Dpga_Ip_CallbackType Dpga_Ip_axDpgaCheckCallback[DPGA_AE_INSTANCE_COUNT];

#define DPGA_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "Dpga_MemMap.h"

/*==================================================================================================
*                                        GLOBAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                        GLOBAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                    LOCAL FUNCTION PROTOTYPES
==================================================================================================*/
#define DPGA_START_SEC_CODE
#include "Dpga_MemMap.h"

static Dpga_Ip_StatusType Dpga_Ip_ConfigureBlankingTime(DPGA_AE_Type * const Base,
                                                        const Dpga_Ip_ConfigType * const Config);
/*prototype of function Dpga_Ip_ConvertAecToDpgaStatus*/
static Dpga_Ip_StatusType Dpga_Ip_ConvertAecToDpgaStatus(uint8 aecStatus);
#if (STD_ON == DPGA_IP_ENABLE_VOLTAGE_MONITORING)
static Dpga_Ip_StatusType Dpga_Ip_ConfigureVoltageMonitor(DPGA_AE_Type * const Base,
                                                          const Dpga_Ip_ConfigType * const Config);
#endif

/*==================================================================================================
*                                         LOCAL FUNCTIONS
==================================================================================================*/
/*FUNCTION**********************************************************************
*
* Function Name : Dpga_Ip_ConvertAecToDpgaStatus
* Description   : convert status from Aec to Dpga
*
* END**************************************************************************/
static Dpga_Ip_StatusType Dpga_Ip_ConvertAecToDpgaStatus(uint8 aecStatus)
{
    Dpga_Ip_StatusType ReturnStatus = DPGA_IP_STATUS_ERROR;
    if ((uint8)AEC_STATUS_SUCCESS == aecStatus)
    {
        ReturnStatus = DPGA_IP_STATUS_SUCCESS;
    }
    return ReturnStatus;
}
/*FUNCTION**********************************************************************
*
* Function Name : Dpga_Ip_ConfigureBlankingTime
* Description   : Configure the Blanking time parameters
*
* END**************************************************************************/
static Dpga_Ip_StatusType Dpga_Ip_ConfigureBlankingTime(DPGA_AE_Type * const Base,
                                                        const Dpga_Ip_ConfigType * const Config)
{
    uint32 CtrlReg = 0u;
    uint32 BtCfgReg;
    uint8 AecStatus = 0u;

    /* Set the configuration mode */
    AecStatus = (uint8) Aec_Ip_SpiRead((uint32)(&(Base->CTRL)), DPGA_IP_REG_WIDTH_1B, &CtrlReg);
    CtrlReg = (CtrlReg & (~DPGA_AE_CTRL_CFGEN_MASK)) | DPGA_AE_CTRL_CFGEN(1U);
    AecStatus |= (uint8) Aec_Ip_SpiWrite((uint32)(&(Base->CTRL)), DPGA_IP_REG_WIDTH_1B, CtrlReg);

    /* Configure the Blanking time duration, in number of module cycles */
    BtCfgReg = DPGA_AE_BTCFG_BTDUR(Config->BlankingTimeDuration);
    AecStatus |= (uint8) Aec_Ip_SpiWrite((uint32)(&(Base->BTCFG)), DPGA_IP_REG_WIDTH_4B, BtCfgReg);

    /* Configure the state of the Blanking Time Triggers 0 - 5: on which edge to start the counter for each trigger */
    BtCfgReg = (BtCfgReg & (~(DPGA_AE_BTCFG_SELTRG0_MASK      |
                              DPGA_AE_BTCFG_SELTRG1_MASK      |
                              DPGA_AE_BTCFG_SELTRG2_MASK      |
                              DPGA_AE_BTCFG_SELTRG3_MASK      |
                              DPGA_AE_BTCFG_SELTRG4_MASK      |
                              DPGA_AE_BTCFG_SELTRG5_MASK)))   |
                              DPGA_AE_BTCFG_SELTRG0(Config->BTTriggerStateArray[0U])  |
                              DPGA_AE_BTCFG_SELTRG1(Config->BTTriggerStateArray[1U])  |
                              DPGA_AE_BTCFG_SELTRG2(Config->BTTriggerStateArray[2U])  |
                              DPGA_AE_BTCFG_SELTRG3(Config->BTTriggerStateArray[3U])  |
                              DPGA_AE_BTCFG_SELTRG4(Config->BTTriggerStateArray[4U])  |
                              DPGA_AE_BTCFG_SELTRG5(Config->BTTriggerStateArray[5U]);
    AecStatus |= (uint8) Aec_Ip_SpiWrite((uint32)(&(Base->BTCFG)), DPGA_IP_REG_WIDTH_4B, BtCfgReg);

    /* Set the functional mode */
    CtrlReg = (CtrlReg & (~DPGA_AE_CTRL_CFGEN_MASK)) | DPGA_AE_CTRL_CFGEN(0U);
    AecStatus |= (uint8) Aec_Ip_SpiWrite((uint32)(&(Base->CTRL)), DPGA_IP_REG_WIDTH_1B, CtrlReg);

    return Dpga_Ip_ConvertAecToDpgaStatus(AecStatus);
}

#if (STD_ON == DPGA_IP_ENABLE_VOLTAGE_MONITORING)
/*FUNCTION**********************************************************************
*
* Function Name : Dpga_Ip_ConfigureVoltageMonitor
* Description   : Configure the Voltage Monitor parameters
*
* END**************************************************************************/
static Dpga_Ip_StatusType Dpga_Ip_ConfigureVoltageMonitor(DPGA_AE_Type * const Base,
                                                          const Dpga_Ip_ConfigType * const Config)
{
    uint32 CtrlReg;
    uint32 VdCfgReg;
    uint32 IntfReg;
    uint32 IntEnReg;
    uint8 AecStatus = 0u;

    /* Set the configuration mode */
    CtrlReg = (uint8)DPGA_IP_CTRL_REG_RESET_VALUE | DPGA_AE_CTRL_CFGEN(1U);
    AecStatus = (uint8) Aec_Ip_SpiWrite((uint32)(&(Base->CTRL)), DPGA_IP_REG_WIDTH_1B, CtrlReg);

    /* Set bipolar or unidirectional input mode */
    CtrlReg = (CtrlReg & (~DPGA_AE_CTRL_BIVDEN_MASK)) | DPGA_AE_CTRL_BIVDEN(Config->BipolarInputModeEnable ? 1U : 0U);
    AecStatus |= (uint8) Aec_Ip_SpiWrite((uint32)(&(Base->CTRL)), DPGA_IP_REG_WIDTH_1B, CtrlReg);

    /* Set the upper and lower limits of the allowed voltage range */
    VdCfgReg = DPGA_AE_VDCFG_LDLIM(Config->LowDetectLimit) | DPGA_AE_VDCFG_HDLIM(Config->HighDetectLimit);
    AecStatus |= (uint8) Aec_Ip_SpiWrite((uint32)(&(Base->VDCFG)), DPGA_IP_REG_WIDTH_4B, VdCfgReg);

    /* Set digital filter time that the amplified voltage needs to be out-of-bounds before
       the status bits and interrupt flags are set */
    VdCfgReg = (VdCfgReg & (~(DPGA_AE_VDCFG_LDFDUR_MASK      |
                              DPGA_AE_VDCFG_HDFDUR_MASK)))   |
                              DPGA_AE_VDCFG_LDFDUR(Config->LowDetectFilterDuration)  |
                              DPGA_AE_VDCFG_HDFDUR(Config->HighDetectFilterDuration);
    AecStatus |= (uint8) Aec_Ip_SpiWrite((uint32)(&(Base->VDCFG)), DPGA_IP_REG_WIDTH_4B, VdCfgReg);

    /* Set the functional mode */
    CtrlReg = (CtrlReg & (~DPGA_AE_CTRL_CFGEN_MASK)) | DPGA_AE_CTRL_CFGEN(0U);
    AecStatus |= (uint8) Aec_Ip_SpiWrite((uint32)(&(Base->CTRL)), DPGA_IP_REG_WIDTH_1B, CtrlReg);

    /* Enable the voltage monitors */
    CtrlReg = (CtrlReg & (~DPGA_AE_CTRL_VDEN_MASK)) | DPGA_AE_CTRL_VDEN(1U);
    AecStatus |= (uint8) Aec_Ip_SpiWrite((uint32)(&(Base->CTRL)), DPGA_IP_REG_WIDTH_1B, CtrlReg);

    /* Clear all voltage detect interrupt flags */
    IntfReg = (uint32)DPGA_AE_INTF_LDIF_MASK | DPGA_AE_INTF_HDIF_MASK;
    AecStatus |= (uint8) Aec_Ip_SpiWrite((uint32)(&(Base->INTF)), DPGA_IP_REG_WIDTH_1B, IntfReg);

    /* Enable the voltage detect events */
    IntEnReg = (uint8)DPGA_AE_INTEN_LDIE_MASK | DPGA_AE_INTEN_HDIE_MASK;
    AecStatus |= (uint8) Aec_Ip_SpiWrite((uint32)(&(Base->INTEN)), DPGA_IP_REG_WIDTH_1B, IntEnReg);

    return Dpga_Ip_ConvertAecToDpgaStatus(AecStatus);
}
#endif /* (STD_ON == DPGA_IP_ENABLE_VOLTAGE_MONITORING) */

/*==================================================================================================
*                                        GLOBAL FUNCTIONS
==================================================================================================*/

/*FUNCTION**********************************************************************
*
* Function Name : Dpga_Ip_Init
* Description   : This function initializes the DPGA module.
*
* @implements     Dpga_Ip_Init_Activity
* END**************************************************************************/
Dpga_Ip_StatusType Dpga_Ip_Init(const uint8 Instance,
                                const Dpga_Ip_ConfigType * const Config)
{
    DPGA_AE_Type * Base;
    uint32 IntfReg;
    uint32 IntEnReg = 0u;
    uint32 CtrlReg;
    uint8 AecStatus = 0u;

#if (STD_ON == DPGA_IP_DEV_ERROR_DETECT)
    DevAssert(Config != NULL_PTR);
    DevAssert(Instance < DPGA_AE_INSTANCE_COUNT);
    DevAssert(Dpga_Ip_bInitialized[Instance] == FALSE);
#endif

    Base = Dpga_Ip_apxBase[Instance];

    /* Reset all registers */
    AecStatus = (uint8) Aec_Ip_SpiWrite((uint32)(&(Base->INTF)), DPGA_IP_REG_WIDTH_1B, (uint32)0U);
    AecStatus |= (uint8) Aec_Ip_SpiWrite((uint32)(&(Base->INTEN)), DPGA_IP_REG_WIDTH_1B, (uint32)0U);

    /* Set the configuration mode to reset all configuration registers */
    CtrlReg = (uint8)DPGA_IP_CTRL_REG_RESET_VALUE | DPGA_AE_CTRL_CFGEN(1U);
    AecStatus |= (uint8) Aec_Ip_SpiWrite((uint32)(&(Base->CTRL)), DPGA_IP_REG_WIDTH_1B, CtrlReg);

    AecStatus |= (uint8) Aec_Ip_SpiWrite((uint32)(&(Base->AMPCFG)), DPGA_IP_REG_WIDTH_4B, (uint32)DPGA_IP_AMPCFG_REG_RESET_VALUE);
    AecStatus |= (uint8) Aec_Ip_SpiWrite((uint32)(&(Base->BTCFG)), DPGA_IP_REG_WIDTH_4B, (uint32)0U);

#if (STD_ON == DPGA_IP_ENABLE_VOLTAGE_MONITORING)
    AecStatus |= (uint8) Aec_Ip_SpiWrite((uint32)(&(Base->VDCFG)), DPGA_IP_REG_WIDTH_4B, (uint32)0U);
#endif

    AecStatus |= (uint8) Aec_Ip_SpiWrite((uint32)(&(Base->CTRL)), DPGA_IP_REG_WIDTH_1B, (uint32)DPGA_IP_CTRL_REG_RESET_VALUE);

    Dpga_Ip_axDpgaCheckCallback[Instance] = Config->DpgaCallback;

    AecStatus |= (uint8) Dpga_Ip_ConfigureAmplifier(Instance, Config->AmplifierConfig);

    AecStatus |= (uint8) Dpga_Ip_ConfigureBlankingTime(Base, Config);

#if (STD_ON == DPGA_IP_ENABLE_VOLTAGE_MONITORING)
    AecStatus |= (uint8) Dpga_Ip_ConfigureVoltageMonitor(Base, Config);
#endif

    /* Clear parity check interrupt flags */
    IntfReg = (uint32)DPGA_AE_INTF_AMPCFGIF_MASK | DPGA_AE_INTF_BTCFGIF_MASK;
    AecStatus |= (uint8) Aec_Ip_SpiWrite((uint32)(&(Base->INTF)), DPGA_IP_REG_WIDTH_1B, IntfReg);

    /* Enable parity check events */
    AecStatus |= (uint8) Aec_Ip_SpiRead((uint32)(&(Base->INTEN)), DPGA_IP_REG_WIDTH_1B, &IntEnReg);
    IntEnReg |= (uint32)DPGA_AE_INTEN_AMPCFGIE_MASK | DPGA_AE_INTEN_BTCFGIE_MASK;
    AecStatus |= (uint8) Aec_Ip_SpiWrite((uint32)(&(Base->INTEN)), DPGA_IP_REG_WIDTH_1B, IntEnReg);

    Dpga_Ip_bInitialized[Instance] = TRUE;

    return Dpga_Ip_ConvertAecToDpgaStatus(AecStatus);
}

/*FUNCTION**********************************************************************
*
* Function Name : Dpga_Ip_DeInit
* Description   : This function deinitializes the DPGA module. The driver can't be used untilo initialized again.
*
* @implements     Dpga_Ip_DeInit_Activity
* END**************************************************************************/
Dpga_Ip_StatusType Dpga_Ip_DeInit(const uint8 Instance)
{
    DPGA_AE_Type * Base;
    uint32 CtrlReg;
    uint8 AecStatus = 0u;

#if (STD_ON == DPGA_IP_DEV_ERROR_DETECT)
    DevAssert(Instance < DPGA_AE_INSTANCE_COUNT);
    DevAssert(Dpga_Ip_bInitialized[Instance] == TRUE);
#endif

    Base = Dpga_Ip_apxBase[Instance];

    /* Reset all registers */
    AecStatus = (uint8) Aec_Ip_SpiWrite((uint32)(&(Base->INTF)), DPGA_IP_REG_WIDTH_1B, (uint32)0U);
    AecStatus |= (uint8) Aec_Ip_SpiWrite((uint32)(&(Base->INTEN)), DPGA_IP_REG_WIDTH_1B, (uint32)0U);

    /* Set the configuration mode to reset all configuration registers */
    CtrlReg = (uint8)DPGA_IP_CTRL_REG_RESET_VALUE | DPGA_AE_CTRL_CFGEN(1U);
    AecStatus |= (uint8) Aec_Ip_SpiWrite((uint32)(&(Base->CTRL)), DPGA_IP_REG_WIDTH_1B, CtrlReg);

    AecStatus |= (uint8) Aec_Ip_SpiWrite((uint32)(&(Base->AMPCFG)), DPGA_IP_REG_WIDTH_4B, (uint32)DPGA_IP_AMPCFG_REG_RESET_VALUE);
    AecStatus |= (uint8) Aec_Ip_SpiWrite((uint32)(&(Base->BTCFG)), DPGA_IP_REG_WIDTH_4B, (uint32)0U);

#if (STD_ON == DPGA_IP_ENABLE_VOLTAGE_MONITORING)
    AecStatus |= (uint8) Aec_Ip_SpiWrite((uint32)(&(Base->VDCFG)), DPGA_IP_REG_WIDTH_4B, (uint32)0U);
#endif

    AecStatus |= (uint8) Aec_Ip_SpiWrite((uint32)(&(Base->CTRL)), DPGA_IP_REG_WIDTH_1B, (uint32)DPGA_IP_CTRL_REG_RESET_VALUE);

    Dpga_Ip_bInitialized[Instance] = FALSE;

    return Dpga_Ip_ConvertAecToDpgaStatus(AecStatus);
}

/*FUNCTION**********************************************************************
*
* Function Name : Dpga_Ip_ConfigureAmplifier
* Description   : This function is used to configure the Amplifier.
*
* @implements     Dpga_Ip_ConfigureAmplifier_Activity
* END**************************************************************************/
Dpga_Ip_StatusType Dpga_Ip_ConfigureAmplifier(const uint8 Instance,
                                              const Dpga_Ip_AmplifierConfigType * AmplifierConfig)
{
    DPGA_AE_Type * Base;
    uint32 CtrlReg = 0u;
    uint32 AmpCfgReg;
    uint8 AecStatus = 0u;

#if (STD_ON == DPGA_IP_DEV_ERROR_DETECT)
    DevAssert(AmplifierConfig != NULL_PTR);
    DevAssert(Instance < DPGA_AE_INSTANCE_COUNT);
    DevAssert(AmplifierConfig->OutCommonModeVoltage <= DPGA_IP_MAX_COMMON_MODE);
    DevAssert(AmplifierConfig->AmplifierGain <= DPGA_IP_MAX_GAIN);
    DevAssert(AmplifierConfig->AmplifierOffset <= DPGA_IP_MAX_OFFSET);
    DevAssert(AmplifierConfig->InCommonModeCoarse <= DPGA_IP_MAX_COMMON_MODE);
    DevAssert(AmplifierConfig->InCommonModeFine <= DPGA_IP_MAX_COMMON_MODE_ADJUST);
#endif

    Base = Dpga_Ip_apxBase[Instance];

    /* Disable the DPGA */
    AecStatus = (uint8) Aec_Ip_SpiRead((uint32)(&(Base->CTRL)), DPGA_IP_REG_WIDTH_1B, &CtrlReg);
    CtrlReg = (CtrlReg & (~DPGA_AE_CTRL_EN_MASK)) | DPGA_AE_CTRL_EN(0U);
    AecStatus |= (uint8) Aec_Ip_SpiWrite((uint32)(&(Base->CTRL)), DPGA_IP_REG_WIDTH_1B, CtrlReg);

    /* Set the configuration mode */
    CtrlReg = (CtrlReg & (~DPGA_AE_CTRL_CFGEN_MASK)) | DPGA_AE_CTRL_CFGEN(1U);
    AecStatus |= (uint8) Aec_Ip_SpiWrite((uint32)(&(Base->CTRL)), DPGA_IP_REG_WIDTH_1B, CtrlReg);

    /* Connect the inputs of the Amplifier to the ground (by default, they are connected to the ground) */
    AecStatus |= (uint8) Aec_Ip_SpiWrite((uint32)(&(Base->AMPCFG)), DPGA_IP_REG_WIDTH_4B, (uint32)DPGA_IP_AMPCFG_REG_RESET_VALUE);

    /* Enable the DPGA */
    CtrlReg = (CtrlReg & (~DPGA_AE_CTRL_EN_MASK)) | DPGA_AE_CTRL_EN(1U);
    AecStatus |= (uint8) Aec_Ip_SpiWrite((uint32)(&(Base->CTRL)), DPGA_IP_REG_WIDTH_1B, CtrlReg);

    /* Configure the Amplifier */
    AmpCfgReg = (uint32)DPGA_IP_AMPCFG_REG_RESET_VALUE |
                 DPGA_AE_AMPCFG_GAINSEL(AmplifierConfig->AmplifierGain)       |
                 DPGA_AE_AMPCFG_OCMSEL(AmplifierConfig->OutCommonModeVoltage) |
                 DPGA_AE_AMPCFG_OFFSEL(AmplifierConfig->AmplifierOffset)      |
                 DPGA_AE_AMPCFG_ICMCSEL(AmplifierConfig->InCommonModeCoarse);
    AecStatus |= (uint8) Aec_Ip_SpiWrite((uint32)(&(Base->AMPCFG)), DPGA_IP_REG_WIDTH_4B, AmpCfgReg);
    AmpCfgReg = (AmpCfgReg & (~DPGA_AE_AMPCFG_IGND_MASK)) | DPGA_AE_AMPCFG_IGND(0U);
    AecStatus |= (uint8) Aec_Ip_SpiWrite((uint32)(&(Base->AMPCFG)), DPGA_IP_REG_WIDTH_4B, AmpCfgReg);
    AmpCfgReg = (AmpCfgReg & (~DPGA_AE_AMPCFG_ICMFSEL_MASK)) | DPGA_AE_AMPCFG_ICMFSEL(AmplifierConfig->InCommonModeFine);
    AecStatus |= (uint8) Aec_Ip_SpiWrite((uint32)(&(Base->AMPCFG)), DPGA_IP_REG_WIDTH_4B, AmpCfgReg);

    /* Set the functional mode */
    CtrlReg = (CtrlReg & (~DPGA_AE_CTRL_CFGEN_MASK)) | DPGA_AE_CTRL_CFGEN(0U);
    AecStatus |= (uint8) Aec_Ip_SpiWrite((uint32)(&(Base->CTRL)), DPGA_IP_REG_WIDTH_1B, CtrlReg);

    return Dpga_Ip_ConvertAecToDpgaStatus(AecStatus);
}

/*FUNCTION**********************************************************************
*
* Function Name : Dpga_Ip_IRQHandler
* Description   : This function handles DPGA interrupt events.
*
* END**************************************************************************/
Dpga_Ip_StatusType Dpga_Ip_IRQHandler(const uint8 Instance)
{
    DPGA_AE_Type * Base;

    uint32 IntfReg = 0u;
    uint32 IntEnReg = 0u;
    uint8 AecStatus = 0u;

#if (STD_ON == DPGA_IP_DEV_ERROR_DETECT)
    DevAssert(Instance < DPGA_AE_INSTANCE_COUNT);
#endif

    Base = Dpga_Ip_apxBase[Instance];

    /* If the module is not initialized, clear all interrupt flags */
    if (Dpga_Ip_bInitialized[Instance] == FALSE)
    {

        IntfReg = (uint32)DPGA_AE_INTF_AMPCFGIF_MASK | DPGA_AE_INTF_BTCFGIF_MASK | DPGA_AE_INTF_LDIF_MASK | DPGA_AE_INTF_HDIF_MASK;
        AecStatus = (uint8) Aec_Ip_SpiWrite((uint32)(&(Base->INTF)), DPGA_IP_REG_WIDTH_1B, IntfReg);
    }
    else
    {
        /* Check if the interrupt was spurious. If not, clear the interrupt flag
           and call the corresponding notification callback */
        AecStatus = (uint8) Aec_Ip_SpiRead((uint32)(&(Base->INTF)), DPGA_IP_REG_WIDTH_1B, &IntfReg);
        AecStatus |= (uint8) Aec_Ip_SpiRead((uint32)(&(Base->INTEN)), DPGA_IP_REG_WIDTH_1B, &IntEnReg);

        if (((IntfReg & DPGA_AE_INTF_AMPCFGIF_MASK) != 0U) && (((IntEnReg & DPGA_AE_INTEN_AMPCFGIE_MASK) != 0U)))
        {
            /* Clear interrupt flag */
            IntfReg = (uint32)DPGA_AE_INTF_AMPCFGIF_MASK;
            AecStatus |= (uint8) Aec_Ip_SpiWrite((uint32)(&(Base->INTF)), DPGA_IP_REG_WIDTH_1B, IntfReg);

            if (Dpga_Ip_axDpgaCheckCallback[Instance] != NULL_PTR)
            {
                Dpga_Ip_axDpgaCheckCallback[Instance](DPGA_IP_AMP_PARITY_CHECK_EVENT);
            }
        }

        if (((IntfReg & DPGA_AE_INTF_BTCFGIF_MASK) != 0U) && (((IntEnReg & DPGA_AE_INTEN_BTCFGIE_MASK) != 0U)))
        {
            /* Clear interrupt flag */
            IntfReg = (uint32)DPGA_AE_INTF_BTCFGIF_MASK;
            AecStatus |= (uint8) Aec_Ip_SpiWrite((uint32)(&(Base->INTF)), DPGA_IP_REG_WIDTH_1B, IntfReg);

            if (Dpga_Ip_axDpgaCheckCallback[Instance] != NULL_PTR)
            {
                Dpga_Ip_axDpgaCheckCallback[Instance](DPGA_IP_BT_PARITY_CHECK_EVENT);
            }
        }

#if (STD_ON == DPGA_IP_ENABLE_VOLTAGE_MONITORING)
        if (((IntfReg & DPGA_AE_INTF_LDIF_MASK) != 0U) && (((IntEnReg & DPGA_AE_INTEN_LDIE_MASK) != 0U)))
        {
            /* Clear interrupt flag */
            IntfReg = (uint32)DPGA_AE_INTF_LDIF_MASK;
            AecStatus |= (uint8) Aec_Ip_SpiWrite((uint32)(&(Base->INTF)), DPGA_IP_REG_WIDTH_1B, IntfReg);

            if (Dpga_Ip_axDpgaCheckCallback[Instance] != NULL_PTR)
            {
                Dpga_Ip_axDpgaCheckCallback[Instance](DPGA_IP_LOW_VOLTAGE_DETECT_EVENT);
            }
        }

        if (((IntfReg & DPGA_AE_INTF_HDIF_MASK) != 0U) && (((IntEnReg & DPGA_AE_INTEN_HDIE_MASK) != 0U)))
        {
            /* Clear interrupt flag */
            IntfReg = (uint32)DPGA_AE_INTF_HDIF_MASK;
            AecStatus |= (uint8) Aec_Ip_SpiWrite((uint32)(&(Base->INTF)), DPGA_IP_REG_WIDTH_1B, IntfReg);

            if (Dpga_Ip_axDpgaCheckCallback[Instance] != NULL_PTR)
            {
                Dpga_Ip_axDpgaCheckCallback[Instance](DPGA_IP_HIGH_VOLTAGE_DETECT_EVENT);
            }
        }
#endif /* (STD_ON == DPGA_IP_ENABLE_VOLTAGE_MONITORING) */
    }

    return Dpga_Ip_ConvertAecToDpgaStatus(AecStatus);
}

#define DPGA_STOP_SEC_CODE
#include "Dpga_MemMap.h"


#ifdef __cplusplus
}
#endif

/** @} */
