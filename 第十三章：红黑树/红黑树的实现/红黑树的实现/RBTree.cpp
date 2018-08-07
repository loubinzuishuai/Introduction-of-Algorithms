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
	RBNode *pre = nil;   //pos的父节点，pos在探寻过程中最终会抵达nil，所以需要保留父节点
	RBNode *pos = root;  //pos用于探查插入key的路径
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
	if (pre == nil) //是一颗空树
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
	RBNode *y, *z ; //y指向的结点的颜色用来判断要不要调整红黑树,z指向的结点是用于调整红黑树的起始节点
	int original_color;
	if (x->left == nil) //可以证明哪怕这里x->right==nil也可以调用rb_delete_fixup()函数进行调整
	{
		y = x;
		original_color = y->color;
		z = x->right;
		transplant(x, z); //这里的z可以是nil
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
		//将x的左右子树的根变成y
		x->right->parent = y;
		y->right = x->right;
		x->left->parent = y;
		y->left = x->left;
		//将y嫁接到x
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
	cout << "找不到关键字" << key << endl;
	return NULL;
}

void RBTree::rb_insert_fixup(RBNode * rp)
{
	while (rp->parent->color == red)
	{
		if (rp->parent == rp->parent->parent->left)
		{
			RBNode *uncle = rp->parent->parent->right;

			if (uncle->color == red) //情况1：rp的叔结点是红色的
			{
				rp->parent->color = black;
				uncle->color = black;
				rp->parent->parent->color = red;
				rp = rp->parent->parent;
			}
			else if (rp == rp->parent->right) //情况2：rp是父节点的右孩子，则旋转成左节点
			{
				rp = rp->parent;
				left_rotate(rp);
			}
			else //情况3：rp是父节点的左孩子
			{
				rp->parent->color = black;
				rp->parent->parent->color = red;
				right_rotate(rp->parent->parent);
			}
		}
		else
		{
			RBNode *uncle = rp->parent->parent->left;

			if (uncle->color == red) //情况1：rp的叔结点是红色的
			{
				rp->parent->color = black;
				uncle->color = black;
				rp->parent->parent->color = red;
				rp = rp->parent->parent;
			}
			else if (rp == rp->parent->left) //情况2：rp是父节点的左孩子，则旋转成右孩子
			{
				rp = rp->parent;
				right_rotate(rp);
			}
			else //情况3：rp是父节点的左孩子
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
	//rp->right 不等于nil，否则无法左旋
	while (rp->right != nil)
	{
		RBNode *y = rp->right;
		//将y的左子树移为rp的右子树
		if (y->left != nil)
			y->left->parent = rp;
		rp->right = y->left;

		//连接rp的父节点和y
		y->parent = rp->parent; 
		if (rp == root)
			root = y;
		else if (rp == rp->parent->left)
			rp->parent->left = y;
		else
			rp->parent->right = y;
		
		//连接rp和y
		rp->parent = y;
		y->left = rp;
	}
}

void RBTree::right_rotate(RBNode * rp)
{
	//rp->left 不等于nil，否则无法左旋
	if (rp->left != nil)
	{
		RBNode *y = rp->left;
		//将y的右子树移为rp的左子树
		if (y->right != nil)
			y->right->parent = rp;
		rp->left = y->right;

		//连接rp的父节点和y
		y->parent = rp->parent;
		if (rp == root)
			root = y;
		else if (rp == rp->parent->left)
			rp->parent->left = y;
		else
			rp->parent->right = y;

		//连接rp和y
		rp->parent = y;
		y->right = rp;
	}
}

void RBTree::transplant(RBNode * x, RBNode * y)
{
	/*将y嫁接到x处*/
	if (x == root)
		root = y;
	else if (x == x->parent->left)
	{
		x->parent->left = y;
		y->parent = x->parent;//这一句即使是对y==nil的情况下也成立，因为接下来就是调用rb_delete_fixup()函数进行调整了，需要nil有父节点
	}
	else
	{
		x->parent->right = y;
		y->parent = x->parent;
	}
}

void RBTree::rb_delete_fixup(RBNode * rp)
{
	/*删除结点后调整红黑树*/
	while (rp != root && rp->color == black)
	{
		if (rp == rp->parent->left) //rp是左孩子
		{
			RBNode *w = rp->parent->right; //w是rp的兄弟
			if (w->color == red) //情况1：如果rp的兄弟是红色，赶紧变成黑色
			{
				rp->parent->color = red;
				w->color = black;
				left_rotate(rp->parent);
				
			}
			else if (w->left->color == black && w->right->color == black) //情况2：兄弟结点的两个孩子都是黑色的
			{
				w->color = red;
				rp = rp->parent;
			}
			else if (w->right->color == black)  //情况3：兄弟节点的右孩子是黑色，左孩子是红色的，就要想办法把右孩子变成红色
			{
				w->color = red;
				w->left->color = black;
				right_rotate(w);
			}
			else                              //情况4：兄弟节点的右孩子红色
			{
				w->color = rp->parent->color;
				rp->parent->color = black;
				w->right->color = black;
				left_rotate(rp->parent);
				rp = root;
			}
		}
		else                        //rp是右孩子
		{
			RBNode *w = rp->parent->left; //w是rp的兄弟
			if (w->color == red) //情况1：如果rp的兄弟是红色，赶紧变成黑色
			{
				rp->parent->color = red;
				w->color = black;
				right_rotate(rp->parent);
			}
			else if (w->left->color == black && w->right->color == black) //情况2：兄弟结点的两个孩子都是黑色的
			{
				w->color = red;
				rp = rp->parent;
			}
			else if (w->left->color == black)  //情况3：兄弟节点的左孩子是黑色，右孩子是红色的，就要想办法把左孩子变成红色
			{
				w->color = red;
				w->right->color = black;
				left_rotate(w);
			}
			else                              //情况4：兄弟节点的右孩子红色
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
