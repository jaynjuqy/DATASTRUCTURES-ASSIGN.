#include <stdio.h>

int findSingle(int arr[], int n) {
    int result = 0;

    for (int i = 0; i < n; i++) {
        result ^= arr[i];
    }

    return result;
}

int main() {
    int arr[] = {1, 2, 3, 4, 3, 2, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    int uniqueElement = findSingle(arr, n);

    printf("\nThe single integer that appears only once: %d\n", uniqueElement);

    return 0;
}
