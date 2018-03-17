void XuatMenu()
{
	cout << "\n============================ HE THONG CHUC NANG ============================";
	cout << "\n0. Thoat khoi chuong trinh";
	cout << "\n1. Xem danh sach";
	cout << "\n2. Tim nut dau tien co du lieu la x";
	cout << "\n3. Tim nut cuoi cung co du lieu la x";
	cout << "\n4. Chen gia tri du lieu x vao dau danh sach";
	cout << "\n5. Chen gia tri du lieu x vao cuoi danh sach";
	cout << "\n6. Huy nut dau";
	cout << "\n7. Huy nut cuoi";
	cout << "\n8. Huy cac nut co du lieu la x";
	cout << "\n9. Huy toan bo danh sach - khoi phuc lai danh sach ban dau";
	cout << "\n10. Tinh so nut cua danh sach";
	cout << "\n11. Tinh so nut cua danh sach co gia tri du lieu bang x";
	cout << "\n12. Tim gia tri nho nhat cua danh sach";
	cout << "\n13. Dem so cac so nguyen to trong danh sach";
	cout << "\n14. Dem xem gia tri lon nhat trong danh sach xuat hien bao nhieu lan";
	cout << "\n15. Tinh tong cac gia tri trong danh sach";
	cout << "\n16. Tinh tong cac gia tri phan biet trong danh sach";
	cout << "\n17. Tinh tong cac gia tri chi xuat hien 1 lan";
	cout << "\n18. Sap danh sach tang dan theo gia tri cua cac nut";
	cout << "\n19. Dao nguoc danh sach l.";
	cout << "\n20. Tach Danh sach l thanh 2 nua truoc sau luu tru vao cac danh sach l1, l2";
	cout << "\n21. Tach luan phien tung nut trong Danh sach l vao 2 danh sach l1, l2.";
	cout << "\n============================================================================";
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

void XuLyMenu(int menu, LIST &l)
{
	int kq;
	Data x;
	LIST l1;
	LIST l2;
	system("cls");
	switch (menu)
	{
	case 0:
		cout << "\n0. Thoat khoi chuong trinh\n";
		break;
	case 1:
		cout << "\n1. Xem danh sach\n";
		cout << "\nDanh sach hien hanh:\n";
		PrintList(l);
		break;
	case 2:
		cout << "\n2. Tim nut dau tien co du lieu la x\n";
		cout << "\nDanh sach hien hanh:\n";
		PrintList(l);
		cout << "\nNhap x = ";
		cin >> x;
		kq = Search_Node_x_First(l, x);
		if (kq == -1)
			cout << "\nKhong co data x = " << x << " o trong danh sach";
		else cout << "\nData x = " << x << " nam dau tien o vi tri thu " << kq << " trong danh sach";
		break;
	case 3:
		cout << "\n3. Tim nut cuoi cung co du lieu la x\n";
		cout << "\nDanh sach hien hanh:\n";
		PrintList(l);
		cout << "\nNhap x = ";
		cin >> x;
		kq = Search_Node_x_End(l, x);
		if (kq == -1)
			cout << "\nKhong co data x = " << x << " o trong danh sach";
		else cout << "\nData x = " << x << " nam cuoi cung o vi tri thu " << kq << " trong danh sach";
		break;
	case 4:
		cout << "\n4. Chen gia tri du lieu x vao dau danh sach\n";
		cout << "\nNhap x can chen : ";
		cin >> x;
		cout << "\nDanh sach ban dau:\n";
		PrintList(l);
		InsertHead(l, x);
		cout << "\nDanh sach sau khi chen:\n";
		PrintList(l);
		break;
	case 5:
		cout << "\n5. Chen gia tri du lieu x vao cuoi danh sach\n";
		cout << "\nNhap x can chen : ";
		cin >> x;
		cout << "\nDanh sach ban dau:\n";
		PrintList(l);
		InsertTail(l, x);
		cout << "\nDanh sach sau khi chen:\n";
		PrintList(l);
		break;
	case 6:
		cout << "\n6. Huy nut dau\n";
		cout << "\nDanh sach ban dau:\n";
		PrintList(l);
		RemoveHead(l);
		cout << "\nDanh sach sau khi xoa:\n";
		PrintList(l);
		break;
	case 7:
		cout << "\n7. Huy nut cuoi\n";
		cout << "\nDanh sach ban dau:\n";
		PrintList(l);
		RemoveTail(l);
		cout << "\nDanh sach sau khi xoa:\n";
		PrintList(l);
		break;
	case 8:
		cout << "\n8. Huy cac nut co du lieu la x\n";
		cout << "\nDanh sach ban dau:\n";
		PrintList(l);
		cout << "\nNhap x = ";
		cin >> x;
		Remove_x(l, x);
		cout << "\nDanh sach sau khi xoa:\n";
		PrintList(l);
		break;
	case 9:
		cout << "\n9. Huy toan bo danh sach - khoi phuc lai danh sach ban dau\n";
		cout << "\nDanh sach ban dau:\n";
		PrintList(l);
		RemoveList(l);
		cout << "\nDanh sach sau khi xoa:\n";
		PrintList(l);
		break;
	case 10:
		cout << "\n10. Tinh so nut cua danh sach\n";
		cout << "\nDanh sach hien hanh:\n";
		PrintList(l);
		cout << "\nSo nut cua danh sach la: " << Count_Node(l);
		break;
	case 11:
		cout << "\n11. Tinh so nut cua danh sach co gia tri du lieu bang x\n";
		cout << "\nDanh sach hien hanh:\n";
		PrintList(l);
		cout << "\nNhap x = ";
		cin >> x;
		cout << "\nSo nut cua danh sach bang voi x la: " << Count_x(l, x);
		break;
	case 12:
		cout << "\n12. Tim gia tri nho nhat cua danh sach\n";
		cout << "\nDanh sach hien hanh:\n";
		PrintList(l);
		cout << "\nGia tri nho nhat cua danh sach la: " << Min_Node(l);
		break;
	case 13:
		cout << "\n13. Dem so cac so nguyen to trong danh sach\n";
		cout << "\nDanh sach hien hanh:\n";
		PrintList(l);
		cout << "\nCo " << Count_Prime(l) << " so nguyen to trong danh sach";
		break;
	case 14:
		cout << "\n14. Dem xem gia tri lon nhat trong danh sach xuat hien bao nhieu lan\n";
		cout << "\nDanh sach hien hanh:\n";
		PrintList(l);
		cout << "\nGia tri lon nhat xuat hien " << Count_Max(l) << " lan";
		break;
	case 15:
		cout << "\n15. Tinh tong cac gia tri trong danh sach\n";
		cout << "\nDanh sach hien hanh:\n";
		PrintList(l);
		cout << "\nTong cua danh sach tren la " << Sum(l);
		break;
	case 16:
		cout << "\n16. Tinh tong cac gia tri phan biet trong danh sach\n";
		cout << "\nDanh sach hien hanh:\n";
		PrintList(l);
		cout << "\nTong cac gia tri phan biet cua danh sach tren la " << Sum_Distinct(l);
		break;
	case 17:
		cout << "\n17. Tinh tong cac gia tri chi xuat hien 1 lan\n";
		cout << "\nDanh sach hien hanh:\n";
		PrintList(l);
		cout << "\nTong cac gia tri chi xuat hien 1 lan cua danh sach tren la " << Sum_Unique(l);
		break;
	case 18:
		cout << "\n18. Sap danh sach tang dan theo gia tri cua cac nut\n";
		cout << "\nDanh sach ban dau:\n";
		PrintList(l);
		Copy(l1, l);
		Sort_Ascending(l1);
		cout << "\nDanh sach sau khi sap xep:\n";
		PrintList(l1);
		break;
	case 19:
		cout << "\n19. Dao nguoc danh sach l.\n";
		cout << "\nDanh sach ban dau:\n";
		PrintList(l);
		Reserve(l1, l);
		cout << "\nDanh sach sau khi dao nguoc:\n";
		PrintList(l1);
		break;
	case 20:
		cout << "\n20. Tach Danh sach l thanh 2 nua truoc sau luu tru vao cac danh sach l1, l2\n";
		cout << "\nDanh sach ban dau:\n";
		PrintList(l);
		Divide(l1, l2, l);
		cout << "\nDanh sach l1:\n";
		PrintList(l1);
		cout << "\nDanh sach l2:\n";
		PrintList(l2);
		break;
	case 21:
		cout << "\n21. Tach luan phien tung nut trong Danh sach l vao 2 danh sach l1, l2.\n";
		cout << "\nDanh sach ban dau:\n";
		PrintList(l);
		Distribute(l1, l2, l);
		cout << "\nDanh sach l1:\n";
		PrintList(l1);
		cout << "\nDanh sach l2:\n";
		PrintList(l2);
		break;
	default:
		break;
	}
	_getch();
}