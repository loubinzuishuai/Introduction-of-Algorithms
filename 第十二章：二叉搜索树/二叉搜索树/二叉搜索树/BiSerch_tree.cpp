#include "BiSerch_tree.h"
#include "BiNode.h"
#include <iostream>
using namespace std;


BiSerch_tree::BiSerch_tree()
{
	root = NULL;
}


BiSerch_tree::~BiSerch_tree()
{
}

void BiSerch_tree::tree_walk(BiNode * p) //ÓÃµÝ¹é·½·¨°´Ë³Ðò´òÓ¡¶þ²æËÑË÷Ê÷
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
	if (x == NULL)  //¿ÕÊ÷
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

void BiSerch_tree::walk()
{
	tree_walk(root); //µÝ¹é
}
