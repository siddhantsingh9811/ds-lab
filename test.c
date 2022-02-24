#include <stdio.h>
#include <stdlib.h>

struct Node{
    int p1;
    int p2; 
    struct Node* next;
};

void addPolynomials(struct Node* head){
    struct Node* cur = head;
    int count = 1;

    int sum = cur->p1 + cur->p2;
    printf("%d + ",sum);
    cur = cur->next;

    while(cur != NULL){

        int sum = cur->p1 + cur->p2;
        printf("%dx^%d +",sum,count);
        cur = cur->next;
        count++;
    }
    printf("\b");
}

void main(){
    int n;
    printf("Enter hightest degree of either polynomials: ");
    scanf("%d",&n);
    struct Node* head = (struct Node*)malloc(sizeof(struct Node));
    struct Node* cur = head;
    for(int i = 0; i<n+1; i++){
        if(i == 0){
            printf("Enter constant term of polynomial 1: ");
            scanf("%d",&head->p1);
            printf("Enter constant term of polynomial 2: ");
            scanf("%d",&head->p2);
            printf("\n");
        }
        else{
            struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
            cur->next = new_node;
            printf("Enter coefficient of x^%d of polynomial 1: ",i);
            scanf("%d",&new_node->p1);
            printf("Enter coefficient of x^%d of polynomial 2: ",i);
            scanf("%d",&new_node->p2);
            printf("\n");
            cur = new_node;
        }
    }
    addPolynomials(head);
}