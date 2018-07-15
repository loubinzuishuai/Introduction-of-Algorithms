#include <iostream>
#include <float.h>
using namespace std;
const double neg_max = -DBL_MAX;
class Subarray
{
public:
	int left, right;
	double sum;
	Subarray(int left, int right, double sum)
	{
		this->left = left;
		this->right = right;
		this->sum = sum;
	}
};
Subarray FIND_CROSSING_SUBARRAY(double *A, int left, int mid, int right)
{
	double left_sum = neg_max;
	int max_left = mid;
	double sum = 0;
	for (int i = mid; i >= left; i--)
	{
		sum += A[i];
		if (sum > left_sum)
		{
			left_sum = sum;
			max_left = i;
		}
	}
	double right_sum = neg_max;
	int max_right = mid+1;
	sum = 0;
	for (int i = mid+1; i <= right; i++)
	{
		sum += A[i];
		if (sum > right_sum)
		{
			right_sum = sum;
			max_right = i;
		}
	}
	return Subarray(max_left, max_right, left_sum + right_sum);
}
Subarray FIND_MAXIMUM_SUBARRAY(double *A, int left, int right)
{
	if (left >= right)
	{
		Subarray sub(left, right, A[left]);
		return sub;
	}
	int mid = (left + right) / 2;
	Subarray sub1 = FIND_MAXIMUM_SUBARRAY(A, left, mid);
	Subarray sub2 = FIND_MAXIMUM_SUBARRAY(A, mid + 1, right);
	Subarray sub3 = FIND_CROSSING_SUBARRAY(A, left, mid, right);
	if (sub1.sum >= sub2.sum && sub1.sum >= sub3.sum)
		return sub1;
	if (sub2.sum >= sub1.sum && sub2.sum >= sub3.sum)
		return sub2;
	else
		return sub3;
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
		Subarray sub = FIND_MAXIMUM_SUBARRAY(A, 0, n - 1);
		cout << "最大子数组：";
		for (int i = sub.left; i <= sub.right; i++)
			cout << A[i] << " ";
		cout << endl << "最大子数组的和是：" << sub.sum << endl;
	}
	return 0;
}