#include <stdio.h>

int array[] = {10,80,30,90,40,50,70};

void display(){
    for(int i = 0; i<sizeof(array)/sizeof(int); i++){
        printf("%d ",array[i]);
    }
    printf("\n");
}

void swap(int *a, int *b){
    int temp = *b;
    *b = *a;
    *a = temp;
}

void quicksort(int *arr,int size){
    if(size>0){
        int pivot = arr[size-1];
        int new_size = -1;
        
        for(int i = 0; i<size; i++){
            if(arr[i]<= pivot){
                new_size++;
                swap(&arr[i],&arr[new_size]);
            }
            else if(arr[i]>pivot){

            }
        }
        // printf("Left Partition\n");
        // for(int i = 0; i<new_size; i++){
        //     printf("%d ",arr[i]);
        // }
        // printf("\n");

        // printf("Right Partition\n");
        // for(int i = new_size+1; i<size; i++){
        //     printf("%d ",arr[i]);
        // }
        // printf("\n\n");
        // quicksort(arr,new_size);
        // quicksort(&arr[new_size+1],size-new_size-1);
    }
}

void main(){
    display();
    quicksort(array,sizeof(array)/sizeof(int));
    display();

}