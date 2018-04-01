#include <iostream>
#include <conio.h>
#include <fstream>
#include <string.h>
#include <stack>
#include <queue>

using namespace std;

#include "Common.h"
#include "Graph.h"
#include "Menu.h"

void ChayChuongTrinh();

int main()
{
	ChayChuongTrinh();
}

void ChayChuongTrinh()
{
	Graph g;
	int menu, soMenu = 8;
	do
	{
		menu = ChonMenu(soMenu);
		XuLyMenu(menu, g);
	} while (menu > 0);
}