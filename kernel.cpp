//To clarify dependency order and keep a clear linear dependency structure, cpp files are included rather than .hpp files
#include "Video/VideoStream.hpp"
#include "Memory/Multiboot.hpp"
//OS Kernel main. Extern C is used to avoid name mangling.
extern "C" void kernelMain(unsigned int* multiboot,unsigned int magicNo){
   VideoMemoryStream cout;
    cout << "Your OS has been replaced by a bad C++ program!\n";
    cout  << "Getting multiboot info: Flags: " << (int)multiboot[0]<<"\n"; 
    MultibootData mbData(multiboot);
    cout.VideoMemPtr += 10;
    cout << "Mem Flag"<< mbData.MemFlags;
    cout << "\nLower Mem" << mbData.lowerMem;
    cout << "\nUpper Mem" << mbData.upperMem;
    //Loop forever, preventing unknown behavior.
    while(1);
}