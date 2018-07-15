#include <iostream>
using namespace std;
void max_subarray_linear(double *A, int n, int &left, int &right, double &sum)
{
	double max_subarray_sum = A[0];
	int max_subarray_index_left = 0, max_subarray_index_right = 0;
	double border_sum = A[0]; //最大边界子数组就是当遍历第i次时，以A[i]为末端的最大和子数组
	int border_index_left = 0, border_index_right = 0; 
	for (int i = 1; i < n; i++)
	{
		//更新边界子数组
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

		//更新最大子数组
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
		cout << "输入数组个数" << endl;
		int n;
		cin >> n;
		cout << "输入数组" << endl;
		double A[100];
		for (int i = 0; i < n; i++)
			cin >> A[i];
		int left, right;
		double sum;
		max_subarray_linear(A, n, left, right, sum);
		cout << "最大子数组：";
		for (int i = left; i <= right; i++)
			cout << A[i] << " ";
		cout << endl << "最大子数组的和是：" << sum << endl;
		cin.sync();
	}
	return 0;
}