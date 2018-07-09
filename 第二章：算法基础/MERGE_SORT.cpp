#include <iostream>
using namespace std;
const int maxn = 1000;
const int max_count = 2147483647;  //整型最大值
void merge(int *a, int left, int mid, int right)
{
	int a1[maxn];
	int a2[maxn];
	int n1 = mid - left + 1;
	int n2 = right - mid;
	for (int i = 0; i < n1; i++)
		a1[i] = a[left + i];
	a1[n1] = max_count;
	for (int i = 0; i < n2; i++)
		a2[i] = a[mid + 1 + i];
	a2[n2] = max_count;
	int i = 0, j = 0;
	for (int k = left; k <= right; k++)
	{
		if (a1[i] < a2[j])
			a[k] = a1[i++];
		else
			a[k] = a2[j++];
	}
}
void merge_sort(int *a, int left, int right)
{
	if (left < right)
	{
		int mid = (left + right) / 2;
		merge_sort(a, left, mid);
		merge_sort(a, mid + 1, right);
		merge(a, left, mid, right);
	}
}
int main()
{
	while (1)
	{
		int n;
		cout << "输入数据的个数n：" << endl;
		cin >> n;
		int a[maxn];
		cout << "输入n个数:" << endl;
		for (int i = 0; i < n; i++)
			cin >> a[i];
		merge_sort(a, 0, n - 1);
		for (int i = 0; i < n; i++)
			cout<< a[i] << " ";
		cout << endl;
	}
	return 0;
}