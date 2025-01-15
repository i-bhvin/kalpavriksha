#include <stdio.h>

int stringLength(char *s){
    int len = 0;
    while(*s){
        len++;
        s++;
    }
    return len;
}

int stringCompare(char *s1, char *s2){
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

void stringSearch(char *s, char *sub, int len){
    int i=0, isFound = 0;
    while(i < len){
        if(stringCompare(s + i, sub) == 0){
            isFound = 1;
            printf("%d", i);
            break;
        }
        i++;
    }

    if(!isFound){
        printf("-1");
    }
}

int main() {
    char string[1001];
    char subString[1001];
    printf("Enter a string: ");
    scanf("%1000[^\n]%*c", string);

    printf("Enter the substring to search: ");
    scanf("%1000[^\n]%*c", subString);

    int len = stringLength(string);

    stringSearch(string, subString, len);
    return 0;
}