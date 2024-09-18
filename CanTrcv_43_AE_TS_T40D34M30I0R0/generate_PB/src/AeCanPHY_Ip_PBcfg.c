
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
*   @file AeCanPHY_Ip_PBcfg.c
*
*   @addtogroup AeCanPHY
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
[!IF "var:defined('postBuildVariant')"!]
    [!VAR "postBuildVariantNameUnderscore" = "concat('_',$postBuildVariant)"!]
[!ELSE!]
    [!VAR "postBuildVariantNameUnderscore" = "string(null)"!]
[!ENDIF!]
#include "AeCanPHY_Ip_Types.h"
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define AE_CANPHY_IP_VENDOR_ID_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_C 43
#define AE_CANPHY_IP_AR_RELEASE_MAJOR_VERSION_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_C 4
#define AE_CANPHY_IP_AR_RELEASE_MINOR_VERSION_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_C 7
#define AE_CANPHY_IP_AR_RELEASE_REVISION_VERSION_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_C 0
#define AE_CANPHY_IP_SW_MAJOR_VERSION_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_C 3
#define AE_CANPHY_IP_SW_MINOR_VERSION_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_C 0
#define AE_CANPHY_IP_SW_PATCH_VERSION_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_C 0
/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/

/*==================================================================================================
*                                   GLOBAL FUNCTION PROTOTYPES
==================================================================================================*/

/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                      GLOBAL CONSTANTS
==================================================================================================*/
#define CANTRCV_43_AE_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanTrcv_43_AE_MemMap.h"

[!VAR "CtrlConfigCount" = "num:i(count(./CanTrcvConfigSet/CanTrcvChannel/*))"!]
const AeCanPHY_Ip_ConfigType AeCanPHY_aConfigPB[!"$postBuildVariantNameUnderscore"!][[!"$CtrlConfigCount"!]U]=
{
    [!INDENT "4"!]
    [!VAR "CtrlIdx" = "num:i(0)"!]
    [!VAR "Spi_Timeout" = "num:i(CanTrcvConfigSet/CanTrcvSPICommTimeout)"!]
    [!VAR "Spi_ReTries_Num" = "num:i(CanTrcvConfigSet/CanTrcvSPICommRetries)"!]
    [!LOOP "node:order(./CanTrcvConfigSet/CanTrcvChannel/*, './CanTrcvChannelId')"!]
    {
        /* .SpiConfig */
        {
            /* .SpiCommRetries */
            (uint8)[!"$Spi_ReTries_Num"!]
        },
        /* .DeviceModeAfterInit */
        AE_CANPHY_OFFLINE_MODE
    }[!IF "num:i($CtrlIdx + 1) < $CtrlConfigCount"!],[!ENDIF!][!CR!]
    [!ENDLOOP!]
    [!ENDINDENT!]
};

#define CANTRCV_43_AE_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanTrcv_43_AE_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */
