#include<stdio.h>
#include<string.h>
int f(int p[100],int m[100][100],int s[100][100],int n) {
	int i, j, k,r,t;
	for (r = 2; r <= n; r++) {
		//r�������������
		for (i = 1; i <= n - r + 1; i++) {
			//r �������������ʼ
			j = i + r - 1;
			m[i][j] = m[i][i] + m[i + 1][j] + p[i - 1] * p[i] * p[j];
			//j������������յ�
			//m�ָ�ΪAi(Ai+1......Aj)
			s[i][j] = i;
			//��ʼ���ָ��λ��ΪAi��
			for (k = i + 1; k <= j - 1; k++) {
				//kΪ�ָ��������λ��
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
	//p������������У�A1=p0*p1,p1ΪA2���У�A1����
	//s����������ʱ���������ڵ�λ��
	//m������������µ��������
	int n;
	//����������ĸ���
	scanf_s("%d", &n);
	for (int i = 0; i <=n; i++) {
		scanf_s("%d", &p[i]);//��ʾA1-An���к���
	}
	memset(m, 0, sizeof(int)*10000);
	//��ʼ��m����ȫΪ0
	int total = f(p, m,s, n);
	printf("%d\n", total);
	//������ٵĴ���
	//������ŵ�λ��
	x = s[1][n];
	temp = x;
	printf("���һ����˵�������");
	printf("%d��\n",x);
	printf("ǰ%d�ľ��������ʱ�����ŵ�λ���ڣ�",temp);
	while (1) {
		if (x - temp <= 2)
		{
			printf("�޷��ٷ�");
			break;
		}
		if (x - 1 <1)break;
		printf("%d ", s[1][x]);
		x = s[1][x];
	}
	printf("\n");
	//�������ŵ�λ��
	x = temp;
	//ʹx����Ϊ���һ�����ʱ��λ��
	printf("��%d�ľ��������ʱ�����ŵ�λ���ڣ�",n-temp);
	while (1)
	{
		if (n - temp<=2) {
			printf("�޷��ٷ�");
			break;
		}
		if (n - x < 1)break;                                 
		printf("%d ", s[temp][x]);
		x = s[temp][x];
	}
	printf("\n");
}