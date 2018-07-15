#include <iostream>
using namespace std;
void max_subarray_linear(double *A, int n, int &left, int &right, double &sum)
{
	double max_subarray_sum = A[0];
	int max_subarray_index_left = 0, max_subarray_index_right = 0;
	double border_sum = A[0]; //���߽���������ǵ�������i��ʱ����A[i]Ϊĩ�˵�����������
	int border_index_left = 0, border_index_right = 0; 
	for (int i = 1; i < n; i++)
	{
		//���±߽�������
		double border_sum_update = border_sum + A[i];
		if (border_sum_update > A[i])
		{
			border_sum = border_sum_update;
			border_index_right = i;
		}
		else
		{
			border_sum = A[i];
			border_index_left = border_index_right = i;
		}

		//�������������
		if (border_sum > max_subarray_sum)
		{
			max_subarray_sum = border_sum;
			max_subarray_index_left = border_index_left;
			max_subarray_index_right = border_index_right;
		}
	}
	left = max_subarray_index_left;
	right = max_subarray_index_right;
	sum = max_subarray_sum;
}

int main()
{

	while (1)
	{
		cout << "�����������" << endl;
		int n;
		cin >> n;
		cout << "��������" << endl;
		double A[100];
		for (int i = 0; i < n; i++)
			cin >> A[i];
		int left, right;
		double sum;
		max_subarray_linear(A, n, left, right, sum);
		cout << "��������飺";
		for (int i = left; i <= right; i++)
			cout << A[i] << " ";
		cout << endl << "���������ĺ��ǣ�" << sum << endl;
		cin.sync();
	}
	return 0;
}