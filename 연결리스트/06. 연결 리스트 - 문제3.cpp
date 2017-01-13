#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct n {
	char data[30];
	int cnt;
	struct n*next;
}node;

struct n *head[26];

int total_word = 0;

void addList(int offset, char *word) {
	node*ptr = head[offset];

	if (ptr == NULL || strcmp(ptr->data, word) < 0) {

	}

	for (ptr = head[offset]; strcmp(ptr->next->data, word) < 0; ptr = ptr->next)
		;
	{
		if (==0) {
			ptr->cnt++;
			return;
		}
	}
	node*temp = (node*)malloc(sizeof(node));
	strcpy(temp->data, word);
	temp->cnt = 1;
	temp->next = NULL;
	total_word++;
	if (*front == NULL||strcmp(((*front)->data),word)>0) {
		temp->next = *front;
		*front = temp;
		return;
	}
	else {
		for (i = *front; i->next&&(strcmp(i->next->data, word) < 0); i = i->next)
			;
		temp->next = i->next;
		i->next = temp;
	}
}

void changeSmall(char data[]) {
	if (data[0] >= 'A'&&data[0] <= 'Z') {
		for (int i = 0; data[i]; i++) {
			if (data[i] >= 'A'&&data[i] <= 'Z') {
				data[i] = data[i] + ('a' - 'A');
			}
		}
	}
}

void readText(FILE**fp,node**front) {
	char fname[40];
	char data[30];
	char *token;
	printf("�Է����� �̸� : ");
	scanf("%s", fname);
	*fp = fopen(fname, "rt");
	if (*fp == NULL) {
		printf("���� ����!!"); return ;
	}
	while (!feof(*fp)) {
		fscanf(*fp, "%s", &data);
		token = strtok(data, " %.,-_'\"?!()[]:\t\n;");
		while (token != NULL) {
			changeSmall(token);
			if (token[0] >= 'a'&&token[0] <= 'z') {
				addList(front,token);
			}
			token = strtok(NULL, " %.,-_'\"?!()[]:\t\n;");
		}
		
	}
	
}
void writeText(FILE**fp,node**ptr) {
	char fname[40];
	printf("����� ���� �̸� : ");
	scanf("%s", fname);
	*fp = fopen(fname, "wt");
	if (fp == NULL) {
		printf("���� ����!\n");
		return;
	}
	for (node*i = *ptr; i;i=i->next) {
		fprintf(*fp, "%s : %d\n", i->data, i->cnt);
	}
	fprintf(*fp, "total : %d\n", total_word);
}

void search(node*ptr) {
	char word[50];
	printf("�˻��� �ܾ� : ");
	scanf("%s", word);

	for (node*i = ptr; i;i= i->next) {
		if (strcmp(i->data, word) == 0) {
			printf("%s : %d\n", i->data, i->cnt);
			return;
		}
	}
	printf("�˻��� �ܾ �����ϴ�!\n");
}
int main() {
	FILE*fp;
	node*front, *rear;
	int n;
	front =  NULL;
	printf(" 1.�Է� // 2.��� // 3.�˻� // 4.����\n");
	while (1) {
		printf("����Է�??");
		scanf("%d", &n);
		switch (n) {
		case 1:
			readText(&fp, &front);
			printf("�Է¿Ϸ�\n");
			break;
		case 2:
			writeText(&fp, &front);
			printf("��¿Ϸ�\n");
			break;
		case 3:
			search(front);
			break;
		case 4:
			printf("����!\n");
			return 0;
		}
		printf("\n");
	}
	
	//printNode(front);
	
}