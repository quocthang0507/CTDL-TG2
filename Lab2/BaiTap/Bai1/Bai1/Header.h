struct NhanVien
{
	char maNV[8];
	char ho[10];
	char tenLot[10];
	char ten[10];
	int namSinh;
	int tdvh;
	int luong;
};

typedef NhanVien Data;

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
	for (size_t i = 0; i < 61; i++)
		cout << '=';
	cout << ':';
}

void Print_Title()
{
	Print_Line();
	cout << endl;
	cout << setiosflags(ios::left)
		<< ':'
		<< setw(8) << "Ma NV"
		<< ':'
		<< setw(10) << "Ho"
		<< ':'
		<< setw(10) << "Ten Lot"
		<< ':'
		<< setw(10) << "Ten"
		<< ':'
		<< setw(5) << "NS"
		<< ':'
		<< setw(4) << "TDVH"
		<< ':'
		<< setw(8) << "Luong"
		<< ':';
	Print_Line();
}

void Print_1Node(Data x)
{
	cout << endl;
	cout << setiosflags(ios::left)
		<< ':'
		<< setw(8) << x.maNV
		<< ':'
		<< setw(10) << x.ho
		<< ':'
		<< setw(10) << x.tenLot
		<< ':'
		<< setw(10) << x.ten
		<< ':'
		<< setw(5) << x.namSinh
		<< ':'
		<< setw(4) << x.tdvh
		<< ':'
		<< setw(8) << x.luong
		<< ':';
}

void PrintList(LIST l)
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

int Read_File(char *filename, LIST &l)
{
	ifstream in(filename);
	if (!in)
		return 0;
	CreateList(l);
	Data x;
	char maNV[8];
	char ho[10];
	char tenLot[10];
	char ten[10];
	int namSinh;
	int tdvh;
	int luong;
	in >> maNV; strcpy_s(x.maNV, maNV);
	in >> ho; strcpy_s(x.ho, ho);
	in >> tenLot; strcpy_s(x.tenLot, tenLot);
	in >> ten; strcpy_s(x.ten, ten);
	in >> namSinh; x.namSinh = namSinh;
	in >> tdvh; x.tdvh = tdvh;
	in >> luong; x.luong = luong;
	InsertTail(l, x);
	while (!in.eof())
	{
		in >> maNV; strcpy_s(x.maNV, maNV);
		in >> ho; strcpy_s(x.ho, ho);
		in >> tenLot; strcpy_s(x.tenLot, tenLot);
		in >> ten; strcpy_s(x.ten, ten);
		in >> namSinh; x.namSinh = namSinh;
		in >> tdvh; x.tdvh = tdvh;
		in >> luong; x.luong = luong;
		InsertTail(l, x);
	}
	in.close();
	return 1;
}

//Tính tổng lương cần phải trả
int Sum_Salary(LIST l)
{
	NODE *p = l.pHead;
	int sum = 0;
	while (p != NULL)
	{
		sum += p->info.luong;
		p = p->pNext;
	}
	return sum;
}

//Tìm tiền lương cao nhất
int Highest_Salary(LIST l)
{
	NODE *p = l.pHead;
	int max = p->info.luong;
	p = p->pNext;
	while (p != NULL)
	{
		if (p->info.luong > max)
			max = p->info.luong;
		p = p->pNext;
	}
	return max;
}

//In danh sách các nhân viên có tiền lương cao nhất
void Print_List_byHighestSalary(LIST l)
{
	NODE *p = l.pHead;
	int max = Highest_Salary(l);
	Print_Title();
	while (p != NULL)
	{
		if (p->info.luong == max)
			Print_1Node(p->info);
		p = p->pNext;
	}
	Print_Line();
}

//In danh sách nhân viên bằng năm sinh cho trước
void Print_List_byYear(LIST l, int namSinh)
{
	NODE *p = l.pHead;
	Print_Title();
	while (p != NULL)
	{
		if (p->info.namSinh == namSinh)
			Print_1Node(p->info);
		p = p->pNext;
	}
	Print_Line();
}

//Tạo và copy danh sách src sang danh sách dst
void Copy(LIST &dst, LIST src)
{
	CreateList(dst);
	if (src.pHead == NULL)
	{
		cout << "\nDanh sach rong!";
		return;
	}
	NODE *p = src.pHead;
	Data x;
	while (p != NULL)
	{
		x = p->info;
		InsertTail(dst, x);
		p = p->pNext;
	}
}

//Sắp xếp tăng dần theo tiền lương
void Sort_Ascending_bySalary(LIST &l)
{
	NODE *p = l.pHead, *q;
	while (p != l.pTail)
	{
		q = p->pNext;
		while (q != NULL)
		{
			if (q->info.luong < p->info.luong)
				swap(p->info, q->info);
			q = q->pNext;
		}
		p = p->pNext;
	}
}

//Sắp xếp tăng dần theo tên, họ và tên lót
void Sort_Ascending_byTen_Ho_tenLot(LIST &l)
{
	NODE *p = l.pHead, *q;
	while (p != l.pTail)
	{
		q = p->pNext;
		while (q != NULL)
		{
			if (_strcmpi(q->info.ten, p->info.ten) < 0)
				swap(p->info, q->info);
			else if (_strcmpi(q->info.ten, p->info.ten) == 0)
				if (_strcmpi(q->info.ho, p->info.ho) < 0)
					swap(p->info, q->info);
				else if (_strcmpi(q->info.ho, p->info.ho) == 0)
					if (_strcmpi(q->info.tenLot, p->info.tenLot) < 0)
						swap(p->info, q->info);
			q = q->pNext;
		}
		p = p->pNext;
	}
}