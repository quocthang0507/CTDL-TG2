//Tạo một đỉnh có nhãn l
Vertex CreateVertex(LabelType l)
{
	Vertex v;
	v.label = l;
	v.visited = NO;
	return v;
}

//Tìm chỉ số của một đỉnh, nếu không có thì trả về -1
int FindIndexOfVertex(Graph g, LabelType l)
{
	for (size_t i = 0; i < MAX; i++)
		if (g.Vertices[i].label == l)
			return i;
	return -1;
}

//Hiển thị tên đỉnh
void DisplayVertex(Graph g, int pos)
{
	cout << g.Vertices[pos].label << '\t';
}

//Xuất ma trận kề
void DisplayMatrix(Graph g)
{
	cout << endl;
	int t;
	cout << setw(6) << "";
	for (size_t i = 0; i < g.numVertices; i++)
		cout << setw(6) << g.Vertices[i].label;
	cout << endl;
	for (size_t i = 0; i < g.numVertices; i++)
	{
		cout << setw(6) << g.Vertices[i].label;
		for (size_t j = 0; j < g.numVertices; j++)
		{
			t = g.cost[i][j];
			if (t == 1000)
				cout << setw(6) << "INF";
			else cout << setw(6) << t;
		}
		cout << endl;
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
		for (size_t j = 0; j < g.numVertices; j++)
		{
			if (i == j)
				g.cost[i][j] = 0;	//Đường chéo chính
			else
				g.cost[i][j] = INF;	//Còn lại là vô cùng
		}
	return g;
}

//Đánh dấu lại trạng thái của các đỉnh
void ResetFlags(Graph &g)
{
	for (size_t i = 0; i < g.numVertices; i++)
		g.Vertices[i].visited = NO;
}

//Kiểm tra 2 đỉnh có vị trí start và end có kề nhau (có cạnh nối với nhau)
int IsConnected(Graph g, int start, int end)
{
	if (g.cost[start][end] == 0 || g.cost[start][end] == INF)
		return 0;
	else return 1;
}

//Thêm một đỉnh có nhãn l vào đồ thị
void AddVertex(Graph &g, LabelType l)
{
	Vertex v = CreateVertex(l);
	g.Vertices[g.numVertices] = v;
	g.numVertices++;
	g.cost[g.numVertices - 1][g.numVertices - 1] = 0;
	for (size_t i = 0; i < g.numVertices - 1; i++)
	{
		g.cost[i][g.numVertices - 1] = INF;
		g.cost[g.numVertices - 1][i] = INF;
	}
}

//Thêm một cạnh vào đồ thị
void AddEdge(Graph &g, int start, int end, CostType weight, bool directed)
{
	if (IsConnected(g, start, end) == 0)	//Nếu 2 đỉnh không kề nhau
	{
		g.numEdges++;
		g.cost[start][end] = weight;
		if (directed == false)				//Nếu là đồ thị vô hướng
			g.cost[end][start] = weight;
	}
}

void AddEdge(Graph &g, int start, int end, CostType weight)
{
	AddEdge(g, start, end, weight, g.directed);
}

void AddEdge(Graph &g, int start, int end)
{
	AddEdge(g, start, end, 1);
}

//Tìm đỉnh kề với curr mà chưa xét
int FindFirstAdjacentVertex(Graph g, int curr)
{
	for (size_t i = 0; i < g.numVertices; i++)
		if (g.Vertices[i].visited == NO && IsConnected(g, curr, i) == 1)
			return i;
	return NULLDATA;
}

//Đọc dữ liệu từ tập tin
int OpenGraph(Graph &g, char *filename)
{
	ifstream is(filename);
	if (is.is_open())
	{
		int n = 0, m = 0;
		bool d = false;
		char l;
		is >> n;	//Số đỉnh
		is >> m;	//Số cạnh
		is >> d;	//Loại đồ thị
		int t;
		g = InitGraph(d);
		g.numEdges = m;
		for (size_t i = 0; i < n; i++)	//Khởi tạo nhãn của các đỉnh
		{
			is >> l;
			AddVertex(g, l);
		}
		for (size_t i = 0; i < n; i++)	//Đọc ma trận kề
			for (size_t j = 0; j < n; j++)
			{
				is >> t;
				if (t != 0)
					g.cost[i][j] = t;
			}
		is.close();
		return 1;
	}
	else
		return 0;
}

//==========================PRIM===============================

void Prim(Graph g, Path tree[MAX])
{
	for (size_t i = 1; i < g.numVertices; i++)		//Khởi tạo cây ban đầu
	{
		tree[i].length = g.cost[0][i];
		tree[i].parent = 0;
	}
	CostType min;		//Lưu cạnh có trọng số nhỏ nhất
	int minVertex;		//Lưu đỉnh cuối của cạnh đó
	for (size_t i = 1; i < g.numVertices; i++)		//Tìm n-1 cạnh cho cây
	{
		/*min = tree[i].length;*/
		min = INF;
		minVertex = 1;
		for (size_t j = 1; j < g.numVertices; j++)	//Tìm cạnh min
			if (g.Vertices[j].visited == NO && tree[j].length < min)
			{
				min = tree[j].length;
				minVertex = j;
			}
		g.Vertices[minVertex].visited = YES;
		for (size_t j = 0; j < g.numVertices; j++)	//Thêm vào cây
			if (g.Vertices[j].visited == NO && g.cost[minVertex][j] < tree[j].length)
			{
				tree[j].length = g.cost[minVertex][j];
				tree[j].parent = minVertex;
			}
	}
}

void PrintPrimMST(Graph g, Path tree[MAX])
{
	cout << endl << "Cay bao trum gom cac canh sau:";
	CostType sum = 0;
	cout << endl << '|' << setw(10) << "Dinh Dau" << '|' << setw(10) << "Dinh Cuoi" << '|' << setw(10) << "Trong so" << '|';
	for (size_t i = 1; i < g.numVertices; i++)
	{
		sum += tree[i].length;
		cout << endl << '|' << setw(10) << g.Vertices[tree[i].parent].label << '|' << setw(10) << g.Vertices[i].label << '|' << setw(10) << tree[i].length << '|';
	}
	cout << "\nCay bao trum ngan nhat co chieu dai: " << sum;
}