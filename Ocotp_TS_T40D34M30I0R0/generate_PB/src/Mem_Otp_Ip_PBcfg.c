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
*   @addtogroup MEM_OTP_IP
*   @{
*/

#ifdef __cplusplus
extern "C"{
#endif

[!INDENT "0"!][!//
/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Mem_Otp_Ip_Types.h"
#include "Mem_Otp_Ip_Cfg.h"

[!ENDINDENT!][!//

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define MEM_OTP_IP_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]VENDOR_ID_CFG_C                      43
#define MEM_OTP_IP_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]AR_RELEASE_MAJOR_VERSION_CFG_C       4
#define MEM_OTP_IP_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]AR_RELEASE_MINOR_VERSION_CFG_C       7
#define MEM_OTP_IP_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]AR_RELEASE_REVISION_VERSION_CFG_C    0
#define MEM_OTP_IP_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]SW_MAJOR_VERSION_CFG_C               3
#define MEM_OTP_IP_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]SW_MINOR_VERSION_CFG_C               0
#define MEM_OTP_IP_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]SW_PATCH_VERSION_CFG_C               0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and Mem_Otp_Ip_Type header file are of the same vendor */
#if (MEM_OTP_IP_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]VENDOR_ID_CFG_C != MEM_OTP_IP_TYPES_VENDOR_ID)
    #error "Mem_Otp_Ip_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBcfg.c and Mem_Otp_Ip_Types.h have different vendor ids"
#endif
/* Check if current file and Mem_Otp_Ip_Type header file are of the same Autosar version */
#if ((MEM_OTP_IP_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]AR_RELEASE_MAJOR_VERSION_CFG_C    != MEM_OTP_IP_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (MEM_OTP_IP_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]AR_RELEASE_MINOR_VERSION_CFG_C    != MEM_OTP_IP_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (MEM_OTP_IP_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]AR_RELEASE_REVISION_VERSION_CFG_C != MEM_OTP_IP_TYPES_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Mem_Otp_Ip_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBcfg.c and Mem_Otp_Ip_Types.h are different"
#endif
/* Check if current file and Mem_Otp_Ip_Type header file are of the same Software version */
#if ((MEM_OTP_IP_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]SW_MAJOR_VERSION_CFG_C != MEM_OTP_IP_TYPES_SW_MAJOR_VERSION) || \
     (MEM_OTP_IP_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]SW_MINOR_VERSION_CFG_C != MEM_OTP_IP_TYPES_SW_MINOR_VERSION) || \
     (MEM_OTP_IP_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]SW_PATCH_VERSION_CFG_C != MEM_OTP_IP_TYPES_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Mem_Otp_Ip_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBcfg.c and Mem_Otp_Ip_Types.h are different"
#endif

/* Check if current file and Mem_Otp_Ip_Cfg header file are of the same vendor */
#if (MEM_OTP_IP_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]VENDOR_ID_CFG_C != MEM_OTP_IP_VENDOR_ID_CFG)
    #error "Mem_Otp_Ip_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBcfg.c and Mem_Otp_Ip_Cfg.h have different vendor ids"
#endif
/* Check if current file and Mem_Otp_Ip_Cfg header file are of the same Autosar version */
#if ((MEM_OTP_IP_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]AR_RELEASE_MAJOR_VERSION_CFG_C    != MEM_OTP_IP_AR_RELEASE_MAJOR_VERSION_CFG) || \
     (MEM_OTP_IP_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]AR_RELEASE_MINOR_VERSION_CFG_C    != MEM_OTP_IP_AR_RELEASE_MINOR_VERSION_CFG) || \
     (MEM_OTP_IP_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]AR_RELEASE_REVISION_VERSION_CFG_C != MEM_OTP_IP_AR_RELEASE_REVISION_VERSION_CFG) \
    )
    #error "AutoSar Version Numbers of Mem_Otp_Ip_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBcfg.c and Mem_Otp_Ip_Cfg.h are different"
#endif
/* Check if current file and Mem_Otp_Ip_Cfg header file are of the same Software version */
#if ((MEM_OTP_IP_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]SW_MAJOR_VERSION_CFG_C != MEM_OTP_IP_SW_MAJOR_VERSION_CFG) || \
     (MEM_OTP_IP_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]SW_MINOR_VERSION_CFG_C != MEM_OTP_IP_SW_MINOR_VERSION_CFG) || \
     (MEM_OTP_IP_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]SW_PATCH_VERSION_CFG_C != MEM_OTP_IP_SW_PATCH_VERSION_CFG) \
    )
    #error "Software Version Numbers of Mem_Otp_Ip_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBcfg.c and Mem_Otp_Ip_Cfg.h are different"
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
#define OCOTP_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Ocotp_MemMap.h"

const Mem_Otp_Ip_ConfigType Ocotp_ConfigSet[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_pHwConfig =
{
[!LOOP "node:order(OcotpConfigList/OcotpHwUnit/*,'node:value(./OcotpInstance)')"!][!//
    (Ocotp_InstanceType)[!"./OcotpInstance"!]U
[!ENDLOOP!][!//
};
#define OCOTP_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Ocotp_MemMap.h"
/*==================================================================================================
*                                        GLOBAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                    LOCAL FUNCTION PROTOTYPES
==================================================================================================*/

/*==================================================================================================
*                                         LOCAL FUNCTIONS
==================================================================================================*/

/*==================================================================================================
*                                        GLOBAL FUNCTIONS
==================================================================================================*/

#ifdef __cplusplus
}
#endif