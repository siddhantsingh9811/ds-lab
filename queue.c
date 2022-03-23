#include <stdio.h>
#include<stdlib.h>
#define SIZE 4
// first in first out woooooooooooooooo

int front,rear,queue[SIZE];

void initializeQueue(){
    front = -1;
    rear = -1;
}
void enqueue(int element);
void dequeue();
void peek();

void main(){
    initializeQueue();
    enqueue(1);
    enqueue(2);
    enqueue(3);
    peek();
    dequeue();
    dequeue();
    dequeue();
    dequeue();
    enqueue(1);
    enqueue(2);
    enqueue(3);
    enqueue(4);
    enqueue(5);
}

void dequeue(){
    if(front == -1){
        printf("Queue is Empty\n");
    }
    else{
        printf("Element %d removed\n",queue[front]);
        front++;
        if (front > rear){
            front = -1;
            rear = -1;
        }
    }
}

void enqueue(int element){
    if(rear == SIZE -1){
        printf("Queue is Full");
    }
    else{
        if(front == -1){
            front = 0;
        }
        rear++;
        queue[rear] = element;
        printf("Element %d inserted\n",element);
    }
}
void peek(){
    if(rear == -1){
        printf("Queue is empty\n");
    }
    else{
        printf("Elements:\n");
        for(int i = 0; i<=rear; i++){
            printf("%d\n",queue[i]);
        }
    }
}
