//Class to interface with screen
class VideoMemoryStream{
public:
    //Beginning of Video Memory
     unsigned short* const VideoMemBegin = (unsigned short*)0xb8000;
    //End of Video Memory, null if unknown
    unsigned short* VideoMemEnd = nullptr;
    //Current Video Memory Address
    unsigned short* VideoMemPtr;
    //Video Text Mode Color information
    short color;
    //Constructor
    VideoMemoryStream(){
        VideoMemPtr = VideoMemBegin;
        color = 0x0A;
    }
    //Print string
    void operator<<(const char *str){
        for(int i = 0; str[i] != '\0'; i++){
            VideoMemPtr[0] = (VideoMemPtr[0] & (color<<8)) | str[i];
            VideoMemPtr++;
            if(VideoMemPtr == VideoMemEnd)
                VideoMemPtr = VideoMemBegin;
        }
    }
};
//OS Kernel main
extern "C" void kernelMain(void* multiboot,unsigned int magicNo){
   VideoMemoryStream cout;
    cout << "Your OS has been replaced by a bad C++ program! ";
    cout << "Getting multiboot info";
    //Loop forever, preventing unknown behavior.
    while(1);
}