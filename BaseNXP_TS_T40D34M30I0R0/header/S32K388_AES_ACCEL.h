/*
** ###################################################################
**     Processor:           S32K388_M7
**     Compiler:            Keil ARM C/C++ Compiler
**     Reference manual:    S32K3xx RM Rev.6 Draft A
**     Version:             rev. 1.1, 2022-12-23
**     Build:               b221223
**
**     Abstract:
**         Peripheral Access Layer for S32K388_M7
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2022 NXP
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
 * @file S32K388_AES_ACCEL.h
 * @version 1.1
 * @date 2022-12-23
 * @brief Peripheral Access Layer for S32K388_AES_ACCEL
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
#if !defined(S32K388_AES_ACCEL_H_)  /* Check if memory map has not been already included */
#define S32K388_AES_ACCEL_H_

#include "S32K388_COMMON.h"

/* ----------------------------------------------------------------------------
   -- AES_ACCEL Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup AES_ACCEL_Peripheral_Access_Layer AES_ACCEL Peripheral Access Layer
 * @{
 */

/** AES_ACCEL - Register Layout Typedef */
typedef struct {
  __IO uint32_t LEN0;                              /**< LEN register, offset: 0x0 */
  __IO uint32_t AILEN0;                            /**< AAD/IV length register, offset: 0x4 */
  __IO uint32_t CRYPT0;                            /**< CRYPT register, offset: 0x8 */
  __I  uint32_t OWNSTAT0;                          /**< OWN_Status register, offset: 0xC */
  __IO uint32_t TLVAL0;                            /**< Timer Load Value Register, offset: 0x10 */
  __I  uint32_t CVAL0;                             /**< Current Timer Value Register, offset: 0x14 */
  __IO uint32_t TCTRL0;                            /**< Timer Control Register, offset: 0x18 */
  __IO uint32_t TFLG0;                             /**< Timer Flag Register, offset: 0x1C */
  __IO uint32_t FEEDINTMAP0;                       /**< FEEDINTMAP register, offset: 0x20 */
  __IO uint32_t RESULTINTMAP0;                     /**< RESULTINTMAP register, offset: 0x24 */
  uint8_t RESERVED_0[65496];
  __IO uint32_t LEN1;                              /**< LEN register, offset: 0x10000 */
  __IO uint32_t AILEN1;                            /**< AAD/IV length register, offset: 0x10004 */
  __IO uint32_t CRYPT1;                            /**< CRYPT register, offset: 0x10008 */
  __I  uint32_t OWNSTAT1;                          /**< OWN_Status register, offset: 0x1000C */
  __IO uint32_t TLVAL1;                            /**< Timer Load Value Register, offset: 0x10010 */
  __I  uint32_t CVAL1;                             /**< Current Timer Value Register, offset: 0x10014 */
  __IO uint32_t TCTRL1;                            /**< Timer Control Register, offset: 0x10018 */
  __IO uint32_t TFLG1;                             /**< Timer Flag Register, offset: 0x1001C */
  __IO uint32_t FEEDINTMAP1;                       /**< FEEDINTMAP register, offset: 0x10020 */
  __IO uint32_t RESULTINTMAP1;                     /**< RESULTINTMAP register, offset: 0x10024 */
  uint8_t RESERVED_1[65496];
  __IO uint32_t LEN2;                              /**< LEN register, offset: 0x20000 */
  __IO uint32_t AILEN2;                            /**< AAD/IV length register, offset: 0x20004 */
  __IO uint32_t CRYPT2;                            /**< CRYPT register, offset: 0x20008 */
  __I  uint32_t OWNSTAT2;                          /**< OWN_Status register, offset: 0x2000C */
  __IO uint32_t TLVAL2;                            /**< Timer Load Value Register, offset: 0x20010 */
  __I  uint32_t CVAL2;                             /**< Current Timer Value Register, offset: 0x20014 */
  __IO uint32_t TCTRL2;                            /**< Timer Control Register, offset: 0x20018 */
  __IO uint32_t TFLG2;                             /**< Timer Flag Register, offset: 0x2001C */
  __IO uint32_t FEEDINTMAP2;                       /**< FEEDINTMAP register, offset: 0x20020 */
  __IO uint32_t RESULTINTMAP2;                     /**< RESULTINTMAP register, offset: 0x20024 */
  uint8_t RESERVED_2[1245144];
  __IO uint32_t LEN3;                              /**< LEN register, offset: 0x150000 */
  __IO uint32_t AILEN3;                            /**< AAD/IV length register, offset: 0x150004 */
  __IO uint32_t CRYPT3;                            /**< CRYPT register, offset: 0x150008 */
  __I  uint32_t OWNSTAT3;                          /**< OWN_Status register, offset: 0x15000C */
  __IO uint32_t TLVAL3;                            /**< Timer Load Value Register, offset: 0x150010 */
  __I  uint32_t CVAL3;                             /**< Current Timer Value Register, offset: 0x150014 */
  __IO uint32_t TCTRL3;                            /**< Timer Control Register, offset: 0x150018 */
  __IO uint32_t TFLG3;                             /**< Timer Flag Register, offset: 0x15001C */
  __IO uint32_t FEEDINTMAP3;                       /**< FEEDINTMAP register, offset: 0x150020 */
  __IO uint32_t RESULTINTMAP3;                     /**< RESULTINTMAP register, offset: 0x150024 */
  uint8_t RESERVED_3[65496];
  __IO uint32_t LEN4;                              /**< LEN register, offset: 0x160000 */
  __IO uint32_t AILEN4;                            /**< AAD/IV length register, offset: 0x160004 */
  __IO uint32_t CRYPT4;                            /**< CRYPT register, offset: 0x160008 */
  __I  uint32_t OWNSTAT4;                          /**< OWN_Status register, offset: 0x16000C */
  __IO uint32_t TLVAL4;                            /**< Timer Load Value Register, offset: 0x160010 */
  __I  uint32_t CVAL4;                             /**< Current Timer Value Register, offset: 0x160014 */
  __IO uint32_t TCTRL4;                            /**< Timer Control Register, offset: 0x160018 */
  __IO uint32_t TFLG4;                             /**< Timer Flag Register, offset: 0x16001C */
  __IO uint32_t FEEDINTMAP4;                       /**< FEEDINTMAP register, offset: 0x160020 */
  __IO uint32_t RESULTINTMAP4;                     /**< RESULTINTMAP register, offset: 0x160024 */
  uint8_t RESERVED_4[65496];
  __IO uint32_t LEN5;                              /**< LEN register, offset: 0x170000 */
  __IO uint32_t AILEN5;                            /**< AAD/IV length register, offset: 0x170004 */
  __IO uint32_t CRYPT5;                            /**< CRYPT register, offset: 0x170008 */
  __I  uint32_t OWNSTAT5;                          /**< OWN_Status register, offset: 0x17000C */
  __IO uint32_t TLVAL5;                            /**< Timer Load Value Register, offset: 0x170010 */
  __I  uint32_t CVAL5;                             /**< Current Timer Value Register, offset: 0x170014 */
  __IO uint32_t TCTRL5;                            /**< Timer Control Register, offset: 0x170018 */
  __IO uint32_t TFLG5;                             /**< Timer Flag Register, offset: 0x17001C */
  __IO uint32_t FEEDINTMAP5;                       /**< FEEDINTMAP register, offset: 0x170020 */
  __IO uint32_t RESULTINTMAP5;                     /**< RESULTINTMAP register, offset: 0x170024 */
  uint8_t RESERVED_5[65496];
  __IO uint32_t LEN6;                              /**< LEN register, offset: 0x180000 */
  __IO uint32_t AILEN6;                            /**< AAD/IV length register, offset: 0x180004 */
  __IO uint32_t CRYPT6;                            /**< CRYPT register, offset: 0x180008 */
  __I  uint32_t OWNSTAT6;                          /**< OWN_Status register, offset: 0x18000C */
  __IO uint32_t TLVAL6;                            /**< Timer Load Value Register, offset: 0x180010 */
  __I  uint32_t CVAL6;                             /**< Current Timer Value Register, offset: 0x180014 */
  __IO uint32_t TCTRL6;                            /**< Timer Control Register, offset: 0x180018 */
  __IO uint32_t TFLG6;                             /**< Timer Flag Register, offset: 0x18001C */
  __IO uint32_t FEEDINTMAP6;                       /**< FEEDINTMAP register, offset: 0x180020 */
  __IO uint32_t RESULTINTMAP6;                     /**< RESULTINTMAP register, offset: 0x180024 */
  uint8_t RESERVED_6[65496];
  __IO uint32_t LEN7;                              /**< LEN register, offset: 0x190000 */
  __IO uint32_t AILEN7;                            /**< AAD/IV length register, offset: 0x190004 */
  __IO uint32_t CRYPT7;                            /**< CRYPT register, offset: 0x190008 */
  __I  uint32_t OWNSTAT7;                          /**< OWN_Status register, offset: 0x19000C */
  __IO uint32_t TLVAL7;                            /**< Timer Load Value Register, offset: 0x190010 */
  __I  uint32_t CVAL7;                             /**< Current Timer Value Register, offset: 0x190014 */
  __IO uint32_t TCTRL7;                            /**< Timer Control Register, offset: 0x190018 */
  __IO uint32_t TFLG7;                             /**< Timer Flag Register, offset: 0x19001C */
  __IO uint32_t FEEDINTMAP7;                       /**< FEEDINTMAP register, offset: 0x190020 */
  __IO uint32_t RESULTINTMAP7;                     /**< RESULTINTMAP register, offset: 0x190024 */
} AES_ACCEL_Type, *AES_ACCEL_MemMapPtr;

/** Number of instances of the AES_ACCEL module. */
#define AES_ACCEL_INSTANCE_COUNT                 (1u)

/* AES_ACCEL - Peripheral instance base addresses */
/** Peripheral AES_ACCEL base address */
#define IP_AES_ACCEL_BASE                        (0x403D0000u)
/** Peripheral AES_ACCEL base pointer */
#define IP_AES_ACCEL                             ((AES_ACCEL_Type *)IP_AES_ACCEL_BASE)
/** Array initializer of AES_ACCEL peripheral base addresses */
#define IP_AES_ACCEL_BASE_ADDRS                  { IP_AES_ACCEL_BASE }
/** Array initializer of AES_ACCEL peripheral base pointers */
#define IP_AES_ACCEL_BASE_PTRS                   { IP_AES_ACCEL }

/* ----------------------------------------------------------------------------
   -- AES_ACCEL Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup AES_ACCEL_Register_Masks AES_ACCEL Register Masks
 * @{
 */

/*! @name LEN0 - LEN register */
/*! @{ */

#define AES_ACCEL_LEN0_TLEN_MASK                 (0x7FFFFU)
#define AES_ACCEL_LEN0_TLEN_SHIFT                (0U)
#define AES_ACCEL_LEN0_TLEN_WIDTH                (19U)
#define AES_ACCEL_LEN0_TLEN(x)                   (((uint32_t)(((uint32_t)(x)) << AES_ACCEL_LEN0_TLEN_SHIFT)) & AES_ACCEL_LEN0_TLEN_MASK)
/*! @} */

/*! @name AILEN0 - AAD/IV length register */
/*! @{ */

#define AES_ACCEL_AILEN0_AAD_MASK                (0x7FFFFU)
#define AES_ACCEL_AILEN0_AAD_SHIFT               (0U)
#define AES_ACCEL_AILEN0_AAD_WIDTH               (19U)
#define AES_ACCEL_AILEN0_AAD(x)                  (((uint32_t)(((uint32_t)(x)) << AES_ACCEL_AILEN0_AAD_SHIFT)) & AES_ACCEL_AILEN0_AAD_MASK)

#define AES_ACCEL_AILEN0_IVLEN_MASK              (0x7F000000U)
#define AES_ACCEL_AILEN0_IVLEN_SHIFT             (24U)
#define AES_ACCEL_AILEN0_IVLEN_WIDTH             (7U)
#define AES_ACCEL_AILEN0_IVLEN(x)                (((uint32_t)(((uint32_t)(x)) << AES_ACCEL_AILEN0_IVLEN_SHIFT)) & AES_ACCEL_AILEN0_IVLEN_MASK)
/*! @} */

/*! @name CRYPT0 - CRYPT register */
/*! @{ */

#define AES_ACCEL_CRYPT0_MASK_MASK               (0x7FU)
#define AES_ACCEL_CRYPT0_MASK_SHIFT              (0U)
#define AES_ACCEL_CRYPT0_MASK_WIDTH              (7U)
#define AES_ACCEL_CRYPT0_MASK(x)                 (((uint32_t)(((uint32_t)(x)) << AES_ACCEL_CRYPT0_MASK_SHIFT)) & AES_ACCEL_CRYPT0_MASK_MASK)

#define AES_ACCEL_CRYPT0_CMODE_MASK              (0xF00U)
#define AES_ACCEL_CRYPT0_CMODE_SHIFT             (8U)
#define AES_ACCEL_CRYPT0_CMODE_WIDTH             (4U)
#define AES_ACCEL_CRYPT0_CMODE(x)                (((uint32_t)(((uint32_t)(x)) << AES_ACCEL_CRYPT0_CMODE_SHIFT)) & AES_ACCEL_CRYPT0_CMODE_MASK)

#define AES_ACCEL_CRYPT0_CO_MASK                 (0x3000U)
#define AES_ACCEL_CRYPT0_CO_SHIFT                (12U)
#define AES_ACCEL_CRYPT0_CO_WIDTH                (2U)
#define AES_ACCEL_CRYPT0_CO(x)                   (((uint32_t)(((uint32_t)(x)) << AES_ACCEL_CRYPT0_CO_SHIFT)) & AES_ACCEL_CRYPT0_CO_MASK)

#define AES_ACCEL_CRYPT0_KSLOT_MASK              (0xFF0000U)
#define AES_ACCEL_CRYPT0_KSLOT_SHIFT             (16U)
#define AES_ACCEL_CRYPT0_KSLOT_WIDTH             (8U)
#define AES_ACCEL_CRYPT0_KSLOT(x)                (((uint32_t)(((uint32_t)(x)) << AES_ACCEL_CRYPT0_KSLOT_SHIFT)) & AES_ACCEL_CRYPT0_KSLOT_MASK)
/*! @} */

/*! @name OWNSTAT0 - OWN_Status register */
/*! @{ */

#define AES_ACCEL_OWNSTAT0_DID_MASK              (0xFU)
#define AES_ACCEL_OWNSTAT0_DID_SHIFT             (0U)
#define AES_ACCEL_OWNSTAT0_DID_WIDTH             (4U)
#define AES_ACCEL_OWNSTAT0_DID(x)                (((uint32_t)(((uint32_t)(x)) << AES_ACCEL_OWNSTAT0_DID_SHIFT)) & AES_ACCEL_OWNSTAT0_DID_MASK)

#define AES_ACCEL_OWNSTAT0_NS_MASK               (0x40U)
#define AES_ACCEL_OWNSTAT0_NS_SHIFT              (6U)
#define AES_ACCEL_OWNSTAT0_NS_WIDTH              (1U)
#define AES_ACCEL_OWNSTAT0_NS(x)                 (((uint32_t)(((uint32_t)(x)) << AES_ACCEL_OWNSTAT0_NS_SHIFT)) & AES_ACCEL_OWNSTAT0_NS_MASK)

#define AES_ACCEL_OWNSTAT0_PRIV_MASK             (0x80U)
#define AES_ACCEL_OWNSTAT0_PRIV_SHIFT            (7U)
#define AES_ACCEL_OWNSTAT0_PRIV_WIDTH            (1U)
#define AES_ACCEL_OWNSTAT0_PRIV(x)               (((uint32_t)(((uint32_t)(x)) << AES_ACCEL_OWNSTAT0_PRIV_SHIFT)) & AES_ACCEL_OWNSTAT0_PRIV_MASK)
/*! @} */

/*! @name TLVAL0 - Timer Load Value Register */
/*! @{ */

#define AES_ACCEL_TLVAL0_TSV_MASK                (0xFFFFU)
#define AES_ACCEL_TLVAL0_TSV_SHIFT               (0U)
#define AES_ACCEL_TLVAL0_TSV_WIDTH               (16U)
#define AES_ACCEL_TLVAL0_TSV(x)                  (((uint32_t)(((uint32_t)(x)) << AES_ACCEL_TLVAL0_TSV_SHIFT)) & AES_ACCEL_TLVAL0_TSV_MASK)
/*! @} */

/*! @name CVAL0 - Current Timer Value Register */
/*! @{ */

#define AES_ACCEL_CVAL0_TVL_MASK                 (0xFFFFU)
#define AES_ACCEL_CVAL0_TVL_SHIFT                (0U)
#define AES_ACCEL_CVAL0_TVL_WIDTH                (16U)
#define AES_ACCEL_CVAL0_TVL(x)                   (((uint32_t)(((uint32_t)(x)) << AES_ACCEL_CVAL0_TVL_SHIFT)) & AES_ACCEL_CVAL0_TVL_MASK)
/*! @} */

/*! @name TCTRL0 - Timer Control Register */
/*! @{ */

#define AES_ACCEL_TCTRL0_TEN_MASK                (0x1U)
#define AES_ACCEL_TCTRL0_TEN_SHIFT               (0U)
#define AES_ACCEL_TCTRL0_TEN_WIDTH               (1U)
#define AES_ACCEL_TCTRL0_TEN(x)                  (((uint32_t)(((uint32_t)(x)) << AES_ACCEL_TCTRL0_TEN_SHIFT)) & AES_ACCEL_TCTRL0_TEN_MASK)

#define AES_ACCEL_TCTRL0_TIE_MASK                (0x2U)
#define AES_ACCEL_TCTRL0_TIE_SHIFT               (1U)
#define AES_ACCEL_TCTRL0_TIE_WIDTH               (1U)
#define AES_ACCEL_TCTRL0_TIE(x)                  (((uint32_t)(((uint32_t)(x)) << AES_ACCEL_TCTRL0_TIE_SHIFT)) & AES_ACCEL_TCTRL0_TIE_MASK)

#define AES_ACCEL_TCTRL0_FRZ_MASK                (0x4U)
#define AES_ACCEL_TCTRL0_FRZ_SHIFT               (2U)
#define AES_ACCEL_TCTRL0_FRZ_WIDTH               (1U)
#define AES_ACCEL_TCTRL0_FRZ(x)                  (((uint32_t)(((uint32_t)(x)) << AES_ACCEL_TCTRL0_FRZ_SHIFT)) & AES_ACCEL_TCTRL0_FRZ_MASK)
/*! @} */

/*! @name TFLG0 - Timer Flag Register */
/*! @{ */

#define AES_ACCEL_TFLG0_TIF_MASK                 (0x1U)
#define AES_ACCEL_TFLG0_TIF_SHIFT                (0U)
#define AES_ACCEL_TFLG0_TIF_WIDTH                (1U)
#define AES_ACCEL_TFLG0_TIF(x)                   (((uint32_t)(((uint32_t)(x)) << AES_ACCEL_TFLG0_TIF_SHIFT)) & AES_ACCEL_TFLG0_TIF_MASK)
/*! @} */

/*! @name FEEDINTMAP0 - FEEDINTMAP register */
/*! @{ */

#define AES_ACCEL_FEEDINTMAP0_FIEN0_MASK         (0x1U)
#define AES_ACCEL_FEEDINTMAP0_FIEN0_SHIFT        (0U)
#define AES_ACCEL_FEEDINTMAP0_FIEN0_WIDTH        (1U)
#define AES_ACCEL_FEEDINTMAP0_FIEN0(x)           (((uint32_t)(((uint32_t)(x)) << AES_ACCEL_FEEDINTMAP0_FIEN0_SHIFT)) & AES_ACCEL_FEEDINTMAP0_FIEN0_MASK)

#define AES_ACCEL_FEEDINTMAP0_FIEN8_MASK         (0x2U)
#define AES_ACCEL_FEEDINTMAP0_FIEN8_SHIFT        (1U)
#define AES_ACCEL_FEEDINTMAP0_FIEN8_WIDTH        (1U)
#define AES_ACCEL_FEEDINTMAP0_FIEN8(x)           (((uint32_t)(((uint32_t)(x)) << AES_ACCEL_FEEDINTMAP0_FIEN8_SHIFT)) & AES_ACCEL_FEEDINTMAP0_FIEN8_MASK)

#define AES_ACCEL_FEEDINTMAP0_FIEN16_MASK        (0x4U)
#define AES_ACCEL_FEEDINTMAP0_FIEN16_SHIFT       (2U)
#define AES_ACCEL_FEEDINTMAP0_FIEN16_WIDTH       (1U)
#define AES_ACCEL_FEEDINTMAP0_FIEN16(x)          (((uint32_t)(((uint32_t)(x)) << AES_ACCEL_FEEDINTMAP0_FIEN16_SHIFT)) & AES_ACCEL_FEEDINTMAP0_FIEN16_MASK)

#define AES_ACCEL_FEEDINTMAP0_FIEN24_MASK        (0x8U)
#define AES_ACCEL_FEEDINTMAP0_FIEN24_SHIFT       (3U)
#define AES_ACCEL_FEEDINTMAP0_FIEN24_WIDTH       (1U)
#define AES_ACCEL_FEEDINTMAP0_FIEN24(x)          (((uint32_t)(((uint32_t)(x)) << AES_ACCEL_FEEDINTMAP0_FIEN24_SHIFT)) & AES_ACCEL_FEEDINTMAP0_FIEN24_MASK)
/*! @} */

/*! @name RESULTINTMAP0 - RESULTINTMAP register */
/*! @{ */

#define AES_ACCEL_RESULTINTMAP0_RIEN0_MASK       (0x1U)
#define AES_ACCEL_RESULTINTMAP0_RIEN0_SHIFT      (0U)
#define AES_ACCEL_RESULTINTMAP0_RIEN0_WIDTH      (1U)
#define AES_ACCEL_RESULTINTMAP0_RIEN0(x)         (((uint32_t)(((uint32_t)(x)) << AES_ACCEL_RESULTINTMAP0_RIEN0_SHIFT)) & AES_ACCEL_RESULTINTMAP0_RIEN0_MASK)

#define AES_ACCEL_RESULTINTMAP0_RIEN8_MASK       (0x2U)
#define AES_ACCEL_RESULTINTMAP0_RIEN8_SHIFT      (1U)
#define AES_ACCEL_RESULTINTMAP0_RIEN8_WIDTH      (1U)
#define AES_ACCEL_RESULTINTMAP0_RIEN8(x)         (((uint32_t)(((uint32_t)(x)) << AES_ACCEL_RESULTINTMAP0_RIEN8_SHIFT)) & AES_ACCEL_RESULTINTMAP0_RIEN8_MASK)

#define AES_ACCEL_RESULTINTMAP0_RIEN16_MASK      (0x4U)
#define AES_ACCEL_RESULTINTMAP0_RIEN16_SHIFT     (2U)
#define AES_ACCEL_RESULTINTMAP0_RIEN16_WIDTH     (1U)
#define AES_ACCEL_RESULTINTMAP0_RIEN16(x)        (((uint32_t)(((uint32_t)(x)) << AES_ACCEL_RESULTINTMAP0_RIEN16_SHIFT)) & AES_ACCEL_RESULTINTMAP0_RIEN16_MASK)
/*! @} */

/*! @name LEN1 - LEN register */
/*! @{ */

#define AES_ACCEL_LEN1_TLEN_MASK                 (0x7FFFFU)
#define AES_ACCEL_LEN1_TLEN_SHIFT                (0U)
#define AES_ACCEL_LEN1_TLEN_WIDTH                (19U)
#define AES_ACCEL_LEN1_TLEN(x)                   (((uint32_t)(((uint32_t)(x)) << AES_ACCEL_LEN1_TLEN_SHIFT)) & AES_ACCEL_LEN1_TLEN_MASK)
/*! @} */

/*! @name AILEN1 - AAD/IV length register */
/*! @{ */

#define AES_ACCEL_AILEN1_AAD_MASK                (0x7FFFFU)
#define AES_ACCEL_AILEN1_AAD_SHIFT               (0U)
#define AES_ACCEL_AILEN1_AAD_WIDTH               (19U)
#define AES_ACCEL_AILEN1_AAD(x)                  (((uint32_t)(((uint32_t)(x)) << AES_ACCEL_AILEN1_AAD_SHIFT)) & AES_ACCEL_AILEN1_AAD_MASK)

#define AES_ACCEL_AILEN1_IVLEN_MASK              (0x7F000000U)
#define AES_ACCEL_AILEN1_IVLEN_SHIFT             (24U)
#define AES_ACCEL_AILEN1_IVLEN_WIDTH             (7U)
#define AES_ACCEL_AILEN1_IVLEN(x)                (((uint32_t)(((uint32_t)(x)) << AES_ACCEL_AILEN1_IVLEN_SHIFT)) & AES_ACCEL_AILEN1_IVLEN_MASK)
/*! @} */

/*! @name CRYPT1 - CRYPT register */
/*! @{ */

#define AES_ACCEL_CRYPT1_MASK_MASK               (0x7FU)
#define AES_ACCEL_CRYPT1_MASK_SHIFT              (0U)
#define AES_ACCEL_CRYPT1_MASK_WIDTH              (7U)
#define AES_ACCEL_CRYPT1_MASK(x)                 (((uint32_t)(((uint32_t)(x)) << AES_ACCEL_CRYPT1_MASK_SHIFT)) & AES_ACCEL_CRYPT1_MASK_MASK)

#define AES_ACCEL_CRYPT1_CMODE_MASK              (0xF00U)
#define AES_ACCEL_CRYPT1_CMODE_SHIFT             (8U)
#define AES_ACCEL_CRYPT1_CMODE_WIDTH             (4U)
#define AES_ACCEL_CRYPT1_CMODE(x)                (((uint32_t)(((uint32_t)(x)) << AES_ACCEL_CRYPT1_CMODE_SHIFT)) & AES_ACCEL_CRYPT1_CMODE_MASK)

#define AES_ACCEL_CRYPT1_CO_MASK                 (0x3000U)
#define AES_ACCEL_CRYPT1_CO_SHIFT                (12U)
#define AES_ACCEL_CRYPT1_CO_WIDTH                (2U)
#define AES_ACCEL_CRYPT1_CO(x)                   (((uint32_t)(((uint32_t)(x)) << AES_ACCEL_CRYPT1_CO_SHIFT)) & AES_ACCEL_CRYPT1_CO_MASK)

#define AES_ACCEL_CRYPT1_KSLOT_MASK              (0xFF0000U)
#define AES_ACCEL_CRYPT1_KSLOT_SHIFT             (16U)
#define AES_ACCEL_CRYPT1_KSLOT_WIDTH             (8U)
#define AES_ACCEL_CRYPT1_KSLOT(x)                (((uint32_t)(((uint32_t)(x)) << AES_ACCEL_CRYPT1_KSLOT_SHIFT)) & AES_ACCEL_CRYPT1_KSLOT_MASK)
/*! @} */

/*! @name OWNSTAT1 - OWN_Status register */
/*! @{ */

#define AES_ACCEL_OWNSTAT1_DID_MASK              (0xFU)
#define AES_ACCEL_OWNSTAT1_DID_SHIFT             (0U)
#define AES_ACCEL_OWNSTAT1_DID_WIDTH             (4U)
#define AES_ACCEL_OWNSTAT1_DID(x)                (((uint32_t)(((uint32_t)(x)) << AES_ACCEL_OWNSTAT1_DID_SHIFT)) & AES_ACCEL_OWNSTAT1_DID_MASK)

#define AES_ACCEL_OWNSTAT1_NS_MASK               (0x40U)
#define AES_ACCEL_OWNSTAT1_NS_SHIFT              (6U)
#define AES_ACCEL_OWNSTAT1_NS_WIDTH              (1U)
#define AES_ACCEL_OWNSTAT1_NS(x)                 (((uint32_t)(((uint32_t)(x)) << AES_ACCEL_OWNSTAT1_NS_SHIFT)) & AES_ACCEL_OWNSTAT1_NS_MASK)

#define AES_ACCEL_OWNSTAT1_PRIV_MASK             (0x80U)
#define AES_ACCEL_OWNSTAT1_PRIV_SHIFT            (7U)
#define AES_ACCEL_OWNSTAT1_PRIV_WIDTH            (1U)
#define AES_ACCEL_OWNSTAT1_PRIV(x)               (((uint32_t)(((uint32_t)(x)) << AES_ACCEL_OWNSTAT1_PRIV_SHIFT)) & AES_ACCEL_OWNSTAT1_PRIV_MASK)
/*! @} */

/*! @name TLVAL1 - Timer Load Value Register */
/*! @{ */

#define AES_ACCEL_TLVAL1_TSV_MASK                (0xFFFFU)
#define AES_ACCEL_TLVAL1_TSV_SHIFT               (0U)
#define AES_ACCEL_TLVAL1_TSV_WIDTH               (16U)
#define AES_ACCEL_TLVAL1_TSV(x)                  (((uint32_t)(((uint32_t)(x)) << AES_ACCEL_TLVAL1_TSV_SHIFT)) & AES_ACCEL_TLVAL1_TSV_MASK)
/*! @} */

/*! @name CVAL1 - Current Timer Value Register */
/*! @{ */

#define AES_ACCEL_CVAL1_TVL_MASK                 (0xFFFFU)
#define AES_ACCEL_CVAL1_TVL_SHIFT                (0U)
#define AES_ACCEL_CVAL1_TVL_WIDTH                (16U)
#define AES_ACCEL_CVAL1_TVL(x)                   (((uint32_t)(((uint32_t)(x)) << AES_ACCEL_CVAL1_TVL_SHIFT)) & AES_ACCEL_CVAL1_TVL_MASK)
/*! @} */

/*! @name TCTRL1 - Timer Control Register */
/*! @{ */

#define AES_ACCEL_TCTRL1_TEN_MASK                (0x1U)
#define AES_ACCEL_TCTRL1_TEN_SHIFT               (0U)
#define AES_ACCEL_TCTRL1_TEN_WIDTH               (1U)
#define AES_ACCEL_TCTRL1_TEN(x)                  (((uint32_t)(((uint32_t)(x)) << AES_ACCEL_TCTRL1_TEN_SHIFT)) & AES_ACCEL_TCTRL1_TEN_MASK)

#define AES_ACCEL_TCTRL1_TIE_MASK                (0x2U)
#define AES_ACCEL_TCTRL1_TIE_SHIFT               (1U)
#define AES_ACCEL_TCTRL1_TIE_WIDTH               (1U)
#define AES_ACCEL_TCTRL1_TIE(x)                  (((uint32_t)(((uint32_t)(x)) << AES_ACCEL_TCTRL1_TIE_SHIFT)) & AES_ACCEL_TCTRL1_TIE_MASK)

#define AES_ACCEL_TCTRL1_FRZ_MASK                (0x4U)
#define AES_ACCEL_TCTRL1_FRZ_SHIFT               (2U)
#define AES_ACCEL_TCTRL1_FRZ_WIDTH               (1U)
#define AES_ACCEL_TCTRL1_FRZ(x)                  (((uint32_t)(((uint32_t)(x)) << AES_ACCEL_TCTRL1_FRZ_SHIFT)) & AES_ACCEL_TCTRL1_FRZ_MASK)
/*! @} */

/*! @name TFLG1 - Timer Flag Register */
/*! @{ */

#define AES_ACCEL_TFLG1_TIF_MASK                 (0x1U)
#define AES_ACCEL_TFLG1_TIF_SHIFT                (0U)
#define AES_ACCEL_TFLG1_TIF_WIDTH                (1U)
#define AES_ACCEL_TFLG1_TIF(x)                   (((uint32_t)(((uint32_t)(x)) << AES_ACCEL_TFLG1_TIF_SHIFT)) & AES_ACCEL_TFLG1_TIF_MASK)
/*! @} */

/*! @name FEEDINTMAP1 - FEEDINTMAP register */
/*! @{ */

#define AES_ACCEL_FEEDINTMAP1_FIEN1_MASK         (0x1U)
#define AES_ACCEL_FEEDINTMAP1_FIEN1_SHIFT        (0U)
#define AES_ACCEL_FEEDINTMAP1_FIEN1_WIDTH        (1U)
#define AES_ACCEL_FEEDINTMAP1_FIEN1(x)           (((uint32_t)(((uint32_t)(x)) << AES_ACCEL_FEEDINTMAP1_FIEN1_SHIFT)) & AES_ACCEL_FEEDINTMAP1_FIEN1_MASK)

#define AES_ACCEL_FEEDINTMAP1_FIEN9_MASK         (0x2U)
#define AES_ACCEL_FEEDINTMAP1_FIEN9_SHIFT        (1U)
#define AES_ACCEL_FEEDINTMAP1_FIEN9_WIDTH        (1U)
#define AES_ACCEL_FEEDINTMAP1_FIEN9(x)           (((uint32_t)(((uint32_t)(x)) << AES_ACCEL_FEEDINTMAP1_FIEN9_SHIFT)) & AES_ACCEL_FEEDINTMAP1_FIEN9_MASK)

#define AES_ACCEL_FEEDINTMAP1_FIEN17_MASK        (0x4U)
#define AES_ACCEL_FEEDINTMAP1_FIEN17_SHIFT       (2U)
#define AES_ACCEL_FEEDINTMAP1_FIEN17_WIDTH       (1U)
#define AES_ACCEL_FEEDINTMAP1_FIEN17(x)          (((uint32_t)(((uint32_t)(x)) << AES_ACCEL_FEEDINTMAP1_FIEN17_SHIFT)) & AES_ACCEL_FEEDINTMAP1_FIEN17_MASK)

#define AES_ACCEL_FEEDINTMAP1_FIEN25_MASK        (0x8U)
#define AES_ACCEL_FEEDINTMAP1_FIEN25_SHIFT       (3U)
#define AES_ACCEL_FEEDINTMAP1_FIEN25_WIDTH       (1U)
#define AES_ACCEL_FEEDINTMAP1_FIEN25(x)          (((uint32_t)(((uint32_t)(x)) << AES_ACCEL_FEEDINTMAP1_FIEN25_SHIFT)) & AES_ACCEL_FEEDINTMAP1_FIEN25_MASK)
/*! @} */

/*! @name RESULTINTMAP1 - RESULTINTMAP register */
/*! @{ */

#define AES_ACCEL_RESULTINTMAP1_RIEN1_MASK       (0x1U)
#define AES_ACCEL_RESULTINTMAP1_RIEN1_SHIFT      (0U)
#define AES_ACCEL_RESULTINTMAP1_RIEN1_WIDTH      (1U)
#define AES_ACCEL_RESULTINTMAP1_RIEN1(x)         (((uint32_t)(((uint32_t)(x)) << AES_ACCEL_RESULTINTMAP1_RIEN1_SHIFT)) & AES_ACCEL_RESULTINTMAP1_RIEN1_MASK)

#define AES_ACCEL_RESULTINTMAP1_RIEN9_MASK       (0x2U)
#define AES_ACCEL_RESULTINTMAP1_RIEN9_SHIFT      (1U)
#define AES_ACCEL_RESULTINTMAP1_RIEN9_WIDTH      (1U)
#define AES_ACCEL_RESULTINTMAP1_RIEN9(x)         (((uint32_t)(((uint32_t)(x)) << AES_ACCEL_RESULTINTMAP1_RIEN9_SHIFT)) & AES_ACCEL_RESULTINTMAP1_RIEN9_MASK)

#define AES_ACCEL_RESULTINTMAP1_RIEN17_MASK      (0x4U)
#define AES_ACCEL_RESULTINTMAP1_RIEN17_SHIFT     (2U)
#define AES_ACCEL_RESULTINTMAP1_RIEN17_WIDTH     (1U)
#define AES_ACCEL_RESULTINTMAP1_RIEN17(x)        (((uint32_t)(((uint32_t)(x)) << AES_ACCEL_RESULTINTMAP1_RIEN17_SHIFT)) & AES_ACCEL_RESULTINTMAP1_RIEN17_MASK)
/*! @} */

/*! @name LEN2 - LEN register */
/*! @{ */

#define AES_ACCEL_LEN2_TLEN_MASK                 (0x7FFFFU)
#define AES_ACCEL_LEN2_TLEN_SHIFT                (0U)
#define AES_ACCEL_LEN2_TLEN_WIDTH                (19U)
#define AES_ACCEL_LEN2_TLEN(x)                   (((uint32_t)(((uint32_t)(x)) << AES_ACCEL_LEN2_TLEN_SHIFT)) & AES_ACCEL_LEN2_TLEN_MASK)
/*! @} */

/*! @name AILEN2 - AAD/IV length register */
/*! @{ */

#define AES_ACCEL_AILEN2_AAD_MASK                (0x7FFFFU)
#define AES_ACCEL_AILEN2_AAD_SHIFT               (0U)
#define AES_ACCEL_AILEN2_AAD_WIDTH               (19U)
#define AES_ACCEL_AILEN2_AAD(x)                  (((uint32_t)(((uint32_t)(x)) << AES_ACCEL_AILEN2_AAD_SHIFT)) & AES_ACCEL_AILEN2_AAD_MASK)

#define AES_ACCEL_AILEN2_IVLEN_MASK              (0x7F000000U)
#define AES_ACCEL_AILEN2_IVLEN_SHIFT             (24U)
#define AES_ACCEL_AILEN2_IVLEN_WIDTH             (7U)
#define AES_ACCEL_AILEN2_IVLEN(x)                (((uint32_t)(((uint32_t)(x)) << AES_ACCEL_AILEN2_IVLEN_SHIFT)) & AES_ACCEL_AILEN2_IVLEN_MASK)
/*! @} */

/*! @name CRYPT2 - CRYPT register */
/*! @{ */

#define AES_ACCEL_CRYPT2_MASK_MASK               (0x7FU)
#define AES_ACCEL_CRYPT2_MASK_SHIFT              (0U)
#define AES_ACCEL_CRYPT2_MASK_WIDTH              (7U)
#define AES_ACCEL_CRYPT2_MASK(x)                 (((uint32_t)(((uint32_t)(x)) << AES_ACCEL_CRYPT2_MASK_SHIFT)) & AES_ACCEL_CRYPT2_MASK_MASK)

#define AES_ACCEL_CRYPT2_CMODE_MASK              (0xF00U)
#define AES_ACCEL_CRYPT2_CMODE_SHIFT             (8U)
#define AES_ACCEL_CRYPT2_CMODE_WIDTH             (4U)
#define AES_ACCEL_CRYPT2_CMODE(x)                (((uint32_t)(((uint32_t)(x)) << AES_ACCEL_CRYPT2_CMODE_SHIFT)) & AES_ACCEL_CRYPT2_CMODE_MASK)

#define AES_ACCEL_CRYPT2_CO_MASK                 (0x3000U)
#define AES_ACCEL_CRYPT2_CO_SHIFT                (12U)
#define AES_ACCEL_CRYPT2_CO_WIDTH                (2U)
#define AES_ACCEL_CRYPT2_CO(x)                   (((uint32_t)(((uint32_t)(x)) << AES_ACCEL_CRYPT2_CO_SHIFT)) & AES_ACCEL_CRYPT2_CO_MASK)

#define AES_ACCEL_CRYPT2_KSLOT_MASK              (0xFF0000U)
#define AES_ACCEL_CRYPT2_KSLOT_SHIFT             (16U)
#define AES_ACCEL_CRYPT2_KSLOT_WIDTH             (8U)
#define AES_ACCEL_CRYPT2_KSLOT(x)                (((uint32_t)(((uint32_t)(x)) << AES_ACCEL_CRYPT2_KSLOT_SHIFT)) & AES_ACCEL_CRYPT2_KSLOT_MASK)
/*! @} */

/*! @name OWNSTAT2 - OWN_Status register */
/*! @{ */

#define AES_ACCEL_OWNSTAT2_DID_MASK              (0xFU)
#define AES_ACCEL_OWNSTAT2_DID_SHIFT             (0U)
#define AES_ACCEL_OWNSTAT2_DID_WIDTH             (4U)
#define AES_ACCEL_OWNSTAT2_DID(x)                (((uint32_t)(((uint32_t)(x)) << AES_ACCEL_OWNSTAT2_DID_SHIFT)) & AES_ACCEL_OWNSTAT2_DID_MASK)

#define AES_ACCEL_OWNSTAT2_NS_MASK               (0x40U)
#define AES_ACCEL_OWNSTAT2_NS_SHIFT              (6U)
#define AES_ACCEL_OWNSTAT2_NS_WIDTH              (1U)
#define AES_ACCEL_OWNSTAT2_NS(x)                 (((uint32_t)(((uint32_t)(x)) << AES_ACCEL_OWNSTAT2_NS_SHIFT)) & AES_ACCEL_OWNSTAT2_NS_MASK)

#define AES_ACCEL_OWNSTAT2_PRIV_MASK             (0x80U)
#define AES_ACCEL_OWNSTAT2_PRIV_SHIFT            (7U)
#define AES_ACCEL_OWNSTAT2_PRIV_WIDTH            (1U)
#define AES_ACCEL_OWNSTAT2_PRIV(x)               (((uint32_t)(((uint32_t)(x)) << AES_ACCEL_OWNSTAT2_PRIV_SHIFT)) & AES_ACCEL_OWNSTAT2_PRIV_MASK)
/*! @} */

/*! @name TLVAL2 - Timer Load Value Register */
/*! @{ */

#define AES_ACCEL_TLVAL2_TSV_MASK                (0xFFFFU)
#define AES_ACCEL_TLVAL2_TSV_SHIFT               (0U)
#define AES_ACCEL_TLVAL2_TSV_WIDTH               (16U)
#define AES_ACCEL_TLVAL2_TSV(x)                  (((uint32_t)(((uint32_t)(x)) << AES_ACCEL_TLVAL2_TSV_SHIFT)) & AES_ACCEL_TLVAL2_TSV_MASK)
/*! @} */

/*! @name CVAL2 - Current Timer Value Register */
/*! @{ */

#define AES_ACCEL_CVAL2_TVL_MASK                 (0xFFFFU)
#define AES_ACCEL_CVAL2_TVL_SHIFT                (0U)
#define AES_ACCEL_CVAL2_TVL_WIDTH                (16U)
#define AES_ACCEL_CVAL2_TVL(x)                   (((uint32_t)(((uint32_t)(x)) << AES_ACCEL_CVAL2_TVL_SHIFT)) & AES_ACCEL_CVAL2_TVL_MASK)
/*! @} */

/*! @name TCTRL2 - Timer Control Register */
/*! @{ */

#define AES_ACCEL_TCTRL2_TEN_MASK                (0x1U)
#define AES_ACCEL_TCTRL2_TEN_SHIFT               (0U)
#define AES_ACCEL_TCTRL2_TEN_WIDTH               (1U)
#define AES_ACCEL_TCTRL2_TEN(x)                  (((uint32_t)(((uint32_t)(x)) << AES_ACCEL_TCTRL2_TEN_SHIFT)) & AES_ACCEL_TCTRL2_TEN_MASK)

#define AES_ACCEL_TCTRL2_TIE_MASK                (0x2U)
#define AES_ACCEL_TCTRL2_TIE_SHIFT               (1U)
#define AES_ACCEL_TCTRL2_TIE_WIDTH               (1U)
#define AES_ACCEL_TCTRL2_TIE(x)                  (((uint32_t)(((uint32_t)(x)) << AES_ACCEL_TCTRL2_TIE_SHIFT)) & AES_ACCEL_TCTRL2_TIE_MASK)

#define AES_ACCEL_TCTRL2_FRZ_MASK                (0x4U)
#define AES_ACCEL_TCTRL2_FRZ_SHIFT               (2U)
#define AES_ACCEL_TCTRL2_FRZ_WIDTH               (1U)
#define AES_ACCEL_TCTRL2_FRZ(x)                  (((uint32_t)(((uint32_t)(x)) << AES_ACCEL_TCTRL2_FRZ_SHIFT)) & AES_ACCEL_TCTRL2_FRZ_MASK)
/*! @} */

/*! @name TFLG2 - Timer Flag Register */
/*! @{ */

#define AES_ACCEL_TFLG2_TIF_MASK                 (0x1U)
#define AES_ACCEL_TFLG2_TIF_SHIFT                (0U)
#define AES_ACCEL_TFLG2_TIF_WIDTH                (1U)
#define AES_ACCEL_TFLG2_TIF(x)                   (((uint32_t)(((uint32_t)(x)) << AES_ACCEL_TFLG2_TIF_SHIFT)) & AES_ACCEL_TFLG2_TIF_MASK)
/*! @} */

/*! @name FEEDINTMAP2 - FEEDINTMAP register */
/*! @{ */

#define AES_ACCEL_FEEDINTMAP2_FIEN2_MASK         (0x1U)
#define AES_ACCEL_FEEDINTMAP2_FIEN2_SHIFT        (0U)
#define AES_ACCEL_FEEDINTMAP2_FIEN2_WIDTH        (1U)
#define AES_ACCEL_FEEDINTMAP2_FIEN2(x)           (((uint32_t)(((uint32_t)(x)) << AES_ACCEL_FEEDINTMAP2_FIEN2_SHIFT)) & AES_ACCEL_FEEDINTMAP2_FIEN2_MASK)

#define AES_ACCEL_FEEDINTMAP2_FIEN10_MASK        (0x2U)
#define AES_ACCEL_FEEDINTMAP2_FIEN10_SHIFT       (1U)
#define AES_ACCEL_FEEDINTMAP2_FIEN10_WIDTH       (1U)
#define AES_ACCEL_FEEDINTMAP2_FIEN10(x)          (((uint32_t)(((uint32_t)(x)) << AES_ACCEL_FEEDINTMAP2_FIEN10_SHIFT)) & AES_ACCEL_FEEDINTMAP2_FIEN10_MASK)

#define AES_ACCEL_FEEDINTMAP2_FIEN18_MASK        (0x4U)
#define AES_ACCEL_FEEDINTMAP2_FIEN18_SHIFT       (2U)
#define AES_ACCEL_FEEDINTMAP2_FIEN18_WIDTH       (1U)
#define AES_ACCEL_FEEDINTMAP2_FIEN18(x)          (((uint32_t)(((uint32_t)(x)) << AES_ACCEL_FEEDINTMAP2_FIEN18_SHIFT)) & AES_ACCEL_FEEDINTMAP2_FIEN18_MASK)

#define AES_ACCEL_FEEDINTMAP2_FIEN26_MASK        (0x8U)
#define AES_ACCEL_FEEDINTMAP2_FIEN26_SHIFT       (3U)
#define AES_ACCEL_FEEDINTMAP2_FIEN26_WIDTH       (1U)
#define AES_ACCEL_FEEDINTMAP2_FIEN26(x)          (((uint32_t)(((uint32_t)(x)) << AES_ACCEL_FEEDINTMAP2_FIEN26_SHIFT)) & AES_ACCEL_FEEDINTMAP2_FIEN26_MASK)
/*! @} */

/*! @name RESULTINTMAP2 - RESULTINTMAP register */
/*! @{ */

#define AES_ACCEL_RESULTINTMAP2_RIEN2_MASK       (0x1U)
#define AES_ACCEL_RESULTINTMAP2_RIEN2_SHIFT      (0U)
#define AES_ACCEL_RESULTINTMAP2_RIEN2_WIDTH      (1U)
#define AES_ACCEL_RESULTINTMAP2_RIEN2(x)         (((uint32_t)(((uint32_t)(x)) << AES_ACCEL_RESULTINTMAP2_RIEN2_SHIFT)) & AES_ACCEL_RESULTINTMAP2_RIEN2_MASK)

#define AES_ACCEL_RESULTINTMAP2_RIEN10_MASK      (0x2U)
#define AES_ACCEL_RESULTINTMAP2_RIEN10_SHIFT     (1U)
#define AES_ACCEL_RESULTINTMAP2_RIEN10_WIDTH     (1U)
#define AES_ACCEL_RESULTINTMAP2_RIEN10(x)        (((uint32_t)(((uint32_t)(x)) << AES_ACCEL_RESULTINTMAP2_RIEN10_SHIFT)) & AES_ACCEL_RESULTINTMAP2_RIEN10_MASK)

#define AES_ACCEL_RESULTINTMAP2_RIEN18_MASK      (0x4U)
#define AES_ACCEL_RESULTINTMAP2_RIEN18_SHIFT     (2U)
#define AES_ACCEL_RESULTINTMAP2_RIEN18_WIDTH     (1U)
#define AES_ACCEL_RESULTINTMAP2_RIEN18(x)        (((uint32_t)(((uint32_t)(x)) << AES_ACCEL_RESULTINTMAP2_RIEN18_SHIFT)) & AES_ACCEL_RESULTINTMAP2_RIEN18_MASK)
/*! @} */

/*! @name LEN3 - LEN register */
/*! @{ */

#define AES_ACCEL_LEN3_TLEN_MASK                 (0x7FFFFU)
#define AES_ACCEL_LEN3_TLEN_SHIFT                (0U)
#define AES_ACCEL_LEN3_TLEN_WIDTH                (19U)
#define AES_ACCEL_LEN3_TLEN(x)                   (((uint32_t)(((uint32_t)(x)) << AES_ACCEL_LEN3_TLEN_SHIFT)) & AES_ACCEL_LEN3_TLEN_MASK)
/*! @} */

/*! @name AILEN3 - AAD/IV length register */
/*! @{ */

#define AES_ACCEL_AILEN3_AAD_MASK                (0x7FFFFU)
#define AES_ACCEL_AILEN3_AAD_SHIFT               (0U)
#define AES_ACCEL_AILEN3_AAD_WIDTH               (19U)
#define AES_ACCEL_AILEN3_AAD(x)                  (((uint32_t)(((uint32_t)(x)) << AES_ACCEL_AILEN3_AAD_SHIFT)) & AES_ACCEL_AILEN3_AAD_MASK)

#define AES_ACCEL_AILEN3_IVLEN_MASK              (0x7F000000U)
#define AES_ACCEL_AILEN3_IVLEN_SHIFT             (24U)
#define AES_ACCEL_AILEN3_IVLEN_WIDTH             (7U)
#define AES_ACCEL_AILEN3_IVLEN(x)                (((uint32_t)(((uint32_t)(x)) << AES_ACCEL_AILEN3_IVLEN_SHIFT)) & AES_ACCEL_AILEN3_IVLEN_MASK)
/*! @} */

/*! @name CRYPT3 - CRYPT register */
/*! @{ */

#define AES_ACCEL_CRYPT3_MASK_MASK               (0x7FU)
#define AES_ACCEL_CRYPT3_MASK_SHIFT              (0U)
#define AES_ACCEL_CRYPT3_MASK_WIDTH              (7U)
#define AES_ACCEL_CRYPT3_MASK(x)                 (((uint32_t)(((uint32_t)(x)) << AES_ACCEL_CRYPT3_MASK_SHIFT)) & AES_ACCEL_CRYPT3_MASK_MASK)

#define AES_ACCEL_CRYPT3_CMODE_MASK              (0xF00U)
#define AES_ACCEL_CRYPT3_CMODE_SHIFT             (8U)
#define AES_ACCEL_CRYPT3_CMODE_WIDTH             (4U)
#define AES_ACCEL_CRYPT3_CMODE(x)                (((uint32_t)(((uint32_t)(x)) << AES_ACCEL_CRYPT3_CMODE_SHIFT)) & AES_ACCEL_CRYPT3_CMODE_MASK)

#define AES_ACCEL_CRYPT3_CO_MASK                 (0x3000U)
#define AES_ACCEL_CRYPT3_CO_SHIFT                (12U)
#define AES_ACCEL_CRYPT3_CO_WIDTH                (2U)
#define AES_ACCEL_CRYPT3_CO(x)                   (((uint32_t)(((uint32_t)(x)) << AES_ACCEL_CRYPT3_CO_SHIFT)) & AES_ACCEL_CRYPT3_CO_MASK)

#define AES_ACCEL_CRYPT3_KSLOT_MASK              (0xFF0000U)
#define AES_ACCEL_CRYPT3_KSLOT_SHIFT             (16U)
#define AES_ACCEL_CRYPT3_KSLOT_WIDTH             (8U)
#define AES_ACCEL_CRYPT3_KSLOT(x)                (((uint32_t)(((uint32_t)(x)) << AES_ACCEL_CRYPT3_KSLOT_SHIFT)) & AES_ACCEL_CRYPT3_KSLOT_MASK)
/*! @} */

/*! @name OWNSTAT3 - OWN_Status register */
/*! @{ */

#define AES_ACCEL_OWNSTAT3_DID_MASK              (0xFU)
#define AES_ACCEL_OWNSTAT3_DID_SHIFT             (0U)
#define AES_ACCEL_OWNSTAT3_DID_WIDTH             (4U)
#define AES_ACCEL_OWNSTAT3_DID(x)                (((uint32_t)(((uint32_t)(x)) << AES_ACCEL_OWNSTAT3_DID_SHIFT)) & AES_ACCEL_OWNSTAT3_DID_MASK)

#define AES_ACCEL_OWNSTAT3_NS_MASK               (0x40U)
#define AES_ACCEL_OWNSTAT3_NS_SHIFT              (6U)
#define AES_ACCEL_OWNSTAT3_NS_WIDTH              (1U)
#define AES_ACCEL_OWNSTAT3_NS(x)                 (((uint32_t)(((uint32_t)(x)) << AES_ACCEL_OWNSTAT3_NS_SHIFT)) & AES_ACCEL_OWNSTAT3_NS_MASK)

#define AES_ACCEL_OWNSTAT3_PRIV_MASK             (0x80U)
#define AES_ACCEL_OWNSTAT3_PRIV_SHIFT            (7U)
#define AES_ACCEL_OWNSTAT3_PRIV_WIDTH            (1U)
#define AES_ACCEL_OWNSTAT3_PRIV(x)               (((uint32_t)(((uint32_t)(x)) << AES_ACCEL_OWNSTAT3_PRIV_SHIFT)) & AES_ACCEL_OWNSTAT3_PRIV_MASK)
/*! @} */

/*! @name TLVAL3 - Timer Load Value Register */
/*! @{ */

#define AES_ACCEL_TLVAL3_TSV_MASK                (0xFFFFU)
#define AES_ACCEL_TLVAL3_TSV_SHIFT               (0U)
#define AES_ACCEL_TLVAL3_TSV_WIDTH               (16U)
#define AES_ACCEL_TLVAL3_TSV(x)                  (((uint32_t)(((uint32_t)(x)) << AES_ACCEL_TLVAL3_TSV_SHIFT)) & AES_ACCEL_TLVAL3_TSV_MASK)
/*! @} */

/*! @name CVAL3 - Current Timer Value Register */
/*! @{ */

#define AES_ACCEL_CVAL3_TVL_MASK                 (0xFFFFU)
#define AES_ACCEL_CVAL3_TVL_SHIFT                (0U)
#define AES_ACCEL_CVAL3_TVL_WIDTH                (16U)
#define AES_ACCEL_CVAL3_TVL(x)                   (((uint32_t)(((uint32_t)(x)) << AES_ACCEL_CVAL3_TVL_SHIFT)) & AES_ACCEL_CVAL3_TVL_MASK)
/*! @} */

/*! @name TCTRL3 - Timer Control Register */
/*! @{ */

#define AES_ACCEL_TCTRL3_TEN_MASK                (0x1U)
#define AES_ACCEL_TCTRL3_TEN_SHIFT               (0U)
#define AES_ACCEL_TCTRL3_TEN_WIDTH               (1U)
#define AES_ACCEL_TCTRL3_TEN(x)                  (((uint32_t)(((uint32_t)(x)) << AES_ACCEL_TCTRL3_TEN_SHIFT)) & AES_ACCEL_TCTRL3_TEN_MASK)

#define AES_ACCEL_TCTRL3_TIE_MASK                (0x2U)
#define AES_ACCEL_TCTRL3_TIE_SHIFT               (1U)
#define AES_ACCEL_TCTRL3_TIE_WIDTH               (1U)
#define AES_ACCEL_TCTRL3_TIE(x)                  (((uint32_t)(((uint32_t)(x)) << AES_ACCEL_TCTRL3_TIE_SHIFT)) & AES_ACCEL_TCTRL3_TIE_MASK)

#define AES_ACCEL_TCTRL3_FRZ_MASK                (0x4U)
#define AES_ACCEL_TCTRL3_FRZ_SHIFT               (2U)
#define AES_ACCEL_TCTRL3_FRZ_WIDTH               (1U)
#define AES_ACCEL_TCTRL3_FRZ(x)                  (((uint32_t)(((uint32_t)(x)) << AES_ACCEL_TCTRL3_FRZ_SHIFT)) & AES_ACCEL_TCTRL3_FRZ_MASK)
/*! @} */

/*! @name TFLG3 - Timer Flag Register */
/*! @{ */

#define AES_ACCEL_TFLG3_TIF_MASK                 (0x1U)
#define AES_ACCEL_TFLG3_TIF_SHIFT                (0U)
#define AES_ACCEL_TFLG3_TIF_WIDTH                (1U)
#define AES_ACCEL_TFLG3_TIF(x)                   (((uint32_t)(((uint32_t)(x)) << AES_ACCEL_TFLG3_TIF_SHIFT)) & AES_ACCEL_TFLG3_TIF_MASK)
/*! @} */

/*! @name FEEDINTMAP3 - FEEDINTMAP register */
/*! @{ */

#define AES_ACCEL_FEEDINTMAP3_FIEN3_MASK         (0x1U)
#define AES_ACCEL_FEEDINTMAP3_FIEN3_SHIFT        (0U)
#define AES_ACCEL_FEEDINTMAP3_FIEN3_WIDTH        (1U)
#define AES_ACCEL_FEEDINTMAP3_FIEN3(x)           (((uint32_t)(((uint32_t)(x)) << AES_ACCEL_FEEDINTMAP3_FIEN3_SHIFT)) & AES_ACCEL_FEEDINTMAP3_FIEN3_MASK)

#define AES_ACCEL_FEEDINTMAP3_FIEN11_MASK        (0x2U)
#define AES_ACCEL_FEEDINTMAP3_FIEN11_SHIFT       (1U)
#define AES_ACCEL_FEEDINTMAP3_FIEN11_WIDTH       (1U)
#define AES_ACCEL_FEEDINTMAP3_FIEN11(x)          (((uint32_t)(((uint32_t)(x)) << AES_ACCEL_FEEDINTMAP3_FIEN11_SHIFT)) & AES_ACCEL_FEEDINTMAP3_FIEN11_MASK)

#define AES_ACCEL_FEEDINTMAP3_FIEN19_MASK        (0x4U)
#define AES_ACCEL_FEEDINTMAP3_FIEN19_SHIFT       (2U)
#define AES_ACCEL_FEEDINTMAP3_FIEN19_WIDTH       (1U)
#define AES_ACCEL_FEEDINTMAP3_FIEN19(x)          (((uint32_t)(((uint32_t)(x)) << AES_ACCEL_FEEDINTMAP3_FIEN19_SHIFT)) & AES_ACCEL_FEEDINTMAP3_FIEN19_MASK)

#define AES_ACCEL_FEEDINTMAP3_FIEN27_MASK        (0x8U)
#define AES_ACCEL_FEEDINTMAP3_FIEN27_SHIFT       (3U)
#define AES_ACCEL_FEEDINTMAP3_FIEN27_WIDTH       (1U)
#define AES_ACCEL_FEEDINTMAP3_FIEN27(x)          (((uint32_t)(((uint32_t)(x)) << AES_ACCEL_FEEDINTMAP3_FIEN27_SHIFT)) & AES_ACCEL_FEEDINTMAP3_FIEN27_MASK)
/*! @} */

/*! @name RESULTINTMAP3 - RESULTINTMAP register */
/*! @{ */

#define AES_ACCEL_RESULTINTMAP3_RIEN3_MASK       (0x1U)
#define AES_ACCEL_RESULTINTMAP3_RIEN3_SHIFT      (0U)
#define AES_ACCEL_RESULTINTMAP3_RIEN3_WIDTH      (1U)
#define AES_ACCEL_RESULTINTMAP3_RIEN3(x)         (((uint32_t)(((uint32_t)(x)) << AES_ACCEL_RESULTINTMAP3_RIEN3_SHIFT)) & AES_ACCEL_RESULTINTMAP3_RIEN3_MASK)

#define AES_ACCEL_RESULTINTMAP3_RIEN11_MASK      (0x2U)
#define AES_ACCEL_RESULTINTMAP3_RIEN11_SHIFT     (1U)
#define AES_ACCEL_RESULTINTMAP3_RIEN11_WIDTH     (1U)
#define AES_ACCEL_RESULTINTMAP3_RIEN11(x)        (((uint32_t)(((uint32_t)(x)) << AES_ACCEL_RESULTINTMAP3_RIEN11_SHIFT)) & AES_ACCEL_RESULTINTMAP3_RIEN11_MASK)

#define AES_ACCEL_RESULTINTMAP3_RIEN19_MASK      (0x4U)
#define AES_ACCEL_RESULTINTMAP3_RIEN19_SHIFT     (2U)
#define AES_ACCEL_RESULTINTMAP3_RIEN19_WIDTH     (1U)
#define AES_ACCEL_RESULTINTMAP3_RIEN19(x)        (((uint32_t)(((uint32_t)(x)) << AES_ACCEL_RESULTINTMAP3_RIEN19_SHIFT)) & AES_ACCEL_RESULTINTMAP3_RIEN19_MASK)
/*! @} */

/*! @name LEN4 - LEN register */
/*! @{ */

#define AES_ACCEL_LEN4_TLEN_MASK                 (0x7FFFFU)
#define AES_ACCEL_LEN4_TLEN_SHIFT                (0U)
#define AES_ACCEL_LEN4_TLEN_WIDTH                (19U)
#define AES_ACCEL_LEN4_TLEN(x)                   (((uint32_t)(((uint32_t)(x)) << AES_ACCEL_LEN4_TLEN_SHIFT)) & AES_ACCEL_LEN4_TLEN_MASK)
/*! @} */

/*! @name AILEN4 - AAD/IV length register */
/*! @{ */

#define AES_ACCEL_AILEN4_AAD_MASK                (0x7FFFFU)
#define AES_ACCEL_AILEN4_AAD_SHIFT               (0U)
#define AES_ACCEL_AILEN4_AAD_WIDTH               (19U)
#define AES_ACCEL_AILEN4_AAD(x)                  (((uint32_t)(((uint32_t)(x)) << AES_ACCEL_AILEN4_AAD_SHIFT)) & AES_ACCEL_AILEN4_AAD_MASK)

#define AES_ACCEL_AILEN4_IVLEN_MASK              (0x7F000000U)
#define AES_ACCEL_AILEN4_IVLEN_SHIFT             (24U)
#define AES_ACCEL_AILEN4_IVLEN_WIDTH             (7U)
#define AES_ACCEL_AILEN4_IVLEN(x)                (((uint32_t)(((uint32_t)(x)) << AES_ACCEL_AILEN4_IVLEN_SHIFT)) & AES_ACCEL_AILEN4_IVLEN_MASK)
/*! @} */

/*! @name CRYPT4 - CRYPT register */
/*! @{ */

#define AES_ACCEL_CRYPT4_MASK_MASK               (0x7FU)
#define AES_ACCEL_CRYPT4_MASK_SHIFT              (0U)
#define AES_ACCEL_CRYPT4_MASK_WIDTH              (7U)
#define AES_ACCEL_CRYPT4_MASK(x)                 (((uint32_t)(((uint32_t)(x)) << AES_ACCEL_CRYPT4_MASK_SHIFT)) & AES_ACCEL_CRYPT4_MASK_MASK)

#define AES_ACCEL_CRYPT4_CMODE_MASK              (0xF00U)
#define AES_ACCEL_CRYPT4_CMODE_SHIFT             (8U)
#define AES_ACCEL_CRYPT4_CMODE_WIDTH             (4U)
#define AES_ACCEL_CRYPT4_CMODE(x)                (((uint32_t)(((uint32_t)(x)) << AES_ACCEL_CRYPT4_CMODE_SHIFT)) & AES_ACCEL_CRYPT4_CMODE_MASK)

#define AES_ACCEL_CRYPT4_CO_MASK                 (0x3000U)
#define AES_ACCEL_CRYPT4_CO_SHIFT                (12U)
#define AES_ACCEL_CRYPT4_CO_WIDTH                (2U)
#define AES_ACCEL_CRYPT4_CO(x)                   (((uint32_t)(((uint32_t)(x)) << AES_ACCEL_CRYPT4_CO_SHIFT)) & AES_ACCEL_CRYPT4_CO_MASK)

#define AES_ACCEL_CRYPT4_KSLOT_MASK              (0xFF0000U)
#define AES_ACCEL_CRYPT4_KSLOT_SHIFT             (16U)
#define AES_ACCEL_CRYPT4_KSLOT_WIDTH             (8U)
#define AES_ACCEL_CRYPT4_KSLOT(x)                (((uint32_t)(((uint32_t)(x)) << AES_ACCEL_CRYPT4_KSLOT_SHIFT)) & AES_ACCEL_CRYPT4_KSLOT_MASK)
/*! @} */

/*! @name OWNSTAT4 - OWN_Status register */
/*! @{ */

#define AES_ACCEL_OWNSTAT4_DID_MASK              (0xFU)
#define AES_ACCEL_OWNSTAT4_DID_SHIFT             (0U)
#define AES_ACCEL_OWNSTAT4_DID_WIDTH             (4U)
#define AES_ACCEL_OWNSTAT4_DID(x)                (((uint32_t)(((uint32_t)(x)) << AES_ACCEL_OWNSTAT4_DID_SHIFT)) & AES_ACCEL_OWNSTAT4_DID_MASK)

#define AES_ACCEL_OWNSTAT4_NS_MASK               (0x40U)
#define AES_ACCEL_OWNSTAT4_NS_SHIFT              (6U)
#define AES_ACCEL_OWNSTAT4_NS_WIDTH              (1U)
#define AES_ACCEL_OWNSTAT4_NS(x)                 (((uint32_t)(((uint32_t)(x)) << AES_ACCEL_OWNSTAT4_NS_SHIFT)) & AES_ACCEL_OWNSTAT4_NS_MASK)

#define AES_ACCEL_OWNSTAT4_PRIV_MASK             (0x80U)
#define AES_ACCEL_OWNSTAT4_PRIV_SHIFT            (7U)
#define AES_ACCEL_OWNSTAT4_PRIV_WIDTH            (1U)
#define AES_ACCEL_OWNSTAT4_PRIV(x)               (((uint32_t)(((uint32_t)(x)) << AES_ACCEL_OWNSTAT4_PRIV_SHIFT)) & AES_ACCEL_OWNSTAT4_PRIV_MASK)
/*! @} */

/*! @name TLVAL4 - Timer Load Value Register */
/*! @{ */

#define AES_ACCEL_TLVAL4_TSV_MASK                (0xFFFFU)
#define AES_ACCEL_TLVAL4_TSV_SHIFT               (0U)
#define AES_ACCEL_TLVAL4_TSV_WIDTH               (16U)
#define AES_ACCEL_TLVAL4_TSV(x)                  (((uint32_t)(((uint32_t)(x)) << AES_ACCEL_TLVAL4_TSV_SHIFT)) & AES_ACCEL_TLVAL4_TSV_MASK)
/*! @} */

/*! @name CVAL4 - Current Timer Value Register */
/*! @{ */

#define AES_ACCEL_CVAL4_TVL_MASK                 (0xFFFFU)
#define AES_ACCEL_CVAL4_TVL_SHIFT                (0U)
#define AES_ACCEL_CVAL4_TVL_WIDTH                (16U)
#define AES_ACCEL_CVAL4_TVL(x)                   (((uint32_t)(((uint32_t)(x)) << AES_ACCEL_CVAL4_TVL_SHIFT)) & AES_ACCEL_CVAL4_TVL_MASK)
/*! @} */

/*! @name TCTRL4 - Timer Control Register */
/*! @{ */

#define AES_ACCEL_TCTRL4_TEN_MASK                (0x1U)
#define AES_ACCEL_TCTRL4_TEN_SHIFT               (0U)
#define AES_ACCEL_TCTRL4_TEN_WIDTH               (1U)
#define AES_ACCEL_TCTRL4_TEN(x)                  (((uint32_t)(((uint32_t)(x)) << AES_ACCEL_TCTRL4_TEN_SHIFT)) & AES_ACCEL_TCTRL4_TEN_MASK)

#define AES_ACCEL_TCTRL4_TIE_MASK                (0x2U)
#define AES_ACCEL_TCTRL4_TIE_SHIFT               (1U)
#define AES_ACCEL_TCTRL4_TIE_WIDTH               (1U)
#define AES_ACCEL_TCTRL4_TIE(x)                  (((uint32_t)(((uint32_t)(x)) << AES_ACCEL_TCTRL4_TIE_SHIFT)) & AES_ACCEL_TCTRL4_TIE_MASK)

#define AES_ACCEL_TCTRL4_FRZ_MASK                (0x4U)
#define AES_ACCEL_TCTRL4_FRZ_SHIFT               (2U)
#define AES_ACCEL_TCTRL4_FRZ_WIDTH               (1U)
#define AES_ACCEL_TCTRL4_FRZ(x)                  (((uint32_t)(((uint32_t)(x)) << AES_ACCEL_TCTRL4_FRZ_SHIFT)) & AES_ACCEL_TCTRL4_FRZ_MASK)
/*! @} */

/*! @name TFLG4 - Timer Flag Register */
/*! @{ */

#define AES_ACCEL_TFLG4_TIF_MASK                 (0x1U)
#define AES_ACCEL_TFLG4_TIF_SHIFT                (0U)
#define AES_ACCEL_TFLG4_TIF_WIDTH                (1U)
#define AES_ACCEL_TFLG4_TIF(x)                   (((uint32_t)(((uint32_t)(x)) << AES_ACCEL_TFLG4_TIF_SHIFT)) & AES_ACCEL_TFLG4_TIF_MASK)
/*! @} */

/*! @name FEEDINTMAP4 - FEEDINTMAP register */
/*! @{ */

#define AES_ACCEL_FEEDINTMAP4_FIEN4_MASK         (0x1U)
#define AES_ACCEL_FEEDINTMAP4_FIEN4_SHIFT        (0U)
#define AES_ACCEL_FEEDINTMAP4_FIEN4_WIDTH        (1U)
#define AES_ACCEL_FEEDINTMAP4_FIEN4(x)           (((uint32_t)(((uint32_t)(x)) << AES_ACCEL_FEEDINTMAP4_FIEN4_SHIFT)) & AES_ACCEL_FEEDINTMAP4_FIEN4_MASK)

#define AES_ACCEL_FEEDINTMAP4_FIEN12_MASK        (0x2U)
#define AES_ACCEL_FEEDINTMAP4_FIEN12_SHIFT       (1U)
#define AES_ACCEL_FEEDINTMAP4_FIEN12_WIDTH       (1U)
#define AES_ACCEL_FEEDINTMAP4_FIEN12(x)          (((uint32_t)(((uint32_t)(x)) << AES_ACCEL_FEEDINTMAP4_FIEN12_SHIFT)) & AES_ACCEL_FEEDINTMAP4_FIEN12_MASK)

#define AES_ACCEL_FEEDINTMAP4_FIEN20_MASK        (0x4U)
#define AES_ACCEL_FEEDINTMAP4_FIEN20_SHIFT       (2U)
#define AES_ACCEL_FEEDINTMAP4_FIEN20_WIDTH       (1U)
#define AES_ACCEL_FEEDINTMAP4_FIEN20(x)          (((uint32_t)(((uint32_t)(x)) << AES_ACCEL_FEEDINTMAP4_FIEN20_SHIFT)) & AES_ACCEL_FEEDINTMAP4_FIEN20_MASK)

#define AES_ACCEL_FEEDINTMAP4_FIEN28_MASK        (0x8U)
#define AES_ACCEL_FEEDINTMAP4_FIEN28_SHIFT       (3U)
#define AES_ACCEL_FEEDINTMAP4_FIEN28_WIDTH       (1U)
#define AES_ACCEL_FEEDINTMAP4_FIEN28(x)          (((uint32_t)(((uint32_t)(x)) << AES_ACCEL_FEEDINTMAP4_FIEN28_SHIFT)) & AES_ACCEL_FEEDINTMAP4_FIEN28_MASK)
/*! @} */

/*! @name RESULTINTMAP4 - RESULTINTMAP register */
/*! @{ */

#define AES_ACCEL_RESULTINTMAP4_RIEN4_MASK       (0x1U)
#define AES_ACCEL_RESULTINTMAP4_RIEN4_SHIFT      (0U)
#define AES_ACCEL_RESULTINTMAP4_RIEN4_WIDTH      (1U)
#define AES_ACCEL_RESULTINTMAP4_RIEN4(x)         (((uint32_t)(((uint32_t)(x)) << AES_ACCEL_RESULTINTMAP4_RIEN4_SHIFT)) & AES_ACCEL_RESULTINTMAP4_RIEN4_MASK)

#define AES_ACCEL_RESULTINTMAP4_RIEN12_MASK      (0x2U)
#define AES_ACCEL_RESULTINTMAP4_RIEN12_SHIFT     (1U)
#define AES_ACCEL_RESULTINTMAP4_RIEN12_WIDTH     (1U)
#define AES_ACCEL_RESULTINTMAP4_RIEN12(x)        (((uint32_t)(((uint32_t)(x)) << AES_ACCEL_RESULTINTMAP4_RIEN12_SHIFT)) & AES_ACCEL_RESULTINTMAP4_RIEN12_MASK)

#define AES_ACCEL_RESULTINTMAP4_RIEN20_MASK      (0x4U)
#define AES_ACCEL_RESULTINTMAP4_RIEN20_SHIFT     (2U)
#define AES_ACCEL_RESULTINTMAP4_RIEN20_WIDTH     (1U)
#define AES_ACCEL_RESULTINTMAP4_RIEN20(x)        (((uint32_t)(((uint32_t)(x)) << AES_ACCEL_RESULTINTMAP4_RIEN20_SHIFT)) & AES_ACCEL_RESULTINTMAP4_RIEN20_MASK)
/*! @} */

/*! @name LEN5 - LEN register */
/*! @{ */

#define AES_ACCEL_LEN5_TLEN_MASK                 (0x7FFFFU)
#define AES_ACCEL_LEN5_TLEN_SHIFT                (0U)
#define AES_ACCEL_LEN5_TLEN_WIDTH                (19U)
#define AES_ACCEL_LEN5_TLEN(x)                   (((uint32_t)(((uint32_t)(x)) << AES_ACCEL_LEN5_TLEN_SHIFT)) & AES_ACCEL_LEN5_TLEN_MASK)
/*! @} */

/*! @name AILEN5 - AAD/IV length register */
/*! @{ */

#define AES_ACCEL_AILEN5_AAD_MASK                (0x7FFFFU)
#define AES_ACCEL_AILEN5_AAD_SHIFT               (0U)
#define AES_ACCEL_AILEN5_AAD_WIDTH               (19U)
#define AES_ACCEL_AILEN5_AAD(x)                  (((uint32_t)(((uint32_t)(x)) << AES_ACCEL_AILEN5_AAD_SHIFT)) & AES_ACCEL_AILEN5_AAD_MASK)

#define AES_ACCEL_AILEN5_IVLEN_MASK              (0x7F000000U)
#define AES_ACCEL_AILEN5_IVLEN_SHIFT             (24U)
#define AES_ACCEL_AILEN5_IVLEN_WIDTH             (7U)
#define AES_ACCEL_AILEN5_IVLEN(x)                (((uint32_t)(((uint32_t)(x)) << AES_ACCEL_AILEN5_IVLEN_SHIFT)) & AES_ACCEL_AILEN5_IVLEN_MASK)
/*! @} */

/*! @name CRYPT5 - CRYPT register */
/*! @{ */

#define AES_ACCEL_CRYPT5_MASK_MASK               (0x7FU)
#define AES_ACCEL_CRYPT5_MASK_SHIFT              (0U)
#define AES_ACCEL_CRYPT5_MASK_WIDTH              (7U)
#define AES_ACCEL_CRYPT5_MASK(x)                 (((uint32_t)(((uint32_t)(x)) << AES_ACCEL_CRYPT5_MASK_SHIFT)) & AES_ACCEL_CRYPT5_MASK_MASK)

#define AES_ACCEL_CRYPT5_CMODE_MASK              (0xF00U)
#define AES_ACCEL_CRYPT5_CMODE_SHIFT             (8U)
#define AES_ACCEL_CRYPT5_CMODE_WIDTH             (4U)
#define AES_ACCEL_CRYPT5_CMODE(x)                (((uint32_t)(((uint32_t)(x)) << AES_ACCEL_CRYPT5_CMODE_SHIFT)) & AES_ACCEL_CRYPT5_CMODE_MASK)

#define AES_ACCEL_CRYPT5_CO_MASK                 (0x3000U)
#define AES_ACCEL_CRYPT5_CO_SHIFT                (12U)
#define AES_ACCEL_CRYPT5_CO_WIDTH                (2U)
#define AES_ACCEL_CRYPT5_CO(x)                   (((uint32_t)(((uint32_t)(x)) << AES_ACCEL_CRYPT5_CO_SHIFT)) & AES_ACCEL_CRYPT5_CO_MASK)

#define AES_ACCEL_CRYPT5_KSLOT_MASK              (0xFF0000U)
#define AES_ACCEL_CRYPT5_KSLOT_SHIFT             (16U)
#define AES_ACCEL_CRYPT5_KSLOT_WIDTH             (8U)
#define AES_ACCEL_CRYPT5_KSLOT(x)                (((uint32_t)(((uint32_t)(x)) << AES_ACCEL_CRYPT5_KSLOT_SHIFT)) & AES_ACCEL_CRYPT5_KSLOT_MASK)
/*! @} */

/*! @name OWNSTAT5 - OWN_Status register */
/*! @{ */

#define AES_ACCEL_OWNSTAT5_DID_MASK              (0xFU)
#define AES_ACCEL_OWNSTAT5_DID_SHIFT             (0U)
#define AES_ACCEL_OWNSTAT5_DID_WIDTH             (4U)
#define AES_ACCEL_OWNSTAT5_DID(x)                (((uint32_t)(((uint32_t)(x)) << AES_ACCEL_OWNSTAT5_DID_SHIFT)) & AES_ACCEL_OWNSTAT5_DID_MASK)

#define AES_ACCEL_OWNSTAT5_NS_MASK               (0x40U)
#define AES_ACCEL_OWNSTAT5_NS_SHIFT              (6U)
#define AES_ACCEL_OWNSTAT5_NS_WIDTH              (1U)
#define AES_ACCEL_OWNSTAT5_NS(x)                 (((uint32_t)(((uint32_t)(x)) << AES_ACCEL_OWNSTAT5_NS_SHIFT)) & AES_ACCEL_OWNSTAT5_NS_MASK)

#define AES_ACCEL_OWNSTAT5_PRIV_MASK             (0x80U)
#define AES_ACCEL_OWNSTAT5_PRIV_SHIFT            (7U)
#define AES_ACCEL_OWNSTAT5_PRIV_WIDTH            (1U)
#define AES_ACCEL_OWNSTAT5_PRIV(x)               (((uint32_t)(((uint32_t)(x)) << AES_ACCEL_OWNSTAT5_PRIV_SHIFT)) & AES_ACCEL_OWNSTAT5_PRIV_MASK)
/*! @} */

/*! @name TLVAL5 - Timer Load Value Register */
/*! @{ */

#define AES_ACCEL_TLVAL5_TSV_MASK                (0xFFFFU)
#define AES_ACCEL_TLVAL5_TSV_SHIFT               (0U)
#define AES_ACCEL_TLVAL5_TSV_WIDTH               (16U)
#define AES_ACCEL_TLVAL5_TSV(x)                  (((uint32_t)(((uint32_t)(x)) << AES_ACCEL_TLVAL5_TSV_SHIFT)) & AES_ACCEL_TLVAL5_TSV_MASK)
/*! @} */

/*! @name CVAL5 - Current Timer Value Register */
/*! @{ */

#define AES_ACCEL_CVAL5_TVL_MASK                 (0xFFFFU)
#define AES_ACCEL_CVAL5_TVL_SHIFT                (0U)
#define AES_ACCEL_CVAL5_TVL_WIDTH                (16U)
#define AES_ACCEL_CVAL5_TVL(x)                   (((uint32_t)(((uint32_t)(x)) << AES_ACCEL_CVAL5_TVL_SHIFT)) & AES_ACCEL_CVAL5_TVL_MASK)
/*! @} */

/*! @name TCTRL5 - Timer Control Register */
/*! @{ */

#define AES_ACCEL_TCTRL5_TEN_MASK                (0x1U)
#define AES_ACCEL_TCTRL5_TEN_SHIFT               (0U)
#define AES_ACCEL_TCTRL5_TEN_WIDTH               (1U)
#define AES_ACCEL_TCTRL5_TEN(x)                  (((uint32_t)(((uint32_t)(x)) << AES_ACCEL_TCTRL5_TEN_SHIFT)) & AES_ACCEL_TCTRL5_TEN_MASK)

#define AES_ACCEL_TCTRL5_TIE_MASK                (0x2U)
#define AES_ACCEL_TCTRL5_TIE_SHIFT               (1U)
#define AES_ACCEL_TCTRL5_TIE_WIDTH               (1U)
#define AES_ACCEL_TCTRL5_TIE(x)                  (((uint32_t)(((uint32_t)(x)) << AES_ACCEL_TCTRL5_TIE_SHIFT)) & AES_ACCEL_TCTRL5_TIE_MASK)

#define AES_ACCEL_TCTRL5_FRZ_MASK                (0x4U)
#define AES_ACCEL_TCTRL5_FRZ_SHIFT               (2U)
#define AES_ACCEL_TCTRL5_FRZ_WIDTH               (1U)
#define AES_ACCEL_TCTRL5_FRZ(x)                  (((uint32_t)(((uint32_t)(x)) << AES_ACCEL_TCTRL5_FRZ_SHIFT)) & AES_ACCEL_TCTRL5_FRZ_MASK)
/*! @} */

/*! @name TFLG5 - Timer Flag Register */
/*! @{ */

#define AES_ACCEL_TFLG5_TIF_MASK                 (0x1U)
#define AES_ACCEL_TFLG5_TIF_SHIFT                (0U)
#define AES_ACCEL_TFLG5_TIF_WIDTH                (1U)
#define AES_ACCEL_TFLG5_TIF(x)                   (((uint32_t)(((uint32_t)(x)) << AES_ACCEL_TFLG5_TIF_SHIFT)) & AES_ACCEL_TFLG5_TIF_MASK)
/*! @} */

/*! @name FEEDINTMAP5 - FEEDINTMAP register */
/*! @{ */

#define AES_ACCEL_FEEDINTMAP5_FIEN5_MASK         (0x1U)
#define AES_ACCEL_FEEDINTMAP5_FIEN5_SHIFT        (0U)
#define AES_ACCEL_FEEDINTMAP5_FIEN5_WIDTH        (1U)
#define AES_ACCEL_FEEDINTMAP5_FIEN5(x)           (((uint32_t)(((uint32_t)(x)) << AES_ACCEL_FEEDINTMAP5_FIEN5_SHIFT)) & AES_ACCEL_FEEDINTMAP5_FIEN5_MASK)

#define AES_ACCEL_FEEDINTMAP5_FIEN13_MASK        (0x2U)
#define AES_ACCEL_FEEDINTMAP5_FIEN13_SHIFT       (1U)
#define AES_ACCEL_FEEDINTMAP5_FIEN13_WIDTH       (1U)
#define AES_ACCEL_FEEDINTMAP5_FIEN13(x)          (((uint32_t)(((uint32_t)(x)) << AES_ACCEL_FEEDINTMAP5_FIEN13_SHIFT)) & AES_ACCEL_FEEDINTMAP5_FIEN13_MASK)

#define AES_ACCEL_FEEDINTMAP5_FIEN21_MASK        (0x4U)
#define AES_ACCEL_FEEDINTMAP5_FIEN21_SHIFT       (2U)
#define AES_ACCEL_FEEDINTMAP5_FIEN21_WIDTH       (1U)
#define AES_ACCEL_FEEDINTMAP5_FIEN21(x)          (((uint32_t)(((uint32_t)(x)) << AES_ACCEL_FEEDINTMAP5_FIEN21_SHIFT)) & AES_ACCEL_FEEDINTMAP5_FIEN21_MASK)

#define AES_ACCEL_FEEDINTMAP5_FIEN29_MASK        (0x8U)
#define AES_ACCEL_FEEDINTMAP5_FIEN29_SHIFT       (3U)
#define AES_ACCEL_FEEDINTMAP5_FIEN29_WIDTH       (1U)
#define AES_ACCEL_FEEDINTMAP5_FIEN29(x)          (((uint32_t)(((uint32_t)(x)) << AES_ACCEL_FEEDINTMAP5_FIEN29_SHIFT)) & AES_ACCEL_FEEDINTMAP5_FIEN29_MASK)
/*! @} */

/*! @name RESULTINTMAP5 - RESULTINTMAP register */
/*! @{ */

#define AES_ACCEL_RESULTINTMAP5_RIEN5_MASK       (0x1U)
#define AES_ACCEL_RESULTINTMAP5_RIEN5_SHIFT      (0U)
#define AES_ACCEL_RESULTINTMAP5_RIEN5_WIDTH      (1U)
#define AES_ACCEL_RESULTINTMAP5_RIEN5(x)         (((uint32_t)(((uint32_t)(x)) << AES_ACCEL_RESULTINTMAP5_RIEN5_SHIFT)) & AES_ACCEL_RESULTINTMAP5_RIEN5_MASK)

#define AES_ACCEL_RESULTINTMAP5_RIEN13_MASK      (0x2U)
#define AES_ACCEL_RESULTINTMAP5_RIEN13_SHIFT     (1U)
#define AES_ACCEL_RESULTINTMAP5_RIEN13_WIDTH     (1U)
#define AES_ACCEL_RESULTINTMAP5_RIEN13(x)        (((uint32_t)(((uint32_t)(x)) << AES_ACCEL_RESULTINTMAP5_RIEN13_SHIFT)) & AES_ACCEL_RESULTINTMAP5_RIEN13_MASK)

#define AES_ACCEL_RESULTINTMAP5_RIEN21_MASK      (0x4U)
#define AES_ACCEL_RESULTINTMAP5_RIEN21_SHIFT     (2U)
#define AES_ACCEL_RESULTINTMAP5_RIEN21_WIDTH     (1U)
#define AES_ACCEL_RESULTINTMAP5_RIEN21(x)        (((uint32_t)(((uint32_t)(x)) << AES_ACCEL_RESULTINTMAP5_RIEN21_SHIFT)) & AES_ACCEL_RESULTINTMAP5_RIEN21_MASK)
/*! @} */

/*! @name LEN6 - LEN register */
/*! @{ */

#define AES_ACCEL_LEN6_TLEN_MASK                 (0x7FFFFU)
#define AES_ACCEL_LEN6_TLEN_SHIFT                (0U)
#define AES_ACCEL_LEN6_TLEN_WIDTH                (19U)
#define AES_ACCEL_LEN6_TLEN(x)                   (((uint32_t)(((uint32_t)(x)) << AES_ACCEL_LEN6_TLEN_SHIFT)) & AES_ACCEL_LEN6_TLEN_MASK)
/*! @} */

/*! @name AILEN6 - AAD/IV length register */
/*! @{ */

#define AES_ACCEL_AILEN6_AAD_MASK                (0x7FFFFU)
#define AES_ACCEL_AILEN6_AAD_SHIFT               (0U)
#define AES_ACCEL_AILEN6_AAD_WIDTH               (19U)
#define AES_ACCEL_AILEN6_AAD(x)                  (((uint32_t)(((uint32_t)(x)) << AES_ACCEL_AILEN6_AAD_SHIFT)) & AES_ACCEL_AILEN6_AAD_MASK)

#define AES_ACCEL_AILEN6_IVLEN_MASK              (0x7F000000U)
#define AES_ACCEL_AILEN6_IVLEN_SHIFT             (24U)
#define AES_ACCEL_AILEN6_IVLEN_WIDTH             (7U)
#define AES_ACCEL_AILEN6_IVLEN(x)                (((uint32_t)(((uint32_t)(x)) << AES_ACCEL_AILEN6_IVLEN_SHIFT)) & AES_ACCEL_AILEN6_IVLEN_MASK)
/*! @} */

/*! @name CRYPT6 - CRYPT register */
/*! @{ */

#define AES_ACCEL_CRYPT6_MASK_MASK               (0x7FU)
#define AES_ACCEL_CRYPT6_MASK_SHIFT              (0U)
#define AES_ACCEL_CRYPT6_MASK_WIDTH              (7U)
#define AES_ACCEL_CRYPT6_MASK(x)                 (((uint32_t)(((uint32_t)(x)) << AES_ACCEL_CRYPT6_MASK_SHIFT)) & AES_ACCEL_CRYPT6_MASK_MASK)

#define AES_ACCEL_CRYPT6_CMODE_MASK              (0xF00U)
#define AES_ACCEL_CRYPT6_CMODE_SHIFT             (8U)
#define AES_ACCEL_CRYPT6_CMODE_WIDTH             (4U)
#define AES_ACCEL_CRYPT6_CMODE(x)                (((uint32_t)(((uint32_t)(x)) << AES_ACCEL_CRYPT6_CMODE_SHIFT)) & AES_ACCEL_CRYPT6_CMODE_MASK)

#define AES_ACCEL_CRYPT6_CO_MASK                 (0x3000U)
#define AES_ACCEL_CRYPT6_CO_SHIFT                (12U)
#define AES_ACCEL_CRYPT6_CO_WIDTH                (2U)
#define AES_ACCEL_CRYPT6_CO(x)                   (((uint32_t)(((uint32_t)(x)) << AES_ACCEL_CRYPT6_CO_SHIFT)) & AES_ACCEL_CRYPT6_CO_MASK)

#define AES_ACCEL_CRYPT6_KSLOT_MASK              (0xFF0000U)
#define AES_ACCEL_CRYPT6_KSLOT_SHIFT             (16U)
#define AES_ACCEL_CRYPT6_KSLOT_WIDTH             (8U)
#define AES_ACCEL_CRYPT6_KSLOT(x)                (((uint32_t)(((uint32_t)(x)) << AES_ACCEL_CRYPT6_KSLOT_SHIFT)) & AES_ACCEL_CRYPT6_KSLOT_MASK)
/*! @} */

/*! @name OWNSTAT6 - OWN_Status register */
/*! @{ */

#define AES_ACCEL_OWNSTAT6_DID_MASK              (0xFU)
#define AES_ACCEL_OWNSTAT6_DID_SHIFT             (0U)
#define AES_ACCEL_OWNSTAT6_DID_WIDTH             (4U)
#define AES_ACCEL_OWNSTAT6_DID(x)                (((uint32_t)(((uint32_t)(x)) << AES_ACCEL_OWNSTAT6_DID_SHIFT)) & AES_ACCEL_OWNSTAT6_DID_MASK)

#define AES_ACCEL_OWNSTAT6_NS_MASK               (0x40U)
#define AES_ACCEL_OWNSTAT6_NS_SHIFT              (6U)
#define AES_ACCEL_OWNSTAT6_NS_WIDTH              (1U)
#define AES_ACCEL_OWNSTAT6_NS(x)                 (((uint32_t)(((uint32_t)(x)) << AES_ACCEL_OWNSTAT6_NS_SHIFT)) & AES_ACCEL_OWNSTAT6_NS_MASK)

#define AES_ACCEL_OWNSTAT6_PRIV_MASK             (0x80U)
#define AES_ACCEL_OWNSTAT6_PRIV_SHIFT            (7U)
#define AES_ACCEL_OWNSTAT6_PRIV_WIDTH            (1U)
#define AES_ACCEL_OWNSTAT6_PRIV(x)               (((uint32_t)(((uint32_t)(x)) << AES_ACCEL_OWNSTAT6_PRIV_SHIFT)) & AES_ACCEL_OWNSTAT6_PRIV_MASK)
/*! @} */

/*! @name TLVAL6 - Timer Load Value Register */
/*! @{ */

#define AES_ACCEL_TLVAL6_TSV_MASK                (0xFFFFU)
#define AES_ACCEL_TLVAL6_TSV_SHIFT               (0U)
#define AES_ACCEL_TLVAL6_TSV_WIDTH               (16U)
#define AES_ACCEL_TLVAL6_TSV(x)                  (((uint32_t)(((uint32_t)(x)) << AES_ACCEL_TLVAL6_TSV_SHIFT)) & AES_ACCEL_TLVAL6_TSV_MASK)
/*! @} */

/*! @name CVAL6 - Current Timer Value Register */
/*! @{ */

#define AES_ACCEL_CVAL6_TVL_MASK                 (0xFFFFU)
#define AES_ACCEL_CVAL6_TVL_SHIFT                (0U)
#define AES_ACCEL_CVAL6_TVL_WIDTH                (16U)
#define AES_ACCEL_CVAL6_TVL(x)                   (((uint32_t)(((uint32_t)(x)) << AES_ACCEL_CVAL6_TVL_SHIFT)) & AES_ACCEL_CVAL6_TVL_MASK)
/*! @} */

/*! @name TCTRL6 - Timer Control Register */
/*! @{ */

#define AES_ACCEL_TCTRL6_TEN_MASK                (0x1U)
#define AES_ACCEL_TCTRL6_TEN_SHIFT               (0U)
#define AES_ACCEL_TCTRL6_TEN_WIDTH               (1U)
#define AES_ACCEL_TCTRL6_TEN(x)                  (((uint32_t)(((uint32_t)(x)) << AES_ACCEL_TCTRL6_TEN_SHIFT)) & AES_ACCEL_TCTRL6_TEN_MASK)

#define AES_ACCEL_TCTRL6_TIE_MASK                (0x2U)
#define AES_ACCEL_TCTRL6_TIE_SHIFT               (1U)
#define AES_ACCEL_TCTRL6_TIE_WIDTH               (1U)
#define AES_ACCEL_TCTRL6_TIE(x)                  (((uint32_t)(((uint32_t)(x)) << AES_ACCEL_TCTRL6_TIE_SHIFT)) & AES_ACCEL_TCTRL6_TIE_MASK)

#define AES_ACCEL_TCTRL6_FRZ_MASK                (0x4U)
#define AES_ACCEL_TCTRL6_FRZ_SHIFT               (2U)
#define AES_ACCEL_TCTRL6_FRZ_WIDTH               (1U)
#define AES_ACCEL_TCTRL6_FRZ(x)                  (((uint32_t)(((uint32_t)(x)) << AES_ACCEL_TCTRL6_FRZ_SHIFT)) & AES_ACCEL_TCTRL6_FRZ_MASK)
/*! @} */

/*! @name TFLG6 - Timer Flag Register */
/*! @{ */

#define AES_ACCEL_TFLG6_TIF_MASK                 (0x1U)
#define AES_ACCEL_TFLG6_TIF_SHIFT                (0U)
#define AES_ACCEL_TFLG6_TIF_WIDTH                (1U)
#define AES_ACCEL_TFLG6_TIF(x)                   (((uint32_t)(((uint32_t)(x)) << AES_ACCEL_TFLG6_TIF_SHIFT)) & AES_ACCEL_TFLG6_TIF_MASK)
/*! @} */

/*! @name FEEDINTMAP6 - FEEDINTMAP register */
/*! @{ */

#define AES_ACCEL_FEEDINTMAP6_FIEN6_MASK         (0x1U)
#define AES_ACCEL_FEEDINTMAP6_FIEN6_SHIFT        (0U)
#define AES_ACCEL_FEEDINTMAP6_FIEN6_WIDTH        (1U)
#define AES_ACCEL_FEEDINTMAP6_FIEN6(x)           (((uint32_t)(((uint32_t)(x)) << AES_ACCEL_FEEDINTMAP6_FIEN6_SHIFT)) & AES_ACCEL_FEEDINTMAP6_FIEN6_MASK)

#define AES_ACCEL_FEEDINTMAP6_FIEN14_MASK        (0x2U)
#define AES_ACCEL_FEEDINTMAP6_FIEN14_SHIFT       (1U)
#define AES_ACCEL_FEEDINTMAP6_FIEN14_WIDTH       (1U)
#define AES_ACCEL_FEEDINTMAP6_FIEN14(x)          (((uint32_t)(((uint32_t)(x)) << AES_ACCEL_FEEDINTMAP6_FIEN14_SHIFT)) & AES_ACCEL_FEEDINTMAP6_FIEN14_MASK)

#define AES_ACCEL_FEEDINTMAP6_FIEN22_MASK        (0x4U)
#define AES_ACCEL_FEEDINTMAP6_FIEN22_SHIFT       (2U)
#define AES_ACCEL_FEEDINTMAP6_FIEN22_WIDTH       (1U)
#define AES_ACCEL_FEEDINTMAP6_FIEN22(x)          (((uint32_t)(((uint32_t)(x)) << AES_ACCEL_FEEDINTMAP6_FIEN22_SHIFT)) & AES_ACCEL_FEEDINTMAP6_FIEN22_MASK)

#define AES_ACCEL_FEEDINTMAP6_FIEN30_MASK        (0x8U)
#define AES_ACCEL_FEEDINTMAP6_FIEN30_SHIFT       (3U)
#define AES_ACCEL_FEEDINTMAP6_FIEN30_WIDTH       (1U)
#define AES_ACCEL_FEEDINTMAP6_FIEN30(x)          (((uint32_t)(((uint32_t)(x)) << AES_ACCEL_FEEDINTMAP6_FIEN30_SHIFT)) & AES_ACCEL_FEEDINTMAP6_FIEN30_MASK)
/*! @} */

/*! @name RESULTINTMAP6 - RESULTINTMAP register */
/*! @{ */

#define AES_ACCEL_RESULTINTMAP6_RIEN6_MASK       (0x1U)
#define AES_ACCEL_RESULTINTMAP6_RIEN6_SHIFT      (0U)
#define AES_ACCEL_RESULTINTMAP6_RIEN6_WIDTH      (1U)
#define AES_ACCEL_RESULTINTMAP6_RIEN6(x)         (((uint32_t)(((uint32_t)(x)) << AES_ACCEL_RESULTINTMAP6_RIEN6_SHIFT)) & AES_ACCEL_RESULTINTMAP6_RIEN6_MASK)

#define AES_ACCEL_RESULTINTMAP6_RIEN14_MASK      (0x2U)
#define AES_ACCEL_RESULTINTMAP6_RIEN14_SHIFT     (1U)
#define AES_ACCEL_RESULTINTMAP6_RIEN14_WIDTH     (1U)
#define AES_ACCEL_RESULTINTMAP6_RIEN14(x)        (((uint32_t)(((uint32_t)(x)) << AES_ACCEL_RESULTINTMAP6_RIEN14_SHIFT)) & AES_ACCEL_RESULTINTMAP6_RIEN14_MASK)

#define AES_ACCEL_RESULTINTMAP6_RIEN22_MASK      (0x4U)
#define AES_ACCEL_RESULTINTMAP6_RIEN22_SHIFT     (2U)
#define AES_ACCEL_RESULTINTMAP6_RIEN22_WIDTH     (1U)
#define AES_ACCEL_RESULTINTMAP6_RIEN22(x)        (((uint32_t)(((uint32_t)(x)) << AES_ACCEL_RESULTINTMAP6_RIEN22_SHIFT)) & AES_ACCEL_RESULTINTMAP6_RIEN22_MASK)
/*! @} */

/*! @name LEN7 - LEN register */
/*! @{ */

#define AES_ACCEL_LEN7_TLEN_MASK                 (0x7FFFFU)
#define AES_ACCEL_LEN7_TLEN_SHIFT                (0U)
#define AES_ACCEL_LEN7_TLEN_WIDTH                (19U)
#define AES_ACCEL_LEN7_TLEN(x)                   (((uint32_t)(((uint32_t)(x)) << AES_ACCEL_LEN7_TLEN_SHIFT)) & AES_ACCEL_LEN7_TLEN_MASK)
/*! @} */

/*! @name AILEN7 - AAD/IV length register */
/*! @{ */

#define AES_ACCEL_AILEN7_AAD_MASK                (0x7FFFFU)
#define AES_ACCEL_AILEN7_AAD_SHIFT               (0U)
#define AES_ACCEL_AILEN7_AAD_WIDTH               (19U)
#define AES_ACCEL_AILEN7_AAD(x)                  (((uint32_t)(((uint32_t)(x)) << AES_ACCEL_AILEN7_AAD_SHIFT)) & AES_ACCEL_AILEN7_AAD_MASK)

#define AES_ACCEL_AILEN7_IVLEN_MASK              (0x7F000000U)
#define AES_ACCEL_AILEN7_IVLEN_SHIFT             (24U)
#define AES_ACCEL_AILEN7_IVLEN_WIDTH             (7U)
#define AES_ACCEL_AILEN7_IVLEN(x)                (((uint32_t)(((uint32_t)(x)) << AES_ACCEL_AILEN7_IVLEN_SHIFT)) & AES_ACCEL_AILEN7_IVLEN_MASK)
/*! @} */

/*! @name CRYPT7 - CRYPT register */
/*! @{ */

#define AES_ACCEL_CRYPT7_MASK_MASK               (0x7FU)
#define AES_ACCEL_CRYPT7_MASK_SHIFT              (0U)
#define AES_ACCEL_CRYPT7_MASK_WIDTH              (7U)
#define AES_ACCEL_CRYPT7_MASK(x)                 (((uint32_t)(((uint32_t)(x)) << AES_ACCEL_CRYPT7_MASK_SHIFT)) & AES_ACCEL_CRYPT7_MASK_MASK)

#define AES_ACCEL_CRYPT7_CMODE_MASK              (0xF00U)
#define AES_ACCEL_CRYPT7_CMODE_SHIFT             (8U)
#define AES_ACCEL_CRYPT7_CMODE_WIDTH             (4U)
#define AES_ACCEL_CRYPT7_CMODE(x)                (((uint32_t)(((uint32_t)(x)) << AES_ACCEL_CRYPT7_CMODE_SHIFT)) & AES_ACCEL_CRYPT7_CMODE_MASK)

#define AES_ACCEL_CRYPT7_CO_MASK                 (0x3000U)
#define AES_ACCEL_CRYPT7_CO_SHIFT                (12U)
#define AES_ACCEL_CRYPT7_CO_WIDTH                (2U)
#define AES_ACCEL_CRYPT7_CO(x)                   (((uint32_t)(((uint32_t)(x)) << AES_ACCEL_CRYPT7_CO_SHIFT)) & AES_ACCEL_CRYPT7_CO_MASK)

#define AES_ACCEL_CRYPT7_KSLOT_MASK              (0xFF0000U)
#define AES_ACCEL_CRYPT7_KSLOT_SHIFT             (16U)
#define AES_ACCEL_CRYPT7_KSLOT_WIDTH             (8U)
#define AES_ACCEL_CRYPT7_KSLOT(x)                (((uint32_t)(((uint32_t)(x)) << AES_ACCEL_CRYPT7_KSLOT_SHIFT)) & AES_ACCEL_CRYPT7_KSLOT_MASK)
/*! @} */

/*! @name OWNSTAT7 - OWN_Status register */
/*! @{ */

#define AES_ACCEL_OWNSTAT7_DID_MASK              (0xFU)
#define AES_ACCEL_OWNSTAT7_DID_SHIFT             (0U)
#define AES_ACCEL_OWNSTAT7_DID_WIDTH             (4U)
#define AES_ACCEL_OWNSTAT7_DID(x)                (((uint32_t)(((uint32_t)(x)) << AES_ACCEL_OWNSTAT7_DID_SHIFT)) & AES_ACCEL_OWNSTAT7_DID_MASK)

#define AES_ACCEL_OWNSTAT7_NS_MASK               (0x40U)
#define AES_ACCEL_OWNSTAT7_NS_SHIFT              (6U)
#define AES_ACCEL_OWNSTAT7_NS_WIDTH              (1U)
#define AES_ACCEL_OWNSTAT7_NS(x)                 (((uint32_t)(((uint32_t)(x)) << AES_ACCEL_OWNSTAT7_NS_SHIFT)) & AES_ACCEL_OWNSTAT7_NS_MASK)

#define AES_ACCEL_OWNSTAT7_PRIV_MASK             (0x80U)
#define AES_ACCEL_OWNSTAT7_PRIV_SHIFT            (7U)
#define AES_ACCEL_OWNSTAT7_PRIV_WIDTH            (1U)
#define AES_ACCEL_OWNSTAT7_PRIV(x)               (((uint32_t)(((uint32_t)(x)) << AES_ACCEL_OWNSTAT7_PRIV_SHIFT)) & AES_ACCEL_OWNSTAT7_PRIV_MASK)
/*! @} */

/*! @name TLVAL7 - Timer Load Value Register */
/*! @{ */

#define AES_ACCEL_TLVAL7_TSV_MASK                (0xFFFFU)
#define AES_ACCEL_TLVAL7_TSV_SHIFT               (0U)
#define AES_ACCEL_TLVAL7_TSV_WIDTH               (16U)
#define AES_ACCEL_TLVAL7_TSV(x)                  (((uint32_t)(((uint32_t)(x)) << AES_ACCEL_TLVAL7_TSV_SHIFT)) & AES_ACCEL_TLVAL7_TSV_MASK)
/*! @} */

/*! @name CVAL7 - Current Timer Value Register */
/*! @{ */

#define AES_ACCEL_CVAL7_TVL_MASK                 (0xFFFFU)
#define AES_ACCEL_CVAL7_TVL_SHIFT                (0U)
#define AES_ACCEL_CVAL7_TVL_WIDTH                (16U)
#define AES_ACCEL_CVAL7_TVL(x)                   (((uint32_t)(((uint32_t)(x)) << AES_ACCEL_CVAL7_TVL_SHIFT)) & AES_ACCEL_CVAL7_TVL_MASK)
/*! @} */

/*! @name TCTRL7 - Timer Control Register */
/*! @{ */

#define AES_ACCEL_TCTRL7_TEN_MASK                (0x1U)
#define AES_ACCEL_TCTRL7_TEN_SHIFT               (0U)
#define AES_ACCEL_TCTRL7_TEN_WIDTH               (1U)
#define AES_ACCEL_TCTRL7_TEN(x)                  (((uint32_t)(((uint32_t)(x)) << AES_ACCEL_TCTRL7_TEN_SHIFT)) & AES_ACCEL_TCTRL7_TEN_MASK)

#define AES_ACCEL_TCTRL7_TIE_MASK                (0x2U)
#define AES_ACCEL_TCTRL7_TIE_SHIFT               (1U)
#define AES_ACCEL_TCTRL7_TIE_WIDTH               (1U)
#define AES_ACCEL_TCTRL7_TIE(x)                  (((uint32_t)(((uint32_t)(x)) << AES_ACCEL_TCTRL7_TIE_SHIFT)) & AES_ACCEL_TCTRL7_TIE_MASK)

#define AES_ACCEL_TCTRL7_FRZ_MASK                (0x4U)
#define AES_ACCEL_TCTRL7_FRZ_SHIFT               (2U)
#define AES_ACCEL_TCTRL7_FRZ_WIDTH               (1U)
#define AES_ACCEL_TCTRL7_FRZ(x)                  (((uint32_t)(((uint32_t)(x)) << AES_ACCEL_TCTRL7_FRZ_SHIFT)) & AES_ACCEL_TCTRL7_FRZ_MASK)
/*! @} */

/*! @name TFLG7 - Timer Flag Register */
/*! @{ */

#define AES_ACCEL_TFLG7_TIF_MASK                 (0x1U)
#define AES_ACCEL_TFLG7_TIF_SHIFT                (0U)
#define AES_ACCEL_TFLG7_TIF_WIDTH                (1U)
#define AES_ACCEL_TFLG7_TIF(x)                   (((uint32_t)(((uint32_t)(x)) << AES_ACCEL_TFLG7_TIF_SHIFT)) & AES_ACCEL_TFLG7_TIF_MASK)
/*! @} */

/*! @name FEEDINTMAP7 - FEEDINTMAP register */
/*! @{ */

#define AES_ACCEL_FEEDINTMAP7_FIEN7_MASK         (0x1U)
#define AES_ACCEL_FEEDINTMAP7_FIEN7_SHIFT        (0U)
#define AES_ACCEL_FEEDINTMAP7_FIEN7_WIDTH        (1U)
#define AES_ACCEL_FEEDINTMAP7_FIEN7(x)           (((uint32_t)(((uint32_t)(x)) << AES_ACCEL_FEEDINTMAP7_FIEN7_SHIFT)) & AES_ACCEL_FEEDINTMAP7_FIEN7_MASK)

#define AES_ACCEL_FEEDINTMAP7_FIEN15_MASK        (0x2U)
#define AES_ACCEL_FEEDINTMAP7_FIEN15_SHIFT       (1U)
#define AES_ACCEL_FEEDINTMAP7_FIEN15_WIDTH       (1U)
#define AES_ACCEL_FEEDINTMAP7_FIEN15(x)          (((uint32_t)(((uint32_t)(x)) << AES_ACCEL_FEEDINTMAP7_FIEN15_SHIFT)) & AES_ACCEL_FEEDINTMAP7_FIEN15_MASK)

#define AES_ACCEL_FEEDINTMAP7_FIEN23_MASK        (0x4U)
#define AES_ACCEL_FEEDINTMAP7_FIEN23_SHIFT       (2U)
#define AES_ACCEL_FEEDINTMAP7_FIEN23_WIDTH       (1U)
#define AES_ACCEL_FEEDINTMAP7_FIEN23(x)          (((uint32_t)(((uint32_t)(x)) << AES_ACCEL_FEEDINTMAP7_FIEN23_SHIFT)) & AES_ACCEL_FEEDINTMAP7_FIEN23_MASK)

#define AES_ACCEL_FEEDINTMAP7_FIEN31_MASK        (0x8U)
#define AES_ACCEL_FEEDINTMAP7_FIEN31_SHIFT       (3U)
#define AES_ACCEL_FEEDINTMAP7_FIEN31_WIDTH       (1U)
#define AES_ACCEL_FEEDINTMAP7_FIEN31(x)          (((uint32_t)(((uint32_t)(x)) << AES_ACCEL_FEEDINTMAP7_FIEN31_SHIFT)) & AES_ACCEL_FEEDINTMAP7_FIEN31_MASK)
/*! @} */

/*! @name RESULTINTMAP7 - RESULTINTMAP register */
/*! @{ */

#define AES_ACCEL_RESULTINTMAP7_RIEN7_MASK       (0x1U)
#define AES_ACCEL_RESULTINTMAP7_RIEN7_SHIFT      (0U)
#define AES_ACCEL_RESULTINTMAP7_RIEN7_WIDTH      (1U)
#define AES_ACCEL_RESULTINTMAP7_RIEN7(x)         (((uint32_t)(((uint32_t)(x)) << AES_ACCEL_RESULTINTMAP7_RIEN7_SHIFT)) & AES_ACCEL_RESULTINTMAP7_RIEN7_MASK)

#define AES_ACCEL_RESULTINTMAP7_RIEN15_MASK      (0x2U)
#define AES_ACCEL_RESULTINTMAP7_RIEN15_SHIFT     (1U)
#define AES_ACCEL_RESULTINTMAP7_RIEN15_WIDTH     (1U)
#define AES_ACCEL_RESULTINTMAP7_RIEN15(x)        (((uint32_t)(((uint32_t)(x)) << AES_ACCEL_RESULTINTMAP7_RIEN15_SHIFT)) & AES_ACCEL_RESULTINTMAP7_RIEN15_MASK)

#define AES_ACCEL_RESULTINTMAP7_RIEN23_MASK      (0x4U)
#define AES_ACCEL_RESULTINTMAP7_RIEN23_SHIFT     (2U)
#define AES_ACCEL_RESULTINTMAP7_RIEN23_WIDTH     (1U)
#define AES_ACCEL_RESULTINTMAP7_RIEN23(x)        (((uint32_t)(((uint32_t)(x)) << AES_ACCEL_RESULTINTMAP7_RIEN23_SHIFT)) & AES_ACCEL_RESULTINTMAP7_RIEN23_MASK)
/*! @} */

/*!
 * @}
 */ /* end of group AES_ACCEL_Register_Masks */

/*!
 * @}
 */ /* end of group AES_ACCEL_Peripheral_Access_Layer */

#endif  /* #if !defined(S32K388_AES_ACCEL_H_) */
