#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#define N 6

void printArray (int a[], int lung);
void swap(int a[], int i, int j);
void bubblesort(int a[], int n);

int main() {
    int a[N];

    for (int i = 0; i < N; i++) {
        scanf("%d", &a[i]);
    }

    bubblesort(a, N);

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

void bubblesort(int a[], int n) {
    int i = 1;
    bool swapped;
    do {
        swapped = false;
        for(int j = 1 ; j <= n - i; j++) {
            if(a[j] < a[j-1]) {
                swap(a, j, j -1);
                swapped = true;
            }
        }
        i++;
    } while(swapped && i < n);
}
