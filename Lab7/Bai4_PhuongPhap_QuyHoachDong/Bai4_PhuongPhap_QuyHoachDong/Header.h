#define MAX 100

typedef int MangKQ[MAX][MAX];

void ChiaPhanThuong(MangKQ c, int m, int n)
{
	//Co i phan thuong ma chia cho 0 hoc sinh thi co 0 cach chia
	for (size_t i = 1; i <= m; i++)
		c[i][0] = 0;
	//Co 0 phan thuong ma chia cho j hoc sinh thi co 1 cach chia
	for (size_t j = 1; j <= n; j++)
		c[0][j] = 1;
	for (size_t i = 1; i <= m; i++)
	{
		for (size_t j = 1; j <= n; j++)
		{
			//Neu so phan thuong < so hoc sinh thi hoc sinh tu [i+1] den j se khong co phan thuong
			//So cach chia i phan thuong cho j hoc sinh bang voi so cach chia i phan thuong cho i hoc sinh
			if (i < j)
				c[i][j] = c[i][i];
			//Neu so phan thuong > so hoc sinh
			else
				/*TH1: người cuối cùng không có phần thưởng, tức là chỉ chia i phần
				thưởng cho j-1 người, trường hợp này số cách chia là C[ i ][ j-1 ]
				
				TH2: người cuối cùng chắc chắn có phần thưởng, khi đó ta sẽ lấy j phần
				thưởng chia cho j người, mỗi người sẽ có được 1 phần thưởng trước, lúc này
				còn lại i - j phần thưởng, tiếp tục lấy số còn lại này chia cho j người, trường
				hợp này số cách chia là C[i - j][j].*/
				c[i][j] = c[i][j - 1] + c[i - j][j];
		}
	}
}