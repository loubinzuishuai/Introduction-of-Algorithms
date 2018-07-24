#include "Max_priority_queue.h"
#include <iostream>
#include <climits>
using namespace std;


Max_priority_queue::Max_priority_queue()
{
	length = heap_size = 0;
}


Max_priority_queue::~Max_priority_queue()
{
}

void Max_priority_queue::inqueue(int key)
{
	element[++heap_size] = INT_MIN;
	increase_key(heap_size, key);
}

void Max_priority_queue::increase_key(int pos, int key)
{
	if (key < element[pos])
	{
		cout << "error: the key can't decrease" << endl;
		return;
	}
	element[pos] = key;
	int parent_pos = pos / 2;
	while (parent_pos >= 1 && element[parent_pos] < element[pos])
	{
		int t = element[pos];
		element[pos] = element[parent_pos];
		element[parent_pos] = t;
		pos = parent_pos;
		parent_pos = pos / 2;
	}
}

void Max_priority_queue::heap_maxify(int i)
{
	int l = 2 * i;
	int r = l + 1;
	int largest = i;
	if (l <= heap_size && element[l] > element[i])
		largest = l;
	if (r <= heap_size && element[r] > element[largest])
		largest = r;
	if (largest != i)
	{
		int t = element[i];
		element[i] = element[largest];
		element[largest] = t;
		heap_maxify(largest);
	}
}

void Max_priority_queue::print()
{
	for (int i = 1; i < heap_size; i++)
		cout << element[i] << " ";
	cout << endl;
}

int Max_priority_queue::dequeue()
{
	if (heap_size == 0)
		return -999999;
	int key = element[1];
	element[1] = element[heap_size--];
	heap_maxify(1);
	return key;
}

int Max_priority_queue::top()
{
	if (heap_size == 0)
		return -999999;
	return element[1];
}
