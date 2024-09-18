/*==================================================================================================
* Project : RTD AUTOSAR 4.7
* Platform : CORTEXM
* Peripheral : LPI2C
* Dependencies : none
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

#ifndef LPI2C_IP[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_H
#define LPI2C_IP[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_H

/**
*   @file
*
*   @addtogroup LPI2C_DRIVER_CONFIGURATION Lpi2c Driver Configurations
*   @{
*/

#ifdef __cplusplus
extern "C"
{
#endif


/*==================================================================================================
*                                          INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Lpi2c_Ip_Types.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define LPI2C_IP[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_VENDOR_ID                     43
#define LPI2C_IP[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_MODULE_ID                     255
#define LPI2C_IP[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_AR_RELEASE_MAJOR_VERSION      4
#define LPI2C_IP[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_AR_RELEASE_MINOR_VERSION      7
#define LPI2C_IP[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_AR_RELEASE_REVISION_VERSION   0
#define LPI2C_IP[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_SW_MAJOR_VERSION              3
#define LPI2C_IP[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_SW_MINOR_VERSION              0
#define LPI2C_IP[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_SW_PATCH_VERSION              0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and Lpi2c_Ip[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg.h header file are of the same vendor */
#if (LPI2C_IP[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_VENDOR_ID != LPI2C_IP_TYPES_VENDOR_ID)
    #error "Lpi2c_Ip[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg.h and Lpi2c_Ip_Types.h have different vendor ids"
#endif

/* Check if current file and Lpi2c_Ip[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg.h header file are of the same Autosar version */
#if ((LPI2C_IP[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_AR_RELEASE_MAJOR_VERSION    != LPI2C_IP_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (LPI2C_IP[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_AR_RELEASE_MINOR_VERSION    != LPI2C_IP_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (LPI2C_IP[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_AR_RELEASE_REVISION_VERSION != LPI2C_IP_TYPES_AR_RELEASE_REVISION_VERSION))
     #error "AUTOSAR Version Numbers of Lpi2c_Ip[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg.h and Lpi2c_Ip_Types.h are different"
#endif

/* Check if current file and Lpi2c_Ip[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg.h header file are of the same Software version */
#if ((LPI2C_IP[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_SW_MAJOR_VERSION != LPI2C_IP_TYPES_SW_MAJOR_VERSION) || \
     (LPI2C_IP[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_SW_MINOR_VERSION != LPI2C_IP_TYPES_SW_MINOR_VERSION) || \
     (LPI2C_IP[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_SW_PATCH_VERSION != LPI2C_IP_TYPES_SW_PATCH_VERSION))
    #error "Software Version Numbers of Lpi2c_Ip[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg.h and Lpi2c_Ip_Types.h are different"
#endif

/*==================================================================================================
*                         LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
*                                      LOCAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/

/*==================================================================================================
*                                      LOCAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                      GLOBAL CONSTANTS
==================================================================================================*/

#define I2C_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "I2c_MemMap.h"

[!NOCODE!][!//
[!VAR "masterConfig" = "count(I2cGlobalConfig/I2cChannel/*[ contains(I2cHwChannel, 'LPI2C') and (I2cMasterSlaveConfiguration = 'MASTER_MODE') ])"!][!//
[!VAR "slaveConfig"  = "count(I2cGlobalConfig/I2cChannel/*[ contains(I2cHwChannel, 'LPI2C') and (I2cMasterSlaveConfiguration = 'SLAVE_MODE')  ])"!][!//

[!ENDNOCODE!][!//

#define LPI2C_IP_NUM_MASTER_INSTANCES_USED[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!] [!"num:i($masterConfig)"!]U
#define LPI2C_IP_NUM_SLAVE_INSTANCES_USED[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]  [!"num:i($slaveConfig)"!]U

[!NOCODE!][!//

[!LOOP "I2cGlobalConfig/I2cChannel/*"!] /* Loop through all configured channels */
    [!IF "contains(I2cHwChannel,'LPI2C')"!] /* Select only LPI2C channels */
        [!IF "contains(I2cMasterSlaveConfiguration,'MASTER')"!] /* Based on the master-slave configuration other structures will be generated */

[!CODE!]

/* Channel configuration for channel [!"I2cHwChannel"!] - configured as master */
extern const Lpi2c_Ip_MasterConfigType I2c_Lpi2cMasterChannel[!"I2cChannelId"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!];

[!ENDCODE!]
        [!ELSE!] /* This is a slave channel */

[!CODE!]

/* Channel configuration for channel [!"I2cHwChannel"!] - configured as slave */
extern const Lpi2c_Ip_SlaveConfigType I2c_Lpi2cSlaveChannel[!"I2cChannelId"!]Config[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!];
[!ENDCODE!]
        [!ENDIF!] /* End of master-slave if */
    [!ENDIF!] /* End of Select only LPI2C channels */
[!ENDLOOP!] /* End of the loop */

[!ENDNOCODE!][!//

#define I2C_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "I2c_MemMap.h"

/*==================================================================================================
*                                      GLOBAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                  LOCAL FUNCTION PROTOTYPES
==================================================================================================*/

/*==================================================================================================
*                                      LOCAL FUNCTIONS
==================================================================================================*/

/*==================================================================================================
*                                      GLOBAL FUNCTIONS
==================================================================================================*/


#ifdef __cplusplus
}
#endif

/** @} */

#endif /* LPI2C_IP[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_H */

