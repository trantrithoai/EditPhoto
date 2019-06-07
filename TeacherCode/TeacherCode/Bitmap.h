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

//Hàm chỉnh độ sáng ảnh.
void AdjustBrightness(const Bitmap &bmp, double factor);

//Hàm chỉnh kích thước ảnh.
void Resize(const Bitmap &inbmp, Bitmap &outbmp, double factor);

//Hàm lấy ảnh trắng đen.
void BlackWhite(const Bitmap &bmp);

//Hàm lấy ảnh đối xứng.
void Symmetry(const Bitmap &inbmp, Bitmap &outbmp);

//Hàm lật ngược ảnh.
void Overturned(const Bitmap &inbmp, Bitmap &outbmp);

//Hàm xoay trái ảnh.
void TurnLeft(const Bitmap &inbmp, Bitmap &outbmp);

//Hàm xoay phải ảnh.
void TurnRight(const Bitmap &inbmp, Bitmap &outbmp);

//Hàm lấy ảnh âm bản.
void Invert(const Bitmap &bmp);

#endif
