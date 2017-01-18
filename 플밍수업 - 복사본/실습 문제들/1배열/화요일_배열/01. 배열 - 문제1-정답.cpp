#include<stdio.h>
#include<stdlib.h>
typedef struct {
	int x, y;
}path;
path p[8] = { {-1,1}, {0,1},{1,1},{1,0},{1,-1},{0,-1},{-1,-1},{-1,0} };

int random_walk(int **A, int row, int col,int limit,int max) {
	int next_row, next_col;
	int cnt = 0, temp, zero = 0;
	while (cnt != limit) {
		temp = rand() % 8;
		next_row = row + p[temp].x;
		next_col = col + p[temp].y;
		if (A[next_row][next_col] == -1)
			continue;
		if (A[next_row][next_col] == 0)
			zero++;
		A[next_row][next_col]++;
		row = next_row;
		col = next_col;
		cnt++;
		if (zero == max)
			break;
	}
	return cnt;
}
void main() {
	int n, m, row, col, limit;

	printf("행렬의 크기 ? :");
	scanf("%d %d", &n, &m);

	printf("순회를 시작하는 좌표 ? :");
	scanf("%d %d", &row, &col);
	
	printf("방문수의 한계값 ? :");
	scanf("%d", &limit);

	int **A = (int**)calloc(n+2,sizeof(int*));
	for (int i = 0; i < n+2; i++)
		A[i] = (int*)calloc(m+2,sizeof(int));

	row++;
	col++;

	for (int i = 0; i < m+2; i++) {
		A[0][i] = -1;
		A[n + 1][i] = -1;
	}
	for (int i = 0; i < n + 2; i++) {
		A[i][0] = -1;
		A[i][m+1] = -1;
	}

	printf("방문수 : %d\n", random_walk(A,row,col,limit,n*m));
	for (int i = 1; i < n+1; i++) {
		for (int j = 1; j < m+1; j++) {
			printf("%d  ", A[i][j]);
		}
		printf("\n");
	}

}