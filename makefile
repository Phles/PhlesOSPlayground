#G++ Flags
## -m32: compile 32bit
## -fno-use-cxa-atexit: disable constructors being called at exit since this is a kernel and has no way of knowing what the destructors are
## -nostdlib: this is a kernel, the standard library is not implemented
## -fno-builtin: no builtin linux system calls available
## -fno-rtti: Runtime type identification does not exist
## -fno-exceptions: C++ exceptions don't exist
## -fno-leading-underscore: Prevent name mangling of kernelMain
## -g: provide gdb debug information. This increases the size of the binary but allows gdb debugging
GPPPARAMS = -m32 -fno-use-cxa-atexit -nostdlib -fno-builtin -fno-rtti -fno-exceptions -fno-leading-underscore -g
#Asm Flags, Compile 32-bit
ASPARAMS = --32
#Linker flags, link into an elf x86 binary
LDPARAMS = -m elf_i386
#Object files to make
objects = loader.o kernel.o
#Static libraries to make
libs = Video.lib Memory.lib
#Make other modules, ensuring they are up to date
.PHONY:
	cd ./Video && $(MAKE) ../Video.lib
	cd ./Memory && $(MAKE) ../Memory.lib
#Other modules that rely on phony
Video.lib: .PHONY
Memory.lib: .PHONY	
#Make objects from .cpp(c++) file
%.o: %.cpp
	g++  $(GPPPARAMS) -o $@  -c $<
#Make objects from .s(assembly) file
%.o:  %.s
	as $(ASPARAMS) -o $@ $<

#The binary that holds the kernel, $< is linker.ld and $@ is phleskernel.bin
phleskernel.bin: linker.ld $(objects) $(libs)
	ld  $(LDPARAMS) -T $< -o  $@ $(objects) $(libs)

#Copy the OS kernel to the boot folder for GRUB on this device
install: phleskernel.bin
	sudo cp $< /boot/phleskernel.bin
#Copy the OS kernel to the boot folder for GRUB on this device and on the first partition of a secondary drive, mounted at a folder one level above this folder
installAll: phleskernel.bin
	sudo cp $< /boot/phleskernel.bin
	sudo mount /dev/sdb1 ../mount
	sudo cp $< ../mount/boot/phleskernel.bin
	sudo umount ../mount

#Run the OS using qemu on the secondary drive
run: installAll
	 sudo qemu-system-i386 -snapshot /dev/sdb
#Run the OS using qemu on the secondary drive but ensure qemu stops execution and waits for a remote gdb debugger
debug:
	 sudo qemu-system-i386 -snapshot /dev/sdb -s -S
#Remove object and bin files, continuing if a file was not found
clean:
	rm $(libs) || true
	rm $(objects) || true
	rm phleskernel.bin || true
	#clean sub modules
	cd ./Video && $(MAKE) clean || true
	cd ./Memory && $(MAKE) clean || true
	