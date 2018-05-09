#define MAX 100

typedef int MangKQ[MAX][MAX];

void ChiaPhanThuong(MangKQ c, int m, int n)
{
	//Có i phần thưởng mà chia cho 0 học sinh thì có 0 cách chia
	for (size_t i = 1; i <= m; i++)
		c[i][0] = 0;
	//Có 0 phần thưởng mà chia cho j học sinh thì có 1 cách chia
	for (size_t j = 1; j <= n; j++)
		c[0][j] = 1;
	for (size_t i = 1; i <= m; i++)
	{
		for (size_t j = 1; j <= n; j++)
		{
			//Nếu số phần thưởng < số học sinh thì học sinh từ [i+1] đến j sẽ không có phần thưởng
			//Như vậy, số cách chia i phần thưởng cho j học sinh bằng với số cách chia i phần thưởng cho i học sinh
			if (i < j)
				c[i][j] = c[i][i];
			//Nếu số phần thưởng > số học sinh
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