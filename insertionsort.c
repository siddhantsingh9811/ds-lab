#include <stdio.h>

int array[] = {4,3,2,10,12,1,5,6};

void swap(int *a, int *b){
    int temp = *b;
    *b = *a;
    *a = temp;
}

void insertion_sort(int *arr, int size){
    if(size>0){
        size--;
        for(int i = 0; i<size; i++){
            if(arr[i] > arr[i+1]){
                swap(&arr[i],&arr[i+1]);
            }
        }
        insertion_sort(&arr[0],size);
    }
}

void main(){
    insertion_sort(array, sizeof(array)/sizeof(int));
    for(int i = 0; i<sizeof(array)/sizeof(int); i++){
            printf("%d ",array[i]);
    }
}