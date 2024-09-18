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
 * @file S32K388_VIRT_WRAPPER.h
 * @version 1.1
 * @date 2022-12-23
 * @brief Peripheral Access Layer for S32K388_VIRT_WRAPPER
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
#if !defined(S32K388_VIRT_WRAPPER_H_)  /* Check if memory map has not been already included */
#define S32K388_VIRT_WRAPPER_H_

#include "S32K388_COMMON.h"

/* ----------------------------------------------------------------------------
   -- VIRT_WRAPPER Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup VIRT_WRAPPER_Peripheral_Access_Layer VIRT_WRAPPER Peripheral Access Layer
 * @{
 */

/** VIRT_WRAPPER - Size of Registers Arrays */
#define VIRT_WRAPPER_REG_C_COUNT                  1u

/** VIRT_WRAPPER - Register Layout Typedef */
typedef struct {
  __IO uint32_t REG_A3_0;                          /**< Parameter_n Register, offset: 0x0 */
  __IO uint32_t REG_A7_4;                          /**< Parameter_n Register, offset: 0x4 */
  __IO uint32_t REG_A11_8;                         /**< Parameter_n Register, offset: 0x8 */
  __IO uint32_t REG_A15_12;                        /**< Parameter_n Register, offset: 0xC */
  __IO uint32_t REG_A19_16;                        /**< Parameter_n Register, offset: 0x10 */
  __IO uint32_t REG_A23_20;                        /**< Parameter_n Register, offset: 0x14 */
  __IO uint32_t REG_A27_24;                        /**< Parameter_n Register, offset: 0x18 */
  __IO uint32_t REG_A31_28;                        /**< Parameter_n Register, offset: 0x1C */
  __IO uint32_t REG_A35_32;                        /**< Parameter_n Register, offset: 0x20 */
  __IO uint32_t REG_A39_36;                        /**< Parameter_n Register, offset: 0x24 */
  __IO uint32_t REG_A43_40;                        /**< Parameter_n Register, offset: 0x28 */
  __IO uint32_t REG_A47_44;                        /**< Parameter_n Register, offset: 0x2C */
  __IO uint32_t REG_A51_48;                        /**< Parameter_n Register, offset: 0x30 */
  __IO uint32_t REG_A55_52;                        /**< Parameter_n Register, offset: 0x34 */
  __IO uint32_t REG_A59_56;                        /**< Parameter_n Register, offset: 0x38 */
  __IO uint32_t REG_A63_60;                        /**< Parameter_n Register, offset: 0x3C */
  __IO uint32_t REG_A67_64;                        /**< Parameter_n Register, offset: 0x40 */
  __IO uint32_t REG_A71_68;                        /**< Parameter_n Register, offset: 0x44 */
  __IO uint32_t REG_A75_72;                        /**< Parameter_n Register, offset: 0x48 */
  __IO uint32_t REG_A79_76;                        /**< Parameter_n Register, offset: 0x4C */
  __IO uint32_t REG_A83_80;                        /**< Parameter_n Register, offset: 0x50 */
  __IO uint32_t REG_A87_84;                        /**< Parameter_n Register, offset: 0x54 */
  __IO uint32_t REG_A91_88;                        /**< Parameter_n Register, offset: 0x58 */
  __IO uint32_t REG_A95_92;                        /**< Parameter_n Register, offset: 0x5C */
  __IO uint32_t REG_A99_96;                        /**< Parameter_n Register, offset: 0x60 */
  __IO uint32_t REG_A103_100;                      /**< Parameter_n Register, offset: 0x64 */
  __IO uint32_t REG_A107_104;                      /**< Parameter_n Register, offset: 0x68 */
  __IO uint32_t REG_A111_108;                      /**< Parameter_n Register, offset: 0x6C */
  __IO uint32_t REG_A115_112;                      /**< Parameter_n Register, offset: 0x70 */
  __IO uint32_t REG_A119_116;                      /**< Parameter_n Register, offset: 0x74 */
  __IO uint32_t REG_A123_120;                      /**< Parameter_n Register, offset: 0x78 */
  __IO uint32_t REG_A127_124;                      /**< Parameter_n Register, offset: 0x7C */
  __IO uint32_t REG_A131_128;                      /**< Parameter_n Register, offset: 0x80 */
  __IO uint32_t REG_A135_132;                      /**< Parameter_n Register, offset: 0x84 */
  __IO uint32_t REG_A139_136;                      /**< Parameter_n Register, offset: 0x88 */
  __IO uint32_t REG_A143_140;                      /**< Parameter_n Register, offset: 0x8C */
  __IO uint32_t REG_A147_144;                      /**< Parameter_n Register, offset: 0x90 */
  __IO uint32_t REG_A151_148;                      /**< Parameter_n Register, offset: 0x94 */
  __IO uint32_t REG_A155_152;                      /**< Parameter_n Register, offset: 0x98 */
  __IO uint32_t REG_A159_156;                      /**< Parameter_n Register, offset: 0x9C */
  __IO uint32_t REG_A163_160;                      /**< Parameter_n Register, offset: 0xA0 */
  __IO uint32_t REG_A167_164;                      /**< Parameter_n Register, offset: 0xA4 */
  __IO uint32_t REG_A171_168;                      /**< Parameter_n Register, offset: 0xA8 */
  __IO uint32_t REG_A175_172;                      /**< Parameter_n Register, offset: 0xAC */
  __IO uint32_t REG_A179_176;                      /**< Parameter_n Register, offset: 0xB0 */
  __IO uint32_t REG_A183_180;                      /**< Parameter_n Register, offset: 0xB4 */
  __IO uint32_t REG_A187_184;                      /**< Parameter_n Register, offset: 0xB8 */
  __IO uint32_t REG_A191_188;                      /**< Parameter_n Register, offset: 0xBC */
  __IO uint32_t REG_A195_192;                      /**< Parameter_n Register, offset: 0xC0 */
  __IO uint32_t REG_A199_196;                      /**< Parameter_n Register, offset: 0xC4 */
  __IO uint32_t REG_A203_200;                      /**< Parameter_n Register, offset: 0xC8 */
  __IO uint32_t REG_A207_204;                      /**< Parameter_n Register, offset: 0xCC */
  __IO uint32_t REG_A211_208;                      /**< Parameter_n Register, offset: 0xD0 */
  __IO uint32_t REG_A215_212;                      /**< Parameter_n Register, offset: 0xD4 */
  __IO uint32_t REG_A219_216;                      /**< Parameter_n Register, offset: 0xD8 */
  __IO uint32_t REG_A223_220;                      /**< Parameter_n Register, offset: 0xDC */
  __IO uint32_t REG_A227_224;                      /**< Parameter_n Register, offset: 0xE0 */
  __IO uint32_t REG_A231_228;                      /**< Parameter_n Register, offset: 0xE4 */
  __IO uint32_t REG_A235_232;                      /**< Parameter_n Register, offset: 0xE8 */
  __IO uint32_t REG_A239_236;                      /**< Parameter_n Register, offset: 0xEC */
  uint8_t RESERVED_0[784];
  __IO uint32_t REG_B3_0;                          /**< Parameter_n Register, offset: 0x400 */
  __IO uint32_t REG_B7_4;                          /**< Parameter_n Register, offset: 0x404 */
  uint8_t RESERVED_1[8];
  __IO uint32_t REG_B19_16;                        /**< Parameter_n Register, offset: 0x410 */
  __IO uint32_t REG_B23_20;                        /**< Parameter_n Register, offset: 0x414 */
  __IO uint32_t REG_B27_24;                        /**< Parameter_n Register, offset: 0x418 */
  __IO uint32_t REG_B31_28;                        /**< Parameter_n Register, offset: 0x41C */
  __IO uint32_t REG_B35_32;                        /**< Parameter_n Register, offset: 0x420 */
  __IO uint32_t REG_B39_36;                        /**< Parameter_n Register, offset: 0x424 */
  __IO uint32_t REG_B43_40;                        /**< Parameter_n Register, offset: 0x428 */
  __IO uint32_t REG_B47_44;                        /**< Parameter_n Register, offset: 0x42C */
  __IO uint32_t REG_B51_48;                        /**< Parameter_n Register, offset: 0x430 */
  __IO uint32_t REG_B55_52;                        /**< Parameter_n Register, offset: 0x434 */
  __IO uint32_t REG_B59_56;                        /**< Parameter_n Register, offset: 0x438 */
  __IO uint32_t REG_B63_60;                        /**< Parameter_n Register, offset: 0x43C */
  __IO uint32_t REG_B67_64;                        /**< Parameter_n Register, offset: 0x440 */
  __IO uint32_t REG_B71_68;                        /**< Parameter_n Register, offset: 0x444 */
  uint8_t RESERVED_2[8];
  __IO uint32_t REG_B83_80;                        /**< Parameter_n Register, offset: 0x450 */
  __IO uint32_t REG_B87_84;                        /**< Parameter_n Register, offset: 0x454 */
  __IO uint32_t REG_B91_88;                        /**< Parameter_n Register, offset: 0x458 */
  __IO uint32_t REG_B95_92;                        /**< Parameter_n Register, offset: 0x45C */
  __IO uint32_t REG_B99_96;                        /**< Parameter_n Register, offset: 0x460 */
  __IO uint32_t REG_B103_100;                      /**< Parameter_n Register, offset: 0x464 */
  uint8_t RESERVED_3[8];
  __IO uint32_t REG_B115_112;                      /**< Parameter_n Register, offset: 0x470 */
  __IO uint32_t REG_B119_116;                      /**< Parameter_n Register, offset: 0x474 */
  __IO uint32_t REG_B123_120;                      /**< Parameter_n Register, offset: 0x478 */
  __IO uint32_t REG_B127_124;                      /**< Parameter_n Register, offset: 0x47C */
  __IO uint32_t REG_B131_128;                      /**< Parameter_n Register, offset: 0x480 */
  __IO uint32_t REG_B135_132;                      /**< Parameter_n Register, offset: 0x484 */
  uint8_t RESERVED_4[8];
  __IO uint32_t REG_B147_144;                      /**< Parameter_n Register, offset: 0x490 */
  __IO uint32_t REG_B151_148;                      /**< Parameter_n Register, offset: 0x494 */
  __IO uint32_t REG_B155_152;                      /**< Parameter_n Register, offset: 0x498 */
  __IO uint32_t REG_B159_156;                      /**< Parameter_n Register, offset: 0x49C */
  __IO uint32_t REG_B163_160;                      /**< Parameter_n Register, offset: 0x4A0 */
  __IO uint32_t REG_B167_164;                      /**< Parameter_n Register, offset: 0x4A4 */
  __IO uint32_t REG_B171_168;                      /**< Parameter_n Register, offset: 0x4A8 */
  __IO uint32_t REG_B175_172;                      /**< Parameter_n Register, offset: 0x4AC */
  __IO uint32_t REG_B179_176;                      /**< Parameter_n Register, offset: 0x4B0 */
  __IO uint32_t REG_B183_180;                      /**< Parameter_n Register, offset: 0x4B4 */
  __IO uint32_t REG_B187_184;                      /**< Parameter_n Register, offset: 0x4B8 */
  __IO uint32_t REG_B191_188;                      /**< Parameter_n Register, offset: 0x4BC */
  __IO uint32_t REG_B195_192;                      /**< Parameter_n Register, offset: 0x4C0 */
  __IO uint32_t REG_B199_196;                      /**< Parameter_n Register, offset: 0x4C4 */
  __IO uint32_t REG_B203_200;                      /**< Parameter_n Register, offset: 0x4C8 */
  uint8_t RESERVED_5[4];
  __IO uint32_t REG_B211_208;                      /**< Parameter_n Register, offset: 0x4D0 */
  __IO uint32_t REG_B215_212;                      /**< Parameter_n Register, offset: 0x4D4 */
  __IO uint32_t REG_B219_216;                      /**< Parameter_n Register, offset: 0x4D8 */
  __IO uint32_t REG_B223_220;                      /**< Parameter_n Register, offset: 0x4DC */
  __IO uint32_t REG_B227_224;                      /**< Parameter_n Register, offset: 0x4E0 */
  __IO uint32_t REG_B231_228;                      /**< Parameter_n Register, offset: 0x4E4 */
  __IO uint32_t REG_B235_232;                      /**< Parameter_n Register, offset: 0x4E8 */
  __IO uint32_t REG_B239_236;                      /**< Parameter_n Register, offset: 0x4EC */
  __IO uint32_t REG_B243_240;                      /**< Parameter_n Register, offset: 0x4F0 */
  __IO uint32_t REG_B247_244;                      /**< Parameter_n Register, offset: 0x4F4 */
  __IO uint32_t REG_B251_248;                      /**< Parameter_n Register, offset: 0x4F8 */
  __IO uint32_t REG_B255_252;                      /**< Parameter_n Register, offset: 0x4FC */
  __IO uint32_t REG_B259_256;                      /**< Parameter_n Register, offset: 0x500 */
  __IO uint32_t REG_B263_260;                      /**< Parameter_n Register, offset: 0x504 */
  __IO uint32_t REG_B267_264;                      /**< Parameter_n Register, offset: 0x508 */
  __IO uint32_t REG_B271_268;                      /**< Parameter_n Register, offset: 0x50C */
  uint8_t RESERVED_6[16];
  __IO uint32_t REG_B291_288;                      /**< Parameter_n Register, offset: 0x520 */
  __IO uint32_t REG_B295_292;                      /**< Parameter_n Register, offset: 0x524 */
  __IO uint32_t REG_B299_296;                      /**< Parameter_n Register, offset: 0x528 */
  __IO uint32_t REG_B303_300;                      /**< Parameter_n Register, offset: 0x52C */
  __IO uint32_t REG_B307_304;                      /**< Parameter_n Register, offset: 0x530 */
  __IO uint32_t REG_B311_308;                      /**< Parameter_n Register, offset: 0x534 */
  __IO uint32_t REG_B315_312;                      /**< Parameter_n Register, offset: 0x538 */
  __IO uint32_t REG_B319_316;                      /**< Parameter_n Register, offset: 0x53C */
  __IO uint32_t REG_B323_320;                      /**< Parameter_n Register, offset: 0x540 */
  __IO uint32_t REG_B327_324;                      /**< Parameter_n Register, offset: 0x544 */
  uint8_t RESERVED_7[12];
  __IO uint32_t REG_B343_340;                      /**< Parameter_n Register, offset: 0x554 */
  __IO uint32_t REG_B347_344;                      /**< Parameter_n Register, offset: 0x558 */
  __IO uint32_t REG_B351_348;                      /**< Parameter_n Register, offset: 0x55C */
  __IO uint32_t REG_B355_352;                      /**< Parameter_n Register, offset: 0x560 */
  __IO uint32_t REG_B359_356;                      /**< Parameter_n Register, offset: 0x564 */
  __IO uint32_t REG_B363_360;                      /**< Parameter_n Register, offset: 0x568 */
  __IO uint32_t REG_B367_364;                      /**< Parameter_n Register, offset: 0x56C */
  __IO uint32_t REG_B371_368;                      /**< Parameter_n Register, offset: 0x570 */
  __IO uint32_t REG_B375_372;                      /**< Parameter_n Register, offset: 0x574 */
  __IO uint32_t REG_B379_376;                      /**< Parameter_n Register, offset: 0x578 */
  uint8_t RESERVED_8[8];
  __IO uint32_t REG_B391_388;                      /**< Parameter_n Register, offset: 0x584 */
  uint8_t RESERVED_9[4];
  __IO uint32_t REG_B399_396;                      /**< Parameter_n Register, offset: 0x58C */
  uint8_t RESERVED_10[8];
  __IO uint32_t REG_B411_408;                      /**< Parameter_n Register, offset: 0x598 */
  __IO uint32_t REG_B415_412;                      /**< Parameter_n Register, offset: 0x59C */
  __IO uint32_t REG_B419_416;                      /**< Parameter_n Register, offset: 0x5A0 */
  uint8_t RESERVED_11[20];
  __IO uint32_t REG_B443_440;                      /**< Parameter_n Register, offset: 0x5B8 */
  uint8_t RESERVED_12[4];
  __IO uint32_t REG_B451_448;                      /**< Parameter_n Register, offset: 0x5C0 */
  __IO uint32_t REG_B455_452;                      /**< Parameter_n Register, offset: 0x5C4 */
  __IO uint32_t REG_B459_456;                      /**< Parameter_n Register, offset: 0x5C8 */
  __IO uint32_t REG_B463_460;                      /**< Parameter_n Register, offset: 0x5CC */
  __IO uint32_t REG_B467_464;                      /**< Parameter_n Register, offset: 0x5D0 */
  __IO uint32_t REG_B471_468;                      /**< Parameter_n Register, offset: 0x5D4 */
  uint8_t RESERVED_13[552];
  __IO uint32_t REG_C[VIRT_WRAPPER_REG_C_COUNT];   /**< Parameter_n Register, array offset: 0x800, array step: 0x4 */
} VIRT_WRAPPER_Type, *VIRT_WRAPPER_MemMapPtr;

/** Number of instances of the VIRT_WRAPPER module. */
#define VIRT_WRAPPER_INSTANCE_COUNT              (1u)

/* VIRT_WRAPPER - Peripheral instance base addresses */
/** Peripheral VIRT_WRAPPER base address */
#define IP_VIRT_WRAPPER_BASE                     (0x402A8000u)
/** Peripheral VIRT_WRAPPER base pointer */
#define IP_VIRT_WRAPPER                          ((VIRT_WRAPPER_Type *)IP_VIRT_WRAPPER_BASE)
/** Array initializer of VIRT_WRAPPER peripheral base addresses */
#define IP_VIRT_WRAPPER_BASE_ADDRS               { IP_VIRT_WRAPPER_BASE }
/** Array initializer of VIRT_WRAPPER peripheral base pointers */
#define IP_VIRT_WRAPPER_BASE_PTRS                { IP_VIRT_WRAPPER }

/* ----------------------------------------------------------------------------
   -- VIRT_WRAPPER Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup VIRT_WRAPPER_Register_Masks VIRT_WRAPPER Register Masks
 * @{
 */

/*! @name REG_A3_0 - Parameter_n Register */
/*! @{ */

#define VIRT_WRAPPER_REG_A3_0_PAD_0_MASK         (0x7U)
#define VIRT_WRAPPER_REG_A3_0_PAD_0_SHIFT        (0U)
#define VIRT_WRAPPER_REG_A3_0_PAD_0_WIDTH        (3U)
#define VIRT_WRAPPER_REG_A3_0_PAD_0(x)           (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A3_0_PAD_0_SHIFT)) & VIRT_WRAPPER_REG_A3_0_PAD_0_MASK)

#define VIRT_WRAPPER_REG_A3_0_PAD_1_MASK         (0x700U)
#define VIRT_WRAPPER_REG_A3_0_PAD_1_SHIFT        (8U)
#define VIRT_WRAPPER_REG_A3_0_PAD_1_WIDTH        (3U)
#define VIRT_WRAPPER_REG_A3_0_PAD_1(x)           (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A3_0_PAD_1_SHIFT)) & VIRT_WRAPPER_REG_A3_0_PAD_1_MASK)

#define VIRT_WRAPPER_REG_A3_0_PAD_2_MASK         (0x70000U)
#define VIRT_WRAPPER_REG_A3_0_PAD_2_SHIFT        (16U)
#define VIRT_WRAPPER_REG_A3_0_PAD_2_WIDTH        (3U)
#define VIRT_WRAPPER_REG_A3_0_PAD_2(x)           (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A3_0_PAD_2_SHIFT)) & VIRT_WRAPPER_REG_A3_0_PAD_2_MASK)

#define VIRT_WRAPPER_REG_A3_0_PAD_3_MASK         (0x7000000U)
#define VIRT_WRAPPER_REG_A3_0_PAD_3_SHIFT        (24U)
#define VIRT_WRAPPER_REG_A3_0_PAD_3_WIDTH        (3U)
#define VIRT_WRAPPER_REG_A3_0_PAD_3(x)           (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A3_0_PAD_3_SHIFT)) & VIRT_WRAPPER_REG_A3_0_PAD_3_MASK)
/*! @} */

/*! @name REG_A7_4 - Parameter_n Register */
/*! @{ */

#define VIRT_WRAPPER_REG_A7_4_PAD_0_MASK         (0x7U)
#define VIRT_WRAPPER_REG_A7_4_PAD_0_SHIFT        (0U)
#define VIRT_WRAPPER_REG_A7_4_PAD_0_WIDTH        (3U)
#define VIRT_WRAPPER_REG_A7_4_PAD_0(x)           (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A7_4_PAD_0_SHIFT)) & VIRT_WRAPPER_REG_A7_4_PAD_0_MASK)

#define VIRT_WRAPPER_REG_A7_4_PAD_1_MASK         (0x700U)
#define VIRT_WRAPPER_REG_A7_4_PAD_1_SHIFT        (8U)
#define VIRT_WRAPPER_REG_A7_4_PAD_1_WIDTH        (3U)
#define VIRT_WRAPPER_REG_A7_4_PAD_1(x)           (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A7_4_PAD_1_SHIFT)) & VIRT_WRAPPER_REG_A7_4_PAD_1_MASK)

#define VIRT_WRAPPER_REG_A7_4_PAD_2_MASK         (0x70000U)
#define VIRT_WRAPPER_REG_A7_4_PAD_2_SHIFT        (16U)
#define VIRT_WRAPPER_REG_A7_4_PAD_2_WIDTH        (3U)
#define VIRT_WRAPPER_REG_A7_4_PAD_2(x)           (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A7_4_PAD_2_SHIFT)) & VIRT_WRAPPER_REG_A7_4_PAD_2_MASK)

#define VIRT_WRAPPER_REG_A7_4_PAD_3_MASK         (0x7000000U)
#define VIRT_WRAPPER_REG_A7_4_PAD_3_SHIFT        (24U)
#define VIRT_WRAPPER_REG_A7_4_PAD_3_WIDTH        (3U)
#define VIRT_WRAPPER_REG_A7_4_PAD_3(x)           (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A7_4_PAD_3_SHIFT)) & VIRT_WRAPPER_REG_A7_4_PAD_3_MASK)
/*! @} */

/*! @name REG_A11_8 - Parameter_n Register */
/*! @{ */

#define VIRT_WRAPPER_REG_A11_8_PAD_0_MASK        (0x7U)
#define VIRT_WRAPPER_REG_A11_8_PAD_0_SHIFT       (0U)
#define VIRT_WRAPPER_REG_A11_8_PAD_0_WIDTH       (3U)
#define VIRT_WRAPPER_REG_A11_8_PAD_0(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A11_8_PAD_0_SHIFT)) & VIRT_WRAPPER_REG_A11_8_PAD_0_MASK)

#define VIRT_WRAPPER_REG_A11_8_PAD_1_MASK        (0x700U)
#define VIRT_WRAPPER_REG_A11_8_PAD_1_SHIFT       (8U)
#define VIRT_WRAPPER_REG_A11_8_PAD_1_WIDTH       (3U)
#define VIRT_WRAPPER_REG_A11_8_PAD_1(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A11_8_PAD_1_SHIFT)) & VIRT_WRAPPER_REG_A11_8_PAD_1_MASK)

#define VIRT_WRAPPER_REG_A11_8_PAD_2_MASK        (0x70000U)
#define VIRT_WRAPPER_REG_A11_8_PAD_2_SHIFT       (16U)
#define VIRT_WRAPPER_REG_A11_8_PAD_2_WIDTH       (3U)
#define VIRT_WRAPPER_REG_A11_8_PAD_2(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A11_8_PAD_2_SHIFT)) & VIRT_WRAPPER_REG_A11_8_PAD_2_MASK)

#define VIRT_WRAPPER_REG_A11_8_PAD_3_MASK        (0x7000000U)
#define VIRT_WRAPPER_REG_A11_8_PAD_3_SHIFT       (24U)
#define VIRT_WRAPPER_REG_A11_8_PAD_3_WIDTH       (3U)
#define VIRT_WRAPPER_REG_A11_8_PAD_3(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A11_8_PAD_3_SHIFT)) & VIRT_WRAPPER_REG_A11_8_PAD_3_MASK)
/*! @} */

/*! @name REG_A15_12 - Parameter_n Register */
/*! @{ */

#define VIRT_WRAPPER_REG_A15_12_PAD_0_MASK       (0x7U)
#define VIRT_WRAPPER_REG_A15_12_PAD_0_SHIFT      (0U)
#define VIRT_WRAPPER_REG_A15_12_PAD_0_WIDTH      (3U)
#define VIRT_WRAPPER_REG_A15_12_PAD_0(x)         (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A15_12_PAD_0_SHIFT)) & VIRT_WRAPPER_REG_A15_12_PAD_0_MASK)

#define VIRT_WRAPPER_REG_A15_12_PAD_1_MASK       (0x700U)
#define VIRT_WRAPPER_REG_A15_12_PAD_1_SHIFT      (8U)
#define VIRT_WRAPPER_REG_A15_12_PAD_1_WIDTH      (3U)
#define VIRT_WRAPPER_REG_A15_12_PAD_1(x)         (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A15_12_PAD_1_SHIFT)) & VIRT_WRAPPER_REG_A15_12_PAD_1_MASK)

#define VIRT_WRAPPER_REG_A15_12_PAD_2_MASK       (0x70000U)
#define VIRT_WRAPPER_REG_A15_12_PAD_2_SHIFT      (16U)
#define VIRT_WRAPPER_REG_A15_12_PAD_2_WIDTH      (3U)
#define VIRT_WRAPPER_REG_A15_12_PAD_2(x)         (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A15_12_PAD_2_SHIFT)) & VIRT_WRAPPER_REG_A15_12_PAD_2_MASK)

#define VIRT_WRAPPER_REG_A15_12_PAD_3_MASK       (0x7000000U)
#define VIRT_WRAPPER_REG_A15_12_PAD_3_SHIFT      (24U)
#define VIRT_WRAPPER_REG_A15_12_PAD_3_WIDTH      (3U)
#define VIRT_WRAPPER_REG_A15_12_PAD_3(x)         (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A15_12_PAD_3_SHIFT)) & VIRT_WRAPPER_REG_A15_12_PAD_3_MASK)
/*! @} */

/*! @name REG_A19_16 - Parameter_n Register */
/*! @{ */

#define VIRT_WRAPPER_REG_A19_16_PAD_0_MASK       (0x7U)
#define VIRT_WRAPPER_REG_A19_16_PAD_0_SHIFT      (0U)
#define VIRT_WRAPPER_REG_A19_16_PAD_0_WIDTH      (3U)
#define VIRT_WRAPPER_REG_A19_16_PAD_0(x)         (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A19_16_PAD_0_SHIFT)) & VIRT_WRAPPER_REG_A19_16_PAD_0_MASK)

#define VIRT_WRAPPER_REG_A19_16_PAD_1_MASK       (0x700U)
#define VIRT_WRAPPER_REG_A19_16_PAD_1_SHIFT      (8U)
#define VIRT_WRAPPER_REG_A19_16_PAD_1_WIDTH      (3U)
#define VIRT_WRAPPER_REG_A19_16_PAD_1(x)         (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A19_16_PAD_1_SHIFT)) & VIRT_WRAPPER_REG_A19_16_PAD_1_MASK)

#define VIRT_WRAPPER_REG_A19_16_PAD_2_MASK       (0x70000U)
#define VIRT_WRAPPER_REG_A19_16_PAD_2_SHIFT      (16U)
#define VIRT_WRAPPER_REG_A19_16_PAD_2_WIDTH      (3U)
#define VIRT_WRAPPER_REG_A19_16_PAD_2(x)         (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A19_16_PAD_2_SHIFT)) & VIRT_WRAPPER_REG_A19_16_PAD_2_MASK)

#define VIRT_WRAPPER_REG_A19_16_PAD_3_MASK       (0x7000000U)
#define VIRT_WRAPPER_REG_A19_16_PAD_3_SHIFT      (24U)
#define VIRT_WRAPPER_REG_A19_16_PAD_3_WIDTH      (3U)
#define VIRT_WRAPPER_REG_A19_16_PAD_3(x)         (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A19_16_PAD_3_SHIFT)) & VIRT_WRAPPER_REG_A19_16_PAD_3_MASK)
/*! @} */

/*! @name REG_A23_20 - Parameter_n Register */
/*! @{ */

#define VIRT_WRAPPER_REG_A23_20_PAD_0_MASK       (0x7U)
#define VIRT_WRAPPER_REG_A23_20_PAD_0_SHIFT      (0U)
#define VIRT_WRAPPER_REG_A23_20_PAD_0_WIDTH      (3U)
#define VIRT_WRAPPER_REG_A23_20_PAD_0(x)         (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A23_20_PAD_0_SHIFT)) & VIRT_WRAPPER_REG_A23_20_PAD_0_MASK)

#define VIRT_WRAPPER_REG_A23_20_PAD_1_MASK       (0x700U)
#define VIRT_WRAPPER_REG_A23_20_PAD_1_SHIFT      (8U)
#define VIRT_WRAPPER_REG_A23_20_PAD_1_WIDTH      (3U)
#define VIRT_WRAPPER_REG_A23_20_PAD_1(x)         (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A23_20_PAD_1_SHIFT)) & VIRT_WRAPPER_REG_A23_20_PAD_1_MASK)

#define VIRT_WRAPPER_REG_A23_20_PAD_2_MASK       (0x70000U)
#define VIRT_WRAPPER_REG_A23_20_PAD_2_SHIFT      (16U)
#define VIRT_WRAPPER_REG_A23_20_PAD_2_WIDTH      (3U)
#define VIRT_WRAPPER_REG_A23_20_PAD_2(x)         (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A23_20_PAD_2_SHIFT)) & VIRT_WRAPPER_REG_A23_20_PAD_2_MASK)

#define VIRT_WRAPPER_REG_A23_20_PAD_3_MASK       (0x7000000U)
#define VIRT_WRAPPER_REG_A23_20_PAD_3_SHIFT      (24U)
#define VIRT_WRAPPER_REG_A23_20_PAD_3_WIDTH      (3U)
#define VIRT_WRAPPER_REG_A23_20_PAD_3(x)         (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A23_20_PAD_3_SHIFT)) & VIRT_WRAPPER_REG_A23_20_PAD_3_MASK)
/*! @} */

/*! @name REG_A27_24 - Parameter_n Register */
/*! @{ */

#define VIRT_WRAPPER_REG_A27_24_PAD_0_MASK       (0x7U)
#define VIRT_WRAPPER_REG_A27_24_PAD_0_SHIFT      (0U)
#define VIRT_WRAPPER_REG_A27_24_PAD_0_WIDTH      (3U)
#define VIRT_WRAPPER_REG_A27_24_PAD_0(x)         (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A27_24_PAD_0_SHIFT)) & VIRT_WRAPPER_REG_A27_24_PAD_0_MASK)

#define VIRT_WRAPPER_REG_A27_24_PAD_1_MASK       (0x700U)
#define VIRT_WRAPPER_REG_A27_24_PAD_1_SHIFT      (8U)
#define VIRT_WRAPPER_REG_A27_24_PAD_1_WIDTH      (3U)
#define VIRT_WRAPPER_REG_A27_24_PAD_1(x)         (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A27_24_PAD_1_SHIFT)) & VIRT_WRAPPER_REG_A27_24_PAD_1_MASK)

#define VIRT_WRAPPER_REG_A27_24_PAD_2_MASK       (0x70000U)
#define VIRT_WRAPPER_REG_A27_24_PAD_2_SHIFT      (16U)
#define VIRT_WRAPPER_REG_A27_24_PAD_2_WIDTH      (3U)
#define VIRT_WRAPPER_REG_A27_24_PAD_2(x)         (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A27_24_PAD_2_SHIFT)) & VIRT_WRAPPER_REG_A27_24_PAD_2_MASK)

#define VIRT_WRAPPER_REG_A27_24_PAD_3_MASK       (0x7000000U)
#define VIRT_WRAPPER_REG_A27_24_PAD_3_SHIFT      (24U)
#define VIRT_WRAPPER_REG_A27_24_PAD_3_WIDTH      (3U)
#define VIRT_WRAPPER_REG_A27_24_PAD_3(x)         (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A27_24_PAD_3_SHIFT)) & VIRT_WRAPPER_REG_A27_24_PAD_3_MASK)
/*! @} */

/*! @name REG_A31_28 - Parameter_n Register */
/*! @{ */

#define VIRT_WRAPPER_REG_A31_28_PAD_0_MASK       (0x7U)
#define VIRT_WRAPPER_REG_A31_28_PAD_0_SHIFT      (0U)
#define VIRT_WRAPPER_REG_A31_28_PAD_0_WIDTH      (3U)
#define VIRT_WRAPPER_REG_A31_28_PAD_0(x)         (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A31_28_PAD_0_SHIFT)) & VIRT_WRAPPER_REG_A31_28_PAD_0_MASK)

#define VIRT_WRAPPER_REG_A31_28_PAD_1_MASK       (0x700U)
#define VIRT_WRAPPER_REG_A31_28_PAD_1_SHIFT      (8U)
#define VIRT_WRAPPER_REG_A31_28_PAD_1_WIDTH      (3U)
#define VIRT_WRAPPER_REG_A31_28_PAD_1(x)         (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A31_28_PAD_1_SHIFT)) & VIRT_WRAPPER_REG_A31_28_PAD_1_MASK)

#define VIRT_WRAPPER_REG_A31_28_PAD_2_MASK       (0x70000U)
#define VIRT_WRAPPER_REG_A31_28_PAD_2_SHIFT      (16U)
#define VIRT_WRAPPER_REG_A31_28_PAD_2_WIDTH      (3U)
#define VIRT_WRAPPER_REG_A31_28_PAD_2(x)         (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A31_28_PAD_2_SHIFT)) & VIRT_WRAPPER_REG_A31_28_PAD_2_MASK)

#define VIRT_WRAPPER_REG_A31_28_PAD_3_MASK       (0x7000000U)
#define VIRT_WRAPPER_REG_A31_28_PAD_3_SHIFT      (24U)
#define VIRT_WRAPPER_REG_A31_28_PAD_3_WIDTH      (3U)
#define VIRT_WRAPPER_REG_A31_28_PAD_3(x)         (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A31_28_PAD_3_SHIFT)) & VIRT_WRAPPER_REG_A31_28_PAD_3_MASK)
/*! @} */

/*! @name REG_A35_32 - Parameter_n Register */
/*! @{ */

#define VIRT_WRAPPER_REG_A35_32_PAD_0_MASK       (0x7U)
#define VIRT_WRAPPER_REG_A35_32_PAD_0_SHIFT      (0U)
#define VIRT_WRAPPER_REG_A35_32_PAD_0_WIDTH      (3U)
#define VIRT_WRAPPER_REG_A35_32_PAD_0(x)         (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A35_32_PAD_0_SHIFT)) & VIRT_WRAPPER_REG_A35_32_PAD_0_MASK)

#define VIRT_WRAPPER_REG_A35_32_PAD_1_MASK       (0x700U)
#define VIRT_WRAPPER_REG_A35_32_PAD_1_SHIFT      (8U)
#define VIRT_WRAPPER_REG_A35_32_PAD_1_WIDTH      (3U)
#define VIRT_WRAPPER_REG_A35_32_PAD_1(x)         (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A35_32_PAD_1_SHIFT)) & VIRT_WRAPPER_REG_A35_32_PAD_1_MASK)

#define VIRT_WRAPPER_REG_A35_32_PAD_2_MASK       (0x70000U)
#define VIRT_WRAPPER_REG_A35_32_PAD_2_SHIFT      (16U)
#define VIRT_WRAPPER_REG_A35_32_PAD_2_WIDTH      (3U)
#define VIRT_WRAPPER_REG_A35_32_PAD_2(x)         (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A35_32_PAD_2_SHIFT)) & VIRT_WRAPPER_REG_A35_32_PAD_2_MASK)

#define VIRT_WRAPPER_REG_A35_32_PAD_3_MASK       (0x7000000U)
#define VIRT_WRAPPER_REG_A35_32_PAD_3_SHIFT      (24U)
#define VIRT_WRAPPER_REG_A35_32_PAD_3_WIDTH      (3U)
#define VIRT_WRAPPER_REG_A35_32_PAD_3(x)         (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A35_32_PAD_3_SHIFT)) & VIRT_WRAPPER_REG_A35_32_PAD_3_MASK)
/*! @} */

/*! @name REG_A39_36 - Parameter_n Register */
/*! @{ */

#define VIRT_WRAPPER_REG_A39_36_PAD_0_MASK       (0x7U)
#define VIRT_WRAPPER_REG_A39_36_PAD_0_SHIFT      (0U)
#define VIRT_WRAPPER_REG_A39_36_PAD_0_WIDTH      (3U)
#define VIRT_WRAPPER_REG_A39_36_PAD_0(x)         (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A39_36_PAD_0_SHIFT)) & VIRT_WRAPPER_REG_A39_36_PAD_0_MASK)

#define VIRT_WRAPPER_REG_A39_36_PAD_1_MASK       (0x700U)
#define VIRT_WRAPPER_REG_A39_36_PAD_1_SHIFT      (8U)
#define VIRT_WRAPPER_REG_A39_36_PAD_1_WIDTH      (3U)
#define VIRT_WRAPPER_REG_A39_36_PAD_1(x)         (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A39_36_PAD_1_SHIFT)) & VIRT_WRAPPER_REG_A39_36_PAD_1_MASK)
/*! @} */

/*! @name REG_A43_40 - Parameter_n Register */
/*! @{ */

#define VIRT_WRAPPER_REG_A43_40_PAD_0_MASK       (0x7U)
#define VIRT_WRAPPER_REG_A43_40_PAD_0_SHIFT      (0U)
#define VIRT_WRAPPER_REG_A43_40_PAD_0_WIDTH      (3U)
#define VIRT_WRAPPER_REG_A43_40_PAD_0(x)         (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A43_40_PAD_0_SHIFT)) & VIRT_WRAPPER_REG_A43_40_PAD_0_MASK)

#define VIRT_WRAPPER_REG_A43_40_PAD_1_MASK       (0x700U)
#define VIRT_WRAPPER_REG_A43_40_PAD_1_SHIFT      (8U)
#define VIRT_WRAPPER_REG_A43_40_PAD_1_WIDTH      (3U)
#define VIRT_WRAPPER_REG_A43_40_PAD_1(x)         (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A43_40_PAD_1_SHIFT)) & VIRT_WRAPPER_REG_A43_40_PAD_1_MASK)

#define VIRT_WRAPPER_REG_A43_40_PAD_2_MASK       (0x70000U)
#define VIRT_WRAPPER_REG_A43_40_PAD_2_SHIFT      (16U)
#define VIRT_WRAPPER_REG_A43_40_PAD_2_WIDTH      (3U)
#define VIRT_WRAPPER_REG_A43_40_PAD_2(x)         (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A43_40_PAD_2_SHIFT)) & VIRT_WRAPPER_REG_A43_40_PAD_2_MASK)

#define VIRT_WRAPPER_REG_A43_40_PAD_3_MASK       (0x7000000U)
#define VIRT_WRAPPER_REG_A43_40_PAD_3_SHIFT      (24U)
#define VIRT_WRAPPER_REG_A43_40_PAD_3_WIDTH      (3U)
#define VIRT_WRAPPER_REG_A43_40_PAD_3(x)         (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A43_40_PAD_3_SHIFT)) & VIRT_WRAPPER_REG_A43_40_PAD_3_MASK)
/*! @} */

/*! @name REG_A47_44 - Parameter_n Register */
/*! @{ */

#define VIRT_WRAPPER_REG_A47_44_PAD_0_MASK       (0x7U)
#define VIRT_WRAPPER_REG_A47_44_PAD_0_SHIFT      (0U)
#define VIRT_WRAPPER_REG_A47_44_PAD_0_WIDTH      (3U)
#define VIRT_WRAPPER_REG_A47_44_PAD_0(x)         (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A47_44_PAD_0_SHIFT)) & VIRT_WRAPPER_REG_A47_44_PAD_0_MASK)

#define VIRT_WRAPPER_REG_A47_44_PAD_1_MASK       (0x700U)
#define VIRT_WRAPPER_REG_A47_44_PAD_1_SHIFT      (8U)
#define VIRT_WRAPPER_REG_A47_44_PAD_1_WIDTH      (3U)
#define VIRT_WRAPPER_REG_A47_44_PAD_1(x)         (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A47_44_PAD_1_SHIFT)) & VIRT_WRAPPER_REG_A47_44_PAD_1_MASK)

#define VIRT_WRAPPER_REG_A47_44_PAD_2_MASK       (0x70000U)
#define VIRT_WRAPPER_REG_A47_44_PAD_2_SHIFT      (16U)
#define VIRT_WRAPPER_REG_A47_44_PAD_2_WIDTH      (3U)
#define VIRT_WRAPPER_REG_A47_44_PAD_2(x)         (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A47_44_PAD_2_SHIFT)) & VIRT_WRAPPER_REG_A47_44_PAD_2_MASK)

#define VIRT_WRAPPER_REG_A47_44_PAD_3_MASK       (0x7000000U)
#define VIRT_WRAPPER_REG_A47_44_PAD_3_SHIFT      (24U)
#define VIRT_WRAPPER_REG_A47_44_PAD_3_WIDTH      (3U)
#define VIRT_WRAPPER_REG_A47_44_PAD_3(x)         (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A47_44_PAD_3_SHIFT)) & VIRT_WRAPPER_REG_A47_44_PAD_3_MASK)
/*! @} */

/*! @name REG_A51_48 - Parameter_n Register */
/*! @{ */

#define VIRT_WRAPPER_REG_A51_48_PAD_0_MASK       (0x7U)
#define VIRT_WRAPPER_REG_A51_48_PAD_0_SHIFT      (0U)
#define VIRT_WRAPPER_REG_A51_48_PAD_0_WIDTH      (3U)
#define VIRT_WRAPPER_REG_A51_48_PAD_0(x)         (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A51_48_PAD_0_SHIFT)) & VIRT_WRAPPER_REG_A51_48_PAD_0_MASK)

#define VIRT_WRAPPER_REG_A51_48_PAD_1_MASK       (0x700U)
#define VIRT_WRAPPER_REG_A51_48_PAD_1_SHIFT      (8U)
#define VIRT_WRAPPER_REG_A51_48_PAD_1_WIDTH      (3U)
#define VIRT_WRAPPER_REG_A51_48_PAD_1(x)         (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A51_48_PAD_1_SHIFT)) & VIRT_WRAPPER_REG_A51_48_PAD_1_MASK)

#define VIRT_WRAPPER_REG_A51_48_PAD_2_MASK       (0x70000U)
#define VIRT_WRAPPER_REG_A51_48_PAD_2_SHIFT      (16U)
#define VIRT_WRAPPER_REG_A51_48_PAD_2_WIDTH      (3U)
#define VIRT_WRAPPER_REG_A51_48_PAD_2(x)         (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A51_48_PAD_2_SHIFT)) & VIRT_WRAPPER_REG_A51_48_PAD_2_MASK)

#define VIRT_WRAPPER_REG_A51_48_PAD_3_MASK       (0x7000000U)
#define VIRT_WRAPPER_REG_A51_48_PAD_3_SHIFT      (24U)
#define VIRT_WRAPPER_REG_A51_48_PAD_3_WIDTH      (3U)
#define VIRT_WRAPPER_REG_A51_48_PAD_3(x)         (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A51_48_PAD_3_SHIFT)) & VIRT_WRAPPER_REG_A51_48_PAD_3_MASK)
/*! @} */

/*! @name REG_A55_52 - Parameter_n Register */
/*! @{ */

#define VIRT_WRAPPER_REG_A55_52_PAD_0_MASK       (0x7U)
#define VIRT_WRAPPER_REG_A55_52_PAD_0_SHIFT      (0U)
#define VIRT_WRAPPER_REG_A55_52_PAD_0_WIDTH      (3U)
#define VIRT_WRAPPER_REG_A55_52_PAD_0(x)         (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A55_52_PAD_0_SHIFT)) & VIRT_WRAPPER_REG_A55_52_PAD_0_MASK)

#define VIRT_WRAPPER_REG_A55_52_PAD_1_MASK       (0x700U)
#define VIRT_WRAPPER_REG_A55_52_PAD_1_SHIFT      (8U)
#define VIRT_WRAPPER_REG_A55_52_PAD_1_WIDTH      (3U)
#define VIRT_WRAPPER_REG_A55_52_PAD_1(x)         (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A55_52_PAD_1_SHIFT)) & VIRT_WRAPPER_REG_A55_52_PAD_1_MASK)

#define VIRT_WRAPPER_REG_A55_52_PAD_2_MASK       (0x70000U)
#define VIRT_WRAPPER_REG_A55_52_PAD_2_SHIFT      (16U)
#define VIRT_WRAPPER_REG_A55_52_PAD_2_WIDTH      (3U)
#define VIRT_WRAPPER_REG_A55_52_PAD_2(x)         (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A55_52_PAD_2_SHIFT)) & VIRT_WRAPPER_REG_A55_52_PAD_2_MASK)

#define VIRT_WRAPPER_REG_A55_52_PAD_3_MASK       (0x7000000U)
#define VIRT_WRAPPER_REG_A55_52_PAD_3_SHIFT      (24U)
#define VIRT_WRAPPER_REG_A55_52_PAD_3_WIDTH      (3U)
#define VIRT_WRAPPER_REG_A55_52_PAD_3(x)         (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A55_52_PAD_3_SHIFT)) & VIRT_WRAPPER_REG_A55_52_PAD_3_MASK)
/*! @} */

/*! @name REG_A59_56 - Parameter_n Register */
/*! @{ */

#define VIRT_WRAPPER_REG_A59_56_PAD_0_MASK       (0x7U)
#define VIRT_WRAPPER_REG_A59_56_PAD_0_SHIFT      (0U)
#define VIRT_WRAPPER_REG_A59_56_PAD_0_WIDTH      (3U)
#define VIRT_WRAPPER_REG_A59_56_PAD_0(x)         (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A59_56_PAD_0_SHIFT)) & VIRT_WRAPPER_REG_A59_56_PAD_0_MASK)

#define VIRT_WRAPPER_REG_A59_56_PAD_1_MASK       (0x700U)
#define VIRT_WRAPPER_REG_A59_56_PAD_1_SHIFT      (8U)
#define VIRT_WRAPPER_REG_A59_56_PAD_1_WIDTH      (3U)
#define VIRT_WRAPPER_REG_A59_56_PAD_1(x)         (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A59_56_PAD_1_SHIFT)) & VIRT_WRAPPER_REG_A59_56_PAD_1_MASK)

#define VIRT_WRAPPER_REG_A59_56_PAD_2_MASK       (0x70000U)
#define VIRT_WRAPPER_REG_A59_56_PAD_2_SHIFT      (16U)
#define VIRT_WRAPPER_REG_A59_56_PAD_2_WIDTH      (3U)
#define VIRT_WRAPPER_REG_A59_56_PAD_2(x)         (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A59_56_PAD_2_SHIFT)) & VIRT_WRAPPER_REG_A59_56_PAD_2_MASK)

#define VIRT_WRAPPER_REG_A59_56_PAD_3_MASK       (0x7000000U)
#define VIRT_WRAPPER_REG_A59_56_PAD_3_SHIFT      (24U)
#define VIRT_WRAPPER_REG_A59_56_PAD_3_WIDTH      (3U)
#define VIRT_WRAPPER_REG_A59_56_PAD_3(x)         (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A59_56_PAD_3_SHIFT)) & VIRT_WRAPPER_REG_A59_56_PAD_3_MASK)
/*! @} */

/*! @name REG_A63_60 - Parameter_n Register */
/*! @{ */

#define VIRT_WRAPPER_REG_A63_60_PAD_0_MASK       (0x7U)
#define VIRT_WRAPPER_REG_A63_60_PAD_0_SHIFT      (0U)
#define VIRT_WRAPPER_REG_A63_60_PAD_0_WIDTH      (3U)
#define VIRT_WRAPPER_REG_A63_60_PAD_0(x)         (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A63_60_PAD_0_SHIFT)) & VIRT_WRAPPER_REG_A63_60_PAD_0_MASK)

#define VIRT_WRAPPER_REG_A63_60_PAD_1_MASK       (0x700U)
#define VIRT_WRAPPER_REG_A63_60_PAD_1_SHIFT      (8U)
#define VIRT_WRAPPER_REG_A63_60_PAD_1_WIDTH      (3U)
#define VIRT_WRAPPER_REG_A63_60_PAD_1(x)         (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A63_60_PAD_1_SHIFT)) & VIRT_WRAPPER_REG_A63_60_PAD_1_MASK)

#define VIRT_WRAPPER_REG_A63_60_PAD_2_MASK       (0x70000U)
#define VIRT_WRAPPER_REG_A63_60_PAD_2_SHIFT      (16U)
#define VIRT_WRAPPER_REG_A63_60_PAD_2_WIDTH      (3U)
#define VIRT_WRAPPER_REG_A63_60_PAD_2(x)         (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A63_60_PAD_2_SHIFT)) & VIRT_WRAPPER_REG_A63_60_PAD_2_MASK)

#define VIRT_WRAPPER_REG_A63_60_PAD_3_MASK       (0x7000000U)
#define VIRT_WRAPPER_REG_A63_60_PAD_3_SHIFT      (24U)
#define VIRT_WRAPPER_REG_A63_60_PAD_3_WIDTH      (3U)
#define VIRT_WRAPPER_REG_A63_60_PAD_3(x)         (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A63_60_PAD_3_SHIFT)) & VIRT_WRAPPER_REG_A63_60_PAD_3_MASK)
/*! @} */

/*! @name REG_A67_64 - Parameter_n Register */
/*! @{ */

#define VIRT_WRAPPER_REG_A67_64_PAD_0_MASK       (0x7U)
#define VIRT_WRAPPER_REG_A67_64_PAD_0_SHIFT      (0U)
#define VIRT_WRAPPER_REG_A67_64_PAD_0_WIDTH      (3U)
#define VIRT_WRAPPER_REG_A67_64_PAD_0(x)         (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A67_64_PAD_0_SHIFT)) & VIRT_WRAPPER_REG_A67_64_PAD_0_MASK)

#define VIRT_WRAPPER_REG_A67_64_PAD_1_MASK       (0x700U)
#define VIRT_WRAPPER_REG_A67_64_PAD_1_SHIFT      (8U)
#define VIRT_WRAPPER_REG_A67_64_PAD_1_WIDTH      (3U)
#define VIRT_WRAPPER_REG_A67_64_PAD_1(x)         (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A67_64_PAD_1_SHIFT)) & VIRT_WRAPPER_REG_A67_64_PAD_1_MASK)

#define VIRT_WRAPPER_REG_A67_64_PAD_2_MASK       (0x70000U)
#define VIRT_WRAPPER_REG_A67_64_PAD_2_SHIFT      (16U)
#define VIRT_WRAPPER_REG_A67_64_PAD_2_WIDTH      (3U)
#define VIRT_WRAPPER_REG_A67_64_PAD_2(x)         (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A67_64_PAD_2_SHIFT)) & VIRT_WRAPPER_REG_A67_64_PAD_2_MASK)

#define VIRT_WRAPPER_REG_A67_64_PAD_3_MASK       (0x7000000U)
#define VIRT_WRAPPER_REG_A67_64_PAD_3_SHIFT      (24U)
#define VIRT_WRAPPER_REG_A67_64_PAD_3_WIDTH      (3U)
#define VIRT_WRAPPER_REG_A67_64_PAD_3(x)         (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A67_64_PAD_3_SHIFT)) & VIRT_WRAPPER_REG_A67_64_PAD_3_MASK)
/*! @} */

/*! @name REG_A71_68 - Parameter_n Register */
/*! @{ */

#define VIRT_WRAPPER_REG_A71_68_PAD_0_MASK       (0x7U)
#define VIRT_WRAPPER_REG_A71_68_PAD_0_SHIFT      (0U)
#define VIRT_WRAPPER_REG_A71_68_PAD_0_WIDTH      (3U)
#define VIRT_WRAPPER_REG_A71_68_PAD_0(x)         (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A71_68_PAD_0_SHIFT)) & VIRT_WRAPPER_REG_A71_68_PAD_0_MASK)

#define VIRT_WRAPPER_REG_A71_68_PAD_1_MASK       (0x700U)
#define VIRT_WRAPPER_REG_A71_68_PAD_1_SHIFT      (8U)
#define VIRT_WRAPPER_REG_A71_68_PAD_1_WIDTH      (3U)
#define VIRT_WRAPPER_REG_A71_68_PAD_1(x)         (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A71_68_PAD_1_SHIFT)) & VIRT_WRAPPER_REG_A71_68_PAD_1_MASK)

#define VIRT_WRAPPER_REG_A71_68_PAD_2_MASK       (0x70000U)
#define VIRT_WRAPPER_REG_A71_68_PAD_2_SHIFT      (16U)
#define VIRT_WRAPPER_REG_A71_68_PAD_2_WIDTH      (3U)
#define VIRT_WRAPPER_REG_A71_68_PAD_2(x)         (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A71_68_PAD_2_SHIFT)) & VIRT_WRAPPER_REG_A71_68_PAD_2_MASK)

#define VIRT_WRAPPER_REG_A71_68_PAD_3_MASK       (0x7000000U)
#define VIRT_WRAPPER_REG_A71_68_PAD_3_SHIFT      (24U)
#define VIRT_WRAPPER_REG_A71_68_PAD_3_WIDTH      (3U)
#define VIRT_WRAPPER_REG_A71_68_PAD_3(x)         (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A71_68_PAD_3_SHIFT)) & VIRT_WRAPPER_REG_A71_68_PAD_3_MASK)
/*! @} */

/*! @name REG_A75_72 - Parameter_n Register */
/*! @{ */

#define VIRT_WRAPPER_REG_A75_72_PAD_0_MASK       (0x7U)
#define VIRT_WRAPPER_REG_A75_72_PAD_0_SHIFT      (0U)
#define VIRT_WRAPPER_REG_A75_72_PAD_0_WIDTH      (3U)
#define VIRT_WRAPPER_REG_A75_72_PAD_0(x)         (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A75_72_PAD_0_SHIFT)) & VIRT_WRAPPER_REG_A75_72_PAD_0_MASK)

#define VIRT_WRAPPER_REG_A75_72_PAD_1_MASK       (0x700U)
#define VIRT_WRAPPER_REG_A75_72_PAD_1_SHIFT      (8U)
#define VIRT_WRAPPER_REG_A75_72_PAD_1_WIDTH      (3U)
#define VIRT_WRAPPER_REG_A75_72_PAD_1(x)         (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A75_72_PAD_1_SHIFT)) & VIRT_WRAPPER_REG_A75_72_PAD_1_MASK)

#define VIRT_WRAPPER_REG_A75_72_PAD_2_MASK       (0x70000U)
#define VIRT_WRAPPER_REG_A75_72_PAD_2_SHIFT      (16U)
#define VIRT_WRAPPER_REG_A75_72_PAD_2_WIDTH      (3U)
#define VIRT_WRAPPER_REG_A75_72_PAD_2(x)         (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A75_72_PAD_2_SHIFT)) & VIRT_WRAPPER_REG_A75_72_PAD_2_MASK)

#define VIRT_WRAPPER_REG_A75_72_PAD_3_MASK       (0x7000000U)
#define VIRT_WRAPPER_REG_A75_72_PAD_3_SHIFT      (24U)
#define VIRT_WRAPPER_REG_A75_72_PAD_3_WIDTH      (3U)
#define VIRT_WRAPPER_REG_A75_72_PAD_3(x)         (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A75_72_PAD_3_SHIFT)) & VIRT_WRAPPER_REG_A75_72_PAD_3_MASK)
/*! @} */

/*! @name REG_A79_76 - Parameter_n Register */
/*! @{ */

#define VIRT_WRAPPER_REG_A79_76_PAD_0_MASK       (0x7U)
#define VIRT_WRAPPER_REG_A79_76_PAD_0_SHIFT      (0U)
#define VIRT_WRAPPER_REG_A79_76_PAD_0_WIDTH      (3U)
#define VIRT_WRAPPER_REG_A79_76_PAD_0(x)         (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A79_76_PAD_0_SHIFT)) & VIRT_WRAPPER_REG_A79_76_PAD_0_MASK)

#define VIRT_WRAPPER_REG_A79_76_PAD_1_MASK       (0x700U)
#define VIRT_WRAPPER_REG_A79_76_PAD_1_SHIFT      (8U)
#define VIRT_WRAPPER_REG_A79_76_PAD_1_WIDTH      (3U)
#define VIRT_WRAPPER_REG_A79_76_PAD_1(x)         (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A79_76_PAD_1_SHIFT)) & VIRT_WRAPPER_REG_A79_76_PAD_1_MASK)

#define VIRT_WRAPPER_REG_A79_76_PAD_2_MASK       (0x70000U)
#define VIRT_WRAPPER_REG_A79_76_PAD_2_SHIFT      (16U)
#define VIRT_WRAPPER_REG_A79_76_PAD_2_WIDTH      (3U)
#define VIRT_WRAPPER_REG_A79_76_PAD_2(x)         (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A79_76_PAD_2_SHIFT)) & VIRT_WRAPPER_REG_A79_76_PAD_2_MASK)

#define VIRT_WRAPPER_REG_A79_76_PAD_3_MASK       (0x7000000U)
#define VIRT_WRAPPER_REG_A79_76_PAD_3_SHIFT      (24U)
#define VIRT_WRAPPER_REG_A79_76_PAD_3_WIDTH      (3U)
#define VIRT_WRAPPER_REG_A79_76_PAD_3(x)         (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A79_76_PAD_3_SHIFT)) & VIRT_WRAPPER_REG_A79_76_PAD_3_MASK)
/*! @} */

/*! @name REG_A83_80 - Parameter_n Register */
/*! @{ */

#define VIRT_WRAPPER_REG_A83_80_PAD_0_MASK       (0x7U)
#define VIRT_WRAPPER_REG_A83_80_PAD_0_SHIFT      (0U)
#define VIRT_WRAPPER_REG_A83_80_PAD_0_WIDTH      (3U)
#define VIRT_WRAPPER_REG_A83_80_PAD_0(x)         (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A83_80_PAD_0_SHIFT)) & VIRT_WRAPPER_REG_A83_80_PAD_0_MASK)

#define VIRT_WRAPPER_REG_A83_80_PAD_1_MASK       (0x700U)
#define VIRT_WRAPPER_REG_A83_80_PAD_1_SHIFT      (8U)
#define VIRT_WRAPPER_REG_A83_80_PAD_1_WIDTH      (3U)
#define VIRT_WRAPPER_REG_A83_80_PAD_1(x)         (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A83_80_PAD_1_SHIFT)) & VIRT_WRAPPER_REG_A83_80_PAD_1_MASK)

#define VIRT_WRAPPER_REG_A83_80_PAD_2_MASK       (0x70000U)
#define VIRT_WRAPPER_REG_A83_80_PAD_2_SHIFT      (16U)
#define VIRT_WRAPPER_REG_A83_80_PAD_2_WIDTH      (3U)
#define VIRT_WRAPPER_REG_A83_80_PAD_2(x)         (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A83_80_PAD_2_SHIFT)) & VIRT_WRAPPER_REG_A83_80_PAD_2_MASK)

#define VIRT_WRAPPER_REG_A83_80_PAD_3_MASK       (0x7000000U)
#define VIRT_WRAPPER_REG_A83_80_PAD_3_SHIFT      (24U)
#define VIRT_WRAPPER_REG_A83_80_PAD_3_WIDTH      (3U)
#define VIRT_WRAPPER_REG_A83_80_PAD_3(x)         (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A83_80_PAD_3_SHIFT)) & VIRT_WRAPPER_REG_A83_80_PAD_3_MASK)
/*! @} */

/*! @name REG_A87_84 - Parameter_n Register */
/*! @{ */

#define VIRT_WRAPPER_REG_A87_84_PAD_0_MASK       (0x7U)
#define VIRT_WRAPPER_REG_A87_84_PAD_0_SHIFT      (0U)
#define VIRT_WRAPPER_REG_A87_84_PAD_0_WIDTH      (3U)
#define VIRT_WRAPPER_REG_A87_84_PAD_0(x)         (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A87_84_PAD_0_SHIFT)) & VIRT_WRAPPER_REG_A87_84_PAD_0_MASK)

#define VIRT_WRAPPER_REG_A87_84_PAD_1_MASK       (0x700U)
#define VIRT_WRAPPER_REG_A87_84_PAD_1_SHIFT      (8U)
#define VIRT_WRAPPER_REG_A87_84_PAD_1_WIDTH      (3U)
#define VIRT_WRAPPER_REG_A87_84_PAD_1(x)         (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A87_84_PAD_1_SHIFT)) & VIRT_WRAPPER_REG_A87_84_PAD_1_MASK)

#define VIRT_WRAPPER_REG_A87_84_PAD_2_MASK       (0x70000U)
#define VIRT_WRAPPER_REG_A87_84_PAD_2_SHIFT      (16U)
#define VIRT_WRAPPER_REG_A87_84_PAD_2_WIDTH      (3U)
#define VIRT_WRAPPER_REG_A87_84_PAD_2(x)         (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A87_84_PAD_2_SHIFT)) & VIRT_WRAPPER_REG_A87_84_PAD_2_MASK)

#define VIRT_WRAPPER_REG_A87_84_PAD_3_MASK       (0x7000000U)
#define VIRT_WRAPPER_REG_A87_84_PAD_3_SHIFT      (24U)
#define VIRT_WRAPPER_REG_A87_84_PAD_3_WIDTH      (3U)
#define VIRT_WRAPPER_REG_A87_84_PAD_3(x)         (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A87_84_PAD_3_SHIFT)) & VIRT_WRAPPER_REG_A87_84_PAD_3_MASK)
/*! @} */

/*! @name REG_A91_88 - Parameter_n Register */
/*! @{ */

#define VIRT_WRAPPER_REG_A91_88_PAD_0_MASK       (0x7U)
#define VIRT_WRAPPER_REG_A91_88_PAD_0_SHIFT      (0U)
#define VIRT_WRAPPER_REG_A91_88_PAD_0_WIDTH      (3U)
#define VIRT_WRAPPER_REG_A91_88_PAD_0(x)         (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A91_88_PAD_0_SHIFT)) & VIRT_WRAPPER_REG_A91_88_PAD_0_MASK)

#define VIRT_WRAPPER_REG_A91_88_PAD_1_MASK       (0x700U)
#define VIRT_WRAPPER_REG_A91_88_PAD_1_SHIFT      (8U)
#define VIRT_WRAPPER_REG_A91_88_PAD_1_WIDTH      (3U)
#define VIRT_WRAPPER_REG_A91_88_PAD_1(x)         (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A91_88_PAD_1_SHIFT)) & VIRT_WRAPPER_REG_A91_88_PAD_1_MASK)

#define VIRT_WRAPPER_REG_A91_88_PAD_2_MASK       (0x70000U)
#define VIRT_WRAPPER_REG_A91_88_PAD_2_SHIFT      (16U)
#define VIRT_WRAPPER_REG_A91_88_PAD_2_WIDTH      (3U)
#define VIRT_WRAPPER_REG_A91_88_PAD_2(x)         (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A91_88_PAD_2_SHIFT)) & VIRT_WRAPPER_REG_A91_88_PAD_2_MASK)

#define VIRT_WRAPPER_REG_A91_88_PAD_3_MASK       (0x7000000U)
#define VIRT_WRAPPER_REG_A91_88_PAD_3_SHIFT      (24U)
#define VIRT_WRAPPER_REG_A91_88_PAD_3_WIDTH      (3U)
#define VIRT_WRAPPER_REG_A91_88_PAD_3(x)         (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A91_88_PAD_3_SHIFT)) & VIRT_WRAPPER_REG_A91_88_PAD_3_MASK)
/*! @} */

/*! @name REG_A95_92 - Parameter_n Register */
/*! @{ */

#define VIRT_WRAPPER_REG_A95_92_PAD_0_MASK       (0x7U)
#define VIRT_WRAPPER_REG_A95_92_PAD_0_SHIFT      (0U)
#define VIRT_WRAPPER_REG_A95_92_PAD_0_WIDTH      (3U)
#define VIRT_WRAPPER_REG_A95_92_PAD_0(x)         (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A95_92_PAD_0_SHIFT)) & VIRT_WRAPPER_REG_A95_92_PAD_0_MASK)

#define VIRT_WRAPPER_REG_A95_92_PAD_1_MASK       (0x700U)
#define VIRT_WRAPPER_REG_A95_92_PAD_1_SHIFT      (8U)
#define VIRT_WRAPPER_REG_A95_92_PAD_1_WIDTH      (3U)
#define VIRT_WRAPPER_REG_A95_92_PAD_1(x)         (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A95_92_PAD_1_SHIFT)) & VIRT_WRAPPER_REG_A95_92_PAD_1_MASK)

#define VIRT_WRAPPER_REG_A95_92_PAD_2_MASK       (0x70000U)
#define VIRT_WRAPPER_REG_A95_92_PAD_2_SHIFT      (16U)
#define VIRT_WRAPPER_REG_A95_92_PAD_2_WIDTH      (3U)
#define VIRT_WRAPPER_REG_A95_92_PAD_2(x)         (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A95_92_PAD_2_SHIFT)) & VIRT_WRAPPER_REG_A95_92_PAD_2_MASK)

#define VIRT_WRAPPER_REG_A95_92_PAD_3_MASK       (0x7000000U)
#define VIRT_WRAPPER_REG_A95_92_PAD_3_SHIFT      (24U)
#define VIRT_WRAPPER_REG_A95_92_PAD_3_WIDTH      (3U)
#define VIRT_WRAPPER_REG_A95_92_PAD_3(x)         (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A95_92_PAD_3_SHIFT)) & VIRT_WRAPPER_REG_A95_92_PAD_3_MASK)
/*! @} */

/*! @name REG_A99_96 - Parameter_n Register */
/*! @{ */

#define VIRT_WRAPPER_REG_A99_96_PAD_0_MASK       (0x7U)
#define VIRT_WRAPPER_REG_A99_96_PAD_0_SHIFT      (0U)
#define VIRT_WRAPPER_REG_A99_96_PAD_0_WIDTH      (3U)
#define VIRT_WRAPPER_REG_A99_96_PAD_0(x)         (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A99_96_PAD_0_SHIFT)) & VIRT_WRAPPER_REG_A99_96_PAD_0_MASK)

#define VIRT_WRAPPER_REG_A99_96_PAD_1_MASK       (0x700U)
#define VIRT_WRAPPER_REG_A99_96_PAD_1_SHIFT      (8U)
#define VIRT_WRAPPER_REG_A99_96_PAD_1_WIDTH      (3U)
#define VIRT_WRAPPER_REG_A99_96_PAD_1(x)         (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A99_96_PAD_1_SHIFT)) & VIRT_WRAPPER_REG_A99_96_PAD_1_MASK)

#define VIRT_WRAPPER_REG_A99_96_PAD_2_MASK       (0x70000U)
#define VIRT_WRAPPER_REG_A99_96_PAD_2_SHIFT      (16U)
#define VIRT_WRAPPER_REG_A99_96_PAD_2_WIDTH      (3U)
#define VIRT_WRAPPER_REG_A99_96_PAD_2(x)         (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A99_96_PAD_2_SHIFT)) & VIRT_WRAPPER_REG_A99_96_PAD_2_MASK)

#define VIRT_WRAPPER_REG_A99_96_PAD_3_MASK       (0x7000000U)
#define VIRT_WRAPPER_REG_A99_96_PAD_3_SHIFT      (24U)
#define VIRT_WRAPPER_REG_A99_96_PAD_3_WIDTH      (3U)
#define VIRT_WRAPPER_REG_A99_96_PAD_3(x)         (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A99_96_PAD_3_SHIFT)) & VIRT_WRAPPER_REG_A99_96_PAD_3_MASK)
/*! @} */

/*! @name REG_A103_100 - Parameter_n Register */
/*! @{ */

#define VIRT_WRAPPER_REG_A103_100_PAD_0_MASK     (0x7U)
#define VIRT_WRAPPER_REG_A103_100_PAD_0_SHIFT    (0U)
#define VIRT_WRAPPER_REG_A103_100_PAD_0_WIDTH    (3U)
#define VIRT_WRAPPER_REG_A103_100_PAD_0(x)       (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A103_100_PAD_0_SHIFT)) & VIRT_WRAPPER_REG_A103_100_PAD_0_MASK)

#define VIRT_WRAPPER_REG_A103_100_PAD_1_MASK     (0x700U)
#define VIRT_WRAPPER_REG_A103_100_PAD_1_SHIFT    (8U)
#define VIRT_WRAPPER_REG_A103_100_PAD_1_WIDTH    (3U)
#define VIRT_WRAPPER_REG_A103_100_PAD_1(x)       (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A103_100_PAD_1_SHIFT)) & VIRT_WRAPPER_REG_A103_100_PAD_1_MASK)

#define VIRT_WRAPPER_REG_A103_100_PAD_2_MASK     (0x70000U)
#define VIRT_WRAPPER_REG_A103_100_PAD_2_SHIFT    (16U)
#define VIRT_WRAPPER_REG_A103_100_PAD_2_WIDTH    (3U)
#define VIRT_WRAPPER_REG_A103_100_PAD_2(x)       (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A103_100_PAD_2_SHIFT)) & VIRT_WRAPPER_REG_A103_100_PAD_2_MASK)

#define VIRT_WRAPPER_REG_A103_100_PAD_3_MASK     (0x7000000U)
#define VIRT_WRAPPER_REG_A103_100_PAD_3_SHIFT    (24U)
#define VIRT_WRAPPER_REG_A103_100_PAD_3_WIDTH    (3U)
#define VIRT_WRAPPER_REG_A103_100_PAD_3(x)       (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A103_100_PAD_3_SHIFT)) & VIRT_WRAPPER_REG_A103_100_PAD_3_MASK)
/*! @} */

/*! @name REG_A107_104 - Parameter_n Register */
/*! @{ */

#define VIRT_WRAPPER_REG_A107_104_PAD_0_MASK     (0x7U)
#define VIRT_WRAPPER_REG_A107_104_PAD_0_SHIFT    (0U)
#define VIRT_WRAPPER_REG_A107_104_PAD_0_WIDTH    (3U)
#define VIRT_WRAPPER_REG_A107_104_PAD_0(x)       (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A107_104_PAD_0_SHIFT)) & VIRT_WRAPPER_REG_A107_104_PAD_0_MASK)

#define VIRT_WRAPPER_REG_A107_104_PAD_1_MASK     (0x700U)
#define VIRT_WRAPPER_REG_A107_104_PAD_1_SHIFT    (8U)
#define VIRT_WRAPPER_REG_A107_104_PAD_1_WIDTH    (3U)
#define VIRT_WRAPPER_REG_A107_104_PAD_1(x)       (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A107_104_PAD_1_SHIFT)) & VIRT_WRAPPER_REG_A107_104_PAD_1_MASK)

#define VIRT_WRAPPER_REG_A107_104_PAD_2_MASK     (0x70000U)
#define VIRT_WRAPPER_REG_A107_104_PAD_2_SHIFT    (16U)
#define VIRT_WRAPPER_REG_A107_104_PAD_2_WIDTH    (3U)
#define VIRT_WRAPPER_REG_A107_104_PAD_2(x)       (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A107_104_PAD_2_SHIFT)) & VIRT_WRAPPER_REG_A107_104_PAD_2_MASK)

#define VIRT_WRAPPER_REG_A107_104_PAD_3_MASK     (0x7000000U)
#define VIRT_WRAPPER_REG_A107_104_PAD_3_SHIFT    (24U)
#define VIRT_WRAPPER_REG_A107_104_PAD_3_WIDTH    (3U)
#define VIRT_WRAPPER_REG_A107_104_PAD_3(x)       (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A107_104_PAD_3_SHIFT)) & VIRT_WRAPPER_REG_A107_104_PAD_3_MASK)
/*! @} */

/*! @name REG_A111_108 - Parameter_n Register */
/*! @{ */

#define VIRT_WRAPPER_REG_A111_108_PAD_0_MASK     (0x7U)
#define VIRT_WRAPPER_REG_A111_108_PAD_0_SHIFT    (0U)
#define VIRT_WRAPPER_REG_A111_108_PAD_0_WIDTH    (3U)
#define VIRT_WRAPPER_REG_A111_108_PAD_0(x)       (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A111_108_PAD_0_SHIFT)) & VIRT_WRAPPER_REG_A111_108_PAD_0_MASK)

#define VIRT_WRAPPER_REG_A111_108_PAD_1_MASK     (0x700U)
#define VIRT_WRAPPER_REG_A111_108_PAD_1_SHIFT    (8U)
#define VIRT_WRAPPER_REG_A111_108_PAD_1_WIDTH    (3U)
#define VIRT_WRAPPER_REG_A111_108_PAD_1(x)       (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A111_108_PAD_1_SHIFT)) & VIRT_WRAPPER_REG_A111_108_PAD_1_MASK)

#define VIRT_WRAPPER_REG_A111_108_PAD_2_MASK     (0x70000U)
#define VIRT_WRAPPER_REG_A111_108_PAD_2_SHIFT    (16U)
#define VIRT_WRAPPER_REG_A111_108_PAD_2_WIDTH    (3U)
#define VIRT_WRAPPER_REG_A111_108_PAD_2(x)       (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A111_108_PAD_2_SHIFT)) & VIRT_WRAPPER_REG_A111_108_PAD_2_MASK)

#define VIRT_WRAPPER_REG_A111_108_PAD_3_MASK     (0x7000000U)
#define VIRT_WRAPPER_REG_A111_108_PAD_3_SHIFT    (24U)
#define VIRT_WRAPPER_REG_A111_108_PAD_3_WIDTH    (3U)
#define VIRT_WRAPPER_REG_A111_108_PAD_3(x)       (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A111_108_PAD_3_SHIFT)) & VIRT_WRAPPER_REG_A111_108_PAD_3_MASK)
/*! @} */

/*! @name REG_A115_112 - Parameter_n Register */
/*! @{ */

#define VIRT_WRAPPER_REG_A115_112_PAD_0_MASK     (0x7U)
#define VIRT_WRAPPER_REG_A115_112_PAD_0_SHIFT    (0U)
#define VIRT_WRAPPER_REG_A115_112_PAD_0_WIDTH    (3U)
#define VIRT_WRAPPER_REG_A115_112_PAD_0(x)       (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A115_112_PAD_0_SHIFT)) & VIRT_WRAPPER_REG_A115_112_PAD_0_MASK)

#define VIRT_WRAPPER_REG_A115_112_PAD_1_MASK     (0x700U)
#define VIRT_WRAPPER_REG_A115_112_PAD_1_SHIFT    (8U)
#define VIRT_WRAPPER_REG_A115_112_PAD_1_WIDTH    (3U)
#define VIRT_WRAPPER_REG_A115_112_PAD_1(x)       (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A115_112_PAD_1_SHIFT)) & VIRT_WRAPPER_REG_A115_112_PAD_1_MASK)

#define VIRT_WRAPPER_REG_A115_112_PAD_2_MASK     (0x70000U)
#define VIRT_WRAPPER_REG_A115_112_PAD_2_SHIFT    (16U)
#define VIRT_WRAPPER_REG_A115_112_PAD_2_WIDTH    (3U)
#define VIRT_WRAPPER_REG_A115_112_PAD_2(x)       (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A115_112_PAD_2_SHIFT)) & VIRT_WRAPPER_REG_A115_112_PAD_2_MASK)

#define VIRT_WRAPPER_REG_A115_112_PAD_3_MASK     (0x7000000U)
#define VIRT_WRAPPER_REG_A115_112_PAD_3_SHIFT    (24U)
#define VIRT_WRAPPER_REG_A115_112_PAD_3_WIDTH    (3U)
#define VIRT_WRAPPER_REG_A115_112_PAD_3(x)       (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A115_112_PAD_3_SHIFT)) & VIRT_WRAPPER_REG_A115_112_PAD_3_MASK)
/*! @} */

/*! @name REG_A119_116 - Parameter_n Register */
/*! @{ */

#define VIRT_WRAPPER_REG_A119_116_PAD_0_MASK     (0x7U)
#define VIRT_WRAPPER_REG_A119_116_PAD_0_SHIFT    (0U)
#define VIRT_WRAPPER_REG_A119_116_PAD_0_WIDTH    (3U)
#define VIRT_WRAPPER_REG_A119_116_PAD_0(x)       (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A119_116_PAD_0_SHIFT)) & VIRT_WRAPPER_REG_A119_116_PAD_0_MASK)

#define VIRT_WRAPPER_REG_A119_116_PAD_1_MASK     (0x700U)
#define VIRT_WRAPPER_REG_A119_116_PAD_1_SHIFT    (8U)
#define VIRT_WRAPPER_REG_A119_116_PAD_1_WIDTH    (3U)
#define VIRT_WRAPPER_REG_A119_116_PAD_1(x)       (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A119_116_PAD_1_SHIFT)) & VIRT_WRAPPER_REG_A119_116_PAD_1_MASK)

#define VIRT_WRAPPER_REG_A119_116_PAD_2_MASK     (0x70000U)
#define VIRT_WRAPPER_REG_A119_116_PAD_2_SHIFT    (16U)
#define VIRT_WRAPPER_REG_A119_116_PAD_2_WIDTH    (3U)
#define VIRT_WRAPPER_REG_A119_116_PAD_2(x)       (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A119_116_PAD_2_SHIFT)) & VIRT_WRAPPER_REG_A119_116_PAD_2_MASK)

#define VIRT_WRAPPER_REG_A119_116_PAD_3_MASK     (0x7000000U)
#define VIRT_WRAPPER_REG_A119_116_PAD_3_SHIFT    (24U)
#define VIRT_WRAPPER_REG_A119_116_PAD_3_WIDTH    (3U)
#define VIRT_WRAPPER_REG_A119_116_PAD_3(x)       (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A119_116_PAD_3_SHIFT)) & VIRT_WRAPPER_REG_A119_116_PAD_3_MASK)
/*! @} */

/*! @name REG_A123_120 - Parameter_n Register */
/*! @{ */

#define VIRT_WRAPPER_REG_A123_120_PAD_0_MASK     (0x7U)
#define VIRT_WRAPPER_REG_A123_120_PAD_0_SHIFT    (0U)
#define VIRT_WRAPPER_REG_A123_120_PAD_0_WIDTH    (3U)
#define VIRT_WRAPPER_REG_A123_120_PAD_0(x)       (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A123_120_PAD_0_SHIFT)) & VIRT_WRAPPER_REG_A123_120_PAD_0_MASK)

#define VIRT_WRAPPER_REG_A123_120_PAD_1_MASK     (0x700U)
#define VIRT_WRAPPER_REG_A123_120_PAD_1_SHIFT    (8U)
#define VIRT_WRAPPER_REG_A123_120_PAD_1_WIDTH    (3U)
#define VIRT_WRAPPER_REG_A123_120_PAD_1(x)       (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A123_120_PAD_1_SHIFT)) & VIRT_WRAPPER_REG_A123_120_PAD_1_MASK)

#define VIRT_WRAPPER_REG_A123_120_PAD_2_MASK     (0x70000U)
#define VIRT_WRAPPER_REG_A123_120_PAD_2_SHIFT    (16U)
#define VIRT_WRAPPER_REG_A123_120_PAD_2_WIDTH    (3U)
#define VIRT_WRAPPER_REG_A123_120_PAD_2(x)       (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A123_120_PAD_2_SHIFT)) & VIRT_WRAPPER_REG_A123_120_PAD_2_MASK)

#define VIRT_WRAPPER_REG_A123_120_PAD_3_MASK     (0x7000000U)
#define VIRT_WRAPPER_REG_A123_120_PAD_3_SHIFT    (24U)
#define VIRT_WRAPPER_REG_A123_120_PAD_3_WIDTH    (3U)
#define VIRT_WRAPPER_REG_A123_120_PAD_3(x)       (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A123_120_PAD_3_SHIFT)) & VIRT_WRAPPER_REG_A123_120_PAD_3_MASK)
/*! @} */

/*! @name REG_A127_124 - Parameter_n Register */
/*! @{ */

#define VIRT_WRAPPER_REG_A127_124_PAD_0_MASK     (0x7U)
#define VIRT_WRAPPER_REG_A127_124_PAD_0_SHIFT    (0U)
#define VIRT_WRAPPER_REG_A127_124_PAD_0_WIDTH    (3U)
#define VIRT_WRAPPER_REG_A127_124_PAD_0(x)       (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A127_124_PAD_0_SHIFT)) & VIRT_WRAPPER_REG_A127_124_PAD_0_MASK)

#define VIRT_WRAPPER_REG_A127_124_PAD_1_MASK     (0x700U)
#define VIRT_WRAPPER_REG_A127_124_PAD_1_SHIFT    (8U)
#define VIRT_WRAPPER_REG_A127_124_PAD_1_WIDTH    (3U)
#define VIRT_WRAPPER_REG_A127_124_PAD_1(x)       (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A127_124_PAD_1_SHIFT)) & VIRT_WRAPPER_REG_A127_124_PAD_1_MASK)

#define VIRT_WRAPPER_REG_A127_124_PAD_2_MASK     (0x70000U)
#define VIRT_WRAPPER_REG_A127_124_PAD_2_SHIFT    (16U)
#define VIRT_WRAPPER_REG_A127_124_PAD_2_WIDTH    (3U)
#define VIRT_WRAPPER_REG_A127_124_PAD_2(x)       (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A127_124_PAD_2_SHIFT)) & VIRT_WRAPPER_REG_A127_124_PAD_2_MASK)

#define VIRT_WRAPPER_REG_A127_124_PAD_3_MASK     (0x7000000U)
#define VIRT_WRAPPER_REG_A127_124_PAD_3_SHIFT    (24U)
#define VIRT_WRAPPER_REG_A127_124_PAD_3_WIDTH    (3U)
#define VIRT_WRAPPER_REG_A127_124_PAD_3(x)       (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A127_124_PAD_3_SHIFT)) & VIRT_WRAPPER_REG_A127_124_PAD_3_MASK)
/*! @} */

/*! @name REG_A131_128 - Parameter_n Register */
/*! @{ */

#define VIRT_WRAPPER_REG_A131_128_PAD_0_MASK     (0x7U)
#define VIRT_WRAPPER_REG_A131_128_PAD_0_SHIFT    (0U)
#define VIRT_WRAPPER_REG_A131_128_PAD_0_WIDTH    (3U)
#define VIRT_WRAPPER_REG_A131_128_PAD_0(x)       (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A131_128_PAD_0_SHIFT)) & VIRT_WRAPPER_REG_A131_128_PAD_0_MASK)

#define VIRT_WRAPPER_REG_A131_128_PAD_1_MASK     (0x700U)
#define VIRT_WRAPPER_REG_A131_128_PAD_1_SHIFT    (8U)
#define VIRT_WRAPPER_REG_A131_128_PAD_1_WIDTH    (3U)
#define VIRT_WRAPPER_REG_A131_128_PAD_1(x)       (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A131_128_PAD_1_SHIFT)) & VIRT_WRAPPER_REG_A131_128_PAD_1_MASK)

#define VIRT_WRAPPER_REG_A131_128_PAD_2_MASK     (0x70000U)
#define VIRT_WRAPPER_REG_A131_128_PAD_2_SHIFT    (16U)
#define VIRT_WRAPPER_REG_A131_128_PAD_2_WIDTH    (3U)
#define VIRT_WRAPPER_REG_A131_128_PAD_2(x)       (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A131_128_PAD_2_SHIFT)) & VIRT_WRAPPER_REG_A131_128_PAD_2_MASK)

#define VIRT_WRAPPER_REG_A131_128_PAD_3_MASK     (0x7000000U)
#define VIRT_WRAPPER_REG_A131_128_PAD_3_SHIFT    (24U)
#define VIRT_WRAPPER_REG_A131_128_PAD_3_WIDTH    (3U)
#define VIRT_WRAPPER_REG_A131_128_PAD_3(x)       (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A131_128_PAD_3_SHIFT)) & VIRT_WRAPPER_REG_A131_128_PAD_3_MASK)
/*! @} */

/*! @name REG_A135_132 - Parameter_n Register */
/*! @{ */

#define VIRT_WRAPPER_REG_A135_132_PAD_0_MASK     (0x7U)
#define VIRT_WRAPPER_REG_A135_132_PAD_0_SHIFT    (0U)
#define VIRT_WRAPPER_REG_A135_132_PAD_0_WIDTH    (3U)
#define VIRT_WRAPPER_REG_A135_132_PAD_0(x)       (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A135_132_PAD_0_SHIFT)) & VIRT_WRAPPER_REG_A135_132_PAD_0_MASK)

#define VIRT_WRAPPER_REG_A135_132_PAD_1_MASK     (0x700U)
#define VIRT_WRAPPER_REG_A135_132_PAD_1_SHIFT    (8U)
#define VIRT_WRAPPER_REG_A135_132_PAD_1_WIDTH    (3U)
#define VIRT_WRAPPER_REG_A135_132_PAD_1(x)       (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A135_132_PAD_1_SHIFT)) & VIRT_WRAPPER_REG_A135_132_PAD_1_MASK)

#define VIRT_WRAPPER_REG_A135_132_PAD_2_MASK     (0x70000U)
#define VIRT_WRAPPER_REG_A135_132_PAD_2_SHIFT    (16U)
#define VIRT_WRAPPER_REG_A135_132_PAD_2_WIDTH    (3U)
#define VIRT_WRAPPER_REG_A135_132_PAD_2(x)       (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A135_132_PAD_2_SHIFT)) & VIRT_WRAPPER_REG_A135_132_PAD_2_MASK)

#define VIRT_WRAPPER_REG_A135_132_PAD_3_MASK     (0x7000000U)
#define VIRT_WRAPPER_REG_A135_132_PAD_3_SHIFT    (24U)
#define VIRT_WRAPPER_REG_A135_132_PAD_3_WIDTH    (3U)
#define VIRT_WRAPPER_REG_A135_132_PAD_3(x)       (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A135_132_PAD_3_SHIFT)) & VIRT_WRAPPER_REG_A135_132_PAD_3_MASK)
/*! @} */

/*! @name REG_A139_136 - Parameter_n Register */
/*! @{ */

#define VIRT_WRAPPER_REG_A139_136_PAD_0_MASK     (0x7U)
#define VIRT_WRAPPER_REG_A139_136_PAD_0_SHIFT    (0U)
#define VIRT_WRAPPER_REG_A139_136_PAD_0_WIDTH    (3U)
#define VIRT_WRAPPER_REG_A139_136_PAD_0(x)       (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A139_136_PAD_0_SHIFT)) & VIRT_WRAPPER_REG_A139_136_PAD_0_MASK)

#define VIRT_WRAPPER_REG_A139_136_PAD_1_MASK     (0x700U)
#define VIRT_WRAPPER_REG_A139_136_PAD_1_SHIFT    (8U)
#define VIRT_WRAPPER_REG_A139_136_PAD_1_WIDTH    (3U)
#define VIRT_WRAPPER_REG_A139_136_PAD_1(x)       (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A139_136_PAD_1_SHIFT)) & VIRT_WRAPPER_REG_A139_136_PAD_1_MASK)

#define VIRT_WRAPPER_REG_A139_136_PAD_2_MASK     (0x70000U)
#define VIRT_WRAPPER_REG_A139_136_PAD_2_SHIFT    (16U)
#define VIRT_WRAPPER_REG_A139_136_PAD_2_WIDTH    (3U)
#define VIRT_WRAPPER_REG_A139_136_PAD_2(x)       (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A139_136_PAD_2_SHIFT)) & VIRT_WRAPPER_REG_A139_136_PAD_2_MASK)

#define VIRT_WRAPPER_REG_A139_136_PAD_3_MASK     (0x7000000U)
#define VIRT_WRAPPER_REG_A139_136_PAD_3_SHIFT    (24U)
#define VIRT_WRAPPER_REG_A139_136_PAD_3_WIDTH    (3U)
#define VIRT_WRAPPER_REG_A139_136_PAD_3(x)       (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A139_136_PAD_3_SHIFT)) & VIRT_WRAPPER_REG_A139_136_PAD_3_MASK)
/*! @} */

/*! @name REG_A143_140 - Parameter_n Register */
/*! @{ */

#define VIRT_WRAPPER_REG_A143_140_PAD_0_MASK     (0x7U)
#define VIRT_WRAPPER_REG_A143_140_PAD_0_SHIFT    (0U)
#define VIRT_WRAPPER_REG_A143_140_PAD_0_WIDTH    (3U)
#define VIRT_WRAPPER_REG_A143_140_PAD_0(x)       (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A143_140_PAD_0_SHIFT)) & VIRT_WRAPPER_REG_A143_140_PAD_0_MASK)

#define VIRT_WRAPPER_REG_A143_140_PAD_2_MASK     (0x70000U)
#define VIRT_WRAPPER_REG_A143_140_PAD_2_SHIFT    (16U)
#define VIRT_WRAPPER_REG_A143_140_PAD_2_WIDTH    (3U)
#define VIRT_WRAPPER_REG_A143_140_PAD_2(x)       (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A143_140_PAD_2_SHIFT)) & VIRT_WRAPPER_REG_A143_140_PAD_2_MASK)

#define VIRT_WRAPPER_REG_A143_140_PAD_3_MASK     (0x7000000U)
#define VIRT_WRAPPER_REG_A143_140_PAD_3_SHIFT    (24U)
#define VIRT_WRAPPER_REG_A143_140_PAD_3_WIDTH    (3U)
#define VIRT_WRAPPER_REG_A143_140_PAD_3(x)       (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A143_140_PAD_3_SHIFT)) & VIRT_WRAPPER_REG_A143_140_PAD_3_MASK)
/*! @} */

/*! @name REG_A147_144 - Parameter_n Register */
/*! @{ */

#define VIRT_WRAPPER_REG_A147_144_PAD_0_MASK     (0x7U)
#define VIRT_WRAPPER_REG_A147_144_PAD_0_SHIFT    (0U)
#define VIRT_WRAPPER_REG_A147_144_PAD_0_WIDTH    (3U)
#define VIRT_WRAPPER_REG_A147_144_PAD_0(x)       (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A147_144_PAD_0_SHIFT)) & VIRT_WRAPPER_REG_A147_144_PAD_0_MASK)

#define VIRT_WRAPPER_REG_A147_144_PAD_1_MASK     (0x700U)
#define VIRT_WRAPPER_REG_A147_144_PAD_1_SHIFT    (8U)
#define VIRT_WRAPPER_REG_A147_144_PAD_1_WIDTH    (3U)
#define VIRT_WRAPPER_REG_A147_144_PAD_1(x)       (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A147_144_PAD_1_SHIFT)) & VIRT_WRAPPER_REG_A147_144_PAD_1_MASK)

#define VIRT_WRAPPER_REG_A147_144_PAD_2_MASK     (0x70000U)
#define VIRT_WRAPPER_REG_A147_144_PAD_2_SHIFT    (16U)
#define VIRT_WRAPPER_REG_A147_144_PAD_2_WIDTH    (3U)
#define VIRT_WRAPPER_REG_A147_144_PAD_2(x)       (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A147_144_PAD_2_SHIFT)) & VIRT_WRAPPER_REG_A147_144_PAD_2_MASK)

#define VIRT_WRAPPER_REG_A147_144_PAD_3_MASK     (0x7000000U)
#define VIRT_WRAPPER_REG_A147_144_PAD_3_SHIFT    (24U)
#define VIRT_WRAPPER_REG_A147_144_PAD_3_WIDTH    (3U)
#define VIRT_WRAPPER_REG_A147_144_PAD_3(x)       (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A147_144_PAD_3_SHIFT)) & VIRT_WRAPPER_REG_A147_144_PAD_3_MASK)
/*! @} */

/*! @name REG_A151_148 - Parameter_n Register */
/*! @{ */

#define VIRT_WRAPPER_REG_A151_148_PAD_0_MASK     (0x7U)
#define VIRT_WRAPPER_REG_A151_148_PAD_0_SHIFT    (0U)
#define VIRT_WRAPPER_REG_A151_148_PAD_0_WIDTH    (3U)
#define VIRT_WRAPPER_REG_A151_148_PAD_0(x)       (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A151_148_PAD_0_SHIFT)) & VIRT_WRAPPER_REG_A151_148_PAD_0_MASK)

#define VIRT_WRAPPER_REG_A151_148_PAD_1_MASK     (0x700U)
#define VIRT_WRAPPER_REG_A151_148_PAD_1_SHIFT    (8U)
#define VIRT_WRAPPER_REG_A151_148_PAD_1_WIDTH    (3U)
#define VIRT_WRAPPER_REG_A151_148_PAD_1(x)       (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A151_148_PAD_1_SHIFT)) & VIRT_WRAPPER_REG_A151_148_PAD_1_MASK)

#define VIRT_WRAPPER_REG_A151_148_PAD_2_MASK     (0x70000U)
#define VIRT_WRAPPER_REG_A151_148_PAD_2_SHIFT    (16U)
#define VIRT_WRAPPER_REG_A151_148_PAD_2_WIDTH    (3U)
#define VIRT_WRAPPER_REG_A151_148_PAD_2(x)       (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A151_148_PAD_2_SHIFT)) & VIRT_WRAPPER_REG_A151_148_PAD_2_MASK)

#define VIRT_WRAPPER_REG_A151_148_PAD_3_MASK     (0x7000000U)
#define VIRT_WRAPPER_REG_A151_148_PAD_3_SHIFT    (24U)
#define VIRT_WRAPPER_REG_A151_148_PAD_3_WIDTH    (3U)
#define VIRT_WRAPPER_REG_A151_148_PAD_3(x)       (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A151_148_PAD_3_SHIFT)) & VIRT_WRAPPER_REG_A151_148_PAD_3_MASK)
/*! @} */

/*! @name REG_A155_152 - Parameter_n Register */
/*! @{ */

#define VIRT_WRAPPER_REG_A155_152_PAD_0_MASK     (0x7U)
#define VIRT_WRAPPER_REG_A155_152_PAD_0_SHIFT    (0U)
#define VIRT_WRAPPER_REG_A155_152_PAD_0_WIDTH    (3U)
#define VIRT_WRAPPER_REG_A155_152_PAD_0(x)       (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A155_152_PAD_0_SHIFT)) & VIRT_WRAPPER_REG_A155_152_PAD_0_MASK)

#define VIRT_WRAPPER_REG_A155_152_PAD_1_MASK     (0x700U)
#define VIRT_WRAPPER_REG_A155_152_PAD_1_SHIFT    (8U)
#define VIRT_WRAPPER_REG_A155_152_PAD_1_WIDTH    (3U)
#define VIRT_WRAPPER_REG_A155_152_PAD_1(x)       (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A155_152_PAD_1_SHIFT)) & VIRT_WRAPPER_REG_A155_152_PAD_1_MASK)

#define VIRT_WRAPPER_REG_A155_152_PAD_2_MASK     (0x70000U)
#define VIRT_WRAPPER_REG_A155_152_PAD_2_SHIFT    (16U)
#define VIRT_WRAPPER_REG_A155_152_PAD_2_WIDTH    (3U)
#define VIRT_WRAPPER_REG_A155_152_PAD_2(x)       (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A155_152_PAD_2_SHIFT)) & VIRT_WRAPPER_REG_A155_152_PAD_2_MASK)

#define VIRT_WRAPPER_REG_A155_152_PAD_3_MASK     (0x7000000U)
#define VIRT_WRAPPER_REG_A155_152_PAD_3_SHIFT    (24U)
#define VIRT_WRAPPER_REG_A155_152_PAD_3_WIDTH    (3U)
#define VIRT_WRAPPER_REG_A155_152_PAD_3(x)       (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A155_152_PAD_3_SHIFT)) & VIRT_WRAPPER_REG_A155_152_PAD_3_MASK)
/*! @} */

/*! @name REG_A159_156 - Parameter_n Register */
/*! @{ */

#define VIRT_WRAPPER_REG_A159_156_PAD_0_MASK     (0x7U)
#define VIRT_WRAPPER_REG_A159_156_PAD_0_SHIFT    (0U)
#define VIRT_WRAPPER_REG_A159_156_PAD_0_WIDTH    (3U)
#define VIRT_WRAPPER_REG_A159_156_PAD_0(x)       (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A159_156_PAD_0_SHIFT)) & VIRT_WRAPPER_REG_A159_156_PAD_0_MASK)

#define VIRT_WRAPPER_REG_A159_156_PAD_1_MASK     (0x700U)
#define VIRT_WRAPPER_REG_A159_156_PAD_1_SHIFT    (8U)
#define VIRT_WRAPPER_REG_A159_156_PAD_1_WIDTH    (3U)
#define VIRT_WRAPPER_REG_A159_156_PAD_1(x)       (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A159_156_PAD_1_SHIFT)) & VIRT_WRAPPER_REG_A159_156_PAD_1_MASK)

#define VIRT_WRAPPER_REG_A159_156_PAD_2_MASK     (0x70000U)
#define VIRT_WRAPPER_REG_A159_156_PAD_2_SHIFT    (16U)
#define VIRT_WRAPPER_REG_A159_156_PAD_2_WIDTH    (3U)
#define VIRT_WRAPPER_REG_A159_156_PAD_2(x)       (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A159_156_PAD_2_SHIFT)) & VIRT_WRAPPER_REG_A159_156_PAD_2_MASK)

#define VIRT_WRAPPER_REG_A159_156_PAD_3_MASK     (0x7000000U)
#define VIRT_WRAPPER_REG_A159_156_PAD_3_SHIFT    (24U)
#define VIRT_WRAPPER_REG_A159_156_PAD_3_WIDTH    (3U)
#define VIRT_WRAPPER_REG_A159_156_PAD_3(x)       (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A159_156_PAD_3_SHIFT)) & VIRT_WRAPPER_REG_A159_156_PAD_3_MASK)
/*! @} */

/*! @name REG_A163_160 - Parameter_n Register */
/*! @{ */

#define VIRT_WRAPPER_REG_A163_160_PAD_0_MASK     (0x7U)
#define VIRT_WRAPPER_REG_A163_160_PAD_0_SHIFT    (0U)
#define VIRT_WRAPPER_REG_A163_160_PAD_0_WIDTH    (3U)
#define VIRT_WRAPPER_REG_A163_160_PAD_0(x)       (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A163_160_PAD_0_SHIFT)) & VIRT_WRAPPER_REG_A163_160_PAD_0_MASK)

#define VIRT_WRAPPER_REG_A163_160_PAD_1_MASK     (0x700U)
#define VIRT_WRAPPER_REG_A163_160_PAD_1_SHIFT    (8U)
#define VIRT_WRAPPER_REG_A163_160_PAD_1_WIDTH    (3U)
#define VIRT_WRAPPER_REG_A163_160_PAD_1(x)       (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A163_160_PAD_1_SHIFT)) & VIRT_WRAPPER_REG_A163_160_PAD_1_MASK)

#define VIRT_WRAPPER_REG_A163_160_PAD_2_MASK     (0x70000U)
#define VIRT_WRAPPER_REG_A163_160_PAD_2_SHIFT    (16U)
#define VIRT_WRAPPER_REG_A163_160_PAD_2_WIDTH    (3U)
#define VIRT_WRAPPER_REG_A163_160_PAD_2(x)       (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A163_160_PAD_2_SHIFT)) & VIRT_WRAPPER_REG_A163_160_PAD_2_MASK)

#define VIRT_WRAPPER_REG_A163_160_PAD_3_MASK     (0x7000000U)
#define VIRT_WRAPPER_REG_A163_160_PAD_3_SHIFT    (24U)
#define VIRT_WRAPPER_REG_A163_160_PAD_3_WIDTH    (3U)
#define VIRT_WRAPPER_REG_A163_160_PAD_3(x)       (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A163_160_PAD_3_SHIFT)) & VIRT_WRAPPER_REG_A163_160_PAD_3_MASK)
/*! @} */

/*! @name REG_A167_164 - Parameter_n Register */
/*! @{ */

#define VIRT_WRAPPER_REG_A167_164_PAD_0_MASK     (0x7U)
#define VIRT_WRAPPER_REG_A167_164_PAD_0_SHIFT    (0U)
#define VIRT_WRAPPER_REG_A167_164_PAD_0_WIDTH    (3U)
#define VIRT_WRAPPER_REG_A167_164_PAD_0(x)       (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A167_164_PAD_0_SHIFT)) & VIRT_WRAPPER_REG_A167_164_PAD_0_MASK)

#define VIRT_WRAPPER_REG_A167_164_PAD_1_MASK     (0x700U)
#define VIRT_WRAPPER_REG_A167_164_PAD_1_SHIFT    (8U)
#define VIRT_WRAPPER_REG_A167_164_PAD_1_WIDTH    (3U)
#define VIRT_WRAPPER_REG_A167_164_PAD_1(x)       (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A167_164_PAD_1_SHIFT)) & VIRT_WRAPPER_REG_A167_164_PAD_1_MASK)

#define VIRT_WRAPPER_REG_A167_164_PAD_2_MASK     (0x70000U)
#define VIRT_WRAPPER_REG_A167_164_PAD_2_SHIFT    (16U)
#define VIRT_WRAPPER_REG_A167_164_PAD_2_WIDTH    (3U)
#define VIRT_WRAPPER_REG_A167_164_PAD_2(x)       (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A167_164_PAD_2_SHIFT)) & VIRT_WRAPPER_REG_A167_164_PAD_2_MASK)

#define VIRT_WRAPPER_REG_A167_164_PAD_3_MASK     (0x7000000U)
#define VIRT_WRAPPER_REG_A167_164_PAD_3_SHIFT    (24U)
#define VIRT_WRAPPER_REG_A167_164_PAD_3_WIDTH    (3U)
#define VIRT_WRAPPER_REG_A167_164_PAD_3(x)       (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A167_164_PAD_3_SHIFT)) & VIRT_WRAPPER_REG_A167_164_PAD_3_MASK)
/*! @} */

/*! @name REG_A171_168 - Parameter_n Register */
/*! @{ */

#define VIRT_WRAPPER_REG_A171_168_PAD_0_MASK     (0x7U)
#define VIRT_WRAPPER_REG_A171_168_PAD_0_SHIFT    (0U)
#define VIRT_WRAPPER_REG_A171_168_PAD_0_WIDTH    (3U)
#define VIRT_WRAPPER_REG_A171_168_PAD_0(x)       (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A171_168_PAD_0_SHIFT)) & VIRT_WRAPPER_REG_A171_168_PAD_0_MASK)

#define VIRT_WRAPPER_REG_A171_168_PAD_1_MASK     (0x700U)
#define VIRT_WRAPPER_REG_A171_168_PAD_1_SHIFT    (8U)
#define VIRT_WRAPPER_REG_A171_168_PAD_1_WIDTH    (3U)
#define VIRT_WRAPPER_REG_A171_168_PAD_1(x)       (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A171_168_PAD_1_SHIFT)) & VIRT_WRAPPER_REG_A171_168_PAD_1_MASK)

#define VIRT_WRAPPER_REG_A171_168_PAD_2_MASK     (0x70000U)
#define VIRT_WRAPPER_REG_A171_168_PAD_2_SHIFT    (16U)
#define VIRT_WRAPPER_REG_A171_168_PAD_2_WIDTH    (3U)
#define VIRT_WRAPPER_REG_A171_168_PAD_2(x)       (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A171_168_PAD_2_SHIFT)) & VIRT_WRAPPER_REG_A171_168_PAD_2_MASK)

#define VIRT_WRAPPER_REG_A171_168_PAD_3_MASK     (0x7000000U)
#define VIRT_WRAPPER_REG_A171_168_PAD_3_SHIFT    (24U)
#define VIRT_WRAPPER_REG_A171_168_PAD_3_WIDTH    (3U)
#define VIRT_WRAPPER_REG_A171_168_PAD_3(x)       (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A171_168_PAD_3_SHIFT)) & VIRT_WRAPPER_REG_A171_168_PAD_3_MASK)
/*! @} */

/*! @name REG_A175_172 - Parameter_n Register */
/*! @{ */

#define VIRT_WRAPPER_REG_A175_172_PAD_0_MASK     (0x7U)
#define VIRT_WRAPPER_REG_A175_172_PAD_0_SHIFT    (0U)
#define VIRT_WRAPPER_REG_A175_172_PAD_0_WIDTH    (3U)
#define VIRT_WRAPPER_REG_A175_172_PAD_0(x)       (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A175_172_PAD_0_SHIFT)) & VIRT_WRAPPER_REG_A175_172_PAD_0_MASK)

#define VIRT_WRAPPER_REG_A175_172_PAD_1_MASK     (0x700U)
#define VIRT_WRAPPER_REG_A175_172_PAD_1_SHIFT    (8U)
#define VIRT_WRAPPER_REG_A175_172_PAD_1_WIDTH    (3U)
#define VIRT_WRAPPER_REG_A175_172_PAD_1(x)       (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A175_172_PAD_1_SHIFT)) & VIRT_WRAPPER_REG_A175_172_PAD_1_MASK)

#define VIRT_WRAPPER_REG_A175_172_PAD_2_MASK     (0x70000U)
#define VIRT_WRAPPER_REG_A175_172_PAD_2_SHIFT    (16U)
#define VIRT_WRAPPER_REG_A175_172_PAD_2_WIDTH    (3U)
#define VIRT_WRAPPER_REG_A175_172_PAD_2(x)       (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A175_172_PAD_2_SHIFT)) & VIRT_WRAPPER_REG_A175_172_PAD_2_MASK)

#define VIRT_WRAPPER_REG_A175_172_PAD_3_MASK     (0x7000000U)
#define VIRT_WRAPPER_REG_A175_172_PAD_3_SHIFT    (24U)
#define VIRT_WRAPPER_REG_A175_172_PAD_3_WIDTH    (3U)
#define VIRT_WRAPPER_REG_A175_172_PAD_3(x)       (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A175_172_PAD_3_SHIFT)) & VIRT_WRAPPER_REG_A175_172_PAD_3_MASK)
/*! @} */

/*! @name REG_A179_176 - Parameter_n Register */
/*! @{ */

#define VIRT_WRAPPER_REG_A179_176_PAD_0_MASK     (0x7U)
#define VIRT_WRAPPER_REG_A179_176_PAD_0_SHIFT    (0U)
#define VIRT_WRAPPER_REG_A179_176_PAD_0_WIDTH    (3U)
#define VIRT_WRAPPER_REG_A179_176_PAD_0(x)       (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A179_176_PAD_0_SHIFT)) & VIRT_WRAPPER_REG_A179_176_PAD_0_MASK)

#define VIRT_WRAPPER_REG_A179_176_PAD_1_MASK     (0x700U)
#define VIRT_WRAPPER_REG_A179_176_PAD_1_SHIFT    (8U)
#define VIRT_WRAPPER_REG_A179_176_PAD_1_WIDTH    (3U)
#define VIRT_WRAPPER_REG_A179_176_PAD_1(x)       (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A179_176_PAD_1_SHIFT)) & VIRT_WRAPPER_REG_A179_176_PAD_1_MASK)

#define VIRT_WRAPPER_REG_A179_176_PAD_2_MASK     (0x70000U)
#define VIRT_WRAPPER_REG_A179_176_PAD_2_SHIFT    (16U)
#define VIRT_WRAPPER_REG_A179_176_PAD_2_WIDTH    (3U)
#define VIRT_WRAPPER_REG_A179_176_PAD_2(x)       (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A179_176_PAD_2_SHIFT)) & VIRT_WRAPPER_REG_A179_176_PAD_2_MASK)

#define VIRT_WRAPPER_REG_A179_176_PAD_3_MASK     (0x7000000U)
#define VIRT_WRAPPER_REG_A179_176_PAD_3_SHIFT    (24U)
#define VIRT_WRAPPER_REG_A179_176_PAD_3_WIDTH    (3U)
#define VIRT_WRAPPER_REG_A179_176_PAD_3(x)       (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A179_176_PAD_3_SHIFT)) & VIRT_WRAPPER_REG_A179_176_PAD_3_MASK)
/*! @} */

/*! @name REG_A183_180 - Parameter_n Register */
/*! @{ */

#define VIRT_WRAPPER_REG_A183_180_PAD_0_MASK     (0x7U)
#define VIRT_WRAPPER_REG_A183_180_PAD_0_SHIFT    (0U)
#define VIRT_WRAPPER_REG_A183_180_PAD_0_WIDTH    (3U)
#define VIRT_WRAPPER_REG_A183_180_PAD_0(x)       (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A183_180_PAD_0_SHIFT)) & VIRT_WRAPPER_REG_A183_180_PAD_0_MASK)

#define VIRT_WRAPPER_REG_A183_180_PAD_1_MASK     (0x700U)
#define VIRT_WRAPPER_REG_A183_180_PAD_1_SHIFT    (8U)
#define VIRT_WRAPPER_REG_A183_180_PAD_1_WIDTH    (3U)
#define VIRT_WRAPPER_REG_A183_180_PAD_1(x)       (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A183_180_PAD_1_SHIFT)) & VIRT_WRAPPER_REG_A183_180_PAD_1_MASK)

#define VIRT_WRAPPER_REG_A183_180_PAD_2_MASK     (0x70000U)
#define VIRT_WRAPPER_REG_A183_180_PAD_2_SHIFT    (16U)
#define VIRT_WRAPPER_REG_A183_180_PAD_2_WIDTH    (3U)
#define VIRT_WRAPPER_REG_A183_180_PAD_2(x)       (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A183_180_PAD_2_SHIFT)) & VIRT_WRAPPER_REG_A183_180_PAD_2_MASK)

#define VIRT_WRAPPER_REG_A183_180_PAD_3_MASK     (0x7000000U)
#define VIRT_WRAPPER_REG_A183_180_PAD_3_SHIFT    (24U)
#define VIRT_WRAPPER_REG_A183_180_PAD_3_WIDTH    (3U)
#define VIRT_WRAPPER_REG_A183_180_PAD_3(x)       (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A183_180_PAD_3_SHIFT)) & VIRT_WRAPPER_REG_A183_180_PAD_3_MASK)
/*! @} */

/*! @name REG_A187_184 - Parameter_n Register */
/*! @{ */

#define VIRT_WRAPPER_REG_A187_184_PAD_0_MASK     (0x7U)
#define VIRT_WRAPPER_REG_A187_184_PAD_0_SHIFT    (0U)
#define VIRT_WRAPPER_REG_A187_184_PAD_0_WIDTH    (3U)
#define VIRT_WRAPPER_REG_A187_184_PAD_0(x)       (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A187_184_PAD_0_SHIFT)) & VIRT_WRAPPER_REG_A187_184_PAD_0_MASK)

#define VIRT_WRAPPER_REG_A187_184_PAD_1_MASK     (0x700U)
#define VIRT_WRAPPER_REG_A187_184_PAD_1_SHIFT    (8U)
#define VIRT_WRAPPER_REG_A187_184_PAD_1_WIDTH    (3U)
#define VIRT_WRAPPER_REG_A187_184_PAD_1(x)       (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A187_184_PAD_1_SHIFT)) & VIRT_WRAPPER_REG_A187_184_PAD_1_MASK)

#define VIRT_WRAPPER_REG_A187_184_PAD_2_MASK     (0x70000U)
#define VIRT_WRAPPER_REG_A187_184_PAD_2_SHIFT    (16U)
#define VIRT_WRAPPER_REG_A187_184_PAD_2_WIDTH    (3U)
#define VIRT_WRAPPER_REG_A187_184_PAD_2(x)       (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A187_184_PAD_2_SHIFT)) & VIRT_WRAPPER_REG_A187_184_PAD_2_MASK)

#define VIRT_WRAPPER_REG_A187_184_PAD_3_MASK     (0x7000000U)
#define VIRT_WRAPPER_REG_A187_184_PAD_3_SHIFT    (24U)
#define VIRT_WRAPPER_REG_A187_184_PAD_3_WIDTH    (3U)
#define VIRT_WRAPPER_REG_A187_184_PAD_3(x)       (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A187_184_PAD_3_SHIFT)) & VIRT_WRAPPER_REG_A187_184_PAD_3_MASK)
/*! @} */

/*! @name REG_A191_188 - Parameter_n Register */
/*! @{ */

#define VIRT_WRAPPER_REG_A191_188_PAD_0_MASK     (0x7U)
#define VIRT_WRAPPER_REG_A191_188_PAD_0_SHIFT    (0U)
#define VIRT_WRAPPER_REG_A191_188_PAD_0_WIDTH    (3U)
#define VIRT_WRAPPER_REG_A191_188_PAD_0(x)       (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A191_188_PAD_0_SHIFT)) & VIRT_WRAPPER_REG_A191_188_PAD_0_MASK)

#define VIRT_WRAPPER_REG_A191_188_PAD_1_MASK     (0x700U)
#define VIRT_WRAPPER_REG_A191_188_PAD_1_SHIFT    (8U)
#define VIRT_WRAPPER_REG_A191_188_PAD_1_WIDTH    (3U)
#define VIRT_WRAPPER_REG_A191_188_PAD_1(x)       (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A191_188_PAD_1_SHIFT)) & VIRT_WRAPPER_REG_A191_188_PAD_1_MASK)

#define VIRT_WRAPPER_REG_A191_188_PAD_2_MASK     (0x70000U)
#define VIRT_WRAPPER_REG_A191_188_PAD_2_SHIFT    (16U)
#define VIRT_WRAPPER_REG_A191_188_PAD_2_WIDTH    (3U)
#define VIRT_WRAPPER_REG_A191_188_PAD_2(x)       (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A191_188_PAD_2_SHIFT)) & VIRT_WRAPPER_REG_A191_188_PAD_2_MASK)

#define VIRT_WRAPPER_REG_A191_188_PAD_3_MASK     (0x7000000U)
#define VIRT_WRAPPER_REG_A191_188_PAD_3_SHIFT    (24U)
#define VIRT_WRAPPER_REG_A191_188_PAD_3_WIDTH    (3U)
#define VIRT_WRAPPER_REG_A191_188_PAD_3(x)       (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A191_188_PAD_3_SHIFT)) & VIRT_WRAPPER_REG_A191_188_PAD_3_MASK)
/*! @} */

/*! @name REG_A195_192 - Parameter_n Register */
/*! @{ */

#define VIRT_WRAPPER_REG_A195_192_PAD_0_MASK     (0x7U)
#define VIRT_WRAPPER_REG_A195_192_PAD_0_SHIFT    (0U)
#define VIRT_WRAPPER_REG_A195_192_PAD_0_WIDTH    (3U)
#define VIRT_WRAPPER_REG_A195_192_PAD_0(x)       (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A195_192_PAD_0_SHIFT)) & VIRT_WRAPPER_REG_A195_192_PAD_0_MASK)

#define VIRT_WRAPPER_REG_A195_192_PAD_1_MASK     (0x700U)
#define VIRT_WRAPPER_REG_A195_192_PAD_1_SHIFT    (8U)
#define VIRT_WRAPPER_REG_A195_192_PAD_1_WIDTH    (3U)
#define VIRT_WRAPPER_REG_A195_192_PAD_1(x)       (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A195_192_PAD_1_SHIFT)) & VIRT_WRAPPER_REG_A195_192_PAD_1_MASK)

#define VIRT_WRAPPER_REG_A195_192_PAD_2_MASK     (0x70000U)
#define VIRT_WRAPPER_REG_A195_192_PAD_2_SHIFT    (16U)
#define VIRT_WRAPPER_REG_A195_192_PAD_2_WIDTH    (3U)
#define VIRT_WRAPPER_REG_A195_192_PAD_2(x)       (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A195_192_PAD_2_SHIFT)) & VIRT_WRAPPER_REG_A195_192_PAD_2_MASK)

#define VIRT_WRAPPER_REG_A195_192_PAD_3_MASK     (0x7000000U)
#define VIRT_WRAPPER_REG_A195_192_PAD_3_SHIFT    (24U)
#define VIRT_WRAPPER_REG_A195_192_PAD_3_WIDTH    (3U)
#define VIRT_WRAPPER_REG_A195_192_PAD_3(x)       (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A195_192_PAD_3_SHIFT)) & VIRT_WRAPPER_REG_A195_192_PAD_3_MASK)
/*! @} */

/*! @name REG_A199_196 - Parameter_n Register */
/*! @{ */

#define VIRT_WRAPPER_REG_A199_196_PAD_0_MASK     (0x7U)
#define VIRT_WRAPPER_REG_A199_196_PAD_0_SHIFT    (0U)
#define VIRT_WRAPPER_REG_A199_196_PAD_0_WIDTH    (3U)
#define VIRT_WRAPPER_REG_A199_196_PAD_0(x)       (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A199_196_PAD_0_SHIFT)) & VIRT_WRAPPER_REG_A199_196_PAD_0_MASK)

#define VIRT_WRAPPER_REG_A199_196_PAD_1_MASK     (0x700U)
#define VIRT_WRAPPER_REG_A199_196_PAD_1_SHIFT    (8U)
#define VIRT_WRAPPER_REG_A199_196_PAD_1_WIDTH    (3U)
#define VIRT_WRAPPER_REG_A199_196_PAD_1(x)       (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A199_196_PAD_1_SHIFT)) & VIRT_WRAPPER_REG_A199_196_PAD_1_MASK)

#define VIRT_WRAPPER_REG_A199_196_PAD_2_MASK     (0x70000U)
#define VIRT_WRAPPER_REG_A199_196_PAD_2_SHIFT    (16U)
#define VIRT_WRAPPER_REG_A199_196_PAD_2_WIDTH    (3U)
#define VIRT_WRAPPER_REG_A199_196_PAD_2(x)       (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A199_196_PAD_2_SHIFT)) & VIRT_WRAPPER_REG_A199_196_PAD_2_MASK)

#define VIRT_WRAPPER_REG_A199_196_PAD_3_MASK     (0x7000000U)
#define VIRT_WRAPPER_REG_A199_196_PAD_3_SHIFT    (24U)
#define VIRT_WRAPPER_REG_A199_196_PAD_3_WIDTH    (3U)
#define VIRT_WRAPPER_REG_A199_196_PAD_3(x)       (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A199_196_PAD_3_SHIFT)) & VIRT_WRAPPER_REG_A199_196_PAD_3_MASK)
/*! @} */

/*! @name REG_A203_200 - Parameter_n Register */
/*! @{ */

#define VIRT_WRAPPER_REG_A203_200_PAD_0_MASK     (0x7U)
#define VIRT_WRAPPER_REG_A203_200_PAD_0_SHIFT    (0U)
#define VIRT_WRAPPER_REG_A203_200_PAD_0_WIDTH    (3U)
#define VIRT_WRAPPER_REG_A203_200_PAD_0(x)       (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A203_200_PAD_0_SHIFT)) & VIRT_WRAPPER_REG_A203_200_PAD_0_MASK)

#define VIRT_WRAPPER_REG_A203_200_PAD_1_MASK     (0x700U)
#define VIRT_WRAPPER_REG_A203_200_PAD_1_SHIFT    (8U)
#define VIRT_WRAPPER_REG_A203_200_PAD_1_WIDTH    (3U)
#define VIRT_WRAPPER_REG_A203_200_PAD_1(x)       (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A203_200_PAD_1_SHIFT)) & VIRT_WRAPPER_REG_A203_200_PAD_1_MASK)

#define VIRT_WRAPPER_REG_A203_200_PAD_2_MASK     (0x70000U)
#define VIRT_WRAPPER_REG_A203_200_PAD_2_SHIFT    (16U)
#define VIRT_WRAPPER_REG_A203_200_PAD_2_WIDTH    (3U)
#define VIRT_WRAPPER_REG_A203_200_PAD_2(x)       (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A203_200_PAD_2_SHIFT)) & VIRT_WRAPPER_REG_A203_200_PAD_2_MASK)

#define VIRT_WRAPPER_REG_A203_200_PAD_3_MASK     (0x7000000U)
#define VIRT_WRAPPER_REG_A203_200_PAD_3_SHIFT    (24U)
#define VIRT_WRAPPER_REG_A203_200_PAD_3_WIDTH    (3U)
#define VIRT_WRAPPER_REG_A203_200_PAD_3(x)       (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A203_200_PAD_3_SHIFT)) & VIRT_WRAPPER_REG_A203_200_PAD_3_MASK)
/*! @} */

/*! @name REG_A207_204 - Parameter_n Register */
/*! @{ */

#define VIRT_WRAPPER_REG_A207_204_PAD_0_MASK     (0x7U)
#define VIRT_WRAPPER_REG_A207_204_PAD_0_SHIFT    (0U)
#define VIRT_WRAPPER_REG_A207_204_PAD_0_WIDTH    (3U)
#define VIRT_WRAPPER_REG_A207_204_PAD_0(x)       (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A207_204_PAD_0_SHIFT)) & VIRT_WRAPPER_REG_A207_204_PAD_0_MASK)

#define VIRT_WRAPPER_REG_A207_204_PAD_1_MASK     (0x700U)
#define VIRT_WRAPPER_REG_A207_204_PAD_1_SHIFT    (8U)
#define VIRT_WRAPPER_REG_A207_204_PAD_1_WIDTH    (3U)
#define VIRT_WRAPPER_REG_A207_204_PAD_1(x)       (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A207_204_PAD_1_SHIFT)) & VIRT_WRAPPER_REG_A207_204_PAD_1_MASK)

#define VIRT_WRAPPER_REG_A207_204_PAD_2_MASK     (0x70000U)
#define VIRT_WRAPPER_REG_A207_204_PAD_2_SHIFT    (16U)
#define VIRT_WRAPPER_REG_A207_204_PAD_2_WIDTH    (3U)
#define VIRT_WRAPPER_REG_A207_204_PAD_2(x)       (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A207_204_PAD_2_SHIFT)) & VIRT_WRAPPER_REG_A207_204_PAD_2_MASK)

#define VIRT_WRAPPER_REG_A207_204_PAD_3_MASK     (0x7000000U)
#define VIRT_WRAPPER_REG_A207_204_PAD_3_SHIFT    (24U)
#define VIRT_WRAPPER_REG_A207_204_PAD_3_WIDTH    (3U)
#define VIRT_WRAPPER_REG_A207_204_PAD_3(x)       (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A207_204_PAD_3_SHIFT)) & VIRT_WRAPPER_REG_A207_204_PAD_3_MASK)
/*! @} */

/*! @name REG_A211_208 - Parameter_n Register */
/*! @{ */

#define VIRT_WRAPPER_REG_A211_208_PAD_0_MASK     (0x7U)
#define VIRT_WRAPPER_REG_A211_208_PAD_0_SHIFT    (0U)
#define VIRT_WRAPPER_REG_A211_208_PAD_0_WIDTH    (3U)
#define VIRT_WRAPPER_REG_A211_208_PAD_0(x)       (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A211_208_PAD_0_SHIFT)) & VIRT_WRAPPER_REG_A211_208_PAD_0_MASK)

#define VIRT_WRAPPER_REG_A211_208_PAD_1_MASK     (0x700U)
#define VIRT_WRAPPER_REG_A211_208_PAD_1_SHIFT    (8U)
#define VIRT_WRAPPER_REG_A211_208_PAD_1_WIDTH    (3U)
#define VIRT_WRAPPER_REG_A211_208_PAD_1(x)       (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A211_208_PAD_1_SHIFT)) & VIRT_WRAPPER_REG_A211_208_PAD_1_MASK)

#define VIRT_WRAPPER_REG_A211_208_PAD_2_MASK     (0x70000U)
#define VIRT_WRAPPER_REG_A211_208_PAD_2_SHIFT    (16U)
#define VIRT_WRAPPER_REG_A211_208_PAD_2_WIDTH    (3U)
#define VIRT_WRAPPER_REG_A211_208_PAD_2(x)       (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A211_208_PAD_2_SHIFT)) & VIRT_WRAPPER_REG_A211_208_PAD_2_MASK)

#define VIRT_WRAPPER_REG_A211_208_PAD_3_MASK     (0x7000000U)
#define VIRT_WRAPPER_REG_A211_208_PAD_3_SHIFT    (24U)
#define VIRT_WRAPPER_REG_A211_208_PAD_3_WIDTH    (3U)
#define VIRT_WRAPPER_REG_A211_208_PAD_3(x)       (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A211_208_PAD_3_SHIFT)) & VIRT_WRAPPER_REG_A211_208_PAD_3_MASK)
/*! @} */

/*! @name REG_A215_212 - Parameter_n Register */
/*! @{ */

#define VIRT_WRAPPER_REG_A215_212_PAD_0_MASK     (0x7U)
#define VIRT_WRAPPER_REG_A215_212_PAD_0_SHIFT    (0U)
#define VIRT_WRAPPER_REG_A215_212_PAD_0_WIDTH    (3U)
#define VIRT_WRAPPER_REG_A215_212_PAD_0(x)       (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A215_212_PAD_0_SHIFT)) & VIRT_WRAPPER_REG_A215_212_PAD_0_MASK)

#define VIRT_WRAPPER_REG_A215_212_PAD_1_MASK     (0x700U)
#define VIRT_WRAPPER_REG_A215_212_PAD_1_SHIFT    (8U)
#define VIRT_WRAPPER_REG_A215_212_PAD_1_WIDTH    (3U)
#define VIRT_WRAPPER_REG_A215_212_PAD_1(x)       (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A215_212_PAD_1_SHIFT)) & VIRT_WRAPPER_REG_A215_212_PAD_1_MASK)

#define VIRT_WRAPPER_REG_A215_212_PAD_2_MASK     (0x70000U)
#define VIRT_WRAPPER_REG_A215_212_PAD_2_SHIFT    (16U)
#define VIRT_WRAPPER_REG_A215_212_PAD_2_WIDTH    (3U)
#define VIRT_WRAPPER_REG_A215_212_PAD_2(x)       (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A215_212_PAD_2_SHIFT)) & VIRT_WRAPPER_REG_A215_212_PAD_2_MASK)

#define VIRT_WRAPPER_REG_A215_212_PAD_3_MASK     (0x7000000U)
#define VIRT_WRAPPER_REG_A215_212_PAD_3_SHIFT    (24U)
#define VIRT_WRAPPER_REG_A215_212_PAD_3_WIDTH    (3U)
#define VIRT_WRAPPER_REG_A215_212_PAD_3(x)       (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A215_212_PAD_3_SHIFT)) & VIRT_WRAPPER_REG_A215_212_PAD_3_MASK)
/*! @} */

/*! @name REG_A219_216 - Parameter_n Register */
/*! @{ */

#define VIRT_WRAPPER_REG_A219_216_PAD_0_MASK     (0x7U)
#define VIRT_WRAPPER_REG_A219_216_PAD_0_SHIFT    (0U)
#define VIRT_WRAPPER_REG_A219_216_PAD_0_WIDTH    (3U)
#define VIRT_WRAPPER_REG_A219_216_PAD_0(x)       (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A219_216_PAD_0_SHIFT)) & VIRT_WRAPPER_REG_A219_216_PAD_0_MASK)

#define VIRT_WRAPPER_REG_A219_216_PAD_1_MASK     (0x700U)
#define VIRT_WRAPPER_REG_A219_216_PAD_1_SHIFT    (8U)
#define VIRT_WRAPPER_REG_A219_216_PAD_1_WIDTH    (3U)
#define VIRT_WRAPPER_REG_A219_216_PAD_1(x)       (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A219_216_PAD_1_SHIFT)) & VIRT_WRAPPER_REG_A219_216_PAD_1_MASK)

#define VIRT_WRAPPER_REG_A219_216_PAD_2_MASK     (0x70000U)
#define VIRT_WRAPPER_REG_A219_216_PAD_2_SHIFT    (16U)
#define VIRT_WRAPPER_REG_A219_216_PAD_2_WIDTH    (3U)
#define VIRT_WRAPPER_REG_A219_216_PAD_2(x)       (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A219_216_PAD_2_SHIFT)) & VIRT_WRAPPER_REG_A219_216_PAD_2_MASK)

#define VIRT_WRAPPER_REG_A219_216_PAD_3_MASK     (0x7000000U)
#define VIRT_WRAPPER_REG_A219_216_PAD_3_SHIFT    (24U)
#define VIRT_WRAPPER_REG_A219_216_PAD_3_WIDTH    (3U)
#define VIRT_WRAPPER_REG_A219_216_PAD_3(x)       (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A219_216_PAD_3_SHIFT)) & VIRT_WRAPPER_REG_A219_216_PAD_3_MASK)
/*! @} */

/*! @name REG_A223_220 - Parameter_n Register */
/*! @{ */

#define VIRT_WRAPPER_REG_A223_220_PAD_0_MASK     (0x7U)
#define VIRT_WRAPPER_REG_A223_220_PAD_0_SHIFT    (0U)
#define VIRT_WRAPPER_REG_A223_220_PAD_0_WIDTH    (3U)
#define VIRT_WRAPPER_REG_A223_220_PAD_0(x)       (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A223_220_PAD_0_SHIFT)) & VIRT_WRAPPER_REG_A223_220_PAD_0_MASK)

#define VIRT_WRAPPER_REG_A223_220_PAD_1_MASK     (0x700U)
#define VIRT_WRAPPER_REG_A223_220_PAD_1_SHIFT    (8U)
#define VIRT_WRAPPER_REG_A223_220_PAD_1_WIDTH    (3U)
#define VIRT_WRAPPER_REG_A223_220_PAD_1(x)       (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A223_220_PAD_1_SHIFT)) & VIRT_WRAPPER_REG_A223_220_PAD_1_MASK)

#define VIRT_WRAPPER_REG_A223_220_PAD_2_MASK     (0x70000U)
#define VIRT_WRAPPER_REG_A223_220_PAD_2_SHIFT    (16U)
#define VIRT_WRAPPER_REG_A223_220_PAD_2_WIDTH    (3U)
#define VIRT_WRAPPER_REG_A223_220_PAD_2(x)       (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A223_220_PAD_2_SHIFT)) & VIRT_WRAPPER_REG_A223_220_PAD_2_MASK)

#define VIRT_WRAPPER_REG_A223_220_PAD_3_MASK     (0x7000000U)
#define VIRT_WRAPPER_REG_A223_220_PAD_3_SHIFT    (24U)
#define VIRT_WRAPPER_REG_A223_220_PAD_3_WIDTH    (3U)
#define VIRT_WRAPPER_REG_A223_220_PAD_3(x)       (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A223_220_PAD_3_SHIFT)) & VIRT_WRAPPER_REG_A223_220_PAD_3_MASK)
/*! @} */

/*! @name REG_A227_224 - Parameter_n Register */
/*! @{ */

#define VIRT_WRAPPER_REG_A227_224_PAD_0_MASK     (0x7U)
#define VIRT_WRAPPER_REG_A227_224_PAD_0_SHIFT    (0U)
#define VIRT_WRAPPER_REG_A227_224_PAD_0_WIDTH    (3U)
#define VIRT_WRAPPER_REG_A227_224_PAD_0(x)       (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A227_224_PAD_0_SHIFT)) & VIRT_WRAPPER_REG_A227_224_PAD_0_MASK)

#define VIRT_WRAPPER_REG_A227_224_PAD_1_MASK     (0x700U)
#define VIRT_WRAPPER_REG_A227_224_PAD_1_SHIFT    (8U)
#define VIRT_WRAPPER_REG_A227_224_PAD_1_WIDTH    (3U)
#define VIRT_WRAPPER_REG_A227_224_PAD_1(x)       (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A227_224_PAD_1_SHIFT)) & VIRT_WRAPPER_REG_A227_224_PAD_1_MASK)

#define VIRT_WRAPPER_REG_A227_224_PAD_2_MASK     (0x70000U)
#define VIRT_WRAPPER_REG_A227_224_PAD_2_SHIFT    (16U)
#define VIRT_WRAPPER_REG_A227_224_PAD_2_WIDTH    (3U)
#define VIRT_WRAPPER_REG_A227_224_PAD_2(x)       (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A227_224_PAD_2_SHIFT)) & VIRT_WRAPPER_REG_A227_224_PAD_2_MASK)

#define VIRT_WRAPPER_REG_A227_224_PAD_3_MASK     (0x7000000U)
#define VIRT_WRAPPER_REG_A227_224_PAD_3_SHIFT    (24U)
#define VIRT_WRAPPER_REG_A227_224_PAD_3_WIDTH    (3U)
#define VIRT_WRAPPER_REG_A227_224_PAD_3(x)       (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A227_224_PAD_3_SHIFT)) & VIRT_WRAPPER_REG_A227_224_PAD_3_MASK)
/*! @} */

/*! @name REG_A231_228 - Parameter_n Register */
/*! @{ */

#define VIRT_WRAPPER_REG_A231_228_PAD_0_MASK     (0x7U)
#define VIRT_WRAPPER_REG_A231_228_PAD_0_SHIFT    (0U)
#define VIRT_WRAPPER_REG_A231_228_PAD_0_WIDTH    (3U)
#define VIRT_WRAPPER_REG_A231_228_PAD_0(x)       (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A231_228_PAD_0_SHIFT)) & VIRT_WRAPPER_REG_A231_228_PAD_0_MASK)

#define VIRT_WRAPPER_REG_A231_228_PAD_1_MASK     (0x700U)
#define VIRT_WRAPPER_REG_A231_228_PAD_1_SHIFT    (8U)
#define VIRT_WRAPPER_REG_A231_228_PAD_1_WIDTH    (3U)
#define VIRT_WRAPPER_REG_A231_228_PAD_1(x)       (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A231_228_PAD_1_SHIFT)) & VIRT_WRAPPER_REG_A231_228_PAD_1_MASK)

#define VIRT_WRAPPER_REG_A231_228_PAD_2_MASK     (0x70000U)
#define VIRT_WRAPPER_REG_A231_228_PAD_2_SHIFT    (16U)
#define VIRT_WRAPPER_REG_A231_228_PAD_2_WIDTH    (3U)
#define VIRT_WRAPPER_REG_A231_228_PAD_2(x)       (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A231_228_PAD_2_SHIFT)) & VIRT_WRAPPER_REG_A231_228_PAD_2_MASK)

#define VIRT_WRAPPER_REG_A231_228_PAD_3_MASK     (0x7000000U)
#define VIRT_WRAPPER_REG_A231_228_PAD_3_SHIFT    (24U)
#define VIRT_WRAPPER_REG_A231_228_PAD_3_WIDTH    (3U)
#define VIRT_WRAPPER_REG_A231_228_PAD_3(x)       (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A231_228_PAD_3_SHIFT)) & VIRT_WRAPPER_REG_A231_228_PAD_3_MASK)
/*! @} */

/*! @name REG_A235_232 - Parameter_n Register */
/*! @{ */

#define VIRT_WRAPPER_REG_A235_232_PAD_0_MASK     (0x7U)
#define VIRT_WRAPPER_REG_A235_232_PAD_0_SHIFT    (0U)
#define VIRT_WRAPPER_REG_A235_232_PAD_0_WIDTH    (3U)
#define VIRT_WRAPPER_REG_A235_232_PAD_0(x)       (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A235_232_PAD_0_SHIFT)) & VIRT_WRAPPER_REG_A235_232_PAD_0_MASK)

#define VIRT_WRAPPER_REG_A235_232_PAD_1_MASK     (0x700U)
#define VIRT_WRAPPER_REG_A235_232_PAD_1_SHIFT    (8U)
#define VIRT_WRAPPER_REG_A235_232_PAD_1_WIDTH    (3U)
#define VIRT_WRAPPER_REG_A235_232_PAD_1(x)       (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A235_232_PAD_1_SHIFT)) & VIRT_WRAPPER_REG_A235_232_PAD_1_MASK)

#define VIRT_WRAPPER_REG_A235_232_PAD_2_MASK     (0x70000U)
#define VIRT_WRAPPER_REG_A235_232_PAD_2_SHIFT    (16U)
#define VIRT_WRAPPER_REG_A235_232_PAD_2_WIDTH    (3U)
#define VIRT_WRAPPER_REG_A235_232_PAD_2(x)       (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A235_232_PAD_2_SHIFT)) & VIRT_WRAPPER_REG_A235_232_PAD_2_MASK)

#define VIRT_WRAPPER_REG_A235_232_PAD_3_MASK     (0x7000000U)
#define VIRT_WRAPPER_REG_A235_232_PAD_3_SHIFT    (24U)
#define VIRT_WRAPPER_REG_A235_232_PAD_3_WIDTH    (3U)
#define VIRT_WRAPPER_REG_A235_232_PAD_3(x)       (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A235_232_PAD_3_SHIFT)) & VIRT_WRAPPER_REG_A235_232_PAD_3_MASK)
/*! @} */

/*! @name REG_A239_236 - Parameter_n Register */
/*! @{ */

#define VIRT_WRAPPER_REG_A239_236_PAD_0_MASK     (0x7U)
#define VIRT_WRAPPER_REG_A239_236_PAD_0_SHIFT    (0U)
#define VIRT_WRAPPER_REG_A239_236_PAD_0_WIDTH    (3U)
#define VIRT_WRAPPER_REG_A239_236_PAD_0(x)       (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A239_236_PAD_0_SHIFT)) & VIRT_WRAPPER_REG_A239_236_PAD_0_MASK)
/*! @} */

/*! @name REG_B3_0 - Parameter_n Register */
/*! @{ */

#define VIRT_WRAPPER_REG_B3_0_INMUX_0_MASK       (0x7U)
#define VIRT_WRAPPER_REG_B3_0_INMUX_0_SHIFT      (0U)
#define VIRT_WRAPPER_REG_B3_0_INMUX_0_WIDTH      (3U)
#define VIRT_WRAPPER_REG_B3_0_INMUX_0(x)         (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B3_0_INMUX_0_SHIFT)) & VIRT_WRAPPER_REG_B3_0_INMUX_0_MASK)

#define VIRT_WRAPPER_REG_B3_0_INMUX_1_MASK       (0x700U)
#define VIRT_WRAPPER_REG_B3_0_INMUX_1_SHIFT      (8U)
#define VIRT_WRAPPER_REG_B3_0_INMUX_1_WIDTH      (3U)
#define VIRT_WRAPPER_REG_B3_0_INMUX_1(x)         (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B3_0_INMUX_1_SHIFT)) & VIRT_WRAPPER_REG_B3_0_INMUX_1_MASK)

#define VIRT_WRAPPER_REG_B3_0_INMUX_2_MASK       (0x70000U)
#define VIRT_WRAPPER_REG_B3_0_INMUX_2_SHIFT      (16U)
#define VIRT_WRAPPER_REG_B3_0_INMUX_2_WIDTH      (3U)
#define VIRT_WRAPPER_REG_B3_0_INMUX_2(x)         (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B3_0_INMUX_2_SHIFT)) & VIRT_WRAPPER_REG_B3_0_INMUX_2_MASK)

#define VIRT_WRAPPER_REG_B3_0_INMUX_3_MASK       (0x7000000U)
#define VIRT_WRAPPER_REG_B3_0_INMUX_3_SHIFT      (24U)
#define VIRT_WRAPPER_REG_B3_0_INMUX_3_WIDTH      (3U)
#define VIRT_WRAPPER_REG_B3_0_INMUX_3(x)         (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B3_0_INMUX_3_SHIFT)) & VIRT_WRAPPER_REG_B3_0_INMUX_3_MASK)
/*! @} */

/*! @name REG_B7_4 - Parameter_n Register */
/*! @{ */

#define VIRT_WRAPPER_REG_B7_4_INMUX_0_MASK       (0x7U)
#define VIRT_WRAPPER_REG_B7_4_INMUX_0_SHIFT      (0U)
#define VIRT_WRAPPER_REG_B7_4_INMUX_0_WIDTH      (3U)
#define VIRT_WRAPPER_REG_B7_4_INMUX_0(x)         (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B7_4_INMUX_0_SHIFT)) & VIRT_WRAPPER_REG_B7_4_INMUX_0_MASK)

#define VIRT_WRAPPER_REG_B7_4_INMUX_1_MASK       (0x700U)
#define VIRT_WRAPPER_REG_B7_4_INMUX_1_SHIFT      (8U)
#define VIRT_WRAPPER_REG_B7_4_INMUX_1_WIDTH      (3U)
#define VIRT_WRAPPER_REG_B7_4_INMUX_1(x)         (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B7_4_INMUX_1_SHIFT)) & VIRT_WRAPPER_REG_B7_4_INMUX_1_MASK)
/*! @} */

/*! @name REG_B19_16 - Parameter_n Register */
/*! @{ */

#define VIRT_WRAPPER_REG_B19_16_INMUX_0_MASK     (0x7U)
#define VIRT_WRAPPER_REG_B19_16_INMUX_0_SHIFT    (0U)
#define VIRT_WRAPPER_REG_B19_16_INMUX_0_WIDTH    (3U)
#define VIRT_WRAPPER_REG_B19_16_INMUX_0(x)       (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B19_16_INMUX_0_SHIFT)) & VIRT_WRAPPER_REG_B19_16_INMUX_0_MASK)

#define VIRT_WRAPPER_REG_B19_16_INMUX_1_MASK     (0x700U)
#define VIRT_WRAPPER_REG_B19_16_INMUX_1_SHIFT    (8U)
#define VIRT_WRAPPER_REG_B19_16_INMUX_1_WIDTH    (3U)
#define VIRT_WRAPPER_REG_B19_16_INMUX_1(x)       (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B19_16_INMUX_1_SHIFT)) & VIRT_WRAPPER_REG_B19_16_INMUX_1_MASK)

#define VIRT_WRAPPER_REG_B19_16_INMUX_2_MASK     (0x70000U)
#define VIRT_WRAPPER_REG_B19_16_INMUX_2_SHIFT    (16U)
#define VIRT_WRAPPER_REG_B19_16_INMUX_2_WIDTH    (3U)
#define VIRT_WRAPPER_REG_B19_16_INMUX_2(x)       (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B19_16_INMUX_2_SHIFT)) & VIRT_WRAPPER_REG_B19_16_INMUX_2_MASK)

#define VIRT_WRAPPER_REG_B19_16_INMUX_3_MASK     (0x7000000U)
#define VIRT_WRAPPER_REG_B19_16_INMUX_3_SHIFT    (24U)
#define VIRT_WRAPPER_REG_B19_16_INMUX_3_WIDTH    (3U)
#define VIRT_WRAPPER_REG_B19_16_INMUX_3(x)       (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B19_16_INMUX_3_SHIFT)) & VIRT_WRAPPER_REG_B19_16_INMUX_3_MASK)
/*! @} */

/*! @name REG_B23_20 - Parameter_n Register */
/*! @{ */

#define VIRT_WRAPPER_REG_B23_20_INMUX_0_MASK     (0x7U)
#define VIRT_WRAPPER_REG_B23_20_INMUX_0_SHIFT    (0U)
#define VIRT_WRAPPER_REG_B23_20_INMUX_0_WIDTH    (3U)
#define VIRT_WRAPPER_REG_B23_20_INMUX_0(x)       (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B23_20_INMUX_0_SHIFT)) & VIRT_WRAPPER_REG_B23_20_INMUX_0_MASK)

#define VIRT_WRAPPER_REG_B23_20_INMUX_1_MASK     (0x700U)
#define VIRT_WRAPPER_REG_B23_20_INMUX_1_SHIFT    (8U)
#define VIRT_WRAPPER_REG_B23_20_INMUX_1_WIDTH    (3U)
#define VIRT_WRAPPER_REG_B23_20_INMUX_1(x)       (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B23_20_INMUX_1_SHIFT)) & VIRT_WRAPPER_REG_B23_20_INMUX_1_MASK)

#define VIRT_WRAPPER_REG_B23_20_INMUX_2_MASK     (0x70000U)
#define VIRT_WRAPPER_REG_B23_20_INMUX_2_SHIFT    (16U)
#define VIRT_WRAPPER_REG_B23_20_INMUX_2_WIDTH    (3U)
#define VIRT_WRAPPER_REG_B23_20_INMUX_2(x)       (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B23_20_INMUX_2_SHIFT)) & VIRT_WRAPPER_REG_B23_20_INMUX_2_MASK)

#define VIRT_WRAPPER_REG_B23_20_INMUX_3_MASK     (0x7000000U)
#define VIRT_WRAPPER_REG_B23_20_INMUX_3_SHIFT    (24U)
#define VIRT_WRAPPER_REG_B23_20_INMUX_3_WIDTH    (3U)
#define VIRT_WRAPPER_REG_B23_20_INMUX_3(x)       (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B23_20_INMUX_3_SHIFT)) & VIRT_WRAPPER_REG_B23_20_INMUX_3_MASK)
/*! @} */

/*! @name REG_B27_24 - Parameter_n Register */
/*! @{ */

#define VIRT_WRAPPER_REG_B27_24_INMUX_0_MASK     (0x7U)
#define VIRT_WRAPPER_REG_B27_24_INMUX_0_SHIFT    (0U)
#define VIRT_WRAPPER_REG_B27_24_INMUX_0_WIDTH    (3U)
#define VIRT_WRAPPER_REG_B27_24_INMUX_0(x)       (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B27_24_INMUX_0_SHIFT)) & VIRT_WRAPPER_REG_B27_24_INMUX_0_MASK)

#define VIRT_WRAPPER_REG_B27_24_INMUX_1_MASK     (0x700U)
#define VIRT_WRAPPER_REG_B27_24_INMUX_1_SHIFT    (8U)
#define VIRT_WRAPPER_REG_B27_24_INMUX_1_WIDTH    (3U)
#define VIRT_WRAPPER_REG_B27_24_INMUX_1(x)       (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B27_24_INMUX_1_SHIFT)) & VIRT_WRAPPER_REG_B27_24_INMUX_1_MASK)

#define VIRT_WRAPPER_REG_B27_24_INMUX_2_MASK     (0x70000U)
#define VIRT_WRAPPER_REG_B27_24_INMUX_2_SHIFT    (16U)
#define VIRT_WRAPPER_REG_B27_24_INMUX_2_WIDTH    (3U)
#define VIRT_WRAPPER_REG_B27_24_INMUX_2(x)       (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B27_24_INMUX_2_SHIFT)) & VIRT_WRAPPER_REG_B27_24_INMUX_2_MASK)

#define VIRT_WRAPPER_REG_B27_24_INMUX_3_MASK     (0x7000000U)
#define VIRT_WRAPPER_REG_B27_24_INMUX_3_SHIFT    (24U)
#define VIRT_WRAPPER_REG_B27_24_INMUX_3_WIDTH    (3U)
#define VIRT_WRAPPER_REG_B27_24_INMUX_3(x)       (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B27_24_INMUX_3_SHIFT)) & VIRT_WRAPPER_REG_B27_24_INMUX_3_MASK)
/*! @} */

/*! @name REG_B31_28 - Parameter_n Register */
/*! @{ */

#define VIRT_WRAPPER_REG_B31_28_INMUX_0_MASK     (0x7U)
#define VIRT_WRAPPER_REG_B31_28_INMUX_0_SHIFT    (0U)
#define VIRT_WRAPPER_REG_B31_28_INMUX_0_WIDTH    (3U)
#define VIRT_WRAPPER_REG_B31_28_INMUX_0(x)       (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B31_28_INMUX_0_SHIFT)) & VIRT_WRAPPER_REG_B31_28_INMUX_0_MASK)

#define VIRT_WRAPPER_REG_B31_28_INMUX_1_MASK     (0x700U)
#define VIRT_WRAPPER_REG_B31_28_INMUX_1_SHIFT    (8U)
#define VIRT_WRAPPER_REG_B31_28_INMUX_1_WIDTH    (3U)
#define VIRT_WRAPPER_REG_B31_28_INMUX_1(x)       (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B31_28_INMUX_1_SHIFT)) & VIRT_WRAPPER_REG_B31_28_INMUX_1_MASK)

#define VIRT_WRAPPER_REG_B31_28_INMUX_2_MASK     (0x70000U)
#define VIRT_WRAPPER_REG_B31_28_INMUX_2_SHIFT    (16U)
#define VIRT_WRAPPER_REG_B31_28_INMUX_2_WIDTH    (3U)
#define VIRT_WRAPPER_REG_B31_28_INMUX_2(x)       (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B31_28_INMUX_2_SHIFT)) & VIRT_WRAPPER_REG_B31_28_INMUX_2_MASK)

#define VIRT_WRAPPER_REG_B31_28_INMUX_3_MASK     (0x7000000U)
#define VIRT_WRAPPER_REG_B31_28_INMUX_3_SHIFT    (24U)
#define VIRT_WRAPPER_REG_B31_28_INMUX_3_WIDTH    (3U)
#define VIRT_WRAPPER_REG_B31_28_INMUX_3(x)       (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B31_28_INMUX_3_SHIFT)) & VIRT_WRAPPER_REG_B31_28_INMUX_3_MASK)
/*! @} */

/*! @name REG_B35_32 - Parameter_n Register */
/*! @{ */

#define VIRT_WRAPPER_REG_B35_32_INMUX_0_MASK     (0x7U)
#define VIRT_WRAPPER_REG_B35_32_INMUX_0_SHIFT    (0U)
#define VIRT_WRAPPER_REG_B35_32_INMUX_0_WIDTH    (3U)
#define VIRT_WRAPPER_REG_B35_32_INMUX_0(x)       (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B35_32_INMUX_0_SHIFT)) & VIRT_WRAPPER_REG_B35_32_INMUX_0_MASK)

#define VIRT_WRAPPER_REG_B35_32_INMUX_1_MASK     (0x700U)
#define VIRT_WRAPPER_REG_B35_32_INMUX_1_SHIFT    (8U)
#define VIRT_WRAPPER_REG_B35_32_INMUX_1_WIDTH    (3U)
#define VIRT_WRAPPER_REG_B35_32_INMUX_1(x)       (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B35_32_INMUX_1_SHIFT)) & VIRT_WRAPPER_REG_B35_32_INMUX_1_MASK)

#define VIRT_WRAPPER_REG_B35_32_INMUX_2_MASK     (0x70000U)
#define VIRT_WRAPPER_REG_B35_32_INMUX_2_SHIFT    (16U)
#define VIRT_WRAPPER_REG_B35_32_INMUX_2_WIDTH    (3U)
#define VIRT_WRAPPER_REG_B35_32_INMUX_2(x)       (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B35_32_INMUX_2_SHIFT)) & VIRT_WRAPPER_REG_B35_32_INMUX_2_MASK)

#define VIRT_WRAPPER_REG_B35_32_INMUX_3_MASK     (0x7000000U)
#define VIRT_WRAPPER_REG_B35_32_INMUX_3_SHIFT    (24U)
#define VIRT_WRAPPER_REG_B35_32_INMUX_3_WIDTH    (3U)
#define VIRT_WRAPPER_REG_B35_32_INMUX_3(x)       (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B35_32_INMUX_3_SHIFT)) & VIRT_WRAPPER_REG_B35_32_INMUX_3_MASK)
/*! @} */

/*! @name REG_B39_36 - Parameter_n Register */
/*! @{ */

#define VIRT_WRAPPER_REG_B39_36_INMUX_0_MASK     (0x7U)
#define VIRT_WRAPPER_REG_B39_36_INMUX_0_SHIFT    (0U)
#define VIRT_WRAPPER_REG_B39_36_INMUX_0_WIDTH    (3U)
#define VIRT_WRAPPER_REG_B39_36_INMUX_0(x)       (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B39_36_INMUX_0_SHIFT)) & VIRT_WRAPPER_REG_B39_36_INMUX_0_MASK)

#define VIRT_WRAPPER_REG_B39_36_INMUX_1_MASK     (0x700U)
#define VIRT_WRAPPER_REG_B39_36_INMUX_1_SHIFT    (8U)
#define VIRT_WRAPPER_REG_B39_36_INMUX_1_WIDTH    (3U)
#define VIRT_WRAPPER_REG_B39_36_INMUX_1(x)       (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B39_36_INMUX_1_SHIFT)) & VIRT_WRAPPER_REG_B39_36_INMUX_1_MASK)

#define VIRT_WRAPPER_REG_B39_36_INMUX_2_MASK     (0x70000U)
#define VIRT_WRAPPER_REG_B39_36_INMUX_2_SHIFT    (16U)
#define VIRT_WRAPPER_REG_B39_36_INMUX_2_WIDTH    (3U)
#define VIRT_WRAPPER_REG_B39_36_INMUX_2(x)       (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B39_36_INMUX_2_SHIFT)) & VIRT_WRAPPER_REG_B39_36_INMUX_2_MASK)

#define VIRT_WRAPPER_REG_B39_36_INMUX_3_MASK     (0x7000000U)
#define VIRT_WRAPPER_REG_B39_36_INMUX_3_SHIFT    (24U)
#define VIRT_WRAPPER_REG_B39_36_INMUX_3_WIDTH    (3U)
#define VIRT_WRAPPER_REG_B39_36_INMUX_3(x)       (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B39_36_INMUX_3_SHIFT)) & VIRT_WRAPPER_REG_B39_36_INMUX_3_MASK)
/*! @} */

/*! @name REG_B43_40 - Parameter_n Register */
/*! @{ */

#define VIRT_WRAPPER_REG_B43_40_INMUX_0_MASK     (0x7U)
#define VIRT_WRAPPER_REG_B43_40_INMUX_0_SHIFT    (0U)
#define VIRT_WRAPPER_REG_B43_40_INMUX_0_WIDTH    (3U)
#define VIRT_WRAPPER_REG_B43_40_INMUX_0(x)       (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B43_40_INMUX_0_SHIFT)) & VIRT_WRAPPER_REG_B43_40_INMUX_0_MASK)

#define VIRT_WRAPPER_REG_B43_40_INMUX_1_MASK     (0x700U)
#define VIRT_WRAPPER_REG_B43_40_INMUX_1_SHIFT    (8U)
#define VIRT_WRAPPER_REG_B43_40_INMUX_1_WIDTH    (3U)
#define VIRT_WRAPPER_REG_B43_40_INMUX_1(x)       (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B43_40_INMUX_1_SHIFT)) & VIRT_WRAPPER_REG_B43_40_INMUX_1_MASK)

#define VIRT_WRAPPER_REG_B43_40_INMUX_2_MASK     (0x70000U)
#define VIRT_WRAPPER_REG_B43_40_INMUX_2_SHIFT    (16U)
#define VIRT_WRAPPER_REG_B43_40_INMUX_2_WIDTH    (3U)
#define VIRT_WRAPPER_REG_B43_40_INMUX_2(x)       (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B43_40_INMUX_2_SHIFT)) & VIRT_WRAPPER_REG_B43_40_INMUX_2_MASK)

#define VIRT_WRAPPER_REG_B43_40_INMUX_3_MASK     (0x7000000U)
#define VIRT_WRAPPER_REG_B43_40_INMUX_3_SHIFT    (24U)
#define VIRT_WRAPPER_REG_B43_40_INMUX_3_WIDTH    (3U)
#define VIRT_WRAPPER_REG_B43_40_INMUX_3(x)       (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B43_40_INMUX_3_SHIFT)) & VIRT_WRAPPER_REG_B43_40_INMUX_3_MASK)
/*! @} */

/*! @name REG_B47_44 - Parameter_n Register */
/*! @{ */

#define VIRT_WRAPPER_REG_B47_44_INMUX_0_MASK     (0x7U)
#define VIRT_WRAPPER_REG_B47_44_INMUX_0_SHIFT    (0U)
#define VIRT_WRAPPER_REG_B47_44_INMUX_0_WIDTH    (3U)
#define VIRT_WRAPPER_REG_B47_44_INMUX_0(x)       (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B47_44_INMUX_0_SHIFT)) & VIRT_WRAPPER_REG_B47_44_INMUX_0_MASK)

#define VIRT_WRAPPER_REG_B47_44_INMUX_1_MASK     (0x700U)
#define VIRT_WRAPPER_REG_B47_44_INMUX_1_SHIFT    (8U)
#define VIRT_WRAPPER_REG_B47_44_INMUX_1_WIDTH    (3U)
#define VIRT_WRAPPER_REG_B47_44_INMUX_1(x)       (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B47_44_INMUX_1_SHIFT)) & VIRT_WRAPPER_REG_B47_44_INMUX_1_MASK)

#define VIRT_WRAPPER_REG_B47_44_INMUX_2_MASK     (0x70000U)
#define VIRT_WRAPPER_REG_B47_44_INMUX_2_SHIFT    (16U)
#define VIRT_WRAPPER_REG_B47_44_INMUX_2_WIDTH    (3U)
#define VIRT_WRAPPER_REG_B47_44_INMUX_2(x)       (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B47_44_INMUX_2_SHIFT)) & VIRT_WRAPPER_REG_B47_44_INMUX_2_MASK)

#define VIRT_WRAPPER_REG_B47_44_INMUX_3_MASK     (0x7000000U)
#define VIRT_WRAPPER_REG_B47_44_INMUX_3_SHIFT    (24U)
#define VIRT_WRAPPER_REG_B47_44_INMUX_3_WIDTH    (3U)
#define VIRT_WRAPPER_REG_B47_44_INMUX_3(x)       (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B47_44_INMUX_3_SHIFT)) & VIRT_WRAPPER_REG_B47_44_INMUX_3_MASK)
/*! @} */

/*! @name REG_B51_48 - Parameter_n Register */
/*! @{ */

#define VIRT_WRAPPER_REG_B51_48_INMUX_0_MASK     (0x7U)
#define VIRT_WRAPPER_REG_B51_48_INMUX_0_SHIFT    (0U)
#define VIRT_WRAPPER_REG_B51_48_INMUX_0_WIDTH    (3U)
#define VIRT_WRAPPER_REG_B51_48_INMUX_0(x)       (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B51_48_INMUX_0_SHIFT)) & VIRT_WRAPPER_REG_B51_48_INMUX_0_MASK)

#define VIRT_WRAPPER_REG_B51_48_INMUX_1_MASK     (0x700U)
#define VIRT_WRAPPER_REG_B51_48_INMUX_1_SHIFT    (8U)
#define VIRT_WRAPPER_REG_B51_48_INMUX_1_WIDTH    (3U)
#define VIRT_WRAPPER_REG_B51_48_INMUX_1(x)       (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B51_48_INMUX_1_SHIFT)) & VIRT_WRAPPER_REG_B51_48_INMUX_1_MASK)

#define VIRT_WRAPPER_REG_B51_48_INMUX_2_MASK     (0x70000U)
#define VIRT_WRAPPER_REG_B51_48_INMUX_2_SHIFT    (16U)
#define VIRT_WRAPPER_REG_B51_48_INMUX_2_WIDTH    (3U)
#define VIRT_WRAPPER_REG_B51_48_INMUX_2(x)       (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B51_48_INMUX_2_SHIFT)) & VIRT_WRAPPER_REG_B51_48_INMUX_2_MASK)

#define VIRT_WRAPPER_REG_B51_48_INMUX_3_MASK     (0x7000000U)
#define VIRT_WRAPPER_REG_B51_48_INMUX_3_SHIFT    (24U)
#define VIRT_WRAPPER_REG_B51_48_INMUX_3_WIDTH    (3U)
#define VIRT_WRAPPER_REG_B51_48_INMUX_3(x)       (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B51_48_INMUX_3_SHIFT)) & VIRT_WRAPPER_REG_B51_48_INMUX_3_MASK)
/*! @} */

/*! @name REG_B55_52 - Parameter_n Register */
/*! @{ */

#define VIRT_WRAPPER_REG_B55_52_INMUX_0_MASK     (0x7U)
#define VIRT_WRAPPER_REG_B55_52_INMUX_0_SHIFT    (0U)
#define VIRT_WRAPPER_REG_B55_52_INMUX_0_WIDTH    (3U)
#define VIRT_WRAPPER_REG_B55_52_INMUX_0(x)       (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B55_52_INMUX_0_SHIFT)) & VIRT_WRAPPER_REG_B55_52_INMUX_0_MASK)

#define VIRT_WRAPPER_REG_B55_52_INMUX_1_MASK     (0x700U)
#define VIRT_WRAPPER_REG_B55_52_INMUX_1_SHIFT    (8U)
#define VIRT_WRAPPER_REG_B55_52_INMUX_1_WIDTH    (3U)
#define VIRT_WRAPPER_REG_B55_52_INMUX_1(x)       (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B55_52_INMUX_1_SHIFT)) & VIRT_WRAPPER_REG_B55_52_INMUX_1_MASK)

#define VIRT_WRAPPER_REG_B55_52_INMUX_2_MASK     (0x70000U)
#define VIRT_WRAPPER_REG_B55_52_INMUX_2_SHIFT    (16U)
#define VIRT_WRAPPER_REG_B55_52_INMUX_2_WIDTH    (3U)
#define VIRT_WRAPPER_REG_B55_52_INMUX_2(x)       (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B55_52_INMUX_2_SHIFT)) & VIRT_WRAPPER_REG_B55_52_INMUX_2_MASK)

#define VIRT_WRAPPER_REG_B55_52_INMUX_3_MASK     (0x7000000U)
#define VIRT_WRAPPER_REG_B55_52_INMUX_3_SHIFT    (24U)
#define VIRT_WRAPPER_REG_B55_52_INMUX_3_WIDTH    (3U)
#define VIRT_WRAPPER_REG_B55_52_INMUX_3(x)       (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B55_52_INMUX_3_SHIFT)) & VIRT_WRAPPER_REG_B55_52_INMUX_3_MASK)
/*! @} */

/*! @name REG_B59_56 - Parameter_n Register */
/*! @{ */

#define VIRT_WRAPPER_REG_B59_56_INMUX_0_MASK     (0x7U)
#define VIRT_WRAPPER_REG_B59_56_INMUX_0_SHIFT    (0U)
#define VIRT_WRAPPER_REG_B59_56_INMUX_0_WIDTH    (3U)
#define VIRT_WRAPPER_REG_B59_56_INMUX_0(x)       (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B59_56_INMUX_0_SHIFT)) & VIRT_WRAPPER_REG_B59_56_INMUX_0_MASK)

#define VIRT_WRAPPER_REG_B59_56_INMUX_1_MASK     (0x700U)
#define VIRT_WRAPPER_REG_B59_56_INMUX_1_SHIFT    (8U)
#define VIRT_WRAPPER_REG_B59_56_INMUX_1_WIDTH    (3U)
#define VIRT_WRAPPER_REG_B59_56_INMUX_1(x)       (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B59_56_INMUX_1_SHIFT)) & VIRT_WRAPPER_REG_B59_56_INMUX_1_MASK)

#define VIRT_WRAPPER_REG_B59_56_INMUX_2_MASK     (0x70000U)
#define VIRT_WRAPPER_REG_B59_56_INMUX_2_SHIFT    (16U)
#define VIRT_WRAPPER_REG_B59_56_INMUX_2_WIDTH    (3U)
#define VIRT_WRAPPER_REG_B59_56_INMUX_2(x)       (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B59_56_INMUX_2_SHIFT)) & VIRT_WRAPPER_REG_B59_56_INMUX_2_MASK)

#define VIRT_WRAPPER_REG_B59_56_INMUX_3_MASK     (0x7000000U)
#define VIRT_WRAPPER_REG_B59_56_INMUX_3_SHIFT    (24U)
#define VIRT_WRAPPER_REG_B59_56_INMUX_3_WIDTH    (3U)
#define VIRT_WRAPPER_REG_B59_56_INMUX_3(x)       (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B59_56_INMUX_3_SHIFT)) & VIRT_WRAPPER_REG_B59_56_INMUX_3_MASK)
/*! @} */

/*! @name REG_B63_60 - Parameter_n Register */
/*! @{ */

#define VIRT_WRAPPER_REG_B63_60_INMUX_0_MASK     (0x7U)
#define VIRT_WRAPPER_REG_B63_60_INMUX_0_SHIFT    (0U)
#define VIRT_WRAPPER_REG_B63_60_INMUX_0_WIDTH    (3U)
#define VIRT_WRAPPER_REG_B63_60_INMUX_0(x)       (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B63_60_INMUX_0_SHIFT)) & VIRT_WRAPPER_REG_B63_60_INMUX_0_MASK)

#define VIRT_WRAPPER_REG_B63_60_INMUX_1_MASK     (0x700U)
#define VIRT_WRAPPER_REG_B63_60_INMUX_1_SHIFT    (8U)
#define VIRT_WRAPPER_REG_B63_60_INMUX_1_WIDTH    (3U)
#define VIRT_WRAPPER_REG_B63_60_INMUX_1(x)       (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B63_60_INMUX_1_SHIFT)) & VIRT_WRAPPER_REG_B63_60_INMUX_1_MASK)

#define VIRT_WRAPPER_REG_B63_60_INMUX_2_MASK     (0x70000U)
#define VIRT_WRAPPER_REG_B63_60_INMUX_2_SHIFT    (16U)
#define VIRT_WRAPPER_REG_B63_60_INMUX_2_WIDTH    (3U)
#define VIRT_WRAPPER_REG_B63_60_INMUX_2(x)       (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B63_60_INMUX_2_SHIFT)) & VIRT_WRAPPER_REG_B63_60_INMUX_2_MASK)

#define VIRT_WRAPPER_REG_B63_60_INMUX_3_MASK     (0x7000000U)
#define VIRT_WRAPPER_REG_B63_60_INMUX_3_SHIFT    (24U)
#define VIRT_WRAPPER_REG_B63_60_INMUX_3_WIDTH    (3U)
#define VIRT_WRAPPER_REG_B63_60_INMUX_3(x)       (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B63_60_INMUX_3_SHIFT)) & VIRT_WRAPPER_REG_B63_60_INMUX_3_MASK)
/*! @} */

/*! @name REG_B67_64 - Parameter_n Register */
/*! @{ */

#define VIRT_WRAPPER_REG_B67_64_INMUX_0_MASK     (0x7U)
#define VIRT_WRAPPER_REG_B67_64_INMUX_0_SHIFT    (0U)
#define VIRT_WRAPPER_REG_B67_64_INMUX_0_WIDTH    (3U)
#define VIRT_WRAPPER_REG_B67_64_INMUX_0(x)       (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B67_64_INMUX_0_SHIFT)) & VIRT_WRAPPER_REG_B67_64_INMUX_0_MASK)

#define VIRT_WRAPPER_REG_B67_64_INMUX_1_MASK     (0x700U)
#define VIRT_WRAPPER_REG_B67_64_INMUX_1_SHIFT    (8U)
#define VIRT_WRAPPER_REG_B67_64_INMUX_1_WIDTH    (3U)
#define VIRT_WRAPPER_REG_B67_64_INMUX_1(x)       (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B67_64_INMUX_1_SHIFT)) & VIRT_WRAPPER_REG_B67_64_INMUX_1_MASK)

#define VIRT_WRAPPER_REG_B67_64_INMUX_2_MASK     (0x70000U)
#define VIRT_WRAPPER_REG_B67_64_INMUX_2_SHIFT    (16U)
#define VIRT_WRAPPER_REG_B67_64_INMUX_2_WIDTH    (3U)
#define VIRT_WRAPPER_REG_B67_64_INMUX_2(x)       (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B67_64_INMUX_2_SHIFT)) & VIRT_WRAPPER_REG_B67_64_INMUX_2_MASK)

#define VIRT_WRAPPER_REG_B67_64_INMUX_3_MASK     (0x7000000U)
#define VIRT_WRAPPER_REG_B67_64_INMUX_3_SHIFT    (24U)
#define VIRT_WRAPPER_REG_B67_64_INMUX_3_WIDTH    (3U)
#define VIRT_WRAPPER_REG_B67_64_INMUX_3(x)       (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B67_64_INMUX_3_SHIFT)) & VIRT_WRAPPER_REG_B67_64_INMUX_3_MASK)
/*! @} */

/*! @name REG_B71_68 - Parameter_n Register */
/*! @{ */

#define VIRT_WRAPPER_REG_B71_68_INMUX_0_MASK     (0x7U)
#define VIRT_WRAPPER_REG_B71_68_INMUX_0_SHIFT    (0U)
#define VIRT_WRAPPER_REG_B71_68_INMUX_0_WIDTH    (3U)
#define VIRT_WRAPPER_REG_B71_68_INMUX_0(x)       (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B71_68_INMUX_0_SHIFT)) & VIRT_WRAPPER_REG_B71_68_INMUX_0_MASK)

#define VIRT_WRAPPER_REG_B71_68_INMUX_1_MASK     (0x700U)
#define VIRT_WRAPPER_REG_B71_68_INMUX_1_SHIFT    (8U)
#define VIRT_WRAPPER_REG_B71_68_INMUX_1_WIDTH    (3U)
#define VIRT_WRAPPER_REG_B71_68_INMUX_1(x)       (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B71_68_INMUX_1_SHIFT)) & VIRT_WRAPPER_REG_B71_68_INMUX_1_MASK)

#define VIRT_WRAPPER_REG_B71_68_INMUX_2_MASK     (0x70000U)
#define VIRT_WRAPPER_REG_B71_68_INMUX_2_SHIFT    (16U)
#define VIRT_WRAPPER_REG_B71_68_INMUX_2_WIDTH    (3U)
#define VIRT_WRAPPER_REG_B71_68_INMUX_2(x)       (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B71_68_INMUX_2_SHIFT)) & VIRT_WRAPPER_REG_B71_68_INMUX_2_MASK)

#define VIRT_WRAPPER_REG_B71_68_INMUX_3_MASK     (0x7000000U)
#define VIRT_WRAPPER_REG_B71_68_INMUX_3_SHIFT    (24U)
#define VIRT_WRAPPER_REG_B71_68_INMUX_3_WIDTH    (3U)
#define VIRT_WRAPPER_REG_B71_68_INMUX_3(x)       (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B71_68_INMUX_3_SHIFT)) & VIRT_WRAPPER_REG_B71_68_INMUX_3_MASK)
/*! @} */

/*! @name REG_B83_80 - Parameter_n Register */
/*! @{ */

#define VIRT_WRAPPER_REG_B83_80_INMUX_0_MASK     (0x7U)
#define VIRT_WRAPPER_REG_B83_80_INMUX_0_SHIFT    (0U)
#define VIRT_WRAPPER_REG_B83_80_INMUX_0_WIDTH    (3U)
#define VIRT_WRAPPER_REG_B83_80_INMUX_0(x)       (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B83_80_INMUX_0_SHIFT)) & VIRT_WRAPPER_REG_B83_80_INMUX_0_MASK)

#define VIRT_WRAPPER_REG_B83_80_INMUX_1_MASK     (0x700U)
#define VIRT_WRAPPER_REG_B83_80_INMUX_1_SHIFT    (8U)
#define VIRT_WRAPPER_REG_B83_80_INMUX_1_WIDTH    (3U)
#define VIRT_WRAPPER_REG_B83_80_INMUX_1(x)       (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B83_80_INMUX_1_SHIFT)) & VIRT_WRAPPER_REG_B83_80_INMUX_1_MASK)

#define VIRT_WRAPPER_REG_B83_80_INMUX_2_MASK     (0x70000U)
#define VIRT_WRAPPER_REG_B83_80_INMUX_2_SHIFT    (16U)
#define VIRT_WRAPPER_REG_B83_80_INMUX_2_WIDTH    (3U)
#define VIRT_WRAPPER_REG_B83_80_INMUX_2(x)       (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B83_80_INMUX_2_SHIFT)) & VIRT_WRAPPER_REG_B83_80_INMUX_2_MASK)

#define VIRT_WRAPPER_REG_B83_80_INMUX_3_MASK     (0x7000000U)
#define VIRT_WRAPPER_REG_B83_80_INMUX_3_SHIFT    (24U)
#define VIRT_WRAPPER_REG_B83_80_INMUX_3_WIDTH    (3U)
#define VIRT_WRAPPER_REG_B83_80_INMUX_3(x)       (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B83_80_INMUX_3_SHIFT)) & VIRT_WRAPPER_REG_B83_80_INMUX_3_MASK)
/*! @} */

/*! @name REG_B87_84 - Parameter_n Register */
/*! @{ */

#define VIRT_WRAPPER_REG_B87_84_INMUX_0_MASK     (0x7U)
#define VIRT_WRAPPER_REG_B87_84_INMUX_0_SHIFT    (0U)
#define VIRT_WRAPPER_REG_B87_84_INMUX_0_WIDTH    (3U)
#define VIRT_WRAPPER_REG_B87_84_INMUX_0(x)       (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B87_84_INMUX_0_SHIFT)) & VIRT_WRAPPER_REG_B87_84_INMUX_0_MASK)

#define VIRT_WRAPPER_REG_B87_84_INMUX_1_MASK     (0x700U)
#define VIRT_WRAPPER_REG_B87_84_INMUX_1_SHIFT    (8U)
#define VIRT_WRAPPER_REG_B87_84_INMUX_1_WIDTH    (3U)
#define VIRT_WRAPPER_REG_B87_84_INMUX_1(x)       (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B87_84_INMUX_1_SHIFT)) & VIRT_WRAPPER_REG_B87_84_INMUX_1_MASK)

#define VIRT_WRAPPER_REG_B87_84_INMUX_2_MASK     (0x70000U)
#define VIRT_WRAPPER_REG_B87_84_INMUX_2_SHIFT    (16U)
#define VIRT_WRAPPER_REG_B87_84_INMUX_2_WIDTH    (3U)
#define VIRT_WRAPPER_REG_B87_84_INMUX_2(x)       (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B87_84_INMUX_2_SHIFT)) & VIRT_WRAPPER_REG_B87_84_INMUX_2_MASK)

#define VIRT_WRAPPER_REG_B87_84_INMUX_3_MASK     (0x7000000U)
#define VIRT_WRAPPER_REG_B87_84_INMUX_3_SHIFT    (24U)
#define VIRT_WRAPPER_REG_B87_84_INMUX_3_WIDTH    (3U)
#define VIRT_WRAPPER_REG_B87_84_INMUX_3(x)       (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B87_84_INMUX_3_SHIFT)) & VIRT_WRAPPER_REG_B87_84_INMUX_3_MASK)
/*! @} */

/*! @name REG_B91_88 - Parameter_n Register */
/*! @{ */

#define VIRT_WRAPPER_REG_B91_88_INMUX_0_MASK     (0x7U)
#define VIRT_WRAPPER_REG_B91_88_INMUX_0_SHIFT    (0U)
#define VIRT_WRAPPER_REG_B91_88_INMUX_0_WIDTH    (3U)
#define VIRT_WRAPPER_REG_B91_88_INMUX_0(x)       (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B91_88_INMUX_0_SHIFT)) & VIRT_WRAPPER_REG_B91_88_INMUX_0_MASK)

#define VIRT_WRAPPER_REG_B91_88_INMUX_1_MASK     (0x700U)
#define VIRT_WRAPPER_REG_B91_88_INMUX_1_SHIFT    (8U)
#define VIRT_WRAPPER_REG_B91_88_INMUX_1_WIDTH    (3U)
#define VIRT_WRAPPER_REG_B91_88_INMUX_1(x)       (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B91_88_INMUX_1_SHIFT)) & VIRT_WRAPPER_REG_B91_88_INMUX_1_MASK)

#define VIRT_WRAPPER_REG_B91_88_INMUX_2_MASK     (0x70000U)
#define VIRT_WRAPPER_REG_B91_88_INMUX_2_SHIFT    (16U)
#define VIRT_WRAPPER_REG_B91_88_INMUX_2_WIDTH    (3U)
#define VIRT_WRAPPER_REG_B91_88_INMUX_2(x)       (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B91_88_INMUX_2_SHIFT)) & VIRT_WRAPPER_REG_B91_88_INMUX_2_MASK)

#define VIRT_WRAPPER_REG_B91_88_INMUX_3_MASK     (0x7000000U)
#define VIRT_WRAPPER_REG_B91_88_INMUX_3_SHIFT    (24U)
#define VIRT_WRAPPER_REG_B91_88_INMUX_3_WIDTH    (3U)
#define VIRT_WRAPPER_REG_B91_88_INMUX_3(x)       (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B91_88_INMUX_3_SHIFT)) & VIRT_WRAPPER_REG_B91_88_INMUX_3_MASK)
/*! @} */

/*! @name REG_B95_92 - Parameter_n Register */
/*! @{ */

#define VIRT_WRAPPER_REG_B95_92_INMUX_0_MASK     (0x7U)
#define VIRT_WRAPPER_REG_B95_92_INMUX_0_SHIFT    (0U)
#define VIRT_WRAPPER_REG_B95_92_INMUX_0_WIDTH    (3U)
#define VIRT_WRAPPER_REG_B95_92_INMUX_0(x)       (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B95_92_INMUX_0_SHIFT)) & VIRT_WRAPPER_REG_B95_92_INMUX_0_MASK)

#define VIRT_WRAPPER_REG_B95_92_INMUX_1_MASK     (0x700U)
#define VIRT_WRAPPER_REG_B95_92_INMUX_1_SHIFT    (8U)
#define VIRT_WRAPPER_REG_B95_92_INMUX_1_WIDTH    (3U)
#define VIRT_WRAPPER_REG_B95_92_INMUX_1(x)       (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B95_92_INMUX_1_SHIFT)) & VIRT_WRAPPER_REG_B95_92_INMUX_1_MASK)

#define VIRT_WRAPPER_REG_B95_92_INMUX_2_MASK     (0x70000U)
#define VIRT_WRAPPER_REG_B95_92_INMUX_2_SHIFT    (16U)
#define VIRT_WRAPPER_REG_B95_92_INMUX_2_WIDTH    (3U)
#define VIRT_WRAPPER_REG_B95_92_INMUX_2(x)       (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B95_92_INMUX_2_SHIFT)) & VIRT_WRAPPER_REG_B95_92_INMUX_2_MASK)

#define VIRT_WRAPPER_REG_B95_92_INMUX_3_MASK     (0x7000000U)
#define VIRT_WRAPPER_REG_B95_92_INMUX_3_SHIFT    (24U)
#define VIRT_WRAPPER_REG_B95_92_INMUX_3_WIDTH    (3U)
#define VIRT_WRAPPER_REG_B95_92_INMUX_3(x)       (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B95_92_INMUX_3_SHIFT)) & VIRT_WRAPPER_REG_B95_92_INMUX_3_MASK)
/*! @} */

/*! @name REG_B99_96 - Parameter_n Register */
/*! @{ */

#define VIRT_WRAPPER_REG_B99_96_INMUX_0_MASK     (0x7U)
#define VIRT_WRAPPER_REG_B99_96_INMUX_0_SHIFT    (0U)
#define VIRT_WRAPPER_REG_B99_96_INMUX_0_WIDTH    (3U)
#define VIRT_WRAPPER_REG_B99_96_INMUX_0(x)       (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B99_96_INMUX_0_SHIFT)) & VIRT_WRAPPER_REG_B99_96_INMUX_0_MASK)

#define VIRT_WRAPPER_REG_B99_96_INMUX_1_MASK     (0x700U)
#define VIRT_WRAPPER_REG_B99_96_INMUX_1_SHIFT    (8U)
#define VIRT_WRAPPER_REG_B99_96_INMUX_1_WIDTH    (3U)
#define VIRT_WRAPPER_REG_B99_96_INMUX_1(x)       (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B99_96_INMUX_1_SHIFT)) & VIRT_WRAPPER_REG_B99_96_INMUX_1_MASK)

#define VIRT_WRAPPER_REG_B99_96_INMUX_2_MASK     (0x70000U)
#define VIRT_WRAPPER_REG_B99_96_INMUX_2_SHIFT    (16U)
#define VIRT_WRAPPER_REG_B99_96_INMUX_2_WIDTH    (3U)
#define VIRT_WRAPPER_REG_B99_96_INMUX_2(x)       (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B99_96_INMUX_2_SHIFT)) & VIRT_WRAPPER_REG_B99_96_INMUX_2_MASK)

#define VIRT_WRAPPER_REG_B99_96_INMUX_3_MASK     (0x7000000U)
#define VIRT_WRAPPER_REG_B99_96_INMUX_3_SHIFT    (24U)
#define VIRT_WRAPPER_REG_B99_96_INMUX_3_WIDTH    (3U)
#define VIRT_WRAPPER_REG_B99_96_INMUX_3(x)       (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B99_96_INMUX_3_SHIFT)) & VIRT_WRAPPER_REG_B99_96_INMUX_3_MASK)
/*! @} */

/*! @name REG_B103_100 - Parameter_n Register */
/*! @{ */

#define VIRT_WRAPPER_REG_B103_100_INMUX_0_MASK   (0x7U)
#define VIRT_WRAPPER_REG_B103_100_INMUX_0_SHIFT  (0U)
#define VIRT_WRAPPER_REG_B103_100_INMUX_0_WIDTH  (3U)
#define VIRT_WRAPPER_REG_B103_100_INMUX_0(x)     (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B103_100_INMUX_0_SHIFT)) & VIRT_WRAPPER_REG_B103_100_INMUX_0_MASK)

#define VIRT_WRAPPER_REG_B103_100_INMUX_1_MASK   (0x700U)
#define VIRT_WRAPPER_REG_B103_100_INMUX_1_SHIFT  (8U)
#define VIRT_WRAPPER_REG_B103_100_INMUX_1_WIDTH  (3U)
#define VIRT_WRAPPER_REG_B103_100_INMUX_1(x)     (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B103_100_INMUX_1_SHIFT)) & VIRT_WRAPPER_REG_B103_100_INMUX_1_MASK)

#define VIRT_WRAPPER_REG_B103_100_INMUX_2_MASK   (0x70000U)
#define VIRT_WRAPPER_REG_B103_100_INMUX_2_SHIFT  (16U)
#define VIRT_WRAPPER_REG_B103_100_INMUX_2_WIDTH  (3U)
#define VIRT_WRAPPER_REG_B103_100_INMUX_2(x)     (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B103_100_INMUX_2_SHIFT)) & VIRT_WRAPPER_REG_B103_100_INMUX_2_MASK)

#define VIRT_WRAPPER_REG_B103_100_INMUX_3_MASK   (0x7000000U)
#define VIRT_WRAPPER_REG_B103_100_INMUX_3_SHIFT  (24U)
#define VIRT_WRAPPER_REG_B103_100_INMUX_3_WIDTH  (3U)
#define VIRT_WRAPPER_REG_B103_100_INMUX_3(x)     (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B103_100_INMUX_3_SHIFT)) & VIRT_WRAPPER_REG_B103_100_INMUX_3_MASK)
/*! @} */

/*! @name REG_B115_112 - Parameter_n Register */
/*! @{ */

#define VIRT_WRAPPER_REG_B115_112_INMUX_0_MASK   (0x7U)
#define VIRT_WRAPPER_REG_B115_112_INMUX_0_SHIFT  (0U)
#define VIRT_WRAPPER_REG_B115_112_INMUX_0_WIDTH  (3U)
#define VIRT_WRAPPER_REG_B115_112_INMUX_0(x)     (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B115_112_INMUX_0_SHIFT)) & VIRT_WRAPPER_REG_B115_112_INMUX_0_MASK)

#define VIRT_WRAPPER_REG_B115_112_INMUX_1_MASK   (0x700U)
#define VIRT_WRAPPER_REG_B115_112_INMUX_1_SHIFT  (8U)
#define VIRT_WRAPPER_REG_B115_112_INMUX_1_WIDTH  (3U)
#define VIRT_WRAPPER_REG_B115_112_INMUX_1(x)     (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B115_112_INMUX_1_SHIFT)) & VIRT_WRAPPER_REG_B115_112_INMUX_1_MASK)

#define VIRT_WRAPPER_REG_B115_112_INMUX_2_MASK   (0x70000U)
#define VIRT_WRAPPER_REG_B115_112_INMUX_2_SHIFT  (16U)
#define VIRT_WRAPPER_REG_B115_112_INMUX_2_WIDTH  (3U)
#define VIRT_WRAPPER_REG_B115_112_INMUX_2(x)     (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B115_112_INMUX_2_SHIFT)) & VIRT_WRAPPER_REG_B115_112_INMUX_2_MASK)

#define VIRT_WRAPPER_REG_B115_112_INMUX_3_MASK   (0x7000000U)
#define VIRT_WRAPPER_REG_B115_112_INMUX_3_SHIFT  (24U)
#define VIRT_WRAPPER_REG_B115_112_INMUX_3_WIDTH  (3U)
#define VIRT_WRAPPER_REG_B115_112_INMUX_3(x)     (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B115_112_INMUX_3_SHIFT)) & VIRT_WRAPPER_REG_B115_112_INMUX_3_MASK)
/*! @} */

/*! @name REG_B119_116 - Parameter_n Register */
/*! @{ */

#define VIRT_WRAPPER_REG_B119_116_INMUX_0_MASK   (0x7U)
#define VIRT_WRAPPER_REG_B119_116_INMUX_0_SHIFT  (0U)
#define VIRT_WRAPPER_REG_B119_116_INMUX_0_WIDTH  (3U)
#define VIRT_WRAPPER_REG_B119_116_INMUX_0(x)     (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B119_116_INMUX_0_SHIFT)) & VIRT_WRAPPER_REG_B119_116_INMUX_0_MASK)

#define VIRT_WRAPPER_REG_B119_116_INMUX_1_MASK   (0x700U)
#define VIRT_WRAPPER_REG_B119_116_INMUX_1_SHIFT  (8U)
#define VIRT_WRAPPER_REG_B119_116_INMUX_1_WIDTH  (3U)
#define VIRT_WRAPPER_REG_B119_116_INMUX_1(x)     (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B119_116_INMUX_1_SHIFT)) & VIRT_WRAPPER_REG_B119_116_INMUX_1_MASK)

#define VIRT_WRAPPER_REG_B119_116_INMUX_2_MASK   (0x70000U)
#define VIRT_WRAPPER_REG_B119_116_INMUX_2_SHIFT  (16U)
#define VIRT_WRAPPER_REG_B119_116_INMUX_2_WIDTH  (3U)
#define VIRT_WRAPPER_REG_B119_116_INMUX_2(x)     (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B119_116_INMUX_2_SHIFT)) & VIRT_WRAPPER_REG_B119_116_INMUX_2_MASK)

#define VIRT_WRAPPER_REG_B119_116_INMUX_3_MASK   (0x7000000U)
#define VIRT_WRAPPER_REG_B119_116_INMUX_3_SHIFT  (24U)
#define VIRT_WRAPPER_REG_B119_116_INMUX_3_WIDTH  (3U)
#define VIRT_WRAPPER_REG_B119_116_INMUX_3(x)     (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B119_116_INMUX_3_SHIFT)) & VIRT_WRAPPER_REG_B119_116_INMUX_3_MASK)
/*! @} */

/*! @name REG_B123_120 - Parameter_n Register */
/*! @{ */

#define VIRT_WRAPPER_REG_B123_120_INMUX_0_MASK   (0x7U)
#define VIRT_WRAPPER_REG_B123_120_INMUX_0_SHIFT  (0U)
#define VIRT_WRAPPER_REG_B123_120_INMUX_0_WIDTH  (3U)
#define VIRT_WRAPPER_REG_B123_120_INMUX_0(x)     (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B123_120_INMUX_0_SHIFT)) & VIRT_WRAPPER_REG_B123_120_INMUX_0_MASK)

#define VIRT_WRAPPER_REG_B123_120_INMUX_1_MASK   (0x700U)
#define VIRT_WRAPPER_REG_B123_120_INMUX_1_SHIFT  (8U)
#define VIRT_WRAPPER_REG_B123_120_INMUX_1_WIDTH  (3U)
#define VIRT_WRAPPER_REG_B123_120_INMUX_1(x)     (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B123_120_INMUX_1_SHIFT)) & VIRT_WRAPPER_REG_B123_120_INMUX_1_MASK)

#define VIRT_WRAPPER_REG_B123_120_INMUX_2_MASK   (0x70000U)
#define VIRT_WRAPPER_REG_B123_120_INMUX_2_SHIFT  (16U)
#define VIRT_WRAPPER_REG_B123_120_INMUX_2_WIDTH  (3U)
#define VIRT_WRAPPER_REG_B123_120_INMUX_2(x)     (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B123_120_INMUX_2_SHIFT)) & VIRT_WRAPPER_REG_B123_120_INMUX_2_MASK)

#define VIRT_WRAPPER_REG_B123_120_INMUX_3_MASK   (0x7000000U)
#define VIRT_WRAPPER_REG_B123_120_INMUX_3_SHIFT  (24U)
#define VIRT_WRAPPER_REG_B123_120_INMUX_3_WIDTH  (3U)
#define VIRT_WRAPPER_REG_B123_120_INMUX_3(x)     (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B123_120_INMUX_3_SHIFT)) & VIRT_WRAPPER_REG_B123_120_INMUX_3_MASK)
/*! @} */

/*! @name REG_B127_124 - Parameter_n Register */
/*! @{ */

#define VIRT_WRAPPER_REG_B127_124_INMUX_0_MASK   (0x7U)
#define VIRT_WRAPPER_REG_B127_124_INMUX_0_SHIFT  (0U)
#define VIRT_WRAPPER_REG_B127_124_INMUX_0_WIDTH  (3U)
#define VIRT_WRAPPER_REG_B127_124_INMUX_0(x)     (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B127_124_INMUX_0_SHIFT)) & VIRT_WRAPPER_REG_B127_124_INMUX_0_MASK)

#define VIRT_WRAPPER_REG_B127_124_INMUX_1_MASK   (0x700U)
#define VIRT_WRAPPER_REG_B127_124_INMUX_1_SHIFT  (8U)
#define VIRT_WRAPPER_REG_B127_124_INMUX_1_WIDTH  (3U)
#define VIRT_WRAPPER_REG_B127_124_INMUX_1(x)     (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B127_124_INMUX_1_SHIFT)) & VIRT_WRAPPER_REG_B127_124_INMUX_1_MASK)

#define VIRT_WRAPPER_REG_B127_124_INMUX_2_MASK   (0x70000U)
#define VIRT_WRAPPER_REG_B127_124_INMUX_2_SHIFT  (16U)
#define VIRT_WRAPPER_REG_B127_124_INMUX_2_WIDTH  (3U)
#define VIRT_WRAPPER_REG_B127_124_INMUX_2(x)     (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B127_124_INMUX_2_SHIFT)) & VIRT_WRAPPER_REG_B127_124_INMUX_2_MASK)

#define VIRT_WRAPPER_REG_B127_124_INMUX_3_MASK   (0x7000000U)
#define VIRT_WRAPPER_REG_B127_124_INMUX_3_SHIFT  (24U)
#define VIRT_WRAPPER_REG_B127_124_INMUX_3_WIDTH  (3U)
#define VIRT_WRAPPER_REG_B127_124_INMUX_3(x)     (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B127_124_INMUX_3_SHIFT)) & VIRT_WRAPPER_REG_B127_124_INMUX_3_MASK)
/*! @} */

/*! @name REG_B131_128 - Parameter_n Register */
/*! @{ */

#define VIRT_WRAPPER_REG_B131_128_INMUX_0_MASK   (0x7U)
#define VIRT_WRAPPER_REG_B131_128_INMUX_0_SHIFT  (0U)
#define VIRT_WRAPPER_REG_B131_128_INMUX_0_WIDTH  (3U)
#define VIRT_WRAPPER_REG_B131_128_INMUX_0(x)     (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B131_128_INMUX_0_SHIFT)) & VIRT_WRAPPER_REG_B131_128_INMUX_0_MASK)

#define VIRT_WRAPPER_REG_B131_128_INMUX_1_MASK   (0x700U)
#define VIRT_WRAPPER_REG_B131_128_INMUX_1_SHIFT  (8U)
#define VIRT_WRAPPER_REG_B131_128_INMUX_1_WIDTH  (3U)
#define VIRT_WRAPPER_REG_B131_128_INMUX_1(x)     (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B131_128_INMUX_1_SHIFT)) & VIRT_WRAPPER_REG_B131_128_INMUX_1_MASK)

#define VIRT_WRAPPER_REG_B131_128_INMUX_2_MASK   (0x70000U)
#define VIRT_WRAPPER_REG_B131_128_INMUX_2_SHIFT  (16U)
#define VIRT_WRAPPER_REG_B131_128_INMUX_2_WIDTH  (3U)
#define VIRT_WRAPPER_REG_B131_128_INMUX_2(x)     (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B131_128_INMUX_2_SHIFT)) & VIRT_WRAPPER_REG_B131_128_INMUX_2_MASK)

#define VIRT_WRAPPER_REG_B131_128_INMUX_3_MASK   (0x7000000U)
#define VIRT_WRAPPER_REG_B131_128_INMUX_3_SHIFT  (24U)
#define VIRT_WRAPPER_REG_B131_128_INMUX_3_WIDTH  (3U)
#define VIRT_WRAPPER_REG_B131_128_INMUX_3(x)     (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B131_128_INMUX_3_SHIFT)) & VIRT_WRAPPER_REG_B131_128_INMUX_3_MASK)
/*! @} */

/*! @name REG_B135_132 - Parameter_n Register */
/*! @{ */

#define VIRT_WRAPPER_REG_B135_132_INMUX_0_MASK   (0x7U)
#define VIRT_WRAPPER_REG_B135_132_INMUX_0_SHIFT  (0U)
#define VIRT_WRAPPER_REG_B135_132_INMUX_0_WIDTH  (3U)
#define VIRT_WRAPPER_REG_B135_132_INMUX_0(x)     (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B135_132_INMUX_0_SHIFT)) & VIRT_WRAPPER_REG_B135_132_INMUX_0_MASK)

#define VIRT_WRAPPER_REG_B135_132_INMUX_1_MASK   (0x700U)
#define VIRT_WRAPPER_REG_B135_132_INMUX_1_SHIFT  (8U)
#define VIRT_WRAPPER_REG_B135_132_INMUX_1_WIDTH  (3U)
#define VIRT_WRAPPER_REG_B135_132_INMUX_1(x)     (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B135_132_INMUX_1_SHIFT)) & VIRT_WRAPPER_REG_B135_132_INMUX_1_MASK)

#define VIRT_WRAPPER_REG_B135_132_INMUX_2_MASK   (0x70000U)
#define VIRT_WRAPPER_REG_B135_132_INMUX_2_SHIFT  (16U)
#define VIRT_WRAPPER_REG_B135_132_INMUX_2_WIDTH  (3U)
#define VIRT_WRAPPER_REG_B135_132_INMUX_2(x)     (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B135_132_INMUX_2_SHIFT)) & VIRT_WRAPPER_REG_B135_132_INMUX_2_MASK)

#define VIRT_WRAPPER_REG_B135_132_INMUX_3_MASK   (0x7000000U)
#define VIRT_WRAPPER_REG_B135_132_INMUX_3_SHIFT  (24U)
#define VIRT_WRAPPER_REG_B135_132_INMUX_3_WIDTH  (3U)
#define VIRT_WRAPPER_REG_B135_132_INMUX_3(x)     (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B135_132_INMUX_3_SHIFT)) & VIRT_WRAPPER_REG_B135_132_INMUX_3_MASK)
/*! @} */

/*! @name REG_B147_144 - Parameter_n Register */
/*! @{ */

#define VIRT_WRAPPER_REG_B147_144_INMUX_0_MASK   (0x7U)
#define VIRT_WRAPPER_REG_B147_144_INMUX_0_SHIFT  (0U)
#define VIRT_WRAPPER_REG_B147_144_INMUX_0_WIDTH  (3U)
#define VIRT_WRAPPER_REG_B147_144_INMUX_0(x)     (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B147_144_INMUX_0_SHIFT)) & VIRT_WRAPPER_REG_B147_144_INMUX_0_MASK)

#define VIRT_WRAPPER_REG_B147_144_INMUX_1_MASK   (0x700U)
#define VIRT_WRAPPER_REG_B147_144_INMUX_1_SHIFT  (8U)
#define VIRT_WRAPPER_REG_B147_144_INMUX_1_WIDTH  (3U)
#define VIRT_WRAPPER_REG_B147_144_INMUX_1(x)     (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B147_144_INMUX_1_SHIFT)) & VIRT_WRAPPER_REG_B147_144_INMUX_1_MASK)

#define VIRT_WRAPPER_REG_B147_144_INMUX_2_MASK   (0x70000U)
#define VIRT_WRAPPER_REG_B147_144_INMUX_2_SHIFT  (16U)
#define VIRT_WRAPPER_REG_B147_144_INMUX_2_WIDTH  (3U)
#define VIRT_WRAPPER_REG_B147_144_INMUX_2(x)     (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B147_144_INMUX_2_SHIFT)) & VIRT_WRAPPER_REG_B147_144_INMUX_2_MASK)

#define VIRT_WRAPPER_REG_B147_144_INMUX_3_MASK   (0x7000000U)
#define VIRT_WRAPPER_REG_B147_144_INMUX_3_SHIFT  (24U)
#define VIRT_WRAPPER_REG_B147_144_INMUX_3_WIDTH  (3U)
#define VIRT_WRAPPER_REG_B147_144_INMUX_3(x)     (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B147_144_INMUX_3_SHIFT)) & VIRT_WRAPPER_REG_B147_144_INMUX_3_MASK)
/*! @} */

/*! @name REG_B151_148 - Parameter_n Register */
/*! @{ */

#define VIRT_WRAPPER_REG_B151_148_INMUX_0_MASK   (0x7U)
#define VIRT_WRAPPER_REG_B151_148_INMUX_0_SHIFT  (0U)
#define VIRT_WRAPPER_REG_B151_148_INMUX_0_WIDTH  (3U)
#define VIRT_WRAPPER_REG_B151_148_INMUX_0(x)     (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B151_148_INMUX_0_SHIFT)) & VIRT_WRAPPER_REG_B151_148_INMUX_0_MASK)

#define VIRT_WRAPPER_REG_B151_148_INMUX_1_MASK   (0x700U)
#define VIRT_WRAPPER_REG_B151_148_INMUX_1_SHIFT  (8U)
#define VIRT_WRAPPER_REG_B151_148_INMUX_1_WIDTH  (3U)
#define VIRT_WRAPPER_REG_B151_148_INMUX_1(x)     (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B151_148_INMUX_1_SHIFT)) & VIRT_WRAPPER_REG_B151_148_INMUX_1_MASK)
/*! @} */

/*! @name REG_B155_152 - Parameter_n Register */
/*! @{ */

#define VIRT_WRAPPER_REG_B155_152_INMUX_0_MASK   (0x7U)
#define VIRT_WRAPPER_REG_B155_152_INMUX_0_SHIFT  (0U)
#define VIRT_WRAPPER_REG_B155_152_INMUX_0_WIDTH  (3U)
#define VIRT_WRAPPER_REG_B155_152_INMUX_0(x)     (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B155_152_INMUX_0_SHIFT)) & VIRT_WRAPPER_REG_B155_152_INMUX_0_MASK)

#define VIRT_WRAPPER_REG_B155_152_INMUX_1_MASK   (0x700U)
#define VIRT_WRAPPER_REG_B155_152_INMUX_1_SHIFT  (8U)
#define VIRT_WRAPPER_REG_B155_152_INMUX_1_WIDTH  (3U)
#define VIRT_WRAPPER_REG_B155_152_INMUX_1(x)     (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B155_152_INMUX_1_SHIFT)) & VIRT_WRAPPER_REG_B155_152_INMUX_1_MASK)

#define VIRT_WRAPPER_REG_B155_152_INMUX_2_MASK   (0x70000U)
#define VIRT_WRAPPER_REG_B155_152_INMUX_2_SHIFT  (16U)
#define VIRT_WRAPPER_REG_B155_152_INMUX_2_WIDTH  (3U)
#define VIRT_WRAPPER_REG_B155_152_INMUX_2(x)     (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B155_152_INMUX_2_SHIFT)) & VIRT_WRAPPER_REG_B155_152_INMUX_2_MASK)

#define VIRT_WRAPPER_REG_B155_152_INMUX_3_MASK   (0x7000000U)
#define VIRT_WRAPPER_REG_B155_152_INMUX_3_SHIFT  (24U)
#define VIRT_WRAPPER_REG_B155_152_INMUX_3_WIDTH  (3U)
#define VIRT_WRAPPER_REG_B155_152_INMUX_3(x)     (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B155_152_INMUX_3_SHIFT)) & VIRT_WRAPPER_REG_B155_152_INMUX_3_MASK)
/*! @} */

/*! @name REG_B159_156 - Parameter_n Register */
/*! @{ */

#define VIRT_WRAPPER_REG_B159_156_INMUX_0_MASK   (0x7U)
#define VIRT_WRAPPER_REG_B159_156_INMUX_0_SHIFT  (0U)
#define VIRT_WRAPPER_REG_B159_156_INMUX_0_WIDTH  (3U)
#define VIRT_WRAPPER_REG_B159_156_INMUX_0(x)     (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B159_156_INMUX_0_SHIFT)) & VIRT_WRAPPER_REG_B159_156_INMUX_0_MASK)

#define VIRT_WRAPPER_REG_B159_156_INMUX_1_MASK   (0x700U)
#define VIRT_WRAPPER_REG_B159_156_INMUX_1_SHIFT  (8U)
#define VIRT_WRAPPER_REG_B159_156_INMUX_1_WIDTH  (3U)
#define VIRT_WRAPPER_REG_B159_156_INMUX_1(x)     (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B159_156_INMUX_1_SHIFT)) & VIRT_WRAPPER_REG_B159_156_INMUX_1_MASK)

#define VIRT_WRAPPER_REG_B159_156_INMUX_2_MASK   (0x70000U)
#define VIRT_WRAPPER_REG_B159_156_INMUX_2_SHIFT  (16U)
#define VIRT_WRAPPER_REG_B159_156_INMUX_2_WIDTH  (3U)
#define VIRT_WRAPPER_REG_B159_156_INMUX_2(x)     (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B159_156_INMUX_2_SHIFT)) & VIRT_WRAPPER_REG_B159_156_INMUX_2_MASK)

#define VIRT_WRAPPER_REG_B159_156_INMUX_3_MASK   (0x7000000U)
#define VIRT_WRAPPER_REG_B159_156_INMUX_3_SHIFT  (24U)
#define VIRT_WRAPPER_REG_B159_156_INMUX_3_WIDTH  (3U)
#define VIRT_WRAPPER_REG_B159_156_INMUX_3(x)     (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B159_156_INMUX_3_SHIFT)) & VIRT_WRAPPER_REG_B159_156_INMUX_3_MASK)
/*! @} */

/*! @name REG_B163_160 - Parameter_n Register */
/*! @{ */

#define VIRT_WRAPPER_REG_B163_160_INMUX_0_MASK   (0x7U)
#define VIRT_WRAPPER_REG_B163_160_INMUX_0_SHIFT  (0U)
#define VIRT_WRAPPER_REG_B163_160_INMUX_0_WIDTH  (3U)
#define VIRT_WRAPPER_REG_B163_160_INMUX_0(x)     (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B163_160_INMUX_0_SHIFT)) & VIRT_WRAPPER_REG_B163_160_INMUX_0_MASK)

#define VIRT_WRAPPER_REG_B163_160_INMUX_1_MASK   (0x700U)
#define VIRT_WRAPPER_REG_B163_160_INMUX_1_SHIFT  (8U)
#define VIRT_WRAPPER_REG_B163_160_INMUX_1_WIDTH  (3U)
#define VIRT_WRAPPER_REG_B163_160_INMUX_1(x)     (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B163_160_INMUX_1_SHIFT)) & VIRT_WRAPPER_REG_B163_160_INMUX_1_MASK)

#define VIRT_WRAPPER_REG_B163_160_INMUX_2_MASK   (0x70000U)
#define VIRT_WRAPPER_REG_B163_160_INMUX_2_SHIFT  (16U)
#define VIRT_WRAPPER_REG_B163_160_INMUX_2_WIDTH  (3U)
#define VIRT_WRAPPER_REG_B163_160_INMUX_2(x)     (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B163_160_INMUX_2_SHIFT)) & VIRT_WRAPPER_REG_B163_160_INMUX_2_MASK)

#define VIRT_WRAPPER_REG_B163_160_INMUX_3_MASK   (0x7000000U)
#define VIRT_WRAPPER_REG_B163_160_INMUX_3_SHIFT  (24U)
#define VIRT_WRAPPER_REG_B163_160_INMUX_3_WIDTH  (3U)
#define VIRT_WRAPPER_REG_B163_160_INMUX_3(x)     (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B163_160_INMUX_3_SHIFT)) & VIRT_WRAPPER_REG_B163_160_INMUX_3_MASK)
/*! @} */

/*! @name REG_B167_164 - Parameter_n Register */
/*! @{ */

#define VIRT_WRAPPER_REG_B167_164_INMUX_0_MASK   (0x7U)
#define VIRT_WRAPPER_REG_B167_164_INMUX_0_SHIFT  (0U)
#define VIRT_WRAPPER_REG_B167_164_INMUX_0_WIDTH  (3U)
#define VIRT_WRAPPER_REG_B167_164_INMUX_0(x)     (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B167_164_INMUX_0_SHIFT)) & VIRT_WRAPPER_REG_B167_164_INMUX_0_MASK)

#define VIRT_WRAPPER_REG_B167_164_INMUX_1_MASK   (0x700U)
#define VIRT_WRAPPER_REG_B167_164_INMUX_1_SHIFT  (8U)
#define VIRT_WRAPPER_REG_B167_164_INMUX_1_WIDTH  (3U)
#define VIRT_WRAPPER_REG_B167_164_INMUX_1(x)     (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B167_164_INMUX_1_SHIFT)) & VIRT_WRAPPER_REG_B167_164_INMUX_1_MASK)

#define VIRT_WRAPPER_REG_B167_164_INMUX_2_MASK   (0x70000U)
#define VIRT_WRAPPER_REG_B167_164_INMUX_2_SHIFT  (16U)
#define VIRT_WRAPPER_REG_B167_164_INMUX_2_WIDTH  (3U)
#define VIRT_WRAPPER_REG_B167_164_INMUX_2(x)     (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B167_164_INMUX_2_SHIFT)) & VIRT_WRAPPER_REG_B167_164_INMUX_2_MASK)

#define VIRT_WRAPPER_REG_B167_164_INMUX_3_MASK   (0x7000000U)
#define VIRT_WRAPPER_REG_B167_164_INMUX_3_SHIFT  (24U)
#define VIRT_WRAPPER_REG_B167_164_INMUX_3_WIDTH  (3U)
#define VIRT_WRAPPER_REG_B167_164_INMUX_3(x)     (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B167_164_INMUX_3_SHIFT)) & VIRT_WRAPPER_REG_B167_164_INMUX_3_MASK)
/*! @} */

/*! @name REG_B171_168 - Parameter_n Register */
/*! @{ */

#define VIRT_WRAPPER_REG_B171_168_INMUX_0_MASK   (0x7U)
#define VIRT_WRAPPER_REG_B171_168_INMUX_0_SHIFT  (0U)
#define VIRT_WRAPPER_REG_B171_168_INMUX_0_WIDTH  (3U)
#define VIRT_WRAPPER_REG_B171_168_INMUX_0(x)     (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B171_168_INMUX_0_SHIFT)) & VIRT_WRAPPER_REG_B171_168_INMUX_0_MASK)

#define VIRT_WRAPPER_REG_B171_168_INMUX_1_MASK   (0x700U)
#define VIRT_WRAPPER_REG_B171_168_INMUX_1_SHIFT  (8U)
#define VIRT_WRAPPER_REG_B171_168_INMUX_1_WIDTH  (3U)
#define VIRT_WRAPPER_REG_B171_168_INMUX_1(x)     (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B171_168_INMUX_1_SHIFT)) & VIRT_WRAPPER_REG_B171_168_INMUX_1_MASK)

#define VIRT_WRAPPER_REG_B171_168_INMUX_2_MASK   (0x70000U)
#define VIRT_WRAPPER_REG_B171_168_INMUX_2_SHIFT  (16U)
#define VIRT_WRAPPER_REG_B171_168_INMUX_2_WIDTH  (3U)
#define VIRT_WRAPPER_REG_B171_168_INMUX_2(x)     (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B171_168_INMUX_2_SHIFT)) & VIRT_WRAPPER_REG_B171_168_INMUX_2_MASK)

#define VIRT_WRAPPER_REG_B171_168_INMUX_3_MASK   (0x7000000U)
#define VIRT_WRAPPER_REG_B171_168_INMUX_3_SHIFT  (24U)
#define VIRT_WRAPPER_REG_B171_168_INMUX_3_WIDTH  (3U)
#define VIRT_WRAPPER_REG_B171_168_INMUX_3(x)     (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B171_168_INMUX_3_SHIFT)) & VIRT_WRAPPER_REG_B171_168_INMUX_3_MASK)
/*! @} */

/*! @name REG_B175_172 - Parameter_n Register */
/*! @{ */

#define VIRT_WRAPPER_REG_B175_172_INMUX_0_MASK   (0x7U)
#define VIRT_WRAPPER_REG_B175_172_INMUX_0_SHIFT  (0U)
#define VIRT_WRAPPER_REG_B175_172_INMUX_0_WIDTH  (3U)
#define VIRT_WRAPPER_REG_B175_172_INMUX_0(x)     (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B175_172_INMUX_0_SHIFT)) & VIRT_WRAPPER_REG_B175_172_INMUX_0_MASK)

#define VIRT_WRAPPER_REG_B175_172_INMUX_1_MASK   (0x700U)
#define VIRT_WRAPPER_REG_B175_172_INMUX_1_SHIFT  (8U)
#define VIRT_WRAPPER_REG_B175_172_INMUX_1_WIDTH  (3U)
#define VIRT_WRAPPER_REG_B175_172_INMUX_1(x)     (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B175_172_INMUX_1_SHIFT)) & VIRT_WRAPPER_REG_B175_172_INMUX_1_MASK)

#define VIRT_WRAPPER_REG_B175_172_INMUX_2_MASK   (0x70000U)
#define VIRT_WRAPPER_REG_B175_172_INMUX_2_SHIFT  (16U)
#define VIRT_WRAPPER_REG_B175_172_INMUX_2_WIDTH  (3U)
#define VIRT_WRAPPER_REG_B175_172_INMUX_2(x)     (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B175_172_INMUX_2_SHIFT)) & VIRT_WRAPPER_REG_B175_172_INMUX_2_MASK)

#define VIRT_WRAPPER_REG_B175_172_INMUX_3_MASK   (0x7000000U)
#define VIRT_WRAPPER_REG_B175_172_INMUX_3_SHIFT  (24U)
#define VIRT_WRAPPER_REG_B175_172_INMUX_3_WIDTH  (3U)
#define VIRT_WRAPPER_REG_B175_172_INMUX_3(x)     (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B175_172_INMUX_3_SHIFT)) & VIRT_WRAPPER_REG_B175_172_INMUX_3_MASK)
/*! @} */

/*! @name REG_B179_176 - Parameter_n Register */
/*! @{ */

#define VIRT_WRAPPER_REG_B179_176_INMUX_0_MASK   (0x7U)
#define VIRT_WRAPPER_REG_B179_176_INMUX_0_SHIFT  (0U)
#define VIRT_WRAPPER_REG_B179_176_INMUX_0_WIDTH  (3U)
#define VIRT_WRAPPER_REG_B179_176_INMUX_0(x)     (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B179_176_INMUX_0_SHIFT)) & VIRT_WRAPPER_REG_B179_176_INMUX_0_MASK)

#define VIRT_WRAPPER_REG_B179_176_INMUX_1_MASK   (0x700U)
#define VIRT_WRAPPER_REG_B179_176_INMUX_1_SHIFT  (8U)
#define VIRT_WRAPPER_REG_B179_176_INMUX_1_WIDTH  (3U)
#define VIRT_WRAPPER_REG_B179_176_INMUX_1(x)     (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B179_176_INMUX_1_SHIFT)) & VIRT_WRAPPER_REG_B179_176_INMUX_1_MASK)

#define VIRT_WRAPPER_REG_B179_176_INMUX_2_MASK   (0x70000U)
#define VIRT_WRAPPER_REG_B179_176_INMUX_2_SHIFT  (16U)
#define VIRT_WRAPPER_REG_B179_176_INMUX_2_WIDTH  (3U)
#define VIRT_WRAPPER_REG_B179_176_INMUX_2(x)     (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B179_176_INMUX_2_SHIFT)) & VIRT_WRAPPER_REG_B179_176_INMUX_2_MASK)

#define VIRT_WRAPPER_REG_B179_176_INMUX_3_MASK   (0x7000000U)
#define VIRT_WRAPPER_REG_B179_176_INMUX_3_SHIFT  (24U)
#define VIRT_WRAPPER_REG_B179_176_INMUX_3_WIDTH  (3U)
#define VIRT_WRAPPER_REG_B179_176_INMUX_3(x)     (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B179_176_INMUX_3_SHIFT)) & VIRT_WRAPPER_REG_B179_176_INMUX_3_MASK)
/*! @} */

/*! @name REG_B183_180 - Parameter_n Register */
/*! @{ */

#define VIRT_WRAPPER_REG_B183_180_INMUX_0_MASK   (0x7U)
#define VIRT_WRAPPER_REG_B183_180_INMUX_0_SHIFT  (0U)
#define VIRT_WRAPPER_REG_B183_180_INMUX_0_WIDTH  (3U)
#define VIRT_WRAPPER_REG_B183_180_INMUX_0(x)     (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B183_180_INMUX_0_SHIFT)) & VIRT_WRAPPER_REG_B183_180_INMUX_0_MASK)

#define VIRT_WRAPPER_REG_B183_180_INMUX_1_MASK   (0x700U)
#define VIRT_WRAPPER_REG_B183_180_INMUX_1_SHIFT  (8U)
#define VIRT_WRAPPER_REG_B183_180_INMUX_1_WIDTH  (3U)
#define VIRT_WRAPPER_REG_B183_180_INMUX_1(x)     (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B183_180_INMUX_1_SHIFT)) & VIRT_WRAPPER_REG_B183_180_INMUX_1_MASK)

#define VIRT_WRAPPER_REG_B183_180_INMUX_2_MASK   (0x70000U)
#define VIRT_WRAPPER_REG_B183_180_INMUX_2_SHIFT  (16U)
#define VIRT_WRAPPER_REG_B183_180_INMUX_2_WIDTH  (3U)
#define VIRT_WRAPPER_REG_B183_180_INMUX_2(x)     (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B183_180_INMUX_2_SHIFT)) & VIRT_WRAPPER_REG_B183_180_INMUX_2_MASK)

#define VIRT_WRAPPER_REG_B183_180_INMUX_3_MASK   (0x7000000U)
#define VIRT_WRAPPER_REG_B183_180_INMUX_3_SHIFT  (24U)
#define VIRT_WRAPPER_REG_B183_180_INMUX_3_WIDTH  (3U)
#define VIRT_WRAPPER_REG_B183_180_INMUX_3(x)     (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B183_180_INMUX_3_SHIFT)) & VIRT_WRAPPER_REG_B183_180_INMUX_3_MASK)
/*! @} */

/*! @name REG_B187_184 - Parameter_n Register */
/*! @{ */

#define VIRT_WRAPPER_REG_B187_184_INMUX_0_MASK   (0x7U)
#define VIRT_WRAPPER_REG_B187_184_INMUX_0_SHIFT  (0U)
#define VIRT_WRAPPER_REG_B187_184_INMUX_0_WIDTH  (3U)
#define VIRT_WRAPPER_REG_B187_184_INMUX_0(x)     (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B187_184_INMUX_0_SHIFT)) & VIRT_WRAPPER_REG_B187_184_INMUX_0_MASK)

#define VIRT_WRAPPER_REG_B187_184_INMUX_1_MASK   (0x700U)
#define VIRT_WRAPPER_REG_B187_184_INMUX_1_SHIFT  (8U)
#define VIRT_WRAPPER_REG_B187_184_INMUX_1_WIDTH  (3U)
#define VIRT_WRAPPER_REG_B187_184_INMUX_1(x)     (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B187_184_INMUX_1_SHIFT)) & VIRT_WRAPPER_REG_B187_184_INMUX_1_MASK)

#define VIRT_WRAPPER_REG_B187_184_INMUX_2_MASK   (0x70000U)
#define VIRT_WRAPPER_REG_B187_184_INMUX_2_SHIFT  (16U)
#define VIRT_WRAPPER_REG_B187_184_INMUX_2_WIDTH  (3U)
#define VIRT_WRAPPER_REG_B187_184_INMUX_2(x)     (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B187_184_INMUX_2_SHIFT)) & VIRT_WRAPPER_REG_B187_184_INMUX_2_MASK)

#define VIRT_WRAPPER_REG_B187_184_INMUX_3_MASK   (0x7000000U)
#define VIRT_WRAPPER_REG_B187_184_INMUX_3_SHIFT  (24U)
#define VIRT_WRAPPER_REG_B187_184_INMUX_3_WIDTH  (3U)
#define VIRT_WRAPPER_REG_B187_184_INMUX_3(x)     (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B187_184_INMUX_3_SHIFT)) & VIRT_WRAPPER_REG_B187_184_INMUX_3_MASK)
/*! @} */

/*! @name REG_B191_188 - Parameter_n Register */
/*! @{ */

#define VIRT_WRAPPER_REG_B191_188_INMUX_0_MASK   (0x7U)
#define VIRT_WRAPPER_REG_B191_188_INMUX_0_SHIFT  (0U)
#define VIRT_WRAPPER_REG_B191_188_INMUX_0_WIDTH  (3U)
#define VIRT_WRAPPER_REG_B191_188_INMUX_0(x)     (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B191_188_INMUX_0_SHIFT)) & VIRT_WRAPPER_REG_B191_188_INMUX_0_MASK)

#define VIRT_WRAPPER_REG_B191_188_INMUX_1_MASK   (0x700U)
#define VIRT_WRAPPER_REG_B191_188_INMUX_1_SHIFT  (8U)
#define VIRT_WRAPPER_REG_B191_188_INMUX_1_WIDTH  (3U)
#define VIRT_WRAPPER_REG_B191_188_INMUX_1(x)     (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B191_188_INMUX_1_SHIFT)) & VIRT_WRAPPER_REG_B191_188_INMUX_1_MASK)

#define VIRT_WRAPPER_REG_B191_188_INMUX_2_MASK   (0x70000U)
#define VIRT_WRAPPER_REG_B191_188_INMUX_2_SHIFT  (16U)
#define VIRT_WRAPPER_REG_B191_188_INMUX_2_WIDTH  (3U)
#define VIRT_WRAPPER_REG_B191_188_INMUX_2(x)     (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B191_188_INMUX_2_SHIFT)) & VIRT_WRAPPER_REG_B191_188_INMUX_2_MASK)

#define VIRT_WRAPPER_REG_B191_188_INMUX_3_MASK   (0x7000000U)
#define VIRT_WRAPPER_REG_B191_188_INMUX_3_SHIFT  (24U)
#define VIRT_WRAPPER_REG_B191_188_INMUX_3_WIDTH  (3U)
#define VIRT_WRAPPER_REG_B191_188_INMUX_3(x)     (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B191_188_INMUX_3_SHIFT)) & VIRT_WRAPPER_REG_B191_188_INMUX_3_MASK)
/*! @} */

/*! @name REG_B195_192 - Parameter_n Register */
/*! @{ */

#define VIRT_WRAPPER_REG_B195_192_INMUX_0_MASK   (0x7U)
#define VIRT_WRAPPER_REG_B195_192_INMUX_0_SHIFT  (0U)
#define VIRT_WRAPPER_REG_B195_192_INMUX_0_WIDTH  (3U)
#define VIRT_WRAPPER_REG_B195_192_INMUX_0(x)     (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B195_192_INMUX_0_SHIFT)) & VIRT_WRAPPER_REG_B195_192_INMUX_0_MASK)

#define VIRT_WRAPPER_REG_B195_192_INMUX_1_MASK   (0x700U)
#define VIRT_WRAPPER_REG_B195_192_INMUX_1_SHIFT  (8U)
#define VIRT_WRAPPER_REG_B195_192_INMUX_1_WIDTH  (3U)
#define VIRT_WRAPPER_REG_B195_192_INMUX_1(x)     (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B195_192_INMUX_1_SHIFT)) & VIRT_WRAPPER_REG_B195_192_INMUX_1_MASK)

#define VIRT_WRAPPER_REG_B195_192_INMUX_2_MASK   (0x70000U)
#define VIRT_WRAPPER_REG_B195_192_INMUX_2_SHIFT  (16U)
#define VIRT_WRAPPER_REG_B195_192_INMUX_2_WIDTH  (3U)
#define VIRT_WRAPPER_REG_B195_192_INMUX_2(x)     (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B195_192_INMUX_2_SHIFT)) & VIRT_WRAPPER_REG_B195_192_INMUX_2_MASK)

#define VIRT_WRAPPER_REG_B195_192_INMUX_3_MASK   (0x7000000U)
#define VIRT_WRAPPER_REG_B195_192_INMUX_3_SHIFT  (24U)
#define VIRT_WRAPPER_REG_B195_192_INMUX_3_WIDTH  (3U)
#define VIRT_WRAPPER_REG_B195_192_INMUX_3(x)     (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B195_192_INMUX_3_SHIFT)) & VIRT_WRAPPER_REG_B195_192_INMUX_3_MASK)
/*! @} */

/*! @name REG_B199_196 - Parameter_n Register */
/*! @{ */

#define VIRT_WRAPPER_REG_B199_196_INMUX_0_MASK   (0x7U)
#define VIRT_WRAPPER_REG_B199_196_INMUX_0_SHIFT  (0U)
#define VIRT_WRAPPER_REG_B199_196_INMUX_0_WIDTH  (3U)
#define VIRT_WRAPPER_REG_B199_196_INMUX_0(x)     (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B199_196_INMUX_0_SHIFT)) & VIRT_WRAPPER_REG_B199_196_INMUX_0_MASK)

#define VIRT_WRAPPER_REG_B199_196_INMUX_1_MASK   (0x700U)
#define VIRT_WRAPPER_REG_B199_196_INMUX_1_SHIFT  (8U)
#define VIRT_WRAPPER_REG_B199_196_INMUX_1_WIDTH  (3U)
#define VIRT_WRAPPER_REG_B199_196_INMUX_1(x)     (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B199_196_INMUX_1_SHIFT)) & VIRT_WRAPPER_REG_B199_196_INMUX_1_MASK)

#define VIRT_WRAPPER_REG_B199_196_INMUX_2_MASK   (0x70000U)
#define VIRT_WRAPPER_REG_B199_196_INMUX_2_SHIFT  (16U)
#define VIRT_WRAPPER_REG_B199_196_INMUX_2_WIDTH  (3U)
#define VIRT_WRAPPER_REG_B199_196_INMUX_2(x)     (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B199_196_INMUX_2_SHIFT)) & VIRT_WRAPPER_REG_B199_196_INMUX_2_MASK)

#define VIRT_WRAPPER_REG_B199_196_INMUX_3_MASK   (0x7000000U)
#define VIRT_WRAPPER_REG_B199_196_INMUX_3_SHIFT  (24U)
#define VIRT_WRAPPER_REG_B199_196_INMUX_3_WIDTH  (3U)
#define VIRT_WRAPPER_REG_B199_196_INMUX_3(x)     (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B199_196_INMUX_3_SHIFT)) & VIRT_WRAPPER_REG_B199_196_INMUX_3_MASK)
/*! @} */

/*! @name REG_B203_200 - Parameter_n Register */
/*! @{ */

#define VIRT_WRAPPER_REG_B203_200_INMUX_0_MASK   (0x7U)
#define VIRT_WRAPPER_REG_B203_200_INMUX_0_SHIFT  (0U)
#define VIRT_WRAPPER_REG_B203_200_INMUX_0_WIDTH  (3U)
#define VIRT_WRAPPER_REG_B203_200_INMUX_0(x)     (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B203_200_INMUX_0_SHIFT)) & VIRT_WRAPPER_REG_B203_200_INMUX_0_MASK)

#define VIRT_WRAPPER_REG_B203_200_INMUX_1_MASK   (0x700U)
#define VIRT_WRAPPER_REG_B203_200_INMUX_1_SHIFT  (8U)
#define VIRT_WRAPPER_REG_B203_200_INMUX_1_WIDTH  (3U)
#define VIRT_WRAPPER_REG_B203_200_INMUX_1(x)     (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B203_200_INMUX_1_SHIFT)) & VIRT_WRAPPER_REG_B203_200_INMUX_1_MASK)

#define VIRT_WRAPPER_REG_B203_200_INMUX_2_MASK   (0x70000U)
#define VIRT_WRAPPER_REG_B203_200_INMUX_2_SHIFT  (16U)
#define VIRT_WRAPPER_REG_B203_200_INMUX_2_WIDTH  (3U)
#define VIRT_WRAPPER_REG_B203_200_INMUX_2(x)     (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B203_200_INMUX_2_SHIFT)) & VIRT_WRAPPER_REG_B203_200_INMUX_2_MASK)
/*! @} */

/*! @name REG_B211_208 - Parameter_n Register */
/*! @{ */

#define VIRT_WRAPPER_REG_B211_208_INMUX_3_MASK   (0x7000000U)
#define VIRT_WRAPPER_REG_B211_208_INMUX_3_SHIFT  (24U)
#define VIRT_WRAPPER_REG_B211_208_INMUX_3_WIDTH  (3U)
#define VIRT_WRAPPER_REG_B211_208_INMUX_3(x)     (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B211_208_INMUX_3_SHIFT)) & VIRT_WRAPPER_REG_B211_208_INMUX_3_MASK)
/*! @} */

/*! @name REG_B215_212 - Parameter_n Register */
/*! @{ */

#define VIRT_WRAPPER_REG_B215_212_INMUX_0_MASK   (0x7U)
#define VIRT_WRAPPER_REG_B215_212_INMUX_0_SHIFT  (0U)
#define VIRT_WRAPPER_REG_B215_212_INMUX_0_WIDTH  (3U)
#define VIRT_WRAPPER_REG_B215_212_INMUX_0(x)     (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B215_212_INMUX_0_SHIFT)) & VIRT_WRAPPER_REG_B215_212_INMUX_0_MASK)

#define VIRT_WRAPPER_REG_B215_212_INMUX_1_MASK   (0x700U)
#define VIRT_WRAPPER_REG_B215_212_INMUX_1_SHIFT  (8U)
#define VIRT_WRAPPER_REG_B215_212_INMUX_1_WIDTH  (3U)
#define VIRT_WRAPPER_REG_B215_212_INMUX_1(x)     (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B215_212_INMUX_1_SHIFT)) & VIRT_WRAPPER_REG_B215_212_INMUX_1_MASK)

#define VIRT_WRAPPER_REG_B215_212_INMUX_2_MASK   (0x70000U)
#define VIRT_WRAPPER_REG_B215_212_INMUX_2_SHIFT  (16U)
#define VIRT_WRAPPER_REG_B215_212_INMUX_2_WIDTH  (3U)
#define VIRT_WRAPPER_REG_B215_212_INMUX_2(x)     (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B215_212_INMUX_2_SHIFT)) & VIRT_WRAPPER_REG_B215_212_INMUX_2_MASK)

#define VIRT_WRAPPER_REG_B215_212_INMUX_3_MASK   (0x7000000U)
#define VIRT_WRAPPER_REG_B215_212_INMUX_3_SHIFT  (24U)
#define VIRT_WRAPPER_REG_B215_212_INMUX_3_WIDTH  (3U)
#define VIRT_WRAPPER_REG_B215_212_INMUX_3(x)     (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B215_212_INMUX_3_SHIFT)) & VIRT_WRAPPER_REG_B215_212_INMUX_3_MASK)
/*! @} */

/*! @name REG_B219_216 - Parameter_n Register */
/*! @{ */

#define VIRT_WRAPPER_REG_B219_216_INMUX_0_MASK   (0x7U)
#define VIRT_WRAPPER_REG_B219_216_INMUX_0_SHIFT  (0U)
#define VIRT_WRAPPER_REG_B219_216_INMUX_0_WIDTH  (3U)
#define VIRT_WRAPPER_REG_B219_216_INMUX_0(x)     (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B219_216_INMUX_0_SHIFT)) & VIRT_WRAPPER_REG_B219_216_INMUX_0_MASK)

#define VIRT_WRAPPER_REG_B219_216_INMUX_1_MASK   (0x700U)
#define VIRT_WRAPPER_REG_B219_216_INMUX_1_SHIFT  (8U)
#define VIRT_WRAPPER_REG_B219_216_INMUX_1_WIDTH  (3U)
#define VIRT_WRAPPER_REG_B219_216_INMUX_1(x)     (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B219_216_INMUX_1_SHIFT)) & VIRT_WRAPPER_REG_B219_216_INMUX_1_MASK)

#define VIRT_WRAPPER_REG_B219_216_INMUX_2_MASK   (0x70000U)
#define VIRT_WRAPPER_REG_B219_216_INMUX_2_SHIFT  (16U)
#define VIRT_WRAPPER_REG_B219_216_INMUX_2_WIDTH  (3U)
#define VIRT_WRAPPER_REG_B219_216_INMUX_2(x)     (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B219_216_INMUX_2_SHIFT)) & VIRT_WRAPPER_REG_B219_216_INMUX_2_MASK)

#define VIRT_WRAPPER_REG_B219_216_INMUX_3_MASK   (0x7000000U)
#define VIRT_WRAPPER_REG_B219_216_INMUX_3_SHIFT  (24U)
#define VIRT_WRAPPER_REG_B219_216_INMUX_3_WIDTH  (3U)
#define VIRT_WRAPPER_REG_B219_216_INMUX_3(x)     (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B219_216_INMUX_3_SHIFT)) & VIRT_WRAPPER_REG_B219_216_INMUX_3_MASK)
/*! @} */

/*! @name REG_B223_220 - Parameter_n Register */
/*! @{ */

#define VIRT_WRAPPER_REG_B223_220_INMUX_0_MASK   (0x7U)
#define VIRT_WRAPPER_REG_B223_220_INMUX_0_SHIFT  (0U)
#define VIRT_WRAPPER_REG_B223_220_INMUX_0_WIDTH  (3U)
#define VIRT_WRAPPER_REG_B223_220_INMUX_0(x)     (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B223_220_INMUX_0_SHIFT)) & VIRT_WRAPPER_REG_B223_220_INMUX_0_MASK)

#define VIRT_WRAPPER_REG_B223_220_INMUX_1_MASK   (0x700U)
#define VIRT_WRAPPER_REG_B223_220_INMUX_1_SHIFT  (8U)
#define VIRT_WRAPPER_REG_B223_220_INMUX_1_WIDTH  (3U)
#define VIRT_WRAPPER_REG_B223_220_INMUX_1(x)     (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B223_220_INMUX_1_SHIFT)) & VIRT_WRAPPER_REG_B223_220_INMUX_1_MASK)

#define VIRT_WRAPPER_REG_B223_220_INMUX_2_MASK   (0x70000U)
#define VIRT_WRAPPER_REG_B223_220_INMUX_2_SHIFT  (16U)
#define VIRT_WRAPPER_REG_B223_220_INMUX_2_WIDTH  (3U)
#define VIRT_WRAPPER_REG_B223_220_INMUX_2(x)     (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B223_220_INMUX_2_SHIFT)) & VIRT_WRAPPER_REG_B223_220_INMUX_2_MASK)

#define VIRT_WRAPPER_REG_B223_220_INMUX_3_MASK   (0x7000000U)
#define VIRT_WRAPPER_REG_B223_220_INMUX_3_SHIFT  (24U)
#define VIRT_WRAPPER_REG_B223_220_INMUX_3_WIDTH  (3U)
#define VIRT_WRAPPER_REG_B223_220_INMUX_3(x)     (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B223_220_INMUX_3_SHIFT)) & VIRT_WRAPPER_REG_B223_220_INMUX_3_MASK)
/*! @} */

/*! @name REG_B227_224 - Parameter_n Register */
/*! @{ */

#define VIRT_WRAPPER_REG_B227_224_INMUX_0_MASK   (0x7U)
#define VIRT_WRAPPER_REG_B227_224_INMUX_0_SHIFT  (0U)
#define VIRT_WRAPPER_REG_B227_224_INMUX_0_WIDTH  (3U)
#define VIRT_WRAPPER_REG_B227_224_INMUX_0(x)     (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B227_224_INMUX_0_SHIFT)) & VIRT_WRAPPER_REG_B227_224_INMUX_0_MASK)

#define VIRT_WRAPPER_REG_B227_224_INMUX_1_MASK   (0x700U)
#define VIRT_WRAPPER_REG_B227_224_INMUX_1_SHIFT  (8U)
#define VIRT_WRAPPER_REG_B227_224_INMUX_1_WIDTH  (3U)
#define VIRT_WRAPPER_REG_B227_224_INMUX_1(x)     (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B227_224_INMUX_1_SHIFT)) & VIRT_WRAPPER_REG_B227_224_INMUX_1_MASK)

#define VIRT_WRAPPER_REG_B227_224_INMUX_2_MASK   (0x70000U)
#define VIRT_WRAPPER_REG_B227_224_INMUX_2_SHIFT  (16U)
#define VIRT_WRAPPER_REG_B227_224_INMUX_2_WIDTH  (3U)
#define VIRT_WRAPPER_REG_B227_224_INMUX_2(x)     (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B227_224_INMUX_2_SHIFT)) & VIRT_WRAPPER_REG_B227_224_INMUX_2_MASK)

#define VIRT_WRAPPER_REG_B227_224_INMUX_3_MASK   (0x7000000U)
#define VIRT_WRAPPER_REG_B227_224_INMUX_3_SHIFT  (24U)
#define VIRT_WRAPPER_REG_B227_224_INMUX_3_WIDTH  (3U)
#define VIRT_WRAPPER_REG_B227_224_INMUX_3(x)     (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B227_224_INMUX_3_SHIFT)) & VIRT_WRAPPER_REG_B227_224_INMUX_3_MASK)
/*! @} */

/*! @name REG_B231_228 - Parameter_n Register */
/*! @{ */

#define VIRT_WRAPPER_REG_B231_228_INMUX_0_MASK   (0x7U)
#define VIRT_WRAPPER_REG_B231_228_INMUX_0_SHIFT  (0U)
#define VIRT_WRAPPER_REG_B231_228_INMUX_0_WIDTH  (3U)
#define VIRT_WRAPPER_REG_B231_228_INMUX_0(x)     (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B231_228_INMUX_0_SHIFT)) & VIRT_WRAPPER_REG_B231_228_INMUX_0_MASK)

#define VIRT_WRAPPER_REG_B231_228_INMUX_1_MASK   (0x700U)
#define VIRT_WRAPPER_REG_B231_228_INMUX_1_SHIFT  (8U)
#define VIRT_WRAPPER_REG_B231_228_INMUX_1_WIDTH  (3U)
#define VIRT_WRAPPER_REG_B231_228_INMUX_1(x)     (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B231_228_INMUX_1_SHIFT)) & VIRT_WRAPPER_REG_B231_228_INMUX_1_MASK)

#define VIRT_WRAPPER_REG_B231_228_INMUX_2_MASK   (0x70000U)
#define VIRT_WRAPPER_REG_B231_228_INMUX_2_SHIFT  (16U)
#define VIRT_WRAPPER_REG_B231_228_INMUX_2_WIDTH  (3U)
#define VIRT_WRAPPER_REG_B231_228_INMUX_2(x)     (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B231_228_INMUX_2_SHIFT)) & VIRT_WRAPPER_REG_B231_228_INMUX_2_MASK)

#define VIRT_WRAPPER_REG_B231_228_INMUX_3_MASK   (0x7000000U)
#define VIRT_WRAPPER_REG_B231_228_INMUX_3_SHIFT  (24U)
#define VIRT_WRAPPER_REG_B231_228_INMUX_3_WIDTH  (3U)
#define VIRT_WRAPPER_REG_B231_228_INMUX_3(x)     (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B231_228_INMUX_3_SHIFT)) & VIRT_WRAPPER_REG_B231_228_INMUX_3_MASK)
/*! @} */

/*! @name REG_B235_232 - Parameter_n Register */
/*! @{ */

#define VIRT_WRAPPER_REG_B235_232_INMUX_0_MASK   (0x7U)
#define VIRT_WRAPPER_REG_B235_232_INMUX_0_SHIFT  (0U)
#define VIRT_WRAPPER_REG_B235_232_INMUX_0_WIDTH  (3U)
#define VIRT_WRAPPER_REG_B235_232_INMUX_0(x)     (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B235_232_INMUX_0_SHIFT)) & VIRT_WRAPPER_REG_B235_232_INMUX_0_MASK)

#define VIRT_WRAPPER_REG_B235_232_INMUX_1_MASK   (0x700U)
#define VIRT_WRAPPER_REG_B235_232_INMUX_1_SHIFT  (8U)
#define VIRT_WRAPPER_REG_B235_232_INMUX_1_WIDTH  (3U)
#define VIRT_WRAPPER_REG_B235_232_INMUX_1(x)     (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B235_232_INMUX_1_SHIFT)) & VIRT_WRAPPER_REG_B235_232_INMUX_1_MASK)

#define VIRT_WRAPPER_REG_B235_232_INMUX_2_MASK   (0x70000U)
#define VIRT_WRAPPER_REG_B235_232_INMUX_2_SHIFT  (16U)
#define VIRT_WRAPPER_REG_B235_232_INMUX_2_WIDTH  (3U)
#define VIRT_WRAPPER_REG_B235_232_INMUX_2(x)     (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B235_232_INMUX_2_SHIFT)) & VIRT_WRAPPER_REG_B235_232_INMUX_2_MASK)

#define VIRT_WRAPPER_REG_B235_232_INMUX_3_MASK   (0x7000000U)
#define VIRT_WRAPPER_REG_B235_232_INMUX_3_SHIFT  (24U)
#define VIRT_WRAPPER_REG_B235_232_INMUX_3_WIDTH  (3U)
#define VIRT_WRAPPER_REG_B235_232_INMUX_3(x)     (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B235_232_INMUX_3_SHIFT)) & VIRT_WRAPPER_REG_B235_232_INMUX_3_MASK)
/*! @} */

/*! @name REG_B239_236 - Parameter_n Register */
/*! @{ */

#define VIRT_WRAPPER_REG_B239_236_INMUX_0_MASK   (0x7U)
#define VIRT_WRAPPER_REG_B239_236_INMUX_0_SHIFT  (0U)
#define VIRT_WRAPPER_REG_B239_236_INMUX_0_WIDTH  (3U)
#define VIRT_WRAPPER_REG_B239_236_INMUX_0(x)     (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B239_236_INMUX_0_SHIFT)) & VIRT_WRAPPER_REG_B239_236_INMUX_0_MASK)

#define VIRT_WRAPPER_REG_B239_236_INMUX_1_MASK   (0x700U)
#define VIRT_WRAPPER_REG_B239_236_INMUX_1_SHIFT  (8U)
#define VIRT_WRAPPER_REG_B239_236_INMUX_1_WIDTH  (3U)
#define VIRT_WRAPPER_REG_B239_236_INMUX_1(x)     (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B239_236_INMUX_1_SHIFT)) & VIRT_WRAPPER_REG_B239_236_INMUX_1_MASK)

#define VIRT_WRAPPER_REG_B239_236_INMUX_2_MASK   (0x70000U)
#define VIRT_WRAPPER_REG_B239_236_INMUX_2_SHIFT  (16U)
#define VIRT_WRAPPER_REG_B239_236_INMUX_2_WIDTH  (3U)
#define VIRT_WRAPPER_REG_B239_236_INMUX_2(x)     (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B239_236_INMUX_2_SHIFT)) & VIRT_WRAPPER_REG_B239_236_INMUX_2_MASK)

#define VIRT_WRAPPER_REG_B239_236_INMUX_3_MASK   (0x7000000U)
#define VIRT_WRAPPER_REG_B239_236_INMUX_3_SHIFT  (24U)
#define VIRT_WRAPPER_REG_B239_236_INMUX_3_WIDTH  (3U)
#define VIRT_WRAPPER_REG_B239_236_INMUX_3(x)     (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B239_236_INMUX_3_SHIFT)) & VIRT_WRAPPER_REG_B239_236_INMUX_3_MASK)
/*! @} */

/*! @name REG_B243_240 - Parameter_n Register */
/*! @{ */

#define VIRT_WRAPPER_REG_B243_240_INMUX_0_MASK   (0x7U)
#define VIRT_WRAPPER_REG_B243_240_INMUX_0_SHIFT  (0U)
#define VIRT_WRAPPER_REG_B243_240_INMUX_0_WIDTH  (3U)
#define VIRT_WRAPPER_REG_B243_240_INMUX_0(x)     (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B243_240_INMUX_0_SHIFT)) & VIRT_WRAPPER_REG_B243_240_INMUX_0_MASK)

#define VIRT_WRAPPER_REG_B243_240_INMUX_1_MASK   (0x700U)
#define VIRT_WRAPPER_REG_B243_240_INMUX_1_SHIFT  (8U)
#define VIRT_WRAPPER_REG_B243_240_INMUX_1_WIDTH  (3U)
#define VIRT_WRAPPER_REG_B243_240_INMUX_1(x)     (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B243_240_INMUX_1_SHIFT)) & VIRT_WRAPPER_REG_B243_240_INMUX_1_MASK)

#define VIRT_WRAPPER_REG_B243_240_INMUX_2_MASK   (0x70000U)
#define VIRT_WRAPPER_REG_B243_240_INMUX_2_SHIFT  (16U)
#define VIRT_WRAPPER_REG_B243_240_INMUX_2_WIDTH  (3U)
#define VIRT_WRAPPER_REG_B243_240_INMUX_2(x)     (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B243_240_INMUX_2_SHIFT)) & VIRT_WRAPPER_REG_B243_240_INMUX_2_MASK)

#define VIRT_WRAPPER_REG_B243_240_INMUX_3_MASK   (0x7000000U)
#define VIRT_WRAPPER_REG_B243_240_INMUX_3_SHIFT  (24U)
#define VIRT_WRAPPER_REG_B243_240_INMUX_3_WIDTH  (3U)
#define VIRT_WRAPPER_REG_B243_240_INMUX_3(x)     (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B243_240_INMUX_3_SHIFT)) & VIRT_WRAPPER_REG_B243_240_INMUX_3_MASK)
/*! @} */

/*! @name REG_B247_244 - Parameter_n Register */
/*! @{ */

#define VIRT_WRAPPER_REG_B247_244_INMUX_0_MASK   (0x7U)
#define VIRT_WRAPPER_REG_B247_244_INMUX_0_SHIFT  (0U)
#define VIRT_WRAPPER_REG_B247_244_INMUX_0_WIDTH  (3U)
#define VIRT_WRAPPER_REG_B247_244_INMUX_0(x)     (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B247_244_INMUX_0_SHIFT)) & VIRT_WRAPPER_REG_B247_244_INMUX_0_MASK)

#define VIRT_WRAPPER_REG_B247_244_INMUX_1_MASK   (0x700U)
#define VIRT_WRAPPER_REG_B247_244_INMUX_1_SHIFT  (8U)
#define VIRT_WRAPPER_REG_B247_244_INMUX_1_WIDTH  (3U)
#define VIRT_WRAPPER_REG_B247_244_INMUX_1(x)     (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B247_244_INMUX_1_SHIFT)) & VIRT_WRAPPER_REG_B247_244_INMUX_1_MASK)

#define VIRT_WRAPPER_REG_B247_244_INMUX_2_MASK   (0x70000U)
#define VIRT_WRAPPER_REG_B247_244_INMUX_2_SHIFT  (16U)
#define VIRT_WRAPPER_REG_B247_244_INMUX_2_WIDTH  (3U)
#define VIRT_WRAPPER_REG_B247_244_INMUX_2(x)     (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B247_244_INMUX_2_SHIFT)) & VIRT_WRAPPER_REG_B247_244_INMUX_2_MASK)

#define VIRT_WRAPPER_REG_B247_244_INMUX_3_MASK   (0x7000000U)
#define VIRT_WRAPPER_REG_B247_244_INMUX_3_SHIFT  (24U)
#define VIRT_WRAPPER_REG_B247_244_INMUX_3_WIDTH  (3U)
#define VIRT_WRAPPER_REG_B247_244_INMUX_3(x)     (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B247_244_INMUX_3_SHIFT)) & VIRT_WRAPPER_REG_B247_244_INMUX_3_MASK)
/*! @} */

/*! @name REG_B251_248 - Parameter_n Register */
/*! @{ */

#define VIRT_WRAPPER_REG_B251_248_INMUX_0_MASK   (0x7U)
#define VIRT_WRAPPER_REG_B251_248_INMUX_0_SHIFT  (0U)
#define VIRT_WRAPPER_REG_B251_248_INMUX_0_WIDTH  (3U)
#define VIRT_WRAPPER_REG_B251_248_INMUX_0(x)     (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B251_248_INMUX_0_SHIFT)) & VIRT_WRAPPER_REG_B251_248_INMUX_0_MASK)

#define VIRT_WRAPPER_REG_B251_248_INMUX_1_MASK   (0x700U)
#define VIRT_WRAPPER_REG_B251_248_INMUX_1_SHIFT  (8U)
#define VIRT_WRAPPER_REG_B251_248_INMUX_1_WIDTH  (3U)
#define VIRT_WRAPPER_REG_B251_248_INMUX_1(x)     (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B251_248_INMUX_1_SHIFT)) & VIRT_WRAPPER_REG_B251_248_INMUX_1_MASK)

#define VIRT_WRAPPER_REG_B251_248_INMUX_2_MASK   (0x70000U)
#define VIRT_WRAPPER_REG_B251_248_INMUX_2_SHIFT  (16U)
#define VIRT_WRAPPER_REG_B251_248_INMUX_2_WIDTH  (3U)
#define VIRT_WRAPPER_REG_B251_248_INMUX_2(x)     (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B251_248_INMUX_2_SHIFT)) & VIRT_WRAPPER_REG_B251_248_INMUX_2_MASK)

#define VIRT_WRAPPER_REG_B251_248_INMUX_3_MASK   (0x7000000U)
#define VIRT_WRAPPER_REG_B251_248_INMUX_3_SHIFT  (24U)
#define VIRT_WRAPPER_REG_B251_248_INMUX_3_WIDTH  (3U)
#define VIRT_WRAPPER_REG_B251_248_INMUX_3(x)     (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B251_248_INMUX_3_SHIFT)) & VIRT_WRAPPER_REG_B251_248_INMUX_3_MASK)
/*! @} */

/*! @name REG_B255_252 - Parameter_n Register */
/*! @{ */

#define VIRT_WRAPPER_REG_B255_252_INMUX_0_MASK   (0x7U)
#define VIRT_WRAPPER_REG_B255_252_INMUX_0_SHIFT  (0U)
#define VIRT_WRAPPER_REG_B255_252_INMUX_0_WIDTH  (3U)
#define VIRT_WRAPPER_REG_B255_252_INMUX_0(x)     (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B255_252_INMUX_0_SHIFT)) & VIRT_WRAPPER_REG_B255_252_INMUX_0_MASK)

#define VIRT_WRAPPER_REG_B255_252_INMUX_1_MASK   (0x700U)
#define VIRT_WRAPPER_REG_B255_252_INMUX_1_SHIFT  (8U)
#define VIRT_WRAPPER_REG_B255_252_INMUX_1_WIDTH  (3U)
#define VIRT_WRAPPER_REG_B255_252_INMUX_1(x)     (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B255_252_INMUX_1_SHIFT)) & VIRT_WRAPPER_REG_B255_252_INMUX_1_MASK)

#define VIRT_WRAPPER_REG_B255_252_INMUX_2_MASK   (0x70000U)
#define VIRT_WRAPPER_REG_B255_252_INMUX_2_SHIFT  (16U)
#define VIRT_WRAPPER_REG_B255_252_INMUX_2_WIDTH  (3U)
#define VIRT_WRAPPER_REG_B255_252_INMUX_2(x)     (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B255_252_INMUX_2_SHIFT)) & VIRT_WRAPPER_REG_B255_252_INMUX_2_MASK)

#define VIRT_WRAPPER_REG_B255_252_INMUX_3_MASK   (0x7000000U)
#define VIRT_WRAPPER_REG_B255_252_INMUX_3_SHIFT  (24U)
#define VIRT_WRAPPER_REG_B255_252_INMUX_3_WIDTH  (3U)
#define VIRT_WRAPPER_REG_B255_252_INMUX_3(x)     (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B255_252_INMUX_3_SHIFT)) & VIRT_WRAPPER_REG_B255_252_INMUX_3_MASK)
/*! @} */

/*! @name REG_B259_256 - Parameter_n Register */
/*! @{ */

#define VIRT_WRAPPER_REG_B259_256_INMUX_0_MASK   (0x7U)
#define VIRT_WRAPPER_REG_B259_256_INMUX_0_SHIFT  (0U)
#define VIRT_WRAPPER_REG_B259_256_INMUX_0_WIDTH  (3U)
#define VIRT_WRAPPER_REG_B259_256_INMUX_0(x)     (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B259_256_INMUX_0_SHIFT)) & VIRT_WRAPPER_REG_B259_256_INMUX_0_MASK)

#define VIRT_WRAPPER_REG_B259_256_INMUX_1_MASK   (0x700U)
#define VIRT_WRAPPER_REG_B259_256_INMUX_1_SHIFT  (8U)
#define VIRT_WRAPPER_REG_B259_256_INMUX_1_WIDTH  (3U)
#define VIRT_WRAPPER_REG_B259_256_INMUX_1(x)     (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B259_256_INMUX_1_SHIFT)) & VIRT_WRAPPER_REG_B259_256_INMUX_1_MASK)

#define VIRT_WRAPPER_REG_B259_256_INMUX_2_MASK   (0x70000U)
#define VIRT_WRAPPER_REG_B259_256_INMUX_2_SHIFT  (16U)
#define VIRT_WRAPPER_REG_B259_256_INMUX_2_WIDTH  (3U)
#define VIRT_WRAPPER_REG_B259_256_INMUX_2(x)     (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B259_256_INMUX_2_SHIFT)) & VIRT_WRAPPER_REG_B259_256_INMUX_2_MASK)

#define VIRT_WRAPPER_REG_B259_256_INMUX_3_MASK   (0x7000000U)
#define VIRT_WRAPPER_REG_B259_256_INMUX_3_SHIFT  (24U)
#define VIRT_WRAPPER_REG_B259_256_INMUX_3_WIDTH  (3U)
#define VIRT_WRAPPER_REG_B259_256_INMUX_3(x)     (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B259_256_INMUX_3_SHIFT)) & VIRT_WRAPPER_REG_B259_256_INMUX_3_MASK)
/*! @} */

/*! @name REG_B263_260 - Parameter_n Register */
/*! @{ */

#define VIRT_WRAPPER_REG_B263_260_INMUX_0_MASK   (0x7U)
#define VIRT_WRAPPER_REG_B263_260_INMUX_0_SHIFT  (0U)
#define VIRT_WRAPPER_REG_B263_260_INMUX_0_WIDTH  (3U)
#define VIRT_WRAPPER_REG_B263_260_INMUX_0(x)     (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B263_260_INMUX_0_SHIFT)) & VIRT_WRAPPER_REG_B263_260_INMUX_0_MASK)

#define VIRT_WRAPPER_REG_B263_260_INMUX_1_MASK   (0x700U)
#define VIRT_WRAPPER_REG_B263_260_INMUX_1_SHIFT  (8U)
#define VIRT_WRAPPER_REG_B263_260_INMUX_1_WIDTH  (3U)
#define VIRT_WRAPPER_REG_B263_260_INMUX_1(x)     (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B263_260_INMUX_1_SHIFT)) & VIRT_WRAPPER_REG_B263_260_INMUX_1_MASK)

#define VIRT_WRAPPER_REG_B263_260_INMUX_2_MASK   (0x70000U)
#define VIRT_WRAPPER_REG_B263_260_INMUX_2_SHIFT  (16U)
#define VIRT_WRAPPER_REG_B263_260_INMUX_2_WIDTH  (3U)
#define VIRT_WRAPPER_REG_B263_260_INMUX_2(x)     (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B263_260_INMUX_2_SHIFT)) & VIRT_WRAPPER_REG_B263_260_INMUX_2_MASK)

#define VIRT_WRAPPER_REG_B263_260_INMUX_3_MASK   (0x7000000U)
#define VIRT_WRAPPER_REG_B263_260_INMUX_3_SHIFT  (24U)
#define VIRT_WRAPPER_REG_B263_260_INMUX_3_WIDTH  (3U)
#define VIRT_WRAPPER_REG_B263_260_INMUX_3(x)     (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B263_260_INMUX_3_SHIFT)) & VIRT_WRAPPER_REG_B263_260_INMUX_3_MASK)
/*! @} */

/*! @name REG_B267_264 - Parameter_n Register */
/*! @{ */

#define VIRT_WRAPPER_REG_B267_264_INMUX_0_MASK   (0x7U)
#define VIRT_WRAPPER_REG_B267_264_INMUX_0_SHIFT  (0U)
#define VIRT_WRAPPER_REG_B267_264_INMUX_0_WIDTH  (3U)
#define VIRT_WRAPPER_REG_B267_264_INMUX_0(x)     (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B267_264_INMUX_0_SHIFT)) & VIRT_WRAPPER_REG_B267_264_INMUX_0_MASK)

#define VIRT_WRAPPER_REG_B267_264_INMUX_1_MASK   (0x700U)
#define VIRT_WRAPPER_REG_B267_264_INMUX_1_SHIFT  (8U)
#define VIRT_WRAPPER_REG_B267_264_INMUX_1_WIDTH  (3U)
#define VIRT_WRAPPER_REG_B267_264_INMUX_1(x)     (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B267_264_INMUX_1_SHIFT)) & VIRT_WRAPPER_REG_B267_264_INMUX_1_MASK)

#define VIRT_WRAPPER_REG_B267_264_INMUX_2_MASK   (0x70000U)
#define VIRT_WRAPPER_REG_B267_264_INMUX_2_SHIFT  (16U)
#define VIRT_WRAPPER_REG_B267_264_INMUX_2_WIDTH  (3U)
#define VIRT_WRAPPER_REG_B267_264_INMUX_2(x)     (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B267_264_INMUX_2_SHIFT)) & VIRT_WRAPPER_REG_B267_264_INMUX_2_MASK)

#define VIRT_WRAPPER_REG_B267_264_INMUX_3_MASK   (0x7000000U)
#define VIRT_WRAPPER_REG_B267_264_INMUX_3_SHIFT  (24U)
#define VIRT_WRAPPER_REG_B267_264_INMUX_3_WIDTH  (3U)
#define VIRT_WRAPPER_REG_B267_264_INMUX_3(x)     (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B267_264_INMUX_3_SHIFT)) & VIRT_WRAPPER_REG_B267_264_INMUX_3_MASK)
/*! @} */

/*! @name REG_B271_268 - Parameter_n Register */
/*! @{ */

#define VIRT_WRAPPER_REG_B271_268_INMUX_0_MASK   (0x7U)
#define VIRT_WRAPPER_REG_B271_268_INMUX_0_SHIFT  (0U)
#define VIRT_WRAPPER_REG_B271_268_INMUX_0_WIDTH  (3U)
#define VIRT_WRAPPER_REG_B271_268_INMUX_0(x)     (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B271_268_INMUX_0_SHIFT)) & VIRT_WRAPPER_REG_B271_268_INMUX_0_MASK)
/*! @} */

/*! @name REG_B291_288 - Parameter_n Register */
/*! @{ */

#define VIRT_WRAPPER_REG_B291_288_INMUX_1_MASK   (0x700U)
#define VIRT_WRAPPER_REG_B291_288_INMUX_1_SHIFT  (8U)
#define VIRT_WRAPPER_REG_B291_288_INMUX_1_WIDTH  (3U)
#define VIRT_WRAPPER_REG_B291_288_INMUX_1(x)     (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B291_288_INMUX_1_SHIFT)) & VIRT_WRAPPER_REG_B291_288_INMUX_1_MASK)

#define VIRT_WRAPPER_REG_B291_288_INMUX_2_MASK   (0x70000U)
#define VIRT_WRAPPER_REG_B291_288_INMUX_2_SHIFT  (16U)
#define VIRT_WRAPPER_REG_B291_288_INMUX_2_WIDTH  (3U)
#define VIRT_WRAPPER_REG_B291_288_INMUX_2(x)     (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B291_288_INMUX_2_SHIFT)) & VIRT_WRAPPER_REG_B291_288_INMUX_2_MASK)

#define VIRT_WRAPPER_REG_B291_288_INMUX_3_MASK   (0x7000000U)
#define VIRT_WRAPPER_REG_B291_288_INMUX_3_SHIFT  (24U)
#define VIRT_WRAPPER_REG_B291_288_INMUX_3_WIDTH  (3U)
#define VIRT_WRAPPER_REG_B291_288_INMUX_3(x)     (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B291_288_INMUX_3_SHIFT)) & VIRT_WRAPPER_REG_B291_288_INMUX_3_MASK)
/*! @} */

/*! @name REG_B295_292 - Parameter_n Register */
/*! @{ */

#define VIRT_WRAPPER_REG_B295_292_INMUX_0_MASK   (0x7U)
#define VIRT_WRAPPER_REG_B295_292_INMUX_0_SHIFT  (0U)
#define VIRT_WRAPPER_REG_B295_292_INMUX_0_WIDTH  (3U)
#define VIRT_WRAPPER_REG_B295_292_INMUX_0(x)     (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B295_292_INMUX_0_SHIFT)) & VIRT_WRAPPER_REG_B295_292_INMUX_0_MASK)

#define VIRT_WRAPPER_REG_B295_292_INMUX_1_MASK   (0x700U)
#define VIRT_WRAPPER_REG_B295_292_INMUX_1_SHIFT  (8U)
#define VIRT_WRAPPER_REG_B295_292_INMUX_1_WIDTH  (3U)
#define VIRT_WRAPPER_REG_B295_292_INMUX_1(x)     (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B295_292_INMUX_1_SHIFT)) & VIRT_WRAPPER_REG_B295_292_INMUX_1_MASK)

#define VIRT_WRAPPER_REG_B295_292_INMUX_2_MASK   (0x70000U)
#define VIRT_WRAPPER_REG_B295_292_INMUX_2_SHIFT  (16U)
#define VIRT_WRAPPER_REG_B295_292_INMUX_2_WIDTH  (3U)
#define VIRT_WRAPPER_REG_B295_292_INMUX_2(x)     (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B295_292_INMUX_2_SHIFT)) & VIRT_WRAPPER_REG_B295_292_INMUX_2_MASK)

#define VIRT_WRAPPER_REG_B295_292_INMUX_3_MASK   (0x7000000U)
#define VIRT_WRAPPER_REG_B295_292_INMUX_3_SHIFT  (24U)
#define VIRT_WRAPPER_REG_B295_292_INMUX_3_WIDTH  (3U)
#define VIRT_WRAPPER_REG_B295_292_INMUX_3(x)     (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B295_292_INMUX_3_SHIFT)) & VIRT_WRAPPER_REG_B295_292_INMUX_3_MASK)
/*! @} */

/*! @name REG_B299_296 - Parameter_n Register */
/*! @{ */

#define VIRT_WRAPPER_REG_B299_296_INMUX_0_MASK   (0x7U)
#define VIRT_WRAPPER_REG_B299_296_INMUX_0_SHIFT  (0U)
#define VIRT_WRAPPER_REG_B299_296_INMUX_0_WIDTH  (3U)
#define VIRT_WRAPPER_REG_B299_296_INMUX_0(x)     (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B299_296_INMUX_0_SHIFT)) & VIRT_WRAPPER_REG_B299_296_INMUX_0_MASK)

#define VIRT_WRAPPER_REG_B299_296_INMUX_1_MASK   (0x700U)
#define VIRT_WRAPPER_REG_B299_296_INMUX_1_SHIFT  (8U)
#define VIRT_WRAPPER_REG_B299_296_INMUX_1_WIDTH  (3U)
#define VIRT_WRAPPER_REG_B299_296_INMUX_1(x)     (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B299_296_INMUX_1_SHIFT)) & VIRT_WRAPPER_REG_B299_296_INMUX_1_MASK)

#define VIRT_WRAPPER_REG_B299_296_INMUX_2_MASK   (0x70000U)
#define VIRT_WRAPPER_REG_B299_296_INMUX_2_SHIFT  (16U)
#define VIRT_WRAPPER_REG_B299_296_INMUX_2_WIDTH  (3U)
#define VIRT_WRAPPER_REG_B299_296_INMUX_2(x)     (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B299_296_INMUX_2_SHIFT)) & VIRT_WRAPPER_REG_B299_296_INMUX_2_MASK)

#define VIRT_WRAPPER_REG_B299_296_INMUX_3_MASK   (0x7000000U)
#define VIRT_WRAPPER_REG_B299_296_INMUX_3_SHIFT  (24U)
#define VIRT_WRAPPER_REG_B299_296_INMUX_3_WIDTH  (3U)
#define VIRT_WRAPPER_REG_B299_296_INMUX_3(x)     (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B299_296_INMUX_3_SHIFT)) & VIRT_WRAPPER_REG_B299_296_INMUX_3_MASK)
/*! @} */

/*! @name REG_B303_300 - Parameter_n Register */
/*! @{ */

#define VIRT_WRAPPER_REG_B303_300_INMUX_0_MASK   (0x7U)
#define VIRT_WRAPPER_REG_B303_300_INMUX_0_SHIFT  (0U)
#define VIRT_WRAPPER_REG_B303_300_INMUX_0_WIDTH  (3U)
#define VIRT_WRAPPER_REG_B303_300_INMUX_0(x)     (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B303_300_INMUX_0_SHIFT)) & VIRT_WRAPPER_REG_B303_300_INMUX_0_MASK)

#define VIRT_WRAPPER_REG_B303_300_INMUX_1_MASK   (0x700U)
#define VIRT_WRAPPER_REG_B303_300_INMUX_1_SHIFT  (8U)
#define VIRT_WRAPPER_REG_B303_300_INMUX_1_WIDTH  (3U)
#define VIRT_WRAPPER_REG_B303_300_INMUX_1(x)     (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B303_300_INMUX_1_SHIFT)) & VIRT_WRAPPER_REG_B303_300_INMUX_1_MASK)

#define VIRT_WRAPPER_REG_B303_300_INMUX_2_MASK   (0x70000U)
#define VIRT_WRAPPER_REG_B303_300_INMUX_2_SHIFT  (16U)
#define VIRT_WRAPPER_REG_B303_300_INMUX_2_WIDTH  (3U)
#define VIRT_WRAPPER_REG_B303_300_INMUX_2(x)     (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B303_300_INMUX_2_SHIFT)) & VIRT_WRAPPER_REG_B303_300_INMUX_2_MASK)

#define VIRT_WRAPPER_REG_B303_300_INMUX_3_MASK   (0x7000000U)
#define VIRT_WRAPPER_REG_B303_300_INMUX_3_SHIFT  (24U)
#define VIRT_WRAPPER_REG_B303_300_INMUX_3_WIDTH  (3U)
#define VIRT_WRAPPER_REG_B303_300_INMUX_3(x)     (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B303_300_INMUX_3_SHIFT)) & VIRT_WRAPPER_REG_B303_300_INMUX_3_MASK)
/*! @} */

/*! @name REG_B307_304 - Parameter_n Register */
/*! @{ */

#define VIRT_WRAPPER_REG_B307_304_INMUX_0_MASK   (0x7U)
#define VIRT_WRAPPER_REG_B307_304_INMUX_0_SHIFT  (0U)
#define VIRT_WRAPPER_REG_B307_304_INMUX_0_WIDTH  (3U)
#define VIRT_WRAPPER_REG_B307_304_INMUX_0(x)     (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B307_304_INMUX_0_SHIFT)) & VIRT_WRAPPER_REG_B307_304_INMUX_0_MASK)

#define VIRT_WRAPPER_REG_B307_304_INMUX_1_MASK   (0x700U)
#define VIRT_WRAPPER_REG_B307_304_INMUX_1_SHIFT  (8U)
#define VIRT_WRAPPER_REG_B307_304_INMUX_1_WIDTH  (3U)
#define VIRT_WRAPPER_REG_B307_304_INMUX_1(x)     (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B307_304_INMUX_1_SHIFT)) & VIRT_WRAPPER_REG_B307_304_INMUX_1_MASK)

#define VIRT_WRAPPER_REG_B307_304_INMUX_2_MASK   (0x70000U)
#define VIRT_WRAPPER_REG_B307_304_INMUX_2_SHIFT  (16U)
#define VIRT_WRAPPER_REG_B307_304_INMUX_2_WIDTH  (3U)
#define VIRT_WRAPPER_REG_B307_304_INMUX_2(x)     (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B307_304_INMUX_2_SHIFT)) & VIRT_WRAPPER_REG_B307_304_INMUX_2_MASK)

#define VIRT_WRAPPER_REG_B307_304_INMUX_3_MASK   (0x7000000U)
#define VIRT_WRAPPER_REG_B307_304_INMUX_3_SHIFT  (24U)
#define VIRT_WRAPPER_REG_B307_304_INMUX_3_WIDTH  (3U)
#define VIRT_WRAPPER_REG_B307_304_INMUX_3(x)     (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B307_304_INMUX_3_SHIFT)) & VIRT_WRAPPER_REG_B307_304_INMUX_3_MASK)
/*! @} */

/*! @name REG_B311_308 - Parameter_n Register */
/*! @{ */

#define VIRT_WRAPPER_REG_B311_308_INMUX_0_MASK   (0x7U)
#define VIRT_WRAPPER_REG_B311_308_INMUX_0_SHIFT  (0U)
#define VIRT_WRAPPER_REG_B311_308_INMUX_0_WIDTH  (3U)
#define VIRT_WRAPPER_REG_B311_308_INMUX_0(x)     (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B311_308_INMUX_0_SHIFT)) & VIRT_WRAPPER_REG_B311_308_INMUX_0_MASK)

#define VIRT_WRAPPER_REG_B311_308_INMUX_1_MASK   (0x700U)
#define VIRT_WRAPPER_REG_B311_308_INMUX_1_SHIFT  (8U)
#define VIRT_WRAPPER_REG_B311_308_INMUX_1_WIDTH  (3U)
#define VIRT_WRAPPER_REG_B311_308_INMUX_1(x)     (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B311_308_INMUX_1_SHIFT)) & VIRT_WRAPPER_REG_B311_308_INMUX_1_MASK)
/*! @} */

/*! @name REG_B315_312 - Parameter_n Register */
/*! @{ */

#define VIRT_WRAPPER_REG_B315_312_INMUX_3_MASK   (0x7000000U)
#define VIRT_WRAPPER_REG_B315_312_INMUX_3_SHIFT  (24U)
#define VIRT_WRAPPER_REG_B315_312_INMUX_3_WIDTH  (3U)
#define VIRT_WRAPPER_REG_B315_312_INMUX_3(x)     (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B315_312_INMUX_3_SHIFT)) & VIRT_WRAPPER_REG_B315_312_INMUX_3_MASK)
/*! @} */

/*! @name REG_B319_316 - Parameter_n Register */
/*! @{ */

#define VIRT_WRAPPER_REG_B319_316_INMUX_0_MASK   (0x7U)
#define VIRT_WRAPPER_REG_B319_316_INMUX_0_SHIFT  (0U)
#define VIRT_WRAPPER_REG_B319_316_INMUX_0_WIDTH  (3U)
#define VIRT_WRAPPER_REG_B319_316_INMUX_0(x)     (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B319_316_INMUX_0_SHIFT)) & VIRT_WRAPPER_REG_B319_316_INMUX_0_MASK)

#define VIRT_WRAPPER_REG_B319_316_INMUX_1_MASK   (0x700U)
#define VIRT_WRAPPER_REG_B319_316_INMUX_1_SHIFT  (8U)
#define VIRT_WRAPPER_REG_B319_316_INMUX_1_WIDTH  (3U)
#define VIRT_WRAPPER_REG_B319_316_INMUX_1(x)     (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B319_316_INMUX_1_SHIFT)) & VIRT_WRAPPER_REG_B319_316_INMUX_1_MASK)

#define VIRT_WRAPPER_REG_B319_316_INMUX_2_MASK   (0x70000U)
#define VIRT_WRAPPER_REG_B319_316_INMUX_2_SHIFT  (16U)
#define VIRT_WRAPPER_REG_B319_316_INMUX_2_WIDTH  (3U)
#define VIRT_WRAPPER_REG_B319_316_INMUX_2(x)     (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B319_316_INMUX_2_SHIFT)) & VIRT_WRAPPER_REG_B319_316_INMUX_2_MASK)

#define VIRT_WRAPPER_REG_B319_316_INMUX_3_MASK   (0x7000000U)
#define VIRT_WRAPPER_REG_B319_316_INMUX_3_SHIFT  (24U)
#define VIRT_WRAPPER_REG_B319_316_INMUX_3_WIDTH  (3U)
#define VIRT_WRAPPER_REG_B319_316_INMUX_3(x)     (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B319_316_INMUX_3_SHIFT)) & VIRT_WRAPPER_REG_B319_316_INMUX_3_MASK)
/*! @} */

/*! @name REG_B323_320 - Parameter_n Register */
/*! @{ */

#define VIRT_WRAPPER_REG_B323_320_INMUX_0_MASK   (0x7U)
#define VIRT_WRAPPER_REG_B323_320_INMUX_0_SHIFT  (0U)
#define VIRT_WRAPPER_REG_B323_320_INMUX_0_WIDTH  (3U)
#define VIRT_WRAPPER_REG_B323_320_INMUX_0(x)     (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B323_320_INMUX_0_SHIFT)) & VIRT_WRAPPER_REG_B323_320_INMUX_0_MASK)

#define VIRT_WRAPPER_REG_B323_320_INMUX_1_MASK   (0x700U)
#define VIRT_WRAPPER_REG_B323_320_INMUX_1_SHIFT  (8U)
#define VIRT_WRAPPER_REG_B323_320_INMUX_1_WIDTH  (3U)
#define VIRT_WRAPPER_REG_B323_320_INMUX_1(x)     (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B323_320_INMUX_1_SHIFT)) & VIRT_WRAPPER_REG_B323_320_INMUX_1_MASK)

#define VIRT_WRAPPER_REG_B323_320_INMUX_2_MASK   (0x70000U)
#define VIRT_WRAPPER_REG_B323_320_INMUX_2_SHIFT  (16U)
#define VIRT_WRAPPER_REG_B323_320_INMUX_2_WIDTH  (3U)
#define VIRT_WRAPPER_REG_B323_320_INMUX_2(x)     (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B323_320_INMUX_2_SHIFT)) & VIRT_WRAPPER_REG_B323_320_INMUX_2_MASK)

#define VIRT_WRAPPER_REG_B323_320_INMUX_3_MASK   (0x7000000U)
#define VIRT_WRAPPER_REG_B323_320_INMUX_3_SHIFT  (24U)
#define VIRT_WRAPPER_REG_B323_320_INMUX_3_WIDTH  (3U)
#define VIRT_WRAPPER_REG_B323_320_INMUX_3(x)     (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B323_320_INMUX_3_SHIFT)) & VIRT_WRAPPER_REG_B323_320_INMUX_3_MASK)
/*! @} */

/*! @name REG_B327_324 - Parameter_n Register */
/*! @{ */

#define VIRT_WRAPPER_REG_B327_324_INMUX_0_MASK   (0x7U)
#define VIRT_WRAPPER_REG_B327_324_INMUX_0_SHIFT  (0U)
#define VIRT_WRAPPER_REG_B327_324_INMUX_0_WIDTH  (3U)
#define VIRT_WRAPPER_REG_B327_324_INMUX_0(x)     (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B327_324_INMUX_0_SHIFT)) & VIRT_WRAPPER_REG_B327_324_INMUX_0_MASK)

#define VIRT_WRAPPER_REG_B327_324_INMUX_1_MASK   (0x700U)
#define VIRT_WRAPPER_REG_B327_324_INMUX_1_SHIFT  (8U)
#define VIRT_WRAPPER_REG_B327_324_INMUX_1_WIDTH  (3U)
#define VIRT_WRAPPER_REG_B327_324_INMUX_1(x)     (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B327_324_INMUX_1_SHIFT)) & VIRT_WRAPPER_REG_B327_324_INMUX_1_MASK)
/*! @} */

/*! @name REG_B343_340 - Parameter_n Register */
/*! @{ */

#define VIRT_WRAPPER_REG_B343_340_INMUX_3_MASK   (0x7000000U)
#define VIRT_WRAPPER_REG_B343_340_INMUX_3_SHIFT  (24U)
#define VIRT_WRAPPER_REG_B343_340_INMUX_3_WIDTH  (3U)
#define VIRT_WRAPPER_REG_B343_340_INMUX_3(x)     (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B343_340_INMUX_3_SHIFT)) & VIRT_WRAPPER_REG_B343_340_INMUX_3_MASK)
/*! @} */

/*! @name REG_B347_344 - Parameter_n Register */
/*! @{ */

#define VIRT_WRAPPER_REG_B347_344_INMUX_0_MASK   (0x7U)
#define VIRT_WRAPPER_REG_B347_344_INMUX_0_SHIFT  (0U)
#define VIRT_WRAPPER_REG_B347_344_INMUX_0_WIDTH  (3U)
#define VIRT_WRAPPER_REG_B347_344_INMUX_0(x)     (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B347_344_INMUX_0_SHIFT)) & VIRT_WRAPPER_REG_B347_344_INMUX_0_MASK)

#define VIRT_WRAPPER_REG_B347_344_INMUX_1_MASK   (0x700U)
#define VIRT_WRAPPER_REG_B347_344_INMUX_1_SHIFT  (8U)
#define VIRT_WRAPPER_REG_B347_344_INMUX_1_WIDTH  (3U)
#define VIRT_WRAPPER_REG_B347_344_INMUX_1(x)     (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B347_344_INMUX_1_SHIFT)) & VIRT_WRAPPER_REG_B347_344_INMUX_1_MASK)

#define VIRT_WRAPPER_REG_B347_344_INMUX_2_MASK   (0x70000U)
#define VIRT_WRAPPER_REG_B347_344_INMUX_2_SHIFT  (16U)
#define VIRT_WRAPPER_REG_B347_344_INMUX_2_WIDTH  (3U)
#define VIRT_WRAPPER_REG_B347_344_INMUX_2(x)     (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B347_344_INMUX_2_SHIFT)) & VIRT_WRAPPER_REG_B347_344_INMUX_2_MASK)

#define VIRT_WRAPPER_REG_B347_344_INMUX_3_MASK   (0x7000000U)
#define VIRT_WRAPPER_REG_B347_344_INMUX_3_SHIFT  (24U)
#define VIRT_WRAPPER_REG_B347_344_INMUX_3_WIDTH  (3U)
#define VIRT_WRAPPER_REG_B347_344_INMUX_3(x)     (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B347_344_INMUX_3_SHIFT)) & VIRT_WRAPPER_REG_B347_344_INMUX_3_MASK)
/*! @} */

/*! @name REG_B351_348 - Parameter_n Register */
/*! @{ */

#define VIRT_WRAPPER_REG_B351_348_INMUX_0_MASK   (0x7U)
#define VIRT_WRAPPER_REG_B351_348_INMUX_0_SHIFT  (0U)
#define VIRT_WRAPPER_REG_B351_348_INMUX_0_WIDTH  (3U)
#define VIRT_WRAPPER_REG_B351_348_INMUX_0(x)     (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B351_348_INMUX_0_SHIFT)) & VIRT_WRAPPER_REG_B351_348_INMUX_0_MASK)

#define VIRT_WRAPPER_REG_B351_348_INMUX_1_MASK   (0x700U)
#define VIRT_WRAPPER_REG_B351_348_INMUX_1_SHIFT  (8U)
#define VIRT_WRAPPER_REG_B351_348_INMUX_1_WIDTH  (3U)
#define VIRT_WRAPPER_REG_B351_348_INMUX_1(x)     (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B351_348_INMUX_1_SHIFT)) & VIRT_WRAPPER_REG_B351_348_INMUX_1_MASK)

#define VIRT_WRAPPER_REG_B351_348_INMUX_2_MASK   (0x70000U)
#define VIRT_WRAPPER_REG_B351_348_INMUX_2_SHIFT  (16U)
#define VIRT_WRAPPER_REG_B351_348_INMUX_2_WIDTH  (3U)
#define VIRT_WRAPPER_REG_B351_348_INMUX_2(x)     (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B351_348_INMUX_2_SHIFT)) & VIRT_WRAPPER_REG_B351_348_INMUX_2_MASK)

#define VIRT_WRAPPER_REG_B351_348_INMUX_3_MASK   (0x7000000U)
#define VIRT_WRAPPER_REG_B351_348_INMUX_3_SHIFT  (24U)
#define VIRT_WRAPPER_REG_B351_348_INMUX_3_WIDTH  (3U)
#define VIRT_WRAPPER_REG_B351_348_INMUX_3(x)     (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B351_348_INMUX_3_SHIFT)) & VIRT_WRAPPER_REG_B351_348_INMUX_3_MASK)
/*! @} */

/*! @name REG_B355_352 - Parameter_n Register */
/*! @{ */

#define VIRT_WRAPPER_REG_B355_352_INMUX_0_MASK   (0x7U)
#define VIRT_WRAPPER_REG_B355_352_INMUX_0_SHIFT  (0U)
#define VIRT_WRAPPER_REG_B355_352_INMUX_0_WIDTH  (3U)
#define VIRT_WRAPPER_REG_B355_352_INMUX_0(x)     (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B355_352_INMUX_0_SHIFT)) & VIRT_WRAPPER_REG_B355_352_INMUX_0_MASK)

#define VIRT_WRAPPER_REG_B355_352_INMUX_1_MASK   (0x700U)
#define VIRT_WRAPPER_REG_B355_352_INMUX_1_SHIFT  (8U)
#define VIRT_WRAPPER_REG_B355_352_INMUX_1_WIDTH  (3U)
#define VIRT_WRAPPER_REG_B355_352_INMUX_1(x)     (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B355_352_INMUX_1_SHIFT)) & VIRT_WRAPPER_REG_B355_352_INMUX_1_MASK)

#define VIRT_WRAPPER_REG_B355_352_INMUX_2_MASK   (0x70000U)
#define VIRT_WRAPPER_REG_B355_352_INMUX_2_SHIFT  (16U)
#define VIRT_WRAPPER_REG_B355_352_INMUX_2_WIDTH  (3U)
#define VIRT_WRAPPER_REG_B355_352_INMUX_2(x)     (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B355_352_INMUX_2_SHIFT)) & VIRT_WRAPPER_REG_B355_352_INMUX_2_MASK)

#define VIRT_WRAPPER_REG_B355_352_INMUX_3_MASK   (0x7000000U)
#define VIRT_WRAPPER_REG_B355_352_INMUX_3_SHIFT  (24U)
#define VIRT_WRAPPER_REG_B355_352_INMUX_3_WIDTH  (3U)
#define VIRT_WRAPPER_REG_B355_352_INMUX_3(x)     (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B355_352_INMUX_3_SHIFT)) & VIRT_WRAPPER_REG_B355_352_INMUX_3_MASK)
/*! @} */

/*! @name REG_B359_356 - Parameter_n Register */
/*! @{ */

#define VIRT_WRAPPER_REG_B359_356_INMUX_0_MASK   (0x7U)
#define VIRT_WRAPPER_REG_B359_356_INMUX_0_SHIFT  (0U)
#define VIRT_WRAPPER_REG_B359_356_INMUX_0_WIDTH  (3U)
#define VIRT_WRAPPER_REG_B359_356_INMUX_0(x)     (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B359_356_INMUX_0_SHIFT)) & VIRT_WRAPPER_REG_B359_356_INMUX_0_MASK)

#define VIRT_WRAPPER_REG_B359_356_INMUX_1_MASK   (0x700U)
#define VIRT_WRAPPER_REG_B359_356_INMUX_1_SHIFT  (8U)
#define VIRT_WRAPPER_REG_B359_356_INMUX_1_WIDTH  (3U)
#define VIRT_WRAPPER_REG_B359_356_INMUX_1(x)     (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B359_356_INMUX_1_SHIFT)) & VIRT_WRAPPER_REG_B359_356_INMUX_1_MASK)

#define VIRT_WRAPPER_REG_B359_356_INMUX_2_MASK   (0x70000U)
#define VIRT_WRAPPER_REG_B359_356_INMUX_2_SHIFT  (16U)
#define VIRT_WRAPPER_REG_B359_356_INMUX_2_WIDTH  (3U)
#define VIRT_WRAPPER_REG_B359_356_INMUX_2(x)     (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B359_356_INMUX_2_SHIFT)) & VIRT_WRAPPER_REG_B359_356_INMUX_2_MASK)

#define VIRT_WRAPPER_REG_B359_356_INMUX_3_MASK   (0x7000000U)
#define VIRT_WRAPPER_REG_B359_356_INMUX_3_SHIFT  (24U)
#define VIRT_WRAPPER_REG_B359_356_INMUX_3_WIDTH  (3U)
#define VIRT_WRAPPER_REG_B359_356_INMUX_3(x)     (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B359_356_INMUX_3_SHIFT)) & VIRT_WRAPPER_REG_B359_356_INMUX_3_MASK)
/*! @} */

/*! @name REG_B363_360 - Parameter_n Register */
/*! @{ */

#define VIRT_WRAPPER_REG_B363_360_INMUX_0_MASK   (0x7U)
#define VIRT_WRAPPER_REG_B363_360_INMUX_0_SHIFT  (0U)
#define VIRT_WRAPPER_REG_B363_360_INMUX_0_WIDTH  (3U)
#define VIRT_WRAPPER_REG_B363_360_INMUX_0(x)     (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B363_360_INMUX_0_SHIFT)) & VIRT_WRAPPER_REG_B363_360_INMUX_0_MASK)

#define VIRT_WRAPPER_REG_B363_360_INMUX_1_MASK   (0x700U)
#define VIRT_WRAPPER_REG_B363_360_INMUX_1_SHIFT  (8U)
#define VIRT_WRAPPER_REG_B363_360_INMUX_1_WIDTH  (3U)
#define VIRT_WRAPPER_REG_B363_360_INMUX_1(x)     (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B363_360_INMUX_1_SHIFT)) & VIRT_WRAPPER_REG_B363_360_INMUX_1_MASK)

#define VIRT_WRAPPER_REG_B363_360_INMUX_2_MASK   (0x70000U)
#define VIRT_WRAPPER_REG_B363_360_INMUX_2_SHIFT  (16U)
#define VIRT_WRAPPER_REG_B363_360_INMUX_2_WIDTH  (3U)
#define VIRT_WRAPPER_REG_B363_360_INMUX_2(x)     (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B363_360_INMUX_2_SHIFT)) & VIRT_WRAPPER_REG_B363_360_INMUX_2_MASK)

#define VIRT_WRAPPER_REG_B363_360_INMUX_3_MASK   (0x7000000U)
#define VIRT_WRAPPER_REG_B363_360_INMUX_3_SHIFT  (24U)
#define VIRT_WRAPPER_REG_B363_360_INMUX_3_WIDTH  (3U)
#define VIRT_WRAPPER_REG_B363_360_INMUX_3(x)     (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B363_360_INMUX_3_SHIFT)) & VIRT_WRAPPER_REG_B363_360_INMUX_3_MASK)
/*! @} */

/*! @name REG_B367_364 - Parameter_n Register */
/*! @{ */

#define VIRT_WRAPPER_REG_B367_364_INMUX_0_MASK   (0x7U)
#define VIRT_WRAPPER_REG_B367_364_INMUX_0_SHIFT  (0U)
#define VIRT_WRAPPER_REG_B367_364_INMUX_0_WIDTH  (3U)
#define VIRT_WRAPPER_REG_B367_364_INMUX_0(x)     (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B367_364_INMUX_0_SHIFT)) & VIRT_WRAPPER_REG_B367_364_INMUX_0_MASK)

#define VIRT_WRAPPER_REG_B367_364_INMUX_1_MASK   (0x700U)
#define VIRT_WRAPPER_REG_B367_364_INMUX_1_SHIFT  (8U)
#define VIRT_WRAPPER_REG_B367_364_INMUX_1_WIDTH  (3U)
#define VIRT_WRAPPER_REG_B367_364_INMUX_1(x)     (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B367_364_INMUX_1_SHIFT)) & VIRT_WRAPPER_REG_B367_364_INMUX_1_MASK)

#define VIRT_WRAPPER_REG_B367_364_INMUX_2_MASK   (0x70000U)
#define VIRT_WRAPPER_REG_B367_364_INMUX_2_SHIFT  (16U)
#define VIRT_WRAPPER_REG_B367_364_INMUX_2_WIDTH  (3U)
#define VIRT_WRAPPER_REG_B367_364_INMUX_2(x)     (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B367_364_INMUX_2_SHIFT)) & VIRT_WRAPPER_REG_B367_364_INMUX_2_MASK)

#define VIRT_WRAPPER_REG_B367_364_INMUX_3_MASK   (0x7000000U)
#define VIRT_WRAPPER_REG_B367_364_INMUX_3_SHIFT  (24U)
#define VIRT_WRAPPER_REG_B367_364_INMUX_3_WIDTH  (3U)
#define VIRT_WRAPPER_REG_B367_364_INMUX_3(x)     (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B367_364_INMUX_3_SHIFT)) & VIRT_WRAPPER_REG_B367_364_INMUX_3_MASK)
/*! @} */

/*! @name REG_B371_368 - Parameter_n Register */
/*! @{ */

#define VIRT_WRAPPER_REG_B371_368_INMUX_0_MASK   (0x7U)
#define VIRT_WRAPPER_REG_B371_368_INMUX_0_SHIFT  (0U)
#define VIRT_WRAPPER_REG_B371_368_INMUX_0_WIDTH  (3U)
#define VIRT_WRAPPER_REG_B371_368_INMUX_0(x)     (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B371_368_INMUX_0_SHIFT)) & VIRT_WRAPPER_REG_B371_368_INMUX_0_MASK)

#define VIRT_WRAPPER_REG_B371_368_INMUX_1_MASK   (0x700U)
#define VIRT_WRAPPER_REG_B371_368_INMUX_1_SHIFT  (8U)
#define VIRT_WRAPPER_REG_B371_368_INMUX_1_WIDTH  (3U)
#define VIRT_WRAPPER_REG_B371_368_INMUX_1(x)     (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B371_368_INMUX_1_SHIFT)) & VIRT_WRAPPER_REG_B371_368_INMUX_1_MASK)

#define VIRT_WRAPPER_REG_B371_368_INMUX_2_MASK   (0x70000U)
#define VIRT_WRAPPER_REG_B371_368_INMUX_2_SHIFT  (16U)
#define VIRT_WRAPPER_REG_B371_368_INMUX_2_WIDTH  (3U)
#define VIRT_WRAPPER_REG_B371_368_INMUX_2(x)     (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B371_368_INMUX_2_SHIFT)) & VIRT_WRAPPER_REG_B371_368_INMUX_2_MASK)
/*! @} */

/*! @name REG_B375_372 - Parameter_n Register */
/*! @{ */

#define VIRT_WRAPPER_REG_B375_372_INMUX_1_MASK   (0x700U)
#define VIRT_WRAPPER_REG_B375_372_INMUX_1_SHIFT  (8U)
#define VIRT_WRAPPER_REG_B375_372_INMUX_1_WIDTH  (3U)
#define VIRT_WRAPPER_REG_B375_372_INMUX_1(x)     (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B375_372_INMUX_1_SHIFT)) & VIRT_WRAPPER_REG_B375_372_INMUX_1_MASK)

#define VIRT_WRAPPER_REG_B375_372_INMUX_2_MASK   (0x70000U)
#define VIRT_WRAPPER_REG_B375_372_INMUX_2_SHIFT  (16U)
#define VIRT_WRAPPER_REG_B375_372_INMUX_2_WIDTH  (3U)
#define VIRT_WRAPPER_REG_B375_372_INMUX_2(x)     (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B375_372_INMUX_2_SHIFT)) & VIRT_WRAPPER_REG_B375_372_INMUX_2_MASK)

#define VIRT_WRAPPER_REG_B375_372_INMUX_3_MASK   (0x7000000U)
#define VIRT_WRAPPER_REG_B375_372_INMUX_3_SHIFT  (24U)
#define VIRT_WRAPPER_REG_B375_372_INMUX_3_WIDTH  (3U)
#define VIRT_WRAPPER_REG_B375_372_INMUX_3(x)     (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B375_372_INMUX_3_SHIFT)) & VIRT_WRAPPER_REG_B375_372_INMUX_3_MASK)
/*! @} */

/*! @name REG_B379_376 - Parameter_n Register */
/*! @{ */

#define VIRT_WRAPPER_REG_B379_376_INMUX_0_MASK   (0x7U)
#define VIRT_WRAPPER_REG_B379_376_INMUX_0_SHIFT  (0U)
#define VIRT_WRAPPER_REG_B379_376_INMUX_0_WIDTH  (3U)
#define VIRT_WRAPPER_REG_B379_376_INMUX_0(x)     (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B379_376_INMUX_0_SHIFT)) & VIRT_WRAPPER_REG_B379_376_INMUX_0_MASK)

#define VIRT_WRAPPER_REG_B379_376_INMUX_1_MASK   (0x700U)
#define VIRT_WRAPPER_REG_B379_376_INMUX_1_SHIFT  (8U)
#define VIRT_WRAPPER_REG_B379_376_INMUX_1_WIDTH  (3U)
#define VIRT_WRAPPER_REG_B379_376_INMUX_1(x)     (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B379_376_INMUX_1_SHIFT)) & VIRT_WRAPPER_REG_B379_376_INMUX_1_MASK)

#define VIRT_WRAPPER_REG_B379_376_INMUX_2_MASK   (0x70000U)
#define VIRT_WRAPPER_REG_B379_376_INMUX_2_SHIFT  (16U)
#define VIRT_WRAPPER_REG_B379_376_INMUX_2_WIDTH  (3U)
#define VIRT_WRAPPER_REG_B379_376_INMUX_2(x)     (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B379_376_INMUX_2_SHIFT)) & VIRT_WRAPPER_REG_B379_376_INMUX_2_MASK)
/*! @} */

/*! @name REG_B391_388 - Parameter_n Register */
/*! @{ */

#define VIRT_WRAPPER_REG_B391_388_INMUX_1_MASK   (0x700U)
#define VIRT_WRAPPER_REG_B391_388_INMUX_1_SHIFT  (8U)
#define VIRT_WRAPPER_REG_B391_388_INMUX_1_WIDTH  (3U)
#define VIRT_WRAPPER_REG_B391_388_INMUX_1(x)     (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B391_388_INMUX_1_SHIFT)) & VIRT_WRAPPER_REG_B391_388_INMUX_1_MASK)
/*! @} */

/*! @name REG_B399_396 - Parameter_n Register */
/*! @{ */

#define VIRT_WRAPPER_REG_B399_396_INMUX_2_MASK   (0x70000U)
#define VIRT_WRAPPER_REG_B399_396_INMUX_2_SHIFT  (16U)
#define VIRT_WRAPPER_REG_B399_396_INMUX_2_WIDTH  (3U)
#define VIRT_WRAPPER_REG_B399_396_INMUX_2(x)     (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B399_396_INMUX_2_SHIFT)) & VIRT_WRAPPER_REG_B399_396_INMUX_2_MASK)

#define VIRT_WRAPPER_REG_B399_396_INMUX_3_MASK   (0x7000000U)
#define VIRT_WRAPPER_REG_B399_396_INMUX_3_SHIFT  (24U)
#define VIRT_WRAPPER_REG_B399_396_INMUX_3_WIDTH  (3U)
#define VIRT_WRAPPER_REG_B399_396_INMUX_3(x)     (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B399_396_INMUX_3_SHIFT)) & VIRT_WRAPPER_REG_B399_396_INMUX_3_MASK)
/*! @} */

/*! @name REG_B411_408 - Parameter_n Register */
/*! @{ */

#define VIRT_WRAPPER_REG_B411_408_INMUX_1_MASK   (0x700U)
#define VIRT_WRAPPER_REG_B411_408_INMUX_1_SHIFT  (8U)
#define VIRT_WRAPPER_REG_B411_408_INMUX_1_WIDTH  (3U)
#define VIRT_WRAPPER_REG_B411_408_INMUX_1(x)     (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B411_408_INMUX_1_SHIFT)) & VIRT_WRAPPER_REG_B411_408_INMUX_1_MASK)

#define VIRT_WRAPPER_REG_B411_408_INMUX_2_MASK   (0x70000U)
#define VIRT_WRAPPER_REG_B411_408_INMUX_2_SHIFT  (16U)
#define VIRT_WRAPPER_REG_B411_408_INMUX_2_WIDTH  (3U)
#define VIRT_WRAPPER_REG_B411_408_INMUX_2(x)     (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B411_408_INMUX_2_SHIFT)) & VIRT_WRAPPER_REG_B411_408_INMUX_2_MASK)

#define VIRT_WRAPPER_REG_B411_408_INMUX_3_MASK   (0x7000000U)
#define VIRT_WRAPPER_REG_B411_408_INMUX_3_SHIFT  (24U)
#define VIRT_WRAPPER_REG_B411_408_INMUX_3_WIDTH  (3U)
#define VIRT_WRAPPER_REG_B411_408_INMUX_3(x)     (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B411_408_INMUX_3_SHIFT)) & VIRT_WRAPPER_REG_B411_408_INMUX_3_MASK)
/*! @} */

/*! @name REG_B415_412 - Parameter_n Register */
/*! @{ */

#define VIRT_WRAPPER_REG_B415_412_INMUX_0_MASK   (0x7U)
#define VIRT_WRAPPER_REG_B415_412_INMUX_0_SHIFT  (0U)
#define VIRT_WRAPPER_REG_B415_412_INMUX_0_WIDTH  (3U)
#define VIRT_WRAPPER_REG_B415_412_INMUX_0(x)     (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B415_412_INMUX_0_SHIFT)) & VIRT_WRAPPER_REG_B415_412_INMUX_0_MASK)

#define VIRT_WRAPPER_REG_B415_412_INMUX_1_MASK   (0x700U)
#define VIRT_WRAPPER_REG_B415_412_INMUX_1_SHIFT  (8U)
#define VIRT_WRAPPER_REG_B415_412_INMUX_1_WIDTH  (3U)
#define VIRT_WRAPPER_REG_B415_412_INMUX_1(x)     (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B415_412_INMUX_1_SHIFT)) & VIRT_WRAPPER_REG_B415_412_INMUX_1_MASK)

#define VIRT_WRAPPER_REG_B415_412_INMUX_2_MASK   (0x70000U)
#define VIRT_WRAPPER_REG_B415_412_INMUX_2_SHIFT  (16U)
#define VIRT_WRAPPER_REG_B415_412_INMUX_2_WIDTH  (3U)
#define VIRT_WRAPPER_REG_B415_412_INMUX_2(x)     (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B415_412_INMUX_2_SHIFT)) & VIRT_WRAPPER_REG_B415_412_INMUX_2_MASK)

#define VIRT_WRAPPER_REG_B415_412_INMUX_3_MASK   (0x7000000U)
#define VIRT_WRAPPER_REG_B415_412_INMUX_3_SHIFT  (24U)
#define VIRT_WRAPPER_REG_B415_412_INMUX_3_WIDTH  (3U)
#define VIRT_WRAPPER_REG_B415_412_INMUX_3(x)     (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B415_412_INMUX_3_SHIFT)) & VIRT_WRAPPER_REG_B415_412_INMUX_3_MASK)
/*! @} */

/*! @name REG_B419_416 - Parameter_n Register */
/*! @{ */

#define VIRT_WRAPPER_REG_B419_416_INMUX_0_MASK   (0x7U)
#define VIRT_WRAPPER_REG_B419_416_INMUX_0_SHIFT  (0U)
#define VIRT_WRAPPER_REG_B419_416_INMUX_0_WIDTH  (3U)
#define VIRT_WRAPPER_REG_B419_416_INMUX_0(x)     (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B419_416_INMUX_0_SHIFT)) & VIRT_WRAPPER_REG_B419_416_INMUX_0_MASK)

#define VIRT_WRAPPER_REG_B419_416_INMUX_1_MASK   (0x700U)
#define VIRT_WRAPPER_REG_B419_416_INMUX_1_SHIFT  (8U)
#define VIRT_WRAPPER_REG_B419_416_INMUX_1_WIDTH  (3U)
#define VIRT_WRAPPER_REG_B419_416_INMUX_1(x)     (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B419_416_INMUX_1_SHIFT)) & VIRT_WRAPPER_REG_B419_416_INMUX_1_MASK)

#define VIRT_WRAPPER_REG_B419_416_INMUX_2_MASK   (0x70000U)
#define VIRT_WRAPPER_REG_B419_416_INMUX_2_SHIFT  (16U)
#define VIRT_WRAPPER_REG_B419_416_INMUX_2_WIDTH  (3U)
#define VIRT_WRAPPER_REG_B419_416_INMUX_2(x)     (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B419_416_INMUX_2_SHIFT)) & VIRT_WRAPPER_REG_B419_416_INMUX_2_MASK)
/*! @} */

/*! @name REG_B443_440 - Parameter_n Register */
/*! @{ */

#define VIRT_WRAPPER_REG_B443_440_INMUX_0_MASK   (0x7U)
#define VIRT_WRAPPER_REG_B443_440_INMUX_0_SHIFT  (0U)
#define VIRT_WRAPPER_REG_B443_440_INMUX_0_WIDTH  (3U)
#define VIRT_WRAPPER_REG_B443_440_INMUX_0(x)     (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B443_440_INMUX_0_SHIFT)) & VIRT_WRAPPER_REG_B443_440_INMUX_0_MASK)
/*! @} */

/*! @name REG_B451_448 - Parameter_n Register */
/*! @{ */

#define VIRT_WRAPPER_REG_B451_448_INMUX_0_MASK   (0x7U)
#define VIRT_WRAPPER_REG_B451_448_INMUX_0_SHIFT  (0U)
#define VIRT_WRAPPER_REG_B451_448_INMUX_0_WIDTH  (3U)
#define VIRT_WRAPPER_REG_B451_448_INMUX_0(x)     (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B451_448_INMUX_0_SHIFT)) & VIRT_WRAPPER_REG_B451_448_INMUX_0_MASK)

#define VIRT_WRAPPER_REG_B451_448_INMUX_1_MASK   (0x700U)
#define VIRT_WRAPPER_REG_B451_448_INMUX_1_SHIFT  (8U)
#define VIRT_WRAPPER_REG_B451_448_INMUX_1_WIDTH  (3U)
#define VIRT_WRAPPER_REG_B451_448_INMUX_1(x)     (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B451_448_INMUX_1_SHIFT)) & VIRT_WRAPPER_REG_B451_448_INMUX_1_MASK)

#define VIRT_WRAPPER_REG_B451_448_INMUX_2_MASK   (0x70000U)
#define VIRT_WRAPPER_REG_B451_448_INMUX_2_SHIFT  (16U)
#define VIRT_WRAPPER_REG_B451_448_INMUX_2_WIDTH  (3U)
#define VIRT_WRAPPER_REG_B451_448_INMUX_2(x)     (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B451_448_INMUX_2_SHIFT)) & VIRT_WRAPPER_REG_B451_448_INMUX_2_MASK)

#define VIRT_WRAPPER_REG_B451_448_INMUX_3_MASK   (0x7000000U)
#define VIRT_WRAPPER_REG_B451_448_INMUX_3_SHIFT  (24U)
#define VIRT_WRAPPER_REG_B451_448_INMUX_3_WIDTH  (3U)
#define VIRT_WRAPPER_REG_B451_448_INMUX_3(x)     (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B451_448_INMUX_3_SHIFT)) & VIRT_WRAPPER_REG_B451_448_INMUX_3_MASK)
/*! @} */

/*! @name REG_B455_452 - Parameter_n Register */
/*! @{ */

#define VIRT_WRAPPER_REG_B455_452_INMUX_0_MASK   (0x7U)
#define VIRT_WRAPPER_REG_B455_452_INMUX_0_SHIFT  (0U)
#define VIRT_WRAPPER_REG_B455_452_INMUX_0_WIDTH  (3U)
#define VIRT_WRAPPER_REG_B455_452_INMUX_0(x)     (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B455_452_INMUX_0_SHIFT)) & VIRT_WRAPPER_REG_B455_452_INMUX_0_MASK)

#define VIRT_WRAPPER_REG_B455_452_INMUX_1_MASK   (0x700U)
#define VIRT_WRAPPER_REG_B455_452_INMUX_1_SHIFT  (8U)
#define VIRT_WRAPPER_REG_B455_452_INMUX_1_WIDTH  (3U)
#define VIRT_WRAPPER_REG_B455_452_INMUX_1(x)     (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B455_452_INMUX_1_SHIFT)) & VIRT_WRAPPER_REG_B455_452_INMUX_1_MASK)

#define VIRT_WRAPPER_REG_B455_452_INMUX_2_MASK   (0x70000U)
#define VIRT_WRAPPER_REG_B455_452_INMUX_2_SHIFT  (16U)
#define VIRT_WRAPPER_REG_B455_452_INMUX_2_WIDTH  (3U)
#define VIRT_WRAPPER_REG_B455_452_INMUX_2(x)     (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B455_452_INMUX_2_SHIFT)) & VIRT_WRAPPER_REG_B455_452_INMUX_2_MASK)

#define VIRT_WRAPPER_REG_B455_452_INMUX_3_MASK   (0x7000000U)
#define VIRT_WRAPPER_REG_B455_452_INMUX_3_SHIFT  (24U)
#define VIRT_WRAPPER_REG_B455_452_INMUX_3_WIDTH  (3U)
#define VIRT_WRAPPER_REG_B455_452_INMUX_3(x)     (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B455_452_INMUX_3_SHIFT)) & VIRT_WRAPPER_REG_B455_452_INMUX_3_MASK)
/*! @} */

/*! @name REG_B459_456 - Parameter_n Register */
/*! @{ */

#define VIRT_WRAPPER_REG_B459_456_INMUX_0_MASK   (0x7U)
#define VIRT_WRAPPER_REG_B459_456_INMUX_0_SHIFT  (0U)
#define VIRT_WRAPPER_REG_B459_456_INMUX_0_WIDTH  (3U)
#define VIRT_WRAPPER_REG_B459_456_INMUX_0(x)     (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B459_456_INMUX_0_SHIFT)) & VIRT_WRAPPER_REG_B459_456_INMUX_0_MASK)

#define VIRT_WRAPPER_REG_B459_456_INMUX_1_MASK   (0x700U)
#define VIRT_WRAPPER_REG_B459_456_INMUX_1_SHIFT  (8U)
#define VIRT_WRAPPER_REG_B459_456_INMUX_1_WIDTH  (3U)
#define VIRT_WRAPPER_REG_B459_456_INMUX_1(x)     (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B459_456_INMUX_1_SHIFT)) & VIRT_WRAPPER_REG_B459_456_INMUX_1_MASK)

#define VIRT_WRAPPER_REG_B459_456_INMUX_2_MASK   (0x70000U)
#define VIRT_WRAPPER_REG_B459_456_INMUX_2_SHIFT  (16U)
#define VIRT_WRAPPER_REG_B459_456_INMUX_2_WIDTH  (3U)
#define VIRT_WRAPPER_REG_B459_456_INMUX_2(x)     (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B459_456_INMUX_2_SHIFT)) & VIRT_WRAPPER_REG_B459_456_INMUX_2_MASK)

#define VIRT_WRAPPER_REG_B459_456_INMUX_3_MASK   (0x7000000U)
#define VIRT_WRAPPER_REG_B459_456_INMUX_3_SHIFT  (24U)
#define VIRT_WRAPPER_REG_B459_456_INMUX_3_WIDTH  (3U)
#define VIRT_WRAPPER_REG_B459_456_INMUX_3(x)     (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B459_456_INMUX_3_SHIFT)) & VIRT_WRAPPER_REG_B459_456_INMUX_3_MASK)
/*! @} */

/*! @name REG_B463_460 - Parameter_n Register */
/*! @{ */

#define VIRT_WRAPPER_REG_B463_460_INMUX_0_MASK   (0x7U)
#define VIRT_WRAPPER_REG_B463_460_INMUX_0_SHIFT  (0U)
#define VIRT_WRAPPER_REG_B463_460_INMUX_0_WIDTH  (3U)
#define VIRT_WRAPPER_REG_B463_460_INMUX_0(x)     (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B463_460_INMUX_0_SHIFT)) & VIRT_WRAPPER_REG_B463_460_INMUX_0_MASK)

#define VIRT_WRAPPER_REG_B463_460_INMUX_1_MASK   (0x700U)
#define VIRT_WRAPPER_REG_B463_460_INMUX_1_SHIFT  (8U)
#define VIRT_WRAPPER_REG_B463_460_INMUX_1_WIDTH  (3U)
#define VIRT_WRAPPER_REG_B463_460_INMUX_1(x)     (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B463_460_INMUX_1_SHIFT)) & VIRT_WRAPPER_REG_B463_460_INMUX_1_MASK)

#define VIRT_WRAPPER_REG_B463_460_INMUX_2_MASK   (0x70000U)
#define VIRT_WRAPPER_REG_B463_460_INMUX_2_SHIFT  (16U)
#define VIRT_WRAPPER_REG_B463_460_INMUX_2_WIDTH  (3U)
#define VIRT_WRAPPER_REG_B463_460_INMUX_2(x)     (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B463_460_INMUX_2_SHIFT)) & VIRT_WRAPPER_REG_B463_460_INMUX_2_MASK)

#define VIRT_WRAPPER_REG_B463_460_INMUX_3_MASK   (0x7000000U)
#define VIRT_WRAPPER_REG_B463_460_INMUX_3_SHIFT  (24U)
#define VIRT_WRAPPER_REG_B463_460_INMUX_3_WIDTH  (3U)
#define VIRT_WRAPPER_REG_B463_460_INMUX_3(x)     (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B463_460_INMUX_3_SHIFT)) & VIRT_WRAPPER_REG_B463_460_INMUX_3_MASK)
/*! @} */

/*! @name REG_B467_464 - Parameter_n Register */
/*! @{ */

#define VIRT_WRAPPER_REG_B467_464_INMUX_0_MASK   (0x7U)
#define VIRT_WRAPPER_REG_B467_464_INMUX_0_SHIFT  (0U)
#define VIRT_WRAPPER_REG_B467_464_INMUX_0_WIDTH  (3U)
#define VIRT_WRAPPER_REG_B467_464_INMUX_0(x)     (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B467_464_INMUX_0_SHIFT)) & VIRT_WRAPPER_REG_B467_464_INMUX_0_MASK)

#define VIRT_WRAPPER_REG_B467_464_INMUX_1_MASK   (0x700U)
#define VIRT_WRAPPER_REG_B467_464_INMUX_1_SHIFT  (8U)
#define VIRT_WRAPPER_REG_B467_464_INMUX_1_WIDTH  (3U)
#define VIRT_WRAPPER_REG_B467_464_INMUX_1(x)     (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B467_464_INMUX_1_SHIFT)) & VIRT_WRAPPER_REG_B467_464_INMUX_1_MASK)

#define VIRT_WRAPPER_REG_B467_464_INMUX_2_MASK   (0x70000U)
#define VIRT_WRAPPER_REG_B467_464_INMUX_2_SHIFT  (16U)
#define VIRT_WRAPPER_REG_B467_464_INMUX_2_WIDTH  (3U)
#define VIRT_WRAPPER_REG_B467_464_INMUX_2(x)     (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B467_464_INMUX_2_SHIFT)) & VIRT_WRAPPER_REG_B467_464_INMUX_2_MASK)

#define VIRT_WRAPPER_REG_B467_464_INMUX_3_MASK   (0x7000000U)
#define VIRT_WRAPPER_REG_B467_464_INMUX_3_SHIFT  (24U)
#define VIRT_WRAPPER_REG_B467_464_INMUX_3_WIDTH  (3U)
#define VIRT_WRAPPER_REG_B467_464_INMUX_3(x)     (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B467_464_INMUX_3_SHIFT)) & VIRT_WRAPPER_REG_B467_464_INMUX_3_MASK)
/*! @} */

/*! @name REG_B471_468 - Parameter_n Register */
/*! @{ */

#define VIRT_WRAPPER_REG_B471_468_INMUX_0_MASK   (0x7U)
#define VIRT_WRAPPER_REG_B471_468_INMUX_0_SHIFT  (0U)
#define VIRT_WRAPPER_REG_B471_468_INMUX_0_WIDTH  (3U)
#define VIRT_WRAPPER_REG_B471_468_INMUX_0(x)     (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B471_468_INMUX_0_SHIFT)) & VIRT_WRAPPER_REG_B471_468_INMUX_0_MASK)

#define VIRT_WRAPPER_REG_B471_468_INMUX_1_MASK   (0x700U)
#define VIRT_WRAPPER_REG_B471_468_INMUX_1_SHIFT  (8U)
#define VIRT_WRAPPER_REG_B471_468_INMUX_1_WIDTH  (3U)
#define VIRT_WRAPPER_REG_B471_468_INMUX_1(x)     (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B471_468_INMUX_1_SHIFT)) & VIRT_WRAPPER_REG_B471_468_INMUX_1_MASK)
/*! @} */

/*! @name REG_C - Parameter_n Register */
/*! @{ */

#define VIRT_WRAPPER_REG_C_INTC_CTRL_MASK        (0x7U)
#define VIRT_WRAPPER_REG_C_INTC_CTRL_SHIFT       (0U)
#define VIRT_WRAPPER_REG_C_INTC_CTRL_WIDTH       (3U)
#define VIRT_WRAPPER_REG_C_INTC_CTRL(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_C_INTC_CTRL_SHIFT)) & VIRT_WRAPPER_REG_C_INTC_CTRL_MASK)
/*! @} */

/*!
 * @}
 */ /* end of group VIRT_WRAPPER_Register_Masks */

/*!
 * @}
 */ /* end of group VIRT_WRAPPER_Peripheral_Access_Layer */

#endif  /* #if !defined(S32K388_VIRT_WRAPPER_H_) */
