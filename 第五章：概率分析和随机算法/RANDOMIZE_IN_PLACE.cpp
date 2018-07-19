#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
const int maxn = 1000; //�������
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
		cout << "�����������:" << endl;
		cin >> n;
		cout << "����������������:" << endl;
		int A[maxn];
		for (int i = 0; i < n; i++)
		{
			cin >> A[i];
		}
		randomize_in_place(A, n);
		cout << "����������������:" << endl;
		for (int i = 0; i < n; i++)
			cout << A[i] << " ";
		cout << endl;
	}
	return 0;
}