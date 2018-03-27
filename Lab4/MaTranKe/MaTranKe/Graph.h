Vertex CreateVertex(LabelType l)
{
	Vertex v;
	v.label = l;
	v.visited = NO;
	return v;
}

void DisplayVertex(Graph g, int pos)
{
	cout << g.Vertices[pos].label << '\t';
}

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
				g.cost[i][j] = 0;
			else
				g.cost[i][j] = INF;
		}
	return g;
}

void ResetFlags(Graph &g)
{
	for (size_t i = 0; i < g.numVertices; i++)
		g.Vertices[i].visited = NO;
}

int IsConnected(Graph g, int start, int end)
{
	if (g.cost[start][end] == 0 || g.cost[start][end] == INF)
		return 0;
	else return 1;
}

void AddVertex(Graph &g, LabelType l)
{
	Vertex v = CreateVertex(l);
	g.Vertices[g.numVertices] = v;
	g.numVertices++;
}

void AddEdge(Graph &g, int start, int end, CostType weight, bool directed)
{
	if (IsConnected(g, start, end) == 0)
		g.numEdges++;
	g.cost[start][end] = weight;
	if (directed == false)
		g.cost[end][start] = weight;
}

void AddEdge(Graph &g, int start, int end, CostType weight)
{
	AddEdge(g, start, end, weight, g.directed);
}

void AddEdge(Graph &g, int start, int end)
{
	AddEdge(g, start, end, 1);
}

void SaveGraph(Graph g, char *filename)
{
	ofstream os(filename);
	os << g.numVertices << '\n';
	os << g.numEdges << '\n';
	os << g.directed << '\n';
	for (size_t i = 0; i < g.numVertices; i++)
		os << g.Vertices[i].label << '\n';
	for (size_t i = 0; i < g.numVertices; i++)
	{
		for (size_t j = 0; j < g.numVertices; j++)
			os << g.cost[i][j] << '\t';
		os << '\n';
	}
	os.close();
}

void OpenGraph(Graph &g, char *filename)
{
	ifstream is(filename);
	if (is.is_open())
	{
		int n = 0, m = 0;
		bool d = false;
		LabelType l;
		is >> n;
		is >> m;
		is >> d;
		g = InitGraph(d);
		g.numEdges = m;
		g.numVertices = n;
		for (size_t i = 0; i < g.numVertices; i++)
		{
			is >> l;
			AddVertex(g, l);
		}
		for (size_t i = 0; i < g.numVertices; i++)
			for (size_t j = 0; j < g.numVertices; j++)
				is >> g.cost[i][j];
		is.close();
	}
	else
		cout << "\nLoi khong the mo file!";
}

int FindFirstAdjacentVertex(Graph g, int curr)
{
	for (size_t i = 0; i < g.numVertices; i++)
		if (g.Vertices[i].visited == NO && IsConnected(g, curr, i) == 1)
			return i;
	return NULLDATA;
}

void DFS_Recursion(Graph &g, int start)
{
	g.Vertices[start].visited = YES;
	DisplayVertex(g, start);
	while (true)
	{
		int t = FindFirstAdjacentVertex(g, start);
		if (t == NULLDATA)
			break;
		else
			DFS_Recursion(g, t);
	}
}

void DFS_Loop(Graph &g, int start)
{
	g.Vertices[start].visited = YES;
	DisplayVertex(g, start);
	stack<int>s;
	s.push(start);
	int curr, adj;
	while (!s.empty())
	{
		curr = s.top();
		adj = FindFirstAdjacentVertex(g, curr);
		if (adj == NULLDATA)
			s.pop();
		else
		{
			g.Vertices[adj].visited = YES;
			DisplayVertex(g, adj);
			s.push(adj);
		}
	}
}

void BFS(Graph g, int start)
{
	g.Vertices[start].visited = YES;
	queue<int>q;
	q.push(start);
	int curr, adj;
	while (!q.empty())
	{
		curr = q.front();
		DisplayVertex(g, curr);
		while (true)
		{
			adj = FindFirstAdjacentVertex(g, curr);
			if (adj == NULLDATA)
				break;
			else
			{
				g.Vertices[adj].visited = YES;
				q.push(adj);
			}
		}
	}
}