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

#ifndef SPI_IPW_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_H
#define SPI_IPW_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_H

/**
*   @file    Spi_Ipw_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBcfg.h
*   @version 3.0.0
*
*   @brief   AUTOSAR Spi - Spi configuration header file.
*   @details This file is the header containing all the extern declaration for SPI
*            module configuration(s).
*   @addtogroup SPI_DRIVER_CONFIGURATION Spi Driver Configuration
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
#include "Spi_Ipw.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define SPI_IPW_VENDOR_ID_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_H                    43
#define SPI_IPW_AR_RELEASE_MAJOR_VERSION_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_H     4
#define SPI_IPW_AR_RELEASE_MINOR_VERSION_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_H     7
#define SPI_IPW_AR_RELEASE_REVISION_VERSION_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_H  0
#define SPI_IPW_SW_MAJOR_VERSION_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_H             3
#define SPI_IPW_SW_MINOR_VERSION_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_H             0
#define SPI_IPW_SW_PATCH_VERSION_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_H             0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if this header file and Spi_Ipw.h are of the same vendor */
#if (SPI_IPW_VENDOR_ID_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_H != SPI_IPW_VENDOR_ID)
    #error "Spi_Ipw_PBcfg.h and Spi_Ipw.h have different vendor ids"
#endif
/* Check if Spi_Ipw_PBcfg.h file and Spi_Ipw.h file are of the same Autosar version */
#if ((SPI_IPW_AR_RELEASE_MAJOR_VERSION_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_H != SPI_IPW_AR_RELEASE_MAJOR_VERSION) || \
     (SPI_IPW_AR_RELEASE_MINOR_VERSION_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_H != SPI_IPW_AR_RELEASE_MINOR_VERSION) || \
     (SPI_IPW_AR_RELEASE_REVISION_VERSION_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_H != SPI_IPW_AR_RELEASE_REVISION_VERSION))
#error "AutoSar Version Numbers of Spi_Ipw_PBcfg.h and Spi_Ipw.h are different"
#endif
#if ((SPI_IPW_SW_MAJOR_VERSION_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_H != SPI_IPW_SW_MAJOR_VERSION) || \
     (SPI_IPW_SW_MINOR_VERSION_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_H != SPI_IPW_SW_MINOR_VERSION) || \
     (SPI_IPW_SW_PATCH_VERSION_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_H != SPI_IPW_SW_PATCH_VERSION))
#error "Software Version Numbers of Spi_Ipw_PBcfg.h and Spi_Ipw.h are different"
#endif
/*==================================================================================================
*                                          CONSTANTS
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
#define SPI_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Spi_MemMap.h"
[!NOCODE!]
[!VAR "ExDeviceCount" = "count(SpiDriver/SpiExternalDevice/*)"!][!//
[!VAR "SpiConfiguredPartitions" = "num:i(count(SpiGeneral/SpiEcucPartitionRef/*))"!]
[!VAR "TotalPartition" = "num:i(count(SpiGeneral/SpiEcucPartitionRef/*))"!]
[!IF "$SpiConfiguredPartitions = 0"!]
    [!VAR "TotalPartition" = "num:i(1)"!]
[!ENDIF!]
[!FOR "PartitionCount" = "1" TO "$TotalPartition"!]
    [!IF "as:modconf('Spi')[1]/SpiGeneral/SpiMulticoreSupport = 'true'"!]
        [!VAR "CurrentPartition" = "concat('_',node:name(node:ref(SpiGeneral/SpiEcucPartitionRef/*[num:i($PartitionCount)])))"!]
    [!ELSE!]
        [!VAR "CurrentPartition" = "string(null)"!]
    [!ENDIF!]
[!CODE!]
/* External device Configuration */
extern const Spi_ExDevicesConfigType Spi_aExternalDeviceConfigList[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][!"$CurrentPartition"!][[!"num:i($ExDeviceCount)"!]U];

/* Hardwre unit device configuration */
extern const Spi_PhyUnitsConfigType Spi_aHwUnitConfigList[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][!"$CurrentPartition"!][SPI_MAX_HWUNIT];
[!ENDCODE!]
[!ENDFOR!]
[!ENDNOCODE!]
#define SPI_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Spi_MemMap.h"

#define SPI_START_SEC_VAR_INIT_UNSPECIFIED
#include "Spi_MemMap.h"
[!NOCODE!]
[!VAR "ExDeviceCount" = "count(SpiDriver/SpiExternalDevice/*)"!][!//
[!VAR "SpiConfiguredPartitions" = "num:i(count(SpiGeneral/SpiEcucPartitionRef/*))"!]
[!VAR "TotalPartition" = "num:i(count(SpiGeneral/SpiEcucPartitionRef/*))"!]
[!IF "$SpiConfiguredPartitions = 0"!]
    [!VAR "TotalPartition" = "num:i(1)"!]
[!ENDIF!]
[!FOR "PartitionCount" = "1" TO "$TotalPartition"!]
    [!IF "as:modconf('Spi')[1]/SpiGeneral/SpiMulticoreSupport = 'true'"!]
        [!VAR "CurrentPartition" = "concat('_',node:name(node:ref(SpiGeneral/SpiEcucPartitionRef/*[num:i($PartitionCount)])))"!]
    [!ELSE!]
        [!VAR "CurrentPartition" = "string(null)"!]
    [!ENDIF!]
[!IF "node:exists(SpiAutosarExt/SpiEnableDmaContMemTransferSupport)"!][!//
[!IF "node:value(SpiAutosarExt/SpiEnableDmaContMemTransferSupport)"!][!//
[!CODE!]
#if ((SPI_DMA_USED == STD_ON) && (SPI_ENABLE_DMA_CONT_MEM_TRANSFER_SUPPORT == STD_ON))
[!ENDCODE!]
[!LOOP "node:order(SpiDriver/SpiSequence/*, 'node:value(SpiSequenceId)')"!]
    [!VAR "SeqChannelCount" = "num:i(0)"!]
    [!VAR "SeqJobCount" = "num:i(0)"!]
    [!IF "node:exists(SpiDmaContMemTransferSequenceEnable)"!]
        [!IF "SpiDmaContMemTransferSequenceEnable"!]
[!CODE!]
/* DMA rx continue memory transfer */
extern Spi_DmaContMemState Spi_DmaConMemTransferTxSeq_[!"num:i(node:value(SpiSequenceId))"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][!"$CurrentPartition"!];
[!ENDCODE!]
        [!ENDIF!]
    [!ENDIF!]
[!ENDLOOP!]
[!CODE!]
#endif
[!ENDCODE!]
[!ENDIF!]
[!ENDIF!]
[!ENDFOR!]
[!ENDNOCODE!]
#define SPI_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Spi_MemMap.h"
/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/

#ifdef __cplusplus
}
#endif

/** @} */

#endif 

[!ENDCODE!][!//
