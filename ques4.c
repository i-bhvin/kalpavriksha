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

void frequencyCount(int **arr, int rows, int cols){
  int mapping[101] = {0};

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      mapping[arr[i][j]]++;
    }
  }

  for (int i = 1; i < 101; i++) {
    if (mapping[i] > 0) {
      printf("%d -> %d times\n", i, mapping[i]);
    }
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

  frequencyCount(arr, rows, cols)

  
  return 0;
}