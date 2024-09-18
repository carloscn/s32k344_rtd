/*==================================================================================================
*   Project              : RTD AUTOSAR 4.7
*   Platform             : CORTEXM
*   Peripheral           : SIUL2
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

/**
*   @file    Tspc_Port_Ip_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBcfg.c
*
*   @addtogroup Port_CFG
*   @{
*/

#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
*                                          INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Tspc_Port_Ip.h"

[!IF "not(contains(as:modconf("Resource")[1]/ResourceGeneral/ResourceSubderivative, 's32k396')) and not(contains(as:modconf("Resource")[1]/ResourceGeneral/ResourceSubderivative, 's32k394'))"!][!//  /* S32K394: sub/phantom derivatives of S32K396 */
[!NOCODE!][!//
[!/* Include package file in order to get valid Pins */!][!//
[!IF "((ecu:get('Port.Derivative'))='s32k311')"!][!//
    [!INCLUDE "Port_S32K311_Resource.m"!][!//
[!ELSEIF "((ecu:get('Port.Derivative'))='s32k310')"!][!//
    [!INCLUDE "Port_S32K310_Resource.m"!][!//
[!ELSEIF "((ecu:get('Port.Derivative'))='s32k312')"!][!//
    [!INCLUDE "Port_S32K312_Resource.m"!][!//
[!ELSEIF "((ecu:get('Port.Derivative'))='s32k314')"!][!//
    [!INCLUDE "Port_S32K314_Resource.m"!][!//
[!ELSEIF "((ecu:get('Port.Derivative'))='s32k324')"!][!//
    [!INCLUDE "Port_S32K324_Resource.m"!][!//
[!ELSEIF "((ecu:get('Port.Derivative'))='s32k342')"!][!//
    [!INCLUDE "Port_S32K342_Resource.m"!][!//
[!ELSEIF "((ecu:get('Port.Derivative'))='s32k341')"!][!//
    [!INCLUDE "Port_S32K341_Resource.m"!][!//
[!ELSEIF "((ecu:get('Port.Derivative'))='s32k322')"!][!//
    [!INCLUDE "Port_S32K322_Resource.m"!][!//
[!ELSEIF "((ecu:get('Port.Derivative'))='s32k344')"!][!//
    [!INCLUDE "Port_S32K344_Resource.m"!][!//
[!ELSEIF "((ecu:get('Port.Derivative'))='s32k358')"!][!//
    [!INCLUDE "Port_S32K358_Resource.m"!][!//
[!ELSEIF "((ecu:get('Port.Derivative'))='s32k328')"!][!//
    [!INCLUDE "Port_S32K328_Resource.m"!][!//
[!ELSEIF "((ecu:get('Port.Derivative'))='s32k338')"!][!//
    [!INCLUDE "Port_S32K338_Resource.m"!][!//
[!ELSEIF "((ecu:get('Port.Derivative'))='s32k348')"!][!//
    [!INCLUDE "Port_S32K348_Resource.m"!][!//
[!ELSEIF "((ecu:get('Port.Derivative'))='s32k388')"!][!//
    [!INCLUDE "Port_S32K388_Resource.m"!][!//
[!ELSEIF "((ecu:get('Port.Derivative'))='s32m276')"!][!//
    [!INCLUDE "Port_S32M276_Resource.m"!][!//
[!ELSEIF "((ecu:get('Port.Derivative'))='s32m274')"!][!//
    [!INCLUDE "Port_S32M274_Resource.m"!][!//
[!ENDIF!][!//
[!ENDNOCODE!][!//
[!ENDIF!][!//

/*==================================================================================================
*                                 SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define TSPC_PORT_IP_VENDOR_ID_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_C                       43
#define TSPC_PORT_IP_AR_RELEASE_MAJOR_VERSION_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_C        4
#define TSPC_PORT_IP_AR_RELEASE_MINOR_VERSION_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_C        7
#define TSPC_PORT_IP_AR_RELEASE_REVISION_VERSION_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_C     0
#define TSPC_PORT_IP_SW_MAJOR_VERSION_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_C                3
#define TSPC_PORT_IP_SW_MINOR_VERSION_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_C                0
#define TSPC_PORT_IP_SW_PATCH_VERSION_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_C                0

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/
/* Check if Tspc_Port_Ip_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBcfg.c and Tspc_Port_Ip.h are of the same vendor */
#if (TSPC_PORT_IP_VENDOR_ID_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_C != TSPC_PORT_IP_VENDOR_ID_H)
    #error "Tspc_Port_Ip_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBcfg.c and Tspc_Port_Ip.h have different vendor ids"
#endif
/* Check if Tspc_Port_Ip_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBcfg.c and Tspc_Port_Ip.h are of the same Autosar version */
#if ((TSPC_PORT_IP_AR_RELEASE_MAJOR_VERSION_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_C    != TSPC_PORT_IP_AR_RELEASE_MAJOR_VERSION_H) || \
     (TSPC_PORT_IP_AR_RELEASE_MINOR_VERSION_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_C    != TSPC_PORT_IP_AR_RELEASE_MINOR_VERSION_H) || \
     (TSPC_PORT_IP_AR_RELEASE_REVISION_VERSION_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_C != TSPC_PORT_IP_AR_RELEASE_REVISION_VERSION_H) \
    )
    #error "AutoSar Version Numbers of Tspc_Port_Ip_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBcfg.c and Tspc_Port_Ip.h are different"
#endif
/* Check if Tspc_Port_Ip_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBcfg.c and Tspc_Port_Ip.h are of the same software version */
#if ((TSPC_PORT_IP_SW_MAJOR_VERSION_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_C != TSPC_PORT_IP_SW_MAJOR_VERSION_H) || \
     (TSPC_PORT_IP_SW_MINOR_VERSION_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_C != TSPC_PORT_IP_SW_MINOR_VERSION_H) || \
     (TSPC_PORT_IP_SW_PATCH_VERSION_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_C != TSPC_PORT_IP_SW_PATCH_VERSION_H)    \
    )
    #error "Software Version Numbers of Tspc_Port_Ip_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBcfg.c and Tspc_Port_Ip.h are different"
#endif

/*==================================================================================================
*                           LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
*                                          LOCAL MACROS
==================================================================================================*/
[!//
[!/*****************************************************************************/!][!//
[!/*                          MACRO CheckIsMscrAvailable                               */!][!//
[!/*****************************************************************************/!][!//
[!MACRO "CheckIsMscrAvailable"!][!//
[!NOCODE!][!//
[!SELECT "PortConfigSet"!]
    [!// Check if the configured MSCRs are not on the list of excluded pins
    [!FOR "LoopCounter" = "1" TO "num:i(count(ecu:list('Port.Siul2Instances')))"!][!//
        [!VAR "resourceName" = "concat('Port.Siul2Instance',num:i($LoopCounter - 1),'NotAvailableMscrs')"!][!//
        [!LOOP "PortContainer/*"!][!//
            [!LOOP "PortPin/*"!][!//
                [!VAR "PortPinPcrVar" = "PortPinPcr"!][!//
                [!VAR "PortPinSiul2InstanceVar" = "ecu:list('Port.Siul2Instances')[num:i($LoopCounter)]"!][!//
                [!IF "contains(concat(',',string(ecu:get($resourceName)),','), concat(',',$PortPinPcrVar,',')) and (./PortPinSiul2Instance = $PortPinSiul2InstanceVar)"!][!//
                    [!ERROR!][!//
                    Error in PortPin list: [!"name(.)"!] with [!"'PortPin Mscr'"!] set to [!"string($PortPinPcrVar)"!] [!"concat('- Mscr not available in this package on the SIUL2 instance ', ecu:list('Port.Siul2Instances')[num:i($LoopCounter)])"!][!//
                    [!ENDERROR!][!//
                [!ENDIF!][!//
            [!ENDLOOP!][!//
        [!ENDLOOP!][!//
    [!ENDFOR!][!//
[!ENDSELECT!][!//
[!ENDNOCODE!][!//
[!ENDMACRO!][!//

[!/*****************************************************************************/!][!//
[!/*                          MACRO GetOBEGroup                               */!][!//
[!/*****************************************************************************/!][!//
[!MACRO "GetOBEGroup_IP"!][!//
[!NOCODE!][!//
[!VAR "TempOBEGroup"="concat(./PortPinSiul2Instance, '_PORT',number(./PortPinPcr), '_', ./PortPinMode,';')"!][!//
[!VAR "ObeGroupIndex_IP"="num:i(substring-after(substring-before((substring-after($PinMap,$TempOBEGroup)),'*'),'~'))"!][!//
[!IF "(./OBEGroupSelect = 'NO_OBE_GROUP')"!][!//
    [!VAR "ObeGroupSelect_IP" = "'0'"!][!//
[!ELSEIF "(./OBEGroupSelect = 'OBE_GROUP1')"!][!//
    [!VAR "ObeGroupSelect_IP" = "'1'"!][!//
[!ELSEIF "(./OBEGroupSelect = 'OBE_GROUP2')"!][!//
    [!VAR "ObeGroupSelect_IP" = "'2'"!][!//
[!ELSE!][!//
    [!/*don't anything*/!][!//
[!ENDIF!][!//
[!ENDNOCODE!][!//
[!ENDMACRO!][!//
/*==================================================================================================
*                                         LOCAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                         LOCAL VARIABLES
==================================================================================================*/
[!VAR "ObeGroupSelect_IP" = "'0'"!][!//
[!VAR "ObeGroupIndex_IP" = "0"!][!//
/*==================================================================================================
*                                        GLOBAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                        GLOBAL VARIABLES
==================================================================================================*/
[!IF "not(contains(as:modconf("Resource")[1]/ResourceGeneral/ResourceSubderivative, 's32k396')) and not(contains(as:modconf("Resource")[1]/ResourceGeneral/ResourceSubderivative, 's32k394'))"!][!//  /* S32K394: sub/phantom derivatives of S32K396 */
#define PORT_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Port_MemMap.h"

[!INDENT "0"!][!//
    const Tspc_Port_Ip_ObeGroupConfig aTspc_InitConfigArr[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][NUM_OF_OBE_GROUP_CONFIG] =
[!ENDINDENT!][!//
{
[!CALL "CheckIsMscrAvailable"!][!//
[!SELECT "PortConfigSet"!][!//
[!VAR "Counter"= "1"!][!//
[!VAR "Maxcounter"= "num:i(count(PortContainer/*/PortPin/*))-1"!][!//
[!LOOP "PortContainer/*/PortPin/*"!][!//
[!CALL "GetOBEGroup_IP"!][!//
[!IF "$Maxcounter>=$Counter"!][!//
    {
        .obeGroupSelect = [!"$ObeGroupSelect_IP"!],
        .obeGroupIndex  = [!"$ObeGroupIndex_IP"!]
    },
[!ELSE!][!//
    {
        .obeGroupSelect = [!"$ObeGroupSelect_IP"!],
        .obeGroupIndex  = [!"$ObeGroupIndex_IP"!]
    }
[!ENDIF!][!//
[!VAR "Counter"= "$Counter+1"!][!//
[!ENDLOOP!][!//
[!ENDSELECT!][!//
};

#define PORT_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Port_MemMap.h"
[!ENDIF!][!//
/*==================================================================================================
*                                        GLOBAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                        GLOBAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                    LOCAL FUNCTION PROTOTYPES
==================================================================================================*/

/*==================================================================================================
*                                         LOCAL FUNCTIONS
==================================================================================================*/

/*==================================================================================================
*                                        GLOBAL FUNCTIONS
==================================================================================================*/

#ifdef __cplusplus
}
#endif

/** @} */
