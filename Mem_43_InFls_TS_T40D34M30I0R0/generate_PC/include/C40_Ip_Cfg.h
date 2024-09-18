[!NOCODE!][!//
[!//////////////////////////////////////////////////////////////////////////////////////////////////
[!////////////////////////   VARIABLE DEFINE FOR EB TRESOS       ///////////////////////////////////

[!VAR "MemName"      = "'Mem_43_InFls'"!][!//
[!VAR "MemNameUpper" = "text:toupper($MemName)"!][!//

[!//////////////////////////////////////////////////////////////////////////////////////////////////
[!///////////////////////    FUNCTION (MACRO) FOR EB TRESOS      ///////////////////////////////////

[!MACRO "FlsGetBlock4PipeSelect", "FlsEnumPipe"!][!//
    [!IF "$FlsEnumPipe='FLS_COMMAND_PIPE_0'"!][!//
        [!VAR "OutPipeSelect" = "'0x00U'"!][!//
    [!ELSEIF "$FlsEnumPipe='FLS_COMMAND_PIPE_1'"!][!//
        [!VAR "OutPipeSelect" = "'0x01U'"!][!//
    [!ELSEIF "$FlsEnumPipe='FLS_COMMAND_PIPE_2'"!][!//
        [!VAR "OutPipeSelect" = "'0x02U'"!][!//
    [!ELSEIF "$FlsEnumPipe='FLS_COMMAND_PIPE_3'"!][!//
        [!VAR "OutPipeSelect" = "'0x03U'"!][!//
    [!ELSE!][!//
        [!VAR "OutPipeSelect" = "'0x04U'"!][!//
    [!ENDIF!][!//
    [!CODE!][!"$OutPipeSelect"!][!ENDCODE!][!//
[!ENDMACRO!][!//
[!//

[!//////////////////////////////////////////////////////////////////////////////////////////////////
[!ENDNOCODE!]
[!AUTOSPACING!]
/*==================================================================================================
*   Project              : RTD AUTOSAR 4.7
*   Platform             : CORTEXM
*   Peripheral           : C40
*   Dependencies         : None
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

#ifndef C40_IP_CFG_H
#define C40_IP_CFG_H

/**
 * @file       C40_Ip_Cfg.h
 *
 * @addtogroup C40_IP
 * implements  C40_Ip_Cfg.h_Artifact
 *
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
#include "OsIf.h"
#include "C40_Ip_Types.h"
#include "[!"ecu:get('Mem.InFls.Header')"!]_PFLASH.h"
#include "[!"ecu:get('Mem.InFls.Header')"!]_FLASH.h"

[!IF "MemGeneral/MemDevErrorDetect"!]
#include "Devassert.h"
[!ENDIF!][!//

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define C40_IP_VENDOR_ID_CFG                          43
#define C40_IP_AR_RELEASE_MAJOR_VERSION_CFG           4
#define C40_IP_AR_RELEASE_MINOR_VERSION_CFG           7
#define C40_IP_AR_RELEASE_REVISION_VERSION_CFG        0
#define C40_IP_SW_MAJOR_VERSION_CFG                   3
#define C40_IP_SW_MINOR_VERSION_CFG                   0
#define C40_IP_SW_PATCH_VERSION_CFG                   0

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if current file and OsIf.h header file are of the same Autosar version */
    #if ((C40_IP_AR_RELEASE_MAJOR_VERSION_CFG != OSIF_AR_RELEASE_MAJOR_VERSION) || \
         (C40_IP_AR_RELEASE_MINOR_VERSION_CFG != OSIF_AR_RELEASE_MINOR_VERSION) \
        )
        #error "AutoSar Version Numbers of C40_Ip_Cfg.h and OsIf.h are different"
    #endif
[!IF "MemGeneral/MemDevErrorDetect"!][!//
    /* Check if current file and Devassert.h header file are of the same Autosar version */
    #if ((C40_IP_AR_RELEASE_MAJOR_VERSION_CFG != DEVASSERT_AR_RELEASE_MAJOR_VERSION) || \
         (C40_IP_AR_RELEASE_MINOR_VERSION_CFG != DEVASSERT_AR_RELEASE_MINOR_VERSION) \
        )
        #error "AutoSar Version Numbers of C40_Ip_Cfg.h and Devassert.h are different"
    #endif
[!ENDIF!][!//
#endif

/* Check if current file and C40_Ip_Types header file are of the same vendor */
#if (C40_IP_VENDOR_ID_CFG != C40_IP_TYPES_VENDOR_ID_CFG)
    #error "C40_Ip_Cfg.h and C40_Ip_Types.h have different vendor ids"
#endif
/* Check if current file and C40_Ip_Types header file are of the same Autosar version */
#if ((C40_IP_AR_RELEASE_MAJOR_VERSION_CFG    != C40_IP_TYPES_AR_RELEASE_MAJOR_VERSION_CFG) || \
     (C40_IP_AR_RELEASE_MINOR_VERSION_CFG    != C40_IP_TYPES_AR_RELEASE_MINOR_VERSION_CFG) || \
     (C40_IP_AR_RELEASE_REVISION_VERSION_CFG != C40_IP_TYPES_AR_RELEASE_REVISION_VERSION_CFG) \
    )
    #error "AutoSar Version Numbers of C40_Ip_Cfg.h and C40_Ip_Types.h are different"
#endif
/* Check if current file and C40_Ip_Types header file are of the same Software version */
#if ((C40_IP_SW_MAJOR_VERSION_CFG != C40_IP_TYPES_SW_MAJOR_VERSION_CFG) || \
     (C40_IP_SW_MINOR_VERSION_CFG != C40_IP_TYPES_SW_MINOR_VERSION_CFG) || \
     (C40_IP_SW_PATCH_VERSION_CFG != C40_IP_TYPES_SW_PATCH_VERSION_CFG) \
    )
    #error "Software Version Numbers of C40_Ip_Cfg.h and C40_Ip_Types.h are different"
#endif


/*==================================================================================================
                                       DEFINES AND MACROS
==================================================================================================*/
[!NOCODE!][!//
[!VAR "c40_ip_synchronize_cache" = "'STD_OFF'"!][!//
[!IF "ecu:has('Mem.InFls.SupportSynchronizeCacheFeature')"!][!//
    [!IF "ecu:get('Mem.InFls.SupportSynchronizeCacheFeature') = 'true'"!][!//
        [!IF "MemAutosarExt/MemSynchronizeCache"!][!//
            [!VAR "c40_ip_synchronize_cache" = "'STD_ON'"!][!//
        [!ENDIF!] [!//
    [!ENDIF!] [!//
[!ENDIF!] [!//
[!ENDNOCODE!][!//

/**
 * @brief  PFlash register base address of PFlash
 */
#define PFLASH_BASEADDR                             IP_PFLASH_BASE

#define FLS_MAX_DATA_SECTOR                         ([!"(ecu:get('Mem.InFls.NumberOfSectorData'))"!]U)

#define FLS_NO_OF_SECTOR_PER_BLOCK                  ([!"(ecu:get('Mem.InFls.NumOfSectorPerBlock'))"!]U)

#define FLS_NO_OF_SUPPER_SECTOR_PER_BLOCK           ([!"(ecu:get('Mem.InFls.NumOfSuperSectorPerBlock'))"!]U)

#define FLS_DATA_PFCBLK_ORDER                       (PFLASH_PFCBLKI_SPELOCK_COUNT - 1U)


/* Order of data flash PFCBLK Registers Arrays */
#define PFLASH_PFCBLK_DATA_LOCKMASTER_S0_ADDR32     ((uint32)&(IP_PFLASH->PFCBLK_LOCKMASTER_S[PFLASH_PFCBLKI_LOCKMASTER_S_COUNT - 1U][0U]))
/**
 * @brief  Block a Lock Master Sector
 */
#define PFLASH_PFCBLK0_LOCKMASTER_S0_ADDR32         ((uint32)&(IP_PFLASH->PFCBLK_LOCKMASTER_S[0U][0U]))
/**
 * @brief   Block UTEST Lock Master Sector
 */
#define PFLASH_PFCBLKU_LOCKMASTER_S_ADDR32          ((uint32)&(IP_PFLASH->PFCBLKU_LOCKMASTER_S[0U]))
/**
 * @brief   Block a Lock Master Super Sector
 */
#define PFLASH_PFCBLK0_LOCKMASTER_SS0_ADDR32        ((uint32)(PFLASH_BASEADDR + (uint32)0x484UL))


/* Enable the use of cache invalidate */
#define C40_IP_SYNCRONIZE_CACHE             ([!"$c40_ip_synchronize_cache"!])

#define C40_MAIN_INTERFACE_ENABLED          ([!IF "MemAutosarExt/MemUsesAlterInterface"!]STD_OFF[!ELSE!]STD_ON[!ENDIF!])

#define C40_IP_ENABLE_USER_MODE_SUPPORT     ([!IF "MemAutosarExt/MemEnableUserModeSupport"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

#ifndef MCAL_ENABLE_USER_MODE_SUPPORT
    #if (STD_ON == C40_IP_ENABLE_USER_MODE_SUPPORT)
        #error MCAL_ENABLE_USER_MODE_SUPPORT is not enabled. For running Fls in user mode the MCAL_ENABLE_USER_MODE_SUPPORT needs to be defined
    #endif
#endif


#define C40_DATA_FLASH_ERROR_SUPPRESSION    ([!IF "MemAutosarExt/MemDataErrorSuppression"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

#define FLS_BLOCK_4_PIPE_SELECTABLE         ([!"ecu:get('Mem.InFls.SupportBlock4PipeSelect')"!])

#if (STD_ON == FLS_BLOCK_4_PIPE_SELECTABLE)
#define C40_BLOCK4_PIPE_SELECT              ([!CALL "FlsGetBlock4PipeSelect", "FlsEnumPipe" = "MemAutosarExt/MemBlock4PipeSelect"!])
#endif


/*! Enable development error check */
#define C40_IP_DEV_ASSERT(x)                [!WS "16"!][!IF "MemGeneral/MemDevErrorDetect"!]DevAssert((x))[!ELSE!](void)(x)[!ENDIF!][!CR!]

#define C40_SECTOR_SET_LOCK_API             ([!IF "MemGeneral/MemSectorSetLockApi"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

#define C40_PROGRAM_VERIFICATION_ENABLED    ([!IF "MemGeneral/MemWriteVerificationEnabled"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

#define C40_ERASE_VERIFICATION_ENABLED      ([!IF "MemGeneral/MemEraseVerificationEnabled"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

#define C40_ERASED_VALUE_32                 ([!"num:inttohex(MemPublishedInformation/MemErasedValue)"!]U)

#define C40_ERASED_VALUE_16                 (C40_ERASED_VALUE_32 & 0xFFFFU)

#define C40_ERASED_VALUE_8                  (C40_ERASED_VALUE_32 & 0xFFU)


#define C40_ECC_CHECK                       ([!IF "MemGeneral/MemECCCheck"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

#define C40_ECC_CHECK_BY_AUTOSAR_OS         ([!IF "MemGeneral/MemECCHandlingProtectionHook"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

#if ( (C40_ECC_CHECK == STD_ON) || (C40_ECC_CHECK_BY_AUTOSAR_OS == STD_ON) )
    #define C40_ECC_VALUE                   ([!"num:inttohex(MemPublishedInformation/MemECCValue)"!]U)
#endif


#define C40_TIMEOUT_SUPERVISION_ENABLED     ([!IF "MemGeneral/MemTimeoutSupervisionEnabled"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

#if (STD_ON == C40_TIMEOUT_SUPERVISION_ENABLED)

#define C40_TIMEOUT_TYPE                    ([!"MemGeneral/MemTimeoutMethod"!])

#define C40_ASYNC_WRITE_TIMEOUT             ([!"MemGeneral/MemAsyncWriteTimeout"!]U)

#define C40_ASYNC_ERASE_TIMEOUT             ([!"MemGeneral/MemAsyncEraseTimeout"!]U)

#define C40_SYNC_WRITE_TIMEOUT              ([!"MemGeneral/MemSyncWriteTimeout"!]U)

#define C40_SYNC_ERASE_TIMEOUT              ([!"MemGeneral/MemSyncEraseTimeout"!]U)

#define C40_ABORT_TIMEOUT                   ([!"MemGeneral/MemAbortTimeout"!]U)

#endif  /*(STD_ON == C40_TIMEOUT_SUPERVISION_ENABLED)*/


#define FLS_INVALID_ADDR                    (0xFFFFFFFFU)

/* Code block 0 addresses */
#define FLS_CODE_BLOCK_0_BASE_ADDR          ([!"ecu:get('Mem.InFls.Code.Block0.Base')"!]U)
#define FLS_CODE_BLOCK_0_END_ADDR           ([!"ecu:get('Mem.InFls.Code.Block0.End')"!]U)

[!IF "ecu:has('Mem.InFls.Code.Block1.Base')"!]
/* Code block 1 addresses */
#define FLS_CODE_BLOCK_1_BASE_ADDR          ([!"ecu:get('Mem.InFls.Code.Block1.Base')"!]U)
#define FLS_CODE_BLOCK_1_END_ADDR           ([!"ecu:get('Mem.InFls.Code.Block1.End')"!]U)
[!ENDIF!]

[!IF "ecu:has('Mem.InFls.Code.Block2.Base')"!]
/* Code block 2 addresses */
#define FLS_CODE_BLOCK_2_BASE_ADDR          ([!"ecu:get('Mem.InFls.Code.Block2.Base')"!]U)
#define FLS_CODE_BLOCK_2_END_ADDR           ([!"ecu:get('Mem.InFls.Code.Block2.End')"!]U)
[!ENDIF!]

[!IF "ecu:has('Mem.InFls.Code.Block3.Base')"!]
/* Code block 3 addresses */
#define FLS_CODE_BLOCK_3_BASE_ADDR          ([!"ecu:get('Mem.InFls.Code.Block3.Base')"!]U)
#define FLS_CODE_BLOCK_3_END_ADDR           ([!"ecu:get('Mem.InFls.Code.Block3.End')"!]U)
[!ENDIF!]

/* Data block addresses */
#define FLS_DATA_BLOCK_BASE_ADDR            ([!"ecu:get('Mem.InFls.Data.Block0.Base')"!]U)
#define FLS_DATA_BLOCK_END_ADDR             ([!"ecu:get('Mem.InFls.Data.Block0.End')"!]U)

/* Utest block addresses */
#define FLS_UTEST_BLOCK_BASE_ADDR           ([!"ecu:get('Mem.InFls.UTest.Block0.Base')"!]U)
#define FLS_UTEST_BLOCK_END_ADDR            ([!"ecu:get('Mem.InFls.UTest.Block0.End')"!]U)

/* Memory flash sector characteristics */
#define FLS_MAX_VIRTUAL_SECTOR              ([!"num:i(count(ecu:list('Mem.InFls.Sector.Physical.List')) - 2)"!]U)

#define FLS_CODE_BLOCK_SIZE                 ([!"ecu:get('Mem.InFls.PFlashSize')"!]U)
#define FLS_CODE_BLOCK_END_ADDR             (FLS_CODE_BLOCK_0_BASE_ADDR + FLS_CODE_BLOCK_SIZE - 1U)

/* Failing address based on the flash memory addressing scheme */
#define FLASH_REGION_0_ADDR                 ([!"ecu:get('Mem.InFls.Region0.Addr')"!])
#define FLASH_REGION_1_ADDR                 ([!"ecu:get('Mem.InFls.Region1.Addr')"!])
#define FLASH_REGION_2_ADDR                 ([!"ecu:get('Mem.InFls.Region2.Addr')"!])
#define FLASH_REGION_3_ADDR                 ([!"ecu:get('Mem.InFls.Region3.Addr')"!])
#define FLASH_REGION_4_ADDR                 ([!"ecu:get('Mem.InFls.Region4.Addr')"!])
#define FLASH_REGION_5_ADDR                 ([!"ecu:get('Mem.InFls.Region5.Addr')"!])


/*==================================================================================================
                                 ENUM TYPEDEFS
==================================================================================================*/

typedef uint32 C40_Ip_VirtualSectorsType;

/**
    For flash area : Code flash : Start 0040_0000h -> 0x007F_E000h and Data Flash: 1000_0000h -> 1003_FFFFh and Utest Flash :  1B00_0000h -> 1B00_1FFFh
*/
[!FOR "SectorIt" = "1" TO "num:i(count(ecu:list('Mem.InFls.Sector.Physical.List')))"!][!//
[!VAR "PhysicalSector" = "ecu:list('Mem.InFls.Sector.Physical.List')[num:i($SectorIt)]"!][!//
[!VAR "PhysicalSector" = "substring-after($PhysicalSector, '_')"!][!//
[!VAR "PhysicalSector" = "text:replace($PhysicalSector, 'FLS', 'C40')"!][!//
[!IF "contains($PhysicalSector, 'DATA') = 'true'"!][!//
    [!VAR "PhysicalAddr" = "num:hextoint(ecu:get('Mem.InFls.DFlashBaseAddr')) + (num:hextoint(ecu:get('Mem.InFls.DFlashSectorSize')) * ($SectorIt - 1))"!][!//
[!ELSEIF "contains($PhysicalSector, 'CODE') = 'true'"!][!//
    [!VAR "PhysicalAddr" = "num:hextoint(ecu:get('Mem.InFls.PFlashBaseAddr')) + (num:hextoint(ecu:get('Mem.InFls.PFlashSectorSize')) * ($SectorIt - 1 - num:i(ecu:get('Mem.InFls.NumberOfSectorData'))))"!][!//
[!ELSE!][!//
    [!VAR "PhysicalAddr" = "num:hextoint('0x1B000000')"!][!//
    [!VAR "PhysicalSector" = "concat($PhysicalSector, '       ')"!][!//
[!ENDIF!][!//
#define [!"$PhysicalSector"!]       ([!"num:i($SectorIt - 1)"!]U)    /* 0x[!"text:toupper(text:replace(num:inttohex($PhysicalAddr, 8), '0x', ''))"!] */
[!ENDFOR!]
#define C40_SECTOR_ERROR                    ([!"num:i($SectorIt)"!]U)    /* default and error return value */


/*==================================================================================================
                                 GLOBAL CONSTANT DECLARATIONS
==================================================================================================*/

#define [!"$MemNameUpper"!]_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "[!"$MemName"!]_MemMap.h"

extern const C40_ConfigType C40_Ip_InitCfg;

#define [!"$MemNameUpper"!]_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "[!"$MemName"!]_MemMap.h"


#ifdef __cplusplus
}
#endif

/** @} */

#endif /* C40_IP_CFG_H */
