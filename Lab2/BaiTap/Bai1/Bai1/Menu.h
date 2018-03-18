void XuatMenu()
{
	cout << "\n============================ HE THONG CHUC NANG ============================";
	cout << "\n0. Thoat khoi chuong trinh";
	cout << "\n1. Xem danh sach nhan vien";
	cout << "\n2. Tinh tong luong ma cong ty tra cho nhan vien";
	cout << "\n3. Tim cac nhan vien co luong cao nhat";
	cout << "\n4. Liet ke danh sach cac nhan vien co nam sinh cho truoc.";
	cout << "\n5. Sap danh sach tang dan theo muc luong";
	cout << "\n6. Sap danh sach tang dan theo ten, ho, chu lot.";
	cout << "\n============================================================================";
}

int ChonMenu(int soMenu)
{
	int stt;
	while (true)
	{
		system("cls");
		XuatMenu();
		cout << "\nChon mot so trong khoang tu [0,.." << soMenu << "] de chon chuc nang, stt = ";
		cin >> stt;
		if (0 <= stt && stt <= soMenu)
			break;
	}
	return stt;
}

void XuLyMenu(int menu, LIST &l)
{
	int namSinh;
	LIST l_copy;
	system("cls");
	switch (menu)
	{
	case 0:
		cout << "\n0. Thoat khoi chuong trinh\n";
		break;
	case 1:
		cout << "\n1. Xem danh sach nhan vien\n";
		cout << "\nDanh sach hien hanh:";
		PrintList(l);
		break;
	case 2:
		cout << "\n2. Tinh tong luong ma cong ty tra cho nhan vien\n";
		cout << "\nDanh sach hien hanh:";
		PrintList(l);
		cout << "\nTong tien luong ma cong ty can tra la: " << Sum_Salary(l);
		break;
	case 3:
		cout << "\n3. Tim cac nhan vien co luong cao nhat\n";
		cout << "\nDanh sach hien hanh:";
		PrintList(l);
		cout << "\nDanh sach theo tien luong cao nhat:";
		Print_List_byHighestSalary(l);
		break;
	case 4:
		cout << "\n4. Liet ke danh sach cac nhan vien co nam sinh cho truoc.\n";
		cout << "\nDanh sach hien hanh:";
		PrintList(l);
		cout << "\nNhap nam sinh : ";
		cin >> namSinh;
		cout << "\nDanh sach theo tien luong cao nhat:";
		Print_List_byYear(l,namSinh);
		break;
	case 5:
		cout << "\n5. Sap danh sach tang dan theo muc luong\n";
		cout << "\nDanh sach ban dau:";
		PrintList(l);
		Copy(l_copy, l);
		Sort_Ascending_bySalary(l_copy);
		cout << "\nDanh sach moi:";
		PrintList(l_copy);
		break;
	case 6:
		cout << "\n6. Sap danh sach tang dan theo ten, ho, chu lot.\n";
		cout << "\nDanh sach ban dau:";
		PrintList(l);
		Copy(l_copy, l);
		Sort_Ascending_byTen_Ho_tenLot(l_copy);
		cout << "\nDanh sach moi:";
		PrintList(l_copy);
		break;
	default:
		break;
	}
	_getch();
}