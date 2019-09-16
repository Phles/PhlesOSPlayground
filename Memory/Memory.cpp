#include "Memory.hpp"
//General Purpose memory functions
bool getBit(unsigned int num,int bitNo){
    return  ((1 << bitNo) & num) >> bitNo;
}