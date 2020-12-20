#include<stdlib.h>
#include<stdio.h>
#define N 6

void stampa (int a[], int lung);
void insertionsort(int a[], int n);

int main() {
    int a[N];

    for (int i = 0; i < N; i++) {
        scanf("%d", &a[i]);
    }

    insertionsort(a, N);

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

void insertionsort(int a[], int n) {
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
