#include <iostream>
#include <fstream>
#include <conio.h>

using namespace std;

void write_int(int a[], int n, char *filename);

int main()
{
	int n = 9;
	int a[] = { 1,2,3,4,5,6,7,8,9 };
	char filename[80];
	system("cls");
	cout << "Nhap ten file can ghi:"; cin >> filename;
	write_int(a, n, filename);
	system("pause");
	return 0;
}

void write_int(int a[], int n, char *filename)
{
	ofstream out(filename);
	if (!out)
	{
		cout << "\nLoi mo file !";
		exit(1);
	}
	out << n;
	for (int i = 0; i < n; i++)
	{
		out << a[i];
		out << '\t';
	}
	cout << "\nGhi xong du lieu vao tap tin " << filename;
	out.close();
}