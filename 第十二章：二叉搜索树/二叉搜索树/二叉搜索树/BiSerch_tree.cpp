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

void BiSerch_tree::tree_walk(BiNode * p) //�õݹ鷽����˳���ӡ����������
{
	if (p != NULL)
	{
		tree_walk(p->lchild);
		cout << p->key << " ";
		tree_walk(p->rchld);
	}
}



void BiSerch_tree::insert(int key)
{
	BiNode *bn = new BiNode;
	bn->key = key;
	bn->parent = bn->rchld = bn->lchild = NULL;
	BiNode *x = root;
	BiNode *y = NULL;
	if (x == NULL)  //����
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
	tree_walk(root); //�ݹ�
}
