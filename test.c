#include<stdio.h>

void main()

{

int i, arr[10];

for(i=0;i<10; i++)

arr[i*2]= 1;

for(i=0;i<10; i++)

arr[i*2+1]= -1;

for(i=0;i<10; i++)

printf("%d,",arr[i]);

           }