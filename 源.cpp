#include<stdio.h>
#include<string.h>
int f(int p[100],int m[100][100],int s[100][100],int n) {
	int i, j, k,r,t;
	for (r = 2; r <= n; r++) {
		//r代表矩阵链长度
		for (i = 1; i <= n - r + 1; i++) {
			//r 代表矩阵链的起始
			j = i + r - 1;
			m[i][j] = m[i][i] + m[i + 1][j] + p[i - 1] * p[i] * p[j];
			//j代表矩阵链的终点
			//m分割为Ai(Ai+1......Aj)
			s[i][j] = i;
			//初始化分割的位置为Ai处
			for (k = i + 1; k <= j - 1; k++) {
				//k为分割矩阵链的位置
				t = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
				if (t < m[i][j]) {
					m[i][j] = t;
					s[i][j] = k;
				}
			}
	}
	}
	return m[1][n];
}
int main() {
	int p[100], s[100][100],m[100][100],x,temp;
	//p代表矩阵链的行，A1=p0*p1,p1为A2的行，A1的列
	//s代表矩阵相乘时，括号所在的位置
	//m代表最优情况下的运算次数
	int n;
	//代表矩阵链的个数
	scanf_s("%d", &n);
	for (int i = 0; i <=n; i++) {
		scanf_s("%d", &p[i]);//表示A1-An的行和列
	}
	memset(m, 0, sizeof(int)*10000);
	//初始化m数组全为0
	int total = f(p, m,s, n);
	printf("%d\n", total);
	//输出最少的次数
	//输出括号的位置
	x = s[1][n];
	temp = x;
	printf("最后一次相乘的括号在");
	printf("%d处\n",x);
	printf("前%d的矩阵链相乘时，括号的位置在：",temp);
	while (1) {
		if (x - temp <= 2)
		{
			printf("无法再分");
			break;
		}
		if (x - 1 <1)break;
		printf("%d ", s[1][x]);
		x = s[1][x];
	}
	printf("\n");
	//后半段括号的位置
	x = temp;
	//使x重新为最后一次相乘时的位置
	printf("后%d的矩阵链相乘时，括号的位置在：",n-temp);
	while (1)
	{
		if (n - temp<=2) {
			printf("无法再分");
			break;
		}
		if (n - x < 1)break;                                 
		printf("%d ", s[temp][x]);
		x = s[temp][x];
	}
	printf("\n");
}