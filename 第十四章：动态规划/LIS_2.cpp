#include <iostream>
using namespace std;
const int maxn = 100;  
int length[maxn];   //length[i]表示以A[i]结尾的最长递增子串长度
void print(int A[], int n)
{
	int B[maxn];
	int m = 0;
	//找到具有最大长度字串的末端索引
	int max = -1;
	int index = -1;
	for (int i = 0; i < n; i++)
	{
		if (length[i] > max)
		{
			max = length[i];
			index = i;
		}
	}
	B[m++] = A[index];
	max--;
	for (int i = index - 1; i >= 0; i--)
	{
		if (A[i] <= B[m - 1] && length[i] == max)
		{
			B[m++] = A[i];
			max--;
		}
	}
	cout << "最长递增子数组是：" << endl;
	for (int i = m-1; i >= 0; i--)
		cout << B[i] << " ";
	cout << endl;
}
void LIS(int A[], int n)
{
	length[0] = 1;  //以A[0]结尾的最长递增子串长度是1
	for (int i = 1; i < n; i++)
	{
		int _max = 1;  //若都比A[i]大，则length[i]是1，所以初始化为1
		for (int j = 0; j < i; j++)
		{
			if (A[i] >= A[j])
			{
				int ls = length[j] + 1;
				if (ls > _max)
					_max = ls;
			}
		}
		length[i] = _max;
	}
	print(A, n);
}
int main()
{
	while (1)
	{
		cout << "输入数组大小：" << endl;
		int n;
		cin >> n;
		cout << "输入数组：" << endl;
		int A[maxn];
		for (int i = 0; i < n; i++)
			cin >> A[i];
		LIS(A, n);
	}
	return 0;
}