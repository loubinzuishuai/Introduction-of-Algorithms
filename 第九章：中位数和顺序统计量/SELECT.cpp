
#include<iostream>

#include<time.h>

using namespace std;

//�򵥵Ľ���

void swap(int& a, int& b)

{

	if (a != b)

	{

		a ^= b;

		b ^= a;

		a ^= b;

	}

}

//������صĻ����㷨

int partition(int a[], int l, int r)

{

	int i = l;

	int v = a[i];

	//��������ָ��i,j,j��������������飬iʼ��ָ�����ԪС��ֵ

	for (int j = l + 1; j <= r; j++)

	{

		//jָ�����ұ����Ĺ���������Сֵ��������iλ��ȥ

		if (a[j]<v) {

			++i;

			if (i != j)//���п��ޣ���i==j,swap(i,j)������

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

	swap(A[f], A[p]);//���������������һ�����������������ָ���ֵ�͵�һ��ֵ����

	return partition(A, p, r);

}

int random_select(int* A, int p, int r, int i)

{

	int k, q;

	if (p == r) return A[p];

	q = randdom_partition(A, p, r);//������֣����⼫���������o(n^2),qΪ��Ԫ����

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

	//����������Ȼ��������ָ�룬i,j,i�����������飬j��j-1��ǰ����

	for (i = l + 1; i <= r; i++)

	{

		key = a[i];

		j = i - 1;

		while (j >= l && a[j]>key)//����key���ֵ����

		{

			a[j + 1] = a[j];

			--j;

		}

		a[j + 1] = key;//����Ӧ�ڵ�λ��

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

			key = insert_sort(a, begin, end, (end - begin) / 2 + 1);//���������飬�ҵ���λ������3������Ϊ���ص�i��Ԫ�أ���1��ʼ����������Ϊ5������3����λ��

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

		printf("%3d  ", A[i]);//���������ɵ�����



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

		printf("%3d  ", A[i]);//�������������



	}

	cout << endl << Find_median(A, 0, 24);//�ҳ���λ������λ��

}
