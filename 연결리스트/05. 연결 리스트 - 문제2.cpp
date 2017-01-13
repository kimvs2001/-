#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
	int data;
	struct node * next;
};

void print_list(struct node *);
void insert_front(struct node **, int);
void swap(struct node **, struct node **);
struct node *sum_list(struct node *, struct node *);
struct node *min_list(struct node *, struct node *);

void main()
{
	char a[101] , b[101];
	struct node * STARTa = NULL, *STARTb = NULL, *List;
	int cond = 0;
	printf("첫번째 수 입력 : ");
	gets_s(a);
	printf("두번째 수 입력 : ");
	gets_s(b);
	
	for (char num : a) {
		if (num == NULL)
			break;
		insert_front(&STARTa, num - '0');
	}
	for (char num : b) {
		if (num == NULL)
			break;
		insert_front(&STARTb, num - '0');
	}

	List = sum_list(STARTa, STARTb);
	printf("두수의 합 : ");
	print_list(List);

	if (strlen(a) < strlen(b)) {
		swap(&STARTa, &STARTb);
		cond = -1;
	}

	List = min_list(STARTa, STARTb);
	printf("두수의 차 : ");
	if (cond == -1)
		printf("- ");
	print_list(List);
}

void insert_front(struct node ** start, int item) {
	struct node * temp;
	temp = (struct node *)malloc(sizeof(struct node));

	temp->data = item;
	temp->next = *start;
	*start = temp;
}

void print_list(struct node *start)
{
	struct node *ptr;

	for (ptr = start; ptr != NULL; ptr = ptr->next)
		printf("%d", ptr->data);
	printf("\n");
}

void swap(struct node ** a, struct node ** b)
{
	struct node * temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

struct node *sum_list(struct node * a, struct node * b) {
	if (a == NULL || b == NULL)
		return NULL;
	int carry = 0, sum = 0;
	struct node * ptra = a, *ptrb = b;
	struct node * list = NULL;
	
	while (ptra != NULL || ptrb != NULL) {
		sum = ((ptra==NULL || ptra->data == 0 )? ptrb->data+carry : (ptrb == NULL || ptrb->data == 0) ? ptra->data + carry : ptra->data + ptrb->data+carry);
		if (sum > 9) {
			carry = 1;
			sum -= 10;
		}
		else
			carry = 0;
		insert_front(&list, sum);	// insert_rear로 할 것!
		
		if (ptra != NULL)
			ptra = ptra->next;
		if (ptrb != NULL)
			ptrb = ptrb->next;
	}
	if (carry == 1)
		insert_front(&list, carry);	// insert_rear로 할 것!
	return list;
}

struct node *min_list(struct node * a, struct node * b) {
	if (a == NULL || b == NULL)
		return NULL;
	int carry = 0, min = 0;
	struct node * ptra = a, *ptrb = b;
	struct node * list = NULL;

	while (ptra != NULL || ptrb != NULL) {
		min = ((ptrb == NULL || ptrb->data == 0) ? ptra->data - carry : ptra->data - ptrb->data - carry);
		if (min == 0 && ptra->next == NULL)
			break;
		if (min < 0) {
			carry = 1;
			min += 10;
		}
		else
			carry = 0;
		insert_front(&list, min);

		if (ptra != NULL)
			ptra = ptra->next;
		if (ptrb != NULL)
			ptrb = ptrb->next;
		
	}
	return list;
}
