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


#ifdef __cplusplus
extern "C" {
#endif

/*==================================================================================================
                                         INCLUDE FILES
==================================================================================================*/
#include "IntCtrl_Ip_Cfg.h"
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define CDD_PLATFORM_INTCTRL_IP_CFG_VENDOR_ID_C                          43
#define CDD_PLATFORM_INTCTRL_IP_CFG_SW_MAJOR_VERSION_C                   3
#define CDD_PLATFORM_INTCTRL_IP_CFG_SW_MINOR_VERSION_C                   0
#define CDD_PLATFORM_INTCTRL_IP_CFG_SW_PATCH_VERSION_C                   0
#define CDD_PLATFORM_INTCTRL_IP_CFG_AR_RELEASE_MAJOR_VERSION_C           4
#define CDD_PLATFORM_INTCTRL_IP_CFG_AR_RELEASE_MINOR_VERSION_C           7
#define CDD_PLATFORM_INTCTRL_IP_CFG_AR_RELEASE_REVISION_VERSION_C        0
/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and IntCtrl_Ip_Cfg header file are of the same vendor */
#if (CDD_PLATFORM_INTCTRL_IP_CFG_VENDOR_ID_C != CDD_PLATFORM_INTCTRL_IP_CFG_VENDOR_ID)
    #error "IntCtrl_Ip_Cfg.c and IntCtrl_Ip_Cfg.h have different vendor ids"
#endif
/* Check if current file and IntCtrl_Ip_Cfg header file are of the same Autosar version */
#if ((CDD_PLATFORM_INTCTRL_IP_CFG_AR_RELEASE_MAJOR_VERSION_C    != CDD_PLATFORM_INTCTRL_IP_CFG_AR_RELEASE_MAJOR_VERSION) || \
     (CDD_PLATFORM_INTCTRL_IP_CFG_AR_RELEASE_MINOR_VERSION_C    != CDD_PLATFORM_INTCTRL_IP_CFG_AR_RELEASE_MINOR_VERSION) || \
     (CDD_PLATFORM_INTCTRL_IP_CFG_AR_RELEASE_REVISION_VERSION_C != CDD_PLATFORM_INTCTRL_IP_CFG_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of IntCtrl_Ip_Cfg.C and IntCtrl_Ip_Cfg.h are different"
#endif
/* Check if current file and IntCtrl_Ip_Cfg header file are of the same Software version */
#if ((CDD_PLATFORM_INTCTRL_IP_CFG_SW_MAJOR_VERSION_C != CDD_PLATFORM_INTCTRL_IP_CFG_SW_MAJOR_VERSION) || \
     (CDD_PLATFORM_INTCTRL_IP_CFG_SW_MINOR_VERSION_C != CDD_PLATFORM_INTCTRL_IP_CFG_SW_MINOR_VERSION) || \
     (CDD_PLATFORM_INTCTRL_IP_CFG_SW_PATCH_VERSION_C != CDD_PLATFORM_INTCTRL_IP_CFG_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of IntCtrl_Ip_Cfg.c and IntCtrl_Ip_Cfg.h are different"
#endif
/*==================================================================================================
                                       GLOBAL VARIABLES
==================================================================================================*/
#define PLATFORM_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Platform_MemMap.h"
[!NOCODE!]



[!VAR "PlatformIrqConfig" = "'PlatformIsrConfig'"!]


[!IF "./GeneralConfiguration/PlatformMulticoreSupport = 'true'"!]


/* Variable storing number of maximum partitions using in configuration */
[!VAR "numPartition" = "0"!]

[!LOOP "as:modconf('Os')[1]/OsApplication/*"!]
    [!SELECT "node:ref(./OsApplicationCoreRef)"!]
        [!IF "$numPartition < node:value(./EcucCoreId)"!]
            [!VAR "numPartition" = "node:value(./EcucCoreId)"!]
        [!ENDIF!]
    [!ENDSELECT!]
[!ENDLOOP!]

[!VAR "numPartition" = "$numPartition + 1"!]

[!FOR "CurrentCoreId" = "0" TO "$numPartition - 1"!]
    [!VAR "CoreIdConfigured" = "0"!]
    [!LOOP "GeneralConfiguration/PlatformEcucPartitionRef/*"!]
        [!VAR "CurrentPartitionRefName" = "node:value(.)"!]
        [!VAR "CurrentPartitionShortName" = "substring-after($CurrentPartitionRefName, '/')"!]
        [!VAR "CurrentPartitionShortName" = "substring-after($CurrentPartitionShortName, '/')"!]
        [!VAR "CurrentPartitionShortName" = "substring-after($CurrentPartitionShortName, '/')"!]
        [!VAR "CurrentPartitionShortName" = "substring-after($CurrentPartitionShortName, '/')"!]
        [!LOOP "as:modconf('Os')[1]/OsApplication/*"!]
            [!IF "$CurrentPartitionRefName = node:value(./OsAppEcucPartitionRef)"!]
                [!SELECT "node:ref(./OsApplicationCoreRef)"!]
                    [!IF "$CurrentCoreId = node:value(./EcucCoreId)"!]                    
                        [!VAR "CoreIdConfigured" = "1"!]
                        [!VAR "PartitionShortName" = "$CurrentPartitionShortName"!]
                        [!VAR "PartitionRefName" = "$CurrentPartitionRefName"!]
                    [!ENDIF!]
                [!ENDSELECT!]
            [!ENDIF!]
        [!ENDLOOP!]
    [!ENDLOOP!]
[!IF "$CoreIdConfigured = 1"!]
[!CODE!]
/*================================== Partition [!"$PartitionShortName"!] ==================================*/
[!ENDCODE!]

[!LOOP "IntCtrlConfig/*"!]
    [!IF "./PlatformNvicEcucPartitionRef = $PartitionRefName "!]
        [!CODE!]

[!IF "(num:i(count(node:ref($PlatformIrqConfig)/*)) > 0)"!]
    /* List of configurations for interrupts */
    static const IntCtrl_Ip_IrqConfigType aIrqConfiguration[!"$PartitionShortName"!][] = {
    [!NOCODE!]
    [!LOOP "node:ref($PlatformIrqConfig)/*"!]
        [!CODE!]    {[!"IsrName"!], (boolean)[!IF "IsrEnabled"!]TRUE[!ELSE!]FALSE[!ENDIF!], [!"IsrPriority"!]U, [!"IsrHandler"!]},
    [!ENDCODE!]
        [!ENDLOOP!]
    [!ENDNOCODE!]};
[!ENDIF!]
/* Configuration structure for interrupt controller */
const IntCtrl_Ip_CtrlConfigType intCtrlConfig[!"$PartitionShortName"!] = {
    [!"num:i(count(node:ref($PlatformIrqConfig)/*))"!]U,
    [!IF "(./../../GeneralConfiguration/PlatformEnableVtorConfiguration = 'true')"!]
    [!"./PlatformVtorAddressConfig"!]U [!ENDIF!]
    [!IF "(num:i(count(node:ref($PlatformIrqConfig)/*)) > 0)"!]
    aIrqConfiguration[!"$PartitionShortName"!]
    [!ELSE!]
    NULL_PTR
    [!ENDIF!]
};



        [!ENDCODE!]
    [!ENDIF!] [!//  [!IF "./PlatformNvicEcucPartitionRef = $PartitionRefName "!]
[!ENDLOOP!] [!//  [!LOOP "IntCtrlConfig/*"!]

[!CODE!]

/*===============================END Partition [!"$PartitionShortName"!] ==================================*/
[!ENDCODE!]
[!ENDIF!]
[!ENDFOR!]
[!ELSE!] [!// [!IF "./GeneralConfiguration/PlatformMulticoreSupport = 'true'"!]
[!IF "count(IntCtrlConfig/*) > 0"!]
    [!CODE!]
[!IF "(num:i(count(node:ref(concat('IntCtrlConfig/*[1]/', $PlatformIrqConfig))/*)) > 0)"!]    
    /* List of configurations for interrupts */
    static const IntCtrl_Ip_IrqConfigType aIrqConfiguration[] = {
    [!NOCODE!]
    [!LOOP "node:ref(concat('IntCtrlConfig/*[1]/', $PlatformIrqConfig))/*"!]
        [!CODE!]    {[!"IsrName"!], (boolean)[!IF "IsrEnabled"!]TRUE[!ELSE!]FALSE[!ENDIF!], [!"IsrPriority"!]U, [!"IsrHandler"!]},
    [!ENDCODE!]
        [!ENDLOOP!]
    [!ENDNOCODE!]};
[!ENDIF!]
/* Configuration structure for interrupt controller */
const IntCtrl_Ip_CtrlConfigType intCtrlConfig = {
    [!"num:i(count(node:ref(concat('IntCtrlConfig/*[1]/', $PlatformIrqConfig))/*))"!]U,
    [!IF "(GeneralConfiguration/PlatformEnableVtorConfiguration = 'true')"!] [!LOOP "IntCtrlConfig/*[1]"!]
    [!CODE!][!"PlatformVtorAddressConfig"!]U, [!ENDCODE!] [!ENDLOOP!]
    [!ENDIF!]
    [!IF "(num:i(count(node:ref(concat('IntCtrlConfig/*[1]/', $PlatformIrqConfig))/*)) > 0)"!]
    aIrqConfiguration
    [!ELSE!]
    NULL_PTR
    [!ENDIF!]
    
};
    [!ENDCODE!]
[!ENDIF!] [!// count(IntCtrlConfig/*) > 0
    
[!ENDIF!] [!// multicore
[!ENDNOCODE!]

#define PLATFORM_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Platform_MemMap.h"

#ifdef __cplusplus
}
#endif
