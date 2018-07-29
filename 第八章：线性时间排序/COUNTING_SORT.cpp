#include <iostream>
using namespace std;
const int maxn = 100;
void counting_sort(int A[], int n, int k)
{
	//n是数组A的大小，k是数组元素的最大值，即数组元素分布在0-k的区间
	int count_array[maxn];
	int result_array[maxn];
	for (int i = 0; i <= k; i++)
		count_array[i] = 0;
	for (int i = 0; i < n; i++)
		count_array[A[i]]++;
	for (int i = 1; i <= k; i++)
		count_array[i] += count_array[i - 1];
	for (int i = n - 1; i >= 0; i--)
	{
		result_array[count_array[A[i]] - 1] = A[i]; //减一是因为数组从0开始
		count_array[A[i]]--;
	}
	for (int i = 0; i < n; i++)
		A[i] = result_array[i];
}
int _max(int A[], int n)
{
	int max_number = -1;
	for (int i = 0; i < n; i++)
	{
		if (A[i] > max_number)
			max_number = A[i];
	}
	return max_number;
}
int main()
{
	while (1)
	{
		int n;
		cout << "输入数组大小：" << endl;
		cin >> n;
		cout << "输入数组：" << endl;
		int A[maxn];
		for (int i = 0; i < n; i++)
			cin >> A[i];
		int k = _max(A, n);
		counting_sort(A, n, k);
		for (int i = 0; i < n; i++)
			cout << A[i] << " ";
		cout << endl;
		
	}
	return 0;
}