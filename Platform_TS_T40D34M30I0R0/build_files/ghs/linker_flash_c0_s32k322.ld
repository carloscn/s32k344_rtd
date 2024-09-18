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
/*
* GHS Linker Command File:
* Target device: This linker is demo and it is using for device S32K322 only. It is not part of the production code deliverables.
* Target core: ARM cortex M7
* Linker support for application running on M7_0 core0 only. It need to align with MPU default setup in core_specific.h and system.c as well.
* Memory setting: Local ram of M7_0 (flash)
*/

/*
* GHS Linker Command File:
* 0x00000000    0x0000FFFF  32768   ITCM_0
* 0x00000000    0x0000FFFF  32768   ITCM_1
* 0x20000000    0x2001FFFF  65536   DTCM_0
* 0x20000000    0x2001FFFF  65536   DTCM_1
* 0x00400000    0x007FFFFF  2097152 Program Flash (last 64K sBAF)
* 0x10000000    0x1003FFFF  131072  Data Flash (last 32K HSE_NVM)
* 0x20400000    0x20408000  32768   Standby RAM_0 (32K)
* 0x20400000    0x20427FFF  65536  SRAM_0
* Last 48 KB of SRAM_1 reserved by HSE Firmware
*/

DEFAULTS
{
    int_results_reserve = 0x100
}

MEMORY
{
    int_flash_c0               : ORIGIN = 0x00400000, LENGTH = 0x00100000    /* 1024K */
    int_flash_c1               : ORIGIN = 0x00500000, LENGTH = 0x000D4000    /* 1024K - 176K (sBAF + HSE) */

    int_itcm                   : ORIGIN = 0x00000000, LENGTH = 0x00008000    /* 32K */
    int_dtcm                   : ORIGIN = 0x20000000, LENGTH = 0x0000F000    /* 60K */
    int_stack_dtcm             : ORIGIN = 0x2000F000, LENGTH = 0x00001000    /* 4KB */

    int_sram_c0                : ORIGIN = 0x20400000, LENGTH = 0x00003F00    /* 16K, include int_sram_fls_rsv_c0 */
    int_sram_fls_rsv_c0        : ORIGIN = 0x20403F00, LENGTH = 0x00000100
    int_sram_no_cacheable_c0   : ORIGIN = 0x20404000, LENGTH = 0x00002000    /* 8KB, needs to include int_results  */
    ram_end_c0                 : ORIGIN = 0x20406000, LENGTH = 0x00000000    /* End of core 0 ram */

    int_sram_c1                : ORIGIN = 0x20406000, LENGTH = 0x00001F00    /* 8K, include int_sram_fls_rsv_c1 */
    int_sram_fls_rsv_c1        : ORIGIN = 0x20407F00, LENGTH = 0x00000100
    int_sram_no_cacheable_c1   : ORIGIN = 0x20408000, LENGTH = 0x00004000    /* 16KB, needs to include int_results  */
    ram_end_c1                 : ORIGIN = 0x2040C000, LENGTH = 0x00000000    /* End of core 1 ram */

    int_sram_shareable         : ORIGIN = 0x2040C000, LENGTH = 0x00004000    /* 16KB */

    ram_rsvd2                  : ORIGIN = 0x20410000, LENGTH = 0x00000000    /* End of SRAM */
}

SECTIONS
{
    .boot_header                                 ALIGN(4)     : > int_flash_c0
    .intc_vector                                 ALIGN(2048)  : > .
    .core_loop                                   ALIGN(4)     : > .
    .startup                                     ALIGN(4)     : > . /* Reset code*/
    .text.startup                                ALIGN(4)     : > .
    .text                                        ALIGN(4)     : > .
    .mcal_text                                   ALIGN(4)     : > .
	.acmcu_code_rom                              ALIGN(4)     : > .
	.acfls_code_rom                              ALIGN(4)     : > .

    .rodata                                     ALIGN(4)      : > .
    .mcal_const_cfg                             ALIGN(4)      : > .
    .mcal_const                                 ALIGN(4)      : > .
    .init_table                                 ALIGN(4)      : > .
    .zero_table                                 ALIGN(4)      : > .

    /* ROM sections for initialized data */
    .ROM.ramcode                  ROM(.ramcode)                 ALIGN(4)      : > .
    .ROM.data                     ROM(.data)                    ALIGN(4)      : > .
    .ROM.mcal_data                ROM(.mcal_data)               ALIGN(4)      : > .
    .ROM.mcal_data_no_cacheable   ROM(.mcal_data_no_cacheable)  ALIGN(4)      : > .
    .ROM.mcal_const_no_cacheable  ROM(.mcal_const_no_cacheable) ALIGN(4)      : > .
    .ROM.mcal_shared_data         ROM(.mcal_shared_data)        ALIGN(4)      : > .
    .ROM.dtcm_data                ROM(.dtcm_data)               ALIGN(4)      : > .
    .ROM.itcm_text                ROM(.itcm_text)               ALIGN(4)      : > .

    .ramcode                                ABS ALIGN(4)      : > int_sram_c0
    .data                                       ALIGN(4)      : > .
    .mcal_data                                  ALIGN(4)      : > .
    .bss                               (NOLOAD) ALIGN(16)     : > .
    .mcal_bss                          (NOLOAD) ALIGN(16)     : > .
    // reserve space for .acfls_code_ram
    .acfls_code_ram                             ALIGN(4) : {. += SIZEOF(.acfls_code_rom);} > .

    .int_results           ALIGN(4) PAD(int_results_reserve)  : > int_sram_no_cacheable_c0
    .mcal_bss_no_cacheable            (NOLOAD) ALIGN(16)      : > .
    .mcal_data_no_cacheable                    ALIGN(4)       : > .
    .mcal_const_no_cacheable                   ALIGN(4)       : > .

    .mcal_shared_data                           ALIGN(16)     : > int_sram_shareable
    .mcal_shared_bss                   (NOLOAD) ALIGN(4)      : > .

    .itcm_text                                 ALIGN(4)         : > int_itcm
    .intc_vector_dtcm     ALIGN(2048) PAD(SIZEOF(.intc_vector)) : > int_dtcm
    .dtcm_data                                 ALIGN(4)         : > .
    .bss_tcm_data                     (NOLOAD) ALIGN(4)         : > .

    __Stack_dtcm_end              = ADDR(int_stack_dtcm);
    __Stack_dtcm_start            = ADDR(int_stack_dtcm) + SIZEOF(int_stack_dtcm);

    __INT_SRAM_START              = ADDR(int_sram_c0);
    __INT_SRAM_END                = ADDR(ram_end_c0);

    __INT_ITCM_START              = ADDR(int_itcm);
    __INT_ITCM_END                = ADDR(int_itcm) + SIZEOF(int_itcm);

    __INT_DTCM_START              = ADDR(int_dtcm);
    __INT_DTCM_END                = ADDR(int_dtcm) + SIZEOF(int_dtcm) + SIZEOF(int_stack_dtcm);

    __RAM_SHAREABLE_START         = ADDR(int_sram_shareable);
    __RAM_SHAREABLE_END           = ADDR(int_sram_shareable) + SIZEOF(int_sram_shareable);
    __RAM_SHAREABLE_SIZE          = 0xE; /*16 kbyte*/
    __ROM_SHAREABLE_START         = ADDR(.ROM.mcal_shared_data);
    __ROM_SHAREABLE_END           = ADDR(.ROM.mcal_shared_data) + SIZEOF(.ROM.mcal_shared_data);
    __RAM_NO_CACHEABLE_START      = ADDR(int_sram_no_cacheable_c0);
    __RAM_NO_CACHEABLE_END        = ADDR(int_sram_shareable)-1;
    __RAM_NO_CACHEABLE_SIZE       = 0xD;  /* 8kbyte in power of 2 */
    __ROM_NO_CACHEABLE_START      = ADDR(.ROM.mcal_data_no_cacheable);
    __ROM_NO_CACHEABLE_END        = ADDR(.ROM.mcal_const_no_cacheable) + SIZEOF(.ROM.mcal_const_no_cacheable);
    __RAM_MCAL_DATA_NC_INIT_START = ADDR(.mcal_data_no_cacheable);
    __RAM_MCAL_DATA_NC_INIT_END   = ADDR(.mcal_const_no_cacheable) + SIZEOF(.mcal_const_no_cacheable);
    __ROM_MCAL_DATA_NC_INIT_START = ADDR(.ROM.mcal_data_no_cacheable);
    __ROM_MCAL_DATA_NC_INIT_END   = ADDR(.ROM.mcal_const_no_cacheable) + SIZEOF(.ROM.mcal_const_no_cacheable);
    __RAM_CACHEABLE_CODE_START    = ADDR(.ramcode);
    __RAM_CACHEABLE_CODE_END      = ADDR(.ramcode) + SIZEOF(.ramcode);
    __ROM_CACHEABLE_CODE_START    = ADDR(.ROM.ramcode);
    __ROM_CACHEABLE_CODE_END      = ADDR(.ROM.ramcode) + SIZEOF(.ROM.ramcode);
    __RAM_CACHEABLE_START         = ADDR(.data);
    __RAM_CACHEABLE_END           = ADDR(int_sram_no_cacheable_c0)-1;
    __RAM_CACHEABLE_SIZE          = 0xE;  /* 16kbyte in power of 2 */
    __ROM_CACHEABLE_START         = ADDR(.ROM.data);
    __ROM_CACHEABLE_END           = ADDR(.ROM.mcal_data) + SIZEOF(.ROM.mcal_data);
    __ROM_CODE_START              = ADDR(int_flash_c0);
    __ROM_DATA_START              = 0x10000000;

    __BSS_SRAM_START              = ADDR(.bss);
    __BSS_SRAM_SIZE               = (ADDR(.mcal_bss) + SIZEOF(.mcal_bss)) - ADDR(.bss);
    __BSS_SRAM_END                = ADDR(.mcal_bss) + SIZEOF(.mcal_bss);

    __BSS_SRAM_NC_START           = ADDR(.mcal_bss_no_cacheable);
    __BSS_SRAM_NC_SIZE            = SIZEOF(.mcal_bss_no_cacheable);
    __BSS_SRAM_NC_END             = __BSS_SRAM_NC_START + __BSS_SRAM_NC_SIZE;

    __BSS_SRAM_SH_START           = ADDR(.mcal_shared_bss);
    __BSS_SRAM_SH_SIZE            = SIZEOF(.mcal_shared_bss);
    __BSS_SRAM_SH_END             = __BSS_SRAM_SH_START + __BSS_SRAM_SH_SIZE;


    __RAM_INTERRUPT_START         = ADDR(.intc_vector_dtcm);
    __INIT_INTERRUPT_START        = ADDR(.intc_vector);
    __INIT_INTERRUPT_END          = ADDR(.intc_vector) + SIZEOF(.intc_vector);

    __RAM_ITCM_START              = ADDR(.itcm_text);
    __ROM_ITCM_START              = ADDR(.ROM.itcm_text);
    __ROM_ITCM_END                = ADDR(.ROM.itcm_text) + SIZEOF(.ROM.itcm_text);

    __RAM_DTCM_DATA_START         = ADDR(.dtcm_data);
    __ROM_DTCM_DATA_START         = ADDR(.ROM.dtcm_data);
    __ROM_DTCM_END                = ADDR(.ROM.dtcm_data) + SIZEOF(.ROM.dtcm_data);

    __INIT_TABLE                  = ADDR(.init_table);
    __ZERO_TABLE                  = ADDR(.zero_table);

    __RAM_INIT                    = 1;
    __ITCM_INIT                   = 1;
    __DTCM_INIT                   = 1;

    /* Fls module access code support */
    Fls_ACEraseRomStart         = ADDR(.acfls_code_rom);
    Fls_ACEraseRomEnd           = ADDR(.acfls_code_rom) + SIZEOF(.acfls_code_rom);
    Fls_ACEraseSize             = (SIZEOF(.acfls_code_rom)+3) / 4; /* Copy 4 bytes at a time*/

    Fls_ACWriteRomStart         = ADDR(.acfls_code_rom);
    Fls_ACWriteRomEnd           = ADDR(.acfls_code_rom) + SIZEOF(.acfls_code_rom);
    Fls_ACWriteSize             = (SIZEOF(.acfls_code_rom)+3) / 4; /* Copy 4 bytes at a time*/

    _ERASE_FUNC_ADDRESS_        = ADDR(.acfls_code_ram);
    _WRITE_FUNC_ADDRESS_        = ADDR(.acfls_code_ram);

    __ENTRY_VTABLE              = ADDR(.intc_vector);

    __CORE0_VTOR                  = __INIT_INTERRUPT_START;
    __CORE1_VTOR                  = ADDR(int_flash_c1);
    __CORE2_VTOR                  = __INIT_INTERRUPT_START;
    __INDEX_COPY_CORE2            = 4;    /* This symbol is used to initialize data of ITCM/DTCM for CORE2 */

}