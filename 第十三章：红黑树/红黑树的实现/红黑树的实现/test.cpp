#include <iostream>
#include <cstdlib>
#include <ctime>
#include "RBTree.h"
using namespace std;
int main()
{
	int A[10] = {41,53,37,35,16};
	/*
	srand((unsigned)time(NULL));
	for (int i = 0; i < 10; i++)
		A[i] = rand() % 100;
		*/
	cout << "��ӡ�������" << endl;
	for (int i = 0; i < 5; i++)
		cout << A[i] << " ";
	RBTree bt;
	for (int i = 0; i < 5; i++)
		bt.insert(A[i]);
	cout << endl;
	cout << "��ӡ�����" << endl;
	bt.walk();
	cout << endl;
	RBNode *p = bt.search(41);
	bt.drop(p);
	cout << "��ӡɾ����ĺ����" << endl;
	bt.walk();

	cout << endl;
	while (1);
}