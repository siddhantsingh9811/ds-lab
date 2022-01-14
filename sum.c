#include <stdio.h>

int sum(int arr[20],int n){
    if(n>0){
        return sum(arr,n-1) + arr[n-1];
    }
    return 0;
}

void main(){
    int arr[20];
    int n;
    printf("Enter Number of Elements: ");
    scanf("%d",&n);
    for(int i = 0; i< n; i++){
        printf("Enter element: ");
        scanf("%d",&arr[i]);
    }
    printf("sum is: %d\n", sum(arr,n));
    
}