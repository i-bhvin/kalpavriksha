#include <stdio.h>
#include <stdlib.h>

int binarySearch(int *arr, int n, int key) {
    int start = 0, end = n - 1;
    int mid = start + (end - start)/2;
    while (start <= end) {
        if (arr[mid] == key) {
            return mid;
        } else if (arr[mid] < key) {
            start = mid + 1;
        } else {
            end = mid - 1;
        }
        mid = start + (end - start) / 2;
    }

    return -1;
}

int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int *arr = (int *)malloc(n * sizeof(int));
    printf("Enter the sorted array: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    int key;
    printf("Enter the element to search: ");
    scanf("%d", &key);

    int index = binarySearch(arr, n, key);

    if (index == -1) {
        printf("Element not found\n");
    } else {
        printf("Element found at index %d\n", index);
    }
    return 0;
}