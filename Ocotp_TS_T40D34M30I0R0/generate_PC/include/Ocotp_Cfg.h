
[!AUTOSPACING!]
[!CODE!][!//
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
*
*   NXP Confidential. This software is owned or controlled by NXP and may only be
*   used strictly in accordance with the applicable license terms. By expressly
*   accepting such terms or by downloading, installing, activating and/or otherwise
*   using the software, you are agreeing that you have read, and that you agree to
*   comply with and are bound by, such license terms. If you do not agree to be
*   bound by the applicable license terms, then you may not retain, install,
*   activate or otherwise use the software.
==================================================================================================*/
#ifndef OCOTP_CFG_H
#define OCOTP_CFG_H

/**
*   @file
*
*   @addtogroup OCOTP
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
#include "Mcal.h"
[!IF "var:defined('postBuildVariant')"!]
[!LOOP "variant:all()"!]
#include "Ocotp_[!"."!]_PBcfg.h"
[!ENDLOOP!]
[!ELSE!]
#include "Ocotp_PBcfg.h"
[!ENDIF!]
[!ENDINDENT!][!//
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define OCOTP_VENDOR_ID_CFG                    43
#define OCOTP_AR_RELEASE_MAJOR_VERSION_CFG     4
#define OCOTP_AR_RELEASE_MINOR_VERSION_CFG     7
#define OCOTP_AR_RELEASE_REVISION_VERSION_CFG  0
#define OCOTP_SW_MAJOR_VERSION_CFG             3
#define OCOTP_SW_MINOR_VERSION_CFG             0
#define OCOTP_SW_PATCH_VERSION_CFG             0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if current file and Std_Types header file are of the same version */
    #if ((OCOTP_AR_RELEASE_MAJOR_VERSION_CFG != MCAL_AR_RELEASE_MAJOR_VERSION) || \
         (OCOTP_AR_RELEASE_MINOR_VERSION_CFG != MCAL_AR_RELEASE_MINOR_VERSION)\
        )
        #error "AutoSar Version Numbers of Ocotp_Cfg.h and Mcal.h are different"
    #endif
#endif

[!IF "var:defined('postBuildVariant')"!]
[!LOOP "variant:all()"!]
/* Check if source file and Ocotp configuration header file are of the same vendor */
#if (OCOTP_[!"."!]_PBCFG_VENDOR_ID != OCOTP_VENDOR_ID_CFG)
 #error "Ocotp_Cfg.h and Ocotp_[!"."!]_PBcfg.h have different vendor IDs"
#endif
 /* Check if header file and Ocotp configuration header file are of the same Autosar version */
#if ((OCOTP_[!"."!]_PBCFG_AR_RELEASE_MAJOR_VERSION    != OCOTP_AR_RELEASE_MAJOR_VERSION_CFG) || \
     (OCOTP_[!"."!]_PBCFG_AR_RELEASE_MINOR_VERSION    != OCOTP_AR_RELEASE_MINOR_VERSION_CFG) || \
     (OCOTP_[!"."!]_PBCFG_AR_RELEASE_REVISION_VERSION != OCOTP_AR_RELEASE_REVISION_VERSION_CFG) \
    )
#error "AutoSar Version Numbers of Ocotp_Cfg.h and Ocotp_[!"."!]_PBcfg.h are different"
#endif
/* Check if header file and Ocotp configuration header file are of the same software version */
#if ((OCOTP_[!"."!]_PBCFG_SW_MAJOR_VERSION != OCOTP_SW_MAJOR_VERSION_CFG) || \
     (OCOTP_[!"."!]_PBCFG_SW_MINOR_VERSION != OCOTP_SW_MINOR_VERSION_CFG) || \
     (OCOTP_[!"."!]_PBCFG_SW_PATCH_VERSION != OCOTP_SW_PATCH_VERSION_CFG) \
    )
#error "Software Version Numbers of Ocotp_Cfg.h and Ocotp_[!"."!]_PBcfg.h are different"
#endif
[!ENDLOOP!]
[!ELSE!]
/* Check if source file and Ocotp configuration header file are of the same vendor */
#if (OCOTP_PBCFG_VENDOR_ID != OCOTP_VENDOR_ID_CFG)
 #error "Ocotp_Cfg.h and Ocotp_PBcfg.h have different vendor IDs"
#endif
 /* Check if header file and Ocotp configuration header file are of the same Autosar version */
#if ((OCOTP_PBCFG_AR_RELEASE_MAJOR_VERSION    != OCOTP_AR_RELEASE_MAJOR_VERSION_CFG) || \
     (OCOTP_PBCFG_AR_RELEASE_MINOR_VERSION    != OCOTP_AR_RELEASE_MINOR_VERSION_CFG) || \
     (OCOTP_PBCFG_AR_RELEASE_REVISION_VERSION != OCOTP_AR_RELEASE_REVISION_VERSION_CFG) \
    )
#error "AutoSar Version Numbers of Ocotp_Cfg.h and Ocotp_PBcfg.h are different"
#endif
/* Check if header file and Ocotp configuration header file are of the same software version */
#if ((OCOTP_PBCFG_SW_MAJOR_VERSION != OCOTP_SW_MAJOR_VERSION_CFG) || \
     (OCOTP_PBCFG_SW_MINOR_VERSION != OCOTP_SW_MINOR_VERSION_CFG) || \
     (OCOTP_PBCFG_SW_PATCH_VERSION != OCOTP_SW_PATCH_VERSION_CFG) \
    )
#error "Software Version Numbers of Ocotp_Cfg.h and Ocotp_PBcfg.h are different"
#endif
[!ENDIF!]

[!INCLUDE "Ocotp_VersionCheck.m"!][!//
/*==================================================================================================
                                           CONSTANTS
==================================================================================================*/


/*==================================================================================================
                                       DEFINES AND MACROS
==================================================================================================*/

#define OCOTP_CONFIG_EXT \
[!IF "var:defined('postBuildVariant')"!][!//
    [!VAR "variantIndex"="0"!][!//
    [!VAR "variantNumber"="variant:size()"!][!//
[!LOOP "variant:all()"!][!//
    [!VAR "variantIndex"="$variantIndex + 1"!][!//
    OCOTP_CONFIG_[!"."!]_PB[!IF "$variantIndex < $variantNumber"!] \[!CR!][!ENDIF!]
[!ENDLOOP!][!//
[!ELSE!][!//
    OCOTP_CONFIG_PB
[!ENDIF!]


[!LOOP "node:order(OcotpChannelList/OcotpChannel/*,'node:value(./OcotpChannelNumber)')"!]
#define OcotpConf_OcotpChannelConfiguration_[!"node:name(.)"!]     [!"./OcotpChannelNumber"!]U
[!ENDLOOP!][!//
[!//
[!LOOP "node:order(OcotpConfigList/OcotpHwUnit/*,'node:value(./OcotpHardwareIndex)')"!]
#define OcotpConf_OcotpHardwareConfiguration_[!"node:name(.)"!]     [!"./OcotpHardwareIndex"!]U
[!ENDLOOP!][!//

[!IF "IMPLEMENTATION_CONFIG_VARIANT='VariantPreCompile'"!][!//
[!IF "variant:size()<=1"!][!//
#define OCOTP_PRECOMPILE_SUPPORT

/* Declaration of pre-compile configuration set structure */
#define Ocotp_Config Ocotp_Config[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]

[!ENDIF!][!//
[!ENDIF!][!//

#define OCOTP_DEV_ERROR_DETECT                      ([!IF "OcotpGeneral/OcotpDevErrorDetect"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

#define OCOTP_NUMBER_INSTANCE_CONFIGURED            ([!"num:i(count(OcotpConfigList/OcotpHwUnit/*))"!]U)

#define OCOTP_NUMBER_CHANNEL_CONFIGURED             ([!"num:i(count(OcotpChannelList/OcotpChannel/*))"!]U)


#define OCOTP_READ_EFUSE_API                        ([!IF "OcotpGeneral/OcotpReadEFuseApi"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])


#define OCOTP_WRITE_MIRROR_API                      ([!IF "OcotpGeneral/OcotpWriteMirrorRegisterApi"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])
#define OCOTP_READ_MIRROR_API                       ([!IF "OcotpGeneral/OcotpReadMirrorRegisterApi"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

#define OCOTP_GET_STATUS_API                        ([!IF "OcotpGeneral/OcotpGetStatusApi"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])


[!ENDCODE!][!//

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

#ifdef __cplusplus
}
#endif

/** @} */

#endif /* OCOTP_CFG_H */

