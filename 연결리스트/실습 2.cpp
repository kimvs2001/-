#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node *next;
};

void print_list(struct node *);
void insert_front(struct node **, int);
void insert_rear(struct node **, struct node **, int);

void main()
{
	struct node *front, *rear;

	front = rear = NULL;

	for (int i = 0; i < 30; i++) {
		insert_rear(&front, &rear, rand() % 1000 + 1);
	}
	print_list(front);
}

void insert_rear(struct node **front, struct node **rear, int data)
{
	struct node *temp;

	temp = (struct node *)malloc(sizeof(struct node));
	temp->data = data;
	if (*front != NULL) (*rear)->next = temp;
	else *front = temp;

	*rear = temp;
}

void insert_front(struct node **start, int data)
{
	struct node *temp;

	temp = (struct node *)malloc(sizeof(struct node));
	temp->data = data;
	temp->next = *start;
	*start = temp;
}

void print_list(struct node *start)
{
	struct node *ptr;

	printf("( ");
	for (ptr = start; ptr != NULL; ptr = ptr->next)
		printf("%d ", ptr->data);
	printf(")\n");
}