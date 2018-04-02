#include <iostream>
#include <conio.h>
#include <fstream>
#include <string.h>
#include <list>
#include <stack>
#include <queue>

using namespace std;

#include "Common.h"
#include "Graph.h"
#include "Connectivity.h"
#include "Menu.h"

void ChayChuongTrinh();

int main()
{
	ChayChuongTrinh();
}

void ChayChuongTrinh()
{
	Graph g;
	int menu, soMenu = 12;
	do
	{
		menu = ChonMenu(soMenu);
		XuLyMenu(menu, g);
	} while (menu > 0);
}