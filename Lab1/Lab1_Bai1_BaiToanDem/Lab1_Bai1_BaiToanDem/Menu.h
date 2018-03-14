void XuatMenu()
{
	cout << "\n=================== HE THONG CHUC NANG ===================";
	cout << "\n0. Thoat khoi chuong trinh";
	cout << "\n1. Dem so phan tu co trong mang";
	cout << "\n2. Dem so phan tu am co trong mang";
	cout << "\n3. Dem so phan tu duong co trong mang";
	cout << "\n4. Dem so phan tu la so nguyen to co trong mang";
	cout << "\n5. Dem so duong chay trong mang";
	cout << "\n==========================================================";
}

int ChonMenu(int soMenu)
{
	int stt;
	while (true)
	{
		system("cls");
		XuatMenu();
		cout << "\nNhap so trong khoang tu [0,..," << soMenu << "] de chon chuc nang, stt = ";
		cin >> stt;
		if (0 <= stt&&stt <= soMenu)
			break;
	}
	return stt;
}

void XuLyMenu(int menu, Mang a, int &length)
{
	system("cls");
	switch (menu)
	{
	case 0:
		cout << "\n0. Thoat khoi chuong trinh\n";
		break;
	case 1:
		cout << "\n1. Dem so phan tu co trong mang\n";
		XuatMang(a, length);
		cout << "\nMang co " << length << " phan tu";
		break;
	case 2:
		cout << "\n2. Dem so phan tu am co trong mang\n";
		XuatMang(a, length);
		cout << "\nMang co " << Dem_Am(a, length) << " phan tu am";
		break;
	case 3:
		cout << "\n3. Dem so phan tu duong co trong mang\n";
		XuatMang(a, length);
		cout << "\nMang co " << Dem_Duong(a, length) << " phan tu duong";
		break;
	case 4:
		cout << "\n4. Dem so phan tu la so nguyen to co trong mang\n";
		XuatMang(a, length);
		cout << "\nMang co " << Dem_NguyenTo(a, length) << " phan tu la so nguyen to";
		break;
	case 5:
		cout << "\n5. Dem so duong chay trong mang\n";
		XuatMang(a, length);
		cout << "\nMang co " << So_DC(a, length) << " duong chay";
		break;
	default:
		break;
	}
	_getch();
}