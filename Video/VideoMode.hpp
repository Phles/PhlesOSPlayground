//Information about VideoModes
#ifndef VIDEOMODE
#define VIDEOMODE
//Class for the video mode of the monitor
enum class VideoMode{
    EGA, //Enhanced Grahpics Adapter Standard Text Mode(console color mode with ASCII text)
    RGB, //Direct Red Green Blue Color mode
    Palette //Color mode using a color palette
};

struct ScreenProperties{
    //Monitor Video Mode
    VideoMode mode;
    
    int frameDepth; //aka bpp, Number of bits in a single pixel, or in EGA  mode 16(bits per character)
    //Width and Height in pixels(or characters in EGA mode)
    int frameWidth, frameHeight;
    //Bytes per row on the screen
    int framePitch;
    ScreenProperties();
    ScreenProperties(VideoMode vMode,int depth, int pitch, int width, int height);

};
#endif