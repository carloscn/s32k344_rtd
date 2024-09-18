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
*
*   NXP Confidential. This software is owned or controlled by NXP and may only be
*   used strictly in accordance with the applicable license terms. By expressly
*   accepting such terms or by downloading, installing, activating and/or otherwise
*   using the software, you are agreeing that you have read, and that you agree to
*   comply with and are bound by, such license terms. If you do not agree to be
*   bound by the applicable license terms, then you may not retain, install,
*   activate or otherwise use the software.
==================================================================================================*/

#ifndef MEM_OTP_IP_H
#define MEM_OTP_IP_H

/**
*   @file
*
*   @addtogroup MEM_OTP_IP
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
#include "Mem_Otp_Ip_Cfg.h"
#include "Mem_Otp_Ip_Types.h"
#include "Mem_Otp_Ip_Defines.h"
#include "Aec_Ip.h"
#include "Devassert.h"
#include "OsIf.h"
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define MEM_OTP_IP_VENDOR_ID                    43
#define MEM_OTP_IP_AR_RELEASE_MAJOR_VERSION     4
#define MEM_OTP_IP_AR_RELEASE_MINOR_VERSION     7
#define MEM_OTP_IP_AR_RELEASE_REVISION_VERSION  0
#define MEM_OTP_IP_SW_MAJOR_VERSION             3
#define MEM_OTP_IP_SW_MINOR_VERSION             0
#define MEM_OTP_IP_SW_PATCH_VERSION             0
/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and Mem_Otp_Ip_Cfg header file are of the same vendor */
#if (MEM_OTP_IP_VENDOR_ID != MEM_OTP_IP_VENDOR_ID_CFG)
    #error "Mem_Otp_Ip.h and Mem_Otp_Ip_Cfg.h have different vendor ids"
#endif
/* Check if current file and Mem_Otp_Ip_Cfg header file are of the same Autosar version */
#if ((MEM_OTP_IP_AR_RELEASE_MAJOR_VERSION    != MEM_OTP_IP_AR_RELEASE_MAJOR_VERSION_CFG) || \
     (MEM_OTP_IP_AR_RELEASE_MINOR_VERSION    != MEM_OTP_IP_AR_RELEASE_MINOR_VERSION_CFG) || \
     (MEM_OTP_IP_AR_RELEASE_REVISION_VERSION != MEM_OTP_IP_AR_RELEASE_REVISION_VERSION_CFG) \
    )
    #error "AutoSar Version Numbers of Mem_Otp_Ip.h and Mem_Otp_Ip_Cfg.h are different"
#endif
/* Check if current file and Mem_Otp_Ip_Cfg header file are of the same Software version */
#if ((MEM_OTP_IP_SW_MAJOR_VERSION != MEM_OTP_IP_SW_MAJOR_VERSION_CFG) || \
     (MEM_OTP_IP_SW_MINOR_VERSION != MEM_OTP_IP_SW_MINOR_VERSION_CFG) || \
     (MEM_OTP_IP_SW_PATCH_VERSION != MEM_OTP_IP_SW_PATCH_VERSION_CFG) \
    )
    #error "Software Version Numbers of Mem_Otp_Ip.h and Mem_Otp_Ip_Cfg.h are different"
#endif

/* Check if current file and Mem_Otp_Ip_Type header file are of the same vendor */
#if (MEM_OTP_IP_VENDOR_ID != MEM_OTP_IP_TYPES_VENDOR_ID)
    #error "Mem_Otp_Ip.h and Mem_Otp_Ip_Types.h have different vendor ids"
#endif
/* Check if current file and Mem_Otp_Ip_Type header file are of the same Autosar version */
#if ((MEM_OTP_IP_AR_RELEASE_MAJOR_VERSION    != MEM_OTP_IP_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (MEM_OTP_IP_AR_RELEASE_MINOR_VERSION    != MEM_OTP_IP_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (MEM_OTP_IP_AR_RELEASE_REVISION_VERSION != MEM_OTP_IP_TYPES_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Mem_Otp_Ip.h and Mem_Otp_Ip_Types.h are different"
#endif
/* Check if current file and Mem_Otp_Ip_Type header file are of the same Software version */
#if ((MEM_OTP_IP_SW_MAJOR_VERSION != MEM_OTP_IP_TYPES_SW_MAJOR_VERSION) || \
     (MEM_OTP_IP_SW_MINOR_VERSION != MEM_OTP_IP_TYPES_SW_MINOR_VERSION) || \
     (MEM_OTP_IP_SW_PATCH_VERSION != MEM_OTP_IP_TYPES_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Mem_Otp_Ip.h and Ocotp_Types.h are different"
#endif

/* Check if current file and Mem_Otp_Ip_Defines header file are of the same vendor */
#if (MEM_OTP_IP_VENDOR_ID != MEM_OTP_IP_DEFINES_VENDOR_ID)
    #error "Mem_Otp_Ip.h and Mem_Otp_Ip_Defines.h have different vendor ids"
#endif
/* Check if current file and Mem_Otp_Ip_Defines header file are of the same Autosar version */
#if ((MEM_OTP_IP_AR_RELEASE_MAJOR_VERSION    != MEM_OTP_IP_DEFINES_AR_RELEASE_MAJOR_VERSION) || \
     (MEM_OTP_IP_AR_RELEASE_MINOR_VERSION    != MEM_OTP_IP_DEFINES_AR_RELEASE_MINOR_VERSION) || \
     (MEM_OTP_IP_AR_RELEASE_REVISION_VERSION != MEM_OTP_IP_DEFINES_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Mem_Otp_Ip.h and Mem_Otp_Ip_Defines.h are different"
#endif
/* Check if current file and Mem_Otp_Ip_Defines header file are of the same Software version */
#if ((MEM_OTP_IP_SW_MAJOR_VERSION != MEM_OTP_IP_DEFINES_SW_MAJOR_VERSION) || \
     (MEM_OTP_IP_SW_MINOR_VERSION != MEM_OTP_IP_DEFINES_SW_MINOR_VERSION) || \
     (MEM_OTP_IP_SW_PATCH_VERSION != MEM_OTP_IP_DEFINES_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Mem_Otp_Ip.h and Mem_Otp_Ip_Defines.h are different"
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if current file and Devassert header file are of the same Autosar version */
    #if ((MEM_OTP_IP_AR_RELEASE_MAJOR_VERSION != DEVASSERT_AR_RELEASE_MAJOR_VERSION) || \
         (MEM_OTP_IP_AR_RELEASE_MINOR_VERSION != DEVASSERT_AR_RELEASE_MINOR_VERSION) \
        )
        #error "AutoSar Version Numbers of Mem_Otp_Ip.h and Devassert.h are different"
    #endif

        /* Check if current file and OsIf header file are of the same Autosar version */
    #if ((MEM_OTP_IP_AR_RELEASE_MAJOR_VERSION != OSIF_AR_RELEASE_MAJOR_VERSION) || \
         (MEM_OTP_IP_AR_RELEASE_MINOR_VERSION != OSIF_AR_RELEASE_MINOR_VERSION) \
        )
        #error "AutoSar Version Numbers of Mem_Otp_Ip.h and OsIf.h are different"
    #endif
#endif

/*==================================================================================================
*                                            CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/

#if (MEM_OTP_IP_DEV_ERROR_DETECT == STD_ON)
#define     DEV_ASSERT_OCOTP(x)   DevAssert(x)
#else
#define     DEV_ASSERT_OCOTP(x)   (void)x;
#endif

/*==================================================================================================
*                                              ENUMS
==================================================================================================*/

/*==================================================================================================
*                                  STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
*                                  GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                       FUNCTION PROTOTYPES
==================================================================================================*/

#define OCOTP_START_SEC_CODE
#include "Ocotp_MemMap.h"

/**
 * @brief        The function initializes Mem_Otp_Ip module.
 * @details      The function clear all errors flag and initializes Mem_Otp_Ip module.
 *
 * @param[in]    pConfig       pointer points to configuration structure.
 *
 * @api
 *
 * @pre          Module has been initialized.
 *
 */
void Mem_Otp_Ip_Init(const Mem_Otp_Ip_ConfigType *pConfig);

/**
 * @brief        The function de-initializes Mem_Otp_Ip module.
 * @details      The function de-initializes Mem_Otp_Ip module.
 *
 * @param[in]    instance       hardware instance.
 *
 * @api
 *
 * @pre          Module has been initialized.
 *
 */
void Mem_Otp_Ip_DeInit(uint32 instance);

#if (MEM_OTP_IP_WRITE_MIRROR_API == STD_ON)
/**
 * @brief        The function write data in a specified mirror register.
 * @details      The function write data in a specified mirror register with an OTPC command or direct register access.
 *
 * @param[in]    instance       hardware instance.
 * @param[in]    address        address of mirror.
 * @param[in]    data           data to be written.
 *
 * @return       Mem_Otp_Ip_StatusType
 * @retval       STATUS_MEM_OTP_IP_SUCCESS if write operation is successful.
 * @retval       STATUS_MEM_OTP_IP_ERROR if error flag is set.
 * @retval       STATUS_MEM_OTP_IP_BUSY hardware is busy.
 *
 * @api
 *
 * @pre          Module has been initialized.
 *
 */
Mem_Otp_Ip_StatusType Mem_Otp_Ip_WriteMirrorRegister
(
    uint32 instance,
    uint32 address,
    uint32 data
);
#endif /* MEM_OTP_IP_WRITE_MIRROR_API == STD_ON */

#if (MEM_OTP_IP_READ_MIRROR_API == STD_ON)
/**
 * @brief        The function reads data in a specified mirror register.
 * @details      The function reads data in a specified mirror register with an OTPC command or direct register access.
 *
 * @param[in]    instance       hardware instance.
 * @param[in]    address        address of mirror.
 * @param[out]   data           pointer points to data result.
 *
 * @return       Mem_Otp_Ip_StatusType
 * @retval       STATUS_MEM_OTP_IP_SUCCESS if read operation is successful.
 * @retval       STATUS_MEM_OTP_IP_ERROR if error flag is set.
 * @retval       STATUS_MEM_OTP_IP_BUSY hardware is busy.
 *
 * @api
 *
 * @pre          Module has been initialized.
 *
 */
Mem_Otp_Ip_StatusType Mem_Otp_Ip_ReadMirrorRegister
(
    uint32 instance,
    uint32 address,
    uint32* data
);
#endif /* MEM_OTP_IP_READ_MIRROR_API == STD_ON */

#if (MEM_OTP_IP_READ_OTP_MEM_API == STD_ON)
/**
 * @brief        The function reads a single byte of data from OTP memory.
 * @details      The function reads a single byte of data from OTP memory.
 *
 * @param[in]    instance       hardware instance.
 * @param[in]    address        address of OTP memory.
 * @param[out]    data           pointer points to data result.
 *
 * @return       Mem_Otp_Ip_StatusType
 * @retval       STATUS_MEM_OTP_IP_SUCCESS if read operation is successful.
 * @retval       STATUS_MEM_OTP_IP_ERROR if error flag is set.
 * @retval       STATUS_MEM_OTP_IP_BUSY hardware is busy.
 *
 * @api
 *
 * @pre          Module has been initialized.
 *
 */
Mem_Otp_Ip_StatusType Mem_Otp_Ip_ReadOTPMem
(
    uint32 instance,
    uint32 address,
    uint32 *data
);
#endif /* MEM_OTP_IP_READ_OTP_MEM_API == STD_ON */

/**
 * @brief        The function checks busy and error state of hardware.
 * @details      The function checks busy and error state of hardware.
 *
 * @param[in]    instance       hardware instance.
 *
 * @return       Mem_Otp_Ip_StatusType
 * @retval       STATUS_MEM_OTP_IP_SUCCESS if hardware is ready.
 * @retval       STATUS_MEM_OTP_IP_ERROR if error flag is set.
 * @retval       STATUS_MEM_OTP_IP_BUSY hardware is busy.
 *
 * @api
 *
 * @pre          Module has been initialized.
 *
 */
Mem_Otp_Ip_StatusType Mem_Otp_Ip_GetBusyState (uint32 instance);

#define OCOTP_STOP_SEC_CODE
#include "Ocotp_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */

#endif /* MEM_OTP_IP_H */
