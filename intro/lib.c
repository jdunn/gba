/*
 * Basic template for the Game Boy Advance 
 * Mode 3 dev
 * lib.c
 */

#include <stdio.h>
#include "lib.h"

void gbaInitialize(void) {
    /* Enables Mode 3 and Background layer 2 for the GBA.
       Should produce a black screen in the emulator
     */
    REG_DISPCNT = MODE_3 | BG2;
 }

/* Information on drawing and blank periods can be found at
 * http://www.coranac.com/tonc/text/video.htm
 * Sections 4.2 & 4.6
 */
void waitForVBlank(void) {
    /* Wait until the next vdraw space is available 
     * Inefficient method until interrupts are used
     */
    while(SCANCOUNTER >= 160); /* wait until vDraw */
    while(SCANCOUNTER < 160);  /* wait until next vBlank */
}

void placePixel(int r, int c, u16 color) {
    VIDEOBUFFER[OFFSET(r,c)] = color;
}

