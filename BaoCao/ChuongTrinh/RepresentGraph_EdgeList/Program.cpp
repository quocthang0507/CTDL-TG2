#include<iostream>
#include<conio.h>
#include<fstream>
#include <iomanip>
#include<queue>
#include<stack>

using namespace std;

#include"Common.h"
#include"Graph.h"
#include"Menu.h";

int main()
{
	int soMenu = 10, menu;
	Graph g;
	do
	{
		menu = ChonMenu(soMenu);
		XuLyMenu(menu, g);
	} while (menu > 0);
	return 1;
}