#include <stdio.h>
#include <limits.h>

int main(void) {
    int n, i;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter %d elements: ", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int largest = INT_MIN, second = INT_MIN;
    for (i = 0; i < n; i++) {
        if (arr[i] > largest) {
            second = largest;
            largest = arr[i];
        } else if (arr[i] > second && arr[i] != largest) {
            second = arr[i];
        }
    }

    if (second == INT_MIN) {
        printf("No second-largest distinct element exists.\n");
    } else {
        printf("Second largest distinct element = %d\n", second);
    }

    return 0;
}
