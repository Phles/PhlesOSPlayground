#include "VideoMode.hpp"
//Assume screen is in basic text mode, note that this method is inaccurate as nothing can be said about the monitior
ScreenProperties::ScreenProperties(){
    mode = VideoMode::EGA;
    frameDepth = 16;
}
//Manually set screen properties
ScreenProperties::ScreenProperties(VideoMode vMode, int depth, int pitch, int width, int height):frameDepth(depth),framePitch(pitch),frameWidth(width),frameHeight(height) {
    mode = vMode;
}