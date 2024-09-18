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

#ifndef XRDC_IP_CFG_DEFINES_H
#define XRDC_IP_CFG_DEFINES_H

/**
*   @file Xrdc_Ip_Cfg_Defines.h
*
*   @addtogroup XRDC_IP XRDC IPV Driver
*   @{
*/


#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
*                                         INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
/**
 * Include specific header file
 */
#include "StandardTypes.h" 
[!IF "RmGeneral/RmEnableXRDCSupport"!][!//
#include "[!"ecu:get('Rm.Common.Header.List')"!]_XRDC.h"
[!ENDIF!][!// RmEnableXRDCSupport

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define RM_XRDC_IP_CFG_DEFINES_VENDOR_ID                    43
#define RM_XRDC_IP_CFG_DEFINES_AR_RELEASE_MAJOR_VERSION     4
#define RM_XRDC_IP_CFG_DEFINES_AR_RELEASE_MINOR_VERSION     7
#define RM_XRDC_IP_CFG_DEFINES_AR_RELEASE_REVISION_VERSION  0
#define RM_XRDC_IP_CFG_DEFINES_SW_MAJOR_VERSION             3
#define RM_XRDC_IP_CFG_DEFINES_SW_MINOR_VERSION             0
#define RM_XRDC_IP_CFG_DEFINES_SW_PATCH_VERSION             0
/*==================================================================================================
*                                      FILE VERSION CHECKS
==================================================================================================*/


/*==================================================================================================
*                                 GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                             ENUMS
==================================================================================================*/


/*==================================================================================================
*                                           CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/
[!IF "RmGeneral/RmEnableXRDCSupport"!]
[!IF "RmGeneral/RmEnableUserModeSupport"!]
/** @brief    User mode support          */
#define XRDC_IP_ENABLE_USER_MODE_SUPPORT

#ifndef MCAL_ENABLE_USER_MODE_SUPPORT
    #ifdef XRDC_IP_ENABLE_USER_MODE_SUPPORT
        #error "MCAL_ENABLE_USER_MODE_SUPPORT is not enabled. For running XRDC in user mode the MCAL_ENABLE_USER_MODE_SUPPORT needs to be defined"
    #endif /* (STD_ON == XRDC_IP_ENABLE_USER_MODE_SUPPORT) */
#endif /* ifndef MCAL_ENABLE_USER_MODE_SUPPORT */
[!ENDIF!][!//

#define XRDC_COUNT                                   (uint32)([!"ecu:get('Rm.XRDC.XRDCInstancesCount')"!]UL)

#define XRDC_NUMBER_OF_DOMAINID                      (uint32)([!"num:i(count(ecu:list('Rm.XRDC.DomainID.List')))"!]UL)

#define XRDC_BASE_ADDRS                              { IP_XRDC_BASE }

#define XRDC_MOD_BASEADDR_ADDR32(instance)           (Xrdc_Ip_InstanceAddress[instance])

#define XRDC_CR_OFFSET                               (uint32)(0x0U)

#define XRDC_HWCFG0_OFFSET                           (uint32)(0xF0U)
#define XRDC_HWCFG1_OFFSET                           (uint32)(0xF4U)
#define XRDC_HWCFG2_OFFSET                           (uint32)(0xF8U)

#define XRDC_MDACFG_OFFSET                           (uint32)(0x100U)

#define XRDC_MRCFG_OFFSET                            (uint32)(0x140U)

#define XRDC_DERRLOC_OFFSET                          (uint32)(0x200U)

#define XRDC_DERR_W_OFFSET                           (uint32)(0x400U)

#define XRDC_PID_OFFSET                              (uint32)(0x700U)

#define XRDC_MDA_W_DFMT0_OFFSET                      (uint32)(0x800U)

#define XRDC_PDAC_W0_OFFSET                          (uint32)(0x1000U)

#define XRDC_PDAC_W1_OFFSET                          (uint32)(0x1004U)

#define XRDC_MRGD_OFFSET                             (uint32)(0x2000U)
[!ENDIF!][!//

#define XRDC_MAX_OF_ERROR_RECORDED                   (uint32)([!"ecu:get('Rm.XRDC.ErrorInstancesCount')"!]UL)

/*==================================================================================================
*                                 STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
*                                      FUNCTION PROTOTYPES
==================================================================================================*/


#ifdef __cplusplus
}
#endif

/** @} */

#endif /* XRDC_IP_DEVICE_REGISTERS_H */


