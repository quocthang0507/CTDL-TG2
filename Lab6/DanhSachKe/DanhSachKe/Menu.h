void XuatMenu()
{
	cout << "\n===================== HE THONG CHUC NANG =====================";
	cout << "\n0. Thoat khoi chuong trinh";
	cout << "\n1. Doc du lieu tu tap tin";
	cout << "\n2. Xuat ma tran ke ra man hinh";
	cout << "\n3. Them mot dinh co nhan label vao do thi";
	cout << "\n4. Xuat thong tin cua mot dinh trong do thi";
	cout << "\n5. Kiem tra hai dinh u, v co ke nhau (co canh noi giua chung) hay khong?";
	cout << "\n6. Them mot canh co trong so w noi 2 dinh u, v vao do thi";
	cout << "\n7. Luu thong tin do thi xuong file";
	cout << "\n8. Duyet do thi theo chieu rong";
	cout << "\n9. Duyet do thi theo chieu sau dung de quy";
	cout << "\n10. Duyet do thi theo chieu sau dung vong lap";
	cout << "\n\n11. Tim cay bao trum toi thieu bang thuat toan Prim";
	cout << "\n12. Tim cay bao trum toi thieu bang thuat toan Kruskal";
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
	//Khai báo các biến phục vụ các chức năng
	int stt;
	LabelType l;
	int p1, p2;
	char u, v;
	VertexPtr V;
	int w;
	char filename[10] = "Text_.txt";
	Path tree1[MAX];
	Edge tree2[MAX];
	//Xử lý chức năng
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
		if (!OpenGraph(g, filename))
			cout << "\nLoi mo file!";
		else cout << "\nThanh cong!";
		break;
	case 2:
		cout << "\n3. Xuat ma tran ke ra man hinh\n";
		cout << "\nMa tran ke: ";
		DisplayMatrix(g);
		break;
	case 3:
		cout << "\n2. Them mot dinh co nhan label vao do thi\n";
		cout << "\nNhap ten dinh can them: ";
		cin >> l;
		cout << "\nMa tran ban dau:";
		DisplayMatrix(g);
		V = CreateVertex(l);
		AddVertex(g, V);
		cout << "\nMa tran moi:";
		DisplayMatrix(g);
		break;
	case 4:
		cout << "\n3. Xuat thong tin cua mot dinh trong do thi\n";
		do
		{
			cout << "\nNhap ten dinh can xem: ";
			cin >> u;
			p1 = FindIndexOfVertex(g, u);
		} while (p1 == -1);
		Xuat1Dinh(g, u);
		break;
	case 5:
		cout << "\n4. Kiem tra hai dinh u, v co ke nhau (co canh noi giua chung) hay khong?\n";
		do
		{
			cout << "\nNhap dinh u : ";
			cin >> u;
			p1 = FindIndexOfVertex(g, u);
		} while (p1 == -1);
		do
		{
			cout << "\nNhap dinh v : ";
			cin >> v;
			p2 = FindIndexOfVertex(g, v);
		} while (p2 == -1);
		if (IsConnected(g, u, v))
			cout << "\nHai dinh " << u << " va " << v << " ke nhau";
		else cout << "\nHai dinh " << u << " va " << v << " khong ke nhau";
		break;
	case 6:
		cout << "\n5. Them mot canh co trong so w noi 2 dinh u, v vao do thi\n";
		do
		{
			cout << "\nNhap dinh u : ";
			cin >> u;
			p1 = FindIndexOfVertex(g, u);
		} while (p1 == -1);
		do
		{
			cout << "\nNhap dinh v : ";
			cin >> v;
			p2 = FindIndexOfVertex(g, v);
		} while (p2 == -1);
		do
		{
			cout << "\nNhap trong so w : ";
			cin >> w;
		} while (w < 1);
		cout << "\nDanh sach ban dau:";
		DisplayMatrix(g);
		AddEdge(g, u, v, w);
		cout << "\nDanh sach moi:";
		DisplayMatrix(g);
		break;
	case 7:
		cout << "\n6. Luu thong tin do thi xuong file\n";
		SaveGraph(g, "Output.txt");
		break;
	case 8:
		cout << "\n7. Duyet do thi theo chieu rong\n";
		do
		{
			cout << "\nNhap ten dinh bat dau : ";
			cin >> u;
			p1 = FindIndexOfVertex(g, u);
		} while (p1 == -1);
		BFS(g, u);
		break;
	case 9:
		cout << "\n9. Duyet do thi theo chieu sau dung de quy\n";
		do
		{
			cout << "\nNhap ten dinh bat dau : ";
			cin >> u;
			p1 = FindIndexOfVertex(g, u);
		} while (p1 == -1);
		ResetFlags(g);
		DFS_Recursion(g, u);
		break;
	case 10:
		cout << "\n10. Duyet do thi theo chieu sau dung vong lap\n";
		do
		{
			cout << "\nNhap ten dinh bat dau : ";
			cin >> u;
			p1 = FindIndexOfVertex(g, u);
		} while (p1 == -1);
		DFS_Loop(g, u);
		break;
	case 11:
		cout << "\n11. Tim cay bao trum toi thieu bang thuat toan Prim\n";
		ResetFlags(g);
		Prim(g, tree1);
		PrintPrimMST(g, tree1);
		break;
	case 12:
		cout << "\n12. Tim cay bao trum toi thieu bang thuat toan Kruskal\n";
		ResetFlags(g);
		Kruskal(g, tree2);
		PrintKruskalMST(g, tree2);
		break;
	default:
		break;
	}
	_getch();
}