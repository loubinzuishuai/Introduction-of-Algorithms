#include <iostream>
#include <string>
using namespace std;
const int maxn = 100;
int length[maxn][maxn];
int partition(int A[], int low, int high)
{
	int x = A[high];
	int i = low - 1;
	for (int j = low; j < high; j++)
	{
		if (A[j] <= x)
			swap(A[j], A[++i]);
	}
	swap(A[high], A[++i]);
	return i;
}
void quicksort(int A[], int low, int high)
{
	if (low > high)
		return;
	int mid = partition(A, low, high);
	quicksort(A, low, mid - 1);
	quicksort(A, mid + 1, high);
}
int get_substring(int A[], int n, int B[], int m, int result[])
{
	if (n == 0 || m == 0)
		return 0;
	int _length;
	if (A[n - 1] == B[m - 1])
	{
		_length = get_substring(A, n - 1, B, m - 1, result) + 1;
		result[_length - 1] = A[n - 1];
	}
	else if (length[n - 1][m] >= length[n][m - 1])
		_length = get_substring(A, n - 1, B, m, result);
	else
		_length = get_substring(A, n, B, m - 1, result);
	return _length;
}
void LCS(int A[], int n, int B[], int m, int result[], int &result_n)
{
	//����������д���result������
	
	//����ʵ���Ǵ����ڴ�����0-(n-1)�еģ�����������һ�±任����Ϊ�����������1��n��
	//ֻҪȡ����Ԫ��ʱ��������һ������
	for (int i = 0; i <= n; i++)
		length[i][0] = 0;
	for (int j = 0; j <= m; j++)
		length[0][j] = 0;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if (A[i - 1] == B[j - 1])  //����������һȡ����i�͵�j��Ԫ��
				length[i][j] = length[i - 1][j - 1] + 1;
			else if (length[i - 1][j] >= length[i][j - 1])
				length[i][j] = length[i - 1][j];
			else
				length[i][j] = length[i][j - 1];
		}
	}
	result_n = get_substring(A, n, B,m, result);
}
void LIS(int A[], int n, int result[], int &result_n)
{
	//�������������
	int B[maxn];
	for (int i = 0; i < n; i++)
		B[i] = A[i];
	quicksort(B, 0, n-1);
	LCS(A, n, B, n, result, result_n);
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
		int result[maxn];
		int result_n = 0;
		for (int i = 0; i < n; i++)
			cin >> A[i];
		LIS(A, n, result, result_n);
		cout << "������������ǣ�" << endl;
		for (int i = 0; i < result_n; i++)
			cout << result[i] << " ";
		cout << endl;
	}
	return 0;
}