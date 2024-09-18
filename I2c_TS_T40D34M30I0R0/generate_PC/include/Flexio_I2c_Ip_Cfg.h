[!NOCODE!][!//
[!//
[!MACRO "MacroPrint", "TextToPrint" = "''""!][!//
[!CODE!][!"$TextToPrint"!][!CR!][!ENDCODE!][!//
[!ENDMACRO!][!//
[!//
[!MACRO "MacroGenerateNumberInstance", "InstanceType" = "''""!][!//
[!NOCODE!][!//

[!CALL "MacroPrint", "TextToPrint" = "concat('#define FLEXIO_I2C_IP_NUMBER_OF_', $InstanceType, '_CHANNEL \')"!]

[!VAR "LastLine" = "'    0'"!]
[!LOOP "variant:all()"!][!//
    [!CALL "MacroPrint", "TextToPrint" = "concat('    FLEXIO_I2C_IP_MAX(FLEXIO_I2C_IP_NUM_', $InstanceType, '_USED_', (.), ', \')"!]
    [!VAR "LastLine" = "concat($LastLine, ' )')"!]
[!ENDLOOP!][!//

[!CALL "MacroPrint", "TextToPrint" = "$LastLine"!]

[!ENDNOCODE!][!//
[!ENDMACRO!][!//
[!//
[!ENDNOCODE!]
[!//
/*==================================================================================================
*   Project              : RTD AUTOSAR 4.7
*   Platform             : CORTEXM
*   Peripheral           : LPI2C
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

#ifndef FLEXIO_I2C_IP_CFG_H
#define FLEXIO_I2C_IP_CFG_H

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
*                                          INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
[!NOCODE!][!//
[!IF "var:defined('postBuildVariant')"!]
[!LOOP "variant:all()"!]
[!CODE!]#include "Flexio_I2c_Ip_[!"."!]_PBcfg.h"[!CR!][!ENDCODE!]
[!ENDLOOP!]
[!ELSE!]
[!CODE!]#include "Flexio_I2c_Ip_PBcfg.h"[!CR!][!ENDCODE!]
[!ENDIF!]
[!ENDNOCODE!][!//

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define FLEXIO_I2C_IP_CFG_VENDOR_ID                     43
#define FLEXIO_I2C_IP_CFG_MODULE_ID                     255
#define FLEXIO_I2C_IP_CFG_AR_RELEASE_MAJOR_VERSION      4
#define FLEXIO_I2C_IP_CFG_AR_RELEASE_MINOR_VERSION      7
#define FLEXIO_I2C_IP_CFG_AR_RELEASE_REVISION_VERSION   0
#define FLEXIO_I2C_IP_CFG_SW_MAJOR_VERSION              3
#define FLEXIO_I2C_IP_CFG_SW_MINOR_VERSION              0
#define FLEXIO_I2C_IP_CFG_SW_PATCH_VERSION              0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/

[!IF "var:defined('postBuildVariant')"!][!//
[!LOOP "variant:all()"!][!//
/* Check if current file and Flexio_I2c_Ip_[!"."!]_PBcfg.h header file are of the same vendor */
#if (FLEXIO_I2C_IP_CFG_VENDOR_ID != FLEXIO_I2C_IP_[!"text:toupper(.)"!]_PBCFG_VENDOR_ID)
    #error "Flexio_I2c_Ip_Cfg.h and Flexio_I2c_Ip_[!"."!]_PBcfg.h have different vendor IDs"
#endif

/* Check if current file and Flexio_I2c_Ip_[!"."!]_PBcfg.h header file are of the same Autosar version */
#if ((FLEXIO_I2C_IP_CFG_AR_RELEASE_MAJOR_VERSION     != FLEXIO_I2C_IP_[!"text:toupper(.)"!]_PBCFG_AR_RELEASE_MAJOR_VERSION) || \
     (FLEXIO_I2C_IP_CFG_AR_RELEASE_MINOR_VERSION     != FLEXIO_I2C_IP_[!"text:toupper(.)"!]_PBCFG_AR_RELEASE_MINOR_VERSION) || \
     (FLEXIO_I2C_IP_CFG_AR_RELEASE_REVISION_VERSION  != FLEXIO_I2C_IP_[!"text:toupper(.)"!]_PBCFG_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Flexio_I2c_Ip_Cfg.h and Flexio_I2c_Ip_[!"."!]_PBcfg.h are different"
#endif

/* Check if current file and Flexio_I2c_Ip_[!"."!]_PBcfg.h header file are of the same software version */
#if ((FLEXIO_I2C_IP_CFG_SW_MAJOR_VERSION != FLEXIO_I2C_IP_[!"text:toupper(.)"!]_PBCFG_SW_MAJOR_VERSION) || \
     (FLEXIO_I2C_IP_CFG_SW_MINOR_VERSION != FLEXIO_I2C_IP_[!"text:toupper(.)"!]_PBCFG_SW_MINOR_VERSION) || \
     (FLEXIO_I2C_IP_CFG_SW_PATCH_VERSION != FLEXIO_I2C_IP_[!"text:toupper(.)"!]_PBCFG_SW_PATCH_VERSION))
    #error "Software Version Numbers of Flexio_I2c_Ip_Cfg.h and Flexio_I2c_Ip_[!"."!]_PBcfg.h are different"
#endif
[!ENDLOOP!][!//
[!ELSE!][!//
/* Check if current file and Flexio_I2c_Ip_PBcfg.h header file are of the same vendor */
#if (FLEXIO_I2C_IP_CFG_VENDOR_ID != FLEXIO_I2C_IP_PBCFG_VENDOR_ID)
    #error "Flexio_I2c_Ip_Cfg.h and Flexio_I2c_Ip_PBcfg.h have different vendor IDs"
#endif

/* Check if current file and Flexio_I2c_Ip_PBcfg.h header file are of the same Autosar version */
#if ((FLEXIO_I2C_IP_CFG_AR_RELEASE_MAJOR_VERSION     != FLEXIO_I2C_IP_PBCFG_AR_RELEASE_MAJOR_VERSION) || \
     (FLEXIO_I2C_IP_CFG_AR_RELEASE_MINOR_VERSION     != FLEXIO_I2C_IP_PBCFG_AR_RELEASE_MINOR_VERSION) || \
     (FLEXIO_I2C_IP_CFG_AR_RELEASE_REVISION_VERSION  != FLEXIO_I2C_IP_PBCFG_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Flexio_I2c_Ip_Cfg.h and Flexio_I2c_Ip_PBcfg.h are different"
#endif

/* Check if current file and Flexio_I2c_Ip_PBcfg.h header file are of the same software version */
#if ((FLEXIO_I2C_IP_CFG_SW_MAJOR_VERSION != FLEXIO_I2C_IP_PBCFG_SW_MAJOR_VERSION) || \
     (FLEXIO_I2C_IP_CFG_SW_MINOR_VERSION != FLEXIO_I2C_IP_PBCFG_SW_MINOR_VERSION) || \
     (FLEXIO_I2C_IP_CFG_SW_PATCH_VERSION != FLEXIO_I2C_IP_PBCFG_SW_PATCH_VERSION))
    #error "Software Version Numbers of Flexio_I2c_Ip_Cfg.h and Flexio_I2c_Ip_PBcfg.h are different"
#endif
[!ENDIF!][!//

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

/**
* @brief          FLEXIO Channel Used
*/
#define FLEXIO_I2C_IP_ENABLE   [!IF "(GeneralConfiguration/I2cFlexIOUsed='true')"!](STD_ON)[!ELSE!](STD_OFF)[!ENDIF!]

#if (FLEXIO_I2C_IP_ENABLE == STD_ON)

[!NOCODE!][!//
[!IF "var:defined('postBuildVariant')"!][!//
[!CODE!][!//
#define  FLEXIO_I2C_IP_MAX(a, b)          (((a) > (b)) ? (a) : (b))

[!CALL "MacroGenerateNumberInstance", "InstanceType" = "'MASTER'"!][!//

[!ENDCODE!][!//

[!ELSE!][!//

[!CODE!][!//
#define FLEXIO_I2C_IP_NUMBER_OF_MASTER_CHANNEL  FLEXIO_I2C_IP_NUM_MASTER_USED
[!ENDCODE!][!//

[!ENDIF!][!//
[!ENDNOCODE!][!//

[!IF "ecu:get('I2cUnifiedInterrupts') = 'TRUE'"!]
/**
* @brief   Unified Interrupt.
*/
#define FLEXIO_I2C_COMMON_IRQ_MASTER_AND_SLAVE
[!ENDIF!]

/**
* @brief            Error detection for IP layer
*/
#define FLEXIO_I2C_IP_DEV_ERROR_DETECT   [!IF "GeneralConfiguration/I2cDevErrorDetect"!](STD_ON)  /* Enable Development Error Detection for IP */[!ELSE!](STD_OFF) /* Disable Development Error Detection for IP */[!ENDIF!]

/**
* @brief            Error events of the i2c module enable/disabled
*/
#define FLEXIO_I2C_IP_EVENT_ERROR_DETECT   [!IF "node:exists(GeneralConfiguration/I2cErrorCallback)"!](STD_ON)  /* Enable Development Error Detection for IP */[!ELSE!](STD_OFF) /* Disable Development Error Detection for IP */[!ENDIF!]
/**
* @brief            Dma support enable/disabled
*/
#define FLEXIO_I2C_IP_DMA_FEATURE_AVAILABLE [!IF "GeneralConfiguration/I2cDmaUsed"!](STD_ON)  /* Enable DMA support for IP */[!ELSE!](STD_OFF) /* Disable DMA support for IP */[!ENDIF!]

/**
* @brief            Dma transfer error of the i2c module enable/disabled
*/
#define FLEXIO_I2C_IP_DMA_TRANSFER_ERROR_DETECT   [!IF "GeneralConfiguration/I2cDmaTransferErrorDetect"!](STD_ON)  /* Enable Dma Transfer Error Detection for IP */[!ELSE!](STD_OFF) /* Disable Dma Transfer Error Detection for IP */[!ENDIF!]

/**
* @brief            FLEXIO timeout type
*/
#define FLEXIO_I2C_IP_TIMEOUT_TYPE                ([!"GeneralConfiguration/I2cTimeoutMethod"!])
/**
* @brief            Enable User Mode Support.
*/
#define FLEXIO_I2C_IP_ENABLE_USER_MODE_SUPPORT   (STD_OFF) /* Disable User Mode support for IP */
/** Check the driver user mode is enabled only when the MCAL_ENABLE_USER_MODE_SUPPORT is enabled */
#ifndef MCAL_ENABLE_USER_MODE_SUPPORT
  #if (STD_ON == FLEXIO_I2C_IP_ENABLE_USER_MODE_SUPPORT)
    #error MCAL_ENABLE_USER_MODE_SUPPORT is not enabled. For running I2C in user mode, the MCAL_ENABLE_USER_MODE_SUPPORT macro needs to be defined.
  #endif /* (STD_ON == FLEXIO_I2C_IP_ENABLE_USER_MODE_SUPPORT) */
#endif /* ifndef MCAL_ENABLE_USER_MODE_SUPPORT */
#endif /* FLEXIO_I2C_IP_ENABLE == STD_ON */

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

#endif /* FLEXIO_I2C_IP_CFG_H */