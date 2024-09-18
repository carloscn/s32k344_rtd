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
*   @file Mscm_Ip_PBcfg.c
*
*   @addtogroup MSCM_IP MSCM IPV Driver
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
#include "Mscm_Ip_Types.h"
#include "Mscm_Ip_Cfg.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define RM_MSCM_IP_PBCFG[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_VENDOR_ID_C                     43
#define RM_MSCM_IP_PBCFG[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_AR_RELEASE_MAJOR_VERSION_C      4
#define RM_MSCM_IP_PBCFG[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_AR_RELEASE_MINOR_VERSION_C      7
#define RM_MSCM_IP_PBCFG[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_AR_RELEASE_REVISION_VERSION_C   0
#define RM_MSCM_IP_PBCFG[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_SW_MAJOR_VERSION_C              3
#define RM_MSCM_IP_PBCFG[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_SW_MINOR_VERSION_C              0
#define RM_MSCM_IP_PBCFG[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_SW_PATCH_VERSION_C              0
/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Checks against Mscm_Ip_Types.h */
#if (RM_MSCM_IP_PBCFG[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_VENDOR_ID_C != RM_MSCM_IP_TYPES_VENDOR_ID)
    #error "Mscm_Ip[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg.c and Mscm_Ip_Types.h have different vendor ids"
#endif
#if ((RM_MSCM_IP_PBCFG[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_AR_RELEASE_MAJOR_VERSION_C    != RM_MSCM_IP_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (RM_MSCM_IP_PBCFG[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_AR_RELEASE_MINOR_VERSION_C    != RM_MSCM_IP_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (RM_MSCM_IP_PBCFG[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_AR_RELEASE_REVISION_VERSION_C != RM_MSCM_IP_TYPES_AR_RELEASE_REVISION_VERSION))
     #error "AUTOSAR Version Numbers of Mscm_Ip[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg.c and Mscm_Ip_Types.h are different"
#endif
#if ((RM_MSCM_IP_PBCFG[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_SW_MAJOR_VERSION_C != RM_MSCM_IP_TYPES_SW_MAJOR_VERSION) || \
     (RM_MSCM_IP_PBCFG[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_SW_MINOR_VERSION_C != RM_MSCM_IP_TYPES_SW_MINOR_VERSION) || \
     (RM_MSCM_IP_PBCFG[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_SW_PATCH_VERSION_C != RM_MSCM_IP_TYPES_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Mscm_Ip[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg.c and Mscm_Ip_Types.h are different"
#endif

/* Checks against Mscm_Ip_Cfg.h */
#if (RM_MSCM_IP_PBCFG[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_VENDOR_ID_C != RM_MSCM_IP_CFG_VENDOR_ID)
    #error "Mscm_Ip[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg.c and Mscm_Ip_Cfg.h have different vendor ids"
#endif
#if ((RM_MSCM_IP_PBCFG[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_AR_RELEASE_MAJOR_VERSION_C    != RM_MSCM_IP_CFG_AR_RELEASE_MAJOR_VERSION) || \
     (RM_MSCM_IP_PBCFG[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_AR_RELEASE_MINOR_VERSION_C    != RM_MSCM_IP_CFG_AR_RELEASE_MINOR_VERSION) || \
     (RM_MSCM_IP_PBCFG[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_AR_RELEASE_REVISION_VERSION_C != RM_MSCM_IP_CFG_AR_RELEASE_REVISION_VERSION))
     #error "AUTOSAR Version Numbers of Mscm_Ip[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg.c and Mscm_Ip_Cfg.h are different"
#endif
#if ((RM_MSCM_IP_PBCFG[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_SW_MAJOR_VERSION_C != RM_MSCM_IP_CFG_SW_MAJOR_VERSION) || \
     (RM_MSCM_IP_PBCFG[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_SW_MINOR_VERSION_C != RM_MSCM_IP_CFG_SW_MINOR_VERSION) || \
     (RM_MSCM_IP_PBCFG[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_SW_PATCH_VERSION_C != RM_MSCM_IP_CFG_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Mscm_Ip[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg.c and Mscm_Ip_Cfg.h are different"
#endif

/*==================================================================================================
*                                      GLOBAL VARIABLES
==================================================================================================*/
[!IF "RmGeneral/RmEnableMscmSupport"!][!//

#define RM_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Rm_MemMap.h"

[!SELECT "RmConfigSet"!][!//
[!VAR "sumConfig"			= "num:i(count(Mscm_Configuration/MscmConfig/*))"!][!// Number of ISR Configuration
[!VAR "sumIRQNumber"		= "num:i(count(ecu:list('Rm.MSCM.irqs.Number.List')))"!][!// Total Number of IRQs
[!VAR "MSCM_SPIStartIdx" 	= "num:i(1)"!][!//
[!NOCODE!][!// Calculate Number of SPI Config
[!VAR "sumSPI" = "$sumConfig"!][!//
[!FOR "Config" = "1" TO "$sumConfig"!][!//
	[!SELECT "Mscm_Configuration/MscmConfig/*[position() = $Config]"!][!//
		[!VAR "CFGName" = "string(node:value(./IsrName))"!][!//
		[!IF "$MSCM_SPIStartIdx > 1"!]
			[!FOR "X" = "1" TO "$MSCM_SPIStartIdx"!][!//
				[!IF "(ecu:list('Rm.MSCM.irqs.Name.List'))[position()=$X] = $CFGName"!][!//
					[!VAR "sumSPI" = "$sumSPI - 1"!][!//
				[!ENDIF!][!//
			[!ENDFOR!][!//
		[!ENDIF!]
	[!ENDSELECT!][!//
[!ENDFOR!][!//
[!ENDNOCODE!][!// !Calculate
static const Mscm_Ip_IrqRouteConfigType IrqRouteConfig[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][[!"num:i($sumSPI)"!]] =
{
[!NOCODE!][!//
[!VAR "spiCount" = "num:i(0)"!][!//
[!FOR "ConfIdx" = "1" TO "$sumConfig"!][!//
	[!VAR "tempTargetCores" = "7"!][!//
	[!SELECT "Mscm_Configuration/MscmConfig/*[position() = $ConfIdx]"!][!//
		[!VAR "isrName" = "string(node:value(./IsrName))"!][!// Get ISR Name from GUI
		[!VAR "check" = "0"!][!//
		[!IF "$MSCM_SPIStartIdx > 1"!]
			[!FOR "X" = "1" TO "$MSCM_SPIStartIdx"!][!// Check no SPI routing
				[!IF "(ecu:list('Rm.MSCM.irqs.Name.List'))[position()=$X] = $isrName"!][!//
					[!VAR "check" = "1"!][!//
					[!BREAK!][!//
				[!ENDIF!][!//
			[!ENDFOR!][!// Check no SPI routing
		[!ENDIF!]
		[!IF "$check = 0"!][!//
			[!VAR "tempTargetCores" = "0"!][!//
			[!FOR "Index" = "0" TO "num:i(count(ecu:list('Rm.MSCM.targetCores.List'))) - num:i(1)"!][!//
				[!IF "text:contains(string(ecu:list('Rm.MSCM.targetCoresArray.List')[position() = (num:i($Index) + num:i(1))]), 'True')"!][!//
					[!IF "(node:value(concat("IsrTargetCore", ($Index))))"!][!//
						[!VAR "tempTargetCores" = "num:dectoint($tempTargetCores) + bit:shl(1,$Index)"!][!//
					[!ENDIF!][!//
				[!ENDIF!][!//
			[!ENDFOR!][!// Index
			[!VAR "spiCount" = "$spiCount + num:i(1)"!][!//
		[!ENDIF!][!//
	[!ENDSELECT!][!//
	[!IF "$check = 0"!][!//
	[!CODE!]    {[!"$isrName"!], [!"num:dectoint($tempTargetCores)"!]U}[!IF "$spiCount != num:i($sumSPI)"!],[!ENDIF!][!CR!][!ENDCODE!]
	[!ENDIF!]
[!ENDFOR!][!// ConfIdx
[!ENDNOCODE!][!// !IrqRouteConfig
};
const Mscm_Ip_ConfigType Mscm_Config[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!] =
{
    (uint32)[!"num:i($sumSPI)"!]U,
	IrqRouteConfig[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]
};
[!ENDSELECT!][!// [!SELECT "RmConfigSet"!]

#define RM_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Rm_MemMap.h"
[!ENDIF!][!//

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

