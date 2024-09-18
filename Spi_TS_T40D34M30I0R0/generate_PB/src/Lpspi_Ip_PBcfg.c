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

/**
*   @file    Lpspi_Ip[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg.c
*   @version 3.0.0
*
*   @brief   AUTOSAR Spi - Post-Build(PB) configuration file code template.
*   @details Code template for Post-Build(PB) configuration file generation.
*
*   @addtogroup LPSPI_DRIVER_CONFIGURATION Lpspi Driver Configuration
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
#include "Lpspi_Ip.h"
#if (LPSPI_IP_DMA_USED == STD_ON)
#include "Dma_Ip.h"
#endif
/*==================================================================================================
*                                    SOURCE FILE VERSION INFORMATION
==================================================================================================*/

#define LPSPI_IP[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_VENDOR_ID_PBCFG_C                        43
#define LPSPI_IP[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_AR_RELEASE_MAJOR_VERSION_PBCFG_C         4
#define LPSPI_IP[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_AR_RELEASE_MINOR_VERSION_PBCFG_C         7
#define LPSPI_IP[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_AR_RELEASE_REVISION_VERSION_PBCFG_C      0
#define LPSPI_IP[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_SW_MAJOR_VERSION_PBCFG_C                 3
#define LPSPI_IP[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_SW_MINOR_VERSION_PBCFG_C                 0
#define LPSPI_IP[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_SW_PATCH_VERSION_PBCFG_C                 0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if Lpspi_Ip.h and Lpspi_Ip_PBcfg.c are of the same vendor */
#if (LPSPI_IP_VENDOR_ID != LPSPI_IP[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_VENDOR_ID_PBCFG_C)
    #error "Lpspi_Ip.h and Lpspi_Ip_PBcfg.c have different vendor ids"
#endif
/* Check if Lpspi_Ip.h file and Lpspi_Ip_PBcfg.c file are of the same Autosar version */
#if ((LPSPI_IP_AR_RELEASE_MAJOR_VERSION != LPSPI_IP[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_AR_RELEASE_MAJOR_VERSION_PBCFG_C) || \
     (LPSPI_IP_AR_RELEASE_MINOR_VERSION != LPSPI_IP[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_AR_RELEASE_MINOR_VERSION_PBCFG_C) || \
     (LPSPI_IP_AR_RELEASE_REVISION_VERSION != LPSPI_IP[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_AR_RELEASE_REVISION_VERSION_PBCFG_C))
#error "AutoSar Version Numbers of Lpspi_Ip.h and Lpspi_Ip_PBcfg.c are different"
#endif
#if ((LPSPI_IP_SW_MAJOR_VERSION != LPSPI_IP[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_SW_MAJOR_VERSION_PBCFG_C) || \
     (LPSPI_IP_SW_MINOR_VERSION != LPSPI_IP[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_SW_MINOR_VERSION_PBCFG_C) || \
     (LPSPI_IP_SW_PATCH_VERSION != LPSPI_IP[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_SW_PATCH_VERSION_PBCFG_C))
#error "Software Version Numbers of Lpspi_Ip.h and Lpspi_Ip_PBcfg.c are different"
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if (LPSPI_IP_DMA_USED == STD_ON)
        /* Check if current file and Dma_Ip header file are of the same Autosar version */
        #if ((DMA_IP_AR_RELEASE_MAJOR_VERSION != LPSPI_IP[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_AR_RELEASE_MAJOR_VERSION_PBCFG_C) || \
             (DMA_IP_AR_RELEASE_MINOR_VERSION != LPSPI_IP[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_AR_RELEASE_MINOR_VERSION_PBCFG_C))
        #error "AutoSar Version Numbers of Lpspi_Ip_Cfg.h and Dma_Ip.h are different"
        #endif
    #endif
#endif
/*==================================================================================================
*                                        LOCAL MACROS
==================================================================================================*/


/*==================================================================================================
                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/


/*==================================================================================================
                                       LOCAL CONSTANTS
==================================================================================================*/


/*==================================================================================================
                                       LOCAL VARIABLES
==================================================================================================*/


/*==================================================================================================
                                       GLOBAL CONSTANTS
==================================================================================================*/
[!NOCODE!][!//
[!MACRO "DetermineOptimalBaudrateSettings"!]
  [!VAR "OptimalAbsoluteBaudrateError" = "$BusClock div 2"!]
  [!VAR "Prescaler" = "1"!]
  [!FOR "PrescalerCount" = "0" TO "7"!]
    [!FOR "SckDiv" = "0" TO "255"!]
      [!VAR "CalculatedBaudrate" = "$BusClock div ($Prescaler * ($SckDiv + 2))"!]
      [!VAR "AbsoluteBaudrateError" = "$CalculatedBaudrate - $DesiredBaudrate"!]
      [!IF "$AbsoluteBaudrateError < 0"!][!VAR "AbsoluteBaudrateError" = "$AbsoluteBaudrateError * (-1)"!][!ENDIF!]
      [!IF "$AbsoluteBaudrateError < $OptimalAbsoluteBaudrateError"!]
        [!VAR "OptimalAbsoluteBaudrateError" = "$AbsoluteBaudrateError"!]
        [!VAR "OptimalPrescaleValue" = "$Prescaler"!]
        [!VAR "OptimalPrescale" = "$PrescalerCount"!]
        [!VAR "OptimalScaler" = "$SckDiv"!]
      [!ENDIF!]
    [!ENDFOR!]
    [!VAR "Prescaler" = "$Prescaler * 2"!]
  [!ENDFOR!]
[!ENDMACRO!][!//

[!MACRO "GenerateExternalDeviceInfo"!]]
  [!IF "$DualClockEnabled = 'true'"!][!//
    [!IF "SpiBaudrate > ($BusClockNormal div 2) or SpiBaudrate < ($BusClockNormal div 32896) or SpiBaudrate > ($BusClockAlternate div 2) or SpiBaudrate < ($BusClockAlternate div 32896)"!]
      [!ERROR!]For SpiPhyUnitClockRef, config [!"@name"!]/SpiBaudrate in range([!"$BusClockNormal div 32896"!], [!"$BusClockNormal div 2"!]).
      For SpiPhyUnitAlternateClockRef, config [!"@name"!]/SpiBaudrate in range([!"$BusClockAlternate div 32896"!], [!"$BusClockAlternate div 2"!]).
      [!ENDERROR!]
    [!ENDIF!]
  [!ELSE!]
    [!IF "SpiBaudrate > ($BusClockNormal div 2) or SpiBaudrate < ($BusClockNormal div 32896)"!]
      [!ERROR!]For SpiPhyUnitClockRef, config [!"@name"!]/SpiBaudrate in range([!"$BusClockNormal div 32896"!], [!"$BusClockNormal div 2"!]).[!ENDERROR!]
    [!ENDIF!]
  [!ENDIF!]

  [!VAR "BusClock" = "$BusClockNormal"!][!//
  [!VAR "DesiredBaudrate" = "SpiBaudrate"!]
  [!CALL "DetermineOptimalBaudrateSettings"!]
  [!VAR "OptimalPRESCALE" = "$OptimalPrescale"!]
  [!VAR "OptimalSCKDIV" = "$OptimalScaler"!]

  [!VAR "PrescaledClock" = "$BusClock div $OptimalPrescaleValue"!]
  [!VAR "DesiredTimeClock" = "(SpiTimeClk2Cs * $PrescaledClock) - 1"!]
  [!IF "$DesiredTimeClock < 0 or $DesiredTimeClock > 255"!]
    [!ERROR!]For SpiPhyUnitClockRef, config [!"@name"!]/SpiTimeClk2Cs in range([!"1 div $PrescaledClock"!], [!"256 div $PrescaledClock"!])[!ENDERROR!]
  [!ELSE!]
    [!VAR "OptimalSCKPCS" = "num:i($DesiredTimeClock + 0.5)"!]
  [!ENDIF!]

  [!VAR "DesiredTimeClock" = "(SpiTimeCs2Clk * $PrescaledClock) - 1"!]
  [!IF "$DesiredTimeClock < 0 or $DesiredTimeClock > 255"!]
    [!ERROR!]For SpiPhyUnitClockRef, config [!"@name"!]/SpiTimeCs2Clk in range([!"1 div $PrescaledClock"!], [!"256 div $PrescaledClock"!])[!ENDERROR!]
  [!ELSE!]
    [!VAR "OptimalPCSSCK" = "num:i($DesiredTimeClock + 0.5)"!]
  [!ENDIF!]

  [!VAR "DesiredTimeClock" = "(SpiTimeCs2Cs * $PrescaledClock) - 2"!]
  [!IF "$DesiredTimeClock < 0 or $DesiredTimeClock > 255"!]
    [!ERROR!]For SpiPhyUnitClockRef, config [!"@name"!]/SpiTimeCs2Cs in range([!"2 div $PrescaledClock"!], [!"257 div $PrescaledClock"!])[!ENDERROR!]
  [!ELSE!]
    [!VAR "OptimalDBT" = "num:i($DesiredTimeClock + 0.5)"!]
  [!ENDIF!]

  [!IF "$DualClockEnabled = 'true'"!][!//
    [!VAR "BusClock" = "$BusClockAlternate"!][!//
    [!VAR "DesiredBaudrate" = "SpiBaudrate"!]
    [!CALL "DetermineOptimalBaudrateSettings"!]
    [!VAR "OptimalPRESCALEAlternate" = "$OptimalPrescale"!]
    [!VAR "OptimalSCKDIVAlternate" = "$OptimalScaler"!]
  
    [!VAR "PrescaledClock" = "$BusClock div $OptimalPrescaleValue"!]
    [!VAR "DesiredTimeClock" = "(SpiTimeClk2Cs * $PrescaledClock) - 1"!]
    [!IF "$DesiredTimeClock < 0 or $DesiredTimeClock > 255"!]
      [!ERROR!]For SpiPhyUnitAlternateClockRef, config [!"@name"!]/SpiTimeClk2Cs in range([!"1 div $PrescaledClock"!], [!"256 div $PrescaledClock"!])[!ENDERROR!]
    [!ELSE!]
      [!VAR "OptimalSCKPCSAlternate" = "num:i($DesiredTimeClock + 0.5)"!]
    [!ENDIF!]
  
    [!VAR "DesiredTimeClock" = "(SpiTimeCs2Clk * $PrescaledClock) - 1"!]
    [!IF "$DesiredTimeClock < 0 or $DesiredTimeClock > 255"!]
      [!ERROR!]For SpiPhyUnitAlternateClockRef, config [!"@name"!]/SpiTimeCs2Clk in range([!"1 div $PrescaledClock"!], [!"256 div $PrescaledClock"!])[!ENDERROR!]
    [!ELSE!]
      [!VAR "OptimalPCSSCKAlternate" = "num:i($DesiredTimeClock + 0.5)"!]
    [!ENDIF!]
  
    [!VAR "DesiredTimeClock" = "(SpiTimeCs2Cs * $PrescaledClock) - 2"!]
    [!IF "$DesiredTimeClock < 0 or $DesiredTimeClock > 255"!]
      [!ERROR!]For SpiPhyUnitAlternateClockRef, config [!"@name"!]/SpiTimeCs2Cs in range([!"2 div $PrescaledClock"!], [!"257 div $PrescaledClock"!])[!ENDERROR!]
    [!ELSE!]
      [!VAR "OptimalDBTAlternate" = "num:i($DesiredTimeClock + 0.5)"!]
    [!ENDIF!]
  [!ENDIF!][!// "$DualClockEnabled = 'true'"

[!ENDMACRO!][!//

[!MACRO "Spi_CheckDualClockSupport"!]
    [!VAR "DualClockSupport"= "'false'"!]
    [!LOOP "SpiGeneral/SpiPhyUnit/*"!][!//
        [!IF "(node:exists(SpiPhyUnitAlternateClockRef))"!][!//
            [!VAR "DualClockSupport"= "'true'"!]
        [!ENDIF!][!//
    [!ENDLOOP!][!//

    [!VAR "DualClockEnabled" = "'false'"!][!//
[!ENDMACRO!][!//

[!MACRO "CheckFrameSizeOfChannelsAssignedHwUnit"!]
[!VAR "CurrentInstance" = "num:i(substring-after(SpiPhyUnitMapping,'_'))"!]
[!VAR "IsFirstChecking" = "'true'"!]
[!VAR "FrameSizeTemp" = "0"!]
[!VAR "TcdConfigOptimize" = "0"!]
[!IF "not(node:exists(SpiMaxDmaFastTransfer))"!] [!// do not support Hwunit that enabled DMA fast mode
[!LOOP "../../../SpiDriver/SpiJob/*"!]
    [!VAR "IsCurrentHwInstance" = "'false'"!]
    [!VAR "HwInstanceIsSelectedByJob" = "99"!]
    [!VAR "FrameSizeOfFirstChannelInJob" = "node:value(node:ref(SpiChannelList/*[1]/SpiChannelAssignment)/SpiDataWidth)"!]
    [!SELECT "node:ref(SpiDeviceAssignment)"!]
        [!VAR "varSpiHwUnit"="string(substring-after(node:value(SpiHwUnit),'CSIB')+1)"!]
        [!IF "contains(node:value(../../../SpiGeneral/SpiPhyUnit/*[number($varSpiHwUnit)]/SpiPhyUnitMapping),'LPSPI')"!]
            [!VAR "HwInstanceIsSelectedByJob" = "num:i(substring-after(node:value(../../../SpiGeneral/SpiPhyUnit/*[number($varSpiHwUnit)]/SpiPhyUnitMapping),'_'))"!]
        [!ENDIF!]
        [!IF "$HwInstanceIsSelectedByJob = $CurrentInstance"!]
            [!VAR "IsCurrentHwInstance" = "'true'"!]
        [!ENDIF!]
    [!ENDSELECT!]
    
    [!IF "$IsCurrentHwInstance = 'true'"!]
        [!IF "$IsFirstChecking = 'true'"!]
        [!VAR "TcdConfigOptimize" = "1"!]
            [!VAR "FrameSizeTemp" = "$FrameSizeOfFirstChannelInJob"!] [!// The first framesize will be saved to compare wiht ohters
            [!VAR "IsFirstChecking" = "'false'"!]
        [!ENDIF!]
        [!LOOP "SpiChannelList/*"!]
            [!SELECT "node:ref(SpiChannelAssignment)"!]
                [!IF "$FrameSizeTemp != SpiDataWidth"!]
                    [!VAR "TcdConfigOptimize" = "2"!]
                [!ENDIF!]
            [!ENDSELECT!]        
        [!ENDLOOP!]
    [!ENDIF!]   
[!ENDLOOP!]
[!ENDIF!] [!// do not support Hwunit that enabled DMA fast mode
[!ENDMACRO!]

[!CALL "Spi_CheckDualClockSupport"!]

[!ENDNOCODE!][!//

/*==================================================================================================
                                       GLOBAL VARIABLES
==================================================================================================*/
[!NOCODE!][!//
[!VAR "hwUnitIndexLpspi"= "0"!]
[!LOOP "SpiGeneral/SpiPhyUnit/*"!]
    [!IF "contains(node:value(SpiPhyUnitMapping),'LPSPI')"!]
        [!VAR "hwUnitIndexLpspi"= "$hwUnitIndexLpspi + 1"!]
    [!ENDIF!]
[!ENDLOOP!]
[!IF "num:i($hwUnitIndexLpspi) != 0"!]
[!CODE!]
#if (LPSPI_IP_DMA_USED == STD_ON)
    #define SPI_START_SEC_VAR_INIT_UNSPECIFIED_NO_CACHEABLE
#else
    #define SPI_START_SEC_VAR_INIT_UNSPECIFIED
#endif
#include "Spi_MemMap.h"

[!NOCODE!][!//
[!VAR "NumberOfExternalDeviceLpspi" = "0"!][!//
[!VAR "spiPath" = "node:path(.)"!][!//
[!LOOP "SpiDriver/SpiExternalDevice/*"!][!//
    [!VAR "varSpiHwUnit"="string(substring-after(node:value(SpiHwUnit),'CSIB')+1)"!][!//
    [!IF "contains((substring-before((node:value(concat($spiPath,'/SpiGeneral/SpiPhyUnit/*[',$varSpiHwUnit,']/SpiPhyUnitMapping'))),'_')),'LPSPI')"!]
        [!VAR "NumberOfExternalDeviceLpspi"= "$NumberOfExternalDeviceLpspi + 1"!]
    [!ENDIF!]
[!ENDLOOP!]
[!IF "num:i($NumberOfExternalDeviceLpspi) != 0"!]
[!CODE!][!//
/* Spi_Ip_DeviceParamsCfg[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!] Device Attribute Configuration of Spi*/
static Lpspi_Ip_DeviceParamsType Lpspi_Ip_DeviceParamsCfg[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][[!"num:i($NumberOfExternalDeviceLpspi)"!]U] =
{
[!ENDCODE!][!//
    [!VAR "ExIndex"="1"!]
    [!LOOP "SpiDriver/SpiExternalDevice/*"!][!//
        [!VAR "varSpiHwUnit"="string(substring-after(node:value(SpiHwUnit),'CSIB')+1)"!][!//
        [!IF "contains((substring-before((node:value(concat($spiPath,'/SpiGeneral/SpiPhyUnit/*[',$varSpiHwUnit,']/SpiPhyUnitMapping'))),'_')),'LPSPI')"!]
            [!CODE!]
    {
        (uint8)8U, /* Frame size - dummy value */
        (boolean)TRUE, /*Lsb - dummy value */
        (uint32)1U  /* Default Data - dummy value */
#if (STD_ON == LPSPI_IP_HALF_DUPLEX_MODE_SUPPORT)        
        , LPSPI_IP_FULL_DUPLEX /* Transfer mode - dummy value */
#endif
    }[!IF "$ExIndex < $NumberOfExternalDeviceLpspi"!],[!ENDIF!][!//
            [!ENDCODE!][!//
            [!VAR "ExIndex"="$ExIndex + 1"!][!//
        [!ENDIF!]
    [!ENDLOOP!][!//
[!CODE!]
};
[!ENDCODE!][!//
[!ENDIF!]
[!ENDNOCODE!][!//

#if (LPSPI_IP_DMA_USED == STD_ON)
    #define SPI_STOP_SEC_VAR_INIT_UNSPECIFIED_NO_CACHEABLE
#else
    #define SPI_STOP_SEC_VAR_INIT_UNSPECIFIED
#endif
#include "Spi_MemMap.h"

#if (LPSPI_IP_ENABLE_DMAFASTTRANSFER_SUPPORT == STD_ON)
#define SPI_START_SEC_VAR_CLEARED_UNSPECIFIED_NO_CACHEABLE
#include "Spi_MemMap.h"

[!NOCODE!][!//
[!LOOP "SpiGeneral/SpiPhyUnit/*"!][!//
[!IF "node:exists(SpiMaxDmaFastTransfer)"!][!//
    [!IF "node:fallback(node:ref(SpiPhyTxDmaChannel)/dmaLogicChannel_EnableScatterGather, 'false') = 'false'"!]
        [!ERROR!] Tx Dma channel of [!"@name"!] wasn't be enabled Scatter/Gather in dma fast mode.[!ENDERROR!]
    [!ENDIF!]
    [!IF "node:fallback(node:ref(SpiPhyRxDmaChannel)/dmaLogicChannel_EnableScatterGather, 'false') = 'false'"!]
        [!ERROR!] Rx Dma channel of [!"@name"!] wasn't be enabled Scatter/Gather in dma fast mode.[!ENDERROR!]
    [!ENDIF!]
[!CODE!][!//
/* Lpspi_Ip_CmdDmaFast_[!"@name"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!] Command Configuration of Dma Fast transfers */
static Lpspi_Ip_CmdDmaFastType Lpspi_Ip_CmdDmaFast_[!"@name"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][[!"num:i(SpiMaxDmaFastTransfer)"!]U];
[!ENDCODE!][!//
[!ENDIF!]
[!ENDLOOP!]
[!ENDNOCODE!][!//

#define SPI_STOP_SEC_VAR_CLEARED_UNSPECIFIED_NO_CACHEABLE
#include "Spi_MemMap.h"
#endif /*(LPSPI_IP_ENABLE_DMAFASTTRANSFER_SUPPORT == STD_ON)*/
[!ENDCODE!]
[!ENDIF!]
[!ENDNOCODE!][!//

[!NOCODE!][!//
[!CODE!]
#define SPI_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Spi_MemMap.h"
[!ENDCODE!]
[!VAR "ExIndex"="0"!]
[!VAR "spiPath" = "node:path(.)"!][!//
[!LOOP "SpiDriver/SpiExternalDevice/*"!][!//
[!VAR "varSpiHwUnit"="string(substring-after(node:value(SpiHwUnit),'CSIB')+1)"!][!//
[!IF "contains((substring-before((node:value(concat($spiPath,'/SpiGeneral/SpiPhyUnit/*[',$varSpiHwUnit,']/SpiPhyUnitMapping'))),'_')),'LPSPI')"!]
[!CODE!][!//
/* Lpspi_Ip_DeviceAttributes_[!"@name"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!] Device Attribute Configuration of Spi*/
const Lpspi_Ip_ExternalDeviceType Lpspi_Ip_DeviceAttributes_[!"@name"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!] =
{
[!ENDCODE!][!//
    [!VAR "varSpiHwUnit"="string(substring-after(node:value(SpiHwUnit),'CSIB')+1)"!][!//
    [!SELECT "node:ref(../../../SpiGeneral/SpiPhyUnit/*[number($varSpiHwUnit)]/SpiPhyUnitClockRef)"!][!//
        [!VAR "BusClockNormal" = "McuClockReferencePointFrequency"!][!//
    [!ENDSELECT!][!//
    [!IF "(node:exists(../../../SpiGeneral/SpiPhyUnit/*[number($varSpiHwUnit)]/SpiPhyUnitAlternateClockRef))"!][!//
        [!VAR "DualClockEnabled" = "'true'"!][!//
        [!SELECT "node:ref(../../../SpiGeneral/SpiPhyUnit/*[number($varSpiHwUnit)]/SpiPhyUnitAlternateClockRef)"!][!//
            [!VAR "BusClockAlternate" = "McuClockReferencePointFrequency"!][!//
        [!ENDSELECT!][!//
    [!ELSE!]
        [!VAR "DualClockEnabled" = "'false'"!][!//
    [!ENDIF!][!//
    [!CALL "GenerateExternalDeviceInfo"!]
    
    [!IF "SpiShiftClockIdleLevel = 'LOW'"!][!//
    [!VAR "CPOL" = "0"!]
    [!ELSE!]
    [!VAR "CPOL" = "1"!]
    [!ENDIF!][!// "SpiShiftClockIdleLevel   = 'LOW'"
    
    [!IF "SpiDataShiftEdge = 'LEADING'"!][!//
    [!VAR "CPHA" = "1"!]
    [!ELSE!]
    [!VAR "CPHA" = "0"!]
    [!ENDIF!][!// "SpiDataShiftEdge     = 'LEADING'"
    
    [!VAR "TransferWidth" = "0"!]
    [!IF "node:exists(SpiTransferWidth)"!]
        [!IF "SpiTransferWidth = 'TRANSFER_2_BIT'"!]
            [!VAR "TransferWidth" = "1"!]
        [!ENDIF!]
        [!IF "SpiTransferWidth = 'TRANSFER_4_BIT'"!]
            [!VAR "TransferWidth" = "2"!]
        [!ENDIF!]
        [!IF "SpiTransferWidth = 'TRANSFER_8_BIT'"!]
            [!VAR "TransferWidth" = "3"!]
        [!ENDIF!]
    [!ENDIF!]
    
    [!VAR "CSIndex" = "'PCS0'"!]
    [!VAR "CsContinues" = "0"!]
    [!IF "SpiEnableCs = 'true'"!][!//
        [!IF "node:exists(SpiCsSelection)"!][!//
            [!IF "SpiCsSelection = 'CS_VIA_PERIPHERAL_ENGINE'"!][!//
                [!IF "SpiCsBehavior = 'CS_KEEP_ASSERTED'"!][!//
                [!VAR "CsContinues" = "1"!]
                [!ELSE!]
                [!VAR "CsContinues" = "0"!]
                [!ENDIF!][!// "SpiCsBehavior     = 'CS_KEEP_ASSERTED'"
                
                [!VAR "CSIndex" = "SpiCsIdentifier"!]
            [!ENDIF!]
        [!ENDIF!]
    [!ENDIF!]
    
[!CODE!][!//
    [!"num:i(substring-after(node:value(../../../SpiGeneral/SpiPhyUnit/*[number($varSpiHwUnit)]/SpiPhyUnitMapping),'_'))"!]U,  /* Instance */
[!ENDCODE!]
    [!IF "$DualClockSupport = 'true'"!][!//
[!CODE!]
    {
        /* Normal Mode CCR */
[!ENDCODE!]
    [!ENDIF!][!//
[!CODE!][!//
        (uint32)(LPSPI_CCR_SCKPCS([!"num:i($OptimalSCKPCS)"!]U) | LPSPI_CCR_PCSSCK([!"num:i($OptimalPCSSCK)"!]U) | LPSPI_CCR_SCKDIV([!"num:i($OptimalSCKDIV)"!]U) | LPSPI_CCR_DBT([!"num:i($OptimalDBT)"!]U)), /* CCR */
[!ENDCODE!][!//
    [!IF "$DualClockSupport = 'true'"!][!//
        [!IF "$DualClockEnabled = 'true'"!][!//
[!CODE!][!//
        /* Alternate Mode CCR */
        (uint32)(LPSPI_CCR_SCKPCS([!"num:i($OptimalSCKPCSAlternate)"!]U) | LPSPI_CCR_PCSSCK([!"num:i($OptimalPCSSCKAlternate)"!]U) | LPSPI_CCR_SCKDIV([!"num:i($OptimalSCKDIVAlternate)"!]U) | LPSPI_CCR_DBT([!"num:i($OptimalDBTAlternate)"!]U)) /* CCR */
[!ENDCODE!]
        [!ELSE!][!//
[!CODE!]
            /*SpiHwUnit is not enable Alternate Mode, Set CCR is the same configuration as Normal Mode to use*/
            (uint32)(LPSPI_CCR_SCKPCS([!"num:i($OptimalSCKPCS)"!]U) | LPSPI_CCR_PCSSCK([!"num:i($OptimalPCSSCK)"!]U) | LPSPI_CCR_SCKDIV([!"num:i($OptimalSCKDIV)"!]U) | LPSPI_CCR_DBT([!"num:i($OptimalDBT)"!]U)) /* CCR */
[!ENDCODE!][!//
        [!ENDIF!][!//
[!CODE!][!//
    },
[!ENDCODE!][!//
    [!ENDIF!][!//
    [!IF "$DualClockSupport = 'true'"!][!//
[!CODE!][!//
    {
[!ENDCODE!][!//
    [!ENDIF!][!//
[!CODE!][!//
        /* Normal Mode TCR */
        (uint32)LPSPI_TCR_WIDTH([!"num:i($TransferWidth)"!]U) | (LPSPI_TCR_CPOL([!"num:i($CPOL)"!]U) | LPSPI_TCR_CPHA([!"num:i($CPHA)"!]U) | LPSPI_TCR_PRESCALE([!"num:i($OptimalPRESCALE)"!]U) | [!//
        LPSPI_TCR_PCS([!"num:i(substring-after($CSIndex,'PCS'))"!]U) | LPSPI_TCR_CONT([!"num:i($CsContinues)"!]U)) /* TCR */
[!ENDCODE!][!//
    [!IF "$DualClockSupport = 'true'"!][!//
        [!IF "$DualClockEnabled = 'true'"!][!//
[!CODE!][!//
        /* Alternate Mode TCR */
        ,(uint32)LPSPI_TCR_WIDTH([!"num:i($TransferWidth)"!]U) | (LPSPI_TCR_CPOL([!"num:i($CPOL)"!]U) | LPSPI_TCR_CPHA([!"num:i($CPHA)"!]U) | LPSPI_TCR_PRESCALE([!"num:i($OptimalPRESCALEAlternate)"!]U) | [!//
        LPSPI_TCR_PCS([!"num:i(substring-after($CSIndex,'PCS'))"!]U) | LPSPI_TCR_CONT([!"num:i($CsContinues)"!]U)) /* TCR */
[!ENDCODE!][!//
        [!ELSE!][!//
[!CODE!][!//
        /*SpiHwUnit is not enabled Alternate Mode, Set TCR is the same configuration as Normal Mode to use*/
        ,(uint32)LPSPI_TCR_WIDTH([!"num:i($TransferWidth)"!]U) | (LPSPI_TCR_CPOL([!"num:i($CPOL)"!]U) | LPSPI_TCR_CPHA([!"num:i($CPHA)"!]U) | LPSPI_TCR_PRESCALE([!"num:i($OptimalPRESCALE)"!]U) | [!//
        LPSPI_TCR_PCS([!"num:i(substring-after($CSIndex,'PCS'))"!]U) | LPSPI_TCR_CONT([!"num:i($CsContinues)"!]U)) /* TCR */
[!ENDCODE!][!//
        [!ENDIF!][!//
[!CODE!][!//
    }
[!ENDCODE!][!//
    [!ENDIF!]
    [!CODE!]
    #if (STD_ON == LPSPI_IP_HALF_DUPLEX_MODE_SUPPORT) 
    [!ENDCODE!]
    [!IF "SpiDeviceHalfDuplexSupport = 'true'"!]
[!CODE!]
    /*HalfDuplexCfgr1*/
    , LPSPI_CFGR1_OUTCFG(1u)[!ENDCODE!] 
        [!IF "node:exists(SpiTransferWidth)"!]
            [!IF "(SpiTransferWidth = 'TRANSFER_4_BIT')"!]
                [!CODE!] | LPSPI_CFGR1_PCSCFG(1u)[!ENDCODE!] 
            [!ENDIF!]
            [!IF "(SpiTransferWidth = 'TRANSFER_8_BIT')"!]
                [!CODE!] | LPSPI_CFGR1_PCSCFG(3u)[!ENDCODE!] 
            [!ENDIF!]
            [!IF "(SpiTransferWidth = 'TRANSFER_1_BIT')"!]
                [!IF "(SpiHalfDuplexPinSelect = 'HALF_DUPLEX_SIN')"!]
                    [!CODE!] | LPSPI_CFGR1_PINCFG(1u)[!ENDCODE!] 
                [!ELSE!]
                    [!CODE!] | LPSPI_CFGR1_PINCFG(2u)[!ENDCODE!] 
                [!ENDIF!]  
            [!ENDIF!]
        [!ENDIF!]
    [!ELSE!]
    [!CODE!],(uint32)0U /* This device do not support half duplex mode */[!ENDCODE!] 
    [!ENDIF!]
    [!CODE!]    
    #endif
    [!ENDCODE!]
[!CODE!]
    ,&Lpspi_Ip_DeviceParamsCfg[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][[!"num:i($ExIndex)"!]U]
};
[!ENDCODE!][!//
    [!VAR "ExIndex"="$ExIndex + 1"!][!//
[!ENDIF!][!//
[!ENDLOOP!][!//

[!VAR "hwUnitIndex"= "0"!]
[!LOOP "SpiGeneral/SpiPhyUnit/*"!][!//
[!IF "contains(node:value(SpiPhyUnitMapping),'LPSPI')"!]

[!IF "node:exists(SpiMaxDmaFastTransfer)"!]
    [!VAR "NumOfTxDmaFastSG"="count(node:ref(SpiPhyTxDmaChannel)/dmaLogicChannel_ConfigType/dmaLogicChannel_ScatterGatherConfigType/dmaLogicChannelConfig_ScatterGatherArrayType/*)"!]
[!CODE!]
#if ((LPSPI_IP_DMA_USED == STD_ON) && (LPSPI_IP_ENABLE_DMAFASTTRANSFER_SUPPORT == STD_ON))
/* List of TCD Scatter Gather Id for Tx DMA channel used in Dma Fast transfer */
static const uint8 Lpspi_Ip_ListTxDmaFastSGId_[!"@name"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][[!"num:i($NumOfTxDmaFastSG)"!]U] =
{
[!ENDCODE!]
    [!FOR "SGIndex" = "0" TO "num:i($NumOfTxDmaFastSG - 1)"!]
[!CODE!]
    (uint8)[!"node:value(node:ref(SpiPhyTxDmaChannel)/dmaLogicChannel_ConfigType/dmaLogicChannel_ScatterGatherConfigType/dmaLogicChannelConfig_ScatterGatherArrayType/*[$SGIndex + 1]/dmaLogicChannelConfig_ScatterGatherElementConfigType/dmaLogicChannelConfig_ScatterGatherElementNameType)"!][!//
    [!IF "$SGIndex < ($NumOfTxDmaFastSG - 1)"!],[!ENDIF!]
[!ENDCODE!]
    [!ENDFOR!]
[!CODE!]
};
[!ENDCODE!]

    [!VAR "NumOfRxDmaFastSG"="count(node:ref(SpiPhyRxDmaChannel)/dmaLogicChannel_ConfigType/dmaLogicChannel_ScatterGatherConfigType/dmaLogicChannelConfig_ScatterGatherArrayType/*)"!]
[!CODE!]
/* List of TCD Scatter Gather Id for Rx DMA channel used in Dma Fast transfer */
static const uint8 Lpspi_Ip_ListRxDmaFastSGId_[!"@name"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][[!"num:i($NumOfRxDmaFastSG)"!]U] =
{
[!ENDCODE!]
    [!FOR "SGIndex" = "0" TO "num:i($NumOfRxDmaFastSG - 1)"!]
[!CODE!]
    (uint8)[!"node:value(node:ref(SpiPhyRxDmaChannel)/dmaLogicChannel_ConfigType/dmaLogicChannel_ScatterGatherConfigType/dmaLogicChannelConfig_ScatterGatherArrayType/*[$SGIndex + 1]/dmaLogicChannelConfig_ScatterGatherElementConfigType/dmaLogicChannelConfig_ScatterGatherElementNameType)"!][!//
    [!IF "$SGIndex < ($NumOfRxDmaFastSG - 1)"!],[!ENDIF!]
[!ENDCODE!]
    [!ENDFOR!]
[!CODE!]
};
#endif
[!ENDCODE!]
    [!ENDIF!]

[!IF "SpiPhyUnitMode = 'SPI_MASTER'"!][!//
    [!VAR "Master" = "1"!]
    [!VAR "SamplePoint" = "SpiSamplePoint"!]
[!ELSE!]
    [!VAR "Master" = "0"!]
    [!VAR "SamplePoint" = "0"!]
[!ENDIF!][!// "SpiPhyUnitMode     = 'SPI_MASTER'"

[!VAR "HwIndex" = "@index"!]
[!VAR "Polarity" = "0"!]
[!LOOP "../../../SpiDriver/SpiExternalDevice/*"!][!//
    [!VAR "ExtDevHwIndex" = "num:i(substring-after(SpiHwUnit,'CSIB'))"!]
    [!IF "$HwIndex = $ExtDevHwIndex"!]
        [!VAR "PCSIndex" = "num:i(substring-after(SpiCsIdentifier,'PCS'))"!]
        [!IF "SpiCsPolarity = 'HIGH'"!]
            [!VAR "Polarity" = "bit:bitset($Polarity, $PCSIndex)"!]
        [!ENDIF!]
    [!ENDIF!][!// "$HwIndex = $ExtDevHwIndex"
[!ENDLOOP!]

[!CODE!][!//
/* The SPI Hw Unit configuration structures */
const Lpspi_Ip_ConfigType Lpspi_Ip_PhyUnitConfig_[!"@name"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!] =
{
[!ENDCODE!]
    [!CALL "CheckFrameSizeOfChannelsAssignedHwUnit"!]
[!CODE!]
    [!"num:i(substring-after(SpiPhyUnitMapping,'_'))"!]U,  /* Instance */
    /* CR */
    (uint32)0,
    /* CFGR1 */
    (uint32)(LPSPI_CFGR1_PINCFG([!"num:i(SpiPinConfiguration)"!]U) | LPSPI_CFGR1_PCSPOL([!"num:i($Polarity)"!]U) | LPSPI_CFGR1_MASTER([!"num:i($Master)"!]U) | LPSPI_CFGR1_SAMPLE([!"num:i($SamplePoint)"!]U)),
    #if (LPSPI_IP_SLAVE_SUPPORT == STD_ON)
    (boolean)[!IF "$Master = 0"!]TRUE[!ELSE!]FALSE[!ENDIF!],
    #endif
    #if (LPSPI_IP_DMA_USED == STD_ON)
[!ENDCODE!][!//
    [!IF "(ecu:get('Spi.SpiDMAPresent') = 'TRUE') and (../../SpiGlobalDmaEnable = 'true') and (../../SpiLevelDelivered >0) and (SpiPhyUnitAsyncUseDma = 'true')"!][!//
[!CODE!][!//
    (boolean)TRUE,
    (uint8)[!"node:value(node:ref(SpiPhyTxDmaChannel)/dmaLogicChannel_LogicName)"!], /* txDmaChannel */
    (uint8)[!"node:value(node:ref(SpiPhyRxDmaChannel)/dmaLogicChannel_LogicName)"!], /* rxDmaChannel */
    #if (LPSPI_IP_ENABLE_DMAFASTTRANSFER_SUPPORT == STD_ON)
    [!IF "node:exists(SpiMaxDmaFastTransfer)"!]
    (uint8)[!"num:i(SpiMaxDmaFastTransfer)"!]U, /* u8NumOfDmaFastTransfer */
    Lpspi_Ip_CmdDmaFast_[!"@name"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!],
    [!"num:i($NumOfTxDmaFastSG)"!]U, /* Number of TCD Scatter Gather for Tx */
    [!"num:i($NumOfRxDmaFastSG)"!]U, /* Number of TCD Scatter Gather for Rx */
    Lpspi_Ip_ListTxDmaFastSGId_[!"@name"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!],
    Lpspi_Ip_ListRxDmaFastSGId_[!"@name"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!],
    [!ELSE!]
    (uint8)0U, /* u8NumOfDmaFastTransfer */
    NULL_PTR, /* pCmdDmaFast */
    (uint8)0U,
    (uint8)0U,
    NULL_PTR, /* List of Tx SG Id */
    NULL_PTR, /* List of Rx SG Id */
    [!ENDIF!]
    #endif
[!ENDCODE!][!//
    [!ELSE!]
[!CODE!][!//
    (boolean)FALSE,
    (uint8)0U, /* txDmaChannel */
    (uint8)0U, /* rxDmaChannel */
    #if (LPSPI_IP_ENABLE_DMAFASTTRANSFER_SUPPORT == STD_ON)
    (uint8)0U, /* u8NumOfDmaFastTransfer */
    NULL_PTR, /* pCmdDmaFast */
    (uint8)0U,
    (uint8)0U,
    NULL_PTR, /* List of Tx SG Id */
    NULL_PTR, /* List of Rx SG Id */
    #endif
[!ENDCODE!][!//
    [!ENDIF!]
[!CODE!][!//
    #endif  /* (LPSPI_IP_DMA_USED == STD_ON) */
    LPSPI_IP_POLLING, /* Transfer mode */
    (uint8)[!"num:i($hwUnitIndex)"!]U /* State structure element from the array */
   #if (LPSPI_IP_DMA_USED == STD_ON)
    [!IF "num:i($TcdConfigOptimize) = 1"!]
    ,(boolean)TRUE  /* If channels in HWunit are the same framesize. */
    ,(uint8)[!"$FrameSizeTemp"!]U
    [!ELSE!]
    ,(boolean)FALSE  /* If channels in HWunit are the same framesize. */
    ,(uint8)0U
    [!ENDIF!]
   #endif
};
[!ENDCODE!][!//
[!VAR "hwUnitIndex"= "$hwUnitIndex + 1"!]
[!ENDIF!]
[!ENDLOOP!]
[!ENDNOCODE!][!//

#define SPI_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Spi_MemMap.h"
/*==================================================================================================
                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/


/*==================================================================================================
                                       LOCAL FUNCTIONS
==================================================================================================*/


/*==================================================================================================
                                       GLOBAL FUNCTIONS
==================================================================================================*/

#ifdef __cplusplus
}
#endif

/** @} */
