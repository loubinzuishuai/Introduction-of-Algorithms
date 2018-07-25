#include <iostream>
#include <cstdlib>
#include<ctime>
using namespace std;
int partition(int A[], int p, int r);
void exchange(int A[], int i, int j)
{
	int t = A[i];
	A[i] = A[j];
	A[j] = t;
}
int random_partition(int A[], int p, int r)
{
	srand(unsigned(time(NULL)));
	int k = p + rand() % (r - p + 1);
	exchange(A, k, r);
	return partition(A, p, r);
}
int partition(int A[], int p, int r)
{
	int x = A[r];
	int i = p - 1;
	for (int j = p; j < r; j++)
		if (A[j] <= x)
			exchange(A, ++i, j);
	exchange(A, ++i, r);
	return i;
}
void random_quick_sort(int A[], int p, int r)
{
	if (p < r)
	{
		int q = random_partition(A, p, r);
		random_quick_sort(A, p, q - 1);
		random_quick_sort(A, q + 1, r);
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
		random_quick_sort(a, 0, n - 1);
		for (int i = 0; i < n; i++)
			cout << a[i] << " ";
		cout << endl;
	}
	return 0;
}