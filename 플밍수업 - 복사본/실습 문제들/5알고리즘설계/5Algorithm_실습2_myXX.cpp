#include <stdio.h>
#include <stdlib.h>
void shortest(int , int );
int find_shorttest_index(int , int );
FILE* fileOpen() {
	FILE* fp;
	char fname[80]="5data.txt";
	if ((fp = fopen(fname, "rt")) == NULL) {
		printf("���� ���� ����\n"); return NULL;
	}
	return fp;
}
int **A, *dist;
bool *visit;
void A_initialize(int n) {
	A = (int**)malloc(sizeof(int*)*n);
	for (int i = 0; i < n; i++)
		A[i] = (int*)malloc(sizeof(int));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			A[i][j] = 9999;
}
void dist_initialize(int n) {
	visit = (bool*)malloc(sizeof(bool)*n);
	dist = (int*)malloc(sizeof(int)*n);
	for (int i = 0; i < n; i++) {
		dist[i] = 0; visit[i] = false;
	}
}//dist�� 0���� -> x ���� ���� �Ÿ�
void main() {
	FILE *fp=fileOpen();
	int n, from, to,cost; 
	
	fscanf(fp,"%d", &n);
	A_initialize(n);
	dist_initialize(n);
	while (1) {
		fscanf(fp,"%d%d%d", &from, &to,&cost);
		if (from == -1)break;
		A[from][to] = cost;
		
	}
//for(int i=0;i<n;i++)	//dist ó���� ��.
//	dist[i] = A[0][i];
	for (int i = 0; i < n; i++)
		dist[i] = A[0][i];	//0���� i�� ���� cost �ʱ�ȭ
	
	//for(int to =1;to<n;to++)
	visit[0] = true;
	shortest(n,to);	// return 1;
	//shortest(1, n);

}

void shortest(int n,int to) {
// dist�� �����ؾߵ�	
	int v;
	int min = find_shorttest_index(v, n);//0���� �ּҺ�����ΰ��� ��
	visit[min] = true; 
		if (dist[min] > dist[min] + A[min][to])
			dist[min] = dist[min] + A[min][to];

}

int find_shorttest_index(int v, int n) {
	//v���� ������ �ִ� �� �߿���
	//���� ����cost�� �� �� �ִ� ��! �� ����
	int shorttest = 9999;
	int shorttest_index = 1;	//dist �迭�߿��� ���� ª���� ã��


	for (int i = 1; i < n; i++) {
		if (shorttest > A[v][i]) {
			shorttest_index = i;
			shorttest = A[v][i];
		}						//�� ª���� ������ �װ��� shorttest_index���ְ�
	}							//�ƴϸ� shorttest_index�� 1

	return shorttest_index;

}