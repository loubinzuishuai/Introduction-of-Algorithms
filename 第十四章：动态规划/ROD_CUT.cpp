#include <iostream>
using namespace std;
const int maxn = 100;
int profit[maxn]; //profit[n]��¼����Ϊn�ĸ������������
int pre_long[maxn]; //pre_long[n]��¼����Ϊn�ĸ����������ָ���ĵ�һ�θ����ĳ���
const int p[11] = { 0, 1, 5, 8, 9,10,17,17,20,4,30 }; //�۸��
int cut_rod(int k)
{
	if (profit[k] > 0)
		return profit[k];
	if (k == 1)
	{
		pre_long[k] = 1;
		profit[k] = p[k];
		return p[k];
	}
	int q_max = -1;
	int pre = 0;
	for (int i = 1; i < k - 1; i++)
	{
		int q = cut_rod(i) + cut_rod(k-i);
		if (q > q_max)
		{
			q_max = q;
			pre = i;
		}
	}
	if (k <= 10 && q_max <= p[k])
	{
		pre_long[k] = k;
		profit[k] = p[k];
	}
	else
	{
		pre_long[k] = pre;
		profit[k] = q_max;
	}
	return profit[k];
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
		cout<<cut_rod(n)<<endl;
		while (n > 0)
		{
			cout << pre_long[n] << " ";
			n = n - pre_long[n];
		}
		cout << endl;
	}
	return 0;
}