#pragma once
#include "BiNode.h"
class BiSerch_tree
{
public:
	BiSerch_tree();
	~BiSerch_tree();
private:
	void tree_walk(BiNode *p); //�ݹ鰴˳���������������
	BiNode* tree_search(BiNode *p, int key); //�ݹ�����key��������ָ��key��ָ��
public:
	BiNode *root;
	BiNode* search(int key); //����һ�����йؼ���key��ָ��
	BiNode* interative_search(int key); //�ǵݹ�汾
	void insert(int key);
	void drop(int key);
	void walk();
	void interative_walk();

};

