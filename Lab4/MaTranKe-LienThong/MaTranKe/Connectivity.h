//Kiểm tra tính liên thông của đồ thị
//Mô tả: Một đồ thị được gọi là liên thông (connected) nếu có đường đi giữa mọi cặp đỉnh phân biệt của đồ thị.
void TestGraphConnectivity(Graph g)
{
	int count = 0, flag = 0;
	for (size_t i = 0; i < g.numVertices; i++)
	{
		if (g.Vertices[i].visited == NO)
		{
			count++;
			cout << "\nThanh phan lien thong thu " << count << " : \t";
			if (DFS_Loop(g, i) == g.numVertices)
				flag = 1;
		}
	}
	cout << "\nLan duyet thu " << count << " thi moi xong!";
	if (flag)
		cout << "\nLien thong!";
	else cout << "\nKhong lien thong!";
}