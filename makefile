GPPPARAMS = -m32 -fno-use-cxa-atexit -nostdlib -fno-builtin -fno-rtti -fno-exceptions -fno-leading-underscore -g
ASPARAMS = --32
LDPARAMS = -m elf_i386
objects = loader.o kernel.o
%.o: %.cpp
	g++  $(GPPPARAMS) -o $@  -c $<
%.o:  %.s
	as $(ASPARAMS) -o $@ $<

phleskernel.bin: linker.ld $(objects)
	ld  $(LDPARAMS) -T $< -o  $@ $(objects)

install: phleskernel.bin
	sudo cp $< /boot/phleskernel.bin

installAll: phleskernel.bin
	sudo cp $< /boot/phleskernel.bin
	sudo mount /dev/sdb1 ../mount
	sudo cp $< ../mount/boot/phleskernel.bin
	sudo umount ../mount
run: installAll
	 sudo qemu-system-i386 -snapshot /dev/sdb
debug:
	 sudo qemu-system-i386 -snapshot /dev/sdb -s -S

