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

int addNode(struct Node* node, int n){
    if(n!=0){
        n--;
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        node->next = newNode;
        printf("Enter value: ");
        scanf("%d",&newNode->data);
        addNode(newNode,n);
    }
    else{
        return 0;
    }
}
void removeValue(struct Node* node, int value){
    struct Node* tmp;
    if(node->data != value){
        removeValue(node->next,value);
    }
    else{
        tmp = node->next;
        node->data = node->next->data;
        node->next = node->next->next;
        free(tmp);
    }
}

void main(){
    struct Node* head = (struct Node*)malloc(sizeof(struct Node));
    int value;
    printf("Enter value: ");
    scanf("%d",&head->data);
    addNode(head,5);

    showList(head);

    printf("Enter value to be deleted: ");
    scanf("%d",&value);
    removeValue(head, value);
    showList(head);
}
