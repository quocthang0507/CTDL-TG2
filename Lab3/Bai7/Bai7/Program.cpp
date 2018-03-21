#include<iostream>
#include<fstream>
#include <iomanip>

using namespace std;

#define MAX 100

struct NhanVien
{
	char maNV[10];
	char hoTen[20];
	int namSinh;
	char diaChi[20];
	double luongCB;
};

void MangCT_TTCT(char *f, NhanVien DS[MAX], int n);
int TTCT_MangCT(char *f, NhanVien TEST[MAX]);
void XuatMang(NhanVien TEST[MAX], int m);

void main()
{
	NhanVien DS[MAX] = {
		{ "123456", "Tran_Tuan", 1960, "Da_Lat", 12500000 },
		{ "103456", "Truong_Tuan_Hoc", 1961, "Sai_Gon", 12500000 },
		{ "123450", "Nguyen_Van_Nam", 1970, "Nha_Trang", 20200000 }
	};
	int n = 3;
	cout << "\nDu lieu mang cau truc DS:\n";
	XuatMang(DS, n);
	system("PAUSE");
	MangCT_TTCT("Bai7test", DS, n);
	NhanVien TEST[MAX];
	int m = TTCT_MangCT("Bai7test", TEST);
	cout << "\nDu lieu mang cau truc TEST:\n";
	XuatMang(TEST, m);
}

void MangCT_TTCT(char *f, NhanVien DS[MAX], int n)
{
	ofstream out(f);
	if (!out)
	{
		cout << "\nLoi mo file !";
		exit(1);
	}
	int i;
	for (i = 0; i < n; i++)
	{
		out << setiosflags(ios::left)
			<< setw(10) << DS[i].maNV
			<< setw(20) << DS[i].hoTen
			<< setw(10) << DS[i].namSinh
			<< setw(20) << DS[i].diaChi
			<< setiosflags(ios::fixed) << setprecision(2)
			<< setw(10) << DS[i].luongCB << '\n';
	}
	out.close();
}

int TTCT_MangCT(char *f, NhanVien TEST[MAX])
{
	ifstream in(f);
	if (!in)
	{
		cout << "\nLoi mo file !";
		exit(1);
	}
	char maNV[10];
	char hoTen[20];
	int namSinh;
	char diaChi[20];
	double LuongCB;
	int i = 0;
	in >> maNV; strcpy_s(TEST[i].maNV, maNV);
	in >> hoTen; strcpy_s(TEST[i].hoTen, hoTen);
	in >> namSinh; TEST[i].namSinh = namSinh;
	in >> diaChi; strcpy_s(TEST[i].diaChi, diaChi);
	in >> LuongCB; TEST[i].luongCB = LuongCB;
	while (!in.eof())
	{
		i++;
		in >> maNV; strcpy_s(TEST[i].maNV, maNV);
		in >> hoTen; strcpy_s(TEST[i].hoTen, hoTen);
		in >> namSinh; TEST[i].namSinh = namSinh;
		in >> diaChi; strcpy_s(TEST[i].diaChi, diaChi);
		in >> LuongCB; TEST[i].luongCB = LuongCB;
	}
	i++;
	in.close();
	return i;
}

void XuatMang(NhanVien TEST[MAX], int m)
{
	int i;
	cout << setiosflags(ios::left)
		<< setw(10) << "MaNV"
		<< setw(20) << "Hoten"
		<< setw(10) << "NS"
		<< setw(20) << "Diachi"
		<< setw(10) << "LuongCB";
	cout << endl;
	for (i = 0; i < m; i++)
	{
		cout << setiosflags(ios::left)
			<< setw(10) << TEST[i].maNV
			<< setw(20) << TEST[i].hoTen
			<< setw(10) << TEST[i].namSinh
			<< setw(20) << TEST[i].diaChi
			<< setiosflags(ios::fixed) << setprecision(2) << setw(10)
			<< TEST[i].luongCB << '\n';
	}
}