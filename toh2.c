#include <stdio.h>
#include<stdlib.h>

#define DISKS 5

struct Tower{
    int items[DISKS];
    int top;
    struct Tower* next;
};

int count = 0;

void showTowers(struct Tower* Tower1){
    for(int i = 0; i<DISKS; i++){
        struct Tower* cur = Tower1;
        printf("|   %d   |",cur->items[i]);
        cur = cur->next;
        while(cur != Tower1){
            printf("|   %d   |",cur->items[i]);
            cur = cur->next;
        }
        printf("\n");
    }
    printf("  Tower1 ");
    printf("  Tower2 ");
    printf("  Tower3 \n");
    printf("\n");
}
void pop(struct Tower* Tower){
    int top = Tower->top;
    for(int i = 0; i<DISKS; i++){
        if(Tower->items[i] == top){
            Tower->items[i] = 0;
            if(i != DISKS-1){
                Tower->top = Tower->items[i+1];
            }
            else{
                Tower->top = 0;
            }
        }
    }
}
void push(struct Tower* Tower, int n){
    Tower->top = n;
    for(int i = DISKS-1; i>=0; i--){
        if(Tower->items[i] == 0){
            Tower->items[i] = n;
            break;
        }
    }
}
void move(struct Tower* initial, struct Tower* destination){
    int top = initial->top;
    pop(initial);
    push(destination,top);
}

void TOH(int n, struct Tower* Tower1, struct Tower* Tower2, struct Tower* Tower3, struct Tower* start){
    if(n == 0){
        return;
    }
    else{
        TOH(n-1, Tower1, Tower3, Tower2,start);
        move(Tower1, Tower3);
        count++;
        showTowers(start);
        TOH(n-1, Tower2, Tower1, Tower3,start);
    }
}

void main(){
    // create towers 0 -> empty
    struct Tower* Tower1 = (struct Tower*)malloc(sizeof(struct Tower));
    for (int i = 0; i<DISKS; i++){
        Tower1->items[i] = i+1;
    }
    Tower1->top = Tower1->items[0];

    struct Tower* Tower2 = (struct Tower*)malloc(sizeof(struct Tower));
    for (int i = 0; i<DISKS; i++){
        Tower2->items[i] = 0;
    }
    Tower2->top = 0;

    struct Tower* Tower3 = (struct Tower*)malloc(sizeof(struct Tower));
    for (int i = 0; i<DISKS; i++){
        Tower3->items[i] = 0;
    }
    Tower3->top = 0;

    Tower1->next = Tower2;
    Tower2->next = Tower3;
    Tower3->next = Tower1;
    showTowers(Tower1);
    TOH(DISKS, Tower1, Tower2, Tower3,Tower1);
    showTowers(Tower1);
    printf("Solved in %d moves\n",count);
}

