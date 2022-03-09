#include <stdio.h>
#include<stdlib.h>
#include <string.h>

struct Node{
    char data;
    struct Node* next;
};

struct dict{
    char c;
    int value;
};
//operator stack
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
        if(top->data!='(' && top->data!=')'){
            printf("%c",top->data);
        }
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
        printf("%c->",tmp->data);
        tmp = tmp->next;
    }
    printf("END\n");
}

int isOperand(char s){
    if(s>='A' && s<='Z'){
        return 1;
    }
    else{
        return 0;
    }
}
int getPrecedence(char c){
    struct dict precedence_order[6];
    precedence_order[0].c = '(';
    precedence_order[0].value = 0;
    
    precedence_order[1].c = '-';
    precedence_order[1].value = 1;
    
    precedence_order[2].c = '+';
    precedence_order[2].value = 1;

    precedence_order[3].c = '*';
    precedence_order[3].value = 2;

    precedence_order[4].c = '/';
    precedence_order[4].value = 2;

    precedence_order[5].c = '^';
    precedence_order[5].value = 3;

    for(int i = 0; i<6; i++){
        if(precedence_order[i].c == c){
            return precedence_order[i].value;
        }
    }
}

void toPostfix(char str[20]){
    for(int i = 0; i<strlen(str)-1; i++){
        if(isOperand(str[i])){
            printf("%c",str[i]);
        }
        else{
            if(str[i]!='(' && str[i]!=')'){
                if(getPrecedence(str[i]) > getPrecedence(top->data)){
                    push(str[i]);
                }
                else if(getPrecedence(str[i]) <= getPrecedence(top->data)){
                    while(getPrecedence(str[i]) <= getPrecedence(top->data) && top->data != '('){
                        pop();
                    }
                    push(str[i]);
                }
            }
            else{
                if(str[i] == '('){
                    push(str[i]);
                }
                else{
                    while(top->data!='('){
                        pop();
                    }
                    pop();
                }
            }
        }
    }
    while(top != NULL){
        pop();
    }
}


void main(){
    char str[20];
    struct Node* head = (struct Node*)malloc(sizeof(struct Node));
    printf("Enter Equation in infix notation: ");
    fgets(str,20,stdin);
    push('(');
    toPostfix(str);
}