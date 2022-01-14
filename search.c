#include <stdio.h>

int search(int arr[20], int n){
    for(int i = 0; i<n; i++){
        if(arr[i] == n){
            printf("Element found");
            return 0;
        }
    }
    printf("Element not found");
}

void main(){
    int arr[20];
    int n;

    printf("Enter no of elements: ");
    scanf("%d", &n);

    for(int i = 0; i<n; i++){
        printf("Enter element: ");
        scanf("%d",&arr[i]);
    }
    printf("Enter number to search for: ");
    scanf("%d", &n);
    search(arr,n);
}