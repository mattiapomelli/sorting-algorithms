#include<stdlib.h>
#include<stdio.h>
#define N 6

void printArray (int a[], int lung);
void swap(int a[], int i, int j);
void selectionsort(int a[], int n);
void selectionsort_rec(int a[], int n);

int main() {
    int a[N];

    for (int i = 0; i < N; i++) {
        scanf("%d", &a[i]);
    }

    selectionsort(a, N);

    printArray(a, N);

    return 0;
}

void printArray (int a[], int len) {
    printf("[ ");
    int i;
    for(i = 0; i < len - 1; i++) {
        printf("%d, ", a[i]);
    }
    printf("%d ]\n", a[i]);
}

void swap(int a[], int i, int j) {
    int temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}

void selectionsort_rec(int a[], int n) {
    if(n > 1)  {
        int max = 0;
        for (int i = 1; i < n; i++) 
            if(a[i] > a[max])
                max = i;

        swap(a, max, n-1);
        selectionsort_rec(a, n-1);
    }
}

void selectionsort(int a[], int n) {
    int min;
    for(int i = 0; i < n - 1; i++) {
        min = i;
        for (int j = i + 1; j < n; j++) 
            if(a[j] < a[min])
                min = j;
        swap(a, min, i);
    }
}
