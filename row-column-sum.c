#include <stdio.h>

void getMatrix(int r,int c, int (*matrix)[10]){
    for(int i = 0; i < r; i++){
        int r = i+1;
        printf("Row %d\n", r);
        for(int j = 0; j < c; j++){
            printf("Enter element: ");
            scanf("%d",&matrix[i][j]);
        }
    }
}

void main(){
    int matrix[10][10];
    int r,c;

    printf("\nEnter no of rows: ");
    scanf("%d",&r);
    printf("\nEnter no of columns: ");
    scanf("%d",&c);

    getMatrix(r,c,&matrix);

    for(int i = 0; i<r; i++){
        int sumr = 0;
        for(int j = 0; j<c; j++){
            sumr+= matrix[i][j];
        }
        printf("Sum of rows: %d", sumr);
    }   
    for(int i = 0; i<r; i++){
        int sumc = 0;
        for(int j = 0; j<c; j++){
            sumc+= matrix[j][i];
        }
        printf("Sum of columns: %d", sumc);
    }   
}