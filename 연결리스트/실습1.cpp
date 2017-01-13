#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node *next;
};

void print_list(struct node *);

void main()
{
	struct node *A, *B, *C, *D, *start;

	A = (struct node *)malloc(sizeof(struct node));
	A->data = 17;

	B = (struct node *)malloc(sizeof(struct node));
	B->data = 26;

	C = (struct node *)malloc(sizeof(struct node));
	C->data = 39;

	D = (struct node *)malloc(sizeof(struct node));
	D->data = 52;

	A->next = B;
	B->next = C;
	C->next = D;
	D->next = NULL;

	start = A;

	print_list(start);
}

void print_list(struct node *start)
{
	struct node *ptr;

	printf("( ");
	for (ptr = start; ptr != NULL; ptr = ptr->next)
		printf("%d ", ptr->data);
	printf(")\n");
}