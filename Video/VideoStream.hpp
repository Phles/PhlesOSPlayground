//Class to interface with screen
class VideoMemoryStream{
public:
    //Beginning of Video Memory
     unsigned short* const VideoMemBegin;
    //End of Video Memory, null if unknown
    unsigned short* VideoMemEnd = nullptr;
    //Current Video Memory Address
    unsigned short* VideoMemPtr;
    //Base to print numbers, max meant to be 16 but 0-9A-Z supported.
    int numericBase;
    //Video Text Mode Color information
    short color;
    //Constructor
    VideoMemoryStream();
    //Print string
    VideoMemoryStream& operator<<(const char *str);
    //Print a single character
    VideoMemoryStream& operator<<(char let);
    //Print a numeric value as a string
    VideoMemoryStream& operator<<(int num);
};