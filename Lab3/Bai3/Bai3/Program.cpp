#include <iostream>
#include <fstream>
#include <conio.h>

#define MAX 100

using namespace std;

void File_Array1(char *filename, int arr[MAX], int &n);

int main()
{
	int n, arr[MAX];
	char filename[80];
	system("cls");
	cout << "Nhap ten file can doc: "; cin >> filename;
	File_Array1(filename, arr, n);
	cout << "\nN=" << n;
	cout << endl;
	for (int i = 0; i < n; i++)
		cout << arr[i] << '\t';
	system("pause");
	return 0;
}

void File_Array1(char *filename, int arr[MAX], int &n)
{
	ifstream in(filename);
	if (!in)
	{
		cout << "\nLoi mo file !";
		exit(1);
	}
	n = 0;
	in >> arr[n];
	while (!in.eof())
	{
		n++;
		in >> arr[n];
	}
	n++;
	in.close();
}