#pragma once
class BiNode
{
public:
	BiNode();
	~BiNode();

public:
	int key;
	BiNode *lchild, *rchld, *parent;
};

