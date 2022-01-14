#include <stdio.h>
#include <string.h>

void main(){
    char str[20];
    char l[20];
    
    printf("Enter string: ");
    scanf("%s",str);
    int n = 0;
    while(str[n]!= '\0'){
        l[n] = str[n] + 32;
        n++;
    }
    printf("lowercase string is: %s",l);
}