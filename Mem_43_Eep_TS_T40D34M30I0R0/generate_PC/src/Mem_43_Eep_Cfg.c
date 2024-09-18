
[!CODE!][!//
/*==================================================================================================
*   Project              : RTD AUTOSAR 4.7
*   Platform             : CORTEXM
*   Peripheral           : IPV_USDHC
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
[!VAR "variantName" = "''"!][!//
[!VAR "variantNameUpperCase" = "''"!][!//
[!IF "var:defined('postBuildVariant')"!][!//
[!VAR "variantName" = "concat('_', $postBuildVariant)"!][!//
[!VAR "variantNameUpperCase" = "toUpperCase(string($variantName))"!][!//
[!ENDIF!][!//

#ifdef __cplusplus
extern "C"{
#endif
/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Mem_43_Eep.h"
#include "Sd_Emmc_Ip_Cfg.h"
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define MEM_43_EEP_VENDOR_ID_CFG_C                      43
#define MEM_43_EEP_AR_RELEASE_MAJOR_VERSION_CFG_C       4
#define MEM_43_EEP_AR_RELEASE_MINOR_VERSION_CFG_C       7
#define MEM_43_EEP_AR_RELEASE_REVISION_VERSION_CFG_C    0
#define MEM_43_EEP_SW_MAJOR_VERSION_CFG_C               3
#define MEM_43_EEP_SW_MINOR_VERSION_CFG_C               0
#define MEM_43_EEP_SW_PATCH_VERSION_CFG_C               0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and Mem_43_Eep header file are of the same vendor */
#if (MEM_43_EEP_VENDOR_ID_CFG_C != MEM_43_EEP_VENDOR_ID)
    #error "Mem_43_Eep_Cfg.c and Mem_43_Eep.h have different vendor ids"
#endif
/* Check if current file and Mem_43_Eep header file are of the same Autosar version */
#if ((MEM_43_EEP_AR_RELEASE_MAJOR_VERSION_CFG_C    != MEM_43_EEP_AR_RELEASE_MAJOR_VERSION) || \
     (MEM_43_EEP_AR_RELEASE_MINOR_VERSION_CFG_C    != MEM_43_EEP_AR_RELEASE_MINOR_VERSION) || \
     (MEM_43_EEP_AR_RELEASE_REVISION_VERSION_CFG_C != MEM_43_EEP_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Mem_43_Eep_Cfg.c and Mem_43_Eep.h are different"
#endif
/* Check if current file and Mem_43_Eep header file are of the same Software version */
#if ((MEM_43_EEP_SW_MAJOR_VERSION_CFG_C != MEM_43_EEP_SW_MAJOR_VERSION) || \
     (MEM_43_EEP_SW_MINOR_VERSION_CFG_C != MEM_43_EEP_SW_MINOR_VERSION) || \
     (MEM_43_EEP_SW_PATCH_VERSION_CFG_C != MEM_43_EEP_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Mem_43_Eep_Cfg.c and Mem_43_Eep.h are different"
#endif

/* Check if current file and Sd_Emmc_Ip_Cfg.h header file are of the same vendor */
#if (MEM_43_EEP_VENDOR_ID_CFG_C != SD_EMMC_VENDOR_ID_IP_CFG)
    #error "Mem_43_Eep_Cfg.c and Sd_Emmc_Ip_Cfg.h have different vendor ids"
#endif
/* Check if current file and Mem_43_Eep header file are of the same Autosar version */
#if ((MEM_43_EEP_AR_RELEASE_MAJOR_VERSION_CFG_C    != SD_EMMC_AR_RELEASE_MAJOR_VERSION_IP_CFG) || \
     (MEM_43_EEP_AR_RELEASE_MINOR_VERSION_CFG_C    != SD_EMMC_AR_RELEASE_MINOR_VERSION_IP_CFG) || \
     (MEM_43_EEP_AR_RELEASE_REVISION_VERSION_CFG_C != SD_EMMC_AR_RELEASE_REVISION_VERSION_IP_CFG) \
    )
    #error "AutoSar Version Numbers of Mem_43_Eep_Cfg.c and Sd_Emmc_Ip_Cfg.h are different"
#endif
/* Check if current file and Mem_43_Eep header file are of the same Software version */
#if ((MEM_43_EEP_SW_MAJOR_VERSION_CFG_C != SD_EMMC_SW_MAJOR_VERSION_IP_CFG) || \
     (MEM_43_EEP_SW_MINOR_VERSION_CFG_C != SD_EMMC_SW_MINOR_VERSION_IP_CFG) || \
     (MEM_43_EEP_SW_PATCH_VERSION_CFG_C != SD_EMMC_SW_PATCH_VERSION_IP_CFG) \
    )
    #error "Software Version Numbers of Mem_43_Eep_Cfg.c and Sd_Emmc_Ip_Cfg.h are different"
#endif
/*==================================================================================================
                                     FUNCTION PROTOTYPES
==================================================================================================*/


/*==================================================================================================
                                           CONSTANTS
==================================================================================================*/
/* Configuration of MemSectorBatch */
[!LOOP "MemInstance/*"!]
const Mem_43_Eep_SectorBatchType Mem_43_Eep_[!"node:name(.)"!]_SectorBatch[[!"num:i(count(./MemSectorBatch/*))"!]U] =
{
    [!VAR "LoopIt" = "count(./MemSectorBatch/*)"!]
    [!LOOP "./MemSectorBatch/*"!]
    [!VAR "LoopIt"            = "$LoopIt - 1"!]
    [!VAR "StartAddress"      = "./MemStartAddress"!]
    [!VAR "EndAddress"        = "num:i(./MemStartAddress + ./MemNumberOfSectors * ./MemEraseSectorSize - 1)"!]
    [!VAR "SectorSize"        = "./MemEraseSectorSize"!]
    [!VAR "ReadPageSize"      = "./MemReadPageSize"!]
    [!VAR "WritePageSize"     = "./MemWritePageSize"!]
    [!VAR "EraseBurstSize"    = "node:when(node:exists(./MemBurstSettings), ./MemBurstSettings/MemEraseBurstSize, ./MemEraseSectorSize)"!]
    [!VAR "ReadBurstSize"     = "node:when(node:exists(./MemBurstSettings), ./MemBurstSettings/MemReadBurstSize,  ./MemReadPageSize)"!]
    [!VAR "WriteBurstSize"    = "node:when(node:exists(./MemBurstSettings), ./MemBurstSettings/MemWriteBurstSize, ./MemWritePageSize)"!]
    {
        /* [!"node:name(.)"!] */
        [!"$StartAddress"!],
        [!"$EndAddress"!],
        [!"$SectorSize"!],
        [!"$ReadPageSize"!],
        [!"$WritePageSize"!],
        [!"$EraseBurstSize"!],
        [!"$ReadBurstSize"!],
        [!"$WriteBurstSize"!]
    }[!IF "$LoopIt != 0"!],[!ENDIF!][!CR!][!//
    [!ENDLOOP!]
};

[!ENDLOOP!][!//

/* Configuration of Mem instances */
static const Mem_43_Eep_MemInstanceType Mem_43_Eep_MemInstances[MEM_43_EEP_INSTANCE_COUNT] =
{
[!VAR "LoopIt" = "count(MemInstance/*)"!]
[!//[!LOOP "node:order(MemInstance/*, 'node:value(./MemInstanceId)')"!][!// Iterate through the MemInstanceId value
[!LOOP "MemInstance/*"!][!// Iterate through the index value
    [!VAR "LoopIt"             = "$LoopIt - 1"!]
    [!VAR "InstanceId"         = "concat('MEM_43_EEP_INSTANCE_', node:pos(.), '_ID')"!]
    [!VAR "SectorBatchCount"   = "num:i(count(./MemSectorBatch/*))"!]
    [!VAR "SectorBatch"        = "concat('Mem_43_Eep_', node:name(.), '_SectorBatch')"!]
    [!VAR "MemUnitIndex"       = "num:i(0)"!]
    {
        /* [!"node:name(.)"!] */
        [!"$InstanceId"!],
        [!"$SectorBatchCount"!],
        [!"$SectorBatch"!],
        [!"$MemUnitIndex"!]
    }[!IF "$LoopIt != 0"!],[!ENDIF!][!CR!][!//
[!ENDLOOP!]
};

[!NOCODE!][!//
[!/* *** multiple inclusion protection *** */!][!//
[!IF "not(var:defined('MEM_EEP_CFG_GENERIC_MACROS_M4'))"!][!//
    [!VAR "MEM_EEP_CFG_GENERIC_MACROS_M4"="'true'"!][!//
    [!//
    [!MACRO "Mem_EepAccCrc","Mem_EepData32"!][!//
        [!NOCODE!][!//
        [!IF "65535 < $Mem_EepData32"!][!//
            [!VAR "Mem_EepCrcReminder" = "bit:or(bit:shl($Mem_EepCrcReminder,16),bit:shr($Mem_EepData32,16))"!][!//
            [!CALL "Mem_EepCalcCrcRemainder16bit"!][!//
        [!ENDIF!][!//
        [!IF "255 < $Mem_EepData32"!][!//
            [!VAR "Mem_EepCrcReminder" = "bit:or(bit:shl($Mem_EepCrcReminder,16),bit:and($Mem_EepData32,65535))"!][!//
            [!CALL "Mem_EepCalcCrcRemainder16bit"!][!//
        [!ELSE!][!//
            [!VAR "Mem_EepCrcReminder" = "bit:or(bit:shl($Mem_EepCrcReminder,8),bit:and($Mem_EepData32,255))"!][!//
            [!CALL "Mem_EepCalcCrcRemainder8bit"!][!//
        [!ENDIF!][!//
        [!ENDNOCODE!][!//
    [!ENDMACRO!][!//
    [!//
    [!MACRO "Mem_EepFinishCrc"!][!//
        [!NOCODE!][!//
        [!VAR "Mem_EepCrcReminder" = "bit:shl($Mem_EepCrcReminder,16)"!][!//
        [!CALL "Mem_EepCalcCrcRemainder16bit"!][!//
        [!ENDNOCODE!][!//
    [!ENDMACRO!][!//
    [!//
    [!MACRO "Mem_EepCalcCrcRemainder16bit"!][!//
        [!NOCODE!][!//
        [!VAR "Rem16CrcPolynomSft" = "2282782720"!][!//
        [!VAR "Rem16LeadingOne" = "2147483648"!][!//
        [!FOR "Rem16Counter"="31" TO "16" STEP "-1"!][!//
            [!IF "bit:and($Rem16LeadingOne,$Mem_EepCrcReminder) = $Rem16LeadingOne"!][!//
                [!VAR "Mem_EepCrcReminder"="bit:xor($Mem_EepCrcReminder,$Rem16CrcPolynomSft)"!][!//
            [!ENDIF!][!//
            [!VAR "Rem16CrcPolynomSft"="bit:shr($Rem16CrcPolynomSft,1)"!][!//
            [!VAR "Rem16LeadingOne"="bit:shr($Rem16LeadingOne,1)"!][!//
        [!ENDFOR!][!//
        [!ENDNOCODE!][!//
    [!ENDMACRO!][!//
    [!//
    [!MACRO "Mem_EepCalcCrcRemainder8bit"!][!//
        [!NOCODE!][!//
            [!VAR "Rem8CrcPolynomSft" = "8917120"!][!//
            [!VAR "Rem8LeadingOne" = "8388608"!][!//
            [!FOR "Rem8Counter"="23" TO "16" STEP "-1"!][!//
                [!IF "bit:and($Rem8LeadingOne,$Mem_EepCrcReminder) = $Rem8LeadingOne"!][!//
                    [!VAR "Mem_EepCrcReminder"="bit:xor($Mem_EepCrcReminder,$Rem8CrcPolynomSft)"!][!//
                [!ENDIF!][!//
                [!VAR "Rem8CrcPolynomSft"="bit:shr($Rem8CrcPolynomSft,1)"!][!//
                [!VAR "Rem8LeadingOne"="bit:shr($Rem8LeadingOne,1)"!][!//
            [!ENDFOR!][!//
        [!ENDNOCODE!][!//
    [!ENDMACRO!][!//
    [!//
    [!MACRO "GetBooleanValue", "Boolean"!][!//
        [!NOCODE!][!//
        [!IF "($Boolean) = 'true'"!]
            [!VAR "BooleanValueOut" = "1"!]
        [!ELSE!]
            [!VAR "BooleanValueOut" = "0"!]
        [!ENDIF!]
        [!ENDNOCODE!][!//
    [!ENDMACRO!][!//
    [!//
[!ENDIF!][!//
[!ENDNOCODE!][!//
[!//
[!/* *** multiple inclusion protection *** */!]
[!IF "not(var:defined('MEM_EEP_CFG_SPECIFIC_MACROS_M4'))"!][!//
    [!VAR "MEM_EEP_CFG_SPECIFIC_MACROS_M4"="'true'"!][!//

    [!MACRO "GetEndianModeValue", "EndianMode"!][!//
        [!NOCODE!][!//
            [!IF "($EndianMode) = 'USDHC_ENDIAN_MODE_BIG'"!]
                [!VAR "EndianModeValueOut" = "0"!]
            [!ELSEIF "($EndianMode) = 'USDHC_ENDIAN_MODE_HALF_WORD_BIG'"!]
                [!VAR "EndianModeValueOut" = "1"!]
            [!ELSE!]
                [!VAR "EndianModeValueOut" = "2"!]
            [!ENDIF!]
        [!ENDNOCODE!][!//
    [!ENDMACRO!][!//
    [!//
    [!MACRO "GetDmaModeValue", "DmaMode"!][!//
        [!NOCODE!][!//
            [!IF "($DmaMode) = 'USDHC_DMA_MODE_NO_DMA'"!]
                [!VAR "DmaModeValueOut" = "0"!]
            [!ELSEIF "($DmaMode) = 'USDHC_DMA_MODE_ADMA1'"!]
                [!VAR "DmaModeValueOut" = "1"!]
            [!ELSE!]
                [!VAR "DmaModeValueOut" = "2"!]
            [!ENDIF!]
        [!ENDNOCODE!][!//
    [!ENDMACRO!][!//
    [!//
    [!MACRO "GetBootModeValue", "BootMode"!][!//
        [!NOCODE!][!//
            [!IF "($BootMode) = 'USDHC_NORMAL_MMC_BOOT'"!]
                [!VAR "BootModeValueOut" = "0"!]
            [!ELSE!]
                [!VAR "BootModeValueOut" = "1"!]
            [!ENDIF!]
        [!ENDNOCODE!][!//
    [!ENDMACRO!][!//
    [!//
    [!MACRO "GetBootFlagsValue"!][!//
        [!NOCODE!][!//
            [!IF "node:value(./BootHostConfig/ackFlag) = 'true'"!]
                [!VAR "BootFlagsValueOut" = "16"!]
            [!ELSE!]
                [!VAR "BootFlagsValueOut" = "0"!]
            [!ENDIF!]
            [!IF "node:value(./BootHostConfig/disChkTimeout) = 'true'"!]
                [!VAR "BootFlagsValueOut" = "bit:or($BootFlagsValueOut,256)"!]
            [!ENDIF!]
            [!IF "node:value(./BootHostConfig/autoBlkGap) = 'true'"!]
                [!VAR "BootFlagsValueOut" = "bit:or($BootFlagsValueOut,128)"!]
            [!ENDIF!]
        [!ENDNOCODE!][!//
    [!ENDMACRO!][!//
    [!//
    [!MACRO "GetCardTypeValue"!][!//
        [!NOCODE!][!//
            [!IF "node:value(./Mem_3_EepEnableOperationsOnEmmc) = 'true'"!]
                [!VAR "CardTypeValueOut" = "1"!]
            [!ELSE!]
                [!VAR "CardTypeValueOut" = "0"!]
            [!ENDIF!]
        [!ENDNOCODE!][!//
    [!ENDMACRO!][!//
    [!//
    [!MACRO "Mem_EepCalcCrc"!][!//
        [!NOCODE!][!//
        [!VAR "Mem_EepCrcReminder" = "0"!][!// reset CRC reminder
            // Calculate CRC for Mem_EepUsdhcControllerCfg
            [!LOOP "./Mem_43_EepUsdhcControllerCfg/*[1]"!]
                // CRC - Accumulate Instance number
                [!CALL "Mem_EepAccCrc","Mem_EepData32"="0"!]
                // CRC - Accumulate cardDetectDat3
                [!CALL "GetBooleanValue","Boolean"="node:value(./cardDetectDat3)"!]
                [!CALL "Mem_EepAccCrc","Mem_EepData32"="$BooleanValueOut"!]
                // CRC - Accumulate Mem_EepEnableAutoCMD12
                [!CALL "GetBooleanValue","Boolean"="node:value(./EnableAutoCMD12)"!]
                [!CALL "Mem_EepAccCrc","Mem_EepData32"="$BooleanValueOut"!]
                // CRC - Accumulate endianMode
                [!CALL "GetEndianModeValue","EndianMode"="node:value(./endianMode)"!]
                [!CALL "Mem_EepAccCrc","Mem_EepData32"="$EndianModeValueOut"!]
                // CRC - Accumulate dmaMode
                [!CALL "GetDmaModeValue","DmaMode"="node:value(./dmaMode)"!]
                [!CALL "Mem_EepAccCrc","Mem_EepData32"="$DmaModeValueOut"!]
                // CRC - Accumulate admaTableSize
                [!CALL "Mem_EepAccCrc","Mem_EepData32"="node:value(./admaTableSize)"!]
                // CRC - Accumulate WriteWatermarkLevel
                [!CALL "Mem_EepAccCrc","Mem_EepData32"="node:value(./WriteWatermarkLevel)"!]
                // CRC - Accumulate ReadWatermarkLevel
                [!CALL "Mem_EepAccCrc","Mem_EepData32"="node:value(./ReadWatermarkLevel)"!]
                [!IF "node:exists(BootHostConfig)"!]
                    // CRC - Accumulate ackTimeout
                    [!CALL "Mem_EepAccCrc","Mem_EepData32"="node:value(./BootHostConfig/ackTimeout)"!]
                    // CRC - Accumulate bootMode
                    [!CALL "GetBootModeValue","BootMode"="node:value(./BootHostConfig/bootMode)"!]
                    [!CALL "Mem_EepAccCrc","Mem_EepData32"="$BootModeValueOut"!]
                    // CRC - Accumulate stopBlockGapCount
                    [!CALL "Mem_EepAccCrc","Mem_EepData32"="node:value(./BootHostConfig/stopBlockGapCount)"!]
                    // CRC - Accumulate bootFlags
                    [!CALL "GetBootFlagsValue"!]
                    [!CALL "Mem_EepAccCrc","Mem_EepData32"="$BootFlagsValueOut"!]
                [!ENDIF!][!//
            [!ENDLOOP!]
            // Calculate CRC for Mem_EepSdCfg
            [!LOOP "./Mem_43_EepSdCfg/*[1]"!]
                // CRC - Accumulate SdConfigClock
                [!CALL "Mem_EepAccCrc","Mem_EepData32"="node:value(./afrequencyTable)"!]
                // CRC - Accumulate SdClockReference
                [!CALL "Mem_EepAccCrc","Mem_EepData32"="node:value(node:ref(./SdClockReference)/McuClockReferencePointFrequency)"!]
            [!ENDLOOP!]
        [!ENDNOCODE!][!//
    [!ENDMACRO!][!//
    
[!ENDIF!][!//

#define MEM_43_EEP_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Mem_43_Eep_MemMap.h"

[!NOCODE!][!//
[!CALL "Mem_EepCalcCrc"!][!//
[!ENDNOCODE!][!//
/**
* @brief       Structure used to set function pointers notification, working mode
*/
const Mem_43_Eep_ConfigType Mem_43_Eep_Config[!WS "1"!] =
{
    [!WS "4"!]/* MemInstance Configuration                                 */ &Mem_43_Eep_MemInstances[0u],
    [!CALL "Mem_EepFinishCrc"!][!//
    [!AUTOSPACING!][!WS "4"!]/* MEM_43_EEP Config Set CRC checksum       */ [!"$Mem_EepCrcReminder"!]U,
    [!WS "4"!]&[!"node:name(Mem_43_EepSdCfg/*)"!][!"$variantName"!]
};

#define MEM_43_EEP_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Mem_43_Eep_MemMap.h"

[!ENDCODE!]

#ifdef __cplusplus
}
#endif

/** @}*/

