#include <iostream>
using namespace std;
const int maxn = 100;
void counting_sort(int A[], int C[], int B[], int n)
{
	//数组A,B,C的位置是对应的，利用B数组来计数排序位置，然后对A,C数组移动排序
	//增加C数组的目的是因为在radix_sort函数中需要用C数组来取得每一位,C数组和A
	//数组得同时移动
	int count_array[10];  
	int result_A[maxn];
	int result_C[maxn];
	for (int i = 0; i < 10; i++)
		count_array[i] = 0;
	for (int i = 0; i < n; i++)
		count_array[B[i]]++;
	for (int i = 1; i < 10; i++)
		count_array[i] += count_array[i - 1];
	for (int i = n-1; i >= 0; i--)
	{
		result_A[count_array[B[i]] - 1] = A[i];
		result_C[count_array[B[i]] - 1] = C[i];
		count_array[B[i]]--;
	}
	for (int i = 0; i < n; i++)
	{
		A[i] = result_A[i];
		C[i] = result_C[i];
	}
}
void radix_sort(int A[], int n)
{
	//这里假设待排序的均是三位数
	int C[maxn];  //因为基数排序会破坏原数组，所以需要复制原数组到C数组
	for (int i = 0; i < n; i++)
		C[i] = A[i];
	for (int i = 0; i < 3; i++)
	{
		int B[maxn];
		for (int j = 0; j < n; j++)
		{
			B[j] =C[j] % 10;
			C[j] /= 10;
		}
		counting_sort(A, C, B, n);
	}
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
		radix_sort(A, n);
		for (int i = 0; i < n; i++)
			cout << A[i] << " ";
		cout << endl;

	}
	return 0;
}