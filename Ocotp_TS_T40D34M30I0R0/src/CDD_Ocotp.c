
/*==================================================================================================
*   Project              : RTD AUTOSAR 4.7
*   Platform             : CORTEXM
*   Peripheral           : MEM_OTP_IP
*   Dependencies         : none
*
*   Autosar Version      : 4.7.0
*   Autosar Revision     : ASR_REL_4_7_REV_0000
*   Autosar Conf.Variant :
*   SW Version           : 3.0.0
*   Build Version        : S32K3_RTD_3_0_0_D2303_ASR_REL_4_7_REV_0000_20230331
*
*   Copyright 2020 - 2023 NXP Semiconductors
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
*   @addtogroup OCOTP
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
#include "CDD_Ocotp.h"
#include "Det.h"
#include "SchM_Ocotp.h"
/*==================================================================================================
 *                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define CDD_OCOTP_VENDOR_ID_C                      43
#define CDD_OCOTP_AR_RELEASE_MAJOR_VERSION_C       4
#define CDD_OCOTP_AR_RELEASE_MINOR_VERSION_C       7
#define CDD_OCOTP_AR_RELEASE_REVISION_VERSION_C    0
#define CDD_OCOTP_SW_MAJOR_VERSION_C               3
#define CDD_OCOTP_SW_MINOR_VERSION_C               0
#define CDD_OCOTP_SW_PATCH_VERSION_C               0

/*==================================================================================================
 *                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and CDD_Ocotp.h header file are of the same vendor */
#if (CDD_OCOTP_VENDOR_ID_C != CDD_OCOTP_VENDOR_ID)
    #error "CDD_Ocotp.c and CDD_Ocotp.h have different vendor ids"
#endif
/* Check if current file and CDD_Ocotp.h header file are of the same AutoSar version */
#if ((CDD_OCOTP_AR_RELEASE_MAJOR_VERSION_C != CDD_OCOTP_AR_RELEASE_MAJOR_VERSION) || \
     (CDD_OCOTP_AR_RELEASE_MINOR_VERSION_C != CDD_OCOTP_AR_RELEASE_MINOR_VERSION) || \
     (CDD_OCOTP_AR_RELEASE_REVISION_VERSION_C != CDD_OCOTP_AR_RELEASE_REVISION_VERSION) \
    )
    #error "Software Version Numbers of CDD_Ocotp.c and CDD_Ocotp.h are different"
#endif
/* Check if current file and CDD_Ocotp.h header file are of the same Software version */
#if ((CDD_OCOTP_SW_MAJOR_VERSION_C != CDD_OCOTP_SW_MAJOR_VERSION) || \
     (CDD_OCOTP_SW_MINOR_VERSION_C != CDD_OCOTP_SW_MINOR_VERSION) || \
     (CDD_OCOTP_SW_PATCH_VERSION_C != CDD_OCOTP_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of CDD_Ocotp.c and CDD_Ocotp.h are different"
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if current file and Det header file are of the same Autosar version */
    #if ((CDD_OCOTP_AR_RELEASE_MAJOR_VERSION_C != DET_AR_RELEASE_MAJOR_VERSION) || \
         (CDD_OCOTP_AR_RELEASE_MINOR_VERSION_C != DET_AR_RELEASE_MINOR_VERSION) \
        )
        #error "AutoSar Version Numbers of CDD_Ocotp.c and Det.h are different"
    #endif
    /* Check if current file and SchM_Ocotp header file are of the same Autosar version */
    #if ((CDD_OCOTP_AR_RELEASE_MAJOR_VERSION_C != SCHM_OCOTP_AR_RELEASE_MAJOR_VERSION) || \
         (CDD_OCOTP_AR_RELEASE_MINOR_VERSION_C != SCHM_OCOTP_AR_RELEASE_MINOR_VERSION) \
        )
        #error "AutoSar Version Numbers of CDD_Ocotp.c and SchM_Ocotp.h are different"
    #endif
    /* Check if current file and OsIf header file are of the same Autosar version */
    #if ((CDD_OCOTP_AR_RELEASE_MAJOR_VERSION_C != OSIF_AR_RELEASE_MAJOR_VERSION) || \
         (CDD_OCOTP_AR_RELEASE_MINOR_VERSION_C != OSIF_AR_RELEASE_MINOR_VERSION) \
        )
        #error "AutoSar Version Numbers of CDD_Ocotp.c and OsIf.h are different"
    #endif
#endif

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

/*==================================================================================================
*                                        GLOBAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                        GLOBAL VARIABLES
==================================================================================================*/
#define OCOTP_START_SEC_VAR_CLEARED_UNSPECIFIED_NO_CACHEABLE
#include "Ocotp_MemMap.h"

const Ocotp_ConfigType *Ocotp_pConfigPtr;

#define OCOTP_STOP_SEC_VAR_CLEARED_UNSPECIFIED_NO_CACHEABLE
#include "Ocotp_MemMap.h"
/*==================================================================================================
*                                    LOCAL FUNCTION PROTOTYPES
==================================================================================================*/
/*==================================================================================================
*                                         LOCAL FUNCTIONS
==================================================================================================*/
/*==================================================================================================
*                                        GLOBAL FUNCTIONS
==================================================================================================*/

#define OCOTP_START_SEC_CODE
#include "Ocotp_MemMap.h"

/**
 * @brief        The function initializes Ocotp module.
 * @details      The function sets the internal module variables according to given
 *               configuration set.
 *
 * @param[in]    ConfigPtr        Pointer to Ocotp driver configuration set.
 *
 * @api
 *
 * @pre          Ocotp_pConfigPtr must be NULL_PTR.
 *
 * @implements   Ocotp_Init_Activity
 *
 */
void Ocotp_Init(const Ocotp_ConfigType * const ConfigPtr)
{
#if(OCOTP_DEV_ERROR_DETECT == STD_ON)
    if (NULL_PTR != Ocotp_pConfigPtr)
    {
        (void)Det_ReportError((uint16)OCOTP_MODULE_ID, OCOTP_INSTANCE_ID, OCOTP_INIT_ID, OCOTP_E_ALREADY_INITIALIZED);
    }
    else
    {
#ifdef OCOTP_PRECOMPILE_SUPPORT
        if (NULL_PTR != ConfigPtr)
#else
        if (NULL_PTR == ConfigPtr)
#endif /* OCOTP_PRECOMPILE_SUPPORT */
        {
            (void) Det_ReportError((uint16)OCOTP_MODULE_ID, OCOTP_INSTANCE_ID, OCOTP_INIT_ID, OCOTP_E_PARAM_CONFIG);
        }
        else
        {
#endif /* OCOTP_DEV_ERROR_DETECT == STD_ON */
            #ifdef OCOTP_PRECOMPILE_SUPPORT
                Ocotp_pConfigPtr = &Ocotp_Config;
                (void)ConfigPtr;
            #else
                Ocotp_pConfigPtr = ConfigPtr;
            #endif /* OCOTP_PRECOMPILE_SUPPORT */
                Ocotp_IPW_Init(Ocotp_pConfigPtr);
#if(OCOTP_DEV_ERROR_DETECT == STD_ON)
        }
    }
#endif /* OCOTP_DEV_ERROR_DETECT == STD_ON */
    return;
}

/**
 * @brief        The function de-initializes Ocotp module.
 * @details      The function sets the Ocotp module's status to un-initialized.
 *
 * @param[in]    none.
 *
 * @api
 *
 * @pre          Ocotp_pConfigPtr must not be NULL_PTR.
 *
 * @implements   Ocotp_Deinit_Activity
 *
 */
void Ocotp_Deinit(void)
{
#if(OCOTP_DEV_ERROR_DETECT == STD_ON)
    if (NULL_PTR == Ocotp_pConfigPtr)
    {
        (void)Det_ReportError((uint16)OCOTP_MODULE_ID, OCOTP_INSTANCE_ID, OCOTP_DEINIT_ID, OCOTP_E_UNINIT);
    }
    else
    {
#endif /* OCOTP_DEV_ERROR_DETECT == STD_ON */
            Ocotp_IPW_Deinit();
            Ocotp_pConfigPtr = NULL_PTR;
#if(OCOTP_DEV_ERROR_DETECT == STD_ON)
    }
#endif /* OCOTP_DEV_ERROR_DETECT == STD_ON */
    return;
}


#if (OCOTP_READ_EFUSE_API == STD_ON)
/**
 * @brief        The function reads data from efuse word.
 * @details      The function reads the data from the eFuse which was
 *               configured by configuration tool.
 *
 * @param[in]    eFuseChannel        Channel of eFuse such as 0, 1, 2 which was configured by user.
 * @param[in]    data                pointer points to the data read from eFuse word.
 *
 * @return       Std_ReturnType
 * @retval       E_OK                    Read operation is successful.
 * @retval       E_NOT_OK                Read operation failed.
 *
 * @api
 *
 * @pre          Ocotp_pConfigPtr must not be NULL_PTR.
 *
 * @implements   Ocotp_ReadEFuse_Activity
 *
 */
Std_ReturnType Ocotp_ReadEFuse
(
    Ocotp_ChannelType eFuseChannel,
    uint32* pData
)
{
    Std_ReturnType eRetVal = (Std_ReturnType)E_NOT_OK;
    Mem_Otp_Ip_StatusType eStatus;

#if(OCOTP_DEV_ERROR_DETECT == STD_ON)
    if (NULL_PTR == Ocotp_pConfigPtr)
    {
        (void)Det_ReportError((uint16)OCOTP_MODULE_ID, OCOTP_INSTANCE_ID, OCOTP_READ_EFUSE_ID, OCOTP_E_UNINIT);
    }
    else if(eFuseChannel >= OCOTP_NUMBER_CHANNEL_CONFIGURED)
    {
        (void)Det_ReportError((uint16)OCOTP_MODULE_ID, OCOTP_INSTANCE_ID, OCOTP_READ_EFUSE_ID, OCOTP_E_PARAM_CHANNEL);
    }
    else if(NULL_PTR == pData)
    {
        (void)Det_ReportError((uint16)OCOTP_MODULE_ID, OCOTP_INSTANCE_ID, OCOTP_READ_EFUSE_ID, OCOTP_E_PARAM_POINTER);
    }
    else
#endif /* OCOTP_DEV_ERROR_DETECT == STD_ON */
    {
            SchM_Enter_Ocotp_OCOTP_EXCLUSIVE_AREA_01();

            eStatus = Ocotp_IPW_ReadEFuse(&(*(Ocotp_pConfigPtr->pChanelConfig))[eFuseChannel], pData);

            SchM_Exit_Ocotp_OCOTP_EXCLUSIVE_AREA_01();
            if(STATUS_MEM_OTP_IP_BUSY == eStatus)
            {
            #if(OCOTP_DEV_ERROR_DETECT == STD_ON)
                (void)Det_ReportError((uint16)OCOTP_MODULE_ID, OCOTP_INSTANCE_ID, OCOTP_READ_EFUSE_ID, OCOTP_E_BUSY);
            #endif /* OCOTP_DEV_ERROR_DETECT == STD_ON */
            }
            if(STATUS_MEM_OTP_IP_ERROR == eStatus)
            {
                (void)Det_ReportTransientFault((uint16)OCOTP_MODULE_ID, OCOTP_INSTANCE_ID, OCOTP_READ_EFUSE_ID, OCOTP_E_READ_FAILED);
            }
            if(STATUS_MEM_OTP_IP_ERROR_TIMEOUT == eStatus)
            {
                (void)Det_ReportRuntimeError((uint16)OCOTP_MODULE_ID, OCOTP_INSTANCE_ID, OCOTP_READ_EFUSE_ID, OCOTP_E_TIMEOUT);
            }
            if (STATUS_MEM_OTP_IP_SUCCESS == eStatus)
            {
                eRetVal = (Std_ReturnType)E_OK;
            }
    }
    return eRetVal;
}
#endif /* OCOTP_READ_EFUSE_API == STD_ON */


#if (OCOTP_READ_MIRROR_API == STD_ON)
/**
 * @brief        The function reads data from mirror register.
 * @details      The function reads the data from the mirror register
 *               which was configured in eFuse channel by configuration tool.
 *
 * @param[in]    eFuseChannel        Channel of eFuse such as 0, 1, 2 which was configured by user.
 *
 * @return       Std_ReturnType
 * @retval       E_OK read operation is successful.
 * @retval       E_NOT_OK read operation failed.
 *
 * @api
 *
 * @pre          Ocotp_pConfigPtr must not be NULL_PTR.
 *
 * @implements   Ocotp_ReadMirrorRegister_Activity
 *
 */
Std_ReturnType Ocotp_ReadMirrorRegister
(
    Ocotp_ChannelType eFuseChannel,
    uint32* pData
)
{
    Std_ReturnType eRetVal = (Std_ReturnType)E_NOT_OK;
    Mem_Otp_Ip_StatusType eStatus;

#if(OCOTP_DEV_ERROR_DETECT == STD_ON)
    if (NULL_PTR == Ocotp_pConfigPtr)
    {
        (void)Det_ReportError((uint16)OCOTP_MODULE_ID, OCOTP_INSTANCE_ID, OCOTP_READ_MIRROR_REGISTER_ID, OCOTP_E_UNINIT);
    }
    else if (eFuseChannel >= OCOTP_NUMBER_CHANNEL_CONFIGURED)
    {
        (void)Det_ReportError((uint16)OCOTP_MODULE_ID, OCOTP_INSTANCE_ID, OCOTP_READ_MIRROR_REGISTER_ID, OCOTP_E_PARAM_CHANNEL);
    }
    else if(NULL_PTR == pData)
    {
        (void)Det_ReportError((uint16)OCOTP_MODULE_ID, OCOTP_INSTANCE_ID, OCOTP_READ_MIRROR_REGISTER_ID, OCOTP_E_PARAM_POINTER);
    }
    else
    {
#endif /* OCOTP_DEV_ERROR_DETECT == STD_ON */
        eStatus = Ocotp_IPW_ReadMirrorRegister(&(*(Ocotp_pConfigPtr->pChanelConfig))[eFuseChannel], pData);
        if(STATUS_MEM_OTP_IP_BUSY == eStatus)
        {
        #if(OCOTP_DEV_ERROR_DETECT == STD_ON)
            (void)Det_ReportError((uint16)OCOTP_MODULE_ID, OCOTP_INSTANCE_ID, OCOTP_READ_MIRROR_REGISTER_ID, OCOTP_E_BUSY);
        #endif /* OCOTP_DEV_ERROR_DETECT == STD_ON */
        }
        if(STATUS_MEM_OTP_IP_ERROR == eStatus)
        {
            (void)Det_ReportTransientFault((uint16)OCOTP_MODULE_ID, OCOTP_INSTANCE_ID, OCOTP_READ_MIRROR_REGISTER_ID, OCOTP_E_READ_FAILED);
        }
        if (STATUS_MEM_OTP_IP_SUCCESS == eStatus)
        {
            eRetVal = (Std_ReturnType)E_OK;
        }
#if(OCOTP_DEV_ERROR_DETECT == STD_ON)
    }
#endif /* OCOTP_DEV_ERROR_DETECT == STD_ON */
    return eRetVal;
}
#endif /* OCOTP_READ_MIRROR_API == STD_ON */

#if (OCOTP_WRITE_MIRROR_API == STD_ON)
/**
 * @brief        The function writes data to mirror register.
 * @details      The function writes the data to the mirror register
 *               which was configured in eFuse channel by configuration tool.
 *
 * @param[in]    eFuseChannel        Channel of eFuse such as 0, 1, 2 which was configured by user.
 * @param[in]    data                data to be written.
 *
 * @return       Std_ReturnType
 * @retval       E_OK write operation is successful.
 * @retval       E_NOT_OK write operation failed.
 *
 * @api
 *
 * @pre          Ocotp_pConfigPtr must not be NULL_PTR.
 *
 * @implements   Ocotp_WriteMirrorRegister_Activity
 *
 */
Std_ReturnType Ocotp_WriteMirrorRegister
(
    Ocotp_ChannelType eFuseChannel,
    uint32 data
)
{
    Std_ReturnType eRetVal = (Std_ReturnType)E_NOT_OK;
    Mem_Otp_Ip_StatusType eStatus;

#if(OCOTP_DEV_ERROR_DETECT == STD_ON)
    if (NULL_PTR == Ocotp_pConfigPtr)
    {
        (void)Det_ReportError((uint16)OCOTP_MODULE_ID, OCOTP_INSTANCE_ID, OCOTP_WRITE_MIRROR_REGISTER_ID, OCOTP_E_UNINIT);
    }
    else if (eFuseChannel >= OCOTP_NUMBER_CHANNEL_CONFIGURED)
    {
        (void)Det_ReportError((uint16)OCOTP_MODULE_ID, OCOTP_INSTANCE_ID, OCOTP_WRITE_MIRROR_REGISTER_ID, OCOTP_E_PARAM_CHANNEL);
    }
    else
    {
#endif /* OCOTP_DEV_ERROR_DETECT == STD_ON */
        eStatus = Ocotp_IPW_WriteMirrorRegister(&(*(Ocotp_pConfigPtr->pChanelConfig))[eFuseChannel], data);
        if (STATUS_MEM_OTP_IP_BUSY == eStatus)
        {
        #if (OCOTP_DEV_ERROR_DETECT == STD_ON)
            (void)Det_ReportError((uint16)OCOTP_MODULE_ID, OCOTP_INSTANCE_ID, OCOTP_WRITE_MIRROR_REGISTER_ID, OCOTP_E_BUSY);
        #endif /* OCOTP_DEV_ERROR_DETECT == STD_ON */
        }
        if (STATUS_MEM_OTP_IP_ERROR == eStatus)
        {
            (void)Det_ReportTransientFault((uint16)OCOTP_MODULE_ID, OCOTP_INSTANCE_ID, OCOTP_WRITE_MIRROR_REGISTER_ID, OCOTP_E_WRITE_FAILED);
        }
        if (STATUS_MEM_OTP_IP_SUCCESS == eStatus)
        {
            eRetVal = (Std_ReturnType)E_OK;
        }
#if(OCOTP_DEV_ERROR_DETECT == STD_ON)
    }
#endif /* OCOTP_DEV_ERROR_DETECT == STD_ON */
    return eRetVal;
}
#endif /* OCOTP_WRITE_MIRROR_API == STD_ON */

#if (OCOTP_GET_STATUS_API == STD_ON)
/**
 * @brief        The function gets status of Ocotp module.
 * @details      The function gets status of Ocotp module
 *               Secure mode is enabled or not. Error occurred or not and
 *               Status of hardware.
 *
 * @param[in]    HwIndex        Index of hardware configured.
 * @param[in]    pStatus        Pointer points to status structure.
 *
 * @return       Std_ReturnType
 *
 * @api
 *
 * @pre          Ocotp_pConfigPtr must not be NULL_PTR.
 *
 * @implements   Ocotp_GetStatus_Activity
 *
 */
Std_ReturnType Ocotp_GetStatus
(
    uint8 HwIndex,
    Ocotp_StatusType* pStatus
)
{
    Std_ReturnType eRetVal = (Std_ReturnType)E_NOT_OK;

#if(OCOTP_DEV_ERROR_DETECT == STD_ON)
    if (NULL_PTR == Ocotp_pConfigPtr)
    {
        (void)Det_ReportError((uint16)OCOTP_MODULE_ID, OCOTP_INSTANCE_ID, OCOTP_GET_STATUS_ID, OCOTP_E_UNINIT);
    }
    else if(HwIndex >= OCOTP_NUMBER_INSTANCE_CONFIGURED)
    {
        (void)Det_ReportError((uint16)OCOTP_MODULE_ID, OCOTP_INSTANCE_ID, OCOTP_GET_STATUS_ID, OCOTP_E_PARAM_INSTANCE);
    }
    else if(NULL_PTR == pStatus)
    {
        (void)Det_ReportError((uint16)OCOTP_MODULE_ID, OCOTP_INSTANCE_ID, OCOTP_GET_STATUS_ID, OCOTP_E_PARAM_POINTER);
    }
    else
    {
#else
    (void)HwIndex;
#endif /* OCOTP_DEV_ERROR_DETECT == STD_ON */
        Ocotp_IPW_GetStatus(Ocotp_pConfigPtr->pHwConfig, pStatus);
        eRetVal = (Std_ReturnType)E_OK;
#if(OCOTP_DEV_ERROR_DETECT == STD_ON)
    }
#endif /* OCOTP_DEV_ERROR_DETECT == STD_ON */
    return eRetVal;
}
#endif /* OCOTP_GET_STATUS_API == STD_ON */

#define OCOTP_STOP_SEC_CODE
#include "Ocotp_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */
