#include <stdio.h>

void removeDuplicate(char *str){
    int map[128] = {0};

    while(*str){
        int index = (*str);
        if(map[index] == 0){
            map[index]++;
            printf("%c", (*str));
        }
        str++;
    }
}

int main() {
    char input[1001];
    printf("Enter a string: ");
    scanf("%1000[^\n]%*c", input);
    removeDuplicate(input);
    return 0;
}