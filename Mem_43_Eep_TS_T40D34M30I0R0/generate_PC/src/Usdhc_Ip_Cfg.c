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

/**
* @file Usdhc_Ip[!"$variantName"!]_PBcfg.c
*
* @addtogroup Usdhc_Ip
* @{
*/

#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Usdhc_Ip_Cfg.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define USDHC[!"$variantNameUpperCase"!]_VENDOR_ID_IP_PBCFG_C                      43
#define USDHC[!"$variantNameUpperCase"!]_AR_RELEASE_MAJOR_VERSION_IP_PBCFG_C       4
#define USDHC[!"$variantNameUpperCase"!]_AR_RELEASE_MINOR_VERSION_IP_PBCFG_C       7
#define USDHC[!"$variantNameUpperCase"!]_AR_RELEASE_REVISION_VERSION_IP_PBCFG_C    0
#define USDHC[!"$variantNameUpperCase"!]_SW_MAJOR_VERSION_IP_PBCFG_C               3
#define USDHC[!"$variantNameUpperCase"!]_SW_MINOR_VERSION_IP_PBCFG_C               0
#define USDHC[!"$variantNameUpperCase"!]_SW_PATCH_VERSION_IP_PBCFG_C               0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and Usdhc_Ip_Cfg header file are of the same vendor */
#if (USDHC[!"$variantNameUpperCase"!]_VENDOR_ID_IP_PBCFG_C != USDHC_VENDOR_ID_IP_CFG)
    #error "AutoSar Version Numbers of Usdhc_Ip[!"$variantName"!]_PBcfg.c and Usdhc_Ip_Cfg.h have different vendor ids"
#endif
/* Check if current file and Usdhc_Ip_Cfg header file are of the same Autosar version */
#if ((USDHC[!"$variantNameUpperCase"!]_AR_RELEASE_MAJOR_VERSION_IP_PBCFG_C    != USDHC_AR_RELEASE_MAJOR_VERSION_IP_CFG) || \
     (USDHC[!"$variantNameUpperCase"!]_AR_RELEASE_MINOR_VERSION_IP_PBCFG_C    != USDHC_AR_RELEASE_MINOR_VERSION_IP_CFG) || \
     (USDHC[!"$variantNameUpperCase"!]_AR_RELEASE_REVISION_VERSION_IP_PBCFG_C != USDHC_AR_RELEASE_REVISION_VERSION_IP_CFG) \
    )
    #error "AutoSar Version Numbers of Usdhc_Ip[!"$variantName"!]_PBcfg.c and Usdhc_Ip_Cfg.h are different"
#endif
/* Check if current file and Usdhc_Ip_Cfg header file are of the same Software version */
#if ((USDHC[!"$variantNameUpperCase"!]_SW_MAJOR_VERSION_IP_PBCFG_C != USDHC_SW_MAJOR_VERSION_IP_CFG) || \
     (USDHC[!"$variantNameUpperCase"!]_SW_MINOR_VERSION_IP_PBCFG_C != USDHC_SW_MINOR_VERSION_IP_CFG) || \
     (USDHC[!"$variantNameUpperCase"!]_SW_PATCH_VERSION_IP_PBCFG_C != USDHC_SW_PATCH_VERSION_IP_CFG) \
    )
    #error "Software Version Numbers of Usdhc_Ip[!"$variantName"!]_PBcfg.c and Usdhc_Ip_Cfg.h are different"
#endif
/*==================================================================================================
                                     FUNCTION PROTOTYPES
==================================================================================================*/
[!NOCODE!][!//
[!INDENT "0"!]
[!IF "node:exists(Mem_43_EepUsdhcControllerCfg)"!][!//
    [!SELECT "Mem_43_EepUsdhcControllerCfg"!]
    [!LOOP "./*"!][!//
        [!IF "(node:exists(cardInsertCallback) and (node:value(cardInsertCallback) != 'NULL_PTR'))"!][!//
            [!CODE!][!//
            /* Declaration of [!"node:name(./cardInsertCallback)"!] function*/
            extern void [!"./cardInsertCallback"!](uint32 instance, uint32 status);
            [!ENDCODE!][!//
        [!ENDIF!]
        [!IF "(node:exists(cardRemoveCallback) and (node:value(cardRemoveCallback) != 'NULL_PTR'))"!][!//
            [!CODE!][!//
            /* Declaration of [!"node:name(./cardRemoveCallback)"!] function*/
            extern void [!"./cardRemoveCallback"!](uint32 instance, uint32 status);
            [!ENDCODE!][!//
        [!ENDIF!]
        [!IF "(node:exists(transferCompleteCallback) and (node:value(transferCompleteCallback) != 'NULL_PTR'))"!][!//
            [!CODE!][!//
            /* Declaration of [!"node:name(./transferCompleteCallback)"!] function*/
            extern void [!"./transferCompleteCallback"!](uint32 instance, uint32 status);
            [!ENDCODE!][!//
        [!ENDIF!]
        [!IF "(node:exists(transferErrorCallback) and (node:value(transferErrorCallback) != 'NULL_PTR'))"!][!//
            [!CODE!][!//
            /* Declaration of [!"node:name(./transferErrorCallback)"!] function*/
            extern void [!"./transferErrorCallback"!](uint32 instance, uint32 status);
            [!ENDCODE!][!//
        [!ENDIF!]
        [!IF "(node:exists(blockGapCallback) and (node:value(blockGapCallback) != 'NULL_PTR'))"!][!//
            [!CODE!][!//
            /* Declaration of [!"node:name(./blockGapCallback)"!] function*/
            extern void [!"./blockGapCallback"!](uint32 instance, uint32 status);
            [!ENDCODE!][!//
        [!ENDIF!]
        [!IF "(node:exists(cardIntCallback) and (node:value(cardIntCallback) != 'NULL_PTR'))"!][!//
            [!CODE!][!//
            /* Declaration of [!"node:name(./cardIntCallback)"!] function*/
            extern void [!"./cardIntCallback"!](uint32 instance, uint32 status);
            [!ENDCODE!][!//
        [!ENDIF!]
    [!ENDLOOP!][!//
    [!ENDSELECT!]
[!ENDIF!]
[!ENDINDENT!]
[!ENDNOCODE!][!//

/*==================================================================================================
                                           CONSTANTS
==================================================================================================*/
[!INDENT "0"!]
[!IF "node:exists(Mem_43_EepUsdhcControllerCfg)"!][!//
    [!SELECT "Mem_43_EepUsdhcControllerCfg"!]
    [!LOOP "./*"!][!//
        [!NOCODE!][!//
[!IF "node:exists(BootHostConfig)"!]
        [!VAR "bootFlagsVal" = "string(null)"!][!//
        [!IF "./BootHostConfig/ackFlag ='true'"!][!//
            [!VAR "bootFlagsVal" = "'USDHC_ENABLE_BOOT_ACK_FLAG | '"!][!//
        [!ELSE!][!//
            [!VAR "bootFlagsVal" = "concat($bootFlagsVal,'USDHC_DISABLE_BOOT_ACK_FLAG | ')"!][!//
        [!ENDIF!][!//
        [!IF "./BootHostConfig/disChkTimeout ='true'"!][!//
            [!VAR "bootFlagsVal" = "concat($bootFlagsVal,'USDHC_DISABLE_TIME_OUT_FLAG | ')"!][!//
        [!ELSE!][!//
            [!VAR "bootFlagsVal" = "concat($bootFlagsVal,'USDHC_ENABLE_TIME_OUT_FLAG | ')"!][!//
        [!ENDIF!][!//
        [!IF "./BootHostConfig/autoBlkGap ='true'"!][!//
            [!VAR "bootFlagsVal" = "concat($bootFlagsVal,'USDHC_ENABLE_BOOT_STOP_AT_BLK_GAP_FLAG')"!][!//
        [!ELSE!][!//
            [!VAR "bootFlagsVal" = "concat($bootFlagsVal,'USDHC_DISABLE_BOOT_STOP_AT_BLK_GAP_FLAG')"!][!//
        [!ENDIF!][!//
[!ENDIF!]
        [!ENDNOCODE!][!//
            #define MEM_43_EEP_START_SEC_VAR_CLEARED_32_NO_CACHEABLE
            #include "Mem_43_Eep_MemMap.h"
            /* Adma table for [!"node:name(.)"!] */
            static uint32 [!"./admaTable"!][!"$variantName"!][[!"./admaTableSize"!]U / 4U];
            #define MEM_43_EEP_STOP_SEC_VAR_CLEARED_32_NO_CACHEABLE
            #include "Mem_43_Eep_MemMap.h"

        #define MEM_43_EEP_START_SEC_CONFIG_DATA_UNSPECIFIED
        #include "Mem_43_Eep_MemMap.h"
        [!IF "node:exists(BootHostConfig)"!]
        static const Usdhc_Ip_BootConfigType [!"node:name(.)"!]_Boot[!"$variantName"!] =
        {
            [!WS "4"!][!"./BootHostConfig/ackTimeout"!]U, /* ackTimeout */
            [!WS "4"!][!"./BootHostConfig/bootMode"!], /* bootMode */
            [!WS "4"!][!"./BootHostConfig/stopBlockGapCount"!]U, /* stopBlockGapCount */
            [!WS "4"!][!"./BootHostConfig/bootBusWidth"!], /* bootBusWidth */
            [!WS "4"!](boolean)[!"text:toupper(./BootHostConfig/ddrEnable)"!], /* enableDDR */
            [!WS "4"!][!"$bootFlagsVal"!], /* bootFlags */
        };
        [!ENDIF!]
        /* uSDHC User Configurations [!"node:name(.)"!] */
        const Usdhc_Ip_ConfigType [!"node:name(.)"!][!"$variantName"!] =
        {
                [!WS "4"!]0U, /* Instance number */
                [!WS "4"!](boolean)[!"text:toupper(./cardDetectDat3)"!], /* cardDetectDat3 */
                [!WS "4"!](boolean)[!"text:toupper(./EnableAutoCMD12)"!], /* EnableAutoCMD12 */
                [!WS "4"!][!"./endianMode"!], /* endianMode */
                [!WS "4"!][!"./dmaMode"!], /* dmaMode */
                [!WS "4"!][!"./admaTable"!][!"$variantName"!], /* admaTable */
                [!WS "4"!][!"./admaTableSize"!]U, /* admaTableSize */
                [!WS "4"!][!"./WriteWatermarkLevel"!]U, /* writeWatermarkLevel */
                [!WS "4"!][!"./ReadWatermarkLevel"!]U, /* readWatermarkLevel */
                [!WS "4"!][!IF "node:exists(cardInsertCallback)"!]&[!"./cardInsertCallback"!][!ELSE!]NULL_PTR[!ENDIF!], /* cardInsertCallback */
                [!WS "4"!][!IF "node:exists(cardRemoveCallback)"!]&[!"./cardRemoveCallback"!][!ELSE!]NULL_PTR[!ENDIF!], /* cardRemoveCallback */
                [!WS "4"!][!IF "node:exists(transferCompleteCallback)"!]&[!"./transferCompleteCallback"!][!ELSE!]NULL_PTR[!ENDIF!], /* transferCompleteCallback */
                [!WS "4"!][!IF "node:exists(transferErrorCallback)"!]&[!"./transferErrorCallback"!][!ELSE!]NULL_PTR[!ENDIF!], /* transferErrorCallback */
                [!WS "4"!][!IF "node:exists(blockGapCallback)"!]&[!"./blockGapCallback"!][!ELSE!]NULL_PTR[!ENDIF!], /* blockGapCallback */
                [!WS "4"!][!IF "node:exists(cardIntCallback)"!]&[!"./cardIntCallback"!][!ELSE!]NULL_PTR[!ENDIF!], /* cardIntCallback */
                [!IF "node:exists(BootHostConfig)"!][!//
                    [!WS "4"!]&[!"node:name(.)"!]_Boot[!"$variantName"!][!ELSE!]NULL_PTR
                [!ENDIF!]
        };

        #define MEM_43_EEP_STOP_SEC_CONFIG_DATA_UNSPECIFIED
        #include "Mem_43_Eep_MemMap.h"
    [!ENDLOOP!][!ENDSELECT!][!ENDIF!][!ENDINDENT!]
[!ENDCODE!]
#ifdef __cplusplus
}
#endif

/** @}*/
