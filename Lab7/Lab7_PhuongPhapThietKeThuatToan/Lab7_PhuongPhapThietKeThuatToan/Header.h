#define MAX 100
#define INF 1000	//Vô cùng

typedef int MangKQ[MAX][MAX];
typedef int Mang[MAX];

//========================PHUONG PHAP CHIA DE TRI========================
void Nhap_TuDong(Mang a, int length)
{
	srand((unsigned)time(NULL));
	for (size_t i = 0; i < length; i++)
		//rand() % (b – a + 1) + a.
		//rand() : 0..32768
		a[i] = rand() % 21 - 10;	//[-10..10]
}

void Xuat_Mang(Mang a, int length)
{
	cout << "\nMang hien hanh: ";
	for (size_t i = 0; i < length; i++)
		cout << a[i] << '\t';
	cout << endl;
}

void MinMax(Mang a, int l, int r, int &min, int &max)
{
	int min1, min2, max1, max2;
	if (r - l == 1)
	{
		min = a[l];
		max = a[l];
	}
	else
	{
		MinMax(a, l, (l + r) / 2, min1, max1);
		MinMax(a, (l + r) / 2, r, min2, max2);
		if (min1 < min2)
			min = min1;
		else min = min2;
		if (max1 < max2)
			max = max2;
		else max = max1;
	}
}

//========================PHUONG PHAP QUAY LUI========================
//Chia m phần thưởng cho người từ vị trí n
void Chia(int m, int n)
{
	if (n > ::n)	//Nếu đã xét xong, tức là vị trí xét (n) > số người thực tế (::n)
	{
		if (m == 0)	//Và đã chia hết m phần thưởng
		{
			::r++;	//Thì tăng số cách chia r lên
			for (int i = 1; i <= ::n; i++) cout << P[i] << '\t';	//Xuất ra cách chia đó
			cout << endl;
		}
	}
	else
		for (int i = P[n - 1]; i >= 0; i--)	//Số phần thưởng của người phía sau phải nhỏ hơn hoặc bằng số phần thưởng của người phía trước
			if (m - i >= 0)					//Số phần thưởng còn lại (m - i) phải không âm
			{
				P[n] = i;					//Ghi nhận lại số phần thưởng i cho người thứ n
				Chia(m - i, n + 1);			//Chia tiếp số phần thưởng còn lại (m - i) cho người tiếp theo (n + 1)
			}
}

//========================PHUONG PHAP THAM LAM========================
int GTS(Graph g, int tour[MAX], int start)
{
	int v, k, w;
	int min, cost, daXet[MAX];
	for (size_t k = 0; k < g.numVertices; k++)
	{
		daXet[k] = 0;
	}
	cost = 0;
	int i;
	v = start;
	i = 1;
	tour[i] = v;
	daXet[v] = 1;
	while (i < g.numVertices)
	{
		min = INF;
		for (size_t k = 0; k < g.numVertices; k++)
			if (!daXet[k])
				if (min > g.cost[v][k])
				{
					min = g.cost[v][k];
					w = k;
				}
		v = w;
		i++;
		tour[i] = v;
		daXet[v] = 1;
		cost += min;
	}
	cost += g.cost[v][start];
	return cost;
}

//========================PHUONG PHAP QUY HOACH DONG========================

void ChiaPhanThuong(MangKQ c, int m, int n)
{
	//Có i phần thưởng mà chia cho 0 học sinh thì có 0 cách chia
	for (size_t i = 1; i <= m; i++)
		c[i][0] = 0;
	//Có 0 phần thưởng mà chia cho j học sinh thì có 1 cách chia
	for (size_t j = 1; j <= n; j++)
		c[0][j] = 1;
	for (size_t i = 1; i <= m; i++)
	{
		for (size_t j = 1; j <= n; j++)
		{
			//Nếu số phần thưởng < số học sinh thì học sinh từ [i+1] đến j sẽ không có phần thưởng
			//Như vậy, số cách chia i phần thưởng cho j học sinh bằng với số cách chia i phần thưởng cho i học sinh
			if (i < j)
				c[i][j] = c[i][i];
			//Nếu số phần thưởng > số học sinh
			else
				/*TH1: người cuối cùng không có phần thưởng, tức là chỉ chia i phần
				thưởng cho j-1 người, trường hợp này số cách chia là C[ i ][ j-1 ]

				TH2: người cuối cùng chắc chắn có phần thưởng, khi đó ta sẽ lấy j phần
				thưởng chia cho j người, mỗi người sẽ có được 1 phần thưởng trước, lúc này
				còn lại i - j phần thưởng, tiếp tục lấy số còn lại này chia cho j người, trường
				hợp này số cách chia là C[i - j][j].*/
				c[i][j] = c[i][j - 1] + c[i - j][j];
		}
	}
}