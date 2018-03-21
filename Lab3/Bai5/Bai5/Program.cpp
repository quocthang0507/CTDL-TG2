#include <iostream>
#include <fstream>
#include <conio.h>

#define MAX 100

using namespace std;

void Input_Mat(int a[MAX][MAX], int n);
void Mat_File(char *Filename, int a[MAX][MAX], int n);

int main()
{
	int n, a[MAX][MAX];
	char filename[80];
	system("cls");
	cout << "\nNhap so phan tu cua ma tran:";
	cin >> n;
	Input_Mat(a, n);
	cout << "Nhap ten file can ghi : ";
	cin >> filename;
	Mat_File(filename, a, n);
	system("pause");
	return 0;
}

void Input_Mat(int a[MAX][MAX], int n)
{
	int i, j;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			cout << "a[" << i << "][" << j << "]=";
			cin >> a[i][j];
		}
	}
}

void Mat_File(char *filename, int a[MAX][MAX], int n)
{
	ofstream out(filename);
	if (!out)
	{
		cout << "\nLoi mo file !";
		exit(1);
	}
	out << n;
	int i, j;
	for (i = 0; i < n; i++)
	{
		out << endl;
		for (j = 0; j < n; j++)
			out << a[i][j] << "\t";
	}
	out.close();
	cout << "\nLuu file thanh cong!";
}