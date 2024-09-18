/*==================================================================================================
*   Project              : RTD AUTOSAR 4.7
*   Platform             : CORTEXM
*   Peripheral           : Swt
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

#ifndef SWT_DEVICE_REGISTERS_H
#define SWT_DEVICE_REGISTERS_H

/**
*   @file
*
*   @addtogroup Swt
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

[!NOCODE!][!// Include specific header file 
[!IF "node:exists(as:modconf("Resource")[1]/ResourceGeneral/ResourceSubderivative)"!][!// 
    [!VAR "DerivativeName" = "text:toupper(substring-before(as:modconf("Resource")[1]/ResourceGeneral/ResourceSubderivative,'_'))"!][!//
    [!IF "contains($DerivativeName, 'S32K3')"!][!//
        [!IF "contains($DerivativeName, 'S32K39')"!][!//
            [!VAR "DerivativeName" = "'S32K39'"!][!//
        [!ELSEIF "$DerivativeName = 'S32K328'"!][!//
            [!VAR "DerivativeName" = "'S32K358'"!][!//
        [!ELSEIF "$DerivativeName = 'S32K338'"!][!//
            [!VAR "DerivativeName" = "'S32K358'"!][!//
        [!ELSEIF "$DerivativeName = 'S32K348'"!][!//
            [!VAR "DerivativeName" = "'S32K358'"!][!//
        [!ELSEIF "$DerivativeName = 'S32K310'"!][!//
            [!VAR "DerivativeName" = "'S32K311'"!][!//
        [!ENDIF!][!//
[!CODE!][!WS "0"!]#include "[!"$DerivativeName"!]_SWT.h"[!CR!][!ENDCODE!][!//
    [!ELSEIF "contains(as:modconf("Resource")[1]/ResourceGeneral/ResourceSubderivative, 's32g2')"!][!// 
[!CODE!][!WS "0"!]#include "S32G274A_SWT.h"[!CR!][!ENDCODE!][!// 
    [!ELSEIF "contains(as:modconf("Resource")[1]/ResourceGeneral/ResourceSubderivative, 's32g3')"!][!// 
[!CODE!][!WS "0"!]#include "S32G399A_SWT.h"[!CR!][!ENDCODE!][!// 
    [!ELSEIF "contains(as:modconf("Resource")[1]/ResourceGeneral/ResourceSubderivative, 's32r45')"!][!// 
[!CODE!][!WS "0"!]#include "S32R45_SWT.h"[!CR!][!ENDCODE!][!// 
    [!ELSEIF "contains(as:modconf("Resource")[1]/ResourceGeneral/ResourceSubderivative, 's32r41')"!][!// 
[!CODE!][!WS "0"!]#include "S32R41_SWT.h"[!CR!][!ENDCODE!][!// 
    [!ELSEIF "contains(as:modconf("Resource")[1]/ResourceGeneral/ResourceSubderivative, 'sja')"!][!// 
[!CODE!][!WS "0"!]#include "SJA1110.h"[!CR!][!ENDCODE!][!// 
    [!ELSEIF "contains(as:modconf("Resource")[1]/ResourceGeneral/ResourceSubderivative, 's32e')"!][!// 
[!CODE!][!WS "0"!]#include "S32E2_SWT.h"[!CR!][!ENDCODE!][!// 
    [!ELSEIF "contains(as:modconf("Resource")[1]/ResourceGeneral/ResourceSubderivative, 's32s')"!][!// 
[!CODE!][!WS "0"!]#include "S32E2_SWT.h"[!CR!][!ENDCODE!][!// 
    [!ELSEIF "contains(as:modconf("Resource")[1]/ResourceGeneral/ResourceSubderivative, 's32z')"!][!// 
[!CODE!][!WS "0"!]#include "S32Z2_SWT.h"[!CR!][!ENDCODE!][!// 
    [!ELSEIF "contains(as:modconf("Resource")[1]/ResourceGeneral/ResourceSubderivative, 'saf85')"!][!// 
[!CODE!][!WS "0"!]#include "SAF85XX_SWT.h"[!CR!][!ENDCODE!][!// 
    [!ELSEIF "contains(as:modconf("Resource")[1]/ResourceGeneral/ResourceSubderivative, 's32n')"!][!// 
[!CODE!][!WS "0"!]#include "S32N2RT_SWT.h"[!CR!][!ENDCODE!][!//
    [!ELSEIF "contains(as:modconf("Resource")[1]/ResourceGeneral/ResourceSubderivative, 's32m27')"!][!//
[!CODE!][!WS "0"!]#include "S32M27x_SWT.h"[!CR!][!ENDCODE!][!// 
    [!ENDIF!][!// 
[!ENDIF!][!// 
[!ENDNOCODE!][!//

/*==================================================================================================
*                                 SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define SWT_IP_DEVICE_REGISTERS_VENDOR_ID                    43
#define SWT_IP_DEVICE_REGISTERS_MODULE_ID                    102
#define SWT_IP_DEVICE_REGISTERS_AR_RELEASE_MAJOR_VERSION     4
#define SWT_IP_DEVICE_REGISTERS_AR_RELEASE_MINOR_VERSION     7
#define SWT_IP_DEVICE_REGISTERS_AR_RELEASE_REVISION_VERSION  0
#define SWT_IP_DEVICE_REGISTERS_SW_MAJOR_VERSION             3
#define SWT_IP_DEVICE_REGISTERS_SW_MINOR_VERSION             0
#define SWT_IP_DEVICE_REGISTERS_SW_PATCH_VERSION             0

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/

/*==================================================================================================
*                                            CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/

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

#endif /*SWT_DEVICE_REGISTERS_H */
