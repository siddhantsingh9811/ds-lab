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

void showMatrix(int r, int c, int (*matrix)[10]){   
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            printf(" %d ",matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}


void main(){
    int r1,c1,r2,c2;
    int matrix1[10][10], matrix2[10][10], matrix[10][10];

    printf("Matrix 1\n");
    printf("\nEnter no of rows: ");
    scanf("%d",&r1);
    printf("\nEnter no of columns: ");
    scanf("%d",&c1);

    getMatrix(r1,c1,matrix1);
    showMatrix(r1,c1,matrix1);
    
    printf("\n\nMatrix 2\n");
    printf("\nEnter no of rows: ");
    scanf("%d",&r2);
    printf("\nEnter no of columns: ");
    scanf("%d",&c2);

    getMatrix(r2,c2,matrix2);
    showMatrix(r2,c2,matrix2);

    if(c2 == r1){
        printf("Matrices are Compatible\n");
        int r = r1;
        int c = c2;

        for(int i = 0; i < r; i++){
            for(int j = 0; j < c; j++){
                int sum = 0;
                for (int k = 0; k < r2; k++) {
                sum += matrix1[i][k] * matrix2[k][j];
                }
                matrix[i][j] = sum;
            }
        }
        printf("Multiplication of the 2 matrices is:\n");
        showMatrix(r,c,matrix);
    }
    else{
        printf("Incompatible matrices\n");
    }
}