//Tạo một đỉnh có nhãn l thành 1 phần tử trong danh sách đỉnh
VertexPtr CreateVertex(LabelType l)
{
	VertexPtr v = new Vertex;	//Vertex *v = new Vertex
	v->label = l;
	v->visited = NO;
	v->EdgeList = NULL;
	return v;
}

//Tạo một cạnh chỉ đến đỉnh l thành một phần tử trong danh sách cạnh
EdgePtr CreateEdge(char l, CostType w)
{
	EdgePtr e = new Edge;
	e->target = l;
	e->weight = w;
	e->marked = NO;
	e->Next = NULL;
	return e;
}

//Tìm chỉ số của một đỉnh, nếu không có thì trả về -1
int FindIndexOfVertex(Graph g, LabelType l)
{
	for (size_t i = 0; i < g.numVertices; i++)
		if (g.Vertices[i]->label == l)
			return i;
	return -1;
}

//Xuất danh sách cạnh của một đỉnh mà được trỏ bằng ds
void XuatDSCanh(EdgePtr ds)
{
	while (ds != NULL)
	{
		cout << "\n\tDinh cuoi : " << ds->target << " Trong so: " << ds->weight;
		ds = ds->Next;
	}
}

//Hiển thị thông tin đỉnh v trong đồ thị
void Xuat1Dinh(Graph g, char v)
{
	int s = FindIndexOfVertex(g, v);
	if (s == -1)
		cout << "\nKhong co dinh " << v << " trong do thi!";
	else
	{
		cout << "\nDinh dau " << v;
		XuatDSCanh(g.Vertices[s]->EdgeList);
	}
}

//Khởi tạo đồ thị
Graph InitGraph(bool directed)
{
	Graph g;
	g.numEdges = 0;
	g.numVertices = 0;
	g.directed = directed;
	for (size_t i = 0; i < g.numVertices; i++)
	{
		g.Vertices[i]->EdgeList = NULL;
		g.Vertices[i]->label = NULL;
		g.Vertices[i]->visited = NO;
	}
	return g;
}

//Đánh dấu lại trạng thái của các đỉnh
void ResetFlags(Graph &g)
{
	for (size_t i = 0; i < g.numVertices; i++)
		g.Vertices[i]->visited = NO;
}

EdgePtr FindEdge(Graph g, char start, char end)
{
	int v = FindIndexOfVertex(g, start);
	EdgePtr ds = g.Vertices[v]->EdgeList;	//Trỏ tới danh sách đỉnh kề với đỉnh start
	while (ds != NULL)
	{
		if (ds->target = end)		//Nếu ds tồn tại đỉnh end nghĩa là có tồn tại cạnh nối
			break;
		ds = ds->Next;
	}
	return ds;
}

//Kiểm tra 2 đỉnh có vị trí start và end có kề nhau (có cạnh nối với nhau)
int IsConnected(Graph g, char start, char end)
{
	EdgePtr e = new Edge;
	e = FindEdge(g, start, end);
	return (e != NULL);
}

//Thêm một đỉnh có nhãn l vào đồ thị
void AddVertex(Graph &g, VertexPtr v)
{
	g.Vertices[g.numVertices] = v;
	g.numVertices++;
}

//Thêm một cạnh e vào danh sách cạnh v
void AddEdge(EdgePtr &v, EdgePtr e)
{
	if (v == NULL)
		v = e;
	else AddEdge(v->Next, e);		//Trỏ tới cuối danh sách
}

// Thêm một cạnh chỉ đến đỉnh lab với trọng số w vào danh sách của đỉnh v
void AddEdge(Graph &g, char v, char lab, CostType w)
{
	if (v == NULL)
		v = lab;
	else
	{
		if (g.directed == 0)
		{
			EdgePtr h, k;
			h = CreateEdge(lab, w);
			k = CreateEdge(v, w);
			AddEdge(g.Vertices[FindIndexOfVertex(g, v)]->EdgeList, h);
			AddEdge(g.Vertices[FindIndexOfVertex(g, lab)]->EdgeList, k);
			g.numEdges = g.numEdges + 2;
		}
		else
		{
			EdgePtr a;
			a = CreateEdge(lab, w);
			AddEdge(g.Vertices[FindIndexOfVertex(g, v)]->EdgeList, a);
			g.numEdges = g.numEdges + 1;
		}
	}
}

//Lưu đồ thị vào tập tin
void SaveGraph(Graph g, char *filename)
{
	ofstream out(filename);
	out << g.numVertices << '\n';
	out << g.numEdges << '\n';
	out << g.directed << '\n';
	for (size_t i = 0; i < g.numVertices; i++)	//Lưu tên các đỉnh
		out << g.Vertices[i]->label << '\n';
	for (size_t i = 0; i < g.numVertices; i++)	//Lưu ma trận kề
	{
		for (size_t j = 0; j < g.numVertices; j++)
		{
			if (i == j)
				out << '0' << '\t';
			else
			{
				if (IsConnected(g, g.Vertices[i]->label, g.Vertices[j]->label))
				{
					EdgePtr t = FindEdge(g, g.Vertices[i]->label, g.Vertices[j]->label);
					out << g.Vertices[j]->EdgeList->weight << '\t';
				}
				else out << "1000" << '\t';
			}
		}
		if (i != g.numVertices - 1)
			out << '\n';
	}
	out.close();
}

//Đọc dữ liệu từ tập tin
int OpenGraph(Graph &g, char *filename)
{
	ifstream in(filename);
	if (in.is_open())
	{
		int n = 0, m = 0, w = 0;
		bool d = false;
		LabelType l;
		in >> n;	//Số đỉnh
		in >> m;	//Số cạnh
		in >> d;	//Loại đồ thị
		g = InitGraph(d);
		for (size_t i = 0; i < n; i++)	//Khởi tạo nhãn của các đỉnh
		{
			in >> l;
			VertexPtr v = CreateVertex(l);
			AddVertex(g, v);
		}
		l = ' ';
		int vt;
		for (size_t i = 0; i < m; i++)	//Đọc ma trận kề
		{
			char s, t;
			in >> s;
			in >> t;
			in >> w;
			if (l != s)
			{
				l = s;
				vt = FindIndexOfVertex(g, s);
			}
			if (w == NULL)
				w = 1;
			EdgePtr e = CreateEdge(t, w);
			AddEdge(g.Vertices[vt]->EdgeList, e);
			g.numEdges++;
		}
		in.close();
		return 1;
	}
	else
		return 0;
}

//Tìm đỉnh kề với curr mà chưa xét
char FindFirstAdjacentVertex(Graph g, char cur)
{
	for (size_t i = 0; i < g.numVertices; i++)
		if (g.Vertices[i]->label == cur)
		{
			EdgePtr p = g.Vertices[i]->EdgeList;
			while (p != NULL)
			{
				for (size_t j = 0; j < g.numVertices; j++)
					if (g.Vertices[j]->label == p->target && g.Vertices[j]->visited == NO)
						return p->target;
				p = p->Next;
			}
		}
	return NULLDATA;
}

//Duyệt đồ thị theo chiều sau (Depth First Search)
//Mô tả: Đi tiếp đến khi nào không đi đến được nữa thì lùi lại và tìm đường đi mới, và một đỉnh không đi qua 2 lần
void DFS_Recursion(Graph &g, int start)
{
	//g.Vertices[start].visited = YES;
	//DisplayVertex(g, start);
	//while (true)
	//{
	//	int t = FindFirstAdjacentVertex(g, start);
	//	if (t == NULLDATA)
	//		break;
	//	else
	//		DFS_Recursion(g, t);
	//}
}

void DFS_Loop(Graph &g, char start)
{
	ResetFlags(g);
	int vt = FindIndexOfVertex(g, start);
	g.Vertices[vt]->visited = YES;
	cout << start << '\t';
	stack<char>s;
	s.push(start);
	char curr, adj;
	while (!s.empty())
	{
		curr = s.top();
		adj = FindFirstAdjacentVertex(g, curr);
		if (adj == NULLDATA)
			s.pop();
		else
		{
			vt = FindIndexOfVertex(g, adj);
			g.Vertices[vt]->visited = YES;
			cout << adj << '\t';
			s.push(adj);
		}
	}
}

//Duyệt đồ thị theo chiều rộng (Breadth First Search)
//Mô tả: Đi từ gốc, sau đó đi tới các đỉnh kề với đỉnh gốc và tiếp tục đi tới các đỉnh kề với các đỉnh đã xét
void BFS(Graph g, char start)
{
	ResetFlags(g);
	int vt = FindIndexOfVertex(g, start);
	g.Vertices[vt]->visited = YES;
	queue<int>q;
	q.push(start);
	char cur, adj;
	cur = q.front();
	while (!q.empty())
	{
		adj = FindFirstAdjacentVertex(g, cur);
		if (adj == NULLDATA)
		{
			q.pop();
			if (q.size() != 0)
				cur = q.front();
			else break;
		}
		else
		{
			vt = FindIndexOfVertex(g, adj);
			g.Vertices[vt]->visited = YES;
			cout << adj << '\t';
			q.push(adj);
		}
	}
}

void DisplayMatrix(Graph g)
{
	for (size_t i = 0; i < g.numVertices; i++)	//Ghi tên các đỉnh
		cout << g.Vertices[i]->label << '\n';
	for (size_t i = 0; i < g.numVertices; i++)	//Ghi ma trận
	{
		for (size_t j = 0; j < g.numVertices; j++)
		{
			if (i == j)
				cout << '0' << '\t';
			else
			{
				if (IsConnected(g, g.Vertices[i]->label, g.Vertices[j]->label))
				{
					EdgePtr t = FindEdge(g, g.Vertices[i]->label, g.Vertices[j]->label);
					cout << g.Vertices[j]->EdgeList->weight << '\t';
				}
				else cout << "INF" << '\t';
			}
		}
		if (i != g.numVertices - 1)
			cout << '\n';
	}

}