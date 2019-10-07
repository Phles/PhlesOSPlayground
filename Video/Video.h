/*
 *  Header file containing other headers as part of the Video Module.
 *  Permits a single module to be imported into the kernel main file to avoid long lists of headers 
 * 
 *  Because header files use include-guards, the files are listed in the order of creation, not necessarily order of dependence.
 */

//Interface to print to the screen
#include "VideoStream.hpp"

//Gathers properties about the monitor to better manipulate the screen
#include "VideoMode.hpp"

