//To clarify dependency order and keep a clear linear dependency structure, cpp files are included rather than .hpp files
#include "Video/VideoStream.hpp"
#include "Memory/Multiboot.hpp"
//OS Kernel main. Extern C is used to avoid name mangling.
extern "C" void kernelMain(unsigned int* multiboot,unsigned int magicNo){
   VideoMemoryStream cout;
    cout << "Your OS has been replaced by a bad C++ program!\r\n";
    cout  << "Getting multiboot info: Flags: " << (int)multiboot[0]<<"\n"; 
    cout.numericBase = 16;
    MultibootData mbData(multiboot);
    //Memory Info
    cout << "Mem Flag"<< mbData.MemFlags;
    cout << "\nLower Mem" << mbData.lowerMem;
    cout << "\nUpper Mem" << mbData.upperMem;
    //Boot info
    cout << "Boot Device Found:" << mbData.bootFlag;
    cout << "Boot Device " << mbData.bootDevice;
    //BIOS MEM Map
    cout << " BIOS MemMap:" <<mbData.biosMapFlag;
    cout <<"BIOS MemMap Length:"<<mbData.biosMemMapLen;
    cout <<"BIOS MemMap Addr:" << (int)mbData.biosMemMapAddr;
    //VBE Info
    cout << "VBE Enabled "<<mbData.vbeFlag;
    cout<<"VBE Control Addr"<<(int)mbData.vbeControlInfo;
    cout <<"VBE Control Signature: "<<(char*)mbData.vbeControlInfo;
    //Loop forever, preventing unknown behavior.
    //loader.s currently enters a halt loop, which is less cpu intensive but has the same functionality.
    //while(1);
}