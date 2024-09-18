/*==================================================================================================
*   Project              : RTD AUTOSAR 4.7
*   Platform             : CORTEXM
*   Peripheral           : IPV_GDU
*   Dependencies         : none
*
*   Autosar Version      : 4.7.0
*   Autosar Revision     : ASR_REL_4_7_REV_0000
*   Autosar Conf.Variant :
*   SW Version           : 3.0.0
*   Build Version        : S32K3_RTD_3_0_0_D2303_ASR_REL_4_7_REV_0000_20230331
*
*   (c) Copyright 2020 - 2023 NXP Semiconductors
*   All Rights Reserved.
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
*   @file    Gdu_Ip[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg.c
*   @version 3.0.0
*
*   @brief   AUTOSAR Gdu - IPV_GDU postbuild configuration.
*
*   @addtogroup IPV_GDU
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
#include "Gdu_Ip[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFOGDUATION
==================================================================================================*/
#define GDU_IP[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_VENDOR_ID_C                     43
#define GDU_IP[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_AR_RELEASE_MAJOR_VERSION_C      4
#define GDU_IP[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_AR_RELEASE_MINOR_VERSION_C      7
#define GDU_IP[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_AR_RELEASE_REVISION_VERSION_C   0
#define GDU_IP[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_SW_MAJOR_VERSION_C              3
#define GDU_IP[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_SW_MINOR_VERSION_C              0
#define GDU_IP[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_SW_PATCH_VERSION_C              0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
#if (GDU_IP[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_VENDOR_ID_C != GDU_IP[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_VENDOR_ID)
    #error "Gdu_Ip[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg.c and Gdu_Ip[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg.h have different vendor ids"
#endif
#if ((GDU_IP[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_AR_RELEASE_MAJOR_VERSION_C    != GDU_IP[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_AR_RELEASE_MAJOR_VERSION) || \
     (GDU_IP[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_AR_RELEASE_MINOR_VERSION_C    != GDU_IP[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_AR_RELEASE_MINOR_VERSION) || \
     (GDU_IP[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_AR_RELEASE_REVISION_VERSION_C != GDU_IP[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_AR_RELEASE_REVISION_VERSION))
     #error "AUTOSAR Version Numbers of Gdu_Ip[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg.c and Gdu_Ip[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg.h are different"
#endif
#if ((GDU_IP[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_SW_MAJOR_VERSION_C != GDU_IP[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_SW_MAJOR_VERSION) || \
     (GDU_IP[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_SW_MINOR_VERSION_C != GDU_IP[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_SW_MINOR_VERSION) || \
     (GDU_IP[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_SW_PATCH_VERSION_C != GDU_IP[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Gdu_Ip[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg.c and Gdu_Ip[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg.h are different"
#endif

/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
*                                         LOCAL MACROS
==================================================================================================*/
/** These bits are set at reset, and are not configured by the driver */
#define GDU_IP_PBCFG_REG_CTL_RESET_VAL  0x00C3u

/*==================================================================================================
*                                         LOCAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                         LOCAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                         GLOBAL CONSTANTS
==================================================================================================*/
#define GDU_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Gdu_MemMap.h"

[!NOCODE!][!//
[!VAR "VariantsNo" = "variant:size()"!]
[!CODE!][!//
/** Gdu Ip Configuration[!IF "var:defined('postBuildVariant')"!] for [!"$postBuildVariant"!] variant.[!ENDIF!] */
[!ENDCODE!][!//
    [!IF "(IMPLEMENTATION_CONFIG_VARIANT !='VariantPostBuild' and ($VariantsNo <= 1))"!][!//
[!CODE!][!//
/* VariantPreCompile/LinkTime and at most 1 configured variant */
const Gdu_Ip_ConfigType Gdu_Ip_xConfig =
{
[!ENDCODE!][!//
[!ELSE!][!//
[!CODE!][!//
/* VariantPostBuild or more than 1 configured variant */
const Gdu_Ip_ConfigType Gdu_Ip_xConfig[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!] =
{
[!ENDCODE!][!//
[!ENDIF!][!//
[!CODE!][!//
/** INTF */       0u,
/** RESERVED_0 */ {0u},
/** INTEN */      (GDU_AE_INTEN_HDHVDIE([!IF "./GduGeneral/GduIntEn/GduHighVoltageIE = 'true'"!]1u[!ELSE!]0U[!ENDIF!]) | GDU_AE_INTEN_DHSIE2([!IF "./GduGeneral/GduIntEn/GduDesaturationHs2IE = 'true'"!]1u[!ELSE!]0U[!ENDIF!]) | GDU_AE_INTEN_DHSIE1([!IF "./GduGeneral/GduIntEn/GduDesaturationHs1IE = 'true'"!]1u[!ELSE!]0U[!ENDIF!]) | GDU_AE_INTEN_DHSIE0([!IF "./GduGeneral/GduIntEn/GduDesaturationHs0IE = 'true'"!]1u[!ELSE!]0U[!ENDIF!]) | GDU_AE_INTEN_DLSIE2([!IF "./GduGeneral/GduIntEn/GduDesaturationLs2IE = 'true'"!]1u[!ELSE!]0U[!ENDIF!]) | GDU_AE_INTEN_DLSIE0([!IF "./GduGeneral/GduIntEn/GduDesaturationLs0IE = 'true'"!]1u[!ELSE!]0U[!ENDIF!]) | GDU_AE_INTEN_DLSIE0([!IF "./GduGeneral/GduIntEn/GduDesaturationLs0IE = 'true'"!]1u[!ELSE!]0U[!ENDIF!])),
/** RESERVED_1 */ {0u},
/** STAT */       0u,
/** CTL */        (GDU_AE_CTL_BOOSTEN([!IF "./GduGeneral/GduCtl/GduBoostConverterEn = 'true'"!]1u[!ELSE!]0U[!ENDIF!]) | GDU_AE_CTL_IRTSW([!IF "./GduGeneral/GduCtl/GduCustomIrefTrimming = 'true'"!]1u[!ELSE!]0U[!ENDIF!]) | GDU_IP_PBCFG_REG_CTL_RESET_VAL),
/** CFG */        (GDU_AE_CFG_SYNCEN([!IF "./GduGeneral/GduCfg/GduSyncPwmClock = 'true'"!]1u[!ELSE!]0U[!ENDIF!]) | GDU_AE_CFG_HDHSDIV([!IF "./GduGeneral/GduCfg/GduVoltageDividerFactor = 'GDU_IP_DIVIDER_HIGH'"!]1u[!ELSE!]0U[!ENDIF!]) | GDU_AE_CFG_HDHVDCFG([!IF "./GduGeneral/GduCfg/GduOvervoltageThreshold = 'GDU_IP_VOLTAGE_HIGH'"!]1u[!ELSE!]0U[!ENDIF!])),
/** RESERVED_2 */ {0u},
/** EACFG */      (GDU_AE_EACFG_DSA([!IF "./GduGeneral/GduEaCfg/GduDesaturationAction = 'true'"!]1u[!ELSE!]0U[!ENDIF!]) | GDU_AE_EACFG_OCA([!IF "./GduGeneral/GduEaCfg/GduOvercurrentAction = 'true'"!]1u[!ELSE!]0U[!ENDIF!])  | GDU_AE_EACFG_HVDA([!IF "./GduGeneral/GduEaCfg/GduOvervoltageAction = 'true'"!]1u[!ELSE!]0U[!ENDIF!])),
/** RESERVED_3 */ {0u},
/** BOOSTCFG */   (GDU_AE_BOOSTCFG_BOCL([!"./GduGeneral/GduBoostCfg/GduBoostCoilCurrent"!]) | GDU_AE_BOOSTCFG_BOCD([!"num:i(./GduGeneral/GduBoostCfg/GduBoostClockDivider)"!]u) | GDU_AE_BOOSTCFG_BODC((uint8)[!"./GduGeneral/GduBoostCfg/GduBoostDutyCyle"!])),
/** BTCFG */      (GDU_AE_BTCFG_BT([!"num:i(./GduGeneral/GduBtCfg/GduBlankingTime)"!]u)),
/** HSSRON */     (GDU_AE_HSSRON_HSTONT_P2([!"num:i(./GduGeneral/GduHssrOn/GduHsTurnOnTicks2)"!]u) | GDU_AE_HSSRON_HSTONT_P1([!"num:i(./GduGeneral/GduHssrOn/GduHsTurnOnTicks1)"!]u) | GDU_AE_HSSRON_HSTONC_P3([!"num:i(./GduGeneral/GduHssrOn/GduHsTurnOnSlew3)"!]u) | GDU_AE_HSSRON_HSTONC_P2([!"num:i(./GduGeneral/GduHssrOn/GduHsTurnOnSlew2)"!]u) | GDU_AE_HSSRON_HSTONC_P1([!"num:i(./GduGeneral/GduHssrOn/GduHsTurnOnSlew1)"!]u)),
/** HSSROFF */    (GDU_AE_HSSROFF_HSTOFFT_P2([!"num:i(./GduGeneral/GduHssrOff/GduHsTurnOffTicks2)"!]u) | GDU_AE_HSSROFF_HSTOFFT_P1([!"num:i(./GduGeneral/GduHssrOff/GduHsTurnOffTicks1)"!]u) | GDU_AE_HSSROFF_HSTOFFC_P3([!"num:i(./GduGeneral/GduHssrOff/GduHsTurnOffSlew3)"!]u) | GDU_AE_HSSROFF_HSTOFFC_P2([!"num:i(./GduGeneral/GduHssrOff/GduHsTurnOffSlew2)"!]u) | GDU_AE_HSSROFF_HSTOFFC_P1([!"num:i(./GduGeneral/GduHssrOff/GduHsTurnOffSlew1)"!]u)),
/** LSSRON */     (GDU_AE_LSSRON_LSTONT_P2([!"num:i(./GduGeneral/GduLssrOn/GduLsTurnOnTicks2)"!]u) | GDU_AE_LSSRON_LSTONT_P1([!"num:i(./GduGeneral/GduLssrOn/GduLsTurnOnTicks1)"!]u) | GDU_AE_LSSRON_LSTONC_P3([!"num:i(./GduGeneral/GduLssrOn/GduLsTurnOnSlew3)"!]u) | GDU_AE_LSSRON_LSTONC_P2([!"num:i(./GduGeneral/GduLssrOn/GduLsTurnOnSlew2)"!]u) | GDU_AE_LSSRON_LSTONC_P1([!"num:i(./GduGeneral/GduLssrOn/GduLsTurnOnSlew1)"!]u)),
/** LSSROFF */    (GDU_AE_LSSROFF_LSTOFFT_P2([!"num:i(./GduGeneral/GduLssrOff/GduLsTurnOffTicks2)"!]u) | GDU_AE_LSSROFF_LSTOFFT_P1([!"num:i(./GduGeneral/GduLssrOff/GduLsTurnOffTicks1)"!]u) | GDU_AE_LSSROFF_LSTOFFC_P3([!"num:i(./GduGeneral/GduLssrOff/GduLsTurnOffSlew3)"!]u) | GDU_AE_LSSROFF_LSTOFFC_P2([!"num:i(./GduGeneral/GduLssrOff/GduLsTurnOffSlew2)"!]u) | GDU_AE_LSSROFF_LSTOFFC_P1([!"num:i(./GduGeneral/GduLssrOff/GduLsTurnOffSlew1)"!]u)),
/** OFFSDCFG */   0u,
/** RESERVED_3 */ {0u},
/** DSCFG */      (GDU_AE_DSCFG_DSFHS([!"./GduGeneral/GduDsCfg/GduDesaturationFilterHs"!]) | GDU_AE_DSCFG_DSFLS([!"./GduGeneral/GduDsCfg/GduDesaturationFilterLs"!]) | GDU_AE_DSCFG_DSLHS([!"./GduGeneral/GduDsCfg/GduDesaturationLevelHs"!])  | GDU_AE_DSCFG_DSLLS([!"./GduGeneral/GduDsCfg/GduDesaturationLevelLs"!])),
/** RESERVED_5 */ {0u},
/** CPCFG */      (GDU_AE_CPCFG_CPCDT([!"./GduGeneral/GduCpCfg/GduChargePumpDischarge"!]) | GDU_AE_CPCFG_CPT([!"num:i(./GduGeneral/GduCpCfg/GduChargePumpVcpOn)"!]u) | GDU_AE_CPCFG_CPCD([!"num:i(./GduGeneral/GduCpCfg/GduChargePumpClockDivider)"!]u)),
/** DLYMR */      0u,
/** DLYMCFG */    0u,
/** SUPCFG */     (GDU_AE_SUPCFG_SUP([!IF "./GduGeneral/GduSupCfg/GduDriveLsFunctionalReset = 'true'"!]1u[!ELSE!]0U[!ENDIF!])),
/** RESERVED_5 */ {0u},
/** IRT */        (GDU_AE_IRT_IRT1P2([!"./GduGeneral/GduIrt/GduIrefTrimmingHg2"!]) | GDU_AE_IRT_IRT0P2([!"./GduGeneral/GduIrt/GduIrefTrimmingLg2"!]) | GDU_AE_IRT_IRT1P1([!"./GduGeneral/GduIrt/GduIrefTrimmingHg1"!]) | GDU_AE_IRT_IRT0P1([!"./GduGeneral/GduIrt/GduIrefTrimmingLg1"!]) | GDU_AE_IRT_IRT1P0([!"./GduGeneral/GduIrt/GduIrefTrimmingHg0"!]) | GDU_AE_IRT_IRT0P0([!"./GduGeneral/GduIrt/GduIrefTrimmingLg0"!])),
};
[!ENDCODE!][!//
[!ENDNOCODE!][!//

#define GDU_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Gdu_MemMap.h"

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

/** @} */
