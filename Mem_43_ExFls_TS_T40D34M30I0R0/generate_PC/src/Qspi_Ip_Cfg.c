[!AUTOSPACING!]
[!CODE!][!//
/*==================================================================================================
*   Project              : RTD AUTOSAR 4.7
*   Platform             : CORTEXM
*   Peripheral           : IPV_QSPI
*   Dependencies         : None
*
*   Autosar Version      : 4.7.0
*   Autosar Revision     : ASR_REL_4_7_REV_0000
*   Autosar Conf.Variant :
*   SW Version           : 3.0.0
*   Build Version        : S32K3_RTD_3_0_0_D2303_ASR_REL_4_7_REV_0000_20230331
*
*   (c) Copyright 2020 - 2023 NXP Semiconductors
*   All Rights Reserved.
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
*   @file Qspi_Ip_Cfg.c
*
*   @addtogroup FLS
*   @{
*/

/* implements Qspi_Ip_Cfg.c_Artifact */

#ifdef __cplusplus
extern "C"{
#endif


/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Qspi_Ip_Cfg.h"


/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/


/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/



/*==================================================================================================
                                     FUNCTION PROTOTYPES
==================================================================================================*/


/*==================================================================================================
                                           CONSTANTS
==================================================================================================*/
[!VAR "configName"          = "'Qspi_Ip'"!][!//

[!VAR "HyperflashCfgExists" = "ecu:has('Mem.ExFls.Qspi.Hyperflash.Available')"!][!//
[!VAR "SerialflashCfgCount" = "num:i(count(MemDevice/MemSerialFlashCfg/*))"!][!//
[!VAR "HyperflashCfgCount"  = "num:i(count(MemDevice/MemHyperFlashCfg/*))"!][!//
[!VAR "FlashConfigCount"    = "num:i($SerialflashCfgCount + $HyperflashCfgCount)"!][!//

[!INDENT "0"!][!//
[!IF "node:exists(MemGeneral/MemQspiInitCallout) or node:exists(MemGeneral/MemQspiResetCallout) or node:exists(MemGeneral/MemQspiErrorCheckCallout) or node:exists(MemGeneral/MemQspiEccCheckCallout)"!][!//
    #define MEM_43_EXFLS_START_SEC_CODE
    #include "Mem_43_ExFls_MemMap.h"

    /* Declaration of QSPI callout functions */
    [!LOOP "text:order(text:split(normalize-space(text:join(MemGeneral/MemQspiInitCallout | MemGeneral/MemQspiResetCallout | MemGeneral/MemQspiErrorCheckCallout))))"!][!//
        extern Qspi_Ip_StatusType [!"."!](uint32 instance);
    [!ENDLOOP!][!//
    [!IF "node:exists(MemGeneral/MemQspiEccCheckCallout)"!][!//
        extern Qspi_Ip_StatusType [!"./MemGeneral/MemQspiEccCheckCallout"!](uint32 instance, uint32 startAddress, uint32 dataLength);
    [!ENDIF!][!//

    #define MEM_43_EXFLS_STOP_SEC_CODE
    #include "Mem_43_ExFls_MemMap.h"
[!ENDIF!][!//


[!IF "$HyperflashCfgCount > 0"!][!//
    #define MEM_43_EXFLS_START_SEC_VAR_INIT_UNSPECIFIED
    #include "Mem_43_ExFls_MemMap.h"

    /* Using the fixed command sets from Qspi_Ip_Hyperflash.c */
    extern Qspi_Ip_InstrOpType QSPI_IP_HF_LUT_NAME[];

    #define MEM_43_EXFLS_STOP_SEC_VAR_INIT_UNSPECIFIED
    #include "Mem_43_ExFls_MemMap.h"

[!ENDIF!][!//


[!AUTOSPACING!]

#define MEM_43_EXFLS_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Mem_43_ExFls_MemMap.h"

/* External QSPI flash parameters. */
[!IF "num:i(count(MemDevice/MemCfg/*)) > 0"!][!//
    /* paFlashConnectionCfg */
    const Qspi_Ip_MemoryConnectionType [!"$configName"!]_paFlashConnectionCfg[[!"num:i(count(MemDevice/MemCfg/*))"!]U] =
    {
        [!VAR "FlsLoopIt" = "count(MemDevice/MemCfg/*)"!][!//
        [!LOOP "MemDevice/MemCfg/*"!][!//
            [!VAR "FlsLoopIt" = "$FlsLoopIt - 1"!][!//
            [!WS "4"!]{
            [!WS "8"!](uint32)[!"node:ref(./MemQspiInstance)/MemControllerName  "!],  /* MemQspiInstance */
            [!WS "8"!][!"./MemConnectionType"!],  /* MemConnectionType */
            [!WS "8"!][!"./MemAlignment"!]U  /* memAlignment */
            [!WS "4"!]}[!IF "$FlsLoopIt != 0"!],[!ENDIF!][!CR!]
        [!ENDLOOP!][!//
    };
[!ENDIF!][!//

[!IF "num:i(count(MemDevice/MemControllerCfg/*)) > 0"!][!//
    /* paQspiUnitCfg */
    const Qspi_Ip_ControllerConfigType [!"$configName"!]_paQspiUnitCfg[[!"num:i(count(MemDevice/MemControllerCfg/*))"!]U] =
    {
        [!VAR "FlsLoopIt" = "count(MemDevice/MemControllerCfg/*)"!][!//
        [!LOOP "MemDevice/MemControllerCfg/*"!][!//
            [!VAR "FlsLoopIt" = "$FlsLoopIt - 1"!][!//
            [!WS "4"!]/* [!"node:name(.)"!] */
            [!WS "4"!]{
                [!WS "8"!][!"./MemHwUnitReadMode"!],                                /* dataRate */
                [!WS "8"!][!"./MemSerialFlashA1Size"!]U,                                /* memSizeA1 */
                [!WS "8"!][!"./MemSerialFlashA2Size"!]U,                                /* memSizeA2 */
                [!WS "8"!][!"./MemHwUnitTcsh"!]U,                                /* csHoldTime */
                [!WS "8"!][!"./MemHwUnitTcss"!]U,                                /* csSetupTime */
                [!WS "8"!][!"./MemHwUnitColumnAddressWidth"!]U,                                /* columnAddr */
                [!WS "8"!][!IF "./MemHwUnitWordAddressable"!](boolean)TRUE[!ELSE!](boolean)FALSE[!ENDIF!],                                /* wordAddresable */
                [!WS "8"!][!"./MemHwUnitSamplingModeA"!],                                /* readModeA */
                [!WS "8"!][!"./MemHwUnitSamplingDly"!],                                /* sampleDelay */
                [!WS "8"!][!"./MemHwUnitSamplingEdge"!],                                /* samplePhase */
                [!WS "8"!]{
                    [!WS "12"!]/* dllSettingsA */
                    [!WS "12"!][!"./MemDllCfgA/MemDllCfgADllMode"!],                                /* dllMode */
                    [!WS "12"!][!IF "./MemDllCfgA/MemDllCfgADllCraFreqEn"!](boolean)TRUE[!ELSE!](boolean)FALSE[!ENDIF!],                                /* freqEnable */
                    [!WS "12"!][!"./MemDllCfgA/MemDllCfgADllCraReferenceCounter"!]U,                      /* referenceCounter */
                    [!WS "12"!][!"./MemDllCfgA/MemDllCfgADllCraResolution"!]U,                            /* resolution */
                    [!WS "12"!][!IF "./MemDllCfgA/MemDllCfgADllMode='QSPI_IP_DLL_BYPASSED'"!][!"./MemDllCfgA/MemDllCfgADllCraSlvDlyCoarse"!][!ELSE!][!"./MemDllCfgA/MemDllCfgADllCraSlvDlyOffset"!][!ENDIF!]U,                                /* coarseDelay */
                    [!WS "12"!][!"./MemDllCfgA/MemDllCfgADllCraSlvFineOffset"!]U,                         /* fineDelay */
                    [!WS "12"!][!"./MemDllCfgA/MemDllCfgADllTapSelect"!]U                                 /* tapSelect */
                [!WS "8"!]},
                [!WS "8"!][!"./MemHwUnitTdh"!],                                /* dataAlign */
                [!WS "8"!][!IF "./MemIdleSignalDriveIOFA2HighLvl"!]1U[!ELSE!]0U[!ENDIF!],                                /* io2IdleValueA */
                [!WS "8"!][!IF "./MemIdleSignalDriveIOFA3HighLvl"!]1U[!ELSE!]0U[!ENDIF!],                                /* io3IdleValueA */
                [!WS "8"!][!IF "./MemHwUnitByteSwapping"!](boolean)TRUE[!ELSE!](boolean)FALSE[!ENDIF!],                                /* byteSwap */
                [!IF "ecu:get('Mem.ExFls.Qspi.Has.Sfp') = 1"!][!//
#if (QSPI_IP_SFP_ENABLE_GLOBAL == STD_ON)
                [!WS "8"!]{/* SfpCfg */
                    [!WS "12"!][!"./MemSecureFlashProtection/MemQspiSfpMasterTimeout"!]UL, /* MasterTimeout */
#if (QSPI_IP_SFP_ENABLE_MDAD == STD_ON)
                    [!WS "12"!]{/* QuadSPI_MDAD_COUNT */
                    [!LOOP "./MemSecureFlashProtection/MemQspiSfpMdadTG/*"!][!//
                        [!WS "16"!]{
                            [!WS "20"!][!"./SecureAttribute"!], /* SecureAttribute */
                            [!WS "20"!][!"./MaskType"!], /* MaskType */
                            [!WS "20"!](boolean)[!"text:toupper(./Valid)"!], /* Valid */
                            [!WS "20"!][!"./Mask"!]U, /* Mask */
                            [!WS "20"!][!"./DomainID"!]U /* DomainID */
                        [!WS "16"!]},
                    [!ENDLOOP!][!//
                    [!WS "12"!]},
#endif /* QSPI_IP_SFP_ENABLE_MDAD */
#if (QSPI_IP_SFP_ENABLE_FRAD == STD_ON)
                    [!WS "12"!]{/* QuadSPI_FRAD_COUNT */
                    [!LOOP "./MemSecureFlashProtection/MemQspiSfpFrad/*"!][!//
                        [!WS "16"!]{
                            [!WS "20"!][!"./StartAddress"!]U, /* StartAddress */
                            [!WS "20"!][!"./EndAddress"!]U, /* EndAddress */
                            [!WS "20"!](boolean)[!"text:toupper(./Valid)"!], /* Valid */
                            [!WS "20"!][!"./Md0Acp"!], /* Md0Acp */
                            [!WS "20"!][!"./Md1Acp"!], /* Md1Acp */
                            [!WS "20"!][!"./ExclusiveAccessLock"!], /* ExclusiveAccessLock */
                            [!WS "20"!][!"./ExclusiveAccessOwner"!]U /* ExclusiveAccessOwner */
                        [!WS "16"!]},
                    [!ENDLOOP!][!//
                    [!WS "12"!]},
#endif /* QSPI_IP_SFP_ENABLE_FRAD */
                [!WS "8"!]},
#endif /* QSPI_IP_SFP_ENABLE_GLOBAL */
                [!ENDIF!][!// ecu:get('Mem.ExFls.Qspi.Has.Sfp')
                [!WS "8"!]{
                    [!WS "12"!]/* AHBConfig */
                    [!WS "12"!]{
                        [!WS "16"!]/* masters */
                        [!WS "16"!][!"./MemAhbBuffer/*[1]/MemAhbBufferMasterId"!]U,  /* buffer 0 master ID */
                        [!WS "16"!][!"./MemAhbBuffer/*[2]/MemAhbBufferMasterId"!]U,  /* buffer 1 master ID */
                        [!WS "16"!][!"./MemAhbBuffer/*[3]/MemAhbBufferMasterId"!]U,  /* buffer 2 master ID */
                        [!WS "16"!][!"./MemAhbBuffer/*[4]/MemAhbBufferMasterId"!]U   /* buffer 3 master ID */
                    [!WS "12"!]},
                    [!WS "12"!]{
                        [!WS "16"!]/* sizes */
                        [!WS "16"!][!"./MemAhbBuffer/*[1]/MemAhbBufferSize"!]U,  /* buffer 0 size */
                        [!WS "16"!][!"./MemAhbBuffer/*[2]/MemAhbBufferSize"!]U,  /* buffer 1 size */
                        [!WS "16"!][!"./MemAhbBuffer/*[3]/MemAhbBufferSize"!]U,  /* buffer 2 size */
                        [!WS "16"!][!"./MemAhbBuffer/*[4]/MemAhbBufferSize"!]U   /* buffer 3 size */
                    [!WS "12"!]},
                    [!IF "./MemAhbBuffer/*[4]/MemAhbBufferAllMasters"!]
                    [!WS "12"!](boolean)TRUE                                /* allMasters */
                    [!ELSE!]
                    [!WS "12"!](boolean)FALSE                                /* allMasters */
                    [!ENDIF!]
                [!WS "8"!]}
            [!WS "4"!]}[!IF "$FlsLoopIt != 0"!],[!ENDIF!][!CR!]
        [!ENDLOOP!][!//
    };
[!ENDIF!][!//
[!//
[!MACRO "ComputeLutSize"!]
    [!VAR "FlsLutSize" = "0"!][!//
    [!LOOP "./MemLUT/*"!][!//
        [!VAR "FlsLutSize" = "$FlsLutSize + count(./MemInstructionOperandPair/*) + 1"!][!//
    [!ENDLOOP!][!//
    [!VAR "FlsLutSize" = "num:i($FlsLutSize)"!][!//
[!ENDMACRO!]
[!//
[!MACRO "ComputeLutIndex", "SeqNo" = "0", "Text" = "", "Comma" = "','"!]
    [!IF "node:exists($SeqNo)"!]
        [!VAR "FlsLutIdx" = "0"!][!//
        [!VAR "FlsLutSelect" = "node:ref($SeqNo)/MemLUTIndex"!][!//
        [!LOOP "node:order(./MemLUT/*, 'node:value(./MemLUTIndex)')"!][!// Iterate through the Fls LUT Index
            [!IF "$FlsLutSelect <= node:value(./MemLUTIndex)"!][!BREAK!][!ENDIF!]
            [!VAR "FlsLutIdx" = "$FlsLutIdx + count(./MemInstructionOperandPair/*) + 1"!][!//
        [!ENDLOOP!][!//
        [!VAR "LutIndexOut" = "concat(string(num:i($FlsLutIdx)), 'U')"!][!//
    [!ELSE!]
        [!VAR "LutIndexOut" = "'QSPI_IP_LUT_INVALID'"!][!//
    [!ENDIF!]
    [!IF "$Text != ''"!]
    [!VAR "LutIndexOut" = "concat($LutIndexOut, $Comma, '  /* ', $Text, ' */')"!][!//
    [!ENDIF!]
[!ENDMACRO!]
[!//
[!MACRO "PrintLutIndex", "SeqNo" = "0", "Text" = "", "Comma" = "','"!][!//
    [!CALL "ComputeLutIndex", "SeqNo" = "$SeqNo", "Text" = "$Text", "Comma" = "$Comma"!][!//
    [!"$LutIndexOut"!][!CR!][!//
[!ENDMACRO!][!//
[!//
[!MACRO "PrintLutIndex_Op", "SeqNo" = "0", "Text" = ""!]
    [!IF "node:exists($SeqNo)"!]
        [!VAR "FlsLutIdx" = "0"!][!//
        [!VAR "FlsLutSelect" = "node:ref($SeqNo)/MemLUTIndex"!][!//
        [!LOOP "node:order(../../MemLUT/*, 'node:value(./MemLUTIndex)')"!][!// Iterate through the Fls LUT Index
            [!IF "$FlsLutSelect <= node:value(./MemLUTIndex)"!][!BREAK!][!ENDIF!]
            [!VAR "FlsLutIdx" = "$FlsLutIdx + count(./MemInstructionOperandPair/*) + 1"!][!//
        [!ENDLOOP!][!//
        [!"num:i($FlsLutIdx)"!]U,                               /* [!"$Text"!] */
    [!ELSE!]
        QSPI_IP_LUT_INVALID,                               /* [!"$Text"!] */
    [!ENDIF!]
[!ENDMACRO!]
[!//
[!MACRO "PrintReadId", "ReadIdSettings" = ""!]
    [!VAR "MemQspiDeviceId"  = "node:ref($ReadIdSettings)/MemQspiDeviceId"!][!//
    [!VAR "IdExpected"       = "text:replaceAll(substring($MemQspiDeviceId, 3), ':', '')"!][!//
    [!VAR "MemCfgReadIdSize" = "node:ref($ReadIdSettings)/MemCfgReadIdSize"!]
    [!IF "not(node:exists(node:ref($ReadIdSettings)/MemCfgReadIdLUT))"!]
        [!VAR "MemCfgReadIdSize" = "num:i(0)"!][!// If the Read Id LUT index reference is not enabled, ignore the user configuration
    [!ENDIF!]
    [!VAR "IdSizeMax" = "num:i(10)"!][!//
    [!VAR "Comma"     = "','"!]
    [!WS "12"!][!"$MemCfgReadIdSize"!]U,  /* readIdSize */
    [!WS "12"!]/* readIdExpected */
    [!WS "12"!]{
    [!FOR "Idx" = "1" TO "$MemCfgReadIdSize"!][!// Copy the user value
        [!VAR "Start"  = "string-length($IdExpected) - ($Idx * 2) + 1"!][!//
        [!VAR "IdByte" = "substring($IdExpected, $Start, 2)"!][!//
        [!VAR "IdOut"  = "concat('0x', $IdByte, 'U')"!][!//
        [!IF "$Idx = $IdSizeMax"!][!VAR "Comma" = "' '"!][!ENDIF!][!//
        [!VAR "IdOut" = "concat($IdOut, $Comma, '  /* byte ', $Idx, ' */')"!][!//
        [!WS "16"!][!"$IdOut"!][!CR!]
    [!ENDFOR!][!//
    [!FOR "Idx" = "$MemCfgReadIdSize + 1" TO "$IdSizeMax"!][!// Override unused bytes with 0xFF
        [!IF "$Idx = $IdSizeMax"!][!VAR "Comma" = "' '"!][!ENDIF!][!//
        [!VAR "IdOut" = "concat('0xFFU', $Comma, '  /* byte ', $Idx, ' */')"!][!//
        [!WS "16"!][!"$IdOut"!][!CR!]
    [!ENDFOR!][!//
    [!WS "12"!]}
[!ENDMACRO!]
[!//
    [!LOOP "MemDevice/MemSerialFlashCfg/*"!][!//
        [!IF "num:i(count(./MemInitConfiguration/*)) > 0"!]
            /* paInitOperations */
            static const Qspi_Ip_InitOperationType [!"node:name(.)"!]_paInitOperations_[!"node:pos(.)"!][[!"num:i(count(./MemInitConfiguration/*))"!]U] =
            {
                [!VAR "FlsLoopIt" = "count(./MemInitConfiguration/*)"!][!//
                [!LOOP "./MemInitConfiguration/*"!][!//
                    [!VAR "FlsLoopIt" = "$FlsLoopIt - 1"!][!//
                    [!WS "4"!]{
                        [!WS "8"!][!"./opType"!],                      /* opType */
                        [!WS "8"!][!CALL "PrintLutIndex_Op", "SeqNo" = "node:when(node:exists(./MemCommand1Lut), ./MemCommand1Lut)", "Text" = "'command1Lut'"!]
                        [!WS "8"!][!CALL "PrintLutIndex_Op", "SeqNo" = "node:when(node:exists(./MemCommand2Lut), ./MemCommand2Lut)", "Text" = "'command2Lut'"!]
                        [!WS "8"!][!CALL "PrintLutIndex_Op", "SeqNo" = "node:when(node:exists(./MemWeLut), ./MemWeLut)", "Text" = "'weLut'"!]
                        [!WS "8"!][!"./addr"!]U,                      /* addr */
                        [!WS "8"!][!"./size"!]U,                      /* size */
                        [!WS "8"!][!"./shift"!]U,                      /* shift */
                        [!WS "8"!][!"./width"!]U,                      /* width */
                        [!WS "8"!][!"./value"!]U,                      /* value */
                        [!IF "node:refvalid(./MemCtrlCfgPtr)"!]
                            [!WS "8"!]&([!"$configName"!]_paQspiUnitCfg[[!"node:pos(node:ref(./MemCtrlCfgPtr))"!]U])  /* MemCtrlCfgPtr */
                        [!ELSE!]
                            [!WS "8"!]NULL_PTR  /* MemCtrlCfgPtr */
                        [!ENDIF!]
                    [!WS "4"!]}[!IF "$FlsLoopIt != 0"!],[!ENDIF!][!CR!]
                [!ENDLOOP!][!//
            };
        [!ENDIF!]

        [!CALL "ComputeLutSize"!][!//

        /* paLutOperations */
        static const Qspi_Ip_InstrOpType [!"node:name(.)"!]_paLutOperations_[!"node:pos(.)"!][[!"$FlsLutSize"!]U] =
        {
            [!VAR "FlsLutIdx" = "0"!][!//
            [!LOOP "node:order(./MemLUT/*, 'node:value(./MemLUTIndex)')"!][!// Iterate through the Fls LUT Index
                [!WS "4"!]/*  [!"num:i($FlsLutIdx)"!]: [!"node:name(.)"!]  */[!CR!]
                [!LOOP "node:order(./MemInstructionOperandPair/*, 'node:value(./MemInstrOperPairIndex)')"!][!// Iterate through the Fls Instruction Operand Pair Index
                    [!VAR "FlsLutIdx" = "$FlsLutIdx + 1"!][!//
                    [!WS "4"!](Qspi_Ip_InstrOpType)((Qspi_Ip_InstrOpType)[!"./MemLUTInstruction"!] | (Qspi_Ip_InstrOpType)[!"./MemLUTPad"!] | (Qspi_Ip_InstrOpType)[!"./MemLUTOperand"!]U),
                [!ENDLOOP!][!//
                [!WS "4"!](Qspi_Ip_InstrOpType)(QSPI_IP_LUT_INSTR_STOP)[!IF "$FlsLutIdx < ($FlsLutSize - 1)"!],[!ENDIF!][!CR!]
                [!VAR "FlsLutIdx" = "$FlsLutIdx + 1"!][!//
            [!ENDLOOP!][!//
        };

    [!ENDLOOP!][!//

[!IF "$HyperflashCfgCount > 0"!][!//
    [!LOOP "MemDevice/MemHyperFlashCfg/*"!][!//
        /* hfConfig */
        static const Qspi_Ip_HyperFlashConfigType [!"node:name(.)"!]_hfConfig_[!"node:pos(.)"!] =
        {
            [!WS "4"!][!"./MemOutputDriverStrength"!],   /* MemOutputDriverStrength */
            [!WS "4"!](boolean)[!"text:toupper(./MemRWDSLowOnDualError)"!],   /* MemRWDSLowOnDualError */
            [!WS "4"!](boolean)[!"text:toupper(./MemSecureRegionUnlocked)"!],   /* MemSecureRegionUnlocked */
            [!WS "4"!][!"./MemReadLatency"!],   /* MemReadLatency */
            [!WS "4"!][!"./MemParamSectorMap"!],  /* MemParamSectorMap */
            [!WS "4"!][!"num:inttohex(./MemCfgReadIdSettings/MemCfgReadIdWordAddr)"!]U   /* deviceIdWordAddress */
        };
        [!CR!]
    [!ENDLOOP!][!//
[!ENDIF!][!//

[!IF "$FlashConfigCount > 0"!][!//
    /* paFlashCfg */
    const Qspi_Ip_MemoryConfigType [!"$configName"!]_paFlashCfg[[!"$FlashConfigCount"!]U] =
    {
        [!VAR "FlsLoopIt" = "$FlashConfigCount"!][!//
        [!LOOP "MemDevice/MemSerialFlashCfg/*"!][!//
            [!VAR "FlsLoopIt" = "$FlsLoopIt - 1"!][!//
            [!WS "4"!]{
                [!WS "8"!]/* [!"node:name(.)"!] */
                [!WS "8"!]QSPI_IP_SERIAL_FLASH,  /* memType */
                [!IF "$HyperflashCfgExists = 'true'"!][!WS "8"!]NULL_PTR,  /* hfConfig */[!CR!][!ENDIF!]
                [!WS "8"!][!"./MemCfgSize"!]U,                               /* memSize */
                [!WS "8"!][!"./MemCfgPageSize"!]U,                               /* pageSize */
                [!WS "8"!][!CALL "PrintLutIndex", "SeqNo" = "node:when(node:exists(./MemCfgReadLUT), ./MemCfgReadLUT)", "Text" = "'readLut'"!]
                [!WS "8"!][!CALL "PrintLutIndex", "SeqNo" = "node:when(node:exists(./MemCfgWriteLUT), ./MemCfgWriteLUT)", "Text" = "'writeLut'"!]
                [!WS "8"!][!CALL "PrintLutIndex", "SeqNo" = "node:when(node:exists(./MemCfgRead0xxLUT), ./MemCfgRead0xxLUT)", "Text" = "'read0xxLut'"!]
                [!WS "8"!][!CALL "PrintLutIndex", "SeqNo" = "node:when(node:exists(./MemCfgRead0xxLUTAHB), ./MemCfgRead0xxLUTAHB)", "Text" = "'read0xxLutAHB'"!]
                [!WS "8"!]/* readIdSettings */
                [!WS "8"!]{
                    [!WS "12"!][!CALL "PrintLutIndex", "SeqNo" = "node:when(node:exists(./MemCfgReadIdSettings/MemCfgReadIdLUT), ./MemCfgReadIdSettings/MemCfgReadIdLUT)", "Text" = "'readIdLut'"!]
                    [!CALL "PrintReadId", "ReadIdSettings" = "node:path(./MemCfgReadIdSettings)"!]
                [!WS "8"!]},
                [!WS "8"!]{
                    [!WS "12"!]/* eraseSettings */
                    [!WS "12"!]{
                        [!WS "16"!]{
                            [!WS "20"!]/* eraseTypes[0] */
                            [!WS "20"!][!CALL "PrintLutIndex", "SeqNo" = "node:when(node:exists(./MemCfgEraseSettings/MemCfgErase1LUT), ./MemCfgEraseSettings/MemCfgErase1LUT)", "Text" = "'eraseLut'"!]
                            [!WS "20"!][!"./MemCfgEraseSettings/MemCfgErase1Size"!]U                               /* size */
                        [!WS "16"!]},
                        [!WS "16"!]{
                            [!WS "20"!]/* eraseTypes[1] */
                            [!WS "20"!][!CALL "PrintLutIndex", "SeqNo" = "node:when(node:exists(./MemCfgEraseSettings/MemCfgErase2LUT), ./MemCfgEraseSettings/MemCfgErase2LUT)", "Text" = "'eraseLut'"!]
                            [!WS "20"!][!"./MemCfgEraseSettings/MemCfgErase2Size"!]U                               /* size */
                        [!WS "16"!]},
                        [!WS "16"!]{
                            [!WS "20"!]/* eraseTypes[2] */
                            [!WS "20"!][!CALL "PrintLutIndex", "SeqNo" = "node:when(node:exists(./MemCfgEraseSettings/MemCfgErase3LUT), ./MemCfgEraseSettings/MemCfgErase3LUT)", "Text" = "'eraseLut'"!]
                            [!WS "20"!][!"./MemCfgEraseSettings/MemCfgErase3Size"!]U                               /* size */
                        [!WS "16"!]},
                        [!WS "16"!]{
                            [!WS "20"!]/* eraseTypes[3] */
                            [!WS "20"!][!CALL "PrintLutIndex", "SeqNo" = "node:when(node:exists(./MemCfgEraseSettings/MemCfgErase4LUT), ./MemCfgEraseSettings/MemCfgErase4LUT)", "Text" = "'eraseLut'"!]
                            [!WS "20"!][!"./MemCfgEraseSettings/MemCfgErase4Size"!]U                               /* size */
                        [!WS "16"!]}
                    [!WS "12"!]},
                    [!WS "12"!][!CALL "PrintLutIndex", "SeqNo" = "node:when(node:exists(./MemCfgEraseSettings/MemChipEraseLUT), ./MemCfgEraseSettings/MemChipEraseLUT)", "Text" = "'ChipEraseLUT'", "Comma" = "' '"!]
                [!WS "8"!]},
                [!WS "8"!]{
                    [!WS "12"!]/* MemStatusConfig */
                    [!WS "12"!][!CALL "PrintLutIndex", "SeqNo" = "node:when(node:exists(./MemStatusConfig/MemStatusRegInitReadLut), ./MemStatusConfig/MemStatusRegInitReadLut)", "Text" = "'statusRegInitReadLut'"!]
                    [!WS "12"!][!CALL "PrintLutIndex", "SeqNo" = "node:when(node:exists(./MemStatusConfig/MemStatusRegReadLut), ./MemStatusConfig/MemStatusRegReadLut)", "Text" = "'statusRegReadLut'"!]
                    [!WS "12"!][!CALL "PrintLutIndex", "SeqNo" = "node:when(node:exists(./MemStatusConfig/MemStatusRegWriteLut), ./MemStatusConfig/MemStatusRegWriteLut)", "Text" = "'statusRegWriteLut'"!]
                    [!WS "12"!][!CALL "PrintLutIndex", "SeqNo" = "node:when(node:exists(./MemStatusConfig/MemWriteEnableSRLut), ./MemStatusConfig/MemWriteEnableSRLut)", "Text" = "'writeEnableSRLut'"!]
                    [!WS "12"!][!CALL "PrintLutIndex", "SeqNo" = "node:when(node:exists(./MemStatusConfig/MemWriteEnableLut), ./MemStatusConfig/MemWriteEnableLut)", "Text" = "'writeEnableLut'"!]
                    [!WS "12"!][!"./MemStatusConfig/MemRegSize"!]U,                               /* MemRegSize */
                    [!WS "12"!][!"./MemStatusConfig/MemBusyOffset"!]U,                               /* MemBusyOffset */
                    [!WS "12"!][!"./MemStatusConfig/MemBusyValue"!]U,                               /* MemBusyValue */
                    [!WS "12"!][!"./MemStatusConfig/MemWriteEnableOffset"!]U,                               /* MemWriteEnableOffset */
                    [!WS "12"!][!"./MemStatusConfig/MemBlockProtectionOffset"!]U,                               /* MemBlockProtectionOffset */
                    [!WS "12"!][!"./MemStatusConfig/MemBlockProtectionWidth"!]U,                               /* MemBlockProtectionWidth */
                    [!WS "12"!][!"./MemStatusConfig/MemBlockProtectionValue"!]U                                /* MemBlockProtectionValue */
                [!WS "8"!]},
                [!WS "8"!]{
                    [!WS "12"!]/* MemSuspendSettings */
                    [!WS "12"!][!CALL "PrintLutIndex", "SeqNo" = "node:when(node:exists(./MemSuspendSettings/MemEraseSuspendLut), ./MemSuspendSettings/MemEraseSuspendLut)", "Text" = "'eraseSuspendLut'"!]
                    [!WS "12"!][!CALL "PrintLutIndex", "SeqNo" = "node:when(node:exists(./MemSuspendSettings/MemEraseResumeLut), ./MemSuspendSettings/MemEraseResumeLut)", "Text" = "'eraseResumeLut'"!]
                    [!WS "12"!][!CALL "PrintLutIndex", "SeqNo" = "node:when(node:exists(./MemSuspendSettings/MemProgramSuspendLut), ./MemSuspendSettings/MemProgramSuspendLut)", "Text" = "'programSuspendLut'"!]
                    [!WS "12"!][!CALL "PrintLutIndex", "SeqNo" = "node:when(node:exists(./MemSuspendSettings/MemProgramResumeLut), ./MemSuspendSettings/MemProgramResumeLut)", "Text" = "'programResumeLut'", "Comma" = "' '"!]
                [!WS "8"!]},
                [!WS "8"!]{
                    [!WS "12"!]/* MemResetSettings */
                    [!WS "12"!][!CALL "PrintLutIndex", "SeqNo" = "node:when(node:exists(./MemResetSettings/MemResetCmdLut), ./MemResetSettings/MemResetCmdLut)", "Text" = "'resetCmdLut'"!]
                    [!WS "12"!][!"./MemResetSettings/MemResetCmdCount"!]U                               /* MemResetCmdCount */
                [!WS "8"!]},
                [!WS "8"!]{
                    [!WS "12"!]/* MemInitResetSettings */
                    [!WS "12"!][!CALL "PrintLutIndex", "SeqNo" = "node:when(node:exists(./MemInitResetSettings/MemResetCmdLut), ./MemInitResetSettings/MemResetCmdLut)", "Text" = "'resetCmdLut'"!]
                    [!WS "12"!][!"./MemInitResetSettings/MemResetCmdCount"!]U                               /* MemResetCmdCount */
                [!WS "8"!]},
                [!WS "8"!]{
                    [!WS "12"!]/* MemInitConfiguration */
                    [!WS "12"!][!"num:i(count(./MemInitConfiguration/*))"!]U,                                  /* opCount */
                    [!IF "num:i(count(./MemInitConfiguration/*)) > 0"!]
                        [!WS "12"!](Qspi_Ip_InitOperationType *)[!"node:name(.)"!]_paInitOperations_[!"node:pos(.)"!]                    /* operations */
                    [!ELSE!]
                        [!WS "12"!]NULL_PTR                                /* operations */
                    [!ENDIF!]
                [!WS "8"!]},
                [!WS "8"!]{
                    [!WS "12"!]/* lutSequences */
                    [!VAR "FlsLutSize" = "0"!][!//
                    [!LOOP "./MemLUT/*"!][!//
                        [!VAR "FlsLutSize" = "$FlsLutSize + count(./MemInstructionOperandPair/*) + 1"!][!//
                    [!ENDLOOP!][!//
                    [!WS "12"!][!"num:i($FlsLutSize)"!]U,                                        /* opCount */
                    [!WS "12"!](Qspi_Ip_InstrOpType *)[!"node:name(.)"!]_paLutOperations_[!"node:pos(.)"!]       /* lutOps */
                [!WS "8"!]},
                [!IF "node:exists(../../../MemQspiInitCallout)"!]
                    [!WS "8"!]&[!"normalize-space(text:join(//FlsConfigSet/MemQspiInitCallout))"!],                    /* initCallout */
                [!ELSE!]
                    [!WS "8"!]NULL_PTR,                               /* initCallout */
                [!ENDIF!]
                [!IF "node:exists(../../../MemQspiResetCallout)"!]
                    [!WS "8"!]&[!"normalize-space(text:join(//FlsConfigSet/MemQspiResetCallout))"!],                    /* resetCallout */
                [!ELSE!]
                    [!WS "8"!]NULL_PTR,                               /* resetCallout */
                [!ENDIF!]
                [!IF "node:exists(../../../MemQspiErrorCheckCallout)"!]
                    [!WS "8"!]&[!"normalize-space(text:join(//FlsConfigSet/MemQspiErrorCheckCallout))"!],                   /* errorCheckCallout */
                [!ELSE!]
                    [!WS "8"!]NULL_PTR,                              /* errorCheckCallout */
                [!ENDIF!]
                [!IF "node:exists(../../../MemQspiEccCheckCallout)"!]
                    [!WS "8"!]&[!"normalize-space(text:join(//FlsConfigSet/MemQspiEccCheckCallout))"!],                    /* eccCheckCallout */
                [!ELSE!]
                    [!WS "8"!]NULL_PTR,                               /* eccCheckCallout */
                [!ENDIF!]
                [!IF "node:refvalid(./MemCtrlAutoCfgPtr)"!]
                    [!WS "8"!]&([!"$configName"!]_paQspiUnitCfg[[!"node:pos(node:ref(./MemCtrlAutoCfgPtr))"!]U])  /* MemCtrlAutoCfgPtr */
                [!ELSE!]
                    [!WS "8"!]NULL_PTR  /* MemCtrlAutoCfgPtr */
                [!ENDIF!]
            [!WS "4"!]}[!IF "$FlsLoopIt != 0"!],[!ENDIF!][!CR!]
        [!ENDLOOP!][!//
        [!LOOP "MemDevice/MemHyperFlashCfg/*"!][!//
            [!VAR "FlsLoopIt" = "$FlsLoopIt - 1"!][!//
            [!WS "4"!]{
                [!WS "8"!]/* [!"node:name(.)"!] */
                [!WS "8"!]QSPI_IP_HYPER_FLASH,  /* memType */
                [!WS "8"!]&[!"node:name(.)"!]_hfConfig_[!"node:pos(.)"!],  /* hfConfig */
                [!WS "8"!][!"./MemCfgSize"!]U,  /* memSize */
                [!WS "8"!][!"./MemCfgPageSize"!]U,  /* pageSize */
                [!WS "8"!]QSPI_IP_HF_LUT_READ,   /* readLut */
                [!WS "8"!]QSPI_IP_HF_LUT_WRITE,  /* writeLut */
                [!WS "8"!]QSPI_IP_LUT_INVALID,   /* read0xxLut */
                [!WS "8"!]QSPI_IP_LUT_INVALID,   /* read0xxLutAHB */
                [!WS "8"!]/* readIdSettings */
                [!WS "8"!]{
                    [!WS "12"!][!IF "node:exists(./MemCfgReadIdSettings/MemCfgReadIdLUT)"!][!"./MemCfgReadIdSettings/MemCfgReadIdLUT"!][!ELSE!]QSPI_IP_LUT_INVALID[!ENDIF!],  /* readIdLut */
                    [!CALL "PrintReadId", "ReadIdSettings" = "node:path(./MemCfgReadIdSettings)"!]
                [!WS "8"!]},
                [!WS "8"!]{
                    [!WS "12"!]/* eraseSettings */
                    [!WS "12"!]{
                        [!WS "16"!]{
                            [!WS "20"!]/* eraseTypes[0] */
                            [!WS "20"!]QSPI_IP_HF_LUT_SE,    /* eraseLut */
                            [!WS "20"!]12U                   /* size 4KB */
                        [!WS "16"!]},
                        [!WS "16"!]{
                            [!WS "20"!]/* eraseTypes[1] */
                            [!WS "20"!]QSPI_IP_HF_LUT_SE,    /* eraseLut */
                            [!WS "20"!]18U                   /* size 256KB */
                        [!WS "16"!]},
                        [!WS "16"!]{
                            [!WS "20"!]/* eraseTypes[2] */
                            [!WS "20"!]QSPI_IP_LUT_INVALID,  /* eraseLut */
                            [!WS "20"!]0U                    /* size */
                        [!WS "16"!]},
                        [!WS "16"!]{
                            [!WS "20"!]/* eraseTypes[3] */
                            [!WS "20"!]QSPI_IP_LUT_INVALID,  /* eraseLut */
                            [!WS "20"!]0U                    /* size */
                        [!WS "16"!]}
                    [!WS "12"!]},
                    [!WS "12"!]QSPI_IP_HF_LUT_CE  /* MemChipEraseLUT */
                [!WS "8"!]},
                [!WS "8"!]{
                    [!WS "12"!]/* MemStatusConfig */
                    [!WS "12"!]QSPI_IP_LUT_INVALID,  /* MemStatusRegInitReadLut */
                    [!WS "12"!]QSPI_IP_LUT_INVALID,  /* MemStatusRegReadLut */
                    [!WS "12"!]QSPI_IP_LUT_INVALID,  /* MemStatusRegWriteLut */
                    [!WS "12"!]QSPI_IP_LUT_INVALID,  /* MemWriteEnableSRLut */
                    [!WS "12"!]QSPI_IP_LUT_INVALID,  /* MemWriteEnableLut */
                    [!WS "12"!]0U,                   /* MemRegSize */
                    [!WS "12"!]0U,                   /* MemBusyOffset */
                    [!WS "12"!]0U,                   /* MemBusyValue */
                    [!WS "12"!]0U,                   /* MemWriteEnableOffset */
                    [!WS "12"!]0U,                   /* MemBlockProtectionOffset */
                    [!WS "12"!]0U,                   /* MemBlockProtectionWidth */
                    [!WS "12"!]0U                    /* MemBlockProtectionValue */
                [!WS "8"!]},
                [!WS "8"!]{
                    [!WS "12"!]/* MemSuspendSettings */
                    [!WS "12"!]QSPI_IP_HF_LUT_ES,  /* MemEraseSuspendLut */
                    [!WS "12"!]QSPI_IP_HF_LUT_ER,  /* MemEraseResumeLut */
                    [!WS "12"!]QSPI_IP_HF_LUT_PS,  /* MemProgramSuspendLut */
                    [!WS "12"!]QSPI_IP_HF_LUT_PR   /* MemProgramResumeLut */
                [!WS "8"!]},
                [!WS "8"!]{
                    [!WS "12"!]/* MemResetSettings */
                    [!WS "12"!]QSPI_IP_HF_LUT_RST,  /* MemResetCmdLut */
                    [!WS "12"!]QSPI_IP_HF_RST_CNT   /* MemResetCmdCount */
                [!WS "8"!]},
                [!WS "8"!]{
                    [!WS "12"!]/* MemInitResetSettings */
                    [!WS "12"!]QSPI_IP_LUT_INVALID,  /* MemResetCmdLut */
                    [!WS "12"!]0U                    /* MemResetCmdCount */
                [!WS "8"!]},
                [!WS "8"!]{
                    [!WS "12"!]/* MemInitConfiguration */
                    [!WS "12"!]0U,        /* opCount */
                    [!WS "12"!]NULL_PTR   /* operations */
                [!WS "8"!]},
                [!WS "8"!]{
                    [!WS "12"!]/* lutSequences */
                    [!WS "12"!]QSPI_IP_HF_LUT_SIZE,                        /* opCount */
                    [!WS "12"!](Qspi_Ip_InstrOpType *)QSPI_IP_HF_LUT_NAME  /* lutOps */
                [!WS "8"!]},
                [!IF "node:exists(../../../MemQspiInitCallout)"!]
                    [!WS "8"!]&[!"normalize-space(text:join(//FlsConfigSet/MemQspiInitCallout))"!],  /* initCallout */
                [!ELSE!]
                    [!WS "8"!]NULL_PTR,  /* initCallout */
                [!ENDIF!]
                [!IF "node:exists(../../../MemQspiResetCallout)"!]
                    [!WS "8"!]&[!"normalize-space(text:join(//FlsConfigSet/MemQspiResetCallout))"!],  /* resetCallout */
                [!ELSE!]
                    [!WS "8"!]NULL_PTR,  /* resetCallout */
                [!ENDIF!]
                [!IF "node:exists(../../../MemQspiErrorCheckCallout)"!]
                    [!WS "8"!]&[!"normalize-space(text:join(//FlsConfigSet/MemQspiErrorCheckCallout))"!],  /* errorCheckCallout */
                [!ELSE!]
                    [!WS "8"!]NULL_PTR,  /* errorCheckCallout */
                [!ENDIF!]
                [!IF "node:exists(../../../MemQspiEccCheckCallout)"!]
                    [!WS "8"!]&[!"normalize-space(text:join(//FlsConfigSet/MemQspiEccCheckCallout))"!],  /* eccCheckCallout */
                [!ELSE!]
                    [!WS "8"!]NULL_PTR,  /* eccCheckCallout */
                [!ENDIF!]
                [!IF "node:refvalid(./MemCtrlAutoCfgPtr)"!]
                    [!WS "8"!]&([!"$configName"!]_paQspiUnitCfg[[!"node:pos(node:ref(./MemCtrlAutoCfgPtr))"!]U])  /* MemCtrlAutoCfgPtr */
                [!ELSE!]
                    [!WS "8"!]NULL_PTR  /* MemCtrlAutoCfgPtr */
                [!ENDIF!]
            [!WS "4"!]}[!IF "$FlsLoopIt != 0"!],[!ENDIF!][!CR!]
        [!ENDLOOP!][!//
    };
[!ENDIF!][!//

#define MEM_43_EXFLS_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Mem_43_ExFls_MemMap.h"

[!ENDINDENT!][!//
[!ENDCODE!][!//

#ifdef __cplusplus
}
#endif

/** @}*/
