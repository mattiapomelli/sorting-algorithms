#include <stdio.h>
#include "heap.h"
#include <stdbool.h>

int left(int i) {
    return 2*i + 1;
}

int right(int i) {
    return 2*i + 2;
}

void swap( int h[], int i, int j) {
    int temp = h[i];
    h[i] = h[j];
    h[j] = temp;
}

// Recursive version of fixHeap
void fixHeapRecursive ( int h[], int i, int n ) {
    int j;
    if ( (j = left(i)) < n ) {            // i ha almeno un figlio

        if ( j != n - 1 )                 // se i ha anche un figlio destro, controllo quale e' il maggiore tra i due figli
            j = h[j] > h[right(i)] ? j : right(i);

        // j ora contiene l'indice del figlio di v di valore massimo    
        if ( h[j] > h[i] ) {
            swap ( h, i, j );
            fixHeapRecursive ( h, j, n );
        }
    }
}

void fixHeap( int h[], int i, int n) {
    int v = i, x = h[v], j;
    bool toPlace = true;
    do {
        if( (j = left(v)) >= n)             // v e' una foglia, non ha figli
            toPlace = false;
        else {
            if(j + 1 < n && h[j+1] > h[j]) // true se v ha un figlio destro, e che e' maggiore del figlio sinistro
                j += 1;

            // j ora contiene l'indice del figlio di v di valore massimo
            if (h[j] > x) {
                h[v] = h[j];
                v = j;
            } else {
                toPlace = false;
            }
        }
    } while (toPlace);
    h[v] = x;
}

void createHeap(int a[], int n) {
    for(int i = n/2; i >= 0; i--) {
        fixHeap(a, i, n);
    }
}