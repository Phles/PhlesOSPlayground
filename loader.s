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
.global loader

#Begin Execution here
loader:
    mov  $kernel_stack ,%esp
    push %eax
    push %ebx
    call kernelMain
_stop:
    cli
    hlt
    jmp _stop

#Add 2MiB of space for the C++ stack frame
.space 2*1024*1024 #2MiB
.section .bss

#Stack for C++
kernel_stack:
