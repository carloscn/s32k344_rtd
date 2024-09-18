/*==================================================================================================
*   Project              : RTD AUTOSAR 4.7
*   Platform             : CORTEXM
*   Peripheral           : DMA,CACHE,TRGMUX,LCU,EMIOS,FLEXIO
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

/* Prevention from multiple including the same header */
#ifndef TRGMUX_IP_CFG_DEVICEREGISTERS_REGISTERS_H_
#define TRGMUX_IP_CFG_DEVICEREGISTERS_REGISTERS_H_

/**
*   @file    Trgmux_Ip_Cfg_DeviceRegisters.h
*
*   @version 3.0.0
*
*   @brief   AUTOSAR Mcl - Trgmux Ip Cfg Device Registers header file.
*   @details
*
*   @addtogroup TRGMUX_IP_DRIVER TRGMUX IP Driver
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
[!INDENT "0"!][!//
[!IF "node:exists(as:modconf("Resource")[1]/ResourceGeneral/ResourceSubderivative)"!][!//
    [!VAR "DerivativeName" = "text:toupper(substring-before(as:modconf("Resource")[1]/ResourceGeneral/ResourceSubderivative,'_'))"!]
    [!IF "contains($DerivativeName, 'S32K3')"!][!//
        [!IF "contains($DerivativeName, 'S32K396') or contains($DerivativeName, 'S32K394')"!][!//
            [!CODE!][!WS "0"!]#include "S32K39_TRGMUX_APP.h"[!CR!][!ENDCODE!][!//
            [!CODE!][!WS "0"!]#include "S32K39_TRGMUX_MSC.h"[!CR!][!ENDCODE!][!//
        [!ELSEIF "contains($DerivativeName, 'S32K310')"!][!//
            [!CODE!][!WS "0"!]#include "S32K311_TRGMUX.h"[!CR!][!ENDCODE!][!//
        [!ELSEIF "contains($DerivativeName, 'S32K328') or contains($DerivativeName, 'S32K338') or contains($DerivativeName, 'S32K348')"!][!//
            [!CODE!][!WS "0"!]#include "S32K358_TRGMUX.h"[!CR!][!ENDCODE!][!//
        [!ELSE!][!//
            [!CODE!][!WS "0"!]#include "[!"$DerivativeName"!]_TRGMUX.h"[!CR!][!ENDCODE!][!//
        [!ENDIF!][!//
    [!ELSEIF "contains($DerivativeName, 'S32M276') or contains($DerivativeName, 'S32M274')"!][!//
        [!CODE!][!WS "0"!]#include "S32M27x_TRGMUX.h"[!CR!][!ENDCODE!][!//
    [!ELSE!][!//
        [!ERROR "The Resource plugin or ResourceSubderivative field is not available for header file inclusion."!][!//
    [!ENDIF!][!//
[!ELSE!][!//
    [!ERROR "The Resource plugin or ResourceSubderivative field is not available for header file inclusion."!][!//
[!ENDIF!][!//
[!ENDINDENT!][!//

/*==================================================================================================
*                                 SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define TRGMUX_IP_CFG_DEVICEREGISTERS_VENDOR_ID                    43
#define TRGMUX_IP_CFG_DEVICEREGISTERS_MODULE_ID                    255
#define TRGMUX_IP_CFG_DEVICEREGISTERS_AR_RELEASE_MAJOR_VERSION     4
#define TRGMUX_IP_CFG_DEVICEREGISTERS_AR_RELEASE_MINOR_VERSION     7
#define TRGMUX_IP_CFG_DEVICEREGISTERS_AR_RELEASE_REVISION_VERSION  0
#define TRGMUX_IP_CFG_DEVICEREGISTERS_SW_MAJOR_VERSION             3
#define TRGMUX_IP_CFG_DEVICEREGISTERS_SW_MINOR_VERSION             0
#define TRGMUX_IP_CFG_DEVICEREGISTERS_SW_PATCH_VERSION             0


/* ----------------------------------------------------------------------------
   -- TRGMUX Peripheral Access Layer
   ---------------------------------------------------------------------------- */
[!INDENT "0"!][!//
[!IF "node:exists(as:modconf("Resource")[1]/ResourceGeneral/ResourceSubderivative)"!][!//
    [!VAR "DerivativeName" = "text:toupper(substring-before(as:modconf("Resource")[1]/ResourceGeneral/ResourceSubderivative,'_'))"!]
    [!IF "contains($DerivativeName, 'S32K3')"!][!//
        [!IF "contains($DerivativeName, 'S32K396') or contains($DerivativeName, 'S32K394')"!][!//
[!CODE!][!//
/*!
 * @addtogroup TRGMUX_Peripheral_Access_Layer TRGMUX Peripheral Access Layer
 * @{
 */
/** TRGMUX - Size of Registers Arrays */
#define TRGMUX_TRGMUXn_COUNT                    62u
#define TRGMUX_IP_TRGMUXn_INSTANCE_COUNT(Instance)\
        ( (Instance==TRGMUX_IP_HW_INST_0) ? (61u) : (18u) )

/** TRGMUX - Register Layout Typedef */
typedef struct {
  __IO uint32_t TRGMUXn[TRGMUX_TRGMUXn_COUNT];     /**< TRGMUX DMAMUX0 Register..TRGMUX FTM7 Register, array offset: 0x0, array step: 0x4 */
} TRGMUX_Type, *TRGMUX_MemMapPtr;

/** Number of instances of the TRGMUX module. */
#define TRGMUX_INSTANCE_COUNT                    (2u)

/* TRGMUX - Peripheral instance base addresses */
/** Peripheral TRGMUX_0 base address */
#define TRGMUX_IP_0_BASE                         (0x40080000u)
/** Peripheral TRGMUX_0 base pointer */
#define TRGMUX_IP_0                              ((TRGMUX_Type *)TRGMUX_IP_0_BASE)
/** Array initializer of TRGMUX_0 peripheral base addresses */
#define TRGMUX_IP_0_BASE_ADDRS                   { TRGMUX_IP_0_BASE }

/** Peripheral TRGMUX_1 base address */
#define TRGMUX_IP_1_BASE                         (0x406C0000u)
/** Peripheral TRGMUX_1 base pointer */
#define TRGMUX_IP_1                              ((TRGMUX_Type *)TRGMUX_IP_1_BASE)
/** Array initializer of TRGMUX_1 peripheral base addresses */
#define TRGMUX_IP_1_BASE_ADDRS                   { TRGMUX_IP_1_BASE }

/** Array initializer of TRGMUX_0 peripheral base pointers */
#define IP_TRGMUX_BASE_PTRS                      { TRGMUX_IP_0, TRGMUX_IP_1 }

/* ----------------------------------------------------------------------------
   -- TRGMUX Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup TRGMUX_Register_Masks TRGMUX Register Masks
 * @{
 */

/*! @name TRGMUXn - TRGMUX DMAMUX0 Register..TRGMUX FTM7 Register */
/*! @{ */

#define TRGMUX_TRGMUXn_SEL0_MASK                 (0x7FU)
#define TRGMUX_TRGMUXn_SEL0_SHIFT                (0U)
#define TRGMUX_TRGMUXn_SEL0_WIDTH                (7U)
#define TRGMUX_TRGMUXn_SEL0(x)                   (((uint32_t)(((uint32_t)(x)) << TRGMUX_TRGMUXn_SEL0_SHIFT)) & TRGMUX_TRGMUXn_SEL0_MASK)

#define TRGMUX_TRGMUXn_SEL1_MASK                 (0x7F00U)
#define TRGMUX_TRGMUXn_SEL1_SHIFT                (8U)
#define TRGMUX_TRGMUXn_SEL1_WIDTH                (7U)
#define TRGMUX_TRGMUXn_SEL1(x)                   (((uint32_t)(((uint32_t)(x)) << TRGMUX_TRGMUXn_SEL1_SHIFT)) & TRGMUX_TRGMUXn_SEL1_MASK)

#define TRGMUX_TRGMUXn_SEL2_MASK                 (0x7F0000U)
#define TRGMUX_TRGMUXn_SEL2_SHIFT                (16U)
#define TRGMUX_TRGMUXn_SEL2_WIDTH                (7U)
#define TRGMUX_TRGMUXn_SEL2(x)                   (((uint32_t)(((uint32_t)(x)) << TRGMUX_TRGMUXn_SEL2_SHIFT)) & TRGMUX_TRGMUXn_SEL2_MASK)

#define TRGMUX_TRGMUXn_SEL3_MASK                 (0x7F000000U)
#define TRGMUX_TRGMUXn_SEL3_SHIFT                (24U)
#define TRGMUX_TRGMUXn_SEL3_WIDTH                (7U)
#define TRGMUX_TRGMUXn_SEL3(x)                   (((uint32_t)(((uint32_t)(x)) << TRGMUX_TRGMUXn_SEL3_SHIFT)) & TRGMUX_TRGMUXn_SEL3_MASK)

#define TRGMUX_TRGMUXn_LK_MASK                   (0x80000000U)
#define TRGMUX_TRGMUXn_LK_SHIFT                  (31U)
#define TRGMUX_TRGMUXn_LK_WIDTH                  (1U)
#define TRGMUX_TRGMUXn_LK(x)                     (((uint32_t)(((uint32_t)(x)) << TRGMUX_TRGMUXn_LK_SHIFT)) & TRGMUX_TRGMUXn_LK_MASK)
/*! @} */
[!ENDCODE!][!//

        [!ELSE!][!//
[!CODE!][!//
#define TRGMUX_IP_TRGMUXn_INSTANCE_COUNT(Instance)   TRGMUX_TRGMUXn_COUNT
[!ENDCODE!][!//

        [!ENDIF!][!//
    [!ELSEIF "contains($DerivativeName, 'S32M276') or contains($DerivativeName, 'S32M274')"!][!//
[!CODE!][!//
#define TRGMUX_IP_TRGMUXn_INSTANCE_COUNT(Instance)   TRGMUX_TRGMUXn_COUNT
[!ENDCODE!][!//
    [!ENDIF!][!//
[!ELSE!][!//
    [!ERROR "The Resource plugin or ResourceSubderivative field is not available for header file inclusion."!][!//
[!ENDIF!][!//
[!ENDINDENT!][!//

#ifdef __cplusplus
}
#endif

/** @} */

#endif  /* #ifndef TRGMUX_IP_CFG_DEVICEREGISTERS_REGISTERS_H_ */

/*==================================================================================================
 *                                        END OF FILE
==================================================================================================*/
