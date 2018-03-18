#include <iostream>
#include <conio.h>
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
	int soMenu = 10, menu;
	LIST l;
	if (Read_File("SinhVien.txt", l) == 0)
		cout << "\nLoi khong the mo file!";
	do
	{
		menu = ChonMenu(soMenu);
		XuLyMenu(menu, l);
	} while (menu > 0);
}