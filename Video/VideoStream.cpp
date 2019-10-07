//Implementation class to interface with screen
#include "VideoStream.hpp"
//Constructor
VideoMemoryStream::VideoMemoryStream():VideoMemBegin((unsigned short*)0xb8000),color(0x0A),numericBase(10),screenProperties(nullptr){
    //Set stream pointer to the starting address of Video Memory
    VideoMemPtr = VideoMemBegin;
}
//Print string
VideoMemoryStream& VideoMemoryStream::operator<<(const char *str){
        //allow escape sequences.
        bool escapes = screenProperties != nullptr;
        for(int i = 0; str[i] != '\0'; i++){
            if(str[i] == '\n' && screenProperties != nullptr){
                //int offset = (int)VideoMemPtr %((int)VideoMemBegin+screenProperties->frameWidth) == 0;
                //if((int)VideoMemPtr % offset == 0)VideoMemPtr++;
                int offset = 80;
                while((int)VideoMemPtr %offset!= 0)VideoMemPtr++;
                
            }
        //Each short represennts a color and a letter, combine the current color with the current letter
        VideoMemPtr[0] = (VideoMemPtr[0] & (color<<8)) | str[i];
        //Go to the next memory address
        VideoMemPtr++;
        //Loop back around if the end is found
        if(VideoMemPtr == VideoMemEnd)
            VideoMemPtr = VideoMemBegin;
    }
    return *this;
}   
//Print a single character as a strng
VideoMemoryStream& VideoMemoryStream::operator<<(char let){
    VideoMemPtr[0] = (VideoMemPtr[0] & (color << 8)) | let;
    //Go to the next memory address
    VideoMemPtr++;
    //Loop back around if the end is found
    if(VideoMemPtr == VideoMemEnd)
        VideoMemPtr = VideoMemBegin;
    return *this;
}
//Print a numeric value as a string
VideoMemoryStream& VideoMemoryStream::operator<<(int num){
    int pow = 1;
    //Find the highest power of the base for this number
    for(int tmp = num; tmp > numericBase;pow*=numericBase)tmp /= numericBase;
    int digit;
    //Iterate through digits
    do{
        digit = num / pow % numericBase;
        if(digit < 10){
            //Ascii 0-9 offset
            char let = digit + '0';
            *this << let;
        }else{
            //Bases above 10 use A as 10
            char let = 'A'+digit-10;
            *this << let;
        }
        pow /= numericBase;

    }while(pow > 0);
    return *this;

}
