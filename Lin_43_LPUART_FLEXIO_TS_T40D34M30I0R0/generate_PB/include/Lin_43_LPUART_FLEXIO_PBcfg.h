/*==================================================================================================
*   Project              : RTD AUTOSAR 4.7
*   Platform             : CORTEXM
*   Peripheral           : LPUART_FLEXIO
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
*
*   NXP Confidential. This software is owned or controlled by NXP and may only be
*   used strictly in accordance with the applicable license terms. By expressly
*   accepting such terms or by downloading, installing, activating and/or otherwise
*   using the software, you are agreeing that you have read, and that you agree to
*   comply with and are bound by, such license terms. If you do not agree to be
*   bound by the applicable license terms, then you may not retain, install,
*   activate or otherwise use the software.
==================================================================================================*/
[!NOCODE!]
[!IF "var:defined('postBuildVariant')"!]
[!CODE!][!//
#ifndef LIN_43_LPUART_FLEXIO[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_H
#define LIN_43_LPUART_FLEXIO[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_H
[!ENDCODE!]
[!ELSE!]
[!CODE!][!//
#ifndef LIN_43_LPUART_FLEXIO_PBCFG_H
#define LIN_43_LPUART_FLEXIO_PBCFG_H
[!ENDCODE!]
[!ENDIF!]
[!ENDNOCODE!]
/**
*   @file
*
*   @defgroup lin_driver LIN Driver
*   @addtogroup  lin_driver LIN Driver
*   @{
*/

#ifdef __cplusplus
extern "C"
{
#endif

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Lin_43_LPUART_FLEXIO_Types.h"

[!NOCODE!][!//
[!INCLUDE "Lin_VersionCheck_Inc_PB.m"!][!//
[!ENDNOCODE!][!//
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
[!NOCODE!]
[!IF "var:defined('postBuildVariant')"!]
[!CODE!][!//
#define LIN_43_LPUART_FLEXIO[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_VENDOR_ID                     43
#define LIN_43_LPUART_FLEXIO[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_AR_RELEASE_MAJOR_VERSION      4
#define LIN_43_LPUART_FLEXIO[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_AR_RELEASE_MINOR_VERSION      7
#define LIN_43_LPUART_FLEXIO[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_AR_RELEASE_REVISION_VERSION   0
#define LIN_43_LPUART_FLEXIO[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_SW_MAJOR_VERSION              3
#define LIN_43_LPUART_FLEXIO[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_SW_MINOR_VERSION              0
#define LIN_43_LPUART_FLEXIO[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_SW_PATCH_VERSION              0
[!ENDCODE!]
[!ELSE!]
[!CODE!][!//
#define LIN_43_LPUART_FLEXIO_PBCFG_VENDOR_ID                     43
#define LIN_43_LPUART_FLEXIO_PBCFG_AR_RELEASE_MAJOR_VERSION      4
#define LIN_43_LPUART_FLEXIO_PBCFG_AR_RELEASE_MINOR_VERSION      7
#define LIN_43_LPUART_FLEXIO_PBCFG_AR_RELEASE_REVISION_VERSION   0
#define LIN_43_LPUART_FLEXIO_PBCFG_SW_MAJOR_VERSION              3
#define LIN_43_LPUART_FLEXIO_PBCFG_SW_MINOR_VERSION              0
#define LIN_43_LPUART_FLEXIO_PBCFG_SW_PATCH_VERSION              0
[!ENDCODE!]
[!ENDIF!]
[!ENDNOCODE!]
/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/


[!NOCODE!]
[!IF "var:defined('postBuildVariant')"!]
[!CODE!][!//
/* Checks against Lin_Types.h */
#if (LIN_43_LPUART_FLEXIO[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_VENDOR_ID != LIN_43_LPUART_FLEXIO_TYPES_VENDOR_ID)
    #error "Lin_43_LPUART_FLEXIO[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg.h and Lin_43_LPUART_FLEXIO_Types.h have different vendor ids"
#endif
#if ((LIN_43_LPUART_FLEXIO[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_AR_RELEASE_MAJOR_VERSION   != LIN_43_LPUART_FLEXIO_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (LIN_43_LPUART_FLEXIO[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_AR_RELEASE_MINOR_VERSION   != LIN_43_LPUART_FLEXIO_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (LIN_43_LPUART_FLEXIO[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_AR_RELEASE_REVISION_VERSION!= LIN_43_LPUART_FLEXIO_TYPES_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AUTOSAR Version Numbers of Lin_43_LPUART_FLEXIO[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg.h and Lin_43_LPUART_FLEXIO_Types.h are different"
#endif
#if ((LIN_43_LPUART_FLEXIO[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_SW_MAJOR_VERSION!= LIN_43_LPUART_FLEXIO_TYPES_SW_MAJOR_VERSION) || \
     (LIN_43_LPUART_FLEXIO[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_SW_MINOR_VERSION!= LIN_43_LPUART_FLEXIO_TYPES_SW_MINOR_VERSION) || \
     (LIN_43_LPUART_FLEXIO[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_SW_PATCH_VERSION!= LIN_43_LPUART_FLEXIO_TYPES_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Lin_43_LPUART_FLEXIO[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg.h and Lin_43_LPUART_FLEXIO_Types.h are different"
#endif
[!ENDCODE!]
[!ELSE!]
[!CODE!][!//
/* Checks against Lin_43_LPUART_FLEXIO_Types.h */
#if (LIN_43_LPUART_FLEXIO_PBCFG_VENDOR_ID != LIN_43_LPUART_FLEXIO_TYPES_VENDOR_ID)
    #error "Lin_43_LPUART_FLEXIO_PBcfg.h and Lin_43_LPUART_FLEXIO_Types.h have different vendor ids"
#endif
#if ((LIN_43_LPUART_FLEXIO_PBCFG_AR_RELEASE_MAJOR_VERSION   != LIN_43_LPUART_FLEXIO_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (LIN_43_LPUART_FLEXIO_PBCFG_AR_RELEASE_MINOR_VERSION   != LIN_43_LPUART_FLEXIO_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (LIN_43_LPUART_FLEXIO_PBCFG_AR_RELEASE_REVISION_VERSION!= LIN_43_LPUART_FLEXIO_TYPES_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AUTOSAR Version Numbers of Lin_43_LPUART_FLEXIO_PBcfg.h and Lin_43_LPUART_FLEXIO_Types.h are different"
#endif
#if ((LIN_43_LPUART_FLEXIO_PBCFG_SW_MAJOR_VERSION!= LIN_43_LPUART_FLEXIO_TYPES_SW_MAJOR_VERSION) || \
     (LIN_43_LPUART_FLEXIO_PBCFG_SW_MINOR_VERSION!= LIN_43_LPUART_FLEXIO_TYPES_SW_MINOR_VERSION) || \
     (LIN_43_LPUART_FLEXIO_PBCFG_SW_PATCH_VERSION!= LIN_43_LPUART_FLEXIO_TYPES_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Lin_43_LPUART_FLEXIO_PBcfg.h and Lin_43_LPUART_FLEXIO_Types.h are different"
#endif
[!ENDCODE!]
[!ENDIF!]
[!ENDNOCODE!]
/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/
[!NOCODE!][!//
[!IF "not(IMPLEMENTATION_CONFIG_VARIANT !='VariantPostBuild' and (variant:size()<=1))"!][!//
    [!IF "var:defined('postBuildVariant')"!][!//
        [!VAR "PostBuildVariantNameUnderscore" = "concat('_',$postBuildVariant)"!][!//
[!CODE!]#define LIN_43_LPUART_FLEXIO_CONFIG_[!"$postBuildVariant"!]_PB \[!CR!][!ENDCODE!]
    [!ELSE!][!//
        [!VAR "PostBuildVariantNameUnderscore" = "string(null)"!][!//
[!CODE!]#define LIN_43_LPUART_FLEXIO_CONFIG_PB \[!CR!][!ENDCODE!]
    [!ENDIF!][!//
    [!VAR "LinConfiguredPartitions" = "num:i((count(LinGeneral/LinEcucPartitionRef/*)))"!][!//
    [!IF "$LinConfiguredPartitions > 0"!][!//
        [!LOOP "LinGeneral/LinEcucPartitionRef/*"!][!//
            [!VAR "CurrentPartition" = "substring-after(substring-after(substring-after(substring-after(.,'/'),'/'),'/'),'/')"!][!//
    [!CODE!]extern const Lin_43_LPUART_FLEXIO_ConfigType Lin_43_LPUART_FLEXIO_Config[!"$PostBuildVariantNameUnderscore"!]_[!"$CurrentPartition"!]; \[!CR!][!ENDCODE!]
        [!ENDLOOP!][!//
    [!ELSE!][!//
    [!CODE!]extern const Lin_43_LPUART_FLEXIO_ConfigType Lin_43_LPUART_FLEXIO_Config[!"$PostBuildVariantNameUnderscore"!];[!ENDCODE!][!//
    [!ENDIF!][!//
[!ENDIF!][!//
[!ENDNOCODE!][!//

/*==================================================================================================
*                                             ENUMS
==================================================================================================*/

/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/

/*==================================================================================================
*                                  EXTERNAL CONSTANTS
==================================================================================================*/

#ifdef __cplusplus
}
#endif

/** @} */

[!NOCODE!]
[!IF "var:defined('postBuildVariant')"!]
[!CODE!][!//
#endif /* LIN'_43_LPUART_FLEXIO_[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_H */
[!ENDCODE!]
[!ELSE!]
[!CODE!][!//
#endif /* LIN_43_LPUART_FLEXIO_PBCFG_H */
[!ENDCODE!]
[!ENDIF!]
[!ENDNOCODE!]