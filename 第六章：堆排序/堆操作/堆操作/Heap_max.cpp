#include "Heap_max.h"
#include<iostream>
using namespace std;


Heap_max::Heap_max()
{
	length = heap_size = 0;
}

Heap_max::Heap_max(int A[], int n)
{
	for (int i = 1; i <= n; i++)
		heap[i] = A[i - 1];
	length = heap_size = n;
}


Heap_max::~Heap_max()
{
}

void Heap_max::build_max_heap()
{
	for (int i = length / 2; i >= 1; i--)
		max_heapify(i);
}

void Heap_max::max_heapify(int i)
{
	//将以A[i]为根节点的子树转化为大根堆,A[0]保存数组大小，树从A[1]开始
	int largest;
	int left = 2 * i, right = left + 1;
	if (left <= heap_size && heap[left] > heap[i])
		largest = left;
	else
		largest = i;
	if (right <= heap_size && heap[right] > heap[largest])
		largest = right;
	if (largest != i)
	{
		int t = heap[i];
		heap[i] = heap[largest];
		heap[largest] = t;
		max_heapify(largest);
	}

}

void Heap_max::print_heap()
{
	for (int i = 1; i <= length; i++)
		cout << heap[i] << " ";
	cout << endl;
}

void Heap_max::heap_sort()
{
	build_max_heap();
	for (int i = length; i > 1; i--)
	{
		int t = heap[i];
		heap[i] = heap[1];
		heap[1] = t;
		heap_size--;
		max_heapify(1);
	}
}
