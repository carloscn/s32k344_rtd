/*==================================================================================================
*   Project              : RTD AUTOSAR 4.7
*   Platform             : CORTEXM
*   Peripheral           : IPV_GDU
*   Dependencies         : none
*
*   Autosar Version      : 4.7.0
*   Autosar Revision     : ASR_REL_4_7_REV_0000
*   Autosar Conf.Variant :
*   SW Version           : 3.0.0
*   Build Version        : S32K3_RTD_3_0_0_D2303_ASR_REL_4_7_REV_0000_20230331
*
*   (c) Copyright 2020 - 2023 NXP Semiconductors
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
*   @file    Gdu_Ip.c
*   @version 3.0.0
*
*   @brief   AUTOSAR Gdu - IPV_GDU main source file.
*
*   @details It implements the main functions of the driver: initialization, delay measurement,
*   slew rate adjustments, and off-state diagnostics. The interrupt handler is implemented in Gdu_Ip_Irq.c.
*
*   @addtogroup IPV_GDU
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
#include "Gdu_Ip.h" /**< Main header file for IPV_GDU */

#include "Aec_Ip.h" /**< Application Extension Controller */

#if (GDU_IP_DEV_ERROR_DETECT == STD_ON)
#include "Devassert.h"
#endif

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define GDU_IP_VENDOR_ID_C                      43
#define GDU_IP_AR_RELEASE_MAJOR_VERSION_C       4
#define GDU_IP_AR_RELEASE_MINOR_VERSION_C       7
#define GDU_IP_AR_RELEASE_REVISION_VERSION_C    0
#define GDU_IP_SW_MAJOR_VERSION_C               3
#define GDU_IP_SW_MINOR_VERSION_C               0
#define GDU_IP_SW_PATCH_VERSION_C               0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
#if (GDU_IP_VENDOR_ID_C != GDU_IP_VENDOR_ID)
    #error "Gdu_Ip.c and Gdu_Ip.h have different vendor ids"
#endif
#if ((GDU_IP_AR_RELEASE_MAJOR_VERSION_C    != GDU_IP_AR_RELEASE_MAJOR_VERSION) || \
     (GDU_IP_AR_RELEASE_MINOR_VERSION_C    != GDU_IP_AR_RELEASE_MINOR_VERSION) || \
     (GDU_IP_AR_RELEASE_REVISION_VERSION_C != GDU_IP_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Gdu_Ip.c and Gdu_Ip.h are different"
#endif
#if ((GDU_IP_SW_MAJOR_VERSION_C != GDU_IP_SW_MAJOR_VERSION) || \
     (GDU_IP_SW_MINOR_VERSION_C != GDU_IP_SW_MINOR_VERSION) || \
     (GDU_IP_SW_PATCH_VERSION_C != GDU_IP_SW_PATCH_VERSION))
    #error "Software Version Numbers of Gdu_Ip.c and Gdu_Ip.h are different"
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
#if (GDU_IP_VENDOR_ID_C != AEC_IP_VENDOR_ID)
    #error "Gdu_Ip.c and Aec_Ip.h have different vendor ids"
#endif
#if ((GDU_IP_AR_RELEASE_MAJOR_VERSION_C    != AEC_IP_AR_RELEASE_MAJOR_VERSION) || \
     (GDU_IP_AR_RELEASE_MINOR_VERSION_C    != AEC_IP_AR_RELEASE_MINOR_VERSION) || \
     (GDU_IP_AR_RELEASE_REVISION_VERSION_C != AEC_IP_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Gdu_Ip.c and Aec_Ip.h are different"
#endif
#if ((GDU_IP_SW_MAJOR_VERSION_C != AEC_IP_SW_MAJOR_VERSION) || \
     (GDU_IP_SW_MINOR_VERSION_C != AEC_IP_SW_MINOR_VERSION) || \
     (GDU_IP_SW_PATCH_VERSION_C != AEC_IP_SW_PATCH_VERSION))
    #error "Software Version Numbers of Gdu_Ip.c and Aec_Ip.h are different"
#endif
#endif

#if (GDU_IP_DEV_ERROR_DETECT == STD_ON)
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if ((GDU_IP_AR_RELEASE_MAJOR_VERSION != DEVASSERT_AR_RELEASE_MAJOR_VERSION) || \
         (GDU_IP_AR_RELEASE_MINOR_VERSION != DEVASSERT_AR_RELEASE_MINOR_VERSION) \
        )
        #error "AutoSar Version Numbers of Gdu_Ip.c and Devassert.h are different"
    #endif
#endif
#endif

/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/
/** Macro used to test development error conditions */
#if (GDU_IP_DEV_ERROR_DETECT == STD_ON)
#define GDU_IP_DEV_ASSERT(Expression)   DevAssert(Expression)
#else
#define GDU_IP_DEV_ASSERT(Expression)
#endif

/*==================================================================================================
*                                      LOCAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      LOCAL VARIABLES
==================================================================================================*/
#define GDU_START_SEC_VAR_CLEARED_BOOLEAN
#include "Gdu_MemMap.h"

/** Holds the state of driver's initialization */
static boolean Gdu_Ip_bInitialized;

#define GDU_STOP_SEC_VAR_CLEARED_BOOLEAN
#include "Gdu_MemMap.h"
#define GDU_START_SEC_VAR_CLEARED_16
#include "Gdu_MemMap.h"

/** Save the state of the CTL register to avoid reading it when a RMW operation is needed */
static uint16 Gdu_Ip_u16ControlRegister;

#define GDU_STOP_SEC_VAR_CLEARED_16
#include "Gdu_MemMap.h"
#define GDU_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "Gdu_MemMap.h"

/** Pointer to the (const) configuration structure */
static const Gdu_Ip_ConfigType * Gdu_Ip_pConfiguration;

#define GDU_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "Gdu_MemMap.h"

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
#define GDU_START_SEC_CODE
#include "Gdu_MemMap.h"

/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/

Gdu_Ip_StatusType Gdu_Ip_Init (
    const Gdu_Ip_ConfigType * const Configuration)
{
    Gdu_Ip_StatusType Status = GDU_IP_STATUS_ERROR;
    uint8 AecStatus = 0u;
    uint16 ControlRegister = 0u;

    GDU_IP_DEV_ASSERT(Configuration != NULL_PTR);

    /* Enable safe state and cfg mode:
     * rewrite the reset values that are present in the received configuration structure. */
    ControlRegister = Configuration->CTL;
    /* Disable the boost converter, the charge pump to allow their configuration. */
    ControlRegister &= (uint16) ~(GDU_AE_CTL_BOOSTEN_MASK | GDU_AE_CTL_CPEN_MASK);
    /* Enable register write to allow the configuration of slew rates and Iref trimming. */
    ControlRegister |= GDU_AE_CTL_RWEN_MASK;
    AecStatus |= (uint8) Aec_Ip_SpiWrite(IP_GDU_AE_BASE + GDU_IP_REG_CTL, GDU_IP_REG_SIZE_16b, ControlRegister);

    if ((uint8) AEC_STATUS_SUCCESS == AecStatus)
    {
        Gdu_Ip_u16ControlRegister = ControlRegister; /* CTL has been written successfully */

        /* INTF does not contain configuration fields */
        AecStatus |= (uint8) Aec_Ip_SpiWrite(IP_GDU_AE_BASE + GDU_IP_REG_INTEN, GDU_IP_REG_SIZE_8b, Configuration->INTEN);
        /* STAT does not contain configuration fields */
        /* CTL does not contain configuration fields */
        AecStatus |= (uint8) Aec_Ip_SpiWrite(IP_GDU_AE_BASE + GDU_IP_REG_CFG, GDU_IP_REG_SIZE_8b, Configuration->CFG);
        AecStatus |= (uint8) Aec_Ip_SpiWrite(IP_GDU_AE_BASE + GDU_IP_REG_EACFG, GDU_IP_REG_SIZE_8b, Configuration->EACFG);
        AecStatus |= (uint8) Aec_Ip_SpiWrite(IP_GDU_AE_BASE + GDU_IP_REG_BOOSTCFG, GDU_IP_REG_SIZE_16b, Configuration->BOOSTCFG);
        AecStatus |= (uint8) Aec_Ip_SpiWrite(IP_GDU_AE_BASE + GDU_IP_REG_BTCFG, GDU_IP_REG_SIZE_16b, Configuration->BTCFG);
        AecStatus |= (uint8) Aec_Ip_SpiWrite(IP_GDU_AE_BASE + GDU_IP_REG_HSSRON, GDU_IP_REG_SIZE_32b, Configuration->HSSRON);
        AecStatus |= (uint8) Aec_Ip_SpiWrite(IP_GDU_AE_BASE + GDU_IP_REG_HSSROFF, GDU_IP_REG_SIZE_32b, Configuration->HSSROFF);
        AecStatus |= (uint8) Aec_Ip_SpiWrite(IP_GDU_AE_BASE + GDU_IP_REG_LSSRON, GDU_IP_REG_SIZE_32b, Configuration->LSSRON);
        AecStatus |= (uint8) Aec_Ip_SpiWrite(IP_GDU_AE_BASE + GDU_IP_REG_LSSROFF, GDU_IP_REG_SIZE_32b, Configuration->LSSROFF);
        AecStatus |= (uint8) Aec_Ip_SpiWrite(IP_GDU_AE_BASE + GDU_IP_REG_OFFSDCFG, GDU_IP_REG_SIZE_8b, Configuration->OFFSDCFG);
        AecStatus |= (uint8) Aec_Ip_SpiWrite(IP_GDU_AE_BASE + GDU_IP_REG_DSCFG, GDU_IP_REG_SIZE_16b, Configuration->DSCFG);
        AecStatus |= (uint8) Aec_Ip_SpiWrite(IP_GDU_AE_BASE + GDU_IP_REG_CPCFG, GDU_IP_REG_SIZE_32b, Configuration->CPCFG);
        /* DLYMR does not contain configuration fields */
        /* DLYMCFG does not contain configuration fields that are to be progrmammed at init */
        AecStatus |= (uint8) Aec_Ip_SpiWrite(IP_GDU_AE_BASE + GDU_IP_REG_SUPCFG, GDU_IP_REG_SIZE_8b, Configuration->SUPCFG);

        if ((ControlRegister & GDU_AE_CTL_IRTSW_MASK) != 0u)
        {
            /* "you can write this register only when Iref trimming by software is enabled" */
            AecStatus |= (uint8) Aec_Ip_SpiWrite(IP_GDU_AE_BASE + GDU_IP_REG_IRT, GDU_IP_REG_SIZE_32b, Configuration->IRT);
        }
    }

    if ((uint8) AEC_STATUS_SUCCESS == AecStatus)
    {
        /* Program the BOOSTEN parameter (the bit is cleared already). */
        ControlRegister |= Configuration->CTL & GDU_AE_CTL_BOOSTEN_MASK;
        /* Enable the charge pump. */
        ControlRegister |= GDU_AE_CTL_CPEN_MASK;
        /* Disable safe state, cfg mode and register write. */
        ControlRegister &= (uint16) ~(GDU_AE_CTL_SSTEN_MASK | GDU_AE_CTL_CFGEN_MASK | GDU_AE_CTL_RWEN_MASK);
        AecStatus |= (uint8) Aec_Ip_SpiWrite(IP_GDU_AE_BASE + GDU_IP_REG_CTL, GDU_IP_REG_SIZE_16b, ControlRegister);
    }

    if ((uint8) AEC_STATUS_SUCCESS == AecStatus)
    {
        Gdu_Ip_bInitialized = TRUE;
        Gdu_Ip_pConfiguration = Configuration;
        Gdu_Ip_u16ControlRegister = ControlRegister; /* CTL has been written successfully */
        Status = GDU_IP_STATUS_OK;
    }

    return Status;
}

Gdu_Ip_StatusType Gdu_Ip_SetMode (
    Gdu_Ip_ModeType Mode)
{
    Gdu_Ip_StatusType Status = GDU_IP_STATUS_OK;
    uint16 ControlRegister = Gdu_Ip_u16ControlRegister;

    GDU_IP_DEV_ASSERT(Gdu_Ip_bInitialized == TRUE);
    GDU_IP_DEV_ASSERT(Mode > GDU_IP_MODE_MIN);
    GDU_IP_DEV_ASSERT(Mode < GDU_IP_MODE_MAX);

    switch (Mode)
    {
        case GDU_IP_MODE_ENABLE:
            ControlRegister |= GDU_AE_CTL_GDUEN_MASK; /* enable the gate drivers */
            ControlRegister |= Gdu_Ip_pConfiguration->CTL & GDU_AE_CTL_CPEN_MASK; /* restore the CPEN configuration */
        break;

        case GDU_IP_MODE_DISABLE:
            /* the charge pump must be disabled along with GDUEN */
            ControlRegister &= (uint16) ~(GDU_AE_CTL_GDUEN_MASK | GDU_AE_CTL_CPEN_MASK);
        break;

        default:
            Status = GDU_IP_STATUS_ERROR;
        break;
    }

    if (GDU_IP_STATUS_OK == Status)
    {
        if (AEC_STATUS_SUCCESS == Aec_Ip_SpiWrite(IP_GDU_AE_BASE + GDU_IP_REG_CTL, GDU_IP_REG_SIZE_16b, ControlRegister))
        {
            Gdu_Ip_u16ControlRegister = ControlRegister; /* CTL has been written successfully */
        }
        else
        {
            Status = GDU_IP_STATUS_ERROR;
        }
    }

    return Status;
}

Gdu_Ip_StatusType Gdu_Ip_SetSafeState (
    Gdu_Ip_SafeStateType SafeState)
{
    Gdu_Ip_StatusType Status = GDU_IP_STATUS_OK;
    uint16 ControlRegister = Gdu_Ip_u16ControlRegister;

    GDU_IP_DEV_ASSERT(Gdu_Ip_bInitialized == TRUE);
    GDU_IP_DEV_ASSERT(SafeState > GDU_IP_SAFESTATE_MIN);
    GDU_IP_DEV_ASSERT(SafeState < GDU_IP_SAFESTATE_MAX);

    switch (SafeState)
    {
        case GDU_IP_SAFESTATE_ON:
            ControlRegister |= GDU_AE_CTL_SSTEN_MASK; /* enable safe state */
        break;

        case GDU_IP_SAFESTATE_OFF:
            ControlRegister &= ~(uint16)GDU_AE_CTL_SSTEN_MASK; /* disable safe state */
        break;

        default:
            Status = GDU_IP_STATUS_ERROR;
        break;
    }

    if (GDU_IP_STATUS_OK == Status)
    {
        if (AEC_STATUS_SUCCESS == Aec_Ip_SpiWrite(IP_GDU_AE_BASE + GDU_IP_REG_CTL, GDU_IP_REG_SIZE_16b, ControlRegister))
        {
            Gdu_Ip_u16ControlRegister = ControlRegister; /* CTL has been written successfully */
        }
        else
        {
            Status = GDU_IP_STATUS_ERROR;
        }
    }

    return Status;
}

Gdu_Ip_StatusType Gdu_Ip_GetStatus (
    Gdu_Ip_ErrorStatusType * ErrorStatus)
{
    Gdu_Ip_StatusType Status = GDU_IP_STATUS_OK;
    uint32 FlagRegister = 0u;
    uint32 FlagMask = 0u;

    GDU_IP_DEV_ASSERT(Gdu_Ip_bInitialized == TRUE);

    if (AEC_STATUS_SUCCESS == Aec_Ip_SpiRead(IP_GDU_AE_BASE + GDU_IP_REG_INTF, GDU_IP_REG_SIZE_8b, &FlagRegister))
    {
        if (NULL_PTR == ErrorStatus)
        {
            FlagMask = GDU_AE_INTF_DLSIF0_MASK |
                       GDU_AE_INTF_DLSIF1_MASK |
                       GDU_AE_INTF_DLSIF2_MASK |
                       GDU_AE_INTF_DHSIF0_MASK |
                       GDU_AE_INTF_DHSIF1_MASK |
                       GDU_AE_INTF_DHSIF2_MASK |
                       GDU_AE_INTF_HDHVDIF_MASK;
            if ((FlagRegister & FlagMask) != 0u)
            {
                Status = GDU_IP_STATUS_ERRORCONDITION;
            }
        }
        else
        {
            if ((FlagRegister & GDU_AE_INTF_DLSIF0_MASK) != 0u)
            {
                ErrorStatus->DesaturationLS0 = TRUE;
                Status = GDU_IP_STATUS_ERRORCONDITION;
            }

            if ((FlagRegister & GDU_AE_INTF_DLSIF1_MASK) != 0u)
            {
                ErrorStatus->DesaturationLS1 = TRUE;
                Status = GDU_IP_STATUS_ERRORCONDITION;
            }

            if ((FlagRegister & GDU_AE_INTF_DLSIF2_MASK) != 0u)
            {
                ErrorStatus->DesaturationLS2 = TRUE;
                Status = GDU_IP_STATUS_ERRORCONDITION;
            }

            if ((FlagRegister & GDU_AE_INTF_DHSIF0_MASK) != 0u)
            {
                ErrorStatus->DesaturationHS0 = TRUE;
                Status = GDU_IP_STATUS_ERRORCONDITION;
            }

            if ((FlagRegister & GDU_AE_INTF_DHSIF1_MASK) != 0u)
            {
                ErrorStatus->DesaturationHS1 = TRUE;
                Status = GDU_IP_STATUS_ERRORCONDITION;
            }

            if ((FlagRegister & GDU_AE_INTF_DHSIF2_MASK) != 0u)
            {
                ErrorStatus->DesaturationHS2 = TRUE;
                Status = GDU_IP_STATUS_ERRORCONDITION;
            }

            if ((FlagRegister & GDU_AE_INTF_HDHVDIF_MASK) != 0u)
            {
                ErrorStatus->HighVoltageHD = TRUE;
                Status = GDU_IP_STATUS_ERRORCONDITION;
            }
        }
    }
    else
    {
        Status = GDU_IP_STATUS_ERROR;
    }

    return Status;
}

Gdu_Ip_StatusType Gdu_Ip_StartDelayMeasurement (
    Gdu_Ip_PwmChannelType PwmChannel,
    Gdu_Ip_EdgeType Edge)
{
    Gdu_Ip_StatusType Status = GDU_IP_STATUS_ERROR;
    uint16 DlymcfgReg = 0u;

    GDU_IP_DEV_ASSERT(Gdu_Ip_bInitialized == TRUE);
    GDU_IP_DEV_ASSERT(PwmChannel > GDU_IP_PWM_CHANNEL_MIN);
    GDU_IP_DEV_ASSERT(PwmChannel < GDU_IP_PWM_CHANNEL_MAX);
    GDU_IP_DEV_ASSERT(Edge > GDU_IP_EDGE_MIN);
    GDU_IP_DEV_ASSERT(Edge < GDU_IP_EDGE_MAX);

    DlymcfgReg = GDU_AE_DLYMCFG_CHSEL(PwmChannel) | GDU_AE_DLYMCFG_EDGESEL(Edge);

    if (AEC_STATUS_SUCCESS == Aec_Ip_SpiWrite(IP_GDU_AE_BASE + GDU_IP_REG_DLYMCFG, GDU_IP_REG_SIZE_16b, DlymcfgReg))
    {
        if (AEC_STATUS_SUCCESS == Aec_Ip_SpiWrite(IP_GDU_AE_BASE + GDU_IP_REG_CTL, GDU_IP_REG_SIZE_16b,
                                                  (uint32)Gdu_Ip_u16ControlRegister | GDU_AE_CTL_DMEN_MASK))
        {
            /* "When the counter expires, GDU writes 0 to this field" - that's why we don't set DMEN in CTL */
            Status = GDU_IP_STATUS_OK;
        }
    }

    return Status;
}

Gdu_Ip_StatusType Gdu_Ip_ReadDelayMeasurement (
    uint8 * Delay)
{
    Gdu_Ip_StatusType Status = GDU_IP_STATUS_ERROR;
    uint32 DlymrReg = 0u;

    GDU_IP_DEV_ASSERT(Gdu_Ip_bInitialized == TRUE);
    GDU_IP_DEV_ASSERT(Delay != NULL_PTR);

    if (AEC_STATUS_SUCCESS == Aec_Ip_SpiRead(IP_GDU_AE_BASE + GDU_IP_REG_DLYMR, GDU_IP_REG_SIZE_32b, &DlymrReg))
    {
        if ((DlymrReg & GDU_AE_DLYMR_DATAVAL_MASK) != 0u)
        {
            *Delay = (uint8) ((DlymrReg & GDU_AE_DLYMR_DELAY_MASK) >> GDU_AE_DLYMR_DELAY_SHIFT);
            Status = GDU_IP_STATUS_OK;
        }
        else
        {
            Status = GDU_IP_STATUS_INVALID;
        }
    }

    return Status;
}

Gdu_Ip_StatusType Gdu_Ip_AdjustSlewRate (
    Gdu_Ip_SlewRateSelectType SlewRateSelect,
    const Gdu_Ip_SlewRateConfigType * SlewRateConfig)
{
    Gdu_Ip_StatusType Status = GDU_IP_STATUS_OK;
    uint16 ControlRegister = 0u;
    uint32 SlewRateRegOffset = 0u;
    uint32 SlewRateRegister = 0u;

    GDU_IP_DEV_ASSERT(Gdu_Ip_bInitialized == TRUE);
    GDU_IP_DEV_ASSERT(SlewRateSelect > GDU_IP_SLEWRATE_MIN);
    GDU_IP_DEV_ASSERT(SlewRateSelect < GDU_IP_SLEWRATE_MAX);
    GDU_IP_DEV_ASSERT(SlewRateConfig != NULL_PTR);

    switch (SlewRateSelect)
    {
        case GDU_IP_SLEWRATE_HS_ON:
            SlewRateRegOffset = GDU_IP_REG_HSSRON;
            SlewRateRegister = GDU_AE_HSSRON_HSTONT_P1(SlewRateConfig->TimePoint1) |
                               GDU_AE_HSSRON_HSTONT_P2(SlewRateConfig->TimePoint2) |
                               GDU_AE_HSSRON_HSTONC_P1(SlewRateConfig->Slew1) |
                               GDU_AE_HSSRON_HSTONC_P2(SlewRateConfig->Slew2) |
                               GDU_AE_HSSRON_HSTONC_P3(SlewRateConfig->Slew3);
        break;

        case GDU_IP_SLEWRATE_HS_OFF:
            SlewRateRegOffset = GDU_IP_REG_HSSROFF;
            SlewRateRegister = GDU_AE_HSSROFF_HSTOFFT_P1(SlewRateConfig->TimePoint1) |
                               GDU_AE_HSSROFF_HSTOFFT_P2(SlewRateConfig->TimePoint2) |
                               GDU_AE_HSSROFF_HSTOFFC_P1(SlewRateConfig->Slew1) |
                               GDU_AE_HSSROFF_HSTOFFC_P2(SlewRateConfig->Slew2) |
                               GDU_AE_HSSROFF_HSTOFFC_P3(SlewRateConfig->Slew3);
        break;

        case GDU_IP_SLEWRATE_LS_ON:
            SlewRateRegOffset = GDU_IP_REG_LSSRON;
            SlewRateRegister = GDU_AE_LSSRON_LSTONT_P1(SlewRateConfig->TimePoint1) |
                               GDU_AE_LSSRON_LSTONT_P2(SlewRateConfig->TimePoint2) |
                               GDU_AE_LSSRON_LSTONC_P1(SlewRateConfig->Slew1) |
                               GDU_AE_LSSRON_LSTONC_P2(SlewRateConfig->Slew2) |
                               GDU_AE_LSSRON_LSTONC_P3(SlewRateConfig->Slew3);
        break;

        case GDU_IP_SLEWRATE_LS_OFF:
            SlewRateRegOffset = GDU_IP_REG_LSSROFF;
            SlewRateRegister = GDU_AE_LSSROFF_LSTOFFT_P1(SlewRateConfig->TimePoint1) |
                               GDU_AE_LSSROFF_LSTOFFT_P2(SlewRateConfig->TimePoint2) |
                               GDU_AE_LSSROFF_LSTOFFC_P1(SlewRateConfig->Slew1) |
                               GDU_AE_LSSROFF_LSTOFFC_P2(SlewRateConfig->Slew2) |
                               GDU_AE_LSSROFF_LSTOFFC_P3(SlewRateConfig->Slew3);
        break;

        default:
            Status = GDU_IP_STATUS_INVALID;
        break;
    }

    if (GDU_IP_STATUS_OK == Status)
    {
        Status = GDU_IP_STATUS_ERROR;
        ControlRegister = Gdu_Ip_u16ControlRegister | GDU_AE_CTL_RWEN_MASK; /* safe state can be achieved through the API */

        if (AEC_STATUS_SUCCESS == Aec_Ip_SpiWrite(IP_GDU_AE_BASE + GDU_IP_REG_CTL, GDU_IP_REG_SIZE_16b, ControlRegister))
        {
            if (AEC_STATUS_SUCCESS == Aec_Ip_SpiWrite(IP_GDU_AE_BASE + SlewRateRegOffset, GDU_IP_REG_SIZE_32b, SlewRateRegister))
            {
                if (AEC_STATUS_SUCCESS == Aec_Ip_SpiWrite(IP_GDU_AE_BASE + GDU_IP_REG_CTL, GDU_IP_REG_SIZE_16b, Gdu_Ip_u16ControlRegister))
                {
                    Status = GDU_IP_STATUS_OK;
                }
            }
        }
    }

    return Status;
}

Gdu_Ip_StatusType Gdu_Ip_SwIrefTrimming (
    Gdu_Ip_IrefTrimmingType IrefTrimming)
{
    Gdu_Ip_StatusType Status = GDU_IP_STATUS_ERROR;
    uint16 ControlRegister = 0u;
    uint32 IrefTrimmingRegister = 0u;

    GDU_IP_DEV_ASSERT(Gdu_Ip_bInitialized == TRUE);
    GDU_IP_DEV_ASSERT(IrefTrimming.LG0 > GDU_IP_IREF_TRIM_MIN);
    GDU_IP_DEV_ASSERT(IrefTrimming.LG0 < GDU_IP_IREF_TRIM_MAX);
    GDU_IP_DEV_ASSERT(IrefTrimming.LG1 > GDU_IP_IREF_TRIM_MIN);
    GDU_IP_DEV_ASSERT(IrefTrimming.LG1 < GDU_IP_IREF_TRIM_MAX);
    GDU_IP_DEV_ASSERT(IrefTrimming.LG2 > GDU_IP_IREF_TRIM_MIN);
    GDU_IP_DEV_ASSERT(IrefTrimming.LG2 < GDU_IP_IREF_TRIM_MAX);
    GDU_IP_DEV_ASSERT(IrefTrimming.HG0 > GDU_IP_IREF_TRIM_MIN);
    GDU_IP_DEV_ASSERT(IrefTrimming.HG0 < GDU_IP_IREF_TRIM_MAX);
    GDU_IP_DEV_ASSERT(IrefTrimming.HG1 > GDU_IP_IREF_TRIM_MIN);
    GDU_IP_DEV_ASSERT(IrefTrimming.HG1 < GDU_IP_IREF_TRIM_MAX);
    GDU_IP_DEV_ASSERT(IrefTrimming.HG2 > GDU_IP_IREF_TRIM_MIN);
    GDU_IP_DEV_ASSERT(IrefTrimming.HG2 < GDU_IP_IREF_TRIM_MAX);

    Gdu_Ip_u16ControlRegister |= GDU_AE_CTL_IRTSW_MASK; /* permanently enable SW Iref trimming */
    ControlRegister = Gdu_Ip_u16ControlRegister | GDU_AE_CTL_RWEN_MASK; /* temporarily enable register writes */

    if (AEC_STATUS_SUCCESS == Aec_Ip_SpiWrite(IP_GDU_AE_BASE + GDU_IP_REG_CTL, GDU_IP_REG_SIZE_16b, ControlRegister))
    {
        IrefTrimmingRegister = GDU_AE_IRT_IRT0P0(IrefTrimming.LG0) |
                               GDU_AE_IRT_IRT1P0(IrefTrimming.HG0) |
                               GDU_AE_IRT_IRT0P1(IrefTrimming.LG1) |
                               GDU_AE_IRT_IRT1P1(IrefTrimming.HG1) |
                               GDU_AE_IRT_IRT0P2(IrefTrimming.LG2) |
                               GDU_AE_IRT_IRT1P2(IrefTrimming.HG2);

        if (AEC_STATUS_SUCCESS == Aec_Ip_SpiWrite(IP_GDU_AE_BASE + GDU_IP_REG_IRT, GDU_IP_REG_SIZE_32b, IrefTrimmingRegister))
        {
            if (AEC_STATUS_SUCCESS == Aec_Ip_SpiWrite(IP_GDU_AE_BASE + GDU_IP_REG_CTL, GDU_IP_REG_SIZE_16b, Gdu_Ip_u16ControlRegister))
            {
                Status = GDU_IP_STATUS_OK;
            }
        }
    }

    return Status;
}

Gdu_Ip_StatusType Gdu_Ip_OffStateDiagnostics (
    Gdu_Ip_OffStateDiagType OffStateDiagnostics)
{
    Gdu_Ip_StatusType Status = GDU_IP_STATUS_ERROR;
    uint8 OffStateDiagRegister = 0u;

    GDU_IP_DEV_ASSERT(Gdu_Ip_bInitialized == TRUE);

    OffStateDiagRegister = GDU_AE_OFFSDCFG_OSDPD0(OffStateDiagnostics.PullHs0Down ? 1u : 0u) |
                           GDU_AE_OFFSDCFG_OSDPD1(OffStateDiagnostics.PullHs1Down ? 1u : 0u) |
                           GDU_AE_OFFSDCFG_OSDPD2(OffStateDiagnostics.PullHs2Down ? 1u : 0u) |
                           GDU_AE_OFFSDCFG_OSDPU0(OffStateDiagnostics.PullHs0Up ? 1u : 0u) |
                           GDU_AE_OFFSDCFG_OSDPU1(OffStateDiagnostics.PullHs1Up ? 1u : 0u) |
                           GDU_AE_OFFSDCFG_OSDPU2(OffStateDiagnostics.PullHs2Up ? 1u : 0u);

    if (AEC_STATUS_SUCCESS == Aec_Ip_SpiWrite(IP_GDU_AE_BASE + GDU_IP_REG_OFFSDCFG, GDU_IP_REG_SIZE_8b, (uint32)OffStateDiagRegister))
    {
        Status = GDU_IP_STATUS_OK;
    }

    return Status;
}

void Gdu_Ip_ISR (
    void)
{
    uint32 InterruptFlags = 0u;
    Gdu_Ip_NotificationType Gdu_Ip_Notification = GDU_IP_NOTIFICATION;

    if (AEC_STATUS_SUCCESS == Aec_Ip_SpiRead(IP_GDU_AE_BASE + GDU_IP_REG_INTF, GDU_IP_REG_SIZE_8b, &InterruptFlags))
    {
        /* clear the reserved bits */
        InterruptFlags &= GDU_AE_INTF_DLSIF0_MASK |
                          GDU_AE_INTF_DLSIF1_MASK |
                          GDU_AE_INTF_DLSIF2_MASK |
                          GDU_AE_INTF_DHSIF0_MASK |
                          GDU_AE_INTF_DHSIF1_MASK |
                          GDU_AE_INTF_DHSIF2_MASK |
                          GDU_AE_INTF_HDHVDIF_MASK;

        if (Gdu_Ip_bInitialized)
        {
            /* notify only for the enabled flags */
            if ((Gdu_Ip_pConfiguration->INTEN & InterruptFlags) != 0u)
            {
                if (Gdu_Ip_Notification != NULL_PTR)
                {
                    Gdu_Ip_Notification(Gdu_Ip_pConfiguration->INTEN & InterruptFlags);
                }
            }
        }

        /* clear all triggered flags */
        (void) Aec_Ip_SpiWrite(IP_GDU_AE_BASE + GDU_IP_REG_INTF, GDU_IP_REG_SIZE_8b, InterruptFlags);
    }
    else
    {
        /* something is wrong with the comm to AE
         * without it, we cannot treat the IRQ */
    }
}

#define GDU_STOP_SEC_CODE
#include "Gdu_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */
