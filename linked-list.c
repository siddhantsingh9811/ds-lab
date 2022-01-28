#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};


void showList(struct Node* node){
    if(node->next != NULL){
        printf("%d --> ", node->data);
        showList(node->next);
    }
    else{
        printf("%d --> END\n", node->data);
    }
} 

void main(){
    struct Node* head = (struct Node*)malloc(sizeof(struct Node));
    struct Node* second = (struct Node*)malloc(sizeof(struct Node));
    struct Node* third = (struct Node*)malloc(sizeof(struct Node));

    head->data = 1;
    head->next = second;

    second->data = 2;
    second->next = third;

    third->data = 3;

    showList(head);
}