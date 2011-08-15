/*
 * Basic template for the Game Boy Advance 
 * Mode 3 dev
 * text.h
 */

#ifndef __TEXT_H__
#define __TEXT_H__

extern const unsigned char fontdata_6x8[12288];

void drawChar(int row, int col, char ch, u16 color);
void drawString(int row, int col, char * str, u16 color);

#endif

