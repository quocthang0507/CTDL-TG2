//Tạo một đỉnh có nhãn l thành 1 phần tử trong danh sách đỉnh
VertexPtr CreateVertex(LabelType l)
{
	VertexPtr v = new Vertex;	//Vertex *v = new Vertex
	v->label = l;
	v->visited = NO;
	v->EdgeList = NULL;
	return v;
}

//Tạo một cạnh chỉ đến đỉnh kề trong danh sách cạnh
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
		if (ds->target == end)		//Nếu ds tồn tại đỉnh end nghĩa là có tồn tại cạnh nối
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

//Đọc dữ liệu từ tập tin
int OpenGraph(Graph &g, char *filename)
{
	ifstream in(filename);
	if (in.is_open())
	{
		int n = 0, m = 0, w = 0, t;
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
		for (size_t i = 0; i < n; i++)
		{
			for (size_t j = 0; j < n; j++)
			{
				in >> t;
				if (t != 1000 && t != 0)
				{
					EdgePtr e = CreateEdge(g.Vertices[j]->label, t);
					AddEdge(g.Vertices[i]->EdgeList, e);
					g.numEdges++;
				}
			}
		}
		in.close();
		return 1;
	}
	else
		return 0;
}

//Hiển thị ma trận kề
void DisplayMatrix(Graph g)
{
	cout << endl;
	for (size_t i = 0; i < g.numVertices; i++)	//Ghi tên các đỉnh
		cout << g.Vertices[i]->label << '\t';
	cout << endl;
	for (size_t i = 0; i < g.numVertices; i++)
	{
		for (size_t j = 0; j < g.numVertices; j++)
		{
			EdgePtr e = FindEdge(g, g.Vertices[i]->label, g.Vertices[j]->label);
			if (e == NULL)
				if (i == j)
					cout << "0" << '\t';
				else cout << "INF" << '\t';
			else cout << e->weight << '\t';
		}
		cout << endl;
	}
}

//==================================PRIM==================================

void EdgeList2CostMatrix(Graph g, CostType matrix[MAX][MAX])
{
	for (size_t i = 0; i < g.numVertices; i++)
	{
		EdgePtr e = g.Vertices[i]->EdgeList;
		for (size_t j = 0; j < g.numVertices; j++)
		{
			if (e->target == g.Vertices[j]->label)
			{
				matrix[i][j] = e->weight;
				if (e->Next != NULL)
					e = e->Next;
			}
			else if (i == j) matrix[i][j] = 0;
			else matrix[i][j] = 1000;
		}
	}
}

void Prim(Graph g, Path tree[MAX], int cost[MAX][MAX])
{
	for (size_t i = 1; i < g.numVertices; i++)		//Khởi tạo cây ban đầu
	{
		tree[i].length = cost[0][i];
		tree[i].parent = 0;
	}
	CostType min;		//Lưu cạnh có trọng số nhỏ nhất
	int minVertex;		//Lưu đỉnh cuối của cạnh đó
	for (size_t i = 1; i < g.numVertices; i++)		//Tìm n-1 cạnh cho cây
	{
		min = INF;
		minVertex = 1;
		for (size_t j = 1; j < g.numVertices; j++)	//Tìm cạnh min
			if (g.Vertices[j]->visited == NO && tree[j].length < min)
			{
				min = tree[j].length;
				minVertex = j;
			}
		g.Vertices[minVertex]->visited = YES;
		for (size_t j = 0; j < g.numVertices; j++)	//Thêm vào cây
			if (g.Vertices[j]->visited == NO && cost[minVertex][j] < tree[j].length)
			{
				tree[j].length = cost[minVertex][j];
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
		cout << endl << '|' << setw(10) << g.Vertices[tree[i].parent]->label << '|' << setw(10) << g.Vertices[i]->label << '|' << setw(10) << tree[i].length << '|';
	}
	cout << "\nCay bao trum ngan nhat co chieu dai: " << sum;
}

//==========================Kruskal===============================

//Lấy ra danh sách cạnh
int AdjMatrix2EdgeList(Graph g, Edge edgeList[UPPER], int cost[MAX][MAX])
{
	int count = 0;
	for (size_t i = 0; i < g.numVertices; i++)
		for (size_t j = 0; j < i; j++)
			if (cost[i][j] != 0 && cost[i][j] != 1000)
			{
				Edge v;
				v.source = g.Vertices[i]->label;
				v.target = g.Vertices[j]->label;
				v.weight = cost[i][j];
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
int Find(Graph g, int leader[MAX], char c)
{
	int x = FindIndexOfVertex(g, c);
	while (x != leader[x])
		x = leader[x];
	return x;
}

//Hợp 2 cây bằng cách nối thêm cạnh e
bool Union(Graph g, int leader[MAX], Edge e)
{
	int x = Find(g, leader, e.source);
	int y = Find(g, leader, e.target);
	if (x == y)			//Nếu trùng gốc
		return false;
	else if (x < y)		//Nhập cây y vào cây x
		leader[y] = x;
	else leader[x] = y;
	return true;
}

void Kruskal(Graph g, Edge tree[UPPER], int cost[MAX][MAX])
{
	int ne = AdjMatrix2EdgeList(g, tree, cost);
	QuickSortEdges(tree, 0, ne - 1);
	int leader[MAX];
	for (size_t i = 0; i < g.numVertices + 1; i++)	//Khởi tạo đỉnh gốc của cây con
		leader[i] = i;
	int count = 0;
	for (size_t i = 0; i < ne; i++)
	{
		if (Union(g, leader, tree[i]))			//Nếu ghép được vào cây bao trùm
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
			cout << endl << '|' << setw(10) << tree[i].source << '|' << setw(10) << tree[i].target << '|' << setw(10) << tree[i].weight << '|';
			sum += tree[i].weight;
		}
	}
	cout << endl << "Tong chieu dai cay bao trum la " << sum;
}

//===============================Dijkstra===============================

//Thuật toán Dijkstra
void Dijkstra(Graph g, int source, Path road[MAX], int cost[MAX][MAX])
{
	CostType min;
	int counter, minVertex, curr;
	for (size_t i = 0; i < g.numVertices; i++)
	{
		road[i].length = cost[source][i];
		road[i].parent = source;
	}
	g.Vertices[source]->visited = YES;
	counter = 1;
	curr = source;
	while (counter < g.numVertices - 1)
	{
		min = INF;
		minVertex = curr;
		for (size_t i = 0; i < g.numVertices; i++)
		{
			if (g.Vertices[i]->visited == NO)
			{
				if (road[i].length > road[curr].length + cost[curr][i])
				{
					road[i].length = road[curr].length + cost[curr][i];
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
		g.Vertices[curr]->visited = YES;
		counter++;
	}
}

//In đoạn đường từ đỉnh đó đến đỉnh target
void PrintPath_Dijkstra(Graph g, Path road[MAX], int target)
{
	if (road[target].parent != target)
		PrintPath_Dijkstra(g, road, road[target].parent);
	cout << '\t' << g.Vertices[target]->label;
}

//In các đoạn đường đến các đỉnh
void PrintAllPath_Dijkstra(Graph g, int start, int cost[MAX][MAX])
{
	Path road[MAX];
	Dijkstra(g, start, road, cost);
	for (size_t i = 0; i < g.numVertices; i++)
	{
		if (road[i].length == INF)
			cout << "\nKhong co duong di tu " << g.Vertices[start]->label << " den " << g.Vertices[i]->label;
		else if (i != start)
		{
			cout << "\nDoan duong tu " << g.Vertices[start]->label << " den " << g.Vertices[i]->label << " la : ";
			PrintPath_Dijkstra(g, road, i);
			cout << "\t(Tong do dai: " << road[i].length << ')';
		}
	}
}

//===============================Floyd===============================

void Floyd(Graph g, Path route[MAX][MAX], int cost[MAX][MAX])
{
	for (size_t i = 0; i < g.numVertices; i++)
		for (size_t j = 0; j < g.numVertices; j++)
		{
			route[i][j].length = cost[i][j];
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
		cout << '\t' << g.Vertices[target]->label;
	}
}

void PrintAllPath_Floyd(Graph g, int cost[MAX][MAX])
{
	Path route[MAX][MAX];
	Floyd(g, route, cost);
	for (size_t i = 0; i < g.numVertices; i++, cout << endl)
		for (size_t j = 0; j < g.numVertices; j++)
		{
			if (route[i][j].length == INF)
				cout << "\nKhong co duong di tu dinh " << g.Vertices[i]->label << " den dinh " << g.Vertices[j]->label;
			else if (i != j)
			{
				cout << "\nDoan duong tu dinh " << g.Vertices[i]->label << " den dinh " << g.Vertices[j]->label << " la: ";
				PrintPath_Floyd(g, route, i, j);
			}
		}
}