#include<stdio.h>
#define size 10
struct node
{
int sapid;
struct node *next;
}
*array[size],*new=NULL,*temp=NULL, *ptr=NULL;
int hash_family(int s)
{
int temp=0, val=0, fam=0,temp1=0;
temp=s;
for(int i=0;i<3;i++) //loop to add the last 3 digits of SAP ID
{
val = temp % 10;
fam = val + fam;
temp = temp/10;
}
if (fam>=10) //loop to add the digits if the sum of last 3 digits is greater than or equal to 10
{
temp = fam;
for(int i=0; i<2;i++)
{
val = temp%10;
temp1 = val+temp1;
temp = temp/10;
}
return temp1;
}
else
return fam;
}
void insert()
{
int sap,family;
printf("Enter the SAPID: ");
scanf("%d",&sap);
// creating a new node
new= (struct node*) malloc(sizeof(struct node)); new->sapid = sap;
new->next =NULL;
family= hash_family(sap);
//checking if the family is empty
if(array[family]==NULL)
{
array[family]=new;
}
else
{
temp=array[family];
while(temp->next !=0)
{
temp=temp->next;
}
temp->next=new;
}
printf("Node inserted successfully in family %d.\n",family);
}
void display()
{
int i;
for(i = 0; i < size; i++)
{
ptr = array[i];
printf("family[%d]",i);
while(ptr)
{
printf("-->%d ",ptr->sapid);
ptr=ptr->next;
}
printf("\n");
}
}
int main() 
{
int choice;
char ch='y';
while(ch=='y' || ch=='Y')
{
printf("=========== MAIN MENU ===========\n");
printf("1.Insert into Hash Table\n2.Display the Hash Table\n3.Exit\nEnter your choice: ");
}  