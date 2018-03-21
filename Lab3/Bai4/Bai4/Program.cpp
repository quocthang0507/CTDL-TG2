#include <iostream>
#include <fstream>
#include <conio.h>

#define MAX 100

using namespace std;

void File_Mat(char *filename, int a[MAX][MAX], int &n);

int main()
{
	int n, a[MAX][MAX], i, j;
	char filename[80];
	system("cls");
	cout << "Nhap ten file can doc : ";
	cin >> filename;
	File_Mat(filename, a, n);
	cout << "\nN=" << n;
	cout << endl;
	for (i = 0; i < n; i++)
	{
		cout << "\n";
		for (j = 0; j < n; j++)
			cout << a[i][j] << '\t';
	}
	system("pause");
	return 0;
}

void File_Mat(char *filename, int a[MAX][MAX], int &n)
{
	ifstream in(filename);
	if (!in)
	{
		cout << "\nLoi mo file!";
		exit(1);
	}
	in >> n;
	int i, j;
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			in >> a[i][j];
	in.close();
}