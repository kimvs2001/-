#include <stdio.h>
#include <stdlib.h>

#define FALSE 0
#define TRUE 1
short int *visited;
int **C;

void print_in_degree(int, int);
void init_visited(int);
void dfs(int, int);
void dfs_spanning_tree(int, int);

void main() {
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
	C = (int **)malloc(sizeof(int *) * n);
	for (int i = 0; i < n; i++)
		C[i] = (int *)malloc(sizeof(int) * n);
	
	visited = (short *)malloc(n * sizeof(short));

	while (fscanf(fp, "%d %d", &u, &v) != EOF) {
		C[u][v] = 1;
	}

	printf("\n노드의 in-degree\n");
	for (int i = 0; i < n; i++) {		// 노드의 in-degree
		print_in_degree(i, n);
	}
	init_visited(n);
	printf("\n깊이 우선 탐색 결과\n");
	dfs(0, n);

	init_visited(n);
	printf("\nDFS Spanning Tree 결과\n");
	dfs_spanning_tree(0, n);
	printf("\n");
}

void init_visited(int n){
	for (int i = 0; i < n; i++)
		visited[i] = FALSE;
}

void dfs(int v, int n) {
	visited[v] = TRUE;
	printf("%d ", v);
	for (int i = 0; i < n; i++) {
		if (!visited[i] && C[v][i] == 1)
			dfs(i, n);
	}
}

void dfs_spanning_tree(int v, int n) {
	visited[v] = TRUE;
	for (int i = 0; i < n; i++) {
		if (!visited[i] && C[v][i] == 1) {
			printf("(%d %d)\n", v, i);
			dfs_spanning_tree(i, n);
		}
	}
}

int print_in_degree(int v, int n){
	int count = 0;

	for (int i = 0; i < n; i++) {
		if (C[i][v] == 1)
			count++;
	}
	printf("%d: %d \n", n, count);
}
