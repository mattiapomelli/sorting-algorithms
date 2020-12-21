#include <stdbool.h>
#include "../array-utils.h"

void fixHeap( int a[], int r, int l);
void createHeap(int a[], int n);
void heapSort(int a[], int n);

int main() {
    int *a, n;

    a = scanArray(&n);

    heapSort(a, n);
    printArray(a, n);

    return 0;
}

void heapSort(int a[], int n) {
    createHeap(a, n);
    for(int l = n - 1; l >= 1; l--) {
        swap(a, 0, l);      // remove last leaf and put value in the root
        fixHeap(a, 0, l);
    }
}

void createHeap(int a[], int n) {
    for(int i = n/2; i >= 0; i--) {
        fixHeap(a, i, n);
    }
}

void fixHeap( int a[], int r, int l) {
    int v = r;
    int x = a[v];       // element to push down
    int j;
    bool toPlace = true;
    do {
        if( (j = 2*v + 1) >= l )             // v is a leaf, doesn't have children nodes
            toPlace = false;
        else {
            if(j + 1 < l && a[j+1] > a[j])  // true if v has has a right child which is greater than the left one
                j += 1;

            // j contains the index of the greatest child of v
            if (a[j] > x) {
                a[v] = a[j];
                v = j;
            } else {
                toPlace = false;
            }
        }
    } while (toPlace);
    a[v] = x;
}



