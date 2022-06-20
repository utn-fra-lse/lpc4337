/*
 * GENERATED FILE - DO NOT EDIT
 * Copyright (c) 2008-2013 Code Red Technologies Ltd,
 * Copyright 2015, 2018-2019 NXP
 * (c) NXP Semiconductors 2013-2022
 * Generated linker script file for LPC4337-M0
 * Created from linkscript.ldt by FMCreateLinkLibraries
 * Using Freemarker v2.3.30
 * MCUXpresso IDE v11.3.1 [Build 5262] [2021-04-02] on Jun 20, 2022 2:38:14 PM
 */

INCLUDE "multicore_blinky_m0app_Debug_library.ld"
INCLUDE "multicore_blinky_m0app_Debug_memory.ld"

ENTRY(ResetISR)

SECTIONS
{
     /* MAIN TEXT SECTION */
    .text : ALIGN(4)
    {
        FILL(0xff)
        __vectors_start__ = ABSOLUTE(.) ;
        KEEP(*(.isr_vector))
        /* Global Section Table */
        . = ALIGN(4) ;
        __section_table_start = .;
        __data_section_table = .;
        LONG(LOADADDR(.data));
        LONG(    ADDR(.data));
        LONG(  SIZEOF(.data));
        LONG(LOADADDR(.data_RAM2));
        LONG(    ADDR(.data_RAM2));
        LONG(  SIZEOF(.data_RAM2));
        LONG(LOADADDR(.data_RAM3));
        LONG(    ADDR(.data_RAM3));
        LONG(  SIZEOF(.data_RAM3));
        LONG(LOADADDR(.data_RAM4));
        LONG(    ADDR(.data_RAM4));
        LONG(  SIZEOF(.data_RAM4));
        __data_section_table_end = .;
        __bss_section_table = .;
        LONG(    ADDR(.bss));
        LONG(  SIZEOF(.bss));
        LONG(    ADDR(.bss_RAM2));
        LONG(  SIZEOF(.bss_RAM2));
        LONG(    ADDR(.bss_RAM3));
        LONG(  SIZEOF(.bss_RAM3));
        LONG(    ADDR(.bss_RAM4));
        LONG(  SIZEOF(.bss_RAM4));
        __bss_section_table_end = .;
        __section_table_end = . ;
        /* End of Global Section Table */

        *(.after_vectors*)

    } > MFlashB512

    .text : ALIGN(4)
    {
       *(.text*)
       *(.rodata .rodata.* .constdata .constdata.*)
       . = ALIGN(4);
    } > MFlashB512
    /*
     * for exception handling/unwind - some Newlib functions (in common
     * with C++ and STDC++) use this.
     */
    .ARM.extab : ALIGN(4)
    {
        *(.ARM.extab* .gnu.linkonce.armextab.*)
    } > MFlashB512

    .ARM.exidx : ALIGN(4)
    {
        __exidx_start = .;
        *(.ARM.exidx* .gnu.linkonce.armexidx.*)
        __exidx_end = .;
    } > MFlashB512
 
    _etext = .;
        
    /* DATA section for RamAHB32 */

    .data_RAM2 : ALIGN(4)
    {
        FILL(0xff)
        PROVIDE(__start_data_RAM2 = .) ;
        PROVIDE(__start_data_RamAHB32 = .) ;
        *(.ramfunc.$RAM2)
        *(.ramfunc.$RamAHB32)
        *(.data.$RAM2)
        *(.data.$RamAHB32)
        *(.data.$RAM2.*)
        *(.data.$RamAHB32.*)
        . = ALIGN(4) ;
        PROVIDE(__end_data_RAM2 = .) ;
        PROVIDE(__end_data_RamAHB32 = .) ;
     } > RamAHB32 AT>MFlashB512

    /* DATA section for RamAHB16 */

    .data_RAM3 : ALIGN(4)
    {
        FILL(0xff)
        PROVIDE(__start_data_RAM3 = .) ;
        PROVIDE(__start_data_RamAHB16 = .) ;
        *(.ramfunc.$RAM3)
        *(.ramfunc.$RamAHB16)
        *(.data.$RAM3)
        *(.data.$RamAHB16)
        *(.data.$RAM3.*)
        *(.data.$RamAHB16.*)
        . = ALIGN(4) ;
        PROVIDE(__end_data_RAM3 = .) ;
        PROVIDE(__end_data_RamAHB16 = .) ;
     } > RamAHB16 AT>MFlashB512

    /* DATA section for RamAHB_ETB16 */

    .data_RAM4 : ALIGN(4)
    {
        FILL(0xff)
        PROVIDE(__start_data_RAM4 = .) ;
        PROVIDE(__start_data_RamAHB_ETB16 = .) ;
        *(.ramfunc.$RAM4)
        *(.ramfunc.$RamAHB_ETB16)
        *(.data.$RAM4)
        *(.data.$RamAHB_ETB16)
        *(.data.$RAM4.*)
        *(.data.$RamAHB_ETB16.*)
        . = ALIGN(4) ;
        PROVIDE(__end_data_RAM4 = .) ;
        PROVIDE(__end_data_RamAHB_ETB16 = .) ;
     } > RamAHB_ETB16 AT>MFlashB512

    /* MAIN DATA SECTION */
    .uninit_RESERVED (NOLOAD) : ALIGN(4)
    {
        _start_uninit_RESERVED = .;
        KEEP(*(.bss.$RESERVED*))
       . = ALIGN(4) ;
        _end_uninit_RESERVED = .;
    } > RamLoc40 AT> RamLoc40

    /* Main DATA section (RamLoc40) */
    .data : ALIGN(4)
    {
       FILL(0xff)
       _data = . ;
       PROVIDE(__start_data_RAM = .) ;
       PROVIDE(__start_data_RamLoc40 = .) ;
       *(vtable)
       *(.ramfunc*)
       KEEP(*(CodeQuickAccess))
       KEEP(*(DataQuickAccess))
       *(RamFunction)
       *(.data*)
       . = ALIGN(4) ;
       _edata = . ;
       PROVIDE(__end_data_RAM = .) ;
       PROVIDE(__end_data_RamLoc40 = .) ;
    } > RamLoc40 AT>MFlashB512

    /* BSS section for RamAHB32 */
    .bss_RAM2 : ALIGN(4)
    {
       PROVIDE(__start_bss_RAM2 = .) ;
       PROVIDE(__start_bss_RamAHB32 = .) ;
       *(.bss.$RAM2)
       *(.bss.$RamAHB32)
       *(.bss.$RAM2.*)
       *(.bss.$RamAHB32.*)
       . = ALIGN (. != 0 ? 4 : 1) ; /* avoid empty segment */
       PROVIDE(__end_bss_RAM2 = .) ;
       PROVIDE(__end_bss_RamAHB32 = .) ;
    } > RamAHB32 AT> RamAHB32

    /* BSS section for RamAHB16 */
    .bss_RAM3 : ALIGN(4)
    {
       PROVIDE(__start_bss_RAM3 = .) ;
       PROVIDE(__start_bss_RamAHB16 = .) ;
       *(.bss.$RAM3)
       *(.bss.$RamAHB16)
       *(.bss.$RAM3.*)
       *(.bss.$RamAHB16.*)
       . = ALIGN (. != 0 ? 4 : 1) ; /* avoid empty segment */
       PROVIDE(__end_bss_RAM3 = .) ;
       PROVIDE(__end_bss_RamAHB16 = .) ;
    } > RamAHB16 AT> RamAHB16

    /* BSS section for RamAHB_ETB16 */
    .bss_RAM4 : ALIGN(4)
    {
       PROVIDE(__start_bss_RAM4 = .) ;
       PROVIDE(__start_bss_RamAHB_ETB16 = .) ;
       *(.bss.$RAM4)
       *(.bss.$RamAHB_ETB16)
       *(.bss.$RAM4.*)
       *(.bss.$RamAHB_ETB16.*)
       . = ALIGN (. != 0 ? 4 : 1) ; /* avoid empty segment */
       PROVIDE(__end_bss_RAM4 = .) ;
       PROVIDE(__end_bss_RamAHB_ETB16 = .) ;
    } > RamAHB_ETB16 AT> RamAHB_ETB16

    /* MAIN BSS SECTION */
    .bss : ALIGN(4)
    {
        _bss = .;
        PROVIDE(__start_bss_RAM = .) ;
        PROVIDE(__start_bss_RamLoc40 = .) ;
        *(.bss*)
        *(COMMON)
        . = ALIGN(4) ;
        _ebss = .;
        PROVIDE(__end_bss_RAM = .) ;
        PROVIDE(__end_bss_RamLoc40 = .) ;
        PROVIDE(end = .);
    } > RamLoc40 AT> RamLoc40

    /* NOINIT section for RamAHB32 */
    .noinit_RAM2 (NOLOAD) : ALIGN(4)
    {
       PROVIDE(__start_noinit_RAM2 = .) ;
       PROVIDE(__start_noinit_RamAHB32 = .) ;
       *(.noinit.$RAM2)
       *(.noinit.$RamAHB32)
       *(.noinit.$RAM2.*)
       *(.noinit.$RamAHB32.*)
       . = ALIGN(4) ;
       PROVIDE(__end_noinit_RAM2 = .) ;
       PROVIDE(__end_noinit_RamAHB32 = .) ;
    } > RamAHB32 AT> RamAHB32

    /* NOINIT section for RamAHB16 */
    .noinit_RAM3 (NOLOAD) : ALIGN(4)
    {
       PROVIDE(__start_noinit_RAM3 = .) ;
       PROVIDE(__start_noinit_RamAHB16 = .) ;
       *(.noinit.$RAM3)
       *(.noinit.$RamAHB16)
       *(.noinit.$RAM3.*)
       *(.noinit.$RamAHB16.*)
       . = ALIGN(4) ;
       PROVIDE(__end_noinit_RAM3 = .) ;
       PROVIDE(__end_noinit_RamAHB16 = .) ;
    } > RamAHB16 AT> RamAHB16

    /* NOINIT section for RamAHB_ETB16 */
    .noinit_RAM4 (NOLOAD) : ALIGN(4)
    {
       PROVIDE(__start_noinit_RAM4 = .) ;
       PROVIDE(__start_noinit_RamAHB_ETB16 = .) ;
       *(.noinit.$RAM4)
       *(.noinit.$RamAHB_ETB16)
       *(.noinit.$RAM4.*)
       *(.noinit.$RamAHB_ETB16.*)
       . = ALIGN(4) ;
       PROVIDE(__end_noinit_RAM4 = .) ;
       PROVIDE(__end_noinit_RamAHB_ETB16 = .) ;
    } > RamAHB_ETB16 AT> RamAHB_ETB16

    /* DEFAULT NOINIT SECTION */
    .noinit (NOLOAD): ALIGN(4)
    {
        _noinit = .;
        PROVIDE(__start_noinit_RAM = .) ;
        PROVIDE(__start_noinit_RamLoc40 = .) ;
        *(.noinit*)
         . = ALIGN(4) ;
        _end_noinit = .;
       PROVIDE(__end_noinit_RAM = .) ;
       PROVIDE(__end_noinit_RamLoc40 = .) ;        
    } > RamLoc40 AT> RamLoc40
    PROVIDE(_pvHeapStart = DEFINED(__user_heap_base) ? __user_heap_base : .);
    PROVIDE(_vStackTop = DEFINED(__user_stack_top) ? __user_stack_top : __top_RamLoc40 - 0);

    /* Provide basic symbols giving location and size of main text
     * block, including initial values of RW data sections. Note that
     * these will need extending to give a complete picture with
     * complex images (e.g multiple Flash banks).
     */
    _image_start = LOADADDR(.text);
    _image_end = LOADADDR(.data) + SIZEOF(.data);
    _image_size = _image_end - _image_start;
}