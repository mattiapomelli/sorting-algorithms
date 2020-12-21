#include "../array-utils.h"

int partition(int a[], int i, int f);
void quickSort(int a[], int i, int f);

int main() {
    int *a, n;
    
    a = scanArray(&n);

    quickSort(a, 0, n);
    printArray(a, n);

    return 0;
}

void quickSort(int a[], int i, int f) {
    while(f - i > 1) {
        int m = partition(a, i, f);
        // order smallest part recursively, and biggest part iteratively
        if(m - i < f - m) {
            quickSort(a, i, m);
            i = m + 1;
        } else  {
            quickSort(a, m + 1, f);
            f = m;
        }
    }
}

int partition(int a[], int i, int f) {
    // choose first element as the pivot
    int pivot = a[i];
    int left = i;
    int right = f;
    while(left < right) {
        // scan from right
        do { right--; } while(a[right] > pivot);
        // scan from left
        do { left++;} while(left < right && a[left] <= pivot);
        // swap elements found in the two scans
        if(left < right) {
            swap(a, left, right);
        }
    }
    // swap pivot with element in position right
    swap(a, i, right);
    // return position of pivot
    return right;
}



