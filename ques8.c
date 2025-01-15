#include <stdio.h>
#include <stdlib.h>

void convertCount(int count, char *result, int *j)
{
    int i = 0;
    char countStr[100];
    while (count)
    {
        countStr[i] = (count % 10) + '0';
        count = count / 10;
        i++;
    }
    i--;
    while (i >= 0)
    {
        result[*j] = countStr[i];
        i--;
        (*j)++;
    }
}

int stringLength(char *str)
{
    int i = 0;
    while (str[i])
    {
        i++;
    }
    return i;
}

void compressString(char *str, char *result)
{
    int i = 0, j = 0;
    while (str[i])
    {
        int count = 1;
        result[j++] = str[i];
        while (str[i] == str[i + 1])
        {
            count++;
            i++;
        }
        convertCount(count, result, &j);
        i++;
    }
    result[j] = '\0';

    if (stringLength(result) > stringLength(str))
    {
        printf("%s", str);
    }
    else
        printf("%s", result);
}

int main()
{
    char input[1001];
    char result[1001];

    printf("Enter a string: ");
    scanf("%1000[^\n]%*c", input);

    compressString(input, result);

    return 0;
}