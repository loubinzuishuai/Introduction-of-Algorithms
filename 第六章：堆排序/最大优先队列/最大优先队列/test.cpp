#include<iostream>
#include <climits>
#include "Max_priority_queue.h"
using namespace std;
int main()
{
	while (1)
	{
		Max_priority_queue mpq;
		for (int i = 0; i < 10; i++)
		{
			int a;
			cin >> a;
			mpq.inqueue(a);
		}
		cout << "��ӡ�ѣ�" << endl;
		mpq.print();
		cout << "top():" << endl;
		cout << mpq.top() << endl;
		cout << "dequeue():" << endl;
		cout << mpq.dequeue() << endl;
		cout << "��ӡ�ѣ�" << endl;
		mpq.print();
		cout << "������������100��" << endl;
		mpq.increase_key(5, 100);
		cout << "top():" << endl;
		cout << mpq.top() << endl;
		cout << "��ӡ�ѣ�" << endl;
		mpq.print();
	}
	return 0;
}