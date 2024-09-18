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
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Lpi2c_Ip[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg.h"
#include "Mcal.h"

#if (STD_ON == LPI2C_IP_DMA_FEATURE_AVAILABLE)
#include "Dma_Ip_Cfg.h"
#endif

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define LPI2C_IP[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_VENDOR_ID_C                     43
#define LPI2C_IP[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_MODULE_ID_C                     255
#define LPI2C_IP[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_AR_RELEASE_MAJOR_VERSION_C      4
#define LPI2C_IP[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_AR_RELEASE_MINOR_VERSION_C      7
#define LPI2C_IP[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_AR_RELEASE_REVISION_VERSION_C   0
#define LPI2C_IP[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_SW_MAJOR_VERSION_C              3
#define LPI2C_IP[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_SW_MINOR_VERSION_C              0
#define LPI2C_IP[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_SW_PATCH_VERSION_C              0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/

/* Check if current file and I2c header file are of the same vendor */
#if (LPI2C_IP[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_VENDOR_ID_C != LPI2C_IP[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_VENDOR_ID)
    #error "Lpi2c_Ip[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg.c and Lpi2c_Ip[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg.h have different vendor ids"
#endif
/* Check if current file and I2c header file are of the same Autosar version */
#if ((LPI2C_IP[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_AR_RELEASE_MAJOR_VERSION_C != LPI2C_IP[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_AR_RELEASE_MAJOR_VERSION) || \
     (LPI2C_IP[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_AR_RELEASE_MINOR_VERSION_C != LPI2C_IP[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_AR_RELEASE_MINOR_VERSION) || \
     (LPI2C_IP[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_AR_RELEASE_REVISION_VERSION_C != LPI2C_IP[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Lpi2c_Ip[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg.c and Lpi2c_Ip[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg.h are different"
#endif
/* Check if current file and I2c header file are of the same Software version */
#if ((LPI2C_IP[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_SW_MAJOR_VERSION_C != LPI2C_IP[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_SW_MAJOR_VERSION) || \
     (LPI2C_IP[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_SW_MINOR_VERSION_C != LPI2C_IP[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_SW_MINOR_VERSION) || \
     (LPI2C_IP[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_SW_PATCH_VERSION_C != LPI2C_IP[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_SW_PATCH_VERSION))
    #error "Software Version Numbers of Lpi2c_Ip[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg.c and Lpi2c_Ip[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg.h are different"
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if (STD_ON == LPI2C_IP_DMA_FEATURE_AVAILABLE)
        /* Check if current file and Dma_Ip_Cfg header file are of the same Autosar version */
        #if ((LPI2C_IP[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_AR_RELEASE_MAJOR_VERSION_C != DMA_IP_CFG_AR_RELEASE_MAJOR_VERSION) || \
            (LPI2C_IP[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_AR_RELEASE_MINOR_VERSION_C != DMA_IP_CFG_AR_RELEASE_MINOR_VERSION))
            #error "AutoSar Version Numbers of Lpi2c_Ip[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg.c and Dma_Ip_Cfg are different"
        #endif
    #endif /* LPI2C_IP_DMA_FEATURE_AVAILABLE */
    /* Check if current file and Mcal.h header file are of the same Autosar version */
    #if ((LPI2C_IP[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_AR_RELEASE_MAJOR_VERSION_C != MCAL_AR_RELEASE_MAJOR_VERSION) || \
         (LPI2C_IP[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_AR_RELEASE_MINOR_VERSION_C != MCAL_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of Lpi2c_Ip[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg.c and Mcal.h are different"
    #endif
#endif /* DISABLE_MCAL_INTERMODULE_ASR_CHECK */

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
[!VAR "masterStateIdx" = "0"!]
[!VAR "slaveStateIdx" = "0"!]
[!LOOP "I2cGlobalConfig/I2cChannel/*"!] /* Loop through all configured channels */
    [!IF "contains(I2cHwChannel,'LPI2C')"!] /* Select only LPI2C channels */
        [!IF "contains(I2cMasterSlaveConfiguration,'MASTER')"!] /* Based on the master-slave configuration other structures will be generated */
[!CODE!]
/* Baud rate structure for channel [!"I2cHwChannel"!] */
static const Lpi2c_Ip_BaudRateType baudrateParams[!"I2cChannelId"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!] =
{
    [!"I2cMasterConfiguration/I2cPrescaler"!],    /* Prescaler */
    [!"I2cMasterConfiguration/I2cClockHighPeriod"!]U,    /* ClkHI */
    [!"I2cMasterConfiguration/I2cClockLowPeriod"!]U,    /* ClkLO */
    [!"I2cMasterConfiguration/I2cSetupHoldDelay"!]U,    /* Set Hold */
    [!"I2cMasterConfiguration/I2cDataValidDelay"!]U,    /* Data Valid */
    [!"I2cMasterConfiguration/I2cHighSpeedModeConfiguration/I2cClockHighPeriod"!]U,    /* ClkHI HS */
    [!"I2cMasterConfiguration/I2cHighSpeedModeConfiguration/I2cClockLowPeriod"!]U,    /* ClkLO HS */
    [!"I2cMasterConfiguration/I2cHighSpeedModeConfiguration/I2cSetupHoldDelay"!]U,    /* Set Hold HS */
    [!"I2cMasterConfiguration/I2cHighSpeedModeConfiguration/I2cDataValidDelay"!]U    /* Data Valid HS */
};

/* Channel configuration for channel [!"I2cHwChannel"!] - configured as master */
const Lpi2c_Ip_MasterConfigType I2c_Lpi2cMasterChannel[!"I2cChannelId"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!] =
{
    /* Slave address */
     0U,

    /*10-bit address */
    (boolean)FALSE,

    /* Operating Mode */
    [!"I2cOperatingMode"!],

    /* Baudrate parameters */
    &baudrateParams[!"I2cChannelId"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!],

    /* Pin Low Timeout */
    [!"I2cMasterConfiguration/I2cPinLowTimeout"!]U,

    /* Bus Idle Timeout */
    [!"I2cMasterConfiguration/I2cBusIdleTimeout"!]U,

    /* Glitch Filter SDA */
    [!"I2cMasterConfiguration/I2cGlitchFilterSDA"!]U,

    /* Glitch Filter SDA */
    [!"I2cMasterConfiguration/I2cGlitchFilterSCL"!]U,

    /* Master code */
    [!"I2cMasterConfiguration/I2cHighSpeedModeConfiguration/I2cMasterCode"!]U,

    /* Transfer Type */
    [!"I2cMasterConfiguration/I2cAsyncMethod"!],

    /* Dma Tx Channel */
    [!IF "I2cMasterConfiguration/I2cAsyncMethod = 'LPI2C_USING_DMA'"!]
    [!IF "node:exists(I2cMasterConfiguration/I2cDmaTxChannelRef)"!]
    [!"node:value(node:ref(I2cMasterConfiguration/I2cDmaTxChannelRef)/dmaLogicChannel_LogicName)"!],
    [!ENDIF!]
    [!ELSE!]
    0U,
    [!ENDIF!]
    /* Dma Rx Channel */
    [!IF "I2cMasterConfiguration/I2cAsyncMethod = 'LPI2C_USING_DMA'"!]
    [!IF "node:exists(I2cMasterConfiguration/I2cDmaRxChannelRef)"!]
    [!"node:value(node:ref(I2cMasterConfiguration/I2cDmaRxChannelRef)/dmaLogicChannel_LogicName)"!],
    [!ENDIF!]
    [!ELSE!]
    0U,
    [!ENDIF!]

    /* Master Callback */
    NULL_PTR,

    /* Master Callback Parameter */
    [!"I2cChannelId"!]U,

    /*  Master State index */
    [!"num:i($masterStateIdx)"!]U,
};
    [!VAR "masterStateIdx" = "num:i($masterStateIdx)+1"!]

[!ENDCODE!]
        [!ELSE!] /* This is a slave channel */
[!CODE!]
/* Channel configuration for channel [!"I2cHwChannel"!] - configured as slave */
const Lpi2c_Ip_SlaveConfigType I2c_Lpi2cSlaveChannel[!"I2cChannelId"!]Config[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!] =
{
    /* Slave Address */
    [!"I2cSlaveConfiguration/I2cSlaveAddress"!]U,

    /* Selects 7-bit or 10-bit address */
    (boolean)[!IF "I2cSlaveConfiguration/I2cSlaveIs10BitAddress = 'true'"!]TRUE[!ELSE!]FALSE[!ENDIF!],

    /* Slave mode */
    (boolean)[!IF "I2cSlaveConfiguration/Lpi2cSlaveListening = 'true'"!]TRUE[!ELSE!]FALSE[!ENDIF!],

    /* Operating Mode */
    [!"I2cOperatingMode"!],

    /* Transfer Type */
    [!"I2cSlaveConfiguration/I2cAsyncMethod"!],

    /* Glitch Filter SDA */
    [!"I2cSlaveConfiguration/I2cGlitchFilterSDA"!]U,

    /* Glitch Filter SCL */
    [!"I2cSlaveConfiguration/I2cGlitchFilterSCL"!]U,

    /* Dma Tx Channel */
    [!IF "I2cSlaveConfiguration/I2cAsyncMethod = 'LPI2C_USING_DMA'"!]
    [!IF "node:exists(I2cSlaveConfiguration/I2cSlaveDmaTxChannelRef)"!]
    [!"node:value(node:ref(I2cSlaveConfiguration/I2cSlaveDmaTxChannelRef)/dmaLogicChannel_LogicName)"!],
    [!ENDIF!]
    [!ELSE!]
    0U,
    [!ENDIF!]
    /* Dma Rx Channel */
    [!IF "I2cSlaveConfiguration/I2cAsyncMethod = 'LPI2C_USING_DMA'"!]
    [!IF "node:exists(I2cSlaveConfiguration/I2cSlaveDmaRxChannelRef)"!]
    [!"node:value(node:ref(I2cSlaveConfiguration/I2cSlaveDmaRxChannelRef)/dmaLogicChannel_LogicName)"!],
    [!ENDIF!]
    [!ELSE!]
    0U,
    [!ENDIF!]

    /* Slave Callback */
    NULL_PTR,

    /* Slave Callback Parameter*/
    [!"I2cChannelId"!]U,
    
    /*  Slave State index */
    [!"num:i($slaveStateIdx)"!]U
};
    [!VAR "slaveStateIdx" = "num:i($slaveStateIdx)+1"!]

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

