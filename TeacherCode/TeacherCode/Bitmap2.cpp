#define _CRT_SECURE_NO_WARNINGS

#include "Bitmap.h"

// O(1)
int SetPixel(const Bitmap &bmp, int row, int col, Color color)
{
	if(row < 0 || row >= bmp.height
		 || col < 0 || col >= bmp.width)
		return 0;
	
	// color: B, G, R
	int offset = (bmp.height - 1 - row)*bmp.rowSize + col*3;
	bmp.pixels[offset] = color.B;
	bmp.pixels[offset + 1] = color.G;
	bmp.pixels[offset + 2] = color.R;
}

int GetPixel(const Bitmap &bmp, int row, int col, Color &color)
{
	if(row < 0 || row >= bmp.height
		 || col < 0 || col >= bmp.width)
		return 0;
	
	// color: B, G, R
	int offset = (bmp.height - 1 - row)*bmp.rowSize + col*3;
	color.B = bmp.pixels[offset];
	color.G = bmp.pixels[offset + 1];
	color.R = bmp.pixels[offset + 2];
}

//Hàm chỉnh kích thước ảnh.
void Resize(const Bitmap &inbmp, Bitmap &outbmp, double factor)
{
	outbmp.width = factor * inbmp.width;
	outbmp.height = factor * inbmp.height;
	outbmp.rowSize = ((3 * outbmp.width + 3)/4)*4;
	outbmp.pixels = new unsigned char[outbmp.rowSize * outbmp.height];
	for (int row = 0; row < inbmp.height; row++)
	{
		for (int col = 0; col < inbmp.width; col++)
		{
			Color color;
			GetPixel(inbmp, row, col, color);
			SetPixel(outbmp, factor*row, factor*col, color);
			SetPixel(outbmp, factor*row, factor*col + 1, color);
			SetPixel(outbmp, factor*row + 1, factor*col, color);
			SetPixel(outbmp, factor*row + 1, factor*col + 1, color);
		}
	}
}

//Hàm chỉnh độ sáng.
void AdjustBrightness(const Bitmap &bmp, double factor)
{
	for(int row = 0; row < bmp.height; row++)
		for(int col = 0; col < bmp.width; col++)
		{
			Color color;
			GetPixel(bmp, row, col, color);
			
			if(color.R*factor > 255)
				color.R = 255;
			else
				color.R = color.R*factor;
			
			if(color.G*factor > 255)
				color.G = 255;
			else
				color.G = color.G*factor;
			
			if(color.B*factor > 255)
				color.B = 255;
			else
				color.B = color.B*factor;
			
			SetPixel(bmp, row, col, color);
		}
}

//Hàm lấy ảnh trắng đen.
void BlackWhite(const Bitmap &bmp)
{
	for (int row = 0; row < bmp.height; row++)
	{
		for (int col = 0; col < bmp.width; col++)
		{
			Color color;
			GetPixel(bmp, row, col, color);

			int Middle = (color.R + color.G + color.B) / 3;
			color.R = Middle;
			color.G = Middle;
			color.B = Middle;

			SetPixel(bmp, row, col, color);
		}
	}
}

//Hàm lấy ảnh đối xứng.
void Symmetry(const Bitmap &inbmp, Bitmap &outbmp)
{
	outbmp.width = inbmp.width;
	outbmp.height = inbmp.height;
	outbmp.rowSize = ((3 * outbmp.width + 3) / 4) * 4;
	outbmp.pixels = new unsigned char[outbmp.rowSize * outbmp.height];	
	for (int row = 0; row < inbmp.height; row++)
	{
		for (int col = inbmp.width - 1; col >= 0; col--)
		{
			Color color;
			GetPixel(inbmp, row, col, color);
			SetPixel(outbmp, row, inbmp.width - col - 1, color);
		}
	}
}

//Hàm lật ngược ảnh.
void Overturned(const Bitmap &inbmp, Bitmap &outbmp)
{
	outbmp.width = inbmp.width;
	outbmp.height = inbmp.height;
	outbmp.rowSize = ((3 * outbmp.width + 3) / 4) * 4;
	outbmp.pixels = new unsigned char[outbmp.rowSize * outbmp.height];

	for (int col = 0; col < inbmp.width; col++)
	{
		for (int row = inbmp.height - 1; row >= 0; row--)
		{
			Color color;
			GetPixel(inbmp, row, col, color);
			SetPixel(outbmp, inbmp.height - row - 1, col, color);
		}
	}
}

//Hàm xoay trái ảnh.
void TurnRight(const Bitmap &inbmp, Bitmap &outbmp)
{
	outbmp.width = inbmp.height;
	outbmp.height = inbmp.width;
	outbmp.rowSize = ((3 * outbmp.width + 3) / 4) * 4;
	outbmp.pixels = new unsigned char[outbmp.rowSize * outbmp.height];
	for (int row = 0; row < inbmp.height; row++)	
	{
		for (int col = 0; col < inbmp.width; col++)
		{
			Color color;
			GetPixel(inbmp, row, col, color);
			SetPixel(outbmp, col, outbmp.width - 1 - row, color);
		}
	}
}

//Hàm xoay phải ảnh.
void TurnLeft(const Bitmap &inbmp, Bitmap &outbmp)
{
	outbmp.width = inbmp.height;
	outbmp.height = inbmp.width;
	outbmp.rowSize = ((3 * outbmp.width + 3) / 4) * 4;
	outbmp.pixels = new unsigned char[outbmp.rowSize * outbmp.height];
	for (int row = 0; row < inbmp.height; row++)
	{
		for (int col = 0; col < inbmp.width; col++)
		{
			Color color;
			GetPixel(inbmp, row, col, color);
			SetPixel(outbmp, outbmp.height - 1 - col, row, color);
		}
	}
}

//Hàm lấy ảnh âm bản.
void Invert(const Bitmap &bmp)
{
	for (int row = 0; row < bmp.height; row++)
	{
		for (int col = 0; col < bmp.width; col++)
		{
			Color color;
			GetPixel(bmp, row, col, color);

			color.R = 255 - color.R;
			color.G = 255 - color.G;
			color.B = 255 - color.B;

			SetPixel(bmp, row, col, color);
		}
	}
}

//Làm mờ ảnh bitmap.
//void blur(Bitmap &bmp, int radius)
//{
//	float rs = ceil(radius * 1.57);
//	for (int i = 0; i < bmp.height; ++i)
//	{
//		for (int j = 0; j < bmp.width; ++j)
//		{
//			double r = 0, g = 0, b = 0;
//			double count = 0;
//
//			for (int iy = i - rs; iy < i + rs + 1; ++iy)
//			{
//				for (int ix = j - rs; ix < j + rs + 1; ++ix)
//				{
//					auto x = min((bmp.width) - 1, max(0, ix));
//					auto y = min((bmp.height) - 1, max(0, iy));
//
//					auto dsq = ((ix - j) * (ix - j)) + ((iy - i) * (iy - i));
//					auto wght = exp(-dsq / (2.0 * radius * radius)) / (_PI * 2.0 * radius * radius);
//
//					Color color;
//
//					GetPixel(bmp, y, x, color);
//
//					r += color.R * wght;
//					g += color.G * wght;
//					b += color.B * wght;
//					count += wght;
//				}
//			}
//			Color color;
//
//			GetPixel(bmp, i, j, color);
//			color.R = round(r / count);
//			color.G = round(g / count);
//			color.B = round(b / count);
//			SetPixel(bmp, i, j, color);
//
//		}
//	}
//}

