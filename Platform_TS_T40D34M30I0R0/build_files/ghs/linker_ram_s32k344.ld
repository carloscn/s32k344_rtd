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
* Target device: This linker is demo and it is using for device S32K344 only. It is not part of the production code deliverables.
* Target core: ARM cortex M7
* Linker need to align with MPU default setup in system.c
*/

/*
* GHS Linker Command File:
* 0x00000000    0x0000FFFF  65536   ITCM
* 0x20000000    0x2001FFFF  131072  DTCM
* 0x20400000    0x20427FFF  163840  SRAM_0
* 0x20428000    0x20443FFF  114688  SRAM_1  /* Actually 112 kB instead of 160KB in RM
*/

DEFAULTS
{
    int_results_reserve = 0x100
}

MEMORY
{
    int_itcm                : ORIGIN = 0x00000000, LENGTH = 0x00010000    /* 64KB */
    int_dtcm                : ORIGIN = 0x20000000, LENGTH = 0x0001F000    /* 124K */
    int_stack_dtcm          : ORIGIN = 0x2001F000, LENGTH = 0x00001000    /* 4KB */
    int_sram                : ORIGIN = 0x20400000, LENGTH = 0x00030000    /* 192KB*/
    int_sram_no_cacheable   : ORIGIN = 0x20430000, LENGTH = 0x0000FF00    /* 64KB, needs to include int_sram_results  */
    int_sram_results        : ORIGIN = 0x2043FF00, LENGTH = 0x00000100
    int_sram_shareable      : ORIGIN = 0x20440000, LENGTH = 0x00004000    /* 16KB */
    ram_rsvd2               : ORIGIN = 0x20444000, LENGTH = 0             /* End of SRAM */
}

SECTIONS
{
    .core_loop                                   ALIGN(4)     : > int_sram
    .startup                                     ALIGN(4)     : > . /* Reset code*/
    .text.startup                                ALIGN(4)     : > .
    .text                                        ALIGN(4)     : > .
    .mcal_text                                   ALIGN(4)     : > .

    .rodata                                     ALIGN(4)      : > .
    .mcal_const_cfg                             ALIGN(4)      : > .
    .mcal_const                                 ALIGN(4)      : > .
    .init_table                                 ALIGN(4)      : > .
    .zero_table                                 ALIGN(4)      : > .

    .acfls_code_rom                              ALIGN(4)     : > .
    .acfls_code_ram                              ALIGN(4) : {. += SIZEOF(.acfls_code_rom);} > .
    .acmcu_code_rom                              ALIGN(4)     : > .
    .ramcode                                 ABS ALIGN(4)     : > .
    .data                                        ALIGN(4)     : > .
    .mcal_data                                   ALIGN(4)     : > .
    .bss                                (NOLOAD) ALIGN(16)    : > .
    .mcal_bss                           (NOLOAD) ALIGN(16)    : > .
    __BSS_SRAM_END = align(4);

    .ROM.dtcm_data               ROM(.dtcm_data) ALIGN(4)     : > .
    __ROM_DTCM_END = align(4);
    .ROM.itcm_text               ROM(.itcm_text) ALIGN(4)     : > .
    __ROM_ITCM_END = align(4);

    .intc_vector                               ALIGN(2048)    : > int_sram_no_cacheable
    .mcal_bss_no_cacheable            (NOLOAD) ALIGN(16)      : > .
    __BSS_SRAM_NC_END = align(4);
    .mcal_data_no_cacheable                    ALIGN(4)       : > .
    .mcal_const_no_cacheable                   ALIGN(4)       : > .
    .int_results           ALIGN(4) PAD(int_results_reserve) (NOLOAD)  : > int_sram_results

    .mcal_shared_data                          ALIGN(16)      : > int_sram_shareable
    .mcal_shared_bss                  (NOLOAD) ALIGN(16)      : > .
    __BSS_SRAM_SH_END = align(4);

    .itcm_text                                 ALIGN(4)                 : > int_itcm
    .intc_vector_dtcm             ALIGN(2048) PAD(SIZEOF(.intc_vector)) : > int_dtcm
    .dtcm_data                                 ALIGN(4)                 : > .
    .dtcm_bss                         (NOLOAD) ALIGN(4)                 : > .

    __Stack_dtcm_end              = ADDR(int_stack_dtcm);
    __Stack_dtcm_start            = ADDR(int_stack_dtcm) + SIZEOF(int_stack_dtcm);

    __INT_SRAM_START              = ADDR(int_sram);
    __INT_SRAM_END                = ADDR(ram_rsvd2);

    __INT_ITCM_START              = ADDR(int_itcm);
    __INT_ITCM_END                = ADDR(int_itcm) + SIZEOF(int_itcm);

    __INT_DTCM_START              = ADDR(int_dtcm);
    __INT_DTCM_END                = ADDR(int_dtcm) + SIZEOF(int_dtcm) + SIZEOF(int_stack_dtcm);

    __RAM_SHAREABLE_START         = ADDR(int_sram_shareable);
    __RAM_SHAREABLE_END           = ADDR(int_sram_shareable) + SIZEOF(int_sram_shareable);
    __RAM_SHAREABLE_SIZE          = 0xE;  /* 16 kbyte in power of 2 */
    __ROM_SHAREABLE_START         = 0;
    __ROM_SHAREABLE_END           = 0;
    __RAM_CACHEABLE_CODE_START    = ADDR(.ramcode);
    __RAM_CACHEABLE_CODE_END      = ADDR(.acmcu_code_rom) + SIZEOF(.acmcu_code_rom);
    __ROM_CACHEABLE_CODE_START    = 0;
    __ROM_CACHEABLE_CODE_END      = 0;
    __RAM_NO_CACHEABLE_START      = ADDR(int_sram_no_cacheable);
    __RAM_NO_CACHEABLE_END        = ADDR(int_sram_no_cacheable) + SIZEOF(int_sram_no_cacheable);
    __RAM_NO_CACHEABLE_SIZE       = 0x10;  /* 64kbyte in power of 2 */
    __ROM_NO_CACHEABLE_START      = 0;
    __ROM_NO_CACHEABLE_END        = 0;
    __RAM_MCAL_DATA_NC_INIT_START = ADDR(.mcal_data_no_cacheable);
    __RAM_MCAL_DATA_NC_INIT_END   = ADDR(.mcal_const_no_cacheable) + SIZEOF(.mcal_const_no_cacheable);
    __ROM_MCAL_DATA_NC_INIT_START = 0;
    __ROM_MCAL_DATA_NC_INIT_END   = 0;
    __RAM_CACHEABLE_START         = ADDR(int_sram);
    __RAM_CACHEABLE_END           = ADDR(int_sram) + SIZEOF(int_sram) - 1;
    __RAM_CACHEABLE_SIZE          = 0x12;  /* 256kbyte in power of 2 */
    __ROM_CACHEABLE_START         = 0;
    __ROM_CACHEABLE_END           = 0;
    __ROM_CODE_START              = 0x00400000;
    __ROM_DATA_START              = 0x10000000;

    __BSS_SRAM_START              = ADDR(.bss);
    __BSS_SRAM_SIZE               = (ADDR(.mcal_bss) + SIZEOF(.mcal_bss)) - ADDR(.bss);

    __BSS_SRAM_NC_START           = ADDR(.mcal_bss_no_cacheable);
    __BSS_SRAM_NC_SIZE            = SIZEOF(.mcal_bss_no_cacheable);

    __BSS_SRAM_SH_START           = ADDR(.mcal_shared_bss);
    __BSS_SRAM_SH_SIZE            = SIZEOF(.mcal_shared_bss);

    __RAM_INTERRUPT_START         = ADDR(.intc_vector_dtcm);
    __INIT_INTERRUPT_START        = ADDR(.intc_vector);
    __INIT_INTERRUPT_END          = ADDR(.intc_vector) + SIZEOF(.intc_vector);

    __RAM_ITCM_START              = ADDR(.itcm_text);
    __ROM_ITCM_START              = ADDR(.ROM.itcm_text);

    __RAM_DTCM_DATA_START         = ADDR(.dtcm_data);
    __ROM_DTCM_DATA_START         = ADDR(.ROM.dtcm_data);

    __INIT_TABLE                  = ADDR(.init_table);
    __ZERO_TABLE                  = ADDR(.zero_table);

    __RAM_INIT                    = 0;
    __ITCM_INIT                   = 1;
    __DTCM_INIT                   = 1;
   /* Discard boot header in RAM */
   /DISCARD/ : { *(.boot_header) }

   /* Fls module access code support */
    Fls_ACEraseRomStart           = ADDR(.acfls_code_rom);
    Fls_ACEraseRomEnd             = ADDR(.acfls_code_rom) + SIZEOF(.acfls_code_rom);
    Fls_ACEraseSize               = (SIZEOF(.acfls_code_rom)+3) / 4; /* Copy 4 bytes at a time*/

    Fls_ACWriteRomStart           = ADDR(.acfls_code_rom);
    Fls_ACWriteRomEnd             = ADDR(.acfls_code_rom) + SIZEOF(.acfls_code_rom);
    Fls_ACWriteSize               = (SIZEOF(.acfls_code_rom)+3) / 4; /* Copy 4 bytes at a time*/

    _ERASE_FUNC_ADDRESS_          = ADDR(.acfls_code_ram);
    _WRITE_FUNC_ADDRESS_          = ADDR(.acfls_code_ram);

    __ENTRY_VTABLE                = __INIT_INTERRUPT_START;
    /* This values are set, but used only when the core boots from flash */
    __CORE0_VTOR                  = __INIT_INTERRUPT_START;
    __CORE1_VTOR                  = __INIT_INTERRUPT_START;
    __CORE2_VTOR                  = __INIT_INTERRUPT_START;
    __INDEX_COPY_CORE2            = 4;    /* This symbol is used to initialize data of ITCM/DTCM for CORE2 */

}
