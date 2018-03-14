#include <iostream>
#include <conio.h>
#include <fstream>

using namespace std;

#include "Header.h"
#include "Menu.h"

void ChayChuongTrinh();

int main()
{
	ChayChuongTrinh();
	return 0;
}

void ChayChuongTrinh()
{
	int n = 7, menu, length = 0;
	Mang a;
	if (Read_File(a, length, "text_a.txt"))
		XuatMang(a, length);
	else
		cout << "\nLoi! Khong the doc du lieu tu tap tin";
	_getch();
	do
	{
		menu = ChonMenu(n);
		XuLyMenu(menu, a, length);
	} while (menu > 0);
}