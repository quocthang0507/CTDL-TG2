#define MAX 100

typedef int Mang[MAX];

void Nhap_TuDong(Mang a, int &length)
{
	srand((unsigned)time(NULL));
	cout << "\nNhap kich thuoc mang : ";
	cin >> length;
	for (size_t i = 0; i < length; i++)
		//rand() % (b – a + 1) + a.
		//rand() : 0..32768
		a[i] = rand() % 21 - 10;	//[-10..10]
}

void Nhap_BangTay(Mang a, int &length)
{
	cout << "\nNhap kich thuoc mang : ";
	cin >> length;
	for (size_t i = 0; i < length; i++)
	{
		cout << "\na[" << i << "] = ";
		cin >> a[i];
	}
}

void Xuat_Mang(Mang a, int length)
{
	cout << "\nMang hien hanh: ";
	for (size_t i = 0; i < length; i++)
		cout << a[i] << '\t';
	cout << endl;
}

void MinMax(Mang a, int l, int r, int &min, int &max)
{
	int min1, min2, max1, max2;
	if (r - l == 1)
	{
		min = a[l];
		max = a[l];
	}
	else
	{
		MinMax(a, l, (l + r) / 2, min1, max1);
		MinMax(a, (l + r) / 2, r, min2, max2);
		if (min1 < min2)
			min = min1;
		else min = min2;
		if (max1 < max2)
			max = max2;
		else max = max1;
	}
}