void XuatMenu()
{
	cout << "\n=================== HE THONG CHUC NANG ===================";
	cout << "\n0. Thoat khoi chuong trinh";
	cout << "\n1. Tim gia tri lon nhat co trong mang";
	cout << "\n2. Tra ve chi so dau tien cua max";
	cout << "\n3. Tra ve chi so dau tien cua max am";
	cout << "\n4. Tra ve khoang cach lon nhat giua x voi cac phan tu";
	cout << "\n5. Tra ve chi so cua so nguyen to co khoang cach max den 1 phan tu trong a (neu co)";
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
	int kq, x;
	switch (menu)
	{
	case 0:
		cout << "\n0. Thoat khoi chuong trinh\n";
		break;
	case 1:
		cout << "\n1. Tim gia tri lon nhat co trong mang\n";
		XuatMang(a, length);
		cout << "Gia tri lon nhat cua mang la " << Tim_Max(a, length);
		break;
	case 2:
		cout << "\n2. Tra ve chi so dau tien cua max\n";
		XuatMang(a, length);
		cout << "Gia tri lon nhat " << Tim_Max(a, length) << " co chi so dau tien la " << Tim_CS_MAX(a, length);
		break;
	case 3:
		cout << "\n3. Tra ve chi so dau tien cua max am\n";
		XuatMang(a, length);
		kq = Tim_CS_Am_Max(a, length);
		if (kq == -1)
			cout << "Khong co phan tu am o trong mang";
		else cout << "\Gia tri max am co chi so dau tien la " << Tim_CS_Am_Max(a, length);
		break;
	case 4:
		cout << "\n4. Tra ve khoang cach lon nhat giua x voi cac phan tu\n";
		XuatMang(a, length);
		cout << "\nNhap phan tu x = ";
		cin >> x;
		kq = Tim_KC_MAX(a, length, x);
		cout << "\nKhoang cach lon nhat tu x = " << x << " den cac phan tu trong mang la " << kq;
		break;
	case 5:
		cout << "\n5. Tra ve chi so cua so nguyen to co khoang cach max den 1 phan tu trong a (neu co)\n";
		XuatMang(a, length);
		do
		{
			cout << "\nNhap phan tu x = ";
			cin >> x;
		} while (!CoChua_x(a,length,x));
		kq = Tim_CS_KC_NT_MAX(a, length, x);
		cout << "\nSo nguyen to o vi tri thu " << kq << " (a[" << kq << "] = " << a[kq] << ") co khoang cach lon nhat den x = " << x;
		break;
	default:
		break;
	}
	_getch();
}