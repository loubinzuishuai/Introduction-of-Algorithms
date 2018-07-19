#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
const int maxn = 1000; //最大数组
const int maxnumber = 9999999; //最大整数

void merge(int *A, int *key, int left, int mid, int right)
{
	int key1[maxn];
	int key2[maxn];
	int A1[maxn], A2[maxn];
	int i;
	for (i = left; i <= mid; i++)
	{
		key1[i - left] = key[i];
		A1[i - left] = A[i];
	}
	key1[i - left] = maxnumber;
	for (i = mid + 1; i <= right; i++)
	{
		key2[i - mid - 1] = key[i];
		A2[i - mid - 1] = A[i];
	}
	key2[i - mid - 1] = maxnumber;
	int key1_i = 0, key2_i = 0;
	for (i = left; i <= right; i++)
	{
		if (key1[key1_i] <= key2[key2_i])
		{
			A[i] = A1[key1_i];
			key[i] = key1[key1_i];
			key1_i++;
		}
		else
		{
			A[i] = A2[key2_i];
			key[i] = key2[key2_i];
			key2_i++;
		}
	}
}

void merge_sort(int *A, int *key, int left, int right)
{
	if (left < right)
	{
		int mid = (left + right) / 2;
		merge_sort(A, key, left, mid);
		merge_sort(A, key, mid + 1, right);
		merge(A, key, left, mid, right);
	}
}
void permute_by_sorting(int *A, int n)
{
	int key[maxn];
	int nn = n*n*n;
	for (int i = 0; i < n; i++)
	{
		int a = rand() % nn;
		key[i] = a;
	}

	merge_sort(A, key, 0, n - 1);
}



int main()
{
	while (1)
	{
		int n;
		cout << "输入数组个数:" << endl;
		cin >> n;
		cout << "输入待随机化的数组:" << endl;
		int A[maxn];
		for (int i = 0; i < n; i++)
		{
			cin >> A[i];
		}
		permute_by_sorting(A, n);
		cout << "随机化后的数组如下:" << endl;
		for (int i = 0; i < n; i++)
			cout << A[i] << " ";
		cout << endl;
	}
	return 0;
}