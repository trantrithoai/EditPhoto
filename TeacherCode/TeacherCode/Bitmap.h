#ifndef _BITMAP_
#define _BITMAP_

struct Bitmap
{
	int width;
	int height;
	int rowSize;
	unsigned char *pixels;
};

struct Color
{
	unsigned char R, G, B;
};

int LoadBitmap(const char *fname, Bitmap &bmp);
int SaveBitmap(const char *fname, const Bitmap &bmp);
void DisposeBitmap(Bitmap &bmp);

int SetPixel(const Bitmap &bmp, int row, int col, Color color);
int GetPixel(const Bitmap &bmp, int row, int col, Color &color);

void AdjustBrightness(const Bitmap &bmp, double factor);
void Resize(const Bitmap &inbmp, Bitmap &outbmp, double factor);
void BlackWhite(const Bitmap &bmp);

void Symmetry(const Bitmap &inbmp, Bitmap &outbmp);

void Overturned(const Bitmap &inbmp, Bitmap &outbmp);

void Invert(const Bitmap &bmp);

#endif
