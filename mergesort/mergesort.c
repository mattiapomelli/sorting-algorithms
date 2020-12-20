#include<stdlib.h>
#include<stdio.h>
#define N 8

void printArray (int a[], int lung);
void doMergesort(int a[], int n);

int main() {
    int a[N];

    for (int i = 0; i < N; i++) {
        scanf("%d", &a[i]);
    }

    doMergesort(a, N);
    printArray(a, N);

    return 0;
}

void printArray (int a[], int lung) {
    printf("[ ");
    int i;
    for(i = 0; i < lung - 1; i++) {
        printf("%d, ", a[i]);
    }
    printf("%d ]\n", a[i]);
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

/*
    i: first index of part to order
    f: first index after part to order
*/
void mergesort(int a[], int i, int f, int x[]) {
    if (f - i > 1) {
        int m = (i + f) / 2;
        mergesort(a, i, m, x);
        mergesort(a, m, f, x);
        merge(a, i, m, f, x);
    }
}

void doMergesort(int a[], int n) {
    int x[n];
    mergesort(a, 0, n, x);
}