#include <stdio.h>
#include <stdlib.h>
#include <float.h>
#include <math.h>

struct node {
	int data;
	struct node *next;
};
struct node **graph;
int *node_num,n;
double *Rank, *nextRank;

void insert_front(int, int);
void node_num_count(struct node**);
void pageRank(struct node**);
bool isEq(double, double);

void main() {
	char fname[80];
	FILE *fp;
	int u, v;

	printf("파일 이름? ");
	gets_s(fname);

	if ((fp = fopen(fname, "rt")) == NULL) {
		printf("파일 열기 실패\n");
		return;
	}

	fscanf_s(fp, "%d", &n);

	graph = (struct node**)calloc(n, sizeof(struct node*));
	node_num = (int*)malloc(n*sizeof(int));
	Rank = (double*)malloc(n*sizeof(double));
	nextRank = (double*)malloc(n*sizeof(double));

	for (int i = 0; i < n; i++) 
		node_num[i] = Rank[i] = nextRank[i] = 0;


	while (fscanf_s(fp, "%d %d", &u, &v) != EOF)
		insert_front(u,v);

	node_num_count(graph);		//각 노드 outdegree 갯수 파악

	for (int i = 0; i < n; i++)
		Rank[i] = 1.0/ n;	//초기 랭크값
	
	pageRank(graph);

	for (int i = 0; i < n; i++)
		printf("%d:   %f\n", i, Rank[i]);
}

void pageRank(struct node **ptr) 
{
	struct node *temp;
	int i;
	while (1) {
		for ( i = 0; i < n; i++) 
			for (temp = ptr[i]; temp != NULL;temp=temp->next)
				nextRank[temp->data] += Rank[i] / node_num[i];

		for (i = 0; i < n; i++)
			if (!isEq(Rank[i], nextRank[i]))
				break;
		if (i == n)
			break;

		for ( i = 0; i < n; i++) {
			Rank[i] = nextRank[i];
			nextRank[i] = 0;
		}
	}
}

bool isEq(double a, double b)
{
	return (fabs(a - b) < (DBL_EPSILON * fabs(a + b)));
}

void insert_front(int tail, int head) 
{
	struct node *temp = (struct node*)malloc(sizeof(struct node));

	temp->data = head;
	temp->next = graph[tail];
	graph[tail] = temp;
}

void node_num_count(struct node **ptr) 
{
	struct node *temp;
	for (int i = 0; i < n; i++) {
		temp = ptr[i];
		while (temp != NULL) {
			node_num[i]++;
			temp = temp->next;
		}
	}
}