void XuatMenu()
{
	cout << "\n===================== HE THONG CHUC NANG =====================";
	cout << "\n0. Thoat khoi chuong trinh";
	cout << "\n1. Doc du lieu tu tap tin";
	cout << "\n2. Them mot dinh co nhan label vao do thi";
	cout << "\n3. Xuat thong tin cua mot dinh trong do thi";
	cout << "\n4. Kiem tra hai dinh u, v co ke nhau (co canh noi giua chung) hay khong?";
	cout << "\n5. Them mot canh co trong so w noi 2 dinh u, v vao do thi";
	cout << "\n6. Luu thong tin do thi xuong file";
	cout << "\n7. Duyet do thi theo chieu rong";
	cout << "\n8. Duyet do thi theo chieu sau";
	cout << "\n==============================================================";
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

void XuLyMenu(int menu)
{
	system("cls");
	switch (menu)
	{
	case 0:
		cout << "\n0. Thoat khoi chuong trinh\n";
		break;
	case 1:
		cout << "\n1. Doc du lieu tu tap tin\n";
		break;
	case 2:
		cout << "\n2. Them mot dinh co nhan label vao do thi\n";
		break;
	case 3:
		cout << "\n3. Xuat thong tin cua mot dinh trong do thi\n";
		break;
	case 4:
		cout << "\n4. Kiem tra hai dinh u, v co ke nhau (co canh noi giua chung) hay khong?\n";
		break;
	case 5:
		cout << "\n5. Them mot canh co trong so w noi 2 dinh u, v vao do thi\n";
		break;
	case 6:
		cout << "\n6. Luu thong tin do thi xuong file\n";
		break;
	case 7:
		cout << "\n7. Duyet do thi theo chieu rong\n";
		break;
	case 8:
		cout << "\n8. Duyet do thi theo chieu sau\n";
		break;
	default:
		break;
	}
	_getch();
}