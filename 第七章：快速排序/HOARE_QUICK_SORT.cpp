#include <iostream>
using namespace std;
int PARTITION(int A[], int p, int r)
{
	int x = A[p];
	int i = p - 1;
	int j = r + 1;
	while (1)
	{
		do
		{
			j--;
		} while (A[j]>x);
		do
		{
			i++;
		} while (A[i]<x);
		if (i<j)
		{
			swap(A[i], A[j]);
		}
		else return j;
	}
}

void QUICKSORT(int A[], int p, int r)
{
	if (p<r)
	{
		int q = PARTITION(A, p, r);
		QUICKSORT(A, p, q);
		QUICKSORT(A, q + 1, r);
	}
}

void main()
{
	int A[12] = {13,19,9,5,12,8,7,4,11,2,6,21 };
	QUICKSORT(A, 0, 11);//K=3
	for (int i = 0; i<12; i++)
	{
		cout << A[i] << " ";
	}
	cout << endl;
	while (1);
}