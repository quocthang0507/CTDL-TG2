#include <iostream>
#include <fstream>
#include <conio.h>

#define MAX 100

using namespace std;

void File_Array(char *filename, int Arr[MAX], int &n);

int main()
{
	int n, Arr[MAX];
	char filename[MAX];
	system("cls");
	cout << "Nhap ten file can mo: ";
	cin >> filename;
	File_Array(filename, Arr, n);
	cout << endl;
	cout << n << endl;
	for (int i = 0; i < n; i++)
		cout << Arr[i] << '\t';
	system("PAUSE");
	return 0;
}

void File_Array(char *filename, int Arr[MAX], int &n)
{
	ifstream in(filename);
	if (!in)
	{
		cout << "\nLoi mo file !";
		exit(1);
	}
	in >> n;
	for (int i = 0; i < n; i++)
	{
		in >> Arr[i];
	}
	in.close();
}