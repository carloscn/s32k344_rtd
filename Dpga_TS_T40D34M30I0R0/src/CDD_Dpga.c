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
*   @addtogroup dpga
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
#include "CDD_Dpga.h"

#if (STD_ON == DPGA_DEV_ERROR_DETECT)
    #include "Det.h"
#endif

/*==================================================================================================
*                                 SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define DPGA_VENDOR_ID_C                      43
#define DPGA_AR_RELEASE_MAJOR_VERSION_C       4
#define DPGA_AR_RELEASE_MINOR_VERSION_C       7
#define DPGA_AR_RELEASE_REVISION_VERSION_C    0
#define DPGA_SW_MAJOR_VERSION_C               3
#define DPGA_SW_MINOR_VERSION_C               0
#define DPGA_SW_PATCH_VERSION_C               0

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and CDD_Dpga header file are of the same vendor */
#if (DPGA_VENDOR_ID_C != DPGA_VENDOR_ID)
    #error "CDD_Dpga.c and CDD_Dpga.h have different vendor ids"
#endif

/* Check if current file and CDD_Dpga header file are of the same Autosar version */
#if ((DPGA_AR_RELEASE_MAJOR_VERSION_C     != DPGA_AR_RELEASE_MAJOR_VERSION) || \
     (DPGA_AR_RELEASE_MINOR_VERSION_C     != DPGA_AR_RELEASE_MINOR_VERSION) || \
     (DPGA_AR_RELEASE_REVISION_VERSION_C  != DPGA_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of CDD_Dpga.c and CDD_Dpga.h are different"
#endif

/* Check if current file and CDD_Dpga header file are of the same software version */
#if ((DPGA_SW_MAJOR_VERSION_C != DPGA_SW_MAJOR_VERSION) || \
     (DPGA_SW_MINOR_VERSION_C != DPGA_SW_MINOR_VERSION) || \
     (DPGA_SW_PATCH_VERSION_C != DPGA_SW_PATCH_VERSION))
    #error "Software Version Numbers of CDD_Dpga.c and CDD_Dpga.h are different"
#endif

#if (STD_ON == DPGA_DEV_ERROR_DETECT)
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
/* Check if source file and Det header file are of the same AutoSar version */
#if ((DPGA_AR_RELEASE_MAJOR_VERSION_C != DET_AR_RELEASE_MAJOR_VERSION) || \
     (DPGA_AR_RELEASE_MINOR_VERSION_C != DET_AR_RELEASE_MINOR_VERSION))
    #error "AutoSar Version Numbers of CDD_Dpga.c and Det.h are different"
#endif
#endif /* DISABLE_MCAL_INTERMODULE_ASR_CHECK */
#endif /* STD_ON == DPGA_DEV_ERROR_DETECT */

/*==================================================================================================
*                           LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
*                                          LOCAL MACROS
==================================================================================================*/

/*==================================================================================================
*                                         LOCAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                         LOCAL VARIABLES
==================================================================================================*/
#if (STD_ON == DPGA_DEV_ERROR_DETECT)
#define DPGA_START_SEC_VAR_CLEARED_BOOLEAN
#include "Dpga_MemMap.h"

static boolean Dpga_bInitialized;

#define DPGA_STOP_SEC_VAR_CLEARED_BOOLEAN
#include "Dpga_MemMap.h"
#endif /* (STD_ON == DPGA_DEV_ERROR_DETECT) */

#define DPGA_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "Dpga_MemMap.h"

static const Dpga_ConfigType * Dpga_pxInitConfig;

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

#if (STD_ON == DPGA_DEV_ERROR_DETECT)
static inline void Dpga_ReportDetError(uint8 ServiceId,
                                       uint8 ErrorId);
static inline Std_ReturnType Dpga_CheckInit(const uint8 ServiceId);
static inline Std_ReturnType Dpga_ValidatePtrInit(const Dpga_ConfigType * ConfigPtr);
#endif /* (STD_ON == DPGA_DEV_ERROR_DETECT) */

/*==================================================================================================
*                                         LOCAL FUNCTIONS
==================================================================================================*/
#if (STD_ON == DPGA_DEV_ERROR_DETECT)
/*local function Dpga_ReportDetError to report the det error*/
static inline void Dpga_ReportDetError(uint8 ServiceId,
                                       uint8 ErrorId)
{
    (void)Det_ReportError((uint16)DPGA_MODULE_ID, (uint8)0U, ServiceId, ErrorId);
}
/*local function Dpga_CheckInit to check init is ok or not*/
static inline Std_ReturnType Dpga_CheckInit(const uint8 ServiceId)
{
    Std_ReturnType ReturnValue = (Std_ReturnType)E_OK;

    if (Dpga_bInitialized == FALSE)
    {
        ReturnValue = (Std_ReturnType)E_NOT_OK;
        Dpga_ReportDetError(ServiceId, DPGA_E_NOT_INITIALIZED);
    }

    return ReturnValue;
}
/*local function Dpga_ValidatePtrInit to check the config pointer*/
static inline Std_ReturnType Dpga_ValidatePtrInit(const Dpga_ConfigType * ConfigPtr)
{
    Std_ReturnType ReturnValue = (Std_ReturnType)E_OK;

#if (STD_ON == DPGA_PRECOMPILE_SUPPORT)
    if (NULL_PTR != ConfigPtr)
#else
    if (NULL_PTR == ConfigPtr)
#endif
    {
        ReturnValue = (Std_ReturnType)E_NOT_OK;
        Dpga_ReportDetError((uint8)DPGA_INIT_ID, (uint8)DPGA_E_INIT_FAILED);
    }

    return ReturnValue;
}
#endif /* (STD_ON == DPGA_DEV_ERROR_DETECT) */

/*==================================================================================================
*                                        GLOBAL FUNCTIONS
==================================================================================================*/
/*FUNCTION**********************************************************************
*
* Function Name : Dpga_Init
* Description   : This function initializes the DPGA module:
*               - Maps the logical channel to the hardware channel
*               - Initializes the channel
*
* @implements     Dpga_Init_Activity
* END**************************************************************************/
Std_ReturnType Dpga_Init(const Dpga_ConfigType * const Config)
{
    Std_ReturnType ReturnValue = (Std_ReturnType)E_NOT_OK;
#if (STD_ON == DPGA_DEV_ERROR_DETECT)
    Std_ReturnType CheckStatus = Dpga_ValidatePtrInit(Config);
    if ((Std_ReturnType)E_OK == CheckStatus)
    {
        if (TRUE == Dpga_bInitialized)
        {
            Dpga_ReportDetError((uint8)DPGA_INIT_ID, (uint8)DPGA_E_ALREADY_INITIALIZED);
        }
        else
        {
#endif /* (STD_ON == DPGA_DEV_ERROR_DETECT) */
#if (STD_ON == DPGA_PRECOMPILE_SUPPORT)
            (void)Config;
            Dpga_pxInitConfig = Dpga_ConfigVariantPredefined[0U];
#else
            Dpga_pxInitConfig = Config;
#endif /* (STD_ON == DPGA_PRECOMPILE_SUPPORT) */
            ReturnValue = (Std_ReturnType)Dpga_Ip_Init(0U, Dpga_pxInitConfig);
#if (STD_ON == DPGA_DEV_ERROR_DETECT)
            Dpga_bInitialized = TRUE;
        }
    }
#endif /* (STD_ON == DPGA_DEV_ERROR_DETECT) */

    return ReturnValue;
}

/*FUNCTION**********************************************************************
*
* Function Name : Dpga_DeInit
* Description   : This function deinitializes the DPGA module to the reset values.
*                 The driver must be initialized before calling Dpga_DeInit().
*
* @implements     Dpga_DeInit_Activity
* END**************************************************************************/
Std_ReturnType Dpga_DeInit(void)
{
    Std_ReturnType ReturnValue = (Std_ReturnType)E_NOT_OK;
#if (STD_ON == DPGA_DEV_ERROR_DETECT)
    Std_ReturnType CheckStatus = Dpga_CheckInit(DPGA_DEINIT_ID);
    if ((Std_ReturnType)E_OK == CheckStatus)
    {
#endif /* (STD_ON == DPGA_DEV_ERROR_DETECT) */
        ReturnValue = (Std_ReturnType)Dpga_Ip_DeInit(0U);
        Dpga_pxInitConfig = NULL_PTR;
#if (STD_ON == DPGA_DEV_ERROR_DETECT)
        Dpga_bInitialized = FALSE;
    }
#endif /* (STD_ON == DPGA_DEV_ERROR_DETECT) */

    return ReturnValue;
}

/*FUNCTION**********************************************************************
*
* Function Name : Dpga_ConfigureAmplifier
* Description   : This function is used to configure the Amplifier at runtime.
*                 The user can store specific configuration values after device power up
*                 and reload them after each device reset.
*
* @implements     Dpga_ConfigureAmplifier_Activity
* END**************************************************************************/
Std_ReturnType Dpga_ConfigureAmplifier(const Dpga_AmplifierConfigType * AmplifierConfig)
{
    Std_ReturnType ReturnValue = (Std_ReturnType)E_NOT_OK;
#if (STD_ON == DPGA_DEV_ERROR_DETECT)
    Std_ReturnType CheckStatus = Dpga_CheckInit(DPGA_CONFIGURE_AMPLIFIER_ID);
    if ((Std_ReturnType)E_OK == CheckStatus)
    {
        if (NULL_PTR == AmplifierConfig)
        {
            ReturnValue = (Std_ReturnType)E_NOT_OK;
            Dpga_ReportDetError((uint8)DPGA_CONFIGURE_AMPLIFIER_ID, (uint8)DPGA_E_INVALID_POINTER);
        }
        else
        {
#endif /* (STD_ON == DPGA_DEV_ERROR_DETECT) */
            ReturnValue = (Std_ReturnType)Dpga_Ip_ConfigureAmplifier(0U, AmplifierConfig);
#if (STD_ON == DPGA_DEV_ERROR_DETECT)
        }
    }
#endif /* (STD_ON == DPGA_DEV_ERROR_DETECT) */

    return ReturnValue;
}

#if (STD_ON == DPGA_VERSION_INFO_API)
/*FUNCTION**********************************************************************
*
* Function Name : Dpga_GetVersionInfo
* Description   : This function returns the version information of the DPGA module.
*
* @implements     Dpga_GetVersionInfo_Activity
* END**************************************************************************/
void Dpga_GetVersionInfo(Std_VersionInfoType * VersionInfo)
{
#if (STD_ON == DPGA_DEV_ERROR_DETECT)
    if (NULL_PTR == VersionInfo)
    {
        Dpga_ReportDetError((uint8)DPGA_GETVERSIONINFO_ID, (uint8)DPGA_E_INVALID_POINTER);
    }
    else
    {
#endif /* (STD_ON == DPGA_DEV_ERROR_DETECT) */
        (VersionInfo)->vendorID = (uint16)DPGA_VENDOR_ID;
        (VersionInfo)->moduleID = (uint16)DPGA_MODULE_ID;
        (VersionInfo)->sw_major_version = (uint8)DPGA_SW_MAJOR_VERSION;
        (VersionInfo)->sw_minor_version = (uint8)DPGA_SW_MINOR_VERSION;
        (VersionInfo)->sw_patch_version = (uint8)DPGA_SW_PATCH_VERSION;
#if (STD_ON == DPGA_DEV_ERROR_DETECT)
    }
#endif /* (STD_ON == DPGA_DEV_ERROR_DETECT) */
}
#endif /* (STD_ON == DPGA_VERSION_INFO_API) */

#define DPGA_STOP_SEC_CODE
#include "Dpga_MemMap.h"


#ifdef __cplusplus
}
#endif

/** @} */
