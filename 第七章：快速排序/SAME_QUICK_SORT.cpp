#include<iostream>
using namespace std;
void partition(int A[], int p, int r, int &q, int &t)
{
	// A[q..t]中所有元素都等于主元素
	// A[p..q-1]中每个元素都小于主元素
	// A[t+1..r]中每个元素都大于主元素
	int x = A[r];
	q = p-1, t = r;
	for (int i = p; i < r; i++)
	{
		if (i >= t)
			break;
		while (A[i] > x && i < t)
			swap(A[--t], A[i]);
		if (A[i] < x)
			swap(A[++q], A[i]);
	}
	swap(A[t], A[r]);
	q++;
}
void quick_sort(int A[], int p, int r)
{
	if (p < r)
	{
		int q, t;
		partition(A, p, r, q, t);
		quick_sort(A, p, q - 1);
		quick_sort(A, t + 1, r);
	}
}
void main()
{
	while (1)
	{
		int n;
		cin >> n;
		int A[1000];
		for (int i = 0; i < n; i++)
			cin >> A[i];
		quick_sort(A, 0, n - 1);
		for (int i = 0; i<n; i++)
		{
			cout << A[i] << " ";
		}
		cout << endl;
	}
	
}