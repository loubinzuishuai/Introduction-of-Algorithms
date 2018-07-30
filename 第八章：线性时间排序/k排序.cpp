#include <iostream>
using namespace std;
const int maxn = 100;
int partition(int A[], int left, int right)
{
	int key = A[right];
	int i = left - 1;
	for (int j = left; j < right; j++)
	{
		if (A[j] <= key)
			swap(A[++i], A[j]);
	}
	swap(A[++i], A[right]);
	return i;
}
void quick_sort(int A[], int left, int right)
{
	if (left < right)
	{
		int mid = partition(A, left, right);
		quick_sort(A, left, mid - 1);
		quick_sort(A, mid + 1, right);
	}
}
void k_sort(int A[], int n, int k)
{
	int B[maxn]; 
	for (int i = 0; i < k; i++)
	{
		int count = 0;
		for (int j = i; j < n; j += k)
			B[count++] = A[j];
		quick_sort(B, 0, count-1);
		count = 0;
		for (int j = i; j < n; j += k)
			A[j] = B[count++];
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
		cout << "输入K值：" << endl;
		int k;
		cin >> k;
		k_sort(A, n, k);
		for (int i = 0; i < n; i++)
			cout << A[i] << " ";
		cout << endl;

	}
	return 0;
}