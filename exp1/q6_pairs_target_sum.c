#include <stdio.h>

int main(void) {
    int n, target, i, j, found = 0;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter %d elements: ", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter target value: ");
    scanf("%d", &target);

    printf("Pairs: ");
    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            if (arr[i] + arr[j] == target) {
                printf("(%d, %d)", arr[i], arr[j]);
                found = 1;
                if (i + 1 < n) {
                    int k, l;
                    for (k = i + 1; k < n; k++) {
                        for (l = k + 1; l < n; l++) {
                            if (arr[k] + arr[l] == target) {
                                printf(", ");
                                break;
                            }
                        }
                        if (k + 1 < n && l < n && arr[k] + arr[l] == target) {
                            break;
                        }
                    }
                }
                if (found && !((i == n - 2) && (j == n - 1))) {
                    printf(", ");
                }
            }
        }
    }

    if (!found) {
        printf("No pairs found");
    }
    printf("\n");

    return 0;
}
