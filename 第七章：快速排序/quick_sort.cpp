#include <iostream>
using namespace std;
int partition(int A[], int p, int r)
{
	int x = A[r];
	int i = p - 1;
	for (int j = p; j < r; j++)
	{
		if (A[j] <= x)
		{
			i++;
			int t = A[i];
			A[i] = A[j];
			A[j] = t;
		}
	}
	i++;
	int t = A[i];
	A[i] = A[r];
	A[r] = t;
	return i;
}
void quick_sort(int A[], int p, int r)
{
	if (p < r)
	{
		int q = partition(A, p, r);
		quick_sort(A, p, q - 1);
		quick_sort(A, q + 1, r);
	}
}

int main()
{
	while (1)
	{
		int n;
		cout << "输入数据的个数n：" << endl;
		cin >> n;
		int a[1000];
		cout << "输入n个数:" << endl;
		for (int i = 0; i < n; i++)
			cin >> a[i];
		quick_sort(a, 0, n - 1);
		for (int i = 0; i < n; i++)
			cout << a[i] << " ";
		cout << endl;
	}
	return 0;
}