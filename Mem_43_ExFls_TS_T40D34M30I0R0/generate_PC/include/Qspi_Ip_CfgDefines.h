[!AUTOSPACING!]
[!CODE!][!//
/*==================================================================================================
*   Project              : RTD AUTOSAR 4.7
*   Platform             : CORTEXM
*   Peripheral           : IPV_QSPI
*   Dependencies         : None
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

#ifndef QSPI_IP_CFG_DEFINES_H
#define QSPI_IP_CFG_DEFINES_H

/**
*   @file Qspi_Ip_CfgDefines.h
*
*   @addtogroup FLS
*   @{
*/

/* implements Qspi_Ip_CfgDefines.h_Artifact */

#ifdef __cplusplus
extern "C"{
#endif


/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define QSPI_IP_VENDOR_ID_CFG_DEFINES                    43
#define QSPI_IP_AR_RELEASE_MAJOR_VERSION_CFG_DEFINES     4
#define QSPI_IP_AR_RELEASE_MINOR_VERSION_CFG_DEFINES     7
#define QSPI_IP_AR_RELEASE_REVISION_VERSION_CFG_DEFINES  0
#define QSPI_IP_SW_MAJOR_VERSION_CFG_DEFINES             3
#define QSPI_IP_SW_MINOR_VERSION_CFG_DEFINES             0
#define QSPI_IP_SW_PATCH_VERSION_CFG_DEFINES             0


/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/

/*==================================================================================================
                                       DEFINES AND MACROS
==================================================================================================*/

#define QSPI_IP_SFP_ENABLE_GLOBAL         ([!IF "MemGeneral/MemQspiSfpEnableGlobal"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])
#define QSPI_IP_SFP_ENABLE_MDAD           ([!IF "MemGeneral/MemQspiSfpEnableMdad"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])
#define QSPI_IP_SFP_ENABLE_FRAD           ([!IF "MemGeneral/MemQspiSfpEnableFrad"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])


[!ENDCODE!][!//
#ifdef __cplusplus
}
#endif

/** @} */

#endif /* QSPI_IP_CFG_DEFINES_H */

