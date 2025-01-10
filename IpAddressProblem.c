// Online C compiler to run C program online
#include <stdio.h>
#include<stdlib.h>


int isDigit(char *s){
    return (*s >= '0' && *s <= '9');
}

int isDot(char *s){
    return (*s == '.');
}

void isValidIPAddress(char *str){
    int dotCount = 0;
    int alreadyInvalid = 0, isFirstCharacter = 1;
    while(*str){
        if(isDot(str)){
            dotCount++;

            if(isFirstCharacter || dotCount >= 4 || *(str + 1) == '\0' || *(str + 1) == '.'){
                alreadyInvalid = 1;
                break;
            }
            
            str++;
        }
        else if(isDigit(str)){
            
            if(*str == '0' && *(str + 1) != '\0' && *(str + 1) != '.'){
                alreadyInvalid = 1;
                break;
            }
            
            
            int num = 0;
            while(isDigit(str)){
                num = num*10 + ((*str) - '0');
                str++;
            }
            str--;
            
            if(num < 0 || num > 255){
                alreadyInvalid = 1;
                break;
            }
        }
        else {
            alreadyInvalid = 1;
            break;
        }
        isFirstCharacter = 0;
        str++;
    }
    if(alreadyInvalid){
        printf("Invalid");
        alreadyInvalid = 1;
    }
    
    if(alreadyInvalid == 0 && dotCount < 3){
        printf("Invalid");
        alreadyInvalid = 1;
    } 
    
    if(alreadyInvalid == 0 && *str == '\0') printf("Valid");
    
}


int main() {
    char input[16];
    printf("Enter the IP Address:\n");
    scanf("%s", input);
    
    isValidIPAddress(input);
    
    

    return 0;
}
