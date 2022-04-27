#include <stdio.h>
#include <stdlib.h>

void main(){
    int l1[25],l2[25],s1,s2;
    printf("Enter Size of list 1: ");
    scanf("%d",&s1);
    for(int i = 0; i<s1; i++){
        printf("Enter Element: ");
        scanf("%d",&l1[i]);
    }

    printf("Enter Size of list 2: ");
    scanf("%d",&s2);
    for(int i = 0; i<s2; i++){
        printf("Enter Element: ");
        scanf("%d",&l2[i]);
    }

    int *l3 = (int*)malloc((s1+s2)*sizeof(int));
    l3 = &l1[0];
    int c = 0;
    for(int i = s1; i<s1+s2; i++){
        l3[i] = l2[c];
        c++;
    }

    for(int i = 0; i<s1+s2; i++){
        printf("%d ",l3[i]);
    }
}