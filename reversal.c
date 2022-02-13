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
void swap(struct Node* node){
    if(node->next != NULL){
        int tmp = node->data;
        node->data = node->next->data;
        node->next->data = tmp;
        swap(node->next);
    }
}
void reverse(struct Node* node){
    if(node->next != NULL){
        swap(node);
        struct Node* detached;
        struct Node* ptr = node;
        while(ptr->next->next != NULL){
            ptr = ptr->next;
        }
        detached = ptr->next;
        ptr->next = NULL;
        // showList(node);
        reverse(node);
        ptr->next = detached;
    }
}
void main(){
    struct Node* head = (struct Node*)malloc(sizeof(struct Node));
    int n;

    printf("Enter Number of Nodes: ");
    scanf("%d",&n);
    printf("Enter value: ");
    scanf("%d",&head->data);
    addNode(head,n-1);
    printf("\n");
    showList(head);
    reverse(head);
    // swap(head);
    showList(head);
}