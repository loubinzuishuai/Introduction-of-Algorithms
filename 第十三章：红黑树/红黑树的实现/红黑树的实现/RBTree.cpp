#include "RBTree.h"
#include <iostream>
#include <stack>
#include <string> 
using namespace std;

const int black = 1, red = 0;


RBTree::RBTree()
{
	nil = new RBNode;
	nil->color = black;
	root = nil;
}


RBTree::~RBTree()
{
}

void RBTree::insert(int key)
{
	RBNode *pre = nil;   //pos�ĸ��ڵ㣬pos��̽Ѱ���������ջ�ִ�nil��������Ҫ�������ڵ�
	RBNode *pos = root;  //pos����̽�����key��·��
	RBNode *rp = new RBNode;
	rp->key = key;
	rp->color = red;
	while (pos != nil)
	{
		pre = pos;
		if (key < pos->key)
			pos = pos->left;
		else
			pos = pos->right;
	}
	if (pre == nil) //��һ�ſ���
		root = rp;
	else if (key < pre->key)
		pre->left = rp;
	else
		pre->right = rp;
	rp->left = rp->right = nil;
	rp->parent = pre;
	rb_insert_fixup(rp);
}

void RBTree::walk()
{
	stack<RBNode*> ss;
	RBNode *x = root;
	while (x != nil)
	{
		ss.push(x);
		x = x->left;
	}
	while(!ss.empty())
	{
		x = ss.top();
		ss.pop();
		cout << x->key << ":" << _color(x->color) << " ";
		x = x->right;
		while (x != nil)
		{
			ss.push(x);
			x = x->left;
		}
		
	}
}

void RBTree::drop(RBNode * x)
{
	RBNode *y, *z ; //yָ��Ľ�����ɫ�����ж�Ҫ��Ҫ���������,zָ��Ľ�������ڵ������������ʼ�ڵ�
	int original_color;
	if (x->left == nil) //����֤����������x->right==nilҲ���Ե���rb_delete_fixup()�������е���
	{
		y = x;
		original_color = y->color;
		z = x->right;
		transplant(x, z); //�����z������nil
	}
	else if (x->right == nil)
	{
		y = x;
		original_color = y->color;
		z = x->left;
		transplant(x, z);
	}
	else
	{
		y = minimum(x->right);
		original_color = y->color;
		z = y->right;
		transplant(y, z);
		//��x�����������ĸ����y
		x->right->parent = y;
		y->right = x->right;
		x->left->parent = y;
		y->left = x->left;
		//��y�޽ӵ�x
		transplant(x, y);
		y->color = x->color;
	}
	if (original_color == black)
		rb_delete_fixup(z);
}

RBNode * RBTree::minimum(RBNode * x)
{
	while (x->left != nil)
		x = x->left;
	return x;
}

RBNode * RBTree::search(int key)
{
	RBNode *x = root;
	while (x != nil)
	{
		if (key == x->key)
			return x;
		else if (key < x->key)
			x = x->left;
		else
			x = x->right;
	}
	cout << "�Ҳ����ؼ���" << key << endl;
	return NULL;
}

void RBTree::rb_insert_fixup(RBNode * rp)
{
	while (rp->parent->color == red)
	{
		if (rp->parent == rp->parent->parent->left)
		{
			RBNode *uncle = rp->parent->parent->right;

			if (uncle->color == red) //���1��rp�������Ǻ�ɫ��
			{
				rp->parent->color = black;
				uncle->color = black;
				rp->parent->parent->color = red;
				rp = rp->parent->parent;
			}
			else if (rp == rp->parent->right) //���2��rp�Ǹ��ڵ���Һ��ӣ�����ת����ڵ�
			{
				rp = rp->parent;
				left_rotate(rp);
			}
			else //���3��rp�Ǹ��ڵ������
			{
				rp->parent->color = black;
				rp->parent->parent->color = red;
				right_rotate(rp->parent->parent);
			}
		}
		else
		{
			RBNode *uncle = rp->parent->parent->left;

			if (uncle->color == red) //���1��rp�������Ǻ�ɫ��
			{
				rp->parent->color = black;
				uncle->color = black;
				rp->parent->parent->color = red;
				rp = rp->parent->parent;
			}
			else if (rp == rp->parent->left) //���2��rp�Ǹ��ڵ�����ӣ�����ת���Һ���
			{
				rp = rp->parent;
				right_rotate(rp);
			}
			else //���3��rp�Ǹ��ڵ������
			{
				rp->parent->color = black;
				rp->parent->parent->color = red;
				left_rotate(rp->parent->parent);
			}

		}
	}
	root->color = black;
}

void RBTree::left_rotate(RBNode * rp)
{
	//rp->right ������nil�������޷�����
	while (rp->right != nil)
	{
		RBNode *y = rp->right;
		//��y����������Ϊrp��������
		if (y->left != nil)
			y->left->parent = rp;
		rp->right = y->left;

		//����rp�ĸ��ڵ��y
		y->parent = rp->parent; 
		if (rp == root)
			root = y;
		else if (rp == rp->parent->left)
			rp->parent->left = y;
		else
			rp->parent->right = y;
		
		//����rp��y
		rp->parent = y;
		y->left = rp;
	}
}

void RBTree::right_rotate(RBNode * rp)
{
	//rp->left ������nil�������޷�����
	if (rp->left != nil)
	{
		RBNode *y = rp->left;
		//��y����������Ϊrp��������
		if (y->right != nil)
			y->right->parent = rp;
		rp->left = y->right;

		//����rp�ĸ��ڵ��y
		y->parent = rp->parent;
		if (rp == root)
			root = y;
		else if (rp == rp->parent->left)
			rp->parent->left = y;
		else
			rp->parent->right = y;

		//����rp��y
		rp->parent = y;
		y->right = rp;
	}
}

void RBTree::transplant(RBNode * x, RBNode * y)
{
	/*��y�޽ӵ�x��*/
	if (x == root)
		root = y;
	else if (x == x->parent->left)
	{
		x->parent->left = y;
		y->parent = x->parent;//��һ�伴ʹ�Ƕ�y==nil�������Ҳ��������Ϊ���������ǵ���rb_delete_fixup()�������е����ˣ���Ҫnil�и��ڵ�
	}
	else
	{
		x->parent->right = y;
		y->parent = x->parent;
	}
}

void RBTree::rb_delete_fixup(RBNode * rp)
{
	/*ɾ��������������*/
	while (rp != root && rp->color == black)
	{
		if (rp == rp->parent->left) //rp������
		{
			RBNode *w = rp->parent->right; //w��rp���ֵ�
			if (w->color == red) //���1�����rp���ֵ��Ǻ�ɫ���Ͻ���ɺ�ɫ
			{
				rp->parent->color = red;
				w->color = black;
				left_rotate(rp->parent);
				
			}
			else if (w->left->color == black && w->right->color == black) //���2���ֵܽ����������Ӷ��Ǻ�ɫ��
			{
				w->color = red;
				rp = rp->parent;
			}
			else if (w->right->color == black)  //���3���ֵܽڵ���Һ����Ǻ�ɫ�������Ǻ�ɫ�ģ���Ҫ��취���Һ��ӱ�ɺ�ɫ
			{
				w->color = red;
				w->left->color = black;
				right_rotate(w);
			}
			else                              //���4���ֵܽڵ���Һ��Ӻ�ɫ
			{
				w->color = rp->parent->color;
				rp->parent->color = black;
				w->right->color = black;
				left_rotate(rp->parent);
				rp = root;
			}
		}
		else                        //rp���Һ���
		{
			RBNode *w = rp->parent->left; //w��rp���ֵ�
			if (w->color == red) //���1�����rp���ֵ��Ǻ�ɫ���Ͻ���ɺ�ɫ
			{
				rp->parent->color = red;
				w->color = black;
				right_rotate(rp->parent);
			}
			else if (w->left->color == black && w->right->color == black) //���2���ֵܽ����������Ӷ��Ǻ�ɫ��
			{
				w->color = red;
				rp = rp->parent;
			}
			else if (w->left->color == black)  //���3���ֵܽڵ�������Ǻ�ɫ���Һ����Ǻ�ɫ�ģ���Ҫ��취�����ӱ�ɺ�ɫ
			{
				w->color = red;
				w->right->color = black;
				left_rotate(w);
			}
			else                              //���4���ֵܽڵ���Һ��Ӻ�ɫ
			{
				w->color = rp->parent->color;
				rp->parent->color = black;
				w->left->color = black;
				right_rotate(rp->parent);
				rp = root;
			}

		}
	}
	rp->color = black;
}

string RBTree::_color(int i)
{
	if (i == 0)
		return "red";
	else
		return "black";
}
