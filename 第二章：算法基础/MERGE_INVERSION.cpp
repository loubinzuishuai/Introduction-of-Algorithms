#include <iostream>
using namespace std;
const int maxn = 1000;
const int max_count = 2147483647;
int inversion_between(int *A, int left, int mid, int right)
{
	//ͳ������Ը������������Ҫ���һ��������������飬�ڶ����������Ҷ�����
	int a1[maxn], a2[maxn];
	for (int i = left; i <= mid; i++)
		a1[i - left] = A[i];
	int n1 = mid - left + 1; //����a1��С
	a1[n1] = max_count; //�ڱ�
	for (int i = mid + 1; i <= right; i++)
		a2[i - mid - 1] = A[i];
	int n2 = right - mid; //����a2��С
	a2[n2] = max_count;//�ڱ�
	int count = 0; //��¼������a2�й鲢������A��Ԫ�ظ���
	int inversion_count = 0; //��¼�����
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