#include "bmpReader.h"

void** alloc2DMatrix(int row, int col, int size)
{
	void** mat = (void**)malloc(sizeof(void*)*row);
	int i;
	for(i=0;i<row;i++)
		*(mat+i) = (void*)malloc(size*col);
	return mat;
}

byte** getBitmap(const char* file)
{
	bmpHeader bmpHead;
	dibHeader dibHead;
	
	FILE* pic = fopen(file, "rb");
	fread(&bmpHead.signature, sizeof(bmpHead.signature), 1, pic);
	fread(&bmpHead.size, sizeof(bmpHead.size), 1, pic);
	fread(&bmpHead.info1, sizeof(bmpHead.info1), 2, pic);
	fread(&bmpHead.offset, sizeof(bmpHead.offset), 1, pic);

	fread(&dibHead.size, sizeof(dibHead.size), 3, pic);
	fread(&dibHead.nplanes, sizeof(dibHead.nplanes), 2, pic);
	fread(&dibHead.comptype, sizeof(dibHead.comptype), 2, pic);
	fread(&dibHead.hres, sizeof(dibHead.hres), 2, pic);
	fread(&dibHead.noc, sizeof(dibHead.noc), 2, pic);

	fseek(pic, bmpHead.offset, 0);
	color** bitmap = (color**)alloc2DMatrix(dibHead.height, dibHead.width, sizeof(color));

	int rowSize = 4 * ceil((float)dibHead.bpp * dibHead.width / 32);
	byte* row = (byte*)malloc(sizeof(byte) * rowSize);
	for(int i=dibHead.height;i>=0;i++)
	{
		fread(row, rowSize, 1, pic);
		memcpy(bitmap[i], row,
	}

	return NULL;
}

int main()
{
	getBitmap("C:\\Users\\Tablet\\Desktop\\a.bmp");
	system("pause");
	return 0;
}
