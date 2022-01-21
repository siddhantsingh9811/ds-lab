#include <stdio.h>
#include <stdlib.h>
struct subject{
    char name[20];
    int code;
};

void main(){
    int n;
    printf("Enter number of elements: ");
    scanf("%d",&n);

    struct subject* subjects = (struct subject*)malloc(n*sizeof(struct subject));

    for(int i = 0; i<n; i++){
        printf("Enter Subject Name: ");
        scanf("%s", subjects[i].name);
        printf("Enter Subject Code: ");
        scanf("%d", &subjects[i].code);
    }
    
    for(int i = 0; i<n; i++){
        printf("Product numbner %d\n",i+1);
        printf("Product name: %s\n",subjects[i].name);
        printf("Product code: %d\n",subjects[i].code);
        printf("\n\n");
    }
    
}
