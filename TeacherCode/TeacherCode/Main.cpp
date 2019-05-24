#include <stdio.h>
#include<conio.h>

#include <iostream>
using namespace std;

#include "Bitmap.h"

int main()
{
	const char *inFileName = "141.BMP";
	const char *outFileName = "out.bmp";
	Bitmap bmp;

	if (LoadBitmap(inFileName, bmp))
	{
		do
		{
			system("cls");

			printf(" Original size photo is %d x %d\n\n", bmp.width, bmp.height);

			cout << "======================= MENU =======================" << endl;
			cout << "1. Install black and white photos." << endl;
			cout << "2. Adjust image brightness." << endl;
			cout << "3. Resize image." << endl;
			cout << "4. Image symmetry." << endl;
			cout << "5. Image overturned." << endl;
			cout << "6. Image invert." << endl;
			cout << "7. Rotate left image." << endl;
			cout << "8. Rotate right image." << endl;
			cout << "9. Reset image." << endl;
			cout << "The rest is leaving the program!!!" << endl;
			cout << "======================= END =======================\n\n" << endl;

			int choice;
			cout << "Please enter your choice: ";
			cin >> choice;

			if (choice == 1)
			{
				BlackWhite(bmp);
				cout << "Completed!!!" << endl;

				if (SaveBitmap(outFileName, bmp))
				{
				}
				else
					printf("Can not save the bitmap file!!!\n");

				DisposeBitmap(bmp);
			}
			else if (choice == 2)
			{
				double factor;
				do
				{
					cout << "How many times do you want to adjust the brightness: ";
					cin >> factor;
					
					if (factor <= 0)
					{
						cout << "Error. Please re-enter!!!" << endl;
					}
				} while (factor <= 0);

				AdjustBrightness(bmp, factor);
				cout << "Completed!!!" << endl;

				if (SaveBitmap(outFileName, bmp))
				{
				}
				else
					printf("Can not save the bitmap file!!!\n");

				DisposeBitmap(bmp);
			}
			else if (choice == 3)
			{
				double factor;
				do
				{
					cout << "How many times do you want to resize the image: ";
					cin >> factor;

					if (factor <= 0)
					{
						cout << "Error. Please re-enter!!!" << endl;
					}
				} while (factor <= 0);

				Bitmap bmp1;
				Resize(bmp, bmp1, factor);
				cout << "Completed!!!" << endl;

				printf("Photo editing size is %d x %d\n", bmp1.width, bmp1.height);

				if (SaveBitmap(outFileName, bmp1))
				{
				}
				else
					printf("Can not save the bitmap file!!!\n");

				DisposeBitmap(bmp1);
				DisposeBitmap(bmp);
			}
			else if (choice == 4)
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
			}
			else if (choice == 5)
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
			}
			else if (choice == 6)
			{
				Invert(bmp);
				cout << "Completed!!!" << endl;

				if (SaveBitmap(outFileName, bmp))
				{
				}
				else
					printf("Can not save the bitmap file!!!\n");

				DisposeBitmap(bmp);
			}
			else if (choice == 7)
			{
				Bitmap bmp1;
				TurnLeft(bmp, bmp1);
				printf("Photo editing size is %d x %d\n", bmp1.width, bmp1.height);
				cout << "Completed!!!" << endl;

				if (SaveBitmap(outFileName, bmp1))
				{
				}
				else
					printf("Can not save the bitmap file!!!\n");

				DisposeBitmap(bmp);
				DisposeBitmap(bmp1);
			}
			else if (choice == 8)
			{
				Bitmap bmp1;
				TurnRight(bmp, bmp1);
				printf("Photo editing size is %d x %d\n", bmp1.width, bmp1.height);
				cout << "Completed!!!" << endl;

				if (SaveBitmap(outFileName, bmp1))
				{
				}
				else
					printf("Can not save the bitmap file!!!\n");

				DisposeBitmap(bmp);
				DisposeBitmap(bmp1);
			}
			else if (choice == 9)
			{
			    LoadBitmap(inFileName, bmp);
				cout << "Completed!!!" << endl;

				if (SaveBitmap(outFileName, bmp))
				{
				}
				else
					printf("Can not save the bitmap file!!!\n");

				DisposeBitmap(bmp);

				system("pause");
				continue;
			}
			else
			{
				cout << "============== THANK YOU FOR USING THE PROGRAM. BYE!!! ==============" << endl;
				system("pause");
				break;
			}
			system("pause");
		} while (LoadBitmap(outFileName, bmp));
	}
	else
	{
		printf("Can not load the bitmap file!!!\n");
	}
	return 0;
}
