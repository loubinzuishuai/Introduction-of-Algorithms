#pragma once
class RBNode
{
public:
	RBNode();
	~RBNode();
public:
	int color; //0代表红，1代表黑 
	int key; //关键字
	RBNode *left, *right, *parent; 
};

