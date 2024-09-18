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
*   @file
*
*   @addtogroup OCOTP
*   @{
*/

#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
                                         INCLUDE FILES
 1) system and project includes
 2) needed interfaces from external units
 3) internal and external interfaces from this unit
==================================================================================================*/
#include "CDD_Ocotp.h"
#include "Ocotp_IPW.h"
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define OCOTP_IPW_VENDOR_ID_C                           43
#define OCOTP_IPW_AR_RELEASE_MAJOR_VERSION_C            4
#define OCOTP_IPW_AR_RELEASE_MINOR_VERSION_C            7
#define OCOTP_IPW_AR_RELEASE_REVISION_VERSION_C         0
#define OCOTP_IPW_SW_MAJOR_VERSION_C                    3
#define OCOTP_IPW_SW_MINOR_VERSION_C                    0
#define OCOTP_IPW_SW_PATCH_VERSION_C                    0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and CDD_Ocotp.h header file are of the same vendor */
#if (OCOTP_IPW_VENDOR_ID_C != CDD_OCOTP_VENDOR_ID)
    #error "Ocotp_IPW.c and CDD_Ocotp.h have different vendor ids"
#endif
/* Check if current file and CDD_Ocotp.h header file are of the same AutoSar version */
#if ((OCOTP_IPW_AR_RELEASE_MAJOR_VERSION_C != CDD_OCOTP_AR_RELEASE_MAJOR_VERSION ) || \
     (OCOTP_IPW_AR_RELEASE_MINOR_VERSION_C != CDD_OCOTP_AR_RELEASE_MINOR_VERSION ) || \
     (OCOTP_IPW_AR_RELEASE_REVISION_VERSION_C != CDD_OCOTP_AR_RELEASE_REVISION_VERSION) \
    )
    #error "Software Version Numbers of Ocotp_IPW.c and CDD_Ocotp.h are different"
#endif
/* Check if current file and CDD_Ocotp.h header file are of the same Software version */
#if ((OCOTP_IPW_SW_MAJOR_VERSION_C != CDD_OCOTP_SW_MAJOR_VERSION) || \
     (OCOTP_IPW_SW_MINOR_VERSION_C != CDD_OCOTP_SW_MINOR_VERSION) || \
     (OCOTP_IPW_SW_PATCH_VERSION_C != CDD_OCOTP_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Ocotp_IPW.c and CDD_Ocotp.h are different"
#endif

/* Check if current file and Ocotp_IPW.h header file are of the same vendor */
#if (OCOTP_IPW_VENDOR_ID_C != OCOTP_IPW_VENDOR_ID)
    #error "Ocotp_IPW.c and Ocotp_IPW.h have different vendor ids"
#endif
/* Check if current file and Ocotp_IPW.h header file are of the same AutoSar version */
#if ((OCOTP_IPW_AR_RELEASE_MAJOR_VERSION_C != OCOTP_IPW_AR_RELEASE_MAJOR_VERSION ) || \
     (OCOTP_IPW_AR_RELEASE_MINOR_VERSION_C != OCOTP_IPW_AR_RELEASE_MINOR_VERSION ) || \
     (OCOTP_IPW_AR_RELEASE_REVISION_VERSION_C != OCOTP_IPW_AR_RELEASE_REVISION_VERSION) \
    )
    #error "Software Version Numbers of Ocotp_IPW.c and Ocotp_IPW.h are different"
#endif
/* Check if current file and Ocotp_IPW.h header file are of the same Software version */
#if ((OCOTP_IPW_SW_MAJOR_VERSION_C != OCOTP_IPW_SW_MAJOR_VERSION) || \
     (OCOTP_IPW_SW_MINOR_VERSION_C != OCOTP_IPW_SW_MINOR_VERSION) || \
     (OCOTP_IPW_SW_PATCH_VERSION_C != OCOTP_IPW_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Ocotp_IPW.c and Ocotp_IPW.h are different"
#endif

/*==================================================================================================
*                           LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
*                                          LOCAL MACROS
==================================================================================================*/

/*==================================================================================================
                                       LOCAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
                                       LOCAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                        GLOBAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
                                       GLOBAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                    LOCAL FUNCTION PROTOTYPES
==================================================================================================*/

/*==================================================================================================
                                       LOCAL FUNCTIONS
==================================================================================================*/

/*==================================================================================================
*                                        GLOBAL FUNCTIONS
==================================================================================================*/
#define OCOTP_START_SEC_CODE
#include "Ocotp_MemMap.h"

/**
* @brief         The function initializes Mem_Otp_Ip module
* @details       The function initializes Mem_Otp_Ip module
*
* @param[in]     pConfig pointer points to configuration structure.
*/
void Ocotp_IPW_Init(const Ocotp_ConfigType * pConfig)
{
    /* Call Mem_Otp_Ip_Init to initialize Ocotp Module */
    Mem_Otp_Ip_Init(pConfig->pHwConfig);
    return;
}

/************************/

void Ocotp_IPW_Deinit(void)
{
    /* Call Mem_Otp_Ip_DeInit to de-initialize Ocotp Module */
    Mem_Otp_Ip_DeInit(Ocotp_pConfigPtr->pHwConfig->ocotpInstance);
    return;
}

#if (OCOTP_WRITE_MIRROR_API == STD_ON)
Mem_Otp_Ip_StatusType Ocotp_IPW_WriteMirrorRegister
(
    const Ocotp_ChannelConfigType* pChannelCfg,
    uint32 data
)
{
    Mem_Otp_Ip_StatusType eRetVal;
    /* Call Mem_Otp_Ip_WriteMirrorRegister to write data to the mirror register */
    eRetVal = Mem_Otp_Ip_WriteMirrorRegister(pChannelCfg->Ocotp_Instance, pChannelCfg->Ocotp_MirrorAddress, data);

    return eRetVal;
}
#endif /* OCOTP_WRITE_MIRROR_API == STD_ON */

#if (OCOTP_READ_EFUSE_API == STD_ON)
Mem_Otp_Ip_StatusType Ocotp_IPW_ReadEFuse
(
    const Ocotp_ChannelConfigType* pChannelCfg,
    uint32 *data
)
{
    Mem_Otp_Ip_StatusType eRetVal;

    /* Call Mem_Otp_Ip_ReadOTPMem to read data from the Mem Otp */
    eRetVal = Mem_Otp_Ip_ReadOTPMem(pChannelCfg->Ocotp_Instance, pChannelCfg->Ocotp_MirrorAddress, data);

    return eRetVal;
}
#endif /* OCOTP_READ_EFUSE_API == STD_ON */

#if (OCOTP_READ_MIRROR_API == STD_ON)
Mem_Otp_Ip_StatusType Ocotp_IPW_ReadMirrorRegister
(
    const Ocotp_ChannelConfigType* pChannelCfg,
    uint32 *data
)
{
    Mem_Otp_Ip_StatusType eRetVal;

    /* Call Mem_Otp_Ip_ReadMirrorRegister to read data from the mirror register */
    eRetVal = Mem_Otp_Ip_ReadMirrorRegister(pChannelCfg->Ocotp_Instance, pChannelCfg->Ocotp_MirrorAddress, data);

    return eRetVal;
}
#endif /* OCOTP_READ_MIRROR_API == STD_ON */

#if (OCOTP_GET_STATUS_API == STD_ON)
void Ocotp_IPW_GetStatus
(
    const Mem_Otp_Ip_ConfigType* pHwCfg,
    Ocotp_StatusType* pStatus
)
{
    Mem_Otp_Ip_StatusType eStatus;
    /* Get status of IP */
    eStatus = Mem_Otp_Ip_GetBusyState(pHwCfg->ocotpInstance);
    if(STATUS_MEM_OTP_IP_BUSY == eStatus)
    {
        pStatus->HardwareStatus = OCOTP_HARDWARE_BUSY;
    }
    else if(STATUS_MEM_OTP_IP_ERROR == eStatus)
    {
        pStatus->HardwareStatus = OCOTP_HARDWARE_ERROR;
    }
    else
    {
        pStatus->HardwareStatus = OCOTP_HARDWARE_IDLE;
    }
    return;
}
#endif /* OCOTP_GET_STATUS_API == STD_ON */

#define OCOTP_STOP_SEC_CODE
#include "Ocotp_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */
