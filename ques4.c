#include <stdio.h>
#include <stdlib.h>

int stringLength(char *s)
{
    int len = 0;
    while (*s)
    {
        len++;
        s++;
    }
    return len;
}

void stringCopy(char *dest, char *src)
{
    char *temp = src;
    while (*src)
    {
        *dest = *src;
        dest++;
        src++;
    }

    src = temp;
    while (*src)
    {
        *dest = *src;
        dest++;
        src++;
    }

    *dest = '\0';
}

int stringCompare(char *s1, char *s2)
{
    while(*s1 && *s2){
        if(*s1 != *s2){
            return 1;
        }
        s1++;
        s2++;
    }
    if(*s2 == '\0'){
        return 0;
    }
    return 1;
}

void checkRotate(char *str, char *s, int len)
{
    int i = 0;
    while(i < len){
        if(stringCompare(str + i, s) == 0){
            printf("true");
            return;
        }
        i++;
    }
    printf("false");
}

int main()
{
    char string1[1001];
    char string2[1001];
    printf("Enter string1: ");
    scanf("%1000[^\n]%*c", string1);

    printf("Enter string2: ");
    scanf("%1000[^\n]%*c", string2);



    int len1 = stringLength(string1);
    int len2 = stringLength(string2);

    if(len1 != len2){
        printf("false");
        return 0;
    }
    char *str = (char *)malloc((2 * len1 + 1) * sizeof(char));

    stringCopy(str, string1);

    checkRotate(str, string2, len1);
    return 0;
}