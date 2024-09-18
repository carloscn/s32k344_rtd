
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

#ifndef CDD_OCOTP_H_
#define CDD_OCOTP_H_

/**
*   @file
*
*   @addtogroup OCOTP
*   @{
*/

#ifdef __cplusplus
extern "C"
{
#endif

/*==================================================================================================
*                                          INCLUDE FILES
*  1) system and project includes
*  2) needed interfaces from external units
*  3) internal and external interfaces from this unit
==================================================================================================*/

#include "Ocotp_Cfg.h"
#include "Ocotp_Types.h"
#include "Ocotp_IPW.h"

/*==================================================================================================
*                                SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define CDD_OCOTP_VENDOR_ID                    43
#define CDD_OCOTP_AR_RELEASE_MAJOR_VERSION     4
#define CDD_OCOTP_AR_RELEASE_MINOR_VERSION     7
#define CDD_OCOTP_AR_RELEASE_REVISION_VERSION  0
#define CDD_OCOTP_SW_MAJOR_VERSION             3
#define CDD_OCOTP_SW_MINOR_VERSION             0
#define CDD_OCOTP_SW_PATCH_VERSION             0
/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and Ocotp_Cfg.h header file are of the same vendor */
#if (CDD_OCOTP_VENDOR_ID != OCOTP_VENDOR_ID_CFG)
    #error "CDD_Ocotp.h and Ocotp_Cfg.h have different vendor ids"
#endif
/* Check if current file and Ocotp_Cfg.h header file are of the same AutoSar version */
#if ((CDD_OCOTP_AR_RELEASE_MAJOR_VERSION != OCOTP_AR_RELEASE_MAJOR_VERSION_CFG ) || \
     (CDD_OCOTP_AR_RELEASE_MINOR_VERSION != OCOTP_AR_RELEASE_MINOR_VERSION_CFG ) || \
     (CDD_OCOTP_AR_RELEASE_REVISION_VERSION != OCOTP_AR_RELEASE_REVISION_VERSION_CFG) \
    )
    #error "Software Version Numbers of CDD_Ocotp.h and Ocotp_Cfg.h are different"
#endif
/* Check if current file and Ocotp_Cfg.h header file are of the same Software version */
#if ((CDD_OCOTP_SW_MAJOR_VERSION != OCOTP_SW_MAJOR_VERSION_CFG) || \
     (CDD_OCOTP_SW_MINOR_VERSION != OCOTP_SW_MINOR_VERSION_CFG) || \
     (CDD_OCOTP_SW_PATCH_VERSION != OCOTP_SW_PATCH_VERSION_CFG) \
    )
    #error "Software Version Numbers of CDD_Ocotp.h and Ocotp_Cfg.h are different"
#endif

/* Check if current file and Ocotp_Types.h header file are of the same vendor */
#if (CDD_OCOTP_VENDOR_ID != OCOTP_TYPES_VENDOR_ID)
    #error "CDD_Ocotp.h and Ocotp_Types.h have different vendor ids"
#endif
/* Check if current file and Ocotp_Types.h header file are of the same AutoSar version */
#if ((CDD_OCOTP_AR_RELEASE_MAJOR_VERSION != OCOTP_TYPES_AR_RELEASE_MAJOR_VERSION ) || \
     (CDD_OCOTP_AR_RELEASE_MINOR_VERSION != OCOTP_TYPES_AR_RELEASE_MINOR_VERSION ) || \
     (CDD_OCOTP_AR_RELEASE_REVISION_VERSION != OCOTP_TYPES_AR_RELEASE_REVISION_VERSION) \
    )
    #error "Software Version Numbers of CDD_Ocotp.h and Ocotp_Types.h are different"
#endif
/* Check if current file and Ocotp_Types.h header file are of the same Software version */
#if ((CDD_OCOTP_SW_MAJOR_VERSION != OCOTP_TYPES_SW_MAJOR_VERSION) || \
     (CDD_OCOTP_SW_MINOR_VERSION != OCOTP_TYPES_SW_MINOR_VERSION) || \
     (CDD_OCOTP_SW_PATCH_VERSION != OCOTP_TYPES_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of CDD_Ocotp.h and Ocotp_Types.h are different"
#endif

/* Check if current file and Ocotp_IPW.h header file are of the same vendor */
#if (CDD_OCOTP_VENDOR_ID != OCOTP_IPW_VENDOR_ID)
    #error "CDD_Ocotp.h and Ocotp_IPW.h have different vendor ids"
#endif
/* Check if current file and Ocotp_IPW.h header file are of the same AutoSar version */
#if ((CDD_OCOTP_AR_RELEASE_MAJOR_VERSION != OCOTP_IPW_AR_RELEASE_MAJOR_VERSION ) || \
     (CDD_OCOTP_AR_RELEASE_MINOR_VERSION != OCOTP_IPW_AR_RELEASE_MINOR_VERSION ) || \
     (CDD_OCOTP_AR_RELEASE_REVISION_VERSION != OCOTP_IPW_AR_RELEASE_REVISION_VERSION) \
    )
    #error "Software Version Numbers of CDD_Ocotp.h and Ocotp_IPW.h are different"
#endif
/* Check if current file and Ocotp_IPW.h header file are of the same Software version */
#if ((CDD_OCOTP_SW_MAJOR_VERSION != OCOTP_IPW_SW_MAJOR_VERSION) || \
     (CDD_OCOTP_SW_MINOR_VERSION != OCOTP_IPW_SW_MINOR_VERSION) || \
     (CDD_OCOTP_SW_PATCH_VERSION != OCOTP_IPW_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of CDD_Ocotp.h and Ocotp_IPW.h are different"
#endif
/*==================================================================================================
*                                            CONSTANTS
==================================================================================================*/
#define OCOTP_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Ocotp_MemMap.h"
OCOTP_CONFIG_EXT
#define OCOTP_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Ocotp_MemMap.h"

#ifdef OCOTP_PRECOMPILE_SUPPORT
#define OCOTP_START_SEC_CONFIG_DATA_UNSPECIFIED
/* @violates @ref Ocotp_Cfg_h_REF_1 Precautions shall be taken in order to prevent the contents of a header file being included more than once */
#include "Ocotp_MemMap.h"

extern const Ocotp_ConfigType Ocotp_Config;

#define OCOTP_STOP_SEC_CONFIG_DATA_UNSPECIFIED
/* @violates @ref Ocotp_Cfg_h_REF_1 Precautions shall be taken in order to prevent the contents of a header file being included more than once */
#include "Ocotp_MemMap.h"
#endif
/*==================================================================================================
*                                        DEFINES AND MACROS
==================================================================================================*/
/**
* @brief          ID of module and instance.
*/
#define OCOTP_MODULE_ID                255U          /*!< Ocotp module ID */
#define OCOTP_INSTANCE_ID              0U            /*!< Ocotp instance ID */

/**
* @brief          Invalid value of index and address.
*/
#define OCOTP_INVALID_INDEX            0xFFU         /*!< Ocotp invalid index ID */
#define OCOTP_INVALID_ADDRESS          0xFFFFFFFFU   /*!< Ocotp invalid address ID */

/**
* @brief          Development error codes (passed to DET).
* @implements     Ocotp_ErrorCodes_define
*/
#define OCOTP_E_PARAM_CONFIG           0x01U /*!< API service called with wrong parameter */
#define OCOTP_E_PARAM_LENGTH           0x02U /*!< API service called with wrong parameter */
#define OCOTP_E_PARAM_POINTER          0x03U /*!< API service called with invalid pointer */
#define OCOTP_E_PARAM_CHANNEL          0x04U /*!< API service used with an invalid channel identifier or channel was not configured for the functionality of the calling API */
#define OCOTP_E_PARAM_INSTANCE         0x05U /*!< API service used with an invalid hardware unit identifier or hardware unit was not configured for the functionality of the calling API */
#define OCOTP_E_PARAM_MODE             0x06U /*!< API service called with wrong parameter */
#define OCOTP_E_UNINIT                 0x07U /*!< API service called without module initialization */
#define OCOTP_E_ALREADY_INITIALIZED    0x08U /*!< Ocotp_init service called module initialization */
#define OCOTP_E_BUSY                   0x09U /*!< API service called while driver still busy */

/**
* @brief          Runtime error codes (passed to DET).
*/
#define OCOTP_E_TIMEOUT                0x0CU /*!< Timeout exceeded */
/**
 *
* @brief          Transient Faults codes (passed to DET).
*
*/
#define OCOTP_E_WRITE_FAILED           0x0AU /*!< Ocotp write failed (HW) */
#define OCOTP_E_READ_FAILED            0x0BU /*!< Ocotp read failed (HW) */

/**
* @brief          All service IDs (passed to DET).
*/
#define OCOTP_INIT_ID                              0x00U   /*!< Service ID of Ocotp_Init function */
#define OCOTP_DEINIT_ID                            0x01U   /*!< Service ID of Ocotp_Deinit function */
#define OCOTP_READ_EFUSE_ID                        0x04U   /*!< Service ID of Ocotp_ReadEFuse function */
#define OCOTP_WRITE_MIRROR_REGISTER_ID             0x10U   /*!< Service ID of Ocotp_WriteMirrorRegister function */
#define OCOTP_READ_MIRROR_REGISTER_ID              0x11U   /*!< Service ID of Ocotp_ReadMirrorRegister function */
#define OCOTP_GET_STATUS_ID                        0x0DU   /*!< Service ID of Ocotp_GetStatus function */

/*==================================================================================================
*                                              ENUMS
==================================================================================================*/

/*==================================================================================================
*                                  STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
*                                  GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/
#define OCOTP_START_SEC_VAR_CLEARED_UNSPECIFIED_NO_CACHEABLE
#include "Ocotp_MemMap.h"

extern const Ocotp_ConfigType *Ocotp_pConfigPtr;

#define OCOTP_STOP_SEC_VAR_CLEARED_UNSPECIFIED_NO_CACHEABLE
#include "Ocotp_MemMap.h"
/*==================================================================================================
*                                      FUNCTION PROTOTYPES
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
 */
void Ocotp_Init(const Ocotp_ConfigType * const ConfigPtr);

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
 */
void Ocotp_Deinit(void);


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
 */
Std_ReturnType Ocotp_ReadEFuse
(
    Ocotp_ChannelType eFuseChannel,
    uint32* pData
);
#endif /* OCOTP_READ_EFUSE_API == STD_ON */


#if (OCOTP_READ_MIRROR_API == STD_ON)
/**
 * @brief        The function reads data from the mirror.
 * @details      The function reads the data from the mirror which was
 *               configured by configuration tool.
 *
 * @param[in]    eFuseChannel        Channel of eFuse such as 0, 1, 2 which was configured by user.
 * @param[in]    data                pointer points to the data read from mirror word.
 *
 * @return       Std_ReturnType
 * @retval       E_OK                    Read operation is successful.
 * @retval       E_NOT_OK                Read operation failed.
 *
 * @api
 *
 * @pre          Ocotp_pConfigPtr must not be NULL_PTR.
 *
 */
Std_ReturnType Ocotp_ReadMirrorRegister
(
    Ocotp_ChannelType eFuseChannel,
    uint32* pData
);
#endif /* OCOTP_READ_MIRROR_API == STD_ON */

#if (OCOTP_WRITE_MIRROR_API == STD_ON)
/**
 * @brief        The function writes data to Mirror register.
 * @details      The function writes the data to the Mirror register
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
 */
Std_ReturnType Ocotp_WriteMirrorRegister
(
    Ocotp_ChannelType eFuseChannel,
    uint32 data
);
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
 */
Std_ReturnType Ocotp_GetStatus
(
    uint8 HwIndex,
    Ocotp_StatusType* pStatus
);
#endif /* OCOTP_GET_STATUS_API == STD_ON */


#define OCOTP_STOP_SEC_CODE
#include "Ocotp_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */

#endif  /* Ocotp_H */
