#include <iostream>
using namespace std;
const int maxn = 100;
void counting_sort(int A[], int C[], int B[], int n)
{
	//����A,B,C��λ���Ƕ�Ӧ�ģ�����B��������������λ�ã�Ȼ���A,C�����ƶ�����
	//����C�����Ŀ������Ϊ��radix_sort��������Ҫ��C������ȡ��ÿһλ,C�����A
	//�����ͬʱ�ƶ�
	int count_array[10];  
	int result_A[maxn];
	int result_C[maxn];
	for (int i = 0; i < 10; i++)
		count_array[i] = 0;
	for (int i = 0; i < n; i++)
		count_array[B[i]]++;
	for (int i = 1; i < 10; i++)
		count_array[i] += count_array[i - 1];
	for (int i = n-1; i >= 0; i--)
	{
		result_A[count_array[B[i]] - 1] = A[i];
		result_C[count_array[B[i]] - 1] = C[i];
		count_array[B[i]]--;
	}
	for (int i = 0; i < n; i++)
	{
		A[i] = result_A[i];
		C[i] = result_C[i];
	}
}
void radix_sort(int A[], int n)
{
	//������������ľ�����λ��
	int C[maxn];  //��Ϊ����������ƻ�ԭ���飬������Ҫ����ԭ���鵽C����
	for (int i = 0; i < n; i++)
		C[i] = A[i];
	for (int i = 0; i < 3; i++)
	{
		int B[maxn];
		for (int j = 0; j < n; j++)
		{
			B[j] =C[j] % 10;
			C[j] /= 10;
		}
		counting_sort(A, C, B, n);
	}
}
int main()
{
	while (1)
	{
		int n;
		cout << "���������С��" << endl;
		cin >> n;
		cout << "�������飺" << endl;
		int A[maxn];
		for (int i = 0; i < n; i++)
			cin >> A[i];
		radix_sort(A, n);
		for (int i = 0; i < n; i++)
			cout << A[i] << " ";
		cout << endl;

	}
	return 0;
}