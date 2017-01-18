#include <stdio.h>
#include <stdlib.h>

struct node {
	int vertex;
	struct node *link;
};
struct node **graph;

void insert_front(int, int);
void print_list(int);

void main()
{
	char fname[80];
	FILE *fp;
	int n, u, v;

	printf("파일 이름? ");
	gets_s(fname);

	if ((fp = fopen(fname, "rt")) == NULL) {
		printf("Error: file open\n");
		return;
	}

	fscanf(fp, "%d", &n);
	graph = (struct node **)calloc(n, sizeof(struct node *));

	while (1) {
		fscanf(fp, "%d%d", &u, &v);
		if (u == -1)
			break;

		insert_front(u, v);
		insert_front(v, u);
	}

	for (int i = 0; i < n; i++) {
		print_list(i);
	}
}

void insert_front(int from, int to)
{
	struct node *ptr;

	ptr = (struct node *)malloc(sizeof(struct node));
	ptr->vertex = to;
	ptr->link = graph[from];
	graph[from] = ptr;
}

void print_list(int to)
{
	struct node *ptr;

	printf("%d: ( ", to);
	for (ptr = graph[to]; ptr; ptr = ptr->link)
		printf("%d ", ptr->vertex);
	printf(")\n");
}