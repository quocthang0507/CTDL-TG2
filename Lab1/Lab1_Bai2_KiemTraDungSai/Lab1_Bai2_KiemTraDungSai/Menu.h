void XuatMenu()
{
	cout << "\n=================== HE THONG CHUC NANG ===================";
	cout << "\n0. Thoat khoi chuong trinh";
	cout << "\n1. Kiem tra mang KHONG chua so 0";
	cout << "\n2. Kiem tra mang CO thu tu tang";
	cout << "\n3. Kiem tra mang chua IT NHAT 3 phan tu lien tiep trung nhau";
	cout << "\n4. Kiem tra mang CHI CHUA 2 gia tri";
	cout << "\n5. Kiem tra mang chua cac gia tri tu 0 -> n-1";
	cout << "\n6. Kiem tra neu mang co chua 0 thi co chua 1";
	cout << "\n7. Kiem tra mang a va mang b co la hoan vi cua nhau";
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
	int l = 0;
	system("cls");
	switch (menu)
	{
	case 0:
		cout << "\n0. Thoat khoi chuong trinh\n";
		break;
	case 1:
		cout << "\n1. Kiem tra mang KHONG chua so 0\n";
		XuatMang(a, length);
		if (KT_KhongChua_Khong(a, length))
			cout << "\nMang tren khong co chua phan tu 0";
		else cout << "\nMang tren co chua phan tu 0";
		break;
	case 2:
		cout << "\n2. Kiem tra mang CO thu tu tang\n";
		XuatMang(a, length);
		if (KT_Tang(a, length))
			cout << "\nMang tren co thu tu tang";
		else cout << "\nMang tren khong co thu tu tang";
		break;
	case 3:
		cout << "\n3. Kiem tra mang chua IT NHAT 3 phan tu lien tiep trung nhau\n";
		XuatMang(a, length);
		if (KT_3PhanTu_Trung(a, length))
			cout << "\nMang tren co chua 3 phan tu lien tiep trung nhau";
		else cout << "\nMang tren khong co chua 3 phan tu lien tiep trung nhau";
		break;
	case 4:
		cout << "\n4. Kiem tra mang CHI CHUA 2 gia tri\n";
		XuatMang(a, length);
		if (KT_Co2PhanTu(a, length))
			cout << "\nMang tren chi co chua 2 phan tu";
		else cout << "\nMang tren khong co chua 2 phan tu";
		break;
	case 5:
		cout << "\n5. Kiem tra mang chua cac gia tri tu 0 -> n-1\n";
		XuatMang(a, length);
		if (KT_ChiChua_TrongKhoang(a, length))
			cout << "\nMang tren chi co chua cac phan tu tu 0 den n-1";
		else cout << "\nMang tren khong co chua het cac phan tu tu 0 den n-1";
		break;
	case 6:
		cout << "\n6. Kiem tra neu mang co chua 0 thi co chua 1\n";
		XuatMang(a, length);
		if (KT_Co0_thi_Co1(a, length))
			cout << "\nMang tren co chua 0 va 1";
		else cout << "\nMang tren khong thoa man tinh chat \"Chua 0 thi chua 1\"";
		break;
	case 7:
		cout << "\n7. Kiem tra mang a va mang b co la hoan vi cua nhau\n";
		Mang b;
		Read_File(b, l, "text_b.txt");
		XuatMang(a, length);
		XuatMang(b, length);
		if (KT_HoanVi(a, b, length))
			cout << "\nMang a la hoan vi cua mang b";
		else cout << "\nCa 2 mang khong la hoan vi cua nhau";
		break;
	default:
		break;
	}
	_getch();
}