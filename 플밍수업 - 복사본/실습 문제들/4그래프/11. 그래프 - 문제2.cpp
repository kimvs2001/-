#include<stdio.h>
#include<stdlib.h>
#define FALSE 0
#define TRUE 1

typedef struct node {
	int vertex;
	int cost;
	struct node *link;
}node;

node **graph;
short *visited;
void insert_front(int, int, int);
void print_list(int);
void spanning_tree_prim(int);
int sum;

int main() {
	FILE *fp;
	int n1, n2, u, v, c, i;

	if ((fp = fopen("data.txt", "rt")) == NULL) {
		printf("File open error\n");
		return 0;
	}
	
	fscanf(fp,"%d %d", &n1, &n2);

	graph = (node **)calloc(n1, sizeof(node *));
	visited = (short *)calloc(n1, sizeof(short));

	while (fscanf(fp, "%d %d %d", &u, &v, &c) != EOF) {
		insert_front(u, v, c);
		insert_front(v, u, c);
	}

	for (i = 0; i < n1; i++) {
		print_list(i);
	}

	spanning_tree_prim(0);
	printf("ÃÑ ºñ¿ë : %d\n", sum);
	return 0;
}

void insert_front(int from, int to, int cost) {
	node *ptr;
	ptr = (node *)malloc(sizeof(node));
	ptr->vertex = to;
	ptr->cost = cost;
	ptr->link = graph[from];
	graph[from] = ptr;
}

void print_list(int to) {
	node *ptr;
	printf("%d ( ", to);
	for (ptr = graph[to]; ptr; ptr = ptr->link) {
		//printf("vertex : %d, cost : %d ", ptr->vertex, ptr->cost);
		printf("%d ", ptr->vertex);
	}
	printf(")\n");
}

void spanning_tree_prim(int to) {
	node *ptr, *min = graph[to];
	visited[to] = TRUE;
	for (ptr = graph[to]; ptr; ptr = ptr->link) {
		if ((ptr->cost < min->cost) && !visited[ptr->vertex]) min = ptr;
	}

	for (ptr = graph[to]; ptr; ptr = ptr->link) {
		if (!visited[ptr->vertex]) {
			printf("%d %d %d \n", to, min->vertex, min->cost);
			sum += min->cost;
			spanning_tree_prim(min->vertex);
			
		}
	}
}