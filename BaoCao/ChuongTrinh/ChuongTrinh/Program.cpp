#include <iostream>
#include <conio.h>

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
	int soMenu = 8, menu;
	do
	{
		menu = ChonMenu(soMenu);
		XuLyMenu(menu);
	} while (menu > 0);
}