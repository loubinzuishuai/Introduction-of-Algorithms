#pragma once
#include "BiNode.h"
class BiSerch_tree
{
public:
	BiSerch_tree();
	~BiSerch_tree();
private:
	void tree_walk(BiNode *p);
public:
	BiNode *root;
	BiNode* search(int key); //返回一个含有关键字key的指针
	BiNode* interative_search(int key); //非递归版本
	void insert(int key);
	void drop(int key);
	void walk();
	void interative_walk();

};

