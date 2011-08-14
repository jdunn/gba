#include <stdio.h>
#include "lib.h"

u16 * videoBuffer = (u16 *) 0x6000000;

void gbaInitialize(void) {
    /* Enables Mode 3 and Background layer 2 for the GBA.
       Should produce a black screen in the emulator
     */
    REG_DISPCNT = MODE_3 | BG2;
 }

