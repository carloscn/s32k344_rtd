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
#ifndef AE_CANPHY_IP_HWACCESS_H
#define AE_CANPHY_IP_HWACCESS_H

/*==================================================================================================
                                         INCLUDE FILES
 1) system and project includes
 2) needed interfaces from external units
 3) internal and external interfaces from this unit
==================================================================================================*/
#include "StandardTypes.h"
#include "AeCanPHY_Ip_Types.h"
/*==================================================================================================
                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/


/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/

/*==================================================================================================
                                           CONSTANTS
==================================================================================================*/

/*==================================================================================================
                                       DEFINES AND MACROS
==================================================================================================*/
#define AE_CANPHY_CANPHY_CFG_REG_ADDR                  (0x70U)
#define AE_CANPHY_CANPHY_CFG_REG_CANPHY_ENABLE         (0x8000U)
#define AE_CANPHY_CANPHY_CFG_REG_CANPHY_MODE_MASK      (0x03U)
#define AE_CANPHY_CANPHY_MONITOR_REG_ADDR              (0x74U)
/*==================================================================================================
                                             ENUMS
==================================================================================================*/

/*==================================================================================================
                                 STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
                                 GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
                                     FUNCTION PROTOTYPES
==================================================================================================*/
#define CANTRCV_43_AE_START_SEC_CODE
#include "CanTrcv_43_AE_MemMap.h"

AeCanPHY_Ip_StatusType AeCanPHY_WriteRegisterViaSpi(const AeCanPHY_Ip_SpiConfigType * SpiConfig, uint16 RegAddr, uint32 writeData, uint8 Size);

AeCanPHY_Ip_StatusType AeCanPHY_ReadRegisterViaSpi(const AeCanPHY_Ip_SpiConfigType * SpiConfig, uint16 RegAddr, uint32 * rxData, uint8 Size);

#define CANTRCV_43_AE_STOP_SEC_CODE
#include "CanTrcv_43_AE_MemMap.h"

#endif /* AE_CANPHY_IP_HWACCESS_H */
