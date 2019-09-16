//Implementation class to interface with screen
#include "VideoStream.hpp"
//Constructor
VideoMemoryStream::VideoMemoryStream():VideoMemBegin((unsigned short*)0xb8000),color(0x0A){
    //Set stream pointer to the starting address of Video Memory
    VideoMemPtr = VideoMemBegin;
}
//Print string
VideoMemoryStream& VideoMemoryStream::operator<<(const char *str){
    for(int i = 0; str[i] != '\0'; i++){
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
VideoMemoryStream& VideoMemoryStream::operator<<(unsigned int num){
    int pow = 1;
    //Find the highest power of ten for this number
    for(int tmp = num; tmp > 10;pow*=10)tmp /= 10;
    int digit;
    //Iterate through digits
    do{
        digit = num / pow % 10;
        //Ascii 0-9 offset
        char let = digit + '0';
        *this << let;
        pow /= 10;

    }while(pow > 0);
    return *this;

}
