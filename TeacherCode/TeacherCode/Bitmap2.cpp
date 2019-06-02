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
void Blur(const Bitmap &bmp)
{
	for (int i = 0; i < bmp.height; i++)
	{
		for (int j = 0; j < bmp.width; j++)
		{
			/*
				X 0 0
				0 0 0
				0 0 0
			*/
			if (i == 0)
			{
				if (j == 0)
				{
					Color color;
					GetPixel(bmp, i, j, color);

					Color color1;
					GetPixel(bmp, i, j + 1, color1);

					Color color2;
					GetPixel(bmp, i + 1, j + 1, color2);

					Color color3;
					GetPixel(bmp, i + 1, j, color3);

					color.B = (color.B + color1.B + color2.B + color3.B) / 4;
					color.G = (color.G + color1.G + color2.G + color3.G) / 4;
					color.R = (color.R + color1.R + color2.R + color3.R) / 4;

					SetPixel(bmp, i, j, color);
				}
				/*
					0 0 X
					0 0 0
					0 0 0
				*/
				else if (j == bmp.width - 1)
				{
					Color color;
					GetPixel(bmp, i, j, color);

					Color color1;
					GetPixel(bmp, i, j - 1, color1);

					Color color2;
					GetPixel(bmp, i + 1, j, color2);

					Color color3;
					GetPixel(bmp, i + 1, j - 1, color3);

					color.B = (color.B + color1.B + color2.B + color3.B) / 4;
					color.G = (color.G + color1.G + color2.G + color3.G) / 4;
					color.R = (color.R + color1.R + color2.R + color3.R) / 4;

					SetPixel(bmp, i, j, color);
				}
				/*
					0 X 0
					0 0 0
					0 0 0
				*/
				else
				{
					Color color;
					GetPixel(bmp, i, j, color);

					Color color1;
					GetPixel(bmp, i, j - 1, color1);

					Color color2;
					GetPixel(bmp, i, j + 1, color2);

					Color color3;
					GetPixel(bmp, i + 1, j - 1, color3);

					Color color4;
					GetPixel(bmp, i + 1, j, color4);

					Color color5;
					GetPixel(bmp, i + 1, j + 1, color5);

					color.B = (color.B + color1.B + color2.B + color3.B + color4.B + color5.B) / 6;
					color.G = (color.G + color1.G + color2.G + color3.G + color4.G + color5.G) / 6;
					color.R = (color.R + color1.R + color2.R + color3.R + color4.R + color5.R) / 6;

					SetPixel(bmp, i, j, color);
				}
			}
			else if (i > 0 && i < bmp.height - 1)
			{
				/*
					0 0 0
					X 0 0
					0 0 0
				*/
				if (j == 0)
				{
					Color color;
					GetPixel(bmp, i, j, color);

					Color color1;
					GetPixel(bmp, i - 1, j, color1);

					Color color2;
					GetPixel(bmp, i - 1, j + 1, color2);

					Color color3;
					GetPixel(bmp, i, j + 1, color3);

					Color color4;
					GetPixel(bmp, i + 1, j + 1, color4);

					Color color5;
					GetPixel(bmp, i + 1, j, color5);

					color.B = (color.B + color1.B + color2.B + color3.B + color4.B + color5.B) / 6;
					color.G = (color.G + color1.G + color2.G + color3.G + color4.G + color5.G) / 6;
					color.R = (color.R + color1.R + color2.R + color3.R + color4.R + color5.R) / 6;

					SetPixel(bmp, i, j, color);
				}
				/*
				0 0 0
				0 0 X
				0 0 0
				*/
				else if (j == bmp.width - 1)
				{
					Color color;
					GetPixel(bmp, i, j, color);

					Color color1;
					GetPixel(bmp, i - 1, j, color1);

					Color color2;
					GetPixel(bmp, i - 1, j - 1, color2);

					Color color3;
					GetPixel(bmp, i, j - 1, color3);

					Color color4;
					GetPixel(bmp, i + 1, j + 1, color4);

					Color color5;
					GetPixel(bmp, i + 1, j, color5);

					color.B = (color.B + color1.B + color2.B + color3.B + color4.B + color5.B) / 6;
					color.G = (color.G + color1.G + color2.G + color3.G + color4.G + color5.G) / 6;
					color.R = (color.R + color1.R + color2.R + color3.R + color4.R + color5.R) / 6;

					SetPixel(bmp, i, j, color);
				}
				/*
				0 0 0
				0 X 0
				0 0 0
				*/
				else
				{
					Color color;
					GetPixel(bmp, i, j, color);

					Color color1;
					GetPixel(bmp, i - 1, j - 1, color1);

					Color color2;
					GetPixel(bmp, i - 1, j, color2);

					Color color3;
					GetPixel(bmp, i - 1, j + 1, color3);

					Color color4;
					GetPixel(bmp, i, j - 1, color4);

					Color color5;
					GetPixel(bmp, i, j + 1, color5);

					Color color6;
					GetPixel(bmp, i + 1, j - 1, color6);

					Color color7;
					GetPixel(bmp, i + 1, j, color7);

					Color color8;
					GetPixel(bmp, i + 1, j + 1, color8);

					color.B = (color.B + color1.B + color2.B + color3.B + color4.B + color5.B + color6.B + color7.B + color8.B) / 9;
					color.G = (color.G + color1.G + color2.G + color3.G + color4.G + color5.G + color6.G + color7.G + color8.G) / 9;
					color.R = (color.R + color1.R + color2.R + color3.R + color4.R + color5.R + color6.R + color7.R + color8.R) / 9;

					SetPixel(bmp, i, j, color);
				}
			}
			else
			{
				/*
					0 0 0
					0 0 0
					X 0 0
				*/
				if (j == 0)
				{
					Color color;
					GetPixel(bmp, i, j, color);

					Color color1;
					GetPixel(bmp, i - 1, j, color1);

					Color color2;
					GetPixel(bmp, i - 1, j + 1, color2);

					Color color3;
					GetPixel(bmp, i, j + 1, color3);

					color.B = (color.B + color1.B + color2.B + color3.B) / 4;
					color.G = (color.G + color1.G + color2.G + color3.G) / 4;
					color.R = (color.R + color1.R + color2.R + color3.R) / 4;

					SetPixel(bmp, i, j, color);
				}
				/*
					0 0 0
					0 0 0
					0 0 X
				*/
				else if (j == bmp.width - 1)
				{
					Color color;
					GetPixel(bmp, i, j, color);

					Color color1;
					GetPixel(bmp, i - 1, j, color1);

					Color color2;
					GetPixel(bmp, i - 1, j - 1, color2);

					Color color3;
					GetPixel(bmp, i, j - 1, color3);

					color.B = (color.B + color1.B + color2.B + color3.B) / 4;
					color.G = (color.G + color1.G + color2.G + color3.G) / 4;
					color.R = (color.R + color1.R + color2.R + color3.R) / 4;

					SetPixel(bmp, i, j, color);
				}
				/*
					0 0 0
					0 0 0
					0 X 0
				*/
				else
				{
					Color color;
					GetPixel(bmp, i, j, color);

					Color color1;
					GetPixel(bmp, i, j - 1, color1);

					Color color2;
					GetPixel(bmp, i, j + 1, color2);

					Color color3;
					GetPixel(bmp, i - 1, j - 1, color3);

					Color color4;
					GetPixel(bmp, i - 1, j, color4);

					Color color5;
					GetPixel(bmp, i - 1, j + 1, color5);

					color.B = (color.B + color1.B + color2.B + color3.B + color4.B + color5.B) / 6;
					color.G = (color.G + color1.G + color2.G + color3.G + color4.G + color5.G) / 6;
					color.R = (color.R + color1.R + color2.R + color3.R + color4.R + color5.R) / 6;

					SetPixel(bmp, i, j, color);
				}
			}
		}
	}
}
