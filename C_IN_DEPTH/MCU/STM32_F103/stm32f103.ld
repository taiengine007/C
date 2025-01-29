/* Linker script for STM32F103 */

ENTRY(_start)

MEMORY
{
    FLASH (rx)      : ORIGIN = 0x08000000, LENGTH = 256K
    RAM (rwx)       : ORIGIN = 0x20000000, LENGTH = 20K
}

SECTIONS
{
    .text :
    {
        . = ALIGN(4);
        _start = .;
        *(.vectors)        /* Vector table */
        *(.text*)          /* Code section */
        *(.rodata*)        /* Read-only data */
        . = ALIGN(4);
    } > FLASH

    .data : 
    {
        . = ALIGN(4);
        *(.data*)          /* Initialized data */
    } > RAM AT> FLASH

    .bss :
    {
        . = ALIGN(4);
        *(.bss*)           /* Uninitialized data */
        *(COMMON)
    } > RAM

    .stack (NOLOAD) :
    {
        . = ALIGN(4);
        . = . + 0x1000;    /* Stack size (4KB) */
    } > RAM
}

