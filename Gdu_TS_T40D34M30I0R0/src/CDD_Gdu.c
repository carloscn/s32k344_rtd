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
*   @file    CDD_Gdu.c
*   @version 3.0.0
*
*   @brief   AUTOSAR Gdu - HLD main source file.
*   @details Acts mostly as a wrapper for the low level driver.
*
*   @addtogroup CDD_GDU
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
#include "CDD_Gdu.h"

#if (GDU_DEV_ERROR_DETECT == STD_ON)
#include "Det.h"
#endif

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define GDU_VENDOR_ID_C                      43
#define GDU_AR_RELEASE_MAJOR_VERSION_C       4
#define GDU_AR_RELEASE_MINOR_VERSION_C       7
#define GDU_AR_RELEASE_REVISION_VERSION_C    0
#define GDU_SW_MAJOR_VERSION_C               3
#define GDU_SW_MINOR_VERSION_C               0
#define GDU_SW_PATCH_VERSION_C               0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
#if (GDU_VENDOR_ID_C != GDU_VENDOR_ID)
    #error "CDD_Gdu.c and CDD_Gdu.h have different vendor ids"
#endif
#if ((GDU_AR_RELEASE_MAJOR_VERSION_C    != GDU_AR_RELEASE_MAJOR_VERSION) || \
     (GDU_AR_RELEASE_MINOR_VERSION_C    != GDU_AR_RELEASE_MINOR_VERSION) || \
     (GDU_AR_RELEASE_REVISION_VERSION_C != GDU_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of CDD_Gdu.c and CDD_Gdu.h are different"
#endif
#if ((GDU_SW_MAJOR_VERSION_C != GDU_SW_MAJOR_VERSION) || \
     (GDU_SW_MINOR_VERSION_C != GDU_SW_MINOR_VERSION) || \
     (GDU_SW_PATCH_VERSION_C != GDU_SW_PATCH_VERSION))
    #error "Software Version Numbers of CDD_Gdu.c and CDD_Gdu.h are different"
#endif

#if (GDU_DEV_ERROR_DETECT == STD_ON)
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
        /* Check if source file and DET header file are of the same version */
        #if ((GDU_AR_RELEASE_MAJOR_VERSION_C != DET_AR_RELEASE_MAJOR_VERSION) || \
             (GDU_AR_RELEASE_MINOR_VERSION_C != DET_AR_RELEASE_MINOR_VERSION) \
            )
            #error "AutoSar Version Numbers of CDD_Gdu.c and Det.h are different"
        #endif
#endif /* DISABLE_MCAL_INTERMODULE_ASR_CHECK */
#endif /* GDU_DEV_ERROR_DETECT == STD_ON */

/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/
#if (GDU_DEV_ERROR_DETECT == STD_ON)

/** Macro used to skip the dev error checks by replacing the given expression with TRUE */
#define GDU_DEV_ASSERT(Expression) (Expression)

/** Macro used to skip the error reporting to Det when GDU_DEV_ERROR_DETECT is STD_OFF */
#define Gdu_ReportDetError(ServiceId, ErrorId) \
    (void) Det_ReportError((uint16)GDU_MODULE_ID, 0u, ServiceId, ErrorId);

#else /* GDU_DEV_ERROR_DETECT == STD_ON */

/** Macro used to skip the dev error checks by replacing the given expression with TRUE */
#define GDU_DEV_ASSERT(Expression) (TRUE)

/** Macro used to skip the error reporting to Det when GDU_DEV_ERROR_DETECT is STD_OFF */
#define Gdu_ReportDetError(ServiceId, ErrorId)

#endif /* GDU_DEV_ERROR_DETECT == STD_ON */

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

static boolean Gdu_bInitialized;

#define GDU_STOP_SEC_VAR_CLEARED_BOOLEAN
#include "Gdu_MemMap.h"
#define GDU_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "Gdu_MemMap.h"

static const Gdu_Ip_ConfigType * Gdu_pConfiguration;

#define GDU_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "Gdu_MemMap.h"

/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/
#define GDU_START_SEC_CODE
#include "Gdu_MemMap.h"

/** * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
* @brief        Check the argument given to the Init API and store it if it's valid.
*
* @param[in]    Configuration Contains the address of the configuration structure.
*
* @return       Returns the status of the pointer validation.
* @retval       TRUE the argument is valid, and Gdu_pConfiguration was assigned a valid address
* @retval       FALSE the argument is invalid for the specified configuration class
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
static boolean Gdu_StoreConfiguration (
    const Gdu_Ip_ConfigType * Configuration)
{
    boolean Status = FALSE;

#if (GDU_PRECOMPILE_SUPPORT == STD_ON)
    if (GDU_DEV_ASSERT(Configuration == NULL_PTR))
    {
        Gdu_pConfiguration = Gdu_ConfigVariantPredefined[0];
        Status = TRUE;
    }
#else /* GDU_PRECOMPILE_SUPPORT */
    if (GDU_DEV_ASSERT(Configuration != NULL_PTR))
    {
        Gdu_pConfiguration = Configuration;
        Status = TRUE;
    }
#endif /* GDU_PRECOMPILE_SUPPORT */
    else
    {
        Gdu_ReportDetError(GDU_DET_SERVICE_INITIALIZATION, GDU_DET_ERROR_PARAMETER);
    }

    return Status;
}

/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/

Std_ReturnType Gdu_Init (
    const Gdu_Ip_ConfigType * Configuration)
{
    Std_ReturnType Status = GDU_RET_INVALID;

    if (Gdu_StoreConfiguration(Configuration))
    {
        if (GDU_IP_STATUS_OK == Gdu_Ip_Init(Gdu_pConfiguration))
        {
            Status = E_OK;
            Gdu_bInitialized = TRUE;
        }
        else
        {
            Status = E_NOT_OK;
        }
    }
    else
    {
        Status = GDU_RET_DET_PARAM;
    }

    return Status;
}

Std_ReturnType Gdu_SetMode (
    Gdu_Ip_ModeType Mode)
{
    Std_ReturnType Status = GDU_RET_INVALID;

    if (GDU_DEV_ASSERT(Gdu_bInitialized))
    {
        if (GDU_DEV_ASSERT((Mode > GDU_IP_MODE_MIN) && (Mode < GDU_IP_MODE_MAX)))
        {
            if (GDU_IP_STATUS_OK == Gdu_Ip_SetMode(Mode))
            {
                Status = E_OK;
            }
            else
            {
                Status = E_NOT_OK;
            }
        }
        else
        {
            Gdu_ReportDetError(GDU_DET_SERVICE_SETMODE, GDU_DET_ERROR_PARAMETER);
            Status = GDU_RET_DET_PARAM;
        }
    }
    else
    {
        Gdu_ReportDetError(GDU_DET_SERVICE_SETMODE, GDU_DET_ERROR_UNINITIALIZED);
        Status = GDU_RET_DET_UNINIT;
    }

    return Status;
}

Std_ReturnType Gdu_SetSafeState (
    Gdu_Ip_SafeStateType SafeState)
{
    Std_ReturnType Status = GDU_RET_INVALID;

    if (GDU_DEV_ASSERT(Gdu_bInitialized))
    {
        if (GDU_DEV_ASSERT((SafeState > GDU_IP_SAFESTATE_MIN) && (SafeState < GDU_IP_SAFESTATE_MAX)))
        {
            if (GDU_IP_STATUS_OK == Gdu_Ip_SetSafeState(SafeState))
            {
                Status = E_OK;
            }
            else
            {
                Status = E_NOT_OK;
            }
        }
        else
        {
            Gdu_ReportDetError(GDU_DET_SERVICE_SETSAFESTATE, GDU_DET_ERROR_PARAMETER);
            Status = GDU_RET_DET_PARAM;
        }
    }
    else
    {
        Gdu_ReportDetError(GDU_DET_SERVICE_SETSAFESTATE, GDU_DET_ERROR_UNINITIALIZED);
        Status = GDU_RET_DET_UNINIT;
    }

    return Status;
}

Std_ReturnType Gdu_GetStatus (
    Gdu_Ip_ErrorStatusType * ErrorStatus)
{
    Std_ReturnType Status = GDU_RET_INVALID;
    Gdu_Ip_StatusType GduStatus = GDU_IP_STATUS_OK;

    if (GDU_DEV_ASSERT(Gdu_bInitialized))
    {
        /* if ErrorStatus is a NULL_PTR the user will not get detailed information about each status bit;
        instead, they will know that one of the error bits is set when the return value is GDU_RET_ERROR */
        GduStatus = Gdu_Ip_GetStatus(ErrorStatus);

        if (GDU_IP_STATUS_OK == GduStatus)
        {
            Status = E_OK;
        }
        else if (GDU_IP_STATUS_ERROR == GduStatus)
        {
            Status = E_NOT_OK;
        }
        else
        {
            Status = GDU_RET_ERROR;
        }
    }
    else
    {
        Gdu_ReportDetError(GDU_DET_SERVICE_GETSTATUS, GDU_DET_ERROR_UNINITIALIZED);
        Status = GDU_RET_DET_UNINIT;
    }

    return Status;
}

Std_ReturnType Gdu_StartDelayMeasurement (
    Gdu_Ip_PwmChannelType PwmChannel,
    Gdu_Ip_EdgeType Edge)
{
    Std_ReturnType Status = GDU_RET_INVALID;

    if (GDU_DEV_ASSERT(Gdu_bInitialized))
    {
        if (GDU_DEV_ASSERT((PwmChannel > GDU_IP_PWM_CHANNEL_MIN) &&
                           (PwmChannel < GDU_IP_PWM_CHANNEL_MAX) &&
                           (Edge > GDU_IP_EDGE_MIN) &&
                           (Edge < GDU_IP_EDGE_MAX)))
        {
            if (GDU_IP_STATUS_OK == Gdu_Ip_StartDelayMeasurement(PwmChannel, Edge))
            {
                Status = E_OK;
            }
            else
            {
                Status = E_NOT_OK;
            }
        }
        else
        {
            Gdu_ReportDetError(GDU_DET_SERVICE_START_DELAYMEAS, GDU_DET_ERROR_PARAMETER);
            Status = GDU_RET_DET_PARAM;
        }
    }
    else
    {
        Gdu_ReportDetError(GDU_DET_SERVICE_START_DELAYMEAS, GDU_DET_ERROR_UNINITIALIZED);
        Status = GDU_RET_DET_UNINIT;
    }

    return Status;
}

Std_ReturnType Gdu_ReadDelayMeasurement (
    uint8 * Delay)
{
    Std_ReturnType Status = GDU_RET_INVALID;

    if (GDU_DEV_ASSERT(Gdu_bInitialized))
    {
        if (GDU_DEV_ASSERT(Delay != NULL_PTR))
        {
            switch (Gdu_Ip_ReadDelayMeasurement(Delay))
            {
                case GDU_IP_STATUS_OK:
                    Status = E_OK;
                break;

                case GDU_IP_STATUS_INVALID:
                    Status = GDU_RET_ERROR;
                break;

                case GDU_IP_STATUS_ERROR:
                default:
                    Status = E_NOT_OK;
                break;
            }
        }
        else
        {
            Gdu_ReportDetError(GDU_DET_SERVICE_READ_DELAYMEAS, GDU_DET_ERROR_PARAMETER);
            Status = GDU_RET_DET_PARAM;
        }
    }
    else
    {
        Gdu_ReportDetError(GDU_DET_SERVICE_READ_DELAYMEAS, GDU_DET_ERROR_UNINITIALIZED);
        Status = GDU_RET_DET_UNINIT;
    }

    return Status;
}

Std_ReturnType Gdu_AdjustSlewRate (
    Gdu_Ip_SlewRateSelectType SlewRateSelect,
    const Gdu_Ip_SlewRateConfigType * SlewRateConfig)
{
    Std_ReturnType Status = GDU_RET_INVALID;

    if (GDU_DEV_ASSERT(Gdu_bInitialized))
    {
        if ((GDU_DEV_ASSERT(SlewRateSelect > GDU_IP_SLEWRATE_MIN) &&
                           (SlewRateSelect < GDU_IP_SLEWRATE_MAX) &&
                           (SlewRateConfig != NULL_PTR)))
        {
            if (GDU_IP_STATUS_OK == Gdu_Ip_AdjustSlewRate(SlewRateSelect, SlewRateConfig))
            {
                Status = E_OK;
            }
            else
            {
                Status = E_NOT_OK;
            }
        }
        else
        {
            Gdu_ReportDetError(GDU_DET_SERVICE_ADJUSTSLEWRATE, GDU_DET_ERROR_PARAMETER);
            Status = GDU_RET_DET_PARAM;
        }
    }
    else
    {
        Gdu_ReportDetError(GDU_DET_SERVICE_ADJUSTSLEWRATE, GDU_DET_ERROR_UNINITIALIZED);
        Status = GDU_RET_DET_UNINIT;
    }

    return Status;
}

Std_ReturnType Gdu_SwIrefTrimming (
    Gdu_Ip_IrefTrimmingType IrefTrimming)
{
    Std_ReturnType Status = GDU_RET_INVALID;

    if (GDU_DEV_ASSERT(Gdu_bInitialized))
    {
        if (GDU_DEV_ASSERT((IrefTrimming.LG0 > GDU_IP_IREF_TRIM_MIN) &&
                           (IrefTrimming.LG0 < GDU_IP_IREF_TRIM_MAX) &&
                           (IrefTrimming.LG1 > GDU_IP_IREF_TRIM_MIN) &&
                           (IrefTrimming.LG1 < GDU_IP_IREF_TRIM_MAX) &&
                           (IrefTrimming.LG2 > GDU_IP_IREF_TRIM_MIN) &&
                           (IrefTrimming.LG2 < GDU_IP_IREF_TRIM_MAX) &&
                           (IrefTrimming.HG0 > GDU_IP_IREF_TRIM_MIN) &&
                           (IrefTrimming.HG0 < GDU_IP_IREF_TRIM_MAX) &&
                           (IrefTrimming.HG1 > GDU_IP_IREF_TRIM_MIN) &&
                           (IrefTrimming.HG1 < GDU_IP_IREF_TRIM_MAX) &&
                           (IrefTrimming.HG2 > GDU_IP_IREF_TRIM_MIN) &&
                           (IrefTrimming.HG2 < GDU_IP_IREF_TRIM_MAX)))
        {
            if (GDU_IP_STATUS_OK == Gdu_Ip_SwIrefTrimming(IrefTrimming))
            {
                Status = E_OK;
            }
            else
            {
                Status = E_NOT_OK;
            }
        }
        else
        {
            Gdu_ReportDetError(GDU_DET_SERVICE_SWIREFTRIMMING, GDU_DET_ERROR_PARAMETER);
            Status = GDU_RET_DET_PARAM;
        }
    }
    else
    {
        Gdu_ReportDetError(GDU_DET_SERVICE_SWIREFTRIMMING, GDU_DET_ERROR_UNINITIALIZED);
        Status = GDU_RET_DET_UNINIT;
    }

    return Status;
}

Std_ReturnType Gdu_OffStateDiagnostics (
    Gdu_Ip_OffStateDiagType OffStateDiagnostics)
{
    Std_ReturnType Status = GDU_RET_INVALID;

    if (GDU_DEV_ASSERT(Gdu_bInitialized))
    {
        if (GDU_IP_STATUS_OK == Gdu_Ip_OffStateDiagnostics(OffStateDiagnostics))
        {
            Status = E_OK;
        }
        else
        {
            Status = E_NOT_OK;
        }
    }
    else
    {
        Gdu_ReportDetError(GDU_DET_SERVICE_OFFSTATEDIAG, GDU_DET_ERROR_UNINITIALIZED);
        Status = GDU_RET_DET_UNINIT;
    }

    return Status;
}

#if (GDU_VERSION_INFO_API == STD_ON)
Std_ReturnType Gdu_GetVersionInfo (
    Std_VersionInfoType * VersionInfo)
{
    Std_ReturnType Status = GDU_RET_INVALID;

    if (GDU_DEV_ASSERT(VersionInfo != NULL_PTR))
    {
        VersionInfo->moduleID = GDU_MODULE_ID;
        VersionInfo->vendorID = GDU_VENDOR_ID;
        VersionInfo->sw_major_version = GDU_SW_MAJOR_VERSION;
        VersionInfo->sw_minor_version = GDU_SW_MINOR_VERSION;
        VersionInfo->sw_patch_version = GDU_SW_PATCH_VERSION;
        Status = E_OK;
    }
    else
    {
        Gdu_ReportDetError(GDU_DET_SERVICE_GETVERSIONINFO, GDU_DET_ERROR_PARAMETER);
        Status = GDU_RET_DET_PARAM;
    }

    return Status;
}
#endif

#define GDU_STOP_SEC_CODE
#include "Gdu_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */
