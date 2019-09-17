#include "Multiboot.hpp"
//Constructor, should parse information from multiboot structure pointer
MultibootData::MultibootData(unsigned int* multibootPtr){
    MemFlags = getBit(multibootPtr[0],0);
    lowerMem =  multibootPtr[1];
    upperMem = multibootPtr[2];
}