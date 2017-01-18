#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node *next;
};

void print_list(struct node *); //프린트 함수
void insert_front(struct node **, int);
void insert_rear(struct node **, struct node **, int);
void sort_order(struct node **, int);
void delete_data(struct node **, int);

void main()
{
	struct node *start = NULL;
	int data;

	for (int i = 0; i < 30; i++) {
		sort_order(&start, rand() % 1000 + 1);
	}
	print_list(start);

	while (1) {
		printf("\n삭제할 데이터? ");
		scanf("%d", &data);
		delete_data(&start, data);
		print_list(start);
	}
}

void delete_data(struct node **start, int input_data)
{
	struct node *ptr, *target;

	if (*start == NULL)
		return;
	if ((*start)->data == input_data) {
		target = *start;
		*start = target->next;
		free(target);
		return;
	}
	for (ptr = *start; ptr->next != NULL && ptr->next->data != input_data; ptr = ptr->next)
		;

	if (ptr->next == NULL)
		return;

	target = ptr->next;
	ptr->next = target->next;
	free(target);
}

void sort_order(struct node **start, int input_data)
{
	struct node *temp, *ptr;

	temp = (struct node *)malloc(sizeof(struct node));
	temp->data = input_data;

	if (*start == NULL || input_data < (*start)->data) {
		temp->next = *start;
		*start = temp;
		return;
	}

	for (ptr = *start; ptr->next != NULL && ptr->next->data < input_data; ptr = ptr->next)
		;
	temp->next = ptr->next;
	ptr->next = temp;
}

void insert_rear(struct node **front, struct node **rear, int data)
{
	struct node *temp;

	temp = (struct node *)malloc(sizeof(struct node));
	temp->data = data;
	temp->next = NULL;

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