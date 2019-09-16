Video:
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
#object files to make into a single library  file
sources = Memory.cpp Multiboot.cpp
objects = Memory.o Multiboot.o
%.o: %.cpp
	g++  $(GPPPARAMS) -c $(sources)
#Archive objects into a static lib
../Memory.lib: $(objects)
	ar rvs  $@ $(objects)
#clean this module
clean:
	rm $(objects)