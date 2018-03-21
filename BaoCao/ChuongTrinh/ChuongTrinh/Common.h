//Định nghĩa các hằng số và kiểu dữ liệu đồ thị
#ifndef _GRAPH_
#define _GRAPH_
#endif //!_GRAPH_

#define UPPER 100			//Số phần tử tối đa
#define ZERO 0				//Giá trị 0
#define MAX 20				//Số đỉnh tối đa
#define INF 1000			//Vô cùng
#define YES 1				//Đã xét
#define NO 0				//Chưa xét
#define NULLDATA -1			//Giá trị rỗng

typedef char LabelType;		//Kiểu tên nhãn là một ký tự
typedef int CostType;		//Trọng số

struct Edge
{
	int Marked;				//Trạng thái
	char source;			//Đỉnh đầu
	char target;			//Đỉnh cuối
	CostType Weight;		//Trọng số
	Edge* Next;				//Cạnh tiếp
};

struct Vertex
{
	LabelType Label;		//Nhãn của đỉnh
	int Visited;			//Trạng thái
};

struct Path					//Một đoạn đường đi
{
	CostType Length;		//Độ dài đường đi
	int Parent;				//Đỉnh trước
};

typedef Edge* EdgePtr;

struct Graph
{
	bool Directed;			//ĐT có hướng hay không
	int NumVertices;		//Số đỉnh
	int NumEdges;			//Số cạnh
	EdgePtr Edges[MAX];		//DS các cạnh
};