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
	cout << "\n\n9. Tim cay bao trum toi thieu bang thuat toan Prim";
	cout << "\n10. Tim cay bao trum toi thiu bang thuat toan Kruskal";
	//cout << "\n\n11. Tim duong di ngan nhat tu mot dinh toi cac dinh con lai dung thuat toan Dijkstra";
	//cout << "\n12. Tim duong di ngan nhat tu mot dinh toi cac dinh con lai dung thuat toan Floyd";
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
	int w;
	char filename[10] = "Text_.txt";
	Path tree[MAX];
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
		if (OpenGraph(g, filename))
		{
			cout << "\nMa tran ke: ";
			DisplayMatrix(g);
		}
		else cout << "\nLoi mo file!";
		break;
	case 2:
		cout << "\n2. Them mot dinh co nhan label vao do thi\n";
		cout << "\nNhap ten dinh can them: ";
		cin >> l;
		cout << "\nMa tran ban dau:";
		DisplayMatrix(g);
		AddVertex(g, l);
		cout << "\nMa tran moi:";
		DisplayMatrix(g);
		break;
	case 3:
		cout << "\n3. Xuat thong tin cua mot dinh trong do thi\n";
		cout << "\nNhap ten dinh can xem: ";
		cin >> u;
		p1 = FindIndexOfVertex(g, u);
		if (p1 != -1)
			DisplayInfoVertex(g, p1);
		else cout << "\nKhong ton tai dinh co nhan la " << u;
		break;
	case 4:
		cout << "\n4. Kiem tra hai dinh u, v co ke nhau (co canh noi giua chung) hay khong?\n";
		cout << "\nNhap dinh u : ";
		cin >> u;
		cout << "\nNhap dinh v : ";
		cin >> v;
		p1 = FindIndexOfVertex(g, u);
		p2 = FindIndexOfVertex(g, v);
		if (IsConnected(g, p1, p2))
			cout << "\nHai dinh " << u << " va " << v << " ke nhau";
		else cout << "\nHai dinh " << u << " va " << v << " khong ke nhau";
		break;
	case 5:
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
		AddEdge(g, p1, p2, w);
		cout << "\nDanh sach moi:";
		DisplayMatrix(g);
		break;
	case 6:
		cout << "\n6. Luu thong tin do thi xuong file\n";
		SaveGraph(g, "Output.txt");
		break;
	case 7:
		cout << "\n7. Duyet do thi theo chieu rong\n";
		do
		{
			cout << "\nNhap ten dinh bat dau : ";
			cin >> u;
			p1 = FindIndexOfVertex(g, u);
		} while (p1 == -1);
		BFS(g, p1);
		break;
	case 8:
		cout << "\n8. Duyet do thi theo chieu sau\n";
		do
		{
			cout << "\nNhap ten dinh bat dau : ";
			cin >> u;
			p1 = FindIndexOfVertex(g, u);
		} while (p1 == -1);
		DFS_Loop(g, p1);
		/*ResetFlags(g);
		DFS_Recursion(g, p1);*/
		break;
	case 9:
		cout << "\n9. Tim cay bao trum toi thieu bang thuat toan Prim\n";
		Prim(g, tree);
		PrintPrimMST(g, tree);
		break;
	case 10:
		cout << "\n10. Tim cay bao trum toi thieu bang thuat toan Kruskal\n";
		Prim(g, tree);
		PrintPrimMST(g, tree);
		break;
	default:
		break;
	}
	_getch();
}