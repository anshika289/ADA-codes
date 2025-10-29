#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int partition(int a[], int low, int high) {
    int pivot = a[high];  // choose last element as pivot
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (a[j] <= pivot) {
            i++;
            // swap a[i] and a[j]
            int temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    }
    // place pivot in correct position
    int temp = a[i+1];
    a[i+1] = a[high];
    a[high] = temp;

    return i+1;
}

void quick_sort(int a[], int low, int high) {
    if (low < high) {
        int pi = partition(a, low, high);
        quick_sort(a, low, pi - 1);   // left subarray
        quick_sort(a, pi + 1, high);  // right subarray
    }
}

void randarr(int a[], int n) {
    for (int i = 0; i < n; i++) {
        a[i] = rand() % 10000;  // random values
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
            quick_sort(temp, 0, n-1);
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
