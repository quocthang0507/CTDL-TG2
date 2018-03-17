#include <iostream>
#include <conio.h>>
#include <fstream>
#include <math.h>

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
	int soMenu = 21, menu;
	LIST l;
	int kq = Read_File("DaySo.txt", l);
	if (kq == 0)
		cout << "\nLoi mo file";
	do
	{
		menu = ChonMenu(soMenu);
		XuLyMenu(menu, l);
	} while (menu > 0);
}