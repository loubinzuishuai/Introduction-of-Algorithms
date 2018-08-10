#include <iostream>
using namespace std;
const int maxn = 100;  
int length[maxn];   //length[i]��ʾ��A[i]��β��������Ӵ�����
void print(int A[], int n)
{
	int B[maxn];
	int m = 0;
	//�ҵ�������󳤶��ִ���ĩ������
	int max = -1;
	int index = -1;
	for (int i = 0; i < n; i++)
	{
		if (length[i] > max)
		{
			max = length[i];
			index = i;
		}
	}
	B[m++] = A[index];
	max--;
	for (int i = index - 1; i >= 0; i--)
	{
		if (A[i] <= B[m - 1] && length[i] == max)
		{
			B[m++] = A[i];
			max--;
		}
	}
	cout << "������������ǣ�" << endl;
	for (int i = m-1; i >= 0; i--)
		cout << B[i] << " ";
	cout << endl;
}
void LIS(int A[], int n)
{
	length[0] = 1;  //��A[0]��β��������Ӵ�������1
	for (int i = 1; i < n; i++)
	{
		int _max = 1;  //������A[i]����length[i]��1�����Գ�ʼ��Ϊ1
		for (int j = 0; j < i; j++)
		{
			if (A[i] >= A[j])
			{
				int ls = length[j] + 1;
				if (ls > _max)
					_max = ls;
			}
		}
		length[i] = _max;
	}
	print(A, n);
}
int main()
{
	while (1)
	{
		cout << "���������С��" << endl;
		int n;
		cin >> n;
		cout << "�������飺" << endl;
		int A[maxn];
		for (int i = 0; i < n; i++)
			cin >> A[i];
		LIS(A, n);
	}
	return 0;
}