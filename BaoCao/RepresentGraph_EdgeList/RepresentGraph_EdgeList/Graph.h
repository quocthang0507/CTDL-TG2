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

//Kiểm tra có 2 đỉnh kề nhau không?
int IsConnected(Graph g, char u, char v)
{
	Edge *e = g.ListEdges;
	while (e != NULL)
	{
		if ((e->info.Source == u) && (e->info.Target == v))
			return 1;
		e = e->Next;
	}
	return 0;
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
		g.NumEdges++;						//Thì tăng số cạnh lên 1
		AddEdge(g.ListEdges, CreateEdge(start, end, w)); //Và thêm cạnh đó vào
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
		int a, b, w;
		char x, y;
		bool directed;
		in >> a;					//Đọc số đỉnh
		in >> b;					//Đọc số cạnh
		in >> directed;				//Đọc hướng đồ thị
		g = InitGraph(directed);	//Khởi tạo đồ thị
		for (int i = 0; i < b; i++)
		{
			in >> x;		//Đỉnh đầu
			in >> y;		//Đỉnh cuối
			in >> w;		//Trọng số			
			AddEdge(g, x, y, w, g.Directed); //Thêm cạnh vào đồ thị
			AddVertex(g, x);	//Thêm đỉnh đầu vào danh sách đỉnh
			AddVertex(g, y);	//Thêm đỉnh cuối vào danh sách đỉnh
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
	out << g.NumVertices << '\t';   //Ghi số đỉnh
	out << g.NumEdges << '\t';		//Ghi số cạnh
	out << g.Directed;				//Ghi kiểu đồ thị
	while (e != NULL)				//Xuất danh sách cạnh
	{
		out << '\n' << e->info.Source << '\t' << e->info.Target << '\t' << e->info.Weight;
		e = e->Next;
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
				if (IsConnected(g, cur, g.Vertices[j].Label) && g.Vertices[j].Visited == NO)
					return g.Vertices[j].Label;
	return NULLDATA;
}

//Duyệt đồ thị theo chiều sâu
void DFS(Graph g, char start)
{
	ResetFlags(g);
	int index = FindIndexVertex(g, start);
	g.Vertices[index].Visited = YES;		//Đánh dấu đỉnh đã xét
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
