#include "quicksort.h"

static void swap(int *a, int *b) {
    *a = *a ^ *b;
    *b = *a ^ *b;
    *a = *a ^ *b;
}

static int partition(int a[], int down, int up) {
    int i = down;
    int j = up;
    int pivot = a[down];
    while (i < j) {
        while (a[i] <= pivot) i++;
        while (a[j] > pivot) j--;
        if (i < j)
            swap(&a[i], &a[j]);
    }
    a[down] = a[j];
    a[j] = pivot;
    return j;
}

static void quicksort_(int a[], int low, int high) {
    if (low >= high) return;
    int j = partition(a, low, high);
    quicksort_(a, low, j - 1);
    quicksort_(a, j + 1, high);
}

void quicksort(int array[], int length) {
    quicksort_(array, 0, length - 1);
}
