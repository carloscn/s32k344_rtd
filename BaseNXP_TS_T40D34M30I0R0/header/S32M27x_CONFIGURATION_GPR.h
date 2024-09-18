/*
** ###################################################################
**     Processor:           S32M27x
**     Compiler:            Keil ARM C/C++ Compiler
**     Reference manual:    S32M27x RM Rev.1
**     Version:             rev. 1.1, 2023-01-03
**     Build:               b230103
**
**     Abstract:
**         Peripheral Access Layer for S32M27x
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2023 NXP
**
**     NXP Confidential. This software is owned or controlled by NXP and may
**     only be used strictly in accordance with the applicable license terms.
**     By expressly accepting such terms or by downloading, installing,
**     activating and/or otherwise using the software, you are agreeing that
**     you have read, and that you agree to comply with and are bound by,
**     such license terms. If you do not agree to be bound by the applicable
**     license terms, then you may not retain, install, activate or otherwise
**     use the software.
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
** ###################################################################
*/

/*!
 * @file S32M27x_CONFIGURATION_GPR.h
 * @version 1.1
 * @date 2023-01-03
 * @brief Peripheral Access Layer for S32M27x_CONFIGURATION_GPR
 *
 * This file contains register definitions and macros for easy access to their
 * bit fields.
 *
 * This file assumes LITTLE endian system.
 */

/**
* @page misra_violations MISRA-C:2012 violations
*
* @section [global]
* Violates MISRA 2012 Advisory Rule 2.3, local typedef not referenced
* The SoC header defines typedef for all modules.
*
* @section [global]
* Violates MISRA 2012 Advisory Rule 2.5, local macro not referenced
* The SoC header defines macros for all modules and registers.
*
* @section [global]
* Violates MISRA 2012 Advisory Directive 4.9, Function-like macro
* These are generated macros used for accessing the bit-fields from registers.
*
* @section [global]
* Violates MISRA 2012 Required Rule 5.1, identifier clash
* The supported compilers use more than 31 significant characters for identifiers.
*
* @section [global]
* Violates MISRA 2012 Required Rule 5.2, identifier clash
* The supported compilers use more than 31 significant characters for identifiers.
*
* @section [global]
* Violates MISRA 2012 Required Rule 5.4, identifier clash
* The supported compilers use more than 31 significant characters for identifiers.
*
* @section [global]
* Violates MISRA 2012 Required Rule 5.5, identifier clash
* The supported compilers use more than 31 significant characters for identifiers.
*
* @section [global]
* Violates MISRA 2012 Required Rule 21.1, defined macro '__I' is reserved to the compiler
* This type qualifier is needed to ensure correct I/O access and addressing.
*/

/* Prevention from multiple including the same memory map */
#if !defined(S32M27x_CONFIGURATION_GPR_H_)  /* Check if memory map has not been already included */
#define S32M27x_CONFIGURATION_GPR_H_

#include "S32M27x_COMMON.h"

/* ----------------------------------------------------------------------------
   -- CONFIGURATION_GPR Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup CONFIGURATION_GPR_Peripheral_Access_Layer CONFIGURATION_GPR Peripheral Access Layer
 * @{
 */

/** CONFIGURATION_GPR - Register Layout Typedef */
typedef struct {
  uint8_t RESERVED_0[28];
  __I  uint32_t CONFIG_REG0;                       /**< General Purpose Configuration 0, offset: 0x1C */
  uint8_t RESERVED_1[20];
  __I  uint32_t CONFIG_REG6;                       /**< General Purpose Configuration 6, offset: 0x34 */
  uint8_t RESERVED_2[8];
  __I  uint32_t CONFIG_CFPRH;                      /**< Configuration Code Flash Memory Passive Block, offset: 0x40 */
} CONFIGURATION_GPR_Type, *CONFIGURATION_GPR_MemMapPtr;

/** Number of instances of the CONFIGURATION_GPR module. */
#define CONFIGURATION_GPR_INSTANCE_COUNT         (1u)

/* CONFIGURATION_GPR - Peripheral instance base addresses */
/** Peripheral CONFIGURATION_GPR base address */
#define IP_CONFIGURATION_GPR_BASE                (0x4039C000u)
/** Peripheral CONFIGURATION_GPR base pointer */
#define IP_CONFIGURATION_GPR                     ((CONFIGURATION_GPR_Type *)IP_CONFIGURATION_GPR_BASE)
/** Array initializer of CONFIGURATION_GPR peripheral base addresses */
#define IP_CONFIGURATION_GPR_BASE_ADDRS          { IP_CONFIGURATION_GPR_BASE }
/** Array initializer of CONFIGURATION_GPR peripheral base pointers */
#define IP_CONFIGURATION_GPR_BASE_PTRS           { IP_CONFIGURATION_GPR }

/* ----------------------------------------------------------------------------
   -- CONFIGURATION_GPR Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup CONFIGURATION_GPR_Register_Masks CONFIGURATION_GPR Register Masks
 * @{
 */

/*! @name CONFIG_REG0 - General Purpose Configuration 0 */
/*! @{ */

#define CONFIGURATION_GPR_CONFIG_REG0_EDB_MASK   (0x40U)
#define CONFIGURATION_GPR_CONFIG_REG0_EDB_SHIFT  (6U)
#define CONFIGURATION_GPR_CONFIG_REG0_EDB_WIDTH  (1U)
#define CONFIGURATION_GPR_CONFIG_REG0_EDB(x)     (((uint32_t)(((uint32_t)(x)) << CONFIGURATION_GPR_CONFIG_REG0_EDB_SHIFT)) & CONFIGURATION_GPR_CONFIG_REG0_EDB_MASK)
/*! @} */

/*! @name CONFIG_REG6 - General Purpose Configuration 6 */
/*! @{ */

#define CONFIGURATION_GPR_CONFIG_REG6_FLEXIO_CLOCK_GATE_MASK (0x10U)
#define CONFIGURATION_GPR_CONFIG_REG6_FLEXIO_CLOCK_GATE_SHIFT (4U)
#define CONFIGURATION_GPR_CONFIG_REG6_FLEXIO_CLOCK_GATE_WIDTH (1U)
#define CONFIGURATION_GPR_CONFIG_REG6_FLEXIO_CLOCK_GATE(x) (((uint32_t)(((uint32_t)(x)) << CONFIGURATION_GPR_CONFIG_REG6_FLEXIO_CLOCK_GATE_SHIFT)) & CONFIGURATION_GPR_CONFIG_REG6_FLEXIO_CLOCK_GATE_MASK)

#define CONFIGURATION_GPR_CONFIG_REG6_HL_MASK    (0x80000000U)
#define CONFIGURATION_GPR_CONFIG_REG6_HL_SHIFT   (31U)
#define CONFIGURATION_GPR_CONFIG_REG6_HL_WIDTH   (1U)
#define CONFIGURATION_GPR_CONFIG_REG6_HL(x)      (((uint32_t)(((uint32_t)(x)) << CONFIGURATION_GPR_CONFIG_REG6_HL_SHIFT)) & CONFIGURATION_GPR_CONFIG_REG6_HL_MASK)
/*! @} */

/*! @name CONFIG_CFPRH - Configuration Code Flash Memory Passive Block */
/*! @{ */

#define CONFIGURATION_GPR_CONFIG_CFPRH_SECURE_SIZE_MASK (0x1FE000U)
#define CONFIGURATION_GPR_CONFIG_CFPRH_SECURE_SIZE_SHIFT (13U)
#define CONFIGURATION_GPR_CONFIG_CFPRH_SECURE_SIZE_WIDTH (8U)
#define CONFIGURATION_GPR_CONFIG_CFPRH_SECURE_SIZE(x) (((uint32_t)(((uint32_t)(x)) << CONFIGURATION_GPR_CONFIG_CFPRH_SECURE_SIZE_SHIFT)) & CONFIGURATION_GPR_CONFIG_CFPRH_SECURE_SIZE_MASK)

#define CONFIGURATION_GPR_CONFIG_CFPRH_SOFT_LOCK_MASK (0x40000000U)
#define CONFIGURATION_GPR_CONFIG_CFPRH_SOFT_LOCK_SHIFT (30U)
#define CONFIGURATION_GPR_CONFIG_CFPRH_SOFT_LOCK_WIDTH (1U)
#define CONFIGURATION_GPR_CONFIG_CFPRH_SOFT_LOCK(x) (((uint32_t)(((uint32_t)(x)) << CONFIGURATION_GPR_CONFIG_CFPRH_SOFT_LOCK_SHIFT)) & CONFIGURATION_GPR_CONFIG_CFPRH_SOFT_LOCK_MASK)

#define CONFIGURATION_GPR_CONFIG_CFPRH_HARD_LOCK_MASK (0x80000000U)
#define CONFIGURATION_GPR_CONFIG_CFPRH_HARD_LOCK_SHIFT (31U)
#define CONFIGURATION_GPR_CONFIG_CFPRH_HARD_LOCK_WIDTH (1U)
#define CONFIGURATION_GPR_CONFIG_CFPRH_HARD_LOCK(x) (((uint32_t)(((uint32_t)(x)) << CONFIGURATION_GPR_CONFIG_CFPRH_HARD_LOCK_SHIFT)) & CONFIGURATION_GPR_CONFIG_CFPRH_HARD_LOCK_MASK)
/*! @} */

/*!
 * @}
 */ /* end of group CONFIGURATION_GPR_Register_Masks */

/*!
 * @}
 */ /* end of group CONFIGURATION_GPR_Peripheral_Access_Layer */

#endif  /* #if !defined(S32M27x_CONFIGURATION_GPR_H_) */
