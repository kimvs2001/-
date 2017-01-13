
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define null ((void *)0)
struct node {
	int data;
	struct node* next;
}*top1,*top2,
*front,*rear,
*empty;
void push1(int data) {
	struct node *temp = (struct node*)malloc(sizeof(struct node));
	temp->data = data;
	temp->next = top1;
	top1 = temp;
}

void push2(int data) {
	struct node *temp2 = (struct node*)malloc(sizeof(struct node));
	temp2->data = data;
	temp2->next = top2;
	top2 = temp2;
}

int pop1() {
	//struct node *temp = (struct node*)malloc(sizeof(struct node));
	int res;
	if (top1 != NULL) {
		res = top1->data;
		top1 = top1->next;
	}
	else return -1;
	return res;
}
int pop2() {
	//struct node *temp = (struct node*)malloc(sizeof(struct node));
	int res;
	if (top2 != NULL) {
		res = top2->data;
		top2 = top2->next;
	}
	else return -1;
	return res;
}
void addq(int data) {
	struct node *temp;
	temp = (struct node*)malloc(sizeof(struct node));
	temp->data = data;
	temp->next = NULL;
	if (front != NULL) rear->next = temp;
}

node* deleteq() {
	struct node *temp = (struct node*)malloc(sizeof(struct node));
	//struct node *temp;
	struct node *ptr=(struct node*)malloc(sizeof(struct node));;
	for (temp = front; temp->next->next != NULL; temp = temp->next);
	ptr = rear;
	rear = temp;
	rear->data = temp->data;
	rear->next = temp->next;
	if(ptr->data == NULL) return empty;
	return ptr;
	
}
 
void main() {
	empty= (struct node*)malloc(sizeof(struct node));
	empty->data = -1;
	char str1[101];
	char str2[101];
	int push_num;
	node *ptr, *ptr2;
	printf("숫자 두개 입력하시오\n");
	gets_s(str1);
	gets_s(str2);
	//atoi(str1);
	//atoi(str2);
	
	//ptr = (struct node*)malloc(sizeof(struct node));

	for (char num : str1) {
		int i = atoi(&num);
		if(i>0&&i<10)push1(i);
		else break;
	}
	for (char num : str2) {
		int i = atoi(&num);
		if (i>0 && i<10)push2(i);
		else break;
	}
	
	printf("\n");
	
	for (int i=0; i != -1;) {
		i = pop1();
		printf("%d ", i);
	}
	
	printf("\n");
	for (int i=0; i != -1;) {
		i = pop2();
		printf("%d ", i);
	}
	//top2가 더 짧다는 조건
	for (;;) {
		int res, carry = 0;
		int p1 = pop1();
		int p2 = pop2();
		
		if (p2 == -1) break;
		else { res = p1 + p2+carry; 
		if (res > 9) { carry = 1; addq(res); }
		}
	}
	for (;;) {
		int res, carry = 0;
		int p1 = pop1();
		if (p1 == -1) break;
		else addq(p1);
	}
	for (int i = 0; i != -1;) {
		printf("%d", deleteq());
			i = deleteq()->data;
	}
}