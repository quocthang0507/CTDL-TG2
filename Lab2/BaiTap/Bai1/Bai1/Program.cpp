#include <iostream>
#include <conio.h>>
#include <fstream>
#include <iomanip>
#include <string.h>

using namespace std;

#include "Header.h"
#include "Menu.h"

void ChayChuongTrinh();

int main()
{
	ChayChuongTrinh();
	return 1;
}

void ChayChuongTrinh()
{
	LIST l;
	if (Read_File("NhanVien.txt", l) == 0)
	{
		cout << "\nLoi khong the mo file";
		_getch();
	}
	else
	{
		int soMenu = 6, menu;
		do
		{
			menu = ChonMenu(soMenu);
			XuLyMenu(menu, l);
		} while (menu > 0);
	}
}