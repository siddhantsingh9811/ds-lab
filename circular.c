#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data; // 0 -> empty and 1 -> full
    struct Node* next;
};

void showNodes(struct Node* head){
    struct Node* cur = head;

    do{
        printf("%d -> ",cur->data);
        cur = cur->next;
    } while (cur->next != head);
    
    printf("%d -> End", cur->data);
}

void addNodes(struct Node* head,  int size){
    struct Node* cur = head;
    for(int i = 0; i<size-1; i++){
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        cur->next = newNode;
        printf("Enter value: ");
        scanf("%d",&newNode->data);
        cur = newNode;
    }
    cur->next = head;
}

void main(){
    struct Node* head = (struct Node*)malloc(sizeof(struct Node));
    int n;
    printf("Enter Number of Nodes: ");
    scanf("%d",&n);
    printf("Enter value: ");
    scanf("%d",&head->data);
    addNodes(head,n);
    showNodes(head);
}
