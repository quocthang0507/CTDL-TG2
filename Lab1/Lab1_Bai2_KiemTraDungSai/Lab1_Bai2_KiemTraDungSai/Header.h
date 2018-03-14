typedef int Mang[100];

void Chen_Cuoi(Mang a, int &length, int x)
{
	a[length] = x;
	length++;
}

bool Read_File(Mang a, int &length, char *filename)
{
	ifstream in(filename);
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

//Kiểm tra mảng a không có phần tử 0
bool KT_KhongChua_Khong(Mang a, int length)
{
	for (size_t i = 0; i < length; i++)
	if (a[i] == 0)
		return false;
	return true;
}

//Kiểm tra mảng a là mảng tăng
bool KT_Tang(Mang a, int length)
{
	for (size_t i = 1; i < length; i++)
	if (a[i] < a[i - 1])
		return false;
	return true;
}

//Kiểm tra mảng a có 3 phần tử liền kề trùng nhau
bool KT_3PhanTu_Trung(Mang a, int length)
{
	for (size_t i = 0; i < length - 2; i++)
	if (a[i] == a[i + 1] && a[i + 1] == a[i + 2])
		return true;
	return false;
}

//Kiểm tra mảng a chỉ có chứa 2 phần tử
bool KT_Co2PhanTu(Mang a, int length)
{
	if (length == 2)
		return true;
	return false;
}

//Nếu mảng a chỉ chứa các phần tử từ 0 đến n-1
//Thì chỉ số i = a[i]
bool KT_ChiChua_TrongKhoang(Mang a, int length)
{
	for (size_t i = 0; i < length; i++)
	if (a[i] >= length || a[i] < 0)
		return false;
	return true;
}

//Kiểm tra mảng a nếu có 0 thì có 1
bool KT_Co0_thi_Co1(Mang a, int length)
{
	bool co_A = false, co_B = false;
	for (size_t i = 0; i < length; i++)
	{
		if (a[i] == 0)
			co_A = true;
		else if (a[i] == 1)
			co_B = true;
	}
	return (co_A && co_B);
}

//Kiểm tra mảng a và mảng b có là hoán vị của nhau
bool KT_HoanVi(Mang a, Mang b, int length)
{
	for (size_t i = 0; i < length; i++)
	if (a[i] != b[length - i - 1])
		return false;
	return true;
}