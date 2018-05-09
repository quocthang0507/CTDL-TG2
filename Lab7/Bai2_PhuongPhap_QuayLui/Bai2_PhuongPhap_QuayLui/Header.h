//Chia m phần thưởng cho người từ vị trí n
void Chia(int m, int n)
{
	if (n > ::n)	//Nếu đã xét xong, tức là vị trí xét (n) > số người thực tế (::n)
	{
		if (m == 0)	//Và đã chia hết m phần thưởng
		{
			r++;	//Thì tăng số cách chia r lên
			for (int i = 1; i <= ::n; i++) cout << P[i] << '\t';	//Xuất ra cách chia đó
			cout << endl;
		}
	}
	else
		for (int i = P[n - 1]; i >= 0; i--)	//Số phần thưởng của người phía sau phải nhỏ hơn hoặc bằng số phần thưởng của người phía trước
			if (m - i >= 0)					//Số phần thưởng còn lại (m - i) phải không âm
			{
				P[n] = i;					//Ghi nhận lại số phần thưởng i cho người thứ n
				Chia(m - i, n + 1);			//Chia tiếp số phần thưởng còn lại (m - i) cho người tiếp theo (n + 1)
			}
}