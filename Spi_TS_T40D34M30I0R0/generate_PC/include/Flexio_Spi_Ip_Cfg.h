/*==================================================================================================
*   Project              : RTD AUTOSAR 4.7
*   Platform             : CORTEXM
*   Peripheral           : LPSPI
*   Dependencies         : 
*
*   Autosar Version      : 4.7.0
*   Autosar Revision     : ASR_REL_4_7_REV_0000
*   Autosar Conf.Variant :
*   SW Version           : 3.0.0
*   Build Version        : S32K3_RTD_3_0_0_D2303_ASR_REL_4_7_REV_0000_20230331
*
*   Copyright 2020 - 2023 NXP Semiconductors NXP
*
*   NXP Confidential. This software is owned or controlled by NXP and may only be
*   used strictly in accordance with the applicable license terms. By expressly
*   accepting such terms or by downloading, installing, activating and/or otherwise
*   using the software, you are agreeing that you have read, and that you agree to
*   comply with and are bound by, such license terms. If you do not agree to be
*   bound by the applicable license terms, then you may not retain, install,
*   activate or otherwise use the software.
==================================================================================================*/
[!CODE!][!//

#ifndef FLEXIO_SPI_IP_CFG_H
#define FLEXIO_SPI_IP_CFG_H

/**
*   @file     Flexio_Spi_Ip_Cfg.h
*   @version 3.0.0
*
*   @brief   AUTOSAR Spi - Spi configuration header file.
*   @details This file is the header containing all the necessary information for SPI
*            module configuration(s).
*   @addtogroup FLEXIO_DRIVER_CONFIGURATION  Flexio_Spi Driver Configuration
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
* 4) user callback header files
==================================================================================================*/
#include "Mcal.h"
#include "OsIf.h"
[!IF "var:defined('postBuildVariant')"!]
[!LOOP "variant:all()"!][!//
#include "Flexio_Spi_Ip_[!"."!]_PBcfg.h"
[!ENDLOOP!][!//
[!ELSE!]
#include "Flexio_Spi_Ip_PBcfg.h"
[!ENDIF!]
#include "[!"ecu:get('Spi.SpiHeaderNameFLEXIO')"!].h"
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/

#define FLEXIO_SPI_IP_VENDOR_ID_CFG                       43
#define FLEXIO_SPI_IP_AR_RELEASE_MAJOR_VERSION_CFG        4
#define FLEXIO_SPI_IP_AR_RELEASE_MINOR_VERSION_CFG        7
#define FLEXIO_SPI_IP_AR_RELEASE_REVISION_VERSION_CFG     0
#define FLEXIO_SPI_IP_SW_MAJOR_VERSION_CFG                3
#define FLEXIO_SPI_IP_SW_MINOR_VERSION_CFG                0
#define FLEXIO_SPI_IP_SW_PATCH_VERSION_CFG                0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if current file and Mcal header file are of the same Autosar version */
    #if ((FLEXIO_SPI_IP_AR_RELEASE_MAJOR_VERSION_CFG != MCAL_AR_RELEASE_MAJOR_VERSION) || \
         (FLEXIO_SPI_IP_AR_RELEASE_MINOR_VERSION_CFG != MCAL_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of Flexio_Spi_Ip_Cfg.h and Mcal.h are different"
    #endif

    /* Check if current file and OsIf header file are of the same Autosar version */
    #if ((FLEXIO_SPI_IP_AR_RELEASE_MAJOR_VERSION_CFG != OSIF_AR_RELEASE_MAJOR_VERSION) || \
         (FLEXIO_SPI_IP_AR_RELEASE_MINOR_VERSION_CFG != OSIF_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of Flexio_Spi_Ip_Cfg.h and OsIf.h are different"
    #endif
#endif

[!IF "var:defined('postBuildVariant')"!]
[!LOOP "variant:all()"!]
/* Check if Flexio_Spi_Ip_[!"."!]_PBcfg header file and Spi configuration header file are of the same vendor */
#if (FLEXIO_SPI_IP_[!"."!]_VENDOR_ID_PBCFG != FLEXIO_SPI_IP_VENDOR_ID_CFG)
    #error "Flexio_Spi_Ip_[!"."!]_PBcfg.h and Flexio_Spi_Ip_Cfg.h have different vendor IDs"
#endif
    /* Check if Flexio_Spi_Ip_[!"."!]_PBcfg header file and Spi  configuration header file are of the same Autosar version */
#if ((FLEXIO_SPI_IP_[!"."!]_AR_RELEASE_MAJOR_VERSION_PBCFG != FLEXIO_SPI_IP_AR_RELEASE_MAJOR_VERSION_CFG) || \
     (FLEXIO_SPI_IP_[!"."!]_AR_RELEASE_MINOR_VERSION_PBCFG != FLEXIO_SPI_IP_AR_RELEASE_MINOR_VERSION_CFG) || \
     (FLEXIO_SPI_IP_[!"."!]_AR_RELEASE_REVISION_VERSION_PBCFG != FLEXIO_SPI_IP_AR_RELEASE_REVISION_VERSION_CFG))
#error "AutoSar Version Numbers of Flexio_Spi_Ip_[!"."!]_PBcfg.h and Flexio_Spi_Ip_Cfg.h are different"
#endif
/* Check if Flexio_Spi_Ip_[!"."!]_PBcfg header file and Spi configuration header file are of the same software version */
#if ((FLEXIO_SPI_IP_[!"."!]_SW_MAJOR_VERSION_PBCFG != FLEXIO_SPI_IP_SW_MAJOR_VERSION_CFG) || \
     (FLEXIO_SPI_IP_[!"."!]_SW_MINOR_VERSION_PBCFG != FLEXIO_SPI_IP_SW_MINOR_VERSION_CFG) || \
     (FLEXIO_SPI_IP_[!"."!]_SW_PATCH_VERSION_PBCFG != FLEXIO_SPI_IP_SW_PATCH_VERSION_CFG))
#error "Software Version Numbers of Flexio_Spi_Ip_[!"."!]_PBcfg.h and Flexio_Spi_Ip_Cfg.h are different"
#endif
[!ENDLOOP!]

[!ELSE!]
/* Check if Flexio_Spi_Ip_PBcfg header file and Spi configuration header file are of the same vendor */
#if (FLEXIO_SPI_IP_VENDOR_ID_PBCFG != FLEXIO_SPI_IP_VENDOR_ID_CFG)
    #error "Flexio_Spi_Ip_PBcfg.h and Flexio_Spi_Ip_Cfg.h have different vendor IDs"
#endif
    /* Check if Flexio_Spi_Ip_PBcfg header file and Spi  configuration header file are of the same Autosar version */
#if ((FLEXIO_SPI_IP_AR_RELEASE_MAJOR_VERSION_PBCFG != FLEXIO_SPI_IP_AR_RELEASE_MAJOR_VERSION_CFG) || \
     (FLEXIO_SPI_IP_AR_RELEASE_MINOR_VERSION_PBCFG != FLEXIO_SPI_IP_AR_RELEASE_MINOR_VERSION_CFG) || \
     (FLEXIO_SPI_IP_AR_RELEASE_REVISION_VERSION_PBCFG != FLEXIO_SPI_IP_AR_RELEASE_REVISION_VERSION_CFG))
#error "AutoSar Version Numbers of Flexio_Spi_Ip_PBcfg.h and Flexio_Spi_Ip_Cfg.h are different"
#endif
/* Check if Flexio_Spi_Ip_PBcfg header file and Spi configuration header file are of the same software version */
#if ((FLEXIO_SPI_IP_SW_MAJOR_VERSION_PBCFG != FLEXIO_SPI_IP_SW_MAJOR_VERSION_CFG) || \
     (FLEXIO_SPI_IP_SW_MINOR_VERSION_PBCFG != FLEXIO_SPI_IP_SW_MINOR_VERSION_CFG) || \
     (FLEXIO_SPI_IP_SW_PATCH_VERSION_PBCFG != FLEXIO_SPI_IP_SW_PATCH_VERSION_CFG))
#error "Software Version Numbers of Flexio_Spi_Ip_PBcfg.h and Flexio_Spi_Ip_Cfg.h are different"
#endif
[!ENDIF!]
/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/
/**
* @brief Flexio SPI supported enable.
* @details Flexio SPI supported enable. 
*/
#define FLEXIO_SPI_IP_ENABLE [!//
[!IF "SpiAutosarExt/SpiFlexioEnable"!][!//
    (STD_ON)
[!ELSE!][!//
    (STD_OFF)
[!ENDIF!][!//

#if (FLEXIO_SPI_IP_ENABLE == STD_ON)
#define FLEXIO_SPI_IP_CONFIG_EXT \
[!IF "var:defined('postBuildVariant')"!][!//
[!LOOP "variant:all()"!][!//
[!WS8!]FLEXIO_SPI_IP_CONFIG_[!"."!]_PB \
[!ENDLOOP!][!//
[!ELSE!][!//
[!WS8!]FLEXIO_SPI_IP_CONFIG_PB
[!ENDIF!]

[!NOCODE!][!//
[!VAR "HWtypeFlexio" = "0"!]
[!LOOP "SpiGeneral/SpiPhyUnit/*"!]
[!IF "contains(node:value(SpiPhyUnitMapping),'FLEXIO_SPI')"!]
    [!VAR "HWtypeFlexio" = "$HWtypeFlexio + 1"!]
[!ENDIF!]
[!ENDLOOP!]
[!IF "num:i($HWtypeFlexio) = 0"!]
    [!VAR "HWtypeFlexio" = "1"!]
[!ENDIF!]
[!ENDNOCODE!][!//
/** @brief Total number of SpiPhyUnit configured. */
#define FLEXIO_SPI_IP_NUMBER_OF_INSTANCES           ([!"num:i($HWtypeFlexio)"!]U)

/** @brief Total number of FLEXIO_SPI HW Unit are supported . */
#define FLEXIO_SPI_IP_NUMBER_OF_HWUNIT_U8         (uint8)([!"ecu:get('Spi.MaxFlexioInstanceSupported')"!]U)

/** @brief Total number of Flexio instance. */
#define FLEXIO_SPI_IP_INSTANCE_COUNT           (FLEXIO_INSTANCE_COUNT)

/** @brief HWUnits enabled/disabled */
[!NOCODE!]
[!VAR "SlaveSupport" = "'false'"!]
[!LOOP "SpiGeneral/SpiPhyUnit/*"!][!//
[!IF "contains(node:value(SpiPhyUnitMapping),'FLEXIO_SPI')"!]
    [!VAR "unit"="substring-after(SpiPhyUnitMapping,'SPI')"!]
    [!CODE!]
#define FLEXIO_SPI_IP[!"$unit"!]_ENABLED  (STD_ON)
    [!ENDCODE!]
    [!IF "SpiPhyUnitMode = 'SPI_SLAVE'"!]
        [!VAR "SlaveSupport" = "'true'"!]
    [!ENDIF!]
[!ENDIF!]
[!ENDLOOP!]
[!CODE!]
#define FLEXIO_SPI_IP_SLAVE_SUPPORT  ([!IF "$SlaveSupport = 'true'"!](STD_ON)[!ELSE!](STD_OFF)[!ENDIF!])
[!ENDCODE!]
[!ENDNOCODE!]

/**
* @brief Defines if transfers are made using DMA or FIFO.
* @details Defines if transfers are made using DMA or FIFO.
*/
#define FLEXIO_SPI_IP_DMA_USED [!//
[!IF "ecu:get('Spi.SpiDMAPresent') = 'TRUE' and SpiGeneral/SpiGlobalDmaEnable = 'true'"!][!//
    (STD_ON)
[!ELSE!][!//
    (STD_OFF)
[!ENDIF!][!//

/**
* @brief If enabled, allows dual MCU clock configuration settings.
* @details If enabled, allows dual MCU clock configuration settings.
*/
[!NOCODE!][!//
[!VAR "DualClockSupport"= "'false'"!]
[!LOOP "SpiGeneral/SpiPhyUnit/*"!][!//
    [!IF "(node:exists(SpiPhyUnitAlternateClockRef))"!][!//
        [!VAR "DualClockSupport"= "'true'"!]
    [!ENDIF!][!//
[!ENDLOOP!][!//
[!ENDNOCODE!][!//
#define FLEXIO_SPI_IP_DUAL_CLOCK_MODE [!//
[!IF "$DualClockSupport = 'true'"!][!//
 (STD_ON)
[!ELSE!][!//
 (STD_OFF)
[!ENDIF!][!//

/**
* @brief Define Timeout Method.
* @details Define a certain timeout method from OsIf will be used in the driver.
*/
#define FLEXIO_SPI_IP_TIMEOUT_METHOD       [!//
[!IF "SpiGeneral/SpiTimeoutMethod = 'OSIF_COUNTER_DUMMY'"!][!//
    (OSIF_COUNTER_DUMMY)
[!ELSEIF "SpiGeneral/SpiTimeoutMethod = 'OSIF_COUNTER_SYSTEM'"!][!//
    (OSIF_COUNTER_SYSTEM)
[!ELSEIF "SpiGeneral/SpiTimeoutMethod = 'OSIF_COUNTER_CUSTOM'"!][!//
    (OSIF_COUNTER_CUSTOM)
[!ENDIF!][!//

/**
* @brief          Enable User Mode Support.
* @details        When SpiAutosarExt/SpiEnableUserModeSupport = TRUE,
*                 the SPI driver can be executed from both supervisor and user mode.
*
* @api
*/
#define FLEXIO_SPI_IP_ENABLE_USER_MODE_SUPPORT (STD_OFF)

/**
* @brief Switches ON or OFF for the detection and reporting of development errors(API parameter checking) at IP level.
*/
/** @implements FLEXIO_SPI_IP_DEV_ERROR_DETECT_define  */
#define FLEXIO_SPI_IP_DEV_ERROR_DETECT     (STD_OFF)

/**
* @brief Maximum of frame size supported.
*/
#define FLEXIO_SPI_IP_FRAMESIZE_MAX_U8                              ((uint8)[!"ecu:get('Spi.SpiFrameSizeMax')"!]U)

/**
* @brief Maximum of frame size supported.
*/
#define FLEXIO_SPI_IP_FRAMESIZE_MIN_U8                              ((uint8)[!"ecu:get('Spi.SpiFrameSizeMin')"!]U)

/** @brief Write to CTRL */
#define FLEXIO_SPI_IP_CTRL_FLEXEN(x)  FLEXIO_CTRL_FLEXEN(x)

/** @brief Write to  TIMCMP */
#define FLEXIO_SPI_IP_TIMECMP_BAUDRATE_MASK_U32  ((uint32) 0x00FFu)
#define FLEXIO_SPI_IP_TIMECMP_FRAMESIZE_MASK_U32 ((uint32) 0xFF00u)
#define FLEXIO_SPI_IP_TIMCMP_CMP(x)        FLEXIO_TIMCMP_CMP(x)

/** @brief CPOL and CPHA selection */
#define FLEXIO_SPI_IP_CPOL_LOW_U8          ((uint8) 0U)
#define FLEXIO_SPI_IP_CPOL_HIGH_U8         ((uint8) 1U)
#define FLEXIO_SPI_IP_CPHA_LEADING_U8      ((uint8) 0U)
#define FLEXIO_SPI_IP_CPHA_TRAILING_U8     ((uint8) 1U)

/** @brief Write to  SHIFTCTL */
#define FLEXIO_SPI_IP_SHIFTCTL_TIMSEL(x)     FLEXIO_SHIFTCTL_TIMSEL(x)
#define FLEXIO_SPI_IP_SHIFTCTL_PINSEL(x)     FLEXIO_SHIFTCTL_PINSEL(x)
#define FLEXIO_SPI_IP_SHIFTCTL_PINCFG(x)     FLEXIO_SHIFTCTL_PINCFG(x) 
#define FLEXIO_SPI_IP_SHIFTCTL_SMOD(x)       FLEXIO_SHIFTCTL_SMOD(x)
#define FLEXIO_SPI_IP_SHIFTCTL_TIMPOL(x)     FLEXIO_SHIFTCTL_TIMPOL(x)

/** @brief Write to SHIFTCFG */
#define FLEXIO_SPI_IP_SHIFTCFG_SSTOP(x)      FLEXIO_SHIFTCFG_SSTOP(x)
#define FLEXIO_SPI_IP_SHIFTCFG_SSTART(x)     FLEXIO_SHIFTCFG_SSTART(x)
#define FLEXIO_SPI_IP_TIMCFG_TIMDEC(x)       FLEXIO_TIMCFG_TIMDEC(x)

/** @brief Write to TIMCTL  */
#define FLEXIO_SPI_IP_TIMCTL_PINSEL(x)             FLEXIO_TIMCTL_PINSEL(x)
#define FLEXIO_SPI_IP_TIMCTL_TRGSEL(x)             FLEXIO_TIMCTL_TRGSEL(x)
#define FLEXIO_SPI_IP_TIMCTL_TRGSRC(x)             FLEXIO_TIMCTL_TRGSRC(x)
#define FLEXIO_SPI_IP_TIMCTL_TIMOD(x)              FLEXIO_TIMCTL_TIMOD(x)
#define FLEXIO_SPI_IP_TIMCTL_TRGPOL(x)             FLEXIO_TIMCTL_TRGPOL(x)
#define FLEXIO_SPI_IP_TIMCTL_PINPOL(x)             FLEXIO_TIMCTL_PINPOL(x)
#define FLEXIO_SPI_IP_TIMCTL_PINCFG(x)             FLEXIO_TIMCTL_PINCFG(x)
#define FLEXIO_SPI_IP_TIMCTL_ONETIM(x)             FLEXIO_TIMCTL_ONETIM(x)

/** @brief Write to TIMCFG  */
#define FLEXIO_SPI_IP_TIMCFG_TIMOUT(x)             FLEXIO_TIMCFG_TIMOUT(x)
#define FLEXIO_SPI_IP_TIMCFG_TIMDIS(x)             FLEXIO_TIMCFG_TIMDIS(x)
#define FLEXIO_SPI_IP_TIMCFG_TIMENA(x)             FLEXIO_TIMCFG_TIMENA(x)
#define FLEXIO_SPI_IP_TIMCFG_TIMRST(x)             FLEXIO_TIMCFG_TIMRST(x)
#define FLEXIO_SPI_IP_TIMCFG_DEFAULT_MASTER_VALUE_U32         ((uint32) 0x00000222u)
#define FLEXIO_SPI_IP_TIMCFG_DEFAULT_SLAVE_CPHA0_VALUE         ((uint32) 0x01200600u)
#define FLEXIO_SPI_IP_TIMCFG_DEFAULT_SLAVE_CPHA1_VALUE         ((uint32) 0x01206602u)

/** @brief Write to SHIFTSIEN and SHIFTSDEN */
#define FLEXIO_SPI_IP_SHIFTSIEN_SSIE(x)         FLEXIO_SHIFTSIEN_SSIE(x)
#define FLEXIO_SPI_IP_SHIFTSDEN_SSDE(x)         FLEXIO_SHIFTSDEN_SSDE(x) 

/**
* @brief Shifters and Timer index
*/
#define FLEXIO_SPI_IP_SHIFTER_0_U8                   ((uint8)0U)
#define FLEXIO_SPI_IP_SHIFTER_1_U8                   ((uint8)1U)
#define FLEXIO_SPI_IP_SHIFTER_2_U8                   ((uint8)2U)
#define FLEXIO_SPI_IP_SHIFTER_3_U8                   ((uint8)3U)
#define FLEXIO_SPI_IP_SHIFTER_4_U8                   ((uint8)4U)
#define FLEXIO_SPI_IP_SHIFTER_5_U8                   ((uint8)5U)
#define FLEXIO_SPI_IP_SHIFTER_6_U8                   ((uint8)6U)
#define FLEXIO_SPI_IP_SHIFTER_7_U8                   ((uint8)7U)

#define FLEXIO_SPI_IP_TIMER_0_U8                     ((uint8)0U)
#define FLEXIO_SPI_IP_TIMER_1_U8                     ((uint8)1U)
#define FLEXIO_SPI_IP_TIMER_2_U8                     ((uint8)2U)
#define FLEXIO_SPI_IP_TIMER_3_U8                     ((uint8)3U)
#define FLEXIO_SPI_IP_TIMER_4_U8                     ((uint8)4U)
#define FLEXIO_SPI_IP_TIMER_5_U8                     ((uint8)5U)
#define FLEXIO_SPI_IP_TIMER_6_U8                     ((uint8)6U)
#define FLEXIO_SPI_IP_TIMER_7_U8                     ((uint8)7U)

#endif /*(FLEXIO_SPI_IP_ENABLE == STD_ON)*/
/*==================================================================================================
 *                                     DEFINES AND MACROS
==================================================================================================*/

/*==================================================================================================
*                                            ENUMS
==================================================================================================*/


/*==================================================================================================
*                               STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/


/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/


/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/


#ifdef __cplusplus
}
#endif

#endif 

/** @} */
[!ENDCODE!][!//
