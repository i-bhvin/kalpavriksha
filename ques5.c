#include <stdio.h>
#include <stdlib.h>

int isDigit(char *c){
    return (*c >= '0' && *c <= '9');
}

int customATOI(char *str){
    int num = 0, isNegative = 0;
    
    if(*str == '-'){
        isNegative = 1;
        str++;
    }
    while(*str){
        if(!isDigit(str)){
            return 0;
        }
        num = num * 10 + (*str - '0');
        str++;
    }
    if(isNegative){
        num = -num;
    }
    return num;
}

int main() {
    char string[101];
    printf("Enter a number: ");
    scanf("%100[^\n]%*c", string);

    int num = customATOI(string);

    printf("%d", num);
    return 0;
}