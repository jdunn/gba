/*
 * Basic template for the Game Boy Advance 
 * Mode 3 dev
 */

#include <stdio.h>
#include "lib.h"

int main(int argc, char * argv[]) {

    /* Initialize GBA memory */
    gbaInitialize();
    
    /* Place a red pixel on the screen */
    //placePixel(20, 20, COLOR(31,0,0));    // function
    PIXEL(20, 20, COLOR(0,31,0));           // macro

    return 0;
}

