#pragma once
class RBNode
{
public:
	RBNode();
	~RBNode();
public:
	int color; //0����죬1����� 
	int key; //�ؼ���
	RBNode *left, *right, *parent; 
};

