#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
const int maxn = 1000; //最大数组
void randomize_in_place(int *A, int n)
{
	srand((unsigned)time(NULL));
	for (int i = 0; i < n; i++)
	{
		int a = i + rand() % (n - i);
		int t = A[i];
		A[i] = A[a];
		A[a] = t;
	}
}
int main()
{
	while (1)
	{
		int n;
		cout << "输入数组个数:" << endl;
		cin >> n;
		cout << "输入待随机化的数组:" << endl;
		int A[maxn];
		for (int i = 0; i < n; i++)
		{
			cin >> A[i];
		}
		randomize_in_place(A, n);
		cout << "随机化后的数组如下:" << endl;
		for (int i = 0; i < n; i++)
			cout << A[i] << " ";
		cout << endl;
	}
	return 0;
}