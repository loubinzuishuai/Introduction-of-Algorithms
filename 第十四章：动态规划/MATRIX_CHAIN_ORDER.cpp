#include <iostream>
using namespace std;
const int maxn = 100;
const int max_number = 999999;
int p[maxn];  //����A[i]����Ϊp[i-1], ��Ϊp[i];
int m[maxn][maxn];  //m[i][j]�������Ai ... Aj���Ż��ֺ�ı����˷�����
int s[maxn][maxn];  //s[i][j]�������Ai ... Aj���Ż��ֵ��м�ֵk��������ΪAi ...Ak��Ak ...Aj
//��̬�滮��˼�룬�������Ž��ֵ����Ҫ�õ��������ֵ�����Ƕ������Ž⣬����Ҫ�õ�������Ľ⣬ֻ��Ҫ��¼��ǰ����Ļ��ֵ�͹���
void matrix_chain_order(int p[], int n)
{
	for (int i = 1; i <= n; i++)
		m[i][i] = 0;
	for (int l = 2; l <= n; l++)
	{
		for (int i = 1; i <= n + 1 - l; i++)
		{
			int j = i + l - 1;
			m[i][j] = max_number;
			for (int k = i; k < j; k++)
			{
				int count = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
				if (count < m[i][j])
				{
					m[i][j] = count;
					s[i][j] = k;
				}
			}
		}
	}
}
void print(int i, int j)
{
	if (i == j)
		cout << 'A' << i;
	else
	{
		cout << '(';
		print(i, s[i][j]);
		print(s[i][j] + 1, j);
		cout << ')';
	}
}
int main()
{
	while (1)
	{
		cout << "�����������:" << endl;
		int n;
		cin >> n;
		cout << "����n��������к��е�ֵ��" << endl;
		for (int i = 0; i < n; i++)
			cin >> p[i] >> p[i + 1];
		matrix_chain_order(p, n);
		print(1, n);
	}
	return 0;
}