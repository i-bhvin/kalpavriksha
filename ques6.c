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


void checkAnagram(char *word1, char *word2) {

    int len1 = stringLength(word1);
    int len2 = stringLength(word2);

    if(len1 != len2){
        printf("false");
        return;
    }

    int map[128] = {0};
    
    while(*word1 && *word2){
        map[*word1]++;
        map[*word2]--;
        word1++;
        word2++;
    }

    for(int i=0; i<128; i++){
        if(map[i] != 0){
            printf("false");
            return;
        }
    }

    printf("true");
}

int main() {
    char word1[101];
    char word2[101];
    printf("Enter the first word: ");
    scanf("%100[^\n]%*c", word1);
    printf("Enter the second word: ");
    scanf("%100[^\n]%*c", word2);

    checkAnagram(word1, word2);
    return 0;
}