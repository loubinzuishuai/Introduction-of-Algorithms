#include <iostream>
#include <cstdlib>
#include <ctime>
#include "BiSerch_tree.h"
using namespace std;
int main()
{
	int A[10];
	srand((unsigned)time(NULL));
	for (int i = 0; i < 10; i++)
		A[i] = rand() % 100;
	cout << "��ӡ�������"<<endl;
	for (int i = 0; i < 10; i++)
		cout << A[i] << " ";
	BiSerch_tree bt;
	for (int i = 0; i < 10; i++)
		bt.insert(A[i]);
	cout << "��ӡ����������" << endl;
	bt.walk();
	cout << endl;
	while(1)
	{ 
		cout << "����Ҫ���ҵĹؼ��֣�";
		int key;
		cin >> key;
		BiNode* p = bt.search(key);
		cout << "�ݹ������Ĺؼ��֣�";
		if (p == NULL)
			cout << "NULL" << endl;
		else cout << p->key << endl;
		cout << "�ǵݹ������Ĺؼ��֣�";
		if (p == NULL)
			cout << "NULL" << endl;
		else cout << p->key << endl;
	}
}