#include <stdio.h>
#include<stdlib.h>
#define SIZE 4
//first in first out
struct Node{
    int data;
    struct Node* next;
};

struct Node* head;
int size = 0;

void showList(struct Node* node){
    if(node->next != NULL){
        printf("%d --> ", node->data);
        showList(node->next);
    }
    else{
        printf("%d --> END\n", node->data);
    }
} 
void insertAtEnd(struct Node* node, int element){
    if(node->next != NULL){
        insertAtEnd(node->next,element);
    }
    else{
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        node->next = newNode;
        newNode->data = element;
    }

}
void deleteAtBeginning(struct Node* head){
    head->data = head->next->data;
    head->next = head->next->next;
    printf("Node Deleted");
}

void dequeue(){
    if(size == 0){
        printf("Queue is empty\n");
    }
    else{
        size--;
        printf("Element %d removed\n",head->data);
        deleteAtBeginning(head);
    }
}

void enqueue(int element){
    if(size == SIZE){
        printf("Queue is full\n");
    }
    else{
        size++;
        if(size = 0){
            head->data = element;
        }
        else{
            insertAtEnd(head,element);
        }
        printf("Element %d added\n",element);
    }
}

void peek(){
    printf("Elements: ");
    showList(head);
}

void main(){
    head = (struct Node*)malloc(sizeof(struct Node));
    enqueue(1);
    enqueue(2);
    enqueue(3);
    enqueue(4);
    peek();    
    dequeue();
    showList(head);
}