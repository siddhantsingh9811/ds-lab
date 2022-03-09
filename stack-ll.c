#include <stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

struct Node* top;


void push(int val)
{
    struct Node* newNode = malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = top;
    top = newNode;
}
void pop(){
    struct Node* tmp;
    if(top != NULL){
        printf("Popped Element %d\n",top->data);
        tmp = top;
        top = top->next;

        free(tmp);
    }
    else{
        printf("Stack is empty\n");
    }
}
void display(){
    struct Node* tmp = top;
    while(tmp != NULL){
        printf("%d->",tmp->data);
        tmp = tmp->next;
    }
    printf("END\n");
}
void main(){
    push(1);
    push(2);
    push(3);
    display();
    pop();
    display();
}