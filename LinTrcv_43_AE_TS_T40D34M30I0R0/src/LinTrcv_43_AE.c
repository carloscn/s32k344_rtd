/*==================================================================================================
*   Project              : RTD AUTOSAR 4.7
*   Platform             : CORTEXM
*   Peripheral           : AE
*   Dependencies         : none
*
*   Autosar Version      : 4.7.0
*   Autosar Revision     : ASR_REL_4_7_REV_0000
*   Autosar Conf.Variant :
*   SW Version           : 3.0.0
*   Build Version        : S32K3_RTD_3_0_0_D2303_ASR_REL_4_7_REV_0000_20230331
*
   (c) Copyright 2020 - 2023 NXP Semiconductors
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
*   @file   LinTrcv_43_AE.c
*   @implements LinTrcv_43_AE.c_Artifact
*
*   @addtogroup LINTRCV
*   @{
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

#include "LinTrcv_43_AE.h"
#include "LinIf.h"

#if (LINTRCV_43_AE_DEV_ERROR_DETECT == STD_ON)
#include "Det.h"
#endif
#if (LINTRCV_43_AE_ICU_USED == STD_ON)
#include "Icu.h"
#endif /* (LINTRCV_43_AE_ICU_USED == STD_ON) */
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/

#define LINTRCV_43_AE_VENDOR_ID_C                      43
#define LINTRCV_43_AE_AR_RELEASE_MAJOR_VERSION_C       4
#define LINTRCV_43_AE_AR_RELEASE_MINOR_VERSION_C       7
#define LINTRCV_43_AE_AR_RELEASE_REVISION_VERSION_C    0
#define LINTRCV_43_AE_SW_MAJOR_VERSION_C               3
#define LINTRCV_43_AE_SW_MINOR_VERSION_C               0
#define LINTRCV_43_AE_SW_PATCH_VERSION_C               0

/*==================================================================================================
*                                      FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and LinTrcv header file are of the same Autosar version */
#if (LINTRCV_43_AE_VENDOR_ID_C != LINTRCV_43_AE_VENDOR_ID)
    #error "LinTrcv.c and LinTrcv.h have different vendor ids"
#endif
#if ((LINTRCV_43_AE_AR_RELEASE_MAJOR_VERSION_C    != LINTRCV_43_AE_AR_RELEASE_MAJOR_VERSION) || \
     (LINTRCV_43_AE_AR_RELEASE_MINOR_VERSION_C    != LINTRCV_43_AE_AR_RELEASE_MINOR_VERSION) || \
     (LINTRCV_43_AE_AR_RELEASE_REVISION_VERSION_C != LINTRCV_43_AE_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of LinTrcv.c and LinTrcv.h are different"
#endif
/* Check if current file and LinTrcv header file are of the same Software version */
#if ((LINTRCV_43_AE_SW_MAJOR_VERSION_C != LINTRCV_43_AE_SW_MAJOR_VERSION) || \
     (LINTRCV_43_AE_SW_MINOR_VERSION_C != LINTRCV_43_AE_SW_MINOR_VERSION) || \
     (LINTRCV_43_AE_SW_PATCH_VERSION_C != LINTRCV_43_AE_SW_PATCH_VERSION) )
    #error "Software Version Numbers of LinTrcv.c and LinTrcv.h are different"
#endif

/*==================================================================================================
*                           LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                       GLOBAL CONSTANTS
==================================================================================================*/
#define LINTRCV_43_AE_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "LinTrcv_43_AE_MemMap.h"


extern const LinTrcv_43_AE_ConfigType * const LinTrcv_43_AE_PBCfgVariantPredefined[LINTRCV_43_AE_MAX_PARTITIONS];

#define LINTRCV_43_AE_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "LinTrcv_43_AE_MemMap.h"

/*==================================================================================================
*                                       GLOBAL VARIABLES
==================================================================================================*/

#define LINTRCV_43_AE_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "LinTrcv_43_AE_MemMap.h"
/**
* @brief          Global configuration pointer.
* @details        Pointer to the configuration structure.
*/
const LinTrcv_43_AE_ConfigType * LinTrcv_43_AE_apConfigPtr[LINTRCV_43_AE_MAX_PARTITIONS];

/**
* @brief          Global configuration array.
* @details        Array containing channel configurations.
*/
const LinTrcv_43_AE_ChannelConfigType *LinTrcv_43_AE_apChannelConfigPtr[LINTRCV_43_AE_HW_MAX_MODULES];

#define LINTRCV_43_AE_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "LinTrcv_43_AE_MemMap.h"


#define LINTRCV_43_AE_START_SEC_VAR_INIT_8
#include "LinTrcv_43_AE_MemMap.h"

/**
* @brief          LINTRCV driver status variable.
* @details        LINTRCV driver state machine.
*/
uint8 LinTrcv_43_AE_au8LinTrcvDrvStatus[LINTRCV_43_AE_MAX_PARTITIONS] = LINTRCV_43_AE_UNINIT_ARRAY;

#define LINTRCV_43_AE_STOP_SEC_VAR_INIT_8
#include "LinTrcv_43_AE_MemMap.h"

#define LINTRCV_43_AE_START_SEC_VAR_CLEARED_8
#include "LinTrcv_43_AE_MemMap.h"

/**
* @brief          LINTRCV channel state variable.
* @details        LINTRCV channel state machine.
*/
uint8 LinTrcv_43_AE_au8LinTrcvChStatus[LINTRCV_43_AE_HW_MAX_MODULES];

#define LINTRCV_43_AE_STOP_SEC_VAR_CLEARED_8
#include "LinTrcv_43_AE_MemMap.h"

/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/
static void LinTrcv_43_AE_InitImplementation(void);

static Std_ReturnType LinTrcv_43_AE_CommonCheckingChannel(const uint8 LinNetwork, const uint8 FunctionalId);
/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/
/**
* @internal
* @brief   Initializes all LINTRCV channels configured.
* @details This function performs software initialization for LinTrcv channles configured
*          - Sets all the available channels to sleep mode and configures
*            their state machine to LINTRCV_TRCV_MODE_SLEEP.
*
* @param   void
*
* @return  void
*/
static void  LinTrcv_43_AE_InitImplementation(void)
{
    uint8 LinTrcv_43_AE_ChLoop;
    uint32 CoreId = LinTrcv_43_AE_GetCoreID();

    for (LinTrcv_43_AE_ChLoop = (uint8)0U; LinTrcv_43_AE_ChLoop < LINTRCV_43_AE_HW_MAX_MODULES; LinTrcv_43_AE_ChLoop++)
    {
        if ((TRUE == LinTrcv_43_AE_apConfigPtr[CoreId]->LinTrcv_43_AE_ChannelPtr[LinTrcv_43_AE_ChLoop]->AllocatedPartition) &&
            (CoreId == LinTrcv_43_AE_apConfigPtr[CoreId]->LinTrcv_43_AE_ChannelPtr[LinTrcv_43_AE_ChLoop]->ChannelCoreId)
           )
        {
            LinTrcv_43_AE_apChannelConfigPtr[LinTrcv_43_AE_ChLoop] = (LinTrcv_43_AE_apConfigPtr[CoreId]->LinTrcv_43_AE_ChannelPtr)[LinTrcv_43_AE_ChLoop];
            LinTrcv_43_AE_Ipw_InitChannel(LinTrcv_43_AE_ChLoop, LinTrcv_43_AE_apChannelConfigPtr[LinTrcv_43_AE_ChLoop]->ChannelConfigPtr);
            /* Set LINTRCV channel state machine to LINTRCV_TRCV_MODE_SLEEP */
            LinTrcv_43_AE_au8LinTrcvChStatus[LinTrcv_43_AE_ChLoop] = LINTRCV_TRCV_MODE_SLEEP;
        }
    }
}

/**
* @internal
* @brief   Check invalid of LinNetwork.
* @details This function performs development error detection of the LinTrcv LinNetwork and provide the error:
*          - The LinTrcv module has yet initialized.
*          - Input LinNetwork index is out of range.
*          - Incorrect in configuration.
*
* @param[in] LinNetwork - the LIN network index.
* @param[in] FunctionalId - the functional index would be provided if any errors appeared.
*
* @return  Std_ReturnType
* @retval  E_NOT_OK   In case of at least a error occurred.
* @retval  E_OK       No error occurred.
*
**/
static Std_ReturnType LinTrcv_43_AE_CommonCheckingChannel(const uint8 LinNetwork, const uint8 FunctionalId)
{
    Std_ReturnType TempReturn = E_NOT_OK;
    uint32 CoreId = LinTrcv_43_AE_GetCoreID();

    /* Check whether the LINTRCV driver is in LINTRCV_43_AE_ACTIVE state */
    if (LINTRCV_43_AE_ACTIVE != LinTrcv_43_AE_au8LinTrcvDrvStatus[CoreId])
    {
        /* LINTRCV driver has not been initialized yet */
    #if (LINTRCV_43_AE_DEV_ERROR_DETECT == STD_ON)
        /* Report error to development error tracer */
        (void)Det_ReportError((uint16)LINTRCV_43_AE_MODULE_ID, \
                              0U, \
                              FunctionalId, \
                              (uint8)LINTRCV_43_AE_E_UNINIT \
                             );
    #else
        /* Casting to avoid misra and compiler warning */
        (void)FunctionalId;
    #endif /* (LINTRCV_43_AE_DEV_ERROR_DETECT == STD_ON) */
    }
    else
    {
        /* Check for invalid LinNetwork */
        if (LinNetwork >= LINTRCV_43_AE_HW_MAX_MODULES)
        {
            /* Invalid LinNetwork */
        #if (LINTRCV_43_AE_DEV_ERROR_DETECT == STD_ON)
            /* Report error to development error tracer */
            (void)Det_ReportError((uint16)LINTRCV_43_AE_MODULE_ID, \
                                  0U, \
                                  FunctionalId, \
                                  (uint8)LINTRCV_43_AE_E_INVALID_LIN_NETWORK \
                                 );
        #endif /* (LINTRCV_43_AE_DEV_ERROR_DETECT == STD_ON) */
        }
        else if ((FALSE == LinTrcv_43_AE_apChannelConfigPtr[LinNetwork]->AllocatedPartition) ||
                 (CoreId != LinTrcv_43_AE_apChannelConfigPtr[LinNetwork]->ChannelCoreId)
                )
        {
            /* Invalid requested resource */
        #if (LINTRCV_43_AE_DEV_ERROR_DETECT == STD_ON)
            /* Report error to development error tracer */
            (void)Det_ReportError((uint16)LINTRCV_43_AE_MODULE_ID, \
                                  0U, \
                                  FunctionalId, \
                                  (uint8)LINTRCV_43_AE_E_PARAM_CONFIG \
                                 );
        #endif /* (LINTRCV_43_AE_DEV_ERROR_DETECT == STD_ON) */
        }
        else
        {
            /* LinNetwork is valid after general check */
            TempReturn = (uint8)E_OK;
        }
    }

    return TempReturn;
}

/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/
/**
* @note put all LINTRCV code into defined section
*/
#define LINTRCV_43_AE_START_SEC_CODE
#include "LinTrcv_43_AE_MemMap.h"
/**
* @brief   Initializes the LINTRCV module.
* @details This function performs software initialization of LINTRCV
*          driver:
*          - Clears the shadow buffer of all available LinTrcv channels
*          - Sets all the available channels to sleep mode and configures
*            their state machine to LINTRCV_43_AE_CH_SLEEP_STATE.
*          - Set driver state machine to LINTRCV_43_AE_INIT.
*
* @param[in] ConfigPtr - Pointer to LINTRCV driver configuration set.
*
* @return  void
*
* @implements LinTrcv_43_AE_Init_Activity
**/
void LinTrcv_43_AE_Init(const LinTrcv_43_AE_ConfigType * ConfigPtr)
{
    uint32 CoreId = LinTrcv_43_AE_GetCoreID();


    if (NULL_PTR != ConfigPtr)
    {
        #if (LINTRCV_43_AE_DEV_ERROR_DETECT == STD_ON)
        /* Invalid pointer */
        (void)Det_ReportError((uint16)LINTRCV_43_AE_MODULE_ID, \
                                0U, \
                                (uint8)LINTRCV_43_AE_INIT_ID, \
                                (uint8)LINTRCV_43_AE_E_INIT_FAILED \
                             );
        #endif /* (LINTRCV_43_AE_DEV_ERROR_DETECT == STD_ON) */
    }
    else if ((NULL_PTR == LinTrcv_43_AE_PBCfgVariantPredefined[CoreId]) || (LinTrcv_43_AE_PBCfgVariantPredefined[CoreId]->PartitionCoreId != CoreId))
    {
        #if (LINTRCV_43_AE_DEV_ERROR_DETECT == STD_ON)
        /* Invalid requested resource */
        (void)Det_ReportError((uint16)LINTRCV_43_AE_MODULE_ID, \
                              0U, \
                              (uint8)LINTRCV_43_AE_INIT_ID, \
                              (uint8)LINTRCV_43_AE_E_PARAM_CONFIG \
                             );
        #endif /* (LINTRCV_43_AE_DEV_ERROR_DETECT == STD_ON) */
    }
    else
    {
        LinTrcv_43_AE_apConfigPtr[CoreId] = LinTrcv_43_AE_PBCfgVariantPredefined[CoreId];

        LinTrcv_43_AE_InitImplementation();

        /* Update LINTRCV driver status to LINTRCV_43_AE_INIT */
        LinTrcv_43_AE_au8LinTrcvDrvStatus[CoreId] = LINTRCV_43_AE_ACTIVE;
    }
}

/**
* @brief   The internal state of the LIN transceiver driver is switched to mode given in the parameter OpMode.
*
* @param[in] LinNetwork       LIN network to wich API call has to be applied
* @param[in] OpMode           The parameter says to which operation mode the change shall be performed.
*
* @return                  Std_ReturnType.
* @retval E_OK             will be returned if the transceiver state has been changed to the requested mode.
*
* @retval E_NOT_OK         will be returned if the transceiver state change is not
*                          accepted or has failed or the parameter is out of the allowed range.
*
*
*
**/
Std_ReturnType  LinTrcv_43_AE_SetOpMode(uint8 LinNetwork, LinTrcv_TrcvModeType OpMode)
{
    Std_ReturnType TempReturn;

    /* General Lin Network checking */
    TempReturn = LinTrcv_43_AE_CommonCheckingChannel(LinNetwork, LINTRCV_43_AE_SETOPMODE_ID);

    if ((uint8)E_OK == TempReturn)
    {
        /* the channel LinNetwork is in mode LINTRCV_TRCV_MODE_SLEEP and the optional transition from this mode to LINTRCV_TRCV_MODE_STANDBY is enabled*/
        if (LINTRCV_TRCV_MODE_STANDBY == OpMode)
        {
            if ((LINTRCV_TRCV_MODE_SLEEP == LinTrcv_43_AE_au8LinTrcvChStatus[LinNetwork]) || (LINTRCV_TRCV_MODE_NORMAL == LinTrcv_43_AE_au8LinTrcvChStatus[LinNetwork]))
            {
                /* Call functional of IPV to change mode and verify mode changed or not, if mode is changed will change mode, Otherwise keep mode this */
                if ((uint8)E_OK == LinTrcv_43_AE_Ipw_SetOpMode(LinNetwork, OpMode))
                {
                    LinTrcv_43_AE_au8LinTrcvChStatus[LinNetwork] = LINTRCV_TRCV_MODE_STANDBY;
#if (LINTRCV_43_AE_ICU_USED == STD_ON)
                    /* SWS_LinTrcv_43_AE_00162 : LinTrcv driver shall enable the ICU channels when the transceiver transmits to standby mode (LINTRCV_43_AE_STANDBY) */
                    Icu_EnableNotification(LinTrcv_43_AE_apChannelConfigPtr[LinNetwork]->LinTrcvIcuChannel);
#endif /* (LINTRCV_43_AE_ICU_USED == STD_ON) */
                }
                else
                {
                    TempReturn = (uint8)E_NOT_OK;
#if (LINTRCV_43_AE_DEV_ERROR_DETECT == STD_ON)
                    /* SWS_LinTrcv_43_AE_00114 */
                    (void)Det_ReportError((uint16)LINTRCV_43_AE_MODULE_ID, \
                                           0U, \
                                           (uint8)LINTRCV_43_AE_SETOPMODE_ID, \
                                           (uint8)LINTRCV_43_AE_E_INVALID_TRCV_OPMODE \
                                         );
#endif /* (LINTRCV_43_AE_DEV_ERROR_DETECT == STD_ON) */
                }
            }
        }
        else if (LINTRCV_TRCV_MODE_SLEEP == OpMode)
        {
           if ((LINTRCV_TRCV_MODE_STANDBY == LinTrcv_43_AE_au8LinTrcvChStatus[LinNetwork]) || (LINTRCV_TRCV_MODE_NORMAL == LinTrcv_43_AE_au8LinTrcvChStatus[LinNetwork]))
           {
                /* Call functional of IPV to change mode and verify mode changed or not, if mode is changed will change mode, Otherwise keep mode this */
                if ((uint8)E_OK == LinTrcv_43_AE_Ipw_SetOpMode(LinNetwork, OpMode))
                {
                    LinTrcv_43_AE_au8LinTrcvChStatus[LinNetwork] = LINTRCV_TRCV_MODE_SLEEP;
                }
                else
                {
                    TempReturn = (uint8)E_NOT_OK;
#if (LINTRCV_43_AE_DEV_ERROR_DETECT == STD_ON)
                    if (LINTRCV_TRCV_MODE_STANDBY == LinTrcv_43_AE_au8LinTrcvChStatus[LinNetwork])
                    {
                        /* SWS_LinTrcv_43_AE_00115 */
                        (void)Det_ReportError((uint16)LINTRCV_43_AE_MODULE_ID, \
                                            0U, \
                                            (uint8)LINTRCV_43_AE_SETOPMODE_ID, \
                                            (uint8)LINTRCV_43_AE_E_TRCV_NOT_NORMAL \
                                            );
                    }
#endif /* (LINTRCV_43_AE_DEV_ERROR_DETECT == STD_ON) */
                }
           }
        }
        else if (LINTRCV_TRCV_MODE_NORMAL == OpMode)
        {
           if ((LINTRCV_TRCV_MODE_STANDBY == LinTrcv_43_AE_au8LinTrcvChStatus[LinNetwork]) || (LINTRCV_TRCV_MODE_SLEEP == LinTrcv_43_AE_au8LinTrcvChStatus[LinNetwork]))
           {
               /* Call functional of IPV to change mode and verify mode changed or not, if mode is changed will change mode, Otherwise keep mode this */
                if ((uint8)E_OK == LinTrcv_43_AE_Ipw_SetOpMode(LinNetwork, OpMode))
                {
                    LinTrcv_43_AE_au8LinTrcvChStatus[LinNetwork] = LINTRCV_TRCV_MODE_NORMAL;
#if (LINTRCV_43_AE_ICU_USED == STD_ON)
                    /* SWS_LinTrcv_43_AE_00163 : LinTrcv driver shall disable the ICU channels when the transceiver transmits to Normal mode (LINTRCV_43_AE_NORMAL) */
                    Icu_DisableNotification(LinTrcv_43_AE_apChannelConfigPtr[LinNetwork]->LinTrcvIcuChannel);
#endif /* (LINTRCV_43_AE_ICU_USED == STD_ON) */
                }
                else
                {
                    TempReturn = (uint8)E_NOT_OK;
#if (LINTRCV_43_AE_DEV_ERROR_DETECT == STD_ON)
                    if (LINTRCV_TRCV_MODE_STANDBY == LinTrcv_43_AE_au8LinTrcvChStatus[LinNetwork])
                    {
                        /* SWS_LinTrcv_43_AE_00149 */
                        (void)Det_ReportError((uint16)LINTRCV_43_AE_MODULE_ID, \
                                            0U, \
                                            (uint8)LINTRCV_43_AE_SETOPMODE_ID, \
                                            (uint8)LINTRCV_43_AE_E_TRCV_NOT_SLEEP \
                                            );
                    }
#endif /* (LINTRCV_43_AE_DEV_ERROR_DETECT == STD_ON) */
                }
           }
        }
        else
        {
            /* nothing need to do */
            TempReturn = (uint8)E_NOT_OK;
        }
    }
    else
    {
        /* Invalid LinNetwork so do nothing */
    }

    return TempReturn;
}

/**
* @brief   API detects the actual software state of LIN transceiver driver.
*
* @param[in] LinNetwork       LIN network to wich API call has to be applied
* @param[out] OpMode           Pointer to operation mode of the bus the API is applied to.
*
* @return                  Std_ReturnType.
* @retval E_OK             will be returned if the operation mode is detected.
*
* @retval E_NOT_OK         will be returned, if service request is failed due to
*                          development errors or the operation mode is not detected.
*
*
*
**/
Std_ReturnType  LinTrcv_43_AE_GetOpMode(uint8 LinNetwork, LinTrcv_TrcvModeType * OpMode)
{
    Std_ReturnType TempReturn;

    /* General Lin Network checking */
    TempReturn = LinTrcv_43_AE_CommonCheckingChannel(LinNetwork, LINTRCV_43_AE_GETOPMODE_ID);

    if ((uint8)E_NOT_OK == TempReturn)
    {
        /* Invalid channel so do nothing */
    }
    else
    {
        /* Check OpMode for not being a null pointer */
        if (NULL_PTR == OpMode)
        {
#if (LINTRCV_43_AE_DEV_ERROR_DETECT == STD_ON)
            /* Invalid pointer */
            /* Report error to development error tracer */
            (void)Det_ReportError((uint16)LINTRCV_43_AE_MODULE_ID, \
                                  0U, \
                                  (uint8)LINTRCV_43_AE_GETOPMODE_ID, \
                                  (uint8)LINTRCV_43_AE_E_PARAM_POINTER \
                                 );
#endif /* (LINTRCV_43_AE_DEV_ERROR_DETECT == STD_ON) */
            TempReturn = E_NOT_OK;
        }
        else
        {
            /* The function LinTrcv_43_AE_GetOpMode shall return the actual state of the LIN transceiver driver in the parameter OpMode */
            TempReturn = LinTrcv_43_AE_Ipw_GetOpMode(LinNetwork, OpMode);
        }
    }

    return TempReturn;

}

/**
* @brief   Notifies the calling function if a wakeup is detected.
*
* @param[in] LinNetwork       LIN network to which API call has to be applied.
*
* @return                  Std_ReturnType.
* @retval E_NOT_OK         Will be returned, if no wakeup has been detected
*
* @retval E_OK             Will be returned, if a wakeup has been detected.
*
* @pre:    LinTrcv_43_AE_Init function must be called before this API.
*
*
**/
Std_ReturnType  LinTrcv_43_AE_CheckWakeup(uint8 LinNetwork)
{
    Std_ReturnType TempReturn;

    /* General channel checking */
    TempReturn = LinTrcv_43_AE_CommonCheckingChannel(LinNetwork, LINTRCV_43_AE_CHECKWAKEUP_ID);

    if ((uint8)E_NOT_OK == TempReturn)
    {
        /* Invalid channel so do nothing */
    }
    else
    {

        /* Check if the addressed LINTRCV channel is in LINTRCV_TRCV_MODE_SLEEP or LINTRCV_TRCV_MODE_STANDBY state*/
        if ((LINTRCV_TRCV_MODE_SLEEP == LinTrcv_43_AE_au8LinTrcvChStatus[LinNetwork]) || (LINTRCV_TRCV_MODE_STANDBY == LinTrcv_43_AE_au8LinTrcvChStatus[LinNetwork]))
        {
            /* LinTrcv channel is in LINTRCV_TRCV_MODE_SLEEP state */
            /* Check if LinTrcv channel has detected a wake-up */
            if ((uint8)E_OK == LinTrcv_43_AE_Ipw_CheckWakeup(LinNetwork))
            {
                /* E_OK Will be returned, if a wakeup has been detected */
                TempReturn = (uint8)E_OK;
#if (LINTRCV_43_AE_WAKEUP_DETECTION == STD_ON)
                if (TRUE == LinTrcv_43_AE_apChannelConfigPtr[LinNetwork]->LinTrcvWakeupByBusUsed)
                {
                    /* Indicates a valid timer wakeup event to ECU State Manager */
                    EcuM_SetWakeupEvent(LinTrcv_43_AE_apChannelConfigPtr[LinNetwork]->LinTrcvChannelEcuMWakeupSource);
                    /* report the wakeup source after the successful wakeup to LinInterface */
                    LinIf_WakeupConfirmation(LinTrcv_43_AE_apChannelConfigPtr[LinNetwork]->LinTrcvChannelEcuMWakeupSource);
                }
#endif /* (LINTRCV_43_AE_WAKEUP_DETECTION == STD_ON) */
            }
        }
        else
        {
            TempReturn = (uint8)E_NOT_OK;
#if (LINTRCV_43_AE_DEV_ERROR_DETECT == STD_ON)
            /* The addressed LIN network is not in mode LINTRCV_TRCV_MODE_SLEEP */
            /* Report error to development error tracer */
            (void)Det_ReportError((uint16)LINTRCV_43_AE_MODULE_ID, \
                                  0U, \
                                  (uint8)LINTRCV_43_AE_CHECKWAKEUP_ID, \
                                  (uint8)LINTRCV_43_AE_E_TRCV_NOT_SLEEP \
                                 );
#endif /* (LINTRCV_43_AE_DEV_ERROR_DETECT == STD_ON) */
        }
    }

    return TempReturn;
}

/**
* @brief   This API enables, disables and clears the notification for wakeup events on the addressed network.
*
* @param[in] LinNetwork           LIN network to which API call has to be applied.
*
* @param[in] TrcvWakupMode        Requested transceiver wakup reason.
*
* @return                  Std_ReturnType.
* @retval E_NOT_OK         will be returned, if service request is failed due to
*                          development errors or the wakeup mode is not set
* @retval E_OK             will be returned if the transceiver state has been changed
*                          to the requested mode..
*
* @pre:    LinTrcv_43_AE_Init function must be called before this API.
*
*
**/
Std_ReturnType  LinTrcv_43_AE_SetWakeupMode(uint8 LinNetwork, LinTrcv_TrcvWakeupModeType TrcvWakupMode)
{
    Std_ReturnType TempReturn;

    /* General channel checking */
    TempReturn = LinTrcv_43_AE_CommonCheckingChannel(LinNetwork, LINTRCV_43_AE_SETWAKEUPMODE_ID);

    if ((uint8)E_NOT_OK == TempReturn)
    {
        /* Invalid channel so do nothing */
    }
    else
    {
         TempReturn = LinTrcv_43_AE_Ipw_SetWakeupMode(LinNetwork, TrcvWakupMode);
    }

    return TempReturn;
}

/**
* @brief   This API provides the reason for the wakeup that the LIN transceiver has detected
*          in the parameter "Reason". The ability to detect and differentiate the possible
*          wakeup reasons depends strongly on the LIN transceiver hardware.
*
* @param[in] LinNetwork       LIN network to wich API call has to be applied
* @param[out] Reason          Pointer to wakeup reason of the bus the API is applied to.
*
* @return                  Std_ReturnType.
* @retval E_OK             will be returned if the wake up reason is detected.
*
* @retval E_NOT_OK         will be returned, if service request is failed due to
*                          development errors or the wakeup reason is not detected..
*
*
*
**/
Std_ReturnType  LinTrcv_43_AE_GetBusWuReason(uint8 LinNetwork, LinTrcv_TrcvWakeupReasonType * Reason)
{
    Std_ReturnType TempReturn;

    /* General channel checking */
    TempReturn = LinTrcv_43_AE_CommonCheckingChannel(LinNetwork, LINTRCV_43_AE_GETBUSWUREASON_ID);

    if ((uint8)E_NOT_OK == TempReturn)
    {
        /* Invalid channel so do nothing */
    }
    else
    {
        /* Check Reason for not being a null pointer */
        if (NULL_PTR == Reason)
        {
#if (LINTRCV_43_AE_DEV_ERROR_DETECT == STD_ON)
            /* Invalid pointer */
            /* Report error to development error tracer */
            (void)Det_ReportError((uint16)LINTRCV_43_AE_MODULE_ID, \
                                  0U, \
                                  (uint8)LINTRCV_43_AE_GETBUSWUREASON_ID, \
                                  (uint8)LINTRCV_43_AE_E_PARAM_POINTER \
                                 );
#endif /* (LINTRCV_43_AE_DEV_ERROR_DETECT == STD_ON) */
            TempReturn = E_NOT_OK;
        }
        else
        {
            /* The function LinTrcv_43_AE_GetBusWuReason shall return the reason for the wake up that the LIN transceiver has detected in the parameter Reason */
        }
    }

    return TempReturn;
}
#if (LINTRCV_43_AE_VERSION_INFO_API == STD_ON)

/**
* @brief   Returns the version information of this module.
* @details The version information includes:
*
*          - Two bytes for the Vendor ID
*          - Two bytes for the Module ID
*          - One byte  for the Instance ID
*          - Three bytes version number. The numbering shall be vendor
*            specific: it consists of:
*
*             - The major, the minor and the patch version number of
*               the module;
*             - The AUTOSAR specification version number shall not
*               be included. The AUTOSAR specification version number is
*               checked during compile time and therefore not required
*               in this API.
*
* @param[in,out] versioninfo   Pointer for storing the version information
*                              of this module.
*
* @return void.
*
* @implements LinTrcv_43_AE_GetVersionInfo_Activity
*
**/
void LinTrcv_43_AE_GetVersionInfo(Std_VersionInfoType * versioninfo)
{
#if( LINTRCV_43_AE_DEV_ERROR_DETECT == STD_ON )
    if (NULL_PTR == versioninfo)
    {
        (void)Det_ReportError((uint16)LINTRCV_43_AE_MODULE_ID, \
                              0U, \
                              (uint8)LINTRCV_43_AE_GETVERSIONINFO_ID, \
                              (uint8)LINTRCV_43_AE_E_PARAM_POINTER \
                             );
    }
    else
#endif /* LINTRCV_43_AE_DEV_ERROR_DETECT == STD_ON */
    {
        (versioninfo)->vendorID = (uint16) LINTRCV_43_AE_VENDOR_ID;
        (versioninfo)->moduleID = (uint8) LINTRCV_43_AE_MODULE_ID;
        (versioninfo)->sw_major_version = (uint8) LINTRCV_43_AE_SW_MAJOR_VERSION;
        (versioninfo)->sw_minor_version = (uint8) LINTRCV_43_AE_SW_MINOR_VERSION;
        (versioninfo)->sw_patch_version = (uint8) LINTRCV_43_AE_SW_PATCH_VERSION;
    }
}
#endif /* LINTRCV_43_AE_VERSION_INFO_API == STD_ON */

#define LINTRCV_43_AE_STOP_SEC_CODE
#include "LinTrcv_43_AE_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */
