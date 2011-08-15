/*
 * Basic template for the Game Boy Advance 
 * Mode 3 dev
 * lib.h
 */

#ifndef __LIB_H__
#define __LIB_H__

/* This is where we will store GBA critical information, such
 * as memory addresses, definitions and other things.
 */

typedef unsigned short u16;
typedef unsigned int u32;

/* We want to treat the "screen" as an array for shorts.
 * NOTE: Declared as extern since definitions usually do not go in header
 * files, causes multiple definition errors (split up in lib.c)
 */

/* // extern u16 * videoBuffer;
 * Place the line below in lib.c if you chose to use a variable for videobuffer
 * // u16 * videoBuffer = (u16 *) 0x6000000;
 */

#define VIDEOBUFFER         ((u16 *) 0x6000000)
#define REG_DISPCNT         *(u16 *) 0x4000000
#define SCANCOUNTER         *(volatile unsigned short *) 0x4000006
#define MODE_3              3
#define BG2                 (1 << 10)

#define ROWS                160
#define COLS                240
#define COLOR(r, g, b)      (r) | (g) << 5 | (b) << 10
#define OFFSET(row, col)    (col) + (row) * COLS
#define PIXEL(r, c, color)  VIDEOBUFFER[OFFSET(r,c)] = color

/* Function prototypes */
void gbaInitialize(void);
void waitForVBlank(void);
void placePixel(int r, int c, u16 color);

#endif

