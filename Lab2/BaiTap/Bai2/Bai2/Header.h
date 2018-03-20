struct SinhVien
{
	char maSV[8];
	double M1;
	double M2;
	double M3;
	double diemTB;
};

typedef SinhVien Data;

//Định nghĩa hằng số tín chỉ của mỗi môn
const int M1 = 4;
const int M2 = 4;
const int M3 = 2;

struct tagNode
{
	Data info;
	tagNode *pNext;
};

typedef tagNode NODE;

struct LIST
{
	NODE *pHead;
	NODE *pTail;
};

void CreateList(LIST &l)
{
	l.pHead = l.pTail = NULL;
}

NODE *GetNode(Data x)
{
	NODE *p = new NODE;
	if (p != NULL)
	{
		p->info = x;
		p->pNext = NULL;
	}
	return p;
}

void InsertTail(LIST &l, Data x)
{
	NODE *new_ele = GetNode(x);
	if (new_ele == NULL)
	{
		cout << "\nLoi cap phat bo nho!";
		return;
	}
	if (l.pHead == NULL)
	{
		l.pHead = new_ele;
		l.pTail = l.pHead;
	}
	else
	{
		l.pTail->pNext = new_ele;
		l.pTail = new_ele;
	}
}

void Print_Line()
{
	cout << endl;
	cout << ':';
	for (size_t i = 0; i < 52; i++)
		cout << '=';
	cout << ':';
}

void Print_Title()
{
	cout << endl << "BANG DIEM SINH VIEN";
	Print_Line();
	cout << endl;
	cout << setiosflags(ios::left)
		<< ':'
		<< setw(8) << "Ma SV"
		<< ':'
		<< setw(10) << "Diem M1"
		<< ':'
		<< setw(10) << "Diem M2"
		<< ':'
		<< setw(10) << "Diem M3"
		<< ':'
		<< setw(10) << "Diem TBHK"
		<< ':';
	Print_Line();
}

void Print_1Node(Data x)
{
	cout << endl;
	cout << setiosflags(ios::left)
		<< ':'
		<< setw(8) << x.maSV
		<< ':'
		<< setw(10) << setprecision(2) << x.M1
		<< ':'
		<< setw(10) << setprecision(2) << x.M2
		<< ':'
		<< setw(10) << setprecision(2) << x.M3
		<< ':'
		<< setw(10) << setprecision(2) << x.diemTB
		<< ':';
}

void Print_Result(LIST l)
{
	NODE *p = l.pHead;
	if (p == NULL)
	{
		cout << "\nDanh sach rong!";
		return;
	}
	Print_Title();
	while (p != NULL)
	{
		Print_1Node(p->info);
		p = p->pNext;
	}
	Print_Line();
	cout << endl;
}

//Tính điểm trung bình của một sinh viên
double Calculate_Mark(Data x)
{
	double mark;
	mark = (x.M1*M1 + x.M2*M2 + x.M3*M3) / (M1 + M2 + M3);
	return mark;
}

int Read_File(char *filename, LIST &l)
{
	ifstream in(filename);
	if (!in)
		return 0;
	Data x;
	CreateList(l);
	char maSV[8];
	double M1;
	double M2;
	double M3;
	double diemTB;
	in >> maSV; strcpy_s(x.maSV, maSV);
	in >> M1; x.M1 = M1;
	in >> M2; x.M2 = M2;
	in >> M3; x.M3 = M3;
	x.diemTB = Calculate_Mark(x);
	InsertTail(l, x);
	while (!in.eof())
	{
		in >> maSV; strcpy_s(x.maSV, maSV);
		in >> M1; x.M1 = M1;
		in >> M2; x.M2 = M2;
		in >> M3; x.M3 = M3;
		x.diemTB = Calculate_Mark(x);
		InsertTail(l, x);
	}
	in.close();
	return 1;
}