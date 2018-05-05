#include <iostream>
#include <conio.h>

using namespace std;

#include "Header.h"

void ChayChuongTrinh();

int main()
{
	ChayChuongTrinh();
	_getch();
	return 0;
}

void ChayChuongTrinh()
{
	int m, n;
	cout << "\nNhap so phan thuong m = ";
	cin >> m;
	cout << "\nNhap so phan thuong n = ";
	cin >> n;
	MangKQ c;
	ChiaPhanThuong(c, m, n);
	cout << "\nCo tat ca la " << c[m][n] << " cach chia giai thuong";
}