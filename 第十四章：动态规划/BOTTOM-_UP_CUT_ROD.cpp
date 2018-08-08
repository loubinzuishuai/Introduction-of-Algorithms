#include <iostream>
using namespace std;
const int maxn = 100;
int profit[maxn]; //profit[n]��¼����Ϊn�ĸ������������
int pre_long[maxn]; //pre_long[n]��¼����Ϊn�ĸ����������ָ���ĵ�һ�θ����ĳ���
const int p[11] = { 0, 1, 5, 8, 9,10,17,17,20,24,25 }; //�۸��
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
		cout << "����������ȣ�";
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