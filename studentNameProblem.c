#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{

    int row, col;

    printf("Enter the number of rows:");
    scanf("%d", &row);
    printf("Enter the number of columns:");
    scanf("%d", &col);

    char ***names = (char ***)malloc(row * sizeof(char **));
    for (int i = 0; i < row; i++)
    {
        names[i] = (char **)malloc(col * sizeof(char *));
        for (int j = 0; j < col; j++)
        {
            names[i][j] = (char *)malloc(51 * sizeof(char));
        }
    }

    int vowelCount = 0, longestNameLength = 0;
    char *longestName = NULL;

    printf("Enter the names:\n");

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            printf("Name at (%d, %d):", i, j);
            scanf("%s", names[i][j]);

            if ( names[i][j][0] == 'A' || names[i][j][0] == 'E' || names[i][j][0] == 'I' || names[i][j][0] == 'O' || names[i][j][0] == 'U' || names[i][j][0] == 'a' || names[i][j][0] == 'e' || names[i][j][0] == 'i' || names[i][j][0] == 'o' || names[i][j][0] == 'u'){
                vowelCount++;
            }

            if (strlen(names[i][j]) > longestNameLength)
            {
                longestNameLength = strlen(names[i][j]);
                longestName = names[i][j];
            }
        }
    }

    printf("The 2D array of names is:\n");

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            printf("%s ", names[i][j]);
        }
        printf("\n");
    }

    printf("The number of names starting with a vowel:%d\n", vowelCount);
    printf("The longest name:%s", longestName);

    for (int i = 0; i < row; i++){
        for (int j = 0; j < col; j++){
            free(names[i][j]);
        }
        free(names[i]);
    }

    free(names); 

    return 0;
}