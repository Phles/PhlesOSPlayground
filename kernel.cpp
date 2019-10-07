//To clarify dependency order and keep a clear linear dependency structure, cpp files are included rather than .hpp files
#include "Video/Video.h"
#include "Memory/Multiboot.hpp"
//OS Kernel main. Extern C is used to avoid name mangling.
extern "C" void kernelMain(unsigned int* multiboot,unsigned int magicNo){
   VideoMemoryStream cout;
    cout.numericBase = 16;
    MultibootData mbData(multiboot);
    ScreenProperties properties(VideoMode::EGA,mbData.frameBuffBpp,mbData.frameBuffPitch,mbData.frameBuffWidth,mbData.frameBuffHeight);
    cout.screenProperties = &properties;
    
    cout << "Your OS has been replaced by a bad C++ program!\r\n";
    cout  << "Getting multiboot info: Flags: " << (int)multiboot[0]<<"\n"; 
    
    cout.color = 0x9;
    //Memory Info
    cout << "Mem Flag"<< mbData.MemFlags;
    cout << "\nLower Mem" << mbData.lowerMem;
    cout << "\nUpper Mem" << mbData.upperMem;
    cout.color = 0x01;
    //Boot info
    cout << "\nBoot Device Found:" << mbData.bootFlag;
    cout << "\nBoot Device " << mbData.bootDevice;
    cout.color = 0xC;
    //BIOS MEM Map
    cout << "\nBIOS MemMap:" <<mbData.biosMapFlag;
    cout <<"\nBIOS MemMap Length:"<<mbData.biosMemMapLen;
    cout <<"\nBIOS MemMap Addr:" << (int)mbData.biosMemMapAddr;
    cout.color = 0xB7;
    //VBE Info
    cout << "\nVBE Enabled "<<mbData.vbeFlag;
    cout<<"\nVBE Control Addr"<<(int)mbData.vbeControlInfo;
    cout <<"\nVBE Control Signature: "<<(char*)mbData.vbeControlInfo;
    cout.color = 0xB;
    //Framebuffer Info
    cout<<"FrameBuf Flag"<<mbData.frameBufferFlag;
    cout << "FrameBuf Addr:"<<(int)mbData.frameBuffAddr;
    cout << "FrameBuf Pitch"<<mbData.frameBuffPitch;
    cout << "FrameBuf Width" << mbData.frameBuffWidth;
    cout << "FrameBuf Height" << mbData.frameBuffHeight;
    cout << "FrameBuf Bpp" << mbData.frameBuffBpp;
    cout << "FrameBuf Type"<<(int)mbData.frameBuffType;
    //Loop forever, preventing unknown behavior.
    //loader.s currently enters a halt loop, which is less cpu intensive but has the same functionality.
    //while(1);
}