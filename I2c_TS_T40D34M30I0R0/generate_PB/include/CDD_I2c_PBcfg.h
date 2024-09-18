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
/*==================================================================================================
==================================================================================================*/

/**
*   @file
*
*   @addtogroup I2C_DRIVER_CONFIGURATION I2c Driver Configurations
*   @{
*/

#ifndef CDD_I2C[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_H
#define CDD_I2C[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_H

#ifdef __cplusplus
extern "C"
{
#endif


/**
* @page misra_violations MISRA-C:2012 violations
*
* @section [global]
* Violates MISRA 2012 Required Rule 5.1, External identifiers shall be distinct.
* The used compilers use more than 31 chars for identifiers.
*
* @section [global]
* Violates MISRA 2012 Required Rule 5.2, Identifiers declared in the same scope and name space shall be distinct.
* The used compilers use more than 31 chars for identifiers.
*
* @section [global]
* Violates MISRA 2012 Required Rule 5.4, Macro identifiers shall be distinct.
* The used compilers use more than 31 chars for identifiers.
*
* @section [global]
* Violates MISRA 2012 Required Rule 5.5, Identifiers shall be distinct from macro names.
* The used compilers use more than 31 chars for identifiers.
*
*/

/*==================================================================================================
*                                          INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/

/*==================================================================================================
*                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define I2C[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_VENDOR_ID                     43
#define I2C[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_MODULE_ID                     255
#define I2C[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_AR_RELEASE_MAJOR_VERSION      4
#define I2C[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_AR_RELEASE_MINOR_VERSION      7
#define I2C[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_AR_RELEASE_REVISION_VERSION   0
#define I2C[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_SW_MAJOR_VERSION              3
#define I2C[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_SW_MINOR_VERSION              0
#define I2C[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_SW_PATCH_VERSION              0

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/

/*==================================================================================================
*                                            CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/
[!NOCODE!]
[!IF "variant:size()>1"!][!//
[!CODE!]
/**
* @brief          Link I2c channels symbolic names with I2c channel IDs.
* @details        Link I2c channels symbolic names with I2c channel IDs.
*
* @api
*/
[!ENDCODE!]
[!FOR "index" = "0" TO "num:i(ecu:get('I2c.I2cGlobalConfig.I2cChannel'))-1"!]
    [!VAR "I2cEcuHwChannel" = "string((ecu:list('I2c.I2cGlobalConfig.I2cChannel.I2cHwChannel'))[$index+1])"!]
    [!VAR "ChannelFound" = "0"!]
    [!LOOP "I2cGlobalConfig/I2cChannel/*"!]
        [!VAR "HardwareChannel" = "string(I2cHwChannel)"!]
        [!IF "$I2cEcuHwChannel = $HardwareChannel"!]
            [!IF "$ChannelFound = 0"!]
                [!CODE!]
#ifndef I2C_[!"$I2cEcuHwChannel"!]
    #define I2C_[!"$I2cEcuHwChannel"!]   [!"num:i($index)"!]U
#endif[!//
                [!ENDCODE!]
                [!VAR "ChannelFound" = "1"!]
            [!ENDIF!]
        [!ENDIF!]
    [!ENDLOOP!]
[!ENDFOR!]
[!ENDIF!]
[!ENDNOCODE!]

/*==================================================================================================
*                                              ENUMS
==================================================================================================*/

/*==================================================================================================
*                                  STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
*                                  GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/
[!NOCODE!]
[!IF "not(IMPLEMENTATION_CONFIG_VARIANT !='VariantPostBuild' and (variant:size()<=1))"!] [!//
[!IF "var:defined('postBuildVariant')"!][!//
  [!VAR "postBuildVariantNameUnderscore" = "concat('_',$postBuildVariant)"!][!//
[!CODE!]#define I2C_CONFIG_[!"$postBuildVariant"!]_PB \[!CR!][!ENDCODE!]
[!ELSE!][!//
  [!VAR "postBuildVariantNameUnderscore" = "string(null)"!][!//
[!CODE!]#define I2C_CONFIG_PB \[!CR!][!ENDCODE!]
[!ENDIF!][!//
[!VAR "I2cConfiguredPartitions" = "num:i(count(I2cGlobalConfig/I2cEcucPartitionRef/*))"!][!//
    [!IF "$I2cConfiguredPartitions > 0"!][!//
        [!VAR "PartitionIndex" = "0"!][!//
        [!LOOP "I2cGlobalConfig/I2cEcucPartitionRef/*"!][!//
            [!VAR "PartitionIndex"="$PartitionIndex + 1"!][!//
            [!VAR "currentPartition" = "substring-after(substring-after(substring-after(substring-after(.,'/'),'/'),'/'),'/')"!][!//
            [!CODE!][!WS4!]extern const I2c_ConfigType I2c_Config[!"$postBuildVariantNameUnderscore"!]_[!"$currentPartition"!];[!IF "$PartitionIndex < $I2cConfiguredPartitions"!]\[!ENDIF!][!CR!][!ENDCODE!]
        [!ENDLOOP!][!//
    [!ELSE!][!//
            [!CODE!][!WS4!]extern const I2c_ConfigType I2c_Config[!"$postBuildVariantNameUnderscore"!];[!CR!][!ENDCODE!]
    [!ENDIF!][!//
[!ENDIF!]
[!ENDNOCODE!]

/*==================================================================================================
*                                       FUNCTION PROTOTYPES
==================================================================================================*/


#ifdef __cplusplus
}
#endif

/** @} */

#endif /* #ifndef CDD_I2C[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_H */

