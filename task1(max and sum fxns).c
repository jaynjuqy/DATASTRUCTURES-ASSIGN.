#include <stdio.h>

int maximum(int arr[], int size) {
    int max = arr[0]; 

    for (int i = 1; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }

    return max;
}

int summation(int arr[], int size) {
    int sum = 0;

    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }

    return sum;
}

int main() {
    int n;

    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int numbers[n];

    printf("Enter %d numbers:\n", n);
    for (int i = 0; i < n; i++) {
        printf("Enter number %d: ", i + 1);
        scanf("%d", &numbers[i]);
    }

    int max = maximum(numbers, n);
    printf("The maximum value in the array is: %d\n", max);

    int sum = summation(numbers, n);
    printf("The sum of the numbers in the array is: %d\n", sum);

    return 0;
}
