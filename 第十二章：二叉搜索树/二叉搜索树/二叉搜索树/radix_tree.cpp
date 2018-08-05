#include <iostream>
#include <string>
#include <stack>
using namespace std;
class RadixNode
{
public:
	string key;   //�ڶ�Ӧ·����ĳһ���ַ����Ľ�㣬key��ʾ���ַ������������key�ǿմ���
	RadixNode *left, *right;
	RadixNode() { left = NULL; right = NULL; key = ""; }
};
class RadixTree
{
private:
	RadixNode *root;
	void recur_print(RadixNode *x);
public:
	RadixTree() { root = NULL; }
	~RadixTree(){}
	void insert(string &s);
	void print_by_order();

};
void RadixTree::recur_print(RadixNode * x)
{
	if (x != NULL)
	{
		if (x->key != "")
			cout << x->key << endl;
		recur_print(x->left);
		recur_print(x->right);
	}
}
void RadixTree::insert(string &s)
{
	if (root == NULL)
		root = new RadixNode;
	RadixNode *x = root;
	for (int i = 0; i < s.length(); i++)
	{
		char ch = s[i];
		if (ch == '0')
		{
			RadixNode *y = x;
			x = x->left;
			if (x == NULL)
			{
				x = new RadixNode;
				y->left = x;
			}
		}
		if (ch == '1')
		{
			RadixNode *y = x;
			x = x->right;
			if (x == NULL)
			{
				x = new RadixNode;
				y->right = x;
			}
		}
		if (i == s.length() - 1) //��keyֵ��д����ַ���
			x->key = s;
	}
}
void RadixTree::print_by_order()
{
	recur_print(root);
}
int main()
{ 
	while (1)
	{
		RadixTree rt;
		cout << "�����ַ�������" << endl;
		int n;
		cin >> n;
		cout << "����n���ַ�����0-1����"<<endl;
		cin.ignore(25, '\n');
		for (int i = 0; i < n; i++)
		{
			string s;
			getline(cin, s);
			rt.insert(s);
		}
		cout << "�����" << endl;
		rt.print_by_order();
	}
	return 0;
}

