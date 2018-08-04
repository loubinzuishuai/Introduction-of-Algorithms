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
	cout << "´òÓ¡Ëæ»úÊý×é"<<endl;
	for (int i = 0; i < 10; i++)
		cout << A[i] << " ";
	BiSerch_tree bt;
	for (int i = 0; i < 10; i++)
		bt.insert(A[i]);
	cout << endl;
	cout << "µÝ¹é´òÓ¡¶þ²æÅÅÐòÊ÷" << endl;
	bt.walk();
	cout << endl;
	cout << "·ÇµÝ¹é´òÓ¡¶þ²æËÑË÷Ê÷" << endl;
	bt.interative_walk();
	cout << endl;
	while(1)
	{ 
		cout << "ÊäÈëÒª²éÕÒµÄ¹Ø¼ü×Ö£º";
		int key;
		cin >> key;
		BiNode* p = bt.search(key);
		cout << "µÝ¹éËÑË÷µÄ¹Ø¼ü×Ö£º";
		if (p == NULL)
			cout << "NULL" << endl;
		else cout << p->key << endl;
		cout << "·ÇµÝ¹éËÑË÷µÄ¹Ø¼ü×Ö£º";
		if (p == NULL)
			cout << "NULL" << endl;
		else cout << p->key << endl;
		cout << "ÊäÈëÒªÉ¾³ýµÄ¹Ø¼ü×Ö£º";
		cin >> key;
		bt.drop(key);
		cout << "·ÇµÝ¹é´òÓ¡¶þ²æËÑË÷Ê÷" << endl;
		bt.interative_walk();
		cout << endl;
		cout << "ÊäÈëÒª²åÈëµÄ¹Ø¼ü×Ö:" << endl;
		cin >> key;
		bt.insert(key);
		cout << "·ÇµÝ¹é´òÓ¡¶þ²æËÑË÷Ê÷" << endl;
		bt.interative_walk();
		cout << endl;
	}
}