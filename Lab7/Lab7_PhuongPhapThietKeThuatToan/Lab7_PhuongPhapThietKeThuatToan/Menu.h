void XuatMenu()
{
	cout << "\n==============================HE THONG CHUC NANG==============================";
	cout << "\n0. Thoat khoi chuong trinh";
	cout << "\n1. Phuong phap chia de tri : Tim min max cua mot day trong pham vi [l..r]";
	cout << "\n2. Phuong phap quay lui : Tim va xuat cach chia phan thuong bang phuong phap vet can";
	cout << "\n3. Phuong phap tham lam : Bai toan du lich";
	cout << "\n4. Phuong phap quy hoach dong : Tim so cach chia phan thuong";
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

void XuLyMenu(int menu)
{
	system("cls");
	int min = 0, max = 0, l, r, length;
	Mang a;
	int tour[MAX];
	int kq, vt;
	char start;
	Graph g;
	switch (menu)
	{
	case 0:
		cout << "\n0. Thoat khoi chuong trinh\n";
		break;
	case 1:
		cout << "\n1. Phuong phap chia de tri : Tim min max cua mot day trong pham vi [l..r]\n";
		cout << "\nNhap kich thuoc mang : ";
		cin >> length;
		Nhap_TuDong(a, length);
		cout << "\nMang duoc nhap tu dong : ";
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
	case 2:
		cout << "\n2. Phuong phap quay lui : Tim va xuat cach chia phan thuong bang phuong phap vet can\n";
		cout << "\nNhap so phan thuong m = ";
		cin >> m;
		cout << "\nNhap so hoc sinh n = ";
		cin >> n;
		::r = 0;
		P[0] = m;
		cout << "\nBang chia phan thuong : \n\n";
		Chia(m, 1);
		cout << "\nCo tat ca la " << ::r << " cach chia phan thuong";
		break;
	case 3:
		cout << "\n3. Phuong phap tham lam : Bai toan du lich\n";
		OpenGraph(g, "Input.txt");
		DisplayMatrix(g);
		do
		{
			cout << "\nNhap ten thanh pho bat dau : ";
			cin >> start;
			vt = FindIndexOfVertex(g, start);
		} while (vt == -1);
		kq = GTS(g, tour, vt);
		cout << "\nQuang duong can di la : ";
		for (size_t i = 1; i <= g.numVertices; i++)
			cout << g.Vertices[tour[i]].label << '\t';
		cout << start;
		cout << "\nChieu dai quang duong la : " << kq;
		break;
	case 4:
		cout << "\n4. Phuong phap quy hoach dong : Tim so cach chia phan thuong\n";
		cout << "\nNhap so phan thuong m = ";
		cin >> m;
		cout << "\nNhap so hoc sinh n = ";
		cin >> n;
		MangKQ c;
		ChiaPhanThuong(c, m, n);
		cout << "\nCo tat ca la " << c[m][n] << " cach chia phan thuong";
		break;
	default:
		break;
	}
	_getch();
}
