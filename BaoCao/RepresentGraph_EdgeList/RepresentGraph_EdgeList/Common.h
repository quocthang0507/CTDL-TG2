#ifndef _GRAPH
#define _GRAPH

//Định nghĩa các hằng số

#define UPPER 100 	//Số phần tử tối đa
#define ZERO 0 		//Giá trị 0
#define MAX 20 		//Số đỉnh tối đa
#define INF 1000 	//Vô cùng
#define YES 1 		//Đã xét
#define NO 0 		//Chưa xét
#define NULLDATA -1 //Giá trị rỗng

//Định nghĩa các kiểu dữ liệu

typedef char LabelType; //Kiểu tên nhãn là một ký tự
typedef int CostType; //Trọng số

//Định nghĩa cấu trúc của một đỉnh mới
struct Vertex
{
	LabelType Label;
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