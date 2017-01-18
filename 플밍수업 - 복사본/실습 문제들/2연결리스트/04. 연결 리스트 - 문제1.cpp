#include <stdio.h>
#include <stdlib.h>
#include <time.h>


typedef struct node {
	int data;
	node *next;

};


void print_list(node* start) {

	for (; start != NULL; start = start->next) {
		printf("%d ", start->data);

	}
	printf("\n");
}

void insert_front(node **start, int data) {
	node *temp = (node*)malloc(sizeof(node));
	temp->data = data;
	temp->next = NULL;

	if (*start == NULL) {
		*start = temp;
	}
	else {
		temp->next = *start;
		*start = temp;
	}

}

void insert_rear(node **front, node **rear, int data) {
	node *temp = (node*)malloc(sizeof(node));
	temp->data = data;
	temp->next = NULL;


	if (*front != NULL) {
		(*rear)->next = temp;
	}
	else *front = temp;
	*rear = temp;


}
void sort_order(node **start, int data) {
	node *temp = (node*)malloc(sizeof(node));
	temp->data = data;
	temp->next = NULL;

	if (*start == NULL)
		*start = temp;
	else {
		node *find = *start;

		if (temp->data < (*start)->data) {
			temp->next = *start;
			*start = temp;
			return;
		}
			
		 while (find->next) {
			if (temp->data < find->next->data) {
				break;
			}
			find = find->next;
		
		}
		temp->next = find->next;
		find->next = temp;
	}

}

void deleteNode(node **start, int data) {
	node *p = *start;

	if (data == p->data) {
		*start = p->next;
		free(p);
	}
	else {
		for (; p->next->data != data; p = p->next)
			if (p->next->next == NULL) {
				printf("입력한 정수가 없음\n");
				return;
			}

		node *temp = p->next;
		p->next = temp->next;
		free(temp);
	}

}

void sort_Node(node **start, node *change) {


	if (*start == NULL)
		*start = change;
	else {
		node *find = *start;

		if (change->data < (*start)->data) {
			change->next = (*start);
			*start = change;
			return;
		}

		while (find->next) {
			if (change->data < find->next->data) {
				break;
			}
			find = find->next;
		}
		change->next = find->next;
		find->next = change;
	}

}

void find_intersection(node *a, node *b) {
	node *pA = a, *pB = b;

	while (pA != NULL && pB != NULL) {
		if (pA->data == pB->data) {
			printf("%d ", pA->data);
			pA = pA->next, pB = pB->next;
		}
		else if (pA->data > pB->data)
			pB = pB->next;
		else if (pA->data < pB->data)
			pA = pA->next;
	}
	printf("\n\n");
}
void find_difference(node *pA, node *pB) {

	while (pA != NULL && pB != NULL) {
		if (pB->data < pA->data)
			pB = pB->next;
		else if (pB->data == pA->data)
		{
			pB = pB->next;
			pA = pA->next;
		}
		else if (pA->data < pB->data)
		{
			printf("%d ", pA->data);
			pA = pA->next;
		}
	}
	if (pA != NULL)
		print_list(pA);
	printf("\n\n");

}

void zigzag(node *pA, node *pB) {
	node *nextA = pA->next;
	node *nextB = pB->next;
	while (nextA && nextB) {
		pA->next = pB;
		pB->next = nextA;
		pA = nextA;
		pB = nextB;
		nextA = nextA->next;
		nextB = nextB->next;
	}
	pA->next = pB;

	if (nextA != NULL)
		pB->next = nextA;
//	if (nextB != NULL)
//		pB->next = nextB;

}




void main() {
	srand((unsigned)time(NULL));

	node *A = NULL;
	node *Arear = NULL;
	node *B = NULL;
	node *pA = A, *pB = B;


	for (int i = 0; i < 30; i++) {
		int data = rand() % 70 + 1;
		sort_order(&A, data);
	}
	printf("출력 1 A : ");
	print_list(A);

	printf("\n");

	for (int i = 0; i < 20; i++)
	{
		int data = rand() % 70 + 1;
		sort_order(&B, data);
	}
	printf("출력 1 B : ");
	print_list(B);
	printf("\n");

	
	printf("출력 2 공통된 수 : ");
	find_intersection(A, B);

	pA = A, pB = B;

	printf("출력 3 A에만 있는 수 : ");
	find_difference(A, B);

	printf("출력 4 C : ");
	node *C = NULL, *pC = C, *Crear = NULL;
	for (pA = A; pA != NULL; pA = pA->next)
		insert_rear(&C, &Crear, pA->data);

	for (pB = B; pB != NULL; pB = pB->next)
		insert_rear(&C, &Crear, pB->data);

	print_list(C);
	printf("\n\n");

	printf("출력 5 A + B : ");
	for (; B != NULL;) {
		pB = B->next;
		sort_Node(&A, B);
		B = pB;
	}
	// B = NULL

	print_list(A);
	printf("\n");


	//6
	zigzag(A, C);
	
	printf("출력 6 A : ");
	print_list(A);
	

	

}


