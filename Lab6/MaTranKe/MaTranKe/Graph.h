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

//Hiển thị thông tin của một đỉnh dựa vào vị trí pos
void DisplayInfoVertex(Graph g, int pos)
{
	cout << "\nCac dinh ke voi " << g.Vertices[pos].label << " la:";
	for (size_t i = 0; i < g.numVertices; i++)
		if (g.cost[pos][i] != ZERO)
			cout << '\t' << g.Vertices[i].label;
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
	for (size_t i = 0; i < g.numVertices; i++)
		cout << '\t' << g.Vertices[i].label;
	cout << endl;
	for (size_t i = 0; i < g.numVertices; i++)
	{
		cout << g.Vertices[i].label << '\t';
		for (size_t j = 0; j < g.numVertices; j++)
		{
			t = g.cost[i][j];
			if (t == 1000)
				cout << "INF";
			else cout << t;
			cout << '\t';
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

//Đọc dữ liệu từ tập tin
int OpenGraph(Graph &g, char *filename)
{
	ifstream is(filename);
	if (is.is_open())
	{
		int n = 0, m = 0;
		bool d = false;
		LabelType l;
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

//==========================Kruskal===============================

//Lấy ra danh sách cạnh
int AdjMatrix2EdgeList(Graph g, Edge edgeList[UPPER])
{
	int count = 0;
	for (size_t i = 1; i < g.numVertices; i++)
		for (size_t j = 0; j < i; j++)
			if (g.cost[i][j] != 0 && g.cost[i][j] != 1000)
			{
				Edge v;
				v.source = i;
				v.target = j;
				v.weight = g.cost[i][j];
				v.marked = NO;
				edgeList[count] = v;
				count++;
			}
	return count;
}

//Sắp xếp danh sách cạnh
void QuickSortEdges(Edge edgeList[MAX], int d, int c)
{
	int i = d, j = c;
	CostType mid = edgeList[(d + c) / 2].weight;
	while (i <= j)
	{
		while (edgeList[i].weight < mid)i++;
		while (edgeList[j].weight > mid)j--;
		if (i <= j)
		{
			swap(edgeList[i], edgeList[j]);
			i++;
			j--;
		}
	}
	if (i < c)QuickSortEdges(edgeList, i, c);
	if (d < j)QuickSortEdges(edgeList, d, j);
}

//Tìm nút gốc của cây chứa đỉnh x
int Find(int leader[MAX], int x)
{
	while (x != leader[x])x = leader[x];
	return x;
}

//Hợp 2 cây bằng cách nối thêm cạnh e
bool Union(int leader[MAX], Edge e)
{
	int x = Find(leader, e.source);
	int y = Find(leader, e.target);
	if (x == y)			//Nếu trùng gốc
		return false;
	else if (x < y)		//Nhập cây y vào cây x
		leader[y] = x;
	else leader[x] = y;
	return true;
}

void Kruskal(Graph g, Edge tree[UPPER])
{
	int ne = AdjMatrix2EdgeList(g, tree);
	QuickSortEdges(tree, 0, ne - 1);
	int leader[MAX];
	for (size_t i = 0; i < g.numVertices + 1; i++)	//Khởi tạo đỉnh gốc của cây con
		leader[i] = i;
	int count = 0;
	for (size_t i = 0; i < ne; i++)
	{
		if (Union(leader, tree[i]))			//Nếu ghép được vào cây bao trùm
		{
			tree[i].marked = YES;
			count++;
			if (count == g.numVertices - 1)	//Nếu đủ n-1 cạnh
				break;
		}
	}
}

void PrintKruskalMST(Graph g, Edge tree[UPPER])
{
	cout << endl << "Cay bao trum gom cac canh sau: ";
	CostType sum = 0;
	cout << endl << '|' << setw(10) << "Dinh Dau" << '|' << setw(10) << "Dinh Cuoi" << '|' << setw(10) << "Trong so" << '|';
	for (size_t i = 0; i < g.numVertices; i++)
	{
		if (tree[i].marked == YES)
		{
			cout << endl << '|' << setw(10) << g.Vertices[tree[i].source].label << '|' << setw(10) << g.Vertices[tree[i].target].label << '|' << setw(10) << tree[i].weight << '|';
			sum += tree[i].weight;
		}
	}
	cout << endl << "Tong chieu dai cay bao trum la " << sum;
}

//===============================Dijkstra===============================

//Thuật toán Dijkstra
void Dijkstra(Graph g, int source, Path road[MAX])
{
	CostType min;
	int counter, minVertex, curr;
	for (size_t i = 0; i < g.numVertices; i++)
	{
		road[i].length = g.cost[source][i];
		road[i].parent = source;
	}
	g.Vertices[source].visited = YES;
	counter = 1;
	curr = source;
	while (counter < g.numVertices - 1)
	{
		min = INF;
		minVertex = curr;
		for (size_t i = 0; i < g.numVertices; i++)
		{
			if (g.Vertices[i].visited == NO)
			{
				if (road[i].length > road[curr].length + g.cost[curr][i])
				{
					road[i].length = road[curr].length + g.cost[curr][i];
					road[i].parent = curr;
				}
				if (min > road[i].length)
				{
					min = road[i].length;
					minVertex = i;
				}
			}
		}
		curr = minVertex;
		g.Vertices[curr].visited = YES;
		counter++;
	}
}

//In đoạn đường từ đỉnh đó đến đỉnh target
void PrintPath_Dijkstra(Graph g, Path road[MAX], int target)
{
	if (road[target].parent != target)
		PrintPath_Dijkstra(g, road, road[target].parent);
	cout << '\t' << g.Vertices[target].label;
}

//In các đoạn đường đến các đỉnh
void PrintAllPath_Dijkstra(Graph g, int start)
{
	Path road[MAX];
	Dijkstra(g, start, road);
	for (size_t i = 0; i < g.numVertices; i++)
	{
		if (road[i].length == INF)
			cout << "\nKhong co duong di tu " << g.Vertices[start].label << " den " << g.Vertices[i].label;
		else if (i != start)
		{
			cout << "\nDoan duong tu " << g.Vertices[start].label << " den " << g.Vertices[i].label << " la : ";
			PrintPath_Dijkstra(g, road, i);
			cout << "\t(Tong do dai: " << road[i].length << ')';
		}
	}
}

//===============================Floyd===============================

void Floyd(Graph g, Path route[MAX][MAX])
{
	for (size_t i = 0; i < g.numVertices; i++)
	for (size_t j = 0; j < g.numVertices; j++)
	{
		route[i][j].length = g.cost[i][j];
		route[i][j].parent = i;
	}
	for (size_t k = 0; k < g.numVertices; k++)
	for (size_t i = 0; i < g.numVertices; i++)
	for (size_t j = 0; j < g.numVertices; j++)
	if (route[i][j].length > route[i][k].length + route[k][j].length)
	{
		route[i][j].length = route[i][k].length + route[k][j].length;
		route[i][j].parent = route[k][j].parent;
	}
}

void PrintPath_Floyd(Graph g, Path route[MAX][MAX], int source, int target)
{
	if (route[source][target].parent != target)
	{
		PrintPath_Floyd(g, route, source, route[source][target].parent);
		cout << '\t' << g.Vertices[target].label;
	}
}

void PrintAllPath_Floyd(Graph g)
{
	Path route[MAX][MAX];
	Floyd(g, route);
	for (size_t i = 0; i < g.numVertices; i++, cout << endl)
	for (size_t j = 0; j < g.numVertices; j++)
	{
		if (route[i][j].length == INF)
			cout << "\nKhong co duong di tu dinh " << g.Vertices[i].label << " den dinh " << g.Vertices[j].label;
		else if (i != j)
		{
			cout << "\nDoan duong tu dinh " << g.Vertices[i].label << " den dinh " << g.Vertices[j].label << " la: ";
			PrintPath_Floyd(g, route, i, j);
		}
	}
}