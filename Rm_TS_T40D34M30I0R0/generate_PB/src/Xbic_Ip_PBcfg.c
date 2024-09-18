/*==================================================================================================
*   Project              : RTD AUTOSAR 4.7
*   Platform             : CORTEXM
*   Peripheral           : 
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
*   @file Xbic_Ip_PBcfg.c
*
*   @addtogroup Xbic_IP Xbic IPV Driver
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
#include "Xbic_Ip_Types.h"
#include "Xbic_Ip_Cfg.h"
#include "Xbic_Ip_Device_Registers.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define RM_XBIC_IP_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_VENDOR_ID_C                     43
#define RM_XBIC_IP_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_AR_RELEASE_MAJOR_VERSION_C      4
#define RM_XBIC_IP_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_AR_RELEASE_MINOR_VERSION_C      7
#define RM_XBIC_IP_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_AR_RELEASE_REVISION_VERSION_C   0
#define RM_XBIC_IP_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_SW_MAJOR_VERSION_C              3
#define RM_XBIC_IP_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_SW_MINOR_VERSION_C              0
#define RM_XBIC_IP_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_SW_PATCH_VERSION_C              0
/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Checks against Xbic_Ip_Types.h */
#if (RM_XBIC_IP_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_VENDOR_ID_C != RM_XBIC_IP_TYPES_VENDOR_ID)
    #error "Xbic_Ip_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBcfg.c and Xbic_Ip_Types.h have different vendor ids"
#endif
#if ((RM_XBIC_IP_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_AR_RELEASE_MAJOR_VERSION_C    != RM_XBIC_IP_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (RM_XBIC_IP_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_AR_RELEASE_MINOR_VERSION_C    != RM_XBIC_IP_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (RM_XBIC_IP_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_AR_RELEASE_REVISION_VERSION_C != RM_XBIC_IP_TYPES_AR_RELEASE_REVISION_VERSION))
     #error "AUTOSAR Version Numbers of Xbic_Ip_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBcfg.c and Xbic_Ip_Types.h are different"
#endif
#if ((RM_XBIC_IP_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_SW_MAJOR_VERSION_C != RM_XBIC_IP_TYPES_SW_MAJOR_VERSION) || \
     (RM_XBIC_IP_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_SW_MINOR_VERSION_C != RM_XBIC_IP_TYPES_SW_MINOR_VERSION) || \
     (RM_XBIC_IP_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_SW_PATCH_VERSION_C != RM_XBIC_IP_TYPES_SW_PATCH_VERSION))
    #error "Software Version Numbers of Xbic_Ip_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBcfg.c and Xbic_Ip_Types.h are different"
#endif

/* Checks against Xbic_Ip_Cfg.h */
#if (RM_XBIC_IP_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_VENDOR_ID_C != RM_XBIC_IP_CFG_VENDOR_ID)
    #error "Xbic_Ip_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBcfg.c and Xbic_Ip_Cfg.h have different vendor ids"
#endif
#if ((RM_XBIC_IP_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_AR_RELEASE_MAJOR_VERSION_C    != RM_XBIC_IP_CFG_AR_RELEASE_MAJOR_VERSION) || \
     (RM_XBIC_IP_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_AR_RELEASE_MINOR_VERSION_C    != RM_XBIC_IP_CFG_AR_RELEASE_MINOR_VERSION) || \
     (RM_XBIC_IP_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_AR_RELEASE_REVISION_VERSION_C != RM_XBIC_IP_CFG_AR_RELEASE_REVISION_VERSION))
     #error "AUTOSAR Version Numbers of Xbic_Ip_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBcfg.c and Xbic_Ip_Cfg.h are different"
#endif
#if ((RM_XBIC_IP_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_SW_MAJOR_VERSION_C != RM_XBIC_IP_CFG_SW_MAJOR_VERSION) || \
     (RM_XBIC_IP_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_SW_MINOR_VERSION_C != RM_XBIC_IP_CFG_SW_MINOR_VERSION) || \
     (RM_XBIC_IP_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_SW_PATCH_VERSION_C != RM_XBIC_IP_CFG_SW_PATCH_VERSION))
    #error "Software Version Numbers of Xbic_Ip_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBcfg.c and Xbic_Ip_Cfg.h are different"
#endif

/* Checks against Xbic_Ip_Device_Registers.h */
#if (RM_XBIC_IP_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_VENDOR_ID_C != RM_XBIC_IP_DEVICE_REGISTERS_VENDOR_ID)
    #error "Xbic_Ip_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBcfg.c and Xbic_Ip_Device_Registers.h have different vendor ids"
#endif
#if ((RM_XBIC_IP_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_AR_RELEASE_MAJOR_VERSION_C    != RM_XBIC_IP_DEVICE_REGISTERS_AR_RELEASE_MAJOR_VERSION) || \
     (RM_XBIC_IP_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_AR_RELEASE_MINOR_VERSION_C    != RM_XBIC_IP_DEVICE_REGISTERS_AR_RELEASE_MINOR_VERSION) || \
     (RM_XBIC_IP_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_AR_RELEASE_REVISION_VERSION_C != RM_XBIC_IP_DEVICE_REGISTERS_AR_RELEASE_REVISION_VERSION))
     #error "AUTOSAR Version Numbers of Xbic_Ip_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBcfg.c and Xbic_Ip_Device_Registers.h are different"
#endif
#if ((RM_XBIC_IP_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_SW_MAJOR_VERSION_C != RM_XBIC_IP_DEVICE_REGISTERS_SW_MAJOR_VERSION) || \
     (RM_XBIC_IP_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_SW_MINOR_VERSION_C != RM_XBIC_IP_DEVICE_REGISTERS_SW_MINOR_VERSION) || \
     (RM_XBIC_IP_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_SW_PATCH_VERSION_C != RM_XBIC_IP_DEVICE_REGISTERS_SW_PATCH_VERSION))
    #error "Software Version Numbers of Xbic_Ip_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBcfg.c and Xbic_Ip_Device_Registers.h are different"
#endif
/*==================================================================================================
*                           LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
*                                          LOCAL MACROS
==================================================================================================*/

/*==================================================================================================
*                                         LOCAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                         LOCAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                        GLOBAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                        GLOBAL VARIABLES
==================================================================================================*/
[!IF "RmGeneral/RmXbicConfigurable"!][!//
[!SELECT "RmConfigSet/Xbic_Configuration/XbicCheckingControl"!][!//
#define RM_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Rm_MemMap.h"

const Xbic_Ip_ConfigType Xbic_Config[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!] =
{   /*Value of MCR registers to enable(bit1)/disable(bit0) for Slave port EDC Error Detection (SEn) and Master Port For Feedback Integrity Check (MEn)*/
    {                /*         SE0 SE1 SE2 SE3 SE4 SE5 SE6 SE7 ME0 ME1 ME2 ME3 ME4 ME5 ME6 ME7  Reverse     */
[!NOCODE!]

  [!/* Macro for print code of MCR value */!]
[!MACRO "PrintHexMCR","Xbic_MCR_Para","Xbic_Instance_Para"!][!//
    [!VAR "Temp" = "concat('00000000',toUpperCase(substring-after(string(num:inttohex($Xbic_MCR_Para)),'0x')))"!]
[!CODE!][!//
        [!"concat('0x',substring($Temp,string-length($Temp) - 8 + 1,8))"!]U[!IF "num:i($Index1) < num:i(count(ecu:list('Rm.Xbic.XbicInstances.List')))"!],[!ELSE!] [!ENDIF!] /* [!"($Xbic_Instance_Para)"!]: [!"text:replaceAll( text:replaceAll( num:inttobin(bit:shr($Xbic_MCR_Para,16),16), '0', '0   '), '1', '1   ')"!]0000000000000000 */
[!ENDCODE!][!//
[!ENDMACRO!][!//

[!FOR "Index1" = "1" TO "num:i(count(ecu:list('Rm.Xbic.XbicInstances.List')))"!]
    [!VAR "Xbic_MCR" = "num:i(0)"!]
    [!VAR "Xbic_Instance" = "(ecu:list('Rm.Xbic.XbicInstances.List')[num:i($Index1)])"!]

    [!/* Get Xbic MCR default value */!]
    [!FOR "Index2" = "1" TO "num:i(count(ecu:list(text:replace('Rm.Xbic.XbicInstanceTemp.Slave.List','Temp',substring-after(ecu:list('Rm.Xbic.XbicInstances.List')[num:i($Index1)], 'XBIC_')))))"!]
        [!VAR "Xbic_MCR" = "bit:or($Xbic_MCR,bit:shr(num:hextoint('0x80000000'),num:i(ecu:list(text:replace('Rm.Xbic.XbicInstanceTemp.Slave.List','Temp',substring-after(ecu:list('Rm.Xbic.XbicInstances.List')[num:i($Index1)], 'XBIC_')))[num:i($Index2)])))"!]
    [!ENDFOR!]
    [!FOR "Index2" = "1" TO "num:i(count(ecu:list(text:replace('Rm.Xbic.XbicInstanceTemp.Master.List','Temp',substring-after(ecu:list('Rm.Xbic.XbicInstances.List')[num:i($Index1)], 'XBIC_')))))"!]
        [!VAR "Xbic_MCR" = "bit:or($Xbic_MCR,bit:shr(num:hextoint('0x00800000'),num:i(ecu:list(text:replace('Rm.Xbic.XbicInstanceTemp.Master.List','Temp',substring-after(ecu:list('Rm.Xbic.XbicInstances.List')[num:i($Index1)], 'XBIC_')))[num:i($Index2)])))"!]
    [!ENDFOR!]

    [!/* Get Xbic MCR configured value in EB */!]
    [!LOOP "./*"!]
        [!IF "(ecu:list('Rm.Xbic.XbicInstances.List')[num:i($Index1)]) = (./XbicInstance)"!]
            [!FOR "Index3" = "0" TO "7"!][!//
                [!IF "(node:value(concat("./SE", $Index3))) = 'false'"!]
                    [!VAR "Xbic_MCR" = "bit:and($Xbic_MCR, bit:not( bit:shr(num:hextoint('0x80000000'),$Index3)))"!]
                [!ENDIF!]
                [!IF "(node:value(concat("./ME", $Index3))) = 'false'"!]
                    [!VAR "Xbic_MCR" = "bit:and($Xbic_MCR, bit:not( bit:shr(num:hextoint('0x00800000'),$Index3)))"!]
                [!ENDIF!]
            [!ENDFOR!]
        [!ENDIF!]
    [!ENDLOOP!]
    [!VAR "Print_Xbic_MCR" = "concat('00000000',toUpperCase(substring-after(string(num:inttohex($Xbic_MCR)),'0x')))"!]

    [!CALL "PrintHexMCR", "Xbic_MCR_Para" = "$Xbic_MCR", "Xbic_Instance_Para" = "$Xbic_Instance"!][!//

[!ENDFOR!]
[!ENDNOCODE!][!//
    }
};

#define RM_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Rm_MemMap.h"
[!ENDSELECT!][!//
[!ENDIF!]
/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/


/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/


/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/

#ifdef __cplusplus
}
#endif

/** @} */

