#pragma once
class Heap_max
{
public:
	Heap_max();
	Heap_max(int A[], int n);
	~Heap_max();
	void build_max_heap();
	void max_heapify(int i);
	void print_heap();
	void heap_sort();
private:
	int heap[99999];
	int heap_size; //堆大小
	int length; //数组大小
};

