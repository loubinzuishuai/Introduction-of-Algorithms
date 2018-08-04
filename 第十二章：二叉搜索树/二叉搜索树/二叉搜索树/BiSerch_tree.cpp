#include "BiSerch_tree.h"
#include "BiNode.h"
#include <stack>
#include <iostream>
using namespace std;


BiSerch_tree::BiSerch_tree()
{
	root = NULL;
}


BiSerch_tree::~BiSerch_tree()
{
}

void BiSerch_tree::tree_walk(BiNode * p) //用递归方法按顺序打印二叉搜索树
{
	if (p != NULL)
	{
		tree_walk(p->lchild);
		cout << p->key << " ";
		tree_walk(p->rchld);
	}
}

BiNode * BiSerch_tree::tree_search(BiNode * p, int key)
{
	if (p == NULL)
		return NULL;
	if (p->key == key)
		return p;
	else if (p->key > key)
		return tree_search(p->lchild, key);
	else
		return tree_search(p->rchld, key);
}

void BiSerch_tree::transplate(BiNode * x, BiNode * y)
{
	//用以y为根节点的二叉搜索树取代以x为根节点的二叉搜索树
	if (x->parent == NULL)
		root = y;
	else if (x->parent->lchild == x)
		x->parent->lchild = y;
	else
		x->parent->rchld = y;
	if(y != NULL)
		y->parent = x->parent;
}

BiNode * BiSerch_tree::minimum(BiNode * p)
{
	//寻找以p为根节点大的二叉搜索树的最小关键字，并返回指向它的指针。
	while (p->lchild != NULL)
		p = p->lchild;
	return p;
}



BiNode * BiSerch_tree::search(int key)
{
	return tree_search(root, key);
}

BiNode * BiSerch_tree::interative_search(int key)
{
	BiNode* x = root;
	while (x != NULL)
	{
		if (x->key == key)
			return x;
		else if (key < x->key)
			x = x->lchild;
		else
			x = x->rchld;
	}
	return NULL;
}

void BiSerch_tree::insert(int key)
{
	BiNode *bn = new BiNode;
	bn->key = key;
	bn->parent = bn->rchld = bn->lchild = NULL;
	BiNode *x = root;
	BiNode *y = NULL;
	if (x == NULL)  //空树
	{
		root = bn;
		return;
	}
	
	while (x != NULL)
	{
		y = x;
		if (key < x->key)
			x = x->lchild;
		else
			x = x->rchld;
	}
	if (key < y->key)
		y->lchild = bn;
	else
		y->rchld = bn;
	bn->parent = y;
}

void BiSerch_tree::drop(int key)
{
	//删除关键字key的节点
	BiNode *x = interative_search(key);
	if (x->lchild == NULL)
		transplate(x, x->rchld);
	else if (x->rchld == NULL)
		transplate(x, x->lchild);
	else
	{
		BiNode *y = minimum(x->rchld);
		transplate(y, y->rchld);
		y->rchld = x->rchld;
		x->rchld->parent = y;
		transplate(x, y);
		y->lchild = x->lchild;
		x->lchild->parent = y;
	}
}

void BiSerch_tree::walk()
{
	tree_walk(root); //递归
}

void BiSerch_tree::interative_walk()
{
	stack<BiNode*> st;
	BiNode *x = root;
	while (x != NULL)
	{
		st.push(x);
		x = x->lchild;
	}
	while (!st.empty())
	{
		x = st.top();
		st.pop();
		cout << x->key << " ";
		x = x->rchld;
		while (x != NULL)
		{
			st.push(x);
			x = x->lchild;
		}
	}
}
