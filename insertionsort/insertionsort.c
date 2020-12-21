#include <stdbool.h>
#include "../array-utils.h"

void insertionSort(int[], int);

int main() {
    int *a, n;
    
    a = scanArray(&n);

    insertionSort(a, n);
    printArray(a, n);

    return 0;
}

void insertionSort(int a[], int n) {
    int x, j;
    for(int k = 1; k < n; k++) {
        // get element in position k
        x = a[k];
        j = k - 1;
        // compare with previous elements until an element smaller than x is found
        while(j >= 0 && a[j] > x ) {
            a[j + 1] = a[j];             // move elements to make space for insertion
            j--;
        }
        // insert x in defined position
        a[j+1] = x;
    }   
}
