#define	UPPER		100		//Số phần tử tối đa
#define	ZERO		0		//Giá trị 0
#define	MAX			20		//Số đỉnh tối đa
#define INF			1000	//Vô cùng
#define YES			1		//Đã xét
#define NO			0		//Chưa xét
#define NULLDATA	-1		//Giá trị rỗng

typedef char LabelType;		
typedef int CostType;

//Định nghĩa một cạnh
struct Edge
{
	int marked;
	char source;	//Vì phải dùng Kruskal nên mới thêm
	char target;
	CostType weight;
	Edge *Next;		//Cạnh kế tiếp
};

//Định nghĩa một đỉnh
struct Vertex
{
	LabelType label;
	int visited;
	Edge *EdgeList;	//Danh sách cạnh kề
};

struct Path
{
	CostType length;
	int parent;
};

typedef Edge *EdgePtr;		//Danh sách cạnh
typedef Vertex *VertexPtr;	//Danh sách đỉnh kề với 1 đỉnh nào đó

//Định nghĩa đồ thị
struct Graph
{
	bool directed;
	int numVertices;
	int numEdges;
	VertexPtr Vertices[MAX];	//Danh sách các đỉnh chứa các đỉnh kề
};