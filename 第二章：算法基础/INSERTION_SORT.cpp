#include <iostream>
using namespace std;
void insertion_sort(int *a, int n)
{
	//������a���в�������
	for (int j = 1; j < n; j++)
	{
		int key = a[j];
		int i;
		for (i = j - 1; i >= 0; i--)
		{
			if (a[i] <= key)
				break;
			a[i + 1] = a[i];
		}
		a[i + 1] = key;
	}
}

int main()
{
	int a[100];
	while (1)
	{
		cout << "���������С" << endl;
		int n;
		cin >> n;
		cout << "��������Ԫ��" << endl;
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
		}
		insertion_sort(a, n);
		cout << "�����";
		for (int i = 0; i < n; i++)
			cout << a[i] << " ";
		cout << endl;
	}
	return 0;
}