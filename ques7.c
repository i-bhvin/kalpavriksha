#include <stdio.h>
#include <stdlib.h>

void getLongestWord(char *str){
    int maxLen = 0, len = 0;
    int maxStart = 0, start = 0;
    int i=0;
    while(str[i] != '\0'){
        if(str[i] != ' '){
            start = i;
            len = 0;
            while(str[i] != ' ' && str[i] != '\0'){
                i++;
                len++;
            }
            
            if(len > maxLen){
                maxLen = len;
                maxStart = start;
            }
        }
        else{
            i++;
        }
    }

    for(int i=maxStart; i<maxStart + maxLen; i++){
        printf("%c", str[i]);
    }
}

int main() {
    
    char string[1001];
    printf("Enter a string: ");
    scanf("%1000[^\n]%*c", string);

    getLongestWord(string);
    return 0;
}