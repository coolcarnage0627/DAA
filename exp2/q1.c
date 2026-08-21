#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int linearSearch(int arr[], int n, int key) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == key)
            return i;
    }
    return -1;
}

int binarySearch(int arr[], int low, int high, int key) {
    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == key)
            return mid;
        else if (arr[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

void fillRandomArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 10000 + 1;
    }
}

void sortArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] > arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

int main() {
    int sizes[] = {100, 200, 500, 1000, 2000, 5000};
    int count = sizeof(sizes) / sizeof(sizes[0]);

    printf("Array Size  | Linear Search Time (ms) | Binary Search Time (ms)\n");
    printf("-----------------------------------------------------------\n");

    for (int i = 0; i < count; i++) {
        int n = sizes[i];
        int *arr = (int *)malloc(n * sizeof(int));
        int key = 9999;

        fillRandomArray(arr, n);
        sortArray(arr, n);

        clock_t start, end;
        double linearTime, binaryTime;

        start = clock();
        linearSearch(arr, n, key);
        end = clock();
        linearTime = ((double)(end - start)) * 1000.0 / CLOCKS_PER_SEC;

        start = clock();
        binarySearch(arr, 0, n - 1, key);
        end = clock();
        binaryTime = ((double)(end - start)) * 1000.0 / CLOCKS_PER_SEC;

        printf("%9d  | %22.4f | %21.4f\n", n, linearTime, binaryTime);

        free(arr);
    }

    return 0;
}
