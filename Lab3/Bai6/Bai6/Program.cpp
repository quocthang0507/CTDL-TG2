#include <iostream>
#include <fstream>
#include <conio.h>
#include <string.h>
#include <iomanip>

#define MAX 20
#define THOAT 0

using namespace std;

struct Date
{
	int ngay;
	int thang;
	int nam;
};

struct NhanVien
{
	int ms;
	char hoTen[MAX];
	Date ntn;
	char diaChi[MAX];
	double luong;
};

void Xuat(NhanVien ds[MAX], int n);
int Read_Struct(char *filename, NhanVien ds[MAX]);

int main()
{
	char filename[80];
	NhanVien ds[MAX];
	system("cls");
	cout << "Nhap ten file can doc : ";
	cin >> filename;
	int n = Read_Struct(filename, ds);
	Xuat(ds, n);
	system("pause");
	return 0;
}

int Read_Struct(char *filename, NhanVien ds[MAX])
{
	ifstream in(filename);
	if (!in)
	{
		cout << "\nLoi mo file !";
		exit(1);
	}
	int ms;
	char hoTen[MAX];
	char diaChi[MAX];
	double luong;
	int ngay, thang, nam;
	int i = 0;
	in >> ms; ds[i].ms = ms;
	in >> hoTen; strcpy_s(ds[i].hoTen, hoTen);
	in >> ngay; ds[i].ntn.ngay = ngay;
	in >> thang; ds[i].ntn.thang = thang;
	in >> nam; ds[i].ntn.nam = nam;
	in >> diaChi; strcpy_s(ds[i].diaChi, diaChi);
	in >> luong; ds[i].luong = luong;
	while (!in.eof())
	{
		i++;
		in >> ms; ds[i].ms = ms;
		in >> hoTen; strcpy_s(ds[i].hoTen, hoTen);
		in >> ngay; ds[i].ntn.ngay = ngay;
		in >> thang; ds[i].ntn.thang = thang;
		in >> nam; ds[i].ntn.nam = nam;
		in >> diaChi; strcpy_s(ds[i].diaChi, diaChi);
		in >> luong; ds[i].luong = luong;
	}
	in.close();
	return i;
}

void Xuat(NhanVien ds[MAX], int n)
{
	cout << setiosflags(ios::left);
	cout << setw(20) << "MS"
		<< setw(20) << "Ho Ten"
		<< setw(20) << "NTN Sinh"
		<< setw(20) << "Dia chi"
		<< setw(20) << "Luong";
	cout << endl;
	for (int i = 0; i < n; i++)
	{
		cout << setw(20) << ds[i].ms
			<< setw(20) << ds[i].hoTen
			<< setw(2) << ds[i].ntn.ngay << '/'
			<< setw(2) << ds[i].ntn.thang << '/'
			<< setw(16) << ds[i].ntn.nam
			<< setw(20) << ds[i].diaChi
			<< setw(20) << ds[i].luong;
		cout << endl;
	}
}