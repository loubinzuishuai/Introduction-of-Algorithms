
#include<iostream>

#include<time.h>

using namespace std;

//简单的交换

void swap(int& a, int& b)

{

	if (a != b)

	{

		a ^= b;

		b ^= a;

		a ^= b;

	}

}

//最经典朴素的划分算法

int partition(int a[], int l, int r)

{

	int i = l;

	int v = a[i];

	//管理两个指针i,j,j负责遍历整个数组，i始终指向比主元小的值

	for (int j = l + 1; j <= r; j++)

	{

		//j指针向右遍历的过程中遇到小值，都换到i位置去

		if (a[j]<v) {

			++i;

			if (i != j)//可有可无，若i==j,swap(i,j)无意义

				swap(a[j], a[i]);

		}

	}

	swap(a[l], a[i]);

	return i;

}

int randdom_partition(int* A, int p, int r)

{

	int f;

	srand((unsigned int)time(0));

	f = p + rand() % (r - p + 1);

	swap(A[f], A[p]);//用随机数生器生成一个随机索引，将索引指向的值和第一个值交换

	return partition(A, p, r);

}

int random_select(int* A, int p, int r, int i)

{

	int k, q;

	if (p == r) return A[p];

	q = randdom_partition(A, p, r);//随机划分，避免极端情况出现o(n^2),q为主元索引

	k = q - p + 1;

	if (i == k)

		return A[q];

	else if (i<k)

		return random_select(A, p, q - 1, i);

	else return random_select(A, q + 1, r, i - k);



}



int insert_sort(int* a, int l, int r, int k)

{

	int i, j, key;

	//插入排序，依然管理两个指针，i,j,i遍历整个数组，j从j-1向前遍历

	for (i = l + 1; i <= r; i++)

	{

		key = a[i];

		j = i - 1;

		while (j >= l && a[j]>key)//将比key大的值后移

		{

			a[j + 1] = a[j];

			--j;

		}

		a[j + 1] = key;//插入应在的位置

	}

	return a[l + k - 1];

}



int Find_median(int* a, int l, int r)

{

	int i, begin, end, len, key, j = 0;

	int ret;

	len = r - l + 1;

	int *B = new int[len / 5 + 1];

	for (i = l; i <= r; i++)

	{

		if ((i - l) % 5 == 0)

		{

			begin = i;

		}

		else if ((i - l) % 5 == 4 || i == r)

		{

			end = i;

			key = insert_sort(a, begin, end, (end - begin) / 2 + 1);//处理单个数组，找到中位数，第3个参数为返回第i个元素（从1开始），若数组为5，返回3即中位数

			B[j++] = key;

		}

	}

	ret = random_select(B, 0, j - 1, (j - 1) / 2 + 1);

	delete[]B;

	return ret;

}

void main()

{

	int A[25];

	srand((unsigned int)time(0));

	for (int i = 0; i<25; i++)

	{

		A[i] = rand() % 100;

		if (i % 5 == 0)

			cout << endl;

		printf("%3d  ", A[i]);//输出随机生成的数组



	}

	cout << endl;

	for (int i = 0; i<25; i++)

	{

		if (i % 5 == 0)

			insert_sort(A, i, i + 4, 0);



	}

	for (int i = 0; i<25; i++)

	{

		if (i % 5 == 0)

			cout << endl;

		printf("%3d  ", A[i]);//输出排序后的数组



	}

	cout << endl << Find_median(A, 0, 24);//找出中位数的中位数

}
