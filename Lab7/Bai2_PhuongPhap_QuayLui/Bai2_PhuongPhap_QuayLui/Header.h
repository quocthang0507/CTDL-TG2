//Chia m phan thuong cho nguoi tu vi tri thu n
void Chia(int m, int n)
{
	if (n > ::n)	//Da xet xong n nguoi
	{
		if (m == 0)	//Chia het toan bo phan thuong
		{
			r++;	//Tang so cach chia
			for (int i = 1; i <= ::n; i++) cout << P[i] << '\t';	//Xuat ra cach chia
			cout << endl;
		}
	}
	else
		for (int i = P[n - 1]; i >= 0; i--)	//So phan thuong cua nguoi sau phai nho hon hoac bang so phan thuong cua nguoi truoc
			if (m - i >= 0)					//So phan thuong con lai phai khong am
			{
				P[n] = i;
				Chia(m - i, n + 1);			//Chia so phan thuong con lai cho nhung nguoi sau
			}
}