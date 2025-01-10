#include<stdio.h>
#include<stdlib.h>

void handleInput(int **matrix, int n){
  printf("Enter the elements of the array:\n");
  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
      scanf("%d", &matrix[i][j]);
    }
  }
}

int diagonalSum(int **matrix, int n){
  int sum =0;
  for(int i=0; i<n; i++){
    sum += matrix[i][i];
  }

  for(int i=0, j=0; i<n && j<n; i++, j++){
      sum += matrix[n-1-j][n-1-i];
  }


  if(n%2 != 0){
    sum -= matrix[n/2][n/2];
  }
  return sum;
}

int main(){
  int n;
  printf("Enter the number of rows and cols (NxN) : ");
  scanf("%d", &n);
  

  int **matrix = (int **)malloc(n * sizeof(int *));
  for(int i=0; i<n; i++){
    matrix[i] = (int *)malloc(n * sizeof(int));
  }

  handleInput(matrix, n);

  int result = diagonalSum(matrix, n);

  printf("The sum of the diagonal elements is : %d", result);
  return 0;
    
}