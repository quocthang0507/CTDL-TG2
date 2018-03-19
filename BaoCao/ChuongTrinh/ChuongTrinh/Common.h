//Định nghĩa các hằng số và kiểu dữ liệu đồ thị

#define MAX 30

typedef char LabelType;
typedef int CostType;

struct Edge
{
	int Marked; // Trạng thái
	char Target; // Đỉnh cuối
	CostType Weight; // Trọng số
	Edge* Next; // Cạnh tiếp
};

struct Vertex
{
	LabelType Label; // Nhãn của đỉnh
	int Visited; // Trạng thái
	Edge* EdgeList; // DS cạnh kề
};

struct Path // Một đoạn đường đi
{
	CostType Length; // Độ dài đđi
	int Parent; // Đỉnh trước
};
typedef Path* PathPtr;
typedef Edge* EdgePtr;
typedef Vertex* VertexPtr;

struct Graph
{
	bool Directed; // ĐT có hướng?
	int NumVertices; // Số đỉnh
	int NumEdges; // Số cạnh
	VertexPtr Vertices[MAX]; // DS cac đỉnh kề
};