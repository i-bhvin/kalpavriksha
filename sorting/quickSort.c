#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int *arr, int s, int e){
    
    int pivot = arr[s];
    int count = 0;
    for(int i=s; i <= e; i++){
        if(arr[i] < pivot){
            count++;
        }
    }

    int pivotIndex = s + count;
    swap(&arr[s], &arr[pivotIndex]);

    int i = s, j = e;
    while(i < pivotIndex && j > pivotIndex){
        if(arr[i] < pivot){
            i++;
        }else if(arr[j] >= pivot){
            j--;
        }else{
            swap(&arr[i], &arr[j]);
            i++;
            j--;
        }
    }

    return pivotIndex;
    
}

void quickSort(int *arr, int s, int e){
    if(s >= e) return;
    
    int p = partition(arr, s, e);

    quickSort(arr, s, p-1);
    quickSort(arr, p+1, e);
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

    quickSort(arr, 0, n-1);

    printf("Sorted array: \n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}