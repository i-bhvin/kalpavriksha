#include <stdio.h>
#include <stdlib.h>

void handleInput(int **arr, int rows, int cols) {
   printf("Enter the elements of the array:\n");
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      scanf("%d", &arr[i][j]);
    }
  }
}

void getRowMinimum(int **arr, int rows, int cols, int *rowMinimum){
  
  for (int i = 0; i < rows; i++) {
    int min = arr[i][0];
    for (int j = 0; j < cols; j++) {
      if (arr[i][j] < min){
        min = arr[i][j];
      }
    }
    rowMinimum[i] = min;
  }
  
}
void getColMaximum(int **arr, int rows, int cols, int *colMaximum){
  
  for (int i = 0; i < rows; i++) {
    int max = arr[0][i];
    for (int j = 0; j < cols; j++) {
      if (arr[j][i] > max){
        max = arr[j][i];
      }
    }
      colMaximum[i] = max;
  }
}

void saddlePoint(int **arr, int rows, int cols, int *rowMinimum, int *colMaximum){

  int flag = 0;
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      if(arr[i][j] == rowMinimum[i] && arr[i][j] == colMaximum[j]){
        printf("%d\n", arr[i][j]);
        flag = 1;
      }
    }
  }

  if(flag == 0){
    printf("-1");
  }
  
}

int main() {
  int rows = 0, cols = 0;
  printf("Enter the number of rows:\n");
  scanf("%d", &rows);
  printf("Enter the number of columns:\n");
  scanf("%d", &cols);

  int **arr = (int **)malloc(rows * sizeof(int *));

  for (int i = 0; i < rows; i++) {
    arr[i] = (int *)malloc(cols * sizeof(int));
  }

  handleInput(arr, rows, cols);

  int *rowMinimum = (int *)malloc(rows * sizeof(int));
  int *colMaximum = (int *)malloc(cols * sizeof(int));


  getRowMinimum(arr, rows, cols, rowMinimum);
  getColMaximum(arr, rows, cols, colMaximum);


  saddlePoint(arr, rows, cols, rowMinimum, colMaximum);

  return 0;
}