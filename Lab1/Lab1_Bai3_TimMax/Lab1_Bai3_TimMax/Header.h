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
	cout << "Mang hien hanh: \n";
	for (size_t i = 0; i < length; i++)
	{
		cout << a[i] << "\t";
		if ((i + 1) % 10 == 0)
			cout << endl;
	}
	cout << "\n";
}

int Tim_Max(Mang a, int length)
{
	int max = a[0];
	for (size_t i = 1; i < length; i++)
		if (a[i] > max)
			max = a[i];
	return max;
}

//Trả về chỉ số đầu tiên đạt max
int Tim_CS_MAX(Mang a, int length)
{
	int max = a[0], kq;
	for (size_t i = 1; i < length; i++)
	{
		if (a[i] > max)
		{
			max = a[i];
			kq = i;
		}
	}
	return kq;
}

//Kiểm tra x có trong mảng a
bool CoChua_x(Mang a, int length, int x)
{
	for (size_t i = 0; i < length; i++)
		if (a[i] == x)
			return true;
	return false;
}

//Tìm và trả về chỉ số của phần tử âm lớn nhất trong mảng
int Tim_CS_Am_Max(Mang a, int length)
{
	int max = -99999, kq = -1;
	for (size_t i = 0; i < length; i++)
		if (a[i]<0 && a[i]>max)
		{
			max = a[i];
			kq = i;
		}
	return kq;
}

//Khoảng cách lớn nhất giữa số x và các phần tử trong a
int Tim_KC_MAX(Mang a, int length, int x)
{
	int max = abs(x - a[0]);
	for (size_t i = 1; i < length; i++)
		if (abs(x - a[i]) > max)
			max = abs(x - a[i]);
	return max;
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

//Trả về chỉ số của số nguyên tố có khoảng cách lớn nhất đến 1 phần tử trong a
int Tim_CS_KC_NT_MAX(Mang a, int length, int x)
{
	int max = 0, kq;
	for (size_t i = 0; i < length; i++)
	{
		if (KT_NguyenTo(a[i]) && max < abs(a[i] - x))
		{
			max = abs(a[i] - x);
			kq = i;
		}
	}
	return kq;
}