#include <stdio.h>

void show_array(int arr[], int n){
    for(int i = 0; i < n; i++){
        printf("%d\n", arr[i]);
    }
}
void main(){
    int n;
    int arr[20];
    printf("Enter Number of Elements: ");
    scanf("%d",&n);
    for(int i = 0; i< n; i++){
        printf("Enter element: ");
        scanf("%d",&arr[i]);
    }
    show_array(arr,n);
    int c =1;
    while(c!=0){
        printf("Enter 1 to delete element, 2 to add element and 0 to exit: ");
        scanf("%d",&c);
        if(c == 1){
            int position;
            printf("Enter positon of element to delete: ");
            scanf("%d",&position);
            for(int i = position-1; i < n; i++){
                arr[i] = arr[i+1];
            }
            n--;
            show_array(arr,n);
        }
        if(c == 2){
            int position;
            int val;
            printf("Enter positon of element to add: ");
            scanf("%d",&position);
            for(int i = n; i > position-1; i--){
                arr[i] = arr[i-1];
            }
            printf("Enter Value: ");
            scanf("%d",&val);
            arr[position-1] = val;
            n++;
            show_array(arr, n);
        }
    }
}