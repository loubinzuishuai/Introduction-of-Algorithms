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
	cout << endl;
	cout << "递归打印二叉排序树" << endl;
	bt.walk();
	cout << endl;
	cout << "非递归打印二叉搜索树" << endl;
	bt.interative_walk();
	cout << endl;
	while(1)
	{ 
		cout << "输入要查找的关键字：";
		int key;
		cin >> key;
		BiNode* p = bt.search(key);
		cout << "递归搜索的关键字：";
		if (p == NULL)
			cout << "NULL" << endl;
		else cout << p->key << endl;
		cout << "非递归搜索的关键字：";
		if (p == NULL)
			cout << "NULL" << endl;
		else cout << p->key << endl;
		cout << "输入要删除的关键字：";
		cin >> key;
		bt.drop(key);
		cout << "非递归打印二叉搜索树" << endl;
		bt.interative_walk();
		cout << endl;
		cout << "输入要插入的关键字:" << endl;
		cin >> key;
		bt.insert(key);
		cout << "非递归打印二叉搜索树" << endl;
		bt.interative_walk();
		cout << endl;
		while (1)
		{
			cout << "输入关键字key：" << endl;
			int key;
			cin >> key;
			if (key == 0)
				break;
			BiNode *pre = bt.predecessor(key);
			cout << "前驱结点为：";
			if (pre != NULL)
				cout << pre->key << endl;
			else
				cout << "NULL" << endl;
			BiNode *suc = bt.successor(key);
			cout << "后继结点为：";
			if (pre != NULL)
				cout << suc->key << endl;
			else
				cout << "NULL" << endl;
		}
	}
}