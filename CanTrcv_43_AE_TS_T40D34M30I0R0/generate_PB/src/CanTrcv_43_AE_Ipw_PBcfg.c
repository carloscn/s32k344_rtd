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
*   @file    CanTrcv_43_AE_Ipw_PBcfg[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!].c
*   @version 3.0.0
*
*   @brief   AUTOSAR CanTrcv_43_AE - module interface
*   @details Configuration Structures for PostBuild
*
*   @addtogroup CANTRCV_DRIVER
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
#include "CanTrcv_43_AE_Ipw_Types.h"
#include "AeCanPHY_Ip.h"
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define CANTRCV_43_AE_IPW_PBCFG[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_VENDOR_ID_C                     43
#define CANTRCV_43_AE_IPW_PBCFG[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_AR_RELEASE_MAJOR_VERSION_C      4
#define CANTRCV_43_AE_IPW_PBCFG[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_AR_RELEASE_MINOR_VERSION_C      7
#define CANTRCV_43_AE_IPW_PBCFG[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_AR_RELEASE_REVISION_VERSION_C   0
#define CANTRCV_43_AE_IPW_PBCFG[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_SW_MAJOR_VERSION_C              3
#define CANTRCV_43_AE_IPW_PBCFG[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_SW_MINOR_VERSION_C              0
#define CANTRCV_43_AE_IPW_PBCFG[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_SW_PATCH_VERSION_C              0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/

/*==================================================================================================
                                 GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/
#define CANTRCV_43_AE_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanTrcv_43_AE_MemMap.h"

/**
* @brief   Export PHY_AE10 configurations.
*/
[!NOCODE!]
[!IF "var:defined('postBuildVariant')"!]
    [!VAR "postBuildVariantNameUnderscore" = "concat('_',$postBuildVariant)"!]
[!ELSE!]
    [!VAR "postBuildVariantNameUnderscore" = "string(null)"!]
[!ENDIF!]
[!SELECT "CanTrcvConfigSet"!]
[!VAR "CtrlConfigCount" = "num:i(count(./CanTrcvChannel/*))"!]
[!VAR "ChnIdx" = "num:i(0)"!]
[!LOOP "node:order(./CanTrcvChannel/*, './CanTrcvChannelId')"!]
[!CODE!]const CanTrcv_43_AE_Ipw_TransceiverConfigType CanTrcv_43_AE_Ipw_TransceiverConfig[!"$postBuildVariantNameUnderscore"!]_Chn[!"$ChnIdx"!] =
{
    &AeCanPHY_aConfigPB[!"$postBuildVariantNameUnderscore"!][[!"$ChnIdx"!]U][!ENDCODE!]
    [!VAR "ChnIdx" = "num:i($ChnIdx + 1)"!]
[!CODE!]
};
[!ENDCODE!]
[!ENDLOOP!]
[!ENDSELECT!]
[!ENDNOCODE!]
#define CANTRCV_43_AE_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanTrcv_43_AE_MemMap.h"

/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/

/*==================================================================================================
*                                      LOCAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      LOCAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                      GLOBAL VARIABLES
==================================================================================================*/

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
