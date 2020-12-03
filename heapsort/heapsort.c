#include <stdio.h>
#include "heap.h"

#define N 8

void print_array( int a[], int n ) {

    printf("[");
    int i;
    if(n > 0) {
        for(i = 0; i < n-1; i++) {
            printf("%d, ", a[i]);
        }
        printf("%d", a[i]);
    }
    printf("]\n");
}

void heapSort(int a[], int n) {
    createHeap(a, n);
    for(int i = n - 1; i >= 1; i--) {
        swap(a, 0, i);
        fixHeap(a, 0, i);
    }
}

int main() {
    int a[N];

    for(int i = 0; i < N; i++) {
        scanf("%d", &a[i]);
    }

    heapSort(a, N);
    print_array(a, N);

    return 0;
}