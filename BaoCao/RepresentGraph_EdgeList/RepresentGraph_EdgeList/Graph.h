//Tạo và trả về đỉnh có nhãn là lab
Vertex CreateVertex(LaberType lab)
{
	Vertex v;
	v.Label = lab;
	v.Visited = NO;
	return v;
}

//Tạo 1 cạnh từ 2 đỉnh và trả về data của cạnh đó
Data CreateEdge(char start, char end, int w)
{
	Data x;
	x.Source = start;
	x.Target = end;
	x.Weight = w;
	x.Marked = NO;
	return x;
}

//Chuyển một cạnh thành một nút trong danh sách
Edge* GetEdge(Data v)
{
	Edge* kq = new Edge;
	if (kq != NULL)
	{
		kq->info = v;
		kq->Next = NULL;
	}
	return kq;
}

//Khởi tạo đồ thị
Graph InitGraph(bool directed)
{
	Graph g;
	g.NumEdges = 0;
	g.NumVertices = 0;
	g.Directed = directed;
	g.ListEdges = NULL;
	return g;
}

//Trả về vị trí của một đỉnh trong danh sách đỉnh
int FindIndexVertex(Graph g, char v)
{
	for (int i = 0; i < g.NumVertices; i++)
		if (g.Vertices[i].Label == v)
			return i;
	return -1;
}

//Thêm một đỉnh vào danh sách đỉnh
void AddVertex(Graph &g, LaberType lab)
{
	if (FindIndexVertex(g, lab) == -1)					//Nếu chưa có đỉnh lab trong đồ thị
	{
		g.Vertices[g.NumVertices] = CreateVertex(lab);	//Thêm đỉnh vào đồ thị
		g.NumVertices++;								//Tăng số lượng đỉnh 
	}
}

//Hiển thị tên đỉnh dựa vào vị trí pos
void DisplayVertex(Graph g, int pos)
{
	cout << '\t' << g.Vertices[pos].Label;
}

//Hiển thị danh sách đỉnh
void DisplayVertices(Graph g)
{
	for (size_t i = 0; i < g.NumVertices; i++)
		DisplayVertex(g, i);
}

//Tìm và trả về trọng số của 2 cạnh
int FindEdge(Graph g, char start, char end)
{
	Edge *e = g.ListEdges;
	while (e != NULL)
	{
		if (e->info.Source == start && e->info.Target == end)
			return e->info.Weight;
		e = e->Next;
	}
	return NULLDATA;
}

//Kiểm tra có 2 đỉnh kề nhau không?
int IsConnected(Graph g, char u, char v)
{
	return (FindEdge(g, u, v) != NULLDATA);
}

//Xuất tiêu đề
void DisplayTitle()
{
	cout << endl;
	for (size_t i = 0; i < 34; i++)
		cout << '=';
	cout << endl
		<< '|'
		<< setw(10) << "Dinh dau"
		<< '|'
		<< setw(10) << "Dinh cuoi"
		<< '|'
		<< setw(10) << "Trong so"
		<< '|';
	cout << endl;
	for (size_t i = 0; i < 34; i++)
		cout << '=';
}

//Hiển thị thông tin của một cạnh có data là e
void Display1Edge(Data e)
{
	cout << endl
		<< '|'
		<< setw(10) << e.Source
		<< '|'
		<< setw(10) << e.Target
		<< '|'
		<< setw(10) << e.Weight
		<< '|';
}

//Hiển thị thông tin 1 đỉnh
void DisplayInfoVertex(Graph g, char d)
{
	Edge *e = g.ListEdges;
	DisplayTitle();
	while (e != NULL)
	{
		if (e->info.Source == d || e->info.Target == d)
			Display1Edge(e->info);
		e = e->Next;
	}
	cout << endl;
	for (size_t i = 0; i < 34; i++)
		cout << '=';
}

//Thêm một cạnh có data v vào danh sách cạnh
void AddEdge(LIST &l, Data v)
{
	if (l == NULL)			//Khi tới cuối danh sách
		l = GetEdge(v);		//Thì thêm cạnh đó vào
	else
		AddEdge(l->Next, v);
}

//Thêm một cạnh vào đồ thị
void AddEdge(Graph &g, char start, char end, CostType w, bool directed)
{
	if (!IsConnected(g, start, end))		//Nếu 2 đỉnh không kề
	{
		AddEdge(g.ListEdges, CreateEdge(start, end, w)); //Thì thêm cạnh đó vào
		g.NumEdges++;
		if (!directed)						//Nếu nó là đồ thị vô hướng
		{
			AddEdge(g.ListEdges, CreateEdge(end, start, w)); //Thì thêm cạnh ngược của n
			g.NumEdges++;
		}
	}
	else									//Còn nếu tồn tại trong danh sách rồi
	{
		Edge *e = g.ListEdges;
		while (e != NULL)
		{
			if (e->info.Source == start && e->info.Target == end)
				e->info.Weight = w;			//Thì thay trọng số mới vào
			e = e->Next;
		}
	}
}

//Thêm một cạnh vào đồ thị
void AddEdge(Graph &g, char n, char d, CostType w)
{
	AddEdge(g, n, d, w, g.Directed);
}

//Tạo đồ thị từ file
int OpenFile(char *f, Graph &g)
{
	ifstream in(f);
	if (in.is_open())
	{
		int a, b, w, t;
		char x, y;
		char l;
		bool directed;
		in >> a;						//Đọc số đỉnh
		in >> b;						//Đọc số cạnh
		in >> directed;					//Đọc hướng đồ thị
		g = InitGraph(directed);		//Khởi tạo đồ thị
		for (size_t i = 0; i < a; i++)	//Đọc tên đỉnh
		{
			in >> l;
			AddVertex(g, l);
		}
		for (size_t i = 0; i < a; i++)	//Đọc ma trận
			for (size_t j = 0; j < a; j++)
			{
				in >> t;
				if (t != 1000 && t != 0)
					AddEdge(g, g.Vertices[i].Label, g.Vertices[j].Label, t);
			}
		in.close();
		return 1;
	}
	else
		return 0;
}

//Lưu đồ thị xuống file
void SaveGraph(Graph g, char *f)
{
	ofstream out(f);
	Edge *e = g.ListEdges;
	out << g.NumVertices << '\n';   //Ghi số đỉnh
	out << g.NumEdges << '\n';		//Ghi số cạnh
	out << g.Directed << '\n';		//Ghi kiểu đồ thị
	for (size_t i = 0; i < g.NumVertices; i++)
		out << g.Vertices[i].Label << '\t';
	for (size_t i = 0; i < g.NumVertices; i++)
	{
		out << endl;
		for (size_t j = 0; j < g.NumVertices; j++)
		{
			int t = FindEdge(g, g.Vertices[i].Label, g.Vertices[j].Label);
			if (t == NULLDATA)
				if (i == j)
					out << 0 << '\t';
				else out << 1000 << '\t';
			else out << t << '\t';
		}
	}
	out.close();
}

//Hiển thị danh sách cạnh
void DisplayEdges(Graph g)
{
	Edge *e = g.ListEdges;
	if (e == NULL)
	{
		cout << "\nDanh sach rong!";
		return;
	}
	DisplayTitle();
	while (e != NULL)
	{
		Display1Edge(e->info);
		e = e->Next;
	}
	cout << endl;
	for (size_t i = 0; i < 34; i++)
		cout << '=';
	cout << endl;
}

//Thiết lập lai trạng thái cờ của các đỉnh, cạnh
void ResetFlags(Graph &g)
{
	Edge *e = g.ListEdges;
	while (e != NULL)			//Reset lại danh sách cạnh
	{
		e->info.Marked = NO;
		e = e->Next;
	}
	for (int i = 0; i < g.NumVertices; i++)	//Reset lại danh sách đỉnh
		g.Vertices[i].Visited = NO;
}


//Tìm đỉnh đầu tiên gằn với cur
char FindFirstAdjacentVertex(Graph g, char cur)
{
	for (size_t i = 0; i < g.NumVertices; i++)
		if (g.Vertices[i].Label == cur)
			for (size_t j = 0; j < g.NumVertices; j++)
				if (g.Vertices[j].Visited == NO && IsConnected(g, cur, g.Vertices[j].Label))
					return g.Vertices[j].Label;
	return NULLDATA;
}

//Duyệt đồ thị theo chiều sâu bằng vòng lặp
void DFS_Loop(Graph g, char start)
{
	ResetFlags(g);
	int index = FindIndexVertex(g, start);
	g.Vertices[index].Visited = YES;	//Đánh dấu đỉnh đã xét
	cout << start << '\t';
	stack<char> s;						//Tạo stack 
	s.push(start);						//Thêm đỉnh start vào stack
	char cur, adj;
	while (!s.empty())
	{
		cur = s.top();
		adj = FindFirstAdjacentVertex(g, cur);
		if (adj == NULLDATA)
			s.pop();
		else
		{
			int index = FindIndexVertex(g, adj);
			cout << adj << '\t';
			g.Vertices[index].Visited = YES;
			s.push(adj);
		}
	}
}

//Duyệt đồ thị theo chiều sâu bằng đệ quy
void DFS_Recursion(Graph &g, char start)
{
	int vt = FindIndexVertex(g, start);
	g.Vertices[vt].Visited = YES;
	cout << start << '\t';
	char adj;
	while (true)
	{
		adj = FindFirstAdjacentVertex(g, start);
		if (adj == NULLDATA)
			break;
		else
			DFS_Recursion(g, adj);
	}
}

//Duyệt đồ thị theo chiều rộng
void BFS(Graph g, char start)
{
	ResetFlags(g);
	int index = FindIndexVertex(g, start);
	g.Vertices[index].Visited = YES;
	queue<char> q;
	q.push(start);
	cout << start << '\t';
	char cur, adj;
	while (!q.empty())
	{
		cur = q.front();
		adj = FindFirstAdjacentVertex(g, cur);
		if (adj == NULLDATA)
		{
			q.pop();
			if (q.size() != 0)
				cur = q.front();
			else
				break;
		}
		else
		{
			index = FindIndexVertex(g, adj);
			cout << adj << '\t';
			g.Vertices[index].Visited = YES;
			q.push(adj);
		}
	}
}
