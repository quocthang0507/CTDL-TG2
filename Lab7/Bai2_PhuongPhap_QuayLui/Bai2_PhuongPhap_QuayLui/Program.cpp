#include <iostream>
#include <conio.h>

using namespace std;

int m;		//m phần thưởng
int n;		//n học sinh
int r;		//r cách chia
int P[100];	//Mảng p kết quả

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