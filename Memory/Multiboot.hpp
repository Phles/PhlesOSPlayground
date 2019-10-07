#include "Memory.hpp"
/*
 * Class to store information about the hardware passed by the bootstrap
 * See GRUB Multiboot header: https://www.gnu.org/software/grub/manual/multiboot/multiboot.html#Header-layout
 */
/*
 *  The following macros are intended to reduce the size of the multiboot header data structure in order to conserver resources
 *  Each Macro will remove a segment of the multiboot header
 */
#define MB_MEMORYREGIONS 1
#define MB_BOOTDEV 1
#define MB_CMD 0
#define MB_BOOTMOD 0
#define MB_KERNELSYM 0
#define MB_BIOSMEMMAP 1
#define MB_HARDDISK 0

#define MB_VBE 1
#define MB_FRAMEBUF 1
struct MultibootData{
    //Memory Information
    #if MB_MEMORYREGIONS
    bool MemFlags;
    int lowerMem,upperMem;
    #endif
    //Kernel Information. Information about the currently running kernel
    #if MB_BOOTDEV
    bool bootFlag;
    int bootDevice;
    #endif
    #if MB_CMD
    bool cmdlineFlag;
    char* cmdline;
    #endif
    //Boot Modules loaded
   #if MB_BOOTMOD
    bool modsFlag;
    int modsCount, *modsAddr;
    #endif
    //Information about kernel binary, not fully implemented
    #if MB_KERNELSYM
    bool isDotOut,isELF;
    #endif
    //BIOS Memory Map
    #if MB_BIOSMEMMAP
    bool biosMapFlag;
    int biosMemMapLen, *biosMemMapAddr;
    #endif
    //Hard Disk Information, size of Drive Structures
    #if MB_HARDDISK
    bool HardDiskFlag;
    int HardDiskLength, *HardDiskAddr;
    #endif

    //VBE (VESA BIOS Extensions)Info
   #if MB_VBE
    bool vbeFlag;
    int *vbeControlInfo;
    #endif
    #if MB_FRAMEBUF
    bool frameBufferFlag;
    int* frameBuffAddr;
    int frameBuffPitch;
    int frameBuffWidth;
    int frameBuffHeight;
    int frameBuffBpp;
    char frameBuffType;
    char* colorInfo;

    #endif
    //Extract info from the location in Memory
    MultibootData(unsigned int* multibootPtr);
};