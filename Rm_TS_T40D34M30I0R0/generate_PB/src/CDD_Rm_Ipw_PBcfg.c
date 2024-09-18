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

/**
*   @file CDD_Rm_Ipw_PBcfg.c
*
*   @addtogroup RM_MODULE RM Driver
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
#include "CDD_Rm_Ipw_Cfg.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define RM_IPW_PBCFG[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_VENDOR_ID_C                     43
#define RM_IPW_PBCFG[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_AR_RELEASE_MAJOR_VERSION_C      4
#define RM_IPW_PBCFG[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_AR_RELEASE_MINOR_VERSION_C      7
#define RM_IPW_PBCFG[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_AR_RELEASE_REVISION_VERSION_C   0
#define RM_IPW_PBCFG[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_SW_MAJOR_VERSION_C              3
#define RM_IPW_PBCFG[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_SW_MINOR_VERSION_C              0
#define RM_IPW_PBCFG[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_SW_PATCH_VERSION_C              0
/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Checks against CDD_Rm_Ipw_Cfg.h */
#if (RM_IPW_PBCFG[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_VENDOR_ID_C != RM_IPW_CFG_VENDOR_ID)
    #error "CDD_Rm_Ipw[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg.c and CDD_Rm_Ipw_Cfg.h have different vendor ids"
#endif
#if ((RM_IPW_PBCFG[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_AR_RELEASE_MAJOR_VERSION_C    != RM_IPW_CFG_AR_RELEASE_MAJOR_VERSION) || \
     (RM_IPW_PBCFG[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_AR_RELEASE_MINOR_VERSION_C    != RM_IPW_CFG_AR_RELEASE_MINOR_VERSION) || \
     (RM_IPW_PBCFG[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_AR_RELEASE_REVISION_VERSION_C != RM_IPW_CFG_AR_RELEASE_REVISION_VERSION))
    #error "AUTOSAR Version Numbers of CDD_Rm_Ipw[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg.c and CDD_Rm_Ipw_Cfg.h are different"
#endif
#if ((RM_IPW_PBCFG[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_SW_MAJOR_VERSION_C != RM_IPW_CFG_SW_MAJOR_VERSION) || \
     (RM_IPW_PBCFG[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_SW_MINOR_VERSION_C != RM_IPW_CFG_SW_MINOR_VERSION) || \
     (RM_IPW_PBCFG[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_SW_PATCH_VERSION_C != RM_IPW_CFG_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of CDD_Rm_Ipw[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg.c and CDD_Rm_Ipw_Cfg.h are different"
#endif
/*==================================================================================================
                                 GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/


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
#define RM_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Rm_MemMap.h"

[!IF "RmGeneral/RmEnableSema42Support"!][!//
[!NOCODE!][!//
[!VAR "Rm_Sema42ChannelCount" = "count(RmConfigSet/Sema42_ModuleConfig/Sema42LogicChannelConfiguration/*)"!][!//

[!CODE!][!//
/**
 * @brief       Sema42 Logic Channel Configuration Array
 */
static const Rm_Ipw_Sema42_LogicChannelConfigType Rm_Ipw_Sema42_LogicChannelArray[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][[!"num:i($Rm_Sema42ChannelCount)"!]U] =
{
[!LOOP "RmConfigSet/Sema42_ModuleConfig/Sema42LogicChannelConfiguration/*"!][!//
[!VAR "Rm_Sema42ChannelCount" = "$Rm_Sema42ChannelCount - 1"!][!//
    {
        /* Hardware Instance  */ [!"(./Sema42HardwareInstance)"!],
        /* Hardware Channel   */ [!"substring-after(./Sema42HardwareChannel ,'')"!]U
    }[!IF "$Rm_Sema42ChannelCount != 0"!],[!ENDIF!]
[!ENDLOOP!][!//
};
[!ENDCODE!][!//

[!VAR "Rm_Sema42ChannelCount" = "count(RmConfigSet/Sema42_ModuleConfig/Sema42LogicChannelConfiguration/*)"!][!//
[!CODE!][!//
static const Rm_Ipw_Sema42_ConfigType Rm_Ipw_Sema42_Config[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!] =
{
    Rm_Ipw_Sema42_LogicChannelArray[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]
};

[!ENDCODE!][!//
[!ENDNOCODE!][!//
[!ENDIF!][!//

[!VAR "ip_Enable_Sum" = "num:i(0)"!][!//
[!IF "RmGeneral/RmEnableXRDCSupport"!][!VAR "ip_Enable_Sum" = "$ip_Enable_Sum + num:i(1)"!][!ENDIF!][!//
[!IF "RmGeneral/RmEnableSema42Support"!][!VAR "ip_Enable_Sum" = "$ip_Enable_Sum + num:i(1)"!][!ENDIF!][!//
[!IF "RmGeneral/RmPflashConfigurable"!][!VAR "ip_Enable_Sum" = "$ip_Enable_Sum + num:i(1)"!][!ENDIF!][!//
[!IF "RmGeneral/RmCrossbarConfigurable"!][!VAR "ip_Enable_Sum" = "$ip_Enable_Sum + num:i(1)"!][!ENDIF!][!//
[!IF "RmGeneral/RmVirtWrapperConfigurable"!][!VAR "ip_Enable_Sum" = "$ip_Enable_Sum + num:i(1)"!][!ENDIF!][!//
[!IF "RmGeneral/RmXbicConfigurable"!][!VAR "ip_Enable_Sum" = "$ip_Enable_Sum + num:i(1)"!][!ENDIF!][!//
[!IF "RmGeneral/RmEnableDmaMuxSupport"!][!VAR "ip_Enable_Sum" = "$ip_Enable_Sum + num:i(1)"!][!ENDIF!][!//
[!IF "RmGeneral/RmEnableMscmSupport"!][!VAR "ip_Enable_Sum" = "$ip_Enable_Sum + num:i(1)"!][!ENDIF!][!//
[!VAR "ip_Index" = "num:i(0)"!][!//


const Rm_Ipw_ConfigType Rm_Ipw_Config[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!] =
{
[!IF "RmGeneral/RmEnableXRDCSupport"!][!//
    &Xrdc_Config[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][!VAR "ip_Index" = "$ip_Index + num:i(1)"!][!IF "$ip_Index < $ip_Enable_Sum"!],[!ENDIF!]
[!ENDIF!][!//
[!IF "RmGeneral/RmEnableSema42Support"!][!//
    &Rm_Ipw_Sema42_Config[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][!VAR "ip_Index" = "$ip_Index + num:i(1)"!][!IF "$ip_Index < $ip_Enable_Sum"!],[!ENDIF!]
[!ENDIF!][!//
[!IF "RmGeneral/RmPflashConfigurable"!][!//
    &Pflash_Config[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][!VAR "ip_Index" = "$ip_Index + num:i(1)"!][!IF "$ip_Index < $ip_Enable_Sum"!],[!ENDIF!]
[!ENDIF!][!//
[!IF "RmGeneral/RmCrossbarConfigurable"!][!//
    &Axbs_Config[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][!VAR "ip_Index" = "$ip_Index + num:i(1)"!][!IF "$ip_Index < $ip_Enable_Sum"!],[!ENDIF!]
[!ENDIF!][!//
[!IF "RmGeneral/RmVirtWrapperConfigurable"!][!//
    &Virt_Wrapper_Ip_Config[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][!VAR "ip_Index" = "$ip_Index + num:i(1)"!][!IF "$ip_Index < $ip_Enable_Sum"!],[!ENDIF!]
[!ENDIF!][!//
[!IF "RmGeneral/RmXbicConfigurable"!][!//
    &Xbic_Config[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][!VAR "ip_Index" = "$ip_Index + num:i(1)"!][!IF "$ip_Index < $ip_Enable_Sum"!],[!ENDIF!]
[!ENDIF!][!//
[!IF "RmGeneral/RmEnableDmaMuxSupport"!][!//
    &Dma_Mux_Config[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][!VAR "ip_Index" = "$ip_Index + num:i(1)"!][!IF "$ip_Index < $ip_Enable_Sum"!],[!ENDIF!]
[!ENDIF!][!//
[!IF "RmGeneral/RmEnableMscmSupport"!][!//
    &Mscm_Config[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]
[!ENDIF!][!//
};

#define RM_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Rm_MemMap.h"

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

