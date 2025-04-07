#include <stdio.h>
#include <stdlib.h>

void merge(int *arr, int s, int mid, int e){
    int len1 = mid - s + 1;
    int len2 = e - mid;

    int *left = (int *)malloc(len1 * sizeof(int));
    int *right = (int *)malloc(len2 * sizeof(int));

    for(int i = 0; i < len1; i++){
        left[i] = arr[s + i];
    }
    for(int i = 0; i < len2; i++){
        right[i] = arr[mid + 1 + i];
    }

    int i = 0, j = 0, k = s;

    while(i < len1 && j < len2){
        if(left[i] <= right[j]){
            arr[k++] = left[i++];
        }else{
            arr[k++] = right[j++];
        }
    }

    while(i < len1){
        arr[k++] = left[i++];
    }
    while(j < len2){
        arr[k++] = right[j++];
    }    
}

void mergeSort(int *arr, int s, int e){
    if(s >= e) return;
    int m = s + (e - s) / 2;
    mergeSort(arr, s, m);
    mergeSort(arr, m+1, e);
    merge(arr, s, m, e);
}

int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int *arr = (int *)malloc(n * sizeof(int));
    printf("Enter the elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    mergeSort(arr, 0, n-1);

    printf("Sorted array: \n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}