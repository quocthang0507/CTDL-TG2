void XuatMenu()
{
	cout << "\n========================== HE THONG CHUC NANG ==========================";
	cout << "\n0. Thoat khoi chuong trinh";
	cout << "\n1. Xem danh sach";
	cout << "\n2. Chen mot sinh vien vao dau danh sach";
	cout << "\n3. Chen mot sinh vien vao cuoi danh sach";
	cout << "\n4. Huy nut dau";
	cout << "\n5. Huy nut cuoi";
	cout << "\n6. Huy tat ca cac sinh vien co ten cho truoc";
	cout << "\n7. Xuat cac sinh vien co ten cho truoc";
	cout << "\n8. Xuat cac sinh vien co nam sinh cho truoc";
	cout << "\n9. Tim cac sinh vien co nam sinh nho nhat cua danh sach";
	cout << "\n10. Sap tang danh sach nhan vien theo nam sinh";
	cout << "\n========================================================================";
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
	char maSV[8];
	char ho[10];
	char tenLot[10];
	char ten[10];
	int namSinh;
	Data x;
	system("cls");
	switch (menu)
	{
	case 0:
		cout << "\n0. Thoat khoi chuong trinh\n";
		break;
	case 1:
		cout << "\n1. Xem danh sach\n";
		cout << "\nDanh sach hien hanh:";
		PrintList(l);
		break;
	case 2:
		cout << "\n2. Chen mot sinh vien vao dau danh sach\n";
		cout << "\nNhap ma sinh vien: ";
		cin >> maSV;
		cout << "\nNhap ho: ";
		cin >> ho;
		cout << "\nNhap ten lot : ";
		cin >> tenLot;
		cout << "\nNhap ten : ";
		cin >> ten;
		cout << "\nNhap nam sinh : ";
		cin >> namSinh;
		strcpy_s(x.maSV, maSV);
		strcpy_s(x.ho, ho);
		strcpy_s(x.tenLot, tenLot);
		strcpy_s(x.ten, ten);
		x.namSinh = namSinh;
		cout << "\nDanh sach ban dau:";
		PrintList(l);
		InsertHead(l, x);
		cout << "\nDanh sach moi:";
		PrintList(l);
		break;
	case 3:
		cout << "\n3. Chen mot sinh vien vao cuoi danh sach\n";
		cout << "\nNhap ma sinh vien: ";
		cin >> maSV;
		cout << "\nNhap ho: ";
		cin >> ho;
		cout << "\nNhap ten lot : ";
		cin >> tenLot;
		cout << "\nNhap ten : ";
		cin >> ten;
		cout << "\nNhap nam sinh : ";
		cin >> namSinh;
		strcpy_s(x.maSV, maSV);
		strcpy_s(x.ho, ho);
		strcpy_s(x.tenLot, tenLot);
		strcpy_s(x.ten, ten);
		x.namSinh = namSinh;
		cout << "\nDanh sach ban dau:";
		PrintList(l);
		InsertTail(l, x);
		cout << "\nDanh sach moi:";
		PrintList(l);
		break;
	case 4:
		cout << "\n4. Huy nut dau\n";
		cout << "\nDanh sach ban dau:";
		PrintList(l);
		RemoveHead(l);
		cout << "\nDanh sach moi:";
		PrintList(l);
		break;
	case 5:
		cout << "\n5. Huy nut cuoi\n";
		cout << "\nDanh sach ban dau:";
		PrintList(l);
		RemoveTail(l);
		cout << "\nDanh sach moi:";
		PrintList(l);
		break;
	case 6:
		cout << "\n6. Huy tat ca cac sinh vien co ten cho truoc\n";
		cout << "\nNhap ten : ";
		cin >> ten;
		cout << "\nDanh sach ban dau:";
		PrintList(l);
		Remove_x(l, ten);
		cout << "\nDanh sach moi:";
		PrintList(l);
		break;
	case 7:
		cout << "\n7. Xuat cac sinh vien co ten cho truoc\n";
		cout << "\nDanh sach hien hanh:";
		PrintList(l);
		cout << "\nNhap ten : ";
		cin >> ten;
		cout << "\nDanh sach theo ten:";
		Print_List_byName(l, ten);
		break;
	case 8:
		cout << "\n8. Xuat cac sinh vien co nam sinh cho truoc\n";
		cout << "\nDanh sach hien hanh:";
		PrintList(l);
		cout << "\nNhap nam sinh : ";
		cin >> namSinh;
		cout << "\nDanh sach theo nam sinh:";
		Print_List_byYear(l, namSinh);
		break;
	case 9:
		cout << "\n9. Tim cac sinh vien co nam sinh nho nhat cua danh sach\n";
		cout << "\nDanh sach hien hanh:";
		PrintList(l);
		cout << "\nDanh sach theo nam sinh nho nhat:";
		Print_List_byMinYear(l);
		break;
	case 10:
		cout << "\n10. Sap tang danh sach nhan vien theo nam sinh\n";
		cout << "\nDanh sach ban dau:";
		PrintList(l);
		Sort_Ascending_byYear(l);
		cout << "\nDanh sach moi:";
		PrintList(l);
		break;
	default:
		break;
	}
	_getch();
}