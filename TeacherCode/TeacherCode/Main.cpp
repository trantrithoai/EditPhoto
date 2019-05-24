#include <stdio.h>
#include<conio.h>

#include <iostream>
using namespace std;

#include "Bitmap.h"

int main()
{
	const char *inFileName = "MARBLES1.BMP";
	const char *outFileName= "out.bmp";
	Bitmap bmp;
	
	if(LoadBitmap(inFileName, bmp))
	{
		printf(" Original size photo is %d x %d\n\n", bmp.width, bmp.height);
		
		cout << "======================= MENU =======================" << endl;
		cout << "1. Install black and white photos." << endl;
		cout << "2. Adjust image brightness." << endl;
		cout << "3. Enlarge image." << endl;
		cout << "4. Image symmetry." << endl;
		cout << "5. Image overturned." << endl;
		cout << "6. Image invert." << endl;
		cout << "The rest is leaving the program!!!" << endl;
		cout<< "======================= END =======================\n\n" << endl;

		int choice;
		cout << "Please enter your choice: ";
		cin >> choice;

		switch (choice)
		{
		case 1:
		{
			BlackWhite(bmp);
			cout << "Completed!!!" << endl;

			if (SaveBitmap(outFileName, bmp))
			{
			}
			else
				printf("Can not save the bitmap file!!!\n");

			DisposeBitmap(bmp);

			break;
		}
		case 2:
		{
			double factor;
			cout << "How many times do you want to adjust the brightness: ";
			cin >> factor;

			AdjustBrightness(bmp, factor);
			cout << "Completed!!!" << endl;

			if (SaveBitmap(outFileName, bmp))
			{
			}
			else
				printf("Can not save the bitmap file!!!\n");

			DisposeBitmap(bmp);

			break;
		}
		case 3:
		{
			double factor;
			cout << "How many times do you want to resize the image: ";
			cin >> factor; 

			Bitmap bmp1;
		    Resize(bmp, bmp1, factor);
			cout << "Completed!!!" << endl;

			printf("Photo editing size is %d x %d\n\n", bmp1.width, bmp1.height);

			if (SaveBitmap(outFileName, bmp1))
			{
			}
			else
				printf("Can not save the bitmap file!!!\n");

			DisposeBitmap(bmp1);
			DisposeBitmap(bmp);

			break;
		}
		case 4:
		{
			Bitmap bmp1;
			Symmetry(bmp, bmp1);
			cout << "Completed!!!" << endl;

			if (SaveBitmap(outFileName, bmp1))
			{
			}
			else
				printf("Can not save the bitmap file!!!\n");

			DisposeBitmap(bmp);
			DisposeBitmap(bmp1);

			break;
		}
		case 5:
		{
			Bitmap bmp1;
			Overturned(bmp, bmp1);
			cout << "Completed!!!" << endl;

			if (SaveBitmap(outFileName, bmp1))
			{
			}
			else
				printf("Can not save the bitmap file!!!\n");

			DisposeBitmap(bmp);
			DisposeBitmap(bmp1);

			break;
		}
		case 6:
		{
			Invert(bmp);
			cout << "Completed!!!" << endl;

			if (SaveBitmap(outFileName, bmp))
			{
			}
			else
				printf("Can not save the bitmap file!!!\n");

			DisposeBitmap(bmp);

			break;
		}
		default:
			break;
		}

		printf("============== THANK YOU FOR USING THE PROGRAM. BYE!!!==============\n");
	}
	else
		printf("Can not load the bitmap file!!!\n");
	
	system("pause");
	return 0;
}
