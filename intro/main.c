/*
 * Basic template for the Game Boy Advance 
 * Mode 3 dev http://www.coranac.com/tonc/text/
 * main.c
 */

#include <stdio.h>
#include "lib.h"
#include "text.h"

int main(int argc, char * argv[]) {
    int r, c, ch;

    /* Initialize GBA memory */
    gbaInitialize();
    
    /* Place a red pixel on the screen */
    //placePixel(20, 20, COLOR(31,0,0));    // function
    //PIXEL(20, 20, COLOR(0,31,0));           // macro

    /* Draw text on the screen */
    //drawString(5, 5, "Hello, World!", COLOR(31,31,31));
    for(r = 0, c = 0, ch = 0; ch < 256; ++ch) {
        if(ch % 25 == 0) {
            r += 9;
            c = 5;
        }
        c += 7;
        drawChar(r, c, ch, COLOR(ch % 32, 31, 31));
    }

    return 0;
}

