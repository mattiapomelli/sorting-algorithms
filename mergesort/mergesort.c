#include "../array-utils.h"

void doMergeSort(int a[], int n);
void merge(int a[], int i, int m, int f, int x[]);
void mergeSort(int a[], int i, int f, int x[]);

int main() {
    int *a, n;
    
    a = scanArray(&n);

    doMergeSort(a, n);
    printArray(a, n);

    return 0;
}

void doMergeSort(int a[], int n) {
    int x[n];
    mergeSort(a, 0, n, x);
}

/*
    i: first index of part to order
    f: first index after part to order
*/
void mergeSort(int a[], int i, int f, int x[]) {
    if (f - i > 1) {
        int m = (i + f) / 2;
        mergeSort(a, i, m, x);
        mergeSort(a, m, f, x);
        merge(a, i, m, f, x);
    }
}

/*
    i: first index of first part to order
    m: first index of second part to order
    f: first index after second part
*/
void merge(int a[], int i, int m, int f, int x[]) {
    int i1 = i, i2 = m;
    int k = 0;
    
    // compare smallest elements in the two parts and put smallest in x
    while(i1 < m && i2 < f) {
        if(a[i1] <= a[i2]) {
            x[k] = a[i1];
            i1++;
        } else {
            x[k] = a[i2];
            i2++;
        }
        k++;
    }
    
    // copy the rest of the part that is not finished into x
    if(i1 < m) {                    // first part is not finished
        for(int j = i1; j < m; j++) {
            x[k] = a[j];
            k++;
        }
    } else {                        // second part is not finished
        for(int j = i2; j < f; j++) {
            x[k] = a[j];
            k++;
        }
    }

    // copy result into a in the corresponding position
    for(k = 0; k < f-i; k++) {
        a[i + k] = x[k];
    }
}



