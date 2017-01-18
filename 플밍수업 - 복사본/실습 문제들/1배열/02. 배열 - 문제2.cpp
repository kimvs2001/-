#include<stdio.h>
#include<stdlib.h>
#define MAX 10000
struct cell {
	int x, y;
};
typedef struct{
	int x, y;
}QUEUE[MAX];
QUEUE queue;
int front = -1, rear = -1;
void addq(int x, int y) {
	queue[++rear].x = x;
	queue[rear].y = y;
}
cell deleteq() {
	cell temp;
	temp.x = queue[++front].x;
	temp.y = queue[front].y;
	return temp;
}
int cnt = 0;
void draw(cell c,int **A) {
	if (A[c.x - 1][c.y] == 0) {
		A[c.x - 1][c.y] = 1;
		cnt++;
		addq(c.x - 1, c.y);
	}
	if (A[c.x + 1][c.y] == 0) {
		A[c.x + 1][c.y] = 1;
		cnt++;
		addq(c.x + 1, c.y);
	}
	if (A[c.x][c.y - 1] == 0) {
		A[c.x][c.y - 1] = 1;
		cnt++;
		addq(c.x , c.y-1);
	}
	if (A[c.x][c.y + 1] == 0) {
		A[c.x][c.y + 1] = 1;
		cnt++;
		addq(c.x , c.y+1);
	}
}

int main(void) {
	
	int n, m, number , t;
	int **A;
	cell *c, temp;

	printf("Enter N and M :");
	scanf("%d %d", &n, &m);
	if (n > 40 || m > 40 || n < 0 || m < 0)
		return 0;
	printf("Enter the number of initial cells :");
	scanf("%d", &number);

	A = (int**)calloc(n+2,sizeof(int*));
	for (int i = 0; i < n + 2; i++)
		A[i] = (int*)calloc(m + 2,sizeof(int));
	for (int i = 0; i < m + 2; i++) {
		A[0][i] = -1;
		A[n + 1][i] = -1;
	}
	for (int i = 0; i < n + 2; i++) {
		A[i][0] = -1;
		A[i][m + 1] = -1;
	}

	c = (struct cell*)malloc(sizeof(struct cell)*number);

	for (int i = 0; i < number; i++) {
		printf("Enter the coordinates (%d) : ",i+1);
		scanf("%d %d", &c[i].x, &c[i].y);
		if (i != 0 && c[i - 1].x == c[i].x&&c[i-1].y == c[i].y)
			i--;
		else {
			A[c[i].x][c[i].y] = 1;
			addq(c[i].x,c[i].y);
			cnt++;
		}
	}

	printf("Enter the number of time steps : ");
	scanf("%d", &t);
	if (t > 10 || t < 0)
		return 0;

	for (int i = 0; i < t+1; i++) {
		int check = rear;
		if(i!=0){
			while (front != check) {
				temp = deleteq();
				draw(temp, A);
			}
		}
		for (int k = 1;k < n + 1; k++) {
			for (int j = 1; j < m + 1; j++)
				printf("%d ", A[k][j]);
			printf("\n");
		}
		printf("T=%d\n",i);
		printf("# of activated cells = %d\n", cnt);
		printf("\n");
	}
}