#pragma once
#include "RBNode.h"
#include <string>

using namespace std;
class RBTree
{
public:
	RBTree();
	~RBTree();
	void insert(int key);
	void walk();
	void drop(RBNode *x);
	RBNode * minimum(RBNode *x);
	RBNode *search(int key);
private:
	void rb_insert_fixup(RBNode *rp);
	void left_rotate(RBNode *rp);
	void right_rotate(RBNode *rp);
	void transplant(RBNode *x, RBNode *y);
	void rb_delete_fixup(RBNode *rp);
	string _color(int i);
private:
	RBNode *root, *nil;
};

