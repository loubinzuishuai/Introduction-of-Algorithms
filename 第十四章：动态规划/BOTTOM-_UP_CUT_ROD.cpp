#include <iostream>
using namespace std;
const int maxn = 100;
int profit[maxn]; //profit[n]记录长度为n的钢条的最大收益
int pre_long[maxn]; //pre_long[n]记录长度为n的钢条最大收益分割方法的第一段钢条的长度
const int p[11] = { 0, 1, 5, 8, 9,10,17,17,20,24,25 }; //价格表
int min(int x, int y)
{
	return x < y ? x : y;
}
int bottom_up_cut_rod(int n)
{
	for (int i = 0; i < n; i++)
	{ 
		profit[i] = -1;
		pre_long[i] = -1;
	}
	profit[0] = 0;
	for (int j = 1; j <= n; j++)
	{
		for (int i = 1; i <= min(j, 10); i++)
		{
			int q = p[i] + profit[j - i];
			if (q > profit[j])
			{
				profit[j] = q;
				pre_long[j] = i;
			}
		}
	}
	return profit[n];
}
int main()
{
	while (1)
	{
		cout << "输入钢条长度：";
		int n;
		cin >> n;
		for (int i = 0; i < n; i++)
			profit[i] = -1;
		cout << bottom_up_cut_rod(n) << endl;
		while (n > 0)
		{
			cout << pre_long[n] << " ";
			n = n - pre_long[n];
		}
		cout << endl;
	}
	return 0;
}