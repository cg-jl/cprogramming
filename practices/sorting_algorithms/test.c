#include <stdio.h>
#include <stdlib.h>

void mergeSort(int values[], int start, int end) {
    int i;
    if (end - start < 2) return;
    int mid = (end + start) / 2;
    mergeSort(values, start, mid);
    mergeSort(values, mid, end);

    int len_left = mid - start;
    int len_right = end - mid;
    int *left = (int *) malloc (sizeof (int) * len_left);
    int *right = (int *) malloc (sizeof (int) * len_right);

    // Copy left part
    for (i = start; i < mid; ++i)
        left[i - start] = values[i];

    // Copy right part
    for (i = mid; i < end; ++i)
        right[i - mid] = values[i];

    int li = 0,
        ri = 0,
        gi = start;

    while (li < len_left && ri < len_right) {
        if (left[li] < right[ri])
            values[gi++] = left[li++];
        else
            values[gi++] = right[ri++];
    }

    while (li < len_left)
        values[gi++] = left[li++];

    while (ri < len_right)
        values[gi++] = right[ri++];

    free(left);
    free(right);
}

int randrange(int min, int max) {
  return min + (rand() % ( max - min + 1));
}

void getRange(int *values, int start, int end) {
    for (int i = start; i < end; ++i)
        values[i - start] = i;
}

void shuffle(int values[], int length) {
    for (int i = length - 1; i >= 0; --i) {
        int index = randrange(0, length - 1);

        int a = values[index];
        values[index] = values[i];
        values[i] = a;
    }
}

void printList(int values[], int start, int end) {
    printf("[ ");
    for (int i = start; i < end; ++i) {
        printf("%d", values[i]);
        if (i < end - 1) printf(",");
        printf(" ");
    }
    printf("]");
}

void printlnList(int values[], int start, int end) {
    printList(values, start, end);
    printf("\n");
}

int main() {
    int a[9];
    getRange(a, 1, 10);

    shuffle(a, 9);
    printf("BEFORE SORTING\n");
    printlnList(a, 0, 9);

    mergeSort(a, 0, 9);

    printf("AFTER SORTING\n");
    printlnList(a, 2, 9);



    return 0; 
}
