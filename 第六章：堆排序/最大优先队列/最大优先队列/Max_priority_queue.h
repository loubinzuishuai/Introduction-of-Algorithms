#pragma once
class Max_priority_queue
{
public:
	Max_priority_queue();
	~Max_priority_queue();
	void inqueue(int key);
	void increase_key(int pos, int key);
	void heap_maxify(int i);
	void print();
	int dequeue();
	int top();
private:
	int element[99999];
	int length;
	int heap_size;
};

