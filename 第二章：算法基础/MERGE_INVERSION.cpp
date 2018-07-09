#include <iostream>
using namespace std;
const int maxn = 1000;
const int max_count = 2147483647;
int inversion_between(int *A, int left, int mid, int right)
{
	//统计逆序对个数，该逆序对要求第一个数来自左段数组，第二个数来自右段数组
	int a1[maxn], a2[maxn];
	for (int i = left; i <= mid; i++)
		a1[i - left] = A[i];
	int n1 = mid - left + 1; //数组a1大小
	a1[n1] = max_count; //哨兵
	for (int i = mid + 1; i <= right; i++)
		a2[i - mid - 1] = A[i];
	int n2 = right - mid; //数组a2大小
	a2[n2] = max_count;//哨兵
	int count = 0; //记录从数组a2中归并到数组A的元素个数
	int inversion_count = 0; //记录逆序对
	int i = 0, j = 0;
	for (int k = left; k <= right; k++)
	{
		if (a1[i] <= a2[j])
		{
			A[k] = a1[i++];
			inversion_count += count;
		}
		else
		{
			A[k] = a2[j++];
			count++;
		}

	}
	return inversion_count;
}
int inversion(int *A, int left, int right)
{
	if (left < right)
	{
		int mid = (left + right) / 2;
		int n1 = inversion(A, left, mid);
		int n2 = inversion(A, mid + 1, right);
		int n = inversion_between(A, left, mid, right);
		return n + n1 + n2;
	}
	else
		return 0;
}

int main()
{
	while (1)
	{
		int n;
		cin >> n;
		int a[maxn];
		for (int i = 0; i < n; i++)
			cin >> a[i];
		cout << inversion(a, 0, n - 1) << endl;
	}
	return 0;
}