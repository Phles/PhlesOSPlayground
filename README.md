# Welcome to PhlesOSPlayground
PhlesOSPlayground is a makefile project to help programmers who want to get into OS development. While it is **_highly recommended_** that you understand low-level programming and the underlying toolset for this project, the documentation is written to assume that you know nothing because often times people understand one or more components of a feature in this process, but not all. That being said, there is not enough time to explain how every feature in this build system(or OS) works down to the hardware level, so there will be notes about what to look up to learn more about how particular systems interact with each other.

Here's a link to a tutorial video that helped set this project on its way: https://www.youtube.com/watch?v=1rnA6wpF0o4
## Project structure
This project is made to work with GRUB bootloader, which comes installed with the majority of linux distros. 
Lookup _menuentry_ in configuring GRUB(grub.cfg) for more details.
### Overview of Make Commands:
_make install_ : Builds the OS binary(phleskernel.bin) and places it in /boot directory

_make installAll_: Builds the OS binary and places it both in /boot and in the same directory on partition 1 of sdb(/dev/sdb1). It assumes a directory named mount is one folder above the project folder.

_make run_: runs qemu using the /dev/sdb drive

_make debug_: runs qemu using the /dev/sdb drive and waits for a gdb connection at localhost:1234 before booting the emulator

### File Structure
**.**:
    This folder holds the main kernel module and all submodules.

**./Video**:
    The Video module, made to control how content appears on the screen

**./Memory**:
    The Memory module, made to process the inital values stored in memory by the bootloader and allocate or deallocate memory
