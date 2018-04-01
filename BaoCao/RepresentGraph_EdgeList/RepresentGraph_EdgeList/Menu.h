void XuatMenu()
{
	cout << "\n===================== HE THONG CHUC NANG =====================";
	cout << "\n0. Thoat khoi chuong trinh";
	cout << "\n1. Doc du lieu tu tap tin";
	cout << "\n2. Xuat danh sach canh cua do thi";
	cout << "\n3. Them mot dinh co nhan label vao do thi";
	cout << "\n4. Xuat thong tin cua mot dinh trong do thi";
	cout << "\n5. Kiem tra hai dinh u, v co ke nhau (co canh noi giua chung) hay khong?";
	cout << "\n6. Them mot canh co trong so w noi 2 dinh u, v vao do thi";
	cout << "\n7. Luu thong tin do thi xuong file";
	cout << "\n8. Duyet do thi theo chieu rong";
	cout << "\n9. Duyet do thi theo chieu sau";
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

void XuLyMenu(int menu, Graph &g)
{
	int stt;
	char filename[10] = "Text_.txt";
	LaberType u, v;
	int w;
	system("cls");
	switch (menu)
	{
	case 0:
		cout << "\n0. Thoat khoi chuong trinh\n";
		break;
	case 1:
		cout << "\n1. Doc du lieu tu tap tin\n";
		do
		{
			cout << "\nNhap thu tu cua file can mo (Tu 1 den 6 tuong ung file Text tu A den F) : ";
			cin >> stt;
		} while (stt < 1 || stt > 6);
		filename[4] = 'A' + stt - 1;
		if (OpenFile(filename, g))
			cout << "\nThanh cong!";
		else cout << "\nLoi mo file!";
		break;
	case 2:
		cout << "\n2. Xuat danh sach canh cua do thi\n";
		cout << "\nDanh sach canh: ";
		DisplayEdges(g);
		break;
	case 3:
		cout << "\n3. Them mot dinh co nhan label vao do thi\n";
		do
		{
			cout << endl << "Nhap ten dinh can them: ";
			cin >> u;
		} while (FindIndexVertex(g, u) != -1);
		AddVertex(g, u);
		cout << endl << "Danh sach dinh:";
		DisplayVertices(g);
		break;
	case 4:
		cout << "\n4. Xuat thong tin cua mot dinh trong do thi\n";
		do
		{
			cout << endl << "Nhap dinh can xuat thong tin : ";
			cin >> u;
		} while (FindIndexVertex(g, u) == -1);
		DisplayInfoVertex(g, u);
		break;
	case 5:
		cout << "\n5. Kiem tra hai dinh u, v co ke nhau (co canh noi giua chung) hay khong?\n";
		do
		{
			cout << endl << "Nhap dinh u : ";
			cin >> u;
		} while (FindIndexVertex(g, u) == -1);
		do
		{
			cout << endl << "Nhap dinh v : ";
			cin >> v;
		} while (FindIndexVertex(g, v) == -1);
		DisplayEdges(g);
		if (IsConnected(g, u, v))
			cout << "\nHai dinh ke nhau";
		else cout << "\nHai dinh khong ke nhau";
		break;
	case 6:
		cout << "\n6. Them mot canh co trong so w noi 2 dinh u, v vao do thi\n";
		do
		{
			do
			{
				cout << endl << "Nhap dinh u : ";
				cin >> u;
			} while (FindIndexVertex(g, u) == -1);
			do
			{
				cout << endl << "Nhap dinh v : ";
				cin >> v;
			} while (FindIndexVertex(g, v) == -1);
		} while (IsConnected(g, u, v));
		do
		{
			cout << "\nNhap trong so w : ";
			cin >> w;
		} while (w < 1);
		AddEdge(g, u, v, w);
		DisplayEdges(g);
		break;
	case 7:
		cout << "\n7. Luu thong tin do thi xuong file\n";
		SaveGraph(g, "Output.txt");
		break;
	case 8:
		cout << "\n8. Duyet do thi theo chieu rong\n";
		do
		{
			cout << endl << "Nhap dinh bat dau : ";
			cin >> u;
		} while (FindIndexVertex(g, u) == -1);
		BFS(g, u);
		break;
	case 9:
		cout << "\n9. Duyet do thi theo chieu sau\n";
		do
		{
			cout << endl << "Nhap dinh bat dau : ";
			cin >> u;
		} while (FindIndexVertex(g, u) == -1);
		DFS(g, u);
		break;
	default:
		break;
	}
	_getch();
}