typedef int Mang[100];

void Chen_Cuoi(Mang a, int &length, int x)
{
	a[length] = x;
	length++;
}

bool Read_File(Mang a, int &length)
{
	ifstream in("text.txt");
	if (!in)
		return false;
	int x;
	in >> x;
	Chen_Cuoi(a, length, x);
	while (!in.eof())
	{
		in >> x;
		Chen_Cuoi(a, length, x);
	}
	in.close();
	return true;
}

void XuatMang(Mang a, int length)
{
	cout << "Mang hien hanh: \n\n";
	for (size_t i = 0; i < length; i++)
	{
		cout << a[i] << "\t";
		if ((i + 1) % 10 == 0)
			cout << endl;
	}
	cout << "\n";
}

//Đếm số lượng phần tử mang giá trị âm ở trong mảng
int Dem_Am(Mang a, int length)
{
	int dem = 0;
	for (size_t i = 0; i < length; i++)
		if (a[i] < 0)
			dem++;
	return dem;
}

//Đếm số lượng phần tử mang giá trị dương ở trong mảng
int Dem_Duong(Mang a, int length)
{
	int dem = 0;
	for (size_t i = 0; i < length; i++)
		if (a[i] > 0)
			dem++;
	return dem;
}

//Hàm kiểm tra a có phải là số nguyên tố hay không?
bool KT_NguyenTo(int a)
{
	if (a > 0)
	{
		for (size_t i = 2; i <= sqrt(a); i++)
			if (a%i == 0)
				return false;
		return true;
	}
	return false;
}

//Đếm số lượng phần tử là số nguyên tố ở trong mảng
int Dem_NguyenTo(Mang a, int length)
{
	int dem = 0;
	for (size_t i = 0; i < length; i++)
		if (KT_NguyenTo(a[i]))
			dem++;
	return dem;
}

//Tìm và trả về giá trị lớn nhất trong mảng
int Tim_Max(Mang a, int length)
{
	int max = a[0];
	for (size_t i = 1; i < length; i++)
		if (max < a[i])
			max = a[i];
	return max;
}

int So_DC(int *a, int n)
{
	int Kq;
	if (n == 1)
		Kq = 1;
	else
		if (n > 1)
			if (*(a + n - 1) < *(a + n - 2))
				Kq = So_DC(a, n - 1) + 1;
			else
				Kq = So_DC(a, n - 1);
	return Kq;
}