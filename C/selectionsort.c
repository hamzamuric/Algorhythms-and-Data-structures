#include "selectionsort.h"

void selectionsort(int array[], int length) {
    int i, j, min, pos;
    for (i = 0; i < length - 2; i++) {
        min = array[i];
        pos = i;
        for (j = i + 1; j < length - 1; j++) {
            if (array[j] < min) {
                min = array[j];
                pos = j;
            }
        }
        array[pos] = array[i];
        array[i] = min;
    }
}