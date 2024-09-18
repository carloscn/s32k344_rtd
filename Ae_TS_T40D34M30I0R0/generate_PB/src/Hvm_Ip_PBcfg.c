/*==================================================================================================
*   Project              : RTD AUTOSAR 4.7
*   Platform             : CORTEXM
*   Peripheral           : 
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

#ifndef HVM_IP_PBCFG_C
#define HVM_IP_PBCFG_C

/**
*   @file
*
*   @addtogroup HVM_DRIVER_CONFIGURATION HVM Driver Configuration
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
#include "Hvm_Ip_Types.h"
#include "Hvm_Ip_Cfg.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define HVM_IP_PBCFG[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_VENDOR_ID_C                     43
#define HVM_IP_PBCFG[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_AR_RELEASE_MAJOR_VERSION_C      4
#define HVM_IP_PBCFG[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_AR_RELEASE_MINOR_VERSION_C      7
#define HVM_IP_PBCFG[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_AR_RELEASE_REVISION_VERSION_C   0
#define HVM_IP_PBCFG[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_SW_MAJOR_VERSION_C              3
#define HVM_IP_PBCFG[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_SW_MINOR_VERSION_C              0
#define HVM_IP_PBCFG[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_SW_PATCH_VERSION_C              0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Checks against Hvm_Ip_Types.h */
#if (HVM_IP_PBCFG[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_VENDOR_ID_C != HVM_IP_TYPES_VENDOR_ID)
    #error "Hvm_Ip[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg.c and Hvm_Ip_Types.h have different vendor ids"
#endif
#if ((HVM_IP_PBCFG[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_AR_RELEASE_MAJOR_VERSION_C    != HVM_IP_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (HVM_IP_PBCFG[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_AR_RELEASE_MINOR_VERSION_C    != HVM_IP_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (HVM_IP_PBCFG[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_AR_RELEASE_REVISION_VERSION_C != HVM_IP_TYPES_AR_RELEASE_REVISION_VERSION))
     #error "AUTOSAR Version Numbers of Hvm_Ip[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg.c and Hvm_Ip_Types.h are different"
#endif
#if ((HVM_IP_PBCFG[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_SW_MAJOR_VERSION_C != HVM_IP_TYPES_SW_MAJOR_VERSION) || \
     (HVM_IP_PBCFG[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_SW_MINOR_VERSION_C != HVM_IP_TYPES_SW_MINOR_VERSION) || \
     (HVM_IP_PBCFG[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_SW_PATCH_VERSION_C != HVM_IP_TYPES_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Hvm_Ip[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg.c and Hvm_Ip_Types.h are different"
#endif

/* Checks against Hvm_Ip_Cfg.h */
#if (HVM_IP_PBCFG[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_VENDOR_ID_C != HVM_IP_CFG_VENDOR_ID)
    #error "Hvm_Ip[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg.c and Hvm_Ip_Cfg.h have different vendor ids"
#endif
#if ((HVM_IP_PBCFG[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_AR_RELEASE_MAJOR_VERSION_C    != HVM_IP_CFG_AR_RELEASE_MAJOR_VERSION) || \
     (HVM_IP_PBCFG[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_AR_RELEASE_MINOR_VERSION_C    != HVM_IP_CFG_AR_RELEASE_MINOR_VERSION) || \
     (HVM_IP_PBCFG[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_AR_RELEASE_REVISION_VERSION_C != HVM_IP_CFG_AR_RELEASE_REVISION_VERSION))
     #error "AUTOSAR Version Numbers of Hvm_Ip[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg.c and Hvm_Ip_Cfg.h are different"
#endif
#if ((HVM_IP_PBCFG[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_SW_MAJOR_VERSION_C != HVM_IP_CFG_SW_MAJOR_VERSION) || \
     (HVM_IP_PBCFG[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_SW_MINOR_VERSION_C != HVM_IP_CFG_SW_MINOR_VERSION) || \
     (HVM_IP_PBCFG[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_SW_PATCH_VERSION_C != HVM_IP_CFG_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Hvm_Ip[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg.c and Hvm_Ip_Cfg.h are different"
#endif

/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/

/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/

/*==================================================================================================
*                                      BUFFER DECLARATIONS
==================================================================================================*/


/*==================================================================================================
*                                   STATE STRUCTURE DECLARATIONS
==================================================================================================*/


/*==================================================================================================
*                                      LOCAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      LOCAL VARIABLES
==================================================================================================*/
#define AE_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Ae_MemMap.h"

[!NOCODE!]
[!SELECT "AeHvmHviConfig"!]
    [!VAR "NumOfHviInstances" = "num:i(count(AeHvmHviInstanceConfig/*))"!]
    [!IF "num:i($NumOfHviInstances) > 0"!]
[!CODE!]
static const Ae_HviChannelConfig Ae_HviChannelConfigInit[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][[!"$NumOfHviInstances"!]U] =
{
[!ENDCODE!]
    [!VAR "FirstInst" = "1"!]
    [!LOOP "AeHvmHviInstanceConfig/*"!]
        [!VAR "InstlHwId"  = "num:i(AeHvmHviChannelIdx)"!]
[!CODE!][!//
    [!IF "num:i($FirstInst)=0"!],[!ENDIF!][!VAR "FirstInst"="0"!]
    {
        {
            [!"num:i($InstlHwId)"!]U,
            (boolean)[!IF "node:value(AeHVIPullUpEn) = 'true'"!]TRUE[!ELSE!]FALSE[!ENDIF!],
            (boolean)[!IF "node:value(AeHVIPullDownEn) = 'true'"!]TRUE[!ELSE!]FALSE[!ENDIF!],
            [!"node:value(AeHviDividerSelect)"!]
        },
        (boolean)[!IF "node:value(AeHVIInputDigitalEn) = 'true'"!]TRUE[!ELSE!]FALSE[!ENDIF!],
        [!"node:value(AeHviDigitalInputPolarity)"!],
        (boolean)[!IF "node:value(AeHVIInterruptInputDigitalEn) = 'true'"!]TRUE[!ELSE!]FALSE[!ENDIF!]
    }
[!ENDCODE!]   
    [!ENDLOOP!]
[!CODE!]
};
[!ENDCODE!]
    [!ENDIF!]
[!ENDSELECT!]
[!ENDNOCODE!]

[!SELECT "AeHvmVmConfig"!]
[!CODE!]
static const Ae_VmConfig Ae_VmConfigInit[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!] =
{
    [!"node:value(AeHvmVoltageMonitorInputSelect)"!],
    (boolean)[!IF "node:value(AeHvmHighVoltageDetectEn) = 'true'"!]TRUE[!ELSE!]FALSE[!ENDIF!],
    (boolean)[!IF "node:value(AeHvmLowVoltageDetectEn) = 'true'"!]TRUE[!ELSE!]FALSE[!ENDIF!],
    (boolean)[!IF "node:value(AeVmHighVoltageDetectInterruptEn) = 'true'"!]TRUE[!ELSE!]FALSE[!ENDIF!],
    (boolean)[!IF "node:value(AeVmLowVoltageDetectInterruptEn) = 'true'"!]TRUE[!ELSE!]FALSE[!ENDIF!],
    [!"node:value(AeHvmHighDetectRefVoltage)"!],
    [!"node:value(AeHvmLowDetectRefVoltage)"!]
};
[!ENDCODE!]
[!ENDSELECT!]

#define AE_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Ae_MemMap.h"
/*==================================================================================================
*                                      GLOBAL VARIABLES
==================================================================================================*/
#define AE_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Ae_MemMap.h"

[!SELECT "AeHvmHviConfig"!]
[!CODE!]
const Hvm_Ip_ConfigType Hvm_Ip_aConfigPB[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!] =
{
    (uint8)[!"node:value(AeHvmHviGeneralConfig/AeHvmHviAnalogchannel)"!],
    (uint8)[!"node:value(AeHvmHviGeneralConfig/AeHvmAnalogInput)"!],
    &Ae_HviChannelConfigInit[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][0U],
    &Ae_VmConfigInit[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]
};
[!ENDCODE!]
[!ENDSELECT!]

#define AE_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Ae_MemMap.h"

/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/


/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/


/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/

#ifdef __cplusplus
}
#endif

/** @} */

#endif /* HVM_IP_PBCFG_C */
