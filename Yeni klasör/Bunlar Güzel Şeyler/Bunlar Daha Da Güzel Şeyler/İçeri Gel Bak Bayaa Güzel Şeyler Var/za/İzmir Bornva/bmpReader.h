#ifndef _H_BMP
#define _H_BMP

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

typedef unsigned char byte;

byte** getBitMap(const char* file);

struct color
{
	byte r,g,b;
};

struct bmpHeader
{
	byte signature[2];
	unsigned int size;
	unsigned short info1;
	unsigned short info2;
	unsigned int offset;
};

struct dibHeader
{
	unsigned int size;
	unsigned int width;
	unsigned int height;
	unsigned short nplanes;
	unsigned short bpp;
	unsigned int comptype;
	unsigned int bmpsize;
	int hres;
	int vres;
	unsigned int noc;
	unsigned int impcol;
};

#endif