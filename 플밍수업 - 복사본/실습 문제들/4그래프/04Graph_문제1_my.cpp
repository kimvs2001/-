#include <stdio.h>
#include <stdlib.h>
void initiallize();
void indegree_count();
void dfs(int);
void spannig(int);
void print_Mat();
int **adMat;
FILE* fileOpen();
int n, *visited;
void main() {
	int from, to,*indegree;
	FILE* fp = fileOpen();
	fscanf(fp, "%d", &n);
	initiallize();
	while (1) {
		fscanf(fp, "%d %d", &from, &to);
		if (from + to < 1) break;
		adMat[from][to] = 1;
	}
	print_Mat();
	
	printf("\n노드의 in_degree\n");
	indegree_count();
	
	printf("깊이 우선 탐색 결과 : \n");
	dfs(0);

	for (int i = 0; i < n; i++)visited[i] = 0;

	printf("\n스패닝 트리 출력 결과 : \n");
	spannig(0);

}
void indegree_count() {
	
	
	for (int i = 0; i < n; i++) {
		int indegree = 0;
		for (int j = 0; j < n; j++) {
			if (adMat[j][i] == 1)indegree++;
		}
		printf("%d :%d\n", i, indegree); 
	}

}
void initiallize() {
	visited = (int*)calloc(n, sizeof(int));

	for (int i = 0; i < n; i++) { visited[i] = false; }
	adMat = (int**)calloc(n, sizeof(int));
	for (int i = 0; i < n; i++) {
		adMat[i] = (int*)calloc(n, sizeof(int));
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			adMat[i][j] = 0;
		}
	}
}

void spannig(int v) {
	
	visited[v] = true;
	
	
	for (int i = 0; i < n; i++) {
		if (adMat[v][i] == 1 && visited[i] == false) {
			printf("\n%5d", v); printf("->%d",i); spannig(i);
		}
	}
	printf("\n");
}
void dfs(int v) {
	visited[v] = true;
	printf("%5d", v);
	for (int i = 0; i < n; i++) {
		if (adMat[v][i] == 1 && visited[i] == false) {
			dfs(i);
		}
	}
}
FILE* fileOpen() {
	char fname[80];
	FILE *fp;
	printf("파일이름을 입력하시오 : ");
	gets_s(fname);
	

	if ((fp = fopen(fname, "rt")) == NULL) {
		printf("파일 오픈 에러 \n");
		return NULL;
	}
	return fp;
}

void print_Mat() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			printf("%d ", adMat[i][j]);
		}printf("\n");
	}
}