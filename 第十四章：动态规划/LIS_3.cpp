#include <iostream>
using namespace std;
const int maxn = 100;
int min_end[maxn]; //min_end[i]��ʾ����Ϊi���Ӵ�����Сĩ��
int pre[maxn];//pre[i]��ʾ��i������ǰ����������
int index[maxn];  //��ǰ�ҵ��ĳ���Ϊi�ĵ��������е���Сĩβ������
int search(int x, int low, int high)
{
	//ѭ������ʽ��֤ÿ��ѭ������low���С�ڵ���x��high�ұߴ���x
	while (low <= high)
	{
		int mid = (low + high) / 2;
		if (min_end[mid] > x)
			high = mid - 1;
		else if (min_end[mid] <= x)
			low = mid + 1;
	}
	return low;
}
void LIS(int A[], int n)
{
	int k = 0;   //min_end[]����ĳ���,�����1��ʼ, min_end[k]��ĩβԪ��
	//����min_end,index���飬�±���1��k������
	//����pre���飬�±���0��n-1������
	min_end[0] = -999999;
	index[0] = -1;  //-1�ǽ�����־
	pre[0] = -1;
	for (int i = 0; i < n; i++)
	{
		int pos = search(A[i], 1, k);
		min_end[pos] = A[i];
		index[pos] = i;
		pre[i] = index[pos - 1];
		if (pos > k) k++;
	}
	//��ӡ�����������
	int result[maxn];
	int result_n = 0; //result����ĳ���
	for (int i = index[k]; i != -1; i = pre[i])
		result[result_n++] = A[i];
	for (int i = result_n-1; i >= 0; i--)
		cout << result[i] << " ";
	cout << endl;
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