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

#ifndef MCU_IPW_CFG_DEFINES_H
#define MCU_IPW_CFG_DEFINES_H

/**
*   @file       Mcu_Ipw_Cfg_Defines.h
*   @version    3.0.0
*
*   @brief      AUTOSAR Mcu - Configuration file for the driver.
*   @details    Precompile parameters and extern configuration.
*
*   @addtogroup MCU
*   @{
*/

#ifdef __cplusplus
extern "C"{
#endif


/*==================================================================================================
                                         INCLUDE FILES
 1) system and project includes
 2) needed interfaces from external units
 3) internal and external interfaces from this unit
==================================================================================================*/
[!NOCODE!][!// Include specific header file 
[!IF "node:exists(as:modconf("Resource")[1]/ResourceGeneral/ResourceSubderivative)"!][!// 
    [!IF "contains(as:modconf("Resource")[1]/ResourceGeneral/ResourceSubderivative, 's32k312')"!][!// 
[!CODE!][!WS "0"!]#include "S32K312_SIUL2.h"[!CR!][!ENDCODE!][!//
[!CODE!][!WS "0"!]#include "S32K312_EMIOS.h"[!CR!][!ENDCODE!][!//
    [!ELSEIF "contains(as:modconf("Resource")[1]/ResourceGeneral/ResourceSubderivative, 's32k311') or
                contains(as:modconf("Resource")[1]/ResourceGeneral/ResourceSubderivative, 's32k310')"!][!//
[!CODE!][!WS "0"!]#include "S32K311_SIUL2.h"[!CR!][!ENDCODE!][!//
[!CODE!][!WS "0"!]#include "S32K311_EMIOS.h"[!CR!][!ENDCODE!][!//
    [!ELSEIF "contains(as:modconf("Resource")[1]/ResourceGeneral/ResourceSubderivative, 's32k314')"!][!//
[!CODE!][!WS "0"!]#include "S32K314_SIUL2.h"[!CR!][!ENDCODE!][!//
[!CODE!][!WS "0"!]#include "S32K314_EMIOS.h"[!CR!][!ENDCODE!][!//
    [!ELSEIF "contains(as:modconf("Resource")[1]/ResourceGeneral/ResourceSubderivative, 's32k322')"!][!//
[!CODE!][!WS "0"!]#include "S32K322_SIUL2.h"[!CR!][!ENDCODE!][!//
[!CODE!][!WS "0"!]#include "S32K322_EMIOS.h"[!CR!][!ENDCODE!][!//
    [!ELSEIF "contains(as:modconf("Resource")[1]/ResourceGeneral/ResourceSubderivative, 's32k324')"!][!//
[!CODE!][!WS "0"!]#include "S32K324_SIUL2.h"[!CR!][!ENDCODE!][!//
[!CODE!][!WS "0"!]#include "S32K324_EMIOS.h"[!CR!][!ENDCODE!][!//
    [!ELSEIF "contains(as:modconf("Resource")[1]/ResourceGeneral/ResourceSubderivative, 's32k341')"!][!//
[!CODE!][!WS "0"!]#include "S32K341_SIUL2.h"[!CR!][!ENDCODE!][!//
[!CODE!][!WS "0"!]#include "S32K341_EMIOS.h"[!CR!][!ENDCODE!][!//
    [!ELSEIF "contains(as:modconf("Resource")[1]/ResourceGeneral/ResourceSubderivative, 's32k342')"!][!//
[!CODE!][!WS "0"!]#include "S32K342_SIUL2.h"[!CR!][!ENDCODE!][!//
[!CODE!][!WS "0"!]#include "S32K342_EMIOS.h"[!CR!][!ENDCODE!][!//
    [!ELSEIF "contains(as:modconf("Resource")[1]/ResourceGeneral/ResourceSubderivative, 's32k39')"!][!//
[!CODE!][!WS "0"!]#include "S32K39_SIUL2.h"[!CR!][!ENDCODE!][!//
[!CODE!][!WS "0"!]#include "S32K39_EMIOS.h"[!CR!][!ENDCODE!][!//
    [!ELSEIF "contains(as:modconf("Resource")[1]/ResourceGeneral/ResourceSubderivative, 's32k358') or
                contains(as:modconf("Resource")[1]/ResourceGeneral/ResourceSubderivative, 's32k328') or
                contains(as:modconf("Resource")[1]/ResourceGeneral/ResourceSubderivative, 's32k338') or
                contains(as:modconf("Resource")[1]/ResourceGeneral/ResourceSubderivative, 's32k348')"!][!//
[!CODE!][!WS "0"!]#include "S32K358_SIUL2.h"[!CR!][!ENDCODE!][!//
[!CODE!][!WS "0"!]#include "S32K358_EMIOS.h"[!CR!][!ENDCODE!][!//
    [!ELSEIF "contains(as:modconf("Resource")[1]/ResourceGeneral/ResourceSubderivative, 's32k388')"!][!//
[!CODE!][!WS "0"!]#include "S32K388_SIUL2.h"[!CR!][!ENDCODE!][!//
[!CODE!][!WS "0"!]#include "S32K388_EMIOS.h"[!CR!][!ENDCODE!][!//
    [!ELSEIF "contains(as:modconf("Resource")[1]/ResourceGeneral/ResourceSubderivative, 's32m27')"!][!//
[!CODE!][!WS "0"!]#include "S32M27x_SIUL2.h"[!CR!][!ENDCODE!][!//
[!CODE!][!WS "0"!]#include "S32M27x_EMIOS.h"[!CR!][!ENDCODE!][!//
    [!ELSE!][!//
[!CODE!][!WS "0"!]#include "S32K344_SIUL2.h"[!CR!][!ENDCODE!][!//
[!CODE!][!WS "0"!]#include "S32K344_EMIOS.h"[!CR!][!ENDCODE!][!//
    [!ENDIF!][!// 
[!ENDIF!][!// 
[!ENDNOCODE!][!//
/*==================================================================================================
                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define MCU_IPW_CFG_DEFINES_VENDOR_ID                       43
#define MCU_IPW_CFG_DEFINES_AR_RELEASE_MAJOR_VERSION        4
#define MCU_IPW_CFG_DEFINES_AR_RELEASE_MINOR_VERSION        7
#define MCU_IPW_CFG_DEFINES_AR_RELEASE_REVISION_VERSION     0
#define MCU_IPW_CFG_DEFINES_SW_MAJOR_VERSION                3
#define MCU_IPW_CFG_DEFINES_SW_MINOR_VERSION                0
#define MCU_IPW_CFG_DEFINES_SW_PATCH_VERSION                0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/

/*==================================================================================================
                                           DEFINES AND MACROS
==================================================================================================*/

/*==================================================================================================
                                             ENUMS
==================================================================================================*/

/*==================================================================================================
                                 STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

#ifdef __cplusplus
}
#endif

/** @} */
#endif /* #ifndef MCU_IPW_CFG_DEFINES_H */

