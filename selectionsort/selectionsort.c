#include "../array-utils.h"

void selectionSort(int a[], int n);
void selectionsort_rec(int a[], int n);

int main() {
    int *a, n;
    
    a = scanArray(&n);

    selectionSort(a, n);
    printArray(a, n);

    return 0;
}

void selectionSort(int a[], int n) {
    int min;
    for(int i = 0; i < n - 1; i++) {
        min = i;
        for (int j = i + 1; j < n; j++) 
            if(a[j] < a[min])
                min = j;
        swap(a, min, i);
    }
}

// Alternative recursive version of selection sort
void selectionSort_rec(int a[], int n) {
    if(n > 1)  {
        int max = 0;
        for (int i = 1; i < n; i++) 
            if(a[i] > a[max])
                max = i;

        swap(a, max, n-1);
        selectionSort_rec(a, n-1);
    }
}


