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

#ifndef SIUL2_PORT_IP_DEFINES
#define SIUL2_PORT_IP_DEFINES

/**
*   @file    Siul2_Port_Ip_Defines.h
*
*   @addtogroup Port_CFG
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
[!INDENT "0"!][!//
[!IF "node:exists(as:modconf("Resource")[1]/ResourceGeneral/ResourceSubderivative)"!][!//
    [!IF "contains(as:modconf("Resource")[1]/ResourceGeneral/ResourceSubderivative, 's32k311') or contains(as:modconf("Resource")[1]/ResourceGeneral/ResourceSubderivative, 's32k310')"!][!// /* S32K310: sub/phantom derivatives of S32K311 */
#include "S32K311_SIUL2.h"
#include "S32K311_DCM_GPR.h"
    [!ELSEIF "contains(as:modconf("Resource")[1]/ResourceGeneral/ResourceSubderivative, 's32k312')"!][!//
#include "S32K312_SIUL2.h"
#include "S32K312_DCM_GPR.h"
    [!ELSEIF "contains(as:modconf("Resource")[1]/ResourceGeneral/ResourceSubderivative, 's32k314')"!][!//
#include "S32K314_SIUL2.h"
#include "S32K314_DCM_GPR.h"
    [!ELSEIF "contains(as:modconf("Resource")[1]/ResourceGeneral/ResourceSubderivative, 's32k324')"!][!//
#include "S32K324_SIUL2.h"
#include "S32K324_DCM_GPR.h"
    [!ELSEIF "contains(as:modconf("Resource")[1]/ResourceGeneral/ResourceSubderivative, 's32k342')"!][!//
#include "S32K342_SIUL2.h"
#include "S32K342_DCM_GPR.h"
    [!ELSEIF "contains(as:modconf("Resource")[1]/ResourceGeneral/ResourceSubderivative, 's32k341')"!][!//
#include "S32K341_SIUL2.h"
#include "S32K341_DCM_GPR.h"
    [!ELSEIF "contains(as:modconf("Resource")[1]/ResourceGeneral/ResourceSubderivative, 's32k322')"!][!//
#include "S32K322_SIUL2.h"
#include "S32K322_DCM_GPR.h"
    [!ELSEIF "contains(as:modconf("Resource")[1]/ResourceGeneral/ResourceSubderivative, 's32k344')"!][!//
#include "S32K344_SIUL2.h"
#include "S32K344_DCM_GPR.h"
    [!ELSEIF "contains(as:modconf("Resource")[1]/ResourceGeneral/ResourceSubderivative, 's32k358') or contains(as:modconf("Resource")[1]/ResourceGeneral/ResourceSubderivative, 's32k328') or contains(as:modconf("Resource")[1]/ResourceGeneral/ResourceSubderivative, 's32k338') or contains(as:modconf("Resource")[1]/ResourceGeneral/ResourceSubderivative, 's32k348')"!][!// /* S32K328, S32K338, S32K348: sub/phantom derivatives of S32K358 */
#include "S32K358_SIUL2.h"
#include "S32K358_DCM_GPR.h"
    [!ELSEIF "contains(as:modconf("Resource")[1]/ResourceGeneral/ResourceSubderivative, 's32k396') or contains(as:modconf("Resource")[1]/ResourceGeneral/ResourceSubderivative, 's32k394')"!][!// /* S32K394: sub/phantom derivatives of S32K396 */
#include "S32K39_SIUL2.h"
#include "S32K39_DCM_GPR.h"
    [!ELSEIF "contains(as:modconf("Resource")[1]/ResourceGeneral/ResourceSubderivative, 's32k388')"!][!//
#include "S32K388_SIUL2.h"
#include "S32K388_DCM_GPR.h"
    [!ELSEIF "contains(as:modconf("Resource")[1]/ResourceGeneral/ResourceSubderivative, 's32m276') or contains(as:modconf("Resource")[1]/ResourceGeneral/ResourceSubderivative, 's32m274')"!][!// /* S32M274: sub/phantom derivatives of S32M27x */
#include "S32M27x_SIUL2.h"
#include "S32M27x_DCM_GPR.h"
    [!ENDIF!][!//
[!ELSE!][!//
    [!ERROR "The Resource plugin or ResourceSubderivative field is not available for header file inclusion."!][!//
[!ENDIF!][!//
[!ENDINDENT!][!//
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define SIUL2_PORT_IP_DEFINES_VENDOR_ID_H                       43
#define SIUL2_PORT_IP_DEFINES_AR_RELEASE_MAJOR_VERSION_H        4
#define SIUL2_PORT_IP_DEFINES_AR_RELEASE_MINOR_VERSION_H        7
#define SIUL2_PORT_IP_DEFINES_AR_RELEASE_REVISION_VERSION_H     0
#define SIUL2_PORT_IP_DEFINES_SW_MAJOR_VERSION_H                3
#define SIUL2_PORT_IP_DEFINES_SW_MINOR_VERSION_H                0
#define SIUL2_PORT_IP_DEFINES_SW_PATCH_VERSION_H                0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/

/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/
/**
* @brief Number of SIUL2 instances present on the subderivative
*/
#define SIUL2_NUM_SIUL2_INSTANCES_U8   ([!"num:i(count(ecu:list('Port.Siul2Instances')))"!])

/* S32K3XX */
#define SIUL2_PORT_IP_HAS_ONEBIT_SLEWRATE           (STD_ON)
#define SIUL2_PORT_IP_HAS_ADC_INTERLEAVE            (STD_ON)
#define SIUL2_PORT_IP_HAS_NO_RECEIVER_SELECT        (STD_ON)

/*! @brief SIUL2 module has DSE bit */
#define FEATURE_SIUL2_PORT_IP_HAS_DRIVE_STRENGTH    (STD_ON)

/*! @brief SIUL2 module has IFE bit */
#define FEATURE_SIUL2_PORT_IP_HAS_INPUT_FILTER      (STD_ON)

/*! @brief SIUL2 module has PKE bit */
#define FEATURE_SIUL2_PORT_IP_HAS_PULL_KEEPER       (STD_ON)

/*! @brief SIUL2 module has INV bit */
#define FEATURE_SIUL2_PORT_IP_HAS_INVERT_DATA       (STD_ON)

[!IF "contains(as:modconf("Resource")[1]/ResourceGeneral/ResourceSubderivative, 's32k396') or contains(as:modconf("Resource")[1]/ResourceGeneral/ResourceSubderivative, 's32k394')"!][!//  /* S32K394: sub/phantom derivatives of S32K396 */
#define FEATURE_SIUL2_PORT_IP_HAS_INPUT_GLITCH_FILTER       (STD_ON)
[!ELSE!][!//
#define FEATURE_SIUL2_PORT_IP_HAS_TOUCH_SENSING             (STD_ON)
[!ENDIF!][!//

/**
* @brief Macros defined for the SIUL2 IPV that are protected.
*/
#define MCAL_SIUL2_REG_PROT_AVAILABLE   (STD_ON)

/**
* @brief Macros defined for the protection size
*/
#define SIUL2_PROT_MEM_U32    ((uint32)0x00000008UL)

[!IF "PortGeneral/PortEnableUserModeSupport"!][!//
/**
* @brief Support for User mode.
*        If this parameter has been configured to 'STD_ON', the PORT driver code can be executed from both supervisor and user mode.
* @implements   PORT_ENABLE_USER_MODE_SUPPORT_define
*/
#define PORT_ENABLE_USER_MODE_SUPPORT   (STD_ON)

/**
* @brief Support for REG_PROT in SIUL2 IP.
*        If the current platform implements REG_PROT for SIUL2 IP, this parameter will be defined, and will enable REG_PROT configuration for SIUL2 IP in PORT drvier
*/
#define PORT_SIUL2_REG_PROT_AVAILABLE   (STD_ON)
[!ELSE!][!//
#define PORT_ENABLE_USER_MODE_SUPPORT   (STD_OFF)
[!ENDIF!][!//

#ifndef MCAL_ENABLE_USER_MODE_SUPPORT
    #ifdef PORT_ENABLE_USER_MODE_SUPPORT
        #if (STD_ON == PORT_ENABLE_USER_MODE_SUPPORT)
            #error MCAL_ENABLE_USER_MODE_SUPPORT is not enabled. For running Port in user mode the MCAL_ENABLE_USER_MODE_SUPPORT needs to be defined
        #endif /* (STD_ON == PORT_ENABLE_USER_MODE_SUPPORT) */
    #endif /* ifdef PORT_ENABLE_USER_MODE_SUPPORT*/
#endif /* ifndef MCAL_ENABLE_USER_MODE_SUPPORT */

/* Pre-processor switch to enable/disable development error detection for Siul2 Ip API */
#define SIUL2_PORT_IP_DEV_ERROR_DETECT                         ([!IF "PortGeneral/SIUL2PortIPDevErrorDetect"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

/**
* @brief Defines specifying number of IMCRs for each of the SIUL2 instances on the platform
*/
[!NOCODE!][!//
[!VAR "CurInstanceIdx"="0"!][!//
[!FOR "LoopCounter" = "1" TO "num:i(count(ecu:list('Port.Siul2Instances')))"!][!//
    [!VAR "CurInstanceName"="ecu:list('Port.Siul2Instances')[num:i($LoopCounter)]"!][!//
[!CODE!][!//
#define PORT_[!"$CurInstanceName"!]_IMCRS_IDX_END_U16     ((uint16)[!"num:i(ecu:list('Port.Siul2InstanceImcrIdxEnd')[num:i($LoopCounter)])"!])
[!ENDCODE!][!//
    [!VAR "CurInstanceIdx"="$CurInstanceIdx + 1"!][!//
[!ENDFOR!][!//
[!ENDNOCODE!][!//

/* Pre-processor switch to enable/disable VirtWrapper support */
#define PORT_VIRTWRAPPER_SUPPORT                      ([!IF "PortGeneral/VirtWrapperSupport"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])
[!SELECT "PortConfigSet"!][!//
[!IF "../PortGeneral/VirtWrapperSupport"!][!//
[!CODE!][!//
#define SIUL2_PDAC_SLOT_NUM     (6U)

#define SIUL2_PDAC0_BASE          (0x40290000U)
#define SIUL2_PDAC0               ((SIUL2_Type *)SIUL2_PDAC0_BASE)
#define SIUL2_PDAC1_BASE          (0x40298000U)
#define SIUL2_PDAC1               ((SIUL2_Type *)SIUL2_PDAC1_BASE)
#define SIUL2_PDAC2_BASE          (0x402A0000U)
#define SIUL2_PDAC2               ((SIUL2_Type *)SIUL2_PDAC2_BASE)
#define SIUL2_PDAC3_BASE          (0x402A8000U)
#define SIUL2_PDAC3               ((SIUL2_Type *)SIUL2_PDAC3_BASE)
#define SIUL2_PDAC4_BASE          (0x402F4000U)
#define SIUL2_PDAC4               ((SIUL2_Type *)SIUL2_PDAC4_BASE)
#define SIUL2_PDAC5_BASE          (0x40348000U)
#define SIUL2_PDAC5               ((SIUL2_Type *)SIUL2_PDAC5_BASE)
[!ENDCODE!][!//
[!ENDIF!][!//
[!ENDSELECT!][!//

#define SIUL2_MSCR_BASE                (IP_SIUL2->MSCR)
/** SIUL2 */
/** Peripheral PORTA_L_HALF base pointer */
#define PORTA_L_HALF                            ((Siul2_Port_Ip_PortType *)(SIUL2_MSCR_BASE + 0x00))
/** Peripheral PORTA_H_HALF base pointer */
#define PORTA_H_HALF                            ((Siul2_Port_Ip_PortType *)(SIUL2_MSCR_BASE + 0x10))
/** Peripheral PORTB_L_HALF base pointer */
#define PORTB_L_HALF                            ((Siul2_Port_Ip_PortType *)(SIUL2_MSCR_BASE + 0x20))
/** Peripheral PORTB_H_HALF base pointer */
#define PORTB_H_HALF                            ((Siul2_Port_Ip_PortType *)(SIUL2_MSCR_BASE + 0x30))
/** Peripheral PORTC_L_HALF base pointer */
#define PORTC_L_HALF                            ((Siul2_Port_Ip_PortType *)(SIUL2_MSCR_BASE + 0x40))
/** Peripheral PORTC_H_HALF base pointer */
#define PORTC_H_HALF                            ((Siul2_Port_Ip_PortType *)(SIUL2_MSCR_BASE + 0x50))
/** Peripheral PORTD_L_HALF base pointer */
#define PORTD_L_HALF                            ((Siul2_Port_Ip_PortType *)(SIUL2_MSCR_BASE + 0x60))
/** Peripheral PORTD_H_HALF base pointer */
#define PORTD_H_HALF                            ((Siul2_Port_Ip_PortType *)(SIUL2_MSCR_BASE + 0x70))
/** Peripheral PORTE_L_HALF base pointer */
#define PORTE_L_HALF                            ((Siul2_Port_Ip_PortType *)(SIUL2_MSCR_BASE + 0x80))
/** Peripheral PORTE_H_HALF base pointer */
#define PORTE_H_HALF                            ((Siul2_Port_Ip_PortType *)(SIUL2_MSCR_BASE + 0x90))
[!IF "((ecu:get('Port.Derivative'))='s32k314') or ((ecu:get('Port.Derivative'))='s32k324') or ((ecu:get('Port.Derivative'))='s32k344') or ((ecu:get('Port.Derivative'))='s32k394') or ((ecu:get('Port.Derivative'))='s32k396') or ((ecu:get('Port.Derivative'))='s32k358') or ((ecu:get('Port.Derivative'))='s32k328') or ((ecu:get('Port.Derivative'))='s32k338') or ((ecu:get('Port.Derivative'))='s32k348')"!][!//
/** Peripheral PORTF_L_HALF base pointer */
#define PORTF_L_HALF                            ((Siul2_Port_Ip_PortType *)(SIUL2_MSCR_BASE + 0xA0))
/** Peripheral PORTF_H_HALF base pointer */
#define PORTF_H_HALF                            ((Siul2_Port_Ip_PortType *)(SIUL2_MSCR_BASE + 0xB0))
/** Peripheral PORTG_L_HALF base pointer */
#define PORTG_L_HALF                            ((Siul2_Port_Ip_PortType *)(SIUL2_MSCR_BASE + 0xC0))
/** Peripheral PORTG_H_HALF base pointer */
#define PORTG_H_HALF                            ((Siul2_Port_Ip_PortType *)(SIUL2_MSCR_BASE + 0xD0))
[!ENDIF!][!//
[!IF "((ecu:get('Port.Derivative'))='s32k328') or ((ecu:get('Port.Derivative'))='s32k338') or ((ecu:get('Port.Derivative'))='s32k348') or ((ecu:get('Port.Derivative'))='s32k358') or ((ecu:get('Port.Derivative'))='s32k396') or ((ecu:get('Port.Derivative'))='s32k394')"!][!//
/** Peripheral PORTH_L_HALF base pointer */
#define PORTH_L_HALF                            ((Siul2_Port_Ip_PortType *)(SIUL2_MSCR_BASE + 0xE0))
[!ENDIF!][!//


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


#ifdef __cplusplus
}
#endif

/** @} */

#endif /* SIUL2_PORT_IP_DEFINES */
