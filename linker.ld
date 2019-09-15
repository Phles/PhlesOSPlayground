/*Name entry point for OS*/
ENTRY(loader)

/*Output file is a 32-bit ELF binary*/
OUTPUT_FORMAT(elf32-i386)

/*Run on 32-bit Intel Chipset Architecture.*/
OUTPUT_ARCH(i386:i386)

/*Sections found in Object Files. More information about each section can be found by looking up the section in x86 assembly language*/
SECTIONS{

    /*Start assigning the program sections at the memory address below. (Location Counter)*/
    . = 0x100000;
    
    /*Instructions for the CPU to run*/
    .text :
    {
        *(.multiboot)
        *(.text*)
        *(.rodata)
    }
    
    /*Global and Static Variables*/
    .data :
    {
        start_ctors = .;
        KEEP(*(.init_array));
        KEEP(*(SORT_BY_INIT_PRIORITY(.init_array.*)));
        end_ctors = .;
        *(.data)
    }

    /*Unintialized Static data, for a zero-filled buffer. Mainly used by compilers*/
    .bss :
    {
        *(.bss)
    }

    /*Everything else we don't care about can just be thrown away*/
    /DISCARD/ :
    {
        *(.fini_array);
        *(.comment);
    }
}