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
/*==================================================================================================
==================================================================================================*/

/**
*   @file    CanIf_Cfg.c
*   @version 3.0.0
*
*   @brief   AUTOSAR CanIf - module interface
*   @details Configuration Structures for PreCompile.
*
*   @addtogroup CANIF_DRIVER
*   @{
*/

#ifdef __cplusplus
extern "C"{
#endif

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
/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "CanIf_Types.h"
[!LOOP "./CanIfCtrlDrvCfg/*"!]
    [!CALL "CanIf_Get_CanDrv_Name", "Driver_Path"="(./CanIfCtrlDrvNameRef)"!]
    #include "[!"$CanDrv_Name"!].h"
[!ENDLOOP!]
[!AUTOSPACING!]

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define CANIF_VENDOR_ID_PCCFG_C                   43
#define CANIF_AR_RELEASE_MAJOR_VERSION_PCCFG_C     4
#define CANIF_AR_RELEASE_MINOR_VERSION_PCCFG_C     7
#define CANIF_AR_RELEASE_REVISION_VERSION_PCCFG_C  0
#define CANIF_SW_MAJOR_VERSION_PCCFG_C             3
#define CANIF_SW_MINOR_VERSION_PCCFG_C             0
#define CANIF_SW_PATCH_VERSION_PCCFG_C             0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/

/*==================================================================================================
*                                   GLOBAL FUNCTION PROTOTYPES
==================================================================================================*/

/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/

/*==================================================================================================
*                                      LOCAL CONSTANTS
==================================================================================================*/
#define CANIF_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"

[!VAR "CanDrvId" = "0"!]
[!LOOP "./CanIfCtrlDrvCfg/*"!]
    [!VAR "Num_CanDrv_Hoh" = "num:i(count(node:ref(./CanIfCtrlDrvNameRef)/../CanConfigSet/CanHardwareObject/*))"!]
    [!CALL "CanIf_Get_CanDrv_Name", "Driver_Path"="(./CanIfCtrlDrvNameRef)"!]
    /* Here is the configuration related to [!"$CanDrv_Name"!] Driver */
    static const CanIf_CanDrvFuncPtrType [!"$CanDrv_Name"!]_Driver_P2Func = 
    {
        /* .CanWrite */
        &[!"$CanDrv_Name"!]_Write
    };

    static const CanIf_CanDrvPCConfigType [!"$CanDrv_Name"!]_Driver_Config =
    {
        /* .CanDrvId */
        (uint8)[!"num:i($CanDrvId)"!]U,
        /* .NumCanHoh */
        (uint8)[!"$Num_CanDrv_Hoh"!]U,
        /* .CanApi */
        &[!"$CanDrv_Name"!]_Driver_P2Func
    };
    [!VAR "CanDrvId" = "$CanDrvId + 1"!]
[!ENDLOOP!]

[!VAR "Num_all_controllers" = "num:i(count(./CanIfCtrlDrvCfg/*/CanIfCtrlCfg/*))"!]
[!IF "$Num_all_controllers > 0"!]
    static const CanIf_CtrlPCConfigType CanIf_CtrlPCConfig[[!"$Num_all_controllers"!]U] =
    {
        [!VAR "CtrlIdx" = "num:i(0)"!]
        [!LOOP "node:order(./CanIfCtrlDrvCfg/*/CanIfCtrlCfg/*, './CanIfCtrlId')"!]
        {
            [!CALL "CanIf_Get_CanDrv_Name", "Driver_Path"="(./../../CanIfCtrlDrvNameRef)"!]
            /* .CanIfCtrlId */
            (uint8)[!"./CanIfCtrlId"!]U,
            /* .CanCtrlId */
            (uint8)[!"node:ref(./CanIfCtrlCanCtrlRef)/CanControllerId"!]U,
            /* .CanDrvConfigPtr */
            &[!"$CanDrv_Name"!]_Driver_Config
            [!VAR "CtrlIdx" = "$CtrlIdx + 1"!]
        }[!IF "num:i($CtrlIdx) < $Num_all_controllers"!],[!ENDIF!][!CR!]
        [!ENDLOOP!]
    };
[!ENDIF!]
/*==================================================================================================
*                                      GLOBAL CONSTANTS
==================================================================================================*/
const CanIf_PCConfigType CanIf_PCConfig = 
{
    /* .NumOfCtrl */
    (uint8)[!"$Num_all_controllers"!]U,
    /* .CanIfCtrlConfigPtr */
    CanIf_CtrlPCConfig
};

#define CANIF_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */
