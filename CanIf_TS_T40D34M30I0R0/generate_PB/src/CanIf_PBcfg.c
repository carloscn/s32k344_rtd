/*==================================================================================================
*   Project              : RTD AUTOSAR 4.7
*   Platform             : CORTEXM
*   Peripheral           : generic
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
/*==================================================================================================
==================================================================================================*/

/**
*   @file    CanIf_PBcfg[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!].c
*   @version 3.0.0
*
*   @brief   AUTOSAR CanIf - module interface
*   @details Configuration Structures for PostBuild
*
*   @addtogroup CANIF_DRIVER
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
==================================================================================================*/
#include "CanIf.h"
[!NOCODE!]
[!IF "var:defined('postBuildVariant')"!]
    [!VAR "postBuildVariantNameUnderscore" = "concat('_',$postBuildVariant)"!]
[!ELSE!]
    [!VAR "postBuildVariantNameUnderscore" = "string(null)"!]
[!ENDIF!]
[!ENDNOCODE!]

[!LOOP "CanIfPublicCfg/CanIfPublicCddHeaderFile/*"!][!//
#include "[!"."!].h"
[!ENDLOOP!]
[!AUTOSPACING!]
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define CANIF_VENDOR_ID_PBCFG[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_C                      43
#define CANIF_AR_RELEASE_MAJOR_VERSION_PBCFG[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_C       4
#define CANIF_AR_RELEASE_MINOR_VERSION_PBCFG[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_C       7
#define CANIF_AR_RELEASE_REVISION_VERSION_PBCFG[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_C    0
#define CANIF_SW_MAJOR_VERSION_PBCFG[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_C               3
#define CANIF_SW_MINOR_VERSION_PBCFG[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_C               0
#define CANIF_SW_PATCH_VERSION_PBCFG[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_C               0
/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/

/*==================================================================================================
*                                      GLOBAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                   GLOBAL FUNCTION PROTOTYPES
==================================================================================================*/

/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
*                                      LOCAL CONSTANTS
==================================================================================================*/
[!NOCODE!]
[!LOOP "./CanIfInitCfg/CanIfInitHohCfg/*/CanIfHthCfg/*"!]
    [!IF "node:ref(./CanIfHthCanCtrlIdRef)/CanIfCtrlCanCtrlRef != node:ref(./CanIfHthIdSymRef)/CanControllerRef"!]
        [!ERROR!]
            For [!"@name"!] of [!"../../@name"!],
            The CanHTH referred via CanIfHthIdSymRef must belong to the CanController referred via CanIfHthCanCtrlIdRef!
        [!ENDERROR!]
    [!ENDIF!]
    [!IF "node:ref(./CanIfHthIdSymRef)/CanObjectType != 'TRANSMIT'"!]
        [!ERROR!]
            For [!"@name"!] of [!"../../@name"!],
            The CanHOH referred via CanIfHthIdSymRef must be TRANSMIT object!
        [!ENDERROR!]
    [!ENDIF!]
[!ENDLOOP!]

[!LOOP "./CanIfInitCfg/CanIfInitHohCfg/*/CanIfHrhCfg/*"!]
    [!IF "node:ref(./CanIfHrhCanCtrlIdRef)/CanIfCtrlCanCtrlRef != node:ref(./CanIfHrhIdSymRef)/CanControllerRef"!]
        [!ERROR!]
            For [!"@name"!] of [!"../../@name"!],
            The CanHRH referred via CanIfHrhIdSymRef must belong to the CanController referred via CanIfHrhCanCtrlIdRef!
        [!ENDERROR!]
    [!ENDIF!]
    [!IF "node:ref(./CanIfHrhIdSymRef)/CanObjectType != 'RECEIVE'"!]
        [!ERROR!]
            For [!"@name"!] of [!"../../@name"!],
            The CanHOH referred via CanIfHrhIdSymRef must be RECEIVE object!
        [!ENDERROR!]
    [!ENDIF!]
[!ENDLOOP!]
[!ENDNOCODE!]

#define CANIF_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"

[!NOCODE!]
[!VAR "CanDrv_Name" = "'Can'"!]
[!MACRO "CanIf_Get_CanDrv_Name", "Driver_Path"!][!// If no vendor API infix found, CanDrv_Name will be 'Can'
    [!VAR "CanDrv_Name" = "'Can'"!]
    [!IF "node:exists(node:ref($Driver_Path)/../CommonPublishedInformation/VendorApiInfix) and node:ref($Driver_Path)/../CommonPublishedInformation/VendorApiInfix != ''"!]
        [!VAR "CanDrv_VendorId" = "node:ref($Driver_Path)/../CommonPublishedInformation/VendorId"!]
        [!VAR "CanDrv_VenorApiInfix" = "node:ref($Driver_Path)/../CommonPublishedInformation/VendorApiInfix"!]
        [!VAR "CanDrv_Name"= "concat('Can_', $CanDrv_VendorId, '_', $CanDrv_VenorApiInfix)"!]
    [!ENDIF!]
[!ENDMACRO!]
[!ENDNOCODE!]

[!INDENT "0"!]
[!VAR "Num_TxPdu" = "num:i(count(./CanIfInitCfg/CanIfTxPduCfg/*))"!]
[!IF "$Num_TxPdu > 0"!]
    /* Here is the TxPdu configuration */
    static const CanIf_TxPduType CanIf_TxPdu[[!"$Num_TxPdu"!]U] =
    {
    [!VAR "PduIndex" = "num:i(0)"!]
    [!LOOP "node:order(./CanIfInitCfg/CanIfTxPduCfg/*, './CanIfTxPduId')"!]
        [!INDENT "4"!]
        {
            [!INDENT "8"!]
            /* .PduIdType */
            (uint8)[!"CanIfTxPduId"!]U,
            /* .CanId */
            (Can_IdType)[!"CanIfTxPduCanId"!]U,
            /* .CanFrameType */
            CANIF_[!"CanIfTxPduCanIdType"!],
            /* .Can_HwHandleType */
            (Can_HwHandleType)[!"num:i(node:ref(node:ref(node:ref(./CanIfTxPduBufferRef)/CanIfBufferHthRef)/CanIfHthIdSymRef)/CanObjectId)"!]U,
            /* .CanIfCtrlId */
            (uint8)[!"num:i(node:ref(node:ref(node:ref(./CanIfTxPduBufferRef)/CanIfBufferHthRef)/CanIfHthCanCtrlIdRef)/CanIfCtrlId)"!]U,
            /* .UserTxConfirmation */
            [!IF "node:exists(CanIfTxPduUserTxConfirmationName)"!][!"normalize-space(CanIfTxPduUserTxConfirmationName)"!][!ELSE!]NULL_PTR[!ENDIF!][!CR!]
            [!VAR "PduIndex" = "$PduIndex + 1"!]
            [!ENDINDENT!]
        }[!IF "num:i($PduIndex) < $Num_TxPdu"!],[!ENDIF!][!CR!]
        [!ENDINDENT!]
    [!ENDLOOP!]
    };
[!ENDIF!]
[!ENDINDENT!]

[!INDENT "0"!]
[!VAR "Num_RxPdu" = "num:i(count(./CanIfInitCfg/CanIfRxPduCfg/*))"!]
[!IF "$Num_RxPdu > 0"!]
    /* Here is the RxPdu configuration */
    static const CanIf_RxPduType CanIf_RxPdu[[!"$Num_RxPdu"!]U] =
    {
    [!VAR "PduIndex" = "num:i(0)"!]
    [!LOOP "node:order(./CanIfInitCfg/CanIfRxPduCfg/*, './CanIfRxPduId')"!]
    [!INDENT "4"!]
    {
        [!INDENT "8"!]
        /* .PduId */
        (uint8)[!"CanIfRxPduId"!]U,
        /* .PduLengthCheck */
        (boolean)[!IF "node:exists(./CanIfRxPduDataLengthCheck)"!][!"text:toupper(./CanIfRxPduDataLengthCheck)"!][!ELSE!]FALSE[!ENDIF!],[!CR!]
        /* .PduLength */
        (uint16)[!IF "node:exists(./CanIfRxPduDataLength)"!][!"./CanIfRxPduDataLength"!][!ELSE!]8[!ENDIF!]U,
        /* .CanIfCtrlId */
        (uint8)[!"num:i(node:ref(node:ref(./CanIfRxPduHrhIdRef)/CanIfHrhCanCtrlIdRef)/CanIfCtrlId)"!]U,
        /* .UserRxIndication */
        [!IF "node:exists(CanIfRxPduUserRxIndicationName)"!][!"normalize-space(CanIfRxPduUserRxIndicationName)"!][!ELSE!]NULL_PTR[!ENDIF!][!CR!]
        [!VAR "PduIndex" = "$PduIndex + 1"!]
        [!ENDINDENT!]
        }[!IF "num:i($PduIndex) < $Num_RxPdu"!],[!ENDIF!][!CR!]
        [!ENDINDENT!]
    [!ENDLOOP!]
    };
[!ENDIF!]
[!ENDINDENT!]

[!VAR "Num_CanDrv" = "num:i(count(./CanIfCtrlDrvCfg/*))"!]
[!IF "$Num_CanDrv > 0"!]
    [!LOOP "./CanIfCtrlDrvCfg/*"!]
        [!CALL "CanIf_Get_CanDrv_Name", "Driver_Path"="(./CanIfCtrlDrvNameRef)"!]

        [!VAR "Num_CanDrv_Hoh" = "num:i(count(node:ref(./CanIfCtrlDrvNameRef)/../CanConfigSet/CanHardwareObject/*))"!]
        [!IF "$Num_CanDrv_Hoh > 0"!]
        [!INDENT "0"!]
        /* Here is the configuration related to [!"$CanDrv_Name"!] Driver */
        static const CanIf_RxPduType * const CanIf_[!"$CanDrv_Name"!]_HohToRxPduMapping[[!"$Num_CanDrv_Hoh"!]U] = 
        {
            [!INDENT "4"!]
            [!FOR "i" = "0" TO "$Num_CanDrv_Hoh - 1"!]
                [!VAR "IsHohUsed" = "0"!]
                [!VAR "RxPduId" = "0"!]
                [!VAR "Can_Hoh_Path" = "node:path(node:ref(./CanIfCtrlDrvNameRef)/../CanConfigSet/CanHardwareObject/*[CanObjectId = $i])"!]
                [!LOOP "node:order(../../CanIfInitCfg/CanIfRxPduCfg/*, './CanIfRxPduId')"!]
                    [!IF "node:path(node:ref(node:ref(CanIfRxPduHrhIdRef)/CanIfHrhIdSymRef)) = $Can_Hoh_Path"!]
                        [!VAR "IsHohUsed" = "1"!]
                        [!VAR "RxPduId" = "CanIfRxPduId"!]
                        [!BREAK!]
                    [!ENDIF!]
                [!ENDLOOP!]
                [!IF "$IsHohUsed = 1"!]&CanIf_RxPdu[[!"$RxPduId"!]U][!ELSE!]NULL_PTR[!ENDIF!][!IF "$i < $Num_CanDrv_Hoh - 1"!],[!ENDIF!][!CR!]
            [!ENDFOR!]
            [!ENDINDENT!]
        };
        
        static const CanIf_CanDrvConfigType CanIf_[!"$CanDrv_Name"!]_DrvConfig = 
        {
            [!INDENT "4"!]
            /* .HohToRxPduMappingPtr */
            CanIf_[!"$CanDrv_Name"!]_HohToRxPduMapping
            [!ENDINDENT!]
        };
        [!ENDINDENT!]
        [!ENDIF!]
    [!ENDLOOP!]
[!ENDIF!]

[!IF "$Num_CanDrv > 0"!]
    [!INDENT "0"!]
    static const CanIf_CanDrvConfigType * const CanIf_CanDrvConfig[[!"$Num_CanDrv"!]U] =
    {
    [!VAR "CanDrvId" = "0"!]
    [!LOOP "./CanIfCtrlDrvCfg/*"!]
        [!VAR "CanDrvId" = "$CanDrvId + 1"!]
        [!CALL "CanIf_Get_CanDrv_Name", "Driver_Path"="(./CanIfCtrlDrvNameRef)"!]
        [!INDENT "4"!]
        &CanIf_[!"$CanDrv_Name"!]_DrvConfig[!IF "num:i($CanDrvId) < $Num_CanDrv"!],[!ENDIF!][!CR!]
        [!ENDINDENT!]
    [!ENDLOOP!]
    };
    [!ENDINDENT!]
[!ENDIF!]

[!INDENT "0"!]
[!IF "(./IMPLEMENTATION_CONFIG_VARIANT != 'VariantPostBuild') and (variant:size() <= 1)"!][!// VariantPreCompile/LinkTime and at most 1 configured variant
const CanIf_ConfigType CanIf_Config =
[!ELSE!]
const CanIf_ConfigType CanIf_Config[!"$postBuildVariantNameUnderscore"!] =
[!ENDIF!]
{
    [!INDENT "4"!]
    /* .NumRxPdu */
    (uint8)[!"$Num_RxPdu"!]U,
    /* .NumTxPdu */
    (uint8)[!"$Num_TxPdu"!]U,
    [!IF "$Num_CanDrv > 0"!]CanIf_CanDrvConfig[!ELSE!]NULL_PTR[!ENDIF!],
    /* .CanIf_RxPduConfigPtr */
    [!IF "$Num_RxPdu > 0"!]CanIf_RxPdu[!ELSE!]NULL_PTR[!ENDIF!],
    /* .CanIf_TxPduConfigPtr */
    [!IF "$Num_TxPdu > 0"!]CanIf_TxPdu[!ELSE!]NULL_PTR[!ENDIF!][!CR!]
    [!ENDINDENT!]
};
[!ENDINDENT!]

#define CANIF_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */
