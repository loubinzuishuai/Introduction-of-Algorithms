#include <iostream>
#include "Heap_max.h"

using namespace std;
int main()
{
	while (1)
	{
		int n;
		cin >> n;
		int A[10000];
		for (int i = 0; i < n; i++)
			cin >> A[i];
		Heap_max heap(A, n);
		heap.heap_sort();
		heap.print_heap();
	}
	return 0;
}