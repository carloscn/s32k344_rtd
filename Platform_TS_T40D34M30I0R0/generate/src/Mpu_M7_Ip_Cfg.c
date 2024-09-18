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
*   @file Mpu_M7_Ip_Cfg.c
*
*   @addtogroup Mpu_M7_Ip Mpu M7 IPV Driver
*   @{
*/



#ifdef __cplusplus
extern "C"
{
#endif


/*==================================================================================================
                                         INCLUDE FILES
 1) system and project includes
 2) needed interfaces from external units
 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Mpu_M7_Ip_Cfg.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define CDD_PLATFORM_MPU_M7_IP_CFG_VENDOR_ID_C                     43
#define CDD_PLATFORM_MPU_M7_IP_CFG_AR_RELEASE_MAJOR_VERSION_C      4
#define CDD_PLATFORM_MPU_M7_IP_CFG_AR_RELEASE_MINOR_VERSION_C      7
#define CDD_PLATFORM_MPU_M7_IP_CFG_AR_RELEASE_REVISION_VERSION_C   0
#define CDD_PLATFORM_MPU_M7_IP_CFG_SW_MAJOR_VERSION_C              3
#define CDD_PLATFORM_MPU_M7_IP_CFG_SW_MINOR_VERSION_C              0
#define CDD_PLATFORM_MPU_M7_IP_CFG_SW_PATCH_VERSION_C              0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Checks against Mpu_M7_Ip_Cfg.h */
#if (CDD_PLATFORM_MPU_M7_IP_CFG_VENDOR_ID_C != CDD_PLATFORM_MPU_M7_IP_CFG_VENDOR_ID)
    #error "Mpu_M7_Ip_Cfg.c and Mpu_M7_Ip_Cfg.h have different vendor ids"
#endif
#if ((CDD_PLATFORM_MPU_M7_IP_CFG_AR_RELEASE_MAJOR_VERSION_C    != CDD_PLATFORM_MPU_M7_IP_CFG_AR_RELEASE_MAJOR_VERSION) || \
     (CDD_PLATFORM_MPU_M7_IP_CFG_AR_RELEASE_MINOR_VERSION_C    != CDD_PLATFORM_MPU_M7_IP_CFG_AR_RELEASE_MINOR_VERSION) || \
     (CDD_PLATFORM_MPU_M7_IP_CFG_AR_RELEASE_REVISION_VERSION_C != CDD_PLATFORM_MPU_M7_IP_CFG_AR_RELEASE_REVISION_VERSION))
     #error "AUTOSAR Version Numbers of Mpu_M7_Ip_Cfg.h and Mpu_M7_Ip_Cfg.h are different"
#endif
#if ((CDD_PLATFORM_MPU_M7_IP_CFG_SW_MAJOR_VERSION_C != CDD_PLATFORM_MPU_M7_IP_CFG_SW_MAJOR_VERSION) || \
     (CDD_PLATFORM_MPU_M7_IP_CFG_SW_MINOR_VERSION_C != CDD_PLATFORM_MPU_M7_IP_CFG_SW_MINOR_VERSION) || \
     (CDD_PLATFORM_MPU_M7_IP_CFG_SW_PATCH_VERSION_C != CDD_PLATFORM_MPU_M7_IP_CFG_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Mpu_M7_Ip_Cfg.c and Mpu_M7_Ip_Cfg.h are different"
#endif
/*==================================================================================================
                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
                                        LOCAL MACROS
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

/*==================================================================================================
                                       GLOBAL VARIABLES
==================================================================================================*/
[!NOCODE!]
    [!IF "GeneralConfiguration/PlatformMpuM7Configurable"!] /* System settings */
[!CODE!][!//
#define PLATFORM_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Platform_MemMap.h"
[!ENDCODE!]
[!VAR "MpuM7MulticoreSupport" = "'false'"!]
[!VAR "currentPartitionNumber" = "''"!]
[!IF "GeneralConfiguration/PlatformMulticoreSupport"!] /* Multicore support */
    [!VAR "MpuM7MulticoreSupport" = "'true'"!]
[!ENDIF!]

[!LOOP "MPU_M7_Configuration/MPU_M7_ModuleConfig/*"!]
[!IF "$MpuM7MulticoreSupport = 'true'"!] /* Multicore support */
    [!VAR "currentPartitionNumber" = "concat('_',substring-after(substring-after(substring-after(substring-after(./Mpu_M7_EcucPartitionRef,'/'),'/'),'/'),'/'))"!][!//
[!CODE!]
/*================================== Partition [!"$currentPartitionNumber"!] ==================================*/
[!ENDCODE!]
[!ENDIF!]


[!CODE!]
/** @brief Mpu_R7 Ip Region Configuration [!"@index"!] */
const Mpu_M7_Ip_RegionConfigType MPU_M7_RegionConfig_[!"@index"!][!"$currentPartitionNumber"!][MPU_M7_NUM_OF_REGION[!"text:toupper($currentPartitionNumber)"!]] =
{
[!ENDCODE!]
[!VAR "comma" = "num:i(1)"!]
[!VAR "numberofConfig" = "(num:i(count(RegionConfig/*)))"!]
[!LOOP "RegionConfig/*"!]
[!CODE!][!//
    {
        [!"node:current()/RegionNumber"!]U,
        [!"node:current()/StartAddress"!]UL,
        [!"node:current()/EndAddress"!]UL,
        [!"node:current()/MemoryType"!],
        [!"node:current()/AccessRights"!],
        [!"node:current()/OuterCachePolicy"!],
        [!"node:current()/InnerCachePolicy"!],
        [!"node:current()/SubregionMask"!]U,
        ([!IF "node:current()/Shareable"!](boolean)TRUE[!ELSE!](boolean)FALSE[!ENDIF!])
    }[!IF "(num:i($comma))< $numberofConfig"!],[!ENDIF!][!CR!][!VAR "comma"="$comma + 1"!][!//
[!ENDCODE!]
[!ENDLOOP!]
[!CODE!][!//
};
[!ENDCODE!]


[!CODE!]
const Mpu_M7_Ip_ConfigType Mpu_M7_Config[!"$currentPartitionNumber"!] =
{
        [!"./PhysicalCoreID"!],
        ([!IF "node:current()/DefaultMapEnable"!](boolean)TRUE[!ELSE!](boolean)FALSE[!ENDIF!]),
        ([!IF "node:current()/RunInHFNMIEnable"!](boolean)TRUE[!ELSE!](boolean)FALSE[!ENDIF!]),
        ([!IF "node:current()/MemManageInterruptEnable"!](boolean)TRUE[!ELSE!](boolean)FALSE[!ENDIF!]),
        [!"num:i(count(node:current()/RegionConfig/*))"!],
        MPU_M7_RegionConfig_[!"@index"!][!"$currentPartitionNumber"!]
};
[!ENDCODE!]
[!ENDLOOP!]

[!CODE!]
#define PLATFORM_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Platform_MemMap.h"
[!ENDCODE!]
    [!ENDIF!]
[!ENDNOCODE!]

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

