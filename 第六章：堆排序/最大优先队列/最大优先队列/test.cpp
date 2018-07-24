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
		cout << "打印堆：" << endl;
		mpq.print();
		cout << "top():" << endl;
		cout << mpq.top() << endl;
		cout << "dequeue():" << endl;
		cout << mpq.dequeue() << endl;
		cout << "打印堆：" << endl;
		mpq.print();
		cout << "将第五个数变成100：" << endl;
		mpq.increase_key(5, 100);
		cout << "top():" << endl;
		cout << mpq.top() << endl;
		cout << "打印堆：" << endl;
		mpq.print();
	}
	return 0;
}