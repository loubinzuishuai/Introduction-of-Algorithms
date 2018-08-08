#include <iostream>
using namespace std;
const int maxn = 100;
const int max_number = 999999;
int p[maxn];  //矩阵A[i]的行为p[i-1], 列为p[i];
int m[maxn][maxn];  //m[i][j]保存矩阵Ai ... Aj最优划分后的标量乘法次数
int s[maxn][maxn];  //s[i][j]保存矩阵Ai ... Aj最优化分的中间值k，即划分为Ai ...Ak和Ak ...Aj
//动态规划的思想，对于最优解的值，需要用到子问题的值，但是对于最优解，不需要用到子问题的解，只需要记录当前问题的划分点就够了
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
		cout << "输入矩阵数量:" << endl;
		int n;
		cin >> n;
		cout << "输入n个矩阵的行和列的值：" << endl;
		for (int i = 0; i < n; i++)
			cin >> p[i] >> p[i + 1];
		matrix_chain_order(p, n);
		print(1, n);
	}
	return 0;
}