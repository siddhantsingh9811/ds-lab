#include <stdio.h>
#include<stdlib.h>
#include <string.h>

struct Node{
    char data;
    struct Node* next;
};

struct Node* top;

void push(char val)
{
    struct Node* newNode = malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = top;
    top = newNode;
}
void pop(){
    struct Node* tmp;
    if(top != NULL){
        printf("%c",top->data);
        tmp = top;
        top = top->next;

        free(tmp);
    }
    else{
        printf("Stack is empty\n");
    }
}

void main(){
    char s[20];
    printf("Enter string: ");
    fgets(s,20, stdin);
    for(int i = 0; i<strlen(s);i++){
        push(s[i]);
    }
    for(int i = 0; i<strlen(s);i++){
        pop();
    }
    printf("\n");
}