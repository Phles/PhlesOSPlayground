//To clarify dependency order and keep a clear linear dependency structure, cpp files are included rather than .hpp files
#include "Video/VideoStream.hpp"
#include "Memory/Multiboot.hpp"
//OS Kernel main. Extern C is used to avoid name mangling.
extern "C" void kernelMain(unsigned int* multiboot,unsigned int magicNo){
   VideoMemoryStream cout;
    cout << "Your OS has been replaced by a bad C++ program!";
    cout  << "Getting multiboot info: Flags: " << multiboot[0]; 
    MultibootData mbData(multiboot);
    cout << "Mem Flag"<< (unsigned int)mbData.MemFlags;
    //Loop forever, preventing unknown behavior.
    while(1);
}