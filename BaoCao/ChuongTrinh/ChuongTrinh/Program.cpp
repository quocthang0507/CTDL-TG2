#include <iostream>
#include <conio.h>
#include <fstream>
#include <stack>
#include <queue>

using namespace std;

#include "Common.h"
#include "Graph.h"
#include "Menu.h"

int main()
{
	int soMenu = 8, menu;
	do
	{
		menu = ChonMenu(soMenu);
		XuLyMenu(menu);
	} while (menu > 0);
	return 1;
}