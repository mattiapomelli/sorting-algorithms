#include <stdio.h>
#include "heap.h"

int left(int i) {
    return 2*i + 1;
}

int right(int i) {
    return 2*i + 2;
}

int cmp( int a, int b) {
    if(a == b)
        return 0;
    else
        return a < b ? -1 : 1;
}

void swap( Heap h, int i, int j) {
    int temp = h[i];
    h[i] = h[j];
    h[j] = temp;
}

void heapify_down ( Heap h, int i, int n ) {
    if ( left(i) < n ) {            // i ha almeno un figlio

        int j;                      // indice del figlio di i con chiave maggiore
        if ( left(i) == n - 1 )     // i ha solo il figlio sinistro
            j = left(i);
        else // i ha due figli
            j = cmp( h[left(i)], h[right(i)] ) > 0 ? 2*i+1 : 2*i + 2;
        
        // se l'elemento e' fuori posto, scambio
        if ( cmp(  h[j], h[i] ) > 0 ) {
            swap ( h, i, j );
            heapify_down ( h, j, n );
        }
    }
}

void fixHeap( Heap h, int i, int n) {
    int x = h[i];
    
}

void print_heap( Heap h, int n ) {
    for(int i = 0; i < n; i++) {
        printf("%d ", h[i] );
    }
    printf("\n");
}

void createHeap(int a[], int n) {
    for(int i = n/2; i >= 0; i--) {
        heapify_down(a, i, n);
    }
}