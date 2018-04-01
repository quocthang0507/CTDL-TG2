#ifndef _GRAPH
#define _GRAPH

//Định nghĩa các hằng số

#define UPPER 100
#define ZERO 0
#define MAX 20
#define INF 1000
#define YES 1
#define NO 0
#define NULLDATA -1

//Định nghĩa các kiểu dữ liệu

typedef char LaberType;
typedef int CostType;

//Định nghĩa cấu trúc của một đỉnh mới
struct Vertex
{
	LaberType Label;
	int		  Visited;
};

//Định nghĩa cấu trúc của một cạnh
struct Data
{
	char      Source;   //Đỉnh đầu
	char      Target;   //Đỉnh cuối
	CostType  Weight;   //Trọng số
	int       Marked;   //Trạng thái
};

//Định nghĩa Danh sách cạnh
struct Edge
{
	Data info;
	Edge *Next;
};

typedef Edge *LIST;

//Định nghĩa cấu trúc của 1 đồ thị
struct Graph
{
	bool Directed;			//Có hướng hay không?
	int NumVertices;        //Số đỉnh
	int NumEdges;           //Số cạnh
	Vertex Vertices[MAX];	//Danh sách đỉnh
	LIST ListEdges;         //Danh sach cạnh
};
#endif