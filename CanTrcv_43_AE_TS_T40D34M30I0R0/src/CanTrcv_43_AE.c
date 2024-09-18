/*==================================================================================================
*   Project              : RTD AUTOSAR 4.7
*   Platform             : CORTEXM
*   Peripheral           : AE
*   Dependencies         : 
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
/*==================================================================================================
==================================================================================================*/
/**
* @file         CanTrcv_43_AE.c
* @version      3.0.0
*
* @brief        AUTOSAR CanTrcv_43_AE - module interface
* @details      API implementation for CanTrcv driver.
*
*
* @addtogroup   CANTRCV_DRIVER
* @{
*/

#ifdef __cplusplus
extern "C"
{
#endif

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "CanTrcv_43_AE.h"
#include "CanTrcv_43_AE_Ipw.h"
#include "CanIf_CanTrcv.h"
#include "SchM_CanTrcv_43_AE.h"
#if (CANTRCV_43_AE_ECUM_USED == STD_ON)
#include "EcuM.h"
#endif

#if (CANTRCV_43_AE_DEV_ERROR_DETECT == STD_ON)
/* guard including Det.h here because only development errors checked in this file */
#include "Det.h"
#endif

#if (CANTRCV_43_AE_DEM_USED == STD_ON) 
#include "Dem.h"
#endif
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define CANTRCV_43_AE_VENDOR_ID_C                      43
#define CANTRCV_43_AE_MODULE_ID_C                      70
#define CANTRCV_43_AE_AR_RELEASE_MAJOR_VERSION_C       4
#define CANTRCV_43_AE_AR_RELEASE_MINOR_VERSION_C       7
#define CANTRCV_43_AE_AR_RELEASE_REVISION_VERSION_C    0
#define CANTRCV_43_AE_SW_MAJOR_VERSION_C               3
#define CANTRCV_43_AE_SW_MINOR_VERSION_C               0
#define CANTRCV_43_AE_SW_PATCH_VERSION_C               0
/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/

/*==================================================================================================
                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/
#if (CANTRCV_43_AE_MULTICORE_ENABLED == STD_ON)
    #define Can_GetCoreID()       ((uint32)OsIf_GetCoreID())
#else
    #define Can_GetCoreID()       ((uint32)0UL)
#endif
/*==================================================================================================
                                       LOCAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
                                       LOCAL VARIABLES
==================================================================================================*/
#define CANTRCV_43_AE_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "CanTrcv_43_AE_MemMap.h"

#if (CANTRCV_43_AE_DEV_ERROR_DETECT == STD_ON)
    static CanTrcv_TrcvModeType CanTrcv_TrcvMode[CANTRCV_43_AE_TRANSCEIVER_CONFIG_COUNT];

    static CanTrcv_43_AE_eDriverStatusType CanTrcv_eDriverStatus[CANTRCV_43_AE_MAX_PARTITIONS];
#endif

/* Pointer to the current Driver Configuration (passed to the driver during initialization). Initialized by CanTrcv_Init(). */
static const CanTrcv_43_AE_ConfigType * CanTrcv_apxConfig[CANTRCV_43_AE_MAX_PARTITIONS];

#define CANTRCV_43_AE_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "CanTrcv_43_AE_MemMap.h"
/*==================================================================================================
                                       GLOBAL CONSTANTS
==================================================================================================*/
#if (CANTRCV_43_AE_PRECOMPILE_SUPPORT == STD_ON)
    #define CANTRCV_43_AE_START_SEC_CONFIG_DATA_UNSPECIFIED
    #include "CanTrcv_43_AE_MemMap.h"
    #if (CANTRCV_43_AE_MULTICORE_ENABLED == STD_ON)
        extern const CanTrcv_43_AE_ConfigType * const CanTrcv_43_AE_Config[CANTRCV_43_AE_MAX_PARTITIONS];
    #else
        extern const CanTrcv_43_AE_ConfigType CanTrcv_43_AE_Config;
    #endif
    #define CANTRCV_43_AE_STOP_SEC_CONFIG_DATA_UNSPECIFIED
    #include "CANTRCV_43_AE_MemMap.h"
#endif
/*==================================================================================================
                                       GLOBAL VARIABLES
==================================================================================================*/

/*==================================================================================================
                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/

/*==================================================================================================
                                       LOCAL FUNCTIONS
==================================================================================================*/

/*==================================================================================================
                                       GLOBAL FUNCTIONS
==================================================================================================*/

/*================================================================================================*/
#define CANTRCV_43_AE_START_SEC_CODE
#include "CanTrcv_43_AE_MemMap.h"

#if (CANTRCV_43_AE_VERSION_INFO_API == STD_ON)
/**
* @brief        CAN transceiver driver get version info function. SID is 0x04.
* @details      Returns the version information of this module.
*
* @param[out]   versioninfo     Pointer to where to store the version information of this module.
*
* @return       void
*
* @api
*/
/** @implements   CanTrcv_GetVersionInfo_Activity */
void CanTrcv_43_AE_GetVersionInfo(Std_VersionInfoType * VersionInfo)
{
#if (CANTRCV_43_AE_DEV_ERROR_DETECT == STD_ON)
    if (NULL_PTR == VersionInfo)
    {
        (void) Det_ReportError((uint16) CANTRCV_43_AE_MODULE_ID,
                (uint8) CANTRCV_43_AE_INSTANCE,
                (uint8) CANTRCV_43_AE_SID_GET_VERSION_INFO,
                (uint8) CANTRCV_43_AE_E_PARAM_POINTER);
    }
    else
    {
#endif /* CANTRCV_43_AE_DEV_ERROR_DETECT == STD_ON */
        VersionInfo->vendorID = (uint16)CANTRCV_43_AE_VENDOR_ID;
        VersionInfo->moduleID = (uint8)CANTRCV_43_AE_MODULE_ID;
        VersionInfo->sw_major_version = (uint8)CANTRCV_43_AE_SW_MAJOR_VERSION;
        VersionInfo->sw_minor_version = (uint8)CANTRCV_43_AE_SW_MINOR_VERSION;
        VersionInfo->sw_patch_version = (uint8)CANTRCV_43_AE_SW_PATCH_VERSION;
#if(CANTRCV_43_AE_DEV_ERROR_DETECT == STD_ON)
    }
#endif /* CANTRCV_43_AE_DEV_ERROR_DETECT == STD_ON */
}
#endif /* CANTRCV_43_AE_VERSION_INFO_API == STD_ON */

/**
* @brief        Initializes CanTrcv module. SID 0x00.
* @details      Initializes all transceivers configured in ConfigPtr parameter.
*               The CANTRCV module shall be initialized by CanTrcv_43_AE_Init() service call during the
*               start-up.
*
* @param[in]    ConfigPtr       Pointer to driver configuration structure.
*
* @return       void
*
*
* @pre          CanTrcv_43_AE_Init shall be called at most once during runtime.
* @post         CanTrcv_43_AE_Init shall initialize all the transceivers and set the driver in READY state.
*
* @api
*/
/** @implements   CanTrcv_Init_Activity */
void CanTrcv_43_AE_Init(const CanTrcv_43_AE_ConfigType * ConfigPtr)
{
    uint32 u32CoreId = 0U;
    uint8 SwTransceiverId = 0U;
#if (CANTRCV_43_AE_DEV_ERROR_DETECT == STD_ON)
    Std_ReturnType TrcvStat = E_OK;
#endif
    const CanTrcv_43_AE_TransceiverConfigType * pTransceiver = NULL_PTR;

    u32CoreId = Can_GetCoreID();

#if (CANTRCV_43_AE_DEV_ERROR_DETECT == STD_ON)
    if (CANTRCV_43_AE_ACTIVE == CanTrcv_eDriverStatus[u32CoreId])
    {
        /* Just Init CanTrcv driver when it was being un-init(not_active) */
        (void)Det_ReportError((uint16)CANTRCV_43_AE_MODULE_ID,
                              (uint8)CANTRCV_43_AE_INSTANCE,
                              (uint8)CANTRCV_43_AE_SID_INIT,
                              (uint8)CANTRCV_43_AE_E_INIT_FAILED);
    }
    else
    {
    #if (CANTRCV_43_AE_PRECOMPILE_SUPPORT == STD_ON)
        if (NULL_PTR != ConfigPtr)
    #else
        if (NULL_PTR == ConfigPtr)
    #endif
        {
            (void)Det_ReportError((uint16)CANTRCV_43_AE_MODULE_ID,
                                  (uint8)CANTRCV_43_AE_INSTANCE,
                                  (uint8)CANTRCV_43_AE_SID_INIT,
                                  (uint8)CANTRCV_43_AE_E_INIT_FAILED);
        }
        else
        {
#endif /* (CANTRCV_43_AE_DEV_ERROR_DETECT == STD_ON) */
    #if (CANTRCV_43_AE_PRECOMPILE_SUPPORT == STD_ON)
        #if (CANTRCV_43_AE_MULTICORE_ENABLED == STD_ON)
            if (NULL_PTR != CanTrcv_43_AE_Config[u32CoreId])
            {
                /* Update config pointer with default configuration if precompile support on. */
                CanTrcv_apxConfig[u32CoreId] = CanTrcv_43_AE_Config[u32CoreId];
            }
        #else
            /* Update config pointer with default configuration if precompile support on. */
            CanTrcv_apxConfig[u32CoreId] = &CanTrcv_43_AE_Config;
        #endif
            (void)ConfigPtr; /* Prevent compiler warning */
    #else
        #if (CANTRCV_43_AE_MULTICORE_ENABLED == STD_ON)
            if (u32CoreId == ConfigPtr->CanTrcv_u32CoreID)
            {
        #endif /* (CANTRCV_43_AE_MULTICORE_ENABLED == STD_ON) */
                /* Copy pointer to current Can Driver configuration. */
                CanTrcv_apxConfig[u32CoreId] = ConfigPtr;
        #if (CANTRCV_43_AE_MULTICORE_ENABLED == STD_ON)
            }
        #endif /* (CANTRCV_43_AE_MULTICORE_ENABLED == STD_ON) */
    #endif /* (CANTRCV_43_AE_PRECOMPILE_SUPPORT == STD_ON) */
            if (NULL_PTR != CanTrcv_apxConfig[u32CoreId])
            {
                for (SwTransceiverId = 0U; SwTransceiverId < CANTRCV_43_AE_TRANSCEIVER_CONFIG_COUNT; SwTransceiverId++)
                {
                    pTransceiver = CanTrcv_apxConfig[u32CoreId]->CanTrcv_ppTransceivers[SwTransceiverId];
                    /* Init all controllers asigned to the current core/partition */
                    if (NULL_PTR != pTransceiver)
                    {
                        if ((Std_ReturnType)E_NOT_OK == CanTrcv_43_AE_Ipw_Init(pTransceiver))
                        {
                        #if (CANTRCV_43_AE_DEV_ERROR_DETECT == STD_ON)
                            TrcvStat = E_NOT_OK;
                        #endif
                            break;
                        }
                    #if (CANTRCV_43_AE_DEV_ERROR_DETECT == STD_ON)
                        else
                        {
                            CanTrcv_TrcvMode[SwTransceiverId] = pTransceiver->CanTrcv_eInitState;
                        }
                    #endif
                    }
                }

            #if (CANTRCV_43_AE_DEV_ERROR_DETECT == STD_ON)
                if ((Std_ReturnType)E_OK == TrcvStat)
                {
                    /* Set driver status to NOT_ACTIVE when all Transceivers init successfully */
                    CanTrcv_eDriverStatus[u32CoreId] = CANTRCV_43_AE_ACTIVE;
                }
            #endif
            }
#if (CANTRCV_43_AE_DEV_ERROR_DETECT == STD_ON)
        #if (CANTRCV_43_AE_MULTICORE_ENABLED == STD_ON)
            else
            {
                (void)Det_ReportError((uint16)CANTRCV_43_AE_MODULE_ID,
                                      (uint8)CANTRCV_43_AE_INSTANCE,
                                      (uint8)CANTRCV_43_AE_SID_INIT,
                                      (uint8)CANTRCV_43_AE_E_PARAM_CONFIG);
            }
        #endif /* (CANTRCV_43_AE_MULTICORE_ENABLED == STD_ON) */
        }
    }
#endif /* (CANTRCV_43_AE_DEV_ERROR_DETECT == STD_ON) */
}

/*================================================================================================*/
/**
* @brief        Sets the mode of the Transceiver to the value OpMode. SID 0x01.
* @details      Puts the device in one of following modes: normal, standby, sleep.
*
* @param[in]    Transceiver         Index of the transceiver.
* @param[out]   OpMode              Desired operating mode.
*
* @return       Std_ReturnType      Result of the transition.
* @retval       E_OK                Operation executed successfully.
* @retval       E_NOT_OK            Operation failed.
*
*
* @pre          CanTrcv module should be initialized before calling the CanTrcv_43_AE_SetOpMode method.
* @post         CanTrcv_43_AE_SetOpMode shall set the transceiver in the desired state.
*
* @api
*/
/** @implements   CanTrcv_SetOpMode_Activity */
Std_ReturnType CanTrcv_43_AE_SetOpMode(uint8 Transceiver, CanTrcv_TrcvModeType OpMode)
{
    Std_ReturnType eRetVal = (Std_ReturnType)E_NOT_OK;
    uint32 u32CoreId = 0U;
    const CanTrcv_43_AE_TransceiverConfigType * pTransceiver = NULL_PTR;

    u32CoreId = Can_GetCoreID();

#if (CANTRCV_43_AE_DEV_ERROR_DETECT == STD_ON)
    if (CANTRCV_43_AE_NOT_ACTIVE == CanTrcv_eDriverStatus[u32CoreId])
    {
        (void)Det_ReportError((uint16)CANTRCV_43_AE_MODULE_ID,
                              (uint8)CANTRCV_43_AE_INSTANCE,
                              (uint8)CANTRCV_43_AE_SID_SET_OPMODE,
                              (uint8)CANTRCV_43_AE_E_UNINIT);
    }
    else
    {
        if (Transceiver >= CANTRCV_43_AE_TRANSCEIVER_CONFIG_COUNT)
        {
            (void)Det_ReportError((uint16)CANTRCV_43_AE_MODULE_ID,
                                  (uint8)CANTRCV_43_AE_INSTANCE,
                                  (uint8)CANTRCV_43_AE_SID_SET_OPMODE,
                                  (uint8)CANTRCV_43_AE_E_INVALID_TRANSCEIVER);
        }
        else
        {
            if ((CANTRCV_TRCVMODE_NORMAL != OpMode) && (CANTRCV_TRCVMODE_STANDBY != OpMode) && (CANTRCV_TRCVMODE_SLEEP   != OpMode))
            {
                (void) Det_ReportError((uint16)CANTRCV_43_AE_MODULE_ID,
                                       (uint8)CANTRCV_43_AE_INSTANCE,
                                       (uint8)CANTRCV_43_AE_SID_SET_OPMODE,
                                       (uint8)CANTRCV_43_AE_E_PARAM_TRCV_OPMODE);
            }
            else
            {
                if ((CANTRCV_TRCVMODE_STANDBY == OpMode) && (CANTRCV_TRCVMODE_SLEEP == CanTrcv_TrcvMode[Transceiver]))
                {
                    (void) Det_ReportError((uint16)CANTRCV_43_AE_MODULE_ID,
                                       (uint8)CANTRCV_43_AE_INSTANCE,
                                       (uint8)CANTRCV_43_AE_SID_SET_OPMODE,
                                       (uint8)CANTRCV_43_AE_E_TRCV_NOT_NORMAL);
                }
                else
                {
                    if ((CANTRCV_TRCVMODE_SLEEP == OpMode) && (CANTRCV_TRCVMODE_NORMAL == CanTrcv_TrcvMode[Transceiver]))
                    {
                        (void) Det_ReportError((uint16)CANTRCV_43_AE_MODULE_ID,
                                       (uint8)CANTRCV_43_AE_INSTANCE,
                                       (uint8)CANTRCV_43_AE_SID_SET_OPMODE,
                                       (uint8)CANTRCV_43_AE_E_TRCV_NOT_STANDBY);
                    }
                    else
                    {
#endif /* (CANTRCV_43_AE_DEV_ERROR_DETECT == STD_ON) */
                        if ((NULL_PTR != CanTrcv_apxConfig[u32CoreId]) && (NULL_PTR != (CanTrcv_apxConfig[u32CoreId]->CanTrcv_ppTransceivers[Transceiver])))
                        {
                            pTransceiver = CanTrcv_apxConfig[u32CoreId]->CanTrcv_ppTransceivers[Transceiver];
                            eRetVal = CanTrcv_43_AE_Ipw_SetOpMode(pTransceiver, OpMode);

                            if ((Std_ReturnType)E_OK == eRetVal)
                            {
                                CanIf_TrcvModeIndication(pTransceiver->CanTrcv_u8CanIfTransceiverId, OpMode);
                            #if (CANTRCV_43_AE_DEV_ERROR_DETECT == STD_ON)
                                CanTrcv_TrcvMode[Transceiver] = OpMode;
                            #endif
                            }
                        }
#if (CANTRCV_43_AE_DEV_ERROR_DETECT == STD_ON)
                    #if (CANTRCV_43_AE_MULTICORE_ENABLED == STD_ON)
                        else
                        {
                            (void)Det_ReportError((uint16)CANTRCV_43_AE_MODULE_ID,
                                                (uint8)CANTRCV_43_AE_INSTANCE,
                                                (uint8)CANTRCV_43_AE_SID_SET_OPMODE,
                                                (uint8)CANTRCV_43_AE_E_PARAM_CONFIG);
                        }
                    #endif
                    }
                }
            }
        }
    }
#endif /* (CANTRCV_43_AE_DEV_ERROR_DETECT == STD_ON) */

    return eRetVal;
}

/*================================================================================================*/
/**
* @brief        Gets current operation mode. SID 0x02.
* @details      Gets the mode of the Transceiver and returns it in OpMode. The device is in one
*               of following modes: normal, standby, sleep.
*
* @param[in]    Transceiver         CAN transceiver ID.
* @param[out]   OpMode              Current operating mode.
*
* @return       Std_ReturnType      Result of the transition.
* @retval       E_OK                Operation executed successfully.
* @retval       E_NOT_OK            Operation failed.
*
*
* @pre          CanTrcv module should be initialized before calling the CanTrcv_43_AE_GetOpMode method.
* @post         CanTrcv_43_AE_GetOpMode shall return the currently working mode of the transceiver.
*
* @api
*/
/** @implements   CanTrcv_GetOpMode_Activity */
Std_ReturnType CanTrcv_43_AE_GetOpMode(uint8 Transceiver, CanTrcv_TrcvModeType* OpMode)
{
    Std_ReturnType eRetVal = (Std_ReturnType)E_NOT_OK;
    uint32 u32CoreId = 0U;
    const CanTrcv_43_AE_TransceiverConfigType * pTransceiver = NULL_PTR;

    u32CoreId = Can_GetCoreID();

#if (CANTRCV_43_AE_DEV_ERROR_DETECT == STD_ON)
    if (CANTRCV_43_AE_NOT_ACTIVE == CanTrcv_eDriverStatus[u32CoreId])
    {
        (void)Det_ReportError((uint16)CANTRCV_43_AE_MODULE_ID,
                              (uint8)CANTRCV_43_AE_INSTANCE,
                              (uint8)CANTRCV_43_AE_SID_GET_OPMODE,
                              (uint8)CANTRCV_43_AE_E_UNINIT);
    }
    else
    {
        if (Transceiver >= CANTRCV_43_AE_TRANSCEIVER_CONFIG_COUNT)
        {
            (void)Det_ReportError((uint16)CANTRCV_43_AE_MODULE_ID,
                                  (uint8)CANTRCV_43_AE_INSTANCE,
                                  (uint8)CANTRCV_43_AE_SID_GET_OPMODE,
                                  (uint8)CANTRCV_43_AE_E_INVALID_TRANSCEIVER);
        }
        else
        {
            if (NULL_PTR == OpMode)
            {
                (void) Det_ReportError((uint16)CANTRCV_43_AE_MODULE_ID,
                                       (uint8)CANTRCV_43_AE_INSTANCE,
                                       (uint8)CANTRCV_43_AE_SID_GET_OPMODE,
                                       (uint8)CANTRCV_43_AE_E_PARAM_POINTER);
            }
            else
            {
#endif /* (CANTRCV_43_AE_DEV_ERROR_DETECT == STD_ON) */
                if ((NULL_PTR != CanTrcv_apxConfig[u32CoreId]) && (NULL_PTR != (CanTrcv_apxConfig[u32CoreId]->CanTrcv_ppTransceivers[Transceiver])))
                {
                    pTransceiver = CanTrcv_apxConfig[u32CoreId]->CanTrcv_ppTransceivers[Transceiver];
                    eRetVal = CanTrcv_43_AE_Ipw_GetOpMode(pTransceiver, OpMode);
                #if (CANTRCV_43_AE_DEV_ERROR_DETECT == STD_ON)
                    if ((Std_ReturnType)E_OK == eRetVal)
                    {
                        CanTrcv_TrcvMode[Transceiver] = *OpMode;
                    }
                #endif
                }
#if (CANTRCV_43_AE_DEV_ERROR_DETECT == STD_ON)
            #if (CANTRCV_43_AE_MULTICORE_ENABLED == STD_ON)
                else
                {
                    (void)Det_ReportError((uint16)CANTRCV_43_AE_MODULE_ID,
                                          (uint8)CANTRCV_43_AE_INSTANCE,
                                          (uint8)CANTRCV_43_AE_SID_GET_OPMODE,
                                          (uint8)CANTRCV_43_AE_E_PARAM_CONFIG);
                }
            #endif
            }
        }
    }
#endif /* (CANTRCV_43_AE_DEV_ERROR_DETECT == STD_ON) */

    return eRetVal;
}

/*================================================================================================*/
/**
* @brief        Gets the wakeup reason of the Transceiver and returns it in parameter Reason. SID 0x03.
* @details      The device can be woken up by Wake Up Pattern
*                   
* @param[in]    Transceiver         CAN transceiver to which API call has to be applied.
* @param[out]   Reason              Pointer to wake up reason.
*
* @return       Std_ReturnType      Result of the transition.
* @retval       E_OK                Operation executed successfully.
* @retval       E_NOT_OK            Operation failed.
*
*
* @pre          CanTrcv module should be initialized before calling the CanTrcv_43_AE_GetBusWuReason method.
* @post         CanTrcv_43_AE_GetBusWuReason shall return wake up reason.
*
* @api
*/
/** @implements   CanTrcv_GetBusWuReason_Activity */
Std_ReturnType CanTrcv_43_AE_GetBusWuReason(uint8 Transceiver, CanTrcv_TrcvWakeupReasonType * Reason)
{
    Std_ReturnType eRetVal = (Std_ReturnType)E_NOT_OK;
    uint32 u32CoreId = 0U;
    const CanTrcv_43_AE_TransceiverConfigType * pTransceiver = NULL_PTR;

    u32CoreId = Can_GetCoreID();

#if (CANTRCV_43_AE_DEV_ERROR_DETECT == STD_ON)
    if (CANTRCV_43_AE_NOT_ACTIVE == CanTrcv_eDriverStatus[u32CoreId])
    {
        (void)Det_ReportError((uint16)CANTRCV_43_AE_MODULE_ID,
                               (uint8)CANTRCV_43_AE_INSTANCE,
                               (uint8)CANTRCV_43_AE_SID_GET_BUS_WU_REASON,
                               (uint8)CANTRCV_43_AE_E_UNINIT);
    }
    else
    {
        if (Transceiver >= CANTRCV_43_AE_TRANSCEIVER_CONFIG_COUNT)
        {
            (void)Det_ReportError((uint16)CANTRCV_43_AE_MODULE_ID,
                                   (uint8)CANTRCV_43_AE_INSTANCE,
                                   (uint8)CANTRCV_43_AE_SID_GET_BUS_WU_REASON,
                                   (uint8)CANTRCV_43_AE_E_INVALID_TRANSCEIVER);
        }
        else
        {
            if (NULL_PTR == Reason)
            {
                (void)Det_ReportError((uint16) CANTRCV_43_AE_MODULE_ID,
                                      (uint8) CANTRCV_43_AE_INSTANCE,
                                      (uint8) CANTRCV_43_AE_SID_GET_BUS_WU_REASON,
                                      (uint8) CANTRCV_43_AE_E_PARAM_POINTER);
            }
            else
            {
#endif /* (CANTRCV_43_AE_DEV_ERROR_DETECT == STD_ON) */
                if ((NULL_PTR != CanTrcv_apxConfig[u32CoreId]) && (NULL_PTR != (CanTrcv_apxConfig[u32CoreId]->CanTrcv_ppTransceivers[Transceiver])))
                {
                    pTransceiver = CanTrcv_apxConfig[u32CoreId]->CanTrcv_ppTransceivers[Transceiver];
                    eRetVal = CanTrcv_43_AE_Ipw_GetBusWuReason(pTransceiver, Reason);
                }
#if (CANTRCV_43_AE_DEV_ERROR_DETECT == STD_ON)
            #if (CANTRCV_43_AE_MULTICORE_ENABLED == STD_ON)
                else
                {
                    (void)Det_ReportError((uint16)CANTRCV_43_AE_MODULE_ID,
                                          (uint8)CANTRCV_43_AE_INSTANCE,
                                          (uint8)CANTRCV_43_AE_SID_GET_BUS_WU_REASON,
                                          (uint8)CANTRCV_43_AE_E_PARAM_CONFIG);
                }
            #endif
            }
        }
    }
#endif /* (CANTRCV_43_AE_DEV_ERROR_DETECT == STD_ON) */

    return eRetVal;
}

/**
* @brief        Enables, disables or clears wake up events of the Transceiver according to TrcvWakeupMode. SID 0x05.
* @details      Enables, disables or clears wake up functionality. If WU mode is disabled all wake up sources
*               and interrupts are off. If WU mode is enabled, all wake up sources and interrupts are set
*               according to configuration. If WU mode is clear, pending wake up flag is cleared.
*
* @param[in]    Transceiver         CAN Transceiver ID.
* @param[in]    TrcvWakeupMode      Mode of wake up functionality (enabled, disabled, cleared).
*
* @return       Std_ReturnType      Result of the transition.
* @retval       E_OK                Operation executed successfully.
* @retval       E_NOT_OK            Operation failed.
*
*
* @pre          CanTrcv module should be initialized before calling the CanTrcv_43_AE_SetWakeupMode method.
* @post         CanTrcv_43_AE_SetWakeupMode shall return status of the transceiver.
*
* @api
*/
/** @implements   CanTrcv_SetWakeupMode_Activity */
Std_ReturnType CanTrcv_43_AE_SetWakeupMode(uint8 Transceiver, CanTrcv_TrcvWakeupModeType TrcvWakeupMode)
{
    Std_ReturnType eRetVal = (Std_ReturnType)E_NOT_OK;
    uint32 u32CoreId = 0U;
    const CanTrcv_43_AE_TransceiverConfigType * pTransceiver = NULL_PTR;

    u32CoreId = Can_GetCoreID();

#if (CANTRCV_43_AE_DEV_ERROR_DETECT == STD_ON)
    if (CANTRCV_43_AE_NOT_ACTIVE == CanTrcv_eDriverStatus[u32CoreId])
    {
        (void)Det_ReportError((uint16)CANTRCV_43_AE_MODULE_ID,
                              (uint8)CANTRCV_43_AE_INSTANCE,
                              (uint8)CANTRCV_43_AE_SID_SET_WAKEUP_MODE,
                              (uint8)CANTRCV_43_AE_E_UNINIT);
    }
    else
    {
        if (Transceiver >= CANTRCV_43_AE_TRANSCEIVER_CONFIG_COUNT)
        {
            (void)Det_ReportError((uint16)CANTRCV_43_AE_MODULE_ID,
                                  (uint8)CANTRCV_43_AE_INSTANCE,
                                  (uint8)CANTRCV_43_AE_SID_SET_WAKEUP_MODE,
                                  (uint8)CANTRCV_43_AE_E_INVALID_TRANSCEIVER);
        }
        else
        {
            if ((CANTRCV_WUMODE_ENABLE != TrcvWakeupMode) && (CANTRCV_WUMODE_DISABLE != TrcvWakeupMode) && (CANTRCV_WUMODE_CLEAR   != TrcvWakeupMode))
            {
                (void) Det_ReportError((uint16)CANTRCV_43_AE_MODULE_ID,
                                       (uint8)CANTRCV_43_AE_INSTANCE,
                                       (uint8)CANTRCV_43_AE_SID_SET_WAKEUP_MODE,
                                       (uint8)CANTRCV_43_AE_E_PARAM_TRCV_WAKEUP_MODE);
            }
            else
            {
#endif /* (CANTRCV_43_AE_DEV_ERROR_DETECT == STD_ON) */
                if ((NULL_PTR != CanTrcv_apxConfig[u32CoreId]) && (NULL_PTR != (CanTrcv_apxConfig[u32CoreId]->CanTrcv_ppTransceivers[Transceiver])))
                {
                    pTransceiver = CanTrcv_apxConfig[u32CoreId]->CanTrcv_ppTransceivers[Transceiver];
                    eRetVal = CanTrcv_43_AE_Ipw_SetWakeupMode(pTransceiver, TrcvWakeupMode);
                }
#if (CANTRCV_43_AE_DEV_ERROR_DETECT == STD_ON)
            #if (CANTRCV_43_AE_MULTICORE_ENABLED == STD_ON)
                else
                {
                    (void)Det_ReportError((uint16)CANTRCV_43_AE_MODULE_ID,
                                        (uint8)CANTRCV_43_AE_INSTANCE,
                                        (uint8)CANTRCV_43_AE_SID_SET_WAKEUP_MODE,
                                        (uint8)CANTRCV_43_AE_E_PARAM_CONFIG);
                }
            #endif
            }
        }
    }
#endif /* (CANTRCV_43_AE_DEV_ERROR_DETECT == STD_ON) */

    return eRetVal;
}

/*================================================================================================*/
/**
* @brief        Service is called by underlying CANIF in case a wake up interrupt is detected. SID 0x07.
* @details      Reads wake up source from the device and  reports it to ECUM.
*
* @param[in]    Transceiver         CAN transceiver ID.
*
* @return       Std_ReturnType      Result of the transition.
* @retval       E_OK                Operation executed successfully.
* @retval       E_NOT_OK            Operation failed.
*
*
* @pre          CanTrcv module should be initialized before calling the CanTrcv_43_AE_CheckWakeup method.
* @post         CanTrcv_43_AE_CheckWakeup shall read and report wake up reason.
*
* @api
*/
/** @implements   CanTrcv_CheckWakeup_Activity */
Std_ReturnType CanTrcv_43_AE_CheckWakeup(uint8 Transceiver)
{
    Std_ReturnType eRetVal = (Std_ReturnType)E_NOT_OK;
    uint32 u32CoreId = 0U;
    boolean bWakeFlag = FALSE;
    const CanTrcv_43_AE_TransceiverConfigType * pTransceiver = NULL_PTR;

    u32CoreId = Can_GetCoreID();

#if (CANTRCV_43_AE_DEV_ERROR_DETECT == STD_ON)
    if (CANTRCV_43_AE_NOT_ACTIVE == CanTrcv_eDriverStatus[u32CoreId])
    {
        (void)Det_ReportError((uint16)CANTRCV_43_AE_MODULE_ID,
                              (uint8)CANTRCV_43_AE_INSTANCE,
                              (uint8)CANTRCV_43_AE_SID_CHECK_WAKEUP,
                              (uint8)CANTRCV_43_AE_E_UNINIT);
    }
    else
    {
        if (Transceiver >= CANTRCV_43_AE_TRANSCEIVER_CONFIG_COUNT)
        {
            (void)Det_ReportError((uint16)CANTRCV_43_AE_MODULE_ID,
                                  (uint8)CANTRCV_43_AE_INSTANCE,
                                  (uint8)CANTRCV_43_AE_SID_CHECK_WAKEUP,
                                  (uint8)CANTRCV_43_AE_E_INVALID_TRANSCEIVER);
        }
        else
        {
#endif /* (CANTRCV_43_AE_DEV_ERROR_DETECT == STD_ON) */
            if ((NULL_PTR != CanTrcv_apxConfig[u32CoreId]) && (NULL_PTR != (CanTrcv_apxConfig[u32CoreId]->CanTrcv_ppTransceivers[Transceiver])))
            {
                pTransceiver = CanTrcv_apxConfig[u32CoreId]->CanTrcv_ppTransceivers[Transceiver];
                if (TRUE == pTransceiver->CanTrcv_bWakeupByBusUsed)
                {
                    eRetVal = CanTrcv_43_AE_Ipw_CheckWakeupFlag(pTransceiver, &bWakeFlag);
                #if (CANTRCV_43_AE_ECUM_USED == STD_ON)
                    if ((E_OK == eRetVal) && (TRUE == bWakeFlag))
                    {
                        if (0U != (pTransceiver->CanTrcv_WakeupSourceMask))
                        {
                            EcuM_SetWakeupEvent(pTransceiver->CanTrcv_WakeupSourceMask);
                        }
                    }
                #endif
                }
            }
#if (CANTRCV_43_AE_DEV_ERROR_DETECT == STD_ON)
        #if (CANTRCV_43_AE_MULTICORE_ENABLED == STD_ON)
            else
            {
                (void)Det_ReportError((uint16)CANTRCV_43_AE_MODULE_ID,
                                    (uint8)CANTRCV_43_AE_INSTANCE,
                                    (uint8)CANTRCV_43_AE_SID_CHECK_WAKEUP,
                                    (uint8)CANTRCV_43_AE_E_PARAM_CONFIG);
            }
        #endif
        }
    }
#endif /* (CANTRCV_43_AE_DEV_ERROR_DETECT == STD_ON) */

    return eRetVal;
}

/*================================================================================================*/
/**
* @brief        Requests to check the status of the wakeup flag from the transceiver hardware. SID 0x0E.
* @details      Checks wake up event and if WU occurred, reports it.
*
* @param[in]    Transceiver         CAN transceiver ID.
*
* @return       Std_ReturnType      Result of the transition.
* @retval       E_OK                Operation executed successfully.
* @retval       E_NOT_OK            Operation failed.
*
*
* @pre          CanTrcv module should be initialized before calling the CanTrcv_43_AE_CheckWakeFlag method.
* @post         CanTrcv_43_AE_CheckWakeFlag shall check for wake up event, and if such event occurred, report it.
*
* @api
*/
/** @implements   CanTrcv_CheckWakeFlag_Activity */
Std_ReturnType CanTrcv_43_AE_CheckWakeFlag(uint8 Transceiver)
{
    Std_ReturnType eRetVal = (Std_ReturnType)E_NOT_OK;
    uint32 u32CoreId = 0U;
    boolean bWakeFlag = FALSE;
    const CanTrcv_43_AE_TransceiverConfigType * pTransceiver = NULL_PTR;

    u32CoreId = Can_GetCoreID();

#if (CANTRCV_43_AE_DEV_ERROR_DETECT == STD_ON)
    if (CANTRCV_43_AE_NOT_ACTIVE == CanTrcv_eDriverStatus[u32CoreId])
    {
        (void)Det_ReportError((uint16)CANTRCV_43_AE_MODULE_ID,
                              (uint8)CANTRCV_43_AE_INSTANCE,
                              (uint8)CANTRCV_43_AE_SID_CHECK_WAKE_FLAG,
                              (uint8)CANTRCV_43_AE_E_UNINIT);
    }
    else
    {
        if (Transceiver >= CANTRCV_43_AE_TRANSCEIVER_CONFIG_COUNT)
        {
            (void)Det_ReportError((uint16)CANTRCV_43_AE_MODULE_ID,
                                  (uint8)CANTRCV_43_AE_INSTANCE,
                                  (uint8)CANTRCV_43_AE_SID_CHECK_WAKE_FLAG,
                                  (uint8)CANTRCV_43_AE_E_INVALID_TRANSCEIVER);
        }
        else
        {
#endif /* (CANTRCV_43_AE_DEV_ERROR_DETECT == STD_ON) */
            if ((NULL_PTR != CanTrcv_apxConfig[u32CoreId]) && (NULL_PTR != (CanTrcv_apxConfig[u32CoreId]->CanTrcv_ppTransceivers[Transceiver])))
            {
                pTransceiver = CanTrcv_apxConfig[u32CoreId]->CanTrcv_ppTransceivers[Transceiver];
                if (TRUE == pTransceiver->CanTrcv_bWakeupByBusUsed)
                {
                    eRetVal = CanTrcv_43_AE_Ipw_CheckWakeupFlag(pTransceiver, &bWakeFlag);
                    if ((Std_ReturnType)E_OK == eRetVal)
                    {
                        if (FALSE == bWakeFlag)
                        {
                            CanIf_CheckTrcvWakeFlagIndication(pTransceiver->CanTrcv_u8CanIfTransceiverId);
                        }
                    #if (CANTRCV_43_AE_ECUM_USED == STD_ON)
                        else
                        {
                            if (0U != (pTransceiver->CanTrcv_WakeupSourceMask))
                            {
                                EcuM_SetWakeupEvent(pTransceiver->CanTrcv_WakeupSourceMask);
                            }
                        }
                    #endif
                    }
                }
            }
#if (CANTRCV_43_AE_DEV_ERROR_DETECT == STD_ON)
        #if (CANTRCV_43_AE_MULTICORE_ENABLED == STD_ON)
            else
            {
                (void)Det_ReportError((uint16)CANTRCV_43_AE_MODULE_ID,
                                    (uint8)CANTRCV_43_AE_INSTANCE,
                                    (uint8)CANTRCV_43_AE_SID_CHECK_WAKE_FLAG,
                                    (uint8)CANTRCV_43_AE_E_PARAM_CONFIG);
            }
        #endif
        }
    }
#endif /* (CANTRCV_43_AE_DEV_ERROR_DETECT == STD_ON) */

    return eRetVal;
}

#if (CANTRCV_43_AEWAKEUP_MODE_POLLING == STD_ON)
/*================================================================================================*/
/**
* @brief          Service to scan all busses for wake up events and perform these event. SID 0x06.
* @details        Scan transceivers for wake up event and reports such event.
*
* @param[in]      None
*
* @return         void
*
*
* @pre
* @post
*
* @api
*/
/** @implements     CanTrcv_MainFunction_Activity */
void CanTrcv_43_AE_MainFunction(void)
{
    Std_ReturnType eRetVal = (Std_ReturnType)E_NOT_OK;
    uint32 u32CoreId = 0U;
    boolean bWakeFlag = FALSE;
    uint8 SwTransceiverId = 0U;
    const CanTrcv_43_AE_TransceiverConfigType * pTransceiver = NULL_PTR;

    u32CoreId = Can_GetCoreID();

    if (NULL_PTR != CanTrcv_apxConfig[u32CoreId])
    {
        for (SwTransceiverId = 0U; SwTransceiverId < CANTRCV_43_AE_TRANSCEIVER_CONFIG_COUNT; SwTransceiverId++)
        {
            pTransceiver = CanTrcv_apxConfig[u32CoreId]->CanTrcv_ppTransceivers[SwTransceiverId];
            /* check all controllers asigned to the current core */
            if ((NULL_PTR != pTransceiver) && (TRUE == pTransceiver->CanTrcv_bWakeupByBusUsed))
            {
                eRetVal = CanTrcv_43_AE_Ipw_CheckWakeupFlag(pTransceiver, &bWakeFlag);

                if ((E_OK == eRetVal) && (TRUE == bWakeFlag))
                {
                #if (CANTRCV_43_AE_ECUM_USED == STD_ON)
                    if (0U != (pTransceiver->CanTrcv_WakeupSourceMask))
                    {
                        EcuM_SetWakeupEvent(pTransceiver->CanTrcv_WakeupSourceMask);
                    }
                #endif
                }
            }
        }
    }
}
#endif /* (CANTRCV_43_AEWAKEUP_MODE_POLLING == STD_ON) */
#if (CANTRCV_43_AE_BUSERR_EN == STD_ON)
/*================================================================================================*/
/**
* @brief          Reads the transceiver diagnostic status periodically and sets product/development accordingly. SID 0x08.
* @details        Reads system error, and reports it if any.
*
* @param[in]      None
*
* @return         void
*
*
* @pre
* @post
*
* @api
*/
/** @implements     CanTrcv_MainFunctionDiagnostics_Activity */
void CanTrcv_43_AE_MainFunctionDiagnostics(void)
{
    uint32 u32CoreId = 0U;
    uint8 SwTransceiverId = 0U;
    Std_ReturnType eRetVal = (Std_ReturnType)E_NOT_OK;
    boolean bErrFlag = FALSE;
    const CanTrcv_43_AE_TransceiverConfigType * pTransceiver = NULL_PTR;

    u32CoreId = Can_GetCoreID();

    if (NULL_PTR != CanTrcv_apxConfig[u32CoreId])
    {
        for (SwTransceiverId = 0U; SwTransceiverId < CANTRCV_43_AE_TRANSCEIVER_CONFIG_COUNT; SwTransceiverId++)
        {
            pTransceiver = CanTrcv_apxConfig[u32CoreId]->CanTrcv_ppTransceivers[SwTransceiverId];
            /* check all controllers asigned to the current core */
            if (NULL_PTR != pTransceiver)
            {
                eRetVal = CanTrcv_43_AE_Ipw_CheckBusError(pTransceiver, &bErrFlag);

                if (E_OK == eRetVal)
                {
                    if (TRUE == bErrFlag)
                    {
                    #if (CANTRCV_43_AE_DEM_USED == STD_ON) 
                        (void)Dem_SetEventStatus(pTransceiver->CanTrcv_DemEventId, DEM_EVENT_STATUS_FAILED);
                    #endif
                    }
                    else
                    {
                    #if (CANTRCV_43_AE_DEM_USED == STD_ON) 
                        (void)Dem_SetEventStatus(pTransceiver->CanTrcv_DemEventId, DEM_EVENT_STATUS_PASSED);
                    #endif
                    }
                }
            }
        }
    }
}
#endif /* (CANTRCV_43_AE_BUSERR_EN == STD_ON) */
/*================================================================================================*/
/**
* @brief          De-initializes the CanTrcv module. SID 0x10.
* @details        De-initialize all the transceivers.
*                 The CANTRCV module shall be de-initialized by CanTrcv_43_AE_DeInit() service call.
*                 This routine is called by:
*                 - CanIf or an upper layer according to Autosar requirements.
*
* @param[in]      None
*
* @return         void
*
*
* @pre            Before transceiver de-initalization, the driver must be initialized and the transceivers must not be in Start state.
* @post           CanTrcv_43_AE_DeInit shall de-initialize all the transceivers and set the driver in UNINIT state.
*
* @api
*/
/** @implements     CanTrcv_DeInit_Activity */
void CanTrcv_43_AE_DeInit(void)
{
    uint32 u32CoreId = 0U;
    uint8 SwTransceiverId = 0U;
    Std_ReturnType TrcvStat = E_OK;
    const CanTrcv_43_AE_TransceiverConfigType * pTransceiver = NULL_PTR;

    u32CoreId = Can_GetCoreID();

#if (CANTRCV_43_AE_DEV_ERROR_DETECT == STD_ON)
    if (CANTRCV_43_AE_NOT_ACTIVE == CanTrcv_eDriverStatus[u32CoreId])
    {
        (void)Det_ReportError((uint16)CANTRCV_43_AE_MODULE_ID,
                              (uint8)CANTRCV_43_AE_INSTANCE,
                              (uint8)CANTRCV_43_AE_SID_DEINIT,
                              (uint8)CANTRCV_43_AE_E_UNINIT);
    }
    else
    {
        for (SwTransceiverId = 0U; SwTransceiverId < CANTRCV_43_AE_TRANSCEIVER_CONFIG_COUNT; SwTransceiverId++)
        {
            /* if at least one transceiver is not in CANTRCV_TRCVMODE_STANDBY or CANTRCV_TRCVMODE_SLEEP, raise a DET error. */
            if (CANTRCV_TRCVMODE_NORMAL == CanTrcv_TrcvMode[SwTransceiverId])
            {
                (void)Det_ReportError((uint16)CANTRCV_43_AE_MODULE_ID,
                                      (uint8)CANTRCV_43_AE_INSTANCE,
                                      (uint8)CANTRCV_43_AE_SID_DEINIT,
                                      (uint8)CANTRCV_43_AE_E_TRCV_NOT_STANDBY);
                TrcvStat = E_NOT_OK;
                break;
            }
        }

        if (E_OK == TrcvStat)
        {
#endif /* (CANTRCV_43_AE_DEV_ERROR_DETECT == STD_ON) */
            if (NULL_PTR != CanTrcv_apxConfig[u32CoreId])
            {
                for (SwTransceiverId = 0U; SwTransceiverId < CANTRCV_43_AE_TRANSCEIVER_CONFIG_COUNT; SwTransceiverId++)
                {
                    pTransceiver = CanTrcv_apxConfig[u32CoreId]->CanTrcv_ppTransceivers[SwTransceiverId];
                    /* DeInit all controllers asigned to the current core */
                    if (NULL_PTR != pTransceiver)
                    {
                        if ((Std_ReturnType)E_NOT_OK == CanTrcv_43_AE_Ipw_DeInit(pTransceiver))
                        {
                            TrcvStat = E_NOT_OK;
                            break;
                        }
                    }
                }

                if ((Std_ReturnType)E_OK == TrcvStat)
                {
                #if (CANTRCV_43_AE_DEV_ERROR_DETECT == STD_ON)
                    /* Set driver status to NOT_ACTIVE when all Transceivers de-init successfully */
                    CanTrcv_eDriverStatus[u32CoreId] = CANTRCV_43_AE_NOT_ACTIVE;
                #endif
                    CanTrcv_apxConfig[u32CoreId] = NULL_PTR;
                }
            }
#if (CANTRCV_43_AE_DEV_ERROR_DETECT == STD_ON)
        }
    }
#endif /* (CANTRCV_43_AE_DEV_ERROR_DETECT == STD_ON) */
}

#define CANTRCV_43_AE_STOP_SEC_CODE
#include "CanTrcv_43_AE_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */
