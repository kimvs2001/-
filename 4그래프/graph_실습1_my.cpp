#include stdio.h
#include stdlib.h

void insert_front(int , int );
void dfs(int);
struct node {
	int vertex =0;
	
	struct node link = NULL;
};
struct node graph = NULL, front = NULL;
int visited ;
void main() {
	int v = 0;
	int n;
	int here = 0, connect = 0;
	scanf(%d, &n);
	visited = (int)calloc(n, sizeof(int));
	graph = (struct node)calloc(n,sizeof(struct node));	calloc 하는 이유  graph 의 초기값이 다 null로  들어가니까
	front = (struct node)calloc(n,sizeof(struct node));
	for (int i = 0; i  n; i++) {
		graph[i] = front[i];
		front[i] = NULL;
	}
	
		while (1) {
			scanf(%d %d, &here, &connect);
			if (here == -1)break;
			insert_front(here, connect);
			insert_front(connect, here);
		}
			dfs(v);
		
}


void insert_front(int here, int connect) {
	struct node temp,top;
	temp = (struct node)malloc(sizeof(node));
	top = (struct node)malloc(sizeof(node));
	top = graph[here];
	temp-vertex = connect;
	temp-link = top;
	graph[here] = temp;
}
void dfs(int v) {
	struct node w;
	visited[v] = true;
	printf(%5d, v);
	for (w = graph[v]; w; w = w-link)
		if (!visited[w-vertex]) dfs(w-vertex);
}