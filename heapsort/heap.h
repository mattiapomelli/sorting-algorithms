#ifndef HEAP_H
#define HEAP_H

typedef int *Heap;

void createHeap(int a[], int n);

void print_heap( Heap h, int n );

void heapify_down ( Heap h, int i, int n );

void swap( Heap h, int i, int j);

#endif