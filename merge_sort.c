#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void merge(int a[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // temp arrays
    int *L = (int*)malloc(n1 * sizeof(int));
    int *R = (int*)malloc(n2 * sizeof(int));

    // copy data
    for (int i = 0; i < n1; i++) L[i] = a[left + i];
    for (int j = 0; j < n2; j++) R[j] = a[mid + 1 + j];

    int i = 0, j = 0, k = left;

    // merge back
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            a[k++] = L[i++];
        } else {
            a[k++] = R[j++];
        }
    }

    // copy remaining
    while (i < n1) a[k++] = L[i++];
    while (j < n2) a[k++] = R[j++];

    free(L);
    free(R);
}

void merge_sort(int a[], int left, int right) {
    if (left < right) {
        int mid = (left + right) / 2;
        merge_sort(a, left, mid);
        merge_sort(a, mid + 1, right);
        merge(a, left, mid, right);
    }
}

void randarr(int a[], int n) {
    for (int i = 0; i < n; i++) {
        a[i] = rand() % 10000;  // random numbers
    }
}

int main() {
    srand(time(NULL));

    for (int n = 1000; n < 10000; n += 1000) {
        int *arr = (int*)malloc(n * sizeof(int));
        int *temp = (int*)malloc(n * sizeof(int));

        if (arr == NULL || temp == NULL) {
            printf("Memory allocation failed!!\n");
            return 1;
        }

        randarr(arr, n);

        clock_t start = clock();
        for (int t = 0; t < 1000; t++) {
            for (int j = 0; j < n; j++) {
                temp[j] = arr[j];
            }
            merge_sort(temp, 0, n-1);
        }
        clock_t end = clock();

        double total_time = (double)(end - start) / CLOCKS_PER_SEC;
        double time = total_time / 1000;  // average per sort

        printf("Time taken for %d elements is %f seconds\n", n, time);

        free(arr);
        free(temp);
    }

    return 0;
}
