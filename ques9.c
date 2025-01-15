#include <stdio.h>
#include <stdlib.h>

void removeChar(char *str, char c){
    int i = 0, j=0;
    while(str[i]){
        if(str[i] != c){
            str[j] = str[i];
            j++;
        }
        i++;
    }
    str[j] = '\0';

    printf("%s", str);
}

int main() {
    char input[1001];
    char c;
    printf("Enter a string: ");
    scanf("%1000[^\n]%*c", input);
    printf("Enter the character to remove: ");
    scanf("%c", &c);

    removeChar(input, c);

    return 0;
}