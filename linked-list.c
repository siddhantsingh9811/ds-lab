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

void insertAtEnd(struct Node* node){
    if(node->next != NULL){
        insertAtEnd(node->next);
    }
    else{
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        node->next = newNode;
        printf("Enter value: ");
        scanf("%d",&newNode->data);
    }

}

int insertAtn(struct Node* node, int n){
    if(n != 0){
        n--;
        insertAtn(node->next,n);   
    }
    else{
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->next = node->next;
        node->next = newNode;
        printf("Enter value: ");
        scanf("%d",&newNode->data);
        return 0;
    }
}

void insertAtBeginning(struct Node* head){
    int tmp;
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    tmp = head->data;
    printf("Enter value: ");
    scanf("%d",&head->data);
    newNode->next = head->next;
    head->next = newNode;
    newNode->data = tmp;
}

void deleteAtEnd(struct Node* node){
    if(node->next->next != NULL){
        deleteAtEnd(node->next);
    }
    else{
        free(node->next);
        node->next = NULL;
        printf("Node Deleted\n");
    }
}
int deleteAtn(struct Node* node, int n){
    if(n != 0){
        n--;
        deleteAtn(node->next,n);   
    }
    else{

        node->next = node->next->next;
        return 0;
    }
}
void deleteAtBeginning(struct Node* head){
    head->data = head->next->data;
    head->next = head->next->next;
    printf("Node Deleted");
}
void main(){
    struct Node* head = (struct Node*)malloc(sizeof(struct Node));
    struct Node* current = (struct Node*)malloc(sizeof(struct Node));
    int n;
    int c;
    printf("Enter Number of Nodes: ");
    scanf("%d",&n);
    printf("Enter value: ");
    scanf("%d",&head->data);
    addNode(head,n-1);
    printf("\n");
    while(1){
        printf("Enter 0 to exit, 1 to show entire list, 2 to insert at end, 3 to insert at nth position, 4 to insert at beginning, 5 to delete at end, 6 to delete at nth position, 7 to delete at beginning: ");
        scanf("%d",&c);
        if(c == 0){
            break;
        }
        else if(c == 1){
            showList(head);
        }
        else if(c == 2){
            insertAtEnd(head);
        }
        else if(c == 3){
            int n;
            printf("Enter n: ");
            scanf("%d",&n);
            insertAtn(head,n-2);
        }
        else if(c == 4){
            insertAtBeginning(head);
        }
        else if(c == 5){
            deleteAtEnd(head);
        }
        else if(c == 6){
            int n;
            printf("Enter n: ");
            scanf("%d",&n);
            deleteAtn(head,n-2);
        }
        else if(c == 7){
            deleteAtBeginning(head);
        }
    }
}