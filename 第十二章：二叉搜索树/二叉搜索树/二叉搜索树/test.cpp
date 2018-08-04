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
	cout << "打印随机数组"<<endl;
	for (int i = 0; i < 10; i++)
		cout << A[i] << " ";
	BiSerch_tree bt;
	for (int i = 0; i < 10; i++)
		bt.insert(A[i]);
	cout << "打印二叉排序树" << endl;
	bt.walk();
	while(1)
	{ }
	
}