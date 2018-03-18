#include <iostream>
#include <conio.h>
#include <fstream>
#include <iomanip>
#include <string.h>

using namespace std;

#include "Header.h"

void ChayChuongTrinh();

int main()
{
	ChayChuongTrinh();
	return 1;
}

void ChayChuongTrinh()
{
	LIST l;
	if (Read_File("DiemSo.txt", l) == 0)
		cout << "\nLoi khong the mo file!";
	else
		Print_Result(l);
	_getch();
}