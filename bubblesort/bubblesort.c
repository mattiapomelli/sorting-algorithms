#include <stdbool.h>
#include "../array-utils.h"

void bubbleSort(int[], int);

int main() {
    int *a, n;
    
    a = scanArray(&n);

    bubbleSort(a, n);
    printArray(a, n);

    return 0;
}

void bubbleSort(int a[], int n) {
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
