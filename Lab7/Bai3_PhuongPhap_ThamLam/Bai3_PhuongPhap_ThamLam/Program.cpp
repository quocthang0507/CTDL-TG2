#include <iostream>
#include <conio.h>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

#include "Common.h"
#include "Graph.h"

void ChayChuongTrinh();

int main()
{
	ChayChuongTrinh();
	_getch();
	return 0;
}

void ChayChuongTrinh()
{
	Graph g;
	Path tree[MAX];
	OpenGraph(g, "Input.txt");
	DisplayMatrix(g);
	Prim(g, tree);
	PrintPrimMST(g, tree);
}