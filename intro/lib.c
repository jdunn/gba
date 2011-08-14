#include <stdio.h>
#include "lib.h"

void gbaInitialize(void) {
    /* Enables Mode 3 and Background layer 2 for the GBA.
       Should produce a black screen in the emulator
     */
    REG_DISPCNT = MODE_3 | BG2;
 }

void placePixel(int r, int c, u16 color) {
    videoBuffer[OFFSET(r,c)] = color;
}

