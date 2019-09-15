#File that prepares the bootloader for the OS.
#Information for GRUB
.set  MAGIC, 0x1badb002
.set FLAGS, (1 << 0 | 1 << 1)
.set CHECKSUM, -(MAGIC+FLAGS)

#Init GRUB vars

.section .multiboot
    .long MAGIC
    .long FLAGS
    .long CHECKSUM

#Execution Information

.section .text
;#C++ function symbol comes from another file
.extern kernelMain
#Main function for assembler
.global loader

#Begin Execution here
loader:
    #C++ needs a kernel stack to be initialized, so do so here.
    mov  $kernel_stack ,%esp
    #Push GRUB arguments to the kernelMain function.
    push %eax
    push %ebx
    call kernelMain
_stop:
    cli #Stop interrupts
    hlt #Halt the system
    jmp _stop #Should the system be unhalted, stop the system again

#Add 2MiB of space for the C++ stack frame
.space 2*1024*1024 #2MiB
.section .bss

#Stack for C++
kernel_stack:
