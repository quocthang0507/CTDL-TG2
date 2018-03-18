struct SinhVien
{
	char maSV[8];
	char ho[10];
	char tenLot[10];
	char ten[10];
	int namSinh;
};

typedef SinhVien Data;

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
	for (size_t i = 0; i < 47; i++)
		cout << '=';
	cout << ':';
}

void Print_Title()
{
	Print_Line();
	cout << endl;
	cout << setiosflags(ios::left)
		<< ':'
		<< setw(8) << "Ma SV"
		<< ':'
		<< setw(10) << "Ho"
		<< ':'
		<< setw(10) << "Ten Lot"
		<< ':'
		<< setw(10) << "Ten"
		<< ':'
		<< setw(5) << "NS"
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
		<< setw(10) << x.ho
		<< ':'
		<< setw(10) << x.tenLot
		<< ':'
		<< setw(10) << x.ten
		<< ':'
		<< setw(5) << x.namSinh
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
	char maSV[8];
	char ho[10];
	char tenLot[10];
	char ten[10];
	int namSinh;
	in >> maSV; strcpy_s(x.maSV, maSV);
	in >> ho; strcpy_s(x.ho, ho);
	in >> tenLot; strcpy_s(x.tenLot, tenLot);
	in >> ten; strcpy_s(x.ten, ten);
	in >> namSinh; x.namSinh = namSinh;
	InsertTail(l, x);
	while (!in.eof())
	{
		in >> maSV; strcpy_s(x.maSV, maSV);
		in >> ho; strcpy_s(x.ho, ho);
		in >> tenLot; strcpy_s(x.tenLot, tenLot);
		in >> ten; strcpy_s(x.ten, ten);
		in >> namSinh; x.namSinh = namSinh;
		InsertTail(l, x);
	}
	in.close();
	return 1;
}

void InsertHead(LIST &l, Data x)
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
		new_ele->pNext = l.pHead;
		l.pHead = new_ele;
	}
}

void RemoveHead(LIST &l)
{
	NODE *p;
	if (l.pHead == NULL)
	{
		cout << "\nDanh sach rong! Khong xoa duoc";
		return;
	}
	p = l.pHead;
	l.pHead = l.pHead->pNext;
	delete p;
	if (l.pHead == NULL)
		l.pTail == NULL;
}

void RemoveTail(LIST &l)
{
	NODE *p, *q;
	if (l.pHead == NULL)
	{
		cout << "\nDanh sach rong! Khong xoa duoc";
		return;
	}
	p = l.pHead;
	q = NULL;
	while (p != l.pTail)
	{
		q = p;
		p = p->pNext;
	}
	l.pTail = q;
	delete p;
	if (l.pTail == NULL)
		l.pHead = NULL;
	else
		l.pTail->pNext = NULL;
}

int RemoveNode_First(LIST &l, char ten[10])
{
	NODE *p = l.pHead, *q = NULL;
	while (p != NULL)
	{
		if (_strcmpi(p->info.ten, ten) == 0)
			break;
		q = p;
		p = p->pNext;
	}
	if (p == NULL)
		return 0;
	if (q != NULL)
	{
		if (p == l.pTail)
			l.pTail = q;
		q->pNext = p->pNext;
	}
	else
	{
		l.pHead = p->pNext;
		if (l.pHead == NULL)
			l.pTail = NULL;
	}
	delete p;
	return 1;
}

void Remove_x(LIST &l, char ten[10])
{
	while (RemoveNode_First(l, ten));
}

void Print_List_byName(LIST l, char ten[10])
{
	NODE *p = l.pHead;
	Print_Title();
	while (p != NULL)
	{
		if (_strcmpi(p->info.ten, ten) == 0)
			Print_1Node(p->info);
		p = p->pNext;
	}
	Print_Line();
}

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

int Min_Year(LIST l)
{
	NODE *p = l.pHead;
	int min = p->info.namSinh;
	p = p->pNext;
	while (p != NULL)
	{
		if (min > p->info.namSinh)
			min = p->info.namSinh;
		p = p->pNext;
	}
	return min;
}

void Print_List_byMinYear(LIST l)
{
	int min = Min_Year(l);
	Print_List_byYear(l, min);
}

void Sort_Ascending_byYear(LIST &l)
{
	NODE *p = l.pHead, *q;
	while (p != l.pTail)
	{
		q = p->pNext;
		while (q != NULL)
		{
			if (q->info.namSinh < p->info.namSinh)
				swap(p->info, q->info);
			q = q->pNext;
		}
		p = p->pNext;
	}
}

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
	}
}