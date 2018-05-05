#include <iostream>
#include <conio.h>

using namespace std;

int m, n, r;
int P[100];

#include "Header.h"

void ChayChuongTrinh();

int main()
{
	ChayChuongTrinh();
	_getch();
}

void ChayChuongTrinh()
{
	cout << "\nNhap so phan thuong m = ";
	cin >> m;
	cout << "\nNhap so phan thuong n = ";
	cin >> n;
	r = 0;
	P[0] = m;
	cout << "\nBang chia phan thuong : \n\n";
	Chia(m, 1);
	cout << "\nCo tat ca la " << r << " cach chia giai thuong";
}