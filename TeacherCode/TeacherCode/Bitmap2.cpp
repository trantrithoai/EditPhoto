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

void Resize(const Bitmap &inbmp, Bitmap &outbmp, double factor)
{
	outbmp.width = factor * inbmp.width;
	outbmp.height = factor * inbmp.height;
	outbmp.rowSize = ((3 * outbmp.width + 3)/4)*4;
	outbmp.pixels = new unsigned char[outbmp.rowSize * outbmp.height];
	for(int row = 0; row < inbmp.height; row++)
		for(int col = 0; col < inbmp.width; col++)
		{
			Color color;
			GetPixel(inbmp, row, col, color);
			SetPixel(outbmp, factor*row, factor*col, color);
			SetPixel(outbmp, factor*row, factor*col + 1, color);
			SetPixel(outbmp, factor*row + 1, factor*col, color);
			SetPixel(outbmp, factor*row + 1, factor*col + 1, color);
		}
}

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

void Swap()
void Symmetry(const Bitmap &bmp)
{
	for (int row = bmp.height - 1; row >= 0; row--)
	{
		for (int col = bmp.width - 1; col >= 0; col--)
		{
			Color color;
			GetPixel(bmp, row, col, color);

		}
	}
}
