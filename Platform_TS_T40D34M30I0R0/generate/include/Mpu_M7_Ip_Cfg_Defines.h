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

#ifndef MPU_M7_IP_CFG_DEFINES_H_
#define MPU_M7_IP_CFG_DEFINES_H_

/**
*   @file Mpu_M7_Ip_CfgDefines.h
*
*   @addtogroup Mpu_M7_Ip Mpu M7 IPV Driver
*   @{
*/

#ifdef __cplusplus
extern "C"{
#endif


/*==================================================================================================
                                         INCLUDE FILES
==================================================================================================*/
#include "StandardTypes.h"
[!NOCODE!][!// Include specific header file
[!IF "node:exists(as:modconf("Resource")[1]/ResourceGeneral/ResourceSubderivative)"!][!//
    [!IF "contains(as:modconf("Resource")[1]/ResourceGeneral/ResourceSubderivative, 's32k312')"!][!//
[!CODE!][!WS "0"!]
#include "S32K312_MPU.h"
#include "S32K312_SCB.h"
#include "S32K312_MSCM.h"
[!CR!][!ENDCODE!][!//
    [!ELSEIF "contains(as:modconf("Resource")[1]/ResourceGeneral/ResourceSubderivative, 's32k344')"!][!//
[!CODE!][!WS "0"!]
#include "S32K344_MPU.h"
#include "S32K344_SCB.h"
#include "S32K344_MSCM.h"
[!CR!][!ENDCODE!][!//
    [!ELSEIF "contains(as:modconf("Resource")[1]/ResourceGeneral/ResourceSubderivative, 's32k314')"!][!//
[!CODE!][!WS "0"!]
#include "S32K314_MPU.h"
#include "S32K314_SCB.h"
#include "S32K314_MSCM.h"
[!CR!][!ENDCODE!][!//
    [!ELSEIF "contains(as:modconf("Resource")[1]/ResourceGeneral/ResourceSubderivative, 's32k324')"!][!//
[!CODE!][!WS "0"!]
#include "S32K324_MPU.h"
#include "S32K324_SCB.h"
#include "S32K324_MSCM.h"
[!CR!][!ENDCODE!][!//
    [!ELSEIF "contains(as:modconf("Resource")[1]/ResourceGeneral/ResourceSubderivative, 's32k396')"!][!//
[!CODE!][!WS "0"!]
#include "S32K39_MPU.h"
#include "S32K39_SCB.h"
#include "S32K39_MSCM.h"
[!CR!][!ENDCODE!][!//
    [!ELSEIF "contains(as:modconf("Resource")[1]/ResourceGeneral/ResourceSubderivative, 's32k394')"!][!//
[!CODE!][!WS "0"!]
#include "S32K39_MPU.h"
#include "S32K39_SCB.h"
#include "S32K39_MSCM.h"
[!CR!][!ENDCODE!][!//
   [!ELSEIF "contains(as:modconf("Resource")[1]/ResourceGeneral/ResourceSubderivative, 's32e27')"!][!//
[!CODE!][!WS "0"!]
#include "S32E2_MPU.h"
#include "S32E2_SCB.h"
#include "S32E2_MSCM.h"
[!CR!][!ENDCODE!][!//
    [!ELSEIF "contains(as:modconf("Resource")[1]/ResourceGeneral/ResourceSubderivative, 's32z27')"!][!//
[!CODE!][!WS "0"!]
#include "S32Z2_MPU.h"
#include "S32Z2_SCB.h"
#include "S32Z2_MSCM.h"
[!CR!][!ENDCODE!][!//
    [!ELSEIF "contains(as:modconf("Resource")[1]/ResourceGeneral/ResourceSubderivative, 's32k358')"!][!//
[!CODE!][!WS "0"!]
#include "S32K358_MPU.h"
#include "S32K358_SCB.h"
#include "S32K358_MSCM.h"
[!CR!][!ENDCODE!][!//
    [!ELSEIF "contains(as:modconf("Resource")[1]/ResourceGeneral/ResourceSubderivative, 's32k328')"!][!//
[!CODE!][!WS "0"!]
#include "S32K358_MPU.h"
#include "S32K358_SCB.h"
#include "S32K358_MSCM.h"
[!CR!][!ENDCODE!][!//
    [!ELSEIF "contains(as:modconf("Resource")[1]/ResourceGeneral/ResourceSubderivative, 's32k338')"!][!//
[!CODE!][!WS "0"!]
#include "S32K358_MPU.h"
#include "S32K358_SCB.h"
#include "S32K358_MSCM.h"
[!CR!][!ENDCODE!][!//
    [!ELSEIF "contains(as:modconf("Resource")[1]/ResourceGeneral/ResourceSubderivative, 's32k348')"!][!//
[!CODE!][!WS "0"!]
#include "S32K358_MPU.h"
#include "S32K358_SCB.h"
#include "S32K358_MSCM.h"
[!CR!][!ENDCODE!][!//
    [!ELSEIF "contains(as:modconf("Resource")[1]/ResourceGeneral/ResourceSubderivative, 's32k388')"!][!//
[!CODE!][!WS "0"!]
#include "S32K388_MPU.h"
#include "S32K388_SCB.h"
#include "S32K388_MSCM.h"
[!CR!][!ENDCODE!][!//
    [!ELSEIF "contains(as:modconf("Resource")[1]/ResourceGeneral/ResourceSubderivative, 's32k311')"!][!//
[!CODE!][!WS "0"!]
#include "S32K311_MPU.h"
#include "S32K311_SCB.h"
#include "S32K311_MSCM.h"
[!CR!][!ENDCODE!][!//
    [!ELSEIF "contains(as:modconf("Resource")[1]/ResourceGeneral/ResourceSubderivative, 's32k310')"!][!//
[!CODE!][!WS "0"!]
#include "S32K311_MPU.h"
#include "S32K311_SCB.h"
#include "S32K311_MSCM.h"
[!CR!][!ENDCODE!][!//
    [!ELSEIF "contains(as:modconf("Resource")[1]/ResourceGeneral/ResourceSubderivative, 's32k342')"!][!//
[!CODE!][!WS "0"!]
#include "S32K342_MPU.h"
#include "S32K342_SCB.h"
#include "S32K342_MSCM.h"
[!CR!][!ENDCODE!][!//
    [!ELSEIF "contains(as:modconf("Resource")[1]/ResourceGeneral/ResourceSubderivative, 's32k341')"!][!//
[!CODE!][!WS "0"!]
#include "S32K341_MPU.h"
#include "S32K341_SCB.h"
#include "S32K341_MSCM.h"
[!CR!][!ENDCODE!][!//
    [!ELSEIF "contains(as:modconf("Resource")[1]/ResourceGeneral/ResourceSubderivative, 's32k322')"!][!//
[!CODE!][!WS "0"!]
#include "S32K322_MPU.h"
#include "S32K322_SCB.h"
#include "S32K322_MSCM.h"
[!CR!][!ENDCODE!][!//
    [!ELSEIF "contains(as:modconf("Resource")[1]/ResourceGeneral/ResourceSubderivative, 's32m276')"!][!//
[!CODE!][!WS "0"!]
#include "S32M27x_MPU.h"
#include "S32M27x_SCB.h"
#include "S32M27x_MSCM.h"
[!CR!][!ENDCODE!][!//
    [!ELSEIF "contains(as:modconf("Resource")[1]/ResourceGeneral/ResourceSubderivative, 's32m274')"!][!//
[!CODE!][!WS "0"!]
#include "S32M27x_MPU.h"
#include "S32M27x_SCB.h"
#include "S32M27x_MSCM.h"
[!CR!][!ENDCODE!][!//
    [!ELSEIF "contains(as:modconf("Resource")[1]/ResourceGeneral/ResourceSubderivative, 's32g2')"!][!//
[!CODE!][!WS "0"!]#include "S32G274A_MPU.h"[!CR!][!ENDCODE!][!//
[!CODE!][!WS "0"!]#include "S32G274A_SCB.h"[!CR!][!ENDCODE!][!//
[!CODE!][!WS "0"!]#include "S32G274A_MSCM.h"[!CR!][!ENDCODE!][!//
    [!ELSEIF "contains(as:modconf("Resource")[1]/ResourceGeneral/ResourceSubderivative, 's32g3')"!][!//
[!CODE!][!WS "0"!]#include "S32G399A_MPU.h"[!CR!][!ENDCODE!][!//
[!CODE!][!WS "0"!]#include "S32G399A_SCB.h"[!CR!][!ENDCODE!][!//
[!CODE!][!WS "0"!]#include "S32G399A_MSCM.h"[!CR!][!ENDCODE!][!//
    [!ELSEIF "contains(as:modconf("Resource")[1]/ResourceGeneral/ResourceSubderivative, 's32r45')"!][!//
[!CODE!][!WS "0"!]#include "S32R45_MPU.h"[!CR!][!ENDCODE!][!//
[!CODE!][!WS "0"!]#include "S32R45_SCB.h"[!CR!][!ENDCODE!][!//
[!CODE!][!WS "0"!]#include "S32R45_MSCM.h"[!CR!][!ENDCODE!][!//
    [!ELSEIF "contains(as:modconf("Resource")[1]/ResourceGeneral/ResourceSubderivative, 's32r41')"!][!//
[!CODE!][!WS "0"!]#include "S32R41_MPU.h"[!CR!][!ENDCODE!][!//
[!CODE!][!WS "0"!]#include "S32R41_SCB.h"[!CR!][!ENDCODE!][!//
[!CODE!][!WS "0"!]#include "S32R41_MSCM.h"[!CR!][!ENDCODE!][!//
    [!ELSEIF "contains(as:modconf("Resource")[1]/ResourceGeneral/ResourceSubderivative, 'saf85')"!][!//
[!CODE!][!WS "0"!]#include "SAF85XX_MPU.h"[!CR!][!ENDCODE!][!//
[!CODE!][!WS "0"!]#include "SAF85XX_SCB.h"[!CR!][!ENDCODE!][!//
[!CODE!][!WS "0"!]#include "SAF85XX_MSCM.h"[!CR!][!ENDCODE!][!//
    [!ENDIF!][!//
[!ENDIF!][!//
[!ENDNOCODE!][!//

[!VAR "MpuM7MulticoreSupport" = "'false'"!]
[!VAR "currentPartitionNumber" = "''"!]
[!IF "GeneralConfiguration/PlatformMulticoreSupport"!] /* Multicore support */
    [!VAR "MpuM7MulticoreSupport" = "'true'"!]
[!ENDIF!]
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define CDD_PLATFORM_MPU_M7_IP_CFG_DEFINES_VENDOR_ID                    43
#define CDD_PLATFORM_MPU_M7_IP_CFG_DEFINES_AR_RELEASE_MAJOR_VERSION     4
#define CDD_PLATFORM_MPU_M7_IP_CFG_DEFINES_AR_RELEASE_MINOR_VERSION     7
#define CDD_PLATFORM_MPU_M7_IP_CFG_DEFINES_AR_RELEASE_REVISION_VERSION  0
#define CDD_PLATFORM_MPU_M7_IP_CFG_DEFINES_SW_MAJOR_VERSION             3
#define CDD_PLATFORM_MPU_M7_IP_CFG_DEFINES_SW_MINOR_VERSION             0
#define CDD_PLATFORM_MPU_M7_IP_CFG_DEFINES_SW_PATCH_VERSION             0


/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
/* Checks against StandardTypes.h */
#if ((CDD_PLATFORM_MPU_M7_IP_CFG_DEFINES_AR_RELEASE_MAJOR_VERSION != STD_AR_RELEASE_MAJOR_VERSION) || \
    (CDD_PLATFORM_MPU_M7_IP_CFG_DEFINES_AR_RELEASE_MINOR_VERSION  != STD_AR_RELEASE_MINOR_VERSION))
    #error "AutoSar Version Numbers of Mpu_M7_Ip_Cfg_Defines.h and StandardTypes.h are different"
#endif
#endif

/*==================================================================================================
*                                            CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/
[!IF "GeneralConfiguration/PlatformMpuM7Configurable"!][!//
/** @brief    Development error checking */
#define MPU_M7_IP_DEV_ERROR_DETECT ([!IF "GeneralConfiguration/PlatformDevErrorDetect"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])
/** @brief    Maximum supported regions */
#define MPU_M7_MAX_REGION_COUNT ([!"ecu:get('Platform.Mpu_M7.MaximumRegionCount')"!]U)
[!IF "GeneralConfiguration/PlatformEnableUserModeSupport"!][!//

/** @brief    User mode support          */
#define MPU_M7_IP_ENABLE_USER_MODE_SUPPORT
#ifndef MCAL_ENABLE_USER_MODE_SUPPORT
    #ifdef MPU_M7_IP_ENABLE_USER_MODE_SUPPORT
        #error "MCAL_ENABLE_USER_MODE_SUPPORT is not enabled. For running MPU_M7 in user mode the MCAL_ENABLE_USER_MODE_SUPPORT needs to be defined"
    #endif /* (ifdef MPU_M7_IP_ENABLE_USER_MODE_SUPPORT) */
#endif /* ifndef MCAL_ENABLE_USER_MODE_SUPPORT */
[!ELSE!][!//
[!ENDIF!][!//

#define MPU_M7_IP_MIN_REGION_SIZE                           ([!"ecu:get('Platform.Mpu_M7.MinRegionSize')"!]U)
#define MPU_M7_IP_MIN_REGION_SIZE_WITH_SUBREGION            ([!"ecu:get('Platform.Mpu_M7.MinRegionSizeWithSubregion')"!])
#define MPU_M7_IP_EXECUTE_RIGHT_MASK                        ([!"ecu:get('Platform.Mpu_M7.ExecuteRightMask')"!])
#define MPU_M7_IP_SCB_CFSR_MMFSR_MASK_WITHOUT_VALID         ([!"ecu:get('Platform.Mpu_M7.MmfsrMaskWithoutValid')"!])
[!ENDIF!][!//


/** @brief    IP enablement checking */
#define PLATFORM_IP_ENABLE_MPU_M7 ([!IF "(GeneralConfiguration/PlatformMpuM7Configurable = 'true')"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])
[!IF "GeneralConfiguration/PlatformMpuM7Configurable"!][!//


[!LOOP "MPU_M7_Configuration/MPU_M7_ModuleConfig/*"!][!//
[!IF "$MpuM7MulticoreSupport = 'true'"!] /* Multicore support */
    [!VAR "currentPartitionNumber" = "concat('_',substring-after(substring-after(substring-after(substring-after(./Mpu_M7_EcucPartitionRef,'/'),'/'),'/'),'/'))"!][!//
[!ENDIF!]


/** @brief    Number of configured memory regions */
#define MPU_M7_NUM_OF_REGION[!"text:toupper($currentPartitionNumber)"!] ([!"num:i(count(RegionConfig/*))"!]U)


[!ENDLOOP!][!//
[!ENDIF!][!//


/*==================================================================================================
*                                              ENUMS
==================================================================================================*/

/*==================================================================================================
*                                  STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
*                                  GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                       FUNCTION PROTOTYPES
==================================================================================================*/

#ifdef __cplusplus
}
#endif

/** @} */

#endif /* MPU_M7_IP_CFG_DEFINES_H_ */

