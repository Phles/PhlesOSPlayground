#include "Memory.hpp"
/*Class to store information about the hardware passed by the bootstrap*/
struct MultibootData{
    bool MemFlags;
    int lowerMem,upperMem;
    //Extract info from the location in Memory
    MultibootData(unsigned int* multibootPtr);
};