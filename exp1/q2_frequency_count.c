#include <stdio.h>

int main(void) {
    int n, i, j, count;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter %d elements: ", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int visited[n];
    for (i = 0; i < n; i++) {
        visited[i] = 0;
    }

    printf("Frequency of each distinct element:\n");
    for (i = 0; i < n; i++) {
        if (!visited[i]) {
            count = 1;
            for (j = i + 1; j < n; j++) {
                if (arr[j] == arr[i]) {
                    count++;
                    visited[j] = 1;
                }
            }
            printf("%d -> %d\n", arr[i], count);
            visited[i] = 1;
        }
    }

    return 0;
}
