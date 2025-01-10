#include<stdio.h>
#include<stdlib.h>

void handleInput(int **matrix, int m, int n){
  printf("Enter the elements of the array:\n");
  for(int i=0; i<m; i++){
    for(int j=0; j<n; j++){
      scanf("%d", &arr[i][j]);
    }
  }
}

int main(){
  int rows=0, cols=0;
  printf("Enter the number of rows:\n");
  scanf("%d", &rows);
  printf("Enter the number of columns:\n");
  scanf("%d", &cols);

  int **arr = (int **)malloc(rows * sizeof(int*));

  for(int i=0; i<rows; i++){
    arr[i] = (int *)malloc(cols * sizeof(int));
  }

  handleInput(arr,rows,cols);

  // Different ways to access the 2D array


  printf("1st way\n");

  for(int i=0; i<rows; i++){
    for(int j=0; j<cols; j++){
      printf("%d ", arr[i][j]);
    }
    printf("\n");
  }
  
  printf("\n2nd way\n");

  for(int i=0; i<rows; i++){
    for(int j=0; j<cols; j++){
      printf("%d ", *(*(arr + i) + j));
    }
    printf("\n");
  }

  return 0;
    
}