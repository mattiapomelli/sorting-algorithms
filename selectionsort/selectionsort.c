#include<stdlib.h>
#include<stdio.h>
#define N 6

void stampa (int a[], int lung);
void scambia(int a[], int i, int j);
void selectionsort(int a[], int n);
void selectionsort_rec(int a[], int n);

int main() {
    int a[N];

    for (int i = 0; i < N; i++) {
        scanf("%d", &a[i]);
    }

    selectionsort(a, N);

    stampa(a, N);

    return 0;
}

void stampa (int a[], int len) {
    printf("[ ");
    int i;
    for(i = 0; i < len - 1; i++) {
        printf("%d, ", a[i]);
    }
    printf("%d ]\n", a[i]);
}

void scambia(int a[], int i, int j) {
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

        scambia(a, max, n-1);
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
        scambia(a, min, i);
    }
}
