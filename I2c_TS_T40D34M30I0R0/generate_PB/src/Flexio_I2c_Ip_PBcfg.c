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
*   @addtogroup FLEXIO_I2C_DRIVER_CONFIGURATION Flexio_I2c Driver Configurations
*   @{
*/

#ifdef __cplusplus
extern "C"
{
#endif


/*==================================================================================================
                                         INCLUDE FILES
 1) system and project includes
 2) needed interfaces from external units
 3) internal and external interfaces from this unit
==================================================================================================*/
[!IF "(GeneralConfiguration/I2cDmaUsed='true')"!]
    [!CODE!]#include "Dma_Ip_Cfg.h"[!ENDCODE!]
[!ENDIF!]
#include "Flexio_I2c_Ip[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define FLEXIO_I2C_IP[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_VENDOR_ID_C                     43
#define FLEXIO_I2C_IP[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_MODULE_ID_C                     255
#define FLEXIO_I2C_IP[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_AR_RELEASE_MAJOR_VERSION_C      4
#define FLEXIO_I2C_IP[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_AR_RELEASE_MINOR_VERSION_C      7
#define FLEXIO_I2C_IP[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_AR_RELEASE_REVISION_VERSION_C   0
#define FLEXIO_I2C_IP[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_SW_MAJOR_VERSION_C              3
#define FLEXIO_I2C_IP[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_SW_MINOR_VERSION_C              0
#define FLEXIO_I2C_IP[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_SW_PATCH_VERSION_C              0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/

[!IF "(GeneralConfiguration/I2cDmaUsed='true')"!]
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if current file and Dma_Ip_Cfg.h header file are of the same Autosar version */
    #if ((FLEXIO_I2C_IP[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_AR_RELEASE_MAJOR_VERSION_C != DMA_IP_CFG_AR_RELEASE_MAJOR_VERSION) || \
        (FLEXIO_I2C_IP[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_AR_RELEASE_MINOR_VERSION_C != DMA_IP_CFG_AR_RELEASE_MINOR_VERSION) || \
        (FLEXIO_I2C_IP[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_AR_RELEASE_REVISION_VERSION_C != DMA_IP_CFG_AR_RELEASE_REVISION_VERSION) \
        )
        #error "AutoSar Version Numbers of Flexio_I2c_Ip[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg.c and Dma_Ip_Cfg.h are different"
    #endif
#endif /* DISABLE_MCAL_INTERMODULE_ASR_CHECK */
[!ENDIF!]

/* Check if current file and Flexio_I2c_Ip[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg.h header file are of the same vendor */
#if (FLEXIO_I2C_IP[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_VENDOR_ID_C != FLEXIO_I2C_IP[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_VENDOR_ID )
    #error "Flexio_I2c_Ip[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg.c and Flexio_I2c_Ip[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg.h have different vendor ids"
#endif

/* Check if current file and Flexio_I2c_Ip[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg.h header file are of the same Autosar version */
#if ((FLEXIO_I2C_IP[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_AR_RELEASE_MAJOR_VERSION_C != FLEXIO_I2C_IP[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_AR_RELEASE_MAJOR_VERSION) || \
     (FLEXIO_I2C_IP[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_AR_RELEASE_MINOR_VERSION_C != FLEXIO_I2C_IP[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_AR_RELEASE_MINOR_VERSION) || \
     (FLEXIO_I2C_IP[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_AR_RELEASE_REVISION_VERSION_C != FLEXIO_I2C_IP[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Flexio_I2c_Ip[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg.c and Flexio_I2c_Ip[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg.h are different"
#endif

/* Check if current file and Flexio_I2c_Ip[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg.h header file are of the same Software version */
#if ((FLEXIO_I2C_IP[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_SW_MAJOR_VERSION_C != FLEXIO_I2C_IP[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_SW_MAJOR_VERSION) || \
     (FLEXIO_I2C_IP[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_SW_MINOR_VERSION_C != FLEXIO_I2C_IP[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_SW_MINOR_VERSION) || \
     (FLEXIO_I2C_IP[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_SW_PATCH_VERSION_C != FLEXIO_I2C_IP[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_SW_PATCH_VERSION ) \
    )
    #error "Software Version Numbers of Flexio_I2c_Ip[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg.c and Flexio_I2c_Ip[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg.h are different"
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
[!IF "(GeneralConfiguration/I2cFlexIOUsed='true')"!]
#define I2C_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "I2c_MemMap.h"

[!NOCODE!][!//
[!VAR "masterStateIdx" = "0"!]
[!VAR "slaveStateIdx" = "0"!]
[!LOOP "I2cGlobalConfig/I2cChannel/*"!] /* Loop through all configured channels */
    [!IF "contains(I2cHwChannel,'FLEXIO')"!] /* Select only FLEXIO_I2C channels */
        [!IF "contains(I2cMasterSlaveConfiguration,'MASTER')"!] /* Based on the master-slave configuration other structures will be generated */
[!CODE!]

/* Channel configuration for channel [!"I2cHwChannel"!] - configured as master */
Flexio_I2c_Ip_MasterConfigType Flexio_I2cMasterChannel[!"I2cChannelId"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!] =
{
[!VAR "SclTimerId" = "num:i(substring-before(substring-after(node:value(I2cHwChannel),'FLEXIO_0_CH_'),'_'))"!][!//
[!VAR "CtlTimerId" = "num:i(substring-after(substring-after(node:value(I2cHwChannel),'FLEXIO_0_CH_'),'_'))"!][!//
[!VAR "instanceId" = "num:i(substring-before(substring-after(node:value(I2cHwChannel),'FLEXIO_'),'_'))"!][!//
[!VAR "SclPinId" = "num:i(substring-after(node:value(node:ref(I2cFlexIOConfiguration/SclFlexioRef)/FlexioMclPinId), '_'))"!][!//
[!VAR "SdaPinId" = "num:i(substring-after(node:value(node:ref(I2cFlexIOConfiguration/SdaFlexioRef)/FlexioMclPinId), '_'))"!][!//
[!IF "node:exists(I2cFlexIOConfiguration/I2cTimerDmaRef)"!]
[!VAR "TimerChannelDMA" = "node:value(node:ref(I2cFlexIOConfiguration/I2cTimerDmaRef)/dmaLogicChannel_LogicName)"!][!//
[!VAR "TimerScl" = "num:i(substring-after(node:value(node:ref(I2cFlexIOConfiguration/SclFlexioRef)/FlexioMclAddChannelId), '_'))"!][!//
[!VAR "TimerControl" = "num:i(substring-after(node:value(node:ref(I2cFlexIOConfiguration/SdaFlexioRef)/FlexioMclAddChannelId), '_'))"!][!//
[!ENDIF!]
    /* Slave address */
    0U,
    /* Transfer Type */
    [!"I2cFlexIOConfiguration/I2cAsyncMethod"!],
    /* Baud rate in hertz */
    (uint32)[!"I2cFlexIOConfiguration/I2cBaudRate"!],
    /* I2c flexio compare value */
    [!"I2cFlexIOConfiguration/I2cFlexIOCompareValue"!],
    /* I2cFlexIOChannelPrescaler */
[!IF "node:exists(I2cFlexIOConfiguration/I2cFlexIOChannelPrescaler)"!]
    FLEXIO_TMR_DECREMENT_ON_FLEXIO_CLK_[!"I2cFlexIOConfiguration/I2cFlexIOChannelPrescaler"!],
[!ELSE!]
    FLEXIO_TMR_DECREMENT_ON_FLEXIO_CLK_DIV_1,
[!ENDIF!]
    /* I2c flexio sda pin */
    [!"num:i($SdaPinId)"!]U,
    /* I2c flexio scl pin */
    [!"num:i($SclPinId)"!]U,
    /* Master Callback */
    NULL_PTR,
    /* I2c Master Callback Parameter */
    [!"I2cChannelId"!]U,
    /* FlexIO device instance number */
    [!"num:i($instanceId)"!]U,
    /* Index of first used internal resource instance (shifter and timer) */
    [!"num:i($SclTimerId)"!]U,
[!IF "node:exists(I2cFlexIOConfiguration/I2cTimerDmaRef)"!][!//
    /* Channel DMA using for Timer*/
    [!"$TimerChannelDMA"!],
    [!"$TimerScl"!],
    [!"$TimerControl"!],
[!ENDIF!][!//
    [!IF "I2cFlexIOConfiguration/I2cAsyncMethod = 'FLEXIO_I2C_USING_DMA'"!]
    [!"node:value(node:ref(I2cFlexIOConfiguration/I2cDmaRxChannelRef)/dmaLogicChannel_LogicName)"!],
    [!"node:value(node:ref(I2cFlexIOConfiguration/I2cDmaTxChannelRef)/dmaLogicChannel_LogicName)"!],
    [!ELSE!]
    /* DMA rx channel */
    0U,
    /* DMA tx channel */
    0U,
    [!ENDIF!]
    /* Master state index */
    [!"num:i($masterStateIdx)"!]U
};
    [!VAR "masterStateIdx" = "num:i($masterStateIdx)+1"!]
[!ENDCODE!]
        [!ENDIF!] /* End of master-slave if */
    [!ENDIF!] /* End of Select only FLEXIO_I2C channels */
[!ENDLOOP!] /* End of the loop */

[!ENDNOCODE!][!//

#define I2C_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "I2c_MemMap.h"
[!ENDIF!]
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

