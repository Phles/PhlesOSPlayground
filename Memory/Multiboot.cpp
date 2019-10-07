#include "Multiboot.hpp"

//Constructor, should parse information from multiboot structure pointer
MultibootData::MultibootData(unsigned int* multibootPtr){
    //The mulitboot structure is parsed in the following format:
    //The first byte if referenced as a boolean for whether or not the following structures are valid
    //Integers(4 byte sections) are used to store the data in each field. Byte numbers precede each section. 
     
    //4-8, Memory Info
    #if MB_MEMORYREGIONS 
    MemFlags = getBit(multibootPtr[0],0);
    lowerMem =  multibootPtr[1];
    upperMem = multibootPtr[2];
    #endif
    //12, Boot Info
    #if MB_BOOTDEV
    bootFlag = getBit(multibootPtr[0],1);
    bootDevice = multibootPtr[3];
    #endif
    //16, Commandline passed to OS
    #if MB_CMD
    cmdlineFlag = getBit(multibootPtr[0],2);
    cmdline = (char*)(multibootPtr[4]);
    #endif
    //20-24, Boot modules information
    #if MB_BOOTMOD
    modsFlag = getBit(multibootPtr[0],3);
    modsCount = multibootPtr[5];
    modsAddr = (int*)(multibootPtr[6]);
    #endif
    //28-40, store kernel binary symbol information in this step if needed.
    #if MB_KERNELSYM
    isDotOut = getBit(multibootPtr[0],4);
    isELF = getBit(multibootPtr[0],5);
    #endif
    //44-48, BIOS Memory Map Info
    #if MB_BIOSMEMMAP
    biosMapFlag = getBit(multibootPtr[0],6);
    biosMemMapLen = multibootPtr[11];
    biosMemMapAddr = (int*)(multibootPtr[12]);
    #endif
    //52-56, Hard Drive Info
    #if MB_HARDDISK
    HardDiskFlag = getBit(multibootPtr[0],7);
    HardDiskLength = multibootPtr[13];
    HardDiskAddr = (int*)(multibootPtr[14]);
    #endif

    //72-86,VBE Info (VESA BIOS Extensions)
    #if MB_VBE
    vbeFlag = getBit(multibootPtr[0],11);
    vbeControlInfo = (int*)multibootPtr[18];
    #endif
    //88-115, FrameBuffer Info
    #if MB_FRAMEBUF
    frameBufferFlag = getBit(multibootPtr[0],12);
    frameBuffAddr = (int*)multibootPtr[22];
    frameBuffPitch = multibootPtr[24];
    frameBuffWidth = multibootPtr[25];
    frameBuffHeight = multibootPtr[26];
    frameBuffBpp = multibootPtr[27]; 
    frameBuffType = ((char*)(multibootPtr))[109];
    colorInfo = &(((char*)(multibootPtr))[110]);
    #endif
}