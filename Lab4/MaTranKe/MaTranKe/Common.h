#define	UPPER		100		//Số phần tử tối đa
#define	ZERO		0		//Giá trị 0
#define	MAX			20		//Số đỉnh tối đa
#define INF			1000	//Vô cùng
#define YES			1		//Đã xét
#define NO			0		//Chưa xét
#define NULLDATA	-1		//Giá trị rỗng

typedef char LabelType;		
typedef int CostType;
typedef CostType Matrix[MAX][MAX];

//Định nghĩa một đỉnh
struct Vertex
{
	LabelType label;
	int visited;
};

//Định nghĩa một cạnh
struct Edge
{
	int source;
	int target;
	CostType weight;
	int marked;
};

//Định nghĩa đường đi
struct Path
{
	CostType length;
	int parent;
};

//Định nghĩa đồ thị
struct Graph
{
	bool directed;
	int numVertices;
	int numEdges;
	Matrix cost;			//Ma trận kề
	Vertex Vertices[MAX];	//Danh sách đỉnh
};