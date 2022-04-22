#include <stdio.h>
#include <stdlib.h>

struct node {
	int info;
	struct node* next;
};

struct node* last = NULL;

void enqueue(int data)
{
    struct node* temp;
	printf("Added element %d\n",data);
	temp = (struct node*)malloc(sizeof(struct node));
	if (last == NULL) {
		temp->info = data;
		temp->next = temp;
		last = temp;
	}

	else {
		temp->info = data;
		temp->next = last->next;
		last->next = temp;
		last = temp;
	}
}

void dequeue()
{
	struct node* temp;

	if (last == NULL)
		printf("\nQueue is empty.\n");
	else {
        printf("Removed Element %d\n",last->info);
		temp = last->next;
		last->next = temp->next;
		free(temp);
	}
}

void peek()
{

	if (last == NULL)
		printf("\nQueue is empty\n");

	else {
		struct node* temp;
		temp = last->next;
        printf("Queue: \n");
		do {
			printf("%d--> ",
				temp->info);
			temp = temp->next;
		} while (temp != last->next);
        printf("END\n");
	}
}

// Driver Code
int main()
{

	enqueue(1);
	enqueue(2);
	enqueue(3);
    peek();
	dequeue();

	peek();

	return 0;
}