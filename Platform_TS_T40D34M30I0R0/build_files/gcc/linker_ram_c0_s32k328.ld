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
* GCC Linker Command File:
* Target device: This linker is demo and it is using for device S32K328 only. It is not part of the production code deliverables.
* Target core: ARM cortex M7
* Linker support for application running on M7_0 core0 only. It need to align with MPU default setup in core_specific.h and system.c as well.
* Memory setting: Local ram of M7_0 (sram)
*/

/*
* GCC Linker Command File:
* 0x00000000    0x0000FFFF  65536   ITCM_0
* 0x00000000    0x0000FFFF  65536   ITCM_2
* 0x20000000    0x2001FFFF  131072  DTCM_0
* 0x20000000    0x2001FFFF  131072  DTCM_2
* 0x00400000    0x00BFFFFF  8388608 Program Flash
* 0x10000000    0x1001FFFF  131072  Data Flash
* 0x20400000    0x2043FFFF  262144  SRAM_0
* 0x20440000    0x2047FFFF  262144  SRAM_1
* 0x20480000    0x204BFFFF  262144  SRAM_2
* Last 176 KB of CODE_FLASH reserved by HSE Firmware
*/

HEAP_SIZE  = DEFINED(__heap_size__)  ? __heap_size__  : 0x00001000;

ENTRY(Reset_Handler)

MEMORY
{
    int_itcm                   : ORIGIN = 0x00000000, LENGTH = 0x00010000    /* 64KB */
    int_dtcm                   : ORIGIN = 0x20000000, LENGTH = 0x0001F000    /* 124KB */
    int_stack_dtcm             : ORIGIN = 0x2001F000, LENGTH = 0x00001000    /* 4KB */

    int_sram_c0                : ORIGIN = 0x20400000, LENGTH = 0x0001FF00    /* 128KB. include int_sram_fls_rsv_c0 */
    int_sram_fls_rsv_c0        : ORIGIN = 0x2041FF00, LENGTH = 0x00000100
    int_sram_no_cacheable_c0   : ORIGIN = 0x20420000, LENGTH = 0x00010000    /* 64KB, needs to include int_results */
    ram_end_c0                 : ORIGIN = 0x20430000, LENGTH = 0x00000000    /* End of core 0 ram */

    int_sram_c1                : ORIGIN = 0x20430000, LENGTH = 0x0000FF00    /* 64KB. include int_sram_fls_rsv_c1 */
    int_sram_fls_rsv_c1        : ORIGIN = 0x2043FF00, LENGTH = 0x00000100
    int_sram_no_cacheable_c1   : ORIGIN = 0x20440000, LENGTH = 0x00010000    /* 64KB, needs to include int_results */
    ram_end_c1                 : ORIGIN = 0x20450000, LENGTH = 0x00000000    /* End of core 1 ram */

    int_sram_c2                : ORIGIN = 0x20450000, LENGTH = 0x0000FF00    /* 64KB, include int_sram_fls_rsv_c2 */
    int_sram_fls_rsv_c2        : ORIGIN = 0x2045FF00, LENGTH = 0x00000100
    int_sram_no_cacheable_c2   : ORIGIN = 0x20460000, LENGTH = 0x00020000    /* 128KB, needs to include int_results  */
    ram_end_c2                 : ORIGIN = 0x20480000, LENGTH = 0x00000000    /* End of core 1 ram */

    int_sram_shareable         : ORIGIN = 0x20480000, LENGTH = 0x00040000    /* 256KB */
    ram_rsvd2                  : ORIGIN = 0x204C0000, LENGTH = 0             /* End of SRAM */
}


SECTIONS
{

    .sram :
    {
        . = ALIGN(4);
        KEEP(*(.core_loop))
        . = ALIGN(4);
        *(.startup)
        . = ALIGN(4);
        *(.text.startup)
        . = ALIGN(4);
        *(.text)
        *(.text*)
        . = ALIGN(4);
        *(.mcal_text)
        . = ALIGN(4);
        KEEP(*(.init))
        . = ALIGN(4);
        KEEP(*(.fini))

        . = ALIGN(4);
        *(.rodata)
        *(.rodata*)
        . = ALIGN(4);
        *(.mcal_const_cfg)
        . = ALIGN(4);
        *(.mcal_const)
        . = ALIGN(4);
        __init_table = .;
        KEEP(*(.init_table))
        . = ALIGN(4);
        __zero_table = .;
        KEEP(*(.zero_table))

        . = ALIGN(4);
        *(.acmcu_code_rom)
        . = ALIGN(4);
        *(.ramcode)
        . = ALIGN(4);
        *(.data)
        *(.data*)
        . = ALIGN(4);
        *(.mcal_data)
        . = ALIGN(16);
        __sram_bss_start = .;
        *(.bss)
        *(.bss*)
        . = ALIGN(16);
        *(.mcal_bss)
        . = ALIGN(4);
        __sram_bss_end = .;
    } > int_sram_c0
    /* heap section */
    .heap (NOLOAD):
    {
    	. += ALIGN(4);
	    _end = .;
	    end = .;
        _heap_start = .;
        . += HEAP_SIZE;
        _heap_end = .;
    } > int_sram_c0

    .acfls_code_rom :
    {
        acfls_code_rom_start = .;
        . = ALIGN(0x4);
        *(.acfls_code_rom)
        acfls_code_rom_end = .;
    } > int_sram_c0

    .acfls_code_ram :
    {
        . += (acfls_code_rom_end - acfls_code_rom_start );
    } > int_sram_c0

    . = ALIGN(4);
    __init_dtcm_data_start = .;

    .non_cacheable :
    {
        . = ALIGN(4);
        KEEP(*(.int_results))
        . += 0x100;
        . = ALIGN(4);
        __interrupts_init_start = .;
        KEEP(*(.intc_vector))
        . = ALIGN(4);
        __interrupts_init_end = .;
        . = ALIGN(16);
        __non_cacheable_bss_start = .;
        *(.mcal_bss_no_cacheable)
        . = ALIGN(4);
        __non_cacheable_bss_end = .;
        . = ALIGN(4);
        *(.mcal_data_no_cacheable)
        . = ALIGN(4);
        *(.mcal_const_no_cacheable)
        HSE_LOOP_ADDR = .;
        LONG(0x0);
    } > int_sram_no_cacheable_c0

    .int_vector :
    {
        . = ALIGN(2048);
        __interrupts_ram_start = .;
        . += __interrupts_init_end - __interrupts_init_start;
        . = ALIGN(4);
        __interrupts_ram_end = .;
    } > int_dtcm

    .data_tcm_data : AT(__init_dtcm_data_start)
    {
        . = ALIGN(4);
        __dtcm_data_start__ = .;
        *(.dtcm_data*)
        . = ALIGN(4);
        __dtcm_data_end__ = .;
    } > int_dtcm

    __init_dtcm_data_end = __init_dtcm_data_start + (__dtcm_data_end__ - __dtcm_data_start__);

    .bss_tcm_data (NOLOAD) :
    {
        . = ALIGN(4);
        __dtcm_bss_start__ = .;
        *(.dtcm_bss*)
        . = ALIGN(4);
        __dtcm_bss_end__ = .;
    } > int_dtcm

    __init_itcm_code_start = __init_dtcm_data_end;

   .itcm_text : AT(__init_itcm_code_start)
    {
        . = ALIGN(4);
        __itcm_start__ = .;
        *(.itcm_text*)
        . = ALIGN(4);
        __itcm_end__ = .;
    } > int_itcm

    __init_itcm_code_end = __init_itcm_code_start + (__itcm_end__ - __itcm_start__);

    .shareable_ram :
    {
    	. = ALIGN(16);
    	__shareable_bss_start = .;
    	KEEP(*(.mcal_shared_bss))
    	. = ALIGN(4);
    	__shareable_bss_end = .;
        . = ALIGN(16);
    	KEEP(*(.mcal_shared_data))
    } > int_sram_shareable

    __Stack_dtcm_end        = ORIGIN(int_stack_dtcm);
    __Stack_dtcm_start      = ORIGIN(int_stack_dtcm) + LENGTH(int_stack_dtcm);

    __INT_SRAM_START         = ORIGIN(int_sram_c0);
    __INT_SRAM_END           = ORIGIN(ram_end_c0);

    __INT_ITCM_START         = ORIGIN(int_itcm);
    __INT_ITCM_END           = ORIGIN(int_itcm) + LENGTH(int_itcm);

    __INT_DTCM_START         = ORIGIN(int_dtcm);
    __INT_DTCM_END           = ORIGIN(int_dtcm) + LENGTH(int_dtcm) + LENGTH(int_stack_dtcm);

    __RAM_SHAREABLE_START    = ORIGIN(int_sram_shareable);
    __RAM_SHAREABLE_END      = ORIGIN(int_sram_shareable) + LENGTH(int_sram_shareable);
    __RAM_SHAREABLE_SIZE     = 0x12;  /* 256kbyte in power of 2 */
    __ROM_SHAREABLE_START    = 0;
    __ROM_SHAREABLE_END      = 0;
    __RAM_NO_CACHEABLE_START = ORIGIN(int_sram_no_cacheable_c0);
    __RAM_NO_CACHEABLE_END   = ORIGIN(int_sram_no_cacheable_c0) + LENGTH(int_sram_no_cacheable_c0);
    __RAM_NO_CACHEABLE_SIZE  = 0x10;  /* 64kbyte in power of 2 */
    __ROM_NO_CACHEABLE_START = 0;
    __ROM_NO_CACHEABLE_END   = 0;
    __RAM_CACHEABLE_START    = ORIGIN(int_sram_c0);
    __RAM_CACHEABLE_END      = ORIGIN(int_sram_c0) + LENGTH(int_sram_c0);
    __RAM_CACHEABLE_SIZE     = 0x11;  /* 128kbyte in power of 2 */
    __ROM_CACHEABLE_START    = 0;
    __ROM_CACHEABLE_END      = 0;
    __ROM_CODE_START         = 0x00400000;
    __ROM_DATA_START         = 0x10000000;

    __BSS_SRAM_START         = __sram_bss_start;
    __BSS_SRAM_END           = __sram_bss_end;
    __BSS_SRAM_SIZE          = __sram_bss_end - __sram_bss_start;

    __BSS_SRAM_NC_START      = __non_cacheable_bss_start;
    __BSS_SRAM_NC_SIZE       = __non_cacheable_bss_end - __non_cacheable_bss_start;
    __BSS_SRAM_NC_END        = __non_cacheable_bss_end;

    __BSS_SRAM_SH_START      = __shareable_bss_start;
    __BSS_SRAM_SH_SIZE       = __shareable_bss_end - __shareable_bss_start;
    __BSS_SRAM_SH_END        = __shareable_bss_end;

    __RAM_INTERRUPT_START    = __interrupts_ram_start;
    __INIT_INTERRUPT_START   = __interrupts_init_start;
    __INIT_INTERRUPT_END     = __interrupts_init_end;

    __RAM_ITCM_START         = __itcm_start__;
    __ROM_ITCM_START         = __init_itcm_code_start;
    __ROM_ITCM_END           = __init_itcm_code_end;

    __RAM_DTCM_DATA_START    = __dtcm_data_start__;
    __ROM_DTCM_DATA_START    = __init_dtcm_data_start;
    __ROM_DTCM_END           = __init_dtcm_data_end;

    __INIT_TABLE             = __init_table;
    __ZERO_TABLE             = __zero_table;

    __RAM_INIT               = 0;
    __ITCM_INIT              = 1;
    __DTCM_INIT              = 1;
   /* Discard boot header in RAM */
   /DISCARD/ : { *(.boot_header) }
    /* Fls module access code support */
    Fls_ACEraseRomStart         = ADDR(.acfls_code_rom);
    Fls_ACEraseRomEnd           = ADDR(.acfls_code_rom) + SIZEOF(.acfls_code_rom);
    Fls_ACEraseSize             = (SIZEOF(.acfls_code_rom)+3) / 4; /* Copy 4 bytes at a time*/

    Fls_ACWriteRomStart         = ADDR(.acfls_code_rom);
    Fls_ACWriteRomEnd           = ADDR(.acfls_code_rom) + SIZEOF(.acfls_code_rom);
    Fls_ACWriteSize             = (SIZEOF(.acfls_code_rom)+3) / 4; /* Copy 4 bytes at a time*/

    _ERASE_FUNC_ADDRESS_        = ADDR(.acfls_code_ram);
    _WRITE_FUNC_ADDRESS_        = ADDR(.acfls_code_ram);

    __ENTRY_VTABLE              = __INIT_INTERRUPT_START;
    __CORE0_VTOR                = __INIT_INTERRUPT_START;
    __CORE1_VTOR                = __INIT_INTERRUPT_START;
    __CORE2_VTOR                = __INIT_INTERRUPT_START;

    __INDEX_COPY_CORE2          = 0;    /* This symbol is used to initialize data of ITCM/DTCM for CORE2 */
}
