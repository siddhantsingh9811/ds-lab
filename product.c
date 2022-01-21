#include <stdio.h>

union product
{
    char name[20];
    int price;
    int quantity;
    int spent;
} products[50];


void main(){
    int n;
    printf("Enter number of products: ");
    scanf("%d",&n);

    for(int i = 0; i < n; i++){
        printf("Enter product name: ");
        scanf("%s",products[i].name);
        
        printf("Enter product price per unit: ");
        scanf("%d",&products[i].price);

        printf("Enter product quantity: ");
        scanf("%d",&products[i].quantity);

        products[i].spent = products[i].price * products[i].quantity;
        printf("\n");

    }

    for(int i = 0; i < n; i++){
        printf("Product Name: %s",products[i].name);
        printf("\nProduct price per unit: %d \nProduct quantity: %d\nTotal Spent: %d\n",products[i].price,products[i].quantity,products[i].spent);
    }
    printf("size of each product: %ld",sizeof(products[0]));

}