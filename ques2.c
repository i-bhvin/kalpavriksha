#include <stdio.h>

void countWords(char *str){
    int wordCount = 0;
    while(*str){
        if(*str != ' '){
            wordCount++;
            while(*str != ' ' && *str != '\0'){
                str++;
            }
        }
        else{
            str++;
        }
    }

    printf("Word count: %d", wordCount);
}

int main() {
    char input[1001];
    printf("Enter a string: ");
    scanf("%1000[^\n]%*c", input);

    countWords(input);
    return 0;
}