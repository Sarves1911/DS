#include<stdio.h>
#include<stdlib.h>

void mergesort(int A[], int length) {
    if (length < 2) {
        return;
    }
    else {
        int mid = length / 2;
        int left[mid];
        int right[length - mid];

        for (int i = 0; i < mid; i++) {
            left[i] = A[i];
        }

        for (int i = mid; i < length; i++) {
            right[i - mid] = A[i];
        }
        
        mergesort(left, mid);
        mergesort(right, length - mid);
        merge(left, right, A, mid, length - mid);
    }
}

void merge(int left[], int right[], int A[], int nL, int nR) {
    int i, j, k;
    i = j = k = 0;

    while (i < nL && j < nR) {
        if (left[i] <= right[j]) {
            A[k] = left[i];
            i++;
        }
        else {
            A[k] = right[j];
            j++;
        }
        k++;
    }

    while (i < nL) {
        A[k] = left[i];
        i++;
        k++;
    }

    while (j < nR) {
        A[k] = right[j];
        j++;
        k++;
    }
}

int main() {
    int A[] = {2, 6, 4, 0, 8, 9};
    int n = sizeof(A) / sizeof(int);

    mergesort(A, n);

    printf("Sorted Array is:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", A[i]);
    }

    return 0;
}
