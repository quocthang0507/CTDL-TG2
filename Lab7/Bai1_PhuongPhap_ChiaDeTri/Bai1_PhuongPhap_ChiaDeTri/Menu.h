void XuatMenu()
{
	cout << "\n==============================HE THONG CHUC NANG==============================";
	cout << "\n0. Thoat khoi chuong trinh";
	cout << "\n1. Nhap tu dong gia tri tu [-10..10] cho mang a";
	cout << "\n2. Nhap bang tay cho mang a";
	cout << "\n3. Tim min max cua mang a trong pham vi [l..r]";
	cout << "\n==============================================================================";
}

int ChonMenu(int soMenu)
{
	int stt;
	while (true)
	{
		system("cls");
		XuatMenu();
		cout << "\nNhap 1 so trong khoang tu [0,..," << soMenu << "] de chon chuc nang, stt = ";
		cin >> stt;
		if (0 <= stt && stt <= soMenu)
			break;
	}
	return stt;
}

void XuLyMenu(int menu, Mang a, int &length)
{
	system("cls");
	int min = 0, max = 0, l, r;
	switch (menu)
	{
	case 0:
		cout << "\n0. Thoat khoi chuong trinh\n";
		break;
	case 1:
		cout << "\n1. Nhap tu dong gia tri tu [-10..10] cho mang a\n";
		Nhap_TuDong(a, length);
		Xuat_Mang(a, length);
		break;
	case 2:
		cout << "\n2. Nhap bang tay cho mang a\n";
		Nhap_BangTay(a, length);
		Xuat_Mang(a, length);
		break;
	case 3:
		cout << "\n3. Tim min max cua mang a trong pham vi [l..r]\n";
		Xuat_Mang(a, length);
		do
		{
			cout << "\nNhap chi so l = ";
			cin >> l;
			cout << "\nNhap chi so r = ";
			cin >> r;
		} while (l > r || l < 0 || r >= length);
		MinMax(a, l, r, min, max);
		cout << "\nMin(a[" << l << ".." << r << "]) = " << min;
		cout << "\nMax(a[" << l << ".." << r << "]) = " << max;
		break;
	default:
		break;
	}
	_getch();
}
