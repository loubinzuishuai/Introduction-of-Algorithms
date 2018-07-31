#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
const int maxn = 100;
int randomized_partition(int A[], int left, int right)
{
	srand(time(NULL));
	int pivot = left + rand() % (right - left + 1);
	swap(A[pivot], A[right]);
	int i = left - 1;
	for (int j = left; j < right; j++)
	{
		if (A[j] <= A[right])
			swap(A[++i], A[j]);
	}
	swap(A[++i], A[right]);
	return i;
}
int randomized_select(int A[], int left, int right, int k)
{
	int pivot = randomized_partition(A, left, right);
	int left_size = pivot - left + 1; // left到pivot的长度，包括pivot
	if (k == left_size)
		return A[pivot];
	else if (k < left_size)
		return randomized_select(A, left, pivot - 1, k);
	else
		return randomized_select(A, pivot + 1, right, k - left_size);
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
		cout << "输入查找元素的顺序统计量：" << endl;
		int k;
		cin >> k;
		int value = randomized_select(A, 0, n-1, k);
		cout << value << endl;

	}
	return 0;
}