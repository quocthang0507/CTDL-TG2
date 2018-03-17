typedef int Data;

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
	NODE *p;
	p = new NODE;
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

void PrintList(LIST l)
{
	NODE *p;
	if (l.pHead == NULL)
	{
		cout << "\nDanh sach rong!";
		return;
	}
	p = l.pHead;
	cout << endl;
	while (p != NULL)
	{
		cout << p->info << '\t';
		p = p->pNext;
	}
	cout << endl;
}

int Read_File(char *filename, LIST &l)
{
	ifstream in(filename);
	if (!in)
		return 0;
	CreateList(l);
	Data x;
	in >> x;
	InsertTail(l, x);
	while (!in.eof())
	{
		in >> x;
		InsertTail(l, x);
	}
	in.close();
	return 1;
}

int Search_Node_x_First(LIST l, Data x)
{
	NODE *p = new NODE;
	int i = 0;
	p = l.pHead;
	while ((p != NULL) && (p->info != x))
	{
		p = p->pNext;
		i++;
	}
	if (p == NULL)
		i = -1;
	return i;
}

int Search_Node_x_End(LIST l, Data x)
{
	NODE *p = new NODE;
	int kq = -1, i = 0;
	p = l.pHead;
	while (p != NULL)
	{
		if (p->info == x)
			kq = i;
		i++;
		p = p->pNext;
	}
	return kq;
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
		l.pHead == NULL;
	else
		l.pTail->pNext = NULL;
}

int RemoveNode_First(LIST &l, Data x)
{
	NODE *p = l.pHead;
	NODE *q = NULL;
	while (p != NULL)
	{
		if (p->info == x)
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
		q->pNext = p->pNext;//q->pNext=NULL
	}
	else //p == l.pHead;
	{
		l.pHead = p->pNext;
		if (l.pHead == NULL)
			l.pTail = NULL;
	}
	delete p;
	return 1;
}

void Remove_x(LIST &l, Data x)
{
	while (RemoveNode_First(l, x));
}

void RemoveList(LIST &l)
{
	NODE *p;
	while (l.pHead != NULL)
	{
		p = l.pHead;
		l.pHead = p->pNext;
		delete p;
	}
	l.pTail = NULL;
}

int Count_Node(LIST l)
{
	NODE *p;
	int count = 0;
	p = l.pHead;
	while (p != NULL)
	{
		p = p->pNext;
		count++;
	}
	return count;
}

int Count_x(LIST l, Data x)
{
	NODE *p;
	int count = 0;
	p = l.pHead;
	while (p != NULL)
	{
		if (p->info == x)
			count++;
		p = p->pNext;
	}
	return count;
}

int Min_Node(LIST l)
{
	NODE *p = l.pHead;
	int min = p->info;
	while (p != NULL)
	{
		if (min > p->info)
			min = p->info;
		p = p->pNext;
	}
	return min;
}

bool Prime_Num(Data x)
{
	int kq = true;
	if (x > 0)
	{
		if (x > 2)
		{
			int t = (int)sqrt(x);
			for (int i = 2; i <= t; i++)
				if (x%i == 0)
				{
					kq = false;
					break;
				}
		}
	}
	else kq = false;
	return kq;
}

int Count_Prime(LIST l)
{
	NODE *p = l.pHead;
	int count = 0;
	while (p != NULL)
	{
		if (Prime_Num(p->info))
			count++;
		p = p->pNext;
	}
	return count;
}

int Max_Node(LIST l)
{
	NODE *p = l.pHead;
	int max = p->info;
	while (p != NULL)
	{
		if (max < p->info)
			max = p->info;
		p = p->pNext;
	}
	return max;
}

int Count_Max(LIST l)
{
	return Count_x(l, Max_Node(l));
}

int Sum(LIST l)
{
	int sum = 0;
	NODE *p = l.pHead;
	while (p != NULL)
	{
		sum += p->info;
		p = p->pNext;
	}
	return sum;
}

int Sum_Distinct(LIST l)
{
	NODE *p = l.pHead;
	LIST t;
	CreateList(t);
	while (p != NULL)
	{
		if (Count_x(t, p->info) == 0)
			InsertTail(t, p->info);
		p = p->pNext;
	}
	return Sum(t);
}

int Sum_Unique(LIST l)
{
	NODE *p = l.pHead;
	int sum = 0;
	while (p != NULL)
	{
		if (Count_x(l, p->info) == 1)
			sum += p->info;
		p = p->pNext;
	}
	return sum;
}

void Sort_Ascending(LIST &l)
{
	NODE *p, *q;
	p = l.pHead;
	while (p != l.pTail)
	{
		q = p->pNext;
		while (q != NULL)
		{
			if (q->info < p->info)
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
	NODE *p;
	Data x;
	for (p = src.pHead; p != NULL; p = p->pNext)
	{
		x = p->info;
		InsertTail(dst, x);
	}
}

void Reserve(LIST &dst, LIST src)
{
	NODE *p = src.pHead;
	CreateList(dst);
	while (p != NULL)
	{
		InsertHead(dst, p->info);
		p = p->pNext;
	}
}

void Distribute(LIST &dst1, LIST &dst2, LIST src)
{
	CreateList(dst1);
	CreateList(dst2);
	NODE *p = src.pHead;
	int flag = 0;
	while (p != NULL)
	{
		if (flag % 2 == 0)
			InsertTail(dst1, p->info);
		else InsertTail(dst2, p->info);
		flag++;
		p = p->pNext;
	}
}

void Divide(LIST &dst1, LIST &dst2, LIST src)
{
	CreateList(dst1);
	CreateList(dst2);
	NODE *p = src.pHead;
	int length = Count_Node(src);
	int t = floor((float)length / 2);
	for (int i = 0; i < t; i++, p = p->pNext)
	{
		InsertTail(dst1, p->info);
	}
	for (; p != NULL; p = p->pNext)
		InsertTail(dst2, p->info);
}