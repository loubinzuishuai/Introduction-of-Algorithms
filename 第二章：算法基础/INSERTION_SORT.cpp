#include <iostream>
using namespace std;
void insertion_sort(int *a, int n)
{
	//对数组a进行插入排序
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
		cout << "输入数组大小" << endl;
		int n;
		cin >> n;
		cout << "输入数组元素" << endl;
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
		}
		insertion_sort(a, n);
		cout << "排序后：";
		for (int i = 0; i < n; i++)
			cout << a[i] << " ";
		cout << endl;
	}
	return 0;
}