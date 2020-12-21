#include <stdio.h>
#include <stdlib.h>
#include "array-utils.h"

void printArray( int a[], int n ) {

    printf("Ordered Array: [");
    int i;
    if(n > 0) {
        for(i = 0; i < n-1; i++) {
            printf("%d, ", a[i]);
        }
        printf("%d", a[i]);
    }
    printf("]\n");
}

void swap( int h[], int i, int j) {
    int temp = h[i];
    h[i] = h[j];
    h[j] = temp;
}

int *scanArray(int *n) {
    int size, *a;
    printf("Enter number of elements to put in the array: ");
    scanf("%d", &size);
    *n = size;

    a = malloc(size * sizeof(int));

    printf("Enter elements: ");
    for(int i = 0; i < size; i++) {
        scanf("%d", &a[i]);
    }

    return a;
}