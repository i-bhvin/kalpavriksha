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

void searchElement(int **arr, int rows, int cols, int target){

  int r = 0, c = cols - 1;
  int isFound = 0;

  while(r < rows && c >= 0){
    if(arr[r][c] == target){
      printf("Element %d found in the matrix at %d row, %d column.", target, r, c);
      isFound = 1;
      break;
    }
    else if(arr[r][c] < target){
      r++;
    }
    else{
      c--;
    }
  }

  if(!isFound){
    printf("Element %d not found in the matrix.", target);
  }

}


int main() {
  int rows = 0, cols = 0;
  int target = 0;
  printf("Enter the number of rows:\n");
  scanf("%d", &rows);
  printf("Enter the number of columns:\n");
  scanf("%d", &cols);

  int **arr = (int **)malloc(rows * sizeof(int *));

  for (int i = 0; i < rows; i++) {
    arr[i] = (int *)malloc(cols * sizeof(int));
  }

  handleInput(arr, rows, cols);

  printf("Enter the target:\n");
  scanf("%d",&target);

  searchElement(arr, rows, cols, target);


  return 0;
}