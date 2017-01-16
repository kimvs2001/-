#include <stdio.h>
#include <stdlib.h>

#define FALSE 0
#define TRUE 1

struct node {
	int vertex;
	struct node *link;
};
struct node **graph;
short *visited;

void insert_front(int, int);
void print_list(int);
void find_max_degree(int);
void init_visited(int);
void dfs(int);
void connected(int);
void dfs_spanning_tree(int);

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
	visited = (short *)malloc(n * sizeof(short));

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

	find_max_degree(n);

	init_visited(n);
	printf("\ndfs(%d): ", 0);
	dfs(0);
	printf("\n\n");

	init_visited(n);
	connected(n);

	init_visited(n);
	printf("\nDFS Spanning Tree\n");
	dfs_spanning_tree(0);
	printf("\n");
}

void find_max_degree(int n)
{
	int max_degree = -1, max_node, degree;
	struct node *ptr;

	for (int i = 0; i < n; i++) {
		degree = 0;
		for (ptr = graph[i]; ptr; ptr = ptr->link)
			degree++;
		if (degree > max_degree) {
			max_degree = degree;
			max_node = i;
		}
	}
	printf("\nDegree가 최대인 노드 = %d (degree = %d)\n", max_node, max_degree);
	print_list(max_node);
}

void init_visited(int n)
{
	for (int i = 0; i < n; i++)
		visited[i] = FALSE;
}

void dfs(int v)
{
	struct node *w;
	visited[v] = TRUE;
	printf("%d ", v);
	for (w = graph[v]; w; w = w->link)
		if (!visited[w->vertex])
			dfs(w->vertex);
}

void dfs_spanning_tree(int v)
{
	struct node *w;

	visited[v] = TRUE;
	for (w = graph[v]; w; w = w->link)
		if (!visited[w->vertex]) {
			printf("(%d %d)\n", v, w->vertex);
			dfs_spanning_tree(w->vertex);
		}
}

void connected(int n)
{
	int i, number = 1;

	for (i = 0; i < n; i++)
		if (visited[i] == FALSE) {
			printf("연결 요소 %d: ", number++);
			dfs(i);  
			printf("\n");
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