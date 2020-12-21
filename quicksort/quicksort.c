#include <stdio.h>

void swap(int a[], int i, int j);
int partition(int a[], int i, int f);
void quickSort(int a[], int i, int f);
void printArray (int a[], int len);

int main() {
    int a[] = {4, 23, 67, -190, 80, 3};

    quickSort(a, 0, 6);
    
    printArray(a, 6);

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

