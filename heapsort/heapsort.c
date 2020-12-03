#include <stdio.h>
#include "heap.h"

void heapSort(int a[], int n) {
    createHeap(a, n);
    for(int i = n - 1; i >= 1; i--) {
        swap(a, 0, i);
        heapify_down(a, 0, i);
    }
}

int main() {
    int a[] = { 6, 5, 8, 2, 13, -80, 120, 6 };
    heapSort(a, 8);
    print_heap(a, 8);

    return 0;
}