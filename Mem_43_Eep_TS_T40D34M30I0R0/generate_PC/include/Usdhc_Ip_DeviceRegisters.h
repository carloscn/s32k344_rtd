/*==================================================================================================
* Project : RTD AUTOSAR 4.7
* Platform : CORTEXM
* Peripheral : IPV_USDHC
* Dependencies : 
*
* Autosar Version : 4.7.0
* Autosar Revision : ASR_REL_4_7_REV_0000
* Autosar Conf.Variant :
* SW Version : 3.0.0
* Build Version : S32K3_RTD_3_0_0_D2303_ASR_REL_4_7_REV_0000_20230331
*
* Copyright 2020 - 2023 NXP Semiconductors
*
* NXP Confidential. This software is owned or controlled by NXP and may only be
* used strictly in accordance with the applicable license terms. By expressly
* accepting such terms or by downloading, installing, activating and/or otherwise
* using the software, you are agreeing that you have read, and that you agree to
* comply with and are bound by, such license terms. If you do not agree to be
* bound by the applicable license terms, then you may not retain, install,
* activate or otherwise use the software.
==================================================================================================*/

#ifndef USDHC_IP_DEVICE_REGISTERS_H
#define USDHC_IP_DEVICE_REGISTERS_H

/**
* @file
*
* @addtogroup MEM_43_EEP_DRIVER Mem_43_Eeprom Driver
* @{
*/
/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
[!CODE!][!// Include specific header file
[!VAR "HeaderFile"!][!"ecu:get('Mem_43_Eep.Usdhc.Header')"!][!ENDVAR!]
#include "[!"$HeaderFile"!]"
[!IF "contains($HeaderFile, 'S32N')"!]#include "Mem_43_Eep_Defines.h"[!ENDIF!]
[!ENDCODE!][!//

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/

#define USDHC_IP_DEVICE_REGISTERS_VENDOR_ID                       43
#define USDHC_IP_DEVICE_REGISTERS_AR_RELEASE_MAJOR_VERSION        4
#define USDHC_IP_DEVICE_REGISTERS_AR_RELEASE_MINOR_VERSION        7
#define USDHC_IP_DEVICE_REGISTERS_AR_RELEASE_REVISION_VERSION     0
#define USDHC_IP_DEVICE_REGISTERS_SW_MAJOR_VERSION                3
#define USDHC_IP_DEVICE_REGISTERS_SW_MINOR_VERSION                0
#define USDHC_IP_DEVICE_REGISTERS_SW_PATCH_VERSION                0

/*==================================================================================================
*                                     DEFINES AND MACROS
==================================================================================================*/
[!CODE!][!//

/*! @brief USDHC supports HS200, HS400 modes with tuning feature */
#define FEATURE_USDHC_HAS_HIGHSPEED_TUNNING           ([!"ecu:get('Mem_43_Eep.HighSpeedTuning.Available')"!])

[!ENDCODE!][!//

#endif /* USDHC_IP_DEVICE_REGISTERS_H */

/** @}*/

