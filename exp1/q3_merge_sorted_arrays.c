#include <stdio.h>

int main(void) {
    int m, n, i, j, k;

    printf("Enter size of first sorted array: ");
    scanf("%d", &m);
    printf("Enter size of second sorted array: ");
    scanf("%d", &n);

    int a[m], b[n], merged[m + n];

    printf("Enter first sorted array: ");
    for (i = 0; i < m; i++) {
        scanf("%d", &a[i]);
    }

    printf("Enter second sorted array: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &b[i]);
    }

    i = 0; j = 0; k = 0;
    while (i < m && j < n) {
        if (a[i] <= b[j]) {
            merged[k++] = a[i++];
        } else {
            merged[k++] = b[j++];
        }
    }

    while (i < m) merged[k++] = a[i++];
    while (j < n) merged[k++] = b[j++];

    printf("Merged sorted array: ");
    for (i = 0; i < m + n; i++) {
        printf("%d ", merged[i]);
    }
    printf("\n");

    return 0;
}
