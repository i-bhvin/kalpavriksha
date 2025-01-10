
#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void reverse(int *arr, int n){
    for(int i=0, j=n-1; i<j; i++, j--){
        swap(&arr[i], &arr[j]);
    }
}

void handleInput(int **arr, int n){
    printf("Enter the elements of the array:\n");
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            scanf("%d", &arr[i][j]);
        }
    }
}

void transposeMatrix(int **arr, int n){
    for(int i=0; i<n; i++){
        for(int j=i; j<n; j++){
            swap(&arr[i][j], &arr[j][i]);
        }
    }
}

void rotateMatrix(int **arr, int n){
    
    transposeMatrix(arr, n);
    
    for(int i=0; i<n; i++){
        reverse(arr[i], n);
    }
    
}

void printMatrix(int **arr, int n){
    printf("\n");
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int n;
    printf("Enter the row and col (NxN):\n");
    scanf("%d", &n);
    
    int **arr = (int **)malloc(n * sizeof(int*));
    for(int i=0; i<n; i++){
        arr[i] = (int *)malloc(n * sizeof(int));
    }
    
    handleInput(arr, n);
    
    rotateMatrix(arr, n);
    
    printMatrix(arr, n);
    

    return 0;
}