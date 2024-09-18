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

#ifndef MEM_OTP_IP_CFG_H
#define MEM_OTP_IP_CFG_H

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
#include "[!"ecu:get('Ocotp.Header')"!]"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define MEM_OTP_IP_VENDOR_ID_CFG                    43
#define MEM_OTP_IP_AR_RELEASE_MAJOR_VERSION_CFG     4
#define MEM_OTP_IP_AR_RELEASE_MINOR_VERSION_CFG     7
#define MEM_OTP_IP_AR_RELEASE_REVISION_VERSION_CFG  0
#define MEM_OTP_IP_SW_MAJOR_VERSION_CFG             3
#define MEM_OTP_IP_SW_MINOR_VERSION_CFG             0
#define MEM_OTP_IP_SW_PATCH_VERSION_CFG             0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and Mem_Otp_Ip_Types header file are of the same vendor */
#if (MEM_OTP_IP_VENDOR_ID_CFG != MEM_OTP_IP_TYPES_VENDOR_ID)
    #error "Mem_Otp_Ip_Cfg.h and Mem_Otp_Ip_Types.h have different vendor ids"
#endif
/* Check if current file and Mem_Otp_Ip_Types header file are of the same Autosar version */
#if ((MEM_OTP_IP_AR_RELEASE_MAJOR_VERSION_CFG    != MEM_OTP_IP_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (MEM_OTP_IP_AR_RELEASE_MINOR_VERSION_CFG    != MEM_OTP_IP_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (MEM_OTP_IP_AR_RELEASE_REVISION_VERSION_CFG != MEM_OTP_IP_TYPES_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Mem_Otp_Ip_Cfg.h and Mem_Otp_Ip_Types.h are different"
#endif
/* Check if current file and Mem_Otp_Ip_Types header file are of the same Software version */
#if ((MEM_OTP_IP_SW_MAJOR_VERSION_CFG != MEM_OTP_IP_TYPES_SW_MAJOR_VERSION) || \
     (MEM_OTP_IP_SW_MINOR_VERSION_CFG != MEM_OTP_IP_TYPES_SW_MINOR_VERSION) || \
     (MEM_OTP_IP_SW_PATCH_VERSION_CFG != MEM_OTP_IP_TYPES_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Mem_Otp_Ip_Cfg.h and Mem_Otp_Ip_Types.h are different"
#endif

/*==================================================================================================
*                                            CONSTANTS
==================================================================================================*/
[!NOCODE!]
[!IF "var:defined('postBuildVariant')"!]
    [!LOOP "variant:all()"!]
        [!CODE!]
/* Ocotp Hardware ConfigSet */
extern const Mem_Otp_Ip_ConfigType Ocotp_ConfigSet_[!"."!]_pHwConfig;
        [!ENDCODE!]
    [!ENDLOOP!]
[!ELSE!]
    [!CODE!]
/* Ocotp Hardware ConfigSet */
extern const Mem_Otp_Ip_ConfigType Ocotp_ConfigSet_pHwConfig;
    [!ENDCODE!]
[!ENDIF!]
[!ENDNOCODE!]
/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/
#define MEM_OTP_IP_DEV_ERROR_DETECT                     ([!IF "OcotpGeneral/OcotpIpDevErrorDetect"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

#define MEM_OTP_IP_WRITE_MIRROR_API                     ([!IF "OcotpGeneral/OcotpWriteMirrorRegisterApi"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])
#define MEM_OTP_IP_WRITE_MIRROR_WITH_COMMAND            ([!IF "OcotpGeneral/OcotpWriteMirrorWithCommand"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])
#define MEM_OTP_IP_READ_MIRROR_API                      ([!IF "OcotpGeneral/OcotpReadMirrorRegisterApi"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])
#define MEM_OTP_IP_READ_MIRROR_WITH_COMMAND             ([!IF "OcotpGeneral/OcotpReadMirrorWithCommand"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])
#define MEM_OTP_IP_READ_OTP_MEM_API                     ([!IF "OcotpGeneral/OcotpReadEFuseApi"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])
#define MEM_OTP_IP_TIMEOUT_TYPE                         ([!"node:value(OcotpGeneral/OcotpTimeoutMethod)"!])

/* OCOTP timeout value */
#define MEM_OTP_IP_WRITE_TIMEOUT_VALUE                  [!"num:i(OcotpGeneral/OcotpWriteTimeout)"!]U
#define MEM_OTP_IP_READ_TIMEOUT_VALUE                   [!"num:i(OcotpGeneral/OcotpReadTimeout)"!]U

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

[!ENDINDENT!][!//

#ifdef __cplusplus
}
#endif

/** @} */

#endif /* MEM_OTP_IP_CFG_H */
