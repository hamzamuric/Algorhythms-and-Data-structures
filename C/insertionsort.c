#include "insertionsort.h"

void insertionsort(int array[], int length) {
    int i, j, k;
    for (i = 1; i < length; i++) {
        k = array[i];
        j = i - 1;
        while (j > 0 && array[j] > k)
            array[j + 1] = array[j--];
        array[j + 1] = k;
    }
}