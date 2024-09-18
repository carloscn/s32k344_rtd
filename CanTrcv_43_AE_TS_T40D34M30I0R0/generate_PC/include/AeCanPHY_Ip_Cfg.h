
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
#ifndef _AE_CANPHY_IP_CFG_H_
#define _AE_CANPHY_IP_CFG_H_

/**
*   @file AeCanPHY_Ip_Cfg.h
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
[!NOCODE!]
[!IF "var:defined('postBuildVariant')"!]
    [!LOOP "variant:all()"!]
        [!CODE!]#include "AeCanPHY_Ip_[!"."!]_PBcfg.h"[!ENDCODE!][!CR!]
    [!ENDLOOP!]
[!ELSE!]
    [!CODE!]#include "AeCanPHY_Ip_PBcfg.h"[!ENDCODE!]
[!ENDIF!]
[!ENDNOCODE!]
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define AE_CANPHY_IP_CFG_VENDOR_ID_H                      43
#define AE_CANPHY_IP_CFG_AR_RELEASE_MAJOR_VERSION_H       4
#define AE_CANPHY_IP_CFG_AR_RELEASE_MINOR_VERSION_H       7
#define AE_CANPHY_IP_CFG_AR_RELEASE_REVISION_VERSION_H    0
#define AE_CANPHY_IP_CFG_SW_MAJOR_VERSION_H               3
#define AE_CANPHY_IP_CFG_SW_MINOR_VERSION_H               0
#define AE_CANPHY_IP_CFG_SW_PATCH_VERSION_H               0
/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/

/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/
[!NOCODE!]
[!CODE!]#define AE_CANPHY_IP_CONFIG_EXT \[!CR!][!ENDCODE!]
    [!INDENT "4"!]
    [!IF "var:defined('postBuildVariant')"!]
        [!VAR "variantIndex"="0"!]
        [!VAR "variantNumber"="variant:size()"!]
        [!LOOP "variant:all()"!]
            [!VAR "variantIndex"="$variantIndex + 1"!]
            [!CODE!]AE_CANPHY_IP_[!"."!]_PB_CFG [!IF "$variantIndex < $variantNumber"!]\[!ENDIF!][!CR!][!ENDCODE!]
        [!ENDLOOP!]
    [!ELSE!]
        [!CODE!]AE_CANPHY_IP_PB_CFG[!ENDCODE!]
    [!ENDIF!]
    [!ENDINDENT!]
[!ENDNOCODE!]

/* Enable Development Error Detection */
#define AE_CANPHY_IP_DEV_ERROR_DETECT[!WS "4"!][!IF "./CanTrcvGeneral/CanTrcvDevErrorDetect = 'true'"!](STD_ON)[!ELSE!](STD_OFF)[!ENDIF!]

#ifdef __cplusplus
}
#endif /* __cplusplus */

/** @} */

#endif /* _AE_CANPHY_IP_CFG_H_ */
