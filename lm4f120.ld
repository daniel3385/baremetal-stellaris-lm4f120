/**
 * Defined symbols (accessible from code space):
 * _etext:        End of code and read only data.
 * _sdata:        Start of initialized variables and vector table.
 * _edata:        End of initialized variables and vector table.
 * _sbss:         Start of uninitialized variable space.
 * _ebss:         End of uninitialized variable space.
 */

/* To inform GDB where to start */ 
ENTRY(reset_handler)

MEMORY
{
    FLASH (rx)  : ORIGIN = 0x00000000, LENGTH = 256K
    SRAM  (rwx) : ORIGIN = 0x20000000, LENGTH = 32K
}

/**
 * Sections:
 * - .text: For code and read only data. Stored at Flash memory.
 * - .data: Vector table and initialized variables. Stored at the end of the
 * .text section. Copied to SRAM by the startup code.
 * - .bss : For uninitialized variables. Allocated at SRAM.
 */ 
SECTIONS
{
    .text :
    {
        KEEP(*(.isr_vector))
        *(.text*)
        *(.rodata*)
        _etext = .;
    } > FLASH

    .data : 
    {
        _sdata = .;
        *(.data*)
        _edata = .;
    } > SRAM AT > FLASH

    .bss :
    {
        _sbss = .;
        *(.bss*)
        *(COMMON)
        _ebss = .;
    } > SRAM

    STACK_SIZE = 0x2000; /* 8 kB */

    .stack :
    {
        . = ALIGN(8);
        . = . + STACK_SIZE;
        . = ALIGN(8);
    } > SRAM

}
